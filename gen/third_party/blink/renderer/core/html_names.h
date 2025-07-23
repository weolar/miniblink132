// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_qualified_names.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/aria_properties.json5
//   ../../third_party/blink/renderer/core/html/html_attribute_names.json5
//   ../../third_party/blink/renderer/core/html/html_tag_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_HTML_NAMES_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_HTML_NAMES_H_

#include <memory>

#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/dom/qualified_name.h"

namespace blink {

class HTMLQualifiedName : public QualifiedName { };

namespace html_names {

// Namespace
CORE_EXPORT extern const WTF::AtomicString& xhtmlNamespaceURI;

// Tags

enum class HTMLTag {
    // Explicitly give unknown a value of 0 as comparison to unknown happens a
    // lot, and comparing to 0 saves an instruction on some hardware.
    kUnknown = 0,
    kA,
    kAbbr,
    kAcronym,
    kAddress,
    kApplet,
    kArea,
    kArticle,
    kAside,
    kAudio,
    kB,
    kBase,
    kBasefont,
    kBdi,
    kBdo,
    kBgsound,
    kBig,
    kBlockquote,
    kBody,
    kBr,
    kButton,
    kCanvas,
    kCaption,
    kCenter,
    kCite,
    kCode,
    kCol,
    kColgroup,
    kCommand,
    kData,
    kDatalist,
    kDd,
    kDel,
    kDetails,
    kDfn,
    kDialog,
    kDir,
    kDiv,
    kDl,
    kDt,
    kEm,
    kEmbed,
    kFencedframeOrUnknown,
    kFieldset,
    kFigcaption,
    kFigure,
    kFont,
    kFooter,
    kForm,
    kFrame,
    kFrameset,
    kH1,
    kH2,
    kH3,
    kH4,
    kH5,
    kH6,
    kHead,
    kHeader,
    kHgroup,
    kHr,
    kHTML,
    kI,
    kIFrame,
    kImage,
    kImg,
    kInput,
    kIns,
    kKbd,
    kKeygen,
    kLabel,
    kLayer,
    kLegend,
    kLi,
    kLink,
    kListing,
    kMain,
    kMap,
    kMark,
    kMarquee,
    kMenu,
    kMeta,
    kMeter,
    kNav,
    kNobr,
    kNoembed,
    kNoframes,
    kNolayer,
    kNoscript,
    kObject,
    kOl,
    kOptgroup,
    kOption,
    kOutput,
    kP,
    kParam,
    kPermissionOrUnknown,
    kPicture,
    kPlaintext,
    kPre,
    kProgress,
    kQ,
    kRb,
    kRp,
    kRt,
    kRTC,
    kRuby,
    kS,
    kSamp,
    kScript,
    kSearch,
    kSection,
    kSelect,
    kSelectedcontent,
    kSlot,
    kSmall,
    kSource,
    kSpan,
    kStrike,
    kStrong,
    kStyle,
    kSub,
    kSummary,
    kSup,
    kTable,
    kTbody,
    kTd,
    kTemplate,
    kTextarea,
    kTfoot,
    kTh,
    kThead,
    kTime,
    kTitle,
    kTr,
    kTrack,
    kTt,
    kU,
    kUl,
    kVar,
    kVideo,
    kWbr,
    kXmp,
};

CORE_EXPORT extern const blink::HTMLQualifiedName& kATag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kAbbrTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kAcronymTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kAddressTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kAppletTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kAreaTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kArticleTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kAsideTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kAudioTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBaseTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBasefontTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBdiTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBdoTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBgsoundTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBigTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBlockquoteTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBodyTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kBrTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kButtonTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kCanvasTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kCaptionTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kCenterTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kCiteTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kCodeTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kColTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kColgroupTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kCommandTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDataTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDatalistTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDdTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDelTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDetailsTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDfnTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDialogTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDirTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDivTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDlTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kDtTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kEmTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kEmbedTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFencedframeTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFieldsetTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFigcaptionTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFigureTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFontTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFooterTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFormTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFrameTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kFramesetTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kH1Tag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kH2Tag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kH3Tag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kH4Tag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kH5Tag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kH6Tag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kHeadTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kHeaderTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kHgroupTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kHrTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kHTMLTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kITag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kIFrameTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kImageTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kImgTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kInputTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kInsTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kKbdTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kKeygenTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kLabelTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kLayerTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kLegendTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kLiTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kLinkTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kListingTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMainTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMapTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMarkTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMarqueeTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMenuTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMetaTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kMeterTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kNavTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kNobrTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kNoembedTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kNoframesTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kNolayerTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kNoscriptTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kObjectTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kOlTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kOptgroupTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kOptionTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kOutputTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kPTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kParamTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kPermissionTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kPictureTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kPlaintextTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kPreTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kProgressTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kQTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kRbTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kRpTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kRtTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kRTCTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kRubyTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSampTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kScriptTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSearchTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSectionTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSelectTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSelectedcontentTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSlotTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSmallTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSourceTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSpanTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kStrikeTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kStrongTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kStyleTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSubTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSummaryTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kSupTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTableTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTbodyTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTdTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTemplateTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTextareaTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTfootTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kThTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTheadTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTimeTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTitleTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTrTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTrackTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kTtTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kUTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kUlTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kVarTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kVideoTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kWbrTag;
CORE_EXPORT extern const blink::HTMLQualifiedName& kXmpTag;

// Attributes
CORE_EXPORT extern const blink::QualifiedName& kAbbrAttr;
CORE_EXPORT extern const blink::QualifiedName& kAcceptAttr;
CORE_EXPORT extern const blink::QualifiedName& kAcceptCharsetAttr;
CORE_EXPORT extern const blink::QualifiedName& kAccesskeyAttr;
CORE_EXPORT extern const blink::QualifiedName& kActionAttr;
CORE_EXPORT extern const blink::QualifiedName& kAdauctionheadersAttr;
CORE_EXPORT extern const blink::QualifiedName& kAlignAttr;
CORE_EXPORT extern const blink::QualifiedName& kAlinkAttr;
CORE_EXPORT extern const blink::QualifiedName& kAllowAttr;
CORE_EXPORT extern const blink::QualifiedName& kAllowfullscreenAttr;
CORE_EXPORT extern const blink::QualifiedName& kAllowpaymentrequestAttr;
CORE_EXPORT extern const blink::QualifiedName& kAltAttr;
CORE_EXPORT extern const blink::QualifiedName& kAnchorAttr;
CORE_EXPORT extern const blink::QualifiedName& kArchiveAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaActionsAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaActivedescendantAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaAtomicAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaAutocompleteAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaBraillelabelAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaBrailleroledescriptionAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaBusyAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaCheckedAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaColcountAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaColindexAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaColindextextAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaColspanAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaControlsAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaCurrentAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaDescribedbyAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaDescriptionAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaDetailsAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaDisabledAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaErrormessageAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaExpandedAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaFlowtoAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaHaspopupAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaHiddenAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaInvalidAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaKeyshortcutsAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaLabelAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaLabeledbyAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaLabelledbyAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaLevelAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaLiveAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaModalAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaMultilineAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaMultiselectableAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaOrientationAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaOwnsAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaPlaceholderAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaPosinsetAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaPressedAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaReadonlyAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaRelevantAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaRequiredAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaRoledescriptionAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaRowcountAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaRowindexAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaRowindextextAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaRowspanAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaSelectedAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaSetsizeAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaSortAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaValuemaxAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaValueminAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaValuenowAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaValuetextAttr;
CORE_EXPORT extern const blink::QualifiedName& kAriaVirtualcontentAttr;
CORE_EXPORT extern const blink::QualifiedName& kAsAttr;
CORE_EXPORT extern const blink::QualifiedName& kAsyncAttr;
CORE_EXPORT extern const blink::QualifiedName& kAttributionsrcAttr;
CORE_EXPORT extern const blink::QualifiedName& kAutocapitalizeAttr;
CORE_EXPORT extern const blink::QualifiedName& kAutocompleteAttr;
CORE_EXPORT extern const blink::QualifiedName& kAutocorrectAttr;
CORE_EXPORT extern const blink::QualifiedName& kAutofocusAttr;
CORE_EXPORT extern const blink::QualifiedName& kAutoplayAttr;
CORE_EXPORT extern const blink::QualifiedName& kAxisAttr;
CORE_EXPORT extern const blink::QualifiedName& kBackgroundAttr;
CORE_EXPORT extern const blink::QualifiedName& kBehaviorAttr;
CORE_EXPORT extern const blink::QualifiedName& kBgcolorAttr;
CORE_EXPORT extern const blink::QualifiedName& kBlockingAttr;
CORE_EXPORT extern const blink::QualifiedName& kBorderAttr;
CORE_EXPORT extern const blink::QualifiedName& kBordercolorAttr;
CORE_EXPORT extern const blink::QualifiedName& kBrowsingtopicsAttr;
CORE_EXPORT extern const blink::QualifiedName& kCaptureAttr;
CORE_EXPORT extern const blink::QualifiedName& kCellpaddingAttr;
CORE_EXPORT extern const blink::QualifiedName& kCellspacingAttr;
CORE_EXPORT extern const blink::QualifiedName& kChallengeAttr;
CORE_EXPORT extern const blink::QualifiedName& kCharAttr;
CORE_EXPORT extern const blink::QualifiedName& kCharoffAttr;
CORE_EXPORT extern const blink::QualifiedName& kCharsetAttr;
CORE_EXPORT extern const blink::QualifiedName& kCheckedAttr;
CORE_EXPORT extern const blink::QualifiedName& kCiteAttr;
CORE_EXPORT extern const blink::QualifiedName& kClassAttr;
CORE_EXPORT extern const blink::QualifiedName& kClassidAttr;
CORE_EXPORT extern const blink::QualifiedName& kClearAttr;
CORE_EXPORT extern const blink::QualifiedName& kClosedbyAttr;
CORE_EXPORT extern const blink::QualifiedName& kCodeAttr;
CORE_EXPORT extern const blink::QualifiedName& kCodebaseAttr;
CORE_EXPORT extern const blink::QualifiedName& kCodetypeAttr;
CORE_EXPORT extern const blink::QualifiedName& kColorAttr;
CORE_EXPORT extern const blink::QualifiedName& kColsAttr;
CORE_EXPORT extern const blink::QualifiedName& kColspanAttr;
CORE_EXPORT extern const blink::QualifiedName& kCommandAttr;
CORE_EXPORT extern const blink::QualifiedName& kCommandforAttr;
CORE_EXPORT extern const blink::QualifiedName& kCompactAttr;
CORE_EXPORT extern const blink::QualifiedName& kContentAttr;
CORE_EXPORT extern const blink::QualifiedName& kContenteditableAttr;
CORE_EXPORT extern const blink::QualifiedName& kControlsAttr;
CORE_EXPORT extern const blink::QualifiedName& kControlslistAttr;
CORE_EXPORT extern const blink::QualifiedName& kCoordsAttr;
CORE_EXPORT extern const blink::QualifiedName& kCredentiallessAttr;
CORE_EXPORT extern const blink::QualifiedName& kCrossoriginAttr;
CORE_EXPORT extern const blink::QualifiedName& kCspAttr;
CORE_EXPORT extern const blink::QualifiedName& kDataAttr;
CORE_EXPORT extern const blink::QualifiedName& kDataSrcAttr;
CORE_EXPORT extern const blink::QualifiedName& kDatetimeAttr;
CORE_EXPORT extern const blink::QualifiedName& kDeclareAttr;
CORE_EXPORT extern const blink::QualifiedName& kDecodingAttr;
CORE_EXPORT extern const blink::QualifiedName& kDefaultAttr;
CORE_EXPORT extern const blink::QualifiedName& kDeferAttr;
CORE_EXPORT extern const blink::QualifiedName& kDelegatesfocusAttr;
CORE_EXPORT extern const blink::QualifiedName& kDirAttr;
CORE_EXPORT extern const blink::QualifiedName& kDirectionAttr;
CORE_EXPORT extern const blink::QualifiedName& kDirnameAttr;
CORE_EXPORT extern const blink::QualifiedName& kDisabledAttr;
CORE_EXPORT extern const blink::QualifiedName& kDisablepictureinpictureAttr;
CORE_EXPORT extern const blink::QualifiedName& kDisableremoteplaybackAttr;
CORE_EXPORT extern const blink::QualifiedName& kDownloadAttr;
CORE_EXPORT extern const blink::QualifiedName& kDraggableAttr;
CORE_EXPORT extern const blink::QualifiedName& kElementtimingAttr;
CORE_EXPORT extern const blink::QualifiedName& kEnctypeAttr;
CORE_EXPORT extern const blink::QualifiedName& kEndAttr;
CORE_EXPORT extern const blink::QualifiedName& kEnterkeyhintAttr;
CORE_EXPORT extern const blink::QualifiedName& kEventAttr;
CORE_EXPORT extern const blink::QualifiedName& kExportpartsAttr;
CORE_EXPORT extern const blink::QualifiedName& kFaceAttr;
CORE_EXPORT extern const blink::QualifiedName& kFetchpriorityAttr;
CORE_EXPORT extern const blink::QualifiedName& kFocusgroupAttr;
CORE_EXPORT extern const blink::QualifiedName& kForAttr;
CORE_EXPORT extern const blink::QualifiedName& kFormAttr;
CORE_EXPORT extern const blink::QualifiedName& kFormactionAttr;
CORE_EXPORT extern const blink::QualifiedName& kFormenctypeAttr;
CORE_EXPORT extern const blink::QualifiedName& kFormmethodAttr;
CORE_EXPORT extern const blink::QualifiedName& kFormnovalidateAttr;
CORE_EXPORT extern const blink::QualifiedName& kFormtargetAttr;
CORE_EXPORT extern const blink::QualifiedName& kFrameAttr;
CORE_EXPORT extern const blink::QualifiedName& kFrameborderAttr;
CORE_EXPORT extern const blink::QualifiedName& kHeadersAttr;
CORE_EXPORT extern const blink::QualifiedName& kHeightAttr;
CORE_EXPORT extern const blink::QualifiedName& kHiddenAttr;
CORE_EXPORT extern const blink::QualifiedName& kHighAttr;
CORE_EXPORT extern const blink::QualifiedName& kHrefAttr;
CORE_EXPORT extern const blink::QualifiedName& kHreflangAttr;
CORE_EXPORT extern const blink::QualifiedName& kHreftranslateAttr;
CORE_EXPORT extern const blink::QualifiedName& kHspaceAttr;
CORE_EXPORT extern const blink::QualifiedName& kHttpEquivAttr;
CORE_EXPORT extern const blink::QualifiedName& kIdAttr;
CORE_EXPORT extern const blink::QualifiedName& kImagesizesAttr;
CORE_EXPORT extern const blink::QualifiedName& kImagesrcsetAttr;
CORE_EXPORT extern const blink::QualifiedName& kIncrementalAttr;
CORE_EXPORT extern const blink::QualifiedName& kInertAttr;
CORE_EXPORT extern const blink::QualifiedName& kInputmodeAttr;
CORE_EXPORT extern const blink::QualifiedName& kIntegrityAttr;
CORE_EXPORT extern const blink::QualifiedName& kInterestactionAttr;
CORE_EXPORT extern const blink::QualifiedName& kInteresttargetAttr;
CORE_EXPORT extern const blink::QualifiedName& kInvisibleAttr;
CORE_EXPORT extern const blink::QualifiedName& kIsAttr;
CORE_EXPORT extern const blink::QualifiedName& kIsmapAttr;
CORE_EXPORT extern const blink::QualifiedName& kItempropAttr;
CORE_EXPORT extern const blink::QualifiedName& kKeytypeAttr;
CORE_EXPORT extern const blink::QualifiedName& kKindAttr;
CORE_EXPORT extern const blink::QualifiedName& kLabelAttr;
CORE_EXPORT extern const blink::QualifiedName& kLangAttr;
CORE_EXPORT extern const blink::QualifiedName& kLanguageAttr;
CORE_EXPORT extern const blink::QualifiedName& kLatencyhintAttr;
CORE_EXPORT extern const blink::QualifiedName& kLeftmarginAttr;
CORE_EXPORT extern const blink::QualifiedName& kLinkAttr;
CORE_EXPORT extern const blink::QualifiedName& kListAttr;
CORE_EXPORT extern const blink::QualifiedName& kLoadingAttr;
CORE_EXPORT extern const blink::QualifiedName& kLongdescAttr;
CORE_EXPORT extern const blink::QualifiedName& kLoopAttr;
CORE_EXPORT extern const blink::QualifiedName& kLowAttr;
CORE_EXPORT extern const blink::QualifiedName& kLowsrcAttr;
CORE_EXPORT extern const blink::QualifiedName& kManifestAttr;
CORE_EXPORT extern const blink::QualifiedName& kMarginheightAttr;
CORE_EXPORT extern const blink::QualifiedName& kMarginwidthAttr;
CORE_EXPORT extern const blink::QualifiedName& kMaxAttr;
CORE_EXPORT extern const blink::QualifiedName& kMaxlengthAttr;
CORE_EXPORT extern const blink::QualifiedName& kMayscriptAttr;
CORE_EXPORT extern const blink::QualifiedName& kMediaAttr;
CORE_EXPORT extern const blink::QualifiedName& kMethodAttr;
CORE_EXPORT extern const blink::QualifiedName& kMinAttr;
CORE_EXPORT extern const blink::QualifiedName& kMinlengthAttr;
CORE_EXPORT extern const blink::QualifiedName& kMultipleAttr;
CORE_EXPORT extern const blink::QualifiedName& kMutedAttr;
CORE_EXPORT extern const blink::QualifiedName& kNameAttr;
CORE_EXPORT extern const blink::QualifiedName& kNohrefAttr;
CORE_EXPORT extern const blink::QualifiedName& kNomoduleAttr;
CORE_EXPORT extern const blink::QualifiedName& kNonceAttr;
CORE_EXPORT extern const blink::QualifiedName& kNoresizeAttr;
CORE_EXPORT extern const blink::QualifiedName& kNoshadeAttr;
CORE_EXPORT extern const blink::QualifiedName& kNovalidateAttr;
CORE_EXPORT extern const blink::QualifiedName& kNowrapAttr;
CORE_EXPORT extern const blink::QualifiedName& kObjectAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnabortAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnafterprintAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnanimationendAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnanimationiterationAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnanimationstartAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnauxclickAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnbeforecopyAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnbeforecutAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnbeforeinputAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnbeforepasteAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnbeforeprintAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnbeforetoggleAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnbeforeunloadAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnblurAttr;
CORE_EXPORT extern const blink::QualifiedName& kOncancelAttr;
CORE_EXPORT extern const blink::QualifiedName& kOncanplayAttr;
CORE_EXPORT extern const blink::QualifiedName& kOncanplaythroughAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnchangeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnclickAttr;
CORE_EXPORT extern const blink::QualifiedName& kOncloseAttr;
CORE_EXPORT extern const blink::QualifiedName& kOncontentvisibilityautostatechangeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOncontextlostAttr;
CORE_EXPORT extern const blink::QualifiedName& kOncontextmenuAttr;
CORE_EXPORT extern const blink::QualifiedName& kOncontextrestoredAttr;
CORE_EXPORT extern const blink::QualifiedName& kOncopyAttr;
CORE_EXPORT extern const blink::QualifiedName& kOncuechangeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOncutAttr;
CORE_EXPORT extern const blink::QualifiedName& kOndblclickAttr;
CORE_EXPORT extern const blink::QualifiedName& kOndismissAttr;
CORE_EXPORT extern const blink::QualifiedName& kOndragAttr;
CORE_EXPORT extern const blink::QualifiedName& kOndragendAttr;
CORE_EXPORT extern const blink::QualifiedName& kOndragenterAttr;
CORE_EXPORT extern const blink::QualifiedName& kOndragleaveAttr;
CORE_EXPORT extern const blink::QualifiedName& kOndragoverAttr;
CORE_EXPORT extern const blink::QualifiedName& kOndragstartAttr;
CORE_EXPORT extern const blink::QualifiedName& kOndropAttr;
CORE_EXPORT extern const blink::QualifiedName& kOndurationchangeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnemptiedAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnendedAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnerrorAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnfocusAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnfocusinAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnfocusoutAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnformdataAttr;
CORE_EXPORT extern const blink::QualifiedName& kOngotpointercaptureAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnhashchangeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOninputAttr;
CORE_EXPORT extern const blink::QualifiedName& kOninvalidAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnkeydownAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnkeypressAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnkeyupAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnlanguagechangeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnloadAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnloadeddataAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnloadedmetadataAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnloadstartAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnlostpointercaptureAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnmessageAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnmessageerrorAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnmousedownAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnmouseenterAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnmouseleaveAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnmousemoveAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnmouseoutAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnmouseoverAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnmouseupAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnmousewheelAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnmoveAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnofflineAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnonlineAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnorientationchangeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnoverscrollAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnpagehideAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnpageshowAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnpasteAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnpauseAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnplayAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnplayingAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnpointercancelAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnpointerdownAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnpointerenterAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnpointerleaveAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnpointermoveAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnpointeroutAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnpointeroverAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnpointerrawupdateAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnpointerupAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnpopstateAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnprogressAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnratechangeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnresetAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnresizeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnresolveAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnscrollAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnscrollendAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnscrollsnapchangeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnscrollsnapchangingAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnsearchAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnsecuritypolicyviolationAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnseekedAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnseekingAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnselectAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnselectionchangeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnselectstartAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnshowAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnslotchangeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnstalledAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnstorageAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnsubmitAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnsuspendAttr;
CORE_EXPORT extern const blink::QualifiedName& kOntimeupdateAttr;
CORE_EXPORT extern const blink::QualifiedName& kOntimezonechangeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOntoggleAttr;
CORE_EXPORT extern const blink::QualifiedName& kOntouchcancelAttr;
CORE_EXPORT extern const blink::QualifiedName& kOntouchendAttr;
CORE_EXPORT extern const blink::QualifiedName& kOntouchmoveAttr;
CORE_EXPORT extern const blink::QualifiedName& kOntouchstartAttr;
CORE_EXPORT extern const blink::QualifiedName& kOntransitionendAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnunloadAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnvalidationstatuschangeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnvolumechangeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnwaitingAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnwebkitanimationendAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnwebkitanimationiterationAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnwebkitanimationstartAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnwebkitfullscreenchangeAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnwebkitfullscreenerrorAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnwebkittransitionendAttr;
CORE_EXPORT extern const blink::QualifiedName& kOnwheelAttr;
CORE_EXPORT extern const blink::QualifiedName& kOpenAttr;
CORE_EXPORT extern const blink::QualifiedName& kOptimumAttr;
CORE_EXPORT extern const blink::QualifiedName& kParsepartsAttr;
CORE_EXPORT extern const blink::QualifiedName& kPartAttr;
CORE_EXPORT extern const blink::QualifiedName& kPatternAttr;
CORE_EXPORT extern const blink::QualifiedName& kPingAttr;
CORE_EXPORT extern const blink::QualifiedName& kPlaceholderAttr;
CORE_EXPORT extern const blink::QualifiedName& kPlaysinlineAttr;
CORE_EXPORT extern const blink::QualifiedName& kPolicyAttr;
CORE_EXPORT extern const blink::QualifiedName& kPopoverAttr;
CORE_EXPORT extern const blink::QualifiedName& kPopovertargetAttr;
CORE_EXPORT extern const blink::QualifiedName& kPopovertargetactionAttr;
CORE_EXPORT extern const blink::QualifiedName& kPosterAttr;
CORE_EXPORT extern const blink::QualifiedName& kPreciselocationAttr;
CORE_EXPORT extern const blink::QualifiedName& kPreloadAttr;
CORE_EXPORT extern const blink::QualifiedName& kPrivatetokenAttr;
CORE_EXPORT extern const blink::QualifiedName& kPropertyAttr;
CORE_EXPORT extern const blink::QualifiedName& kPseudoAttr;
CORE_EXPORT extern const blink::QualifiedName& kReadonlyAttr;
CORE_EXPORT extern const blink::QualifiedName& kReferrerpolicyAttr;
CORE_EXPORT extern const blink::QualifiedName& kRelAttr;
CORE_EXPORT extern const blink::QualifiedName& kRequiredAttr;
CORE_EXPORT extern const blink::QualifiedName& kRevAttr;
CORE_EXPORT extern const blink::QualifiedName& kReversedAttr;
CORE_EXPORT extern const blink::QualifiedName& kRoleAttr;
CORE_EXPORT extern const blink::QualifiedName& kRowsAttr;
CORE_EXPORT extern const blink::QualifiedName& kRowspanAttr;
CORE_EXPORT extern const blink::QualifiedName& kRulesAttr;
CORE_EXPORT extern const blink::QualifiedName& kSandboxAttr;
CORE_EXPORT extern const blink::QualifiedName& kSchemeAttr;
CORE_EXPORT extern const blink::QualifiedName& kScopeAttr;
CORE_EXPORT extern const blink::QualifiedName& kScrollamountAttr;
CORE_EXPORT extern const blink::QualifiedName& kScrolldelayAttr;
CORE_EXPORT extern const blink::QualifiedName& kScrollingAttr;
CORE_EXPORT extern const blink::QualifiedName& kSelectAttr;
CORE_EXPORT extern const blink::QualifiedName& kSelectedAttr;
CORE_EXPORT extern const blink::QualifiedName& kSelectedcontentelementAttr;
CORE_EXPORT extern const blink::QualifiedName& kShadowrootAttr;
CORE_EXPORT extern const blink::QualifiedName& kShadowrootclonableAttr;
CORE_EXPORT extern const blink::QualifiedName& kShadowrootdelegatesfocusAttr;
CORE_EXPORT extern const blink::QualifiedName& kShadowrootmodeAttr;
CORE_EXPORT extern const blink::QualifiedName& kShadowrootreferencetargetAttr;
CORE_EXPORT extern const blink::QualifiedName& kShadowrootserializableAttr;
CORE_EXPORT extern const blink::QualifiedName& kShapeAttr;
CORE_EXPORT extern const blink::QualifiedName& kSharedstoragewritableAttr;
CORE_EXPORT extern const blink::QualifiedName& kSizeAttr;
CORE_EXPORT extern const blink::QualifiedName& kSizesAttr;
CORE_EXPORT extern const blink::QualifiedName& kSlotAttr;
CORE_EXPORT extern const blink::QualifiedName& kSpanAttr;
CORE_EXPORT extern const blink::QualifiedName& kSpellcheckAttr;
CORE_EXPORT extern const blink::QualifiedName& kSrcAttr;
CORE_EXPORT extern const blink::QualifiedName& kSrcdocAttr;
CORE_EXPORT extern const blink::QualifiedName& kSrclangAttr;
CORE_EXPORT extern const blink::QualifiedName& kSrcsetAttr;
CORE_EXPORT extern const blink::QualifiedName& kStandbyAttr;
CORE_EXPORT extern const blink::QualifiedName& kStartAttr;
CORE_EXPORT extern const blink::QualifiedName& kStepAttr;
CORE_EXPORT extern const blink::QualifiedName& kStyleAttr;
CORE_EXPORT extern const blink::QualifiedName& kSummaryAttr;
CORE_EXPORT extern const blink::QualifiedName& kTabindexAttr;
CORE_EXPORT extern const blink::QualifiedName& kTargetAttr;
CORE_EXPORT extern const blink::QualifiedName& kTextAttr;
CORE_EXPORT extern const blink::QualifiedName& kTitleAttr;
CORE_EXPORT extern const blink::QualifiedName& kTopmarginAttr;
CORE_EXPORT extern const blink::QualifiedName& kTranslateAttr;
CORE_EXPORT extern const blink::QualifiedName& kTruespeedAttr;
CORE_EXPORT extern const blink::QualifiedName& kTypeAttr;
CORE_EXPORT extern const blink::QualifiedName& kUsemapAttr;
CORE_EXPORT extern const blink::QualifiedName& kValignAttr;
CORE_EXPORT extern const blink::QualifiedName& kValueAttr;
CORE_EXPORT extern const blink::QualifiedName& kValuetypeAttr;
CORE_EXPORT extern const blink::QualifiedName& kVersionAttr;
CORE_EXPORT extern const blink::QualifiedName& kVirtualkeyboardpolicyAttr;
CORE_EXPORT extern const blink::QualifiedName& kVlinkAttr;
CORE_EXPORT extern const blink::QualifiedName& kVspaceAttr;
CORE_EXPORT extern const blink::QualifiedName& kWebkitdirectoryAttr;
CORE_EXPORT extern const blink::QualifiedName& kWidthAttr;
CORE_EXPORT extern const blink::QualifiedName& kWrapAttr;
CORE_EXPORT extern const blink::QualifiedName& kWritingsuggestionsAttr;

constexpr unsigned kTagsCount = 142;
CORE_EXPORT std::unique_ptr<const HTMLQualifiedName*[]> GetTags();

constexpr unsigned kAttrsCount = 413;

CORE_EXPORT extern const blink::HTMLQualifiedName& TagToQualifiedName(HTMLTag tag);

void Init();

} // namespace html_names
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_HTML_NAMES_H_
