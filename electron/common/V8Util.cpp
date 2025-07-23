
#include "electron/common/V8Util.h"

#include "electron/common/gin_helper/microtasks_scope.h"
#include "electron/common/gin_helper/converter.h"
#include "third_party/blink/public/common/messaging/web_message_port.h"
#include "third_party/blink/renderer/core/messaging/blink_transferable_message.h"

namespace atom {

namespace {

const uint8_t kNativeImageTag = 'i';
const uint8_t kTrailerOffsetTag = 0xFE;
const uint8_t kVersionTag = 0xFF;

} // namespace

class V8Serializer : public v8::ValueSerializer::Delegate {
public:
    explicit V8Serializer(v8::Isolate* isolate)
        : m_isolate(isolate)
        , m_serializer(isolate, this)
    {
    }
    ~V8Serializer() override = default;

    bool Serialize(v8::Local<v8::Value> value, blink::CloneableMessage* out)
    {
        gin_helper::MicrotasksScope microtasks_scope(m_isolate, false, v8::MicrotasksScope::kDoNotRunMicrotasks);
        WriteBlinkEnvelope(19);

        m_serializer.WriteHeader();
        bool wrote_value;
        if (!m_serializer.WriteValue(m_isolate->GetCurrentContext(), value).To(&wrote_value)) {
            m_isolate->ThrowException(v8::Exception::Error(gin_helper::StringToV8(m_isolate, "An object could not be cloned.")));
            return false;
        }
        DCHECK(wrote_value);

        std::pair<uint8_t*, size_t> serializerVal = m_serializer.Release();
        uint8_t* data_bytes = serializerVal.first;
        size_t data_len = serializerVal.second;

        DCHECK_EQ(std::data(m_data), data_bytes);
        DCHECK_GE(std::size(m_data), data_len);
        m_data.resize(data_len);
        out->owned_encoded_message = std::move(m_data);
        out->encoded_message = out->owned_encoded_message;
        return true;
    }

    bool Serialize(v8::Local<v8::Value> value, blink::TransferableMessage* out)
    {
        gin_helper::MicrotasksScope microtasks_scope(m_isolate, false, v8::MicrotasksScope::kDoNotRunMicrotasks);
        WriteBlinkEnvelope(19);

        m_serializer.WriteHeader();
        bool wrote_value;
        if (!m_serializer.WriteValue(m_isolate->GetCurrentContext(), value).To(&wrote_value)) {
            m_isolate->ThrowException(v8::Exception::Error(gin_helper::StringToV8(m_isolate, "An object could not be cloned.")));
            return false;
        }
        DCHECK(wrote_value);

        std::pair<uint8_t*, size_t> serializerVal = m_serializer.Release();
        uint8_t* data_bytes = serializerVal.first;
        size_t data_len = serializerVal.second;

        DCHECK_EQ(std::data(m_data), data_bytes);
        DCHECK_GE(std::size(m_data), data_len);
        m_data.resize(data_len);
        out->owned_encoded_message = std::move(m_data);
        out->encoded_message = out->owned_encoded_message;
        out->sender_agent_cluster_id = blink::WebMessagePort::GetEmbedderAgentClusterID();

        return true;
    }

    // v8::ValueSerializer::Delegate
    void* ReallocateBufferMemory(void* old_buffer, size_t size, size_t* actual_size) override
    {
        DCHECK_EQ(old_buffer, m_data.data());
        m_data.resize(size);
        *actual_size = m_data.capacity();
        return m_data.data();
    }

    void FreeBufferMemory(void* buffer) override
    {
        DCHECK_EQ(buffer, m_data.data());
        m_data = {};
    }

    v8::Maybe<bool> WriteHostObject(v8::Isolate* isolate, v8::Local<v8::Object> object) override
    {
        //api::NativeImage* native_image;
        if (false /*gin_helper::ConvertFromV8(isolate, object, &native_image)*/) {
            //             // Serialize the NativeImage
            //             WriteTag(kNativeImageTag);
            //             gfx::ImageSkia image = native_image->image().AsImageSkia();
            //             std::vector<gfx::ImageSkiaRep> image_reps = image.image_reps();
            //             m_serializer.WriteUint32(image_reps.size());
            //             for (const auto& rep : image_reps) {
            //                 m_serializer.WriteDouble(rep.scale());
            //                 const SkBitmap& bitmap = rep.GetBitmap();
            //                 std::vector<uint8_t> bytes =
            //                     skia::mojom::InlineBitmap::Serialize(&bitmap);
            //                 m_serializer.WriteUint32(bytes.size());
            //                 m_serializer.WriteRawBytes(bytes.data(), bytes.size());
            //             }
            //             return v8::Just(true);
        } else {
            return v8::ValueSerializer::Delegate::WriteHostObject(isolate, object);
        }
    }

    void ThrowDataCloneError(v8::Local<v8::String> message) override
    {
        m_isolate->ThrowException(v8::Exception::Error(message));
    }

private:
    void WriteTag(const uint8_t tag)
    {
        m_serializer.WriteRawBytes(&tag, 1U);
    }

    void WriteBlinkEnvelope(uint32_t blink_version)
    {
        // Write a dummy blink version envelope for compatibility with
        // blink::V8ScriptValueSerializer
        WriteTag(kVersionTag);
        m_serializer.WriteUint32(blink_version);
    }

    raw_ptr<v8::Isolate> m_isolate;
    std::vector<uint8_t> m_data;
    v8::ValueSerializer m_serializer;
};

class V8Deserializer : public v8::ValueDeserializer::Delegate {
public:
    V8Deserializer(v8::Isolate* isolate, base::span<const uint8_t> data)
        : m_isolate(isolate)
        , m_deserializer(isolate, data.data(), data.size(), this)
        , m_context(isolate->GetCurrentContext())
    {
    }

    V8Deserializer(v8::Isolate* isolate, const blink::CloneableMessage& message)
        : V8Deserializer(isolate, message.encoded_message)
    {
    }

    V8Deserializer(v8::Local<v8::Context> context, base::span<const uint8_t> data)
        : V8Deserializer(context->GetIsolate(), data)
    {
        m_context = (context);
    }

    v8::Local<v8::Value> Deserialize()
    {
        v8::EscapableHandleScope scope(m_isolate);

        uint32_t blinkVersion;
        if (!ReadBlinkEnvelope(&blinkVersion))
            return v8::Null(m_isolate);

        bool readHeader;
        if (!m_deserializer.ReadHeader(m_context).To(&readHeader))
            return v8::Null(m_isolate);
        DCHECK(readHeader);
        v8::Local<v8::Value> value;
        if (!m_deserializer.ReadValue(m_context).ToLocal(&value))
            return v8::Null(m_isolate);
        return scope.Escape(value);
    }

    v8::MaybeLocal<v8::Object> ReadHostObject(v8::Isolate* isolate) override
    {
        uint8_t tag = 0;
        if (!ReadTag(&tag))
            return v8::ValueDeserializer::Delegate::ReadHostObject(isolate);
        switch (tag) {
        case kNativeImageTag:
            //             if (api::NativeImage* native_image = ReadNativeImage(isolate))
            //                 return native_image->GetWrapper(isolate);
            break;
        }
        // Throws an exception.
        return v8::ValueDeserializer::Delegate::ReadHostObject(isolate);
    }

private:
    bool ReadTag(uint8_t* tag)
    {
        const void* tag_bytes = nullptr;
        if (!m_deserializer.ReadRawBytes(1, &tag_bytes))
            return false;
        *tag = *reinterpret_cast<const uint8_t*>(tag_bytes);
        return true;
    }

    bool ReadBlinkEnvelope(uint32_t* blink_version)
    {
        // Read a dummy blink version envelope for compatibility with
        // blink::V8ScriptValueDeserializer
        uint8_t tag = 0;
        if (!ReadTag(&tag) || tag != kVersionTag)
            return false;
        if (!m_deserializer.ReadUint32(blink_version))
            return false;
        static constexpr uint32_t kMinWireFormatVersionWithTrailer = 21;
        if (*blink_version >= kMinWireFormatVersionWithTrailer) {
            // In these versions, we expect kTrailerOffsetTag (0xFE) followed by an
            // offset and size. See details in
            // third_party/blink/renderer/core/v8/serialization/serialization_tag.h.
            uint8_t trailer_offset_tag = 0;
            if (!ReadTag(&trailer_offset_tag) || trailer_offset_tag != kTrailerOffsetTag)
                return false;
            const void* trailer_offset_and_size_bytes = nullptr;
            static constexpr size_t kTrailerOffsetDataSize = sizeof(uint64_t) + sizeof(uint32_t);
            if (!m_deserializer.ReadRawBytes(kTrailerOffsetDataSize, &trailer_offset_and_size_bytes))
                return false;
        }

        return true;
    }

    //     api::NativeImage* ReadNativeImage(v8::Isolate* isolate) {
    //         gfx::ImageSkia image_skia;
    //         uint32_t num_reps = 0;
    //         if (!m_deserializer.ReadUint32(&num_reps))
    //             return nullptr;
    //         for (uint32_t i = 0; i < num_reps; i++) {
    //             double scale = 0.0;
    //             if (!m_deserializer.ReadDouble(&scale))
    //                 return nullptr;
    //             uint32_t bitmap_size_bytes = 0;
    //             if (!m_deserializer.ReadUint32(&bitmap_size_bytes))
    //                 return nullptr;
    //             const void* bitmap_data = nullptr;
    //             if (!m_deserializer.ReadRawBytes(bitmap_size_bytes, &bitmap_data))
    //                 return nullptr;
    //             SkBitmap bitmap;
    //             if (!skia::mojom::InlineBitmap::Deserialize(bitmap_data,
    //                 bitmap_size_bytes, &bitmap))
    //                 return nullptr;
    //             image_skia.AddRepresentation(gfx::ImageSkiaRep(bitmap, scale));
    //         }
    //         gfx::Image image(image_skia);
    //         return new api::NativeImage(isolate, image);
    //     }

    raw_ptr<v8::Isolate> m_isolate;
    v8::ValueDeserializer m_deserializer;
    v8::Local<v8::Context> m_context;
};

//---

bool serializeV8Value(v8::Isolate* isolate, v8::Local<v8::Value> value, blink::TransferableMessage* out)
{
    return V8Serializer(isolate).Serialize(value, out);

    //     blink::ScriptValue scriptValue(isolate, value);
    //     blink::StructuredSerializeOptions options;
    //     scoped_refptr<SerializedScriptValue> PostMessageHelper::SerializeMessageByMove(isolate,
    //         scriptValue, &options, Transferables & transferables, ExceptionState & exception_state)
}

v8::Local<v8::Value> deserializeV8Value(v8::Isolate* isolate, const blink::TransferableMessage& in)
{
    return V8Deserializer(isolate, in).Deserialize();
}

v8::Local<v8::Value> deserializeV8Value(v8::Isolate* isolate, base::span<const uint8_t> data)
{
    return V8Deserializer(isolate, data).Deserialize();
}

v8::Local<v8::Value> deserializeV8Value(v8::Isolate* isolate, const blink::CloneableMessage& in)
{
    return V8Deserializer(isolate, in).Deserialize();
}

v8::Local<v8::Value> deserializeV8Value(v8::Local<v8::Context> context, base::span<const uint8_t> data)
{
    return V8Deserializer(context, data).Deserialize();
}

bool serializeV8Value(v8::Isolate* isolate, v8::Local<v8::Value> value, blink::CloneableMessage* out)
{
    return V8Serializer(isolate).Serialize(value, out);
}

}