// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_type_helpers.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/html_tag_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_HTML_ELEMENT_TYPE_HELPERS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_HTML_ELEMENT_TYPE_HELPERS_H_

#include "third_party/blink/renderer/core/html/html_element.h"
#include "third_party/blink/renderer/core/html_names.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

class Document;

// Type checking.
class HTMLAnchorElement;
template <> struct DowncastTraits<HTMLAnchorElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kATag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLAnchorElement is forward declared and not included.
    template <typename T = HTMLAnchorElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLAnchorElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLAreaElement;
template <> struct DowncastTraits<HTMLAreaElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kAreaTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLAreaElement is forward declared and not included.
    template <typename T = HTMLAreaElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLAreaElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLAudioElement;
template <> struct DowncastTraits<HTMLAudioElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kAudioTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLAudioElement is forward declared and not included.
    template <typename T = HTMLAudioElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLAudioElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLBaseElement;
template <> struct DowncastTraits<HTMLBaseElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kBaseTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLBaseElement is forward declared and not included.
    template <typename T = HTMLBaseElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLBaseElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLBDIElement;
template <> struct DowncastTraits<HTMLBDIElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kBdiTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLBDIElement is forward declared and not included.
    template <typename T = HTMLBDIElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLBDIElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLBodyElement;
template <> struct DowncastTraits<HTMLBodyElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kBodyTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLBodyElement is forward declared and not included.
    template <typename T = HTMLBodyElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLBodyElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLBRElement;
template <> struct DowncastTraits<HTMLBRElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kBrTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLBRElement is forward declared and not included.
    template <typename T = HTMLBRElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLBRElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLButtonElement;
template <> struct DowncastTraits<HTMLButtonElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kButtonTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLButtonElement is forward declared and not included.
    template <typename T = HTMLButtonElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLButtonElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLCanvasElement;
template <> struct DowncastTraits<HTMLCanvasElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kCanvasTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLCanvasElement is forward declared and not included.
    template <typename T = HTMLCanvasElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLCanvasElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLTableCaptionElement;
template <> struct DowncastTraits<HTMLTableCaptionElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kCaptionTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLTableCaptionElement is forward declared and not included.
    template <typename T = HTMLTableCaptionElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLTableCaptionElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLDataElement;
template <> struct DowncastTraits<HTMLDataElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kDataTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLDataElement is forward declared and not included.
    template <typename T = HTMLDataElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLDataElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLDataListElement;
template <> struct DowncastTraits<HTMLDataListElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kDatalistTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLDataListElement is forward declared and not included.
    template <typename T = HTMLDataListElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLDataListElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLDetailsElement;
template <> struct DowncastTraits<HTMLDetailsElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kDetailsTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLDetailsElement is forward declared and not included.
    template <typename T = HTMLDetailsElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLDetailsElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLDialogElement;
template <> struct DowncastTraits<HTMLDialogElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kDialogTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLDialogElement is forward declared and not included.
    template <typename T = HTMLDialogElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLDialogElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLDirectoryElement;
template <> struct DowncastTraits<HTMLDirectoryElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kDirTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLDirectoryElement is forward declared and not included.
    template <typename T = HTMLDirectoryElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLDirectoryElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLDivElement;
template <> struct DowncastTraits<HTMLDivElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kDivTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLDivElement is forward declared and not included.
    template <typename T = HTMLDivElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLDivElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLDListElement;
template <> struct DowncastTraits<HTMLDListElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kDlTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLDListElement is forward declared and not included.
    template <typename T = HTMLDListElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLDListElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLEmbedElement;
template <> struct DowncastTraits<HTMLEmbedElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kEmbedTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLEmbedElement is forward declared and not included.
    template <typename T = HTMLEmbedElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLEmbedElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLFieldSetElement;
template <> struct DowncastTraits<HTMLFieldSetElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kFieldsetTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLFieldSetElement is forward declared and not included.
    template <typename T = HTMLFieldSetElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLFieldSetElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLFontElement;
template <> struct DowncastTraits<HTMLFontElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kFontTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLFontElement is forward declared and not included.
    template <typename T = HTMLFontElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLFontElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLFormElement;
template <> struct DowncastTraits<HTMLFormElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kFormTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLFormElement is forward declared and not included.
    template <typename T = HTMLFormElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLFormElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLFrameElement;
template <> struct DowncastTraits<HTMLFrameElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kFrameTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLFrameElement is forward declared and not included.
    template <typename T = HTMLFrameElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLFrameElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLFrameSetElement;
template <> struct DowncastTraits<HTMLFrameSetElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kFramesetTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLFrameSetElement is forward declared and not included.
    template <typename T = HTMLFrameSetElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLFrameSetElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLHeadElement;
template <> struct DowncastTraits<HTMLHeadElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kHeadTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLHeadElement is forward declared and not included.
    template <typename T = HTMLHeadElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLHeadElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLHRElement;
template <> struct DowncastTraits<HTMLHRElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kHrTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLHRElement is forward declared and not included.
    template <typename T = HTMLHRElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLHRElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLHtmlElement;
template <> struct DowncastTraits<HTMLHtmlElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kHTMLTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLHtmlElement is forward declared and not included.
    template <typename T = HTMLHtmlElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLHtmlElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLIFrameElement;
template <> struct DowncastTraits<HTMLIFrameElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kIFrameTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLIFrameElement is forward declared and not included.
    template <typename T = HTMLIFrameElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLIFrameElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLImageElement;
template <> struct DowncastTraits<HTMLImageElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kImgTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLImageElement is forward declared and not included.
    template <typename T = HTMLImageElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLImageElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLInputElement;
template <> struct DowncastTraits<HTMLInputElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kInputTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLInputElement is forward declared and not included.
    template <typename T = HTMLInputElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLInputElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLLabelElement;
template <> struct DowncastTraits<HTMLLabelElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kLabelTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLLabelElement is forward declared and not included.
    template <typename T = HTMLLabelElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLLabelElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLLegendElement;
template <> struct DowncastTraits<HTMLLegendElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kLegendTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLLegendElement is forward declared and not included.
    template <typename T = HTMLLegendElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLLegendElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLLIElement;
template <> struct DowncastTraits<HTMLLIElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kLiTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLLIElement is forward declared and not included.
    template <typename T = HTMLLIElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLLIElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLLinkElement;
template <> struct DowncastTraits<HTMLLinkElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kLinkTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLLinkElement is forward declared and not included.
    template <typename T = HTMLLinkElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLLinkElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLMapElement;
template <> struct DowncastTraits<HTMLMapElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kMapTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLMapElement is forward declared and not included.
    template <typename T = HTMLMapElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLMapElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLMarqueeElement;
template <> struct DowncastTraits<HTMLMarqueeElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kMarqueeTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLMarqueeElement is forward declared and not included.
    template <typename T = HTMLMarqueeElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLMarqueeElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLMenuElement;
template <> struct DowncastTraits<HTMLMenuElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kMenuTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLMenuElement is forward declared and not included.
    template <typename T = HTMLMenuElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLMenuElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLMetaElement;
template <> struct DowncastTraits<HTMLMetaElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kMetaTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLMetaElement is forward declared and not included.
    template <typename T = HTMLMetaElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLMetaElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLMeterElement;
template <> struct DowncastTraits<HTMLMeterElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kMeterTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLMeterElement is forward declared and not included.
    template <typename T = HTMLMeterElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLMeterElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLNoEmbedElement;
template <> struct DowncastTraits<HTMLNoEmbedElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kNoembedTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLNoEmbedElement is forward declared and not included.
    template <typename T = HTMLNoEmbedElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLNoEmbedElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLNoScriptElement;
template <> struct DowncastTraits<HTMLNoScriptElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kNoscriptTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLNoScriptElement is forward declared and not included.
    template <typename T = HTMLNoScriptElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLNoScriptElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLOListElement;
template <> struct DowncastTraits<HTMLOListElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kOlTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLOListElement is forward declared and not included.
    template <typename T = HTMLOListElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLOListElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLOptGroupElement;
template <> struct DowncastTraits<HTMLOptGroupElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kOptgroupTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLOptGroupElement is forward declared and not included.
    template <typename T = HTMLOptGroupElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLOptGroupElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLOptionElement;
template <> struct DowncastTraits<HTMLOptionElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kOptionTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLOptionElement is forward declared and not included.
    template <typename T = HTMLOptionElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLOptionElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLOutputElement;
template <> struct DowncastTraits<HTMLOutputElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kOutputTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLOutputElement is forward declared and not included.
    template <typename T = HTMLOutputElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLOutputElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLParagraphElement;
template <> struct DowncastTraits<HTMLParagraphElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kPTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLParagraphElement is forward declared and not included.
    template <typename T = HTMLParagraphElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLParagraphElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLParamElement;
template <> struct DowncastTraits<HTMLParamElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kParamTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLParamElement is forward declared and not included.
    template <typename T = HTMLParamElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLParamElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLPictureElement;
template <> struct DowncastTraits<HTMLPictureElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kPictureTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLPictureElement is forward declared and not included.
    template <typename T = HTMLPictureElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLPictureElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLProgressElement;
template <> struct DowncastTraits<HTMLProgressElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kProgressTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLProgressElement is forward declared and not included.
    template <typename T = HTMLProgressElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLProgressElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLScriptElement;
template <> struct DowncastTraits<HTMLScriptElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kScriptTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLScriptElement is forward declared and not included.
    template <typename T = HTMLScriptElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLScriptElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLSearchElement;
template <> struct DowncastTraits<HTMLSearchElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kSearchTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLSearchElement is forward declared and not included.
    template <typename T = HTMLSearchElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLSearchElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLSelectElement;
template <> struct DowncastTraits<HTMLSelectElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kSelectTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLSelectElement is forward declared and not included.
    template <typename T = HTMLSelectElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLSelectElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLSelectedContentElement;
template <> struct DowncastTraits<HTMLSelectedContentElement> {
    static bool AllowFrom(const Element& element)
    {
        // If the following line doesn't compile, your feature may vary by context,
        // in which case you'll need to write your own type helpers that can
        // distinguish elements without relying solely on tag name.
        if (!RuntimeEnabledFeatures::CustomizableSelectEnabled())
            return false;
        return element.HasTagName(html_names::kSelectedcontentTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLSelectedContentElement is forward declared and not included.
    template <typename T = HTMLSelectedContentElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLSelectedContentElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLSlotElement;
template <> struct DowncastTraits<HTMLSlotElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kSlotTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLSlotElement is forward declared and not included.
    template <typename T = HTMLSlotElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLSlotElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLSourceElement;
template <> struct DowncastTraits<HTMLSourceElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kSourceTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLSourceElement is forward declared and not included.
    template <typename T = HTMLSourceElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLSourceElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLSpanElement;
template <> struct DowncastTraits<HTMLSpanElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kSpanTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLSpanElement is forward declared and not included.
    template <typename T = HTMLSpanElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLSpanElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLStyleElement;
template <> struct DowncastTraits<HTMLStyleElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kStyleTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLStyleElement is forward declared and not included.
    template <typename T = HTMLStyleElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLStyleElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLSummaryElement;
template <> struct DowncastTraits<HTMLSummaryElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kSummaryTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLSummaryElement is forward declared and not included.
    template <typename T = HTMLSummaryElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLSummaryElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLTableElement;
template <> struct DowncastTraits<HTMLTableElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kTableTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLTableElement is forward declared and not included.
    template <typename T = HTMLTableElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLTableElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLTemplateElement;
template <> struct DowncastTraits<HTMLTemplateElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kTemplateTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLTemplateElement is forward declared and not included.
    template <typename T = HTMLTemplateElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLTemplateElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLTextAreaElement;
template <> struct DowncastTraits<HTMLTextAreaElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kTextareaTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLTextAreaElement is forward declared and not included.
    template <typename T = HTMLTextAreaElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLTextAreaElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLTimeElement;
template <> struct DowncastTraits<HTMLTimeElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kTimeTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLTimeElement is forward declared and not included.
    template <typename T = HTMLTimeElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLTimeElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLTitleElement;
template <> struct DowncastTraits<HTMLTitleElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kTitleTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLTitleElement is forward declared and not included.
    template <typename T = HTMLTitleElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLTitleElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLTableRowElement;
template <> struct DowncastTraits<HTMLTableRowElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kTrTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLTableRowElement is forward declared and not included.
    template <typename T = HTMLTableRowElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLTableRowElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLTrackElement;
template <> struct DowncastTraits<HTMLTrackElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kTrackTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLTrackElement is forward declared and not included.
    template <typename T = HTMLTrackElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLTrackElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLUListElement;
template <> struct DowncastTraits<HTMLUListElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kUlTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLUListElement is forward declared and not included.
    template <typename T = HTMLUListElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLUListElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLVideoElement;
template <> struct DowncastTraits<HTMLVideoElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kVideoTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLVideoElement is forward declared and not included.
    template <typename T = HTMLVideoElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLVideoElement>(UnsafeTo<HTMLElement>(node));
    }
};

class HTMLWBRElement;
template <> struct DowncastTraits<HTMLWBRElement> {
    static bool AllowFrom(const Element& element)
    {
        return element.HasTagName(html_names::kWbrTag);
    }
    // Force this helper to only be instantiated when used. Otherwise, the
    // `IsA<...>` calls will always trigger a build failure since
    // HTMLWBRElement is forward declared and not included.
    template <typename T = HTMLWBRElement> static bool AllowFrom(const Node& node)
    {
        // UnsafeTo<> is safe because Is*Element(), by definition, only returns
        // true if `node` is derived from `Element`.
        return node.IsHTMLElement() && IsA<HTMLWBRElement>(UnsafeTo<HTMLElement>(node));
    }
};

enum class HTMLElementType {
    kHTMLAnchorElement,
    kHTMLAreaElement,
    kHTMLAudioElement,
    kHTMLBaseElement,
    kHTMLBodyElement,
    kHTMLBRElement,
    kHTMLButtonElement,
    kHTMLCanvasElement,
    kHTMLDataElement,
    kHTMLDataListElement,
    kHTMLDetailsElement,
    kHTMLDialogElement,
    kHTMLDirectoryElement,
    kHTMLDivElement,
    kHTMLDListElement,
    kHTMLElement,
    kHTMLEmbedElement,
    kHTMLFencedFrameElement,
    kHTMLFieldSetElement,
    kHTMLFontElement,
    kHTMLFormElement,
    kHTMLFrameElement,
    kHTMLFrameSetElement,
    kHTMLHeadElement,
    kHTMLHeadingElement,
    kHTMLHRElement,
    kHTMLHtmlElement,
    kHTMLIFrameElement,
    kHTMLImageElement,
    kHTMLInputElement,
    kHTMLLabelElement,
    kHTMLLegendElement,
    kHTMLLIElement,
    kHTMLLinkElement,
    kHTMLMapElement,
    kHTMLMarqueeElement,
    kHTMLMenuElement,
    kHTMLMetaElement,
    kHTMLMeterElement,
    kHTMLModElement,
    kHTMLObjectElement,
    kHTMLOListElement,
    kHTMLOptGroupElement,
    kHTMLOptionElement,
    kHTMLOutputElement,
    kHTMLParagraphElement,
    kHTMLParamElement,
    kHTMLPermissionElement,
    kHTMLPictureElement,
    kHTMLPreElement,
    kHTMLProgressElement,
    kHTMLQuoteElement,
    kHTMLScriptElement,
    kHTMLSearchElement,
    kHTMLSelectedContentElement,
    kHTMLSelectElement,
    kHTMLSlotElement,
    kHTMLSourceElement,
    kHTMLSpanElement,
    kHTMLStyleElement,
    kHTMLTableCaptionElement,
    kHTMLTableCellElement,
    kHTMLTableColElement,
    kHTMLTableElement,
    kHTMLTableRowElement,
    kHTMLTableSectionElement,
    kHTMLTemplateElement,
    kHTMLTextAreaElement,
    kHTMLTimeElement,
    kHTMLTitleElement,
    kHTMLTrackElement,
    kHTMLUListElement,
    kHTMLUnknownElement,
    kHTMLVideoElement,
};

// Tag checking.
// |tag_name| is the local name for an HTML element in lowercase.
// The corresponding HTMLElement type for the tag name will be returned.
// Do NOT use this function with SVG tag names and SVGElements.
// If |tag_name| is an undefined HTML tag name HTMLUnknownElement is returned.
HTMLElementType HtmlElementTypeForTag(const AtomicString& tag_name, const Document*);

bool IsKnownBuiltinTagName(const AtomicString& tag_name);

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_HTML_ELEMENT_TYPE_HELPERS_H_
