// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/css/properties/templates/css_properties.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/core/css/properties/css_property_methods.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "third_party/blink/renderer/core/css/properties/longhands.h"

#include "third_party/blink/renderer/core/css/css_custom_ident_value.h"
#include "third_party/blink/renderer/core/css/css_identifier_value.h"
#include "third_party/blink/renderer/core/css/css_primitive_value.h"
#include "third_party/blink/renderer/core/css/css_primitive_value_mappings.h"
#include "third_party/blink/renderer/core/css/css_value_list.h"
#include "third_party/blink/renderer/core/css/css_value_pair.h"
#include "third_party/blink/renderer/core/css/properties/css_direction_aware_resolver.h"
#include "third_party/blink/renderer/core/css/properties/style_building_utils.h"
#include "third_party/blink/renderer/core/css/resolver/font_builder.h"
#include "third_party/blink/renderer/core/css/resolver/style_builder_converter.h"
#include "third_party/blink/renderer/core/css/resolver/style_resolver_state.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/style/computed_style.h"
#include "third_party/blink/renderer/core/style/style_svg_resource.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {
namespace css_longhand {

// color-scheme

const char* ColorScheme::GetPropertyName() const
{
    return "color-scheme";
}

const WTF::AtomicString& ColorScheme::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("color-scheme"));
    return name;
}

const char* ColorScheme::GetJSPropertyName() const
{
    return "colorScheme";
}

// forced-color-adjust

CSSExposure ForcedColorAdjust::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::ForcedColorsEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ForcedColorAdjust::GetPropertyName() const
{
    return "forced-color-adjust";
}

const WTF::AtomicString& ForcedColorAdjust::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("forced-color-adjust"));
    return name;
}

const char* ForcedColorAdjust::GetJSPropertyName() const
{
    return "forcedColorAdjust";
}

void ForcedColorAdjust::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetForcedColorAdjust(ComputedStyleInitialValues::InitialForcedColorAdjust());
}
void ForcedColorAdjust::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetForcedColorAdjust(state.ParentStyle()->ForcedColorAdjust());
}
void ForcedColorAdjust::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetForcedColorAdjust(To<CSSIdentifierValue>(value).ConvertTo<blink::EForcedColorAdjust>());
}

// mask-image

const char* MaskImage::GetPropertyName() const
{
    return "mask-image";
}

const WTF::AtomicString& MaskImage::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("mask-image"));
    return name;
}

const char* MaskImage::GetJSPropertyName() const
{
    return "maskImage";
}

void MaskImage::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    curr_child->SetImage(FillLayer::InitialFillImage(EFillLayerType::kMask));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearImage();
}

void MaskImage::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
    while (curr_parent && curr_parent->IsImageSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetImage(curr_parent->GetImage());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearImage();
        curr_child = curr_child->Next();
    }
}

void MaskImage::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillImage(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillImage(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearImage();
        curr_child = curr_child->Next();
    }
}

// math-depth

const char* MathDepth::GetPropertyName() const
{
    return "math-depth";
}

const WTF::AtomicString& MathDepth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("math-depth"));
    return name;
}

const char* MathDepth::GetJSPropertyName() const
{
    return "mathDepth";
}

void MathDepth::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMathDepth(ComputedStyleInitialValues::InitialMathDepth());
}
void MathDepth::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMathDepth(state.ParentStyle()->MathDepth());
}

// position

const char* Position::GetPropertyName() const
{
    return "position";
}

const WTF::AtomicString& Position::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("position"));
    return name;
}

const char* Position::GetJSPropertyName() const
{
    return "position";
}

void Position::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPosition(ComputedStyleInitialValues::InitialPosition());
}
void Position::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPosition(state.ParentStyle()->GetPosition());
}
void Position::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPosition(To<CSSIdentifierValue>(value).ConvertTo<blink::EPosition>());
}

// position-anchor

const char* PositionAnchor::GetPropertyName() const
{
    return "position-anchor";
}

const WTF::AtomicString& PositionAnchor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("position-anchor"));
    return name;
}

const char* PositionAnchor::GetJSPropertyName() const
{
    return "positionAnchor";
}

// text-size-adjust

const char* TextSizeAdjust::GetPropertyName() const
{
    return "text-size-adjust";
}

const WTF::AtomicString& TextSizeAdjust::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-size-adjust"));
    return name;
}

const char* TextSizeAdjust::GetJSPropertyName() const
{
    return "textSizeAdjust";
}

// appearance

const char* Appearance::GetPropertyName() const
{
    return "appearance";
}

const WTF::AtomicString& Appearance::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("appearance"));
    return name;
}

const char* Appearance::GetJSPropertyName() const
{
    return "appearance";
}

void Appearance::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetAppearance(ComputedStyleInitialValues::InitialAppearance());
}
void Appearance::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetAppearance(state.ParentStyle()->Appearance());
}
void Appearance::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetAppearance(To<CSSIdentifierValue>(value).ConvertTo<blink::ControlPart>());
}

// color

const char* Color::GetPropertyName() const
{
    return "color";
}

const WTF::AtomicString& Color::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("color"));
    return name;
}

const char* Color::GetJSPropertyName() const
{
    return "color";
}

// direction

const char* Direction::GetPropertyName() const
{
    return "direction";
}

const WTF::AtomicString& Direction::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("direction"));
    return name;
}

const char* Direction::GetJSPropertyName() const
{
    return "direction";
}

void Direction::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetDirection(ComputedStyleInitialValues::InitialDirection());
}
void Direction::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetDirection(state.ParentStyle()->Direction());
}

// font-family

const char* FontFamily::GetPropertyName() const
{
    return "font-family";
}

const WTF::AtomicString& FontFamily::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-family"));
    return name;
}

const char* FontFamily::GetJSPropertyName() const
{
    return "fontFamily";
}

void FontFamily::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetFamilyDescription(StyleBuilderConverter::ConvertFontFamily(state, value));
}

// font-feature-settings

const char* FontFeatureSettings::GetPropertyName() const
{
    return "font-feature-settings";
}

const WTF::AtomicString& FontFeatureSettings::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-feature-settings"));
    return name;
}

const char* FontFeatureSettings::GetJSPropertyName() const
{
    return "fontFeatureSettings";
}

void FontFeatureSettings::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFeatureSettings(FontBuilder::InitialFeatureSettings());
}
void FontFeatureSettings::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFeatureSettings(state.ParentFontDescription().FeatureSettings());
}
void FontFeatureSettings::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetFeatureSettings(StyleBuilderConverter::ConvertFontFeatureSettings(state, value));
}

// font-kerning

const char* FontKerning::GetPropertyName() const
{
    return "font-kerning";
}

const WTF::AtomicString& FontKerning::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-kerning"));
    return name;
}

const char* FontKerning::GetJSPropertyName() const
{
    return "fontKerning";
}

void FontKerning::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetKerning(FontBuilder::InitialKerning());
}
void FontKerning::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetKerning(state.ParentFontDescription().GetKerning());
}
void FontKerning::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetKerning(StyleBuilderConverter::ConvertFontKerning(state, value));
}

// font-optical-sizing

const char* FontOpticalSizing::GetPropertyName() const
{
    return "font-optical-sizing";
}

const WTF::AtomicString& FontOpticalSizing::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-optical-sizing"));
    return name;
}

const char* FontOpticalSizing::GetJSPropertyName() const
{
    return "fontOpticalSizing";
}

void FontOpticalSizing::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFontOpticalSizing(FontBuilder::InitialFontOpticalSizing());
}
void FontOpticalSizing::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFontOpticalSizing(state.ParentFontDescription().FontOpticalSizing());
}
void FontOpticalSizing::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetFontOpticalSizing(StyleBuilderConverter::ConvertFontOpticalSizing(state, value));
}

// font-palette

const char* FontPalette::GetPropertyName() const
{
    return "font-palette";
}

const WTF::AtomicString& FontPalette::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-palette"));
    return name;
}

const char* FontPalette::GetJSPropertyName() const
{
    return "fontPalette";
}

void FontPalette::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFontPalette(FontBuilder::InitialFontPalette());
}
void FontPalette::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFontPalette(state.ParentFontDescription().GetFontPalette());
}
void FontPalette::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetFontPalette(StyleBuilderConverter::ConvertFontPalette(state, value));
}

// font-size

const char* FontSize::GetPropertyName() const
{
    return "font-size";
}

const WTF::AtomicString& FontSize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-size"));
    return name;
}

const char* FontSize::GetJSPropertyName() const
{
    return "fontSize";
}

void FontSize::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetSize(FontBuilder::InitialSize());
}
void FontSize::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetSize(state.ParentFontDescription().GetSize());
}
void FontSize::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetSize(StyleBuilderConverter::ConvertFontSize(state, value));
}

// font-size-adjust

CSSExposure FontSizeAdjust::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSFontSizeAdjustEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* FontSizeAdjust::GetPropertyName() const
{
    return "font-size-adjust";
}

const WTF::AtomicString& FontSizeAdjust::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-size-adjust"));
    return name;
}

const char* FontSizeAdjust::GetJSPropertyName() const
{
    return "fontSizeAdjust";
}

void FontSizeAdjust::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetSizeAdjust(FontBuilder::InitialSizeAdjust());
}
void FontSizeAdjust::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetSizeAdjust(state.ParentFontDescription().SizeAdjust());
}
void FontSizeAdjust::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetSizeAdjust(StyleBuilderConverter::ConvertFontSizeAdjust(state, value));
}

// font-stretch

const char* FontStretch::GetPropertyName() const
{
    return "font-stretch";
}

const WTF::AtomicString& FontStretch::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-stretch"));
    return name;
}

const char* FontStretch::GetJSPropertyName() const
{
    return "fontStretch";
}

void FontStretch::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetStretch(FontBuilder::InitialStretch());
}
void FontStretch::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetStretch(state.ParentFontDescription().Stretch());
}
void FontStretch::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetStretch(StyleBuilderConverter::ConvertFontStretch(state, value));
}

// font-style

const char* FontStyle::GetPropertyName() const
{
    return "font-style";
}

const WTF::AtomicString& FontStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-style"));
    return name;
}

const char* FontStyle::GetJSPropertyName() const
{
    return "fontStyle";
}

void FontStyle::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetStyle(FontBuilder::InitialStyle());
}
void FontStyle::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetStyle(state.ParentFontDescription().Style());
}
void FontStyle::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetStyle(StyleBuilderConverter::ConvertFontStyle(state, value));
}

// font-synthesis-small-caps

const char* FontSynthesisSmallCaps::GetPropertyName() const
{
    return "font-synthesis-small-caps";
}

const WTF::AtomicString& FontSynthesisSmallCaps::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-synthesis-small-caps"));
    return name;
}

const char* FontSynthesisSmallCaps::GetJSPropertyName() const
{
    return "fontSynthesisSmallCaps";
}

void FontSynthesisSmallCaps::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFontSynthesisSmallCaps(FontBuilder::InitialFontSynthesisSmallCaps());
}
void FontSynthesisSmallCaps::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFontSynthesisSmallCaps(state.ParentFontDescription().GetFontSynthesisSmallCaps());
}
void FontSynthesisSmallCaps::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetFontSynthesisSmallCaps(To<CSSIdentifierValue>(value).ConvertTo<blink::FontDescription::FontSynthesisSmallCaps>());
}

// font-synthesis-style

const char* FontSynthesisStyle::GetPropertyName() const
{
    return "font-synthesis-style";
}

const WTF::AtomicString& FontSynthesisStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-synthesis-style"));
    return name;
}

const char* FontSynthesisStyle::GetJSPropertyName() const
{
    return "fontSynthesisStyle";
}

void FontSynthesisStyle::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFontSynthesisStyle(FontBuilder::InitialFontSynthesisStyle());
}
void FontSynthesisStyle::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFontSynthesisStyle(state.ParentFontDescription().GetFontSynthesisStyle());
}
void FontSynthesisStyle::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetFontSynthesisStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::FontDescription::FontSynthesisStyle>());
}

// font-synthesis-weight

const char* FontSynthesisWeight::GetPropertyName() const
{
    return "font-synthesis-weight";
}

const WTF::AtomicString& FontSynthesisWeight::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-synthesis-weight"));
    return name;
}

const char* FontSynthesisWeight::GetJSPropertyName() const
{
    return "fontSynthesisWeight";
}

void FontSynthesisWeight::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFontSynthesisWeight(FontBuilder::InitialFontSynthesisWeight());
}
void FontSynthesisWeight::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFontSynthesisWeight(state.ParentFontDescription().GetFontSynthesisWeight());
}
void FontSynthesisWeight::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetFontSynthesisWeight(To<CSSIdentifierValue>(value).ConvertTo<blink::FontDescription::FontSynthesisWeight>());
}

// font-variant-alternates

const char* FontVariantAlternates::GetPropertyName() const
{
    return "font-variant-alternates";
}

const WTF::AtomicString& FontVariantAlternates::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-variant-alternates"));
    return name;
}

const char* FontVariantAlternates::GetJSPropertyName() const
{
    return "fontVariantAlternates";
}

void FontVariantAlternates::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFontVariantAlternates(FontBuilder::InitialFontVariantAlternates());
}
void FontVariantAlternates::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFontVariantAlternates(state.ParentFontDescription().GetFontVariantAlternates());
}
void FontVariantAlternates::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetFontVariantAlternates(StyleBuilderConverter::ConvertFontVariantAlternates(state, value));
}

// font-variant-caps

const char* FontVariantCaps::GetPropertyName() const
{
    return "font-variant-caps";
}

const WTF::AtomicString& FontVariantCaps::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-variant-caps"));
    return name;
}

const char* FontVariantCaps::GetJSPropertyName() const
{
    return "fontVariantCaps";
}

void FontVariantCaps::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetVariantCaps(FontBuilder::InitialVariantCaps());
}
void FontVariantCaps::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetVariantCaps(state.ParentFontDescription().VariantCaps());
}
void FontVariantCaps::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetVariantCaps(StyleBuilderConverter::ConvertFontVariantCaps(state, value));
}

// font-variant-east-asian

const char* FontVariantEastAsian::GetPropertyName() const
{
    return "font-variant-east-asian";
}

const WTF::AtomicString& FontVariantEastAsian::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-variant-east-asian"));
    return name;
}

const char* FontVariantEastAsian::GetJSPropertyName() const
{
    return "fontVariantEastAsian";
}

void FontVariantEastAsian::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetVariantEastAsian(FontBuilder::InitialVariantEastAsian());
}
void FontVariantEastAsian::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetVariantEastAsian(state.ParentFontDescription().VariantEastAsian());
}
void FontVariantEastAsian::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetVariantEastAsian(StyleBuilderConverter::ConvertFontVariantEastAsian(state, value));
}

// font-variant-emoji

CSSExposure FontVariantEmoji::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::FontVariantEmojiEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* FontVariantEmoji::GetPropertyName() const
{
    return "font-variant-emoji";
}

const WTF::AtomicString& FontVariantEmoji::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-variant-emoji"));
    return name;
}

const char* FontVariantEmoji::GetJSPropertyName() const
{
    return "fontVariantEmoji";
}

void FontVariantEmoji::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetVariantEmoji(FontBuilder::InitialVariantEmoji());
}
void FontVariantEmoji::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetVariantEmoji(state.ParentFontDescription().VariantEmoji());
}
void FontVariantEmoji::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetVariantEmoji(StyleBuilderConverter::ConvertFontVariantEmoji(state, value));
}

// font-variant-ligatures

const char* FontVariantLigatures::GetPropertyName() const
{
    return "font-variant-ligatures";
}

const WTF::AtomicString& FontVariantLigatures::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-variant-ligatures"));
    return name;
}

const char* FontVariantLigatures::GetJSPropertyName() const
{
    return "fontVariantLigatures";
}

void FontVariantLigatures::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetVariantLigatures(FontBuilder::InitialVariantLigatures());
}
void FontVariantLigatures::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetVariantLigatures(state.ParentFontDescription().GetVariantLigatures());
}
void FontVariantLigatures::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetVariantLigatures(StyleBuilderConverter::ConvertFontVariantLigatures(state, value));
}

// font-variant-numeric

const char* FontVariantNumeric::GetPropertyName() const
{
    return "font-variant-numeric";
}

const WTF::AtomicString& FontVariantNumeric::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-variant-numeric"));
    return name;
}

const char* FontVariantNumeric::GetJSPropertyName() const
{
    return "fontVariantNumeric";
}

void FontVariantNumeric::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetVariantNumeric(FontBuilder::InitialVariantNumeric());
}
void FontVariantNumeric::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetVariantNumeric(state.ParentFontDescription().VariantNumeric());
}
void FontVariantNumeric::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetVariantNumeric(StyleBuilderConverter::ConvertFontVariantNumeric(state, value));
}

// font-variant-position

const char* FontVariantPosition::GetPropertyName() const
{
    return "font-variant-position";
}

const WTF::AtomicString& FontVariantPosition::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-variant-position"));
    return name;
}

const char* FontVariantPosition::GetJSPropertyName() const
{
    return "fontVariantPosition";
}

void FontVariantPosition::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetVariantPosition(FontBuilder::InitialVariantPosition());
}
void FontVariantPosition::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetVariantPosition(state.ParentFontDescription().VariantPosition());
}
void FontVariantPosition::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetVariantPosition(StyleBuilderConverter::ConvertFontVariantPosition(state, value));
}

// font-variation-settings

const char* FontVariationSettings::GetPropertyName() const
{
    return "font-variation-settings";
}

const WTF::AtomicString& FontVariationSettings::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-variation-settings"));
    return name;
}

const char* FontVariationSettings::GetJSPropertyName() const
{
    return "fontVariationSettings";
}

void FontVariationSettings::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetVariationSettings(FontBuilder::InitialVariationSettings());
}
void FontVariationSettings::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetVariationSettings(state.ParentFontDescription().VariationSettings());
}
void FontVariationSettings::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetVariationSettings(StyleBuilderConverter::ConvertFontVariationSettings(state, value));
}

// font-weight

const char* FontWeight::GetPropertyName() const
{
    return "font-weight";
}

const WTF::AtomicString& FontWeight::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-weight"));
    return name;
}

const char* FontWeight::GetJSPropertyName() const
{
    return "fontWeight";
}

void FontWeight::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetWeight(FontBuilder::InitialWeight());
}
void FontWeight::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetWeight(state.ParentFontDescription().Weight());
}
void FontWeight::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetWeight(StyleBuilderConverter::ConvertFontWeight(state, value));
}

// inset-area

CSSExposure InsetArea::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSInsetAreaPropertyEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* InsetArea::GetPropertyName() const
{
    return "inset-area";
}

const WTF::AtomicString& InsetArea::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("inset-area"));
    return name;
}

const char* InsetArea::GetJSPropertyName() const
{
    return "insetArea";
}

const CSSProperty* InsetArea::SurrogateFor(WritingDirectionMode) const
{
    return &GetCSSPropertyPositionArea();
}

// -internal-visited-color

CSSExposure InternalVisitedColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedColor::GetPropertyName() const
{
    return "-internal-visited-color";
}

const WTF::AtomicString& InternalVisitedColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-color"));
    return name;
}

const char* InternalVisitedColor::GetJSPropertyName() const
{
    return "internalVisitedColor";
}

// position-area

const char* PositionArea::GetPropertyName() const
{
    return "position-area";
}

const WTF::AtomicString& PositionArea::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("position-area"));
    return name;
}

const char* PositionArea::GetJSPropertyName() const
{
    return "positionArea";
}

void PositionArea::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPositionArea(ComputedStyleInitialValues::InitialPositionArea());
}

// text-orientation

const char* TextOrientation::GetPropertyName() const
{
    return "text-orientation";
}

const WTF::AtomicString& TextOrientation::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-orientation"));
    return name;
}

const char* TextOrientation::GetJSPropertyName() const
{
    return "textOrientation";
}

// text-rendering

const char* TextRendering::GetPropertyName() const
{
    return "text-rendering";
}

const WTF::AtomicString& TextRendering::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-rendering"));
    return name;
}

const char* TextRendering::GetJSPropertyName() const
{
    return "textRendering";
}

void TextRendering::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetTextRendering(FontBuilder::InitialTextRendering());
}
void TextRendering::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetTextRendering(state.ParentFontDescription().TextRendering());
}
void TextRendering::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetTextRendering(To<CSSIdentifierValue>(value).ConvertTo<blink::TextRenderingMode>());
}

// text-spacing-trim

const char* TextSpacingTrim::GetPropertyName() const
{
    return "text-spacing-trim";
}

const WTF::AtomicString& TextSpacingTrim::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-spacing-trim"));
    return name;
}

const char* TextSpacingTrim::GetJSPropertyName() const
{
    return "textSpacingTrim";
}

void TextSpacingTrim::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetTextSpacingTrim(FontBuilder::InitialTextSpacingTrim());
}
void TextSpacingTrim::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetTextSpacingTrim(state.ParentFontDescription().GetTextSpacingTrim());
}
void TextSpacingTrim::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetTextSpacingTrim(To<CSSIdentifierValue>(value).ConvertTo<blink::TextSpacingTrim>());
}

// -webkit-font-smoothing

const char* WebkitFontSmoothing::GetPropertyName() const
{
    return "-webkit-font-smoothing";
}

const WTF::AtomicString& WebkitFontSmoothing::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-font-smoothing"));
    return name;
}

const char* WebkitFontSmoothing::GetJSPropertyName() const
{
    return "webkitFontSmoothing";
}

void WebkitFontSmoothing::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFontSmoothing(FontBuilder::InitialFontSmoothing());
}
void WebkitFontSmoothing::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetFontSmoothing(state.ParentFontDescription().FontSmoothing());
}
void WebkitFontSmoothing::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.GetFontBuilder().SetFontSmoothing(To<CSSIdentifierValue>(value).ConvertTo<blink::FontSmoothingMode>());
}

// -webkit-locale

const char* WebkitLocale::GetPropertyName() const
{
    return "-webkit-locale";
}

const WTF::AtomicString& WebkitLocale::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-locale"));
    return name;
}

const char* WebkitLocale::GetJSPropertyName() const
{
    return "webkitLocale";
}

void WebkitLocale::ApplyInitial(StyleResolverState& state) const
{
    state.GetFontBuilder().SetLocale(FontBuilder::InitialLocale());
}
void WebkitLocale::ApplyInherit(StyleResolverState& state) const
{
    state.GetFontBuilder().SetLocale(state.ParentFontDescription().Locale());
}

// -webkit-text-orientation

const char* WebkitTextOrientation::GetPropertyName() const
{
    return "-webkit-text-orientation";
}

const WTF::AtomicString& WebkitTextOrientation::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-orientation"));
    return name;
}

const char* WebkitTextOrientation::GetJSPropertyName() const
{
    return "webkitTextOrientation";
}

const CSSProperty* WebkitTextOrientation::SurrogateFor(WritingDirectionMode) const
{
    return &GetCSSPropertyTextOrientation();
}

// -webkit-writing-mode

const char* WebkitWritingMode::GetPropertyName() const
{
    return "-webkit-writing-mode";
}

const WTF::AtomicString& WebkitWritingMode::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-writing-mode"));
    return name;
}

const char* WebkitWritingMode::GetJSPropertyName() const
{
    return "webkitWritingMode";
}

const CSSProperty* WebkitWritingMode::SurrogateFor(WritingDirectionMode) const
{
    return &GetCSSPropertyWritingMode();
}

// writing-mode

const char* WritingMode::GetPropertyName() const
{
    return "writing-mode";
}

const WTF::AtomicString& WritingMode::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("writing-mode"));
    return name;
}

const char* WritingMode::GetJSPropertyName() const
{
    return "writingMode";
}

// zoom

const char* Zoom::GetPropertyName() const
{
    return "zoom";
}

const WTF::AtomicString& Zoom::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("zoom"));
    return name;
}

const char* Zoom::GetJSPropertyName() const
{
    return "zoom";
}

// accent-color

const char* AccentColor::GetPropertyName() const
{
    return "accent-color";
}

const WTF::AtomicString& AccentColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("accent-color"));
    return name;
}

const char* AccentColor::GetJSPropertyName() const
{
    return "accentColor";
}

void AccentColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetAccentColor(ComputedStyleInitialValues::InitialAccentColor());
}
void AccentColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetAccentColor(state.ParentStyle()->AccentColor());
}
void AccentColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetAccentColor(StyleBuilderConverter::ConvertStyleAutoColor(state, value));
}

// additive-symbols

const char* AdditiveSymbols::GetPropertyName() const
{
    return "additive-symbols";
}

const WTF::AtomicString& AdditiveSymbols::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("additive-symbols"));
    return name;
}

const char* AdditiveSymbols::GetJSPropertyName() const
{
    return "additiveSymbols";
}

// align-content

const char* AlignContent::GetPropertyName() const
{
    return "align-content";
}

const WTF::AtomicString& AlignContent::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("align-content"));
    return name;
}

const char* AlignContent::GetJSPropertyName() const
{
    return "alignContent";
}

void AlignContent::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetAlignContent(ComputedStyleInitialValues::InitialAlignContent());
}
void AlignContent::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetAlignContent(state.ParentStyle()->AlignContent());
}
void AlignContent::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetAlignContent(StyleBuilderConverter::ConvertContentAlignmentData(state, value));
}

// align-items

const char* AlignItems::GetPropertyName() const
{
    return "align-items";
}

const WTF::AtomicString& AlignItems::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("align-items"));
    return name;
}

const char* AlignItems::GetJSPropertyName() const
{
    return "alignItems";
}

void AlignItems::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetAlignItems(ComputedStyleInitialValues::InitialAlignItems());
}
void AlignItems::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetAlignItems(state.ParentStyle()->AlignItems());
}
void AlignItems::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetAlignItems(StyleBuilderConverter::ConvertSelfOrDefaultAlignmentData(state, value));
}

// align-self

const char* AlignSelf::GetPropertyName() const
{
    return "align-self";
}

const WTF::AtomicString& AlignSelf::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("align-self"));
    return name;
}

const char* AlignSelf::GetJSPropertyName() const
{
    return "alignSelf";
}

void AlignSelf::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetAlignSelf(ComputedStyleInitialValues::InitialAlignSelf());
}
void AlignSelf::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetAlignSelf(state.ParentStyle()->AlignSelf());
}
void AlignSelf::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetAlignSelf(StyleBuilderConverter::ConvertSelfOrDefaultAlignmentData(state, value));
}

// alignment-baseline

const char* AlignmentBaseline::GetPropertyName() const
{
    return "alignment-baseline";
}

const WTF::AtomicString& AlignmentBaseline::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("alignment-baseline"));
    return name;
}

const char* AlignmentBaseline::GetJSPropertyName() const
{
    return "alignmentBaseline";
}

void AlignmentBaseline::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetAlignmentBaseline(ComputedStyleInitialValues::InitialAlignmentBaseline());
}
void AlignmentBaseline::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetAlignmentBaseline(state.ParentStyle()->AlignmentBaseline());
}
void AlignmentBaseline::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetAlignmentBaseline(To<CSSIdentifierValue>(value).ConvertTo<blink::EAlignmentBaseline>());
}

// all

const char* All::GetPropertyName() const
{
    return "all";
}

const WTF::AtomicString& All::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("all"));
    return name;
}

const char* All::GetJSPropertyName() const
{
    return "all";
}

void All::ApplyInitial(StyleResolverState& state) const
{
    // Intentionally empty.
}
void All::ApplyInherit(StyleResolverState& state) const
{
    // Intentionally empty.
}
void All::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    // Intentionally empty.
}

// anchor-name

const char* AnchorName::GetPropertyName() const
{
    return "anchor-name";
}

const WTF::AtomicString& AnchorName::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("anchor-name"));
    return name;
}

const char* AnchorName::GetJSPropertyName() const
{
    return "anchorName";
}

void AnchorName::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetAnchorName(ComputedStyleInitialValues::InitialAnchorName());
}
void AnchorName::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetAnchorName(state.ParentStyle()->AnchorName());
}
void AnchorName::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetAnchorName(StyleBuilderConverter::ConvertAnchorName(state, value));
}

// anchor-scope

CSSExposure AnchorScope::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSAnchorScopeEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* AnchorScope::GetPropertyName() const
{
    return "anchor-scope";
}

const WTF::AtomicString& AnchorScope::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("anchor-scope"));
    return name;
}

const char* AnchorScope::GetJSPropertyName() const
{
    return "anchorScope";
}

void AnchorScope::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetAnchorScope(ComputedStyleInitialValues::InitialAnchorScope());
}
void AnchorScope::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetAnchorScope(state.ParentStyle()->AnchorScope());
}
void AnchorScope::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetAnchorScope(StyleBuilderConverter::ConvertAnchorScope(state, value));
}

// animation-composition

const char* AnimationComposition::GetPropertyName() const
{
    return "animation-composition";
}

const WTF::AtomicString& AnimationComposition::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-composition"));
    return name;
}

const char* AnimationComposition::GetJSPropertyName() const
{
    return "animationComposition";
}

void AnimationComposition::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Animations())
        return;
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.CompositionList().clear();
    data.CompositionList().push_back(CSSAnimationData::InitialComposition());
}

void AnimationComposition::ApplyInherit(StyleResolverState& state) const
{
    const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessAnimations().CompositionList() = parent_data->CompositionList();
}

void AnimationComposition::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.CompositionList().clear();
    data.CompositionList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.CompositionList().push_back(CSSToStyleMap::MapAnimationComposition(state, item));
    }
}

// animation-delay

const char* AnimationDelay::GetPropertyName() const
{
    return "animation-delay";
}

const WTF::AtomicString& AnimationDelay::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-delay"));
    return name;
}

const char* AnimationDelay::GetJSPropertyName() const
{
    return "animationDelay";
}

void AnimationDelay::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Animations())
        return;
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.DelayStartList().clear();
    data.DelayStartList().push_back(CSSAnimationData::InitialDelayStart());
}

void AnimationDelay::ApplyInherit(StyleResolverState& state) const
{
    const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessAnimations().DelayStartList() = parent_data->DelayStartList();
}

void AnimationDelay::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.DelayStartList().clear();
    data.DelayStartList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.DelayStartList().push_back(CSSToStyleMap::MapAnimationDelayStart(state, item));
    }
}

// animation-direction

const char* AnimationDirection::GetPropertyName() const
{
    return "animation-direction";
}

const WTF::AtomicString& AnimationDirection::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-direction"));
    return name;
}

const char* AnimationDirection::GetJSPropertyName() const
{
    return "animationDirection";
}

void AnimationDirection::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Animations())
        return;
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.DirectionList().clear();
    data.DirectionList().push_back(CSSAnimationData::InitialDirection());
}

void AnimationDirection::ApplyInherit(StyleResolverState& state) const
{
    const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessAnimations().DirectionList() = parent_data->DirectionList();
}

void AnimationDirection::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.DirectionList().clear();
    data.DirectionList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.DirectionList().push_back(CSSToStyleMap::MapAnimationDirection(state, item));
    }
}

// animation-duration

const char* AnimationDuration::GetPropertyName() const
{
    return "animation-duration";
}

const WTF::AtomicString& AnimationDuration::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-duration"));
    return name;
}

const char* AnimationDuration::GetJSPropertyName() const
{
    return "animationDuration";
}

void AnimationDuration::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Animations())
        return;
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.DurationList().clear();
    data.DurationList().push_back(CSSAnimationData::InitialDuration());
}

void AnimationDuration::ApplyInherit(StyleResolverState& state) const
{
    const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessAnimations().DurationList() = parent_data->DurationList();
}

void AnimationDuration::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.DurationList().clear();
    data.DurationList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.DurationList().push_back(CSSToStyleMap::MapAnimationDuration(state, item));
    }
}

// animation-fill-mode

const char* AnimationFillMode::GetPropertyName() const
{
    return "animation-fill-mode";
}

const WTF::AtomicString& AnimationFillMode::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-fill-mode"));
    return name;
}

const char* AnimationFillMode::GetJSPropertyName() const
{
    return "animationFillMode";
}

void AnimationFillMode::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Animations())
        return;
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.FillModeList().clear();
    data.FillModeList().push_back(CSSAnimationData::InitialFillMode());
}

void AnimationFillMode::ApplyInherit(StyleResolverState& state) const
{
    const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessAnimations().FillModeList() = parent_data->FillModeList();
}

void AnimationFillMode::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.FillModeList().clear();
    data.FillModeList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.FillModeList().push_back(CSSToStyleMap::MapAnimationFillMode(state, item));
    }
}

// animation-iteration-count

const char* AnimationIterationCount::GetPropertyName() const
{
    return "animation-iteration-count";
}

const WTF::AtomicString& AnimationIterationCount::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-iteration-count"));
    return name;
}

const char* AnimationIterationCount::GetJSPropertyName() const
{
    return "animationIterationCount";
}

void AnimationIterationCount::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Animations())
        return;
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.IterationCountList().clear();
    data.IterationCountList().push_back(CSSAnimationData::InitialIterationCount());
}

void AnimationIterationCount::ApplyInherit(StyleResolverState& state) const
{
    const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessAnimations().IterationCountList() = parent_data->IterationCountList();
}

void AnimationIterationCount::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.IterationCountList().clear();
    data.IterationCountList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.IterationCountList().push_back(CSSToStyleMap::MapAnimationIterationCount(state, item));
    }
}

// animation-name

const char* AnimationName::GetPropertyName() const
{
    return "animation-name";
}

const WTF::AtomicString& AnimationName::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-name"));
    return name;
}

const char* AnimationName::GetJSPropertyName() const
{
    return "animationName";
}

void AnimationName::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Animations())
        return;
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.NameList().clear();
    data.NameList().push_back(CSSAnimationData::InitialName());
}

void AnimationName::ApplyInherit(StyleResolverState& state) const
{
    const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessAnimations().NameList() = parent_data->NameList();
}

void AnimationName::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.NameList().clear();
    data.NameList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.NameList().push_back(CSSToStyleMap::MapAnimationName(state, item));
    }
}

// animation-play-state

const char* AnimationPlayState::GetPropertyName() const
{
    return "animation-play-state";
}

const WTF::AtomicString& AnimationPlayState::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-play-state"));
    return name;
}

const char* AnimationPlayState::GetJSPropertyName() const
{
    return "animationPlayState";
}

void AnimationPlayState::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Animations())
        return;
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.PlayStateList().clear();
    data.PlayStateList().push_back(CSSAnimationData::InitialPlayState());
}

void AnimationPlayState::ApplyInherit(StyleResolverState& state) const
{
    const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessAnimations().PlayStateList() = parent_data->PlayStateList();
}

void AnimationPlayState::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.PlayStateList().clear();
    data.PlayStateList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.PlayStateList().push_back(CSSToStyleMap::MapAnimationPlayState(state, item));
    }
}

// animation-range-end

CSSExposure AnimationRangeEnd::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::ScrollTimelineEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* AnimationRangeEnd::GetPropertyName() const
{
    return "animation-range-end";
}

const WTF::AtomicString& AnimationRangeEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-range-end"));
    return name;
}

const char* AnimationRangeEnd::GetJSPropertyName() const
{
    return "animationRangeEnd";
}

void AnimationRangeEnd::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Animations())
        return;
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.RangeEndList().clear();
    data.RangeEndList().push_back(CSSAnimationData::InitialRangeEnd());
}

void AnimationRangeEnd::ApplyInherit(StyleResolverState& state) const
{
    const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessAnimations().RangeEndList() = parent_data->RangeEndList();
}

void AnimationRangeEnd::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.RangeEndList().clear();
    data.RangeEndList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.RangeEndList().push_back(CSSToStyleMap::MapAnimationRangeEnd(state, item));
    }
}

// animation-range-start

CSSExposure AnimationRangeStart::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::ScrollTimelineEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* AnimationRangeStart::GetPropertyName() const
{
    return "animation-range-start";
}

const WTF::AtomicString& AnimationRangeStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-range-start"));
    return name;
}

const char* AnimationRangeStart::GetJSPropertyName() const
{
    return "animationRangeStart";
}

void AnimationRangeStart::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Animations())
        return;
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.RangeStartList().clear();
    data.RangeStartList().push_back(CSSAnimationData::InitialRangeStart());
}

void AnimationRangeStart::ApplyInherit(StyleResolverState& state) const
{
    const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessAnimations().RangeStartList() = parent_data->RangeStartList();
}

void AnimationRangeStart::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.RangeStartList().clear();
    data.RangeStartList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.RangeStartList().push_back(CSSToStyleMap::MapAnimationRangeStart(state, item));
    }
}

// animation-timeline

CSSExposure AnimationTimeline::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::ScrollTimelineEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* AnimationTimeline::GetPropertyName() const
{
    return "animation-timeline";
}

const WTF::AtomicString& AnimationTimeline::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-timeline"));
    return name;
}

const char* AnimationTimeline::GetJSPropertyName() const
{
    return "animationTimeline";
}

void AnimationTimeline::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Animations())
        return;
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.TimelineList().clear();
    data.TimelineList().push_back(CSSAnimationData::InitialTimeline());
}

void AnimationTimeline::ApplyInherit(StyleResolverState& state) const
{
    const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessAnimations().TimelineList() = parent_data->TimelineList();
}

void AnimationTimeline::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.TimelineList().clear();
    data.TimelineList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.TimelineList().push_back(CSSToStyleMap::MapAnimationTimeline(state, item));
    }
}

// animation-timing-function

const char* AnimationTimingFunction::GetPropertyName() const
{
    return "animation-timing-function";
}

const WTF::AtomicString& AnimationTimingFunction::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("animation-timing-function"));
    return name;
}

const char* AnimationTimingFunction::GetJSPropertyName() const
{
    return "animationTimingFunction";
}

void AnimationTimingFunction::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Animations())
        return;
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.TimingFunctionList().clear();
    data.TimingFunctionList().push_back(CSSAnimationData::InitialTimingFunction());
}

void AnimationTimingFunction::ApplyInherit(StyleResolverState& state) const
{
    const CSSAnimationData* parent_data = state.ParentStyle()->Animations();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessAnimations().TimingFunctionList() = parent_data->TimingFunctionList();
}

void AnimationTimingFunction::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSAnimationData& data = state.StyleBuilder().AccessAnimations();
    data.TimingFunctionList().clear();
    data.TimingFunctionList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.TimingFunctionList().push_back(CSSToStyleMap::MapAnimationTimingFunction(state, item));
    }
}

// app-region

const char* AppRegion::GetPropertyName() const
{
    return "app-region";
}

const WTF::AtomicString& AppRegion::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("app-region"));
    return name;
}

const char* AppRegion::GetJSPropertyName() const
{
    return "appRegion";
}

// ascent-override

const char* AscentOverride::GetPropertyName() const
{
    return "ascent-override";
}

const WTF::AtomicString& AscentOverride::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("ascent-override"));
    return name;
}

const char* AscentOverride::GetJSPropertyName() const
{
    return "ascentOverride";
}

// aspect-ratio

const char* AspectRatio::GetPropertyName() const
{
    return "aspect-ratio";
}

const WTF::AtomicString& AspectRatio::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("aspect-ratio"));
    return name;
}

const char* AspectRatio::GetJSPropertyName() const
{
    return "aspectRatio";
}

void AspectRatio::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetAspectRatio(ComputedStyleInitialValues::InitialAspectRatio());
}
void AspectRatio::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetAspectRatio(state.ParentStyle()->AspectRatio());
}
void AspectRatio::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetAspectRatio(StyleBuilderConverter::ConvertAspectRatio(state, value));
}

// backdrop-filter

const char* BackdropFilter::GetPropertyName() const
{
    return "backdrop-filter";
}

const WTF::AtomicString& BackdropFilter::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("backdrop-filter"));
    return name;
}

const char* BackdropFilter::GetJSPropertyName() const
{
    return "backdropFilter";
}

void BackdropFilter::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBackdropFilter(ComputedStyleInitialValues::InitialBackdropFilter());
}
void BackdropFilter::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBackdropFilter(state.ParentStyle()->BackdropFilter());
}

// backface-visibility

const char* BackfaceVisibility::GetPropertyName() const
{
    return "backface-visibility";
}

const WTF::AtomicString& BackfaceVisibility::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("backface-visibility"));
    return name;
}

const char* BackfaceVisibility::GetJSPropertyName() const
{
    return "backfaceVisibility";
}

void BackfaceVisibility::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBackfaceVisibility(ComputedStyleInitialValues::InitialBackfaceVisibility());
}
void BackfaceVisibility::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBackfaceVisibility(state.ParentStyle()->BackfaceVisibility());
}
void BackfaceVisibility::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBackfaceVisibility(To<CSSIdentifierValue>(value).ConvertTo<blink::EBackfaceVisibility>());
}

// background-attachment

const char* BackgroundAttachment::GetPropertyName() const
{
    return "background-attachment";
}

const WTF::AtomicString& BackgroundAttachment::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-attachment"));
    return name;
}

const char* BackgroundAttachment::GetJSPropertyName() const
{
    return "backgroundAttachment";
}

void BackgroundAttachment::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    curr_child->SetAttachment(FillLayer::InitialFillAttachment(EFillLayerType::kBackground));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearAttachment();
}

void BackgroundAttachment::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
    while (curr_parent && curr_parent->IsAttachmentSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetAttachment(curr_parent->Attachment());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearAttachment();
        curr_child = curr_child->Next();
    }
}

void BackgroundAttachment::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillAttachment(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillAttachment(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearAttachment();
        curr_child = curr_child->Next();
    }
}

// background-blend-mode

const char* BackgroundBlendMode::GetPropertyName() const
{
    return "background-blend-mode";
}

const WTF::AtomicString& BackgroundBlendMode::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-blend-mode"));
    return name;
}

const char* BackgroundBlendMode::GetJSPropertyName() const
{
    return "backgroundBlendMode";
}

void BackgroundBlendMode::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    curr_child->SetBlendMode(FillLayer::InitialFillBlendMode(EFillLayerType::kBackground));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearBlendMode();
}

void BackgroundBlendMode::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
    while (curr_parent && curr_parent->IsBlendModeSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetBlendMode(curr_parent->GetBlendMode());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearBlendMode();
        curr_child = curr_child->Next();
    }
}

void BackgroundBlendMode::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillBlendMode(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillBlendMode(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearBlendMode();
        curr_child = curr_child->Next();
    }
}

// background-clip

const char* BackgroundClip::GetPropertyName() const
{
    return "background-clip";
}

const WTF::AtomicString& BackgroundClip::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-clip"));
    return name;
}

const char* BackgroundClip::GetJSPropertyName() const
{
    return "backgroundClip";
}

void BackgroundClip::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    curr_child->SetClip(FillLayer::InitialFillClip(EFillLayerType::kBackground));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearClip();
}

void BackgroundClip::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
    while (curr_parent && curr_parent->IsClipSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetClip(curr_parent->Clip());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearClip();
        curr_child = curr_child->Next();
    }
}

// background-color

const char* BackgroundColor::GetPropertyName() const
{
    return "background-color";
}

const WTF::AtomicString& BackgroundColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-color"));
    return name;
}

const char* BackgroundColor::GetJSPropertyName() const
{
    return "backgroundColor";
}

void BackgroundColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBackgroundColor(ComputedStyleInitialValues::InitialBackgroundColor());
}

void BackgroundColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBackgroundColor(state.ParentStyle()->BackgroundColor());
}

void BackgroundColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBackgroundColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// background-image

const char* BackgroundImage::GetPropertyName() const
{
    return "background-image";
}

const WTF::AtomicString& BackgroundImage::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-image"));
    return name;
}

const char* BackgroundImage::GetJSPropertyName() const
{
    return "backgroundImage";
}

void BackgroundImage::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    curr_child->SetImage(FillLayer::InitialFillImage(EFillLayerType::kBackground));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearImage();
}

void BackgroundImage::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
    while (curr_parent && curr_parent->IsImageSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetImage(curr_parent->GetImage());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearImage();
        curr_child = curr_child->Next();
    }
}

void BackgroundImage::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillImage(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillImage(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearImage();
        curr_child = curr_child->Next();
    }
}

// background-origin

const char* BackgroundOrigin::GetPropertyName() const
{
    return "background-origin";
}

const WTF::AtomicString& BackgroundOrigin::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-origin"));
    return name;
}

const char* BackgroundOrigin::GetJSPropertyName() const
{
    return "backgroundOrigin";
}

void BackgroundOrigin::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    curr_child->SetOrigin(FillLayer::InitialFillOrigin(EFillLayerType::kBackground));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearOrigin();
}

void BackgroundOrigin::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
    while (curr_parent && curr_parent->IsOriginSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetOrigin(curr_parent->Origin());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearOrigin();
        curr_child = curr_child->Next();
    }
}

void BackgroundOrigin::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillOrigin(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillOrigin(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearOrigin();
        curr_child = curr_child->Next();
    }
}

// background-position-x

const char* BackgroundPositionX::GetPropertyName() const
{
    return "background-position-x";
}

const WTF::AtomicString& BackgroundPositionX::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-position-x"));
    return name;
}

const char* BackgroundPositionX::GetJSPropertyName() const
{
    return "backgroundPositionX";
}

void BackgroundPositionX::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    curr_child->SetPositionX(FillLayer::InitialFillPositionX(EFillLayerType::kBackground));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearPositionX();
}

void BackgroundPositionX::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
    while (curr_parent && curr_parent->IsPositionXSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetPositionX(curr_parent->PositionX());
        if (curr_parent->IsBackgroundXOriginSet())
            curr_child->SetBackgroundXOrigin(curr_parent->BackgroundXOrigin());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearPositionX();
        curr_child = curr_child->Next();
    }
}

void BackgroundPositionX::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillPositionX(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillPositionX(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearPositionX();
        curr_child = curr_child->Next();
    }
}

// background-position-y

const char* BackgroundPositionY::GetPropertyName() const
{
    return "background-position-y";
}

const WTF::AtomicString& BackgroundPositionY::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-position-y"));
    return name;
}

const char* BackgroundPositionY::GetJSPropertyName() const
{
    return "backgroundPositionY";
}

void BackgroundPositionY::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    curr_child->SetPositionY(FillLayer::InitialFillPositionY(EFillLayerType::kBackground));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearPositionY();
}

void BackgroundPositionY::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
    while (curr_parent && curr_parent->IsPositionYSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetPositionY(curr_parent->PositionY());
        if (curr_parent->IsBackgroundYOriginSet())
            curr_child->SetBackgroundYOrigin(curr_parent->BackgroundYOrigin());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearPositionY();
        curr_child = curr_child->Next();
    }
}

void BackgroundPositionY::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillPositionY(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillPositionY(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearPositionY();
        curr_child = curr_child->Next();
    }
}

// background-repeat

const char* BackgroundRepeat::GetPropertyName() const
{
    return "background-repeat";
}

const WTF::AtomicString& BackgroundRepeat::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-repeat"));
    return name;
}

const char* BackgroundRepeat::GetJSPropertyName() const
{
    return "backgroundRepeat";
}

void BackgroundRepeat::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    curr_child->SetRepeat(FillLayer::InitialFillRepeat(EFillLayerType::kBackground));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearRepeat();
}

void BackgroundRepeat::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
    while (curr_parent && curr_parent->IsRepeatSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetRepeat(curr_parent->Repeat());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearRepeat();
        curr_child = curr_child->Next();
    }
}

void BackgroundRepeat::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillRepeat(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillRepeat(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearRepeat();
        curr_child = curr_child->Next();
    }
}

// background-size

const char* BackgroundSize::GetPropertyName() const
{
    return "background-size";
}

const WTF::AtomicString& BackgroundSize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("background-size"));
    return name;
}

const char* BackgroundSize::GetJSPropertyName() const
{
    return "backgroundSize";
}

void BackgroundSize::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    curr_child->SetSize(FillLayer::InitialFillSize(EFillLayerType::kBackground));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearSize();
}

void BackgroundSize::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->BackgroundLayers();
    while (curr_parent && curr_parent->IsSizeSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetSize(curr_parent->Size());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearSize();
        curr_child = curr_child->Next();
    }
}

void BackgroundSize::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessBackgroundLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillSize(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillSize(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearSize();
        curr_child = curr_child->Next();
    }
}

// base-palette

const char* BasePalette::GetPropertyName() const
{
    return "base-palette";
}

const WTF::AtomicString& BasePalette::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("base-palette"));
    return name;
}

const char* BasePalette::GetJSPropertyName() const
{
    return "basePalette";
}

// baseline-shift

const char* BaselineShift::GetPropertyName() const
{
    return "baseline-shift";
}

const WTF::AtomicString& BaselineShift::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("baseline-shift"));
    return name;
}

const char* BaselineShift::GetJSPropertyName() const
{
    return "baselineShift";
}

void BaselineShift::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBaselineShift(ComputedStyleInitialValues::InitialBaselineShift());
}

// baseline-source

const char* BaselineSource::GetPropertyName() const
{
    return "baseline-source";
}

const WTF::AtomicString& BaselineSource::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("baseline-source"));
    return name;
}

const char* BaselineSource::GetJSPropertyName() const
{
    return "baselineSource";
}

void BaselineSource::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBaselineSource(ComputedStyleInitialValues::InitialBaselineSource());
}
void BaselineSource::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBaselineSource(state.ParentStyle()->BaselineSource());
}
void BaselineSource::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBaselineSource(To<CSSIdentifierValue>(value).ConvertTo<blink::EBaselineSource>());
}

// block-size

const char* BlockSize::GetPropertyName() const
{
    return "block-size";
}

const WTF::AtomicString& BlockSize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("block-size"));
    return name;
}

const char* BlockSize::GetJSPropertyName() const
{
    return "blockSize";
}

const CSSProperty* BlockSize::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BlockSize::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlock(writing_direction, CSSDirectionAwareResolver::PhysicalSizeMapping());
}

bool BlockSize::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalSizeMapping().Contains(id);
}

// border-block-end-color

const char* BorderBlockEndColor::GetPropertyName() const
{
    return "border-block-end-color";
}

const WTF::AtomicString& BorderBlockEndColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-end-color"));
    return name;
}

const char* BorderBlockEndColor::GetJSPropertyName() const
{
    return "borderBlockEndColor";
}

const CSSProperty* BorderBlockEndColor::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderBlockEndColor::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockEnd(writing_direction, CSSDirectionAwareResolver::PhysicalBorderColorMapping());
}

bool BorderBlockEndColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderColorMapping().Contains(id);
}

// border-block-end-style

const char* BorderBlockEndStyle::GetPropertyName() const
{
    return "border-block-end-style";
}

const WTF::AtomicString& BorderBlockEndStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-end-style"));
    return name;
}

const char* BorderBlockEndStyle::GetJSPropertyName() const
{
    return "borderBlockEndStyle";
}

const CSSProperty* BorderBlockEndStyle::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderBlockEndStyle::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockEnd(writing_direction, CSSDirectionAwareResolver::PhysicalBorderStyleMapping());
}

bool BorderBlockEndStyle::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderStyleMapping().Contains(id);
}

// border-block-end-width

const char* BorderBlockEndWidth::GetPropertyName() const
{
    return "border-block-end-width";
}

const WTF::AtomicString& BorderBlockEndWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-end-width"));
    return name;
}

const char* BorderBlockEndWidth::GetJSPropertyName() const
{
    return "borderBlockEndWidth";
}

const CSSProperty* BorderBlockEndWidth::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderBlockEndWidth::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockEnd(writing_direction, CSSDirectionAwareResolver::PhysicalBorderWidthMapping());
}

bool BorderBlockEndWidth::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderWidthMapping().Contains(id);
}

// border-block-start-color

const char* BorderBlockStartColor::GetPropertyName() const
{
    return "border-block-start-color";
}

const WTF::AtomicString& BorderBlockStartColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-start-color"));
    return name;
}

const char* BorderBlockStartColor::GetJSPropertyName() const
{
    return "borderBlockStartColor";
}

const CSSProperty* BorderBlockStartColor::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderBlockStartColor::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockStart(writing_direction, CSSDirectionAwareResolver::PhysicalBorderColorMapping());
}

bool BorderBlockStartColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderColorMapping().Contains(id);
}

// border-block-start-style

const char* BorderBlockStartStyle::GetPropertyName() const
{
    return "border-block-start-style";
}

const WTF::AtomicString& BorderBlockStartStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-start-style"));
    return name;
}

const char* BorderBlockStartStyle::GetJSPropertyName() const
{
    return "borderBlockStartStyle";
}

const CSSProperty* BorderBlockStartStyle::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderBlockStartStyle::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockStart(writing_direction, CSSDirectionAwareResolver::PhysicalBorderStyleMapping());
}

bool BorderBlockStartStyle::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderStyleMapping().Contains(id);
}

// border-block-start-width

const char* BorderBlockStartWidth::GetPropertyName() const
{
    return "border-block-start-width";
}

const WTF::AtomicString& BorderBlockStartWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-block-start-width"));
    return name;
}

const char* BorderBlockStartWidth::GetJSPropertyName() const
{
    return "borderBlockStartWidth";
}

const CSSProperty* BorderBlockStartWidth::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderBlockStartWidth::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockStart(writing_direction, CSSDirectionAwareResolver::PhysicalBorderWidthMapping());
}

bool BorderBlockStartWidth::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderWidthMapping().Contains(id);
}

// border-bottom-color

const char* BorderBottomColor::GetPropertyName() const
{
    return "border-bottom-color";
}

const WTF::AtomicString& BorderBottomColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-bottom-color"));
    return name;
}

const char* BorderBottomColor::GetJSPropertyName() const
{
    return "borderBottomColor";
}

bool BorderBottomColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderColorMapping().Contains(id);
}

void BorderBottomColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderBottomColor(StyleColor::CurrentColor());
}

void BorderBottomColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderBottomColor(state.ParentStyle()->BorderBottomColor());
}

void BorderBottomColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderBottomColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// border-bottom-left-radius

const char* BorderBottomLeftRadius::GetPropertyName() const
{
    return "border-bottom-left-radius";
}

const WTF::AtomicString& BorderBottomLeftRadius::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-bottom-left-radius"));
    return name;
}

const char* BorderBottomLeftRadius::GetJSPropertyName() const
{
    return "borderBottomLeftRadius";
}

bool BorderBottomLeftRadius::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderRadiusMapping().Contains(id);
}

void BorderBottomLeftRadius::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderBottomLeftRadius(ComputedStyleInitialValues::InitialBorderBottomLeftRadius());
}
void BorderBottomLeftRadius::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderBottomLeftRadius(state.ParentStyle()->BorderBottomLeftRadius());
}
void BorderBottomLeftRadius::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderBottomLeftRadius(StyleBuilderConverter::ConvertRadius(state, value));
}

// border-bottom-right-radius

const char* BorderBottomRightRadius::GetPropertyName() const
{
    return "border-bottom-right-radius";
}

const WTF::AtomicString& BorderBottomRightRadius::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-bottom-right-radius"));
    return name;
}

const char* BorderBottomRightRadius::GetJSPropertyName() const
{
    return "borderBottomRightRadius";
}

bool BorderBottomRightRadius::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderRadiusMapping().Contains(id);
}

void BorderBottomRightRadius::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderBottomRightRadius(ComputedStyleInitialValues::InitialBorderBottomRightRadius());
}
void BorderBottomRightRadius::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderBottomRightRadius(state.ParentStyle()->BorderBottomRightRadius());
}
void BorderBottomRightRadius::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderBottomRightRadius(StyleBuilderConverter::ConvertRadius(state, value));
}

// border-bottom-style

const char* BorderBottomStyle::GetPropertyName() const
{
    return "border-bottom-style";
}

const WTF::AtomicString& BorderBottomStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-bottom-style"));
    return name;
}

const char* BorderBottomStyle::GetJSPropertyName() const
{
    return "borderBottomStyle";
}

bool BorderBottomStyle::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderStyleMapping().Contains(id);
}

void BorderBottomStyle::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderBottomStyle(ComputedStyleInitialValues::InitialBorderBottomStyle());
}
void BorderBottomStyle::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderBottomStyle(state.ParentStyle()->BorderBottomStyle());
}
void BorderBottomStyle::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderBottomStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::EBorderStyle>());
}

// border-bottom-width

const char* BorderBottomWidth::GetPropertyName() const
{
    return "border-bottom-width";
}

const WTF::AtomicString& BorderBottomWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-bottom-width"));
    return name;
}

const char* BorderBottomWidth::GetJSPropertyName() const
{
    return "borderBottomWidth";
}

bool BorderBottomWidth::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderWidthMapping().Contains(id);
}

void BorderBottomWidth::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderBottomWidth(ComputedStyleInitialValues::InitialBorderBottomWidth());
}
void BorderBottomWidth::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderBottomWidth(state.ParentStyle()->BorderBottomWidth());
}
void BorderBottomWidth::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderBottomWidth(StyleBuilderConverter::ConvertBorderWidth(state, value));
}

// border-collapse

const char* BorderCollapse::GetPropertyName() const
{
    return "border-collapse";
}

const WTF::AtomicString& BorderCollapse::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-collapse"));
    return name;
}

const char* BorderCollapse::GetJSPropertyName() const
{
    return "borderCollapse";
}

void BorderCollapse::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderCollapse(ComputedStyleInitialValues::InitialBorderCollapse());
    state.StyleBuilder().SetBorderCollapseIsInherited(false);
}
void BorderCollapse::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderCollapse(state.ParentStyle()->BorderCollapse());
    state.StyleBuilder().SetBorderCollapseIsInherited(true);
}
void BorderCollapse::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderCollapse(To<CSSIdentifierValue>(value).ConvertTo<blink::EBorderCollapse>());
    state.StyleBuilder().SetBorderCollapseIsInherited(false);
}

// border-end-end-radius

const char* BorderEndEndRadius::GetPropertyName() const
{
    return "border-end-end-radius";
}

const WTF::AtomicString& BorderEndEndRadius::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-end-end-radius"));
    return name;
}

const char* BorderEndEndRadius::GetJSPropertyName() const
{
    return "borderEndEndRadius";
}

const CSSProperty* BorderEndEndRadius::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderEndEndRadius::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveEndEnd(writing_direction, CSSDirectionAwareResolver::PhysicalBorderRadiusMapping());
}

bool BorderEndEndRadius::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderRadiusMapping().Contains(id);
}

// border-end-start-radius

const char* BorderEndStartRadius::GetPropertyName() const
{
    return "border-end-start-radius";
}

const WTF::AtomicString& BorderEndStartRadius::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-end-start-radius"));
    return name;
}

const char* BorderEndStartRadius::GetJSPropertyName() const
{
    return "borderEndStartRadius";
}

const CSSProperty* BorderEndStartRadius::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderEndStartRadius::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveEndStart(writing_direction, CSSDirectionAwareResolver::PhysicalBorderRadiusMapping());
}

bool BorderEndStartRadius::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderRadiusMapping().Contains(id);
}

// border-image-outset

const char* BorderImageOutset::GetPropertyName() const
{
    return "border-image-outset";
}

const WTF::AtomicString& BorderImageOutset::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-image-outset"));
    return name;
}

const char* BorderImageOutset::GetJSPropertyName() const
{
    return "borderImageOutset";
}

void BorderImageOutset::ApplyInitial(StyleResolverState& state) const
{
    const NinePieceImage& current_image = state.StyleBuilder().BorderImage();
    if (style_building_utils::BorderImageLengthMatchesAllSides(current_image.Outset(), BorderImageLength(0)))
        return;
    NinePieceImage image(current_image);
    image.SetOutset(0);
    state.StyleBuilder().SetBorderImage(image);
}
void BorderImageOutset::ApplyInherit(StyleResolverState& state) const
{
    NinePieceImage image(state.StyleBuilder().BorderImage());
    image.CopyOutsetFrom(state.ParentStyle()->BorderImage());
    state.StyleBuilder().SetBorderImage(image);
}
void BorderImageOutset::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    NinePieceImage image(state.StyleBuilder().BorderImage());
    image.SetOutset(CSSToStyleMap::MapNinePieceImageQuad(state, value));
    state.StyleBuilder().SetBorderImage(image);
}

// border-image-repeat

const char* BorderImageRepeat::GetPropertyName() const
{
    return "border-image-repeat";
}

const WTF::AtomicString& BorderImageRepeat::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-image-repeat"));
    return name;
}

const char* BorderImageRepeat::GetJSPropertyName() const
{
    return "borderImageRepeat";
}

void BorderImageRepeat::ApplyInitial(StyleResolverState& state) const
{
    const NinePieceImage& current_image = state.StyleBuilder().BorderImage();
    if (current_image.HorizontalRule() == kStretchImageRule && current_image.VerticalRule() == kStretchImageRule)
        return;
    NinePieceImage image(current_image);
    image.SetHorizontalRule(kStretchImageRule);
    image.SetVerticalRule(kStretchImageRule);
    state.StyleBuilder().SetBorderImage(image);
}
void BorderImageRepeat::ApplyInherit(StyleResolverState& state) const
{
    NinePieceImage image(state.StyleBuilder().BorderImage());
    image.CopyRepeatFrom(state.ParentStyle()->BorderImage());
    state.StyleBuilder().SetBorderImage(image);
}
void BorderImageRepeat::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    NinePieceImage image(state.StyleBuilder().BorderImage());
    CSSToStyleMap::MapNinePieceImageRepeat(state, value, image);
    state.StyleBuilder().SetBorderImage(image);
}

// border-image-slice

const char* BorderImageSlice::GetPropertyName() const
{
    return "border-image-slice";
}

const WTF::AtomicString& BorderImageSlice::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-image-slice"));
    return name;
}

const char* BorderImageSlice::GetJSPropertyName() const
{
    return "borderImageSlice";
}

void BorderImageSlice::ApplyInitial(StyleResolverState& state) const
{
    const NinePieceImage& current_image = state.StyleBuilder().BorderImage();
    if (current_image.Fill() == false && style_building_utils::LengthMatchesAllSides(current_image.ImageSlices(), Length::Percent(100)))
        return;
    NinePieceImage image(current_image);
    image.SetImageSlices(LengthBox(Length::Percent(100), Length::Percent(100), Length::Percent(100), Length::Percent(100)));
    image.SetFill(false);
    state.StyleBuilder().SetBorderImage(image);
}
void BorderImageSlice::ApplyInherit(StyleResolverState& state) const
{
    NinePieceImage image(state.StyleBuilder().BorderImage());
    image.CopyImageSlicesFrom(state.ParentStyle()->BorderImage());
    state.StyleBuilder().SetBorderImage(image);
}
void BorderImageSlice::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    NinePieceImage image(state.StyleBuilder().BorderImage());
    CSSToStyleMap::MapNinePieceImageSlice(state, value, image);
    state.StyleBuilder().SetBorderImage(image);
}

// border-image-source

const char* BorderImageSource::GetPropertyName() const
{
    return "border-image-source";
}

const WTF::AtomicString& BorderImageSource::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-image-source"));
    return name;
}

const char* BorderImageSource::GetJSPropertyName() const
{
    return "borderImageSource";
}

void BorderImageSource::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderImageSource(ComputedStyleInitialValues::InitialBorderImageSource());
}
void BorderImageSource::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderImageSource(state.ParentStyle()->BorderImageSource());
}

// border-image-width

const char* BorderImageWidth::GetPropertyName() const
{
    return "border-image-width";
}

const WTF::AtomicString& BorderImageWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-image-width"));
    return name;
}

const char* BorderImageWidth::GetJSPropertyName() const
{
    return "borderImageWidth";
}

void BorderImageWidth::ApplyInitial(StyleResolverState& state) const
{
    const NinePieceImage& current_image = state.StyleBuilder().BorderImage();
    if (style_building_utils::BorderImageLengthMatchesAllSides(current_image.BorderSlices(), BorderImageLength(1.0)))
        return;
    NinePieceImage image(current_image);
    image.SetBorderSlices(1.0);
    state.StyleBuilder().SetBorderImage(image);
}
void BorderImageWidth::ApplyInherit(StyleResolverState& state) const
{
    NinePieceImage image(state.StyleBuilder().BorderImage());
    image.CopyBorderSlicesFrom(state.ParentStyle()->BorderImage());
    state.StyleBuilder().SetBorderImage(image);
}
void BorderImageWidth::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    NinePieceImage image(state.StyleBuilder().BorderImage());
    image.SetBorderSlices(CSSToStyleMap::MapNinePieceImageQuad(state, value));
    state.StyleBuilder().SetBorderImage(image);
}

// border-inline-end-color

const char* BorderInlineEndColor::GetPropertyName() const
{
    return "border-inline-end-color";
}

const WTF::AtomicString& BorderInlineEndColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-end-color"));
    return name;
}

const char* BorderInlineEndColor::GetJSPropertyName() const
{
    return "borderInlineEndColor";
}

const CSSProperty* BorderInlineEndColor::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderInlineEndColor::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineEnd(writing_direction, CSSDirectionAwareResolver::PhysicalBorderColorMapping());
}

bool BorderInlineEndColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderColorMapping().Contains(id);
}

// border-inline-end-style

const char* BorderInlineEndStyle::GetPropertyName() const
{
    return "border-inline-end-style";
}

const WTF::AtomicString& BorderInlineEndStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-end-style"));
    return name;
}

const char* BorderInlineEndStyle::GetJSPropertyName() const
{
    return "borderInlineEndStyle";
}

const CSSProperty* BorderInlineEndStyle::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderInlineEndStyle::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineEnd(writing_direction, CSSDirectionAwareResolver::PhysicalBorderStyleMapping());
}

bool BorderInlineEndStyle::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderStyleMapping().Contains(id);
}

// border-inline-end-width

const char* BorderInlineEndWidth::GetPropertyName() const
{
    return "border-inline-end-width";
}

const WTF::AtomicString& BorderInlineEndWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-end-width"));
    return name;
}

const char* BorderInlineEndWidth::GetJSPropertyName() const
{
    return "borderInlineEndWidth";
}

const CSSProperty* BorderInlineEndWidth::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderInlineEndWidth::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineEnd(writing_direction, CSSDirectionAwareResolver::PhysicalBorderWidthMapping());
}

bool BorderInlineEndWidth::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderWidthMapping().Contains(id);
}

// border-inline-start-color

const char* BorderInlineStartColor::GetPropertyName() const
{
    return "border-inline-start-color";
}

const WTF::AtomicString& BorderInlineStartColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-start-color"));
    return name;
}

const char* BorderInlineStartColor::GetJSPropertyName() const
{
    return "borderInlineStartColor";
}

const CSSProperty* BorderInlineStartColor::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderInlineStartColor::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineStart(writing_direction, CSSDirectionAwareResolver::PhysicalBorderColorMapping());
}

bool BorderInlineStartColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderColorMapping().Contains(id);
}

// border-inline-start-style

const char* BorderInlineStartStyle::GetPropertyName() const
{
    return "border-inline-start-style";
}

const WTF::AtomicString& BorderInlineStartStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-start-style"));
    return name;
}

const char* BorderInlineStartStyle::GetJSPropertyName() const
{
    return "borderInlineStartStyle";
}

const CSSProperty* BorderInlineStartStyle::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderInlineStartStyle::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineStart(writing_direction, CSSDirectionAwareResolver::PhysicalBorderStyleMapping());
}

bool BorderInlineStartStyle::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderStyleMapping().Contains(id);
}

// border-inline-start-width

const char* BorderInlineStartWidth::GetPropertyName() const
{
    return "border-inline-start-width";
}

const WTF::AtomicString& BorderInlineStartWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-inline-start-width"));
    return name;
}

const char* BorderInlineStartWidth::GetJSPropertyName() const
{
    return "borderInlineStartWidth";
}

const CSSProperty* BorderInlineStartWidth::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderInlineStartWidth::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineStart(writing_direction, CSSDirectionAwareResolver::PhysicalBorderWidthMapping());
}

bool BorderInlineStartWidth::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderWidthMapping().Contains(id);
}

// border-left-color

const char* BorderLeftColor::GetPropertyName() const
{
    return "border-left-color";
}

const WTF::AtomicString& BorderLeftColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-left-color"));
    return name;
}

const char* BorderLeftColor::GetJSPropertyName() const
{
    return "borderLeftColor";
}

bool BorderLeftColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderColorMapping().Contains(id);
}

void BorderLeftColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderLeftColor(StyleColor::CurrentColor());
}

void BorderLeftColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderLeftColor(state.ParentStyle()->BorderLeftColor());
}

void BorderLeftColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderLeftColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// border-left-style

const char* BorderLeftStyle::GetPropertyName() const
{
    return "border-left-style";
}

const WTF::AtomicString& BorderLeftStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-left-style"));
    return name;
}

const char* BorderLeftStyle::GetJSPropertyName() const
{
    return "borderLeftStyle";
}

bool BorderLeftStyle::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderStyleMapping().Contains(id);
}

void BorderLeftStyle::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderLeftStyle(ComputedStyleInitialValues::InitialBorderLeftStyle());
}
void BorderLeftStyle::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderLeftStyle(state.ParentStyle()->BorderLeftStyle());
}
void BorderLeftStyle::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderLeftStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::EBorderStyle>());
}

// border-left-width

const char* BorderLeftWidth::GetPropertyName() const
{
    return "border-left-width";
}

const WTF::AtomicString& BorderLeftWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-left-width"));
    return name;
}

const char* BorderLeftWidth::GetJSPropertyName() const
{
    return "borderLeftWidth";
}

bool BorderLeftWidth::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderWidthMapping().Contains(id);
}

void BorderLeftWidth::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderLeftWidth(ComputedStyleInitialValues::InitialBorderLeftWidth());
}
void BorderLeftWidth::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderLeftWidth(state.ParentStyle()->BorderLeftWidth());
}
void BorderLeftWidth::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderLeftWidth(StyleBuilderConverter::ConvertBorderWidth(state, value));
}

// border-right-color

const char* BorderRightColor::GetPropertyName() const
{
    return "border-right-color";
}

const WTF::AtomicString& BorderRightColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-right-color"));
    return name;
}

const char* BorderRightColor::GetJSPropertyName() const
{
    return "borderRightColor";
}

bool BorderRightColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderColorMapping().Contains(id);
}

void BorderRightColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderRightColor(StyleColor::CurrentColor());
}

void BorderRightColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderRightColor(state.ParentStyle()->BorderRightColor());
}

void BorderRightColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderRightColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// border-right-style

const char* BorderRightStyle::GetPropertyName() const
{
    return "border-right-style";
}

const WTF::AtomicString& BorderRightStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-right-style"));
    return name;
}

const char* BorderRightStyle::GetJSPropertyName() const
{
    return "borderRightStyle";
}

bool BorderRightStyle::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderStyleMapping().Contains(id);
}

void BorderRightStyle::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderRightStyle(ComputedStyleInitialValues::InitialBorderRightStyle());
}
void BorderRightStyle::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderRightStyle(state.ParentStyle()->BorderRightStyle());
}
void BorderRightStyle::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderRightStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::EBorderStyle>());
}

// border-right-width

const char* BorderRightWidth::GetPropertyName() const
{
    return "border-right-width";
}

const WTF::AtomicString& BorderRightWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-right-width"));
    return name;
}

const char* BorderRightWidth::GetJSPropertyName() const
{
    return "borderRightWidth";
}

bool BorderRightWidth::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderWidthMapping().Contains(id);
}

void BorderRightWidth::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderRightWidth(ComputedStyleInitialValues::InitialBorderRightWidth());
}
void BorderRightWidth::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderRightWidth(state.ParentStyle()->BorderRightWidth());
}
void BorderRightWidth::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderRightWidth(StyleBuilderConverter::ConvertBorderWidth(state, value));
}

// border-start-end-radius

const char* BorderStartEndRadius::GetPropertyName() const
{
    return "border-start-end-radius";
}

const WTF::AtomicString& BorderStartEndRadius::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-start-end-radius"));
    return name;
}

const char* BorderStartEndRadius::GetJSPropertyName() const
{
    return "borderStartEndRadius";
}

const CSSProperty* BorderStartEndRadius::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderStartEndRadius::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveStartEnd(writing_direction, CSSDirectionAwareResolver::PhysicalBorderRadiusMapping());
}

bool BorderStartEndRadius::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderRadiusMapping().Contains(id);
}

// border-start-start-radius

const char* BorderStartStartRadius::GetPropertyName() const
{
    return "border-start-start-radius";
}

const WTF::AtomicString& BorderStartStartRadius::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-start-start-radius"));
    return name;
}

const char* BorderStartStartRadius::GetJSPropertyName() const
{
    return "borderStartStartRadius";
}

const CSSProperty* BorderStartStartRadius::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& BorderStartStartRadius::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveStartStart(writing_direction, CSSDirectionAwareResolver::PhysicalBorderRadiusMapping());
}

bool BorderStartStartRadius::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalBorderRadiusMapping().Contains(id);
}

// border-top-color

const char* BorderTopColor::GetPropertyName() const
{
    return "border-top-color";
}

const WTF::AtomicString& BorderTopColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-top-color"));
    return name;
}

const char* BorderTopColor::GetJSPropertyName() const
{
    return "borderTopColor";
}

bool BorderTopColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderColorMapping().Contains(id);
}

void BorderTopColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderTopColor(StyleColor::CurrentColor());
}

void BorderTopColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderTopColor(state.ParentStyle()->BorderTopColor());
}

void BorderTopColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderTopColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// border-top-left-radius

const char* BorderTopLeftRadius::GetPropertyName() const
{
    return "border-top-left-radius";
}

const WTF::AtomicString& BorderTopLeftRadius::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-top-left-radius"));
    return name;
}

const char* BorderTopLeftRadius::GetJSPropertyName() const
{
    return "borderTopLeftRadius";
}

bool BorderTopLeftRadius::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderRadiusMapping().Contains(id);
}

void BorderTopLeftRadius::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderTopLeftRadius(ComputedStyleInitialValues::InitialBorderTopLeftRadius());
}
void BorderTopLeftRadius::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderTopLeftRadius(state.ParentStyle()->BorderTopLeftRadius());
}
void BorderTopLeftRadius::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderTopLeftRadius(StyleBuilderConverter::ConvertRadius(state, value));
}

// border-top-right-radius

const char* BorderTopRightRadius::GetPropertyName() const
{
    return "border-top-right-radius";
}

const WTF::AtomicString& BorderTopRightRadius::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-top-right-radius"));
    return name;
}

const char* BorderTopRightRadius::GetJSPropertyName() const
{
    return "borderTopRightRadius";
}

bool BorderTopRightRadius::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderRadiusMapping().Contains(id);
}

void BorderTopRightRadius::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderTopRightRadius(ComputedStyleInitialValues::InitialBorderTopRightRadius());
}
void BorderTopRightRadius::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderTopRightRadius(state.ParentStyle()->BorderTopRightRadius());
}
void BorderTopRightRadius::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderTopRightRadius(StyleBuilderConverter::ConvertRadius(state, value));
}

// border-top-style

const char* BorderTopStyle::GetPropertyName() const
{
    return "border-top-style";
}

const WTF::AtomicString& BorderTopStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-top-style"));
    return name;
}

const char* BorderTopStyle::GetJSPropertyName() const
{
    return "borderTopStyle";
}

bool BorderTopStyle::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderStyleMapping().Contains(id);
}

void BorderTopStyle::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderTopStyle(ComputedStyleInitialValues::InitialBorderTopStyle());
}
void BorderTopStyle::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderTopStyle(state.ParentStyle()->BorderTopStyle());
}
void BorderTopStyle::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderTopStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::EBorderStyle>());
}

// border-top-width

const char* BorderTopWidth::GetPropertyName() const
{
    return "border-top-width";
}

const WTF::AtomicString& BorderTopWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("border-top-width"));
    return name;
}

const char* BorderTopWidth::GetJSPropertyName() const
{
    return "borderTopWidth";
}

bool BorderTopWidth::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalBorderWidthMapping().Contains(id);
}

void BorderTopWidth::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderTopWidth(ComputedStyleInitialValues::InitialBorderTopWidth());
}
void BorderTopWidth::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderTopWidth(state.ParentStyle()->BorderTopWidth());
}
void BorderTopWidth::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBorderTopWidth(StyleBuilderConverter::ConvertBorderWidth(state, value));
}

// bottom

const char* Bottom::GetPropertyName() const
{
    return "bottom";
}

const WTF::AtomicString& Bottom::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("bottom"));
    return name;
}

const char* Bottom::GetJSPropertyName() const
{
    return "bottom";
}

bool Bottom::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalInsetMapping().Contains(id);
}

void Bottom::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBottom(ComputedStyleInitialValues::InitialBottom());
}
void Bottom::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBottom(state.ParentStyle()->Bottom());
}
void Bottom::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    blink::AnchorScope anchor_scope(blink::AnchorScope::Mode::kBottom, state.CssToLengthConversionData().GetAnchorEvaluator());
    state.StyleBuilder().SetBottom(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

// box-decoration-break

CSSExposure BoxDecorationBreak::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::BoxDecorationBreakEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* BoxDecorationBreak::GetPropertyName() const
{
    return "box-decoration-break";
}

const WTF::AtomicString& BoxDecorationBreak::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("box-decoration-break"));
    return name;
}

const char* BoxDecorationBreak::GetJSPropertyName() const
{
    return "boxDecorationBreak";
}

void BoxDecorationBreak::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxDecorationBreak(ComputedStyleInitialValues::InitialBoxDecorationBreak());
}
void BoxDecorationBreak::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxDecorationBreak(state.ParentStyle()->BoxDecorationBreak());
}
void BoxDecorationBreak::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBoxDecorationBreak(To<CSSIdentifierValue>(value).ConvertTo<blink::EBoxDecorationBreak>());
}

// box-shadow

const char* BoxShadow::GetPropertyName() const
{
    return "box-shadow";
}

const WTF::AtomicString& BoxShadow::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("box-shadow"));
    return name;
}

const char* BoxShadow::GetJSPropertyName() const
{
    return "boxShadow";
}

void BoxShadow::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxShadow(ComputedStyleInitialValues::InitialBoxShadow());
}
void BoxShadow::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxShadow(state.ParentStyle()->BoxShadow());
}
void BoxShadow::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBoxShadow(StyleBuilderConverter::ConvertShadowList(state, value));
}

// box-sizing

const char* BoxSizing::GetPropertyName() const
{
    return "box-sizing";
}

const WTF::AtomicString& BoxSizing::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("box-sizing"));
    return name;
}

const char* BoxSizing::GetJSPropertyName() const
{
    return "boxSizing";
}

void BoxSizing::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxSizing(ComputedStyleInitialValues::InitialBoxSizing());
}
void BoxSizing::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxSizing(state.ParentStyle()->BoxSizing());
}
void BoxSizing::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBoxSizing(To<CSSIdentifierValue>(value).ConvertTo<blink::EBoxSizing>());
}

// break-after

const char* BreakAfter::GetPropertyName() const
{
    return "break-after";
}

const WTF::AtomicString& BreakAfter::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("break-after"));
    return name;
}

const char* BreakAfter::GetJSPropertyName() const
{
    return "breakAfter";
}

void BreakAfter::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBreakAfter(ComputedStyleInitialValues::InitialBreakAfter());
}
void BreakAfter::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBreakAfter(state.ParentStyle()->BreakAfter());
}
void BreakAfter::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBreakAfter(To<CSSIdentifierValue>(value).ConvertTo<blink::EBreakBetween>());
}

// break-before

const char* BreakBefore::GetPropertyName() const
{
    return "break-before";
}

const WTF::AtomicString& BreakBefore::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("break-before"));
    return name;
}

const char* BreakBefore::GetJSPropertyName() const
{
    return "breakBefore";
}

void BreakBefore::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBreakBefore(ComputedStyleInitialValues::InitialBreakBefore());
}
void BreakBefore::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBreakBefore(state.ParentStyle()->BreakBefore());
}
void BreakBefore::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBreakBefore(To<CSSIdentifierValue>(value).ConvertTo<blink::EBreakBetween>());
}

// break-inside

const char* BreakInside::GetPropertyName() const
{
    return "break-inside";
}

const WTF::AtomicString& BreakInside::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("break-inside"));
    return name;
}

const char* BreakInside::GetJSPropertyName() const
{
    return "breakInside";
}

void BreakInside::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBreakInside(ComputedStyleInitialValues::InitialBreakInside());
}
void BreakInside::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBreakInside(state.ParentStyle()->BreakInside());
}
void BreakInside::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBreakInside(To<CSSIdentifierValue>(value).ConvertTo<blink::EBreakInside>());
}

// buffered-rendering

const char* BufferedRendering::GetPropertyName() const
{
    return "buffered-rendering";
}

const WTF::AtomicString& BufferedRendering::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("buffered-rendering"));
    return name;
}

const char* BufferedRendering::GetJSPropertyName() const
{
    return "bufferedRendering";
}

void BufferedRendering::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBufferedRendering(ComputedStyleInitialValues::InitialBufferedRendering());
}
void BufferedRendering::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBufferedRendering(state.ParentStyle()->BufferedRendering());
}
void BufferedRendering::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBufferedRendering(To<CSSIdentifierValue>(value).ConvertTo<blink::EBufferedRendering>());
}

// caption-side

const char* CaptionSide::GetPropertyName() const
{
    return "caption-side";
}

const WTF::AtomicString& CaptionSide::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("caption-side"));
    return name;
}

const char* CaptionSide::GetJSPropertyName() const
{
    return "captionSide";
}

void CaptionSide::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetCaptionSide(ComputedStyleInitialValues::InitialCaptionSide());
    state.StyleBuilder().SetCaptionSideIsInherited(false);
}
void CaptionSide::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetCaptionSide(state.ParentStyle()->CaptionSide());
    state.StyleBuilder().SetCaptionSideIsInherited(true);
}
void CaptionSide::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetCaptionSide(To<CSSIdentifierValue>(value).ConvertTo<blink::ECaptionSide>());
    state.StyleBuilder().SetCaptionSideIsInherited(false);
}

// caret-animation

CSSExposure CaretAnimation::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSCaretAnimationEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* CaretAnimation::GetPropertyName() const
{
    return "caret-animation";
}

const WTF::AtomicString& CaretAnimation::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("caret-animation"));
    return name;
}

const char* CaretAnimation::GetJSPropertyName() const
{
    return "caretAnimation";
}

void CaretAnimation::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetCaretAnimation(ComputedStyleInitialValues::InitialCaretAnimation());
}
void CaretAnimation::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetCaretAnimation(state.ParentStyle()->CaretAnimation());
}
void CaretAnimation::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetCaretAnimation(To<CSSIdentifierValue>(value).ConvertTo<blink::ECaretAnimation>());
}

// caret-color

const char* CaretColor::GetPropertyName() const
{
    return "caret-color";
}

const WTF::AtomicString& CaretColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("caret-color"));
    return name;
}

const char* CaretColor::GetJSPropertyName() const
{
    return "caretColor";
}

void CaretColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetCaretColor(ComputedStyleInitialValues::InitialCaretColor());
}
void CaretColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetCaretColor(state.ParentStyle()->CaretColor());
}
void CaretColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetCaretColor(StyleBuilderConverter::ConvertStyleAutoColor(state, value));
}

// clear

const char* Clear::GetPropertyName() const
{
    return "clear";
}

const WTF::AtomicString& Clear::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("clear"));
    return name;
}

const char* Clear::GetJSPropertyName() const
{
    return "clear";
}

void Clear::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetClear(ComputedStyleInitialValues::InitialClear());
}
void Clear::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetClear(state.ParentStyle()->Clear());
}
void Clear::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetClear(To<CSSIdentifierValue>(value).ConvertTo<blink::EClear>());
}

// clip

const char* Clip::GetPropertyName() const
{
    return "clip";
}

const WTF::AtomicString& Clip::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("clip"));
    return name;
}

const char* Clip::GetJSPropertyName() const
{
    return "clip";
}

void Clip::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetHasAutoClip();
}
void Clip::ApplyInherit(StyleResolverState& state) const
{
    if (state.ParentStyle()->HasAutoClip())
        state.StyleBuilder().SetHasAutoClip();
    else
        state.StyleBuilder().SetClip(state.ParentStyle()->Clip());
}
void Clip::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    auto* identifier_value = DynamicTo<CSSIdentifierValue>(value);
    if (identifier_value && identifier_value->GetValueID() == CSSValueID::kAuto)
        state.StyleBuilder().SetHasAutoClip();
    else
        state.StyleBuilder().SetClip(StyleBuilderConverter::ConvertClip(state, value));
}

// clip-path

const char* ClipPath::GetPropertyName() const
{
    return "clip-path";
}

const WTF::AtomicString& ClipPath::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("clip-path"));
    return name;
}

const char* ClipPath::GetJSPropertyName() const
{
    return "clipPath";
}

void ClipPath::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetClipPath(ComputedStyleInitialValues::InitialClipPath());
}
void ClipPath::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetClipPath(state.ParentStyle()->ClipPath());
}
void ClipPath::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetClipPath(StyleBuilderConverter::ConvertClipPath(state, value));
}

// clip-rule

const char* ClipRule::GetPropertyName() const
{
    return "clip-rule";
}

const WTF::AtomicString& ClipRule::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("clip-rule"));
    return name;
}

const char* ClipRule::GetJSPropertyName() const
{
    return "clipRule";
}

void ClipRule::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetClipRule(ComputedStyleInitialValues::InitialClipRule());
}
void ClipRule::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetClipRule(state.ParentStyle()->ClipRule());
}
void ClipRule::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetClipRule(To<CSSIdentifierValue>(value).ConvertTo<blink::WindRule>());
}

// color-interpolation

const char* ColorInterpolation::GetPropertyName() const
{
    return "color-interpolation";
}

const WTF::AtomicString& ColorInterpolation::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("color-interpolation"));
    return name;
}

const char* ColorInterpolation::GetJSPropertyName() const
{
    return "colorInterpolation";
}

void ColorInterpolation::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetColorInterpolation(ComputedStyleInitialValues::InitialColorInterpolation());
}
void ColorInterpolation::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetColorInterpolation(state.ParentStyle()->ColorInterpolation());
}
void ColorInterpolation::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetColorInterpolation(To<CSSIdentifierValue>(value).ConvertTo<blink::EColorInterpolation>());
}

// color-interpolation-filters

const char* ColorInterpolationFilters::GetPropertyName() const
{
    return "color-interpolation-filters";
}

const WTF::AtomicString& ColorInterpolationFilters::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("color-interpolation-filters"));
    return name;
}

const char* ColorInterpolationFilters::GetJSPropertyName() const
{
    return "colorInterpolationFilters";
}

void ColorInterpolationFilters::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetColorInterpolationFilters(ComputedStyleInitialValues::InitialColorInterpolationFilters());
}
void ColorInterpolationFilters::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetColorInterpolationFilters(state.ParentStyle()->ColorInterpolationFilters());
}
void ColorInterpolationFilters::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetColorInterpolationFilters(To<CSSIdentifierValue>(value).ConvertTo<blink::EColorInterpolation>());
}

// color-rendering

const char* ColorRendering::GetPropertyName() const
{
    return "color-rendering";
}

const WTF::AtomicString& ColorRendering::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("color-rendering"));
    return name;
}

const char* ColorRendering::GetJSPropertyName() const
{
    return "colorRendering";
}

void ColorRendering::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetColorRendering(ComputedStyleInitialValues::InitialColorRendering());
}
void ColorRendering::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetColorRendering(state.ParentStyle()->ColorRendering());
}
void ColorRendering::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetColorRendering(To<CSSIdentifierValue>(value).ConvertTo<blink::EColorRendering>());
}

// column-count

const char* ColumnCount::GetPropertyName() const
{
    return "column-count";
}

const WTF::AtomicString& ColumnCount::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-count"));
    return name;
}

const char* ColumnCount::GetJSPropertyName() const
{
    return "columnCount";
}

void ColumnCount::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetHasAutoColumnCount();
}
void ColumnCount::ApplyInherit(StyleResolverState& state) const
{
    if (state.ParentStyle()->HasAutoColumnCount())
        state.StyleBuilder().SetHasAutoColumnCount();
    else
        state.StyleBuilder().SetColumnCount(state.ParentStyle()->ColumnCount());
}
void ColumnCount::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    auto* identifier_value = DynamicTo<CSSIdentifierValue>(value);
    if (identifier_value && identifier_value->GetValueID() == CSSValueID::kAuto)
        state.StyleBuilder().SetHasAutoColumnCount();
    else
        state.StyleBuilder().SetColumnCount(To<CSSPrimitiveValue>(value).ConvertTo<unsigned short>(state.CssToLengthConversionData()));
}

// column-fill

const char* ColumnFill::GetPropertyName() const
{
    return "column-fill";
}

const WTF::AtomicString& ColumnFill::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-fill"));
    return name;
}

const char* ColumnFill::GetJSPropertyName() const
{
    return "columnFill";
}

void ColumnFill::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetColumnFill(ComputedStyleInitialValues::InitialColumnFill());
}
void ColumnFill::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetColumnFill(state.ParentStyle()->GetColumnFill());
}
void ColumnFill::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetColumnFill(To<CSSIdentifierValue>(value).ConvertTo<blink::EColumnFill>());
}

// column-gap

const char* ColumnGap::GetPropertyName() const
{
    return "column-gap";
}

const WTF::AtomicString& ColumnGap::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-gap"));
    return name;
}

const char* ColumnGap::GetJSPropertyName() const
{
    return "columnGap";
}

void ColumnGap::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetColumnGap(ComputedStyleInitialValues::InitialColumnGap());
}
void ColumnGap::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetColumnGap(state.ParentStyle()->ColumnGap());
}
void ColumnGap::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetColumnGap(StyleBuilderConverter::ConvertGapLength(state, value));
}

// column-rule-color

const char* ColumnRuleColor::GetPropertyName() const
{
    return "column-rule-color";
}

const WTF::AtomicString& ColumnRuleColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-rule-color"));
    return name;
}

const char* ColumnRuleColor::GetJSPropertyName() const
{
    return "columnRuleColor";
}

void ColumnRuleColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetColumnRuleColor(ComputedStyleInitialValues::InitialColumnRuleColor());
}
void ColumnRuleColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetColumnRuleColor(state.ParentStyle()->ColumnRuleColor());
}
void ColumnRuleColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetColumnRuleColor(StyleBuilderConverter::ConvertGapDecorationColorDataList(state, value));
}

// column-rule-style

const char* ColumnRuleStyle::GetPropertyName() const
{
    return "column-rule-style";
}

const WTF::AtomicString& ColumnRuleStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-rule-style"));
    return name;
}

const char* ColumnRuleStyle::GetJSPropertyName() const
{
    return "columnRuleStyle";
}

void ColumnRuleStyle::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetColumnRuleStyle(ComputedStyleInitialValues::InitialColumnRuleStyle());
}
void ColumnRuleStyle::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetColumnRuleStyle(state.ParentStyle()->ColumnRuleStyle());
}
void ColumnRuleStyle::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetColumnRuleStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::EBorderStyle>());
}

// column-rule-width

const char* ColumnRuleWidth::GetPropertyName() const
{
    return "column-rule-width";
}

const WTF::AtomicString& ColumnRuleWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-rule-width"));
    return name;
}

const char* ColumnRuleWidth::GetJSPropertyName() const
{
    return "columnRuleWidth";
}

void ColumnRuleWidth::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetColumnRuleWidth(ComputedStyleInitialValues::InitialColumnRuleWidth());
}
void ColumnRuleWidth::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetColumnRuleWidth(state.ParentStyle()->ColumnRuleWidth());
}
void ColumnRuleWidth::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetColumnRuleWidth(StyleBuilderConverter::ConvertColumnRuleWidth(state, value));
}

// column-span

const char* ColumnSpan::GetPropertyName() const
{
    return "column-span";
}

const WTF::AtomicString& ColumnSpan::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-span"));
    return name;
}

const char* ColumnSpan::GetJSPropertyName() const
{
    return "columnSpan";
}

void ColumnSpan::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetColumnSpan(ComputedStyleInitialValues::InitialColumnSpan());
}
void ColumnSpan::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetColumnSpan(state.ParentStyle()->GetColumnSpan());
}
void ColumnSpan::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetColumnSpan(To<CSSIdentifierValue>(value).ConvertTo<blink::EColumnSpan>());
}

// column-width

const char* ColumnWidth::GetPropertyName() const
{
    return "column-width";
}

const WTF::AtomicString& ColumnWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("column-width"));
    return name;
}

const char* ColumnWidth::GetJSPropertyName() const
{
    return "columnWidth";
}

void ColumnWidth::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetHasAutoColumnWidth();
}
void ColumnWidth::ApplyInherit(StyleResolverState& state) const
{
    if (state.ParentStyle()->HasAutoColumnWidth())
        state.StyleBuilder().SetHasAutoColumnWidth();
    else
        state.StyleBuilder().SetColumnWidth(state.ParentStyle()->ColumnWidth());
}
void ColumnWidth::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    auto* identifier_value = DynamicTo<CSSIdentifierValue>(value);
    if (identifier_value && identifier_value->GetValueID() == CSSValueID::kAuto)
        state.StyleBuilder().SetHasAutoColumnWidth();
    else
        state.StyleBuilder().SetColumnWidth(StyleBuilderConverter::ConvertComputedLength<float>(state, value));
}

// contain

const char* Contain::GetPropertyName() const
{
    return "contain";
}

const WTF::AtomicString& Contain::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("contain"));
    return name;
}

const char* Contain::GetJSPropertyName() const
{
    return "contain";
}

void Contain::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetContain(ComputedStyleInitialValues::InitialContain());
}
void Contain::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetContain(state.ParentStyle()->Contain());
}
void Contain::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetContain(StyleBuilderConverter::ConvertFlags<Containment>(state, value));
}

// contain-intrinsic-block-size

const char* ContainIntrinsicBlockSize::GetPropertyName() const
{
    return "contain-intrinsic-block-size";
}

const WTF::AtomicString& ContainIntrinsicBlockSize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("contain-intrinsic-block-size"));
    return name;
}

const char* ContainIntrinsicBlockSize::GetJSPropertyName() const
{
    return "containIntrinsicBlockSize";
}

const CSSProperty* ContainIntrinsicBlockSize::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& ContainIntrinsicBlockSize::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlock(writing_direction, CSSDirectionAwareResolver::PhysicalContainIntrinsicSizeMapping());
}

bool ContainIntrinsicBlockSize::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalContainIntrinsicSizeMapping().Contains(id);
}

// contain-intrinsic-height

const char* ContainIntrinsicHeight::GetPropertyName() const
{
    return "contain-intrinsic-height";
}

const WTF::AtomicString& ContainIntrinsicHeight::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("contain-intrinsic-height"));
    return name;
}

const char* ContainIntrinsicHeight::GetJSPropertyName() const
{
    return "containIntrinsicHeight";
}

void ContainIntrinsicHeight::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetContainIntrinsicHeight(ComputedStyleInitialValues::InitialContainIntrinsicHeight());
}
void ContainIntrinsicHeight::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetContainIntrinsicHeight(state.ParentStyle()->ContainIntrinsicHeight());
}
void ContainIntrinsicHeight::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetContainIntrinsicHeight(StyleBuilderConverter::ConvertIntrinsicDimension(state, value));
}

// contain-intrinsic-inline-size

const char* ContainIntrinsicInlineSize::GetPropertyName() const
{
    return "contain-intrinsic-inline-size";
}

const WTF::AtomicString& ContainIntrinsicInlineSize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("contain-intrinsic-inline-size"));
    return name;
}

const char* ContainIntrinsicInlineSize::GetJSPropertyName() const
{
    return "containIntrinsicInlineSize";
}

const CSSProperty* ContainIntrinsicInlineSize::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& ContainIntrinsicInlineSize::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInline(writing_direction, CSSDirectionAwareResolver::PhysicalContainIntrinsicSizeMapping());
}

bool ContainIntrinsicInlineSize::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalContainIntrinsicSizeMapping().Contains(id);
}

// contain-intrinsic-width

const char* ContainIntrinsicWidth::GetPropertyName() const
{
    return "contain-intrinsic-width";
}

const WTF::AtomicString& ContainIntrinsicWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("contain-intrinsic-width"));
    return name;
}

const char* ContainIntrinsicWidth::GetJSPropertyName() const
{
    return "containIntrinsicWidth";
}

void ContainIntrinsicWidth::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetContainIntrinsicWidth(ComputedStyleInitialValues::InitialContainIntrinsicWidth());
}
void ContainIntrinsicWidth::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetContainIntrinsicWidth(state.ParentStyle()->ContainIntrinsicWidth());
}
void ContainIntrinsicWidth::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetContainIntrinsicWidth(StyleBuilderConverter::ConvertIntrinsicDimension(state, value));
}

// container-name

const char* ContainerName::GetPropertyName() const
{
    return "container-name";
}

const WTF::AtomicString& ContainerName::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("container-name"));
    return name;
}

const char* ContainerName::GetJSPropertyName() const
{
    return "containerName";
}

void ContainerName::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetContainerName(ComputedStyleInitialValues::InitialContainerName());
}
void ContainerName::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetContainerName(state.ParentStyle()->ContainerName());
}
void ContainerName::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetContainerName(StyleBuilderConverter::ConvertContainerName(state, value));
}

// container-type

const char* ContainerType::GetPropertyName() const
{
    return "container-type";
}

const WTF::AtomicString& ContainerType::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("container-type"));
    return name;
}

const char* ContainerType::GetJSPropertyName() const
{
    return "containerType";
}

void ContainerType::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetContainerType(ComputedStyleInitialValues::InitialContainerType());
}
void ContainerType::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetContainerType(state.ParentStyle()->ContainerType());
}
void ContainerType::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetContainerType(StyleBuilderConverter::ConvertFlags<EContainerType, CSSValueID::kNormal>(state, value));
}

// content

const char* Content::GetPropertyName() const
{
    return "content";
}

const WTF::AtomicString& Content::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("content"));
    return name;
}

const char* Content::GetJSPropertyName() const
{
    return "content";
}

// content-visibility

const char* ContentVisibility::GetPropertyName() const
{
    return "content-visibility";
}

const WTF::AtomicString& ContentVisibility::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("content-visibility"));
    return name;
}

const char* ContentVisibility::GetJSPropertyName() const
{
    return "contentVisibility";
}

void ContentVisibility::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetContentVisibility(ComputedStyleInitialValues::InitialContentVisibility());
}
void ContentVisibility::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetContentVisibility(state.ParentStyle()->ContentVisibility());
}
void ContentVisibility::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetContentVisibility(To<CSSIdentifierValue>(value).ConvertTo<blink::EContentVisibility>());
}

// counter-increment

const char* CounterIncrement::GetPropertyName() const
{
    return "counter-increment";
}

const WTF::AtomicString& CounterIncrement::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("counter-increment"));
    return name;
}

const char* CounterIncrement::GetJSPropertyName() const
{
    return "counterIncrement";
}

void CounterIncrement::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().ClearIncrementDirectives();
}

void CounterIncrement::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().ClearIncrementDirectives();
    const CounterDirectiveMap* parent_map = state.ParentStyle()->GetCounterDirectives();
    if (!parent_map)
        return;

    CounterDirectiveMap& map = state.StyleBuilder().AccessCounterDirectives();
    DCHECK(!parent_map->empty());

    typedef CounterDirectiveMap::const_iterator Iterator;
    Iterator end = parent_map->end();
    for (Iterator it = parent_map->begin(); it != end; ++it) {
        CounterDirectives& directives = map.insert(it->key, CounterDirectives()).stored_value->value;
        directives.InheritIncrement(it->value);
    }
}

void CounterIncrement::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().ClearIncrementDirectives();

    const auto* list = DynamicTo<CSSValueList>(value);
    if (!list) {
        DCHECK_EQ(To<CSSIdentifierValue>(value).GetValueID(), CSSValueID::kNone);
        return;
    }

    CounterDirectiveMap& map = state.StyleBuilder().AccessCounterDirectives();

    for (const CSSValue* item : *list) {
        const auto& pair = To<CSSValuePair>(*item);
        AtomicString identifier(To<CSSCustomIdentValue>(pair.First()).Value());
        int counter_value = To<CSSPrimitiveValue>(pair.Second()).ComputeInteger(state.CssToLengthConversionData());
        CounterDirectives& directives = map.insert(identifier, CounterDirectives()).stored_value->value;
        directives.AddIncrementValue(counter_value);
    }
    DCHECK(!map.empty());
}

// counter-reset

const char* CounterReset::GetPropertyName() const
{
    return "counter-reset";
}

const WTF::AtomicString& CounterReset::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("counter-reset"));
    return name;
}

const char* CounterReset::GetJSPropertyName() const
{
    return "counterReset";
}

void CounterReset::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().ClearResetDirectives();
}

void CounterReset::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().ClearResetDirectives();
    const CounterDirectiveMap* parent_map = state.ParentStyle()->GetCounterDirectives();
    if (!parent_map)
        return;

    CounterDirectiveMap& map = state.StyleBuilder().AccessCounterDirectives();
    DCHECK(!parent_map->empty());

    typedef CounterDirectiveMap::const_iterator Iterator;
    Iterator end = parent_map->end();
    for (Iterator it = parent_map->begin(); it != end; ++it) {
        CounterDirectives& directives = map.insert(it->key, CounterDirectives()).stored_value->value;
        directives.InheritReset(it->value);
    }
}

void CounterReset::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().ClearResetDirectives();

    const auto* list = DynamicTo<CSSValueList>(value);
    if (!list) {
        DCHECK_EQ(To<CSSIdentifierValue>(value).GetValueID(), CSSValueID::kNone);
        return;
    }

    CounterDirectiveMap& map = state.StyleBuilder().AccessCounterDirectives();

    for (const CSSValue* item : *list) {
        const auto& pair = To<CSSValuePair>(*item);
        AtomicString identifier(To<CSSCustomIdentValue>(pair.First()).Value());
        int counter_value = To<CSSPrimitiveValue>(pair.Second()).ComputeInteger(state.CssToLengthConversionData());
        CounterDirectives& directives = map.insert(identifier, CounterDirectives()).stored_value->value;
        directives.SetResetValue(counter_value);
    }
    DCHECK(!map.empty());
}

// counter-set

const char* CounterSet::GetPropertyName() const
{
    return "counter-set";
}

const WTF::AtomicString& CounterSet::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("counter-set"));
    return name;
}

const char* CounterSet::GetJSPropertyName() const
{
    return "counterSet";
}

void CounterSet::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().ClearSetDirectives();
}

void CounterSet::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().ClearSetDirectives();
    const CounterDirectiveMap* parent_map = state.ParentStyle()->GetCounterDirectives();
    if (!parent_map)
        return;

    CounterDirectiveMap& map = state.StyleBuilder().AccessCounterDirectives();
    DCHECK(!parent_map->empty());

    typedef CounterDirectiveMap::const_iterator Iterator;
    Iterator end = parent_map->end();
    for (Iterator it = parent_map->begin(); it != end; ++it) {
        CounterDirectives& directives = map.insert(it->key, CounterDirectives()).stored_value->value;
        directives.InheritSet(it->value);
    }
}

void CounterSet::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().ClearSetDirectives();

    const auto* list = DynamicTo<CSSValueList>(value);
    if (!list) {
        DCHECK_EQ(To<CSSIdentifierValue>(value).GetValueID(), CSSValueID::kNone);
        return;
    }

    CounterDirectiveMap& map = state.StyleBuilder().AccessCounterDirectives();

    for (const CSSValue* item : *list) {
        const auto& pair = To<CSSValuePair>(*item);
        AtomicString identifier(To<CSSCustomIdentValue>(pair.First()).Value());
        int counter_value = To<CSSPrimitiveValue>(pair.Second()).ComputeInteger(state.CssToLengthConversionData());
        CounterDirectives& directives = map.insert(identifier, CounterDirectives()).stored_value->value;
        directives.SetSetValue(counter_value);
    }
    DCHECK(!map.empty());
}

// cursor

const char* Cursor::GetPropertyName() const
{
    return "cursor";
}

const WTF::AtomicString& Cursor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("cursor"));
    return name;
}

const char* Cursor::GetJSPropertyName() const
{
    return "cursor";
}

// cx

const char* Cx::GetPropertyName() const
{
    return "cx";
}

const WTF::AtomicString& Cx::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("cx"));
    return name;
}

const char* Cx::GetJSPropertyName() const
{
    return "cx";
}

void Cx::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetCx(ComputedStyleInitialValues::InitialCx());
}
void Cx::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetCx(state.ParentStyle()->Cx());
}
void Cx::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetCx(StyleBuilderConverter::ConvertLength(state, value));
}

// cy

const char* Cy::GetPropertyName() const
{
    return "cy";
}

const WTF::AtomicString& Cy::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("cy"));
    return name;
}

const char* Cy::GetJSPropertyName() const
{
    return "cy";
}

void Cy::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetCy(ComputedStyleInitialValues::InitialCy());
}
void Cy::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetCy(state.ParentStyle()->Cy());
}
void Cy::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetCy(StyleBuilderConverter::ConvertLength(state, value));
}

// d

const char* D::GetPropertyName() const
{
    return "d";
}

const WTF::AtomicString& D::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("d"));
    return name;
}

const char* D::GetJSPropertyName() const
{
    return "d";
}

void D::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetD(ComputedStyleInitialValues::InitialD());
}
void D::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetD(state.ParentStyle()->D());
}
void D::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetD(StyleBuilderConverter::ConvertPathOrNone(state, value));
}

// descent-override

const char* DescentOverride::GetPropertyName() const
{
    return "descent-override";
}

const WTF::AtomicString& DescentOverride::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("descent-override"));
    return name;
}

const char* DescentOverride::GetJSPropertyName() const
{
    return "descentOverride";
}

// display

const char* Display::GetPropertyName() const
{
    return "display";
}

const WTF::AtomicString& Display::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("display"));
    return name;
}

const char* Display::GetJSPropertyName() const
{
    return "display";
}

// dominant-baseline

const char* DominantBaseline::GetPropertyName() const
{
    return "dominant-baseline";
}

const WTF::AtomicString& DominantBaseline::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("dominant-baseline"));
    return name;
}

const char* DominantBaseline::GetJSPropertyName() const
{
    return "dominantBaseline";
}

void DominantBaseline::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetDominantBaseline(ComputedStyleInitialValues::InitialDominantBaseline());
}
void DominantBaseline::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetDominantBaseline(state.ParentStyle()->DominantBaseline());
}
void DominantBaseline::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetDominantBaseline(To<CSSIdentifierValue>(value).ConvertTo<blink::EDominantBaseline>());
}

// dynamic-range-limit

CSSExposure DynamicRangeLimit::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSDynamicRangeLimitEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* DynamicRangeLimit::GetPropertyName() const
{
    return "dynamic-range-limit";
}

const WTF::AtomicString& DynamicRangeLimit::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("dynamic-range-limit"));
    return name;
}

const char* DynamicRangeLimit::GetJSPropertyName() const
{
    return "dynamicRangeLimit";
}

void DynamicRangeLimit::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetDynamicRangeLimit(ComputedStyleInitialValues::InitialDynamicRangeLimit());
}
void DynamicRangeLimit::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetDynamicRangeLimit(state.ParentStyle()->GetDynamicRangeLimit());
}
void DynamicRangeLimit::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetDynamicRangeLimit(StyleBuilderConverter::ConvertDynamicRangeLimit(state, value));
}

// empty-cells

const char* EmptyCells::GetPropertyName() const
{
    return "empty-cells";
}

const WTF::AtomicString& EmptyCells::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("empty-cells"));
    return name;
}

const char* EmptyCells::GetJSPropertyName() const
{
    return "emptyCells";
}

void EmptyCells::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetEmptyCells(ComputedStyleInitialValues::InitialEmptyCells());
    state.StyleBuilder().SetEmptyCellsIsInherited(false);
}
void EmptyCells::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetEmptyCells(state.ParentStyle()->EmptyCells());
    state.StyleBuilder().SetEmptyCellsIsInherited(true);
}
void EmptyCells::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetEmptyCells(To<CSSIdentifierValue>(value).ConvertTo<blink::EEmptyCells>());
    state.StyleBuilder().SetEmptyCellsIsInherited(false);
}

// fallback

const char* Fallback::GetPropertyName() const
{
    return "fallback";
}

const WTF::AtomicString& Fallback::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("fallback"));
    return name;
}

const char* Fallback::GetJSPropertyName() const
{
    return "fallback";
}

// field-sizing

const char* FieldSizing::GetPropertyName() const
{
    return "field-sizing";
}

const WTF::AtomicString& FieldSizing::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("field-sizing"));
    return name;
}

const char* FieldSizing::GetJSPropertyName() const
{
    return "fieldSizing";
}

void FieldSizing::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetFieldSizing(ComputedStyleInitialValues::InitialFieldSizing());
}
void FieldSizing::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetFieldSizing(state.ParentStyle()->FieldSizing());
}
void FieldSizing::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetFieldSizing(To<CSSIdentifierValue>(value).ConvertTo<blink::EFieldSizing>());
}

// fill

const char* Fill::GetPropertyName() const
{
    return "fill";
}

const WTF::AtomicString& Fill::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("fill"));
    return name;
}

const char* Fill::GetJSPropertyName() const
{
    return "fill";
}

void Fill::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetFillPaint(ComputedStyleInitialValues::InitialFillPaint());
}

void Fill::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetFillPaint(state.ParentStyle()->FillPaint());
}

// fill-opacity

const char* FillOpacity::GetPropertyName() const
{
    return "fill-opacity";
}

const WTF::AtomicString& FillOpacity::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("fill-opacity"));
    return name;
}

const char* FillOpacity::GetJSPropertyName() const
{
    return "fillOpacity";
}

void FillOpacity::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetFillOpacity(ComputedStyleInitialValues::InitialFillOpacity());
}
void FillOpacity::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetFillOpacity(state.ParentStyle()->FillOpacity());
}
void FillOpacity::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetFillOpacity(StyleBuilderConverter::ConvertAlpha(state, value));
}

// fill-rule

const char* FillRule::GetPropertyName() const
{
    return "fill-rule";
}

const WTF::AtomicString& FillRule::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("fill-rule"));
    return name;
}

const char* FillRule::GetJSPropertyName() const
{
    return "fillRule";
}

void FillRule::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetFillRule(ComputedStyleInitialValues::InitialFillRule());
}
void FillRule::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetFillRule(state.ParentStyle()->FillRule());
}
void FillRule::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetFillRule(To<CSSIdentifierValue>(value).ConvertTo<blink::WindRule>());
}

// filter

const char* Filter::GetPropertyName() const
{
    return "filter";
}

const WTF::AtomicString& Filter::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("filter"));
    return name;
}

const char* Filter::GetJSPropertyName() const
{
    return "filter";
}

void Filter::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetFilter(ComputedStyleInitialValues::InitialFilter());
}
void Filter::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetFilter(state.ParentStyle()->Filter());
}

// flex-basis

const char* FlexBasis::GetPropertyName() const
{
    return "flex-basis";
}

const WTF::AtomicString& FlexBasis::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("flex-basis"));
    return name;
}

const char* FlexBasis::GetJSPropertyName() const
{
    return "flexBasis";
}

void FlexBasis::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetFlexBasis(ComputedStyleInitialValues::InitialFlexBasis());
}
void FlexBasis::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetFlexBasis(state.ParentStyle()->FlexBasis());
}
void FlexBasis::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetFlexBasis(StyleBuilderConverter::ConvertLengthSizing(state, value));
}

// flex-direction

const char* FlexDirection::GetPropertyName() const
{
    return "flex-direction";
}

const WTF::AtomicString& FlexDirection::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("flex-direction"));
    return name;
}

const char* FlexDirection::GetJSPropertyName() const
{
    return "flexDirection";
}

void FlexDirection::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetFlexDirection(ComputedStyleInitialValues::InitialFlexDirection());
}
void FlexDirection::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetFlexDirection(state.ParentStyle()->FlexDirection());
}
void FlexDirection::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetFlexDirection(To<CSSIdentifierValue>(value).ConvertTo<blink::EFlexDirection>());
}

// flex-grow

const char* FlexGrow::GetPropertyName() const
{
    return "flex-grow";
}

const WTF::AtomicString& FlexGrow::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("flex-grow"));
    return name;
}

const char* FlexGrow::GetJSPropertyName() const
{
    return "flexGrow";
}

void FlexGrow::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetFlexGrow(ComputedStyleInitialValues::InitialFlexGrow());
}
void FlexGrow::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetFlexGrow(state.ParentStyle()->FlexGrow());
}
void FlexGrow::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetFlexGrow(To<CSSPrimitiveValue>(value).ConvertTo<float>(state.CssToLengthConversionData()));
}

// flex-shrink

const char* FlexShrink::GetPropertyName() const
{
    return "flex-shrink";
}

const WTF::AtomicString& FlexShrink::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("flex-shrink"));
    return name;
}

const char* FlexShrink::GetJSPropertyName() const
{
    return "flexShrink";
}

void FlexShrink::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetFlexShrink(ComputedStyleInitialValues::InitialFlexShrink());
}
void FlexShrink::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetFlexShrink(state.ParentStyle()->FlexShrink());
}
void FlexShrink::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetFlexShrink(To<CSSPrimitiveValue>(value).ConvertTo<float>(state.CssToLengthConversionData()));
}

// flex-wrap

const char* FlexWrap::GetPropertyName() const
{
    return "flex-wrap";
}

const WTF::AtomicString& FlexWrap::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("flex-wrap"));
    return name;
}

const char* FlexWrap::GetJSPropertyName() const
{
    return "flexWrap";
}

void FlexWrap::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetFlexWrap(ComputedStyleInitialValues::InitialFlexWrap());
}
void FlexWrap::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetFlexWrap(state.ParentStyle()->FlexWrap());
}
void FlexWrap::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetFlexWrap(To<CSSIdentifierValue>(value).ConvertTo<blink::EFlexWrap>());
}

// float

const char* Float::GetPropertyName() const
{
    return "float";
}

const WTF::AtomicString& Float::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("float"));
    return name;
}

const char* Float::GetJSPropertyName() const
{
    return "float";
}

void Float::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetFloating(ComputedStyleInitialValues::InitialFloating());
}
void Float::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetFloating(state.ParentStyle()->Floating());
}
void Float::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetFloating(To<CSSIdentifierValue>(value).ConvertTo<blink::EFloat>());
}

// flood-color

const char* FloodColor::GetPropertyName() const
{
    return "flood-color";
}

const WTF::AtomicString& FloodColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("flood-color"));
    return name;
}

const char* FloodColor::GetJSPropertyName() const
{
    return "floodColor";
}

void FloodColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetFloodColor(ComputedStyleInitialValues::InitialFloodColor());
}

void FloodColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetFloodColor(state.ParentStyle()->FloodColor());
}

void FloodColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetFloodColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// flood-opacity

const char* FloodOpacity::GetPropertyName() const
{
    return "flood-opacity";
}

const WTF::AtomicString& FloodOpacity::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("flood-opacity"));
    return name;
}

const char* FloodOpacity::GetJSPropertyName() const
{
    return "floodOpacity";
}

void FloodOpacity::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetFloodOpacity(ComputedStyleInitialValues::InitialFloodOpacity());
}
void FloodOpacity::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetFloodOpacity(state.ParentStyle()->FloodOpacity());
}
void FloodOpacity::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetFloodOpacity(StyleBuilderConverter::ConvertAlpha(state, value));
}

// font-display

const char* FontDisplay::GetPropertyName() const
{
    return "font-display";
}

const WTF::AtomicString& FontDisplay::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("font-display"));
    return name;
}

const char* FontDisplay::GetJSPropertyName() const
{
    return "fontDisplay";
}

// grid-auto-columns

const char* GridAutoColumns::GetPropertyName() const
{
    return "grid-auto-columns";
}

const WTF::AtomicString& GridAutoColumns::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-auto-columns"));
    return name;
}

const char* GridAutoColumns::GetJSPropertyName() const
{
    return "gridAutoColumns";
}

void GridAutoColumns::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridAutoColumns(ComputedStyleInitialValues::InitialGridAutoColumns());
}
void GridAutoColumns::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridAutoColumns(state.ParentStyle()->GridAutoColumns());
}
void GridAutoColumns::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetGridAutoColumns(StyleBuilderConverter::ConvertGridTrackSizeList(state, value));
}

// grid-auto-flow

const char* GridAutoFlow::GetPropertyName() const
{
    return "grid-auto-flow";
}

const WTF::AtomicString& GridAutoFlow::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-auto-flow"));
    return name;
}

const char* GridAutoFlow::GetJSPropertyName() const
{
    return "gridAutoFlow";
}

void GridAutoFlow::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridAutoFlow(ComputedStyleInitialValues::InitialGridAutoFlow());
}
void GridAutoFlow::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridAutoFlow(state.ParentStyle()->GetGridAutoFlow());
}
void GridAutoFlow::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetGridAutoFlow(StyleBuilderConverter::ConvertGridAutoFlow(state, value));
}

// grid-auto-rows

const char* GridAutoRows::GetPropertyName() const
{
    return "grid-auto-rows";
}

const WTF::AtomicString& GridAutoRows::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-auto-rows"));
    return name;
}

const char* GridAutoRows::GetJSPropertyName() const
{
    return "gridAutoRows";
}

void GridAutoRows::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridAutoRows(ComputedStyleInitialValues::InitialGridAutoRows());
}
void GridAutoRows::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridAutoRows(state.ParentStyle()->GridAutoRows());
}
void GridAutoRows::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetGridAutoRows(StyleBuilderConverter::ConvertGridTrackSizeList(state, value));
}

// grid-column-end

const char* GridColumnEnd::GetPropertyName() const
{
    return "grid-column-end";
}

const WTF::AtomicString& GridColumnEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-column-end"));
    return name;
}

const char* GridColumnEnd::GetJSPropertyName() const
{
    return "gridColumnEnd";
}

void GridColumnEnd::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridColumnEnd(ComputedStyleInitialValues::InitialGridColumnEnd());
}
void GridColumnEnd::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridColumnEnd(state.ParentStyle()->GridColumnEnd());
}
void GridColumnEnd::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetGridColumnEnd(StyleBuilderConverter::ConvertGridPosition(state, value));
}

// grid-column-start

const char* GridColumnStart::GetPropertyName() const
{
    return "grid-column-start";
}

const WTF::AtomicString& GridColumnStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-column-start"));
    return name;
}

const char* GridColumnStart::GetJSPropertyName() const
{
    return "gridColumnStart";
}

void GridColumnStart::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridColumnStart(ComputedStyleInitialValues::InitialGridColumnStart());
}
void GridColumnStart::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridColumnStart(state.ParentStyle()->GridColumnStart());
}
void GridColumnStart::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetGridColumnStart(StyleBuilderConverter::ConvertGridPosition(state, value));
}

// grid-row-end

const char* GridRowEnd::GetPropertyName() const
{
    return "grid-row-end";
}

const WTF::AtomicString& GridRowEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-row-end"));
    return name;
}

const char* GridRowEnd::GetJSPropertyName() const
{
    return "gridRowEnd";
}

void GridRowEnd::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridRowEnd(ComputedStyleInitialValues::InitialGridRowEnd());
}
void GridRowEnd::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridRowEnd(state.ParentStyle()->GridRowEnd());
}
void GridRowEnd::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetGridRowEnd(StyleBuilderConverter::ConvertGridPosition(state, value));
}

// grid-row-start

const char* GridRowStart::GetPropertyName() const
{
    return "grid-row-start";
}

const WTF::AtomicString& GridRowStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-row-start"));
    return name;
}

const char* GridRowStart::GetJSPropertyName() const
{
    return "gridRowStart";
}

void GridRowStart::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridRowStart(ComputedStyleInitialValues::InitialGridRowStart());
}
void GridRowStart::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridRowStart(state.ParentStyle()->GridRowStart());
}
void GridRowStart::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetGridRowStart(StyleBuilderConverter::ConvertGridPosition(state, value));
}

// grid-template-areas

const char* GridTemplateAreas::GetPropertyName() const
{
    return "grid-template-areas";
}

const WTF::AtomicString& GridTemplateAreas::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-template-areas"));
    return name;
}

const char* GridTemplateAreas::GetJSPropertyName() const
{
    return "gridTemplateAreas";
}

void GridTemplateAreas::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridTemplateAreas(ComputedStyleInitialValues::InitialGridTemplateAreas());
}
void GridTemplateAreas::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridTemplateAreas(state.ParentStyle()->GridTemplateAreas());
}
void GridTemplateAreas::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetGridTemplateAreas(StyleBuilderConverter::ConvertGridTemplateAreas(state, value));
}

// grid-template-columns

const char* GridTemplateColumns::GetPropertyName() const
{
    return "grid-template-columns";
}

const WTF::AtomicString& GridTemplateColumns::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-template-columns"));
    return name;
}

const char* GridTemplateColumns::GetJSPropertyName() const
{
    return "gridTemplateColumns";
}

void GridTemplateColumns::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridTemplateColumns(ComputedStyleInitialValues::InitialGridTemplateColumns());
}

void GridTemplateColumns::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridTemplateColumns(state.ParentStyle()->GridTemplateColumns());
}

void GridTemplateColumns::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    ComputedGridTrackList computed_grid_track_list;
    StyleBuilderConverter::ConvertGridTrackList(value, computed_grid_track_list, state);
    state.StyleBuilder().SetGridTemplateColumns(computed_grid_track_list);
}

// grid-template-rows

const char* GridTemplateRows::GetPropertyName() const
{
    return "grid-template-rows";
}

const WTF::AtomicString& GridTemplateRows::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-template-rows"));
    return name;
}

const char* GridTemplateRows::GetJSPropertyName() const
{
    return "gridTemplateRows";
}

void GridTemplateRows::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridTemplateRows(ComputedStyleInitialValues::InitialGridTemplateRows());
}

void GridTemplateRows::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetGridTemplateRows(state.ParentStyle()->GridTemplateRows());
}

void GridTemplateRows::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    ComputedGridTrackList computed_grid_track_list;
    StyleBuilderConverter::ConvertGridTrackList(value, computed_grid_track_list, state);
    state.StyleBuilder().SetGridTemplateRows(computed_grid_track_list);
}

// height

const char* Height::GetPropertyName() const
{
    return "height";
}

const WTF::AtomicString& Height::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("height"));
    return name;
}

const char* Height::GetJSPropertyName() const
{
    return "height";
}

bool Height::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalSizeMapping().Contains(id);
}

void Height::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetHeight(ComputedStyleInitialValues::InitialHeight());
}
void Height::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetHeight(state.ParentStyle()->Height());
}
void Height::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    blink::AnchorScope anchor_scope(blink::AnchorScope::Mode::kHeight, state.CssToLengthConversionData().GetAnchorEvaluator());
    state.StyleBuilder().SetHeight(StyleBuilderConverter::ConvertLengthSizing(state, value));
}

// hyphenate-character

const char* HyphenateCharacter::GetPropertyName() const
{
    return "hyphenate-character";
}

const WTF::AtomicString& HyphenateCharacter::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("hyphenate-character"));
    return name;
}

const char* HyphenateCharacter::GetJSPropertyName() const
{
    return "hyphenateCharacter";
}

void HyphenateCharacter::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetHyphenationString(ComputedStyleInitialValues::InitialHyphenationString());
}
void HyphenateCharacter::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetHyphenationString(state.ParentStyle()->HyphenationString());
}
void HyphenateCharacter::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetHyphenationString(StyleBuilderConverter::ConvertString<CSSValueID::kAuto>(state, value));
}

// hyphenate-limit-chars

const char* HyphenateLimitChars::GetPropertyName() const
{
    return "hyphenate-limit-chars";
}

const WTF::AtomicString& HyphenateLimitChars::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("hyphenate-limit-chars"));
    return name;
}

const char* HyphenateLimitChars::GetJSPropertyName() const
{
    return "hyphenateLimitChars";
}

void HyphenateLimitChars::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetHyphenateLimitChars(ComputedStyleInitialValues::InitialHyphenateLimitChars());
}
void HyphenateLimitChars::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetHyphenateLimitChars(state.ParentStyle()->HyphenateLimitChars());
}
void HyphenateLimitChars::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetHyphenateLimitChars(StyleBuilderConverter::ConvertHyphenateLimitChars(state, value));
}

// hyphens

const char* Hyphens::GetPropertyName() const
{
    return "hyphens";
}

const WTF::AtomicString& Hyphens::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("hyphens"));
    return name;
}

const char* Hyphens::GetJSPropertyName() const
{
    return "hyphens";
}

void Hyphens::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetHyphens(ComputedStyleInitialValues::InitialHyphens());
}
void Hyphens::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetHyphens(state.ParentStyle()->GetHyphens());
}
void Hyphens::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetHyphens(To<CSSIdentifierValue>(value).ConvertTo<blink::Hyphens>());
}

// image-orientation

const char* ImageOrientation::GetPropertyName() const
{
    return "image-orientation";
}

const WTF::AtomicString& ImageOrientation::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("image-orientation"));
    return name;
}

const char* ImageOrientation::GetJSPropertyName() const
{
    return "imageOrientation";
}

void ImageOrientation::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetImageOrientation(ComputedStyleInitialValues::InitialImageOrientation());
}
void ImageOrientation::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetImageOrientation(state.ParentStyle()->ImageOrientation());
}
void ImageOrientation::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetImageOrientation(StyleBuilderConverter::ConvertImageOrientation(state, value));
}

// image-rendering

const char* ImageRendering::GetPropertyName() const
{
    return "image-rendering";
}

const WTF::AtomicString& ImageRendering::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("image-rendering"));
    return name;
}

const char* ImageRendering::GetJSPropertyName() const
{
    return "imageRendering";
}

void ImageRendering::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetImageRendering(ComputedStyleInitialValues::InitialImageRendering());
}
void ImageRendering::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetImageRendering(state.ParentStyle()->ImageRendering());
}
void ImageRendering::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetImageRendering(To<CSSIdentifierValue>(value).ConvertTo<blink::EImageRendering>());
}

// inherits

const char* Inherits::GetPropertyName() const
{
    return "inherits";
}

const WTF::AtomicString& Inherits::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("inherits"));
    return name;
}

const char* Inherits::GetJSPropertyName() const
{
    return "inherits";
}

// initial-letter

const char* InitialLetter::GetPropertyName() const
{
    return "initial-letter";
}

const WTF::AtomicString& InitialLetter::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("initial-letter"));
    return name;
}

const char* InitialLetter::GetJSPropertyName() const
{
    return "initialLetter";
}

void InitialLetter::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInitialLetter(ComputedStyleInitialValues::InitialInitialLetter());
}
void InitialLetter::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInitialLetter(state.ParentStyle()->InitialLetter());
}
void InitialLetter::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInitialLetter(StyleBuilderConverter::ConvertInitialLetter(state, value));
}

// initial-value

const char* InitialValue::GetPropertyName() const
{
    return "initial-value";
}

const WTF::AtomicString& InitialValue::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("initial-value"));
    return name;
}

const char* InitialValue::GetJSPropertyName() const
{
    return "initialValue";
}

// inline-size

const char* InlineSize::GetPropertyName() const
{
    return "inline-size";
}

const WTF::AtomicString& InlineSize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("inline-size"));
    return name;
}

const char* InlineSize::GetJSPropertyName() const
{
    return "inlineSize";
}

const CSSProperty* InlineSize::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& InlineSize::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInline(writing_direction, CSSDirectionAwareResolver::PhysicalSizeMapping());
}

bool InlineSize::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalSizeMapping().Contains(id);
}

// inset-block-end

const char* InsetBlockEnd::GetPropertyName() const
{
    return "inset-block-end";
}

const WTF::AtomicString& InsetBlockEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("inset-block-end"));
    return name;
}

const char* InsetBlockEnd::GetJSPropertyName() const
{
    return "insetBlockEnd";
}

const CSSProperty* InsetBlockEnd::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& InsetBlockEnd::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockEnd(writing_direction, CSSDirectionAwareResolver::PhysicalInsetMapping());
}

bool InsetBlockEnd::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalInsetMapping().Contains(id);
}

// inset-block-start

const char* InsetBlockStart::GetPropertyName() const
{
    return "inset-block-start";
}

const WTF::AtomicString& InsetBlockStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("inset-block-start"));
    return name;
}

const char* InsetBlockStart::GetJSPropertyName() const
{
    return "insetBlockStart";
}

const CSSProperty* InsetBlockStart::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& InsetBlockStart::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockStart(writing_direction, CSSDirectionAwareResolver::PhysicalInsetMapping());
}

bool InsetBlockStart::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalInsetMapping().Contains(id);
}

// inset-inline-end

const char* InsetInlineEnd::GetPropertyName() const
{
    return "inset-inline-end";
}

const WTF::AtomicString& InsetInlineEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("inset-inline-end"));
    return name;
}

const char* InsetInlineEnd::GetJSPropertyName() const
{
    return "insetInlineEnd";
}

const CSSProperty* InsetInlineEnd::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& InsetInlineEnd::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineEnd(writing_direction, CSSDirectionAwareResolver::PhysicalInsetMapping());
}

bool InsetInlineEnd::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalInsetMapping().Contains(id);
}

// inset-inline-start

const char* InsetInlineStart::GetPropertyName() const
{
    return "inset-inline-start";
}

const WTF::AtomicString& InsetInlineStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("inset-inline-start"));
    return name;
}

const char* InsetInlineStart::GetJSPropertyName() const
{
    return "insetInlineStart";
}

const CSSProperty* InsetInlineStart::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& InsetInlineStart::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineStart(writing_direction, CSSDirectionAwareResolver::PhysicalInsetMapping());
}

bool InsetInlineStart::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalInsetMapping().Contains(id);
}

// interactivity

CSSExposure Interactivity::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSInertEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* Interactivity::GetPropertyName() const
{
    return "interactivity";
}

const WTF::AtomicString& Interactivity::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("interactivity"));
    return name;
}

const char* Interactivity::GetJSPropertyName() const
{
    return "interactivity";
}

void Interactivity::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInteractivity(ComputedStyleInitialValues::InitialInteractivity());
}
void Interactivity::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInteractivity(state.ParentStyle()->Interactivity());
}
void Interactivity::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInteractivity(To<CSSIdentifierValue>(value).ConvertTo<blink::EInteractivity>());
}

// -internal-align-content-block

CSSExposure InternalAlignContentBlock::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalAlignContentBlock::GetPropertyName() const
{
    return "-internal-align-content-block";
}

const WTF::AtomicString& InternalAlignContentBlock::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-align-content-block"));
    return name;
}

const char* InternalAlignContentBlock::GetJSPropertyName() const
{
    return "internalAlignContentBlock";
}

void InternalAlignContentBlock::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetAlignContentBlockCenter(ComputedStyleInitialValues::InitialAlignContentBlockCenter());
}
void InternalAlignContentBlock::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetAlignContentBlockCenter(state.ParentStyle()->AlignContentBlockCenter());
}
void InternalAlignContentBlock::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetAlignContentBlockCenter(StyleBuilderConverter::ConvertInternalAlignContentBlock(state, value));
}

// -internal-empty-line-height

CSSExposure InternalEmptyLineHeight::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalEmptyLineHeight::GetPropertyName() const
{
    return "-internal-empty-line-height";
}

const WTF::AtomicString& InternalEmptyLineHeight::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-empty-line-height"));
    return name;
}

const char* InternalEmptyLineHeight::GetJSPropertyName() const
{
    return "internalEmptyLineHeight";
}

void InternalEmptyLineHeight::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetHasLineIfEmpty(ComputedStyleInitialValues::InitialHasLineIfEmpty());
}
void InternalEmptyLineHeight::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetHasLineIfEmpty(state.ParentStyle()->HasLineIfEmpty());
}
void InternalEmptyLineHeight::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetHasLineIfEmpty(StyleBuilderConverter::ConvertInternalEmptyLineHeight(state, value));
}

// -internal-font-size-delta

CSSExposure InternalFontSizeDelta::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalFontSizeDelta::GetPropertyName() const
{
    return "-internal-font-size-delta";
}

const WTF::AtomicString& InternalFontSizeDelta::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-font-size-delta"));
    return name;
}

const char* InternalFontSizeDelta::GetJSPropertyName() const
{
    return "internalFontSizeDelta";
}

void InternalFontSizeDelta::ApplyInitial(StyleResolverState& state) const
{
    // Intentionally empty.
}
void InternalFontSizeDelta::ApplyInherit(StyleResolverState& state) const
{
    // Intentionally empty.
}
void InternalFontSizeDelta::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    // Intentionally empty.
}

// -internal-forced-background-color

CSSExposure InternalForcedBackgroundColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalForcedBackgroundColor::GetPropertyName() const
{
    return "-internal-forced-background-color";
}

const WTF::AtomicString& InternalForcedBackgroundColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-forced-background-color"));
    return name;
}

const char* InternalForcedBackgroundColor::GetJSPropertyName() const
{
    return "internalForcedBackgroundColor";
}

void InternalForcedBackgroundColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalForcedBackgroundColor(ComputedStyleInitialValues::InitialInternalForcedBackgroundColor());
}

void InternalForcedBackgroundColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalForcedBackgroundColor(state.ParentStyle()->InternalForcedBackgroundColor());
}

void InternalForcedBackgroundColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalForcedBackgroundColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// -internal-forced-border-color

CSSExposure InternalForcedBorderColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalForcedBorderColor::GetPropertyName() const
{
    return "-internal-forced-border-color";
}

const WTF::AtomicString& InternalForcedBorderColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-forced-border-color"));
    return name;
}

const char* InternalForcedBorderColor::GetJSPropertyName() const
{
    return "internalForcedBorderColor";
}

void InternalForcedBorderColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalForcedBorderColor(StyleColor::CurrentColor());
}

void InternalForcedBorderColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalForcedBorderColor(state.ParentStyle()->InternalForcedBorderColor());
}

void InternalForcedBorderColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalForcedBorderColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// -internal-forced-color

CSSExposure InternalForcedColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalForcedColor::GetPropertyName() const
{
    return "-internal-forced-color";
}

const WTF::AtomicString& InternalForcedColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-forced-color"));
    return name;
}

const char* InternalForcedColor::GetJSPropertyName() const
{
    return "internalForcedColor";
}

// -internal-forced-outline-color

CSSExposure InternalForcedOutlineColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalForcedOutlineColor::GetPropertyName() const
{
    return "-internal-forced-outline-color";
}

const WTF::AtomicString& InternalForcedOutlineColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-forced-outline-color"));
    return name;
}

const char* InternalForcedOutlineColor::GetJSPropertyName() const
{
    return "internalForcedOutlineColor";
}

void InternalForcedOutlineColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalForcedOutlineColor(StyleColor::CurrentColor());
}

void InternalForcedOutlineColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalForcedOutlineColor(state.ParentStyle()->InternalForcedOutlineColor());
}

void InternalForcedOutlineColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalForcedOutlineColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// -internal-forced-visited-color

CSSExposure InternalForcedVisitedColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalForcedVisitedColor::GetPropertyName() const
{
    return "-internal-forced-visited-color";
}

const WTF::AtomicString& InternalForcedVisitedColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-forced-visited-color"));
    return name;
}

const char* InternalForcedVisitedColor::GetJSPropertyName() const
{
    return "internalForcedVisitedColor";
}

// -internal-overflow-block

CSSExposure InternalOverflowBlock::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalOverflowBlock::GetPropertyName() const
{
    return "-internal-overflow-block";
}

const WTF::AtomicString& InternalOverflowBlock::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-overflow-block"));
    return name;
}

const char* InternalOverflowBlock::GetJSPropertyName() const
{
    return "internalOverflowBlock";
}

const CSSProperty* InternalOverflowBlock::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& InternalOverflowBlock::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlock(writing_direction, CSSDirectionAwareResolver::PhysicalOverflowMapping());
}

bool InternalOverflowBlock::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalOverflowMapping().Contains(id);
}

// -internal-overflow-inline

CSSExposure InternalOverflowInline::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalOverflowInline::GetPropertyName() const
{
    return "-internal-overflow-inline";
}

const WTF::AtomicString& InternalOverflowInline::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-overflow-inline"));
    return name;
}

const char* InternalOverflowInline::GetJSPropertyName() const
{
    return "internalOverflowInline";
}

const CSSProperty* InternalOverflowInline::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& InternalOverflowInline::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInline(writing_direction, CSSDirectionAwareResolver::PhysicalOverflowMapping());
}

bool InternalOverflowInline::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalOverflowMapping().Contains(id);
}

// -internal-visited-background-color

CSSExposure InternalVisitedBackgroundColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedBackgroundColor::GetPropertyName() const
{
    return "-internal-visited-background-color";
}

const WTF::AtomicString& InternalVisitedBackgroundColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-background-color"));
    return name;
}

const char* InternalVisitedBackgroundColor::GetJSPropertyName() const
{
    return "internalVisitedBackgroundColor";
}

void InternalVisitedBackgroundColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedBackgroundColor(ComputedStyleInitialValues::InitialBackgroundColor());
}

void InternalVisitedBackgroundColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedBackgroundColor(state.ParentStyle()->BackgroundColor());
}

void InternalVisitedBackgroundColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalVisitedBackgroundColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

// -internal-visited-border-block-end-color

CSSExposure InternalVisitedBorderBlockEndColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedBorderBlockEndColor::GetPropertyName() const
{
    return "-internal-visited-border-block-end-color";
}

const WTF::AtomicString& InternalVisitedBorderBlockEndColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-block-end-color"));
    return name;
}

const char* InternalVisitedBorderBlockEndColor::GetJSPropertyName() const
{
    return "internalVisitedBorderBlockEndColor";
}

const CSSProperty* InternalVisitedBorderBlockEndColor::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& InternalVisitedBorderBlockEndColor::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockEnd(writing_direction, CSSDirectionAwareResolver::PhysicalVisitedBorderColorMapping());
}

bool InternalVisitedBorderBlockEndColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalVisitedBorderColorMapping().Contains(id);
}

// -internal-visited-border-block-start-color

CSSExposure InternalVisitedBorderBlockStartColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedBorderBlockStartColor::GetPropertyName() const
{
    return "-internal-visited-border-block-start-color";
}

const WTF::AtomicString& InternalVisitedBorderBlockStartColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-block-start-color"));
    return name;
}

const char* InternalVisitedBorderBlockStartColor::GetJSPropertyName() const
{
    return "internalVisitedBorderBlockStartColor";
}

const CSSProperty* InternalVisitedBorderBlockStartColor::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& InternalVisitedBorderBlockStartColor::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockStart(writing_direction, CSSDirectionAwareResolver::PhysicalVisitedBorderColorMapping());
}

bool InternalVisitedBorderBlockStartColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalVisitedBorderColorMapping().Contains(id);
}

// -internal-visited-border-bottom-color

CSSExposure InternalVisitedBorderBottomColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedBorderBottomColor::GetPropertyName() const
{
    return "-internal-visited-border-bottom-color";
}

const WTF::AtomicString& InternalVisitedBorderBottomColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-bottom-color"));
    return name;
}

const char* InternalVisitedBorderBottomColor::GetJSPropertyName() const
{
    return "internalVisitedBorderBottomColor";
}

bool InternalVisitedBorderBottomColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalVisitedBorderColorMapping().Contains(id);
}

void InternalVisitedBorderBottomColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedBorderBottomColor(StyleColor::CurrentColor());
}

void InternalVisitedBorderBottomColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedBorderBottomColor(state.ParentStyle()->BorderBottomColor());
}

void InternalVisitedBorderBottomColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalVisitedBorderBottomColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

// -internal-visited-border-inline-end-color

CSSExposure InternalVisitedBorderInlineEndColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedBorderInlineEndColor::GetPropertyName() const
{
    return "-internal-visited-border-inline-end-color";
}

const WTF::AtomicString& InternalVisitedBorderInlineEndColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-inline-end-color"));
    return name;
}

const char* InternalVisitedBorderInlineEndColor::GetJSPropertyName() const
{
    return "internalVisitedBorderInlineEndColor";
}

const CSSProperty* InternalVisitedBorderInlineEndColor::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& InternalVisitedBorderInlineEndColor::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineEnd(writing_direction, CSSDirectionAwareResolver::PhysicalVisitedBorderColorMapping());
}

bool InternalVisitedBorderInlineEndColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalVisitedBorderColorMapping().Contains(id);
}

// -internal-visited-border-inline-start-color

CSSExposure InternalVisitedBorderInlineStartColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedBorderInlineStartColor::GetPropertyName() const
{
    return "-internal-visited-border-inline-start-color";
}

const WTF::AtomicString& InternalVisitedBorderInlineStartColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-inline-start-color"));
    return name;
}

const char* InternalVisitedBorderInlineStartColor::GetJSPropertyName() const
{
    return "internalVisitedBorderInlineStartColor";
}

const CSSProperty* InternalVisitedBorderInlineStartColor::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& InternalVisitedBorderInlineStartColor::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineStart(writing_direction, CSSDirectionAwareResolver::PhysicalVisitedBorderColorMapping());
}

bool InternalVisitedBorderInlineStartColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalVisitedBorderColorMapping().Contains(id);
}

// -internal-visited-border-left-color

CSSExposure InternalVisitedBorderLeftColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedBorderLeftColor::GetPropertyName() const
{
    return "-internal-visited-border-left-color";
}

const WTF::AtomicString& InternalVisitedBorderLeftColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-left-color"));
    return name;
}

const char* InternalVisitedBorderLeftColor::GetJSPropertyName() const
{
    return "internalVisitedBorderLeftColor";
}

bool InternalVisitedBorderLeftColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalVisitedBorderColorMapping().Contains(id);
}

void InternalVisitedBorderLeftColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedBorderLeftColor(StyleColor::CurrentColor());
}

void InternalVisitedBorderLeftColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedBorderLeftColor(state.ParentStyle()->BorderLeftColor());
}

void InternalVisitedBorderLeftColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalVisitedBorderLeftColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

// -internal-visited-border-right-color

CSSExposure InternalVisitedBorderRightColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedBorderRightColor::GetPropertyName() const
{
    return "-internal-visited-border-right-color";
}

const WTF::AtomicString& InternalVisitedBorderRightColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-right-color"));
    return name;
}

const char* InternalVisitedBorderRightColor::GetJSPropertyName() const
{
    return "internalVisitedBorderRightColor";
}

bool InternalVisitedBorderRightColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalVisitedBorderColorMapping().Contains(id);
}

void InternalVisitedBorderRightColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedBorderRightColor(StyleColor::CurrentColor());
}

void InternalVisitedBorderRightColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedBorderRightColor(state.ParentStyle()->BorderRightColor());
}

void InternalVisitedBorderRightColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalVisitedBorderRightColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

// -internal-visited-border-top-color

CSSExposure InternalVisitedBorderTopColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedBorderTopColor::GetPropertyName() const
{
    return "-internal-visited-border-top-color";
}

const WTF::AtomicString& InternalVisitedBorderTopColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-border-top-color"));
    return name;
}

const char* InternalVisitedBorderTopColor::GetJSPropertyName() const
{
    return "internalVisitedBorderTopColor";
}

bool InternalVisitedBorderTopColor::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalVisitedBorderColorMapping().Contains(id);
}

void InternalVisitedBorderTopColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedBorderTopColor(StyleColor::CurrentColor());
}

void InternalVisitedBorderTopColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedBorderTopColor(state.ParentStyle()->BorderTopColor());
}

void InternalVisitedBorderTopColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalVisitedBorderTopColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

// -internal-visited-caret-color

CSSExposure InternalVisitedCaretColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedCaretColor::GetPropertyName() const
{
    return "-internal-visited-caret-color";
}

const WTF::AtomicString& InternalVisitedCaretColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-caret-color"));
    return name;
}

const char* InternalVisitedCaretColor::GetJSPropertyName() const
{
    return "internalVisitedCaretColor";
}

void InternalVisitedCaretColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedCaretColor(StyleAutoColor::AutoColor());
}

void InternalVisitedCaretColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedCaretColor(state.ParentStyle()->CaretColor());
}

void InternalVisitedCaretColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalVisitedCaretColor(StyleBuilderConverter::ConvertStyleAutoColor(state, value, true));
}

// -internal-visited-column-rule-color

CSSExposure InternalVisitedColumnRuleColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedColumnRuleColor::GetPropertyName() const
{
    return "-internal-visited-column-rule-color";
}

const WTF::AtomicString& InternalVisitedColumnRuleColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-column-rule-color"));
    return name;
}

const char* InternalVisitedColumnRuleColor::GetJSPropertyName() const
{
    return "internalVisitedColumnRuleColor";
}

void InternalVisitedColumnRuleColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedColumnRuleColor(ComputedStyleInitialValues::InitialInternalVisitedColumnRuleColor());
}
void InternalVisitedColumnRuleColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedColumnRuleColor(state.ParentStyle()->InternalVisitedColumnRuleColor());
}
void InternalVisitedColumnRuleColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalVisitedColumnRuleColor(StyleBuilderConverter::ConvertGapDecorationColorDataList(state, value));
}

// -internal-visited-fill

CSSExposure InternalVisitedFill::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedFill::GetPropertyName() const
{
    return "-internal-visited-fill";
}

const WTF::AtomicString& InternalVisitedFill::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-fill"));
    return name;
}

const char* InternalVisitedFill::GetJSPropertyName() const
{
    return "internalVisitedFill";
}

void InternalVisitedFill::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedFillPaint(ComputedStyleInitialValues::InitialFillPaint());
}

void InternalVisitedFill::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedFillPaint(state.ParentStyle()->FillPaint());
}

void InternalVisitedFill::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalVisitedFillPaint(StyleBuilderConverter::ConvertSVGPaint(state, value, true));
}

// -internal-visited-outline-color

CSSExposure InternalVisitedOutlineColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedOutlineColor::GetPropertyName() const
{
    return "-internal-visited-outline-color";
}

const WTF::AtomicString& InternalVisitedOutlineColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-outline-color"));
    return name;
}

const char* InternalVisitedOutlineColor::GetJSPropertyName() const
{
    return "internalVisitedOutlineColor";
}

void InternalVisitedOutlineColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedOutlineColor(StyleColor::CurrentColor());
}

void InternalVisitedOutlineColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedOutlineColor(state.ParentStyle()->OutlineColor());
}

void InternalVisitedOutlineColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalVisitedOutlineColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

// -internal-visited-stroke

CSSExposure InternalVisitedStroke::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedStroke::GetPropertyName() const
{
    return "-internal-visited-stroke";
}

const WTF::AtomicString& InternalVisitedStroke::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-stroke"));
    return name;
}

const char* InternalVisitedStroke::GetJSPropertyName() const
{
    return "internalVisitedStroke";
}

void InternalVisitedStroke::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedStrokePaint(ComputedStyleInitialValues::InitialStrokePaint());
}

void InternalVisitedStroke::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedStrokePaint(state.ParentStyle()->StrokePaint());
}

void InternalVisitedStroke::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalVisitedStrokePaint(StyleBuilderConverter::ConvertSVGPaint(state, value, true));
}

// -internal-visited-text-decoration-color

CSSExposure InternalVisitedTextDecorationColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedTextDecorationColor::GetPropertyName() const
{
    return "-internal-visited-text-decoration-color";
}

const WTF::AtomicString& InternalVisitedTextDecorationColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-text-decoration-color"));
    return name;
}

const char* InternalVisitedTextDecorationColor::GetJSPropertyName() const
{
    return "internalVisitedTextDecorationColor";
}

void InternalVisitedTextDecorationColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedTextDecorationColor(StyleColor::CurrentColor());
}

void InternalVisitedTextDecorationColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedTextDecorationColor(state.ParentStyle()->TextDecorationColor());
}

void InternalVisitedTextDecorationColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalVisitedTextDecorationColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

// -internal-visited-text-emphasis-color

CSSExposure InternalVisitedTextEmphasisColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedTextEmphasisColor::GetPropertyName() const
{
    return "-internal-visited-text-emphasis-color";
}

const WTF::AtomicString& InternalVisitedTextEmphasisColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-text-emphasis-color"));
    return name;
}

const char* InternalVisitedTextEmphasisColor::GetJSPropertyName() const
{
    return "internalVisitedTextEmphasisColor";
}

void InternalVisitedTextEmphasisColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedTextEmphasisColor(StyleColor::CurrentColor());
}

void InternalVisitedTextEmphasisColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedTextEmphasisColor(state.ParentStyle()->TextEmphasisColor());
}

void InternalVisitedTextEmphasisColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalVisitedTextEmphasisColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

// -internal-visited-text-fill-color

CSSExposure InternalVisitedTextFillColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedTextFillColor::GetPropertyName() const
{
    return "-internal-visited-text-fill-color";
}

const WTF::AtomicString& InternalVisitedTextFillColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-text-fill-color"));
    return name;
}

const char* InternalVisitedTextFillColor::GetJSPropertyName() const
{
    return "internalVisitedTextFillColor";
}

void InternalVisitedTextFillColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedTextFillColor(StyleColor::CurrentColor());
}

void InternalVisitedTextFillColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedTextFillColor(state.ParentStyle()->TextFillColor());
}

void InternalVisitedTextFillColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalVisitedTextFillColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

// -internal-visited-text-stroke-color

CSSExposure InternalVisitedTextStrokeColor::Exposure(const ExecutionContext* execution_context) const
{
    return CSSExposure::kUA;
}

const char* InternalVisitedTextStrokeColor::GetPropertyName() const
{
    return "-internal-visited-text-stroke-color";
}

const WTF::AtomicString& InternalVisitedTextStrokeColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-internal-visited-text-stroke-color"));
    return name;
}

const char* InternalVisitedTextStrokeColor::GetJSPropertyName() const
{
    return "internalVisitedTextStrokeColor";
}

void InternalVisitedTextStrokeColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedTextStrokeColor(StyleColor::CurrentColor());
}

void InternalVisitedTextStrokeColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInternalVisitedTextStrokeColor(state.ParentStyle()->TextStrokeColor());
}

void InternalVisitedTextStrokeColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInternalVisitedTextStrokeColor(StyleBuilderConverter::ConvertStyleColor(state, value, true));
}

// interpolate-size

CSSExposure InterpolateSize::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSCalcSizeFunctionEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* InterpolateSize::GetPropertyName() const
{
    return "interpolate-size";
}

const WTF::AtomicString& InterpolateSize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("interpolate-size"));
    return name;
}

const char* InterpolateSize::GetJSPropertyName() const
{
    return "interpolateSize";
}

void InterpolateSize::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetInterpolateSize(ComputedStyleInitialValues::InitialInterpolateSize());
}
void InterpolateSize::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetInterpolateSize(state.ParentStyle()->InterpolateSize());
}
void InterpolateSize::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetInterpolateSize(To<CSSIdentifierValue>(value).ConvertTo<blink::EInterpolateSize>());
}

// isolation

const char* Isolation::GetPropertyName() const
{
    return "isolation";
}

const WTF::AtomicString& Isolation::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("isolation"));
    return name;
}

const char* Isolation::GetJSPropertyName() const
{
    return "isolation";
}

void Isolation::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetIsolation(ComputedStyleInitialValues::InitialIsolation());
}
void Isolation::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetIsolation(state.ParentStyle()->Isolation());
}
void Isolation::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetIsolation(To<CSSIdentifierValue>(value).ConvertTo<blink::EIsolation>());
}

// justify-content

const char* JustifyContent::GetPropertyName() const
{
    return "justify-content";
}

const WTF::AtomicString& JustifyContent::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("justify-content"));
    return name;
}

const char* JustifyContent::GetJSPropertyName() const
{
    return "justifyContent";
}

void JustifyContent::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetJustifyContent(ComputedStyleInitialValues::InitialJustifyContent());
}
void JustifyContent::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetJustifyContent(state.ParentStyle()->JustifyContent());
}
void JustifyContent::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetJustifyContent(StyleBuilderConverter::ConvertContentAlignmentData(state, value));
}

// justify-items

const char* JustifyItems::GetPropertyName() const
{
    return "justify-items";
}

const WTF::AtomicString& JustifyItems::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("justify-items"));
    return name;
}

const char* JustifyItems::GetJSPropertyName() const
{
    return "justifyItems";
}

void JustifyItems::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetJustifyItems(ComputedStyleInitialValues::InitialJustifyItems());
}
void JustifyItems::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetJustifyItems(state.ParentStyle()->JustifyItems());
}
void JustifyItems::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetJustifyItems(StyleBuilderConverter::ConvertSelfOrDefaultAlignmentData(state, value));
}

// justify-self

const char* JustifySelf::GetPropertyName() const
{
    return "justify-self";
}

const WTF::AtomicString& JustifySelf::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("justify-self"));
    return name;
}

const char* JustifySelf::GetJSPropertyName() const
{
    return "justifySelf";
}

void JustifySelf::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetJustifySelf(ComputedStyleInitialValues::InitialJustifySelf());
}
void JustifySelf::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetJustifySelf(state.ParentStyle()->JustifySelf());
}
void JustifySelf::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetJustifySelf(StyleBuilderConverter::ConvertSelfOrDefaultAlignmentData(state, value));
}

// left

const char* Left::GetPropertyName() const
{
    return "left";
}

const WTF::AtomicString& Left::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("left"));
    return name;
}

const char* Left::GetJSPropertyName() const
{
    return "left";
}

bool Left::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalInsetMapping().Contains(id);
}

void Left::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetLeft(ComputedStyleInitialValues::InitialLeft());
}
void Left::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetLeft(state.ParentStyle()->Left());
}
void Left::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    blink::AnchorScope anchor_scope(blink::AnchorScope::Mode::kLeft, state.CssToLengthConversionData().GetAnchorEvaluator());
    state.StyleBuilder().SetLeft(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

// letter-spacing

const char* LetterSpacing::GetPropertyName() const
{
    return "letter-spacing";
}

const WTF::AtomicString& LetterSpacing::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("letter-spacing"));
    return name;
}

const char* LetterSpacing::GetJSPropertyName() const
{
    return "letterSpacing";
}

void LetterSpacing::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetLetterSpacing(ComputedStyleInitialValues::InitialLetterSpacing());
}
void LetterSpacing::ApplyInherit(StyleResolverState& state) const
{
    if (state.GetDocument().StandardizedBrowserZoomEnabled()) {
        if (ApplyParentValueIfZoomChanged(state)) {
            return;
        }
    }
    state.StyleBuilder().SetLetterSpacing(state.ParentStyle()->LetterSpacing());
}
void LetterSpacing::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetLetterSpacing(StyleBuilderConverter::ConvertSpacing(state, value));
}

// lighting-color

const char* LightingColor::GetPropertyName() const
{
    return "lighting-color";
}

const WTF::AtomicString& LightingColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("lighting-color"));
    return name;
}

const char* LightingColor::GetJSPropertyName() const
{
    return "lightingColor";
}

void LightingColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetLightingColor(ComputedStyleInitialValues::InitialLightingColor());
}

void LightingColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetLightingColor(state.ParentStyle()->LightingColor());
}

void LightingColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetLightingColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// line-break

const char* LineBreak::GetPropertyName() const
{
    return "line-break";
}

const WTF::AtomicString& LineBreak::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("line-break"));
    return name;
}

const char* LineBreak::GetJSPropertyName() const
{
    return "lineBreak";
}

const CSSProperty* LineBreak::SurrogateFor(WritingDirectionMode) const
{
    return &GetCSSPropertyWebkitLineBreak();
}

// line-clamp

CSSExposure LineClamp::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSLineClampEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* LineClamp::GetPropertyName() const
{
    return "line-clamp";
}

const WTF::AtomicString& LineClamp::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("line-clamp"));
    return name;
}

const char* LineClamp::GetJSPropertyName() const
{
    return "lineClamp";
}

void LineClamp::ApplyInherit(StyleResolverState& state) const
{
    if (state.ParentStyle()->HasAutoStandardLineClamp())
        state.StyleBuilder().SetHasAutoStandardLineClamp();
    else
        state.StyleBuilder().SetStandardLineClamp(state.ParentStyle()->StandardLineClamp());
}
void LineClamp::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    auto* identifier_value = DynamicTo<CSSIdentifierValue>(value);
    if (identifier_value && identifier_value->GetValueID() == CSSValueID::kAuto)
        state.StyleBuilder().SetHasAutoStandardLineClamp();
    else
        state.StyleBuilder().SetStandardLineClamp(StyleBuilderConverter::ConvertIntegerOrNone<0>(state, value));
}

// line-gap-override

const char* LineGapOverride::GetPropertyName() const
{
    return "line-gap-override";
}

const WTF::AtomicString& LineGapOverride::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("line-gap-override"));
    return name;
}

const char* LineGapOverride::GetJSPropertyName() const
{
    return "lineGapOverride";
}

// line-height

const char* LineHeight::GetPropertyName() const
{
    return "line-height";
}

const WTF::AtomicString& LineHeight::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("line-height"));
    return name;
}

const char* LineHeight::GetJSPropertyName() const
{
    return "lineHeight";
}

void LineHeight::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetLineHeight(ComputedStyleInitialValues::InitialLineHeight());
}
void LineHeight::ApplyInherit(StyleResolverState& state) const
{
    if (state.GetDocument().StandardizedBrowserZoomEnabled()) {
        if (ApplyParentValueIfZoomChanged(state)) {
            return;
        }
    }
    state.StyleBuilder().SetLineHeight(state.ParentStyle()->SpecifiedLineHeight());
}
void LineHeight::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetLineHeight(StyleBuilderConverter::ConvertLineHeight(state, value));
}

// list-style-image

const char* ListStyleImage::GetPropertyName() const
{
    return "list-style-image";
}

const WTF::AtomicString& ListStyleImage::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("list-style-image"));
    return name;
}

const char* ListStyleImage::GetJSPropertyName() const
{
    return "listStyleImage";
}

void ListStyleImage::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetListStyleImage(ComputedStyleInitialValues::InitialListStyleImage());
}
void ListStyleImage::ApplyInherit(StyleResolverState& state) const
{
    if (state.GetDocument().StandardizedBrowserZoomEnabled()) {
        if (ApplyParentValueIfZoomChanged(state)) {
            return;
        }
    }
    state.StyleBuilder().SetListStyleImage(state.ParentStyle()->ListStyleImage());
}

// list-style-position

const char* ListStylePosition::GetPropertyName() const
{
    return "list-style-position";
}

const WTF::AtomicString& ListStylePosition::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("list-style-position"));
    return name;
}

const char* ListStylePosition::GetJSPropertyName() const
{
    return "listStylePosition";
}

void ListStylePosition::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetListStylePosition(ComputedStyleInitialValues::InitialListStylePosition());
    state.StyleBuilder().SetListStylePositionIsInherited(false);
}
void ListStylePosition::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetListStylePosition(state.ParentStyle()->ListStylePosition());
    state.StyleBuilder().SetListStylePositionIsInherited(true);
}
void ListStylePosition::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetListStylePosition(To<CSSIdentifierValue>(value).ConvertTo<blink::EListStylePosition>());
    state.StyleBuilder().SetListStylePositionIsInherited(false);
}

// list-style-type

const char* ListStyleType::GetPropertyName() const
{
    return "list-style-type";
}

const WTF::AtomicString& ListStyleType::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("list-style-type"));
    return name;
}

const char* ListStyleType::GetJSPropertyName() const
{
    return "listStyleType";
}

void ListStyleType::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetListStyleType(ComputedStyleInitialValues::InitialListStyleType());
}
void ListStyleType::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetListStyleType(state.ParentStyle()->ListStyleType());
}

// margin-block-end

const char* MarginBlockEnd::GetPropertyName() const
{
    return "margin-block-end";
}

const WTF::AtomicString& MarginBlockEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-block-end"));
    return name;
}

const char* MarginBlockEnd::GetJSPropertyName() const
{
    return "marginBlockEnd";
}

const CSSProperty* MarginBlockEnd::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& MarginBlockEnd::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockEnd(writing_direction, CSSDirectionAwareResolver::PhysicalMarginMapping());
}

bool MarginBlockEnd::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalMarginMapping().Contains(id);
}

// margin-block-start

const char* MarginBlockStart::GetPropertyName() const
{
    return "margin-block-start";
}

const WTF::AtomicString& MarginBlockStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-block-start"));
    return name;
}

const char* MarginBlockStart::GetJSPropertyName() const
{
    return "marginBlockStart";
}

const CSSProperty* MarginBlockStart::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& MarginBlockStart::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockStart(writing_direction, CSSDirectionAwareResolver::PhysicalMarginMapping());
}

bool MarginBlockStart::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalMarginMapping().Contains(id);
}

// margin-bottom

const char* MarginBottom::GetPropertyName() const
{
    return "margin-bottom";
}

const WTF::AtomicString& MarginBottom::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-bottom"));
    return name;
}

const char* MarginBottom::GetJSPropertyName() const
{
    return "marginBottom";
}

bool MarginBottom::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalMarginMapping().Contains(id);
}

void MarginBottom::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMarginBottom(ComputedStyleInitialValues::InitialMarginBottom());
}
void MarginBottom::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMarginBottom(state.ParentStyle()->MarginBottom());
}
void MarginBottom::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    blink::AnchorScope anchor_scope(blink::AnchorScope::Mode::kHeight, state.CssToLengthConversionData().GetAnchorEvaluator());
    state.StyleBuilder().SetMarginBottom(StyleBuilderConverter::ConvertQuirkyLength(state, value));
}

// margin-inline-end

const char* MarginInlineEnd::GetPropertyName() const
{
    return "margin-inline-end";
}

const WTF::AtomicString& MarginInlineEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-inline-end"));
    return name;
}

const char* MarginInlineEnd::GetJSPropertyName() const
{
    return "marginInlineEnd";
}

const CSSProperty* MarginInlineEnd::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& MarginInlineEnd::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineEnd(writing_direction, CSSDirectionAwareResolver::PhysicalMarginMapping());
}

bool MarginInlineEnd::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalMarginMapping().Contains(id);
}

// margin-inline-start

const char* MarginInlineStart::GetPropertyName() const
{
    return "margin-inline-start";
}

const WTF::AtomicString& MarginInlineStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-inline-start"));
    return name;
}

const char* MarginInlineStart::GetJSPropertyName() const
{
    return "marginInlineStart";
}

const CSSProperty* MarginInlineStart::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& MarginInlineStart::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineStart(writing_direction, CSSDirectionAwareResolver::PhysicalMarginMapping());
}

bool MarginInlineStart::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalMarginMapping().Contains(id);
}

// margin-left

const char* MarginLeft::GetPropertyName() const
{
    return "margin-left";
}

const WTF::AtomicString& MarginLeft::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-left"));
    return name;
}

const char* MarginLeft::GetJSPropertyName() const
{
    return "marginLeft";
}

bool MarginLeft::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalMarginMapping().Contains(id);
}

void MarginLeft::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMarginLeft(ComputedStyleInitialValues::InitialMarginLeft());
}
void MarginLeft::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMarginLeft(state.ParentStyle()->MarginLeft());
}
void MarginLeft::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    blink::AnchorScope anchor_scope(blink::AnchorScope::Mode::kWidth, state.CssToLengthConversionData().GetAnchorEvaluator());
    state.StyleBuilder().SetMarginLeft(StyleBuilderConverter::ConvertQuirkyLength(state, value));
}

// margin-right

const char* MarginRight::GetPropertyName() const
{
    return "margin-right";
}

const WTF::AtomicString& MarginRight::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-right"));
    return name;
}

const char* MarginRight::GetJSPropertyName() const
{
    return "marginRight";
}

bool MarginRight::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalMarginMapping().Contains(id);
}

void MarginRight::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMarginRight(ComputedStyleInitialValues::InitialMarginRight());
}
void MarginRight::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMarginRight(state.ParentStyle()->MarginRight());
}
void MarginRight::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    blink::AnchorScope anchor_scope(blink::AnchorScope::Mode::kWidth, state.CssToLengthConversionData().GetAnchorEvaluator());
    state.StyleBuilder().SetMarginRight(StyleBuilderConverter::ConvertQuirkyLength(state, value));
}

// margin-top

const char* MarginTop::GetPropertyName() const
{
    return "margin-top";
}

const WTF::AtomicString& MarginTop::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("margin-top"));
    return name;
}

const char* MarginTop::GetJSPropertyName() const
{
    return "marginTop";
}

bool MarginTop::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalMarginMapping().Contains(id);
}

void MarginTop::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMarginTop(ComputedStyleInitialValues::InitialMarginTop());
}
void MarginTop::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMarginTop(state.ParentStyle()->MarginTop());
}
void MarginTop::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    blink::AnchorScope anchor_scope(blink::AnchorScope::Mode::kHeight, state.CssToLengthConversionData().GetAnchorEvaluator());
    state.StyleBuilder().SetMarginTop(StyleBuilderConverter::ConvertQuirkyLength(state, value));
}

// marker-end

const char* MarkerEnd::GetPropertyName() const
{
    return "marker-end";
}

const WTF::AtomicString& MarkerEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("marker-end"));
    return name;
}

const char* MarkerEnd::GetJSPropertyName() const
{
    return "markerEnd";
}

void MarkerEnd::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMarkerEndResource(ComputedStyleInitialValues::InitialMarkerEndResource());
}
void MarkerEnd::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMarkerEndResource(state.ParentStyle()->MarkerEndResource());
}

// marker-mid

const char* MarkerMid::GetPropertyName() const
{
    return "marker-mid";
}

const WTF::AtomicString& MarkerMid::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("marker-mid"));
    return name;
}

const char* MarkerMid::GetJSPropertyName() const
{
    return "markerMid";
}

void MarkerMid::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMarkerMidResource(ComputedStyleInitialValues::InitialMarkerMidResource());
}
void MarkerMid::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMarkerMidResource(state.ParentStyle()->MarkerMidResource());
}

// marker-start

const char* MarkerStart::GetPropertyName() const
{
    return "marker-start";
}

const WTF::AtomicString& MarkerStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("marker-start"));
    return name;
}

const char* MarkerStart::GetJSPropertyName() const
{
    return "markerStart";
}

void MarkerStart::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMarkerStartResource(ComputedStyleInitialValues::InitialMarkerStartResource());
}
void MarkerStart::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMarkerStartResource(state.ParentStyle()->MarkerStartResource());
}

// mask-clip

const char* MaskClip::GetPropertyName() const
{
    return "mask-clip";
}

const WTF::AtomicString& MaskClip::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("mask-clip"));
    return name;
}

const char* MaskClip::GetJSPropertyName() const
{
    return "maskClip";
}

void MaskClip::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    curr_child->SetClip(FillLayer::InitialFillClip(EFillLayerType::kMask));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearClip();
}

void MaskClip::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
    while (curr_parent && curr_parent->IsClipSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetClip(curr_parent->Clip());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearClip();
        curr_child = curr_child->Next();
    }
}

void MaskClip::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillClip(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillClip(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearClip();
        curr_child = curr_child->Next();
    }
}

// mask-composite

const char* MaskComposite::GetPropertyName() const
{
    return "mask-composite";
}

const WTF::AtomicString& MaskComposite::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("mask-composite"));
    return name;
}

const char* MaskComposite::GetJSPropertyName() const
{
    return "maskComposite";
}

void MaskComposite::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    curr_child->SetCompositingOperator(FillLayer::InitialFillCompositingOperator(EFillLayerType::kMask));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearCompositingOperator();
}

void MaskComposite::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
    while (curr_parent && curr_parent->IsCompositingOperatorSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetCompositingOperator(curr_parent->CompositingOperator());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearCompositingOperator();
        curr_child = curr_child->Next();
    }
}

void MaskComposite::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillCompositingOperator(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillCompositingOperator(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearCompositingOperator();
        curr_child = curr_child->Next();
    }
}

// mask-mode

const char* MaskMode::GetPropertyName() const
{
    return "mask-mode";
}

const WTF::AtomicString& MaskMode::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("mask-mode"));
    return name;
}

const char* MaskMode::GetJSPropertyName() const
{
    return "maskMode";
}

void MaskMode::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    curr_child->SetMaskMode(FillLayer::InitialFillMaskMode(EFillLayerType::kMask));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearMaskMode();
}

void MaskMode::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
    while (curr_parent && curr_parent->IsMaskModeSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetMaskMode(curr_parent->MaskMode());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearMaskMode();
        curr_child = curr_child->Next();
    }
}

void MaskMode::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillMaskMode(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillMaskMode(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearMaskMode();
        curr_child = curr_child->Next();
    }
}

// mask-origin

const char* MaskOrigin::GetPropertyName() const
{
    return "mask-origin";
}

const WTF::AtomicString& MaskOrigin::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("mask-origin"));
    return name;
}

const char* MaskOrigin::GetJSPropertyName() const
{
    return "maskOrigin";
}

void MaskOrigin::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    curr_child->SetOrigin(FillLayer::InitialFillOrigin(EFillLayerType::kMask));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearOrigin();
}

void MaskOrigin::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
    while (curr_parent && curr_parent->IsOriginSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetOrigin(curr_parent->Origin());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearOrigin();
        curr_child = curr_child->Next();
    }
}

void MaskOrigin::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillOrigin(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillOrigin(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearOrigin();
        curr_child = curr_child->Next();
    }
}

// mask-repeat

const char* MaskRepeat::GetPropertyName() const
{
    return "mask-repeat";
}

const WTF::AtomicString& MaskRepeat::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("mask-repeat"));
    return name;
}

const char* MaskRepeat::GetJSPropertyName() const
{
    return "maskRepeat";
}

void MaskRepeat::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    curr_child->SetRepeat(FillLayer::InitialFillRepeat(EFillLayerType::kMask));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearRepeat();
}

void MaskRepeat::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
    while (curr_parent && curr_parent->IsRepeatSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetRepeat(curr_parent->Repeat());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearRepeat();
        curr_child = curr_child->Next();
    }
}

void MaskRepeat::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillRepeat(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillRepeat(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearRepeat();
        curr_child = curr_child->Next();
    }
}

// mask-size

const char* MaskSize::GetPropertyName() const
{
    return "mask-size";
}

const WTF::AtomicString& MaskSize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("mask-size"));
    return name;
}

const char* MaskSize::GetJSPropertyName() const
{
    return "maskSize";
}

void MaskSize::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    curr_child->SetSize(FillLayer::InitialFillSize(EFillLayerType::kMask));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearSize();
}

void MaskSize::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
    while (curr_parent && curr_parent->IsSizeSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetSize(curr_parent->Size());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearSize();
        curr_child = curr_child->Next();
    }
}

void MaskSize::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillSize(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillSize(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearSize();
        curr_child = curr_child->Next();
    }
}

// mask-type

const char* MaskType::GetPropertyName() const
{
    return "mask-type";
}

const WTF::AtomicString& MaskType::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("mask-type"));
    return name;
}

const char* MaskType::GetJSPropertyName() const
{
    return "maskType";
}

void MaskType::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMaskType(ComputedStyleInitialValues::InitialMaskType());
}
void MaskType::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMaskType(state.ParentStyle()->MaskType());
}
void MaskType::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetMaskType(To<CSSIdentifierValue>(value).ConvertTo<blink::EMaskType>());
}

// masonry-slack

CSSExposure MasonrySlack::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSMasonryLayoutEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* MasonrySlack::GetPropertyName() const
{
    return "masonry-slack";
}

const WTF::AtomicString& MasonrySlack::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("masonry-slack"));
    return name;
}

const char* MasonrySlack::GetJSPropertyName() const
{
    return "masonrySlack";
}

void MasonrySlack::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMasonrySlack(ComputedStyleInitialValues::InitialMasonrySlack());
}
void MasonrySlack::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMasonrySlack(state.ParentStyle()->MasonrySlack());
}
void MasonrySlack::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetMasonrySlack(StyleBuilderConverter::ConvertMasonrySlack(state, value));
}

// masonry-template-tracks

CSSExposure MasonryTemplateTracks::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSMasonryLayoutEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* MasonryTemplateTracks::GetPropertyName() const
{
    return "masonry-template-tracks";
}

const WTF::AtomicString& MasonryTemplateTracks::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("masonry-template-tracks"));
    return name;
}

const char* MasonryTemplateTracks::GetJSPropertyName() const
{
    return "masonryTemplateTracks";
}

void MasonryTemplateTracks::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMasonryTemplateTracks(ComputedStyleInitialValues::InitialMasonryTemplateTracks());
}

void MasonryTemplateTracks::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMasonryTemplateTracks(state.ParentStyle()->MasonryTemplateTracks());
}

void MasonryTemplateTracks::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    ComputedGridTrackList computed_grid_track_list;
    StyleBuilderConverter::ConvertGridTrackList(value, computed_grid_track_list, state);
    state.StyleBuilder().SetMasonryTemplateTracks(computed_grid_track_list);
}

// masonry-track-end

CSSExposure MasonryTrackEnd::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSMasonryLayoutEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* MasonryTrackEnd::GetPropertyName() const
{
    return "masonry-track-end";
}

const WTF::AtomicString& MasonryTrackEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("masonry-track-end"));
    return name;
}

const char* MasonryTrackEnd::GetJSPropertyName() const
{
    return "masonryTrackEnd";
}

void MasonryTrackEnd::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMasonryTrackEnd(ComputedStyleInitialValues::InitialMasonryTrackEnd());
}
void MasonryTrackEnd::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMasonryTrackEnd(state.ParentStyle()->MasonryTrackEnd());
}
void MasonryTrackEnd::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetMasonryTrackEnd(StyleBuilderConverter::ConvertGridPosition(state, value));
}

// masonry-track-start

CSSExposure MasonryTrackStart::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSMasonryLayoutEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* MasonryTrackStart::GetPropertyName() const
{
    return "masonry-track-start";
}

const WTF::AtomicString& MasonryTrackStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("masonry-track-start"));
    return name;
}

const char* MasonryTrackStart::GetJSPropertyName() const
{
    return "masonryTrackStart";
}

void MasonryTrackStart::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMasonryTrackStart(ComputedStyleInitialValues::InitialMasonryTrackStart());
}
void MasonryTrackStart::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMasonryTrackStart(state.ParentStyle()->MasonryTrackStart());
}
void MasonryTrackStart::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetMasonryTrackStart(StyleBuilderConverter::ConvertGridPosition(state, value));
}

// math-shift

const char* MathShift::GetPropertyName() const
{
    return "math-shift";
}

const WTF::AtomicString& MathShift::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("math-shift"));
    return name;
}

const char* MathShift::GetJSPropertyName() const
{
    return "mathShift";
}

void MathShift::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMathShift(ComputedStyleInitialValues::InitialMathShift());
}
void MathShift::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMathShift(state.ParentStyle()->MathShift());
}
void MathShift::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetMathShift(To<CSSIdentifierValue>(value).ConvertTo<blink::EMathShift>());
}

// math-style

const char* MathStyle::GetPropertyName() const
{
    return "math-style";
}

const WTF::AtomicString& MathStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("math-style"));
    return name;
}

const char* MathStyle::GetJSPropertyName() const
{
    return "mathStyle";
}

void MathStyle::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMathStyle(ComputedStyleInitialValues::InitialMathStyle());
}
void MathStyle::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMathStyle(state.ParentStyle()->MathStyle());
}
void MathStyle::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetMathStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::EMathStyle>());
}

// max-block-size

const char* MaxBlockSize::GetPropertyName() const
{
    return "max-block-size";
}

const WTF::AtomicString& MaxBlockSize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("max-block-size"));
    return name;
}

const char* MaxBlockSize::GetJSPropertyName() const
{
    return "maxBlockSize";
}

const CSSProperty* MaxBlockSize::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& MaxBlockSize::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlock(writing_direction, CSSDirectionAwareResolver::PhysicalMaxSizeMapping());
}

bool MaxBlockSize::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalMaxSizeMapping().Contains(id);
}

// max-height

const char* MaxHeight::GetPropertyName() const
{
    return "max-height";
}

const WTF::AtomicString& MaxHeight::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("max-height"));
    return name;
}

const char* MaxHeight::GetJSPropertyName() const
{
    return "maxHeight";
}

bool MaxHeight::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalMaxSizeMapping().Contains(id);
}

void MaxHeight::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMaxHeight(ComputedStyleInitialValues::InitialMaxHeight());
}
void MaxHeight::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMaxHeight(state.ParentStyle()->MaxHeight());
}
void MaxHeight::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    blink::AnchorScope anchor_scope(blink::AnchorScope::Mode::kHeight, state.CssToLengthConversionData().GetAnchorEvaluator());
    state.StyleBuilder().SetMaxHeight(StyleBuilderConverter::ConvertLengthMaxSizing(state, value));
}

// max-inline-size

const char* MaxInlineSize::GetPropertyName() const
{
    return "max-inline-size";
}

const WTF::AtomicString& MaxInlineSize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("max-inline-size"));
    return name;
}

const char* MaxInlineSize::GetJSPropertyName() const
{
    return "maxInlineSize";
}

const CSSProperty* MaxInlineSize::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& MaxInlineSize::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInline(writing_direction, CSSDirectionAwareResolver::PhysicalMaxSizeMapping());
}

bool MaxInlineSize::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalMaxSizeMapping().Contains(id);
}

// max-width

const char* MaxWidth::GetPropertyName() const
{
    return "max-width";
}

const WTF::AtomicString& MaxWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("max-width"));
    return name;
}

const char* MaxWidth::GetJSPropertyName() const
{
    return "maxWidth";
}

bool MaxWidth::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalMaxSizeMapping().Contains(id);
}

void MaxWidth::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMaxWidth(ComputedStyleInitialValues::InitialMaxWidth());
}
void MaxWidth::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMaxWidth(state.ParentStyle()->MaxWidth());
}
void MaxWidth::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    blink::AnchorScope anchor_scope(blink::AnchorScope::Mode::kWidth, state.CssToLengthConversionData().GetAnchorEvaluator());
    state.StyleBuilder().SetMaxWidth(StyleBuilderConverter::ConvertLengthMaxSizing(state, value));
}

// min-block-size

const char* MinBlockSize::GetPropertyName() const
{
    return "min-block-size";
}

const WTF::AtomicString& MinBlockSize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("min-block-size"));
    return name;
}

const char* MinBlockSize::GetJSPropertyName() const
{
    return "minBlockSize";
}

const CSSProperty* MinBlockSize::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& MinBlockSize::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlock(writing_direction, CSSDirectionAwareResolver::PhysicalMinSizeMapping());
}

bool MinBlockSize::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalMinSizeMapping().Contains(id);
}

// min-height

const char* MinHeight::GetPropertyName() const
{
    return "min-height";
}

const WTF::AtomicString& MinHeight::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("min-height"));
    return name;
}

const char* MinHeight::GetJSPropertyName() const
{
    return "minHeight";
}

bool MinHeight::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalMinSizeMapping().Contains(id);
}

void MinHeight::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMinHeight(ComputedStyleInitialValues::InitialMinHeight());
}
void MinHeight::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMinHeight(state.ParentStyle()->MinHeight());
}
void MinHeight::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    blink::AnchorScope anchor_scope(blink::AnchorScope::Mode::kHeight, state.CssToLengthConversionData().GetAnchorEvaluator());
    state.StyleBuilder().SetMinHeight(StyleBuilderConverter::ConvertLengthSizing(state, value));
}

// min-inline-size

const char* MinInlineSize::GetPropertyName() const
{
    return "min-inline-size";
}

const WTF::AtomicString& MinInlineSize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("min-inline-size"));
    return name;
}

const char* MinInlineSize::GetJSPropertyName() const
{
    return "minInlineSize";
}

const CSSProperty* MinInlineSize::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& MinInlineSize::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInline(writing_direction, CSSDirectionAwareResolver::PhysicalMinSizeMapping());
}

bool MinInlineSize::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalMinSizeMapping().Contains(id);
}

// min-width

const char* MinWidth::GetPropertyName() const
{
    return "min-width";
}

const WTF::AtomicString& MinWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("min-width"));
    return name;
}

const char* MinWidth::GetJSPropertyName() const
{
    return "minWidth";
}

bool MinWidth::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalMinSizeMapping().Contains(id);
}

void MinWidth::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMinWidth(ComputedStyleInitialValues::InitialMinWidth());
}
void MinWidth::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMinWidth(state.ParentStyle()->MinWidth());
}
void MinWidth::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    blink::AnchorScope anchor_scope(blink::AnchorScope::Mode::kWidth, state.CssToLengthConversionData().GetAnchorEvaluator());
    state.StyleBuilder().SetMinWidth(StyleBuilderConverter::ConvertLengthSizing(state, value));
}

// mix-blend-mode

const char* MixBlendMode::GetPropertyName() const
{
    return "mix-blend-mode";
}

const WTF::AtomicString& MixBlendMode::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("mix-blend-mode"));
    return name;
}

const char* MixBlendMode::GetJSPropertyName() const
{
    return "mixBlendMode";
}

void MixBlendMode::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBlendMode(ComputedStyleInitialValues::InitialBlendMode());
}
void MixBlendMode::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBlendMode(state.ParentStyle()->GetBlendMode());
}
void MixBlendMode::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBlendMode(To<CSSIdentifierValue>(value).ConvertTo<blink::BlendMode>());
}

// navigation

CSSExposure Navigation::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::ViewTransitionOnNavigationEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* Navigation::GetPropertyName() const
{
    return "navigation";
}

const WTF::AtomicString& Navigation::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("navigation"));
    return name;
}

const char* Navigation::GetJSPropertyName() const
{
    return "navigation";
}

// negative

const char* Negative::GetPropertyName() const
{
    return "negative";
}

const WTF::AtomicString& Negative::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("negative"));
    return name;
}

const char* Negative::GetJSPropertyName() const
{
    return "negative";
}

// object-fit

const char* ObjectFit::GetPropertyName() const
{
    return "object-fit";
}

const WTF::AtomicString& ObjectFit::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("object-fit"));
    return name;
}

const char* ObjectFit::GetJSPropertyName() const
{
    return "objectFit";
}

void ObjectFit::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetObjectFit(ComputedStyleInitialValues::InitialObjectFit());
}
void ObjectFit::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetObjectFit(state.ParentStyle()->GetObjectFit());
}
void ObjectFit::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetObjectFit(To<CSSIdentifierValue>(value).ConvertTo<blink::EObjectFit>());
}

// object-position

const char* ObjectPosition::GetPropertyName() const
{
    return "object-position";
}

const WTF::AtomicString& ObjectPosition::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("object-position"));
    return name;
}

const char* ObjectPosition::GetJSPropertyName() const
{
    return "objectPosition";
}

void ObjectPosition::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetObjectPosition(ComputedStyleInitialValues::InitialObjectPosition());
}
void ObjectPosition::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetObjectPosition(state.ParentStyle()->ObjectPosition());
}
void ObjectPosition::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetObjectPosition(StyleBuilderConverter::ConvertPosition(state, value));
}

// object-view-box

const char* ObjectViewBox::GetPropertyName() const
{
    return "object-view-box";
}

const WTF::AtomicString& ObjectViewBox::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("object-view-box"));
    return name;
}

const char* ObjectViewBox::GetJSPropertyName() const
{
    return "objectViewBox";
}

void ObjectViewBox::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetObjectViewBox(ComputedStyleInitialValues::InitialObjectViewBox());
}
void ObjectViewBox::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetObjectViewBox(state.ParentStyle()->ObjectViewBox());
}
void ObjectViewBox::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetObjectViewBox(StyleBuilderConverter::ConvertObjectViewBox(state, value));
}

// offset-anchor

const char* OffsetAnchor::GetPropertyName() const
{
    return "offset-anchor";
}

const WTF::AtomicString& OffsetAnchor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("offset-anchor"));
    return name;
}

const char* OffsetAnchor::GetJSPropertyName() const
{
    return "offsetAnchor";
}

void OffsetAnchor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOffsetAnchor(ComputedStyleInitialValues::InitialOffsetAnchor());
}
void OffsetAnchor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOffsetAnchor(state.ParentStyle()->OffsetAnchor());
}
void OffsetAnchor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOffsetAnchor(StyleBuilderConverter::ConvertPositionOrAuto(state, value));
}

// offset-distance

const char* OffsetDistance::GetPropertyName() const
{
    return "offset-distance";
}

const WTF::AtomicString& OffsetDistance::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("offset-distance"));
    return name;
}

const char* OffsetDistance::GetJSPropertyName() const
{
    return "offsetDistance";
}

void OffsetDistance::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOffsetDistance(ComputedStyleInitialValues::InitialOffsetDistance());
}
void OffsetDistance::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOffsetDistance(state.ParentStyle()->OffsetDistance());
}
void OffsetDistance::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOffsetDistance(StyleBuilderConverter::ConvertLength(state, value));
}

// offset-path

const char* OffsetPath::GetPropertyName() const
{
    return "offset-path";
}

const WTF::AtomicString& OffsetPath::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("offset-path"));
    return name;
}

const char* OffsetPath::GetJSPropertyName() const
{
    return "offsetPath";
}

void OffsetPath::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOffsetPath(ComputedStyleInitialValues::InitialOffsetPath());
}
void OffsetPath::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOffsetPath(state.ParentStyle()->OffsetPath());
}
void OffsetPath::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOffsetPath(StyleBuilderConverter::ConvertOffsetPath(state, value));
}

// offset-position

const char* OffsetPosition::GetPropertyName() const
{
    return "offset-position";
}

const WTF::AtomicString& OffsetPosition::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("offset-position"));
    return name;
}

const char* OffsetPosition::GetJSPropertyName() const
{
    return "offsetPosition";
}

void OffsetPosition::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOffsetPosition(ComputedStyleInitialValues::InitialOffsetPosition());
}
void OffsetPosition::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOffsetPosition(state.ParentStyle()->OffsetPosition());
}
void OffsetPosition::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOffsetPosition(StyleBuilderConverter::ConvertOffsetPosition(state, value));
}

// offset-rotate

const char* OffsetRotate::GetPropertyName() const
{
    return "offset-rotate";
}

const WTF::AtomicString& OffsetRotate::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("offset-rotate"));
    return name;
}

const char* OffsetRotate::GetJSPropertyName() const
{
    return "offsetRotate";
}

void OffsetRotate::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOffsetRotate(ComputedStyleInitialValues::InitialOffsetRotate());
}
void OffsetRotate::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOffsetRotate(state.ParentStyle()->OffsetRotate());
}
void OffsetRotate::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOffsetRotate(StyleBuilderConverter::ConvertOffsetRotate(state, value));
}

// opacity

const char* Opacity::GetPropertyName() const
{
    return "opacity";
}

const WTF::AtomicString& Opacity::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("opacity"));
    return name;
}

const char* Opacity::GetJSPropertyName() const
{
    return "opacity";
}

void Opacity::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOpacity(ComputedStyleInitialValues::InitialOpacity());
}
void Opacity::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOpacity(state.ParentStyle()->Opacity());
}
void Opacity::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOpacity(To<CSSPrimitiveValue>(value).ConvertTo<float>(state.CssToLengthConversionData()));
}

// order

const char* Order::GetPropertyName() const
{
    return "order";
}

const WTF::AtomicString& Order::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("order"));
    return name;
}

const char* Order::GetJSPropertyName() const
{
    return "order";
}

void Order::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOrder(ComputedStyleInitialValues::InitialOrder());
}
void Order::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOrder(state.ParentStyle()->Order());
}
void Order::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOrder(To<CSSPrimitiveValue>(value).ConvertTo<int>(state.CssToLengthConversionData()));
}

// origin-trial-test-property

CSSExposure OriginTrialTestProperty::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* OriginTrialTestProperty::GetPropertyName() const
{
    return "origin-trial-test-property";
}

const WTF::AtomicString& OriginTrialTestProperty::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("origin-trial-test-property"));
    return name;
}

const char* OriginTrialTestProperty::GetJSPropertyName() const
{
    return "originTrialTestProperty";
}

void OriginTrialTestProperty::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOriginTrialTestProperty(ComputedStyleInitialValues::InitialOriginTrialTestProperty());
}
void OriginTrialTestProperty::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOriginTrialTestProperty(state.ParentStyle()->OriginTrialTestProperty());
}
void OriginTrialTestProperty::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOriginTrialTestProperty(To<CSSIdentifierValue>(value).ConvertTo<blink::EOriginTrialTestProperty>());
}

// orphans

const char* Orphans::GetPropertyName() const
{
    return "orphans";
}

const WTF::AtomicString& Orphans::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("orphans"));
    return name;
}

const char* Orphans::GetJSPropertyName() const
{
    return "orphans";
}

void Orphans::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOrphans(ComputedStyleInitialValues::InitialOrphans());
}
void Orphans::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOrphans(state.ParentStyle()->Orphans());
}
void Orphans::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOrphans(To<CSSPrimitiveValue>(value).ConvertTo<short>(state.CssToLengthConversionData()));
}

// outline-color

const char* OutlineColor::GetPropertyName() const
{
    return "outline-color";
}

const WTF::AtomicString& OutlineColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("outline-color"));
    return name;
}

const char* OutlineColor::GetJSPropertyName() const
{
    return "outlineColor";
}

void OutlineColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOutlineColor(StyleColor::CurrentColor());
}

void OutlineColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOutlineColor(state.ParentStyle()->OutlineColor());
}

void OutlineColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOutlineColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// outline-offset

const char* OutlineOffset::GetPropertyName() const
{
    return "outline-offset";
}

const WTF::AtomicString& OutlineOffset::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("outline-offset"));
    return name;
}

const char* OutlineOffset::GetJSPropertyName() const
{
    return "outlineOffset";
}

void OutlineOffset::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOutlineOffset(ComputedStyleInitialValues::InitialOutlineOffset());
}
void OutlineOffset::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOutlineOffset(state.ParentStyle()->OutlineOffset());
}
void OutlineOffset::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOutlineOffset(StyleBuilderConverter::ConvertLayoutUnit(state, value));
}

// outline-style

const char* OutlineStyle::GetPropertyName() const
{
    return "outline-style";
}

const WTF::AtomicString& OutlineStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("outline-style"));
    return name;
}

const char* OutlineStyle::GetJSPropertyName() const
{
    return "outlineStyle";
}

// outline-width

const char* OutlineWidth::GetPropertyName() const
{
    return "outline-width";
}

const WTF::AtomicString& OutlineWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("outline-width"));
    return name;
}

const char* OutlineWidth::GetJSPropertyName() const
{
    return "outlineWidth";
}

void OutlineWidth::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOutlineWidth(ComputedStyleInitialValues::InitialOutlineWidth());
}
void OutlineWidth::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOutlineWidth(state.ParentStyle()->OutlineWidth());
}
void OutlineWidth::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOutlineWidth(StyleBuilderConverter::ConvertBorderWidth(state, value));
}

// overflow-anchor

const char* OverflowAnchor::GetPropertyName() const
{
    return "overflow-anchor";
}

const WTF::AtomicString& OverflowAnchor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("overflow-anchor"));
    return name;
}

const char* OverflowAnchor::GetJSPropertyName() const
{
    return "overflowAnchor";
}

void OverflowAnchor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOverflowAnchor(ComputedStyleInitialValues::InitialOverflowAnchor());
}
void OverflowAnchor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOverflowAnchor(state.ParentStyle()->OverflowAnchor());
}
void OverflowAnchor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOverflowAnchor(To<CSSIdentifierValue>(value).ConvertTo<blink::EOverflowAnchor>());
}

// overflow-block

CSSExposure OverflowBlock::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSLogicalOverflowEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* OverflowBlock::GetPropertyName() const
{
    return "overflow-block";
}

const WTF::AtomicString& OverflowBlock::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("overflow-block"));
    return name;
}

const char* OverflowBlock::GetJSPropertyName() const
{
    return "overflowBlock";
}

const CSSProperty* OverflowBlock::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& OverflowBlock::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlock(writing_direction, CSSDirectionAwareResolver::PhysicalOverflowMapping());
}

bool OverflowBlock::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalOverflowMapping().Contains(id);
}

// overflow-clip-margin

const char* OverflowClipMargin::GetPropertyName() const
{
    return "overflow-clip-margin";
}

const WTF::AtomicString& OverflowClipMargin::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("overflow-clip-margin"));
    return name;
}

const char* OverflowClipMargin::GetJSPropertyName() const
{
    return "overflowClipMargin";
}

void OverflowClipMargin::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOverflowClipMargin(ComputedStyleInitialValues::InitialOverflowClipMargin());
}
void OverflowClipMargin::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOverflowClipMargin(state.ParentStyle()->OverflowClipMargin());
}
void OverflowClipMargin::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOverflowClipMargin(StyleBuilderConverter::ConvertOverflowClipMargin(state, value));
}

// overflow-inline

CSSExposure OverflowInline::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSLogicalOverflowEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* OverflowInline::GetPropertyName() const
{
    return "overflow-inline";
}

const WTF::AtomicString& OverflowInline::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("overflow-inline"));
    return name;
}

const char* OverflowInline::GetJSPropertyName() const
{
    return "overflowInline";
}

const CSSProperty* OverflowInline::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& OverflowInline::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInline(writing_direction, CSSDirectionAwareResolver::PhysicalOverflowMapping());
}

bool OverflowInline::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalOverflowMapping().Contains(id);
}

// overflow-wrap

const char* OverflowWrap::GetPropertyName() const
{
    return "overflow-wrap";
}

const WTF::AtomicString& OverflowWrap::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("overflow-wrap"));
    return name;
}

const char* OverflowWrap::GetJSPropertyName() const
{
    return "overflowWrap";
}

void OverflowWrap::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOverflowWrap(ComputedStyleInitialValues::InitialOverflowWrap());
}
void OverflowWrap::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOverflowWrap(state.ParentStyle()->OverflowWrap());
}
void OverflowWrap::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOverflowWrap(To<CSSIdentifierValue>(value).ConvertTo<blink::EOverflowWrap>());
}

// overflow-x

const char* OverflowX::GetPropertyName() const
{
    return "overflow-x";
}

const WTF::AtomicString& OverflowX::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("overflow-x"));
    return name;
}

const char* OverflowX::GetJSPropertyName() const
{
    return "overflowX";
}

bool OverflowX::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalOverflowMapping().Contains(id);
}

// overflow-y

const char* OverflowY::GetPropertyName() const
{
    return "overflow-y";
}

const WTF::AtomicString& OverflowY::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("overflow-y"));
    return name;
}

const char* OverflowY::GetJSPropertyName() const
{
    return "overflowY";
}

bool OverflowY::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalOverflowMapping().Contains(id);
}

// overlay

const char* Overlay::GetPropertyName() const
{
    return "overlay";
}

const WTF::AtomicString& Overlay::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("overlay"));
    return name;
}

const char* Overlay::GetJSPropertyName() const
{
    return "overlay";
}

void Overlay::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOverlay(ComputedStyleInitialValues::InitialOverlay());
}
void Overlay::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOverlay(state.ParentStyle()->Overlay());
}
void Overlay::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOverlay(To<CSSIdentifierValue>(value).ConvertTo<blink::EOverlay>());
}

// override-colors

const char* OverrideColors::GetPropertyName() const
{
    return "override-colors";
}

const WTF::AtomicString& OverrideColors::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("override-colors"));
    return name;
}

const char* OverrideColors::GetJSPropertyName() const
{
    return "overrideColors";
}

// overscroll-behavior-block

const char* OverscrollBehaviorBlock::GetPropertyName() const
{
    return "overscroll-behavior-block";
}

const WTF::AtomicString& OverscrollBehaviorBlock::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("overscroll-behavior-block"));
    return name;
}

const char* OverscrollBehaviorBlock::GetJSPropertyName() const
{
    return "overscrollBehaviorBlock";
}

const CSSProperty* OverscrollBehaviorBlock::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& OverscrollBehaviorBlock::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlock(writing_direction, CSSDirectionAwareResolver::PhysicalOverscrollBehaviorMapping());
}

bool OverscrollBehaviorBlock::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalOverscrollBehaviorMapping().Contains(id);
}

// overscroll-behavior-inline

const char* OverscrollBehaviorInline::GetPropertyName() const
{
    return "overscroll-behavior-inline";
}

const WTF::AtomicString& OverscrollBehaviorInline::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("overscroll-behavior-inline"));
    return name;
}

const char* OverscrollBehaviorInline::GetJSPropertyName() const
{
    return "overscrollBehaviorInline";
}

const CSSProperty* OverscrollBehaviorInline::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& OverscrollBehaviorInline::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInline(writing_direction, CSSDirectionAwareResolver::PhysicalOverscrollBehaviorMapping());
}

bool OverscrollBehaviorInline::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalOverscrollBehaviorMapping().Contains(id);
}

// overscroll-behavior-x

const char* OverscrollBehaviorX::GetPropertyName() const
{
    return "overscroll-behavior-x";
}

const WTF::AtomicString& OverscrollBehaviorX::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("overscroll-behavior-x"));
    return name;
}

const char* OverscrollBehaviorX::GetJSPropertyName() const
{
    return "overscrollBehaviorX";
}

bool OverscrollBehaviorX::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalOverscrollBehaviorMapping().Contains(id);
}

void OverscrollBehaviorX::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOverscrollBehaviorX(ComputedStyleInitialValues::InitialOverscrollBehaviorX());
}
void OverscrollBehaviorX::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOverscrollBehaviorX(state.ParentStyle()->OverscrollBehaviorX());
}
void OverscrollBehaviorX::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOverscrollBehaviorX(To<CSSIdentifierValue>(value).ConvertTo<blink::EOverscrollBehavior>());
}

// overscroll-behavior-y

const char* OverscrollBehaviorY::GetPropertyName() const
{
    return "overscroll-behavior-y";
}

const WTF::AtomicString& OverscrollBehaviorY::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("overscroll-behavior-y"));
    return name;
}

const char* OverscrollBehaviorY::GetJSPropertyName() const
{
    return "overscrollBehaviorY";
}

bool OverscrollBehaviorY::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalOverscrollBehaviorMapping().Contains(id);
}

void OverscrollBehaviorY::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetOverscrollBehaviorY(ComputedStyleInitialValues::InitialOverscrollBehaviorY());
}
void OverscrollBehaviorY::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetOverscrollBehaviorY(state.ParentStyle()->OverscrollBehaviorY());
}
void OverscrollBehaviorY::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetOverscrollBehaviorY(To<CSSIdentifierValue>(value).ConvertTo<blink::EOverscrollBehavior>());
}

// pad

const char* Pad::GetPropertyName() const
{
    return "pad";
}

const WTF::AtomicString& Pad::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("pad"));
    return name;
}

const char* Pad::GetJSPropertyName() const
{
    return "pad";
}

// padding-block-end

const char* PaddingBlockEnd::GetPropertyName() const
{
    return "padding-block-end";
}

const WTF::AtomicString& PaddingBlockEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-block-end"));
    return name;
}

const char* PaddingBlockEnd::GetJSPropertyName() const
{
    return "paddingBlockEnd";
}

const CSSProperty* PaddingBlockEnd::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& PaddingBlockEnd::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockEnd(writing_direction, CSSDirectionAwareResolver::PhysicalPaddingMapping());
}

bool PaddingBlockEnd::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalPaddingMapping().Contains(id);
}

// padding-block-start

const char* PaddingBlockStart::GetPropertyName() const
{
    return "padding-block-start";
}

const WTF::AtomicString& PaddingBlockStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-block-start"));
    return name;
}

const char* PaddingBlockStart::GetJSPropertyName() const
{
    return "paddingBlockStart";
}

const CSSProperty* PaddingBlockStart::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& PaddingBlockStart::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockStart(writing_direction, CSSDirectionAwareResolver::PhysicalPaddingMapping());
}

bool PaddingBlockStart::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalPaddingMapping().Contains(id);
}

// padding-bottom

const char* PaddingBottom::GetPropertyName() const
{
    return "padding-bottom";
}

const WTF::AtomicString& PaddingBottom::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-bottom"));
    return name;
}

const char* PaddingBottom::GetJSPropertyName() const
{
    return "paddingBottom";
}

bool PaddingBottom::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalPaddingMapping().Contains(id);
}

void PaddingBottom::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPaddingBottom(ComputedStyleInitialValues::InitialPaddingBottom());
}
void PaddingBottom::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPaddingBottom(state.ParentStyle()->PaddingBottom());
}
void PaddingBottom::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPaddingBottom(StyleBuilderConverter::ConvertLength(state, value));
}

// padding-inline-end

const char* PaddingInlineEnd::GetPropertyName() const
{
    return "padding-inline-end";
}

const WTF::AtomicString& PaddingInlineEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-inline-end"));
    return name;
}

const char* PaddingInlineEnd::GetJSPropertyName() const
{
    return "paddingInlineEnd";
}

const CSSProperty* PaddingInlineEnd::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& PaddingInlineEnd::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineEnd(writing_direction, CSSDirectionAwareResolver::PhysicalPaddingMapping());
}

bool PaddingInlineEnd::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalPaddingMapping().Contains(id);
}

// padding-inline-start

const char* PaddingInlineStart::GetPropertyName() const
{
    return "padding-inline-start";
}

const WTF::AtomicString& PaddingInlineStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-inline-start"));
    return name;
}

const char* PaddingInlineStart::GetJSPropertyName() const
{
    return "paddingInlineStart";
}

const CSSProperty* PaddingInlineStart::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& PaddingInlineStart::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineStart(writing_direction, CSSDirectionAwareResolver::PhysicalPaddingMapping());
}

bool PaddingInlineStart::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalPaddingMapping().Contains(id);
}

// padding-left

const char* PaddingLeft::GetPropertyName() const
{
    return "padding-left";
}

const WTF::AtomicString& PaddingLeft::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-left"));
    return name;
}

const char* PaddingLeft::GetJSPropertyName() const
{
    return "paddingLeft";
}

bool PaddingLeft::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalPaddingMapping().Contains(id);
}

void PaddingLeft::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPaddingLeft(ComputedStyleInitialValues::InitialPaddingLeft());
}
void PaddingLeft::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPaddingLeft(state.ParentStyle()->PaddingLeft());
}
void PaddingLeft::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPaddingLeft(StyleBuilderConverter::ConvertLength(state, value));
}

// padding-right

const char* PaddingRight::GetPropertyName() const
{
    return "padding-right";
}

const WTF::AtomicString& PaddingRight::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-right"));
    return name;
}

const char* PaddingRight::GetJSPropertyName() const
{
    return "paddingRight";
}

bool PaddingRight::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalPaddingMapping().Contains(id);
}

void PaddingRight::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPaddingRight(ComputedStyleInitialValues::InitialPaddingRight());
}
void PaddingRight::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPaddingRight(state.ParentStyle()->PaddingRight());
}
void PaddingRight::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPaddingRight(StyleBuilderConverter::ConvertLength(state, value));
}

// padding-top

const char* PaddingTop::GetPropertyName() const
{
    return "padding-top";
}

const WTF::AtomicString& PaddingTop::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("padding-top"));
    return name;
}

const char* PaddingTop::GetJSPropertyName() const
{
    return "paddingTop";
}

bool PaddingTop::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalPaddingMapping().Contains(id);
}

void PaddingTop::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPaddingTop(ComputedStyleInitialValues::InitialPaddingTop());
}
void PaddingTop::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPaddingTop(state.ParentStyle()->PaddingTop());
}
void PaddingTop::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPaddingTop(StyleBuilderConverter::ConvertLength(state, value));
}

// page

const char* Page::GetPropertyName() const
{
    return "page";
}

const WTF::AtomicString& Page::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("page"));
    return name;
}

const char* Page::GetJSPropertyName() const
{
    return "page";
}

void Page::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPage(ComputedStyleInitialValues::InitialPage());
}
void Page::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPage(state.ParentStyle()->Page());
}
void Page::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPage(StyleBuilderConverter::ConvertPage(state, value));
}

// page-orientation

const char* PageOrientation::GetPropertyName() const
{
    return "page-orientation";
}

const WTF::AtomicString& PageOrientation::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("page-orientation"));
    return name;
}

const char* PageOrientation::GetJSPropertyName() const
{
    return "pageOrientation";
}

void PageOrientation::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPageOrientation(ComputedStyleInitialValues::InitialPageOrientation());
}
void PageOrientation::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPageOrientation(state.ParentStyle()->GetPageOrientation());
}
void PageOrientation::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPageOrientation(To<CSSIdentifierValue>(value).ConvertTo<blink::PageOrientation>());
}

// paint-order

const char* PaintOrder::GetPropertyName() const
{
    return "paint-order";
}

const WTF::AtomicString& PaintOrder::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("paint-order"));
    return name;
}

const char* PaintOrder::GetJSPropertyName() const
{
    return "paintOrder";
}

void PaintOrder::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPaintOrder(ComputedStyleInitialValues::InitialPaintOrder());
}
void PaintOrder::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPaintOrder(state.ParentStyle()->PaintOrder());
}
void PaintOrder::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPaintOrder(StyleBuilderConverter::ConvertPaintOrder(state, value));
}

// perspective

const char* Perspective::GetPropertyName() const
{
    return "perspective";
}

const WTF::AtomicString& Perspective::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("perspective"));
    return name;
}

const char* Perspective::GetJSPropertyName() const
{
    return "perspective";
}

void Perspective::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPerspective(ComputedStyleInitialValues::InitialPerspective());
}
void Perspective::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPerspective(state.ParentStyle()->Perspective());
}
void Perspective::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPerspective(StyleBuilderConverter::ConvertPerspective(state, value));
}

// perspective-origin

const char* PerspectiveOrigin::GetPropertyName() const
{
    return "perspective-origin";
}

const WTF::AtomicString& PerspectiveOrigin::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("perspective-origin"));
    return name;
}

const char* PerspectiveOrigin::GetJSPropertyName() const
{
    return "perspectiveOrigin";
}

void PerspectiveOrigin::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPerspectiveOrigin(ComputedStyleInitialValues::InitialPerspectiveOrigin());
}
void PerspectiveOrigin::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPerspectiveOrigin(state.ParentStyle()->PerspectiveOrigin());
}
void PerspectiveOrigin::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPerspectiveOrigin(StyleBuilderConverter::ConvertPosition(state, value));
}

// pointer-events

const char* PointerEvents::GetPropertyName() const
{
    return "pointer-events";
}

const WTF::AtomicString& PointerEvents::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("pointer-events"));
    return name;
}

const char* PointerEvents::GetJSPropertyName() const
{
    return "pointerEvents";
}

void PointerEvents::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPointerEvents(ComputedStyleInitialValues::InitialPointerEvents());
    state.StyleBuilder().SetPointerEventsIsInherited(false);
}
void PointerEvents::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPointerEvents(state.ParentStyle()->PointerEvents());
    state.StyleBuilder().SetPointerEventsIsInherited(true);
}
void PointerEvents::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPointerEvents(To<CSSIdentifierValue>(value).ConvertTo<blink::EPointerEvents>());
    state.StyleBuilder().SetPointerEventsIsInherited(false);
}

// popover-hide-delay

CSSExposure PopoverHideDelay::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::HTMLPopoverActionHoverEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* PopoverHideDelay::GetPropertyName() const
{
    return "popover-hide-delay";
}

const WTF::AtomicString& PopoverHideDelay::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("popover-hide-delay"));
    return name;
}

const char* PopoverHideDelay::GetJSPropertyName() const
{
    return "popoverHideDelay";
}

void PopoverHideDelay::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPopoverHideDelay(ComputedStyleInitialValues::InitialPopoverHideDelay());
}
void PopoverHideDelay::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPopoverHideDelay(state.ParentStyle()->PopoverHideDelay());
}
void PopoverHideDelay::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPopoverHideDelay(StyleBuilderConverter::ConvertTimeValue(state, value));
}

// popover-show-delay

CSSExposure PopoverShowDelay::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::HTMLPopoverActionHoverEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* PopoverShowDelay::GetPropertyName() const
{
    return "popover-show-delay";
}

const WTF::AtomicString& PopoverShowDelay::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("popover-show-delay"));
    return name;
}

const char* PopoverShowDelay::GetJSPropertyName() const
{
    return "popoverShowDelay";
}

void PopoverShowDelay::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPopoverShowDelay(ComputedStyleInitialValues::InitialPopoverShowDelay());
}
void PopoverShowDelay::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPopoverShowDelay(state.ParentStyle()->PopoverShowDelay());
}
void PopoverShowDelay::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPopoverShowDelay(StyleBuilderConverter::ConvertTimeValue(state, value));
}

// position-try-fallbacks

const char* PositionTryFallbacks::GetPropertyName() const
{
    return "position-try-fallbacks";
}

const WTF::AtomicString& PositionTryFallbacks::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("position-try-fallbacks"));
    return name;
}

const char* PositionTryFallbacks::GetJSPropertyName() const
{
    return "positionTryFallbacks";
}

void PositionTryFallbacks::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPositionTryFallbacks(ComputedStyleInitialValues::InitialPositionTryFallbacks());
}
void PositionTryFallbacks::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPositionTryFallbacks(state.ParentStyle()->GetPositionTryFallbacks());
}

// position-try-order

const char* PositionTryOrder::GetPropertyName() const
{
    return "position-try-order";
}

const WTF::AtomicString& PositionTryOrder::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("position-try-order"));
    return name;
}

const char* PositionTryOrder::GetJSPropertyName() const
{
    return "positionTryOrder";
}

void PositionTryOrder::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPositionTryOrder(ComputedStyleInitialValues::InitialPositionTryOrder());
}
void PositionTryOrder::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPositionTryOrder(state.ParentStyle()->PositionTryOrder());
}
void PositionTryOrder::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPositionTryOrder(To<CSSIdentifierValue>(value).ConvertTo<blink::EPositionTryOrder>());
}

// position-visibility

const char* PositionVisibility::GetPropertyName() const
{
    return "position-visibility";
}

const WTF::AtomicString& PositionVisibility::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("position-visibility"));
    return name;
}

const char* PositionVisibility::GetJSPropertyName() const
{
    return "positionVisibility";
}

void PositionVisibility::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPositionVisibility(ComputedStyleInitialValues::InitialPositionVisibility());
}
void PositionVisibility::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPositionVisibility(state.ParentStyle()->GetPositionVisibility());
}
void PositionVisibility::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPositionVisibility(StyleBuilderConverter::ConvertPositionVisibility(state, value));
}

// prefix

const char* Prefix::GetPropertyName() const
{
    return "prefix";
}

const WTF::AtomicString& Prefix::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("prefix"));
    return name;
}

const char* Prefix::GetJSPropertyName() const
{
    return "prefix";
}

// quotes

const char* Quotes::GetPropertyName() const
{
    return "quotes";
}

const WTF::AtomicString& Quotes::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("quotes"));
    return name;
}

const char* Quotes::GetJSPropertyName() const
{
    return "quotes";
}

void Quotes::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetQuotes(ComputedStyleInitialValues::InitialQuotes());
}
void Quotes::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetQuotes(state.ParentStyle()->Quotes());
}
void Quotes::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetQuotes(StyleBuilderConverter::ConvertQuotes(state, value));
}

// r

const char* R::GetPropertyName() const
{
    return "r";
}

const WTF::AtomicString& R::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("r"));
    return name;
}

const char* R::GetJSPropertyName() const
{
    return "r";
}

void R::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetR(ComputedStyleInitialValues::InitialR());
}
void R::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetR(state.ParentStyle()->R());
}
void R::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetR(StyleBuilderConverter::ConvertLength(state, value));
}

// range

const char* Range::GetPropertyName() const
{
    return "range";
}

const WTF::AtomicString& Range::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("range"));
    return name;
}

const char* Range::GetJSPropertyName() const
{
    return "range";
}

// reading-flow

CSSExposure ReadingFlow::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSReadingFlowEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ReadingFlow::GetPropertyName() const
{
    return "reading-flow";
}

const WTF::AtomicString& ReadingFlow::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("reading-flow"));
    return name;
}

const char* ReadingFlow::GetJSPropertyName() const
{
    return "readingFlow";
}

void ReadingFlow::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetReadingFlow(ComputedStyleInitialValues::InitialReadingFlow());
}
void ReadingFlow::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetReadingFlow(state.ParentStyle()->ReadingFlow());
}
void ReadingFlow::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetReadingFlow(To<CSSIdentifierValue>(value).ConvertTo<blink::EReadingFlow>());
}

// resize

const char* Resize::GetPropertyName() const
{
    return "resize";
}

const WTF::AtomicString& Resize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("resize"));
    return name;
}

const char* Resize::GetJSPropertyName() const
{
    return "resize";
}

void Resize::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetResize(ComputedStyleInitialValues::InitialResize());
}
void Resize::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetResize(state.ParentStyle()->Resize());
}

// right

const char* Right::GetPropertyName() const
{
    return "right";
}

const WTF::AtomicString& Right::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("right"));
    return name;
}

const char* Right::GetJSPropertyName() const
{
    return "right";
}

bool Right::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalInsetMapping().Contains(id);
}

void Right::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetRight(ComputedStyleInitialValues::InitialRight());
}
void Right::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetRight(state.ParentStyle()->Right());
}
void Right::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    blink::AnchorScope anchor_scope(blink::AnchorScope::Mode::kRight, state.CssToLengthConversionData().GetAnchorEvaluator());
    state.StyleBuilder().SetRight(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

// rotate

const char* Rotate::GetPropertyName() const
{
    return "rotate";
}

const WTF::AtomicString& Rotate::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("rotate"));
    return name;
}

const char* Rotate::GetJSPropertyName() const
{
    return "rotate";
}

void Rotate::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetRotate(ComputedStyleInitialValues::InitialRotate());
}
void Rotate::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetRotate(state.ParentStyle()->Rotate());
}
void Rotate::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetRotate(StyleBuilderConverter::ConvertRotate(state, value));
}

// row-gap

const char* RowGap::GetPropertyName() const
{
    return "row-gap";
}

const WTF::AtomicString& RowGap::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("row-gap"));
    return name;
}

const char* RowGap::GetJSPropertyName() const
{
    return "rowGap";
}

void RowGap::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetRowGap(ComputedStyleInitialValues::InitialRowGap());
}
void RowGap::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetRowGap(state.ParentStyle()->RowGap());
}
void RowGap::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetRowGap(StyleBuilderConverter::ConvertGapLength(state, value));
}

// ruby-align

const char* RubyAlign::GetPropertyName() const
{
    return "ruby-align";
}

const WTF::AtomicString& RubyAlign::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("ruby-align"));
    return name;
}

const char* RubyAlign::GetJSPropertyName() const
{
    return "rubyAlign";
}

void RubyAlign::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetRubyAlign(ComputedStyleInitialValues::InitialRubyAlign());
}
void RubyAlign::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetRubyAlign(state.ParentStyle()->RubyAlign());
}
void RubyAlign::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetRubyAlign(To<CSSIdentifierValue>(value).ConvertTo<blink::ERubyAlign>());
}

// ruby-position

const char* RubyPosition::GetPropertyName() const
{
    return "ruby-position";
}

const WTF::AtomicString& RubyPosition::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("ruby-position"));
    return name;
}

const char* RubyPosition::GetJSPropertyName() const
{
    return "rubyPosition";
}

void RubyPosition::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetRubyPosition(ComputedStyleInitialValues::InitialRubyPosition());
}
void RubyPosition::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetRubyPosition(state.ParentStyle()->GetRubyPosition());
}
void RubyPosition::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetRubyPosition(StyleBuilderConverter::ConvertRubyPosition(state, value));
}

// rx

const char* Rx::GetPropertyName() const
{
    return "rx";
}

const WTF::AtomicString& Rx::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("rx"));
    return name;
}

const char* Rx::GetJSPropertyName() const
{
    return "rx";
}

void Rx::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetRx(ComputedStyleInitialValues::InitialRx());
}
void Rx::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetRx(state.ParentStyle()->Rx());
}
void Rx::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetRx(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

// ry

const char* Ry::GetPropertyName() const
{
    return "ry";
}

const WTF::AtomicString& Ry::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("ry"));
    return name;
}

const char* Ry::GetJSPropertyName() const
{
    return "ry";
}

void Ry::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetRy(ComputedStyleInitialValues::InitialRy());
}
void Ry::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetRy(state.ParentStyle()->Ry());
}
void Ry::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetRy(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

// scale

const char* Scale::GetPropertyName() const
{
    return "scale";
}

const WTF::AtomicString& Scale::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scale"));
    return name;
}

const char* Scale::GetJSPropertyName() const
{
    return "scale";
}

void Scale::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScale(ComputedStyleInitialValues::InitialScale());
}
void Scale::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScale(state.ParentStyle()->Scale());
}
void Scale::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScale(StyleBuilderConverter::ConvertScale(state, value));
}

// scroll-behavior

const char* ScrollBehavior::GetPropertyName() const
{
    return "scroll-behavior";
}

const WTF::AtomicString& ScrollBehavior::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-behavior"));
    return name;
}

const char* ScrollBehavior::GetJSPropertyName() const
{
    return "scrollBehavior";
}

void ScrollBehavior::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollBehavior(ComputedStyleInitialValues::InitialScrollBehavior());
}
void ScrollBehavior::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollBehavior(state.ParentStyle()->GetScrollBehavior());
}
void ScrollBehavior::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollBehavior(To<CSSIdentifierValue>(value).ConvertTo<blink::mojom::blink::ScrollBehavior>());
}

// scroll-margin-block-end

const char* ScrollMarginBlockEnd::GetPropertyName() const
{
    return "scroll-margin-block-end";
}

const WTF::AtomicString& ScrollMarginBlockEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-block-end"));
    return name;
}

const char* ScrollMarginBlockEnd::GetJSPropertyName() const
{
    return "scrollMarginBlockEnd";
}

const CSSProperty* ScrollMarginBlockEnd::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& ScrollMarginBlockEnd::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockEnd(writing_direction, CSSDirectionAwareResolver::PhysicalScrollMarginMapping());
}

bool ScrollMarginBlockEnd::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalScrollMarginMapping().Contains(id);
}

// scroll-margin-block-start

const char* ScrollMarginBlockStart::GetPropertyName() const
{
    return "scroll-margin-block-start";
}

const WTF::AtomicString& ScrollMarginBlockStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-block-start"));
    return name;
}

const char* ScrollMarginBlockStart::GetJSPropertyName() const
{
    return "scrollMarginBlockStart";
}

const CSSProperty* ScrollMarginBlockStart::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& ScrollMarginBlockStart::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockStart(writing_direction, CSSDirectionAwareResolver::PhysicalScrollMarginMapping());
}

bool ScrollMarginBlockStart::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalScrollMarginMapping().Contains(id);
}

// scroll-margin-bottom

const char* ScrollMarginBottom::GetPropertyName() const
{
    return "scroll-margin-bottom";
}

const WTF::AtomicString& ScrollMarginBottom::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-bottom"));
    return name;
}

const char* ScrollMarginBottom::GetJSPropertyName() const
{
    return "scrollMarginBottom";
}

bool ScrollMarginBottom::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalScrollMarginMapping().Contains(id);
}

void ScrollMarginBottom::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollMarginBottom(ComputedStyleInitialValues::InitialScrollMarginBottom());
}
void ScrollMarginBottom::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollMarginBottom(state.ParentStyle()->ScrollMarginBottom());
}
void ScrollMarginBottom::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollMarginBottom(StyleBuilderConverter::ConvertComputedLength<float>(state, value));
}

// scroll-margin-inline-end

const char* ScrollMarginInlineEnd::GetPropertyName() const
{
    return "scroll-margin-inline-end";
}

const WTF::AtomicString& ScrollMarginInlineEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-inline-end"));
    return name;
}

const char* ScrollMarginInlineEnd::GetJSPropertyName() const
{
    return "scrollMarginInlineEnd";
}

const CSSProperty* ScrollMarginInlineEnd::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& ScrollMarginInlineEnd::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineEnd(writing_direction, CSSDirectionAwareResolver::PhysicalScrollMarginMapping());
}

bool ScrollMarginInlineEnd::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalScrollMarginMapping().Contains(id);
}

// scroll-margin-inline-start

const char* ScrollMarginInlineStart::GetPropertyName() const
{
    return "scroll-margin-inline-start";
}

const WTF::AtomicString& ScrollMarginInlineStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-inline-start"));
    return name;
}

const char* ScrollMarginInlineStart::GetJSPropertyName() const
{
    return "scrollMarginInlineStart";
}

const CSSProperty* ScrollMarginInlineStart::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& ScrollMarginInlineStart::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineStart(writing_direction, CSSDirectionAwareResolver::PhysicalScrollMarginMapping());
}

bool ScrollMarginInlineStart::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalScrollMarginMapping().Contains(id);
}

// scroll-margin-left

const char* ScrollMarginLeft::GetPropertyName() const
{
    return "scroll-margin-left";
}

const WTF::AtomicString& ScrollMarginLeft::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-left"));
    return name;
}

const char* ScrollMarginLeft::GetJSPropertyName() const
{
    return "scrollMarginLeft";
}

bool ScrollMarginLeft::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalScrollMarginMapping().Contains(id);
}

void ScrollMarginLeft::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollMarginLeft(ComputedStyleInitialValues::InitialScrollMarginLeft());
}
void ScrollMarginLeft::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollMarginLeft(state.ParentStyle()->ScrollMarginLeft());
}
void ScrollMarginLeft::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollMarginLeft(StyleBuilderConverter::ConvertComputedLength<float>(state, value));
}

// scroll-margin-right

const char* ScrollMarginRight::GetPropertyName() const
{
    return "scroll-margin-right";
}

const WTF::AtomicString& ScrollMarginRight::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-right"));
    return name;
}

const char* ScrollMarginRight::GetJSPropertyName() const
{
    return "scrollMarginRight";
}

bool ScrollMarginRight::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalScrollMarginMapping().Contains(id);
}

void ScrollMarginRight::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollMarginRight(ComputedStyleInitialValues::InitialScrollMarginRight());
}
void ScrollMarginRight::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollMarginRight(state.ParentStyle()->ScrollMarginRight());
}
void ScrollMarginRight::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollMarginRight(StyleBuilderConverter::ConvertComputedLength<float>(state, value));
}

// scroll-margin-top

const char* ScrollMarginTop::GetPropertyName() const
{
    return "scroll-margin-top";
}

const WTF::AtomicString& ScrollMarginTop::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-margin-top"));
    return name;
}

const char* ScrollMarginTop::GetJSPropertyName() const
{
    return "scrollMarginTop";
}

bool ScrollMarginTop::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalScrollMarginMapping().Contains(id);
}

void ScrollMarginTop::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollMarginTop(ComputedStyleInitialValues::InitialScrollMarginTop());
}
void ScrollMarginTop::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollMarginTop(state.ParentStyle()->ScrollMarginTop());
}
void ScrollMarginTop::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollMarginTop(StyleBuilderConverter::ConvertComputedLength<float>(state, value));
}

// scroll-marker-group

CSSExposure ScrollMarkerGroup::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSPseudoScrollMarkersEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ScrollMarkerGroup::GetPropertyName() const
{
    return "scroll-marker-group";
}

const WTF::AtomicString& ScrollMarkerGroup::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-marker-group"));
    return name;
}

const char* ScrollMarkerGroup::GetJSPropertyName() const
{
    return "scrollMarkerGroup";
}

void ScrollMarkerGroup::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollMarkerGroup(ComputedStyleInitialValues::InitialScrollMarkerGroup());
}
void ScrollMarkerGroup::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollMarkerGroup(state.ParentStyle()->ScrollMarkerGroup());
}
void ScrollMarkerGroup::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollMarkerGroup(To<CSSIdentifierValue>(value).ConvertTo<blink::EScrollMarkerGroup>());
}

// scroll-padding-block-end

const char* ScrollPaddingBlockEnd::GetPropertyName() const
{
    return "scroll-padding-block-end";
}

const WTF::AtomicString& ScrollPaddingBlockEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-block-end"));
    return name;
}

const char* ScrollPaddingBlockEnd::GetJSPropertyName() const
{
    return "scrollPaddingBlockEnd";
}

const CSSProperty* ScrollPaddingBlockEnd::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& ScrollPaddingBlockEnd::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockEnd(writing_direction, CSSDirectionAwareResolver::PhysicalScrollPaddingMapping());
}

bool ScrollPaddingBlockEnd::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalScrollPaddingMapping().Contains(id);
}

// scroll-padding-block-start

const char* ScrollPaddingBlockStart::GetPropertyName() const
{
    return "scroll-padding-block-start";
}

const WTF::AtomicString& ScrollPaddingBlockStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-block-start"));
    return name;
}

const char* ScrollPaddingBlockStart::GetJSPropertyName() const
{
    return "scrollPaddingBlockStart";
}

const CSSProperty* ScrollPaddingBlockStart::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& ScrollPaddingBlockStart::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlockStart(writing_direction, CSSDirectionAwareResolver::PhysicalScrollPaddingMapping());
}

bool ScrollPaddingBlockStart::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalScrollPaddingMapping().Contains(id);
}

// scroll-padding-bottom

const char* ScrollPaddingBottom::GetPropertyName() const
{
    return "scroll-padding-bottom";
}

const WTF::AtomicString& ScrollPaddingBottom::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-bottom"));
    return name;
}

const char* ScrollPaddingBottom::GetJSPropertyName() const
{
    return "scrollPaddingBottom";
}

bool ScrollPaddingBottom::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalScrollPaddingMapping().Contains(id);
}

void ScrollPaddingBottom::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollPaddingBottom(ComputedStyleInitialValues::InitialScrollPaddingBottom());
}
void ScrollPaddingBottom::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollPaddingBottom(state.ParentStyle()->ScrollPaddingBottom());
}
void ScrollPaddingBottom::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollPaddingBottom(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

// scroll-padding-inline-end

const char* ScrollPaddingInlineEnd::GetPropertyName() const
{
    return "scroll-padding-inline-end";
}

const WTF::AtomicString& ScrollPaddingInlineEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-inline-end"));
    return name;
}

const char* ScrollPaddingInlineEnd::GetJSPropertyName() const
{
    return "scrollPaddingInlineEnd";
}

const CSSProperty* ScrollPaddingInlineEnd::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& ScrollPaddingInlineEnd::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineEnd(writing_direction, CSSDirectionAwareResolver::PhysicalScrollPaddingMapping());
}

bool ScrollPaddingInlineEnd::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalScrollPaddingMapping().Contains(id);
}

// scroll-padding-inline-start

const char* ScrollPaddingInlineStart::GetPropertyName() const
{
    return "scroll-padding-inline-start";
}

const WTF::AtomicString& ScrollPaddingInlineStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-inline-start"));
    return name;
}

const char* ScrollPaddingInlineStart::GetJSPropertyName() const
{
    return "scrollPaddingInlineStart";
}

const CSSProperty* ScrollPaddingInlineStart::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& ScrollPaddingInlineStart::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInlineStart(writing_direction, CSSDirectionAwareResolver::PhysicalScrollPaddingMapping());
}

bool ScrollPaddingInlineStart::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalScrollPaddingMapping().Contains(id);
}

// scroll-padding-left

const char* ScrollPaddingLeft::GetPropertyName() const
{
    return "scroll-padding-left";
}

const WTF::AtomicString& ScrollPaddingLeft::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-left"));
    return name;
}

const char* ScrollPaddingLeft::GetJSPropertyName() const
{
    return "scrollPaddingLeft";
}

bool ScrollPaddingLeft::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalScrollPaddingMapping().Contains(id);
}

void ScrollPaddingLeft::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollPaddingLeft(ComputedStyleInitialValues::InitialScrollPaddingLeft());
}
void ScrollPaddingLeft::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollPaddingLeft(state.ParentStyle()->ScrollPaddingLeft());
}
void ScrollPaddingLeft::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollPaddingLeft(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

// scroll-padding-right

const char* ScrollPaddingRight::GetPropertyName() const
{
    return "scroll-padding-right";
}

const WTF::AtomicString& ScrollPaddingRight::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-right"));
    return name;
}

const char* ScrollPaddingRight::GetJSPropertyName() const
{
    return "scrollPaddingRight";
}

bool ScrollPaddingRight::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalScrollPaddingMapping().Contains(id);
}

void ScrollPaddingRight::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollPaddingRight(ComputedStyleInitialValues::InitialScrollPaddingRight());
}
void ScrollPaddingRight::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollPaddingRight(state.ParentStyle()->ScrollPaddingRight());
}
void ScrollPaddingRight::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollPaddingRight(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

// scroll-padding-top

const char* ScrollPaddingTop::GetPropertyName() const
{
    return "scroll-padding-top";
}

const WTF::AtomicString& ScrollPaddingTop::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-padding-top"));
    return name;
}

const char* ScrollPaddingTop::GetJSPropertyName() const
{
    return "scrollPaddingTop";
}

bool ScrollPaddingTop::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalScrollPaddingMapping().Contains(id);
}

void ScrollPaddingTop::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollPaddingTop(ComputedStyleInitialValues::InitialScrollPaddingTop());
}
void ScrollPaddingTop::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollPaddingTop(state.ParentStyle()->ScrollPaddingTop());
}
void ScrollPaddingTop::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollPaddingTop(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

// scroll-snap-align

const char* ScrollSnapAlign::GetPropertyName() const
{
    return "scroll-snap-align";
}

const WTF::AtomicString& ScrollSnapAlign::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-snap-align"));
    return name;
}

const char* ScrollSnapAlign::GetJSPropertyName() const
{
    return "scrollSnapAlign";
}

void ScrollSnapAlign::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollSnapAlign(ComputedStyleInitialValues::InitialScrollSnapAlign());
}
void ScrollSnapAlign::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollSnapAlign(state.ParentStyle()->GetScrollSnapAlign());
}
void ScrollSnapAlign::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollSnapAlign(StyleBuilderConverter::ConvertSnapAlign(state, value));
}

// scroll-snap-stop

const char* ScrollSnapStop::GetPropertyName() const
{
    return "scroll-snap-stop";
}

const WTF::AtomicString& ScrollSnapStop::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-snap-stop"));
    return name;
}

const char* ScrollSnapStop::GetJSPropertyName() const
{
    return "scrollSnapStop";
}

void ScrollSnapStop::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollSnapStop(ComputedStyleInitialValues::InitialScrollSnapStop());
}
void ScrollSnapStop::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollSnapStop(state.ParentStyle()->ScrollSnapStop());
}
void ScrollSnapStop::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollSnapStop(To<CSSIdentifierValue>(value).ConvertTo<blink::EScrollSnapStop>());
}

// scroll-snap-type

const char* ScrollSnapType::GetPropertyName() const
{
    return "scroll-snap-type";
}

const WTF::AtomicString& ScrollSnapType::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-snap-type"));
    return name;
}

const char* ScrollSnapType::GetJSPropertyName() const
{
    return "scrollSnapType";
}

void ScrollSnapType::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollSnapType(ComputedStyleInitialValues::InitialScrollSnapType());
}
void ScrollSnapType::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollSnapType(state.ParentStyle()->GetScrollSnapType());
}
void ScrollSnapType::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollSnapType(StyleBuilderConverter::ConvertSnapType(state, value));
}

// scroll-start-block

CSSExposure ScrollStartBlock::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSScrollStartEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ScrollStartBlock::GetPropertyName() const
{
    return "scroll-start-block";
}

const WTF::AtomicString& ScrollStartBlock::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-start-block"));
    return name;
}

const char* ScrollStartBlock::GetJSPropertyName() const
{
    return "scrollStartBlock";
}

const CSSProperty* ScrollStartBlock::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& ScrollStartBlock::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveBlock(writing_direction, CSSDirectionAwareResolver::PhysicalScrollStartMapping());
}

bool ScrollStartBlock::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalScrollStartMapping().Contains(id);
}

// scroll-start-inline

CSSExposure ScrollStartInline::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSScrollStartEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ScrollStartInline::GetPropertyName() const
{
    return "scroll-start-inline";
}

const WTF::AtomicString& ScrollStartInline::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-start-inline"));
    return name;
}

const char* ScrollStartInline::GetJSPropertyName() const
{
    return "scrollStartInline";
}

const CSSProperty* ScrollStartInline::SurrogateFor(WritingDirectionMode writing_direction) const
{
    return &ResolveDirectionAwarePropertyInternal(writing_direction);
}

const CSSProperty& ScrollStartInline::ResolveDirectionAwarePropertyInternal(WritingDirectionMode writing_direction) const
{
    return CSSDirectionAwareResolver::ResolveInline(writing_direction, CSSDirectionAwareResolver::PhysicalScrollStartMapping());
}

bool ScrollStartInline::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::PhysicalScrollStartMapping().Contains(id);
}

// scroll-start-target

CSSExposure ScrollStartTarget::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSScrollStartTargetEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ScrollStartTarget::GetPropertyName() const
{
    return "scroll-start-target";
}

const WTF::AtomicString& ScrollStartTarget::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-start-target"));
    return name;
}

const char* ScrollStartTarget::GetJSPropertyName() const
{
    return "scrollStartTarget";
}

void ScrollStartTarget::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollStartTarget(ComputedStyleInitialValues::InitialScrollStartTarget());
}
void ScrollStartTarget::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollStartTarget(state.ParentStyle()->ScrollStartTarget());
}
void ScrollStartTarget::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollStartTarget(To<CSSIdentifierValue>(value).ConvertTo<blink::EScrollStartTarget>());
}

// scroll-start-x

CSSExposure ScrollStartX::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSScrollStartEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ScrollStartX::GetPropertyName() const
{
    return "scroll-start-x";
}

const WTF::AtomicString& ScrollStartX::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-start-x"));
    return name;
}

const char* ScrollStartX::GetJSPropertyName() const
{
    return "scrollStartX";
}

bool ScrollStartX::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalScrollStartMapping().Contains(id);
}

void ScrollStartX::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollStartX(ComputedStyleInitialValues::InitialScrollStartX());
}
void ScrollStartX::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollStartX(state.ParentStyle()->ScrollStartX());
}
void ScrollStartX::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollStartX(StyleBuilderConverter::ConvertScrollStart(state, value));
}

// scroll-start-y

CSSExposure ScrollStartY::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSScrollStartEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ScrollStartY::GetPropertyName() const
{
    return "scroll-start-y";
}

const WTF::AtomicString& ScrollStartY::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-start-y"));
    return name;
}

const char* ScrollStartY::GetJSPropertyName() const
{
    return "scrollStartY";
}

bool ScrollStartY::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalScrollStartMapping().Contains(id);
}

void ScrollStartY::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollStartY(ComputedStyleInitialValues::InitialScrollStartY());
}
void ScrollStartY::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollStartY(state.ParentStyle()->ScrollStartY());
}
void ScrollStartY::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollStartY(StyleBuilderConverter::ConvertScrollStart(state, value));
}

// scroll-timeline-axis

CSSExposure ScrollTimelineAxis::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::ScrollTimelineEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ScrollTimelineAxis::GetPropertyName() const
{
    return "scroll-timeline-axis";
}

const WTF::AtomicString& ScrollTimelineAxis::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-timeline-axis"));
    return name;
}

const char* ScrollTimelineAxis::GetJSPropertyName() const
{
    return "scrollTimelineAxis";
}

void ScrollTimelineAxis::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollTimelineAxis(ComputedStyleInitialValues::InitialScrollTimelineAxis());
}
void ScrollTimelineAxis::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollTimelineAxis(state.ParentStyle()->ScrollTimelineAxis());
}
void ScrollTimelineAxis::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollTimelineAxis(StyleBuilderConverter::ConvertViewTimelineAxis(state, value));
}

// scroll-timeline-name

CSSExposure ScrollTimelineName::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::ScrollTimelineEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ScrollTimelineName::GetPropertyName() const
{
    return "scroll-timeline-name";
}

const WTF::AtomicString& ScrollTimelineName::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scroll-timeline-name"));
    return name;
}

const char* ScrollTimelineName::GetJSPropertyName() const
{
    return "scrollTimelineName";
}

void ScrollTimelineName::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollTimelineName(ComputedStyleInitialValues::InitialScrollTimelineName());
}
void ScrollTimelineName::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollTimelineName(state.ParentStyle()->ScrollTimelineName());
}
void ScrollTimelineName::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollTimelineName(StyleBuilderConverter::ConvertViewTimelineName(state, value));
}

// scrollbar-color

CSSExposure ScrollbarColor::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::ScrollbarColorEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ScrollbarColor::GetPropertyName() const
{
    return "scrollbar-color";
}

const WTF::AtomicString& ScrollbarColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scrollbar-color"));
    return name;
}

const char* ScrollbarColor::GetJSPropertyName() const
{
    return "scrollbarColor";
}

void ScrollbarColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollbarColor(ComputedStyleInitialValues::InitialScrollbarColor());
}
void ScrollbarColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollbarColor(state.ParentStyle()->ScrollbarColor());
}
void ScrollbarColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollbarColor(StyleBuilderConverter::ConvertScrollbarColor(state, value));
}

// scrollbar-gutter

const char* ScrollbarGutter::GetPropertyName() const
{
    return "scrollbar-gutter";
}

const WTF::AtomicString& ScrollbarGutter::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scrollbar-gutter"));
    return name;
}

const char* ScrollbarGutter::GetJSPropertyName() const
{
    return "scrollbarGutter";
}

void ScrollbarGutter::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollbarGutter(ComputedStyleInitialValues::InitialScrollbarGutter());
}
void ScrollbarGutter::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollbarGutter(state.ParentStyle()->ScrollbarGutter());
}
void ScrollbarGutter::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollbarGutter(StyleBuilderConverter::ConvertScrollbarGutter(state, value));
}

// scrollbar-width

CSSExposure ScrollbarWidth::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::ScrollbarWidthEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ScrollbarWidth::GetPropertyName() const
{
    return "scrollbar-width";
}

const WTF::AtomicString& ScrollbarWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("scrollbar-width"));
    return name;
}

const char* ScrollbarWidth::GetJSPropertyName() const
{
    return "scrollbarWidth";
}

void ScrollbarWidth::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollbarWidth(ComputedStyleInitialValues::InitialScrollbarWidth());
}
void ScrollbarWidth::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetScrollbarWidth(state.ParentStyle()->ScrollbarWidth());
}
void ScrollbarWidth::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetScrollbarWidth(To<CSSIdentifierValue>(value).ConvertTo<blink::EScrollbarWidth>());
}

// shape-image-threshold

const char* ShapeImageThreshold::GetPropertyName() const
{
    return "shape-image-threshold";
}

const WTF::AtomicString& ShapeImageThreshold::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("shape-image-threshold"));
    return name;
}

const char* ShapeImageThreshold::GetJSPropertyName() const
{
    return "shapeImageThreshold";
}

void ShapeImageThreshold::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetShapeImageThreshold(ComputedStyleInitialValues::InitialShapeImageThreshold());
}
void ShapeImageThreshold::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetShapeImageThreshold(state.ParentStyle()->ShapeImageThreshold());
}
void ShapeImageThreshold::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetShapeImageThreshold(To<CSSPrimitiveValue>(value).ConvertTo<float>(state.CssToLengthConversionData()));
}

// shape-margin

const char* ShapeMargin::GetPropertyName() const
{
    return "shape-margin";
}

const WTF::AtomicString& ShapeMargin::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("shape-margin"));
    return name;
}

const char* ShapeMargin::GetJSPropertyName() const
{
    return "shapeMargin";
}

void ShapeMargin::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetShapeMargin(ComputedStyleInitialValues::InitialShapeMargin());
}
void ShapeMargin::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetShapeMargin(state.ParentStyle()->ShapeMargin());
}
void ShapeMargin::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetShapeMargin(StyleBuilderConverter::ConvertLength(state, value));
}

// shape-outside

const char* ShapeOutside::GetPropertyName() const
{
    return "shape-outside";
}

const WTF::AtomicString& ShapeOutside::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("shape-outside"));
    return name;
}

const char* ShapeOutside::GetJSPropertyName() const
{
    return "shapeOutside";
}

void ShapeOutside::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetShapeOutside(ComputedStyleInitialValues::InitialShapeOutside());
}
void ShapeOutside::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetShapeOutside(state.ParentStyle()->ShapeOutside());
}
void ShapeOutside::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetShapeOutside(StyleBuilderConverter::ConvertShapeValue(state, value));
}

// shape-rendering

const char* ShapeRendering::GetPropertyName() const
{
    return "shape-rendering";
}

const WTF::AtomicString& ShapeRendering::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("shape-rendering"));
    return name;
}

const char* ShapeRendering::GetJSPropertyName() const
{
    return "shapeRendering";
}

void ShapeRendering::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetShapeRendering(ComputedStyleInitialValues::InitialShapeRendering());
}
void ShapeRendering::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetShapeRendering(state.ParentStyle()->ShapeRendering());
}
void ShapeRendering::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetShapeRendering(To<CSSIdentifierValue>(value).ConvertTo<blink::EShapeRendering>());
}

// size

const char* Size::GetPropertyName() const
{
    return "size";
}

const WTF::AtomicString& Size::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("size"));
    return name;
}

const char* Size::GetJSPropertyName() const
{
    return "size";
}

// size-adjust

const char* SizeAdjust::GetPropertyName() const
{
    return "size-adjust";
}

const WTF::AtomicString& SizeAdjust::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("size-adjust"));
    return name;
}

const char* SizeAdjust::GetJSPropertyName() const
{
    return "sizeAdjust";
}

// speak

const char* Speak::GetPropertyName() const
{
    return "speak";
}

const WTF::AtomicString& Speak::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("speak"));
    return name;
}

const char* Speak::GetJSPropertyName() const
{
    return "speak";
}

void Speak::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetSpeak(ComputedStyleInitialValues::InitialSpeak());
}
void Speak::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetSpeak(state.ParentStyle()->Speak());
}
void Speak::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetSpeak(To<CSSIdentifierValue>(value).ConvertTo<blink::ESpeak>());
}

// speak-as

const char* SpeakAs::GetPropertyName() const
{
    return "speak-as";
}

const WTF::AtomicString& SpeakAs::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("speak-as"));
    return name;
}

const char* SpeakAs::GetJSPropertyName() const
{
    return "speakAs";
}

// src

const char* Src::GetPropertyName() const
{
    return "src";
}

const WTF::AtomicString& Src::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("src"));
    return name;
}

const char* Src::GetJSPropertyName() const
{
    return "src";
}

// stop-color

const char* StopColor::GetPropertyName() const
{
    return "stop-color";
}

const WTF::AtomicString& StopColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("stop-color"));
    return name;
}

const char* StopColor::GetJSPropertyName() const
{
    return "stopColor";
}

void StopColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetStopColor(ComputedStyleInitialValues::InitialStopColor());
}

void StopColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetStopColor(state.ParentStyle()->StopColor());
}

void StopColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetStopColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// stop-opacity

const char* StopOpacity::GetPropertyName() const
{
    return "stop-opacity";
}

const WTF::AtomicString& StopOpacity::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("stop-opacity"));
    return name;
}

const char* StopOpacity::GetJSPropertyName() const
{
    return "stopOpacity";
}

void StopOpacity::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetStopOpacity(ComputedStyleInitialValues::InitialStopOpacity());
}
void StopOpacity::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetStopOpacity(state.ParentStyle()->StopOpacity());
}
void StopOpacity::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetStopOpacity(StyleBuilderConverter::ConvertAlpha(state, value));
}

// stroke

const char* Stroke::GetPropertyName() const
{
    return "stroke";
}

const WTF::AtomicString& Stroke::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke"));
    return name;
}

const char* Stroke::GetJSPropertyName() const
{
    return "stroke";
}

void Stroke::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetStrokePaint(ComputedStyleInitialValues::InitialStrokePaint());
}

void Stroke::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetStrokePaint(state.ParentStyle()->StrokePaint());
}

// stroke-dasharray

const char* StrokeDasharray::GetPropertyName() const
{
    return "stroke-dasharray";
}

const WTF::AtomicString& StrokeDasharray::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke-dasharray"));
    return name;
}

const char* StrokeDasharray::GetJSPropertyName() const
{
    return "strokeDasharray";
}

void StrokeDasharray::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetStrokeDashArray(ComputedStyleInitialValues::InitialStrokeDashArray());
}
void StrokeDasharray::ApplyInherit(StyleResolverState& state) const
{
    if (state.GetDocument().StandardizedBrowserZoomEnabled()) {
        if (ApplyParentValueIfZoomChanged(state)) {
            return;
        }
    }
    state.StyleBuilder().SetStrokeDashArray(state.ParentStyle()->StrokeDashArray());
}
void StrokeDasharray::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetStrokeDashArray(StyleBuilderConverter::ConvertStrokeDasharray(state, value));
}

// stroke-dashoffset

const char* StrokeDashoffset::GetPropertyName() const
{
    return "stroke-dashoffset";
}

const WTF::AtomicString& StrokeDashoffset::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke-dashoffset"));
    return name;
}

const char* StrokeDashoffset::GetJSPropertyName() const
{
    return "strokeDashoffset";
}

void StrokeDashoffset::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetStrokeDashOffset(ComputedStyleInitialValues::InitialStrokeDashOffset());
}
void StrokeDashoffset::ApplyInherit(StyleResolverState& state) const
{
    if (state.GetDocument().StandardizedBrowserZoomEnabled()) {
        if (ApplyParentValueIfZoomChanged(state)) {
            return;
        }
    }
    state.StyleBuilder().SetStrokeDashOffset(state.ParentStyle()->StrokeDashOffset());
}
void StrokeDashoffset::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetStrokeDashOffset(StyleBuilderConverter::ConvertLength(state, value));
}

// stroke-linecap

const char* StrokeLinecap::GetPropertyName() const
{
    return "stroke-linecap";
}

const WTF::AtomicString& StrokeLinecap::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke-linecap"));
    return name;
}

const char* StrokeLinecap::GetJSPropertyName() const
{
    return "strokeLinecap";
}

void StrokeLinecap::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetCapStyle(ComputedStyleInitialValues::InitialCapStyle());
}
void StrokeLinecap::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetCapStyle(state.ParentStyle()->CapStyle());
}
void StrokeLinecap::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetCapStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::LineCap>());
}

// stroke-linejoin

const char* StrokeLinejoin::GetPropertyName() const
{
    return "stroke-linejoin";
}

const WTF::AtomicString& StrokeLinejoin::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke-linejoin"));
    return name;
}

const char* StrokeLinejoin::GetJSPropertyName() const
{
    return "strokeLinejoin";
}

void StrokeLinejoin::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetJoinStyle(ComputedStyleInitialValues::InitialJoinStyle());
}
void StrokeLinejoin::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetJoinStyle(state.ParentStyle()->JoinStyle());
}
void StrokeLinejoin::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetJoinStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::LineJoin>());
}

// stroke-miterlimit

const char* StrokeMiterlimit::GetPropertyName() const
{
    return "stroke-miterlimit";
}

const WTF::AtomicString& StrokeMiterlimit::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke-miterlimit"));
    return name;
}

const char* StrokeMiterlimit::GetJSPropertyName() const
{
    return "strokeMiterlimit";
}

void StrokeMiterlimit::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetStrokeMiterLimit(ComputedStyleInitialValues::InitialStrokeMiterLimit());
}
void StrokeMiterlimit::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetStrokeMiterLimit(state.ParentStyle()->StrokeMiterLimit());
}
void StrokeMiterlimit::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetStrokeMiterLimit(To<CSSPrimitiveValue>(value).ConvertTo<float>(state.CssToLengthConversionData()));
}

// stroke-opacity

const char* StrokeOpacity::GetPropertyName() const
{
    return "stroke-opacity";
}

const WTF::AtomicString& StrokeOpacity::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke-opacity"));
    return name;
}

const char* StrokeOpacity::GetJSPropertyName() const
{
    return "strokeOpacity";
}

void StrokeOpacity::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetStrokeOpacity(ComputedStyleInitialValues::InitialStrokeOpacity());
}
void StrokeOpacity::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetStrokeOpacity(state.ParentStyle()->StrokeOpacity());
}
void StrokeOpacity::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetStrokeOpacity(StyleBuilderConverter::ConvertAlpha(state, value));
}

// stroke-width

const char* StrokeWidth::GetPropertyName() const
{
    return "stroke-width";
}

const WTF::AtomicString& StrokeWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("stroke-width"));
    return name;
}

const char* StrokeWidth::GetJSPropertyName() const
{
    return "strokeWidth";
}

void StrokeWidth::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetStrokeWidth(ComputedStyleInitialValues::InitialStrokeWidth());
}
void StrokeWidth::ApplyInherit(StyleResolverState& state) const
{
    if (state.GetDocument().StandardizedBrowserZoomEnabled()) {
        if (ApplyParentValueIfZoomChanged(state)) {
            return;
        }
    }
    state.StyleBuilder().SetStrokeWidth(state.ParentStyle()->StrokeWidth());
}
void StrokeWidth::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetStrokeWidth(StyleBuilderConverter::ConvertUnzoomedLength(state, value));
}

// suffix

const char* Suffix::GetPropertyName() const
{
    return "suffix";
}

const WTF::AtomicString& Suffix::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("suffix"));
    return name;
}

const char* Suffix::GetJSPropertyName() const
{
    return "suffix";
}

// symbols

const char* Symbols::GetPropertyName() const
{
    return "symbols";
}

const WTF::AtomicString& Symbols::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("symbols"));
    return name;
}

const char* Symbols::GetJSPropertyName() const
{
    return "symbols";
}

// syntax

const char* Syntax::GetPropertyName() const
{
    return "syntax";
}

const WTF::AtomicString& Syntax::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("syntax"));
    return name;
}

const char* Syntax::GetJSPropertyName() const
{
    return "syntax";
}

// system

const char* System::GetPropertyName() const
{
    return "system";
}

const WTF::AtomicString& System::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("system"));
    return name;
}

const char* System::GetJSPropertyName() const
{
    return "system";
}

// tab-size

const char* TabSize::GetPropertyName() const
{
    return "tab-size";
}

const WTF::AtomicString& TabSize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("tab-size"));
    return name;
}

const char* TabSize::GetJSPropertyName() const
{
    return "tabSize";
}

void TabSize::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTabSize(ComputedStyleInitialValues::InitialTabSize());
}
void TabSize::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTabSize(state.ParentStyle()->GetTabSize());
}
void TabSize::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTabSize(StyleBuilderConverter::ConvertLengthOrTabSpaces(state, value));
}

// table-layout

const char* TableLayout::GetPropertyName() const
{
    return "table-layout";
}

const WTF::AtomicString& TableLayout::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("table-layout"));
    return name;
}

const char* TableLayout::GetJSPropertyName() const
{
    return "tableLayout";
}

void TableLayout::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTableLayout(ComputedStyleInitialValues::InitialTableLayout());
}
void TableLayout::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTableLayout(state.ParentStyle()->TableLayout());
}
void TableLayout::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTableLayout(To<CSSIdentifierValue>(value).ConvertTo<blink::ETableLayout>());
}

// text-align

const char* TextAlign::GetPropertyName() const
{
    return "text-align";
}

const WTF::AtomicString& TextAlign::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-align"));
    return name;
}

const char* TextAlign::GetJSPropertyName() const
{
    return "textAlign";
}

void TextAlign::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextAlign(ComputedStyleInitialValues::InitialTextAlign());
}
void TextAlign::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextAlign(state.ParentStyle()->GetTextAlign());
}

// text-align-last

const char* TextAlignLast::GetPropertyName() const
{
    return "text-align-last";
}

const WTF::AtomicString& TextAlignLast::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-align-last"));
    return name;
}

const char* TextAlignLast::GetJSPropertyName() const
{
    return "textAlignLast";
}

void TextAlignLast::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextAlignLast(ComputedStyleInitialValues::InitialTextAlignLast());
}
void TextAlignLast::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextAlignLast(state.ParentStyle()->TextAlignLast());
}
void TextAlignLast::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextAlignLast(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextAlignLast>());
}

// text-anchor

const char* TextAnchor::GetPropertyName() const
{
    return "text-anchor";
}

const WTF::AtomicString& TextAnchor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-anchor"));
    return name;
}

const char* TextAnchor::GetJSPropertyName() const
{
    return "textAnchor";
}

void TextAnchor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextAnchor(ComputedStyleInitialValues::InitialTextAnchor());
}
void TextAnchor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextAnchor(state.ParentStyle()->TextAnchor());
}
void TextAnchor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextAnchor(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextAnchor>());
}

// text-autospace

CSSExposure TextAutospace::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSTextAutoSpaceEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* TextAutospace::GetPropertyName() const
{
    return "text-autospace";
}

const WTF::AtomicString& TextAutospace::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-autospace"));
    return name;
}

const char* TextAutospace::GetJSPropertyName() const
{
    return "textAutospace";
}

void TextAutospace::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextAutospace(ComputedStyleInitialValues::InitialTextAutospace());
}
void TextAutospace::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextAutospace(state.ParentStyle()->TextAutospace());
}
void TextAutospace::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextAutospace(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextAutospace>());
}

// text-box-edge

CSSExposure TextBoxEdge::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSTextBoxTrimEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* TextBoxEdge::GetPropertyName() const
{
    return "text-box-edge";
}

const WTF::AtomicString& TextBoxEdge::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-box-edge"));
    return name;
}

const char* TextBoxEdge::GetJSPropertyName() const
{
    return "textBoxEdge";
}

void TextBoxEdge::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextBoxEdge(ComputedStyleInitialValues::InitialTextBoxEdge());
}
void TextBoxEdge::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextBoxEdge(state.ParentStyle()->GetTextBoxEdge());
}
void TextBoxEdge::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextBoxEdge(StyleBuilderConverter::ConvertTextBoxEdge(state, value));
}

// text-box-trim

CSSExposure TextBoxTrim::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSTextBoxTrimEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* TextBoxTrim::GetPropertyName() const
{
    return "text-box-trim";
}

const WTF::AtomicString& TextBoxTrim::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-box-trim"));
    return name;
}

const char* TextBoxTrim::GetJSPropertyName() const
{
    return "textBoxTrim";
}

void TextBoxTrim::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextBoxTrim(ComputedStyleInitialValues::InitialTextBoxTrim());
}
void TextBoxTrim::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextBoxTrim(state.ParentStyle()->TextBoxTrim());
}
void TextBoxTrim::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextBoxTrim(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextBoxTrim>());
}

// text-combine-upright

const char* TextCombineUpright::GetPropertyName() const
{
    return "text-combine-upright";
}

const WTF::AtomicString& TextCombineUpright::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-combine-upright"));
    return name;
}

const char* TextCombineUpright::GetJSPropertyName() const
{
    return "textCombineUpright";
}

void TextCombineUpright::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextCombine(ComputedStyleInitialValues::InitialTextCombine());
}
void TextCombineUpright::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextCombine(state.ParentStyle()->TextCombine());
}
void TextCombineUpright::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextCombine(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextCombine>());
}

// text-decoration-color

const char* TextDecorationColor::GetPropertyName() const
{
    return "text-decoration-color";
}

const WTF::AtomicString& TextDecorationColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-decoration-color"));
    return name;
}

const char* TextDecorationColor::GetJSPropertyName() const
{
    return "textDecorationColor";
}

void TextDecorationColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextDecorationColor(StyleColor::CurrentColor());
}

void TextDecorationColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextDecorationColor(state.ParentStyle()->TextDecorationColor());
}

void TextDecorationColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextDecorationColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// text-decoration-line

const char* TextDecorationLine::GetPropertyName() const
{
    return "text-decoration-line";
}

const WTF::AtomicString& TextDecorationLine::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-decoration-line"));
    return name;
}

const char* TextDecorationLine::GetJSPropertyName() const
{
    return "textDecorationLine";
}

void TextDecorationLine::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextDecorationLine(ComputedStyleInitialValues::InitialTextDecorationLine());
}
void TextDecorationLine::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextDecorationLine(state.ParentStyle()->GetTextDecorationLine());
}
void TextDecorationLine::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextDecorationLine(StyleBuilderConverter::ConvertFlags<blink::TextDecorationLine>(state, value));
}

// text-decoration-skip-ink

const char* TextDecorationSkipInk::GetPropertyName() const
{
    return "text-decoration-skip-ink";
}

const WTF::AtomicString& TextDecorationSkipInk::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-decoration-skip-ink"));
    return name;
}

const char* TextDecorationSkipInk::GetJSPropertyName() const
{
    return "textDecorationSkipInk";
}

void TextDecorationSkipInk::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextDecorationSkipInk(ComputedStyleInitialValues::InitialTextDecorationSkipInk());
}
void TextDecorationSkipInk::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextDecorationSkipInk(state.ParentStyle()->TextDecorationSkipInk());
}
void TextDecorationSkipInk::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextDecorationSkipInk(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextDecorationSkipInk>());
}

// text-decoration-style

const char* TextDecorationStyle::GetPropertyName() const
{
    return "text-decoration-style";
}

const WTF::AtomicString& TextDecorationStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-decoration-style"));
    return name;
}

const char* TextDecorationStyle::GetJSPropertyName() const
{
    return "textDecorationStyle";
}

void TextDecorationStyle::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextDecorationStyle(ComputedStyleInitialValues::InitialTextDecorationStyle());
}
void TextDecorationStyle::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextDecorationStyle(state.ParentStyle()->TextDecorationStyle());
}
void TextDecorationStyle::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextDecorationStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextDecorationStyle>());
}

// text-decoration-thickness

const char* TextDecorationThickness::GetPropertyName() const
{
    return "text-decoration-thickness";
}

const WTF::AtomicString& TextDecorationThickness::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-decoration-thickness"));
    return name;
}

const char* TextDecorationThickness::GetJSPropertyName() const
{
    return "textDecorationThickness";
}

void TextDecorationThickness::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextDecorationThickness(ComputedStyleInitialValues::InitialTextDecorationThickness());
}
void TextDecorationThickness::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextDecorationThickness(state.ParentStyle()->GetTextDecorationThickness());
}
void TextDecorationThickness::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextDecorationThickness(StyleBuilderConverter::ConvertTextDecorationThickness(state, value));
}

// text-emphasis-color

const char* TextEmphasisColor::GetPropertyName() const
{
    return "text-emphasis-color";
}

const WTF::AtomicString& TextEmphasisColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-emphasis-color"));
    return name;
}

const char* TextEmphasisColor::GetJSPropertyName() const
{
    return "textEmphasisColor";
}

void TextEmphasisColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextEmphasisColor(StyleColor::CurrentColor());
}

void TextEmphasisColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextEmphasisColor(state.ParentStyle()->TextEmphasisColor());
}

void TextEmphasisColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextEmphasisColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// text-emphasis-position

const char* TextEmphasisPosition::GetPropertyName() const
{
    return "text-emphasis-position";
}

const WTF::AtomicString& TextEmphasisPosition::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-emphasis-position"));
    return name;
}

const char* TextEmphasisPosition::GetJSPropertyName() const
{
    return "textEmphasisPosition";
}

void TextEmphasisPosition::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextEmphasisPosition(ComputedStyleInitialValues::InitialTextEmphasisPosition());
}
void TextEmphasisPosition::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextEmphasisPosition(state.ParentStyle()->GetTextEmphasisPosition());
}
void TextEmphasisPosition::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextEmphasisPosition(StyleBuilderConverter::ConvertTextTextEmphasisPosition(state, value));
}

// text-emphasis-style

const char* TextEmphasisStyle::GetPropertyName() const
{
    return "text-emphasis-style";
}

const WTF::AtomicString& TextEmphasisStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-emphasis-style"));
    return name;
}

const char* TextEmphasisStyle::GetJSPropertyName() const
{
    return "textEmphasisStyle";
}

// text-indent

const char* TextIndent::GetPropertyName() const
{
    return "text-indent";
}

const WTF::AtomicString& TextIndent::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-indent"));
    return name;
}

const char* TextIndent::GetJSPropertyName() const
{
    return "textIndent";
}

void TextIndent::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextIndent(ComputedStyleInitialValues::InitialTextIndent());
}
void TextIndent::ApplyInherit(StyleResolverState& state) const
{
    if (state.GetDocument().StandardizedBrowserZoomEnabled()) {
        if (ApplyParentValueIfZoomChanged(state)) {
            return;
        }
    }
    state.StyleBuilder().SetTextIndent(state.ParentStyle()->TextIndent());
}

// text-overflow

const char* TextOverflow::GetPropertyName() const
{
    return "text-overflow";
}

const WTF::AtomicString& TextOverflow::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-overflow"));
    return name;
}

const char* TextOverflow::GetJSPropertyName() const
{
    return "textOverflow";
}

void TextOverflow::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextOverflow(ComputedStyleInitialValues::InitialTextOverflow());
}
void TextOverflow::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextOverflow(state.ParentStyle()->TextOverflow());
}
void TextOverflow::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextOverflow(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextOverflow>());
}

// text-shadow

const char* TextShadow::GetPropertyName() const
{
    return "text-shadow";
}

const WTF::AtomicString& TextShadow::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-shadow"));
    return name;
}

const char* TextShadow::GetJSPropertyName() const
{
    return "textShadow";
}

void TextShadow::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextShadow(ComputedStyleInitialValues::InitialTextShadow());
}
void TextShadow::ApplyInherit(StyleResolverState& state) const
{
    if (state.GetDocument().StandardizedBrowserZoomEnabled()) {
        if (ApplyParentValueIfZoomChanged(state)) {
            return;
        }
    }
    state.StyleBuilder().SetTextShadow(state.ParentStyle()->TextShadow());
}
void TextShadow::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextShadow(StyleBuilderConverter::ConvertShadowList(state, value));
}

// text-transform

const char* TextTransform::GetPropertyName() const
{
    return "text-transform";
}

const WTF::AtomicString& TextTransform::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-transform"));
    return name;
}

const char* TextTransform::GetJSPropertyName() const
{
    return "textTransform";
}

void TextTransform::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextTransform(ComputedStyleInitialValues::InitialTextTransform());
    state.StyleBuilder().SetTextTransformIsInherited(false);
}
void TextTransform::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextTransform(state.ParentStyle()->TextTransform());
    state.StyleBuilder().SetTextTransformIsInherited(true);
}
void TextTransform::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextTransform(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextTransform>());
    state.StyleBuilder().SetTextTransformIsInherited(false);
}

// text-underline-offset

const char* TextUnderlineOffset::GetPropertyName() const
{
    return "text-underline-offset";
}

const WTF::AtomicString& TextUnderlineOffset::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-underline-offset"));
    return name;
}

const char* TextUnderlineOffset::GetJSPropertyName() const
{
    return "textUnderlineOffset";
}

void TextUnderlineOffset::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextUnderlineOffset(ComputedStyleInitialValues::InitialTextUnderlineOffset());
}
void TextUnderlineOffset::ApplyInherit(StyleResolverState& state) const
{
    if (state.GetDocument().StandardizedBrowserZoomEnabled()) {
        if (ApplyParentValueIfZoomChanged(state)) {
            return;
        }
    }
    state.StyleBuilder().SetTextUnderlineOffset(state.ParentStyle()->TextUnderlineOffset());
}
void TextUnderlineOffset::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextUnderlineOffset(StyleBuilderConverter::ConvertTextUnderlineOffset(state, value));
}

// text-underline-position

const char* TextUnderlinePosition::GetPropertyName() const
{
    return "text-underline-position";
}

const WTF::AtomicString& TextUnderlinePosition::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-underline-position"));
    return name;
}

const char* TextUnderlinePosition::GetJSPropertyName() const
{
    return "textUnderlinePosition";
}

void TextUnderlinePosition::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextUnderlinePosition(ComputedStyleInitialValues::InitialTextUnderlinePosition());
}
void TextUnderlinePosition::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextUnderlinePosition(state.ParentStyle()->GetTextUnderlinePosition());
}
void TextUnderlinePosition::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextUnderlinePosition(StyleBuilderConverter::ConvertTextUnderlinePosition(state, value));
}

// text-wrap-mode

const char* TextWrapMode::GetPropertyName() const
{
    return "text-wrap-mode";
}

const WTF::AtomicString& TextWrapMode::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-wrap-mode"));
    return name;
}

const char* TextWrapMode::GetJSPropertyName() const
{
    return "textWrapMode";
}

void TextWrapMode::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextWrapMode(ComputedStyleInitialValues::InitialTextWrapMode());
}
void TextWrapMode::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextWrapMode(state.ParentStyle()->GetTextWrapMode());
}
void TextWrapMode::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextWrapMode(To<CSSIdentifierValue>(value).ConvertTo<blink::TextWrapMode>());
}

// text-wrap-style

const char* TextWrapStyle::GetPropertyName() const
{
    return "text-wrap-style";
}

const WTF::AtomicString& TextWrapStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("text-wrap-style"));
    return name;
}

const char* TextWrapStyle::GetJSPropertyName() const
{
    return "textWrapStyle";
}

void TextWrapStyle::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextWrapStyle(ComputedStyleInitialValues::InitialTextWrapStyle());
}
void TextWrapStyle::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextWrapStyle(state.ParentStyle()->GetTextWrapStyle());
}
void TextWrapStyle::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextWrapStyle(To<CSSIdentifierValue>(value).ConvertTo<blink::TextWrapStyle>());
}

// timeline-scope

CSSExposure TimelineScope::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::TimelineScopeEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* TimelineScope::GetPropertyName() const
{
    return "timeline-scope";
}

const WTF::AtomicString& TimelineScope::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("timeline-scope"));
    return name;
}

const char* TimelineScope::GetJSPropertyName() const
{
    return "timelineScope";
}

void TimelineScope::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTimelineScope(ComputedStyleInitialValues::InitialTimelineScope());
}
void TimelineScope::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTimelineScope(state.ParentStyle()->TimelineScope());
}
void TimelineScope::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTimelineScope(StyleBuilderConverter::ConvertTimelineScope(state, value));
}

// top

const char* Top::GetPropertyName() const
{
    return "top";
}

const WTF::AtomicString& Top::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("top"));
    return name;
}

const char* Top::GetJSPropertyName() const
{
    return "top";
}

bool Top::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalInsetMapping().Contains(id);
}

void Top::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTop(ComputedStyleInitialValues::InitialTop());
}
void Top::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTop(state.ParentStyle()->Top());
}
void Top::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    blink::AnchorScope anchor_scope(blink::AnchorScope::Mode::kTop, state.CssToLengthConversionData().GetAnchorEvaluator());
    state.StyleBuilder().SetTop(StyleBuilderConverter::ConvertLengthOrAuto(state, value));
}

// touch-action

const char* TouchAction::GetPropertyName() const
{
    return "touch-action";
}

const WTF::AtomicString& TouchAction::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("touch-action"));
    return name;
}

const char* TouchAction::GetJSPropertyName() const
{
    return "touchAction";
}

void TouchAction::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTouchAction(ComputedStyleInitialValues::InitialTouchAction());
}
void TouchAction::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTouchAction(state.ParentStyle()->GetTouchAction());
}
void TouchAction::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTouchAction(StyleBuilderConverter::ConvertFlags<blink::TouchAction>(state, value));
}

// transform

const char* Transform::GetPropertyName() const
{
    return "transform";
}

const WTF::AtomicString& Transform::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("transform"));
    return name;
}

const char* Transform::GetJSPropertyName() const
{
    return "transform";
}

void Transform::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTransform(ComputedStyleInitialValues::InitialTransform());
}
void Transform::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTransform(state.ParentStyle()->Transform());
}
void Transform::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTransform(StyleBuilderConverter::ConvertTransformOperations(state, value));
}

// transform-box

const char* TransformBox::GetPropertyName() const
{
    return "transform-box";
}

const WTF::AtomicString& TransformBox::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("transform-box"));
    return name;
}

const char* TransformBox::GetJSPropertyName() const
{
    return "transformBox";
}

void TransformBox::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTransformBox(ComputedStyleInitialValues::InitialTransformBox());
}
void TransformBox::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTransformBox(state.ParentStyle()->TransformBox());
}
void TransformBox::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTransformBox(To<CSSIdentifierValue>(value).ConvertTo<blink::ETransformBox>());
}

// transform-origin

const char* TransformOrigin::GetPropertyName() const
{
    return "transform-origin";
}

const WTF::AtomicString& TransformOrigin::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("transform-origin"));
    return name;
}

const char* TransformOrigin::GetJSPropertyName() const
{
    return "transformOrigin";
}

void TransformOrigin::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTransformOrigin(ComputedStyleInitialValues::InitialTransformOrigin());
}
void TransformOrigin::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTransformOrigin(state.ParentStyle()->GetTransformOrigin());
}
void TransformOrigin::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTransformOrigin(StyleBuilderConverter::ConvertTransformOrigin(state, value));
}

// transform-style

const char* TransformStyle::GetPropertyName() const
{
    return "transform-style";
}

const WTF::AtomicString& TransformStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("transform-style"));
    return name;
}

const char* TransformStyle::GetJSPropertyName() const
{
    return "transformStyle";
}

void TransformStyle::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTransformStyle3D(ComputedStyleInitialValues::InitialTransformStyle3D());
}
void TransformStyle::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTransformStyle3D(state.ParentStyle()->TransformStyle3D());
}
void TransformStyle::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTransformStyle3D(To<CSSIdentifierValue>(value).ConvertTo<blink::ETransformStyle3D>());
}

// transition-behavior

const char* TransitionBehavior::GetPropertyName() const
{
    return "transition-behavior";
}

const WTF::AtomicString& TransitionBehavior::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("transition-behavior"));
    return name;
}

const char* TransitionBehavior::GetJSPropertyName() const
{
    return "transitionBehavior";
}

void TransitionBehavior::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Transitions())
        return;
    CSSTransitionData& data = state.StyleBuilder().AccessTransitions();
    data.BehaviorList().clear();
    data.BehaviorList().push_back(CSSTransitionData::InitialBehavior());
}

void TransitionBehavior::ApplyInherit(StyleResolverState& state) const
{
    const CSSTransitionData* parent_data = state.ParentStyle()->Transitions();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessTransitions().BehaviorList() = parent_data->BehaviorList();
}

void TransitionBehavior::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSTransitionData& data = state.StyleBuilder().AccessTransitions();
    data.BehaviorList().clear();
    data.BehaviorList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.BehaviorList().push_back(CSSToStyleMap::MapAnimationBehavior(state, item));
    }
}

// transition-delay

const char* TransitionDelay::GetPropertyName() const
{
    return "transition-delay";
}

const WTF::AtomicString& TransitionDelay::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("transition-delay"));
    return name;
}

const char* TransitionDelay::GetJSPropertyName() const
{
    return "transitionDelay";
}

void TransitionDelay::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Transitions())
        return;
    CSSTransitionData& data = state.StyleBuilder().AccessTransitions();
    data.DelayStartList().clear();
    data.DelayStartList().push_back(CSSTransitionData::InitialDelayStart());
}

void TransitionDelay::ApplyInherit(StyleResolverState& state) const
{
    const CSSTransitionData* parent_data = state.ParentStyle()->Transitions();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessTransitions().DelayStartList() = parent_data->DelayStartList();
}

void TransitionDelay::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSTransitionData& data = state.StyleBuilder().AccessTransitions();
    data.DelayStartList().clear();
    data.DelayStartList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.DelayStartList().push_back(CSSToStyleMap::MapAnimationDelayStart(state, item));
    }
}

// transition-duration

const char* TransitionDuration::GetPropertyName() const
{
    return "transition-duration";
}

const WTF::AtomicString& TransitionDuration::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("transition-duration"));
    return name;
}

const char* TransitionDuration::GetJSPropertyName() const
{
    return "transitionDuration";
}

void TransitionDuration::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Transitions())
        return;
    CSSTransitionData& data = state.StyleBuilder().AccessTransitions();
    data.DurationList().clear();
    data.DurationList().push_back(CSSTransitionData::InitialDuration());
}

void TransitionDuration::ApplyInherit(StyleResolverState& state) const
{
    const CSSTransitionData* parent_data = state.ParentStyle()->Transitions();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessTransitions().DurationList() = parent_data->DurationList();
}

void TransitionDuration::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSTransitionData& data = state.StyleBuilder().AccessTransitions();
    data.DurationList().clear();
    data.DurationList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.DurationList().push_back(CSSToStyleMap::MapAnimationDuration(state, item));
    }
}

// transition-property

const char* TransitionProperty::GetPropertyName() const
{
    return "transition-property";
}

const WTF::AtomicString& TransitionProperty::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("transition-property"));
    return name;
}

const char* TransitionProperty::GetJSPropertyName() const
{
    return "transitionProperty";
}

void TransitionProperty::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Transitions())
        return;
    CSSTransitionData& data = state.StyleBuilder().AccessTransitions();
    data.PropertyList().clear();
    data.PropertyList().push_back(CSSTransitionData::InitialProperty());
}

void TransitionProperty::ApplyInherit(StyleResolverState& state) const
{
    const CSSTransitionData* parent_data = state.ParentStyle()->Transitions();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessTransitions().PropertyList() = parent_data->PropertyList();
}

void TransitionProperty::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSTransitionData& data = state.StyleBuilder().AccessTransitions();
    data.PropertyList().clear();
    data.PropertyList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.PropertyList().push_back(CSSToStyleMap::MapAnimationProperty(state, item));
    }
}

// transition-timing-function

const char* TransitionTimingFunction::GetPropertyName() const
{
    return "transition-timing-function";
}

const WTF::AtomicString& TransitionTimingFunction::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("transition-timing-function"));
    return name;
}

const char* TransitionTimingFunction::GetJSPropertyName() const
{
    return "transitionTimingFunction";
}

void TransitionTimingFunction::ApplyInitial(StyleResolverState& state) const
{
    if (!state.StyleBuilder().Transitions())
        return;
    CSSTransitionData& data = state.StyleBuilder().AccessTransitions();
    data.TimingFunctionList().clear();
    data.TimingFunctionList().push_back(CSSTransitionData::InitialTimingFunction());
}

void TransitionTimingFunction::ApplyInherit(StyleResolverState& state) const
{
    const CSSTransitionData* parent_data = state.ParentStyle()->Transitions();
    if (!parent_data)
        ApplyInitial(state);
    else
        state.StyleBuilder().AccessTransitions().TimingFunctionList() = parent_data->TimingFunctionList();
}

void TransitionTimingFunction::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    const CSSValueList& list = To<CSSValueList>(value);
    CSSTransitionData& data = state.StyleBuilder().AccessTransitions();
    data.TimingFunctionList().clear();
    data.TimingFunctionList().reserve(list.length());
    for (const CSSValue* list_value : list) {
        const auto& item = *list_value;
        data.TimingFunctionList().push_back(CSSToStyleMap::MapAnimationTimingFunction(state, item));
    }
}

// translate

const char* Translate::GetPropertyName() const
{
    return "translate";
}

const WTF::AtomicString& Translate::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("translate"));
    return name;
}

const char* Translate::GetJSPropertyName() const
{
    return "translate";
}

void Translate::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTranslate(ComputedStyleInitialValues::InitialTranslate());
}
void Translate::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTranslate(state.ParentStyle()->Translate());
}
void Translate::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTranslate(StyleBuilderConverter::ConvertTranslate(state, value));
}

// types

CSSExposure Types::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::ViewTransitionOnNavigationEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* Types::GetPropertyName() const
{
    return "types";
}

const WTF::AtomicString& Types::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("types"));
    return name;
}

const char* Types::GetJSPropertyName() const
{
    return "types";
}

// unicode-bidi

const char* UnicodeBidi::GetPropertyName() const
{
    return "unicode-bidi";
}

const WTF::AtomicString& UnicodeBidi::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("unicode-bidi"));
    return name;
}

const char* UnicodeBidi::GetJSPropertyName() const
{
    return "unicodeBidi";
}

void UnicodeBidi::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetUnicodeBidi(ComputedStyleInitialValues::InitialUnicodeBidi());
}
void UnicodeBidi::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetUnicodeBidi(state.ParentStyle()->GetUnicodeBidi());
}
void UnicodeBidi::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetUnicodeBidi(To<CSSIdentifierValue>(value).ConvertTo<blink::UnicodeBidi>());
}

// unicode-range

const char* UnicodeRange::GetPropertyName() const
{
    return "unicode-range";
}

const WTF::AtomicString& UnicodeRange::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("unicode-range"));
    return name;
}

const char* UnicodeRange::GetJSPropertyName() const
{
    return "unicodeRange";
}

// user-select

const char* UserSelect::GetPropertyName() const
{
    return "user-select";
}

const WTF::AtomicString& UserSelect::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("user-select"));
    return name;
}

const char* UserSelect::GetJSPropertyName() const
{
    return "userSelect";
}

void UserSelect::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetUserSelect(ComputedStyleInitialValues::InitialUserSelect());
}
void UserSelect::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetUserSelect(state.ParentStyle()->UserSelect());
}
void UserSelect::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetUserSelect(To<CSSIdentifierValue>(value).ConvertTo<blink::EUserSelect>());
}

// vector-effect

const char* VectorEffect::GetPropertyName() const
{
    return "vector-effect";
}

const WTF::AtomicString& VectorEffect::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("vector-effect"));
    return name;
}

const char* VectorEffect::GetJSPropertyName() const
{
    return "vectorEffect";
}

void VectorEffect::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetVectorEffect(ComputedStyleInitialValues::InitialVectorEffect());
}
void VectorEffect::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetVectorEffect(state.ParentStyle()->VectorEffect());
}
void VectorEffect::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetVectorEffect(To<CSSIdentifierValue>(value).ConvertTo<blink::EVectorEffect>());
}

// vertical-align

const char* VerticalAlign::GetPropertyName() const
{
    return "vertical-align";
}

const WTF::AtomicString& VerticalAlign::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("vertical-align"));
    return name;
}

const char* VerticalAlign::GetJSPropertyName() const
{
    return "verticalAlign";
}

void VerticalAlign::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetVerticalAlign(ComputedStyleInitialValues::InitialVerticalAlign());
}

// view-timeline-axis

CSSExposure ViewTimelineAxis::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::ScrollTimelineEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ViewTimelineAxis::GetPropertyName() const
{
    return "view-timeline-axis";
}

const WTF::AtomicString& ViewTimelineAxis::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("view-timeline-axis"));
    return name;
}

const char* ViewTimelineAxis::GetJSPropertyName() const
{
    return "viewTimelineAxis";
}

void ViewTimelineAxis::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetViewTimelineAxis(ComputedStyleInitialValues::InitialViewTimelineAxis());
}
void ViewTimelineAxis::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetViewTimelineAxis(state.ParentStyle()->ViewTimelineAxis());
}
void ViewTimelineAxis::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetViewTimelineAxis(StyleBuilderConverter::ConvertViewTimelineAxis(state, value));
}

// view-timeline-inset

CSSExposure ViewTimelineInset::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::ScrollTimelineEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ViewTimelineInset::GetPropertyName() const
{
    return "view-timeline-inset";
}

const WTF::AtomicString& ViewTimelineInset::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("view-timeline-inset"));
    return name;
}

const char* ViewTimelineInset::GetJSPropertyName() const
{
    return "viewTimelineInset";
}

void ViewTimelineInset::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetViewTimelineInset(ComputedStyleInitialValues::InitialViewTimelineInset());
}
void ViewTimelineInset::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetViewTimelineInset(state.ParentStyle()->ViewTimelineInset());
}
void ViewTimelineInset::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetViewTimelineInset(StyleBuilderConverter::ConvertViewTimelineInset(state, value));
}

// view-timeline-name

CSSExposure ViewTimelineName::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::ScrollTimelineEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ViewTimelineName::GetPropertyName() const
{
    return "view-timeline-name";
}

const WTF::AtomicString& ViewTimelineName::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("view-timeline-name"));
    return name;
}

const char* ViewTimelineName::GetJSPropertyName() const
{
    return "viewTimelineName";
}

void ViewTimelineName::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetViewTimelineName(ComputedStyleInitialValues::InitialViewTimelineName());
}
void ViewTimelineName::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetViewTimelineName(state.ParentStyle()->ViewTimelineName());
}
void ViewTimelineName::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetViewTimelineName(StyleBuilderConverter::ConvertViewTimelineName(state, value));
}

// view-transition-capture-mode

CSSExposure ViewTransitionCaptureMode::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::ViewTransitionLayeredCaptureEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ViewTransitionCaptureMode::GetPropertyName() const
{
    return "view-transition-capture-mode";
}

const WTF::AtomicString& ViewTransitionCaptureMode::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("view-transition-capture-mode"));
    return name;
}

const char* ViewTransitionCaptureMode::GetJSPropertyName() const
{
    return "viewTransitionCaptureMode";
}

void ViewTransitionCaptureMode::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetViewTransitionCaptureMode(ComputedStyleInitialValues::InitialViewTransitionCaptureMode());
}
void ViewTransitionCaptureMode::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetViewTransitionCaptureMode(state.ParentStyle()->ViewTransitionCaptureMode());
}
void ViewTransitionCaptureMode::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetViewTransitionCaptureMode(StyleBuilderConverter::ConvertViewTransitionCaptureMode(state, value));
}

// view-transition-class

CSSExposure ViewTransitionClass::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::CSSViewTransitionClassEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ViewTransitionClass::GetPropertyName() const
{
    return "view-transition-class";
}

const WTF::AtomicString& ViewTransitionClass::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("view-transition-class"));
    return name;
}

const char* ViewTransitionClass::GetJSPropertyName() const
{
    return "viewTransitionClass";
}

void ViewTransitionClass::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetViewTransitionClass(ComputedStyleInitialValues::InitialViewTransitionClass());
}
void ViewTransitionClass::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetViewTransitionClass(state.ParentStyle()->ViewTransitionClass());
}
void ViewTransitionClass::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetViewTransitionClass(StyleBuilderConverter::ConvertViewTransitionClass(state, value));
}

// view-transition-group

CSSExposure ViewTransitionGroup::Exposure(const ExecutionContext* execution_context) const
{
    if (!RuntimeEnabledFeatures::NestedViewTransitionEnabled(execution_context)) {
        return CSSExposure::kNone;
    }
    return CSSExposure::kWeb;
}

const char* ViewTransitionGroup::GetPropertyName() const
{
    return "view-transition-group";
}

const WTF::AtomicString& ViewTransitionGroup::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("view-transition-group"));
    return name;
}

const char* ViewTransitionGroup::GetJSPropertyName() const
{
    return "viewTransitionGroup";
}

void ViewTransitionGroup::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetViewTransitionGroup(ComputedStyleInitialValues::InitialViewTransitionGroup());
}
void ViewTransitionGroup::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetViewTransitionGroup(state.ParentStyle()->ViewTransitionGroup());
}
void ViewTransitionGroup::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetViewTransitionGroup(StyleBuilderConverter::ConvertViewTransitionGroup(state, value));
}

// view-transition-name

const char* ViewTransitionName::GetPropertyName() const
{
    return "view-transition-name";
}

const WTF::AtomicString& ViewTransitionName::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("view-transition-name"));
    return name;
}

const char* ViewTransitionName::GetJSPropertyName() const
{
    return "viewTransitionName";
}

void ViewTransitionName::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetViewTransitionName(ComputedStyleInitialValues::InitialViewTransitionName());
}
void ViewTransitionName::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetViewTransitionName(state.ParentStyle()->ViewTransitionName());
}
void ViewTransitionName::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetViewTransitionName(StyleBuilderConverter::ConvertViewTransitionName(state, value));
}

// visibility

const char* Visibility::GetPropertyName() const
{
    return "visibility";
}

const WTF::AtomicString& Visibility::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("visibility"));
    return name;
}

const char* Visibility::GetJSPropertyName() const
{
    return "visibility";
}

void Visibility::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetVisibility(ComputedStyleInitialValues::InitialVisibility());
    state.StyleBuilder().SetVisibilityIsInherited(false);
}
void Visibility::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetVisibility(state.ParentStyle()->Visibility());
    state.StyleBuilder().SetVisibilityIsInherited(true);
}
void Visibility::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetVisibility(To<CSSIdentifierValue>(value).ConvertTo<blink::EVisibility>());
    state.StyleBuilder().SetVisibilityIsInherited(false);
}

// -webkit-border-horizontal-spacing

const char* WebkitBorderHorizontalSpacing::GetPropertyName() const
{
    return "-webkit-border-horizontal-spacing";
}

const WTF::AtomicString& WebkitBorderHorizontalSpacing::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-horizontal-spacing"));
    return name;
}

const char* WebkitBorderHorizontalSpacing::GetJSPropertyName() const
{
    return "webkitBorderHorizontalSpacing";
}

void WebkitBorderHorizontalSpacing::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetHorizontalBorderSpacing(ComputedStyleInitialValues::InitialHorizontalBorderSpacing());
}
void WebkitBorderHorizontalSpacing::ApplyInherit(StyleResolverState& state) const
{
    if (state.GetDocument().StandardizedBrowserZoomEnabled()) {
        if (ApplyParentValueIfZoomChanged(state)) {
            return;
        }
    }
    state.StyleBuilder().SetHorizontalBorderSpacing(state.ParentStyle()->HorizontalBorderSpacing());
}
void WebkitBorderHorizontalSpacing::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetHorizontalBorderSpacing(StyleBuilderConverter::ConvertComputedLength<short>(state, value));
}

// -webkit-border-image

const char* WebkitBorderImage::GetPropertyName() const
{
    return "-webkit-border-image";
}

const WTF::AtomicString& WebkitBorderImage::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-image"));
    return name;
}

const char* WebkitBorderImage::GetJSPropertyName() const
{
    return "webkitBorderImage";
}

void WebkitBorderImage::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderImage(ComputedStyleInitialValues::InitialBorderImage());
}
void WebkitBorderImage::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBorderImage(state.ParentStyle()->BorderImage());
}

// -webkit-border-vertical-spacing

const char* WebkitBorderVerticalSpacing::GetPropertyName() const
{
    return "-webkit-border-vertical-spacing";
}

const WTF::AtomicString& WebkitBorderVerticalSpacing::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-vertical-spacing"));
    return name;
}

const char* WebkitBorderVerticalSpacing::GetJSPropertyName() const
{
    return "webkitBorderVerticalSpacing";
}

void WebkitBorderVerticalSpacing::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetVerticalBorderSpacing(ComputedStyleInitialValues::InitialVerticalBorderSpacing());
}
void WebkitBorderVerticalSpacing::ApplyInherit(StyleResolverState& state) const
{
    if (state.GetDocument().StandardizedBrowserZoomEnabled()) {
        if (ApplyParentValueIfZoomChanged(state)) {
            return;
        }
    }
    state.StyleBuilder().SetVerticalBorderSpacing(state.ParentStyle()->VerticalBorderSpacing());
}
void WebkitBorderVerticalSpacing::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetVerticalBorderSpacing(StyleBuilderConverter::ConvertComputedLength<short>(state, value));
}

// -webkit-box-align

const char* WebkitBoxAlign::GetPropertyName() const
{
    return "-webkit-box-align";
}

const WTF::AtomicString& WebkitBoxAlign::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-align"));
    return name;
}

const char* WebkitBoxAlign::GetJSPropertyName() const
{
    return "webkitBoxAlign";
}

void WebkitBoxAlign::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxAlign(ComputedStyleInitialValues::InitialBoxAlign());
}
void WebkitBoxAlign::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxAlign(state.ParentStyle()->BoxAlign());
}
void WebkitBoxAlign::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBoxAlign(To<CSSIdentifierValue>(value).ConvertTo<blink::EBoxAlignment>());
}

// -webkit-box-decoration-break

const char* WebkitBoxDecorationBreak::GetPropertyName() const
{
    return "-webkit-box-decoration-break";
}

const WTF::AtomicString& WebkitBoxDecorationBreak::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-decoration-break"));
    return name;
}

const char* WebkitBoxDecorationBreak::GetJSPropertyName() const
{
    return "webkitBoxDecorationBreak";
}

const CSSProperty* WebkitBoxDecorationBreak::SurrogateFor(WritingDirectionMode) const
{
    return &GetCSSPropertyBoxDecorationBreak();
}

// -webkit-box-direction

const char* WebkitBoxDirection::GetPropertyName() const
{
    return "-webkit-box-direction";
}

const WTF::AtomicString& WebkitBoxDirection::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-direction"));
    return name;
}

const char* WebkitBoxDirection::GetJSPropertyName() const
{
    return "webkitBoxDirection";
}

void WebkitBoxDirection::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxDirection(ComputedStyleInitialValues::InitialBoxDirection());
}
void WebkitBoxDirection::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxDirection(state.ParentStyle()->BoxDirection());
}
void WebkitBoxDirection::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBoxDirection(To<CSSIdentifierValue>(value).ConvertTo<blink::EBoxDirection>());
}

// -webkit-box-flex

const char* WebkitBoxFlex::GetPropertyName() const
{
    return "-webkit-box-flex";
}

const WTF::AtomicString& WebkitBoxFlex::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-flex"));
    return name;
}

const char* WebkitBoxFlex::GetJSPropertyName() const
{
    return "webkitBoxFlex";
}

void WebkitBoxFlex::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxFlex(ComputedStyleInitialValues::InitialBoxFlex());
}
void WebkitBoxFlex::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxFlex(state.ParentStyle()->BoxFlex());
}
void WebkitBoxFlex::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBoxFlex(To<CSSPrimitiveValue>(value).ConvertTo<float>(state.CssToLengthConversionData()));
}

// -webkit-box-ordinal-group

const char* WebkitBoxOrdinalGroup::GetPropertyName() const
{
    return "-webkit-box-ordinal-group";
}

const WTF::AtomicString& WebkitBoxOrdinalGroup::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-ordinal-group"));
    return name;
}

const char* WebkitBoxOrdinalGroup::GetJSPropertyName() const
{
    return "webkitBoxOrdinalGroup";
}

void WebkitBoxOrdinalGroup::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxOrdinalGroup(ComputedStyleInitialValues::InitialBoxOrdinalGroup());
}
void WebkitBoxOrdinalGroup::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxOrdinalGroup(state.ParentStyle()->BoxOrdinalGroup());
}
void WebkitBoxOrdinalGroup::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBoxOrdinalGroup(To<CSSPrimitiveValue>(value).ConvertTo<unsigned>(state.CssToLengthConversionData()));
}

// -webkit-box-orient

const char* WebkitBoxOrient::GetPropertyName() const
{
    return "-webkit-box-orient";
}

const WTF::AtomicString& WebkitBoxOrient::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-orient"));
    return name;
}

const char* WebkitBoxOrient::GetJSPropertyName() const
{
    return "webkitBoxOrient";
}

void WebkitBoxOrient::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxOrient(ComputedStyleInitialValues::InitialBoxOrient());
}
void WebkitBoxOrient::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxOrient(state.ParentStyle()->BoxOrient());
}
void WebkitBoxOrient::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBoxOrient(To<CSSIdentifierValue>(value).ConvertTo<blink::EBoxOrient>());
}

// -webkit-box-pack

const char* WebkitBoxPack::GetPropertyName() const
{
    return "-webkit-box-pack";
}

const WTF::AtomicString& WebkitBoxPack::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-pack"));
    return name;
}

const char* WebkitBoxPack::GetJSPropertyName() const
{
    return "webkitBoxPack";
}

void WebkitBoxPack::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxPack(ComputedStyleInitialValues::InitialBoxPack());
}
void WebkitBoxPack::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxPack(state.ParentStyle()->BoxPack());
}
void WebkitBoxPack::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBoxPack(To<CSSIdentifierValue>(value).ConvertTo<blink::EBoxPack>());
}

// -webkit-box-reflect

const char* WebkitBoxReflect::GetPropertyName() const
{
    return "-webkit-box-reflect";
}

const WTF::AtomicString& WebkitBoxReflect::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-reflect"));
    return name;
}

const char* WebkitBoxReflect::GetJSPropertyName() const
{
    return "webkitBoxReflect";
}

void WebkitBoxReflect::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxReflect(ComputedStyleInitialValues::InitialBoxReflect());
}
void WebkitBoxReflect::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetBoxReflect(state.ParentStyle()->BoxReflect());
}
void WebkitBoxReflect::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetBoxReflect(StyleBuilderConverter::ConvertBoxReflect(state, value));
}

// -webkit-line-break

const char* WebkitLineBreak::GetPropertyName() const
{
    return "-webkit-line-break";
}

const WTF::AtomicString& WebkitLineBreak::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-line-break"));
    return name;
}

const char* WebkitLineBreak::GetJSPropertyName() const
{
    return "webkitLineBreak";
}

void WebkitLineBreak::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetLineBreak(ComputedStyleInitialValues::InitialLineBreak());
}
void WebkitLineBreak::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetLineBreak(state.ParentStyle()->GetLineBreak());
}
void WebkitLineBreak::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetLineBreak(To<CSSIdentifierValue>(value).ConvertTo<blink::LineBreak>());
}

// -webkit-line-clamp

const char* WebkitLineClamp::GetPropertyName() const
{
    return "-webkit-line-clamp";
}

const WTF::AtomicString& WebkitLineClamp::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-line-clamp"));
    return name;
}

const char* WebkitLineClamp::GetJSPropertyName() const
{
    return "webkitLineClamp";
}

void WebkitLineClamp::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetWebkitLineClamp(ComputedStyleInitialValues::InitialWebkitLineClamp());
}
void WebkitLineClamp::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetWebkitLineClamp(state.ParentStyle()->WebkitLineClamp());
}
void WebkitLineClamp::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetWebkitLineClamp(StyleBuilderConverter::ConvertIntegerOrNone<0>(state, value));
}

// -webkit-mask-box-image-outset

const char* WebkitMaskBoxImageOutset::GetPropertyName() const
{
    return "-webkit-mask-box-image-outset";
}

const WTF::AtomicString& WebkitMaskBoxImageOutset::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-box-image-outset"));
    return name;
}

const char* WebkitMaskBoxImageOutset::GetJSPropertyName() const
{
    return "webkitMaskBoxImageOutset";
}

void WebkitMaskBoxImageOutset::ApplyInitial(StyleResolverState& state) const
{
    const NinePieceImage& current_image = state.StyleBuilder().MaskBoxImage();
    if (style_building_utils::BorderImageLengthMatchesAllSides(current_image.Outset(), BorderImageLength(0)))
        return;
    NinePieceImage image(current_image);
    image.SetOutset(0);
    state.StyleBuilder().SetMaskBoxImage(image);
}
void WebkitMaskBoxImageOutset::ApplyInherit(StyleResolverState& state) const
{
    NinePieceImage image(state.StyleBuilder().MaskBoxImage());
    image.CopyOutsetFrom(state.ParentStyle()->MaskBoxImage());
    state.StyleBuilder().SetMaskBoxImage(image);
}
void WebkitMaskBoxImageOutset::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    NinePieceImage image(state.StyleBuilder().MaskBoxImage());
    image.SetOutset(CSSToStyleMap::MapNinePieceImageQuad(state, value));
    state.StyleBuilder().SetMaskBoxImage(image);
}

// -webkit-mask-box-image-repeat

const char* WebkitMaskBoxImageRepeat::GetPropertyName() const
{
    return "-webkit-mask-box-image-repeat";
}

const WTF::AtomicString& WebkitMaskBoxImageRepeat::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-box-image-repeat"));
    return name;
}

const char* WebkitMaskBoxImageRepeat::GetJSPropertyName() const
{
    return "webkitMaskBoxImageRepeat";
}

void WebkitMaskBoxImageRepeat::ApplyInitial(StyleResolverState& state) const
{
    const NinePieceImage& current_image = state.StyleBuilder().MaskBoxImage();
    if (current_image.HorizontalRule() == kStretchImageRule && current_image.VerticalRule() == kStretchImageRule)
        return;
    NinePieceImage image(current_image);
    image.SetHorizontalRule(kStretchImageRule);
    image.SetVerticalRule(kStretchImageRule);
    state.StyleBuilder().SetMaskBoxImage(image);
}
void WebkitMaskBoxImageRepeat::ApplyInherit(StyleResolverState& state) const
{
    NinePieceImage image(state.StyleBuilder().MaskBoxImage());
    image.CopyRepeatFrom(state.ParentStyle()->MaskBoxImage());
    state.StyleBuilder().SetMaskBoxImage(image);
}
void WebkitMaskBoxImageRepeat::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    NinePieceImage image(state.StyleBuilder().MaskBoxImage());
    CSSToStyleMap::MapNinePieceImageRepeat(state, value, image);
    state.StyleBuilder().SetMaskBoxImage(image);
}

// -webkit-mask-box-image-slice

const char* WebkitMaskBoxImageSlice::GetPropertyName() const
{
    return "-webkit-mask-box-image-slice";
}

const WTF::AtomicString& WebkitMaskBoxImageSlice::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-box-image-slice"));
    return name;
}

const char* WebkitMaskBoxImageSlice::GetJSPropertyName() const
{
    return "webkitMaskBoxImageSlice";
}

void WebkitMaskBoxImageSlice::ApplyInitial(StyleResolverState& state) const
{
    const NinePieceImage& current_image = state.StyleBuilder().MaskBoxImage();
    // Masks have a different initial value for slices. Preserve the value of 0
    // for backwards compatibility.
    if (current_image.Fill() == true && style_building_utils::LengthMatchesAllSides(current_image.ImageSlices(), Length::Fixed(0)))
        return;
    NinePieceImage image(current_image);
    image.SetImageSlices(LengthBox(Length::Fixed(0), Length::Fixed(0), Length::Fixed(0), Length::Fixed(0)));
    image.SetFill(true);
    state.StyleBuilder().SetMaskBoxImage(image);
}
void WebkitMaskBoxImageSlice::ApplyInherit(StyleResolverState& state) const
{
    NinePieceImage image(state.StyleBuilder().MaskBoxImage());
    image.CopyImageSlicesFrom(state.ParentStyle()->MaskBoxImage());
    state.StyleBuilder().SetMaskBoxImage(image);
}
void WebkitMaskBoxImageSlice::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    NinePieceImage image(state.StyleBuilder().MaskBoxImage());
    CSSToStyleMap::MapNinePieceImageSlice(state, value, image);
    state.StyleBuilder().SetMaskBoxImage(image);
}

// -webkit-mask-box-image-source

const char* WebkitMaskBoxImageSource::GetPropertyName() const
{
    return "-webkit-mask-box-image-source";
}

const WTF::AtomicString& WebkitMaskBoxImageSource::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-box-image-source"));
    return name;
}

const char* WebkitMaskBoxImageSource::GetJSPropertyName() const
{
    return "webkitMaskBoxImageSource";
}

void WebkitMaskBoxImageSource::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetMaskBoxImageSource(ComputedStyleInitialValues::InitialMaskBoxImageSource());
}
void WebkitMaskBoxImageSource::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetMaskBoxImageSource(state.ParentStyle()->MaskBoxImageSource());
}

// -webkit-mask-box-image-width

const char* WebkitMaskBoxImageWidth::GetPropertyName() const
{
    return "-webkit-mask-box-image-width";
}

const WTF::AtomicString& WebkitMaskBoxImageWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-box-image-width"));
    return name;
}

const char* WebkitMaskBoxImageWidth::GetJSPropertyName() const
{
    return "webkitMaskBoxImageWidth";
}

void WebkitMaskBoxImageWidth::ApplyInitial(StyleResolverState& state) const
{
    const NinePieceImage& current_image = state.StyleBuilder().MaskBoxImage();
    // Masks have a different initial value for widths. Preserve the value of
    // 'auto' for backwards compatibility.
    if (style_building_utils::BorderImageLengthMatchesAllSides(current_image.BorderSlices(), BorderImageLength(Length::Auto())))
        return;
    NinePieceImage image(current_image);
    image.SetBorderSlices(Length::Auto());
    state.StyleBuilder().SetMaskBoxImage(image);
}
void WebkitMaskBoxImageWidth::ApplyInherit(StyleResolverState& state) const
{
    NinePieceImage image(state.StyleBuilder().MaskBoxImage());
    image.CopyBorderSlicesFrom(state.ParentStyle()->MaskBoxImage());
    state.StyleBuilder().SetMaskBoxImage(image);
}
void WebkitMaskBoxImageWidth::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    NinePieceImage image(state.StyleBuilder().MaskBoxImage());
    image.SetBorderSlices(CSSToStyleMap::MapNinePieceImageQuad(state, value));
    state.StyleBuilder().SetMaskBoxImage(image);
}

// -webkit-mask-position-x

const char* WebkitMaskPositionX::GetPropertyName() const
{
    return "-webkit-mask-position-x";
}

const WTF::AtomicString& WebkitMaskPositionX::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-position-x"));
    return name;
}

const char* WebkitMaskPositionX::GetJSPropertyName() const
{
    return "webkitMaskPositionX";
}

void WebkitMaskPositionX::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    curr_child->SetPositionX(FillLayer::InitialFillPositionX(EFillLayerType::kMask));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearPositionX();
}

void WebkitMaskPositionX::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
    while (curr_parent && curr_parent->IsPositionXSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetPositionX(curr_parent->PositionX());
        if (curr_parent->IsBackgroundXOriginSet())
            curr_child->SetBackgroundXOrigin(curr_parent->BackgroundXOrigin());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearPositionX();
        curr_child = curr_child->Next();
    }
}

void WebkitMaskPositionX::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillPositionX(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillPositionX(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearPositionX();
        curr_child = curr_child->Next();
    }
}

// -webkit-mask-position-y

const char* WebkitMaskPositionY::GetPropertyName() const
{
    return "-webkit-mask-position-y";
}

const WTF::AtomicString& WebkitMaskPositionY::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-position-y"));
    return name;
}

const char* WebkitMaskPositionY::GetJSPropertyName() const
{
    return "webkitMaskPositionY";
}

void WebkitMaskPositionY::ApplyInitial(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    curr_child->SetPositionY(FillLayer::InitialFillPositionY(EFillLayerType::kMask));
    for (curr_child = curr_child->Next(); curr_child; curr_child = curr_child->Next())
        curr_child->ClearPositionY();
}

void WebkitMaskPositionY::ApplyInherit(StyleResolverState& state) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const FillLayer* curr_parent = &state.ParentStyle()->MaskLayers();
    while (curr_parent && curr_parent->IsPositionYSet()) {
        if (!curr_child)
            curr_child = prev_child->EnsureNext();
        curr_child->SetPositionY(curr_parent->PositionY());
        if (curr_parent->IsBackgroundYOriginSet())
            curr_child->SetBackgroundYOrigin(curr_parent->BackgroundYOrigin());
        prev_child = curr_child;
        curr_child = prev_child->Next();
        curr_parent = curr_parent->Next();
    }

    while (curr_child) {
        // Reset any remaining layers to not have the property set.
        curr_child->ClearPositionY();
        curr_child = curr_child->Next();
    }
}

void WebkitMaskPositionY::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    FillLayer* curr_child = &state.StyleBuilder().AccessMaskLayers();
    FillLayer* prev_child = 0;
    const auto* value_list = DynamicTo<CSSValueList>(value);
    if (value_list && !value.IsImageSetValue()) {
        // Walk each value and put it into a layer, creating new layers as needed.
        for (unsigned int i = 0; i < value_list->length(); i++) {
            if (!curr_child)
                curr_child = prev_child->EnsureNext();
            CSSToStyleMap::MapFillPositionY(state, curr_child, value_list->Item(i));
            prev_child = curr_child;
            curr_child = curr_child->Next();
        }
    } else {
        CSSToStyleMap::MapFillPositionY(state, curr_child, value);
        curr_child = curr_child->Next();
    }
    while (curr_child) {
        // Reset all remaining layers to not have the property set.
        curr_child->ClearPositionY();
        curr_child = curr_child->Next();
    }
}

// -webkit-perspective-origin-x

const char* WebkitPerspectiveOriginX::GetPropertyName() const
{
    return "-webkit-perspective-origin-x";
}

const WTF::AtomicString& WebkitPerspectiveOriginX::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-perspective-origin-x"));
    return name;
}

const char* WebkitPerspectiveOriginX::GetJSPropertyName() const
{
    return "webkitPerspectiveOriginX";
}

void WebkitPerspectiveOriginX::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPerspectiveOriginX(ComputedStyleInitialValues::InitialPerspectiveOriginX());
}
void WebkitPerspectiveOriginX::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPerspectiveOriginX(StyleBuilderConverter::ConvertLength(state, value));
}

// -webkit-perspective-origin-y

const char* WebkitPerspectiveOriginY::GetPropertyName() const
{
    return "-webkit-perspective-origin-y";
}

const WTF::AtomicString& WebkitPerspectiveOriginY::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-perspective-origin-y"));
    return name;
}

const char* WebkitPerspectiveOriginY::GetJSPropertyName() const
{
    return "webkitPerspectiveOriginY";
}

void WebkitPerspectiveOriginY::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPerspectiveOriginY(ComputedStyleInitialValues::InitialPerspectiveOriginY());
}
void WebkitPerspectiveOriginY::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPerspectiveOriginY(StyleBuilderConverter::ConvertLength(state, value));
}

// -webkit-print-color-adjust

const char* WebkitPrintColorAdjust::GetPropertyName() const
{
    return "-webkit-print-color-adjust";
}

const WTF::AtomicString& WebkitPrintColorAdjust::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-print-color-adjust"));
    return name;
}

const char* WebkitPrintColorAdjust::GetJSPropertyName() const
{
    return "webkitPrintColorAdjust";
}

void WebkitPrintColorAdjust::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetPrintColorAdjust(ComputedStyleInitialValues::InitialPrintColorAdjust());
}
void WebkitPrintColorAdjust::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetPrintColorAdjust(state.ParentStyle()->PrintColorAdjust());
}
void WebkitPrintColorAdjust::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetPrintColorAdjust(To<CSSIdentifierValue>(value).ConvertTo<blink::EPrintColorAdjust>());
}

// -webkit-rtl-ordering

const char* WebkitRtlOrdering::GetPropertyName() const
{
    return "-webkit-rtl-ordering";
}

const WTF::AtomicString& WebkitRtlOrdering::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-rtl-ordering"));
    return name;
}

const char* WebkitRtlOrdering::GetJSPropertyName() const
{
    return "webkitRtlOrdering";
}

void WebkitRtlOrdering::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetRtlOrdering(ComputedStyleInitialValues::InitialRtlOrdering());
    state.StyleBuilder().SetRtlOrderingIsInherited(false);
}
void WebkitRtlOrdering::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetRtlOrdering(state.ParentStyle()->RtlOrdering());
    state.StyleBuilder().SetRtlOrderingIsInherited(true);
}
void WebkitRtlOrdering::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetRtlOrdering(To<CSSIdentifierValue>(value).ConvertTo<blink::EOrder>());
    state.StyleBuilder().SetRtlOrderingIsInherited(false);
}

// -webkit-ruby-position

const char* WebkitRubyPosition::GetPropertyName() const
{
    return "-webkit-ruby-position";
}

const WTF::AtomicString& WebkitRubyPosition::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-ruby-position"));
    return name;
}

const char* WebkitRubyPosition::GetJSPropertyName() const
{
    return "webkitRubyPosition";
}

const CSSProperty* WebkitRubyPosition::SurrogateFor(WritingDirectionMode) const
{
    return &GetCSSPropertyRubyPosition();
}

// -webkit-tap-highlight-color

const char* WebkitTapHighlightColor::GetPropertyName() const
{
    return "-webkit-tap-highlight-color";
}

const WTF::AtomicString& WebkitTapHighlightColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-tap-highlight-color"));
    return name;
}

const char* WebkitTapHighlightColor::GetJSPropertyName() const
{
    return "webkitTapHighlightColor";
}

void WebkitTapHighlightColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTapHighlightColor(ComputedStyleInitialValues::InitialTapHighlightColor());
}
void WebkitTapHighlightColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTapHighlightColor(state.ParentStyle()->TapHighlightColor());
}
void WebkitTapHighlightColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTapHighlightColor(StyleBuilderConverter::ConvertStyleColor(state, value));
}

// -webkit-text-combine

const char* WebkitTextCombine::GetPropertyName() const
{
    return "-webkit-text-combine";
}

const WTF::AtomicString& WebkitTextCombine::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-combine"));
    return name;
}

const char* WebkitTextCombine::GetJSPropertyName() const
{
    return "webkitTextCombine";
}

const CSSProperty* WebkitTextCombine::SurrogateFor(WritingDirectionMode) const
{
    return &GetCSSPropertyTextCombineUpright();
}

// -webkit-text-decorations-in-effect

const char* WebkitTextDecorationsInEffect::GetPropertyName() const
{
    return "-webkit-text-decorations-in-effect";
}

const WTF::AtomicString& WebkitTextDecorationsInEffect::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-decorations-in-effect"));
    return name;
}

const char* WebkitTextDecorationsInEffect::GetJSPropertyName() const
{
    return "webkitTextDecorationsInEffect";
}

void WebkitTextDecorationsInEffect::ApplyInitial(StyleResolverState& state) const
{
    // Intentionally empty.
}
void WebkitTextDecorationsInEffect::ApplyInherit(StyleResolverState& state) const
{
    // Intentionally empty.
}
void WebkitTextDecorationsInEffect::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    // Intentionally empty.
}

// -webkit-text-fill-color

const char* WebkitTextFillColor::GetPropertyName() const
{
    return "-webkit-text-fill-color";
}

const WTF::AtomicString& WebkitTextFillColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-fill-color"));
    return name;
}

const char* WebkitTextFillColor::GetJSPropertyName() const
{
    return "webkitTextFillColor";
}

void WebkitTextFillColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextFillColor(StyleColor::CurrentColor());
}

void WebkitTextFillColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextFillColor(state.ParentStyle()->TextFillColor());
}

void WebkitTextFillColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextFillColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// -webkit-text-security

const char* WebkitTextSecurity::GetPropertyName() const
{
    return "-webkit-text-security";
}

const WTF::AtomicString& WebkitTextSecurity::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-security"));
    return name;
}

const char* WebkitTextSecurity::GetJSPropertyName() const
{
    return "webkitTextSecurity";
}

void WebkitTextSecurity::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextSecurity(ComputedStyleInitialValues::InitialTextSecurity());
}
void WebkitTextSecurity::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextSecurity(state.ParentStyle()->TextSecurity());
}
void WebkitTextSecurity::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextSecurity(To<CSSIdentifierValue>(value).ConvertTo<blink::ETextSecurity>());
}

// -webkit-text-stroke-color

const char* WebkitTextStrokeColor::GetPropertyName() const
{
    return "-webkit-text-stroke-color";
}

const WTF::AtomicString& WebkitTextStrokeColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-stroke-color"));
    return name;
}

const char* WebkitTextStrokeColor::GetJSPropertyName() const
{
    return "webkitTextStrokeColor";
}

void WebkitTextStrokeColor::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextStrokeColor(StyleColor::CurrentColor());
}

void WebkitTextStrokeColor::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextStrokeColor(state.ParentStyle()->TextStrokeColor());
}

void WebkitTextStrokeColor::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextStrokeColor(StyleBuilderConverter::ConvertStyleColor(state, value, false));
}

// -webkit-text-stroke-width

const char* WebkitTextStrokeWidth::GetPropertyName() const
{
    return "-webkit-text-stroke-width";
}

const WTF::AtomicString& WebkitTextStrokeWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-stroke-width"));
    return name;
}

const char* WebkitTextStrokeWidth::GetJSPropertyName() const
{
    return "webkitTextStrokeWidth";
}

void WebkitTextStrokeWidth::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTextStrokeWidth(ComputedStyleInitialValues::InitialTextStrokeWidth());
}
void WebkitTextStrokeWidth::ApplyInherit(StyleResolverState& state) const
{
    if (state.GetDocument().StandardizedBrowserZoomEnabled()) {
        if (ApplyParentValueIfZoomChanged(state)) {
            return;
        }
    }
    state.StyleBuilder().SetTextStrokeWidth(state.ParentStyle()->TextStrokeWidth());
}
void WebkitTextStrokeWidth::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTextStrokeWidth(StyleBuilderConverter::ConvertTextStrokeWidth(state, value));
}

// -webkit-transform-origin-x

const char* WebkitTransformOriginX::GetPropertyName() const
{
    return "-webkit-transform-origin-x";
}

const WTF::AtomicString& WebkitTransformOriginX::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transform-origin-x"));
    return name;
}

const char* WebkitTransformOriginX::GetJSPropertyName() const
{
    return "webkitTransformOriginX";
}

void WebkitTransformOriginX::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTransformOriginX(ComputedStyleInitialValues::InitialTransformOriginX());
}
void WebkitTransformOriginX::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTransformOriginX(StyleBuilderConverter::ConvertLength(state, value));
}

// -webkit-transform-origin-y

const char* WebkitTransformOriginY::GetPropertyName() const
{
    return "-webkit-transform-origin-y";
}

const WTF::AtomicString& WebkitTransformOriginY::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transform-origin-y"));
    return name;
}

const char* WebkitTransformOriginY::GetJSPropertyName() const
{
    return "webkitTransformOriginY";
}

void WebkitTransformOriginY::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTransformOriginY(ComputedStyleInitialValues::InitialTransformOriginY());
}
void WebkitTransformOriginY::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTransformOriginY(StyleBuilderConverter::ConvertLength(state, value));
}

// -webkit-transform-origin-z

const char* WebkitTransformOriginZ::GetPropertyName() const
{
    return "-webkit-transform-origin-z";
}

const WTF::AtomicString& WebkitTransformOriginZ::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transform-origin-z"));
    return name;
}

const char* WebkitTransformOriginZ::GetJSPropertyName() const
{
    return "webkitTransformOriginZ";
}

void WebkitTransformOriginZ::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetTransformOriginZ(ComputedStyleInitialValues::InitialTransformOriginZ());
}
void WebkitTransformOriginZ::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetTransformOriginZ(StyleBuilderConverter::ConvertComputedLength<float>(state, value));
}

// -webkit-user-drag

const char* WebkitUserDrag::GetPropertyName() const
{
    return "-webkit-user-drag";
}

const WTF::AtomicString& WebkitUserDrag::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-user-drag"));
    return name;
}

const char* WebkitUserDrag::GetJSPropertyName() const
{
    return "webkitUserDrag";
}

void WebkitUserDrag::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetUserDrag(ComputedStyleInitialValues::InitialUserDrag());
}
void WebkitUserDrag::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetUserDrag(state.ParentStyle()->UserDrag());
}
void WebkitUserDrag::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetUserDrag(To<CSSIdentifierValue>(value).ConvertTo<blink::EUserDrag>());
}

// -webkit-user-modify

const char* WebkitUserModify::GetPropertyName() const
{
    return "-webkit-user-modify";
}

const WTF::AtomicString& WebkitUserModify::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-user-modify"));
    return name;
}

const char* WebkitUserModify::GetJSPropertyName() const
{
    return "webkitUserModify";
}

void WebkitUserModify::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetUserModify(ComputedStyleInitialValues::InitialUserModify());
}
void WebkitUserModify::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetUserModify(state.ParentStyle()->UserModify());
}
void WebkitUserModify::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetUserModify(To<CSSIdentifierValue>(value).ConvertTo<blink::EUserModify>());
}

// white-space-collapse

const char* WhiteSpaceCollapse::GetPropertyName() const
{
    return "white-space-collapse";
}

const WTF::AtomicString& WhiteSpaceCollapse::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("white-space-collapse"));
    return name;
}

const char* WhiteSpaceCollapse::GetJSPropertyName() const
{
    return "whiteSpaceCollapse";
}

void WhiteSpaceCollapse::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetWhiteSpaceCollapse(ComputedStyleInitialValues::InitialWhiteSpaceCollapse());
}
void WhiteSpaceCollapse::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetWhiteSpaceCollapse(state.ParentStyle()->GetWhiteSpaceCollapse());
}
void WhiteSpaceCollapse::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetWhiteSpaceCollapse(To<CSSIdentifierValue>(value).ConvertTo<blink::WhiteSpaceCollapse>());
}

// widows

const char* Widows::GetPropertyName() const
{
    return "widows";
}

const WTF::AtomicString& Widows::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("widows"));
    return name;
}

const char* Widows::GetJSPropertyName() const
{
    return "widows";
}

void Widows::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetWidows(ComputedStyleInitialValues::InitialWidows());
}
void Widows::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetWidows(state.ParentStyle()->Widows());
}
void Widows::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetWidows(To<CSSPrimitiveValue>(value).ConvertTo<short>(state.CssToLengthConversionData()));
}

// width

const char* Width::GetPropertyName() const
{
    return "width";
}

const WTF::AtomicString& Width::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("width"));
    return name;
}

const char* Width::GetJSPropertyName() const
{
    return "width";
}

bool Width::IsInSameLogicalPropertyGroupWithDifferentMappingLogic(CSSPropertyID id) const
{
    return CSSDirectionAwareResolver::LogicalSizeMapping().Contains(id);
}

void Width::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetWidth(ComputedStyleInitialValues::InitialWidth());
}
void Width::ApplyInherit(StyleResolverState& state) const
{
    if (state.GetDocument().StandardizedBrowserZoomEnabled()) {
        if (ApplyParentValueIfZoomChanged(state)) {
            return;
        }
    }
    state.StyleBuilder().SetWidth(state.ParentStyle()->Width());
}
void Width::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    blink::AnchorScope anchor_scope(blink::AnchorScope::Mode::kWidth, state.CssToLengthConversionData().GetAnchorEvaluator());
    state.StyleBuilder().SetWidth(StyleBuilderConverter::ConvertLengthSizing(state, value));
}

// will-change

const char* WillChange::GetPropertyName() const
{
    return "will-change";
}

const WTF::AtomicString& WillChange::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("will-change"));
    return name;
}

const char* WillChange::GetJSPropertyName() const
{
    return "willChange";
}

// word-break

const char* WordBreak::GetPropertyName() const
{
    return "word-break";
}

const WTF::AtomicString& WordBreak::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("word-break"));
    return name;
}

const char* WordBreak::GetJSPropertyName() const
{
    return "wordBreak";
}

void WordBreak::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetWordBreak(ComputedStyleInitialValues::InitialWordBreak());
}
void WordBreak::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetWordBreak(state.ParentStyle()->WordBreak());
}

// word-spacing

const char* WordSpacing::GetPropertyName() const
{
    return "word-spacing";
}

const WTF::AtomicString& WordSpacing::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("word-spacing"));
    return name;
}

const char* WordSpacing::GetJSPropertyName() const
{
    return "wordSpacing";
}

void WordSpacing::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetWordSpacing(ComputedStyleInitialValues::InitialWordSpacing());
}
void WordSpacing::ApplyInherit(StyleResolverState& state) const
{
    if (state.GetDocument().StandardizedBrowserZoomEnabled()) {
        if (ApplyParentValueIfZoomChanged(state)) {
            return;
        }
    }
    state.StyleBuilder().SetWordSpacing(state.ParentStyle()->WordSpacing());
}
void WordSpacing::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetWordSpacing(StyleBuilderConverter::ConvertSpacing(state, value));
}

// x

const char* X::GetPropertyName() const
{
    return "x";
}

const WTF::AtomicString& X::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("x"));
    return name;
}

const char* X::GetJSPropertyName() const
{
    return "x";
}

void X::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetX(ComputedStyleInitialValues::InitialX());
}
void X::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetX(state.ParentStyle()->X());
}
void X::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetX(StyleBuilderConverter::ConvertLength(state, value));
}

// y

const char* Y::GetPropertyName() const
{
    return "y";
}

const WTF::AtomicString& Y::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("y"));
    return name;
}

const char* Y::GetJSPropertyName() const
{
    return "y";
}

void Y::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetY(ComputedStyleInitialValues::InitialY());
}
void Y::ApplyInherit(StyleResolverState& state) const
{
    state.StyleBuilder().SetY(state.ParentStyle()->Y());
}
void Y::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    state.StyleBuilder().SetY(StyleBuilderConverter::ConvertLength(state, value));
}

// z-index

const char* ZIndex::GetPropertyName() const
{
    return "z-index";
}

const WTF::AtomicString& ZIndex::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("z-index"));
    return name;
}

const char* ZIndex::GetJSPropertyName() const
{
    return "zIndex";
}

void ZIndex::ApplyInitial(StyleResolverState& state) const
{
    state.StyleBuilder().SetHasAutoZIndex();
}
void ZIndex::ApplyInherit(StyleResolverState& state) const
{
    if (state.ParentStyle()->HasAutoZIndex())
        state.StyleBuilder().SetHasAutoZIndex();
    else
        state.StyleBuilder().SetZIndex(state.ParentStyle()->ZIndex());
}
void ZIndex::ApplyValue(StyleResolverState& state, const CSSValue& value, ValueMode) const
{
    auto* identifier_value = DynamicTo<CSSIdentifierValue>(value);
    if (identifier_value && identifier_value->GetValueID() == CSSValueID::kAuto)
        state.StyleBuilder().SetHasAutoZIndex();
    else
        state.StyleBuilder().SetZIndex(StyleBuilderConverter::ConvertInteger(state, value));
}

// -webkit-appearance

const char* WebkitAppearance::GetPropertyName() const
{
    return "-webkit-appearance";
}

const WTF::AtomicString& WebkitAppearance::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-appearance"));
    return name;
}

const char* WebkitAppearance::GetJSPropertyName() const
{
    return "webkitAppearance";
}

// -webkit-app-region

const char* WebkitAppRegion::GetPropertyName() const
{
    return "-webkit-app-region";
}

const WTF::AtomicString& WebkitAppRegion::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-app-region"));
    return name;
}

const char* WebkitAppRegion::GetJSPropertyName() const
{
    return "webkitAppRegion";
}

// -webkit-mask-clip

const char* WebkitMaskClip::GetPropertyName() const
{
    return "-webkit-mask-clip";
}

const WTF::AtomicString& WebkitMaskClip::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-clip"));
    return name;
}

const char* WebkitMaskClip::GetJSPropertyName() const
{
    return "webkitMaskClip";
}

// -webkit-mask-composite

const char* WebkitMaskComposite::GetPropertyName() const
{
    return "-webkit-mask-composite";
}

const WTF::AtomicString& WebkitMaskComposite::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-composite"));
    return name;
}

const char* WebkitMaskComposite::GetJSPropertyName() const
{
    return "webkitMaskComposite";
}

// -webkit-mask-image

const char* WebkitMaskImage::GetPropertyName() const
{
    return "-webkit-mask-image";
}

const WTF::AtomicString& WebkitMaskImage::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-image"));
    return name;
}

const char* WebkitMaskImage::GetJSPropertyName() const
{
    return "webkitMaskImage";
}

// -webkit-mask-origin

const char* WebkitMaskOrigin::GetPropertyName() const
{
    return "-webkit-mask-origin";
}

const WTF::AtomicString& WebkitMaskOrigin::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-origin"));
    return name;
}

const char* WebkitMaskOrigin::GetJSPropertyName() const
{
    return "webkitMaskOrigin";
}

// -webkit-mask-repeat

const char* WebkitMaskRepeat::GetPropertyName() const
{
    return "-webkit-mask-repeat";
}

const WTF::AtomicString& WebkitMaskRepeat::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-repeat"));
    return name;
}

const char* WebkitMaskRepeat::GetJSPropertyName() const
{
    return "webkitMaskRepeat";
}

// -webkit-mask-size

const char* WebkitMaskSize::GetPropertyName() const
{
    return "-webkit-mask-size";
}

const WTF::AtomicString& WebkitMaskSize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-mask-size"));
    return name;
}

const char* WebkitMaskSize::GetJSPropertyName() const
{
    return "webkitMaskSize";
}

// -webkit-border-end-color

const char* WebkitBorderEndColor::GetPropertyName() const
{
    return "-webkit-border-end-color";
}

const WTF::AtomicString& WebkitBorderEndColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-end-color"));
    return name;
}

const char* WebkitBorderEndColor::GetJSPropertyName() const
{
    return "webkitBorderEndColor";
}

// -webkit-border-end-style

const char* WebkitBorderEndStyle::GetPropertyName() const
{
    return "-webkit-border-end-style";
}

const WTF::AtomicString& WebkitBorderEndStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-end-style"));
    return name;
}

const char* WebkitBorderEndStyle::GetJSPropertyName() const
{
    return "webkitBorderEndStyle";
}

// -webkit-border-end-width

const char* WebkitBorderEndWidth::GetPropertyName() const
{
    return "-webkit-border-end-width";
}

const WTF::AtomicString& WebkitBorderEndWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-end-width"));
    return name;
}

const char* WebkitBorderEndWidth::GetJSPropertyName() const
{
    return "webkitBorderEndWidth";
}

// -webkit-border-start-color

const char* WebkitBorderStartColor::GetPropertyName() const
{
    return "-webkit-border-start-color";
}

const WTF::AtomicString& WebkitBorderStartColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-start-color"));
    return name;
}

const char* WebkitBorderStartColor::GetJSPropertyName() const
{
    return "webkitBorderStartColor";
}

// -webkit-border-start-style

const char* WebkitBorderStartStyle::GetPropertyName() const
{
    return "-webkit-border-start-style";
}

const WTF::AtomicString& WebkitBorderStartStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-start-style"));
    return name;
}

const char* WebkitBorderStartStyle::GetJSPropertyName() const
{
    return "webkitBorderStartStyle";
}

// -webkit-border-start-width

const char* WebkitBorderStartWidth::GetPropertyName() const
{
    return "-webkit-border-start-width";
}

const WTF::AtomicString& WebkitBorderStartWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-start-width"));
    return name;
}

const char* WebkitBorderStartWidth::GetJSPropertyName() const
{
    return "webkitBorderStartWidth";
}

// -webkit-border-before-color

const char* WebkitBorderBeforeColor::GetPropertyName() const
{
    return "-webkit-border-before-color";
}

const WTF::AtomicString& WebkitBorderBeforeColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-before-color"));
    return name;
}

const char* WebkitBorderBeforeColor::GetJSPropertyName() const
{
    return "webkitBorderBeforeColor";
}

// -webkit-border-before-style

const char* WebkitBorderBeforeStyle::GetPropertyName() const
{
    return "-webkit-border-before-style";
}

const WTF::AtomicString& WebkitBorderBeforeStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-before-style"));
    return name;
}

const char* WebkitBorderBeforeStyle::GetJSPropertyName() const
{
    return "webkitBorderBeforeStyle";
}

// -webkit-border-before-width

const char* WebkitBorderBeforeWidth::GetPropertyName() const
{
    return "-webkit-border-before-width";
}

const WTF::AtomicString& WebkitBorderBeforeWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-before-width"));
    return name;
}

const char* WebkitBorderBeforeWidth::GetJSPropertyName() const
{
    return "webkitBorderBeforeWidth";
}

// -webkit-border-after-color

const char* WebkitBorderAfterColor::GetPropertyName() const
{
    return "-webkit-border-after-color";
}

const WTF::AtomicString& WebkitBorderAfterColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-after-color"));
    return name;
}

const char* WebkitBorderAfterColor::GetJSPropertyName() const
{
    return "webkitBorderAfterColor";
}

// -webkit-border-after-style

const char* WebkitBorderAfterStyle::GetPropertyName() const
{
    return "-webkit-border-after-style";
}

const WTF::AtomicString& WebkitBorderAfterStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-after-style"));
    return name;
}

const char* WebkitBorderAfterStyle::GetJSPropertyName() const
{
    return "webkitBorderAfterStyle";
}

// -webkit-border-after-width

const char* WebkitBorderAfterWidth::GetPropertyName() const
{
    return "-webkit-border-after-width";
}

const WTF::AtomicString& WebkitBorderAfterWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-after-width"));
    return name;
}

const char* WebkitBorderAfterWidth::GetJSPropertyName() const
{
    return "webkitBorderAfterWidth";
}

// -webkit-margin-end

const char* WebkitMarginEnd::GetPropertyName() const
{
    return "-webkit-margin-end";
}

const WTF::AtomicString& WebkitMarginEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-margin-end"));
    return name;
}

const char* WebkitMarginEnd::GetJSPropertyName() const
{
    return "webkitMarginEnd";
}

// -webkit-margin-start

const char* WebkitMarginStart::GetPropertyName() const
{
    return "-webkit-margin-start";
}

const WTF::AtomicString& WebkitMarginStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-margin-start"));
    return name;
}

const char* WebkitMarginStart::GetJSPropertyName() const
{
    return "webkitMarginStart";
}

// -webkit-margin-before

const char* WebkitMarginBefore::GetPropertyName() const
{
    return "-webkit-margin-before";
}

const WTF::AtomicString& WebkitMarginBefore::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-margin-before"));
    return name;
}

const char* WebkitMarginBefore::GetJSPropertyName() const
{
    return "webkitMarginBefore";
}

// -webkit-margin-after

const char* WebkitMarginAfter::GetPropertyName() const
{
    return "-webkit-margin-after";
}

const WTF::AtomicString& WebkitMarginAfter::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-margin-after"));
    return name;
}

const char* WebkitMarginAfter::GetJSPropertyName() const
{
    return "webkitMarginAfter";
}

// -webkit-padding-end

const char* WebkitPaddingEnd::GetPropertyName() const
{
    return "-webkit-padding-end";
}

const WTF::AtomicString& WebkitPaddingEnd::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-padding-end"));
    return name;
}

const char* WebkitPaddingEnd::GetJSPropertyName() const
{
    return "webkitPaddingEnd";
}

// -webkit-padding-start

const char* WebkitPaddingStart::GetPropertyName() const
{
    return "-webkit-padding-start";
}

const WTF::AtomicString& WebkitPaddingStart::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-padding-start"));
    return name;
}

const char* WebkitPaddingStart::GetJSPropertyName() const
{
    return "webkitPaddingStart";
}

// -webkit-padding-before

const char* WebkitPaddingBefore::GetPropertyName() const
{
    return "-webkit-padding-before";
}

const WTF::AtomicString& WebkitPaddingBefore::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-padding-before"));
    return name;
}

const char* WebkitPaddingBefore::GetJSPropertyName() const
{
    return "webkitPaddingBefore";
}

// -webkit-padding-after

const char* WebkitPaddingAfter::GetPropertyName() const
{
    return "-webkit-padding-after";
}

const WTF::AtomicString& WebkitPaddingAfter::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-padding-after"));
    return name;
}

const char* WebkitPaddingAfter::GetJSPropertyName() const
{
    return "webkitPaddingAfter";
}

// -webkit-logical-width

const char* WebkitLogicalWidth::GetPropertyName() const
{
    return "-webkit-logical-width";
}

const WTF::AtomicString& WebkitLogicalWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-logical-width"));
    return name;
}

const char* WebkitLogicalWidth::GetJSPropertyName() const
{
    return "webkitLogicalWidth";
}

// -webkit-logical-height

const char* WebkitLogicalHeight::GetPropertyName() const
{
    return "-webkit-logical-height";
}

const WTF::AtomicString& WebkitLogicalHeight::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-logical-height"));
    return name;
}

const char* WebkitLogicalHeight::GetJSPropertyName() const
{
    return "webkitLogicalHeight";
}

// -webkit-min-logical-width

const char* WebkitMinLogicalWidth::GetPropertyName() const
{
    return "-webkit-min-logical-width";
}

const WTF::AtomicString& WebkitMinLogicalWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-min-logical-width"));
    return name;
}

const char* WebkitMinLogicalWidth::GetJSPropertyName() const
{
    return "webkitMinLogicalWidth";
}

// -webkit-min-logical-height

const char* WebkitMinLogicalHeight::GetPropertyName() const
{
    return "-webkit-min-logical-height";
}

const WTF::AtomicString& WebkitMinLogicalHeight::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-min-logical-height"));
    return name;
}

const char* WebkitMinLogicalHeight::GetJSPropertyName() const
{
    return "webkitMinLogicalHeight";
}

// -webkit-max-logical-width

const char* WebkitMaxLogicalWidth::GetPropertyName() const
{
    return "-webkit-max-logical-width";
}

const WTF::AtomicString& WebkitMaxLogicalWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-max-logical-width"));
    return name;
}

const char* WebkitMaxLogicalWidth::GetJSPropertyName() const
{
    return "webkitMaxLogicalWidth";
}

// -webkit-max-logical-height

const char* WebkitMaxLogicalHeight::GetPropertyName() const
{
    return "-webkit-max-logical-height";
}

const WTF::AtomicString& WebkitMaxLogicalHeight::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-max-logical-height"));
    return name;
}

const char* WebkitMaxLogicalHeight::GetJSPropertyName() const
{
    return "webkitMaxLogicalHeight";
}

// -epub-caption-side

const char* EpubCaptionSide::GetPropertyName() const
{
    return "-epub-caption-side";
}

const WTF::AtomicString& EpubCaptionSide::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-caption-side"));
    return name;
}

const char* EpubCaptionSide::GetJSPropertyName() const
{
    return "epubCaptionSide";
}

// -epub-text-combine

const char* EpubTextCombine::GetPropertyName() const
{
    return "-epub-text-combine";
}

const WTF::AtomicString& EpubTextCombine::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-text-combine"));
    return name;
}

const char* EpubTextCombine::GetJSPropertyName() const
{
    return "epubTextCombine";
}

// -epub-text-emphasis-color

const char* EpubTextEmphasisColor::GetPropertyName() const
{
    return "-epub-text-emphasis-color";
}

const WTF::AtomicString& EpubTextEmphasisColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-text-emphasis-color"));
    return name;
}

const char* EpubTextEmphasisColor::GetJSPropertyName() const
{
    return "epubTextEmphasisColor";
}

// -epub-text-emphasis-style

const char* EpubTextEmphasisStyle::GetPropertyName() const
{
    return "-epub-text-emphasis-style";
}

const WTF::AtomicString& EpubTextEmphasisStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-text-emphasis-style"));
    return name;
}

const char* EpubTextEmphasisStyle::GetJSPropertyName() const
{
    return "epubTextEmphasisStyle";
}

// -epub-text-orientation

const char* EpubTextOrientation::GetPropertyName() const
{
    return "-epub-text-orientation";
}

const WTF::AtomicString& EpubTextOrientation::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-text-orientation"));
    return name;
}

const char* EpubTextOrientation::GetJSPropertyName() const
{
    return "epubTextOrientation";
}

// -epub-text-transform

const char* EpubTextTransform::GetPropertyName() const
{
    return "-epub-text-transform";
}

const WTF::AtomicString& EpubTextTransform::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-text-transform"));
    return name;
}

const char* EpubTextTransform::GetJSPropertyName() const
{
    return "epubTextTransform";
}

// -epub-word-break

const char* EpubWordBreak::GetPropertyName() const
{
    return "-epub-word-break";
}

const WTF::AtomicString& EpubWordBreak::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-word-break"));
    return name;
}

const char* EpubWordBreak::GetJSPropertyName() const
{
    return "epubWordBreak";
}

// -epub-writing-mode

const char* EpubWritingMode::GetPropertyName() const
{
    return "-epub-writing-mode";
}

const WTF::AtomicString& EpubWritingMode::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-epub-writing-mode"));
    return name;
}

const char* EpubWritingMode::GetJSPropertyName() const
{
    return "epubWritingMode";
}

// -webkit-align-content

const char* WebkitAlignContent::GetPropertyName() const
{
    return "-webkit-align-content";
}

const WTF::AtomicString& WebkitAlignContent::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-align-content"));
    return name;
}

const char* WebkitAlignContent::GetJSPropertyName() const
{
    return "webkitAlignContent";
}

// -webkit-align-items

const char* WebkitAlignItems::GetPropertyName() const
{
    return "-webkit-align-items";
}

const WTF::AtomicString& WebkitAlignItems::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-align-items"));
    return name;
}

const char* WebkitAlignItems::GetJSPropertyName() const
{
    return "webkitAlignItems";
}

// -webkit-align-self

const char* WebkitAlignSelf::GetPropertyName() const
{
    return "-webkit-align-self";
}

const WTF::AtomicString& WebkitAlignSelf::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-align-self"));
    return name;
}

const char* WebkitAlignSelf::GetJSPropertyName() const
{
    return "webkitAlignSelf";
}

// -webkit-animation-delay

const char* WebkitAnimationDelay::GetPropertyName() const
{
    return "-webkit-animation-delay";
}

const WTF::AtomicString& WebkitAnimationDelay::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-delay"));
    return name;
}

const char* WebkitAnimationDelay::GetJSPropertyName() const
{
    return "webkitAnimationDelay";
}

// -webkit-animation-direction

const char* WebkitAnimationDirection::GetPropertyName() const
{
    return "-webkit-animation-direction";
}

const WTF::AtomicString& WebkitAnimationDirection::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-direction"));
    return name;
}

const char* WebkitAnimationDirection::GetJSPropertyName() const
{
    return "webkitAnimationDirection";
}

// -webkit-animation-duration

const char* WebkitAnimationDuration::GetPropertyName() const
{
    return "-webkit-animation-duration";
}

const WTF::AtomicString& WebkitAnimationDuration::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-duration"));
    return name;
}

const char* WebkitAnimationDuration::GetJSPropertyName() const
{
    return "webkitAnimationDuration";
}

// -webkit-animation-fill-mode

const char* WebkitAnimationFillMode::GetPropertyName() const
{
    return "-webkit-animation-fill-mode";
}

const WTF::AtomicString& WebkitAnimationFillMode::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-fill-mode"));
    return name;
}

const char* WebkitAnimationFillMode::GetJSPropertyName() const
{
    return "webkitAnimationFillMode";
}

// -webkit-animation-iteration-count

const char* WebkitAnimationIterationCount::GetPropertyName() const
{
    return "-webkit-animation-iteration-count";
}

const WTF::AtomicString& WebkitAnimationIterationCount::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-iteration-count"));
    return name;
}

const char* WebkitAnimationIterationCount::GetJSPropertyName() const
{
    return "webkitAnimationIterationCount";
}

// -webkit-animation-name

const char* WebkitAnimationName::GetPropertyName() const
{
    return "-webkit-animation-name";
}

const WTF::AtomicString& WebkitAnimationName::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-name"));
    return name;
}

const char* WebkitAnimationName::GetJSPropertyName() const
{
    return "webkitAnimationName";
}

// -webkit-animation-play-state

const char* WebkitAnimationPlayState::GetPropertyName() const
{
    return "-webkit-animation-play-state";
}

const WTF::AtomicString& WebkitAnimationPlayState::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-play-state"));
    return name;
}

const char* WebkitAnimationPlayState::GetJSPropertyName() const
{
    return "webkitAnimationPlayState";
}

// -webkit-animation-timing-function

const char* WebkitAnimationTimingFunction::GetPropertyName() const
{
    return "-webkit-animation-timing-function";
}

const WTF::AtomicString& WebkitAnimationTimingFunction::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-animation-timing-function"));
    return name;
}

const char* WebkitAnimationTimingFunction::GetJSPropertyName() const
{
    return "webkitAnimationTimingFunction";
}

// -webkit-backface-visibility

const char* WebkitBackfaceVisibility::GetPropertyName() const
{
    return "-webkit-backface-visibility";
}

const WTF::AtomicString& WebkitBackfaceVisibility::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-backface-visibility"));
    return name;
}

const char* WebkitBackfaceVisibility::GetJSPropertyName() const
{
    return "webkitBackfaceVisibility";
}

// -webkit-background-clip

const char* WebkitBackgroundClip::GetPropertyName() const
{
    return "-webkit-background-clip";
}

const WTF::AtomicString& WebkitBackgroundClip::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-background-clip"));
    return name;
}

const char* WebkitBackgroundClip::GetJSPropertyName() const
{
    return "webkitBackgroundClip";
}

// -webkit-background-origin

const char* WebkitBackgroundOrigin::GetPropertyName() const
{
    return "-webkit-background-origin";
}

const WTF::AtomicString& WebkitBackgroundOrigin::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-background-origin"));
    return name;
}

const char* WebkitBackgroundOrigin::GetJSPropertyName() const
{
    return "webkitBackgroundOrigin";
}

// -webkit-background-size

const char* WebkitBackgroundSize::GetPropertyName() const
{
    return "-webkit-background-size";
}

const WTF::AtomicString& WebkitBackgroundSize::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-background-size"));
    return name;
}

const char* WebkitBackgroundSize::GetJSPropertyName() const
{
    return "webkitBackgroundSize";
}

// -webkit-border-bottom-left-radius

const char* WebkitBorderBottomLeftRadius::GetPropertyName() const
{
    return "-webkit-border-bottom-left-radius";
}

const WTF::AtomicString& WebkitBorderBottomLeftRadius::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-bottom-left-radius"));
    return name;
}

const char* WebkitBorderBottomLeftRadius::GetJSPropertyName() const
{
    return "webkitBorderBottomLeftRadius";
}

// -webkit-border-bottom-right-radius

const char* WebkitBorderBottomRightRadius::GetPropertyName() const
{
    return "-webkit-border-bottom-right-radius";
}

const WTF::AtomicString& WebkitBorderBottomRightRadius::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-bottom-right-radius"));
    return name;
}

const char* WebkitBorderBottomRightRadius::GetJSPropertyName() const
{
    return "webkitBorderBottomRightRadius";
}

// -webkit-border-top-left-radius

const char* WebkitBorderTopLeftRadius::GetPropertyName() const
{
    return "-webkit-border-top-left-radius";
}

const WTF::AtomicString& WebkitBorderTopLeftRadius::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-top-left-radius"));
    return name;
}

const char* WebkitBorderTopLeftRadius::GetJSPropertyName() const
{
    return "webkitBorderTopLeftRadius";
}

// -webkit-border-top-right-radius

const char* WebkitBorderTopRightRadius::GetPropertyName() const
{
    return "-webkit-border-top-right-radius";
}

const WTF::AtomicString& WebkitBorderTopRightRadius::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-border-top-right-radius"));
    return name;
}

const char* WebkitBorderTopRightRadius::GetJSPropertyName() const
{
    return "webkitBorderTopRightRadius";
}

// -webkit-box-shadow

const char* WebkitBoxShadow::GetPropertyName() const
{
    return "-webkit-box-shadow";
}

const WTF::AtomicString& WebkitBoxShadow::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-shadow"));
    return name;
}

const char* WebkitBoxShadow::GetJSPropertyName() const
{
    return "webkitBoxShadow";
}

// -webkit-box-sizing

const char* WebkitBoxSizing::GetPropertyName() const
{
    return "-webkit-box-sizing";
}

const WTF::AtomicString& WebkitBoxSizing::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-box-sizing"));
    return name;
}

const char* WebkitBoxSizing::GetJSPropertyName() const
{
    return "webkitBoxSizing";
}

// -webkit-clip-path

const char* WebkitClipPath::GetPropertyName() const
{
    return "-webkit-clip-path";
}

const WTF::AtomicString& WebkitClipPath::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-clip-path"));
    return name;
}

const char* WebkitClipPath::GetJSPropertyName() const
{
    return "webkitClipPath";
}

// -webkit-column-count

const char* WebkitColumnCount::GetPropertyName() const
{
    return "-webkit-column-count";
}

const WTF::AtomicString& WebkitColumnCount::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-count"));
    return name;
}

const char* WebkitColumnCount::GetJSPropertyName() const
{
    return "webkitColumnCount";
}

// -webkit-column-gap

const char* WebkitColumnGap::GetPropertyName() const
{
    return "-webkit-column-gap";
}

const WTF::AtomicString& WebkitColumnGap::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-gap"));
    return name;
}

const char* WebkitColumnGap::GetJSPropertyName() const
{
    return "webkitColumnGap";
}

// -webkit-column-rule-color

const char* WebkitColumnRuleColor::GetPropertyName() const
{
    return "-webkit-column-rule-color";
}

const WTF::AtomicString& WebkitColumnRuleColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-rule-color"));
    return name;
}

const char* WebkitColumnRuleColor::GetJSPropertyName() const
{
    return "webkitColumnRuleColor";
}

// -webkit-column-rule-style

const char* WebkitColumnRuleStyle::GetPropertyName() const
{
    return "-webkit-column-rule-style";
}

const WTF::AtomicString& WebkitColumnRuleStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-rule-style"));
    return name;
}

const char* WebkitColumnRuleStyle::GetJSPropertyName() const
{
    return "webkitColumnRuleStyle";
}

// -webkit-column-rule-width

const char* WebkitColumnRuleWidth::GetPropertyName() const
{
    return "-webkit-column-rule-width";
}

const WTF::AtomicString& WebkitColumnRuleWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-rule-width"));
    return name;
}

const char* WebkitColumnRuleWidth::GetJSPropertyName() const
{
    return "webkitColumnRuleWidth";
}

// -webkit-column-span

const char* WebkitColumnSpan::GetPropertyName() const
{
    return "-webkit-column-span";
}

const WTF::AtomicString& WebkitColumnSpan::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-span"));
    return name;
}

const char* WebkitColumnSpan::GetJSPropertyName() const
{
    return "webkitColumnSpan";
}

// -webkit-column-width

const char* WebkitColumnWidth::GetPropertyName() const
{
    return "-webkit-column-width";
}

const WTF::AtomicString& WebkitColumnWidth::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-column-width"));
    return name;
}

const char* WebkitColumnWidth::GetJSPropertyName() const
{
    return "webkitColumnWidth";
}

// -webkit-filter

const char* WebkitFilter::GetPropertyName() const
{
    return "-webkit-filter";
}

const WTF::AtomicString& WebkitFilter::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-filter"));
    return name;
}

const char* WebkitFilter::GetJSPropertyName() const
{
    return "webkitFilter";
}

// -webkit-flex-basis

const char* WebkitFlexBasis::GetPropertyName() const
{
    return "-webkit-flex-basis";
}

const WTF::AtomicString& WebkitFlexBasis::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-flex-basis"));
    return name;
}

const char* WebkitFlexBasis::GetJSPropertyName() const
{
    return "webkitFlexBasis";
}

// -webkit-flex-direction

const char* WebkitFlexDirection::GetPropertyName() const
{
    return "-webkit-flex-direction";
}

const WTF::AtomicString& WebkitFlexDirection::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-flex-direction"));
    return name;
}

const char* WebkitFlexDirection::GetJSPropertyName() const
{
    return "webkitFlexDirection";
}

// -webkit-flex-grow

const char* WebkitFlexGrow::GetPropertyName() const
{
    return "-webkit-flex-grow";
}

const WTF::AtomicString& WebkitFlexGrow::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-flex-grow"));
    return name;
}

const char* WebkitFlexGrow::GetJSPropertyName() const
{
    return "webkitFlexGrow";
}

// -webkit-flex-shrink

const char* WebkitFlexShrink::GetPropertyName() const
{
    return "-webkit-flex-shrink";
}

const WTF::AtomicString& WebkitFlexShrink::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-flex-shrink"));
    return name;
}

const char* WebkitFlexShrink::GetJSPropertyName() const
{
    return "webkitFlexShrink";
}

// -webkit-flex-wrap

const char* WebkitFlexWrap::GetPropertyName() const
{
    return "-webkit-flex-wrap";
}

const WTF::AtomicString& WebkitFlexWrap::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-flex-wrap"));
    return name;
}

const char* WebkitFlexWrap::GetJSPropertyName() const
{
    return "webkitFlexWrap";
}

// -webkit-font-feature-settings

const char* WebkitFontFeatureSettings::GetPropertyName() const
{
    return "-webkit-font-feature-settings";
}

const WTF::AtomicString& WebkitFontFeatureSettings::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-font-feature-settings"));
    return name;
}

const char* WebkitFontFeatureSettings::GetJSPropertyName() const
{
    return "webkitFontFeatureSettings";
}

// -webkit-hyphenate-character

const char* WebkitHyphenateCharacter::GetPropertyName() const
{
    return "-webkit-hyphenate-character";
}

const WTF::AtomicString& WebkitHyphenateCharacter::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-hyphenate-character"));
    return name;
}

const char* WebkitHyphenateCharacter::GetJSPropertyName() const
{
    return "webkitHyphenateCharacter";
}

// -webkit-justify-content

const char* WebkitJustifyContent::GetPropertyName() const
{
    return "-webkit-justify-content";
}

const WTF::AtomicString& WebkitJustifyContent::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-justify-content"));
    return name;
}

const char* WebkitJustifyContent::GetJSPropertyName() const
{
    return "webkitJustifyContent";
}

// -webkit-opacity

const char* WebkitOpacity::GetPropertyName() const
{
    return "-webkit-opacity";
}

const WTF::AtomicString& WebkitOpacity::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-opacity"));
    return name;
}

const char* WebkitOpacity::GetJSPropertyName() const
{
    return "webkitOpacity";
}

// -webkit-order

const char* WebkitOrder::GetPropertyName() const
{
    return "-webkit-order";
}

const WTF::AtomicString& WebkitOrder::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-order"));
    return name;
}

const char* WebkitOrder::GetJSPropertyName() const
{
    return "webkitOrder";
}

// -webkit-perspective

const char* WebkitPerspective::GetPropertyName() const
{
    return "-webkit-perspective";
}

const WTF::AtomicString& WebkitPerspective::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-perspective"));
    return name;
}

const char* WebkitPerspective::GetJSPropertyName() const
{
    return "webkitPerspective";
}

// -webkit-perspective-origin

const char* WebkitPerspectiveOrigin::GetPropertyName() const
{
    return "-webkit-perspective-origin";
}

const WTF::AtomicString& WebkitPerspectiveOrigin::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-perspective-origin"));
    return name;
}

const char* WebkitPerspectiveOrigin::GetJSPropertyName() const
{
    return "webkitPerspectiveOrigin";
}

// -webkit-shape-image-threshold

const char* WebkitShapeImageThreshold::GetPropertyName() const
{
    return "-webkit-shape-image-threshold";
}

const WTF::AtomicString& WebkitShapeImageThreshold::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-shape-image-threshold"));
    return name;
}

const char* WebkitShapeImageThreshold::GetJSPropertyName() const
{
    return "webkitShapeImageThreshold";
}

// -webkit-shape-margin

const char* WebkitShapeMargin::GetPropertyName() const
{
    return "-webkit-shape-margin";
}

const WTF::AtomicString& WebkitShapeMargin::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-shape-margin"));
    return name;
}

const char* WebkitShapeMargin::GetJSPropertyName() const
{
    return "webkitShapeMargin";
}

// -webkit-shape-outside

const char* WebkitShapeOutside::GetPropertyName() const
{
    return "-webkit-shape-outside";
}

const WTF::AtomicString& WebkitShapeOutside::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-shape-outside"));
    return name;
}

const char* WebkitShapeOutside::GetJSPropertyName() const
{
    return "webkitShapeOutside";
}

// -webkit-text-emphasis-color

const char* WebkitTextEmphasisColor::GetPropertyName() const
{
    return "-webkit-text-emphasis-color";
}

const WTF::AtomicString& WebkitTextEmphasisColor::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-emphasis-color"));
    return name;
}

const char* WebkitTextEmphasisColor::GetJSPropertyName() const
{
    return "webkitTextEmphasisColor";
}

// -webkit-text-emphasis-position

const char* WebkitTextEmphasisPosition::GetPropertyName() const
{
    return "-webkit-text-emphasis-position";
}

const WTF::AtomicString& WebkitTextEmphasisPosition::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-emphasis-position"));
    return name;
}

const char* WebkitTextEmphasisPosition::GetJSPropertyName() const
{
    return "webkitTextEmphasisPosition";
}

// -webkit-text-emphasis-style

const char* WebkitTextEmphasisStyle::GetPropertyName() const
{
    return "-webkit-text-emphasis-style";
}

const WTF::AtomicString& WebkitTextEmphasisStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-emphasis-style"));
    return name;
}

const char* WebkitTextEmphasisStyle::GetJSPropertyName() const
{
    return "webkitTextEmphasisStyle";
}

// -webkit-text-size-adjust

const char* WebkitTextSizeAdjust::GetPropertyName() const
{
    return "-webkit-text-size-adjust";
}

const WTF::AtomicString& WebkitTextSizeAdjust::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-text-size-adjust"));
    return name;
}

const char* WebkitTextSizeAdjust::GetJSPropertyName() const
{
    return "webkitTextSizeAdjust";
}

// -webkit-transform

const char* WebkitTransform::GetPropertyName() const
{
    return "-webkit-transform";
}

const WTF::AtomicString& WebkitTransform::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transform"));
    return name;
}

const char* WebkitTransform::GetJSPropertyName() const
{
    return "webkitTransform";
}

// -webkit-transform-origin

const char* WebkitTransformOrigin::GetPropertyName() const
{
    return "-webkit-transform-origin";
}

const WTF::AtomicString& WebkitTransformOrigin::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transform-origin"));
    return name;
}

const char* WebkitTransformOrigin::GetJSPropertyName() const
{
    return "webkitTransformOrigin";
}

// -webkit-transform-style

const char* WebkitTransformStyle::GetPropertyName() const
{
    return "-webkit-transform-style";
}

const WTF::AtomicString& WebkitTransformStyle::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transform-style"));
    return name;
}

const char* WebkitTransformStyle::GetJSPropertyName() const
{
    return "webkitTransformStyle";
}

// -webkit-transition-delay

const char* WebkitTransitionDelay::GetPropertyName() const
{
    return "-webkit-transition-delay";
}

const WTF::AtomicString& WebkitTransitionDelay::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transition-delay"));
    return name;
}

const char* WebkitTransitionDelay::GetJSPropertyName() const
{
    return "webkitTransitionDelay";
}

// -webkit-transition-duration

const char* WebkitTransitionDuration::GetPropertyName() const
{
    return "-webkit-transition-duration";
}

const WTF::AtomicString& WebkitTransitionDuration::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transition-duration"));
    return name;
}

const char* WebkitTransitionDuration::GetJSPropertyName() const
{
    return "webkitTransitionDuration";
}

// -webkit-transition-property

const char* WebkitTransitionProperty::GetPropertyName() const
{
    return "-webkit-transition-property";
}

const WTF::AtomicString& WebkitTransitionProperty::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transition-property"));
    return name;
}

const char* WebkitTransitionProperty::GetJSPropertyName() const
{
    return "webkitTransitionProperty";
}

// -webkit-transition-timing-function

const char* WebkitTransitionTimingFunction::GetPropertyName() const
{
    return "-webkit-transition-timing-function";
}

const WTF::AtomicString& WebkitTransitionTimingFunction::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-transition-timing-function"));
    return name;
}

const char* WebkitTransitionTimingFunction::GetJSPropertyName() const
{
    return "webkitTransitionTimingFunction";
}

// -webkit-user-select

const char* WebkitUserSelect::GetPropertyName() const
{
    return "-webkit-user-select";
}

const WTF::AtomicString& WebkitUserSelect::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("-webkit-user-select"));
    return name;
}

const char* WebkitUserSelect::GetJSPropertyName() const
{
    return "webkitUserSelect";
}

// word-wrap

const char* WordWrap::GetPropertyName() const
{
    return "word-wrap";
}

const WTF::AtomicString& WordWrap::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("word-wrap"));
    return name;
}

const char* WordWrap::GetJSPropertyName() const
{
    return "wordWrap";
}

// grid-column-gap

const char* GridColumnGap::GetPropertyName() const
{
    return "grid-column-gap";
}

const WTF::AtomicString& GridColumnGap::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-column-gap"));
    return name;
}

const char* GridColumnGap::GetJSPropertyName() const
{
    return "gridColumnGap";
}

// grid-row-gap

const char* GridRowGap::GetPropertyName() const
{
    return "grid-row-gap";
}

const WTF::AtomicString& GridRowGap::GetPropertyNameAtomicString() const
{
    DEFINE_STATIC_LOCAL(const AtomicString, name, ("grid-row-gap"));
    return name;
}

const char* GridRowGap::GetJSPropertyName() const
{
    return "gridRowGap";
}

} // namespace css_longhand
} // namespace blink
