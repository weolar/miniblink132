#include "src/objects/bytecode-array.h"

namespace v8 {
namespace internal {

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=7&c=1
class TorqueGeneratedBytecodeArrayAsserts {
  static constexpr int kStartOfStrongFieldsOffset = ExposedTrustedObject::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=9&c=9
  static constexpr int kLengthOffset = ExposedTrustedObject::kHeaderSize;
  static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=10&c=3
  static constexpr int kWrapperOffset = kLengthOffsetEnd + 1;
  static constexpr int kWrapperOffsetEnd = kWrapperOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kWrapperOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kWrapperOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=11&c=3
  static constexpr int kSourcePositionTableOffset = kWrapperOffsetEnd + 1;
  static constexpr int kSourcePositionTableOffsetEnd = kSourcePositionTableOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=12&c=3
  static constexpr int kHandlerTableOffset = kSourcePositionTableOffsetEnd + 1;
  static constexpr int kHandlerTableOffsetEnd = kHandlerTableOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=13&c=3
  static constexpr int kConstantPoolOffset = kHandlerTableOffsetEnd + 1;
  static constexpr int kConstantPoolOffsetEnd = kConstantPoolOffset + kTaggedSize - 1;
  static constexpr int kEndOfWeakFieldsOffset = kConstantPoolOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=14&c=3
  static constexpr int kFrameSizeOffset = kConstantPoolOffsetEnd + 1;
  static constexpr int kFrameSizeOffsetEnd = kFrameSizeOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=15&c=3
  static constexpr int kParameterSizeOffset = kFrameSizeOffsetEnd + 1;
  static constexpr int kParameterSizeOffsetEnd = kParameterSizeOffset + kUInt16Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=16&c=3
  static constexpr int kMaxArgumentsOffset = kParameterSizeOffsetEnd + 1;
  static constexpr int kMaxArgumentsOffsetEnd = kMaxArgumentsOffset + kUInt16Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=17&c=3
  static constexpr int kIncomingNewTargetOrGeneratorRegisterOffset = kMaxArgumentsOffsetEnd + 1;
  static constexpr int kIncomingNewTargetOrGeneratorRegisterOffsetEnd = kIncomingNewTargetOrGeneratorRegisterOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=19&c=31
  static constexpr int kOptionalPaddingOffset = kIncomingNewTargetOrGeneratorRegisterOffsetEnd + 1;
  static constexpr int kOptionalPaddingOffsetEnd = kOptionalPaddingOffset + 0 - 1;
  static constexpr int kHeaderSize = kOptionalPaddingOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=20&c=3
  static constexpr int kBytesOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kBytesOffsetEnd = kBytesOffset + 0 - 1;

  static_assert(kLengthOffset == BytecodeArray::kLengthOffset,
                "Values of BytecodeArray::kLengthOffset defined in Torque and C++ do not match");
  static_assert(kWrapperOffset == BytecodeArray::kWrapperOffset,
                "Values of BytecodeArray::kWrapperOffset defined in Torque and C++ do not match");
  static_assert(kSourcePositionTableOffset == BytecodeArray::kSourcePositionTableOffset,
                "Values of BytecodeArray::kSourcePositionTableOffset defined in Torque and C++ do not match");
  static_assert(kHandlerTableOffset == BytecodeArray::kHandlerTableOffset,
                "Values of BytecodeArray::kHandlerTableOffset defined in Torque and C++ do not match");
  static_assert(kConstantPoolOffset == BytecodeArray::kConstantPoolOffset,
                "Values of BytecodeArray::kConstantPoolOffset defined in Torque and C++ do not match");
  static_assert(kFrameSizeOffset == BytecodeArray::kFrameSizeOffset,
                "Values of BytecodeArray::kFrameSizeOffset defined in Torque and C++ do not match");
  static_assert(kParameterSizeOffset == BytecodeArray::kParameterSizeOffset,
                "Values of BytecodeArray::kParameterSizeOffset defined in Torque and C++ do not match");
  static_assert(kMaxArgumentsOffset == BytecodeArray::kMaxArgumentsOffset,
                "Values of BytecodeArray::kMaxArgumentsOffset defined in Torque and C++ do not match");
  static_assert(kIncomingNewTargetOrGeneratorRegisterOffset == BytecodeArray::kIncomingNewTargetOrGeneratorRegisterOffset,
                "Values of BytecodeArray::kIncomingNewTargetOrGeneratorRegisterOffset defined in Torque and C++ do not match");
  static_assert(kOptionalPaddingOffset == BytecodeArray::kOptionalPaddingOffset,
                "Values of BytecodeArray::kOptionalPaddingOffset defined in Torque and C++ do not match");
  static_assert(kBytesOffset == BytecodeArray::kBytesOffset,
                "Values of BytecodeArray::kBytesOffset defined in Torque and C++ do not match");
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=26&c=1
class TorqueGeneratedBytecodeWrapperAsserts {
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=28&c=3
  static constexpr int kBytecodeOffset = Struct::kHeaderSize;
  static constexpr int kBytecodeOffsetEnd = kBytecodeOffset + kTrustedPointerSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kBytecodeOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kBytecodeOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kBytecodeOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kBytecodeOffsetEnd + 1;
  static constexpr int kHeaderSize = kBytecodeOffsetEnd + 1;
  static constexpr int kSize = kBytecodeOffsetEnd + 1;

  static_assert(kBytecodeOffset == BytecodeWrapper::kBytecodeOffset,
                "Values of BytecodeWrapper::kBytecodeOffset defined in Torque and C++ do not match");
  static_assert(kSize == BytecodeWrapper::kSize);
};

} // namespace internal
} // namespace v8
