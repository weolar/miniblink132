#include "src/objects/struct-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=5&c=1
bool IsStruct_NonInline(Tagged<HeapObject> o) {
  return IsStruct(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedStruct<Struct, HeapObject>::StructVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::StructVerify(Cast<Struct>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=13&c=1
bool IsClassPositions_NonInline(Tagged<HeapObject> o) {
  return IsClassPositions(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedClassPositions<ClassPositions, Struct>::ClassPositionsVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::ClassPositionsVerify(Cast<ClassPositions>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=18&c=1
bool IsAccessorPair_NonInline(Tagged<HeapObject> o) {
  return IsAccessorPair(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedAccessorPair<AccessorPair, Struct>::AccessorPairVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::AccessorPairVerify(Cast<AccessorPair>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/struct.tq?l=8&c=1
bool IsTuple2_NonInline(Tagged<HeapObject> o) {
  return IsTuple2(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedTuple2<Tuple2, Struct>::Tuple2Verify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::Tuple2Verify(Cast<Tuple2>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
