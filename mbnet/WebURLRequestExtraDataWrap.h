
/*
 * Copyright (C) 2010 Patrick Gansterer <paroga@paroga.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef mbnet_WebURLRequestExtraDataWrap_h
#define mbnet_WebURLRequestExtraDataWrap_h

#include "third_party/blink/public/platform/web_url_request_extra_data.h"
#include "third_party/blink/public/mojom/loader/request_context_frame_type.mojom-shared.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include <memory>

namespace mbnet {

class WebURLRequestExtraDataWrap : public blink::WebURLRequestExtraData {
public:
    int64_t mbwebviewId = 0;
    MojoHandle dataPipeProducerHandle = 0;
    blink::mojom::RequestContextFrameType frameType = blink::mojom::RequestContextFrameType::kNone;

    void setIsDownload(std::unique_ptr<String> name)
    {
        downloadName = std::move(name);
    }

    bool isDownload() const
    {
        return !!downloadName.get();
    }

    std::unique_ptr<String> releaseDownloadName()
    {
        return std::move(downloadName);
    }

    std::unique_ptr<String> downloadName;
};

}

#endif // mbnet_WebURLRequestExtraDataWrap_h
