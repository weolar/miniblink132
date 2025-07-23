#include "src/objects/api-callbacks-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=13&c=1
bool IsInterceptorInfo_NonInline(Tagged<HeapObject> o)
{
    return IsInterceptorInfo(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedInterceptorInfo<InterceptorInfo, Struct>::InterceptorInfoVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::InterceptorInfoVerify(Cast<InterceptorInfo>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=25&c=1
bool IsAccessCheckInfo_NonInline(Tagged<HeapObject> o)
{
    return IsAccessCheckInfo(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedAccessCheckInfo<AccessCheckInfo, Struct>::AccessCheckInfoVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::AccessCheckInfoVerify(Cast<AccessCheckInfo>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=42&c=1
bool IsAccessorInfo_NonInline(Tagged<HeapObject> o)
{
    return IsAccessorInfo(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedAccessorInfo<AccessorInfo, HeapObject>::AccessorInfoVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::AccessorInfoVerify(Cast<AccessorInfo>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
