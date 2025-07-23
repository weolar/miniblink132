#include "src/objects/hole.h"

namespace v8 {
namespace internal {

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/hole.tq?l=5&c=1
class TorqueGeneratedHoleAsserts {
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/hole.tq?l=7&c=3
    static constexpr int kRawNumericValueOffset = HeapObject::kHeaderSize;
    static constexpr int kRawNumericValueOffsetEnd = kRawNumericValueOffset + kDoubleSize - 1;
    static constexpr int kStartOfWeakFieldsOffset = kRawNumericValueOffsetEnd + 1;
    static constexpr int kEndOfWeakFieldsOffset = kRawNumericValueOffsetEnd + 1;
    static constexpr int kStartOfStrongFieldsOffset = kRawNumericValueOffsetEnd + 1;
    static constexpr int kEndOfStrongFieldsOffset = kRawNumericValueOffsetEnd + 1;
    static constexpr int kHeaderSize = kRawNumericValueOffsetEnd + 1;
    static constexpr int kSize = kRawNumericValueOffsetEnd + 1;

    static_assert(kRawNumericValueOffset == Hole::kRawNumericValueOffset, "Values of Hole::kRawNumericValueOffset defined in Torque and C++ do not match");
    static_assert(kSize == Hole::kSize);
};

} // namespace internal
} // namespace v8
