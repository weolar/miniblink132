// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef LITE_IPC_IPC_CHANNEL_WIN_H_
#define LITE_IPC_IPC_CHANNEL_WIN_H_

#include "ipc_lite/ipc_channel.h"

#include <queue>
#include <string>

//#include "base/memory/scoped_ptr.h"
#include "base/memory/weak_ptr.h"
//#include "base/message_loop.h"
#include "ipc_lite/ipc_channel_reader.h"
#include "base/message_loop/message_pump_for_io.h"
#include "base/message_loop/message_pump_win.h"

namespace base {
class ThreadChecker;
}

namespace IPC {

class Channel::ChannelImpl : public internal::ChannelReader, public base::MessagePumpForIO::IOHandler {
public:
    // Mirror methods of Channel, see ipc_channel.h for description.
    ChannelImpl(const IPC::ChannelHandle& channel_handle, Mode mode, Listener* listener);
    ~ChannelImpl();
    bool Connect();
    void Close();
    bool Send(Message* message);
    static bool IsNamedServerInitialized(const std::string& channel_id);
    base::ProcessId peer_pid() const
    {
        return peer_pid_;
    }

private:
    // ChannelReader implementation.
    virtual ReadState ReadData(char* buffer, int buffer_len, int* bytes_read) OVERRIDE;
    virtual bool WillDispatchInputMessage(Message* msg) OVERRIDE;
    bool DidEmptyInputBuffers() OVERRIDE;
    virtual void HandleHelloMessage(const Message& msg) OVERRIDE;

    static const std::wstring PipeName(const std::string& channel_id, int32_t* secret);
    bool CreatePipe(const IPC::ChannelHandle& channel_handle, Mode mode);

    bool ProcessConnection();
    bool ProcessOutgoingMessages(base::MessagePumpForIO::IOContext* context, DWORD bytes_written);

    // MessageLoop::IOHandler implementation.
    /*virtual*/ void OnIOCompleted(base::MessagePumpForIO::IOContext* context, DWORD bytes_transfered, DWORD error) override;

private:
    struct State {
        explicit State(ChannelImpl* channel);
        ~State();
        base::MessagePumpForIO::IOContext context;
        bool is_pending;
    };

    State input_state_;
    State output_state_;

    HANDLE pipe_;

    base::ProcessId peer_pid_;

    // Messages to be sent are queued here.
    std::queue<Message*> output_queue_;

    // In server-mode, we have to wait for the client to connect before we
    // can begin reading.  We make use of the input_state_ when performing
    // the connect operation in overlapped mode.
    bool waiting_connect_;

    // This flag is set when processing incoming messages.  It is used to
    // avoid recursing through ProcessIncomingMessages, which could cause
    // problems.  TODO(darin): make this unnecessary
    bool processing_incoming_;

    // Determines if we should validate a client's secret on connection.
    bool validate_client_;

    // This is a unique per-channel value used to authenticate the client end of
    // a connection. If the value is non-zero, the client passes it in the hello
    // and the host validates. (We don't send the zero value fto preserve IPC
    // compatability with existing clients that don't validate the channel.)
    int32_t client_secret_;

    std::unique_ptr<base::ThreadChecker> thread_check_;

    base::WeakPtrFactory<ChannelImpl> weak_factory_;

    DISALLOW_COPY_AND_ASSIGN(ChannelImpl);
};

} // namespace IPC

#endif // IPC_IPC_CHANNEL_WIN_H_
