#include "src/ast/ast.h"
#include "src/builtins/builtins-array-gen.h"
#include "src/builtins/builtins-bigint-gen.h"
#include "src/builtins/builtins-call-gen.h"
#include "src/builtins/builtins-collections-gen.h"
#include "src/builtins/builtins-constructor-gen.h"
#include "src/builtins/builtins-data-view-gen.h"
#include "src/builtins/builtins-iterator-gen.h"
#include "src/builtins/builtins-object-gen.h"
#include "src/builtins/builtins-promise-gen.h"
#include "src/builtins/builtins-promise.h"
#include "src/builtins/builtins-proxy-gen.h"
#include "src/builtins/builtins-regexp-gen.h"
#include "src/builtins/builtins-string-gen.h"
#include "src/builtins/builtins-typed-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins-wasm-gen.h"
#include "src/builtins/builtins.h"
#include "src/codegen/code-factory.h"
#include "src/debug/debug-wasm-objects.h"
#include "src/heap/factory-inl.h"
#include "src/ic/binary-op-assembler.h"
#include "src/ic/handler-configuration-inl.h"
#include "src/objects/arguments.h"
#include "src/objects/bigint.h"
#include "src/objects/call-site-info.h"
#include "src/objects/elements-kind.h"
#include "src/objects/free-space.h"
#include "src/objects/intl-objects.h"
#include "src/objects/js-atomics-synchronization.h"
#include "src/objects/js-break-iterator.h"
#include "src/objects/js-collator.h"
#include "src/objects/js-date-time-format.h"
#include "src/objects/js-display-names.h"
#include "src/objects/js-disposable-stack.h"
#include "src/objects/js-duration-format.h"
#include "src/objects/js-function.h"
#include "src/objects/js-generator.h"
#include "src/objects/js-iterator-helpers.h"
#include "src/objects/js-list-format.h"
#include "src/objects/js-locale.h"
#include "src/objects/js-number-format.h"
#include "src/objects/js-objects.h"
#include "src/objects/js-plural-rules.h"
#include "src/objects/js-promise.h"
#include "src/objects/js-raw-json.h"
#include "src/objects/js-regexp-string-iterator.h"
#include "src/objects/js-relative-time-format.h"
#include "src/objects/js-segment-iterator-inl.h"
#include "src/objects/js-segmenter.h"
#include "src/objects/js-segments.h"
#include "src/objects/js-shadow-realm.h"
#include "src/objects/js-shared-array.h"
#include "src/objects/js-struct.h"
#include "src/objects/js-temporal-objects.h"
#include "src/objects/js-weak-refs.h"
#include "src/objects/objects.h"
#include "src/objects/ordered-hash-table.h"
#include "src/objects/property-array.h"
#include "src/objects/property-descriptor-object.h"
#include "src/objects/source-text-module.h"
#include "src/objects/swiss-hash-table-helpers.h"
#include "src/objects/swiss-name-dictionary.h"
#include "src/objects/synthetic-module.h"
#include "src/objects/template-objects.h"
#include "src/objects/torque-defined-classes.h"
#include "src/objects/turbofan-types.h"
#include "src/objects/turboshaft-types.h"
#include "src/torque/runtime-support.h"
#include "src/wasm/value-type.h"
#include "src/wasm/wasm-linkage.h"
#include "src/wasm/wasm-module.h"
#include "src/codegen/code-stub-assembler-inl.h"
// Required Builtins:
#include "torque-generated/src/wasm/wasm-objects-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"
#include "torque-generated/src/builtins/wasm-tq-csa.h"
#include "torque-generated/src/wasm/wasm-objects-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=22&c=1
TNode<Uint8T> FromConstexpr_AddressType_constexpr_kI32_0(compiler::CodeAssemblerState* state_, wasm::AddressType p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint8T> tmp0;
    TNode<Uint8T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = TNode<Uint8T>::UncheckedCast(ca_.Uint32Constant(CastToUnderlyingTypeIfEnum(p_o)));
        tmp1 = (TNode<Uint8T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint8T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=22&c=1
TNode<Uint8T> FromConstexpr_AddressType_constexpr_kI64_0(compiler::CodeAssemblerState* state_, wasm::AddressType p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint8T> tmp0;
    TNode<Uint8T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = TNode<Uint8T>::UncheckedCast(ca_.Uint32Constant(CastToUnderlyingTypeIfEnum(p_o)));
        tmp1 = (TNode<Uint8T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint8T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=31&c=1
TNode<WasmTrustedInstanceData> Cast_WasmTrustedInstanceData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmTrustedInstanceData_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmTrustedInstanceData> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=33&c=1
TNode<WasmInstanceObject> Cast_WasmInstanceObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmInstanceObject> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmInstanceObject_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmInstanceObject> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=43&c=1
TNode<WasmImportData> Cast_WasmImportData_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmImportData> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmImportData_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmImportData> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=66&c=1
TNode<WasmFastApiCallData> Cast_WasmFastApiCallData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmFastApiCallData> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmFastApiCallData_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmFastApiCallData> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=74&c=1
TNode<WasmInternalFunction> Cast_WasmInternalFunction_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmInternalFunction> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmInternalFunction_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmInternalFunction> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=109&c=1
TNode<WasmFuncRef> Cast_WasmFuncRef_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmFuncRef> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmFuncRef_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmFuncRef> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=118&c=1
TNode<WasmFunctionData> Cast_WasmFunctionData_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmFunctionData> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmFunctionData_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmFunctionData> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=134&c=1
TNode<WasmExportedFunctionData> Cast_WasmExportedFunctionData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmExportedFunctionData> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmExportedFunctionData_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmExportedFunctionData> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=157&c=1
TNode<WasmJSFunctionData> Cast_WasmJSFunctionData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmJSFunctionData> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmJSFunctionData_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmJSFunctionData> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=163&c=1
TNode<WasmCapiFunctionData> Cast_WasmCapiFunctionData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmCapiFunctionData> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmCapiFunctionData_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmCapiFunctionData> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=170&c=1
TNode<WasmResumeData> Cast_WasmResumeData_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmResumeData> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmResumeData_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmResumeData> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=175&c=1
TNode<WasmContinuationObject> Cast_WasmContinuationObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmContinuationObject> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmContinuationObject_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmContinuationObject> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=181&c=1
TNode<WasmSuspenderObject> Cast_WasmSuspenderObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmSuspenderObject> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmSuspenderObject_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmSuspenderObject> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=190&c=1
TNode<WasmExceptionTag> Cast_WasmExceptionTag_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmExceptionTag> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmExceptionTag_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmExceptionTag> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=197&c=1
TNode<WasmExceptionPackage> Cast_WasmExceptionPackage_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmExceptionPackage> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmExceptionPackage_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmExceptionPackage> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=199&c=1
TNode<WasmModuleObject> Cast_WasmModuleObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmModuleObject> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmModuleObject_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmModuleObject> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=204&c=1
TNode<WasmDispatchTable> Cast_WasmDispatchTable_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmDispatchTable> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmDispatchTable_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmDispatchTable> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=206&c=1
TNode<WasmTableObject> Cast_WasmTableObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTableObject> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmTableObject_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmTableObject> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=237&c=1
TNode<WasmMemoryObject> Cast_WasmMemoryObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmMemoryObject> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmMemoryObject_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmMemoryObject> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=248&c=1
TNode<WasmGlobalObject> Cast_WasmGlobalObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmGlobalObject> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmGlobalObject_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmGlobalObject> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=262&c=1
TNode<WasmTagObject> Cast_WasmTagObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTagObject> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmTagObject_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmTagObject> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=271&c=1
TNode<AsmWasmData> Cast_AsmWasmData_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<AsmWasmData> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_AsmWasmData_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<AsmWasmData> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=276&c=1
TNode<WasmTypeInfo> Cast_WasmTypeInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTypeInfo> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmTypeInfo_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmTypeInfo> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=299&c=1
TNode<WasmObject> Cast_WasmObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmObject> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmObject_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmObject> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=302&c=1
TNode<WasmStruct> Cast_WasmStruct_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmStruct> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmStruct_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmStruct> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=305&c=1
TNode<WasmArray> Cast_WasmArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmArray> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmArray_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmArray> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=313&c=1
TNode<WasmStringViewIter> Cast_WasmStringViewIter_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmStringViewIter> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmStringViewIter_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmStringViewIter> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=321&c=1
TNode<WasmNull> Cast_WasmNull_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmNull> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmNull_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmNull> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=324&c=1
TNode<WasmNull> kWasmNull_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<WasmNull> tmp0;
    tmp0 = CodeStubAssembler(state_).WasmNullConstant();
    return TNode<WasmNull> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=326&c=1
TNode<WasmSuspendingObject> Cast_WasmSuspendingObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmSuspendingObject> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = DownCastForTorqueClass_WasmSuspendingObject_0(state_, TNode<HeapObject> { p_obj }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_CastError);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmSuspendingObject> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=111&c=3
TNode<TrustedPointerT> LoadWasmFuncRefTrustedInternal_0(compiler::CodeAssemblerState* state_, TNode<WasmFuncRef> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<TrustedPointerT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<TrustedPointerT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=111&c=3
void StoreWasmFuncRefTrustedInternal_0(compiler::CodeAssemblerState* state_, TNode<WasmFuncRef> p_o, TNode<TrustedPointerT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=47&c=3
TNode<MaybeObject> LoadWasmImportDataProtectedInstanceData_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<MaybeObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<MaybeObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<MaybeObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=47&c=3
void StoreWasmImportDataProtectedInstanceData_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o, TNode<MaybeObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<MaybeObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=48&c=3
TNode<NativeContext> LoadWasmImportDataNativeContext_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<NativeContext> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<NativeContext>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<NativeContext> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=48&c=3
void StoreWasmImportDataNativeContext_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o, TNode<NativeContext> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<NativeContext>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=49&c=3
TNode<HeapObject> LoadWasmImportDataCallable_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<HeapObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<HeapObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=49&c=3
void StoreWasmImportDataCallable_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o, TNode<HeapObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=50&c=3
TNode<Smi> LoadWasmImportDataSuspend_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=50&c=3
void StoreWasmImportDataSuspend_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=51&c=3
TNode<Smi> LoadWasmImportDataWrapperBudget_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=51&c=3
void StoreWasmImportDataWrapperBudget_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=58&c=3
TNode<Object> LoadWasmImportDataCallOrigin_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Object> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Object> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=58&c=3
void StoreWasmImportDataCallOrigin_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o, TNode<Object> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=60&c=3
TNode<RawPtrT> LoadWasmImportDataSig_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
        tmp1 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<RawPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=60&c=3
void StoreWasmImportDataSig_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o, TNode<RawPtrT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
        CodeStubAssembler(state_).StoreReference<RawPtrT>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=34&c=3
TNode<TrustedPointerT> LoadWasmInstanceObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmInstanceObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<TrustedPointerT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp1 = CodeStubAssembler(state_).LoadReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<TrustedPointerT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=34&c=3
void StoreWasmInstanceObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmInstanceObject> p_o, TNode<TrustedPointerT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=35&c=3
TNode<WasmModuleObject> LoadWasmInstanceObjectModuleObject_0(compiler::CodeAssemblerState* state_, TNode<WasmInstanceObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<WasmModuleObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp1 = CodeStubAssembler(state_).LoadReference<WasmModuleObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<WasmModuleObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=35&c=3
void StoreWasmInstanceObjectModuleObject_0(compiler::CodeAssemblerState* state_, TNode<WasmInstanceObject> p_o, TNode<WasmModuleObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        CodeStubAssembler(state_).StoreReference<WasmModuleObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=36&c=3
TNode<JSObject> LoadWasmInstanceObjectExportsObject_0(compiler::CodeAssemblerState* state_, TNode<WasmInstanceObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<JSObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        tmp1 = CodeStubAssembler(state_).LoadReference<JSObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<JSObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=36&c=3
void StoreWasmInstanceObjectExportsObject_0(compiler::CodeAssemblerState* state_, TNode<WasmInstanceObject> p_o, TNode<JSObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        CodeStubAssembler(state_).StoreReference<JSObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=67&c=3
TNode<HeapObject> LoadWasmFastApiCallDataSignature_0(compiler::CodeAssemblerState* state_, TNode<WasmFastApiCallData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<HeapObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<HeapObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=67&c=3
void StoreWasmFastApiCallDataSignature_0(compiler::CodeAssemblerState* state_, TNode<WasmFastApiCallData> p_o, TNode<HeapObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=68&c=3
TNode<Object> LoadWasmFastApiCallDataCallbackData_0(compiler::CodeAssemblerState* state_, TNode<WasmFastApiCallData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Object> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Object> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=68&c=3
void StoreWasmFastApiCallDataCallbackData_0(compiler::CodeAssemblerState* state_, TNode<WasmFastApiCallData> p_o, TNode<Object> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=69&c=3
TNode<MaybeObject> LoadWasmFastApiCallDataCachedMap_0(compiler::CodeAssemblerState* state_, TNode<WasmFastApiCallData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<MaybeObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp1 = CodeStubAssembler(state_).LoadReference<MaybeObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<MaybeObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=69&c=3
void StoreWasmFastApiCallDataCachedMap_0(compiler::CodeAssemblerState* state_, TNode<WasmFastApiCallData> p_o, TNode<MaybeObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<MaybeObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=81&c=3
TNode<MaybeObject> LoadWasmInternalFunctionProtectedImplicitArg_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<MaybeObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<MaybeObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<MaybeObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=81&c=3
void StoreWasmInternalFunctionProtectedImplicitArg_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o, TNode<MaybeObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<MaybeObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=84&c=3
TNode<HeapObject> LoadWasmInternalFunctionExternal_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<HeapObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<HeapObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=84&c=3
void StoreWasmInternalFunctionExternal_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o, TNode<HeapObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=91&c=3
TNode<Smi> LoadWasmInternalFunctionFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=91&c=3
void StoreWasmInternalFunctionFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=93&c=3
TNode<RawPtrT> LoadWasmInternalFunctionCallTarget_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp1 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<RawPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=93&c=3
void StoreWasmInternalFunctionCallTarget_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o, TNode<RawPtrT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        CodeStubAssembler(state_).StoreReference<RawPtrT>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=120&c=3
TNode<TrustedPointerT> LoadWasmFunctionDataWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<TrustedPointerT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<TrustedPointerT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=120&c=3
void StoreWasmFunctionDataWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o, TNode<TrustedPointerT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=123&c=3
TNode<WasmFuncRef> LoadWasmFunctionDataFuncRef_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<WasmFuncRef> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<WasmFuncRef>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<WasmFuncRef> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=123&c=3
void StoreWasmFunctionDataFuncRef_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o, TNode<WasmFuncRef> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<WasmFuncRef>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=125&c=3
TNode<Smi> LoadWasmFunctionDataJsPromiseFlags_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=125&c=3
void StoreWasmFunctionDataJsPromiseFlags_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=128&c=3
TNode<MaybeObject> LoadWasmFunctionDataProtectedInternal_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<MaybeObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp1 = CodeStubAssembler(state_).LoadReference<MaybeObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<MaybeObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=128&c=3
void StoreWasmFunctionDataProtectedInternal_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o, TNode<MaybeObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        CodeStubAssembler(state_).StoreReference<MaybeObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=138&c=3
TNode<MaybeObject> LoadWasmExportedFunctionDataProtectedInstanceData_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<MaybeObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        tmp1 = CodeStubAssembler(state_).LoadReference<MaybeObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<MaybeObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=138&c=3
void StoreWasmExportedFunctionDataProtectedInstanceData_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<MaybeObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        CodeStubAssembler(state_).StoreReference<MaybeObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=139&c=3
TNode<Smi> LoadWasmExportedFunctionDataFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=139&c=3
void StoreWasmExportedFunctionDataFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=141&c=3
TNode<Cell> LoadWasmExportedFunctionDataWrapperBudget_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Cell> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
        tmp1 = CodeStubAssembler(state_).LoadReference<Cell>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Cell> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=141&c=3
void StoreWasmExportedFunctionDataWrapperBudget_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<Cell> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
        CodeStubAssembler(state_).StoreReference<Cell>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=142&c=3
TNode<Smi> LoadWasmExportedFunctionDataCanonicalTypeIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 32);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=142&c=3
void StoreWasmExportedFunctionDataCanonicalTypeIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 32);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=147&c=3
TNode<Smi> LoadWasmExportedFunctionDataPackedArgsSize_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 36);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=147&c=3
void StoreWasmExportedFunctionDataPackedArgsSize_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 36);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=148&c=3
TNode<TrustedPointerT> LoadWasmExportedFunctionDataCWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<TrustedPointerT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 40);
        tmp1 = CodeStubAssembler(state_).LoadReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<TrustedPointerT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=148&c=3
void StoreWasmExportedFunctionDataCWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<TrustedPointerT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 40);
        CodeStubAssembler(state_).StoreReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=150&c=3
TNode<RawPtrT> LoadWasmExportedFunctionDataSig_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 44);
        tmp1 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<RawPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=150&c=3
void StoreWasmExportedFunctionDataSig_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<RawPtrT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 44);
        CodeStubAssembler(state_).StoreReference<RawPtrT>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=158&c=3
TNode<Smi> LoadWasmJSFunctionDataCanonicalSigIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=158&c=3
void StoreWasmJSFunctionDataCanonicalSigIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=159&c=3
TNode<MaybeObject> LoadWasmJSFunctionDataProtectedOffheapData_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<MaybeObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        tmp1 = CodeStubAssembler(state_).LoadReference<MaybeObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<MaybeObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=159&c=3
void StoreWasmJSFunctionDataProtectedOffheapData_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o, TNode<MaybeObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        CodeStubAssembler(state_).StoreReference<MaybeObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=165&c=3
TNode<Smi> LoadWasmCapiFunctionDataCanonicalSigIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=165&c=3
void StoreWasmCapiFunctionDataCanonicalSigIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=166&c=3
TNode<Foreign> LoadWasmCapiFunctionDataEmbedderData_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Foreign> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        tmp1 = CodeStubAssembler(state_).LoadReference<Foreign>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Foreign> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=166&c=3
void StoreWasmCapiFunctionDataEmbedderData_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o, TNode<Foreign> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        CodeStubAssembler(state_).StoreReference<Foreign>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=167&c=3
TNode<RawPtrT> LoadWasmCapiFunctionDataSig_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
        tmp1 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<RawPtrT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=167&c=3
void StoreWasmCapiFunctionDataSig_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o, TNode<RawPtrT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
        CodeStubAssembler(state_).StoreReference<RawPtrT>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=171&c=3
TNode<WasmSuspenderObject> LoadWasmResumeDataSuspender_0(compiler::CodeAssemblerState* state_, TNode<WasmResumeData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<WasmSuspenderObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<WasmSuspenderObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<WasmSuspenderObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=171&c=3
void StoreWasmResumeDataSuspender_0(compiler::CodeAssemblerState* state_, TNode<WasmResumeData> p_o, TNode<WasmSuspenderObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<WasmSuspenderObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=172&c=3
TNode<Smi> LoadWasmResumeDataOnResume_0(compiler::CodeAssemblerState* state_, TNode<WasmResumeData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=172&c=3
void StoreWasmResumeDataOnResume_0(compiler::CodeAssemblerState* state_, TNode<WasmResumeData> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=176&c=3
TNode<HeapObject> LoadWasmContinuationObjectParent_0(compiler::CodeAssemblerState* state_, TNode<WasmContinuationObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<HeapObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<HeapObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=176&c=3
void StoreWasmContinuationObjectParent_0(compiler::CodeAssemblerState* state_, TNode<WasmContinuationObject> p_o, TNode<HeapObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=177&c=3
TNode<ExternalPointerT> LoadWasmContinuationObjectStack_0(compiler::CodeAssemblerState* state_, TNode<WasmContinuationObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<ExternalPointerT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<ExternalPointerT>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<ExternalPointerT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=177&c=3
void StoreWasmContinuationObjectStack_0(compiler::CodeAssemblerState* state_, TNode<WasmContinuationObject> p_o, TNode<ExternalPointerT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<ExternalPointerT>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=178&c=3
TNode<ExternalPointerT> LoadWasmContinuationObjectJmpbuf_0(compiler::CodeAssemblerState* state_, TNode<WasmContinuationObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<ExternalPointerT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp1 = CodeStubAssembler(state_).LoadReference<ExternalPointerT>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<ExternalPointerT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=178&c=3
void StoreWasmContinuationObjectJmpbuf_0(compiler::CodeAssemblerState* state_, TNode<WasmContinuationObject> p_o, TNode<ExternalPointerT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<ExternalPointerT>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=182&c=3
TNode<HeapObject> LoadWasmSuspenderObjectContinuation_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<HeapObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<HeapObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=182&c=3
void StoreWasmSuspenderObjectContinuation_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o, TNode<HeapObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=183&c=3
TNode<HeapObject> LoadWasmSuspenderObjectParent_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<HeapObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<HeapObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=183&c=3
void StoreWasmSuspenderObjectParent_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o, TNode<HeapObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=184&c=3
TNode<JSPromise> LoadWasmSuspenderObjectPromise_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<JSPromise> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp1 = CodeStubAssembler(state_).LoadReference<JSPromise>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<JSPromise> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=184&c=3
void StoreWasmSuspenderObjectPromise_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o, TNode<JSPromise> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<JSPromise>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=185&c=3
TNode<HeapObject> LoadWasmSuspenderObjectResume_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<HeapObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<HeapObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=185&c=3
void StoreWasmSuspenderObjectResume_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o, TNode<HeapObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=186&c=3
TNode<HeapObject> LoadWasmSuspenderObjectReject_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<HeapObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<HeapObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=186&c=3
void StoreWasmSuspenderObjectReject_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o, TNode<HeapObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=187&c=3
TNode<Smi> LoadWasmSuspenderObjectState_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=187&c=3
void StoreWasmSuspenderObjectState_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=194&c=3
TNode<Smi> LoadWasmExceptionTagIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExceptionTag> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=194&c=3
void StoreWasmExceptionTagIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExceptionTag> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=200&c=3
TNode<Foreign> LoadWasmModuleObjectManagedNativeModule_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Foreign> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp1 = CodeStubAssembler(state_).LoadReference<Foreign>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Foreign> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=200&c=3
void StoreWasmModuleObjectManagedNativeModule_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o, TNode<Foreign> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<Foreign>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=201&c=3
TNode<Script> LoadWasmModuleObjectScript_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Script> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp1 = CodeStubAssembler(state_).LoadReference<Script>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Script> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=201&c=3
void StoreWasmModuleObjectScript_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o, TNode<Script> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        CodeStubAssembler(state_).StoreReference<Script>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=215&c=3
TNode<FixedArray> LoadWasmTableObjectEntries_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<FixedArray> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp1 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<FixedArray> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=215&c=3
void StoreWasmTableObjectEntries_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<FixedArray> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<FixedArray>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=216&c=3
TNode<Smi> LoadWasmTableObjectCurrentLength_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=216&c=3
void StoreWasmTableObjectCurrentLength_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=221&c=3
TNode<Object> LoadWasmTableObjectMaximumLength_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Object> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Object> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=221&c=3
void StoreWasmTableObjectMaximumLength_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<Object> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=224&c=3
TNode<FixedArray> LoadWasmTableObjectUses_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<FixedArray> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        tmp1 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<FixedArray> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=224&c=3
void StoreWasmTableObjectUses_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<FixedArray> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        CodeStubAssembler(state_).StoreReference<FixedArray>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=225&c=3
TNode<Smi> LoadWasmTableObjectRawType_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=225&c=3
void StoreWasmTableObjectRawType_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=229&c=3
TNode<TrustedPointerT> LoadWasmTableObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<TrustedPointerT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 32);
        tmp1 = CodeStubAssembler(state_).LoadReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<TrustedPointerT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=229&c=3
void StoreWasmTableObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<TrustedPointerT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 32);
        CodeStubAssembler(state_).StoreReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=230&c=3
TNode<Uint8T> LoadWasmTableObjectAddressType_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Uint8T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 36);
        tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint8T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=230&c=3
void StoreWasmTableObjectAddressType_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<Uint8T> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 36);
        CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=232&c=3
TNode<Uint8T> LoadWasmTableObjectPaddingForAddressType0_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Uint8T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 37);
        tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint8T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=232&c=3
void StoreWasmTableObjectPaddingForAddressType0_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<Uint8T> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 37);
        CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=233&c=3
TNode<Uint16T> LoadWasmTableObjectPaddingForAddressType1_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Uint16T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 38);
        tmp1 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint16T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=233&c=3
void StoreWasmTableObjectPaddingForAddressType1_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<Uint16T> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 38);
        CodeStubAssembler(state_).StoreReference<Uint16T>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=238&c=3
TNode<JSArrayBuffer> LoadWasmMemoryObjectArrayBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<JSArrayBuffer> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp1 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<JSArrayBuffer> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=238&c=3
void StoreWasmMemoryObjectArrayBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o, TNode<JSArrayBuffer> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<JSArrayBuffer>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=239&c=3
TNode<Smi> LoadWasmMemoryObjectMaximumPages_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=239&c=3
void StoreWasmMemoryObjectMaximumPages_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=240&c=3
TNode<WeakArrayList> LoadWasmMemoryObjectInstances_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<WeakArrayList> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        tmp1 = CodeStubAssembler(state_).LoadReference<WeakArrayList>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<WeakArrayList> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=240&c=3
void StoreWasmMemoryObjectInstances_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o, TNode<WeakArrayList> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        CodeStubAssembler(state_).StoreReference<WeakArrayList>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=241&c=3
TNode<Uint8T> LoadWasmMemoryObjectAddressType_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Uint8T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint8T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=241&c=3
void StoreWasmMemoryObjectAddressType_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o, TNode<Uint8T> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=243&c=3
TNode<Uint8T> LoadWasmMemoryObjectPaddingForAddressType0_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Uint8T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 25);
        tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint8T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=243&c=3
void StoreWasmMemoryObjectPaddingForAddressType0_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o, TNode<Uint8T> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 25);
        CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=244&c=3
TNode<Uint16T> LoadWasmMemoryObjectPaddingForAddressType1_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Uint16T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 26);
        tmp1 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint16T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=244&c=3
void StoreWasmMemoryObjectPaddingForAddressType1_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o, TNode<Uint16T> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 26);
        CodeStubAssembler(state_).StoreReference<Uint16T>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=252&c=3
TNode<TrustedPointerT> LoadWasmGlobalObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<TrustedPointerT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp1 = CodeStubAssembler(state_).LoadReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<TrustedPointerT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=252&c=3
void StoreWasmGlobalObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<TrustedPointerT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=253&c=3
TNode<HeapObject> LoadWasmGlobalObjectUntaggedBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<HeapObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<HeapObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=253&c=3
void StoreWasmGlobalObjectUntaggedBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<HeapObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=254&c=3
TNode<HeapObject> LoadWasmGlobalObjectTaggedBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<HeapObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<HeapObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=254&c=3
void StoreWasmGlobalObjectTaggedBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<HeapObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=255&c=3
TNode<Smi> LoadWasmGlobalObjectOffset_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=255&c=3
void StoreWasmGlobalObjectOffset_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=256&c=3
TNode<Smi> LoadWasmGlobalObjectRawType_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=256&c=3
void StoreWasmGlobalObjectRawType_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=259&c=3
TNode<Smi> LoadWasmGlobalObjectIsMutable_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 32);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=259&c=3
void StoreWasmGlobalObjectIsMutable_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 32);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=263&c=3
TNode<ByteArray> LoadWasmTagObjectSerializedSignature_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<ByteArray> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp1 = CodeStubAssembler(state_).LoadReference<ByteArray>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<ByteArray> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=263&c=3
void StoreWasmTagObjectSerializedSignature_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o, TNode<ByteArray> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<ByteArray>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=264&c=3
TNode<HeapObject> LoadWasmTagObjectTag_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<HeapObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<HeapObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=264&c=3
void StoreWasmTagObjectTag_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o, TNode<HeapObject> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=265&c=3
TNode<Smi> LoadWasmTagObjectCanonicalTypeIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=265&c=3
void StoreWasmTagObjectCanonicalTypeIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o, TNode<Smi> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=266&c=3
TNode<TrustedPointerT> LoadWasmTagObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<TrustedPointerT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        tmp1 = CodeStubAssembler(state_).LoadReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<TrustedPointerT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=266&c=3
void StoreWasmTagObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o, TNode<TrustedPointerT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
        CodeStubAssembler(state_).StoreReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=272&c=3
TNode<Foreign> LoadAsmWasmDataManagedNativeModule_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Foreign> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<Foreign>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Foreign> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=272&c=3
void StoreAsmWasmDataManagedNativeModule_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o, TNode<Foreign> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<Foreign>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=273&c=3
TNode<HeapNumber> LoadAsmWasmDataUsesBitset_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<HeapNumber> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<HeapNumber>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<HeapNumber> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=273&c=3
void StoreAsmWasmDataUsesBitset_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o, TNode<HeapNumber> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<HeapNumber>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=285&c=3
TNode<ExternalPointerT> LoadWasmTypeInfoNativeType_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<ExternalPointerT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<ExternalPointerT>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<ExternalPointerT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=285&c=3
void StoreWasmTypeInfoNativeType_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o, TNode<ExternalPointerT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<ExternalPointerT>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=286&c=3
TNode<Uint32T> LoadWasmTypeInfoModuleTypeIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=286&c=3
void StoreWasmTypeInfoModuleTypeIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o, TNode<Uint32T> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=290&c=3
TNode<TrustedPointerT> LoadWasmTypeInfoTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<TrustedPointerT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp1 = CodeStubAssembler(state_).LoadReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<TrustedPointerT> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=290&c=3
void StoreWasmTypeInfoTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o, TNode<TrustedPointerT> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<TrustedPointerT>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=291&c=9
TNode<Smi> LoadWasmTypeInfoSupertypesLength_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Smi> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
TorqueStructSlice_Object_MutableReference_Object_0 FieldSliceWasmTypeInfoSupertypes_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<Object> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_o, tmp0 });
        tmp2 = Convert_intptr_Smi_0(state_, TNode<Smi> { tmp1 });
        tmp3 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x14ull));
        std::tie(tmp4, tmp5, tmp6) = NewMutableSlice_Object_0(state_, TNode<Object> { p_o }, TNode<IntPtrT> { tmp3 }, TNode<IntPtrT> { tmp2 }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructSlice_Object_MutableReference_Object_0 { TNode<Object> { tmp4 }, TNode<IntPtrT> { tmp5 }, TNode<IntPtrT> { tmp6 },
        TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
TNode<Object> LoadWasmTypeInfoSupertypes_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o, TNode<IntPtrT> p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<UintPtrT> tmp4;
    TNode<BoolT> tmp5;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1, tmp2) = FieldSliceWasmTypeInfoSupertypes_0(state_, TNode<WasmTypeInfo> { p_o }).Flatten();
        tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { p_i });
        tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp2 });
        tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp3 }, TNode<UintPtrT> { tmp4 });
        ca_.Branch(tmp5, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<Object> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Object> tmp10;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { p_i });
        tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp1 }, TNode<IntPtrT> { tmp6 });
        std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp7 }).Flatten();
        tmp10 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp8, tmp9 });
        ca_.Goto(&block10);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block10);
    return TNode<Object> { tmp10 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
void StoreWasmTypeInfoSupertypes_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o, TNode<IntPtrT> p_i, TNode<Object> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<UintPtrT> tmp4;
    TNode<BoolT> tmp5;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1, tmp2) = FieldSliceWasmTypeInfoSupertypes_0(state_, TNode<WasmTypeInfo> { p_o }).Flatten();
        tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { p_i });
        tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp2 });
        tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp3 }, TNode<UintPtrT> { tmp4 });
        ca_.Branch(tmp5, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<Object> tmp8;
    TNode<IntPtrT> tmp9;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { p_i });
        tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp1 }, TNode<IntPtrT> { tmp6 });
        std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp7 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp8, tmp9 }, p_v);
        ca_.Goto(&block10);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=307&c=3
TNode<Uint32T> LoadWasmArrayLength_0(compiler::CodeAssemblerState* state_, TNode<WasmArray> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=307&c=3
void StoreWasmArrayLength_0(compiler::CodeAssemblerState* state_, TNode<WasmArray> p_o, TNode<Uint32T> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=314&c=3
TNode<String> LoadWasmStringViewIterString_0(compiler::CodeAssemblerState* state_, TNode<WasmStringViewIter> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<String> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<String> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=314&c=3
void StoreWasmStringViewIterString_0(compiler::CodeAssemblerState* state_, TNode<WasmStringViewIter> p_o, TNode<String> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<String>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=315&c=3
TNode<Uint32T> LoadWasmStringViewIterOffset_0(compiler::CodeAssemblerState* state_, TNode<WasmStringViewIter> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=315&c=3
void StoreWasmStringViewIterOffset_0(compiler::CodeAssemblerState* state_, TNode<WasmStringViewIter> p_o, TNode<Uint32T> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=327&c=3
TNode<JSReceiver> LoadWasmSuspendingObjectCallable_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspendingObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<JSReceiver> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp1 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference { p_o, tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<JSReceiver> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=327&c=3
void StoreWasmSuspendingObjectCallable_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspendingObject> p_o, TNode<JSReceiver> p_v)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference { p_o, tmp0 }, p_v);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=31&c=1
TNode<WasmTrustedInstanceData> DownCastForTorqueClass_WasmTrustedInstanceData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(190), static_cast<InstanceType>(190))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmTrustedInstanceData>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmTrustedInstanceData>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(190));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(190), static_cast<InstanceType>(190))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(190));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmTrustedInstanceData> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmTrustedInstanceData> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=33&c=1
TNode<WasmInstanceObject> DownCastForTorqueClass_WasmInstanceObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(2160), static_cast<InstanceType>(2160))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmInstanceObject>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmInstanceObject>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(2160));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(2160), static_cast<InstanceType>(2160))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(2160));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmInstanceObject> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmInstanceObject> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=43&c=1
TNode<WasmImportData> DownCastForTorqueClass_WasmImportData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(199), static_cast<InstanceType>(199))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmImportData>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmImportData>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(199));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(199), static_cast<InstanceType>(199))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(199));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmImportData> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmImportData> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=66&c=1
TNode<WasmFastApiCallData> DownCastForTorqueClass_WasmFastApiCallData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(287), static_cast<InstanceType>(287))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmFastApiCallData>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmFastApiCallData>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(287));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(287), static_cast<InstanceType>(287))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(287));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmFastApiCallData> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmFastApiCallData> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=74&c=1
TNode<WasmInternalFunction> DownCastForTorqueClass_WasmInternalFunction_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(189), static_cast<InstanceType>(189))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmInternalFunction>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmInternalFunction>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(189));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(189), static_cast<InstanceType>(189))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(189));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmInternalFunction> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmInternalFunction> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=109&c=1
TNode<WasmFuncRef> DownCastForTorqueClass_WasmFuncRef_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(288), static_cast<InstanceType>(288))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmFuncRef>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmFuncRef>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(288));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(288), static_cast<InstanceType>(288))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(288));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmFuncRef> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmFuncRef> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=118&c=1
TNode<WasmFunctionData> DownCastForTorqueClass_WasmFunctionData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(179), static_cast<InstanceType>(182))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmFunctionData>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmFunctionData>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(179));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(182), static_cast<InstanceType>(179))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(179));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmFunctionData> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmFunctionData> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=134&c=1
TNode<WasmExportedFunctionData> DownCastForTorqueClass_WasmExportedFunctionData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(181), static_cast<InstanceType>(181))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmExportedFunctionData>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmExportedFunctionData>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(181));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(181), static_cast<InstanceType>(181))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(181));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmExportedFunctionData> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmExportedFunctionData> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=157&c=1
TNode<WasmJSFunctionData> DownCastForTorqueClass_WasmJSFunctionData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(182), static_cast<InstanceType>(182))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmJSFunctionData>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmJSFunctionData>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(182));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(182), static_cast<InstanceType>(182))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(182));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmJSFunctionData> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmJSFunctionData> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=163&c=1
TNode<WasmCapiFunctionData> DownCastForTorqueClass_WasmCapiFunctionData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(180), static_cast<InstanceType>(180))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmCapiFunctionData>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmCapiFunctionData>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(180));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(180), static_cast<InstanceType>(180))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(180));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmCapiFunctionData> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmCapiFunctionData> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=170&c=1
TNode<WasmResumeData> DownCastForTorqueClass_WasmResumeData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(290), static_cast<InstanceType>(290))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmResumeData>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmResumeData>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(290));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(290), static_cast<InstanceType>(290))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(290));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmResumeData> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmResumeData> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=175&c=1
TNode<WasmContinuationObject> DownCastForTorqueClass_WasmContinuationObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(286), static_cast<InstanceType>(286))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmContinuationObject>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmContinuationObject>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(286));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(286), static_cast<InstanceType>(286))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(286));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmContinuationObject> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmContinuationObject> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=181&c=1
TNode<WasmSuspenderObject> DownCastForTorqueClass_WasmSuspenderObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(292), static_cast<InstanceType>(292))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmSuspenderObject>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmSuspenderObject>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(292));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(292), static_cast<InstanceType>(292))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(292));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmSuspenderObject> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmSuspenderObject> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=190&c=1
TNode<WasmExceptionTag> DownCastForTorqueClass_WasmExceptionTag_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(174), static_cast<InstanceType>(174))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmExceptionTag>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmExceptionTag>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(174));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(174), static_cast<InstanceType>(174))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(174));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmExceptionTag> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmExceptionTag> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=197&c=1
TNode<WasmExceptionPackage> DownCastForTorqueClass_WasmExceptionPackage_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(2158), static_cast<InstanceType>(2158))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmExceptionPackage>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmExceptionPackage>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(2158));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(2158), static_cast<InstanceType>(2158))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(2158));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmExceptionPackage> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmExceptionPackage> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=199&c=1
TNode<WasmModuleObject> DownCastForTorqueClass_WasmModuleObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(2162), static_cast<InstanceType>(2162))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmModuleObject>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmModuleObject>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(2162));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(2162), static_cast<InstanceType>(2162))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(2162));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmModuleObject> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmModuleObject> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=204&c=1
TNode<WasmDispatchTable> DownCastForTorqueClass_WasmDispatchTable_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(198), static_cast<InstanceType>(198))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmDispatchTable>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmDispatchTable>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(198));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(198), static_cast<InstanceType>(198))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(198));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmDispatchTable> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmDispatchTable> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=206&c=1
TNode<WasmTableObject> DownCastForTorqueClass_WasmTableObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(2164), static_cast<InstanceType>(2164))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmTableObject>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmTableObject>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(2164));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(2164), static_cast<InstanceType>(2164))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(2164));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmTableObject> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmTableObject> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=237&c=1
TNode<WasmMemoryObject> DownCastForTorqueClass_WasmMemoryObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(2161), static_cast<InstanceType>(2161))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmMemoryObject>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmMemoryObject>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(2161));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(2161), static_cast<InstanceType>(2161))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(2161));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmMemoryObject> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmMemoryObject> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=248&c=1
TNode<WasmGlobalObject> DownCastForTorqueClass_WasmGlobalObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(2159), static_cast<InstanceType>(2159))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmGlobalObject>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmGlobalObject>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(2159));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(2159), static_cast<InstanceType>(2159))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(2159));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmGlobalObject> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmGlobalObject> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=262&c=1
TNode<WasmTagObject> DownCastForTorqueClass_WasmTagObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(2165), static_cast<InstanceType>(2165))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmTagObject>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmTagObject>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(2165));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(2165), static_cast<InstanceType>(2165))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(2165));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmTagObject> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmTagObject> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=271&c=1
TNode<AsmWasmData> DownCastForTorqueClass_AsmWasmData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(145), static_cast<InstanceType>(145))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<AsmWasmData>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<AsmWasmData>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(145));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(145), static_cast<InstanceType>(145))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(145));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<AsmWasmData> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<AsmWasmData> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=276&c=1
TNode<WasmTypeInfo> DownCastForTorqueClass_WasmTypeInfo_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(293), static_cast<InstanceType>(293))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmTypeInfo>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmTypeInfo>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(293));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(293), static_cast<InstanceType>(293))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(293));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmTypeInfo> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmTypeInfo> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=299&c=1
TNode<WasmObject> DownCastForTorqueClass_WasmObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(296), static_cast<InstanceType>(297))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmObject>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmObject>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(296));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(297), static_cast<InstanceType>(296))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(296));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmObject> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmObject> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=302&c=1
TNode<WasmStruct> DownCastForTorqueClass_WasmStruct_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(297), static_cast<InstanceType>(297))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmStruct>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmStruct>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(297));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(297), static_cast<InstanceType>(297))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(297));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmStruct> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmStruct> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=305&c=1
TNode<WasmArray> DownCastForTorqueClass_WasmArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(296), static_cast<InstanceType>(296))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmArray>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmArray>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(296));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(296), static_cast<InstanceType>(296))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(296));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmArray> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmArray> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=313&c=1
TNode<WasmStringViewIter> DownCastForTorqueClass_WasmStringViewIter_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(291), static_cast<InstanceType>(291))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmStringViewIter>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmStringViewIter>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(291));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(291), static_cast<InstanceType>(291))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(291));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmStringViewIter> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmStringViewIter> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=321&c=1
TNode<WasmNull> DownCastForTorqueClass_WasmNull_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(289), static_cast<InstanceType>(289))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmNull>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmNull>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(289));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(289), static_cast<InstanceType>(289))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(289));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmNull> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmNull> { tmp20 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=326&c=1
TNode<WasmSuspendingObject> DownCastForTorqueClass_WasmSuspendingObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Map> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_o, tmp0 });
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(2163), static_cast<InstanceType>(2163))))) {
            ca_.Goto(&block3);
        } else {
            ca_.Goto(&block4);
        }
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        if ((CodeStubAssembler(state_).ClassHasMapConstant<WasmSuspendingObject>())) {
            ca_.Goto(&block6);
        } else {
            ca_.Goto(&block7);
        }
    }

    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).GetClassMapConstant<WasmSuspendingObject>();
        tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject> { tmp1 }, TNode<HeapObject> { tmp2 });
        ca_.Branch(tmp3, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block1);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block8);
    }

    TNode<IntPtrT> tmp4;
    TNode<Uint16T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(2163));
        tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block1);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block8);
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block5);
    }

    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<Uint16T> tmp11;
    TNode<Int32T> tmp12;
    TNode<Uint16T> tmp13;
    TNode<Uint16T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = FromConstexpr_int32_constexpr_int32_0(
            state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(2163), static_cast<InstanceType>(2163))));
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp1, tmp9 });
        tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp10 });
        tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp11 });
        tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(2163));
        tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T> { tmp13 });
        tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T> { tmp12 }, TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp8 });
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp17 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block5);
    }

    TNode<WasmSuspendingObject> tmp20;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp20 = TORQUE_CAST(TNode<HeapObject> { p_o });
        ca_.Goto(&block15);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(label_CastError);
    }

    ca_.Bind(&block15);
    return TNode<WasmSuspendingObject> { tmp20 };
}

} // namespace internal
} // namespace v8
