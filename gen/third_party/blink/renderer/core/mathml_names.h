// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_qualified_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/mathml/mathml_attribute_names.json5
//   ../../third_party/blink/renderer/core/mathml/mathml_tag_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_MATHML_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_MATHML_NAMES_H_

#include <memory>

#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/dom/qualified_name.h"

namespace blink {

class MathMLQualifiedName : public QualifiedName { };

namespace mathml_names {

// Namespace
CORE_EXPORT extern const WTF::AtomicString& kNamespaceURI;

// Tags

CORE_EXPORT extern const blink::MathMLQualifiedName& kAnnotationTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kAnnotationXmlTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMactionTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMalignmarkTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMathTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMerrorTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMfracTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMglyphTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMiTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMmultiscriptsTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMnTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMoTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMoverTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMpaddedTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMphantomTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMprescriptsTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMrootTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMrowTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMsTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMspaceTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMsqrtTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMstyleTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMsubTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMsubsupTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMsupTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMtableTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMtdTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMtextTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMtrTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMunderTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kMunderoverTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kNoneTag;
CORE_EXPORT extern const blink::MathMLQualifiedName& kSemanticsTag;

// Attributes
CORE_EXPORT extern const blink::QualifiedName& kAccentAttr;
CORE_EXPORT extern const blink::QualifiedName& kAccentunderAttr;
CORE_EXPORT extern const blink::QualifiedName& kColumnspanAttr;
CORE_EXPORT extern const blink::QualifiedName& kDefinitionURLAttr;
CORE_EXPORT extern const blink::QualifiedName& kDepthAttr;
CORE_EXPORT extern const blink::QualifiedName& kDisplayAttr;
CORE_EXPORT extern const blink::QualifiedName& kDisplaystyleAttr;
CORE_EXPORT extern const blink::QualifiedName& kEncodingAttr;
CORE_EXPORT extern const blink::QualifiedName& kFormAttr;
CORE_EXPORT extern const blink::QualifiedName& kHeightAttr;
CORE_EXPORT extern const blink::QualifiedName& kLargeopAttr;
CORE_EXPORT extern const blink::QualifiedName& kLinethicknessAttr;
CORE_EXPORT extern const blink::QualifiedName& kLspaceAttr;
CORE_EXPORT extern const blink::QualifiedName& kMathbackgroundAttr;
CORE_EXPORT extern const blink::QualifiedName& kMathcolorAttr;
CORE_EXPORT extern const blink::QualifiedName& kMathsizeAttr;
CORE_EXPORT extern const blink::QualifiedName& kMathvariantAttr;
CORE_EXPORT extern const blink::QualifiedName& kMaxsizeAttr;
CORE_EXPORT extern const blink::QualifiedName& kMinsizeAttr;
CORE_EXPORT extern const blink::QualifiedName& kMovablelimitsAttr;
CORE_EXPORT extern const blink::QualifiedName& kRowspanAttr;
CORE_EXPORT extern const blink::QualifiedName& kRspaceAttr;
CORE_EXPORT extern const blink::QualifiedName& kScriptlevelAttr;
CORE_EXPORT extern const blink::QualifiedName& kStretchyAttr;
CORE_EXPORT extern const blink::QualifiedName& kSymmetricAttr;
CORE_EXPORT extern const blink::QualifiedName& kVoffsetAttr;
CORE_EXPORT extern const blink::QualifiedName& kWidthAttr;

constexpr unsigned kTagsCount = 33;
CORE_EXPORT std::unique_ptr<const MathMLQualifiedName*[]> GetTags();

constexpr unsigned kAttrsCount = 27;
std::unique_ptr<const QualifiedName*[]> GetAttrs();

void Init();

} // namespace mathml_names
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_MATHML_NAMES_H_
