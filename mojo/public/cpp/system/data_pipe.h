// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file provides a C++ wrapping around the Mojo C API for data pipes,
// replacing the prefix of "Mojo" with a "mojo" namespace, and using more
// strongly-typed representations of |MojoHandle|s.
//
// Please see "mojo/public/c/system/data_pipe.h" for complete documentation of
// the API.

#ifndef MOJO_PUBLIC_CPP_SYSTEM_DATA_PIPE_H_
#define MOJO_PUBLIC_CPP_SYSTEM_DATA_PIPE_H_

#include <stdint.h>

#include "mojo/public/c/system/data_pipe.h"
#include "mojo/public/c/system/types.h"
#include "mojo/public/cpp/system/handle.h"
#include "base/containers/span.h"

namespace mojo {

// A strongly-typed representation of a |MojoHandle| to the producer end of a
// data pipe.
class DataPipeProducerHandle : public Handle {
public:
    DataPipeProducerHandle()
    {
    }
    explicit DataPipeProducerHandle(MojoHandle value)
        : Handle(value)
    {
    }

    MojoResult WriteData(base::span<const uint8_t> data, MojoWriteDataFlags flags, size_t& bytes_written) const
    {
        MojoWriteDataOptions options;
        options.struct_size = sizeof(options);
        options.flags = flags;

        // Because of ABI-stability requirements, the C-level APIs take `uint32_t`.
        // But, for compatibility with C++ containers, the C++ APIs take `size_t`.
        //
        // We use `saturated_cast` so that when `num_bytes` doesn't fit into
        // `uint32_t`, then we will simply report that a smaller number of bytes was
        // written.  We accept that `num_bytes_u32` may no longer being a multiple
        // of `MojoCreateDataPipeOptions::element_num_bytes` and rely on the C layer
        // to return `MOJO_RESULT_INVALID_ARGUMENT` in this case (as reflected in
        // the doc comment above).
        uint32_t num_bytes_u32 = base::saturated_cast<uint32_t>(data.size());

        MojoResult result = MojoWriteData(value(), data.data(), &num_bytes_u32, &options);
        bytes_written = size_t { num_bytes_u32 };
        return result;
    }

    // Writes to a data pipe. See |MojoWriteData| for complete documentation.
    MojoResult WriteData(const void* elements, uint32_t* num_bytes, MojoWriteDataFlags flags) const
    {
        MojoWriteDataOptions options;
        options.struct_size = sizeof(options);
        options.flags = flags;
        return MojoWriteData(value(), elements, num_bytes, &options);
    }

    // Begins a two-phase write to a data pipe. See |MojoBeginWriteData()| for
    // complete documentation.
    MojoResult BeginWriteData(void** buffer, uint32_t* buffer_num_bytes, MojoBeginWriteDataFlags flags) const
    {
        MojoBeginWriteDataOptions options;
        options.struct_size = sizeof(options);
        options.flags = flags;
        return MojoBeginWriteData(value(), &options, buffer, buffer_num_bytes);
    }

    MojoResult BeginWriteData(size_t write_size_hint, MojoBeginWriteDataFlags flags, base::span<uint8_t>& buffer) const
    {
        MojoBeginWriteDataOptions options;
        options.struct_size = sizeof(options);
        options.flags = flags;

        // Because of ABI-stability requirements, the C-level APIs take `uint32_t`.
        // But, for compatibility with C++ containers, the C++ APIs take `size_t`.
        //
        // As documented by MojoBeginWriteData, on input `write_size_hint` is
        // merely a hint of how many bytes the producer is readily able to supply.
        // Therefore we use a `saturated_cast` to gracefully handle big values.
        void* buffer_ptr = nullptr;
        uint32_t buffer_num_bytes = base::saturated_cast<uint32_t>(write_size_hint);
        MojoResult result = MojoBeginWriteData(value(), &options, &buffer_ptr, &buffer_num_bytes);
        if (result == MOJO_RESULT_OK) {
            // SAFETY: Relying on the contract of the `MojoBeginWriteData` C API which
            // says: "On success |*buffer| will be a pointer to which the caller can
            // write up to |*buffer_num_bytes| bytes of data."
            buffer = UNSAFE_BUFFERS(base::span(static_cast<uint8_t*>(buffer_ptr), size_t{ buffer_num_bytes }));
        }
        return result;
    }


    // Completes a two-phase write to a data pipe. See |MojoEndWriteData()| for
    // complete documentation.
    MojoResult EndWriteData(uint32_t num_bytes_written) const
    {
        return MojoEndWriteData(value(), num_bytes_written, nullptr);
    }

    // Copying and assignment allowed.
};

static_assert(sizeof(DataPipeProducerHandle) == sizeof(Handle), "Bad size for C++ DataPipeProducerHandle");

typedef ScopedHandleBase<DataPipeProducerHandle> ScopedDataPipeProducerHandle;
static_assert(sizeof(ScopedDataPipeProducerHandle) == sizeof(DataPipeProducerHandle), "Bad size for C++ ScopedDataPipeProducerHandle");

// A strongly-typed representation of a |MojoHandle| to the consumer end of a
// data pipe.
class DataPipeConsumerHandle : public Handle {
public:
    DataPipeConsumerHandle()
    {
    }
    explicit DataPipeConsumerHandle(MojoHandle value)
        : Handle(value)
    {
    }

    MojoResult ReadData(MojoReadDataFlags flags, base::span<uint8_t> buffer, size_t& bytes_read) const 
    {
        MojoReadDataOptions options;
        options.struct_size = sizeof(options);
        options.flags = flags;

        // Because of ABI-stability requirements, the C-level APIs take `uint32_t`.
        // But, for compatibility with C++ containers, the C++ APIs take `size_t`.
        //
        // Input value of `*num_bytes` is ignored in `MOJO_READ_DATA_FLAG_QUERY`
        // mode and otherwise is an _upper_ bound on how many bytes will be read (or
        // discarded in `MOJO_READ_DATA_FLAG_DISCARD`).  Therefore it is okay to use
        // `saturated_cast` instead of `checked_cast` because the C-layer mojo code
        // will anyway read only up to uin32_t max bytes.
        uint32_t num_bytes = base::saturated_cast<uint32_t>(buffer.size());
        MojoResult result = MojoReadData(value(), &options, buffer.data(), &num_bytes);
        bytes_read = size_t{ num_bytes };
        return result;
    }

    // Reads from a data pipe. See |MojoReadData()| for complete documentation.
    MojoResult ReadData(void* elements, uint32_t* num_bytes, MojoReadDataFlags flags) const
    {
        MojoReadDataOptions options;
        options.struct_size = sizeof(options);
        options.flags = flags;
        return MojoReadData(value(), &options, elements, num_bytes);
    }

    // Begins a two-phase read from a data pipe. See |MojoBeginReadData()| for
    // complete documentation.
    MojoResult BeginReadData(const void** buffer, uint32_t* buffer_num_bytes, MojoBeginReadDataFlags flags) const
    {
        MojoBeginReadDataOptions options;
        options.struct_size = sizeof(options);
        options.flags = flags;
        return MojoBeginReadData(value(), &options, buffer, buffer_num_bytes);
    }

    MojoResult BeginReadData(MojoBeginReadDataFlags flags, base::span<const uint8_t>& buffer) const
    {
        MojoBeginReadDataOptions options;
        options.struct_size = sizeof(options);
        options.flags = flags;

        const void* data = nullptr;
        uint32_t buffer_num_bytes = 0;
        MojoResult result = MojoBeginReadData(value(), &options, &data, &buffer_num_bytes);
        if (result == MOJO_RESULT_OK) {
            // SAFETY: Relying on the contract of the `MojoBeginReadData` C API which
            // says: "On success, |*buffer| will be a pointer from which the caller
            // can read up to |*buffer_num_bytes| bytes of data."
            buffer = UNSAFE_BUFFERS(base::span(static_cast<const uint8_t*>(data), size_t { buffer_num_bytes }));
        }
        return result;
    }

    // Completes a two-phase read from a data pipe. See |MojoEndReadData()| for
    // complete documentation.
    MojoResult EndReadData(uint32_t num_bytes_read) const
    {
        return MojoEndReadData(value(), num_bytes_read, nullptr);
    }

    // Copying and assignment allowed.
};

static_assert(sizeof(DataPipeConsumerHandle) == sizeof(Handle), "Bad size for C++ DataPipeConsumerHandle");

typedef ScopedHandleBase<DataPipeConsumerHandle> ScopedDataPipeConsumerHandle;
static_assert(sizeof(ScopedDataPipeConsumerHandle) == sizeof(DataPipeConsumerHandle), "Bad size for C++ ScopedDataPipeConsumerHandle");

// Creates a new data pipe. See |MojoCreateDataPipe()| for complete
// documentation.
inline MojoResult CreateDataPipe(
    const MojoCreateDataPipeOptions* options, ScopedDataPipeProducerHandle& data_pipe_producer, ScopedDataPipeConsumerHandle& data_pipe_consumer)
{
    DataPipeProducerHandle producer_handle;
    DataPipeConsumerHandle consumer_handle;
    MojoResult rv = MojoCreateDataPipe(options, producer_handle.mutable_value(), consumer_handle.mutable_value());
    // Reset even on failure (reduces the chances that a "stale"/incorrect handle
    // will be used).
    data_pipe_producer.reset(producer_handle);
    data_pipe_consumer.reset(consumer_handle);
    return rv;
}

// Creates a new data pipe with a specified capacity size. For setting
// additional options, see |CreateDataPipe()| above.
inline MojoResult CreateDataPipe(
    uint32_t capacity_num_bytes, ScopedDataPipeProducerHandle& data_pipe_producer, ScopedDataPipeConsumerHandle& data_pipe_consumer)
{
    MojoCreateDataPipeOptions options;
    options.struct_size = sizeof(MojoCreateDataPipeOptions);
    options.flags = MOJO_CREATE_DATA_PIPE_FLAG_NONE;
    options.element_num_bytes = 1;
    options.capacity_num_bytes = capacity_num_bytes;
    return CreateDataPipe(&options, data_pipe_producer, data_pipe_consumer);
}

} // namespace mojo

#endif // MOJO_PUBLIC_CPP_SYSTEM_DATA_PIPE_H_
