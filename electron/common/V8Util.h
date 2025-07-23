#ifndef electron_common_V8Util_h
#define electron_common_V8Util_h

#include "v8.h"
#include "base/containers/span.h"

namespace blink {
struct BlinkTransferableMessage;
struct TransferableMessage;
struct CloneableMessage;
}

namespace atom {

bool serializeV8Value(v8::Isolate* isolate, v8::Local<v8::Value> value, blink::TransferableMessage* out);
v8::Local<v8::Value> deserializeV8Value(v8::Isolate* isolate, const blink::TransferableMessage& in);
v8::Local<v8::Value> deserializeV8Value(v8::Isolate* isolate, base::span<const uint8_t> data);
v8::Local<v8::Value> deserializeV8Value(v8::Local<v8::Context> context, base::span<const uint8_t> data);
v8::Local<v8::Value> deserializeV8Value(v8::Isolate* isolate, const blink::CloneableMessage& in);
bool serializeV8Value(v8::Isolate* isolate, v8::Local<v8::Value> value, blink::CloneableMessage* out);

} // atom

#endif // electron_common_V8Util_h