#include "src/objects/js-collection-iterator-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-collection-iterator.tq?l=5&c=1
bool IsJSCollectionIterator_NonInline(Tagged<HeapObject> o)
{
    return IsJSCollectionIterator(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSCollectionIterator<JSCollectionIterator, JSObject>::JSCollectionIteratorVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSCollectionIteratorVerify(Cast<JSCollectionIterator>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
