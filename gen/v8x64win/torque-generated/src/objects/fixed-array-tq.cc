#include "src/objects/fixed-array-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

#include "src/objects/fixed-array.h"

namespace v8 {
namespace internal {

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=5&c=1
class TorqueGeneratedFixedArrayBaseAsserts {
  static constexpr int kStartOfStrongFieldsOffset = sizeof(HeapObjectLayout);
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=8&c=9
  static constexpr int kLengthOffset = sizeof(HeapObjectLayout);
  static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kHeaderSize = kLengthOffsetEnd + 1;

  static_assert(kLengthOffset == offsetof(FixedArrayBase, length_),
                "Value of FixedArrayBase::kLengthOffset defined in Torque and offset of field FixedArrayBase::length in C++ do not match");
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=11&c=1
class TorqueGeneratedFixedArrayAsserts {
  static constexpr int kStartOfStrongFieldsOffset = sizeof(FixedArrayBase);
  static constexpr int kHeaderSize = sizeof(FixedArrayBase);
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=14&c=3
  static constexpr int kObjectsOffset = sizeof(FixedArrayBase);
  static constexpr int kObjectsOffsetEnd = kObjectsOffset + 0 - 1;
  static constexpr int kEndOfStrongFieldsOffset = kObjectsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kObjectsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kObjectsOffsetEnd + 1;

  static_assert(kObjectsOffset == OFFSET_OF_DATA_START(FixedArray),
                "Value of FixedArray::kObjectsOffset defined in Torque and offset of field FixedArray::objects in C++ do not match");
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=36&c=1
class TorqueGeneratedWeakFixedArrayAsserts {
  static constexpr int kStartOfStrongFieldsOffset = sizeof(HeapObjectLayout);
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=38&c=9
  static constexpr int kLengthOffset = sizeof(HeapObjectLayout);
  static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kHeaderSize = kLengthOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=39&c=3
  static constexpr int kObjectsOffset = kLengthOffsetEnd + 1;
  static constexpr int kObjectsOffsetEnd = kObjectsOffset + 0 - 1;
  static constexpr int kEndOfWeakFieldsOffset = kObjectsOffsetEnd + 1;

  static_assert(kLengthOffset == offsetof(WeakFixedArray, length_),
                "Value of WeakFixedArray::kLengthOffset defined in Torque and offset of field WeakFixedArray::length in C++ do not match");
  static_assert(kObjectsOffset == OFFSET_OF_DATA_START(WeakFixedArray),
                "Value of WeakFixedArray::kObjectsOffset defined in Torque and offset of field WeakFixedArray::objects in C++ do not match");
};

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=68&c=1
bool IsWeakArrayList_NonInline(Tagged<HeapObject> o) {
  return IsWeakArrayList(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedWeakArrayList<WeakArrayList, HeapObject>::WeakArrayListVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::WeakArrayListVerify(Cast<WeakArrayList>(*this), isolate);
}


#endif  // VERIFY_HEAP
// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=31&c=1
class TorqueGeneratedFixedDoubleArrayAsserts {
  static constexpr int kHeaderSize = sizeof(FixedArrayBase);
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=33&c=3
  static constexpr int kValuesOffset = sizeof(FixedArrayBase);
  static constexpr int kValuesOffsetEnd = kValuesOffset + 0 - 1;
  static constexpr int kStartOfWeakFieldsOffset = kValuesOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kValuesOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kValuesOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kValuesOffsetEnd + 1;

  static_assert(kValuesOffset == OFFSET_OF_DATA_START(FixedDoubleArray),
                "Value of FixedDoubleArray::kValuesOffset defined in Torque and offset of field FixedDoubleArray::values in C++ do not match");
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=19&c=1
class TorqueGeneratedTrustedFixedArrayAsserts {
  static constexpr int kStartOfStrongFieldsOffset = sizeof(TrustedObjectLayout);
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=21&c=9
  static constexpr int kLengthOffset = sizeof(TrustedObjectLayout);
  static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
  static constexpr int kHeaderSize = kLengthOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=22&c=3
  static constexpr int kObjectsOffset = kLengthOffsetEnd + 1;
  static constexpr int kObjectsOffsetEnd = kObjectsOffset + 0 - 1;
  static constexpr int kEndOfStrongFieldsOffset = kObjectsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kObjectsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kObjectsOffsetEnd + 1;

  static_assert(kLengthOffset == offsetof(TrustedFixedArray, length_),
                "Value of TrustedFixedArray::kLengthOffset defined in Torque and offset of field TrustedFixedArray::length in C++ do not match");
  static_assert(kObjectsOffset == OFFSET_OF_DATA_START(TrustedFixedArray),
                "Value of TrustedFixedArray::kObjectsOffset defined in Torque and offset of field TrustedFixedArray::objects in C++ do not match");
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=25&c=1
class TorqueGeneratedProtectedFixedArrayAsserts {
  static constexpr int kStartOfStrongFieldsOffset = sizeof(TrustedObjectLayout);
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=27&c=9
  static constexpr int kLengthOffset = sizeof(TrustedObjectLayout);
  static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
  static constexpr int kHeaderSize = kLengthOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=28&c=3
  static constexpr int kObjectsOffset = kLengthOffsetEnd + 1;
  static constexpr int kObjectsOffsetEnd = kObjectsOffset + 0 - 1;
  static constexpr int kEndOfStrongFieldsOffset = kObjectsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kObjectsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kObjectsOffsetEnd + 1;

  static_assert(kLengthOffset == offsetof(ProtectedFixedArray, length_),
                "Value of ProtectedFixedArray::kLengthOffset defined in Torque and offset of field ProtectedFixedArray::length in C++ do not match");
  static_assert(kObjectsOffset == OFFSET_OF_DATA_START(ProtectedFixedArray),
                "Value of ProtectedFixedArray::kObjectsOffset defined in Torque and offset of field ProtectedFixedArray::objects in C++ do not match");
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=42&c=1
class TorqueGeneratedTrustedWeakFixedArrayAsserts {
  static constexpr int kStartOfStrongFieldsOffset = sizeof(TrustedObjectLayout);
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=44&c=9
  static constexpr int kLengthOffset = sizeof(TrustedObjectLayout);
  static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kHeaderSize = kLengthOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=45&c=3
  static constexpr int kObjectsOffset = kLengthOffsetEnd + 1;
  static constexpr int kObjectsOffsetEnd = kObjectsOffset + 0 - 1;
  static constexpr int kEndOfWeakFieldsOffset = kObjectsOffsetEnd + 1;

  static_assert(kLengthOffset == offsetof(TrustedWeakFixedArray, length_),
                "Value of TrustedWeakFixedArray::kLengthOffset defined in Torque and offset of field TrustedWeakFixedArray::length in C++ do not match");
  static_assert(kObjectsOffset == OFFSET_OF_DATA_START(TrustedWeakFixedArray),
                "Value of TrustedWeakFixedArray::kObjectsOffset defined in Torque and offset of field TrustedWeakFixedArray::objects in C++ do not match");
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=48&c=1
class TorqueGeneratedByteArrayAsserts {
  static constexpr int kHeaderSize = sizeof(FixedArrayBase);
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=50&c=3
  static constexpr int kValuesOffset = sizeof(FixedArrayBase);
  static constexpr int kValuesOffsetEnd = kValuesOffset + 0 - 1;
  static constexpr int kStartOfWeakFieldsOffset = kValuesOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kValuesOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kValuesOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kValuesOffsetEnd + 1;

  static_assert(kValuesOffset == OFFSET_OF_DATA_START(ByteArray),
                "Value of ByteArray::kValuesOffset defined in Torque and offset of field ByteArray::values in C++ do not match");
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=53&c=1
class TorqueGeneratedTrustedByteArrayAsserts {
  static constexpr int kStartOfStrongFieldsOffset = sizeof(TrustedObjectLayout);
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=55&c=9
  static constexpr int kLengthOffset = sizeof(TrustedObjectLayout);
  static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kHeaderSize = kLengthOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=56&c=3
  static constexpr int kValuesOffset = kLengthOffsetEnd + 1;
  static constexpr int kValuesOffsetEnd = kValuesOffset + 0 - 1;
  static constexpr int kStartOfWeakFieldsOffset = kValuesOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kValuesOffsetEnd + 1;

  static_assert(kLengthOffset == offsetof(TrustedByteArray, length_),
                "Value of TrustedByteArray::kLengthOffset defined in Torque and offset of field TrustedByteArray::length in C++ do not match");
  static_assert(kValuesOffset == OFFSET_OF_DATA_START(TrustedByteArray),
                "Value of TrustedByteArray::kValuesOffset defined in Torque and offset of field TrustedByteArray::values in C++ do not match");
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=61&c=1
class TorqueGeneratedArrayListAsserts {
  static constexpr int kStartOfStrongFieldsOffset = sizeof(HeapObjectLayout);
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=63&c=9
  static constexpr int kCapacityOffset = sizeof(HeapObjectLayout);
  static constexpr int kCapacityOffsetEnd = kCapacityOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=64&c=3
  static constexpr int kLengthOffset = kCapacityOffsetEnd + 1;
  static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
  static constexpr int kHeaderSize = kLengthOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=65&c=3
  static constexpr int kObjectsOffset = kLengthOffsetEnd + 1;
  static constexpr int kObjectsOffsetEnd = kObjectsOffset + 0 - 1;
  static constexpr int kEndOfStrongFieldsOffset = kObjectsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kObjectsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kObjectsOffsetEnd + 1;

  static_assert(kCapacityOffset == offsetof(ArrayList, capacity_),
                "Value of ArrayList::kCapacityOffset defined in Torque and offset of field ArrayList::capacity in C++ do not match");
  static_assert(kLengthOffset == offsetof(ArrayList, length_),
                "Value of ArrayList::kLengthOffset defined in Torque and offset of field ArrayList::length in C++ do not match");
  static_assert(kObjectsOffset == OFFSET_OF_DATA_START(ArrayList),
                "Value of ArrayList::kObjectsOffset defined in Torque and offset of field ArrayList::objects in C++ do not match");
};

} // namespace internal
} // namespace v8
