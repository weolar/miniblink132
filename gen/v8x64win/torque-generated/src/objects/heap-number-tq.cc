#include "src/objects/heap-number.h"

namespace v8 {
namespace internal {

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/heap-number.tq?l=5&c=1
class TorqueGeneratedHeapNumberAsserts {
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/heap-number.tq?l=9&c=3
  static constexpr int kValueOffset = sizeof(PrimitiveHeapObject);
  static constexpr int kValueOffsetEnd = kValueOffset + kDoubleSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kValueOffsetEnd + 1;
  static constexpr int kHeaderSize = kValueOffsetEnd + 1;
  static constexpr int kSize = kValueOffsetEnd + 1;

  static_assert(kValueOffset == offsetof(HeapNumber, value_),
                "Value of HeapNumber::kValueOffset defined in Torque and offset of field HeapNumber::value in C++ do not match");
  static_assert(kSize == sizeof(HeapNumber));
};

} // namespace internal
} // namespace v8
