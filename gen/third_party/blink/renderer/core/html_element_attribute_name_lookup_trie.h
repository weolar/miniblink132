// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_attribute_name_lookup_trie.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/html_attribute_names.json5

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_HTML_ELEMENT_ATTRIBUTE_NAME_LOOKUP_TRIE_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_HTML_ELEMENT_ATTRIBUTE_NAME_LOOKUP_TRIE_H_

#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_uchar.h"

namespace blink {

class QualifiedName;

// Returns the QualifiedName for the attribute whose name matches `data`.
// Returns `g_null_name` if there is no match. It is expected this is only
// called if `length` is > 0.
CORE_EXPORT const QualifiedName& LookupHTMLAttributeName(const UChar* data, unsigned length);

// Returns the QualifiedName for the attribute whose name matches `data`.
// Returns `g_null_name` if there is no match. It is expected this is only
// called if `length` is > 0.
CORE_EXPORT const QualifiedName& LookupHTMLAttributeName(const LChar* data, unsigned length);

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_HTML_ELEMENT_ATTRIBUTE_NAME_LOOKUP_TRIE_H_
