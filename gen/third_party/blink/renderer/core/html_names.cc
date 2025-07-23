// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_qualified_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/aria_properties.json5
//   ../../third_party/blink/renderer/core/html/html_attribute_names.json5
//   ../../third_party/blink/renderer/core/html/html_tag_names.json5

#include "third_party/blink/renderer/core/html_names.h"

#include <memory>

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/static_constructors.h"
#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace html_names {

DEFINE_GLOBAL(AtomicString, xhtmlNamespaceURI);

// Tags

void* tag_storage[kTagsCount * ((sizeof(HTMLQualifiedName) + sizeof(void*) - 1) / sizeof(void*))];
const HTMLQualifiedName& kATag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[0];
const HTMLQualifiedName& kAbbrTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[1];
const HTMLQualifiedName& kAcronymTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[2];
const HTMLQualifiedName& kAddressTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[3];
const HTMLQualifiedName& kAppletTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[4];
const HTMLQualifiedName& kAreaTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[5];
const HTMLQualifiedName& kArticleTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[6];
const HTMLQualifiedName& kAsideTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[7];
const HTMLQualifiedName& kAudioTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[8];
const HTMLQualifiedName& kBTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[9];
const HTMLQualifiedName& kBaseTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[10];
const HTMLQualifiedName& kBasefontTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[11];
const HTMLQualifiedName& kBdiTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[12];
const HTMLQualifiedName& kBdoTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[13];
const HTMLQualifiedName& kBgsoundTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[14];
const HTMLQualifiedName& kBigTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[15];
const HTMLQualifiedName& kBlockquoteTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[16];
const HTMLQualifiedName& kBodyTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[17];
const HTMLQualifiedName& kBrTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[18];
const HTMLQualifiedName& kButtonTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[19];
const HTMLQualifiedName& kCanvasTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[20];
const HTMLQualifiedName& kCaptionTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[21];
const HTMLQualifiedName& kCenterTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[22];
const HTMLQualifiedName& kCiteTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[23];
const HTMLQualifiedName& kCodeTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[24];
const HTMLQualifiedName& kColTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[25];
const HTMLQualifiedName& kColgroupTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[26];
const HTMLQualifiedName& kCommandTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[27];
const HTMLQualifiedName& kDataTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[28];
const HTMLQualifiedName& kDatalistTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[29];
const HTMLQualifiedName& kDdTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[30];
const HTMLQualifiedName& kDelTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[31];
const HTMLQualifiedName& kDetailsTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[32];
const HTMLQualifiedName& kDfnTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[33];
const HTMLQualifiedName& kDialogTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[34];
const HTMLQualifiedName& kDirTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[35];
const HTMLQualifiedName& kDivTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[36];
const HTMLQualifiedName& kDlTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[37];
const HTMLQualifiedName& kDtTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[38];
const HTMLQualifiedName& kEmTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[39];
const HTMLQualifiedName& kEmbedTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[40];
const HTMLQualifiedName& kFencedframeTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[41];
const HTMLQualifiedName& kFieldsetTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[42];
const HTMLQualifiedName& kFigcaptionTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[43];
const HTMLQualifiedName& kFigureTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[44];
const HTMLQualifiedName& kFontTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[45];
const HTMLQualifiedName& kFooterTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[46];
const HTMLQualifiedName& kFormTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[47];
const HTMLQualifiedName& kFrameTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[48];
const HTMLQualifiedName& kFramesetTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[49];
const HTMLQualifiedName& kH1Tag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[50];
const HTMLQualifiedName& kH2Tag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[51];
const HTMLQualifiedName& kH3Tag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[52];
const HTMLQualifiedName& kH4Tag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[53];
const HTMLQualifiedName& kH5Tag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[54];
const HTMLQualifiedName& kH6Tag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[55];
const HTMLQualifiedName& kHeadTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[56];
const HTMLQualifiedName& kHeaderTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[57];
const HTMLQualifiedName& kHgroupTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[58];
const HTMLQualifiedName& kHrTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[59];
const HTMLQualifiedName& kHTMLTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[60];
const HTMLQualifiedName& kITag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[61];
const HTMLQualifiedName& kIFrameTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[62];
const HTMLQualifiedName& kImageTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[63];
const HTMLQualifiedName& kImgTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[64];
const HTMLQualifiedName& kInputTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[65];
const HTMLQualifiedName& kInsTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[66];
const HTMLQualifiedName& kKbdTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[67];
const HTMLQualifiedName& kKeygenTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[68];
const HTMLQualifiedName& kLabelTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[69];
const HTMLQualifiedName& kLayerTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[70];
const HTMLQualifiedName& kLegendTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[71];
const HTMLQualifiedName& kLiTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[72];
const HTMLQualifiedName& kLinkTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[73];
const HTMLQualifiedName& kListingTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[74];
const HTMLQualifiedName& kMainTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[75];
const HTMLQualifiedName& kMapTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[76];
const HTMLQualifiedName& kMarkTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[77];
const HTMLQualifiedName& kMarqueeTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[78];
const HTMLQualifiedName& kMenuTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[79];
const HTMLQualifiedName& kMetaTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[80];
const HTMLQualifiedName& kMeterTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[81];
const HTMLQualifiedName& kNavTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[82];
const HTMLQualifiedName& kNobrTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[83];
const HTMLQualifiedName& kNoembedTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[84];
const HTMLQualifiedName& kNoframesTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[85];
const HTMLQualifiedName& kNolayerTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[86];
const HTMLQualifiedName& kNoscriptTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[87];
const HTMLQualifiedName& kObjectTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[88];
const HTMLQualifiedName& kOlTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[89];
const HTMLQualifiedName& kOptgroupTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[90];
const HTMLQualifiedName& kOptionTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[91];
const HTMLQualifiedName& kOutputTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[92];
const HTMLQualifiedName& kPTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[93];
const HTMLQualifiedName& kParamTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[94];
const HTMLQualifiedName& kPermissionTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[95];
const HTMLQualifiedName& kPictureTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[96];
const HTMLQualifiedName& kPlaintextTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[97];
const HTMLQualifiedName& kPreTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[98];
const HTMLQualifiedName& kProgressTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[99];
const HTMLQualifiedName& kQTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[100];
const HTMLQualifiedName& kRbTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[101];
const HTMLQualifiedName& kRpTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[102];
const HTMLQualifiedName& kRtTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[103];
const HTMLQualifiedName& kRTCTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[104];
const HTMLQualifiedName& kRubyTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[105];
const HTMLQualifiedName& kSTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[106];
const HTMLQualifiedName& kSampTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[107];
const HTMLQualifiedName& kScriptTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[108];
const HTMLQualifiedName& kSearchTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[109];
const HTMLQualifiedName& kSectionTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[110];
const HTMLQualifiedName& kSelectTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[111];
const HTMLQualifiedName& kSelectedcontentTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[112];
const HTMLQualifiedName& kSlotTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[113];
const HTMLQualifiedName& kSmallTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[114];
const HTMLQualifiedName& kSourceTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[115];
const HTMLQualifiedName& kSpanTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[116];
const HTMLQualifiedName& kStrikeTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[117];
const HTMLQualifiedName& kStrongTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[118];
const HTMLQualifiedName& kStyleTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[119];
const HTMLQualifiedName& kSubTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[120];
const HTMLQualifiedName& kSummaryTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[121];
const HTMLQualifiedName& kSupTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[122];
const HTMLQualifiedName& kTableTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[123];
const HTMLQualifiedName& kTbodyTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[124];
const HTMLQualifiedName& kTdTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[125];
const HTMLQualifiedName& kTemplateTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[126];
const HTMLQualifiedName& kTextareaTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[127];
const HTMLQualifiedName& kTfootTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[128];
const HTMLQualifiedName& kThTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[129];
const HTMLQualifiedName& kTheadTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[130];
const HTMLQualifiedName& kTimeTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[131];
const HTMLQualifiedName& kTitleTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[132];
const HTMLQualifiedName& kTrTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[133];
const HTMLQualifiedName& kTrackTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[134];
const HTMLQualifiedName& kTtTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[135];
const HTMLQualifiedName& kUTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[136];
const HTMLQualifiedName& kUlTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[137];
const HTMLQualifiedName& kVarTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[138];
const HTMLQualifiedName& kVideoTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[139];
const HTMLQualifiedName& kWbrTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[140];
const HTMLQualifiedName& kXmpTag = reinterpret_cast<HTMLQualifiedName*>(&tag_storage)[141];

std::unique_ptr<const HTMLQualifiedName*[]> GetTags()
{
    auto tags = std::make_unique<const HTMLQualifiedName*[]>(kTagsCount);
    for (size_t i = 0; i < kTagsCount; ++i)
        tags[i] = reinterpret_cast<HTMLQualifiedName*>(&tag_storage) + i;
    return tags;
}

// Attributes

void* attr_storage[kAttrsCount * ((sizeof(QualifiedName) + sizeof(void*) - 1) / sizeof(void*))];

const QualifiedName& kAbbrAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[0];
const QualifiedName& kAcceptAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[1];
const QualifiedName& kAcceptCharsetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[2];
const QualifiedName& kAccesskeyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[3];
const QualifiedName& kActionAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[4];
const QualifiedName& kAdauctionheadersAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[5];
const QualifiedName& kAlignAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[6];
const QualifiedName& kAlinkAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[7];
const QualifiedName& kAllowAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[8];
const QualifiedName& kAllowfullscreenAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[9];
const QualifiedName& kAllowpaymentrequestAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[10];
const QualifiedName& kAltAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[11];
const QualifiedName& kAnchorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[12];
const QualifiedName& kArchiveAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[13];
const QualifiedName& kAriaActionsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[14];
const QualifiedName& kAriaActivedescendantAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[15];
const QualifiedName& kAriaAtomicAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[16];
const QualifiedName& kAriaAutocompleteAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[17];
const QualifiedName& kAriaBraillelabelAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[18];
const QualifiedName& kAriaBrailleroledescriptionAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[19];
const QualifiedName& kAriaBusyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[20];
const QualifiedName& kAriaCheckedAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[21];
const QualifiedName& kAriaColcountAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[22];
const QualifiedName& kAriaColindexAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[23];
const QualifiedName& kAriaColindextextAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[24];
const QualifiedName& kAriaColspanAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[25];
const QualifiedName& kAriaControlsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[26];
const QualifiedName& kAriaCurrentAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[27];
const QualifiedName& kAriaDescribedbyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[28];
const QualifiedName& kAriaDescriptionAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[29];
const QualifiedName& kAriaDetailsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[30];
const QualifiedName& kAriaDisabledAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[31];
const QualifiedName& kAriaErrormessageAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[32];
const QualifiedName& kAriaExpandedAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[33];
const QualifiedName& kAriaFlowtoAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[34];
const QualifiedName& kAriaHaspopupAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[35];
const QualifiedName& kAriaHiddenAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[36];
const QualifiedName& kAriaInvalidAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[37];
const QualifiedName& kAriaKeyshortcutsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[38];
const QualifiedName& kAriaLabelAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[39];
const QualifiedName& kAriaLabeledbyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[40];
const QualifiedName& kAriaLabelledbyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[41];
const QualifiedName& kAriaLevelAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[42];
const QualifiedName& kAriaLiveAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[43];
const QualifiedName& kAriaModalAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[44];
const QualifiedName& kAriaMultilineAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[45];
const QualifiedName& kAriaMultiselectableAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[46];
const QualifiedName& kAriaOrientationAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[47];
const QualifiedName& kAriaOwnsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[48];
const QualifiedName& kAriaPlaceholderAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[49];
const QualifiedName& kAriaPosinsetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[50];
const QualifiedName& kAriaPressedAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[51];
const QualifiedName& kAriaReadonlyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[52];
const QualifiedName& kAriaRelevantAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[53];
const QualifiedName& kAriaRequiredAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[54];
const QualifiedName& kAriaRoledescriptionAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[55];
const QualifiedName& kAriaRowcountAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[56];
const QualifiedName& kAriaRowindexAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[57];
const QualifiedName& kAriaRowindextextAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[58];
const QualifiedName& kAriaRowspanAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[59];
const QualifiedName& kAriaSelectedAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[60];
const QualifiedName& kAriaSetsizeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[61];
const QualifiedName& kAriaSortAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[62];
const QualifiedName& kAriaValuemaxAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[63];
const QualifiedName& kAriaValueminAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[64];
const QualifiedName& kAriaValuenowAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[65];
const QualifiedName& kAriaValuetextAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[66];
const QualifiedName& kAriaVirtualcontentAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[67];
const QualifiedName& kAsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[68];
const QualifiedName& kAsyncAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[69];
const QualifiedName& kAttributionsrcAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[70];
const QualifiedName& kAutocapitalizeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[71];
const QualifiedName& kAutocompleteAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[72];
const QualifiedName& kAutocorrectAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[73];
const QualifiedName& kAutofocusAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[74];
const QualifiedName& kAutoplayAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[75];
const QualifiedName& kAxisAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[76];
const QualifiedName& kBackgroundAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[77];
const QualifiedName& kBehaviorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[78];
const QualifiedName& kBgcolorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[79];
const QualifiedName& kBlockingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[80];
const QualifiedName& kBorderAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[81];
const QualifiedName& kBordercolorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[82];
const QualifiedName& kBrowsingtopicsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[83];
const QualifiedName& kCaptureAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[84];
const QualifiedName& kCellpaddingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[85];
const QualifiedName& kCellspacingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[86];
const QualifiedName& kChallengeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[87];
const QualifiedName& kCharAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[88];
const QualifiedName& kCharoffAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[89];
const QualifiedName& kCharsetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[90];
const QualifiedName& kCheckedAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[91];
const QualifiedName& kCiteAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[92];
const QualifiedName& kClassAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[93];
const QualifiedName& kClassidAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[94];
const QualifiedName& kClearAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[95];
const QualifiedName& kClosedbyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[96];
const QualifiedName& kCodeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[97];
const QualifiedName& kCodebaseAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[98];
const QualifiedName& kCodetypeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[99];
const QualifiedName& kColorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[100];
const QualifiedName& kColsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[101];
const QualifiedName& kColspanAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[102];
const QualifiedName& kCommandAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[103];
const QualifiedName& kCommandforAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[104];
const QualifiedName& kCompactAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[105];
const QualifiedName& kContentAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[106];
const QualifiedName& kContenteditableAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[107];
const QualifiedName& kControlsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[108];
const QualifiedName& kControlslistAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[109];
const QualifiedName& kCoordsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[110];
const QualifiedName& kCredentiallessAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[111];
const QualifiedName& kCrossoriginAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[112];
const QualifiedName& kCspAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[113];
const QualifiedName& kDataAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[114];
const QualifiedName& kDataSrcAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[115];
const QualifiedName& kDatetimeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[116];
const QualifiedName& kDeclareAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[117];
const QualifiedName& kDecodingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[118];
const QualifiedName& kDefaultAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[119];
const QualifiedName& kDeferAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[120];
const QualifiedName& kDelegatesfocusAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[121];
const QualifiedName& kDirAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[122];
const QualifiedName& kDirectionAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[123];
const QualifiedName& kDirnameAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[124];
const QualifiedName& kDisabledAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[125];
const QualifiedName& kDisablepictureinpictureAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[126];
const QualifiedName& kDisableremoteplaybackAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[127];
const QualifiedName& kDownloadAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[128];
const QualifiedName& kDraggableAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[129];
const QualifiedName& kElementtimingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[130];
const QualifiedName& kEnctypeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[131];
const QualifiedName& kEndAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[132];
const QualifiedName& kEnterkeyhintAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[133];
const QualifiedName& kEventAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[134];
const QualifiedName& kExportpartsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[135];
const QualifiedName& kFaceAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[136];
const QualifiedName& kFetchpriorityAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[137];
const QualifiedName& kFocusgroupAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[138];
const QualifiedName& kForAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[139];
const QualifiedName& kFormAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[140];
const QualifiedName& kFormactionAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[141];
const QualifiedName& kFormenctypeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[142];
const QualifiedName& kFormmethodAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[143];
const QualifiedName& kFormnovalidateAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[144];
const QualifiedName& kFormtargetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[145];
const QualifiedName& kFrameAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[146];
const QualifiedName& kFrameborderAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[147];
const QualifiedName& kHeadersAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[148];
const QualifiedName& kHeightAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[149];
const QualifiedName& kHiddenAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[150];
const QualifiedName& kHighAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[151];
const QualifiedName& kHrefAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[152];
const QualifiedName& kHreflangAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[153];
const QualifiedName& kHreftranslateAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[154];
const QualifiedName& kHspaceAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[155];
const QualifiedName& kHttpEquivAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[156];
const QualifiedName& kIdAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[157];
const QualifiedName& kImagesizesAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[158];
const QualifiedName& kImagesrcsetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[159];
const QualifiedName& kIncrementalAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[160];
const QualifiedName& kInertAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[161];
const QualifiedName& kInputmodeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[162];
const QualifiedName& kIntegrityAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[163];
const QualifiedName& kInterestactionAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[164];
const QualifiedName& kInteresttargetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[165];
const QualifiedName& kInvisibleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[166];
const QualifiedName& kIsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[167];
const QualifiedName& kIsmapAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[168];
const QualifiedName& kItempropAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[169];
const QualifiedName& kKeytypeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[170];
const QualifiedName& kKindAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[171];
const QualifiedName& kLabelAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[172];
const QualifiedName& kLangAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[173];
const QualifiedName& kLanguageAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[174];
const QualifiedName& kLatencyhintAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[175];
const QualifiedName& kLeftmarginAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[176];
const QualifiedName& kLinkAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[177];
const QualifiedName& kListAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[178];
const QualifiedName& kLoadingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[179];
const QualifiedName& kLongdescAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[180];
const QualifiedName& kLoopAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[181];
const QualifiedName& kLowAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[182];
const QualifiedName& kLowsrcAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[183];
const QualifiedName& kManifestAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[184];
const QualifiedName& kMarginheightAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[185];
const QualifiedName& kMarginwidthAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[186];
const QualifiedName& kMaxAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[187];
const QualifiedName& kMaxlengthAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[188];
const QualifiedName& kMayscriptAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[189];
const QualifiedName& kMediaAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[190];
const QualifiedName& kMethodAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[191];
const QualifiedName& kMinAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[192];
const QualifiedName& kMinlengthAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[193];
const QualifiedName& kMultipleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[194];
const QualifiedName& kMutedAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[195];
const QualifiedName& kNameAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[196];
const QualifiedName& kNohrefAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[197];
const QualifiedName& kNomoduleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[198];
const QualifiedName& kNonceAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[199];
const QualifiedName& kNoresizeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[200];
const QualifiedName& kNoshadeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[201];
const QualifiedName& kNovalidateAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[202];
const QualifiedName& kNowrapAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[203];
const QualifiedName& kObjectAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[204];
const QualifiedName& kOnabortAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[205];
const QualifiedName& kOnafterprintAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[206];
const QualifiedName& kOnanimationendAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[207];
const QualifiedName& kOnanimationiterationAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[208];
const QualifiedName& kOnanimationstartAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[209];
const QualifiedName& kOnauxclickAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[210];
const QualifiedName& kOnbeforecopyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[211];
const QualifiedName& kOnbeforecutAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[212];
const QualifiedName& kOnbeforeinputAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[213];
const QualifiedName& kOnbeforepasteAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[214];
const QualifiedName& kOnbeforeprintAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[215];
const QualifiedName& kOnbeforetoggleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[216];
const QualifiedName& kOnbeforeunloadAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[217];
const QualifiedName& kOnblurAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[218];
const QualifiedName& kOncancelAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[219];
const QualifiedName& kOncanplayAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[220];
const QualifiedName& kOncanplaythroughAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[221];
const QualifiedName& kOnchangeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[222];
const QualifiedName& kOnclickAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[223];
const QualifiedName& kOncloseAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[224];
const QualifiedName& kOncontentvisibilityautostatechangeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[225];
const QualifiedName& kOncontextlostAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[226];
const QualifiedName& kOncontextmenuAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[227];
const QualifiedName& kOncontextrestoredAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[228];
const QualifiedName& kOncopyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[229];
const QualifiedName& kOncuechangeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[230];
const QualifiedName& kOncutAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[231];
const QualifiedName& kOndblclickAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[232];
const QualifiedName& kOndismissAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[233];
const QualifiedName& kOndragAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[234];
const QualifiedName& kOndragendAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[235];
const QualifiedName& kOndragenterAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[236];
const QualifiedName& kOndragleaveAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[237];
const QualifiedName& kOndragoverAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[238];
const QualifiedName& kOndragstartAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[239];
const QualifiedName& kOndropAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[240];
const QualifiedName& kOndurationchangeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[241];
const QualifiedName& kOnemptiedAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[242];
const QualifiedName& kOnendedAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[243];
const QualifiedName& kOnerrorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[244];
const QualifiedName& kOnfocusAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[245];
const QualifiedName& kOnfocusinAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[246];
const QualifiedName& kOnfocusoutAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[247];
const QualifiedName& kOnformdataAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[248];
const QualifiedName& kOngotpointercaptureAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[249];
const QualifiedName& kOnhashchangeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[250];
const QualifiedName& kOninputAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[251];
const QualifiedName& kOninvalidAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[252];
const QualifiedName& kOnkeydownAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[253];
const QualifiedName& kOnkeypressAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[254];
const QualifiedName& kOnkeyupAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[255];
const QualifiedName& kOnlanguagechangeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[256];
const QualifiedName& kOnloadAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[257];
const QualifiedName& kOnloadeddataAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[258];
const QualifiedName& kOnloadedmetadataAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[259];
const QualifiedName& kOnloadstartAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[260];
const QualifiedName& kOnlostpointercaptureAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[261];
const QualifiedName& kOnmessageAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[262];
const QualifiedName& kOnmessageerrorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[263];
const QualifiedName& kOnmousedownAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[264];
const QualifiedName& kOnmouseenterAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[265];
const QualifiedName& kOnmouseleaveAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[266];
const QualifiedName& kOnmousemoveAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[267];
const QualifiedName& kOnmouseoutAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[268];
const QualifiedName& kOnmouseoverAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[269];
const QualifiedName& kOnmouseupAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[270];
const QualifiedName& kOnmousewheelAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[271];
const QualifiedName& kOnmoveAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[272];
const QualifiedName& kOnofflineAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[273];
const QualifiedName& kOnonlineAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[274];
const QualifiedName& kOnorientationchangeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[275];
const QualifiedName& kOnoverscrollAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[276];
const QualifiedName& kOnpagehideAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[277];
const QualifiedName& kOnpageshowAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[278];
const QualifiedName& kOnpasteAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[279];
const QualifiedName& kOnpauseAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[280];
const QualifiedName& kOnplayAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[281];
const QualifiedName& kOnplayingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[282];
const QualifiedName& kOnpointercancelAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[283];
const QualifiedName& kOnpointerdownAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[284];
const QualifiedName& kOnpointerenterAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[285];
const QualifiedName& kOnpointerleaveAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[286];
const QualifiedName& kOnpointermoveAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[287];
const QualifiedName& kOnpointeroutAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[288];
const QualifiedName& kOnpointeroverAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[289];
const QualifiedName& kOnpointerrawupdateAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[290];
const QualifiedName& kOnpointerupAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[291];
const QualifiedName& kOnpopstateAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[292];
const QualifiedName& kOnprogressAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[293];
const QualifiedName& kOnratechangeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[294];
const QualifiedName& kOnresetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[295];
const QualifiedName& kOnresizeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[296];
const QualifiedName& kOnresolveAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[297];
const QualifiedName& kOnscrollAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[298];
const QualifiedName& kOnscrollendAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[299];
const QualifiedName& kOnscrollsnapchangeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[300];
const QualifiedName& kOnscrollsnapchangingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[301];
const QualifiedName& kOnsearchAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[302];
const QualifiedName& kOnsecuritypolicyviolationAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[303];
const QualifiedName& kOnseekedAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[304];
const QualifiedName& kOnseekingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[305];
const QualifiedName& kOnselectAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[306];
const QualifiedName& kOnselectionchangeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[307];
const QualifiedName& kOnselectstartAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[308];
const QualifiedName& kOnshowAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[309];
const QualifiedName& kOnslotchangeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[310];
const QualifiedName& kOnstalledAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[311];
const QualifiedName& kOnstorageAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[312];
const QualifiedName& kOnsubmitAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[313];
const QualifiedName& kOnsuspendAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[314];
const QualifiedName& kOntimeupdateAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[315];
const QualifiedName& kOntimezonechangeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[316];
const QualifiedName& kOntoggleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[317];
const QualifiedName& kOntouchcancelAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[318];
const QualifiedName& kOntouchendAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[319];
const QualifiedName& kOntouchmoveAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[320];
const QualifiedName& kOntouchstartAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[321];
const QualifiedName& kOntransitionendAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[322];
const QualifiedName& kOnunloadAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[323];
const QualifiedName& kOnvalidationstatuschangeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[324];
const QualifiedName& kOnvolumechangeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[325];
const QualifiedName& kOnwaitingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[326];
const QualifiedName& kOnwebkitanimationendAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[327];
const QualifiedName& kOnwebkitanimationiterationAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[328];
const QualifiedName& kOnwebkitanimationstartAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[329];
const QualifiedName& kOnwebkitfullscreenchangeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[330];
const QualifiedName& kOnwebkitfullscreenerrorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[331];
const QualifiedName& kOnwebkittransitionendAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[332];
const QualifiedName& kOnwheelAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[333];
const QualifiedName& kOpenAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[334];
const QualifiedName& kOptimumAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[335];
const QualifiedName& kParsepartsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[336];
const QualifiedName& kPartAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[337];
const QualifiedName& kPatternAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[338];
const QualifiedName& kPingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[339];
const QualifiedName& kPlaceholderAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[340];
const QualifiedName& kPlaysinlineAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[341];
const QualifiedName& kPolicyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[342];
const QualifiedName& kPopoverAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[343];
const QualifiedName& kPopovertargetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[344];
const QualifiedName& kPopovertargetactionAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[345];
const QualifiedName& kPosterAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[346];
const QualifiedName& kPreciselocationAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[347];
const QualifiedName& kPreloadAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[348];
const QualifiedName& kPrivatetokenAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[349];
const QualifiedName& kPropertyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[350];
const QualifiedName& kPseudoAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[351];
const QualifiedName& kReadonlyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[352];
const QualifiedName& kReferrerpolicyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[353];
const QualifiedName& kRelAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[354];
const QualifiedName& kRequiredAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[355];
const QualifiedName& kRevAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[356];
const QualifiedName& kReversedAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[357];
const QualifiedName& kRoleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[358];
const QualifiedName& kRowsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[359];
const QualifiedName& kRowspanAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[360];
const QualifiedName& kRulesAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[361];
const QualifiedName& kSandboxAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[362];
const QualifiedName& kSchemeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[363];
const QualifiedName& kScopeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[364];
const QualifiedName& kScrollamountAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[365];
const QualifiedName& kScrolldelayAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[366];
const QualifiedName& kScrollingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[367];
const QualifiedName& kSelectAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[368];
const QualifiedName& kSelectedAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[369];
const QualifiedName& kSelectedcontentelementAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[370];
const QualifiedName& kShadowrootAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[371];
const QualifiedName& kShadowrootclonableAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[372];
const QualifiedName& kShadowrootdelegatesfocusAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[373];
const QualifiedName& kShadowrootmodeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[374];
const QualifiedName& kShadowrootreferencetargetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[375];
const QualifiedName& kShadowrootserializableAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[376];
const QualifiedName& kShapeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[377];
const QualifiedName& kSharedstoragewritableAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[378];
const QualifiedName& kSizeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[379];
const QualifiedName& kSizesAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[380];
const QualifiedName& kSlotAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[381];
const QualifiedName& kSpanAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[382];
const QualifiedName& kSpellcheckAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[383];
const QualifiedName& kSrcAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[384];
const QualifiedName& kSrcdocAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[385];
const QualifiedName& kSrclangAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[386];
const QualifiedName& kSrcsetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[387];
const QualifiedName& kStandbyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[388];
const QualifiedName& kStartAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[389];
const QualifiedName& kStepAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[390];
const QualifiedName& kStyleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[391];
const QualifiedName& kSummaryAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[392];
const QualifiedName& kTabindexAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[393];
const QualifiedName& kTargetAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[394];
const QualifiedName& kTextAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[395];
const QualifiedName& kTitleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[396];
const QualifiedName& kTopmarginAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[397];
const QualifiedName& kTranslateAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[398];
const QualifiedName& kTruespeedAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[399];
const QualifiedName& kTypeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[400];
const QualifiedName& kUsemapAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[401];
const QualifiedName& kValignAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[402];
const QualifiedName& kValueAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[403];
const QualifiedName& kValuetypeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[404];
const QualifiedName& kVersionAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[405];
const QualifiedName& kVirtualkeyboardpolicyAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[406];
const QualifiedName& kVlinkAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[407];
const QualifiedName& kVspaceAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[408];
const QualifiedName& kWebkitdirectoryAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[409];
const QualifiedName& kWidthAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[410];
const QualifiedName& kWrapAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[411];
const QualifiedName& kWritingsuggestionsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[412];

void Init()
{
    struct NameEntry {
        const char* name;
        unsigned char length;
        unsigned char is_tag;
        unsigned char is_attr;
    };

    // Namespace
    // Use placement new to initialize the globals.
    AtomicString ns_uri("http://www.w3.org/1999/xhtml");
    new ((void*)&xhtmlNamespaceURI) AtomicString(ns_uri);

    static const NameEntry kNames[] = {
        { "a", 1, 1, 0 },
        { "abbr", 4, 1, 1 },
        { "accept", 6, 0, 1 },
        { "accept-charset", 14, 0, 1 },
        { "accesskey", 9, 0, 1 },
        { "acronym", 7, 1, 0 },
        { "action", 6, 0, 1 },
        { "adauctionheaders", 16, 0, 1 },
        { "address", 7, 1, 0 },
        { "align", 5, 0, 1 },
        { "alink", 5, 0, 1 },
        { "allow", 5, 0, 1 },
        { "allowfullscreen", 15, 0, 1 },
        { "allowpaymentrequest", 19, 0, 1 },
        { "alt", 3, 0, 1 },
        { "anchor", 6, 0, 1 },
        { "applet", 6, 1, 0 },
        { "archive", 7, 0, 1 },
        { "area", 4, 1, 0 },
        { "aria-actions", 12, 0, 1 },
        { "aria-activedescendant", 21, 0, 1 },
        { "aria-atomic", 11, 0, 1 },
        { "aria-autocomplete", 17, 0, 1 },
        { "aria-braillelabel", 17, 0, 1 },
        { "aria-brailleroledescription", 27, 0, 1 },
        { "aria-busy", 9, 0, 1 },
        { "aria-checked", 12, 0, 1 },
        { "aria-colcount", 13, 0, 1 },
        { "aria-colindex", 13, 0, 1 },
        { "aria-colindextext", 17, 0, 1 },
        { "aria-colspan", 12, 0, 1 },
        { "aria-controls", 13, 0, 1 },
        { "aria-current", 12, 0, 1 },
        { "aria-describedby", 16, 0, 1 },
        { "aria-description", 16, 0, 1 },
        { "aria-details", 12, 0, 1 },
        { "aria-disabled", 13, 0, 1 },
        { "aria-errormessage", 17, 0, 1 },
        { "aria-expanded", 13, 0, 1 },
        { "aria-flowto", 11, 0, 1 },
        { "aria-haspopup", 13, 0, 1 },
        { "aria-hidden", 11, 0, 1 },
        { "aria-invalid", 12, 0, 1 },
        { "aria-keyshortcuts", 17, 0, 1 },
        { "aria-label", 10, 0, 1 },
        { "aria-labeledby", 14, 0, 1 },
        { "aria-labelledby", 15, 0, 1 },
        { "aria-level", 10, 0, 1 },
        { "aria-live", 9, 0, 1 },
        { "aria-modal", 10, 0, 1 },
        { "aria-multiline", 14, 0, 1 },
        { "aria-multiselectable", 20, 0, 1 },
        { "aria-orientation", 16, 0, 1 },
        { "aria-owns", 9, 0, 1 },
        { "aria-placeholder", 16, 0, 1 },
        { "aria-posinset", 13, 0, 1 },
        { "aria-pressed", 12, 0, 1 },
        { "aria-readonly", 13, 0, 1 },
        { "aria-relevant", 13, 0, 1 },
        { "aria-required", 13, 0, 1 },
        { "aria-roledescription", 20, 0, 1 },
        { "aria-rowcount", 13, 0, 1 },
        { "aria-rowindex", 13, 0, 1 },
        { "aria-rowindextext", 17, 0, 1 },
        { "aria-rowspan", 12, 0, 1 },
        { "aria-selected", 13, 0, 1 },
        { "aria-setsize", 12, 0, 1 },
        { "aria-sort", 9, 0, 1 },
        { "aria-valuemax", 13, 0, 1 },
        { "aria-valuemin", 13, 0, 1 },
        { "aria-valuenow", 13, 0, 1 },
        { "aria-valuetext", 14, 0, 1 },
        { "aria-virtualcontent", 19, 0, 1 },
        { "article", 7, 1, 0 },
        { "as", 2, 0, 1 },
        { "aside", 5, 1, 0 },
        { "async", 5, 0, 1 },
        { "attributionsrc", 14, 0, 1 },
        { "audio", 5, 1, 0 },
        { "autocapitalize", 14, 0, 1 },
        { "autocomplete", 12, 0, 1 },
        { "autocorrect", 11, 0, 1 },
        { "autofocus", 9, 0, 1 },
        { "autoplay", 8, 0, 1 },
        { "axis", 4, 0, 1 },
        { "b", 1, 1, 0 },
        { "background", 10, 0, 1 },
        { "base", 4, 1, 0 },
        { "basefont", 8, 1, 0 },
        { "bdi", 3, 1, 0 },
        { "bdo", 3, 1, 0 },
        { "behavior", 8, 0, 1 },
        { "bgcolor", 7, 0, 1 },
        { "bgsound", 7, 1, 0 },
        { "big", 3, 1, 0 },
        { "blocking", 8, 0, 1 },
        { "blockquote", 10, 1, 0 },
        { "body", 4, 1, 0 },
        { "border", 6, 0, 1 },
        { "bordercolor", 11, 0, 1 },
        { "br", 2, 1, 0 },
        { "browsingtopics", 14, 0, 1 },
        { "button", 6, 1, 0 },
        { "canvas", 6, 1, 0 },
        { "caption", 7, 1, 0 },
        { "capture", 7, 0, 1 },
        { "cellpadding", 11, 0, 1 },
        { "cellspacing", 11, 0, 1 },
        { "center", 6, 1, 0 },
        { "challenge", 9, 0, 1 },
        { "char", 4, 0, 1 },
        { "charoff", 7, 0, 1 },
        { "charset", 7, 0, 1 },
        { "checked", 7, 0, 1 },
        { "cite", 4, 1, 1 },
        { "class", 5, 0, 1 },
        { "classid", 7, 0, 1 },
        { "clear", 5, 0, 1 },
        { "closedby", 8, 0, 1 },
        { "code", 4, 1, 1 },
        { "codebase", 8, 0, 1 },
        { "codetype", 8, 0, 1 },
        { "col", 3, 1, 0 },
        { "colgroup", 8, 1, 0 },
        { "color", 5, 0, 1 },
        { "cols", 4, 0, 1 },
        { "colspan", 7, 0, 1 },
        { "command", 7, 1, 1 },
        { "commandfor", 10, 0, 1 },
        { "compact", 7, 0, 1 },
        { "content", 7, 0, 1 },
        { "contenteditable", 15, 0, 1 },
        { "controls", 8, 0, 1 },
        { "controlslist", 12, 0, 1 },
        { "coords", 6, 0, 1 },
        { "credentialless", 14, 0, 1 },
        { "crossorigin", 11, 0, 1 },
        { "csp", 3, 0, 1 },
        { "data", 4, 1, 1 },
        { "data-src", 8, 0, 1 },
        { "datalist", 8, 1, 0 },
        { "datetime", 8, 0, 1 },
        { "dd", 2, 1, 0 },
        { "declare", 7, 0, 1 },
        { "decoding", 8, 0, 1 },
        { "default", 7, 0, 1 },
        { "defer", 5, 0, 1 },
        { "del", 3, 1, 0 },
        { "delegatesfocus", 14, 0, 1 },
        { "details", 7, 1, 0 },
        { "dfn", 3, 1, 0 },
        { "dialog", 6, 1, 0 },
        { "dir", 3, 1, 1 },
        { "direction", 9, 0, 1 },
        { "dirname", 7, 0, 1 },
        { "disabled", 8, 0, 1 },
        { "disablepictureinpicture", 23, 0, 1 },
        { "disableremoteplayback", 21, 0, 1 },
        { "div", 3, 1, 0 },
        { "dl", 2, 1, 0 },
        { "download", 8, 0, 1 },
        { "draggable", 9, 0, 1 },
        { "dt", 2, 1, 0 },
        { "elementtiming", 13, 0, 1 },
        { "em", 2, 1, 0 },
        { "embed", 5, 1, 0 },
        { "enctype", 7, 0, 1 },
        { "end", 3, 0, 1 },
        { "enterkeyhint", 12, 0, 1 },
        { "event", 5, 0, 1 },
        { "exportparts", 11, 0, 1 },
        { "face", 4, 0, 1 },
        { "fencedframe", 11, 1, 0 },
        { "fetchpriority", 13, 0, 1 },
        { "fieldset", 8, 1, 0 },
        { "figcaption", 10, 1, 0 },
        { "figure", 6, 1, 0 },
        { "focusgroup", 10, 0, 1 },
        { "font", 4, 1, 0 },
        { "footer", 6, 1, 0 },
        { "for", 3, 0, 1 },
        { "form", 4, 1, 1 },
        { "formaction", 10, 0, 1 },
        { "formenctype", 11, 0, 1 },
        { "formmethod", 10, 0, 1 },
        { "formnovalidate", 14, 0, 1 },
        { "formtarget", 10, 0, 1 },
        { "frame", 5, 1, 1 },
        { "frameborder", 11, 0, 1 },
        { "frameset", 8, 1, 0 },
        { "h1", 2, 1, 0 },
        { "h2", 2, 1, 0 },
        { "h3", 2, 1, 0 },
        { "h4", 2, 1, 0 },
        { "h5", 2, 1, 0 },
        { "h6", 2, 1, 0 },
        { "head", 4, 1, 0 },
        { "header", 6, 1, 0 },
        { "headers", 7, 0, 1 },
        { "height", 6, 0, 1 },
        { "hgroup", 6, 1, 0 },
        { "hidden", 6, 0, 1 },
        { "high", 4, 0, 1 },
        { "hr", 2, 1, 0 },
        { "href", 4, 0, 1 },
        { "hreflang", 8, 0, 1 },
        { "hreftranslate", 13, 0, 1 },
        { "hspace", 6, 0, 1 },
        { "html", 4, 1, 0 },
        { "http-equiv", 10, 0, 1 },
        { "i", 1, 1, 0 },
        { "id", 2, 0, 1 },
        { "iframe", 6, 1, 0 },
        { "image", 5, 1, 0 },
        { "imagesizes", 10, 0, 1 },
        { "imagesrcset", 11, 0, 1 },
        { "img", 3, 1, 0 },
        { "incremental", 11, 0, 1 },
        { "inert", 5, 0, 1 },
        { "input", 5, 1, 0 },
        { "inputmode", 9, 0, 1 },
        { "ins", 3, 1, 0 },
        { "integrity", 9, 0, 1 },
        { "interestaction", 14, 0, 1 },
        { "interesttarget", 14, 0, 1 },
        { "invisible", 9, 0, 1 },
        { "is", 2, 0, 1 },
        { "ismap", 5, 0, 1 },
        { "itemprop", 8, 0, 1 },
        { "kbd", 3, 1, 0 },
        { "keygen", 6, 1, 0 },
        { "keytype", 7, 0, 1 },
        { "kind", 4, 0, 1 },
        { "label", 5, 1, 1 },
        { "lang", 4, 0, 1 },
        { "language", 8, 0, 1 },
        { "latencyhint", 11, 0, 1 },
        { "layer", 5, 1, 0 },
        { "leftmargin", 10, 0, 1 },
        { "legend", 6, 1, 0 },
        { "li", 2, 1, 0 },
        { "link", 4, 1, 1 },
        { "list", 4, 0, 1 },
        { "listing", 7, 1, 0 },
        { "loading", 7, 0, 1 },
        { "longdesc", 8, 0, 1 },
        { "loop", 4, 0, 1 },
        { "low", 3, 0, 1 },
        { "lowsrc", 6, 0, 1 },
        { "main", 4, 1, 0 },
        { "manifest", 8, 0, 1 },
        { "map", 3, 1, 0 },
        { "marginheight", 12, 0, 1 },
        { "marginwidth", 11, 0, 1 },
        { "mark", 4, 1, 0 },
        { "marquee", 7, 1, 0 },
        { "max", 3, 0, 1 },
        { "maxlength", 9, 0, 1 },
        { "mayscript", 9, 0, 1 },
        { "media", 5, 0, 1 },
        { "menu", 4, 1, 0 },
        { "meta", 4, 1, 0 },
        { "meter", 5, 1, 0 },
        { "method", 6, 0, 1 },
        { "min", 3, 0, 1 },
        { "minlength", 9, 0, 1 },
        { "multiple", 8, 0, 1 },
        { "muted", 5, 0, 1 },
        { "name", 4, 0, 1 },
        { "nav", 3, 1, 0 },
        { "nobr", 4, 1, 0 },
        { "noembed", 7, 1, 0 },
        { "noframes", 8, 1, 0 },
        { "nohref", 6, 0, 1 },
        { "nolayer", 7, 1, 0 },
        { "nomodule", 8, 0, 1 },
        { "nonce", 5, 0, 1 },
        { "noresize", 8, 0, 1 },
        { "noscript", 8, 1, 0 },
        { "noshade", 7, 0, 1 },
        { "novalidate", 10, 0, 1 },
        { "nowrap", 6, 0, 1 },
        { "object", 6, 1, 1 },
        { "ol", 2, 1, 0 },
        { "onabort", 7, 0, 1 },
        { "onafterprint", 12, 0, 1 },
        { "onanimationend", 14, 0, 1 },
        { "onanimationiteration", 20, 0, 1 },
        { "onanimationstart", 16, 0, 1 },
        { "onauxclick", 10, 0, 1 },
        { "onbeforecopy", 12, 0, 1 },
        { "onbeforecut", 11, 0, 1 },
        { "onbeforeinput", 13, 0, 1 },
        { "onbeforepaste", 13, 0, 1 },
        { "onbeforeprint", 13, 0, 1 },
        { "onbeforetoggle", 14, 0, 1 },
        { "onbeforeunload", 14, 0, 1 },
        { "onblur", 6, 0, 1 },
        { "oncancel", 8, 0, 1 },
        { "oncanplay", 9, 0, 1 },
        { "oncanplaythrough", 16, 0, 1 },
        { "onchange", 8, 0, 1 },
        { "onclick", 7, 0, 1 },
        { "onclose", 7, 0, 1 },
        { "oncontentvisibilityautostatechange", 34, 0, 1 },
        { "oncontextlost", 13, 0, 1 },
        { "oncontextmenu", 13, 0, 1 },
        { "oncontextrestored", 17, 0, 1 },
        { "oncopy", 6, 0, 1 },
        { "oncuechange", 11, 0, 1 },
        { "oncut", 5, 0, 1 },
        { "ondblclick", 10, 0, 1 },
        { "ondismiss", 9, 0, 1 },
        { "ondrag", 6, 0, 1 },
        { "ondragend", 9, 0, 1 },
        { "ondragenter", 11, 0, 1 },
        { "ondragleave", 11, 0, 1 },
        { "ondragover", 10, 0, 1 },
        { "ondragstart", 11, 0, 1 },
        { "ondrop", 6, 0, 1 },
        { "ondurationchange", 16, 0, 1 },
        { "onemptied", 9, 0, 1 },
        { "onended", 7, 0, 1 },
        { "onerror", 7, 0, 1 },
        { "onfocus", 7, 0, 1 },
        { "onfocusin", 9, 0, 1 },
        { "onfocusout", 10, 0, 1 },
        { "onformdata", 10, 0, 1 },
        { "ongotpointercapture", 19, 0, 1 },
        { "onhashchange", 12, 0, 1 },
        { "oninput", 7, 0, 1 },
        { "oninvalid", 9, 0, 1 },
        { "onkeydown", 9, 0, 1 },
        { "onkeypress", 10, 0, 1 },
        { "onkeyup", 7, 0, 1 },
        { "onlanguagechange", 16, 0, 1 },
        { "onload", 6, 0, 1 },
        { "onloadeddata", 12, 0, 1 },
        { "onloadedmetadata", 16, 0, 1 },
        { "onloadstart", 11, 0, 1 },
        { "onlostpointercapture", 20, 0, 1 },
        { "onmessage", 9, 0, 1 },
        { "onmessageerror", 14, 0, 1 },
        { "onmousedown", 11, 0, 1 },
        { "onmouseenter", 12, 0, 1 },
        { "onmouseleave", 12, 0, 1 },
        { "onmousemove", 11, 0, 1 },
        { "onmouseout", 10, 0, 1 },
        { "onmouseover", 11, 0, 1 },
        { "onmouseup", 9, 0, 1 },
        { "onmousewheel", 12, 0, 1 },
        { "onmove", 6, 0, 1 },
        { "onoffline", 9, 0, 1 },
        { "ononline", 8, 0, 1 },
        { "onorientationchange", 19, 0, 1 },
        { "onoverscroll", 12, 0, 1 },
        { "onpagehide", 10, 0, 1 },
        { "onpageshow", 10, 0, 1 },
        { "onpaste", 7, 0, 1 },
        { "onpause", 7, 0, 1 },
        { "onplay", 6, 0, 1 },
        { "onplaying", 9, 0, 1 },
        { "onpointercancel", 15, 0, 1 },
        { "onpointerdown", 13, 0, 1 },
        { "onpointerenter", 14, 0, 1 },
        { "onpointerleave", 14, 0, 1 },
        { "onpointermove", 13, 0, 1 },
        { "onpointerout", 12, 0, 1 },
        { "onpointerover", 13, 0, 1 },
        { "onpointerrawupdate", 18, 0, 1 },
        { "onpointerup", 11, 0, 1 },
        { "onpopstate", 10, 0, 1 },
        { "onprogress", 10, 0, 1 },
        { "onratechange", 12, 0, 1 },
        { "onreset", 7, 0, 1 },
        { "onresize", 8, 0, 1 },
        { "onresolve", 9, 0, 1 },
        { "onscroll", 8, 0, 1 },
        { "onscrollend", 11, 0, 1 },
        { "onscrollsnapchange", 18, 0, 1 },
        { "onscrollsnapchanging", 20, 0, 1 },
        { "onsearch", 8, 0, 1 },
        { "onsecuritypolicyviolation", 25, 0, 1 },
        { "onseeked", 8, 0, 1 },
        { "onseeking", 9, 0, 1 },
        { "onselect", 8, 0, 1 },
        { "onselectionchange", 17, 0, 1 },
        { "onselectstart", 13, 0, 1 },
        { "onshow", 6, 0, 1 },
        { "onslotchange", 12, 0, 1 },
        { "onstalled", 9, 0, 1 },
        { "onstorage", 9, 0, 1 },
        { "onsubmit", 8, 0, 1 },
        { "onsuspend", 9, 0, 1 },
        { "ontimeupdate", 12, 0, 1 },
        { "ontimezonechange", 16, 0, 1 },
        { "ontoggle", 8, 0, 1 },
        { "ontouchcancel", 13, 0, 1 },
        { "ontouchend", 10, 0, 1 },
        { "ontouchmove", 11, 0, 1 },
        { "ontouchstart", 12, 0, 1 },
        { "ontransitionend", 15, 0, 1 },
        { "onunload", 8, 0, 1 },
        { "onvalidationstatuschange", 24, 0, 1 },
        { "onvolumechange", 14, 0, 1 },
        { "onwaiting", 9, 0, 1 },
        { "onwebkitanimationend", 20, 0, 1 },
        { "onwebkitanimationiteration", 26, 0, 1 },
        { "onwebkitanimationstart", 22, 0, 1 },
        { "onwebkitfullscreenchange", 24, 0, 1 },
        { "onwebkitfullscreenerror", 23, 0, 1 },
        { "onwebkittransitionend", 21, 0, 1 },
        { "onwheel", 7, 0, 1 },
        { "open", 4, 0, 1 },
        { "optgroup", 8, 1, 0 },
        { "optimum", 7, 0, 1 },
        { "option", 6, 1, 0 },
        { "output", 6, 1, 0 },
        { "p", 1, 1, 0 },
        { "param", 5, 1, 0 },
        { "parseparts", 10, 0, 1 },
        { "part", 4, 0, 1 },
        { "pattern", 7, 0, 1 },
        { "permission", 10, 1, 0 },
        { "picture", 7, 1, 0 },
        { "ping", 4, 0, 1 },
        { "placeholder", 11, 0, 1 },
        { "plaintext", 9, 1, 0 },
        { "playsinline", 11, 0, 1 },
        { "policy", 6, 0, 1 },
        { "popover", 7, 0, 1 },
        { "popovertarget", 13, 0, 1 },
        { "popovertargetaction", 19, 0, 1 },
        { "poster", 6, 0, 1 },
        { "pre", 3, 1, 0 },
        { "preciselocation", 15, 0, 1 },
        { "preload", 7, 0, 1 },
        { "privatetoken", 12, 0, 1 },
        { "progress", 8, 1, 0 },
        { "property", 8, 0, 1 },
        { "pseudo", 6, 0, 1 },
        { "q", 1, 1, 0 },
        { "rb", 2, 1, 0 },
        { "readonly", 8, 0, 1 },
        { "referrerpolicy", 14, 0, 1 },
        { "rel", 3, 0, 1 },
        { "required", 8, 0, 1 },
        { "rev", 3, 0, 1 },
        { "reversed", 8, 0, 1 },
        { "role", 4, 0, 1 },
        { "rows", 4, 0, 1 },
        { "rowspan", 7, 0, 1 },
        { "rp", 2, 1, 0 },
        { "rt", 2, 1, 0 },
        { "rtc", 3, 1, 0 },
        { "ruby", 4, 1, 0 },
        { "rules", 5, 0, 1 },
        { "s", 1, 1, 0 },
        { "samp", 4, 1, 0 },
        { "sandbox", 7, 0, 1 },
        { "scheme", 6, 0, 1 },
        { "scope", 5, 0, 1 },
        { "script", 6, 1, 0 },
        { "scrollamount", 12, 0, 1 },
        { "scrolldelay", 11, 0, 1 },
        { "scrolling", 9, 0, 1 },
        { "search", 6, 1, 0 },
        { "section", 7, 1, 0 },
        { "select", 6, 1, 1 },
        { "selected", 8, 0, 1 },
        { "selectedcontent", 15, 1, 0 },
        { "selectedcontentelement", 22, 0, 1 },
        { "shadowroot", 10, 0, 1 },
        { "shadowrootclonable", 18, 0, 1 },
        { "shadowrootdelegatesfocus", 24, 0, 1 },
        { "shadowrootmode", 14, 0, 1 },
        { "shadowrootreferencetarget", 25, 0, 1 },
        { "shadowrootserializable", 22, 0, 1 },
        { "shape", 5, 0, 1 },
        { "sharedstoragewritable", 21, 0, 1 },
        { "size", 4, 0, 1 },
        { "sizes", 5, 0, 1 },
        { "slot", 4, 1, 1 },
        { "small", 5, 1, 0 },
        { "source", 6, 1, 0 },
        { "span", 4, 1, 1 },
        { "spellcheck", 10, 0, 1 },
        { "src", 3, 0, 1 },
        { "srcdoc", 6, 0, 1 },
        { "srclang", 7, 0, 1 },
        { "srcset", 6, 0, 1 },
        { "standby", 7, 0, 1 },
        { "start", 5, 0, 1 },
        { "step", 4, 0, 1 },
        { "strike", 6, 1, 0 },
        { "strong", 6, 1, 0 },
        { "style", 5, 1, 1 },
        { "sub", 3, 1, 0 },
        { "summary", 7, 1, 1 },
        { "sup", 3, 1, 0 },
        { "tabindex", 8, 0, 1 },
        { "table", 5, 1, 0 },
        { "target", 6, 0, 1 },
        { "tbody", 5, 1, 0 },
        { "td", 2, 1, 0 },
        { "template", 8, 1, 0 },
        { "text", 4, 0, 1 },
        { "textarea", 8, 1, 0 },
        { "tfoot", 5, 1, 0 },
        { "th", 2, 1, 0 },
        { "thead", 5, 1, 0 },
        { "time", 4, 1, 0 },
        { "title", 5, 1, 1 },
        { "topmargin", 9, 0, 1 },
        { "tr", 2, 1, 0 },
        { "track", 5, 1, 0 },
        { "translate", 9, 0, 1 },
        { "truespeed", 9, 0, 1 },
        { "tt", 2, 1, 0 },
        { "type", 4, 0, 1 },
        { "u", 1, 1, 0 },
        { "ul", 2, 1, 0 },
        { "usemap", 6, 0, 1 },
        { "valign", 6, 0, 1 },
        { "value", 5, 0, 1 },
        { "valuetype", 9, 0, 1 },
        { "var", 3, 1, 0 },
        { "version", 7, 0, 1 },
        { "video", 5, 1, 0 },
        { "virtualkeyboardpolicy", 21, 0, 1 },
        { "vlink", 5, 0, 1 },
        { "vspace", 6, 0, 1 },
        { "wbr", 3, 1, 0 },
        { "webkitdirectory", 15, 0, 1 },
        { "width", 5, 0, 1 },
        { "wrap", 4, 0, 1 },
        { "writingsuggestions", 18, 0, 1 },
        { "xmp", 3, 1, 0 },
    };

    size_t tag_i = 0;
    size_t attr_i = 0;
    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        if (kNames[i].is_tag) {
            void* address = reinterpret_cast<HTMLQualifiedName*>(&tag_storage) + tag_i;
            QualifiedName::CreateStatic(address, impl, ns_uri);
            ++tag_i;
        }

        if (!kNames[i].is_attr)
            continue;
        void* address = reinterpret_cast<QualifiedName*>(&attr_storage) + attr_i;
        QualifiedName::CreateStatic(address, impl);
        ++attr_i;
    }
    DCHECK_EQ(tag_i, kTagsCount);
    DCHECK_EQ(attr_i, kAttrsCount);
}

const blink::HTMLQualifiedName& TagToQualifiedName(HTMLTag tag)
{
    switch (tag) {
    case HTMLTag::kA:
        return kATag;
    case HTMLTag::kAbbr:
        return kAbbrTag;
    case HTMLTag::kAcronym:
        return kAcronymTag;
    case HTMLTag::kAddress:
        return kAddressTag;
    case HTMLTag::kApplet:
        return kAppletTag;
    case HTMLTag::kArea:
        return kAreaTag;
    case HTMLTag::kArticle:
        return kArticleTag;
    case HTMLTag::kAside:
        return kAsideTag;
    case HTMLTag::kAudio:
        return kAudioTag;
    case HTMLTag::kB:
        return kBTag;
    case HTMLTag::kBase:
        return kBaseTag;
    case HTMLTag::kBasefont:
        return kBasefontTag;
    case HTMLTag::kBdi:
        return kBdiTag;
    case HTMLTag::kBdo:
        return kBdoTag;
    case HTMLTag::kBgsound:
        return kBgsoundTag;
    case HTMLTag::kBig:
        return kBigTag;
    case HTMLTag::kBlockquote:
        return kBlockquoteTag;
    case HTMLTag::kBody:
        return kBodyTag;
    case HTMLTag::kBr:
        return kBrTag;
    case HTMLTag::kButton:
        return kButtonTag;
    case HTMLTag::kCanvas:
        return kCanvasTag;
    case HTMLTag::kCaption:
        return kCaptionTag;
    case HTMLTag::kCenter:
        return kCenterTag;
    case HTMLTag::kCite:
        return kCiteTag;
    case HTMLTag::kCode:
        return kCodeTag;
    case HTMLTag::kCol:
        return kColTag;
    case HTMLTag::kColgroup:
        return kColgroupTag;
    case HTMLTag::kCommand:
        return kCommandTag;
    case HTMLTag::kData:
        return kDataTag;
    case HTMLTag::kDatalist:
        return kDatalistTag;
    case HTMLTag::kDd:
        return kDdTag;
    case HTMLTag::kDel:
        return kDelTag;
    case HTMLTag::kDetails:
        return kDetailsTag;
    case HTMLTag::kDfn:
        return kDfnTag;
    case HTMLTag::kDialog:
        return kDialogTag;
    case HTMLTag::kDir:
        return kDirTag;
    case HTMLTag::kDiv:
        return kDivTag;
    case HTMLTag::kDl:
        return kDlTag;
    case HTMLTag::kDt:
        return kDtTag;
    case HTMLTag::kEm:
        return kEmTag;
    case HTMLTag::kEmbed:
        return kEmbedTag;
    case HTMLTag::kFencedframeOrUnknown:
        return kFencedframeTag;
    case HTMLTag::kFieldset:
        return kFieldsetTag;
    case HTMLTag::kFigcaption:
        return kFigcaptionTag;
    case HTMLTag::kFigure:
        return kFigureTag;
    case HTMLTag::kFont:
        return kFontTag;
    case HTMLTag::kFooter:
        return kFooterTag;
    case HTMLTag::kForm:
        return kFormTag;
    case HTMLTag::kFrame:
        return kFrameTag;
    case HTMLTag::kFrameset:
        return kFramesetTag;
    case HTMLTag::kH1:
        return kH1Tag;
    case HTMLTag::kH2:
        return kH2Tag;
    case HTMLTag::kH3:
        return kH3Tag;
    case HTMLTag::kH4:
        return kH4Tag;
    case HTMLTag::kH5:
        return kH5Tag;
    case HTMLTag::kH6:
        return kH6Tag;
    case HTMLTag::kHead:
        return kHeadTag;
    case HTMLTag::kHeader:
        return kHeaderTag;
    case HTMLTag::kHgroup:
        return kHgroupTag;
    case HTMLTag::kHr:
        return kHrTag;
    case HTMLTag::kHTML:
        return kHTMLTag;
    case HTMLTag::kI:
        return kITag;
    case HTMLTag::kIFrame:
        return kIFrameTag;
    case HTMLTag::kImage:
        return kImageTag;
    case HTMLTag::kImg:
        return kImgTag;
    case HTMLTag::kInput:
        return kInputTag;
    case HTMLTag::kIns:
        return kInsTag;
    case HTMLTag::kKbd:
        return kKbdTag;
    case HTMLTag::kKeygen:
        return kKeygenTag;
    case HTMLTag::kLabel:
        return kLabelTag;
    case HTMLTag::kLayer:
        return kLayerTag;
    case HTMLTag::kLegend:
        return kLegendTag;
    case HTMLTag::kLi:
        return kLiTag;
    case HTMLTag::kLink:
        return kLinkTag;
    case HTMLTag::kListing:
        return kListingTag;
    case HTMLTag::kMain:
        return kMainTag;
    case HTMLTag::kMap:
        return kMapTag;
    case HTMLTag::kMark:
        return kMarkTag;
    case HTMLTag::kMarquee:
        return kMarqueeTag;
    case HTMLTag::kMenu:
        return kMenuTag;
    case HTMLTag::kMeta:
        return kMetaTag;
    case HTMLTag::kMeter:
        return kMeterTag;
    case HTMLTag::kNav:
        return kNavTag;
    case HTMLTag::kNobr:
        return kNobrTag;
    case HTMLTag::kNoembed:
        return kNoembedTag;
    case HTMLTag::kNoframes:
        return kNoframesTag;
    case HTMLTag::kNolayer:
        return kNolayerTag;
    case HTMLTag::kNoscript:
        return kNoscriptTag;
    case HTMLTag::kObject:
        return kObjectTag;
    case HTMLTag::kOl:
        return kOlTag;
    case HTMLTag::kOptgroup:
        return kOptgroupTag;
    case HTMLTag::kOption:
        return kOptionTag;
    case HTMLTag::kOutput:
        return kOutputTag;
    case HTMLTag::kP:
        return kPTag;
    case HTMLTag::kParam:
        return kParamTag;
    case HTMLTag::kPermissionOrUnknown:
        return kPermissionTag;
    case HTMLTag::kPicture:
        return kPictureTag;
    case HTMLTag::kPlaintext:
        return kPlaintextTag;
    case HTMLTag::kPre:
        return kPreTag;
    case HTMLTag::kProgress:
        return kProgressTag;
    case HTMLTag::kQ:
        return kQTag;
    case HTMLTag::kRb:
        return kRbTag;
    case HTMLTag::kRp:
        return kRpTag;
    case HTMLTag::kRt:
        return kRtTag;
    case HTMLTag::kRTC:
        return kRTCTag;
    case HTMLTag::kRuby:
        return kRubyTag;
    case HTMLTag::kS:
        return kSTag;
    case HTMLTag::kSamp:
        return kSampTag;
    case HTMLTag::kScript:
        return kScriptTag;
    case HTMLTag::kSearch:
        return kSearchTag;
    case HTMLTag::kSection:
        return kSectionTag;
    case HTMLTag::kSelect:
        return kSelectTag;
    case HTMLTag::kSelectedcontent:
        return kSelectedcontentTag;
    case HTMLTag::kSlot:
        return kSlotTag;
    case HTMLTag::kSmall:
        return kSmallTag;
    case HTMLTag::kSource:
        return kSourceTag;
    case HTMLTag::kSpan:
        return kSpanTag;
    case HTMLTag::kStrike:
        return kStrikeTag;
    case HTMLTag::kStrong:
        return kStrongTag;
    case HTMLTag::kStyle:
        return kStyleTag;
    case HTMLTag::kSub:
        return kSubTag;
    case HTMLTag::kSummary:
        return kSummaryTag;
    case HTMLTag::kSup:
        return kSupTag;
    case HTMLTag::kTable:
        return kTableTag;
    case HTMLTag::kTbody:
        return kTbodyTag;
    case HTMLTag::kTd:
        return kTdTag;
    case HTMLTag::kTemplate:
        return kTemplateTag;
    case HTMLTag::kTextarea:
        return kTextareaTag;
    case HTMLTag::kTfoot:
        return kTfootTag;
    case HTMLTag::kTh:
        return kThTag;
    case HTMLTag::kThead:
        return kTheadTag;
    case HTMLTag::kTime:
        return kTimeTag;
    case HTMLTag::kTitle:
        return kTitleTag;
    case HTMLTag::kTr:
        return kTrTag;
    case HTMLTag::kTrack:
        return kTrackTag;
    case HTMLTag::kTt:
        return kTtTag;
    case HTMLTag::kU:
        return kUTag;
    case HTMLTag::kUl:
        return kUlTag;
    case HTMLTag::kVar:
        return kVarTag;
    case HTMLTag::kVideo:
        return kVideoTag;
    case HTMLTag::kWbr:
        return kWbrTag;
    case HTMLTag::kXmp:
        return kXmpTag;
    case HTMLTag::kUnknown:
        return static_cast<const blink::HTMLQualifiedName&>(g_null_name);
    }
}

} // namespace html_names
} // namespace blink
