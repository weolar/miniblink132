#include "src/objects/data-handler-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=7&c=1
bool IsDataHandler_NonInline(Tagged<HeapObject> o) {
  return IsDataHandler(o);
}

#ifdef VERIFY_HEAP

template <>
void TorqueGeneratedDataHandler<DataHandler, Struct>::DataHandlerVerify(Isolate* isolate) {
  TorqueGeneratedClassVerifiers::DataHandlerVerify(Cast<DataHandler>(*this), isolate);
}


#endif  // VERIFY_HEAP
} // namespace internal
} // namespace v8
