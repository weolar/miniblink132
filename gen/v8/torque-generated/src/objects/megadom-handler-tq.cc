#include "src/objects/megadom-handler-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/megadom-handler.tq?l=5&c=1
bool IsMegaDomHandler_NonInline(Tagged<HeapObject> o)
{
    return IsMegaDomHandler(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedMegaDomHandler<MegaDomHandler, HeapObject>::MegaDomHandlerVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::MegaDomHandlerVerify(Cast<MegaDomHandler>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
