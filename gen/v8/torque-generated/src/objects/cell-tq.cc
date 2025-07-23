#include "src/objects/cell-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/cell.tq?l=5&c=1
bool IsCell_NonInline(Tagged<HeapObject> o)
{
    return IsCell(o);
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedCell<Cell, HeapObject>::CellVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::CellVerify(Cast<Cell>(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
