#include "src/objects/js-weak-refs-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=21&c=1
bool IsWeakCell_NonInline(Tagged<HeapObject> o)
{
    return IsWeakCell(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedWeakCell<WeakCell, HeapObject>::WeakCellVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::WeakCellVerify(Cast<WeakCell>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=9&c=1
bool IsJSFinalizationRegistry_NonInline(Tagged<HeapObject> o)
{
    return IsJSFinalizationRegistry(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSFinalizationRegistry<JSFinalizationRegistry, JSObject>::JSFinalizationRegistryVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSFinalizationRegistryVerify(Cast<JSFinalizationRegistry>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=42&c=1
bool IsJSWeakRef_NonInline(Tagged<HeapObject> o)
{
    return IsJSWeakRef(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSWeakRef<JSWeakRef, JSObject>::JSWeakRefVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSWeakRefVerify(Cast<JSWeakRef>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
