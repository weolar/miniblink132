#include "src/objects/trusted-object.h"

namespace v8 {
namespace internal {

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/trusted-object.tq?l=5&c=1
class TorqueGeneratedTrustedObjectAsserts {
    static constexpr int kStartOfWeakFieldsOffset = HeapObject::kHeaderSize;
    static constexpr int kEndOfWeakFieldsOffset = HeapObject::kHeaderSize;
    static constexpr int kStartOfStrongFieldsOffset = HeapObject::kHeaderSize;
    static constexpr int kEndOfStrongFieldsOffset = HeapObject::kHeaderSize;
    static constexpr int kHeaderSize = HeapObject::kHeaderSize;
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/trusted-object.tq?l=9&c=1
class TorqueGeneratedExposedTrustedObjectAsserts {
    static constexpr int kStartOfWeakFieldsOffset = TrustedObject::kHeaderSize;
    static constexpr int kEndOfWeakFieldsOffset = TrustedObject::kHeaderSize;
    static constexpr int kStartOfStrongFieldsOffset = TrustedObject::kHeaderSize;
    static constexpr int kEndOfStrongFieldsOffset = TrustedObject::kHeaderSize;
    static constexpr int kHeaderSize = TrustedObject::kHeaderSize;
};

} // namespace internal
} // namespace v8
