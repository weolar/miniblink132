// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE.chromium file.

#include "electron/common/gin_helper/locker.h"

#include "content/common/ThreadCall.h"

namespace gin_helper {

Locker::Locker(v8::Isolate* isolate)
{
    if (IsBrowserProcess())
        locker_ = std::make_unique<v8::Locker>(isolate);
}

Locker::~Locker() = default;

// void Locker::SetIsBrowserProcess(bool is_browser_process) {
//     g_is_browser_process = is_browser_process;
// }

bool Locker::IsBrowserProcess()
{
    return content::ThreadCall::isUiThread();
}

//bool Locker::g_is_browser_process = false;

} // namespace gin_helper
