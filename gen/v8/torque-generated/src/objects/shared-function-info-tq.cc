#include "src/objects/shared-function-info-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

#include "src/objects/shared-function-info.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=7&c=1
bool IsPreparseData_NonInline(Tagged<HeapObject> o)
{
    return IsPreparseData(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedPreparseData<PreparseData, HeapObject>::PreparseDataVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::PreparseDataVerify(Cast<PreparseData>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=13&c=1
bool IsInterpreterData_NonInline(Tagged<HeapObject> o)
{
    return IsInterpreterData(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedInterpreterData<InterpreterData, ExposedTrustedObject>::InterpreterDataVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::InterpreterDataVerify(Cast<InterpreterData>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=57&c=1
bool IsSharedFunctionInfo_NonInline(Tagged<HeapObject> o)
{
    return IsSharedFunctionInfo(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedSharedFunctionInfo<SharedFunctionInfo, HeapObject>::SharedFunctionInfoVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::SharedFunctionInfoVerify(Cast<SharedFunctionInfo>(*this), isolate);
}

#endif // VERIFY_HEAP
// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=110&c=1
class TorqueGeneratedSharedFunctionInfoWrapperAsserts {
    static constexpr int kStartOfStrongFieldsOffset = TrustedObject::kHeaderSize;
    // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=112&c=3
    static constexpr int kSharedInfoOffset = TrustedObject::kHeaderSize;
    static constexpr int kSharedInfoOffsetEnd = kSharedInfoOffset + kTaggedSize - 1;
    static constexpr int kEndOfStrongFieldsOffset = kSharedInfoOffsetEnd + 1;
    static constexpr int kStartOfWeakFieldsOffset = kSharedInfoOffsetEnd + 1;
    static constexpr int kEndOfWeakFieldsOffset = kSharedInfoOffsetEnd + 1;
    static constexpr int kHeaderSize = kSharedInfoOffsetEnd + 1;
    static constexpr int kSize = kSharedInfoOffsetEnd + 1;

    static_assert(kSharedInfoOffset == SharedFunctionInfoWrapper::kSharedInfoOffset,
        "Values of SharedFunctionInfoWrapper::kSharedInfoOffset defined in Torque and C++ do not match");
    static_assert(kSize == SharedFunctionInfoWrapper::kSize);
};

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=141&c=1
bool IsUncompiledData_NonInline(Tagged<HeapObject> o)
{
    return IsUncompiledData(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedUncompiledData<UncompiledData, ExposedTrustedObject>::UncompiledDataVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::UncompiledDataVerify(Cast<UncompiledData>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=148&c=1
bool IsUncompiledDataWithoutPreparseData_NonInline(Tagged<HeapObject> o)
{
    return IsUncompiledDataWithoutPreparseData(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedUncompiledDataWithoutPreparseData<UncompiledDataWithoutPreparseData, UncompiledData>::UncompiledDataWithoutPreparseDataVerify(
    Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::UncompiledDataWithoutPreparseDataVerify(Cast<UncompiledDataWithoutPreparseData>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=152&c=1
bool IsUncompiledDataWithPreparseData_NonInline(Tagged<HeapObject> o)
{
    return IsUncompiledDataWithPreparseData(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedUncompiledDataWithPreparseData<UncompiledDataWithPreparseData, UncompiledData>::UncompiledDataWithPreparseDataVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::UncompiledDataWithPreparseDataVerify(Cast<UncompiledDataWithPreparseData>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=158&c=1
bool IsUncompiledDataWithoutPreparseDataWithJob_NonInline(Tagged<HeapObject> o)
{
    return IsUncompiledDataWithoutPreparseDataWithJob(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedUncompiledDataWithoutPreparseDataWithJob<UncompiledDataWithoutPreparseDataWithJob,
    UncompiledDataWithoutPreparseData>::UncompiledDataWithoutPreparseDataWithJobVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::UncompiledDataWithoutPreparseDataWithJobVerify(Cast<UncompiledDataWithoutPreparseDataWithJob>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=165&c=1
bool IsUncompiledDataWithPreparseDataAndJob_NonInline(Tagged<HeapObject> o)
{
    return IsUncompiledDataWithPreparseDataAndJob(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedUncompiledDataWithPreparseDataAndJob<UncompiledDataWithPreparseDataAndJob,
    UncompiledDataWithPreparseData>::UncompiledDataWithPreparseDataAndJobVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::UncompiledDataWithPreparseDataAndJobVerify(Cast<UncompiledDataWithPreparseDataAndJob>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/shared-function-info.tq?l=182&c=1
bool IsOnHeapBasicBlockProfilerData_NonInline(Tagged<HeapObject> o)
{
    return IsOnHeapBasicBlockProfilerData(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedOnHeapBasicBlockProfilerData<OnHeapBasicBlockProfilerData, HeapObject>::OnHeapBasicBlockProfilerDataVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::OnHeapBasicBlockProfilerDataVerify(Cast<OnHeapBasicBlockProfilerData>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
