// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_factory.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/aria_properties.json5
//   ../../third_party/blink/renderer/core/html/html_attribute_names.json5
//   ../../third_party/blink/renderer/core/html/html_tag_names.json5

#include "third_party/blink/renderer/core/html_element_factory.h"

#include <iterator>

#include "third_party/blink/renderer/core/html_names.h"
#include "third_party/blink/renderer/core/html/canvas/html_canvas_element.h"
#include "third_party/blink/renderer/core/html/fenced_frame/html_fenced_frame_element.h"
#include "third_party/blink/renderer/core/html/forms/html_button_element.h"
#include "third_party/blink/renderer/core/html/forms/html_data_list_element.h"
#include "third_party/blink/renderer/core/html/forms/html_field_set_element.h"
#include "third_party/blink/renderer/core/html/forms/html_form_element.h"
#include "third_party/blink/renderer/core/html/forms/html_input_element.h"
#include "third_party/blink/renderer/core/html/forms/html_label_element.h"
#include "third_party/blink/renderer/core/html/forms/html_legend_element.h"
#include "third_party/blink/renderer/core/html/forms/html_opt_group_element.h"
#include "third_party/blink/renderer/core/html/forms/html_option_element.h"
#include "third_party/blink/renderer/core/html/forms/html_output_element.h"
#include "third_party/blink/renderer/core/html/forms/html_select_element.h"
#include "third_party/blink/renderer/core/html/forms/html_selected_content_element.h"
#include "third_party/blink/renderer/core/html/forms/html_text_area_element.h"
#include "third_party/blink/renderer/core/html/html_anchor_element.h"
#include "third_party/blink/renderer/core/html/html_area_element.h"
#include "third_party/blink/renderer/core/html/html_base_element.h"
#include "third_party/blink/renderer/core/html/html_bdi_element.h"
#include "third_party/blink/renderer/core/html/html_body_element.h"
#include "third_party/blink/renderer/core/html/html_br_element.h"
#include "third_party/blink/renderer/core/html/html_data_element.h"
#include "third_party/blink/renderer/core/html/html_details_element.h"
#include "third_party/blink/renderer/core/html/html_dialog_element.h"
#include "third_party/blink/renderer/core/html/html_directory_element.h"
#include "third_party/blink/renderer/core/html/html_div_element.h"
#include "third_party/blink/renderer/core/html/html_dlist_element.h"
#include "third_party/blink/renderer/core/html/html_element.h"
#include "third_party/blink/renderer/core/html/html_embed_element.h"
#include "third_party/blink/renderer/core/html/html_font_element.h"
#include "third_party/blink/renderer/core/html/html_frame_element.h"
#include "third_party/blink/renderer/core/html/html_frame_set_element.h"
#include "third_party/blink/renderer/core/html/html_head_element.h"
#include "third_party/blink/renderer/core/html/html_heading_element.h"
#include "third_party/blink/renderer/core/html/html_hr_element.h"
#include "third_party/blink/renderer/core/html/html_html_element.h"
#include "third_party/blink/renderer/core/html/html_iframe_element.h"
#include "third_party/blink/renderer/core/html/html_image_element.h"
#include "third_party/blink/renderer/core/html/html_li_element.h"
#include "third_party/blink/renderer/core/html/html_link_element.h"
#include "third_party/blink/renderer/core/html/html_map_element.h"
#include "third_party/blink/renderer/core/html/html_marquee_element.h"
#include "third_party/blink/renderer/core/html/html_menu_element.h"
#include "third_party/blink/renderer/core/html/html_meta_element.h"
#include "third_party/blink/renderer/core/html/html_meter_element.h"
#include "third_party/blink/renderer/core/html/html_mod_element.h"
#include "third_party/blink/renderer/core/html/html_no_embed_element.h"
#include "third_party/blink/renderer/core/html/html_no_script_element.h"
#include "third_party/blink/renderer/core/html/html_object_element.h"
#include "third_party/blink/renderer/core/html/html_olist_element.h"
#include "third_party/blink/renderer/core/html/html_paragraph_element.h"
#include "third_party/blink/renderer/core/html/html_param_element.h"
#include "third_party/blink/renderer/core/html/html_permission_element.h"
#include "third_party/blink/renderer/core/html/html_picture_element.h"
#include "third_party/blink/renderer/core/html/html_pre_element.h"
#include "third_party/blink/renderer/core/html/html_progress_element.h"
#include "third_party/blink/renderer/core/html/html_quote_element.h"
#include "third_party/blink/renderer/core/html/html_script_element.h"
#include "third_party/blink/renderer/core/html/html_search_element.h"
#include "third_party/blink/renderer/core/html/html_slot_element.h"
#include "third_party/blink/renderer/core/html/html_source_element.h"
#include "third_party/blink/renderer/core/html/html_span_element.h"
#include "third_party/blink/renderer/core/html/html_style_element.h"
#include "third_party/blink/renderer/core/html/html_summary_element.h"
#include "third_party/blink/renderer/core/html/html_table_caption_element.h"
#include "third_party/blink/renderer/core/html/html_table_cell_element.h"
#include "third_party/blink/renderer/core/html/html_table_col_element.h"
#include "third_party/blink/renderer/core/html/html_table_element.h"
#include "third_party/blink/renderer/core/html/html_table_row_element.h"
#include "third_party/blink/renderer/core/html/html_table_section_element.h"
#include "third_party/blink/renderer/core/html/html_template_element.h"
#include "third_party/blink/renderer/core/html/html_time_element.h"
#include "third_party/blink/renderer/core/html/html_title_element.h"
#include "third_party/blink/renderer/core/html/html_ulist_element.h"
#include "third_party/blink/renderer/core/html/html_unknown_element.h"
#include "third_party/blink/renderer/core/html/html_wbr_element.h"
#include "third_party/blink/renderer/core/html/media/html_audio_element.h"
#include "third_party/blink/renderer/core/html/media/html_video_element.h"
#include "third_party/blink/renderer/core/html/track/html_track_element.h"
#include "third_party/blink/renderer/core/html/html_unknown_element.h"
#include "third_party/blink/renderer/platform/heap/garbage_collected.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "third_party/blink/renderer/platform/wtf/hash_map.h"

namespace blink {

using HTMLConstructorFunction = HTMLElement* (*)(Document&, const CreateElementFlags);

using HTMLFunctionMap = HashMap<AtomicString, HTMLConstructorFunction>;

static HTMLFunctionMap* g_html_constructors = nullptr;

static HTMLElement* HTMLAConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLAnchorElement>(document);
}
static HTMLElement* HTMLAbbrConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kAbbrTag, document);
}
static HTMLElement* HTMLAcronymConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kAcronymTag, document);
}
static HTMLElement* HTMLAddressConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kAddressTag, document);
}
static HTMLElement* HTMLAppletConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLUnknownElement>(html_names::kAppletTag, document);
}
static HTMLElement* HTMLAreaConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLAreaElement>(document);
}
static HTMLElement* HTMLArticleConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kArticleTag, document);
}
static HTMLElement* HTMLAsideConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kAsideTag, document);
}
static HTMLElement* HTMLAudioConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLAudioElement>(document);
}
static HTMLElement* HTMLBConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kBTag, document);
}
static HTMLElement* HTMLBaseConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLBaseElement>(document);
}
static HTMLElement* HTMLBasefontConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kBasefontTag, document);
}
static HTMLElement* HTMLBdiConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLBDIElement>(document);
}
static HTMLElement* HTMLBdoConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kBdoTag, document);
}
static HTMLElement* HTMLBgsoundConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLUnknownElement>(html_names::kBgsoundTag, document);
}
static HTMLElement* HTMLBigConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kBigTag, document);
}
static HTMLElement* HTMLBlockquoteConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLQuoteElement>(html_names::kBlockquoteTag, document);
}
static HTMLElement* HTMLBodyConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLBodyElement>(document);
}
static HTMLElement* HTMLBrConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLBRElement>(document);
}
static HTMLElement* HTMLButtonConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLButtonElement>(document);
}
static HTMLElement* HTMLCanvasConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLCanvasElement>(document);
}
static HTMLElement* HTMLCaptionConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLTableCaptionElement>(document);
}
static HTMLElement* HTMLCenterConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kCenterTag, document);
}
static HTMLElement* HTMLCiteConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kCiteTag, document);
}
static HTMLElement* HTMLCodeConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kCodeTag, document);
}
static HTMLElement* HTMLColConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLTableColElement>(html_names::kColTag, document);
}
static HTMLElement* HTMLColgroupConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLTableColElement>(html_names::kColgroupTag, document);
}
static HTMLElement* HTMLCommandConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLUnknownElement>(html_names::kCommandTag, document);
}
static HTMLElement* HTMLDataConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLDataElement>(document);
}
static HTMLElement* HTMLDatalistConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLDataListElement>(document);
}
static HTMLElement* HTMLDdConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kDdTag, document);
}
static HTMLElement* HTMLDelConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLModElement>(html_names::kDelTag, document);
}
static HTMLElement* HTMLDetailsConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLDetailsElement>(document);
}
static HTMLElement* HTMLDfnConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kDfnTag, document);
}
static HTMLElement* HTMLDialogConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLDialogElement>(document);
}
static HTMLElement* HTMLDirConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLDirectoryElement>(document);
}
static HTMLElement* HTMLDivConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLDivElement>(document);
}
static HTMLElement* HTMLDlConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLDListElement>(document);
}
static HTMLElement* HTMLDtConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kDtTag, document);
}
static HTMLElement* HTMLEmConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kEmTag, document);
}
static HTMLElement* HTMLEmbedConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLEmbedElement>(document, flags);
}
static HTMLElement* HTMLFencedframeConstructor(Document& document, const CreateElementFlags flags)
{
    if (!RuntimeEnabledFeatures::FencedFramesEnabled(document.GetExecutionContext()))
        return MakeGarbageCollected<HTMLUnknownElement>(html_names::kFencedframeTag, document);
    return MakeGarbageCollected<HTMLFencedFrameElement>(document);
}
static HTMLElement* HTMLFieldsetConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLFieldSetElement>(document);
}
static HTMLElement* HTMLFigcaptionConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kFigcaptionTag, document);
}
static HTMLElement* HTMLFigureConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kFigureTag, document);
}
static HTMLElement* HTMLFontConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLFontElement>(document);
}
static HTMLElement* HTMLFooterConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kFooterTag, document);
}
static HTMLElement* HTMLFormConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLFormElement>(document);
}
static HTMLElement* HTMLFrameConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLFrameElement>(document);
}
static HTMLElement* HTMLFramesetConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLFrameSetElement>(document);
}
static HTMLElement* HTMLH1Constructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLHeadingElement>(html_names::kH1Tag, document);
}
static HTMLElement* HTMLH2Constructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLHeadingElement>(html_names::kH2Tag, document);
}
static HTMLElement* HTMLH3Constructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLHeadingElement>(html_names::kH3Tag, document);
}
static HTMLElement* HTMLH4Constructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLHeadingElement>(html_names::kH4Tag, document);
}
static HTMLElement* HTMLH5Constructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLHeadingElement>(html_names::kH5Tag, document);
}
static HTMLElement* HTMLH6Constructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLHeadingElement>(html_names::kH6Tag, document);
}
static HTMLElement* HTMLHeadConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLHeadElement>(document);
}
static HTMLElement* HTMLHeaderConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kHeaderTag, document);
}
static HTMLElement* HTMLHgroupConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kHgroupTag, document);
}
static HTMLElement* HTMLHrConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLHRElement>(document);
}
static HTMLElement* HTMLHTMLConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLHtmlElement>(document);
}
static HTMLElement* HTMLIConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kITag, document);
}
static HTMLElement* HTMLIFrameConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLIFrameElement>(document);
}
static HTMLElement* HTMLImageConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLUnknownElement>(html_names::kImageTag, document);
}
static HTMLElement* HTMLImgConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLImageElement>(document, flags);
}
static HTMLElement* HTMLInputConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLInputElement>(document, flags);
}
static HTMLElement* HTMLInsConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLModElement>(html_names::kInsTag, document);
}
static HTMLElement* HTMLKbdConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kKbdTag, document);
}
static HTMLElement* HTMLKeygenConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLUnknownElement>(html_names::kKeygenTag, document);
}
static HTMLElement* HTMLLabelConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLLabelElement>(document);
}
static HTMLElement* HTMLLayerConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kLayerTag, document);
}
static HTMLElement* HTMLLegendConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLLegendElement>(document);
}
static HTMLElement* HTMLLiConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLLIElement>(document);
}
static HTMLElement* HTMLLinkConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLLinkElement>(document, flags);
}
static HTMLElement* HTMLListingConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLPreElement>(html_names::kListingTag, document);
}
static HTMLElement* HTMLMainConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kMainTag, document);
}
static HTMLElement* HTMLMapConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLMapElement>(document);
}
static HTMLElement* HTMLMarkConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kMarkTag, document);
}
static HTMLElement* HTMLMarqueeConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLMarqueeElement>(document);
}
static HTMLElement* HTMLMenuConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLMenuElement>(document);
}
static HTMLElement* HTMLMetaConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLMetaElement>(document, flags);
}
static HTMLElement* HTMLMeterConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLMeterElement>(document);
}
static HTMLElement* HTMLNavConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kNavTag, document);
}
static HTMLElement* HTMLNobrConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kNobrTag, document);
}
static HTMLElement* HTMLNoembedConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLNoEmbedElement>(document);
}
static HTMLElement* HTMLNoframesConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kNoframesTag, document);
}
static HTMLElement* HTMLNolayerConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kNolayerTag, document);
}
static HTMLElement* HTMLNoscriptConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLNoScriptElement>(document);
}
static HTMLElement* HTMLObjectConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLObjectElement>(document, flags);
}
static HTMLElement* HTMLOlConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLOListElement>(document);
}
static HTMLElement* HTMLOptgroupConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLOptGroupElement>(document);
}
static HTMLElement* HTMLOptionConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLOptionElement>(document);
}
static HTMLElement* HTMLOutputConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLOutputElement>(document);
}
static HTMLElement* HTMLPConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLParagraphElement>(document);
}
static HTMLElement* HTMLParamConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLParamElement>(document);
}
static HTMLElement* HTMLPermissionConstructor(Document& document, const CreateElementFlags flags)
{
    if (!RuntimeEnabledFeatures::PermissionElementEnabled(document.GetExecutionContext()))
        return MakeGarbageCollected<HTMLUnknownElement>(html_names::kPermissionTag, document);
    return MakeGarbageCollected<HTMLPermissionElement>(document);
}
static HTMLElement* HTMLPictureConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLPictureElement>(document);
}
static HTMLElement* HTMLPlaintextConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kPlaintextTag, document);
}
static HTMLElement* HTMLPreConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLPreElement>(html_names::kPreTag, document);
}
static HTMLElement* HTMLProgressConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLProgressElement>(document);
}
static HTMLElement* HTMLQConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLQuoteElement>(html_names::kQTag, document);
}
static HTMLElement* HTMLRbConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kRbTag, document);
}
static HTMLElement* HTMLRpConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kRpTag, document);
}
static HTMLElement* HTMLRtConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kRtTag, document);
}
static HTMLElement* HTMLRTCConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kRTCTag, document);
}
static HTMLElement* HTMLRubyConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kRubyTag, document);
}
static HTMLElement* HTMLSConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kSTag, document);
}
static HTMLElement* HTMLSampConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kSampTag, document);
}
static HTMLElement* HTMLScriptConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLScriptElement>(document, flags);
}
static HTMLElement* HTMLSearchConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLSearchElement>(document);
}
static HTMLElement* HTMLSectionConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kSectionTag, document);
}
static HTMLElement* HTMLSelectConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLSelectElement>(document);
}
static HTMLElement* HTMLSelectedcontentConstructor(Document& document, const CreateElementFlags flags)
{
    if (!RuntimeEnabledFeatures::CustomizableSelectEnabled(document.GetExecutionContext()))
        return MakeGarbageCollected<HTMLUnknownElement>(html_names::kSelectedcontentTag, document);
    return MakeGarbageCollected<HTMLSelectedContentElement>(document);
}
static HTMLElement* HTMLSlotConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLSlotElement>(document);
}
static HTMLElement* HTMLSmallConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kSmallTag, document);
}
static HTMLElement* HTMLSourceConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLSourceElement>(document);
}
static HTMLElement* HTMLSpanConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLSpanElement>(document);
}
static HTMLElement* HTMLStrikeConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kStrikeTag, document);
}
static HTMLElement* HTMLStrongConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kStrongTag, document);
}
static HTMLElement* HTMLStyleConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLStyleElement>(document, flags);
}
static HTMLElement* HTMLSubConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kSubTag, document);
}
static HTMLElement* HTMLSummaryConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLSummaryElement>(document);
}
static HTMLElement* HTMLSupConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kSupTag, document);
}
static HTMLElement* HTMLTableConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLTableElement>(document);
}
static HTMLElement* HTMLTbodyConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLTableSectionElement>(html_names::kTbodyTag, document);
}
static HTMLElement* HTMLTdConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLTableCellElement>(html_names::kTdTag, document);
}
static HTMLElement* HTMLTemplateConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLTemplateElement>(document);
}
static HTMLElement* HTMLTextareaConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLTextAreaElement>(document);
}
static HTMLElement* HTMLTfootConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLTableSectionElement>(html_names::kTfootTag, document);
}
static HTMLElement* HTMLThConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLTableCellElement>(html_names::kThTag, document);
}
static HTMLElement* HTMLTheadConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLTableSectionElement>(html_names::kTheadTag, document);
}
static HTMLElement* HTMLTimeConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLTimeElement>(document);
}
static HTMLElement* HTMLTitleConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLTitleElement>(document);
}
static HTMLElement* HTMLTrConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLTableRowElement>(document);
}
static HTMLElement* HTMLTrackConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLTrackElement>(document);
}
static HTMLElement* HTMLTtConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kTtTag, document);
}
static HTMLElement* HTMLUConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kUTag, document);
}
static HTMLElement* HTMLUlConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLUListElement>(document);
}
static HTMLElement* HTMLVarConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLElement>(html_names::kVarTag, document);
}
static HTMLElement* HTMLVideoConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLVideoElement>(document);
}
static HTMLElement* HTMLWbrConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLWBRElement>(document);
}
static HTMLElement* HTMLXmpConstructor(Document& document, const CreateElementFlags flags)
{
    return MakeGarbageCollected<HTMLPreElement>(html_names::kXmpTag, document);
}

struct CreateHTMLFunctionMapData {
    const QualifiedName& tag;
    HTMLConstructorFunction func;
};

static void CreateHTMLFunctionMap()
{
    DCHECK(!g_html_constructors);
    g_html_constructors = new HTMLFunctionMap;
    // Empty array initializer lists are illegal [dcl.init.aggr] and will not
    // compile in MSVC. If tags list is empty, add check to skip this.
    static const CreateHTMLFunctionMapData data[] = {
        { html_names::kATag, HTMLAConstructor },
        { html_names::kAbbrTag, HTMLAbbrConstructor },
        { html_names::kAcronymTag, HTMLAcronymConstructor },
        { html_names::kAddressTag, HTMLAddressConstructor },
        { html_names::kAppletTag, HTMLAppletConstructor },
        { html_names::kAreaTag, HTMLAreaConstructor },
        { html_names::kArticleTag, HTMLArticleConstructor },
        { html_names::kAsideTag, HTMLAsideConstructor },
        { html_names::kAudioTag, HTMLAudioConstructor },
        { html_names::kBTag, HTMLBConstructor },
        { html_names::kBaseTag, HTMLBaseConstructor },
        { html_names::kBasefontTag, HTMLBasefontConstructor },
        { html_names::kBdiTag, HTMLBdiConstructor },
        { html_names::kBdoTag, HTMLBdoConstructor },
        { html_names::kBgsoundTag, HTMLBgsoundConstructor },
        { html_names::kBigTag, HTMLBigConstructor },
        { html_names::kBlockquoteTag, HTMLBlockquoteConstructor },
        { html_names::kBodyTag, HTMLBodyConstructor },
        { html_names::kBrTag, HTMLBrConstructor },
        { html_names::kButtonTag, HTMLButtonConstructor },
        { html_names::kCanvasTag, HTMLCanvasConstructor },
        { html_names::kCaptionTag, HTMLCaptionConstructor },
        { html_names::kCenterTag, HTMLCenterConstructor },
        { html_names::kCiteTag, HTMLCiteConstructor },
        { html_names::kCodeTag, HTMLCodeConstructor },
        { html_names::kColTag, HTMLColConstructor },
        { html_names::kColgroupTag, HTMLColgroupConstructor },
        { html_names::kCommandTag, HTMLCommandConstructor },
        { html_names::kDataTag, HTMLDataConstructor },
        { html_names::kDatalistTag, HTMLDatalistConstructor },
        { html_names::kDdTag, HTMLDdConstructor },
        { html_names::kDelTag, HTMLDelConstructor },
        { html_names::kDetailsTag, HTMLDetailsConstructor },
        { html_names::kDfnTag, HTMLDfnConstructor },
        { html_names::kDialogTag, HTMLDialogConstructor },
        { html_names::kDirTag, HTMLDirConstructor },
        { html_names::kDivTag, HTMLDivConstructor },
        { html_names::kDlTag, HTMLDlConstructor },
        { html_names::kDtTag, HTMLDtConstructor },
        { html_names::kEmTag, HTMLEmConstructor },
        { html_names::kEmbedTag, HTMLEmbedConstructor },
        { html_names::kFencedframeTag, HTMLFencedframeConstructor },
        { html_names::kFieldsetTag, HTMLFieldsetConstructor },
        { html_names::kFigcaptionTag, HTMLFigcaptionConstructor },
        { html_names::kFigureTag, HTMLFigureConstructor },
        { html_names::kFontTag, HTMLFontConstructor },
        { html_names::kFooterTag, HTMLFooterConstructor },
        { html_names::kFormTag, HTMLFormConstructor },
        { html_names::kFrameTag, HTMLFrameConstructor },
        { html_names::kFramesetTag, HTMLFramesetConstructor },
        { html_names::kH1Tag, HTMLH1Constructor },
        { html_names::kH2Tag, HTMLH2Constructor },
        { html_names::kH3Tag, HTMLH3Constructor },
        { html_names::kH4Tag, HTMLH4Constructor },
        { html_names::kH5Tag, HTMLH5Constructor },
        { html_names::kH6Tag, HTMLH6Constructor },
        { html_names::kHeadTag, HTMLHeadConstructor },
        { html_names::kHeaderTag, HTMLHeaderConstructor },
        { html_names::kHgroupTag, HTMLHgroupConstructor },
        { html_names::kHrTag, HTMLHrConstructor },
        { html_names::kHTMLTag, HTMLHTMLConstructor },
        { html_names::kITag, HTMLIConstructor },
        { html_names::kIFrameTag, HTMLIFrameConstructor },
        { html_names::kImageTag, HTMLImageConstructor },
        { html_names::kImgTag, HTMLImgConstructor },
        { html_names::kInputTag, HTMLInputConstructor },
        { html_names::kInsTag, HTMLInsConstructor },
        { html_names::kKbdTag, HTMLKbdConstructor },
        { html_names::kKeygenTag, HTMLKeygenConstructor },
        { html_names::kLabelTag, HTMLLabelConstructor },
        { html_names::kLayerTag, HTMLLayerConstructor },
        { html_names::kLegendTag, HTMLLegendConstructor },
        { html_names::kLiTag, HTMLLiConstructor },
        { html_names::kLinkTag, HTMLLinkConstructor },
        { html_names::kListingTag, HTMLListingConstructor },
        { html_names::kMainTag, HTMLMainConstructor },
        { html_names::kMapTag, HTMLMapConstructor },
        { html_names::kMarkTag, HTMLMarkConstructor },
        { html_names::kMarqueeTag, HTMLMarqueeConstructor },
        { html_names::kMenuTag, HTMLMenuConstructor },
        { html_names::kMetaTag, HTMLMetaConstructor },
        { html_names::kMeterTag, HTMLMeterConstructor },
        { html_names::kNavTag, HTMLNavConstructor },
        { html_names::kNobrTag, HTMLNobrConstructor },
        { html_names::kNoembedTag, HTMLNoembedConstructor },
        { html_names::kNoframesTag, HTMLNoframesConstructor },
        { html_names::kNolayerTag, HTMLNolayerConstructor },
        { html_names::kNoscriptTag, HTMLNoscriptConstructor },
        { html_names::kObjectTag, HTMLObjectConstructor },
        { html_names::kOlTag, HTMLOlConstructor },
        { html_names::kOptgroupTag, HTMLOptgroupConstructor },
        { html_names::kOptionTag, HTMLOptionConstructor },
        { html_names::kOutputTag, HTMLOutputConstructor },
        { html_names::kPTag, HTMLPConstructor },
        { html_names::kParamTag, HTMLParamConstructor },
        { html_names::kPermissionTag, HTMLPermissionConstructor },
        { html_names::kPictureTag, HTMLPictureConstructor },
        { html_names::kPlaintextTag, HTMLPlaintextConstructor },
        { html_names::kPreTag, HTMLPreConstructor },
        { html_names::kProgressTag, HTMLProgressConstructor },
        { html_names::kQTag, HTMLQConstructor },
        { html_names::kRbTag, HTMLRbConstructor },
        { html_names::kRpTag, HTMLRpConstructor },
        { html_names::kRtTag, HTMLRtConstructor },
        { html_names::kRTCTag, HTMLRTCConstructor },
        { html_names::kRubyTag, HTMLRubyConstructor },
        { html_names::kSTag, HTMLSConstructor },
        { html_names::kSampTag, HTMLSampConstructor },
        { html_names::kScriptTag, HTMLScriptConstructor },
        { html_names::kSearchTag, HTMLSearchConstructor },
        { html_names::kSectionTag, HTMLSectionConstructor },
        { html_names::kSelectTag, HTMLSelectConstructor },
        { html_names::kSelectedcontentTag, HTMLSelectedcontentConstructor },
        { html_names::kSlotTag, HTMLSlotConstructor },
        { html_names::kSmallTag, HTMLSmallConstructor },
        { html_names::kSourceTag, HTMLSourceConstructor },
        { html_names::kSpanTag, HTMLSpanConstructor },
        { html_names::kStrikeTag, HTMLStrikeConstructor },
        { html_names::kStrongTag, HTMLStrongConstructor },
        { html_names::kStyleTag, HTMLStyleConstructor },
        { html_names::kSubTag, HTMLSubConstructor },
        { html_names::kSummaryTag, HTMLSummaryConstructor },
        { html_names::kSupTag, HTMLSupConstructor },
        { html_names::kTableTag, HTMLTableConstructor },
        { html_names::kTbodyTag, HTMLTbodyConstructor },
        { html_names::kTdTag, HTMLTdConstructor },
        { html_names::kTemplateTag, HTMLTemplateConstructor },
        { html_names::kTextareaTag, HTMLTextareaConstructor },
        { html_names::kTfootTag, HTMLTfootConstructor },
        { html_names::kThTag, HTMLThConstructor },
        { html_names::kTheadTag, HTMLTheadConstructor },
        { html_names::kTimeTag, HTMLTimeConstructor },
        { html_names::kTitleTag, HTMLTitleConstructor },
        { html_names::kTrTag, HTMLTrConstructor },
        { html_names::kTrackTag, HTMLTrackConstructor },
        { html_names::kTtTag, HTMLTtConstructor },
        { html_names::kUTag, HTMLUConstructor },
        { html_names::kUlTag, HTMLUlConstructor },
        { html_names::kVarTag, HTMLVarConstructor },
        { html_names::kVideoTag, HTMLVideoConstructor },
        { html_names::kWbrTag, HTMLWbrConstructor },
        { html_names::kXmpTag, HTMLXmpConstructor },
    };
    for (size_t i = 0; i < std::size(data); i++)
        g_html_constructors->Set(data[i].tag.LocalName(), data[i].func);
}

HTMLElement* HTMLElementFactory::Create(const AtomicString& local_name, Document& document, const CreateElementFlags flags)
{
    if (!g_html_constructors)
        CreateHTMLFunctionMap();
    auto it = g_html_constructors->find(local_name);
    if (it == g_html_constructors->end())
        return nullptr;
    HTMLConstructorFunction function = it->value;
    return function(document, flags);
}

} // namespace blink
