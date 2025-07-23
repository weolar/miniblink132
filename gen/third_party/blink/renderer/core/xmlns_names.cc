// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_qualified_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/xml/xmlns_attribute_names.json5

#include "third_party/blink/renderer/core/xmlns_names.h"

#include <memory>

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/static_constructors.h"
#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"
#include "third_party/blink/renderer/platform/wtf/text/string_hasher.h"

namespace blink {
namespace xmlns_names {

DEFINE_GLOBAL(AtomicString, kNamespaceURI);

// Attributes

void* attr_storage[kAttrsCount * ((sizeof(QualifiedName) + sizeof(void*) - 1) / sizeof(void*))];

const QualifiedName& kXmlnsAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[0];

std::unique_ptr<const QualifiedName*[]> GetAttrs()
{
    auto attrs = std::make_unique<const QualifiedName*[]>(kAttrsCount);
    for (size_t i = 0; i < kAttrsCount; ++i)
        attrs[i] = reinterpret_cast<QualifiedName*>(&attr_storage) + i;
    return attrs;
}

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
    AtomicString ns_uri("http://www.w3.org/2000/xmlns/");
    new ((void*)&kNamespaceURI) AtomicString(ns_uri);

    static const NameEntry kNames[] = {
        { "xmlns", 5, 0, 1 },
    };

    size_t attr_i = 0;
    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length);
        void* address = reinterpret_cast<QualifiedName*>(&attr_storage) + attr_i;
        QualifiedName::CreateStatic(address, impl, ns_uri);
        ++attr_i;
    }
    DCHECK_EQ(attr_i, kAttrsCount);
}

} // namespace xmlns_names
} // namespace blink
