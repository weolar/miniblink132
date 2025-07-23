// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/css/properties/templates/css_property_instances.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

// clang-format on

#include "third_party/blink/renderer/core/css/properties/css_property_instances.h"

#include "third_party/blink/renderer/core/css/properties/longhands.h"
#include "third_party/blink/renderer/core/css/properties/longhands/variable.h"
#include "third_party/blink/renderer/core/css/properties/shorthands.h"

namespace blink {

// NOTE: Everything in here must be reinterpret_cast-able
// to CSSUnresolvedProperty! In particular, this means that
// multiple inheritance is forbidden. We enforce this through
// DCHECKs as much as we can; this also checks (compile-time)
// that everything inherits from CSSUnresolvedProperty.
union alignas(kCSSPropertyUnionBytes) CSSPropertyUnion {
    constexpr CSSPropertyUnion()
    {
    } // For kInvalid.
    constexpr CSSPropertyUnion(Variable property)
        : variable_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&variable_));
    }

    constexpr CSSPropertyUnion(::blink::css_longhand::ColorScheme property)
        : csspropertycolorscheme_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycolorscheme_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ForcedColorAdjust property)
        : csspropertyforcedcoloradjust_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyforcedcoloradjust_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MaskImage property)
        : csspropertymaskimage_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymaskimage_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MathDepth property)
        : csspropertymathdepth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymathdepth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Position property)
        : csspropertyposition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyposition_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PositionAnchor property)
        : csspropertypositionanchor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypositionanchor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextSizeAdjust property)
        : csspropertytextsizeadjust_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextsizeadjust_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Appearance property)
        : csspropertyappearance_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyappearance_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Color property)
        : csspropertycolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Direction property)
        : csspropertydirection_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertydirection_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontFamily property)
        : csspropertyfontfamily_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontfamily_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontFeatureSettings property)
        : csspropertyfontfeaturesettings_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontfeaturesettings_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontKerning property)
        : csspropertyfontkerning_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontkerning_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontOpticalSizing property)
        : csspropertyfontopticalsizing_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontopticalsizing_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontPalette property)
        : csspropertyfontpalette_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontpalette_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontSize property)
        : csspropertyfontsize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontsize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontSizeAdjust property)
        : csspropertyfontsizeadjust_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontsizeadjust_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontStretch property)
        : csspropertyfontstretch_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontstretch_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontStyle property)
        : csspropertyfontstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontSynthesisSmallCaps property)
        : csspropertyfontsynthesissmallcaps_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontsynthesissmallcaps_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontSynthesisStyle property)
        : csspropertyfontsynthesisstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontsynthesisstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontSynthesisWeight property)
        : csspropertyfontsynthesisweight_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontsynthesisweight_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontVariantAlternates property)
        : csspropertyfontvariantalternates_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontvariantalternates_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontVariantCaps property)
        : csspropertyfontvariantcaps_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontvariantcaps_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontVariantEastAsian property)
        : csspropertyfontvarianteastasian_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontvarianteastasian_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontVariantEmoji property)
        : csspropertyfontvariantemoji_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontvariantemoji_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontVariantLigatures property)
        : csspropertyfontvariantligatures_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontvariantligatures_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontVariantNumeric property)
        : csspropertyfontvariantnumeric_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontvariantnumeric_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontVariantPosition property)
        : csspropertyfontvariantposition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontvariantposition_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontVariationSettings property)
        : csspropertyfontvariationsettings_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontvariationsettings_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontWeight property)
        : csspropertyfontweight_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontweight_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InsetArea property)
        : csspropertyinsetarea_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinsetarea_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedColor property)
        : csspropertyinternalvisitedcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PositionArea property)
        : csspropertypositionarea_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypositionarea_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextOrientation property)
        : csspropertytextorientation_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextorientation_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextRendering property)
        : csspropertytextrendering_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextrendering_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextSpacingTrim property)
        : csspropertytextspacingtrim_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextspacingtrim_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitFontSmoothing property)
        : csspropertywebkitfontsmoothing_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitfontsmoothing_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitLocale property)
        : csspropertywebkitlocale_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitlocale_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTextOrientation property)
        : csspropertywebkittextorientation_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkittextorientation_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitWritingMode property)
        : csspropertywebkitwritingmode_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitwritingmode_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WritingMode property)
        : csspropertywritingmode_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywritingmode_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Zoom property)
        : csspropertyzoom_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyzoom_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AccentColor property)
        : csspropertyaccentcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaccentcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AdditiveSymbols property)
        : csspropertyadditivesymbols_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyadditivesymbols_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AlignContent property)
        : csspropertyaligncontent_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaligncontent_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AlignItems property)
        : csspropertyalignitems_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyalignitems_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AlignSelf property)
        : csspropertyalignself_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyalignself_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AlignmentBaseline property)
        : csspropertyalignmentbaseline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyalignmentbaseline_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::All property)
        : csspropertyall_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyall_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AnchorName property)
        : csspropertyanchorname_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanchorname_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AnchorScope property)
        : csspropertyanchorscope_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanchorscope_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AnimationComposition property)
        : csspropertyanimationcomposition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanimationcomposition_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AnimationDelay property)
        : csspropertyanimationdelay_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanimationdelay_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AnimationDirection property)
        : csspropertyanimationdirection_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanimationdirection_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AnimationDuration property)
        : csspropertyanimationduration_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanimationduration_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AnimationFillMode property)
        : csspropertyanimationfillmode_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanimationfillmode_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AnimationIterationCount property)
        : csspropertyanimationiterationcount_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanimationiterationcount_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AnimationName property)
        : csspropertyanimationname_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanimationname_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AnimationPlayState property)
        : csspropertyanimationplaystate_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanimationplaystate_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AnimationRangeEnd property)
        : csspropertyanimationrangeend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanimationrangeend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AnimationRangeStart property)
        : csspropertyanimationrangestart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanimationrangestart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AnimationTimeline property)
        : csspropertyanimationtimeline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanimationtimeline_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AnimationTimingFunction property)
        : csspropertyanimationtimingfunction_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanimationtimingfunction_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AppRegion property)
        : csspropertyappregion_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyappregion_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AscentOverride property)
        : csspropertyascentoverride_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyascentoverride_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::AspectRatio property)
        : csspropertyaspectratio_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaspectratio_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BackdropFilter property)
        : csspropertybackdropfilter_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybackdropfilter_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BackfaceVisibility property)
        : csspropertybackfacevisibility_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybackfacevisibility_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BackgroundAttachment property)
        : csspropertybackgroundattachment_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybackgroundattachment_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BackgroundBlendMode property)
        : csspropertybackgroundblendmode_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybackgroundblendmode_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BackgroundClip property)
        : csspropertybackgroundclip_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybackgroundclip_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BackgroundColor property)
        : csspropertybackgroundcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybackgroundcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BackgroundImage property)
        : csspropertybackgroundimage_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybackgroundimage_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BackgroundOrigin property)
        : csspropertybackgroundorigin_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybackgroundorigin_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BackgroundPositionX property)
        : csspropertybackgroundpositionx_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybackgroundpositionx_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BackgroundPositionY property)
        : csspropertybackgroundpositiony_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybackgroundpositiony_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BackgroundRepeat property)
        : csspropertybackgroundrepeat_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybackgroundrepeat_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BackgroundSize property)
        : csspropertybackgroundsize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybackgroundsize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BasePalette property)
        : csspropertybasepalette_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybasepalette_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BaselineShift property)
        : csspropertybaselineshift_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybaselineshift_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BaselineSource property)
        : csspropertybaselinesource_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybaselinesource_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BlockSize property)
        : csspropertyblocksize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyblocksize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderBlockEndColor property)
        : csspropertyborderblockendcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderblockendcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderBlockEndStyle property)
        : csspropertyborderblockendstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderblockendstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderBlockEndWidth property)
        : csspropertyborderblockendwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderblockendwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderBlockStartColor property)
        : csspropertyborderblockstartcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderblockstartcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderBlockStartStyle property)
        : csspropertyborderblockstartstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderblockstartstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderBlockStartWidth property)
        : csspropertyborderblockstartwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderblockstartwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderBottomColor property)
        : csspropertyborderbottomcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderbottomcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderBottomLeftRadius property)
        : csspropertyborderbottomleftradius_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderbottomleftradius_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderBottomRightRadius property)
        : csspropertyborderbottomrightradius_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderbottomrightradius_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderBottomStyle property)
        : csspropertyborderbottomstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderbottomstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderBottomWidth property)
        : csspropertyborderbottomwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderbottomwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderCollapse property)
        : csspropertybordercollapse_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybordercollapse_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderEndEndRadius property)
        : csspropertyborderendendradius_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderendendradius_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderEndStartRadius property)
        : csspropertyborderendstartradius_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderendstartradius_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderImageOutset property)
        : csspropertyborderimageoutset_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderimageoutset_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderImageRepeat property)
        : csspropertyborderimagerepeat_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderimagerepeat_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderImageSlice property)
        : csspropertyborderimageslice_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderimageslice_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderImageSource property)
        : csspropertyborderimagesource_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderimagesource_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderImageWidth property)
        : csspropertyborderimagewidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderimagewidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderInlineEndColor property)
        : csspropertyborderinlineendcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderinlineendcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderInlineEndStyle property)
        : csspropertyborderinlineendstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderinlineendstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderInlineEndWidth property)
        : csspropertyborderinlineendwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderinlineendwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderInlineStartColor property)
        : csspropertyborderinlinestartcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderinlinestartcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderInlineStartStyle property)
        : csspropertyborderinlinestartstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderinlinestartstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderInlineStartWidth property)
        : csspropertyborderinlinestartwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderinlinestartwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderLeftColor property)
        : csspropertyborderleftcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderleftcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderLeftStyle property)
        : csspropertyborderleftstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderleftstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderLeftWidth property)
        : csspropertyborderleftwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderleftwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderRightColor property)
        : csspropertyborderrightcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderrightcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderRightStyle property)
        : csspropertyborderrightstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderrightstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderRightWidth property)
        : csspropertyborderrightwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderrightwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderStartEndRadius property)
        : csspropertyborderstartendradius_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderstartendradius_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderStartStartRadius property)
        : csspropertyborderstartstartradius_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderstartstartradius_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderTopColor property)
        : csspropertybordertopcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybordertopcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderTopLeftRadius property)
        : csspropertybordertopleftradius_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybordertopleftradius_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderTopRightRadius property)
        : csspropertybordertoprightradius_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybordertoprightradius_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderTopStyle property)
        : csspropertybordertopstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybordertopstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BorderTopWidth property)
        : csspropertybordertopwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybordertopwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Bottom property)
        : csspropertybottom_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybottom_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BoxDecorationBreak property)
        : csspropertyboxdecorationbreak_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyboxdecorationbreak_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BoxShadow property)
        : csspropertyboxshadow_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyboxshadow_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BoxSizing property)
        : csspropertyboxsizing_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyboxsizing_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BreakAfter property)
        : csspropertybreakafter_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybreakafter_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BreakBefore property)
        : csspropertybreakbefore_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybreakbefore_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BreakInside property)
        : csspropertybreakinside_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybreakinside_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::BufferedRendering property)
        : csspropertybufferedrendering_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybufferedrendering_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::CaptionSide property)
        : csspropertycaptionside_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycaptionside_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::CaretAnimation property)
        : csspropertycaretanimation_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycaretanimation_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::CaretColor property)
        : csspropertycaretcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycaretcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Clear property)
        : csspropertyclear_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyclear_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Clip property)
        : csspropertyclip_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyclip_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ClipPath property)
        : csspropertyclippath_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyclippath_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ClipRule property)
        : csspropertycliprule_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycliprule_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ColorInterpolation property)
        : csspropertycolorinterpolation_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycolorinterpolation_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ColorInterpolationFilters property)
        : csspropertycolorinterpolationfilters_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycolorinterpolationfilters_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ColorRendering property)
        : csspropertycolorrendering_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycolorrendering_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ColumnCount property)
        : csspropertycolumncount_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycolumncount_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ColumnFill property)
        : csspropertycolumnfill_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycolumnfill_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ColumnGap property)
        : csspropertycolumngap_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycolumngap_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ColumnRuleColor property)
        : csspropertycolumnrulecolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycolumnrulecolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ColumnRuleStyle property)
        : csspropertycolumnrulestyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycolumnrulestyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ColumnRuleWidth property)
        : csspropertycolumnrulewidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycolumnrulewidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ColumnSpan property)
        : csspropertycolumnspan_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycolumnspan_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ColumnWidth property)
        : csspropertycolumnwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycolumnwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Contain property)
        : csspropertycontain_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycontain_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ContainIntrinsicBlockSize property)
        : csspropertycontainintrinsicblocksize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycontainintrinsicblocksize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ContainIntrinsicHeight property)
        : csspropertycontainintrinsicheight_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycontainintrinsicheight_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ContainIntrinsicInlineSize property)
        : csspropertycontainintrinsicinlinesize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycontainintrinsicinlinesize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ContainIntrinsicWidth property)
        : csspropertycontainintrinsicwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycontainintrinsicwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ContainerName property)
        : csspropertycontainername_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycontainername_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ContainerType property)
        : csspropertycontainertype_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycontainertype_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Content property)
        : csspropertycontent_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycontent_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ContentVisibility property)
        : csspropertycontentvisibility_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycontentvisibility_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::CounterIncrement property)
        : csspropertycounterincrement_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycounterincrement_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::CounterReset property)
        : csspropertycounterreset_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycounterreset_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::CounterSet property)
        : csspropertycounterset_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycounterset_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Cursor property)
        : csspropertycursor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycursor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Cx property)
        : csspropertycx_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycx_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Cy property)
        : csspropertycy_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycy_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::D property)
        : csspropertyd_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyd_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::DescentOverride property)
        : csspropertydescentoverride_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertydescentoverride_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Display property)
        : csspropertydisplay_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertydisplay_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::DominantBaseline property)
        : csspropertydominantbaseline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertydominantbaseline_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::DynamicRangeLimit property)
        : csspropertydynamicrangelimit_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertydynamicrangelimit_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::EmptyCells property)
        : csspropertyemptycells_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyemptycells_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Fallback property)
        : csspropertyfallback_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfallback_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FieldSizing property)
        : csspropertyfieldsizing_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfieldsizing_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Fill property)
        : csspropertyfill_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfill_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FillOpacity property)
        : csspropertyfillopacity_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfillopacity_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FillRule property)
        : csspropertyfillrule_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfillrule_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Filter property)
        : csspropertyfilter_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfilter_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FlexBasis property)
        : csspropertyflexbasis_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyflexbasis_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FlexDirection property)
        : csspropertyflexdirection_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyflexdirection_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FlexGrow property)
        : csspropertyflexgrow_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyflexgrow_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FlexShrink property)
        : csspropertyflexshrink_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyflexshrink_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FlexWrap property)
        : csspropertyflexwrap_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyflexwrap_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Float property)
        : csspropertyfloat_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfloat_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FloodColor property)
        : csspropertyfloodcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfloodcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FloodOpacity property)
        : csspropertyfloodopacity_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfloodopacity_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::FontDisplay property)
        : csspropertyfontdisplay_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontdisplay_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::GridAutoColumns property)
        : csspropertygridautocolumns_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygridautocolumns_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::GridAutoFlow property)
        : csspropertygridautoflow_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygridautoflow_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::GridAutoRows property)
        : csspropertygridautorows_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygridautorows_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::GridColumnEnd property)
        : csspropertygridcolumnend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygridcolumnend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::GridColumnStart property)
        : csspropertygridcolumnstart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygridcolumnstart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::GridRowEnd property)
        : csspropertygridrowend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygridrowend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::GridRowStart property)
        : csspropertygridrowstart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygridrowstart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::GridTemplateAreas property)
        : csspropertygridtemplateareas_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygridtemplateareas_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::GridTemplateColumns property)
        : csspropertygridtemplatecolumns_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygridtemplatecolumns_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::GridTemplateRows property)
        : csspropertygridtemplaterows_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygridtemplaterows_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Height property)
        : csspropertyheight_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyheight_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::HyphenateCharacter property)
        : csspropertyhyphenatecharacter_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyhyphenatecharacter_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::HyphenateLimitChars property)
        : csspropertyhyphenatelimitchars_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyhyphenatelimitchars_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Hyphens property)
        : csspropertyhyphens_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyhyphens_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ImageOrientation property)
        : csspropertyimageorientation_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyimageorientation_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ImageRendering property)
        : csspropertyimagerendering_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyimagerendering_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Inherits property)
        : csspropertyinherits_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinherits_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InitialLetter property)
        : csspropertyinitialletter_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinitialletter_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InitialValue property)
        : csspropertyinitialvalue_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinitialvalue_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InlineSize property)
        : csspropertyinlinesize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinlinesize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InsetBlockEnd property)
        : csspropertyinsetblockend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinsetblockend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InsetBlockStart property)
        : csspropertyinsetblockstart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinsetblockstart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InsetInlineEnd property)
        : csspropertyinsetinlineend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinsetinlineend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InsetInlineStart property)
        : csspropertyinsetinlinestart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinsetinlinestart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Interactivity property)
        : csspropertyinteractivity_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinteractivity_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalAlignContentBlock property)
        : csspropertyinternalaligncontentblock_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalaligncontentblock_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalEmptyLineHeight property)
        : csspropertyinternalemptylineheight_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalemptylineheight_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalFontSizeDelta property)
        : csspropertyinternalfontsizedelta_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalfontsizedelta_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalForcedBackgroundColor property)
        : csspropertyinternalforcedbackgroundcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalforcedbackgroundcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalForcedBorderColor property)
        : csspropertyinternalforcedbordercolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalforcedbordercolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalForcedColor property)
        : csspropertyinternalforcedcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalforcedcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalForcedOutlineColor property)
        : csspropertyinternalforcedoutlinecolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalforcedoutlinecolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalForcedVisitedColor property)
        : csspropertyinternalforcedvisitedcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalforcedvisitedcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalOverflowBlock property)
        : csspropertyinternaloverflowblock_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternaloverflowblock_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalOverflowInline property)
        : csspropertyinternaloverflowinline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternaloverflowinline_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedBackgroundColor property)
        : csspropertyinternalvisitedbackgroundcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedbackgroundcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedBorderBlockEndColor property)
        : csspropertyinternalvisitedborderblockendcolor_(std::move(property))
    {
        DCHECK(
            reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedborderblockendcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedBorderBlockStartColor property)
        : csspropertyinternalvisitedborderblockstartcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this)
            == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedborderblockstartcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedBorderBottomColor property)
        : csspropertyinternalvisitedborderbottomcolor_(std::move(property))
    {
        DCHECK(
            reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedborderbottomcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedBorderInlineEndColor property)
        : csspropertyinternalvisitedborderinlineendcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this)
            == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedborderinlineendcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedBorderInlineStartColor property)
        : csspropertyinternalvisitedborderinlinestartcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this)
            == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedborderinlinestartcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedBorderLeftColor property)
        : csspropertyinternalvisitedborderleftcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedborderleftcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedBorderRightColor property)
        : csspropertyinternalvisitedborderrightcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedborderrightcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedBorderTopColor property)
        : csspropertyinternalvisitedbordertopcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedbordertopcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedCaretColor property)
        : csspropertyinternalvisitedcaretcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedcaretcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedColumnRuleColor property)
        : csspropertyinternalvisitedcolumnrulecolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedcolumnrulecolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedFill property)
        : csspropertyinternalvisitedfill_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedfill_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedOutlineColor property)
        : csspropertyinternalvisitedoutlinecolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedoutlinecolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedStroke property)
        : csspropertyinternalvisitedstroke_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedstroke_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedTextDecorationColor property)
        : csspropertyinternalvisitedtextdecorationcolor_(std::move(property))
    {
        DCHECK(
            reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedtextdecorationcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedTextEmphasisColor property)
        : csspropertyinternalvisitedtextemphasiscolor_(std::move(property))
    {
        DCHECK(
            reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedtextemphasiscolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedTextFillColor property)
        : csspropertyinternalvisitedtextfillcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedtextfillcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InternalVisitedTextStrokeColor property)
        : csspropertyinternalvisitedtextstrokecolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinternalvisitedtextstrokecolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::InterpolateSize property)
        : csspropertyinterpolatesize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinterpolatesize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Isolation property)
        : csspropertyisolation_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyisolation_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::JustifyContent property)
        : csspropertyjustifycontent_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyjustifycontent_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::JustifyItems property)
        : csspropertyjustifyitems_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyjustifyitems_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::JustifySelf property)
        : csspropertyjustifyself_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyjustifyself_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Left property)
        : csspropertyleft_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyleft_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::LetterSpacing property)
        : csspropertyletterspacing_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyletterspacing_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::LightingColor property)
        : csspropertylightingcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertylightingcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::LineBreak property)
        : csspropertylinebreak_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertylinebreak_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::LineClamp property)
        : csspropertylineclamp_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertylineclamp_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::LineGapOverride property)
        : csspropertylinegapoverride_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertylinegapoverride_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::LineHeight property)
        : csspropertylineheight_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertylineheight_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ListStyleImage property)
        : csspropertyliststyleimage_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyliststyleimage_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ListStylePosition property)
        : csspropertyliststyleposition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyliststyleposition_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ListStyleType property)
        : csspropertyliststyletype_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyliststyletype_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MarginBlockEnd property)
        : csspropertymarginblockend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymarginblockend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MarginBlockStart property)
        : csspropertymarginblockstart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymarginblockstart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MarginBottom property)
        : csspropertymarginbottom_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymarginbottom_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MarginInlineEnd property)
        : csspropertymargininlineend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymargininlineend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MarginInlineStart property)
        : csspropertymargininlinestart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymargininlinestart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MarginLeft property)
        : csspropertymarginleft_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymarginleft_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MarginRight property)
        : csspropertymarginright_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymarginright_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MarginTop property)
        : csspropertymargintop_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymargintop_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MarkerEnd property)
        : csspropertymarkerend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymarkerend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MarkerMid property)
        : csspropertymarkermid_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymarkermid_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MarkerStart property)
        : csspropertymarkerstart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymarkerstart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MaskClip property)
        : csspropertymaskclip_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymaskclip_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MaskComposite property)
        : csspropertymaskcomposite_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymaskcomposite_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MaskMode property)
        : csspropertymaskmode_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymaskmode_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MaskOrigin property)
        : csspropertymaskorigin_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymaskorigin_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MaskRepeat property)
        : csspropertymaskrepeat_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymaskrepeat_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MaskSize property)
        : csspropertymasksize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymasksize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MaskType property)
        : csspropertymasktype_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymasktype_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MasonrySlack property)
        : csspropertymasonryslack_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymasonryslack_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MasonryTemplateTracks property)
        : csspropertymasonrytemplatetracks_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymasonrytemplatetracks_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MasonryTrackEnd property)
        : csspropertymasonrytrackend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymasonrytrackend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MasonryTrackStart property)
        : csspropertymasonrytrackstart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymasonrytrackstart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MathShift property)
        : csspropertymathshift_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymathshift_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MathStyle property)
        : csspropertymathstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymathstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MaxBlockSize property)
        : csspropertymaxblocksize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymaxblocksize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MaxHeight property)
        : csspropertymaxheight_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymaxheight_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MaxInlineSize property)
        : csspropertymaxinlinesize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymaxinlinesize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MaxWidth property)
        : csspropertymaxwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymaxwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MinBlockSize property)
        : csspropertyminblocksize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyminblocksize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MinHeight property)
        : csspropertyminheight_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyminheight_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MinInlineSize property)
        : csspropertymininlinesize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymininlinesize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MinWidth property)
        : csspropertyminwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyminwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::MixBlendMode property)
        : csspropertymixblendmode_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymixblendmode_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Navigation property)
        : csspropertynavigation_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertynavigation_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Negative property)
        : csspropertynegative_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertynegative_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ObjectFit property)
        : csspropertyobjectfit_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyobjectfit_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ObjectPosition property)
        : csspropertyobjectposition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyobjectposition_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ObjectViewBox property)
        : csspropertyobjectviewbox_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyobjectviewbox_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OffsetAnchor property)
        : csspropertyoffsetanchor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoffsetanchor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OffsetDistance property)
        : csspropertyoffsetdistance_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoffsetdistance_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OffsetPath property)
        : csspropertyoffsetpath_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoffsetpath_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OffsetPosition property)
        : csspropertyoffsetposition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoffsetposition_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OffsetRotate property)
        : csspropertyoffsetrotate_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoffsetrotate_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Opacity property)
        : csspropertyopacity_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyopacity_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Order property)
        : csspropertyorder_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyorder_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OriginTrialTestProperty property)
        : csspropertyorigintrialtestproperty_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyorigintrialtestproperty_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Orphans property)
        : csspropertyorphans_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyorphans_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OutlineColor property)
        : csspropertyoutlinecolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoutlinecolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OutlineOffset property)
        : csspropertyoutlineoffset_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoutlineoffset_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OutlineStyle property)
        : csspropertyoutlinestyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoutlinestyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OutlineWidth property)
        : csspropertyoutlinewidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoutlinewidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OverflowAnchor property)
        : csspropertyoverflowanchor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoverflowanchor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OverflowBlock property)
        : csspropertyoverflowblock_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoverflowblock_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OverflowClipMargin property)
        : csspropertyoverflowclipmargin_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoverflowclipmargin_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OverflowInline property)
        : csspropertyoverflowinline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoverflowinline_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OverflowWrap property)
        : csspropertyoverflowwrap_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoverflowwrap_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OverflowX property)
        : csspropertyoverflowx_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoverflowx_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OverflowY property)
        : csspropertyoverflowy_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoverflowy_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Overlay property)
        : csspropertyoverlay_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoverlay_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OverrideColors property)
        : csspropertyoverridecolors_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoverridecolors_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OverscrollBehaviorBlock property)
        : csspropertyoverscrollbehaviorblock_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoverscrollbehaviorblock_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OverscrollBehaviorInline property)
        : csspropertyoverscrollbehaviorinline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoverscrollbehaviorinline_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OverscrollBehaviorX property)
        : csspropertyoverscrollbehaviorx_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoverscrollbehaviorx_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::OverscrollBehaviorY property)
        : csspropertyoverscrollbehaviory_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoverscrollbehaviory_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Pad property)
        : csspropertypad_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypad_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PaddingBlockEnd property)
        : csspropertypaddingblockend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypaddingblockend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PaddingBlockStart property)
        : csspropertypaddingblockstart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypaddingblockstart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PaddingBottom property)
        : csspropertypaddingbottom_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypaddingbottom_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PaddingInlineEnd property)
        : csspropertypaddinginlineend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypaddinginlineend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PaddingInlineStart property)
        : csspropertypaddinginlinestart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypaddinginlinestart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PaddingLeft property)
        : csspropertypaddingleft_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypaddingleft_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PaddingRight property)
        : csspropertypaddingright_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypaddingright_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PaddingTop property)
        : csspropertypaddingtop_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypaddingtop_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Page property)
        : csspropertypage_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypage_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PageOrientation property)
        : csspropertypageorientation_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypageorientation_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PaintOrder property)
        : csspropertypaintorder_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypaintorder_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Perspective property)
        : csspropertyperspective_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyperspective_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PerspectiveOrigin property)
        : csspropertyperspectiveorigin_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyperspectiveorigin_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PointerEvents property)
        : csspropertypointerevents_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypointerevents_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PopoverHideDelay property)
        : csspropertypopoverhidedelay_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypopoverhidedelay_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PopoverShowDelay property)
        : csspropertypopovershowdelay_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypopovershowdelay_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PositionTryFallbacks property)
        : csspropertypositiontryfallbacks_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypositiontryfallbacks_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PositionTryOrder property)
        : csspropertypositiontryorder_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypositiontryorder_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::PositionVisibility property)
        : csspropertypositionvisibility_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypositionvisibility_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Prefix property)
        : csspropertyprefix_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyprefix_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Quotes property)
        : csspropertyquotes_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyquotes_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::R property)
        : csspropertyr_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyr_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Range property)
        : csspropertyrange_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyrange_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ReadingFlow property)
        : csspropertyreadingflow_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyreadingflow_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Resize property)
        : csspropertyresize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyresize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Right property)
        : csspropertyright_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyright_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Rotate property)
        : csspropertyrotate_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyrotate_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::RowGap property)
        : csspropertyrowgap_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyrowgap_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::RubyAlign property)
        : csspropertyrubyalign_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyrubyalign_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::RubyPosition property)
        : csspropertyrubyposition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyrubyposition_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Rx property)
        : csspropertyrx_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyrx_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Ry property)
        : csspropertyry_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyry_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Scale property)
        : csspropertyscale_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscale_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollBehavior property)
        : csspropertyscrollbehavior_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollbehavior_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollMarginBlockEnd property)
        : csspropertyscrollmarginblockend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollmarginblockend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollMarginBlockStart property)
        : csspropertyscrollmarginblockstart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollmarginblockstart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollMarginBottom property)
        : csspropertyscrollmarginbottom_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollmarginbottom_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollMarginInlineEnd property)
        : csspropertyscrollmargininlineend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollmargininlineend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollMarginInlineStart property)
        : csspropertyscrollmargininlinestart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollmargininlinestart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollMarginLeft property)
        : csspropertyscrollmarginleft_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollmarginleft_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollMarginRight property)
        : csspropertyscrollmarginright_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollmarginright_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollMarginTop property)
        : csspropertyscrollmargintop_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollmargintop_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollMarkerGroup property)
        : csspropertyscrollmarkergroup_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollmarkergroup_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollPaddingBlockEnd property)
        : csspropertyscrollpaddingblockend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollpaddingblockend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollPaddingBlockStart property)
        : csspropertyscrollpaddingblockstart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollpaddingblockstart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollPaddingBottom property)
        : csspropertyscrollpaddingbottom_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollpaddingbottom_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollPaddingInlineEnd property)
        : csspropertyscrollpaddinginlineend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollpaddinginlineend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollPaddingInlineStart property)
        : csspropertyscrollpaddinginlinestart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollpaddinginlinestart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollPaddingLeft property)
        : csspropertyscrollpaddingleft_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollpaddingleft_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollPaddingRight property)
        : csspropertyscrollpaddingright_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollpaddingright_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollPaddingTop property)
        : csspropertyscrollpaddingtop_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollpaddingtop_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollSnapAlign property)
        : csspropertyscrollsnapalign_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollsnapalign_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollSnapStop property)
        : csspropertyscrollsnapstop_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollsnapstop_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollSnapType property)
        : csspropertyscrollsnaptype_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollsnaptype_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollStartBlock property)
        : csspropertyscrollstartblock_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollstartblock_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollStartInline property)
        : csspropertyscrollstartinline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollstartinline_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollStartTarget property)
        : csspropertyscrollstarttarget_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollstarttarget_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollStartX property)
        : csspropertyscrollstartx_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollstartx_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollStartY property)
        : csspropertyscrollstarty_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollstarty_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollTimelineAxis property)
        : csspropertyscrolltimelineaxis_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrolltimelineaxis_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollTimelineName property)
        : csspropertyscrolltimelinename_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrolltimelinename_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollbarColor property)
        : csspropertyscrollbarcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollbarcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollbarGutter property)
        : csspropertyscrollbargutter_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollbargutter_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ScrollbarWidth property)
        : csspropertyscrollbarwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollbarwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ShapeImageThreshold property)
        : csspropertyshapeimagethreshold_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyshapeimagethreshold_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ShapeMargin property)
        : csspropertyshapemargin_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyshapemargin_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ShapeOutside property)
        : csspropertyshapeoutside_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyshapeoutside_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ShapeRendering property)
        : csspropertyshaperendering_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyshaperendering_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Size property)
        : csspropertysize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertysize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::SizeAdjust property)
        : csspropertysizeadjust_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertysizeadjust_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Speak property)
        : csspropertyspeak_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyspeak_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::SpeakAs property)
        : csspropertyspeakas_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyspeakas_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Src property)
        : csspropertysrc_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertysrc_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::StopColor property)
        : csspropertystopcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertystopcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::StopOpacity property)
        : csspropertystopopacity_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertystopopacity_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Stroke property)
        : csspropertystroke_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertystroke_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::StrokeDasharray property)
        : csspropertystrokedasharray_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertystrokedasharray_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::StrokeDashoffset property)
        : csspropertystrokedashoffset_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertystrokedashoffset_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::StrokeLinecap property)
        : csspropertystrokelinecap_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertystrokelinecap_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::StrokeLinejoin property)
        : csspropertystrokelinejoin_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertystrokelinejoin_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::StrokeMiterlimit property)
        : csspropertystrokemiterlimit_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertystrokemiterlimit_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::StrokeOpacity property)
        : csspropertystrokeopacity_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertystrokeopacity_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::StrokeWidth property)
        : csspropertystrokewidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertystrokewidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Suffix property)
        : csspropertysuffix_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertysuffix_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Symbols property)
        : csspropertysymbols_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertysymbols_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Syntax property)
        : csspropertysyntax_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertysyntax_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::System property)
        : csspropertysystem_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertysystem_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TabSize property)
        : csspropertytabsize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytabsize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TableLayout property)
        : csspropertytablelayout_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytablelayout_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextAlign property)
        : csspropertytextalign_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextalign_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextAlignLast property)
        : csspropertytextalignlast_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextalignlast_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextAnchor property)
        : csspropertytextanchor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextanchor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextAutospace property)
        : csspropertytextautospace_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextautospace_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextBoxEdge property)
        : csspropertytextboxedge_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextboxedge_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextBoxTrim property)
        : csspropertytextboxtrim_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextboxtrim_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextCombineUpright property)
        : csspropertytextcombineupright_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextcombineupright_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextDecorationColor property)
        : csspropertytextdecorationcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextdecorationcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextDecorationLine property)
        : csspropertytextdecorationline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextdecorationline_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextDecorationSkipInk property)
        : csspropertytextdecorationskipink_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextdecorationskipink_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextDecorationStyle property)
        : csspropertytextdecorationstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextdecorationstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextDecorationThickness property)
        : csspropertytextdecorationthickness_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextdecorationthickness_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextEmphasisColor property)
        : csspropertytextemphasiscolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextemphasiscolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextEmphasisPosition property)
        : csspropertytextemphasisposition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextemphasisposition_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextEmphasisStyle property)
        : csspropertytextemphasisstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextemphasisstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextIndent property)
        : csspropertytextindent_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextindent_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextOverflow property)
        : csspropertytextoverflow_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextoverflow_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextShadow property)
        : csspropertytextshadow_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextshadow_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextTransform property)
        : csspropertytexttransform_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytexttransform_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextUnderlineOffset property)
        : csspropertytextunderlineoffset_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextunderlineoffset_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextUnderlinePosition property)
        : csspropertytextunderlineposition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextunderlineposition_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextWrapMode property)
        : csspropertytextwrapmode_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextwrapmode_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TextWrapStyle property)
        : csspropertytextwrapstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextwrapstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TimelineScope property)
        : csspropertytimelinescope_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytimelinescope_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Top property)
        : csspropertytop_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytop_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TouchAction property)
        : csspropertytouchaction_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytouchaction_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Transform property)
        : csspropertytransform_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytransform_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TransformBox property)
        : csspropertytransformbox_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytransformbox_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TransformOrigin property)
        : csspropertytransformorigin_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytransformorigin_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TransformStyle property)
        : csspropertytransformstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytransformstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TransitionBehavior property)
        : csspropertytransitionbehavior_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytransitionbehavior_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TransitionDelay property)
        : csspropertytransitiondelay_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytransitiondelay_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TransitionDuration property)
        : csspropertytransitionduration_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytransitionduration_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TransitionProperty property)
        : csspropertytransitionproperty_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytransitionproperty_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::TransitionTimingFunction property)
        : csspropertytransitiontimingfunction_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytransitiontimingfunction_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Translate property)
        : csspropertytranslate_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytranslate_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Types property)
        : csspropertytypes_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytypes_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::UnicodeBidi property)
        : csspropertyunicodebidi_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyunicodebidi_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::UnicodeRange property)
        : csspropertyunicoderange_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyunicoderange_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::UserSelect property)
        : csspropertyuserselect_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyuserselect_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::VectorEffect property)
        : csspropertyvectoreffect_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyvectoreffect_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::VerticalAlign property)
        : csspropertyverticalalign_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyverticalalign_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ViewTimelineAxis property)
        : csspropertyviewtimelineaxis_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyviewtimelineaxis_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ViewTimelineInset property)
        : csspropertyviewtimelineinset_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyviewtimelineinset_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ViewTimelineName property)
        : csspropertyviewtimelinename_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyviewtimelinename_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ViewTransitionCaptureMode property)
        : csspropertyviewtransitioncapturemode_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyviewtransitioncapturemode_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ViewTransitionClass property)
        : csspropertyviewtransitionclass_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyviewtransitionclass_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ViewTransitionGroup property)
        : csspropertyviewtransitiongroup_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyviewtransitiongroup_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ViewTransitionName property)
        : csspropertyviewtransitionname_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyviewtransitionname_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Visibility property)
        : csspropertyvisibility_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyvisibility_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderHorizontalSpacing property)
        : csspropertywebkitborderhorizontalspacing_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitborderhorizontalspacing_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderImage property)
        : csspropertywebkitborderimage_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitborderimage_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderVerticalSpacing property)
        : csspropertywebkitborderverticalspacing_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitborderverticalspacing_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBoxAlign property)
        : csspropertywebkitboxalign_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitboxalign_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBoxDecorationBreak property)
        : csspropertywebkitboxdecorationbreak_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitboxdecorationbreak_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBoxDirection property)
        : csspropertywebkitboxdirection_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitboxdirection_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBoxFlex property)
        : csspropertywebkitboxflex_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitboxflex_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBoxOrdinalGroup property)
        : csspropertywebkitboxordinalgroup_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitboxordinalgroup_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBoxOrient property)
        : csspropertywebkitboxorient_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitboxorient_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBoxPack property)
        : csspropertywebkitboxpack_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitboxpack_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBoxReflect property)
        : csspropertywebkitboxreflect_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitboxreflect_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitLineBreak property)
        : csspropertywebkitlinebreak_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitlinebreak_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitLineClamp property)
        : csspropertywebkitlineclamp_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitlineclamp_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMaskBoxImageOutset property)
        : csspropertywebkitmaskboximageoutset_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitmaskboximageoutset_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMaskBoxImageRepeat property)
        : csspropertywebkitmaskboximagerepeat_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitmaskboximagerepeat_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMaskBoxImageSlice property)
        : csspropertywebkitmaskboximageslice_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitmaskboximageslice_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMaskBoxImageSource property)
        : csspropertywebkitmaskboximagesource_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitmaskboximagesource_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMaskBoxImageWidth property)
        : csspropertywebkitmaskboximagewidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitmaskboximagewidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMaskPositionX property)
        : csspropertywebkitmaskpositionx_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitmaskpositionx_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMaskPositionY property)
        : csspropertywebkitmaskpositiony_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitmaskpositiony_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitPerspectiveOriginX property)
        : csspropertywebkitperspectiveoriginx_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitperspectiveoriginx_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitPerspectiveOriginY property)
        : csspropertywebkitperspectiveoriginy_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitperspectiveoriginy_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitPrintColorAdjust property)
        : csspropertywebkitprintcoloradjust_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitprintcoloradjust_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitRtlOrdering property)
        : csspropertywebkitrtlordering_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitrtlordering_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitRubyPosition property)
        : csspropertywebkitrubyposition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitrubyposition_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTapHighlightColor property)
        : csspropertywebkittaphighlightcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkittaphighlightcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTextCombine property)
        : csspropertywebkittextcombine_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkittextcombine_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTextDecorationsInEffect property)
        : csspropertywebkittextdecorationsineffect_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkittextdecorationsineffect_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTextFillColor property)
        : csspropertywebkittextfillcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkittextfillcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTextSecurity property)
        : csspropertywebkittextsecurity_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkittextsecurity_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTextStrokeColor property)
        : csspropertywebkittextstrokecolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkittextstrokecolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTextStrokeWidth property)
        : csspropertywebkittextstrokewidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkittextstrokewidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTransformOriginX property)
        : csspropertywebkittransformoriginx_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkittransformoriginx_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTransformOriginY property)
        : csspropertywebkittransformoriginy_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkittransformoriginy_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTransformOriginZ property)
        : csspropertywebkittransformoriginz_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkittransformoriginz_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitUserDrag property)
        : csspropertywebkituserdrag_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkituserdrag_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitUserModify property)
        : csspropertywebkitusermodify_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitusermodify_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WhiteSpaceCollapse property)
        : csspropertywhitespacecollapse_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywhitespacecollapse_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Widows property)
        : csspropertywidows_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywidows_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Width property)
        : csspropertywidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WillChange property)
        : csspropertywillchange_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywillchange_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WordBreak property)
        : csspropertywordbreak_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywordbreak_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WordSpacing property)
        : csspropertywordspacing_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywordspacing_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::X property)
        : csspropertyx_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyx_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::Y property)
        : csspropertyy_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyy_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::ZIndex property)
        : csspropertyzindex_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyzindex_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::AlternativeAnimationWithTimeline property)
        : csspropertyalternativeanimationwithtimeline_(std::move(property))
    {
        DCHECK(
            reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyalternativeanimationwithtimeline_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Animation property)
        : csspropertyanimation_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanimation_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::AnimationRange property)
        : csspropertyanimationrange_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyanimationrange_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Background property)
        : csspropertybackground_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybackground_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BackgroundPosition property)
        : csspropertybackgroundposition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybackgroundposition_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Border property)
        : csspropertyborder_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborder_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderBlock property)
        : csspropertyborderblock_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderblock_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderBlockColor property)
        : csspropertyborderblockcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderblockcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderBlockEnd property)
        : csspropertyborderblockend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderblockend_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderBlockStart property)
        : csspropertyborderblockstart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderblockstart_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderBlockStyle property)
        : csspropertyborderblockstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderblockstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderBlockWidth property)
        : csspropertyborderblockwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderblockwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderBottom property)
        : csspropertyborderbottom_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderbottom_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderColor property)
        : csspropertybordercolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybordercolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderImage property)
        : csspropertyborderimage_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderimage_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderInline property)
        : csspropertyborderinline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderinline_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderInlineColor property)
        : csspropertyborderinlinecolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderinlinecolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderInlineEnd property)
        : csspropertyborderinlineend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderinlineend_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderInlineStart property)
        : csspropertyborderinlinestart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderinlinestart_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderInlineStyle property)
        : csspropertyborderinlinestyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderinlinestyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderInlineWidth property)
        : csspropertyborderinlinewidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderinlinewidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderLeft property)
        : csspropertyborderleft_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderleft_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderRadius property)
        : csspropertyborderradius_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderradius_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderRight property)
        : csspropertyborderright_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderright_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderSpacing property)
        : csspropertyborderspacing_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderspacing_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderStyle property)
        : csspropertyborderstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderTop property)
        : csspropertybordertop_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertybordertop_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::BorderWidth property)
        : csspropertyborderwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyborderwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::ColumnRule property)
        : csspropertycolumnrule_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycolumnrule_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Columns property)
        : csspropertycolumns_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycolumns_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::ContainIntrinsicSize property)
        : csspropertycontainintrinsicsize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycontainintrinsicsize_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Container property)
        : csspropertycontainer_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertycontainer_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Flex property)
        : csspropertyflex_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyflex_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::FlexFlow property)
        : csspropertyflexflow_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyflexflow_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Font property)
        : csspropertyfont_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfont_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::FontSynthesis property)
        : csspropertyfontsynthesis_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontsynthesis_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::FontVariant property)
        : csspropertyfontvariant_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyfontvariant_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Gap property)
        : csspropertygap_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygap_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Grid property)
        : csspropertygrid_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygrid_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::GridArea property)
        : csspropertygridarea_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygridarea_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::GridColumn property)
        : csspropertygridcolumn_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygridcolumn_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::GridRow property)
        : csspropertygridrow_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygridrow_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::GridTemplate property)
        : csspropertygridtemplate_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertygridtemplate_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Inset property)
        : csspropertyinset_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinset_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::InsetBlock property)
        : csspropertyinsetblock_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinsetblock_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::InsetInline property)
        : csspropertyinsetinline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyinsetinline_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::ListStyle property)
        : csspropertyliststyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyliststyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Margin property)
        : csspropertymargin_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymargin_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::MarginBlock property)
        : csspropertymarginblock_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymarginblock_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::MarginInline property)
        : csspropertymargininline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymargininline_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Marker property)
        : csspropertymarker_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymarker_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Mask property)
        : csspropertymask_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymask_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::MaskPosition property)
        : csspropertymaskposition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymaskposition_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::MasonryTrack property)
        : csspropertymasonrytrack_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertymasonrytrack_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Offset property)
        : csspropertyoffset_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoffset_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Outline property)
        : csspropertyoutline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoutline_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Overflow property)
        : csspropertyoverflow_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoverflow_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::OverscrollBehavior property)
        : csspropertyoverscrollbehavior_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyoverscrollbehavior_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Padding property)
        : csspropertypadding_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypadding_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::PaddingBlock property)
        : csspropertypaddingblock_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypaddingblock_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::PaddingInline property)
        : csspropertypaddinginline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypaddinginline_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::PageBreakAfter property)
        : csspropertypagebreakafter_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypagebreakafter_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::PageBreakBefore property)
        : csspropertypagebreakbefore_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypagebreakbefore_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::PageBreakInside property)
        : csspropertypagebreakinside_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypagebreakinside_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::PlaceContent property)
        : csspropertyplacecontent_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyplacecontent_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::PlaceItems property)
        : csspropertyplaceitems_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyplaceitems_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::PlaceSelf property)
        : csspropertyplaceself_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyplaceself_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::PositionTry property)
        : csspropertypositiontry_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertypositiontry_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::ScrollMargin property)
        : csspropertyscrollmargin_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollmargin_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::ScrollMarginBlock property)
        : csspropertyscrollmarginblock_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollmarginblock_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::ScrollMarginInline property)
        : csspropertyscrollmargininline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollmargininline_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::ScrollPadding property)
        : csspropertyscrollpadding_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollpadding_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::ScrollPaddingBlock property)
        : csspropertyscrollpaddingblock_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollpaddingblock_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::ScrollPaddingInline property)
        : csspropertyscrollpaddinginline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollpaddinginline_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::ScrollStart property)
        : csspropertyscrollstart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrollstart_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::ScrollTimeline property)
        : csspropertyscrolltimeline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyscrolltimeline_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::TextBox property)
        : csspropertytextbox_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextbox_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::TextDecoration property)
        : csspropertytextdecoration_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextdecoration_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::TextEmphasis property)
        : csspropertytextemphasis_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextemphasis_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::TextSpacing property)
        : csspropertytextspacing_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextspacing_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::TextWrap property)
        : csspropertytextwrap_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytextwrap_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::Transition property)
        : csspropertytransition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertytransition_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::ViewTimeline property)
        : csspropertyviewtimeline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyviewtimeline_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitColumnBreakAfter property)
        : csspropertywebkitcolumnbreakafter_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitcolumnbreakafter_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitColumnBreakBefore property)
        : csspropertywebkitcolumnbreakbefore_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitcolumnbreakbefore_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitColumnBreakInside property)
        : csspropertywebkitcolumnbreakinside_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitcolumnbreakinside_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitMaskBoxImage property)
        : csspropertywebkitmaskboximage_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkitmaskboximage_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitTextStroke property)
        : csspropertywebkittextstroke_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywebkittextstroke_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WhiteSpace property)
        : csspropertywhitespace_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertywhitespace_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitAppearance property)
        : csspropertyaliaswebkitappearance_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitappearance_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitAppRegion property)
        : csspropertyaliaswebkitappregion_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitappregion_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMaskClip property)
        : csspropertyaliaswebkitmaskclip_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitmaskclip_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMaskComposite property)
        : csspropertyaliaswebkitmaskcomposite_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitmaskcomposite_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMaskImage property)
        : csspropertyaliaswebkitmaskimage_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitmaskimage_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMaskOrigin property)
        : csspropertyaliaswebkitmaskorigin_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitmaskorigin_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMaskRepeat property)
        : csspropertyaliaswebkitmaskrepeat_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitmaskrepeat_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMaskSize property)
        : csspropertyaliaswebkitmasksize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitmasksize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderEndColor property)
        : csspropertyaliaswebkitborderendcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderendcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderEndStyle property)
        : csspropertyaliaswebkitborderendstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderendstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderEndWidth property)
        : csspropertyaliaswebkitborderendwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderendwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderStartColor property)
        : csspropertyaliaswebkitborderstartcolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderstartcolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderStartStyle property)
        : csspropertyaliaswebkitborderstartstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderstartstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderStartWidth property)
        : csspropertyaliaswebkitborderstartwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderstartwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderBeforeColor property)
        : csspropertyaliaswebkitborderbeforecolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderbeforecolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderBeforeStyle property)
        : csspropertyaliaswebkitborderbeforestyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderbeforestyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderBeforeWidth property)
        : csspropertyaliaswebkitborderbeforewidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderbeforewidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderAfterColor property)
        : csspropertyaliaswebkitborderaftercolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderaftercolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderAfterStyle property)
        : csspropertyaliaswebkitborderafterstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderafterstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderAfterWidth property)
        : csspropertyaliaswebkitborderafterwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderafterwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMarginEnd property)
        : csspropertyaliaswebkitmarginend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitmarginend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMarginStart property)
        : csspropertyaliaswebkitmarginstart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitmarginstart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMarginBefore property)
        : csspropertyaliaswebkitmarginbefore_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitmarginbefore_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMarginAfter property)
        : csspropertyaliaswebkitmarginafter_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitmarginafter_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitPaddingEnd property)
        : csspropertyaliaswebkitpaddingend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitpaddingend_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitPaddingStart property)
        : csspropertyaliaswebkitpaddingstart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitpaddingstart_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitPaddingBefore property)
        : csspropertyaliaswebkitpaddingbefore_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitpaddingbefore_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitPaddingAfter property)
        : csspropertyaliaswebkitpaddingafter_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitpaddingafter_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitLogicalWidth property)
        : csspropertyaliaswebkitlogicalwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitlogicalwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitLogicalHeight property)
        : csspropertyaliaswebkitlogicalheight_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitlogicalheight_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMinLogicalWidth property)
        : csspropertyaliaswebkitminlogicalwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitminlogicalwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMinLogicalHeight property)
        : csspropertyaliaswebkitminlogicalheight_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitminlogicalheight_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMaxLogicalWidth property)
        : csspropertyaliaswebkitmaxlogicalwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitmaxlogicalwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitMaxLogicalHeight property)
        : csspropertyaliaswebkitmaxlogicalheight_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitmaxlogicalheight_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitBorderAfter property)
        : csspropertyaliaswebkitborderafter_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderafter_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitBorderBefore property)
        : csspropertyaliaswebkitborderbefore_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderbefore_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitBorderEnd property)
        : csspropertyaliaswebkitborderend_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderend_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitBorderStart property)
        : csspropertyaliaswebkitborderstart_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderstart_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitMask property)
        : csspropertyaliaswebkitmask_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitmask_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitMaskPosition property)
        : csspropertyaliaswebkitmaskposition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitmaskposition_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::EpubCaptionSide property)
        : csspropertyaliasepubcaptionside_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliasepubcaptionside_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::EpubTextCombine property)
        : csspropertyaliasepubtextcombine_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliasepubtextcombine_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::EpubTextEmphasis property)
        : csspropertyaliasepubtextemphasis_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliasepubtextemphasis_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::EpubTextEmphasisColor property)
        : csspropertyaliasepubtextemphasiscolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliasepubtextemphasiscolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::EpubTextEmphasisStyle property)
        : csspropertyaliasepubtextemphasisstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliasepubtextemphasisstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::EpubTextOrientation property)
        : csspropertyaliasepubtextorientation_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliasepubtextorientation_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::EpubTextTransform property)
        : csspropertyaliasepubtexttransform_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliasepubtexttransform_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::EpubWordBreak property)
        : csspropertyaliasepubwordbreak_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliasepubwordbreak_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::EpubWritingMode property)
        : csspropertyaliasepubwritingmode_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliasepubwritingmode_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitAlignContent property)
        : csspropertyaliaswebkitaligncontent_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitaligncontent_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitAlignItems property)
        : csspropertyaliaswebkitalignitems_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitalignitems_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitAlignSelf property)
        : csspropertyaliaswebkitalignself_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitalignself_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitAnimation property)
        : csspropertyaliaswebkitanimation_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitanimation_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitAlternativeAnimationWithTimeline property)
        : csspropertyaliaswebkitalternativeanimationwithtimeline_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this)
            == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitalternativeanimationwithtimeline_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitAnimationDelay property)
        : csspropertyaliaswebkitanimationdelay_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitanimationdelay_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitAnimationDirection property)
        : csspropertyaliaswebkitanimationdirection_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitanimationdirection_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitAnimationDuration property)
        : csspropertyaliaswebkitanimationduration_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitanimationduration_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitAnimationFillMode property)
        : csspropertyaliaswebkitanimationfillmode_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitanimationfillmode_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitAnimationIterationCount property)
        : csspropertyaliaswebkitanimationiterationcount_(std::move(property))
    {
        DCHECK(
            reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitanimationiterationcount_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitAnimationName property)
        : csspropertyaliaswebkitanimationname_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitanimationname_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitAnimationPlayState property)
        : csspropertyaliaswebkitanimationplaystate_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitanimationplaystate_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitAnimationTimingFunction property)
        : csspropertyaliaswebkitanimationtimingfunction_(std::move(property))
    {
        DCHECK(
            reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitanimationtimingfunction_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBackfaceVisibility property)
        : csspropertyaliaswebkitbackfacevisibility_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitbackfacevisibility_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBackgroundClip property)
        : csspropertyaliaswebkitbackgroundclip_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitbackgroundclip_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBackgroundOrigin property)
        : csspropertyaliaswebkitbackgroundorigin_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitbackgroundorigin_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBackgroundSize property)
        : csspropertyaliaswebkitbackgroundsize_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitbackgroundsize_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderBottomLeftRadius property)
        : csspropertyaliaswebkitborderbottomleftradius_(std::move(property))
    {
        DCHECK(
            reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderbottomleftradius_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderBottomRightRadius property)
        : csspropertyaliaswebkitborderbottomrightradius_(std::move(property))
    {
        DCHECK(
            reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderbottomrightradius_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitBorderRadius property)
        : csspropertyaliaswebkitborderradius_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitborderradius_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderTopLeftRadius property)
        : csspropertyaliaswebkitbordertopleftradius_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitbordertopleftradius_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBorderTopRightRadius property)
        : csspropertyaliaswebkitbordertoprightradius_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitbordertoprightradius_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBoxShadow property)
        : csspropertyaliaswebkitboxshadow_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitboxshadow_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitBoxSizing property)
        : csspropertyaliaswebkitboxsizing_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitboxsizing_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitClipPath property)
        : csspropertyaliaswebkitclippath_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitclippath_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitColumnCount property)
        : csspropertyaliaswebkitcolumncount_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitcolumncount_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitColumnGap property)
        : csspropertyaliaswebkitcolumngap_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitcolumngap_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitColumnRule property)
        : csspropertyaliaswebkitcolumnrule_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitcolumnrule_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitColumnRuleColor property)
        : csspropertyaliaswebkitcolumnrulecolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitcolumnrulecolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitColumnRuleStyle property)
        : csspropertyaliaswebkitcolumnrulestyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitcolumnrulestyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitColumnRuleWidth property)
        : csspropertyaliaswebkitcolumnrulewidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitcolumnrulewidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitColumnSpan property)
        : csspropertyaliaswebkitcolumnspan_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitcolumnspan_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitColumnWidth property)
        : csspropertyaliaswebkitcolumnwidth_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitcolumnwidth_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitColumns property)
        : csspropertyaliaswebkitcolumns_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitcolumns_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitFilter property)
        : csspropertyaliaswebkitfilter_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitfilter_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitFlex property)
        : csspropertyaliaswebkitflex_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitflex_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitFlexBasis property)
        : csspropertyaliaswebkitflexbasis_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitflexbasis_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitFlexDirection property)
        : csspropertyaliaswebkitflexdirection_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitflexdirection_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitFlexFlow property)
        : csspropertyaliaswebkitflexflow_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitflexflow_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitFlexGrow property)
        : csspropertyaliaswebkitflexgrow_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitflexgrow_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitFlexShrink property)
        : csspropertyaliaswebkitflexshrink_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitflexshrink_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitFlexWrap property)
        : csspropertyaliaswebkitflexwrap_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitflexwrap_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitFontFeatureSettings property)
        : csspropertyaliaswebkitfontfeaturesettings_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitfontfeaturesettings_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitHyphenateCharacter property)
        : csspropertyaliaswebkithyphenatecharacter_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkithyphenatecharacter_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitJustifyContent property)
        : csspropertyaliaswebkitjustifycontent_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitjustifycontent_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitOpacity property)
        : csspropertyaliaswebkitopacity_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitopacity_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitOrder property)
        : csspropertyaliaswebkitorder_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitorder_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitPerspective property)
        : csspropertyaliaswebkitperspective_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitperspective_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitPerspectiveOrigin property)
        : csspropertyaliaswebkitperspectiveorigin_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitperspectiveorigin_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitShapeImageThreshold property)
        : csspropertyaliaswebkitshapeimagethreshold_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitshapeimagethreshold_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitShapeMargin property)
        : csspropertyaliaswebkitshapemargin_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitshapemargin_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitShapeOutside property)
        : csspropertyaliaswebkitshapeoutside_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkitshapeoutside_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitTextEmphasis property)
        : csspropertyaliaswebkittextemphasis_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkittextemphasis_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTextEmphasisColor property)
        : csspropertyaliaswebkittextemphasiscolor_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkittextemphasiscolor_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTextEmphasisPosition property)
        : csspropertyaliaswebkittextemphasisposition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkittextemphasisposition_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTextEmphasisStyle property)
        : csspropertyaliaswebkittextemphasisstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkittextemphasisstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTextSizeAdjust property)
        : csspropertyaliaswebkittextsizeadjust_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkittextsizeadjust_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTransform property)
        : csspropertyaliaswebkittransform_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkittransform_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTransformOrigin property)
        : csspropertyaliaswebkittransformorigin_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkittransformorigin_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTransformStyle property)
        : csspropertyaliaswebkittransformstyle_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkittransformstyle_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::WebkitTransition property)
        : csspropertyaliaswebkittransition_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkittransition_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTransitionDelay property)
        : csspropertyaliaswebkittransitiondelay_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkittransitiondelay_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTransitionDuration property)
        : csspropertyaliaswebkittransitionduration_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkittransitionduration_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTransitionProperty property)
        : csspropertyaliaswebkittransitionproperty_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkittransitionproperty_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitTransitionTimingFunction property)
        : csspropertyaliaswebkittransitiontimingfunction_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this)
            == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkittransitiontimingfunction_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WebkitUserSelect property)
        : csspropertyaliaswebkituserselect_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswebkituserselect_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::WordWrap property)
        : csspropertyaliaswordwrap_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliaswordwrap_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::GridColumnGap property)
        : csspropertyaliasgridcolumngap_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliasgridcolumngap_));
    }
    constexpr CSSPropertyUnion(::blink::css_longhand::GridRowGap property)
        : csspropertyaliasgridrowgap_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliasgridrowgap_));
    }
    constexpr CSSPropertyUnion(::blink::css_shorthand::GridGap property)
        : csspropertyaliasgridgap_(std::move(property))
    {
        DCHECK(reinterpret_cast<const CSSUnresolvedProperty*>(this) == static_cast<const CSSUnresolvedProperty*>(&csspropertyaliasgridgap_));
    }

    Variable variable_;
    ::blink::css_longhand::ColorScheme csspropertycolorscheme_;
    ::blink::css_longhand::ForcedColorAdjust csspropertyforcedcoloradjust_;
    ::blink::css_longhand::MaskImage csspropertymaskimage_;
    ::blink::css_longhand::MathDepth csspropertymathdepth_;
    ::blink::css_longhand::Position csspropertyposition_;
    ::blink::css_longhand::PositionAnchor csspropertypositionanchor_;
    ::blink::css_longhand::TextSizeAdjust csspropertytextsizeadjust_;
    ::blink::css_longhand::Appearance csspropertyappearance_;
    ::blink::css_longhand::Color csspropertycolor_;
    ::blink::css_longhand::Direction csspropertydirection_;
    ::blink::css_longhand::FontFamily csspropertyfontfamily_;
    ::blink::css_longhand::FontFeatureSettings csspropertyfontfeaturesettings_;
    ::blink::css_longhand::FontKerning csspropertyfontkerning_;
    ::blink::css_longhand::FontOpticalSizing csspropertyfontopticalsizing_;
    ::blink::css_longhand::FontPalette csspropertyfontpalette_;
    ::blink::css_longhand::FontSize csspropertyfontsize_;
    ::blink::css_longhand::FontSizeAdjust csspropertyfontsizeadjust_;
    ::blink::css_longhand::FontStretch csspropertyfontstretch_;
    ::blink::css_longhand::FontStyle csspropertyfontstyle_;
    ::blink::css_longhand::FontSynthesisSmallCaps csspropertyfontsynthesissmallcaps_;
    ::blink::css_longhand::FontSynthesisStyle csspropertyfontsynthesisstyle_;
    ::blink::css_longhand::FontSynthesisWeight csspropertyfontsynthesisweight_;
    ::blink::css_longhand::FontVariantAlternates csspropertyfontvariantalternates_;
    ::blink::css_longhand::FontVariantCaps csspropertyfontvariantcaps_;
    ::blink::css_longhand::FontVariantEastAsian csspropertyfontvarianteastasian_;
    ::blink::css_longhand::FontVariantEmoji csspropertyfontvariantemoji_;
    ::blink::css_longhand::FontVariantLigatures csspropertyfontvariantligatures_;
    ::blink::css_longhand::FontVariantNumeric csspropertyfontvariantnumeric_;
    ::blink::css_longhand::FontVariantPosition csspropertyfontvariantposition_;
    ::blink::css_longhand::FontVariationSettings csspropertyfontvariationsettings_;
    ::blink::css_longhand::FontWeight csspropertyfontweight_;
    ::blink::css_longhand::InsetArea csspropertyinsetarea_;
    ::blink::css_longhand::InternalVisitedColor csspropertyinternalvisitedcolor_;
    ::blink::css_longhand::PositionArea csspropertypositionarea_;
    ::blink::css_longhand::TextOrientation csspropertytextorientation_;
    ::blink::css_longhand::TextRendering csspropertytextrendering_;
    ::blink::css_longhand::TextSpacingTrim csspropertytextspacingtrim_;
    ::blink::css_longhand::WebkitFontSmoothing csspropertywebkitfontsmoothing_;
    ::blink::css_longhand::WebkitLocale csspropertywebkitlocale_;
    ::blink::css_longhand::WebkitTextOrientation csspropertywebkittextorientation_;
    ::blink::css_longhand::WebkitWritingMode csspropertywebkitwritingmode_;
    ::blink::css_longhand::WritingMode csspropertywritingmode_;
    ::blink::css_longhand::Zoom csspropertyzoom_;
    ::blink::css_longhand::AccentColor csspropertyaccentcolor_;
    ::blink::css_longhand::AdditiveSymbols csspropertyadditivesymbols_;
    ::blink::css_longhand::AlignContent csspropertyaligncontent_;
    ::blink::css_longhand::AlignItems csspropertyalignitems_;
    ::blink::css_longhand::AlignSelf csspropertyalignself_;
    ::blink::css_longhand::AlignmentBaseline csspropertyalignmentbaseline_;
    ::blink::css_longhand::All csspropertyall_;
    ::blink::css_longhand::AnchorName csspropertyanchorname_;
    ::blink::css_longhand::AnchorScope csspropertyanchorscope_;
    ::blink::css_longhand::AnimationComposition csspropertyanimationcomposition_;
    ::blink::css_longhand::AnimationDelay csspropertyanimationdelay_;
    ::blink::css_longhand::AnimationDirection csspropertyanimationdirection_;
    ::blink::css_longhand::AnimationDuration csspropertyanimationduration_;
    ::blink::css_longhand::AnimationFillMode csspropertyanimationfillmode_;
    ::blink::css_longhand::AnimationIterationCount csspropertyanimationiterationcount_;
    ::blink::css_longhand::AnimationName csspropertyanimationname_;
    ::blink::css_longhand::AnimationPlayState csspropertyanimationplaystate_;
    ::blink::css_longhand::AnimationRangeEnd csspropertyanimationrangeend_;
    ::blink::css_longhand::AnimationRangeStart csspropertyanimationrangestart_;
    ::blink::css_longhand::AnimationTimeline csspropertyanimationtimeline_;
    ::blink::css_longhand::AnimationTimingFunction csspropertyanimationtimingfunction_;
    ::blink::css_longhand::AppRegion csspropertyappregion_;
    ::blink::css_longhand::AscentOverride csspropertyascentoverride_;
    ::blink::css_longhand::AspectRatio csspropertyaspectratio_;
    ::blink::css_longhand::BackdropFilter csspropertybackdropfilter_;
    ::blink::css_longhand::BackfaceVisibility csspropertybackfacevisibility_;
    ::blink::css_longhand::BackgroundAttachment csspropertybackgroundattachment_;
    ::blink::css_longhand::BackgroundBlendMode csspropertybackgroundblendmode_;
    ::blink::css_longhand::BackgroundClip csspropertybackgroundclip_;
    ::blink::css_longhand::BackgroundColor csspropertybackgroundcolor_;
    ::blink::css_longhand::BackgroundImage csspropertybackgroundimage_;
    ::blink::css_longhand::BackgroundOrigin csspropertybackgroundorigin_;
    ::blink::css_longhand::BackgroundPositionX csspropertybackgroundpositionx_;
    ::blink::css_longhand::BackgroundPositionY csspropertybackgroundpositiony_;
    ::blink::css_longhand::BackgroundRepeat csspropertybackgroundrepeat_;
    ::blink::css_longhand::BackgroundSize csspropertybackgroundsize_;
    ::blink::css_longhand::BasePalette csspropertybasepalette_;
    ::blink::css_longhand::BaselineShift csspropertybaselineshift_;
    ::blink::css_longhand::BaselineSource csspropertybaselinesource_;
    ::blink::css_longhand::BlockSize csspropertyblocksize_;
    ::blink::css_longhand::BorderBlockEndColor csspropertyborderblockendcolor_;
    ::blink::css_longhand::BorderBlockEndStyle csspropertyborderblockendstyle_;
    ::blink::css_longhand::BorderBlockEndWidth csspropertyborderblockendwidth_;
    ::blink::css_longhand::BorderBlockStartColor csspropertyborderblockstartcolor_;
    ::blink::css_longhand::BorderBlockStartStyle csspropertyborderblockstartstyle_;
    ::blink::css_longhand::BorderBlockStartWidth csspropertyborderblockstartwidth_;
    ::blink::css_longhand::BorderBottomColor csspropertyborderbottomcolor_;
    ::blink::css_longhand::BorderBottomLeftRadius csspropertyborderbottomleftradius_;
    ::blink::css_longhand::BorderBottomRightRadius csspropertyborderbottomrightradius_;
    ::blink::css_longhand::BorderBottomStyle csspropertyborderbottomstyle_;
    ::blink::css_longhand::BorderBottomWidth csspropertyborderbottomwidth_;
    ::blink::css_longhand::BorderCollapse csspropertybordercollapse_;
    ::blink::css_longhand::BorderEndEndRadius csspropertyborderendendradius_;
    ::blink::css_longhand::BorderEndStartRadius csspropertyborderendstartradius_;
    ::blink::css_longhand::BorderImageOutset csspropertyborderimageoutset_;
    ::blink::css_longhand::BorderImageRepeat csspropertyborderimagerepeat_;
    ::blink::css_longhand::BorderImageSlice csspropertyborderimageslice_;
    ::blink::css_longhand::BorderImageSource csspropertyborderimagesource_;
    ::blink::css_longhand::BorderImageWidth csspropertyborderimagewidth_;
    ::blink::css_longhand::BorderInlineEndColor csspropertyborderinlineendcolor_;
    ::blink::css_longhand::BorderInlineEndStyle csspropertyborderinlineendstyle_;
    ::blink::css_longhand::BorderInlineEndWidth csspropertyborderinlineendwidth_;
    ::blink::css_longhand::BorderInlineStartColor csspropertyborderinlinestartcolor_;
    ::blink::css_longhand::BorderInlineStartStyle csspropertyborderinlinestartstyle_;
    ::blink::css_longhand::BorderInlineStartWidth csspropertyborderinlinestartwidth_;
    ::blink::css_longhand::BorderLeftColor csspropertyborderleftcolor_;
    ::blink::css_longhand::BorderLeftStyle csspropertyborderleftstyle_;
    ::blink::css_longhand::BorderLeftWidth csspropertyborderleftwidth_;
    ::blink::css_longhand::BorderRightColor csspropertyborderrightcolor_;
    ::blink::css_longhand::BorderRightStyle csspropertyborderrightstyle_;
    ::blink::css_longhand::BorderRightWidth csspropertyborderrightwidth_;
    ::blink::css_longhand::BorderStartEndRadius csspropertyborderstartendradius_;
    ::blink::css_longhand::BorderStartStartRadius csspropertyborderstartstartradius_;
    ::blink::css_longhand::BorderTopColor csspropertybordertopcolor_;
    ::blink::css_longhand::BorderTopLeftRadius csspropertybordertopleftradius_;
    ::blink::css_longhand::BorderTopRightRadius csspropertybordertoprightradius_;
    ::blink::css_longhand::BorderTopStyle csspropertybordertopstyle_;
    ::blink::css_longhand::BorderTopWidth csspropertybordertopwidth_;
    ::blink::css_longhand::Bottom csspropertybottom_;
    ::blink::css_longhand::BoxDecorationBreak csspropertyboxdecorationbreak_;
    ::blink::css_longhand::BoxShadow csspropertyboxshadow_;
    ::blink::css_longhand::BoxSizing csspropertyboxsizing_;
    ::blink::css_longhand::BreakAfter csspropertybreakafter_;
    ::blink::css_longhand::BreakBefore csspropertybreakbefore_;
    ::blink::css_longhand::BreakInside csspropertybreakinside_;
    ::blink::css_longhand::BufferedRendering csspropertybufferedrendering_;
    ::blink::css_longhand::CaptionSide csspropertycaptionside_;
    ::blink::css_longhand::CaretAnimation csspropertycaretanimation_;
    ::blink::css_longhand::CaretColor csspropertycaretcolor_;
    ::blink::css_longhand::Clear csspropertyclear_;
    ::blink::css_longhand::Clip csspropertyclip_;
    ::blink::css_longhand::ClipPath csspropertyclippath_;
    ::blink::css_longhand::ClipRule csspropertycliprule_;
    ::blink::css_longhand::ColorInterpolation csspropertycolorinterpolation_;
    ::blink::css_longhand::ColorInterpolationFilters csspropertycolorinterpolationfilters_;
    ::blink::css_longhand::ColorRendering csspropertycolorrendering_;
    ::blink::css_longhand::ColumnCount csspropertycolumncount_;
    ::blink::css_longhand::ColumnFill csspropertycolumnfill_;
    ::blink::css_longhand::ColumnGap csspropertycolumngap_;
    ::blink::css_longhand::ColumnRuleColor csspropertycolumnrulecolor_;
    ::blink::css_longhand::ColumnRuleStyle csspropertycolumnrulestyle_;
    ::blink::css_longhand::ColumnRuleWidth csspropertycolumnrulewidth_;
    ::blink::css_longhand::ColumnSpan csspropertycolumnspan_;
    ::blink::css_longhand::ColumnWidth csspropertycolumnwidth_;
    ::blink::css_longhand::Contain csspropertycontain_;
    ::blink::css_longhand::ContainIntrinsicBlockSize csspropertycontainintrinsicblocksize_;
    ::blink::css_longhand::ContainIntrinsicHeight csspropertycontainintrinsicheight_;
    ::blink::css_longhand::ContainIntrinsicInlineSize csspropertycontainintrinsicinlinesize_;
    ::blink::css_longhand::ContainIntrinsicWidth csspropertycontainintrinsicwidth_;
    ::blink::css_longhand::ContainerName csspropertycontainername_;
    ::blink::css_longhand::ContainerType csspropertycontainertype_;
    ::blink::css_longhand::Content csspropertycontent_;
    ::blink::css_longhand::ContentVisibility csspropertycontentvisibility_;
    ::blink::css_longhand::CounterIncrement csspropertycounterincrement_;
    ::blink::css_longhand::CounterReset csspropertycounterreset_;
    ::blink::css_longhand::CounterSet csspropertycounterset_;
    ::blink::css_longhand::Cursor csspropertycursor_;
    ::blink::css_longhand::Cx csspropertycx_;
    ::blink::css_longhand::Cy csspropertycy_;
    ::blink::css_longhand::D csspropertyd_;
    ::blink::css_longhand::DescentOverride csspropertydescentoverride_;
    ::blink::css_longhand::Display csspropertydisplay_;
    ::blink::css_longhand::DominantBaseline csspropertydominantbaseline_;
    ::blink::css_longhand::DynamicRangeLimit csspropertydynamicrangelimit_;
    ::blink::css_longhand::EmptyCells csspropertyemptycells_;
    ::blink::css_longhand::Fallback csspropertyfallback_;
    ::blink::css_longhand::FieldSizing csspropertyfieldsizing_;
    ::blink::css_longhand::Fill csspropertyfill_;
    ::blink::css_longhand::FillOpacity csspropertyfillopacity_;
    ::blink::css_longhand::FillRule csspropertyfillrule_;
    ::blink::css_longhand::Filter csspropertyfilter_;
    ::blink::css_longhand::FlexBasis csspropertyflexbasis_;
    ::blink::css_longhand::FlexDirection csspropertyflexdirection_;
    ::blink::css_longhand::FlexGrow csspropertyflexgrow_;
    ::blink::css_longhand::FlexShrink csspropertyflexshrink_;
    ::blink::css_longhand::FlexWrap csspropertyflexwrap_;
    ::blink::css_longhand::Float csspropertyfloat_;
    ::blink::css_longhand::FloodColor csspropertyfloodcolor_;
    ::blink::css_longhand::FloodOpacity csspropertyfloodopacity_;
    ::blink::css_longhand::FontDisplay csspropertyfontdisplay_;
    ::blink::css_longhand::GridAutoColumns csspropertygridautocolumns_;
    ::blink::css_longhand::GridAutoFlow csspropertygridautoflow_;
    ::blink::css_longhand::GridAutoRows csspropertygridautorows_;
    ::blink::css_longhand::GridColumnEnd csspropertygridcolumnend_;
    ::blink::css_longhand::GridColumnStart csspropertygridcolumnstart_;
    ::blink::css_longhand::GridRowEnd csspropertygridrowend_;
    ::blink::css_longhand::GridRowStart csspropertygridrowstart_;
    ::blink::css_longhand::GridTemplateAreas csspropertygridtemplateareas_;
    ::blink::css_longhand::GridTemplateColumns csspropertygridtemplatecolumns_;
    ::blink::css_longhand::GridTemplateRows csspropertygridtemplaterows_;
    ::blink::css_longhand::Height csspropertyheight_;
    ::blink::css_longhand::HyphenateCharacter csspropertyhyphenatecharacter_;
    ::blink::css_longhand::HyphenateLimitChars csspropertyhyphenatelimitchars_;
    ::blink::css_longhand::Hyphens csspropertyhyphens_;
    ::blink::css_longhand::ImageOrientation csspropertyimageorientation_;
    ::blink::css_longhand::ImageRendering csspropertyimagerendering_;
    ::blink::css_longhand::Inherits csspropertyinherits_;
    ::blink::css_longhand::InitialLetter csspropertyinitialletter_;
    ::blink::css_longhand::InitialValue csspropertyinitialvalue_;
    ::blink::css_longhand::InlineSize csspropertyinlinesize_;
    ::blink::css_longhand::InsetBlockEnd csspropertyinsetblockend_;
    ::blink::css_longhand::InsetBlockStart csspropertyinsetblockstart_;
    ::blink::css_longhand::InsetInlineEnd csspropertyinsetinlineend_;
    ::blink::css_longhand::InsetInlineStart csspropertyinsetinlinestart_;
    ::blink::css_longhand::Interactivity csspropertyinteractivity_;
    ::blink::css_longhand::InternalAlignContentBlock csspropertyinternalaligncontentblock_;
    ::blink::css_longhand::InternalEmptyLineHeight csspropertyinternalemptylineheight_;
    ::blink::css_longhand::InternalFontSizeDelta csspropertyinternalfontsizedelta_;
    ::blink::css_longhand::InternalForcedBackgroundColor csspropertyinternalforcedbackgroundcolor_;
    ::blink::css_longhand::InternalForcedBorderColor csspropertyinternalforcedbordercolor_;
    ::blink::css_longhand::InternalForcedColor csspropertyinternalforcedcolor_;
    ::blink::css_longhand::InternalForcedOutlineColor csspropertyinternalforcedoutlinecolor_;
    ::blink::css_longhand::InternalForcedVisitedColor csspropertyinternalforcedvisitedcolor_;
    ::blink::css_longhand::InternalOverflowBlock csspropertyinternaloverflowblock_;
    ::blink::css_longhand::InternalOverflowInline csspropertyinternaloverflowinline_;
    ::blink::css_longhand::InternalVisitedBackgroundColor csspropertyinternalvisitedbackgroundcolor_;
    ::blink::css_longhand::InternalVisitedBorderBlockEndColor csspropertyinternalvisitedborderblockendcolor_;
    ::blink::css_longhand::InternalVisitedBorderBlockStartColor csspropertyinternalvisitedborderblockstartcolor_;
    ::blink::css_longhand::InternalVisitedBorderBottomColor csspropertyinternalvisitedborderbottomcolor_;
    ::blink::css_longhand::InternalVisitedBorderInlineEndColor csspropertyinternalvisitedborderinlineendcolor_;
    ::blink::css_longhand::InternalVisitedBorderInlineStartColor csspropertyinternalvisitedborderinlinestartcolor_;
    ::blink::css_longhand::InternalVisitedBorderLeftColor csspropertyinternalvisitedborderleftcolor_;
    ::blink::css_longhand::InternalVisitedBorderRightColor csspropertyinternalvisitedborderrightcolor_;
    ::blink::css_longhand::InternalVisitedBorderTopColor csspropertyinternalvisitedbordertopcolor_;
    ::blink::css_longhand::InternalVisitedCaretColor csspropertyinternalvisitedcaretcolor_;
    ::blink::css_longhand::InternalVisitedColumnRuleColor csspropertyinternalvisitedcolumnrulecolor_;
    ::blink::css_longhand::InternalVisitedFill csspropertyinternalvisitedfill_;
    ::blink::css_longhand::InternalVisitedOutlineColor csspropertyinternalvisitedoutlinecolor_;
    ::blink::css_longhand::InternalVisitedStroke csspropertyinternalvisitedstroke_;
    ::blink::css_longhand::InternalVisitedTextDecorationColor csspropertyinternalvisitedtextdecorationcolor_;
    ::blink::css_longhand::InternalVisitedTextEmphasisColor csspropertyinternalvisitedtextemphasiscolor_;
    ::blink::css_longhand::InternalVisitedTextFillColor csspropertyinternalvisitedtextfillcolor_;
    ::blink::css_longhand::InternalVisitedTextStrokeColor csspropertyinternalvisitedtextstrokecolor_;
    ::blink::css_longhand::InterpolateSize csspropertyinterpolatesize_;
    ::blink::css_longhand::Isolation csspropertyisolation_;
    ::blink::css_longhand::JustifyContent csspropertyjustifycontent_;
    ::blink::css_longhand::JustifyItems csspropertyjustifyitems_;
    ::blink::css_longhand::JustifySelf csspropertyjustifyself_;
    ::blink::css_longhand::Left csspropertyleft_;
    ::blink::css_longhand::LetterSpacing csspropertyletterspacing_;
    ::blink::css_longhand::LightingColor csspropertylightingcolor_;
    ::blink::css_longhand::LineBreak csspropertylinebreak_;
    ::blink::css_longhand::LineClamp csspropertylineclamp_;
    ::blink::css_longhand::LineGapOverride csspropertylinegapoverride_;
    ::blink::css_longhand::LineHeight csspropertylineheight_;
    ::blink::css_longhand::ListStyleImage csspropertyliststyleimage_;
    ::blink::css_longhand::ListStylePosition csspropertyliststyleposition_;
    ::blink::css_longhand::ListStyleType csspropertyliststyletype_;
    ::blink::css_longhand::MarginBlockEnd csspropertymarginblockend_;
    ::blink::css_longhand::MarginBlockStart csspropertymarginblockstart_;
    ::blink::css_longhand::MarginBottom csspropertymarginbottom_;
    ::blink::css_longhand::MarginInlineEnd csspropertymargininlineend_;
    ::blink::css_longhand::MarginInlineStart csspropertymargininlinestart_;
    ::blink::css_longhand::MarginLeft csspropertymarginleft_;
    ::blink::css_longhand::MarginRight csspropertymarginright_;
    ::blink::css_longhand::MarginTop csspropertymargintop_;
    ::blink::css_longhand::MarkerEnd csspropertymarkerend_;
    ::blink::css_longhand::MarkerMid csspropertymarkermid_;
    ::blink::css_longhand::MarkerStart csspropertymarkerstart_;
    ::blink::css_longhand::MaskClip csspropertymaskclip_;
    ::blink::css_longhand::MaskComposite csspropertymaskcomposite_;
    ::blink::css_longhand::MaskMode csspropertymaskmode_;
    ::blink::css_longhand::MaskOrigin csspropertymaskorigin_;
    ::blink::css_longhand::MaskRepeat csspropertymaskrepeat_;
    ::blink::css_longhand::MaskSize csspropertymasksize_;
    ::blink::css_longhand::MaskType csspropertymasktype_;
    ::blink::css_longhand::MasonrySlack csspropertymasonryslack_;
    ::blink::css_longhand::MasonryTemplateTracks csspropertymasonrytemplatetracks_;
    ::blink::css_longhand::MasonryTrackEnd csspropertymasonrytrackend_;
    ::blink::css_longhand::MasonryTrackStart csspropertymasonrytrackstart_;
    ::blink::css_longhand::MathShift csspropertymathshift_;
    ::blink::css_longhand::MathStyle csspropertymathstyle_;
    ::blink::css_longhand::MaxBlockSize csspropertymaxblocksize_;
    ::blink::css_longhand::MaxHeight csspropertymaxheight_;
    ::blink::css_longhand::MaxInlineSize csspropertymaxinlinesize_;
    ::blink::css_longhand::MaxWidth csspropertymaxwidth_;
    ::blink::css_longhand::MinBlockSize csspropertyminblocksize_;
    ::blink::css_longhand::MinHeight csspropertyminheight_;
    ::blink::css_longhand::MinInlineSize csspropertymininlinesize_;
    ::blink::css_longhand::MinWidth csspropertyminwidth_;
    ::blink::css_longhand::MixBlendMode csspropertymixblendmode_;
    ::blink::css_longhand::Navigation csspropertynavigation_;
    ::blink::css_longhand::Negative csspropertynegative_;
    ::blink::css_longhand::ObjectFit csspropertyobjectfit_;
    ::blink::css_longhand::ObjectPosition csspropertyobjectposition_;
    ::blink::css_longhand::ObjectViewBox csspropertyobjectviewbox_;
    ::blink::css_longhand::OffsetAnchor csspropertyoffsetanchor_;
    ::blink::css_longhand::OffsetDistance csspropertyoffsetdistance_;
    ::blink::css_longhand::OffsetPath csspropertyoffsetpath_;
    ::blink::css_longhand::OffsetPosition csspropertyoffsetposition_;
    ::blink::css_longhand::OffsetRotate csspropertyoffsetrotate_;
    ::blink::css_longhand::Opacity csspropertyopacity_;
    ::blink::css_longhand::Order csspropertyorder_;
    ::blink::css_longhand::OriginTrialTestProperty csspropertyorigintrialtestproperty_;
    ::blink::css_longhand::Orphans csspropertyorphans_;
    ::blink::css_longhand::OutlineColor csspropertyoutlinecolor_;
    ::blink::css_longhand::OutlineOffset csspropertyoutlineoffset_;
    ::blink::css_longhand::OutlineStyle csspropertyoutlinestyle_;
    ::blink::css_longhand::OutlineWidth csspropertyoutlinewidth_;
    ::blink::css_longhand::OverflowAnchor csspropertyoverflowanchor_;
    ::blink::css_longhand::OverflowBlock csspropertyoverflowblock_;
    ::blink::css_longhand::OverflowClipMargin csspropertyoverflowclipmargin_;
    ::blink::css_longhand::OverflowInline csspropertyoverflowinline_;
    ::blink::css_longhand::OverflowWrap csspropertyoverflowwrap_;
    ::blink::css_longhand::OverflowX csspropertyoverflowx_;
    ::blink::css_longhand::OverflowY csspropertyoverflowy_;
    ::blink::css_longhand::Overlay csspropertyoverlay_;
    ::blink::css_longhand::OverrideColors csspropertyoverridecolors_;
    ::blink::css_longhand::OverscrollBehaviorBlock csspropertyoverscrollbehaviorblock_;
    ::blink::css_longhand::OverscrollBehaviorInline csspropertyoverscrollbehaviorinline_;
    ::blink::css_longhand::OverscrollBehaviorX csspropertyoverscrollbehaviorx_;
    ::blink::css_longhand::OverscrollBehaviorY csspropertyoverscrollbehaviory_;
    ::blink::css_longhand::Pad csspropertypad_;
    ::blink::css_longhand::PaddingBlockEnd csspropertypaddingblockend_;
    ::blink::css_longhand::PaddingBlockStart csspropertypaddingblockstart_;
    ::blink::css_longhand::PaddingBottom csspropertypaddingbottom_;
    ::blink::css_longhand::PaddingInlineEnd csspropertypaddinginlineend_;
    ::blink::css_longhand::PaddingInlineStart csspropertypaddinginlinestart_;
    ::blink::css_longhand::PaddingLeft csspropertypaddingleft_;
    ::blink::css_longhand::PaddingRight csspropertypaddingright_;
    ::blink::css_longhand::PaddingTop csspropertypaddingtop_;
    ::blink::css_longhand::Page csspropertypage_;
    ::blink::css_longhand::PageOrientation csspropertypageorientation_;
    ::blink::css_longhand::PaintOrder csspropertypaintorder_;
    ::blink::css_longhand::Perspective csspropertyperspective_;
    ::blink::css_longhand::PerspectiveOrigin csspropertyperspectiveorigin_;
    ::blink::css_longhand::PointerEvents csspropertypointerevents_;
    ::blink::css_longhand::PopoverHideDelay csspropertypopoverhidedelay_;
    ::blink::css_longhand::PopoverShowDelay csspropertypopovershowdelay_;
    ::blink::css_longhand::PositionTryFallbacks csspropertypositiontryfallbacks_;
    ::blink::css_longhand::PositionTryOrder csspropertypositiontryorder_;
    ::blink::css_longhand::PositionVisibility csspropertypositionvisibility_;
    ::blink::css_longhand::Prefix csspropertyprefix_;
    ::blink::css_longhand::Quotes csspropertyquotes_;
    ::blink::css_longhand::R csspropertyr_;
    ::blink::css_longhand::Range csspropertyrange_;
    ::blink::css_longhand::ReadingFlow csspropertyreadingflow_;
    ::blink::css_longhand::Resize csspropertyresize_;
    ::blink::css_longhand::Right csspropertyright_;
    ::blink::css_longhand::Rotate csspropertyrotate_;
    ::blink::css_longhand::RowGap csspropertyrowgap_;
    ::blink::css_longhand::RubyAlign csspropertyrubyalign_;
    ::blink::css_longhand::RubyPosition csspropertyrubyposition_;
    ::blink::css_longhand::Rx csspropertyrx_;
    ::blink::css_longhand::Ry csspropertyry_;
    ::blink::css_longhand::Scale csspropertyscale_;
    ::blink::css_longhand::ScrollBehavior csspropertyscrollbehavior_;
    ::blink::css_longhand::ScrollMarginBlockEnd csspropertyscrollmarginblockend_;
    ::blink::css_longhand::ScrollMarginBlockStart csspropertyscrollmarginblockstart_;
    ::blink::css_longhand::ScrollMarginBottom csspropertyscrollmarginbottom_;
    ::blink::css_longhand::ScrollMarginInlineEnd csspropertyscrollmargininlineend_;
    ::blink::css_longhand::ScrollMarginInlineStart csspropertyscrollmargininlinestart_;
    ::blink::css_longhand::ScrollMarginLeft csspropertyscrollmarginleft_;
    ::blink::css_longhand::ScrollMarginRight csspropertyscrollmarginright_;
    ::blink::css_longhand::ScrollMarginTop csspropertyscrollmargintop_;
    ::blink::css_longhand::ScrollMarkerGroup csspropertyscrollmarkergroup_;
    ::blink::css_longhand::ScrollPaddingBlockEnd csspropertyscrollpaddingblockend_;
    ::blink::css_longhand::ScrollPaddingBlockStart csspropertyscrollpaddingblockstart_;
    ::blink::css_longhand::ScrollPaddingBottom csspropertyscrollpaddingbottom_;
    ::blink::css_longhand::ScrollPaddingInlineEnd csspropertyscrollpaddinginlineend_;
    ::blink::css_longhand::ScrollPaddingInlineStart csspropertyscrollpaddinginlinestart_;
    ::blink::css_longhand::ScrollPaddingLeft csspropertyscrollpaddingleft_;
    ::blink::css_longhand::ScrollPaddingRight csspropertyscrollpaddingright_;
    ::blink::css_longhand::ScrollPaddingTop csspropertyscrollpaddingtop_;
    ::blink::css_longhand::ScrollSnapAlign csspropertyscrollsnapalign_;
    ::blink::css_longhand::ScrollSnapStop csspropertyscrollsnapstop_;
    ::blink::css_longhand::ScrollSnapType csspropertyscrollsnaptype_;
    ::blink::css_longhand::ScrollStartBlock csspropertyscrollstartblock_;
    ::blink::css_longhand::ScrollStartInline csspropertyscrollstartinline_;
    ::blink::css_longhand::ScrollStartTarget csspropertyscrollstarttarget_;
    ::blink::css_longhand::ScrollStartX csspropertyscrollstartx_;
    ::blink::css_longhand::ScrollStartY csspropertyscrollstarty_;
    ::blink::css_longhand::ScrollTimelineAxis csspropertyscrolltimelineaxis_;
    ::blink::css_longhand::ScrollTimelineName csspropertyscrolltimelinename_;
    ::blink::css_longhand::ScrollbarColor csspropertyscrollbarcolor_;
    ::blink::css_longhand::ScrollbarGutter csspropertyscrollbargutter_;
    ::blink::css_longhand::ScrollbarWidth csspropertyscrollbarwidth_;
    ::blink::css_longhand::ShapeImageThreshold csspropertyshapeimagethreshold_;
    ::blink::css_longhand::ShapeMargin csspropertyshapemargin_;
    ::blink::css_longhand::ShapeOutside csspropertyshapeoutside_;
    ::blink::css_longhand::ShapeRendering csspropertyshaperendering_;
    ::blink::css_longhand::Size csspropertysize_;
    ::blink::css_longhand::SizeAdjust csspropertysizeadjust_;
    ::blink::css_longhand::Speak csspropertyspeak_;
    ::blink::css_longhand::SpeakAs csspropertyspeakas_;
    ::blink::css_longhand::Src csspropertysrc_;
    ::blink::css_longhand::StopColor csspropertystopcolor_;
    ::blink::css_longhand::StopOpacity csspropertystopopacity_;
    ::blink::css_longhand::Stroke csspropertystroke_;
    ::blink::css_longhand::StrokeDasharray csspropertystrokedasharray_;
    ::blink::css_longhand::StrokeDashoffset csspropertystrokedashoffset_;
    ::blink::css_longhand::StrokeLinecap csspropertystrokelinecap_;
    ::blink::css_longhand::StrokeLinejoin csspropertystrokelinejoin_;
    ::blink::css_longhand::StrokeMiterlimit csspropertystrokemiterlimit_;
    ::blink::css_longhand::StrokeOpacity csspropertystrokeopacity_;
    ::blink::css_longhand::StrokeWidth csspropertystrokewidth_;
    ::blink::css_longhand::Suffix csspropertysuffix_;
    ::blink::css_longhand::Symbols csspropertysymbols_;
    ::blink::css_longhand::Syntax csspropertysyntax_;
    ::blink::css_longhand::System csspropertysystem_;
    ::blink::css_longhand::TabSize csspropertytabsize_;
    ::blink::css_longhand::TableLayout csspropertytablelayout_;
    ::blink::css_longhand::TextAlign csspropertytextalign_;
    ::blink::css_longhand::TextAlignLast csspropertytextalignlast_;
    ::blink::css_longhand::TextAnchor csspropertytextanchor_;
    ::blink::css_longhand::TextAutospace csspropertytextautospace_;
    ::blink::css_longhand::TextBoxEdge csspropertytextboxedge_;
    ::blink::css_longhand::TextBoxTrim csspropertytextboxtrim_;
    ::blink::css_longhand::TextCombineUpright csspropertytextcombineupright_;
    ::blink::css_longhand::TextDecorationColor csspropertytextdecorationcolor_;
    ::blink::css_longhand::TextDecorationLine csspropertytextdecorationline_;
    ::blink::css_longhand::TextDecorationSkipInk csspropertytextdecorationskipink_;
    ::blink::css_longhand::TextDecorationStyle csspropertytextdecorationstyle_;
    ::blink::css_longhand::TextDecorationThickness csspropertytextdecorationthickness_;
    ::blink::css_longhand::TextEmphasisColor csspropertytextemphasiscolor_;
    ::blink::css_longhand::TextEmphasisPosition csspropertytextemphasisposition_;
    ::blink::css_longhand::TextEmphasisStyle csspropertytextemphasisstyle_;
    ::blink::css_longhand::TextIndent csspropertytextindent_;
    ::blink::css_longhand::TextOverflow csspropertytextoverflow_;
    ::blink::css_longhand::TextShadow csspropertytextshadow_;
    ::blink::css_longhand::TextTransform csspropertytexttransform_;
    ::blink::css_longhand::TextUnderlineOffset csspropertytextunderlineoffset_;
    ::blink::css_longhand::TextUnderlinePosition csspropertytextunderlineposition_;
    ::blink::css_longhand::TextWrapMode csspropertytextwrapmode_;
    ::blink::css_longhand::TextWrapStyle csspropertytextwrapstyle_;
    ::blink::css_longhand::TimelineScope csspropertytimelinescope_;
    ::blink::css_longhand::Top csspropertytop_;
    ::blink::css_longhand::TouchAction csspropertytouchaction_;
    ::blink::css_longhand::Transform csspropertytransform_;
    ::blink::css_longhand::TransformBox csspropertytransformbox_;
    ::blink::css_longhand::TransformOrigin csspropertytransformorigin_;
    ::blink::css_longhand::TransformStyle csspropertytransformstyle_;
    ::blink::css_longhand::TransitionBehavior csspropertytransitionbehavior_;
    ::blink::css_longhand::TransitionDelay csspropertytransitiondelay_;
    ::blink::css_longhand::TransitionDuration csspropertytransitionduration_;
    ::blink::css_longhand::TransitionProperty csspropertytransitionproperty_;
    ::blink::css_longhand::TransitionTimingFunction csspropertytransitiontimingfunction_;
    ::blink::css_longhand::Translate csspropertytranslate_;
    ::blink::css_longhand::Types csspropertytypes_;
    ::blink::css_longhand::UnicodeBidi csspropertyunicodebidi_;
    ::blink::css_longhand::UnicodeRange csspropertyunicoderange_;
    ::blink::css_longhand::UserSelect csspropertyuserselect_;
    ::blink::css_longhand::VectorEffect csspropertyvectoreffect_;
    ::blink::css_longhand::VerticalAlign csspropertyverticalalign_;
    ::blink::css_longhand::ViewTimelineAxis csspropertyviewtimelineaxis_;
    ::blink::css_longhand::ViewTimelineInset csspropertyviewtimelineinset_;
    ::blink::css_longhand::ViewTimelineName csspropertyviewtimelinename_;
    ::blink::css_longhand::ViewTransitionCaptureMode csspropertyviewtransitioncapturemode_;
    ::blink::css_longhand::ViewTransitionClass csspropertyviewtransitionclass_;
    ::blink::css_longhand::ViewTransitionGroup csspropertyviewtransitiongroup_;
    ::blink::css_longhand::ViewTransitionName csspropertyviewtransitionname_;
    ::blink::css_longhand::Visibility csspropertyvisibility_;
    ::blink::css_longhand::WebkitBorderHorizontalSpacing csspropertywebkitborderhorizontalspacing_;
    ::blink::css_longhand::WebkitBorderImage csspropertywebkitborderimage_;
    ::blink::css_longhand::WebkitBorderVerticalSpacing csspropertywebkitborderverticalspacing_;
    ::blink::css_longhand::WebkitBoxAlign csspropertywebkitboxalign_;
    ::blink::css_longhand::WebkitBoxDecorationBreak csspropertywebkitboxdecorationbreak_;
    ::blink::css_longhand::WebkitBoxDirection csspropertywebkitboxdirection_;
    ::blink::css_longhand::WebkitBoxFlex csspropertywebkitboxflex_;
    ::blink::css_longhand::WebkitBoxOrdinalGroup csspropertywebkitboxordinalgroup_;
    ::blink::css_longhand::WebkitBoxOrient csspropertywebkitboxorient_;
    ::blink::css_longhand::WebkitBoxPack csspropertywebkitboxpack_;
    ::blink::css_longhand::WebkitBoxReflect csspropertywebkitboxreflect_;
    ::blink::css_longhand::WebkitLineBreak csspropertywebkitlinebreak_;
    ::blink::css_longhand::WebkitLineClamp csspropertywebkitlineclamp_;
    ::blink::css_longhand::WebkitMaskBoxImageOutset csspropertywebkitmaskboximageoutset_;
    ::blink::css_longhand::WebkitMaskBoxImageRepeat csspropertywebkitmaskboximagerepeat_;
    ::blink::css_longhand::WebkitMaskBoxImageSlice csspropertywebkitmaskboximageslice_;
    ::blink::css_longhand::WebkitMaskBoxImageSource csspropertywebkitmaskboximagesource_;
    ::blink::css_longhand::WebkitMaskBoxImageWidth csspropertywebkitmaskboximagewidth_;
    ::blink::css_longhand::WebkitMaskPositionX csspropertywebkitmaskpositionx_;
    ::blink::css_longhand::WebkitMaskPositionY csspropertywebkitmaskpositiony_;
    ::blink::css_longhand::WebkitPerspectiveOriginX csspropertywebkitperspectiveoriginx_;
    ::blink::css_longhand::WebkitPerspectiveOriginY csspropertywebkitperspectiveoriginy_;
    ::blink::css_longhand::WebkitPrintColorAdjust csspropertywebkitprintcoloradjust_;
    ::blink::css_longhand::WebkitRtlOrdering csspropertywebkitrtlordering_;
    ::blink::css_longhand::WebkitRubyPosition csspropertywebkitrubyposition_;
    ::blink::css_longhand::WebkitTapHighlightColor csspropertywebkittaphighlightcolor_;
    ::blink::css_longhand::WebkitTextCombine csspropertywebkittextcombine_;
    ::blink::css_longhand::WebkitTextDecorationsInEffect csspropertywebkittextdecorationsineffect_;
    ::blink::css_longhand::WebkitTextFillColor csspropertywebkittextfillcolor_;
    ::blink::css_longhand::WebkitTextSecurity csspropertywebkittextsecurity_;
    ::blink::css_longhand::WebkitTextStrokeColor csspropertywebkittextstrokecolor_;
    ::blink::css_longhand::WebkitTextStrokeWidth csspropertywebkittextstrokewidth_;
    ::blink::css_longhand::WebkitTransformOriginX csspropertywebkittransformoriginx_;
    ::blink::css_longhand::WebkitTransformOriginY csspropertywebkittransformoriginy_;
    ::blink::css_longhand::WebkitTransformOriginZ csspropertywebkittransformoriginz_;
    ::blink::css_longhand::WebkitUserDrag csspropertywebkituserdrag_;
    ::blink::css_longhand::WebkitUserModify csspropertywebkitusermodify_;
    ::blink::css_longhand::WhiteSpaceCollapse csspropertywhitespacecollapse_;
    ::blink::css_longhand::Widows csspropertywidows_;
    ::blink::css_longhand::Width csspropertywidth_;
    ::blink::css_longhand::WillChange csspropertywillchange_;
    ::blink::css_longhand::WordBreak csspropertywordbreak_;
    ::blink::css_longhand::WordSpacing csspropertywordspacing_;
    ::blink::css_longhand::X csspropertyx_;
    ::blink::css_longhand::Y csspropertyy_;
    ::blink::css_longhand::ZIndex csspropertyzindex_;
    ::blink::css_shorthand::AlternativeAnimationWithTimeline csspropertyalternativeanimationwithtimeline_;
    ::blink::css_shorthand::Animation csspropertyanimation_;
    ::blink::css_shorthand::AnimationRange csspropertyanimationrange_;
    ::blink::css_shorthand::Background csspropertybackground_;
    ::blink::css_shorthand::BackgroundPosition csspropertybackgroundposition_;
    ::blink::css_shorthand::Border csspropertyborder_;
    ::blink::css_shorthand::BorderBlock csspropertyborderblock_;
    ::blink::css_shorthand::BorderBlockColor csspropertyborderblockcolor_;
    ::blink::css_shorthand::BorderBlockEnd csspropertyborderblockend_;
    ::blink::css_shorthand::BorderBlockStart csspropertyborderblockstart_;
    ::blink::css_shorthand::BorderBlockStyle csspropertyborderblockstyle_;
    ::blink::css_shorthand::BorderBlockWidth csspropertyborderblockwidth_;
    ::blink::css_shorthand::BorderBottom csspropertyborderbottom_;
    ::blink::css_shorthand::BorderColor csspropertybordercolor_;
    ::blink::css_shorthand::BorderImage csspropertyborderimage_;
    ::blink::css_shorthand::BorderInline csspropertyborderinline_;
    ::blink::css_shorthand::BorderInlineColor csspropertyborderinlinecolor_;
    ::blink::css_shorthand::BorderInlineEnd csspropertyborderinlineend_;
    ::blink::css_shorthand::BorderInlineStart csspropertyborderinlinestart_;
    ::blink::css_shorthand::BorderInlineStyle csspropertyborderinlinestyle_;
    ::blink::css_shorthand::BorderInlineWidth csspropertyborderinlinewidth_;
    ::blink::css_shorthand::BorderLeft csspropertyborderleft_;
    ::blink::css_shorthand::BorderRadius csspropertyborderradius_;
    ::blink::css_shorthand::BorderRight csspropertyborderright_;
    ::blink::css_shorthand::BorderSpacing csspropertyborderspacing_;
    ::blink::css_shorthand::BorderStyle csspropertyborderstyle_;
    ::blink::css_shorthand::BorderTop csspropertybordertop_;
    ::blink::css_shorthand::BorderWidth csspropertyborderwidth_;
    ::blink::css_shorthand::ColumnRule csspropertycolumnrule_;
    ::blink::css_shorthand::Columns csspropertycolumns_;
    ::blink::css_shorthand::ContainIntrinsicSize csspropertycontainintrinsicsize_;
    ::blink::css_shorthand::Container csspropertycontainer_;
    ::blink::css_shorthand::Flex csspropertyflex_;
    ::blink::css_shorthand::FlexFlow csspropertyflexflow_;
    ::blink::css_shorthand::Font csspropertyfont_;
    ::blink::css_shorthand::FontSynthesis csspropertyfontsynthesis_;
    ::blink::css_shorthand::FontVariant csspropertyfontvariant_;
    ::blink::css_shorthand::Gap csspropertygap_;
    ::blink::css_shorthand::Grid csspropertygrid_;
    ::blink::css_shorthand::GridArea csspropertygridarea_;
    ::blink::css_shorthand::GridColumn csspropertygridcolumn_;
    ::blink::css_shorthand::GridRow csspropertygridrow_;
    ::blink::css_shorthand::GridTemplate csspropertygridtemplate_;
    ::blink::css_shorthand::Inset csspropertyinset_;
    ::blink::css_shorthand::InsetBlock csspropertyinsetblock_;
    ::blink::css_shorthand::InsetInline csspropertyinsetinline_;
    ::blink::css_shorthand::ListStyle csspropertyliststyle_;
    ::blink::css_shorthand::Margin csspropertymargin_;
    ::blink::css_shorthand::MarginBlock csspropertymarginblock_;
    ::blink::css_shorthand::MarginInline csspropertymargininline_;
    ::blink::css_shorthand::Marker csspropertymarker_;
    ::blink::css_shorthand::Mask csspropertymask_;
    ::blink::css_shorthand::MaskPosition csspropertymaskposition_;
    ::blink::css_shorthand::MasonryTrack csspropertymasonrytrack_;
    ::blink::css_shorthand::Offset csspropertyoffset_;
    ::blink::css_shorthand::Outline csspropertyoutline_;
    ::blink::css_shorthand::Overflow csspropertyoverflow_;
    ::blink::css_shorthand::OverscrollBehavior csspropertyoverscrollbehavior_;
    ::blink::css_shorthand::Padding csspropertypadding_;
    ::blink::css_shorthand::PaddingBlock csspropertypaddingblock_;
    ::blink::css_shorthand::PaddingInline csspropertypaddinginline_;
    ::blink::css_shorthand::PageBreakAfter csspropertypagebreakafter_;
    ::blink::css_shorthand::PageBreakBefore csspropertypagebreakbefore_;
    ::blink::css_shorthand::PageBreakInside csspropertypagebreakinside_;
    ::blink::css_shorthand::PlaceContent csspropertyplacecontent_;
    ::blink::css_shorthand::PlaceItems csspropertyplaceitems_;
    ::blink::css_shorthand::PlaceSelf csspropertyplaceself_;
    ::blink::css_shorthand::PositionTry csspropertypositiontry_;
    ::blink::css_shorthand::ScrollMargin csspropertyscrollmargin_;
    ::blink::css_shorthand::ScrollMarginBlock csspropertyscrollmarginblock_;
    ::blink::css_shorthand::ScrollMarginInline csspropertyscrollmargininline_;
    ::blink::css_shorthand::ScrollPadding csspropertyscrollpadding_;
    ::blink::css_shorthand::ScrollPaddingBlock csspropertyscrollpaddingblock_;
    ::blink::css_shorthand::ScrollPaddingInline csspropertyscrollpaddinginline_;
    ::blink::css_shorthand::ScrollStart csspropertyscrollstart_;
    ::blink::css_shorthand::ScrollTimeline csspropertyscrolltimeline_;
    ::blink::css_shorthand::TextBox csspropertytextbox_;
    ::blink::css_shorthand::TextDecoration csspropertytextdecoration_;
    ::blink::css_shorthand::TextEmphasis csspropertytextemphasis_;
    ::blink::css_shorthand::TextSpacing csspropertytextspacing_;
    ::blink::css_shorthand::TextWrap csspropertytextwrap_;
    ::blink::css_shorthand::Transition csspropertytransition_;
    ::blink::css_shorthand::ViewTimeline csspropertyviewtimeline_;
    ::blink::css_shorthand::WebkitColumnBreakAfter csspropertywebkitcolumnbreakafter_;
    ::blink::css_shorthand::WebkitColumnBreakBefore csspropertywebkitcolumnbreakbefore_;
    ::blink::css_shorthand::WebkitColumnBreakInside csspropertywebkitcolumnbreakinside_;
    ::blink::css_shorthand::WebkitMaskBoxImage csspropertywebkitmaskboximage_;
    ::blink::css_shorthand::WebkitTextStroke csspropertywebkittextstroke_;
    ::blink::css_shorthand::WhiteSpace csspropertywhitespace_;
    ::blink::css_longhand::WebkitAppearance csspropertyaliaswebkitappearance_;
    ::blink::css_longhand::WebkitAppRegion csspropertyaliaswebkitappregion_;
    ::blink::css_longhand::WebkitMaskClip csspropertyaliaswebkitmaskclip_;
    ::blink::css_longhand::WebkitMaskComposite csspropertyaliaswebkitmaskcomposite_;
    ::blink::css_longhand::WebkitMaskImage csspropertyaliaswebkitmaskimage_;
    ::blink::css_longhand::WebkitMaskOrigin csspropertyaliaswebkitmaskorigin_;
    ::blink::css_longhand::WebkitMaskRepeat csspropertyaliaswebkitmaskrepeat_;
    ::blink::css_longhand::WebkitMaskSize csspropertyaliaswebkitmasksize_;
    ::blink::css_longhand::WebkitBorderEndColor csspropertyaliaswebkitborderendcolor_;
    ::blink::css_longhand::WebkitBorderEndStyle csspropertyaliaswebkitborderendstyle_;
    ::blink::css_longhand::WebkitBorderEndWidth csspropertyaliaswebkitborderendwidth_;
    ::blink::css_longhand::WebkitBorderStartColor csspropertyaliaswebkitborderstartcolor_;
    ::blink::css_longhand::WebkitBorderStartStyle csspropertyaliaswebkitborderstartstyle_;
    ::blink::css_longhand::WebkitBorderStartWidth csspropertyaliaswebkitborderstartwidth_;
    ::blink::css_longhand::WebkitBorderBeforeColor csspropertyaliaswebkitborderbeforecolor_;
    ::blink::css_longhand::WebkitBorderBeforeStyle csspropertyaliaswebkitborderbeforestyle_;
    ::blink::css_longhand::WebkitBorderBeforeWidth csspropertyaliaswebkitborderbeforewidth_;
    ::blink::css_longhand::WebkitBorderAfterColor csspropertyaliaswebkitborderaftercolor_;
    ::blink::css_longhand::WebkitBorderAfterStyle csspropertyaliaswebkitborderafterstyle_;
    ::blink::css_longhand::WebkitBorderAfterWidth csspropertyaliaswebkitborderafterwidth_;
    ::blink::css_longhand::WebkitMarginEnd csspropertyaliaswebkitmarginend_;
    ::blink::css_longhand::WebkitMarginStart csspropertyaliaswebkitmarginstart_;
    ::blink::css_longhand::WebkitMarginBefore csspropertyaliaswebkitmarginbefore_;
    ::blink::css_longhand::WebkitMarginAfter csspropertyaliaswebkitmarginafter_;
    ::blink::css_longhand::WebkitPaddingEnd csspropertyaliaswebkitpaddingend_;
    ::blink::css_longhand::WebkitPaddingStart csspropertyaliaswebkitpaddingstart_;
    ::blink::css_longhand::WebkitPaddingBefore csspropertyaliaswebkitpaddingbefore_;
    ::blink::css_longhand::WebkitPaddingAfter csspropertyaliaswebkitpaddingafter_;
    ::blink::css_longhand::WebkitLogicalWidth csspropertyaliaswebkitlogicalwidth_;
    ::blink::css_longhand::WebkitLogicalHeight csspropertyaliaswebkitlogicalheight_;
    ::blink::css_longhand::WebkitMinLogicalWidth csspropertyaliaswebkitminlogicalwidth_;
    ::blink::css_longhand::WebkitMinLogicalHeight csspropertyaliaswebkitminlogicalheight_;
    ::blink::css_longhand::WebkitMaxLogicalWidth csspropertyaliaswebkitmaxlogicalwidth_;
    ::blink::css_longhand::WebkitMaxLogicalHeight csspropertyaliaswebkitmaxlogicalheight_;
    ::blink::css_shorthand::WebkitBorderAfter csspropertyaliaswebkitborderafter_;
    ::blink::css_shorthand::WebkitBorderBefore csspropertyaliaswebkitborderbefore_;
    ::blink::css_shorthand::WebkitBorderEnd csspropertyaliaswebkitborderend_;
    ::blink::css_shorthand::WebkitBorderStart csspropertyaliaswebkitborderstart_;
    ::blink::css_shorthand::WebkitMask csspropertyaliaswebkitmask_;
    ::blink::css_shorthand::WebkitMaskPosition csspropertyaliaswebkitmaskposition_;
    ::blink::css_longhand::EpubCaptionSide csspropertyaliasepubcaptionside_;
    ::blink::css_longhand::EpubTextCombine csspropertyaliasepubtextcombine_;
    ::blink::css_shorthand::EpubTextEmphasis csspropertyaliasepubtextemphasis_;
    ::blink::css_longhand::EpubTextEmphasisColor csspropertyaliasepubtextemphasiscolor_;
    ::blink::css_longhand::EpubTextEmphasisStyle csspropertyaliasepubtextemphasisstyle_;
    ::blink::css_longhand::EpubTextOrientation csspropertyaliasepubtextorientation_;
    ::blink::css_longhand::EpubTextTransform csspropertyaliasepubtexttransform_;
    ::blink::css_longhand::EpubWordBreak csspropertyaliasepubwordbreak_;
    ::blink::css_longhand::EpubWritingMode csspropertyaliasepubwritingmode_;
    ::blink::css_longhand::WebkitAlignContent csspropertyaliaswebkitaligncontent_;
    ::blink::css_longhand::WebkitAlignItems csspropertyaliaswebkitalignitems_;
    ::blink::css_longhand::WebkitAlignSelf csspropertyaliaswebkitalignself_;
    ::blink::css_shorthand::WebkitAnimation csspropertyaliaswebkitanimation_;
    ::blink::css_shorthand::WebkitAlternativeAnimationWithTimeline csspropertyaliaswebkitalternativeanimationwithtimeline_;
    ::blink::css_longhand::WebkitAnimationDelay csspropertyaliaswebkitanimationdelay_;
    ::blink::css_longhand::WebkitAnimationDirection csspropertyaliaswebkitanimationdirection_;
    ::blink::css_longhand::WebkitAnimationDuration csspropertyaliaswebkitanimationduration_;
    ::blink::css_longhand::WebkitAnimationFillMode csspropertyaliaswebkitanimationfillmode_;
    ::blink::css_longhand::WebkitAnimationIterationCount csspropertyaliaswebkitanimationiterationcount_;
    ::blink::css_longhand::WebkitAnimationName csspropertyaliaswebkitanimationname_;
    ::blink::css_longhand::WebkitAnimationPlayState csspropertyaliaswebkitanimationplaystate_;
    ::blink::css_longhand::WebkitAnimationTimingFunction csspropertyaliaswebkitanimationtimingfunction_;
    ::blink::css_longhand::WebkitBackfaceVisibility csspropertyaliaswebkitbackfacevisibility_;
    ::blink::css_longhand::WebkitBackgroundClip csspropertyaliaswebkitbackgroundclip_;
    ::blink::css_longhand::WebkitBackgroundOrigin csspropertyaliaswebkitbackgroundorigin_;
    ::blink::css_longhand::WebkitBackgroundSize csspropertyaliaswebkitbackgroundsize_;
    ::blink::css_longhand::WebkitBorderBottomLeftRadius csspropertyaliaswebkitborderbottomleftradius_;
    ::blink::css_longhand::WebkitBorderBottomRightRadius csspropertyaliaswebkitborderbottomrightradius_;
    ::blink::css_shorthand::WebkitBorderRadius csspropertyaliaswebkitborderradius_;
    ::blink::css_longhand::WebkitBorderTopLeftRadius csspropertyaliaswebkitbordertopleftradius_;
    ::blink::css_longhand::WebkitBorderTopRightRadius csspropertyaliaswebkitbordertoprightradius_;
    ::blink::css_longhand::WebkitBoxShadow csspropertyaliaswebkitboxshadow_;
    ::blink::css_longhand::WebkitBoxSizing csspropertyaliaswebkitboxsizing_;
    ::blink::css_longhand::WebkitClipPath csspropertyaliaswebkitclippath_;
    ::blink::css_longhand::WebkitColumnCount csspropertyaliaswebkitcolumncount_;
    ::blink::css_longhand::WebkitColumnGap csspropertyaliaswebkitcolumngap_;
    ::blink::css_shorthand::WebkitColumnRule csspropertyaliaswebkitcolumnrule_;
    ::blink::css_longhand::WebkitColumnRuleColor csspropertyaliaswebkitcolumnrulecolor_;
    ::blink::css_longhand::WebkitColumnRuleStyle csspropertyaliaswebkitcolumnrulestyle_;
    ::blink::css_longhand::WebkitColumnRuleWidth csspropertyaliaswebkitcolumnrulewidth_;
    ::blink::css_longhand::WebkitColumnSpan csspropertyaliaswebkitcolumnspan_;
    ::blink::css_longhand::WebkitColumnWidth csspropertyaliaswebkitcolumnwidth_;
    ::blink::css_shorthand::WebkitColumns csspropertyaliaswebkitcolumns_;
    ::blink::css_longhand::WebkitFilter csspropertyaliaswebkitfilter_;
    ::blink::css_shorthand::WebkitFlex csspropertyaliaswebkitflex_;
    ::blink::css_longhand::WebkitFlexBasis csspropertyaliaswebkitflexbasis_;
    ::blink::css_longhand::WebkitFlexDirection csspropertyaliaswebkitflexdirection_;
    ::blink::css_shorthand::WebkitFlexFlow csspropertyaliaswebkitflexflow_;
    ::blink::css_longhand::WebkitFlexGrow csspropertyaliaswebkitflexgrow_;
    ::blink::css_longhand::WebkitFlexShrink csspropertyaliaswebkitflexshrink_;
    ::blink::css_longhand::WebkitFlexWrap csspropertyaliaswebkitflexwrap_;
    ::blink::css_longhand::WebkitFontFeatureSettings csspropertyaliaswebkitfontfeaturesettings_;
    ::blink::css_longhand::WebkitHyphenateCharacter csspropertyaliaswebkithyphenatecharacter_;
    ::blink::css_longhand::WebkitJustifyContent csspropertyaliaswebkitjustifycontent_;
    ::blink::css_longhand::WebkitOpacity csspropertyaliaswebkitopacity_;
    ::blink::css_longhand::WebkitOrder csspropertyaliaswebkitorder_;
    ::blink::css_longhand::WebkitPerspective csspropertyaliaswebkitperspective_;
    ::blink::css_longhand::WebkitPerspectiveOrigin csspropertyaliaswebkitperspectiveorigin_;
    ::blink::css_longhand::WebkitShapeImageThreshold csspropertyaliaswebkitshapeimagethreshold_;
    ::blink::css_longhand::WebkitShapeMargin csspropertyaliaswebkitshapemargin_;
    ::blink::css_longhand::WebkitShapeOutside csspropertyaliaswebkitshapeoutside_;
    ::blink::css_shorthand::WebkitTextEmphasis csspropertyaliaswebkittextemphasis_;
    ::blink::css_longhand::WebkitTextEmphasisColor csspropertyaliaswebkittextemphasiscolor_;
    ::blink::css_longhand::WebkitTextEmphasisPosition csspropertyaliaswebkittextemphasisposition_;
    ::blink::css_longhand::WebkitTextEmphasisStyle csspropertyaliaswebkittextemphasisstyle_;
    ::blink::css_longhand::WebkitTextSizeAdjust csspropertyaliaswebkittextsizeadjust_;
    ::blink::css_longhand::WebkitTransform csspropertyaliaswebkittransform_;
    ::blink::css_longhand::WebkitTransformOrigin csspropertyaliaswebkittransformorigin_;
    ::blink::css_longhand::WebkitTransformStyle csspropertyaliaswebkittransformstyle_;
    ::blink::css_shorthand::WebkitTransition csspropertyaliaswebkittransition_;
    ::blink::css_longhand::WebkitTransitionDelay csspropertyaliaswebkittransitiondelay_;
    ::blink::css_longhand::WebkitTransitionDuration csspropertyaliaswebkittransitionduration_;
    ::blink::css_longhand::WebkitTransitionProperty csspropertyaliaswebkittransitionproperty_;
    ::blink::css_longhand::WebkitTransitionTimingFunction csspropertyaliaswebkittransitiontimingfunction_;
    ::blink::css_longhand::WebkitUserSelect csspropertyaliaswebkituserselect_;
    ::blink::css_longhand::WordWrap csspropertyaliaswordwrap_;
    ::blink::css_longhand::GridColumnGap csspropertyaliasgridcolumngap_;
    ::blink::css_longhand::GridRowGap csspropertyaliasgridrowgap_;
    ::blink::css_shorthand::GridGap csspropertyaliasgridgap_;
};
static_assert(sizeof(CSSPropertyUnion) == kCSSPropertyUnionBytes);

const CSSPropertyUnion kCssProperties[] = {
    {}, // kInvalid.
    Variable(),
    ::blink::css_longhand::ColorScheme(),
    ::blink::css_longhand::ForcedColorAdjust(),
    ::blink::css_longhand::MaskImage(),
    ::blink::css_longhand::MathDepth(),
    ::blink::css_longhand::Position(),
    ::blink::css_longhand::PositionAnchor(),
    ::blink::css_longhand::TextSizeAdjust(),
    ::blink::css_longhand::Appearance(),
    ::blink::css_longhand::Color(),
    ::blink::css_longhand::Direction(),
    ::blink::css_longhand::FontFamily(),
    ::blink::css_longhand::FontFeatureSettings(),
    ::blink::css_longhand::FontKerning(),
    ::blink::css_longhand::FontOpticalSizing(),
    ::blink::css_longhand::FontPalette(),
    ::blink::css_longhand::FontSize(),
    ::blink::css_longhand::FontSizeAdjust(),
    ::blink::css_longhand::FontStretch(),
    ::blink::css_longhand::FontStyle(),
    ::blink::css_longhand::FontSynthesisSmallCaps(),
    ::blink::css_longhand::FontSynthesisStyle(),
    ::blink::css_longhand::FontSynthesisWeight(),
    ::blink::css_longhand::FontVariantAlternates(),
    ::blink::css_longhand::FontVariantCaps(),
    ::blink::css_longhand::FontVariantEastAsian(),
    ::blink::css_longhand::FontVariantEmoji(),
    ::blink::css_longhand::FontVariantLigatures(),
    ::blink::css_longhand::FontVariantNumeric(),
    ::blink::css_longhand::FontVariantPosition(),
    ::blink::css_longhand::FontVariationSettings(),
    ::blink::css_longhand::FontWeight(),
    ::blink::css_longhand::InsetArea(),
    ::blink::css_longhand::InternalVisitedColor(),
    ::blink::css_longhand::PositionArea(),
    ::blink::css_longhand::TextOrientation(),
    ::blink::css_longhand::TextRendering(),
    ::blink::css_longhand::TextSpacingTrim(),
    ::blink::css_longhand::WebkitFontSmoothing(),
    ::blink::css_longhand::WebkitLocale(),
    ::blink::css_longhand::WebkitTextOrientation(),
    ::blink::css_longhand::WebkitWritingMode(),
    ::blink::css_longhand::WritingMode(),
    ::blink::css_longhand::Zoom(),
    ::blink::css_longhand::AccentColor(),
    ::blink::css_longhand::AdditiveSymbols(),
    ::blink::css_longhand::AlignContent(),
    ::blink::css_longhand::AlignItems(),
    ::blink::css_longhand::AlignSelf(),
    ::blink::css_longhand::AlignmentBaseline(),
    ::blink::css_longhand::All(),
    ::blink::css_longhand::AnchorName(),
    ::blink::css_longhand::AnchorScope(),
    ::blink::css_longhand::AnimationComposition(),
    ::blink::css_longhand::AnimationDelay(),
    ::blink::css_longhand::AnimationDirection(),
    ::blink::css_longhand::AnimationDuration(),
    ::blink::css_longhand::AnimationFillMode(),
    ::blink::css_longhand::AnimationIterationCount(),
    ::blink::css_longhand::AnimationName(),
    ::blink::css_longhand::AnimationPlayState(),
    ::blink::css_longhand::AnimationRangeEnd(),
    ::blink::css_longhand::AnimationRangeStart(),
    ::blink::css_longhand::AnimationTimeline(),
    ::blink::css_longhand::AnimationTimingFunction(),
    ::blink::css_longhand::AppRegion(),
    ::blink::css_longhand::AscentOverride(),
    ::blink::css_longhand::AspectRatio(),
    ::blink::css_longhand::BackdropFilter(),
    ::blink::css_longhand::BackfaceVisibility(),
    ::blink::css_longhand::BackgroundAttachment(),
    ::blink::css_longhand::BackgroundBlendMode(),
    ::blink::css_longhand::BackgroundClip(),
    ::blink::css_longhand::BackgroundColor(),
    ::blink::css_longhand::BackgroundImage(),
    ::blink::css_longhand::BackgroundOrigin(),
    ::blink::css_longhand::BackgroundPositionX(),
    ::blink::css_longhand::BackgroundPositionY(),
    ::blink::css_longhand::BackgroundRepeat(),
    ::blink::css_longhand::BackgroundSize(),
    ::blink::css_longhand::BasePalette(),
    ::blink::css_longhand::BaselineShift(),
    ::blink::css_longhand::BaselineSource(),
    ::blink::css_longhand::BlockSize(),
    ::blink::css_longhand::BorderBlockEndColor(),
    ::blink::css_longhand::BorderBlockEndStyle(),
    ::blink::css_longhand::BorderBlockEndWidth(),
    ::blink::css_longhand::BorderBlockStartColor(),
    ::blink::css_longhand::BorderBlockStartStyle(),
    ::blink::css_longhand::BorderBlockStartWidth(),
    ::blink::css_longhand::BorderBottomColor(),
    ::blink::css_longhand::BorderBottomLeftRadius(),
    ::blink::css_longhand::BorderBottomRightRadius(),
    ::blink::css_longhand::BorderBottomStyle(),
    ::blink::css_longhand::BorderBottomWidth(),
    ::blink::css_longhand::BorderCollapse(),
    ::blink::css_longhand::BorderEndEndRadius(),
    ::blink::css_longhand::BorderEndStartRadius(),
    ::blink::css_longhand::BorderImageOutset(),
    ::blink::css_longhand::BorderImageRepeat(),
    ::blink::css_longhand::BorderImageSlice(),
    ::blink::css_longhand::BorderImageSource(),
    ::blink::css_longhand::BorderImageWidth(),
    ::blink::css_longhand::BorderInlineEndColor(),
    ::blink::css_longhand::BorderInlineEndStyle(),
    ::blink::css_longhand::BorderInlineEndWidth(),
    ::blink::css_longhand::BorderInlineStartColor(),
    ::blink::css_longhand::BorderInlineStartStyle(),
    ::blink::css_longhand::BorderInlineStartWidth(),
    ::blink::css_longhand::BorderLeftColor(),
    ::blink::css_longhand::BorderLeftStyle(),
    ::blink::css_longhand::BorderLeftWidth(),
    ::blink::css_longhand::BorderRightColor(),
    ::blink::css_longhand::BorderRightStyle(),
    ::blink::css_longhand::BorderRightWidth(),
    ::blink::css_longhand::BorderStartEndRadius(),
    ::blink::css_longhand::BorderStartStartRadius(),
    ::blink::css_longhand::BorderTopColor(),
    ::blink::css_longhand::BorderTopLeftRadius(),
    ::blink::css_longhand::BorderTopRightRadius(),
    ::blink::css_longhand::BorderTopStyle(),
    ::blink::css_longhand::BorderTopWidth(),
    ::blink::css_longhand::Bottom(),
    ::blink::css_longhand::BoxDecorationBreak(),
    ::blink::css_longhand::BoxShadow(),
    ::blink::css_longhand::BoxSizing(),
    ::blink::css_longhand::BreakAfter(),
    ::blink::css_longhand::BreakBefore(),
    ::blink::css_longhand::BreakInside(),
    ::blink::css_longhand::BufferedRendering(),
    ::blink::css_longhand::CaptionSide(),
    ::blink::css_longhand::CaretAnimation(),
    ::blink::css_longhand::CaretColor(),
    ::blink::css_longhand::Clear(),
    ::blink::css_longhand::Clip(),
    ::blink::css_longhand::ClipPath(),
    ::blink::css_longhand::ClipRule(),
    ::blink::css_longhand::ColorInterpolation(),
    ::blink::css_longhand::ColorInterpolationFilters(),
    ::blink::css_longhand::ColorRendering(),
    ::blink::css_longhand::ColumnCount(),
    ::blink::css_longhand::ColumnFill(),
    ::blink::css_longhand::ColumnGap(),
    ::blink::css_longhand::ColumnRuleColor(),
    ::blink::css_longhand::ColumnRuleStyle(),
    ::blink::css_longhand::ColumnRuleWidth(),
    ::blink::css_longhand::ColumnSpan(),
    ::blink::css_longhand::ColumnWidth(),
    ::blink::css_longhand::Contain(),
    ::blink::css_longhand::ContainIntrinsicBlockSize(),
    ::blink::css_longhand::ContainIntrinsicHeight(),
    ::blink::css_longhand::ContainIntrinsicInlineSize(),
    ::blink::css_longhand::ContainIntrinsicWidth(),
    ::blink::css_longhand::ContainerName(),
    ::blink::css_longhand::ContainerType(),
    ::blink::css_longhand::Content(),
    ::blink::css_longhand::ContentVisibility(),
    ::blink::css_longhand::CounterIncrement(),
    ::blink::css_longhand::CounterReset(),
    ::blink::css_longhand::CounterSet(),
    ::blink::css_longhand::Cursor(),
    ::blink::css_longhand::Cx(),
    ::blink::css_longhand::Cy(),
    ::blink::css_longhand::D(),
    ::blink::css_longhand::DescentOverride(),
    ::blink::css_longhand::Display(),
    ::blink::css_longhand::DominantBaseline(),
    ::blink::css_longhand::DynamicRangeLimit(),
    ::blink::css_longhand::EmptyCells(),
    ::blink::css_longhand::Fallback(),
    ::blink::css_longhand::FieldSizing(),
    ::blink::css_longhand::Fill(),
    ::blink::css_longhand::FillOpacity(),
    ::blink::css_longhand::FillRule(),
    ::blink::css_longhand::Filter(),
    ::blink::css_longhand::FlexBasis(),
    ::blink::css_longhand::FlexDirection(),
    ::blink::css_longhand::FlexGrow(),
    ::blink::css_longhand::FlexShrink(),
    ::blink::css_longhand::FlexWrap(),
    ::blink::css_longhand::Float(),
    ::blink::css_longhand::FloodColor(),
    ::blink::css_longhand::FloodOpacity(),
    ::blink::css_longhand::FontDisplay(),
    ::blink::css_longhand::GridAutoColumns(),
    ::blink::css_longhand::GridAutoFlow(),
    ::blink::css_longhand::GridAutoRows(),
    ::blink::css_longhand::GridColumnEnd(),
    ::blink::css_longhand::GridColumnStart(),
    ::blink::css_longhand::GridRowEnd(),
    ::blink::css_longhand::GridRowStart(),
    ::blink::css_longhand::GridTemplateAreas(),
    ::blink::css_longhand::GridTemplateColumns(),
    ::blink::css_longhand::GridTemplateRows(),
    ::blink::css_longhand::Height(),
    ::blink::css_longhand::HyphenateCharacter(),
    ::blink::css_longhand::HyphenateLimitChars(),
    ::blink::css_longhand::Hyphens(),
    ::blink::css_longhand::ImageOrientation(),
    ::blink::css_longhand::ImageRendering(),
    ::blink::css_longhand::Inherits(),
    ::blink::css_longhand::InitialLetter(),
    ::blink::css_longhand::InitialValue(),
    ::blink::css_longhand::InlineSize(),
    ::blink::css_longhand::InsetBlockEnd(),
    ::blink::css_longhand::InsetBlockStart(),
    ::blink::css_longhand::InsetInlineEnd(),
    ::blink::css_longhand::InsetInlineStart(),
    ::blink::css_longhand::Interactivity(),
    ::blink::css_longhand::InternalAlignContentBlock(),
    ::blink::css_longhand::InternalEmptyLineHeight(),
    ::blink::css_longhand::InternalFontSizeDelta(),
    ::blink::css_longhand::InternalForcedBackgroundColor(),
    ::blink::css_longhand::InternalForcedBorderColor(),
    ::blink::css_longhand::InternalForcedColor(),
    ::blink::css_longhand::InternalForcedOutlineColor(),
    ::blink::css_longhand::InternalForcedVisitedColor(),
    ::blink::css_longhand::InternalOverflowBlock(),
    ::blink::css_longhand::InternalOverflowInline(),
    ::blink::css_longhand::InternalVisitedBackgroundColor(),
    ::blink::css_longhand::InternalVisitedBorderBlockEndColor(),
    ::blink::css_longhand::InternalVisitedBorderBlockStartColor(),
    ::blink::css_longhand::InternalVisitedBorderBottomColor(),
    ::blink::css_longhand::InternalVisitedBorderInlineEndColor(),
    ::blink::css_longhand::InternalVisitedBorderInlineStartColor(),
    ::blink::css_longhand::InternalVisitedBorderLeftColor(),
    ::blink::css_longhand::InternalVisitedBorderRightColor(),
    ::blink::css_longhand::InternalVisitedBorderTopColor(),
    ::blink::css_longhand::InternalVisitedCaretColor(),
    ::blink::css_longhand::InternalVisitedColumnRuleColor(),
    ::blink::css_longhand::InternalVisitedFill(),
    ::blink::css_longhand::InternalVisitedOutlineColor(),
    ::blink::css_longhand::InternalVisitedStroke(),
    ::blink::css_longhand::InternalVisitedTextDecorationColor(),
    ::blink::css_longhand::InternalVisitedTextEmphasisColor(),
    ::blink::css_longhand::InternalVisitedTextFillColor(),
    ::blink::css_longhand::InternalVisitedTextStrokeColor(),
    ::blink::css_longhand::InterpolateSize(),
    ::blink::css_longhand::Isolation(),
    ::blink::css_longhand::JustifyContent(),
    ::blink::css_longhand::JustifyItems(),
    ::blink::css_longhand::JustifySelf(),
    ::blink::css_longhand::Left(),
    ::blink::css_longhand::LetterSpacing(),
    ::blink::css_longhand::LightingColor(),
    ::blink::css_longhand::LineBreak(),
    ::blink::css_longhand::LineClamp(),
    ::blink::css_longhand::LineGapOverride(),
    ::blink::css_longhand::LineHeight(),
    ::blink::css_longhand::ListStyleImage(),
    ::blink::css_longhand::ListStylePosition(),
    ::blink::css_longhand::ListStyleType(),
    ::blink::css_longhand::MarginBlockEnd(),
    ::blink::css_longhand::MarginBlockStart(),
    ::blink::css_longhand::MarginBottom(),
    ::blink::css_longhand::MarginInlineEnd(),
    ::blink::css_longhand::MarginInlineStart(),
    ::blink::css_longhand::MarginLeft(),
    ::blink::css_longhand::MarginRight(),
    ::blink::css_longhand::MarginTop(),
    ::blink::css_longhand::MarkerEnd(),
    ::blink::css_longhand::MarkerMid(),
    ::blink::css_longhand::MarkerStart(),
    ::blink::css_longhand::MaskClip(),
    ::blink::css_longhand::MaskComposite(),
    ::blink::css_longhand::MaskMode(),
    ::blink::css_longhand::MaskOrigin(),
    ::blink::css_longhand::MaskRepeat(),
    ::blink::css_longhand::MaskSize(),
    ::blink::css_longhand::MaskType(),
    ::blink::css_longhand::MasonrySlack(),
    ::blink::css_longhand::MasonryTemplateTracks(),
    ::blink::css_longhand::MasonryTrackEnd(),
    ::blink::css_longhand::MasonryTrackStart(),
    ::blink::css_longhand::MathShift(),
    ::blink::css_longhand::MathStyle(),
    ::blink::css_longhand::MaxBlockSize(),
    ::blink::css_longhand::MaxHeight(),
    ::blink::css_longhand::MaxInlineSize(),
    ::blink::css_longhand::MaxWidth(),
    ::blink::css_longhand::MinBlockSize(),
    ::blink::css_longhand::MinHeight(),
    ::blink::css_longhand::MinInlineSize(),
    ::blink::css_longhand::MinWidth(),
    ::blink::css_longhand::MixBlendMode(),
    ::blink::css_longhand::Navigation(),
    ::blink::css_longhand::Negative(),
    ::blink::css_longhand::ObjectFit(),
    ::blink::css_longhand::ObjectPosition(),
    ::blink::css_longhand::ObjectViewBox(),
    ::blink::css_longhand::OffsetAnchor(),
    ::blink::css_longhand::OffsetDistance(),
    ::blink::css_longhand::OffsetPath(),
    ::blink::css_longhand::OffsetPosition(),
    ::blink::css_longhand::OffsetRotate(),
    ::blink::css_longhand::Opacity(),
    ::blink::css_longhand::Order(),
    ::blink::css_longhand::OriginTrialTestProperty(),
    ::blink::css_longhand::Orphans(),
    ::blink::css_longhand::OutlineColor(),
    ::blink::css_longhand::OutlineOffset(),
    ::blink::css_longhand::OutlineStyle(),
    ::blink::css_longhand::OutlineWidth(),
    ::blink::css_longhand::OverflowAnchor(),
    ::blink::css_longhand::OverflowBlock(),
    ::blink::css_longhand::OverflowClipMargin(),
    ::blink::css_longhand::OverflowInline(),
    ::blink::css_longhand::OverflowWrap(),
    ::blink::css_longhand::OverflowX(),
    ::blink::css_longhand::OverflowY(),
    ::blink::css_longhand::Overlay(),
    ::blink::css_longhand::OverrideColors(),
    ::blink::css_longhand::OverscrollBehaviorBlock(),
    ::blink::css_longhand::OverscrollBehaviorInline(),
    ::blink::css_longhand::OverscrollBehaviorX(),
    ::blink::css_longhand::OverscrollBehaviorY(),
    ::blink::css_longhand::Pad(),
    ::blink::css_longhand::PaddingBlockEnd(),
    ::blink::css_longhand::PaddingBlockStart(),
    ::blink::css_longhand::PaddingBottom(),
    ::blink::css_longhand::PaddingInlineEnd(),
    ::blink::css_longhand::PaddingInlineStart(),
    ::blink::css_longhand::PaddingLeft(),
    ::blink::css_longhand::PaddingRight(),
    ::blink::css_longhand::PaddingTop(),
    ::blink::css_longhand::Page(),
    ::blink::css_longhand::PageOrientation(),
    ::blink::css_longhand::PaintOrder(),
    ::blink::css_longhand::Perspective(),
    ::blink::css_longhand::PerspectiveOrigin(),
    ::blink::css_longhand::PointerEvents(),
    ::blink::css_longhand::PopoverHideDelay(),
    ::blink::css_longhand::PopoverShowDelay(),
    ::blink::css_longhand::PositionTryFallbacks(),
    ::blink::css_longhand::PositionTryOrder(),
    ::blink::css_longhand::PositionVisibility(),
    ::blink::css_longhand::Prefix(),
    ::blink::css_longhand::Quotes(),
    ::blink::css_longhand::R(),
    ::blink::css_longhand::Range(),
    ::blink::css_longhand::ReadingFlow(),
    ::blink::css_longhand::Resize(),
    ::blink::css_longhand::Right(),
    ::blink::css_longhand::Rotate(),
    ::blink::css_longhand::RowGap(),
    ::blink::css_longhand::RubyAlign(),
    ::blink::css_longhand::RubyPosition(),
    ::blink::css_longhand::Rx(),
    ::blink::css_longhand::Ry(),
    ::blink::css_longhand::Scale(),
    ::blink::css_longhand::ScrollBehavior(),
    ::blink::css_longhand::ScrollMarginBlockEnd(),
    ::blink::css_longhand::ScrollMarginBlockStart(),
    ::blink::css_longhand::ScrollMarginBottom(),
    ::blink::css_longhand::ScrollMarginInlineEnd(),
    ::blink::css_longhand::ScrollMarginInlineStart(),
    ::blink::css_longhand::ScrollMarginLeft(),
    ::blink::css_longhand::ScrollMarginRight(),
    ::blink::css_longhand::ScrollMarginTop(),
    ::blink::css_longhand::ScrollMarkerGroup(),
    ::blink::css_longhand::ScrollPaddingBlockEnd(),
    ::blink::css_longhand::ScrollPaddingBlockStart(),
    ::blink::css_longhand::ScrollPaddingBottom(),
    ::blink::css_longhand::ScrollPaddingInlineEnd(),
    ::blink::css_longhand::ScrollPaddingInlineStart(),
    ::blink::css_longhand::ScrollPaddingLeft(),
    ::blink::css_longhand::ScrollPaddingRight(),
    ::blink::css_longhand::ScrollPaddingTop(),
    ::blink::css_longhand::ScrollSnapAlign(),
    ::blink::css_longhand::ScrollSnapStop(),
    ::blink::css_longhand::ScrollSnapType(),
    ::blink::css_longhand::ScrollStartBlock(),
    ::blink::css_longhand::ScrollStartInline(),
    ::blink::css_longhand::ScrollStartTarget(),
    ::blink::css_longhand::ScrollStartX(),
    ::blink::css_longhand::ScrollStartY(),
    ::blink::css_longhand::ScrollTimelineAxis(),
    ::blink::css_longhand::ScrollTimelineName(),
    ::blink::css_longhand::ScrollbarColor(),
    ::blink::css_longhand::ScrollbarGutter(),
    ::blink::css_longhand::ScrollbarWidth(),
    ::blink::css_longhand::ShapeImageThreshold(),
    ::blink::css_longhand::ShapeMargin(),
    ::blink::css_longhand::ShapeOutside(),
    ::blink::css_longhand::ShapeRendering(),
    ::blink::css_longhand::Size(),
    ::blink::css_longhand::SizeAdjust(),
    ::blink::css_longhand::Speak(),
    ::blink::css_longhand::SpeakAs(),
    ::blink::css_longhand::Src(),
    ::blink::css_longhand::StopColor(),
    ::blink::css_longhand::StopOpacity(),
    ::blink::css_longhand::Stroke(),
    ::blink::css_longhand::StrokeDasharray(),
    ::blink::css_longhand::StrokeDashoffset(),
    ::blink::css_longhand::StrokeLinecap(),
    ::blink::css_longhand::StrokeLinejoin(),
    ::blink::css_longhand::StrokeMiterlimit(),
    ::blink::css_longhand::StrokeOpacity(),
    ::blink::css_longhand::StrokeWidth(),
    ::blink::css_longhand::Suffix(),
    ::blink::css_longhand::Symbols(),
    ::blink::css_longhand::Syntax(),
    ::blink::css_longhand::System(),
    ::blink::css_longhand::TabSize(),
    ::blink::css_longhand::TableLayout(),
    ::blink::css_longhand::TextAlign(),
    ::blink::css_longhand::TextAlignLast(),
    ::blink::css_longhand::TextAnchor(),
    ::blink::css_longhand::TextAutospace(),
    ::blink::css_longhand::TextBoxEdge(),
    ::blink::css_longhand::TextBoxTrim(),
    ::blink::css_longhand::TextCombineUpright(),
    ::blink::css_longhand::TextDecorationColor(),
    ::blink::css_longhand::TextDecorationLine(),
    ::blink::css_longhand::TextDecorationSkipInk(),
    ::blink::css_longhand::TextDecorationStyle(),
    ::blink::css_longhand::TextDecorationThickness(),
    ::blink::css_longhand::TextEmphasisColor(),
    ::blink::css_longhand::TextEmphasisPosition(),
    ::blink::css_longhand::TextEmphasisStyle(),
    ::blink::css_longhand::TextIndent(),
    ::blink::css_longhand::TextOverflow(),
    ::blink::css_longhand::TextShadow(),
    ::blink::css_longhand::TextTransform(),
    ::blink::css_longhand::TextUnderlineOffset(),
    ::blink::css_longhand::TextUnderlinePosition(),
    ::blink::css_longhand::TextWrapMode(),
    ::blink::css_longhand::TextWrapStyle(),
    ::blink::css_longhand::TimelineScope(),
    ::blink::css_longhand::Top(),
    ::blink::css_longhand::TouchAction(),
    ::blink::css_longhand::Transform(),
    ::blink::css_longhand::TransformBox(),
    ::blink::css_longhand::TransformOrigin(),
    ::blink::css_longhand::TransformStyle(),
    ::blink::css_longhand::TransitionBehavior(),
    ::blink::css_longhand::TransitionDelay(),
    ::blink::css_longhand::TransitionDuration(),
    ::blink::css_longhand::TransitionProperty(),
    ::blink::css_longhand::TransitionTimingFunction(),
    ::blink::css_longhand::Translate(),
    ::blink::css_longhand::Types(),
    ::blink::css_longhand::UnicodeBidi(),
    ::blink::css_longhand::UnicodeRange(),
    ::blink::css_longhand::UserSelect(),
    ::blink::css_longhand::VectorEffect(),
    ::blink::css_longhand::VerticalAlign(),
    ::blink::css_longhand::ViewTimelineAxis(),
    ::blink::css_longhand::ViewTimelineInset(),
    ::blink::css_longhand::ViewTimelineName(),
    ::blink::css_longhand::ViewTransitionCaptureMode(),
    ::blink::css_longhand::ViewTransitionClass(),
    ::blink::css_longhand::ViewTransitionGroup(),
    ::blink::css_longhand::ViewTransitionName(),
    ::blink::css_longhand::Visibility(),
    ::blink::css_longhand::WebkitBorderHorizontalSpacing(),
    ::blink::css_longhand::WebkitBorderImage(),
    ::blink::css_longhand::WebkitBorderVerticalSpacing(),
    ::blink::css_longhand::WebkitBoxAlign(),
    ::blink::css_longhand::WebkitBoxDecorationBreak(),
    ::blink::css_longhand::WebkitBoxDirection(),
    ::blink::css_longhand::WebkitBoxFlex(),
    ::blink::css_longhand::WebkitBoxOrdinalGroup(),
    ::blink::css_longhand::WebkitBoxOrient(),
    ::blink::css_longhand::WebkitBoxPack(),
    ::blink::css_longhand::WebkitBoxReflect(),
    ::blink::css_longhand::WebkitLineBreak(),
    ::blink::css_longhand::WebkitLineClamp(),
    ::blink::css_longhand::WebkitMaskBoxImageOutset(),
    ::blink::css_longhand::WebkitMaskBoxImageRepeat(),
    ::blink::css_longhand::WebkitMaskBoxImageSlice(),
    ::blink::css_longhand::WebkitMaskBoxImageSource(),
    ::blink::css_longhand::WebkitMaskBoxImageWidth(),
    ::blink::css_longhand::WebkitMaskPositionX(),
    ::blink::css_longhand::WebkitMaskPositionY(),
    ::blink::css_longhand::WebkitPerspectiveOriginX(),
    ::blink::css_longhand::WebkitPerspectiveOriginY(),
    ::blink::css_longhand::WebkitPrintColorAdjust(),
    ::blink::css_longhand::WebkitRtlOrdering(),
    ::blink::css_longhand::WebkitRubyPosition(),
    ::blink::css_longhand::WebkitTapHighlightColor(),
    ::blink::css_longhand::WebkitTextCombine(),
    ::blink::css_longhand::WebkitTextDecorationsInEffect(),
    ::blink::css_longhand::WebkitTextFillColor(),
    ::blink::css_longhand::WebkitTextSecurity(),
    ::blink::css_longhand::WebkitTextStrokeColor(),
    ::blink::css_longhand::WebkitTextStrokeWidth(),
    ::blink::css_longhand::WebkitTransformOriginX(),
    ::blink::css_longhand::WebkitTransformOriginY(),
    ::blink::css_longhand::WebkitTransformOriginZ(),
    ::blink::css_longhand::WebkitUserDrag(),
    ::blink::css_longhand::WebkitUserModify(),
    ::blink::css_longhand::WhiteSpaceCollapse(),
    ::blink::css_longhand::Widows(),
    ::blink::css_longhand::Width(),
    ::blink::css_longhand::WillChange(),
    ::blink::css_longhand::WordBreak(),
    ::blink::css_longhand::WordSpacing(),
    ::blink::css_longhand::X(),
    ::blink::css_longhand::Y(),
    ::blink::css_longhand::ZIndex(),
    ::blink::css_shorthand::AlternativeAnimationWithTimeline(),
    ::blink::css_shorthand::Animation(),
    ::blink::css_shorthand::AnimationRange(),
    ::blink::css_shorthand::Background(),
    ::blink::css_shorthand::BackgroundPosition(),
    ::blink::css_shorthand::Border(),
    ::blink::css_shorthand::BorderBlock(),
    ::blink::css_shorthand::BorderBlockColor(),
    ::blink::css_shorthand::BorderBlockEnd(),
    ::blink::css_shorthand::BorderBlockStart(),
    ::blink::css_shorthand::BorderBlockStyle(),
    ::blink::css_shorthand::BorderBlockWidth(),
    ::blink::css_shorthand::BorderBottom(),
    ::blink::css_shorthand::BorderColor(),
    ::blink::css_shorthand::BorderImage(),
    ::blink::css_shorthand::BorderInline(),
    ::blink::css_shorthand::BorderInlineColor(),
    ::blink::css_shorthand::BorderInlineEnd(),
    ::blink::css_shorthand::BorderInlineStart(),
    ::blink::css_shorthand::BorderInlineStyle(),
    ::blink::css_shorthand::BorderInlineWidth(),
    ::blink::css_shorthand::BorderLeft(),
    ::blink::css_shorthand::BorderRadius(),
    ::blink::css_shorthand::BorderRight(),
    ::blink::css_shorthand::BorderSpacing(),
    ::blink::css_shorthand::BorderStyle(),
    ::blink::css_shorthand::BorderTop(),
    ::blink::css_shorthand::BorderWidth(),
    ::blink::css_shorthand::ColumnRule(),
    ::blink::css_shorthand::Columns(),
    ::blink::css_shorthand::ContainIntrinsicSize(),
    ::blink::css_shorthand::Container(),
    ::blink::css_shorthand::Flex(),
    ::blink::css_shorthand::FlexFlow(),
    ::blink::css_shorthand::Font(),
    ::blink::css_shorthand::FontSynthesis(),
    ::blink::css_shorthand::FontVariant(),
    ::blink::css_shorthand::Gap(),
    ::blink::css_shorthand::Grid(),
    ::blink::css_shorthand::GridArea(),
    ::blink::css_shorthand::GridColumn(),
    ::blink::css_shorthand::GridRow(),
    ::blink::css_shorthand::GridTemplate(),
    ::blink::css_shorthand::Inset(),
    ::blink::css_shorthand::InsetBlock(),
    ::blink::css_shorthand::InsetInline(),
    ::blink::css_shorthand::ListStyle(),
    ::blink::css_shorthand::Margin(),
    ::blink::css_shorthand::MarginBlock(),
    ::blink::css_shorthand::MarginInline(),
    ::blink::css_shorthand::Marker(),
    ::blink::css_shorthand::Mask(),
    ::blink::css_shorthand::MaskPosition(),
    ::blink::css_shorthand::MasonryTrack(),
    ::blink::css_shorthand::Offset(),
    ::blink::css_shorthand::Outline(),
    ::blink::css_shorthand::Overflow(),
    ::blink::css_shorthand::OverscrollBehavior(),
    ::blink::css_shorthand::Padding(),
    ::blink::css_shorthand::PaddingBlock(),
    ::blink::css_shorthand::PaddingInline(),
    ::blink::css_shorthand::PageBreakAfter(),
    ::blink::css_shorthand::PageBreakBefore(),
    ::blink::css_shorthand::PageBreakInside(),
    ::blink::css_shorthand::PlaceContent(),
    ::blink::css_shorthand::PlaceItems(),
    ::blink::css_shorthand::PlaceSelf(),
    ::blink::css_shorthand::PositionTry(),
    ::blink::css_shorthand::ScrollMargin(),
    ::blink::css_shorthand::ScrollMarginBlock(),
    ::blink::css_shorthand::ScrollMarginInline(),
    ::blink::css_shorthand::ScrollPadding(),
    ::blink::css_shorthand::ScrollPaddingBlock(),
    ::blink::css_shorthand::ScrollPaddingInline(),
    ::blink::css_shorthand::ScrollStart(),
    ::blink::css_shorthand::ScrollTimeline(),
    ::blink::css_shorthand::TextBox(),
    ::blink::css_shorthand::TextDecoration(),
    ::blink::css_shorthand::TextEmphasis(),
    ::blink::css_shorthand::TextSpacing(),
    ::blink::css_shorthand::TextWrap(),
    ::blink::css_shorthand::Transition(),
    ::blink::css_shorthand::ViewTimeline(),
    ::blink::css_shorthand::WebkitColumnBreakAfter(),
    ::blink::css_shorthand::WebkitColumnBreakBefore(),
    ::blink::css_shorthand::WebkitColumnBreakInside(),
    ::blink::css_shorthand::WebkitMaskBoxImage(),
    ::blink::css_shorthand::WebkitTextStroke(),
    ::blink::css_shorthand::WhiteSpace(),
    ::blink::css_longhand::WebkitAppearance(),
    ::blink::css_longhand::WebkitAppRegion(),
    ::blink::css_longhand::WebkitMaskClip(),
    ::blink::css_longhand::WebkitMaskComposite(),
    ::blink::css_longhand::WebkitMaskImage(),
    ::blink::css_longhand::WebkitMaskOrigin(),
    ::blink::css_longhand::WebkitMaskRepeat(),
    ::blink::css_longhand::WebkitMaskSize(),
    ::blink::css_longhand::WebkitBorderEndColor(),
    ::blink::css_longhand::WebkitBorderEndStyle(),
    ::blink::css_longhand::WebkitBorderEndWidth(),
    ::blink::css_longhand::WebkitBorderStartColor(),
    ::blink::css_longhand::WebkitBorderStartStyle(),
    ::blink::css_longhand::WebkitBorderStartWidth(),
    ::blink::css_longhand::WebkitBorderBeforeColor(),
    ::blink::css_longhand::WebkitBorderBeforeStyle(),
    ::blink::css_longhand::WebkitBorderBeforeWidth(),
    ::blink::css_longhand::WebkitBorderAfterColor(),
    ::blink::css_longhand::WebkitBorderAfterStyle(),
    ::blink::css_longhand::WebkitBorderAfterWidth(),
    ::blink::css_longhand::WebkitMarginEnd(),
    ::blink::css_longhand::WebkitMarginStart(),
    ::blink::css_longhand::WebkitMarginBefore(),
    ::blink::css_longhand::WebkitMarginAfter(),
    ::blink::css_longhand::WebkitPaddingEnd(),
    ::blink::css_longhand::WebkitPaddingStart(),
    ::blink::css_longhand::WebkitPaddingBefore(),
    ::blink::css_longhand::WebkitPaddingAfter(),
    ::blink::css_longhand::WebkitLogicalWidth(),
    ::blink::css_longhand::WebkitLogicalHeight(),
    ::blink::css_longhand::WebkitMinLogicalWidth(),
    ::blink::css_longhand::WebkitMinLogicalHeight(),
    ::blink::css_longhand::WebkitMaxLogicalWidth(),
    ::blink::css_longhand::WebkitMaxLogicalHeight(),
    ::blink::css_shorthand::WebkitBorderAfter(),
    ::blink::css_shorthand::WebkitBorderBefore(),
    ::blink::css_shorthand::WebkitBorderEnd(),
    ::blink::css_shorthand::WebkitBorderStart(),
    ::blink::css_shorthand::WebkitMask(),
    ::blink::css_shorthand::WebkitMaskPosition(),
    ::blink::css_longhand::EpubCaptionSide(),
    ::blink::css_longhand::EpubTextCombine(),
    ::blink::css_shorthand::EpubTextEmphasis(),
    ::blink::css_longhand::EpubTextEmphasisColor(),
    ::blink::css_longhand::EpubTextEmphasisStyle(),
    ::blink::css_longhand::EpubTextOrientation(),
    ::blink::css_longhand::EpubTextTransform(),
    ::blink::css_longhand::EpubWordBreak(),
    ::blink::css_longhand::EpubWritingMode(),
    ::blink::css_longhand::WebkitAlignContent(),
    ::blink::css_longhand::WebkitAlignItems(),
    ::blink::css_longhand::WebkitAlignSelf(),
    ::blink::css_shorthand::WebkitAnimation(),
    ::blink::css_shorthand::WebkitAlternativeAnimationWithTimeline(),
    ::blink::css_longhand::WebkitAnimationDelay(),
    ::blink::css_longhand::WebkitAnimationDirection(),
    ::blink::css_longhand::WebkitAnimationDuration(),
    ::blink::css_longhand::WebkitAnimationFillMode(),
    ::blink::css_longhand::WebkitAnimationIterationCount(),
    ::blink::css_longhand::WebkitAnimationName(),
    ::blink::css_longhand::WebkitAnimationPlayState(),
    ::blink::css_longhand::WebkitAnimationTimingFunction(),
    ::blink::css_longhand::WebkitBackfaceVisibility(),
    ::blink::css_longhand::WebkitBackgroundClip(),
    ::blink::css_longhand::WebkitBackgroundOrigin(),
    ::blink::css_longhand::WebkitBackgroundSize(),
    ::blink::css_longhand::WebkitBorderBottomLeftRadius(),
    ::blink::css_longhand::WebkitBorderBottomRightRadius(),
    ::blink::css_shorthand::WebkitBorderRadius(),
    ::blink::css_longhand::WebkitBorderTopLeftRadius(),
    ::blink::css_longhand::WebkitBorderTopRightRadius(),
    ::blink::css_longhand::WebkitBoxShadow(),
    ::blink::css_longhand::WebkitBoxSizing(),
    ::blink::css_longhand::WebkitClipPath(),
    ::blink::css_longhand::WebkitColumnCount(),
    ::blink::css_longhand::WebkitColumnGap(),
    ::blink::css_shorthand::WebkitColumnRule(),
    ::blink::css_longhand::WebkitColumnRuleColor(),
    ::blink::css_longhand::WebkitColumnRuleStyle(),
    ::blink::css_longhand::WebkitColumnRuleWidth(),
    ::blink::css_longhand::WebkitColumnSpan(),
    ::blink::css_longhand::WebkitColumnWidth(),
    ::blink::css_shorthand::WebkitColumns(),
    ::blink::css_longhand::WebkitFilter(),
    ::blink::css_shorthand::WebkitFlex(),
    ::blink::css_longhand::WebkitFlexBasis(),
    ::blink::css_longhand::WebkitFlexDirection(),
    ::blink::css_shorthand::WebkitFlexFlow(),
    ::blink::css_longhand::WebkitFlexGrow(),
    ::blink::css_longhand::WebkitFlexShrink(),
    ::blink::css_longhand::WebkitFlexWrap(),
    ::blink::css_longhand::WebkitFontFeatureSettings(),
    ::blink::css_longhand::WebkitHyphenateCharacter(),
    ::blink::css_longhand::WebkitJustifyContent(),
    ::blink::css_longhand::WebkitOpacity(),
    ::blink::css_longhand::WebkitOrder(),
    ::blink::css_longhand::WebkitPerspective(),
    ::blink::css_longhand::WebkitPerspectiveOrigin(),
    ::blink::css_longhand::WebkitShapeImageThreshold(),
    ::blink::css_longhand::WebkitShapeMargin(),
    ::blink::css_longhand::WebkitShapeOutside(),
    ::blink::css_shorthand::WebkitTextEmphasis(),
    ::blink::css_longhand::WebkitTextEmphasisColor(),
    ::blink::css_longhand::WebkitTextEmphasisPosition(),
    ::blink::css_longhand::WebkitTextEmphasisStyle(),
    ::blink::css_longhand::WebkitTextSizeAdjust(),
    ::blink::css_longhand::WebkitTransform(),
    ::blink::css_longhand::WebkitTransformOrigin(),
    ::blink::css_longhand::WebkitTransformStyle(),
    ::blink::css_shorthand::WebkitTransition(),
    ::blink::css_longhand::WebkitTransitionDelay(),
    ::blink::css_longhand::WebkitTransitionDuration(),
    ::blink::css_longhand::WebkitTransitionProperty(),
    ::blink::css_longhand::WebkitTransitionTimingFunction(),
    ::blink::css_longhand::WebkitUserSelect(),
    ::blink::css_longhand::WordWrap(),
    ::blink::css_longhand::GridColumnGap(),
    ::blink::css_longhand::GridRowGap(),
    ::blink::css_shorthand::GridGap(),
};

// Mapping from a property's ID to that of its visited counterpart,
// or kInvalid if it has none.
const uint8_t kPropertyVisitedIDs[] = {
    static_cast<uint8_t>(CSSPropertyID::kInvalid),
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kVariable.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kColorScheme.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kForcedColorAdjust.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMaskImage.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMathDepth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPosition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPositionAnchor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextSizeAdjust.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAppearance.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedColor), // kColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kDirection.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontFamily.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontFeatureSettings.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontKerning.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontOpticalSizing.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontPalette.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontSize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontSizeAdjust.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontStretch.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontSynthesisSmallCaps.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontSynthesisStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontSynthesisWeight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontVariantAlternates.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontVariantCaps.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontVariantEastAsian.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontVariantEmoji.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontVariantLigatures.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontVariantNumeric.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontVariantPosition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontVariationSettings.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontWeight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInsetArea.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPositionArea.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextOrientation.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextRendering.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextSpacingTrim.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitFontSmoothing.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitLocale.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitTextOrientation.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitWritingMode.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWritingMode.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kZoom.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAccentColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAdditiveSymbols.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAlignContent.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAlignItems.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAlignSelf.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAlignmentBaseline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAll.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnchorName.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnchorScope.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnimationComposition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnimationDelay.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnimationDirection.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnimationDuration.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnimationFillMode.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnimationIterationCount.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnimationName.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnimationPlayState.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnimationRangeEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnimationRangeStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnimationTimeline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnimationTimingFunction.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAppRegion.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAscentOverride.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAspectRatio.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBackdropFilter.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBackfaceVisibility.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBackgroundAttachment.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBackgroundBlendMode.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBackgroundClip.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedBackgroundColor), // kBackgroundColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBackgroundImage.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBackgroundOrigin.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBackgroundPositionX.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBackgroundPositionY.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBackgroundRepeat.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBackgroundSize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBasePalette.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBaselineShift.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBaselineSource.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBlockSize.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedBorderBlockEndColor), // kBorderBlockEndColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderBlockEndStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderBlockEndWidth.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedBorderBlockStartColor), // kBorderBlockStartColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderBlockStartStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderBlockStartWidth.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedBorderBottomColor), // kBorderBottomColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderBottomLeftRadius.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderBottomRightRadius.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderBottomStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderBottomWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderCollapse.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderEndEndRadius.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderEndStartRadius.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderImageOutset.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderImageRepeat.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderImageSlice.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderImageSource.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderImageWidth.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedBorderInlineEndColor), // kBorderInlineEndColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderInlineEndStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderInlineEndWidth.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedBorderInlineStartColor), // kBorderInlineStartColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderInlineStartStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderInlineStartWidth.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedBorderLeftColor), // kBorderLeftColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderLeftStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderLeftWidth.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedBorderRightColor), // kBorderRightColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderRightStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderRightWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderStartEndRadius.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderStartStartRadius.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedBorderTopColor), // kBorderTopColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderTopLeftRadius.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderTopRightRadius.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderTopStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderTopWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBottom.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBoxDecorationBreak.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBoxShadow.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBoxSizing.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBreakAfter.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBreakBefore.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBreakInside.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBufferedRendering.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kCaptionSide.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kCaretAnimation.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedCaretColor), // kCaretColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kClear.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kClip.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kClipPath.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kClipRule.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kColorInterpolation.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kColorInterpolationFilters.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kColorRendering.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kColumnCount.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kColumnFill.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kColumnGap.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedColumnRuleColor), // kColumnRuleColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kColumnRuleStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kColumnRuleWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kColumnSpan.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kColumnWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kContain.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kContainIntrinsicBlockSize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kContainIntrinsicHeight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kContainIntrinsicInlineSize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kContainIntrinsicWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kContainerName.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kContainerType.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kContent.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kContentVisibility.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kCounterIncrement.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kCounterReset.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kCounterSet.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kCursor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kCx.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kCy.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kD.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kDescentOverride.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kDisplay.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kDominantBaseline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kDynamicRangeLimit.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kEmptyCells.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFallback.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFieldSizing.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedFill), // kFill.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFillOpacity.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFillRule.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFilter.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFlexBasis.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFlexDirection.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFlexGrow.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFlexShrink.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFlexWrap.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFloat.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFloodColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFloodOpacity.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontDisplay.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGridAutoColumns.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGridAutoFlow.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGridAutoRows.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGridColumnEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGridColumnStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGridRowEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGridRowStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGridTemplateAreas.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGridTemplateColumns.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGridTemplateRows.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kHeight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kHyphenateCharacter.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kHyphenateLimitChars.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kHyphens.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kImageOrientation.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kImageRendering.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInherits.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInitialLetter.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInitialValue.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInlineSize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInsetBlockEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInsetBlockStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInsetInlineEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInsetInlineStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInteractivity.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalAlignContentBlock.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalEmptyLineHeight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalFontSizeDelta.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalForcedBackgroundColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalForcedBorderColor.
    static_cast<uint8_t>(CSSPropertyID::kInternalForcedVisitedColor), // kInternalForcedColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalForcedOutlineColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalForcedVisitedColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalOverflowBlock.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalOverflowInline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedBackgroundColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedBorderBlockEndColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedBorderBlockStartColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedBorderBottomColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedBorderInlineEndColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedBorderInlineStartColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedBorderLeftColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedBorderRightColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedBorderTopColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedCaretColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedColumnRuleColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedFill.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedOutlineColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedStroke.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedTextDecorationColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedTextEmphasisColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedTextFillColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInternalVisitedTextStrokeColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInterpolateSize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kIsolation.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kJustifyContent.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kJustifyItems.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kJustifySelf.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kLeft.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kLetterSpacing.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kLightingColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kLineBreak.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kLineClamp.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kLineGapOverride.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kLineHeight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kListStyleImage.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kListStylePosition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kListStyleType.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMarginBlockEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMarginBlockStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMarginBottom.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMarginInlineEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMarginInlineStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMarginLeft.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMarginRight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMarginTop.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMarkerEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMarkerMid.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMarkerStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMaskClip.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMaskComposite.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMaskMode.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMaskOrigin.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMaskRepeat.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMaskSize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMaskType.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMasonrySlack.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMasonryTemplateTracks.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMasonryTrackEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMasonryTrackStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMathShift.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMathStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMaxBlockSize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMaxHeight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMaxInlineSize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMaxWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMinBlockSize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMinHeight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMinInlineSize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMinWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMixBlendMode.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kNavigation.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kNegative.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kObjectFit.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kObjectPosition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kObjectViewBox.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOffsetAnchor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOffsetDistance.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOffsetPath.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOffsetPosition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOffsetRotate.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOpacity.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOrder.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOriginTrialTestProperty.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOrphans.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedOutlineColor), // kOutlineColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOutlineOffset.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOutlineStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOutlineWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOverflowAnchor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOverflowBlock.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOverflowClipMargin.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOverflowInline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOverflowWrap.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOverflowX.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOverflowY.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOverlay.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOverrideColors.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOverscrollBehaviorBlock.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOverscrollBehaviorInline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOverscrollBehaviorX.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOverscrollBehaviorY.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPad.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPaddingBlockEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPaddingBlockStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPaddingBottom.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPaddingInlineEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPaddingInlineStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPaddingLeft.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPaddingRight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPaddingTop.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPage.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPageOrientation.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPaintOrder.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPerspective.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPerspectiveOrigin.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPointerEvents.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPopoverHideDelay.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPopoverShowDelay.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPositionTryFallbacks.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPositionTryOrder.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPositionVisibility.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPrefix.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kQuotes.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kR.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kRange.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kReadingFlow.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kResize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kRight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kRotate.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kRowGap.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kRubyAlign.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kRubyPosition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kRx.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kRy.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScale.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollBehavior.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollMarginBlockEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollMarginBlockStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollMarginBottom.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollMarginInlineEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollMarginInlineStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollMarginLeft.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollMarginRight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollMarginTop.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollMarkerGroup.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollPaddingBlockEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollPaddingBlockStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollPaddingBottom.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollPaddingInlineEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollPaddingInlineStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollPaddingLeft.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollPaddingRight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollPaddingTop.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollSnapAlign.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollSnapStop.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollSnapType.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollStartBlock.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollStartInline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollStartTarget.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollStartX.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollStartY.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollTimelineAxis.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollTimelineName.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollbarColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollbarGutter.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollbarWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kShapeImageThreshold.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kShapeMargin.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kShapeOutside.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kShapeRendering.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kSize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kSizeAdjust.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kSpeak.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kSpeakAs.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kSrc.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kStopColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kStopOpacity.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedStroke), // kStroke.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kStrokeDasharray.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kStrokeDashoffset.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kStrokeLinecap.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kStrokeLinejoin.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kStrokeMiterlimit.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kStrokeOpacity.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kStrokeWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kSuffix.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kSymbols.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kSyntax.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kSystem.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTabSize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTableLayout.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextAlign.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextAlignLast.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextAnchor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextAutospace.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextBoxEdge.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextBoxTrim.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextCombineUpright.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedTextDecorationColor), // kTextDecorationColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextDecorationLine.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextDecorationSkipInk.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextDecorationStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextDecorationThickness.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedTextEmphasisColor), // kTextEmphasisColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextEmphasisPosition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextEmphasisStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextIndent.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextOverflow.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextShadow.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextTransform.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextUnderlineOffset.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextUnderlinePosition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextWrapMode.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextWrapStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTimelineScope.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTop.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTouchAction.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTransform.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTransformBox.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTransformOrigin.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTransformStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTransitionBehavior.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTransitionDelay.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTransitionDuration.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTransitionProperty.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTransitionTimingFunction.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTranslate.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTypes.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kUnicodeBidi.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kUnicodeRange.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kUserSelect.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kVectorEffect.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kVerticalAlign.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kViewTimelineAxis.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kViewTimelineInset.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kViewTimelineName.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kViewTransitionCaptureMode.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kViewTransitionClass.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kViewTransitionGroup.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kViewTransitionName.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kVisibility.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitBorderHorizontalSpacing.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitBorderImage.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitBorderVerticalSpacing.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitBoxAlign.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitBoxDecorationBreak.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitBoxDirection.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitBoxFlex.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitBoxOrdinalGroup.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitBoxOrient.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitBoxPack.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitBoxReflect.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitLineBreak.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitLineClamp.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitMaskBoxImageOutset.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitMaskBoxImageRepeat.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitMaskBoxImageSlice.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitMaskBoxImageSource.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitMaskBoxImageWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitMaskPositionX.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitMaskPositionY.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitPerspectiveOriginX.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitPerspectiveOriginY.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitPrintColorAdjust.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitRtlOrdering.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitRubyPosition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitTapHighlightColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitTextCombine.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitTextDecorationsInEffect.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedTextFillColor), // kWebkitTextFillColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitTextSecurity.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedTextStrokeColor), // kWebkitTextStrokeColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitTextStrokeWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitTransformOriginX.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitTransformOriginY.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitTransformOriginZ.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitUserDrag.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitUserModify.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWhiteSpaceCollapse.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWidows.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWillChange.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWordBreak.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWordSpacing.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kX.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kY.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kZIndex.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAlternativeAnimationWithTimeline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnimation.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAnimationRange.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBackground.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBackgroundPosition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorder.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderBlock.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderBlockColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderBlockEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderBlockStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderBlockStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderBlockWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderBottom.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderImage.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderInline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderInlineColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderInlineEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderInlineStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderInlineStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderInlineWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderLeft.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderRadius.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderRight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderSpacing.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderTop.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kBorderWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kColumnRule.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kColumns.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kContainIntrinsicSize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kContainer.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFlex.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFlexFlow.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFont.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontSynthesis.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kFontVariant.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGap.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGrid.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGridArea.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGridColumn.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGridRow.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kGridTemplate.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInset.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInsetBlock.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kInsetInline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kListStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMargin.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMarginBlock.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMarginInline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMarker.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMask.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMaskPosition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kMasonryTrack.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOffset.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOutline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOverflow.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kOverscrollBehavior.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPadding.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPaddingBlock.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPaddingInline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPageBreakAfter.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPageBreakBefore.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPageBreakInside.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPlaceContent.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPlaceItems.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPlaceSelf.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kPositionTry.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollMargin.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollMarginBlock.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollMarginInline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollPadding.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollPaddingBlock.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollPaddingInline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kScrollTimeline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextBox.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextDecoration.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextEmphasis.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextSpacing.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTextWrap.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kTransition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kViewTimeline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitColumnBreakAfter.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitColumnBreakBefore.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitColumnBreakInside.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitMaskBoxImage.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWebkitTextStroke.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kWhiteSpace.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitAppearance.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitAppRegion.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaskClip.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaskComposite.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaskImage.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaskOrigin.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaskRepeat.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaskSize.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedBorderInlineEndColor), // kAliasWebkitBorderEndColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderEndStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderEndWidth.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedBorderInlineStartColor), // kAliasWebkitBorderStartColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderStartStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderStartWidth.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedBorderBlockStartColor), // kAliasWebkitBorderBeforeColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderBeforeStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderBeforeWidth.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedBorderBlockEndColor), // kAliasWebkitBorderAfterColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderAfterStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderAfterWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMarginEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMarginStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMarginBefore.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMarginAfter.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitPaddingEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitPaddingStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitPaddingBefore.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitPaddingAfter.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitLogicalWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitLogicalHeight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMinLogicalWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMinLogicalHeight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaxLogicalWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaxLogicalHeight.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderAfter.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderBefore.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderEnd.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderStart.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMask.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaskPosition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasEpubCaptionSide.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasEpubTextCombine.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasEpubTextEmphasis.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedTextEmphasisColor), // kAliasEpubTextEmphasisColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasEpubTextEmphasisStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasEpubTextOrientation.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasEpubTextTransform.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasEpubWordBreak.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasEpubWritingMode.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitAlignContent.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitAlignItems.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitAlignSelf.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimation.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitAlternativeAnimationWithTimeline.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationDelay.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationDirection.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationDuration.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationFillMode.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationIterationCount.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationName.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationPlayState.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationTimingFunction.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBackfaceVisibility.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBackgroundClip.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBackgroundOrigin.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBackgroundSize.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderBottomLeftRadius.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderBottomRightRadius.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderRadius.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderTopLeftRadius.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderTopRightRadius.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBoxShadow.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitBoxSizing.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitClipPath.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumnCount.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumnGap.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumnRule.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedColumnRuleColor), // kAliasWebkitColumnRuleColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumnRuleStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumnRuleWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumnSpan.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumnWidth.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumns.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitFilter.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitFlex.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitFlexBasis.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitFlexDirection.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitFlexFlow.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitFlexGrow.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitFlexShrink.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitFlexWrap.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitFontFeatureSettings.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitHyphenateCharacter.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitJustifyContent.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitOpacity.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitOrder.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitPerspective.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitPerspectiveOrigin.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitShapeImageThreshold.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitShapeMargin.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitShapeOutside.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitTextEmphasis.
    static_cast<uint8_t>(CSSPropertyID::kInternalVisitedTextEmphasisColor), // kAliasWebkitTextEmphasisColor.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitTextEmphasisPosition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitTextEmphasisStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitTextSizeAdjust.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransform.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransformOrigin.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransformStyle.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransition.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransitionDelay.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransitionDuration.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransitionProperty.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransitionTimingFunction.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWebkitUserSelect.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasWordWrap.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasGridColumnGap.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasGridRowGap.
    static_cast<uint8_t>(CSSPropertyID::kInvalid), // kAliasGridGap.
};

// Verify that all properties (used in the array) fit into a uint8_t.
// If this stops holding, we'll either need to switch types of
// kPropertyVisitedIDs, or reorganize the ordering of the enum
// so that the kInternalVisited* ones are earlier.
static_assert(static_cast<size_t>(CSSPropertyID::kInvalid) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedBackgroundColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedBorderBlockEndColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedBorderBlockStartColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedBorderBottomColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedBorderInlineEndColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedBorderInlineStartColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedBorderLeftColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedBorderRightColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedBorderTopColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedCaretColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedColumnRuleColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedFill) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalForcedVisitedColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedOutlineColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedStroke) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedTextDecorationColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedTextEmphasisColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedTextFillColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedTextStrokeColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedBorderInlineEndColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedBorderInlineStartColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedBorderBlockStartColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedBorderBlockEndColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedTextEmphasisColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedColumnRuleColor) < 256);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalVisitedTextEmphasisColor) < 256);

// Similar, for unvisited IDs. Note that this array is much less
// hot than kPropertyVisitedIDs, so it's definitely fine that it's uint16_t.
const uint16_t kPropertyUnvisitedIDs[] = {
    static_cast<uint16_t>(CSSPropertyID::kInvalid),
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kVariable.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kColorScheme.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kForcedColorAdjust.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMaskImage.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMathDepth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPosition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPositionAnchor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextSizeAdjust.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAppearance.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kDirection.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontFamily.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontFeatureSettings.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontKerning.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontOpticalSizing.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontPalette.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontSizeAdjust.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontStretch.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontSynthesisSmallCaps.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontSynthesisStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontSynthesisWeight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontVariantAlternates.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontVariantCaps.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontVariantEastAsian.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontVariantEmoji.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontVariantLigatures.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontVariantNumeric.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontVariantPosition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontVariationSettings.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontWeight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInsetArea.
    static_cast<uint16_t>(CSSPropertyID::kColor), // kInternalVisitedColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPositionArea.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextOrientation.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextRendering.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextSpacingTrim.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitFontSmoothing.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitLocale.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitTextOrientation.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitWritingMode.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWritingMode.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kZoom.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAccentColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAdditiveSymbols.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAlignContent.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAlignItems.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAlignSelf.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAlignmentBaseline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAll.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnchorName.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnchorScope.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnimationComposition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnimationDelay.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnimationDirection.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnimationDuration.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnimationFillMode.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnimationIterationCount.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnimationName.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnimationPlayState.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnimationRangeEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnimationRangeStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnimationTimeline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnimationTimingFunction.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAppRegion.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAscentOverride.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAspectRatio.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBackdropFilter.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBackfaceVisibility.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBackgroundAttachment.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBackgroundBlendMode.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBackgroundClip.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBackgroundColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBackgroundImage.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBackgroundOrigin.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBackgroundPositionX.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBackgroundPositionY.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBackgroundRepeat.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBackgroundSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBasePalette.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBaselineShift.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBaselineSource.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBlockSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBlockEndColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBlockEndStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBlockEndWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBlockStartColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBlockStartStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBlockStartWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBottomColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBottomLeftRadius.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBottomRightRadius.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBottomStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBottomWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderCollapse.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderEndEndRadius.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderEndStartRadius.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderImageOutset.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderImageRepeat.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderImageSlice.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderImageSource.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderImageWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderInlineEndColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderInlineEndStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderInlineEndWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderInlineStartColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderInlineStartStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderInlineStartWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderLeftColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderLeftStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderLeftWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderRightColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderRightStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderRightWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderStartEndRadius.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderStartStartRadius.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderTopColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderTopLeftRadius.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderTopRightRadius.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderTopStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderTopWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBottom.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBoxDecorationBreak.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBoxShadow.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBoxSizing.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBreakAfter.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBreakBefore.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBreakInside.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBufferedRendering.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kCaptionSide.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kCaretAnimation.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kCaretColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kClear.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kClip.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kClipPath.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kClipRule.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kColorInterpolation.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kColorInterpolationFilters.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kColorRendering.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kColumnCount.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kColumnFill.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kColumnGap.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kColumnRuleColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kColumnRuleStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kColumnRuleWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kColumnSpan.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kColumnWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kContain.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kContainIntrinsicBlockSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kContainIntrinsicHeight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kContainIntrinsicInlineSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kContainIntrinsicWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kContainerName.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kContainerType.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kContent.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kContentVisibility.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kCounterIncrement.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kCounterReset.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kCounterSet.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kCursor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kCx.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kCy.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kD.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kDescentOverride.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kDisplay.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kDominantBaseline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kDynamicRangeLimit.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kEmptyCells.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFallback.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFieldSizing.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFill.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFillOpacity.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFillRule.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFilter.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFlexBasis.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFlexDirection.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFlexGrow.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFlexShrink.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFlexWrap.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFloat.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFloodColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFloodOpacity.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontDisplay.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGridAutoColumns.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGridAutoFlow.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGridAutoRows.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGridColumnEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGridColumnStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGridRowEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGridRowStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGridTemplateAreas.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGridTemplateColumns.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGridTemplateRows.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kHeight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kHyphenateCharacter.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kHyphenateLimitChars.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kHyphens.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kImageOrientation.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kImageRendering.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInherits.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInitialLetter.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInitialValue.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInlineSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInsetBlockEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInsetBlockStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInsetInlineEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInsetInlineStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInteractivity.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInternalAlignContentBlock.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInternalEmptyLineHeight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInternalFontSizeDelta.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInternalForcedBackgroundColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInternalForcedBorderColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInternalForcedColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInternalForcedOutlineColor.
    static_cast<uint16_t>(CSSPropertyID::kInternalForcedColor), // kInternalForcedVisitedColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInternalOverflowBlock.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInternalOverflowInline.
    static_cast<uint16_t>(CSSPropertyID::kBackgroundColor), // kInternalVisitedBackgroundColor.
    static_cast<uint16_t>(CSSPropertyID::kBorderBlockEndColor), // kInternalVisitedBorderBlockEndColor.
    static_cast<uint16_t>(CSSPropertyID::kBorderBlockStartColor), // kInternalVisitedBorderBlockStartColor.
    static_cast<uint16_t>(CSSPropertyID::kBorderBottomColor), // kInternalVisitedBorderBottomColor.
    static_cast<uint16_t>(CSSPropertyID::kBorderInlineEndColor), // kInternalVisitedBorderInlineEndColor.
    static_cast<uint16_t>(CSSPropertyID::kBorderInlineStartColor), // kInternalVisitedBorderInlineStartColor.
    static_cast<uint16_t>(CSSPropertyID::kBorderLeftColor), // kInternalVisitedBorderLeftColor.
    static_cast<uint16_t>(CSSPropertyID::kBorderRightColor), // kInternalVisitedBorderRightColor.
    static_cast<uint16_t>(CSSPropertyID::kBorderTopColor), // kInternalVisitedBorderTopColor.
    static_cast<uint16_t>(CSSPropertyID::kCaretColor), // kInternalVisitedCaretColor.
    static_cast<uint16_t>(CSSPropertyID::kColumnRuleColor), // kInternalVisitedColumnRuleColor.
    static_cast<uint16_t>(CSSPropertyID::kFill), // kInternalVisitedFill.
    static_cast<uint16_t>(CSSPropertyID::kOutlineColor), // kInternalVisitedOutlineColor.
    static_cast<uint16_t>(CSSPropertyID::kStroke), // kInternalVisitedStroke.
    static_cast<uint16_t>(CSSPropertyID::kTextDecorationColor), // kInternalVisitedTextDecorationColor.
    static_cast<uint16_t>(CSSPropertyID::kTextEmphasisColor), // kInternalVisitedTextEmphasisColor.
    static_cast<uint16_t>(CSSPropertyID::kWebkitTextFillColor), // kInternalVisitedTextFillColor.
    static_cast<uint16_t>(CSSPropertyID::kWebkitTextStrokeColor), // kInternalVisitedTextStrokeColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInterpolateSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kIsolation.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kJustifyContent.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kJustifyItems.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kJustifySelf.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kLeft.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kLetterSpacing.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kLightingColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kLineBreak.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kLineClamp.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kLineGapOverride.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kLineHeight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kListStyleImage.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kListStylePosition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kListStyleType.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMarginBlockEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMarginBlockStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMarginBottom.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMarginInlineEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMarginInlineStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMarginLeft.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMarginRight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMarginTop.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMarkerEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMarkerMid.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMarkerStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMaskClip.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMaskComposite.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMaskMode.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMaskOrigin.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMaskRepeat.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMaskSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMaskType.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMasonrySlack.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMasonryTemplateTracks.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMasonryTrackEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMasonryTrackStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMathShift.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMathStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMaxBlockSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMaxHeight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMaxInlineSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMaxWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMinBlockSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMinHeight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMinInlineSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMinWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMixBlendMode.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kNavigation.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kNegative.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kObjectFit.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kObjectPosition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kObjectViewBox.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOffsetAnchor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOffsetDistance.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOffsetPath.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOffsetPosition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOffsetRotate.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOpacity.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOrder.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOriginTrialTestProperty.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOrphans.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOutlineColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOutlineOffset.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOutlineStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOutlineWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOverflowAnchor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOverflowBlock.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOverflowClipMargin.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOverflowInline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOverflowWrap.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOverflowX.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOverflowY.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOverlay.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOverrideColors.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOverscrollBehaviorBlock.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOverscrollBehaviorInline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOverscrollBehaviorX.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOverscrollBehaviorY.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPad.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPaddingBlockEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPaddingBlockStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPaddingBottom.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPaddingInlineEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPaddingInlineStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPaddingLeft.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPaddingRight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPaddingTop.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPage.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPageOrientation.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPaintOrder.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPerspective.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPerspectiveOrigin.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPointerEvents.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPopoverHideDelay.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPopoverShowDelay.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPositionTryFallbacks.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPositionTryOrder.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPositionVisibility.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPrefix.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kQuotes.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kR.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kRange.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kReadingFlow.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kResize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kRight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kRotate.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kRowGap.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kRubyAlign.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kRubyPosition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kRx.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kRy.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScale.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollBehavior.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollMarginBlockEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollMarginBlockStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollMarginBottom.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollMarginInlineEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollMarginInlineStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollMarginLeft.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollMarginRight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollMarginTop.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollMarkerGroup.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollPaddingBlockEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollPaddingBlockStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollPaddingBottom.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollPaddingInlineEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollPaddingInlineStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollPaddingLeft.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollPaddingRight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollPaddingTop.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollSnapAlign.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollSnapStop.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollSnapType.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollStartBlock.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollStartInline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollStartTarget.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollStartX.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollStartY.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollTimelineAxis.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollTimelineName.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollbarColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollbarGutter.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollbarWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kShapeImageThreshold.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kShapeMargin.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kShapeOutside.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kShapeRendering.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kSizeAdjust.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kSpeak.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kSpeakAs.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kSrc.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kStopColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kStopOpacity.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kStroke.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kStrokeDasharray.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kStrokeDashoffset.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kStrokeLinecap.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kStrokeLinejoin.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kStrokeMiterlimit.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kStrokeOpacity.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kStrokeWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kSuffix.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kSymbols.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kSyntax.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kSystem.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTabSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTableLayout.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextAlign.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextAlignLast.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextAnchor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextAutospace.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextBoxEdge.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextBoxTrim.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextCombineUpright.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextDecorationColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextDecorationLine.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextDecorationSkipInk.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextDecorationStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextDecorationThickness.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextEmphasisColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextEmphasisPosition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextEmphasisStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextIndent.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextOverflow.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextShadow.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextTransform.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextUnderlineOffset.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextUnderlinePosition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextWrapMode.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextWrapStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTimelineScope.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTop.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTouchAction.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTransform.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTransformBox.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTransformOrigin.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTransformStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTransitionBehavior.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTransitionDelay.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTransitionDuration.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTransitionProperty.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTransitionTimingFunction.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTranslate.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTypes.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kUnicodeBidi.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kUnicodeRange.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kUserSelect.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kVectorEffect.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kVerticalAlign.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kViewTimelineAxis.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kViewTimelineInset.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kViewTimelineName.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kViewTransitionCaptureMode.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kViewTransitionClass.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kViewTransitionGroup.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kViewTransitionName.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kVisibility.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitBorderHorizontalSpacing.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitBorderImage.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitBorderVerticalSpacing.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitBoxAlign.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitBoxDecorationBreak.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitBoxDirection.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitBoxFlex.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitBoxOrdinalGroup.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitBoxOrient.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitBoxPack.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitBoxReflect.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitLineBreak.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitLineClamp.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitMaskBoxImageOutset.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitMaskBoxImageRepeat.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitMaskBoxImageSlice.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitMaskBoxImageSource.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitMaskBoxImageWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitMaskPositionX.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitMaskPositionY.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitPerspectiveOriginX.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitPerspectiveOriginY.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitPrintColorAdjust.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitRtlOrdering.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitRubyPosition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitTapHighlightColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitTextCombine.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitTextDecorationsInEffect.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitTextFillColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitTextSecurity.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitTextStrokeColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitTextStrokeWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitTransformOriginX.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitTransformOriginY.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitTransformOriginZ.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitUserDrag.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitUserModify.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWhiteSpaceCollapse.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWidows.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWillChange.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWordBreak.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWordSpacing.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kX.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kY.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kZIndex.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAlternativeAnimationWithTimeline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnimation.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAnimationRange.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBackground.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBackgroundPosition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorder.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBlock.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBlockColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBlockEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBlockStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBlockStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBlockWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderBottom.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderImage.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderInline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderInlineColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderInlineEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderInlineStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderInlineStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderInlineWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderLeft.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderRadius.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderRight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderSpacing.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderTop.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kBorderWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kColumnRule.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kColumns.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kContainIntrinsicSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kContainer.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFlex.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFlexFlow.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFont.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontSynthesis.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kFontVariant.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGap.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGrid.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGridArea.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGridColumn.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGridRow.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kGridTemplate.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInset.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInsetBlock.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kInsetInline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kListStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMargin.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMarginBlock.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMarginInline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMarker.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMask.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMaskPosition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kMasonryTrack.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOffset.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOutline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOverflow.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kOverscrollBehavior.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPadding.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPaddingBlock.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPaddingInline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPageBreakAfter.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPageBreakBefore.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPageBreakInside.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPlaceContent.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPlaceItems.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPlaceSelf.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kPositionTry.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollMargin.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollMarginBlock.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollMarginInline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollPadding.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollPaddingBlock.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollPaddingInline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kScrollTimeline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextBox.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextDecoration.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextEmphasis.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextSpacing.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTextWrap.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kTransition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kViewTimeline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitColumnBreakAfter.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitColumnBreakBefore.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitColumnBreakInside.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitMaskBoxImage.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWebkitTextStroke.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kWhiteSpace.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitAppearance.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitAppRegion.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaskClip.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaskComposite.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaskImage.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaskOrigin.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaskRepeat.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaskSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderEndColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderEndStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderEndWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderStartColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderStartStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderStartWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderBeforeColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderBeforeStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderBeforeWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderAfterColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderAfterStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderAfterWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMarginEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMarginStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMarginBefore.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMarginAfter.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitPaddingEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitPaddingStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitPaddingBefore.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitPaddingAfter.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitLogicalWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitLogicalHeight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMinLogicalWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMinLogicalHeight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaxLogicalWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaxLogicalHeight.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderAfter.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderBefore.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderEnd.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderStart.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMask.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitMaskPosition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasEpubCaptionSide.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasEpubTextCombine.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasEpubTextEmphasis.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasEpubTextEmphasisColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasEpubTextEmphasisStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasEpubTextOrientation.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasEpubTextTransform.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasEpubWordBreak.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasEpubWritingMode.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitAlignContent.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitAlignItems.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitAlignSelf.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimation.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitAlternativeAnimationWithTimeline.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationDelay.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationDirection.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationDuration.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationFillMode.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationIterationCount.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationName.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationPlayState.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitAnimationTimingFunction.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBackfaceVisibility.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBackgroundClip.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBackgroundOrigin.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBackgroundSize.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderBottomLeftRadius.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderBottomRightRadius.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderRadius.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderTopLeftRadius.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBorderTopRightRadius.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBoxShadow.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitBoxSizing.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitClipPath.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumnCount.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumnGap.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumnRule.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumnRuleColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumnRuleStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumnRuleWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumnSpan.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumnWidth.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitColumns.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitFilter.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitFlex.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitFlexBasis.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitFlexDirection.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitFlexFlow.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitFlexGrow.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitFlexShrink.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitFlexWrap.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitFontFeatureSettings.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitHyphenateCharacter.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitJustifyContent.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitOpacity.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitOrder.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitPerspective.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitPerspectiveOrigin.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitShapeImageThreshold.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitShapeMargin.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitShapeOutside.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitTextEmphasis.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitTextEmphasisColor.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitTextEmphasisPosition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitTextEmphasisStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitTextSizeAdjust.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransform.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransformOrigin.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransformStyle.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransition.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransitionDelay.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransitionDuration.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransitionProperty.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitTransitionTimingFunction.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWebkitUserSelect.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasWordWrap.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasGridColumnGap.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasGridRowGap.
    static_cast<uint16_t>(CSSPropertyID::kInvalid), // kAliasGridGap.
};

// Same check as for kPropertyVisitedIDs.
static_assert(static_cast<size_t>(CSSPropertyID::kInvalid) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kInternalForcedColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kBackgroundColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kBorderBlockEndColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kBorderBlockStartColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kBorderBottomColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kBorderInlineEndColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kBorderInlineStartColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kBorderLeftColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kBorderRightColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kBorderTopColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kCaretColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kColumnRuleColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kFill) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kOutlineColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kStroke) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kTextDecorationColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kTextEmphasisColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kWebkitTextFillColor) < 65536);
static_assert(static_cast<size_t>(CSSPropertyID::kWebkitTextStrokeColor) < 65536);

} // namespace blink
