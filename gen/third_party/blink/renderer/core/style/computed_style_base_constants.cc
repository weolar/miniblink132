// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/style/templates/computed_style_base_constants.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_group_config.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/core/css/css_properties_ranking.json5
//   ../../third_party/blink/renderer/core/css/css_value_keywords.json5
//   ../../third_party/blink/renderer/core/style/computed_style_extra_fields.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "third_party/blink/renderer/core/style/computed_style_base_constants.h"

#include <ostream>

namespace blink {

#if DCHECK_IS_ON()
std::ostream& operator<<(std::ostream& o, const EAlignmentBaseline v)
{
    switch (v) {
    case EAlignmentBaseline::kBaseline:
        o << "baseline";
        break;
    case EAlignmentBaseline::kMiddle:
        o << "middle";
        break;
    case EAlignmentBaseline::kAuto:
        o << "auto";
        break;
    case EAlignmentBaseline::kAlphabetic:
        o << "alphabetic";
        break;
    case EAlignmentBaseline::kBeforeEdge:
        o << "before-edge";
        break;
    case EAlignmentBaseline::kAfterEdge:
        o << "after-edge";
        break;
    case EAlignmentBaseline::kCentral:
        o << "central";
        break;
    case EAlignmentBaseline::kTextBeforeEdge:
        o << "text-before-edge";
        break;
    case EAlignmentBaseline::kTextAfterEdge:
        o << "text-after-edge";
        break;
    case EAlignmentBaseline::kIdeographic:
        o << "ideographic";
        break;
    case EAlignmentBaseline::kHanging:
        o << "hanging";
        break;
    case EAlignmentBaseline::kMathematical:
        o << "mathematical";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EBackfaceVisibility v)
{
    switch (v) {
    case EBackfaceVisibility::kHidden:
        o << "hidden";
        break;
    case EBackfaceVisibility::kVisible:
        o << "visible";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EBaselineSource v)
{
    switch (v) {
    case EBaselineSource::kAuto:
        o << "auto";
        break;
    case EBaselineSource::kFirst:
        o << "first";
        break;
    case EBaselineSource::kLast:
        o << "last";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EBorderCollapse v)
{
    switch (v) {
    case EBorderCollapse::kCollapse:
        o << "collapse";
        break;
    case EBorderCollapse::kSeparate:
        o << "separate";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EBorderStyle v)
{
    switch (v) {
    case EBorderStyle::kNone:
        o << "none";
        break;
    case EBorderStyle::kHidden:
        o << "hidden";
        break;
    case EBorderStyle::kInset:
        o << "inset";
        break;
    case EBorderStyle::kGroove:
        o << "groove";
        break;
    case EBorderStyle::kOutset:
        o << "outset";
        break;
    case EBorderStyle::kRidge:
        o << "ridge";
        break;
    case EBorderStyle::kDotted:
        o << "dotted";
        break;
    case EBorderStyle::kDashed:
        o << "dashed";
        break;
    case EBorderStyle::kSolid:
        o << "solid";
        break;
    case EBorderStyle::kDouble:
        o << "double";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EBoxAlignment v)
{
    switch (v) {
    case EBoxAlignment::kBaseline:
        o << "baseline";
        break;
    case EBoxAlignment::kCenter:
        o << "center";
        break;
    case EBoxAlignment::kStretch:
        o << "stretch";
        break;
    case EBoxAlignment::kStart:
        o << "start";
        break;
    case EBoxAlignment::kEnd:
        o << "end";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EBoxDecorationBreak v)
{
    switch (v) {
    case EBoxDecorationBreak::kClone:
        o << "clone";
        break;
    case EBoxDecorationBreak::kSlice:
        o << "slice";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EBoxDirection v)
{
    switch (v) {
    case EBoxDirection::kNormal:
        o << "normal";
        break;
    case EBoxDirection::kReverse:
        o << "reverse";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EBoxOrient v)
{
    switch (v) {
    case EBoxOrient::kHorizontal:
        o << "horizontal";
        break;
    case EBoxOrient::kVertical:
        o << "vertical";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EBoxPack v)
{
    switch (v) {
    case EBoxPack::kCenter:
        o << "center";
        break;
    case EBoxPack::kJustify:
        o << "justify";
        break;
    case EBoxPack::kStart:
        o << "start";
        break;
    case EBoxPack::kEnd:
        o << "end";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EBoxSizing v)
{
    switch (v) {
    case EBoxSizing::kBorderBox:
        o << "border-box";
        break;
    case EBoxSizing::kContentBox:
        o << "content-box";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EBreakBetween v)
{
    switch (v) {
    case EBreakBetween::kLeft:
        o << "left";
        break;
    case EBreakBetween::kRight:
        o << "right";
        break;
    case EBreakBetween::kAuto:
        o << "auto";
        break;
    case EBreakBetween::kAvoid:
        o << "avoid";
        break;
    case EBreakBetween::kColumn:
        o << "column";
        break;
    case EBreakBetween::kAvoidPage:
        o << "avoid-page";
        break;
    case EBreakBetween::kPage:
        o << "page";
        break;
    case EBreakBetween::kRecto:
        o << "recto";
        break;
    case EBreakBetween::kVerso:
        o << "verso";
        break;
    case EBreakBetween::kAvoidColumn:
        o << "avoid-column";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EBreakInside v)
{
    switch (v) {
    case EBreakInside::kAuto:
        o << "auto";
        break;
    case EBreakInside::kAvoid:
        o << "avoid";
        break;
    case EBreakInside::kAvoidPage:
        o << "avoid-page";
        break;
    case EBreakInside::kAvoidColumn:
        o << "avoid-column";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EBufferedRendering v)
{
    switch (v) {
    case EBufferedRendering::kAuto:
        o << "auto";
        break;
    case EBufferedRendering::kStatic:
        o << "static";
        break;
    case EBufferedRendering::kDynamic:
        o << "dynamic";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ECaptionSide v)
{
    switch (v) {
    case ECaptionSide::kTop:
        o << "top";
        break;
    case ECaptionSide::kBottom:
        o << "bottom";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ECaretAnimation v)
{
    switch (v) {
    case ECaretAnimation::kAuto:
        o << "auto";
        break;
    case ECaretAnimation::kManual:
        o << "manual";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EClear v)
{
    switch (v) {
    case EClear::kNone:
        o << "none";
        break;
    case EClear::kLeft:
        o << "left";
        break;
    case EClear::kRight:
        o << "right";
        break;
    case EClear::kInlineStart:
        o << "inline-start";
        break;
    case EClear::kInlineEnd:
        o << "inline-end";
        break;
    case EClear::kBoth:
        o << "both";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EColorInterpolation v)
{
    switch (v) {
    case EColorInterpolation::kAuto:
        o << "auto";
        break;
    case EColorInterpolation::kSRGB:
        o << "srgb";
        break;
    case EColorInterpolation::kLinearrgb:
        o << "linearrgb";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EColorRendering v)
{
    switch (v) {
    case EColorRendering::kAuto:
        o << "auto";
        break;
    case EColorRendering::kOptimizespeed:
        o << "optimizespeed";
        break;
    case EColorRendering::kOptimizequality:
        o << "optimizequality";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EColumnFill v)
{
    switch (v) {
    case EColumnFill::kAuto:
        o << "auto";
        break;
    case EColumnFill::kBalance:
        o << "balance";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EColumnSpan v)
{
    switch (v) {
    case EColumnSpan::kNone:
        o << "none";
        break;
    case EColumnSpan::kAll:
        o << "all";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EContentVisibility v)
{
    switch (v) {
    case EContentVisibility::kHidden:
        o << "hidden";
        break;
    case EContentVisibility::kAuto:
        o << "auto";
        break;
    case EContentVisibility::kVisible:
        o << "visible";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ECursor v)
{
    switch (v) {
    case ECursor::kNone:
        o << "none";
        break;
    case ECursor::kCopy:
        o << "copy";
        break;
    case ECursor::kAuto:
        o << "auto";
        break;
    case ECursor::kCrosshair:
        o << "crosshair";
        break;
    case ECursor::kDefault:
        o << "default";
        break;
    case ECursor::kPointer:
        o << "pointer";
        break;
    case ECursor::kMove:
        o << "move";
        break;
    case ECursor::kVerticalText:
        o << "vertical-text";
        break;
    case ECursor::kCell:
        o << "cell";
        break;
    case ECursor::kContextMenu:
        o << "context-menu";
        break;
    case ECursor::kAlias:
        o << "alias";
        break;
    case ECursor::kProgress:
        o << "progress";
        break;
    case ECursor::kNoDrop:
        o << "no-drop";
        break;
    case ECursor::kNotAllowed:
        o << "not-allowed";
        break;
    case ECursor::kZoomIn:
        o << "zoom-in";
        break;
    case ECursor::kZoomOut:
        o << "zoom-out";
        break;
    case ECursor::kEResize:
        o << "e-resize";
        break;
    case ECursor::kNeResize:
        o << "ne-resize";
        break;
    case ECursor::kNwResize:
        o << "nw-resize";
        break;
    case ECursor::kNResize:
        o << "n-resize";
        break;
    case ECursor::kSeResize:
        o << "se-resize";
        break;
    case ECursor::kSwResize:
        o << "sw-resize";
        break;
    case ECursor::kSResize:
        o << "s-resize";
        break;
    case ECursor::kWResize:
        o << "w-resize";
        break;
    case ECursor::kEwResize:
        o << "ew-resize";
        break;
    case ECursor::kNsResize:
        o << "ns-resize";
        break;
    case ECursor::kNeswResize:
        o << "nesw-resize";
        break;
    case ECursor::kNwseResize:
        o << "nwse-resize";
        break;
    case ECursor::kColResize:
        o << "col-resize";
        break;
    case ECursor::kRowResize:
        o << "row-resize";
        break;
    case ECursor::kText:
        o << "text";
        break;
    case ECursor::kWait:
        o << "wait";
        break;
    case ECursor::kHelp:
        o << "help";
        break;
    case ECursor::kAllScroll:
        o << "all-scroll";
        break;
    case ECursor::kGrab:
        o << "grab";
        break;
    case ECursor::kGrabbing:
        o << "grabbing";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EDisplay v)
{
    switch (v) {
    case EDisplay::kInline:
        o << "inline";
        break;
    case EDisplay::kBlock:
        o << "block";
        break;
    case EDisplay::kListItem:
        o << "list-item";
        break;
    case EDisplay::kInlineBlock:
        o << "inline-block";
        break;
    case EDisplay::kTable:
        o << "table";
        break;
    case EDisplay::kInlineTable:
        o << "inline-table";
        break;
    case EDisplay::kTableRowGroup:
        o << "table-row-group";
        break;
    case EDisplay::kTableHeaderGroup:
        o << "table-header-group";
        break;
    case EDisplay::kTableFooterGroup:
        o << "table-footer-group";
        break;
    case EDisplay::kTableRow:
        o << "table-row";
        break;
    case EDisplay::kTableColumnGroup:
        o << "table-column-group";
        break;
    case EDisplay::kTableColumn:
        o << "table-column";
        break;
    case EDisplay::kTableCell:
        o << "table-cell";
        break;
    case EDisplay::kTableCaption:
        o << "table-caption";
        break;
    case EDisplay::kWebkitBox:
        o << "-webkit-box";
        break;
    case EDisplay::kWebkitInlineBox:
        o << "-webkit-inline-box";
        break;
    case EDisplay::kFlex:
        o << "flex";
        break;
    case EDisplay::kInlineFlex:
        o << "inline-flex";
        break;
    case EDisplay::kGrid:
        o << "grid";
        break;
    case EDisplay::kInlineGrid:
        o << "inline-grid";
        break;
    case EDisplay::kContents:
        o << "contents";
        break;
    case EDisplay::kFlowRoot:
        o << "flow-root";
        break;
    case EDisplay::kNone:
        o << "none";
        break;
    case EDisplay::kLayoutCustom:
        o << "layout-custom";
        break;
    case EDisplay::kInlineLayoutCustom:
        o << "inline-layout-custom";
        break;
    case EDisplay::kMath:
        o << "math";
        break;
    case EDisplay::kBlockMath:
        o << "block math";
        break;
    case EDisplay::kInlineListItem:
        o << "inline list-item";
        break;
    case EDisplay::kFlowRootListItem:
        o << "flow-root list-item";
        break;
    case EDisplay::kInlineFlowRootListItem:
        o << "inline flow-root list-item";
        break;
    case EDisplay::kRuby:
        o << "ruby";
        break;
    case EDisplay::kBlockRuby:
        o << "block ruby";
        break;
    case EDisplay::kRubyText:
        o << "ruby-text";
        break;
    case EDisplay::kMasonry:
        o << "masonry";
        break;
    case EDisplay::kInlineMasonry:
        o << "inline-masonry";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EDominantBaseline v)
{
    switch (v) {
    case EDominantBaseline::kMiddle:
        o << "middle";
        break;
    case EDominantBaseline::kAuto:
        o << "auto";
        break;
    case EDominantBaseline::kAlphabetic:
        o << "alphabetic";
        break;
    case EDominantBaseline::kCentral:
        o << "central";
        break;
    case EDominantBaseline::kTextBeforeEdge:
        o << "text-before-edge";
        break;
    case EDominantBaseline::kTextAfterEdge:
        o << "text-after-edge";
        break;
    case EDominantBaseline::kIdeographic:
        o << "ideographic";
        break;
    case EDominantBaseline::kHanging:
        o << "hanging";
        break;
    case EDominantBaseline::kMathematical:
        o << "mathematical";
        break;
    case EDominantBaseline::kUseScript:
        o << "use-script";
        break;
    case EDominantBaseline::kNoChange:
        o << "no-change";
        break;
    case EDominantBaseline::kResetSize:
        o << "reset-size";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EDraggableRegionMode v)
{
    switch (v) {
    case EDraggableRegionMode::kNone:
        o << "none";
        break;
    case EDraggableRegionMode::kDrag:
        o << "drag";
        break;
    case EDraggableRegionMode::kNoDrag:
        o << "no-drag";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EEmptyCells v)
{
    switch (v) {
    case EEmptyCells::kHide:
        o << "hide";
        break;
    case EEmptyCells::kShow:
        o << "show";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EFieldSizing v)
{
    switch (v) {
    case EFieldSizing::kFixed:
        o << "fixed";
        break;
    case EFieldSizing::kContent:
        o << "content";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EFlexDirection v)
{
    switch (v) {
    case EFlexDirection::kRow:
        o << "row";
        break;
    case EFlexDirection::kRowReverse:
        o << "row-reverse";
        break;
    case EFlexDirection::kColumn:
        o << "column";
        break;
    case EFlexDirection::kColumnReverse:
        o << "column-reverse";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EFlexWrap v)
{
    switch (v) {
    case EFlexWrap::kNowrap:
        o << "nowrap";
        break;
    case EFlexWrap::kWrap:
        o << "wrap";
        break;
    case EFlexWrap::kWrapReverse:
        o << "wrap-reverse";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EFloat v)
{
    switch (v) {
    case EFloat::kNone:
        o << "none";
        break;
    case EFloat::kLeft:
        o << "left";
        break;
    case EFloat::kRight:
        o << "right";
        break;
    case EFloat::kInlineStart:
        o << "inline-start";
        break;
    case EFloat::kInlineEnd:
        o << "inline-end";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EForcedColorAdjust v)
{
    switch (v) {
    case EForcedColorAdjust::kNone:
        o << "none";
        break;
    case EForcedColorAdjust::kAuto:
        o << "auto";
        break;
    case EForcedColorAdjust::kPreserveParentColor:
        o << "preserve-parent-color";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EImageRendering v)
{
    switch (v) {
    case EImageRendering::kAuto:
        o << "auto";
        break;
    case EImageRendering::kOptimizespeed:
        o << "optimizespeed";
        break;
    case EImageRendering::kOptimizequality:
        o << "optimizequality";
        break;
    case EImageRendering::kPixelated:
        o << "pixelated";
        break;
    case EImageRendering::kWebkitOptimizeContrast:
        o << "-webkit-optimize-contrast";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EInlineBlockBaselineEdge v)
{
    switch (v) {
    case EInlineBlockBaselineEdge::kMarginBox:
        o << "margin-box";
        break;
    case EInlineBlockBaselineEdge::kBorderBox:
        o << "border-box";
        break;
    case EInlineBlockBaselineEdge::kContentBox:
        o << "content-box";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EInsideLink v)
{
    switch (v) {
    case EInsideLink::kNotInsideLink:
        o << "not-inside-link";
        break;
    case EInsideLink::kInsideUnvisitedLink:
        o << "inside-unvisited-link";
        break;
    case EInsideLink::kInsideVisitedLink:
        o << "inside-visited-link";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EInteractivity v)
{
    switch (v) {
    case EInteractivity::kAuto:
        o << "auto";
        break;
    case EInteractivity::kInert:
        o << "inert";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EInterpolateSize v)
{
    switch (v) {
    case EInterpolateSize::kNumericOnly:
        o << "numeric-only";
        break;
    case EInterpolateSize::kAllowKeywords:
        o << "allow-keywords";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EIsolation v)
{
    switch (v) {
    case EIsolation::kAuto:
        o << "auto";
        break;
    case EIsolation::kIsolate:
        o << "isolate";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EListStylePosition v)
{
    switch (v) {
    case EListStylePosition::kOutside:
        o << "outside";
        break;
    case EListStylePosition::kInside:
        o << "inside";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EMaskType v)
{
    switch (v) {
    case EMaskType::kAlpha:
        o << "alpha";
        break;
    case EMaskType::kLuminance:
        o << "luminance";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EMathShift v)
{
    switch (v) {
    case EMathShift::kNormal:
        o << "normal";
        break;
    case EMathShift::kCompact:
        o << "compact";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EMathStyle v)
{
    switch (v) {
    case EMathStyle::kNormal:
        o << "normal";
        break;
    case EMathStyle::kCompact:
        o << "compact";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EObjectFit v)
{
    switch (v) {
    case EObjectFit::kNone:
        o << "none";
        break;
    case EObjectFit::kContain:
        o << "contain";
        break;
    case EObjectFit::kCover:
        o << "cover";
        break;
    case EObjectFit::kFill:
        o << "fill";
        break;
    case EObjectFit::kScaleDown:
        o << "scale-down";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EOrder v)
{
    switch (v) {
    case EOrder::kLogical:
        o << "logical";
        break;
    case EOrder::kVisual:
        o << "visual";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EOriginTrialTestProperty v)
{
    switch (v) {
    case EOriginTrialTestProperty::kNone:
        o << "none";
        break;
    case EOriginTrialTestProperty::kNormal:
        o << "normal";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EOverflow v)
{
    switch (v) {
    case EOverflow::kHidden:
        o << "hidden";
        break;
    case EOverflow::kAuto:
        o << "auto";
        break;
    case EOverflow::kVisible:
        o << "visible";
        break;
    case EOverflow::kOverlay:
        o << "overlay";
        break;
    case EOverflow::kScroll:
        o << "scroll";
        break;
    case EOverflow::kClip:
        o << "clip";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EOverflowAnchor v)
{
    switch (v) {
    case EOverflowAnchor::kNone:
        o << "none";
        break;
    case EOverflowAnchor::kAuto:
        o << "auto";
        break;
    case EOverflowAnchor::kVisible:
        o << "visible";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EOverflowWrap v)
{
    switch (v) {
    case EOverflowWrap::kNormal:
        o << "normal";
        break;
    case EOverflowWrap::kBreakWord:
        o << "break-word";
        break;
    case EOverflowWrap::kAnywhere:
        o << "anywhere";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EOverlay v)
{
    switch (v) {
    case EOverlay::kNone:
        o << "none";
        break;
    case EOverlay::kAuto:
        o << "auto";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EOverscrollBehavior v)
{
    switch (v) {
    case EOverscrollBehavior::kNone:
        o << "none";
        break;
    case EOverscrollBehavior::kAuto:
        o << "auto";
        break;
    case EOverscrollBehavior::kContain:
        o << "contain";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EPointerEvents v)
{
    switch (v) {
    case EPointerEvents::kNone:
        o << "none";
        break;
    case EPointerEvents::kAll:
        o << "all";
        break;
    case EPointerEvents::kAuto:
        o << "auto";
        break;
    case EPointerEvents::kVisible:
        o << "visible";
        break;
    case EPointerEvents::kVisiblepainted:
        o << "visiblepainted";
        break;
    case EPointerEvents::kVisiblefill:
        o << "visiblefill";
        break;
    case EPointerEvents::kVisiblestroke:
        o << "visiblestroke";
        break;
    case EPointerEvents::kPainted:
        o << "painted";
        break;
    case EPointerEvents::kFill:
        o << "fill";
        break;
    case EPointerEvents::kStroke:
        o << "stroke";
        break;
    case EPointerEvents::kBoundingBox:
        o << "bounding-box";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EPosition v)
{
    switch (v) {
    case EPosition::kAbsolute:
        o << "absolute";
        break;
    case EPosition::kFixed:
        o << "fixed";
        break;
    case EPosition::kRelative:
        o << "relative";
        break;
    case EPosition::kStatic:
        o << "static";
        break;
    case EPosition::kSticky:
        o << "sticky";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EPositionTryOrder v)
{
    switch (v) {
    case EPositionTryOrder::kNormal:
        o << "normal";
        break;
    case EPositionTryOrder::kMostWidth:
        o << "most-width";
        break;
    case EPositionTryOrder::kMostHeight:
        o << "most-height";
        break;
    case EPositionTryOrder::kMostBlockSize:
        o << "most-block-size";
        break;
    case EPositionTryOrder::kMostInlineSize:
        o << "most-inline-size";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EPrintColorAdjust v)
{
    switch (v) {
    case EPrintColorAdjust::kEconomy:
        o << "economy";
        break;
    case EPrintColorAdjust::kExact:
        o << "exact";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EReadingFlow v)
{
    switch (v) {
    case EReadingFlow::kNormal:
        o << "normal";
        break;
    case EReadingFlow::kFlexVisual:
        o << "flex-visual";
        break;
    case EReadingFlow::kFlexFlow:
        o << "flex-flow";
        break;
    case EReadingFlow::kGridRows:
        o << "grid-rows";
        break;
    case EReadingFlow::kGridColumns:
        o << "grid-columns";
        break;
    case EReadingFlow::kGridOrder:
        o << "grid-order";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EResize v)
{
    switch (v) {
    case EResize::kNone:
        o << "none";
        break;
    case EResize::kInline:
        o << "inline";
        break;
    case EResize::kBlock:
        o << "block";
        break;
    case EResize::kBoth:
        o << "both";
        break;
    case EResize::kHorizontal:
        o << "horizontal";
        break;
    case EResize::kVertical:
        o << "vertical";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ERubyAlign v)
{
    switch (v) {
    case ERubyAlign::kCenter:
        o << "center";
        break;
    case ERubyAlign::kStart:
        o << "start";
        break;
    case ERubyAlign::kSpaceBetween:
        o << "space-between";
        break;
    case ERubyAlign::kSpaceAround:
        o << "space-around";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EScrollMarkerGroup v)
{
    switch (v) {
    case EScrollMarkerGroup::kNone:
        o << "none";
        break;
    case EScrollMarkerGroup::kAfter:
        o << "after";
        break;
    case EScrollMarkerGroup::kBefore:
        o << "before";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EScrollSnapStop v)
{
    switch (v) {
    case EScrollSnapStop::kNormal:
        o << "normal";
        break;
    case EScrollSnapStop::kAlways:
        o << "always";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EScrollStartTarget v)
{
    switch (v) {
    case EScrollStartTarget::kNone:
        o << "none";
        break;
    case EScrollStartTarget::kAuto:
        o << "auto";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EScrollbarWidth v)
{
    switch (v) {
    case EScrollbarWidth::kNone:
        o << "none";
        break;
    case EScrollbarWidth::kAuto:
        o << "auto";
        break;
    case EScrollbarWidth::kThin:
        o << "thin";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EShapeRendering v)
{
    switch (v) {
    case EShapeRendering::kAuto:
        o << "auto";
        break;
    case EShapeRendering::kOptimizespeed:
        o << "optimizespeed";
        break;
    case EShapeRendering::kGeometricprecision:
        o << "geometricprecision";
        break;
    case EShapeRendering::kCrispedges:
        o << "crispedges";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ESpeak v)
{
    switch (v) {
    case ESpeak::kNone:
        o << "none";
        break;
    case ESpeak::kNormal:
        o << "normal";
        break;
    case ESpeak::kSpellOut:
        o << "spell-out";
        break;
    case ESpeak::kDigits:
        o << "digits";
        break;
    case ESpeak::kLiteralPunctuation:
        o << "literal-punctuation";
        break;
    case ESpeak::kNoPunctuation:
        o << "no-punctuation";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ETableLayout v)
{
    switch (v) {
    case ETableLayout::kAuto:
        o << "auto";
        break;
    case ETableLayout::kFixed:
        o << "fixed";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ETextAlign v)
{
    switch (v) {
    case ETextAlign::kLeft:
        o << "left";
        break;
    case ETextAlign::kRight:
        o << "right";
        break;
    case ETextAlign::kCenter:
        o << "center";
        break;
    case ETextAlign::kJustify:
        o << "justify";
        break;
    case ETextAlign::kWebkitLeft:
        o << "-webkit-left";
        break;
    case ETextAlign::kWebkitRight:
        o << "-webkit-right";
        break;
    case ETextAlign::kWebkitCenter:
        o << "-webkit-center";
        break;
    case ETextAlign::kStart:
        o << "start";
        break;
    case ETextAlign::kEnd:
        o << "end";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ETextAlignLast v)
{
    switch (v) {
    case ETextAlignLast::kLeft:
        o << "left";
        break;
    case ETextAlignLast::kRight:
        o << "right";
        break;
    case ETextAlignLast::kCenter:
        o << "center";
        break;
    case ETextAlignLast::kJustify:
        o << "justify";
        break;
    case ETextAlignLast::kAuto:
        o << "auto";
        break;
    case ETextAlignLast::kStart:
        o << "start";
        break;
    case ETextAlignLast::kEnd:
        o << "end";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ETextAnchor v)
{
    switch (v) {
    case ETextAnchor::kMiddle:
        o << "middle";
        break;
    case ETextAnchor::kStart:
        o << "start";
        break;
    case ETextAnchor::kEnd:
        o << "end";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ETextAutospace v)
{
    switch (v) {
    case ETextAutospace::kNormal:
        o << "normal";
        break;
    case ETextAutospace::kNoAutospace:
        o << "no-autospace";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ETextBoxTrim v)
{
    switch (v) {
    case ETextBoxTrim::kNone:
        o << "none";
        break;
    case ETextBoxTrim::kTrimBoth:
        o << "trim-both";
        break;
    case ETextBoxTrim::kTrimEnd:
        o << "trim-end";
        break;
    case ETextBoxTrim::kTrimStart:
        o << "trim-start";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ETextCombine v)
{
    switch (v) {
    case ETextCombine::kNone:
        o << "none";
        break;
    case ETextCombine::kAll:
        o << "all";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ETextDecorationSkipInk v)
{
    switch (v) {
    case ETextDecorationSkipInk::kNone:
        o << "none";
        break;
    case ETextDecorationSkipInk::kAuto:
        o << "auto";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ETextDecorationStyle v)
{
    switch (v) {
    case ETextDecorationStyle::kDotted:
        o << "dotted";
        break;
    case ETextDecorationStyle::kDashed:
        o << "dashed";
        break;
    case ETextDecorationStyle::kSolid:
        o << "solid";
        break;
    case ETextDecorationStyle::kDouble:
        o << "double";
        break;
    case ETextDecorationStyle::kWavy:
        o << "wavy";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ETextOrientation v)
{
    switch (v) {
    case ETextOrientation::kMixed:
        o << "mixed";
        break;
    case ETextOrientation::kSideways:
        o << "sideways";
        break;
    case ETextOrientation::kUpright:
        o << "upright";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ETextOverflow v)
{
    switch (v) {
    case ETextOverflow::kClip:
        o << "clip";
        break;
    case ETextOverflow::kEllipsis:
        o << "ellipsis";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ETextSecurity v)
{
    switch (v) {
    case ETextSecurity::kNone:
        o << "none";
        break;
    case ETextSecurity::kDisc:
        o << "disc";
        break;
    case ETextSecurity::kCircle:
        o << "circle";
        break;
    case ETextSecurity::kSquare:
        o << "square";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ETextTransform v)
{
    switch (v) {
    case ETextTransform::kNone:
        o << "none";
        break;
    case ETextTransform::kCapitalize:
        o << "capitalize";
        break;
    case ETextTransform::kUppercase:
        o << "uppercase";
        break;
    case ETextTransform::kLowercase:
        o << "lowercase";
        break;
    case ETextTransform::kMathAuto:
        o << "math-auto";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ETransformBox v)
{
    switch (v) {
    case ETransformBox::kBorderBox:
        o << "border-box";
        break;
    case ETransformBox::kContentBox:
        o << "content-box";
        break;
    case ETransformBox::kFillBox:
        o << "fill-box";
        break;
    case ETransformBox::kViewBox:
        o << "view-box";
        break;
    case ETransformBox::kStrokeBox:
        o << "stroke-box";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const ETransformStyle3D v)
{
    switch (v) {
    case ETransformStyle3D::kFlat:
        o << "flat";
        break;
    case ETransformStyle3D::kPreserve3d:
        o << "preserve-3d";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EUserDrag v)
{
    switch (v) {
    case EUserDrag::kNone:
        o << "none";
        break;
    case EUserDrag::kAuto:
        o << "auto";
        break;
    case EUserDrag::kElement:
        o << "element";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EUserModify v)
{
    switch (v) {
    case EUserModify::kReadOnly:
        o << "read-only";
        break;
    case EUserModify::kReadWrite:
        o << "read-write";
        break;
    case EUserModify::kReadWritePlaintextOnly:
        o << "read-write-plaintext-only";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EUserSelect v)
{
    switch (v) {
    case EUserSelect::kNone:
        o << "none";
        break;
    case EUserSelect::kAll:
        o << "all";
        break;
    case EUserSelect::kAuto:
        o << "auto";
        break;
    case EUserSelect::kText:
        o << "text";
        break;
    case EUserSelect::kContain:
        o << "contain";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EVectorEffect v)
{
    switch (v) {
    case EVectorEffect::kNone:
        o << "none";
        break;
    case EVectorEffect::kNonScalingStroke:
        o << "non-scaling-stroke";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EVisibility v)
{
    switch (v) {
    case EVisibility::kHidden:
        o << "hidden";
        break;
    case EVisibility::kVisible:
        o << "visible";
        break;
    case EVisibility::kCollapse:
        o << "collapse";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const EWordBreak v)
{
    switch (v) {
    case EWordBreak::kNormal:
        o << "normal";
        break;
    case EWordBreak::kBreakAll:
        o << "break-all";
        break;
    case EWordBreak::kKeepAll:
        o << "keep-all";
        break;
    case EWordBreak::kAutoPhrase:
        o << "auto-phrase";
        break;
    case EWordBreak::kBreakWord:
        o << "break-word";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const Hyphens v)
{
    switch (v) {
    case Hyphens::kNone:
        o << "none";
        break;
    case Hyphens::kAuto:
        o << "auto";
        break;
    case Hyphens::kManual:
        o << "manual";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const LineBreak v)
{
    switch (v) {
    case LineBreak::kNormal:
        o << "normal";
        break;
    case LineBreak::kAuto:
        o << "auto";
        break;
    case LineBreak::kLoose:
        o << "loose";
        break;
    case LineBreak::kStrict:
        o << "strict";
        break;
    case LineBreak::kAfterWhiteSpace:
        o << "after-white-space";
        break;
    case LineBreak::kAnywhere:
        o << "anywhere";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const RubyPosition v)
{
    switch (v) {
    case RubyPosition::kOver:
        o << "over";
        break;
    case RubyPosition::kUnder:
        o << "under";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const TextDecorationLine v)
{
    if (v == TextDecorationLine::kNone) {
        return o << "none";
    }
    if ((v & TextDecorationLine::kUnderline) == TextDecorationLine::kUnderline) {
        o << "underline ";
    }
    if ((v & TextDecorationLine::kOverline) == TextDecorationLine::kOverline) {
        o << "overline ";
    }
    if ((v & TextDecorationLine::kLineThrough) == TextDecorationLine::kLineThrough) {
        o << "line-through ";
    }
    if ((v & TextDecorationLine::kBlink) == TextDecorationLine::kBlink) {
        o << "blink ";
    }
    if ((v & TextDecorationLine::kSpellingError) == TextDecorationLine::kSpellingError) {
        o << "spelling-error ";
    }
    if ((v & TextDecorationLine::kGrammarError) == TextDecorationLine::kGrammarError) {
        o << "grammar-error ";
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const TextEmphasisFill v)
{
    switch (v) {
    case TextEmphasisFill::kFilled:
        o << "filled";
        break;
    case TextEmphasisFill::kOpen:
        o << "open";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const TextEmphasisMark v)
{
    switch (v) {
    case TextEmphasisMark::kNone:
        o << "none";
        break;
    case TextEmphasisMark::kAuto:
        o << "auto";
        break;
    case TextEmphasisMark::kDot:
        o << "dot";
        break;
    case TextEmphasisMark::kCircle:
        o << "circle";
        break;
    case TextEmphasisMark::kDoubleCircle:
        o << "double-circle";
        break;
    case TextEmphasisMark::kTriangle:
        o << "triangle";
        break;
    case TextEmphasisMark::kSesame:
        o << "sesame";
        break;
    case TextEmphasisMark::kCustom:
        o << "custom";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const TextWrapMode v)
{
    switch (v) {
    case TextWrapMode::kNowrap:
        o << "nowrap";
        break;
    case TextWrapMode::kWrap:
        o << "wrap";
        break;
    }
    return o;
}

std::ostream& operator<<(std::ostream& o, const TextWrapStyle v)
{
    switch (v) {
    case TextWrapStyle::kAuto:
        o << "auto";
        break;
    case TextWrapStyle::kPretty:
        o << "pretty";
        break;
    case TextWrapStyle::kBalance:
        o << "balance";
        break;
    case TextWrapStyle::kStable:
        o << "stable";
        break;
    }
    return o;
}

#endif

} // namespace blink
