// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_lookup_trie.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/html_tag_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_HTML_ELEMENT_LOOKUP_TRIE_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_HTML_ELEMENT_LOOKUP_TRIE_H_

#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_uchar.h"

namespace blink {
namespace html_names {
enum class HTMLTag;
}

// Returns the tag for the supplied string. If the string matches a valid tag,
// `tag` is set and true is returned, otherwise this returns false.
CORE_EXPORT html_names::HTMLTag lookupHTMLTag(const UChar* data, unsigned length);

// Returns the tag for the supplied string. If the string matches a valid tag,
// `tag` is set and true is returned, otherwise this returns false.
CORE_EXPORT html_names::HTMLTag lookupHTMLTag(const LChar* data, unsigned length);

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_HTML_ELEMENT_LOOKUP_TRIE_H_
