#include "src/objects/name.h"

namespace v8 {
namespace internal {

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/name.tq?l=5&c=1
class TorqueGeneratedNameAsserts {
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/name.tq?l=8&c=3
  static constexpr int kRawHashFieldOffset = sizeof(PrimitiveHeapObject);
  static constexpr int kRawHashFieldOffsetEnd = kRawHashFieldOffset + kInt32Size - 1;
  static constexpr int kStartOfWeakFieldsOffset = kRawHashFieldOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kRawHashFieldOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kRawHashFieldOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kRawHashFieldOffsetEnd + 1;
  static constexpr int kHeaderSize = kRawHashFieldOffsetEnd + 1;

  static_assert(kRawHashFieldOffset == offsetof(Name, raw_hash_field_),
                "Value of Name::kRawHashFieldOffset defined in Torque and offset of field Name::raw_hash_field in C++ do not match");
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/name.tq?l=30&c=1
class TorqueGeneratedSymbolAsserts {
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/name.tq?l=32&c=3
  static constexpr int kFlagsOffset = sizeof(Name);
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kInt32Size - 1;
  static constexpr int kStartOfStrongFieldsOffset = kFlagsOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/name.tq?l=33&c=3
  static constexpr int kDescriptionOffset = kFlagsOffsetEnd + 1;
  static constexpr int kDescriptionOffsetEnd = kDescriptionOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kDescriptionOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kDescriptionOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kDescriptionOffsetEnd + 1;
  static constexpr int kHeaderSize = kDescriptionOffsetEnd + 1;
  static constexpr int kSize = kDescriptionOffsetEnd + 1;

  static_assert(kFlagsOffset == offsetof(Symbol, flags_),
                "Value of Symbol::kFlagsOffset defined in Torque and offset of field Symbol::flags in C++ do not match");
  static_assert(kDescriptionOffset == offsetof(Symbol, description_),
                "Value of Symbol::kDescriptionOffset defined in Torque and offset of field Symbol::description in C++ do not match");
  static_assert(kSize == sizeof(Symbol));
};

} // namespace internal
} // namespace v8
