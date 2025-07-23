#include "src/objects/template-objects-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=5&c=1
bool IsTemplateObjectDescription_NonInline(Tagged<HeapObject> o)
{
    return IsTemplateObjectDescription(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedTemplateObjectDescription<TemplateObjectDescription, Struct>::TemplateObjectDescriptionVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::TemplateObjectDescriptionVerify(Cast<TemplateObjectDescription>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
