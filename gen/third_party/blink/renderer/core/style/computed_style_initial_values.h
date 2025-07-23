// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_INITIAL_VALUES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_INITIAL_VALUES_H_

#include "third_party/blink/renderer/core/style/computed_style_constants.h"
#include "third_party/blink/renderer/core/style/filter_operations.h"
#include "cc/input/scroll_snap_data.h"
#include "third_party/blink/public/common/css/page_orientation.h"
#include "third_party/blink/public/common/css/page_size_type.h"
#include "third_party/blink/public/mojom/frame/color_scheme.mojom-blink.h"
#include "third_party/blink/public/mojom/scroll/scroll_enums.mojom-blink.h"
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
#include "third_party/blink/renderer/core/style/computed_grid_track_list.h"
#include "third_party/blink/renderer/core/style/cursor_list.h"
#include "third_party/blink/renderer/core/style/fill_layer.h"
#include "third_party/blink/renderer/core/style/filter_operations.h"
#include "third_party/blink/renderer/core/style/gap_data_list.h"
#include "third_party/blink/renderer/core/style/grid_position.h"
#include "third_party/blink/renderer/core/style/grid_track_list.h"
#include "third_party/blink/renderer/core/style/list_style_type_data.h"
#include "third_party/blink/renderer/core/style/nine_piece_image.h"
#include "third_party/blink/renderer/core/style/position_area.h"
#include "third_party/blink/renderer/core/style/scroll_start_data.h"
#include "third_party/blink/renderer/core/style/style_anchor_scope.h"
#include "third_party/blink/renderer/core/style/style_aspect_ratio.h"
#include "third_party/blink/renderer/core/style/style_content_alignment_data.h"
#include "third_party/blink/renderer/core/style/style_highlight_data.h"
#include "third_party/blink/renderer/core/style/style_hyphenate_limit_chars.h"
#include "third_party/blink/renderer/core/style/style_initial_letter.h"
#include "third_party/blink/renderer/core/style/style_intrinsic_length.h"
#include "third_party/blink/renderer/core/style/style_offset_rotation.h"
#include "third_party/blink/renderer/core/style/style_overflow_clip_margin.h"
#include "third_party/blink/renderer/core/style/style_self_alignment_data.h"
#include "third_party/blink/renderer/core/style/style_view_transition_group.h"
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
#include "third_party/blink/renderer/platform/text/tab_size.h"
#include "third_party/blink/renderer/platform/text/text_direction.h"
#include "third_party/blink/renderer/platform/text/unicode_bidi.h"
#include "third_party/blink/renderer/platform/text/writing_mode.h"
#include "third_party/blink/renderer/platform/theme_types.h"
#include "third_party/blink/renderer/platform/transforms/transform_operations.h"
#include "third_party/blink/renderer/platform/wtf/hash_set.h"
#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"
#include "ui/gfx/geometry/size_f.h"

namespace blink {

class StyleImage;
class BasicShape;
class CSSAnimationData;
class CSSTransitionData;
class ClipPathOperation;
class ComputedGridTemplateAreas;
class ContentData;
class CounterDirectiveMap;
class OffsetPathOperation;
class PaintImages;
class PositionTryFallbacks;
class QuotesData;
class RotateTransformOperation;
class ScaleTransformOperation;
class ScopedCSSName;
class ScopedCSSNameList;
class ShadowList;
class ShapeValue;
class StyleBaseData;
class StyleImage;
class StyleInheritedVariables;
class StyleInitialData;
class StyleNonInheritedVariables;
class StylePath;
class StyleReflection;
class StyleSVGResource;
class StyleScrollbarColor;
class StyleUAShadowHostData;
class StyleViewTransitionName;
class TranslateTransformOperation;

/**
 * A set of functions that return the initial value for each field on ComputedStyle.
 * This includes both properties defined in css_properties.json5 and the extra
 * fields defined in computed_style_extra_fields.json5.
 */
class ComputedStyleInitialValues {
    STATIC_ONLY(ComputedStyleInitialValues);

public:
    // Hand-written methods.

    static StyleContentAlignmentData InitialContentAlignment()
    {
        return StyleContentAlignmentData(ContentPosition::kNormal, ContentDistributionType::kDefault, OverflowAlignment::kDefault);
    }
    static StyleSelfAlignmentData InitialDefaultAlignment()
    {
        return StyleSelfAlignmentData(ItemPosition::kNormal, OverflowAlignment::kDefault);
    }
    static StyleImage* InitialBorderImageSource()
    {
        return nullptr;
    }
    static float InitialBorderWidth()
    {
        return 3;
    }
    static uint16_t InitialColumnRuleWidth()
    {
        return 3;
    }

    // Grid properties.
    static wtf_size_t InitialGridAutoRepeatInsertionPoint()
    {
        return 0;
    }
    static AutoRepeatType InitialGridAutoRepeatType()
    {
        return AutoRepeatType::kNoAutoRepeat;
    }
    static GridAxisType InitialGridAxisType()
    {
        return GridAxisType::kStandaloneAxis;
    }

    // FIXME: Remove letter-spacing/word-spacing and replace them with respective
    // FontBuilder calls.
    static float InitialWordSpacing()
    {
        return 0.0f;
    }
    static float InitialLetterSpacing()
    {
        return 0.0f;
    }

    static EVerticalAlign InitialVerticalAlign()
    {
        return EVerticalAlign::kBaseline;
    }

    // -webkit-perspective-origin-x
    static Length InitialPerspectiveOriginX()
    {
        return Length::Percent(50.0);
    }

    // -webkit-perspective-origin-y
    static Length InitialPerspectiveOriginY()
    {
        return Length::Percent(50.0);
    }

    // -webkit-transform-origin-x
    static Length InitialTransformOriginX()
    {
        return Length::Percent(50.0);
    }
    // -webkit-transform-origin-y
    static Length InitialTransformOriginY()
    {
        return Length::Percent(50.0);
    }
    // -webkit-transform-origin-z
    static float InitialTransformOriginZ()
    {
        return 0;
    }

    // -webkit-mask-box-image-source
    static StyleImage* InitialMaskBoxImageSource()
    {
        return nullptr;
    }

    static const FilterOperations& InitialFilter()
    {
        return InitialFilterInternal();
    }
    static const FilterOperations& InitialBackdropFilter()
    {
        return InitialFilterInternal();
    }

    // Generated methods below.

    static Vector<AtomicString> InitialColorScheme()
    {
        return Vector<AtomicString, 0>();
    }

    static EForcedColorAdjust InitialForcedColorAdjust()
    {
        return EForcedColorAdjust::kAuto;
    }

    static short InitialMathDepth()
    {
        return 0;
    }

    static EPosition InitialPosition()
    {
        return EPosition::kStatic;
    }

    static ScopedCSSName* InitialPositionAnchor()
    {
        return nullptr;
    }

    static TextSizeAdjust InitialTextSizeAdjust()
    {
        return TextSizeAdjust::AdjustAuto();
    }

    static ControlPart InitialAppearance()
    {
        return kNoControlPart;
    }

    static StyleColor InitialColor()
    {
        return StyleColor(Color::kBlack);
    }

    static TextDirection InitialDirection()
    {
        return TextDirection::kLtr;
    }

    static StyleColor InitialInternalVisitedColor()
    {
        return StyleColor(Color::kBlack);
    }

    static PositionArea InitialPositionArea()
    {
        return PositionArea();
    }

    static ETextOrientation InitialTextOrientation()
    {
        return ETextOrientation::kMixed;
    }

    static WritingMode InitialWritingMode()
    {
        return WritingMode::kHorizontalTb;
    }

    static float InitialZoom()
    {
        return 1.0;
    }

    static StyleAutoColor InitialAccentColor()
    {
        return StyleAutoColor::AutoColor();
    }

    static StyleContentAlignmentData InitialAlignContent()
    {
        return StyleContentAlignmentData(ContentPosition::kNormal, ContentDistributionType::kDefault, OverflowAlignment::kDefault);
    }

    static StyleSelfAlignmentData InitialAlignItems()
    {
        return StyleSelfAlignmentData(ItemPosition::kNormal, OverflowAlignment::kDefault);
    }

    static StyleSelfAlignmentData InitialAlignSelf()
    {
        return StyleSelfAlignmentData(ItemPosition::kAuto, OverflowAlignment::kDefault);
    }

    static EAlignmentBaseline InitialAlignmentBaseline()
    {
        return EAlignmentBaseline::kAuto;
    }

    static ScopedCSSNameList* InitialAnchorName()
    {
        return nullptr;
    }

    static StyleAnchorScope InitialAnchorScope()
    {
        return StyleAnchorScope();
    }

    static EDraggableRegionMode InitialDraggableRegionMode()
    {
        return EDraggableRegionMode::kNone;
    }

    static StyleAspectRatio InitialAspectRatio()
    {
        return StyleAspectRatio(EAspectRatioType::kAuto, gfx::SizeF());
    }

    static EBackfaceVisibility InitialBackfaceVisibility()
    {
        return EBackfaceVisibility::kVisible;
    }

    static StyleColor InitialBackgroundColor()
    {
        return StyleColor(Color::kTransparent);
    }

    static Length InitialBaselineShift()
    {
        return Length::Fixed();
    }

    static EBaselineSource InitialBaselineSource()
    {
        return EBaselineSource::kAuto;
    }

    static StyleColor InitialBorderBottomColor()
    {
        return StyleColor::CurrentColor();
    }

    static LengthSize InitialBorderBottomLeftRadius()
    {
        return LengthSize(Length::Fixed(0), Length::Fixed(0));
    }

    static LengthSize InitialBorderBottomRightRadius()
    {
        return LengthSize(Length::Fixed(0), Length::Fixed(0));
    }

    static EBorderStyle InitialBorderBottomStyle()
    {
        return EBorderStyle::kNone;
    }

    static int InitialBorderBottomWidth()
    {
        return 3;
    }

    static EBorderCollapse InitialBorderCollapse()
    {
        return EBorderCollapse::kSeparate;
    }

    static StyleColor InitialBorderLeftColor()
    {
        return StyleColor::CurrentColor();
    }

    static EBorderStyle InitialBorderLeftStyle()
    {
        return EBorderStyle::kNone;
    }

    static int InitialBorderLeftWidth()
    {
        return 3;
    }

    static StyleColor InitialBorderRightColor()
    {
        return StyleColor::CurrentColor();
    }

    static EBorderStyle InitialBorderRightStyle()
    {
        return EBorderStyle::kNone;
    }

    static int InitialBorderRightWidth()
    {
        return 3;
    }

    static StyleColor InitialBorderTopColor()
    {
        return StyleColor::CurrentColor();
    }

    static LengthSize InitialBorderTopLeftRadius()
    {
        return LengthSize(Length::Fixed(0), Length::Fixed(0));
    }

    static LengthSize InitialBorderTopRightRadius()
    {
        return LengthSize(Length::Fixed(0), Length::Fixed(0));
    }

    static EBorderStyle InitialBorderTopStyle()
    {
        return EBorderStyle::kNone;
    }

    static int InitialBorderTopWidth()
    {
        return 3;
    }

    static Length InitialBottom()
    {
        return Length();
    }

    static EBoxDecorationBreak InitialBoxDecorationBreak()
    {
        return EBoxDecorationBreak::kSlice;
    }

    static ShadowList* InitialBoxShadow()
    {
        return nullptr;
    }

    static EBoxSizing InitialBoxSizing()
    {
        return EBoxSizing::kContentBox;
    }

    static EBreakBetween InitialBreakAfter()
    {
        return EBreakBetween::kAuto;
    }

    static EBreakBetween InitialBreakBefore()
    {
        return EBreakBetween::kAuto;
    }

    static EBreakInside InitialBreakInside()
    {
        return EBreakInside::kAuto;
    }

    static EBufferedRendering InitialBufferedRendering()
    {
        return EBufferedRendering::kAuto;
    }

    static ECaptionSide InitialCaptionSide()
    {
        return ECaptionSide::kTop;
    }

    static ECaretAnimation InitialCaretAnimation()
    {
        return ECaretAnimation::kAuto;
    }

    static StyleAutoColor InitialCaretColor()
    {
        return StyleAutoColor::AutoColor();
    }

    static EClear InitialClear()
    {
        return EClear::kNone;
    }

    static LengthBox InitialClip()
    {
        return LengthBox();
    }

    static ClipPathOperation* InitialClipPath()
    {
        return nullptr;
    }

    static WindRule InitialClipRule()
    {
        return RULE_NONZERO;
    }

    static EColorInterpolation InitialColorInterpolation()
    {
        return EColorInterpolation::kSRGB;
    }

    static EColorInterpolation InitialColorInterpolationFilters()
    {
        return EColorInterpolation::kLinearrgb;
    }

    static EColorRendering InitialColorRendering()
    {
        return EColorRendering::kAuto;
    }

    static unsigned short InitialColumnCount()
    {
        return 1;
    }

    static EColumnFill InitialColumnFill()
    {
        return EColumnFill::kBalance;
    }

    static std::optional<Length> InitialColumnGap()
    {
        return std::nullopt;
    }

    static GapDataList<StyleColor> InitialColumnRuleColor()
    {
        return GapDataList<StyleColor>::DefaultGapColorDataList();
    }

    static EBorderStyle InitialColumnRuleStyle()
    {
        return EBorderStyle::kNone;
    }

    static EColumnSpan InitialColumnSpan()
    {
        return EColumnSpan::kNone;
    }

    static float InitialColumnWidth()
    {
        return 0.0f;
    }

    static unsigned InitialContain()
    {
        return kContainsNone;
    }

    static StyleIntrinsicLength InitialContainIntrinsicHeight()
    {
        return StyleIntrinsicLength();
    }

    static StyleIntrinsicLength InitialContainIntrinsicWidth()
    {
        return StyleIntrinsicLength();
    }

    static ScopedCSSNameList* InitialContainerName()
    {
        return nullptr;
    }

    static unsigned InitialContainerType()
    {
        return kContainerTypeNormal;
    }

    static ContentData* InitialContent()
    {
        return nullptr;
    }

    static EContentVisibility InitialContentVisibility()
    {
        return EContentVisibility::kVisible;
    }

    static ECursor InitialCursor()
    {
        return ECursor::kAuto;
    }

    static Length InitialCx()
    {
        return Length::Fixed();
    }

    static Length InitialCy()
    {
        return Length::Fixed();
    }

    static StylePath* InitialD()
    {
        return nullptr;
    }

    static EDominantBaseline InitialDominantBaseline()
    {
        return EDominantBaseline::kAuto;
    }

    static DynamicRangeLimit InitialDynamicRangeLimit()
    {
        return DynamicRangeLimit(cc::PaintFlags::DynamicRangeLimit::kHigh);
    }

    static EEmptyCells InitialEmptyCells()
    {
        return EEmptyCells::kShow;
    }

    static EFieldSizing InitialFieldSizing()
    {
        return EFieldSizing::kFixed;
    }

    static SVGPaint InitialFillPaint()
    {
        return SVGPaint(Color::kBlack);
    }

    static float InitialFillOpacity()
    {
        return 1;
    }

    static WindRule InitialFillRule()
    {
        return RULE_NONZERO;
    }

    static Length InitialFlexBasis()
    {
        return Length::Auto();
    }

    static EFlexDirection InitialFlexDirection()
    {
        return EFlexDirection::kRow;
    }

    static float InitialFlexGrow()
    {
        return 0.0f;
    }

    static float InitialFlexShrink()
    {
        return 1.0f;
    }

    static EFlexWrap InitialFlexWrap()
    {
        return EFlexWrap::kNowrap;
    }

    static EFloat InitialFloating()
    {
        return EFloat::kNone;
    }

    static StyleColor InitialFloodColor()
    {
        return StyleColor(Color::kBlack);
    }

    static float InitialFloodOpacity()
    {
        return 1;
    }

    static NGGridTrackList InitialGridAutoColumns()
    {
        return NGGridTrackList(GridTrackSize(Length::Auto()));
    }

    static GridAutoFlow InitialGridAutoFlow()
    {
        return kAutoFlowRow;
    }

    static NGGridTrackList InitialGridAutoRows()
    {
        return NGGridTrackList(GridTrackSize(Length::Auto()));
    }

    static GridPosition InitialGridColumnEnd()
    {
        return GridPosition();
    }

    static GridPosition InitialGridColumnStart()
    {
        return GridPosition();
    }

    static GridPosition InitialGridRowEnd()
    {
        return GridPosition();
    }

    static GridPosition InitialGridRowStart()
    {
        return GridPosition();
    }

    static ComputedGridTemplateAreas* InitialGridTemplateAreas()
    {
        return nullptr;
    }

    static ComputedGridTrackList InitialGridTemplateColumns()
    {
        return ComputedGridTrackList();
    }

    static ComputedGridTrackList InitialGridTemplateRows()
    {
        return ComputedGridTrackList();
    }

    static Length InitialHeight()
    {
        return Length();
    }

    static AtomicString InitialHyphenationString()
    {
        return AtomicString();
    }

    static StyleHyphenateLimitChars InitialHyphenateLimitChars()
    {
        return StyleHyphenateLimitChars();
    }

    static Hyphens InitialHyphens()
    {
        return Hyphens::kManual;
    }

    static RespectImageOrientationEnum InitialImageOrientation()
    {
        return kRespectImageOrientation;
    }

    static EImageRendering InitialImageRendering()
    {
        return EImageRendering::kAuto;
    }

    static StyleInitialLetter InitialInitialLetter()
    {
        return StyleInitialLetter();
    }

    static EInteractivity InitialInteractivity()
    {
        return EInteractivity::kAuto;
    }

    static bool InitialAlignContentBlockCenter()
    {
        return false;
    }

    static bool InitialHasLineIfEmpty()
    {
        return false;
    }

    static StyleColor InitialInternalForcedBackgroundColor()
    {
        return StyleColor(CSSValueID::kCanvas);
    }

    static StyleColor InitialInternalForcedBorderColor()
    {
        return StyleColor::CurrentColor();
    }

    static StyleColor InitialInternalForcedColor()
    {
        return StyleColor(CSSValueID::kCanvastext);
    }

    static StyleColor InitialInternalForcedOutlineColor()
    {
        return StyleColor::CurrentColor();
    }

    static StyleColor InitialInternalForcedVisitedColor()
    {
        return StyleColor(CSSValueID::kCanvastext);
    }

    static StyleColor InitialInternalVisitedBackgroundColor()
    {
        return StyleColor(Color::kTransparent);
    }

    static StyleColor InitialInternalVisitedBorderBottomColor()
    {
        return StyleColor::CurrentColor();
    }

    static StyleColor InitialInternalVisitedBorderLeftColor()
    {
        return StyleColor::CurrentColor();
    }

    static StyleColor InitialInternalVisitedBorderRightColor()
    {
        return StyleColor::CurrentColor();
    }

    static StyleColor InitialInternalVisitedBorderTopColor()
    {
        return StyleColor::CurrentColor();
    }

    static StyleAutoColor InitialInternalVisitedCaretColor()
    {
        return StyleAutoColor::AutoColor();
    }

    static GapDataList<StyleColor> InitialInternalVisitedColumnRuleColor()
    {
        return GapDataList<StyleColor>::DefaultGapColorDataList();
    }

    static SVGPaint InitialInternalVisitedFillPaint()
    {
        return SVGPaint(Color::kBlack);
    }

    static StyleColor InitialInternalVisitedOutlineColor()
    {
        return StyleColor::CurrentColor();
    }

    static SVGPaint InitialInternalVisitedStrokePaint()
    {
        return SVGPaint();
    }

    static StyleColor InitialInternalVisitedTextDecorationColor()
    {
        return StyleColor::CurrentColor();
    }

    static StyleColor InitialInternalVisitedTextEmphasisColor()
    {
        return StyleColor::CurrentColor();
    }

    static StyleColor InitialInternalVisitedTextFillColor()
    {
        return StyleColor::CurrentColor();
    }

    static StyleColor InitialInternalVisitedTextStrokeColor()
    {
        return StyleColor::CurrentColor();
    }

    static EInterpolateSize InitialInterpolateSize()
    {
        return EInterpolateSize::kNumericOnly;
    }

    static EIsolation InitialIsolation()
    {
        return EIsolation::kAuto;
    }

    static StyleContentAlignmentData InitialJustifyContent()
    {
        return StyleContentAlignmentData(ContentPosition::kNormal, ContentDistributionType::kDefault, OverflowAlignment::kDefault);
    }

    static StyleSelfAlignmentData InitialJustifyItems()
    {
        return StyleSelfAlignmentData(ItemPosition::kLegacy, OverflowAlignment::kDefault);
    }

    static StyleSelfAlignmentData InitialJustifySelf()
    {
        return StyleSelfAlignmentData(ItemPosition::kAuto, OverflowAlignment::kDefault);
    }

    static Length InitialLeft()
    {
        return Length();
    }

    static StyleColor InitialLightingColor()
    {
        return StyleColor(Color::kWhite);
    }

    static int InitialStandardLineClamp()
    {
        return 0;
    }

    static Length InitialLineHeight()
    {
        return Length::Auto();
    }

    static StyleImage* InitialListStyleImage()
    {
        return nullptr;
    }

    static EListStylePosition InitialListStylePosition()
    {
        return EListStylePosition::kOutside;
    }

    static ListStyleTypeData* InitialListStyleType()
    {
        return ListStyleTypeData::CreateCounterStyle(keywords::kDisc, nullptr);
    }

    static Length InitialMarginBottom()
    {
        return Length::Fixed();
    }

    static Length InitialMarginLeft()
    {
        return Length::Fixed();
    }

    static Length InitialMarginRight()
    {
        return Length::Fixed();
    }

    static Length InitialMarginTop()
    {
        return Length::Fixed();
    }

    static StyleSVGResource* InitialMarkerEndResource()
    {
        return nullptr;
    }

    static StyleSVGResource* InitialMarkerMidResource()
    {
        return nullptr;
    }

    static StyleSVGResource* InitialMarkerStartResource()
    {
        return nullptr;
    }

    static EMaskType InitialMaskType()
    {
        return EMaskType::kLuminance;
    }

    static std::optional<Length> InitialMasonrySlack()
    {
        return std::nullopt;
    }

    static ComputedGridTrackList InitialMasonryTemplateTracks()
    {
        return ComputedGridTrackList::DefaultMasonryTrackList();
    }

    static GridPosition InitialMasonryTrackEnd()
    {
        return GridPosition();
    }

    static GridPosition InitialMasonryTrackStart()
    {
        return GridPosition();
    }

    static EMathShift InitialMathShift()
    {
        return EMathShift::kNormal;
    }

    static EMathStyle InitialMathStyle()
    {
        return EMathStyle::kNormal;
    }

    static Length InitialMaxHeight()
    {
        return Length::None();
    }

    static Length InitialMaxWidth()
    {
        return Length::None();
    }

    static Length InitialMinHeight()
    {
        return Length();
    }

    static Length InitialMinWidth()
    {
        return Length();
    }

    static BlendMode InitialBlendMode()
    {
        return BlendMode::kNormal;
    }

    static EObjectFit InitialObjectFit()
    {
        return EObjectFit::kFill;
    }

    static LengthPoint InitialObjectPosition()
    {
        return LengthPoint(Length::Percent(50.0), Length::Percent(50.0));
    }

    static BasicShape* InitialObjectViewBox()
    {
        return nullptr;
    }

    static LengthPoint InitialOffsetAnchor()
    {
        return LengthPoint(Length::Auto(), Length::Auto());
    }

    static Length InitialOffsetDistance()
    {
        return Length::Fixed(0);
    }

    static OffsetPathOperation* InitialOffsetPath()
    {
        return nullptr;
    }

    static LengthPoint InitialOffsetPosition()
    {
        return LengthPoint(Length::None(), Length::None());
    }

    static StyleOffsetRotation InitialOffsetRotate()
    {
        return StyleOffsetRotation(0, OffsetRotationType::kAuto);
    }

    static float InitialOpacity()
    {
        return 1.0;
    }

    static int InitialOrder()
    {
        return 0;
    }

    static EOriginTrialTestProperty InitialOriginTrialTestProperty()
    {
        return EOriginTrialTestProperty::kNormal;
    }

    static short InitialOrphans()
    {
        return 2;
    }

    static StyleColor InitialOutlineColor()
    {
        return StyleColor::CurrentColor();
    }

    static LayoutUnit InitialOutlineOffset()
    {
        return LayoutUnit();
    }

    static EBorderStyle InitialOutlineStyle()
    {
        return EBorderStyle::kNone;
    }

    static int InitialOutlineWidth()
    {
        return 3;
    }

    static EOverflowAnchor InitialOverflowAnchor()
    {
        return EOverflowAnchor::kAuto;
    }

    static std::optional<StyleOverflowClipMargin> InitialOverflowClipMargin()
    {
        return std::nullopt;
    }

    static EOverflowWrap InitialOverflowWrap()
    {
        return EOverflowWrap::kNormal;
    }

    static EOverflow InitialOverflowX()
    {
        return EOverflow::kVisible;
    }

    static EOverflow InitialOverflowY()
    {
        return EOverflow::kVisible;
    }

    static EOverlay InitialOverlay()
    {
        return EOverlay::kNone;
    }

    static EOverscrollBehavior InitialOverscrollBehaviorX()
    {
        return EOverscrollBehavior::kAuto;
    }

    static EOverscrollBehavior InitialOverscrollBehaviorY()
    {
        return EOverscrollBehavior::kAuto;
    }

    static Length InitialPaddingBottom()
    {
        return Length::Fixed();
    }

    static Length InitialPaddingLeft()
    {
        return Length::Fixed();
    }

    static Length InitialPaddingRight()
    {
        return Length::Fixed();
    }

    static Length InitialPaddingTop()
    {
        return Length::Fixed();
    }

    static AtomicString InitialPage()
    {
        return AtomicString();
    }

    static PageOrientation InitialPageOrientation()
    {
        return PageOrientation::kUpright;
    }

    static EPaintOrder InitialPaintOrder()
    {
        return kPaintOrderNormal;
    }

    static float InitialPerspective()
    {
        return -1.0;
    }

    static LengthPoint InitialPerspectiveOrigin()
    {
        return LengthPoint(Length::Percent(50.0), Length::Percent(50.0));
    }

    static EPointerEvents InitialPointerEvents()
    {
        return EPointerEvents::kAuto;
    }

    static float InitialPopoverHideDelay()
    {
        return HUGE_VALF;
    }

    static float InitialPopoverShowDelay()
    {
        return 0.5;
    }

    static PositionTryFallbacks* InitialPositionTryFallbacks()
    {
        return nullptr;
    }

    static EPositionTryOrder InitialPositionTryOrder()
    {
        return EPositionTryOrder::kNormal;
    }

    static PositionVisibility InitialPositionVisibility()
    {
        return PositionVisibility::kAlways;
    }

    static QuotesData* InitialQuotes()
    {
        return nullptr;
    }

    static Length InitialR()
    {
        return Length::Fixed();
    }

    static EReadingFlow InitialReadingFlow()
    {
        return EReadingFlow::kNormal;
    }

    static EResize InitialResize()
    {
        return EResize::kNone;
    }

    static Length InitialRight()
    {
        return Length();
    }

    static RotateTransformOperation* InitialRotate()
    {
        return nullptr;
    }

    static std::optional<Length> InitialRowGap()
    {
        return std::nullopt;
    }

    static ERubyAlign InitialRubyAlign()
    {
        return ERubyAlign::kSpaceAround;
    }

    static RubyPosition InitialRubyPosition()
    {
        return RubyPosition::kOver;
    }

    static Length InitialRx()
    {
        return Length::Auto();
    }

    static Length InitialRy()
    {
        return Length::Auto();
    }

    static ScaleTransformOperation* InitialScale()
    {
        return nullptr;
    }

    static mojom::blink::ScrollBehavior InitialScrollBehavior()
    {
        return mojom::blink::ScrollBehavior::kAuto;
    }

    static float InitialScrollMarginBottom()
    {
        return 0.0f;
    }

    static float InitialScrollMarginLeft()
    {
        return 0.0f;
    }

    static float InitialScrollMarginRight()
    {
        return 0.0f;
    }

    static float InitialScrollMarginTop()
    {
        return 0.0f;
    }

    static EScrollMarkerGroup InitialScrollMarkerGroup()
    {
        return EScrollMarkerGroup::kNone;
    }

    static Length InitialScrollPaddingBottom()
    {
        return Length();
    }

    static Length InitialScrollPaddingLeft()
    {
        return Length();
    }

    static Length InitialScrollPaddingRight()
    {
        return Length();
    }

    static Length InitialScrollPaddingTop()
    {
        return Length();
    }

    static cc::ScrollSnapAlign InitialScrollSnapAlign()
    {
        return cc::ScrollSnapAlign();
    }

    static EScrollSnapStop InitialScrollSnapStop()
    {
        return EScrollSnapStop::kNormal;
    }

    static cc::ScrollSnapType InitialScrollSnapType()
    {
        return cc::ScrollSnapType();
    }

    static EScrollStartTarget InitialScrollStartTarget()
    {
        return EScrollStartTarget::kNone;
    }

    static ScrollStartData InitialScrollStartX()
    {
        return blink::ScrollStartData();
    }

    static ScrollStartData InitialScrollStartY()
    {
        return blink::ScrollStartData();
    }

    static Vector<TimelineAxis> InitialScrollTimelineAxis()
    {
        return Vector<TimelineAxis>();
    }

    static ScopedCSSNameList* InitialScrollTimelineName()
    {
        return nullptr;
    }

    static StyleScrollbarColor* InitialScrollbarColor()
    {
        return nullptr;
    }

    static unsigned InitialScrollbarGutter()
    {
        return kScrollbarGutterAuto;
    }

    static EScrollbarWidth InitialScrollbarWidth()
    {
        return EScrollbarWidth::kAuto;
    }

    static float InitialShapeImageThreshold()
    {
        return 0.0;
    }

    static Length InitialShapeMargin()
    {
        return Length::Fixed(0);
    }

    static ShapeValue* InitialShapeOutside()
    {
        return nullptr;
    }

    static EShapeRendering InitialShapeRendering()
    {
        return EShapeRendering::kAuto;
    }

    static ESpeak InitialSpeak()
    {
        return ESpeak::kNormal;
    }

    static StyleColor InitialStopColor()
    {
        return StyleColor(Color::kBlack);
    }

    static float InitialStopOpacity()
    {
        return 1;
    }

    static SVGPaint InitialStrokePaint()
    {
        return SVGPaint();
    }

    static SVGDashArray* InitialStrokeDashArray()
    {
        return EmptyDashArray();
    }

    static Length InitialStrokeDashOffset()
    {
        return Length::Fixed();
    }

    static LineCap InitialCapStyle()
    {
        return kButtCap;
    }

    static LineJoin InitialJoinStyle()
    {
        return kMiterJoin;
    }

    static float InitialStrokeMiterLimit()
    {
        return 4;
    }

    static float InitialStrokeOpacity()
    {
        return 1;
    }

    static UnzoomedLength InitialStrokeWidth()
    {
        return UnzoomedLength(Length::Fixed(1));
    }

    static TabSize InitialTabSize()
    {
        return TabSize(8);
    }

    static ETableLayout InitialTableLayout()
    {
        return ETableLayout::kAuto;
    }

    static ETextAlign InitialTextAlign()
    {
        return ETextAlign::kStart;
    }

    static ETextAlignLast InitialTextAlignLast()
    {
        return ETextAlignLast::kAuto;
    }

    static ETextAnchor InitialTextAnchor()
    {
        return ETextAnchor::kStart;
    }

    static ETextAutospace InitialTextAutospace()
    {
        return ETextAutospace::kNormal;
    }

    static TextBoxEdge InitialTextBoxEdge()
    {
        return TextBoxEdge();
    }

    static ETextBoxTrim InitialTextBoxTrim()
    {
        return ETextBoxTrim::kNone;
    }

    static ETextCombine InitialTextCombine()
    {
        return ETextCombine::kNone;
    }

    static StyleColor InitialTextDecorationColor()
    {
        return StyleColor::CurrentColor();
    }

    static TextDecorationLine InitialTextDecorationLine()
    {
        return TextDecorationLine::kNone;
    }

    static ETextDecorationSkipInk InitialTextDecorationSkipInk()
    {
        return ETextDecorationSkipInk::kAuto;
    }

    static ETextDecorationStyle InitialTextDecorationStyle()
    {
        return ETextDecorationStyle::kSolid;
    }

    static TextDecorationThickness InitialTextDecorationThickness()
    {
        return TextDecorationThickness(Length::Auto());
    }

    static StyleColor InitialTextEmphasisColor()
    {
        return StyleColor::CurrentColor();
    }

    static TextEmphasisPosition InitialTextEmphasisPosition()
    {
        return TextEmphasisPosition::kOverRight;
    }

    static Length InitialTextIndent()
    {
        return Length::Fixed();
    }

    static ETextOverflow InitialTextOverflow()
    {
        return ETextOverflow::kClip;
    }

    static ShadowList* InitialTextShadow()
    {
        return nullptr;
    }

    static ETextTransform InitialTextTransform()
    {
        return ETextTransform::kNone;
    }

    static Length InitialTextUnderlineOffset()
    {
        return Length();
    }

    static TextUnderlinePosition InitialTextUnderlinePosition()
    {
        return TextUnderlinePosition::kAuto;
    }

    static TextWrapMode InitialTextWrapMode()
    {
        return TextWrapMode::kWrap;
    }

    static TextWrapStyle InitialTextWrapStyle()
    {
        return TextWrapStyle::kAuto;
    }

    static ScopedCSSNameList* InitialTimelineScope()
    {
        return nullptr;
    }

    static Length InitialTop()
    {
        return Length();
    }

    static TouchAction InitialTouchAction()
    {
        return TouchAction::kAuto;
    }

    static TransformOperations InitialTransform()
    {
        return EmptyTransformOperations();
    }

    static ETransformBox InitialTransformBox()
    {
        return ETransformBox::kViewBox;
    }

    static TransformOrigin InitialTransformOrigin()
    {
        return TransformOrigin(Length::Percent(50.0), Length::Percent(50.0), 0);
    }

    static ETransformStyle3D InitialTransformStyle3D()
    {
        return ETransformStyle3D::kFlat;
    }

    static TranslateTransformOperation* InitialTranslate()
    {
        return nullptr;
    }

    static UnicodeBidi InitialUnicodeBidi()
    {
        return UnicodeBidi::kNormal;
    }

    static EUserSelect InitialUserSelect()
    {
        return EUserSelect::kAuto;
    }

    static EVectorEffect InitialVectorEffect()
    {
        return EVectorEffect::kNone;
    }

    static Vector<TimelineAxis> InitialViewTimelineAxis()
    {
        return Vector<TimelineAxis>();
    }

    static Vector<TimelineInset> InitialViewTimelineInset()
    {
        return Vector<TimelineInset>();
    }

    static ScopedCSSNameList* InitialViewTimelineName()
    {
        return nullptr;
    }

    static StyleViewTransitionCaptureMode InitialViewTransitionCaptureMode()
    {
        return StyleViewTransitionCaptureMode::kLayered;
    }

    static ScopedCSSNameList* InitialViewTransitionClass()
    {
        return nullptr;
    }

    static StyleViewTransitionGroup InitialViewTransitionGroup()
    {
        return StyleViewTransitionGroup::Normal();
    }

    static StyleViewTransitionName* InitialViewTransitionName()
    {
        return nullptr;
    }

    static EVisibility InitialVisibility()
    {
        return EVisibility::kVisible;
    }

    static short InitialHorizontalBorderSpacing()
    {
        return 0;
    }

    static short InitialVerticalBorderSpacing()
    {
        return 0;
    }

    static EBoxAlignment InitialBoxAlign()
    {
        return EBoxAlignment::kStretch;
    }

    static EBoxDirection InitialBoxDirection()
    {
        return EBoxDirection::kNormal;
    }

    static float InitialBoxFlex()
    {
        return 0.0f;
    }

    static unsigned InitialBoxOrdinalGroup()
    {
        return 1;
    }

    static EBoxOrient InitialBoxOrient()
    {
        return EBoxOrient::kHorizontal;
    }

    static EBoxPack InitialBoxPack()
    {
        return EBoxPack::kStart;
    }

    static StyleReflection* InitialBoxReflect()
    {
        return nullptr;
    }

    static LineBreak InitialLineBreak()
    {
        return LineBreak::kAuto;
    }

    static int InitialWebkitLineClamp()
    {
        return 0;
    }

    static EPrintColorAdjust InitialPrintColorAdjust()
    {
        return EPrintColorAdjust::kEconomy;
    }

    static EOrder InitialRtlOrdering()
    {
        return EOrder::kLogical;
    }

    static StyleColor InitialTapHighlightColor()
    {
        return StyleColor(LayoutTheme::TapHighlightColor());
    }

    static StyleColor InitialTextFillColor()
    {
        return StyleColor::CurrentColor();
    }

    static ETextSecurity InitialTextSecurity()
    {
        return ETextSecurity::kNone;
    }

    static StyleColor InitialTextStrokeColor()
    {
        return StyleColor::CurrentColor();
    }

    static float InitialTextStrokeWidth()
    {
        return 0;
    }

    static EUserDrag InitialUserDrag()
    {
        return EUserDrag::kAuto;
    }

    static EUserModify InitialUserModify()
    {
        return EUserModify::kReadOnly;
    }

    static WhiteSpaceCollapse InitialWhiteSpaceCollapse()
    {
        return WhiteSpaceCollapse::kCollapse;
    }

    static short InitialWidows()
    {
        return 2;
    }

    static Length InitialWidth()
    {
        return Length();
    }

    static EWordBreak InitialWordBreak()
    {
        return EWordBreak::kNormal;
    }

    static Length InitialX()
    {
        return Length::Fixed();
    }

    static Length InitialY()
    {
        return Length::Fixed();
    }

    static int InitialZIndex()
    {
        return 0;
    }

    static EDisplay InitialDisplay()
    {
        return EDisplay::kInline;
    }

    static AtomicString InitialDisplayLayoutCustomName()
    {
        return g_null_atom;
    }

    static AtomicString InitialDisplayLayoutCustomParentName()
    {
        return g_null_atom;
    }

    static bool InitialIsOriginalDisplayInlineType()
    {
        return true;
    }

    static EInsideLink InitialInsideLink()
    {
        return EInsideLink::kNotInsideLink;
    }

    static bool InitialInForcedColorsMode()
    {
        return false;
    }

    static unsigned InitialViewportUnitFlags()
    {
        return 0;
    }

    static PseudoId InitialStyleType()
    {
        return PseudoId::kPseudoIdNone;
    }

    static unsigned InitialPseudoElementStyles()
    {
        return kPseudoIdNone;
    }

    static bool InitialHasNonUniversalHighlightPseudoStyles()
    {
        return false;
    }

    static bool InitialHasNonUaHighlightPseudoStyles()
    {
        return false;
    }

    static bool InitialHighlightsDependOnSizeContainerQueries()
    {
        return false;
    }

    static AtomicString InitialPseudoArgument()
    {
        return g_null_atom;
    }

    static HashSet<AtomicString>* InitialCustomHighlightNames()
    {
        return nullptr;
    }

    static Length InitialVerticalAlignLength()
    {
        return Length();
    }

    static NinePieceImage InitialBorderImage()
    {
        return NinePieceImage();
    }

    static bool InitialHasClipPath()
    {
        return false;
    }

    static bool InitialHasAutoClip()
    {
        return true;
    }

    static bool InitialHasAutoZIndex()
    {
        return true;
    }

    static bool InitialHasAutoStandardLineClamp()
    {
        return false;
    }

    static Font InitialFont()
    {
        return Font();
    }

    static float InitialTextAutosizingMultiplier()
    {
        return 1.0;
    }

    static CursorList* InitialCursorData()
    {
        return nullptr;
    }

    static float InitialEffectiveZoom()
    {
        return 1.0f;
    }

    static TextEmphasisFill InitialTextEmphasisFill()
    {
        return TextEmphasisFill::kFilled;
    }

    static TextEmphasisMark InitialTextEmphasisMark()
    {
        return TextEmphasisMark::kNone;
    }

    static bool InitialSubtreeWillChangeContents()
    {
        return false;
    }

    static bool InitialSubtreeIsSticky()
    {
        return false;
    }

    static TouchAction InitialEffectiveTouchAction()
    {
        return TouchAction::kAuto;
    }

    static ControlPart InitialEffectiveAppearance()
    {
        return kNoControlPart;
    }

    static AtomicString InitialTextEmphasisCustomMark()
    {
        return AtomicString();
    }

    static base::RefCountedData<Vector<AppliedTextDecoration, 1>>* InitialBaseTextDecorationData()
    {
        return nullptr;
    }

    static StyleInheritedVariables* InitialInheritedVariables()
    {
        return nullptr;
    }

    static StyleHighlightData InitialHighlightData()
    {
        return StyleHighlightData();
    }

    static StyleInitialData* InitialInitialData()
    {
        return nullptr;
    }

    static CounterDirectiveMap* InitialCounterDirectives()
    {
        return nullptr;
    }

    static CSSAnimationData* InitialAnimations()
    {
        return nullptr;
    }

    static CSSTransitionData* InitialTransitions()
    {
        return nullptr;
    }

    static NinePieceImage InitialMaskBoxImage()
    {
        return NinePieceImage::MaskDefaults();
    }

    static gfx::SizeF InitialPageSize()
    {
        return gfx::SizeF();
    }

    static bool InitialOutlineStyleIsAuto()
    {
        return false;
    }

    static Vector<String> InitialCallbackSelectors()
    {
        return Vector<String>();
    }

    static HeapHashSet<WeakMember<StyleRule>>* InitialDocumentRulesSelectors()
    {
        return nullptr;
    }

    static PaintImages* InitialPaintImages()
    {
        return nullptr;
    }

    static StyleNonInheritedVariables* InitialNonInheritedVariables()
    {
        return nullptr;
    }

    static PageSizeType InitialPageSizeType()
    {
        return PageSizeType::kAuto;
    }

    static bool InitialHasCurrentOpacityAnimation()
    {
        return false;
    }

    static bool InitialHasCurrentTranslateAnimation()
    {
        return false;
    }

    static bool InitialHasCurrentRotateAnimation()
    {
        return false;
    }

    static bool InitialHasCurrentScaleAnimation()
    {
        return false;
    }

    static bool InitialHasCurrentTransformAnimation()
    {
        return false;
    }

    static bool InitialHasCurrentFilterAnimation()
    {
        return false;
    }

    static bool InitialHasCurrentBackdropFilterAnimation()
    {
        return false;
    }

    static bool InitialHasCurrentBackgroundColorAnimation()
    {
        return false;
    }

    static bool InitialIsRunningOpacityAnimationOnCompositor()
    {
        return false;
    }

    static bool InitialIsRunningTransformAnimationOnCompositor()
    {
        return false;
    }

    static bool InitialIsRunningScaleAnimationOnCompositor()
    {
        return false;
    }

    static bool InitialIsRunningRotateAnimationOnCompositor()
    {
        return false;
    }

    static bool InitialIsRunningTranslateAnimationOnCompositor()
    {
        return false;
    }

    static bool InitialIsRunningFilterAnimationOnCompositor()
    {
        return false;
    }

    static bool InitialIsRunningBackdropFilterAnimationOnCompositor()
    {
        return false;
    }

    static bool InitialForcesStackingContext()
    {
        return false;
    }

    static bool InitialRequiresAcceleratedCompositingForExternalReasons()
    {
        return false;
    }

    static bool InitialColorIsCurrentColor()
    {
        return true;
    }

    static bool InitialInternalVisitedColorIsCurrentColor()
    {
        return true;
    }

    static Vector<CSSPropertyID> InitialWillChangeProperties()
    {
        return Vector<CSSPropertyID>();
    }

    static bool InitialWillChangeContents()
    {
        return false;
    }

    static bool InitialWillChangeScrollPosition()
    {
        return false;
    }

    static bool InitialHasAutoColumnWidth()
    {
        return true;
    }

    static bool InitialHasAutoColumnCount()
    {
        return true;
    }

    static bool InitialDarkColorScheme()
    {
        return false;
    }

    static bool InitialColorSchemeFlagsIsNormal()
    {
        return false;
    }

    static bool InitialColorSchemeForced()
    {
        return false;
    }

    static EInlineBlockBaselineEdge InitialInlineBlockBaselineEdge()
    {
        return EInlineBlockBaselineEdge::kMarginBox;
    }

    static Length InitialMathBaseline()
    {
        return Length();
    }

    static Length InitialMathFractionBarThickness()
    {
        return Length();
    }

    static Length InitialMathLSpace()
    {
        return Length();
    }

    static Length InitialMathRSpace()
    {
        return Length();
    }

    static Length InitialMathPaddedVOffset()
    {
        return Length();
    }

    static Length InitialMathPaddedDepth()
    {
        return Length();
    }

    static Length InitialMathMinSize()
    {
        return Length();
    }

    static Length InitialMathMaxSize()
    {
        return Length();
    }

    static bool InitialEffectiveZIndexZero()
    {
        return false;
    }

    static EBaselineShiftType InitialBaselineShiftType()
    {
        return EBaselineShiftType::kLength;
    }

    static EDominantBaseline InitialCssDominantBaseline()
    {
        return EDominantBaseline::kAuto;
    }

    static bool InitialDependsOnSizeContainerQueries()
    {
        return false;
    }

    static bool InitialDependsOnStyleContainerQueries()
    {
        return false;
    }

    static bool InitialDependsOnScrollStateContainerQueries()
    {
        return false;
    }

    static bool InitialFirstLineDependsOnSizeContainerQueries()
    {
        return false;
    }

    static StyleBaseData* InitialBaseData()
    {
        return nullptr;
    }

    static StyleUAShadowHostData* InitialUAShadowHostData()
    {
        return nullptr;
    }

    static bool InitialSkipsContents()
    {
        return false;
    }

    static bool InitialIsHTMLInert()
    {
        return false;
    }

    static bool InitialInlineStyleLostCascade()
    {
        return false;
    }

    static std::optional<blink::PositionAreaOffsets> InitialPositionAreaOffsets()
    {
        return std::nullopt;
    }

    static std::optional<PhysicalOffset> InitialAnchorCenterOffset()
    {
        return std::nullopt;
    }

    static bool InitialPrefersDefaultScrollbarStyles()
    {
        return false;
    }

    static bool InitialIsPageMarginBox()
    {
        return false;
    }

    static bool InitialInBaseSelectAppearance()
    {
        return false;
    }

private:
    static const FilterOperations& InitialFilterInternal()
    {
        DEFINE_STATIC_LOCAL(const Persistent<FilterOperationsWrapper>, ops, (MakeGarbageCollected<FilterOperationsWrapper>()));
        return ops->Operations();
    }
};

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_INITIAL_VALUES_H_
