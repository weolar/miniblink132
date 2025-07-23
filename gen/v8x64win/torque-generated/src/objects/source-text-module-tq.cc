#include "src/objects/source-text-module-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=12&c=1
bool IsSourceTextModule_NonInline(Tagged<HeapObject> o) {
  return IsSourceTextModule(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedSourceTextModule<SourceTextModule, Module>::SourceTextModuleVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::SourceTextModuleVerify(Cast<SourceTextModule>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=58&c=1
bool IsModuleRequest_NonInline(Tagged<HeapObject> o) {
  return IsModuleRequest(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedModuleRequest<ModuleRequest, Struct>::ModuleRequestVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::ModuleRequestVerify(Cast<ModuleRequest>(*this), isolate);
}


#endif  // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=68&c=1
bool IsSourceTextModuleInfoEntry_NonInline(Tagged<HeapObject> o) {
  return IsSourceTextModuleInfoEntry(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedSourceTextModuleInfoEntry<SourceTextModuleInfoEntry, Struct>::SourceTextModuleInfoEntryVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::SourceTextModuleInfoEntryVerify(Cast<SourceTextModuleInfoEntry>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
