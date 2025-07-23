// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_type_helpers.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/mathml/mathml_tag_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_MATHML_ELEMENT_TYPE_HELPERS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_MATHML_ELEMENT_TYPE_HELPERS_H_

#include "third_party/blink/renderer/core/mathml/mathml_element.h"
#include "third_party/blink/renderer/core/mathml_names.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

class Document;

// Type checking.
class MathMLFractionElement;
template <> struct DowncastTraits<MathMLFractionElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(mathml_names::kMfracTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // MathMLFractionElement is forward declared and not included.
    template <typename T = MathMLFractionElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsMathMLElement() && IsA<MathMLFractionElement>(UnsafeTo<MathMLElement>(node));
    }
};

class MathMLOperatorElement;
template <> struct DowncastTraits<MathMLOperatorElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(mathml_names::kMoTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // MathMLOperatorElement is forward declared and not included.
    template <typename T = MathMLOperatorElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsMathMLElement() && IsA<MathMLOperatorElement>(UnsafeTo<MathMLElement>(node));
    }
};

class MathMLPaddedElement;
template <> struct DowncastTraits<MathMLPaddedElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(mathml_names::kMpaddedTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // MathMLPaddedElement is forward declared and not included.
    template <typename T = MathMLPaddedElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsMathMLElement() && IsA<MathMLPaddedElement>(UnsafeTo<MathMLElement>(node));
    }
};

class MathMLSpaceElement;
template <> struct DowncastTraits<MathMLSpaceElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(mathml_names::kMspaceTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // MathMLSpaceElement is forward declared and not included.
    template <typename T = MathMLSpaceElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsMathMLElement() && IsA<MathMLSpaceElement>(UnsafeTo<MathMLElement>(node));
    }
};

class MathMLTableCellElement;
template <> struct DowncastTraits<MathMLTableCellElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(mathml_names::kMtdTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // MathMLTableCellElement is forward declared and not included.
    template <typename T = MathMLTableCellElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsMathMLElement() && IsA<MathMLTableCellElement>(UnsafeTo<MathMLElement>(node));
    }
};

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_MATHML_ELEMENT_TYPE_HELPERS_H_
