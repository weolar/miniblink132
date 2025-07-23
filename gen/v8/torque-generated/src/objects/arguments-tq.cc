#include "src/objects/arguments-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=5&c=1
bool IsJSArgumentsObject_NonInline(Tagged<HeapObject> o)
{
    return IsJSArgumentsObject(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSArgumentsObject<JSArgumentsObject, JSObject>::JSArgumentsObjectVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSArgumentsObjectVerify(Cast<JSArgumentsObject>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=41&c=1
bool IsAliasedArgumentsEntry_NonInline(Tagged<HeapObject> o)
{
    return IsAliasedArgumentsEntry(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedAliasedArgumentsEntry<AliasedArgumentsEntry, Struct>::AliasedArgumentsEntryVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::AliasedArgumentsEntryVerify(Cast<AliasedArgumentsEntry>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
