// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/style/templates/computed_style_base.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_group_config.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/core/css/css_properties_ranking.json5
//   ../../third_party/blink/renderer/core/css/css_value_keywords.json5
//   ../../third_party/blink/renderer/core/style/computed_style_extra_fields.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "third_party/blink/renderer/core/style/computed_style.h"
#include "third_party/blink/renderer/core/style/computed_style_base.h"
#include "third_party/blink/renderer/core/style/content_data.h" // For the logging operator to be visible.
#include "third_party/blink/renderer/platform/wtf/size_assertions.h"

#include <utility>

namespace blink {

// Constructor and destructor are protected so that only the parent class ComputedStyle
// can instantiate this class.
ComputedStyleBase::ComputedStyleBase()
    : rare_inherited_usage_less_than_64_percent_data_(StyleRareInheritedUsageLessThan64PercentData::Create())
    , rare_non_inherited_usage_less_than_14_percent_data_(StyleRareNonInheritedUsageLessThan14PercentData::Create())
    , inherited_data_(StyleInheritedData::Create())
    , visual_data_(StyleVisualData::Create())
    , svg_data_(StyleSVGData::Create())
    , surround_data_(StyleSurroundData::Create())
    , background_data_(StyleBackgroundData::Create())
    , box_data_(StyleBoxData::Create())
    , font_data_(StyleFontData::Create())
    , base_data_(nullptr)
    , data_ {
        static_cast<unsigned>(kPseudoIdNone) // pseudo_element_styles_
        ,
        static_cast<unsigned>(ECursor::kAuto) // cursor_
        ,
        static_cast<unsigned>(EPointerEvents::kAuto) // pointer_events_
        ,
        static_cast<unsigned>(false) // affected_by_active_
        ,
        static_cast<unsigned>(EDisplay::kInline) // display_
        ,
        static_cast<unsigned>(PseudoId::kPseudoIdNone) // style_type_
        ,
        static_cast<unsigned>(kScrollbarGutterAuto) // scrollbar_gutter_
        ,
        static_cast<unsigned>(ETextAlign::kStart) // text_align_
        ,
        static_cast<unsigned>(static_cast<unsigned>(EVerticalAlign::kBaseline)) // vertical_align_
        ,
        static_cast<unsigned>(EClear::kNone) // clear_
        ,
        static_cast<unsigned>(EFloat::kNone) // floating_
        ,
        static_cast<unsigned>(EContentVisibility::kVisible) // content_visibility_
        ,
        static_cast<unsigned>(EOverflow::kVisible) // overflow_x_
        ,
        static_cast<unsigned>(EOverflow::kVisible) // overflow_y_
        ,
        static_cast<unsigned>(EPosition::kStatic) // position_
        ,
        static_cast<unsigned>(ETextTransform::kNone) // text_transform_
        ,
        static_cast<unsigned>(ETransformBox::kViewBox) // transform_box_
        ,
        static_cast<unsigned>(UnicodeBidi::kNormal) // unicode_bidi_
        ,
        static_cast<unsigned>(WritingMode::kHorizontalTb) // writing_mode_
        ,
        static_cast<unsigned>(EInsideLink::kNotInsideLink) // inside_link_
        ,
        static_cast<unsigned>(0) // is_stacking_context_without_containment_
        ,
        static_cast<unsigned>(EOverflowAnchor::kAuto) // overflow_anchor_
        ,
        static_cast<unsigned>(TextWrapStyle::kAuto) // text_wrap_style_
        ,
        static_cast<unsigned>(0) // viewport_unit_flags_
        ,
        static_cast<unsigned>(false) // affected_by_drag_
        ,
        static_cast<unsigned>(EVisibility::kVisible) // visibility_
        ,
        static_cast<unsigned>(WhiteSpaceCollapse::kCollapse) // white_space_collapse_
        ,
        static_cast<unsigned>(false) // affected_by_focus_within_
        ,
        static_cast<unsigned>(false) // affected_by_hover_
        ,
        static_cast<unsigned>(EBorderCollapse::kSeparate) // border_collapse_
        ,
        static_cast<unsigned>(true) // border_collapse_is_inherited_
        ,
        static_cast<unsigned>(EBoxDirection::kNormal) // box_direction_
        ,
        static_cast<unsigned>(EBoxSizing::kContentBox) // box_sizing_
        ,
        static_cast<unsigned>(ECaptionSide::kTop) // caption_side_
        ,
        static_cast<unsigned>(true) // caption_side_is_inherited_
        ,
        static_cast<unsigned>(ECaretAnimation::kAuto) // caret_animation_
        ,
        static_cast<unsigned>(false) // child_has_explicit_inheritance_
        ,
        static_cast<unsigned>(true) // color_is_inherited_
        ,
        static_cast<unsigned>(false) // color_scheme_flags_is_normal_
        ,
        static_cast<unsigned>(false) // color_scheme_forced_
        ,
        static_cast<unsigned>(false) // custom_style_callback_depends_on_font_
        ,
        static_cast<unsigned>(false) // dark_color_scheme_
        ,
        static_cast<unsigned>(TextDirection::kLtr) // direction_
        ,
        static_cast<unsigned>(EEmptyCells::kShow) // empty_cells_
        ,
        static_cast<unsigned>(true) // empty_cells_is_inherited_
        ,
        static_cast<unsigned>(false) // has_attr_function_
        ,
        static_cast<unsigned>(false) // has_author_background_
        ,
        static_cast<unsigned>(false) // has_author_border_
        ,
        static_cast<unsigned>(false) // has_author_border_radius_
        ,
        static_cast<unsigned>(false) // has_author_highlight_colors_
        ,
        static_cast<unsigned>(false) // has_container_relative_units_
        ,
        static_cast<unsigned>(false) // has_em_units_
        ,
        static_cast<unsigned>(false) // has_env_
        ,
        static_cast<unsigned>(false) // has_explicit_inheritance_
        ,
        static_cast<unsigned>(false) // has_glyph_relative_units_
        ,
        static_cast<unsigned>(false) // has_logical_direction_relative_units_
        ,
        static_cast<unsigned>(false) // has_root_font_relative_units_
        ,
        static_cast<unsigned>(false) // has_variable_declaration_
        ,
        static_cast<unsigned>(false) // has_variable_reference_
        ,
        static_cast<unsigned>(false) // is_ensured_in_display_none_
        ,
        static_cast<unsigned>(false) // is_ensured_outside_flat_tree_
        ,
        static_cast<unsigned>(false) // is_flex_or_grid_or_custom_item_
        ,
        static_cast<unsigned>(false) // is_html_inert_
        ,
        static_cast<unsigned>(true) // is_html_inert_is_inherited_
        ,
        static_cast<unsigned>(false) // is_in_blockifying_display_
        ,
        static_cast<unsigned>(false) // is_in_inlinifying_display_
        ,
        static_cast<unsigned>(false) // is_inside_display_ignoring_floating_children_
        ,
        static_cast<unsigned>(false) // is_inside_list_element_
        ,
        static_cast<unsigned>(false) // is_link_
        ,
        static_cast<unsigned>(true) // is_original_display_inline_type_
        ,
        static_cast<unsigned>(false) // is_page_margin_box_
        ,
        static_cast<unsigned>(false) // is_specified_display_webkit_box_
        ,
        static_cast<unsigned>(EListStylePosition::kOutside) // list_style_position_
        ,
        static_cast<unsigned>(true) // list_style_position_is_inherited_
        ,
        static_cast<unsigned>(EOriginTrialTestProperty::kNormal) // origin_trial_test_property_
        ,
        static_cast<unsigned>(true) // pointer_events_is_inherited_
        ,
        static_cast<unsigned>(false) // prefers_default_scrollbar_styles_
        ,
        static_cast<unsigned>(EPrintColorAdjust::kEconomy) // print_color_adjust_
        ,
        static_cast<unsigned>(EOrder::kLogical) // rtl_ordering_
        ,
        static_cast<unsigned>(true) // rtl_ordering_is_inherited_
        ,
        static_cast<unsigned>(EScrollSnapStop::kNormal) // scroll_snap_stop_
        ,
        static_cast<unsigned>(false) // should_ignore_overflow_property_for_inline_block_baseline_
        ,
        static_cast<unsigned>(false) // skips_contents_
        ,
        static_cast<unsigned>(ETableLayout::kAuto) // table_layout_
        ,
        static_cast<unsigned>(true) // text_transform_is_inherited_
        ,
        static_cast<unsigned>(TextWrapMode::kWrap) // text_wrap_mode_
        ,
        static_cast<unsigned>(true) // visibility_is_inherited_
    }
{
}

// These const_casts are quite safe, since ComputedStyle[Base] is immutable.
ComputedStyleBase::ComputedStyleBase(const ComputedStyleBuilderBase& builder)
    : rare_inherited_usage_less_than_64_percent_data_(
        const_cast<StyleRareInheritedUsageLessThan64PercentData*>(builder.rare_inherited_usage_less_than_64_percent_data_))
    , rare_non_inherited_usage_less_than_14_percent_data_(
          const_cast<StyleRareNonInheritedUsageLessThan14PercentData*>(builder.rare_non_inherited_usage_less_than_14_percent_data_))
    , inherited_data_(const_cast<StyleInheritedData*>(builder.inherited_data_))
    , visual_data_(const_cast<StyleVisualData*>(builder.visual_data_))
    , svg_data_(const_cast<StyleSVGData*>(builder.svg_data_))
    , surround_data_(const_cast<StyleSurroundData*>(builder.surround_data_))
    , background_data_(const_cast<StyleBackgroundData*>(builder.background_data_))
    , box_data_(const_cast<StyleBoxData*>(builder.box_data_))
    , font_data_(const_cast<StyleFontData*>(builder.font_data_))
    , base_data_(builder.base_data_)
    , data_(builder.data_)
{
    // Reset derived flags:
    data_.is_stacking_context_without_containment_ = 0;
}

Vector<std::pair<String, size_t>> ComputedStyleBase::FindChangedGroups(const ComputedStyleBase& other_style) const
{
    Vector<std::pair<String, size_t>> output;
    if (!base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_, other_style.rare_inherited_usage_less_than_64_percent_data_)) {
        output.emplace_back("rare_inherited_usage_less_than_64_percent_data_", sizeof(*rare_inherited_usage_less_than_64_percent_data_));
    }
    if (!base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_,
            other_style.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_)) {
        output.emplace_back("rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_",
            sizeof(*rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_));
    }
    if (!base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_,
            other_style.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_)) {
        output.emplace_back("rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_",
            sizeof(*rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_));
    }
    if (!base::ValuesEquivalent(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_,
            other_style.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_)) {
        output.emplace_back(
            "rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_",
            sizeof(*rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_));
    }
    if (!base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_,
            other_style.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_)) {
        output.emplace_back("rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_",
            sizeof(*rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_));
    }
    if (!base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_data_,
            other_style.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_data_)) {
        output.emplace_back("rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_data_",
            sizeof(*rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_data_));
    }
    if (!base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_, other_style.rare_non_inherited_usage_less_than_14_percent_data_)) {
        output.emplace_back("rare_non_inherited_usage_less_than_14_percent_data_", sizeof(*rare_non_inherited_usage_less_than_14_percent_data_));
    }
    if (!base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            other_style.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_)) {
        output.emplace_back("rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_",
            sizeof(*rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_));
    }
    if (!base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_,
            other_style.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_)) {
        output.emplace_back("rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_",
            sizeof(*rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_));
    }
    if (!base::ValuesEquivalent(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_,
            other_style.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_)) {
        output.emplace_back("rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_",
            sizeof(*rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_));
    }
    if (!base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_,
            other_style.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_)) {
        output.emplace_back("rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_",
            sizeof(*rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_));
    }
    if (!base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_data_,
            other_style.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_data_)) {
        output.emplace_back("rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_data_",
            sizeof(*rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_data_));
    }
    if (!base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_,
            other_style.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_)) {
        output.emplace_back("rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_",
            sizeof(*rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_));
    }
    if (!base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_,
            other_style.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_)) {
        output.emplace_back("rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_",
            sizeof(*rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_));
    }
    if (!base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_,
            other_style.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_)) {
        output.emplace_back("rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_",
            sizeof(*rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_));
    }
    if (!base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_,
            other_style.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_)) {
        output.emplace_back("rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_",
            sizeof(*rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_));
    }
    if (!base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_,
            other_style.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_)) {
        output.emplace_back("rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_",
            sizeof(*rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_));
    }
    if (!base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                    ->rare_non_inherited_usage_less_than_100_percent_data_,
            other_style.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_)) {
        output.emplace_back("rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_"
                            "usage_less_than_100_percent_data_",
            sizeof(*rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_));
    }
    if (!base::ValuesEquivalent(inherited_data_, other_style.inherited_data_)) {
        output.emplace_back("inherited_data_", sizeof(*inherited_data_));
    }
    if (!base::ValuesEquivalent(visual_data_, other_style.visual_data_)) {
        output.emplace_back("visual_data_", sizeof(*visual_data_));
    }
    if (!base::ValuesEquivalent(svg_data_, other_style.svg_data_)) {
        output.emplace_back("svg_data_", sizeof(*svg_data_));
    }
    if (!base::ValuesEquivalent(svg_data_->misc_data_, other_style.svg_data_->misc_data_)) {
        output.emplace_back("svg_data_->misc_data_", sizeof(*svg_data_->misc_data_));
    }
    if (!base::ValuesEquivalent(svg_data_->geometry_data_, other_style.svg_data_->geometry_data_)) {
        output.emplace_back("svg_data_->geometry_data_", sizeof(*svg_data_->geometry_data_));
    }
    if (!base::ValuesEquivalent(svg_data_->fill_data_, other_style.svg_data_->fill_data_)) {
        output.emplace_back("svg_data_->fill_data_", sizeof(*svg_data_->fill_data_));
    }
    if (!base::ValuesEquivalent(svg_data_->stroke_data_, other_style.svg_data_->stroke_data_)) {
        output.emplace_back("svg_data_->stroke_data_", sizeof(*svg_data_->stroke_data_));
    }
    if (!base::ValuesEquivalent(svg_data_->inherited_resources_data_, other_style.svg_data_->inherited_resources_data_)) {
        output.emplace_back("svg_data_->inherited_resources_data_", sizeof(*svg_data_->inherited_resources_data_));
    }
    if (!base::ValuesEquivalent(svg_data_->stop_data_, other_style.svg_data_->stop_data_)) {
        output.emplace_back("svg_data_->stop_data_", sizeof(*svg_data_->stop_data_));
    }
    if (!base::ValuesEquivalent(surround_data_, other_style.surround_data_)) {
        output.emplace_back("surround_data_", sizeof(*surround_data_));
    }
    if (!base::ValuesEquivalent(background_data_, other_style.background_data_)) {
        output.emplace_back("background_data_", sizeof(*background_data_));
    }
    if (!base::ValuesEquivalent(box_data_, other_style.box_data_)) {
        output.emplace_back("box_data_", sizeof(*box_data_));
    }
    if (!base::ValuesEquivalent(font_data_, other_style.font_data_)) {
        output.emplace_back("font_data_", sizeof(*font_data_));
    }

    return output;
}

void ComputedStyleBase::Trace(Visitor* visitor) const
{
    static_cast<const ComputedStyle*>(this)->TraceAfterDispatch(visitor);
}

uint64_t ComputedStyleBase::FieldInvalidationDiff(const ComputedStyle& a, const ComputedStyle& b)
{
    uint64_t diff = 0u;
    if (a.rare_inherited_usage_less_than_64_percent_data_.Get() != b.rare_inherited_usage_less_than_64_percent_data_.Get()) {
        if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_.Get()
            != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_.Get()) {
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_) {
                diff |= kTextDecoration;
            }
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->accent_color_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->accent_color_) {
                diff |= kAccentColor;
            }
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->image_orientation_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->image_orientation_) {
                diff |= kLayout;
                diff |= kPaint;
            }
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_.Get()
            != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_.Get()) {
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_.Get()
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_.Get()) {
                if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                        ->internal_visited_text_emphasis_color_
                    != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                           ->internal_visited_text_emphasis_color_) {
                    diff |= kColor;
                }
                if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                        ->internal_visited_text_fill_color_
                    != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                           ->internal_visited_text_fill_color_) {
                    diff |= kColor;
                }
                if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                        ->internal_visited_text_stroke_color_
                    != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                           ->internal_visited_text_stroke_color_) {
                    diff |= kColor;
                }
                if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                        ->internal_visited_caret_color_
                    != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                           ->internal_visited_caret_color_) {
                    diff |= kColor;
                }
            }
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->dynamic_range_limit_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->dynamic_range_limit_) {
                diff |= kPaint;
            }
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (!base::ValuesEquivalent(
                    a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->scrollbar_color_,
                    b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->scrollbar_color_)) {
                diff |= kScrollbarStyle;
                diff |= kScrollbarColor;
            }
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_zoom_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_zoom_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_mark_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_mark_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ruby_align_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ruby_align_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_will_change_contents_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_will_change_contents_) {
                diff |= kCompositing;
            }
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_autospace_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_autospace_) {
                diff |= kReshape;
            }
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_fill_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_fill_) {
                diff |= kLayout;
                diff |= kPaint;
            }
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_ != b.rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (!base::ValuesEquivalent(a.rare_inherited_usage_less_than_64_percent_data_->quotes_, b.rare_inherited_usage_less_than_64_percent_data_->quotes_)) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (!base::ValuesEquivalent(
                a.rare_inherited_usage_less_than_64_percent_data_->list_style_image_, b.rare_inherited_usage_less_than_64_percent_data_->list_style_image_)) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (!base::ValuesEquivalent(
                a.rare_inherited_usage_less_than_64_percent_data_->list_style_type_, b.rare_inherited_usage_less_than_64_percent_data_->list_style_type_)) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (!base::ValuesEquivalent(
                a.rare_inherited_usage_less_than_64_percent_data_->text_shadow_, b.rare_inherited_usage_less_than_64_percent_data_->text_shadow_)) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_indent_ != b.rare_inherited_usage_less_than_64_percent_data_->text_indent_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_ != b.rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->tab_size_ != b.rare_inherited_usage_less_than_64_percent_data_->tab_size_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_stroke_width_ != b.rare_inherited_usage_less_than_64_percent_data_->text_stroke_width_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_
            != b.rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_) {
            diff |= kColor;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_fill_color_ != b.rare_inherited_usage_less_than_64_percent_data_->text_fill_color_) {
            diff |= kColor;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_ != b.rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_) {
            diff |= kColor;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->caret_color_ != b.rare_inherited_usage_less_than_64_percent_data_->caret_color_) {
            diff |= kColor;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->orphans_ != b.rare_inherited_usage_less_than_64_percent_data_->orphans_) {
            diff |= kLayout;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->widows_ != b.rare_inherited_usage_less_than_64_percent_data_->widows_) {
            diff |= kLayout;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_box_edge_ != b.rare_inherited_usage_less_than_64_percent_data_->text_box_edge_) {
            diff |= kLayout;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_underline_position_
            != b.rare_inherited_usage_less_than_64_percent_data_->text_underline_position_) {
            diff |= kTextDecoration;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->image_rendering_ != b.rare_inherited_usage_less_than_64_percent_data_->image_rendering_) {
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->line_break_ != b.rare_inherited_usage_less_than_64_percent_data_->line_break_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_align_last_ != b.rare_inherited_usage_less_than_64_percent_data_->text_align_last_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->user_select_ != b.rare_inherited_usage_less_than_64_percent_data_->user_select_) {
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->word_break_ != b.rare_inherited_usage_less_than_64_percent_data_->word_break_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->hyphens_ != b.rare_inherited_usage_less_than_64_percent_data_->hyphens_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->overflow_wrap_ != b.rare_inherited_usage_less_than_64_percent_data_->overflow_wrap_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_emphasis_position_
            != b.rare_inherited_usage_less_than_64_percent_data_->text_emphasis_position_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_orientation_ != b.rare_inherited_usage_less_than_64_percent_data_->text_orientation_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_security_ != b.rare_inherited_usage_less_than_64_percent_data_->text_security_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->user_modify_ != b.rare_inherited_usage_less_than_64_percent_data_->user_modify_) {
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->ruby_position_ != b.rare_inherited_usage_less_than_64_percent_data_->ruby_position_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_combine_ != b.rare_inherited_usage_less_than_64_percent_data_->text_combine_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_decoration_skip_ink_
            != b.rare_inherited_usage_less_than_64_percent_data_->text_decoration_skip_ink_) {
            diff |= kTextDecoration;
        }
    }
    if (a.rare_non_inherited_usage_less_than_14_percent_data_.Get() != b.rare_non_inherited_usage_less_than_14_percent_data_.Get()) {
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_.Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_.Get()) {
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_
                        ->grid_template_columns_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_
                           ->grid_template_columns_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_
                        ->grid_template_rows_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_
                           ->grid_template_rows_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_.Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_.Get()) {
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                        ->internal_visited_column_rule_color_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                           ->internal_visited_column_rule_color_) {
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                        ->internal_visited_background_color_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                           ->internal_visited_background_color_) {
                    diff |= kBackgroundColor;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                        ->internal_visited_border_bottom_color_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                           ->internal_visited_border_bottom_color_) {
                    diff |= kBorderOutlineVisitedColor;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                        ->internal_visited_border_left_color_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                           ->internal_visited_border_left_color_) {
                    diff |= kBorderOutlineVisitedColor;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                        ->internal_visited_border_right_color_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                           ->internal_visited_border_right_color_) {
                    diff |= kBorderOutlineVisitedColor;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                        ->internal_visited_border_top_color_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                           ->internal_visited_border_top_color_) {
                    diff |= kBorderOutlineVisitedColor;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                        ->internal_visited_outline_color_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                           ->internal_visited_outline_color_) {
                    diff |= kBorderOutlineVisitedColor;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                        ->internal_visited_text_decoration_color_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                           ->internal_visited_text_decoration_color_) {
                    diff |= kColor;
                }
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_data_.Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_data_.Get()) {
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_data_
                        ->masonry_template_tracks_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_data_
                           ->masonry_template_tracks_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_.Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_.Get()) {
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                        ->will_change_properties_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                           ->will_change_properties_) {
                    diff |= kCompositing;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                        ->will_change_scroll_position_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                           ->will_change_scroll_position_) {
                    diff |= kCompositing;
                }
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_.Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_.Get()) {
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
                        ->math_fraction_bar_thickness_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
                           ->math_fraction_bar_thickness_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_l_space_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
                           ->math_l_space_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_r_space_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
                           ->math_r_space_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
                        ->math_padded_v_offset_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
                           ->math_padded_v_offset_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_min_size_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
                           ->math_min_size_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_max_size_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
                           ->math_max_size_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_end_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_end_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_start_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_start_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_name_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                       ->display_layout_custom_name_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (!base::ValuesEquivalent(
                    a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->object_view_box_,
                    b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->object_view_box_)) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_) {
                diff |= kMask;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_) {
                diff |= kMask;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scope_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scope_) {
                diff |= kLayout;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_) {
                diff |= kLayout;
            }
            if (!base::ValuesEquivalent(
                    a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_anchor_,
                    b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_anchor_)) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (!base::ValuesEquivalent(
                    a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_,
                    b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_)) {
                diff |= kLayout;
            }
            if (!base::ValuesEquivalent(
                    a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_fallbacks_,
                    b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_fallbacks_)) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_slack_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_slack_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_) {
                diff |= kReshape;
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->standard_line_clamp_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->standard_line_clamp_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_area_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_area_) {
                diff |= kLayout;
                diff |= kOutOfFlow;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_type_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_type_) {
                diff |= kLayout;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_order_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_order_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_visibility_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_visibility_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->reading_flow_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->reading_flow_) {
                diff |= kLayout;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scrollbar_width_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scrollbar_width_) {
                diff |= kLayout;
                diff |= kPaint;
                diff |= kScrollbarStyle;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->align_content_block_center_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                       ->align_content_block_center_) {
                diff |= kLayout;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_count_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_count_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_width_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_width_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->has_current_backdrop_filter_animation_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                       ->has_current_backdrop_filter_animation_) {
                diff |= kCompositing;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_filter_animation_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                       ->has_current_filter_animation_) {
                diff |= kCompositing;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_opacity_animation_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                       ->has_current_opacity_animation_) {
                diff |= kCompositing;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_rotate_animation_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                       ->has_current_rotate_animation_) {
                diff |= kCompositing;
                diff |= kHasTransform;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_scale_animation_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                       ->has_current_scale_animation_) {
                diff |= kCompositing;
                diff |= kHasTransform;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_transform_animation_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                       ->has_current_transform_animation_) {
                diff |= kCompositing;
                diff |= kHasTransform;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_translate_animation_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                       ->has_current_translate_animation_) {
                diff |= kCompositing;
                diff |= kHasTransform;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->outline_style_is_auto_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->outline_style_is_auto_) {
                diff |= kOutline;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_start_target_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_start_target_) {
                diff |= kLayout;
            }
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_.Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                       ->rare_non_inherited_usage_less_than_100_percent_data_.Get()) {
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_columns_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_columns_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_rows_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_rows_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->backdrop_filter_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->backdrop_filter_) {
                    diff |= kCompositing;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_end_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_end_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_start_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_start_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_end_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_end_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_start_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_start_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->box_reflect_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->box_reflect_)) {
                    diff |= kFilterData;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_thickness_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_thickness_) {
                    diff |= kTextDecoration;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_color_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_color_) {
                    diff |= kPaint;
                }
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->clip_path_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->clip_path_)) {
                    diff |= kClipPath;
                }
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->grid_template_areas_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_template_areas_)) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->offset_path_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_path_)) {
                    diff |= kHasTransform;
                    diff |= kTransformData;
                    diff |= kTransformOther;
                }
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->rotate_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->rotate_)) {
                    diff |= kHasTransform;
                    diff |= kTransformData;
                    diff |= kTransformOther;
                }
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->scale_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->scale_)) {
                    diff |= kHasTransform;
                    diff |= kTransformData;
                    diff |= kTransformOther;
                }
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->shape_outside_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->shape_outside_)) {
                    diff |= kPaint;
                }
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->translate_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->translate_)) {
                    diff |= kHasTransform;
                    diff |= kTransformData;
                    diff |= kTransformOther;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->column_gap_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_gap_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->row_gap_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->row_gap_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->offset_rotate_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_rotate_) {
                    diff |= kTransformData;
                    diff |= kTransformOther;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->object_position_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->object_position_) {
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->offset_anchor_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_anchor_) {
                    diff |= kTransformData;
                    diff |= kTransformOther;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->offset_position_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_position_) {
                    diff |= kHasTransform;
                    diff |= kTransformData;
                    diff |= kTransformOther;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_origin_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_origin_) {
                    diff |= kTransformOther;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->offset_distance_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_distance_) {
                    diff |= kTransformData;
                    diff |= kTransformOther;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->shape_margin_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->shape_margin_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->column_width_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_width_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_) {
                    diff |= kTransformOther;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->outline_color_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->outline_color_) {
                    diff |= kOutline;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_color_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_color_) {
                    diff |= kColor;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->box_ordinal_group_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->box_ordinal_group_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_width_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_width_) {
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->column_count_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_count_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->justify_items_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->justify_items_) {
                    diff |= kLayout;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->justify_self_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->justify_self_) {
                    diff |= kLayout;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->blend_mode_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->blend_mode_) {
                    diff |= kBlendMode;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->contain_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->contain_) {
                    diff |= kLayout;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->break_after_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->break_after_) {
                    diff |= kLayout;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->break_before_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->break_before_) {
                    diff |= kLayout;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_style_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_style_) {
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_flow_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_flow_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_style_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_style_) {
                    diff |= kTextDecoration;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->break_inside_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->break_inside_) {
                    diff |= kLayout;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->column_fill_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_fill_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->draggable_region_mode_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->draggable_region_mode_) {
                    diff |= kLayout;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->user_drag_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->user_drag_) {
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->column_span_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_span_) {
                    diff |= kLayout;
                    diff |= kPaint;
                }
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                        ->rare_non_inherited_usage_less_than_100_percent_data_->isolation_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->isolation_) {
                    diff |= kPaint;
                }
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->filter_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->filter_) {
                diff |= kFilterData;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_grow_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_grow_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_shrink_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_shrink_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_flex_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_flex_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_) {
                diff |= kOutline;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->order_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->order_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_width_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_width_) {
                diff |= kOutline;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->webkit_line_clamp_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->webkit_line_clamp_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_) {
                diff |= kLayout;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_) {
                diff |= kLayout;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_style_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_style_) {
                diff |= kOutline;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_align_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_align_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->object_fit_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->object_fit_) {
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->resize_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->resize_) {
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_pack_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_pack_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->backface_visibility_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->backface_visibility_) {
                diff |= kCompositing;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_orient_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_orient_) {
                diff |= kLayout;
                diff |= kPaint;
            }
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->transform_ != b.rare_non_inherited_usage_less_than_14_percent_data_->transform_) {
            diff |= kHasTransform;
            diff |= kTransformData;
            diff |= kTransformProperty;
        }
        if (!base::ValuesEquivalent(
                a.rare_non_inherited_usage_less_than_14_percent_data_->box_shadow_, b.rare_non_inherited_usage_less_than_14_percent_data_->box_shadow_)) {
            diff |= kPaint;
            diff |= kVisualOverflow;
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->opacity_ != b.rare_non_inherited_usage_less_than_14_percent_data_->opacity_) {
            diff |= kOpacity;
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->align_items_ != b.rare_non_inherited_usage_less_than_14_percent_data_->align_items_) {
            diff |= kLayout;
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->justify_content_
            != b.rare_non_inherited_usage_less_than_14_percent_data_->justify_content_) {
            diff |= kLayout;
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->appearance_ != b.rare_non_inherited_usage_less_than_14_percent_data_->appearance_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->flex_direction_ != b.rare_non_inherited_usage_less_than_14_percent_data_->flex_direction_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->flex_wrap_ != b.rare_non_inherited_usage_less_than_14_percent_data_->flex_wrap_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->text_overflow_ != b.rare_non_inherited_usage_less_than_14_percent_data_->text_overflow_) {
            diff |= kLayout;
            diff |= kPaint;
        }
    }
    if (a.inherited_data_.Get() != b.inherited_data_.Get()) {
        if (a.inherited_data_->line_height_ != b.inherited_data_->line_height_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.inherited_data_->text_autosizing_multiplier_ != b.inherited_data_->text_autosizing_multiplier_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.inherited_data_->color_ != b.inherited_data_->color_) {
            diff |= kAccentColor;
            diff |= kBackgroundCurrentColor;
            diff |= kBorderVisual;
            diff |= kColor;
            diff |= kOutline;
        }
        if (a.inherited_data_->internal_visited_color_ != b.inherited_data_->internal_visited_color_) {
            diff |= kBackgroundCurrentColor;
            diff |= kBorderVisual;
            diff |= kColor;
        }
        if (a.inherited_data_->horizontal_border_spacing_ != b.inherited_data_->horizontal_border_spacing_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.inherited_data_->vertical_border_spacing_ != b.inherited_data_->vertical_border_spacing_) {
            diff |= kLayout;
            diff |= kPaint;
        }
    }
    if (a.visual_data_.Get() != b.visual_data_.Get()) {
        if (!base::ValuesEquivalent(a.visual_data_->base_text_decoration_data_, b.visual_data_->base_text_decoration_data_)) {
            diff |= kTextDecoration;
        }
        if (a.visual_data_->clip_ != b.visual_data_->clip_) {
            diff |= kClip;
        }
        if (a.visual_data_->text_decoration_line_ != b.visual_data_->text_decoration_line_) {
            diff |= kTextDecoration;
        }
        if (a.visual_data_->field_sizing_ != b.visual_data_->field_sizing_) {
            diff |= kLayout;
        }
        if (a.visual_data_->has_auto_clip_ != b.visual_data_->has_auto_clip_) {
            diff |= kClip;
        }
    }
    if (a.svg_data_.Get() != b.svg_data_.Get()) {
        if (a.svg_data_->misc_data_.Get() != b.svg_data_->misc_data_.Get()) {
            if (a.svg_data_->misc_data_->baseline_shift_ != b.svg_data_->misc_data_->baseline_shift_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.svg_data_->misc_data_->flood_opacity_ != b.svg_data_->misc_data_->flood_opacity_) {
                diff |= kPaint;
            }
            if (a.svg_data_->misc_data_->flood_color_ != b.svg_data_->misc_data_->flood_color_) {
                diff |= kPaint;
            }
            if (a.svg_data_->misc_data_->lighting_color_ != b.svg_data_->misc_data_->lighting_color_) {
                diff |= kPaint;
            }
            if (a.svg_data_->misc_data_->baseline_shift_type_ != b.svg_data_->misc_data_->baseline_shift_type_) {
                diff |= kLayout;
                diff |= kPaint;
            }
        }
        if (a.svg_data_->geometry_data_.Get() != b.svg_data_->geometry_data_.Get()) {
            if (!base::ValuesEquivalent(a.svg_data_->geometry_data_->d_, b.svg_data_->geometry_data_->d_)) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.svg_data_->geometry_data_->cx_ != b.svg_data_->geometry_data_->cx_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.svg_data_->geometry_data_->cy_ != b.svg_data_->geometry_data_->cy_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.svg_data_->geometry_data_->r_ != b.svg_data_->geometry_data_->r_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.svg_data_->geometry_data_->rx_ != b.svg_data_->geometry_data_->rx_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.svg_data_->geometry_data_->ry_ != b.svg_data_->geometry_data_->ry_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.svg_data_->geometry_data_->x_ != b.svg_data_->geometry_data_->x_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.svg_data_->geometry_data_->y_ != b.svg_data_->geometry_data_->y_) {
                diff |= kLayout;
                diff |= kPaint;
            }
        }
        if (a.svg_data_->fill_data_.Get() != b.svg_data_->fill_data_.Get()) {
            if (a.svg_data_->fill_data_->fill_paint_ != b.svg_data_->fill_data_->fill_paint_) {
                diff |= kPaint;
            }
            if (a.svg_data_->fill_data_->fill_opacity_ != b.svg_data_->fill_data_->fill_opacity_) {
                diff |= kPaint;
            }
        }
        if (a.svg_data_->stroke_data_.Get() != b.svg_data_->stroke_data_.Get()) {
            if (!base::ValuesEquivalent(a.svg_data_->stroke_data_->stroke_dash_array_, b.svg_data_->stroke_data_->stroke_dash_array_)) {
                diff |= kPaint;
                diff |= kStroke;
            }
            if (a.svg_data_->stroke_data_->internal_visited_stroke_paint_ != b.svg_data_->stroke_data_->internal_visited_stroke_paint_) {
                diff |= kPaint;
            }
            if (a.svg_data_->stroke_data_->stroke_paint_ != b.svg_data_->stroke_data_->stroke_paint_) {
                diff |= kPaint;
                diff |= kStroke;
            }
            if (a.svg_data_->stroke_data_->stroke_dash_offset_ != b.svg_data_->stroke_data_->stroke_dash_offset_) {
                diff |= kPaint;
            }
            if (a.svg_data_->stroke_data_->stroke_width_ != b.svg_data_->stroke_data_->stroke_width_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.svg_data_->stroke_data_->stroke_miter_limit_ != b.svg_data_->stroke_data_->stroke_miter_limit_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.svg_data_->stroke_data_->stroke_opacity_ != b.svg_data_->stroke_data_->stroke_opacity_) {
                diff |= kPaint;
            }
            if (a.svg_data_->stroke_data_->cap_style_ != b.svg_data_->stroke_data_->cap_style_) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (a.svg_data_->stroke_data_->join_style_ != b.svg_data_->stroke_data_->join_style_) {
                diff |= kLayout;
                diff |= kPaint;
            }
        }
        if (a.svg_data_->inherited_resources_data_.Get() != b.svg_data_->inherited_resources_data_.Get()) {
            if (!base::ValuesEquivalent(
                    a.svg_data_->inherited_resources_data_->marker_end_resource_, b.svg_data_->inherited_resources_data_->marker_end_resource_)) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (!base::ValuesEquivalent(
                    a.svg_data_->inherited_resources_data_->marker_mid_resource_, b.svg_data_->inherited_resources_data_->marker_mid_resource_)) {
                diff |= kLayout;
                diff |= kPaint;
            }
            if (!base::ValuesEquivalent(
                    a.svg_data_->inherited_resources_data_->marker_start_resource_, b.svg_data_->inherited_resources_data_->marker_start_resource_)) {
                diff |= kLayout;
                diff |= kPaint;
            }
        }
        if (a.svg_data_->stop_data_.Get() != b.svg_data_->stop_data_.Get()) {
            if (a.svg_data_->stop_data_->stop_opacity_ != b.svg_data_->stop_data_->stop_opacity_) {
                diff |= kPaint;
            }
            if (a.svg_data_->stop_data_->stop_color_ != b.svg_data_->stop_data_->stop_color_) {
                diff |= kPaint;
            }
        }
        if (a.svg_data_->transform_origin_ != b.svg_data_->transform_origin_) {
            diff |= kTransformData;
            diff |= kTransformOther;
        }
        if (a.svg_data_->alignment_baseline_ != b.svg_data_->alignment_baseline_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.svg_data_->css_dominant_baseline_ != b.svg_data_->css_dominant_baseline_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.svg_data_->dominant_baseline_ != b.svg_data_->dominant_baseline_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.svg_data_->paint_order_ != b.svg_data_->paint_order_) {
            diff |= kPaint;
        }
        if (a.svg_data_->color_interpolation_ != b.svg_data_->color_interpolation_) {
            diff |= kPaint;
        }
        if (a.svg_data_->color_interpolation_filters_ != b.svg_data_->color_interpolation_filters_) {
            diff |= kPaint;
        }
        if (a.svg_data_->shape_rendering_ != b.svg_data_->shape_rendering_) {
            diff |= kPaint;
        }
        if (a.svg_data_->text_anchor_ != b.svg_data_->text_anchor_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.svg_data_->clip_rule_ != b.svg_data_->clip_rule_) {
            diff |= kPaint;
        }
        if (a.svg_data_->fill_rule_ != b.svg_data_->fill_rule_) {
            diff |= kPaint;
        }
        if (a.svg_data_->mask_type_ != b.svg_data_->mask_type_) {
            diff |= kPaint;
        }
        if (a.svg_data_->vector_effect_ != b.svg_data_->vector_effect_) {
            diff |= kLayout;
            diff |= kPaint;
        }
    }
    if (a.surround_data_.Get() != b.surround_data_.Get()) {
        if (a.surround_data_->border_image_ != b.surround_data_->border_image_) {
            diff |= kBorderImage;
            diff |= kBorderVisual;
        }
        if (a.surround_data_->aspect_ratio_ != b.surround_data_->aspect_ratio_) {
            diff |= kLayout;
        }
        if (a.surround_data_->contain_intrinsic_height_ != b.surround_data_->contain_intrinsic_height_) {
            diff |= kLayout;
            diff |= kScrollAnchor;
        }
        if (a.surround_data_->contain_intrinsic_width_ != b.surround_data_->contain_intrinsic_width_) {
            diff |= kLayout;
            diff |= kScrollAnchor;
        }
        if (a.surround_data_->border_bottom_left_radius_ != b.surround_data_->border_bottom_left_radius_) {
            diff |= kBorderRadius;
            diff |= kPaint;
        }
        if (a.surround_data_->border_bottom_right_radius_ != b.surround_data_->border_bottom_right_radius_) {
            diff |= kBorderRadius;
            diff |= kPaint;
        }
        if (a.surround_data_->border_top_left_radius_ != b.surround_data_->border_top_left_radius_) {
            diff |= kBorderRadius;
            diff |= kPaint;
        }
        if (a.surround_data_->border_top_right_radius_ != b.surround_data_->border_top_right_radius_) {
            diff |= kBorderRadius;
            diff |= kPaint;
        }
        if (a.surround_data_->bottom_ != b.surround_data_->bottom_) {
            diff |= kInset;
            diff |= kOutOfFlow;
            diff |= kScrollAnchor;
        }
        if (a.surround_data_->left_ != b.surround_data_->left_) {
            diff |= kInset;
            diff |= kOutOfFlow;
            diff |= kScrollAnchor;
        }
        if (a.surround_data_->right_ != b.surround_data_->right_) {
            diff |= kInset;
            diff |= kOutOfFlow;
            diff |= kScrollAnchor;
        }
        if (a.surround_data_->top_ != b.surround_data_->top_) {
            diff |= kInset;
            diff |= kOutOfFlow;
            diff |= kScrollAnchor;
        }
        if (a.surround_data_->border_bottom_color_ != b.surround_data_->border_bottom_color_) {
            diff |= kBorderVisual;
        }
        if (a.surround_data_->border_left_color_ != b.surround_data_->border_left_color_) {
            diff |= kBorderVisual;
        }
        if (a.surround_data_->border_right_color_ != b.surround_data_->border_right_color_) {
            diff |= kBorderVisual;
        }
        if (a.surround_data_->border_top_color_ != b.surround_data_->border_top_color_) {
            diff |= kBorderVisual;
        }
    }
    if (a.background_data_.Get() != b.background_data_.Get()) {
        if (a.background_data_->background_ != b.background_data_->background_) {
            diff |= kBackground;
            diff |= kBackgroundCurrentColor;
        }
        if (a.background_data_->background_color_ != b.background_data_->background_color_) {
            diff |= kBackgroundColor;
        }
    }
    if (a.box_data_.Get() != b.box_data_.Get()) {
        if (a.box_data_->height_ != b.box_data_->height_) {
            diff |= kLayout;
            diff |= kScrollAnchor;
        }
        if (a.box_data_->margin_bottom_ != b.box_data_->margin_bottom_) {
            diff |= kMargin;
            diff |= kOutOfFlow;
            diff |= kScrollAnchor;
        }
        if (a.box_data_->margin_left_ != b.box_data_->margin_left_) {
            diff |= kMargin;
            diff |= kOutOfFlow;
            diff |= kScrollAnchor;
        }
        if (a.box_data_->margin_right_ != b.box_data_->margin_right_) {
            diff |= kMargin;
            diff |= kOutOfFlow;
            diff |= kScrollAnchor;
        }
        if (a.box_data_->margin_top_ != b.box_data_->margin_top_) {
            diff |= kMargin;
            diff |= kOutOfFlow;
            diff |= kScrollAnchor;
        }
        if (a.box_data_->max_height_ != b.box_data_->max_height_) {
            diff |= kLayout;
            diff |= kScrollAnchor;
        }
        if (a.box_data_->max_width_ != b.box_data_->max_width_) {
            diff |= kLayout;
            diff |= kScrollAnchor;
        }
        if (a.box_data_->min_height_ != b.box_data_->min_height_) {
            diff |= kLayout;
            diff |= kScrollAnchor;
        }
        if (a.box_data_->min_width_ != b.box_data_->min_width_) {
            diff |= kLayout;
            diff |= kScrollAnchor;
        }
        if (a.box_data_->padding_bottom_ != b.box_data_->padding_bottom_) {
            diff |= kLayout;
            diff |= kPaint;
            diff |= kScrollAnchor;
        }
        if (a.box_data_->padding_left_ != b.box_data_->padding_left_) {
            diff |= kLayout;
            diff |= kPaint;
            diff |= kScrollAnchor;
        }
        if (a.box_data_->padding_right_ != b.box_data_->padding_right_) {
            diff |= kLayout;
            diff |= kPaint;
            diff |= kScrollAnchor;
        }
        if (a.box_data_->padding_top_ != b.box_data_->padding_top_) {
            diff |= kLayout;
            diff |= kPaint;
            diff |= kScrollAnchor;
        }
        if (a.box_data_->width_ != b.box_data_->width_) {
            diff |= kLayout;
            diff |= kScrollAnchor;
        }
        if (a.box_data_->vertical_align_length_ != b.box_data_->vertical_align_length_) {
            diff |= kLayout;
        }
        if (a.box_data_->border_bottom_width_ != b.box_data_->border_bottom_width_) {
            diff |= kBorderWidth;
            diff |= kBorderVisual;
        }
        if (a.box_data_->border_left_width_ != b.box_data_->border_left_width_) {
            diff |= kBorderWidth;
            diff |= kBorderVisual;
        }
        if (a.box_data_->border_right_width_ != b.box_data_->border_right_width_) {
            diff |= kBorderWidth;
            diff |= kBorderVisual;
        }
        if (a.box_data_->border_top_width_ != b.box_data_->border_top_width_) {
            diff |= kBorderWidth;
            diff |= kBorderVisual;
        }
        if (a.box_data_->z_index_ != b.box_data_->z_index_) {
            diff |= kZIndex;
        }
        if (a.box_data_->border_bottom_style_ != b.box_data_->border_bottom_style_) {
            diff |= kBorderWidth;
            diff |= kBorderVisual;
        }
        if (a.box_data_->border_left_style_ != b.box_data_->border_left_style_) {
            diff |= kBorderWidth;
            diff |= kBorderVisual;
        }
        if (a.box_data_->border_right_style_ != b.box_data_->border_right_style_) {
            diff |= kBorderWidth;
            diff |= kBorderVisual;
        }
        if (a.box_data_->border_top_style_ != b.box_data_->border_top_style_) {
            diff |= kBorderWidth;
            diff |= kBorderVisual;
        }
        if (a.box_data_->baseline_source_ != b.box_data_->baseline_source_) {
            diff |= kLayout;
        }
        if (a.box_data_->text_box_trim_ != b.box_data_->text_box_trim_) {
            diff |= kLayout;
        }
        if (a.box_data_->box_decoration_break_ != b.box_data_->box_decoration_break_) {
            diff |= kLayout;
            diff |= kPaint;
        }
        if (a.box_data_->has_auto_standard_line_clamp_ != b.box_data_->has_auto_standard_line_clamp_) {
            diff |= kLayout;
            diff |= kPaint;
        }
    }
    if (a.font_data_.Get() != b.font_data_.Get()) {
        if (a.font_data_->font_ != b.font_data_->font_) {
            diff |= kReshape;
        }
    }
    if (a.data_.pseudo_element_styles_ != b.data_.pseudo_element_styles_) {
        diff |= kScrollbarStyle;
    }
    if (a.data_.scrollbar_gutter_ != b.data_.scrollbar_gutter_) {
        diff |= kLayout;
    }
    if (a.data_.text_align_ != b.data_.text_align_) {
        diff |= kLayout;
        diff |= kPaint;
    }
    if (a.data_.vertical_align_ != b.data_.vertical_align_) {
        diff |= kLayout;
    }
    if (a.data_.clear_ != b.data_.clear_) {
        diff |= kLayout;
        diff |= kPaint;
    }
    if (a.data_.floating_ != b.data_.floating_) {
        diff |= kLayout;
        diff |= kPaint;
    }
    if (a.data_.content_visibility_ != b.data_.content_visibility_) {
        diff |= kLayout;
    }
    if (a.data_.overflow_x_ != b.data_.overflow_x_) {
        diff |= kLayout;
        diff |= kPaint;
    }
    if (a.data_.overflow_y_ != b.data_.overflow_y_) {
        diff |= kLayout;
        diff |= kPaint;
    }
    if (a.data_.position_ != b.data_.position_) {
        diff |= kClip;
        diff |= kLayout;
        diff |= kScrollAnchor;
    }
    if (a.data_.text_transform_ != b.data_.text_transform_) {
        diff |= kReshape;
    }
    if (a.data_.transform_box_ != b.data_.transform_box_) {
        diff |= kTransformData;
        diff |= kTransformOther;
    }
    if (a.data_.unicode_bidi_ != b.data_.unicode_bidi_) {
        diff |= kReshape;
    }
    if (a.data_.writing_mode_ != b.data_.writing_mode_) {
        diff |= kLayout;
        diff |= kPaint;
    }
    if (a.data_.inside_link_ != b.data_.inside_link_) {
        diff |= kBorderVisual;
        diff |= kPaint;
    }
    if (a.data_.text_wrap_style_ != b.data_.text_wrap_style_) {
        diff |= kLayout;
    }
    if (a.data_.visibility_ != b.data_.visibility_) {
        diff |= kPaint;
        diff |= kVisibility;
    }
    if (a.data_.white_space_collapse_ != b.data_.white_space_collapse_) {
        diff |= kReshape;
    }
    if (a.data_.border_collapse_ != b.data_.border_collapse_) {
        diff |= kLayout;
        diff |= kPaint;
    }
    if (a.data_.box_direction_ != b.data_.box_direction_) {
        diff |= kLayout;
        diff |= kPaint;
    }
    if (a.data_.box_sizing_ != b.data_.box_sizing_) {
        diff |= kLayout;
    }
    if (a.data_.caption_side_ != b.data_.caption_side_) {
        diff |= kLayout;
        diff |= kPaint;
    }
    if (a.data_.caret_animation_ != b.data_.caret_animation_) {
        diff |= kPaint;
    }
    if (a.data_.color_scheme_forced_ != b.data_.color_scheme_forced_) {
        diff |= kPaint;
    }
    if (a.data_.dark_color_scheme_ != b.data_.dark_color_scheme_) {
        diff |= kAccentColor;
        diff |= kBackgroundCurrentColor;
        diff |= kBorderVisual;
        diff |= kPaint;
    }
    if (a.data_.direction_ != b.data_.direction_) {
        diff |= kReshape;
    }
    if (a.data_.empty_cells_ != b.data_.empty_cells_) {
        diff |= kLayout;
        diff |= kPaint;
    }
    if (a.data_.is_original_display_inline_type_ != b.data_.is_original_display_inline_type_) {
        diff |= kLayout;
        diff |= kPaint;
    }
    if (a.data_.is_specified_display_webkit_box_ != b.data_.is_specified_display_webkit_box_) {
        diff |= kLayout;
        diff |= kPaint;
    }
    if (a.data_.list_style_position_ != b.data_.list_style_position_) {
        diff |= kLayout;
        diff |= kPaint;
    }
    if (a.data_.prefers_default_scrollbar_styles_ != b.data_.prefers_default_scrollbar_styles_) {
        diff |= kLayout;
        diff |= kPaint;
        diff |= kScrollbarColor;
    }
    if (a.data_.print_color_adjust_ != b.data_.print_color_adjust_) {
        diff |= kPaint;
    }
    if (a.data_.rtl_ordering_ != b.data_.rtl_ordering_) {
        diff |= kReshape;
    }
    if (a.data_.skips_contents_ != b.data_.skips_contents_) {
        diff |= kLayout;
    }
    if (a.data_.table_layout_ != b.data_.table_layout_) {
        diff |= kLayout;
        diff |= kPaint;
    }
    if (a.data_.text_wrap_mode_ != b.data_.text_wrap_mode_) {
        diff |= kLayout;
    }

    return diff;
}

// Derived fields:

// is_stacking_context_without_containment_
bool ComputedStyleBase::IsStackingContextWithoutContainment() const
{
    if (!data_.is_stacking_context_without_containment_) {
        data_.is_stacking_context_without_containment_
            = 0b10 | (static_cast<unsigned>(static_cast<const ComputedStyle*>(this)->CalculateIsStackingContextWithoutContainment()) & 1);
    }
    return data_.is_stacking_context_without_containment_ & 1;
}

#if DCHECK_IS_ON()

String ComputedStyleBase::DebugFieldToString(DebugField field)
{
    switch (field) {
    case DebugField::accent_color_:
        return "accent_color_";
    case DebugField::affected_by_active_:
        return "affected_by_active_";
    case DebugField::affected_by_css_function_:
        return "affected_by_css_function_";
    case DebugField::affected_by_drag_:
        return "affected_by_drag_";
    case DebugField::affected_by_focus_within_:
        return "affected_by_focus_within_";
    case DebugField::affected_by_hover_:
        return "affected_by_hover_";
    case DebugField::align_content_:
        return "align_content_";
    case DebugField::align_content_block_center_:
        return "align_content_block_center_";
    case DebugField::align_items_:
        return "align_items_";
    case DebugField::align_self_:
        return "align_self_";
    case DebugField::alignment_baseline_:
        return "alignment_baseline_";
    case DebugField::anchor_center_offset_:
        return "anchor_center_offset_";
    case DebugField::anchor_name_:
        return "anchor_name_";
    case DebugField::anchor_scope_:
        return "anchor_scope_";
    case DebugField::animations_:
        return "animations_";
    case DebugField::appearance_:
        return "appearance_";
    case DebugField::aspect_ratio_:
        return "aspect_ratio_";
    case DebugField::backdrop_filter_:
        return "backdrop_filter_";
    case DebugField::backface_visibility_:
        return "backface_visibility_";
    case DebugField::background_:
        return "background_";
    case DebugField::background_color_:
        return "background_color_";
    case DebugField::base_data_:
        return "base_data_";
    case DebugField::base_text_decoration_data_:
        return "base_text_decoration_data_";
    case DebugField::baseline_shift_:
        return "baseline_shift_";
    case DebugField::baseline_shift_type_:
        return "baseline_shift_type_";
    case DebugField::baseline_source_:
        return "baseline_source_";
    case DebugField::blend_mode_:
        return "blend_mode_";
    case DebugField::border_bottom_color_:
        return "border_bottom_color_";
    case DebugField::border_bottom_left_radius_:
        return "border_bottom_left_radius_";
    case DebugField::border_bottom_right_radius_:
        return "border_bottom_right_radius_";
    case DebugField::border_bottom_style_:
        return "border_bottom_style_";
    case DebugField::border_bottom_width_:
        return "border_bottom_width_";
    case DebugField::border_collapse_:
        return "border_collapse_";
    case DebugField::border_collapse_is_inherited_:
        return "border_collapse_is_inherited_";
    case DebugField::border_image_:
        return "border_image_";
    case DebugField::border_left_color_:
        return "border_left_color_";
    case DebugField::border_left_style_:
        return "border_left_style_";
    case DebugField::border_left_width_:
        return "border_left_width_";
    case DebugField::border_right_color_:
        return "border_right_color_";
    case DebugField::border_right_style_:
        return "border_right_style_";
    case DebugField::border_right_width_:
        return "border_right_width_";
    case DebugField::border_top_color_:
        return "border_top_color_";
    case DebugField::border_top_left_radius_:
        return "border_top_left_radius_";
    case DebugField::border_top_right_radius_:
        return "border_top_right_radius_";
    case DebugField::border_top_style_:
        return "border_top_style_";
    case DebugField::border_top_width_:
        return "border_top_width_";
    case DebugField::bottom_:
        return "bottom_";
    case DebugField::box_align_:
        return "box_align_";
    case DebugField::box_decoration_break_:
        return "box_decoration_break_";
    case DebugField::box_direction_:
        return "box_direction_";
    case DebugField::box_flex_:
        return "box_flex_";
    case DebugField::box_ordinal_group_:
        return "box_ordinal_group_";
    case DebugField::box_orient_:
        return "box_orient_";
    case DebugField::box_pack_:
        return "box_pack_";
    case DebugField::box_reflect_:
        return "box_reflect_";
    case DebugField::box_shadow_:
        return "box_shadow_";
    case DebugField::box_sizing_:
        return "box_sizing_";
    case DebugField::break_after_:
        return "break_after_";
    case DebugField::break_before_:
        return "break_before_";
    case DebugField::break_inside_:
        return "break_inside_";
    case DebugField::buffered_rendering_:
        return "buffered_rendering_";
    case DebugField::callback_selectors_:
        return "callback_selectors_";
    case DebugField::can_affect_animations_:
        return "can_affect_animations_";
    case DebugField::cap_style_:
        return "cap_style_";
    case DebugField::caption_side_:
        return "caption_side_";
    case DebugField::caption_side_is_inherited_:
        return "caption_side_is_inherited_";
    case DebugField::caret_animation_:
        return "caret_animation_";
    case DebugField::caret_color_:
        return "caret_color_";
    case DebugField::child_has_explicit_inheritance_:
        return "child_has_explicit_inheritance_";
    case DebugField::clear_:
        return "clear_";
    case DebugField::clip_:
        return "clip_";
    case DebugField::clip_path_:
        return "clip_path_";
    case DebugField::clip_rule_:
        return "clip_rule_";
    case DebugField::color_:
        return "color_";
    case DebugField::color_interpolation_:
        return "color_interpolation_";
    case DebugField::color_interpolation_filters_:
        return "color_interpolation_filters_";
    case DebugField::color_is_current_color_:
        return "color_is_current_color_";
    case DebugField::color_is_inherited_:
        return "color_is_inherited_";
    case DebugField::color_rendering_:
        return "color_rendering_";
    case DebugField::color_scheme_:
        return "color_scheme_";
    case DebugField::color_scheme_flags_is_normal_:
        return "color_scheme_flags_is_normal_";
    case DebugField::color_scheme_forced_:
        return "color_scheme_forced_";
    case DebugField::column_count_:
        return "column_count_";
    case DebugField::column_fill_:
        return "column_fill_";
    case DebugField::column_gap_:
        return "column_gap_";
    case DebugField::column_rule_color_:
        return "column_rule_color_";
    case DebugField::column_rule_style_:
        return "column_rule_style_";
    case DebugField::column_rule_width_:
        return "column_rule_width_";
    case DebugField::column_span_:
        return "column_span_";
    case DebugField::column_width_:
        return "column_width_";
    case DebugField::contain_:
        return "contain_";
    case DebugField::contain_intrinsic_height_:
        return "contain_intrinsic_height_";
    case DebugField::contain_intrinsic_width_:
        return "contain_intrinsic_width_";
    case DebugField::container_name_:
        return "container_name_";
    case DebugField::container_type_:
        return "container_type_";
    case DebugField::content_:
        return "content_";
    case DebugField::content_visibility_:
        return "content_visibility_";
    case DebugField::counter_directives_:
        return "counter_directives_";
    case DebugField::css_dominant_baseline_:
        return "css_dominant_baseline_";
    case DebugField::cursor_:
        return "cursor_";
    case DebugField::cursor_data_:
        return "cursor_data_";
    case DebugField::custom_highlight_names_:
        return "custom_highlight_names_";
    case DebugField::custom_style_callback_depends_on_font_:
        return "custom_style_callback_depends_on_font_";
    case DebugField::cx_:
        return "cx_";
    case DebugField::cy_:
        return "cy_";
    case DebugField::d_:
        return "d_";
    case DebugField::dark_color_scheme_:
        return "dark_color_scheme_";
    case DebugField::depends_on_scroll_state_container_queries_:
        return "depends_on_scroll_state_container_queries_";
    case DebugField::depends_on_size_container_queries_:
        return "depends_on_size_container_queries_";
    case DebugField::depends_on_style_container_queries_:
        return "depends_on_style_container_queries_";
    case DebugField::direction_:
        return "direction_";
    case DebugField::display_:
        return "display_";
    case DebugField::display_layout_custom_name_:
        return "display_layout_custom_name_";
    case DebugField::display_layout_custom_parent_name_:
        return "display_layout_custom_parent_name_";
    case DebugField::document_rules_selectors_:
        return "document_rules_selectors_";
    case DebugField::dominant_baseline_:
        return "dominant_baseline_";
    case DebugField::draggable_region_mode_:
        return "draggable_region_mode_";
    case DebugField::dynamic_range_limit_:
        return "dynamic_range_limit_";
    case DebugField::effective_appearance_:
        return "effective_appearance_";
    case DebugField::effective_touch_action_:
        return "effective_touch_action_";
    case DebugField::effective_z_index_zero_:
        return "effective_z_index_zero_";
    case DebugField::effective_zoom_:
        return "effective_zoom_";
    case DebugField::element_is_view_transition_participant_:
        return "element_is_view_transition_participant_";
    case DebugField::empty_cells_:
        return "empty_cells_";
    case DebugField::empty_cells_is_inherited_:
        return "empty_cells_is_inherited_";
    case DebugField::field_sizing_:
        return "field_sizing_";
    case DebugField::fill_opacity_:
        return "fill_opacity_";
    case DebugField::fill_paint_:
        return "fill_paint_";
    case DebugField::fill_rule_:
        return "fill_rule_";
    case DebugField::filter_:
        return "filter_";
    case DebugField::first_line_depends_on_size_container_queries_:
        return "first_line_depends_on_size_container_queries_";
    case DebugField::flex_basis_:
        return "flex_basis_";
    case DebugField::flex_direction_:
        return "flex_direction_";
    case DebugField::flex_grow_:
        return "flex_grow_";
    case DebugField::flex_shrink_:
        return "flex_shrink_";
    case DebugField::flex_wrap_:
        return "flex_wrap_";
    case DebugField::floating_:
        return "floating_";
    case DebugField::flood_color_:
        return "flood_color_";
    case DebugField::flood_opacity_:
        return "flood_opacity_";
    case DebugField::font_:
        return "font_";
    case DebugField::forced_color_adjust_:
        return "forced_color_adjust_";
    case DebugField::forces_stacking_context_:
        return "forces_stacking_context_";
    case DebugField::grid_auto_columns_:
        return "grid_auto_columns_";
    case DebugField::grid_auto_flow_:
        return "grid_auto_flow_";
    case DebugField::grid_auto_rows_:
        return "grid_auto_rows_";
    case DebugField::grid_column_end_:
        return "grid_column_end_";
    case DebugField::grid_column_start_:
        return "grid_column_start_";
    case DebugField::grid_row_end_:
        return "grid_row_end_";
    case DebugField::grid_row_start_:
        return "grid_row_start_";
    case DebugField::grid_template_areas_:
        return "grid_template_areas_";
    case DebugField::grid_template_columns_:
        return "grid_template_columns_";
    case DebugField::grid_template_rows_:
        return "grid_template_rows_";
    case DebugField::has_anchor_evaluator_:
        return "has_anchor_evaluator_";
    case DebugField::has_anchor_functions_:
        return "has_anchor_functions_";
    case DebugField::has_attr_function_:
        return "has_attr_function_";
    case DebugField::has_author_background_:
        return "has_author_background_";
    case DebugField::has_author_border_:
        return "has_author_border_";
    case DebugField::has_author_border_radius_:
        return "has_author_border_radius_";
    case DebugField::has_author_highlight_colors_:
        return "has_author_highlight_colors_";
    case DebugField::has_auto_clip_:
        return "has_auto_clip_";
    case DebugField::has_auto_column_count_:
        return "has_auto_column_count_";
    case DebugField::has_auto_column_width_:
        return "has_auto_column_width_";
    case DebugField::has_auto_standard_line_clamp_:
        return "has_auto_standard_line_clamp_";
    case DebugField::has_auto_z_index_:
        return "has_auto_z_index_";
    case DebugField::has_clip_path_:
        return "has_clip_path_";
    case DebugField::has_container_relative_units_:
        return "has_container_relative_units_";
    case DebugField::has_current_backdrop_filter_animation_:
        return "has_current_backdrop_filter_animation_";
    case DebugField::has_current_background_color_animation_:
        return "has_current_background_color_animation_";
    case DebugField::has_current_filter_animation_:
        return "has_current_filter_animation_";
    case DebugField::has_current_opacity_animation_:
        return "has_current_opacity_animation_";
    case DebugField::has_current_rotate_animation_:
        return "has_current_rotate_animation_";
    case DebugField::has_current_scale_animation_:
        return "has_current_scale_animation_";
    case DebugField::has_current_transform_animation_:
        return "has_current_transform_animation_";
    case DebugField::has_current_translate_animation_:
        return "has_current_translate_animation_";
    case DebugField::has_em_units_:
        return "has_em_units_";
    case DebugField::has_env_:
        return "has_env_";
    case DebugField::has_explicit_inheritance_:
        return "has_explicit_inheritance_";
    case DebugField::has_explicit_overflow_x_visible_:
        return "has_explicit_overflow_x_visible_";
    case DebugField::has_explicit_overflow_y_visible_:
        return "has_explicit_overflow_y_visible_";
    case DebugField::has_glyph_relative_units_:
        return "has_glyph_relative_units_";
    case DebugField::has_line_height_relative_units_:
        return "has_line_height_relative_units_";
    case DebugField::has_line_if_empty_:
        return "has_line_if_empty_";
    case DebugField::has_logical_direction_relative_units_:
        return "has_logical_direction_relative_units_";
    case DebugField::has_non_ua_highlight_pseudo_styles_:
        return "has_non_ua_highlight_pseudo_styles_";
    case DebugField::has_non_universal_highlight_pseudo_styles_:
        return "has_non_universal_highlight_pseudo_styles_";
    case DebugField::has_root_font_relative_units_:
        return "has_root_font_relative_units_";
    case DebugField::has_variable_declaration_:
        return "has_variable_declaration_";
    case DebugField::has_variable_reference_:
        return "has_variable_reference_";
    case DebugField::height_:
        return "height_";
    case DebugField::highlight_data_:
        return "highlight_data_";
    case DebugField::highlights_depend_on_size_container_queries_:
        return "highlights_depend_on_size_container_queries_";
    case DebugField::horizontal_border_spacing_:
        return "horizontal_border_spacing_";
    case DebugField::hyphenate_limit_chars_:
        return "hyphenate_limit_chars_";
    case DebugField::hyphenation_string_:
        return "hyphenation_string_";
    case DebugField::hyphens_:
        return "hyphens_";
    case DebugField::image_orientation_:
        return "image_orientation_";
    case DebugField::image_rendering_:
        return "image_rendering_";
    case DebugField::in_base_select_appearance_:
        return "in_base_select_appearance_";
    case DebugField::in_forced_colors_mode_:
        return "in_forced_colors_mode_";
    case DebugField::inherited_variables_:
        return "inherited_variables_";
    case DebugField::initial_data_:
        return "initial_data_";
    case DebugField::initial_letter_:
        return "initial_letter_";
    case DebugField::inline_block_baseline_edge_:
        return "inline_block_baseline_edge_";
    case DebugField::inline_style_lost_cascade_:
        return "inline_style_lost_cascade_";
    case DebugField::inside_link_:
        return "inside_link_";
    case DebugField::interactivity_:
        return "interactivity_";
    case DebugField::internal_forced_background_color_:
        return "internal_forced_background_color_";
    case DebugField::internal_forced_border_color_:
        return "internal_forced_border_color_";
    case DebugField::internal_forced_color_:
        return "internal_forced_color_";
    case DebugField::internal_forced_outline_color_:
        return "internal_forced_outline_color_";
    case DebugField::internal_forced_visited_color_:
        return "internal_forced_visited_color_";
    case DebugField::internal_visited_background_color_:
        return "internal_visited_background_color_";
    case DebugField::internal_visited_border_bottom_color_:
        return "internal_visited_border_bottom_color_";
    case DebugField::internal_visited_border_left_color_:
        return "internal_visited_border_left_color_";
    case DebugField::internal_visited_border_right_color_:
        return "internal_visited_border_right_color_";
    case DebugField::internal_visited_border_top_color_:
        return "internal_visited_border_top_color_";
    case DebugField::internal_visited_caret_color_:
        return "internal_visited_caret_color_";
    case DebugField::internal_visited_color_:
        return "internal_visited_color_";
    case DebugField::internal_visited_color_is_current_color_:
        return "internal_visited_color_is_current_color_";
    case DebugField::internal_visited_column_rule_color_:
        return "internal_visited_column_rule_color_";
    case DebugField::internal_visited_fill_paint_:
        return "internal_visited_fill_paint_";
    case DebugField::internal_visited_outline_color_:
        return "internal_visited_outline_color_";
    case DebugField::internal_visited_stroke_paint_:
        return "internal_visited_stroke_paint_";
    case DebugField::internal_visited_text_decoration_color_:
        return "internal_visited_text_decoration_color_";
    case DebugField::internal_visited_text_emphasis_color_:
        return "internal_visited_text_emphasis_color_";
    case DebugField::internal_visited_text_fill_color_:
        return "internal_visited_text_fill_color_";
    case DebugField::internal_visited_text_stroke_color_:
        return "internal_visited_text_stroke_color_";
    case DebugField::interpolate_size_:
        return "interpolate_size_";
    case DebugField::is_ensured_in_display_none_:
        return "is_ensured_in_display_none_";
    case DebugField::is_ensured_outside_flat_tree_:
        return "is_ensured_outside_flat_tree_";
    case DebugField::is_flex_or_grid_or_custom_item_:
        return "is_flex_or_grid_or_custom_item_";
    case DebugField::is_html_inert_:
        return "is_html_inert_";
    case DebugField::is_html_inert_is_inherited_:
        return "is_html_inert_is_inherited_";
    case DebugField::is_in_blockifying_display_:
        return "is_in_blockifying_display_";
    case DebugField::is_in_inlinifying_display_:
        return "is_in_inlinifying_display_";
    case DebugField::is_inside_display_ignoring_floating_children_:
        return "is_inside_display_ignoring_floating_children_";
    case DebugField::is_inside_list_element_:
        return "is_inside_list_element_";
    case DebugField::is_link_:
        return "is_link_";
    case DebugField::is_original_display_inline_type_:
        return "is_original_display_inline_type_";
    case DebugField::is_page_margin_box_:
        return "is_page_margin_box_";
    case DebugField::is_running_backdrop_filter_animation_on_compositor_:
        return "is_running_backdrop_filter_animation_on_compositor_";
    case DebugField::is_running_filter_animation_on_compositor_:
        return "is_running_filter_animation_on_compositor_";
    case DebugField::is_running_opacity_animation_on_compositor_:
        return "is_running_opacity_animation_on_compositor_";
    case DebugField::is_running_rotate_animation_on_compositor_:
        return "is_running_rotate_animation_on_compositor_";
    case DebugField::is_running_scale_animation_on_compositor_:
        return "is_running_scale_animation_on_compositor_";
    case DebugField::is_running_transform_animation_on_compositor_:
        return "is_running_transform_animation_on_compositor_";
    case DebugField::is_running_translate_animation_on_compositor_:
        return "is_running_translate_animation_on_compositor_";
    case DebugField::is_secondary_body_element_:
        return "is_secondary_body_element_";
    case DebugField::is_specified_display_webkit_box_:
        return "is_specified_display_webkit_box_";
    case DebugField::is_stacking_context_without_containment_:
        return "is_stacking_context_without_containment_";
    case DebugField::is_starting_style_:
        return "is_starting_style_";
    case DebugField::isolation_:
        return "isolation_";
    case DebugField::join_style_:
        return "join_style_";
    case DebugField::justify_content_:
        return "justify_content_";
    case DebugField::justify_items_:
        return "justify_items_";
    case DebugField::justify_self_:
        return "justify_self_";
    case DebugField::left_:
        return "left_";
    case DebugField::lighting_color_:
        return "lighting_color_";
    case DebugField::line_break_:
        return "line_break_";
    case DebugField::line_height_:
        return "line_height_";
    case DebugField::list_style_image_:
        return "list_style_image_";
    case DebugField::list_style_position_:
        return "list_style_position_";
    case DebugField::list_style_position_is_inherited_:
        return "list_style_position_is_inherited_";
    case DebugField::list_style_type_:
        return "list_style_type_";
    case DebugField::margin_bottom_:
        return "margin_bottom_";
    case DebugField::margin_left_:
        return "margin_left_";
    case DebugField::margin_right_:
        return "margin_right_";
    case DebugField::margin_top_:
        return "margin_top_";
    case DebugField::marker_end_resource_:
        return "marker_end_resource_";
    case DebugField::marker_mid_resource_:
        return "marker_mid_resource_";
    case DebugField::marker_start_resource_:
        return "marker_start_resource_";
    case DebugField::mask_:
        return "mask_";
    case DebugField::mask_box_image_:
        return "mask_box_image_";
    case DebugField::mask_type_:
        return "mask_type_";
    case DebugField::masonry_slack_:
        return "masonry_slack_";
    case DebugField::masonry_template_tracks_:
        return "masonry_template_tracks_";
    case DebugField::masonry_track_end_:
        return "masonry_track_end_";
    case DebugField::masonry_track_start_:
        return "masonry_track_start_";
    case DebugField::math_baseline_:
        return "math_baseline_";
    case DebugField::math_depth_:
        return "math_depth_";
    case DebugField::math_fraction_bar_thickness_:
        return "math_fraction_bar_thickness_";
    case DebugField::math_l_space_:
        return "math_l_space_";
    case DebugField::math_max_size_:
        return "math_max_size_";
    case DebugField::math_min_size_:
        return "math_min_size_";
    case DebugField::math_padded_depth_:
        return "math_padded_depth_";
    case DebugField::math_padded_v_offset_:
        return "math_padded_v_offset_";
    case DebugField::math_r_space_:
        return "math_r_space_";
    case DebugField::math_shift_:
        return "math_shift_";
    case DebugField::math_style_:
        return "math_style_";
    case DebugField::max_height_:
        return "max_height_";
    case DebugField::max_width_:
        return "max_width_";
    case DebugField::may_have_margin_:
        return "may_have_margin_";
    case DebugField::may_have_padding_:
        return "may_have_padding_";
    case DebugField::min_height_:
        return "min_height_";
    case DebugField::min_width_:
        return "min_width_";
    case DebugField::non_inherited_variables_:
        return "non_inherited_variables_";
    case DebugField::object_fit_:
        return "object_fit_";
    case DebugField::object_position_:
        return "object_position_";
    case DebugField::object_view_box_:
        return "object_view_box_";
    case DebugField::offset_anchor_:
        return "offset_anchor_";
    case DebugField::offset_distance_:
        return "offset_distance_";
    case DebugField::offset_path_:
        return "offset_path_";
    case DebugField::offset_position_:
        return "offset_position_";
    case DebugField::offset_rotate_:
        return "offset_rotate_";
    case DebugField::opacity_:
        return "opacity_";
    case DebugField::order_:
        return "order_";
    case DebugField::origin_trial_test_property_:
        return "origin_trial_test_property_";
    case DebugField::orphans_:
        return "orphans_";
    case DebugField::outline_color_:
        return "outline_color_";
    case DebugField::outline_offset_:
        return "outline_offset_";
    case DebugField::outline_style_:
        return "outline_style_";
    case DebugField::outline_style_is_auto_:
        return "outline_style_is_auto_";
    case DebugField::outline_width_:
        return "outline_width_";
    case DebugField::overflow_anchor_:
        return "overflow_anchor_";
    case DebugField::overflow_clip_margin_:
        return "overflow_clip_margin_";
    case DebugField::overflow_wrap_:
        return "overflow_wrap_";
    case DebugField::overflow_x_:
        return "overflow_x_";
    case DebugField::overflow_y_:
        return "overflow_y_";
    case DebugField::overlay_:
        return "overlay_";
    case DebugField::overscroll_behavior_x_:
        return "overscroll_behavior_x_";
    case DebugField::overscroll_behavior_y_:
        return "overscroll_behavior_y_";
    case DebugField::padding_bottom_:
        return "padding_bottom_";
    case DebugField::padding_left_:
        return "padding_left_";
    case DebugField::padding_right_:
        return "padding_right_";
    case DebugField::padding_top_:
        return "padding_top_";
    case DebugField::page_:
        return "page_";
    case DebugField::page_orientation_:
        return "page_orientation_";
    case DebugField::page_size_:
        return "page_size_";
    case DebugField::page_size_type_:
        return "page_size_type_";
    case DebugField::paint_images_:
        return "paint_images_";
    case DebugField::paint_order_:
        return "paint_order_";
    case DebugField::perspective_:
        return "perspective_";
    case DebugField::perspective_origin_:
        return "perspective_origin_";
    case DebugField::pointer_events_:
        return "pointer_events_";
    case DebugField::pointer_events_is_inherited_:
        return "pointer_events_is_inherited_";
    case DebugField::popover_hide_delay_:
        return "popover_hide_delay_";
    case DebugField::popover_show_delay_:
        return "popover_show_delay_";
    case DebugField::position_:
        return "position_";
    case DebugField::position_anchor_:
        return "position_anchor_";
    case DebugField::position_area_:
        return "position_area_";
    case DebugField::position_area_offsets_:
        return "position_area_offsets_";
    case DebugField::position_try_fallbacks_:
        return "position_try_fallbacks_";
    case DebugField::position_try_order_:
        return "position_try_order_";
    case DebugField::position_visibility_:
        return "position_visibility_";
    case DebugField::prefers_default_scrollbar_styles_:
        return "prefers_default_scrollbar_styles_";
    case DebugField::print_color_adjust_:
        return "print_color_adjust_";
    case DebugField::pseudo_argument_:
        return "pseudo_argument_";
    case DebugField::pseudo_element_styles_:
        return "pseudo_element_styles_";
    case DebugField::quotes_:
        return "quotes_";
    case DebugField::r_:
        return "r_";
    case DebugField::reading_flow_:
        return "reading_flow_";
    case DebugField::requires_accelerated_compositing_for_external_reasons_:
        return "requires_accelerated_compositing_for_external_reasons_";
    case DebugField::resize_:
        return "resize_";
    case DebugField::right_:
        return "right_";
    case DebugField::rotate_:
        return "rotate_";
    case DebugField::row_gap_:
        return "row_gap_";
    case DebugField::rtl_ordering_:
        return "rtl_ordering_";
    case DebugField::rtl_ordering_is_inherited_:
        return "rtl_ordering_is_inherited_";
    case DebugField::ruby_align_:
        return "ruby_align_";
    case DebugField::ruby_position_:
        return "ruby_position_";
    case DebugField::rx_:
        return "rx_";
    case DebugField::ry_:
        return "ry_";
    case DebugField::scale_:
        return "scale_";
    case DebugField::scroll_behavior_:
        return "scroll_behavior_";
    case DebugField::scroll_margin_bottom_:
        return "scroll_margin_bottom_";
    case DebugField::scroll_margin_left_:
        return "scroll_margin_left_";
    case DebugField::scroll_margin_right_:
        return "scroll_margin_right_";
    case DebugField::scroll_margin_top_:
        return "scroll_margin_top_";
    case DebugField::scroll_marker_group_:
        return "scroll_marker_group_";
    case DebugField::scroll_padding_bottom_:
        return "scroll_padding_bottom_";
    case DebugField::scroll_padding_left_:
        return "scroll_padding_left_";
    case DebugField::scroll_padding_right_:
        return "scroll_padding_right_";
    case DebugField::scroll_padding_top_:
        return "scroll_padding_top_";
    case DebugField::scroll_snap_align_:
        return "scroll_snap_align_";
    case DebugField::scroll_snap_stop_:
        return "scroll_snap_stop_";
    case DebugField::scroll_snap_type_:
        return "scroll_snap_type_";
    case DebugField::scroll_start_target_:
        return "scroll_start_target_";
    case DebugField::scroll_start_x_:
        return "scroll_start_x_";
    case DebugField::scroll_start_y_:
        return "scroll_start_y_";
    case DebugField::scroll_timeline_axis_:
        return "scroll_timeline_axis_";
    case DebugField::scroll_timeline_name_:
        return "scroll_timeline_name_";
    case DebugField::scrollbar_color_:
        return "scrollbar_color_";
    case DebugField::scrollbar_gutter_:
        return "scrollbar_gutter_";
    case DebugField::scrollbar_width_:
        return "scrollbar_width_";
    case DebugField::shape_image_threshold_:
        return "shape_image_threshold_";
    case DebugField::shape_margin_:
        return "shape_margin_";
    case DebugField::shape_outside_:
        return "shape_outside_";
    case DebugField::shape_rendering_:
        return "shape_rendering_";
    case DebugField::should_ignore_overflow_property_for_inline_block_baseline_:
        return "should_ignore_overflow_property_for_inline_block_baseline_";
    case DebugField::skips_contents_:
        return "skips_contents_";
    case DebugField::speak_:
        return "speak_";
    case DebugField::standard_line_clamp_:
        return "standard_line_clamp_";
    case DebugField::stop_color_:
        return "stop_color_";
    case DebugField::stop_opacity_:
        return "stop_opacity_";
    case DebugField::stroke_dash_array_:
        return "stroke_dash_array_";
    case DebugField::stroke_dash_offset_:
        return "stroke_dash_offset_";
    case DebugField::stroke_miter_limit_:
        return "stroke_miter_limit_";
    case DebugField::stroke_opacity_:
        return "stroke_opacity_";
    case DebugField::stroke_paint_:
        return "stroke_paint_";
    case DebugField::stroke_width_:
        return "stroke_width_";
    case DebugField::style_type_:
        return "style_type_";
    case DebugField::subtree_is_sticky_:
        return "subtree_is_sticky_";
    case DebugField::subtree_will_change_contents_:
        return "subtree_will_change_contents_";
    case DebugField::tab_size_:
        return "tab_size_";
    case DebugField::table_layout_:
        return "table_layout_";
    case DebugField::tap_highlight_color_:
        return "tap_highlight_color_";
    case DebugField::text_align_:
        return "text_align_";
    case DebugField::text_align_last_:
        return "text_align_last_";
    case DebugField::text_anchor_:
        return "text_anchor_";
    case DebugField::text_autosizing_multiplier_:
        return "text_autosizing_multiplier_";
    case DebugField::text_autospace_:
        return "text_autospace_";
    case DebugField::text_box_edge_:
        return "text_box_edge_";
    case DebugField::text_box_trim_:
        return "text_box_trim_";
    case DebugField::text_combine_:
        return "text_combine_";
    case DebugField::text_decoration_color_:
        return "text_decoration_color_";
    case DebugField::text_decoration_line_:
        return "text_decoration_line_";
    case DebugField::text_decoration_skip_ink_:
        return "text_decoration_skip_ink_";
    case DebugField::text_decoration_style_:
        return "text_decoration_style_";
    case DebugField::text_decoration_thickness_:
        return "text_decoration_thickness_";
    case DebugField::text_emphasis_color_:
        return "text_emphasis_color_";
    case DebugField::text_emphasis_custom_mark_:
        return "text_emphasis_custom_mark_";
    case DebugField::text_emphasis_fill_:
        return "text_emphasis_fill_";
    case DebugField::text_emphasis_mark_:
        return "text_emphasis_mark_";
    case DebugField::text_emphasis_position_:
        return "text_emphasis_position_";
    case DebugField::text_fill_color_:
        return "text_fill_color_";
    case DebugField::text_indent_:
        return "text_indent_";
    case DebugField::text_orientation_:
        return "text_orientation_";
    case DebugField::text_overflow_:
        return "text_overflow_";
    case DebugField::text_security_:
        return "text_security_";
    case DebugField::text_shadow_:
        return "text_shadow_";
    case DebugField::text_size_adjust_:
        return "text_size_adjust_";
    case DebugField::text_stroke_color_:
        return "text_stroke_color_";
    case DebugField::text_stroke_width_:
        return "text_stroke_width_";
    case DebugField::text_transform_:
        return "text_transform_";
    case DebugField::text_transform_is_inherited_:
        return "text_transform_is_inherited_";
    case DebugField::text_underline_offset_:
        return "text_underline_offset_";
    case DebugField::text_underline_position_:
        return "text_underline_position_";
    case DebugField::text_wrap_mode_:
        return "text_wrap_mode_";
    case DebugField::text_wrap_style_:
        return "text_wrap_style_";
    case DebugField::timeline_scope_:
        return "timeline_scope_";
    case DebugField::top_:
        return "top_";
    case DebugField::touch_action_:
        return "touch_action_";
    case DebugField::transform_:
        return "transform_";
    case DebugField::transform_box_:
        return "transform_box_";
    case DebugField::transform_origin_:
        return "transform_origin_";
    case DebugField::transform_style_3d_:
        return "transform_style_3d_";
    case DebugField::transitions_:
        return "transitions_";
    case DebugField::translate_:
        return "translate_";
    case DebugField::ua_shadow_host_data_:
        return "ua_shadow_host_data_";
    case DebugField::unicode_bidi_:
        return "unicode_bidi_";
    case DebugField::user_drag_:
        return "user_drag_";
    case DebugField::user_modify_:
        return "user_modify_";
    case DebugField::user_select_:
        return "user_select_";
    case DebugField::vector_effect_:
        return "vector_effect_";
    case DebugField::vertical_align_:
        return "vertical_align_";
    case DebugField::vertical_align_length_:
        return "vertical_align_length_";
    case DebugField::vertical_border_spacing_:
        return "vertical_border_spacing_";
    case DebugField::view_timeline_axis_:
        return "view_timeline_axis_";
    case DebugField::view_timeline_inset_:
        return "view_timeline_inset_";
    case DebugField::view_timeline_name_:
        return "view_timeline_name_";
    case DebugField::view_transition_capture_mode_:
        return "view_transition_capture_mode_";
    case DebugField::view_transition_class_:
        return "view_transition_class_";
    case DebugField::view_transition_group_:
        return "view_transition_group_";
    case DebugField::view_transition_name_:
        return "view_transition_name_";
    case DebugField::viewport_unit_flags_:
        return "viewport_unit_flags_";
    case DebugField::visibility_:
        return "visibility_";
    case DebugField::visibility_is_inherited_:
        return "visibility_is_inherited_";
    case DebugField::webkit_line_clamp_:
        return "webkit_line_clamp_";
    case DebugField::white_space_collapse_:
        return "white_space_collapse_";
    case DebugField::widows_:
        return "widows_";
    case DebugField::width_:
        return "width_";
    case DebugField::will_change_contents_:
        return "will_change_contents_";
    case DebugField::will_change_properties_:
        return "will_change_properties_";
    case DebugField::will_change_scroll_position_:
        return "will_change_scroll_position_";
    case DebugField::word_break_:
        return "word_break_";
    case DebugField::writing_mode_:
        return "writing_mode_";
    case DebugField::x_:
        return "x_";
    case DebugField::y_:
        return "y_";
    case DebugField::z_index_:
        return "z_index_";
    case DebugField::zoom_:
        return "zoom_";
    }
}

template <typename, typename = void> constexpr bool HasLogging {};

template <typename T> constexpr bool HasLogging<T, std::void_t<decltype(std::stringstream() << std::declval<T>())>> = true;

template <typename> constexpr bool IsPersistent = false;
template <typename T> constexpr bool IsPersistent<Persistent<T>> = true;

template <typename> constexpr bool IsScopedRefPtr = false;
template <typename T> constexpr bool IsScopedRefPtr<scoped_refptr<T>> = true;

template <class T> static std::string DebugStringForField(const T& t)
{
    if constexpr (std::is_same_v<T, bool>) {
        return t ? "true" : "false";
    }
    if constexpr (IsPersistent<T>) {
        if constexpr (HasLogging<typename T::PointeeType>) {
            std::stringstream ss;
            ss << *t;
            return ss.str();
        }
    }
    if constexpr (IsScopedRefPtr<T>) {
        if constexpr (HasLogging<typename T::element_type>) {
            std::stringstream ss;
            ss << *t;
            return ss.str();
        }
    }
    if constexpr (HasLogging<T>) {
        std::stringstream ss;
        ss << t;
        return ss.str();
    }
    return "<unable to print>";
}

Vector<ComputedStyleBase::DebugDiff> ComputedStyleBase::DebugDiffFields(const ComputedStyleBase& o) const
{
    Vector<DebugDiff> diff;
    // Group: rare-inherited-usage-less-than-100-percent
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_)) {
        DebugDiff d;
        d.field = DebugField::text_underline_offset_;
        d.actual
            = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_);
        d.correct
            = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->tap_highlight_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->tap_highlight_color_)) {
        DebugDiff d;
        d.field = DebugField::tap_highlight_color_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->tap_highlight_color_);
        d.correct
            = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->tap_highlight_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->accent_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->accent_color_)) {
        DebugDiff d;
        d.field = DebugField::accent_color_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->accent_color_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->accent_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_depth_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_depth_)) {
        DebugDiff d;
        d.field = DebugField::math_depth_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_depth_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_depth_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->image_orientation_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->image_orientation_)) {
        DebugDiff d;
        d.field = DebugField::image_orientation_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->image_orientation_);
        d.correct
            = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->image_orientation_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_shift_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_shift_)) {
        DebugDiff d;
        d.field = DebugField::math_shift_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_shift_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_shift_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_style_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_style_)) {
        DebugDiff d;
        d.field = DebugField::math_style_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_style_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_style_);
        diff.push_back(std::move(d));
    }

    // Group: inherited_forced_colors
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_
                ->internal_forced_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_
                   ->internal_forced_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_forced_color_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_
                                           ->inherited_forced_colors_data_->internal_forced_color_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_
                                            ->inherited_forced_colors_data_->internal_forced_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_
                ->internal_forced_visited_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_
                   ->internal_forced_visited_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_forced_visited_color_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_
                                           ->inherited_forced_colors_data_->internal_forced_visited_color_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_
                                            ->inherited_forced_colors_data_->internal_forced_visited_color_);
        diff.push_back(std::move(d));
    }

    // Group: inherited_visited
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                ->internal_visited_text_emphasis_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                   ->internal_visited_text_emphasis_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_text_emphasis_color_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_
                                           ->inherited_visited_data_->internal_visited_text_emphasis_color_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_
                                            ->inherited_visited_data_->internal_visited_text_emphasis_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                ->internal_visited_text_fill_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                   ->internal_visited_text_fill_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_text_fill_color_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_
                                           ->inherited_visited_data_->internal_visited_text_fill_color_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_
                                            ->inherited_visited_data_->internal_visited_text_fill_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                ->internal_visited_text_stroke_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                   ->internal_visited_text_stroke_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_text_stroke_color_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_
                                           ->inherited_visited_data_->internal_visited_text_stroke_color_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_
                                            ->inherited_visited_data_->internal_visited_text_stroke_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                ->internal_visited_caret_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                   ->internal_visited_caret_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_caret_color_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_
                                           ->inherited_visited_data_->internal_visited_caret_color_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_
                                            ->inherited_visited_data_->internal_visited_caret_color_);
        diff.push_back(std::move(d));
    }

    // Group: highlight-data
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_data_->highlight_data_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_data_->highlight_data_)) {
        DebugDiff d;
        d.field = DebugField::highlight_data_;
        d.actual = DebugStringForField(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_data_->highlight_data_);
        d.correct = DebugStringForField(
            o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_data_->highlight_data_);
        diff.push_back(std::move(d));
    }

    // Group: rare-inherited-usage-less-than-64-percent-sub
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->dynamic_range_limit_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->dynamic_range_limit_)) {
        DebugDiff d;
        d.field = DebugField::dynamic_range_limit_;
        d.actual
            = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->dynamic_range_limit_);
        d.correct
            = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->dynamic_range_limit_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_)) {
        DebugDiff d;
        d.field = DebugField::text_emphasis_custom_mark_;
        d.actual = DebugStringForField(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_);
        d.correct = DebugStringForField(
            o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ua_shadow_host_data_,
            o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ua_shadow_host_data_))) {
        DebugDiff d;
        d.field = DebugField::ua_shadow_host_data_;
        d.actual
            = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ua_shadow_host_data_);
        d.correct
            = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ua_shadow_host_data_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->scrollbar_color_,
            o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->scrollbar_color_))) {
        DebugDiff d;
        d.field = DebugField::scrollbar_color_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->scrollbar_color_);
        d.correct
            = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->scrollbar_color_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->cursor_data_,
            o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->cursor_data_))) {
        DebugDiff d;
        d.field = DebugField::cursor_data_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->cursor_data_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->cursor_data_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->initial_data_,
            o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->initial_data_))) {
        DebugDiff d;
        d.field = DebugField::initial_data_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->initial_data_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->initial_data_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_zoom_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_zoom_)) {
        DebugDiff d;
        d.field = DebugField::effective_zoom_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_zoom_);
        d.correct
            = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_zoom_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_)) {
        DebugDiff d;
        d.field = DebugField::hyphenate_limit_chars_;
        d.actual
            = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_);
        d.correct = DebugStringForField(
            o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_touch_action_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_touch_action_)) {
        DebugDiff d;
        d.field = DebugField::effective_touch_action_;
        d.actual = DebugStringForField(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_touch_action_);
        d.correct = DebugStringForField(
            o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_touch_action_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_mark_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_mark_)) {
        DebugDiff d;
        d.field = DebugField::text_emphasis_mark_;
        d.actual
            = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_mark_);
        d.correct
            = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_mark_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ruby_align_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ruby_align_)) {
        DebugDiff d;
        d.field = DebugField::ruby_align_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ruby_align_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ruby_align_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->has_line_if_empty_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->has_line_if_empty_)) {
        DebugDiff d;
        d.field = DebugField::has_line_if_empty_;
        d.actual
            = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->has_line_if_empty_);
        d.correct
            = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->has_line_if_empty_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->in_base_select_appearance_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->in_base_select_appearance_)) {
        DebugDiff d;
        d.field = DebugField::in_base_select_appearance_;
        d.actual = DebugStringForField(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->in_base_select_appearance_);
        d.correct = DebugStringForField(
            o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->in_base_select_appearance_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->interactivity_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->interactivity_)) {
        DebugDiff d;
        d.field = DebugField::interactivity_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->interactivity_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->interactivity_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->interpolate_size_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->interpolate_size_)) {
        DebugDiff d;
        d.field = DebugField::interpolate_size_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->interpolate_size_);
        d.correct
            = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->interpolate_size_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_is_sticky_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_is_sticky_)) {
        DebugDiff d;
        d.field = DebugField::subtree_is_sticky_;
        d.actual
            = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_is_sticky_);
        d.correct
            = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_is_sticky_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_will_change_contents_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_will_change_contents_)) {
        DebugDiff d;
        d.field = DebugField::subtree_will_change_contents_;
        d.actual = DebugStringForField(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_will_change_contents_);
        d.correct = DebugStringForField(
            o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_will_change_contents_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_autospace_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_autospace_)) {
        DebugDiff d;
        d.field = DebugField::text_autospace_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_autospace_);
        d.correct
            = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_autospace_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_fill_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_fill_)) {
        DebugDiff d;
        d.field = DebugField::text_emphasis_fill_;
        d.actual
            = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_fill_);
        d.correct
            = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_fill_);
        diff.push_back(std::move(d));
    }

    // Group: rare-inherited-usage-less-than-64-percent
    if (!(rare_inherited_usage_less_than_64_percent_data_->color_scheme_ == o.rare_inherited_usage_less_than_64_percent_data_->color_scheme_)) {
        DebugDiff d;
        d.field = DebugField::color_scheme_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->color_scheme_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->color_scheme_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_ == o.rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_)) {
        DebugDiff d;
        d.field = DebugField::hyphenation_string_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->quotes_, o.rare_inherited_usage_less_than_64_percent_data_->quotes_))) {
        DebugDiff d;
        d.field = DebugField::quotes_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->quotes_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->quotes_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            rare_inherited_usage_less_than_64_percent_data_->list_style_image_, o.rare_inherited_usage_less_than_64_percent_data_->list_style_image_))) {
        DebugDiff d;
        d.field = DebugField::list_style_image_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->list_style_image_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->list_style_image_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            rare_inherited_usage_less_than_64_percent_data_->list_style_type_, o.rare_inherited_usage_less_than_64_percent_data_->list_style_type_))) {
        DebugDiff d;
        d.field = DebugField::list_style_type_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->list_style_type_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->list_style_type_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            rare_inherited_usage_less_than_64_percent_data_->text_shadow_, o.rare_inherited_usage_less_than_64_percent_data_->text_shadow_))) {
        DebugDiff d;
        d.field = DebugField::text_shadow_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->text_shadow_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->text_shadow_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_indent_ == o.rare_inherited_usage_less_than_64_percent_data_->text_indent_)) {
        DebugDiff d;
        d.field = DebugField::text_indent_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->text_indent_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->text_indent_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_ == o.rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_)) {
        DebugDiff d;
        d.field = DebugField::text_size_adjust_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->tab_size_ == o.rare_inherited_usage_less_than_64_percent_data_->tab_size_)) {
        DebugDiff d;
        d.field = DebugField::tab_size_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->tab_size_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->tab_size_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_stroke_width_ == o.rare_inherited_usage_less_than_64_percent_data_->text_stroke_width_)) {
        DebugDiff d;
        d.field = DebugField::text_stroke_width_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->text_stroke_width_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->text_stroke_width_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_ == o.rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_)) {
        DebugDiff d;
        d.field = DebugField::text_emphasis_color_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_fill_color_ == o.rare_inherited_usage_less_than_64_percent_data_->text_fill_color_)) {
        DebugDiff d;
        d.field = DebugField::text_fill_color_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->text_fill_color_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->text_fill_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_ == o.rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_)) {
        DebugDiff d;
        d.field = DebugField::text_stroke_color_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->caret_color_ == o.rare_inherited_usage_less_than_64_percent_data_->caret_color_)) {
        DebugDiff d;
        d.field = DebugField::caret_color_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->caret_color_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->caret_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->orphans_ == o.rare_inherited_usage_less_than_64_percent_data_->orphans_)) {
        DebugDiff d;
        d.field = DebugField::orphans_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->orphans_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->orphans_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->widows_ == o.rare_inherited_usage_less_than_64_percent_data_->widows_)) {
        DebugDiff d;
        d.field = DebugField::widows_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->widows_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->widows_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_box_edge_ == o.rare_inherited_usage_less_than_64_percent_data_->text_box_edge_)) {
        DebugDiff d;
        d.field = DebugField::text_box_edge_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->text_box_edge_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->text_box_edge_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_underline_position_
            == o.rare_inherited_usage_less_than_64_percent_data_->text_underline_position_)) {
        DebugDiff d;
        d.field = DebugField::text_underline_position_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->text_underline_position_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->text_underline_position_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->image_rendering_ == o.rare_inherited_usage_less_than_64_percent_data_->image_rendering_)) {
        DebugDiff d;
        d.field = DebugField::image_rendering_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->image_rendering_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->image_rendering_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->line_break_ == o.rare_inherited_usage_less_than_64_percent_data_->line_break_)) {
        DebugDiff d;
        d.field = DebugField::line_break_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->line_break_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->line_break_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->speak_ == o.rare_inherited_usage_less_than_64_percent_data_->speak_)) {
        DebugDiff d;
        d.field = DebugField::speak_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->speak_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->speak_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_align_last_ == o.rare_inherited_usage_less_than_64_percent_data_->text_align_last_)) {
        DebugDiff d;
        d.field = DebugField::text_align_last_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->text_align_last_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->text_align_last_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->user_select_ == o.rare_inherited_usage_less_than_64_percent_data_->user_select_)) {
        DebugDiff d;
        d.field = DebugField::user_select_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->user_select_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->user_select_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->word_break_ == o.rare_inherited_usage_less_than_64_percent_data_->word_break_)) {
        DebugDiff d;
        d.field = DebugField::word_break_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->word_break_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->word_break_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->forced_color_adjust_ == o.rare_inherited_usage_less_than_64_percent_data_->forced_color_adjust_)) {
        DebugDiff d;
        d.field = DebugField::forced_color_adjust_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->forced_color_adjust_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->forced_color_adjust_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->hyphens_ == o.rare_inherited_usage_less_than_64_percent_data_->hyphens_)) {
        DebugDiff d;
        d.field = DebugField::hyphens_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->hyphens_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->hyphens_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->overflow_wrap_ == o.rare_inherited_usage_less_than_64_percent_data_->overflow_wrap_)) {
        DebugDiff d;
        d.field = DebugField::overflow_wrap_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->overflow_wrap_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->overflow_wrap_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_position_
            == o.rare_inherited_usage_less_than_64_percent_data_->text_emphasis_position_)) {
        DebugDiff d;
        d.field = DebugField::text_emphasis_position_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_position_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->text_emphasis_position_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_orientation_ == o.rare_inherited_usage_less_than_64_percent_data_->text_orientation_)) {
        DebugDiff d;
        d.field = DebugField::text_orientation_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->text_orientation_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->text_orientation_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_security_ == o.rare_inherited_usage_less_than_64_percent_data_->text_security_)) {
        DebugDiff d;
        d.field = DebugField::text_security_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->text_security_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->text_security_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->user_modify_ == o.rare_inherited_usage_less_than_64_percent_data_->user_modify_)) {
        DebugDiff d;
        d.field = DebugField::user_modify_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->user_modify_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->user_modify_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->ruby_position_ == o.rare_inherited_usage_less_than_64_percent_data_->ruby_position_)) {
        DebugDiff d;
        d.field = DebugField::ruby_position_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->ruby_position_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->ruby_position_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_combine_ == o.rare_inherited_usage_less_than_64_percent_data_->text_combine_)) {
        DebugDiff d;
        d.field = DebugField::text_combine_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->text_combine_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->text_combine_);
        diff.push_back(std::move(d));
    }
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_decoration_skip_ink_
            == o.rare_inherited_usage_less_than_64_percent_data_->text_decoration_skip_ink_)) {
        DebugDiff d;
        d.field = DebugField::text_decoration_skip_ink_;
        d.actual = DebugStringForField(rare_inherited_usage_less_than_64_percent_data_->text_decoration_skip_ink_);
        d.correct = DebugStringForField(o.rare_inherited_usage_less_than_64_percent_data_->text_decoration_skip_ink_);
        diff.push_back(std::move(d));
    }

    // Group: grid
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_columns_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_
                   ->grid_template_columns_)) {
        DebugDiff d;
        d.field = DebugField::grid_template_columns_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_columns_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_columns_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_rows_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_
                   ->grid_template_rows_)) {
        DebugDiff d;
        d.field = DebugField::grid_template_rows_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_rows_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_rows_);
        diff.push_back(std::move(d));
    }

    // Group: forced_colors
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
                ->internal_forced_background_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
                   ->internal_forced_background_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_forced_background_color_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->forced_colors_data_->internal_forced_background_color_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->forced_colors_data_->internal_forced_background_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
                ->internal_forced_border_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
                   ->internal_forced_border_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_forced_border_color_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->forced_colors_data_->internal_forced_border_color_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->forced_colors_data_->internal_forced_border_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
                ->internal_forced_outline_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
                   ->internal_forced_outline_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_forced_outline_color_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->forced_colors_data_->internal_forced_outline_color_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->forced_colors_data_->internal_forced_outline_color_);
        diff.push_back(std::move(d));
    }

    // Group: visited
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                ->internal_visited_column_rule_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                   ->internal_visited_column_rule_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_column_rule_color_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->visited_data_->internal_visited_column_rule_color_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->visited_data_->internal_visited_column_rule_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                ->internal_visited_background_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                   ->internal_visited_background_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_background_color_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->visited_data_->internal_visited_background_color_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->visited_data_->internal_visited_background_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                ->internal_visited_border_bottom_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                   ->internal_visited_border_bottom_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_border_bottom_color_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->visited_data_->internal_visited_border_bottom_color_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->visited_data_->internal_visited_border_bottom_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                ->internal_visited_border_left_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                   ->internal_visited_border_left_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_border_left_color_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->visited_data_->internal_visited_border_left_color_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->visited_data_->internal_visited_border_left_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                ->internal_visited_border_right_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                   ->internal_visited_border_right_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_border_right_color_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->visited_data_->internal_visited_border_right_color_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->visited_data_->internal_visited_border_right_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                ->internal_visited_border_top_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                   ->internal_visited_border_top_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_border_top_color_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->visited_data_->internal_visited_border_top_color_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->visited_data_->internal_visited_border_top_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                ->internal_visited_outline_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                   ->internal_visited_outline_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_outline_color_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->visited_data_->internal_visited_outline_color_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->visited_data_->internal_visited_outline_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                ->internal_visited_text_decoration_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                   ->internal_visited_text_decoration_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_text_decoration_color_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->visited_data_->internal_visited_text_decoration_color_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->visited_data_->internal_visited_text_decoration_color_);
        diff.push_back(std::move(d));
    }

    // Group: masonry
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_data_->masonry_template_tracks_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_data_
                   ->masonry_template_tracks_)) {
        DebugDiff d;
        d.field = DebugField::masonry_template_tracks_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->masonry_data_->masonry_template_tracks_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->masonry_data_->masonry_template_tracks_);
        diff.push_back(std::move(d));
    }

    // Group: start
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_x_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_x_)) {
        DebugDiff d;
        d.field = DebugField::scroll_start_x_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_x_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_x_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_y_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_y_)) {
        DebugDiff d;
        d.field = DebugField::scroll_start_y_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_y_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_y_);
        diff.push_back(std::move(d));
    }

    // Group: timeline
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->scroll_timeline_axis_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
                   ->scroll_timeline_axis_)) {
        DebugDiff d;
        d.field = DebugField::scroll_timeline_axis_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->timeline_data_->scroll_timeline_axis_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->timeline_data_->scroll_timeline_axis_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_axis_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
                   ->view_timeline_axis_)) {
        DebugDiff d;
        d.field = DebugField::view_timeline_axis_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_axis_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->timeline_data_->view_timeline_axis_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_inset_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
                   ->view_timeline_inset_)) {
        DebugDiff d;
        d.field = DebugField::view_timeline_inset_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_inset_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->timeline_data_->view_timeline_inset_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->scroll_timeline_name_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
                ->scroll_timeline_name_))) {
        DebugDiff d;
        d.field = DebugField::scroll_timeline_name_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->timeline_data_->scroll_timeline_name_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->timeline_data_->scroll_timeline_name_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->timeline_scope_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->timeline_scope_))) {
        DebugDiff d;
        d.field = DebugField::timeline_scope_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->timeline_scope_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->timeline_scope_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_name_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
                ->view_timeline_name_))) {
        DebugDiff d;
        d.field = DebugField::view_timeline_name_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_name_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->timeline_data_->view_timeline_name_);
        diff.push_back(std::move(d));
    }

    // Group: will-change
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                ->will_change_properties_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                   ->will_change_properties_)) {
        DebugDiff d;
        d.field = DebugField::will_change_properties_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->will_change_data_->will_change_properties_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->will_change_data_->will_change_properties_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_->will_change_contents_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                   ->will_change_contents_)) {
        DebugDiff d;
        d.field = DebugField::will_change_contents_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->will_change_data_->will_change_contents_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->will_change_data_->will_change_contents_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                ->will_change_scroll_position_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                   ->will_change_scroll_position_)) {
        DebugDiff d;
        d.field = DebugField::will_change_scroll_position_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->will_change_data_->will_change_scroll_position_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->will_change_data_->will_change_scroll_position_);
        diff.push_back(std::move(d));
    }

    // Group: math
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_baseline_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_baseline_)) {
        DebugDiff d;
        d.field = DebugField::math_baseline_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_baseline_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_baseline_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_fraction_bar_thickness_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
                   ->math_fraction_bar_thickness_)) {
        DebugDiff d;
        d.field = DebugField::math_fraction_bar_thickness_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
                                           ->math_fraction_bar_thickness_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->math_data_->math_fraction_bar_thickness_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_l_space_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_l_space_)) {
        DebugDiff d;
        d.field = DebugField::math_l_space_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_l_space_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_l_space_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_r_space_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_r_space_)) {
        DebugDiff d;
        d.field = DebugField::math_r_space_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_r_space_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_r_space_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_v_offset_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
                   ->math_padded_v_offset_)) {
        DebugDiff d;
        d.field = DebugField::math_padded_v_offset_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_v_offset_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_v_offset_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_depth_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
                   ->math_padded_depth_)) {
        DebugDiff d;
        d.field = DebugField::math_padded_depth_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_depth_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_depth_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_min_size_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_min_size_)) {
        DebugDiff d;
        d.field = DebugField::math_min_size_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_min_size_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_min_size_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_max_size_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_max_size_)) {
        DebugDiff d;
        d.field = DebugField::math_max_size_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_max_size_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_max_size_);
        diff.push_back(std::move(d));
    }

    // Group: rare-non-inherited-usage-less-than-14-percent-sub
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_group_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_group_)) {
        DebugDiff d;
        d.field = DebugField::view_transition_group_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_group_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_group_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_end_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_end_)) {
        DebugDiff d;
        d.field = DebugField::masonry_track_end_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_end_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_end_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_start_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_start_)) {
        DebugDiff d;
        d.field = DebugField::masonry_track_start_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_start_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_start_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_name_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_name_)) {
        DebugDiff d;
        d.field = DebugField::display_layout_custom_name_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_name_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_name_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_parent_name_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                   ->display_layout_custom_parent_name_)) {
        DebugDiff d;
        d.field = DebugField::display_layout_custom_parent_name_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_parent_name_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_parent_name_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->pseudo_argument_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->pseudo_argument_)) {
        DebugDiff d;
        d.field = DebugField::pseudo_argument_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->pseudo_argument_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->pseudo_argument_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->object_view_box_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->object_view_box_))) {
        DebugDiff d;
        d.field = DebugField::object_view_box_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->object_view_box_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->object_view_box_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->custom_highlight_names_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->custom_highlight_names_))) {
        DebugDiff d;
        d.field = DebugField::custom_highlight_names_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->custom_highlight_names_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->custom_highlight_names_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->counter_directives_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->counter_directives_))) {
        DebugDiff d;
        d.field = DebugField::counter_directives_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->counter_directives_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->counter_directives_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->animations_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->animations_))) {
        DebugDiff d;
        d.field = DebugField::animations_;
        d.actual
            = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->animations_);
        d.correct
            = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->animations_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->transitions_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->transitions_))) {
        DebugDiff d;
        d.field = DebugField::transitions_;
        d.actual
            = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->transitions_);
        d.correct
            = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->transitions_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->callback_selectors_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->callback_selectors_)) {
        DebugDiff d;
        d.field = DebugField::callback_selectors_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->callback_selectors_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->callback_selectors_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_)) {
        DebugDiff d;
        d.field = DebugField::mask_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_)) {
        DebugDiff d;
        d.field = DebugField::mask_box_image_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scope_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scope_)) {
        DebugDiff d;
        d.field = DebugField::anchor_scope_;
        d.actual
            = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scope_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scope_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_)) {
        DebugDiff d;
        d.field = DebugField::overflow_clip_margin_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_anchor_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_anchor_))) {
        DebugDiff d;
        d.field = DebugField::position_anchor_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_anchor_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_anchor_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_))) {
        DebugDiff d;
        d.field = DebugField::anchor_name_;
        d.actual
            = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_);
        d.correct
            = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_name_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_name_))) {
        DebugDiff d;
        d.field = DebugField::container_name_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_name_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_name_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_fallbacks_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_fallbacks_))) {
        DebugDiff d;
        d.field = DebugField::position_try_fallbacks_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_fallbacks_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_fallbacks_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_class_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_class_))) {
        DebugDiff d;
        d.field = DebugField::view_transition_class_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_class_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_class_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_name_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_name_))) {
        DebugDiff d;
        d.field = DebugField::view_transition_name_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_name_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_name_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->document_rules_selectors_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->document_rules_selectors_))) {
        DebugDiff d;
        d.field = DebugField::document_rules_selectors_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->document_rules_selectors_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->document_rules_selectors_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->non_inherited_variables_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->non_inherited_variables_))) {
        DebugDiff d;
        d.field = DebugField::non_inherited_variables_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->non_inherited_variables_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->non_inherited_variables_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_slack_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_slack_)) {
        DebugDiff d;
        d.field = DebugField::masonry_slack_;
        d.actual
            = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_slack_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_slack_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_)) {
        DebugDiff d;
        d.field = DebugField::initial_letter_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_)) {
        DebugDiff d;
        d.field = DebugField::page_size_;
        d.actual
            = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_);
        d.correct
            = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->popover_hide_delay_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->popover_hide_delay_)) {
        DebugDiff d;
        d.field = DebugField::popover_hide_delay_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->popover_hide_delay_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->popover_hide_delay_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->popover_show_delay_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->popover_show_delay_)) {
        DebugDiff d;
        d.field = DebugField::popover_show_delay_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->popover_show_delay_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->popover_show_delay_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_bottom_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_bottom_)) {
        DebugDiff d;
        d.field = DebugField::scroll_margin_bottom_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_bottom_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_bottom_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_left_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_left_)) {
        DebugDiff d;
        d.field = DebugField::scroll_margin_left_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_left_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_left_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_right_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_right_)) {
        DebugDiff d;
        d.field = DebugField::scroll_margin_right_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_right_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_right_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_top_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_top_)) {
        DebugDiff d;
        d.field = DebugField::scroll_margin_top_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_top_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_top_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->standard_line_clamp_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->standard_line_clamp_)) {
        DebugDiff d;
        d.field = DebugField::standard_line_clamp_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->standard_line_clamp_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->standard_line_clamp_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_area_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_area_)) {
        DebugDiff d;
        d.field = DebugField::position_area_;
        d.actual
            = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_area_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_area_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_appearance_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_appearance_)) {
        DebugDiff d;
        d.field = DebugField::effective_appearance_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_appearance_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_appearance_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_type_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_type_)) {
        DebugDiff d;
        d.field = DebugField::container_type_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_type_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_type_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_order_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_order_)) {
        DebugDiff d;
        d.field = DebugField::position_try_order_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_order_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_order_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_visibility_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_visibility_)) {
        DebugDiff d;
        d.field = DebugField::position_visibility_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_visibility_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_visibility_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->reading_flow_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->reading_flow_)) {
        DebugDiff d;
        d.field = DebugField::reading_flow_;
        d.actual
            = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->reading_flow_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->reading_flow_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->inline_block_baseline_edge_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->inline_block_baseline_edge_)) {
        DebugDiff d;
        d.field = DebugField::inline_block_baseline_edge_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->inline_block_baseline_edge_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->inline_block_baseline_edge_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overscroll_behavior_x_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overscroll_behavior_x_)) {
        DebugDiff d;
        d.field = DebugField::overscroll_behavior_x_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overscroll_behavior_x_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overscroll_behavior_x_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overscroll_behavior_y_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overscroll_behavior_y_)) {
        DebugDiff d;
        d.field = DebugField::overscroll_behavior_y_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overscroll_behavior_y_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overscroll_behavior_y_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_type_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_type_)) {
        DebugDiff d;
        d.field = DebugField::page_size_type_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_type_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_type_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_marker_group_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_marker_group_)) {
        DebugDiff d;
        d.field = DebugField::scroll_marker_group_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_marker_group_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_marker_group_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scrollbar_width_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scrollbar_width_)) {
        DebugDiff d;
        d.field = DebugField::scrollbar_width_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scrollbar_width_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scrollbar_width_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_capture_mode_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_capture_mode_)) {
        DebugDiff d;
        d.field = DebugField::view_transition_capture_mode_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_capture_mode_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_capture_mode_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->affected_by_css_function_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->affected_by_css_function_)) {
        DebugDiff d;
        d.field = DebugField::affected_by_css_function_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->affected_by_css_function_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->affected_by_css_function_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->align_content_block_center_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->align_content_block_center_)) {
        DebugDiff d;
        d.field = DebugField::align_content_block_center_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->align_content_block_center_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->align_content_block_center_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->can_affect_animations_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->can_affect_animations_)) {
        DebugDiff d;
        d.field = DebugField::can_affect_animations_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->can_affect_animations_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->can_affect_animations_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                ->depends_on_scroll_state_container_queries_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                   ->depends_on_scroll_state_container_queries_)) {
        DebugDiff d;
        d.field = DebugField::depends_on_scroll_state_container_queries_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->depends_on_scroll_state_container_queries_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->depends_on_scroll_state_container_queries_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_size_container_queries_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                   ->depends_on_size_container_queries_)) {
        DebugDiff d;
        d.field = DebugField::depends_on_size_container_queries_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_size_container_queries_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_size_container_queries_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_style_container_queries_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                   ->depends_on_style_container_queries_)) {
        DebugDiff d;
        d.field = DebugField::depends_on_style_container_queries_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_style_container_queries_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->depends_on_style_container_queries_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_z_index_zero_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_z_index_zero_)) {
        DebugDiff d;
        d.field = DebugField::effective_z_index_zero_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_z_index_zero_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_z_index_zero_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->element_is_view_transition_participant_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                   ->element_is_view_transition_participant_)) {
        DebugDiff d;
        d.field = DebugField::element_is_view_transition_participant_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->element_is_view_transition_participant_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->element_is_view_transition_participant_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                ->first_line_depends_on_size_container_queries_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                   ->first_line_depends_on_size_container_queries_)) {
        DebugDiff d;
        d.field = DebugField::first_line_depends_on_size_container_queries_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->first_line_depends_on_size_container_queries_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->first_line_depends_on_size_container_queries_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forces_stacking_context_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forces_stacking_context_)) {
        DebugDiff d;
        d.field = DebugField::forces_stacking_context_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forces_stacking_context_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forces_stacking_context_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_count_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_count_)) {
        DebugDiff d;
        d.field = DebugField::has_auto_column_count_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_count_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_count_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_width_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_width_)) {
        DebugDiff d;
        d.field = DebugField::has_auto_column_width_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_width_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_width_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_backdrop_filter_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                   ->has_current_backdrop_filter_animation_)) {
        DebugDiff d;
        d.field = DebugField::has_current_backdrop_filter_animation_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->has_current_backdrop_filter_animation_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->has_current_backdrop_filter_animation_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_background_color_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                   ->has_current_background_color_animation_)) {
        DebugDiff d;
        d.field = DebugField::has_current_background_color_animation_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->has_current_background_color_animation_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->has_current_background_color_animation_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_filter_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_filter_animation_)) {
        DebugDiff d;
        d.field = DebugField::has_current_filter_animation_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_filter_animation_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_filter_animation_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_opacity_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                   ->has_current_opacity_animation_)) {
        DebugDiff d;
        d.field = DebugField::has_current_opacity_animation_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_opacity_animation_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_opacity_animation_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_rotate_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_rotate_animation_)) {
        DebugDiff d;
        d.field = DebugField::has_current_rotate_animation_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_rotate_animation_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_rotate_animation_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_scale_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_scale_animation_)) {
        DebugDiff d;
        d.field = DebugField::has_current_scale_animation_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_scale_animation_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_scale_animation_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_transform_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                   ->has_current_transform_animation_)) {
        DebugDiff d;
        d.field = DebugField::has_current_transform_animation_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_transform_animation_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_transform_animation_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_translate_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                   ->has_current_translate_animation_)) {
        DebugDiff d;
        d.field = DebugField::has_current_translate_animation_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_translate_animation_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_translate_animation_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_x_visible_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                   ->has_explicit_overflow_x_visible_)) {
        DebugDiff d;
        d.field = DebugField::has_explicit_overflow_x_visible_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_x_visible_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_x_visible_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_y_visible_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                   ->has_explicit_overflow_y_visible_)) {
        DebugDiff d;
        d.field = DebugField::has_explicit_overflow_y_visible_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_y_visible_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_y_visible_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_secondary_body_element_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_secondary_body_element_)) {
        DebugDiff d;
        d.field = DebugField::is_secondary_body_element_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_secondary_body_element_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_secondary_body_element_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_starting_style_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_starting_style_)) {
        DebugDiff d;
        d.field = DebugField::is_starting_style_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_starting_style_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_starting_style_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->outline_style_is_auto_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->outline_style_is_auto_)) {
        DebugDiff d;
        d.field = DebugField::outline_style_is_auto_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->outline_style_is_auto_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->outline_style_is_auto_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overlay_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overlay_)) {
        DebugDiff d;
        d.field = DebugField::overlay_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overlay_);
        d.correct
            = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overlay_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                ->requires_accelerated_compositing_for_external_reasons_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                   ->requires_accelerated_compositing_for_external_reasons_)) {
        DebugDiff d;
        d.field = DebugField::requires_accelerated_compositing_for_external_reasons_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                           ->requires_accelerated_compositing_for_external_reasons_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                            ->requires_accelerated_compositing_for_external_reasons_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_start_target_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_start_target_)) {
        DebugDiff d;
        d.field = DebugField::scroll_start_target_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_start_target_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_start_target_);
        diff.push_back(std::move(d));
    }

    // Group: rare-non-inherited-usage-less-than-100-percent
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_columns_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_columns_)) {
        DebugDiff d;
        d.field = DebugField::grid_auto_columns_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_columns_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_columns_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_rows_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_rows_)) {
        DebugDiff d;
        d.field = DebugField::grid_auto_rows_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_rows_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_rows_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->backdrop_filter_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->backdrop_filter_)) {
        DebugDiff d;
        d.field = DebugField::backdrop_filter_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->backdrop_filter_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->backdrop_filter_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_end_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_end_)) {
        DebugDiff d;
        d.field = DebugField::grid_column_end_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_end_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_end_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_start_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_start_)) {
        DebugDiff d;
        d.field = DebugField::grid_column_start_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_start_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_start_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_end_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_end_)) {
        DebugDiff d;
        d.field = DebugField::grid_row_end_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_end_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_end_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_start_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_start_)) {
        DebugDiff d;
        d.field = DebugField::grid_row_start_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_start_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_start_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->page_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->page_)) {
        DebugDiff d;
        d.field = DebugField::page_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->page_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->page_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                     ->rare_non_inherited_usage_less_than_100_percent_data_->box_reflect_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->box_reflect_))) {
        DebugDiff d;
        d.field = DebugField::box_reflect_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->box_reflect_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->box_reflect_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_thickness_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_thickness_)) {
        DebugDiff d;
        d.field = DebugField::text_decoration_thickness_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_thickness_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_thickness_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_color_)) {
        DebugDiff d;
        d.field = DebugField::column_rule_color_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_color_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_color_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                     ->rare_non_inherited_usage_less_than_100_percent_data_->clip_path_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->clip_path_))) {
        DebugDiff d;
        d.field = DebugField::clip_path_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->clip_path_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->clip_path_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                     ->rare_non_inherited_usage_less_than_100_percent_data_->grid_template_areas_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->grid_template_areas_))) {
        DebugDiff d;
        d.field = DebugField::grid_template_areas_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_template_areas_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_template_areas_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                     ->rare_non_inherited_usage_less_than_100_percent_data_->offset_path_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->offset_path_))) {
        DebugDiff d;
        d.field = DebugField::offset_path_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_path_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_path_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                     ->rare_non_inherited_usage_less_than_100_percent_data_->rotate_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->rotate_))) {
        DebugDiff d;
        d.field = DebugField::rotate_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->rotate_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->rotate_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                     ->rare_non_inherited_usage_less_than_100_percent_data_->scale_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->scale_))) {
        DebugDiff d;
        d.field = DebugField::scale_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->scale_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->scale_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                     ->rare_non_inherited_usage_less_than_100_percent_data_->shape_outside_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->shape_outside_))) {
        DebugDiff d;
        d.field = DebugField::shape_outside_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->shape_outside_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->shape_outside_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                     ->rare_non_inherited_usage_less_than_100_percent_data_->translate_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->translate_))) {
        DebugDiff d;
        d.field = DebugField::translate_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->translate_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->translate_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->column_gap_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->column_gap_)) {
        DebugDiff d;
        d.field = DebugField::column_gap_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_gap_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->column_gap_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->row_gap_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->row_gap_)) {
        DebugDiff d;
        d.field = DebugField::row_gap_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->row_gap_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->row_gap_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->offset_rotate_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->offset_rotate_)) {
        DebugDiff d;
        d.field = DebugField::offset_rotate_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_rotate_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_rotate_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->object_position_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->object_position_)) {
        DebugDiff d;
        d.field = DebugField::object_position_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->object_position_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->object_position_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->offset_anchor_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->offset_anchor_)) {
        DebugDiff d;
        d.field = DebugField::offset_anchor_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_anchor_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_anchor_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->offset_position_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->offset_position_)) {
        DebugDiff d;
        d.field = DebugField::offset_position_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_position_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_position_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_origin_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_origin_)) {
        DebugDiff d;
        d.field = DebugField::perspective_origin_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_origin_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_origin_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->offset_distance_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->offset_distance_)) {
        DebugDiff d;
        d.field = DebugField::offset_distance_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_distance_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_distance_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_bottom_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_bottom_)) {
        DebugDiff d;
        d.field = DebugField::scroll_padding_bottom_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_bottom_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_bottom_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_left_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_left_)) {
        DebugDiff d;
        d.field = DebugField::scroll_padding_left_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_left_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_left_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_right_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_right_)) {
        DebugDiff d;
        d.field = DebugField::scroll_padding_right_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_right_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_right_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_top_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_top_)) {
        DebugDiff d;
        d.field = DebugField::scroll_padding_top_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_top_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_top_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->shape_margin_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->shape_margin_)) {
        DebugDiff d;
        d.field = DebugField::shape_margin_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->shape_margin_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->shape_margin_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->column_width_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->column_width_)) {
        DebugDiff d;
        d.field = DebugField::column_width_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_width_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->column_width_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_)) {
        DebugDiff d;
        d.field = DebugField::perspective_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->shape_image_threshold_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->shape_image_threshold_)) {
        DebugDiff d;
        d.field = DebugField::shape_image_threshold_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->shape_image_threshold_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->shape_image_threshold_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_type_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_type_)) {
        DebugDiff d;
        d.field = DebugField::scroll_snap_type_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_type_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_type_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_align_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_align_)) {
        DebugDiff d;
        d.field = DebugField::scroll_snap_align_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_align_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_align_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->outline_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->outline_color_)) {
        DebugDiff d;
        d.field = DebugField::outline_color_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->outline_color_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->outline_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_color_)) {
        DebugDiff d;
        d.field = DebugField::text_decoration_color_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_color_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_color_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->box_ordinal_group_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->box_ordinal_group_)) {
        DebugDiff d;
        d.field = DebugField::box_ordinal_group_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->box_ordinal_group_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->box_ordinal_group_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_width_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_width_)) {
        DebugDiff d;
        d.field = DebugField::column_rule_width_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_width_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_width_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->column_count_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->column_count_)) {
        DebugDiff d;
        d.field = DebugField::column_count_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_count_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->column_count_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->justify_items_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->justify_items_)) {
        DebugDiff d;
        d.field = DebugField::justify_items_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->justify_items_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->justify_items_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->justify_self_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->justify_self_)) {
        DebugDiff d;
        d.field = DebugField::justify_self_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->justify_self_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->justify_self_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->blend_mode_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->blend_mode_)) {
        DebugDiff d;
        d.field = DebugField::blend_mode_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->blend_mode_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->blend_mode_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->contain_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->contain_)) {
        DebugDiff d;
        d.field = DebugField::contain_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->contain_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->contain_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->break_after_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->break_after_)) {
        DebugDiff d;
        d.field = DebugField::break_after_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->break_after_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->break_after_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->break_before_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->break_before_)) {
        DebugDiff d;
        d.field = DebugField::break_before_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->break_before_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->break_before_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_style_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_style_)) {
        DebugDiff d;
        d.field = DebugField::column_rule_style_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_style_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_style_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_flow_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_flow_)) {
        DebugDiff d;
        d.field = DebugField::grid_auto_flow_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_flow_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_flow_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_style_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_style_)) {
        DebugDiff d;
        d.field = DebugField::text_decoration_style_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_style_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_style_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->break_inside_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->break_inside_)) {
        DebugDiff d;
        d.field = DebugField::break_inside_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->break_inside_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->break_inside_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->column_fill_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->column_fill_)) {
        DebugDiff d;
        d.field = DebugField::column_fill_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_fill_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->column_fill_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->draggable_region_mode_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->draggable_region_mode_)) {
        DebugDiff d;
        d.field = DebugField::draggable_region_mode_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->draggable_region_mode_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->draggable_region_mode_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->page_orientation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->page_orientation_)) {
        DebugDiff d;
        d.field = DebugField::page_orientation_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->page_orientation_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->page_orientation_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_behavior_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_behavior_)) {
        DebugDiff d;
        d.field = DebugField::scroll_behavior_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_behavior_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_behavior_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->user_drag_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->user_drag_)) {
        DebugDiff d;
        d.field = DebugField::user_drag_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->user_drag_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->user_drag_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->column_span_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->column_span_)) {
        DebugDiff d;
        d.field = DebugField::column_span_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_span_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->column_span_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->isolation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->isolation_)) {
        DebugDiff d;
        d.field = DebugField::isolation_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->isolation_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->isolation_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->transform_style_3d_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                   ->rare_non_inherited_usage_less_than_100_percent_data_->transform_style_3d_)) {
        DebugDiff d;
        d.field = DebugField::transform_style_3d_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->transform_style_3d_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->transform_style_3d_);
        diff.push_back(std::move(d));
    }

    // Group: rare-non-inherited-usage-less-than-22-percent
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->filter_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->filter_)) {
        DebugDiff d;
        d.field = DebugField::filter_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->filter_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->filter_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_)) {
        DebugDiff d;
        d.field = DebugField::flex_basis_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_);
        d.correct
            = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_grow_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_grow_)) {
        DebugDiff d;
        d.field = DebugField::flex_grow_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_grow_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_grow_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_shrink_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_shrink_)) {
        DebugDiff d;
        d.field = DebugField::flex_shrink_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_shrink_);
        d.correct
            = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_shrink_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_flex_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_flex_)) {
        DebugDiff d;
        d.field = DebugField::box_flex_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_flex_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_flex_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_)) {
        DebugDiff d;
        d.field = DebugField::outline_offset_;
        d.actual
            = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_);
        d.correct
            = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->order_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->order_)) {
        DebugDiff d;
        d.field = DebugField::order_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->order_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->order_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_width_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_width_)) {
        DebugDiff d;
        d.field = DebugField::outline_width_;
        d.actual
            = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_width_);
        d.correct
            = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_width_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->webkit_line_clamp_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->webkit_line_clamp_)) {
        DebugDiff d;
        d.field = DebugField::webkit_line_clamp_;
        d.actual
            = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->webkit_line_clamp_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->webkit_line_clamp_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_)) {
        DebugDiff d;
        d.field = DebugField::align_self_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_);
        d.correct
            = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_)) {
        DebugDiff d;
        d.field = DebugField::align_content_;
        d.actual
            = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_);
        d.correct
            = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->touch_action_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->touch_action_)) {
        DebugDiff d;
        d.field = DebugField::touch_action_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->touch_action_);
        d.correct
            = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->touch_action_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_style_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_style_)) {
        DebugDiff d;
        d.field = DebugField::outline_style_;
        d.actual
            = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_style_);
        d.correct
            = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_style_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_align_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_align_)) {
        DebugDiff d;
        d.field = DebugField::box_align_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_align_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_align_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->object_fit_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->object_fit_)) {
        DebugDiff d;
        d.field = DebugField::object_fit_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->object_fit_);
        d.correct
            = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->object_fit_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->resize_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->resize_)) {
        DebugDiff d;
        d.field = DebugField::resize_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->resize_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->resize_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_pack_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_pack_)) {
        DebugDiff d;
        d.field = DebugField::box_pack_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_pack_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_pack_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->backface_visibility_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->backface_visibility_)) {
        DebugDiff d;
        d.field = DebugField::backface_visibility_;
        d.actual = DebugStringForField(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->backface_visibility_);
        d.correct = DebugStringForField(
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->backface_visibility_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_orient_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_orient_)) {
        DebugDiff d;
        d.field = DebugField::box_orient_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_orient_);
        d.correct
            = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_orient_);
        diff.push_back(std::move(d));
    }

    // Group: rare-non-inherited-usage-less-than-14-percent
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->transform_ == o.rare_non_inherited_usage_less_than_14_percent_data_->transform_)) {
        DebugDiff d;
        d.field = DebugField::transform_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->transform_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->transform_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            rare_non_inherited_usage_less_than_14_percent_data_->box_shadow_, o.rare_non_inherited_usage_less_than_14_percent_data_->box_shadow_))) {
        DebugDiff d;
        d.field = DebugField::box_shadow_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->box_shadow_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->box_shadow_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            rare_non_inherited_usage_less_than_14_percent_data_->content_, o.rare_non_inherited_usage_less_than_14_percent_data_->content_))) {
        DebugDiff d;
        d.field = DebugField::content_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->content_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->content_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->opacity_ == o.rare_non_inherited_usage_less_than_14_percent_data_->opacity_)) {
        DebugDiff d;
        d.field = DebugField::opacity_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->opacity_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->opacity_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->align_items_ == o.rare_non_inherited_usage_less_than_14_percent_data_->align_items_)) {
        DebugDiff d;
        d.field = DebugField::align_items_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->align_items_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->align_items_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->justify_content_ == o.rare_non_inherited_usage_less_than_14_percent_data_->justify_content_)) {
        DebugDiff d;
        d.field = DebugField::justify_content_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->justify_content_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->justify_content_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->appearance_ == o.rare_non_inherited_usage_less_than_14_percent_data_->appearance_)) {
        DebugDiff d;
        d.field = DebugField::appearance_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->appearance_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->appearance_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->flex_direction_ == o.rare_non_inherited_usage_less_than_14_percent_data_->flex_direction_)) {
        DebugDiff d;
        d.field = DebugField::flex_direction_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->flex_direction_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->flex_direction_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->flex_wrap_ == o.rare_non_inherited_usage_less_than_14_percent_data_->flex_wrap_)) {
        DebugDiff d;
        d.field = DebugField::flex_wrap_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->flex_wrap_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->flex_wrap_);
        diff.push_back(std::move(d));
    }
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->text_overflow_ == o.rare_non_inherited_usage_less_than_14_percent_data_->text_overflow_)) {
        DebugDiff d;
        d.field = DebugField::text_overflow_;
        d.actual = DebugStringForField(rare_non_inherited_usage_less_than_14_percent_data_->text_overflow_);
        d.correct = DebugStringForField(o.rare_non_inherited_usage_less_than_14_percent_data_->text_overflow_);
        diff.push_back(std::move(d));
    }

    // Group: inherited
    if (!(base::ValuesEquivalent(inherited_data_->inherited_variables_, o.inherited_data_->inherited_variables_))) {
        DebugDiff d;
        d.field = DebugField::inherited_variables_;
        d.actual = DebugStringForField(inherited_data_->inherited_variables_);
        d.correct = DebugStringForField(o.inherited_data_->inherited_variables_);
        diff.push_back(std::move(d));
    }
    if (!(inherited_data_->line_height_ == o.inherited_data_->line_height_)) {
        DebugDiff d;
        d.field = DebugField::line_height_;
        d.actual = DebugStringForField(inherited_data_->line_height_);
        d.correct = DebugStringForField(o.inherited_data_->line_height_);
        diff.push_back(std::move(d));
    }
    if (!(inherited_data_->text_autosizing_multiplier_ == o.inherited_data_->text_autosizing_multiplier_)) {
        DebugDiff d;
        d.field = DebugField::text_autosizing_multiplier_;
        d.actual = DebugStringForField(inherited_data_->text_autosizing_multiplier_);
        d.correct = DebugStringForField(o.inherited_data_->text_autosizing_multiplier_);
        diff.push_back(std::move(d));
    }
    if (!(inherited_data_->color_ == o.inherited_data_->color_)) {
        DebugDiff d;
        d.field = DebugField::color_;
        d.actual = DebugStringForField(inherited_data_->color_);
        d.correct = DebugStringForField(o.inherited_data_->color_);
        diff.push_back(std::move(d));
    }
    if (!(inherited_data_->internal_visited_color_ == o.inherited_data_->internal_visited_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_color_;
        d.actual = DebugStringForField(inherited_data_->internal_visited_color_);
        d.correct = DebugStringForField(o.inherited_data_->internal_visited_color_);
        diff.push_back(std::move(d));
    }
    if (!(inherited_data_->horizontal_border_spacing_ == o.inherited_data_->horizontal_border_spacing_)) {
        DebugDiff d;
        d.field = DebugField::horizontal_border_spacing_;
        d.actual = DebugStringForField(inherited_data_->horizontal_border_spacing_);
        d.correct = DebugStringForField(o.inherited_data_->horizontal_border_spacing_);
        diff.push_back(std::move(d));
    }
    if (!(inherited_data_->vertical_border_spacing_ == o.inherited_data_->vertical_border_spacing_)) {
        DebugDiff d;
        d.field = DebugField::vertical_border_spacing_;
        d.actual = DebugStringForField(inherited_data_->vertical_border_spacing_);
        d.correct = DebugStringForField(o.inherited_data_->vertical_border_spacing_);
        diff.push_back(std::move(d));
    }
    if (!(inherited_data_->color_is_current_color_ == o.inherited_data_->color_is_current_color_)) {
        DebugDiff d;
        d.field = DebugField::color_is_current_color_;
        d.actual = DebugStringForField(inherited_data_->color_is_current_color_);
        d.correct = DebugStringForField(o.inherited_data_->color_is_current_color_);
        diff.push_back(std::move(d));
    }
    if (!(inherited_data_->in_forced_colors_mode_ == o.inherited_data_->in_forced_colors_mode_)) {
        DebugDiff d;
        d.field = DebugField::in_forced_colors_mode_;
        d.actual = DebugStringForField(inherited_data_->in_forced_colors_mode_);
        d.correct = DebugStringForField(o.inherited_data_->in_forced_colors_mode_);
        diff.push_back(std::move(d));
    }
    if (!(inherited_data_->internal_visited_color_is_current_color_ == o.inherited_data_->internal_visited_color_is_current_color_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_color_is_current_color_;
        d.actual = DebugStringForField(inherited_data_->internal_visited_color_is_current_color_);
        d.correct = DebugStringForField(o.inherited_data_->internal_visited_color_is_current_color_);
        diff.push_back(std::move(d));
    }

    // Group: visual
    if (!(base::ValuesEquivalent(visual_data_->base_text_decoration_data_, o.visual_data_->base_text_decoration_data_))) {
        DebugDiff d;
        d.field = DebugField::base_text_decoration_data_;
        d.actual = DebugStringForField(visual_data_->base_text_decoration_data_);
        d.correct = DebugStringForField(o.visual_data_->base_text_decoration_data_);
        diff.push_back(std::move(d));
    }
    if (!(visual_data_->clip_ == o.visual_data_->clip_)) {
        DebugDiff d;
        d.field = DebugField::clip_;
        d.actual = DebugStringForField(visual_data_->clip_);
        d.correct = DebugStringForField(o.visual_data_->clip_);
        diff.push_back(std::move(d));
    }
    if (!(visual_data_->zoom_ == o.visual_data_->zoom_)) {
        DebugDiff d;
        d.field = DebugField::zoom_;
        d.actual = DebugStringForField(visual_data_->zoom_);
        d.correct = DebugStringForField(o.visual_data_->zoom_);
        diff.push_back(std::move(d));
    }
    if (!(visual_data_->text_decoration_line_ == o.visual_data_->text_decoration_line_)) {
        DebugDiff d;
        d.field = DebugField::text_decoration_line_;
        d.actual = DebugStringForField(visual_data_->text_decoration_line_);
        d.correct = DebugStringForField(o.visual_data_->text_decoration_line_);
        diff.push_back(std::move(d));
    }
    if (!(visual_data_->field_sizing_ == o.visual_data_->field_sizing_)) {
        DebugDiff d;
        d.field = DebugField::field_sizing_;
        d.actual = DebugStringForField(visual_data_->field_sizing_);
        d.correct = DebugStringForField(o.visual_data_->field_sizing_);
        diff.push_back(std::move(d));
    }
    if (!(visual_data_->has_auto_clip_ == o.visual_data_->has_auto_clip_)) {
        DebugDiff d;
        d.field = DebugField::has_auto_clip_;
        d.actual = DebugStringForField(visual_data_->has_auto_clip_);
        d.correct = DebugStringForField(o.visual_data_->has_auto_clip_);
        diff.push_back(std::move(d));
    }
    if (!(visual_data_->has_clip_path_ == o.visual_data_->has_clip_path_)) {
        DebugDiff d;
        d.field = DebugField::has_clip_path_;
        d.actual = DebugStringForField(visual_data_->has_clip_path_);
        d.correct = DebugStringForField(o.visual_data_->has_clip_path_);
        diff.push_back(std::move(d));
    }

    // Group: misc
    if (!(svg_data_->misc_data_->baseline_shift_ == o.svg_data_->misc_data_->baseline_shift_)) {
        DebugDiff d;
        d.field = DebugField::baseline_shift_;
        d.actual = DebugStringForField(svg_data_->misc_data_->baseline_shift_);
        d.correct = DebugStringForField(o.svg_data_->misc_data_->baseline_shift_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->misc_data_->flood_opacity_ == o.svg_data_->misc_data_->flood_opacity_)) {
        DebugDiff d;
        d.field = DebugField::flood_opacity_;
        d.actual = DebugStringForField(svg_data_->misc_data_->flood_opacity_);
        d.correct = DebugStringForField(o.svg_data_->misc_data_->flood_opacity_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->misc_data_->flood_color_ == o.svg_data_->misc_data_->flood_color_)) {
        DebugDiff d;
        d.field = DebugField::flood_color_;
        d.actual = DebugStringForField(svg_data_->misc_data_->flood_color_);
        d.correct = DebugStringForField(o.svg_data_->misc_data_->flood_color_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->misc_data_->lighting_color_ == o.svg_data_->misc_data_->lighting_color_)) {
        DebugDiff d;
        d.field = DebugField::lighting_color_;
        d.actual = DebugStringForField(svg_data_->misc_data_->lighting_color_);
        d.correct = DebugStringForField(o.svg_data_->misc_data_->lighting_color_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->misc_data_->baseline_shift_type_ == o.svg_data_->misc_data_->baseline_shift_type_)) {
        DebugDiff d;
        d.field = DebugField::baseline_shift_type_;
        d.actual = DebugStringForField(svg_data_->misc_data_->baseline_shift_type_);
        d.correct = DebugStringForField(o.svg_data_->misc_data_->baseline_shift_type_);
        diff.push_back(std::move(d));
    }

    // Group: geometry
    if (!(base::ValuesEquivalent(svg_data_->geometry_data_->d_, o.svg_data_->geometry_data_->d_))) {
        DebugDiff d;
        d.field = DebugField::d_;
        d.actual = DebugStringForField(svg_data_->geometry_data_->d_);
        d.correct = DebugStringForField(o.svg_data_->geometry_data_->d_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->geometry_data_->cx_ == o.svg_data_->geometry_data_->cx_)) {
        DebugDiff d;
        d.field = DebugField::cx_;
        d.actual = DebugStringForField(svg_data_->geometry_data_->cx_);
        d.correct = DebugStringForField(o.svg_data_->geometry_data_->cx_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->geometry_data_->cy_ == o.svg_data_->geometry_data_->cy_)) {
        DebugDiff d;
        d.field = DebugField::cy_;
        d.actual = DebugStringForField(svg_data_->geometry_data_->cy_);
        d.correct = DebugStringForField(o.svg_data_->geometry_data_->cy_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->geometry_data_->r_ == o.svg_data_->geometry_data_->r_)) {
        DebugDiff d;
        d.field = DebugField::r_;
        d.actual = DebugStringForField(svg_data_->geometry_data_->r_);
        d.correct = DebugStringForField(o.svg_data_->geometry_data_->r_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->geometry_data_->rx_ == o.svg_data_->geometry_data_->rx_)) {
        DebugDiff d;
        d.field = DebugField::rx_;
        d.actual = DebugStringForField(svg_data_->geometry_data_->rx_);
        d.correct = DebugStringForField(o.svg_data_->geometry_data_->rx_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->geometry_data_->ry_ == o.svg_data_->geometry_data_->ry_)) {
        DebugDiff d;
        d.field = DebugField::ry_;
        d.actual = DebugStringForField(svg_data_->geometry_data_->ry_);
        d.correct = DebugStringForField(o.svg_data_->geometry_data_->ry_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->geometry_data_->x_ == o.svg_data_->geometry_data_->x_)) {
        DebugDiff d;
        d.field = DebugField::x_;
        d.actual = DebugStringForField(svg_data_->geometry_data_->x_);
        d.correct = DebugStringForField(o.svg_data_->geometry_data_->x_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->geometry_data_->y_ == o.svg_data_->geometry_data_->y_)) {
        DebugDiff d;
        d.field = DebugField::y_;
        d.actual = DebugStringForField(svg_data_->geometry_data_->y_);
        d.correct = DebugStringForField(o.svg_data_->geometry_data_->y_);
        diff.push_back(std::move(d));
    }

    // Group: fill
    if (!(svg_data_->fill_data_->fill_paint_ == o.svg_data_->fill_data_->fill_paint_)) {
        DebugDiff d;
        d.field = DebugField::fill_paint_;
        d.actual = DebugStringForField(svg_data_->fill_data_->fill_paint_);
        d.correct = DebugStringForField(o.svg_data_->fill_data_->fill_paint_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->fill_data_->internal_visited_fill_paint_ == o.svg_data_->fill_data_->internal_visited_fill_paint_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_fill_paint_;
        d.actual = DebugStringForField(svg_data_->fill_data_->internal_visited_fill_paint_);
        d.correct = DebugStringForField(o.svg_data_->fill_data_->internal_visited_fill_paint_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->fill_data_->fill_opacity_ == o.svg_data_->fill_data_->fill_opacity_)) {
        DebugDiff d;
        d.field = DebugField::fill_opacity_;
        d.actual = DebugStringForField(svg_data_->fill_data_->fill_opacity_);
        d.correct = DebugStringForField(o.svg_data_->fill_data_->fill_opacity_);
        diff.push_back(std::move(d));
    }

    // Group: stroke
    if (!(base::ValuesEquivalent(svg_data_->stroke_data_->stroke_dash_array_, o.svg_data_->stroke_data_->stroke_dash_array_))) {
        DebugDiff d;
        d.field = DebugField::stroke_dash_array_;
        d.actual = DebugStringForField(svg_data_->stroke_data_->stroke_dash_array_);
        d.correct = DebugStringForField(o.svg_data_->stroke_data_->stroke_dash_array_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->stroke_data_->internal_visited_stroke_paint_ == o.svg_data_->stroke_data_->internal_visited_stroke_paint_)) {
        DebugDiff d;
        d.field = DebugField::internal_visited_stroke_paint_;
        d.actual = DebugStringForField(svg_data_->stroke_data_->internal_visited_stroke_paint_);
        d.correct = DebugStringForField(o.svg_data_->stroke_data_->internal_visited_stroke_paint_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->stroke_data_->stroke_paint_ == o.svg_data_->stroke_data_->stroke_paint_)) {
        DebugDiff d;
        d.field = DebugField::stroke_paint_;
        d.actual = DebugStringForField(svg_data_->stroke_data_->stroke_paint_);
        d.correct = DebugStringForField(o.svg_data_->stroke_data_->stroke_paint_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->stroke_data_->stroke_dash_offset_ == o.svg_data_->stroke_data_->stroke_dash_offset_)) {
        DebugDiff d;
        d.field = DebugField::stroke_dash_offset_;
        d.actual = DebugStringForField(svg_data_->stroke_data_->stroke_dash_offset_);
        d.correct = DebugStringForField(o.svg_data_->stroke_data_->stroke_dash_offset_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->stroke_data_->stroke_width_ == o.svg_data_->stroke_data_->stroke_width_)) {
        DebugDiff d;
        d.field = DebugField::stroke_width_;
        d.actual = DebugStringForField(svg_data_->stroke_data_->stroke_width_);
        d.correct = DebugStringForField(o.svg_data_->stroke_data_->stroke_width_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->stroke_data_->stroke_miter_limit_ == o.svg_data_->stroke_data_->stroke_miter_limit_)) {
        DebugDiff d;
        d.field = DebugField::stroke_miter_limit_;
        d.actual = DebugStringForField(svg_data_->stroke_data_->stroke_miter_limit_);
        d.correct = DebugStringForField(o.svg_data_->stroke_data_->stroke_miter_limit_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->stroke_data_->stroke_opacity_ == o.svg_data_->stroke_data_->stroke_opacity_)) {
        DebugDiff d;
        d.field = DebugField::stroke_opacity_;
        d.actual = DebugStringForField(svg_data_->stroke_data_->stroke_opacity_);
        d.correct = DebugStringForField(o.svg_data_->stroke_data_->stroke_opacity_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->stroke_data_->cap_style_ == o.svg_data_->stroke_data_->cap_style_)) {
        DebugDiff d;
        d.field = DebugField::cap_style_;
        d.actual = DebugStringForField(svg_data_->stroke_data_->cap_style_);
        d.correct = DebugStringForField(o.svg_data_->stroke_data_->cap_style_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->stroke_data_->join_style_ == o.svg_data_->stroke_data_->join_style_)) {
        DebugDiff d;
        d.field = DebugField::join_style_;
        d.actual = DebugStringForField(svg_data_->stroke_data_->join_style_);
        d.correct = DebugStringForField(o.svg_data_->stroke_data_->join_style_);
        diff.push_back(std::move(d));
    }

    // Group: inherited_resources
    if (!(base::ValuesEquivalent(svg_data_->inherited_resources_data_->marker_end_resource_, o.svg_data_->inherited_resources_data_->marker_end_resource_))) {
        DebugDiff d;
        d.field = DebugField::marker_end_resource_;
        d.actual = DebugStringForField(svg_data_->inherited_resources_data_->marker_end_resource_);
        d.correct = DebugStringForField(o.svg_data_->inherited_resources_data_->marker_end_resource_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(svg_data_->inherited_resources_data_->marker_mid_resource_, o.svg_data_->inherited_resources_data_->marker_mid_resource_))) {
        DebugDiff d;
        d.field = DebugField::marker_mid_resource_;
        d.actual = DebugStringForField(svg_data_->inherited_resources_data_->marker_mid_resource_);
        d.correct = DebugStringForField(o.svg_data_->inherited_resources_data_->marker_mid_resource_);
        diff.push_back(std::move(d));
    }
    if (!(base::ValuesEquivalent(
            svg_data_->inherited_resources_data_->marker_start_resource_, o.svg_data_->inherited_resources_data_->marker_start_resource_))) {
        DebugDiff d;
        d.field = DebugField::marker_start_resource_;
        d.actual = DebugStringForField(svg_data_->inherited_resources_data_->marker_start_resource_);
        d.correct = DebugStringForField(o.svg_data_->inherited_resources_data_->marker_start_resource_);
        diff.push_back(std::move(d));
    }

    // Group: stop
    if (!(svg_data_->stop_data_->stop_opacity_ == o.svg_data_->stop_data_->stop_opacity_)) {
        DebugDiff d;
        d.field = DebugField::stop_opacity_;
        d.actual = DebugStringForField(svg_data_->stop_data_->stop_opacity_);
        d.correct = DebugStringForField(o.svg_data_->stop_data_->stop_opacity_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->stop_data_->stop_color_ == o.svg_data_->stop_data_->stop_color_)) {
        DebugDiff d;
        d.field = DebugField::stop_color_;
        d.actual = DebugStringForField(svg_data_->stop_data_->stop_color_);
        d.correct = DebugStringForField(o.svg_data_->stop_data_->stop_color_);
        diff.push_back(std::move(d));
    }

    // Group: svg
    if (!(svg_data_->transform_origin_ == o.svg_data_->transform_origin_)) {
        DebugDiff d;
        d.field = DebugField::transform_origin_;
        d.actual = DebugStringForField(svg_data_->transform_origin_);
        d.correct = DebugStringForField(o.svg_data_->transform_origin_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->alignment_baseline_ == o.svg_data_->alignment_baseline_)) {
        DebugDiff d;
        d.field = DebugField::alignment_baseline_;
        d.actual = DebugStringForField(svg_data_->alignment_baseline_);
        d.correct = DebugStringForField(o.svg_data_->alignment_baseline_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->css_dominant_baseline_ == o.svg_data_->css_dominant_baseline_)) {
        DebugDiff d;
        d.field = DebugField::css_dominant_baseline_;
        d.actual = DebugStringForField(svg_data_->css_dominant_baseline_);
        d.correct = DebugStringForField(o.svg_data_->css_dominant_baseline_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->dominant_baseline_ == o.svg_data_->dominant_baseline_)) {
        DebugDiff d;
        d.field = DebugField::dominant_baseline_;
        d.actual = DebugStringForField(svg_data_->dominant_baseline_);
        d.correct = DebugStringForField(o.svg_data_->dominant_baseline_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->paint_order_ == o.svg_data_->paint_order_)) {
        DebugDiff d;
        d.field = DebugField::paint_order_;
        d.actual = DebugStringForField(svg_data_->paint_order_);
        d.correct = DebugStringForField(o.svg_data_->paint_order_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->buffered_rendering_ == o.svg_data_->buffered_rendering_)) {
        DebugDiff d;
        d.field = DebugField::buffered_rendering_;
        d.actual = DebugStringForField(svg_data_->buffered_rendering_);
        d.correct = DebugStringForField(o.svg_data_->buffered_rendering_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->color_interpolation_ == o.svg_data_->color_interpolation_)) {
        DebugDiff d;
        d.field = DebugField::color_interpolation_;
        d.actual = DebugStringForField(svg_data_->color_interpolation_);
        d.correct = DebugStringForField(o.svg_data_->color_interpolation_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->color_interpolation_filters_ == o.svg_data_->color_interpolation_filters_)) {
        DebugDiff d;
        d.field = DebugField::color_interpolation_filters_;
        d.actual = DebugStringForField(svg_data_->color_interpolation_filters_);
        d.correct = DebugStringForField(o.svg_data_->color_interpolation_filters_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->color_rendering_ == o.svg_data_->color_rendering_)) {
        DebugDiff d;
        d.field = DebugField::color_rendering_;
        d.actual = DebugStringForField(svg_data_->color_rendering_);
        d.correct = DebugStringForField(o.svg_data_->color_rendering_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->shape_rendering_ == o.svg_data_->shape_rendering_)) {
        DebugDiff d;
        d.field = DebugField::shape_rendering_;
        d.actual = DebugStringForField(svg_data_->shape_rendering_);
        d.correct = DebugStringForField(o.svg_data_->shape_rendering_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->text_anchor_ == o.svg_data_->text_anchor_)) {
        DebugDiff d;
        d.field = DebugField::text_anchor_;
        d.actual = DebugStringForField(svg_data_->text_anchor_);
        d.correct = DebugStringForField(o.svg_data_->text_anchor_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->clip_rule_ == o.svg_data_->clip_rule_)) {
        DebugDiff d;
        d.field = DebugField::clip_rule_;
        d.actual = DebugStringForField(svg_data_->clip_rule_);
        d.correct = DebugStringForField(o.svg_data_->clip_rule_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->fill_rule_ == o.svg_data_->fill_rule_)) {
        DebugDiff d;
        d.field = DebugField::fill_rule_;
        d.actual = DebugStringForField(svg_data_->fill_rule_);
        d.correct = DebugStringForField(o.svg_data_->fill_rule_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->mask_type_ == o.svg_data_->mask_type_)) {
        DebugDiff d;
        d.field = DebugField::mask_type_;
        d.actual = DebugStringForField(svg_data_->mask_type_);
        d.correct = DebugStringForField(o.svg_data_->mask_type_);
        diff.push_back(std::move(d));
    }
    if (!(svg_data_->vector_effect_ == o.svg_data_->vector_effect_)) {
        DebugDiff d;
        d.field = DebugField::vector_effect_;
        d.actual = DebugStringForField(svg_data_->vector_effect_);
        d.correct = DebugStringForField(o.svg_data_->vector_effect_);
        diff.push_back(std::move(d));
    }

    // Group: surround
    if (!(surround_data_->border_image_ == o.surround_data_->border_image_)) {
        DebugDiff d;
        d.field = DebugField::border_image_;
        d.actual = DebugStringForField(surround_data_->border_image_);
        d.correct = DebugStringForField(o.surround_data_->border_image_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->aspect_ratio_ == o.surround_data_->aspect_ratio_)) {
        DebugDiff d;
        d.field = DebugField::aspect_ratio_;
        d.actual = DebugStringForField(surround_data_->aspect_ratio_);
        d.correct = DebugStringForField(o.surround_data_->aspect_ratio_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->contain_intrinsic_height_ == o.surround_data_->contain_intrinsic_height_)) {
        DebugDiff d;
        d.field = DebugField::contain_intrinsic_height_;
        d.actual = DebugStringForField(surround_data_->contain_intrinsic_height_);
        d.correct = DebugStringForField(o.surround_data_->contain_intrinsic_height_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->contain_intrinsic_width_ == o.surround_data_->contain_intrinsic_width_)) {
        DebugDiff d;
        d.field = DebugField::contain_intrinsic_width_;
        d.actual = DebugStringForField(surround_data_->contain_intrinsic_width_);
        d.correct = DebugStringForField(o.surround_data_->contain_intrinsic_width_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->border_bottom_left_radius_ == o.surround_data_->border_bottom_left_radius_)) {
        DebugDiff d;
        d.field = DebugField::border_bottom_left_radius_;
        d.actual = DebugStringForField(surround_data_->border_bottom_left_radius_);
        d.correct = DebugStringForField(o.surround_data_->border_bottom_left_radius_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->border_bottom_right_radius_ == o.surround_data_->border_bottom_right_radius_)) {
        DebugDiff d;
        d.field = DebugField::border_bottom_right_radius_;
        d.actual = DebugStringForField(surround_data_->border_bottom_right_radius_);
        d.correct = DebugStringForField(o.surround_data_->border_bottom_right_radius_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->border_top_left_radius_ == o.surround_data_->border_top_left_radius_)) {
        DebugDiff d;
        d.field = DebugField::border_top_left_radius_;
        d.actual = DebugStringForField(surround_data_->border_top_left_radius_);
        d.correct = DebugStringForField(o.surround_data_->border_top_left_radius_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->border_top_right_radius_ == o.surround_data_->border_top_right_radius_)) {
        DebugDiff d;
        d.field = DebugField::border_top_right_radius_;
        d.actual = DebugStringForField(surround_data_->border_top_right_radius_);
        d.correct = DebugStringForField(o.surround_data_->border_top_right_radius_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->bottom_ == o.surround_data_->bottom_)) {
        DebugDiff d;
        d.field = DebugField::bottom_;
        d.actual = DebugStringForField(surround_data_->bottom_);
        d.correct = DebugStringForField(o.surround_data_->bottom_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->left_ == o.surround_data_->left_)) {
        DebugDiff d;
        d.field = DebugField::left_;
        d.actual = DebugStringForField(surround_data_->left_);
        d.correct = DebugStringForField(o.surround_data_->left_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->right_ == o.surround_data_->right_)) {
        DebugDiff d;
        d.field = DebugField::right_;
        d.actual = DebugStringForField(surround_data_->right_);
        d.correct = DebugStringForField(o.surround_data_->right_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->top_ == o.surround_data_->top_)) {
        DebugDiff d;
        d.field = DebugField::top_;
        d.actual = DebugStringForField(surround_data_->top_);
        d.correct = DebugStringForField(o.surround_data_->top_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->border_bottom_color_ == o.surround_data_->border_bottom_color_)) {
        DebugDiff d;
        d.field = DebugField::border_bottom_color_;
        d.actual = DebugStringForField(surround_data_->border_bottom_color_);
        d.correct = DebugStringForField(o.surround_data_->border_bottom_color_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->border_left_color_ == o.surround_data_->border_left_color_)) {
        DebugDiff d;
        d.field = DebugField::border_left_color_;
        d.actual = DebugStringForField(surround_data_->border_left_color_);
        d.correct = DebugStringForField(o.surround_data_->border_left_color_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->border_right_color_ == o.surround_data_->border_right_color_)) {
        DebugDiff d;
        d.field = DebugField::border_right_color_;
        d.actual = DebugStringForField(surround_data_->border_right_color_);
        d.correct = DebugStringForField(o.surround_data_->border_right_color_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->border_top_color_ == o.surround_data_->border_top_color_)) {
        DebugDiff d;
        d.field = DebugField::border_top_color_;
        d.actual = DebugStringForField(surround_data_->border_top_color_);
        d.correct = DebugStringForField(o.surround_data_->border_top_color_);
        diff.push_back(std::move(d));
    }
    if (!(surround_data_->has_anchor_evaluator_ == o.surround_data_->has_anchor_evaluator_)) {
        DebugDiff d;
        d.field = DebugField::has_anchor_evaluator_;
        d.actual = DebugStringForField(surround_data_->has_anchor_evaluator_);
        d.correct = DebugStringForField(o.surround_data_->has_anchor_evaluator_);
        diff.push_back(std::move(d));
    }

    // Group: background
    if (!(background_data_->background_ == o.background_data_->background_)) {
        DebugDiff d;
        d.field = DebugField::background_;
        d.actual = DebugStringForField(background_data_->background_);
        d.correct = DebugStringForField(o.background_data_->background_);
        diff.push_back(std::move(d));
    }
    if (!(background_data_->background_color_ == o.background_data_->background_color_)) {
        DebugDiff d;
        d.field = DebugField::background_color_;
        d.actual = DebugStringForField(background_data_->background_color_);
        d.correct = DebugStringForField(o.background_data_->background_color_);
        diff.push_back(std::move(d));
    }

    // Group: box
    if (!(box_data_->height_ == o.box_data_->height_)) {
        DebugDiff d;
        d.field = DebugField::height_;
        d.actual = DebugStringForField(box_data_->height_);
        d.correct = DebugStringForField(o.box_data_->height_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->margin_bottom_ == o.box_data_->margin_bottom_)) {
        DebugDiff d;
        d.field = DebugField::margin_bottom_;
        d.actual = DebugStringForField(box_data_->margin_bottom_);
        d.correct = DebugStringForField(o.box_data_->margin_bottom_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->margin_left_ == o.box_data_->margin_left_)) {
        DebugDiff d;
        d.field = DebugField::margin_left_;
        d.actual = DebugStringForField(box_data_->margin_left_);
        d.correct = DebugStringForField(o.box_data_->margin_left_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->margin_right_ == o.box_data_->margin_right_)) {
        DebugDiff d;
        d.field = DebugField::margin_right_;
        d.actual = DebugStringForField(box_data_->margin_right_);
        d.correct = DebugStringForField(o.box_data_->margin_right_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->margin_top_ == o.box_data_->margin_top_)) {
        DebugDiff d;
        d.field = DebugField::margin_top_;
        d.actual = DebugStringForField(box_data_->margin_top_);
        d.correct = DebugStringForField(o.box_data_->margin_top_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->max_height_ == o.box_data_->max_height_)) {
        DebugDiff d;
        d.field = DebugField::max_height_;
        d.actual = DebugStringForField(box_data_->max_height_);
        d.correct = DebugStringForField(o.box_data_->max_height_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->max_width_ == o.box_data_->max_width_)) {
        DebugDiff d;
        d.field = DebugField::max_width_;
        d.actual = DebugStringForField(box_data_->max_width_);
        d.correct = DebugStringForField(o.box_data_->max_width_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->min_height_ == o.box_data_->min_height_)) {
        DebugDiff d;
        d.field = DebugField::min_height_;
        d.actual = DebugStringForField(box_data_->min_height_);
        d.correct = DebugStringForField(o.box_data_->min_height_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->min_width_ == o.box_data_->min_width_)) {
        DebugDiff d;
        d.field = DebugField::min_width_;
        d.actual = DebugStringForField(box_data_->min_width_);
        d.correct = DebugStringForField(o.box_data_->min_width_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->padding_bottom_ == o.box_data_->padding_bottom_)) {
        DebugDiff d;
        d.field = DebugField::padding_bottom_;
        d.actual = DebugStringForField(box_data_->padding_bottom_);
        d.correct = DebugStringForField(o.box_data_->padding_bottom_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->padding_left_ == o.box_data_->padding_left_)) {
        DebugDiff d;
        d.field = DebugField::padding_left_;
        d.actual = DebugStringForField(box_data_->padding_left_);
        d.correct = DebugStringForField(o.box_data_->padding_left_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->padding_right_ == o.box_data_->padding_right_)) {
        DebugDiff d;
        d.field = DebugField::padding_right_;
        d.actual = DebugStringForField(box_data_->padding_right_);
        d.correct = DebugStringForField(o.box_data_->padding_right_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->padding_top_ == o.box_data_->padding_top_)) {
        DebugDiff d;
        d.field = DebugField::padding_top_;
        d.actual = DebugStringForField(box_data_->padding_top_);
        d.correct = DebugStringForField(o.box_data_->padding_top_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->width_ == o.box_data_->width_)) {
        DebugDiff d;
        d.field = DebugField::width_;
        d.actual = DebugStringForField(box_data_->width_);
        d.correct = DebugStringForField(o.box_data_->width_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->vertical_align_length_ == o.box_data_->vertical_align_length_)) {
        DebugDiff d;
        d.field = DebugField::vertical_align_length_;
        d.actual = DebugStringForField(box_data_->vertical_align_length_);
        d.correct = DebugStringForField(o.box_data_->vertical_align_length_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->border_bottom_width_ == o.box_data_->border_bottom_width_)) {
        DebugDiff d;
        d.field = DebugField::border_bottom_width_;
        d.actual = DebugStringForField(box_data_->border_bottom_width_);
        d.correct = DebugStringForField(o.box_data_->border_bottom_width_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->border_left_width_ == o.box_data_->border_left_width_)) {
        DebugDiff d;
        d.field = DebugField::border_left_width_;
        d.actual = DebugStringForField(box_data_->border_left_width_);
        d.correct = DebugStringForField(o.box_data_->border_left_width_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->border_right_width_ == o.box_data_->border_right_width_)) {
        DebugDiff d;
        d.field = DebugField::border_right_width_;
        d.actual = DebugStringForField(box_data_->border_right_width_);
        d.correct = DebugStringForField(o.box_data_->border_right_width_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->border_top_width_ == o.box_data_->border_top_width_)) {
        DebugDiff d;
        d.field = DebugField::border_top_width_;
        d.actual = DebugStringForField(box_data_->border_top_width_);
        d.correct = DebugStringForField(o.box_data_->border_top_width_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->z_index_ == o.box_data_->z_index_)) {
        DebugDiff d;
        d.field = DebugField::z_index_;
        d.actual = DebugStringForField(box_data_->z_index_);
        d.correct = DebugStringForField(o.box_data_->z_index_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->border_bottom_style_ == o.box_data_->border_bottom_style_)) {
        DebugDiff d;
        d.field = DebugField::border_bottom_style_;
        d.actual = DebugStringForField(box_data_->border_bottom_style_);
        d.correct = DebugStringForField(o.box_data_->border_bottom_style_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->border_left_style_ == o.box_data_->border_left_style_)) {
        DebugDiff d;
        d.field = DebugField::border_left_style_;
        d.actual = DebugStringForField(box_data_->border_left_style_);
        d.correct = DebugStringForField(o.box_data_->border_left_style_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->border_right_style_ == o.box_data_->border_right_style_)) {
        DebugDiff d;
        d.field = DebugField::border_right_style_;
        d.actual = DebugStringForField(box_data_->border_right_style_);
        d.correct = DebugStringForField(o.box_data_->border_right_style_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->border_top_style_ == o.box_data_->border_top_style_)) {
        DebugDiff d;
        d.field = DebugField::border_top_style_;
        d.actual = DebugStringForField(box_data_->border_top_style_);
        d.correct = DebugStringForField(o.box_data_->border_top_style_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->baseline_source_ == o.box_data_->baseline_source_)) {
        DebugDiff d;
        d.field = DebugField::baseline_source_;
        d.actual = DebugStringForField(box_data_->baseline_source_);
        d.correct = DebugStringForField(o.box_data_->baseline_source_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->text_box_trim_ == o.box_data_->text_box_trim_)) {
        DebugDiff d;
        d.field = DebugField::text_box_trim_;
        d.actual = DebugStringForField(box_data_->text_box_trim_);
        d.correct = DebugStringForField(o.box_data_->text_box_trim_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->box_decoration_break_ == o.box_data_->box_decoration_break_)) {
        DebugDiff d;
        d.field = DebugField::box_decoration_break_;
        d.actual = DebugStringForField(box_data_->box_decoration_break_);
        d.correct = DebugStringForField(o.box_data_->box_decoration_break_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->has_auto_standard_line_clamp_ == o.box_data_->has_auto_standard_line_clamp_)) {
        DebugDiff d;
        d.field = DebugField::has_auto_standard_line_clamp_;
        d.actual = DebugStringForField(box_data_->has_auto_standard_line_clamp_);
        d.correct = DebugStringForField(o.box_data_->has_auto_standard_line_clamp_);
        diff.push_back(std::move(d));
    }
    if (!(box_data_->has_auto_z_index_ == o.box_data_->has_auto_z_index_)) {
        DebugDiff d;
        d.field = DebugField::has_auto_z_index_;
        d.actual = DebugStringForField(box_data_->has_auto_z_index_);
        d.correct = DebugStringForField(o.box_data_->has_auto_z_index_);
        diff.push_back(std::move(d));
    }

    // Group: font
    if (!(font_data_->font_ == o.font_data_->font_)) {
        DebugDiff d;
        d.field = DebugField::font_;
        d.actual = DebugStringForField(font_data_->font_);
        d.correct = DebugStringForField(o.font_data_->font_);
        diff.push_back(std::move(d));
    }

    // Group: None
    if (!(data_.cursor_ == o.data_.cursor_)) {
        DebugDiff d;
        d.field = DebugField::cursor_;
        d.actual = DebugStringForField(data_.cursor_);
        d.correct = DebugStringForField(o.data_.cursor_);
        diff.push_back(std::move(d));
    }
    if (!(data_.pointer_events_ == o.data_.pointer_events_)) {
        DebugDiff d;
        d.field = DebugField::pointer_events_;
        d.actual = DebugStringForField(data_.pointer_events_);
        d.correct = DebugStringForField(o.data_.pointer_events_);
        diff.push_back(std::move(d));
    }
    if (!(data_.display_ == o.data_.display_)) {
        DebugDiff d;
        d.field = DebugField::display_;
        d.actual = DebugStringForField(data_.display_);
        d.correct = DebugStringForField(o.data_.display_);
        diff.push_back(std::move(d));
    }
    if (!(data_.scrollbar_gutter_ == o.data_.scrollbar_gutter_)) {
        DebugDiff d;
        d.field = DebugField::scrollbar_gutter_;
        d.actual = DebugStringForField(data_.scrollbar_gutter_);
        d.correct = DebugStringForField(o.data_.scrollbar_gutter_);
        diff.push_back(std::move(d));
    }
    if (!(data_.text_align_ == o.data_.text_align_)) {
        DebugDiff d;
        d.field = DebugField::text_align_;
        d.actual = DebugStringForField(data_.text_align_);
        d.correct = DebugStringForField(o.data_.text_align_);
        diff.push_back(std::move(d));
    }
    if (!(data_.vertical_align_ == o.data_.vertical_align_)) {
        DebugDiff d;
        d.field = DebugField::vertical_align_;
        d.actual = DebugStringForField(data_.vertical_align_);
        d.correct = DebugStringForField(o.data_.vertical_align_);
        diff.push_back(std::move(d));
    }
    if (!(data_.clear_ == o.data_.clear_)) {
        DebugDiff d;
        d.field = DebugField::clear_;
        d.actual = DebugStringForField(data_.clear_);
        d.correct = DebugStringForField(o.data_.clear_);
        diff.push_back(std::move(d));
    }
    if (!(data_.floating_ == o.data_.floating_)) {
        DebugDiff d;
        d.field = DebugField::floating_;
        d.actual = DebugStringForField(data_.floating_);
        d.correct = DebugStringForField(o.data_.floating_);
        diff.push_back(std::move(d));
    }
    if (!(data_.content_visibility_ == o.data_.content_visibility_)) {
        DebugDiff d;
        d.field = DebugField::content_visibility_;
        d.actual = DebugStringForField(data_.content_visibility_);
        d.correct = DebugStringForField(o.data_.content_visibility_);
        diff.push_back(std::move(d));
    }
    if (!(data_.overflow_x_ == o.data_.overflow_x_)) {
        DebugDiff d;
        d.field = DebugField::overflow_x_;
        d.actual = DebugStringForField(data_.overflow_x_);
        d.correct = DebugStringForField(o.data_.overflow_x_);
        diff.push_back(std::move(d));
    }
    if (!(data_.overflow_y_ == o.data_.overflow_y_)) {
        DebugDiff d;
        d.field = DebugField::overflow_y_;
        d.actual = DebugStringForField(data_.overflow_y_);
        d.correct = DebugStringForField(o.data_.overflow_y_);
        diff.push_back(std::move(d));
    }
    if (!(data_.position_ == o.data_.position_)) {
        DebugDiff d;
        d.field = DebugField::position_;
        d.actual = DebugStringForField(data_.position_);
        d.correct = DebugStringForField(o.data_.position_);
        diff.push_back(std::move(d));
    }
    if (!(data_.text_transform_ == o.data_.text_transform_)) {
        DebugDiff d;
        d.field = DebugField::text_transform_;
        d.actual = DebugStringForField(data_.text_transform_);
        d.correct = DebugStringForField(o.data_.text_transform_);
        diff.push_back(std::move(d));
    }
    if (!(data_.transform_box_ == o.data_.transform_box_)) {
        DebugDiff d;
        d.field = DebugField::transform_box_;
        d.actual = DebugStringForField(data_.transform_box_);
        d.correct = DebugStringForField(o.data_.transform_box_);
        diff.push_back(std::move(d));
    }
    if (!(data_.unicode_bidi_ == o.data_.unicode_bidi_)) {
        DebugDiff d;
        d.field = DebugField::unicode_bidi_;
        d.actual = DebugStringForField(data_.unicode_bidi_);
        d.correct = DebugStringForField(o.data_.unicode_bidi_);
        diff.push_back(std::move(d));
    }
    if (!(data_.writing_mode_ == o.data_.writing_mode_)) {
        DebugDiff d;
        d.field = DebugField::writing_mode_;
        d.actual = DebugStringForField(data_.writing_mode_);
        d.correct = DebugStringForField(o.data_.writing_mode_);
        diff.push_back(std::move(d));
    }
    if (!(data_.inside_link_ == o.data_.inside_link_)) {
        DebugDiff d;
        d.field = DebugField::inside_link_;
        d.actual = DebugStringForField(data_.inside_link_);
        d.correct = DebugStringForField(o.data_.inside_link_);
        diff.push_back(std::move(d));
    }
    if (!(IsStackingContextWithoutContainment() == o.IsStackingContextWithoutContainment())) {
        DebugDiff d;
        d.field = DebugField::is_stacking_context_without_containment_;
        d.actual = DebugStringForField(IsStackingContextWithoutContainment());
        d.correct = DebugStringForField(o.IsStackingContextWithoutContainment());
        diff.push_back(std::move(d));
    }
    if (!(data_.overflow_anchor_ == o.data_.overflow_anchor_)) {
        DebugDiff d;
        d.field = DebugField::overflow_anchor_;
        d.actual = DebugStringForField(data_.overflow_anchor_);
        d.correct = DebugStringForField(o.data_.overflow_anchor_);
        diff.push_back(std::move(d));
    }
    if (!(data_.text_wrap_style_ == o.data_.text_wrap_style_)) {
        DebugDiff d;
        d.field = DebugField::text_wrap_style_;
        d.actual = DebugStringForField(data_.text_wrap_style_);
        d.correct = DebugStringForField(o.data_.text_wrap_style_);
        diff.push_back(std::move(d));
    }
    if (!(data_.viewport_unit_flags_ == o.data_.viewport_unit_flags_)) {
        DebugDiff d;
        d.field = DebugField::viewport_unit_flags_;
        d.actual = DebugStringForField(data_.viewport_unit_flags_);
        d.correct = DebugStringForField(o.data_.viewport_unit_flags_);
        diff.push_back(std::move(d));
    }
    if (!(data_.visibility_ == o.data_.visibility_)) {
        DebugDiff d;
        d.field = DebugField::visibility_;
        d.actual = DebugStringForField(data_.visibility_);
        d.correct = DebugStringForField(o.data_.visibility_);
        diff.push_back(std::move(d));
    }
    if (!(data_.white_space_collapse_ == o.data_.white_space_collapse_)) {
        DebugDiff d;
        d.field = DebugField::white_space_collapse_;
        d.actual = DebugStringForField(data_.white_space_collapse_);
        d.correct = DebugStringForField(o.data_.white_space_collapse_);
        diff.push_back(std::move(d));
    }
    if (!(data_.border_collapse_ == o.data_.border_collapse_)) {
        DebugDiff d;
        d.field = DebugField::border_collapse_;
        d.actual = DebugStringForField(data_.border_collapse_);
        d.correct = DebugStringForField(o.data_.border_collapse_);
        diff.push_back(std::move(d));
    }
    if (!(data_.border_collapse_is_inherited_ == o.data_.border_collapse_is_inherited_)) {
        DebugDiff d;
        d.field = DebugField::border_collapse_is_inherited_;
        d.actual = DebugStringForField(data_.border_collapse_is_inherited_);
        d.correct = DebugStringForField(o.data_.border_collapse_is_inherited_);
        diff.push_back(std::move(d));
    }
    if (!(data_.box_direction_ == o.data_.box_direction_)) {
        DebugDiff d;
        d.field = DebugField::box_direction_;
        d.actual = DebugStringForField(data_.box_direction_);
        d.correct = DebugStringForField(o.data_.box_direction_);
        diff.push_back(std::move(d));
    }
    if (!(data_.box_sizing_ == o.data_.box_sizing_)) {
        DebugDiff d;
        d.field = DebugField::box_sizing_;
        d.actual = DebugStringForField(data_.box_sizing_);
        d.correct = DebugStringForField(o.data_.box_sizing_);
        diff.push_back(std::move(d));
    }
    if (!(data_.caption_side_ == o.data_.caption_side_)) {
        DebugDiff d;
        d.field = DebugField::caption_side_;
        d.actual = DebugStringForField(data_.caption_side_);
        d.correct = DebugStringForField(o.data_.caption_side_);
        diff.push_back(std::move(d));
    }
    if (!(data_.caption_side_is_inherited_ == o.data_.caption_side_is_inherited_)) {
        DebugDiff d;
        d.field = DebugField::caption_side_is_inherited_;
        d.actual = DebugStringForField(data_.caption_side_is_inherited_);
        d.correct = DebugStringForField(o.data_.caption_side_is_inherited_);
        diff.push_back(std::move(d));
    }
    if (!(data_.caret_animation_ == o.data_.caret_animation_)) {
        DebugDiff d;
        d.field = DebugField::caret_animation_;
        d.actual = DebugStringForField(data_.caret_animation_);
        d.correct = DebugStringForField(o.data_.caret_animation_);
        diff.push_back(std::move(d));
    }
    if (!(data_.color_is_inherited_ == o.data_.color_is_inherited_)) {
        DebugDiff d;
        d.field = DebugField::color_is_inherited_;
        d.actual = DebugStringForField(data_.color_is_inherited_);
        d.correct = DebugStringForField(o.data_.color_is_inherited_);
        diff.push_back(std::move(d));
    }
    if (!(data_.direction_ == o.data_.direction_)) {
        DebugDiff d;
        d.field = DebugField::direction_;
        d.actual = DebugStringForField(data_.direction_);
        d.correct = DebugStringForField(o.data_.direction_);
        diff.push_back(std::move(d));
    }
    if (!(data_.empty_cells_ == o.data_.empty_cells_)) {
        DebugDiff d;
        d.field = DebugField::empty_cells_;
        d.actual = DebugStringForField(data_.empty_cells_);
        d.correct = DebugStringForField(o.data_.empty_cells_);
        diff.push_back(std::move(d));
    }
    if (!(data_.empty_cells_is_inherited_ == o.data_.empty_cells_is_inherited_)) {
        DebugDiff d;
        d.field = DebugField::empty_cells_is_inherited_;
        d.actual = DebugStringForField(data_.empty_cells_is_inherited_);
        d.correct = DebugStringForField(o.data_.empty_cells_is_inherited_);
        diff.push_back(std::move(d));
    }
    if (!(data_.has_author_background_ == o.data_.has_author_background_)) {
        DebugDiff d;
        d.field = DebugField::has_author_background_;
        d.actual = DebugStringForField(data_.has_author_background_);
        d.correct = DebugStringForField(o.data_.has_author_background_);
        diff.push_back(std::move(d));
    }
    if (!(data_.has_author_border_ == o.data_.has_author_border_)) {
        DebugDiff d;
        d.field = DebugField::has_author_border_;
        d.actual = DebugStringForField(data_.has_author_border_);
        d.correct = DebugStringForField(o.data_.has_author_border_);
        diff.push_back(std::move(d));
    }
    if (!(data_.has_author_border_radius_ == o.data_.has_author_border_radius_)) {
        DebugDiff d;
        d.field = DebugField::has_author_border_radius_;
        d.actual = DebugStringForField(data_.has_author_border_radius_);
        d.correct = DebugStringForField(o.data_.has_author_border_radius_);
        diff.push_back(std::move(d));
    }
    if (!(data_.has_author_highlight_colors_ == o.data_.has_author_highlight_colors_)) {
        DebugDiff d;
        d.field = DebugField::has_author_highlight_colors_;
        d.actual = DebugStringForField(data_.has_author_highlight_colors_);
        d.correct = DebugStringForField(o.data_.has_author_highlight_colors_);
        diff.push_back(std::move(d));
    }
    if (!(data_.has_explicit_inheritance_ == o.data_.has_explicit_inheritance_)) {
        DebugDiff d;
        d.field = DebugField::has_explicit_inheritance_;
        d.actual = DebugStringForField(data_.has_explicit_inheritance_);
        d.correct = DebugStringForField(o.data_.has_explicit_inheritance_);
        diff.push_back(std::move(d));
    }
    if (!(data_.is_html_inert_ == o.data_.is_html_inert_)) {
        DebugDiff d;
        d.field = DebugField::is_html_inert_;
        d.actual = DebugStringForField(data_.is_html_inert_);
        d.correct = DebugStringForField(o.data_.is_html_inert_);
        diff.push_back(std::move(d));
    }
    if (!(data_.is_html_inert_is_inherited_ == o.data_.is_html_inert_is_inherited_)) {
        DebugDiff d;
        d.field = DebugField::is_html_inert_is_inherited_;
        d.actual = DebugStringForField(data_.is_html_inert_is_inherited_);
        d.correct = DebugStringForField(o.data_.is_html_inert_is_inherited_);
        diff.push_back(std::move(d));
    }
    if (!(data_.is_original_display_inline_type_ == o.data_.is_original_display_inline_type_)) {
        DebugDiff d;
        d.field = DebugField::is_original_display_inline_type_;
        d.actual = DebugStringForField(data_.is_original_display_inline_type_);
        d.correct = DebugStringForField(o.data_.is_original_display_inline_type_);
        diff.push_back(std::move(d));
    }
    if (!(data_.is_page_margin_box_ == o.data_.is_page_margin_box_)) {
        DebugDiff d;
        d.field = DebugField::is_page_margin_box_;
        d.actual = DebugStringForField(data_.is_page_margin_box_);
        d.correct = DebugStringForField(o.data_.is_page_margin_box_);
        diff.push_back(std::move(d));
    }
    if (!(data_.is_specified_display_webkit_box_ == o.data_.is_specified_display_webkit_box_)) {
        DebugDiff d;
        d.field = DebugField::is_specified_display_webkit_box_;
        d.actual = DebugStringForField(data_.is_specified_display_webkit_box_);
        d.correct = DebugStringForField(o.data_.is_specified_display_webkit_box_);
        diff.push_back(std::move(d));
    }
    if (!(data_.list_style_position_ == o.data_.list_style_position_)) {
        DebugDiff d;
        d.field = DebugField::list_style_position_;
        d.actual = DebugStringForField(data_.list_style_position_);
        d.correct = DebugStringForField(o.data_.list_style_position_);
        diff.push_back(std::move(d));
    }
    if (!(data_.list_style_position_is_inherited_ == o.data_.list_style_position_is_inherited_)) {
        DebugDiff d;
        d.field = DebugField::list_style_position_is_inherited_;
        d.actual = DebugStringForField(data_.list_style_position_is_inherited_);
        d.correct = DebugStringForField(o.data_.list_style_position_is_inherited_);
        diff.push_back(std::move(d));
    }
    if (!(data_.origin_trial_test_property_ == o.data_.origin_trial_test_property_)) {
        DebugDiff d;
        d.field = DebugField::origin_trial_test_property_;
        d.actual = DebugStringForField(data_.origin_trial_test_property_);
        d.correct = DebugStringForField(o.data_.origin_trial_test_property_);
        diff.push_back(std::move(d));
    }
    if (!(data_.pointer_events_is_inherited_ == o.data_.pointer_events_is_inherited_)) {
        DebugDiff d;
        d.field = DebugField::pointer_events_is_inherited_;
        d.actual = DebugStringForField(data_.pointer_events_is_inherited_);
        d.correct = DebugStringForField(o.data_.pointer_events_is_inherited_);
        diff.push_back(std::move(d));
    }
    if (!(data_.prefers_default_scrollbar_styles_ == o.data_.prefers_default_scrollbar_styles_)) {
        DebugDiff d;
        d.field = DebugField::prefers_default_scrollbar_styles_;
        d.actual = DebugStringForField(data_.prefers_default_scrollbar_styles_);
        d.correct = DebugStringForField(o.data_.prefers_default_scrollbar_styles_);
        diff.push_back(std::move(d));
    }
    if (!(data_.print_color_adjust_ == o.data_.print_color_adjust_)) {
        DebugDiff d;
        d.field = DebugField::print_color_adjust_;
        d.actual = DebugStringForField(data_.print_color_adjust_);
        d.correct = DebugStringForField(o.data_.print_color_adjust_);
        diff.push_back(std::move(d));
    }
    if (!(data_.rtl_ordering_ == o.data_.rtl_ordering_)) {
        DebugDiff d;
        d.field = DebugField::rtl_ordering_;
        d.actual = DebugStringForField(data_.rtl_ordering_);
        d.correct = DebugStringForField(o.data_.rtl_ordering_);
        diff.push_back(std::move(d));
    }
    if (!(data_.rtl_ordering_is_inherited_ == o.data_.rtl_ordering_is_inherited_)) {
        DebugDiff d;
        d.field = DebugField::rtl_ordering_is_inherited_;
        d.actual = DebugStringForField(data_.rtl_ordering_is_inherited_);
        d.correct = DebugStringForField(o.data_.rtl_ordering_is_inherited_);
        diff.push_back(std::move(d));
    }
    if (!(data_.scroll_snap_stop_ == o.data_.scroll_snap_stop_)) {
        DebugDiff d;
        d.field = DebugField::scroll_snap_stop_;
        d.actual = DebugStringForField(data_.scroll_snap_stop_);
        d.correct = DebugStringForField(o.data_.scroll_snap_stop_);
        diff.push_back(std::move(d));
    }
    if (!(data_.should_ignore_overflow_property_for_inline_block_baseline_ == o.data_.should_ignore_overflow_property_for_inline_block_baseline_)) {
        DebugDiff d;
        d.field = DebugField::should_ignore_overflow_property_for_inline_block_baseline_;
        d.actual = DebugStringForField(data_.should_ignore_overflow_property_for_inline_block_baseline_);
        d.correct = DebugStringForField(o.data_.should_ignore_overflow_property_for_inline_block_baseline_);
        diff.push_back(std::move(d));
    }
    if (!(data_.skips_contents_ == o.data_.skips_contents_)) {
        DebugDiff d;
        d.field = DebugField::skips_contents_;
        d.actual = DebugStringForField(data_.skips_contents_);
        d.correct = DebugStringForField(o.data_.skips_contents_);
        diff.push_back(std::move(d));
    }
    if (!(data_.table_layout_ == o.data_.table_layout_)) {
        DebugDiff d;
        d.field = DebugField::table_layout_;
        d.actual = DebugStringForField(data_.table_layout_);
        d.correct = DebugStringForField(o.data_.table_layout_);
        diff.push_back(std::move(d));
    }
    if (!(data_.text_transform_is_inherited_ == o.data_.text_transform_is_inherited_)) {
        DebugDiff d;
        d.field = DebugField::text_transform_is_inherited_;
        d.actual = DebugStringForField(data_.text_transform_is_inherited_);
        d.correct = DebugStringForField(o.data_.text_transform_is_inherited_);
        diff.push_back(std::move(d));
    }
    if (!(data_.text_wrap_mode_ == o.data_.text_wrap_mode_)) {
        DebugDiff d;
        d.field = DebugField::text_wrap_mode_;
        d.actual = DebugStringForField(data_.text_wrap_mode_);
        d.correct = DebugStringForField(o.data_.text_wrap_mode_);
        diff.push_back(std::move(d));
    }
    if (!(data_.visibility_is_inherited_ == o.data_.visibility_is_inherited_)) {
        DebugDiff d;
        d.field = DebugField::visibility_is_inherited_;
        d.actual = DebugStringForField(data_.visibility_is_inherited_);
        d.correct = DebugStringForField(o.data_.visibility_is_inherited_);
        diff.push_back(std::move(d));
    }

    return diff;
}

#endif // DCHECK_IS_ON()

ComputedStyleBase::StyleRareInheritedUsageLessThan100PercentData::StyleRareInheritedUsageLessThan100PercentData()
    : text_underline_offset_(Length())
    , tap_highlight_color_(StyleColor(LayoutTheme::TapHighlightColor()))
    , accent_color_(StyleAutoColor::AutoColor())
    , math_depth_(0)
    , image_orientation_(static_cast<unsigned>(kRespectImageOrientation))
    , math_shift_(static_cast<unsigned>(EMathShift::kNormal))
    , math_style_(static_cast<unsigned>(EMathStyle::kNormal))
{
}

ComputedStyleBase::StyleRareInheritedUsageLessThan100PercentData::StyleRareInheritedUsageLessThan100PercentData(
    const StyleRareInheritedUsageLessThan100PercentData& other)
    : text_underline_offset_(other.text_underline_offset_)
    , tap_highlight_color_(other.tap_highlight_color_)
    , accent_color_(other.accent_color_)
    , math_depth_(other.math_depth_)
    , image_orientation_(other.image_orientation_)
    , math_shift_(other.math_shift_)
    , math_style_(other.math_style_)
{
}

ComputedStyleBase::StyleInheritedForcedColorsData::StyleInheritedForcedColorsData()
    : internal_forced_color_(StyleColor(CSSValueID::kCanvastext))
    , internal_forced_visited_color_(StyleColor(CSSValueID::kCanvastext))
{
}

ComputedStyleBase::StyleInheritedForcedColorsData::StyleInheritedForcedColorsData(const StyleInheritedForcedColorsData& other)
    : internal_forced_color_(other.internal_forced_color_)
    , internal_forced_visited_color_(other.internal_forced_visited_color_)
{
}

ComputedStyleBase::StyleInheritedVisitedData::StyleInheritedVisitedData()
    : internal_visited_text_emphasis_color_(StyleColor::CurrentColor())
    , internal_visited_text_fill_color_(StyleColor::CurrentColor())
    , internal_visited_text_stroke_color_(StyleColor::CurrentColor())
    , internal_visited_caret_color_(StyleAutoColor::AutoColor())
{
}

ComputedStyleBase::StyleInheritedVisitedData::StyleInheritedVisitedData(const StyleInheritedVisitedData& other)
    : internal_visited_text_emphasis_color_(other.internal_visited_text_emphasis_color_)
    , internal_visited_text_fill_color_(other.internal_visited_text_fill_color_)
    , internal_visited_text_stroke_color_(other.internal_visited_text_stroke_color_)
    , internal_visited_caret_color_(other.internal_visited_caret_color_)
{
}

ComputedStyleBase::StyleHighlightDataData::StyleHighlightDataData()
    : highlight_data_(StyleHighlightData())
{
}

ComputedStyleBase::StyleHighlightDataData::StyleHighlightDataData(const StyleHighlightDataData& other)
    : highlight_data_(other.highlight_data_)
{
}

ComputedStyleBase::StyleRareInheritedUsageLessThan64PercentSubData::StyleRareInheritedUsageLessThan64PercentSubData()
    : inherited_forced_colors_data_(StyleInheritedForcedColorsData::Create())
    , inherited_visited_data_(StyleInheritedVisitedData::Create())
    , highlight_data_data_(StyleHighlightDataData::Create())
    , dynamic_range_limit_(DynamicRangeLimit(cc::PaintFlags::DynamicRangeLimit::kHigh))
    , text_emphasis_custom_mark_(AtomicString())
    , ua_shadow_host_data_(nullptr)
    , scrollbar_color_(nullptr)
    , cursor_data_(nullptr)
    , initial_data_(nullptr)
    , effective_zoom_(1.0f)
    , hyphenate_limit_chars_(StyleHyphenateLimitChars())
    , effective_touch_action_(static_cast<unsigned>(TouchAction::kAuto))
    , text_emphasis_mark_(static_cast<unsigned>(TextEmphasisMark::kNone))
    , ruby_align_(static_cast<unsigned>(ERubyAlign::kSpaceAround))
    , has_line_if_empty_(static_cast<unsigned>(false))
    , in_base_select_appearance_(static_cast<unsigned>(false))
    , interactivity_(static_cast<unsigned>(EInteractivity::kAuto))
    , interpolate_size_(static_cast<unsigned>(EInterpolateSize::kNumericOnly))
    , subtree_is_sticky_(static_cast<unsigned>(false))
    , subtree_will_change_contents_(static_cast<unsigned>(false))
    , text_autospace_(static_cast<unsigned>(ETextAutospace::kNormal))
    , text_emphasis_fill_(static_cast<unsigned>(TextEmphasisFill::kFilled))
{
}

ComputedStyleBase::StyleRareInheritedUsageLessThan64PercentSubData::StyleRareInheritedUsageLessThan64PercentSubData(
    const StyleRareInheritedUsageLessThan64PercentSubData& other)
    : inherited_forced_colors_data_(other.inherited_forced_colors_data_)
    , inherited_visited_data_(other.inherited_visited_data_)
    , highlight_data_data_(other.highlight_data_data_)
    , dynamic_range_limit_(other.dynamic_range_limit_)
    , text_emphasis_custom_mark_(other.text_emphasis_custom_mark_)
    , ua_shadow_host_data_(MemberCopy(other.ua_shadow_host_data_))
    , scrollbar_color_(MemberCopy(other.scrollbar_color_))
    , cursor_data_(MemberCopy(other.cursor_data_))
    , initial_data_(MemberCopy(other.initial_data_))
    , effective_zoom_(other.effective_zoom_)
    , hyphenate_limit_chars_(other.hyphenate_limit_chars_)
    , effective_touch_action_(other.effective_touch_action_)
    , text_emphasis_mark_(other.text_emphasis_mark_)
    , ruby_align_(other.ruby_align_)
    , has_line_if_empty_(other.has_line_if_empty_)
    , in_base_select_appearance_(other.in_base_select_appearance_)
    , interactivity_(other.interactivity_)
    , interpolate_size_(other.interpolate_size_)
    , subtree_is_sticky_(other.subtree_is_sticky_)
    , subtree_will_change_contents_(other.subtree_will_change_contents_)
    , text_autospace_(other.text_autospace_)
    , text_emphasis_fill_(other.text_emphasis_fill_)
{
}

ComputedStyleBase::StyleRareInheritedUsageLessThan64PercentData::StyleRareInheritedUsageLessThan64PercentData()
    : rare_inherited_usage_less_than_100_percent_data_(StyleRareInheritedUsageLessThan100PercentData::Create())
    , rare_inherited_usage_less_than_64_percent_sub_data_(StyleRareInheritedUsageLessThan64PercentSubData::Create())
    , color_scheme_(Vector<AtomicString, 0>())
    , hyphenation_string_(AtomicString())
    , quotes_(nullptr)
    , list_style_image_(nullptr)
    , list_style_type_(ListStyleTypeData::CreateCounterStyle(keywords::kDisc, nullptr))
    , text_shadow_(nullptr)
    , text_indent_(Length::Fixed())
    , text_size_adjust_(TextSizeAdjust::AdjustAuto())
    , tab_size_(TabSize(8))
    , text_stroke_width_(0)
    , text_emphasis_color_(StyleColor::CurrentColor())
    , text_fill_color_(StyleColor::CurrentColor())
    , text_stroke_color_(StyleColor::CurrentColor())
    , caret_color_(StyleAutoColor::AutoColor())
    , orphans_(2)
    , widows_(2)
    , text_box_edge_(static_cast<unsigned>(TextBoxEdge()))
    , text_underline_position_(static_cast<unsigned>(TextUnderlinePosition::kAuto))
    , image_rendering_(static_cast<unsigned>(EImageRendering::kAuto))
    , line_break_(static_cast<unsigned>(LineBreak::kAuto))
    , speak_(static_cast<unsigned>(ESpeak::kNormal))
    , text_align_last_(static_cast<unsigned>(ETextAlignLast::kAuto))
    , user_select_(static_cast<unsigned>(EUserSelect::kAuto))
    , word_break_(static_cast<unsigned>(EWordBreak::kNormal))
    , forced_color_adjust_(static_cast<unsigned>(EForcedColorAdjust::kAuto))
    , hyphens_(static_cast<unsigned>(Hyphens::kManual))
    , overflow_wrap_(static_cast<unsigned>(EOverflowWrap::kNormal))
    , text_emphasis_position_(static_cast<unsigned>(TextEmphasisPosition::kOverRight))
    , text_orientation_(static_cast<unsigned>(ETextOrientation::kMixed))
    , text_security_(static_cast<unsigned>(ETextSecurity::kNone))
    , user_modify_(static_cast<unsigned>(EUserModify::kReadOnly))
    , ruby_position_(static_cast<unsigned>(RubyPosition::kOver))
    , text_combine_(static_cast<unsigned>(ETextCombine::kNone))
    , text_decoration_skip_ink_(static_cast<unsigned>(ETextDecorationSkipInk::kAuto))
{
}

ComputedStyleBase::StyleRareInheritedUsageLessThan64PercentData::StyleRareInheritedUsageLessThan64PercentData(
    const StyleRareInheritedUsageLessThan64PercentData& other)
    : rare_inherited_usage_less_than_100_percent_data_(other.rare_inherited_usage_less_than_100_percent_data_)
    , rare_inherited_usage_less_than_64_percent_sub_data_(other.rare_inherited_usage_less_than_64_percent_sub_data_)
    , color_scheme_(other.color_scheme_)
    , hyphenation_string_(other.hyphenation_string_)
    , quotes_(MemberCopy(other.quotes_))
    , list_style_image_(MemberCopy(other.list_style_image_))
    , list_style_type_(MemberCopy(other.list_style_type_))
    , text_shadow_(MemberCopy(other.text_shadow_))
    , text_indent_(other.text_indent_)
    , text_size_adjust_(other.text_size_adjust_)
    , tab_size_(other.tab_size_)
    , text_stroke_width_(other.text_stroke_width_)
    , text_emphasis_color_(other.text_emphasis_color_)
    , text_fill_color_(other.text_fill_color_)
    , text_stroke_color_(other.text_stroke_color_)
    , caret_color_(other.caret_color_)
    , orphans_(other.orphans_)
    , widows_(other.widows_)
    , text_box_edge_(other.text_box_edge_)
    , text_underline_position_(other.text_underline_position_)
    , image_rendering_(other.image_rendering_)
    , line_break_(other.line_break_)
    , speak_(other.speak_)
    , text_align_last_(other.text_align_last_)
    , user_select_(other.user_select_)
    , word_break_(other.word_break_)
    , forced_color_adjust_(other.forced_color_adjust_)
    , hyphens_(other.hyphens_)
    , overflow_wrap_(other.overflow_wrap_)
    , text_emphasis_position_(other.text_emphasis_position_)
    , text_orientation_(other.text_orientation_)
    , text_security_(other.text_security_)
    , user_modify_(other.user_modify_)
    , ruby_position_(other.ruby_position_)
    , text_combine_(other.text_combine_)
    , text_decoration_skip_ink_(other.text_decoration_skip_ink_)
{
}

ComputedStyleBase::StyleGridData::StyleGridData()
    : grid_template_columns_(ComputedGridTrackList())
    , grid_template_rows_(ComputedGridTrackList())
{
}

ComputedStyleBase::StyleGridData::StyleGridData(const StyleGridData& other)
    : grid_template_columns_(other.grid_template_columns_)
    , grid_template_rows_(other.grid_template_rows_)
{
}

ComputedStyleBase::StyleForcedColorsData::StyleForcedColorsData()
    : internal_forced_background_color_(StyleColor(CSSValueID::kCanvas))
    , internal_forced_border_color_(StyleColor::CurrentColor())
    , internal_forced_outline_color_(StyleColor::CurrentColor())
{
}

ComputedStyleBase::StyleForcedColorsData::StyleForcedColorsData(const StyleForcedColorsData& other)
    : internal_forced_background_color_(other.internal_forced_background_color_)
    , internal_forced_border_color_(other.internal_forced_border_color_)
    , internal_forced_outline_color_(other.internal_forced_outline_color_)
{
}

ComputedStyleBase::StyleVisitedData::StyleVisitedData()
    : internal_visited_column_rule_color_(GapDataList<StyleColor>::DefaultGapColorDataList())
    , internal_visited_background_color_(StyleColor(Color::kTransparent))
    , internal_visited_border_bottom_color_(StyleColor::CurrentColor())
    , internal_visited_border_left_color_(StyleColor::CurrentColor())
    , internal_visited_border_right_color_(StyleColor::CurrentColor())
    , internal_visited_border_top_color_(StyleColor::CurrentColor())
    , internal_visited_outline_color_(StyleColor::CurrentColor())
    , internal_visited_text_decoration_color_(StyleColor::CurrentColor())
{
}

ComputedStyleBase::StyleVisitedData::StyleVisitedData(const StyleVisitedData& other)
    : internal_visited_column_rule_color_(other.internal_visited_column_rule_color_)
    , internal_visited_background_color_(other.internal_visited_background_color_)
    , internal_visited_border_bottom_color_(other.internal_visited_border_bottom_color_)
    , internal_visited_border_left_color_(other.internal_visited_border_left_color_)
    , internal_visited_border_right_color_(other.internal_visited_border_right_color_)
    , internal_visited_border_top_color_(other.internal_visited_border_top_color_)
    , internal_visited_outline_color_(other.internal_visited_outline_color_)
    , internal_visited_text_decoration_color_(other.internal_visited_text_decoration_color_)
{
}

ComputedStyleBase::StyleMasonryData::StyleMasonryData()
    : masonry_template_tracks_(ComputedGridTrackList::DefaultMasonryTrackList())
{
}

ComputedStyleBase::StyleMasonryData::StyleMasonryData(const StyleMasonryData& other)
    : masonry_template_tracks_(other.masonry_template_tracks_)
{
}

ComputedStyleBase::StyleStartData::StyleStartData()
    : scroll_start_x_(blink::ScrollStartData())
    , scroll_start_y_(blink::ScrollStartData())
{
}

ComputedStyleBase::StyleStartData::StyleStartData(const StyleStartData& other)
    : scroll_start_x_(other.scroll_start_x_)
    , scroll_start_y_(other.scroll_start_y_)
{
}

ComputedStyleBase::StyleTimelineData::StyleTimelineData()
    : scroll_timeline_axis_(Vector<TimelineAxis>())
    , view_timeline_axis_(Vector<TimelineAxis>())
    , view_timeline_inset_(Vector<TimelineInset>())
    , scroll_timeline_name_(nullptr)
    , timeline_scope_(nullptr)
    , view_timeline_name_(nullptr)
{
}

ComputedStyleBase::StyleTimelineData::StyleTimelineData(const StyleTimelineData& other)
    : scroll_timeline_axis_(other.scroll_timeline_axis_)
    , view_timeline_axis_(other.view_timeline_axis_)
    , view_timeline_inset_(other.view_timeline_inset_)
    , scroll_timeline_name_(MemberCopy(other.scroll_timeline_name_))
    , timeline_scope_(MemberCopy(other.timeline_scope_))
    , view_timeline_name_(MemberCopy(other.view_timeline_name_))
{
}

ComputedStyleBase::StyleWillChangeData::StyleWillChangeData()
    : will_change_properties_(Vector<CSSPropertyID>())
    , will_change_contents_(static_cast<unsigned>(false))
    , will_change_scroll_position_(static_cast<unsigned>(false))
{
}

ComputedStyleBase::StyleWillChangeData::StyleWillChangeData(const StyleWillChangeData& other)
    : will_change_properties_(other.will_change_properties_)
    , will_change_contents_(other.will_change_contents_)
    , will_change_scroll_position_(other.will_change_scroll_position_)
{
}

ComputedStyleBase::StyleMathData::StyleMathData()
    : math_baseline_(Length())
    , math_fraction_bar_thickness_(Length())
    , math_l_space_(Length())
    , math_r_space_(Length())
    , math_padded_v_offset_(Length())
    , math_padded_depth_(Length())
    , math_min_size_(Length())
    , math_max_size_(Length())
{
}

ComputedStyleBase::StyleMathData::StyleMathData(const StyleMathData& other)
    : math_baseline_(other.math_baseline_)
    , math_fraction_bar_thickness_(other.math_fraction_bar_thickness_)
    , math_l_space_(other.math_l_space_)
    , math_r_space_(other.math_r_space_)
    , math_padded_v_offset_(other.math_padded_v_offset_)
    , math_padded_depth_(other.math_padded_depth_)
    , math_min_size_(other.math_min_size_)
    , math_max_size_(other.math_max_size_)
{
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan14PercentSubData::StyleRareNonInheritedUsageLessThan14PercentSubData()
    : grid_data_(StyleGridData::Create())
    , forced_colors_data_(StyleForcedColorsData::Create())
    , visited_data_(StyleVisitedData::Create())
    , masonry_data_(StyleMasonryData::Create())
    , start_data_(StyleStartData::Create())
    , timeline_data_(StyleTimelineData::Create())
    , will_change_data_(StyleWillChangeData::Create())
    , math_data_(StyleMathData::Create())
    , view_transition_group_(StyleViewTransitionGroup::Normal())
    , masonry_track_end_(GridPosition())
    , masonry_track_start_(GridPosition())
    , display_layout_custom_name_(g_null_atom)
    , display_layout_custom_parent_name_(g_null_atom)
    , pseudo_argument_(g_null_atom)
    , object_view_box_(nullptr)
    , custom_highlight_names_(nullptr)
    , counter_directives_(nullptr)
    , animations_(nullptr)
    , transitions_(nullptr)
    , callback_selectors_(Vector<String>())
    , mask_(FillLayer(EFillLayerType::kMask, true))
    , mask_box_image_(NinePieceImage::MaskDefaults())
    , anchor_scope_(StyleAnchorScope())
    , overflow_clip_margin_(std::nullopt)
    , position_area_offsets_(std::nullopt)
    , anchor_center_offset_(std::nullopt)
    , position_anchor_(nullptr)
    , anchor_name_(nullptr)
    , container_name_(nullptr)
    , position_try_fallbacks_(nullptr)
    , view_transition_class_(nullptr)
    , view_transition_name_(nullptr)
    , document_rules_selectors_(nullptr)
    , paint_images_(nullptr)
    , non_inherited_variables_(nullptr)
    , masonry_slack_(std::nullopt)
    , initial_letter_(StyleInitialLetter())
    , page_size_(gfx::SizeF())
    , popover_hide_delay_(HUGE_VALF)
    , popover_show_delay_(0.5)
    , scroll_margin_bottom_(0.0f)
    , scroll_margin_left_(0.0f)
    , scroll_margin_right_(0.0f)
    , scroll_margin_top_(0.0f)
    , standard_line_clamp_(0)
    , position_area_(PositionArea())
    , effective_appearance_(static_cast<unsigned>(kNoControlPart))
    , container_type_(static_cast<unsigned>(kContainerTypeNormal))
    , position_try_order_(static_cast<unsigned>(EPositionTryOrder::kNormal))
    , position_visibility_(static_cast<unsigned>(PositionVisibility::kAlways))
    , reading_flow_(static_cast<unsigned>(EReadingFlow::kNormal))
    , inline_block_baseline_edge_(static_cast<unsigned>(EInlineBlockBaselineEdge::kMarginBox))
    , overscroll_behavior_x_(static_cast<unsigned>(EOverscrollBehavior::kAuto))
    , overscroll_behavior_y_(static_cast<unsigned>(EOverscrollBehavior::kAuto))
    , page_size_type_(static_cast<unsigned>(PageSizeType::kAuto))
    , scroll_marker_group_(static_cast<unsigned>(EScrollMarkerGroup::kNone))
    , scrollbar_width_(static_cast<unsigned>(EScrollbarWidth::kAuto))
    , view_transition_capture_mode_(static_cast<unsigned>(StyleViewTransitionCaptureMode::kLayered))
    , affected_by_css_function_(static_cast<unsigned>(false))
    , align_content_block_center_(static_cast<unsigned>(false))
    , can_affect_animations_(static_cast<unsigned>(false))
    , depends_on_scroll_state_container_queries_(static_cast<unsigned>(false))
    , depends_on_size_container_queries_(static_cast<unsigned>(false))
    , depends_on_style_container_queries_(static_cast<unsigned>(false))
    , effective_z_index_zero_(static_cast<unsigned>(false))
    , element_is_view_transition_participant_(static_cast<unsigned>(false))
    , first_line_depends_on_size_container_queries_(static_cast<unsigned>(false))
    , forces_stacking_context_(static_cast<unsigned>(false))
    , has_auto_column_count_(static_cast<unsigned>(true))
    , has_auto_column_width_(static_cast<unsigned>(true))
    , has_current_backdrop_filter_animation_(static_cast<unsigned>(false))
    , has_current_background_color_animation_(static_cast<unsigned>(false))
    , has_current_filter_animation_(static_cast<unsigned>(false))
    , has_current_opacity_animation_(static_cast<unsigned>(false))
    , has_current_rotate_animation_(static_cast<unsigned>(false))
    , has_current_scale_animation_(static_cast<unsigned>(false))
    , has_current_transform_animation_(static_cast<unsigned>(false))
    , has_current_translate_animation_(static_cast<unsigned>(false))
    , has_explicit_overflow_x_visible_(static_cast<unsigned>(false))
    , has_explicit_overflow_y_visible_(static_cast<unsigned>(false))
    , has_line_height_relative_units_(static_cast<unsigned>(false))
    , has_non_ua_highlight_pseudo_styles_(static_cast<unsigned>(false))
    , has_non_universal_highlight_pseudo_styles_(static_cast<unsigned>(false))
    , highlights_depend_on_size_container_queries_(static_cast<unsigned>(false))
    , inline_style_lost_cascade_(static_cast<unsigned>(false))
    , is_running_backdrop_filter_animation_on_compositor_(static_cast<unsigned>(false))
    , is_running_filter_animation_on_compositor_(static_cast<unsigned>(false))
    , is_running_opacity_animation_on_compositor_(static_cast<unsigned>(false))
    , is_running_rotate_animation_on_compositor_(static_cast<unsigned>(false))
    , is_running_scale_animation_on_compositor_(static_cast<unsigned>(false))
    , is_running_transform_animation_on_compositor_(static_cast<unsigned>(false))
    , is_running_translate_animation_on_compositor_(static_cast<unsigned>(false))
    , is_secondary_body_element_(static_cast<unsigned>(false))
    , is_starting_style_(static_cast<unsigned>(false))
    , outline_style_is_auto_(static_cast<unsigned>(false))
    , overlay_(static_cast<unsigned>(EOverlay::kNone))
    , requires_accelerated_compositing_for_external_reasons_(static_cast<unsigned>(false))
    , scroll_start_target_(static_cast<unsigned>(EScrollStartTarget::kNone))
{
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan14PercentSubData::StyleRareNonInheritedUsageLessThan14PercentSubData(
    const StyleRareNonInheritedUsageLessThan14PercentSubData& other)
    : grid_data_(other.grid_data_)
    , forced_colors_data_(other.forced_colors_data_)
    , visited_data_(other.visited_data_)
    , masonry_data_(other.masonry_data_)
    , start_data_(other.start_data_)
    , timeline_data_(other.timeline_data_)
    , will_change_data_(other.will_change_data_)
    , math_data_(other.math_data_)
    , view_transition_group_(other.view_transition_group_)
    , masonry_track_end_(other.masonry_track_end_)
    , masonry_track_start_(other.masonry_track_start_)
    , display_layout_custom_name_(other.display_layout_custom_name_)
    , display_layout_custom_parent_name_(other.display_layout_custom_parent_name_)
    , pseudo_argument_(other.pseudo_argument_)
    , object_view_box_(MemberCopy(other.object_view_box_))
    , custom_highlight_names_(MemberCopy(other.custom_highlight_names_))
    , counter_directives_(MemberCopy(other.counter_directives_))
    , animations_(MemberCopy(other.animations_))
    , transitions_(MemberCopy(other.transitions_))
    , callback_selectors_(other.callback_selectors_)
    , mask_(other.mask_)
    , mask_box_image_(other.mask_box_image_)
    , anchor_scope_(other.anchor_scope_)
    , overflow_clip_margin_(other.overflow_clip_margin_)
    , position_area_offsets_(other.position_area_offsets_)
    , anchor_center_offset_(other.anchor_center_offset_)
    , position_anchor_(MemberCopy(other.position_anchor_))
    , anchor_name_(MemberCopy(other.anchor_name_))
    , container_name_(MemberCopy(other.container_name_))
    , position_try_fallbacks_(MemberCopy(other.position_try_fallbacks_))
    , view_transition_class_(MemberCopy(other.view_transition_class_))
    , view_transition_name_(MemberCopy(other.view_transition_name_))
    , document_rules_selectors_(MemberCopy(other.document_rules_selectors_))
    , paint_images_(MemberCopy(other.paint_images_))
    , non_inherited_variables_(MemberCopy(other.non_inherited_variables_))
    , masonry_slack_(other.masonry_slack_)
    , initial_letter_(other.initial_letter_)
    , page_size_(other.page_size_)
    , popover_hide_delay_(other.popover_hide_delay_)
    , popover_show_delay_(other.popover_show_delay_)
    , scroll_margin_bottom_(other.scroll_margin_bottom_)
    , scroll_margin_left_(other.scroll_margin_left_)
    , scroll_margin_right_(other.scroll_margin_right_)
    , scroll_margin_top_(other.scroll_margin_top_)
    , standard_line_clamp_(other.standard_line_clamp_)
    , position_area_(other.position_area_)
    , effective_appearance_(other.effective_appearance_)
    , container_type_(other.container_type_)
    , position_try_order_(other.position_try_order_)
    , position_visibility_(other.position_visibility_)
    , reading_flow_(other.reading_flow_)
    , inline_block_baseline_edge_(other.inline_block_baseline_edge_)
    , overscroll_behavior_x_(other.overscroll_behavior_x_)
    , overscroll_behavior_y_(other.overscroll_behavior_y_)
    , page_size_type_(other.page_size_type_)
    , scroll_marker_group_(other.scroll_marker_group_)
    , scrollbar_width_(other.scrollbar_width_)
    , view_transition_capture_mode_(other.view_transition_capture_mode_)
    , affected_by_css_function_(other.affected_by_css_function_)
    , align_content_block_center_(other.align_content_block_center_)
    , can_affect_animations_(other.can_affect_animations_)
    , depends_on_scroll_state_container_queries_(other.depends_on_scroll_state_container_queries_)
    , depends_on_size_container_queries_(other.depends_on_size_container_queries_)
    , depends_on_style_container_queries_(other.depends_on_style_container_queries_)
    , effective_z_index_zero_(other.effective_z_index_zero_)
    , element_is_view_transition_participant_(other.element_is_view_transition_participant_)
    , first_line_depends_on_size_container_queries_(other.first_line_depends_on_size_container_queries_)
    , forces_stacking_context_(other.forces_stacking_context_)
    , has_auto_column_count_(other.has_auto_column_count_)
    , has_auto_column_width_(other.has_auto_column_width_)
    , has_current_backdrop_filter_animation_(other.has_current_backdrop_filter_animation_)
    , has_current_background_color_animation_(other.has_current_background_color_animation_)
    , has_current_filter_animation_(other.has_current_filter_animation_)
    , has_current_opacity_animation_(other.has_current_opacity_animation_)
    , has_current_rotate_animation_(other.has_current_rotate_animation_)
    , has_current_scale_animation_(other.has_current_scale_animation_)
    , has_current_transform_animation_(other.has_current_transform_animation_)
    , has_current_translate_animation_(other.has_current_translate_animation_)
    , has_explicit_overflow_x_visible_(other.has_explicit_overflow_x_visible_)
    , has_explicit_overflow_y_visible_(other.has_explicit_overflow_y_visible_)
    , has_line_height_relative_units_(other.has_line_height_relative_units_)
    , has_non_ua_highlight_pseudo_styles_(other.has_non_ua_highlight_pseudo_styles_)
    , has_non_universal_highlight_pseudo_styles_(other.has_non_universal_highlight_pseudo_styles_)
    , highlights_depend_on_size_container_queries_(other.highlights_depend_on_size_container_queries_)
    , inline_style_lost_cascade_(other.inline_style_lost_cascade_)
    , is_running_backdrop_filter_animation_on_compositor_(other.is_running_backdrop_filter_animation_on_compositor_)
    , is_running_filter_animation_on_compositor_(other.is_running_filter_animation_on_compositor_)
    , is_running_opacity_animation_on_compositor_(other.is_running_opacity_animation_on_compositor_)
    , is_running_rotate_animation_on_compositor_(other.is_running_rotate_animation_on_compositor_)
    , is_running_scale_animation_on_compositor_(other.is_running_scale_animation_on_compositor_)
    , is_running_transform_animation_on_compositor_(other.is_running_transform_animation_on_compositor_)
    , is_running_translate_animation_on_compositor_(other.is_running_translate_animation_on_compositor_)
    , is_secondary_body_element_(other.is_secondary_body_element_)
    , is_starting_style_(other.is_starting_style_)
    , outline_style_is_auto_(other.outline_style_is_auto_)
    , overlay_(other.overlay_)
    , requires_accelerated_compositing_for_external_reasons_(other.requires_accelerated_compositing_for_external_reasons_)
    , scroll_start_target_(other.scroll_start_target_)
{
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan100PercentData::StyleRareNonInheritedUsageLessThan100PercentData()
    : grid_auto_columns_(NGGridTrackList(GridTrackSize(Length::Auto())))
    , grid_auto_rows_(NGGridTrackList(GridTrackSize(Length::Auto())))
    , backdrop_filter_(FilterOperations())
    , grid_column_end_(GridPosition())
    , grid_column_start_(GridPosition())
    , grid_row_end_(GridPosition())
    , grid_row_start_(GridPosition())
    , page_(AtomicString())
    , box_reflect_(nullptr)
    , text_decoration_thickness_(TextDecorationThickness(Length::Auto()))
    , column_rule_color_(GapDataList<StyleColor>::DefaultGapColorDataList())
    , clip_path_(nullptr)
    , grid_template_areas_(nullptr)
    , offset_path_(nullptr)
    , rotate_(nullptr)
    , scale_(nullptr)
    , shape_outside_(nullptr)
    , translate_(nullptr)
    , column_gap_(std::nullopt)
    , row_gap_(std::nullopt)
    , offset_rotate_(StyleOffsetRotation(0, OffsetRotationType::kAuto))
    , object_position_(LengthPoint(Length::Percent(50.0), Length::Percent(50.0)))
    , offset_anchor_(LengthPoint(Length::Auto(), Length::Auto()))
    , offset_position_(LengthPoint(Length::None(), Length::None()))
    , perspective_origin_(LengthPoint(Length::Percent(50.0), Length::Percent(50.0)))
    , offset_distance_(Length::Fixed(0))
    , scroll_padding_bottom_(Length())
    , scroll_padding_left_(Length())
    , scroll_padding_right_(Length())
    , scroll_padding_top_(Length())
    , shape_margin_(Length::Fixed(0))
    , column_width_(0.0f)
    , perspective_(-1.0)
    , shape_image_threshold_(0.0)
    , scroll_snap_type_(cc::ScrollSnapType())
    , scroll_snap_align_(cc::ScrollSnapAlign())
    , outline_color_(StyleColor::CurrentColor())
    , text_decoration_color_(StyleColor::CurrentColor())
    , box_ordinal_group_(1)
    , column_rule_width_(3)
    , column_count_(1)
    , justify_items_(StyleSelfAlignmentData(ItemPosition::kLegacy, OverflowAlignment::kDefault))
    , justify_self_(StyleSelfAlignmentData(ItemPosition::kAuto, OverflowAlignment::kDefault))
    , blend_mode_(static_cast<unsigned>(BlendMode::kNormal))
    , contain_(static_cast<unsigned>(kContainsNone))
    , break_after_(static_cast<unsigned>(EBreakBetween::kAuto))
    , break_before_(static_cast<unsigned>(EBreakBetween::kAuto))
    , column_rule_style_(static_cast<unsigned>(EBorderStyle::kNone))
    , grid_auto_flow_(static_cast<unsigned>(kAutoFlowRow))
    , text_decoration_style_(static_cast<unsigned>(ETextDecorationStyle::kSolid))
    , break_inside_(static_cast<unsigned>(EBreakInside::kAuto))
    , column_fill_(static_cast<unsigned>(EColumnFill::kBalance))
    , draggable_region_mode_(static_cast<unsigned>(EDraggableRegionMode::kNone))
    , page_orientation_(static_cast<unsigned>(PageOrientation::kUpright))
    , scroll_behavior_(static_cast<unsigned>(mojom::blink::ScrollBehavior::kAuto))
    , user_drag_(static_cast<unsigned>(EUserDrag::kAuto))
    , column_span_(static_cast<unsigned>(EColumnSpan::kNone))
    , isolation_(static_cast<unsigned>(EIsolation::kAuto))
    , transform_style_3d_(static_cast<unsigned>(ETransformStyle3D::kFlat))
{
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan100PercentData::StyleRareNonInheritedUsageLessThan100PercentData(
    const StyleRareNonInheritedUsageLessThan100PercentData& other)
    : grid_auto_columns_(other.grid_auto_columns_)
    , grid_auto_rows_(other.grid_auto_rows_)
    , backdrop_filter_(other.backdrop_filter_)
    , grid_column_end_(other.grid_column_end_)
    , grid_column_start_(other.grid_column_start_)
    , grid_row_end_(other.grid_row_end_)
    , grid_row_start_(other.grid_row_start_)
    , page_(other.page_)
    , box_reflect_(MemberCopy(other.box_reflect_))
    , text_decoration_thickness_(other.text_decoration_thickness_)
    , column_rule_color_(other.column_rule_color_)
    , clip_path_(MemberCopy(other.clip_path_))
    , grid_template_areas_(MemberCopy(other.grid_template_areas_))
    , offset_path_(MemberCopy(other.offset_path_))
    , rotate_(MemberCopy(other.rotate_))
    , scale_(MemberCopy(other.scale_))
    , shape_outside_(MemberCopy(other.shape_outside_))
    , translate_(MemberCopy(other.translate_))
    , column_gap_(other.column_gap_)
    , row_gap_(other.row_gap_)
    , offset_rotate_(other.offset_rotate_)
    , object_position_(other.object_position_)
    , offset_anchor_(other.offset_anchor_)
    , offset_position_(other.offset_position_)
    , perspective_origin_(other.perspective_origin_)
    , offset_distance_(other.offset_distance_)
    , scroll_padding_bottom_(other.scroll_padding_bottom_)
    , scroll_padding_left_(other.scroll_padding_left_)
    , scroll_padding_right_(other.scroll_padding_right_)
    , scroll_padding_top_(other.scroll_padding_top_)
    , shape_margin_(other.shape_margin_)
    , column_width_(other.column_width_)
    , perspective_(other.perspective_)
    , shape_image_threshold_(other.shape_image_threshold_)
    , scroll_snap_type_(other.scroll_snap_type_)
    , scroll_snap_align_(other.scroll_snap_align_)
    , outline_color_(other.outline_color_)
    , text_decoration_color_(other.text_decoration_color_)
    , box_ordinal_group_(other.box_ordinal_group_)
    , column_rule_width_(other.column_rule_width_)
    , column_count_(other.column_count_)
    , justify_items_(other.justify_items_)
    , justify_self_(other.justify_self_)
    , blend_mode_(other.blend_mode_)
    , contain_(other.contain_)
    , break_after_(other.break_after_)
    , break_before_(other.break_before_)
    , column_rule_style_(other.column_rule_style_)
    , grid_auto_flow_(other.grid_auto_flow_)
    , text_decoration_style_(other.text_decoration_style_)
    , break_inside_(other.break_inside_)
    , column_fill_(other.column_fill_)
    , draggable_region_mode_(other.draggable_region_mode_)
    , page_orientation_(other.page_orientation_)
    , scroll_behavior_(other.scroll_behavior_)
    , user_drag_(other.user_drag_)
    , column_span_(other.column_span_)
    , isolation_(other.isolation_)
    , transform_style_3d_(other.transform_style_3d_)
{
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan22PercentData::StyleRareNonInheritedUsageLessThan22PercentData()
    : rare_non_inherited_usage_less_than_100_percent_data_(StyleRareNonInheritedUsageLessThan100PercentData::Create())
    , filter_(FilterOperations())
    , flex_basis_(Length::Auto())
    , flex_grow_(0.0f)
    , flex_shrink_(1.0f)
    , box_flex_(0.0f)
    , outline_offset_(LayoutUnit())
    , order_(0)
    , outline_width_(3)
    , webkit_line_clamp_(0)
    , align_self_(StyleSelfAlignmentData(ItemPosition::kAuto, OverflowAlignment::kDefault))
    , align_content_(StyleContentAlignmentData(ContentPosition::kNormal, ContentDistributionType::kDefault, OverflowAlignment::kDefault))
    , touch_action_(static_cast<unsigned>(TouchAction::kAuto))
    , outline_style_(static_cast<unsigned>(EBorderStyle::kNone))
    , box_align_(static_cast<unsigned>(EBoxAlignment::kStretch))
    , object_fit_(static_cast<unsigned>(EObjectFit::kFill))
    , resize_(static_cast<unsigned>(EResize::kNone))
    , box_pack_(static_cast<unsigned>(EBoxPack::kStart))
    , backface_visibility_(static_cast<unsigned>(EBackfaceVisibility::kVisible))
    , box_orient_(static_cast<unsigned>(EBoxOrient::kHorizontal))
{
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan22PercentData::StyleRareNonInheritedUsageLessThan22PercentData(
    const StyleRareNonInheritedUsageLessThan22PercentData& other)
    : rare_non_inherited_usage_less_than_100_percent_data_(other.rare_non_inherited_usage_less_than_100_percent_data_)
    , filter_(other.filter_)
    , flex_basis_(other.flex_basis_)
    , flex_grow_(other.flex_grow_)
    , flex_shrink_(other.flex_shrink_)
    , box_flex_(other.box_flex_)
    , outline_offset_(other.outline_offset_)
    , order_(other.order_)
    , outline_width_(other.outline_width_)
    , webkit_line_clamp_(other.webkit_line_clamp_)
    , align_self_(other.align_self_)
    , align_content_(other.align_content_)
    , touch_action_(other.touch_action_)
    , outline_style_(other.outline_style_)
    , box_align_(other.box_align_)
    , object_fit_(other.object_fit_)
    , resize_(other.resize_)
    , box_pack_(other.box_pack_)
    , backface_visibility_(other.backface_visibility_)
    , box_orient_(other.box_orient_)
{
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan14PercentData::StyleRareNonInheritedUsageLessThan14PercentData()
    : rare_non_inherited_usage_less_than_14_percent_sub_data_(StyleRareNonInheritedUsageLessThan14PercentSubData::Create())
    , rare_non_inherited_usage_less_than_22_percent_data_(StyleRareNonInheritedUsageLessThan22PercentData::Create())
    , transform_(EmptyTransformOperations())
    , box_shadow_(nullptr)
    , content_(nullptr)
    , opacity_(1.0)
    , align_items_(StyleSelfAlignmentData(ItemPosition::kNormal, OverflowAlignment::kDefault))
    , justify_content_(StyleContentAlignmentData(ContentPosition::kNormal, ContentDistributionType::kDefault, OverflowAlignment::kDefault))
    , appearance_(static_cast<unsigned>(kNoControlPart))
    , flex_direction_(static_cast<unsigned>(EFlexDirection::kRow))
    , flex_wrap_(static_cast<unsigned>(EFlexWrap::kNowrap))
    , text_overflow_(static_cast<unsigned>(ETextOverflow::kClip))
{
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan14PercentData::StyleRareNonInheritedUsageLessThan14PercentData(
    const StyleRareNonInheritedUsageLessThan14PercentData& other)
    : rare_non_inherited_usage_less_than_14_percent_sub_data_(other.rare_non_inherited_usage_less_than_14_percent_sub_data_)
    , rare_non_inherited_usage_less_than_22_percent_data_(other.rare_non_inherited_usage_less_than_22_percent_data_)
    , transform_(other.transform_)
    , box_shadow_(MemberCopy(other.box_shadow_))
    , content_(MemberCopy(other.content_))
    , opacity_(other.opacity_)
    , align_items_(other.align_items_)
    , justify_content_(other.justify_content_)
    , appearance_(other.appearance_)
    , flex_direction_(other.flex_direction_)
    , flex_wrap_(other.flex_wrap_)
    , text_overflow_(other.text_overflow_)
{
}

ComputedStyleBase::StyleInheritedData::StyleInheritedData()
    : inherited_variables_(nullptr)
    , line_height_(Length::Auto())
    , text_autosizing_multiplier_(1.0)
    , color_(StyleColor(Color::kBlack))
    , internal_visited_color_(StyleColor(Color::kBlack))
    , horizontal_border_spacing_(0)
    , vertical_border_spacing_(0)
    , color_is_current_color_(static_cast<unsigned>(true))
    , in_forced_colors_mode_(static_cast<unsigned>(false))
    , internal_visited_color_is_current_color_(static_cast<unsigned>(true))
{
}

ComputedStyleBase::StyleInheritedData::StyleInheritedData(const StyleInheritedData& other)
    : inherited_variables_(MemberCopy(other.inherited_variables_))
    , line_height_(other.line_height_)
    , text_autosizing_multiplier_(other.text_autosizing_multiplier_)
    , color_(other.color_)
    , internal_visited_color_(other.internal_visited_color_)
    , horizontal_border_spacing_(other.horizontal_border_spacing_)
    , vertical_border_spacing_(other.vertical_border_spacing_)
    , color_is_current_color_(other.color_is_current_color_)
    , in_forced_colors_mode_(other.in_forced_colors_mode_)
    , internal_visited_color_is_current_color_(other.internal_visited_color_is_current_color_)
{
}

ComputedStyleBase::StyleVisualData::StyleVisualData()
    : base_text_decoration_data_(nullptr)
    , clip_(LengthBox())
    , zoom_(1.0)
    , text_decoration_line_(static_cast<unsigned>(TextDecorationLine::kNone))
    , field_sizing_(static_cast<unsigned>(EFieldSizing::kFixed))
    , has_auto_clip_(static_cast<unsigned>(true))
    , has_clip_path_(static_cast<unsigned>(false))
{
}

ComputedStyleBase::StyleVisualData::StyleVisualData(const StyleVisualData& other)
    : base_text_decoration_data_(MemberCopy(other.base_text_decoration_data_))
    , clip_(other.clip_)
    , zoom_(other.zoom_)
    , text_decoration_line_(other.text_decoration_line_)
    , field_sizing_(other.field_sizing_)
    , has_auto_clip_(other.has_auto_clip_)
    , has_clip_path_(other.has_clip_path_)
{
}

ComputedStyleBase::StyleMiscData::StyleMiscData()
    : baseline_shift_(Length::Fixed())
    , flood_opacity_(1)
    , flood_color_(StyleColor(Color::kBlack))
    , lighting_color_(StyleColor(Color::kWhite))
    , baseline_shift_type_(static_cast<unsigned>(EBaselineShiftType::kLength))
{
}

ComputedStyleBase::StyleMiscData::StyleMiscData(const StyleMiscData& other)
    : baseline_shift_(other.baseline_shift_)
    , flood_opacity_(other.flood_opacity_)
    , flood_color_(other.flood_color_)
    , lighting_color_(other.lighting_color_)
    , baseline_shift_type_(other.baseline_shift_type_)
{
}

ComputedStyleBase::StyleGeometryData::StyleGeometryData()
    : d_(nullptr)
    , cx_(Length::Fixed())
    , cy_(Length::Fixed())
    , r_(Length::Fixed())
    , rx_(Length::Auto())
    , ry_(Length::Auto())
    , x_(Length::Fixed())
    , y_(Length::Fixed())
{
}

ComputedStyleBase::StyleGeometryData::StyleGeometryData(const StyleGeometryData& other)
    : d_(MemberCopy(other.d_))
    , cx_(other.cx_)
    , cy_(other.cy_)
    , r_(other.r_)
    , rx_(other.rx_)
    , ry_(other.ry_)
    , x_(other.x_)
    , y_(other.y_)
{
}

ComputedStyleBase::StyleFillData::StyleFillData()
    : fill_paint_(SVGPaint(Color::kBlack))
    , internal_visited_fill_paint_(SVGPaint(Color::kBlack))
    , fill_opacity_(1)
{
}

ComputedStyleBase::StyleFillData::StyleFillData(const StyleFillData& other)
    : fill_paint_(other.fill_paint_)
    , internal_visited_fill_paint_(other.internal_visited_fill_paint_)
    , fill_opacity_(other.fill_opacity_)
{
}

ComputedStyleBase::StyleStrokeData::StyleStrokeData()
    : stroke_dash_array_(EmptyDashArray())
    , internal_visited_stroke_paint_(SVGPaint())
    , stroke_paint_(SVGPaint())
    , stroke_dash_offset_(Length::Fixed())
    , stroke_width_(UnzoomedLength(Length::Fixed(1)))
    , stroke_miter_limit_(4)
    , stroke_opacity_(1)
    , cap_style_(static_cast<unsigned>(kButtCap))
    , join_style_(static_cast<unsigned>(kMiterJoin))
{
}

ComputedStyleBase::StyleStrokeData::StyleStrokeData(const StyleStrokeData& other)
    : stroke_dash_array_(MemberCopy(other.stroke_dash_array_))
    , internal_visited_stroke_paint_(other.internal_visited_stroke_paint_)
    , stroke_paint_(other.stroke_paint_)
    , stroke_dash_offset_(other.stroke_dash_offset_)
    , stroke_width_(other.stroke_width_)
    , stroke_miter_limit_(other.stroke_miter_limit_)
    , stroke_opacity_(other.stroke_opacity_)
    , cap_style_(other.cap_style_)
    , join_style_(other.join_style_)
{
}

ComputedStyleBase::StyleInheritedResourcesData::StyleInheritedResourcesData()
    : marker_end_resource_(nullptr)
    , marker_mid_resource_(nullptr)
    , marker_start_resource_(nullptr)
{
}

ComputedStyleBase::StyleInheritedResourcesData::StyleInheritedResourcesData(const StyleInheritedResourcesData& other)
    : marker_end_resource_(MemberCopy(other.marker_end_resource_))
    , marker_mid_resource_(MemberCopy(other.marker_mid_resource_))
    , marker_start_resource_(MemberCopy(other.marker_start_resource_))
{
}

ComputedStyleBase::StyleStopData::StyleStopData()
    : stop_opacity_(1)
    , stop_color_(StyleColor(Color::kBlack))
{
}

ComputedStyleBase::StyleStopData::StyleStopData(const StyleStopData& other)
    : stop_opacity_(other.stop_opacity_)
    , stop_color_(other.stop_color_)
{
}

ComputedStyleBase::StyleSVGData::StyleSVGData()
    : misc_data_(StyleMiscData::Create())
    , geometry_data_(StyleGeometryData::Create())
    , fill_data_(StyleFillData::Create())
    , stroke_data_(StyleStrokeData::Create())
    , inherited_resources_data_(StyleInheritedResourcesData::Create())
    , stop_data_(StyleStopData::Create())
    , transform_origin_(TransformOrigin(Length::Percent(50.0), Length::Percent(50.0), 0))
    , alignment_baseline_(static_cast<unsigned>(EAlignmentBaseline::kAuto))
    , css_dominant_baseline_(static_cast<unsigned>(EDominantBaseline::kAuto))
    , dominant_baseline_(static_cast<unsigned>(EDominantBaseline::kAuto))
    , paint_order_(static_cast<unsigned>(kPaintOrderNormal))
    , buffered_rendering_(static_cast<unsigned>(EBufferedRendering::kAuto))
    , color_interpolation_(static_cast<unsigned>(EColorInterpolation::kSRGB))
    , color_interpolation_filters_(static_cast<unsigned>(EColorInterpolation::kLinearrgb))
    , color_rendering_(static_cast<unsigned>(EColorRendering::kAuto))
    , shape_rendering_(static_cast<unsigned>(EShapeRendering::kAuto))
    , text_anchor_(static_cast<unsigned>(ETextAnchor::kStart))
    , clip_rule_(static_cast<unsigned>(RULE_NONZERO))
    , fill_rule_(static_cast<unsigned>(RULE_NONZERO))
    , mask_type_(static_cast<unsigned>(EMaskType::kLuminance))
    , vector_effect_(static_cast<unsigned>(EVectorEffect::kNone))
{
}

ComputedStyleBase::StyleSVGData::StyleSVGData(const StyleSVGData& other)
    : misc_data_(other.misc_data_)
    , geometry_data_(other.geometry_data_)
    , fill_data_(other.fill_data_)
    , stroke_data_(other.stroke_data_)
    , inherited_resources_data_(other.inherited_resources_data_)
    , stop_data_(other.stop_data_)
    , transform_origin_(other.transform_origin_)
    , alignment_baseline_(other.alignment_baseline_)
    , css_dominant_baseline_(other.css_dominant_baseline_)
    , dominant_baseline_(other.dominant_baseline_)
    , paint_order_(other.paint_order_)
    , buffered_rendering_(other.buffered_rendering_)
    , color_interpolation_(other.color_interpolation_)
    , color_interpolation_filters_(other.color_interpolation_filters_)
    , color_rendering_(other.color_rendering_)
    , shape_rendering_(other.shape_rendering_)
    , text_anchor_(other.text_anchor_)
    , clip_rule_(other.clip_rule_)
    , fill_rule_(other.fill_rule_)
    , mask_type_(other.mask_type_)
    , vector_effect_(other.vector_effect_)
{
}

ComputedStyleBase::StyleSurroundData::StyleSurroundData()
    : border_image_(NinePieceImage())
    , aspect_ratio_(StyleAspectRatio(EAspectRatioType::kAuto, gfx::SizeF()))
    , contain_intrinsic_height_(StyleIntrinsicLength())
    , contain_intrinsic_width_(StyleIntrinsicLength())
    , border_bottom_left_radius_(LengthSize(Length::Fixed(0), Length::Fixed(0)))
    , border_bottom_right_radius_(LengthSize(Length::Fixed(0), Length::Fixed(0)))
    , border_top_left_radius_(LengthSize(Length::Fixed(0), Length::Fixed(0)))
    , border_top_right_radius_(LengthSize(Length::Fixed(0), Length::Fixed(0)))
    , bottom_(Length())
    , left_(Length())
    , right_(Length())
    , top_(Length())
    , border_bottom_color_(StyleColor::CurrentColor())
    , border_left_color_(StyleColor::CurrentColor())
    , border_right_color_(StyleColor::CurrentColor())
    , border_top_color_(StyleColor::CurrentColor())
    , has_anchor_evaluator_(static_cast<unsigned>(false))
    , has_anchor_functions_(static_cast<unsigned>(false))
    , may_have_margin_(static_cast<unsigned>(false))
    , may_have_padding_(static_cast<unsigned>(false))
{
}

ComputedStyleBase::StyleSurroundData::StyleSurroundData(const StyleSurroundData& other)
    : border_image_(other.border_image_)
    , aspect_ratio_(other.aspect_ratio_)
    , contain_intrinsic_height_(other.contain_intrinsic_height_)
    , contain_intrinsic_width_(other.contain_intrinsic_width_)
    , border_bottom_left_radius_(other.border_bottom_left_radius_)
    , border_bottom_right_radius_(other.border_bottom_right_radius_)
    , border_top_left_radius_(other.border_top_left_radius_)
    , border_top_right_radius_(other.border_top_right_radius_)
    , bottom_(other.bottom_)
    , left_(other.left_)
    , right_(other.right_)
    , top_(other.top_)
    , border_bottom_color_(other.border_bottom_color_)
    , border_left_color_(other.border_left_color_)
    , border_right_color_(other.border_right_color_)
    , border_top_color_(other.border_top_color_)
    , has_anchor_evaluator_(other.has_anchor_evaluator_)
    , has_anchor_functions_(other.has_anchor_functions_)
    , may_have_margin_(other.may_have_margin_)
    , may_have_padding_(other.may_have_padding_)
{
}

ComputedStyleBase::StyleBackgroundData::StyleBackgroundData()
    : background_(FillLayer(EFillLayerType::kBackground, true))
    , background_color_(StyleColor(Color::kTransparent))
{
}

ComputedStyleBase::StyleBackgroundData::StyleBackgroundData(const StyleBackgroundData& other)
    : background_(other.background_)
    , background_color_(other.background_color_)
{
}

ComputedStyleBase::StyleBoxData::StyleBoxData()
    : height_(Length())
    , margin_bottom_(Length::Fixed())
    , margin_left_(Length::Fixed())
    , margin_right_(Length::Fixed())
    , margin_top_(Length::Fixed())
    , max_height_(Length::None())
    , max_width_(Length::None())
    , min_height_(Length())
    , min_width_(Length())
    , padding_bottom_(Length::Fixed())
    , padding_left_(Length::Fixed())
    , padding_right_(Length::Fixed())
    , padding_top_(Length::Fixed())
    , width_(Length())
    , vertical_align_length_(Length())
    , border_bottom_width_(3)
    , border_left_width_(3)
    , border_right_width_(3)
    , border_top_width_(3)
    , z_index_(0)
    , border_bottom_style_(static_cast<unsigned>(EBorderStyle::kNone))
    , border_left_style_(static_cast<unsigned>(EBorderStyle::kNone))
    , border_right_style_(static_cast<unsigned>(EBorderStyle::kNone))
    , border_top_style_(static_cast<unsigned>(EBorderStyle::kNone))
    , baseline_source_(static_cast<unsigned>(EBaselineSource::kAuto))
    , text_box_trim_(static_cast<unsigned>(ETextBoxTrim::kNone))
    , box_decoration_break_(static_cast<unsigned>(EBoxDecorationBreak::kSlice))
    , has_auto_standard_line_clamp_(static_cast<unsigned>(false))
    , has_auto_z_index_(static_cast<unsigned>(true))
{
}

ComputedStyleBase::StyleBoxData::StyleBoxData(const StyleBoxData& other)
    : height_(other.height_)
    , margin_bottom_(other.margin_bottom_)
    , margin_left_(other.margin_left_)
    , margin_right_(other.margin_right_)
    , margin_top_(other.margin_top_)
    , max_height_(other.max_height_)
    , max_width_(other.max_width_)
    , min_height_(other.min_height_)
    , min_width_(other.min_width_)
    , padding_bottom_(other.padding_bottom_)
    , padding_left_(other.padding_left_)
    , padding_right_(other.padding_right_)
    , padding_top_(other.padding_top_)
    , width_(other.width_)
    , vertical_align_length_(other.vertical_align_length_)
    , border_bottom_width_(other.border_bottom_width_)
    , border_left_width_(other.border_left_width_)
    , border_right_width_(other.border_right_width_)
    , border_top_width_(other.border_top_width_)
    , z_index_(other.z_index_)
    , border_bottom_style_(other.border_bottom_style_)
    , border_left_style_(other.border_left_style_)
    , border_right_style_(other.border_right_style_)
    , border_top_style_(other.border_top_style_)
    , baseline_source_(other.baseline_source_)
    , text_box_trim_(other.text_box_trim_)
    , box_decoration_break_(other.box_decoration_break_)
    , has_auto_standard_line_clamp_(other.has_auto_standard_line_clamp_)
    , has_auto_z_index_(other.has_auto_z_index_)
{
}

ComputedStyleBase::StyleFontData::StyleFontData()
    : font_(Font())
{
}

ComputedStyleBase::StyleFontData::StyleFontData(const StyleFontData& other)
    : font_(other.font_)
{
}

ComputedStyleBuilderBase::ComputedStyleBuilderBase(const ComputedStyleBase& style)
    : rare_inherited_usage_less_than_64_percent_data_(style.rare_inherited_usage_less_than_64_percent_data_)
    , rare_non_inherited_usage_less_than_14_percent_data_(style.rare_non_inherited_usage_less_than_14_percent_data_)
    , inherited_data_(style.inherited_data_)
    , visual_data_(style.visual_data_)
    , svg_data_(style.svg_data_)
    , surround_data_(style.surround_data_)
    , background_data_(style.background_data_)
    , box_data_(style.box_data_)
    , font_data_(style.font_data_)
    , base_data_(style.base_data_)
    , data_(style.data_)
{
}

ComputedStyleBuilderBase::ComputedStyleBuilderBase(const ComputedStyleBase& source_for_noninherited, const ComputedStyleBase& parent_style)
    : rare_inherited_usage_less_than_64_percent_data_(parent_style.rare_inherited_usage_less_than_64_percent_data_)
    , rare_non_inherited_usage_less_than_14_percent_data_(source_for_noninherited.rare_non_inherited_usage_less_than_14_percent_data_)
    , inherited_data_(parent_style.inherited_data_)
    , visual_data_(source_for_noninherited.visual_data_)
    , svg_data_(parent_style.svg_data_ == source_for_noninherited.svg_data_
              ? parent_style.svg_data_.Get()
              : MakeGarbageCollected<StyleSVGData>(*source_for_noninherited.svg_data_, *parent_style.svg_data_))
    , surround_data_(source_for_noninherited.surround_data_)
    , background_data_(source_for_noninherited.background_data_)
    , box_data_(source_for_noninherited.box_data_)
    , font_data_(parent_style.font_data_)
    , base_data_(nullptr /* base_data_ */)
    , data_ { static_cast<unsigned>(kPseudoIdNone) /* pseudo_element_styles_ */
        ,
        parent_style.data_.cursor_, parent_style.data_.pointer_events_, static_cast<unsigned>(false) /* affected_by_active_ */
        ,
        source_for_noninherited.data_.display_, static_cast<unsigned>(PseudoId::kPseudoIdNone) /* style_type_ */
        ,
        source_for_noninherited.data_.scrollbar_gutter_, parent_style.data_.text_align_, source_for_noninherited.data_.vertical_align_,
        source_for_noninherited.data_.clear_, source_for_noninherited.data_.floating_, source_for_noninherited.data_.content_visibility_,
        source_for_noninherited.data_.overflow_x_, source_for_noninherited.data_.overflow_y_, source_for_noninherited.data_.position_,
        parent_style.data_.text_transform_, source_for_noninherited.data_.transform_box_, source_for_noninherited.data_.unicode_bidi_,
        parent_style.data_.writing_mode_, parent_style.data_.inside_link_, static_cast<unsigned>(0) /* is_stacking_context_without_containment_ (mutable) */
        ,
        source_for_noninherited.data_.overflow_anchor_, parent_style.data_.text_wrap_style_, source_for_noninherited.data_.viewport_unit_flags_,
        static_cast<unsigned>(false) /* affected_by_drag_ */
        ,
        parent_style.data_.visibility_, parent_style.data_.white_space_collapse_, static_cast<unsigned>(false) /* affected_by_focus_within_ */
        ,
        static_cast<unsigned>(false) /* affected_by_hover_ */
        ,
        parent_style.data_.border_collapse_, source_for_noninherited.data_.border_collapse_is_inherited_, source_for_noninherited.data_.box_direction_,
        source_for_noninherited.data_.box_sizing_, parent_style.data_.caption_side_, source_for_noninherited.data_.caption_side_is_inherited_,
        parent_style.data_.caret_animation_, static_cast<unsigned>(false) /* child_has_explicit_inheritance_ (mutable) */
        ,
        source_for_noninherited.data_.color_is_inherited_, parent_style.data_.color_scheme_flags_is_normal_, parent_style.data_.color_scheme_forced_,
        source_for_noninherited.data_.custom_style_callback_depends_on_font_, parent_style.data_.dark_color_scheme_, parent_style.data_.direction_,
        parent_style.data_.empty_cells_, source_for_noninherited.data_.empty_cells_is_inherited_, static_cast<unsigned>(false) /* has_attr_function_ */
        ,
        source_for_noninherited.data_.has_author_background_, source_for_noninherited.data_.has_author_border_,
        source_for_noninherited.data_.has_author_border_radius_, source_for_noninherited.data_.has_author_highlight_colors_,
        source_for_noninherited.data_.has_container_relative_units_, source_for_noninherited.data_.has_em_units_, source_for_noninherited.data_.has_env_,
        source_for_noninherited.data_.has_explicit_inheritance_, source_for_noninherited.data_.has_glyph_relative_units_,
        source_for_noninherited.data_.has_logical_direction_relative_units_, source_for_noninherited.data_.has_root_font_relative_units_,
        source_for_noninherited.data_.has_variable_declaration_, source_for_noninherited.data_.has_variable_reference_,
        source_for_noninherited.data_.is_ensured_in_display_none_, parent_style.data_.is_ensured_outside_flat_tree_,
        source_for_noninherited.data_.is_flex_or_grid_or_custom_item_, parent_style.data_.is_html_inert_,
        source_for_noninherited.data_.is_html_inert_is_inherited_, source_for_noninherited.data_.is_in_blockifying_display_,
        source_for_noninherited.data_.is_in_inlinifying_display_, source_for_noninherited.data_.is_inside_display_ignoring_floating_children_,
        parent_style.data_.is_inside_list_element_, static_cast<unsigned>(false) /* is_link_ */
        ,
        source_for_noninherited.data_.is_original_display_inline_type_, source_for_noninherited.data_.is_page_margin_box_,
        source_for_noninherited.data_.is_specified_display_webkit_box_, parent_style.data_.list_style_position_,
        source_for_noninherited.data_.list_style_position_is_inherited_, source_for_noninherited.data_.origin_trial_test_property_,
        source_for_noninherited.data_.pointer_events_is_inherited_, parent_style.data_.prefers_default_scrollbar_styles_,
        parent_style.data_.print_color_adjust_, parent_style.data_.rtl_ordering_, source_for_noninherited.data_.rtl_ordering_is_inherited_,
        source_for_noninherited.data_.scroll_snap_stop_, source_for_noninherited.data_.should_ignore_overflow_property_for_inline_block_baseline_,
        source_for_noninherited.data_.skips_contents_, source_for_noninherited.data_.table_layout_, source_for_noninherited.data_.text_transform_is_inherited_,
        parent_style.data_.text_wrap_mode_, source_for_noninherited.data_.visibility_is_inherited_ }
{
    if (parent_style.svg_data_ != source_for_noninherited.svg_data_) {
        // We created this object fresh ourselves, so we do not need to clone it
        // if we wish to do further changes later on.
        access_.svg_data_ = true;
    }

    // The following fields have the 'reset_on_new_style' flag set, but were
    // part of groups that were copied wholesale in the initialization.
    if (rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->custom_highlight_names_ != nullptr) {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->custom_highlight_names_
            = nullptr;
    }
    if (rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_non_ua_highlight_pseudo_styles_
        != static_cast<unsigned>(false)) {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->has_non_ua_highlight_pseudo_styles_
            = static_cast<unsigned>(false);
    }
    if (rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_non_universal_highlight_pseudo_styles_
        != static_cast<unsigned>(false)) {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->has_non_universal_highlight_pseudo_styles_
            = static_cast<unsigned>(false);
    }
    if (rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
            ->highlights_depend_on_size_container_queries_
        != static_cast<unsigned>(false)) {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->highlights_depend_on_size_container_queries_
            = static_cast<unsigned>(false);
    }
}

void ComputedStyleBuilderBase::PropagateIndependentInheritedProperties(const ComputedStyleBase& parent_style)
{
    ComputedStyleBuilderBase& builder = *this;
    if (ColorIsInherited())
        builder.Access(inherited_data_, access_.inherited_data_)->color_ = parent_style.inherited_data_->color_;
    if (PointerEventsIsInherited())
        builder.data_.pointer_events_ = parent_style.data_.pointer_events_;
    if (TextTransformIsInherited())
        builder.data_.text_transform_ = parent_style.data_.text_transform_;
    if (VisibilityIsInherited())
        builder.data_.visibility_ = parent_style.data_.visibility_;
    if (BorderCollapseIsInherited())
        builder.data_.border_collapse_ = parent_style.data_.border_collapse_;
    if (CaptionSideIsInherited())
        builder.data_.caption_side_ = parent_style.data_.caption_side_;
    if (EmptyCellsIsInherited())
        builder.data_.empty_cells_ = parent_style.data_.empty_cells_;
    if (IsHTMLInertIsInherited())
        builder.data_.is_html_inert_ = parent_style.data_.is_html_inert_;
    if (ListStylePositionIsInherited())
        builder.data_.list_style_position_ = parent_style.data_.list_style_position_;
    if (RtlOrderingIsInherited())
        builder.data_.rtl_ordering_ = parent_style.data_.rtl_ordering_;
}

} // namespace blink
