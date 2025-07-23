// Copyright (c) 2013 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/nodeblink.h"
#include "common/NodeRegisterHelp.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/libnode/src/node_version.h"
#include <v8.h>
#include <string>

namespace {

void initializeCommonOriginalFsApi(v8::Local<v8::Object> exports, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, void* priv)
{
}

} // namespace

static const char CommonOriginalFsSricpt[] = "module.exports = require('fs');";

static NodeNative nativeCommonOriginalFsNative { "original-fs", CommonOriginalFsSricpt, sizeof(CommonOriginalFsSricpt) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_common_original_fs, initializeCommonOriginalFsApi, &nativeCommonOriginalFsNative)
