
// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ipc_lite/ipc_message_macros.h"
#include "ipc_lite/ipc_message_utils.h"

// Defines the IPC messages used by the automation interface.

// NOTE: All IPC messages have either a routing_id of 0 (for asynchronous
//       messages), or one that's been assigned by the proxy (for calls
//       which expect a response).  The routing_id shouldn't be used for
//       any other purpose in these message types.

// NOTE: All the new IPC messages should go at the end.
//       The test <--> browser IPC message IDs need to match the reference
//       builds.  Since we now define the IDs based on __LINE__, to allow these
//       IPC messages to be used to control an old version of Chrome we need
//       the message IDs to remain the same.  This means that you should not
//       change the line number of these types of messages. You can, however,
//       change the browser <--> renderer messages.

#define IPC_MESSAGE_START MojoLiteMsgStart

IPC_MESSAGE_CONTROL5(
    CrossProcessConnector_PostMessage, uintptr_t /*pid*/, uintptr_t /*handle*/, int /*state*/, std::vector<char> /*data*/, std::vector<uintptr_t> /*handles*/)
IPC_MESSAGE_CONTROL1(CrossProcessConnector_PostMessageTest, uintptr_t)
