// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_type_helpers.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/svg/svg_tag_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_SVG_ELEMENT_TYPE_HELPERS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_SVG_ELEMENT_TYPE_HELPERS_H_

#include "third_party/blink/renderer/core/svg/svg_element.h"
#include "third_party/blink/renderer/core/svg_names.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

class Document;

// Type checking.
class SVGAElement;
template <> struct DowncastTraits<SVGAElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kATag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGAElement is forward declared and not included.
    template <typename T = SVGAElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGAElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGAnimateMotionElement;
template <> struct DowncastTraits<SVGAnimateMotionElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kAnimateMotionTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGAnimateMotionElement is forward declared and not included.
    template <typename T = SVGAnimateMotionElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGAnimateMotionElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGAnimateTransformElement;
template <> struct DowncastTraits<SVGAnimateTransformElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kAnimateTransformTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGAnimateTransformElement is forward declared and not included.
    template <typename T = SVGAnimateTransformElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGAnimateTransformElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGCircleElement;
template <> struct DowncastTraits<SVGCircleElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kCircleTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGCircleElement is forward declared and not included.
    template <typename T = SVGCircleElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGCircleElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGClipPathElement;
template <> struct DowncastTraits<SVGClipPathElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kClipPathTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGClipPathElement is forward declared and not included.
    template <typename T = SVGClipPathElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGClipPathElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGDefsElement;
template <> struct DowncastTraits<SVGDefsElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kDefsTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGDefsElement is forward declared and not included.
    template <typename T = SVGDefsElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGDefsElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGDescElement;
template <> struct DowncastTraits<SVGDescElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kDescTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGDescElement is forward declared and not included.
    template <typename T = SVGDescElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGDescElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGEllipseElement;
template <> struct DowncastTraits<SVGEllipseElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kEllipseTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGEllipseElement is forward declared and not included.
    template <typename T = SVGEllipseElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGEllipseElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEBlendElement;
template <> struct DowncastTraits<SVGFEBlendElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEBlendTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEBlendElement is forward declared and not included.
    template <typename T = SVGFEBlendElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEBlendElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEColorMatrixElement;
template <> struct DowncastTraits<SVGFEColorMatrixElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEColorMatrixTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEColorMatrixElement is forward declared and not included.
    template <typename T = SVGFEColorMatrixElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEColorMatrixElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEComponentTransferElement;
template <> struct DowncastTraits<SVGFEComponentTransferElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEComponentTransferTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEComponentTransferElement is forward declared and not included.
    template <typename T = SVGFEComponentTransferElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEComponentTransferElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFECompositeElement;
template <> struct DowncastTraits<SVGFECompositeElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFECompositeTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFECompositeElement is forward declared and not included.
    template <typename T = SVGFECompositeElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFECompositeElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEConvolveMatrixElement;
template <> struct DowncastTraits<SVGFEConvolveMatrixElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEConvolveMatrixTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEConvolveMatrixElement is forward declared and not included.
    template <typename T = SVGFEConvolveMatrixElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEConvolveMatrixElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEDiffuseLightingElement;
template <> struct DowncastTraits<SVGFEDiffuseLightingElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEDiffuseLightingTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEDiffuseLightingElement is forward declared and not included.
    template <typename T = SVGFEDiffuseLightingElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEDiffuseLightingElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEDisplacementMapElement;
template <> struct DowncastTraits<SVGFEDisplacementMapElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEDisplacementMapTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEDisplacementMapElement is forward declared and not included.
    template <typename T = SVGFEDisplacementMapElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEDisplacementMapElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEDistantLightElement;
template <> struct DowncastTraits<SVGFEDistantLightElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEDistantLightTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEDistantLightElement is forward declared and not included.
    template <typename T = SVGFEDistantLightElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEDistantLightElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEDropShadowElement;
template <> struct DowncastTraits<SVGFEDropShadowElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEDropShadowTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEDropShadowElement is forward declared and not included.
    template <typename T = SVGFEDropShadowElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEDropShadowElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEFloodElement;
template <> struct DowncastTraits<SVGFEFloodElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEFloodTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEFloodElement is forward declared and not included.
    template <typename T = SVGFEFloodElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEFloodElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEFuncAElement;
template <> struct DowncastTraits<SVGFEFuncAElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEFuncATag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEFuncAElement is forward declared and not included.
    template <typename T = SVGFEFuncAElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEFuncAElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEFuncBElement;
template <> struct DowncastTraits<SVGFEFuncBElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEFuncBTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEFuncBElement is forward declared and not included.
    template <typename T = SVGFEFuncBElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEFuncBElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEFuncGElement;
template <> struct DowncastTraits<SVGFEFuncGElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEFuncGTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEFuncGElement is forward declared and not included.
    template <typename T = SVGFEFuncGElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEFuncGElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEFuncRElement;
template <> struct DowncastTraits<SVGFEFuncRElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEFuncRTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEFuncRElement is forward declared and not included.
    template <typename T = SVGFEFuncRElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEFuncRElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEGaussianBlurElement;
template <> struct DowncastTraits<SVGFEGaussianBlurElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEGaussianBlurTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEGaussianBlurElement is forward declared and not included.
    template <typename T = SVGFEGaussianBlurElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEGaussianBlurElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEImageElement;
template <> struct DowncastTraits<SVGFEImageElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEImageTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEImageElement is forward declared and not included.
    template <typename T = SVGFEImageElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEImageElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEMergeElement;
template <> struct DowncastTraits<SVGFEMergeElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEMergeTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEMergeElement is forward declared and not included.
    template <typename T = SVGFEMergeElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEMergeElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEMergeNodeElement;
template <> struct DowncastTraits<SVGFEMergeNodeElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEMergeNodeTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEMergeNodeElement is forward declared and not included.
    template <typename T = SVGFEMergeNodeElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEMergeNodeElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEMorphologyElement;
template <> struct DowncastTraits<SVGFEMorphologyElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEMorphologyTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEMorphologyElement is forward declared and not included.
    template <typename T = SVGFEMorphologyElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEMorphologyElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEOffsetElement;
template <> struct DowncastTraits<SVGFEOffsetElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEOffsetTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEOffsetElement is forward declared and not included.
    template <typename T = SVGFEOffsetElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEOffsetElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFEPointLightElement;
template <> struct DowncastTraits<SVGFEPointLightElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFEPointLightTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFEPointLightElement is forward declared and not included.
    template <typename T = SVGFEPointLightElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFEPointLightElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFESpecularLightingElement;
template <> struct DowncastTraits<SVGFESpecularLightingElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFESpecularLightingTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFESpecularLightingElement is forward declared and not included.
    template <typename T = SVGFESpecularLightingElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFESpecularLightingElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFESpotLightElement;
template <> struct DowncastTraits<SVGFESpotLightElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFESpotLightTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFESpotLightElement is forward declared and not included.
    template <typename T = SVGFESpotLightElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFESpotLightElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFETileElement;
template <> struct DowncastTraits<SVGFETileElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFETileTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFETileElement is forward declared and not included.
    template <typename T = SVGFETileElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFETileElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFETurbulenceElement;
template <> struct DowncastTraits<SVGFETurbulenceElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFETurbulenceTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFETurbulenceElement is forward declared and not included.
    template <typename T = SVGFETurbulenceElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFETurbulenceElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGFilterElement;
template <> struct DowncastTraits<SVGFilterElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kFilterTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGFilterElement is forward declared and not included.
    template <typename T = SVGFilterElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGFilterElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGForeignObjectElement;
template <> struct DowncastTraits<SVGForeignObjectElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kForeignObjectTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGForeignObjectElement is forward declared and not included.
    template <typename T = SVGForeignObjectElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGForeignObjectElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGGElement;
template <> struct DowncastTraits<SVGGElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kGTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGGElement is forward declared and not included.
    template <typename T = SVGGElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGGElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGImageElement;
template <> struct DowncastTraits<SVGImageElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kImageTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGImageElement is forward declared and not included.
    template <typename T = SVGImageElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGImageElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGLineElement;
template <> struct DowncastTraits<SVGLineElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kLineTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGLineElement is forward declared and not included.
    template <typename T = SVGLineElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGLineElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGLinearGradientElement;
template <> struct DowncastTraits<SVGLinearGradientElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kLinearGradientTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGLinearGradientElement is forward declared and not included.
    template <typename T = SVGLinearGradientElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGLinearGradientElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGMarkerElement;
template <> struct DowncastTraits<SVGMarkerElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kMarkerTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGMarkerElement is forward declared and not included.
    template <typename T = SVGMarkerElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGMarkerElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGMaskElement;
template <> struct DowncastTraits<SVGMaskElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kMaskTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGMaskElement is forward declared and not included.
    template <typename T = SVGMaskElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGMaskElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGMetadataElement;
template <> struct DowncastTraits<SVGMetadataElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kMetadataTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGMetadataElement is forward declared and not included.
    template <typename T = SVGMetadataElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGMetadataElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGMPathElement;
template <> struct DowncastTraits<SVGMPathElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kMPathTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGMPathElement is forward declared and not included.
    template <typename T = SVGMPathElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGMPathElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGPathElement;
template <> struct DowncastTraits<SVGPathElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kPathTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGPathElement is forward declared and not included.
    template <typename T = SVGPathElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGPathElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGPatternElement;
template <> struct DowncastTraits<SVGPatternElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kPatternTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGPatternElement is forward declared and not included.
    template <typename T = SVGPatternElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGPatternElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGPolygonElement;
template <> struct DowncastTraits<SVGPolygonElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kPolygonTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGPolygonElement is forward declared and not included.
    template <typename T = SVGPolygonElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGPolygonElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGPolylineElement;
template <> struct DowncastTraits<SVGPolylineElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kPolylineTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGPolylineElement is forward declared and not included.
    template <typename T = SVGPolylineElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGPolylineElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGRadialGradientElement;
template <> struct DowncastTraits<SVGRadialGradientElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kRadialGradientTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGRadialGradientElement is forward declared and not included.
    template <typename T = SVGRadialGradientElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGRadialGradientElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGRectElement;
template <> struct DowncastTraits<SVGRectElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kRectTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGRectElement is forward declared and not included.
    template <typename T = SVGRectElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGRectElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGScriptElement;
template <> struct DowncastTraits<SVGScriptElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kScriptTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGScriptElement is forward declared and not included.
    template <typename T = SVGScriptElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGScriptElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGSetElement;
template <> struct DowncastTraits<SVGSetElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kSetTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGSetElement is forward declared and not included.
    template <typename T = SVGSetElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGSetElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGStopElement;
template <> struct DowncastTraits<SVGStopElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kStopTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGStopElement is forward declared and not included.
    template <typename T = SVGStopElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGStopElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGStyleElement;
template <> struct DowncastTraits<SVGStyleElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kStyleTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGStyleElement is forward declared and not included.
    template <typename T = SVGStyleElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGStyleElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGSVGElement;
template <> struct DowncastTraits<SVGSVGElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kSVGTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGSVGElement is forward declared and not included.
    template <typename T = SVGSVGElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGSVGElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGSwitchElement;
template <> struct DowncastTraits<SVGSwitchElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kSwitchTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGSwitchElement is forward declared and not included.
    template <typename T = SVGSwitchElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGSwitchElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGSymbolElement;
template <> struct DowncastTraits<SVGSymbolElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kSymbolTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGSymbolElement is forward declared and not included.
    template <typename T = SVGSymbolElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGSymbolElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGTextElement;
template <> struct DowncastTraits<SVGTextElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kTextTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGTextElement is forward declared and not included.
    template <typename T = SVGTextElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGTextElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGTextPathElement;
template <> struct DowncastTraits<SVGTextPathElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kTextPathTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGTextPathElement is forward declared and not included.
    template <typename T = SVGTextPathElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGTextPathElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGTitleElement;
template <> struct DowncastTraits<SVGTitleElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kTitleTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGTitleElement is forward declared and not included.
    template <typename T = SVGTitleElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGTitleElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGTSpanElement;
template <> struct DowncastTraits<SVGTSpanElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kTSpanTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGTSpanElement is forward declared and not included.
    template <typename T = SVGTSpanElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGTSpanElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGUseElement;
template <> struct DowncastTraits<SVGUseElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kUseTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGUseElement is forward declared and not included.
    template <typename T = SVGUseElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGUseElement>(UnsafeTo<SVGElement>(node));
    }
};

class SVGViewElement;
template <> struct DowncastTraits<SVGViewElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(svg_names::kViewTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // SVGViewElement is forward declared and not included.
    template <typename T = SVGViewElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsSVGElement() && IsA<SVGViewElement>(UnsafeTo<SVGElement>(node));
    }
};

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_SVG_ELEMENT_TYPE_HELPERS_H_
