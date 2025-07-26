// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <stdint.h>
#include <vector>

// Get basic type definitions.
#define IPC_MESSAGE_IMPL
#include "mojo/public/cpp/mojo_lite_msg.h"

// Generate constructors.
#include "ipc_lite/struct_constructor_macros.h"
#include "mojo/public/cpp/mojo_lite_msg.h"

// Generate destructors.
#include "ipc_lite/struct_destructor_macros.h"
#include "mojo/public/cpp/mojo_lite_msg.h"

// Generate param traits write methods.
#include "ipc_lite/param_traits_write_macros.h"
namespace IPC {
#include "mojo/public/cpp/mojo_lite_msg.h"
} // namespace IPC

// Generate param traits read methods.
#include "ipc_lite/param_traits_read_macros.h"
namespace IPC {
#include "mojo/public/cpp/mojo_lite_msg.h"
} // namespace IPC

// Generate param traits log methods.
#include "ipc_lite/param_traits_log_macros.h"
namespace IPC {
#include "mojo/public/cpp/mojo_lite_msg.h"
} // namespace IPC
