// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef content_common_WebMimeRegistryImpl_h
#define content_common_WebMimeRegistryImpl_h

#include "third_party/blink/public/platform/web_string.h"
#include "third_party/blink/renderer/platform/wtf/hash_set.h"
#include "third_party/blink/renderer/platform/wtf/hash_map.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include <string>

namespace content {

class WebMimeRegistryImpl {
public:
    enum SupportsType { IsNotSupported, IsSupported, MayBeSupported };

    WebMimeRegistryImpl();
    ~WebMimeRegistryImpl();

    // WebMimeRegistry methods:
    SupportsType supportsMIMEType(const blink::WebString&);

    SupportsType supportsImageMIMEType(const blink::WebString&);

    SupportsType supportsJavaScriptMIMEType(const blink::WebString&);

    SupportsType supportsMediaMIMEType(const blink::WebString&, const blink::WebString&, const blink::WebString&);

    bool supportsMediaSourceMIMEType(const blink::WebString&, const blink::WebString&);

    SupportsType supportsNonImageMIMEType(const blink::WebString&);

    blink::WebString mimeTypeForExtension(const blink::WebString&);

    blink::WebString wellKnownMimeTypeForExtension(const blink::WebString&);

    blink::WebString mimeTypeFromFile(const blink::WebString&);

    SupportsType supportsImagePrefixedMIMEType(const blink::WebString& mimeType);

    blink::WebString extensionForMimeType(const blink::WebString& mime);
    Vector<blink::WebString> extensionsForMimeType(const blink::WebString& mime);

    static WebMimeRegistryImpl* get();

private:
    void ensureMimeTypeMap();

    WTF::HashSet<WTF::String>* m_supportedMIMETypes;
    WTF::HashSet<WTF::String>* m_supportedImageResourceMIMETypes;
    WTF::HashSet<WTF::String>* m_supportedJavaScriptMIMETypes;
    WTF::HashSet<String>* m_supportedNonImageMIMETypes;
    WTF::HashMap<WTF::String, WTF::String>* m_mimetypeMap;

    struct MimetypeToExt {
        WTF::String mime;
        WTF::Vector<WTF::String> exts;
    };
    struct MimetypeToExtMap {
        WTF::Vector<MimetypeToExt*> m_map;
        void add(const char* mine, ...);
    };
    MimetypeToExtMap* m_mimetypeToExtMap;
};

} // namespace content

#endif // WebMimeRegistryImpl_h
