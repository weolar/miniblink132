#include "src/objects/foreign-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=5&c=1
bool IsForeign_NonInline(Tagged<HeapObject> o)
{
    return IsForeign(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedForeign<Foreign, HeapObject>::ForeignVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::ForeignVerify(Cast<Foreign>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/foreign.tq?l=10&c=1
bool IsTrustedForeign_NonInline(Tagged<HeapObject> o)
{
    return IsTrustedForeign(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedTrustedForeign<TrustedForeign, TrustedObject>::TrustedForeignVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::TrustedForeignVerify(Cast<TrustedForeign>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
