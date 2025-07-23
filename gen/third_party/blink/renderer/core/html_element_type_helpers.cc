// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_type_helpers.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/html_tag_names.json5

#include "third_party/blink/renderer/core/html_element_type_helpers.h"

#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/html_names.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "third_party/blink/renderer/platform/wtf/hash_map.h"
#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"

namespace blink {
using HTMLTypeMap = HashMap<AtomicString, HTMLElementType>;

HTMLTypeMap CreateHTMLTypeMap()
{
    HTMLTypeMap html_type_map;
    html_type_map.ReserveCapacityForSize(142);
    static const struct {
        const QualifiedName* name;
        HTMLElementType type;
    } kTags[] = {
        { &html_names::kATag, HTMLElementType::kHTMLAnchorElement },
        { &html_names::kAbbrTag, HTMLElementType::kHTMLElement },
        { &html_names::kAcronymTag, HTMLElementType::kHTMLElement },
        { &html_names::kAddressTag, HTMLElementType::kHTMLElement },
        { &html_names::kAppletTag, HTMLElementType::kHTMLUnknownElement },
        { &html_names::kAreaTag, HTMLElementType::kHTMLAreaElement },
        { &html_names::kArticleTag, HTMLElementType::kHTMLElement },
        { &html_names::kAsideTag, HTMLElementType::kHTMLElement },
        { &html_names::kAudioTag, HTMLElementType::kHTMLAudioElement },
        { &html_names::kBTag, HTMLElementType::kHTMLElement },
        { &html_names::kBaseTag, HTMLElementType::kHTMLBaseElement },
        { &html_names::kBasefontTag, HTMLElementType::kHTMLElement },
        { &html_names::kBdiTag, HTMLElementType::kHTMLElement },
        { &html_names::kBdoTag, HTMLElementType::kHTMLElement },
        { &html_names::kBgsoundTag, HTMLElementType::kHTMLUnknownElement },
        { &html_names::kBigTag, HTMLElementType::kHTMLElement },
        { &html_names::kBlockquoteTag, HTMLElementType::kHTMLQuoteElement },
        { &html_names::kBodyTag, HTMLElementType::kHTMLBodyElement },
        { &html_names::kBrTag, HTMLElementType::kHTMLBRElement },
        { &html_names::kButtonTag, HTMLElementType::kHTMLButtonElement },
        { &html_names::kCanvasTag, HTMLElementType::kHTMLCanvasElement },
        { &html_names::kCaptionTag, HTMLElementType::kHTMLTableCaptionElement },
        { &html_names::kCenterTag, HTMLElementType::kHTMLElement },
        { &html_names::kCiteTag, HTMLElementType::kHTMLElement },
        { &html_names::kCodeTag, HTMLElementType::kHTMLElement },
        { &html_names::kColTag, HTMLElementType::kHTMLTableColElement },
        { &html_names::kColgroupTag, HTMLElementType::kHTMLTableColElement },
        { &html_names::kCommandTag, HTMLElementType::kHTMLUnknownElement },
        { &html_names::kDataTag, HTMLElementType::kHTMLDataElement },
        { &html_names::kDatalistTag, HTMLElementType::kHTMLDataListElement },
        { &html_names::kDdTag, HTMLElementType::kHTMLElement },
        { &html_names::kDelTag, HTMLElementType::kHTMLModElement },
        { &html_names::kDetailsTag, HTMLElementType::kHTMLDetailsElement },
        { &html_names::kDfnTag, HTMLElementType::kHTMLElement },
        { &html_names::kDialogTag, HTMLElementType::kHTMLDialogElement },
        { &html_names::kDirTag, HTMLElementType::kHTMLDirectoryElement },
        { &html_names::kDivTag, HTMLElementType::kHTMLDivElement },
        { &html_names::kDlTag, HTMLElementType::kHTMLDListElement },
        { &html_names::kDtTag, HTMLElementType::kHTMLElement },
        { &html_names::kEmTag, HTMLElementType::kHTMLElement },
        { &html_names::kEmbedTag, HTMLElementType::kHTMLEmbedElement },
        { &html_names::kFencedframeTag, HTMLElementType::kHTMLFencedFrameElement },
        { &html_names::kFieldsetTag, HTMLElementType::kHTMLFieldSetElement },
        { &html_names::kFigcaptionTag, HTMLElementType::kHTMLElement },
        { &html_names::kFigureTag, HTMLElementType::kHTMLElement },
        { &html_names::kFontTag, HTMLElementType::kHTMLFontElement },
        { &html_names::kFooterTag, HTMLElementType::kHTMLElement },
        { &html_names::kFormTag, HTMLElementType::kHTMLFormElement },
        { &html_names::kFrameTag, HTMLElementType::kHTMLFrameElement },
        { &html_names::kFramesetTag, HTMLElementType::kHTMLFrameSetElement },
        { &html_names::kH1Tag, HTMLElementType::kHTMLHeadingElement },
        { &html_names::kH2Tag, HTMLElementType::kHTMLHeadingElement },
        { &html_names::kH3Tag, HTMLElementType::kHTMLHeadingElement },
        { &html_names::kH4Tag, HTMLElementType::kHTMLHeadingElement },
        { &html_names::kH5Tag, HTMLElementType::kHTMLHeadingElement },
        { &html_names::kH6Tag, HTMLElementType::kHTMLHeadingElement },
        { &html_names::kHeadTag, HTMLElementType::kHTMLHeadElement },
        { &html_names::kHeaderTag, HTMLElementType::kHTMLElement },
        { &html_names::kHgroupTag, HTMLElementType::kHTMLElement },
        { &html_names::kHrTag, HTMLElementType::kHTMLHRElement },
        { &html_names::kHTMLTag, HTMLElementType::kHTMLHtmlElement },
        { &html_names::kITag, HTMLElementType::kHTMLElement },
        { &html_names::kIFrameTag, HTMLElementType::kHTMLIFrameElement },
        { &html_names::kImageTag, HTMLElementType::kHTMLUnknownElement },
        { &html_names::kImgTag, HTMLElementType::kHTMLImageElement },
        { &html_names::kInputTag, HTMLElementType::kHTMLInputElement },
        { &html_names::kInsTag, HTMLElementType::kHTMLModElement },
        { &html_names::kKbdTag, HTMLElementType::kHTMLElement },
        { &html_names::kKeygenTag, HTMLElementType::kHTMLUnknownElement },
        { &html_names::kLabelTag, HTMLElementType::kHTMLLabelElement },
        { &html_names::kLayerTag, HTMLElementType::kHTMLElement },
        { &html_names::kLegendTag, HTMLElementType::kHTMLLegendElement },
        { &html_names::kLiTag, HTMLElementType::kHTMLLIElement },
        { &html_names::kLinkTag, HTMLElementType::kHTMLLinkElement },
        { &html_names::kListingTag, HTMLElementType::kHTMLPreElement },
        { &html_names::kMainTag, HTMLElementType::kHTMLElement },
        { &html_names::kMapTag, HTMLElementType::kHTMLMapElement },
        { &html_names::kMarkTag, HTMLElementType::kHTMLElement },
        { &html_names::kMarqueeTag, HTMLElementType::kHTMLMarqueeElement },
        { &html_names::kMenuTag, HTMLElementType::kHTMLMenuElement },
        { &html_names::kMetaTag, HTMLElementType::kHTMLMetaElement },
        { &html_names::kMeterTag, HTMLElementType::kHTMLMeterElement },
        { &html_names::kNavTag, HTMLElementType::kHTMLElement },
        { &html_names::kNobrTag, HTMLElementType::kHTMLElement },
        { &html_names::kNoembedTag, HTMLElementType::kHTMLElement },
        { &html_names::kNoframesTag, HTMLElementType::kHTMLElement },
        { &html_names::kNolayerTag, HTMLElementType::kHTMLElement },
        { &html_names::kNoscriptTag, HTMLElementType::kHTMLElement },
        { &html_names::kObjectTag, HTMLElementType::kHTMLObjectElement },
        { &html_names::kOlTag, HTMLElementType::kHTMLOListElement },
        { &html_names::kOptgroupTag, HTMLElementType::kHTMLOptGroupElement },
        { &html_names::kOptionTag, HTMLElementType::kHTMLOptionElement },
        { &html_names::kOutputTag, HTMLElementType::kHTMLOutputElement },
        { &html_names::kPTag, HTMLElementType::kHTMLParagraphElement },
        { &html_names::kParamTag, HTMLElementType::kHTMLParamElement },
        { &html_names::kPermissionTag, HTMLElementType::kHTMLPermissionElement },
        { &html_names::kPictureTag, HTMLElementType::kHTMLPictureElement },
        { &html_names::kPlaintextTag, HTMLElementType::kHTMLElement },
        { &html_names::kPreTag, HTMLElementType::kHTMLPreElement },
        { &html_names::kProgressTag, HTMLElementType::kHTMLProgressElement },
        { &html_names::kQTag, HTMLElementType::kHTMLQuoteElement },
        { &html_names::kRbTag, HTMLElementType::kHTMLElement },
        { &html_names::kRpTag, HTMLElementType::kHTMLElement },
        { &html_names::kRtTag, HTMLElementType::kHTMLElement },
        { &html_names::kRTCTag, HTMLElementType::kHTMLElement },
        { &html_names::kRubyTag, HTMLElementType::kHTMLElement },
        { &html_names::kSTag, HTMLElementType::kHTMLElement },
        { &html_names::kSampTag, HTMLElementType::kHTMLElement },
        { &html_names::kScriptTag, HTMLElementType::kHTMLScriptElement },
        { &html_names::kSearchTag, HTMLElementType::kHTMLSearchElement },
        { &html_names::kSectionTag, HTMLElementType::kHTMLElement },
        { &html_names::kSelectTag, HTMLElementType::kHTMLSelectElement },
        { &html_names::kSelectedcontentTag, HTMLElementType::kHTMLSelectedContentElement },
        { &html_names::kSlotTag, HTMLElementType::kHTMLSlotElement },
        { &html_names::kSmallTag, HTMLElementType::kHTMLElement },
        { &html_names::kSourceTag, HTMLElementType::kHTMLSourceElement },
        { &html_names::kSpanTag, HTMLElementType::kHTMLSpanElement },
        { &html_names::kStrikeTag, HTMLElementType::kHTMLElement },
        { &html_names::kStrongTag, HTMLElementType::kHTMLElement },
        { &html_names::kStyleTag, HTMLElementType::kHTMLStyleElement },
        { &html_names::kSubTag, HTMLElementType::kHTMLElement },
        { &html_names::kSummaryTag, HTMLElementType::kHTMLElement },
        { &html_names::kSupTag, HTMLElementType::kHTMLElement },
        { &html_names::kTableTag, HTMLElementType::kHTMLTableElement },
        { &html_names::kTbodyTag, HTMLElementType::kHTMLTableSectionElement },
        { &html_names::kTdTag, HTMLElementType::kHTMLTableCellElement },
        { &html_names::kTemplateTag, HTMLElementType::kHTMLTemplateElement },
        { &html_names::kTextareaTag, HTMLElementType::kHTMLTextAreaElement },
        { &html_names::kTfootTag, HTMLElementType::kHTMLTableSectionElement },
        { &html_names::kThTag, HTMLElementType::kHTMLTableCellElement },
        { &html_names::kTheadTag, HTMLElementType::kHTMLTableSectionElement },
        { &html_names::kTimeTag, HTMLElementType::kHTMLTimeElement },
        { &html_names::kTitleTag, HTMLElementType::kHTMLTitleElement },
        { &html_names::kTrTag, HTMLElementType::kHTMLTableRowElement },
        { &html_names::kTrackTag, HTMLElementType::kHTMLTrackElement },
        { &html_names::kTtTag, HTMLElementType::kHTMLElement },
        { &html_names::kUTag, HTMLElementType::kHTMLElement },
        { &html_names::kUlTag, HTMLElementType::kHTMLUListElement },
        { &html_names::kVarTag, HTMLElementType::kHTMLElement },
        { &html_names::kVideoTag, HTMLElementType::kHTMLVideoElement },
        { &html_names::kWbrTag, HTMLElementType::kHTMLElement },
        { &html_names::kXmpTag, HTMLElementType::kHTMLPreElement },
    };
    for (const auto& tag : kTags)
        html_type_map.insert(tag.name->LocalName(), tag.type);
    return html_type_map;
}

static const HTMLTypeMap& GetHTMLTypeMap()
{
    DEFINE_STATIC_LOCAL(const HTMLTypeMap, html_type_map, (CreateHTMLTypeMap()));
    return html_type_map;
}

HTMLElementType HtmlElementTypeForTag(const AtomicString& tag_name, const Document* document)
{
    const auto& html_type_map = GetHTMLTypeMap();
    auto it = html_type_map.find(tag_name);
    if (it == html_type_map.end())
        return HTMLElementType::kHTMLUnknownElement;

    if (tag_name == "fencedframe") {
        if (!RuntimeEnabledFeatures::FencedFramesEnabled(document->GetExecutionContext())) {
            return HTMLElementType::kHTMLUnknownElement;
        }
    }
    if (tag_name == "permission") {
        if (!RuntimeEnabledFeatures::PermissionElementEnabled(document->GetExecutionContext())) {
            return HTMLElementType::kHTMLUnknownElement;
        }
    }
    if (tag_name == "selectedcontent") {
        if (!RuntimeEnabledFeatures::CustomizableSelectEnabled(document->GetExecutionContext())) {
            return HTMLElementType::kHTMLUnknownElement;
        }
    }
    return it->value;
}

bool IsKnownBuiltinTagName(const AtomicString& tag_name)
{
    return GetHTMLTypeMap().Contains(tag_name);
}
} // namespace blink
