// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_factory.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/svg/svg_attribute_names.json5
//   ../../third_party/blink/renderer/core/svg/svg_tag_names.json5

#include "third_party/blink/renderer/core/svg_element_factory.h"

#include <iterator>

#include "third_party/blink/renderer/core/svg_names.h"
#include "third_party/blink/renderer/core/svg/svg_a_element.h"
#include "third_party/blink/renderer/core/svg/svg_animate_element.h"
#include "third_party/blink/renderer/core/svg/svg_animate_motion_element.h"
#include "third_party/blink/renderer/core/svg/svg_animate_transform_element.h"
#include "third_party/blink/renderer/core/svg/svg_circle_element.h"
#include "third_party/blink/renderer/core/svg/svg_clip_path_element.h"
#include "third_party/blink/renderer/core/svg/svg_defs_element.h"
#include "third_party/blink/renderer/core/svg/svg_desc_element.h"
#include "third_party/blink/renderer/core/svg/svg_ellipse_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_blend_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_color_matrix_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_component_transfer_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_composite_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_convolve_matrix_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_diffuse_lighting_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_displacement_map_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_distant_light_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_drop_shadow_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_flood_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_func_a_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_func_b_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_func_g_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_func_r_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_gaussian_blur_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_image_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_merge_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_merge_node_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_morphology_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_offset_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_point_light_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_specular_lighting_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_spot_light_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_tile_element.h"
#include "third_party/blink/renderer/core/svg/svg_fe_turbulence_element.h"
#include "third_party/blink/renderer/core/svg/svg_filter_element.h"
#include "third_party/blink/renderer/core/svg/svg_foreign_object_element.h"
#include "third_party/blink/renderer/core/svg/svg_g_element.h"
#include "third_party/blink/renderer/core/svg/svg_image_element.h"
#include "third_party/blink/renderer/core/svg/svg_line_element.h"
#include "third_party/blink/renderer/core/svg/svg_linear_gradient_element.h"
#include "third_party/blink/renderer/core/svg/svg_marker_element.h"
#include "third_party/blink/renderer/core/svg/svg_mask_element.h"
#include "third_party/blink/renderer/core/svg/svg_metadata_element.h"
#include "third_party/blink/renderer/core/svg/svg_mpath_element.h"
#include "third_party/blink/renderer/core/svg/svg_path_element.h"
#include "third_party/blink/renderer/core/svg/svg_pattern_element.h"
#include "third_party/blink/renderer/core/svg/svg_polygon_element.h"
#include "third_party/blink/renderer/core/svg/svg_polyline_element.h"
#include "third_party/blink/renderer/core/svg/svg_radial_gradient_element.h"
#include "third_party/blink/renderer/core/svg/svg_rect_element.h"
#include "third_party/blink/renderer/core/svg/svg_script_element.h"
#include "third_party/blink/renderer/core/svg/svg_set_element.h"
#include "third_party/blink/renderer/core/svg/svg_stop_element.h"
#include "third_party/blink/renderer/core/svg/svg_style_element.h"
#include "third_party/blink/renderer/core/svg/svg_svg_element.h"
#include "third_party/blink/renderer/core/svg/svg_switch_element.h"
#include "third_party/blink/renderer/core/svg/svg_symbol_element.h"
#include "third_party/blink/renderer/core/svg/svg_text_element.h"
#include "third_party/blink/renderer/core/svg/svg_text_path_element.h"
#include "third_party/blink/renderer/core/svg/svg_title_element.h"
#include "third_party/blink/renderer/core/svg/svg_tspan_element.h"
#include "third_party/blink/renderer/core/svg/svg_unknown_element.h"
#include "third_party/blink/renderer/core/svg/svg_use_element.h"
#include "third_party/blink/renderer/core/svg/svg_view_element.h"
#include "third_party/blink/renderer/core/svg/svg_unknown_element.h"
#include "third_party/blink/renderer/platform/heap/garbage_collected.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "third_party/blink/renderer/platform/wtf/hash_map.h"

namespace blink {

using SVGConstructorFunction = SVGElement* (*)(Document&, const CreateElementFlags);

using SVGFunctionMap = HashMap<AtomicString, SVGConstructorFunction>;

static SVGFunctionMap* g_svg_constructors = nullptr;

static SVGElement* SVGAConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGAElement>(document);
}
static SVGElement* SVGAnimateConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGAnimateElement>(document);
}
static SVGElement* SVGAnimateMotionConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGAnimateMotionElement>(document);
}
static SVGElement* SVGAnimateTransformConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGAnimateTransformElement>(document);
}
static SVGElement* SVGCircleConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGCircleElement>(document);
}
static SVGElement* SVGClipPathConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGClipPathElement>(document);
}
static SVGElement* SVGDefsConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGDefsElement>(document);
}
static SVGElement* SVGDescConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGDescElement>(document);
}
static SVGElement* SVGEllipseConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGEllipseElement>(document);
}
static SVGElement* SVGFEBlendConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEBlendElement>(document);
}
static SVGElement* SVGFEColorMatrixConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEColorMatrixElement>(document);
}
static SVGElement* SVGFEComponentTransferConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEComponentTransferElement>(document);
}
static SVGElement* SVGFECompositeConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFECompositeElement>(document);
}
static SVGElement* SVGFEConvolveMatrixConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEConvolveMatrixElement>(document);
}
static SVGElement* SVGFEDiffuseLightingConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEDiffuseLightingElement>(document);
}
static SVGElement* SVGFEDisplacementMapConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEDisplacementMapElement>(document);
}
static SVGElement* SVGFEDistantLightConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEDistantLightElement>(document);
}
static SVGElement* SVGFEDropShadowConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEDropShadowElement>(document);
}
static SVGElement* SVGFEFloodConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEFloodElement>(document);
}
static SVGElement* SVGFEFuncAConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEFuncAElement>(document);
}
static SVGElement* SVGFEFuncBConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEFuncBElement>(document);
}
static SVGElement* SVGFEFuncGConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEFuncGElement>(document);
}
static SVGElement* SVGFEFuncRConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEFuncRElement>(document);
}
static SVGElement* SVGFEGaussianBlurConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEGaussianBlurElement>(document);
}
static SVGElement* SVGFEImageConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEImageElement>(document);
}
static SVGElement* SVGFEMergeConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEMergeElement>(document);
}
static SVGElement* SVGFEMergeNodeConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEMergeNodeElement>(document);
}
static SVGElement* SVGFEMorphologyConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEMorphologyElement>(document);
}
static SVGElement* SVGFEOffsetConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEOffsetElement>(document);
}
static SVGElement* SVGFEPointLightConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFEPointLightElement>(document);
}
static SVGElement* SVGFESpecularLightingConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFESpecularLightingElement>(document);
}
static SVGElement* SVGFESpotLightConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFESpotLightElement>(document);
}
static SVGElement* SVGFETileConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFETileElement>(document);
}
static SVGElement* SVGFETurbulenceConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFETurbulenceElement>(document);
}
static SVGElement* SVGFilterConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGFilterElement>(document);
}
static SVGElement* SVGForeignObjectConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGForeignObjectElement>(document);
}
static SVGElement* SVGGConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGGElement>(document);
}
static SVGElement* SVGImageConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGImageElement>(document);
}
static SVGElement* SVGLineConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGLineElement>(document);
}
static SVGElement* SVGLinearGradientConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGLinearGradientElement>(document);
}
static SVGElement* SVGMarkerConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGMarkerElement>(document);
}
static SVGElement* SVGMaskConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGMaskElement>(document);
}
static SVGElement* SVGMetadataConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGMetadataElement>(document);
}
static SVGElement* SVGMPathConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGMPathElement>(document);
}
static SVGElement* SVGPathConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGPathElement>(document);
}
static SVGElement* SVGPatternConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGPatternElement>(document);
}
static SVGElement* SVGPolygonConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGPolygonElement>(document);
}
static SVGElement* SVGPolylineConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGPolylineElement>(document);
}
static SVGElement* SVGRadialGradientConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGRadialGradientElement>(document);
}
static SVGElement* SVGRectConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGRectElement>(document);
}
static SVGElement* SVGScriptConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGScriptElement>(document, flags);
}
static SVGElement* SVGSetConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGSetElement>(document);
}
static SVGElement* SVGStopConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGStopElement>(document);
}
static SVGElement* SVGStyleConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGStyleElement>(document, flags);
}
static SVGElement* SVGSVGConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGSVGElement>(document);
}
static SVGElement* SVGSwitchConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGSwitchElement>(document);
}
static SVGElement* SVGSymbolConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGSymbolElement>(document);
}
static SVGElement* SVGTextConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGTextElement>(document);
}
static SVGElement* SVGTextPathConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGTextPathElement>(document);
}
static SVGElement* SVGTitleConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGTitleElement>(document);
}
static SVGElement* SVGTSpanConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGTSpanElement>(document);
}
static SVGElement* SVGUseConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGUseElement>(document);
}
static SVGElement* SVGViewConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<SVGViewElement>(document);
}

struct CreateSVGFunctionMapData {
    const QualifiedName& tag;
    SVGConstructorFunction func;
};

static void CreateSVGFunctionMap()
{
    DCHECK(!g_svg_constructors);
    g_svg_constructors = new SVGFunctionMap;
    // Empty array initializer lists are illegal [dcl.init.aggr] and will not
    // compile in MSVC. If tags list is empty, add check to skip this.
    static const CreateSVGFunctionMapData data[] = {
        { svg_names::kATag, SVGAConstructor },
        { svg_names::kAnimateTag, SVGAnimateConstructor },
        { svg_names::kAnimateMotionTag, SVGAnimateMotionConstructor },
        { svg_names::kAnimateTransformTag, SVGAnimateTransformConstructor },
        { svg_names::kCircleTag, SVGCircleConstructor },
        { svg_names::kClipPathTag, SVGClipPathConstructor },
        { svg_names::kDefsTag, SVGDefsConstructor },
        { svg_names::kDescTag, SVGDescConstructor },
        { svg_names::kEllipseTag, SVGEllipseConstructor },
        { svg_names::kFEBlendTag, SVGFEBlendConstructor },
        { svg_names::kFEColorMatrixTag, SVGFEColorMatrixConstructor },
        { svg_names::kFEComponentTransferTag, SVGFEComponentTransferConstructor },
        { svg_names::kFECompositeTag, SVGFECompositeConstructor },
        { svg_names::kFEConvolveMatrixTag, SVGFEConvolveMatrixConstructor },
        { svg_names::kFEDiffuseLightingTag, SVGFEDiffuseLightingConstructor },
        { svg_names::kFEDisplacementMapTag, SVGFEDisplacementMapConstructor },
        { svg_names::kFEDistantLightTag, SVGFEDistantLightConstructor },
        { svg_names::kFEDropShadowTag, SVGFEDropShadowConstructor },
        { svg_names::kFEFloodTag, SVGFEFloodConstructor },
        { svg_names::kFEFuncATag, SVGFEFuncAConstructor },
        { svg_names::kFEFuncBTag, SVGFEFuncBConstructor },
        { svg_names::kFEFuncGTag, SVGFEFuncGConstructor },
        { svg_names::kFEFuncRTag, SVGFEFuncRConstructor },
        { svg_names::kFEGaussianBlurTag, SVGFEGaussianBlurConstructor },
        { svg_names::kFEImageTag, SVGFEImageConstructor },
        { svg_names::kFEMergeTag, SVGFEMergeConstructor },
        { svg_names::kFEMergeNodeTag, SVGFEMergeNodeConstructor },
        { svg_names::kFEMorphologyTag, SVGFEMorphologyConstructor },
        { svg_names::kFEOffsetTag, SVGFEOffsetConstructor },
        { svg_names::kFEPointLightTag, SVGFEPointLightConstructor },
        { svg_names::kFESpecularLightingTag, SVGFESpecularLightingConstructor },
        { svg_names::kFESpotLightTag, SVGFESpotLightConstructor },
        { svg_names::kFETileTag, SVGFETileConstructor },
        { svg_names::kFETurbulenceTag, SVGFETurbulenceConstructor },
        { svg_names::kFilterTag, SVGFilterConstructor },
        { svg_names::kForeignObjectTag, SVGForeignObjectConstructor },
        { svg_names::kGTag, SVGGConstructor },
        { svg_names::kImageTag, SVGImageConstructor },
        { svg_names::kLineTag, SVGLineConstructor },
        { svg_names::kLinearGradientTag, SVGLinearGradientConstructor },
        { svg_names::kMarkerTag, SVGMarkerConstructor },
        { svg_names::kMaskTag, SVGMaskConstructor },
        { svg_names::kMetadataTag, SVGMetadataConstructor },
        { svg_names::kMPathTag, SVGMPathConstructor },
        { svg_names::kPathTag, SVGPathConstructor },
        { svg_names::kPatternTag, SVGPatternConstructor },
        { svg_names::kPolygonTag, SVGPolygonConstructor },
        { svg_names::kPolylineTag, SVGPolylineConstructor },
        { svg_names::kRadialGradientTag, SVGRadialGradientConstructor },
        { svg_names::kRectTag, SVGRectConstructor },
        { svg_names::kScriptTag, SVGScriptConstructor },
        { svg_names::kSetTag, SVGSetConstructor },
        { svg_names::kStopTag, SVGStopConstructor },
        { svg_names::kStyleTag, SVGStyleConstructor },
        { svg_names::kSVGTag, SVGSVGConstructor },
        { svg_names::kSwitchTag, SVGSwitchConstructor },
        { svg_names::kSymbolTag, SVGSymbolConstructor },
        { svg_names::kTextTag, SVGTextConstructor },
        { svg_names::kTextPathTag, SVGTextPathConstructor },
        { svg_names::kTitleTag, SVGTitleConstructor },
        { svg_names::kTSpanTag, SVGTSpanConstructor },
        { svg_names::kUseTag, SVGUseConstructor },
        { svg_names::kViewTag, SVGViewConstructor },
    };
    for (size_t i = 0; i < std::size(data); i++)
        g_svg_constructors->Set(data[i].tag.LocalName(), data[i].func);
}

SVGElement* SVGElementFactory::Create(const AtomicString& local_name, Document& document, const CreateElementFlags flags)
{
    if (!g_svg_constructors)
        CreateSVGFunctionMap();
    auto it = g_svg_constructors->find(local_name);
    if (it == g_svg_constructors->end())
        return nullptr;
    SVGConstructorFunction function = it->value;
    return function(document, flags);
}

} // namespace blink
