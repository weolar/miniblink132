// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "electron/common/gin_helper/per_context_data.h"

#include "base/logging.h"
#include "electron/common/gin_helper/public/context_holder.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "electron/common/gin_helper/public/gin_embedders.h"

namespace gin_helper {

PerContextData::PerContextData(ContextHolder* context_holder, v8::Local<v8::Context> context)
    : context_holder_(context_holder)
    , runner_(NULL)
{
    context->SetAlignedPointerInEmbedderData(kPerContextDataStartIndex + gin_helper::GinEmbedder::kEmbedderNativeGin, this);
}

PerContextData::~PerContextData()
{
    v8::HandleScope handle_scope(context_holder_->isolate());
    context_holder_->context()->SetAlignedPointerInEmbedderData(kPerContextDataStartIndex + gin_helper::GinEmbedder::kEmbedderNativeGin, NULL);
}

// static
PerContextData* PerContextData::From(v8::Local<v8::Context> context)
{
    return static_cast<PerContextData*>(context->GetAlignedPointerFromEmbedderData(gin_helper::InternalFields::kEncodedValueIndex));
}

} // namespace gin_helper
