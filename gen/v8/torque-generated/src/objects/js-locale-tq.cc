#include "src/objects/js-locale-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-locale.tq?l=7&c=1
bool IsJSLocale_NonInline(Tagged<HeapObject> o)
{
    return IsJSLocale(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSLocale<JSLocale, JSObject>::JSLocaleVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSLocaleVerify(Cast<JSLocale>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
