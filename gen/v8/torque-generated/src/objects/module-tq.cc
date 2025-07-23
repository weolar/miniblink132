#include "src/objects/module-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=5&c=1
bool IsModule_NonInline(Tagged<HeapObject> o)
{
    return IsModule(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedModule<Module, HeapObject>::ModuleVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::ModuleVerify(Cast<Module>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=20&c=1
bool IsJSModuleNamespace_NonInline(Tagged<HeapObject> o)
{
    return IsJSModuleNamespace(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSModuleNamespace<JSModuleNamespace, JSSpecialObject>::JSModuleNamespaceVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSModuleNamespaceVerify(Cast<JSModuleNamespace>(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=24&c=1
bool IsScriptOrModule_NonInline(Tagged<HeapObject> o)
{
    return IsScriptOrModule(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedScriptOrModule<ScriptOrModule, Struct>::ScriptOrModuleVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::ScriptOrModuleVerify(Cast<ScriptOrModule>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
