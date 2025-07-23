// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/style/templates/computed_style_base.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_group_config.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/core/css/css_properties_ranking.json5
//   ../../third_party/blink/renderer/core/css/css_value_keywords.json5
//   ../../third_party/blink/renderer/core/style/computed_style_extra_fields.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_BASE_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_BASE_H_

#include "base/memory/values_equivalent.h"
#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/style/computed_style_constants.h"
#include "third_party/blink/renderer/core/style/member_copy.h"
#include "third_party/blink/renderer/core/style/computed_style_initial_values.h"
#include "third_party/blink/renderer/core/style/style_cached_data.h"
#include "cc/input/scroll_snap_data.h"
#include "third_party/blink/public/common/css/page_orientation.h"
#include "third_party/blink/public/common/css/page_size_type.h"
#include "third_party/blink/public/mojom/frame/color_scheme.mojom-blink.h"
#include "third_party/blink/public/mojom/scroll/scroll_enums.mojom-blink.h"
#include "third_party/blink/renderer/core/animation/css/css_animation_data.h"
#include "third_party/blink/renderer/core/animation/css/css_transition_data.h"
#include "third_party/blink/renderer/core/animation/effect_model.h"
#include "third_party/blink/renderer/core/animation/timeline_inset.h"
#include "third_party/blink/renderer/core/css/css_property_names.h"
#include "third_party/blink/renderer/core/css/style_auto_color.h"
#include "third_party/blink/renderer/core/css/style_color.h"
#include "third_party/blink/renderer/core/css/style_rule.h"
#include "third_party/blink/renderer/core/css/white_space.h"
#include "third_party/blink/renderer/core/css_value_keywords.h"
#include "third_party/blink/renderer/core/keywords.h"
#include "third_party/blink/renderer/core/layout/geometry/physical_offset.h"
#include "third_party/blink/renderer/core/layout/layout_theme.h"
#include "third_party/blink/renderer/core/style/applied_text_decoration.h"
#include "third_party/blink/renderer/core/style/basic_shapes.h"
#include "third_party/blink/renderer/core/style/clip_path_operation.h"
#include "third_party/blink/renderer/core/style/computed_grid_template_areas.h"
#include "third_party/blink/renderer/core/style/computed_grid_track_list.h"
#include "third_party/blink/renderer/core/style/content_data.h"
#include "third_party/blink/renderer/core/style/counter_directives.h"
#include "third_party/blink/renderer/core/style/cursor_list.h"
#include "third_party/blink/renderer/core/style/fill_layer.h"
#include "third_party/blink/renderer/core/style/filter_operations.h"
#include "third_party/blink/renderer/core/style/gap_data_list.h"
#include "third_party/blink/renderer/core/style/grid_position.h"
#include "third_party/blink/renderer/core/style/grid_track_list.h"
#include "third_party/blink/renderer/core/style/list_style_type_data.h"
#include "third_party/blink/renderer/core/style/nine_piece_image.h"
#include "third_party/blink/renderer/core/style/offset_path_operation.h"
#include "third_party/blink/renderer/core/style/paint_images.h"
#include "third_party/blink/renderer/core/style/position_area.h"
#include "third_party/blink/renderer/core/style/position_try_fallbacks.h"
#include "third_party/blink/renderer/core/style/scoped_css_name.h"
#include "third_party/blink/renderer/core/style/scroll_start_data.h"
#include "third_party/blink/renderer/core/style/shadow_list.h"
#include "third_party/blink/renderer/core/style/shape_value.h"
#include "third_party/blink/renderer/core/style/style_anchor_scope.h"
#include "third_party/blink/renderer/core/style/style_aspect_ratio.h"
#include "third_party/blink/renderer/core/style/style_base_data.h"
#include "third_party/blink/renderer/core/style/style_content_alignment_data.h"
#include "third_party/blink/renderer/core/style/style_highlight_data.h"
#include "third_party/blink/renderer/core/style/style_hyphenate_limit_chars.h"
#include "third_party/blink/renderer/core/style/style_image.h"
#include "third_party/blink/renderer/core/style/style_inherited_variables.h"
#include "third_party/blink/renderer/core/style/style_initial_data.h"
#include "third_party/blink/renderer/core/style/style_initial_letter.h"
#include "third_party/blink/renderer/core/style/style_intrinsic_length.h"
#include "third_party/blink/renderer/core/style/style_non_inherited_variables.h"
#include "third_party/blink/renderer/core/style/style_offset_rotation.h"
#include "third_party/blink/renderer/core/style/style_overflow_clip_margin.h"
#include "third_party/blink/renderer/core/style/style_path.h"
#include "third_party/blink/renderer/core/style/style_reflection.h"
#include "third_party/blink/renderer/core/style/style_scrollbar_color.h"
#include "third_party/blink/renderer/core/style/style_self_alignment_data.h"
#include "third_party/blink/renderer/core/style/style_svg_resource.h"
#include "third_party/blink/renderer/core/style/style_ua_shadow_host_data.h"
#include "third_party/blink/renderer/core/style/style_view_transition_group.h"
#include "third_party/blink/renderer/core/style/style_view_transition_name.h"
#include "third_party/blink/renderer/core/style/svg_dash_array.h"
#include "third_party/blink/renderer/core/style/svg_paint.h"
#include "third_party/blink/renderer/core/style/text_box_edge.h"
#include "third_party/blink/renderer/core/style/text_decoration_thickness.h"
#include "third_party/blink/renderer/core/style/text_size_adjust.h"
#include "third_party/blink/renderer/core/style/transform_origin.h"
#include "third_party/blink/renderer/core/style/unzoomed_length.h"
#include "third_party/blink/renderer/platform/fonts/font.h"
#include "third_party/blink/renderer/platform/fonts/shaping/text_spacing_trim.h"
#include "third_party/blink/renderer/platform/geometry/layout_unit.h"
#include "third_party/blink/renderer/platform/geometry/length.h"
#include "third_party/blink/renderer/platform/geometry/length_box.h"
#include "third_party/blink/renderer/platform/geometry/length_point.h"
#include "third_party/blink/renderer/platform/geometry/length_size.h"
#include "third_party/blink/renderer/platform/graphics/graphics_types.h"
#include "third_party/blink/renderer/platform/graphics/image_orientation.h"
#include "third_party/blink/renderer/platform/graphics/touch_action.h"
#include "third_party/blink/renderer/platform/heap/collection_support/heap_hash_set.h"
#include "third_party/blink/renderer/platform/heap/member.h"
#include "third_party/blink/renderer/platform/heap/persistent.h"
#include "third_party/blink/renderer/platform/text/quotes_data.h"
#include "third_party/blink/renderer/platform/text/tab_size.h"
#include "third_party/blink/renderer/platform/text/text_direction.h"
#include "third_party/blink/renderer/platform/text/unicode_bidi.h"
#include "third_party/blink/renderer/platform/text/writing_mode.h"
#include "third_party/blink/renderer/platform/theme_types.h"
#include "third_party/blink/renderer/platform/transforms/rotate_transform_operation.h"
#include "third_party/blink/renderer/platform/transforms/scale_transform_operation.h"
#include "third_party/blink/renderer/platform/transforms/transform_operations.h"
#include "third_party/blink/renderer/platform/transforms/translate_transform_operation.h"
#include "third_party/blink/renderer/platform/wtf/hash_set.h"
#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"
#include "ui/gfx/geometry/size_f.h"

namespace blink {

// Forward declaration for diff functions.
class ComputedStyle;

// Forward declaration for constructor.
class ComputedStyleBuilderBase;

// Forward declaration of friends:
namespace css_longhand {
class Position;
}
namespace css_longhand {
class Appearance;
}
namespace css_longhand {
class Color;
}
namespace css_longhand {
class InternalVisitedColor;
}
namespace css_longhand {
class AccentColor;
}
namespace css_longhand {
class BackdropFilter;
}
namespace css_longhand {
class BackgroundColor;
}
namespace css_longhand {
class BorderBottomColor;
}
namespace css_longhand {
class BorderBottomWidth;
}
namespace css_longhand {
class BorderLeftColor;
}
namespace css_longhand {
class BorderLeftWidth;
}
namespace css_longhand {
class BorderRightColor;
}
namespace css_longhand {
class BorderRightWidth;
}
namespace css_longhand {
class BorderTopColor;
}
namespace css_longhand {
class BorderTopWidth;
}
namespace css_longhand {
class CaretColor;
}
namespace css_longhand {
class Clear;
}
namespace css_longhand {
class Clip;
}
namespace css_longhand {
class ClipPath;
}
namespace css_longhand {
class ColumnCount;
}
namespace css_longhand {
class ColumnRuleWidth;
}
namespace css_longhand {
class ColumnWidth;
}
namespace css_longhand {
class Content;
}
namespace css_longhand {
class Filter;
}
namespace css_longhand {
class Float;
}
namespace css_longhand {
class GridAutoFlow;
}
namespace css_longhand {
class InternalForcedBackgroundColor;
}
namespace css_longhand {
class InternalForcedBorderColor;
}
namespace css_longhand {
class InternalForcedColor;
}
namespace css_longhand {
class InternalForcedOutlineColor;
}
namespace css_longhand {
class InternalForcedVisitedColor;
}
namespace css_longhand {
class InternalVisitedBackgroundColor;
}
namespace css_longhand {
class InternalVisitedBorderBottomColor;
}
namespace css_longhand {
class InternalVisitedBorderLeftColor;
}
namespace css_longhand {
class InternalVisitedBorderRightColor;
}
namespace css_longhand {
class InternalVisitedBorderTopColor;
}
namespace css_longhand {
class InternalVisitedCaretColor;
}
namespace css_longhand {
class InternalVisitedOutlineColor;
}
namespace css_longhand {
class InternalVisitedTextDecorationColor;
}
namespace css_longhand {
class InternalVisitedTextEmphasisColor;
}
namespace css_longhand {
class InternalVisitedTextFillColor;
}
namespace css_longhand {
class InternalVisitedTextStrokeColor;
}
namespace css_longhand {
class LineClamp;
}
namespace css_longhand {
class LineHeight;
}
namespace css_longhand {
class MarginBottom;
}
namespace css_longhand {
class MarginLeft;
}
namespace css_longhand {
class MarginRight;
}
namespace css_longhand {
class MarginTop;
}
namespace css_longhand {
class Opacity;
}
namespace css_longhand {
class Orphans;
}
namespace css_longhand {
class OutlineColor;
}
namespace css_longhand {
class OutlineWidth;
}
namespace css_longhand {
class PaddingBottom;
}
namespace css_longhand {
class PaddingLeft;
}
namespace css_longhand {
class PaddingRight;
}
namespace css_longhand {
class PaddingTop;
}
namespace css_longhand {
class PointerEvents;
}
namespace css_longhand {
class Resize;
}
namespace css_longhand {
class ShapeImageThreshold;
}
namespace css_longhand {
class ShapeOutside;
}
namespace css_longhand {
class StopColor;
}
namespace css_longhand {
class TabSize;
}
namespace css_longhand {
class TextDecorationColor;
}
namespace css_longhand {
class TextEmphasisColor;
}
namespace css_longhand {
class UserSelect;
}
namespace css_longhand {
class WebkitBoxDirection;
}
namespace css_longhand {
class WebkitBoxOrdinalGroup;
}
namespace css_longhand {
class WebkitTextFillColor;
}
namespace css_longhand {
class WebkitTextStrokeColor;
}
namespace css_longhand {
class WebkitUserModify;
}
namespace css_longhand {
class Widows;
}
namespace css_longhand {
class ZIndex;
}

// The generated portion of ComputedStyle. For more info, see the header comment
// in computed_style.h.
//
// ComputedStyleBase is a generated class that stores data members or 'fields'
// used in ComputedStyle. These fields can represent CSS properties or internal
// style information.
//
// STORAGE:
//
// Fields are organised in a tree structure, where a node (called a 'group')
// stores a set of fields and a set of pointers to child nodes (called
// 'subgroups'). We can visualise the tree structure with ComputedStyleBase as
// the root node:
//
// ComputedStyleBase (fields: display, vertical-align, ...)
//  |- StyleSurroundData (fields: border-color, left/right/top/bottom, ...)
//  |- StyleBoxData (fields: width, height, padding, ...)
//  |- ...
//  |- StyleRareNonInheritedData (fields: box-shadow, text-overflow, ...)
//      |- StyleFlexibleBoxData (fields: flex-direction, flex-wrap, ...)
//      |- ...
//
// This design saves memory by allowing multiple ComputedStyleBases to share the
// same instance of a subgroup. For example, if a page never uses flex box
// properties, then every ComputedStyleBase can share the same instance of
// StyleFlexibleBoxData. Without this sharing, we would need to allocate a copy
// of all the flex box fields for every ComputedStyleBase. Similarly, when an
// element inherits from its parent, its ComputedStyleBase can simply share all
// of its subgroups with the parent's.
//
// Most of these groupings are done manually, although there have been some
// adjustments based on statistics.
//
// INTERFACE:
//
// The functions generated for a field is determined by its 'template'. For
// example, a field with the 'keyword' template has only one setter, whereas an
// 'external' field has an extra setter that takes an rvalue reference. A list
// of the available templates can be found in css_properties.json5.
class ComputedStyleBase : public GarbageCollected<ComputedStyleBase> {
    // Properties with protected accessors must be friends because
    // Longhand::Apply* functions typically need the "raw" computed value:
    friend class css_longhand::Position;
    friend class css_longhand::Appearance;
    friend class css_longhand::Color;
    friend class css_longhand::InternalVisitedColor;
    friend class css_longhand::AccentColor;
    friend class css_longhand::BackdropFilter;
    friend class css_longhand::BackgroundColor;
    friend class css_longhand::BorderBottomColor;
    friend class css_longhand::BorderBottomWidth;
    friend class css_longhand::BorderLeftColor;
    friend class css_longhand::BorderLeftWidth;
    friend class css_longhand::BorderRightColor;
    friend class css_longhand::BorderRightWidth;
    friend class css_longhand::BorderTopColor;
    friend class css_longhand::BorderTopWidth;
    friend class css_longhand::CaretColor;
    friend class css_longhand::Clear;
    friend class css_longhand::Clip;
    friend class css_longhand::ClipPath;
    friend class css_longhand::ColumnCount;
    friend class css_longhand::ColumnRuleWidth;
    friend class css_longhand::ColumnWidth;
    friend class css_longhand::Content;
    friend class css_longhand::Filter;
    friend class css_longhand::Float;
    friend class css_longhand::GridAutoFlow;
    friend class css_longhand::InternalForcedBackgroundColor;
    friend class css_longhand::InternalForcedBorderColor;
    friend class css_longhand::InternalForcedColor;
    friend class css_longhand::InternalForcedOutlineColor;
    friend class css_longhand::InternalForcedVisitedColor;
    friend class css_longhand::InternalVisitedBackgroundColor;
    friend class css_longhand::InternalVisitedBorderBottomColor;
    friend class css_longhand::InternalVisitedBorderLeftColor;
    friend class css_longhand::InternalVisitedBorderRightColor;
    friend class css_longhand::InternalVisitedBorderTopColor;
    friend class css_longhand::InternalVisitedCaretColor;
    friend class css_longhand::InternalVisitedOutlineColor;
    friend class css_longhand::InternalVisitedTextDecorationColor;
    friend class css_longhand::InternalVisitedTextEmphasisColor;
    friend class css_longhand::InternalVisitedTextFillColor;
    friend class css_longhand::InternalVisitedTextStrokeColor;
    friend class css_longhand::LineClamp;
    friend class css_longhand::LineHeight;
    friend class css_longhand::MarginBottom;
    friend class css_longhand::MarginLeft;
    friend class css_longhand::MarginRight;
    friend class css_longhand::MarginTop;
    friend class css_longhand::Opacity;
    friend class css_longhand::Orphans;
    friend class css_longhand::OutlineColor;
    friend class css_longhand::OutlineWidth;
    friend class css_longhand::PaddingBottom;
    friend class css_longhand::PaddingLeft;
    friend class css_longhand::PaddingRight;
    friend class css_longhand::PaddingTop;
    friend class css_longhand::PointerEvents;
    friend class css_longhand::Resize;
    friend class css_longhand::ShapeImageThreshold;
    friend class css_longhand::ShapeOutside;
    friend class css_longhand::StopColor;
    friend class css_longhand::TabSize;
    friend class css_longhand::TextDecorationColor;
    friend class css_longhand::TextEmphasisColor;
    friend class css_longhand::UserSelect;
    friend class css_longhand::WebkitBoxDirection;
    friend class css_longhand::WebkitBoxOrdinalGroup;
    friend class css_longhand::WebkitTextFillColor;
    friend class css_longhand::WebkitTextStrokeColor;
    friend class css_longhand::WebkitUserModify;
    friend class css_longhand::Widows;
    friend class css_longhand::ZIndex;

public:
    inline bool IndependentInheritedEqual(const ComputedStyleBase& o) const
    {
        return ((inherited_data_.Get() == o.inherited_data_.Get() || (inherited_data_->color_ == o.inherited_data_->color_))
            && data_.pointer_events_ == o.data_.pointer_events_ && data_.text_transform_ == o.data_.text_transform_ && data_.visibility_ == o.data_.visibility_
            && data_.border_collapse_ == o.data_.border_collapse_ && data_.caption_side_ == o.data_.caption_side_ && data_.empty_cells_ == o.data_.empty_cells_
            && data_.is_html_inert_ == o.data_.is_html_inert_ && data_.list_style_position_ == o.data_.list_style_position_
            && data_.rtl_ordering_ == o.data_.rtl_ordering_

        );
    }

    inline bool NonIndependentInheritedEqual(const ComputedStyleBase& o) const
    {
        return (base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_, o.rare_inherited_usage_less_than_64_percent_data_)
            && (inherited_data_.Get() == o.inherited_data_.Get()
                || (inherited_data_->line_height_ == o.inherited_data_->line_height_
                    && inherited_data_->text_autosizing_multiplier_ == o.inherited_data_->text_autosizing_multiplier_
                    && inherited_data_->internal_visited_color_ == o.inherited_data_->internal_visited_color_
                    && inherited_data_->horizontal_border_spacing_ == o.inherited_data_->horizontal_border_spacing_
                    && inherited_data_->vertical_border_spacing_ == o.inherited_data_->vertical_border_spacing_
                    && inherited_data_->color_is_current_color_ == o.inherited_data_->color_is_current_color_
                    && inherited_data_->in_forced_colors_mode_ == o.inherited_data_->in_forced_colors_mode_
                    && inherited_data_->internal_visited_color_is_current_color_ == o.inherited_data_->internal_visited_color_is_current_color_))
            && (svg_data_.Get() == o.svg_data_.Get()
                || (base::ValuesEquivalent(svg_data_->fill_data_, o.svg_data_->fill_data_)
                    && base::ValuesEquivalent(svg_data_->stroke_data_, o.svg_data_->stroke_data_)
                    && base::ValuesEquivalent(svg_data_->inherited_resources_data_, o.svg_data_->inherited_resources_data_)
                    && svg_data_->css_dominant_baseline_ == o.svg_data_->css_dominant_baseline_
                    && svg_data_->dominant_baseline_ == o.svg_data_->dominant_baseline_ && svg_data_->paint_order_ == o.svg_data_->paint_order_
                    && svg_data_->color_interpolation_ == o.svg_data_->color_interpolation_
                    && svg_data_->color_interpolation_filters_ == o.svg_data_->color_interpolation_filters_
                    && svg_data_->color_rendering_ == o.svg_data_->color_rendering_ && svg_data_->shape_rendering_ == o.svg_data_->shape_rendering_
                    && svg_data_->text_anchor_ == o.svg_data_->text_anchor_ && svg_data_->clip_rule_ == o.svg_data_->clip_rule_
                    && svg_data_->fill_rule_ == o.svg_data_->fill_rule_))
            && base::ValuesEquivalent(font_data_, o.font_data_) && data_.cursor_ == o.data_.cursor_ && data_.text_align_ == o.data_.text_align_
            && data_.writing_mode_ == o.data_.writing_mode_ && data_.inside_link_ == o.data_.inside_link_ && data_.text_wrap_style_ == o.data_.text_wrap_style_
            && data_.white_space_collapse_ == o.data_.white_space_collapse_ && data_.caret_animation_ == o.data_.caret_animation_
            && data_.direction_ == o.data_.direction_ && data_.prefers_default_scrollbar_styles_ == o.data_.prefers_default_scrollbar_styles_
            && data_.print_color_adjust_ == o.data_.print_color_adjust_ && data_.text_wrap_mode_ == o.data_.text_wrap_mode_

        );
    }

    inline bool InheritedVariablesEqual(const ComputedStyleBase& o) const
    {
        return ((inherited_data_.Get() == o.inherited_data_.Get()
            || (base::ValuesEquivalent(inherited_data_->inherited_variables_, o.inherited_data_->inherited_variables_)))

        );
    }

    inline bool InheritedEqual(const ComputedStyleBase& o) const
    {
        return IndependentInheritedEqual(o) && NonIndependentInheritedEqual(o);
    }

    inline bool NonInheritedEqual(const ComputedStyleBase& o) const
    {
        return (base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_, o.rare_non_inherited_usage_less_than_14_percent_data_)
            && base::ValuesEquivalent(visual_data_, o.visual_data_)
            && (svg_data_.Get() == o.svg_data_.Get()
                || (base::ValuesEquivalent(svg_data_->misc_data_, o.svg_data_->misc_data_)
                    && base::ValuesEquivalent(svg_data_->geometry_data_, o.svg_data_->geometry_data_)
                    && base::ValuesEquivalent(svg_data_->stop_data_, o.svg_data_->stop_data_) && svg_data_->transform_origin_ == o.svg_data_->transform_origin_
                    && svg_data_->alignment_baseline_ == o.svg_data_->alignment_baseline_ && svg_data_->buffered_rendering_ == o.svg_data_->buffered_rendering_
                    && svg_data_->mask_type_ == o.svg_data_->mask_type_ && svg_data_->vector_effect_ == o.svg_data_->vector_effect_))
            && base::ValuesEquivalent(surround_data_, o.surround_data_) && base::ValuesEquivalent(background_data_, o.background_data_)
            && base::ValuesEquivalent(box_data_, o.box_data_) && data_.display_ == o.data_.display_ && data_.scrollbar_gutter_ == o.data_.scrollbar_gutter_
            && data_.vertical_align_ == o.data_.vertical_align_ && data_.clear_ == o.data_.clear_ && data_.floating_ == o.data_.floating_
            && data_.content_visibility_ == o.data_.content_visibility_ && data_.overflow_x_ == o.data_.overflow_x_ && data_.overflow_y_ == o.data_.overflow_y_
            && data_.position_ == o.data_.position_ && data_.transform_box_ == o.data_.transform_box_ && data_.unicode_bidi_ == o.data_.unicode_bidi_
            && IsStackingContextWithoutContainment() == o.IsStackingContextWithoutContainment() && data_.overflow_anchor_ == o.data_.overflow_anchor_
            && data_.viewport_unit_flags_ == o.data_.viewport_unit_flags_ && data_.box_direction_ == o.data_.box_direction_
            && data_.box_sizing_ == o.data_.box_sizing_ && data_.has_author_background_ == o.data_.has_author_background_
            && data_.has_author_border_ == o.data_.has_author_border_ && data_.has_author_border_radius_ == o.data_.has_author_border_radius_
            && data_.has_author_highlight_colors_ == o.data_.has_author_highlight_colors_
            && data_.has_explicit_inheritance_ == o.data_.has_explicit_inheritance_
            && data_.is_original_display_inline_type_ == o.data_.is_original_display_inline_type_ && data_.is_page_margin_box_ == o.data_.is_page_margin_box_
            && data_.is_specified_display_webkit_box_ == o.data_.is_specified_display_webkit_box_
            && data_.origin_trial_test_property_ == o.data_.origin_trial_test_property_ && data_.scroll_snap_stop_ == o.data_.scroll_snap_stop_
            && data_.should_ignore_overflow_property_for_inline_block_baseline_ == o.data_.should_ignore_overflow_property_for_inline_block_baseline_
            && data_.skips_contents_ == o.data_.skips_contents_ && data_.table_layout_ == o.data_.table_layout_

        );
    }

    inline bool InheritedDataShared(const ComputedStyleBase& o) const
    {
        return (base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_.Get(), o.rare_inherited_usage_less_than_64_percent_data_.Get())
            && base::ValuesEquivalent(inherited_data_.Get(), o.inherited_data_.Get())
            && (base::ValuesEquivalent(svg_data_.Get(), o.svg_data_.Get())
                || (base::ValuesEquivalent(svg_data_->fill_data_.Get(), o.svg_data_->fill_data_.Get())
                    && base::ValuesEquivalent(svg_data_->stroke_data_.Get(), o.svg_data_->stroke_data_.Get())
                    && base::ValuesEquivalent(svg_data_->inherited_resources_data_.Get(), o.svg_data_->inherited_resources_data_.Get())
                    && svg_data_->css_dominant_baseline_ == o.svg_data_->css_dominant_baseline_
                    && svg_data_->dominant_baseline_ == o.svg_data_->dominant_baseline_ && svg_data_->paint_order_ == o.svg_data_->paint_order_
                    && svg_data_->color_interpolation_ == o.svg_data_->color_interpolation_
                    && svg_data_->color_interpolation_filters_ == o.svg_data_->color_interpolation_filters_
                    && svg_data_->color_rendering_ == o.svg_data_->color_rendering_ && svg_data_->shape_rendering_ == o.svg_data_->shape_rendering_
                    && svg_data_->text_anchor_ == o.svg_data_->text_anchor_ && svg_data_->clip_rule_ == o.svg_data_->clip_rule_
                    && svg_data_->fill_rule_ == o.svg_data_->fill_rule_))
            && base::ValuesEquivalent(font_data_.Get(), o.font_data_.Get()) && data_.cursor_ == o.data_.cursor_
            && data_.pointer_events_ == o.data_.pointer_events_ && data_.text_align_ == o.data_.text_align_ && data_.text_transform_ == o.data_.text_transform_
            && data_.writing_mode_ == o.data_.writing_mode_ && data_.inside_link_ == o.data_.inside_link_ && data_.text_wrap_style_ == o.data_.text_wrap_style_
            && data_.visibility_ == o.data_.visibility_ && data_.white_space_collapse_ == o.data_.white_space_collapse_
            && data_.border_collapse_ == o.data_.border_collapse_ && data_.caption_side_ == o.data_.caption_side_
            && data_.caret_animation_ == o.data_.caret_animation_ && data_.color_scheme_flags_is_normal_ == o.data_.color_scheme_flags_is_normal_
            && data_.color_scheme_forced_ == o.data_.color_scheme_forced_ && data_.dark_color_scheme_ == o.data_.dark_color_scheme_
            && data_.direction_ == o.data_.direction_ && data_.empty_cells_ == o.data_.empty_cells_
            && data_.is_ensured_outside_flat_tree_ == o.data_.is_ensured_outside_flat_tree_ && data_.is_html_inert_ == o.data_.is_html_inert_
            && data_.is_inside_list_element_ == o.data_.is_inside_list_element_ && data_.list_style_position_ == o.data_.list_style_position_
            && data_.prefers_default_scrollbar_styles_ == o.data_.prefers_default_scrollbar_styles_ && data_.print_color_adjust_ == o.data_.print_color_adjust_
            && data_.rtl_ordering_ == o.data_.rtl_ordering_ && data_.text_wrap_mode_ == o.data_.text_wrap_mode_

        );
    }

    // Fields.
    // TODO(sashab): Remove initialFoo() static methods and update callers to
    // use resetFoo(), which can be more efficient.

    // accent-color

    // AffectedByActive
    bool AffectedByActive() const
    {
        return static_cast<bool>(data_.affected_by_active_);
    }

    // AffectedByCSSFunction
    bool AffectedByCSSFunction() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->affected_by_css_function_);
    }

    // AffectedByDrag
    bool AffectedByDrag() const
    {
        return static_cast<bool>(data_.affected_by_drag_);
    }

    // AffectedByFocusWithin
    bool AffectedByFocusWithin() const
    {
        return static_cast<bool>(data_.affected_by_focus_within_);
    }

    // AffectedByHover
    bool AffectedByHover() const
    {
        return static_cast<bool>(data_.affected_by_hover_);
    }

    // align-content
    const StyleContentAlignmentData& AlignContent() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_;
    }

    // -internal-align-content-block
    bool AlignContentBlockCenter() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->align_content_block_center_);
    }

    // align-items
    const StyleSelfAlignmentData& AlignItems() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->align_items_;
    }

    // align-self
    const StyleSelfAlignmentData& AlignSelf() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_;
    }

    // alignment-baseline
    EAlignmentBaseline AlignmentBaseline() const
    {
        return static_cast<EAlignmentBaseline>(svg_data_->alignment_baseline_);
    }

    // AnchorCenterOffset
    const std::optional<PhysicalOffset>& AnchorCenterOffset() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_center_offset_;
    }

    // anchor-name
    const Member<ScopedCSSNameList>& AnchorName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_;
    }

    // anchor-scope
    const StyleAnchorScope& AnchorScope() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scope_;
    }

    // Animations

    // appearance

    // aspect-ratio
    const StyleAspectRatio& AspectRatio() const
    {
        return surround_data_->aspect_ratio_;
    }

    // backdrop-filter
    const FilterOperations& BackdropFilter() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->backdrop_filter_;
    }

    // backface-visibility
    EBackfaceVisibility BackfaceVisibility() const
    {
        return static_cast<EBackfaceVisibility>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->backface_visibility_);
    }

    // Background

    // background-color

    // BaseData
    StyleBaseData* BaseData() const
    {
        return base_data_.Get();
    }

    // BaseTextDecorationData

    // baseline-shift
    const Length& BaselineShift() const
    {
        return svg_data_->misc_data_->baseline_shift_;
    }

    // BaselineShiftType
    EBaselineShiftType BaselineShiftType() const
    {
        return static_cast<EBaselineShiftType>(svg_data_->misc_data_->baseline_shift_type_);
    }

    // baseline-source
    EBaselineSource BaselineSource() const
    {
        return static_cast<EBaselineSource>(box_data_->baseline_source_);
    }

    // mix-blend-mode
    BlendMode GetBlendMode() const
    {
        return static_cast<BlendMode>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                          ->rare_non_inherited_usage_less_than_100_percent_data_->blend_mode_);
    }

    // border-bottom-color

    // border-bottom-left-radius
    const LengthSize& BorderBottomLeftRadius() const
    {
        return surround_data_->border_bottom_left_radius_;
    }

    // border-bottom-right-radius
    const LengthSize& BorderBottomRightRadius() const
    {
        return surround_data_->border_bottom_right_radius_;
    }

    // border-bottom-style
    EBorderStyle BorderBottomStyle() const
    {
        return static_cast<EBorderStyle>(box_data_->border_bottom_style_);
    }

    // border-bottom-width

    // border-collapse
    EBorderCollapse BorderCollapse() const
    {
        return static_cast<EBorderCollapse>(data_.border_collapse_);
    }

    // border-collapse
    bool BorderCollapseIsInherited() const
    {
        return static_cast<bool>(data_.border_collapse_is_inherited_);
    }

    // border-image
    const NinePieceImage& BorderImage() const
    {
        return surround_data_->border_image_;
    }

    // border-left-color

    // border-left-style
    EBorderStyle BorderLeftStyle() const
    {
        return static_cast<EBorderStyle>(box_data_->border_left_style_);
    }

    // border-left-width

    // border-right-color

    // border-right-style
    EBorderStyle BorderRightStyle() const
    {
        return static_cast<EBorderStyle>(box_data_->border_right_style_);
    }

    // border-right-width

    // border-top-color

    // border-top-left-radius
    const LengthSize& BorderTopLeftRadius() const
    {
        return surround_data_->border_top_left_radius_;
    }

    // border-top-right-radius
    const LengthSize& BorderTopRightRadius() const
    {
        return surround_data_->border_top_right_radius_;
    }

    // border-top-style
    EBorderStyle BorderTopStyle() const
    {
        return static_cast<EBorderStyle>(box_data_->border_top_style_);
    }

    // border-top-width

    // bottom
    const Length& Bottom() const
    {
        return surround_data_->bottom_;
    }

    // -webkit-box-align
    EBoxAlignment BoxAlign() const
    {
        return static_cast<EBoxAlignment>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_align_);
    }

    // box-decoration-break
    EBoxDecorationBreak BoxDecorationBreak() const
    {
        return static_cast<EBoxDecorationBreak>(box_data_->box_decoration_break_);
    }

    // -webkit-box-direction

    // -webkit-box-flex
    float BoxFlex() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_flex_;
    }

    // -webkit-box-ordinal-group
    unsigned BoxOrdinalGroup() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->box_ordinal_group_;
    }

    // -webkit-box-orient
    EBoxOrient BoxOrient() const
    {
        return static_cast<EBoxOrient>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_orient_);
    }

    // -webkit-box-pack
    EBoxPack BoxPack() const
    {
        return static_cast<EBoxPack>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_pack_);
    }

    // -webkit-box-reflect
    StyleReflection* BoxReflect() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->box_reflect_.get();
    }

    // box-shadow
    ShadowList* BoxShadow() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->box_shadow_.Get();
    }

    // box-sizing
    EBoxSizing BoxSizing() const
    {
        return static_cast<EBoxSizing>(data_.box_sizing_);
    }

    // break-after
    EBreakBetween BreakAfter() const
    {
        return static_cast<EBreakBetween>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                              ->rare_non_inherited_usage_less_than_100_percent_data_->break_after_);
    }

    // break-before
    EBreakBetween BreakBefore() const
    {
        return static_cast<EBreakBetween>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                              ->rare_non_inherited_usage_less_than_100_percent_data_->break_before_);
    }

    // break-inside
    EBreakInside BreakInside() const
    {
        return static_cast<EBreakInside>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                             ->rare_non_inherited_usage_less_than_100_percent_data_->break_inside_);
    }

    // buffered-rendering
    EBufferedRendering BufferedRendering() const
    {
        return static_cast<EBufferedRendering>(svg_data_->buffered_rendering_);
    }

    // CallbackSelectors
    const Vector<String>& CallbackSelectors() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->callback_selectors_;
    }

    // CanAffectAnimations
    bool CanAffectAnimations() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->can_affect_animations_);
    }

    // stroke-linecap
    LineCap CapStyle() const
    {
        return static_cast<LineCap>(svg_data_->stroke_data_->cap_style_);
    }

    // caption-side
    ECaptionSide CaptionSide() const
    {
        return static_cast<ECaptionSide>(data_.caption_side_);
    }

    // caption-side
    bool CaptionSideIsInherited() const
    {
        return static_cast<bool>(data_.caption_side_is_inherited_);
    }

    // caret-animation
    ECaretAnimation CaretAnimation() const
    {
        return static_cast<ECaretAnimation>(data_.caret_animation_);
    }

    // caret-color

    // ChildHasExplicitInheritance
    bool ChildHasExplicitInheritance() const
    {
        return static_cast<bool>(data_.child_has_explicit_inheritance_);
    }

    void SetChildHasExplicitInheritance() const
    {
        data_.child_has_explicit_inheritance_ = static_cast<unsigned>(true);
    }

    // clear

    // clip
    const LengthBox& Clip() const
    {
        return visual_data_->clip_;
    }

    // clip-path

    // clip-rule
    WindRule ClipRule() const
    {
        return static_cast<WindRule>(svg_data_->clip_rule_);
    }

    // color

    // color-interpolation
    EColorInterpolation ColorInterpolation() const
    {
        return static_cast<EColorInterpolation>(svg_data_->color_interpolation_);
    }

    // color-interpolation-filters
    EColorInterpolation ColorInterpolationFilters() const
    {
        return static_cast<EColorInterpolation>(svg_data_->color_interpolation_filters_);
    }

    // ColorIsCurrentColor

    // color

    // color-rendering
    EColorRendering ColorRendering() const
    {
        return static_cast<EColorRendering>(svg_data_->color_rendering_);
    }

    // color-scheme
    const Vector<AtomicString>& ColorScheme() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->color_scheme_;
    }

    // ColorSchemeFlagsIsNormal
    bool ColorSchemeFlagsIsNormal() const
    {
        return static_cast<bool>(data_.color_scheme_flags_is_normal_);
    }

    // ColorSchemeForced
    bool ColorSchemeForced() const
    {
        return static_cast<bool>(data_.color_scheme_forced_);
    }

    // column-count
    unsigned short ColumnCount() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->column_count_;
    }

    // column-fill
    EColumnFill GetColumnFill() const
    {
        return static_cast<EColumnFill>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->column_fill_);
    }

    // column-gap
    const std::optional<Length>& ColumnGap() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->column_gap_;
    }

    // column-rule-color
    const GapDataList<StyleColor>& ColumnRuleColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_color_;
    }

    // column-rule-style
    EBorderStyle ColumnRuleStyle() const
    {
        return static_cast<EBorderStyle>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                             ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_style_);
    }

    // column-rule-width

    // column-span
    EColumnSpan GetColumnSpan() const
    {
        return static_cast<EColumnSpan>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->column_span_);
    }

    // column-width
    float ColumnWidth() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->column_width_;
    }

    // contain
    unsigned Contain() const
    {
        return static_cast<unsigned>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                         ->rare_non_inherited_usage_less_than_100_percent_data_->contain_);
    }

    // contain-intrinsic-height
    const StyleIntrinsicLength& ContainIntrinsicHeight() const
    {
        return surround_data_->contain_intrinsic_height_;
    }

    // contain-intrinsic-width
    const StyleIntrinsicLength& ContainIntrinsicWidth() const
    {
        return surround_data_->contain_intrinsic_width_;
    }

    // container-name
    const Member<ScopedCSSNameList>& ContainerName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_name_;
    }

    // container-type
    unsigned ContainerType() const
    {
        return static_cast<unsigned>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_type_);
    }

    // content

    // content-visibility
    EContentVisibility ContentVisibility() const
    {
        return static_cast<EContentVisibility>(data_.content_visibility_);
    }

    // CounterDirectives

    // CssDominantBaseline
    EDominantBaseline CssDominantBaseline() const
    {
        return static_cast<EDominantBaseline>(svg_data_->css_dominant_baseline_);
    }

    // cursor
    ECursor Cursor() const
    {
        return static_cast<ECursor>(data_.cursor_);
    }

    // CursorData

    // CustomHighlightNames

    // CustomStyleCallbackDependsOnFont
    bool CustomStyleCallbackDependsOnFont() const
    {
        return static_cast<bool>(data_.custom_style_callback_depends_on_font_);
    }

    // cx
    const Length& Cx() const
    {
        return svg_data_->geometry_data_->cx_;
    }

    // cy
    const Length& Cy() const
    {
        return svg_data_->geometry_data_->cy_;
    }

    // d
    StylePath* D() const
    {
        return svg_data_->geometry_data_->d_.get();
    }

    // DarkColorScheme
    bool DarkColorScheme() const
    {
        return static_cast<bool>(data_.dark_color_scheme_);
    }

    // DependsOnScrollStateContainerQueries
    bool DependsOnScrollStateContainerQueries() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->depends_on_scroll_state_container_queries_);
    }

    // DependsOnSizeContainerQueries
    bool DependsOnSizeContainerQueries() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_size_container_queries_);
    }

    // DependsOnStyleContainerQueries
    bool DependsOnStyleContainerQueries() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_style_container_queries_);
    }

    // direction
    TextDirection Direction() const
    {
        return static_cast<TextDirection>(data_.direction_);
    }

    // Display
    EDisplay Display() const
    {
        return static_cast<EDisplay>(data_.display_);
    }

    // DisplayLayoutCustomName
    const AtomicString& DisplayLayoutCustomName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_name_;
    }

    // DisplayLayoutCustomParentName
    const AtomicString& DisplayLayoutCustomParentName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_parent_name_;
    }

    // DocumentRulesSelectors
    const Member<HeapHashSet<WeakMember<StyleRule>>>& DocumentRulesSelectors() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->document_rules_selectors_;
    }

    // dominant-baseline
    EDominantBaseline DominantBaseline() const
    {
        return static_cast<EDominantBaseline>(svg_data_->dominant_baseline_);
    }

    // app-region
    EDraggableRegionMode DraggableRegionMode() const
    {
        return static_cast<EDraggableRegionMode>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                     ->rare_non_inherited_usage_less_than_100_percent_data_->draggable_region_mode_);
    }

    // dynamic-range-limit
    const DynamicRangeLimit& GetDynamicRangeLimit() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->dynamic_range_limit_;
    }

    // EffectiveAppearance
    ControlPart EffectiveAppearance() const
    {
        return static_cast<ControlPart>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_appearance_);
    }

    // EffectiveTouchAction
    TouchAction EffectiveTouchAction() const
    {
        return static_cast<TouchAction>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_touch_action_);
    }

    // EffectiveZIndexZero
    bool EffectiveZIndexZero() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_z_index_zero_);
    }

    // EffectiveZoom
    float EffectiveZoom() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_zoom_;
    }

    // ElementIsViewTransitionParticipant
    bool ElementIsViewTransitionParticipant() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->element_is_view_transition_participant_);
    }

    // empty-cells
    EEmptyCells EmptyCells() const
    {
        return static_cast<EEmptyCells>(data_.empty_cells_);
    }

    // empty-cells
    bool EmptyCellsIsInherited() const
    {
        return static_cast<bool>(data_.empty_cells_is_inherited_);
    }

    // field-sizing
    EFieldSizing FieldSizing() const
    {
        return static_cast<EFieldSizing>(visual_data_->field_sizing_);
    }

    // fill-opacity
    float FillOpacity() const
    {
        return svg_data_->fill_data_->fill_opacity_;
    }

    // fill
    const SVGPaint& FillPaint() const
    {
        return svg_data_->fill_data_->fill_paint_;
    }

    // fill-rule
    WindRule FillRule() const
    {
        return static_cast<WindRule>(svg_data_->fill_rule_);
    }

    // filter
    const FilterOperations& Filter() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->filter_;
    }

    // FirstLineDependsOnSizeContainerQueries
    bool FirstLineDependsOnSizeContainerQueries() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->first_line_depends_on_size_container_queries_);
    }

    // flex-basis
    const Length& FlexBasis() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_;
    }

    // flex-direction
    EFlexDirection FlexDirection() const
    {
        return static_cast<EFlexDirection>(rare_non_inherited_usage_less_than_14_percent_data_->flex_direction_);
    }

    // flex-grow
    float FlexGrow() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_grow_;
    }

    // flex-shrink
    float FlexShrink() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_shrink_;
    }

    // flex-wrap
    EFlexWrap FlexWrap() const
    {
        return static_cast<EFlexWrap>(rare_non_inherited_usage_less_than_14_percent_data_->flex_wrap_);
    }

    // float

    // flood-color
    const StyleColor& FloodColor() const
    {
        return svg_data_->misc_data_->flood_color_;
    }

    // flood-opacity
    float FloodOpacity() const
    {
        return svg_data_->misc_data_->flood_opacity_;
    }

    // font
    const Font& GetFont() const
    {
        return font_data_->font_;
    }

    // forced-color-adjust
    EForcedColorAdjust ForcedColorAdjust() const
    {
        return static_cast<EForcedColorAdjust>(rare_inherited_usage_less_than_64_percent_data_->forced_color_adjust_);
    }

    // ForcesStackingContext
    bool ForcesStackingContext() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forces_stacking_context_);
    }

    // grid-auto-columns
    const NGGridTrackList& GridAutoColumns() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_columns_;
    }

    // grid-auto-flow

    // grid-auto-rows
    const NGGridTrackList& GridAutoRows() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_rows_;
    }

    // grid-column-end
    const GridPosition& GridColumnEnd() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_end_;
    }

    // grid-column-start
    const GridPosition& GridColumnStart() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_start_;
    }

    // grid-row-end
    const GridPosition& GridRowEnd() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_end_;
    }

    // grid-row-start
    const GridPosition& GridRowStart() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_start_;
    }

    // grid-template-areas
    const Member<ComputedGridTemplateAreas>& GridTemplateAreas() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_template_areas_;
    }

    // grid-template-columns
    const ComputedGridTrackList& GridTemplateColumns() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_columns_;
    }

    // grid-template-rows
    const ComputedGridTrackList& GridTemplateRows() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_rows_;
    }

    // HasAnchorEvaluator
    bool HasAnchorEvaluator() const
    {
        return static_cast<bool>(surround_data_->has_anchor_evaluator_);
    }

    // HasAnchorFunctions
    bool HasAnchorFunctions() const
    {
        return static_cast<bool>(surround_data_->has_anchor_functions_);
    }

    // HasAttrFunction
    bool HasAttrFunction() const
    {
        return static_cast<bool>(data_.has_attr_function_);
    }

    // HasAuthorBackground
    bool HasAuthorBackground() const
    {
        return static_cast<bool>(data_.has_author_background_);
    }

    // HasAuthorBorder
    bool HasAuthorBorder() const
    {
        return static_cast<bool>(data_.has_author_border_);
    }

    // HasAuthorBorderRadius
    bool HasAuthorBorderRadius() const
    {
        return static_cast<bool>(data_.has_author_border_radius_);
    }

    // HasAuthorHighlightColors
    bool HasAuthorHighlightColors() const
    {
        return static_cast<bool>(data_.has_author_highlight_colors_);
    }

    // HasAutoClip
    bool HasAutoClip() const
    {
        return static_cast<bool>(visual_data_->has_auto_clip_);
    }

    // HasAutoColumnCount
    bool HasAutoColumnCount() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_count_);
    }

    // HasAutoColumnWidth
    bool HasAutoColumnWidth() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_width_);
    }

    // HasAutoStandardLineClamp
    bool HasAutoStandardLineClamp() const
    {
        return static_cast<bool>(box_data_->has_auto_standard_line_clamp_);
    }

    // HasAutoZIndex
    bool HasAutoZIndex() const
    {
        return static_cast<bool>(box_data_->has_auto_z_index_);
    }

    // HasClipPath
    bool HasClipPath() const
    {
        return static_cast<bool>(visual_data_->has_clip_path_);
    }

    // HasContainerRelativeUnits
    bool HasContainerRelativeUnits() const
    {
        return static_cast<bool>(data_.has_container_relative_units_);
    }

    // HasCurrentBackdropFilterAnimation
    bool HasCurrentBackdropFilterAnimation() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->has_current_backdrop_filter_animation_);
    }

    // HasCurrentBackgroundColorAnimation
    bool HasCurrentBackgroundColorAnimation() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->has_current_background_color_animation_);
    }

    // HasCurrentFilterAnimation
    bool HasCurrentFilterAnimation() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_filter_animation_);
    }

    // HasCurrentOpacityAnimation
    bool HasCurrentOpacityAnimation() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_opacity_animation_);
    }

    // HasCurrentRotateAnimation
    bool HasCurrentRotateAnimation() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_rotate_animation_);
    }

    // HasCurrentScaleAnimation
    bool HasCurrentScaleAnimation() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_scale_animation_);
    }

    // HasCurrentTransformAnimation
    bool HasCurrentTransformAnimation() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_transform_animation_);
    }

    // HasCurrentTranslateAnimation
    bool HasCurrentTranslateAnimation() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_translate_animation_);
    }

    // HasEmUnits
    bool HasEmUnits() const
    {
        return static_cast<bool>(data_.has_em_units_);
    }

    // HasEnv
    bool HasEnv() const
    {
        return static_cast<bool>(data_.has_env_);
    }

    // HasExplicitInheritance
    bool HasExplicitInheritance() const
    {
        return static_cast<bool>(data_.has_explicit_inheritance_);
    }

    // HasExplicitOverflowXVisible
    bool HasExplicitOverflowXVisible() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_x_visible_);
    }

    // HasExplicitOverflowYVisible
    bool HasExplicitOverflowYVisible() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_y_visible_);
    }

    // HasGlyphRelativeUnits
    bool HasGlyphRelativeUnits() const
    {
        return static_cast<bool>(data_.has_glyph_relative_units_);
    }

    // HasLineHeightRelativeUnits
    bool HasLineHeightRelativeUnits() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_line_height_relative_units_);
    }

    // -internal-empty-line-height
    bool HasLineIfEmpty() const
    {
        return static_cast<bool>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->has_line_if_empty_);
    }

    // HasLogicalDirectionRelativeUnits
    bool HasLogicalDirectionRelativeUnits() const
    {
        return static_cast<bool>(data_.has_logical_direction_relative_units_);
    }

    // HasNonUaHighlightPseudoStyles
    bool HasNonUaHighlightPseudoStyles() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_non_ua_highlight_pseudo_styles_);
    }

    // HasNonUniversalHighlightPseudoStyles
    bool HasNonUniversalHighlightPseudoStyles() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->has_non_universal_highlight_pseudo_styles_);
    }

    // HasRootFontRelativeUnits
    bool HasRootFontRelativeUnits() const
    {
        return static_cast<bool>(data_.has_root_font_relative_units_);
    }

    // HasVariableDeclaration
    bool HasVariableDeclaration() const
    {
        return static_cast<bool>(data_.has_variable_declaration_);
    }

    // HasVariableReference
    bool HasVariableReference() const
    {
        return static_cast<bool>(data_.has_variable_reference_);
    }

    // height
    const Length& Height() const
    {
        return box_data_->height_;
    }

    // HighlightData
    const StyleHighlightData& HighlightData() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_data_->highlight_data_;
    }

    // HighlightsDependOnSizeContainerQueries
    bool HighlightsDependOnSizeContainerQueries() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->highlights_depend_on_size_container_queries_);
    }

    // -webkit-border-horizontal-spacing
    short HorizontalBorderSpacing() const
    {
        return inherited_data_->horizontal_border_spacing_;
    }

    // hyphenate-limit-chars
    const StyleHyphenateLimitChars& HyphenateLimitChars() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_;
    }

    // hyphenate-character
    const AtomicString& HyphenationString() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_;
    }

    // hyphens
    Hyphens GetHyphens() const
    {
        return static_cast<Hyphens>(rare_inherited_usage_less_than_64_percent_data_->hyphens_);
    }

    // image-orientation
    RespectImageOrientationEnum ImageOrientation() const
    {
        return static_cast<RespectImageOrientationEnum>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->image_orientation_);
    }

    // image-rendering
    EImageRendering ImageRendering() const
    {
        return static_cast<EImageRendering>(rare_inherited_usage_less_than_64_percent_data_->image_rendering_);
    }

    // InBaseSelectAppearance
    bool InBaseSelectAppearance() const
    {
        return static_cast<bool>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->in_base_select_appearance_);
    }

    // InForcedColorsMode
    bool InForcedColorsMode() const
    {
        return static_cast<bool>(inherited_data_->in_forced_colors_mode_);
    }

    // InheritedVariables

    // InitialData
    StyleInitialData* InitialData() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->initial_data_.Get();
    }

    // initial-letter
    const StyleInitialLetter& InitialLetter() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_;
    }

    // InlineBlockBaselineEdge
    EInlineBlockBaselineEdge InlineBlockBaselineEdge() const
    {
        return static_cast<EInlineBlockBaselineEdge>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->inline_block_baseline_edge_);
    }

    // InlineStyleLostCascade
    bool InlineStyleLostCascade() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->inline_style_lost_cascade_);
    }

    // InsideLink
    EInsideLink InsideLink() const
    {
        return static_cast<EInsideLink>(data_.inside_link_);
    }

    // interactivity
    EInteractivity Interactivity() const
    {
        return static_cast<EInteractivity>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->interactivity_);
    }

    // -internal-forced-background-color

    // -internal-forced-border-color

    // -internal-forced-color

    // -internal-forced-outline-color

    // -internal-forced-visited-color

    // -internal-visited-background-color

    // -internal-visited-border-bottom-color

    // -internal-visited-border-left-color

    // -internal-visited-border-right-color

    // -internal-visited-border-top-color

    // -internal-visited-caret-color

    // -internal-visited-color

    // InternalVisitedColorIsCurrentColor

    // -internal-visited-column-rule-color
    const GapDataList<StyleColor>& InternalVisitedColumnRuleColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_column_rule_color_;
    }

    // -internal-visited-fill
    const SVGPaint& InternalVisitedFillPaint() const
    {
        return svg_data_->fill_data_->internal_visited_fill_paint_;
    }

    // -internal-visited-outline-color

    // -internal-visited-stroke
    const SVGPaint& InternalVisitedStrokePaint() const
    {
        return svg_data_->stroke_data_->internal_visited_stroke_paint_;
    }

    // -internal-visited-text-decoration-color

    // -internal-visited-text-emphasis-color

    // -internal-visited-text-fill-color

    // -internal-visited-text-stroke-color

    // interpolate-size
    EInterpolateSize InterpolateSize() const
    {
        return static_cast<EInterpolateSize>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->interpolate_size_);
    }

    // IsEnsuredInDisplayNone
    bool IsEnsuredInDisplayNone() const
    {
        return static_cast<bool>(data_.is_ensured_in_display_none_);
    }

    // IsEnsuredOutsideFlatTree
    bool IsEnsuredOutsideFlatTree() const
    {
        return static_cast<bool>(data_.is_ensured_outside_flat_tree_);
    }

    // IsFlexOrGridOrCustomItem
    bool IsFlexOrGridOrCustomItem() const
    {
        return static_cast<bool>(data_.is_flex_or_grid_or_custom_item_);
    }

    // IsHTMLInert
    bool IsHTMLInert() const
    {
        return static_cast<bool>(data_.is_html_inert_);
    }

    // IsHTMLInert
    bool IsHTMLInertIsInherited() const
    {
        return static_cast<bool>(data_.is_html_inert_is_inherited_);
    }

    // IsInBlockifyingDisplay
    bool IsInBlockifyingDisplay() const
    {
        return static_cast<bool>(data_.is_in_blockifying_display_);
    }

    // IsInInlinifyingDisplay
    bool IsInInlinifyingDisplay() const
    {
        return static_cast<bool>(data_.is_in_inlinifying_display_);
    }

    // IsInsideDisplayIgnoringFloatingChildren
    bool IsInsideDisplayIgnoringFloatingChildren() const
    {
        return static_cast<bool>(data_.is_inside_display_ignoring_floating_children_);
    }

    // IsInsideListElement
    bool IsInsideListElement() const
    {
        return static_cast<bool>(data_.is_inside_list_element_);
    }

    // IsLink
    bool IsLink() const
    {
        return static_cast<bool>(data_.is_link_);
    }

    // IsOriginalDisplayInlineType
    bool IsOriginalDisplayInlineType() const
    {
        return static_cast<bool>(data_.is_original_display_inline_type_);
    }

    // IsPageMarginBox
    bool IsPageMarginBox() const
    {
        return static_cast<bool>(data_.is_page_margin_box_);
    }

    // IsRunningBackdropFilterAnimationOnCompositor
    bool IsRunningBackdropFilterAnimationOnCompositor() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->is_running_backdrop_filter_animation_on_compositor_);
    }

    // IsRunningFilterAnimationOnCompositor
    bool IsRunningFilterAnimationOnCompositor() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->is_running_filter_animation_on_compositor_);
    }

    // IsRunningOpacityAnimationOnCompositor
    bool IsRunningOpacityAnimationOnCompositor() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->is_running_opacity_animation_on_compositor_);
    }

    // IsRunningRotateAnimationOnCompositor
    bool IsRunningRotateAnimationOnCompositor() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->is_running_rotate_animation_on_compositor_);
    }

    // IsRunningScaleAnimationOnCompositor
    bool IsRunningScaleAnimationOnCompositor() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->is_running_scale_animation_on_compositor_);
    }

    // IsRunningTransformAnimationOnCompositor
    bool IsRunningTransformAnimationOnCompositor() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->is_running_transform_animation_on_compositor_);
    }

    // IsRunningTranslateAnimationOnCompositor
    bool IsRunningTranslateAnimationOnCompositor() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->is_running_translate_animation_on_compositor_);
    }

    // IsSecondaryBodyElement
    bool IsSecondaryBodyElement() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_secondary_body_element_);
    }

    // IsSpecifiedDisplayWebkitBox
    bool IsSpecifiedDisplayWebkitBox() const
    {
        return static_cast<bool>(data_.is_specified_display_webkit_box_);
    }

    // IsStackingContextWithoutContainment
    bool CORE_EXPORT IsStackingContextWithoutContainment() const;

    // IsStartingStyle
    bool IsStartingStyle() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_starting_style_);
    }

    // isolation
    EIsolation Isolation() const
    {
        return static_cast<EIsolation>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->isolation_);
    }

    // stroke-linejoin
    LineJoin JoinStyle() const
    {
        return static_cast<LineJoin>(svg_data_->stroke_data_->join_style_);
    }

    // justify-content
    const StyleContentAlignmentData& JustifyContent() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->justify_content_;
    }

    // justify-items
    const StyleSelfAlignmentData& JustifyItems() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->justify_items_;
    }

    // justify-self
    const StyleSelfAlignmentData& JustifySelf() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->justify_self_;
    }

    // left
    const Length& Left() const
    {
        return surround_data_->left_;
    }

    // lighting-color
    const StyleColor& LightingColor() const
    {
        return svg_data_->misc_data_->lighting_color_;
    }

    // -webkit-line-break
    LineBreak GetLineBreak() const
    {
        return static_cast<LineBreak>(rare_inherited_usage_less_than_64_percent_data_->line_break_);
    }

    // line-height

    // list-style-image
    const Member<StyleImage>& ListStyleImage() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->list_style_image_;
    }

    // list-style-position
    EListStylePosition ListStylePosition() const
    {
        return static_cast<EListStylePosition>(data_.list_style_position_);
    }

    // list-style-position
    bool ListStylePositionIsInherited() const
    {
        return static_cast<bool>(data_.list_style_position_is_inherited_);
    }

    // list-style-type
    const Member<ListStyleTypeData>& ListStyleType() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->list_style_type_;
    }

    // margin-bottom
    const Length& MarginBottom() const
    {
        return box_data_->margin_bottom_;
    }

    // margin-left
    const Length& MarginLeft() const
    {
        return box_data_->margin_left_;
    }

    // margin-right
    const Length& MarginRight() const
    {
        return box_data_->margin_right_;
    }

    // margin-top
    const Length& MarginTop() const
    {
        return box_data_->margin_top_;
    }

    // marker-end
    StyleSVGResource* MarkerEndResource() const
    {
        return svg_data_->inherited_resources_data_->marker_end_resource_.Get();
    }

    // marker-mid
    StyleSVGResource* MarkerMidResource() const
    {
        return svg_data_->inherited_resources_data_->marker_mid_resource_.Get();
    }

    // marker-start
    StyleSVGResource* MarkerStartResource() const
    {
        return svg_data_->inherited_resources_data_->marker_start_resource_.Get();
    }

    // Mask

    // MaskBoxImage

    // mask-type
    EMaskType MaskType() const
    {
        return static_cast<EMaskType>(svg_data_->mask_type_);
    }

    // masonry-slack
    const std::optional<Length>& MasonrySlack() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_slack_;
    }

    // masonry-template-tracks
    const ComputedGridTrackList& MasonryTemplateTracks() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_data_
            ->masonry_template_tracks_;
    }

    // masonry-track-end
    const GridPosition& MasonryTrackEnd() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_end_;
    }

    // masonry-track-start
    const GridPosition& MasonryTrackStart() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_start_;
    }

    // MathBaseline
    const Length& GetMathBaseline() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_baseline_;
    }

    // math-depth
    short MathDepth() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_depth_;
    }

    // MathFractionBarThickness
    const Length& GetMathFractionBarThickness() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
            ->math_fraction_bar_thickness_;
    }

    // MathLSpace
    const Length& GetMathLSpace() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_l_space_;
    }

    // MathMaxSize
    const Length& GetMathMaxSize() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_max_size_;
    }

    // MathMinSize
    const Length& GetMathMinSize() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_min_size_;
    }

    // MathPaddedDepth
    const Length& GetMathPaddedDepth() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_depth_;
    }

    // MathPaddedVOffset
    const Length& GetMathPaddedVOffset() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_v_offset_;
    }

    // MathRSpace
    const Length& GetMathRSpace() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_r_space_;
    }

    // math-shift
    EMathShift MathShift() const
    {
        return static_cast<EMathShift>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_shift_);
    }

    // math-style
    EMathStyle MathStyle() const
    {
        return static_cast<EMathStyle>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_style_);
    }

    // max-height
    const Length& MaxHeight() const
    {
        return box_data_->max_height_;
    }

    // max-width
    const Length& MaxWidth() const
    {
        return box_data_->max_width_;
    }

    // MayHaveMargin
    bool MayHaveMargin() const
    {
        return static_cast<bool>(surround_data_->may_have_margin_);
    }

    // MayHavePadding
    bool MayHavePadding() const
    {
        return static_cast<bool>(surround_data_->may_have_padding_);
    }

    // min-height
    const Length& MinHeight() const
    {
        return box_data_->min_height_;
    }

    // min-width
    const Length& MinWidth() const
    {
        return box_data_->min_width_;
    }

    // NonInheritedVariables

    // object-fit
    EObjectFit GetObjectFit() const
    {
        return static_cast<EObjectFit>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->object_fit_);
    }

    // object-position
    const LengthPoint& ObjectPosition() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->object_position_;
    }

    // object-view-box
    BasicShape* ObjectViewBox() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->object_view_box_.get();
    }

    // offset-anchor
    const LengthPoint& OffsetAnchor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_anchor_;
    }

    // offset-distance
    const Length& OffsetDistance() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_distance_;
    }

    // offset-path
    OffsetPathOperation* OffsetPath() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_path_.Get();
    }

    // offset-position
    const LengthPoint& OffsetPosition() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_position_;
    }

    // offset-rotate
    const StyleOffsetRotation& OffsetRotate() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_rotate_;
    }

    // opacity
    float Opacity() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->opacity_;
    }

    // order
    int Order() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->order_;
    }

    // origin-trial-test-property
    EOriginTrialTestProperty OriginTrialTestProperty() const
    {
        return static_cast<EOriginTrialTestProperty>(data_.origin_trial_test_property_);
    }

    // orphans
    short Orphans() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->orphans_;
    }

    // outline-color

    // outline-offset
    const LayoutUnit& OutlineOffset() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_;
    }

    // outline-style
    EBorderStyle OutlineStyle() const
    {
        return static_cast<EBorderStyle>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_style_);
    }

    // OutlineStyleIsAuto
    bool OutlineStyleIsAuto() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->outline_style_is_auto_);
    }

    // outline-width

    // overflow-anchor
    EOverflowAnchor OverflowAnchor() const
    {
        return static_cast<EOverflowAnchor>(data_.overflow_anchor_);
    }

    // overflow-clip-margin
    const std::optional<StyleOverflowClipMargin>& OverflowClipMargin() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_;
    }

    // overflow-wrap
    EOverflowWrap OverflowWrap() const
    {
        return static_cast<EOverflowWrap>(rare_inherited_usage_less_than_64_percent_data_->overflow_wrap_);
    }

    // overflow-x
    EOverflow OverflowX() const
    {
        return static_cast<EOverflow>(data_.overflow_x_);
    }

    // overflow-y
    EOverflow OverflowY() const
    {
        return static_cast<EOverflow>(data_.overflow_y_);
    }

    // overlay
    EOverlay Overlay() const
    {
        return static_cast<EOverlay>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overlay_);
    }

    // overscroll-behavior-x
    EOverscrollBehavior OverscrollBehaviorX() const
    {
        return static_cast<EOverscrollBehavior>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overscroll_behavior_x_);
    }

    // overscroll-behavior-y
    EOverscrollBehavior OverscrollBehaviorY() const
    {
        return static_cast<EOverscrollBehavior>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overscroll_behavior_y_);
    }

    // padding-bottom
    const Length& PaddingBottom() const
    {
        return box_data_->padding_bottom_;
    }

    // padding-left
    const Length& PaddingLeft() const
    {
        return box_data_->padding_left_;
    }

    // padding-right
    const Length& PaddingRight() const
    {
        return box_data_->padding_right_;
    }

    // padding-top
    const Length& PaddingTop() const
    {
        return box_data_->padding_top_;
    }

    // page
    const AtomicString& Page() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->page_;
    }

    // page-orientation
    PageOrientation GetPageOrientation() const
    {
        return static_cast<PageOrientation>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->page_orientation_);
    }

    // PageSize
    const gfx::SizeF& PageSize() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_;
    }

    // PageSizeType
    PageSizeType GetPageSizeType() const
    {
        return static_cast<PageSizeType>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_type_);
    }

    // PaintImages

    // paint-order
    EPaintOrder PaintOrder() const
    {
        return static_cast<EPaintOrder>(svg_data_->paint_order_);
    }

    // perspective
    float Perspective() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_;
    }

    // perspective-origin
    const LengthPoint& PerspectiveOrigin() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_origin_;
    }

    // pointer-events

    // pointer-events

    // popover-hide-delay
    float PopoverHideDelay() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->popover_hide_delay_;
    }

    // popover-show-delay
    float PopoverShowDelay() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->popover_show_delay_;
    }

    // position

    // position-anchor
    const Member<ScopedCSSName>& PositionAnchor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_anchor_;
    }

    // position-area
    const PositionArea& GetPositionArea() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_area_;
    }

    // PositionAreaOffsets
    const std::optional<blink::PositionAreaOffsets>& PositionAreaOffsets() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_area_offsets_;
    }

    // position-try-fallbacks
    const Member<PositionTryFallbacks>& GetPositionTryFallbacks() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_fallbacks_;
    }

    // position-try-order
    EPositionTryOrder PositionTryOrder() const
    {
        return static_cast<EPositionTryOrder>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_order_);
    }

    // position-visibility
    PositionVisibility GetPositionVisibility() const
    {
        return static_cast<PositionVisibility>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_visibility_);
    }

    // PrefersDefaultScrollbarStyles
    bool PrefersDefaultScrollbarStyles() const
    {
        return static_cast<bool>(data_.prefers_default_scrollbar_styles_);
    }

    // -webkit-print-color-adjust
    EPrintColorAdjust PrintColorAdjust() const
    {
        return static_cast<EPrintColorAdjust>(data_.print_color_adjust_);
    }

    // PseudoArgument
    const AtomicString& PseudoArgument() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->pseudo_argument_;
    }

    // PseudoElementStyles

    // quotes
    QuotesData* Quotes() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->quotes_.get();
    }

    // r
    const Length& R() const
    {
        return svg_data_->geometry_data_->r_;
    }

    // reading-flow
    EReadingFlow ReadingFlow() const
    {
        return static_cast<EReadingFlow>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->reading_flow_);
    }

    // RequiresAcceleratedCompositingForExternalReasons
    bool RequiresAcceleratedCompositingForExternalReasons() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->requires_accelerated_compositing_for_external_reasons_);
    }

    // resize

    // right
    const Length& Right() const
    {
        return surround_data_->right_;
    }

    // rotate
    RotateTransformOperation* Rotate() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->rotate_.Get();
    }

    // row-gap
    const std::optional<Length>& RowGap() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->row_gap_;
    }

    // -webkit-rtl-ordering
    EOrder RtlOrdering() const
    {
        return static_cast<EOrder>(data_.rtl_ordering_);
    }

    // -webkit-rtl-ordering
    bool RtlOrderingIsInherited() const
    {
        return static_cast<bool>(data_.rtl_ordering_is_inherited_);
    }

    // ruby-align
    ERubyAlign RubyAlign() const
    {
        return static_cast<ERubyAlign>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ruby_align_);
    }

    // ruby-position
    RubyPosition GetRubyPosition() const
    {
        return static_cast<RubyPosition>(rare_inherited_usage_less_than_64_percent_data_->ruby_position_);
    }

    // rx
    const Length& Rx() const
    {
        return svg_data_->geometry_data_->rx_;
    }

    // ry
    const Length& Ry() const
    {
        return svg_data_->geometry_data_->ry_;
    }

    // scale
    ScaleTransformOperation* Scale() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->scale_.Get();
    }

    // scroll-behavior
    mojom::blink::ScrollBehavior GetScrollBehavior() const
    {
        return static_cast<mojom::blink::ScrollBehavior>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_behavior_);
    }

    // scroll-margin-bottom
    float ScrollMarginBottom() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_bottom_;
    }

    // scroll-margin-left
    float ScrollMarginLeft() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_left_;
    }

    // scroll-margin-right
    float ScrollMarginRight() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_right_;
    }

    // scroll-margin-top
    float ScrollMarginTop() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_top_;
    }

    // scroll-marker-group
    EScrollMarkerGroup ScrollMarkerGroup() const
    {
        return static_cast<EScrollMarkerGroup>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_marker_group_);
    }

    // scroll-padding-bottom
    const Length& ScrollPaddingBottom() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_bottom_;
    }

    // scroll-padding-left
    const Length& ScrollPaddingLeft() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_left_;
    }

    // scroll-padding-right
    const Length& ScrollPaddingRight() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_right_;
    }

    // scroll-padding-top
    const Length& ScrollPaddingTop() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_top_;
    }

    // scroll-snap-align
    const cc::ScrollSnapAlign& GetScrollSnapAlign() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_align_;
    }

    // scroll-snap-stop
    EScrollSnapStop ScrollSnapStop() const
    {
        return static_cast<EScrollSnapStop>(data_.scroll_snap_stop_);
    }

    // scroll-snap-type
    const cc::ScrollSnapType& GetScrollSnapType() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_type_;
    }

    // scroll-start-target
    EScrollStartTarget ScrollStartTarget() const
    {
        return static_cast<EScrollStartTarget>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_start_target_);
    }

    // scroll-start-x
    const ScrollStartData& ScrollStartX() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_x_;
    }

    // scroll-start-y
    const ScrollStartData& ScrollStartY() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_y_;
    }

    // scroll-timeline-axis
    const Vector<TimelineAxis>& ScrollTimelineAxis() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
            ->scroll_timeline_axis_;
    }

    // scroll-timeline-name
    const Member<ScopedCSSNameList>& ScrollTimelineName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
            ->scroll_timeline_name_;
    }

    // scrollbar-color
    StyleScrollbarColor* ScrollbarColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->scrollbar_color_.Get();
    }

    // scrollbar-gutter
    unsigned ScrollbarGutter() const
    {
        return static_cast<unsigned>(data_.scrollbar_gutter_);
    }

    // scrollbar-width
    EScrollbarWidth ScrollbarWidth() const
    {
        return static_cast<EScrollbarWidth>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scrollbar_width_);
    }

    // shape-image-threshold
    float ShapeImageThreshold() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->shape_image_threshold_;
    }

    // shape-margin
    const Length& ShapeMargin() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->shape_margin_;
    }

    // shape-outside

    // shape-rendering
    EShapeRendering ShapeRendering() const
    {
        return static_cast<EShapeRendering>(svg_data_->shape_rendering_);
    }

    // ShouldIgnoreOverflowPropertyForInlineBlockBaseline
    bool ShouldIgnoreOverflowPropertyForInlineBlockBaseline() const
    {
        return static_cast<bool>(data_.should_ignore_overflow_property_for_inline_block_baseline_);
    }

    // SkipsContents
    bool SkipsContents() const
    {
        return static_cast<bool>(data_.skips_contents_);
    }

    // speak
    ESpeak Speak() const
    {
        return static_cast<ESpeak>(rare_inherited_usage_less_than_64_percent_data_->speak_);
    }

    // line-clamp
    int StandardLineClamp() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->standard_line_clamp_;
    }

    // stop-color

    // stop-opacity
    float StopOpacity() const
    {
        return svg_data_->stop_data_->stop_opacity_;
    }

    // stroke-dasharray
    SVGDashArray* StrokeDashArray() const
    {
        return svg_data_->stroke_data_->stroke_dash_array_.get();
    }

    // stroke-dashoffset
    const Length& StrokeDashOffset() const
    {
        return svg_data_->stroke_data_->stroke_dash_offset_;
    }

    // stroke-miterlimit
    float StrokeMiterLimit() const
    {
        return svg_data_->stroke_data_->stroke_miter_limit_;
    }

    // stroke-opacity
    float StrokeOpacity() const
    {
        return svg_data_->stroke_data_->stroke_opacity_;
    }

    // stroke
    const SVGPaint& StrokePaint() const
    {
        return svg_data_->stroke_data_->stroke_paint_;
    }

    // stroke-width
    const UnzoomedLength& StrokeWidth() const
    {
        return svg_data_->stroke_data_->stroke_width_;
    }

    // StyleType
    PseudoId StyleType() const
    {
        return static_cast<PseudoId>(data_.style_type_);
    }

    // SubtreeIsSticky
    bool SubtreeIsSticky() const
    {
        return static_cast<bool>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_is_sticky_);
    }

    // SubtreeWillChangeContents
    bool SubtreeWillChangeContents() const
    {
        return static_cast<bool>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_will_change_contents_);
    }

    // tab-size
    const TabSize& GetTabSize() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->tab_size_;
    }

    // table-layout
    ETableLayout TableLayout() const
    {
        return static_cast<ETableLayout>(data_.table_layout_);
    }

    // -webkit-tap-highlight-color
    const StyleColor& TapHighlightColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->tap_highlight_color_;
    }

    // text-align
    ETextAlign GetTextAlign() const
    {
        return static_cast<ETextAlign>(data_.text_align_);
    }

    // text-align-last
    ETextAlignLast TextAlignLast() const
    {
        return static_cast<ETextAlignLast>(rare_inherited_usage_less_than_64_percent_data_->text_align_last_);
    }

    // text-anchor
    ETextAnchor TextAnchor() const
    {
        return static_cast<ETextAnchor>(svg_data_->text_anchor_);
    }

    // TextAutosizingMultiplier
    float TextAutosizingMultiplier() const
    {
        return inherited_data_->text_autosizing_multiplier_;
    }

    // text-autospace
    ETextAutospace TextAutospace() const
    {
        return static_cast<ETextAutospace>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_autospace_);
    }

    // text-box-edge
    TextBoxEdge GetTextBoxEdge() const
    {
        return static_cast<TextBoxEdge>(rare_inherited_usage_less_than_64_percent_data_->text_box_edge_);
    }

    // text-box-trim
    ETextBoxTrim TextBoxTrim() const
    {
        return static_cast<ETextBoxTrim>(box_data_->text_box_trim_);
    }

    // text-combine-upright
    ETextCombine TextCombine() const
    {
        return static_cast<ETextCombine>(rare_inherited_usage_less_than_64_percent_data_->text_combine_);
    }

    // text-decoration-color

    // text-decoration-line
    TextDecorationLine GetTextDecorationLine() const
    {
        return static_cast<TextDecorationLine>(visual_data_->text_decoration_line_);
    }

    // text-decoration-skip-ink
    ETextDecorationSkipInk TextDecorationSkipInk() const
    {
        return static_cast<ETextDecorationSkipInk>(rare_inherited_usage_less_than_64_percent_data_->text_decoration_skip_ink_);
    }

    // text-decoration-style
    ETextDecorationStyle TextDecorationStyle() const
    {
        return static_cast<ETextDecorationStyle>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                     ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_style_);
    }

    // text-decoration-thickness
    const TextDecorationThickness& GetTextDecorationThickness() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_thickness_;
    }

    // text-emphasis-color

    // TextEmphasisCustomMark
    const AtomicString& TextEmphasisCustomMark() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_;
    }

    // TextEmphasisFill
    TextEmphasisFill GetTextEmphasisFill() const
    {
        return static_cast<TextEmphasisFill>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_fill_);
    }

    // TextEmphasisMark

    // text-emphasis-position
    TextEmphasisPosition GetTextEmphasisPosition() const
    {
        return static_cast<TextEmphasisPosition>(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_position_);
    }

    // -webkit-text-fill-color

    // text-indent
    const Length& TextIndent() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->text_indent_;
    }

    // text-orientation
    ETextOrientation GetTextOrientation() const
    {
        return static_cast<ETextOrientation>(rare_inherited_usage_less_than_64_percent_data_->text_orientation_);
    }

    // text-overflow
    ETextOverflow TextOverflow() const
    {
        return static_cast<ETextOverflow>(rare_non_inherited_usage_less_than_14_percent_data_->text_overflow_);
    }

    // -webkit-text-security
    ETextSecurity TextSecurity() const
    {
        return static_cast<ETextSecurity>(rare_inherited_usage_less_than_64_percent_data_->text_security_);
    }

    // text-shadow
    ShadowList* TextShadow() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->text_shadow_.Get();
    }

    // text-size-adjust
    const TextSizeAdjust& GetTextSizeAdjust() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_;
    }

    // -webkit-text-stroke-color

    // -webkit-text-stroke-width
    float TextStrokeWidth() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->text_stroke_width_;
    }

    // text-transform
    ETextTransform TextTransform() const
    {
        return static_cast<ETextTransform>(data_.text_transform_);
    }

    // text-transform
    bool TextTransformIsInherited() const
    {
        return static_cast<bool>(data_.text_transform_is_inherited_);
    }

    // text-underline-offset
    const Length& TextUnderlineOffset() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_;
    }

    // text-underline-position
    TextUnderlinePosition GetTextUnderlinePosition() const
    {
        return static_cast<TextUnderlinePosition>(rare_inherited_usage_less_than_64_percent_data_->text_underline_position_);
    }

    // text-wrap-mode
    TextWrapMode GetTextWrapMode() const
    {
        return static_cast<TextWrapMode>(data_.text_wrap_mode_);
    }

    // text-wrap-style
    TextWrapStyle GetTextWrapStyle() const
    {
        return static_cast<TextWrapStyle>(data_.text_wrap_style_);
    }

    // timeline-scope
    const Member<ScopedCSSNameList>& TimelineScope() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->timeline_scope_;
    }

    // top
    const Length& Top() const
    {
        return surround_data_->top_;
    }

    // touch-action
    TouchAction GetTouchAction() const
    {
        return static_cast<TouchAction>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->touch_action_);
    }

    // transform
    const TransformOperations& Transform() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->transform_;
    }

    // transform-box
    ETransformBox TransformBox() const
    {
        return static_cast<ETransformBox>(data_.transform_box_);
    }

    // transform-origin
    const TransformOrigin& GetTransformOrigin() const
    {
        return svg_data_->transform_origin_;
    }

    // transform-style
    ETransformStyle3D TransformStyle3D() const
    {
        return static_cast<ETransformStyle3D>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                  ->rare_non_inherited_usage_less_than_100_percent_data_->transform_style_3d_);
    }

    // Transitions

    // translate
    TranslateTransformOperation* Translate() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->translate_.Get();
    }

    // UAShadowHostData
    StyleUAShadowHostData* UAShadowHostData() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ua_shadow_host_data_.get();
    }

    // unicode-bidi
    UnicodeBidi GetUnicodeBidi() const
    {
        return static_cast<UnicodeBidi>(data_.unicode_bidi_);
    }

    // -webkit-user-drag
    EUserDrag UserDrag() const
    {
        return static_cast<EUserDrag>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                          ->rare_non_inherited_usage_less_than_100_percent_data_->user_drag_);
    }

    // -webkit-user-modify

    // user-select

    // vector-effect
    EVectorEffect VectorEffect() const
    {
        return static_cast<EVectorEffect>(svg_data_->vector_effect_);
    }

    // VerticalAlign

    // VerticalAlignLength
    const Length& GetVerticalAlignLength() const
    {
        return box_data_->vertical_align_length_;
    }

    // -webkit-border-vertical-spacing
    short VerticalBorderSpacing() const
    {
        return inherited_data_->vertical_border_spacing_;
    }

    // view-timeline-axis
    const Vector<TimelineAxis>& ViewTimelineAxis() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
            ->view_timeline_axis_;
    }

    // view-timeline-inset
    const Vector<TimelineInset>& ViewTimelineInset() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
            ->view_timeline_inset_;
    }

    // view-timeline-name
    const Member<ScopedCSSNameList>& ViewTimelineName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
            ->view_timeline_name_;
    }

    // view-transition-capture-mode
    StyleViewTransitionCaptureMode ViewTransitionCaptureMode() const
    {
        return static_cast<StyleViewTransitionCaptureMode>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_capture_mode_);
    }

    // view-transition-class
    const Member<ScopedCSSNameList>& ViewTransitionClass() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_class_;
    }

    // view-transition-group
    const StyleViewTransitionGroup& ViewTransitionGroup() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_group_;
    }

    // view-transition-name
    const Member<StyleViewTransitionName>& ViewTransitionName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_name_;
    }

    // ViewportUnitFlags
    unsigned ViewportUnitFlags() const
    {
        return static_cast<unsigned>(data_.viewport_unit_flags_);
    }

    // visibility
    EVisibility Visibility() const
    {
        return static_cast<EVisibility>(data_.visibility_);
    }

    // visibility
    bool VisibilityIsInherited() const
    {
        return static_cast<bool>(data_.visibility_is_inherited_);
    }

    // -webkit-line-clamp
    int WebkitLineClamp() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->webkit_line_clamp_;
    }

    // white-space-collapse
    WhiteSpaceCollapse GetWhiteSpaceCollapse() const
    {
        return static_cast<WhiteSpaceCollapse>(data_.white_space_collapse_);
    }

    // widows
    short Widows() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->widows_;
    }

    // width
    const Length& Width() const
    {
        return box_data_->width_;
    }

    // WillChangeContents
    bool WillChangeContents() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                                     ->will_change_contents_);
    }

    // WillChangeProperties
    const Vector<CSSPropertyID>& WillChangeProperties() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
            ->will_change_properties_;
    }

    // WillChangeScrollPosition
    bool WillChangeScrollPosition() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                                     ->will_change_scroll_position_);
    }

    // word-break
    EWordBreak WordBreak() const
    {
        return static_cast<EWordBreak>(rare_inherited_usage_less_than_64_percent_data_->word_break_);
    }

    // writing-mode
    WritingMode GetWritingMode() const
    {
        return static_cast<WritingMode>(data_.writing_mode_);
    }

    // x
    const Length& X() const
    {
        return svg_data_->geometry_data_->x_;
    }

    // y
    const Length& Y() const
    {
        return svg_data_->geometry_data_->y_;
    }

    // z-index
    int ZIndex() const
    {
        return box_data_->z_index_;
    }

    // zoom
    float Zoom() const
    {
        return visual_data_->zoom_;
    }

#if DCHECK_IS_ON()
    enum class DebugField {
        accent_color_,
        affected_by_active_,
        affected_by_css_function_,
        affected_by_drag_,
        affected_by_focus_within_,
        affected_by_hover_,
        align_content_,
        align_content_block_center_,
        align_items_,
        align_self_,
        alignment_baseline_,
        anchor_center_offset_,
        anchor_name_,
        anchor_scope_,
        animations_,
        appearance_,
        aspect_ratio_,
        backdrop_filter_,
        backface_visibility_,
        background_,
        background_color_,
        base_data_,
        base_text_decoration_data_,
        baseline_shift_,
        baseline_shift_type_,
        baseline_source_,
        blend_mode_,
        border_bottom_color_,
        border_bottom_left_radius_,
        border_bottom_right_radius_,
        border_bottom_style_,
        border_bottom_width_,
        border_collapse_,
        border_collapse_is_inherited_,
        border_image_,
        border_left_color_,
        border_left_style_,
        border_left_width_,
        border_right_color_,
        border_right_style_,
        border_right_width_,
        border_top_color_,
        border_top_left_radius_,
        border_top_right_radius_,
        border_top_style_,
        border_top_width_,
        bottom_,
        box_align_,
        box_decoration_break_,
        box_direction_,
        box_flex_,
        box_ordinal_group_,
        box_orient_,
        box_pack_,
        box_reflect_,
        box_shadow_,
        box_sizing_,
        break_after_,
        break_before_,
        break_inside_,
        buffered_rendering_,
        callback_selectors_,
        can_affect_animations_,
        cap_style_,
        caption_side_,
        caption_side_is_inherited_,
        caret_animation_,
        caret_color_,
        child_has_explicit_inheritance_,
        clear_,
        clip_,
        clip_path_,
        clip_rule_,
        color_,
        color_interpolation_,
        color_interpolation_filters_,
        color_is_current_color_,
        color_is_inherited_,
        color_rendering_,
        color_scheme_,
        color_scheme_flags_is_normal_,
        color_scheme_forced_,
        column_count_,
        column_fill_,
        column_gap_,
        column_rule_color_,
        column_rule_style_,
        column_rule_width_,
        column_span_,
        column_width_,
        contain_,
        contain_intrinsic_height_,
        contain_intrinsic_width_,
        container_name_,
        container_type_,
        content_,
        content_visibility_,
        counter_directives_,
        css_dominant_baseline_,
        cursor_,
        cursor_data_,
        custom_highlight_names_,
        custom_style_callback_depends_on_font_,
        cx_,
        cy_,
        d_,
        dark_color_scheme_,
        depends_on_scroll_state_container_queries_,
        depends_on_size_container_queries_,
        depends_on_style_container_queries_,
        direction_,
        display_,
        display_layout_custom_name_,
        display_layout_custom_parent_name_,
        document_rules_selectors_,
        dominant_baseline_,
        draggable_region_mode_,
        dynamic_range_limit_,
        effective_appearance_,
        effective_touch_action_,
        effective_z_index_zero_,
        effective_zoom_,
        element_is_view_transition_participant_,
        empty_cells_,
        empty_cells_is_inherited_,
        field_sizing_,
        fill_opacity_,
        fill_paint_,
        fill_rule_,
        filter_,
        first_line_depends_on_size_container_queries_,
        flex_basis_,
        flex_direction_,
        flex_grow_,
        flex_shrink_,
        flex_wrap_,
        floating_,
        flood_color_,
        flood_opacity_,
        font_,
        forced_color_adjust_,
        forces_stacking_context_,
        grid_auto_columns_,
        grid_auto_flow_,
        grid_auto_rows_,
        grid_column_end_,
        grid_column_start_,
        grid_row_end_,
        grid_row_start_,
        grid_template_areas_,
        grid_template_columns_,
        grid_template_rows_,
        has_anchor_evaluator_,
        has_anchor_functions_,
        has_attr_function_,
        has_author_background_,
        has_author_border_,
        has_author_border_radius_,
        has_author_highlight_colors_,
        has_auto_clip_,
        has_auto_column_count_,
        has_auto_column_width_,
        has_auto_standard_line_clamp_,
        has_auto_z_index_,
        has_clip_path_,
        has_container_relative_units_,
        has_current_backdrop_filter_animation_,
        has_current_background_color_animation_,
        has_current_filter_animation_,
        has_current_opacity_animation_,
        has_current_rotate_animation_,
        has_current_scale_animation_,
        has_current_transform_animation_,
        has_current_translate_animation_,
        has_em_units_,
        has_env_,
        has_explicit_inheritance_,
        has_explicit_overflow_x_visible_,
        has_explicit_overflow_y_visible_,
        has_glyph_relative_units_,
        has_line_height_relative_units_,
        has_line_if_empty_,
        has_logical_direction_relative_units_,
        has_non_ua_highlight_pseudo_styles_,
        has_non_universal_highlight_pseudo_styles_,
        has_root_font_relative_units_,
        has_variable_declaration_,
        has_variable_reference_,
        height_,
        highlight_data_,
        highlights_depend_on_size_container_queries_,
        horizontal_border_spacing_,
        hyphenate_limit_chars_,
        hyphenation_string_,
        hyphens_,
        image_orientation_,
        image_rendering_,
        in_base_select_appearance_,
        in_forced_colors_mode_,
        inherited_variables_,
        initial_data_,
        initial_letter_,
        inline_block_baseline_edge_,
        inline_style_lost_cascade_,
        inside_link_,
        interactivity_,
        internal_forced_background_color_,
        internal_forced_border_color_,
        internal_forced_color_,
        internal_forced_outline_color_,
        internal_forced_visited_color_,
        internal_visited_background_color_,
        internal_visited_border_bottom_color_,
        internal_visited_border_left_color_,
        internal_visited_border_right_color_,
        internal_visited_border_top_color_,
        internal_visited_caret_color_,
        internal_visited_color_,
        internal_visited_color_is_current_color_,
        internal_visited_column_rule_color_,
        internal_visited_fill_paint_,
        internal_visited_outline_color_,
        internal_visited_stroke_paint_,
        internal_visited_text_decoration_color_,
        internal_visited_text_emphasis_color_,
        internal_visited_text_fill_color_,
        internal_visited_text_stroke_color_,
        interpolate_size_,
        is_ensured_in_display_none_,
        is_ensured_outside_flat_tree_,
        is_flex_or_grid_or_custom_item_,
        is_html_inert_,
        is_html_inert_is_inherited_,
        is_in_blockifying_display_,
        is_in_inlinifying_display_,
        is_inside_display_ignoring_floating_children_,
        is_inside_list_element_,
        is_link_,
        is_original_display_inline_type_,
        is_page_margin_box_,
        is_running_backdrop_filter_animation_on_compositor_,
        is_running_filter_animation_on_compositor_,
        is_running_opacity_animation_on_compositor_,
        is_running_rotate_animation_on_compositor_,
        is_running_scale_animation_on_compositor_,
        is_running_transform_animation_on_compositor_,
        is_running_translate_animation_on_compositor_,
        is_secondary_body_element_,
        is_specified_display_webkit_box_,
        is_stacking_context_without_containment_,
        is_starting_style_,
        isolation_,
        join_style_,
        justify_content_,
        justify_items_,
        justify_self_,
        left_,
        lighting_color_,
        line_break_,
        line_height_,
        list_style_image_,
        list_style_position_,
        list_style_position_is_inherited_,
        list_style_type_,
        margin_bottom_,
        margin_left_,
        margin_right_,
        margin_top_,
        marker_end_resource_,
        marker_mid_resource_,
        marker_start_resource_,
        mask_,
        mask_box_image_,
        mask_type_,
        masonry_slack_,
        masonry_template_tracks_,
        masonry_track_end_,
        masonry_track_start_,
        math_baseline_,
        math_depth_,
        math_fraction_bar_thickness_,
        math_l_space_,
        math_max_size_,
        math_min_size_,
        math_padded_depth_,
        math_padded_v_offset_,
        math_r_space_,
        math_shift_,
        math_style_,
        max_height_,
        max_width_,
        may_have_margin_,
        may_have_padding_,
        min_height_,
        min_width_,
        non_inherited_variables_,
        object_fit_,
        object_position_,
        object_view_box_,
        offset_anchor_,
        offset_distance_,
        offset_path_,
        offset_position_,
        offset_rotate_,
        opacity_,
        order_,
        origin_trial_test_property_,
        orphans_,
        outline_color_,
        outline_offset_,
        outline_style_,
        outline_style_is_auto_,
        outline_width_,
        overflow_anchor_,
        overflow_clip_margin_,
        overflow_wrap_,
        overflow_x_,
        overflow_y_,
        overlay_,
        overscroll_behavior_x_,
        overscroll_behavior_y_,
        padding_bottom_,
        padding_left_,
        padding_right_,
        padding_top_,
        page_,
        page_orientation_,
        page_size_,
        page_size_type_,
        paint_images_,
        paint_order_,
        perspective_,
        perspective_origin_,
        pointer_events_,
        pointer_events_is_inherited_,
        popover_hide_delay_,
        popover_show_delay_,
        position_,
        position_anchor_,
        position_area_,
        position_area_offsets_,
        position_try_fallbacks_,
        position_try_order_,
        position_visibility_,
        prefers_default_scrollbar_styles_,
        print_color_adjust_,
        pseudo_argument_,
        pseudo_element_styles_,
        quotes_,
        r_,
        reading_flow_,
        requires_accelerated_compositing_for_external_reasons_,
        resize_,
        right_,
        rotate_,
        row_gap_,
        rtl_ordering_,
        rtl_ordering_is_inherited_,
        ruby_align_,
        ruby_position_,
        rx_,
        ry_,
        scale_,
        scroll_behavior_,
        scroll_margin_bottom_,
        scroll_margin_left_,
        scroll_margin_right_,
        scroll_margin_top_,
        scroll_marker_group_,
        scroll_padding_bottom_,
        scroll_padding_left_,
        scroll_padding_right_,
        scroll_padding_top_,
        scroll_snap_align_,
        scroll_snap_stop_,
        scroll_snap_type_,
        scroll_start_target_,
        scroll_start_x_,
        scroll_start_y_,
        scroll_timeline_axis_,
        scroll_timeline_name_,
        scrollbar_color_,
        scrollbar_gutter_,
        scrollbar_width_,
        shape_image_threshold_,
        shape_margin_,
        shape_outside_,
        shape_rendering_,
        should_ignore_overflow_property_for_inline_block_baseline_,
        skips_contents_,
        speak_,
        standard_line_clamp_,
        stop_color_,
        stop_opacity_,
        stroke_dash_array_,
        stroke_dash_offset_,
        stroke_miter_limit_,
        stroke_opacity_,
        stroke_paint_,
        stroke_width_,
        style_type_,
        subtree_is_sticky_,
        subtree_will_change_contents_,
        tab_size_,
        table_layout_,
        tap_highlight_color_,
        text_align_,
        text_align_last_,
        text_anchor_,
        text_autosizing_multiplier_,
        text_autospace_,
        text_box_edge_,
        text_box_trim_,
        text_combine_,
        text_decoration_color_,
        text_decoration_line_,
        text_decoration_skip_ink_,
        text_decoration_style_,
        text_decoration_thickness_,
        text_emphasis_color_,
        text_emphasis_custom_mark_,
        text_emphasis_fill_,
        text_emphasis_mark_,
        text_emphasis_position_,
        text_fill_color_,
        text_indent_,
        text_orientation_,
        text_overflow_,
        text_security_,
        text_shadow_,
        text_size_adjust_,
        text_stroke_color_,
        text_stroke_width_,
        text_transform_,
        text_transform_is_inherited_,
        text_underline_offset_,
        text_underline_position_,
        text_wrap_mode_,
        text_wrap_style_,
        timeline_scope_,
        top_,
        touch_action_,
        transform_,
        transform_box_,
        transform_origin_,
        transform_style_3d_,
        transitions_,
        translate_,
        ua_shadow_host_data_,
        unicode_bidi_,
        user_drag_,
        user_modify_,
        user_select_,
        vector_effect_,
        vertical_align_,
        vertical_align_length_,
        vertical_border_spacing_,
        view_timeline_axis_,
        view_timeline_inset_,
        view_timeline_name_,
        view_transition_capture_mode_,
        view_transition_class_,
        view_transition_group_,
        view_transition_name_,
        viewport_unit_flags_,
        visibility_,
        visibility_is_inherited_,
        webkit_line_clamp_,
        white_space_collapse_,
        widows_,
        width_,
        will_change_contents_,
        will_change_properties_,
        will_change_scroll_position_,
        word_break_,
        writing_mode_,
        x_,
        y_,
        z_index_,
        zoom_,
    };
    struct DebugDiff {
        DebugField field;
        std::string correct;
        std::string actual;
    };

    CORE_EXPORT static String DebugFieldToString(DebugField);

    // Returns a list of all fields that differ between |this| and |o|.
    CORE_EXPORT Vector<DebugDiff> DebugDiffFields(const ComputedStyleBase& o) const;
#endif // DCHECK_IS_ON()

    // Find a list of which subgroups listed have changed between this and the
    // other ComputedStyle(Base); output a list of the changed groups and their
    // sizes in bytes. This is meant for more precise memory tracking than just
    // looking at the Oilpan statistics, or for finding out (empirically)
    // which groups are affected by setting a specific property. It is used
    // only in the style perftest, not in the normal rendering engine.
    //
    // Note that if you change something deep in a subgroup like e.g. a->b->c,
    // both a->b and a will also be recorded, as they must be modified to get
    // the pointer in place. The fixed 4- or 8-byte Oilpan header overhead
    // is not included.
    Vector<std::pair<String, size_t>> FindChangedGroups(const ComputedStyleBase& other_style) const;

    CORE_EXPORT void Trace(Visitor* visitor) const;
    void TraceAfterDispatch(Visitor* visitor) const
    {
        visitor->Trace(rare_inherited_usage_less_than_64_percent_data_);
        visitor->Trace(rare_non_inherited_usage_less_than_14_percent_data_);
        visitor->Trace(inherited_data_);
        visitor->Trace(visual_data_);
        visitor->Trace(svg_data_);
        visitor->Trace(surround_data_);
        visitor->Trace(background_data_);
        visitor->Trace(box_data_);
        visitor->Trace(font_data_);
        visitor->Trace(base_data_);
    }

private:
    class StyleRareInheritedUsageLessThan100PercentData : public GarbageCollected<StyleRareInheritedUsageLessThan100PercentData> {
    public:
        explicit StyleRareInheritedUsageLessThan100PercentData();
        CORE_EXPORT StyleRareInheritedUsageLessThan100PercentData(const StyleRareInheritedUsageLessThan100PercentData&);

        static StyleRareInheritedUsageLessThan100PercentData* Create()
        {
            return MakeGarbageCollected<StyleRareInheritedUsageLessThan100PercentData>();
        }
        StyleRareInheritedUsageLessThan100PercentData* Copy() const
        {
            return MakeGarbageCollected<StyleRareInheritedUsageLessThan100PercentData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<Length>::Trace(visitor, text_underline_offset_);
            TraceIfNeeded<StyleColor>::Trace(visitor, tap_highlight_color_);
            TraceIfNeeded<StyleAutoColor>::Trace(visitor, accent_color_);
            TraceIfNeeded<short>::Trace(visitor, math_depth_);
        }

        bool operator==(const StyleRareInheritedUsageLessThan100PercentData& other) const
        {
            return (text_underline_offset_ == other.text_underline_offset_ && tap_highlight_color_ == other.tap_highlight_color_
                && accent_color_ == other.accent_color_ && math_depth_ == other.math_depth_ && image_orientation_ == other.image_orientation_
                && math_shift_ == other.math_shift_ && math_style_ == other.math_style_);
        }
        bool operator!=(const StyleRareInheritedUsageLessThan100PercentData& other) const
        {
            return !(*this == other);
        }

        Length text_underline_offset_;
        StyleColor tap_highlight_color_;
        StyleAutoColor accent_color_;
        short math_depth_;
        unsigned image_orientation_ : 1; // RespectImageOrientationEnum
        unsigned math_shift_ : 1; // EMathShift
        unsigned math_style_ : 1; // EMathStyle
    };

    class StyleInheritedForcedColorsData : public GarbageCollected<StyleInheritedForcedColorsData> {
    public:
        explicit StyleInheritedForcedColorsData();
        CORE_EXPORT StyleInheritedForcedColorsData(const StyleInheritedForcedColorsData&);

        static StyleInheritedForcedColorsData* Create()
        {
            return MakeGarbageCollected<StyleInheritedForcedColorsData>();
        }
        StyleInheritedForcedColorsData* Copy() const
        {
            return MakeGarbageCollected<StyleInheritedForcedColorsData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_forced_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_forced_visited_color_);
        }

        bool operator==(const StyleInheritedForcedColorsData& other) const
        {
            return (internal_forced_color_ == other.internal_forced_color_ && internal_forced_visited_color_ == other.internal_forced_visited_color_);
        }
        bool operator!=(const StyleInheritedForcedColorsData& other) const
        {
            return !(*this == other);
        }

        StyleColor internal_forced_color_;
        StyleColor internal_forced_visited_color_;
    };

    class StyleInheritedVisitedData : public GarbageCollected<StyleInheritedVisitedData> {
    public:
        explicit StyleInheritedVisitedData();
        CORE_EXPORT StyleInheritedVisitedData(const StyleInheritedVisitedData&);

        static StyleInheritedVisitedData* Create()
        {
            return MakeGarbageCollected<StyleInheritedVisitedData>();
        }
        StyleInheritedVisitedData* Copy() const
        {
            return MakeGarbageCollected<StyleInheritedVisitedData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_text_emphasis_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_text_fill_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_text_stroke_color_);
            TraceIfNeeded<StyleAutoColor>::Trace(visitor, internal_visited_caret_color_);
        }

        bool operator==(const StyleInheritedVisitedData& other) const
        {
            return (internal_visited_text_emphasis_color_ == other.internal_visited_text_emphasis_color_
                && internal_visited_text_fill_color_ == other.internal_visited_text_fill_color_
                && internal_visited_text_stroke_color_ == other.internal_visited_text_stroke_color_
                && internal_visited_caret_color_ == other.internal_visited_caret_color_);
        }
        bool operator!=(const StyleInheritedVisitedData& other) const
        {
            return !(*this == other);
        }

        StyleColor internal_visited_text_emphasis_color_;
        StyleColor internal_visited_text_fill_color_;
        StyleColor internal_visited_text_stroke_color_;
        StyleAutoColor internal_visited_caret_color_;
    };

    class StyleHighlightDataData : public GarbageCollected<StyleHighlightDataData> {
    public:
        explicit StyleHighlightDataData();
        CORE_EXPORT StyleHighlightDataData(const StyleHighlightDataData&);

        static StyleHighlightDataData* Create()
        {
            return MakeGarbageCollected<StyleHighlightDataData>();
        }
        StyleHighlightDataData* Copy() const
        {
            return MakeGarbageCollected<StyleHighlightDataData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<StyleHighlightData>::Trace(visitor, highlight_data_);
        }

        bool operator==(const StyleHighlightDataData& other) const
        {
            return (highlight_data_ == other.highlight_data_);
        }
        bool operator!=(const StyleHighlightDataData& other) const
        {
            return !(*this == other);
        }

        StyleHighlightData highlight_data_;
    };

    class StyleRareInheritedUsageLessThan64PercentSubData : public GarbageCollected<StyleRareInheritedUsageLessThan64PercentSubData> {
    public:
        explicit StyleRareInheritedUsageLessThan64PercentSubData();
        CORE_EXPORT StyleRareInheritedUsageLessThan64PercentSubData(const StyleRareInheritedUsageLessThan64PercentSubData&);

        static StyleRareInheritedUsageLessThan64PercentSubData* Create()
        {
            return MakeGarbageCollected<StyleRareInheritedUsageLessThan64PercentSubData>();
        }
        StyleRareInheritedUsageLessThan64PercentSubData* Copy() const
        {
            return MakeGarbageCollected<StyleRareInheritedUsageLessThan64PercentSubData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            visitor->Trace(inherited_forced_colors_data_);
            visitor->Trace(inherited_visited_data_);
            visitor->Trace(highlight_data_data_);
            TraceIfNeeded<DynamicRangeLimit>::Trace(visitor, dynamic_range_limit_);
            TraceIfNeeded<AtomicString>::Trace(visitor, text_emphasis_custom_mark_);
            visitor->Trace(scrollbar_color_);
            visitor->Trace(cursor_data_);
            visitor->Trace(initial_data_);
            TraceIfNeeded<float>::Trace(visitor, effective_zoom_);
            TraceIfNeeded<StyleHyphenateLimitChars>::Trace(visitor, hyphenate_limit_chars_);
        }

        bool operator==(const StyleRareInheritedUsageLessThan64PercentSubData& other) const
        {
            return (base::ValuesEquivalent(inherited_forced_colors_data_, other.inherited_forced_colors_data_)
                && base::ValuesEquivalent(inherited_visited_data_, other.inherited_visited_data_)
                && base::ValuesEquivalent(highlight_data_data_, other.highlight_data_data_) && dynamic_range_limit_ == other.dynamic_range_limit_
                && text_emphasis_custom_mark_ == other.text_emphasis_custom_mark_ && base::ValuesEquivalent(ua_shadow_host_data_, other.ua_shadow_host_data_)
                && base::ValuesEquivalent(scrollbar_color_, other.scrollbar_color_) && base::ValuesEquivalent(cursor_data_, other.cursor_data_)
                && base::ValuesEquivalent(initial_data_, other.initial_data_) && effective_zoom_ == other.effective_zoom_
                && hyphenate_limit_chars_ == other.hyphenate_limit_chars_ && effective_touch_action_ == other.effective_touch_action_
                && text_emphasis_mark_ == other.text_emphasis_mark_ && ruby_align_ == other.ruby_align_ && has_line_if_empty_ == other.has_line_if_empty_
                && in_base_select_appearance_ == other.in_base_select_appearance_ && interactivity_ == other.interactivity_
                && interpolate_size_ == other.interpolate_size_ && subtree_is_sticky_ == other.subtree_is_sticky_
                && subtree_will_change_contents_ == other.subtree_will_change_contents_ && text_autospace_ == other.text_autospace_
                && text_emphasis_fill_ == other.text_emphasis_fill_);
        }
        bool operator!=(const StyleRareInheritedUsageLessThan64PercentSubData& other) const
        {
            return !(*this == other);
        }

        Member<StyleInheritedForcedColorsData> inherited_forced_colors_data_;
        Member<StyleInheritedVisitedData> inherited_visited_data_;
        Member<StyleHighlightDataData> highlight_data_data_;
        DynamicRangeLimit dynamic_range_limit_;
        AtomicString text_emphasis_custom_mark_;
        std::unique_ptr<StyleUAShadowHostData> ua_shadow_host_data_;
        Member<StyleScrollbarColor> scrollbar_color_;
        Member<CursorList> cursor_data_;
        Member<StyleInitialData> initial_data_;
        float effective_zoom_;
        StyleHyphenateLimitChars hyphenate_limit_chars_;
        unsigned effective_touch_action_ : 8; // TouchAction
        unsigned text_emphasis_mark_ : 3; // TextEmphasisMark
        unsigned ruby_align_ : 2; // ERubyAlign
        unsigned has_line_if_empty_ : 1; // bool
        unsigned in_base_select_appearance_ : 1; // bool
        unsigned interactivity_ : 1; // EInteractivity
        unsigned interpolate_size_ : 1; // EInterpolateSize
        unsigned subtree_is_sticky_ : 1; // bool
        unsigned subtree_will_change_contents_ : 1; // bool
        unsigned text_autospace_ : 1; // ETextAutospace
        unsigned text_emphasis_fill_ : 1; // TextEmphasisFill
    };

    class StyleRareInheritedUsageLessThan64PercentData : public GarbageCollected<StyleRareInheritedUsageLessThan64PercentData> {
    public:
        explicit StyleRareInheritedUsageLessThan64PercentData();
        CORE_EXPORT StyleRareInheritedUsageLessThan64PercentData(const StyleRareInheritedUsageLessThan64PercentData&);

        static StyleRareInheritedUsageLessThan64PercentData* Create()
        {
            return MakeGarbageCollected<StyleRareInheritedUsageLessThan64PercentData>();
        }
        StyleRareInheritedUsageLessThan64PercentData* Copy() const
        {
            return MakeGarbageCollected<StyleRareInheritedUsageLessThan64PercentData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            visitor->Trace(rare_inherited_usage_less_than_100_percent_data_);
            visitor->Trace(rare_inherited_usage_less_than_64_percent_sub_data_);
            TraceIfNeeded<Vector<AtomicString>>::Trace(visitor, color_scheme_);
            TraceIfNeeded<AtomicString>::Trace(visitor, hyphenation_string_);
            visitor->Trace(list_style_image_);
            visitor->Trace(list_style_type_);
            visitor->Trace(text_shadow_);
            TraceIfNeeded<Length>::Trace(visitor, text_indent_);
            TraceIfNeeded<TextSizeAdjust>::Trace(visitor, text_size_adjust_);
            TraceIfNeeded<TabSize>::Trace(visitor, tab_size_);
            TraceIfNeeded<float>::Trace(visitor, text_stroke_width_);
            TraceIfNeeded<StyleColor>::Trace(visitor, text_emphasis_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, text_fill_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, text_stroke_color_);
            TraceIfNeeded<StyleAutoColor>::Trace(visitor, caret_color_);
            TraceIfNeeded<short>::Trace(visitor, orphans_);
            TraceIfNeeded<short>::Trace(visitor, widows_);
        }

        bool operator==(const StyleRareInheritedUsageLessThan64PercentData& other) const
        {
            return (base::ValuesEquivalent(rare_inherited_usage_less_than_100_percent_data_, other.rare_inherited_usage_less_than_100_percent_data_)
                && base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_sub_data_, other.rare_inherited_usage_less_than_64_percent_sub_data_)
                && color_scheme_ == other.color_scheme_ && hyphenation_string_ == other.hyphenation_string_ && base::ValuesEquivalent(quotes_, other.quotes_)
                && base::ValuesEquivalent(list_style_image_, other.list_style_image_) && base::ValuesEquivalent(list_style_type_, other.list_style_type_)
                && base::ValuesEquivalent(text_shadow_, other.text_shadow_) && text_indent_ == other.text_indent_
                && text_size_adjust_ == other.text_size_adjust_ && tab_size_ == other.tab_size_ && text_stroke_width_ == other.text_stroke_width_
                && text_emphasis_color_ == other.text_emphasis_color_ && text_fill_color_ == other.text_fill_color_
                && text_stroke_color_ == other.text_stroke_color_ && caret_color_ == other.caret_color_ && orphans_ == other.orphans_
                && widows_ == other.widows_ && text_box_edge_ == other.text_box_edge_ && text_underline_position_ == other.text_underline_position_
                && image_rendering_ == other.image_rendering_ && line_break_ == other.line_break_ && speak_ == other.speak_
                && text_align_last_ == other.text_align_last_ && user_select_ == other.user_select_ && word_break_ == other.word_break_
                && forced_color_adjust_ == other.forced_color_adjust_ && hyphens_ == other.hyphens_ && overflow_wrap_ == other.overflow_wrap_
                && text_emphasis_position_ == other.text_emphasis_position_ && text_orientation_ == other.text_orientation_
                && text_security_ == other.text_security_ && user_modify_ == other.user_modify_ && ruby_position_ == other.ruby_position_
                && text_combine_ == other.text_combine_ && text_decoration_skip_ink_ == other.text_decoration_skip_ink_);
        }
        bool operator!=(const StyleRareInheritedUsageLessThan64PercentData& other) const
        {
            return !(*this == other);
        }

        Member<StyleRareInheritedUsageLessThan100PercentData> rare_inherited_usage_less_than_100_percent_data_;
        Member<StyleRareInheritedUsageLessThan64PercentSubData> rare_inherited_usage_less_than_64_percent_sub_data_;
        Vector<AtomicString> color_scheme_;
        AtomicString hyphenation_string_;
        scoped_refptr<QuotesData> quotes_;
        Member<StyleImage> list_style_image_;
        Member<ListStyleTypeData> list_style_type_;
        Member<ShadowList> text_shadow_;
        Length text_indent_;
        TextSizeAdjust text_size_adjust_;
        TabSize tab_size_;
        float text_stroke_width_;
        StyleColor text_emphasis_color_;
        StyleColor text_fill_color_;
        StyleColor text_stroke_color_;
        StyleAutoColor caret_color_;
        short orphans_;
        short widows_;
        unsigned text_box_edge_ : 6; // TextBoxEdge
        unsigned text_underline_position_ : 4; // TextUnderlinePosition
        unsigned image_rendering_ : 3; // EImageRendering
        unsigned line_break_ : 3; // LineBreak
        unsigned speak_ : 3; // ESpeak
        unsigned text_align_last_ : 3; // ETextAlignLast
        unsigned user_select_ : 3; // EUserSelect
        unsigned word_break_ : 3; // EWordBreak
        unsigned forced_color_adjust_ : 2; // EForcedColorAdjust
        unsigned hyphens_ : 2; // Hyphens
        unsigned overflow_wrap_ : 2; // EOverflowWrap
        unsigned text_emphasis_position_ : 2; // TextEmphasisPosition
        unsigned text_orientation_ : 2; // ETextOrientation
        unsigned text_security_ : 2; // ETextSecurity
        unsigned user_modify_ : 2; // EUserModify
        unsigned ruby_position_ : 1; // RubyPosition
        unsigned text_combine_ : 1; // ETextCombine
        unsigned text_decoration_skip_ink_ : 1; // ETextDecorationSkipInk
    };

    class StyleGridData : public GarbageCollected<StyleGridData> {
    public:
        explicit StyleGridData();
        CORE_EXPORT StyleGridData(const StyleGridData&);

        static StyleGridData* Create()
        {
            return MakeGarbageCollected<StyleGridData>();
        }
        StyleGridData* Copy() const
        {
            return MakeGarbageCollected<StyleGridData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<ComputedGridTrackList>::Trace(visitor, grid_template_columns_);
            TraceIfNeeded<ComputedGridTrackList>::Trace(visitor, grid_template_rows_);
        }

        bool operator==(const StyleGridData& other) const
        {
            return (grid_template_columns_ == other.grid_template_columns_ && grid_template_rows_ == other.grid_template_rows_);
        }
        bool operator!=(const StyleGridData& other) const
        {
            return !(*this == other);
        }

        ComputedGridTrackList grid_template_columns_;
        ComputedGridTrackList grid_template_rows_;
    };

    class StyleForcedColorsData : public GarbageCollected<StyleForcedColorsData> {
    public:
        explicit StyleForcedColorsData();
        CORE_EXPORT StyleForcedColorsData(const StyleForcedColorsData&);

        static StyleForcedColorsData* Create()
        {
            return MakeGarbageCollected<StyleForcedColorsData>();
        }
        StyleForcedColorsData* Copy() const
        {
            return MakeGarbageCollected<StyleForcedColorsData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_forced_background_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_forced_border_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_forced_outline_color_);
        }

        bool operator==(const StyleForcedColorsData& other) const
        {
            return (internal_forced_background_color_ == other.internal_forced_background_color_
                && internal_forced_border_color_ == other.internal_forced_border_color_
                && internal_forced_outline_color_ == other.internal_forced_outline_color_);
        }
        bool operator!=(const StyleForcedColorsData& other) const
        {
            return !(*this == other);
        }

        StyleColor internal_forced_background_color_;
        StyleColor internal_forced_border_color_;
        StyleColor internal_forced_outline_color_;
    };

    class StyleVisitedData : public GarbageCollected<StyleVisitedData> {
    public:
        explicit StyleVisitedData();
        CORE_EXPORT StyleVisitedData(const StyleVisitedData&);

        static StyleVisitedData* Create()
        {
            return MakeGarbageCollected<StyleVisitedData>();
        }
        StyleVisitedData* Copy() const
        {
            return MakeGarbageCollected<StyleVisitedData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<GapDataList<StyleColor>>::Trace(visitor, internal_visited_column_rule_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_background_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_border_bottom_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_border_left_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_border_right_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_border_top_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_outline_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_text_decoration_color_);
        }

        bool operator==(const StyleVisitedData& other) const
        {
            return (internal_visited_column_rule_color_ == other.internal_visited_column_rule_color_
                && internal_visited_background_color_ == other.internal_visited_background_color_
                && internal_visited_border_bottom_color_ == other.internal_visited_border_bottom_color_
                && internal_visited_border_left_color_ == other.internal_visited_border_left_color_
                && internal_visited_border_right_color_ == other.internal_visited_border_right_color_
                && internal_visited_border_top_color_ == other.internal_visited_border_top_color_
                && internal_visited_outline_color_ == other.internal_visited_outline_color_
                && internal_visited_text_decoration_color_ == other.internal_visited_text_decoration_color_);
        }
        bool operator!=(const StyleVisitedData& other) const
        {
            return !(*this == other);
        }

        GapDataList<StyleColor> internal_visited_column_rule_color_;
        StyleColor internal_visited_background_color_;
        StyleColor internal_visited_border_bottom_color_;
        StyleColor internal_visited_border_left_color_;
        StyleColor internal_visited_border_right_color_;
        StyleColor internal_visited_border_top_color_;
        StyleColor internal_visited_outline_color_;
        StyleColor internal_visited_text_decoration_color_;
    };

    class StyleMasonryData : public GarbageCollected<StyleMasonryData> {
    public:
        explicit StyleMasonryData();
        CORE_EXPORT StyleMasonryData(const StyleMasonryData&);

        static StyleMasonryData* Create()
        {
            return MakeGarbageCollected<StyleMasonryData>();
        }
        StyleMasonryData* Copy() const
        {
            return MakeGarbageCollected<StyleMasonryData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<ComputedGridTrackList>::Trace(visitor, masonry_template_tracks_);
        }

        bool operator==(const StyleMasonryData& other) const
        {
            return (masonry_template_tracks_ == other.masonry_template_tracks_);
        }
        bool operator!=(const StyleMasonryData& other) const
        {
            return !(*this == other);
        }

        ComputedGridTrackList masonry_template_tracks_;
    };

    class StyleStartData : public GarbageCollected<StyleStartData> {
    public:
        explicit StyleStartData();
        CORE_EXPORT StyleStartData(const StyleStartData&);

        static StyleStartData* Create()
        {
            return MakeGarbageCollected<StyleStartData>();
        }
        StyleStartData* Copy() const
        {
            return MakeGarbageCollected<StyleStartData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<ScrollStartData>::Trace(visitor, scroll_start_x_);
            TraceIfNeeded<ScrollStartData>::Trace(visitor, scroll_start_y_);
        }

        bool operator==(const StyleStartData& other) const
        {
            return (scroll_start_x_ == other.scroll_start_x_ && scroll_start_y_ == other.scroll_start_y_);
        }
        bool operator!=(const StyleStartData& other) const
        {
            return !(*this == other);
        }

        ScrollStartData scroll_start_x_;
        ScrollStartData scroll_start_y_;
    };

    class StyleTimelineData : public GarbageCollected<StyleTimelineData> {
    public:
        explicit StyleTimelineData();
        CORE_EXPORT StyleTimelineData(const StyleTimelineData&);

        static StyleTimelineData* Create()
        {
            return MakeGarbageCollected<StyleTimelineData>();
        }
        StyleTimelineData* Copy() const
        {
            return MakeGarbageCollected<StyleTimelineData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<Vector<TimelineAxis>>::Trace(visitor, scroll_timeline_axis_);
            TraceIfNeeded<Vector<TimelineAxis>>::Trace(visitor, view_timeline_axis_);
            TraceIfNeeded<Vector<TimelineInset>>::Trace(visitor, view_timeline_inset_);
            visitor->Trace(scroll_timeline_name_);
            visitor->Trace(timeline_scope_);
            visitor->Trace(view_timeline_name_);
        }

        bool operator==(const StyleTimelineData& other) const
        {
            return (scroll_timeline_axis_ == other.scroll_timeline_axis_ && view_timeline_axis_ == other.view_timeline_axis_
                && view_timeline_inset_ == other.view_timeline_inset_ && base::ValuesEquivalent(scroll_timeline_name_, other.scroll_timeline_name_)
                && base::ValuesEquivalent(timeline_scope_, other.timeline_scope_) && base::ValuesEquivalent(view_timeline_name_, other.view_timeline_name_));
        }
        bool operator!=(const StyleTimelineData& other) const
        {
            return !(*this == other);
        }

        Vector<TimelineAxis> scroll_timeline_axis_;
        Vector<TimelineAxis> view_timeline_axis_;
        Vector<TimelineInset> view_timeline_inset_;
        Member<ScopedCSSNameList> scroll_timeline_name_;
        Member<ScopedCSSNameList> timeline_scope_;
        Member<ScopedCSSNameList> view_timeline_name_;
    };

    class StyleWillChangeData : public GarbageCollected<StyleWillChangeData> {
    public:
        explicit StyleWillChangeData();
        CORE_EXPORT StyleWillChangeData(const StyleWillChangeData&);

        static StyleWillChangeData* Create()
        {
            return MakeGarbageCollected<StyleWillChangeData>();
        }
        StyleWillChangeData* Copy() const
        {
            return MakeGarbageCollected<StyleWillChangeData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<Vector<CSSPropertyID>>::Trace(visitor, will_change_properties_);
        }

        bool operator==(const StyleWillChangeData& other) const
        {
            return (will_change_properties_ == other.will_change_properties_ && will_change_contents_ == other.will_change_contents_
                && will_change_scroll_position_ == other.will_change_scroll_position_);
        }
        bool operator!=(const StyleWillChangeData& other) const
        {
            return !(*this == other);
        }

        Vector<CSSPropertyID> will_change_properties_;
        unsigned will_change_contents_ : 1; // bool
        unsigned will_change_scroll_position_ : 1; // bool
    };

    class StyleMathData : public GarbageCollected<StyleMathData> {
    public:
        explicit StyleMathData();
        CORE_EXPORT StyleMathData(const StyleMathData&);

        static StyleMathData* Create()
        {
            return MakeGarbageCollected<StyleMathData>();
        }
        StyleMathData* Copy() const
        {
            return MakeGarbageCollected<StyleMathData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<Length>::Trace(visitor, math_baseline_);
            TraceIfNeeded<Length>::Trace(visitor, math_fraction_bar_thickness_);
            TraceIfNeeded<Length>::Trace(visitor, math_l_space_);
            TraceIfNeeded<Length>::Trace(visitor, math_r_space_);
            TraceIfNeeded<Length>::Trace(visitor, math_padded_v_offset_);
            TraceIfNeeded<Length>::Trace(visitor, math_padded_depth_);
            TraceIfNeeded<Length>::Trace(visitor, math_min_size_);
            TraceIfNeeded<Length>::Trace(visitor, math_max_size_);
        }

        bool operator==(const StyleMathData& other) const
        {
            return (math_baseline_ == other.math_baseline_ && math_fraction_bar_thickness_ == other.math_fraction_bar_thickness_
                && math_l_space_ == other.math_l_space_ && math_r_space_ == other.math_r_space_ && math_padded_v_offset_ == other.math_padded_v_offset_
                && math_padded_depth_ == other.math_padded_depth_ && math_min_size_ == other.math_min_size_ && math_max_size_ == other.math_max_size_);
        }
        bool operator!=(const StyleMathData& other) const
        {
            return !(*this == other);
        }

        Length math_baseline_;
        Length math_fraction_bar_thickness_;
        Length math_l_space_;
        Length math_r_space_;
        Length math_padded_v_offset_;
        Length math_padded_depth_;
        Length math_min_size_;
        Length math_max_size_;
    };

    class StyleRareNonInheritedUsageLessThan14PercentSubData : public GarbageCollected<StyleRareNonInheritedUsageLessThan14PercentSubData> {
    public:
        explicit StyleRareNonInheritedUsageLessThan14PercentSubData();
        CORE_EXPORT StyleRareNonInheritedUsageLessThan14PercentSubData(const StyleRareNonInheritedUsageLessThan14PercentSubData&);

        static StyleRareNonInheritedUsageLessThan14PercentSubData* Create()
        {
            return MakeGarbageCollected<StyleRareNonInheritedUsageLessThan14PercentSubData>();
        }
        StyleRareNonInheritedUsageLessThan14PercentSubData* Copy() const
        {
            return MakeGarbageCollected<StyleRareNonInheritedUsageLessThan14PercentSubData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            visitor->Trace(grid_data_);
            visitor->Trace(forced_colors_data_);
            visitor->Trace(visited_data_);
            visitor->Trace(masonry_data_);
            visitor->Trace(start_data_);
            visitor->Trace(timeline_data_);
            visitor->Trace(will_change_data_);
            visitor->Trace(math_data_);
            TraceIfNeeded<StyleViewTransitionGroup>::Trace(visitor, view_transition_group_);
            TraceIfNeeded<GridPosition>::Trace(visitor, masonry_track_end_);
            TraceIfNeeded<GridPosition>::Trace(visitor, masonry_track_start_);
            TraceIfNeeded<AtomicString>::Trace(visitor, display_layout_custom_name_);
            TraceIfNeeded<AtomicString>::Trace(visitor, display_layout_custom_parent_name_);
            TraceIfNeeded<AtomicString>::Trace(visitor, pseudo_argument_);
            TraceIfNeeded<Vector<String>>::Trace(visitor, callback_selectors_);
            TraceIfNeeded<FillLayer>::Trace(visitor, mask_);
            TraceIfNeeded<NinePieceImage>::Trace(visitor, mask_box_image_);
            TraceIfNeeded<StyleAnchorScope>::Trace(visitor, anchor_scope_);
            TraceIfNeeded<std::optional<StyleOverflowClipMargin>>::Trace(visitor, overflow_clip_margin_);
            TraceIfNeeded<std::optional<blink::PositionAreaOffsets>>::Trace(visitor, position_area_offsets_);
            TraceIfNeeded<std::optional<PhysicalOffset>>::Trace(visitor, anchor_center_offset_);
            visitor->Trace(position_anchor_);
            visitor->Trace(anchor_name_);
            visitor->Trace(container_name_);
            visitor->Trace(position_try_fallbacks_);
            visitor->Trace(view_transition_class_);
            visitor->Trace(view_transition_name_);
            visitor->Trace(document_rules_selectors_);
            visitor->Trace(paint_images_);
            visitor->Trace(non_inherited_variables_);
            TraceIfNeeded<std::optional<Length>>::Trace(visitor, masonry_slack_);
            TraceIfNeeded<StyleInitialLetter>::Trace(visitor, initial_letter_);
            TraceIfNeeded<gfx::SizeF>::Trace(visitor, page_size_);
            TraceIfNeeded<float>::Trace(visitor, popover_hide_delay_);
            TraceIfNeeded<float>::Trace(visitor, popover_show_delay_);
            TraceIfNeeded<float>::Trace(visitor, scroll_margin_bottom_);
            TraceIfNeeded<float>::Trace(visitor, scroll_margin_left_);
            TraceIfNeeded<float>::Trace(visitor, scroll_margin_right_);
            TraceIfNeeded<float>::Trace(visitor, scroll_margin_top_);
            TraceIfNeeded<int>::Trace(visitor, standard_line_clamp_);
            TraceIfNeeded<PositionArea>::Trace(visitor, position_area_);
        }

        bool operator==(const StyleRareNonInheritedUsageLessThan14PercentSubData& other) const
        {
            return (base::ValuesEquivalent(grid_data_, other.grid_data_) && base::ValuesEquivalent(forced_colors_data_, other.forced_colors_data_)
                && base::ValuesEquivalent(visited_data_, other.visited_data_) && base::ValuesEquivalent(masonry_data_, other.masonry_data_)
                && base::ValuesEquivalent(start_data_, other.start_data_) && base::ValuesEquivalent(timeline_data_, other.timeline_data_)
                && base::ValuesEquivalent(will_change_data_, other.will_change_data_) && base::ValuesEquivalent(math_data_, other.math_data_)
                && view_transition_group_ == other.view_transition_group_ && masonry_track_end_ == other.masonry_track_end_
                && masonry_track_start_ == other.masonry_track_start_ && display_layout_custom_name_ == other.display_layout_custom_name_
                && display_layout_custom_parent_name_ == other.display_layout_custom_parent_name_ && pseudo_argument_ == other.pseudo_argument_
                && base::ValuesEquivalent(object_view_box_, other.object_view_box_)
                && base::ValuesEquivalent(custom_highlight_names_, other.custom_highlight_names_)
                && base::ValuesEquivalent(counter_directives_, other.counter_directives_) && base::ValuesEquivalent(animations_, other.animations_)
                && base::ValuesEquivalent(transitions_, other.transitions_) && callback_selectors_ == other.callback_selectors_ && mask_ == other.mask_
                && mask_box_image_ == other.mask_box_image_ && anchor_scope_ == other.anchor_scope_ && overflow_clip_margin_ == other.overflow_clip_margin_
                && base::ValuesEquivalent(position_anchor_, other.position_anchor_) && base::ValuesEquivalent(anchor_name_, other.anchor_name_)
                && base::ValuesEquivalent(container_name_, other.container_name_)
                && base::ValuesEquivalent(position_try_fallbacks_, other.position_try_fallbacks_)
                && base::ValuesEquivalent(view_transition_class_, other.view_transition_class_)
                && base::ValuesEquivalent(view_transition_name_, other.view_transition_name_)
                && base::ValuesEquivalent(document_rules_selectors_, other.document_rules_selectors_)
                && base::ValuesEquivalent(non_inherited_variables_, other.non_inherited_variables_) && masonry_slack_ == other.masonry_slack_
                && initial_letter_ == other.initial_letter_ && page_size_ == other.page_size_ && popover_hide_delay_ == other.popover_hide_delay_
                && popover_show_delay_ == other.popover_show_delay_ && scroll_margin_bottom_ == other.scroll_margin_bottom_
                && scroll_margin_left_ == other.scroll_margin_left_ && scroll_margin_right_ == other.scroll_margin_right_
                && scroll_margin_top_ == other.scroll_margin_top_ && standard_line_clamp_ == other.standard_line_clamp_
                && position_area_ == other.position_area_ && effective_appearance_ == other.effective_appearance_ && container_type_ == other.container_type_
                && position_try_order_ == other.position_try_order_ && position_visibility_ == other.position_visibility_
                && reading_flow_ == other.reading_flow_ && inline_block_baseline_edge_ == other.inline_block_baseline_edge_
                && overscroll_behavior_x_ == other.overscroll_behavior_x_ && overscroll_behavior_y_ == other.overscroll_behavior_y_
                && page_size_type_ == other.page_size_type_ && scroll_marker_group_ == other.scroll_marker_group_ && scrollbar_width_ == other.scrollbar_width_
                && view_transition_capture_mode_ == other.view_transition_capture_mode_ && affected_by_css_function_ == other.affected_by_css_function_
                && align_content_block_center_ == other.align_content_block_center_ && can_affect_animations_ == other.can_affect_animations_
                && depends_on_scroll_state_container_queries_ == other.depends_on_scroll_state_container_queries_
                && depends_on_size_container_queries_ == other.depends_on_size_container_queries_
                && depends_on_style_container_queries_ == other.depends_on_style_container_queries_ && effective_z_index_zero_ == other.effective_z_index_zero_
                && element_is_view_transition_participant_ == other.element_is_view_transition_participant_
                && first_line_depends_on_size_container_queries_ == other.first_line_depends_on_size_container_queries_
                && forces_stacking_context_ == other.forces_stacking_context_ && has_auto_column_count_ == other.has_auto_column_count_
                && has_auto_column_width_ == other.has_auto_column_width_
                && has_current_backdrop_filter_animation_ == other.has_current_backdrop_filter_animation_
                && has_current_background_color_animation_ == other.has_current_background_color_animation_
                && has_current_filter_animation_ == other.has_current_filter_animation_
                && has_current_opacity_animation_ == other.has_current_opacity_animation_
                && has_current_rotate_animation_ == other.has_current_rotate_animation_ && has_current_scale_animation_ == other.has_current_scale_animation_
                && has_current_transform_animation_ == other.has_current_transform_animation_
                && has_current_translate_animation_ == other.has_current_translate_animation_
                && has_explicit_overflow_x_visible_ == other.has_explicit_overflow_x_visible_
                && has_explicit_overflow_y_visible_ == other.has_explicit_overflow_y_visible_ && is_secondary_body_element_ == other.is_secondary_body_element_
                && is_starting_style_ == other.is_starting_style_ && outline_style_is_auto_ == other.outline_style_is_auto_ && overlay_ == other.overlay_
                && requires_accelerated_compositing_for_external_reasons_ == other.requires_accelerated_compositing_for_external_reasons_
                && scroll_start_target_ == other.scroll_start_target_);
        }
        bool operator!=(const StyleRareNonInheritedUsageLessThan14PercentSubData& other) const
        {
            return !(*this == other);
        }

        Member<StyleGridData> grid_data_;
        Member<StyleForcedColorsData> forced_colors_data_;
        Member<StyleVisitedData> visited_data_;
        Member<StyleMasonryData> masonry_data_;
        Member<StyleStartData> start_data_;
        Member<StyleTimelineData> timeline_data_;
        Member<StyleWillChangeData> will_change_data_;
        Member<StyleMathData> math_data_;
        StyleViewTransitionGroup view_transition_group_;
        GridPosition masonry_track_end_;
        GridPosition masonry_track_start_;
        AtomicString display_layout_custom_name_;
        AtomicString display_layout_custom_parent_name_;
        AtomicString pseudo_argument_;
        scoped_refptr<BasicShape> object_view_box_;
        std::unique_ptr<HashSet<AtomicString>> custom_highlight_names_;
        std::unique_ptr<CounterDirectiveMap> counter_directives_;
        std::unique_ptr<CSSAnimationData> animations_;
        std::unique_ptr<CSSTransitionData> transitions_;
        Vector<String> callback_selectors_;
        FillLayer mask_;
        NinePieceImage mask_box_image_;
        StyleAnchorScope anchor_scope_;
        std::optional<StyleOverflowClipMargin> overflow_clip_margin_;
        std::optional<blink::PositionAreaOffsets> position_area_offsets_;
        std::optional<PhysicalOffset> anchor_center_offset_;
        Member<ScopedCSSName> position_anchor_;
        Member<ScopedCSSNameList> anchor_name_;
        Member<ScopedCSSNameList> container_name_;
        Member<PositionTryFallbacks> position_try_fallbacks_;
        Member<ScopedCSSNameList> view_transition_class_;
        Member<StyleViewTransitionName> view_transition_name_;
        Member<HeapHashSet<WeakMember<StyleRule>>> document_rules_selectors_;
        Member<PaintImages> paint_images_;
        Member<StyleNonInheritedVariables> non_inherited_variables_;
        std::optional<Length> masonry_slack_;
        StyleInitialLetter initial_letter_;
        gfx::SizeF page_size_;
        float popover_hide_delay_;
        float popover_show_delay_;
        float scroll_margin_bottom_;
        float scroll_margin_left_;
        float scroll_margin_right_;
        float scroll_margin_top_;
        int standard_line_clamp_;
        PositionArea position_area_;
        unsigned effective_appearance_ : 5; // ControlPart
        unsigned container_type_ : 3; // unsigned
        unsigned position_try_order_ : 3; // EPositionTryOrder
        unsigned position_visibility_ : 3; // PositionVisibility
        unsigned reading_flow_ : 3; // EReadingFlow
        unsigned inline_block_baseline_edge_ : 2; // EInlineBlockBaselineEdge
        unsigned overscroll_behavior_x_ : 2; // EOverscrollBehavior
        unsigned overscroll_behavior_y_ : 2; // EOverscrollBehavior
        unsigned page_size_type_ : 2; // PageSizeType
        unsigned scroll_marker_group_ : 2; // EScrollMarkerGroup
        unsigned scrollbar_width_ : 2; // EScrollbarWidth
        unsigned view_transition_capture_mode_ : 2; // StyleViewTransitionCaptureMode
        unsigned affected_by_css_function_ : 1; // bool
        unsigned align_content_block_center_ : 1; // bool
        unsigned can_affect_animations_ : 1; // bool
        unsigned depends_on_scroll_state_container_queries_ : 1; // bool
        unsigned depends_on_size_container_queries_ : 1; // bool
        unsigned depends_on_style_container_queries_ : 1; // bool
        unsigned effective_z_index_zero_ : 1; // bool
        unsigned element_is_view_transition_participant_ : 1; // bool
        unsigned first_line_depends_on_size_container_queries_ : 1; // bool
        unsigned forces_stacking_context_ : 1; // bool
        unsigned has_auto_column_count_ : 1; // bool
        unsigned has_auto_column_width_ : 1; // bool
        unsigned has_current_backdrop_filter_animation_ : 1; // bool
        unsigned has_current_background_color_animation_ : 1; // bool
        unsigned has_current_filter_animation_ : 1; // bool
        unsigned has_current_opacity_animation_ : 1; // bool
        unsigned has_current_rotate_animation_ : 1; // bool
        unsigned has_current_scale_animation_ : 1; // bool
        unsigned has_current_transform_animation_ : 1; // bool
        unsigned has_current_translate_animation_ : 1; // bool
        unsigned has_explicit_overflow_x_visible_ : 1; // bool
        unsigned has_explicit_overflow_y_visible_ : 1; // bool
        unsigned has_line_height_relative_units_ : 1; // bool
        unsigned has_non_ua_highlight_pseudo_styles_ : 1; // bool
        unsigned has_non_universal_highlight_pseudo_styles_ : 1; // bool
        unsigned highlights_depend_on_size_container_queries_ : 1; // bool
        unsigned inline_style_lost_cascade_ : 1; // bool
        unsigned is_running_backdrop_filter_animation_on_compositor_ : 1; // bool
        unsigned is_running_filter_animation_on_compositor_ : 1; // bool
        unsigned is_running_opacity_animation_on_compositor_ : 1; // bool
        unsigned is_running_rotate_animation_on_compositor_ : 1; // bool
        unsigned is_running_scale_animation_on_compositor_ : 1; // bool
        unsigned is_running_transform_animation_on_compositor_ : 1; // bool
        unsigned is_running_translate_animation_on_compositor_ : 1; // bool
        unsigned is_secondary_body_element_ : 1; // bool
        unsigned is_starting_style_ : 1; // bool
        unsigned outline_style_is_auto_ : 1; // bool
        unsigned overlay_ : 1; // EOverlay
        unsigned requires_accelerated_compositing_for_external_reasons_ : 1; // bool
        unsigned scroll_start_target_ : 1; // EScrollStartTarget
    };

    class StyleRareNonInheritedUsageLessThan100PercentData : public GarbageCollected<StyleRareNonInheritedUsageLessThan100PercentData> {
    public:
        explicit StyleRareNonInheritedUsageLessThan100PercentData();
        CORE_EXPORT StyleRareNonInheritedUsageLessThan100PercentData(const StyleRareNonInheritedUsageLessThan100PercentData&);

        static StyleRareNonInheritedUsageLessThan100PercentData* Create()
        {
            return MakeGarbageCollected<StyleRareNonInheritedUsageLessThan100PercentData>();
        }
        StyleRareNonInheritedUsageLessThan100PercentData* Copy() const
        {
            return MakeGarbageCollected<StyleRareNonInheritedUsageLessThan100PercentData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<NGGridTrackList>::Trace(visitor, grid_auto_columns_);
            TraceIfNeeded<NGGridTrackList>::Trace(visitor, grid_auto_rows_);
            TraceIfNeeded<FilterOperations>::Trace(visitor, backdrop_filter_);
            TraceIfNeeded<GridPosition>::Trace(visitor, grid_column_end_);
            TraceIfNeeded<GridPosition>::Trace(visitor, grid_column_start_);
            TraceIfNeeded<GridPosition>::Trace(visitor, grid_row_end_);
            TraceIfNeeded<GridPosition>::Trace(visitor, grid_row_start_);
            TraceIfNeeded<AtomicString>::Trace(visitor, page_);
            TraceIfNeeded<TextDecorationThickness>::Trace(visitor, text_decoration_thickness_);
            TraceIfNeeded<GapDataList<StyleColor>>::Trace(visitor, column_rule_color_);
            visitor->Trace(clip_path_);
            visitor->Trace(grid_template_areas_);
            visitor->Trace(offset_path_);
            visitor->Trace(rotate_);
            visitor->Trace(scale_);
            visitor->Trace(shape_outside_);
            visitor->Trace(translate_);
            TraceIfNeeded<std::optional<Length>>::Trace(visitor, column_gap_);
            TraceIfNeeded<std::optional<Length>>::Trace(visitor, row_gap_);
            TraceIfNeeded<StyleOffsetRotation>::Trace(visitor, offset_rotate_);
            TraceIfNeeded<LengthPoint>::Trace(visitor, object_position_);
            TraceIfNeeded<LengthPoint>::Trace(visitor, offset_anchor_);
            TraceIfNeeded<LengthPoint>::Trace(visitor, offset_position_);
            TraceIfNeeded<LengthPoint>::Trace(visitor, perspective_origin_);
            TraceIfNeeded<Length>::Trace(visitor, offset_distance_);
            TraceIfNeeded<Length>::Trace(visitor, scroll_padding_bottom_);
            TraceIfNeeded<Length>::Trace(visitor, scroll_padding_left_);
            TraceIfNeeded<Length>::Trace(visitor, scroll_padding_right_);
            TraceIfNeeded<Length>::Trace(visitor, scroll_padding_top_);
            TraceIfNeeded<Length>::Trace(visitor, shape_margin_);
            TraceIfNeeded<float>::Trace(visitor, column_width_);
            TraceIfNeeded<float>::Trace(visitor, perspective_);
            TraceIfNeeded<float>::Trace(visitor, shape_image_threshold_);
            TraceIfNeeded<cc::ScrollSnapType>::Trace(visitor, scroll_snap_type_);
            TraceIfNeeded<cc::ScrollSnapAlign>::Trace(visitor, scroll_snap_align_);
            TraceIfNeeded<StyleColor>::Trace(visitor, outline_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, text_decoration_color_);
            TraceIfNeeded<unsigned>::Trace(visitor, box_ordinal_group_);
            TraceIfNeeded<int>::Trace(visitor, column_rule_width_);
            TraceIfNeeded<unsigned short>::Trace(visitor, column_count_);
            TraceIfNeeded<StyleSelfAlignmentData>::Trace(visitor, justify_items_);
            TraceIfNeeded<StyleSelfAlignmentData>::Trace(visitor, justify_self_);
        }

        bool operator==(const StyleRareNonInheritedUsageLessThan100PercentData& other) const
        {
            return (grid_auto_columns_ == other.grid_auto_columns_ && grid_auto_rows_ == other.grid_auto_rows_ && backdrop_filter_ == other.backdrop_filter_
                && grid_column_end_ == other.grid_column_end_ && grid_column_start_ == other.grid_column_start_ && grid_row_end_ == other.grid_row_end_
                && grid_row_start_ == other.grid_row_start_ && page_ == other.page_ && base::ValuesEquivalent(box_reflect_, other.box_reflect_)
                && text_decoration_thickness_ == other.text_decoration_thickness_ && column_rule_color_ == other.column_rule_color_
                && base::ValuesEquivalent(clip_path_, other.clip_path_) && base::ValuesEquivalent(grid_template_areas_, other.grid_template_areas_)
                && base::ValuesEquivalent(offset_path_, other.offset_path_) && base::ValuesEquivalent(rotate_, other.rotate_)
                && base::ValuesEquivalent(scale_, other.scale_) && base::ValuesEquivalent(shape_outside_, other.shape_outside_)
                && base::ValuesEquivalent(translate_, other.translate_) && column_gap_ == other.column_gap_ && row_gap_ == other.row_gap_
                && offset_rotate_ == other.offset_rotate_ && object_position_ == other.object_position_ && offset_anchor_ == other.offset_anchor_
                && offset_position_ == other.offset_position_ && perspective_origin_ == other.perspective_origin_ && offset_distance_ == other.offset_distance_
                && scroll_padding_bottom_ == other.scroll_padding_bottom_ && scroll_padding_left_ == other.scroll_padding_left_
                && scroll_padding_right_ == other.scroll_padding_right_ && scroll_padding_top_ == other.scroll_padding_top_
                && shape_margin_ == other.shape_margin_ && column_width_ == other.column_width_ && perspective_ == other.perspective_
                && shape_image_threshold_ == other.shape_image_threshold_ && scroll_snap_type_ == other.scroll_snap_type_
                && scroll_snap_align_ == other.scroll_snap_align_ && outline_color_ == other.outline_color_
                && text_decoration_color_ == other.text_decoration_color_ && box_ordinal_group_ == other.box_ordinal_group_
                && column_rule_width_ == other.column_rule_width_ && column_count_ == other.column_count_ && justify_items_ == other.justify_items_
                && justify_self_ == other.justify_self_ && blend_mode_ == other.blend_mode_ && contain_ == other.contain_ && break_after_ == other.break_after_
                && break_before_ == other.break_before_ && column_rule_style_ == other.column_rule_style_ && grid_auto_flow_ == other.grid_auto_flow_
                && text_decoration_style_ == other.text_decoration_style_ && break_inside_ == other.break_inside_ && column_fill_ == other.column_fill_
                && draggable_region_mode_ == other.draggable_region_mode_ && page_orientation_ == other.page_orientation_
                && scroll_behavior_ == other.scroll_behavior_ && user_drag_ == other.user_drag_ && column_span_ == other.column_span_
                && isolation_ == other.isolation_ && transform_style_3d_ == other.transform_style_3d_);
        }
        bool operator!=(const StyleRareNonInheritedUsageLessThan100PercentData& other) const
        {
            return !(*this == other);
        }

        NGGridTrackList grid_auto_columns_;
        NGGridTrackList grid_auto_rows_;
        FilterOperations backdrop_filter_;
        GridPosition grid_column_end_;
        GridPosition grid_column_start_;
        GridPosition grid_row_end_;
        GridPosition grid_row_start_;
        AtomicString page_;
        scoped_refptr<StyleReflection> box_reflect_;
        TextDecorationThickness text_decoration_thickness_;
        GapDataList<StyleColor> column_rule_color_;
        Member<ClipPathOperation> clip_path_;
        Member<ComputedGridTemplateAreas> grid_template_areas_;
        Member<OffsetPathOperation> offset_path_;
        Member<RotateTransformOperation> rotate_;
        Member<ScaleTransformOperation> scale_;
        Member<ShapeValue> shape_outside_;
        Member<TranslateTransformOperation> translate_;
        std::optional<Length> column_gap_;
        std::optional<Length> row_gap_;
        StyleOffsetRotation offset_rotate_;
        LengthPoint object_position_;
        LengthPoint offset_anchor_;
        LengthPoint offset_position_;
        LengthPoint perspective_origin_;
        Length offset_distance_;
        Length scroll_padding_bottom_;
        Length scroll_padding_left_;
        Length scroll_padding_right_;
        Length scroll_padding_top_;
        Length shape_margin_;
        float column_width_;
        float perspective_;
        float shape_image_threshold_;
        cc::ScrollSnapType scroll_snap_type_;
        cc::ScrollSnapAlign scroll_snap_align_;
        StyleColor outline_color_;
        StyleColor text_decoration_color_;
        unsigned box_ordinal_group_;
        int column_rule_width_;
        unsigned short column_count_;
        StyleSelfAlignmentData justify_items_;
        StyleSelfAlignmentData justify_self_;
        unsigned blend_mode_ : 5; // BlendMode
        unsigned contain_ : 5; // unsigned
        unsigned break_after_ : 4; // EBreakBetween
        unsigned break_before_ : 4; // EBreakBetween
        unsigned column_rule_style_ : 4; // EBorderStyle
        unsigned grid_auto_flow_ : 4; // GridAutoFlow
        unsigned text_decoration_style_ : 3; // ETextDecorationStyle
        unsigned break_inside_ : 2; // EBreakInside
        unsigned column_fill_ : 1; // EColumnFill
        unsigned draggable_region_mode_ : 2; // EDraggableRegionMode
        unsigned page_orientation_ : 2; // PageOrientation
        unsigned scroll_behavior_ : 2; // mojom::blink::ScrollBehavior
        unsigned user_drag_ : 2; // EUserDrag
        unsigned column_span_ : 1; // EColumnSpan
        unsigned isolation_ : 1; // EIsolation
        unsigned transform_style_3d_ : 1; // ETransformStyle3D
    };

    class StyleRareNonInheritedUsageLessThan22PercentData : public GarbageCollected<StyleRareNonInheritedUsageLessThan22PercentData> {
    public:
        explicit StyleRareNonInheritedUsageLessThan22PercentData();
        CORE_EXPORT StyleRareNonInheritedUsageLessThan22PercentData(const StyleRareNonInheritedUsageLessThan22PercentData&);

        static StyleRareNonInheritedUsageLessThan22PercentData* Create()
        {
            return MakeGarbageCollected<StyleRareNonInheritedUsageLessThan22PercentData>();
        }
        StyleRareNonInheritedUsageLessThan22PercentData* Copy() const
        {
            return MakeGarbageCollected<StyleRareNonInheritedUsageLessThan22PercentData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            visitor->Trace(rare_non_inherited_usage_less_than_100_percent_data_);
            TraceIfNeeded<FilterOperations>::Trace(visitor, filter_);
            TraceIfNeeded<Length>::Trace(visitor, flex_basis_);
            TraceIfNeeded<float>::Trace(visitor, flex_grow_);
            TraceIfNeeded<float>::Trace(visitor, flex_shrink_);
            TraceIfNeeded<float>::Trace(visitor, box_flex_);
            TraceIfNeeded<LayoutUnit>::Trace(visitor, outline_offset_);
            TraceIfNeeded<int>::Trace(visitor, order_);
            TraceIfNeeded<int>::Trace(visitor, outline_width_);
            TraceIfNeeded<int>::Trace(visitor, webkit_line_clamp_);
            TraceIfNeeded<StyleSelfAlignmentData>::Trace(visitor, align_self_);
            TraceIfNeeded<StyleContentAlignmentData>::Trace(visitor, align_content_);
        }

        bool operator==(const StyleRareNonInheritedUsageLessThan22PercentData& other) const
        {
            return (base::ValuesEquivalent(rare_non_inherited_usage_less_than_100_percent_data_, other.rare_non_inherited_usage_less_than_100_percent_data_)
                && filter_ == other.filter_ && flex_basis_ == other.flex_basis_ && flex_grow_ == other.flex_grow_ && flex_shrink_ == other.flex_shrink_
                && box_flex_ == other.box_flex_ && outline_offset_ == other.outline_offset_ && order_ == other.order_ && outline_width_ == other.outline_width_
                && webkit_line_clamp_ == other.webkit_line_clamp_ && align_self_ == other.align_self_ && align_content_ == other.align_content_
                && touch_action_ == other.touch_action_ && outline_style_ == other.outline_style_ && box_align_ == other.box_align_
                && object_fit_ == other.object_fit_ && resize_ == other.resize_ && box_pack_ == other.box_pack_
                && backface_visibility_ == other.backface_visibility_ && box_orient_ == other.box_orient_);
        }
        bool operator!=(const StyleRareNonInheritedUsageLessThan22PercentData& other) const
        {
            return !(*this == other);
        }

        Member<StyleRareNonInheritedUsageLessThan100PercentData> rare_non_inherited_usage_less_than_100_percent_data_;
        FilterOperations filter_;
        Length flex_basis_;
        float flex_grow_;
        float flex_shrink_;
        float box_flex_;
        LayoutUnit outline_offset_;
        int order_;
        int outline_width_;
        int webkit_line_clamp_;
        StyleSelfAlignmentData align_self_;
        StyleContentAlignmentData align_content_;
        unsigned touch_action_ : 8; // TouchAction
        unsigned outline_style_ : 4; // EBorderStyle
        unsigned box_align_ : 3; // EBoxAlignment
        unsigned object_fit_ : 3; // EObjectFit
        unsigned resize_ : 3; // EResize
        unsigned box_pack_ : 2; // EBoxPack
        unsigned backface_visibility_ : 1; // EBackfaceVisibility
        unsigned box_orient_ : 1; // EBoxOrient
    };

    class StyleRareNonInheritedUsageLessThan14PercentData : public GarbageCollected<StyleRareNonInheritedUsageLessThan14PercentData> {
    public:
        explicit StyleRareNonInheritedUsageLessThan14PercentData();
        CORE_EXPORT StyleRareNonInheritedUsageLessThan14PercentData(const StyleRareNonInheritedUsageLessThan14PercentData&);

        static StyleRareNonInheritedUsageLessThan14PercentData* Create()
        {
            return MakeGarbageCollected<StyleRareNonInheritedUsageLessThan14PercentData>();
        }
        StyleRareNonInheritedUsageLessThan14PercentData* Copy() const
        {
            return MakeGarbageCollected<StyleRareNonInheritedUsageLessThan14PercentData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            visitor->Trace(rare_non_inherited_usage_less_than_14_percent_sub_data_);
            visitor->Trace(rare_non_inherited_usage_less_than_22_percent_data_);
            TraceIfNeeded<TransformOperations>::Trace(visitor, transform_);
            visitor->Trace(box_shadow_);
            visitor->Trace(content_);
            TraceIfNeeded<float>::Trace(visitor, opacity_);
            TraceIfNeeded<StyleSelfAlignmentData>::Trace(visitor, align_items_);
            TraceIfNeeded<StyleContentAlignmentData>::Trace(visitor, justify_content_);
        }

        bool operator==(const StyleRareNonInheritedUsageLessThan14PercentData& other) const
        {
            return (
                base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_sub_data_, other.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                && base::ValuesEquivalent(rare_non_inherited_usage_less_than_22_percent_data_, other.rare_non_inherited_usage_less_than_22_percent_data_)
                && transform_ == other.transform_ && base::ValuesEquivalent(box_shadow_, other.box_shadow_) && base::ValuesEquivalent(content_, other.content_)
                && opacity_ == other.opacity_ && align_items_ == other.align_items_ && justify_content_ == other.justify_content_
                && appearance_ == other.appearance_ && flex_direction_ == other.flex_direction_ && flex_wrap_ == other.flex_wrap_
                && text_overflow_ == other.text_overflow_);
        }
        bool operator!=(const StyleRareNonInheritedUsageLessThan14PercentData& other) const
        {
            return !(*this == other);
        }

        Member<StyleRareNonInheritedUsageLessThan14PercentSubData> rare_non_inherited_usage_less_than_14_percent_sub_data_;
        Member<StyleRareNonInheritedUsageLessThan22PercentData> rare_non_inherited_usage_less_than_22_percent_data_;
        TransformOperations transform_;
        Member<ShadowList> box_shadow_;
        Member<ContentData> content_;
        float opacity_;
        StyleSelfAlignmentData align_items_;
        StyleContentAlignmentData justify_content_;
        unsigned appearance_ : 5; // ControlPart
        unsigned flex_direction_ : 2; // EFlexDirection
        unsigned flex_wrap_ : 2; // EFlexWrap
        unsigned text_overflow_ : 1; // ETextOverflow
    };

    class StyleInheritedData : public GarbageCollected<StyleInheritedData> {
    public:
        explicit StyleInheritedData();
        CORE_EXPORT StyleInheritedData(const StyleInheritedData&);

        static StyleInheritedData* Create()
        {
            return MakeGarbageCollected<StyleInheritedData>();
        }
        StyleInheritedData* Copy() const
        {
            return MakeGarbageCollected<StyleInheritedData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            visitor->Trace(inherited_variables_);
            TraceIfNeeded<Length>::Trace(visitor, line_height_);
            TraceIfNeeded<float>::Trace(visitor, text_autosizing_multiplier_);
            TraceIfNeeded<StyleColor>::Trace(visitor, color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, internal_visited_color_);
            TraceIfNeeded<short>::Trace(visitor, horizontal_border_spacing_);
            TraceIfNeeded<short>::Trace(visitor, vertical_border_spacing_);
        }

        bool operator==(const StyleInheritedData& other) const
        {
            return (base::ValuesEquivalent(inherited_variables_, other.inherited_variables_) && line_height_ == other.line_height_
                && text_autosizing_multiplier_ == other.text_autosizing_multiplier_ && color_ == other.color_
                && internal_visited_color_ == other.internal_visited_color_ && horizontal_border_spacing_ == other.horizontal_border_spacing_
                && vertical_border_spacing_ == other.vertical_border_spacing_ && color_is_current_color_ == other.color_is_current_color_
                && in_forced_colors_mode_ == other.in_forced_colors_mode_
                && internal_visited_color_is_current_color_ == other.internal_visited_color_is_current_color_);
        }
        bool operator!=(const StyleInheritedData& other) const
        {
            return !(*this == other);
        }

        Member<StyleInheritedVariables> inherited_variables_;
        Length line_height_;
        float text_autosizing_multiplier_;
        StyleColor color_;
        StyleColor internal_visited_color_;
        short horizontal_border_spacing_;
        short vertical_border_spacing_;
        unsigned color_is_current_color_ : 1; // bool
        unsigned in_forced_colors_mode_ : 1; // bool
        unsigned internal_visited_color_is_current_color_ : 1; // bool
    };

    class StyleVisualData : public GarbageCollected<StyleVisualData> {
    public:
        explicit StyleVisualData();
        CORE_EXPORT StyleVisualData(const StyleVisualData&);

        static StyleVisualData* Create()
        {
            return MakeGarbageCollected<StyleVisualData>();
        }
        StyleVisualData* Copy() const
        {
            return MakeGarbageCollected<StyleVisualData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<LengthBox>::Trace(visitor, clip_);
            TraceIfNeeded<float>::Trace(visitor, zoom_);
        }

        bool operator==(const StyleVisualData& other) const
        {
            return (base::ValuesEquivalent(base_text_decoration_data_, other.base_text_decoration_data_) && clip_ == other.clip_ && zoom_ == other.zoom_
                && text_decoration_line_ == other.text_decoration_line_ && field_sizing_ == other.field_sizing_ && has_auto_clip_ == other.has_auto_clip_
                && has_clip_path_ == other.has_clip_path_);
        }
        bool operator!=(const StyleVisualData& other) const
        {
            return !(*this == other);
        }

        scoped_refptr<base::RefCountedData<Vector<AppliedTextDecoration, 1>>> base_text_decoration_data_;
        LengthBox clip_;
        float zoom_;
        unsigned text_decoration_line_ : 6; // TextDecorationLine
        unsigned field_sizing_ : 1; // EFieldSizing
        unsigned has_auto_clip_ : 1; // bool
        unsigned has_clip_path_ : 1; // bool
    };

    class StyleMiscData : public GarbageCollected<StyleMiscData> {
    public:
        explicit StyleMiscData();
        CORE_EXPORT StyleMiscData(const StyleMiscData&);

        static StyleMiscData* Create()
        {
            return MakeGarbageCollected<StyleMiscData>();
        }
        StyleMiscData* Copy() const
        {
            return MakeGarbageCollected<StyleMiscData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<Length>::Trace(visitor, baseline_shift_);
            TraceIfNeeded<float>::Trace(visitor, flood_opacity_);
            TraceIfNeeded<StyleColor>::Trace(visitor, flood_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, lighting_color_);
        }

        bool operator==(const StyleMiscData& other) const
        {
            return (baseline_shift_ == other.baseline_shift_ && flood_opacity_ == other.flood_opacity_ && flood_color_ == other.flood_color_
                && lighting_color_ == other.lighting_color_ && baseline_shift_type_ == other.baseline_shift_type_);
        }
        bool operator!=(const StyleMiscData& other) const
        {
            return !(*this == other);
        }

        Length baseline_shift_;
        float flood_opacity_;
        StyleColor flood_color_;
        StyleColor lighting_color_;
        unsigned baseline_shift_type_ : 2; // EBaselineShiftType
    };

    class StyleGeometryData : public GarbageCollected<StyleGeometryData> {
    public:
        explicit StyleGeometryData();
        CORE_EXPORT StyleGeometryData(const StyleGeometryData&);

        static StyleGeometryData* Create()
        {
            return MakeGarbageCollected<StyleGeometryData>();
        }
        StyleGeometryData* Copy() const
        {
            return MakeGarbageCollected<StyleGeometryData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<Length>::Trace(visitor, cx_);
            TraceIfNeeded<Length>::Trace(visitor, cy_);
            TraceIfNeeded<Length>::Trace(visitor, r_);
            TraceIfNeeded<Length>::Trace(visitor, rx_);
            TraceIfNeeded<Length>::Trace(visitor, ry_);
            TraceIfNeeded<Length>::Trace(visitor, x_);
            TraceIfNeeded<Length>::Trace(visitor, y_);
        }

        bool operator==(const StyleGeometryData& other) const
        {
            return (base::ValuesEquivalent(d_, other.d_) && cx_ == other.cx_ && cy_ == other.cy_ && r_ == other.r_ && rx_ == other.rx_ && ry_ == other.ry_
                && x_ == other.x_ && y_ == other.y_);
        }
        bool operator!=(const StyleGeometryData& other) const
        {
            return !(*this == other);
        }

        scoped_refptr<StylePath> d_;
        Length cx_;
        Length cy_;
        Length r_;
        Length rx_;
        Length ry_;
        Length x_;
        Length y_;
    };

    class StyleFillData : public GarbageCollected<StyleFillData> {
    public:
        explicit StyleFillData();
        CORE_EXPORT StyleFillData(const StyleFillData&);

        static StyleFillData* Create()
        {
            return MakeGarbageCollected<StyleFillData>();
        }
        StyleFillData* Copy() const
        {
            return MakeGarbageCollected<StyleFillData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<SVGPaint>::Trace(visitor, fill_paint_);
            TraceIfNeeded<SVGPaint>::Trace(visitor, internal_visited_fill_paint_);
            TraceIfNeeded<float>::Trace(visitor, fill_opacity_);
        }

        bool operator==(const StyleFillData& other) const
        {
            return (
                fill_paint_ == other.fill_paint_ && internal_visited_fill_paint_ == other.internal_visited_fill_paint_ && fill_opacity_ == other.fill_opacity_);
        }
        bool operator!=(const StyleFillData& other) const
        {
            return !(*this == other);
        }

        SVGPaint fill_paint_;
        SVGPaint internal_visited_fill_paint_;
        float fill_opacity_;
    };

    class StyleStrokeData : public GarbageCollected<StyleStrokeData> {
    public:
        explicit StyleStrokeData();
        CORE_EXPORT StyleStrokeData(const StyleStrokeData&);

        static StyleStrokeData* Create()
        {
            return MakeGarbageCollected<StyleStrokeData>();
        }
        StyleStrokeData* Copy() const
        {
            return MakeGarbageCollected<StyleStrokeData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<SVGPaint>::Trace(visitor, internal_visited_stroke_paint_);
            TraceIfNeeded<SVGPaint>::Trace(visitor, stroke_paint_);
            TraceIfNeeded<Length>::Trace(visitor, stroke_dash_offset_);
            TraceIfNeeded<UnzoomedLength>::Trace(visitor, stroke_width_);
            TraceIfNeeded<float>::Trace(visitor, stroke_miter_limit_);
            TraceIfNeeded<float>::Trace(visitor, stroke_opacity_);
        }

        bool operator==(const StyleStrokeData& other) const
        {
            return (base::ValuesEquivalent(stroke_dash_array_, other.stroke_dash_array_)
                && internal_visited_stroke_paint_ == other.internal_visited_stroke_paint_ && stroke_paint_ == other.stroke_paint_
                && stroke_dash_offset_ == other.stroke_dash_offset_ && stroke_width_ == other.stroke_width_ && stroke_miter_limit_ == other.stroke_miter_limit_
                && stroke_opacity_ == other.stroke_opacity_ && cap_style_ == other.cap_style_ && join_style_ == other.join_style_);
        }
        bool operator!=(const StyleStrokeData& other) const
        {
            return !(*this == other);
        }

        scoped_refptr<SVGDashArray> stroke_dash_array_;
        SVGPaint internal_visited_stroke_paint_;
        SVGPaint stroke_paint_;
        Length stroke_dash_offset_;
        UnzoomedLength stroke_width_;
        float stroke_miter_limit_;
        float stroke_opacity_;
        unsigned cap_style_ : 2; // LineCap
        unsigned join_style_ : 2; // LineJoin
    };

    class StyleInheritedResourcesData : public GarbageCollected<StyleInheritedResourcesData> {
    public:
        explicit StyleInheritedResourcesData();
        CORE_EXPORT StyleInheritedResourcesData(const StyleInheritedResourcesData&);

        static StyleInheritedResourcesData* Create()
        {
            return MakeGarbageCollected<StyleInheritedResourcesData>();
        }
        StyleInheritedResourcesData* Copy() const
        {
            return MakeGarbageCollected<StyleInheritedResourcesData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            visitor->Trace(marker_end_resource_);
            visitor->Trace(marker_mid_resource_);
            visitor->Trace(marker_start_resource_);
        }

        bool operator==(const StyleInheritedResourcesData& other) const
        {
            return (base::ValuesEquivalent(marker_end_resource_, other.marker_end_resource_)
                && base::ValuesEquivalent(marker_mid_resource_, other.marker_mid_resource_)
                && base::ValuesEquivalent(marker_start_resource_, other.marker_start_resource_));
        }
        bool operator!=(const StyleInheritedResourcesData& other) const
        {
            return !(*this == other);
        }

        Member<StyleSVGResource> marker_end_resource_;
        Member<StyleSVGResource> marker_mid_resource_;
        Member<StyleSVGResource> marker_start_resource_;
    };

    class StyleStopData : public GarbageCollected<StyleStopData> {
    public:
        explicit StyleStopData();
        CORE_EXPORT StyleStopData(const StyleStopData&);

        static StyleStopData* Create()
        {
            return MakeGarbageCollected<StyleStopData>();
        }
        StyleStopData* Copy() const
        {
            return MakeGarbageCollected<StyleStopData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<float>::Trace(visitor, stop_opacity_);
            TraceIfNeeded<StyleColor>::Trace(visitor, stop_color_);
        }

        bool operator==(const StyleStopData& other) const
        {
            return (stop_opacity_ == other.stop_opacity_ && stop_color_ == other.stop_color_);
        }
        bool operator!=(const StyleStopData& other) const
        {
            return !(*this == other);
        }

        float stop_opacity_;
        StyleColor stop_color_;
    };

    class StyleSVGData : public GarbageCollected<StyleSVGData> {
    public:
        explicit StyleSVGData();
        CORE_EXPORT StyleSVGData(const StyleSVGData&);

        static StyleSVGData* Create()
        {
            return MakeGarbageCollected<StyleSVGData>();
        }
        StyleSVGData* Copy() const
        {
            return MakeGarbageCollected<StyleSVGData>(*this);
        }

        // Used when constructing ComputedStyleBase, since this group contains
        // both inherited and non-inherited members.
        CORE_EXPORT StyleSVGData(const StyleSVGData& source_for_noninherited, const StyleSVGData& parent_style)
            : misc_data_(source_for_noninherited.misc_data_)
            , geometry_data_(source_for_noninherited.geometry_data_)
            , fill_data_(parent_style.fill_data_)
            , stroke_data_(parent_style.stroke_data_)
            , inherited_resources_data_(parent_style.inherited_resources_data_)
            , stop_data_(source_for_noninherited.stop_data_)
            , transform_origin_(source_for_noninherited.transform_origin_)
            , alignment_baseline_(source_for_noninherited.alignment_baseline_)
            , css_dominant_baseline_(parent_style.css_dominant_baseline_)
            , dominant_baseline_(parent_style.dominant_baseline_)
            , paint_order_(parent_style.paint_order_)
            , buffered_rendering_(source_for_noninherited.buffered_rendering_)
            , color_interpolation_(parent_style.color_interpolation_)
            , color_interpolation_filters_(parent_style.color_interpolation_filters_)
            , color_rendering_(parent_style.color_rendering_)
            , shape_rendering_(parent_style.shape_rendering_)
            , text_anchor_(parent_style.text_anchor_)
            , clip_rule_(parent_style.clip_rule_)
            , fill_rule_(parent_style.fill_rule_)
            , mask_type_(source_for_noninherited.mask_type_)
            , vector_effect_(source_for_noninherited.vector_effect_)
        {
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            visitor->Trace(misc_data_);
            visitor->Trace(geometry_data_);
            visitor->Trace(fill_data_);
            visitor->Trace(stroke_data_);
            visitor->Trace(inherited_resources_data_);
            visitor->Trace(stop_data_);
            TraceIfNeeded<TransformOrigin>::Trace(visitor, transform_origin_);
        }

        bool operator==(const StyleSVGData& other) const
        {
            return (base::ValuesEquivalent(misc_data_, other.misc_data_) && base::ValuesEquivalent(geometry_data_, other.geometry_data_)
                && base::ValuesEquivalent(fill_data_, other.fill_data_) && base::ValuesEquivalent(stroke_data_, other.stroke_data_)
                && base::ValuesEquivalent(inherited_resources_data_, other.inherited_resources_data_) && base::ValuesEquivalent(stop_data_, other.stop_data_)
                && transform_origin_ == other.transform_origin_ && alignment_baseline_ == other.alignment_baseline_
                && css_dominant_baseline_ == other.css_dominant_baseline_ && dominant_baseline_ == other.dominant_baseline_
                && paint_order_ == other.paint_order_ && buffered_rendering_ == other.buffered_rendering_ && color_interpolation_ == other.color_interpolation_
                && color_interpolation_filters_ == other.color_interpolation_filters_ && color_rendering_ == other.color_rendering_
                && shape_rendering_ == other.shape_rendering_ && text_anchor_ == other.text_anchor_ && clip_rule_ == other.clip_rule_
                && fill_rule_ == other.fill_rule_ && mask_type_ == other.mask_type_ && vector_effect_ == other.vector_effect_);
        }
        bool operator!=(const StyleSVGData& other) const
        {
            return !(*this == other);
        }

        Member<StyleMiscData> misc_data_;
        Member<StyleGeometryData> geometry_data_;
        Member<StyleFillData> fill_data_;
        Member<StyleStrokeData> stroke_data_;
        Member<StyleInheritedResourcesData> inherited_resources_data_;
        Member<StyleStopData> stop_data_;
        TransformOrigin transform_origin_;
        unsigned alignment_baseline_ : 4; // EAlignmentBaseline
        unsigned css_dominant_baseline_ : 4; // EDominantBaseline
        unsigned dominant_baseline_ : 4; // EDominantBaseline
        unsigned paint_order_ : 3; // EPaintOrder
        unsigned buffered_rendering_ : 2; // EBufferedRendering
        unsigned color_interpolation_ : 2; // EColorInterpolation
        unsigned color_interpolation_filters_ : 2; // EColorInterpolation
        unsigned color_rendering_ : 2; // EColorRendering
        unsigned shape_rendering_ : 2; // EShapeRendering
        unsigned text_anchor_ : 2; // ETextAnchor
        unsigned clip_rule_ : 1; // WindRule
        unsigned fill_rule_ : 1; // WindRule
        unsigned mask_type_ : 1; // EMaskType
        unsigned vector_effect_ : 1; // EVectorEffect
    };

    class StyleSurroundData : public GarbageCollected<StyleSurroundData> {
    public:
        explicit StyleSurroundData();
        CORE_EXPORT StyleSurroundData(const StyleSurroundData&);

        static StyleSurroundData* Create()
        {
            return MakeGarbageCollected<StyleSurroundData>();
        }
        StyleSurroundData* Copy() const
        {
            return MakeGarbageCollected<StyleSurroundData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<NinePieceImage>::Trace(visitor, border_image_);
            TraceIfNeeded<StyleAspectRatio>::Trace(visitor, aspect_ratio_);
            TraceIfNeeded<StyleIntrinsicLength>::Trace(visitor, contain_intrinsic_height_);
            TraceIfNeeded<StyleIntrinsicLength>::Trace(visitor, contain_intrinsic_width_);
            TraceIfNeeded<LengthSize>::Trace(visitor, border_bottom_left_radius_);
            TraceIfNeeded<LengthSize>::Trace(visitor, border_bottom_right_radius_);
            TraceIfNeeded<LengthSize>::Trace(visitor, border_top_left_radius_);
            TraceIfNeeded<LengthSize>::Trace(visitor, border_top_right_radius_);
            TraceIfNeeded<Length>::Trace(visitor, bottom_);
            TraceIfNeeded<Length>::Trace(visitor, left_);
            TraceIfNeeded<Length>::Trace(visitor, right_);
            TraceIfNeeded<Length>::Trace(visitor, top_);
            TraceIfNeeded<StyleColor>::Trace(visitor, border_bottom_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, border_left_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, border_right_color_);
            TraceIfNeeded<StyleColor>::Trace(visitor, border_top_color_);
        }

        bool operator==(const StyleSurroundData& other) const
        {
            return (border_image_ == other.border_image_ && aspect_ratio_ == other.aspect_ratio_ && contain_intrinsic_height_ == other.contain_intrinsic_height_
                && contain_intrinsic_width_ == other.contain_intrinsic_width_ && border_bottom_left_radius_ == other.border_bottom_left_radius_
                && border_bottom_right_radius_ == other.border_bottom_right_radius_ && border_top_left_radius_ == other.border_top_left_radius_
                && border_top_right_radius_ == other.border_top_right_radius_ && bottom_ == other.bottom_ && left_ == other.left_ && right_ == other.right_
                && top_ == other.top_ && border_bottom_color_ == other.border_bottom_color_ && border_left_color_ == other.border_left_color_
                && border_right_color_ == other.border_right_color_ && border_top_color_ == other.border_top_color_
                && has_anchor_evaluator_ == other.has_anchor_evaluator_);
        }
        bool operator!=(const StyleSurroundData& other) const
        {
            return !(*this == other);
        }

        NinePieceImage border_image_;
        StyleAspectRatio aspect_ratio_;
        StyleIntrinsicLength contain_intrinsic_height_;
        StyleIntrinsicLength contain_intrinsic_width_;
        LengthSize border_bottom_left_radius_;
        LengthSize border_bottom_right_radius_;
        LengthSize border_top_left_radius_;
        LengthSize border_top_right_radius_;
        Length bottom_;
        Length left_;
        Length right_;
        Length top_;
        StyleColor border_bottom_color_;
        StyleColor border_left_color_;
        StyleColor border_right_color_;
        StyleColor border_top_color_;
        unsigned has_anchor_evaluator_ : 1; // bool
        unsigned has_anchor_functions_ : 1; // bool
        unsigned may_have_margin_ : 1; // bool
        unsigned may_have_padding_ : 1; // bool
    };

    class StyleBackgroundData : public GarbageCollected<StyleBackgroundData> {
    public:
        explicit StyleBackgroundData();
        CORE_EXPORT StyleBackgroundData(const StyleBackgroundData&);

        static StyleBackgroundData* Create()
        {
            return MakeGarbageCollected<StyleBackgroundData>();
        }
        StyleBackgroundData* Copy() const
        {
            return MakeGarbageCollected<StyleBackgroundData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<FillLayer>::Trace(visitor, background_);
            TraceIfNeeded<StyleColor>::Trace(visitor, background_color_);
        }

        bool operator==(const StyleBackgroundData& other) const
        {
            return (background_ == other.background_ && background_color_ == other.background_color_);
        }
        bool operator!=(const StyleBackgroundData& other) const
        {
            return !(*this == other);
        }

        FillLayer background_;
        StyleColor background_color_;
    };

    class StyleBoxData : public GarbageCollected<StyleBoxData> {
    public:
        explicit StyleBoxData();
        CORE_EXPORT StyleBoxData(const StyleBoxData&);

        static StyleBoxData* Create()
        {
            return MakeGarbageCollected<StyleBoxData>();
        }
        StyleBoxData* Copy() const
        {
            return MakeGarbageCollected<StyleBoxData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<Length>::Trace(visitor, height_);
            TraceIfNeeded<Length>::Trace(visitor, margin_bottom_);
            TraceIfNeeded<Length>::Trace(visitor, margin_left_);
            TraceIfNeeded<Length>::Trace(visitor, margin_right_);
            TraceIfNeeded<Length>::Trace(visitor, margin_top_);
            TraceIfNeeded<Length>::Trace(visitor, max_height_);
            TraceIfNeeded<Length>::Trace(visitor, max_width_);
            TraceIfNeeded<Length>::Trace(visitor, min_height_);
            TraceIfNeeded<Length>::Trace(visitor, min_width_);
            TraceIfNeeded<Length>::Trace(visitor, padding_bottom_);
            TraceIfNeeded<Length>::Trace(visitor, padding_left_);
            TraceIfNeeded<Length>::Trace(visitor, padding_right_);
            TraceIfNeeded<Length>::Trace(visitor, padding_top_);
            TraceIfNeeded<Length>::Trace(visitor, width_);
            TraceIfNeeded<Length>::Trace(visitor, vertical_align_length_);
            TraceIfNeeded<int>::Trace(visitor, border_bottom_width_);
            TraceIfNeeded<int>::Trace(visitor, border_left_width_);
            TraceIfNeeded<int>::Trace(visitor, border_right_width_);
            TraceIfNeeded<int>::Trace(visitor, border_top_width_);
            TraceIfNeeded<int>::Trace(visitor, z_index_);
        }

        bool operator==(const StyleBoxData& other) const
        {
            return (height_ == other.height_ && margin_bottom_ == other.margin_bottom_ && margin_left_ == other.margin_left_
                && margin_right_ == other.margin_right_ && margin_top_ == other.margin_top_ && max_height_ == other.max_height_
                && max_width_ == other.max_width_ && min_height_ == other.min_height_ && min_width_ == other.min_width_
                && padding_bottom_ == other.padding_bottom_ && padding_left_ == other.padding_left_ && padding_right_ == other.padding_right_
                && padding_top_ == other.padding_top_ && width_ == other.width_ && vertical_align_length_ == other.vertical_align_length_
                && border_bottom_width_ == other.border_bottom_width_ && border_left_width_ == other.border_left_width_
                && border_right_width_ == other.border_right_width_ && border_top_width_ == other.border_top_width_ && z_index_ == other.z_index_
                && border_bottom_style_ == other.border_bottom_style_ && border_left_style_ == other.border_left_style_
                && border_right_style_ == other.border_right_style_ && border_top_style_ == other.border_top_style_
                && baseline_source_ == other.baseline_source_ && text_box_trim_ == other.text_box_trim_ && box_decoration_break_ == other.box_decoration_break_
                && has_auto_standard_line_clamp_ == other.has_auto_standard_line_clamp_ && has_auto_z_index_ == other.has_auto_z_index_);
        }
        bool operator!=(const StyleBoxData& other) const
        {
            return !(*this == other);
        }

        Length height_;
        Length margin_bottom_;
        Length margin_left_;
        Length margin_right_;
        Length margin_top_;
        Length max_height_;
        Length max_width_;
        Length min_height_;
        Length min_width_;
        Length padding_bottom_;
        Length padding_left_;
        Length padding_right_;
        Length padding_top_;
        Length width_;
        Length vertical_align_length_;
        int border_bottom_width_;
        int border_left_width_;
        int border_right_width_;
        int border_top_width_;
        int z_index_;
        unsigned border_bottom_style_ : 4; // EBorderStyle
        unsigned border_left_style_ : 4; // EBorderStyle
        unsigned border_right_style_ : 4; // EBorderStyle
        unsigned border_top_style_ : 4; // EBorderStyle
        unsigned baseline_source_ : 2; // EBaselineSource
        unsigned text_box_trim_ : 2; // ETextBoxTrim
        unsigned box_decoration_break_ : 1; // EBoxDecorationBreak
        unsigned has_auto_standard_line_clamp_ : 1; // bool
        unsigned has_auto_z_index_ : 1; // bool
    };

    class StyleFontData : public GarbageCollected<StyleFontData> {
    public:
        explicit StyleFontData();
        CORE_EXPORT StyleFontData(const StyleFontData&);

        static StyleFontData* Create()
        {
            return MakeGarbageCollected<StyleFontData>();
        }
        StyleFontData* Copy() const
        {
            return MakeGarbageCollected<StyleFontData>(*this);
        }

        CORE_EXPORT void Trace(Visitor* visitor) const
        {
            TraceIfNeeded<Font>::Trace(visitor, font_);
        }

        bool operator==(const StyleFontData& other) const
        {
            return (font_ == other.font_);
        }
        bool operator!=(const StyleFontData& other) const
        {
            return !(*this == other);
        }

        Font font_;
    };

protected:
    // Constructor and destructor are protected so that only the parent class ComputedStyle
    // can instantiate this class.
    ComputedStyleBase();
    ComputedStyleBase(const ComputedStyleBase& initial_style) = default;
    explicit ComputedStyleBase(const ComputedStyleBuilderBase&);

    // accent-color
    const StyleAutoColor& AccentColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->accent_color_;
    }

    // AffectedByActive

    // AffectedByCSSFunction

    // AffectedByDrag

    // AffectedByFocusWithin

    // AffectedByHover

    // align-content

    // -internal-align-content-block

    // align-items

    // align-self

    // alignment-baseline

    // AnchorCenterOffset

    // anchor-name

    // anchor-scope

    // Animations
    const std::unique_ptr<CSSAnimationData>& AnimationsInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->animations_;
    }

    // appearance
    ControlPart Appearance() const
    {
        return static_cast<ControlPart>(rare_non_inherited_usage_less_than_14_percent_data_->appearance_);
    }

    // aspect-ratio

    // backdrop-filter

    // backface-visibility

    // Background
    const FillLayer& BackgroundInternal() const
    {
        return background_data_->background_;
    }

    // background-color
    const StyleColor& BackgroundColor() const
    {
        return background_data_->background_color_;
    }

    // BaseTextDecorationData
    const scoped_refptr<base::RefCountedData<Vector<AppliedTextDecoration, 1>>>& BaseTextDecorationDataInternal() const
    {
        return visual_data_->base_text_decoration_data_;
    }

    // baseline-shift

    // BaselineShiftType

    // baseline-source

    // mix-blend-mode

    // border-bottom-color
    const StyleColor& BorderBottomColor() const
    {
        return surround_data_->border_bottom_color_;
    }

    // border-bottom-left-radius

    // border-bottom-right-radius

    // border-bottom-style

    // border-bottom-width
    const int& BorderBottomWidthInternal() const
    {
        return box_data_->border_bottom_width_;
    }

    // border-collapse

    // border-collapse

    // border-image

    // border-left-color
    const StyleColor& BorderLeftColor() const
    {
        return surround_data_->border_left_color_;
    }

    // border-left-style

    // border-left-width
    const int& BorderLeftWidthInternal() const
    {
        return box_data_->border_left_width_;
    }

    // border-right-color
    const StyleColor& BorderRightColor() const
    {
        return surround_data_->border_right_color_;
    }

    // border-right-style

    // border-right-width
    const int& BorderRightWidthInternal() const
    {
        return box_data_->border_right_width_;
    }

    // border-top-color
    const StyleColor& BorderTopColor() const
    {
        return surround_data_->border_top_color_;
    }

    // border-top-left-radius

    // border-top-right-radius

    // border-top-style

    // border-top-width
    const int& BorderTopWidthInternal() const
    {
        return box_data_->border_top_width_;
    }

    // bottom

    // -webkit-box-align

    // box-decoration-break

    // -webkit-box-direction
    EBoxDirection BoxDirection() const
    {
        return static_cast<EBoxDirection>(data_.box_direction_);
    }

    // -webkit-box-flex

    // -webkit-box-ordinal-group

    // -webkit-box-orient

    // -webkit-box-pack

    // box-sizing

    // break-after

    // break-before

    // break-inside

    // buffered-rendering

    // CallbackSelectors

    // CanAffectAnimations

    // stroke-linecap

    // caption-side

    // caption-side

    // caret-animation

    // caret-color
    const StyleAutoColor& CaretColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->caret_color_;
    }

    // ChildHasExplicitInheritance

    // clear
    EClear Clear() const
    {
        return static_cast<EClear>(data_.clear_);
    }

    // clip

    // clip-path
    const Member<ClipPathOperation>& ClipPathInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->clip_path_;
    }

    // clip-rule

    // color
    const StyleColor& Color() const
    {
        return inherited_data_->color_;
    }

    // color-interpolation

    // color-interpolation-filters

    // ColorIsCurrentColor
    bool ColorIsCurrentColor() const
    {
        return static_cast<bool>(inherited_data_->color_is_current_color_);
    }

    // color
    bool ColorIsInherited() const
    {
        return static_cast<bool>(data_.color_is_inherited_);
    }

    // color-rendering

    // color-scheme

    // ColorSchemeFlagsIsNormal

    // ColorSchemeForced

    // column-count

    // column-fill

    // column-gap

    // column-rule-color

    // column-rule-style

    // column-rule-width
    const int& ColumnRuleWidthInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_width_;
    }

    // column-span

    // column-width

    // contain

    // contain-intrinsic-height

    // contain-intrinsic-width

    // container-name

    // container-type

    // content
    const Member<ContentData>& ContentInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->content_;
    }

    // content-visibility

    // CounterDirectives
    const std::unique_ptr<CounterDirectiveMap>& CounterDirectivesInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->counter_directives_;
    }

    // CssDominantBaseline

    // cursor

    // CursorData
    const Member<CursorList>& CursorDataInternal() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->cursor_data_;
    }

    // CustomHighlightNames
    const std::unique_ptr<HashSet<AtomicString>>& CustomHighlightNamesInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->custom_highlight_names_;
    }

    // CustomStyleCallbackDependsOnFont

    // cx

    // cy

    // DarkColorScheme

    // DependsOnScrollStateContainerQueries

    // DependsOnSizeContainerQueries

    // DependsOnStyleContainerQueries

    // direction

    // Display

    // DisplayLayoutCustomName

    // DisplayLayoutCustomParentName

    // DocumentRulesSelectors

    // dominant-baseline

    // app-region

    // dynamic-range-limit

    // EffectiveAppearance

    // EffectiveTouchAction

    // EffectiveZIndexZero

    // EffectiveZoom

    // ElementIsViewTransitionParticipant

    // empty-cells

    // empty-cells

    // field-sizing

    // fill-opacity

    // fill

    // fill-rule

    // filter

    // FirstLineDependsOnSizeContainerQueries

    // flex-basis

    // flex-direction

    // flex-grow

    // flex-shrink

    // flex-wrap

    // float
    EFloat Floating() const
    {
        return static_cast<EFloat>(data_.floating_);
    }

    // flood-color

    // flood-opacity

    // font

    // forced-color-adjust

    // ForcesStackingContext

    // grid-auto-columns

    // grid-auto-flow
    GridAutoFlow GridAutoFlowInternal() const
    {
        return static_cast<GridAutoFlow>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                             ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_flow_);
    }

    // grid-auto-rows

    // grid-column-end

    // grid-column-start

    // grid-row-end

    // grid-row-start

    // grid-template-areas

    // grid-template-columns

    // grid-template-rows

    // HasAnchorEvaluator

    // HasAnchorFunctions

    // HasAttrFunction

    // HasAuthorBackground

    // HasAuthorBorder

    // HasAuthorBorderRadius

    // HasAuthorHighlightColors

    // HasAutoClip

    // HasAutoColumnCount

    // HasAutoColumnWidth

    // HasAutoStandardLineClamp

    // HasAutoZIndex

    // HasClipPath

    // HasContainerRelativeUnits

    // HasCurrentBackdropFilterAnimation

    // HasCurrentBackgroundColorAnimation

    // HasCurrentFilterAnimation

    // HasCurrentOpacityAnimation

    // HasCurrentRotateAnimation

    // HasCurrentScaleAnimation

    // HasCurrentTransformAnimation

    // HasCurrentTranslateAnimation

    // HasEmUnits

    // HasEnv

    // HasExplicitInheritance

    // HasExplicitOverflowXVisible

    // HasExplicitOverflowYVisible

    // HasGlyphRelativeUnits

    // HasLineHeightRelativeUnits

    // -internal-empty-line-height

    // HasLogicalDirectionRelativeUnits

    // HasNonUaHighlightPseudoStyles

    // HasNonUniversalHighlightPseudoStyles

    // HasRootFontRelativeUnits

    // HasVariableDeclaration

    // HasVariableReference

    // height

    // HighlightData

    // HighlightsDependOnSizeContainerQueries

    // -webkit-border-horizontal-spacing

    // hyphenate-limit-chars

    // hyphenate-character

    // hyphens

    // image-orientation

    // image-rendering

    // InBaseSelectAppearance

    // InForcedColorsMode

    // InheritedVariables
    const Member<StyleInheritedVariables>& InheritedVariablesInternal() const
    {
        return inherited_data_->inherited_variables_;
    }

    // initial-letter

    // InlineBlockBaselineEdge

    // InlineStyleLostCascade

    // InsideLink

    // interactivity

    // -internal-forced-background-color
    const StyleColor& InternalForcedBackgroundColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
            ->internal_forced_background_color_;
    }

    // -internal-forced-border-color
    const StyleColor& InternalForcedBorderColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
            ->internal_forced_border_color_;
    }

    // -internal-forced-color
    const StyleColor& InternalForcedColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_
            ->internal_forced_color_;
    }

    // -internal-forced-outline-color
    const StyleColor& InternalForcedOutlineColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
            ->internal_forced_outline_color_;
    }

    // -internal-forced-visited-color
    const StyleColor& InternalForcedVisitedColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_
            ->internal_forced_visited_color_;
    }

    // -internal-visited-background-color
    const StyleColor& InternalVisitedBackgroundColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_background_color_;
    }

    // -internal-visited-border-bottom-color
    const StyleColor& InternalVisitedBorderBottomColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_border_bottom_color_;
    }

    // -internal-visited-border-left-color
    const StyleColor& InternalVisitedBorderLeftColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_border_left_color_;
    }

    // -internal-visited-border-right-color
    const StyleColor& InternalVisitedBorderRightColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_border_right_color_;
    }

    // -internal-visited-border-top-color
    const StyleColor& InternalVisitedBorderTopColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_border_top_color_;
    }

    // -internal-visited-caret-color
    const StyleAutoColor& InternalVisitedCaretColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
            ->internal_visited_caret_color_;
    }

    // -internal-visited-color
    const StyleColor& InternalVisitedColor() const
    {
        return inherited_data_->internal_visited_color_;
    }

    // InternalVisitedColorIsCurrentColor
    bool InternalVisitedColorIsCurrentColor() const
    {
        return static_cast<bool>(inherited_data_->internal_visited_color_is_current_color_);
    }

    // -internal-visited-column-rule-color

    // -internal-visited-fill

    // -internal-visited-outline-color
    const StyleColor& InternalVisitedOutlineColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_outline_color_;
    }

    // -internal-visited-stroke

    // -internal-visited-text-decoration-color
    const StyleColor& InternalVisitedTextDecorationColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_text_decoration_color_;
    }

    // -internal-visited-text-emphasis-color
    const StyleColor& InternalVisitedTextEmphasisColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
            ->internal_visited_text_emphasis_color_;
    }

    // -internal-visited-text-fill-color
    const StyleColor& InternalVisitedTextFillColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
            ->internal_visited_text_fill_color_;
    }

    // -internal-visited-text-stroke-color
    const StyleColor& InternalVisitedTextStrokeColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
            ->internal_visited_text_stroke_color_;
    }

    // interpolate-size

    // IsEnsuredInDisplayNone

    // IsEnsuredOutsideFlatTree

    // IsFlexOrGridOrCustomItem

    // IsHTMLInert

    // IsHTMLInert

    // IsInBlockifyingDisplay

    // IsInInlinifyingDisplay

    // IsInsideDisplayIgnoringFloatingChildren

    // IsInsideListElement

    // IsLink

    // IsOriginalDisplayInlineType

    // IsPageMarginBox

    // IsRunningBackdropFilterAnimationOnCompositor

    // IsRunningFilterAnimationOnCompositor

    // IsRunningOpacityAnimationOnCompositor

    // IsRunningRotateAnimationOnCompositor

    // IsRunningScaleAnimationOnCompositor

    // IsRunningTransformAnimationOnCompositor

    // IsRunningTranslateAnimationOnCompositor

    // IsSecondaryBodyElement

    // IsSpecifiedDisplayWebkitBox

    // IsStackingContextWithoutContainment

    // IsStartingStyle

    // isolation

    // stroke-linejoin

    // justify-content

    // justify-items

    // justify-self

    // left

    // lighting-color

    // -webkit-line-break

    // line-height
    const Length& LineHeightInternal() const
    {
        return inherited_data_->line_height_;
    }

    // list-style-image

    // list-style-position

    // list-style-position

    // list-style-type

    // margin-bottom

    // margin-left

    // margin-right

    // margin-top

    // Mask
    const FillLayer& MaskInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_;
    }

    // MaskBoxImage
    const NinePieceImage& MaskBoxImageInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_;
    }

    // mask-type

    // masonry-slack

    // masonry-template-tracks

    // masonry-track-end

    // masonry-track-start

    // MathBaseline

    // math-depth

    // MathFractionBarThickness

    // MathLSpace

    // MathMaxSize

    // MathMinSize

    // MathPaddedDepth

    // MathPaddedVOffset

    // MathRSpace

    // math-shift

    // math-style

    // max-height

    // max-width

    // MayHaveMargin

    // MayHavePadding

    // min-height

    // min-width

    // NonInheritedVariables
    const Member<StyleNonInheritedVariables>& NonInheritedVariablesInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->non_inherited_variables_;
    }

    // object-fit

    // object-position

    // offset-anchor

    // offset-distance

    // offset-position

    // offset-rotate

    // opacity

    // order

    // origin-trial-test-property

    // orphans

    // outline-color
    const StyleColor& OutlineColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->outline_color_;
    }

    // outline-offset

    // outline-style

    // OutlineStyleIsAuto

    // outline-width
    const int& OutlineWidthInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_width_;
    }

    // overflow-anchor

    // overflow-clip-margin

    // overflow-wrap

    // overflow-x

    // overflow-y

    // overlay

    // overscroll-behavior-x

    // overscroll-behavior-y

    // padding-bottom

    // padding-left

    // padding-right

    // padding-top

    // page

    // page-orientation

    // PageSize

    // PageSizeType

    // PaintImages
    const Member<PaintImages>& PaintImagesInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->paint_images_;
    }

    // paint-order

    // perspective

    // perspective-origin

    // pointer-events
    EPointerEvents PointerEvents() const
    {
        return static_cast<EPointerEvents>(data_.pointer_events_);
    }

    // pointer-events
    bool PointerEventsIsInherited() const
    {
        return static_cast<bool>(data_.pointer_events_is_inherited_);
    }

    // popover-hide-delay

    // popover-show-delay

    // position
    EPosition PositionInternal() const
    {
        return static_cast<EPosition>(data_.position_);
    }

    // position-anchor

    // position-area

    // PositionAreaOffsets

    // position-try-fallbacks

    // position-try-order

    // position-visibility

    // PrefersDefaultScrollbarStyles

    // -webkit-print-color-adjust

    // PseudoArgument

    // PseudoElementStyles
    unsigned PseudoElementStylesInternal() const
    {
        return static_cast<unsigned>(data_.pseudo_element_styles_);
    }

    // r

    // reading-flow

    // RequiresAcceleratedCompositingForExternalReasons

    // resize
    EResize Resize() const
    {
        return static_cast<EResize>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->resize_);
    }

    // right

    // row-gap

    // -webkit-rtl-ordering

    // -webkit-rtl-ordering

    // ruby-align

    // ruby-position

    // rx

    // ry

    // scroll-behavior

    // scroll-margin-bottom

    // scroll-margin-left

    // scroll-margin-right

    // scroll-margin-top

    // scroll-marker-group

    // scroll-padding-bottom

    // scroll-padding-left

    // scroll-padding-right

    // scroll-padding-top

    // scroll-snap-align

    // scroll-snap-stop

    // scroll-snap-type

    // scroll-start-target

    // scroll-start-x

    // scroll-start-y

    // scroll-timeline-axis

    // scroll-timeline-name

    // scrollbar-gutter

    // scrollbar-width

    // shape-image-threshold

    // shape-margin

    // shape-outside
    const Member<ShapeValue>& ShapeOutsideInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->shape_outside_;
    }

    // shape-rendering

    // ShouldIgnoreOverflowPropertyForInlineBlockBaseline

    // SkipsContents

    // speak

    // line-clamp

    // stop-color
    const StyleColor& StopColor() const
    {
        return svg_data_->stop_data_->stop_color_;
    }

    // stop-opacity

    // stroke-dashoffset

    // stroke-miterlimit

    // stroke-opacity

    // stroke

    // stroke-width

    // StyleType

    // SubtreeIsSticky

    // SubtreeWillChangeContents

    // tab-size

    // table-layout

    // -webkit-tap-highlight-color

    // text-align

    // text-align-last

    // text-anchor

    // TextAutosizingMultiplier

    // text-autospace

    // text-box-edge

    // text-box-trim

    // text-combine-upright

    // text-decoration-color
    const StyleColor& TextDecorationColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_color_;
    }

    // text-decoration-line

    // text-decoration-skip-ink

    // text-decoration-style

    // text-decoration-thickness

    // text-emphasis-color
    const StyleColor& TextEmphasisColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_;
    }

    // TextEmphasisCustomMark

    // TextEmphasisFill

    // TextEmphasisMark
    TextEmphasisMark TextEmphasisMarkInternal() const
    {
        return static_cast<TextEmphasisMark>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_mark_);
    }

    // text-emphasis-position

    // -webkit-text-fill-color
    const StyleColor& TextFillColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->text_fill_color_;
    }

    // text-indent

    // text-orientation

    // text-overflow

    // -webkit-text-security

    // text-size-adjust

    // -webkit-text-stroke-color
    const StyleColor& TextStrokeColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_;
    }

    // -webkit-text-stroke-width

    // text-transform

    // text-transform

    // text-underline-offset

    // text-underline-position

    // text-wrap-mode

    // text-wrap-style

    // timeline-scope

    // top

    // touch-action

    // transform

    // transform-box

    // transform-origin

    // transform-style

    // Transitions
    const std::unique_ptr<CSSTransitionData>& TransitionsInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->transitions_;
    }

    // unicode-bidi

    // -webkit-user-drag

    // -webkit-user-modify
    EUserModify UserModify() const
    {
        return static_cast<EUserModify>(rare_inherited_usage_less_than_64_percent_data_->user_modify_);
    }

    // user-select
    EUserSelect UserSelect() const
    {
        return static_cast<EUserSelect>(rare_inherited_usage_less_than_64_percent_data_->user_select_);
    }

    // vector-effect

    // VerticalAlign
    unsigned VerticalAlignInternal() const
    {
        return static_cast<unsigned>(data_.vertical_align_);
    }

    // VerticalAlignLength

    // -webkit-border-vertical-spacing

    // view-timeline-axis

    // view-timeline-inset

    // view-timeline-name

    // view-transition-capture-mode

    // view-transition-class

    // view-transition-group

    // view-transition-name

    // ViewportUnitFlags

    // visibility

    // visibility

    // -webkit-line-clamp

    // white-space-collapse

    // widows

    // width

    // WillChangeContents

    // WillChangeProperties

    // WillChangeScrollPosition

    // word-break

    // writing-mode

    // x

    // y

    // z-index

    // zoom

    struct Data {
        unsigned pseudo_element_styles_ : 21; // unsigned
        unsigned cursor_ : 6; // ECursor
        unsigned pointer_events_ : 4; // EPointerEvents
        unsigned affected_by_active_ : 1; // bool
        unsigned display_ : 6; // EDisplay
        unsigned style_type_ : 6; // PseudoId
        unsigned scrollbar_gutter_ : 4; // unsigned
        unsigned text_align_ : 4; // ETextAlign
        unsigned vertical_align_ : 4; // unsigned
        unsigned clear_ : 3; // EClear
        unsigned floating_ : 3; // EFloat
        unsigned content_visibility_ : 2; // EContentVisibility
        unsigned overflow_x_ : 3; // EOverflow
        unsigned overflow_y_ : 3; // EOverflow
        unsigned position_ : 3; // EPosition
        unsigned text_transform_ : 3; // ETextTransform
        unsigned transform_box_ : 3; // ETransformBox
        unsigned unicode_bidi_ : 3; // UnicodeBidi
        unsigned writing_mode_ : 3; // WritingMode
        unsigned inside_link_ : 2; // EInsideLink
        mutable unsigned is_stacking_context_without_containment_ : 2; // unsigned
        unsigned overflow_anchor_ : 2; // EOverflowAnchor
        unsigned text_wrap_style_ : 2; // TextWrapStyle
        unsigned viewport_unit_flags_ : 2; // unsigned
        unsigned affected_by_drag_ : 1; // bool
        unsigned visibility_ : 2; // EVisibility
        unsigned white_space_collapse_ : 2; // WhiteSpaceCollapse
        unsigned affected_by_focus_within_ : 1; // bool
        unsigned affected_by_hover_ : 1; // bool
        unsigned border_collapse_ : 1; // EBorderCollapse
        unsigned border_collapse_is_inherited_ : 1; // bool
        unsigned box_direction_ : 1; // EBoxDirection
        unsigned box_sizing_ : 1; // EBoxSizing
        unsigned caption_side_ : 1; // ECaptionSide
        unsigned caption_side_is_inherited_ : 1; // bool
        unsigned caret_animation_ : 1; // ECaretAnimation
        mutable unsigned child_has_explicit_inheritance_ : 1; // bool
        unsigned color_is_inherited_ : 1; // bool
        unsigned color_scheme_flags_is_normal_ : 1; // bool
        unsigned color_scheme_forced_ : 1; // bool
        unsigned custom_style_callback_depends_on_font_ : 1; // bool
        unsigned dark_color_scheme_ : 1; // bool
        unsigned direction_ : 1; // TextDirection
        unsigned empty_cells_ : 1; // EEmptyCells
        unsigned empty_cells_is_inherited_ : 1; // bool
        unsigned has_attr_function_ : 1; // bool
        unsigned has_author_background_ : 1; // bool
        unsigned has_author_border_ : 1; // bool
        unsigned has_author_border_radius_ : 1; // bool
        unsigned has_author_highlight_colors_ : 1; // bool
        unsigned has_container_relative_units_ : 1; // bool
        unsigned has_em_units_ : 1; // bool
        unsigned has_env_ : 1; // bool
        unsigned has_explicit_inheritance_ : 1; // bool
        unsigned has_glyph_relative_units_ : 1; // bool
        unsigned has_logical_direction_relative_units_ : 1; // bool
        unsigned has_root_font_relative_units_ : 1; // bool
        unsigned has_variable_declaration_ : 1; // bool
        unsigned has_variable_reference_ : 1; // bool
        unsigned is_ensured_in_display_none_ : 1; // bool
        unsigned is_ensured_outside_flat_tree_ : 1; // bool
        unsigned is_flex_or_grid_or_custom_item_ : 1; // bool
        unsigned is_html_inert_ : 1; // bool
        unsigned is_html_inert_is_inherited_ : 1; // bool
        unsigned is_in_blockifying_display_ : 1; // bool
        unsigned is_in_inlinifying_display_ : 1; // bool
        unsigned is_inside_display_ignoring_floating_children_ : 1; // bool
        unsigned is_inside_list_element_ : 1; // bool
        unsigned is_link_ : 1; // bool
        unsigned is_original_display_inline_type_ : 1; // bool
        unsigned is_page_margin_box_ : 1; // bool
        unsigned is_specified_display_webkit_box_ : 1; // bool
        unsigned list_style_position_ : 1; // EListStylePosition
        unsigned list_style_position_is_inherited_ : 1; // bool
        unsigned origin_trial_test_property_ : 1; // EOriginTrialTestProperty
        unsigned pointer_events_is_inherited_ : 1; // bool
        unsigned prefers_default_scrollbar_styles_ : 1; // bool
        unsigned print_color_adjust_ : 1; // EPrintColorAdjust
        unsigned rtl_ordering_ : 1; // EOrder
        unsigned rtl_ordering_is_inherited_ : 1; // bool
        unsigned scroll_snap_stop_ : 1; // EScrollSnapStop
        unsigned should_ignore_overflow_property_for_inline_block_baseline_ : 1; // bool
        unsigned skips_contents_ : 1; // bool
        unsigned table_layout_ : 1; // ETableLayout
        unsigned text_transform_is_inherited_ : 1; // bool
        unsigned text_wrap_mode_ : 1; // TextWrapMode
        unsigned visibility_is_inherited_ : 1; // bool
    };

    enum FieldDifference : uint64_t {
        kAccentColor = static_cast<uint64_t>(1) << 0,
        kBackground = static_cast<uint64_t>(1) << 1,
        kBackgroundColor = static_cast<uint64_t>(1) << 2,
        kBackgroundCurrentColor = static_cast<uint64_t>(1) << 3,
        kBlendMode = static_cast<uint64_t>(1) << 4,
        kBorderImage = static_cast<uint64_t>(1) << 5,
        kBorderOutlineVisitedColor = static_cast<uint64_t>(1) << 6,
        kBorderRadius = static_cast<uint64_t>(1) << 7,
        kBorderVisual = static_cast<uint64_t>(1) << 8,
        kBorderWidth = static_cast<uint64_t>(1) << 9,
        kClip = static_cast<uint64_t>(1) << 10,
        kClipPath = static_cast<uint64_t>(1) << 11,
        kColor = static_cast<uint64_t>(1) << 12,
        kCompositing = static_cast<uint64_t>(1) << 13,
        kFilterData = static_cast<uint64_t>(1) << 14,
        kHasTransform = static_cast<uint64_t>(1) << 15,
        kInset = static_cast<uint64_t>(1) << 16,
        kLayout = static_cast<uint64_t>(1) << 17,
        kMargin = static_cast<uint64_t>(1) << 18,
        kMask = static_cast<uint64_t>(1) << 19,
        kOpacity = static_cast<uint64_t>(1) << 20,
        kOutline = static_cast<uint64_t>(1) << 21,
        kOutOfFlow = static_cast<uint64_t>(1) << 22,
        kPaint = static_cast<uint64_t>(1) << 23,
        kReshape = static_cast<uint64_t>(1) << 24,
        kScrollAnchor = static_cast<uint64_t>(1) << 25,
        kScrollbarColor = static_cast<uint64_t>(1) << 26,
        kScrollbarStyle = static_cast<uint64_t>(1) << 27,
        kStroke = static_cast<uint64_t>(1) << 28,
        kTextDecoration = static_cast<uint64_t>(1) << 29,
        kTransformData = static_cast<uint64_t>(1) << 30,
        kTransformOther = static_cast<uint64_t>(1) << 31,
        kTransformProperty = static_cast<uint64_t>(1) << 32,
        kVisibility = static_cast<uint64_t>(1) << 33,
        kVisualOverflow = static_cast<uint64_t>(1) << 34,
        kZIndex = static_cast<uint64_t>(1) << 35,
    };

    static uint64_t FieldInvalidationDiff(const ComputedStyle& a, const ComputedStyle& b);

private:
    friend class ComputedStyleBuilder;
    friend class ComputedStyleBuilderBase;

    // Storage.
    Member<StyleRareInheritedUsageLessThan64PercentData> rare_inherited_usage_less_than_64_percent_data_;
    Member<StyleRareNonInheritedUsageLessThan14PercentData> rare_non_inherited_usage_less_than_14_percent_data_;
    Member<StyleInheritedData> inherited_data_;
    Member<StyleVisualData> visual_data_;
    Member<StyleSVGData> svg_data_;
    Member<StyleSurroundData> surround_data_;
    Member<StyleBackgroundData> background_data_;
    Member<StyleBoxData> box_data_;
    Member<StyleFontData> font_data_;

    Member<StyleBaseData> base_data_;

    Data data_;
};

class ComputedStyleBuilderBase {
    STACK_ALLOCATED();

public:
    enum IsAtShadowBoundary {
        kAtShadowBoundary,
        kNotAtShadowBoundary,
    };

    // accent-color

    void SetAccentColor(const StyleAutoColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->accent_color_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_100_percent_data_,
                access_.rare_inherited_usage_less_than_100_percent_data_)
                ->accent_color_
                = v;
    }

    void SetAccentColor(StyleAutoColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->accent_color_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_100_percent_data_,
                access_.rare_inherited_usage_less_than_100_percent_data_)
                ->accent_color_
                = std::move(v);
    }

    inline void ResetAccentColor()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_100_percent_data_,
            access_.rare_inherited_usage_less_than_100_percent_data_)
            ->accent_color_
            = StyleAutoColor::AutoColor();
    }

    // AffectedByActive
    bool AffectedByActive() const
    {
        return static_cast<bool>(data_.affected_by_active_);
    }

    void SetAffectedByActive()
    {
        data_.affected_by_active_ = static_cast<unsigned>(true);
    }

    // AffectedByCSSFunction
    bool AffectedByCSSFunction() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->affected_by_css_function_);
    }

    void SetAffectedByCSSFunction()
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->affected_by_css_function_
                == static_cast<unsigned>(true)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->affected_by_css_function_
                = static_cast<unsigned>(true);
    }

    // AffectedByDrag
    bool AffectedByDrag() const
    {
        return static_cast<bool>(data_.affected_by_drag_);
    }

    void SetAffectedByDrag()
    {
        data_.affected_by_drag_ = static_cast<unsigned>(true);
    }

    // AffectedByFocusWithin
    bool AffectedByFocusWithin() const
    {
        return static_cast<bool>(data_.affected_by_focus_within_);
    }

    void SetAffectedByFocusWithin()
    {
        data_.affected_by_focus_within_ = static_cast<unsigned>(true);
    }

    // AffectedByHover
    bool AffectedByHover() const
    {
        return static_cast<bool>(data_.affected_by_hover_);
    }

    void SetAffectedByHover()
    {
        data_.affected_by_hover_ = static_cast<unsigned>(true);
    }

    // align-content
    const StyleContentAlignmentData& AlignContent() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_;
    }

    void SetAlignContent(const StyleContentAlignmentData& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->align_content_
                = v;
    }

    void SetAlignContent(StyleContentAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->align_content_
                = std::move(v);
    }

    inline void ResetAlignContent()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->align_content_
            = StyleContentAlignmentData(ContentPosition::kNormal, ContentDistributionType::kDefault, OverflowAlignment::kDefault);
    }

    // -internal-align-content-block
    bool AlignContentBlockCenter() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->align_content_block_center_);
    }

    void SetAlignContentBlockCenter(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->align_content_block_center_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->align_content_block_center_
                = static_cast<unsigned>(v);
    }

    inline void ResetAlignContentBlockCenter()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->align_content_block_center_
            = static_cast<unsigned>(false);
    }

    // align-items
    const StyleSelfAlignmentData& AlignItems() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->align_items_;
    }

    void SetAlignItems(const StyleSelfAlignmentData& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->align_items_ == v))
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->align_items_ = v;
    }

    void SetAlignItems(StyleSelfAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->align_items_ == v))
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->align_items_
                = std::move(v);
    }

    inline void ResetAlignItems()
    {
        Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->align_items_
            = StyleSelfAlignmentData(ItemPosition::kNormal, OverflowAlignment::kDefault);
    }

    // align-self
    const StyleSelfAlignmentData& AlignSelf() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_;
    }

    void SetAlignSelf(const StyleSelfAlignmentData& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->align_self_
                = v;
    }

    void SetAlignSelf(StyleSelfAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->align_self_
                = std::move(v);
    }

    inline void ResetAlignSelf()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->align_self_
            = StyleSelfAlignmentData(ItemPosition::kAuto, OverflowAlignment::kDefault);
    }

    // alignment-baseline
    EAlignmentBaseline AlignmentBaseline() const
    {
        return static_cast<EAlignmentBaseline>(svg_data_->alignment_baseline_);
    }

    void SetAlignmentBaseline(EAlignmentBaseline v)
    {
        if (!(svg_data_->alignment_baseline_ == static_cast<unsigned>(v)))
            Access(svg_data_, access_.svg_data_)->alignment_baseline_ = static_cast<unsigned>(v);
    }

    inline void ResetAlignmentBaseline()
    {
        Access(svg_data_, access_.svg_data_)->alignment_baseline_ = static_cast<unsigned>(EAlignmentBaseline::kAuto);
    }

    // AnchorCenterOffset
    const std::optional<PhysicalOffset>& AnchorCenterOffset() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_center_offset_;
    }

    void SetAnchorCenterOffset(const std::optional<PhysicalOffset>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_center_offset_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->anchor_center_offset_
                = v;
    }

    void SetAnchorCenterOffset(std::optional<PhysicalOffset>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_center_offset_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->anchor_center_offset_
                = std::move(v);
    }

    inline void ResetAnchorCenterOffset()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->anchor_center_offset_
            = std::nullopt;
    }

    // anchor-name
    const Member<ScopedCSSNameList>& AnchorName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_;
    }

    void SetAnchorName(const Member<ScopedCSSNameList>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->anchor_name_
                = v;
    }

    void SetAnchorName(Member<ScopedCSSNameList>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->anchor_name_
                = std::move(v);
    }

    inline void ResetAnchorName()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->anchor_name_
            = nullptr;
    }

    // anchor-scope
    const StyleAnchorScope& AnchorScope() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scope_;
    }

    void SetAnchorScope(const StyleAnchorScope& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scope_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->anchor_scope_
                = v;
    }

    void SetAnchorScope(StyleAnchorScope&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scope_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->anchor_scope_
                = std::move(v);
    }

    inline void ResetAnchorScope()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->anchor_scope_
            = StyleAnchorScope();
    }

    // Animations

    inline void ResetAnimations()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->animations_
            = nullptr;
    }

    // appearance

    void SetAppearance(ControlPart v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->appearance_ == static_cast<unsigned>(v)))
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->appearance_
                = static_cast<unsigned>(v);
    }

    inline void ResetAppearance()
    {
        Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->appearance_
            = static_cast<unsigned>(kNoControlPart);
    }

    // aspect-ratio
    const StyleAspectRatio& AspectRatio() const
    {
        return surround_data_->aspect_ratio_;
    }

    void SetAspectRatio(const StyleAspectRatio& v)
    {
        if (!(surround_data_->aspect_ratio_ == v))
            Access(surround_data_, access_.surround_data_)->aspect_ratio_ = v;
    }

    void SetAspectRatio(StyleAspectRatio&& v)
    {
        if (!(surround_data_->aspect_ratio_ == v))
            Access(surround_data_, access_.surround_data_)->aspect_ratio_ = std::move(v);
    }

    inline void ResetAspectRatio()
    {
        Access(surround_data_, access_.surround_data_)->aspect_ratio_ = StyleAspectRatio(EAspectRatioType::kAuto, gfx::SizeF());
    }

    // backdrop-filter
    const FilterOperations& BackdropFilter() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->backdrop_filter_;
    }

    void SetBackdropFilter(const FilterOperations& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->backdrop_filter_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->backdrop_filter_
                = v;
    }

    void SetBackdropFilter(FilterOperations&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->backdrop_filter_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->backdrop_filter_
                = std::move(v);
    }

    inline void ResetBackdropFilter()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->backdrop_filter_
            = FilterOperations();
    }

    // backface-visibility
    EBackfaceVisibility BackfaceVisibility() const
    {
        return static_cast<EBackfaceVisibility>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->backface_visibility_);
    }

    void SetBackfaceVisibility(EBackfaceVisibility v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->backface_visibility_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->backface_visibility_
                = static_cast<unsigned>(v);
    }

    inline void ResetBackfaceVisibility()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->backface_visibility_
            = static_cast<unsigned>(EBackfaceVisibility::kVisible);
    }

    // Background

    inline void ResetBackground()
    {
        Access(background_data_, access_.background_data_)->background_ = FillLayer(EFillLayerType::kBackground, true);
    }

    // background-color

    void SetBackgroundColor(const StyleColor& v)
    {
        if (!(background_data_->background_color_ == v))
            Access(background_data_, access_.background_data_)->background_color_ = v;
    }

    void SetBackgroundColor(StyleColor&& v)
    {
        if (!(background_data_->background_color_ == v))
            Access(background_data_, access_.background_data_)->background_color_ = std::move(v);
    }

    inline void ResetBackgroundColor()
    {
        Access(background_data_, access_.background_data_)->background_color_ = StyleColor(Color::kTransparent);
    }

    // BaseData
    StyleBaseData* BaseData() const
    {
        return base_data_;
    }

    void SetBaseData(StyleBaseData* v)
    {
        base_data_ = std::move(v);
    }

    // BaseTextDecorationData

    void SetBaseTextDecorationData(const scoped_refptr<base::RefCountedData<Vector<AppliedTextDecoration, 1>>>& v)
    {
        if (!(visual_data_->base_text_decoration_data_ == v))
            Access(visual_data_, access_.visual_data_)->base_text_decoration_data_ = v;
    }

    void SetBaseTextDecorationData(scoped_refptr<base::RefCountedData<Vector<AppliedTextDecoration, 1>>>&& v)
    {
        if (!(visual_data_->base_text_decoration_data_ == v))
            Access(visual_data_, access_.visual_data_)->base_text_decoration_data_ = std::move(v);
    }

    inline void ResetBaseTextDecorationData()
    {
        Access(visual_data_, access_.visual_data_)->base_text_decoration_data_ = nullptr;
    }

    // baseline-shift
    const Length& BaselineShift() const
    {
        return svg_data_->misc_data_->baseline_shift_;
    }

    void SetBaselineShift(const Length& v)
    {
        if (!(svg_data_->misc_data_->baseline_shift_ == v))
            Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->baseline_shift_ = v;
    }

    void SetBaselineShift(Length&& v)
    {
        if (!(svg_data_->misc_data_->baseline_shift_ == v))
            Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->baseline_shift_ = std::move(v);
    }

    inline void ResetBaselineShift()
    {
        Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->baseline_shift_ = Length::Fixed();
    }

    // BaselineShiftType
    EBaselineShiftType BaselineShiftType() const
    {
        return static_cast<EBaselineShiftType>(svg_data_->misc_data_->baseline_shift_type_);
    }

    void SetBaselineShiftType(EBaselineShiftType v)
    {
        if (!(svg_data_->misc_data_->baseline_shift_type_ == static_cast<unsigned>(v)))
            Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->baseline_shift_type_ = static_cast<unsigned>(v);
    }

    inline void ResetBaselineShiftType()
    {
        Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->baseline_shift_type_ = static_cast<unsigned>(EBaselineShiftType::kLength);
    }

    // baseline-source
    EBaselineSource BaselineSource() const
    {
        return static_cast<EBaselineSource>(box_data_->baseline_source_);
    }

    void SetBaselineSource(EBaselineSource v)
    {
        if (!(box_data_->baseline_source_ == static_cast<unsigned>(v)))
            Access(box_data_, access_.box_data_)->baseline_source_ = static_cast<unsigned>(v);
    }

    inline void ResetBaselineSource()
    {
        Access(box_data_, access_.box_data_)->baseline_source_ = static_cast<unsigned>(EBaselineSource::kAuto);
    }

    // mix-blend-mode
    BlendMode GetBlendMode() const
    {
        return static_cast<BlendMode>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                          ->rare_non_inherited_usage_less_than_100_percent_data_->blend_mode_);
    }

    void SetBlendMode(BlendMode v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->blend_mode_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->blend_mode_
                = static_cast<unsigned>(v);
    }

    inline void ResetBlendMode()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->blend_mode_
            = static_cast<unsigned>(BlendMode::kNormal);
    }

    // border-bottom-color

    void SetBorderBottomColor(const StyleColor& v)
    {
        if (!(surround_data_->border_bottom_color_ == v))
            Access(surround_data_, access_.surround_data_)->border_bottom_color_ = v;
    }

    void SetBorderBottomColor(StyleColor&& v)
    {
        if (!(surround_data_->border_bottom_color_ == v))
            Access(surround_data_, access_.surround_data_)->border_bottom_color_ = std::move(v);
    }

    inline void ResetBorderBottomColor()
    {
        Access(surround_data_, access_.surround_data_)->border_bottom_color_ = StyleColor::CurrentColor();
    }

    // border-bottom-left-radius
    const LengthSize& BorderBottomLeftRadius() const
    {
        return surround_data_->border_bottom_left_radius_;
    }

    void SetBorderBottomLeftRadius(const LengthSize& v)
    {
        if (!(surround_data_->border_bottom_left_radius_ == v))
            Access(surround_data_, access_.surround_data_)->border_bottom_left_radius_ = v;
    }

    void SetBorderBottomLeftRadius(LengthSize&& v)
    {
        if (!(surround_data_->border_bottom_left_radius_ == v))
            Access(surround_data_, access_.surround_data_)->border_bottom_left_radius_ = std::move(v);
    }

    inline void ResetBorderBottomLeftRadius()
    {
        Access(surround_data_, access_.surround_data_)->border_bottom_left_radius_ = LengthSize(Length::Fixed(0), Length::Fixed(0));
    }

    // border-bottom-right-radius
    const LengthSize& BorderBottomRightRadius() const
    {
        return surround_data_->border_bottom_right_radius_;
    }

    void SetBorderBottomRightRadius(const LengthSize& v)
    {
        if (!(surround_data_->border_bottom_right_radius_ == v))
            Access(surround_data_, access_.surround_data_)->border_bottom_right_radius_ = v;
    }

    void SetBorderBottomRightRadius(LengthSize&& v)
    {
        if (!(surround_data_->border_bottom_right_radius_ == v))
            Access(surround_data_, access_.surround_data_)->border_bottom_right_radius_ = std::move(v);
    }

    inline void ResetBorderBottomRightRadius()
    {
        Access(surround_data_, access_.surround_data_)->border_bottom_right_radius_ = LengthSize(Length::Fixed(0), Length::Fixed(0));
    }

    // border-bottom-style
    EBorderStyle BorderBottomStyle() const
    {
        return static_cast<EBorderStyle>(box_data_->border_bottom_style_);
    }

    void SetBorderBottomStyle(EBorderStyle v)
    {
        if (!(box_data_->border_bottom_style_ == static_cast<unsigned>(v)))
            Access(box_data_, access_.box_data_)->border_bottom_style_ = static_cast<unsigned>(v);
    }

    inline void ResetBorderBottomStyle()
    {
        Access(box_data_, access_.box_data_)->border_bottom_style_ = static_cast<unsigned>(EBorderStyle::kNone);
    }

    // border-bottom-width

    void SetBorderBottomWidth(const int& v)
    {
        if (!(box_data_->border_bottom_width_ == v))
            Access(box_data_, access_.box_data_)->border_bottom_width_ = v;
    }

    void SetBorderBottomWidth(int&& v)
    {
        if (!(box_data_->border_bottom_width_ == v))
            Access(box_data_, access_.box_data_)->border_bottom_width_ = std::move(v);
    }

    inline void ResetBorderBottomWidth()
    {
        Access(box_data_, access_.box_data_)->border_bottom_width_ = 3;
    }

    // border-collapse
    EBorderCollapse BorderCollapse() const
    {
        return static_cast<EBorderCollapse>(data_.border_collapse_);
    }

    void SetBorderCollapse(EBorderCollapse v)
    {
        data_.border_collapse_ = static_cast<unsigned>(v);
    }

    inline void ResetBorderCollapse()
    {
        data_.border_collapse_ = static_cast<unsigned>(EBorderCollapse::kSeparate);
    }

    // border-collapse
    bool BorderCollapseIsInherited() const
    {
        return static_cast<bool>(data_.border_collapse_is_inherited_);
    }

    void SetBorderCollapseIsInherited(bool v)
    {
        data_.border_collapse_is_inherited_ = static_cast<unsigned>(v);
    }

    inline void ResetBorderCollapseIsInherited()
    {
        data_.border_collapse_is_inherited_ = static_cast<unsigned>(true);
    }

    // border-image
    const NinePieceImage& BorderImage() const
    {
        return surround_data_->border_image_;
    }

    void SetBorderImage(const NinePieceImage& v)
    {
        if (!(surround_data_->border_image_ == v))
            Access(surround_data_, access_.surround_data_)->border_image_ = v;
    }

    void SetBorderImage(NinePieceImage&& v)
    {
        if (!(surround_data_->border_image_ == v))
            Access(surround_data_, access_.surround_data_)->border_image_ = std::move(v);
    }

    inline void ResetBorderImage()
    {
        Access(surround_data_, access_.surround_data_)->border_image_ = NinePieceImage();
    }

    // border-left-color

    void SetBorderLeftColor(const StyleColor& v)
    {
        if (!(surround_data_->border_left_color_ == v))
            Access(surround_data_, access_.surround_data_)->border_left_color_ = v;
    }

    void SetBorderLeftColor(StyleColor&& v)
    {
        if (!(surround_data_->border_left_color_ == v))
            Access(surround_data_, access_.surround_data_)->border_left_color_ = std::move(v);
    }

    inline void ResetBorderLeftColor()
    {
        Access(surround_data_, access_.surround_data_)->border_left_color_ = StyleColor::CurrentColor();
    }

    // border-left-style
    EBorderStyle BorderLeftStyle() const
    {
        return static_cast<EBorderStyle>(box_data_->border_left_style_);
    }

    void SetBorderLeftStyle(EBorderStyle v)
    {
        if (!(box_data_->border_left_style_ == static_cast<unsigned>(v)))
            Access(box_data_, access_.box_data_)->border_left_style_ = static_cast<unsigned>(v);
    }

    inline void ResetBorderLeftStyle()
    {
        Access(box_data_, access_.box_data_)->border_left_style_ = static_cast<unsigned>(EBorderStyle::kNone);
    }

    // border-left-width

    void SetBorderLeftWidth(const int& v)
    {
        if (!(box_data_->border_left_width_ == v))
            Access(box_data_, access_.box_data_)->border_left_width_ = v;
    }

    void SetBorderLeftWidth(int&& v)
    {
        if (!(box_data_->border_left_width_ == v))
            Access(box_data_, access_.box_data_)->border_left_width_ = std::move(v);
    }

    inline void ResetBorderLeftWidth()
    {
        Access(box_data_, access_.box_data_)->border_left_width_ = 3;
    }

    // border-right-color

    void SetBorderRightColor(const StyleColor& v)
    {
        if (!(surround_data_->border_right_color_ == v))
            Access(surround_data_, access_.surround_data_)->border_right_color_ = v;
    }

    void SetBorderRightColor(StyleColor&& v)
    {
        if (!(surround_data_->border_right_color_ == v))
            Access(surround_data_, access_.surround_data_)->border_right_color_ = std::move(v);
    }

    inline void ResetBorderRightColor()
    {
        Access(surround_data_, access_.surround_data_)->border_right_color_ = StyleColor::CurrentColor();
    }

    // border-right-style
    EBorderStyle BorderRightStyle() const
    {
        return static_cast<EBorderStyle>(box_data_->border_right_style_);
    }

    void SetBorderRightStyle(EBorderStyle v)
    {
        if (!(box_data_->border_right_style_ == static_cast<unsigned>(v)))
            Access(box_data_, access_.box_data_)->border_right_style_ = static_cast<unsigned>(v);
    }

    inline void ResetBorderRightStyle()
    {
        Access(box_data_, access_.box_data_)->border_right_style_ = static_cast<unsigned>(EBorderStyle::kNone);
    }

    // border-right-width

    void SetBorderRightWidth(const int& v)
    {
        if (!(box_data_->border_right_width_ == v))
            Access(box_data_, access_.box_data_)->border_right_width_ = v;
    }

    void SetBorderRightWidth(int&& v)
    {
        if (!(box_data_->border_right_width_ == v))
            Access(box_data_, access_.box_data_)->border_right_width_ = std::move(v);
    }

    inline void ResetBorderRightWidth()
    {
        Access(box_data_, access_.box_data_)->border_right_width_ = 3;
    }

    // border-top-color

    void SetBorderTopColor(const StyleColor& v)
    {
        if (!(surround_data_->border_top_color_ == v))
            Access(surround_data_, access_.surround_data_)->border_top_color_ = v;
    }

    void SetBorderTopColor(StyleColor&& v)
    {
        if (!(surround_data_->border_top_color_ == v))
            Access(surround_data_, access_.surround_data_)->border_top_color_ = std::move(v);
    }

    inline void ResetBorderTopColor()
    {
        Access(surround_data_, access_.surround_data_)->border_top_color_ = StyleColor::CurrentColor();
    }

    // border-top-left-radius
    const LengthSize& BorderTopLeftRadius() const
    {
        return surround_data_->border_top_left_radius_;
    }

    void SetBorderTopLeftRadius(const LengthSize& v)
    {
        if (!(surround_data_->border_top_left_radius_ == v))
            Access(surround_data_, access_.surround_data_)->border_top_left_radius_ = v;
    }

    void SetBorderTopLeftRadius(LengthSize&& v)
    {
        if (!(surround_data_->border_top_left_radius_ == v))
            Access(surround_data_, access_.surround_data_)->border_top_left_radius_ = std::move(v);
    }

    inline void ResetBorderTopLeftRadius()
    {
        Access(surround_data_, access_.surround_data_)->border_top_left_radius_ = LengthSize(Length::Fixed(0), Length::Fixed(0));
    }

    // border-top-right-radius
    const LengthSize& BorderTopRightRadius() const
    {
        return surround_data_->border_top_right_radius_;
    }

    void SetBorderTopRightRadius(const LengthSize& v)
    {
        if (!(surround_data_->border_top_right_radius_ == v))
            Access(surround_data_, access_.surround_data_)->border_top_right_radius_ = v;
    }

    void SetBorderTopRightRadius(LengthSize&& v)
    {
        if (!(surround_data_->border_top_right_radius_ == v))
            Access(surround_data_, access_.surround_data_)->border_top_right_radius_ = std::move(v);
    }

    inline void ResetBorderTopRightRadius()
    {
        Access(surround_data_, access_.surround_data_)->border_top_right_radius_ = LengthSize(Length::Fixed(0), Length::Fixed(0));
    }

    // border-top-style
    EBorderStyle BorderTopStyle() const
    {
        return static_cast<EBorderStyle>(box_data_->border_top_style_);
    }

    void SetBorderTopStyle(EBorderStyle v)
    {
        if (!(box_data_->border_top_style_ == static_cast<unsigned>(v)))
            Access(box_data_, access_.box_data_)->border_top_style_ = static_cast<unsigned>(v);
    }

    inline void ResetBorderTopStyle()
    {
        Access(box_data_, access_.box_data_)->border_top_style_ = static_cast<unsigned>(EBorderStyle::kNone);
    }

    // border-top-width

    void SetBorderTopWidth(const int& v)
    {
        if (!(box_data_->border_top_width_ == v))
            Access(box_data_, access_.box_data_)->border_top_width_ = v;
    }

    void SetBorderTopWidth(int&& v)
    {
        if (!(box_data_->border_top_width_ == v))
            Access(box_data_, access_.box_data_)->border_top_width_ = std::move(v);
    }

    inline void ResetBorderTopWidth()
    {
        Access(box_data_, access_.box_data_)->border_top_width_ = 3;
    }

    // bottom
    const Length& Bottom() const
    {
        return surround_data_->bottom_;
    }

    void SetBottom(const Length& v)
    {
        if (!(surround_data_->bottom_ == v))
            Access(surround_data_, access_.surround_data_)->bottom_ = v;
    }

    void SetBottom(Length&& v)
    {
        if (!(surround_data_->bottom_ == v))
            Access(surround_data_, access_.surround_data_)->bottom_ = std::move(v);
    }

    inline void ResetBottom()
    {
        Access(surround_data_, access_.surround_data_)->bottom_ = Length();
    }

    // -webkit-box-align
    EBoxAlignment BoxAlign() const
    {
        return static_cast<EBoxAlignment>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_align_);
    }

    void SetBoxAlign(EBoxAlignment v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_align_ == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->box_align_
                = static_cast<unsigned>(v);
    }

    inline void ResetBoxAlign()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->box_align_
            = static_cast<unsigned>(EBoxAlignment::kStretch);
    }

    // box-decoration-break
    EBoxDecorationBreak BoxDecorationBreak() const
    {
        return static_cast<EBoxDecorationBreak>(box_data_->box_decoration_break_);
    }

    void SetBoxDecorationBreak(EBoxDecorationBreak v)
    {
        if (!(box_data_->box_decoration_break_ == static_cast<unsigned>(v)))
            Access(box_data_, access_.box_data_)->box_decoration_break_ = static_cast<unsigned>(v);
    }

    inline void ResetBoxDecorationBreak()
    {
        Access(box_data_, access_.box_data_)->box_decoration_break_ = static_cast<unsigned>(EBoxDecorationBreak::kSlice);
    }

    // -webkit-box-direction

    void SetBoxDirection(EBoxDirection v)
    {
        data_.box_direction_ = static_cast<unsigned>(v);
    }

    inline void ResetBoxDirection()
    {
        data_.box_direction_ = static_cast<unsigned>(EBoxDirection::kNormal);
    }

    // -webkit-box-flex
    float BoxFlex() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_flex_;
    }

    void SetBoxFlex(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_flex_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->box_flex_
                = v;
    }

    inline void ResetBoxFlex()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->box_flex_
            = 0.0f;
    }

    // -webkit-box-ordinal-group
    unsigned BoxOrdinalGroup() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->box_ordinal_group_;
    }

    inline void ResetBoxOrdinalGroup()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->box_ordinal_group_
            = 1;
    }

    // -webkit-box-orient
    EBoxOrient BoxOrient() const
    {
        return static_cast<EBoxOrient>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_orient_);
    }

    void SetBoxOrient(EBoxOrient v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_orient_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->box_orient_
                = static_cast<unsigned>(v);
    }

    inline void ResetBoxOrient()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->box_orient_
            = static_cast<unsigned>(EBoxOrient::kHorizontal);
    }

    // -webkit-box-pack
    EBoxPack BoxPack() const
    {
        return static_cast<EBoxPack>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_pack_);
    }

    void SetBoxPack(EBoxPack v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_pack_ == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->box_pack_
                = static_cast<unsigned>(v);
    }

    inline void ResetBoxPack()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->box_pack_
            = static_cast<unsigned>(EBoxPack::kStart);
    }

    // -webkit-box-reflect
    StyleReflection* BoxReflect() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->box_reflect_.get();
    }

    void SetBoxReflect(scoped_refptr<StyleReflection> v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->box_reflect_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->box_reflect_
                = std::move(v);
    }

    // box-shadow
    ShadowList* BoxShadow() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->box_shadow_.Get();
    }

    void SetBoxShadow(Member<ShadowList> v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->box_shadow_ == v))
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->box_shadow_
                = std::move(v);
    }

    // box-sizing
    EBoxSizing BoxSizing() const
    {
        return static_cast<EBoxSizing>(data_.box_sizing_);
    }

    void SetBoxSizing(EBoxSizing v)
    {
        data_.box_sizing_ = static_cast<unsigned>(v);
    }

    inline void ResetBoxSizing()
    {
        data_.box_sizing_ = static_cast<unsigned>(EBoxSizing::kContentBox);
    }

    // break-after
    EBreakBetween BreakAfter() const
    {
        return static_cast<EBreakBetween>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                              ->rare_non_inherited_usage_less_than_100_percent_data_->break_after_);
    }

    void SetBreakAfter(EBreakBetween v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->break_after_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->break_after_
                = static_cast<unsigned>(v);
    }

    inline void ResetBreakAfter()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->break_after_
            = static_cast<unsigned>(EBreakBetween::kAuto);
    }

    // break-before
    EBreakBetween BreakBefore() const
    {
        return static_cast<EBreakBetween>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                              ->rare_non_inherited_usage_less_than_100_percent_data_->break_before_);
    }

    void SetBreakBefore(EBreakBetween v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->break_before_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->break_before_
                = static_cast<unsigned>(v);
    }

    inline void ResetBreakBefore()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->break_before_
            = static_cast<unsigned>(EBreakBetween::kAuto);
    }

    // break-inside
    EBreakInside BreakInside() const
    {
        return static_cast<EBreakInside>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                             ->rare_non_inherited_usage_less_than_100_percent_data_->break_inside_);
    }

    void SetBreakInside(EBreakInside v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->break_inside_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->break_inside_
                = static_cast<unsigned>(v);
    }

    inline void ResetBreakInside()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->break_inside_
            = static_cast<unsigned>(EBreakInside::kAuto);
    }

    // buffered-rendering
    EBufferedRendering BufferedRendering() const
    {
        return static_cast<EBufferedRendering>(svg_data_->buffered_rendering_);
    }

    void SetBufferedRendering(EBufferedRendering v)
    {
        if (!(svg_data_->buffered_rendering_ == static_cast<unsigned>(v)))
            Access(svg_data_, access_.svg_data_)->buffered_rendering_ = static_cast<unsigned>(v);
    }

    inline void ResetBufferedRendering()
    {
        Access(svg_data_, access_.svg_data_)->buffered_rendering_ = static_cast<unsigned>(EBufferedRendering::kAuto);
    }

    // CallbackSelectors
    const Vector<String>& CallbackSelectors() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->callback_selectors_;
    }

    inline void ResetCallbackSelectors()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->callback_selectors_
            = Vector<String>();
    }

    // CanAffectAnimations
    bool CanAffectAnimations() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->can_affect_animations_);
    }

    void SetCanAffectAnimations()
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->can_affect_animations_
                == static_cast<unsigned>(true)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->can_affect_animations_
                = static_cast<unsigned>(true);
    }

    // stroke-linecap
    LineCap CapStyle() const
    {
        return static_cast<LineCap>(svg_data_->stroke_data_->cap_style_);
    }

    void SetCapStyle(LineCap v)
    {
        if (!(svg_data_->stroke_data_->cap_style_ == static_cast<unsigned>(v)))
            Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->cap_style_ = static_cast<unsigned>(v);
    }

    inline void ResetCapStyle()
    {
        Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->cap_style_ = static_cast<unsigned>(kButtCap);
    }

    // caption-side
    ECaptionSide CaptionSide() const
    {
        return static_cast<ECaptionSide>(data_.caption_side_);
    }

    void SetCaptionSide(ECaptionSide v)
    {
        data_.caption_side_ = static_cast<unsigned>(v);
    }

    inline void ResetCaptionSide()
    {
        data_.caption_side_ = static_cast<unsigned>(ECaptionSide::kTop);
    }

    // caption-side
    bool CaptionSideIsInherited() const
    {
        return static_cast<bool>(data_.caption_side_is_inherited_);
    }

    void SetCaptionSideIsInherited(bool v)
    {
        data_.caption_side_is_inherited_ = static_cast<unsigned>(v);
    }

    inline void ResetCaptionSideIsInherited()
    {
        data_.caption_side_is_inherited_ = static_cast<unsigned>(true);
    }

    // caret-animation
    ECaretAnimation CaretAnimation() const
    {
        return static_cast<ECaretAnimation>(data_.caret_animation_);
    }

    void SetCaretAnimation(ECaretAnimation v)
    {
        data_.caret_animation_ = static_cast<unsigned>(v);
    }

    inline void ResetCaretAnimation()
    {
        data_.caret_animation_ = static_cast<unsigned>(ECaretAnimation::kAuto);
    }

    // caret-color

    void SetCaretColor(const StyleAutoColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->caret_color_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->caret_color_ = v;
    }

    void SetCaretColor(StyleAutoColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->caret_color_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->caret_color_ = std::move(v);
    }

    inline void ResetCaretColor()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->caret_color_
            = StyleAutoColor::AutoColor();
    }

    // clear

    void SetClear(EClear v)
    {
        data_.clear_ = static_cast<unsigned>(v);
    }

    inline void ResetClear()
    {
        data_.clear_ = static_cast<unsigned>(EClear::kNone);
    }

    // clip
    const LengthBox& Clip() const
    {
        return visual_data_->clip_;
    }

    inline void ResetClip()
    {
        Access(visual_data_, access_.visual_data_)->clip_ = LengthBox();
    }

    // clip-path

    inline void ResetClipPath()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->clip_path_
            = nullptr;
    }

    // clip-rule
    WindRule ClipRule() const
    {
        return static_cast<WindRule>(svg_data_->clip_rule_);
    }

    void SetClipRule(WindRule v)
    {
        if (!(svg_data_->clip_rule_ == static_cast<unsigned>(v)))
            Access(svg_data_, access_.svg_data_)->clip_rule_ = static_cast<unsigned>(v);
    }

    inline void ResetClipRule()
    {
        Access(svg_data_, access_.svg_data_)->clip_rule_ = static_cast<unsigned>(RULE_NONZERO);
    }

    // color

    void SetColor(const StyleColor& v)
    {
        if (!(inherited_data_->color_ == v))
            Access(inherited_data_, access_.inherited_data_)->color_ = v;
    }

    void SetColor(StyleColor&& v)
    {
        if (!(inherited_data_->color_ == v))
            Access(inherited_data_, access_.inherited_data_)->color_ = std::move(v);
    }

    inline void ResetColor()
    {
        Access(inherited_data_, access_.inherited_data_)->color_ = StyleColor(Color::kBlack);
    }

    // color-interpolation
    EColorInterpolation ColorInterpolation() const
    {
        return static_cast<EColorInterpolation>(svg_data_->color_interpolation_);
    }

    void SetColorInterpolation(EColorInterpolation v)
    {
        if (!(svg_data_->color_interpolation_ == static_cast<unsigned>(v)))
            Access(svg_data_, access_.svg_data_)->color_interpolation_ = static_cast<unsigned>(v);
    }

    inline void ResetColorInterpolation()
    {
        Access(svg_data_, access_.svg_data_)->color_interpolation_ = static_cast<unsigned>(EColorInterpolation::kSRGB);
    }

    // color-interpolation-filters
    EColorInterpolation ColorInterpolationFilters() const
    {
        return static_cast<EColorInterpolation>(svg_data_->color_interpolation_filters_);
    }

    void SetColorInterpolationFilters(EColorInterpolation v)
    {
        if (!(svg_data_->color_interpolation_filters_ == static_cast<unsigned>(v)))
            Access(svg_data_, access_.svg_data_)->color_interpolation_filters_ = static_cast<unsigned>(v);
    }

    inline void ResetColorInterpolationFilters()
    {
        Access(svg_data_, access_.svg_data_)->color_interpolation_filters_ = static_cast<unsigned>(EColorInterpolation::kLinearrgb);
    }

    // ColorIsCurrentColor

    void SetColorIsCurrentColor(bool v)
    {
        if (!(inherited_data_->color_is_current_color_ == static_cast<unsigned>(v)))
            Access(inherited_data_, access_.inherited_data_)->color_is_current_color_ = static_cast<unsigned>(v);
    }

    inline void ResetColorIsCurrentColor()
    {
        Access(inherited_data_, access_.inherited_data_)->color_is_current_color_ = static_cast<unsigned>(true);
    }

    // color

    void SetColorIsInherited(bool v)
    {
        data_.color_is_inherited_ = static_cast<unsigned>(v);
    }

    inline void ResetColorIsInherited()
    {
        data_.color_is_inherited_ = static_cast<unsigned>(true);
    }

    // color-rendering
    EColorRendering ColorRendering() const
    {
        return static_cast<EColorRendering>(svg_data_->color_rendering_);
    }

    void SetColorRendering(EColorRendering v)
    {
        if (!(svg_data_->color_rendering_ == static_cast<unsigned>(v)))
            Access(svg_data_, access_.svg_data_)->color_rendering_ = static_cast<unsigned>(v);
    }

    inline void ResetColorRendering()
    {
        Access(svg_data_, access_.svg_data_)->color_rendering_ = static_cast<unsigned>(EColorRendering::kAuto);
    }

    // color-scheme
    const Vector<AtomicString>& ColorScheme() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->color_scheme_;
    }

    void SetColorScheme(const Vector<AtomicString>& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->color_scheme_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->color_scheme_ = v;
    }

    void SetColorScheme(Vector<AtomicString>&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->color_scheme_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->color_scheme_ = std::move(v);
    }

    inline void ResetColorScheme()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->color_scheme_
            = Vector<AtomicString, 0>();
    }

    // ColorSchemeFlagsIsNormal
    bool ColorSchemeFlagsIsNormal() const
    {
        return static_cast<bool>(data_.color_scheme_flags_is_normal_);
    }

    void SetColorSchemeFlagsIsNormal(bool v)
    {
        data_.color_scheme_flags_is_normal_ = static_cast<unsigned>(v);
    }

    inline void ResetColorSchemeFlagsIsNormal()
    {
        data_.color_scheme_flags_is_normal_ = static_cast<unsigned>(false);
    }

    // ColorSchemeForced
    bool ColorSchemeForced() const
    {
        return static_cast<bool>(data_.color_scheme_forced_);
    }

    void SetColorSchemeForced(bool v)
    {
        data_.color_scheme_forced_ = static_cast<unsigned>(v);
    }

    inline void ResetColorSchemeForced()
    {
        data_.color_scheme_forced_ = static_cast<unsigned>(false);
    }

    // column-count
    unsigned short ColumnCount() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->column_count_;
    }

    inline void ResetColumnCount()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->column_count_
            = 1;
    }

    // column-fill
    EColumnFill GetColumnFill() const
    {
        return static_cast<EColumnFill>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->column_fill_);
    }

    void SetColumnFill(EColumnFill v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->column_fill_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->column_fill_
                = static_cast<unsigned>(v);
    }

    inline void ResetColumnFill()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->column_fill_
            = static_cast<unsigned>(EColumnFill::kBalance);
    }

    // column-gap
    const std::optional<Length>& ColumnGap() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->column_gap_;
    }

    void SetColumnGap(const std::optional<Length>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->column_gap_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->column_gap_
                = v;
    }

    void SetColumnGap(std::optional<Length>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->column_gap_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->column_gap_
                = std::move(v);
    }

    inline void ResetColumnGap()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->column_gap_
            = std::nullopt;
    }

    // column-rule-color
    const GapDataList<StyleColor>& ColumnRuleColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_color_;
    }

    void SetColumnRuleColor(const GapDataList<StyleColor>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->column_rule_color_
                = v;
    }

    void SetColumnRuleColor(GapDataList<StyleColor>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->column_rule_color_
                = std::move(v);
    }

    inline void ResetColumnRuleColor()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->column_rule_color_
            = GapDataList<StyleColor>::DefaultGapColorDataList();
    }

    // column-rule-style
    EBorderStyle ColumnRuleStyle() const
    {
        return static_cast<EBorderStyle>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                             ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_style_);
    }

    void SetColumnRuleStyle(EBorderStyle v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_style_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->column_rule_style_
                = static_cast<unsigned>(v);
    }

    inline void ResetColumnRuleStyle()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->column_rule_style_
            = static_cast<unsigned>(EBorderStyle::kNone);
    }

    // column-rule-width

    inline void ResetColumnRuleWidth()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->column_rule_width_
            = 3;
    }

    // column-span
    EColumnSpan GetColumnSpan() const
    {
        return static_cast<EColumnSpan>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->column_span_);
    }

    void SetColumnSpan(EColumnSpan v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->column_span_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->column_span_
                = static_cast<unsigned>(v);
    }

    inline void ResetColumnSpan()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->column_span_
            = static_cast<unsigned>(EColumnSpan::kNone);
    }

    // column-width
    float ColumnWidth() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->column_width_;
    }

    inline void ResetColumnWidth()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->column_width_
            = 0.0f;
    }

    // contain
    unsigned Contain() const
    {
        return static_cast<unsigned>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                         ->rare_non_inherited_usage_less_than_100_percent_data_->contain_);
    }

    void SetContain(unsigned v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->contain_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->contain_
                = static_cast<unsigned>(v);
    }

    inline void ResetContain()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->contain_
            = static_cast<unsigned>(kContainsNone);
    }

    // contain-intrinsic-height
    const StyleIntrinsicLength& ContainIntrinsicHeight() const
    {
        return surround_data_->contain_intrinsic_height_;
    }

    void SetContainIntrinsicHeight(const StyleIntrinsicLength& v)
    {
        if (!(surround_data_->contain_intrinsic_height_ == v))
            Access(surround_data_, access_.surround_data_)->contain_intrinsic_height_ = v;
    }

    void SetContainIntrinsicHeight(StyleIntrinsicLength&& v)
    {
        if (!(surround_data_->contain_intrinsic_height_ == v))
            Access(surround_data_, access_.surround_data_)->contain_intrinsic_height_ = std::move(v);
    }

    inline void ResetContainIntrinsicHeight()
    {
        Access(surround_data_, access_.surround_data_)->contain_intrinsic_height_ = StyleIntrinsicLength();
    }

    // contain-intrinsic-width
    const StyleIntrinsicLength& ContainIntrinsicWidth() const
    {
        return surround_data_->contain_intrinsic_width_;
    }

    void SetContainIntrinsicWidth(const StyleIntrinsicLength& v)
    {
        if (!(surround_data_->contain_intrinsic_width_ == v))
            Access(surround_data_, access_.surround_data_)->contain_intrinsic_width_ = v;
    }

    void SetContainIntrinsicWidth(StyleIntrinsicLength&& v)
    {
        if (!(surround_data_->contain_intrinsic_width_ == v))
            Access(surround_data_, access_.surround_data_)->contain_intrinsic_width_ = std::move(v);
    }

    inline void ResetContainIntrinsicWidth()
    {
        Access(surround_data_, access_.surround_data_)->contain_intrinsic_width_ = StyleIntrinsicLength();
    }

    // container-name
    const Member<ScopedCSSNameList>& ContainerName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_name_;
    }

    void SetContainerName(const Member<ScopedCSSNameList>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_name_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->container_name_
                = v;
    }

    void SetContainerName(Member<ScopedCSSNameList>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_name_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->container_name_
                = std::move(v);
    }

    inline void ResetContainerName()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->container_name_
            = nullptr;
    }

    // container-type
    unsigned ContainerType() const
    {
        return static_cast<unsigned>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_type_);
    }

    void SetContainerType(unsigned v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_type_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->container_type_
                = static_cast<unsigned>(v);
    }

    inline void ResetContainerType()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->container_type_
            = static_cast<unsigned>(kContainerTypeNormal);
    }

    // content

    void SetContent(const Member<ContentData>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->content_ == v))
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->content_ = v;
    }

    void SetContent(Member<ContentData>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->content_ == v))
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->content_ = std::move(v);
    }

    inline void ResetContent()
    {
        Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->content_ = nullptr;
    }

    // content-visibility
    EContentVisibility ContentVisibility() const
    {
        return static_cast<EContentVisibility>(data_.content_visibility_);
    }

    void SetContentVisibility(EContentVisibility v)
    {
        data_.content_visibility_ = static_cast<unsigned>(v);
    }

    inline void ResetContentVisibility()
    {
        data_.content_visibility_ = static_cast<unsigned>(EContentVisibility::kVisible);
    }

    // CounterDirectives

    inline void ResetCounterDirectives()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->counter_directives_
            = nullptr;
    }

    // CssDominantBaseline
    EDominantBaseline CssDominantBaseline() const
    {
        return static_cast<EDominantBaseline>(svg_data_->css_dominant_baseline_);
    }

    void SetCssDominantBaseline(EDominantBaseline v)
    {
        if (!(svg_data_->css_dominant_baseline_ == static_cast<unsigned>(v)))
            Access(svg_data_, access_.svg_data_)->css_dominant_baseline_ = static_cast<unsigned>(v);
    }

    inline void ResetCssDominantBaseline()
    {
        Access(svg_data_, access_.svg_data_)->css_dominant_baseline_ = static_cast<unsigned>(EDominantBaseline::kAuto);
    }

    // cursor
    ECursor Cursor() const
    {
        return static_cast<ECursor>(data_.cursor_);
    }

    void SetCursor(ECursor v)
    {
        data_.cursor_ = static_cast<unsigned>(v);
    }

    inline void ResetCursor()
    {
        data_.cursor_ = static_cast<unsigned>(ECursor::kAuto);
    }

    // CursorData

    inline void ResetCursorData()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->cursor_data_
            = nullptr;
    }

    // CustomHighlightNames

    inline void ResetCustomHighlightNames()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->custom_highlight_names_
            = nullptr;
    }

    // CustomStyleCallbackDependsOnFont
    bool CustomStyleCallbackDependsOnFont() const
    {
        return static_cast<bool>(data_.custom_style_callback_depends_on_font_);
    }

    void SetCustomStyleCallbackDependsOnFont()
    {
        data_.custom_style_callback_depends_on_font_ = static_cast<unsigned>(true);
    }

    // cx
    const Length& Cx() const
    {
        return svg_data_->geometry_data_->cx_;
    }

    void SetCx(const Length& v)
    {
        if (!(svg_data_->geometry_data_->cx_ == v))
            Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cx_ = v;
    }

    void SetCx(Length&& v)
    {
        if (!(svg_data_->geometry_data_->cx_ == v))
            Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cx_ = std::move(v);
    }

    inline void ResetCx()
    {
        Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cx_ = Length::Fixed();
    }

    // cy
    const Length& Cy() const
    {
        return svg_data_->geometry_data_->cy_;
    }

    void SetCy(const Length& v)
    {
        if (!(svg_data_->geometry_data_->cy_ == v))
            Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cy_ = v;
    }

    void SetCy(Length&& v)
    {
        if (!(svg_data_->geometry_data_->cy_ == v))
            Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cy_ = std::move(v);
    }

    inline void ResetCy()
    {
        Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cy_ = Length::Fixed();
    }

    // d
    StylePath* D() const
    {
        return svg_data_->geometry_data_->d_.get();
    }

    void SetD(scoped_refptr<StylePath> v)
    {
        if (!(svg_data_->geometry_data_->d_ == v))
            Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->d_ = std::move(v);
    }

    // DarkColorScheme
    bool DarkColorScheme() const
    {
        return static_cast<bool>(data_.dark_color_scheme_);
    }

    void SetDarkColorScheme(bool v)
    {
        data_.dark_color_scheme_ = static_cast<unsigned>(v);
    }

    inline void ResetDarkColorScheme()
    {
        data_.dark_color_scheme_ = static_cast<unsigned>(false);
    }

    // DependsOnScrollStateContainerQueries
    bool DependsOnScrollStateContainerQueries() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->depends_on_scroll_state_container_queries_);
    }

    void SetDependsOnScrollStateContainerQueries(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->depends_on_scroll_state_container_queries_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->depends_on_scroll_state_container_queries_
                = static_cast<unsigned>(v);
    }

    inline void ResetDependsOnScrollStateContainerQueries()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->depends_on_scroll_state_container_queries_
            = static_cast<unsigned>(false);
    }

    // DependsOnSizeContainerQueries
    bool DependsOnSizeContainerQueries() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_size_container_queries_);
    }

    void SetDependsOnSizeContainerQueries(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_size_container_queries_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->depends_on_size_container_queries_
                = static_cast<unsigned>(v);
    }

    inline void ResetDependsOnSizeContainerQueries()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->depends_on_size_container_queries_
            = static_cast<unsigned>(false);
    }

    // DependsOnStyleContainerQueries
    bool DependsOnStyleContainerQueries() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_style_container_queries_);
    }

    void SetDependsOnStyleContainerQueries(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_style_container_queries_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->depends_on_style_container_queries_
                = static_cast<unsigned>(v);
    }

    inline void ResetDependsOnStyleContainerQueries()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->depends_on_style_container_queries_
            = static_cast<unsigned>(false);
    }

    // direction
    TextDirection Direction() const
    {
        return static_cast<TextDirection>(data_.direction_);
    }

    void SetDirection(TextDirection v)
    {
        data_.direction_ = static_cast<unsigned>(v);
    }

    inline void ResetDirection()
    {
        data_.direction_ = static_cast<unsigned>(TextDirection::kLtr);
    }

    // Display
    EDisplay Display() const
    {
        return static_cast<EDisplay>(data_.display_);
    }

    void SetDisplay(EDisplay v)
    {
        data_.display_ = static_cast<unsigned>(v);
    }

    inline void ResetDisplay()
    {
        data_.display_ = static_cast<unsigned>(EDisplay::kInline);
    }

    // DisplayLayoutCustomName
    const AtomicString& DisplayLayoutCustomName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_name_;
    }

    void SetDisplayLayoutCustomName(const AtomicString& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_name_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->display_layout_custom_name_
                = v;
    }

    void SetDisplayLayoutCustomName(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_name_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->display_layout_custom_name_
                = std::move(v);
    }

    inline void ResetDisplayLayoutCustomName()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->display_layout_custom_name_
            = g_null_atom;
    }

    // DisplayLayoutCustomParentName
    const AtomicString& DisplayLayoutCustomParentName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_parent_name_;
    }

    void SetDisplayLayoutCustomParentName(const AtomicString& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_parent_name_
                == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->display_layout_custom_parent_name_
                = v;
    }

    void SetDisplayLayoutCustomParentName(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_parent_name_
                == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->display_layout_custom_parent_name_
                = std::move(v);
    }

    inline void ResetDisplayLayoutCustomParentName()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->display_layout_custom_parent_name_
            = g_null_atom;
    }

    // DocumentRulesSelectors
    const Member<HeapHashSet<WeakMember<StyleRule>>>& DocumentRulesSelectors() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->document_rules_selectors_;
    }

    inline void ResetDocumentRulesSelectors()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->document_rules_selectors_
            = nullptr;
    }

    // dominant-baseline
    EDominantBaseline DominantBaseline() const
    {
        return static_cast<EDominantBaseline>(svg_data_->dominant_baseline_);
    }

    void SetDominantBaseline(EDominantBaseline v)
    {
        if (!(svg_data_->dominant_baseline_ == static_cast<unsigned>(v)))
            Access(svg_data_, access_.svg_data_)->dominant_baseline_ = static_cast<unsigned>(v);
    }

    inline void ResetDominantBaseline()
    {
        Access(svg_data_, access_.svg_data_)->dominant_baseline_ = static_cast<unsigned>(EDominantBaseline::kAuto);
    }

    // app-region
    EDraggableRegionMode DraggableRegionMode() const
    {
        return static_cast<EDraggableRegionMode>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                     ->rare_non_inherited_usage_less_than_100_percent_data_->draggable_region_mode_);
    }

    void SetDraggableRegionMode(EDraggableRegionMode v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->draggable_region_mode_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->draggable_region_mode_
                = static_cast<unsigned>(v);
    }

    inline void ResetDraggableRegionMode()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->draggable_region_mode_
            = static_cast<unsigned>(EDraggableRegionMode::kNone);
    }

    // dynamic-range-limit
    const DynamicRangeLimit& GetDynamicRangeLimit() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->dynamic_range_limit_;
    }

    void SetDynamicRangeLimit(const DynamicRangeLimit& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->dynamic_range_limit_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->dynamic_range_limit_
                = v;
    }

    void SetDynamicRangeLimit(DynamicRangeLimit&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->dynamic_range_limit_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->dynamic_range_limit_
                = std::move(v);
    }

    inline void ResetDynamicRangeLimit()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->dynamic_range_limit_
            = DynamicRangeLimit(cc::PaintFlags::DynamicRangeLimit::kHigh);
    }

    // EffectiveAppearance
    ControlPart EffectiveAppearance() const
    {
        return static_cast<ControlPart>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_appearance_);
    }

    void SetEffectiveAppearance(ControlPart v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_appearance_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->effective_appearance_
                = static_cast<unsigned>(v);
    }

    inline void ResetEffectiveAppearance()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->effective_appearance_
            = static_cast<unsigned>(kNoControlPart);
    }

    // EffectiveTouchAction
    TouchAction EffectiveTouchAction() const
    {
        return static_cast<TouchAction>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_touch_action_);
    }

    void SetEffectiveTouchAction(TouchAction v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_touch_action_
                == static_cast<unsigned>(v)))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->effective_touch_action_
                = static_cast<unsigned>(v);
    }

    inline void ResetEffectiveTouchAction()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->effective_touch_action_
            = static_cast<unsigned>(TouchAction::kAuto);
    }

    // EffectiveZIndexZero
    bool EffectiveZIndexZero() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_z_index_zero_);
    }

    void SetEffectiveZIndexZero(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_z_index_zero_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->effective_z_index_zero_
                = static_cast<unsigned>(v);
    }

    inline void ResetEffectiveZIndexZero()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->effective_z_index_zero_
            = static_cast<unsigned>(false);
    }

    // EffectiveZoom
    float EffectiveZoom() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_zoom_;
    }

    inline void ResetEffectiveZoom()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->effective_zoom_
            = 1.0f;
    }

    // ElementIsViewTransitionParticipant
    bool ElementIsViewTransitionParticipant() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->element_is_view_transition_participant_);
    }

    void SetElementIsViewTransitionParticipant()
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->element_is_view_transition_participant_
                == static_cast<unsigned>(true)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->element_is_view_transition_participant_
                = static_cast<unsigned>(true);
    }

    // empty-cells
    EEmptyCells EmptyCells() const
    {
        return static_cast<EEmptyCells>(data_.empty_cells_);
    }

    void SetEmptyCells(EEmptyCells v)
    {
        data_.empty_cells_ = static_cast<unsigned>(v);
    }

    inline void ResetEmptyCells()
    {
        data_.empty_cells_ = static_cast<unsigned>(EEmptyCells::kShow);
    }

    // empty-cells
    bool EmptyCellsIsInherited() const
    {
        return static_cast<bool>(data_.empty_cells_is_inherited_);
    }

    void SetEmptyCellsIsInherited(bool v)
    {
        data_.empty_cells_is_inherited_ = static_cast<unsigned>(v);
    }

    inline void ResetEmptyCellsIsInherited()
    {
        data_.empty_cells_is_inherited_ = static_cast<unsigned>(true);
    }

    // field-sizing
    EFieldSizing FieldSizing() const
    {
        return static_cast<EFieldSizing>(visual_data_->field_sizing_);
    }

    void SetFieldSizing(EFieldSizing v)
    {
        if (!(visual_data_->field_sizing_ == static_cast<unsigned>(v)))
            Access(visual_data_, access_.visual_data_)->field_sizing_ = static_cast<unsigned>(v);
    }

    inline void ResetFieldSizing()
    {
        Access(visual_data_, access_.visual_data_)->field_sizing_ = static_cast<unsigned>(EFieldSizing::kFixed);
    }

    // fill-opacity
    float FillOpacity() const
    {
        return svg_data_->fill_data_->fill_opacity_;
    }

    void SetFillOpacity(float v)
    {
        if (!(svg_data_->fill_data_->fill_opacity_ == v))
            Access(Access(svg_data_, access_.svg_data_)->fill_data_, access_.fill_data_)->fill_opacity_ = v;
    }

    inline void ResetFillOpacity()
    {
        Access(Access(svg_data_, access_.svg_data_)->fill_data_, access_.fill_data_)->fill_opacity_ = 1;
    }

    // fill
    const SVGPaint& FillPaint() const
    {
        return svg_data_->fill_data_->fill_paint_;
    }

    void SetFillPaint(const SVGPaint& v)
    {
        if (!(svg_data_->fill_data_->fill_paint_ == v))
            Access(Access(svg_data_, access_.svg_data_)->fill_data_, access_.fill_data_)->fill_paint_ = v;
    }

    void SetFillPaint(SVGPaint&& v)
    {
        if (!(svg_data_->fill_data_->fill_paint_ == v))
            Access(Access(svg_data_, access_.svg_data_)->fill_data_, access_.fill_data_)->fill_paint_ = std::move(v);
    }

    inline void ResetFillPaint()
    {
        Access(Access(svg_data_, access_.svg_data_)->fill_data_, access_.fill_data_)->fill_paint_ = SVGPaint(Color::kBlack);
    }

    // fill-rule
    WindRule FillRule() const
    {
        return static_cast<WindRule>(svg_data_->fill_rule_);
    }

    void SetFillRule(WindRule v)
    {
        if (!(svg_data_->fill_rule_ == static_cast<unsigned>(v)))
            Access(svg_data_, access_.svg_data_)->fill_rule_ = static_cast<unsigned>(v);
    }

    inline void ResetFillRule()
    {
        Access(svg_data_, access_.svg_data_)->fill_rule_ = static_cast<unsigned>(RULE_NONZERO);
    }

    // filter
    const FilterOperations& Filter() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->filter_;
    }

    void SetFilter(const FilterOperations& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->filter_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->filter_
                = v;
    }

    void SetFilter(FilterOperations&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->filter_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->filter_
                = std::move(v);
    }

    inline void ResetFilter()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->filter_
            = FilterOperations();
    }

    // FirstLineDependsOnSizeContainerQueries
    bool FirstLineDependsOnSizeContainerQueries() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->first_line_depends_on_size_container_queries_);
    }

    void SetFirstLineDependsOnSizeContainerQueries(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->first_line_depends_on_size_container_queries_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->first_line_depends_on_size_container_queries_
                = static_cast<unsigned>(v);
    }

    inline void ResetFirstLineDependsOnSizeContainerQueries()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->first_line_depends_on_size_container_queries_
            = static_cast<unsigned>(false);
    }

    // flex-basis
    const Length& FlexBasis() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_;
    }

    void SetFlexBasis(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->flex_basis_
                = v;
    }

    void SetFlexBasis(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->flex_basis_
                = std::move(v);
    }

    inline void ResetFlexBasis()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->flex_basis_
            = Length::Auto();
    }

    // flex-direction
    EFlexDirection FlexDirection() const
    {
        return static_cast<EFlexDirection>(rare_non_inherited_usage_less_than_14_percent_data_->flex_direction_);
    }

    void SetFlexDirection(EFlexDirection v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->flex_direction_ == static_cast<unsigned>(v)))
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->flex_direction_
                = static_cast<unsigned>(v);
    }

    inline void ResetFlexDirection()
    {
        Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->flex_direction_
            = static_cast<unsigned>(EFlexDirection::kRow);
    }

    // flex-grow
    float FlexGrow() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_grow_;
    }

    void SetFlexGrow(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_grow_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->flex_grow_
                = v;
    }

    inline void ResetFlexGrow()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->flex_grow_
            = 0.0f;
    }

    // flex-shrink
    float FlexShrink() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_shrink_;
    }

    void SetFlexShrink(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_shrink_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->flex_shrink_
                = v;
    }

    inline void ResetFlexShrink()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->flex_shrink_
            = 1.0f;
    }

    // flex-wrap
    EFlexWrap FlexWrap() const
    {
        return static_cast<EFlexWrap>(rare_non_inherited_usage_less_than_14_percent_data_->flex_wrap_);
    }

    void SetFlexWrap(EFlexWrap v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->flex_wrap_ == static_cast<unsigned>(v)))
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->flex_wrap_
                = static_cast<unsigned>(v);
    }

    inline void ResetFlexWrap()
    {
        Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->flex_wrap_
            = static_cast<unsigned>(EFlexWrap::kNowrap);
    }

    // float

    void SetFloating(EFloat v)
    {
        data_.floating_ = static_cast<unsigned>(v);
    }

    inline void ResetFloating()
    {
        data_.floating_ = static_cast<unsigned>(EFloat::kNone);
    }

    // flood-color
    const StyleColor& FloodColor() const
    {
        return svg_data_->misc_data_->flood_color_;
    }

    void SetFloodColor(const StyleColor& v)
    {
        if (!(svg_data_->misc_data_->flood_color_ == v))
            Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->flood_color_ = v;
    }

    void SetFloodColor(StyleColor&& v)
    {
        if (!(svg_data_->misc_data_->flood_color_ == v))
            Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->flood_color_ = std::move(v);
    }

    inline void ResetFloodColor()
    {
        Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->flood_color_ = StyleColor(Color::kBlack);
    }

    // flood-opacity
    float FloodOpacity() const
    {
        return svg_data_->misc_data_->flood_opacity_;
    }

    void SetFloodOpacity(float v)
    {
        if (!(svg_data_->misc_data_->flood_opacity_ == v))
            Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->flood_opacity_ = v;
    }

    inline void ResetFloodOpacity()
    {
        Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->flood_opacity_ = 1;
    }

    // font
    const Font& GetFont() const
    {
        return font_data_->font_;
    }

    void SetFont(const Font& v)
    {
        if (!(font_data_->font_ == v))
            Access(font_data_, access_.font_data_)->font_ = v;
    }

    void SetFont(Font&& v)
    {
        if (!(font_data_->font_ == v))
            Access(font_data_, access_.font_data_)->font_ = std::move(v);
    }

    inline void ResetFont()
    {
        Access(font_data_, access_.font_data_)->font_ = Font();
    }

    // forced-color-adjust
    EForcedColorAdjust ForcedColorAdjust() const
    {
        return static_cast<EForcedColorAdjust>(rare_inherited_usage_less_than_64_percent_data_->forced_color_adjust_);
    }

    void SetForcedColorAdjust(EForcedColorAdjust v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->forced_color_adjust_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->forced_color_adjust_
                = static_cast<unsigned>(v);
    }

    inline void ResetForcedColorAdjust()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->forced_color_adjust_
            = static_cast<unsigned>(EForcedColorAdjust::kAuto);
    }

    // ForcesStackingContext
    bool ForcesStackingContext() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forces_stacking_context_);
    }

    void SetForcesStackingContext(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forces_stacking_context_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->forces_stacking_context_
                = static_cast<unsigned>(v);
    }

    inline void ResetForcesStackingContext()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->forces_stacking_context_
            = static_cast<unsigned>(false);
    }

    // grid-auto-columns
    const NGGridTrackList& GridAutoColumns() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_columns_;
    }

    void SetGridAutoColumns(const NGGridTrackList& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_columns_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_auto_columns_
                = v;
    }

    void SetGridAutoColumns(NGGridTrackList&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_columns_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_auto_columns_
                = std::move(v);
    }

    inline void ResetGridAutoColumns()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->grid_auto_columns_
            = NGGridTrackList(GridTrackSize(Length::Auto()));
    }

    // grid-auto-flow

    void SetGridAutoFlow(GridAutoFlow v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_flow_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_auto_flow_
                = static_cast<unsigned>(v);
    }

    inline void ResetGridAutoFlow()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->grid_auto_flow_
            = static_cast<unsigned>(kAutoFlowRow);
    }

    // grid-auto-rows
    const NGGridTrackList& GridAutoRows() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_rows_;
    }

    void SetGridAutoRows(const NGGridTrackList& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_rows_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_auto_rows_
                = v;
    }

    void SetGridAutoRows(NGGridTrackList&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_rows_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_auto_rows_
                = std::move(v);
    }

    inline void ResetGridAutoRows()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->grid_auto_rows_
            = NGGridTrackList(GridTrackSize(Length::Auto()));
    }

    // grid-column-end
    const GridPosition& GridColumnEnd() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_end_;
    }

    void SetGridColumnEnd(const GridPosition& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_end_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_column_end_
                = v;
    }

    void SetGridColumnEnd(GridPosition&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_end_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_column_end_
                = std::move(v);
    }

    inline void ResetGridColumnEnd()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->grid_column_end_
            = GridPosition();
    }

    // grid-column-start
    const GridPosition& GridColumnStart() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_start_;
    }

    void SetGridColumnStart(const GridPosition& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_start_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_column_start_
                = v;
    }

    void SetGridColumnStart(GridPosition&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_start_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_column_start_
                = std::move(v);
    }

    inline void ResetGridColumnStart()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->grid_column_start_
            = GridPosition();
    }

    // grid-row-end
    const GridPosition& GridRowEnd() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_end_;
    }

    void SetGridRowEnd(const GridPosition& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_end_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_row_end_
                = v;
    }

    void SetGridRowEnd(GridPosition&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_end_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_row_end_
                = std::move(v);
    }

    inline void ResetGridRowEnd()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->grid_row_end_
            = GridPosition();
    }

    // grid-row-start
    const GridPosition& GridRowStart() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_start_;
    }

    void SetGridRowStart(const GridPosition& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_start_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_row_start_
                = v;
    }

    void SetGridRowStart(GridPosition&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_start_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_row_start_
                = std::move(v);
    }

    inline void ResetGridRowStart()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->grid_row_start_
            = GridPosition();
    }

    // grid-template-areas
    const Member<ComputedGridTemplateAreas>& GridTemplateAreas() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->grid_template_areas_;
    }

    void SetGridTemplateAreas(const Member<ComputedGridTemplateAreas>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->grid_template_areas_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_template_areas_
                = v;
    }

    void SetGridTemplateAreas(Member<ComputedGridTemplateAreas>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->grid_template_areas_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_template_areas_
                = std::move(v);
    }

    inline void ResetGridTemplateAreas()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->grid_template_areas_
            = nullptr;
    }

    // grid-template-columns
    const ComputedGridTrackList& GridTemplateColumns() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_columns_;
    }

    void SetGridTemplateColumns(const ComputedGridTrackList& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_columns_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->grid_data_,
                access_.grid_data_)
                ->grid_template_columns_
                = v;
    }

    void SetGridTemplateColumns(ComputedGridTrackList&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_columns_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->grid_data_,
                access_.grid_data_)
                ->grid_template_columns_
                = std::move(v);
    }

    inline void ResetGridTemplateColumns()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->grid_data_,
            access_.grid_data_)
            ->grid_template_columns_
            = ComputedGridTrackList();
    }

    // grid-template-rows
    const ComputedGridTrackList& GridTemplateRows() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_rows_;
    }

    void SetGridTemplateRows(const ComputedGridTrackList& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_rows_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->grid_data_,
                access_.grid_data_)
                ->grid_template_rows_
                = v;
    }

    void SetGridTemplateRows(ComputedGridTrackList&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_rows_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->grid_data_,
                access_.grid_data_)
                ->grid_template_rows_
                = std::move(v);
    }

    inline void ResetGridTemplateRows()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->grid_data_,
            access_.grid_data_)
            ->grid_template_rows_
            = ComputedGridTrackList();
    }

    // HasAnchorEvaluator
    bool HasAnchorEvaluator() const
    {
        return static_cast<bool>(surround_data_->has_anchor_evaluator_);
    }

    void SetHasAnchorEvaluator()
    {
        if (!(surround_data_->has_anchor_evaluator_ == static_cast<unsigned>(true)))
            Access(surround_data_, access_.surround_data_)->has_anchor_evaluator_ = static_cast<unsigned>(true);
    }

    // HasAnchorFunctions
    bool HasAnchorFunctions() const
    {
        return static_cast<bool>(surround_data_->has_anchor_functions_);
    }

    void SetHasAnchorFunctions()
    {
        if (!(surround_data_->has_anchor_functions_ == static_cast<unsigned>(true)))
            Access(surround_data_, access_.surround_data_)->has_anchor_functions_ = static_cast<unsigned>(true);
    }

    // HasAttrFunction
    bool HasAttrFunction() const
    {
        return static_cast<bool>(data_.has_attr_function_);
    }

    void SetHasAttrFunction()
    {
        data_.has_attr_function_ = static_cast<unsigned>(true);
    }

    // HasAuthorBackground
    bool HasAuthorBackground() const
    {
        return static_cast<bool>(data_.has_author_background_);
    }

    void SetHasAuthorBackground()
    {
        data_.has_author_background_ = static_cast<unsigned>(true);
    }

    // HasAuthorBorder
    bool HasAuthorBorder() const
    {
        return static_cast<bool>(data_.has_author_border_);
    }

    void SetHasAuthorBorder()
    {
        data_.has_author_border_ = static_cast<unsigned>(true);
    }

    // HasAuthorBorderRadius
    bool HasAuthorBorderRadius() const
    {
        return static_cast<bool>(data_.has_author_border_radius_);
    }

    void SetHasAuthorBorderRadius()
    {
        data_.has_author_border_radius_ = static_cast<unsigned>(true);
    }

    // HasAuthorHighlightColors
    bool HasAuthorHighlightColors() const
    {
        return static_cast<bool>(data_.has_author_highlight_colors_);
    }

    void SetHasAuthorHighlightColors()
    {
        data_.has_author_highlight_colors_ = static_cast<unsigned>(true);
    }

    // HasAutoClip
    bool HasAutoClip() const
    {
        return static_cast<bool>(visual_data_->has_auto_clip_);
    }

    inline void ResetHasAutoClip()
    {
        Access(visual_data_, access_.visual_data_)->has_auto_clip_ = static_cast<unsigned>(true);
    }

    // HasAutoColumnCount
    bool HasAutoColumnCount() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_count_);
    }

    inline void ResetHasAutoColumnCount()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->has_auto_column_count_
            = static_cast<unsigned>(true);
    }

    // HasAutoColumnWidth
    bool HasAutoColumnWidth() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_width_);
    }

    inline void ResetHasAutoColumnWidth()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->has_auto_column_width_
            = static_cast<unsigned>(true);
    }

    // HasAutoStandardLineClamp
    bool HasAutoStandardLineClamp() const
    {
        return static_cast<bool>(box_data_->has_auto_standard_line_clamp_);
    }

    inline void ResetHasAutoStandardLineClamp()
    {
        Access(box_data_, access_.box_data_)->has_auto_standard_line_clamp_ = static_cast<unsigned>(false);
    }

    // HasAutoZIndex
    bool HasAutoZIndex() const
    {
        return static_cast<bool>(box_data_->has_auto_z_index_);
    }

    inline void ResetHasAutoZIndex()
    {
        Access(box_data_, access_.box_data_)->has_auto_z_index_ = static_cast<unsigned>(true);
    }

    // HasClipPath
    bool HasClipPath() const
    {
        return static_cast<bool>(visual_data_->has_clip_path_);
    }

    void SetHasClipPath(bool v)
    {
        if (!(visual_data_->has_clip_path_ == static_cast<unsigned>(v)))
            Access(visual_data_, access_.visual_data_)->has_clip_path_ = static_cast<unsigned>(v);
    }

    inline void ResetHasClipPath()
    {
        Access(visual_data_, access_.visual_data_)->has_clip_path_ = static_cast<unsigned>(false);
    }

    // HasContainerRelativeUnits
    bool HasContainerRelativeUnits() const
    {
        return static_cast<bool>(data_.has_container_relative_units_);
    }

    void SetHasContainerRelativeUnits()
    {
        data_.has_container_relative_units_ = static_cast<unsigned>(true);
    }

    // HasCurrentBackdropFilterAnimation
    bool HasCurrentBackdropFilterAnimation() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->has_current_backdrop_filter_animation_);
    }

    void SetHasCurrentBackdropFilterAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->has_current_backdrop_filter_animation_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->has_current_backdrop_filter_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentBackdropFilterAnimation()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->has_current_backdrop_filter_animation_
            = static_cast<unsigned>(false);
    }

    // HasCurrentBackgroundColorAnimation
    bool HasCurrentBackgroundColorAnimation() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->has_current_background_color_animation_);
    }

    void SetHasCurrentBackgroundColorAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->has_current_background_color_animation_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->has_current_background_color_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentBackgroundColorAnimation()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->has_current_background_color_animation_
            = static_cast<unsigned>(false);
    }

    // HasCurrentFilterAnimation
    bool HasCurrentFilterAnimation() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_filter_animation_);
    }

    void SetHasCurrentFilterAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_filter_animation_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->has_current_filter_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentFilterAnimation()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->has_current_filter_animation_
            = static_cast<unsigned>(false);
    }

    // HasCurrentOpacityAnimation
    bool HasCurrentOpacityAnimation() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_opacity_animation_);
    }

    void SetHasCurrentOpacityAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_opacity_animation_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->has_current_opacity_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentOpacityAnimation()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->has_current_opacity_animation_
            = static_cast<unsigned>(false);
    }

    // HasCurrentRotateAnimation
    bool HasCurrentRotateAnimation() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_rotate_animation_);
    }

    void SetHasCurrentRotateAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_rotate_animation_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->has_current_rotate_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentRotateAnimation()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->has_current_rotate_animation_
            = static_cast<unsigned>(false);
    }

    // HasCurrentScaleAnimation
    bool HasCurrentScaleAnimation() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_scale_animation_);
    }

    void SetHasCurrentScaleAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_scale_animation_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->has_current_scale_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentScaleAnimation()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->has_current_scale_animation_
            = static_cast<unsigned>(false);
    }

    // HasCurrentTransformAnimation
    bool HasCurrentTransformAnimation() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_transform_animation_);
    }

    void SetHasCurrentTransformAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_transform_animation_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->has_current_transform_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentTransformAnimation()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->has_current_transform_animation_
            = static_cast<unsigned>(false);
    }

    // HasCurrentTranslateAnimation
    bool HasCurrentTranslateAnimation() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_translate_animation_);
    }

    void SetHasCurrentTranslateAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_translate_animation_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->has_current_translate_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentTranslateAnimation()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->has_current_translate_animation_
            = static_cast<unsigned>(false);
    }

    // HasEmUnits
    bool HasEmUnits() const
    {
        return static_cast<bool>(data_.has_em_units_);
    }

    void SetHasEmUnits()
    {
        data_.has_em_units_ = static_cast<unsigned>(true);
    }

    // HasEnv
    bool HasEnv() const
    {
        return static_cast<bool>(data_.has_env_);
    }

    void SetHasEnv()
    {
        data_.has_env_ = static_cast<unsigned>(true);
    }

    // HasExplicitInheritance
    bool HasExplicitInheritance() const
    {
        return static_cast<bool>(data_.has_explicit_inheritance_);
    }

    void SetHasExplicitInheritance()
    {
        data_.has_explicit_inheritance_ = static_cast<unsigned>(true);
    }

    // HasExplicitOverflowXVisible
    bool HasExplicitOverflowXVisible() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_x_visible_);
    }

    void SetHasExplicitOverflowXVisible()
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_x_visible_
                == static_cast<unsigned>(true)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->has_explicit_overflow_x_visible_
                = static_cast<unsigned>(true);
    }

    // HasExplicitOverflowYVisible
    bool HasExplicitOverflowYVisible() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_y_visible_);
    }

    void SetHasExplicitOverflowYVisible()
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_y_visible_
                == static_cast<unsigned>(true)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->has_explicit_overflow_y_visible_
                = static_cast<unsigned>(true);
    }

    // HasGlyphRelativeUnits
    bool HasGlyphRelativeUnits() const
    {
        return static_cast<bool>(data_.has_glyph_relative_units_);
    }

    void SetHasGlyphRelativeUnits()
    {
        data_.has_glyph_relative_units_ = static_cast<unsigned>(true);
    }

    // HasLineHeightRelativeUnits
    bool HasLineHeightRelativeUnits() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_line_height_relative_units_);
    }

    void SetHasLineHeightRelativeUnits()
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_line_height_relative_units_
                == static_cast<unsigned>(true)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->has_line_height_relative_units_
                = static_cast<unsigned>(true);
    }

    // -internal-empty-line-height
    bool HasLineIfEmpty() const
    {
        return static_cast<bool>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->has_line_if_empty_);
    }

    void SetHasLineIfEmpty(bool v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->has_line_if_empty_
                == static_cast<unsigned>(v)))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->has_line_if_empty_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasLineIfEmpty()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->has_line_if_empty_
            = static_cast<unsigned>(false);
    }

    // HasLogicalDirectionRelativeUnits
    bool HasLogicalDirectionRelativeUnits() const
    {
        return static_cast<bool>(data_.has_logical_direction_relative_units_);
    }

    void SetHasLogicalDirectionRelativeUnits()
    {
        data_.has_logical_direction_relative_units_ = static_cast<unsigned>(true);
    }

    // HasNonUaHighlightPseudoStyles
    bool HasNonUaHighlightPseudoStyles() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_non_ua_highlight_pseudo_styles_);
    }

    void SetHasNonUaHighlightPseudoStyles(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_non_ua_highlight_pseudo_styles_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->has_non_ua_highlight_pseudo_styles_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasNonUaHighlightPseudoStyles()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->has_non_ua_highlight_pseudo_styles_
            = static_cast<unsigned>(false);
    }

    // HasNonUniversalHighlightPseudoStyles
    bool HasNonUniversalHighlightPseudoStyles() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->has_non_universal_highlight_pseudo_styles_);
    }

    void SetHasNonUniversalHighlightPseudoStyles(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->has_non_universal_highlight_pseudo_styles_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->has_non_universal_highlight_pseudo_styles_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasNonUniversalHighlightPseudoStyles()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->has_non_universal_highlight_pseudo_styles_
            = static_cast<unsigned>(false);
    }

    // HasRootFontRelativeUnits
    bool HasRootFontRelativeUnits() const
    {
        return static_cast<bool>(data_.has_root_font_relative_units_);
    }

    void SetHasRootFontRelativeUnits()
    {
        data_.has_root_font_relative_units_ = static_cast<unsigned>(true);
    }

    // HasVariableDeclaration
    bool HasVariableDeclaration() const
    {
        return static_cast<bool>(data_.has_variable_declaration_);
    }

    void SetHasVariableDeclaration()
    {
        data_.has_variable_declaration_ = static_cast<unsigned>(true);
    }

    // HasVariableReference
    bool HasVariableReference() const
    {
        return static_cast<bool>(data_.has_variable_reference_);
    }

    void SetHasVariableReference()
    {
        data_.has_variable_reference_ = static_cast<unsigned>(true);
    }

    // height
    const Length& Height() const
    {
        return box_data_->height_;
    }

    void SetHeight(const Length& v)
    {
        if (!(box_data_->height_ == v))
            Access(box_data_, access_.box_data_)->height_ = v;
    }

    void SetHeight(Length&& v)
    {
        if (!(box_data_->height_ == v))
            Access(box_data_, access_.box_data_)->height_ = std::move(v);
    }

    inline void ResetHeight()
    {
        Access(box_data_, access_.box_data_)->height_ = Length();
    }

    // HighlightData
    const StyleHighlightData& HighlightData() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_data_->highlight_data_;
    }

    void SetHighlightData(const StyleHighlightData& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_data_->highlight_data_ == v))
            Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                              ->rare_inherited_usage_less_than_64_percent_sub_data_,
                       access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                       ->highlight_data_data_,
                access_.highlight_data_data_)
                ->highlight_data_
                = v;
    }

    void SetHighlightData(StyleHighlightData&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_data_->highlight_data_ == v))
            Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                              ->rare_inherited_usage_less_than_64_percent_sub_data_,
                       access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                       ->highlight_data_data_,
                access_.highlight_data_data_)
                ->highlight_data_
                = std::move(v);
    }

    inline void ResetHighlightData()
    {
        Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_64_percent_sub_data_,
                   access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                   ->highlight_data_data_,
            access_.highlight_data_data_)
            ->highlight_data_
            = StyleHighlightData();
    }

    // HighlightsDependOnSizeContainerQueries
    bool HighlightsDependOnSizeContainerQueries() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->highlights_depend_on_size_container_queries_);
    }

    void SetHighlightsDependOnSizeContainerQueries(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->highlights_depend_on_size_container_queries_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->highlights_depend_on_size_container_queries_
                = static_cast<unsigned>(v);
    }

    inline void ResetHighlightsDependOnSizeContainerQueries()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->highlights_depend_on_size_container_queries_
            = static_cast<unsigned>(false);
    }

    // -webkit-border-horizontal-spacing
    short HorizontalBorderSpacing() const
    {
        return inherited_data_->horizontal_border_spacing_;
    }

    void SetHorizontalBorderSpacing(short v)
    {
        if (!(inherited_data_->horizontal_border_spacing_ == v))
            Access(inherited_data_, access_.inherited_data_)->horizontal_border_spacing_ = v;
    }

    inline void ResetHorizontalBorderSpacing()
    {
        Access(inherited_data_, access_.inherited_data_)->horizontal_border_spacing_ = 0;
    }

    // hyphenate-limit-chars
    const StyleHyphenateLimitChars& HyphenateLimitChars() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_;
    }

    void SetHyphenateLimitChars(const StyleHyphenateLimitChars& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->hyphenate_limit_chars_
                = v;
    }

    void SetHyphenateLimitChars(StyleHyphenateLimitChars&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->hyphenate_limit_chars_
                = std::move(v);
    }

    inline void ResetHyphenateLimitChars()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->hyphenate_limit_chars_
            = StyleHyphenateLimitChars();
    }

    // hyphenate-character
    const AtomicString& HyphenationString() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_;
    }

    void SetHyphenationString(const AtomicString& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->hyphenation_string_ = v;
    }

    void SetHyphenationString(AtomicString&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->hyphenation_string_
                = std::move(v);
    }

    inline void ResetHyphenationString()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->hyphenation_string_ = AtomicString();
    }

    // hyphens
    Hyphens GetHyphens() const
    {
        return static_cast<Hyphens>(rare_inherited_usage_less_than_64_percent_data_->hyphens_);
    }

    void SetHyphens(Hyphens v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->hyphens_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->hyphens_
                = static_cast<unsigned>(v);
    }

    inline void ResetHyphens()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->hyphens_
            = static_cast<unsigned>(Hyphens::kManual);
    }

    // image-orientation
    RespectImageOrientationEnum ImageOrientation() const
    {
        return static_cast<RespectImageOrientationEnum>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->image_orientation_);
    }

    void SetImageOrientation(RespectImageOrientationEnum v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->image_orientation_
                == static_cast<unsigned>(v)))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_100_percent_data_,
                access_.rare_inherited_usage_less_than_100_percent_data_)
                ->image_orientation_
                = static_cast<unsigned>(v);
    }

    inline void ResetImageOrientation()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_100_percent_data_,
            access_.rare_inherited_usage_less_than_100_percent_data_)
            ->image_orientation_
            = static_cast<unsigned>(kRespectImageOrientation);
    }

    // image-rendering
    EImageRendering ImageRendering() const
    {
        return static_cast<EImageRendering>(rare_inherited_usage_less_than_64_percent_data_->image_rendering_);
    }

    void SetImageRendering(EImageRendering v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->image_rendering_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->image_rendering_
                = static_cast<unsigned>(v);
    }

    inline void ResetImageRendering()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->image_rendering_
            = static_cast<unsigned>(EImageRendering::kAuto);
    }

    // InBaseSelectAppearance
    bool InBaseSelectAppearance() const
    {
        return static_cast<bool>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->in_base_select_appearance_);
    }

    void SetInBaseSelectAppearance(bool v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->in_base_select_appearance_
                == static_cast<unsigned>(v)))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->in_base_select_appearance_
                = static_cast<unsigned>(v);
    }

    inline void ResetInBaseSelectAppearance()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->in_base_select_appearance_
            = static_cast<unsigned>(false);
    }

    // InForcedColorsMode
    bool InForcedColorsMode() const
    {
        return static_cast<bool>(inherited_data_->in_forced_colors_mode_);
    }

    void SetInForcedColorsMode(bool v)
    {
        if (!(inherited_data_->in_forced_colors_mode_ == static_cast<unsigned>(v)))
            Access(inherited_data_, access_.inherited_data_)->in_forced_colors_mode_ = static_cast<unsigned>(v);
    }

    inline void ResetInForcedColorsMode()
    {
        Access(inherited_data_, access_.inherited_data_)->in_forced_colors_mode_ = static_cast<unsigned>(false);
    }

    // InheritedVariables

    inline void ResetInheritedVariables()
    {
        Access(inherited_data_, access_.inherited_data_)->inherited_variables_ = nullptr;
    }

    // InitialData
    StyleInitialData* InitialData() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->initial_data_.Get();
    }

    void SetInitialData(Member<StyleInitialData> v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->initial_data_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->initial_data_
                = std::move(v);
    }

    // initial-letter
    const StyleInitialLetter& InitialLetter() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_;
    }

    void SetInitialLetter(const StyleInitialLetter& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->initial_letter_
                = v;
    }

    void SetInitialLetter(StyleInitialLetter&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->initial_letter_
                = std::move(v);
    }

    inline void ResetInitialLetter()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->initial_letter_
            = StyleInitialLetter();
    }

    // InlineBlockBaselineEdge
    EInlineBlockBaselineEdge InlineBlockBaselineEdge() const
    {
        return static_cast<EInlineBlockBaselineEdge>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->inline_block_baseline_edge_);
    }

    void SetInlineBlockBaselineEdge(EInlineBlockBaselineEdge v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->inline_block_baseline_edge_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->inline_block_baseline_edge_
                = static_cast<unsigned>(v);
    }

    inline void ResetInlineBlockBaselineEdge()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->inline_block_baseline_edge_
            = static_cast<unsigned>(EInlineBlockBaselineEdge::kMarginBox);
    }

    // InlineStyleLostCascade
    bool InlineStyleLostCascade() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->inline_style_lost_cascade_);
    }

    void SetInlineStyleLostCascade(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->inline_style_lost_cascade_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->inline_style_lost_cascade_
                = static_cast<unsigned>(v);
    }

    inline void ResetInlineStyleLostCascade()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->inline_style_lost_cascade_
            = static_cast<unsigned>(false);
    }

    // InsideLink
    EInsideLink InsideLink() const
    {
        return static_cast<EInsideLink>(data_.inside_link_);
    }

    void SetInsideLink(EInsideLink v)
    {
        data_.inside_link_ = static_cast<unsigned>(v);
    }

    inline void ResetInsideLink()
    {
        data_.inside_link_ = static_cast<unsigned>(EInsideLink::kNotInsideLink);
    }

    // interactivity
    EInteractivity Interactivity() const
    {
        return static_cast<EInteractivity>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->interactivity_);
    }

    void SetInteractivity(EInteractivity v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->interactivity_ == static_cast<unsigned>(v)))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->interactivity_
                = static_cast<unsigned>(v);
    }

    inline void ResetInteractivity()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->interactivity_
            = static_cast<unsigned>(EInteractivity::kAuto);
    }

    // -internal-forced-background-color

    void SetInternalForcedBackgroundColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
                    ->internal_forced_background_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->forced_colors_data_,
                access_.forced_colors_data_)
                ->internal_forced_background_color_
                = v;
    }

    void SetInternalForcedBackgroundColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
                    ->internal_forced_background_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->forced_colors_data_,
                access_.forced_colors_data_)
                ->internal_forced_background_color_
                = std::move(v);
    }

    inline void ResetInternalForcedBackgroundColor()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->forced_colors_data_,
            access_.forced_colors_data_)
            ->internal_forced_background_color_
            = StyleColor(CSSValueID::kCanvas);
    }

    // -internal-forced-border-color

    void SetInternalForcedBorderColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
                    ->internal_forced_border_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->forced_colors_data_,
                access_.forced_colors_data_)
                ->internal_forced_border_color_
                = v;
    }

    void SetInternalForcedBorderColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
                    ->internal_forced_border_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->forced_colors_data_,
                access_.forced_colors_data_)
                ->internal_forced_border_color_
                = std::move(v);
    }

    inline void ResetInternalForcedBorderColor()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->forced_colors_data_,
            access_.forced_colors_data_)
            ->internal_forced_border_color_
            = StyleColor::CurrentColor();
    }

    // -internal-forced-color

    void SetInternalForcedColor(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_
                    ->internal_forced_color_
                == v))
            Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                              ->rare_inherited_usage_less_than_64_percent_sub_data_,
                       access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                       ->inherited_forced_colors_data_,
                access_.inherited_forced_colors_data_)
                ->internal_forced_color_
                = v;
    }

    void SetInternalForcedColor(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_
                    ->internal_forced_color_
                == v))
            Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                              ->rare_inherited_usage_less_than_64_percent_sub_data_,
                       access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                       ->inherited_forced_colors_data_,
                access_.inherited_forced_colors_data_)
                ->internal_forced_color_
                = std::move(v);
    }

    inline void ResetInternalForcedColor()
    {
        Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_64_percent_sub_data_,
                   access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                   ->inherited_forced_colors_data_,
            access_.inherited_forced_colors_data_)
            ->internal_forced_color_
            = StyleColor(CSSValueID::kCanvastext);
    }

    // -internal-forced-outline-color

    void SetInternalForcedOutlineColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
                    ->internal_forced_outline_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->forced_colors_data_,
                access_.forced_colors_data_)
                ->internal_forced_outline_color_
                = v;
    }

    void SetInternalForcedOutlineColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
                    ->internal_forced_outline_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->forced_colors_data_,
                access_.forced_colors_data_)
                ->internal_forced_outline_color_
                = std::move(v);
    }

    inline void ResetInternalForcedOutlineColor()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->forced_colors_data_,
            access_.forced_colors_data_)
            ->internal_forced_outline_color_
            = StyleColor::CurrentColor();
    }

    // -internal-forced-visited-color

    void SetInternalForcedVisitedColor(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_
                    ->internal_forced_visited_color_
                == v))
            Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                              ->rare_inherited_usage_less_than_64_percent_sub_data_,
                       access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                       ->inherited_forced_colors_data_,
                access_.inherited_forced_colors_data_)
                ->internal_forced_visited_color_
                = v;
    }

    void SetInternalForcedVisitedColor(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_
                    ->internal_forced_visited_color_
                == v))
            Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                              ->rare_inherited_usage_less_than_64_percent_sub_data_,
                       access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                       ->inherited_forced_colors_data_,
                access_.inherited_forced_colors_data_)
                ->internal_forced_visited_color_
                = std::move(v);
    }

    inline void ResetInternalForcedVisitedColor()
    {
        Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_64_percent_sub_data_,
                   access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                   ->inherited_forced_colors_data_,
            access_.inherited_forced_colors_data_)
            ->internal_forced_visited_color_
            = StyleColor(CSSValueID::kCanvastext);
    }

    // -internal-visited-background-color

    void SetInternalVisitedBackgroundColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_background_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_background_color_
                = v;
    }

    void SetInternalVisitedBackgroundColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_background_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_background_color_
                = std::move(v);
    }

    inline void ResetInternalVisitedBackgroundColor()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->visited_data_,
            access_.visited_data_)
            ->internal_visited_background_color_
            = StyleColor(Color::kTransparent);
    }

    // -internal-visited-border-bottom-color

    void SetInternalVisitedBorderBottomColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_border_bottom_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_border_bottom_color_
                = v;
    }

    void SetInternalVisitedBorderBottomColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_border_bottom_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_border_bottom_color_
                = std::move(v);
    }

    inline void ResetInternalVisitedBorderBottomColor()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->visited_data_,
            access_.visited_data_)
            ->internal_visited_border_bottom_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-border-left-color

    void SetInternalVisitedBorderLeftColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_border_left_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_border_left_color_
                = v;
    }

    void SetInternalVisitedBorderLeftColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_border_left_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_border_left_color_
                = std::move(v);
    }

    inline void ResetInternalVisitedBorderLeftColor()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->visited_data_,
            access_.visited_data_)
            ->internal_visited_border_left_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-border-right-color

    void SetInternalVisitedBorderRightColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_border_right_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_border_right_color_
                = v;
    }

    void SetInternalVisitedBorderRightColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_border_right_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_border_right_color_
                = std::move(v);
    }

    inline void ResetInternalVisitedBorderRightColor()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->visited_data_,
            access_.visited_data_)
            ->internal_visited_border_right_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-border-top-color

    void SetInternalVisitedBorderTopColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_border_top_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_border_top_color_
                = v;
    }

    void SetInternalVisitedBorderTopColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_border_top_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_border_top_color_
                = std::move(v);
    }

    inline void ResetInternalVisitedBorderTopColor()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->visited_data_,
            access_.visited_data_)
            ->internal_visited_border_top_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-caret-color

    void SetInternalVisitedCaretColor(const StyleAutoColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                    ->internal_visited_caret_color_
                == v))
            Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                              ->rare_inherited_usage_less_than_64_percent_sub_data_,
                       access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                       ->inherited_visited_data_,
                access_.inherited_visited_data_)
                ->internal_visited_caret_color_
                = v;
    }

    void SetInternalVisitedCaretColor(StyleAutoColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                    ->internal_visited_caret_color_
                == v))
            Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                              ->rare_inherited_usage_less_than_64_percent_sub_data_,
                       access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                       ->inherited_visited_data_,
                access_.inherited_visited_data_)
                ->internal_visited_caret_color_
                = std::move(v);
    }

    inline void ResetInternalVisitedCaretColor()
    {
        Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_64_percent_sub_data_,
                   access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                   ->inherited_visited_data_,
            access_.inherited_visited_data_)
            ->internal_visited_caret_color_
            = StyleAutoColor::AutoColor();
    }

    // -internal-visited-color

    void SetInternalVisitedColor(const StyleColor& v)
    {
        if (!(inherited_data_->internal_visited_color_ == v))
            Access(inherited_data_, access_.inherited_data_)->internal_visited_color_ = v;
    }

    void SetInternalVisitedColor(StyleColor&& v)
    {
        if (!(inherited_data_->internal_visited_color_ == v))
            Access(inherited_data_, access_.inherited_data_)->internal_visited_color_ = std::move(v);
    }

    inline void ResetInternalVisitedColor()
    {
        Access(inherited_data_, access_.inherited_data_)->internal_visited_color_ = StyleColor(Color::kBlack);
    }

    // InternalVisitedColorIsCurrentColor

    void SetInternalVisitedColorIsCurrentColor(bool v)
    {
        if (!(inherited_data_->internal_visited_color_is_current_color_ == static_cast<unsigned>(v)))
            Access(inherited_data_, access_.inherited_data_)->internal_visited_color_is_current_color_ = static_cast<unsigned>(v);
    }

    inline void ResetInternalVisitedColorIsCurrentColor()
    {
        Access(inherited_data_, access_.inherited_data_)->internal_visited_color_is_current_color_ = static_cast<unsigned>(true);
    }

    // -internal-visited-column-rule-color
    const GapDataList<StyleColor>& InternalVisitedColumnRuleColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_column_rule_color_;
    }

    void SetInternalVisitedColumnRuleColor(const GapDataList<StyleColor>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_column_rule_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_column_rule_color_
                = v;
    }

    void SetInternalVisitedColumnRuleColor(GapDataList<StyleColor>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_column_rule_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_column_rule_color_
                = std::move(v);
    }

    inline void ResetInternalVisitedColumnRuleColor()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->visited_data_,
            access_.visited_data_)
            ->internal_visited_column_rule_color_
            = GapDataList<StyleColor>::DefaultGapColorDataList();
    }

    // -internal-visited-fill
    const SVGPaint& InternalVisitedFillPaint() const
    {
        return svg_data_->fill_data_->internal_visited_fill_paint_;
    }

    void SetInternalVisitedFillPaint(const SVGPaint& v)
    {
        if (!(svg_data_->fill_data_->internal_visited_fill_paint_ == v))
            Access(Access(svg_data_, access_.svg_data_)->fill_data_, access_.fill_data_)->internal_visited_fill_paint_ = v;
    }

    void SetInternalVisitedFillPaint(SVGPaint&& v)
    {
        if (!(svg_data_->fill_data_->internal_visited_fill_paint_ == v))
            Access(Access(svg_data_, access_.svg_data_)->fill_data_, access_.fill_data_)->internal_visited_fill_paint_ = std::move(v);
    }

    inline void ResetInternalVisitedFillPaint()
    {
        Access(Access(svg_data_, access_.svg_data_)->fill_data_, access_.fill_data_)->internal_visited_fill_paint_ = SVGPaint(Color::kBlack);
    }

    // -internal-visited-outline-color

    void SetInternalVisitedOutlineColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_outline_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_outline_color_
                = v;
    }

    void SetInternalVisitedOutlineColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_outline_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_outline_color_
                = std::move(v);
    }

    inline void ResetInternalVisitedOutlineColor()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->visited_data_,
            access_.visited_data_)
            ->internal_visited_outline_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-stroke
    const SVGPaint& InternalVisitedStrokePaint() const
    {
        return svg_data_->stroke_data_->internal_visited_stroke_paint_;
    }

    void SetInternalVisitedStrokePaint(const SVGPaint& v)
    {
        if (!(svg_data_->stroke_data_->internal_visited_stroke_paint_ == v))
            Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->internal_visited_stroke_paint_ = v;
    }

    void SetInternalVisitedStrokePaint(SVGPaint&& v)
    {
        if (!(svg_data_->stroke_data_->internal_visited_stroke_paint_ == v))
            Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->internal_visited_stroke_paint_ = std::move(v);
    }

    inline void ResetInternalVisitedStrokePaint()
    {
        Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->internal_visited_stroke_paint_ = SVGPaint();
    }

    // -internal-visited-text-decoration-color

    void SetInternalVisitedTextDecorationColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_text_decoration_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_text_decoration_color_
                = v;
    }

    void SetInternalVisitedTextDecorationColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                    ->internal_visited_text_decoration_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->visited_data_,
                access_.visited_data_)
                ->internal_visited_text_decoration_color_
                = std::move(v);
    }

    inline void ResetInternalVisitedTextDecorationColor()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->visited_data_,
            access_.visited_data_)
            ->internal_visited_text_decoration_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-text-emphasis-color

    void SetInternalVisitedTextEmphasisColor(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                    ->internal_visited_text_emphasis_color_
                == v))
            Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                              ->rare_inherited_usage_less_than_64_percent_sub_data_,
                       access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                       ->inherited_visited_data_,
                access_.inherited_visited_data_)
                ->internal_visited_text_emphasis_color_
                = v;
    }

    void SetInternalVisitedTextEmphasisColor(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                    ->internal_visited_text_emphasis_color_
                == v))
            Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                              ->rare_inherited_usage_less_than_64_percent_sub_data_,
                       access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                       ->inherited_visited_data_,
                access_.inherited_visited_data_)
                ->internal_visited_text_emphasis_color_
                = std::move(v);
    }

    inline void ResetInternalVisitedTextEmphasisColor()
    {
        Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_64_percent_sub_data_,
                   access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                   ->inherited_visited_data_,
            access_.inherited_visited_data_)
            ->internal_visited_text_emphasis_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-text-fill-color

    void SetInternalVisitedTextFillColor(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                    ->internal_visited_text_fill_color_
                == v))
            Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                              ->rare_inherited_usage_less_than_64_percent_sub_data_,
                       access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                       ->inherited_visited_data_,
                access_.inherited_visited_data_)
                ->internal_visited_text_fill_color_
                = v;
    }

    void SetInternalVisitedTextFillColor(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                    ->internal_visited_text_fill_color_
                == v))
            Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                              ->rare_inherited_usage_less_than_64_percent_sub_data_,
                       access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                       ->inherited_visited_data_,
                access_.inherited_visited_data_)
                ->internal_visited_text_fill_color_
                = std::move(v);
    }

    inline void ResetInternalVisitedTextFillColor()
    {
        Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_64_percent_sub_data_,
                   access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                   ->inherited_visited_data_,
            access_.inherited_visited_data_)
            ->internal_visited_text_fill_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-text-stroke-color

    void SetInternalVisitedTextStrokeColor(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                    ->internal_visited_text_stroke_color_
                == v))
            Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                              ->rare_inherited_usage_less_than_64_percent_sub_data_,
                       access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                       ->inherited_visited_data_,
                access_.inherited_visited_data_)
                ->internal_visited_text_stroke_color_
                = v;
    }

    void SetInternalVisitedTextStrokeColor(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                    ->internal_visited_text_stroke_color_
                == v))
            Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                              ->rare_inherited_usage_less_than_64_percent_sub_data_,
                       access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                       ->inherited_visited_data_,
                access_.inherited_visited_data_)
                ->internal_visited_text_stroke_color_
                = std::move(v);
    }

    inline void ResetInternalVisitedTextStrokeColor()
    {
        Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_64_percent_sub_data_,
                   access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                   ->inherited_visited_data_,
            access_.inherited_visited_data_)
            ->internal_visited_text_stroke_color_
            = StyleColor::CurrentColor();
    }

    // interpolate-size
    EInterpolateSize InterpolateSize() const
    {
        return static_cast<EInterpolateSize>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->interpolate_size_);
    }

    void SetInterpolateSize(EInterpolateSize v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->interpolate_size_
                == static_cast<unsigned>(v)))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->interpolate_size_
                = static_cast<unsigned>(v);
    }

    inline void ResetInterpolateSize()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->interpolate_size_
            = static_cast<unsigned>(EInterpolateSize::kNumericOnly);
    }

    // IsEnsuredInDisplayNone
    bool IsEnsuredInDisplayNone() const
    {
        return static_cast<bool>(data_.is_ensured_in_display_none_);
    }

    void SetIsEnsuredInDisplayNone()
    {
        data_.is_ensured_in_display_none_ = static_cast<unsigned>(true);
    }

    // IsEnsuredOutsideFlatTree
    bool IsEnsuredOutsideFlatTree() const
    {
        return static_cast<bool>(data_.is_ensured_outside_flat_tree_);
    }

    void SetIsEnsuredOutsideFlatTree()
    {
        data_.is_ensured_outside_flat_tree_ = static_cast<unsigned>(true);
    }

    // IsFlexOrGridOrCustomItem
    bool IsFlexOrGridOrCustomItem() const
    {
        return static_cast<bool>(data_.is_flex_or_grid_or_custom_item_);
    }

    void SetIsFlexOrGridOrCustomItem()
    {
        data_.is_flex_or_grid_or_custom_item_ = static_cast<unsigned>(true);
    }

    // IsHTMLInert
    bool IsHTMLInert() const
    {
        return static_cast<bool>(data_.is_html_inert_);
    }

    void SetIsHTMLInert(bool v)
    {
        data_.is_html_inert_ = static_cast<unsigned>(v);
    }

    inline void ResetIsHTMLInert()
    {
        data_.is_html_inert_ = static_cast<unsigned>(false);
    }

    // IsHTMLInert
    bool IsHTMLInertIsInherited() const
    {
        return static_cast<bool>(data_.is_html_inert_is_inherited_);
    }

    void SetIsHTMLInertIsInherited(bool v)
    {
        data_.is_html_inert_is_inherited_ = static_cast<unsigned>(v);
    }

    inline void ResetIsHTMLInertIsInherited()
    {
        data_.is_html_inert_is_inherited_ = static_cast<unsigned>(true);
    }

    // IsInBlockifyingDisplay
    bool IsInBlockifyingDisplay() const
    {
        return static_cast<bool>(data_.is_in_blockifying_display_);
    }

    void SetIsInBlockifyingDisplay()
    {
        data_.is_in_blockifying_display_ = static_cast<unsigned>(true);
    }

    // IsInInlinifyingDisplay
    bool IsInInlinifyingDisplay() const
    {
        return static_cast<bool>(data_.is_in_inlinifying_display_);
    }

    void SetIsInInlinifyingDisplay()
    {
        data_.is_in_inlinifying_display_ = static_cast<unsigned>(true);
    }

    // IsInsideDisplayIgnoringFloatingChildren
    bool IsInsideDisplayIgnoringFloatingChildren() const
    {
        return static_cast<bool>(data_.is_inside_display_ignoring_floating_children_);
    }

    void SetIsInsideDisplayIgnoringFloatingChildren()
    {
        data_.is_inside_display_ignoring_floating_children_ = static_cast<unsigned>(true);
    }

    // IsInsideListElement
    bool IsInsideListElement() const
    {
        return static_cast<bool>(data_.is_inside_list_element_);
    }

    void SetIsInsideListElement()
    {
        data_.is_inside_list_element_ = static_cast<unsigned>(true);
    }

    // IsLink
    bool IsLink() const
    {
        return static_cast<bool>(data_.is_link_);
    }

    void SetIsLink()
    {
        data_.is_link_ = static_cast<unsigned>(true);
    }

    // IsOriginalDisplayInlineType
    bool IsOriginalDisplayInlineType() const
    {
        return static_cast<bool>(data_.is_original_display_inline_type_);
    }

    void SetIsOriginalDisplayInlineType(bool v)
    {
        data_.is_original_display_inline_type_ = static_cast<unsigned>(v);
    }

    inline void ResetIsOriginalDisplayInlineType()
    {
        data_.is_original_display_inline_type_ = static_cast<unsigned>(true);
    }

    // IsPageMarginBox
    bool IsPageMarginBox() const
    {
        return static_cast<bool>(data_.is_page_margin_box_);
    }

    void SetIsPageMarginBox(bool v)
    {
        data_.is_page_margin_box_ = static_cast<unsigned>(v);
    }

    inline void ResetIsPageMarginBox()
    {
        data_.is_page_margin_box_ = static_cast<unsigned>(false);
    }

    // IsRunningBackdropFilterAnimationOnCompositor
    bool IsRunningBackdropFilterAnimationOnCompositor() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->is_running_backdrop_filter_animation_on_compositor_);
    }

    void SetIsRunningBackdropFilterAnimationOnCompositor(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->is_running_backdrop_filter_animation_on_compositor_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->is_running_backdrop_filter_animation_on_compositor_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsRunningBackdropFilterAnimationOnCompositor()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->is_running_backdrop_filter_animation_on_compositor_
            = static_cast<unsigned>(false);
    }

    // IsRunningFilterAnimationOnCompositor
    bool IsRunningFilterAnimationOnCompositor() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->is_running_filter_animation_on_compositor_);
    }

    void SetIsRunningFilterAnimationOnCompositor(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->is_running_filter_animation_on_compositor_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->is_running_filter_animation_on_compositor_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsRunningFilterAnimationOnCompositor()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->is_running_filter_animation_on_compositor_
            = static_cast<unsigned>(false);
    }

    // IsRunningOpacityAnimationOnCompositor
    bool IsRunningOpacityAnimationOnCompositor() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->is_running_opacity_animation_on_compositor_);
    }

    void SetIsRunningOpacityAnimationOnCompositor(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->is_running_opacity_animation_on_compositor_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->is_running_opacity_animation_on_compositor_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsRunningOpacityAnimationOnCompositor()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->is_running_opacity_animation_on_compositor_
            = static_cast<unsigned>(false);
    }

    // IsRunningRotateAnimationOnCompositor
    bool IsRunningRotateAnimationOnCompositor() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->is_running_rotate_animation_on_compositor_);
    }

    void SetIsRunningRotateAnimationOnCompositor(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->is_running_rotate_animation_on_compositor_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->is_running_rotate_animation_on_compositor_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsRunningRotateAnimationOnCompositor()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->is_running_rotate_animation_on_compositor_
            = static_cast<unsigned>(false);
    }

    // IsRunningScaleAnimationOnCompositor
    bool IsRunningScaleAnimationOnCompositor() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->is_running_scale_animation_on_compositor_);
    }

    void SetIsRunningScaleAnimationOnCompositor(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->is_running_scale_animation_on_compositor_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->is_running_scale_animation_on_compositor_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsRunningScaleAnimationOnCompositor()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->is_running_scale_animation_on_compositor_
            = static_cast<unsigned>(false);
    }

    // IsRunningTransformAnimationOnCompositor
    bool IsRunningTransformAnimationOnCompositor() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->is_running_transform_animation_on_compositor_);
    }

    void SetIsRunningTransformAnimationOnCompositor(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->is_running_transform_animation_on_compositor_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->is_running_transform_animation_on_compositor_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsRunningTransformAnimationOnCompositor()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->is_running_transform_animation_on_compositor_
            = static_cast<unsigned>(false);
    }

    // IsRunningTranslateAnimationOnCompositor
    bool IsRunningTranslateAnimationOnCompositor() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->is_running_translate_animation_on_compositor_);
    }

    void SetIsRunningTranslateAnimationOnCompositor(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->is_running_translate_animation_on_compositor_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->is_running_translate_animation_on_compositor_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsRunningTranslateAnimationOnCompositor()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->is_running_translate_animation_on_compositor_
            = static_cast<unsigned>(false);
    }

    // IsSecondaryBodyElement
    bool IsSecondaryBodyElement() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_secondary_body_element_);
    }

    void SetIsSecondaryBodyElement()
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_secondary_body_element_
                == static_cast<unsigned>(true)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->is_secondary_body_element_
                = static_cast<unsigned>(true);
    }

    // IsSpecifiedDisplayWebkitBox
    bool IsSpecifiedDisplayWebkitBox() const
    {
        return static_cast<bool>(data_.is_specified_display_webkit_box_);
    }

    void SetIsSpecifiedDisplayWebkitBox()
    {
        data_.is_specified_display_webkit_box_ = static_cast<unsigned>(true);
    }

    // IsStartingStyle
    bool IsStartingStyle() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_starting_style_);
    }

    void SetIsStartingStyle()
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_starting_style_
                == static_cast<unsigned>(true)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->is_starting_style_
                = static_cast<unsigned>(true);
    }

    // isolation
    EIsolation Isolation() const
    {
        return static_cast<EIsolation>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->isolation_);
    }

    void SetIsolation(EIsolation v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->isolation_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->isolation_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsolation()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->isolation_
            = static_cast<unsigned>(EIsolation::kAuto);
    }

    // stroke-linejoin
    LineJoin JoinStyle() const
    {
        return static_cast<LineJoin>(svg_data_->stroke_data_->join_style_);
    }

    void SetJoinStyle(LineJoin v)
    {
        if (!(svg_data_->stroke_data_->join_style_ == static_cast<unsigned>(v)))
            Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->join_style_ = static_cast<unsigned>(v);
    }

    inline void ResetJoinStyle()
    {
        Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->join_style_ = static_cast<unsigned>(kMiterJoin);
    }

    // justify-content
    const StyleContentAlignmentData& JustifyContent() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->justify_content_;
    }

    void SetJustifyContent(const StyleContentAlignmentData& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->justify_content_ == v))
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->justify_content_ = v;
    }

    void SetJustifyContent(StyleContentAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->justify_content_ == v))
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->justify_content_
                = std::move(v);
    }

    inline void ResetJustifyContent()
    {
        Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->justify_content_
            = StyleContentAlignmentData(ContentPosition::kNormal, ContentDistributionType::kDefault, OverflowAlignment::kDefault);
    }

    // justify-items
    const StyleSelfAlignmentData& JustifyItems() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->justify_items_;
    }

    void SetJustifyItems(const StyleSelfAlignmentData& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->justify_items_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->justify_items_
                = v;
    }

    void SetJustifyItems(StyleSelfAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->justify_items_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->justify_items_
                = std::move(v);
    }

    inline void ResetJustifyItems()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->justify_items_
            = StyleSelfAlignmentData(ItemPosition::kLegacy, OverflowAlignment::kDefault);
    }

    // justify-self
    const StyleSelfAlignmentData& JustifySelf() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->justify_self_;
    }

    void SetJustifySelf(const StyleSelfAlignmentData& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->justify_self_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->justify_self_
                = v;
    }

    void SetJustifySelf(StyleSelfAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->justify_self_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->justify_self_
                = std::move(v);
    }

    inline void ResetJustifySelf()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->justify_self_
            = StyleSelfAlignmentData(ItemPosition::kAuto, OverflowAlignment::kDefault);
    }

    // left
    const Length& Left() const
    {
        return surround_data_->left_;
    }

    void SetLeft(const Length& v)
    {
        if (!(surround_data_->left_ == v))
            Access(surround_data_, access_.surround_data_)->left_ = v;
    }

    void SetLeft(Length&& v)
    {
        if (!(surround_data_->left_ == v))
            Access(surround_data_, access_.surround_data_)->left_ = std::move(v);
    }

    inline void ResetLeft()
    {
        Access(surround_data_, access_.surround_data_)->left_ = Length();
    }

    // lighting-color
    const StyleColor& LightingColor() const
    {
        return svg_data_->misc_data_->lighting_color_;
    }

    void SetLightingColor(const StyleColor& v)
    {
        if (!(svg_data_->misc_data_->lighting_color_ == v))
            Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->lighting_color_ = v;
    }

    void SetLightingColor(StyleColor&& v)
    {
        if (!(svg_data_->misc_data_->lighting_color_ == v))
            Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->lighting_color_ = std::move(v);
    }

    inline void ResetLightingColor()
    {
        Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->lighting_color_ = StyleColor(Color::kWhite);
    }

    // -webkit-line-break
    LineBreak GetLineBreak() const
    {
        return static_cast<LineBreak>(rare_inherited_usage_less_than_64_percent_data_->line_break_);
    }

    void SetLineBreak(LineBreak v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->line_break_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->line_break_
                = static_cast<unsigned>(v);
    }

    inline void ResetLineBreak()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->line_break_
            = static_cast<unsigned>(LineBreak::kAuto);
    }

    // line-height

    void SetLineHeight(const Length& v)
    {
        if (!(inherited_data_->line_height_ == v))
            Access(inherited_data_, access_.inherited_data_)->line_height_ = v;
    }

    void SetLineHeight(Length&& v)
    {
        if (!(inherited_data_->line_height_ == v))
            Access(inherited_data_, access_.inherited_data_)->line_height_ = std::move(v);
    }

    inline void ResetLineHeight()
    {
        Access(inherited_data_, access_.inherited_data_)->line_height_ = Length::Auto();
    }

    // list-style-image
    const Member<StyleImage>& ListStyleImage() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->list_style_image_;
    }

    void SetListStyleImage(const Member<StyleImage>& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->list_style_image_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->list_style_image_ = v;
    }

    void SetListStyleImage(Member<StyleImage>&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->list_style_image_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->list_style_image_ = std::move(v);
    }

    inline void ResetListStyleImage()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->list_style_image_ = nullptr;
    }

    // list-style-position
    EListStylePosition ListStylePosition() const
    {
        return static_cast<EListStylePosition>(data_.list_style_position_);
    }

    void SetListStylePosition(EListStylePosition v)
    {
        data_.list_style_position_ = static_cast<unsigned>(v);
    }

    inline void ResetListStylePosition()
    {
        data_.list_style_position_ = static_cast<unsigned>(EListStylePosition::kOutside);
    }

    // list-style-position
    bool ListStylePositionIsInherited() const
    {
        return static_cast<bool>(data_.list_style_position_is_inherited_);
    }

    void SetListStylePositionIsInherited(bool v)
    {
        data_.list_style_position_is_inherited_ = static_cast<unsigned>(v);
    }

    inline void ResetListStylePositionIsInherited()
    {
        data_.list_style_position_is_inherited_ = static_cast<unsigned>(true);
    }

    // list-style-type
    const Member<ListStyleTypeData>& ListStyleType() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->list_style_type_;
    }

    void SetListStyleType(const Member<ListStyleTypeData>& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->list_style_type_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->list_style_type_ = v;
    }

    void SetListStyleType(Member<ListStyleTypeData>&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->list_style_type_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->list_style_type_ = std::move(v);
    }

    inline void ResetListStyleType()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->list_style_type_
            = ListStyleTypeData::CreateCounterStyle(keywords::kDisc, nullptr);
    }

    // margin-bottom
    const Length& MarginBottom() const
    {
        return box_data_->margin_bottom_;
    }

    inline void ResetMarginBottom()
    {
        Access(box_data_, access_.box_data_)->margin_bottom_ = Length::Fixed();
    }

    // margin-left
    const Length& MarginLeft() const
    {
        return box_data_->margin_left_;
    }

    inline void ResetMarginLeft()
    {
        Access(box_data_, access_.box_data_)->margin_left_ = Length::Fixed();
    }

    // margin-right
    const Length& MarginRight() const
    {
        return box_data_->margin_right_;
    }

    inline void ResetMarginRight()
    {
        Access(box_data_, access_.box_data_)->margin_right_ = Length::Fixed();
    }

    // margin-top
    const Length& MarginTop() const
    {
        return box_data_->margin_top_;
    }

    inline void ResetMarginTop()
    {
        Access(box_data_, access_.box_data_)->margin_top_ = Length::Fixed();
    }

    // marker-end
    StyleSVGResource* MarkerEndResource() const
    {
        return svg_data_->inherited_resources_data_->marker_end_resource_.Get();
    }

    void SetMarkerEndResource(Member<StyleSVGResource> v)
    {
        if (!(svg_data_->inherited_resources_data_->marker_end_resource_ == v))
            Access(Access(svg_data_, access_.svg_data_)->inherited_resources_data_, access_.inherited_resources_data_)->marker_end_resource_ = std::move(v);
    }

    // marker-mid
    StyleSVGResource* MarkerMidResource() const
    {
        return svg_data_->inherited_resources_data_->marker_mid_resource_.Get();
    }

    void SetMarkerMidResource(Member<StyleSVGResource> v)
    {
        if (!(svg_data_->inherited_resources_data_->marker_mid_resource_ == v))
            Access(Access(svg_data_, access_.svg_data_)->inherited_resources_data_, access_.inherited_resources_data_)->marker_mid_resource_ = std::move(v);
    }

    // marker-start
    StyleSVGResource* MarkerStartResource() const
    {
        return svg_data_->inherited_resources_data_->marker_start_resource_.Get();
    }

    void SetMarkerStartResource(Member<StyleSVGResource> v)
    {
        if (!(svg_data_->inherited_resources_data_->marker_start_resource_ == v))
            Access(Access(svg_data_, access_.svg_data_)->inherited_resources_data_, access_.inherited_resources_data_)->marker_start_resource_ = std::move(v);
    }

    // Mask

    inline void ResetMask()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->mask_
            = FillLayer(EFillLayerType::kMask, true);
    }

    // MaskBoxImage

    inline void ResetMaskBoxImage()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->mask_box_image_
            = NinePieceImage::MaskDefaults();
    }

    // mask-type
    EMaskType MaskType() const
    {
        return static_cast<EMaskType>(svg_data_->mask_type_);
    }

    void SetMaskType(EMaskType v)
    {
        if (!(svg_data_->mask_type_ == static_cast<unsigned>(v)))
            Access(svg_data_, access_.svg_data_)->mask_type_ = static_cast<unsigned>(v);
    }

    inline void ResetMaskType()
    {
        Access(svg_data_, access_.svg_data_)->mask_type_ = static_cast<unsigned>(EMaskType::kLuminance);
    }

    // masonry-slack
    const std::optional<Length>& MasonrySlack() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_slack_;
    }

    void SetMasonrySlack(const std::optional<Length>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_slack_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->masonry_slack_
                = v;
    }

    void SetMasonrySlack(std::optional<Length>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_slack_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->masonry_slack_
                = std::move(v);
    }

    inline void ResetMasonrySlack()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->masonry_slack_
            = std::nullopt;
    }

    // masonry-template-tracks
    const ComputedGridTrackList& MasonryTemplateTracks() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_data_
            ->masonry_template_tracks_;
    }

    void SetMasonryTemplateTracks(const ComputedGridTrackList& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_data_
                    ->masonry_template_tracks_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->masonry_data_,
                access_.masonry_data_)
                ->masonry_template_tracks_
                = v;
    }

    void SetMasonryTemplateTracks(ComputedGridTrackList&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_data_
                    ->masonry_template_tracks_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->masonry_data_,
                access_.masonry_data_)
                ->masonry_template_tracks_
                = std::move(v);
    }

    inline void ResetMasonryTemplateTracks()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->masonry_data_,
            access_.masonry_data_)
            ->masonry_template_tracks_
            = ComputedGridTrackList::DefaultMasonryTrackList();
    }

    // masonry-track-end
    const GridPosition& MasonryTrackEnd() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_end_;
    }

    void SetMasonryTrackEnd(const GridPosition& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_end_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->masonry_track_end_
                = v;
    }

    void SetMasonryTrackEnd(GridPosition&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_end_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->masonry_track_end_
                = std::move(v);
    }

    inline void ResetMasonryTrackEnd()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->masonry_track_end_
            = GridPosition();
    }

    // masonry-track-start
    const GridPosition& MasonryTrackStart() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_start_;
    }

    void SetMasonryTrackStart(const GridPosition& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_start_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->masonry_track_start_
                = v;
    }

    void SetMasonryTrackStart(GridPosition&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->masonry_track_start_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->masonry_track_start_
                = std::move(v);
    }

    inline void ResetMasonryTrackStart()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->masonry_track_start_
            = GridPosition();
    }

    // MathBaseline
    const Length& GetMathBaseline() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_baseline_;
    }

    void SetMathBaseline(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_baseline_ == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_baseline_
                = v;
    }

    void SetMathBaseline(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_baseline_ == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_baseline_
                = std::move(v);
    }

    inline void ResetMathBaseline()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->math_data_,
            access_.math_data_)
            ->math_baseline_
            = Length();
    }

    // math-depth
    short MathDepth() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_depth_;
    }

    void SetMathDepth(short v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_depth_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_100_percent_data_,
                access_.rare_inherited_usage_less_than_100_percent_data_)
                ->math_depth_
                = v;
    }

    inline void ResetMathDepth()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_100_percent_data_,
            access_.rare_inherited_usage_less_than_100_percent_data_)
            ->math_depth_
            = 0;
    }

    // MathFractionBarThickness
    const Length& GetMathFractionBarThickness() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
            ->math_fraction_bar_thickness_;
    }

    void SetMathFractionBarThickness(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
                    ->math_fraction_bar_thickness_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_fraction_bar_thickness_
                = v;
    }

    void SetMathFractionBarThickness(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_
                    ->math_fraction_bar_thickness_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_fraction_bar_thickness_
                = std::move(v);
    }

    inline void ResetMathFractionBarThickness()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->math_data_,
            access_.math_data_)
            ->math_fraction_bar_thickness_
            = Length();
    }

    // MathLSpace
    const Length& GetMathLSpace() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_l_space_;
    }

    void SetMathLSpace(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_l_space_ == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_l_space_
                = v;
    }

    void SetMathLSpace(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_l_space_ == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_l_space_
                = std::move(v);
    }

    inline void ResetMathLSpace()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->math_data_,
            access_.math_data_)
            ->math_l_space_
            = Length();
    }

    // MathMaxSize
    const Length& GetMathMaxSize() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_max_size_;
    }

    void SetMathMaxSize(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_max_size_ == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_max_size_
                = v;
    }

    void SetMathMaxSize(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_max_size_ == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_max_size_
                = std::move(v);
    }

    inline void ResetMathMaxSize()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->math_data_,
            access_.math_data_)
            ->math_max_size_
            = Length();
    }

    // MathMinSize
    const Length& GetMathMinSize() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_min_size_;
    }

    void SetMathMinSize(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_min_size_ == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_min_size_
                = v;
    }

    void SetMathMinSize(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_min_size_ == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_min_size_
                = std::move(v);
    }

    inline void ResetMathMinSize()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->math_data_,
            access_.math_data_)
            ->math_min_size_
            = Length();
    }

    // MathPaddedDepth
    const Length& GetMathPaddedDepth() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_depth_;
    }

    void SetMathPaddedDepth(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_depth_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_padded_depth_
                = v;
    }

    void SetMathPaddedDepth(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_depth_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_padded_depth_
                = std::move(v);
    }

    inline void ResetMathPaddedDepth()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->math_data_,
            access_.math_data_)
            ->math_padded_depth_
            = Length();
    }

    // MathPaddedVOffset
    const Length& GetMathPaddedVOffset() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_v_offset_;
    }

    void SetMathPaddedVOffset(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_v_offset_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_padded_v_offset_
                = v;
    }

    void SetMathPaddedVOffset(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_v_offset_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_padded_v_offset_
                = std::move(v);
    }

    inline void ResetMathPaddedVOffset()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->math_data_,
            access_.math_data_)
            ->math_padded_v_offset_
            = Length();
    }

    // MathRSpace
    const Length& GetMathRSpace() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_r_space_;
    }

    void SetMathRSpace(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_r_space_ == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_r_space_
                = v;
    }

    void SetMathRSpace(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_r_space_ == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->math_data_,
                access_.math_data_)
                ->math_r_space_
                = std::move(v);
    }

    inline void ResetMathRSpace()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->math_data_,
            access_.math_data_)
            ->math_r_space_
            = Length();
    }

    // math-shift
    EMathShift MathShift() const
    {
        return static_cast<EMathShift>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_shift_);
    }

    void SetMathShift(EMathShift v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_shift_ == static_cast<unsigned>(v)))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_100_percent_data_,
                access_.rare_inherited_usage_less_than_100_percent_data_)
                ->math_shift_
                = static_cast<unsigned>(v);
    }

    inline void ResetMathShift()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_100_percent_data_,
            access_.rare_inherited_usage_less_than_100_percent_data_)
            ->math_shift_
            = static_cast<unsigned>(EMathShift::kNormal);
    }

    // math-style
    EMathStyle MathStyle() const
    {
        return static_cast<EMathStyle>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_style_);
    }

    void SetMathStyle(EMathStyle v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_style_ == static_cast<unsigned>(v)))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_100_percent_data_,
                access_.rare_inherited_usage_less_than_100_percent_data_)
                ->math_style_
                = static_cast<unsigned>(v);
    }

    inline void ResetMathStyle()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_100_percent_data_,
            access_.rare_inherited_usage_less_than_100_percent_data_)
            ->math_style_
            = static_cast<unsigned>(EMathStyle::kNormal);
    }

    // max-height
    const Length& MaxHeight() const
    {
        return box_data_->max_height_;
    }

    void SetMaxHeight(const Length& v)
    {
        if (!(box_data_->max_height_ == v))
            Access(box_data_, access_.box_data_)->max_height_ = v;
    }

    void SetMaxHeight(Length&& v)
    {
        if (!(box_data_->max_height_ == v))
            Access(box_data_, access_.box_data_)->max_height_ = std::move(v);
    }

    inline void ResetMaxHeight()
    {
        Access(box_data_, access_.box_data_)->max_height_ = Length::None();
    }

    // max-width
    const Length& MaxWidth() const
    {
        return box_data_->max_width_;
    }

    void SetMaxWidth(const Length& v)
    {
        if (!(box_data_->max_width_ == v))
            Access(box_data_, access_.box_data_)->max_width_ = v;
    }

    void SetMaxWidth(Length&& v)
    {
        if (!(box_data_->max_width_ == v))
            Access(box_data_, access_.box_data_)->max_width_ = std::move(v);
    }

    inline void ResetMaxWidth()
    {
        Access(box_data_, access_.box_data_)->max_width_ = Length::None();
    }

    // MayHaveMargin
    bool MayHaveMargin() const
    {
        return static_cast<bool>(surround_data_->may_have_margin_);
    }

    void SetMayHaveMargin()
    {
        if (!(surround_data_->may_have_margin_ == static_cast<unsigned>(true)))
            Access(surround_data_, access_.surround_data_)->may_have_margin_ = static_cast<unsigned>(true);
    }

    // MayHavePadding
    bool MayHavePadding() const
    {
        return static_cast<bool>(surround_data_->may_have_padding_);
    }

    void SetMayHavePadding()
    {
        if (!(surround_data_->may_have_padding_ == static_cast<unsigned>(true)))
            Access(surround_data_, access_.surround_data_)->may_have_padding_ = static_cast<unsigned>(true);
    }

    // min-height
    const Length& MinHeight() const
    {
        return box_data_->min_height_;
    }

    void SetMinHeight(const Length& v)
    {
        if (!(box_data_->min_height_ == v))
            Access(box_data_, access_.box_data_)->min_height_ = v;
    }

    void SetMinHeight(Length&& v)
    {
        if (!(box_data_->min_height_ == v))
            Access(box_data_, access_.box_data_)->min_height_ = std::move(v);
    }

    inline void ResetMinHeight()
    {
        Access(box_data_, access_.box_data_)->min_height_ = Length();
    }

    // min-width
    const Length& MinWidth() const
    {
        return box_data_->min_width_;
    }

    void SetMinWidth(const Length& v)
    {
        if (!(box_data_->min_width_ == v))
            Access(box_data_, access_.box_data_)->min_width_ = v;
    }

    void SetMinWidth(Length&& v)
    {
        if (!(box_data_->min_width_ == v))
            Access(box_data_, access_.box_data_)->min_width_ = std::move(v);
    }

    inline void ResetMinWidth()
    {
        Access(box_data_, access_.box_data_)->min_width_ = Length();
    }

    // NonInheritedVariables

    inline void ResetNonInheritedVariables()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->non_inherited_variables_
            = nullptr;
    }

    // object-fit
    EObjectFit GetObjectFit() const
    {
        return static_cast<EObjectFit>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->object_fit_);
    }

    void SetObjectFit(EObjectFit v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->object_fit_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->object_fit_
                = static_cast<unsigned>(v);
    }

    inline void ResetObjectFit()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->object_fit_
            = static_cast<unsigned>(EObjectFit::kFill);
    }

    // object-position
    const LengthPoint& ObjectPosition() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->object_position_;
    }

    void SetObjectPosition(const LengthPoint& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->object_position_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->object_position_
                = v;
    }

    void SetObjectPosition(LengthPoint&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->object_position_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->object_position_
                = std::move(v);
    }

    inline void ResetObjectPosition()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->object_position_
            = LengthPoint(Length::Percent(50.0), Length::Percent(50.0));
    }

    // object-view-box
    BasicShape* ObjectViewBox() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->object_view_box_.get();
    }

    void SetObjectViewBox(scoped_refptr<BasicShape> v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->object_view_box_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->object_view_box_
                = std::move(v);
    }

    // offset-anchor
    const LengthPoint& OffsetAnchor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_anchor_;
    }

    void SetOffsetAnchor(const LengthPoint& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->offset_anchor_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->offset_anchor_
                = v;
    }

    void SetOffsetAnchor(LengthPoint&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->offset_anchor_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->offset_anchor_
                = std::move(v);
    }

    inline void ResetOffsetAnchor()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->offset_anchor_
            = LengthPoint(Length::Auto(), Length::Auto());
    }

    // offset-distance
    const Length& OffsetDistance() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_distance_;
    }

    void SetOffsetDistance(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->offset_distance_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->offset_distance_
                = v;
    }

    void SetOffsetDistance(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->offset_distance_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->offset_distance_
                = std::move(v);
    }

    inline void ResetOffsetDistance()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->offset_distance_
            = Length::Fixed(0);
    }

    // offset-path
    OffsetPathOperation* OffsetPath() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_path_.Get();
    }

    void SetOffsetPath(Member<OffsetPathOperation> v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->offset_path_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->offset_path_
                = std::move(v);
    }

    // offset-position
    const LengthPoint& OffsetPosition() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_position_;
    }

    void SetOffsetPosition(const LengthPoint& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->offset_position_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->offset_position_
                = v;
    }

    void SetOffsetPosition(LengthPoint&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->offset_position_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->offset_position_
                = std::move(v);
    }

    inline void ResetOffsetPosition()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->offset_position_
            = LengthPoint(Length::None(), Length::None());
    }

    // offset-rotate
    const StyleOffsetRotation& OffsetRotate() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_rotate_;
    }

    void SetOffsetRotate(const StyleOffsetRotation& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->offset_rotate_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->offset_rotate_
                = v;
    }

    void SetOffsetRotate(StyleOffsetRotation&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->offset_rotate_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->offset_rotate_
                = std::move(v);
    }

    inline void ResetOffsetRotate()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->offset_rotate_
            = StyleOffsetRotation(0, OffsetRotationType::kAuto);
    }

    // opacity
    float Opacity() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->opacity_;
    }

    inline void ResetOpacity()
    {
        Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->opacity_ = 1.0;
    }

    // order
    int Order() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->order_;
    }

    void SetOrder(int v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->order_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->order_
                = v;
    }

    inline void ResetOrder()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->order_
            = 0;
    }

    // origin-trial-test-property
    EOriginTrialTestProperty OriginTrialTestProperty() const
    {
        return static_cast<EOriginTrialTestProperty>(data_.origin_trial_test_property_);
    }

    void SetOriginTrialTestProperty(EOriginTrialTestProperty v)
    {
        data_.origin_trial_test_property_ = static_cast<unsigned>(v);
    }

    inline void ResetOriginTrialTestProperty()
    {
        data_.origin_trial_test_property_ = static_cast<unsigned>(EOriginTrialTestProperty::kNormal);
    }

    // orphans
    short Orphans() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->orphans_;
    }

    inline void ResetOrphans()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->orphans_ = 2;
    }

    // outline-color

    void SetOutlineColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->outline_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->outline_color_
                = v;
    }

    void SetOutlineColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->outline_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->outline_color_
                = std::move(v);
    }

    inline void ResetOutlineColor()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->outline_color_
            = StyleColor::CurrentColor();
    }

    // outline-offset
    const LayoutUnit& OutlineOffset() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_;
    }

    void SetOutlineOffset(const LayoutUnit& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->outline_offset_
                = v;
    }

    void SetOutlineOffset(LayoutUnit&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->outline_offset_
                = std::move(v);
    }

    inline void ResetOutlineOffset()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->outline_offset_
            = LayoutUnit();
    }

    // outline-style
    EBorderStyle OutlineStyle() const
    {
        return static_cast<EBorderStyle>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_style_);
    }

    void SetOutlineStyle(EBorderStyle v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_style_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->outline_style_
                = static_cast<unsigned>(v);
    }

    inline void ResetOutlineStyle()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->outline_style_
            = static_cast<unsigned>(EBorderStyle::kNone);
    }

    // OutlineStyleIsAuto
    bool OutlineStyleIsAuto() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->outline_style_is_auto_);
    }

    void SetOutlineStyleIsAuto(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->outline_style_is_auto_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->outline_style_is_auto_
                = static_cast<unsigned>(v);
    }

    inline void ResetOutlineStyleIsAuto()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->outline_style_is_auto_
            = static_cast<unsigned>(false);
    }

    // outline-width

    void SetOutlineWidth(const int& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_width_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->outline_width_
                = v;
    }

    void SetOutlineWidth(int&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_width_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->outline_width_
                = std::move(v);
    }

    inline void ResetOutlineWidth()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->outline_width_
            = 3;
    }

    // overflow-anchor
    EOverflowAnchor OverflowAnchor() const
    {
        return static_cast<EOverflowAnchor>(data_.overflow_anchor_);
    }

    void SetOverflowAnchor(EOverflowAnchor v)
    {
        data_.overflow_anchor_ = static_cast<unsigned>(v);
    }

    inline void ResetOverflowAnchor()
    {
        data_.overflow_anchor_ = static_cast<unsigned>(EOverflowAnchor::kAuto);
    }

    // overflow-clip-margin
    const std::optional<StyleOverflowClipMargin>& OverflowClipMargin() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_;
    }

    void SetOverflowClipMargin(const std::optional<StyleOverflowClipMargin>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->overflow_clip_margin_
                = v;
    }

    void SetOverflowClipMargin(std::optional<StyleOverflowClipMargin>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->overflow_clip_margin_
                = std::move(v);
    }

    inline void ResetOverflowClipMargin()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->overflow_clip_margin_
            = std::nullopt;
    }

    // overflow-wrap
    EOverflowWrap OverflowWrap() const
    {
        return static_cast<EOverflowWrap>(rare_inherited_usage_less_than_64_percent_data_->overflow_wrap_);
    }

    void SetOverflowWrap(EOverflowWrap v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->overflow_wrap_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->overflow_wrap_
                = static_cast<unsigned>(v);
    }

    inline void ResetOverflowWrap()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->overflow_wrap_
            = static_cast<unsigned>(EOverflowWrap::kNormal);
    }

    // overflow-x
    EOverflow OverflowX() const
    {
        return static_cast<EOverflow>(data_.overflow_x_);
    }

    void SetOverflowX(EOverflow v)
    {
        data_.overflow_x_ = static_cast<unsigned>(v);
    }

    inline void ResetOverflowX()
    {
        data_.overflow_x_ = static_cast<unsigned>(EOverflow::kVisible);
    }

    // overflow-y
    EOverflow OverflowY() const
    {
        return static_cast<EOverflow>(data_.overflow_y_);
    }

    void SetOverflowY(EOverflow v)
    {
        data_.overflow_y_ = static_cast<unsigned>(v);
    }

    inline void ResetOverflowY()
    {
        data_.overflow_y_ = static_cast<unsigned>(EOverflow::kVisible);
    }

    // overlay
    EOverlay Overlay() const
    {
        return static_cast<EOverlay>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overlay_);
    }

    void SetOverlay(EOverlay v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overlay_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->overlay_
                = static_cast<unsigned>(v);
    }

    inline void ResetOverlay()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->overlay_
            = static_cast<unsigned>(EOverlay::kNone);
    }

    // overscroll-behavior-x
    EOverscrollBehavior OverscrollBehaviorX() const
    {
        return static_cast<EOverscrollBehavior>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overscroll_behavior_x_);
    }

    void SetOverscrollBehaviorX(EOverscrollBehavior v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overscroll_behavior_x_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->overscroll_behavior_x_
                = static_cast<unsigned>(v);
    }

    inline void ResetOverscrollBehaviorX()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->overscroll_behavior_x_
            = static_cast<unsigned>(EOverscrollBehavior::kAuto);
    }

    // overscroll-behavior-y
    EOverscrollBehavior OverscrollBehaviorY() const
    {
        return static_cast<EOverscrollBehavior>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overscroll_behavior_y_);
    }

    void SetOverscrollBehaviorY(EOverscrollBehavior v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overscroll_behavior_y_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->overscroll_behavior_y_
                = static_cast<unsigned>(v);
    }

    inline void ResetOverscrollBehaviorY()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->overscroll_behavior_y_
            = static_cast<unsigned>(EOverscrollBehavior::kAuto);
    }

    // padding-bottom
    const Length& PaddingBottom() const
    {
        return box_data_->padding_bottom_;
    }

    inline void ResetPaddingBottom()
    {
        Access(box_data_, access_.box_data_)->padding_bottom_ = Length::Fixed();
    }

    // padding-left
    const Length& PaddingLeft() const
    {
        return box_data_->padding_left_;
    }

    inline void ResetPaddingLeft()
    {
        Access(box_data_, access_.box_data_)->padding_left_ = Length::Fixed();
    }

    // padding-right
    const Length& PaddingRight() const
    {
        return box_data_->padding_right_;
    }

    inline void ResetPaddingRight()
    {
        Access(box_data_, access_.box_data_)->padding_right_ = Length::Fixed();
    }

    // padding-top
    const Length& PaddingTop() const
    {
        return box_data_->padding_top_;
    }

    inline void ResetPaddingTop()
    {
        Access(box_data_, access_.box_data_)->padding_top_ = Length::Fixed();
    }

    // page
    const AtomicString& Page() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->page_;
    }

    void SetPage(const AtomicString& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->page_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->page_
                = v;
    }

    void SetPage(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->page_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->page_
                = std::move(v);
    }

    inline void ResetPage()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->page_
            = AtomicString();
    }

    // page-orientation
    PageOrientation GetPageOrientation() const
    {
        return static_cast<PageOrientation>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->page_orientation_);
    }

    void SetPageOrientation(PageOrientation v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->page_orientation_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->page_orientation_
                = static_cast<unsigned>(v);
    }

    inline void ResetPageOrientation()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->page_orientation_
            = static_cast<unsigned>(PageOrientation::kUpright);
    }

    // PageSize
    const gfx::SizeF& PageSize() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_;
    }

    void SetPageSize(const gfx::SizeF& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->page_size_
                = v;
    }

    void SetPageSize(gfx::SizeF&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->page_size_
                = std::move(v);
    }

    inline void ResetPageSize()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->page_size_
            = gfx::SizeF();
    }

    // PageSizeType
    PageSizeType GetPageSizeType() const
    {
        return static_cast<PageSizeType>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_type_);
    }

    void SetPageSizeType(PageSizeType v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_type_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->page_size_type_
                = static_cast<unsigned>(v);
    }

    inline void ResetPageSizeType()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->page_size_type_
            = static_cast<unsigned>(PageSizeType::kAuto);
    }

    // PaintImages

    inline void ResetPaintImages()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->paint_images_
            = nullptr;
    }

    // paint-order
    EPaintOrder PaintOrder() const
    {
        return static_cast<EPaintOrder>(svg_data_->paint_order_);
    }

    void SetPaintOrder(EPaintOrder v)
    {
        if (!(svg_data_->paint_order_ == static_cast<unsigned>(v)))
            Access(svg_data_, access_.svg_data_)->paint_order_ = static_cast<unsigned>(v);
    }

    inline void ResetPaintOrder()
    {
        Access(svg_data_, access_.svg_data_)->paint_order_ = static_cast<unsigned>(kPaintOrderNormal);
    }

    // perspective
    float Perspective() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_;
    }

    void SetPerspective(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->perspective_
                = v;
    }

    inline void ResetPerspective()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->perspective_
            = -1.0;
    }

    // perspective-origin
    const LengthPoint& PerspectiveOrigin() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_origin_;
    }

    void SetPerspectiveOrigin(const LengthPoint& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_origin_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->perspective_origin_
                = v;
    }

    void SetPerspectiveOrigin(LengthPoint&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_origin_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->perspective_origin_
                = std::move(v);
    }

    inline void ResetPerspectiveOrigin()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->perspective_origin_
            = LengthPoint(Length::Percent(50.0), Length::Percent(50.0));
    }

    // pointer-events

    void SetPointerEvents(EPointerEvents v)
    {
        data_.pointer_events_ = static_cast<unsigned>(v);
    }

    inline void ResetPointerEvents()
    {
        data_.pointer_events_ = static_cast<unsigned>(EPointerEvents::kAuto);
    }

    // pointer-events

    void SetPointerEventsIsInherited(bool v)
    {
        data_.pointer_events_is_inherited_ = static_cast<unsigned>(v);
    }

    inline void ResetPointerEventsIsInherited()
    {
        data_.pointer_events_is_inherited_ = static_cast<unsigned>(true);
    }

    // popover-hide-delay
    float PopoverHideDelay() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->popover_hide_delay_;
    }

    void SetPopoverHideDelay(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->popover_hide_delay_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->popover_hide_delay_
                = v;
    }

    inline void ResetPopoverHideDelay()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->popover_hide_delay_
            = HUGE_VALF;
    }

    // popover-show-delay
    float PopoverShowDelay() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->popover_show_delay_;
    }

    void SetPopoverShowDelay(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->popover_show_delay_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->popover_show_delay_
                = v;
    }

    inline void ResetPopoverShowDelay()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->popover_show_delay_
            = 0.5;
    }

    // position

    void SetPosition(EPosition v)
    {
        data_.position_ = static_cast<unsigned>(v);
    }

    inline void ResetPosition()
    {
        data_.position_ = static_cast<unsigned>(EPosition::kStatic);
    }

    // position-anchor
    const Member<ScopedCSSName>& PositionAnchor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_anchor_;
    }

    void SetPositionAnchor(const Member<ScopedCSSName>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_anchor_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->position_anchor_
                = v;
    }

    void SetPositionAnchor(Member<ScopedCSSName>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_anchor_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->position_anchor_
                = std::move(v);
    }

    inline void ResetPositionAnchor()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->position_anchor_
            = nullptr;
    }

    // position-area
    const PositionArea& GetPositionArea() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_area_;
    }

    void SetPositionArea(const PositionArea& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_area_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->position_area_
                = v;
    }

    void SetPositionArea(PositionArea&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_area_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->position_area_
                = std::move(v);
    }

    inline void ResetPositionArea()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->position_area_
            = PositionArea();
    }

    // PositionAreaOffsets
    const std::optional<blink::PositionAreaOffsets>& PositionAreaOffsets() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_area_offsets_;
    }

    void SetPositionAreaOffsets(const std::optional<blink::PositionAreaOffsets>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_area_offsets_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->position_area_offsets_
                = v;
    }

    void SetPositionAreaOffsets(std::optional<blink::PositionAreaOffsets>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_area_offsets_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->position_area_offsets_
                = std::move(v);
    }

    inline void ResetPositionAreaOffsets()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->position_area_offsets_
            = std::nullopt;
    }

    // position-try-fallbacks
    const Member<PositionTryFallbacks>& GetPositionTryFallbacks() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_fallbacks_;
    }

    void SetPositionTryFallbacks(const Member<PositionTryFallbacks>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_fallbacks_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->position_try_fallbacks_
                = v;
    }

    void SetPositionTryFallbacks(Member<PositionTryFallbacks>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_fallbacks_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->position_try_fallbacks_
                = std::move(v);
    }

    inline void ResetPositionTryFallbacks()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->position_try_fallbacks_
            = nullptr;
    }

    // position-try-order
    EPositionTryOrder PositionTryOrder() const
    {
        return static_cast<EPositionTryOrder>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_order_);
    }

    void SetPositionTryOrder(EPositionTryOrder v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_try_order_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->position_try_order_
                = static_cast<unsigned>(v);
    }

    inline void ResetPositionTryOrder()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->position_try_order_
            = static_cast<unsigned>(EPositionTryOrder::kNormal);
    }

    // position-visibility
    PositionVisibility GetPositionVisibility() const
    {
        return static_cast<PositionVisibility>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_visibility_);
    }

    void SetPositionVisibility(PositionVisibility v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_visibility_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->position_visibility_
                = static_cast<unsigned>(v);
    }

    inline void ResetPositionVisibility()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->position_visibility_
            = static_cast<unsigned>(PositionVisibility::kAlways);
    }

    // PrefersDefaultScrollbarStyles
    bool PrefersDefaultScrollbarStyles() const
    {
        return static_cast<bool>(data_.prefers_default_scrollbar_styles_);
    }

    void SetPrefersDefaultScrollbarStyles(bool v)
    {
        data_.prefers_default_scrollbar_styles_ = static_cast<unsigned>(v);
    }

    inline void ResetPrefersDefaultScrollbarStyles()
    {
        data_.prefers_default_scrollbar_styles_ = static_cast<unsigned>(false);
    }

    // -webkit-print-color-adjust
    EPrintColorAdjust PrintColorAdjust() const
    {
        return static_cast<EPrintColorAdjust>(data_.print_color_adjust_);
    }

    void SetPrintColorAdjust(EPrintColorAdjust v)
    {
        data_.print_color_adjust_ = static_cast<unsigned>(v);
    }

    inline void ResetPrintColorAdjust()
    {
        data_.print_color_adjust_ = static_cast<unsigned>(EPrintColorAdjust::kEconomy);
    }

    // PseudoArgument
    const AtomicString& PseudoArgument() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->pseudo_argument_;
    }

    void SetPseudoArgument(const AtomicString& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->pseudo_argument_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->pseudo_argument_
                = v;
    }

    void SetPseudoArgument(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->pseudo_argument_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->pseudo_argument_
                = std::move(v);
    }

    inline void ResetPseudoArgument()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->pseudo_argument_
            = g_null_atom;
    }

    // PseudoElementStyles

    void SetPseudoElementStyles(unsigned v)
    {
        data_.pseudo_element_styles_ = static_cast<unsigned>(v);
    }

    inline void ResetPseudoElementStyles()
    {
        data_.pseudo_element_styles_ = static_cast<unsigned>(kPseudoIdNone);
    }

    // quotes
    QuotesData* Quotes() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->quotes_.get();
    }

    void SetQuotes(scoped_refptr<QuotesData> v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->quotes_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->quotes_ = std::move(v);
    }

    // r
    const Length& R() const
    {
        return svg_data_->geometry_data_->r_;
    }

    void SetR(const Length& v)
    {
        if (!(svg_data_->geometry_data_->r_ == v))
            Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->r_ = v;
    }

    void SetR(Length&& v)
    {
        if (!(svg_data_->geometry_data_->r_ == v))
            Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->r_ = std::move(v);
    }

    inline void ResetR()
    {
        Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->r_ = Length::Fixed();
    }

    // reading-flow
    EReadingFlow ReadingFlow() const
    {
        return static_cast<EReadingFlow>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->reading_flow_);
    }

    void SetReadingFlow(EReadingFlow v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->reading_flow_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->reading_flow_
                = static_cast<unsigned>(v);
    }

    inline void ResetReadingFlow()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->reading_flow_
            = static_cast<unsigned>(EReadingFlow::kNormal);
    }

    // RequiresAcceleratedCompositingForExternalReasons
    bool RequiresAcceleratedCompositingForExternalReasons() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                                     ->requires_accelerated_compositing_for_external_reasons_);
    }

    void SetRequiresAcceleratedCompositingForExternalReasons(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                    ->requires_accelerated_compositing_for_external_reasons_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->requires_accelerated_compositing_for_external_reasons_
                = static_cast<unsigned>(v);
    }

    inline void ResetRequiresAcceleratedCompositingForExternalReasons()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->requires_accelerated_compositing_for_external_reasons_
            = static_cast<unsigned>(false);
    }

    // resize

    void SetResize(EResize v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->resize_ == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->resize_
                = static_cast<unsigned>(v);
    }

    inline void ResetResize()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->resize_
            = static_cast<unsigned>(EResize::kNone);
    }

    // right
    const Length& Right() const
    {
        return surround_data_->right_;
    }

    void SetRight(const Length& v)
    {
        if (!(surround_data_->right_ == v))
            Access(surround_data_, access_.surround_data_)->right_ = v;
    }

    void SetRight(Length&& v)
    {
        if (!(surround_data_->right_ == v))
            Access(surround_data_, access_.surround_data_)->right_ = std::move(v);
    }

    inline void ResetRight()
    {
        Access(surround_data_, access_.surround_data_)->right_ = Length();
    }

    // rotate
    RotateTransformOperation* Rotate() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->rotate_.Get();
    }

    void SetRotate(Member<RotateTransformOperation> v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->rotate_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->rotate_
                = std::move(v);
    }

    // row-gap
    const std::optional<Length>& RowGap() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->row_gap_;
    }

    void SetRowGap(const std::optional<Length>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->row_gap_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->row_gap_
                = v;
    }

    void SetRowGap(std::optional<Length>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->row_gap_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->row_gap_
                = std::move(v);
    }

    inline void ResetRowGap()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->row_gap_
            = std::nullopt;
    }

    // -webkit-rtl-ordering
    EOrder RtlOrdering() const
    {
        return static_cast<EOrder>(data_.rtl_ordering_);
    }

    void SetRtlOrdering(EOrder v)
    {
        data_.rtl_ordering_ = static_cast<unsigned>(v);
    }

    inline void ResetRtlOrdering()
    {
        data_.rtl_ordering_ = static_cast<unsigned>(EOrder::kLogical);
    }

    // -webkit-rtl-ordering
    bool RtlOrderingIsInherited() const
    {
        return static_cast<bool>(data_.rtl_ordering_is_inherited_);
    }

    void SetRtlOrderingIsInherited(bool v)
    {
        data_.rtl_ordering_is_inherited_ = static_cast<unsigned>(v);
    }

    inline void ResetRtlOrderingIsInherited()
    {
        data_.rtl_ordering_is_inherited_ = static_cast<unsigned>(true);
    }

    // ruby-align
    ERubyAlign RubyAlign() const
    {
        return static_cast<ERubyAlign>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ruby_align_);
    }

    void SetRubyAlign(ERubyAlign v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ruby_align_ == static_cast<unsigned>(v)))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->ruby_align_
                = static_cast<unsigned>(v);
    }

    inline void ResetRubyAlign()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->ruby_align_
            = static_cast<unsigned>(ERubyAlign::kSpaceAround);
    }

    // ruby-position
    RubyPosition GetRubyPosition() const
    {
        return static_cast<RubyPosition>(rare_inherited_usage_less_than_64_percent_data_->ruby_position_);
    }

    void SetRubyPosition(RubyPosition v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->ruby_position_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->ruby_position_
                = static_cast<unsigned>(v);
    }

    inline void ResetRubyPosition()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->ruby_position_
            = static_cast<unsigned>(RubyPosition::kOver);
    }

    // rx
    const Length& Rx() const
    {
        return svg_data_->geometry_data_->rx_;
    }

    void SetRx(const Length& v)
    {
        if (!(svg_data_->geometry_data_->rx_ == v))
            Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->rx_ = v;
    }

    void SetRx(Length&& v)
    {
        if (!(svg_data_->geometry_data_->rx_ == v))
            Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->rx_ = std::move(v);
    }

    inline void ResetRx()
    {
        Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->rx_ = Length::Auto();
    }

    // ry
    const Length& Ry() const
    {
        return svg_data_->geometry_data_->ry_;
    }

    void SetRy(const Length& v)
    {
        if (!(svg_data_->geometry_data_->ry_ == v))
            Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->ry_ = v;
    }

    void SetRy(Length&& v)
    {
        if (!(svg_data_->geometry_data_->ry_ == v))
            Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->ry_ = std::move(v);
    }

    inline void ResetRy()
    {
        Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->ry_ = Length::Auto();
    }

    // scale
    ScaleTransformOperation* Scale() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->scale_.Get();
    }

    void SetScale(Member<ScaleTransformOperation> v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->scale_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->scale_
                = std::move(v);
    }

    // scroll-behavior
    mojom::blink::ScrollBehavior GetScrollBehavior() const
    {
        return static_cast<mojom::blink::ScrollBehavior>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_behavior_);
    }

    void SetScrollBehavior(mojom::blink::ScrollBehavior v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_behavior_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->scroll_behavior_
                = static_cast<unsigned>(v);
    }

    inline void ResetScrollBehavior()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->scroll_behavior_
            = static_cast<unsigned>(mojom::blink::ScrollBehavior::kAuto);
    }

    // scroll-margin-bottom
    float ScrollMarginBottom() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_bottom_;
    }

    void SetScrollMarginBottom(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_bottom_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->scroll_margin_bottom_
                = v;
    }

    inline void ResetScrollMarginBottom()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->scroll_margin_bottom_
            = 0.0f;
    }

    // scroll-margin-left
    float ScrollMarginLeft() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_left_;
    }

    void SetScrollMarginLeft(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_left_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->scroll_margin_left_
                = v;
    }

    inline void ResetScrollMarginLeft()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->scroll_margin_left_
            = 0.0f;
    }

    // scroll-margin-right
    float ScrollMarginRight() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_right_;
    }

    void SetScrollMarginRight(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_right_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->scroll_margin_right_
                = v;
    }

    inline void ResetScrollMarginRight()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->scroll_margin_right_
            = 0.0f;
    }

    // scroll-margin-top
    float ScrollMarginTop() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_top_;
    }

    void SetScrollMarginTop(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_top_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->scroll_margin_top_
                = v;
    }

    inline void ResetScrollMarginTop()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->scroll_margin_top_
            = 0.0f;
    }

    // scroll-marker-group
    EScrollMarkerGroup ScrollMarkerGroup() const
    {
        return static_cast<EScrollMarkerGroup>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_marker_group_);
    }

    void SetScrollMarkerGroup(EScrollMarkerGroup v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_marker_group_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->scroll_marker_group_
                = static_cast<unsigned>(v);
    }

    inline void ResetScrollMarkerGroup()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->scroll_marker_group_
            = static_cast<unsigned>(EScrollMarkerGroup::kNone);
    }

    // scroll-padding-bottom
    const Length& ScrollPaddingBottom() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_bottom_;
    }

    void SetScrollPaddingBottom(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_bottom_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->scroll_padding_bottom_
                = v;
    }

    void SetScrollPaddingBottom(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_bottom_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->scroll_padding_bottom_
                = std::move(v);
    }

    inline void ResetScrollPaddingBottom()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->scroll_padding_bottom_
            = Length();
    }

    // scroll-padding-left
    const Length& ScrollPaddingLeft() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_left_;
    }

    void SetScrollPaddingLeft(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_left_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->scroll_padding_left_
                = v;
    }

    void SetScrollPaddingLeft(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_left_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->scroll_padding_left_
                = std::move(v);
    }

    inline void ResetScrollPaddingLeft()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->scroll_padding_left_
            = Length();
    }

    // scroll-padding-right
    const Length& ScrollPaddingRight() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_right_;
    }

    void SetScrollPaddingRight(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_right_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->scroll_padding_right_
                = v;
    }

    void SetScrollPaddingRight(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_right_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->scroll_padding_right_
                = std::move(v);
    }

    inline void ResetScrollPaddingRight()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->scroll_padding_right_
            = Length();
    }

    // scroll-padding-top
    const Length& ScrollPaddingTop() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_top_;
    }

    void SetScrollPaddingTop(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_top_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->scroll_padding_top_
                = v;
    }

    void SetScrollPaddingTop(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_padding_top_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->scroll_padding_top_
                = std::move(v);
    }

    inline void ResetScrollPaddingTop()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->scroll_padding_top_
            = Length();
    }

    // scroll-snap-align
    const cc::ScrollSnapAlign& GetScrollSnapAlign() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_align_;
    }

    void SetScrollSnapAlign(const cc::ScrollSnapAlign& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_align_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->scroll_snap_align_
                = v;
    }

    void SetScrollSnapAlign(cc::ScrollSnapAlign&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_align_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->scroll_snap_align_
                = std::move(v);
    }

    inline void ResetScrollSnapAlign()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->scroll_snap_align_
            = cc::ScrollSnapAlign();
    }

    // scroll-snap-stop
    EScrollSnapStop ScrollSnapStop() const
    {
        return static_cast<EScrollSnapStop>(data_.scroll_snap_stop_);
    }

    void SetScrollSnapStop(EScrollSnapStop v)
    {
        data_.scroll_snap_stop_ = static_cast<unsigned>(v);
    }

    inline void ResetScrollSnapStop()
    {
        data_.scroll_snap_stop_ = static_cast<unsigned>(EScrollSnapStop::kNormal);
    }

    // scroll-snap-type
    const cc::ScrollSnapType& GetScrollSnapType() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_type_;
    }

    void SetScrollSnapType(const cc::ScrollSnapType& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_type_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->scroll_snap_type_
                = v;
    }

    void SetScrollSnapType(cc::ScrollSnapType&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_snap_type_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->scroll_snap_type_
                = std::move(v);
    }

    inline void ResetScrollSnapType()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->scroll_snap_type_
            = cc::ScrollSnapType();
    }

    // scroll-start-target
    EScrollStartTarget ScrollStartTarget() const
    {
        return static_cast<EScrollStartTarget>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_start_target_);
    }

    void SetScrollStartTarget(EScrollStartTarget v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_start_target_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->scroll_start_target_
                = static_cast<unsigned>(v);
    }

    inline void ResetScrollStartTarget()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->scroll_start_target_
            = static_cast<unsigned>(EScrollStartTarget::kNone);
    }

    // scroll-start-x
    const ScrollStartData& ScrollStartX() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_x_;
    }

    void SetScrollStartX(const ScrollStartData& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_x_ == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->start_data_,
                access_.start_data_)
                ->scroll_start_x_
                = v;
    }

    void SetScrollStartX(ScrollStartData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_x_ == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->start_data_,
                access_.start_data_)
                ->scroll_start_x_
                = std::move(v);
    }

    inline void ResetScrollStartX()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->start_data_,
            access_.start_data_)
            ->scroll_start_x_
            = blink::ScrollStartData();
    }

    // scroll-start-y
    const ScrollStartData& ScrollStartY() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_y_;
    }

    void SetScrollStartY(const ScrollStartData& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_y_ == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->start_data_,
                access_.start_data_)
                ->scroll_start_y_
                = v;
    }

    void SetScrollStartY(ScrollStartData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->start_data_->scroll_start_y_ == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->start_data_,
                access_.start_data_)
                ->scroll_start_y_
                = std::move(v);
    }

    inline void ResetScrollStartY()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->start_data_,
            access_.start_data_)
            ->scroll_start_y_
            = blink::ScrollStartData();
    }

    // scroll-timeline-axis
    const Vector<TimelineAxis>& ScrollTimelineAxis() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
            ->scroll_timeline_axis_;
    }

    void SetScrollTimelineAxis(const Vector<TimelineAxis>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
                    ->scroll_timeline_axis_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->timeline_data_,
                access_.timeline_data_)
                ->scroll_timeline_axis_
                = v;
    }

    void SetScrollTimelineAxis(Vector<TimelineAxis>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
                    ->scroll_timeline_axis_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->timeline_data_,
                access_.timeline_data_)
                ->scroll_timeline_axis_
                = std::move(v);
    }

    inline void ResetScrollTimelineAxis()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->timeline_data_,
            access_.timeline_data_)
            ->scroll_timeline_axis_
            = Vector<TimelineAxis>();
    }

    // scroll-timeline-name
    const Member<ScopedCSSNameList>& ScrollTimelineName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
            ->scroll_timeline_name_;
    }

    void SetScrollTimelineName(const Member<ScopedCSSNameList>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
                    ->scroll_timeline_name_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->timeline_data_,
                access_.timeline_data_)
                ->scroll_timeline_name_
                = v;
    }

    void SetScrollTimelineName(Member<ScopedCSSNameList>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
                    ->scroll_timeline_name_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->timeline_data_,
                access_.timeline_data_)
                ->scroll_timeline_name_
                = std::move(v);
    }

    inline void ResetScrollTimelineName()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->timeline_data_,
            access_.timeline_data_)
            ->scroll_timeline_name_
            = nullptr;
    }

    // scrollbar-color
    StyleScrollbarColor* ScrollbarColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->scrollbar_color_.Get();
    }

    void SetScrollbarColor(Member<StyleScrollbarColor> v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->scrollbar_color_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->scrollbar_color_
                = std::move(v);
    }

    // scrollbar-gutter
    unsigned ScrollbarGutter() const
    {
        return static_cast<unsigned>(data_.scrollbar_gutter_);
    }

    void SetScrollbarGutter(unsigned v)
    {
        data_.scrollbar_gutter_ = static_cast<unsigned>(v);
    }

    inline void ResetScrollbarGutter()
    {
        data_.scrollbar_gutter_ = static_cast<unsigned>(kScrollbarGutterAuto);
    }

    // scrollbar-width
    EScrollbarWidth ScrollbarWidth() const
    {
        return static_cast<EScrollbarWidth>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scrollbar_width_);
    }

    void SetScrollbarWidth(EScrollbarWidth v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scrollbar_width_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->scrollbar_width_
                = static_cast<unsigned>(v);
    }

    inline void ResetScrollbarWidth()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->scrollbar_width_
            = static_cast<unsigned>(EScrollbarWidth::kAuto);
    }

    // shape-image-threshold
    float ShapeImageThreshold() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->shape_image_threshold_;
    }

    inline void ResetShapeImageThreshold()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->shape_image_threshold_
            = 0.0;
    }

    // shape-margin
    const Length& ShapeMargin() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->shape_margin_;
    }

    void SetShapeMargin(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->shape_margin_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->shape_margin_
                = v;
    }

    void SetShapeMargin(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->shape_margin_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->shape_margin_
                = std::move(v);
    }

    inline void ResetShapeMargin()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->shape_margin_
            = Length::Fixed(0);
    }

    // shape-outside

    void SetShapeOutside(const Member<ShapeValue>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->shape_outside_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->shape_outside_
                = v;
    }

    void SetShapeOutside(Member<ShapeValue>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->shape_outside_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->shape_outside_
                = std::move(v);
    }

    inline void ResetShapeOutside()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->shape_outside_
            = nullptr;
    }

    // shape-rendering
    EShapeRendering ShapeRendering() const
    {
        return static_cast<EShapeRendering>(svg_data_->shape_rendering_);
    }

    void SetShapeRendering(EShapeRendering v)
    {
        if (!(svg_data_->shape_rendering_ == static_cast<unsigned>(v)))
            Access(svg_data_, access_.svg_data_)->shape_rendering_ = static_cast<unsigned>(v);
    }

    inline void ResetShapeRendering()
    {
        Access(svg_data_, access_.svg_data_)->shape_rendering_ = static_cast<unsigned>(EShapeRendering::kAuto);
    }

    // ShouldIgnoreOverflowPropertyForInlineBlockBaseline
    bool ShouldIgnoreOverflowPropertyForInlineBlockBaseline() const
    {
        return static_cast<bool>(data_.should_ignore_overflow_property_for_inline_block_baseline_);
    }

    void SetShouldIgnoreOverflowPropertyForInlineBlockBaseline()
    {
        data_.should_ignore_overflow_property_for_inline_block_baseline_ = static_cast<unsigned>(true);
    }

    // SkipsContents
    bool SkipsContents() const
    {
        return static_cast<bool>(data_.skips_contents_);
    }

    void SetSkipsContents(bool v)
    {
        data_.skips_contents_ = static_cast<unsigned>(v);
    }

    inline void ResetSkipsContents()
    {
        data_.skips_contents_ = static_cast<unsigned>(false);
    }

    // speak
    ESpeak Speak() const
    {
        return static_cast<ESpeak>(rare_inherited_usage_less_than_64_percent_data_->speak_);
    }

    void SetSpeak(ESpeak v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->speak_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->speak_ = static_cast<unsigned>(v);
    }

    inline void ResetSpeak()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->speak_
            = static_cast<unsigned>(ESpeak::kNormal);
    }

    // line-clamp
    int StandardLineClamp() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->standard_line_clamp_;
    }

    inline void ResetStandardLineClamp()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->standard_line_clamp_
            = 0;
    }

    // stop-color

    void SetStopColor(const StyleColor& v)
    {
        if (!(svg_data_->stop_data_->stop_color_ == v))
            Access(Access(svg_data_, access_.svg_data_)->stop_data_, access_.stop_data_)->stop_color_ = v;
    }

    void SetStopColor(StyleColor&& v)
    {
        if (!(svg_data_->stop_data_->stop_color_ == v))
            Access(Access(svg_data_, access_.svg_data_)->stop_data_, access_.stop_data_)->stop_color_ = std::move(v);
    }

    inline void ResetStopColor()
    {
        Access(Access(svg_data_, access_.svg_data_)->stop_data_, access_.stop_data_)->stop_color_ = StyleColor(Color::kBlack);
    }

    // stop-opacity
    float StopOpacity() const
    {
        return svg_data_->stop_data_->stop_opacity_;
    }

    void SetStopOpacity(float v)
    {
        if (!(svg_data_->stop_data_->stop_opacity_ == v))
            Access(Access(svg_data_, access_.svg_data_)->stop_data_, access_.stop_data_)->stop_opacity_ = v;
    }

    inline void ResetStopOpacity()
    {
        Access(Access(svg_data_, access_.svg_data_)->stop_data_, access_.stop_data_)->stop_opacity_ = 1;
    }

    // stroke-dasharray
    SVGDashArray* StrokeDashArray() const
    {
        return svg_data_->stroke_data_->stroke_dash_array_.get();
    }

    void SetStrokeDashArray(scoped_refptr<SVGDashArray> v)
    {
        if (!(svg_data_->stroke_data_->stroke_dash_array_ == v))
            Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_dash_array_ = std::move(v);
    }

    // stroke-dashoffset
    const Length& StrokeDashOffset() const
    {
        return svg_data_->stroke_data_->stroke_dash_offset_;
    }

    void SetStrokeDashOffset(const Length& v)
    {
        if (!(svg_data_->stroke_data_->stroke_dash_offset_ == v))
            Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_dash_offset_ = v;
    }

    void SetStrokeDashOffset(Length&& v)
    {
        if (!(svg_data_->stroke_data_->stroke_dash_offset_ == v))
            Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_dash_offset_ = std::move(v);
    }

    inline void ResetStrokeDashOffset()
    {
        Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_dash_offset_ = Length::Fixed();
    }

    // stroke-miterlimit
    float StrokeMiterLimit() const
    {
        return svg_data_->stroke_data_->stroke_miter_limit_;
    }

    void SetStrokeMiterLimit(float v)
    {
        if (!(svg_data_->stroke_data_->stroke_miter_limit_ == v))
            Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_miter_limit_ = v;
    }

    inline void ResetStrokeMiterLimit()
    {
        Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_miter_limit_ = 4;
    }

    // stroke-opacity
    float StrokeOpacity() const
    {
        return svg_data_->stroke_data_->stroke_opacity_;
    }

    void SetStrokeOpacity(float v)
    {
        if (!(svg_data_->stroke_data_->stroke_opacity_ == v))
            Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_opacity_ = v;
    }

    inline void ResetStrokeOpacity()
    {
        Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_opacity_ = 1;
    }

    // stroke
    const SVGPaint& StrokePaint() const
    {
        return svg_data_->stroke_data_->stroke_paint_;
    }

    void SetStrokePaint(const SVGPaint& v)
    {
        if (!(svg_data_->stroke_data_->stroke_paint_ == v))
            Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_paint_ = v;
    }

    void SetStrokePaint(SVGPaint&& v)
    {
        if (!(svg_data_->stroke_data_->stroke_paint_ == v))
            Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_paint_ = std::move(v);
    }

    inline void ResetStrokePaint()
    {
        Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_paint_ = SVGPaint();
    }

    // stroke-width
    const UnzoomedLength& StrokeWidth() const
    {
        return svg_data_->stroke_data_->stroke_width_;
    }

    void SetStrokeWidth(const UnzoomedLength& v)
    {
        if (!(svg_data_->stroke_data_->stroke_width_ == v))
            Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_width_ = v;
    }

    void SetStrokeWidth(UnzoomedLength&& v)
    {
        if (!(svg_data_->stroke_data_->stroke_width_ == v))
            Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_width_ = std::move(v);
    }

    inline void ResetStrokeWidth()
    {
        Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_width_ = UnzoomedLength(Length::Fixed(1));
    }

    // StyleType
    PseudoId StyleType() const
    {
        return static_cast<PseudoId>(data_.style_type_);
    }

    void SetStyleType(PseudoId v)
    {
        data_.style_type_ = static_cast<unsigned>(v);
    }

    inline void ResetStyleType()
    {
        data_.style_type_ = static_cast<unsigned>(PseudoId::kPseudoIdNone);
    }

    // SubtreeIsSticky
    bool SubtreeIsSticky() const
    {
        return static_cast<bool>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_is_sticky_);
    }

    void SetSubtreeIsSticky(bool v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_is_sticky_
                == static_cast<unsigned>(v)))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->subtree_is_sticky_
                = static_cast<unsigned>(v);
    }

    inline void ResetSubtreeIsSticky()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->subtree_is_sticky_
            = static_cast<unsigned>(false);
    }

    // SubtreeWillChangeContents
    bool SubtreeWillChangeContents() const
    {
        return static_cast<bool>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_will_change_contents_);
    }

    void SetSubtreeWillChangeContents(bool v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_will_change_contents_
                == static_cast<unsigned>(v)))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->subtree_will_change_contents_
                = static_cast<unsigned>(v);
    }

    inline void ResetSubtreeWillChangeContents()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->subtree_will_change_contents_
            = static_cast<unsigned>(false);
    }

    // tab-size
    const TabSize& GetTabSize() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->tab_size_;
    }

    inline void ResetTabSize()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->tab_size_ = TabSize(8);
    }

    // table-layout
    ETableLayout TableLayout() const
    {
        return static_cast<ETableLayout>(data_.table_layout_);
    }

    void SetTableLayout(ETableLayout v)
    {
        data_.table_layout_ = static_cast<unsigned>(v);
    }

    inline void ResetTableLayout()
    {
        data_.table_layout_ = static_cast<unsigned>(ETableLayout::kAuto);
    }

    // -webkit-tap-highlight-color
    const StyleColor& TapHighlightColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->tap_highlight_color_;
    }

    void SetTapHighlightColor(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->tap_highlight_color_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_100_percent_data_,
                access_.rare_inherited_usage_less_than_100_percent_data_)
                ->tap_highlight_color_
                = v;
    }

    void SetTapHighlightColor(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->tap_highlight_color_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_100_percent_data_,
                access_.rare_inherited_usage_less_than_100_percent_data_)
                ->tap_highlight_color_
                = std::move(v);
    }

    inline void ResetTapHighlightColor()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_100_percent_data_,
            access_.rare_inherited_usage_less_than_100_percent_data_)
            ->tap_highlight_color_
            = StyleColor(LayoutTheme::TapHighlightColor());
    }

    // text-align
    ETextAlign GetTextAlign() const
    {
        return static_cast<ETextAlign>(data_.text_align_);
    }

    void SetTextAlign(ETextAlign v)
    {
        data_.text_align_ = static_cast<unsigned>(v);
    }

    inline void ResetTextAlign()
    {
        data_.text_align_ = static_cast<unsigned>(ETextAlign::kStart);
    }

    // text-align-last
    ETextAlignLast TextAlignLast() const
    {
        return static_cast<ETextAlignLast>(rare_inherited_usage_less_than_64_percent_data_->text_align_last_);
    }

    void SetTextAlignLast(ETextAlignLast v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_align_last_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_align_last_
                = static_cast<unsigned>(v);
    }

    inline void ResetTextAlignLast()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_align_last_
            = static_cast<unsigned>(ETextAlignLast::kAuto);
    }

    // text-anchor
    ETextAnchor TextAnchor() const
    {
        return static_cast<ETextAnchor>(svg_data_->text_anchor_);
    }

    void SetTextAnchor(ETextAnchor v)
    {
        if (!(svg_data_->text_anchor_ == static_cast<unsigned>(v)))
            Access(svg_data_, access_.svg_data_)->text_anchor_ = static_cast<unsigned>(v);
    }

    inline void ResetTextAnchor()
    {
        Access(svg_data_, access_.svg_data_)->text_anchor_ = static_cast<unsigned>(ETextAnchor::kStart);
    }

    // TextAutosizingMultiplier
    float TextAutosizingMultiplier() const
    {
        return inherited_data_->text_autosizing_multiplier_;
    }

    inline void ResetTextAutosizingMultiplier()
    {
        Access(inherited_data_, access_.inherited_data_)->text_autosizing_multiplier_ = 1.0;
    }

    // text-autospace
    ETextAutospace TextAutospace() const
    {
        return static_cast<ETextAutospace>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_autospace_);
    }

    void SetTextAutospace(ETextAutospace v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_autospace_
                == static_cast<unsigned>(v)))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->text_autospace_
                = static_cast<unsigned>(v);
    }

    inline void ResetTextAutospace()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->text_autospace_
            = static_cast<unsigned>(ETextAutospace::kNormal);
    }

    // text-box-edge
    TextBoxEdge GetTextBoxEdge() const
    {
        return static_cast<TextBoxEdge>(rare_inherited_usage_less_than_64_percent_data_->text_box_edge_);
    }

    void SetTextBoxEdge(TextBoxEdge v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_box_edge_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_box_edge_
                = static_cast<unsigned>(v);
    }

    inline void ResetTextBoxEdge()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_box_edge_
            = static_cast<unsigned>(TextBoxEdge());
    }

    // text-box-trim
    ETextBoxTrim TextBoxTrim() const
    {
        return static_cast<ETextBoxTrim>(box_data_->text_box_trim_);
    }

    void SetTextBoxTrim(ETextBoxTrim v)
    {
        if (!(box_data_->text_box_trim_ == static_cast<unsigned>(v)))
            Access(box_data_, access_.box_data_)->text_box_trim_ = static_cast<unsigned>(v);
    }

    inline void ResetTextBoxTrim()
    {
        Access(box_data_, access_.box_data_)->text_box_trim_ = static_cast<unsigned>(ETextBoxTrim::kNone);
    }

    // text-combine-upright
    ETextCombine TextCombine() const
    {
        return static_cast<ETextCombine>(rare_inherited_usage_less_than_64_percent_data_->text_combine_);
    }

    void SetTextCombine(ETextCombine v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_combine_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_combine_
                = static_cast<unsigned>(v);
    }

    inline void ResetTextCombine()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_combine_
            = static_cast<unsigned>(ETextCombine::kNone);
    }

    // text-decoration-color

    void SetTextDecorationColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->text_decoration_color_
                = v;
    }

    void SetTextDecorationColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_color_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->text_decoration_color_
                = std::move(v);
    }

    inline void ResetTextDecorationColor()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->text_decoration_color_
            = StyleColor::CurrentColor();
    }

    // text-decoration-line
    TextDecorationLine GetTextDecorationLine() const
    {
        return static_cast<TextDecorationLine>(visual_data_->text_decoration_line_);
    }

    void SetTextDecorationLine(TextDecorationLine v)
    {
        if (!(visual_data_->text_decoration_line_ == static_cast<unsigned>(v)))
            Access(visual_data_, access_.visual_data_)->text_decoration_line_ = static_cast<unsigned>(v);
    }

    inline void ResetTextDecorationLine()
    {
        Access(visual_data_, access_.visual_data_)->text_decoration_line_ = static_cast<unsigned>(TextDecorationLine::kNone);
    }

    // text-decoration-skip-ink
    ETextDecorationSkipInk TextDecorationSkipInk() const
    {
        return static_cast<ETextDecorationSkipInk>(rare_inherited_usage_less_than_64_percent_data_->text_decoration_skip_ink_);
    }

    void SetTextDecorationSkipInk(ETextDecorationSkipInk v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_decoration_skip_ink_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_decoration_skip_ink_
                = static_cast<unsigned>(v);
    }

    inline void ResetTextDecorationSkipInk()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_decoration_skip_ink_
            = static_cast<unsigned>(ETextDecorationSkipInk::kAuto);
    }

    // text-decoration-style
    ETextDecorationStyle TextDecorationStyle() const
    {
        return static_cast<ETextDecorationStyle>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                     ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_style_);
    }

    void SetTextDecorationStyle(ETextDecorationStyle v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_style_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->text_decoration_style_
                = static_cast<unsigned>(v);
    }

    inline void ResetTextDecorationStyle()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->text_decoration_style_
            = static_cast<unsigned>(ETextDecorationStyle::kSolid);
    }

    // text-decoration-thickness
    const TextDecorationThickness& GetTextDecorationThickness() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_thickness_;
    }

    void SetTextDecorationThickness(const TextDecorationThickness& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_thickness_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->text_decoration_thickness_
                = v;
    }

    void SetTextDecorationThickness(TextDecorationThickness&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_thickness_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->text_decoration_thickness_
                = std::move(v);
    }

    inline void ResetTextDecorationThickness()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->text_decoration_thickness_
            = TextDecorationThickness(Length::Auto());
    }

    // text-emphasis-color

    void SetTextEmphasisColor(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_emphasis_color_ = v;
    }

    void SetTextEmphasisColor(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_emphasis_color_
                = std::move(v);
    }

    inline void ResetTextEmphasisColor()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_emphasis_color_
            = StyleColor::CurrentColor();
    }

    // TextEmphasisCustomMark
    const AtomicString& TextEmphasisCustomMark() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_;
    }

    void SetTextEmphasisCustomMark(const AtomicString& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->text_emphasis_custom_mark_
                = v;
    }

    void SetTextEmphasisCustomMark(AtomicString&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->text_emphasis_custom_mark_
                = std::move(v);
    }

    inline void ResetTextEmphasisCustomMark()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->text_emphasis_custom_mark_
            = AtomicString();
    }

    // TextEmphasisFill
    TextEmphasisFill GetTextEmphasisFill() const
    {
        return static_cast<TextEmphasisFill>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_fill_);
    }

    void SetTextEmphasisFill(TextEmphasisFill v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_fill_
                == static_cast<unsigned>(v)))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->text_emphasis_fill_
                = static_cast<unsigned>(v);
    }

    inline void ResetTextEmphasisFill()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->text_emphasis_fill_
            = static_cast<unsigned>(TextEmphasisFill::kFilled);
    }

    // TextEmphasisMark

    void SetTextEmphasisMark(TextEmphasisMark v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_mark_
                == static_cast<unsigned>(v)))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->text_emphasis_mark_
                = static_cast<unsigned>(v);
    }

    inline void ResetTextEmphasisMark()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->text_emphasis_mark_
            = static_cast<unsigned>(TextEmphasisMark::kNone);
    }

    // text-emphasis-position
    TextEmphasisPosition GetTextEmphasisPosition() const
    {
        return static_cast<TextEmphasisPosition>(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_position_);
    }

    void SetTextEmphasisPosition(TextEmphasisPosition v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_position_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_emphasis_position_
                = static_cast<unsigned>(v);
    }

    inline void ResetTextEmphasisPosition()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_emphasis_position_
            = static_cast<unsigned>(TextEmphasisPosition::kOverRight);
    }

    // -webkit-text-fill-color

    void SetTextFillColor(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_fill_color_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_fill_color_ = v;
    }

    void SetTextFillColor(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_fill_color_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_fill_color_ = std::move(v);
    }

    inline void ResetTextFillColor()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_fill_color_
            = StyleColor::CurrentColor();
    }

    // text-indent
    const Length& TextIndent() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->text_indent_;
    }

    void SetTextIndent(const Length& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_indent_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_indent_ = v;
    }

    void SetTextIndent(Length&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_indent_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_indent_ = std::move(v);
    }

    inline void ResetTextIndent()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_indent_ = Length::Fixed();
    }

    // text-orientation
    ETextOrientation GetTextOrientation() const
    {
        return static_cast<ETextOrientation>(rare_inherited_usage_less_than_64_percent_data_->text_orientation_);
    }

    void SetTextOrientation(ETextOrientation v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_orientation_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_orientation_
                = static_cast<unsigned>(v);
    }

    inline void ResetTextOrientation()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_orientation_
            = static_cast<unsigned>(ETextOrientation::kMixed);
    }

    // text-overflow
    ETextOverflow TextOverflow() const
    {
        return static_cast<ETextOverflow>(rare_non_inherited_usage_less_than_14_percent_data_->text_overflow_);
    }

    void SetTextOverflow(ETextOverflow v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->text_overflow_ == static_cast<unsigned>(v)))
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->text_overflow_
                = static_cast<unsigned>(v);
    }

    inline void ResetTextOverflow()
    {
        Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->text_overflow_
            = static_cast<unsigned>(ETextOverflow::kClip);
    }

    // -webkit-text-security
    ETextSecurity TextSecurity() const
    {
        return static_cast<ETextSecurity>(rare_inherited_usage_less_than_64_percent_data_->text_security_);
    }

    void SetTextSecurity(ETextSecurity v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_security_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_security_
                = static_cast<unsigned>(v);
    }

    inline void ResetTextSecurity()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_security_
            = static_cast<unsigned>(ETextSecurity::kNone);
    }

    // text-shadow
    ShadowList* TextShadow() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->text_shadow_.Get();
    }

    void SetTextShadow(Member<ShadowList> v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_shadow_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_shadow_ = std::move(v);
    }

    // text-size-adjust
    const TextSizeAdjust& GetTextSizeAdjust() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_;
    }

    void SetTextSizeAdjust(const TextSizeAdjust& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_size_adjust_ = v;
    }

    void SetTextSizeAdjust(TextSizeAdjust&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_size_adjust_ = std::move(v);
    }

    inline void ResetTextSizeAdjust()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_size_adjust_
            = TextSizeAdjust::AdjustAuto();
    }

    // -webkit-text-stroke-color

    void SetTextStrokeColor(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_stroke_color_ = v;
    }

    void SetTextStrokeColor(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_stroke_color_ = std::move(v);
    }

    inline void ResetTextStrokeColor()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_stroke_color_
            = StyleColor::CurrentColor();
    }

    // -webkit-text-stroke-width
    float TextStrokeWidth() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->text_stroke_width_;
    }

    void SetTextStrokeWidth(float v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_stroke_width_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_stroke_width_ = v;
    }

    inline void ResetTextStrokeWidth()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_stroke_width_ = 0;
    }

    // text-transform
    ETextTransform TextTransform() const
    {
        return static_cast<ETextTransform>(data_.text_transform_);
    }

    void SetTextTransform(ETextTransform v)
    {
        data_.text_transform_ = static_cast<unsigned>(v);
    }

    inline void ResetTextTransform()
    {
        data_.text_transform_ = static_cast<unsigned>(ETextTransform::kNone);
    }

    // text-transform
    bool TextTransformIsInherited() const
    {
        return static_cast<bool>(data_.text_transform_is_inherited_);
    }

    void SetTextTransformIsInherited(bool v)
    {
        data_.text_transform_is_inherited_ = static_cast<unsigned>(v);
    }

    inline void ResetTextTransformIsInherited()
    {
        data_.text_transform_is_inherited_ = static_cast<unsigned>(true);
    }

    // text-underline-offset
    const Length& TextUnderlineOffset() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_;
    }

    void SetTextUnderlineOffset(const Length& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_100_percent_data_,
                access_.rare_inherited_usage_less_than_100_percent_data_)
                ->text_underline_offset_
                = v;
    }

    void SetTextUnderlineOffset(Length&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_100_percent_data_,
                access_.rare_inherited_usage_less_than_100_percent_data_)
                ->text_underline_offset_
                = std::move(v);
    }

    inline void ResetTextUnderlineOffset()
    {
        Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                   ->rare_inherited_usage_less_than_100_percent_data_,
            access_.rare_inherited_usage_less_than_100_percent_data_)
            ->text_underline_offset_
            = Length();
    }

    // text-underline-position
    TextUnderlinePosition GetTextUnderlinePosition() const
    {
        return static_cast<TextUnderlinePosition>(rare_inherited_usage_less_than_64_percent_data_->text_underline_position_);
    }

    void SetTextUnderlinePosition(TextUnderlinePosition v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_underline_position_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_underline_position_
                = static_cast<unsigned>(v);
    }

    inline void ResetTextUnderlinePosition()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_underline_position_
            = static_cast<unsigned>(TextUnderlinePosition::kAuto);
    }

    // text-wrap-mode
    TextWrapMode GetTextWrapMode() const
    {
        return static_cast<TextWrapMode>(data_.text_wrap_mode_);
    }

    void SetTextWrapMode(TextWrapMode v)
    {
        data_.text_wrap_mode_ = static_cast<unsigned>(v);
    }

    inline void ResetTextWrapMode()
    {
        data_.text_wrap_mode_ = static_cast<unsigned>(TextWrapMode::kWrap);
    }

    // text-wrap-style
    TextWrapStyle GetTextWrapStyle() const
    {
        return static_cast<TextWrapStyle>(data_.text_wrap_style_);
    }

    void SetTextWrapStyle(TextWrapStyle v)
    {
        data_.text_wrap_style_ = static_cast<unsigned>(v);
    }

    inline void ResetTextWrapStyle()
    {
        data_.text_wrap_style_ = static_cast<unsigned>(TextWrapStyle::kAuto);
    }

    // timeline-scope
    const Member<ScopedCSSNameList>& TimelineScope() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->timeline_scope_;
    }

    void SetTimelineScope(const Member<ScopedCSSNameList>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->timeline_scope_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->timeline_data_,
                access_.timeline_data_)
                ->timeline_scope_
                = v;
    }

    void SetTimelineScope(Member<ScopedCSSNameList>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->timeline_scope_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->timeline_data_,
                access_.timeline_data_)
                ->timeline_scope_
                = std::move(v);
    }

    inline void ResetTimelineScope()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->timeline_data_,
            access_.timeline_data_)
            ->timeline_scope_
            = nullptr;
    }

    // top
    const Length& Top() const
    {
        return surround_data_->top_;
    }

    void SetTop(const Length& v)
    {
        if (!(surround_data_->top_ == v))
            Access(surround_data_, access_.surround_data_)->top_ = v;
    }

    void SetTop(Length&& v)
    {
        if (!(surround_data_->top_ == v))
            Access(surround_data_, access_.surround_data_)->top_ = std::move(v);
    }

    inline void ResetTop()
    {
        Access(surround_data_, access_.surround_data_)->top_ = Length();
    }

    // touch-action
    TouchAction GetTouchAction() const
    {
        return static_cast<TouchAction>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->touch_action_);
    }

    void SetTouchAction(TouchAction v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->touch_action_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->touch_action_
                = static_cast<unsigned>(v);
    }

    inline void ResetTouchAction()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->touch_action_
            = static_cast<unsigned>(TouchAction::kAuto);
    }

    // transform
    const TransformOperations& Transform() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->transform_;
    }

    void SetTransform(const TransformOperations& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->transform_ == v))
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->transform_ = v;
    }

    void SetTransform(TransformOperations&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->transform_ == v))
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->transform_ = std::move(v);
    }

    inline void ResetTransform()
    {
        Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->transform_
            = EmptyTransformOperations();
    }

    // transform-box
    ETransformBox TransformBox() const
    {
        return static_cast<ETransformBox>(data_.transform_box_);
    }

    void SetTransformBox(ETransformBox v)
    {
        data_.transform_box_ = static_cast<unsigned>(v);
    }

    inline void ResetTransformBox()
    {
        data_.transform_box_ = static_cast<unsigned>(ETransformBox::kViewBox);
    }

    // transform-origin
    const TransformOrigin& GetTransformOrigin() const
    {
        return svg_data_->transform_origin_;
    }

    void SetTransformOrigin(const TransformOrigin& v)
    {
        if (!(svg_data_->transform_origin_ == v))
            Access(svg_data_, access_.svg_data_)->transform_origin_ = v;
    }

    void SetTransformOrigin(TransformOrigin&& v)
    {
        if (!(svg_data_->transform_origin_ == v))
            Access(svg_data_, access_.svg_data_)->transform_origin_ = std::move(v);
    }

    inline void ResetTransformOrigin()
    {
        Access(svg_data_, access_.svg_data_)->transform_origin_ = TransformOrigin(Length::Percent(50.0), Length::Percent(50.0), 0);
    }

    // transform-style
    ETransformStyle3D TransformStyle3D() const
    {
        return static_cast<ETransformStyle3D>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                  ->rare_non_inherited_usage_less_than_100_percent_data_->transform_style_3d_);
    }

    void SetTransformStyle3D(ETransformStyle3D v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->transform_style_3d_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->transform_style_3d_
                = static_cast<unsigned>(v);
    }

    inline void ResetTransformStyle3D()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->transform_style_3d_
            = static_cast<unsigned>(ETransformStyle3D::kFlat);
    }

    // Transitions

    inline void ResetTransitions()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->transitions_
            = nullptr;
    }

    // translate
    TranslateTransformOperation* Translate() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->translate_.Get();
    }

    void SetTranslate(Member<TranslateTransformOperation> v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->translate_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->translate_
                = std::move(v);
    }

    // UAShadowHostData
    StyleUAShadowHostData* UAShadowHostData() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ua_shadow_host_data_.get();
    }

    void SetUAShadowHostData(std::unique_ptr<StyleUAShadowHostData> v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->ua_shadow_host_data_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->ua_shadow_host_data_
                = std::move(v);
    }

    // unicode-bidi
    UnicodeBidi GetUnicodeBidi() const
    {
        return static_cast<UnicodeBidi>(data_.unicode_bidi_);
    }

    void SetUnicodeBidi(UnicodeBidi v)
    {
        data_.unicode_bidi_ = static_cast<unsigned>(v);
    }

    inline void ResetUnicodeBidi()
    {
        data_.unicode_bidi_ = static_cast<unsigned>(UnicodeBidi::kNormal);
    }

    // -webkit-user-drag
    EUserDrag UserDrag() const
    {
        return static_cast<EUserDrag>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                          ->rare_non_inherited_usage_less_than_100_percent_data_->user_drag_);
    }

    void SetUserDrag(EUserDrag v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->user_drag_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->user_drag_
                = static_cast<unsigned>(v);
    }

    inline void ResetUserDrag()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
                   access_.rare_non_inherited_usage_less_than_22_percent_data_)
                   ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->user_drag_
            = static_cast<unsigned>(EUserDrag::kAuto);
    }

    // -webkit-user-modify

    void SetUserModify(EUserModify v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->user_modify_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->user_modify_
                = static_cast<unsigned>(v);
    }

    inline void ResetUserModify()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->user_modify_
            = static_cast<unsigned>(EUserModify::kReadOnly);
    }

    // user-select

    void SetUserSelect(EUserSelect v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->user_select_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->user_select_
                = static_cast<unsigned>(v);
    }

    inline void ResetUserSelect()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->user_select_
            = static_cast<unsigned>(EUserSelect::kAuto);
    }

    // vector-effect
    EVectorEffect VectorEffect() const
    {
        return static_cast<EVectorEffect>(svg_data_->vector_effect_);
    }

    void SetVectorEffect(EVectorEffect v)
    {
        if (!(svg_data_->vector_effect_ == static_cast<unsigned>(v)))
            Access(svg_data_, access_.svg_data_)->vector_effect_ = static_cast<unsigned>(v);
    }

    inline void ResetVectorEffect()
    {
        Access(svg_data_, access_.svg_data_)->vector_effect_ = static_cast<unsigned>(EVectorEffect::kNone);
    }

    // VerticalAlign

    inline void ResetVerticalAlign()
    {
        data_.vertical_align_ = static_cast<unsigned>(static_cast<unsigned>(EVerticalAlign::kBaseline));
    }

    // VerticalAlignLength
    const Length& GetVerticalAlignLength() const
    {
        return box_data_->vertical_align_length_;
    }

    inline void ResetVerticalAlignLength()
    {
        Access(box_data_, access_.box_data_)->vertical_align_length_ = Length();
    }

    // -webkit-border-vertical-spacing
    short VerticalBorderSpacing() const
    {
        return inherited_data_->vertical_border_spacing_;
    }

    void SetVerticalBorderSpacing(short v)
    {
        if (!(inherited_data_->vertical_border_spacing_ == v))
            Access(inherited_data_, access_.inherited_data_)->vertical_border_spacing_ = v;
    }

    inline void ResetVerticalBorderSpacing()
    {
        Access(inherited_data_, access_.inherited_data_)->vertical_border_spacing_ = 0;
    }

    // view-timeline-axis
    const Vector<TimelineAxis>& ViewTimelineAxis() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
            ->view_timeline_axis_;
    }

    void SetViewTimelineAxis(const Vector<TimelineAxis>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_axis_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->timeline_data_,
                access_.timeline_data_)
                ->view_timeline_axis_
                = v;
    }

    void SetViewTimelineAxis(Vector<TimelineAxis>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_axis_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->timeline_data_,
                access_.timeline_data_)
                ->view_timeline_axis_
                = std::move(v);
    }

    inline void ResetViewTimelineAxis()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->timeline_data_,
            access_.timeline_data_)
            ->view_timeline_axis_
            = Vector<TimelineAxis>();
    }

    // view-timeline-inset
    const Vector<TimelineInset>& ViewTimelineInset() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
            ->view_timeline_inset_;
    }

    void SetViewTimelineInset(const Vector<TimelineInset>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_inset_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->timeline_data_,
                access_.timeline_data_)
                ->view_timeline_inset_
                = v;
    }

    void SetViewTimelineInset(Vector<TimelineInset>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_inset_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->timeline_data_,
                access_.timeline_data_)
                ->view_timeline_inset_
                = std::move(v);
    }

    inline void ResetViewTimelineInset()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->timeline_data_,
            access_.timeline_data_)
            ->view_timeline_inset_
            = Vector<TimelineInset>();
    }

    // view-timeline-name
    const Member<ScopedCSSNameList>& ViewTimelineName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_
            ->view_timeline_name_;
    }

    void SetViewTimelineName(const Member<ScopedCSSNameList>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_name_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->timeline_data_,
                access_.timeline_data_)
                ->view_timeline_name_
                = v;
    }

    void SetViewTimelineName(Member<ScopedCSSNameList>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_name_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->timeline_data_,
                access_.timeline_data_)
                ->view_timeline_name_
                = std::move(v);
    }

    inline void ResetViewTimelineName()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->timeline_data_,
            access_.timeline_data_)
            ->view_timeline_name_
            = nullptr;
    }

    // view-transition-capture-mode
    StyleViewTransitionCaptureMode ViewTransitionCaptureMode() const
    {
        return static_cast<StyleViewTransitionCaptureMode>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_capture_mode_);
    }

    void SetViewTransitionCaptureMode(StyleViewTransitionCaptureMode v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_capture_mode_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->view_transition_capture_mode_
                = static_cast<unsigned>(v);
    }

    inline void ResetViewTransitionCaptureMode()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->view_transition_capture_mode_
            = static_cast<unsigned>(StyleViewTransitionCaptureMode::kLayered);
    }

    // view-transition-class
    const Member<ScopedCSSNameList>& ViewTransitionClass() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_class_;
    }

    void SetViewTransitionClass(const Member<ScopedCSSNameList>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_class_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->view_transition_class_
                = v;
    }

    void SetViewTransitionClass(Member<ScopedCSSNameList>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_class_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->view_transition_class_
                = std::move(v);
    }

    inline void ResetViewTransitionClass()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->view_transition_class_
            = nullptr;
    }

    // view-transition-group
    const StyleViewTransitionGroup& ViewTransitionGroup() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_group_;
    }

    void SetViewTransitionGroup(const StyleViewTransitionGroup& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_group_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->view_transition_group_
                = v;
    }

    void SetViewTransitionGroup(StyleViewTransitionGroup&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_group_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->view_transition_group_
                = std::move(v);
    }

    inline void ResetViewTransitionGroup()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->view_transition_group_
            = StyleViewTransitionGroup::Normal();
    }

    // view-transition-name
    const Member<StyleViewTransitionName>& ViewTransitionName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_name_;
    }

    void SetViewTransitionName(const Member<StyleViewTransitionName>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_name_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->view_transition_name_
                = v;
    }

    void SetViewTransitionName(Member<StyleViewTransitionName>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->view_transition_name_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->view_transition_name_
                = std::move(v);
    }

    inline void ResetViewTransitionName()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->view_transition_name_
            = nullptr;
    }

    // ViewportUnitFlags
    unsigned ViewportUnitFlags() const
    {
        return static_cast<unsigned>(data_.viewport_unit_flags_);
    }

    void SetViewportUnitFlags(unsigned v)
    {
        data_.viewport_unit_flags_ = static_cast<unsigned>(v);
    }

    inline void ResetViewportUnitFlags()
    {
        data_.viewport_unit_flags_ = static_cast<unsigned>(0);
    }

    // visibility
    EVisibility Visibility() const
    {
        return static_cast<EVisibility>(data_.visibility_);
    }

    void SetVisibility(EVisibility v)
    {
        data_.visibility_ = static_cast<unsigned>(v);
    }

    inline void ResetVisibility()
    {
        data_.visibility_ = static_cast<unsigned>(EVisibility::kVisible);
    }

    // visibility
    bool VisibilityIsInherited() const
    {
        return static_cast<bool>(data_.visibility_is_inherited_);
    }

    void SetVisibilityIsInherited(bool v)
    {
        data_.visibility_is_inherited_ = static_cast<unsigned>(v);
    }

    inline void ResetVisibilityIsInherited()
    {
        data_.visibility_is_inherited_ = static_cast<unsigned>(true);
    }

    // -webkit-line-clamp
    int WebkitLineClamp() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->webkit_line_clamp_;
    }

    void SetWebkitLineClamp(int v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->webkit_line_clamp_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->webkit_line_clamp_
                = v;
    }

    inline void ResetWebkitLineClamp()
    {
        Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                   ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->webkit_line_clamp_
            = 0;
    }

    // white-space-collapse
    WhiteSpaceCollapse GetWhiteSpaceCollapse() const
    {
        return static_cast<WhiteSpaceCollapse>(data_.white_space_collapse_);
    }

    void SetWhiteSpaceCollapse(WhiteSpaceCollapse v)
    {
        data_.white_space_collapse_ = static_cast<unsigned>(v);
    }

    inline void ResetWhiteSpaceCollapse()
    {
        data_.white_space_collapse_ = static_cast<unsigned>(WhiteSpaceCollapse::kCollapse);
    }

    // widows
    short Widows() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->widows_;
    }

    inline void ResetWidows()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->widows_ = 2;
    }

    // width
    const Length& Width() const
    {
        return box_data_->width_;
    }

    void SetWidth(const Length& v)
    {
        if (!(box_data_->width_ == v))
            Access(box_data_, access_.box_data_)->width_ = v;
    }

    void SetWidth(Length&& v)
    {
        if (!(box_data_->width_ == v))
            Access(box_data_, access_.box_data_)->width_ = std::move(v);
    }

    inline void ResetWidth()
    {
        Access(box_data_, access_.box_data_)->width_ = Length();
    }

    // WillChangeContents
    bool WillChangeContents() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                                     ->will_change_contents_);
    }

    void SetWillChangeContents(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                    ->will_change_contents_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->will_change_data_,
                access_.will_change_data_)
                ->will_change_contents_
                = static_cast<unsigned>(v);
    }

    inline void ResetWillChangeContents()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->will_change_data_,
            access_.will_change_data_)
            ->will_change_contents_
            = static_cast<unsigned>(false);
    }

    // WillChangeProperties
    const Vector<CSSPropertyID>& WillChangeProperties() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
            ->will_change_properties_;
    }

    void SetWillChangeProperties(const Vector<CSSPropertyID>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                    ->will_change_properties_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->will_change_data_,
                access_.will_change_data_)
                ->will_change_properties_
                = v;
    }

    void SetWillChangeProperties(Vector<CSSPropertyID>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                    ->will_change_properties_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->will_change_data_,
                access_.will_change_data_)
                ->will_change_properties_
                = std::move(v);
    }

    inline void ResetWillChangeProperties()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->will_change_data_,
            access_.will_change_data_)
            ->will_change_properties_
            = Vector<CSSPropertyID>();
    }

    // WillChangeScrollPosition
    bool WillChangeScrollPosition() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                                     ->will_change_scroll_position_);
    }

    void SetWillChangeScrollPosition(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_
                    ->will_change_scroll_position_
                == static_cast<unsigned>(v)))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->will_change_data_,
                access_.will_change_data_)
                ->will_change_scroll_position_
                = static_cast<unsigned>(v);
    }

    inline void ResetWillChangeScrollPosition()
    {
        Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                   access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                   ->will_change_data_,
            access_.will_change_data_)
            ->will_change_scroll_position_
            = static_cast<unsigned>(false);
    }

    // word-break
    EWordBreak WordBreak() const
    {
        return static_cast<EWordBreak>(rare_inherited_usage_less_than_64_percent_data_->word_break_);
    }

    void SetWordBreak(EWordBreak v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->word_break_ == static_cast<unsigned>(v)))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->word_break_
                = static_cast<unsigned>(v);
    }

    inline void ResetWordBreak()
    {
        Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->word_break_
            = static_cast<unsigned>(EWordBreak::kNormal);
    }

    // writing-mode
    WritingMode GetWritingMode() const
    {
        return static_cast<WritingMode>(data_.writing_mode_);
    }

    void SetWritingMode(WritingMode v)
    {
        data_.writing_mode_ = static_cast<unsigned>(v);
    }

    inline void ResetWritingMode()
    {
        data_.writing_mode_ = static_cast<unsigned>(WritingMode::kHorizontalTb);
    }

    // x
    const Length& X() const
    {
        return svg_data_->geometry_data_->x_;
    }

    void SetX(const Length& v)
    {
        if (!(svg_data_->geometry_data_->x_ == v))
            Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->x_ = v;
    }

    void SetX(Length&& v)
    {
        if (!(svg_data_->geometry_data_->x_ == v))
            Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->x_ = std::move(v);
    }

    inline void ResetX()
    {
        Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->x_ = Length::Fixed();
    }

    // y
    const Length& Y() const
    {
        return svg_data_->geometry_data_->y_;
    }

    void SetY(const Length& v)
    {
        if (!(svg_data_->geometry_data_->y_ == v))
            Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->y_ = v;
    }

    void SetY(Length&& v)
    {
        if (!(svg_data_->geometry_data_->y_ == v))
            Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->y_ = std::move(v);
    }

    inline void ResetY()
    {
        Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->y_ = Length::Fixed();
    }

    // z-index
    int ZIndex() const
    {
        return box_data_->z_index_;
    }

    inline void ResetZIndex()
    {
        Access(box_data_, access_.box_data_)->z_index_ = 0;
    }

    // zoom
    float Zoom() const
    {
        return visual_data_->zoom_;
    }

    void SetZoom(float v)
    {
        if (!(visual_data_->zoom_ == v))
            Access(visual_data_, access_.visual_data_)->zoom_ = v;
    }

    inline void ResetZoom()
    {
        Access(visual_data_, access_.visual_data_)->zoom_ = 1.0;
    }

protected:
    ComputedStyleBuilderBase() = delete;

    explicit ComputedStyleBuilderBase(const ComputedStyleBase&);

    ComputedStyleBuilderBase(const ComputedStyleBase& source_for_noninherited, const ComputedStyleBase& parent_style);

    void PropagateIndependentInheritedProperties(const ComputedStyleBase& parent_style);

    // accent-color
    const StyleAutoColor& AccentColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->accent_color_;
    }

    StyleAutoColor& MutableAccentColorInternal()
    {
        return Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_100_percent_data_,
            access_.rare_inherited_usage_less_than_100_percent_data_)
            ->accent_color_;
    }

    // AffectedByActive

    // AffectedByCSSFunction

    // AffectedByDrag

    // AffectedByFocusWithin

    // AffectedByHover

    // align-content

    StyleContentAlignmentData& MutableAlignContentInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->align_content_;
    }

    // -internal-align-content-block

    bool MutableAlignContentBlockCenterInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->align_content_block_center_);
    }

    // align-items

    StyleSelfAlignmentData& MutableAlignItemsInternal()
    {
        return Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->align_items_;
    }

    // align-self

    StyleSelfAlignmentData& MutableAlignSelfInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->align_self_;
    }

    // alignment-baseline

    EAlignmentBaseline MutableAlignmentBaselineInternal()
    {
        return static_cast<EAlignmentBaseline>(Access(svg_data_, access_.svg_data_)->alignment_baseline_);
    }

    // AnchorCenterOffset

    std::optional<PhysicalOffset>& MutableAnchorCenterOffsetInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->anchor_center_offset_;
    }

    // anchor-name

    Member<ScopedCSSNameList>& MutableAnchorNameInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->anchor_name_;
    }

    // anchor-scope

    StyleAnchorScope& MutableAnchorScopeInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->anchor_scope_;
    }

    // Animations
    const std::unique_ptr<CSSAnimationData>& AnimationsInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->animations_;
    }

    void SetAnimationsInternal(std::unique_ptr<CSSAnimationData>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->animations_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->animations_
                = std::move(v);
    }

    std::unique_ptr<CSSAnimationData>& MutableAnimationsInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->animations_;
    }

    // appearance
    ControlPart Appearance() const
    {
        return static_cast<ControlPart>(rare_non_inherited_usage_less_than_14_percent_data_->appearance_);
    }

    ControlPart MutableAppearanceInternal()
    {
        return static_cast<ControlPart>(
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->appearance_);
    }

    // aspect-ratio

    StyleAspectRatio& MutableAspectRatioInternal()
    {
        return Access(surround_data_, access_.surround_data_)->aspect_ratio_;
    }

    // backdrop-filter

    FilterOperations& MutableBackdropFilterInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->backdrop_filter_;
    }

    // backface-visibility

    EBackfaceVisibility MutableBackfaceVisibilityInternal()
    {
        return static_cast<EBackfaceVisibility>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->backface_visibility_);
    }

    // Background
    const FillLayer& BackgroundInternal() const
    {
        return background_data_->background_;
    }

    void SetBackgroundInternal(const FillLayer& v)
    {
        if (!(background_data_->background_ == v))
            Access(background_data_, access_.background_data_)->background_ = v;
    }

    void SetBackgroundInternal(FillLayer&& v)
    {
        if (!(background_data_->background_ == v))
            Access(background_data_, access_.background_data_)->background_ = std::move(v);
    }

    FillLayer& MutableBackgroundInternal()
    {
        return Access(background_data_, access_.background_data_)->background_;
    }

    // background-color
    const StyleColor& BackgroundColor() const
    {
        return background_data_->background_color_;
    }

    StyleColor& MutableBackgroundColorInternal()
    {
        return Access(background_data_, access_.background_data_)->background_color_;
    }

    // BaseData

    // BaseTextDecorationData
    const scoped_refptr<base::RefCountedData<Vector<AppliedTextDecoration, 1>>>& BaseTextDecorationDataInternal() const
    {
        return visual_data_->base_text_decoration_data_;
    }

    scoped_refptr<base::RefCountedData<Vector<AppliedTextDecoration, 1>>>& MutableBaseTextDecorationDataInternal()
    {
        return Access(visual_data_, access_.visual_data_)->base_text_decoration_data_;
    }

    // baseline-shift

    Length& MutableBaselineShiftInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->baseline_shift_;
    }

    // BaselineShiftType

    EBaselineShiftType MutableBaselineShiftTypeInternal()
    {
        return static_cast<EBaselineShiftType>(Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->baseline_shift_type_);
    }

    // baseline-source

    EBaselineSource MutableBaselineSourceInternal()
    {
        return static_cast<EBaselineSource>(Access(box_data_, access_.box_data_)->baseline_source_);
    }

    // mix-blend-mode

    BlendMode MutableBlendModeInternal()
    {
        return static_cast<BlendMode>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->blend_mode_);
    }

    // border-bottom-color
    const StyleColor& BorderBottomColor() const
    {
        return surround_data_->border_bottom_color_;
    }

    StyleColor& MutableBorderBottomColorInternal()
    {
        return Access(surround_data_, access_.surround_data_)->border_bottom_color_;
    }

    // border-bottom-left-radius

    LengthSize& MutableBorderBottomLeftRadiusInternal()
    {
        return Access(surround_data_, access_.surround_data_)->border_bottom_left_radius_;
    }

    // border-bottom-right-radius

    LengthSize& MutableBorderBottomRightRadiusInternal()
    {
        return Access(surround_data_, access_.surround_data_)->border_bottom_right_radius_;
    }

    // border-bottom-style

    EBorderStyle MutableBorderBottomStyleInternal()
    {
        return static_cast<EBorderStyle>(Access(box_data_, access_.box_data_)->border_bottom_style_);
    }

    // border-bottom-width
    const int& BorderBottomWidthInternal() const
    {
        return box_data_->border_bottom_width_;
    }

    int& MutableBorderBottomWidthInternal()
    {
        return Access(box_data_, access_.box_data_)->border_bottom_width_;
    }

    // border-collapse

    EBorderCollapse MutableBorderCollapseInternal()
    {
        return static_cast<EBorderCollapse>(data_.border_collapse_);
    }

    // border-collapse

    bool MutableBorderCollapseIsInheritedInternal()
    {
        return static_cast<bool>(data_.border_collapse_is_inherited_);
    }

    // border-image

    NinePieceImage& MutableBorderImageInternal()
    {
        return Access(surround_data_, access_.surround_data_)->border_image_;
    }

    // border-left-color
    const StyleColor& BorderLeftColor() const
    {
        return surround_data_->border_left_color_;
    }

    StyleColor& MutableBorderLeftColorInternal()
    {
        return Access(surround_data_, access_.surround_data_)->border_left_color_;
    }

    // border-left-style

    EBorderStyle MutableBorderLeftStyleInternal()
    {
        return static_cast<EBorderStyle>(Access(box_data_, access_.box_data_)->border_left_style_);
    }

    // border-left-width
    const int& BorderLeftWidthInternal() const
    {
        return box_data_->border_left_width_;
    }

    int& MutableBorderLeftWidthInternal()
    {
        return Access(box_data_, access_.box_data_)->border_left_width_;
    }

    // border-right-color
    const StyleColor& BorderRightColor() const
    {
        return surround_data_->border_right_color_;
    }

    StyleColor& MutableBorderRightColorInternal()
    {
        return Access(surround_data_, access_.surround_data_)->border_right_color_;
    }

    // border-right-style

    EBorderStyle MutableBorderRightStyleInternal()
    {
        return static_cast<EBorderStyle>(Access(box_data_, access_.box_data_)->border_right_style_);
    }

    // border-right-width
    const int& BorderRightWidthInternal() const
    {
        return box_data_->border_right_width_;
    }

    int& MutableBorderRightWidthInternal()
    {
        return Access(box_data_, access_.box_data_)->border_right_width_;
    }

    // border-top-color
    const StyleColor& BorderTopColor() const
    {
        return surround_data_->border_top_color_;
    }

    StyleColor& MutableBorderTopColorInternal()
    {
        return Access(surround_data_, access_.surround_data_)->border_top_color_;
    }

    // border-top-left-radius

    LengthSize& MutableBorderTopLeftRadiusInternal()
    {
        return Access(surround_data_, access_.surround_data_)->border_top_left_radius_;
    }

    // border-top-right-radius

    LengthSize& MutableBorderTopRightRadiusInternal()
    {
        return Access(surround_data_, access_.surround_data_)->border_top_right_radius_;
    }

    // border-top-style

    EBorderStyle MutableBorderTopStyleInternal()
    {
        return static_cast<EBorderStyle>(Access(box_data_, access_.box_data_)->border_top_style_);
    }

    // border-top-width
    const int& BorderTopWidthInternal() const
    {
        return box_data_->border_top_width_;
    }

    int& MutableBorderTopWidthInternal()
    {
        return Access(box_data_, access_.box_data_)->border_top_width_;
    }

    // bottom

    Length& MutableBottomInternal()
    {
        return Access(surround_data_, access_.surround_data_)->bottom_;
    }

    // -webkit-box-align

    EBoxAlignment MutableBoxAlignInternal()
    {
        return static_cast<EBoxAlignment>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->box_align_);
    }

    // box-decoration-break

    EBoxDecorationBreak MutableBoxDecorationBreakInternal()
    {
        return static_cast<EBoxDecorationBreak>(Access(box_data_, access_.box_data_)->box_decoration_break_);
    }

    // -webkit-box-direction
    EBoxDirection BoxDirection() const
    {
        return static_cast<EBoxDirection>(data_.box_direction_);
    }

    EBoxDirection MutableBoxDirectionInternal()
    {
        return static_cast<EBoxDirection>(data_.box_direction_);
    }

    // -webkit-box-flex

    float MutableBoxFlexInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->box_flex_;
    }

    // -webkit-box-ordinal-group

    void SetBoxOrdinalGroupInternal(unsigned v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->box_ordinal_group_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->box_ordinal_group_
                = v;
    }

    unsigned MutableBoxOrdinalGroupInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->box_ordinal_group_;
    }

    // -webkit-box-orient

    EBoxOrient MutableBoxOrientInternal()
    {
        return static_cast<EBoxOrient>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->box_orient_);
    }

    // -webkit-box-pack

    EBoxPack MutableBoxPackInternal()
    {
        return static_cast<EBoxPack>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->box_pack_);
    }

    // -webkit-box-reflect

    // box-shadow

    // box-sizing

    EBoxSizing MutableBoxSizingInternal()
    {
        return static_cast<EBoxSizing>(data_.box_sizing_);
    }

    // break-after

    EBreakBetween MutableBreakAfterInternal()
    {
        return static_cast<EBreakBetween>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->break_after_);
    }

    // break-before

    EBreakBetween MutableBreakBeforeInternal()
    {
        return static_cast<EBreakBetween>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->break_before_);
    }

    // break-inside

    EBreakInside MutableBreakInsideInternal()
    {
        return static_cast<EBreakInside>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->break_inside_);
    }

    // buffered-rendering

    EBufferedRendering MutableBufferedRenderingInternal()
    {
        return static_cast<EBufferedRendering>(Access(svg_data_, access_.svg_data_)->buffered_rendering_);
    }

    // CallbackSelectors

    void SetCallbackSelectorsInternal(const Vector<String>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->callback_selectors_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->callback_selectors_
                = v;
    }

    void SetCallbackSelectorsInternal(Vector<String>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->callback_selectors_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->callback_selectors_
                = std::move(v);
    }

    Vector<String>& MutableCallbackSelectorsInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->callback_selectors_;
    }

    // CanAffectAnimations

    // stroke-linecap

    LineCap MutableCapStyleInternal()
    {
        return static_cast<LineCap>(Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->cap_style_);
    }

    // caption-side

    ECaptionSide MutableCaptionSideInternal()
    {
        return static_cast<ECaptionSide>(data_.caption_side_);
    }

    // caption-side

    bool MutableCaptionSideIsInheritedInternal()
    {
        return static_cast<bool>(data_.caption_side_is_inherited_);
    }

    // caret-animation

    ECaretAnimation MutableCaretAnimationInternal()
    {
        return static_cast<ECaretAnimation>(data_.caret_animation_);
    }

    // caret-color
    const StyleAutoColor& CaretColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->caret_color_;
    }

    StyleAutoColor& MutableCaretColorInternal()
    {
        return Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->caret_color_;
    }

    // clear
    EClear Clear() const
    {
        return static_cast<EClear>(data_.clear_);
    }

    EClear MutableClearInternal()
    {
        return static_cast<EClear>(data_.clear_);
    }

    // clip

    void SetClipInternal(const LengthBox& v)
    {
        if (!(visual_data_->clip_ == v))
            Access(visual_data_, access_.visual_data_)->clip_ = v;
    }

    void SetClipInternal(LengthBox&& v)
    {
        if (!(visual_data_->clip_ == v))
            Access(visual_data_, access_.visual_data_)->clip_ = std::move(v);
    }

    LengthBox& MutableClipInternal()
    {
        return Access(visual_data_, access_.visual_data_)->clip_;
    }

    // clip-path
    const Member<ClipPathOperation>& ClipPathInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->clip_path_;
    }

    void SetClipPathInternal(Member<ClipPathOperation>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->clip_path_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->clip_path_
                = std::move(v);
    }

    Member<ClipPathOperation>& MutableClipPathInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->clip_path_;
    }

    // clip-rule

    WindRule MutableClipRuleInternal()
    {
        return static_cast<WindRule>(Access(svg_data_, access_.svg_data_)->clip_rule_);
    }

    // color
    const StyleColor& Color() const
    {
        return inherited_data_->color_;
    }

    StyleColor& MutableColorInternal()
    {
        return Access(inherited_data_, access_.inherited_data_)->color_;
    }

    // color-interpolation

    EColorInterpolation MutableColorInterpolationInternal()
    {
        return static_cast<EColorInterpolation>(Access(svg_data_, access_.svg_data_)->color_interpolation_);
    }

    // color-interpolation-filters

    EColorInterpolation MutableColorInterpolationFiltersInternal()
    {
        return static_cast<EColorInterpolation>(Access(svg_data_, access_.svg_data_)->color_interpolation_filters_);
    }

    // ColorIsCurrentColor
    bool ColorIsCurrentColor() const
    {
        return static_cast<bool>(inherited_data_->color_is_current_color_);
    }

    bool MutableColorIsCurrentColorInternal()
    {
        return static_cast<bool>(Access(inherited_data_, access_.inherited_data_)->color_is_current_color_);
    }

    // color
    bool ColorIsInherited() const
    {
        return static_cast<bool>(data_.color_is_inherited_);
    }

    bool MutableColorIsInheritedInternal()
    {
        return static_cast<bool>(data_.color_is_inherited_);
    }

    // color-rendering

    EColorRendering MutableColorRenderingInternal()
    {
        return static_cast<EColorRendering>(Access(svg_data_, access_.svg_data_)->color_rendering_);
    }

    // color-scheme

    Vector<AtomicString>& MutableColorSchemeInternal()
    {
        return Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->color_scheme_;
    }

    // ColorSchemeFlagsIsNormal

    bool MutableColorSchemeFlagsIsNormalInternal()
    {
        return static_cast<bool>(data_.color_scheme_flags_is_normal_);
    }

    // ColorSchemeForced

    bool MutableColorSchemeForcedInternal()
    {
        return static_cast<bool>(data_.color_scheme_forced_);
    }

    // column-count

    void SetColumnCountInternal(unsigned short v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->column_count_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->column_count_
                = v;
    }

    unsigned short MutableColumnCountInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->column_count_;
    }

    // column-fill

    EColumnFill MutableColumnFillInternal()
    {
        return static_cast<EColumnFill>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->column_fill_);
    }

    // column-gap

    std::optional<Length>& MutableColumnGapInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->column_gap_;
    }

    // column-rule-color

    GapDataList<StyleColor>& MutableColumnRuleColorInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->column_rule_color_;
    }

    // column-rule-style

    EBorderStyle MutableColumnRuleStyleInternal()
    {
        return static_cast<EBorderStyle>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->column_rule_style_);
    }

    // column-rule-width
    const int& ColumnRuleWidthInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_width_;
    }

    void SetColumnRuleWidthInternal(const int& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_width_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->column_rule_width_
                = v;
    }

    void SetColumnRuleWidthInternal(int&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_width_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->column_rule_width_
                = std::move(v);
    }

    int& MutableColumnRuleWidthInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->column_rule_width_;
    }

    // column-span

    EColumnSpan MutableColumnSpanInternal()
    {
        return static_cast<EColumnSpan>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->column_span_);
    }

    // column-width

    void SetColumnWidthInternal(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->column_width_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->column_width_
                = v;
    }

    float MutableColumnWidthInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->column_width_;
    }

    // contain

    unsigned MutableContainInternal()
    {
        return static_cast<unsigned>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->contain_);
    }

    // contain-intrinsic-height

    StyleIntrinsicLength& MutableContainIntrinsicHeightInternal()
    {
        return Access(surround_data_, access_.surround_data_)->contain_intrinsic_height_;
    }

    // contain-intrinsic-width

    StyleIntrinsicLength& MutableContainIntrinsicWidthInternal()
    {
        return Access(surround_data_, access_.surround_data_)->contain_intrinsic_width_;
    }

    // container-name

    Member<ScopedCSSNameList>& MutableContainerNameInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->container_name_;
    }

    // container-type

    unsigned MutableContainerTypeInternal()
    {
        return static_cast<unsigned>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->container_type_);
    }

    // content
    const Member<ContentData>& ContentInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->content_;
    }

    Member<ContentData>& MutableContentInternal()
    {
        return Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->content_;
    }

    // content-visibility

    EContentVisibility MutableContentVisibilityInternal()
    {
        return static_cast<EContentVisibility>(data_.content_visibility_);
    }

    // CounterDirectives
    const std::unique_ptr<CounterDirectiveMap>& CounterDirectivesInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->counter_directives_;
    }

    void SetCounterDirectivesInternal(std::unique_ptr<CounterDirectiveMap>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->counter_directives_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->counter_directives_
                = std::move(v);
    }

    std::unique_ptr<CounterDirectiveMap>& MutableCounterDirectivesInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->counter_directives_;
    }

    // CssDominantBaseline

    EDominantBaseline MutableCssDominantBaselineInternal()
    {
        return static_cast<EDominantBaseline>(Access(svg_data_, access_.svg_data_)->css_dominant_baseline_);
    }

    // cursor

    ECursor MutableCursorInternal()
    {
        return static_cast<ECursor>(data_.cursor_);
    }

    // CursorData
    const Member<CursorList>& CursorDataInternal() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->cursor_data_;
    }

    void SetCursorDataInternal(Member<CursorList>&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->cursor_data_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->cursor_data_
                = std::move(v);
    }

    Member<CursorList>& MutableCursorDataInternal()
    {
        return Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->cursor_data_;
    }

    // CustomHighlightNames
    const std::unique_ptr<HashSet<AtomicString>>& CustomHighlightNamesInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->custom_highlight_names_;
    }

    void SetCustomHighlightNamesInternal(std::unique_ptr<HashSet<AtomicString>>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->custom_highlight_names_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->custom_highlight_names_
                = std::move(v);
    }

    std::unique_ptr<HashSet<AtomicString>>& MutableCustomHighlightNamesInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->custom_highlight_names_;
    }

    // CustomStyleCallbackDependsOnFont

    // cx

    Length& MutableCxInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cx_;
    }

    // cy

    Length& MutableCyInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->cy_;
    }

    // d

    // DarkColorScheme

    bool MutableDarkColorSchemeInternal()
    {
        return static_cast<bool>(data_.dark_color_scheme_);
    }

    // DependsOnScrollStateContainerQueries

    bool MutableDependsOnScrollStateContainerQueriesInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->depends_on_scroll_state_container_queries_);
    }

    // DependsOnSizeContainerQueries

    bool MutableDependsOnSizeContainerQueriesInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->depends_on_size_container_queries_);
    }

    // DependsOnStyleContainerQueries

    bool MutableDependsOnStyleContainerQueriesInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->depends_on_style_container_queries_);
    }

    // direction

    TextDirection MutableDirectionInternal()
    {
        return static_cast<TextDirection>(data_.direction_);
    }

    // Display

    EDisplay MutableDisplayInternal()
    {
        return static_cast<EDisplay>(data_.display_);
    }

    // DisplayLayoutCustomName

    AtomicString& MutableDisplayLayoutCustomNameInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->display_layout_custom_name_;
    }

    // DisplayLayoutCustomParentName

    AtomicString& MutableDisplayLayoutCustomParentNameInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->display_layout_custom_parent_name_;
    }

    // DocumentRulesSelectors

    void SetDocumentRulesSelectorsInternal(Member<HeapHashSet<WeakMember<StyleRule>>>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->document_rules_selectors_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->document_rules_selectors_
                = std::move(v);
    }

    Member<HeapHashSet<WeakMember<StyleRule>>>& MutableDocumentRulesSelectorsInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->document_rules_selectors_;
    }

    // dominant-baseline

    EDominantBaseline MutableDominantBaselineInternal()
    {
        return static_cast<EDominantBaseline>(Access(svg_data_, access_.svg_data_)->dominant_baseline_);
    }

    // app-region

    EDraggableRegionMode MutableDraggableRegionModeInternal()
    {
        return static_cast<EDraggableRegionMode>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->draggable_region_mode_);
    }

    // dynamic-range-limit

    DynamicRangeLimit& MutableDynamicRangeLimitInternal()
    {
        return Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->dynamic_range_limit_;
    }

    // EffectiveAppearance

    ControlPart MutableEffectiveAppearanceInternal()
    {
        return static_cast<ControlPart>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->effective_appearance_);
    }

    // EffectiveTouchAction

    TouchAction MutableEffectiveTouchActionInternal()
    {
        return static_cast<TouchAction>(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                                                   ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                                            ->effective_touch_action_);
    }

    // EffectiveZIndexZero

    bool MutableEffectiveZIndexZeroInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->effective_z_index_zero_);
    }

    // EffectiveZoom

    void SetEffectiveZoomInternal(float v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_zoom_ == v))
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->effective_zoom_
                = v;
    }

    float MutableEffectiveZoomInternal()
    {
        return Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->effective_zoom_;
    }

    // ElementIsViewTransitionParticipant

    // empty-cells

    EEmptyCells MutableEmptyCellsInternal()
    {
        return static_cast<EEmptyCells>(data_.empty_cells_);
    }

    // empty-cells

    bool MutableEmptyCellsIsInheritedInternal()
    {
        return static_cast<bool>(data_.empty_cells_is_inherited_);
    }

    // field-sizing

    EFieldSizing MutableFieldSizingInternal()
    {
        return static_cast<EFieldSizing>(Access(visual_data_, access_.visual_data_)->field_sizing_);
    }

    // fill-opacity

    float MutableFillOpacityInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->fill_data_, access_.fill_data_)->fill_opacity_;
    }

    // fill

    SVGPaint& MutableFillPaintInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->fill_data_, access_.fill_data_)->fill_paint_;
    }

    // fill-rule

    WindRule MutableFillRuleInternal()
    {
        return static_cast<WindRule>(Access(svg_data_, access_.svg_data_)->fill_rule_);
    }

    // filter

    FilterOperations& MutableFilterInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->filter_;
    }

    // FirstLineDependsOnSizeContainerQueries

    bool MutableFirstLineDependsOnSizeContainerQueriesInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->first_line_depends_on_size_container_queries_);
    }

    // flex-basis

    Length& MutableFlexBasisInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->flex_basis_;
    }

    // flex-direction

    EFlexDirection MutableFlexDirectionInternal()
    {
        return static_cast<EFlexDirection>(
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->flex_direction_);
    }

    // flex-grow

    float MutableFlexGrowInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->flex_grow_;
    }

    // flex-shrink

    float MutableFlexShrinkInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->flex_shrink_;
    }

    // flex-wrap

    EFlexWrap MutableFlexWrapInternal()
    {
        return static_cast<EFlexWrap>(
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->flex_wrap_);
    }

    // float
    EFloat Floating() const
    {
        return static_cast<EFloat>(data_.floating_);
    }

    EFloat MutableFloatingInternal()
    {
        return static_cast<EFloat>(data_.floating_);
    }

    // flood-color

    StyleColor& MutableFloodColorInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->flood_color_;
    }

    // flood-opacity

    float MutableFloodOpacityInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->flood_opacity_;
    }

    // font

    Font& MutableFontInternal()
    {
        return Access(font_data_, access_.font_data_)->font_;
    }

    // forced-color-adjust

    EForcedColorAdjust MutableForcedColorAdjustInternal()
    {
        return static_cast<EForcedColorAdjust>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->forced_color_adjust_);
    }

    // ForcesStackingContext

    bool MutableForcesStackingContextInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->forces_stacking_context_);
    }

    // grid-auto-columns

    NGGridTrackList& MutableGridAutoColumnsInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->grid_auto_columns_;
    }

    // grid-auto-flow
    GridAutoFlow GridAutoFlowInternal() const
    {
        return static_cast<GridAutoFlow>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                             ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_flow_);
    }

    GridAutoFlow MutableGridAutoFlowInternal()
    {
        return static_cast<GridAutoFlow>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->grid_auto_flow_);
    }

    // grid-auto-rows

    NGGridTrackList& MutableGridAutoRowsInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->grid_auto_rows_;
    }

    // grid-column-end

    GridPosition& MutableGridColumnEndInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->grid_column_end_;
    }

    // grid-column-start

    GridPosition& MutableGridColumnStartInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->grid_column_start_;
    }

    // grid-row-end

    GridPosition& MutableGridRowEndInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->grid_row_end_;
    }

    // grid-row-start

    GridPosition& MutableGridRowStartInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->grid_row_start_;
    }

    // grid-template-areas

    Member<ComputedGridTemplateAreas>& MutableGridTemplateAreasInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->grid_template_areas_;
    }

    // grid-template-columns

    ComputedGridTrackList& MutableGridTemplateColumnsInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->grid_data_,
            access_.grid_data_)
            ->grid_template_columns_;
    }

    // grid-template-rows

    ComputedGridTrackList& MutableGridTemplateRowsInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->grid_data_,
            access_.grid_data_)
            ->grid_template_rows_;
    }

    // HasAnchorEvaluator

    // HasAnchorFunctions

    // HasAttrFunction

    // HasAuthorBackground

    // HasAuthorBorder

    // HasAuthorBorderRadius

    // HasAuthorHighlightColors

    // HasAutoClip

    void SetHasAutoClipInternal(bool v)
    {
        if (!(visual_data_->has_auto_clip_ == static_cast<unsigned>(v)))
            Access(visual_data_, access_.visual_data_)->has_auto_clip_ = static_cast<unsigned>(v);
    }

    bool MutableHasAutoClipInternal()
    {
        return static_cast<bool>(Access(visual_data_, access_.visual_data_)->has_auto_clip_);
    }

    // HasAutoColumnCount

    void SetHasAutoColumnCountInternal(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_count_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->has_auto_column_count_
                = static_cast<unsigned>(v);
    }

    bool MutableHasAutoColumnCountInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->has_auto_column_count_);
    }

    // HasAutoColumnWidth

    void SetHasAutoColumnWidthInternal(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_width_
                == static_cast<unsigned>(v)))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->has_auto_column_width_
                = static_cast<unsigned>(v);
    }

    bool MutableHasAutoColumnWidthInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->has_auto_column_width_);
    }

    // HasAutoStandardLineClamp

    void SetHasAutoStandardLineClampInternal(bool v)
    {
        if (!(box_data_->has_auto_standard_line_clamp_ == static_cast<unsigned>(v)))
            Access(box_data_, access_.box_data_)->has_auto_standard_line_clamp_ = static_cast<unsigned>(v);
    }

    bool MutableHasAutoStandardLineClampInternal()
    {
        return static_cast<bool>(Access(box_data_, access_.box_data_)->has_auto_standard_line_clamp_);
    }

    // HasAutoZIndex

    void SetHasAutoZIndexInternal(bool v)
    {
        if (!(box_data_->has_auto_z_index_ == static_cast<unsigned>(v)))
            Access(box_data_, access_.box_data_)->has_auto_z_index_ = static_cast<unsigned>(v);
    }

    bool MutableHasAutoZIndexInternal()
    {
        return static_cast<bool>(Access(box_data_, access_.box_data_)->has_auto_z_index_);
    }

    // HasClipPath

    bool MutableHasClipPathInternal()
    {
        return static_cast<bool>(Access(visual_data_, access_.visual_data_)->has_clip_path_);
    }

    // HasContainerRelativeUnits

    // HasCurrentBackdropFilterAnimation

    bool MutableHasCurrentBackdropFilterAnimationInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->has_current_backdrop_filter_animation_);
    }

    // HasCurrentBackgroundColorAnimation

    bool MutableHasCurrentBackgroundColorAnimationInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->has_current_background_color_animation_);
    }

    // HasCurrentFilterAnimation

    bool MutableHasCurrentFilterAnimationInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->has_current_filter_animation_);
    }

    // HasCurrentOpacityAnimation

    bool MutableHasCurrentOpacityAnimationInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->has_current_opacity_animation_);
    }

    // HasCurrentRotateAnimation

    bool MutableHasCurrentRotateAnimationInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->has_current_rotate_animation_);
    }

    // HasCurrentScaleAnimation

    bool MutableHasCurrentScaleAnimationInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->has_current_scale_animation_);
    }

    // HasCurrentTransformAnimation

    bool MutableHasCurrentTransformAnimationInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->has_current_transform_animation_);
    }

    // HasCurrentTranslateAnimation

    bool MutableHasCurrentTranslateAnimationInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->has_current_translate_animation_);
    }

    // HasEmUnits

    // HasEnv

    // HasExplicitInheritance

    // HasExplicitOverflowXVisible

    // HasExplicitOverflowYVisible

    // HasGlyphRelativeUnits

    // HasLineHeightRelativeUnits

    // -internal-empty-line-height

    bool MutableHasLineIfEmptyInternal()
    {
        return static_cast<bool>(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                                            ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                                     ->has_line_if_empty_);
    }

    // HasLogicalDirectionRelativeUnits

    // HasNonUaHighlightPseudoStyles

    bool MutableHasNonUaHighlightPseudoStylesInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->has_non_ua_highlight_pseudo_styles_);
    }

    // HasNonUniversalHighlightPseudoStyles

    bool MutableHasNonUniversalHighlightPseudoStylesInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->has_non_universal_highlight_pseudo_styles_);
    }

    // HasRootFontRelativeUnits

    // HasVariableDeclaration

    // HasVariableReference

    // height

    Length& MutableHeightInternal()
    {
        return Access(box_data_, access_.box_data_)->height_;
    }

    // HighlightData

    StyleHighlightData& MutableHighlightDataInternal()
    {
        return Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                                 ->rare_inherited_usage_less_than_64_percent_sub_data_,
                          access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                          ->highlight_data_data_,
            access_.highlight_data_data_)
            ->highlight_data_;
    }

    // HighlightsDependOnSizeContainerQueries

    bool MutableHighlightsDependOnSizeContainerQueriesInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->highlights_depend_on_size_container_queries_);
    }

    // -webkit-border-horizontal-spacing

    short MutableHorizontalBorderSpacingInternal()
    {
        return Access(inherited_data_, access_.inherited_data_)->horizontal_border_spacing_;
    }

    // hyphenate-limit-chars

    StyleHyphenateLimitChars& MutableHyphenateLimitCharsInternal()
    {
        return Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->hyphenate_limit_chars_;
    }

    // hyphenate-character

    AtomicString& MutableHyphenationStringInternal()
    {
        return Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->hyphenation_string_;
    }

    // hyphens

    Hyphens MutableHyphensInternal()
    {
        return static_cast<Hyphens>(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->hyphens_);
    }

    // image-orientation

    RespectImageOrientationEnum MutableImageOrientationInternal()
    {
        return static_cast<RespectImageOrientationEnum>(
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_100_percent_data_,
                access_.rare_inherited_usage_less_than_100_percent_data_)
                ->image_orientation_);
    }

    // image-rendering

    EImageRendering MutableImageRenderingInternal()
    {
        return static_cast<EImageRendering>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->image_rendering_);
    }

    // InBaseSelectAppearance

    bool MutableInBaseSelectAppearanceInternal()
    {
        return static_cast<bool>(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                                            ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                                     ->in_base_select_appearance_);
    }

    // InForcedColorsMode

    bool MutableInForcedColorsModeInternal()
    {
        return static_cast<bool>(Access(inherited_data_, access_.inherited_data_)->in_forced_colors_mode_);
    }

    // InheritedVariables
    const Member<StyleInheritedVariables>& InheritedVariablesInternal() const
    {
        return inherited_data_->inherited_variables_;
    }

    void SetInheritedVariablesInternal(Member<StyleInheritedVariables>&& v)
    {
        if (!(inherited_data_->inherited_variables_ == v))
            Access(inherited_data_, access_.inherited_data_)->inherited_variables_ = std::move(v);
    }

    Member<StyleInheritedVariables>& MutableInheritedVariablesInternal()
    {
        return Access(inherited_data_, access_.inherited_data_)->inherited_variables_;
    }

    // InitialData

    // initial-letter

    StyleInitialLetter& MutableInitialLetterInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->initial_letter_;
    }

    // InlineBlockBaselineEdge

    EInlineBlockBaselineEdge MutableInlineBlockBaselineEdgeInternal()
    {
        return static_cast<EInlineBlockBaselineEdge>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->inline_block_baseline_edge_);
    }

    // InlineStyleLostCascade

    bool MutableInlineStyleLostCascadeInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->inline_style_lost_cascade_);
    }

    // InsideLink

    EInsideLink MutableInsideLinkInternal()
    {
        return static_cast<EInsideLink>(data_.inside_link_);
    }

    // interactivity

    EInteractivity MutableInteractivityInternal()
    {
        return static_cast<EInteractivity>(
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->interactivity_);
    }

    // -internal-forced-background-color
    const StyleColor& InternalForcedBackgroundColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
            ->internal_forced_background_color_;
    }

    StyleColor& MutableInternalForcedBackgroundColorInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->forced_colors_data_,
            access_.forced_colors_data_)
            ->internal_forced_background_color_;
    }

    // -internal-forced-border-color
    const StyleColor& InternalForcedBorderColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
            ->internal_forced_border_color_;
    }

    StyleColor& MutableInternalForcedBorderColorInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->forced_colors_data_,
            access_.forced_colors_data_)
            ->internal_forced_border_color_;
    }

    // -internal-forced-color
    const StyleColor& InternalForcedColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_
            ->internal_forced_color_;
    }

    StyleColor& MutableInternalForcedColorInternal()
    {
        return Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                                 ->rare_inherited_usage_less_than_64_percent_sub_data_,
                          access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                          ->inherited_forced_colors_data_,
            access_.inherited_forced_colors_data_)
            ->internal_forced_color_;
    }

    // -internal-forced-outline-color
    const StyleColor& InternalForcedOutlineColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
            ->internal_forced_outline_color_;
    }

    StyleColor& MutableInternalForcedOutlineColorInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->forced_colors_data_,
            access_.forced_colors_data_)
            ->internal_forced_outline_color_;
    }

    // -internal-forced-visited-color
    const StyleColor& InternalForcedVisitedColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_
            ->internal_forced_visited_color_;
    }

    StyleColor& MutableInternalForcedVisitedColorInternal()
    {
        return Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                                 ->rare_inherited_usage_less_than_64_percent_sub_data_,
                          access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                          ->inherited_forced_colors_data_,
            access_.inherited_forced_colors_data_)
            ->internal_forced_visited_color_;
    }

    // -internal-visited-background-color
    const StyleColor& InternalVisitedBackgroundColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_background_color_;
    }

    StyleColor& MutableInternalVisitedBackgroundColorInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->visited_data_,
            access_.visited_data_)
            ->internal_visited_background_color_;
    }

    // -internal-visited-border-bottom-color
    const StyleColor& InternalVisitedBorderBottomColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_border_bottom_color_;
    }

    StyleColor& MutableInternalVisitedBorderBottomColorInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->visited_data_,
            access_.visited_data_)
            ->internal_visited_border_bottom_color_;
    }

    // -internal-visited-border-left-color
    const StyleColor& InternalVisitedBorderLeftColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_border_left_color_;
    }

    StyleColor& MutableInternalVisitedBorderLeftColorInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->visited_data_,
            access_.visited_data_)
            ->internal_visited_border_left_color_;
    }

    // -internal-visited-border-right-color
    const StyleColor& InternalVisitedBorderRightColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_border_right_color_;
    }

    StyleColor& MutableInternalVisitedBorderRightColorInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->visited_data_,
            access_.visited_data_)
            ->internal_visited_border_right_color_;
    }

    // -internal-visited-border-top-color
    const StyleColor& InternalVisitedBorderTopColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_border_top_color_;
    }

    StyleColor& MutableInternalVisitedBorderTopColorInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->visited_data_,
            access_.visited_data_)
            ->internal_visited_border_top_color_;
    }

    // -internal-visited-caret-color
    const StyleAutoColor& InternalVisitedCaretColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
            ->internal_visited_caret_color_;
    }

    StyleAutoColor& MutableInternalVisitedCaretColorInternal()
    {
        return Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                                 ->rare_inherited_usage_less_than_64_percent_sub_data_,
                          access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                          ->inherited_visited_data_,
            access_.inherited_visited_data_)
            ->internal_visited_caret_color_;
    }

    // -internal-visited-color
    const StyleColor& InternalVisitedColor() const
    {
        return inherited_data_->internal_visited_color_;
    }

    StyleColor& MutableInternalVisitedColorInternal()
    {
        return Access(inherited_data_, access_.inherited_data_)->internal_visited_color_;
    }

    // InternalVisitedColorIsCurrentColor
    bool InternalVisitedColorIsCurrentColor() const
    {
        return static_cast<bool>(inherited_data_->internal_visited_color_is_current_color_);
    }

    bool MutableInternalVisitedColorIsCurrentColorInternal()
    {
        return static_cast<bool>(Access(inherited_data_, access_.inherited_data_)->internal_visited_color_is_current_color_);
    }

    // -internal-visited-column-rule-color

    GapDataList<StyleColor>& MutableInternalVisitedColumnRuleColorInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->visited_data_,
            access_.visited_data_)
            ->internal_visited_column_rule_color_;
    }

    // -internal-visited-fill

    SVGPaint& MutableInternalVisitedFillPaintInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->fill_data_, access_.fill_data_)->internal_visited_fill_paint_;
    }

    // -internal-visited-outline-color
    const StyleColor& InternalVisitedOutlineColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_outline_color_;
    }

    StyleColor& MutableInternalVisitedOutlineColorInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->visited_data_,
            access_.visited_data_)
            ->internal_visited_outline_color_;
    }

    // -internal-visited-stroke

    SVGPaint& MutableInternalVisitedStrokePaintInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->internal_visited_stroke_paint_;
    }

    // -internal-visited-text-decoration-color
    const StyleColor& InternalVisitedTextDecorationColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
            ->internal_visited_text_decoration_color_;
    }

    StyleColor& MutableInternalVisitedTextDecorationColorInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->visited_data_,
            access_.visited_data_)
            ->internal_visited_text_decoration_color_;
    }

    // -internal-visited-text-emphasis-color
    const StyleColor& InternalVisitedTextEmphasisColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
            ->internal_visited_text_emphasis_color_;
    }

    StyleColor& MutableInternalVisitedTextEmphasisColorInternal()
    {
        return Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                                 ->rare_inherited_usage_less_than_64_percent_sub_data_,
                          access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                          ->inherited_visited_data_,
            access_.inherited_visited_data_)
            ->internal_visited_text_emphasis_color_;
    }

    // -internal-visited-text-fill-color
    const StyleColor& InternalVisitedTextFillColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
            ->internal_visited_text_fill_color_;
    }

    StyleColor& MutableInternalVisitedTextFillColorInternal()
    {
        return Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                                 ->rare_inherited_usage_less_than_64_percent_sub_data_,
                          access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                          ->inherited_visited_data_,
            access_.inherited_visited_data_)
            ->internal_visited_text_fill_color_;
    }

    // -internal-visited-text-stroke-color
    const StyleColor& InternalVisitedTextStrokeColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
            ->internal_visited_text_stroke_color_;
    }

    StyleColor& MutableInternalVisitedTextStrokeColorInternal()
    {
        return Access(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                                 ->rare_inherited_usage_less_than_64_percent_sub_data_,
                          access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                          ->inherited_visited_data_,
            access_.inherited_visited_data_)
            ->internal_visited_text_stroke_color_;
    }

    // interpolate-size

    EInterpolateSize MutableInterpolateSizeInternal()
    {
        return static_cast<EInterpolateSize>(
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->interpolate_size_);
    }

    // IsEnsuredInDisplayNone

    // IsEnsuredOutsideFlatTree

    // IsFlexOrGridOrCustomItem

    // IsHTMLInert

    bool MutableIsHTMLInertInternal()
    {
        return static_cast<bool>(data_.is_html_inert_);
    }

    // IsHTMLInert

    bool MutableIsHTMLInertIsInheritedInternal()
    {
        return static_cast<bool>(data_.is_html_inert_is_inherited_);
    }

    // IsInBlockifyingDisplay

    // IsInInlinifyingDisplay

    // IsInsideDisplayIgnoringFloatingChildren

    // IsInsideListElement

    // IsLink

    // IsOriginalDisplayInlineType

    bool MutableIsOriginalDisplayInlineTypeInternal()
    {
        return static_cast<bool>(data_.is_original_display_inline_type_);
    }

    // IsPageMarginBox

    bool MutableIsPageMarginBoxInternal()
    {
        return static_cast<bool>(data_.is_page_margin_box_);
    }

    // IsRunningBackdropFilterAnimationOnCompositor

    bool MutableIsRunningBackdropFilterAnimationOnCompositorInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->is_running_backdrop_filter_animation_on_compositor_);
    }

    // IsRunningFilterAnimationOnCompositor

    bool MutableIsRunningFilterAnimationOnCompositorInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->is_running_filter_animation_on_compositor_);
    }

    // IsRunningOpacityAnimationOnCompositor

    bool MutableIsRunningOpacityAnimationOnCompositorInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->is_running_opacity_animation_on_compositor_);
    }

    // IsRunningRotateAnimationOnCompositor

    bool MutableIsRunningRotateAnimationOnCompositorInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->is_running_rotate_animation_on_compositor_);
    }

    // IsRunningScaleAnimationOnCompositor

    bool MutableIsRunningScaleAnimationOnCompositorInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->is_running_scale_animation_on_compositor_);
    }

    // IsRunningTransformAnimationOnCompositor

    bool MutableIsRunningTransformAnimationOnCompositorInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->is_running_transform_animation_on_compositor_);
    }

    // IsRunningTranslateAnimationOnCompositor

    bool MutableIsRunningTranslateAnimationOnCompositorInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->is_running_translate_animation_on_compositor_);
    }

    // IsSecondaryBodyElement

    // IsSpecifiedDisplayWebkitBox

    // IsStartingStyle

    // isolation

    EIsolation MutableIsolationInternal()
    {
        return static_cast<EIsolation>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->isolation_);
    }

    // stroke-linejoin

    LineJoin MutableJoinStyleInternal()
    {
        return static_cast<LineJoin>(Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->join_style_);
    }

    // justify-content

    StyleContentAlignmentData& MutableJustifyContentInternal()
    {
        return Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->justify_content_;
    }

    // justify-items

    StyleSelfAlignmentData& MutableJustifyItemsInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->justify_items_;
    }

    // justify-self

    StyleSelfAlignmentData& MutableJustifySelfInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->justify_self_;
    }

    // left

    Length& MutableLeftInternal()
    {
        return Access(surround_data_, access_.surround_data_)->left_;
    }

    // lighting-color

    StyleColor& MutableLightingColorInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->misc_data_, access_.misc_data_)->lighting_color_;
    }

    // -webkit-line-break

    LineBreak MutableLineBreakInternal()
    {
        return static_cast<LineBreak>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->line_break_);
    }

    // line-height
    const Length& LineHeightInternal() const
    {
        return inherited_data_->line_height_;
    }

    Length& MutableLineHeightInternal()
    {
        return Access(inherited_data_, access_.inherited_data_)->line_height_;
    }

    // list-style-image

    Member<StyleImage>& MutableListStyleImageInternal()
    {
        return Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->list_style_image_;
    }

    // list-style-position

    EListStylePosition MutableListStylePositionInternal()
    {
        return static_cast<EListStylePosition>(data_.list_style_position_);
    }

    // list-style-position

    bool MutableListStylePositionIsInheritedInternal()
    {
        return static_cast<bool>(data_.list_style_position_is_inherited_);
    }

    // list-style-type

    Member<ListStyleTypeData>& MutableListStyleTypeInternal()
    {
        return Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->list_style_type_;
    }

    // margin-bottom

    void SetMarginBottomInternal(const Length& v)
    {
        if (!(box_data_->margin_bottom_ == v))
            Access(box_data_, access_.box_data_)->margin_bottom_ = v;
    }

    void SetMarginBottomInternal(Length&& v)
    {
        if (!(box_data_->margin_bottom_ == v))
            Access(box_data_, access_.box_data_)->margin_bottom_ = std::move(v);
    }

    Length& MutableMarginBottomInternal()
    {
        return Access(box_data_, access_.box_data_)->margin_bottom_;
    }

    // margin-left

    void SetMarginLeftInternal(const Length& v)
    {
        if (!(box_data_->margin_left_ == v))
            Access(box_data_, access_.box_data_)->margin_left_ = v;
    }

    void SetMarginLeftInternal(Length&& v)
    {
        if (!(box_data_->margin_left_ == v))
            Access(box_data_, access_.box_data_)->margin_left_ = std::move(v);
    }

    Length& MutableMarginLeftInternal()
    {
        return Access(box_data_, access_.box_data_)->margin_left_;
    }

    // margin-right

    void SetMarginRightInternal(const Length& v)
    {
        if (!(box_data_->margin_right_ == v))
            Access(box_data_, access_.box_data_)->margin_right_ = v;
    }

    void SetMarginRightInternal(Length&& v)
    {
        if (!(box_data_->margin_right_ == v))
            Access(box_data_, access_.box_data_)->margin_right_ = std::move(v);
    }

    Length& MutableMarginRightInternal()
    {
        return Access(box_data_, access_.box_data_)->margin_right_;
    }

    // margin-top

    void SetMarginTopInternal(const Length& v)
    {
        if (!(box_data_->margin_top_ == v))
            Access(box_data_, access_.box_data_)->margin_top_ = v;
    }

    void SetMarginTopInternal(Length&& v)
    {
        if (!(box_data_->margin_top_ == v))
            Access(box_data_, access_.box_data_)->margin_top_ = std::move(v);
    }

    Length& MutableMarginTopInternal()
    {
        return Access(box_data_, access_.box_data_)->margin_top_;
    }

    // marker-end

    // marker-mid

    // marker-start

    // Mask
    const FillLayer& MaskInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_;
    }

    void SetMaskInternal(const FillLayer& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->mask_
                = v;
    }

    void SetMaskInternal(FillLayer&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->mask_
                = std::move(v);
    }

    FillLayer& MutableMaskInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->mask_;
    }

    // MaskBoxImage
    const NinePieceImage& MaskBoxImageInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_;
    }

    void SetMaskBoxImageInternal(const NinePieceImage& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->mask_box_image_
                = v;
    }

    void SetMaskBoxImageInternal(NinePieceImage&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->mask_box_image_
                = std::move(v);
    }

    NinePieceImage& MutableMaskBoxImageInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->mask_box_image_;
    }

    // mask-type

    EMaskType MutableMaskTypeInternal()
    {
        return static_cast<EMaskType>(Access(svg_data_, access_.svg_data_)->mask_type_);
    }

    // masonry-slack

    std::optional<Length>& MutableMasonrySlackInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->masonry_slack_;
    }

    // masonry-template-tracks

    ComputedGridTrackList& MutableMasonryTemplateTracksInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->masonry_data_,
            access_.masonry_data_)
            ->masonry_template_tracks_;
    }

    // masonry-track-end

    GridPosition& MutableMasonryTrackEndInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->masonry_track_end_;
    }

    // masonry-track-start

    GridPosition& MutableMasonryTrackStartInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->masonry_track_start_;
    }

    // MathBaseline

    Length& MutableMathBaselineInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->math_data_,
            access_.math_data_)
            ->math_baseline_;
    }

    // math-depth

    short MutableMathDepthInternal()
    {
        return Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_100_percent_data_,
            access_.rare_inherited_usage_less_than_100_percent_data_)
            ->math_depth_;
    }

    // MathFractionBarThickness

    Length& MutableMathFractionBarThicknessInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->math_data_,
            access_.math_data_)
            ->math_fraction_bar_thickness_;
    }

    // MathLSpace

    Length& MutableMathLSpaceInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->math_data_,
            access_.math_data_)
            ->math_l_space_;
    }

    // MathMaxSize

    Length& MutableMathMaxSizeInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->math_data_,
            access_.math_data_)
            ->math_max_size_;
    }

    // MathMinSize

    Length& MutableMathMinSizeInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->math_data_,
            access_.math_data_)
            ->math_min_size_;
    }

    // MathPaddedDepth

    Length& MutableMathPaddedDepthInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->math_data_,
            access_.math_data_)
            ->math_padded_depth_;
    }

    // MathPaddedVOffset

    Length& MutableMathPaddedVOffsetInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->math_data_,
            access_.math_data_)
            ->math_padded_v_offset_;
    }

    // MathRSpace

    Length& MutableMathRSpaceInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->math_data_,
            access_.math_data_)
            ->math_r_space_;
    }

    // math-shift

    EMathShift MutableMathShiftInternal()
    {
        return static_cast<EMathShift>(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                                                  ->rare_inherited_usage_less_than_100_percent_data_,
            access_.rare_inherited_usage_less_than_100_percent_data_)
                                           ->math_shift_);
    }

    // math-style

    EMathStyle MutableMathStyleInternal()
    {
        return static_cast<EMathStyle>(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                                                  ->rare_inherited_usage_less_than_100_percent_data_,
            access_.rare_inherited_usage_less_than_100_percent_data_)
                                           ->math_style_);
    }

    // max-height

    Length& MutableMaxHeightInternal()
    {
        return Access(box_data_, access_.box_data_)->max_height_;
    }

    // max-width

    Length& MutableMaxWidthInternal()
    {
        return Access(box_data_, access_.box_data_)->max_width_;
    }

    // MayHaveMargin

    // MayHavePadding

    // min-height

    Length& MutableMinHeightInternal()
    {
        return Access(box_data_, access_.box_data_)->min_height_;
    }

    // min-width

    Length& MutableMinWidthInternal()
    {
        return Access(box_data_, access_.box_data_)->min_width_;
    }

    // NonInheritedVariables
    const Member<StyleNonInheritedVariables>& NonInheritedVariablesInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->non_inherited_variables_;
    }

    void SetNonInheritedVariablesInternal(Member<StyleNonInheritedVariables>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->non_inherited_variables_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->non_inherited_variables_
                = std::move(v);
    }

    Member<StyleNonInheritedVariables>& MutableNonInheritedVariablesInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->non_inherited_variables_;
    }

    // object-fit

    EObjectFit MutableObjectFitInternal()
    {
        return static_cast<EObjectFit>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->object_fit_);
    }

    // object-position

    LengthPoint& MutableObjectPositionInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->object_position_;
    }

    // object-view-box

    // offset-anchor

    LengthPoint& MutableOffsetAnchorInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->offset_anchor_;
    }

    // offset-distance

    Length& MutableOffsetDistanceInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->offset_distance_;
    }

    // offset-path

    // offset-position

    LengthPoint& MutableOffsetPositionInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->offset_position_;
    }

    // offset-rotate

    StyleOffsetRotation& MutableOffsetRotateInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->offset_rotate_;
    }

    // opacity

    void SetOpacityInternal(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->opacity_ == v))
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->opacity_ = v;
    }

    float MutableOpacityInternal()
    {
        return Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->opacity_;
    }

    // order

    int MutableOrderInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->order_;
    }

    // origin-trial-test-property

    EOriginTrialTestProperty MutableOriginTrialTestPropertyInternal()
    {
        return static_cast<EOriginTrialTestProperty>(data_.origin_trial_test_property_);
    }

    // orphans

    void SetOrphansInternal(short v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->orphans_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->orphans_ = v;
    }

    short MutableOrphansInternal()
    {
        return Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->orphans_;
    }

    // outline-color
    const StyleColor& OutlineColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->outline_color_;
    }

    StyleColor& MutableOutlineColorInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->outline_color_;
    }

    // outline-offset

    LayoutUnit& MutableOutlineOffsetInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->outline_offset_;
    }

    // outline-style

    EBorderStyle MutableOutlineStyleInternal()
    {
        return static_cast<EBorderStyle>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->outline_style_);
    }

    // OutlineStyleIsAuto

    bool MutableOutlineStyleIsAutoInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->outline_style_is_auto_);
    }

    // outline-width
    const int& OutlineWidthInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_width_;
    }

    int& MutableOutlineWidthInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->outline_width_;
    }

    // overflow-anchor

    EOverflowAnchor MutableOverflowAnchorInternal()
    {
        return static_cast<EOverflowAnchor>(data_.overflow_anchor_);
    }

    // overflow-clip-margin

    std::optional<StyleOverflowClipMargin>& MutableOverflowClipMarginInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->overflow_clip_margin_;
    }

    // overflow-wrap

    EOverflowWrap MutableOverflowWrapInternal()
    {
        return static_cast<EOverflowWrap>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->overflow_wrap_);
    }

    // overflow-x

    EOverflow MutableOverflowXInternal()
    {
        return static_cast<EOverflow>(data_.overflow_x_);
    }

    // overflow-y

    EOverflow MutableOverflowYInternal()
    {
        return static_cast<EOverflow>(data_.overflow_y_);
    }

    // overlay

    EOverlay MutableOverlayInternal()
    {
        return static_cast<EOverlay>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->overlay_);
    }

    // overscroll-behavior-x

    EOverscrollBehavior MutableOverscrollBehaviorXInternal()
    {
        return static_cast<EOverscrollBehavior>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->overscroll_behavior_x_);
    }

    // overscroll-behavior-y

    EOverscrollBehavior MutableOverscrollBehaviorYInternal()
    {
        return static_cast<EOverscrollBehavior>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->overscroll_behavior_y_);
    }

    // padding-bottom

    void SetPaddingBottomInternal(const Length& v)
    {
        if (!(box_data_->padding_bottom_ == v))
            Access(box_data_, access_.box_data_)->padding_bottom_ = v;
    }

    void SetPaddingBottomInternal(Length&& v)
    {
        if (!(box_data_->padding_bottom_ == v))
            Access(box_data_, access_.box_data_)->padding_bottom_ = std::move(v);
    }

    Length& MutablePaddingBottomInternal()
    {
        return Access(box_data_, access_.box_data_)->padding_bottom_;
    }

    // padding-left

    void SetPaddingLeftInternal(const Length& v)
    {
        if (!(box_data_->padding_left_ == v))
            Access(box_data_, access_.box_data_)->padding_left_ = v;
    }

    void SetPaddingLeftInternal(Length&& v)
    {
        if (!(box_data_->padding_left_ == v))
            Access(box_data_, access_.box_data_)->padding_left_ = std::move(v);
    }

    Length& MutablePaddingLeftInternal()
    {
        return Access(box_data_, access_.box_data_)->padding_left_;
    }

    // padding-right

    void SetPaddingRightInternal(const Length& v)
    {
        if (!(box_data_->padding_right_ == v))
            Access(box_data_, access_.box_data_)->padding_right_ = v;
    }

    void SetPaddingRightInternal(Length&& v)
    {
        if (!(box_data_->padding_right_ == v))
            Access(box_data_, access_.box_data_)->padding_right_ = std::move(v);
    }

    Length& MutablePaddingRightInternal()
    {
        return Access(box_data_, access_.box_data_)->padding_right_;
    }

    // padding-top

    void SetPaddingTopInternal(const Length& v)
    {
        if (!(box_data_->padding_top_ == v))
            Access(box_data_, access_.box_data_)->padding_top_ = v;
    }

    void SetPaddingTopInternal(Length&& v)
    {
        if (!(box_data_->padding_top_ == v))
            Access(box_data_, access_.box_data_)->padding_top_ = std::move(v);
    }

    Length& MutablePaddingTopInternal()
    {
        return Access(box_data_, access_.box_data_)->padding_top_;
    }

    // page

    AtomicString& MutablePageInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->page_;
    }

    // page-orientation

    PageOrientation MutablePageOrientationInternal()
    {
        return static_cast<PageOrientation>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->page_orientation_);
    }

    // PageSize

    gfx::SizeF& MutablePageSizeInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->page_size_;
    }

    // PageSizeType

    PageSizeType MutablePageSizeTypeInternal()
    {
        return static_cast<PageSizeType>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->page_size_type_);
    }

    // PaintImages
    const Member<PaintImages>& PaintImagesInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->paint_images_;
    }

    void SetPaintImagesInternal(Member<PaintImages>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->paint_images_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->paint_images_
                = std::move(v);
    }

    Member<PaintImages>& MutablePaintImagesInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->paint_images_;
    }

    // paint-order

    EPaintOrder MutablePaintOrderInternal()
    {
        return static_cast<EPaintOrder>(Access(svg_data_, access_.svg_data_)->paint_order_);
    }

    // perspective

    float MutablePerspectiveInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->perspective_;
    }

    // perspective-origin

    LengthPoint& MutablePerspectiveOriginInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->perspective_origin_;
    }

    // pointer-events
    EPointerEvents PointerEvents() const
    {
        return static_cast<EPointerEvents>(data_.pointer_events_);
    }

    EPointerEvents MutablePointerEventsInternal()
    {
        return static_cast<EPointerEvents>(data_.pointer_events_);
    }

    // pointer-events
    bool PointerEventsIsInherited() const
    {
        return static_cast<bool>(data_.pointer_events_is_inherited_);
    }

    bool MutablePointerEventsIsInheritedInternal()
    {
        return static_cast<bool>(data_.pointer_events_is_inherited_);
    }

    // popover-hide-delay

    float MutablePopoverHideDelayInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->popover_hide_delay_;
    }

    // popover-show-delay

    float MutablePopoverShowDelayInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->popover_show_delay_;
    }

    // position
    EPosition PositionInternal() const
    {
        return static_cast<EPosition>(data_.position_);
    }

    EPosition MutablePositionInternal()
    {
        return static_cast<EPosition>(data_.position_);
    }

    // position-anchor

    Member<ScopedCSSName>& MutablePositionAnchorInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->position_anchor_;
    }

    // position-area

    PositionArea& MutablePositionAreaInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->position_area_;
    }

    // PositionAreaOffsets

    std::optional<blink::PositionAreaOffsets>& MutablePositionAreaOffsetsInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->position_area_offsets_;
    }

    // position-try-fallbacks

    Member<PositionTryFallbacks>& MutablePositionTryFallbacksInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->position_try_fallbacks_;
    }

    // position-try-order

    EPositionTryOrder MutablePositionTryOrderInternal()
    {
        return static_cast<EPositionTryOrder>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->position_try_order_);
    }

    // position-visibility

    PositionVisibility MutablePositionVisibilityInternal()
    {
        return static_cast<PositionVisibility>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->position_visibility_);
    }

    // PrefersDefaultScrollbarStyles

    bool MutablePrefersDefaultScrollbarStylesInternal()
    {
        return static_cast<bool>(data_.prefers_default_scrollbar_styles_);
    }

    // -webkit-print-color-adjust

    EPrintColorAdjust MutablePrintColorAdjustInternal()
    {
        return static_cast<EPrintColorAdjust>(data_.print_color_adjust_);
    }

    // PseudoArgument

    AtomicString& MutablePseudoArgumentInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->pseudo_argument_;
    }

    // PseudoElementStyles
    unsigned PseudoElementStylesInternal() const
    {
        return static_cast<unsigned>(data_.pseudo_element_styles_);
    }

    unsigned MutablePseudoElementStylesInternal()
    {
        return static_cast<unsigned>(data_.pseudo_element_styles_);
    }

    // quotes

    // r

    Length& MutableRInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->r_;
    }

    // reading-flow

    EReadingFlow MutableReadingFlowInternal()
    {
        return static_cast<EReadingFlow>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->reading_flow_);
    }

    // RequiresAcceleratedCompositingForExternalReasons

    bool MutableRequiresAcceleratedCompositingForExternalReasonsInternal()
    {
        return static_cast<bool>(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                            ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                                     ->requires_accelerated_compositing_for_external_reasons_);
    }

    // resize
    EResize Resize() const
    {
        return static_cast<EResize>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->resize_);
    }

    EResize MutableResizeInternal()
    {
        return static_cast<EResize>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->resize_);
    }

    // right

    Length& MutableRightInternal()
    {
        return Access(surround_data_, access_.surround_data_)->right_;
    }

    // rotate

    // row-gap

    std::optional<Length>& MutableRowGapInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->row_gap_;
    }

    // -webkit-rtl-ordering

    EOrder MutableRtlOrderingInternal()
    {
        return static_cast<EOrder>(data_.rtl_ordering_);
    }

    // -webkit-rtl-ordering

    bool MutableRtlOrderingIsInheritedInternal()
    {
        return static_cast<bool>(data_.rtl_ordering_is_inherited_);
    }

    // ruby-align

    ERubyAlign MutableRubyAlignInternal()
    {
        return static_cast<ERubyAlign>(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                                                  ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                                           ->ruby_align_);
    }

    // ruby-position

    RubyPosition MutableRubyPositionInternal()
    {
        return static_cast<RubyPosition>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->ruby_position_);
    }

    // rx

    Length& MutableRxInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->rx_;
    }

    // ry

    Length& MutableRyInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->ry_;
    }

    // scale

    // scroll-behavior

    mojom::blink::ScrollBehavior MutableScrollBehaviorInternal()
    {
        return static_cast<mojom::blink::ScrollBehavior>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->scroll_behavior_);
    }

    // scroll-margin-bottom

    float MutableScrollMarginBottomInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->scroll_margin_bottom_;
    }

    // scroll-margin-left

    float MutableScrollMarginLeftInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->scroll_margin_left_;
    }

    // scroll-margin-right

    float MutableScrollMarginRightInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->scroll_margin_right_;
    }

    // scroll-margin-top

    float MutableScrollMarginTopInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->scroll_margin_top_;
    }

    // scroll-marker-group

    EScrollMarkerGroup MutableScrollMarkerGroupInternal()
    {
        return static_cast<EScrollMarkerGroup>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->scroll_marker_group_);
    }

    // scroll-padding-bottom

    Length& MutableScrollPaddingBottomInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->scroll_padding_bottom_;
    }

    // scroll-padding-left

    Length& MutableScrollPaddingLeftInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->scroll_padding_left_;
    }

    // scroll-padding-right

    Length& MutableScrollPaddingRightInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->scroll_padding_right_;
    }

    // scroll-padding-top

    Length& MutableScrollPaddingTopInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->scroll_padding_top_;
    }

    // scroll-snap-align

    cc::ScrollSnapAlign& MutableScrollSnapAlignInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->scroll_snap_align_;
    }

    // scroll-snap-stop

    EScrollSnapStop MutableScrollSnapStopInternal()
    {
        return static_cast<EScrollSnapStop>(data_.scroll_snap_stop_);
    }

    // scroll-snap-type

    cc::ScrollSnapType& MutableScrollSnapTypeInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->scroll_snap_type_;
    }

    // scroll-start-target

    EScrollStartTarget MutableScrollStartTargetInternal()
    {
        return static_cast<EScrollStartTarget>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->scroll_start_target_);
    }

    // scroll-start-x

    ScrollStartData& MutableScrollStartXInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->start_data_,
            access_.start_data_)
            ->scroll_start_x_;
    }

    // scroll-start-y

    ScrollStartData& MutableScrollStartYInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->start_data_,
            access_.start_data_)
            ->scroll_start_y_;
    }

    // scroll-timeline-axis

    Vector<TimelineAxis>& MutableScrollTimelineAxisInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->timeline_data_,
            access_.timeline_data_)
            ->scroll_timeline_axis_;
    }

    // scroll-timeline-name

    Member<ScopedCSSNameList>& MutableScrollTimelineNameInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->timeline_data_,
            access_.timeline_data_)
            ->scroll_timeline_name_;
    }

    // scrollbar-color

    // scrollbar-gutter

    unsigned MutableScrollbarGutterInternal()
    {
        return static_cast<unsigned>(data_.scrollbar_gutter_);
    }

    // scrollbar-width

    EScrollbarWidth MutableScrollbarWidthInternal()
    {
        return static_cast<EScrollbarWidth>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->scrollbar_width_);
    }

    // shape-image-threshold

    void SetShapeImageThresholdInternal(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                    ->rare_non_inherited_usage_less_than_100_percent_data_->shape_image_threshold_
                == v))
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->shape_image_threshold_
                = v;
    }

    float MutableShapeImageThresholdInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->shape_image_threshold_;
    }

    // shape-margin

    Length& MutableShapeMarginInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->shape_margin_;
    }

    // shape-outside
    const Member<ShapeValue>& ShapeOutsideInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->shape_outside_;
    }

    Member<ShapeValue>& MutableShapeOutsideInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->shape_outside_;
    }

    // shape-rendering

    EShapeRendering MutableShapeRenderingInternal()
    {
        return static_cast<EShapeRendering>(Access(svg_data_, access_.svg_data_)->shape_rendering_);
    }

    // ShouldIgnoreOverflowPropertyForInlineBlockBaseline

    // SkipsContents

    bool MutableSkipsContentsInternal()
    {
        return static_cast<bool>(data_.skips_contents_);
    }

    // speak

    ESpeak MutableSpeakInternal()
    {
        return static_cast<ESpeak>(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->speak_);
    }

    // line-clamp

    void SetStandardLineClampInternal(int v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->standard_line_clamp_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->standard_line_clamp_
                = v;
    }

    int MutableStandardLineClampInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->standard_line_clamp_;
    }

    // stop-color
    const StyleColor& StopColor() const
    {
        return svg_data_->stop_data_->stop_color_;
    }

    StyleColor& MutableStopColorInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->stop_data_, access_.stop_data_)->stop_color_;
    }

    // stop-opacity

    float MutableStopOpacityInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->stop_data_, access_.stop_data_)->stop_opacity_;
    }

    // stroke-dasharray

    // stroke-dashoffset

    Length& MutableStrokeDashOffsetInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_dash_offset_;
    }

    // stroke-miterlimit

    float MutableStrokeMiterLimitInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_miter_limit_;
    }

    // stroke-opacity

    float MutableStrokeOpacityInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_opacity_;
    }

    // stroke

    SVGPaint& MutableStrokePaintInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_paint_;
    }

    // stroke-width

    UnzoomedLength& MutableStrokeWidthInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->stroke_data_, access_.stroke_data_)->stroke_width_;
    }

    // StyleType

    PseudoId MutableStyleTypeInternal()
    {
        return static_cast<PseudoId>(data_.style_type_);
    }

    // SubtreeIsSticky

    bool MutableSubtreeIsStickyInternal()
    {
        return static_cast<bool>(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                                            ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                                     ->subtree_is_sticky_);
    }

    // SubtreeWillChangeContents

    bool MutableSubtreeWillChangeContentsInternal()
    {
        return static_cast<bool>(Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                                            ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                                     ->subtree_will_change_contents_);
    }

    // tab-size

    void SetTabSizeInternal(const TabSize& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->tab_size_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->tab_size_ = v;
    }

    void SetTabSizeInternal(TabSize&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->tab_size_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->tab_size_ = std::move(v);
    }

    TabSize& MutableTabSizeInternal()
    {
        return Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->tab_size_;
    }

    // table-layout

    ETableLayout MutableTableLayoutInternal()
    {
        return static_cast<ETableLayout>(data_.table_layout_);
    }

    // -webkit-tap-highlight-color

    StyleColor& MutableTapHighlightColorInternal()
    {
        return Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_100_percent_data_,
            access_.rare_inherited_usage_less_than_100_percent_data_)
            ->tap_highlight_color_;
    }

    // text-align

    ETextAlign MutableTextAlignInternal()
    {
        return static_cast<ETextAlign>(data_.text_align_);
    }

    // text-align-last

    ETextAlignLast MutableTextAlignLastInternal()
    {
        return static_cast<ETextAlignLast>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_align_last_);
    }

    // text-anchor

    ETextAnchor MutableTextAnchorInternal()
    {
        return static_cast<ETextAnchor>(Access(svg_data_, access_.svg_data_)->text_anchor_);
    }

    // TextAutosizingMultiplier

    void SetTextAutosizingMultiplierInternal(float v)
    {
        if (!(inherited_data_->text_autosizing_multiplier_ == v))
            Access(inherited_data_, access_.inherited_data_)->text_autosizing_multiplier_ = v;
    }

    float MutableTextAutosizingMultiplierInternal()
    {
        return Access(inherited_data_, access_.inherited_data_)->text_autosizing_multiplier_;
    }

    // text-autospace

    ETextAutospace MutableTextAutospaceInternal()
    {
        return static_cast<ETextAutospace>(
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->text_autospace_);
    }

    // text-box-edge

    TextBoxEdge MutableTextBoxEdgeInternal()
    {
        return static_cast<TextBoxEdge>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_box_edge_);
    }

    // text-box-trim

    ETextBoxTrim MutableTextBoxTrimInternal()
    {
        return static_cast<ETextBoxTrim>(Access(box_data_, access_.box_data_)->text_box_trim_);
    }

    // text-combine-upright

    ETextCombine MutableTextCombineInternal()
    {
        return static_cast<ETextCombine>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_combine_);
    }

    // text-decoration-color
    const StyleColor& TextDecorationColor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
            ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_color_;
    }

    StyleColor& MutableTextDecorationColorInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->text_decoration_color_;
    }

    // text-decoration-line

    // text-decoration-skip-ink

    ETextDecorationSkipInk MutableTextDecorationSkipInkInternal()
    {
        return static_cast<ETextDecorationSkipInk>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_decoration_skip_ink_);
    }

    // text-decoration-style

    ETextDecorationStyle MutableTextDecorationStyleInternal()
    {
        return static_cast<ETextDecorationStyle>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->text_decoration_style_);
    }

    // text-decoration-thickness

    TextDecorationThickness& MutableTextDecorationThicknessInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_22_percent_data_,
                          access_.rare_non_inherited_usage_less_than_22_percent_data_)
                          ->rare_non_inherited_usage_less_than_100_percent_data_,
            access_.rare_non_inherited_usage_less_than_100_percent_data_)
            ->text_decoration_thickness_;
    }

    // text-emphasis-color
    const StyleColor& TextEmphasisColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_;
    }

    StyleColor& MutableTextEmphasisColorInternal()
    {
        return Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_emphasis_color_;
    }

    // TextEmphasisCustomMark

    AtomicString& MutableTextEmphasisCustomMarkInternal()
    {
        return Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_64_percent_sub_data_,
            access_.rare_inherited_usage_less_than_64_percent_sub_data_)
            ->text_emphasis_custom_mark_;
    }

    // TextEmphasisFill

    TextEmphasisFill MutableTextEmphasisFillInternal()
    {
        return static_cast<TextEmphasisFill>(
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->text_emphasis_fill_);
    }

    // TextEmphasisMark
    TextEmphasisMark TextEmphasisMarkInternal() const
    {
        return static_cast<TextEmphasisMark>(
            rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_mark_);
    }

    TextEmphasisMark MutableTextEmphasisMarkInternal()
    {
        return static_cast<TextEmphasisMark>(
            Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                       ->rare_inherited_usage_less_than_64_percent_sub_data_,
                access_.rare_inherited_usage_less_than_64_percent_sub_data_)
                ->text_emphasis_mark_);
    }

    // text-emphasis-position

    TextEmphasisPosition MutableTextEmphasisPositionInternal()
    {
        return static_cast<TextEmphasisPosition>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_emphasis_position_);
    }

    // -webkit-text-fill-color
    const StyleColor& TextFillColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->text_fill_color_;
    }

    StyleColor& MutableTextFillColorInternal()
    {
        return Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_fill_color_;
    }

    // text-indent

    Length& MutableTextIndentInternal()
    {
        return Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_indent_;
    }

    // text-orientation

    ETextOrientation MutableTextOrientationInternal()
    {
        return static_cast<ETextOrientation>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_orientation_);
    }

    // text-overflow

    ETextOverflow MutableTextOverflowInternal()
    {
        return static_cast<ETextOverflow>(
            Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->text_overflow_);
    }

    // -webkit-text-security

    ETextSecurity MutableTextSecurityInternal()
    {
        return static_cast<ETextSecurity>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_security_);
    }

    // text-shadow

    // text-size-adjust

    TextSizeAdjust& MutableTextSizeAdjustInternal()
    {
        return Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_size_adjust_;
    }

    // -webkit-text-stroke-color
    const StyleColor& TextStrokeColor() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_;
    }

    StyleColor& MutableTextStrokeColorInternal()
    {
        return Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_stroke_color_;
    }

    // -webkit-text-stroke-width

    float MutableTextStrokeWidthInternal()
    {
        return Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_stroke_width_;
    }

    // text-transform

    ETextTransform MutableTextTransformInternal()
    {
        return static_cast<ETextTransform>(data_.text_transform_);
    }

    // text-transform

    bool MutableTextTransformIsInheritedInternal()
    {
        return static_cast<bool>(data_.text_transform_is_inherited_);
    }

    // text-underline-offset

    Length& MutableTextUnderlineOffsetInternal()
    {
        return Access(Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)
                          ->rare_inherited_usage_less_than_100_percent_data_,
            access_.rare_inherited_usage_less_than_100_percent_data_)
            ->text_underline_offset_;
    }

    // text-underline-position

    TextUnderlinePosition MutableTextUnderlinePositionInternal()
    {
        return static_cast<TextUnderlinePosition>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->text_underline_position_);
    }

    // text-wrap-mode

    TextWrapMode MutableTextWrapModeInternal()
    {
        return static_cast<TextWrapMode>(data_.text_wrap_mode_);
    }

    // text-wrap-style

    TextWrapStyle MutableTextWrapStyleInternal()
    {
        return static_cast<TextWrapStyle>(data_.text_wrap_style_);
    }

    // timeline-scope

    Member<ScopedCSSNameList>& MutableTimelineScopeInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->timeline_data_,
            access_.timeline_data_)
            ->timeline_scope_;
    }

    // top

    Length& MutableTopInternal()
    {
        return Access(surround_data_, access_.surround_data_)->top_;
    }

    // touch-action

    TouchAction MutableTouchActionInternal()
    {
        return static_cast<TouchAction>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_22_percent_data_,
                access_.rare_non_inherited_usage_less_than_22_percent_data_)
                ->touch_action_);
    }

    // transform

    TransformOperations& MutableTransformInternal()
    {
        return Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)->transform_;
    }

    // transform-box

    ETransformBox MutableTransformBoxInternal()
    {
        return static_cast<ETransformBox>(data_.transform_box_);
    }

    // transform-origin

    TransformOrigin& MutableTransformOriginInternal()
    {
        return Access(svg_data_, access_.svg_data_)->transform_origin_;
    }

    // transform-style

    ETransformStyle3D MutableTransformStyle3DInternal()
    {
        return static_cast<ETransformStyle3D>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->transform_style_3d_);
    }

    // Transitions
    const std::unique_ptr<CSSTransitionData>& TransitionsInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->transitions_;
    }

    void SetTransitionsInternal(std::unique_ptr<CSSTransitionData>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->transitions_ == v))
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->transitions_
                = std::move(v);
    }

    std::unique_ptr<CSSTransitionData>& MutableTransitionsInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->transitions_;
    }

    // translate

    // UAShadowHostData

    // unicode-bidi

    UnicodeBidi MutableUnicodeBidiInternal()
    {
        return static_cast<UnicodeBidi>(data_.unicode_bidi_);
    }

    // -webkit-user-drag

    EUserDrag MutableUserDragInternal()
    {
        return static_cast<EUserDrag>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_22_percent_data_,
                       access_.rare_non_inherited_usage_less_than_22_percent_data_)
                       ->rare_non_inherited_usage_less_than_100_percent_data_,
                access_.rare_non_inherited_usage_less_than_100_percent_data_)
                ->user_drag_);
    }

    // -webkit-user-modify
    EUserModify UserModify() const
    {
        return static_cast<EUserModify>(rare_inherited_usage_less_than_64_percent_data_->user_modify_);
    }

    EUserModify MutableUserModifyInternal()
    {
        return static_cast<EUserModify>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->user_modify_);
    }

    // user-select
    EUserSelect UserSelect() const
    {
        return static_cast<EUserSelect>(rare_inherited_usage_less_than_64_percent_data_->user_select_);
    }

    EUserSelect MutableUserSelectInternal()
    {
        return static_cast<EUserSelect>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->user_select_);
    }

    // vector-effect

    EVectorEffect MutableVectorEffectInternal()
    {
        return static_cast<EVectorEffect>(Access(svg_data_, access_.svg_data_)->vector_effect_);
    }

    // VerticalAlign
    unsigned VerticalAlignInternal() const
    {
        return static_cast<unsigned>(data_.vertical_align_);
    }

    void SetVerticalAlignInternal(unsigned v)
    {
        data_.vertical_align_ = static_cast<unsigned>(v);
    }

    unsigned MutableVerticalAlignInternal()
    {
        return static_cast<unsigned>(data_.vertical_align_);
    }

    // VerticalAlignLength

    void SetVerticalAlignLengthInternal(const Length& v)
    {
        if (!(box_data_->vertical_align_length_ == v))
            Access(box_data_, access_.box_data_)->vertical_align_length_ = v;
    }

    void SetVerticalAlignLengthInternal(Length&& v)
    {
        if (!(box_data_->vertical_align_length_ == v))
            Access(box_data_, access_.box_data_)->vertical_align_length_ = std::move(v);
    }

    Length& MutableVerticalAlignLengthInternal()
    {
        return Access(box_data_, access_.box_data_)->vertical_align_length_;
    }

    // -webkit-border-vertical-spacing

    short MutableVerticalBorderSpacingInternal()
    {
        return Access(inherited_data_, access_.inherited_data_)->vertical_border_spacing_;
    }

    // view-timeline-axis

    Vector<TimelineAxis>& MutableViewTimelineAxisInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->timeline_data_,
            access_.timeline_data_)
            ->view_timeline_axis_;
    }

    // view-timeline-inset

    Vector<TimelineInset>& MutableViewTimelineInsetInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->timeline_data_,
            access_.timeline_data_)
            ->view_timeline_inset_;
    }

    // view-timeline-name

    Member<ScopedCSSNameList>& MutableViewTimelineNameInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->timeline_data_,
            access_.timeline_data_)
            ->view_timeline_name_;
    }

    // view-transition-capture-mode

    StyleViewTransitionCaptureMode MutableViewTransitionCaptureModeInternal()
    {
        return static_cast<StyleViewTransitionCaptureMode>(
            Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                       ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                ->view_transition_capture_mode_);
    }

    // view-transition-class

    Member<ScopedCSSNameList>& MutableViewTransitionClassInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->view_transition_class_;
    }

    // view-transition-group

    StyleViewTransitionGroup& MutableViewTransitionGroupInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->view_transition_group_;
    }

    // view-transition-name

    Member<StyleViewTransitionName>& MutableViewTransitionNameInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
            access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
            ->view_transition_name_;
    }

    // ViewportUnitFlags

    unsigned MutableViewportUnitFlagsInternal()
    {
        return static_cast<unsigned>(data_.viewport_unit_flags_);
    }

    // visibility

    EVisibility MutableVisibilityInternal()
    {
        return static_cast<EVisibility>(data_.visibility_);
    }

    // visibility

    bool MutableVisibilityIsInheritedInternal()
    {
        return static_cast<bool>(data_.visibility_is_inherited_);
    }

    // -webkit-line-clamp

    int MutableWebkitLineClampInternal()
    {
        return Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                          ->rare_non_inherited_usage_less_than_22_percent_data_,
            access_.rare_non_inherited_usage_less_than_22_percent_data_)
            ->webkit_line_clamp_;
    }

    // white-space-collapse

    WhiteSpaceCollapse MutableWhiteSpaceCollapseInternal()
    {
        return static_cast<WhiteSpaceCollapse>(data_.white_space_collapse_);
    }

    // widows

    void SetWidowsInternal(short v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->widows_ == v))
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->widows_ = v;
    }

    short MutableWidowsInternal()
    {
        return Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->widows_;
    }

    // width

    Length& MutableWidthInternal()
    {
        return Access(box_data_, access_.box_data_)->width_;
    }

    // WillChangeContents

    bool MutableWillChangeContentsInternal()
    {
        return static_cast<bool>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->will_change_data_,
                access_.will_change_data_)
                ->will_change_contents_);
    }

    // WillChangeProperties

    Vector<CSSPropertyID>& MutableWillChangePropertiesInternal()
    {
        return Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                                 ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                          access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                          ->will_change_data_,
            access_.will_change_data_)
            ->will_change_properties_;
    }

    // WillChangeScrollPosition

    bool MutableWillChangeScrollPositionInternal()
    {
        return static_cast<bool>(
            Access(Access(Access(rare_non_inherited_usage_less_than_14_percent_data_, access_.rare_non_inherited_usage_less_than_14_percent_data_)
                              ->rare_non_inherited_usage_less_than_14_percent_sub_data_,
                       access_.rare_non_inherited_usage_less_than_14_percent_sub_data_)
                       ->will_change_data_,
                access_.will_change_data_)
                ->will_change_scroll_position_);
    }

    // word-break

    EWordBreak MutableWordBreakInternal()
    {
        return static_cast<EWordBreak>(
            Access(rare_inherited_usage_less_than_64_percent_data_, access_.rare_inherited_usage_less_than_64_percent_data_)->word_break_);
    }

    // writing-mode

    WritingMode MutableWritingModeInternal()
    {
        return static_cast<WritingMode>(data_.writing_mode_);
    }

    // x

    Length& MutableXInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->x_;
    }

    // y

    Length& MutableYInternal()
    {
        return Access(Access(svg_data_, access_.svg_data_)->geometry_data_, access_.geometry_data_)->y_;
    }

    // z-index

    void SetZIndexInternal(int v)
    {
        if (!(box_data_->z_index_ == v))
            Access(box_data_, access_.box_data_)->z_index_ = v;
    }

    int MutableZIndexInternal()
    {
        return Access(box_data_, access_.box_data_)->z_index_;
    }

    // zoom

    float MutableZoomInternal()
    {
        return Access(visual_data_, access_.visual_data_)->zoom_;
    }

    void ResetAccess() const
    {
        memset(&access_, 0, sizeof(access_));
    }

private:
    friend class ComputedStyleBase;

    // Access flags. These are passed to Access to ensure that we have
    // a private copy of the relevant group before mutation.
    mutable struct {
        bool background_data_ = false;
        bool box_data_ = false;
        bool fill_data_ = false;
        bool font_data_ = false;
        bool forced_colors_data_ = false;
        bool geometry_data_ = false;
        bool grid_data_ = false;
        bool highlight_data_data_ = false;
        bool inherited_data_ = false;
        bool inherited_forced_colors_data_ = false;
        bool inherited_resources_data_ = false;
        bool inherited_visited_data_ = false;
        bool masonry_data_ = false;
        bool math_data_ = false;
        bool misc_data_ = false;
        bool rare_inherited_usage_less_than_100_percent_data_ = false;
        bool rare_inherited_usage_less_than_64_percent_data_ = false;
        bool rare_inherited_usage_less_than_64_percent_sub_data_ = false;
        bool rare_non_inherited_usage_less_than_100_percent_data_ = false;
        bool rare_non_inherited_usage_less_than_14_percent_data_ = false;
        bool rare_non_inherited_usage_less_than_14_percent_sub_data_ = false;
        bool rare_non_inherited_usage_less_than_22_percent_data_ = false;
        bool start_data_ = false;
        bool stop_data_ = false;
        bool stroke_data_ = false;
        bool surround_data_ = false;
        bool svg_data_ = false;
        bool timeline_data_ = false;
        bool visited_data_ = false;
        bool visual_data_ = false;
        bool will_change_data_ = false;
    } access_;

    template <typename T> static T* Access(T*& data, bool& access_flag)
    {
        if (!access_flag) {
            access_flag = true;
            data = data->Copy();
        }
        return data;
    }

    template <typename T> static T* Access(Member<T>& data, bool& access_flag)
    {
        if (!access_flag) {
            access_flag = true;
            data = data->Copy();
        }
        return data.Get();
    }

    using StyleRareInheritedUsageLessThan64PercentData = ComputedStyleBase::StyleRareInheritedUsageLessThan64PercentData;
    using StyleRareNonInheritedUsageLessThan14PercentData = ComputedStyleBase::StyleRareNonInheritedUsageLessThan14PercentData;
    using StyleInheritedData = ComputedStyleBase::StyleInheritedData;
    using StyleVisualData = ComputedStyleBase::StyleVisualData;
    using StyleSVGData = ComputedStyleBase::StyleSVGData;
    using StyleSurroundData = ComputedStyleBase::StyleSurroundData;
    using StyleBackgroundData = ComputedStyleBase::StyleBackgroundData;
    using StyleBoxData = ComputedStyleBase::StyleBoxData;
    using StyleFontData = ComputedStyleBase::StyleFontData;

    // Storage.
    StyleRareInheritedUsageLessThan64PercentData* rare_inherited_usage_less_than_64_percent_data_;
    StyleRareNonInheritedUsageLessThan14PercentData* rare_non_inherited_usage_less_than_14_percent_data_;
    StyleInheritedData* inherited_data_;
    StyleVisualData* visual_data_;
    StyleSVGData* svg_data_;
    StyleSurroundData* surround_data_;
    StyleBackgroundData* background_data_;
    StyleBoxData* box_data_;
    StyleFontData* font_data_;

    StyleBaseData* base_data_;

    ComputedStyleBase::Data data_;
};

} // namespace blink

namespace blink {
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleBackgroundData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleBoxData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleFillData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleFontData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleForcedColorsData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleGeometryData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleGridData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleHighlightDataData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleInheritedData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleInheritedForcedColorsData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleInheritedResourcesData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleInheritedVisitedData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMasonryData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMathData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleMiscData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleRareInheritedUsageLessThan100PercentData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleRareInheritedUsageLessThan64PercentData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleRareInheritedUsageLessThan64PercentSubData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleRareNonInheritedUsageLessThan100PercentData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleRareNonInheritedUsageLessThan14PercentData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleRareNonInheritedUsageLessThan14PercentSubData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T>
struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleRareNonInheritedUsageLessThan22PercentData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleStartData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleStopData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleStrokeData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleSurroundData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleSVGData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleTimelineData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleVisitedData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleVisualData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase::StyleWillChangeData, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
template <typename T> struct ThreadingTrait<T, std::enable_if_t<std::is_base_of<blink::ComputedStyleBase, T>::value>> {
    static constexpr ThreadAffinity kAffinity = kMainThreadOnly;
};
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_BASE_H_
