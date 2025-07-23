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
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-flat-tq-csa.h"
#include "torque-generated/src/builtins/array-from-async-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-splice-tq-csa.h"
#include "torque-generated/src/builtins/array-to-sorted-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/boolean-tq-csa.h"
#include "torque-generated/src/builtins/builtins-string-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/conversion-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frames-tq-csa.h"
#include "torque-generated/src/builtins/internal-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/number-tq-csa.h"
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/promise-misc-tq-csa.h"
#include "torque-generated/src/builtins/promise-resolve-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/heap-number-tq-csa.h"
#include "torque-generated/src/objects/js-function-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"
#include "torque-generated/src/objects/js-promise-tq-csa.h"
#include "torque-generated/src/objects/map-tq-csa.h"
#include "torque-generated/src/objects/promise-tq-csa.h"
#include "torque-generated/src/objects/property-cell-tq-csa.h"
#include "torque-generated/src/objects/regexp-match-info-tq-csa.h"
#include "torque-generated/src/objects/scope-info-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"
#include "torque-generated/third_party/v8/builtins/array-sort-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=5&c=1
TNode<Context> Cast_Context_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_Context_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<Context>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=17&c=1
TNode<ScriptContextTable> Cast_ScriptContextTable_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<ScriptContextTable> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_ScriptContextTable_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<ScriptContextTable>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=25&c=1
TNode<Context> Cast_AwaitContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_AwaitContext_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<Context>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=26&c=1
TNode<Context> Cast_BlockContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_BlockContext_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<Context>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=27&c=1
TNode<Context> Cast_CatchContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_CatchContext_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<Context>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=28&c=1
TNode<Context> Cast_DebugEvaluateContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_DebugEvaluateContext_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<Context>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=30&c=1
TNode<Context> Cast_EvalContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_EvalContext_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<Context>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=31&c=1
TNode<Context> Cast_ModuleContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_ModuleContext_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<Context>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=32&c=1
TNode<Context> Cast_ScriptContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_ScriptContext_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<Context>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=33&c=1
TNode<Context> Cast_WithContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_WithContext_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<Context>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=35&c=1
TNode<Context> Cast_FunctionContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_FunctionContext_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<Context>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=37&c=1
TNode<Smi> kInitialContextSlotValue_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<Smi> tmp0;
    tmp0 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
  return TNode<Smi>{tmp0};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=39&c=1
TNode<Context> AllocateSyntheticFunctionContext_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_nativeContext, int31_t p_slots) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Context> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Convert_intptr_constexpr_int31_0(state_, p_slots);
    tmp1 = AllocateSyntheticFunctionContext_1(state_, TNode<NativeContext>{p_nativeContext}, TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Context>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=46&c=1
TNode<Context> AllocateSyntheticFunctionContext_1(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_nativeContext, TNode<IntPtrT> p_slots) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<BoolT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Map> tmp5;
  TNode<Smi> tmp6;
  TNode<Smi> tmp7;
  TNode<Smi> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<BoolT> tmp12;
  TNode<BoolT> tmp13;
  TNode<HeapObject> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<Context> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<ScopeInfo> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Undefined> tmp22;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_intptr_0(state_, Context::Field::MIN_CONTEXT_SLOTS);
    tmp1 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{p_slots}, TNode<IntPtrT>{tmp0});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp1}, "static_assert(slots >= ContextSlot::MIN_CONTEXT_SLOTS) at https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=48&c=3");
    tmp2 = FUNCTION_CONTEXT_MAP_INDEX_0(state_);
    std::tie(tmp3, tmp4) = ContextSlot_NativeContext_NativeContext_Map_0(state_, TNode<NativeContext>{p_nativeContext}, TNode<IntPtrT>{tmp2}).Flatten();
    tmp5 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp3, tmp4});
    tmp6 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{p_slots});
    tmp7 = kInitialContextSlotValue_0(state_);
    std::tie(tmp8) = ConstantIterator_Smi_0(state_, TNode<Smi>{tmp7}).Flatten();
    tmp9 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp6});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp11 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp9}, kTaggedSize);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp14 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp11}, TNode<Map>{tmp5}, TNode<BoolT>{tmp12}, TNode<BoolT>{tmp13});
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp14, tmp15}, tmp5);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp14, tmp16}, tmp6);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_Object_ConstantIterator_Smi_0(state_, TorqueStructSlice_Object_MutableReference_Object_0{TNode<Object>{tmp14}, TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_Smi_0{TNode<Smi>{tmp8}});
    tmp18 = TORQUE_CAST(TNode<HeapObject>{tmp14});
    tmp19 = SCOPE_INFO_INDEX_0(state_);
    tmp20 = kEmptyScopeInfo_0(state_);
    InitContextSlot_FunctionContext_Context_ScopeInfo_ScopeInfo_0(state_, TNode<Context>{tmp18}, TNode<IntPtrT>{tmp19}, TNode<ScopeInfo>{tmp20});
    tmp21 = PREVIOUS_INDEX_0(state_);
    tmp22 = Undefined_0(state_);
    InitContextSlot_FunctionContext_Context_Undefined_OR_Context_OR_Zero_Undefined_0(state_, TNode<Context>{tmp18}, TNode<IntPtrT>{tmp21}, TNode<Undefined>{tmp22});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Context>{tmp18};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=61&c=1
TNode<NativeContext> Cast_NativeContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = DownCastForTorqueClass_NativeContext_0(state_, TNode<HeapObject>{p_obj}, &label1);
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
  return TNode<NativeContext>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_SCOPE_INFO_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_PREVIOUS_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_AGGREGATE_ERROR_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ARRAY_BUFFER_FUN_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ARRAY_BUFFER_NOINIT_FUN_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ARRAY_BUFFER_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ARRAY_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ARRAY_JOIN_STACK_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_OBJECT_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ITERATOR_RESULT_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ITERATOR_MAP_HELPER_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ITERATOR_FILTER_HELPER_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ITERATOR_TAKE_HELPER_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ITERATOR_DROP_HELPER_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ITERATOR_FLAT_MAP_HELPER_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ITERATOR_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_VALID_ITERATOR_WRAPPER_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_JS_ARRAY_PACKED_SMI_ELEMENTS_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_JS_MAP_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_JS_SET_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_MATH_RANDOM_CACHE_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_MATH_RANDOM_INDEX_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_NUMBER_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_PROXY_REVOCABLE_RESULT_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_REFLECT_APPLY_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_REGEXP_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_REGEXP_LAST_MATCH_INFO_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_INITIAL_STRING_ITERATOR_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_INITIAL_ARRAY_ITERATOR_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_INITIAL_ITERATOR_PROTOTYPE_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_SLOW_OBJECT_WITH_NULL_PROTOTYPE_MAP_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_STRICT_ARGUMENTS_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_SLOPPY_ARGUMENTS_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_FAST_ALIASED_ARGUMENTS_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_FUNCTION_CONTEXT_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_FUNCTION_PROTOTYPE_APPLY_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_STRING_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_UINT8_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_INT8_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_UINT16_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_INT16_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_UINT32_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_INT32_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_FLOAT16_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_FLOAT32_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_FLOAT64_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_UINT8_CLAMPED_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_BIGUINT64_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_BIGINT64_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_RAB_GSAB_UINT8_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_RAB_GSAB_INT8_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_RAB_GSAB_UINT16_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_RAB_GSAB_INT16_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_RAB_GSAB_UINT32_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_RAB_GSAB_INT32_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_RAB_GSAB_FLOAT16_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_RAB_GSAB_FLOAT32_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_RAB_GSAB_FLOAT64_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_RAB_GSAB_UINT8_CLAMPED_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_RAB_GSAB_BIGUINT64_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_RAB_GSAB_BIGINT64_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_ACCESSOR_PROPERTY_DESCRIPTOR_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_DATA_PROPERTY_DESCRIPTOR_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_PROMISE_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_PROMISE_THEN_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_PROMISE_PROTOTYPE_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_PROMISE_HOOK_INIT_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_PROMISE_HOOK_BEFORE_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_PROMISE_HOOK_AFTER_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_PROMISE_HOOK_RESOLVE_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_CONTINUATION_PRESERVED_EMBEDDER_DATA_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_BOUND_FUNCTION_WITH_CONSTRUCTOR_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_BOUND_FUNCTION_WITHOUT_CONSTRUCTOR_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_WRAPPED_FUNCTION_MAP_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_CONTEXT_SIDE_TABLE_PROPERTY_INDEX_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_MIN_CONTEXT_SLOTS_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FromConstexpr_ContextSlot_constexpr_MIN_CONTEXT_EXTENDED_SLOTS_0(compiler::CodeAssemblerState* state_, Context::Field p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.IntPtrConstant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<IntPtrT>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> SCOPE_INFO_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_SCOPE_INFO_INDEX_0(state_, Context::Field::SCOPE_INFO_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> PREVIOUS_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_PREVIOUS_INDEX_0(state_, Context::Field::PREVIOUS_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> AGGREGATE_ERROR_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_AGGREGATE_ERROR_FUNCTION_INDEX_0(state_, Context::Field::AGGREGATE_ERROR_FUNCTION_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> ARRAY_BUFFER_FUN_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_ARRAY_BUFFER_FUN_INDEX_0(state_, Context::Field::ARRAY_BUFFER_FUN_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> ARRAY_BUFFER_NOINIT_FUN_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_ARRAY_BUFFER_NOINIT_FUN_INDEX_0(state_, Context::Field::ARRAY_BUFFER_NOINIT_FUN_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> ARRAY_BUFFER_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_ARRAY_BUFFER_MAP_INDEX_0(state_, Context::Field::ARRAY_BUFFER_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> ARRAY_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_ARRAY_FUNCTION_INDEX_0(state_, Context::Field::ARRAY_FUNCTION_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> ARRAY_JOIN_STACK_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_ARRAY_JOIN_STACK_INDEX_0(state_, Context::Field::ARRAY_JOIN_STACK_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> OBJECT_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_OBJECT_FUNCTION_INDEX_0(state_, Context::Field::OBJECT_FUNCTION_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> ITERATOR_RESULT_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_ITERATOR_RESULT_MAP_INDEX_0(state_, Context::Field::ITERATOR_RESULT_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> ITERATOR_MAP_HELPER_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_ITERATOR_MAP_HELPER_MAP_INDEX_0(state_, Context::Field::ITERATOR_MAP_HELPER_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> ITERATOR_FILTER_HELPER_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_ITERATOR_FILTER_HELPER_MAP_INDEX_0(state_, Context::Field::ITERATOR_FILTER_HELPER_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> ITERATOR_TAKE_HELPER_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_ITERATOR_TAKE_HELPER_MAP_INDEX_0(state_, Context::Field::ITERATOR_TAKE_HELPER_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> ITERATOR_DROP_HELPER_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_ITERATOR_DROP_HELPER_MAP_INDEX_0(state_, Context::Field::ITERATOR_DROP_HELPER_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> ITERATOR_FLAT_MAP_HELPER_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_ITERATOR_FLAT_MAP_HELPER_MAP_INDEX_0(state_, Context::Field::ITERATOR_FLAT_MAP_HELPER_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> ITERATOR_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_ITERATOR_FUNCTION_INDEX_0(state_, Context::Field::ITERATOR_FUNCTION_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> VALID_ITERATOR_WRAPPER_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_VALID_ITERATOR_WRAPPER_MAP_INDEX_0(state_, Context::Field::VALID_ITERATOR_WRAPPER_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX_0(state_, Context::Field::JS_ARRAY_PACKED_ELEMENTS_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> JS_ARRAY_PACKED_SMI_ELEMENTS_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_JS_ARRAY_PACKED_SMI_ELEMENTS_MAP_INDEX_0(state_, Context::Field::JS_ARRAY_PACKED_SMI_ELEMENTS_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> JS_MAP_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_JS_MAP_MAP_INDEX_0(state_, Context::Field::JS_MAP_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> JS_SET_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_JS_SET_MAP_INDEX_0(state_, Context::Field::JS_SET_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> MATH_RANDOM_CACHE_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_MATH_RANDOM_CACHE_INDEX_0(state_, Context::Field::MATH_RANDOM_CACHE_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> MATH_RANDOM_INDEX_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_MATH_RANDOM_INDEX_INDEX_0(state_, Context::Field::MATH_RANDOM_INDEX_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> NUMBER_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_NUMBER_FUNCTION_INDEX_0(state_, Context::Field::NUMBER_FUNCTION_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> PROXY_REVOCABLE_RESULT_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_PROXY_REVOCABLE_RESULT_MAP_INDEX_0(state_, Context::Field::PROXY_REVOCABLE_RESULT_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> REFLECT_APPLY_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_REFLECT_APPLY_INDEX_0(state_, Context::Field::REFLECT_APPLY_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> REGEXP_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_REGEXP_FUNCTION_INDEX_0(state_, Context::Field::REGEXP_FUNCTION_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> REGEXP_LAST_MATCH_INFO_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_REGEXP_LAST_MATCH_INFO_INDEX_0(state_, Context::Field::REGEXP_LAST_MATCH_INFO_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> INITIAL_STRING_ITERATOR_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_INITIAL_STRING_ITERATOR_MAP_INDEX_0(state_, Context::Field::INITIAL_STRING_ITERATOR_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> INITIAL_ARRAY_ITERATOR_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_INITIAL_ARRAY_ITERATOR_MAP_INDEX_0(state_, Context::Field::INITIAL_ARRAY_ITERATOR_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> INITIAL_ITERATOR_PROTOTYPE_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_INITIAL_ITERATOR_PROTOTYPE_INDEX_0(state_, Context::Field::INITIAL_ITERATOR_PROTOTYPE_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> SLOW_OBJECT_WITH_NULL_PROTOTYPE_MAP_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_SLOW_OBJECT_WITH_NULL_PROTOTYPE_MAP_0(state_, Context::Field::SLOW_OBJECT_WITH_NULL_PROTOTYPE_MAP);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> STRICT_ARGUMENTS_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_STRICT_ARGUMENTS_MAP_INDEX_0(state_, Context::Field::STRICT_ARGUMENTS_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> SLOPPY_ARGUMENTS_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_SLOPPY_ARGUMENTS_MAP_INDEX_0(state_, Context::Field::SLOPPY_ARGUMENTS_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FAST_ALIASED_ARGUMENTS_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_FAST_ALIASED_ARGUMENTS_MAP_INDEX_0(state_, Context::Field::FAST_ALIASED_ARGUMENTS_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FUNCTION_CONTEXT_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_FUNCTION_CONTEXT_MAP_INDEX_0(state_, Context::Field::FUNCTION_CONTEXT_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FUNCTION_PROTOTYPE_APPLY_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_FUNCTION_PROTOTYPE_APPLY_INDEX_0(state_, Context::Field::FUNCTION_PROTOTYPE_APPLY_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> STRING_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_STRING_FUNCTION_INDEX_0(state_, Context::Field::STRING_FUNCTION_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> UINT8_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_UINT8_ARRAY_FUN_INDEX_0(state_, Context::Field::UINT8_ARRAY_FUN_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> INT8_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_INT8_ARRAY_FUN_INDEX_0(state_, Context::Field::INT8_ARRAY_FUN_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> UINT16_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_UINT16_ARRAY_FUN_INDEX_0(state_, Context::Field::UINT16_ARRAY_FUN_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> INT16_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_INT16_ARRAY_FUN_INDEX_0(state_, Context::Field::INT16_ARRAY_FUN_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> UINT32_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_UINT32_ARRAY_FUN_INDEX_0(state_, Context::Field::UINT32_ARRAY_FUN_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> INT32_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_INT32_ARRAY_FUN_INDEX_0(state_, Context::Field::INT32_ARRAY_FUN_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FLOAT16_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_FLOAT16_ARRAY_FUN_INDEX_0(state_, Context::Field::FLOAT16_ARRAY_FUN_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FLOAT32_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_FLOAT32_ARRAY_FUN_INDEX_0(state_, Context::Field::FLOAT32_ARRAY_FUN_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> FLOAT64_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_FLOAT64_ARRAY_FUN_INDEX_0(state_, Context::Field::FLOAT64_ARRAY_FUN_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> UINT8_CLAMPED_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_UINT8_CLAMPED_ARRAY_FUN_INDEX_0(state_, Context::Field::UINT8_CLAMPED_ARRAY_FUN_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> BIGUINT64_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_BIGUINT64_ARRAY_FUN_INDEX_0(state_, Context::Field::BIGUINT64_ARRAY_FUN_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> BIGINT64_ARRAY_FUN_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_BIGINT64_ARRAY_FUN_INDEX_0(state_, Context::Field::BIGINT64_ARRAY_FUN_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> RAB_GSAB_UINT8_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_RAB_GSAB_UINT8_ARRAY_MAP_INDEX_0(state_, Context::Field::RAB_GSAB_UINT8_ARRAY_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> RAB_GSAB_INT8_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_RAB_GSAB_INT8_ARRAY_MAP_INDEX_0(state_, Context::Field::RAB_GSAB_INT8_ARRAY_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> RAB_GSAB_UINT16_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_RAB_GSAB_UINT16_ARRAY_MAP_INDEX_0(state_, Context::Field::RAB_GSAB_UINT16_ARRAY_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> RAB_GSAB_INT16_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_RAB_GSAB_INT16_ARRAY_MAP_INDEX_0(state_, Context::Field::RAB_GSAB_INT16_ARRAY_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> RAB_GSAB_UINT32_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_RAB_GSAB_UINT32_ARRAY_MAP_INDEX_0(state_, Context::Field::RAB_GSAB_UINT32_ARRAY_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> RAB_GSAB_INT32_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_RAB_GSAB_INT32_ARRAY_MAP_INDEX_0(state_, Context::Field::RAB_GSAB_INT32_ARRAY_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> RAB_GSAB_FLOAT16_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_RAB_GSAB_FLOAT16_ARRAY_MAP_INDEX_0(state_, Context::Field::RAB_GSAB_FLOAT16_ARRAY_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> RAB_GSAB_FLOAT32_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_RAB_GSAB_FLOAT32_ARRAY_MAP_INDEX_0(state_, Context::Field::RAB_GSAB_FLOAT32_ARRAY_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> RAB_GSAB_FLOAT64_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_RAB_GSAB_FLOAT64_ARRAY_MAP_INDEX_0(state_, Context::Field::RAB_GSAB_FLOAT64_ARRAY_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> RAB_GSAB_UINT8_CLAMPED_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_RAB_GSAB_UINT8_CLAMPED_ARRAY_MAP_INDEX_0(state_, Context::Field::RAB_GSAB_UINT8_CLAMPED_ARRAY_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> RAB_GSAB_BIGUINT64_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_RAB_GSAB_BIGUINT64_ARRAY_MAP_INDEX_0(state_, Context::Field::RAB_GSAB_BIGUINT64_ARRAY_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> RAB_GSAB_BIGINT64_ARRAY_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_RAB_GSAB_BIGINT64_ARRAY_MAP_INDEX_0(state_, Context::Field::RAB_GSAB_BIGINT64_ARRAY_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> ACCESSOR_PROPERTY_DESCRIPTOR_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_ACCESSOR_PROPERTY_DESCRIPTOR_MAP_INDEX_0(state_, Context::Field::ACCESSOR_PROPERTY_DESCRIPTOR_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> DATA_PROPERTY_DESCRIPTOR_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_DATA_PROPERTY_DESCRIPTOR_MAP_INDEX_0(state_, Context::Field::DATA_PROPERTY_DESCRIPTOR_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> PROMISE_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_PROMISE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_FUNCTION_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> PROMISE_THEN_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_PROMISE_THEN_INDEX_0(state_, Context::Field::PROMISE_THEN_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> PROMISE_PROTOTYPE_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_PROMISE_PROTOTYPE_INDEX_0(state_, Context::Field::PROMISE_PROTOTYPE_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX_0(state_, Context::Field::STRICT_FUNCTION_WITHOUT_PROTOTYPE_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> PROMISE_HOOK_INIT_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_PROMISE_HOOK_INIT_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_HOOK_INIT_FUNCTION_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> PROMISE_HOOK_BEFORE_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_PROMISE_HOOK_BEFORE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_HOOK_BEFORE_FUNCTION_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> PROMISE_HOOK_AFTER_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_PROMISE_HOOK_AFTER_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_HOOK_AFTER_FUNCTION_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> PROMISE_HOOK_RESOLVE_FUNCTION_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_PROMISE_HOOK_RESOLVE_FUNCTION_INDEX_0(state_, Context::Field::PROMISE_HOOK_RESOLVE_FUNCTION_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> CONTINUATION_PRESERVED_EMBEDDER_DATA_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_CONTINUATION_PRESERVED_EMBEDDER_DATA_INDEX_0(state_, Context::Field::CONTINUATION_PRESERVED_EMBEDDER_DATA_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> BOUND_FUNCTION_WITH_CONSTRUCTOR_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_BOUND_FUNCTION_WITH_CONSTRUCTOR_MAP_INDEX_0(state_, Context::Field::BOUND_FUNCTION_WITH_CONSTRUCTOR_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> BOUND_FUNCTION_WITHOUT_CONSTRUCTOR_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_BOUND_FUNCTION_WITHOUT_CONSTRUCTOR_MAP_INDEX_0(state_, Context::Field::BOUND_FUNCTION_WITHOUT_CONSTRUCTOR_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> WRAPPED_FUNCTION_MAP_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_WRAPPED_FUNCTION_MAP_INDEX_0(state_, Context::Field::WRAPPED_FUNCTION_MAP_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=98&c=1
TNode<IntPtrT> CONTEXT_SIDE_TABLE_PROPERTY_INDEX_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_ContextSlot_constexpr_CONTEXT_SIDE_TABLE_PROPERTY_INDEX_0(state_, Context::Field::CONTEXT_SIDE_TABLE_PROPERTY_INDEX);
  TNode<IntPtrT> tmp1;
    tmp1 = (TNode<IntPtrT>{tmp0});
  return TNode<IntPtrT>{tmp1};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=196&c=1
TNode<Object> LoadContextElement_0(compiler::CodeAssemblerState* state_, TNode<Context> p_c, TNode<IntPtrT> p_i) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    tmp10 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp8, tmp9});
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<Object>{tmp10};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=201&c=1
TNode<Object> LoadContextElement_1(compiler::CodeAssemblerState* state_, TNode<Context> p_c, TNode<Smi> p_i) {
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
  TNode<IntPtrT> tmp3;
  TNode<UintPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<BoolT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp3 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp6 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp4}, TNode<UintPtrT>{tmp5});
    ca_.Branch(tmp6, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Object> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<Object> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp7 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp3});
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp7});
    std::tie(tmp9, tmp10) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp8}).Flatten();
    tmp11 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp9, tmp10});
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<Object>{tmp11};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=206&c=1
TNode<Object> LoadContextElement_2(compiler::CodeAssemblerState* state_, TNode<Context> p_c, int32_t p_i) {
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
  TNode<IntPtrT> tmp3;
  TNode<UintPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<BoolT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp3 = FromConstexpr_intptr_constexpr_int32_0(state_, p_i);
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp6 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp4}, TNode<UintPtrT>{tmp5});
    ca_.Branch(tmp6, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Object> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<Object> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp7 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp3});
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp7});
    std::tie(tmp9, tmp10) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp8}).Flatten();
    tmp11 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp9, tmp10});
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<Object>{tmp11};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=211&c=1
TNode<Object> LoadScriptContextElement_0(compiler::CodeAssemblerState* state_, TNode<Context> p_c, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = LoadScriptContextElementImpl_0(state_, TNode<Context>{p_c}, TNode<IntPtrT>{p_i});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=216&c=1
TNode<Object> LoadScriptContextElement_1(compiler::CodeAssemblerState* state_, TNode<Context> p_c, TNode<Smi> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{p_i});
    tmp1 = LoadScriptContextElementImpl_0(state_, TNode<Context>{p_c}, TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=221&c=1
TNode<Object> LoadScriptContextElement_2(compiler::CodeAssemblerState* state_, TNode<Context> p_c, int32_t p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int32_0(state_, p_i);
    tmp1 = LoadScriptContextElementImpl_0(state_, TNode<Context>{p_c}, TNode<IntPtrT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=226&c=1
void StoreContextElement_0(compiler::CodeAssemblerState* state_, TNode<Context> p_c, TNode<IntPtrT> p_i, TNode<Object> p_o) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp8, tmp9}, p_o);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=231&c=1
void StoreContextElement_1(compiler::CodeAssemblerState* state_, TNode<Context> p_c, TNode<Smi> p_i, TNode<Object> p_o) {
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
  TNode<IntPtrT> tmp3;
  TNode<UintPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<BoolT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp3 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp6 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp4}, TNode<UintPtrT>{tmp5});
    ca_.Branch(tmp6, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Object> tmp9;
  TNode<IntPtrT> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp7 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp3});
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp7});
    std::tie(tmp9, tmp10) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp8}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp10}, p_o);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=236&c=1
void StoreContextElement_2(compiler::CodeAssemblerState* state_, TNode<Context> p_c, int32_t p_i, TNode<Object> p_o) {
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
  TNode<IntPtrT> tmp3;
  TNode<UintPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<BoolT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp3 = FromConstexpr_intptr_constexpr_int32_0(state_, p_i);
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp6 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp4}, TNode<UintPtrT>{tmp5});
    ca_.Branch(tmp6, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Object> tmp9;
  TNode<IntPtrT> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp7 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp3});
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp7});
    std::tie(tmp9, tmp10) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp8}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp10}, p_o);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=241&c=1
void StoreContextElementAndUpdateSideData_0(compiler::CodeAssemblerState* state_, TNode<Context> p_c, TNode<IntPtrT> p_i, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    StoreScriptContextAndUpdateSlotProperty_0(state_, TNode<Context>{p_c}, TNode<IntPtrT>{p_i}, TNode<Object>{p_o});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=247&c=1
void StoreContextElementAndUpdateSideData_1(compiler::CodeAssemblerState* state_, TNode<Context> p_c, int32_t p_i, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int32_0(state_, p_i);
    StoreScriptContextAndUpdateSlotProperty_0(state_, TNode<Context>{p_c}, TNode<IntPtrT>{tmp0}, TNode<Object>{p_o});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TF_BUILTIN(AllocateIfMutableHeapNumberScriptContextSlot, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Object> parameter0 = UncheckedParameter<Object>(Descriptor::kN);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kC);
  USE(parameter1);
  TNode<Smi> parameter2 = UncheckedParameter<Smi>(Descriptor::kI);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapNumber> tmp0;
  TNode<Context> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TORQUE_CAST(TNode<Object>{parameter0});
    tmp1 = TORQUE_CAST(TNode<Object>{parameter1});
    tmp2 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{parameter2});
    tmp3 = IsMutableHeapNumber_0(state_, TNode<Context>{tmp1}, TNode<IntPtrT>{tmp2}, TNode<Object>{tmp0});
    ca_.Branch(tmp3, &block27, std::vector<compiler::Node*>{}, &block28, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp4;
  TNode<Float64T> tmp5;
  TNode<HeapNumber> tmp6;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp5 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp0, tmp4});
    tmp6 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp5});
    CodeStubAssembler(state_).Return(tmp6);
  }

  if (block28.is_used()) {
    ca_.Bind(&block28);
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(StoreCurrentScriptContextSlotBaseline, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Object> parameter0 = UncheckedParameter<Object>(Descriptor::kO);
  USE(parameter0);
  TNode<Smi> parameter1 = UncheckedParameter<Smi>(Descriptor::kI);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Undefined> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadContextFromBaseline();
    tmp1 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{parameter1});
    StoreScriptContextAndUpdateSlotProperty_0(state_, TNode<Context>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<Object>{parameter0});
    tmp2 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TF_BUILTIN(StoreScriptContextSlotBaseline, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Object> parameter0 = UncheckedParameter<Object>(Descriptor::kC);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kO);
  USE(parameter1);
  TNode<Smi> parameter2 = UncheckedParameter<Smi>(Descriptor::kI);
  USE(parameter2);
  TNode<TaggedIndex> parameter3 = UncheckedParameter<TaggedIndex>(Descriptor::kD);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, IntPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Context> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Context> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TORQUE_CAST(TNode<Object>{parameter0});
    tmp1 = CodeStubAssembler(state_).TaggedIndexToIntPtr(TNode<TaggedIndex>{parameter3});
    ca_.Goto(&block16, tmp0, tmp1);
  }

  TNode<Context> phi_bb16_4;
  TNode<IntPtrT> phi_bb16_5;
  TNode<IntPtrT> tmp2;
  TNode<BoolT> tmp3;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_4, &phi_bb16_5);
    tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb16_5}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp3, &block14, std::vector<compiler::Node*>{phi_bb16_4, phi_bb16_5}, &block15, std::vector<compiler::Node*>{phi_bb16_4, phi_bb16_5});
  }

  TNode<Context> phi_bb14_4;
  TNode<IntPtrT> phi_bb14_5;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<Object> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<UintPtrT> tmp10;
  TNode<UintPtrT> tmp11;
  TNode<BoolT> tmp12;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_4, &phi_bb14_5);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp5 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb14_5}, TNode<IntPtrT>{tmp4});
    std::tie(tmp6, tmp7, tmp8) = FieldSliceContextElements_0(state_, TNode<Context>{phi_bb14_4}).Flatten();
    tmp9 = PREVIOUS_INDEX_0(state_);
    tmp10 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp9});
    tmp11 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp8});
    tmp12 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp10}, TNode<UintPtrT>{tmp11});
    ca_.Branch(tmp12, &block21, std::vector<compiler::Node*>{phi_bb14_4, phi_bb14_4}, &block22, std::vector<compiler::Node*>{phi_bb14_4, phi_bb14_4});
  }

  TNode<Context> phi_bb21_4;
  TNode<Context> phi_bb21_6;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<Object> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<Object> tmp17;
  TNode<Context> tmp18;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_4, &phi_bb21_6);
    tmp13 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp9});
    tmp14 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp13});
    std::tie(tmp15, tmp16) = NewReference_Object_0(state_, TNode<Object>{tmp6}, TNode<IntPtrT>{tmp14}).Flatten();
    tmp17 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp15, tmp16});
    tmp18 = UnsafeCast_Context_0(state_, TNode<Context>{phi_bb21_4}, TNode<Object>{tmp17});
    ca_.Goto(&block16, tmp18, tmp5);
  }

  TNode<Context> phi_bb22_4;
  TNode<Context> phi_bb22_6;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_4, &phi_bb22_6);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Context> phi_bb15_4;
  TNode<IntPtrT> phi_bb15_5;
  TNode<IntPtrT> tmp19;
  TNode<Undefined> tmp20;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_4, &phi_bb15_5);
    tmp19 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{parameter2});
    StoreScriptContextAndUpdateSlotProperty_0(state_, TNode<Context>{phi_bb15_4}, TNode<IntPtrT>{tmp19}, TNode<Object>{parameter1});
    tmp20 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp20);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=291&c=1
void StoreScriptContextAndUpdateSlotProperty_0(compiler::CodeAssemblerState* state_, TNode<Context> p_c, TNode<IntPtrT> p_index, TNode<Object> p_newValue) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block69(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block80(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block79(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block76(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block75(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block81(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block91(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block90(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block93(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block92(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block88(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block86(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block84(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block99(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block100(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block107(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block106(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block109(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block108(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block104(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block114(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block115(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block85(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block124(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block123(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block120(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block118(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block130(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block131(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block119(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block138(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block139(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block125(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block146(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block147(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block94(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block82(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block154(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block155(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block162(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block163(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block166(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block175(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block174(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block171(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block169(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block181(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block182(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block170(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block191(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block190(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block187(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block185(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block186(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block199(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block198(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block201(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block200(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block196(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block194(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block192(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block207(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block208(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block215(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block214(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block217(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block216(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block212(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block222(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block223(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block193(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block230(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block231(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block238(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block239(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block202(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block176(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block167(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block242(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block249(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block248(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block251(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block250(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block246(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block258(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block257(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block254(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block252(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block263(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block262(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block253(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block271(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block270(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block273(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block272(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block268(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block266(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block264(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block279(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block278(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block281(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block280(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block276(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block265(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block288(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block287(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block284(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block282(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block283(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block293(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block294(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block301(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block302(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block274(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block259(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block243(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block317(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block318(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block244(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block168(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block73(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block321(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_ScriptContext_0(state_, TNode<HeapObject>{p_c}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Object> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<HeapObject> tmp7;
  TNode<HeapObject> tmp8;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = FromConstexpr_intptr_constexpr_intptr_0(state_, Context::Field::MIN_CONTEXT_EXTENDED_SLOTS);
    tmp3 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{p_index}, TNode<IntPtrT>{tmp2});
    tmp4 = CONTEXT_SIDE_TABLE_PROPERTY_INDEX_0(state_);
    std::tie(tmp5, tmp6) = ContextSlot_ScriptContext_Context_HeapObject_0(state_, TNode<Context>{tmp0}, TNode<IntPtrT>{tmp4}).Flatten();
    tmp7 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp5, tmp6});
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp7}, &label9);
    ca_.Goto(&block9);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block10);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block7);
  }

  TNode<FixedArray> tmp10;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    compiler::CodeAssemblerLabel label11(&ca_);
    tmp10 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp8}, &label11);
    ca_.Goto(&block11);
    if (label11.is_used()) {
      ca_.Bind(&label11);
      ca_.Goto(&block12);
    }
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block7);
  }

  TNode<IntPtrT> tmp12;
  TNode<Smi> tmp13;
  TNode<Smi> tmp14;
  TNode<BoolT> tmp15;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp13 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp10, tmp12});
    tmp14 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp15 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp13}, TNode<Smi>{tmp14});
    ca_.Branch(tmp15, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block1);
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  TNode<Object> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<UintPtrT> tmp19;
  TNode<UintPtrT> tmp20;
  TNode<BoolT> tmp21;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    std::tie(tmp16, tmp17, tmp18) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp19 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp20 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp18});
    tmp21 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp19}, TNode<UintPtrT>{tmp20});
    ca_.Branch(tmp21, &block19, std::vector<compiler::Node*>{}, &block20, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<Object> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<Object> tmp26;
  TNode<Hole> tmp27;
  TNode<BoolT> tmp28;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    tmp22 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp23 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp22});
    std::tie(tmp24, tmp25) = NewReference_Object_0(state_, TNode<Object>{tmp16}, TNode<IntPtrT>{tmp23}).Flatten();
    tmp26 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp24, tmp25});
    tmp27 = TheHole_0(state_);
    tmp28 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp26}, TNode<HeapObject>{tmp27});
    ca_.Branch(tmp28, &block23, std::vector<compiler::Node*>{}, &block24, std::vector<compiler::Node*>{});
  }

  if (block20.is_used()) {
    ca_.Bind(&block20);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<UintPtrT> tmp32;
  TNode<UintPtrT> tmp33;
  TNode<BoolT> tmp34;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    std::tie(tmp29, tmp30, tmp31) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp10}).Flatten();
    tmp32 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp33 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp31});
    tmp34 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp32}, TNode<UintPtrT>{tmp33});
    ca_.Branch(tmp34, &block41, std::vector<compiler::Node*>{}, &block42, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<Object> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<IntPtrT> tmp39;
  TNode<Smi> tmp40;
  TNode<Object> tmp41;
  TNode<IntPtrT> tmp42;
  TNode<IntPtrT> tmp43;
  TNode<UintPtrT> tmp44;
  TNode<UintPtrT> tmp45;
  TNode<BoolT> tmp46;
  if (block41.is_used()) {
    ca_.Bind(&block41);
    tmp35 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp3});
    tmp36 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp30}, TNode<IntPtrT>{tmp35});
    std::tie(tmp37, tmp38) = NewReference_Object_0(state_, TNode<Object>{tmp29}, TNode<IntPtrT>{tmp36}).Flatten();
    tmp39 = kContextSidePropertyConst_0(state_);
    tmp40 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp39});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp37, tmp38}, tmp40);
    std::tie(tmp41, tmp42, tmp43) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp44 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp45 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp43});
    tmp46 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp44}, TNode<UintPtrT>{tmp45});
    ca_.Branch(tmp46, &block49, std::vector<compiler::Node*>{}, &block50, std::vector<compiler::Node*>{});
  }

  if (block42.is_used()) {
    ca_.Bind(&block42);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp47;
  TNode<IntPtrT> tmp48;
  TNode<Object> tmp49;
  TNode<IntPtrT> tmp50;
  if (block49.is_used()) {
    ca_.Bind(&block49);
    tmp47 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp48 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp42}, TNode<IntPtrT>{tmp47});
    std::tie(tmp49, tmp50) = NewReference_Object_0(state_, TNode<Object>{tmp41}, TNode<IntPtrT>{tmp48}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp49, tmp50}, p_newValue);
    ca_.Goto(&block1);
  }

  if (block50.is_used()) {
    ca_.Bind(&block50);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<BoolT> tmp51;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    tmp51 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp26}, TNode<MaybeObject>{p_newValue});
    ca_.Branch(tmp51, &block53, std::vector<compiler::Node*>{}, &block54, std::vector<compiler::Node*>{});
  }

  if (block53.is_used()) {
    ca_.Bind(&block53);
    ca_.Goto(&block1);
  }

  TNode<Object> tmp52;
  TNode<IntPtrT> tmp53;
  TNode<IntPtrT> tmp54;
  TNode<UintPtrT> tmp55;
  TNode<UintPtrT> tmp56;
  TNode<BoolT> tmp57;
  if (block54.is_used()) {
    ca_.Bind(&block54);
    std::tie(tmp52, tmp53, tmp54) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp10}).Flatten();
    tmp55 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp56 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp54});
    tmp57 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp55}, TNode<UintPtrT>{tmp56});
    ca_.Branch(tmp57, &block59, std::vector<compiler::Node*>{}, &block60, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp58;
  TNode<IntPtrT> tmp59;
  TNode<Object> tmp60;
  TNode<IntPtrT> tmp61;
  TNode<Object> tmp62;
  TNode<Smi> tmp63;
  if (block59.is_used()) {
    ca_.Bind(&block59);
    tmp58 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp3});
    tmp59 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp53}, TNode<IntPtrT>{tmp58});
    std::tie(tmp60, tmp61) = NewReference_Object_0(state_, TNode<Object>{tmp52}, TNode<IntPtrT>{tmp59}).Flatten();
    tmp62 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp60, tmp61});
    compiler::CodeAssemblerLabel label64(&ca_);
    tmp63 = Cast_Smi_0(state_, TNode<Object>{tmp62}, &label64);
    ca_.Goto(&block65);
    if (label64.is_used()) {
      ca_.Bind(&label64);
      ca_.Goto(&block66);
    }
  }

  if (block60.is_used()) {
    ca_.Bind(&block60);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<ContextSidePropertyCell> tmp65;
  if (block66.is_used()) {
    ca_.Bind(&block66);
    compiler::CodeAssemblerLabel label66(&ca_);
    tmp65 = Cast_ContextSidePropertyCell_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp62)}, &label66);
    ca_.Goto(&block69);
    if (label66.is_used()) {
      ca_.Bind(&label66);
      ca_.Goto(&block70);
    }
  }

  TNode<Undefined> tmp67;
  TNode<IntPtrT> tmp68;
  if (block65.is_used()) {
    ca_.Bind(&block65);
    tmp67 = Undefined_0(state_);
    tmp68 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp63});
    ca_.Goto(&block63, tmp67, tmp68);
  }

  if (block70.is_used()) {
    ca_.Bind(&block70);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp69;
  TNode<Smi> tmp70;
  TNode<IntPtrT> tmp71;
  if (block69.is_used()) {
    ca_.Bind(&block69);
    tmp69 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp70 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp65, tmp69});
    tmp71 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp70});
    ca_.Goto(&block63, tmp65, tmp71);
  }

  TNode<HeapObject> phi_bb63_9;
  TNode<IntPtrT> phi_bb63_10;
  TNode<IntPtrT> tmp72;
  TNode<BoolT> tmp73;
  if (block63.is_used()) {
    ca_.Bind(&block63, &phi_bb63_9, &phi_bb63_10);
    tmp72 = kContextSidePropertyConst_0(state_);
    tmp73 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb63_10}, TNode<IntPtrT>{tmp72});
    ca_.Branch(tmp73, &block71, std::vector<compiler::Node*>{}, &block72, std::vector<compiler::Node*>{});
  }

  TNode<ContextSidePropertyCell> tmp74;
  if (block71.is_used()) {
    ca_.Bind(&block71);
    compiler::CodeAssemblerLabel label75(&ca_);
    tmp74 = Cast_ContextSidePropertyCell_0(state_, TNode<HeapObject>{phi_bb63_9}, &label75);
    ca_.Goto(&block79);
    if (label75.is_used()) {
      ca_.Bind(&label75);
      ca_.Goto(&block80);
    }
  }

  TNode<BoolT> tmp76;
  if (block80.is_used()) {
    ca_.Bind(&block80);
    tmp76 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block76, tmp76);
  }

  TNode<BoolT> tmp77;
  if (block79.is_used()) {
    ca_.Bind(&block79);
    tmp77 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block76, tmp77);
  }

  TNode<BoolT> phi_bb76_13;
  if (block76.is_used()) {
    ca_.Bind(&block76, &phi_bb76_13);
    ca_.Branch(phi_bb76_13, &block74, std::vector<compiler::Node*>{}, &block75, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp78;
  if (block74.is_used()) {
    ca_.Bind(&block74);
    tmp78 = CodeStubAssembler(state_).CallRuntime(Runtime::kInvalidateDependentCodeForScriptContextSlot, p_c, phi_bb63_9); 
    ca_.Goto(&block75);
  }

  TNode<BoolT> tmp79;
  if (block75.is_used()) {
    ca_.Bind(&block75);
    tmp79 = CodeStubAssembler(state_).IsScriptContextMutableHeapNumberFlag();
    ca_.Branch(tmp79, &block81, std::vector<compiler::Node*>{}, &block82, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp80;
  if (block81.is_used()) {
    ca_.Bind(&block81);
    compiler::CodeAssemblerLabel label81(&ca_);
    tmp80 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_newValue}, &label81);
    ca_.Goto(&block90);
    if (label81.is_used()) {
      ca_.Bind(&label81);
      ca_.Goto(&block91);
    }
  }

  if (block91.is_used()) {
    ca_.Bind(&block91);
    ca_.Goto(&block88);
  }

  TNode<HeapNumber> tmp82;
  if (block90.is_used()) {
    ca_.Bind(&block90);
    compiler::CodeAssemblerLabel label83(&ca_);
    tmp82 = Cast_HeapNumber_0(state_, TNode<HeapObject>{tmp80}, &label83);
    ca_.Goto(&block92);
    if (label83.is_used()) {
      ca_.Bind(&label83);
      ca_.Goto(&block93);
    }
  }

  if (block93.is_used()) {
    ca_.Bind(&block93);
    ca_.Goto(&block88);
  }

  TNode<BoolT> tmp84;
  if (block92.is_used()) {
    ca_.Bind(&block92);
    tmp84 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block86, tmp84);
  }

  TNode<BoolT> tmp85;
  if (block88.is_used()) {
    ca_.Bind(&block88);
    tmp85 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block86, tmp85);
  }

  TNode<BoolT> phi_bb86_13;
  if (block86.is_used()) {
    ca_.Bind(&block86, &phi_bb86_13);
    ca_.Branch(phi_bb86_13, &block84, std::vector<compiler::Node*>{}, &block85, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp86;
  TNode<IntPtrT> tmp87;
  TNode<IntPtrT> tmp88;
  TNode<UintPtrT> tmp89;
  TNode<UintPtrT> tmp90;
  TNode<BoolT> tmp91;
  if (block84.is_used()) {
    ca_.Bind(&block84);
    std::tie(tmp86, tmp87, tmp88) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp10}).Flatten();
    tmp89 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp90 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp88});
    tmp91 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp89}, TNode<UintPtrT>{tmp90});
    ca_.Branch(tmp91, &block99, std::vector<compiler::Node*>{}, &block100, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp92;
  TNode<IntPtrT> tmp93;
  TNode<Object> tmp94;
  TNode<IntPtrT> tmp95;
  TNode<IntPtrT> tmp96;
  TNode<Smi> tmp97;
  TNode<HeapObject> tmp98;
  if (block99.is_used()) {
    ca_.Bind(&block99);
    tmp92 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp3});
    tmp93 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp87}, TNode<IntPtrT>{tmp92});
    std::tie(tmp94, tmp95) = NewReference_Object_0(state_, TNode<Object>{tmp86}, TNode<IntPtrT>{tmp93}).Flatten();
    tmp96 = kContextSidePropertyHeapNumber_0(state_);
    tmp97 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp96});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp94, tmp95}, tmp97);
    compiler::CodeAssemblerLabel label99(&ca_);
    tmp98 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_newValue}, &label99);
    ca_.Goto(&block106);
    if (label99.is_used()) {
      ca_.Bind(&label99);
      ca_.Goto(&block107);
    }
  }

  if (block100.is_used()) {
    ca_.Bind(&block100);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block107.is_used()) {
    ca_.Bind(&block107);
    ca_.Goto(&block104);
  }

  TNode<HeapNumber> tmp100;
  if (block106.is_used()) {
    ca_.Bind(&block106);
    compiler::CodeAssemblerLabel label101(&ca_);
    tmp100 = Cast_HeapNumber_0(state_, TNode<HeapObject>{tmp98}, &label101);
    ca_.Goto(&block108);
    if (label101.is_used()) {
      ca_.Bind(&label101);
      ca_.Goto(&block109);
    }
  }

  if (block109.is_used()) {
    ca_.Bind(&block109);
    ca_.Goto(&block104);
  }

  TNode<Object> tmp102;
  TNode<IntPtrT> tmp103;
  TNode<IntPtrT> tmp104;
  TNode<UintPtrT> tmp105;
  TNode<UintPtrT> tmp106;
  TNode<BoolT> tmp107;
  if (block108.is_used()) {
    ca_.Bind(&block108);
    std::tie(tmp102, tmp103, tmp104) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp105 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp106 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp104});
    tmp107 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp105}, TNode<UintPtrT>{tmp106});
    ca_.Branch(tmp107, &block114, std::vector<compiler::Node*>{}, &block115, std::vector<compiler::Node*>{});
  }

  if (block104.is_used()) {
    ca_.Bind(&block104);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp108;
  TNode<IntPtrT> tmp109;
  TNode<Object> tmp110;
  TNode<IntPtrT> tmp111;
  TNode<IntPtrT> tmp112;
  TNode<Float64T> tmp113;
  TNode<HeapNumber> tmp114;
  if (block114.is_used()) {
    ca_.Bind(&block114);
    tmp108 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp109 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp103}, TNode<IntPtrT>{tmp108});
    std::tie(tmp110, tmp111) = NewReference_Object_0(state_, TNode<Object>{tmp102}, TNode<IntPtrT>{tmp109}).Flatten();
    tmp112 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp113 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp100, tmp112});
    tmp114 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp113});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp110, tmp111}, tmp114);
    ca_.Goto(&block94);
  }

  if (block115.is_used()) {
    ca_.Bind(&block115);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Smi> tmp115;
  if (block85.is_used()) {
    ca_.Bind(&block85);
    compiler::CodeAssemblerLabel label116(&ca_);
    tmp115 = Cast_Smi_0(state_, TNode<Object>{p_newValue}, &label116);
    ca_.Goto(&block123);
    if (label116.is_used()) {
      ca_.Bind(&label116);
      ca_.Goto(&block124);
    }
  }

  TNode<BoolT> tmp117;
  if (block124.is_used()) {
    ca_.Bind(&block124);
    tmp117 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block120, tmp117);
  }

  TNode<BoolT> tmp118;
  if (block123.is_used()) {
    ca_.Bind(&block123);
    tmp118 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block120, tmp118);
  }

  TNode<BoolT> phi_bb120_13;
  if (block120.is_used()) {
    ca_.Bind(&block120, &phi_bb120_13);
    ca_.Branch(phi_bb120_13, &block118, std::vector<compiler::Node*>{}, &block119, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp119;
  TNode<IntPtrT> tmp120;
  TNode<IntPtrT> tmp121;
  TNode<UintPtrT> tmp122;
  TNode<UintPtrT> tmp123;
  TNode<BoolT> tmp124;
  if (block118.is_used()) {
    ca_.Bind(&block118);
    std::tie(tmp119, tmp120, tmp121) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp10}).Flatten();
    tmp122 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp123 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp121});
    tmp124 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp122}, TNode<UintPtrT>{tmp123});
    ca_.Branch(tmp124, &block130, std::vector<compiler::Node*>{}, &block131, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp125;
  TNode<IntPtrT> tmp126;
  TNode<Object> tmp127;
  TNode<IntPtrT> tmp128;
  TNode<IntPtrT> tmp129;
  TNode<Smi> tmp130;
  if (block130.is_used()) {
    ca_.Bind(&block130);
    tmp125 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp3});
    tmp126 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp120}, TNode<IntPtrT>{tmp125});
    std::tie(tmp127, tmp128) = NewReference_Object_0(state_, TNode<Object>{tmp119}, TNode<IntPtrT>{tmp126}).Flatten();
    tmp129 = kContextSidePropertySmi_0(state_);
    tmp130 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp129});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp127, tmp128}, tmp130);
    ca_.Goto(&block125);
  }

  if (block131.is_used()) {
    ca_.Bind(&block131);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> tmp131;
  TNode<IntPtrT> tmp132;
  TNode<IntPtrT> tmp133;
  TNode<UintPtrT> tmp134;
  TNode<UintPtrT> tmp135;
  TNode<BoolT> tmp136;
  if (block119.is_used()) {
    ca_.Bind(&block119);
    std::tie(tmp131, tmp132, tmp133) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp10}).Flatten();
    tmp134 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp135 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp133});
    tmp136 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp134}, TNode<UintPtrT>{tmp135});
    ca_.Branch(tmp136, &block138, std::vector<compiler::Node*>{}, &block139, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp137;
  TNode<IntPtrT> tmp138;
  TNode<Object> tmp139;
  TNode<IntPtrT> tmp140;
  TNode<IntPtrT> tmp141;
  TNode<Smi> tmp142;
  if (block138.is_used()) {
    ca_.Bind(&block138);
    tmp137 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp3});
    tmp138 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp132}, TNode<IntPtrT>{tmp137});
    std::tie(tmp139, tmp140) = NewReference_Object_0(state_, TNode<Object>{tmp131}, TNode<IntPtrT>{tmp138}).Flatten();
    tmp141 = kContextSidePropertyOther_0(state_);
    tmp142 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp141});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp139, tmp140}, tmp142);
    ca_.Goto(&block125);
  }

  if (block139.is_used()) {
    ca_.Bind(&block139);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> tmp143;
  TNode<IntPtrT> tmp144;
  TNode<IntPtrT> tmp145;
  TNode<UintPtrT> tmp146;
  TNode<UintPtrT> tmp147;
  TNode<BoolT> tmp148;
  if (block125.is_used()) {
    ca_.Bind(&block125);
    std::tie(tmp143, tmp144, tmp145) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp146 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp147 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp145});
    tmp148 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp146}, TNode<UintPtrT>{tmp147});
    ca_.Branch(tmp148, &block146, std::vector<compiler::Node*>{}, &block147, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp149;
  TNode<IntPtrT> tmp150;
  TNode<Object> tmp151;
  TNode<IntPtrT> tmp152;
  if (block146.is_used()) {
    ca_.Bind(&block146);
    tmp149 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp150 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp144}, TNode<IntPtrT>{tmp149});
    std::tie(tmp151, tmp152) = NewReference_Object_0(state_, TNode<Object>{tmp143}, TNode<IntPtrT>{tmp150}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp151, tmp152}, p_newValue);
    ca_.Goto(&block94);
  }

  if (block147.is_used()) {
    ca_.Bind(&block147);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block94.is_used()) {
    ca_.Bind(&block94);
    ca_.Goto(&block83);
  }

  TNode<Object> tmp153;
  TNode<IntPtrT> tmp154;
  TNode<IntPtrT> tmp155;
  TNode<UintPtrT> tmp156;
  TNode<UintPtrT> tmp157;
  TNode<BoolT> tmp158;
  if (block82.is_used()) {
    ca_.Bind(&block82);
    std::tie(tmp153, tmp154, tmp155) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp10}).Flatten();
    tmp156 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp157 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp155});
    tmp158 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp156}, TNode<UintPtrT>{tmp157});
    ca_.Branch(tmp158, &block154, std::vector<compiler::Node*>{}, &block155, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp159;
  TNode<IntPtrT> tmp160;
  TNode<Object> tmp161;
  TNode<IntPtrT> tmp162;
  TNode<IntPtrT> tmp163;
  TNode<Smi> tmp164;
  TNode<Object> tmp165;
  TNode<IntPtrT> tmp166;
  TNode<IntPtrT> tmp167;
  TNode<UintPtrT> tmp168;
  TNode<UintPtrT> tmp169;
  TNode<BoolT> tmp170;
  if (block154.is_used()) {
    ca_.Bind(&block154);
    tmp159 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp3});
    tmp160 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp154}, TNode<IntPtrT>{tmp159});
    std::tie(tmp161, tmp162) = NewReference_Object_0(state_, TNode<Object>{tmp153}, TNode<IntPtrT>{tmp160}).Flatten();
    tmp163 = kContextSidePropertyOther_0(state_);
    tmp164 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp163});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp161, tmp162}, tmp164);
    std::tie(tmp165, tmp166, tmp167) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp168 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp169 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp167});
    tmp170 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp168}, TNode<UintPtrT>{tmp169});
    ca_.Branch(tmp170, &block162, std::vector<compiler::Node*>{}, &block163, std::vector<compiler::Node*>{});
  }

  if (block155.is_used()) {
    ca_.Bind(&block155);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp171;
  TNode<IntPtrT> tmp172;
  TNode<Object> tmp173;
  TNode<IntPtrT> tmp174;
  if (block162.is_used()) {
    ca_.Bind(&block162);
    tmp171 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp172 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp166}, TNode<IntPtrT>{tmp171});
    std::tie(tmp173, tmp174) = NewReference_Object_0(state_, TNode<Object>{tmp165}, TNode<IntPtrT>{tmp172}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp173, tmp174}, p_newValue);
    ca_.Goto(&block83);
  }

  if (block163.is_used()) {
    ca_.Bind(&block163);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block83.is_used()) {
    ca_.Bind(&block83);
    ca_.Goto(&block73);
  }

  TNode<IntPtrT> tmp175;
  TNode<BoolT> tmp176;
  if (block72.is_used()) {
    ca_.Bind(&block72);
    tmp175 = kContextSidePropertySmi_0(state_);
    tmp176 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb63_10}, TNode<IntPtrT>{tmp175});
    ca_.Branch(tmp176, &block166, std::vector<compiler::Node*>{}, &block167, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp177;
  if (block166.is_used()) {
    ca_.Bind(&block166);
    compiler::CodeAssemblerLabel label178(&ca_);
    tmp177 = Cast_Smi_0(state_, TNode<Object>{p_newValue}, &label178);
    ca_.Goto(&block174);
    if (label178.is_used()) {
      ca_.Bind(&label178);
      ca_.Goto(&block175);
    }
  }

  TNode<BoolT> tmp179;
  if (block175.is_used()) {
    ca_.Bind(&block175);
    tmp179 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block171, tmp179);
  }

  TNode<BoolT> tmp180;
  if (block174.is_used()) {
    ca_.Bind(&block174);
    tmp180 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block171, tmp180);
  }

  TNode<BoolT> phi_bb171_13;
  if (block171.is_used()) {
    ca_.Bind(&block171, &phi_bb171_13);
    ca_.Branch(phi_bb171_13, &block169, std::vector<compiler::Node*>{}, &block170, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp181;
  TNode<IntPtrT> tmp182;
  TNode<IntPtrT> tmp183;
  TNode<UintPtrT> tmp184;
  TNode<UintPtrT> tmp185;
  TNode<BoolT> tmp186;
  if (block169.is_used()) {
    ca_.Bind(&block169);
    std::tie(tmp181, tmp182, tmp183) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp184 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp185 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp183});
    tmp186 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp184}, TNode<UintPtrT>{tmp185});
    ca_.Branch(tmp186, &block181, std::vector<compiler::Node*>{}, &block182, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp187;
  TNode<IntPtrT> tmp188;
  TNode<Object> tmp189;
  TNode<IntPtrT> tmp190;
  if (block181.is_used()) {
    ca_.Bind(&block181);
    tmp187 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp188 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp182}, TNode<IntPtrT>{tmp187});
    std::tie(tmp189, tmp190) = NewReference_Object_0(state_, TNode<Object>{tmp181}, TNode<IntPtrT>{tmp188}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp189, tmp190}, p_newValue);
    ca_.Goto(&block176);
  }

  if (block182.is_used()) {
    ca_.Bind(&block182);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<ContextSidePropertyCell> tmp191;
  if (block170.is_used()) {
    ca_.Bind(&block170);
    compiler::CodeAssemblerLabel label192(&ca_);
    tmp191 = Cast_ContextSidePropertyCell_0(state_, TNode<HeapObject>{phi_bb63_9}, &label192);
    ca_.Goto(&block190);
    if (label192.is_used()) {
      ca_.Bind(&label192);
      ca_.Goto(&block191);
    }
  }

  TNode<BoolT> tmp193;
  if (block191.is_used()) {
    ca_.Bind(&block191);
    tmp193 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block187, tmp193);
  }

  TNode<BoolT> tmp194;
  if (block190.is_used()) {
    ca_.Bind(&block190);
    tmp194 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block187, tmp194);
  }

  TNode<BoolT> phi_bb187_13;
  if (block187.is_used()) {
    ca_.Bind(&block187, &phi_bb187_13);
    ca_.Branch(phi_bb187_13, &block185, std::vector<compiler::Node*>{}, &block186, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp195;
  if (block185.is_used()) {
    ca_.Bind(&block185);
    tmp195 = CodeStubAssembler(state_).CallRuntime(Runtime::kInvalidateDependentCodeForScriptContextSlot, p_c, phi_bb63_9); 
    ca_.Goto(&block186);
  }

  TNode<HeapObject> tmp196;
  if (block186.is_used()) {
    ca_.Bind(&block186);
    compiler::CodeAssemblerLabel label197(&ca_);
    tmp196 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_newValue}, &label197);
    ca_.Goto(&block198);
    if (label197.is_used()) {
      ca_.Bind(&label197);
      ca_.Goto(&block199);
    }
  }

  if (block199.is_used()) {
    ca_.Bind(&block199);
    ca_.Goto(&block196);
  }

  TNode<HeapNumber> tmp198;
  if (block198.is_used()) {
    ca_.Bind(&block198);
    compiler::CodeAssemblerLabel label199(&ca_);
    tmp198 = Cast_HeapNumber_0(state_, TNode<HeapObject>{tmp196}, &label199);
    ca_.Goto(&block200);
    if (label199.is_used()) {
      ca_.Bind(&label199);
      ca_.Goto(&block201);
    }
  }

  if (block201.is_used()) {
    ca_.Bind(&block201);
    ca_.Goto(&block196);
  }

  TNode<BoolT> tmp200;
  if (block200.is_used()) {
    ca_.Bind(&block200);
    tmp200 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block194, tmp200);
  }

  TNode<BoolT> tmp201;
  if (block196.is_used()) {
    ca_.Bind(&block196);
    tmp201 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block194, tmp201);
  }

  TNode<BoolT> phi_bb194_13;
  if (block194.is_used()) {
    ca_.Bind(&block194, &phi_bb194_13);
    ca_.Branch(phi_bb194_13, &block192, std::vector<compiler::Node*>{}, &block193, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp202;
  TNode<IntPtrT> tmp203;
  TNode<IntPtrT> tmp204;
  TNode<UintPtrT> tmp205;
  TNode<UintPtrT> tmp206;
  TNode<BoolT> tmp207;
  if (block192.is_used()) {
    ca_.Bind(&block192);
    std::tie(tmp202, tmp203, tmp204) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp10}).Flatten();
    tmp205 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp206 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp204});
    tmp207 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp205}, TNode<UintPtrT>{tmp206});
    ca_.Branch(tmp207, &block207, std::vector<compiler::Node*>{}, &block208, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp208;
  TNode<IntPtrT> tmp209;
  TNode<Object> tmp210;
  TNode<IntPtrT> tmp211;
  TNode<IntPtrT> tmp212;
  TNode<Smi> tmp213;
  TNode<HeapObject> tmp214;
  if (block207.is_used()) {
    ca_.Bind(&block207);
    tmp208 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp3});
    tmp209 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp203}, TNode<IntPtrT>{tmp208});
    std::tie(tmp210, tmp211) = NewReference_Object_0(state_, TNode<Object>{tmp202}, TNode<IntPtrT>{tmp209}).Flatten();
    tmp212 = kContextSidePropertyHeapNumber_0(state_);
    tmp213 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp212});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp210, tmp211}, tmp213);
    compiler::CodeAssemblerLabel label215(&ca_);
    tmp214 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_newValue}, &label215);
    ca_.Goto(&block214);
    if (label215.is_used()) {
      ca_.Bind(&label215);
      ca_.Goto(&block215);
    }
  }

  if (block208.is_used()) {
    ca_.Bind(&block208);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block215.is_used()) {
    ca_.Bind(&block215);
    ca_.Goto(&block212);
  }

  TNode<HeapNumber> tmp216;
  if (block214.is_used()) {
    ca_.Bind(&block214);
    compiler::CodeAssemblerLabel label217(&ca_);
    tmp216 = Cast_HeapNumber_0(state_, TNode<HeapObject>{tmp214}, &label217);
    ca_.Goto(&block216);
    if (label217.is_used()) {
      ca_.Bind(&label217);
      ca_.Goto(&block217);
    }
  }

  if (block217.is_used()) {
    ca_.Bind(&block217);
    ca_.Goto(&block212);
  }

  TNode<Object> tmp218;
  TNode<IntPtrT> tmp219;
  TNode<IntPtrT> tmp220;
  TNode<UintPtrT> tmp221;
  TNode<UintPtrT> tmp222;
  TNode<BoolT> tmp223;
  if (block216.is_used()) {
    ca_.Bind(&block216);
    std::tie(tmp218, tmp219, tmp220) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp221 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp222 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp220});
    tmp223 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp221}, TNode<UintPtrT>{tmp222});
    ca_.Branch(tmp223, &block222, std::vector<compiler::Node*>{}, &block223, std::vector<compiler::Node*>{});
  }

  if (block212.is_used()) {
    ca_.Bind(&block212);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp224;
  TNode<IntPtrT> tmp225;
  TNode<Object> tmp226;
  TNode<IntPtrT> tmp227;
  TNode<IntPtrT> tmp228;
  TNode<Float64T> tmp229;
  TNode<HeapNumber> tmp230;
  if (block222.is_used()) {
    ca_.Bind(&block222);
    tmp224 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp225 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp219}, TNode<IntPtrT>{tmp224});
    std::tie(tmp226, tmp227) = NewReference_Object_0(state_, TNode<Object>{tmp218}, TNode<IntPtrT>{tmp225}).Flatten();
    tmp228 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp229 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp216, tmp228});
    tmp230 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp229});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp226, tmp227}, tmp230);
    ca_.Goto(&block202);
  }

  if (block223.is_used()) {
    ca_.Bind(&block223);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> tmp231;
  TNode<IntPtrT> tmp232;
  TNode<IntPtrT> tmp233;
  TNode<UintPtrT> tmp234;
  TNode<UintPtrT> tmp235;
  TNode<BoolT> tmp236;
  if (block193.is_used()) {
    ca_.Bind(&block193);
    std::tie(tmp231, tmp232, tmp233) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp10}).Flatten();
    tmp234 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp235 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp233});
    tmp236 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp234}, TNode<UintPtrT>{tmp235});
    ca_.Branch(tmp236, &block230, std::vector<compiler::Node*>{}, &block231, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp237;
  TNode<IntPtrT> tmp238;
  TNode<Object> tmp239;
  TNode<IntPtrT> tmp240;
  TNode<IntPtrT> tmp241;
  TNode<Smi> tmp242;
  TNode<Object> tmp243;
  TNode<IntPtrT> tmp244;
  TNode<IntPtrT> tmp245;
  TNode<UintPtrT> tmp246;
  TNode<UintPtrT> tmp247;
  TNode<BoolT> tmp248;
  if (block230.is_used()) {
    ca_.Bind(&block230);
    tmp237 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp3});
    tmp238 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp232}, TNode<IntPtrT>{tmp237});
    std::tie(tmp239, tmp240) = NewReference_Object_0(state_, TNode<Object>{tmp231}, TNode<IntPtrT>{tmp238}).Flatten();
    tmp241 = kContextSidePropertyOther_0(state_);
    tmp242 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp241});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp239, tmp240}, tmp242);
    std::tie(tmp243, tmp244, tmp245) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp246 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp247 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp245});
    tmp248 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp246}, TNode<UintPtrT>{tmp247});
    ca_.Branch(tmp248, &block238, std::vector<compiler::Node*>{}, &block239, std::vector<compiler::Node*>{});
  }

  if (block231.is_used()) {
    ca_.Bind(&block231);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp249;
  TNode<IntPtrT> tmp250;
  TNode<Object> tmp251;
  TNode<IntPtrT> tmp252;
  if (block238.is_used()) {
    ca_.Bind(&block238);
    tmp249 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp250 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp244}, TNode<IntPtrT>{tmp249});
    std::tie(tmp251, tmp252) = NewReference_Object_0(state_, TNode<Object>{tmp243}, TNode<IntPtrT>{tmp250}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp251, tmp252}, p_newValue);
    ca_.Goto(&block202);
  }

  if (block239.is_used()) {
    ca_.Bind(&block239);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block202.is_used()) {
    ca_.Bind(&block202);
    ca_.Goto(&block176);
  }

  if (block176.is_used()) {
    ca_.Bind(&block176);
    ca_.Goto(&block168);
  }

  TNode<IntPtrT> tmp253;
  TNode<BoolT> tmp254;
  if (block167.is_used()) {
    ca_.Bind(&block167);
    tmp253 = kContextSidePropertyHeapNumber_0(state_);
    tmp254 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb63_10}, TNode<IntPtrT>{tmp253});
    ca_.Branch(tmp254, &block242, std::vector<compiler::Node*>{}, &block243, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp255;
  if (block242.is_used()) {
    ca_.Bind(&block242);
    compiler::CodeAssemblerLabel label256(&ca_);
    tmp255 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp26}, &label256);
    ca_.Goto(&block248);
    if (label256.is_used()) {
      ca_.Bind(&label256);
      ca_.Goto(&block249);
    }
  }

  if (block249.is_used()) {
    ca_.Bind(&block249);
    ca_.Goto(&block246);
  }

  TNode<HeapNumber> tmp257;
  if (block248.is_used()) {
    ca_.Bind(&block248);
    compiler::CodeAssemblerLabel label258(&ca_);
    tmp257 = Cast_HeapNumber_0(state_, TNode<HeapObject>{tmp255}, &label258);
    ca_.Goto(&block250);
    if (label258.is_used()) {
      ca_.Bind(&label258);
      ca_.Goto(&block251);
    }
  }

  if (block251.is_used()) {
    ca_.Bind(&block251);
    ca_.Goto(&block246);
  }

  TNode<Smi> tmp259;
  if (block250.is_used()) {
    ca_.Bind(&block250);
    compiler::CodeAssemblerLabel label260(&ca_);
    tmp259 = Cast_Smi_0(state_, TNode<Object>{p_newValue}, &label260);
    ca_.Goto(&block257);
    if (label260.is_used()) {
      ca_.Bind(&label260);
      ca_.Goto(&block258);
    }
  }

  if (block246.is_used()) {
    ca_.Bind(&block246);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<BoolT> tmp261;
  if (block258.is_used()) {
    ca_.Bind(&block258);
    tmp261 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block254, tmp261);
  }

  TNode<BoolT> tmp262;
  if (block257.is_used()) {
    ca_.Bind(&block257);
    tmp262 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block254, tmp262);
  }

  TNode<BoolT> phi_bb254_14;
  if (block254.is_used()) {
    ca_.Bind(&block254, &phi_bb254_14);
    ca_.Branch(phi_bb254_14, &block252, std::vector<compiler::Node*>{}, &block253, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp263;
  if (block252.is_used()) {
    ca_.Bind(&block252);
    compiler::CodeAssemblerLabel label264(&ca_);
    tmp263 = Cast_Smi_0(state_, TNode<Object>{p_newValue}, &label264);
    ca_.Goto(&block262);
    if (label264.is_used()) {
      ca_.Bind(&label264);
      ca_.Goto(&block263);
    }
  }

  if (block263.is_used()) {
    ca_.Bind(&block263);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp265;
  TNode<Float64T> tmp266;
  TNode<Float64T> tmp267;
  if (block262.is_used()) {
    ca_.Bind(&block262);
    tmp265 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp266 = CodeStubAssembler(state_).SmiToFloat64(TNode<Smi>{tmp263});
    tmp267 = CodeStubAssembler(state_).Float64SilenceNaN(TNode<Float64T>{tmp266});
    CodeStubAssembler(state_).StoreReference<Float64T>(CodeStubAssembler::Reference{tmp257, tmp265}, tmp267);
    ca_.Goto(&block259);
  }

  TNode<HeapObject> tmp268;
  if (block253.is_used()) {
    ca_.Bind(&block253);
    compiler::CodeAssemblerLabel label269(&ca_);
    tmp268 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_newValue}, &label269);
    ca_.Goto(&block270);
    if (label269.is_used()) {
      ca_.Bind(&label269);
      ca_.Goto(&block271);
    }
  }

  if (block271.is_used()) {
    ca_.Bind(&block271);
    ca_.Goto(&block268);
  }

  TNode<HeapNumber> tmp270;
  if (block270.is_used()) {
    ca_.Bind(&block270);
    compiler::CodeAssemblerLabel label271(&ca_);
    tmp270 = Cast_HeapNumber_0(state_, TNode<HeapObject>{tmp268}, &label271);
    ca_.Goto(&block272);
    if (label271.is_used()) {
      ca_.Bind(&label271);
      ca_.Goto(&block273);
    }
  }

  if (block273.is_used()) {
    ca_.Bind(&block273);
    ca_.Goto(&block268);
  }

  TNode<BoolT> tmp272;
  if (block272.is_used()) {
    ca_.Bind(&block272);
    tmp272 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block266, tmp272);
  }

  TNode<BoolT> tmp273;
  if (block268.is_used()) {
    ca_.Bind(&block268);
    tmp273 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block266, tmp273);
  }

  TNode<BoolT> phi_bb266_14;
  if (block266.is_used()) {
    ca_.Bind(&block266, &phi_bb266_14);
    ca_.Branch(phi_bb266_14, &block264, std::vector<compiler::Node*>{}, &block265, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp274;
  if (block264.is_used()) {
    ca_.Bind(&block264);
    compiler::CodeAssemblerLabel label275(&ca_);
    tmp274 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_newValue}, &label275);
    ca_.Goto(&block278);
    if (label275.is_used()) {
      ca_.Bind(&label275);
      ca_.Goto(&block279);
    }
  }

  if (block279.is_used()) {
    ca_.Bind(&block279);
    ca_.Goto(&block276);
  }

  TNode<HeapNumber> tmp276;
  if (block278.is_used()) {
    ca_.Bind(&block278);
    compiler::CodeAssemblerLabel label277(&ca_);
    tmp276 = Cast_HeapNumber_0(state_, TNode<HeapObject>{tmp274}, &label277);
    ca_.Goto(&block280);
    if (label277.is_used()) {
      ca_.Bind(&label277);
      ca_.Goto(&block281);
    }
  }

  if (block281.is_used()) {
    ca_.Bind(&block281);
    ca_.Goto(&block276);
  }

  TNode<IntPtrT> tmp278;
  TNode<IntPtrT> tmp279;
  TNode<Float64T> tmp280;
  TNode<Float64T> tmp281;
  if (block280.is_used()) {
    ca_.Bind(&block280);
    tmp278 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp279 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp280 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp276, tmp279});
    tmp281 = CodeStubAssembler(state_).Float64SilenceNaN(TNode<Float64T>{tmp280});
    CodeStubAssembler(state_).StoreReference<Float64T>(CodeStubAssembler::Reference{tmp257, tmp278}, tmp281);
    ca_.Goto(&block274);
  }

  if (block276.is_used()) {
    ca_.Bind(&block276);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<ContextSidePropertyCell> tmp282;
  if (block265.is_used()) {
    ca_.Bind(&block265);
    compiler::CodeAssemblerLabel label283(&ca_);
    tmp282 = Cast_ContextSidePropertyCell_0(state_, TNode<HeapObject>{phi_bb63_9}, &label283);
    ca_.Goto(&block287);
    if (label283.is_used()) {
      ca_.Bind(&label283);
      ca_.Goto(&block288);
    }
  }

  TNode<BoolT> tmp284;
  if (block288.is_used()) {
    ca_.Bind(&block288);
    tmp284 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block284, tmp284);
  }

  TNode<BoolT> tmp285;
  if (block287.is_used()) {
    ca_.Bind(&block287);
    tmp285 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block284, tmp285);
  }

  TNode<BoolT> phi_bb284_14;
  if (block284.is_used()) {
    ca_.Bind(&block284, &phi_bb284_14);
    ca_.Branch(phi_bb284_14, &block282, std::vector<compiler::Node*>{}, &block283, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp286;
  if (block282.is_used()) {
    ca_.Bind(&block282);
    tmp286 = CodeStubAssembler(state_).CallRuntime(Runtime::kInvalidateDependentCodeForScriptContextSlot, p_c, phi_bb63_9); 
    ca_.Goto(&block283);
  }

  TNode<Object> tmp287;
  TNode<IntPtrT> tmp288;
  TNode<IntPtrT> tmp289;
  TNode<UintPtrT> tmp290;
  TNode<UintPtrT> tmp291;
  TNode<BoolT> tmp292;
  if (block283.is_used()) {
    ca_.Bind(&block283);
    std::tie(tmp287, tmp288, tmp289) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp10}).Flatten();
    tmp290 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp291 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp289});
    tmp292 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp290}, TNode<UintPtrT>{tmp291});
    ca_.Branch(tmp292, &block293, std::vector<compiler::Node*>{}, &block294, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp293;
  TNode<IntPtrT> tmp294;
  TNode<Object> tmp295;
  TNode<IntPtrT> tmp296;
  TNode<IntPtrT> tmp297;
  TNode<Smi> tmp298;
  TNode<Object> tmp299;
  TNode<IntPtrT> tmp300;
  TNode<IntPtrT> tmp301;
  TNode<UintPtrT> tmp302;
  TNode<UintPtrT> tmp303;
  TNode<BoolT> tmp304;
  if (block293.is_used()) {
    ca_.Bind(&block293);
    tmp293 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp3});
    tmp294 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp288}, TNode<IntPtrT>{tmp293});
    std::tie(tmp295, tmp296) = NewReference_Object_0(state_, TNode<Object>{tmp287}, TNode<IntPtrT>{tmp294}).Flatten();
    tmp297 = kContextSidePropertyOther_0(state_);
    tmp298 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp297});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp295, tmp296}, tmp298);
    std::tie(tmp299, tmp300, tmp301) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp302 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp303 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp301});
    tmp304 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp302}, TNode<UintPtrT>{tmp303});
    ca_.Branch(tmp304, &block301, std::vector<compiler::Node*>{}, &block302, std::vector<compiler::Node*>{});
  }

  if (block294.is_used()) {
    ca_.Bind(&block294);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp305;
  TNode<IntPtrT> tmp306;
  TNode<Object> tmp307;
  TNode<IntPtrT> tmp308;
  if (block301.is_used()) {
    ca_.Bind(&block301);
    tmp305 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp306 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp300}, TNode<IntPtrT>{tmp305});
    std::tie(tmp307, tmp308) = NewReference_Object_0(state_, TNode<Object>{tmp299}, TNode<IntPtrT>{tmp306}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp307, tmp308}, p_newValue);
    ca_.Goto(&block274);
  }

  if (block302.is_used()) {
    ca_.Bind(&block302);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block274.is_used()) {
    ca_.Bind(&block274);
    ca_.Goto(&block259);
  }

  if (block259.is_used()) {
    ca_.Bind(&block259);
    ca_.Goto(&block244);
  }

  TNode<Object> tmp309;
  TNode<IntPtrT> tmp310;
  TNode<IntPtrT> tmp311;
  TNode<UintPtrT> tmp312;
  TNode<UintPtrT> tmp313;
  TNode<BoolT> tmp314;
  if (block243.is_used()) {
    ca_.Bind(&block243);
    std::tie(tmp309, tmp310, tmp311) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp312 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp313 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp311});
    tmp314 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp312}, TNode<UintPtrT>{tmp313});
    ca_.Branch(tmp314, &block317, std::vector<compiler::Node*>{}, &block318, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp315;
  TNode<IntPtrT> tmp316;
  TNode<Object> tmp317;
  TNode<IntPtrT> tmp318;
  if (block317.is_used()) {
    ca_.Bind(&block317);
    tmp315 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp316 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp310}, TNode<IntPtrT>{tmp315});
    std::tie(tmp317, tmp318) = NewReference_Object_0(state_, TNode<Object>{tmp309}, TNode<IntPtrT>{tmp316}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp317, tmp318}, p_newValue);
    ca_.Goto(&block244);
  }

  if (block318.is_used()) {
    ca_.Bind(&block318);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block244.is_used()) {
    ca_.Bind(&block244);
    ca_.Goto(&block168);
  }

  if (block168.is_used()) {
    ca_.Bind(&block168);
    ca_.Goto(&block73);
  }

  if (block73.is_used()) {
    ca_.Bind(&block73);
    ca_.Goto(&block1);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(&block321);
  }

    ca_.Bind(&block321);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=419&c=1
TNode<Object> LoadScriptContextElementImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_c, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<UintPtrT> tmp3;
  TNode<UintPtrT> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_c}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<BoolT> tmp11;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    tmp10 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp8, tmp9});
    tmp11 = IsMutableHeapNumber_0(state_, TNode<Context>{p_c}, TNode<IntPtrT>{p_i}, TNode<Object>{tmp10});
    ca_.Branch(tmp11, &block19, std::vector<compiler::Node*>{}, &block20, std::vector<compiler::Node*>{});
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<HeapObject> tmp12;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    compiler::CodeAssemblerLabel label13(&ca_);
    tmp12 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp10}, &label13);
    ca_.Goto(&block24);
    if (label13.is_used()) {
      ca_.Bind(&label13);
      ca_.Goto(&block25);
    }
  }

  if (block25.is_used()) {
    ca_.Bind(&block25);
    ca_.Goto(&block22);
  }

  TNode<HeapNumber> tmp14;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    compiler::CodeAssemblerLabel label15(&ca_);
    tmp14 = Cast_HeapNumber_0(state_, TNode<HeapObject>{tmp12}, &label15);
    ca_.Goto(&block26);
    if (label15.is_used()) {
      ca_.Bind(&label15);
      ca_.Goto(&block27);
    }
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    ca_.Goto(&block22);
  }

  TNode<IntPtrT> tmp16;
  TNode<Float64T> tmp17;
  TNode<HeapNumber> tmp18;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp17 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp14, tmp16});
    tmp18 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp17});
    ca_.Goto(&block1, tmp18);
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.Goto(&block1, tmp10);
  }

  TNode<Object> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.Goto(&block28, phi_bb1_2);
  }

  TNode<Object> phi_bb28_2;
    ca_.Bind(&block28, &phi_bb28_2);
  return TNode<Object>{phi_bb28_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=429&c=1
TNode<BoolT> IsMutableHeapNumber_0(compiler::CodeAssemblerState* state_, TNode<Context> p_c, TNode<IntPtrT> p_index, TNode<Object> p_val) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_val}, &label1);
    ca_.Goto(&block8);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block9);
    }
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block6);
  }

  TNode<HeapNumber> tmp2;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_HeapNumber_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block10);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block11);
    }
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block6);
  }

  TNode<BoolT> tmp4;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block4, tmp4);
  }

  TNode<BoolT> tmp5;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block4, tmp5);
  }

  TNode<BoolT> phi_bb4_5;
  TNode<BoolT> tmp6;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5);
    tmp6 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{phi_bb4_5});
    ca_.Branch(tmp6, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp7);
  }

  TNode<Context> tmp8;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = Cast_ScriptContext_0(state_, TNode<HeapObject>{p_c}, &label9);
    ca_.Goto(&block14);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block15);
    }
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Object> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<HeapObject> tmp15;
  TNode<HeapObject> tmp16;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp10 = FromConstexpr_intptr_constexpr_intptr_0(state_, Context::Field::MIN_CONTEXT_EXTENDED_SLOTS);
    tmp11 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{p_index}, TNode<IntPtrT>{tmp10});
    tmp12 = CONTEXT_SIDE_TABLE_PROPERTY_INDEX_0(state_);
    std::tie(tmp13, tmp14) = ContextSlot_ScriptContext_Context_HeapObject_0(state_, TNode<Context>{tmp8}, TNode<IntPtrT>{tmp12}).Flatten();
    tmp15 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp13, tmp14});
    compiler::CodeAssemblerLabel label17(&ca_);
    tmp16 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp15}, &label17);
    ca_.Goto(&block19);
    if (label17.is_used()) {
      ca_.Bind(&label17);
      ca_.Goto(&block20);
    }
  }

  if (block20.is_used()) {
    ca_.Bind(&block20);
    ca_.Goto(&block17);
  }

  TNode<FixedArray> tmp18;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    compiler::CodeAssemblerLabel label19(&ca_);
    tmp18 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp16}, &label19);
    ca_.Goto(&block21);
    if (label19.is_used()) {
      ca_.Bind(&label19);
      ca_.Goto(&block22);
    }
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.Goto(&block17);
  }

  TNode<IntPtrT> tmp20;
  TNode<Smi> tmp21;
  TNode<Smi> tmp22;
  TNode<BoolT> tmp23;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp21 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp18, tmp20});
    tmp22 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp23 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp21}, TNode<Smi>{tmp22});
    ca_.Branch(tmp23, &block23, std::vector<compiler::Node*>{}, &block24, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp24;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp24 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp24);
  }

  TNode<BoolT> tmp25;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp25 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp25);
  }

  TNode<Object> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<UintPtrT> tmp29;
  TNode<UintPtrT> tmp30;
  TNode<BoolT> tmp31;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    std::tie(tmp26, tmp27, tmp28) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp18}).Flatten();
    tmp29 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp11});
    tmp30 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp28});
    tmp31 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp29}, TNode<UintPtrT>{tmp30});
    ca_.Branch(tmp31, &block29, std::vector<compiler::Node*>{}, &block30, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<Object> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<Object> tmp36;
  TNode<Undefined> tmp37;
  if (block29.is_used()) {
    ca_.Bind(&block29);
    tmp32 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp11});
    tmp33 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp27}, TNode<IntPtrT>{tmp32});
    std::tie(tmp34, tmp35) = NewReference_Object_0(state_, TNode<Object>{tmp26}, TNode<IntPtrT>{tmp33}).Flatten();
    tmp36 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp34, tmp35});
    compiler::CodeAssemblerLabel label38(&ca_);
    tmp37 = Cast_Undefined_1(state_, TNode<Object>{tmp36}, &label38);
    ca_.Goto(&block35);
    if (label38.is_used()) {
      ca_.Bind(&label38);
      ca_.Goto(&block36);
    }
  }

  if (block30.is_used()) {
    ca_.Bind(&block30);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<HeapObject> tmp39;
  if (block36.is_used()) {
    ca_.Bind(&block36);
    compiler::CodeAssemblerLabel label40(&ca_);
    tmp39 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{ca_.UncheckedCast<Object>(tmp36)}, &label40);
    ca_.Goto(&block40);
    if (label40.is_used()) {
      ca_.Bind(&label40);
      ca_.Goto(&block41);
    }
  }

  TNode<BoolT> tmp41;
  if (block35.is_used()) {
    ca_.Bind(&block35);
    tmp41 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp41);
  }

  if (block41.is_used()) {
    ca_.Bind(&block41);
    ca_.Goto(&block38);
  }

  TNode<ContextSidePropertyCell> tmp42;
  if (block40.is_used()) {
    ca_.Bind(&block40);
    compiler::CodeAssemblerLabel label43(&ca_);
    tmp42 = Cast_ContextSidePropertyCell_0(state_, TNode<HeapObject>{tmp39}, &label43);
    ca_.Goto(&block42);
    if (label43.is_used()) {
      ca_.Bind(&label43);
      ca_.Goto(&block43);
    }
  }

  if (block43.is_used()) {
    ca_.Bind(&block43);
    ca_.Goto(&block38);
  }

  TNode<IntPtrT> tmp44;
  TNode<Smi> tmp45;
  TNode<IntPtrT> tmp46;
  TNode<IntPtrT> tmp47;
  TNode<BoolT> tmp48;
  if (block42.is_used()) {
    ca_.Bind(&block42);
    tmp44 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp45 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp42, tmp44});
    tmp46 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp45});
    tmp47 = kContextSidePropertyHeapNumber_0(state_);
    tmp48 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp46}, TNode<IntPtrT>{tmp47});
    ca_.Goto(&block1, tmp48);
  }

  TNode<Smi> tmp49;
  if (block38.is_used()) {
    ca_.Bind(&block38);
    compiler::CodeAssemblerLabel label50(&ca_);
    tmp49 = Cast_Smi_0(state_, TNode<Object>{ca_.UncheckedCast<Object>(tmp36)}, &label50);
    ca_.Goto(&block46);
    if (label50.is_used()) {
      ca_.Bind(&label50);
      ca_.Goto(&block47);
    }
  }

  if (block47.is_used()) {
    ca_.Bind(&block47);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp51;
  TNode<IntPtrT> tmp52;
  TNode<BoolT> tmp53;
  if (block46.is_used()) {
    ca_.Bind(&block46);
    tmp51 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp49});
    tmp52 = kContextSidePropertyHeapNumber_0(state_);
    tmp53 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp51}, TNode<IntPtrT>{tmp52});
    ca_.Goto(&block1, tmp53);
  }

  TNode<BoolT> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block48, phi_bb1_3);
  }

  TNode<BoolT> phi_bb48_3;
    ca_.Bind(&block48, &phi_bb48_3);
  return TNode<BoolT>{phi_bb48_3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=465&c=1
TNode<Smi> kNoContext_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<Smi> tmp0;
    tmp0 = CodeStubAssembler(state_).NoContextConstant();
  return TNode<Smi>{tmp0};}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=13&c=9
TNode<Smi> LoadContextLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_o) {
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
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=14&c=3
TorqueStructSlice_Object_MutableReference_Object_0 FieldSliceContextElements_0(compiler::CodeAssemblerState* state_, TNode<Context> p_o) {
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
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    tmp2 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x8ull));
    std::tie(tmp4, tmp5, tmp6) = NewMutableSlice_Object_0(state_, TNode<Object>{p_o}, TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp2}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_Object_MutableReference_Object_0{TNode<Object>{tmp4}, TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp6}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=14&c=3
TNode<Object> LoadContextElements_0(compiler::CodeAssemblerState* state_, TNode<Context> p_o, TNode<IntPtrT> p_i) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_o}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    tmp10 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp8, tmp9});
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<Object>{tmp10};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=14&c=3
void StoreContextElements_0(compiler::CodeAssemblerState* state_, TNode<Context> p_o, TNode<IntPtrT> p_i, TNode<Object> p_v) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_o}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp8, tmp9}, p_v);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=10&c=3
TNode<ScopeInfo> Method_Context_GetScopeInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_this) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<ScopeInfo> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = SCOPE_INFO_INDEX_0(state_);
    std::tie(tmp1, tmp2) = ContextSlot_Context_Context_ScopeInfo_0(state_, TNode<Context>{p_this}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp3 = CodeStubAssembler(state_).LoadReference<ScopeInfo>(CodeStubAssembler::Reference{tmp1, tmp2});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<ScopeInfo>{tmp3};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=19&c=9
TNode<Smi> LoadScriptContextTableCapacity_0(compiler::CodeAssemblerState* state_, TNode<ScriptContextTable> p_o) {
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
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=20&c=3
TNode<Smi> LoadScriptContextTableLength_0(compiler::CodeAssemblerState* state_, TNode<ScriptContextTable> p_o) {
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
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=20&c=3
void StoreScriptContextTableLength_0(compiler::CodeAssemblerState* state_, TNode<ScriptContextTable> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=21&c=3
TNode<NameToIndexHashTable> LoadScriptContextTableNamesToContextIndex_0(compiler::CodeAssemblerState* state_, TNode<ScriptContextTable> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<NameToIndexHashTable> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<NameToIndexHashTable>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<NameToIndexHashTable>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=21&c=3
void StoreScriptContextTableNamesToContextIndex_0(compiler::CodeAssemblerState* state_, TNode<ScriptContextTable> p_o, TNode<NameToIndexHashTable> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<NameToIndexHashTable>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=22&c=3
TorqueStructSlice_Context_MutableReference_Context_0 FieldSliceScriptContextTableObjects_0(compiler::CodeAssemblerState* state_, TNode<ScriptContextTable> p_o) {
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
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    tmp2 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x10ull));
    std::tie(tmp4, tmp5, tmp6) = NewMutableSlice_Context_0(state_, TNode<Object>{p_o}, TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp2}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_Context_MutableReference_Context_0{TNode<Object>{tmp4}, TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp6}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=22&c=3
TNode<Context> LoadScriptContextTableObjects_0(compiler::CodeAssemblerState* state_, TNode<ScriptContextTable> p_o, TNode<IntPtrT> p_i) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceScriptContextTableObjects_0(state_, TNode<ScriptContextTable>{p_o}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Context> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Context_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Context_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    tmp10 = CodeStubAssembler(state_).LoadReference<Context>(CodeStubAssembler::Reference{tmp8, tmp9});
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TNode<Context>{tmp10};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=22&c=3
void StoreScriptContextTableObjects_0(compiler::CodeAssemblerState* state_, TNode<ScriptContextTable> p_o, TNode<IntPtrT> p_i, TNode<Context> p_v) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceScriptContextTableObjects_0(state_, TNode<ScriptContextTable>{p_o}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Context_0(state_, TNode<IntPtrT>{p_i});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Context_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{tmp8, tmp9}, p_v);
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=5&c=1
TNode<Context> DownCastForTorqueClass_Context_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(220), static_cast<InstanceType>(229))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if ((CodeStubAssembler(state_).ClassHasMapConstant<Context>())) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<Context>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
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
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(220));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(229), static_cast<InstanceType>(220))));
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(220));
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block5);
  }

  TNode<Context> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<Context>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=17&c=1
TNode<ScriptContextTable> DownCastForTorqueClass_ScriptContextTable_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(280), static_cast<InstanceType>(280))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if ((CodeStubAssembler(state_).ClassHasMapConstant<ScriptContextTable>())) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<ScriptContextTable>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
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
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(280));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(280), static_cast<InstanceType>(280))));
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(280));
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block5);
  }

  TNode<ScriptContextTable> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<ScriptContextTable>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=25&c=1
TNode<Context> DownCastForTorqueClass_AwaitContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(220), static_cast<InstanceType>(220))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if ((false)) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<void>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
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
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(220));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(220), static_cast<InstanceType>(220))));
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(220));
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block5);
  }

  TNode<Context> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<Context>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=26&c=1
TNode<Context> DownCastForTorqueClass_BlockContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(221), static_cast<InstanceType>(221))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if ((false)) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<void>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
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
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(221));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(221), static_cast<InstanceType>(221))));
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(221));
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block5);
  }

  TNode<Context> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<Context>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=27&c=1
TNode<Context> DownCastForTorqueClass_CatchContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(222), static_cast<InstanceType>(222))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if ((false)) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<void>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
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
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(222));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(222), static_cast<InstanceType>(222))));
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(222));
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block5);
  }

  TNode<Context> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<Context>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=28&c=1
TNode<Context> DownCastForTorqueClass_DebugEvaluateContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(223), static_cast<InstanceType>(223))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if ((false)) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<void>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
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
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(223));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(223), static_cast<InstanceType>(223))));
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(223));
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block5);
  }

  TNode<Context> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<Context>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=30&c=1
TNode<Context> DownCastForTorqueClass_EvalContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(224), static_cast<InstanceType>(224))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if ((false)) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<void>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
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
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(224));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(224), static_cast<InstanceType>(224))));
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(224));
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block5);
  }

  TNode<Context> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<Context>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=31&c=1
TNode<Context> DownCastForTorqueClass_ModuleContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(226), static_cast<InstanceType>(226))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if ((false)) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<void>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
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
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(226));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(226), static_cast<InstanceType>(226))));
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(226));
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block5);
  }

  TNode<Context> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<Context>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=32&c=1
TNode<Context> DownCastForTorqueClass_ScriptContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(228), static_cast<InstanceType>(228))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if ((false)) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<void>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
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
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(228));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(228), static_cast<InstanceType>(228))));
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(228));
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block5);
  }

  TNode<Context> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<Context>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=33&c=1
TNode<Context> DownCastForTorqueClass_WithContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(229), static_cast<InstanceType>(229))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if ((false)) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<void>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
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
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(229));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(229), static_cast<InstanceType>(229))));
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(229));
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block5);
  }

  TNode<Context> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<Context>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=35&c=1
TNode<Context> DownCastForTorqueClass_FunctionContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(225), static_cast<InstanceType>(225))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if ((false)) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<void>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
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
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(225));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(225), static_cast<InstanceType>(225))));
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(225));
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block5);
  }

  TNode<Context> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<Context>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=50&c=8
TorqueStructReference_Map_0 ContextSlot_NativeContext_NativeContext_Map_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    std::tie(tmp10, tmp11) = ReferenceCast_Map_Object_0(state_, TorqueStructReference_Object_0{TNode<Object>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructReference_Map_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=54&c=18
TorqueStructConstantIterator_Smi_0 ConstantIterator_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructConstantIterator_Smi_0{TNode<Smi>{p_value}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=51&c=18
void InitializeFieldsFromIterator_Object_ConstantIterator_Smi_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_MutableReference_Object_0 p_target, TorqueStructConstantIterator_Smi_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_target.length});
    tmp1 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_target.offset}, TNode<IntPtrT>{tmp0});
    ca_.Goto(&block5, p_target.offset);
  }

  TNode<IntPtrT> phi_bb5_5;
  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp2, &block3, std::vector<compiler::Node*>{phi_bb5_5}, &block4, std::vector<compiler::Node*>{phi_bb5_5});
  }

  TNode<IntPtrT> phi_bb3_5;
  TNode<BoolT> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5);
    tmp3 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb3_5}, TNode<IntPtrT>{tmp1});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{phi_bb3_5}, &block10, std::vector<compiler::Node*>{phi_bb3_5});
  }

  TNode<IntPtrT> phi_bb9_5;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5);
    ca_.Goto(&block4, phi_bb9_5);
  }

  TNode<IntPtrT> phi_bb10_5;
  TNode<Object> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5);
    std::tie(tmp4, tmp5) = NewReference_Object_0(state_, TNode<Object>{p_target.object}, TNode<IntPtrT>{phi_bb10_5}).Flatten();
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_5}, TNode<IntPtrT>{tmp6});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp4, tmp5}, p_originIterator.value);
    ca_.Goto(&block5, tmp7);
  }

  TNode<IntPtrT> phi_bb4_5;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5);
    ca_.Goto(&block16);
  }

    ca_.Bind(&block16);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=56&c=3
void InitContextSlot_FunctionContext_Context_ScopeInfo_ScopeInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<ScopeInfo> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<UintPtrT> tmp3;
  TNode<UintPtrT> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block18, std::vector<compiler::Node*>{}, &block19, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp8, tmp9}, p_value);
    ca_.Goto(&block22);
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block22);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=57&c=3
void InitContextSlot_FunctionContext_Context_Undefined_OR_Context_OR_Zero_Undefined_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index, TNode<Undefined> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<UintPtrT> tmp3;
  TNode<UintPtrT> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block18, std::vector<compiler::Node*>{}, &block19, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp8, tmp9}, p_value);
    ca_.Goto(&block22);
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block22);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=61&c=1
TNode<NativeContext> DownCastForTorqueClass_NativeContext_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError) {
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
    tmp1 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{p_o, tmp0});
    if (((CodeStubAssembler(state_).ConstexprInt31Equal(static_cast<InstanceType>(227), static_cast<InstanceType>(227))))) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if ((CodeStubAssembler(state_).ClassHasMapConstant<NativeContext>())) {
      ca_.Goto(&block6);
    } else {
      ca_.Goto(&block7);
    }
  }

  TNode<Map> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp2 = CodeStubAssembler(state_).GetClassMapConstant<NativeContext>();
    tmp3 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
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
    tmp5 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp4});
    tmp6 = FromConstexpr_uint32_constexpr_uint32_0(state_, static_cast<InstanceType>(227));
    tmp7 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T>{tmp5}, TNode<Uint32T>{tmp6});
    ca_.Branch(tmp7, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
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
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, (CodeStubAssembler(state_).ConstexprUint32Sub(static_cast<InstanceType>(227), static_cast<InstanceType>(227))));
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp1, tmp9});
    tmp11 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp10});
    tmp12 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp11});
    tmp13 = FromConstexpr_InstanceType_constexpr_InstanceType_0(state_, static_cast<InstanceType>(227));
    tmp14 = Convert_uint16_InstanceType_0(state_, TNode<Uint16T>{tmp13});
    tmp15 = Convert_int32_uint16_0(state_, TNode<Uint16T>{tmp14});
    tmp16 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp15});
    tmp17 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp16});
    tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp8});
    tmp19 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T>{tmp17}, TNode<Uint32T>{tmp18});
    ca_.Branch(tmp19, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block5);
  }

  TNode<NativeContext> tmp20;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp20 = TORQUE_CAST(TNode<HeapObject>{p_o});
    ca_.Goto(&block15);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block15);
  return TNode<NativeContext>{tmp20};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=255&c=18
TNode<HeapNumber> UnsafeCast_HeapNumber_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapNumber> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<HeapNumber>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=256&c=19
TNode<Context> UnsafeCast_Context_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<Context>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=296&c=29
TorqueStructReference_HeapObject_0 ContextSlot_ScriptContext_Context_HeapObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    std::tie(tmp10, tmp11) = ReferenceCast_HeapObject_Object_0(state_, TorqueStructReference_Object_0{TNode<Object>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructReference_HeapObject_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=300&c=7
TNode<FixedArray> Cast_FixedArray_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_o}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1);
  }

  TNode<FixedArray> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block7);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block7);
  return TNode<FixedArray>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=347&c=9
TNode<BoolT> Is_ContextSidePropertyCell_Undefined_OR_ContextSidePropertyCell_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<ContextSidePropertyCell> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_ContextSidePropertyCell_0(state_, TNode<HeapObject>{p_o}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp3);
  }

  TNode<BoolT> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=420&c=10
TNode<BoolT> Is_ScriptContext_Context_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Context> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Context> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_ScriptContext_0(state_, TNode<HeapObject>{p_o}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp3);
  }

  TNode<BoolT> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=448&c=5
TNode<ContextSidePropertyCell> Cast_ContextSidePropertyCell_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_o}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1);
  }

  TNode<ContextSidePropertyCell> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_ContextSidePropertyCell_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block7);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block7);
  return TNode<ContextSidePropertyCell>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=14&c=3
TorqueStructSlice_Object_MutableReference_Object_0 NewMutableSlice_Object_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1, tmp2) = (TorqueStructSlice_Object_MutableReference_Object_0{TNode<Object>{p_object}, TNode<IntPtrT>{p_offset}, TNode<IntPtrT>{p_length}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_Object_MutableReference_Object_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=11&c=13
TorqueStructReference_ScopeInfo_0 ContextSlot_Context_Context_ScopeInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    std::tie(tmp10, tmp11) = ReferenceCast_ScopeInfo_Object_0(state_, TorqueStructReference_Object_0{TNode<Object>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructReference_ScopeInfo_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=22&c=3
TorqueStructSlice_Context_MutableReference_Context_0 NewMutableSlice_Context_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1, tmp2) = (TorqueStructSlice_Context_MutableReference_Context_0{TNode<Object>{p_object}, TNode<IntPtrT>{p_offset}, TNode<IntPtrT>{p_length}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructSlice_Context_MutableReference_Context_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_JSReceiver_0 ReferenceCast_JSReceiver_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<JSReceiver> tmp2;
  TNode<JSReceiver> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_JSReceiver_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_JSReceiver_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_JSAny_0 ReferenceCast_JSAny_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<Object> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_JSAny_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = (TNode<Object>{tmp2});
    ca_.Goto(&block12);
  }

    ca_.Bind(&block12);
  return TorqueStructReference_JSAny_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_Smi_0 ReferenceCast_Smi_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Smi> tmp2;
  TNode<Smi> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_Smi_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block12);
  }

    ca_.Bind(&block12);
  return TorqueStructReference_Smi_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_JSPromise_0 ReferenceCast_JSPromise_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<JSPromise> tmp2;
  TNode<JSPromise> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_JSPromise_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<JSPromise>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_JSPromise_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_Number_0 ReferenceCast_Number_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Number> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_Number_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block12);
  }

    ca_.Bind(&block12);
  return TorqueStructReference_Number_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=87&c=10
TorqueStructReference_JSFunction_0 ContextSlot_NativeContext_NativeContext_JSFunction_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    std::tie(tmp10, tmp11) = ReferenceCast_JSFunction_Object_0(state_, TorqueStructReference_Object_0{TNode<Object>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructReference_JSFunction_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=95&c=10
TorqueStructReference_Undefined_OR_FixedArray_0 NativeContextSlot_Undefined_OR_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    std::tie(tmp1, tmp2) = ContextSlot_NativeContext_NativeContext_Undefined_OR_FixedArray_0(state_, TNode<NativeContext>{tmp0}, TNode<IntPtrT>{p_index}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_Undefined_OR_FixedArray_0{TNode<Object>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=95&c=10
TorqueStructReference_JSFunction_0 NativeContextSlot_JSFunction_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    std::tie(tmp1, tmp2) = ContextSlot_NativeContext_NativeContext_JSFunction_0(state_, TNode<NativeContext>{tmp0}, TNode<IntPtrT>{p_index}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_JSFunction_0{TNode<Object>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=95&c=10
TorqueStructReference_Constructor_0 NativeContextSlot_Constructor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    std::tie(tmp1, tmp2) = ContextSlot_NativeContext_NativeContext_Constructor_0(state_, TNode<NativeContext>{tmp0}, TNode<IntPtrT>{p_index}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_Constructor_0{TNode<Object>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=95&c=10
TorqueStructReference_Callable_0 NativeContextSlot_Callable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    std::tie(tmp1, tmp2) = ContextSlot_NativeContext_NativeContext_Callable_0(state_, TNode<NativeContext>{tmp0}, TNode<IntPtrT>{p_index}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_Callable_0{TNode<Object>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=95&c=10
TorqueStructReference_RegExpMatchInfo_0 NativeContextSlot_RegExpMatchInfo_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    std::tie(tmp1, tmp2) = ContextSlot_NativeContext_NativeContext_RegExpMatchInfo_0(state_, TNode<NativeContext>{tmp0}, TNode<IntPtrT>{p_index}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_RegExpMatchInfo_0{TNode<Object>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=95&c=10
TorqueStructReference_JSObject_0 NativeContextSlot_JSObject_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    std::tie(tmp1, tmp2) = ContextSlot_NativeContext_NativeContext_JSObject_0(state_, TNode<NativeContext>{tmp0}, TNode<IntPtrT>{p_index}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_JSObject_0{TNode<Object>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=95&c=10
TorqueStructReference_Smi_0 NativeContextSlot_Smi_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = ContextSlot_NativeContext_NativeContext_Smi_0(state_, TNode<NativeContext>{p_context}, TNode<IntPtrT>{p_index}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_Smi_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=95&c=10
TorqueStructReference_FixedDoubleArray_0 NativeContextSlot_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = ContextSlot_NativeContext_NativeContext_FixedDoubleArray_0(state_, TNode<NativeContext>{p_context}, TNode<IntPtrT>{p_index}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_FixedDoubleArray_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_Boolean_0 ReferenceCast_Boolean_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Boolean> tmp2;
  TNode<Boolean> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_Boolean_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<Boolean>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block12);
  }

    ca_.Bind(&block12);
  return TorqueStructReference_Boolean_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_PromiseCapability_0 ReferenceCast_PromiseCapability_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<PromiseCapability> tmp2;
  TNode<PromiseCapability> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_PromiseCapability_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<PromiseCapability>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_PromiseCapability_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=87&c=10
TorqueStructReference_JSObject_0 ContextSlot_NativeContext_NativeContext_JSObject_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    std::tie(tmp10, tmp11) = ReferenceCast_JSObject_Object_0(state_, TorqueStructReference_Object_0{TNode<Object>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructReference_JSObject_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_FixedArray_0 ReferenceCast_FixedArray_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<FixedArray> tmp2;
  TNode<FixedArray> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_FixedArray_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_FixedArray_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_Callable_0 ReferenceCast_Callable_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<JSReceiver> tmp2;
  TNode<JSReceiver> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_Callable_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_Callable_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_Constructor_0 ReferenceCast_Constructor_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<JSReceiver> tmp2;
  TNode<JSReceiver> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_Constructor_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_Constructor_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=95&c=10
TorqueStructReference_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0 NativeContextSlot_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<IntPtrT> p_index) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<NativeContext> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    std::tie(tmp1, tmp2) = ContextSlot_NativeContext_NativeContext_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0(state_, TNode<NativeContext>{tmp0}, TNode<IntPtrT>{p_index}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0{TNode<Object>{tmp1}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_Null_OR_JSProxy_0 ReferenceCast_Null_OR_JSProxy_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<HeapObject> tmp2;
  TNode<HeapObject> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_Null_OR_JSProxy_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_Null_OR_JSProxy_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_Map_0 ReferenceCast_Map_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Map> tmp2;
  TNode<Map> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_Map_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_Map_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_HeapObject_0 ReferenceCast_HeapObject_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<HeapObject> tmp2;
  TNode<HeapObject> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_HeapObject_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_HeapObject_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_ScopeInfo_0 ReferenceCast_ScopeInfo_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<ScopeInfo> tmp2;
  TNode<ScopeInfo> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_ScopeInfo_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<ScopeInfo>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_ScopeInfo_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_Undefined_OR_JSFunction_0 ReferenceCast_Undefined_OR_JSFunction_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<HeapObject> tmp2;
  TNode<HeapObject> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_Undefined_OR_JSFunction_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_Undefined_OR_JSFunction_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_JSFunction_0 ReferenceCast_JSFunction_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<JSFunction> tmp2;
  TNode<JSFunction> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_JSFunction_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<JSFunction>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_JSFunction_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=91&c=10
TorqueStructReference_Undefined_OR_FixedArray_0 ContextSlot_NativeContext_NativeContext_Undefined_OR_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    std::tie(tmp10, tmp11) = ReferenceCast_Undefined_OR_FixedArray_Object_0(state_, TorqueStructReference_Object_0{TNode<Object>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructReference_Undefined_OR_FixedArray_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=91&c=10
TorqueStructReference_Constructor_0 ContextSlot_NativeContext_NativeContext_Constructor_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    std::tie(tmp10, tmp11) = ReferenceCast_Constructor_Object_0(state_, TorqueStructReference_Object_0{TNode<Object>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructReference_Constructor_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=91&c=10
TorqueStructReference_Callable_0 ContextSlot_NativeContext_NativeContext_Callable_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    std::tie(tmp10, tmp11) = ReferenceCast_Callable_Object_0(state_, TorqueStructReference_Object_0{TNode<Object>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructReference_Callable_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=91&c=10
TorqueStructReference_RegExpMatchInfo_0 ContextSlot_NativeContext_NativeContext_RegExpMatchInfo_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    std::tie(tmp10, tmp11) = ReferenceCast_RegExpMatchInfo_Object_0(state_, TorqueStructReference_Object_0{TNode<Object>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructReference_RegExpMatchInfo_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=87&c=10
TorqueStructReference_Smi_0 ContextSlot_NativeContext_NativeContext_Smi_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    std::tie(tmp10, tmp11) = ReferenceCast_Smi_Object_0(state_, TorqueStructReference_Object_0{TNode<Object>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructReference_Smi_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=87&c=10
TorqueStructReference_FixedDoubleArray_0 ContextSlot_NativeContext_NativeContext_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    std::tie(tmp10, tmp11) = ReferenceCast_FixedDoubleArray_Object_0(state_, TorqueStructReference_Object_0{TNode<Object>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructReference_FixedDoubleArray_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_JSObject_0 ReferenceCast_JSObject_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<JSObject> tmp2;
  TNode<JSObject> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_JSObject_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<JSObject>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_JSObject_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=91&c=10
TorqueStructReference_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0 ContextSlot_NativeContext_NativeContext_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index) {
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
    std::tie(tmp0, tmp1, tmp2) = FieldSliceContextElements_0(state_, TNode<Context>{p_context}).Flatten();
    tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_index});
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp2});
    tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{p_index});
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp6});
    std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object>{tmp0}, TNode<IntPtrT>{tmp7}).Flatten();
    std::tie(tmp10, tmp11) = ReferenceCast_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_Object_0(state_, TorqueStructReference_Object_0{TNode<Object>{tmp8}, TNode<IntPtrT>{tmp9}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block10);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block10);
  return TorqueStructReference_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0{TNode<Object>{tmp10}, TNode<IntPtrT>{tmp11}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_Undefined_OR_FixedArray_0 ReferenceCast_Undefined_OR_FixedArray_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<HeapObject> tmp2;
  TNode<HeapObject> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_Undefined_OR_FixedArray_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_Undefined_OR_FixedArray_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_RegExpMatchInfo_0 ReferenceCast_RegExpMatchInfo_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<RegExpMatchInfo> tmp2;
  TNode<RegExpMatchInfo> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_RegExpMatchInfo_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<RegExpMatchInfo>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_RegExpMatchInfo_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_FixedDoubleArray_0 ReferenceCast_FixedDoubleArray_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<FixedDoubleArray> tmp2;
  TNode<FixedDoubleArray> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_FixedDoubleArray_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<FixedDoubleArray>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_FixedDoubleArray_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=82&c=10
TorqueStructReference_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0 ReferenceCast_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_Object_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Object_0 p_ref) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<HeapObject> tmp2;
  TNode<HeapObject> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0(state_, TNode<Object>{p_ref.object}, TNode<IntPtrT>{p_ref.offset}).Flatten();
    tmp2 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp0, tmp1});
    tmp3 = TORQUE_CAST(TNode<Object>{tmp2});
    ca_.Goto(&block15);
  }

    ca_.Bind(&block15);
  return TorqueStructReference_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

} // namespace internal
} // namespace v8
