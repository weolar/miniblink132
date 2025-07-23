// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GIN_HELPER_PUBLIC_WRAPPER_INFO_H_
#define GIN_HELPER_PUBLIC_WRAPPER_INFO_H_

#include "gin/gin_export.h"
#include "gin/public/wrapper_info.h"

namespace gin_helper {

// Gin embedder that use their own WrapperInfo-like structs must ensure that
// the first field is of type GinEmbedderId and has the correct id set. They
// also should use kWrapperInfoIndex to start their WrapperInfo-like struct
// and ensure that all objects have kNumberOfInternalFields internal fields.
using InternalFields = gin::InternalFields;
using WrapperInfo = gin::WrapperInfo;

} // namespace gin_helper

#endif // GIN_PUBLIC_WRAPPER_INFO_H_
