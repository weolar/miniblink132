#include "src/objects/feedback-vector-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

#include "src/objects/feedback-vector.h"

namespace v8 {
namespace internal {

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=38&c=1
class TorqueGeneratedClosureFeedbackCellArrayAsserts {
    static constexpr int kStartOfStrongFieldsOffset = sizeof(HeapObjectLayout);
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=40&c=9
    static constexpr int kLengthOffset = sizeof(HeapObjectLayout);
    static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
    static constexpr int kHeaderSize = kLengthOffsetEnd + 1;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=41&c=3
    static constexpr int kObjectsOffset = kLengthOffsetEnd + 1;
    static constexpr int kObjectsOffsetEnd = kObjectsOffset + 0 - 1;
    static constexpr int kEndOfStrongFieldsOffset = kObjectsOffsetEnd + 1;
    static constexpr int kStartOfWeakFieldsOffset = kObjectsOffsetEnd + 1;
    static constexpr int kEndOfWeakFieldsOffset = kObjectsOffsetEnd + 1;

    static_assert(kLengthOffset == offsetof(ClosureFeedbackCellArray, length_),
        "Value of ClosureFeedbackCellArray::kLengthOffset defined in Torque and offset of field ClosureFeedbackCellArray::length in C++ do not match");
    static_assert(kObjectsOffset == OFFSET_OF_DATA_START(ClosureFeedbackCellArray),
        "Value of ClosureFeedbackCellArray::kObjectsOffset defined in Torque and offset of field ClosureFeedbackCellArray::objects in C++ do not match");
};

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=44&c=1
bool IsFeedbackVector_NonInline(Tagged<HeapObject> o)
{
    return IsFeedbackVector(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedFeedbackVector<FeedbackVector, HeapObject>::FeedbackVectorVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::FeedbackVectorVerify(Cast<FeedbackVector>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
