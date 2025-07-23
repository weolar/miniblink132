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
#include "torque-generated/src/builtins/js-to-wasm-tq-csa.h"
#include "torque-generated/src/builtins/array-findindex-tq-csa.h"
#include "torque-generated/src/builtins/array-flat-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-splice-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/builtins-bigint-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frames-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/builtins/js-to-js-tq-csa.h"
#include "torque-generated/src/builtins/js-to-wasm-tq-csa.h"
#include "torque-generated/src/builtins/wasm-tq-csa.h"
#include "torque-generated/src/builtins/wasm-to-js-tq-csa.h"
#include "torque-generated/src/wasm/wasm-objects-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=70&c=1
TNode<Int32T> FromConstexpr_ValueKind_constexpr_kRef_0(compiler::CodeAssemblerState* state_, wasm::ValueKind p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=70&c=1
TNode<Int32T> FromConstexpr_ValueKind_constexpr_kRefNull_0(compiler::CodeAssemblerState* state_, wasm::ValueKind p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=76&c=1
TNode<Int32T> FromConstexpr_Promise_constexpr_kPromise_0(compiler::CodeAssemblerState* state_, wasm::Promise p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=76&c=1
TNode<Int32T> FromConstexpr_Promise_constexpr_kNoPromise_0(compiler::CodeAssemblerState* state_, wasm::Promise p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=76&c=1
TNode<Int32T> FromConstexpr_Promise_constexpr_kStressSwitch_0(compiler::CodeAssemblerState* state_, wasm::Promise p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kExtern_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kNoExtern_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kString_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kEq_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kI31_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kStruct_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kArray_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kAny_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kNone_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kFunc_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kNoFunc_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kExn_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=82&c=1
TNode<Int32T> FromConstexpr_HeapType_constexpr_kNoExn_0(compiler::CodeAssemblerState* state_, wasm::HeapType::Representation p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=148&c=1
TNode<Uint32T> Bitcast_uint32_float32_0(compiler::CodeAssemblerState* state_, TNode<Float32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Uint32T> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).BitcastFloat32ToInt32(TNode<Float32T>{p_v});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint32T>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=157&c=1
TNode<IntPtrT> TruncateBigIntToI64_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_input) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BigInt> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).ToBigInt(TNode<Context>{p_context}, TNode<Object>{p_input});
    tmp1 = BigIntBuiltinsAssembler(state_).ReadBigIntLength(TNode<BigInt>{tmp0});
    tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp3, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp4;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp4 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block1, tmp4);
  }

  TNode<IntPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<Uint32T> tmp7;
  TNode<Uint32T> tmp8;
  TNode<BoolT> tmp9;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp5 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp6 = CodeStubAssembler(state_).LoadBigIntDigit(TNode<BigInt>{tmp0}, TNode<IntPtrT>{tmp5});
    tmp7 = BigIntBuiltinsAssembler(state_).ReadBigIntSign(TNode<BigInt>{tmp0});
    tmp8 = kPositiveSign_0(state_);
    tmp9 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp7}, TNode<Uint32T>{tmp8});
    ca_.Branch(tmp9, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp10;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp10 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp6});
    ca_.Goto(&block1, tmp10);
  }

  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp11 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp6});
    tmp12 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp13 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp12}, TNode<IntPtrT>{tmp11});
    ca_.Goto(&block1, tmp13);
  }

  TNode<IntPtrT> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.Goto(&block10, phi_bb1_2);
  }

  TNode<IntPtrT> phi_bb10_2;
    ca_.Bind(&block10, &phi_bb10_2);
  return TNode<IntPtrT>{phi_bb10_2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=265&c=1
TorqueStructReturnSlotAllocator_0 NewReturnSlotAllocator_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<BoolT> tmp3;
  TNode<BoolT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_intptr_0(state_, arraysize(wasm::kGpReturnRegisters));
    tmp1 = FromConstexpr_intptr_constexpr_intptr_0(state_, arraysize(wasm::kFpReturnRegisters));
    tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReturnSlotAllocator_0{TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<BoolT>{tmp3}, TNode<BoolT>{tmp4}, TNode<IntPtrT>{tmp2}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=391&c=1
TorqueStructLocationAllocator_0 LocationAllocatorForParams_0(compiler::CodeAssemblerState* state_, TorqueStructReference_intptr_0 p_paramBuffer) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).UniqueIntPtrConstant(arraysize(wasm::kGpParamRegisters) - 1);
    tmp1 = CodeStubAssembler(state_).UniqueIntPtrConstant(arraysize(wasm::kFpParamRegisters));
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp3 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp2});
    if (((CodeStubAssembler(state_).ConstexprBoolNot((CodeStubAssembler(state_).Is64()))))) {
      ca_.Goto(&block2);
    } else {
      ca_.Goto(&block3);
    }
  }

  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp5 = CodeStubAssembler(state_).WordAnd(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    tmp6 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp5});
    ca_.Goto(&block4, tmp6);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block4, tmp3);
  }

  TNode<IntPtrT> phi_bb4_6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<BoolT> tmp12;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_6);
    tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb4_6}, TNode<IntPtrT>{p_paramBuffer.offset});
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp9});
    tmp11 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block9);
  }

    ca_.Bind(&block9);
  return TorqueStructLocationAllocator_0{TNode<Object>{p_paramBuffer.object}, TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{p_paramBuffer.offset}, TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp11}, TNode<BoolT>{tmp12}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=412&c=1
TorqueStructLocationAllocator_0 LocationAllocatorForReturns_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_gpRegs, TNode<RawPtrT> p_fpRegs, TNode<RawPtrT> p_stack) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<TaggedIndex> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<BoolT> tmp13;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = kZeroBitPattern_0(state_);
    tmp1 = FromConstexpr_intptr_constexpr_intptr_0(state_, arraysize(wasm::kGpReturnRegisters));
    tmp2 = FromConstexpr_intptr_constexpr_intptr_0(state_, arraysize(wasm::kFpReturnRegisters));
    tmp3 = Convert_intptr_WasmCodePointer_0(state_, TNode<RawPtrT>{p_gpRegs});
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
    tmp5 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    tmp6 = Convert_intptr_WasmCodePointer_0(state_, TNode<RawPtrT>{p_fpRegs});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp6}, TNode<IntPtrT>{tmp7});
    tmp9 = Convert_intptr_WasmCodePointer_0(state_, TNode<RawPtrT>{p_stack});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
    tmp11 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp9}, TNode<IntPtrT>{tmp10});
    tmp12 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructLocationAllocator_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp8}, TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp12}, TNode<BoolT>{tmp13}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=427&c=1
TNode<Object> JSToWasmObject_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<HeapObject> p_trustedInstanceDataOrUndefined, TNode<Int32T> p_targetType, TNode<Object> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  TNode<Int32T> tmp2;
  TNode<Int32T> tmp3;
  TNode<Int32T> tmp4;
  TNode<Int32T> tmp5;
  TNode<Int32T> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueType::kKindBits);
    tmp1 = CodeStubAssembler(state_).Word32Sar(TNode<Int32T>{p_targetType}, TNode<Int32T>{tmp0});
    tmp2 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmHeapTypeBitsMask);
    tmp3 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp2});
    tmp4 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    tmp5 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{p_targetType}, TNode<Int32T>{tmp4});
    tmp6 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kExtern);
    tmp7 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp3}, TNode<Int32T>{tmp6});
    ca_.Branch(tmp7, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp8;
  TNode<BoolT> tmp9;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    tmp9 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp8});
    ca_.Branch(tmp9, &block6, std::vector<compiler::Node*>{}, &block7, std::vector<compiler::Node*>{});
  }

  TNode<Null> tmp10;
  TNode<BoolT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp10 = Null_0(state_);
    tmp11 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{p_value}, TNode<HeapObject>{tmp10});
    ca_.Goto(&block8, tmp11);
  }

  TNode<BoolT> tmp12;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block8, tmp12);
  }

  TNode<BoolT> phi_bb8_7;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_7);
    ca_.Branch(phi_bb8_7, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kWasmTrapJSTypeError);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block1, p_value);
  }

  TNode<Int32T> tmp13;
  TNode<BoolT> tmp14;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp13 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kString);
    tmp14 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp3}, TNode<Int32T>{tmp13});
    ca_.Branch(tmp14, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp15;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp15 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object>{p_value});
    ca_.Branch(tmp15, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kWasmTrapJSTypeError);
  }

  TNode<HeapObject> tmp16;
  TNode<BoolT> tmp17;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp16 = UnsafeCast_HeapObject_0(state_, TNode<Context>{p_context}, TNode<Object>{p_value});
    tmp17 = CodeStubAssembler(state_).IsString(TNode<HeapObject>{tmp16});
    ca_.Branch(tmp17, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1, p_value);
  }

  TNode<Null> tmp18;
  TNode<BoolT> tmp19;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp18 = Null_0(state_);
    tmp19 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{p_value}, TNode<HeapObject>{tmp18});
    ca_.Branch(tmp19, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp20;
  TNode<BoolT> tmp21;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp20 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    tmp21 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp20});
    ca_.Branch(tmp21, &block17, std::vector<compiler::Node*>{}, &block18, std::vector<compiler::Node*>{});
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kWasmTrapJSTypeError);
  }

  TNode<WasmNull> tmp22;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp22 = kWasmNull_0(state_);
    ca_.Goto(&block1, tmp22);
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kWasmTrapJSTypeError);
  }

  TNode<Smi> tmp23;
  TNode<Object> tmp24;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp23 = Convert_Smi_int32_0(state_, TNode<Int32T>{p_targetType});
    tmp24 = CodeStubAssembler(state_).CallRuntime(Runtime::kWasmGenericJSToWasmObject, p_context, p_trustedInstanceDataOrUndefined, p_value, tmp23); 
    ca_.Goto(&block1, tmp24);
  }

  TNode<Object> phi_bb1_4;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_4);
    ca_.Goto(&block24, phi_bb1_4);
  }

  TNode<Object> phi_bb24_4;
    ca_.Bind(&block24, &phi_bb24_4);
  return TNode<Object>{phi_bb24_4};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=462&c=1
void HandleF32Params_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TorqueStructLocationAllocator_0 p_locationAllocator, TorqueStructReference_intptr_0 p_toRef, TNode<Object> p_param) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    if ((wasm::kIsFpAlwaysDouble)) {
      ca_.Goto(&block2);
    } else {
      ca_.Goto(&block3);
    }
  }

  TNode<IntPtrT> tmp0;
  TNode<BoolT> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp1 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{p_locationAllocator.remainingFPRegs}, TNode<IntPtrT>{tmp0});
    ca_.Branch(tmp1, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Float32T> tmp4;
  TNode<Float64T> tmp5;
  TNode<Float64T> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    std::tie(tmp2, tmp3) = RefCast_float64_0(state_, TorqueStructReference_intptr_0{TNode<Object>{p_toRef.object}, TNode<IntPtrT>{p_toRef.offset}, TorqueStructUnsafe_0{}}).Flatten();
    tmp4 = ca_.CallBuiltin<Float32T>(Builtin::kWasmTaggedToFloat32, p_context, p_param);
    tmp5 = CodeStubAssembler(state_).ChangeFloat32ToFloat64(TNode<Float32T>{tmp4});
    tmp6 = CodeStubAssembler(state_).Float64SilenceNaN(TNode<Float64T>{tmp5});
    CodeStubAssembler(state_).StoreReference<Float64T>(CodeStubAssembler::Reference{tmp2, tmp3}, tmp6);
    ca_.Goto(&block8);
  }

  TNode<Object> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Float32T> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    std::tie(tmp7, tmp8) = RefCast_float32_0(state_, TorqueStructReference_intptr_0{TNode<Object>{p_toRef.object}, TNode<IntPtrT>{p_toRef.offset}, TorqueStructUnsafe_0{}}).Flatten();
    tmp9 = ca_.CallBuiltin<Float32T>(Builtin::kWasmTaggedToFloat32, p_context, p_param);
    CodeStubAssembler(state_).StoreReference<Float32T>(CodeStubAssembler::Reference{tmp7, tmp8}, tmp9);
    ca_.Goto(&block8);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block4);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    if ((wasm::kIsBigEndian)) {
      ca_.Goto(&block9);
    } else {
      ca_.Goto(&block10);
    }
  }

  TNode<Float32T> tmp10;
  TNode<Uint32T> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp10 = ca_.CallBuiltin<Float32T>(Builtin::kWasmTaggedToFloat32, p_context, p_param);
    tmp11 = Bitcast_uint32_float32_0(state_, TNode<Float32T>{tmp10});
    tmp12 = Convert_intptr_uint32_0(state_, TNode<Uint32T>{tmp11});
    tmp13 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x20ull));
    tmp14 = CodeStubAssembler(state_).WordShl(TNode<IntPtrT>{tmp12}, TNode<IntPtrT>{tmp13});
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{p_toRef.object, p_toRef.offset}, tmp14);
    ca_.Goto(&block11);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    if ((wasm::kIsBigEndianOnSim)) {
      ca_.Goto(&block12);
    } else {
      ca_.Goto(&block13);
    }
  }

  TNode<IntPtrT> tmp15;
  TNode<BoolT> tmp16;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp15 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp16 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{p_locationAllocator.remainingFPRegs}, TNode<IntPtrT>{tmp15});
    ca_.Branch(tmp16, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  TNode<Float32T> tmp17;
  TNode<Uint32T> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp17 = ca_.CallBuiltin<Float32T>(Builtin::kWasmTaggedToFloat32, p_context, p_param);
    tmp18 = Bitcast_uint32_float32_0(state_, TNode<Float32T>{tmp17});
    tmp19 = Convert_intptr_uint32_0(state_, TNode<Uint32T>{tmp18});
    tmp20 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x20ull));
    tmp21 = CodeStubAssembler(state_).WordShl(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp20});
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{p_toRef.object, p_toRef.offset}, tmp21);
    ca_.Goto(&block18);
  }

  TNode<Float32T> tmp22;
  TNode<Uint32T> tmp23;
  TNode<IntPtrT> tmp24;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp22 = ca_.CallBuiltin<Float32T>(Builtin::kWasmTaggedToFloat32, p_context, p_param);
    tmp23 = Bitcast_uint32_float32_0(state_, TNode<Float32T>{tmp22});
    tmp24 = Convert_intptr_uint32_0(state_, TNode<Uint32T>{tmp23});
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{p_toRef.object, p_toRef.offset}, tmp24);
    ca_.Goto(&block18);
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.Goto(&block14);
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block14);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    ca_.Goto(&block11);
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block4);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block19);
  }

    ca_.Bind(&block19);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=484&c=1
TNode<Object> JSToWasmWrapperHelper_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<Object> p__receiver, TNode<JSFunction> p_target, TorqueStructArguments p_arguments, wasm::Promise p_promise) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block69(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block75(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block76(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block73(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block77(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block81(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block82(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block84(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block85(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block80(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block78(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block79(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block93(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block96(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block97(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block101(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block99(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block112(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block113(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, BoolT> block114(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block110(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block116(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block117(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block119(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block120(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block122(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block123(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block124(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block121(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block115(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT> block111(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT> block100(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT, IntPtrT> block94(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT, IntPtrT> block126(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT, IntPtrT> block127(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, IntPtrT, IntPtrT, BoolT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block125(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT> block132(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT> block131(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT> block133(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT> block134(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, Object, IntPtrT> block135(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T> block138(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T> block136(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block141(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block145(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block146(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block148(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block149(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block151(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block152(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block147(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block144(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block156(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block155(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block153(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block142(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block157(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block161(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block162(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block164(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block165(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block167(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block168(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block163(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block160(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block169(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block170(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block171(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block158(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block172(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block176(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block177(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block178(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block182(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block183(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block185(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block186(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block181(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block179(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block175(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block173(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block187(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block190(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block194(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block195(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block197(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block198(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block200(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block201(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block196(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block193(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block191(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block203(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block204(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block206(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block207(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block209(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block210(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block205(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block202(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block212(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block213(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block215(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block216(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block218(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT> block219(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT, Object, IntPtrT> block214(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object, IntPtrT, Object, IntPtrT> block211(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block192(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block188(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Object, Int32T> block227(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Object, Int32T> block228(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Int32T> block233(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, Int32T> block234(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block189(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block174(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block159(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block143(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T> block137(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block237(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block240(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block241(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block238(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object> block239(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block242(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block245(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block246(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T, Int32T> block249(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T, Int32T> block247(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T, Int32T> block253(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T, Int32T> block254(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T, Int32T, BoolT> block255(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T, Int32T> block251(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T, Int32T> block252(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T> block260(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T> block261(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T> block265(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T> block266(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T> block268(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T> block269(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T> block271(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T> block272(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T, Object, IntPtrT> block267(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T, Object, IntPtrT> block264(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Int32T, Int32T> block248(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block243(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, IntPtrT> block275(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, IntPtrT> block276(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block277(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block278(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block280(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block281(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block283(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T> block284(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object> block282(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, BoolT, Object, Int32T, Object> block279(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block286(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<SharedFunctionInfo> tmp1;
  TNode<WasmExportedFunctionData> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp1 = CodeStubAssembler(state_).LoadReference<SharedFunctionInfo>(CodeStubAssembler::Reference{p_target, tmp0});
    tmp2 = CodeStubAssembler(state_).LoadSharedFunctionInfoWasmExportedFunctionData(TNode<SharedFunctionInfo>{tmp1});
    if (((CodeStubAssembler(state_).ConstexprBoolNot(((CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kPromise)) || (CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kStressSwitch))))))) {
      ca_.Goto(&block2);
    } else {
      ca_.Goto(&block3);
    }
  }

  TNode<IntPtrT> tmp3;
  TNode<Cell> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<Object> tmp6;
  TNode<Smi> tmp7;
  TNode<Smi> tmp8;
  TNode<Smi> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<Cell> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Smi> tmp13;
  TNode<BoolT> tmp14;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp4 = CodeStubAssembler(state_).LoadReference<Cell>(CodeStubAssembler::Reference{tmp2, tmp3});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp6 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp4, tmp5});
    tmp7 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp6});
    tmp8 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
    tmp9 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp7}, TNode<Smi>{tmp8});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp11 = CodeStubAssembler(state_).LoadReference<Cell>(CodeStubAssembler::Reference{tmp2, tmp10});
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp11, tmp12}, tmp9);
    tmp13 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
    tmp14 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp9}, TNode<Smi>{tmp13});
    ca_.Branch(tmp14, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp15;
  TNode<Object> tmp16;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp15 = kNoContext_0(state_);
    tmp16 = CodeStubAssembler(state_).CallRuntime(Runtime::kTierUpJSToWasmWrapper, tmp15, tmp2); 
    ca_.Goto(&block6);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block4);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block4);
  }

  TNode<IntPtrT> tmp17;
  TNode<RawPtrT> tmp18;
  TNode<WasmInternalFunction> tmp19;
  TNode<TrustedObject> tmp20;
  TNode<WasmTrustedInstanceData> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<Object> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<Int32T> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<Object> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<Int32T> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<Object> tmp33;
  TNode<IntPtrT> tmp34;
  TNode<RawPtrT> tmp35;
  TNode<RawPtrT> tmp36;
  TNode<Int32T> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<Object> tmp39;
  TNode<IntPtrT> tmp40;
  TNode<IntPtrT> tmp41;
  TNode<Undefined> tmp42;
  TNode<IntPtrT> tmp43;
  TNode<BoolT> tmp44;
  TNode<Int32T> tmp45;
  TNode<BoolT> tmp46;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 44);
    tmp18 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp2, tmp17});
    tmp19 = CodeStubAssembler(state_).LoadWasmInternalFunctionFromFunctionData(TNode<WasmFunctionData>{tmp2});
    tmp20 = CodeStubAssembler(state_).LoadImplicitArgFromWasmInternalFunction(TNode<WasmInternalFunction>{tmp19});
    tmp21 = CodeStubAssembler(state_).LoadWasmTrustedInstanceDataFromWasmExportedFunctionData(TNode<WasmExportedFunctionData>{tmp2});
    tmp22 = FromConstexpr_intptr_constexpr_intptr_0(state_, wasm::FunctionSig::kParameterCountOffset);
    std::tie(tmp23, tmp24) = GetRefAt_intptr_RawFunctionSigPtr_0(state_, TNode<RawPtrT>{tmp18}, TNode<IntPtrT>{tmp22}).Flatten();
    tmp25 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{tmp23, tmp24});
    tmp26 = CodeStubAssembler(state_).TruncateIntPtrToInt32(TNode<IntPtrT>{tmp25});
    tmp27 = FromConstexpr_intptr_constexpr_intptr_0(state_, wasm::FunctionSig::kReturnCountOffset);
    std::tie(tmp28, tmp29) = GetRefAt_intptr_RawFunctionSigPtr_0(state_, TNode<RawPtrT>{tmp18}, TNode<IntPtrT>{tmp27}).Flatten();
    tmp30 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{tmp28, tmp29});
    tmp31 = CodeStubAssembler(state_).TruncateIntPtrToInt32(TNode<IntPtrT>{tmp30});
    tmp32 = FromConstexpr_intptr_constexpr_intptr_0(state_, wasm::FunctionSig::kRepsOffset);
    std::tie(tmp33, tmp34) = GetRefAt_WasmCodePointer_RawFunctionSigPtr_0(state_, TNode<RawPtrT>{tmp18}, TNode<IntPtrT>{tmp32}).Flatten();
    tmp35 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp33, tmp34});
    tmp36 = (TNode<RawPtrT>{tmp35});
    tmp37 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp26}, TNode<Int32T>{tmp31});
    tmp38 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp37});
    std::tie(tmp39, tmp40, tmp41) = NewOffHeapConstSlice_int32_0(state_, TNode<RawPtrT>{tmp36}, TNode<IntPtrT>{tmp38}).Flatten();
    tmp42 = Undefined_0(state_);
    tmp43 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp44 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp45 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp46 = CodeStubAssembler(state_).Int32GreaterThan(TNode<Int32T>{tmp31}, TNode<Int32T>{tmp45});
    ca_.Branch(tmp46, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{tmp42, tmp43, tmp44});
  }

  TNode<Smi> tmp47;
  TNode<JSArray> tmp48;
  TNode<IntPtrT> tmp49;
  TNode<IntPtrT> tmp50;
  TNode<Object> tmp51;
  TNode<IntPtrT> tmp52;
  TNode<IntPtrT> tmp53;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp47 = Convert_Smi_int32_0(state_, TNode<Int32T>{tmp31});
    tmp48 = ca_.CallBuiltin<JSArray>(Builtin::kWasmAllocateJSArray, p_context, tmp47);
    tmp49 = Convert_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp50 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp31});
    compiler::CodeAssemblerLabel label54(&ca_);
    std::tie(tmp51, tmp52, tmp53) = Subslice_int32_0(state_, TorqueStructSlice_int32_ConstReference_int32_0{TNode<Object>{tmp39}, TNode<IntPtrT>{tmp40}, TNode<IntPtrT>{tmp41}, TorqueStructUnsafe_0{}}, TNode<IntPtrT>{tmp49}, TNode<IntPtrT>{tmp50}, &label54).Flatten();
    ca_.Goto(&block11);
    if (label54.is_used()) {
      ca_.Bind(&label54);
      ca_.Goto(&block12);
    }
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp55;
  TNode<IntPtrT> tmp56;
  TNode<BoolT> tmp57;
  TNode<BoolT> tmp58;
  TNode<IntPtrT> tmp59;
  TNode<IntPtrT> tmp60;
  TNode<IntPtrT> tmp61;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    std::tie(tmp55, tmp56, tmp57, tmp58, tmp59) = NewReturnSlotAllocator_0(state_).Flatten();
    tmp60 = TimesSizeOf_int32_0(state_, TNode<IntPtrT>{tmp53});
    tmp61 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp52}, TNode<IntPtrT>{tmp60});
    ca_.Goto(&block16, tmp44, tmp55, tmp56, tmp57, tmp58, tmp59, tmp52);
  }

  TNode<BoolT> phi_bb16_19;
  TNode<IntPtrT> phi_bb16_23;
  TNode<IntPtrT> phi_bb16_24;
  TNode<BoolT> phi_bb16_25;
  TNode<BoolT> phi_bb16_26;
  TNode<IntPtrT> phi_bb16_27;
  TNode<IntPtrT> phi_bb16_29;
  TNode<BoolT> tmp62;
  TNode<BoolT> tmp63;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_19, &phi_bb16_23, &phi_bb16_24, &phi_bb16_25, &phi_bb16_26, &phi_bb16_27, &phi_bb16_29);
    tmp62 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb16_29}, TNode<IntPtrT>{tmp61});
    tmp63 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp62});
    ca_.Branch(tmp63, &block14, std::vector<compiler::Node*>{phi_bb16_19, phi_bb16_23, phi_bb16_24, phi_bb16_25, phi_bb16_26, phi_bb16_27, phi_bb16_29}, &block15, std::vector<compiler::Node*>{phi_bb16_19, phi_bb16_23, phi_bb16_24, phi_bb16_25, phi_bb16_26, phi_bb16_27, phi_bb16_29});
  }

  TNode<BoolT> phi_bb14_19;
  TNode<IntPtrT> phi_bb14_23;
  TNode<IntPtrT> phi_bb14_24;
  TNode<BoolT> phi_bb14_25;
  TNode<BoolT> phi_bb14_26;
  TNode<IntPtrT> phi_bb14_27;
  TNode<IntPtrT> phi_bb14_29;
  TNode<Object> tmp64;
  TNode<IntPtrT> tmp65;
  TNode<IntPtrT> tmp66;
  TNode<IntPtrT> tmp67;
  TNode<Int32T> tmp68;
  TNode<Int32T> tmp69;
  TNode<BoolT> tmp70;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_19, &phi_bb14_23, &phi_bb14_24, &phi_bb14_25, &phi_bb14_26, &phi_bb14_27, &phi_bb14_29);
    std::tie(tmp64, tmp65) = NewReference_int32_0(state_, TNode<Object>{tmp51}, TNode<IntPtrT>{phi_bb14_29}).Flatten();
    tmp66 = FromConstexpr_intptr_constexpr_int31_0(state_, kInt32Size);
    tmp67 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb14_29}, TNode<IntPtrT>{tmp66});
    tmp68 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp64, tmp65});
    tmp69 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI32.raw_bit_field());
    tmp70 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp68}, TNode<Int32T>{tmp69});
    ca_.Branch(tmp70, &block25, std::vector<compiler::Node*>{phi_bb14_19, phi_bb14_23, phi_bb14_24, phi_bb14_25, phi_bb14_26, phi_bb14_27}, &block26, std::vector<compiler::Node*>{phi_bb14_19, phi_bb14_23, phi_bb14_24, phi_bb14_25, phi_bb14_26, phi_bb14_27});
  }

  TNode<BoolT> phi_bb25_19;
  TNode<IntPtrT> phi_bb25_23;
  TNode<IntPtrT> phi_bb25_24;
  TNode<BoolT> phi_bb25_25;
  TNode<BoolT> phi_bb25_26;
  TNode<IntPtrT> phi_bb25_27;
  TNode<IntPtrT> tmp71;
  TNode<BoolT> tmp72;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_19, &phi_bb25_23, &phi_bb25_24, &phi_bb25_25, &phi_bb25_26, &phi_bb25_27);
    tmp71 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp72 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb25_23}, TNode<IntPtrT>{tmp71});
    ca_.Branch(tmp72, &block29, std::vector<compiler::Node*>{phi_bb25_19, phi_bb25_23, phi_bb25_24, phi_bb25_25, phi_bb25_26, phi_bb25_27}, &block30, std::vector<compiler::Node*>{phi_bb25_19, phi_bb25_23, phi_bb25_24, phi_bb25_25, phi_bb25_26, phi_bb25_27});
  }

  TNode<BoolT> phi_bb29_19;
  TNode<IntPtrT> phi_bb29_23;
  TNode<IntPtrT> phi_bb29_24;
  TNode<BoolT> phi_bb29_25;
  TNode<BoolT> phi_bb29_26;
  TNode<IntPtrT> phi_bb29_27;
  TNode<IntPtrT> tmp73;
  TNode<IntPtrT> tmp74;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_19, &phi_bb29_23, &phi_bb29_24, &phi_bb29_25, &phi_bb29_26, &phi_bb29_27);
    tmp73 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp74 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb29_23}, TNode<IntPtrT>{tmp73});
    ca_.Goto(&block28, phi_bb29_19, tmp74, phi_bb29_24, phi_bb29_25, phi_bb29_26, phi_bb29_27);
  }

  TNode<BoolT> phi_bb30_19;
  TNode<IntPtrT> phi_bb30_23;
  TNode<IntPtrT> phi_bb30_24;
  TNode<BoolT> phi_bb30_25;
  TNode<BoolT> phi_bb30_26;
  TNode<IntPtrT> phi_bb30_27;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_19, &phi_bb30_23, &phi_bb30_24, &phi_bb30_25, &phi_bb30_26, &phi_bb30_27);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block32, phi_bb30_19, phi_bb30_23, phi_bb30_24, phi_bb30_25, phi_bb30_26, phi_bb30_27);
    } else {
      ca_.Goto(&block33, phi_bb30_19, phi_bb30_23, phi_bb30_24, phi_bb30_25, phi_bb30_26, phi_bb30_27);
    }
  }

  TNode<BoolT> phi_bb32_19;
  TNode<IntPtrT> phi_bb32_23;
  TNode<IntPtrT> phi_bb32_24;
  TNode<BoolT> phi_bb32_25;
  TNode<BoolT> phi_bb32_26;
  TNode<IntPtrT> phi_bb32_27;
  TNode<IntPtrT> tmp75;
  TNode<IntPtrT> tmp76;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_19, &phi_bb32_23, &phi_bb32_24, &phi_bb32_25, &phi_bb32_26, &phi_bb32_27);
    tmp75 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp76 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb32_27}, TNode<IntPtrT>{tmp75});
    ca_.Goto(&block34, phi_bb32_19, phi_bb32_23, phi_bb32_24, phi_bb32_25, phi_bb32_26, tmp76);
  }

  TNode<BoolT> phi_bb33_19;
  TNode<IntPtrT> phi_bb33_23;
  TNode<IntPtrT> phi_bb33_24;
  TNode<BoolT> phi_bb33_25;
  TNode<BoolT> phi_bb33_26;
  TNode<IntPtrT> phi_bb33_27;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_19, &phi_bb33_23, &phi_bb33_24, &phi_bb33_25, &phi_bb33_26, &phi_bb33_27);
    ca_.Branch(phi_bb33_25, &block35, std::vector<compiler::Node*>{phi_bb33_19, phi_bb33_23, phi_bb33_24, phi_bb33_25, phi_bb33_26, phi_bb33_27}, &block36, std::vector<compiler::Node*>{phi_bb33_19, phi_bb33_23, phi_bb33_24, phi_bb33_25, phi_bb33_26, phi_bb33_27});
  }

  TNode<BoolT> phi_bb35_19;
  TNode<IntPtrT> phi_bb35_23;
  TNode<IntPtrT> phi_bb35_24;
  TNode<BoolT> phi_bb35_25;
  TNode<BoolT> phi_bb35_26;
  TNode<IntPtrT> phi_bb35_27;
  TNode<BoolT> tmp77;
  TNode<BoolT> tmp78;
  if (block35.is_used()) {
    ca_.Bind(&block35, &phi_bb35_19, &phi_bb35_23, &phi_bb35_24, &phi_bb35_25, &phi_bb35_26, &phi_bb35_27);
    tmp77 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp78 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block37, phi_bb35_19, phi_bb35_23, phi_bb35_24, tmp77, tmp78, phi_bb35_27);
  }

  TNode<BoolT> phi_bb36_19;
  TNode<IntPtrT> phi_bb36_23;
  TNode<IntPtrT> phi_bb36_24;
  TNode<BoolT> phi_bb36_25;
  TNode<BoolT> phi_bb36_26;
  TNode<IntPtrT> phi_bb36_27;
  TNode<IntPtrT> tmp79;
  TNode<IntPtrT> tmp80;
  TNode<BoolT> tmp81;
  TNode<BoolT> tmp82;
  if (block36.is_used()) {
    ca_.Bind(&block36, &phi_bb36_19, &phi_bb36_23, &phi_bb36_24, &phi_bb36_25, &phi_bb36_26, &phi_bb36_27);
    tmp79 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp80 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb36_27}, TNode<IntPtrT>{tmp79});
    tmp81 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp82 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block37, phi_bb36_19, phi_bb36_23, phi_bb36_24, tmp81, tmp82, tmp80);
  }

  TNode<BoolT> phi_bb37_19;
  TNode<IntPtrT> phi_bb37_23;
  TNode<IntPtrT> phi_bb37_24;
  TNode<BoolT> phi_bb37_25;
  TNode<BoolT> phi_bb37_26;
  TNode<IntPtrT> phi_bb37_27;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_19, &phi_bb37_23, &phi_bb37_24, &phi_bb37_25, &phi_bb37_26, &phi_bb37_27);
    ca_.Goto(&block34, phi_bb37_19, phi_bb37_23, phi_bb37_24, phi_bb37_25, phi_bb37_26, phi_bb37_27);
  }

  TNode<BoolT> phi_bb34_19;
  TNode<IntPtrT> phi_bb34_23;
  TNode<IntPtrT> phi_bb34_24;
  TNode<BoolT> phi_bb34_25;
  TNode<BoolT> phi_bb34_26;
  TNode<IntPtrT> phi_bb34_27;
  if (block34.is_used()) {
    ca_.Bind(&block34, &phi_bb34_19, &phi_bb34_23, &phi_bb34_24, &phi_bb34_25, &phi_bb34_26, &phi_bb34_27);
    ca_.Goto(&block28, phi_bb34_19, phi_bb34_23, phi_bb34_24, phi_bb34_25, phi_bb34_26, phi_bb34_27);
  }

  TNode<BoolT> phi_bb28_19;
  TNode<IntPtrT> phi_bb28_23;
  TNode<IntPtrT> phi_bb28_24;
  TNode<BoolT> phi_bb28_25;
  TNode<BoolT> phi_bb28_26;
  TNode<IntPtrT> phi_bb28_27;
  if (block28.is_used()) {
    ca_.Bind(&block28, &phi_bb28_19, &phi_bb28_23, &phi_bb28_24, &phi_bb28_25, &phi_bb28_26, &phi_bb28_27);
    ca_.Goto(&block27, phi_bb28_19, phi_bb28_23, phi_bb28_24, phi_bb28_25, phi_bb28_26, phi_bb28_27);
  }

  TNode<BoolT> phi_bb26_19;
  TNode<IntPtrT> phi_bb26_23;
  TNode<IntPtrT> phi_bb26_24;
  TNode<BoolT> phi_bb26_25;
  TNode<BoolT> phi_bb26_26;
  TNode<IntPtrT> phi_bb26_27;
  TNode<Int32T> tmp83;
  TNode<BoolT> tmp84;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_19, &phi_bb26_23, &phi_bb26_24, &phi_bb26_25, &phi_bb26_26, &phi_bb26_27);
    tmp83 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI64.raw_bit_field());
    tmp84 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp68}, TNode<Int32T>{tmp83});
    ca_.Branch(tmp84, &block38, std::vector<compiler::Node*>{phi_bb26_19, phi_bb26_23, phi_bb26_24, phi_bb26_25, phi_bb26_26, phi_bb26_27}, &block39, std::vector<compiler::Node*>{phi_bb26_19, phi_bb26_23, phi_bb26_24, phi_bb26_25, phi_bb26_26, phi_bb26_27});
  }

  TNode<BoolT> phi_bb38_19;
  TNode<IntPtrT> phi_bb38_23;
  TNode<IntPtrT> phi_bb38_24;
  TNode<BoolT> phi_bb38_25;
  TNode<BoolT> phi_bb38_26;
  TNode<IntPtrT> phi_bb38_27;
  TNode<IntPtrT> tmp85;
  TNode<BoolT> tmp86;
  if (block38.is_used()) {
    ca_.Bind(&block38, &phi_bb38_19, &phi_bb38_23, &phi_bb38_24, &phi_bb38_25, &phi_bb38_26, &phi_bb38_27);
    tmp85 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp86 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb38_23}, TNode<IntPtrT>{tmp85});
    ca_.Branch(tmp86, &block42, std::vector<compiler::Node*>{phi_bb38_19, phi_bb38_23, phi_bb38_24, phi_bb38_25, phi_bb38_26, phi_bb38_27}, &block43, std::vector<compiler::Node*>{phi_bb38_19, phi_bb38_23, phi_bb38_24, phi_bb38_25, phi_bb38_26, phi_bb38_27});
  }

  TNode<BoolT> phi_bb42_19;
  TNode<IntPtrT> phi_bb42_23;
  TNode<IntPtrT> phi_bb42_24;
  TNode<BoolT> phi_bb42_25;
  TNode<BoolT> phi_bb42_26;
  TNode<IntPtrT> phi_bb42_27;
  TNode<IntPtrT> tmp87;
  TNode<IntPtrT> tmp88;
  if (block42.is_used()) {
    ca_.Bind(&block42, &phi_bb42_19, &phi_bb42_23, &phi_bb42_24, &phi_bb42_25, &phi_bb42_26, &phi_bb42_27);
    tmp87 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp88 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb42_23}, TNode<IntPtrT>{tmp87});
    ca_.Goto(&block41, phi_bb42_19, tmp88, phi_bb42_24, phi_bb42_25, phi_bb42_26, phi_bb42_27);
  }

  TNode<BoolT> phi_bb43_19;
  TNode<IntPtrT> phi_bb43_23;
  TNode<IntPtrT> phi_bb43_24;
  TNode<BoolT> phi_bb43_25;
  TNode<BoolT> phi_bb43_26;
  TNode<IntPtrT> phi_bb43_27;
  if (block43.is_used()) {
    ca_.Bind(&block43, &phi_bb43_19, &phi_bb43_23, &phi_bb43_24, &phi_bb43_25, &phi_bb43_26, &phi_bb43_27);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block45, phi_bb43_19, phi_bb43_23, phi_bb43_24, phi_bb43_25, phi_bb43_26, phi_bb43_27);
    } else {
      ca_.Goto(&block46, phi_bb43_19, phi_bb43_23, phi_bb43_24, phi_bb43_25, phi_bb43_26, phi_bb43_27);
    }
  }

  TNode<BoolT> phi_bb45_19;
  TNode<IntPtrT> phi_bb45_23;
  TNode<IntPtrT> phi_bb45_24;
  TNode<BoolT> phi_bb45_25;
  TNode<BoolT> phi_bb45_26;
  TNode<IntPtrT> phi_bb45_27;
  TNode<IntPtrT> tmp89;
  TNode<IntPtrT> tmp90;
  if (block45.is_used()) {
    ca_.Bind(&block45, &phi_bb45_19, &phi_bb45_23, &phi_bb45_24, &phi_bb45_25, &phi_bb45_26, &phi_bb45_27);
    tmp89 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp90 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb45_27}, TNode<IntPtrT>{tmp89});
    ca_.Goto(&block47, phi_bb45_19, phi_bb45_23, phi_bb45_24, phi_bb45_25, phi_bb45_26, tmp90);
  }

  TNode<BoolT> phi_bb46_19;
  TNode<IntPtrT> phi_bb46_23;
  TNode<IntPtrT> phi_bb46_24;
  TNode<BoolT> phi_bb46_25;
  TNode<BoolT> phi_bb46_26;
  TNode<IntPtrT> phi_bb46_27;
  if (block46.is_used()) {
    ca_.Bind(&block46, &phi_bb46_19, &phi_bb46_23, &phi_bb46_24, &phi_bb46_25, &phi_bb46_26, &phi_bb46_27);
    ca_.Branch(phi_bb46_25, &block48, std::vector<compiler::Node*>{phi_bb46_19, phi_bb46_23, phi_bb46_24, phi_bb46_25, phi_bb46_26, phi_bb46_27}, &block49, std::vector<compiler::Node*>{phi_bb46_19, phi_bb46_23, phi_bb46_24, phi_bb46_25, phi_bb46_26, phi_bb46_27});
  }

  TNode<BoolT> phi_bb48_19;
  TNode<IntPtrT> phi_bb48_23;
  TNode<IntPtrT> phi_bb48_24;
  TNode<BoolT> phi_bb48_25;
  TNode<BoolT> phi_bb48_26;
  TNode<IntPtrT> phi_bb48_27;
  TNode<BoolT> tmp91;
  TNode<BoolT> tmp92;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_19, &phi_bb48_23, &phi_bb48_24, &phi_bb48_25, &phi_bb48_26, &phi_bb48_27);
    tmp91 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp92 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block50, phi_bb48_19, phi_bb48_23, phi_bb48_24, tmp91, tmp92, phi_bb48_27);
  }

  TNode<BoolT> phi_bb49_19;
  TNode<IntPtrT> phi_bb49_23;
  TNode<IntPtrT> phi_bb49_24;
  TNode<BoolT> phi_bb49_25;
  TNode<BoolT> phi_bb49_26;
  TNode<IntPtrT> phi_bb49_27;
  TNode<IntPtrT> tmp93;
  TNode<IntPtrT> tmp94;
  TNode<BoolT> tmp95;
  TNode<BoolT> tmp96;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_19, &phi_bb49_23, &phi_bb49_24, &phi_bb49_25, &phi_bb49_26, &phi_bb49_27);
    tmp93 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp94 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb49_27}, TNode<IntPtrT>{tmp93});
    tmp95 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp96 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block50, phi_bb49_19, phi_bb49_23, phi_bb49_24, tmp95, tmp96, tmp94);
  }

  TNode<BoolT> phi_bb50_19;
  TNode<IntPtrT> phi_bb50_23;
  TNode<IntPtrT> phi_bb50_24;
  TNode<BoolT> phi_bb50_25;
  TNode<BoolT> phi_bb50_26;
  TNode<IntPtrT> phi_bb50_27;
  if (block50.is_used()) {
    ca_.Bind(&block50, &phi_bb50_19, &phi_bb50_23, &phi_bb50_24, &phi_bb50_25, &phi_bb50_26, &phi_bb50_27);
    ca_.Goto(&block47, phi_bb50_19, phi_bb50_23, phi_bb50_24, phi_bb50_25, phi_bb50_26, phi_bb50_27);
  }

  TNode<BoolT> phi_bb47_19;
  TNode<IntPtrT> phi_bb47_23;
  TNode<IntPtrT> phi_bb47_24;
  TNode<BoolT> phi_bb47_25;
  TNode<BoolT> phi_bb47_26;
  TNode<IntPtrT> phi_bb47_27;
  if (block47.is_used()) {
    ca_.Bind(&block47, &phi_bb47_19, &phi_bb47_23, &phi_bb47_24, &phi_bb47_25, &phi_bb47_26, &phi_bb47_27);
    ca_.Goto(&block41, phi_bb47_19, phi_bb47_23, phi_bb47_24, phi_bb47_25, phi_bb47_26, phi_bb47_27);
  }

  TNode<BoolT> phi_bb41_19;
  TNode<IntPtrT> phi_bb41_23;
  TNode<IntPtrT> phi_bb41_24;
  TNode<BoolT> phi_bb41_25;
  TNode<BoolT> phi_bb41_26;
  TNode<IntPtrT> phi_bb41_27;
  if (block41.is_used()) {
    ca_.Bind(&block41, &phi_bb41_19, &phi_bb41_23, &phi_bb41_24, &phi_bb41_25, &phi_bb41_26, &phi_bb41_27);
    if (((CodeStubAssembler(state_).ConstexprBoolNot((CodeStubAssembler(state_).Is64()))))) {
      ca_.Goto(&block51, phi_bb41_19, phi_bb41_23, phi_bb41_24, phi_bb41_25, phi_bb41_26, phi_bb41_27);
    } else {
      ca_.Goto(&block52, phi_bb41_19, phi_bb41_23, phi_bb41_24, phi_bb41_25, phi_bb41_26, phi_bb41_27);
    }
  }

  TNode<BoolT> phi_bb51_19;
  TNode<IntPtrT> phi_bb51_23;
  TNode<IntPtrT> phi_bb51_24;
  TNode<BoolT> phi_bb51_25;
  TNode<BoolT> phi_bb51_26;
  TNode<IntPtrT> phi_bb51_27;
  TNode<IntPtrT> tmp97;
  TNode<BoolT> tmp98;
  if (block51.is_used()) {
    ca_.Bind(&block51, &phi_bb51_19, &phi_bb51_23, &phi_bb51_24, &phi_bb51_25, &phi_bb51_26, &phi_bb51_27);
    tmp97 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp98 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb51_23}, TNode<IntPtrT>{tmp97});
    ca_.Branch(tmp98, &block55, std::vector<compiler::Node*>{phi_bb51_19, phi_bb51_23, phi_bb51_24, phi_bb51_25, phi_bb51_26, phi_bb51_27}, &block56, std::vector<compiler::Node*>{phi_bb51_19, phi_bb51_23, phi_bb51_24, phi_bb51_25, phi_bb51_26, phi_bb51_27});
  }

  TNode<BoolT> phi_bb55_19;
  TNode<IntPtrT> phi_bb55_23;
  TNode<IntPtrT> phi_bb55_24;
  TNode<BoolT> phi_bb55_25;
  TNode<BoolT> phi_bb55_26;
  TNode<IntPtrT> phi_bb55_27;
  TNode<IntPtrT> tmp99;
  TNode<IntPtrT> tmp100;
  if (block55.is_used()) {
    ca_.Bind(&block55, &phi_bb55_19, &phi_bb55_23, &phi_bb55_24, &phi_bb55_25, &phi_bb55_26, &phi_bb55_27);
    tmp99 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp100 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb55_23}, TNode<IntPtrT>{tmp99});
    ca_.Goto(&block54, phi_bb55_19, tmp100, phi_bb55_24, phi_bb55_25, phi_bb55_26, phi_bb55_27);
  }

  TNode<BoolT> phi_bb56_19;
  TNode<IntPtrT> phi_bb56_23;
  TNode<IntPtrT> phi_bb56_24;
  TNode<BoolT> phi_bb56_25;
  TNode<BoolT> phi_bb56_26;
  TNode<IntPtrT> phi_bb56_27;
  if (block56.is_used()) {
    ca_.Bind(&block56, &phi_bb56_19, &phi_bb56_23, &phi_bb56_24, &phi_bb56_25, &phi_bb56_26, &phi_bb56_27);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block58, phi_bb56_19, phi_bb56_23, phi_bb56_24, phi_bb56_25, phi_bb56_26, phi_bb56_27);
    } else {
      ca_.Goto(&block59, phi_bb56_19, phi_bb56_23, phi_bb56_24, phi_bb56_25, phi_bb56_26, phi_bb56_27);
    }
  }

  TNode<BoolT> phi_bb58_19;
  TNode<IntPtrT> phi_bb58_23;
  TNode<IntPtrT> phi_bb58_24;
  TNode<BoolT> phi_bb58_25;
  TNode<BoolT> phi_bb58_26;
  TNode<IntPtrT> phi_bb58_27;
  TNode<IntPtrT> tmp101;
  TNode<IntPtrT> tmp102;
  if (block58.is_used()) {
    ca_.Bind(&block58, &phi_bb58_19, &phi_bb58_23, &phi_bb58_24, &phi_bb58_25, &phi_bb58_26, &phi_bb58_27);
    tmp101 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp102 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb58_27}, TNode<IntPtrT>{tmp101});
    ca_.Goto(&block60, phi_bb58_19, phi_bb58_23, phi_bb58_24, phi_bb58_25, phi_bb58_26, tmp102);
  }

  TNode<BoolT> phi_bb59_19;
  TNode<IntPtrT> phi_bb59_23;
  TNode<IntPtrT> phi_bb59_24;
  TNode<BoolT> phi_bb59_25;
  TNode<BoolT> phi_bb59_26;
  TNode<IntPtrT> phi_bb59_27;
  if (block59.is_used()) {
    ca_.Bind(&block59, &phi_bb59_19, &phi_bb59_23, &phi_bb59_24, &phi_bb59_25, &phi_bb59_26, &phi_bb59_27);
    ca_.Branch(phi_bb59_25, &block61, std::vector<compiler::Node*>{phi_bb59_19, phi_bb59_23, phi_bb59_24, phi_bb59_25, phi_bb59_26, phi_bb59_27}, &block62, std::vector<compiler::Node*>{phi_bb59_19, phi_bb59_23, phi_bb59_24, phi_bb59_25, phi_bb59_26, phi_bb59_27});
  }

  TNode<BoolT> phi_bb61_19;
  TNode<IntPtrT> phi_bb61_23;
  TNode<IntPtrT> phi_bb61_24;
  TNode<BoolT> phi_bb61_25;
  TNode<BoolT> phi_bb61_26;
  TNode<IntPtrT> phi_bb61_27;
  TNode<BoolT> tmp103;
  TNode<BoolT> tmp104;
  if (block61.is_used()) {
    ca_.Bind(&block61, &phi_bb61_19, &phi_bb61_23, &phi_bb61_24, &phi_bb61_25, &phi_bb61_26, &phi_bb61_27);
    tmp103 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp104 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block63, phi_bb61_19, phi_bb61_23, phi_bb61_24, tmp103, tmp104, phi_bb61_27);
  }

  TNode<BoolT> phi_bb62_19;
  TNode<IntPtrT> phi_bb62_23;
  TNode<IntPtrT> phi_bb62_24;
  TNode<BoolT> phi_bb62_25;
  TNode<BoolT> phi_bb62_26;
  TNode<IntPtrT> phi_bb62_27;
  TNode<IntPtrT> tmp105;
  TNode<IntPtrT> tmp106;
  TNode<BoolT> tmp107;
  TNode<BoolT> tmp108;
  if (block62.is_used()) {
    ca_.Bind(&block62, &phi_bb62_19, &phi_bb62_23, &phi_bb62_24, &phi_bb62_25, &phi_bb62_26, &phi_bb62_27);
    tmp105 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp106 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb62_27}, TNode<IntPtrT>{tmp105});
    tmp107 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp108 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block63, phi_bb62_19, phi_bb62_23, phi_bb62_24, tmp107, tmp108, tmp106);
  }

  TNode<BoolT> phi_bb63_19;
  TNode<IntPtrT> phi_bb63_23;
  TNode<IntPtrT> phi_bb63_24;
  TNode<BoolT> phi_bb63_25;
  TNode<BoolT> phi_bb63_26;
  TNode<IntPtrT> phi_bb63_27;
  if (block63.is_used()) {
    ca_.Bind(&block63, &phi_bb63_19, &phi_bb63_23, &phi_bb63_24, &phi_bb63_25, &phi_bb63_26, &phi_bb63_27);
    ca_.Goto(&block60, phi_bb63_19, phi_bb63_23, phi_bb63_24, phi_bb63_25, phi_bb63_26, phi_bb63_27);
  }

  TNode<BoolT> phi_bb60_19;
  TNode<IntPtrT> phi_bb60_23;
  TNode<IntPtrT> phi_bb60_24;
  TNode<BoolT> phi_bb60_25;
  TNode<BoolT> phi_bb60_26;
  TNode<IntPtrT> phi_bb60_27;
  if (block60.is_used()) {
    ca_.Bind(&block60, &phi_bb60_19, &phi_bb60_23, &phi_bb60_24, &phi_bb60_25, &phi_bb60_26, &phi_bb60_27);
    ca_.Goto(&block54, phi_bb60_19, phi_bb60_23, phi_bb60_24, phi_bb60_25, phi_bb60_26, phi_bb60_27);
  }

  TNode<BoolT> phi_bb54_19;
  TNode<IntPtrT> phi_bb54_23;
  TNode<IntPtrT> phi_bb54_24;
  TNode<BoolT> phi_bb54_25;
  TNode<BoolT> phi_bb54_26;
  TNode<IntPtrT> phi_bb54_27;
  if (block54.is_used()) {
    ca_.Bind(&block54, &phi_bb54_19, &phi_bb54_23, &phi_bb54_24, &phi_bb54_25, &phi_bb54_26, &phi_bb54_27);
    ca_.Goto(&block53, phi_bb54_19, phi_bb54_23, phi_bb54_24, phi_bb54_25, phi_bb54_26, phi_bb54_27);
  }

  TNode<BoolT> phi_bb52_19;
  TNode<IntPtrT> phi_bb52_23;
  TNode<IntPtrT> phi_bb52_24;
  TNode<BoolT> phi_bb52_25;
  TNode<BoolT> phi_bb52_26;
  TNode<IntPtrT> phi_bb52_27;
  if (block52.is_used()) {
    ca_.Bind(&block52, &phi_bb52_19, &phi_bb52_23, &phi_bb52_24, &phi_bb52_25, &phi_bb52_26, &phi_bb52_27);
    ca_.Goto(&block53, phi_bb52_19, phi_bb52_23, phi_bb52_24, phi_bb52_25, phi_bb52_26, phi_bb52_27);
  }

  TNode<BoolT> phi_bb53_19;
  TNode<IntPtrT> phi_bb53_23;
  TNode<IntPtrT> phi_bb53_24;
  TNode<BoolT> phi_bb53_25;
  TNode<BoolT> phi_bb53_26;
  TNode<IntPtrT> phi_bb53_27;
  if (block53.is_used()) {
    ca_.Bind(&block53, &phi_bb53_19, &phi_bb53_23, &phi_bb53_24, &phi_bb53_25, &phi_bb53_26, &phi_bb53_27);
    ca_.Goto(&block40, phi_bb53_19, phi_bb53_23, phi_bb53_24, phi_bb53_25, phi_bb53_26, phi_bb53_27);
  }

  TNode<BoolT> phi_bb39_19;
  TNode<IntPtrT> phi_bb39_23;
  TNode<IntPtrT> phi_bb39_24;
  TNode<BoolT> phi_bb39_25;
  TNode<BoolT> phi_bb39_26;
  TNode<IntPtrT> phi_bb39_27;
  TNode<Int32T> tmp109;
  TNode<BoolT> tmp110;
  if (block39.is_used()) {
    ca_.Bind(&block39, &phi_bb39_19, &phi_bb39_23, &phi_bb39_24, &phi_bb39_25, &phi_bb39_26, &phi_bb39_27);
    tmp109 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF32.raw_bit_field());
    tmp110 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp68}, TNode<Int32T>{tmp109});
    ca_.Branch(tmp110, &block64, std::vector<compiler::Node*>{phi_bb39_19, phi_bb39_23, phi_bb39_24, phi_bb39_25, phi_bb39_26, phi_bb39_27}, &block65, std::vector<compiler::Node*>{phi_bb39_19, phi_bb39_23, phi_bb39_24, phi_bb39_25, phi_bb39_26, phi_bb39_27});
  }

  TNode<BoolT> phi_bb64_19;
  TNode<IntPtrT> phi_bb64_23;
  TNode<IntPtrT> phi_bb64_24;
  TNode<BoolT> phi_bb64_25;
  TNode<BoolT> phi_bb64_26;
  TNode<IntPtrT> phi_bb64_27;
  TNode<IntPtrT> tmp111;
  TNode<BoolT> tmp112;
  if (block64.is_used()) {
    ca_.Bind(&block64, &phi_bb64_19, &phi_bb64_23, &phi_bb64_24, &phi_bb64_25, &phi_bb64_26, &phi_bb64_27);
    tmp111 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp112 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb64_24}, TNode<IntPtrT>{tmp111});
    ca_.Branch(tmp112, &block68, std::vector<compiler::Node*>{phi_bb64_19, phi_bb64_23, phi_bb64_24, phi_bb64_25, phi_bb64_26, phi_bb64_27}, &block69, std::vector<compiler::Node*>{phi_bb64_19, phi_bb64_23, phi_bb64_24, phi_bb64_25, phi_bb64_26, phi_bb64_27});
  }

  TNode<BoolT> phi_bb68_19;
  TNode<IntPtrT> phi_bb68_23;
  TNode<IntPtrT> phi_bb68_24;
  TNode<BoolT> phi_bb68_25;
  TNode<BoolT> phi_bb68_26;
  TNode<IntPtrT> phi_bb68_27;
  TNode<IntPtrT> tmp113;
  TNode<IntPtrT> tmp114;
  if (block68.is_used()) {
    ca_.Bind(&block68, &phi_bb68_19, &phi_bb68_23, &phi_bb68_24, &phi_bb68_25, &phi_bb68_26, &phi_bb68_27);
    tmp113 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp114 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb68_24}, TNode<IntPtrT>{tmp113});
    ca_.Goto(&block67, phi_bb68_19, phi_bb68_23, tmp114, phi_bb68_25, phi_bb68_26, phi_bb68_27);
  }

  TNode<BoolT> phi_bb69_19;
  TNode<IntPtrT> phi_bb69_23;
  TNode<IntPtrT> phi_bb69_24;
  TNode<BoolT> phi_bb69_25;
  TNode<BoolT> phi_bb69_26;
  TNode<IntPtrT> phi_bb69_27;
  if (block69.is_used()) {
    ca_.Bind(&block69, &phi_bb69_19, &phi_bb69_23, &phi_bb69_24, &phi_bb69_25, &phi_bb69_26, &phi_bb69_27);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block71, phi_bb69_19, phi_bb69_23, phi_bb69_24, phi_bb69_25, phi_bb69_26, phi_bb69_27);
    } else {
      ca_.Goto(&block72, phi_bb69_19, phi_bb69_23, phi_bb69_24, phi_bb69_25, phi_bb69_26, phi_bb69_27);
    }
  }

  TNode<BoolT> phi_bb71_19;
  TNode<IntPtrT> phi_bb71_23;
  TNode<IntPtrT> phi_bb71_24;
  TNode<BoolT> phi_bb71_25;
  TNode<BoolT> phi_bb71_26;
  TNode<IntPtrT> phi_bb71_27;
  TNode<IntPtrT> tmp115;
  TNode<IntPtrT> tmp116;
  if (block71.is_used()) {
    ca_.Bind(&block71, &phi_bb71_19, &phi_bb71_23, &phi_bb71_24, &phi_bb71_25, &phi_bb71_26, &phi_bb71_27);
    tmp115 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp116 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb71_27}, TNode<IntPtrT>{tmp115});
    ca_.Goto(&block73, phi_bb71_19, phi_bb71_23, phi_bb71_24, phi_bb71_25, phi_bb71_26, tmp116);
  }

  TNode<BoolT> phi_bb72_19;
  TNode<IntPtrT> phi_bb72_23;
  TNode<IntPtrT> phi_bb72_24;
  TNode<BoolT> phi_bb72_25;
  TNode<BoolT> phi_bb72_26;
  TNode<IntPtrT> phi_bb72_27;
  if (block72.is_used()) {
    ca_.Bind(&block72, &phi_bb72_19, &phi_bb72_23, &phi_bb72_24, &phi_bb72_25, &phi_bb72_26, &phi_bb72_27);
    ca_.Branch(phi_bb72_25, &block74, std::vector<compiler::Node*>{phi_bb72_19, phi_bb72_23, phi_bb72_24, phi_bb72_25, phi_bb72_26, phi_bb72_27}, &block75, std::vector<compiler::Node*>{phi_bb72_19, phi_bb72_23, phi_bb72_24, phi_bb72_25, phi_bb72_26, phi_bb72_27});
  }

  TNode<BoolT> phi_bb74_19;
  TNode<IntPtrT> phi_bb74_23;
  TNode<IntPtrT> phi_bb74_24;
  TNode<BoolT> phi_bb74_25;
  TNode<BoolT> phi_bb74_26;
  TNode<IntPtrT> phi_bb74_27;
  TNode<BoolT> tmp117;
  TNode<BoolT> tmp118;
  if (block74.is_used()) {
    ca_.Bind(&block74, &phi_bb74_19, &phi_bb74_23, &phi_bb74_24, &phi_bb74_25, &phi_bb74_26, &phi_bb74_27);
    tmp117 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp118 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block76, phi_bb74_19, phi_bb74_23, phi_bb74_24, tmp117, tmp118, phi_bb74_27);
  }

  TNode<BoolT> phi_bb75_19;
  TNode<IntPtrT> phi_bb75_23;
  TNode<IntPtrT> phi_bb75_24;
  TNode<BoolT> phi_bb75_25;
  TNode<BoolT> phi_bb75_26;
  TNode<IntPtrT> phi_bb75_27;
  TNode<IntPtrT> tmp119;
  TNode<IntPtrT> tmp120;
  TNode<BoolT> tmp121;
  TNode<BoolT> tmp122;
  if (block75.is_used()) {
    ca_.Bind(&block75, &phi_bb75_19, &phi_bb75_23, &phi_bb75_24, &phi_bb75_25, &phi_bb75_26, &phi_bb75_27);
    tmp119 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp120 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb75_27}, TNode<IntPtrT>{tmp119});
    tmp121 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp122 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block76, phi_bb75_19, phi_bb75_23, phi_bb75_24, tmp121, tmp122, tmp120);
  }

  TNode<BoolT> phi_bb76_19;
  TNode<IntPtrT> phi_bb76_23;
  TNode<IntPtrT> phi_bb76_24;
  TNode<BoolT> phi_bb76_25;
  TNode<BoolT> phi_bb76_26;
  TNode<IntPtrT> phi_bb76_27;
  if (block76.is_used()) {
    ca_.Bind(&block76, &phi_bb76_19, &phi_bb76_23, &phi_bb76_24, &phi_bb76_25, &phi_bb76_26, &phi_bb76_27);
    ca_.Goto(&block73, phi_bb76_19, phi_bb76_23, phi_bb76_24, phi_bb76_25, phi_bb76_26, phi_bb76_27);
  }

  TNode<BoolT> phi_bb73_19;
  TNode<IntPtrT> phi_bb73_23;
  TNode<IntPtrT> phi_bb73_24;
  TNode<BoolT> phi_bb73_25;
  TNode<BoolT> phi_bb73_26;
  TNode<IntPtrT> phi_bb73_27;
  if (block73.is_used()) {
    ca_.Bind(&block73, &phi_bb73_19, &phi_bb73_23, &phi_bb73_24, &phi_bb73_25, &phi_bb73_26, &phi_bb73_27);
    ca_.Goto(&block67, phi_bb73_19, phi_bb73_23, phi_bb73_24, phi_bb73_25, phi_bb73_26, phi_bb73_27);
  }

  TNode<BoolT> phi_bb67_19;
  TNode<IntPtrT> phi_bb67_23;
  TNode<IntPtrT> phi_bb67_24;
  TNode<BoolT> phi_bb67_25;
  TNode<BoolT> phi_bb67_26;
  TNode<IntPtrT> phi_bb67_27;
  if (block67.is_used()) {
    ca_.Bind(&block67, &phi_bb67_19, &phi_bb67_23, &phi_bb67_24, &phi_bb67_25, &phi_bb67_26, &phi_bb67_27);
    ca_.Goto(&block66, phi_bb67_19, phi_bb67_23, phi_bb67_24, phi_bb67_25, phi_bb67_26, phi_bb67_27);
  }

  TNode<BoolT> phi_bb65_19;
  TNode<IntPtrT> phi_bb65_23;
  TNode<IntPtrT> phi_bb65_24;
  TNode<BoolT> phi_bb65_25;
  TNode<BoolT> phi_bb65_26;
  TNode<IntPtrT> phi_bb65_27;
  TNode<Int32T> tmp123;
  TNode<BoolT> tmp124;
  if (block65.is_used()) {
    ca_.Bind(&block65, &phi_bb65_19, &phi_bb65_23, &phi_bb65_24, &phi_bb65_25, &phi_bb65_26, &phi_bb65_27);
    tmp123 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF64.raw_bit_field());
    tmp124 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp68}, TNode<Int32T>{tmp123});
    ca_.Branch(tmp124, &block77, std::vector<compiler::Node*>{phi_bb65_19, phi_bb65_23, phi_bb65_24, phi_bb65_25, phi_bb65_26, phi_bb65_27}, &block78, std::vector<compiler::Node*>{phi_bb65_19, phi_bb65_23, phi_bb65_24, phi_bb65_25, phi_bb65_26, phi_bb65_27});
  }

  TNode<BoolT> phi_bb77_19;
  TNode<IntPtrT> phi_bb77_23;
  TNode<IntPtrT> phi_bb77_24;
  TNode<BoolT> phi_bb77_25;
  TNode<BoolT> phi_bb77_26;
  TNode<IntPtrT> phi_bb77_27;
  TNode<IntPtrT> tmp125;
  TNode<BoolT> tmp126;
  if (block77.is_used()) {
    ca_.Bind(&block77, &phi_bb77_19, &phi_bb77_23, &phi_bb77_24, &phi_bb77_25, &phi_bb77_26, &phi_bb77_27);
    tmp125 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp126 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb77_24}, TNode<IntPtrT>{tmp125});
    ca_.Branch(tmp126, &block81, std::vector<compiler::Node*>{phi_bb77_19, phi_bb77_23, phi_bb77_24, phi_bb77_25, phi_bb77_26, phi_bb77_27}, &block82, std::vector<compiler::Node*>{phi_bb77_19, phi_bb77_23, phi_bb77_24, phi_bb77_25, phi_bb77_26, phi_bb77_27});
  }

  TNode<BoolT> phi_bb81_19;
  TNode<IntPtrT> phi_bb81_23;
  TNode<IntPtrT> phi_bb81_24;
  TNode<BoolT> phi_bb81_25;
  TNode<BoolT> phi_bb81_26;
  TNode<IntPtrT> phi_bb81_27;
  TNode<IntPtrT> tmp127;
  TNode<IntPtrT> tmp128;
  if (block81.is_used()) {
    ca_.Bind(&block81, &phi_bb81_19, &phi_bb81_23, &phi_bb81_24, &phi_bb81_25, &phi_bb81_26, &phi_bb81_27);
    tmp127 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp128 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb81_24}, TNode<IntPtrT>{tmp127});
    ca_.Goto(&block80, phi_bb81_19, phi_bb81_23, tmp128, phi_bb81_25, phi_bb81_26, phi_bb81_27);
  }

  TNode<BoolT> phi_bb82_19;
  TNode<IntPtrT> phi_bb82_23;
  TNode<IntPtrT> phi_bb82_24;
  TNode<BoolT> phi_bb82_25;
  TNode<BoolT> phi_bb82_26;
  TNode<IntPtrT> phi_bb82_27;
  if (block82.is_used()) {
    ca_.Bind(&block82, &phi_bb82_19, &phi_bb82_23, &phi_bb82_24, &phi_bb82_25, &phi_bb82_26, &phi_bb82_27);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block83, phi_bb82_19, phi_bb82_23, phi_bb82_24, phi_bb82_25, phi_bb82_26, phi_bb82_27);
    } else {
      ca_.Goto(&block84, phi_bb82_19, phi_bb82_23, phi_bb82_24, phi_bb82_25, phi_bb82_26, phi_bb82_27);
    }
  }

  TNode<BoolT> phi_bb83_19;
  TNode<IntPtrT> phi_bb83_23;
  TNode<IntPtrT> phi_bb83_24;
  TNode<BoolT> phi_bb83_25;
  TNode<BoolT> phi_bb83_26;
  TNode<IntPtrT> phi_bb83_27;
  TNode<IntPtrT> tmp129;
  TNode<IntPtrT> tmp130;
  if (block83.is_used()) {
    ca_.Bind(&block83, &phi_bb83_19, &phi_bb83_23, &phi_bb83_24, &phi_bb83_25, &phi_bb83_26, &phi_bb83_27);
    tmp129 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp130 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb83_27}, TNode<IntPtrT>{tmp129});
    ca_.Goto(&block85, phi_bb83_19, phi_bb83_23, phi_bb83_24, phi_bb83_25, phi_bb83_26, tmp130);
  }

  TNode<BoolT> phi_bb84_19;
  TNode<IntPtrT> phi_bb84_23;
  TNode<IntPtrT> phi_bb84_24;
  TNode<BoolT> phi_bb84_25;
  TNode<BoolT> phi_bb84_26;
  TNode<IntPtrT> phi_bb84_27;
  TNode<IntPtrT> tmp131;
  TNode<IntPtrT> tmp132;
  TNode<BoolT> tmp133;
  if (block84.is_used()) {
    ca_.Bind(&block84, &phi_bb84_19, &phi_bb84_23, &phi_bb84_24, &phi_bb84_25, &phi_bb84_26, &phi_bb84_27);
    tmp131 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp132 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb84_27}, TNode<IntPtrT>{tmp131});
    tmp133 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block85, phi_bb84_19, phi_bb84_23, phi_bb84_24, phi_bb84_25, tmp133, tmp132);
  }

  TNode<BoolT> phi_bb85_19;
  TNode<IntPtrT> phi_bb85_23;
  TNode<IntPtrT> phi_bb85_24;
  TNode<BoolT> phi_bb85_25;
  TNode<BoolT> phi_bb85_26;
  TNode<IntPtrT> phi_bb85_27;
  if (block85.is_used()) {
    ca_.Bind(&block85, &phi_bb85_19, &phi_bb85_23, &phi_bb85_24, &phi_bb85_25, &phi_bb85_26, &phi_bb85_27);
    ca_.Goto(&block80, phi_bb85_19, phi_bb85_23, phi_bb85_24, phi_bb85_25, phi_bb85_26, phi_bb85_27);
  }

  TNode<BoolT> phi_bb80_19;
  TNode<IntPtrT> phi_bb80_23;
  TNode<IntPtrT> phi_bb80_24;
  TNode<BoolT> phi_bb80_25;
  TNode<BoolT> phi_bb80_26;
  TNode<IntPtrT> phi_bb80_27;
  if (block80.is_used()) {
    ca_.Bind(&block80, &phi_bb80_19, &phi_bb80_23, &phi_bb80_24, &phi_bb80_25, &phi_bb80_26, &phi_bb80_27);
    ca_.Goto(&block79, phi_bb80_19, phi_bb80_23, phi_bb80_24, phi_bb80_25, phi_bb80_26, phi_bb80_27);
  }

  TNode<BoolT> phi_bb78_19;
  TNode<IntPtrT> phi_bb78_23;
  TNode<IntPtrT> phi_bb78_24;
  TNode<BoolT> phi_bb78_25;
  TNode<BoolT> phi_bb78_26;
  TNode<IntPtrT> phi_bb78_27;
  TNode<Int32T> tmp134;
  TNode<Int32T> tmp135;
  TNode<BoolT> tmp136;
  if (block78.is_used()) {
    ca_.Bind(&block78, &phi_bb78_19, &phi_bb78_23, &phi_bb78_24, &phi_bb78_25, &phi_bb78_26, &phi_bb78_27);
    tmp134 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    tmp135 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp68}, TNode<Int32T>{tmp134});
    tmp136 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block79, tmp136, phi_bb78_23, phi_bb78_24, phi_bb78_25, phi_bb78_26, phi_bb78_27);
  }

  TNode<BoolT> phi_bb79_19;
  TNode<IntPtrT> phi_bb79_23;
  TNode<IntPtrT> phi_bb79_24;
  TNode<BoolT> phi_bb79_25;
  TNode<BoolT> phi_bb79_26;
  TNode<IntPtrT> phi_bb79_27;
  if (block79.is_used()) {
    ca_.Bind(&block79, &phi_bb79_19, &phi_bb79_23, &phi_bb79_24, &phi_bb79_25, &phi_bb79_26, &phi_bb79_27);
    ca_.Goto(&block66, phi_bb79_19, phi_bb79_23, phi_bb79_24, phi_bb79_25, phi_bb79_26, phi_bb79_27);
  }

  TNode<BoolT> phi_bb66_19;
  TNode<IntPtrT> phi_bb66_23;
  TNode<IntPtrT> phi_bb66_24;
  TNode<BoolT> phi_bb66_25;
  TNode<BoolT> phi_bb66_26;
  TNode<IntPtrT> phi_bb66_27;
  if (block66.is_used()) {
    ca_.Bind(&block66, &phi_bb66_19, &phi_bb66_23, &phi_bb66_24, &phi_bb66_25, &phi_bb66_26, &phi_bb66_27);
    ca_.Goto(&block40, phi_bb66_19, phi_bb66_23, phi_bb66_24, phi_bb66_25, phi_bb66_26, phi_bb66_27);
  }

  TNode<BoolT> phi_bb40_19;
  TNode<IntPtrT> phi_bb40_23;
  TNode<IntPtrT> phi_bb40_24;
  TNode<BoolT> phi_bb40_25;
  TNode<BoolT> phi_bb40_26;
  TNode<IntPtrT> phi_bb40_27;
  if (block40.is_used()) {
    ca_.Bind(&block40, &phi_bb40_19, &phi_bb40_23, &phi_bb40_24, &phi_bb40_25, &phi_bb40_26, &phi_bb40_27);
    ca_.Goto(&block27, phi_bb40_19, phi_bb40_23, phi_bb40_24, phi_bb40_25, phi_bb40_26, phi_bb40_27);
  }

  TNode<BoolT> phi_bb27_19;
  TNode<IntPtrT> phi_bb27_23;
  TNode<IntPtrT> phi_bb27_24;
  TNode<BoolT> phi_bb27_25;
  TNode<BoolT> phi_bb27_26;
  TNode<IntPtrT> phi_bb27_27;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_19, &phi_bb27_23, &phi_bb27_24, &phi_bb27_25, &phi_bb27_26, &phi_bb27_27);
    ca_.Goto(&block16, phi_bb27_19, phi_bb27_23, phi_bb27_24, phi_bb27_25, phi_bb27_26, phi_bb27_27, tmp67);
  }

  TNode<BoolT> phi_bb15_19;
  TNode<IntPtrT> phi_bb15_23;
  TNode<IntPtrT> phi_bb15_24;
  TNode<BoolT> phi_bb15_25;
  TNode<BoolT> phi_bb15_26;
  TNode<IntPtrT> phi_bb15_27;
  TNode<IntPtrT> phi_bb15_29;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_19, &phi_bb15_23, &phi_bb15_24, &phi_bb15_25, &phi_bb15_26, &phi_bb15_27, &phi_bb15_29);
    ca_.Branch(phi_bb15_19, &block93, std::vector<compiler::Node*>{phi_bb15_19, phi_bb15_23, phi_bb15_24, phi_bb15_25, phi_bb15_26, phi_bb15_27, phi_bb15_29}, &block94, std::vector<compiler::Node*>{phi_bb15_19, phi_bb15_23, phi_bb15_24, phi_bb15_25, phi_bb15_26, phi_bb15_27, phi_bb15_29, tmp61});
  }

  TNode<BoolT> phi_bb93_19;
  TNode<IntPtrT> phi_bb93_23;
  TNode<IntPtrT> phi_bb93_24;
  TNode<BoolT> phi_bb93_25;
  TNode<BoolT> phi_bb93_26;
  TNode<IntPtrT> phi_bb93_27;
  TNode<IntPtrT> phi_bb93_29;
  TNode<BoolT> tmp137;
  if (block93.is_used()) {
    ca_.Bind(&block93, &phi_bb93_19, &phi_bb93_23, &phi_bb93_24, &phi_bb93_25, &phi_bb93_26, &phi_bb93_27, &phi_bb93_29);
    tmp137 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{phi_bb93_26});
    ca_.Branch(tmp137, &block96, std::vector<compiler::Node*>{phi_bb93_19, phi_bb93_23, phi_bb93_24, phi_bb93_25, phi_bb93_26, phi_bb93_27, phi_bb93_29}, &block97, std::vector<compiler::Node*>{phi_bb93_19, phi_bb93_23, phi_bb93_24, phi_bb93_25, phi_bb93_26, phi_bb93_27, phi_bb93_29});
  }

  TNode<BoolT> phi_bb96_19;
  TNode<IntPtrT> phi_bb96_23;
  TNode<IntPtrT> phi_bb96_24;
  TNode<BoolT> phi_bb96_25;
  TNode<BoolT> phi_bb96_26;
  TNode<IntPtrT> phi_bb96_27;
  TNode<IntPtrT> phi_bb96_29;
  TNode<BoolT> tmp138;
  if (block96.is_used()) {
    ca_.Bind(&block96, &phi_bb96_19, &phi_bb96_23, &phi_bb96_24, &phi_bb96_25, &phi_bb96_26, &phi_bb96_27, &phi_bb96_29);
    tmp138 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block97, phi_bb96_19, phi_bb96_23, phi_bb96_24, tmp138, phi_bb96_26, phi_bb96_27, phi_bb96_29);
  }

  TNode<BoolT> phi_bb97_19;
  TNode<IntPtrT> phi_bb97_23;
  TNode<IntPtrT> phi_bb97_24;
  TNode<BoolT> phi_bb97_25;
  TNode<BoolT> phi_bb97_26;
  TNode<IntPtrT> phi_bb97_27;
  TNode<IntPtrT> phi_bb97_29;
  TNode<IntPtrT> tmp139;
  TNode<IntPtrT> tmp140;
  if (block97.is_used()) {
    ca_.Bind(&block97, &phi_bb97_19, &phi_bb97_23, &phi_bb97_24, &phi_bb97_25, &phi_bb97_26, &phi_bb97_27, &phi_bb97_29);
    tmp139 = TimesSizeOf_int32_0(state_, TNode<IntPtrT>{tmp53});
    tmp140 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp52}, TNode<IntPtrT>{tmp139});
    ca_.Goto(&block101, phi_bb97_19, phi_bb97_23, phi_bb97_24, phi_bb97_25, phi_bb97_26, phi_bb97_27, tmp52);
  }

  TNode<BoolT> phi_bb101_19;
  TNode<IntPtrT> phi_bb101_23;
  TNode<IntPtrT> phi_bb101_24;
  TNode<BoolT> phi_bb101_25;
  TNode<BoolT> phi_bb101_26;
  TNode<IntPtrT> phi_bb101_27;
  TNode<IntPtrT> phi_bb101_29;
  TNode<BoolT> tmp141;
  TNode<BoolT> tmp142;
  if (block101.is_used()) {
    ca_.Bind(&block101, &phi_bb101_19, &phi_bb101_23, &phi_bb101_24, &phi_bb101_25, &phi_bb101_26, &phi_bb101_27, &phi_bb101_29);
    tmp141 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb101_29}, TNode<IntPtrT>{tmp140});
    tmp142 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp141});
    ca_.Branch(tmp142, &block99, std::vector<compiler::Node*>{phi_bb101_19, phi_bb101_23, phi_bb101_24, phi_bb101_25, phi_bb101_26, phi_bb101_27, phi_bb101_29}, &block100, std::vector<compiler::Node*>{phi_bb101_19, phi_bb101_23, phi_bb101_24, phi_bb101_25, phi_bb101_26, phi_bb101_27, phi_bb101_29});
  }

  TNode<BoolT> phi_bb99_19;
  TNode<IntPtrT> phi_bb99_23;
  TNode<IntPtrT> phi_bb99_24;
  TNode<BoolT> phi_bb99_25;
  TNode<BoolT> phi_bb99_26;
  TNode<IntPtrT> phi_bb99_27;
  TNode<IntPtrT> phi_bb99_29;
  TNode<Object> tmp143;
  TNode<IntPtrT> tmp144;
  TNode<IntPtrT> tmp145;
  TNode<IntPtrT> tmp146;
  TNode<Int32T> tmp147;
  TNode<Int32T> tmp148;
  TNode<Int32T> tmp149;
  TNode<Int32T> tmp150;
  TNode<BoolT> tmp151;
  if (block99.is_used()) {
    ca_.Bind(&block99, &phi_bb99_19, &phi_bb99_23, &phi_bb99_24, &phi_bb99_25, &phi_bb99_26, &phi_bb99_27, &phi_bb99_29);
    std::tie(tmp143, tmp144) = NewReference_int32_0(state_, TNode<Object>{tmp51}, TNode<IntPtrT>{phi_bb99_29}).Flatten();
    tmp145 = FromConstexpr_intptr_constexpr_int31_0(state_, kInt32Size);
    tmp146 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb99_29}, TNode<IntPtrT>{tmp145});
    tmp147 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp143, tmp144});
    tmp148 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    tmp149 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp147}, TNode<Int32T>{tmp148});
    tmp150 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    tmp151 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp149}, TNode<Int32T>{tmp150});
    ca_.Branch(tmp151, &block112, std::vector<compiler::Node*>{phi_bb99_19, phi_bb99_23, phi_bb99_24, phi_bb99_25, phi_bb99_26, phi_bb99_27}, &block113, std::vector<compiler::Node*>{phi_bb99_19, phi_bb99_23, phi_bb99_24, phi_bb99_25, phi_bb99_26, phi_bb99_27});
  }

  TNode<BoolT> phi_bb112_19;
  TNode<IntPtrT> phi_bb112_23;
  TNode<IntPtrT> phi_bb112_24;
  TNode<BoolT> phi_bb112_25;
  TNode<BoolT> phi_bb112_26;
  TNode<IntPtrT> phi_bb112_27;
  TNode<BoolT> tmp152;
  if (block112.is_used()) {
    ca_.Bind(&block112, &phi_bb112_19, &phi_bb112_23, &phi_bb112_24, &phi_bb112_25, &phi_bb112_26, &phi_bb112_27);
    tmp152 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block114, phi_bb112_19, phi_bb112_23, phi_bb112_24, phi_bb112_25, phi_bb112_26, phi_bb112_27, tmp152);
  }

  TNode<BoolT> phi_bb113_19;
  TNode<IntPtrT> phi_bb113_23;
  TNode<IntPtrT> phi_bb113_24;
  TNode<BoolT> phi_bb113_25;
  TNode<BoolT> phi_bb113_26;
  TNode<IntPtrT> phi_bb113_27;
  TNode<Int32T> tmp153;
  TNode<BoolT> tmp154;
  if (block113.is_used()) {
    ca_.Bind(&block113, &phi_bb113_19, &phi_bb113_23, &phi_bb113_24, &phi_bb113_25, &phi_bb113_26, &phi_bb113_27);
    tmp153 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRefNull);
    tmp154 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp149}, TNode<Int32T>{tmp153});
    ca_.Goto(&block114, phi_bb113_19, phi_bb113_23, phi_bb113_24, phi_bb113_25, phi_bb113_26, phi_bb113_27, tmp154);
  }

  TNode<BoolT> phi_bb114_19;
  TNode<IntPtrT> phi_bb114_23;
  TNode<IntPtrT> phi_bb114_24;
  TNode<BoolT> phi_bb114_25;
  TNode<BoolT> phi_bb114_26;
  TNode<IntPtrT> phi_bb114_27;
  TNode<BoolT> phi_bb114_34;
  if (block114.is_used()) {
    ca_.Bind(&block114, &phi_bb114_19, &phi_bb114_23, &phi_bb114_24, &phi_bb114_25, &phi_bb114_26, &phi_bb114_27, &phi_bb114_34);
    ca_.Branch(phi_bb114_34, &block110, std::vector<compiler::Node*>{phi_bb114_19, phi_bb114_23, phi_bb114_24, phi_bb114_25, phi_bb114_26, phi_bb114_27}, &block111, std::vector<compiler::Node*>{phi_bb114_19, phi_bb114_23, phi_bb114_24, phi_bb114_25, phi_bb114_26, phi_bb114_27});
  }

  TNode<BoolT> phi_bb110_19;
  TNode<IntPtrT> phi_bb110_23;
  TNode<IntPtrT> phi_bb110_24;
  TNode<BoolT> phi_bb110_25;
  TNode<BoolT> phi_bb110_26;
  TNode<IntPtrT> phi_bb110_27;
  TNode<IntPtrT> tmp155;
  TNode<BoolT> tmp156;
  if (block110.is_used()) {
    ca_.Bind(&block110, &phi_bb110_19, &phi_bb110_23, &phi_bb110_24, &phi_bb110_25, &phi_bb110_26, &phi_bb110_27);
    tmp155 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp156 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb110_23}, TNode<IntPtrT>{tmp155});
    ca_.Branch(tmp156, &block116, std::vector<compiler::Node*>{phi_bb110_19, phi_bb110_23, phi_bb110_24, phi_bb110_25, phi_bb110_26, phi_bb110_27}, &block117, std::vector<compiler::Node*>{phi_bb110_19, phi_bb110_23, phi_bb110_24, phi_bb110_25, phi_bb110_26, phi_bb110_27});
  }

  TNode<BoolT> phi_bb116_19;
  TNode<IntPtrT> phi_bb116_23;
  TNode<IntPtrT> phi_bb116_24;
  TNode<BoolT> phi_bb116_25;
  TNode<BoolT> phi_bb116_26;
  TNode<IntPtrT> phi_bb116_27;
  TNode<IntPtrT> tmp157;
  TNode<IntPtrT> tmp158;
  if (block116.is_used()) {
    ca_.Bind(&block116, &phi_bb116_19, &phi_bb116_23, &phi_bb116_24, &phi_bb116_25, &phi_bb116_26, &phi_bb116_27);
    tmp157 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp158 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb116_23}, TNode<IntPtrT>{tmp157});
    ca_.Goto(&block115, phi_bb116_19, tmp158, phi_bb116_24, phi_bb116_25, phi_bb116_26, phi_bb116_27);
  }

  TNode<BoolT> phi_bb117_19;
  TNode<IntPtrT> phi_bb117_23;
  TNode<IntPtrT> phi_bb117_24;
  TNode<BoolT> phi_bb117_25;
  TNode<BoolT> phi_bb117_26;
  TNode<IntPtrT> phi_bb117_27;
  if (block117.is_used()) {
    ca_.Bind(&block117, &phi_bb117_19, &phi_bb117_23, &phi_bb117_24, &phi_bb117_25, &phi_bb117_26, &phi_bb117_27);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block119, phi_bb117_19, phi_bb117_23, phi_bb117_24, phi_bb117_25, phi_bb117_26, phi_bb117_27);
    } else {
      ca_.Goto(&block120, phi_bb117_19, phi_bb117_23, phi_bb117_24, phi_bb117_25, phi_bb117_26, phi_bb117_27);
    }
  }

  TNode<BoolT> phi_bb119_19;
  TNode<IntPtrT> phi_bb119_23;
  TNode<IntPtrT> phi_bb119_24;
  TNode<BoolT> phi_bb119_25;
  TNode<BoolT> phi_bb119_26;
  TNode<IntPtrT> phi_bb119_27;
  TNode<IntPtrT> tmp159;
  TNode<IntPtrT> tmp160;
  if (block119.is_used()) {
    ca_.Bind(&block119, &phi_bb119_19, &phi_bb119_23, &phi_bb119_24, &phi_bb119_25, &phi_bb119_26, &phi_bb119_27);
    tmp159 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp160 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb119_27}, TNode<IntPtrT>{tmp159});
    ca_.Goto(&block121, phi_bb119_19, phi_bb119_23, phi_bb119_24, phi_bb119_25, phi_bb119_26, tmp160);
  }

  TNode<BoolT> phi_bb120_19;
  TNode<IntPtrT> phi_bb120_23;
  TNode<IntPtrT> phi_bb120_24;
  TNode<BoolT> phi_bb120_25;
  TNode<BoolT> phi_bb120_26;
  TNode<IntPtrT> phi_bb120_27;
  if (block120.is_used()) {
    ca_.Bind(&block120, &phi_bb120_19, &phi_bb120_23, &phi_bb120_24, &phi_bb120_25, &phi_bb120_26, &phi_bb120_27);
    ca_.Branch(phi_bb120_25, &block122, std::vector<compiler::Node*>{phi_bb120_19, phi_bb120_23, phi_bb120_24, phi_bb120_25, phi_bb120_26, phi_bb120_27}, &block123, std::vector<compiler::Node*>{phi_bb120_19, phi_bb120_23, phi_bb120_24, phi_bb120_25, phi_bb120_26, phi_bb120_27});
  }

  TNode<BoolT> phi_bb122_19;
  TNode<IntPtrT> phi_bb122_23;
  TNode<IntPtrT> phi_bb122_24;
  TNode<BoolT> phi_bb122_25;
  TNode<BoolT> phi_bb122_26;
  TNode<IntPtrT> phi_bb122_27;
  TNode<BoolT> tmp161;
  TNode<BoolT> tmp162;
  if (block122.is_used()) {
    ca_.Bind(&block122, &phi_bb122_19, &phi_bb122_23, &phi_bb122_24, &phi_bb122_25, &phi_bb122_26, &phi_bb122_27);
    tmp161 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp162 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block124, phi_bb122_19, phi_bb122_23, phi_bb122_24, tmp161, tmp162, phi_bb122_27);
  }

  TNode<BoolT> phi_bb123_19;
  TNode<IntPtrT> phi_bb123_23;
  TNode<IntPtrT> phi_bb123_24;
  TNode<BoolT> phi_bb123_25;
  TNode<BoolT> phi_bb123_26;
  TNode<IntPtrT> phi_bb123_27;
  TNode<IntPtrT> tmp163;
  TNode<IntPtrT> tmp164;
  TNode<BoolT> tmp165;
  TNode<BoolT> tmp166;
  if (block123.is_used()) {
    ca_.Bind(&block123, &phi_bb123_19, &phi_bb123_23, &phi_bb123_24, &phi_bb123_25, &phi_bb123_26, &phi_bb123_27);
    tmp163 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp164 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb123_27}, TNode<IntPtrT>{tmp163});
    tmp165 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp166 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block124, phi_bb123_19, phi_bb123_23, phi_bb123_24, tmp165, tmp166, tmp164);
  }

  TNode<BoolT> phi_bb124_19;
  TNode<IntPtrT> phi_bb124_23;
  TNode<IntPtrT> phi_bb124_24;
  TNode<BoolT> phi_bb124_25;
  TNode<BoolT> phi_bb124_26;
  TNode<IntPtrT> phi_bb124_27;
  if (block124.is_used()) {
    ca_.Bind(&block124, &phi_bb124_19, &phi_bb124_23, &phi_bb124_24, &phi_bb124_25, &phi_bb124_26, &phi_bb124_27);
    ca_.Goto(&block121, phi_bb124_19, phi_bb124_23, phi_bb124_24, phi_bb124_25, phi_bb124_26, phi_bb124_27);
  }

  TNode<BoolT> phi_bb121_19;
  TNode<IntPtrT> phi_bb121_23;
  TNode<IntPtrT> phi_bb121_24;
  TNode<BoolT> phi_bb121_25;
  TNode<BoolT> phi_bb121_26;
  TNode<IntPtrT> phi_bb121_27;
  if (block121.is_used()) {
    ca_.Bind(&block121, &phi_bb121_19, &phi_bb121_23, &phi_bb121_24, &phi_bb121_25, &phi_bb121_26, &phi_bb121_27);
    ca_.Goto(&block115, phi_bb121_19, phi_bb121_23, phi_bb121_24, phi_bb121_25, phi_bb121_26, phi_bb121_27);
  }

  TNode<BoolT> phi_bb115_19;
  TNode<IntPtrT> phi_bb115_23;
  TNode<IntPtrT> phi_bb115_24;
  TNode<BoolT> phi_bb115_25;
  TNode<BoolT> phi_bb115_26;
  TNode<IntPtrT> phi_bb115_27;
  if (block115.is_used()) {
    ca_.Bind(&block115, &phi_bb115_19, &phi_bb115_23, &phi_bb115_24, &phi_bb115_25, &phi_bb115_26, &phi_bb115_27);
    ca_.Goto(&block111, phi_bb115_19, phi_bb115_23, phi_bb115_24, phi_bb115_25, phi_bb115_26, phi_bb115_27);
  }

  TNode<BoolT> phi_bb111_19;
  TNode<IntPtrT> phi_bb111_23;
  TNode<IntPtrT> phi_bb111_24;
  TNode<BoolT> phi_bb111_25;
  TNode<BoolT> phi_bb111_26;
  TNode<IntPtrT> phi_bb111_27;
  if (block111.is_used()) {
    ca_.Bind(&block111, &phi_bb111_19, &phi_bb111_23, &phi_bb111_24, &phi_bb111_25, &phi_bb111_26, &phi_bb111_27);
    ca_.Goto(&block101, phi_bb111_19, phi_bb111_23, phi_bb111_24, phi_bb111_25, phi_bb111_26, phi_bb111_27, tmp146);
  }

  TNode<BoolT> phi_bb100_19;
  TNode<IntPtrT> phi_bb100_23;
  TNode<IntPtrT> phi_bb100_24;
  TNode<BoolT> phi_bb100_25;
  TNode<BoolT> phi_bb100_26;
  TNode<IntPtrT> phi_bb100_27;
  TNode<IntPtrT> phi_bb100_29;
  if (block100.is_used()) {
    ca_.Bind(&block100, &phi_bb100_19, &phi_bb100_23, &phi_bb100_24, &phi_bb100_25, &phi_bb100_26, &phi_bb100_27, &phi_bb100_29);
    ca_.Goto(&block94, phi_bb100_19, phi_bb100_23, phi_bb100_24, phi_bb100_25, phi_bb100_26, phi_bb100_27, phi_bb100_29, tmp140);
  }

  TNode<BoolT> phi_bb94_19;
  TNode<IntPtrT> phi_bb94_23;
  TNode<IntPtrT> phi_bb94_24;
  TNode<BoolT> phi_bb94_25;
  TNode<BoolT> phi_bb94_26;
  TNode<IntPtrT> phi_bb94_27;
  TNode<IntPtrT> phi_bb94_29;
  TNode<IntPtrT> phi_bb94_30;
  if (block94.is_used()) {
    ca_.Bind(&block94, &phi_bb94_19, &phi_bb94_23, &phi_bb94_24, &phi_bb94_25, &phi_bb94_26, &phi_bb94_27, &phi_bb94_29, &phi_bb94_30);
    ca_.Branch(phi_bb94_26, &block126, std::vector<compiler::Node*>{phi_bb94_19, phi_bb94_23, phi_bb94_24, phi_bb94_25, phi_bb94_26, phi_bb94_27, phi_bb94_29, phi_bb94_30}, &block127, std::vector<compiler::Node*>{phi_bb94_19, phi_bb94_23, phi_bb94_24, phi_bb94_25, phi_bb94_26, phi_bb94_27, phi_bb94_29, phi_bb94_30});
  }

  TNode<BoolT> phi_bb126_19;
  TNode<IntPtrT> phi_bb126_23;
  TNode<IntPtrT> phi_bb126_24;
  TNode<BoolT> phi_bb126_25;
  TNode<BoolT> phi_bb126_26;
  TNode<IntPtrT> phi_bb126_27;
  TNode<IntPtrT> phi_bb126_29;
  TNode<IntPtrT> phi_bb126_30;
  TNode<IntPtrT> tmp167;
  TNode<IntPtrT> tmp168;
  if (block126.is_used()) {
    ca_.Bind(&block126, &phi_bb126_19, &phi_bb126_23, &phi_bb126_24, &phi_bb126_25, &phi_bb126_26, &phi_bb126_27, &phi_bb126_29, &phi_bb126_30);
    tmp167 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp168 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb126_27}, TNode<IntPtrT>{tmp167});
    ca_.Goto(&block125, phi_bb126_19, phi_bb126_23, phi_bb126_24, phi_bb126_25, phi_bb126_26, phi_bb126_27, phi_bb126_29, phi_bb126_30, tmp168);
  }

  TNode<BoolT> phi_bb127_19;
  TNode<IntPtrT> phi_bb127_23;
  TNode<IntPtrT> phi_bb127_24;
  TNode<BoolT> phi_bb127_25;
  TNode<BoolT> phi_bb127_26;
  TNode<IntPtrT> phi_bb127_27;
  TNode<IntPtrT> phi_bb127_29;
  TNode<IntPtrT> phi_bb127_30;
  if (block127.is_used()) {
    ca_.Bind(&block127, &phi_bb127_19, &phi_bb127_23, &phi_bb127_24, &phi_bb127_25, &phi_bb127_26, &phi_bb127_27, &phi_bb127_29, &phi_bb127_30);
    ca_.Goto(&block125, phi_bb127_19, phi_bb127_23, phi_bb127_24, phi_bb127_25, phi_bb127_26, phi_bb127_27, phi_bb127_29, phi_bb127_30, phi_bb127_27);
  }

  TNode<BoolT> phi_bb125_19;
  TNode<IntPtrT> phi_bb125_23;
  TNode<IntPtrT> phi_bb125_24;
  TNode<BoolT> phi_bb125_25;
  TNode<BoolT> phi_bb125_26;
  TNode<IntPtrT> phi_bb125_27;
  TNode<IntPtrT> phi_bb125_29;
  TNode<IntPtrT> phi_bb125_30;
  TNode<IntPtrT> phi_bb125_31;
  if (block125.is_used()) {
    ca_.Bind(&block125, &phi_bb125_19, &phi_bb125_23, &phi_bb125_24, &phi_bb125_25, &phi_bb125_26, &phi_bb125_27, &phi_bb125_29, &phi_bb125_30, &phi_bb125_31);
    ca_.Goto(&block8, tmp48, phi_bb125_31, phi_bb125_19);
  }

  TNode<Object> phi_bb8_17;
  TNode<IntPtrT> phi_bb8_18;
  TNode<BoolT> phi_bb8_19;
  TNode<IntPtrT> tmp169;
  TNode<IntPtrT> tmp170;
  TNode<Object> tmp171;
  TNode<IntPtrT> tmp172;
  TNode<IntPtrT> tmp173;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_17, &phi_bb8_18, &phi_bb8_19);
    tmp169 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp31});
    tmp170 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp26});
    compiler::CodeAssemblerLabel label174(&ca_);
    std::tie(tmp171, tmp172, tmp173) = Subslice_int32_0(state_, TorqueStructSlice_int32_ConstReference_int32_0{TNode<Object>{tmp39}, TNode<IntPtrT>{tmp40}, TNode<IntPtrT>{tmp41}, TorqueStructUnsafe_0{}}, TNode<IntPtrT>{tmp169}, TNode<IntPtrT>{tmp170}, &label174).Flatten();
    ca_.Goto(&block131, phi_bb8_17, phi_bb8_18, phi_bb8_19);
    if (label174.is_used()) {
      ca_.Bind(&label174);
      ca_.Goto(&block132, phi_bb8_17, phi_bb8_18, phi_bb8_19);
    }
  }

  TNode<Object> phi_bb132_17;
  TNode<IntPtrT> phi_bb132_18;
  TNode<BoolT> phi_bb132_19;
  if (block132.is_used()) {
    ca_.Bind(&block132, &phi_bb132_17, &phi_bb132_18, &phi_bb132_19);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> phi_bb131_17;
  TNode<IntPtrT> phi_bb131_18;
  TNode<BoolT> phi_bb131_19;
  TNode<Int32T> tmp175;
  TNode<BoolT> tmp176;
  if (block131.is_used()) {
    ca_.Bind(&block131, &phi_bb131_17, &phi_bb131_18, &phi_bb131_19);
    tmp175 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xaull));
    tmp176 = CodeStubAssembler(state_).Int32LessThanOrEqual(TNode<Int32T>{tmp26}, TNode<Int32T>{tmp175});
    ca_.Branch(tmp176, &block133, std::vector<compiler::Node*>{phi_bb131_17, phi_bb131_18, phi_bb131_19}, &block134, std::vector<compiler::Node*>{phi_bb131_17, phi_bb131_18, phi_bb131_19});
  }

  TNode<Object> phi_bb133_17;
  TNode<IntPtrT> phi_bb133_18;
  TNode<BoolT> phi_bb133_19;
  TNode<RawPtrT> tmp177;
  TNode<RawPtrT> tmp178;
  TNode<Object> tmp179;
  TNode<IntPtrT> tmp180;
  if (block133.is_used()) {
    ca_.Bind(&block133, &phi_bb133_17, &phi_bb133_18, &phi_bb133_19);
    tmp177 = CodeStubAssembler(state_).StackSlotPtr((FromConstexpr_constexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x90ull))), (SizeOf_float64_0(state_)));
    tmp178 = (TNode<RawPtrT>{tmp177});
    std::tie(tmp179, tmp180) = NewOffHeapReference_intptr_0(state_, TNode<RawPtrT>{tmp178}).Flatten();
    ca_.Goto(&block135, phi_bb133_17, phi_bb133_18, phi_bb133_19, tmp179, tmp180);
  }

  TNode<Object> phi_bb134_17;
  TNode<IntPtrT> phi_bb134_18;
  TNode<BoolT> phi_bb134_19;
  TNode<IntPtrT> tmp181;
  TNode<IntPtrT> tmp182;
  TNode<IntPtrT> tmp183;
  TNode<IntPtrT> tmp184;
  TNode<IntPtrT> tmp185;
  TNode<IntPtrT> tmp186;
  TNode<IntPtrT> tmp187;
  TNode<IntPtrT> tmp188;
  TNode<IntPtrT> tmp189;
  TNode<IntPtrT> tmp190;
  TNode<UintPtrT> tmp191;
  TNode<ByteArray> tmp192;
  TNode<Object> tmp193;
  TNode<IntPtrT> tmp194;
  TNode<IntPtrT> tmp195;
  TNode<Object> tmp196;
  TNode<IntPtrT> tmp197;
  if (block134.is_used()) {
    ca_.Bind(&block134, &phi_bb134_17, &phi_bb134_18, &phi_bb134_19);
    tmp181 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp182 = CodeStubAssembler(state_).UniqueIntPtrConstant(arraysize(wasm::kGpParamRegisters) - 1);
    tmp183 = Convert_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp184 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp182}, TNode<IntPtrT>{tmp183});
    tmp185 = CodeStubAssembler(state_).UniqueIntPtrConstant(arraysize(wasm::kFpParamRegisters));
    tmp186 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp185}, TNode<IntPtrT>{tmp181});
    tmp187 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp184}, TNode<IntPtrT>{tmp186});
    tmp188 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp26});
    tmp189 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp188}, TNode<IntPtrT>{tmp181});
    tmp190 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp187}, TNode<IntPtrT>{tmp189});
    tmp191 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp190});
    tmp192 = CodeStubAssembler(state_).AllocateByteArray(TNode<UintPtrT>{tmp191});
    std::tie(tmp193, tmp194, tmp195) = FieldSliceByteArrayValues_0(state_, TNode<ByteArray>{tmp192}).Flatten();
    std::tie(tmp196, tmp197) = NewReference_intptr_0(state_, TNode<Object>{tmp193}, TNode<IntPtrT>{tmp194}).Flatten();
    ca_.Goto(&block135, phi_bb134_17, phi_bb134_18, phi_bb134_19, tmp196, tmp197);
  }

  TNode<Object> phi_bb135_17;
  TNode<IntPtrT> phi_bb135_18;
  TNode<BoolT> phi_bb135_19;
  TNode<Object> phi_bb135_23;
  TNode<IntPtrT> phi_bb135_24;
  TNode<Object> tmp198;
  TNode<IntPtrT> tmp199;
  TNode<IntPtrT> tmp200;
  TNode<IntPtrT> tmp201;
  TNode<IntPtrT> tmp202;
  TNode<IntPtrT> tmp203;
  TNode<IntPtrT> tmp204;
  TNode<IntPtrT> tmp205;
  TNode<BoolT> tmp206;
  TNode<BoolT> tmp207;
  TNode<Smi> tmp208;
  TNode<Int32T> tmp209;
  TNode<Int32T> tmp210;
  if (block135.is_used()) {
    ca_.Bind(&block135, &phi_bb135_17, &phi_bb135_18, &phi_bb135_19, &phi_bb135_23, &phi_bb135_24);
    std::tie(tmp198, tmp199, tmp200, tmp201, tmp202, tmp203, tmp204, tmp205, tmp206) = LocationAllocatorForParams_0(state_, TorqueStructReference_intptr_0{TNode<Object>{phi_bb135_23}, TNode<IntPtrT>{phi_bb135_24}, TorqueStructUnsafe_0{}}).Flatten();
    tmp207 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp208 = Convert_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp209 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp210 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block138, phi_bb135_17, phi_bb135_18, phi_bb135_19, tmp199, tmp200, tmp201, tmp202, tmp203, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210);
  }

  TNode<Object> phi_bb138_17;
  TNode<IntPtrT> phi_bb138_18;
  TNode<BoolT> phi_bb138_19;
  TNode<IntPtrT> phi_bb138_26;
  TNode<IntPtrT> phi_bb138_27;
  TNode<IntPtrT> phi_bb138_28;
  TNode<IntPtrT> phi_bb138_29;
  TNode<IntPtrT> phi_bb138_30;
  TNode<IntPtrT> phi_bb138_32;
  TNode<BoolT> phi_bb138_33;
  TNode<BoolT> phi_bb138_34;
  TNode<Object> phi_bb138_35;
  TNode<Int32T> phi_bb138_36;
  TNode<Int32T> phi_bb138_37;
  TNode<BoolT> tmp211;
  if (block138.is_used()) {
    ca_.Bind(&block138, &phi_bb138_17, &phi_bb138_18, &phi_bb138_19, &phi_bb138_26, &phi_bb138_27, &phi_bb138_28, &phi_bb138_29, &phi_bb138_30, &phi_bb138_32, &phi_bb138_33, &phi_bb138_34, &phi_bb138_35, &phi_bb138_36, &phi_bb138_37);
    tmp211 = CodeStubAssembler(state_).Int32LessThan(TNode<Int32T>{phi_bb138_36}, TNode<Int32T>{tmp26});
    ca_.Branch(tmp211, &block136, std::vector<compiler::Node*>{phi_bb138_17, phi_bb138_18, phi_bb138_19, phi_bb138_26, phi_bb138_27, phi_bb138_28, phi_bb138_29, phi_bb138_30, phi_bb138_32, phi_bb138_33, phi_bb138_34, phi_bb138_35, phi_bb138_36, phi_bb138_37}, &block137, std::vector<compiler::Node*>{phi_bb138_17, phi_bb138_18, phi_bb138_19, phi_bb138_26, phi_bb138_27, phi_bb138_28, phi_bb138_29, phi_bb138_30, phi_bb138_32, phi_bb138_33, phi_bb138_34, phi_bb138_35, phi_bb138_36, phi_bb138_37});
  }

  TNode<Object> phi_bb136_17;
  TNode<IntPtrT> phi_bb136_18;
  TNode<BoolT> phi_bb136_19;
  TNode<IntPtrT> phi_bb136_26;
  TNode<IntPtrT> phi_bb136_27;
  TNode<IntPtrT> phi_bb136_28;
  TNode<IntPtrT> phi_bb136_29;
  TNode<IntPtrT> phi_bb136_30;
  TNode<IntPtrT> phi_bb136_32;
  TNode<BoolT> phi_bb136_33;
  TNode<BoolT> phi_bb136_34;
  TNode<Object> phi_bb136_35;
  TNode<Int32T> phi_bb136_36;
  TNode<Int32T> phi_bb136_37;
  TNode<IntPtrT> tmp212;
  TNode<Object> tmp213;
  TNode<Int32T> tmp214;
  TNode<Int32T> tmp215;
  TNode<IntPtrT> tmp216;
  TNode<IntPtrT> tmp217;
  TNode<IntPtrT> tmp218;
  TNode<Object> tmp219;
  TNode<IntPtrT> tmp220;
  TNode<Int32T> tmp221;
  TNode<Int32T> tmp222;
  TNode<BoolT> tmp223;
  if (block136.is_used()) {
    ca_.Bind(&block136, &phi_bb136_17, &phi_bb136_18, &phi_bb136_19, &phi_bb136_26, &phi_bb136_27, &phi_bb136_28, &phi_bb136_29, &phi_bb136_30, &phi_bb136_32, &phi_bb136_33, &phi_bb136_34, &phi_bb136_35, &phi_bb136_36, &phi_bb136_37);
    tmp212 = Convert_intptr_int32_0(state_, TNode<Int32T>{phi_bb136_37});
    tmp213 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{p_arguments.frame}, TNode<RawPtrT>{p_arguments.base}, TNode<IntPtrT>{p_arguments.length}, TNode<IntPtrT>{p_arguments.actual_count}}, TNode<IntPtrT>{tmp212});
    tmp214 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    tmp215 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{phi_bb136_36}, TNode<Int32T>{tmp214});
    tmp216 = Convert_intptr_int32_0(state_, TNode<Int32T>{phi_bb136_36});
    tmp217 = TimesSizeOf_int32_0(state_, TNode<IntPtrT>{tmp216});
    tmp218 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp172}, TNode<IntPtrT>{tmp217});
    std::tie(tmp219, tmp220) = NewReference_int32_0(state_, TNode<Object>{tmp171}, TNode<IntPtrT>{tmp218}).Flatten();
    tmp221 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp219, tmp220});
    tmp222 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI32.raw_bit_field());
    tmp223 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp221}, TNode<Int32T>{tmp222});
    ca_.Branch(tmp223, &block141, std::vector<compiler::Node*>{phi_bb136_17, phi_bb136_18, phi_bb136_19, phi_bb136_26, phi_bb136_27, phi_bb136_28, phi_bb136_29, phi_bb136_30, phi_bb136_32, phi_bb136_33, phi_bb136_34, phi_bb136_35, phi_bb136_37}, &block142, std::vector<compiler::Node*>{phi_bb136_17, phi_bb136_18, phi_bb136_19, phi_bb136_26, phi_bb136_27, phi_bb136_28, phi_bb136_29, phi_bb136_30, phi_bb136_32, phi_bb136_33, phi_bb136_34, phi_bb136_35, phi_bb136_37});
  }

  TNode<Object> phi_bb141_17;
  TNode<IntPtrT> phi_bb141_18;
  TNode<BoolT> phi_bb141_19;
  TNode<IntPtrT> phi_bb141_26;
  TNode<IntPtrT> phi_bb141_27;
  TNode<IntPtrT> phi_bb141_28;
  TNode<IntPtrT> phi_bb141_29;
  TNode<IntPtrT> phi_bb141_30;
  TNode<IntPtrT> phi_bb141_32;
  TNode<BoolT> phi_bb141_33;
  TNode<BoolT> phi_bb141_34;
  TNode<Object> phi_bb141_35;
  TNode<Int32T> phi_bb141_37;
  TNode<IntPtrT> tmp224;
  TNode<IntPtrT> tmp225;
  TNode<IntPtrT> tmp226;
  TNode<BoolT> tmp227;
  if (block141.is_used()) {
    ca_.Bind(&block141, &phi_bb141_17, &phi_bb141_18, &phi_bb141_19, &phi_bb141_26, &phi_bb141_27, &phi_bb141_28, &phi_bb141_29, &phi_bb141_30, &phi_bb141_32, &phi_bb141_33, &phi_bb141_34, &phi_bb141_35, &phi_bb141_37);
    tmp224 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp225 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb141_26}, TNode<IntPtrT>{tmp224});
    tmp226 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp227 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb141_26}, TNode<IntPtrT>{tmp226});
    ca_.Branch(tmp227, &block145, std::vector<compiler::Node*>{phi_bb141_17, phi_bb141_18, phi_bb141_19, phi_bb141_27, phi_bb141_28, phi_bb141_29, phi_bb141_30, phi_bb141_32, phi_bb141_33, phi_bb141_34, phi_bb141_35, phi_bb141_37}, &block146, std::vector<compiler::Node*>{phi_bb141_17, phi_bb141_18, phi_bb141_19, phi_bb141_27, phi_bb141_28, phi_bb141_29, phi_bb141_30, phi_bb141_32, phi_bb141_33, phi_bb141_34, phi_bb141_35, phi_bb141_37});
  }

  TNode<Object> phi_bb145_17;
  TNode<IntPtrT> phi_bb145_18;
  TNode<BoolT> phi_bb145_19;
  TNode<IntPtrT> phi_bb145_27;
  TNode<IntPtrT> phi_bb145_28;
  TNode<IntPtrT> phi_bb145_29;
  TNode<IntPtrT> phi_bb145_30;
  TNode<IntPtrT> phi_bb145_32;
  TNode<BoolT> phi_bb145_33;
  TNode<BoolT> phi_bb145_34;
  TNode<Object> phi_bb145_35;
  TNode<Int32T> phi_bb145_37;
  TNode<Object> tmp228;
  TNode<IntPtrT> tmp229;
  TNode<IntPtrT> tmp230;
  TNode<IntPtrT> tmp231;
  if (block145.is_used()) {
    ca_.Bind(&block145, &phi_bb145_17, &phi_bb145_18, &phi_bb145_19, &phi_bb145_27, &phi_bb145_28, &phi_bb145_29, &phi_bb145_30, &phi_bb145_32, &phi_bb145_33, &phi_bb145_34, &phi_bb145_35, &phi_bb145_37);
    std::tie(tmp228, tmp229) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb145_28}).Flatten();
    tmp230 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp231 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb145_28}, TNode<IntPtrT>{tmp230});
    ca_.Goto(&block144, phi_bb145_17, phi_bb145_18, phi_bb145_19, phi_bb145_27, tmp231, phi_bb145_29, phi_bb145_30, phi_bb145_32, phi_bb145_33, phi_bb145_34, phi_bb145_35, phi_bb145_37, tmp228, tmp229);
  }

  TNode<Object> phi_bb146_17;
  TNode<IntPtrT> phi_bb146_18;
  TNode<BoolT> phi_bb146_19;
  TNode<IntPtrT> phi_bb146_27;
  TNode<IntPtrT> phi_bb146_28;
  TNode<IntPtrT> phi_bb146_29;
  TNode<IntPtrT> phi_bb146_30;
  TNode<IntPtrT> phi_bb146_32;
  TNode<BoolT> phi_bb146_33;
  TNode<BoolT> phi_bb146_34;
  TNode<Object> phi_bb146_35;
  TNode<Int32T> phi_bb146_37;
  if (block146.is_used()) {
    ca_.Bind(&block146, &phi_bb146_17, &phi_bb146_18, &phi_bb146_19, &phi_bb146_27, &phi_bb146_28, &phi_bb146_29, &phi_bb146_30, &phi_bb146_32, &phi_bb146_33, &phi_bb146_34, &phi_bb146_35, &phi_bb146_37);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block148, phi_bb146_17, phi_bb146_18, phi_bb146_19, phi_bb146_27, phi_bb146_28, phi_bb146_29, phi_bb146_30, phi_bb146_32, phi_bb146_33, phi_bb146_34, phi_bb146_35, phi_bb146_37);
    } else {
      ca_.Goto(&block149, phi_bb146_17, phi_bb146_18, phi_bb146_19, phi_bb146_27, phi_bb146_28, phi_bb146_29, phi_bb146_30, phi_bb146_32, phi_bb146_33, phi_bb146_34, phi_bb146_35, phi_bb146_37);
    }
  }

  TNode<Object> phi_bb148_17;
  TNode<IntPtrT> phi_bb148_18;
  TNode<BoolT> phi_bb148_19;
  TNode<IntPtrT> phi_bb148_27;
  TNode<IntPtrT> phi_bb148_28;
  TNode<IntPtrT> phi_bb148_29;
  TNode<IntPtrT> phi_bb148_30;
  TNode<IntPtrT> phi_bb148_32;
  TNode<BoolT> phi_bb148_33;
  TNode<BoolT> phi_bb148_34;
  TNode<Object> phi_bb148_35;
  TNode<Int32T> phi_bb148_37;
  TNode<Object> tmp232;
  TNode<IntPtrT> tmp233;
  TNode<IntPtrT> tmp234;
  TNode<IntPtrT> tmp235;
  if (block148.is_used()) {
    ca_.Bind(&block148, &phi_bb148_17, &phi_bb148_18, &phi_bb148_19, &phi_bb148_27, &phi_bb148_28, &phi_bb148_29, &phi_bb148_30, &phi_bb148_32, &phi_bb148_33, &phi_bb148_34, &phi_bb148_35, &phi_bb148_37);
    std::tie(tmp232, tmp233) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb148_30}).Flatten();
    tmp234 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp235 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb148_30}, TNode<IntPtrT>{tmp234});
    ca_.Goto(&block147, phi_bb148_17, phi_bb148_18, phi_bb148_19, phi_bb148_27, phi_bb148_28, phi_bb148_29, tmp235, phi_bb148_32, phi_bb148_33, phi_bb148_34, phi_bb148_35, phi_bb148_37, tmp232, tmp233);
  }

  TNode<Object> phi_bb149_17;
  TNode<IntPtrT> phi_bb149_18;
  TNode<BoolT> phi_bb149_19;
  TNode<IntPtrT> phi_bb149_27;
  TNode<IntPtrT> phi_bb149_28;
  TNode<IntPtrT> phi_bb149_29;
  TNode<IntPtrT> phi_bb149_30;
  TNode<IntPtrT> phi_bb149_32;
  TNode<BoolT> phi_bb149_33;
  TNode<BoolT> phi_bb149_34;
  TNode<Object> phi_bb149_35;
  TNode<Int32T> phi_bb149_37;
  TNode<IntPtrT> tmp236;
  TNode<BoolT> tmp237;
  if (block149.is_used()) {
    ca_.Bind(&block149, &phi_bb149_17, &phi_bb149_18, &phi_bb149_19, &phi_bb149_27, &phi_bb149_28, &phi_bb149_29, &phi_bb149_30, &phi_bb149_32, &phi_bb149_33, &phi_bb149_34, &phi_bb149_35, &phi_bb149_37);
    tmp236 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp237 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb149_32}, TNode<IntPtrT>{tmp236});
    ca_.Branch(tmp237, &block151, std::vector<compiler::Node*>{phi_bb149_17, phi_bb149_18, phi_bb149_19, phi_bb149_27, phi_bb149_28, phi_bb149_29, phi_bb149_30, phi_bb149_32, phi_bb149_33, phi_bb149_34, phi_bb149_35, phi_bb149_37}, &block152, std::vector<compiler::Node*>{phi_bb149_17, phi_bb149_18, phi_bb149_19, phi_bb149_27, phi_bb149_28, phi_bb149_29, phi_bb149_30, phi_bb149_32, phi_bb149_33, phi_bb149_34, phi_bb149_35, phi_bb149_37});
  }

  TNode<Object> phi_bb151_17;
  TNode<IntPtrT> phi_bb151_18;
  TNode<BoolT> phi_bb151_19;
  TNode<IntPtrT> phi_bb151_27;
  TNode<IntPtrT> phi_bb151_28;
  TNode<IntPtrT> phi_bb151_29;
  TNode<IntPtrT> phi_bb151_30;
  TNode<IntPtrT> phi_bb151_32;
  TNode<BoolT> phi_bb151_33;
  TNode<BoolT> phi_bb151_34;
  TNode<Object> phi_bb151_35;
  TNode<Int32T> phi_bb151_37;
  TNode<Object> tmp238;
  TNode<IntPtrT> tmp239;
  TNode<IntPtrT> tmp240;
  TNode<BoolT> tmp241;
  if (block151.is_used()) {
    ca_.Bind(&block151, &phi_bb151_17, &phi_bb151_18, &phi_bb151_19, &phi_bb151_27, &phi_bb151_28, &phi_bb151_29, &phi_bb151_30, &phi_bb151_32, &phi_bb151_33, &phi_bb151_34, &phi_bb151_35, &phi_bb151_37);
    std::tie(tmp238, tmp239) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb151_32}).Flatten();
    tmp240 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp241 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block147, phi_bb151_17, phi_bb151_18, phi_bb151_19, phi_bb151_27, phi_bb151_28, phi_bb151_29, phi_bb151_30, tmp240, tmp241, phi_bb151_34, phi_bb151_35, phi_bb151_37, tmp238, tmp239);
  }

  TNode<Object> phi_bb152_17;
  TNode<IntPtrT> phi_bb152_18;
  TNode<BoolT> phi_bb152_19;
  TNode<IntPtrT> phi_bb152_27;
  TNode<IntPtrT> phi_bb152_28;
  TNode<IntPtrT> phi_bb152_29;
  TNode<IntPtrT> phi_bb152_30;
  TNode<IntPtrT> phi_bb152_32;
  TNode<BoolT> phi_bb152_33;
  TNode<BoolT> phi_bb152_34;
  TNode<Object> phi_bb152_35;
  TNode<Int32T> phi_bb152_37;
  TNode<Object> tmp242;
  TNode<IntPtrT> tmp243;
  TNode<IntPtrT> tmp244;
  TNode<IntPtrT> tmp245;
  TNode<IntPtrT> tmp246;
  TNode<IntPtrT> tmp247;
  TNode<BoolT> tmp248;
  if (block152.is_used()) {
    ca_.Bind(&block152, &phi_bb152_17, &phi_bb152_18, &phi_bb152_19, &phi_bb152_27, &phi_bb152_28, &phi_bb152_29, &phi_bb152_30, &phi_bb152_32, &phi_bb152_33, &phi_bb152_34, &phi_bb152_35, &phi_bb152_37);
    std::tie(tmp242, tmp243) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb152_30}).Flatten();
    tmp244 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp245 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb152_30}, TNode<IntPtrT>{tmp244});
    tmp246 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp247 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp245}, TNode<IntPtrT>{tmp246});
    tmp248 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block147, phi_bb152_17, phi_bb152_18, phi_bb152_19, phi_bb152_27, phi_bb152_28, phi_bb152_29, tmp247, tmp245, tmp248, phi_bb152_34, phi_bb152_35, phi_bb152_37, tmp242, tmp243);
  }

  TNode<Object> phi_bb147_17;
  TNode<IntPtrT> phi_bb147_18;
  TNode<BoolT> phi_bb147_19;
  TNode<IntPtrT> phi_bb147_27;
  TNode<IntPtrT> phi_bb147_28;
  TNode<IntPtrT> phi_bb147_29;
  TNode<IntPtrT> phi_bb147_30;
  TNode<IntPtrT> phi_bb147_32;
  TNode<BoolT> phi_bb147_33;
  TNode<BoolT> phi_bb147_34;
  TNode<Object> phi_bb147_35;
  TNode<Int32T> phi_bb147_37;
  TNode<Object> phi_bb147_40;
  TNode<IntPtrT> phi_bb147_41;
  if (block147.is_used()) {
    ca_.Bind(&block147, &phi_bb147_17, &phi_bb147_18, &phi_bb147_19, &phi_bb147_27, &phi_bb147_28, &phi_bb147_29, &phi_bb147_30, &phi_bb147_32, &phi_bb147_33, &phi_bb147_34, &phi_bb147_35, &phi_bb147_37, &phi_bb147_40, &phi_bb147_41);
    ca_.Goto(&block144, phi_bb147_17, phi_bb147_18, phi_bb147_19, phi_bb147_27, phi_bb147_28, phi_bb147_29, phi_bb147_30, phi_bb147_32, phi_bb147_33, phi_bb147_34, phi_bb147_35, phi_bb147_37, phi_bb147_40, phi_bb147_41);
  }

  TNode<Object> phi_bb144_17;
  TNode<IntPtrT> phi_bb144_18;
  TNode<BoolT> phi_bb144_19;
  TNode<IntPtrT> phi_bb144_27;
  TNode<IntPtrT> phi_bb144_28;
  TNode<IntPtrT> phi_bb144_29;
  TNode<IntPtrT> phi_bb144_30;
  TNode<IntPtrT> phi_bb144_32;
  TNode<BoolT> phi_bb144_33;
  TNode<BoolT> phi_bb144_34;
  TNode<Object> phi_bb144_35;
  TNode<Int32T> phi_bb144_37;
  TNode<Object> phi_bb144_40;
  TNode<IntPtrT> phi_bb144_41;
  TNode<Smi> tmp249;
  if (block144.is_used()) {
    ca_.Bind(&block144, &phi_bb144_17, &phi_bb144_18, &phi_bb144_19, &phi_bb144_27, &phi_bb144_28, &phi_bb144_29, &phi_bb144_30, &phi_bb144_32, &phi_bb144_33, &phi_bb144_34, &phi_bb144_35, &phi_bb144_37, &phi_bb144_40, &phi_bb144_41);
    compiler::CodeAssemblerLabel label250(&ca_);
    tmp249 = Cast_Smi_0(state_, TNode<Object>{tmp213}, &label250);
    ca_.Goto(&block155, phi_bb144_17, phi_bb144_18, phi_bb144_19, phi_bb144_27, phi_bb144_28, phi_bb144_29, phi_bb144_30, phi_bb144_32, phi_bb144_33, phi_bb144_34, phi_bb144_35, phi_bb144_37, phi_bb144_40, phi_bb144_41);
    if (label250.is_used()) {
      ca_.Bind(&label250);
      ca_.Goto(&block156, phi_bb144_17, phi_bb144_18, phi_bb144_19, phi_bb144_27, phi_bb144_28, phi_bb144_29, phi_bb144_30, phi_bb144_32, phi_bb144_33, phi_bb144_34, phi_bb144_35, phi_bb144_37, phi_bb144_40, phi_bb144_41);
    }
  }

  TNode<Object> phi_bb156_17;
  TNode<IntPtrT> phi_bb156_18;
  TNode<BoolT> phi_bb156_19;
  TNode<IntPtrT> phi_bb156_27;
  TNode<IntPtrT> phi_bb156_28;
  TNode<IntPtrT> phi_bb156_29;
  TNode<IntPtrT> phi_bb156_30;
  TNode<IntPtrT> phi_bb156_32;
  TNode<BoolT> phi_bb156_33;
  TNode<BoolT> phi_bb156_34;
  TNode<Object> phi_bb156_35;
  TNode<Int32T> phi_bb156_37;
  TNode<Object> phi_bb156_40;
  TNode<IntPtrT> phi_bb156_41;
  TNode<Int32T> tmp251;
  TNode<IntPtrT> tmp252;
  if (block156.is_used()) {
    ca_.Bind(&block156, &phi_bb156_17, &phi_bb156_18, &phi_bb156_19, &phi_bb156_27, &phi_bb156_28, &phi_bb156_29, &phi_bb156_30, &phi_bb156_32, &phi_bb156_33, &phi_bb156_34, &phi_bb156_35, &phi_bb156_37, &phi_bb156_40, &phi_bb156_41);
    tmp251 = ca_.CallBuiltin<Int32T>(Builtin::kWasmTaggedNonSmiToInt32, p_context, ca_.UncheckedCast<HeapObject>(tmp213));
    tmp252 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp251});
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb156_40, phi_bb156_41}, tmp252);
    ca_.Goto(&block153, phi_bb156_17, phi_bb156_18, phi_bb156_19, phi_bb156_27, phi_bb156_28, phi_bb156_29, phi_bb156_30, phi_bb156_32, phi_bb156_33, phi_bb156_34, phi_bb156_35, phi_bb156_37, phi_bb156_40, phi_bb156_41);
  }

  TNode<Object> phi_bb155_17;
  TNode<IntPtrT> phi_bb155_18;
  TNode<BoolT> phi_bb155_19;
  TNode<IntPtrT> phi_bb155_27;
  TNode<IntPtrT> phi_bb155_28;
  TNode<IntPtrT> phi_bb155_29;
  TNode<IntPtrT> phi_bb155_30;
  TNode<IntPtrT> phi_bb155_32;
  TNode<BoolT> phi_bb155_33;
  TNode<BoolT> phi_bb155_34;
  TNode<Object> phi_bb155_35;
  TNode<Int32T> phi_bb155_37;
  TNode<Object> phi_bb155_40;
  TNode<IntPtrT> phi_bb155_41;
  TNode<Int32T> tmp253;
  TNode<IntPtrT> tmp254;
  if (block155.is_used()) {
    ca_.Bind(&block155, &phi_bb155_17, &phi_bb155_18, &phi_bb155_19, &phi_bb155_27, &phi_bb155_28, &phi_bb155_29, &phi_bb155_30, &phi_bb155_32, &phi_bb155_33, &phi_bb155_34, &phi_bb155_35, &phi_bb155_37, &phi_bb155_40, &phi_bb155_41);
    tmp253 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi>{tmp249});
    tmp254 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp253});
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb155_40, phi_bb155_41}, tmp254);
    ca_.Goto(&block153, phi_bb155_17, phi_bb155_18, phi_bb155_19, phi_bb155_27, phi_bb155_28, phi_bb155_29, phi_bb155_30, phi_bb155_32, phi_bb155_33, phi_bb155_34, phi_bb155_35, phi_bb155_37, phi_bb155_40, phi_bb155_41);
  }

  TNode<Object> phi_bb153_17;
  TNode<IntPtrT> phi_bb153_18;
  TNode<BoolT> phi_bb153_19;
  TNode<IntPtrT> phi_bb153_27;
  TNode<IntPtrT> phi_bb153_28;
  TNode<IntPtrT> phi_bb153_29;
  TNode<IntPtrT> phi_bb153_30;
  TNode<IntPtrT> phi_bb153_32;
  TNode<BoolT> phi_bb153_33;
  TNode<BoolT> phi_bb153_34;
  TNode<Object> phi_bb153_35;
  TNode<Int32T> phi_bb153_37;
  TNode<Object> phi_bb153_40;
  TNode<IntPtrT> phi_bb153_41;
  if (block153.is_used()) {
    ca_.Bind(&block153, &phi_bb153_17, &phi_bb153_18, &phi_bb153_19, &phi_bb153_27, &phi_bb153_28, &phi_bb153_29, &phi_bb153_30, &phi_bb153_32, &phi_bb153_33, &phi_bb153_34, &phi_bb153_35, &phi_bb153_37, &phi_bb153_40, &phi_bb153_41);
    ca_.Goto(&block143, phi_bb153_17, phi_bb153_18, phi_bb153_19, tmp225, phi_bb153_27, phi_bb153_28, phi_bb153_29, phi_bb153_30, phi_bb153_32, phi_bb153_33, phi_bb153_34, phi_bb153_35, phi_bb153_37);
  }

  TNode<Object> phi_bb142_17;
  TNode<IntPtrT> phi_bb142_18;
  TNode<BoolT> phi_bb142_19;
  TNode<IntPtrT> phi_bb142_26;
  TNode<IntPtrT> phi_bb142_27;
  TNode<IntPtrT> phi_bb142_28;
  TNode<IntPtrT> phi_bb142_29;
  TNode<IntPtrT> phi_bb142_30;
  TNode<IntPtrT> phi_bb142_32;
  TNode<BoolT> phi_bb142_33;
  TNode<BoolT> phi_bb142_34;
  TNode<Object> phi_bb142_35;
  TNode<Int32T> phi_bb142_37;
  TNode<Int32T> tmp255;
  TNode<BoolT> tmp256;
  if (block142.is_used()) {
    ca_.Bind(&block142, &phi_bb142_17, &phi_bb142_18, &phi_bb142_19, &phi_bb142_26, &phi_bb142_27, &phi_bb142_28, &phi_bb142_29, &phi_bb142_30, &phi_bb142_32, &phi_bb142_33, &phi_bb142_34, &phi_bb142_35, &phi_bb142_37);
    tmp255 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF32.raw_bit_field());
    tmp256 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp221}, TNode<Int32T>{tmp255});
    ca_.Branch(tmp256, &block157, std::vector<compiler::Node*>{phi_bb142_17, phi_bb142_18, phi_bb142_19, phi_bb142_26, phi_bb142_27, phi_bb142_28, phi_bb142_29, phi_bb142_30, phi_bb142_32, phi_bb142_33, phi_bb142_34, phi_bb142_35, phi_bb142_37}, &block158, std::vector<compiler::Node*>{phi_bb142_17, phi_bb142_18, phi_bb142_19, phi_bb142_26, phi_bb142_27, phi_bb142_28, phi_bb142_29, phi_bb142_30, phi_bb142_32, phi_bb142_33, phi_bb142_34, phi_bb142_35, phi_bb142_37});
  }

  TNode<Object> phi_bb157_17;
  TNode<IntPtrT> phi_bb157_18;
  TNode<BoolT> phi_bb157_19;
  TNode<IntPtrT> phi_bb157_26;
  TNode<IntPtrT> phi_bb157_27;
  TNode<IntPtrT> phi_bb157_28;
  TNode<IntPtrT> phi_bb157_29;
  TNode<IntPtrT> phi_bb157_30;
  TNode<IntPtrT> phi_bb157_32;
  TNode<BoolT> phi_bb157_33;
  TNode<BoolT> phi_bb157_34;
  TNode<Object> phi_bb157_35;
  TNode<Int32T> phi_bb157_37;
  TNode<IntPtrT> tmp257;
  TNode<IntPtrT> tmp258;
  TNode<IntPtrT> tmp259;
  TNode<BoolT> tmp260;
  if (block157.is_used()) {
    ca_.Bind(&block157, &phi_bb157_17, &phi_bb157_18, &phi_bb157_19, &phi_bb157_26, &phi_bb157_27, &phi_bb157_28, &phi_bb157_29, &phi_bb157_30, &phi_bb157_32, &phi_bb157_33, &phi_bb157_34, &phi_bb157_35, &phi_bb157_37);
    tmp257 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp258 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb157_27}, TNode<IntPtrT>{tmp257});
    tmp259 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp260 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb157_27}, TNode<IntPtrT>{tmp259});
    ca_.Branch(tmp260, &block161, std::vector<compiler::Node*>{phi_bb157_17, phi_bb157_18, phi_bb157_19, phi_bb157_26, phi_bb157_28, phi_bb157_29, phi_bb157_30, phi_bb157_32, phi_bb157_33, phi_bb157_34, phi_bb157_35, phi_bb157_37}, &block162, std::vector<compiler::Node*>{phi_bb157_17, phi_bb157_18, phi_bb157_19, phi_bb157_26, phi_bb157_28, phi_bb157_29, phi_bb157_30, phi_bb157_32, phi_bb157_33, phi_bb157_34, phi_bb157_35, phi_bb157_37});
  }

  TNode<Object> phi_bb161_17;
  TNode<IntPtrT> phi_bb161_18;
  TNode<BoolT> phi_bb161_19;
  TNode<IntPtrT> phi_bb161_26;
  TNode<IntPtrT> phi_bb161_28;
  TNode<IntPtrT> phi_bb161_29;
  TNode<IntPtrT> phi_bb161_30;
  TNode<IntPtrT> phi_bb161_32;
  TNode<BoolT> phi_bb161_33;
  TNode<BoolT> phi_bb161_34;
  TNode<Object> phi_bb161_35;
  TNode<Int32T> phi_bb161_37;
  TNode<Object> tmp261;
  TNode<IntPtrT> tmp262;
  TNode<IntPtrT> tmp263;
  TNode<IntPtrT> tmp264;
  if (block161.is_used()) {
    ca_.Bind(&block161, &phi_bb161_17, &phi_bb161_18, &phi_bb161_19, &phi_bb161_26, &phi_bb161_28, &phi_bb161_29, &phi_bb161_30, &phi_bb161_32, &phi_bb161_33, &phi_bb161_34, &phi_bb161_35, &phi_bb161_37);
    std::tie(tmp261, tmp262) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb161_29}).Flatten();
    tmp263 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp264 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb161_29}, TNode<IntPtrT>{tmp263});
    ca_.Goto(&block160, phi_bb161_17, phi_bb161_18, phi_bb161_19, phi_bb161_26, phi_bb161_28, tmp264, phi_bb161_30, phi_bb161_32, phi_bb161_33, phi_bb161_34, phi_bb161_35, phi_bb161_37, tmp261, tmp262);
  }

  TNode<Object> phi_bb162_17;
  TNode<IntPtrT> phi_bb162_18;
  TNode<BoolT> phi_bb162_19;
  TNode<IntPtrT> phi_bb162_26;
  TNode<IntPtrT> phi_bb162_28;
  TNode<IntPtrT> phi_bb162_29;
  TNode<IntPtrT> phi_bb162_30;
  TNode<IntPtrT> phi_bb162_32;
  TNode<BoolT> phi_bb162_33;
  TNode<BoolT> phi_bb162_34;
  TNode<Object> phi_bb162_35;
  TNode<Int32T> phi_bb162_37;
  if (block162.is_used()) {
    ca_.Bind(&block162, &phi_bb162_17, &phi_bb162_18, &phi_bb162_19, &phi_bb162_26, &phi_bb162_28, &phi_bb162_29, &phi_bb162_30, &phi_bb162_32, &phi_bb162_33, &phi_bb162_34, &phi_bb162_35, &phi_bb162_37);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block164, phi_bb162_17, phi_bb162_18, phi_bb162_19, phi_bb162_26, phi_bb162_28, phi_bb162_29, phi_bb162_30, phi_bb162_32, phi_bb162_33, phi_bb162_34, phi_bb162_35, phi_bb162_37);
    } else {
      ca_.Goto(&block165, phi_bb162_17, phi_bb162_18, phi_bb162_19, phi_bb162_26, phi_bb162_28, phi_bb162_29, phi_bb162_30, phi_bb162_32, phi_bb162_33, phi_bb162_34, phi_bb162_35, phi_bb162_37);
    }
  }

  TNode<Object> phi_bb164_17;
  TNode<IntPtrT> phi_bb164_18;
  TNode<BoolT> phi_bb164_19;
  TNode<IntPtrT> phi_bb164_26;
  TNode<IntPtrT> phi_bb164_28;
  TNode<IntPtrT> phi_bb164_29;
  TNode<IntPtrT> phi_bb164_30;
  TNode<IntPtrT> phi_bb164_32;
  TNode<BoolT> phi_bb164_33;
  TNode<BoolT> phi_bb164_34;
  TNode<Object> phi_bb164_35;
  TNode<Int32T> phi_bb164_37;
  TNode<Object> tmp265;
  TNode<IntPtrT> tmp266;
  TNode<IntPtrT> tmp267;
  TNode<IntPtrT> tmp268;
  if (block164.is_used()) {
    ca_.Bind(&block164, &phi_bb164_17, &phi_bb164_18, &phi_bb164_19, &phi_bb164_26, &phi_bb164_28, &phi_bb164_29, &phi_bb164_30, &phi_bb164_32, &phi_bb164_33, &phi_bb164_34, &phi_bb164_35, &phi_bb164_37);
    std::tie(tmp265, tmp266) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb164_30}).Flatten();
    tmp267 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp268 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb164_30}, TNode<IntPtrT>{tmp267});
    ca_.Goto(&block163, phi_bb164_17, phi_bb164_18, phi_bb164_19, phi_bb164_26, phi_bb164_28, phi_bb164_29, tmp268, phi_bb164_32, phi_bb164_33, phi_bb164_34, phi_bb164_35, phi_bb164_37, tmp265, tmp266);
  }

  TNode<Object> phi_bb165_17;
  TNode<IntPtrT> phi_bb165_18;
  TNode<BoolT> phi_bb165_19;
  TNode<IntPtrT> phi_bb165_26;
  TNode<IntPtrT> phi_bb165_28;
  TNode<IntPtrT> phi_bb165_29;
  TNode<IntPtrT> phi_bb165_30;
  TNode<IntPtrT> phi_bb165_32;
  TNode<BoolT> phi_bb165_33;
  TNode<BoolT> phi_bb165_34;
  TNode<Object> phi_bb165_35;
  TNode<Int32T> phi_bb165_37;
  TNode<IntPtrT> tmp269;
  TNode<BoolT> tmp270;
  if (block165.is_used()) {
    ca_.Bind(&block165, &phi_bb165_17, &phi_bb165_18, &phi_bb165_19, &phi_bb165_26, &phi_bb165_28, &phi_bb165_29, &phi_bb165_30, &phi_bb165_32, &phi_bb165_33, &phi_bb165_34, &phi_bb165_35, &phi_bb165_37);
    tmp269 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp270 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb165_32}, TNode<IntPtrT>{tmp269});
    ca_.Branch(tmp270, &block167, std::vector<compiler::Node*>{phi_bb165_17, phi_bb165_18, phi_bb165_19, phi_bb165_26, phi_bb165_28, phi_bb165_29, phi_bb165_30, phi_bb165_32, phi_bb165_33, phi_bb165_34, phi_bb165_35, phi_bb165_37}, &block168, std::vector<compiler::Node*>{phi_bb165_17, phi_bb165_18, phi_bb165_19, phi_bb165_26, phi_bb165_28, phi_bb165_29, phi_bb165_30, phi_bb165_32, phi_bb165_33, phi_bb165_34, phi_bb165_35, phi_bb165_37});
  }

  TNode<Object> phi_bb167_17;
  TNode<IntPtrT> phi_bb167_18;
  TNode<BoolT> phi_bb167_19;
  TNode<IntPtrT> phi_bb167_26;
  TNode<IntPtrT> phi_bb167_28;
  TNode<IntPtrT> phi_bb167_29;
  TNode<IntPtrT> phi_bb167_30;
  TNode<IntPtrT> phi_bb167_32;
  TNode<BoolT> phi_bb167_33;
  TNode<BoolT> phi_bb167_34;
  TNode<Object> phi_bb167_35;
  TNode<Int32T> phi_bb167_37;
  TNode<Object> tmp271;
  TNode<IntPtrT> tmp272;
  TNode<IntPtrT> tmp273;
  TNode<BoolT> tmp274;
  if (block167.is_used()) {
    ca_.Bind(&block167, &phi_bb167_17, &phi_bb167_18, &phi_bb167_19, &phi_bb167_26, &phi_bb167_28, &phi_bb167_29, &phi_bb167_30, &phi_bb167_32, &phi_bb167_33, &phi_bb167_34, &phi_bb167_35, &phi_bb167_37);
    std::tie(tmp271, tmp272) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb167_32}).Flatten();
    tmp273 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp274 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block163, phi_bb167_17, phi_bb167_18, phi_bb167_19, phi_bb167_26, phi_bb167_28, phi_bb167_29, phi_bb167_30, tmp273, tmp274, phi_bb167_34, phi_bb167_35, phi_bb167_37, tmp271, tmp272);
  }

  TNode<Object> phi_bb168_17;
  TNode<IntPtrT> phi_bb168_18;
  TNode<BoolT> phi_bb168_19;
  TNode<IntPtrT> phi_bb168_26;
  TNode<IntPtrT> phi_bb168_28;
  TNode<IntPtrT> phi_bb168_29;
  TNode<IntPtrT> phi_bb168_30;
  TNode<IntPtrT> phi_bb168_32;
  TNode<BoolT> phi_bb168_33;
  TNode<BoolT> phi_bb168_34;
  TNode<Object> phi_bb168_35;
  TNode<Int32T> phi_bb168_37;
  TNode<Object> tmp275;
  TNode<IntPtrT> tmp276;
  TNode<IntPtrT> tmp277;
  TNode<IntPtrT> tmp278;
  TNode<IntPtrT> tmp279;
  TNode<IntPtrT> tmp280;
  TNode<BoolT> tmp281;
  if (block168.is_used()) {
    ca_.Bind(&block168, &phi_bb168_17, &phi_bb168_18, &phi_bb168_19, &phi_bb168_26, &phi_bb168_28, &phi_bb168_29, &phi_bb168_30, &phi_bb168_32, &phi_bb168_33, &phi_bb168_34, &phi_bb168_35, &phi_bb168_37);
    std::tie(tmp275, tmp276) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb168_30}).Flatten();
    tmp277 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp278 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb168_30}, TNode<IntPtrT>{tmp277});
    tmp279 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp280 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp278}, TNode<IntPtrT>{tmp279});
    tmp281 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block163, phi_bb168_17, phi_bb168_18, phi_bb168_19, phi_bb168_26, phi_bb168_28, phi_bb168_29, tmp280, tmp278, tmp281, phi_bb168_34, phi_bb168_35, phi_bb168_37, tmp275, tmp276);
  }

  TNode<Object> phi_bb163_17;
  TNode<IntPtrT> phi_bb163_18;
  TNode<BoolT> phi_bb163_19;
  TNode<IntPtrT> phi_bb163_26;
  TNode<IntPtrT> phi_bb163_28;
  TNode<IntPtrT> phi_bb163_29;
  TNode<IntPtrT> phi_bb163_30;
  TNode<IntPtrT> phi_bb163_32;
  TNode<BoolT> phi_bb163_33;
  TNode<BoolT> phi_bb163_34;
  TNode<Object> phi_bb163_35;
  TNode<Int32T> phi_bb163_37;
  TNode<Object> phi_bb163_40;
  TNode<IntPtrT> phi_bb163_41;
  if (block163.is_used()) {
    ca_.Bind(&block163, &phi_bb163_17, &phi_bb163_18, &phi_bb163_19, &phi_bb163_26, &phi_bb163_28, &phi_bb163_29, &phi_bb163_30, &phi_bb163_32, &phi_bb163_33, &phi_bb163_34, &phi_bb163_35, &phi_bb163_37, &phi_bb163_40, &phi_bb163_41);
    ca_.Goto(&block160, phi_bb163_17, phi_bb163_18, phi_bb163_19, phi_bb163_26, phi_bb163_28, phi_bb163_29, phi_bb163_30, phi_bb163_32, phi_bb163_33, phi_bb163_34, phi_bb163_35, phi_bb163_37, phi_bb163_40, phi_bb163_41);
  }

  TNode<Object> phi_bb160_17;
  TNode<IntPtrT> phi_bb160_18;
  TNode<BoolT> phi_bb160_19;
  TNode<IntPtrT> phi_bb160_26;
  TNode<IntPtrT> phi_bb160_28;
  TNode<IntPtrT> phi_bb160_29;
  TNode<IntPtrT> phi_bb160_30;
  TNode<IntPtrT> phi_bb160_32;
  TNode<BoolT> phi_bb160_33;
  TNode<BoolT> phi_bb160_34;
  TNode<Object> phi_bb160_35;
  TNode<Int32T> phi_bb160_37;
  TNode<Object> phi_bb160_40;
  TNode<IntPtrT> phi_bb160_41;
  if (block160.is_used()) {
    ca_.Bind(&block160, &phi_bb160_17, &phi_bb160_18, &phi_bb160_19, &phi_bb160_26, &phi_bb160_28, &phi_bb160_29, &phi_bb160_30, &phi_bb160_32, &phi_bb160_33, &phi_bb160_34, &phi_bb160_35, &phi_bb160_37, &phi_bb160_40, &phi_bb160_41);
    if ((((wasm::kIsFpAlwaysDouble || wasm::kIsBigEndian) || wasm::kIsBigEndianOnSim))) {
      ca_.Goto(&block169, phi_bb160_17, phi_bb160_18, phi_bb160_19, phi_bb160_26, phi_bb160_28, phi_bb160_29, phi_bb160_30, phi_bb160_32, phi_bb160_33, phi_bb160_34, phi_bb160_35, phi_bb160_37, phi_bb160_40, phi_bb160_41);
    } else {
      ca_.Goto(&block170, phi_bb160_17, phi_bb160_18, phi_bb160_19, phi_bb160_26, phi_bb160_28, phi_bb160_29, phi_bb160_30, phi_bb160_32, phi_bb160_33, phi_bb160_34, phi_bb160_35, phi_bb160_37, phi_bb160_40, phi_bb160_41);
    }
  }

  TNode<Object> phi_bb169_17;
  TNode<IntPtrT> phi_bb169_18;
  TNode<BoolT> phi_bb169_19;
  TNode<IntPtrT> phi_bb169_26;
  TNode<IntPtrT> phi_bb169_28;
  TNode<IntPtrT> phi_bb169_29;
  TNode<IntPtrT> phi_bb169_30;
  TNode<IntPtrT> phi_bb169_32;
  TNode<BoolT> phi_bb169_33;
  TNode<BoolT> phi_bb169_34;
  TNode<Object> phi_bb169_35;
  TNode<Int32T> phi_bb169_37;
  TNode<Object> phi_bb169_40;
  TNode<IntPtrT> phi_bb169_41;
  if (block169.is_used()) {
    ca_.Bind(&block169, &phi_bb169_17, &phi_bb169_18, &phi_bb169_19, &phi_bb169_26, &phi_bb169_28, &phi_bb169_29, &phi_bb169_30, &phi_bb169_32, &phi_bb169_33, &phi_bb169_34, &phi_bb169_35, &phi_bb169_37, &phi_bb169_40, &phi_bb169_41);
    HandleF32Params_0(state_, TNode<NativeContext>{p_context}, TorqueStructLocationAllocator_0{TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb169_26}, TNode<IntPtrT>{tmp258}, TNode<IntPtrT>{phi_bb169_28}, TNode<IntPtrT>{phi_bb169_29}, TNode<IntPtrT>{phi_bb169_30}, TNode<IntPtrT>{tmp204}, TNode<IntPtrT>{phi_bb169_32}, TNode<BoolT>{phi_bb169_33}}, TorqueStructReference_intptr_0{TNode<Object>{phi_bb169_40}, TNode<IntPtrT>{phi_bb169_41}, TorqueStructUnsafe_0{}}, TNode<Object>{tmp213});
    ca_.Goto(&block171, phi_bb169_17, phi_bb169_18, phi_bb169_19, phi_bb169_26, phi_bb169_28, phi_bb169_29, phi_bb169_30, phi_bb169_32, phi_bb169_33, phi_bb169_34, phi_bb169_35, phi_bb169_37, phi_bb169_40, phi_bb169_41);
  }

  TNode<Object> phi_bb170_17;
  TNode<IntPtrT> phi_bb170_18;
  TNode<BoolT> phi_bb170_19;
  TNode<IntPtrT> phi_bb170_26;
  TNode<IntPtrT> phi_bb170_28;
  TNode<IntPtrT> phi_bb170_29;
  TNode<IntPtrT> phi_bb170_30;
  TNode<IntPtrT> phi_bb170_32;
  TNode<BoolT> phi_bb170_33;
  TNode<BoolT> phi_bb170_34;
  TNode<Object> phi_bb170_35;
  TNode<Int32T> phi_bb170_37;
  TNode<Object> phi_bb170_40;
  TNode<IntPtrT> phi_bb170_41;
  TNode<Float32T> tmp282;
  TNode<Uint32T> tmp283;
  TNode<IntPtrT> tmp284;
  if (block170.is_used()) {
    ca_.Bind(&block170, &phi_bb170_17, &phi_bb170_18, &phi_bb170_19, &phi_bb170_26, &phi_bb170_28, &phi_bb170_29, &phi_bb170_30, &phi_bb170_32, &phi_bb170_33, &phi_bb170_34, &phi_bb170_35, &phi_bb170_37, &phi_bb170_40, &phi_bb170_41);
    tmp282 = ca_.CallBuiltin<Float32T>(Builtin::kWasmTaggedToFloat32, p_context, tmp213);
    tmp283 = Bitcast_uint32_float32_0(state_, TNode<Float32T>{tmp282});
    tmp284 = Convert_intptr_uint32_0(state_, TNode<Uint32T>{tmp283});
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb170_40, phi_bb170_41}, tmp284);
    ca_.Goto(&block171, phi_bb170_17, phi_bb170_18, phi_bb170_19, phi_bb170_26, phi_bb170_28, phi_bb170_29, phi_bb170_30, phi_bb170_32, phi_bb170_33, phi_bb170_34, phi_bb170_35, phi_bb170_37, phi_bb170_40, phi_bb170_41);
  }

  TNode<Object> phi_bb171_17;
  TNode<IntPtrT> phi_bb171_18;
  TNode<BoolT> phi_bb171_19;
  TNode<IntPtrT> phi_bb171_26;
  TNode<IntPtrT> phi_bb171_28;
  TNode<IntPtrT> phi_bb171_29;
  TNode<IntPtrT> phi_bb171_30;
  TNode<IntPtrT> phi_bb171_32;
  TNode<BoolT> phi_bb171_33;
  TNode<BoolT> phi_bb171_34;
  TNode<Object> phi_bb171_35;
  TNode<Int32T> phi_bb171_37;
  TNode<Object> phi_bb171_40;
  TNode<IntPtrT> phi_bb171_41;
  if (block171.is_used()) {
    ca_.Bind(&block171, &phi_bb171_17, &phi_bb171_18, &phi_bb171_19, &phi_bb171_26, &phi_bb171_28, &phi_bb171_29, &phi_bb171_30, &phi_bb171_32, &phi_bb171_33, &phi_bb171_34, &phi_bb171_35, &phi_bb171_37, &phi_bb171_40, &phi_bb171_41);
    ca_.Goto(&block159, phi_bb171_17, phi_bb171_18, phi_bb171_19, phi_bb171_26, tmp258, phi_bb171_28, phi_bb171_29, phi_bb171_30, phi_bb171_32, phi_bb171_33, phi_bb171_34, phi_bb171_35, phi_bb171_37);
  }

  TNode<Object> phi_bb158_17;
  TNode<IntPtrT> phi_bb158_18;
  TNode<BoolT> phi_bb158_19;
  TNode<IntPtrT> phi_bb158_26;
  TNode<IntPtrT> phi_bb158_27;
  TNode<IntPtrT> phi_bb158_28;
  TNode<IntPtrT> phi_bb158_29;
  TNode<IntPtrT> phi_bb158_30;
  TNode<IntPtrT> phi_bb158_32;
  TNode<BoolT> phi_bb158_33;
  TNode<BoolT> phi_bb158_34;
  TNode<Object> phi_bb158_35;
  TNode<Int32T> phi_bb158_37;
  TNode<Int32T> tmp285;
  TNode<BoolT> tmp286;
  if (block158.is_used()) {
    ca_.Bind(&block158, &phi_bb158_17, &phi_bb158_18, &phi_bb158_19, &phi_bb158_26, &phi_bb158_27, &phi_bb158_28, &phi_bb158_29, &phi_bb158_30, &phi_bb158_32, &phi_bb158_33, &phi_bb158_34, &phi_bb158_35, &phi_bb158_37);
    tmp285 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF64.raw_bit_field());
    tmp286 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp221}, TNode<Int32T>{tmp285});
    ca_.Branch(tmp286, &block172, std::vector<compiler::Node*>{phi_bb158_17, phi_bb158_18, phi_bb158_19, phi_bb158_26, phi_bb158_27, phi_bb158_28, phi_bb158_29, phi_bb158_30, phi_bb158_32, phi_bb158_33, phi_bb158_34, phi_bb158_35, phi_bb158_37}, &block173, std::vector<compiler::Node*>{phi_bb158_17, phi_bb158_18, phi_bb158_19, phi_bb158_26, phi_bb158_27, phi_bb158_28, phi_bb158_29, phi_bb158_30, phi_bb158_32, phi_bb158_33, phi_bb158_34, phi_bb158_35, phi_bb158_37});
  }

  TNode<Object> phi_bb172_17;
  TNode<IntPtrT> phi_bb172_18;
  TNode<BoolT> phi_bb172_19;
  TNode<IntPtrT> phi_bb172_26;
  TNode<IntPtrT> phi_bb172_27;
  TNode<IntPtrT> phi_bb172_28;
  TNode<IntPtrT> phi_bb172_29;
  TNode<IntPtrT> phi_bb172_30;
  TNode<IntPtrT> phi_bb172_32;
  TNode<BoolT> phi_bb172_33;
  TNode<BoolT> phi_bb172_34;
  TNode<Object> phi_bb172_35;
  TNode<Int32T> phi_bb172_37;
  TNode<IntPtrT> tmp287;
  TNode<IntPtrT> tmp288;
  TNode<IntPtrT> tmp289;
  TNode<BoolT> tmp290;
  if (block172.is_used()) {
    ca_.Bind(&block172, &phi_bb172_17, &phi_bb172_18, &phi_bb172_19, &phi_bb172_26, &phi_bb172_27, &phi_bb172_28, &phi_bb172_29, &phi_bb172_30, &phi_bb172_32, &phi_bb172_33, &phi_bb172_34, &phi_bb172_35, &phi_bb172_37);
    tmp287 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp288 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb172_27}, TNode<IntPtrT>{tmp287});
    tmp289 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp290 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb172_27}, TNode<IntPtrT>{tmp289});
    ca_.Branch(tmp290, &block176, std::vector<compiler::Node*>{phi_bb172_17, phi_bb172_18, phi_bb172_19, phi_bb172_26, phi_bb172_28, phi_bb172_29, phi_bb172_30, phi_bb172_32, phi_bb172_33, phi_bb172_34, phi_bb172_35, phi_bb172_37}, &block177, std::vector<compiler::Node*>{phi_bb172_17, phi_bb172_18, phi_bb172_19, phi_bb172_26, phi_bb172_28, phi_bb172_29, phi_bb172_30, phi_bb172_32, phi_bb172_33, phi_bb172_34, phi_bb172_35, phi_bb172_37});
  }

  TNode<Object> phi_bb176_17;
  TNode<IntPtrT> phi_bb176_18;
  TNode<BoolT> phi_bb176_19;
  TNode<IntPtrT> phi_bb176_26;
  TNode<IntPtrT> phi_bb176_28;
  TNode<IntPtrT> phi_bb176_29;
  TNode<IntPtrT> phi_bb176_30;
  TNode<IntPtrT> phi_bb176_32;
  TNode<BoolT> phi_bb176_33;
  TNode<BoolT> phi_bb176_34;
  TNode<Object> phi_bb176_35;
  TNode<Int32T> phi_bb176_37;
  TNode<Object> tmp291;
  TNode<IntPtrT> tmp292;
  TNode<IntPtrT> tmp293;
  TNode<IntPtrT> tmp294;
  if (block176.is_used()) {
    ca_.Bind(&block176, &phi_bb176_17, &phi_bb176_18, &phi_bb176_19, &phi_bb176_26, &phi_bb176_28, &phi_bb176_29, &phi_bb176_30, &phi_bb176_32, &phi_bb176_33, &phi_bb176_34, &phi_bb176_35, &phi_bb176_37);
    std::tie(tmp291, tmp292) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb176_29}).Flatten();
    tmp293 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp294 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb176_29}, TNode<IntPtrT>{tmp293});
    ca_.Goto(&block175, phi_bb176_17, phi_bb176_18, phi_bb176_19, phi_bb176_26, phi_bb176_28, tmp294, phi_bb176_30, phi_bb176_32, phi_bb176_33, phi_bb176_34, phi_bb176_35, phi_bb176_37, tmp291, tmp292);
  }

  TNode<Object> phi_bb177_17;
  TNode<IntPtrT> phi_bb177_18;
  TNode<BoolT> phi_bb177_19;
  TNode<IntPtrT> phi_bb177_26;
  TNode<IntPtrT> phi_bb177_28;
  TNode<IntPtrT> phi_bb177_29;
  TNode<IntPtrT> phi_bb177_30;
  TNode<IntPtrT> phi_bb177_32;
  TNode<BoolT> phi_bb177_33;
  TNode<BoolT> phi_bb177_34;
  TNode<Object> phi_bb177_35;
  TNode<Int32T> phi_bb177_37;
  if (block177.is_used()) {
    ca_.Bind(&block177, &phi_bb177_17, &phi_bb177_18, &phi_bb177_19, &phi_bb177_26, &phi_bb177_28, &phi_bb177_29, &phi_bb177_30, &phi_bb177_32, &phi_bb177_33, &phi_bb177_34, &phi_bb177_35, &phi_bb177_37);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block178, phi_bb177_17, phi_bb177_18, phi_bb177_19, phi_bb177_26, phi_bb177_28, phi_bb177_29, phi_bb177_30, phi_bb177_32, phi_bb177_33, phi_bb177_34, phi_bb177_35, phi_bb177_37);
    } else {
      ca_.Goto(&block179, phi_bb177_17, phi_bb177_18, phi_bb177_19, phi_bb177_26, phi_bb177_28, phi_bb177_29, phi_bb177_30, phi_bb177_32, phi_bb177_33, phi_bb177_34, phi_bb177_35, phi_bb177_37);
    }
  }

  TNode<Object> phi_bb178_17;
  TNode<IntPtrT> phi_bb178_18;
  TNode<BoolT> phi_bb178_19;
  TNode<IntPtrT> phi_bb178_26;
  TNode<IntPtrT> phi_bb178_28;
  TNode<IntPtrT> phi_bb178_29;
  TNode<IntPtrT> phi_bb178_30;
  TNode<IntPtrT> phi_bb178_32;
  TNode<BoolT> phi_bb178_33;
  TNode<BoolT> phi_bb178_34;
  TNode<Object> phi_bb178_35;
  TNode<Int32T> phi_bb178_37;
  if (block178.is_used()) {
    ca_.Bind(&block178, &phi_bb178_17, &phi_bb178_18, &phi_bb178_19, &phi_bb178_26, &phi_bb178_28, &phi_bb178_29, &phi_bb178_30, &phi_bb178_32, &phi_bb178_33, &phi_bb178_34, &phi_bb178_35, &phi_bb178_37);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block182, phi_bb178_17, phi_bb178_18, phi_bb178_19, phi_bb178_26, phi_bb178_28, phi_bb178_29, phi_bb178_30, phi_bb178_32, phi_bb178_33, phi_bb178_34, phi_bb178_35, phi_bb178_37);
    } else {
      ca_.Goto(&block183, phi_bb178_17, phi_bb178_18, phi_bb178_19, phi_bb178_26, phi_bb178_28, phi_bb178_29, phi_bb178_30, phi_bb178_32, phi_bb178_33, phi_bb178_34, phi_bb178_35, phi_bb178_37);
    }
  }

  TNode<Object> phi_bb182_17;
  TNode<IntPtrT> phi_bb182_18;
  TNode<BoolT> phi_bb182_19;
  TNode<IntPtrT> phi_bb182_26;
  TNode<IntPtrT> phi_bb182_28;
  TNode<IntPtrT> phi_bb182_29;
  TNode<IntPtrT> phi_bb182_30;
  TNode<IntPtrT> phi_bb182_32;
  TNode<BoolT> phi_bb182_33;
  TNode<BoolT> phi_bb182_34;
  TNode<Object> phi_bb182_35;
  TNode<Int32T> phi_bb182_37;
  TNode<Object> tmp295;
  TNode<IntPtrT> tmp296;
  TNode<IntPtrT> tmp297;
  TNode<IntPtrT> tmp298;
  if (block182.is_used()) {
    ca_.Bind(&block182, &phi_bb182_17, &phi_bb182_18, &phi_bb182_19, &phi_bb182_26, &phi_bb182_28, &phi_bb182_29, &phi_bb182_30, &phi_bb182_32, &phi_bb182_33, &phi_bb182_34, &phi_bb182_35, &phi_bb182_37);
    std::tie(tmp295, tmp296) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb182_30}).Flatten();
    tmp297 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp298 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb182_30}, TNode<IntPtrT>{tmp297});
    ca_.Goto(&block181, phi_bb182_17, phi_bb182_18, phi_bb182_19, phi_bb182_26, phi_bb182_28, phi_bb182_29, tmp298, phi_bb182_32, phi_bb182_33, phi_bb182_34, phi_bb182_35, phi_bb182_37, tmp295, tmp296);
  }

  TNode<Object> phi_bb183_17;
  TNode<IntPtrT> phi_bb183_18;
  TNode<BoolT> phi_bb183_19;
  TNode<IntPtrT> phi_bb183_26;
  TNode<IntPtrT> phi_bb183_28;
  TNode<IntPtrT> phi_bb183_29;
  TNode<IntPtrT> phi_bb183_30;
  TNode<IntPtrT> phi_bb183_32;
  TNode<BoolT> phi_bb183_33;
  TNode<BoolT> phi_bb183_34;
  TNode<Object> phi_bb183_35;
  TNode<Int32T> phi_bb183_37;
  TNode<IntPtrT> tmp299;
  TNode<BoolT> tmp300;
  if (block183.is_used()) {
    ca_.Bind(&block183, &phi_bb183_17, &phi_bb183_18, &phi_bb183_19, &phi_bb183_26, &phi_bb183_28, &phi_bb183_29, &phi_bb183_30, &phi_bb183_32, &phi_bb183_33, &phi_bb183_34, &phi_bb183_35, &phi_bb183_37);
    tmp299 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp300 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb183_32}, TNode<IntPtrT>{tmp299});
    ca_.Branch(tmp300, &block185, std::vector<compiler::Node*>{phi_bb183_17, phi_bb183_18, phi_bb183_19, phi_bb183_26, phi_bb183_28, phi_bb183_29, phi_bb183_30, phi_bb183_32, phi_bb183_33, phi_bb183_34, phi_bb183_35, phi_bb183_37}, &block186, std::vector<compiler::Node*>{phi_bb183_17, phi_bb183_18, phi_bb183_19, phi_bb183_26, phi_bb183_28, phi_bb183_29, phi_bb183_30, phi_bb183_32, phi_bb183_33, phi_bb183_34, phi_bb183_35, phi_bb183_37});
  }

  TNode<Object> phi_bb185_17;
  TNode<IntPtrT> phi_bb185_18;
  TNode<BoolT> phi_bb185_19;
  TNode<IntPtrT> phi_bb185_26;
  TNode<IntPtrT> phi_bb185_28;
  TNode<IntPtrT> phi_bb185_29;
  TNode<IntPtrT> phi_bb185_30;
  TNode<IntPtrT> phi_bb185_32;
  TNode<BoolT> phi_bb185_33;
  TNode<BoolT> phi_bb185_34;
  TNode<Object> phi_bb185_35;
  TNode<Int32T> phi_bb185_37;
  TNode<Object> tmp301;
  TNode<IntPtrT> tmp302;
  TNode<IntPtrT> tmp303;
  TNode<BoolT> tmp304;
  if (block185.is_used()) {
    ca_.Bind(&block185, &phi_bb185_17, &phi_bb185_18, &phi_bb185_19, &phi_bb185_26, &phi_bb185_28, &phi_bb185_29, &phi_bb185_30, &phi_bb185_32, &phi_bb185_33, &phi_bb185_34, &phi_bb185_35, &phi_bb185_37);
    std::tie(tmp301, tmp302) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb185_32}).Flatten();
    tmp303 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp304 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block181, phi_bb185_17, phi_bb185_18, phi_bb185_19, phi_bb185_26, phi_bb185_28, phi_bb185_29, phi_bb185_30, tmp303, tmp304, phi_bb185_34, phi_bb185_35, phi_bb185_37, tmp301, tmp302);
  }

  TNode<Object> phi_bb186_17;
  TNode<IntPtrT> phi_bb186_18;
  TNode<BoolT> phi_bb186_19;
  TNode<IntPtrT> phi_bb186_26;
  TNode<IntPtrT> phi_bb186_28;
  TNode<IntPtrT> phi_bb186_29;
  TNode<IntPtrT> phi_bb186_30;
  TNode<IntPtrT> phi_bb186_32;
  TNode<BoolT> phi_bb186_33;
  TNode<BoolT> phi_bb186_34;
  TNode<Object> phi_bb186_35;
  TNode<Int32T> phi_bb186_37;
  TNode<Object> tmp305;
  TNode<IntPtrT> tmp306;
  TNode<IntPtrT> tmp307;
  TNode<IntPtrT> tmp308;
  TNode<IntPtrT> tmp309;
  TNode<IntPtrT> tmp310;
  TNode<BoolT> tmp311;
  if (block186.is_used()) {
    ca_.Bind(&block186, &phi_bb186_17, &phi_bb186_18, &phi_bb186_19, &phi_bb186_26, &phi_bb186_28, &phi_bb186_29, &phi_bb186_30, &phi_bb186_32, &phi_bb186_33, &phi_bb186_34, &phi_bb186_35, &phi_bb186_37);
    std::tie(tmp305, tmp306) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb186_30}).Flatten();
    tmp307 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp308 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb186_30}, TNode<IntPtrT>{tmp307});
    tmp309 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp310 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp308}, TNode<IntPtrT>{tmp309});
    tmp311 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block181, phi_bb186_17, phi_bb186_18, phi_bb186_19, phi_bb186_26, phi_bb186_28, phi_bb186_29, tmp310, tmp308, tmp311, phi_bb186_34, phi_bb186_35, phi_bb186_37, tmp305, tmp306);
  }

  TNode<Object> phi_bb181_17;
  TNode<IntPtrT> phi_bb181_18;
  TNode<BoolT> phi_bb181_19;
  TNode<IntPtrT> phi_bb181_26;
  TNode<IntPtrT> phi_bb181_28;
  TNode<IntPtrT> phi_bb181_29;
  TNode<IntPtrT> phi_bb181_30;
  TNode<IntPtrT> phi_bb181_32;
  TNode<BoolT> phi_bb181_33;
  TNode<BoolT> phi_bb181_34;
  TNode<Object> phi_bb181_35;
  TNode<Int32T> phi_bb181_37;
  TNode<Object> phi_bb181_40;
  TNode<IntPtrT> phi_bb181_41;
  if (block181.is_used()) {
    ca_.Bind(&block181, &phi_bb181_17, &phi_bb181_18, &phi_bb181_19, &phi_bb181_26, &phi_bb181_28, &phi_bb181_29, &phi_bb181_30, &phi_bb181_32, &phi_bb181_33, &phi_bb181_34, &phi_bb181_35, &phi_bb181_37, &phi_bb181_40, &phi_bb181_41);
    ca_.Goto(&block175, phi_bb181_17, phi_bb181_18, phi_bb181_19, phi_bb181_26, phi_bb181_28, phi_bb181_29, phi_bb181_30, phi_bb181_32, phi_bb181_33, phi_bb181_34, phi_bb181_35, phi_bb181_37, phi_bb181_40, phi_bb181_41);
  }

  TNode<Object> phi_bb179_17;
  TNode<IntPtrT> phi_bb179_18;
  TNode<BoolT> phi_bb179_19;
  TNode<IntPtrT> phi_bb179_26;
  TNode<IntPtrT> phi_bb179_28;
  TNode<IntPtrT> phi_bb179_29;
  TNode<IntPtrT> phi_bb179_30;
  TNode<IntPtrT> phi_bb179_32;
  TNode<BoolT> phi_bb179_33;
  TNode<BoolT> phi_bb179_34;
  TNode<Object> phi_bb179_35;
  TNode<Int32T> phi_bb179_37;
  TNode<Object> tmp312;
  TNode<IntPtrT> tmp313;
  TNode<IntPtrT> tmp314;
  TNode<IntPtrT> tmp315;
  TNode<BoolT> tmp316;
  if (block179.is_used()) {
    ca_.Bind(&block179, &phi_bb179_17, &phi_bb179_18, &phi_bb179_19, &phi_bb179_26, &phi_bb179_28, &phi_bb179_29, &phi_bb179_30, &phi_bb179_32, &phi_bb179_33, &phi_bb179_34, &phi_bb179_35, &phi_bb179_37);
    std::tie(tmp312, tmp313) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb179_30}).Flatten();
    tmp314 = FromConstexpr_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Mul((FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull))), (SizeOf_intptr_0(state_)))));
    tmp315 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb179_30}, TNode<IntPtrT>{tmp314});
    tmp316 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block175, phi_bb179_17, phi_bb179_18, phi_bb179_19, phi_bb179_26, phi_bb179_28, phi_bb179_29, tmp315, phi_bb179_32, tmp316, phi_bb179_34, phi_bb179_35, phi_bb179_37, tmp312, tmp313);
  }

  TNode<Object> phi_bb175_17;
  TNode<IntPtrT> phi_bb175_18;
  TNode<BoolT> phi_bb175_19;
  TNode<IntPtrT> phi_bb175_26;
  TNode<IntPtrT> phi_bb175_28;
  TNode<IntPtrT> phi_bb175_29;
  TNode<IntPtrT> phi_bb175_30;
  TNode<IntPtrT> phi_bb175_32;
  TNode<BoolT> phi_bb175_33;
  TNode<BoolT> phi_bb175_34;
  TNode<Object> phi_bb175_35;
  TNode<Int32T> phi_bb175_37;
  TNode<Object> phi_bb175_40;
  TNode<IntPtrT> phi_bb175_41;
  TNode<Object> tmp317;
  TNode<IntPtrT> tmp318;
  TNode<Float64T> tmp319;
  TNode<Float64T> tmp320;
  if (block175.is_used()) {
    ca_.Bind(&block175, &phi_bb175_17, &phi_bb175_18, &phi_bb175_19, &phi_bb175_26, &phi_bb175_28, &phi_bb175_29, &phi_bb175_30, &phi_bb175_32, &phi_bb175_33, &phi_bb175_34, &phi_bb175_35, &phi_bb175_37, &phi_bb175_40, &phi_bb175_41);
    std::tie(tmp317, tmp318) = RefCast_float64_0(state_, TorqueStructReference_intptr_0{TNode<Object>{phi_bb175_40}, TNode<IntPtrT>{phi_bb175_41}, TorqueStructUnsafe_0{}}).Flatten();
    tmp319 = CodeStubAssembler(state_).ChangeTaggedToFloat64(TNode<Context>{p_context}, TNode<Object>{tmp213});
    tmp320 = CodeStubAssembler(state_).Float64SilenceNaN(TNode<Float64T>{tmp319});
    CodeStubAssembler(state_).StoreReference<Float64T>(CodeStubAssembler::Reference{tmp317, tmp318}, tmp320);
    ca_.Goto(&block174, phi_bb175_17, phi_bb175_18, phi_bb175_19, phi_bb175_26, tmp288, phi_bb175_28, phi_bb175_29, phi_bb175_30, phi_bb175_32, phi_bb175_33, phi_bb175_34, phi_bb175_35, phi_bb175_37);
  }

  TNode<Object> phi_bb173_17;
  TNode<IntPtrT> phi_bb173_18;
  TNode<BoolT> phi_bb173_19;
  TNode<IntPtrT> phi_bb173_26;
  TNode<IntPtrT> phi_bb173_27;
  TNode<IntPtrT> phi_bb173_28;
  TNode<IntPtrT> phi_bb173_29;
  TNode<IntPtrT> phi_bb173_30;
  TNode<IntPtrT> phi_bb173_32;
  TNode<BoolT> phi_bb173_33;
  TNode<BoolT> phi_bb173_34;
  TNode<Object> phi_bb173_35;
  TNode<Int32T> phi_bb173_37;
  TNode<Int32T> tmp321;
  TNode<BoolT> tmp322;
  if (block173.is_used()) {
    ca_.Bind(&block173, &phi_bb173_17, &phi_bb173_18, &phi_bb173_19, &phi_bb173_26, &phi_bb173_27, &phi_bb173_28, &phi_bb173_29, &phi_bb173_30, &phi_bb173_32, &phi_bb173_33, &phi_bb173_34, &phi_bb173_35, &phi_bb173_37);
    tmp321 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI64.raw_bit_field());
    tmp322 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp221}, TNode<Int32T>{tmp321});
    ca_.Branch(tmp322, &block187, std::vector<compiler::Node*>{phi_bb173_17, phi_bb173_18, phi_bb173_19, phi_bb173_26, phi_bb173_27, phi_bb173_28, phi_bb173_29, phi_bb173_30, phi_bb173_32, phi_bb173_33, phi_bb173_34, phi_bb173_35, phi_bb173_37}, &block188, std::vector<compiler::Node*>{phi_bb173_17, phi_bb173_18, phi_bb173_19, phi_bb173_26, phi_bb173_27, phi_bb173_28, phi_bb173_29, phi_bb173_30, phi_bb173_32, phi_bb173_33, phi_bb173_34, phi_bb173_35, phi_bb173_37});
  }

  TNode<Object> phi_bb187_17;
  TNode<IntPtrT> phi_bb187_18;
  TNode<BoolT> phi_bb187_19;
  TNode<IntPtrT> phi_bb187_26;
  TNode<IntPtrT> phi_bb187_27;
  TNode<IntPtrT> phi_bb187_28;
  TNode<IntPtrT> phi_bb187_29;
  TNode<IntPtrT> phi_bb187_30;
  TNode<IntPtrT> phi_bb187_32;
  TNode<BoolT> phi_bb187_33;
  TNode<BoolT> phi_bb187_34;
  TNode<Object> phi_bb187_35;
  TNode<Int32T> phi_bb187_37;
  if (block187.is_used()) {
    ca_.Bind(&block187, &phi_bb187_17, &phi_bb187_18, &phi_bb187_19, &phi_bb187_26, &phi_bb187_27, &phi_bb187_28, &phi_bb187_29, &phi_bb187_30, &phi_bb187_32, &phi_bb187_33, &phi_bb187_34, &phi_bb187_35, &phi_bb187_37);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block190, phi_bb187_17, phi_bb187_18, phi_bb187_19, phi_bb187_26, phi_bb187_27, phi_bb187_28, phi_bb187_29, phi_bb187_30, phi_bb187_32, phi_bb187_33, phi_bb187_34, phi_bb187_35, phi_bb187_37);
    } else {
      ca_.Goto(&block191, phi_bb187_17, phi_bb187_18, phi_bb187_19, phi_bb187_26, phi_bb187_27, phi_bb187_28, phi_bb187_29, phi_bb187_30, phi_bb187_32, phi_bb187_33, phi_bb187_34, phi_bb187_35, phi_bb187_37);
    }
  }

  TNode<Object> phi_bb190_17;
  TNode<IntPtrT> phi_bb190_18;
  TNode<BoolT> phi_bb190_19;
  TNode<IntPtrT> phi_bb190_26;
  TNode<IntPtrT> phi_bb190_27;
  TNode<IntPtrT> phi_bb190_28;
  TNode<IntPtrT> phi_bb190_29;
  TNode<IntPtrT> phi_bb190_30;
  TNode<IntPtrT> phi_bb190_32;
  TNode<BoolT> phi_bb190_33;
  TNode<BoolT> phi_bb190_34;
  TNode<Object> phi_bb190_35;
  TNode<Int32T> phi_bb190_37;
  TNode<IntPtrT> tmp323;
  TNode<IntPtrT> tmp324;
  TNode<IntPtrT> tmp325;
  TNode<BoolT> tmp326;
  if (block190.is_used()) {
    ca_.Bind(&block190, &phi_bb190_17, &phi_bb190_18, &phi_bb190_19, &phi_bb190_26, &phi_bb190_27, &phi_bb190_28, &phi_bb190_29, &phi_bb190_30, &phi_bb190_32, &phi_bb190_33, &phi_bb190_34, &phi_bb190_35, &phi_bb190_37);
    tmp323 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp324 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb190_26}, TNode<IntPtrT>{tmp323});
    tmp325 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp326 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb190_26}, TNode<IntPtrT>{tmp325});
    ca_.Branch(tmp326, &block194, std::vector<compiler::Node*>{phi_bb190_17, phi_bb190_18, phi_bb190_19, phi_bb190_27, phi_bb190_28, phi_bb190_29, phi_bb190_30, phi_bb190_32, phi_bb190_33, phi_bb190_34, phi_bb190_35, phi_bb190_37}, &block195, std::vector<compiler::Node*>{phi_bb190_17, phi_bb190_18, phi_bb190_19, phi_bb190_27, phi_bb190_28, phi_bb190_29, phi_bb190_30, phi_bb190_32, phi_bb190_33, phi_bb190_34, phi_bb190_35, phi_bb190_37});
  }

  TNode<Object> phi_bb194_17;
  TNode<IntPtrT> phi_bb194_18;
  TNode<BoolT> phi_bb194_19;
  TNode<IntPtrT> phi_bb194_27;
  TNode<IntPtrT> phi_bb194_28;
  TNode<IntPtrT> phi_bb194_29;
  TNode<IntPtrT> phi_bb194_30;
  TNode<IntPtrT> phi_bb194_32;
  TNode<BoolT> phi_bb194_33;
  TNode<BoolT> phi_bb194_34;
  TNode<Object> phi_bb194_35;
  TNode<Int32T> phi_bb194_37;
  TNode<Object> tmp327;
  TNode<IntPtrT> tmp328;
  TNode<IntPtrT> tmp329;
  TNode<IntPtrT> tmp330;
  if (block194.is_used()) {
    ca_.Bind(&block194, &phi_bb194_17, &phi_bb194_18, &phi_bb194_19, &phi_bb194_27, &phi_bb194_28, &phi_bb194_29, &phi_bb194_30, &phi_bb194_32, &phi_bb194_33, &phi_bb194_34, &phi_bb194_35, &phi_bb194_37);
    std::tie(tmp327, tmp328) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb194_28}).Flatten();
    tmp329 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp330 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb194_28}, TNode<IntPtrT>{tmp329});
    ca_.Goto(&block193, phi_bb194_17, phi_bb194_18, phi_bb194_19, phi_bb194_27, tmp330, phi_bb194_29, phi_bb194_30, phi_bb194_32, phi_bb194_33, phi_bb194_34, phi_bb194_35, phi_bb194_37, tmp327, tmp328);
  }

  TNode<Object> phi_bb195_17;
  TNode<IntPtrT> phi_bb195_18;
  TNode<BoolT> phi_bb195_19;
  TNode<IntPtrT> phi_bb195_27;
  TNode<IntPtrT> phi_bb195_28;
  TNode<IntPtrT> phi_bb195_29;
  TNode<IntPtrT> phi_bb195_30;
  TNode<IntPtrT> phi_bb195_32;
  TNode<BoolT> phi_bb195_33;
  TNode<BoolT> phi_bb195_34;
  TNode<Object> phi_bb195_35;
  TNode<Int32T> phi_bb195_37;
  if (block195.is_used()) {
    ca_.Bind(&block195, &phi_bb195_17, &phi_bb195_18, &phi_bb195_19, &phi_bb195_27, &phi_bb195_28, &phi_bb195_29, &phi_bb195_30, &phi_bb195_32, &phi_bb195_33, &phi_bb195_34, &phi_bb195_35, &phi_bb195_37);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block197, phi_bb195_17, phi_bb195_18, phi_bb195_19, phi_bb195_27, phi_bb195_28, phi_bb195_29, phi_bb195_30, phi_bb195_32, phi_bb195_33, phi_bb195_34, phi_bb195_35, phi_bb195_37);
    } else {
      ca_.Goto(&block198, phi_bb195_17, phi_bb195_18, phi_bb195_19, phi_bb195_27, phi_bb195_28, phi_bb195_29, phi_bb195_30, phi_bb195_32, phi_bb195_33, phi_bb195_34, phi_bb195_35, phi_bb195_37);
    }
  }

  TNode<Object> phi_bb197_17;
  TNode<IntPtrT> phi_bb197_18;
  TNode<BoolT> phi_bb197_19;
  TNode<IntPtrT> phi_bb197_27;
  TNode<IntPtrT> phi_bb197_28;
  TNode<IntPtrT> phi_bb197_29;
  TNode<IntPtrT> phi_bb197_30;
  TNode<IntPtrT> phi_bb197_32;
  TNode<BoolT> phi_bb197_33;
  TNode<BoolT> phi_bb197_34;
  TNode<Object> phi_bb197_35;
  TNode<Int32T> phi_bb197_37;
  TNode<Object> tmp331;
  TNode<IntPtrT> tmp332;
  TNode<IntPtrT> tmp333;
  TNode<IntPtrT> tmp334;
  if (block197.is_used()) {
    ca_.Bind(&block197, &phi_bb197_17, &phi_bb197_18, &phi_bb197_19, &phi_bb197_27, &phi_bb197_28, &phi_bb197_29, &phi_bb197_30, &phi_bb197_32, &phi_bb197_33, &phi_bb197_34, &phi_bb197_35, &phi_bb197_37);
    std::tie(tmp331, tmp332) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb197_30}).Flatten();
    tmp333 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp334 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb197_30}, TNode<IntPtrT>{tmp333});
    ca_.Goto(&block196, phi_bb197_17, phi_bb197_18, phi_bb197_19, phi_bb197_27, phi_bb197_28, phi_bb197_29, tmp334, phi_bb197_32, phi_bb197_33, phi_bb197_34, phi_bb197_35, phi_bb197_37, tmp331, tmp332);
  }

  TNode<Object> phi_bb198_17;
  TNode<IntPtrT> phi_bb198_18;
  TNode<BoolT> phi_bb198_19;
  TNode<IntPtrT> phi_bb198_27;
  TNode<IntPtrT> phi_bb198_28;
  TNode<IntPtrT> phi_bb198_29;
  TNode<IntPtrT> phi_bb198_30;
  TNode<IntPtrT> phi_bb198_32;
  TNode<BoolT> phi_bb198_33;
  TNode<BoolT> phi_bb198_34;
  TNode<Object> phi_bb198_35;
  TNode<Int32T> phi_bb198_37;
  TNode<IntPtrT> tmp335;
  TNode<BoolT> tmp336;
  if (block198.is_used()) {
    ca_.Bind(&block198, &phi_bb198_17, &phi_bb198_18, &phi_bb198_19, &phi_bb198_27, &phi_bb198_28, &phi_bb198_29, &phi_bb198_30, &phi_bb198_32, &phi_bb198_33, &phi_bb198_34, &phi_bb198_35, &phi_bb198_37);
    tmp335 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp336 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb198_32}, TNode<IntPtrT>{tmp335});
    ca_.Branch(tmp336, &block200, std::vector<compiler::Node*>{phi_bb198_17, phi_bb198_18, phi_bb198_19, phi_bb198_27, phi_bb198_28, phi_bb198_29, phi_bb198_30, phi_bb198_32, phi_bb198_33, phi_bb198_34, phi_bb198_35, phi_bb198_37}, &block201, std::vector<compiler::Node*>{phi_bb198_17, phi_bb198_18, phi_bb198_19, phi_bb198_27, phi_bb198_28, phi_bb198_29, phi_bb198_30, phi_bb198_32, phi_bb198_33, phi_bb198_34, phi_bb198_35, phi_bb198_37});
  }

  TNode<Object> phi_bb200_17;
  TNode<IntPtrT> phi_bb200_18;
  TNode<BoolT> phi_bb200_19;
  TNode<IntPtrT> phi_bb200_27;
  TNode<IntPtrT> phi_bb200_28;
  TNode<IntPtrT> phi_bb200_29;
  TNode<IntPtrT> phi_bb200_30;
  TNode<IntPtrT> phi_bb200_32;
  TNode<BoolT> phi_bb200_33;
  TNode<BoolT> phi_bb200_34;
  TNode<Object> phi_bb200_35;
  TNode<Int32T> phi_bb200_37;
  TNode<Object> tmp337;
  TNode<IntPtrT> tmp338;
  TNode<IntPtrT> tmp339;
  TNode<BoolT> tmp340;
  if (block200.is_used()) {
    ca_.Bind(&block200, &phi_bb200_17, &phi_bb200_18, &phi_bb200_19, &phi_bb200_27, &phi_bb200_28, &phi_bb200_29, &phi_bb200_30, &phi_bb200_32, &phi_bb200_33, &phi_bb200_34, &phi_bb200_35, &phi_bb200_37);
    std::tie(tmp337, tmp338) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb200_32}).Flatten();
    tmp339 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp340 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block196, phi_bb200_17, phi_bb200_18, phi_bb200_19, phi_bb200_27, phi_bb200_28, phi_bb200_29, phi_bb200_30, tmp339, tmp340, phi_bb200_34, phi_bb200_35, phi_bb200_37, tmp337, tmp338);
  }

  TNode<Object> phi_bb201_17;
  TNode<IntPtrT> phi_bb201_18;
  TNode<BoolT> phi_bb201_19;
  TNode<IntPtrT> phi_bb201_27;
  TNode<IntPtrT> phi_bb201_28;
  TNode<IntPtrT> phi_bb201_29;
  TNode<IntPtrT> phi_bb201_30;
  TNode<IntPtrT> phi_bb201_32;
  TNode<BoolT> phi_bb201_33;
  TNode<BoolT> phi_bb201_34;
  TNode<Object> phi_bb201_35;
  TNode<Int32T> phi_bb201_37;
  TNode<Object> tmp341;
  TNode<IntPtrT> tmp342;
  TNode<IntPtrT> tmp343;
  TNode<IntPtrT> tmp344;
  TNode<IntPtrT> tmp345;
  TNode<IntPtrT> tmp346;
  TNode<BoolT> tmp347;
  if (block201.is_used()) {
    ca_.Bind(&block201, &phi_bb201_17, &phi_bb201_18, &phi_bb201_19, &phi_bb201_27, &phi_bb201_28, &phi_bb201_29, &phi_bb201_30, &phi_bb201_32, &phi_bb201_33, &phi_bb201_34, &phi_bb201_35, &phi_bb201_37);
    std::tie(tmp341, tmp342) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb201_30}).Flatten();
    tmp343 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp344 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb201_30}, TNode<IntPtrT>{tmp343});
    tmp345 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp346 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp344}, TNode<IntPtrT>{tmp345});
    tmp347 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block196, phi_bb201_17, phi_bb201_18, phi_bb201_19, phi_bb201_27, phi_bb201_28, phi_bb201_29, tmp346, tmp344, tmp347, phi_bb201_34, phi_bb201_35, phi_bb201_37, tmp341, tmp342);
  }

  TNode<Object> phi_bb196_17;
  TNode<IntPtrT> phi_bb196_18;
  TNode<BoolT> phi_bb196_19;
  TNode<IntPtrT> phi_bb196_27;
  TNode<IntPtrT> phi_bb196_28;
  TNode<IntPtrT> phi_bb196_29;
  TNode<IntPtrT> phi_bb196_30;
  TNode<IntPtrT> phi_bb196_32;
  TNode<BoolT> phi_bb196_33;
  TNode<BoolT> phi_bb196_34;
  TNode<Object> phi_bb196_35;
  TNode<Int32T> phi_bb196_37;
  TNode<Object> phi_bb196_40;
  TNode<IntPtrT> phi_bb196_41;
  if (block196.is_used()) {
    ca_.Bind(&block196, &phi_bb196_17, &phi_bb196_18, &phi_bb196_19, &phi_bb196_27, &phi_bb196_28, &phi_bb196_29, &phi_bb196_30, &phi_bb196_32, &phi_bb196_33, &phi_bb196_34, &phi_bb196_35, &phi_bb196_37, &phi_bb196_40, &phi_bb196_41);
    ca_.Goto(&block193, phi_bb196_17, phi_bb196_18, phi_bb196_19, phi_bb196_27, phi_bb196_28, phi_bb196_29, phi_bb196_30, phi_bb196_32, phi_bb196_33, phi_bb196_34, phi_bb196_35, phi_bb196_37, phi_bb196_40, phi_bb196_41);
  }

  TNode<Object> phi_bb193_17;
  TNode<IntPtrT> phi_bb193_18;
  TNode<BoolT> phi_bb193_19;
  TNode<IntPtrT> phi_bb193_27;
  TNode<IntPtrT> phi_bb193_28;
  TNode<IntPtrT> phi_bb193_29;
  TNode<IntPtrT> phi_bb193_30;
  TNode<IntPtrT> phi_bb193_32;
  TNode<BoolT> phi_bb193_33;
  TNode<BoolT> phi_bb193_34;
  TNode<Object> phi_bb193_35;
  TNode<Int32T> phi_bb193_37;
  TNode<Object> phi_bb193_40;
  TNode<IntPtrT> phi_bb193_41;
  TNode<IntPtrT> tmp348;
  if (block193.is_used()) {
    ca_.Bind(&block193, &phi_bb193_17, &phi_bb193_18, &phi_bb193_19, &phi_bb193_27, &phi_bb193_28, &phi_bb193_29, &phi_bb193_30, &phi_bb193_32, &phi_bb193_33, &phi_bb193_34, &phi_bb193_35, &phi_bb193_37, &phi_bb193_40, &phi_bb193_41);
    tmp348 = TruncateBigIntToI64_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp213});
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb193_40, phi_bb193_41}, tmp348);
    ca_.Goto(&block192, phi_bb193_17, phi_bb193_18, phi_bb193_19, tmp324, phi_bb193_27, phi_bb193_28, phi_bb193_29, phi_bb193_30, phi_bb193_32, phi_bb193_33, phi_bb193_34, phi_bb193_35, phi_bb193_37);
  }

  TNode<Object> phi_bb191_17;
  TNode<IntPtrT> phi_bb191_18;
  TNode<BoolT> phi_bb191_19;
  TNode<IntPtrT> phi_bb191_26;
  TNode<IntPtrT> phi_bb191_27;
  TNode<IntPtrT> phi_bb191_28;
  TNode<IntPtrT> phi_bb191_29;
  TNode<IntPtrT> phi_bb191_30;
  TNode<IntPtrT> phi_bb191_32;
  TNode<BoolT> phi_bb191_33;
  TNode<BoolT> phi_bb191_34;
  TNode<Object> phi_bb191_35;
  TNode<Int32T> phi_bb191_37;
  TNode<IntPtrT> tmp349;
  TNode<IntPtrT> tmp350;
  TNode<IntPtrT> tmp351;
  TNode<BoolT> tmp352;
  if (block191.is_used()) {
    ca_.Bind(&block191, &phi_bb191_17, &phi_bb191_18, &phi_bb191_19, &phi_bb191_26, &phi_bb191_27, &phi_bb191_28, &phi_bb191_29, &phi_bb191_30, &phi_bb191_32, &phi_bb191_33, &phi_bb191_34, &phi_bb191_35, &phi_bb191_37);
    tmp349 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp350 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb191_26}, TNode<IntPtrT>{tmp349});
    tmp351 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp352 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb191_26}, TNode<IntPtrT>{tmp351});
    ca_.Branch(tmp352, &block203, std::vector<compiler::Node*>{phi_bb191_17, phi_bb191_18, phi_bb191_19, phi_bb191_27, phi_bb191_28, phi_bb191_29, phi_bb191_30, phi_bb191_32, phi_bb191_33, phi_bb191_34, phi_bb191_35, phi_bb191_37}, &block204, std::vector<compiler::Node*>{phi_bb191_17, phi_bb191_18, phi_bb191_19, phi_bb191_27, phi_bb191_28, phi_bb191_29, phi_bb191_30, phi_bb191_32, phi_bb191_33, phi_bb191_34, phi_bb191_35, phi_bb191_37});
  }

  TNode<Object> phi_bb203_17;
  TNode<IntPtrT> phi_bb203_18;
  TNode<BoolT> phi_bb203_19;
  TNode<IntPtrT> phi_bb203_27;
  TNode<IntPtrT> phi_bb203_28;
  TNode<IntPtrT> phi_bb203_29;
  TNode<IntPtrT> phi_bb203_30;
  TNode<IntPtrT> phi_bb203_32;
  TNode<BoolT> phi_bb203_33;
  TNode<BoolT> phi_bb203_34;
  TNode<Object> phi_bb203_35;
  TNode<Int32T> phi_bb203_37;
  TNode<Object> tmp353;
  TNode<IntPtrT> tmp354;
  TNode<IntPtrT> tmp355;
  TNode<IntPtrT> tmp356;
  if (block203.is_used()) {
    ca_.Bind(&block203, &phi_bb203_17, &phi_bb203_18, &phi_bb203_19, &phi_bb203_27, &phi_bb203_28, &phi_bb203_29, &phi_bb203_30, &phi_bb203_32, &phi_bb203_33, &phi_bb203_34, &phi_bb203_35, &phi_bb203_37);
    std::tie(tmp353, tmp354) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb203_28}).Flatten();
    tmp355 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp356 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb203_28}, TNode<IntPtrT>{tmp355});
    ca_.Goto(&block202, phi_bb203_17, phi_bb203_18, phi_bb203_19, phi_bb203_27, tmp356, phi_bb203_29, phi_bb203_30, phi_bb203_32, phi_bb203_33, phi_bb203_34, phi_bb203_35, phi_bb203_37, tmp353, tmp354);
  }

  TNode<Object> phi_bb204_17;
  TNode<IntPtrT> phi_bb204_18;
  TNode<BoolT> phi_bb204_19;
  TNode<IntPtrT> phi_bb204_27;
  TNode<IntPtrT> phi_bb204_28;
  TNode<IntPtrT> phi_bb204_29;
  TNode<IntPtrT> phi_bb204_30;
  TNode<IntPtrT> phi_bb204_32;
  TNode<BoolT> phi_bb204_33;
  TNode<BoolT> phi_bb204_34;
  TNode<Object> phi_bb204_35;
  TNode<Int32T> phi_bb204_37;
  if (block204.is_used()) {
    ca_.Bind(&block204, &phi_bb204_17, &phi_bb204_18, &phi_bb204_19, &phi_bb204_27, &phi_bb204_28, &phi_bb204_29, &phi_bb204_30, &phi_bb204_32, &phi_bb204_33, &phi_bb204_34, &phi_bb204_35, &phi_bb204_37);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block206, phi_bb204_17, phi_bb204_18, phi_bb204_19, phi_bb204_27, phi_bb204_28, phi_bb204_29, phi_bb204_30, phi_bb204_32, phi_bb204_33, phi_bb204_34, phi_bb204_35, phi_bb204_37);
    } else {
      ca_.Goto(&block207, phi_bb204_17, phi_bb204_18, phi_bb204_19, phi_bb204_27, phi_bb204_28, phi_bb204_29, phi_bb204_30, phi_bb204_32, phi_bb204_33, phi_bb204_34, phi_bb204_35, phi_bb204_37);
    }
  }

  TNode<Object> phi_bb206_17;
  TNode<IntPtrT> phi_bb206_18;
  TNode<BoolT> phi_bb206_19;
  TNode<IntPtrT> phi_bb206_27;
  TNode<IntPtrT> phi_bb206_28;
  TNode<IntPtrT> phi_bb206_29;
  TNode<IntPtrT> phi_bb206_30;
  TNode<IntPtrT> phi_bb206_32;
  TNode<BoolT> phi_bb206_33;
  TNode<BoolT> phi_bb206_34;
  TNode<Object> phi_bb206_35;
  TNode<Int32T> phi_bb206_37;
  TNode<Object> tmp357;
  TNode<IntPtrT> tmp358;
  TNode<IntPtrT> tmp359;
  TNode<IntPtrT> tmp360;
  if (block206.is_used()) {
    ca_.Bind(&block206, &phi_bb206_17, &phi_bb206_18, &phi_bb206_19, &phi_bb206_27, &phi_bb206_28, &phi_bb206_29, &phi_bb206_30, &phi_bb206_32, &phi_bb206_33, &phi_bb206_34, &phi_bb206_35, &phi_bb206_37);
    std::tie(tmp357, tmp358) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb206_30}).Flatten();
    tmp359 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp360 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb206_30}, TNode<IntPtrT>{tmp359});
    ca_.Goto(&block205, phi_bb206_17, phi_bb206_18, phi_bb206_19, phi_bb206_27, phi_bb206_28, phi_bb206_29, tmp360, phi_bb206_32, phi_bb206_33, phi_bb206_34, phi_bb206_35, phi_bb206_37, tmp357, tmp358);
  }

  TNode<Object> phi_bb207_17;
  TNode<IntPtrT> phi_bb207_18;
  TNode<BoolT> phi_bb207_19;
  TNode<IntPtrT> phi_bb207_27;
  TNode<IntPtrT> phi_bb207_28;
  TNode<IntPtrT> phi_bb207_29;
  TNode<IntPtrT> phi_bb207_30;
  TNode<IntPtrT> phi_bb207_32;
  TNode<BoolT> phi_bb207_33;
  TNode<BoolT> phi_bb207_34;
  TNode<Object> phi_bb207_35;
  TNode<Int32T> phi_bb207_37;
  TNode<IntPtrT> tmp361;
  TNode<BoolT> tmp362;
  if (block207.is_used()) {
    ca_.Bind(&block207, &phi_bb207_17, &phi_bb207_18, &phi_bb207_19, &phi_bb207_27, &phi_bb207_28, &phi_bb207_29, &phi_bb207_30, &phi_bb207_32, &phi_bb207_33, &phi_bb207_34, &phi_bb207_35, &phi_bb207_37);
    tmp361 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp362 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb207_32}, TNode<IntPtrT>{tmp361});
    ca_.Branch(tmp362, &block209, std::vector<compiler::Node*>{phi_bb207_17, phi_bb207_18, phi_bb207_19, phi_bb207_27, phi_bb207_28, phi_bb207_29, phi_bb207_30, phi_bb207_32, phi_bb207_33, phi_bb207_34, phi_bb207_35, phi_bb207_37}, &block210, std::vector<compiler::Node*>{phi_bb207_17, phi_bb207_18, phi_bb207_19, phi_bb207_27, phi_bb207_28, phi_bb207_29, phi_bb207_30, phi_bb207_32, phi_bb207_33, phi_bb207_34, phi_bb207_35, phi_bb207_37});
  }

  TNode<Object> phi_bb209_17;
  TNode<IntPtrT> phi_bb209_18;
  TNode<BoolT> phi_bb209_19;
  TNode<IntPtrT> phi_bb209_27;
  TNode<IntPtrT> phi_bb209_28;
  TNode<IntPtrT> phi_bb209_29;
  TNode<IntPtrT> phi_bb209_30;
  TNode<IntPtrT> phi_bb209_32;
  TNode<BoolT> phi_bb209_33;
  TNode<BoolT> phi_bb209_34;
  TNode<Object> phi_bb209_35;
  TNode<Int32T> phi_bb209_37;
  TNode<Object> tmp363;
  TNode<IntPtrT> tmp364;
  TNode<IntPtrT> tmp365;
  TNode<BoolT> tmp366;
  if (block209.is_used()) {
    ca_.Bind(&block209, &phi_bb209_17, &phi_bb209_18, &phi_bb209_19, &phi_bb209_27, &phi_bb209_28, &phi_bb209_29, &phi_bb209_30, &phi_bb209_32, &phi_bb209_33, &phi_bb209_34, &phi_bb209_35, &phi_bb209_37);
    std::tie(tmp363, tmp364) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb209_32}).Flatten();
    tmp365 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp366 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block205, phi_bb209_17, phi_bb209_18, phi_bb209_19, phi_bb209_27, phi_bb209_28, phi_bb209_29, phi_bb209_30, tmp365, tmp366, phi_bb209_34, phi_bb209_35, phi_bb209_37, tmp363, tmp364);
  }

  TNode<Object> phi_bb210_17;
  TNode<IntPtrT> phi_bb210_18;
  TNode<BoolT> phi_bb210_19;
  TNode<IntPtrT> phi_bb210_27;
  TNode<IntPtrT> phi_bb210_28;
  TNode<IntPtrT> phi_bb210_29;
  TNode<IntPtrT> phi_bb210_30;
  TNode<IntPtrT> phi_bb210_32;
  TNode<BoolT> phi_bb210_33;
  TNode<BoolT> phi_bb210_34;
  TNode<Object> phi_bb210_35;
  TNode<Int32T> phi_bb210_37;
  TNode<Object> tmp367;
  TNode<IntPtrT> tmp368;
  TNode<IntPtrT> tmp369;
  TNode<IntPtrT> tmp370;
  TNode<IntPtrT> tmp371;
  TNode<IntPtrT> tmp372;
  TNode<BoolT> tmp373;
  if (block210.is_used()) {
    ca_.Bind(&block210, &phi_bb210_17, &phi_bb210_18, &phi_bb210_19, &phi_bb210_27, &phi_bb210_28, &phi_bb210_29, &phi_bb210_30, &phi_bb210_32, &phi_bb210_33, &phi_bb210_34, &phi_bb210_35, &phi_bb210_37);
    std::tie(tmp367, tmp368) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb210_30}).Flatten();
    tmp369 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp370 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb210_30}, TNode<IntPtrT>{tmp369});
    tmp371 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp372 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp370}, TNode<IntPtrT>{tmp371});
    tmp373 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block205, phi_bb210_17, phi_bb210_18, phi_bb210_19, phi_bb210_27, phi_bb210_28, phi_bb210_29, tmp372, tmp370, tmp373, phi_bb210_34, phi_bb210_35, phi_bb210_37, tmp367, tmp368);
  }

  TNode<Object> phi_bb205_17;
  TNode<IntPtrT> phi_bb205_18;
  TNode<BoolT> phi_bb205_19;
  TNode<IntPtrT> phi_bb205_27;
  TNode<IntPtrT> phi_bb205_28;
  TNode<IntPtrT> phi_bb205_29;
  TNode<IntPtrT> phi_bb205_30;
  TNode<IntPtrT> phi_bb205_32;
  TNode<BoolT> phi_bb205_33;
  TNode<BoolT> phi_bb205_34;
  TNode<Object> phi_bb205_35;
  TNode<Int32T> phi_bb205_37;
  TNode<Object> phi_bb205_40;
  TNode<IntPtrT> phi_bb205_41;
  if (block205.is_used()) {
    ca_.Bind(&block205, &phi_bb205_17, &phi_bb205_18, &phi_bb205_19, &phi_bb205_27, &phi_bb205_28, &phi_bb205_29, &phi_bb205_30, &phi_bb205_32, &phi_bb205_33, &phi_bb205_34, &phi_bb205_35, &phi_bb205_37, &phi_bb205_40, &phi_bb205_41);
    ca_.Goto(&block202, phi_bb205_17, phi_bb205_18, phi_bb205_19, phi_bb205_27, phi_bb205_28, phi_bb205_29, phi_bb205_30, phi_bb205_32, phi_bb205_33, phi_bb205_34, phi_bb205_35, phi_bb205_37, phi_bb205_40, phi_bb205_41);
  }

  TNode<Object> phi_bb202_17;
  TNode<IntPtrT> phi_bb202_18;
  TNode<BoolT> phi_bb202_19;
  TNode<IntPtrT> phi_bb202_27;
  TNode<IntPtrT> phi_bb202_28;
  TNode<IntPtrT> phi_bb202_29;
  TNode<IntPtrT> phi_bb202_30;
  TNode<IntPtrT> phi_bb202_32;
  TNode<BoolT> phi_bb202_33;
  TNode<BoolT> phi_bb202_34;
  TNode<Object> phi_bb202_35;
  TNode<Int32T> phi_bb202_37;
  TNode<Object> phi_bb202_40;
  TNode<IntPtrT> phi_bb202_41;
  TNode<IntPtrT> tmp374;
  TNode<IntPtrT> tmp375;
  TNode<IntPtrT> tmp376;
  TNode<BoolT> tmp377;
  if (block202.is_used()) {
    ca_.Bind(&block202, &phi_bb202_17, &phi_bb202_18, &phi_bb202_19, &phi_bb202_27, &phi_bb202_28, &phi_bb202_29, &phi_bb202_30, &phi_bb202_32, &phi_bb202_33, &phi_bb202_34, &phi_bb202_35, &phi_bb202_37, &phi_bb202_40, &phi_bb202_41);
    tmp374 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp375 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp350}, TNode<IntPtrT>{tmp374});
    tmp376 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp377 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp350}, TNode<IntPtrT>{tmp376});
    ca_.Branch(tmp377, &block212, std::vector<compiler::Node*>{phi_bb202_17, phi_bb202_18, phi_bb202_19, phi_bb202_27, phi_bb202_28, phi_bb202_29, phi_bb202_30, phi_bb202_32, phi_bb202_33, phi_bb202_34, phi_bb202_35, phi_bb202_37, phi_bb202_40, phi_bb202_41}, &block213, std::vector<compiler::Node*>{phi_bb202_17, phi_bb202_18, phi_bb202_19, phi_bb202_27, phi_bb202_28, phi_bb202_29, phi_bb202_30, phi_bb202_32, phi_bb202_33, phi_bb202_34, phi_bb202_35, phi_bb202_37, phi_bb202_40, phi_bb202_41});
  }

  TNode<Object> phi_bb212_17;
  TNode<IntPtrT> phi_bb212_18;
  TNode<BoolT> phi_bb212_19;
  TNode<IntPtrT> phi_bb212_27;
  TNode<IntPtrT> phi_bb212_28;
  TNode<IntPtrT> phi_bb212_29;
  TNode<IntPtrT> phi_bb212_30;
  TNode<IntPtrT> phi_bb212_32;
  TNode<BoolT> phi_bb212_33;
  TNode<BoolT> phi_bb212_34;
  TNode<Object> phi_bb212_35;
  TNode<Int32T> phi_bb212_37;
  TNode<Object> phi_bb212_40;
  TNode<IntPtrT> phi_bb212_41;
  TNode<Object> tmp378;
  TNode<IntPtrT> tmp379;
  TNode<IntPtrT> tmp380;
  TNode<IntPtrT> tmp381;
  if (block212.is_used()) {
    ca_.Bind(&block212, &phi_bb212_17, &phi_bb212_18, &phi_bb212_19, &phi_bb212_27, &phi_bb212_28, &phi_bb212_29, &phi_bb212_30, &phi_bb212_32, &phi_bb212_33, &phi_bb212_34, &phi_bb212_35, &phi_bb212_37, &phi_bb212_40, &phi_bb212_41);
    std::tie(tmp378, tmp379) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb212_28}).Flatten();
    tmp380 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp381 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb212_28}, TNode<IntPtrT>{tmp380});
    ca_.Goto(&block211, phi_bb212_17, phi_bb212_18, phi_bb212_19, phi_bb212_27, tmp381, phi_bb212_29, phi_bb212_30, phi_bb212_32, phi_bb212_33, phi_bb212_34, phi_bb212_35, phi_bb212_37, phi_bb212_40, phi_bb212_41, tmp378, tmp379);
  }

  TNode<Object> phi_bb213_17;
  TNode<IntPtrT> phi_bb213_18;
  TNode<BoolT> phi_bb213_19;
  TNode<IntPtrT> phi_bb213_27;
  TNode<IntPtrT> phi_bb213_28;
  TNode<IntPtrT> phi_bb213_29;
  TNode<IntPtrT> phi_bb213_30;
  TNode<IntPtrT> phi_bb213_32;
  TNode<BoolT> phi_bb213_33;
  TNode<BoolT> phi_bb213_34;
  TNode<Object> phi_bb213_35;
  TNode<Int32T> phi_bb213_37;
  TNode<Object> phi_bb213_40;
  TNode<IntPtrT> phi_bb213_41;
  if (block213.is_used()) {
    ca_.Bind(&block213, &phi_bb213_17, &phi_bb213_18, &phi_bb213_19, &phi_bb213_27, &phi_bb213_28, &phi_bb213_29, &phi_bb213_30, &phi_bb213_32, &phi_bb213_33, &phi_bb213_34, &phi_bb213_35, &phi_bb213_37, &phi_bb213_40, &phi_bb213_41);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block215, phi_bb213_17, phi_bb213_18, phi_bb213_19, phi_bb213_27, phi_bb213_28, phi_bb213_29, phi_bb213_30, phi_bb213_32, phi_bb213_33, phi_bb213_34, phi_bb213_35, phi_bb213_37, phi_bb213_40, phi_bb213_41);
    } else {
      ca_.Goto(&block216, phi_bb213_17, phi_bb213_18, phi_bb213_19, phi_bb213_27, phi_bb213_28, phi_bb213_29, phi_bb213_30, phi_bb213_32, phi_bb213_33, phi_bb213_34, phi_bb213_35, phi_bb213_37, phi_bb213_40, phi_bb213_41);
    }
  }

  TNode<Object> phi_bb215_17;
  TNode<IntPtrT> phi_bb215_18;
  TNode<BoolT> phi_bb215_19;
  TNode<IntPtrT> phi_bb215_27;
  TNode<IntPtrT> phi_bb215_28;
  TNode<IntPtrT> phi_bb215_29;
  TNode<IntPtrT> phi_bb215_30;
  TNode<IntPtrT> phi_bb215_32;
  TNode<BoolT> phi_bb215_33;
  TNode<BoolT> phi_bb215_34;
  TNode<Object> phi_bb215_35;
  TNode<Int32T> phi_bb215_37;
  TNode<Object> phi_bb215_40;
  TNode<IntPtrT> phi_bb215_41;
  TNode<Object> tmp382;
  TNode<IntPtrT> tmp383;
  TNode<IntPtrT> tmp384;
  TNode<IntPtrT> tmp385;
  if (block215.is_used()) {
    ca_.Bind(&block215, &phi_bb215_17, &phi_bb215_18, &phi_bb215_19, &phi_bb215_27, &phi_bb215_28, &phi_bb215_29, &phi_bb215_30, &phi_bb215_32, &phi_bb215_33, &phi_bb215_34, &phi_bb215_35, &phi_bb215_37, &phi_bb215_40, &phi_bb215_41);
    std::tie(tmp382, tmp383) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb215_30}).Flatten();
    tmp384 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp385 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb215_30}, TNode<IntPtrT>{tmp384});
    ca_.Goto(&block214, phi_bb215_17, phi_bb215_18, phi_bb215_19, phi_bb215_27, phi_bb215_28, phi_bb215_29, tmp385, phi_bb215_32, phi_bb215_33, phi_bb215_34, phi_bb215_35, phi_bb215_37, phi_bb215_40, phi_bb215_41, tmp382, tmp383);
  }

  TNode<Object> phi_bb216_17;
  TNode<IntPtrT> phi_bb216_18;
  TNode<BoolT> phi_bb216_19;
  TNode<IntPtrT> phi_bb216_27;
  TNode<IntPtrT> phi_bb216_28;
  TNode<IntPtrT> phi_bb216_29;
  TNode<IntPtrT> phi_bb216_30;
  TNode<IntPtrT> phi_bb216_32;
  TNode<BoolT> phi_bb216_33;
  TNode<BoolT> phi_bb216_34;
  TNode<Object> phi_bb216_35;
  TNode<Int32T> phi_bb216_37;
  TNode<Object> phi_bb216_40;
  TNode<IntPtrT> phi_bb216_41;
  TNode<IntPtrT> tmp386;
  TNode<BoolT> tmp387;
  if (block216.is_used()) {
    ca_.Bind(&block216, &phi_bb216_17, &phi_bb216_18, &phi_bb216_19, &phi_bb216_27, &phi_bb216_28, &phi_bb216_29, &phi_bb216_30, &phi_bb216_32, &phi_bb216_33, &phi_bb216_34, &phi_bb216_35, &phi_bb216_37, &phi_bb216_40, &phi_bb216_41);
    tmp386 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp387 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb216_32}, TNode<IntPtrT>{tmp386});
    ca_.Branch(tmp387, &block218, std::vector<compiler::Node*>{phi_bb216_17, phi_bb216_18, phi_bb216_19, phi_bb216_27, phi_bb216_28, phi_bb216_29, phi_bb216_30, phi_bb216_32, phi_bb216_33, phi_bb216_34, phi_bb216_35, phi_bb216_37, phi_bb216_40, phi_bb216_41}, &block219, std::vector<compiler::Node*>{phi_bb216_17, phi_bb216_18, phi_bb216_19, phi_bb216_27, phi_bb216_28, phi_bb216_29, phi_bb216_30, phi_bb216_32, phi_bb216_33, phi_bb216_34, phi_bb216_35, phi_bb216_37, phi_bb216_40, phi_bb216_41});
  }

  TNode<Object> phi_bb218_17;
  TNode<IntPtrT> phi_bb218_18;
  TNode<BoolT> phi_bb218_19;
  TNode<IntPtrT> phi_bb218_27;
  TNode<IntPtrT> phi_bb218_28;
  TNode<IntPtrT> phi_bb218_29;
  TNode<IntPtrT> phi_bb218_30;
  TNode<IntPtrT> phi_bb218_32;
  TNode<BoolT> phi_bb218_33;
  TNode<BoolT> phi_bb218_34;
  TNode<Object> phi_bb218_35;
  TNode<Int32T> phi_bb218_37;
  TNode<Object> phi_bb218_40;
  TNode<IntPtrT> phi_bb218_41;
  TNode<Object> tmp388;
  TNode<IntPtrT> tmp389;
  TNode<IntPtrT> tmp390;
  TNode<BoolT> tmp391;
  if (block218.is_used()) {
    ca_.Bind(&block218, &phi_bb218_17, &phi_bb218_18, &phi_bb218_19, &phi_bb218_27, &phi_bb218_28, &phi_bb218_29, &phi_bb218_30, &phi_bb218_32, &phi_bb218_33, &phi_bb218_34, &phi_bb218_35, &phi_bb218_37, &phi_bb218_40, &phi_bb218_41);
    std::tie(tmp388, tmp389) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb218_32}).Flatten();
    tmp390 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp391 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block214, phi_bb218_17, phi_bb218_18, phi_bb218_19, phi_bb218_27, phi_bb218_28, phi_bb218_29, phi_bb218_30, tmp390, tmp391, phi_bb218_34, phi_bb218_35, phi_bb218_37, phi_bb218_40, phi_bb218_41, tmp388, tmp389);
  }

  TNode<Object> phi_bb219_17;
  TNode<IntPtrT> phi_bb219_18;
  TNode<BoolT> phi_bb219_19;
  TNode<IntPtrT> phi_bb219_27;
  TNode<IntPtrT> phi_bb219_28;
  TNode<IntPtrT> phi_bb219_29;
  TNode<IntPtrT> phi_bb219_30;
  TNode<IntPtrT> phi_bb219_32;
  TNode<BoolT> phi_bb219_33;
  TNode<BoolT> phi_bb219_34;
  TNode<Object> phi_bb219_35;
  TNode<Int32T> phi_bb219_37;
  TNode<Object> phi_bb219_40;
  TNode<IntPtrT> phi_bb219_41;
  TNode<Object> tmp392;
  TNode<IntPtrT> tmp393;
  TNode<IntPtrT> tmp394;
  TNode<IntPtrT> tmp395;
  TNode<IntPtrT> tmp396;
  TNode<IntPtrT> tmp397;
  TNode<BoolT> tmp398;
  if (block219.is_used()) {
    ca_.Bind(&block219, &phi_bb219_17, &phi_bb219_18, &phi_bb219_19, &phi_bb219_27, &phi_bb219_28, &phi_bb219_29, &phi_bb219_30, &phi_bb219_32, &phi_bb219_33, &phi_bb219_34, &phi_bb219_35, &phi_bb219_37, &phi_bb219_40, &phi_bb219_41);
    std::tie(tmp392, tmp393) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb219_30}).Flatten();
    tmp394 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp395 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb219_30}, TNode<IntPtrT>{tmp394});
    tmp396 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp397 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp395}, TNode<IntPtrT>{tmp396});
    tmp398 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block214, phi_bb219_17, phi_bb219_18, phi_bb219_19, phi_bb219_27, phi_bb219_28, phi_bb219_29, tmp397, tmp395, tmp398, phi_bb219_34, phi_bb219_35, phi_bb219_37, phi_bb219_40, phi_bb219_41, tmp392, tmp393);
  }

  TNode<Object> phi_bb214_17;
  TNode<IntPtrT> phi_bb214_18;
  TNode<BoolT> phi_bb214_19;
  TNode<IntPtrT> phi_bb214_27;
  TNode<IntPtrT> phi_bb214_28;
  TNode<IntPtrT> phi_bb214_29;
  TNode<IntPtrT> phi_bb214_30;
  TNode<IntPtrT> phi_bb214_32;
  TNode<BoolT> phi_bb214_33;
  TNode<BoolT> phi_bb214_34;
  TNode<Object> phi_bb214_35;
  TNode<Int32T> phi_bb214_37;
  TNode<Object> phi_bb214_40;
  TNode<IntPtrT> phi_bb214_41;
  TNode<Object> phi_bb214_42;
  TNode<IntPtrT> phi_bb214_43;
  if (block214.is_used()) {
    ca_.Bind(&block214, &phi_bb214_17, &phi_bb214_18, &phi_bb214_19, &phi_bb214_27, &phi_bb214_28, &phi_bb214_29, &phi_bb214_30, &phi_bb214_32, &phi_bb214_33, &phi_bb214_34, &phi_bb214_35, &phi_bb214_37, &phi_bb214_40, &phi_bb214_41, &phi_bb214_42, &phi_bb214_43);
    ca_.Goto(&block211, phi_bb214_17, phi_bb214_18, phi_bb214_19, phi_bb214_27, phi_bb214_28, phi_bb214_29, phi_bb214_30, phi_bb214_32, phi_bb214_33, phi_bb214_34, phi_bb214_35, phi_bb214_37, phi_bb214_40, phi_bb214_41, phi_bb214_42, phi_bb214_43);
  }

  TNode<Object> phi_bb211_17;
  TNode<IntPtrT> phi_bb211_18;
  TNode<BoolT> phi_bb211_19;
  TNode<IntPtrT> phi_bb211_27;
  TNode<IntPtrT> phi_bb211_28;
  TNode<IntPtrT> phi_bb211_29;
  TNode<IntPtrT> phi_bb211_30;
  TNode<IntPtrT> phi_bb211_32;
  TNode<BoolT> phi_bb211_33;
  TNode<BoolT> phi_bb211_34;
  TNode<Object> phi_bb211_35;
  TNode<Int32T> phi_bb211_37;
  TNode<Object> phi_bb211_40;
  TNode<IntPtrT> phi_bb211_41;
  TNode<Object> phi_bb211_42;
  TNode<IntPtrT> phi_bb211_43;
  TNode<BigInt> tmp399;
  TNode<UintPtrT> tmp400;
  TNode<UintPtrT> tmp401;
  TNode<IntPtrT> tmp402;
  TNode<IntPtrT> tmp403;
  if (block211.is_used()) {
    ca_.Bind(&block211, &phi_bb211_17, &phi_bb211_18, &phi_bb211_19, &phi_bb211_27, &phi_bb211_28, &phi_bb211_29, &phi_bb211_30, &phi_bb211_32, &phi_bb211_33, &phi_bb211_34, &phi_bb211_35, &phi_bb211_37, &phi_bb211_40, &phi_bb211_41, &phi_bb211_42, &phi_bb211_43);
    tmp399 = CodeStubAssembler(state_).ToBigInt(TNode<Context>{p_context}, TNode<Object>{tmp213});
    std::tie(tmp400, tmp401) = CodeStubAssembler(state_).BigIntToRawBytes(TNode<BigInt>{tmp399}).Flatten();
    tmp402 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp400});
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb211_40, phi_bb211_41}, tmp402);
    tmp403 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp401});
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb211_42, phi_bb211_43}, tmp403);
    ca_.Goto(&block192, phi_bb211_17, phi_bb211_18, phi_bb211_19, tmp375, phi_bb211_27, phi_bb211_28, phi_bb211_29, phi_bb211_30, phi_bb211_32, phi_bb211_33, phi_bb211_34, phi_bb211_35, phi_bb211_37);
  }

  TNode<Object> phi_bb192_17;
  TNode<IntPtrT> phi_bb192_18;
  TNode<BoolT> phi_bb192_19;
  TNode<IntPtrT> phi_bb192_26;
  TNode<IntPtrT> phi_bb192_27;
  TNode<IntPtrT> phi_bb192_28;
  TNode<IntPtrT> phi_bb192_29;
  TNode<IntPtrT> phi_bb192_30;
  TNode<IntPtrT> phi_bb192_32;
  TNode<BoolT> phi_bb192_33;
  TNode<BoolT> phi_bb192_34;
  TNode<Object> phi_bb192_35;
  TNode<Int32T> phi_bb192_37;
  if (block192.is_used()) {
    ca_.Bind(&block192, &phi_bb192_17, &phi_bb192_18, &phi_bb192_19, &phi_bb192_26, &phi_bb192_27, &phi_bb192_28, &phi_bb192_29, &phi_bb192_30, &phi_bb192_32, &phi_bb192_33, &phi_bb192_34, &phi_bb192_35, &phi_bb192_37);
    ca_.Goto(&block189, phi_bb192_17, phi_bb192_18, phi_bb192_19, phi_bb192_26, phi_bb192_27, phi_bb192_28, phi_bb192_29, phi_bb192_30, phi_bb192_32, phi_bb192_33, phi_bb192_34, phi_bb192_35, phi_bb192_37);
  }

  TNode<Object> phi_bb188_17;
  TNode<IntPtrT> phi_bb188_18;
  TNode<BoolT> phi_bb188_19;
  TNode<IntPtrT> phi_bb188_26;
  TNode<IntPtrT> phi_bb188_27;
  TNode<IntPtrT> phi_bb188_28;
  TNode<IntPtrT> phi_bb188_29;
  TNode<IntPtrT> phi_bb188_30;
  TNode<IntPtrT> phi_bb188_32;
  TNode<BoolT> phi_bb188_33;
  TNode<BoolT> phi_bb188_34;
  TNode<Object> phi_bb188_35;
  TNode<Int32T> phi_bb188_37;
  TNode<Int32T> tmp404;
  TNode<Int32T> tmp405;
  TNode<BoolT> tmp406;
  TNode<BoolT> tmp407;
  if (block188.is_used()) {
    ca_.Bind(&block188, &phi_bb188_17, &phi_bb188_18, &phi_bb188_19, &phi_bb188_26, &phi_bb188_27, &phi_bb188_28, &phi_bb188_29, &phi_bb188_30, &phi_bb188_32, &phi_bb188_33, &phi_bb188_34, &phi_bb188_35, &phi_bb188_37);
    tmp404 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    tmp405 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp221}, TNode<Int32T>{tmp404});
    tmp406 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp407 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object>{phi_bb188_35});
    ca_.Branch(tmp407, &block227, std::vector<compiler::Node*>{phi_bb188_17, phi_bb188_18, phi_bb188_19, phi_bb188_26, phi_bb188_27, phi_bb188_28, phi_bb188_29, phi_bb188_30, phi_bb188_32, phi_bb188_33, phi_bb188_35, phi_bb188_37}, &block228, std::vector<compiler::Node*>{phi_bb188_17, phi_bb188_18, phi_bb188_19, phi_bb188_26, phi_bb188_27, phi_bb188_28, phi_bb188_29, phi_bb188_30, phi_bb188_32, phi_bb188_33, phi_bb188_35, phi_bb188_37});
  }

  TNode<Object> phi_bb227_17;
  TNode<IntPtrT> phi_bb227_18;
  TNode<BoolT> phi_bb227_19;
  TNode<IntPtrT> phi_bb227_26;
  TNode<IntPtrT> phi_bb227_27;
  TNode<IntPtrT> phi_bb227_28;
  TNode<IntPtrT> phi_bb227_29;
  TNode<IntPtrT> phi_bb227_30;
  TNode<IntPtrT> phi_bb227_32;
  TNode<BoolT> phi_bb227_33;
  TNode<Object> phi_bb227_35;
  TNode<Int32T> phi_bb227_37;
  TNode<IntPtrT> tmp408;
  TNode<FixedArray> tmp409;
  if (block227.is_used()) {
    ca_.Bind(&block227, &phi_bb227_17, &phi_bb227_18, &phi_bb227_19, &phi_bb227_26, &phi_bb227_27, &phi_bb227_28, &phi_bb227_29, &phi_bb227_30, &phi_bb227_32, &phi_bb227_33, &phi_bb227_35, &phi_bb227_37);
    tmp408 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp26});
    tmp409 = ca_.CallBuiltin<FixedArray>(Builtin::kWasmAllocateZeroedFixedArray, TNode<Object>(), tmp408);
    ca_.Goto(&block228, phi_bb227_17, phi_bb227_18, phi_bb227_19, phi_bb227_26, phi_bb227_27, phi_bb227_28, phi_bb227_29, phi_bb227_30, phi_bb227_32, phi_bb227_33, tmp409, phi_bb227_37);
  }

  TNode<Object> phi_bb228_17;
  TNode<IntPtrT> phi_bb228_18;
  TNode<BoolT> phi_bb228_19;
  TNode<IntPtrT> phi_bb228_26;
  TNode<IntPtrT> phi_bb228_27;
  TNode<IntPtrT> phi_bb228_28;
  TNode<IntPtrT> phi_bb228_29;
  TNode<IntPtrT> phi_bb228_30;
  TNode<IntPtrT> phi_bb228_32;
  TNode<BoolT> phi_bb228_33;
  TNode<Object> phi_bb228_35;
  TNode<Int32T> phi_bb228_37;
  TNode<FixedArray> tmp410;
  TNode<Object> tmp411;
  TNode<IntPtrT> tmp412;
  TNode<IntPtrT> tmp413;
  TNode<IntPtrT> tmp414;
  TNode<UintPtrT> tmp415;
  TNode<UintPtrT> tmp416;
  TNode<BoolT> tmp417;
  if (block228.is_used()) {
    ca_.Bind(&block228, &phi_bb228_17, &phi_bb228_18, &phi_bb228_19, &phi_bb228_26, &phi_bb228_27, &phi_bb228_28, &phi_bb228_29, &phi_bb228_30, &phi_bb228_32, &phi_bb228_33, &phi_bb228_35, &phi_bb228_37);
    tmp410 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{phi_bb228_35});
    std::tie(tmp411, tmp412, tmp413) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp410}).Flatten();
    tmp414 = Convert_intptr_int32_0(state_, TNode<Int32T>{phi_bb228_37});
    tmp415 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp414});
    tmp416 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp413});
    tmp417 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp415}, TNode<UintPtrT>{tmp416});
    ca_.Branch(tmp417, &block233, std::vector<compiler::Node*>{phi_bb228_17, phi_bb228_18, phi_bb228_19, phi_bb228_26, phi_bb228_27, phi_bb228_28, phi_bb228_29, phi_bb228_30, phi_bb228_32, phi_bb228_33, phi_bb228_37}, &block234, std::vector<compiler::Node*>{phi_bb228_17, phi_bb228_18, phi_bb228_19, phi_bb228_26, phi_bb228_27, phi_bb228_28, phi_bb228_29, phi_bb228_30, phi_bb228_32, phi_bb228_33, phi_bb228_37});
  }

  TNode<Object> phi_bb233_17;
  TNode<IntPtrT> phi_bb233_18;
  TNode<BoolT> phi_bb233_19;
  TNode<IntPtrT> phi_bb233_26;
  TNode<IntPtrT> phi_bb233_27;
  TNode<IntPtrT> phi_bb233_28;
  TNode<IntPtrT> phi_bb233_29;
  TNode<IntPtrT> phi_bb233_30;
  TNode<IntPtrT> phi_bb233_32;
  TNode<BoolT> phi_bb233_33;
  TNode<Int32T> phi_bb233_37;
  TNode<IntPtrT> tmp418;
  TNode<IntPtrT> tmp419;
  TNode<Object> tmp420;
  TNode<IntPtrT> tmp421;
  TNode<Object> tmp422;
  if (block233.is_used()) {
    ca_.Bind(&block233, &phi_bb233_17, &phi_bb233_18, &phi_bb233_19, &phi_bb233_26, &phi_bb233_27, &phi_bb233_28, &phi_bb233_29, &phi_bb233_30, &phi_bb233_32, &phi_bb233_33, &phi_bb233_37);
    tmp418 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp414});
    tmp419 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp412}, TNode<IntPtrT>{tmp418});
    std::tie(tmp420, tmp421) = NewReference_Object_0(state_, TNode<Object>{tmp411}, TNode<IntPtrT>{tmp419}).Flatten();
    tmp422 = JSToWasmObject_0(state_, TNode<NativeContext>{p_context}, TNode<HeapObject>{tmp21}, TNode<Int32T>{tmp221}, TNode<Object>{tmp213});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp420, tmp421}, tmp422);
    ca_.Goto(&block189, phi_bb233_17, phi_bb233_18, phi_bb233_19, phi_bb233_26, phi_bb233_27, phi_bb233_28, phi_bb233_29, phi_bb233_30, phi_bb233_32, phi_bb233_33, tmp406, phi_bb228_35, phi_bb233_37);
  }

  TNode<Object> phi_bb234_17;
  TNode<IntPtrT> phi_bb234_18;
  TNode<BoolT> phi_bb234_19;
  TNode<IntPtrT> phi_bb234_26;
  TNode<IntPtrT> phi_bb234_27;
  TNode<IntPtrT> phi_bb234_28;
  TNode<IntPtrT> phi_bb234_29;
  TNode<IntPtrT> phi_bb234_30;
  TNode<IntPtrT> phi_bb234_32;
  TNode<BoolT> phi_bb234_33;
  TNode<Int32T> phi_bb234_37;
  if (block234.is_used()) {
    ca_.Bind(&block234, &phi_bb234_17, &phi_bb234_18, &phi_bb234_19, &phi_bb234_26, &phi_bb234_27, &phi_bb234_28, &phi_bb234_29, &phi_bb234_30, &phi_bb234_32, &phi_bb234_33, &phi_bb234_37);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> phi_bb189_17;
  TNode<IntPtrT> phi_bb189_18;
  TNode<BoolT> phi_bb189_19;
  TNode<IntPtrT> phi_bb189_26;
  TNode<IntPtrT> phi_bb189_27;
  TNode<IntPtrT> phi_bb189_28;
  TNode<IntPtrT> phi_bb189_29;
  TNode<IntPtrT> phi_bb189_30;
  TNode<IntPtrT> phi_bb189_32;
  TNode<BoolT> phi_bb189_33;
  TNode<BoolT> phi_bb189_34;
  TNode<Object> phi_bb189_35;
  TNode<Int32T> phi_bb189_37;
  if (block189.is_used()) {
    ca_.Bind(&block189, &phi_bb189_17, &phi_bb189_18, &phi_bb189_19, &phi_bb189_26, &phi_bb189_27, &phi_bb189_28, &phi_bb189_29, &phi_bb189_30, &phi_bb189_32, &phi_bb189_33, &phi_bb189_34, &phi_bb189_35, &phi_bb189_37);
    ca_.Goto(&block174, phi_bb189_17, phi_bb189_18, phi_bb189_19, phi_bb189_26, phi_bb189_27, phi_bb189_28, phi_bb189_29, phi_bb189_30, phi_bb189_32, phi_bb189_33, phi_bb189_34, phi_bb189_35, phi_bb189_37);
  }

  TNode<Object> phi_bb174_17;
  TNode<IntPtrT> phi_bb174_18;
  TNode<BoolT> phi_bb174_19;
  TNode<IntPtrT> phi_bb174_26;
  TNode<IntPtrT> phi_bb174_27;
  TNode<IntPtrT> phi_bb174_28;
  TNode<IntPtrT> phi_bb174_29;
  TNode<IntPtrT> phi_bb174_30;
  TNode<IntPtrT> phi_bb174_32;
  TNode<BoolT> phi_bb174_33;
  TNode<BoolT> phi_bb174_34;
  TNode<Object> phi_bb174_35;
  TNode<Int32T> phi_bb174_37;
  if (block174.is_used()) {
    ca_.Bind(&block174, &phi_bb174_17, &phi_bb174_18, &phi_bb174_19, &phi_bb174_26, &phi_bb174_27, &phi_bb174_28, &phi_bb174_29, &phi_bb174_30, &phi_bb174_32, &phi_bb174_33, &phi_bb174_34, &phi_bb174_35, &phi_bb174_37);
    ca_.Goto(&block159, phi_bb174_17, phi_bb174_18, phi_bb174_19, phi_bb174_26, phi_bb174_27, phi_bb174_28, phi_bb174_29, phi_bb174_30, phi_bb174_32, phi_bb174_33, phi_bb174_34, phi_bb174_35, phi_bb174_37);
  }

  TNode<Object> phi_bb159_17;
  TNode<IntPtrT> phi_bb159_18;
  TNode<BoolT> phi_bb159_19;
  TNode<IntPtrT> phi_bb159_26;
  TNode<IntPtrT> phi_bb159_27;
  TNode<IntPtrT> phi_bb159_28;
  TNode<IntPtrT> phi_bb159_29;
  TNode<IntPtrT> phi_bb159_30;
  TNode<IntPtrT> phi_bb159_32;
  TNode<BoolT> phi_bb159_33;
  TNode<BoolT> phi_bb159_34;
  TNode<Object> phi_bb159_35;
  TNode<Int32T> phi_bb159_37;
  if (block159.is_used()) {
    ca_.Bind(&block159, &phi_bb159_17, &phi_bb159_18, &phi_bb159_19, &phi_bb159_26, &phi_bb159_27, &phi_bb159_28, &phi_bb159_29, &phi_bb159_30, &phi_bb159_32, &phi_bb159_33, &phi_bb159_34, &phi_bb159_35, &phi_bb159_37);
    ca_.Goto(&block143, phi_bb159_17, phi_bb159_18, phi_bb159_19, phi_bb159_26, phi_bb159_27, phi_bb159_28, phi_bb159_29, phi_bb159_30, phi_bb159_32, phi_bb159_33, phi_bb159_34, phi_bb159_35, phi_bb159_37);
  }

  TNode<Object> phi_bb143_17;
  TNode<IntPtrT> phi_bb143_18;
  TNode<BoolT> phi_bb143_19;
  TNode<IntPtrT> phi_bb143_26;
  TNode<IntPtrT> phi_bb143_27;
  TNode<IntPtrT> phi_bb143_28;
  TNode<IntPtrT> phi_bb143_29;
  TNode<IntPtrT> phi_bb143_30;
  TNode<IntPtrT> phi_bb143_32;
  TNode<BoolT> phi_bb143_33;
  TNode<BoolT> phi_bb143_34;
  TNode<Object> phi_bb143_35;
  TNode<Int32T> phi_bb143_37;
  TNode<Int32T> tmp423;
  TNode<Int32T> tmp424;
  if (block143.is_used()) {
    ca_.Bind(&block143, &phi_bb143_17, &phi_bb143_18, &phi_bb143_19, &phi_bb143_26, &phi_bb143_27, &phi_bb143_28, &phi_bb143_29, &phi_bb143_30, &phi_bb143_32, &phi_bb143_33, &phi_bb143_34, &phi_bb143_35, &phi_bb143_37);
    tmp423 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    tmp424 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{phi_bb143_37}, TNode<Int32T>{tmp423});
    ca_.Goto(&block138, phi_bb143_17, phi_bb143_18, phi_bb143_19, phi_bb143_26, phi_bb143_27, phi_bb143_28, phi_bb143_29, phi_bb143_30, phi_bb143_32, phi_bb143_33, phi_bb143_34, phi_bb143_35, tmp215, tmp424);
  }

  TNode<Object> phi_bb137_17;
  TNode<IntPtrT> phi_bb137_18;
  TNode<BoolT> phi_bb137_19;
  TNode<IntPtrT> phi_bb137_26;
  TNode<IntPtrT> phi_bb137_27;
  TNode<IntPtrT> phi_bb137_28;
  TNode<IntPtrT> phi_bb137_29;
  TNode<IntPtrT> phi_bb137_30;
  TNode<IntPtrT> phi_bb137_32;
  TNode<BoolT> phi_bb137_33;
  TNode<BoolT> phi_bb137_34;
  TNode<Object> phi_bb137_35;
  TNode<Int32T> phi_bb137_36;
  TNode<Int32T> phi_bb137_37;
  TNode<Undefined> tmp425;
  if (block137.is_used()) {
    ca_.Bind(&block137, &phi_bb137_17, &phi_bb137_18, &phi_bb137_19, &phi_bb137_26, &phi_bb137_27, &phi_bb137_28, &phi_bb137_29, &phi_bb137_30, &phi_bb137_32, &phi_bb137_33, &phi_bb137_34, &phi_bb137_35, &phi_bb137_36, &phi_bb137_37);
    tmp425 = Undefined_0(state_);
    if ((((CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kPromise)) || (CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kStressSwitch))))) {
      ca_.Goto(&block237, phi_bb137_17, phi_bb137_18, phi_bb137_19, phi_bb137_26, phi_bb137_27, phi_bb137_28, phi_bb137_29, phi_bb137_30, phi_bb137_32, phi_bb137_33, phi_bb137_34, phi_bb137_35, phi_bb137_36);
    } else {
      ca_.Goto(&block238, phi_bb137_17, phi_bb137_18, phi_bb137_19, phi_bb137_26, phi_bb137_27, phi_bb137_28, phi_bb137_29, phi_bb137_30, phi_bb137_32, phi_bb137_33, phi_bb137_34, phi_bb137_35, phi_bb137_36);
    }
  }

  TNode<Object> phi_bb237_17;
  TNode<IntPtrT> phi_bb237_18;
  TNode<BoolT> phi_bb237_19;
  TNode<IntPtrT> phi_bb237_26;
  TNode<IntPtrT> phi_bb237_27;
  TNode<IntPtrT> phi_bb237_28;
  TNode<IntPtrT> phi_bb237_29;
  TNode<IntPtrT> phi_bb237_30;
  TNode<IntPtrT> phi_bb237_32;
  TNode<BoolT> phi_bb237_33;
  TNode<BoolT> phi_bb237_34;
  TNode<Object> phi_bb237_35;
  TNode<Int32T> phi_bb237_36;
  TNode<Object> tmp426;
  TNode<BoolT> tmp427;
  if (block237.is_used()) {
    ca_.Bind(&block237, &phi_bb237_17, &phi_bb237_18, &phi_bb237_19, &phi_bb237_26, &phi_bb237_27, &phi_bb237_28, &phi_bb237_29, &phi_bb237_30, &phi_bb237_32, &phi_bb237_33, &phi_bb237_34, &phi_bb237_35, &phi_bb237_36);
    tmp426 = CodeStubAssembler(state_).CallRuntime(Runtime::kWasmAllocateSuspender, p_context); 
    tmp427 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kStressSwitch)));
    ca_.Branch(tmp427, &block240, std::vector<compiler::Node*>{phi_bb237_17, phi_bb237_18, phi_bb237_19, phi_bb237_26, phi_bb237_27, phi_bb237_28, phi_bb237_29, phi_bb237_30, phi_bb237_32, phi_bb237_33, phi_bb237_34, phi_bb237_35, phi_bb237_36}, &block241, std::vector<compiler::Node*>{phi_bb237_17, phi_bb237_18, phi_bb237_19, phi_bb237_26, phi_bb237_27, phi_bb237_28, phi_bb237_29, phi_bb237_30, phi_bb237_32, phi_bb237_33, phi_bb237_34, phi_bb237_35, phi_bb237_36});
  }

  TNode<Object> phi_bb240_17;
  TNode<IntPtrT> phi_bb240_18;
  TNode<BoolT> phi_bb240_19;
  TNode<IntPtrT> phi_bb240_26;
  TNode<IntPtrT> phi_bb240_27;
  TNode<IntPtrT> phi_bb240_28;
  TNode<IntPtrT> phi_bb240_29;
  TNode<IntPtrT> phi_bb240_30;
  TNode<IntPtrT> phi_bb240_32;
  TNode<BoolT> phi_bb240_33;
  TNode<BoolT> phi_bb240_34;
  TNode<Object> phi_bb240_35;
  TNode<Int32T> phi_bb240_36;
  TNode<WasmSuspenderObject> tmp428;
  TNode<IntPtrT> tmp429;
  TNode<Undefined> tmp430;
  if (block240.is_used()) {
    ca_.Bind(&block240, &phi_bb240_17, &phi_bb240_18, &phi_bb240_19, &phi_bb240_26, &phi_bb240_27, &phi_bb240_28, &phi_bb240_29, &phi_bb240_30, &phi_bb240_32, &phi_bb240_33, &phi_bb240_34, &phi_bb240_35, &phi_bb240_36);
    tmp428 = UnsafeCast_WasmSuspenderObject_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp426});
    tmp429 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp430 = Undefined_0(state_);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp428, tmp429}, tmp430);
    ca_.Goto(&block241, phi_bb240_17, phi_bb240_18, phi_bb240_19, phi_bb240_26, phi_bb240_27, phi_bb240_28, phi_bb240_29, phi_bb240_30, phi_bb240_32, phi_bb240_33, phi_bb240_34, phi_bb240_35, phi_bb240_36);
  }

  TNode<Object> phi_bb241_17;
  TNode<IntPtrT> phi_bb241_18;
  TNode<BoolT> phi_bb241_19;
  TNode<IntPtrT> phi_bb241_26;
  TNode<IntPtrT> phi_bb241_27;
  TNode<IntPtrT> phi_bb241_28;
  TNode<IntPtrT> phi_bb241_29;
  TNode<IntPtrT> phi_bb241_30;
  TNode<IntPtrT> phi_bb241_32;
  TNode<BoolT> phi_bb241_33;
  TNode<BoolT> phi_bb241_34;
  TNode<Object> phi_bb241_35;
  TNode<Int32T> phi_bb241_36;
  if (block241.is_used()) {
    ca_.Bind(&block241, &phi_bb241_17, &phi_bb241_18, &phi_bb241_19, &phi_bb241_26, &phi_bb241_27, &phi_bb241_28, &phi_bb241_29, &phi_bb241_30, &phi_bb241_32, &phi_bb241_33, &phi_bb241_34, &phi_bb241_35, &phi_bb241_36);
    ca_.Goto(&block239, phi_bb241_17, phi_bb241_18, phi_bb241_19, phi_bb241_26, phi_bb241_27, phi_bb241_28, phi_bb241_29, phi_bb241_30, phi_bb241_32, phi_bb241_33, phi_bb241_34, phi_bb241_35, phi_bb241_36, tmp426);
  }

  TNode<Object> phi_bb238_17;
  TNode<IntPtrT> phi_bb238_18;
  TNode<BoolT> phi_bb238_19;
  TNode<IntPtrT> phi_bb238_26;
  TNode<IntPtrT> phi_bb238_27;
  TNode<IntPtrT> phi_bb238_28;
  TNode<IntPtrT> phi_bb238_29;
  TNode<IntPtrT> phi_bb238_30;
  TNode<IntPtrT> phi_bb238_32;
  TNode<BoolT> phi_bb238_33;
  TNode<BoolT> phi_bb238_34;
  TNode<Object> phi_bb238_35;
  TNode<Int32T> phi_bb238_36;
  if (block238.is_used()) {
    ca_.Bind(&block238, &phi_bb238_17, &phi_bb238_18, &phi_bb238_19, &phi_bb238_26, &phi_bb238_27, &phi_bb238_28, &phi_bb238_29, &phi_bb238_30, &phi_bb238_32, &phi_bb238_33, &phi_bb238_34, &phi_bb238_35, &phi_bb238_36);
    ca_.Goto(&block239, phi_bb238_17, phi_bb238_18, phi_bb238_19, phi_bb238_26, phi_bb238_27, phi_bb238_28, phi_bb238_29, phi_bb238_30, phi_bb238_32, phi_bb238_33, phi_bb238_34, phi_bb238_35, phi_bb238_36, tmp425);
  }

  TNode<Object> phi_bb239_17;
  TNode<IntPtrT> phi_bb239_18;
  TNode<BoolT> phi_bb239_19;
  TNode<IntPtrT> phi_bb239_26;
  TNode<IntPtrT> phi_bb239_27;
  TNode<IntPtrT> phi_bb239_28;
  TNode<IntPtrT> phi_bb239_29;
  TNode<IntPtrT> phi_bb239_30;
  TNode<IntPtrT> phi_bb239_32;
  TNode<BoolT> phi_bb239_33;
  TNode<BoolT> phi_bb239_34;
  TNode<Object> phi_bb239_35;
  TNode<Int32T> phi_bb239_36;
  TNode<Object> phi_bb239_37;
  if (block239.is_used()) {
    ca_.Bind(&block239, &phi_bb239_17, &phi_bb239_18, &phi_bb239_19, &phi_bb239_26, &phi_bb239_27, &phi_bb239_28, &phi_bb239_29, &phi_bb239_30, &phi_bb239_32, &phi_bb239_33, &phi_bb239_34, &phi_bb239_35, &phi_bb239_36, &phi_bb239_37);
    ca_.Branch(phi_bb239_34, &block242, std::vector<compiler::Node*>{phi_bb239_17, phi_bb239_18, phi_bb239_19, phi_bb239_26, phi_bb239_27, phi_bb239_28, phi_bb239_29, phi_bb239_30, phi_bb239_32, phi_bb239_33, phi_bb239_34, phi_bb239_35, phi_bb239_36}, &block243, std::vector<compiler::Node*>{phi_bb239_17, phi_bb239_18, phi_bb239_19, phi_bb239_26, phi_bb239_27, phi_bb239_28, phi_bb239_29, phi_bb239_30, phi_bb239_32, phi_bb239_33, phi_bb239_34, phi_bb239_35, phi_bb239_36});
  }

  TNode<Object> phi_bb242_17;
  TNode<IntPtrT> phi_bb242_18;
  TNode<BoolT> phi_bb242_19;
  TNode<IntPtrT> phi_bb242_26;
  TNode<IntPtrT> phi_bb242_27;
  TNode<IntPtrT> phi_bb242_28;
  TNode<IntPtrT> phi_bb242_29;
  TNode<IntPtrT> phi_bb242_30;
  TNode<IntPtrT> phi_bb242_32;
  TNode<BoolT> phi_bb242_33;
  TNode<BoolT> phi_bb242_34;
  TNode<Object> phi_bb242_35;
  TNode<Int32T> phi_bb242_36;
  TNode<Int32T> tmp431;
  TNode<Int32T> tmp432;
  TNode<BoolT> tmp433;
  if (block242.is_used()) {
    ca_.Bind(&block242, &phi_bb242_17, &phi_bb242_18, &phi_bb242_19, &phi_bb242_26, &phi_bb242_27, &phi_bb242_28, &phi_bb242_29, &phi_bb242_30, &phi_bb242_32, &phi_bb242_33, &phi_bb242_34, &phi_bb242_35, &phi_bb242_36);
    tmp431 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp432 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp433 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{phi_bb242_33});
    ca_.Branch(tmp433, &block245, std::vector<compiler::Node*>{phi_bb242_17, phi_bb242_18, phi_bb242_19, phi_bb242_26, phi_bb242_27, phi_bb242_28, phi_bb242_29, phi_bb242_30, phi_bb242_32, phi_bb242_33, phi_bb242_34, phi_bb242_35, phi_bb242_36}, &block246, std::vector<compiler::Node*>{phi_bb242_17, phi_bb242_18, phi_bb242_19, phi_bb242_26, phi_bb242_27, phi_bb242_28, phi_bb242_29, phi_bb242_30, phi_bb242_32, phi_bb242_33, phi_bb242_34, phi_bb242_35, phi_bb242_36});
  }

  TNode<Object> phi_bb245_17;
  TNode<IntPtrT> phi_bb245_18;
  TNode<BoolT> phi_bb245_19;
  TNode<IntPtrT> phi_bb245_26;
  TNode<IntPtrT> phi_bb245_27;
  TNode<IntPtrT> phi_bb245_28;
  TNode<IntPtrT> phi_bb245_29;
  TNode<IntPtrT> phi_bb245_30;
  TNode<IntPtrT> phi_bb245_32;
  TNode<BoolT> phi_bb245_33;
  TNode<BoolT> phi_bb245_34;
  TNode<Object> phi_bb245_35;
  TNode<Int32T> phi_bb245_36;
  TNode<IntPtrT> tmp434;
  if (block245.is_used()) {
    ca_.Bind(&block245, &phi_bb245_17, &phi_bb245_18, &phi_bb245_19, &phi_bb245_26, &phi_bb245_27, &phi_bb245_28, &phi_bb245_29, &phi_bb245_30, &phi_bb245_32, &phi_bb245_33, &phi_bb245_34, &phi_bb245_35, &phi_bb245_36);
    tmp434 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block246, phi_bb245_17, phi_bb245_18, phi_bb245_19, phi_bb245_26, phi_bb245_27, phi_bb245_28, phi_bb245_29, phi_bb245_30, tmp434, phi_bb245_33, phi_bb245_34, phi_bb245_35, phi_bb245_36);
  }

  TNode<Object> phi_bb246_17;
  TNode<IntPtrT> phi_bb246_18;
  TNode<BoolT> phi_bb246_19;
  TNode<IntPtrT> phi_bb246_26;
  TNode<IntPtrT> phi_bb246_27;
  TNode<IntPtrT> phi_bb246_28;
  TNode<IntPtrT> phi_bb246_29;
  TNode<IntPtrT> phi_bb246_30;
  TNode<IntPtrT> phi_bb246_32;
  TNode<BoolT> phi_bb246_33;
  TNode<BoolT> phi_bb246_34;
  TNode<Object> phi_bb246_35;
  TNode<Int32T> phi_bb246_36;
  if (block246.is_used()) {
    ca_.Bind(&block246, &phi_bb246_17, &phi_bb246_18, &phi_bb246_19, &phi_bb246_26, &phi_bb246_27, &phi_bb246_28, &phi_bb246_29, &phi_bb246_30, &phi_bb246_32, &phi_bb246_33, &phi_bb246_34, &phi_bb246_35, &phi_bb246_36);
    ca_.Goto(&block249, phi_bb246_17, phi_bb246_18, phi_bb246_19, phi_bb246_26, phi_bb246_27, phi_bb246_28, phi_bb246_29, phi_bb246_30, phi_bb246_32, phi_bb246_33, phi_bb246_34, phi_bb246_35, phi_bb246_36, tmp431, tmp432);
  }

  TNode<Object> phi_bb249_17;
  TNode<IntPtrT> phi_bb249_18;
  TNode<BoolT> phi_bb249_19;
  TNode<IntPtrT> phi_bb249_26;
  TNode<IntPtrT> phi_bb249_27;
  TNode<IntPtrT> phi_bb249_28;
  TNode<IntPtrT> phi_bb249_29;
  TNode<IntPtrT> phi_bb249_30;
  TNode<IntPtrT> phi_bb249_32;
  TNode<BoolT> phi_bb249_33;
  TNode<BoolT> phi_bb249_34;
  TNode<Object> phi_bb249_35;
  TNode<Int32T> phi_bb249_36;
  TNode<Int32T> phi_bb249_38;
  TNode<Int32T> phi_bb249_39;
  TNode<BoolT> tmp435;
  if (block249.is_used()) {
    ca_.Bind(&block249, &phi_bb249_17, &phi_bb249_18, &phi_bb249_19, &phi_bb249_26, &phi_bb249_27, &phi_bb249_28, &phi_bb249_29, &phi_bb249_30, &phi_bb249_32, &phi_bb249_33, &phi_bb249_34, &phi_bb249_35, &phi_bb249_36, &phi_bb249_38, &phi_bb249_39);
    tmp435 = CodeStubAssembler(state_).Int32LessThan(TNode<Int32T>{phi_bb249_38}, TNode<Int32T>{tmp26});
    ca_.Branch(tmp435, &block247, std::vector<compiler::Node*>{phi_bb249_17, phi_bb249_18, phi_bb249_19, phi_bb249_26, phi_bb249_27, phi_bb249_28, phi_bb249_29, phi_bb249_30, phi_bb249_32, phi_bb249_33, phi_bb249_34, phi_bb249_35, phi_bb249_36, phi_bb249_38, phi_bb249_39}, &block248, std::vector<compiler::Node*>{phi_bb249_17, phi_bb249_18, phi_bb249_19, phi_bb249_26, phi_bb249_27, phi_bb249_28, phi_bb249_29, phi_bb249_30, phi_bb249_32, phi_bb249_33, phi_bb249_34, phi_bb249_35, phi_bb249_36, phi_bb249_38, phi_bb249_39});
  }

  TNode<Object> phi_bb247_17;
  TNode<IntPtrT> phi_bb247_18;
  TNode<BoolT> phi_bb247_19;
  TNode<IntPtrT> phi_bb247_26;
  TNode<IntPtrT> phi_bb247_27;
  TNode<IntPtrT> phi_bb247_28;
  TNode<IntPtrT> phi_bb247_29;
  TNode<IntPtrT> phi_bb247_30;
  TNode<IntPtrT> phi_bb247_32;
  TNode<BoolT> phi_bb247_33;
  TNode<BoolT> phi_bb247_34;
  TNode<Object> phi_bb247_35;
  TNode<Int32T> phi_bb247_36;
  TNode<Int32T> phi_bb247_38;
  TNode<Int32T> phi_bb247_39;
  TNode<IntPtrT> tmp436;
  TNode<IntPtrT> tmp437;
  TNode<IntPtrT> tmp438;
  TNode<Object> tmp439;
  TNode<IntPtrT> tmp440;
  TNode<Int32T> tmp441;
  TNode<Int32T> tmp442;
  TNode<Int32T> tmp443;
  TNode<Int32T> tmp444;
  TNode<BoolT> tmp445;
  if (block247.is_used()) {
    ca_.Bind(&block247, &phi_bb247_17, &phi_bb247_18, &phi_bb247_19, &phi_bb247_26, &phi_bb247_27, &phi_bb247_28, &phi_bb247_29, &phi_bb247_30, &phi_bb247_32, &phi_bb247_33, &phi_bb247_34, &phi_bb247_35, &phi_bb247_36, &phi_bb247_38, &phi_bb247_39);
    tmp436 = Convert_intptr_int32_0(state_, TNode<Int32T>{phi_bb247_38});
    tmp437 = TimesSizeOf_int32_0(state_, TNode<IntPtrT>{tmp436});
    tmp438 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp172}, TNode<IntPtrT>{tmp437});
    std::tie(tmp439, tmp440) = NewReference_int32_0(state_, TNode<Object>{tmp171}, TNode<IntPtrT>{tmp438}).Flatten();
    tmp441 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp439, tmp440});
    tmp442 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    tmp443 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp441}, TNode<Int32T>{tmp442});
    tmp444 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    tmp445 = CodeStubAssembler(state_).Word32NotEqual(TNode<Int32T>{tmp443}, TNode<Int32T>{tmp444});
    ca_.Branch(tmp445, &block253, std::vector<compiler::Node*>{phi_bb247_17, phi_bb247_18, phi_bb247_19, phi_bb247_26, phi_bb247_27, phi_bb247_28, phi_bb247_29, phi_bb247_30, phi_bb247_32, phi_bb247_33, phi_bb247_34, phi_bb247_35, phi_bb247_36, phi_bb247_38, phi_bb247_39}, &block254, std::vector<compiler::Node*>{phi_bb247_17, phi_bb247_18, phi_bb247_19, phi_bb247_26, phi_bb247_27, phi_bb247_28, phi_bb247_29, phi_bb247_30, phi_bb247_32, phi_bb247_33, phi_bb247_34, phi_bb247_35, phi_bb247_36, phi_bb247_38, phi_bb247_39});
  }

  TNode<Object> phi_bb253_17;
  TNode<IntPtrT> phi_bb253_18;
  TNode<BoolT> phi_bb253_19;
  TNode<IntPtrT> phi_bb253_26;
  TNode<IntPtrT> phi_bb253_27;
  TNode<IntPtrT> phi_bb253_28;
  TNode<IntPtrT> phi_bb253_29;
  TNode<IntPtrT> phi_bb253_30;
  TNode<IntPtrT> phi_bb253_32;
  TNode<BoolT> phi_bb253_33;
  TNode<BoolT> phi_bb253_34;
  TNode<Object> phi_bb253_35;
  TNode<Int32T> phi_bb253_36;
  TNode<Int32T> phi_bb253_38;
  TNode<Int32T> phi_bb253_39;
  TNode<Int32T> tmp446;
  TNode<BoolT> tmp447;
  if (block253.is_used()) {
    ca_.Bind(&block253, &phi_bb253_17, &phi_bb253_18, &phi_bb253_19, &phi_bb253_26, &phi_bb253_27, &phi_bb253_28, &phi_bb253_29, &phi_bb253_30, &phi_bb253_32, &phi_bb253_33, &phi_bb253_34, &phi_bb253_35, &phi_bb253_36, &phi_bb253_38, &phi_bb253_39);
    tmp446 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRefNull);
    tmp447 = CodeStubAssembler(state_).Word32NotEqual(TNode<Int32T>{tmp443}, TNode<Int32T>{tmp446});
    ca_.Goto(&block255, phi_bb253_17, phi_bb253_18, phi_bb253_19, phi_bb253_26, phi_bb253_27, phi_bb253_28, phi_bb253_29, phi_bb253_30, phi_bb253_32, phi_bb253_33, phi_bb253_34, phi_bb253_35, phi_bb253_36, phi_bb253_38, phi_bb253_39, tmp447);
  }

  TNode<Object> phi_bb254_17;
  TNode<IntPtrT> phi_bb254_18;
  TNode<BoolT> phi_bb254_19;
  TNode<IntPtrT> phi_bb254_26;
  TNode<IntPtrT> phi_bb254_27;
  TNode<IntPtrT> phi_bb254_28;
  TNode<IntPtrT> phi_bb254_29;
  TNode<IntPtrT> phi_bb254_30;
  TNode<IntPtrT> phi_bb254_32;
  TNode<BoolT> phi_bb254_33;
  TNode<BoolT> phi_bb254_34;
  TNode<Object> phi_bb254_35;
  TNode<Int32T> phi_bb254_36;
  TNode<Int32T> phi_bb254_38;
  TNode<Int32T> phi_bb254_39;
  TNode<BoolT> tmp448;
  if (block254.is_used()) {
    ca_.Bind(&block254, &phi_bb254_17, &phi_bb254_18, &phi_bb254_19, &phi_bb254_26, &phi_bb254_27, &phi_bb254_28, &phi_bb254_29, &phi_bb254_30, &phi_bb254_32, &phi_bb254_33, &phi_bb254_34, &phi_bb254_35, &phi_bb254_36, &phi_bb254_38, &phi_bb254_39);
    tmp448 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block255, phi_bb254_17, phi_bb254_18, phi_bb254_19, phi_bb254_26, phi_bb254_27, phi_bb254_28, phi_bb254_29, phi_bb254_30, phi_bb254_32, phi_bb254_33, phi_bb254_34, phi_bb254_35, phi_bb254_36, phi_bb254_38, phi_bb254_39, tmp448);
  }

  TNode<Object> phi_bb255_17;
  TNode<IntPtrT> phi_bb255_18;
  TNode<BoolT> phi_bb255_19;
  TNode<IntPtrT> phi_bb255_26;
  TNode<IntPtrT> phi_bb255_27;
  TNode<IntPtrT> phi_bb255_28;
  TNode<IntPtrT> phi_bb255_29;
  TNode<IntPtrT> phi_bb255_30;
  TNode<IntPtrT> phi_bb255_32;
  TNode<BoolT> phi_bb255_33;
  TNode<BoolT> phi_bb255_34;
  TNode<Object> phi_bb255_35;
  TNode<Int32T> phi_bb255_36;
  TNode<Int32T> phi_bb255_38;
  TNode<Int32T> phi_bb255_39;
  TNode<BoolT> phi_bb255_43;
  if (block255.is_used()) {
    ca_.Bind(&block255, &phi_bb255_17, &phi_bb255_18, &phi_bb255_19, &phi_bb255_26, &phi_bb255_27, &phi_bb255_28, &phi_bb255_29, &phi_bb255_30, &phi_bb255_32, &phi_bb255_33, &phi_bb255_34, &phi_bb255_35, &phi_bb255_36, &phi_bb255_38, &phi_bb255_39, &phi_bb255_43);
    ca_.Branch(phi_bb255_43, &block251, std::vector<compiler::Node*>{phi_bb255_17, phi_bb255_18, phi_bb255_19, phi_bb255_26, phi_bb255_27, phi_bb255_28, phi_bb255_29, phi_bb255_30, phi_bb255_32, phi_bb255_33, phi_bb255_34, phi_bb255_35, phi_bb255_36, phi_bb255_38, phi_bb255_39}, &block252, std::vector<compiler::Node*>{phi_bb255_17, phi_bb255_18, phi_bb255_19, phi_bb255_26, phi_bb255_27, phi_bb255_28, phi_bb255_29, phi_bb255_30, phi_bb255_32, phi_bb255_33, phi_bb255_34, phi_bb255_35, phi_bb255_36, phi_bb255_38, phi_bb255_39});
  }

  TNode<Object> phi_bb251_17;
  TNode<IntPtrT> phi_bb251_18;
  TNode<BoolT> phi_bb251_19;
  TNode<IntPtrT> phi_bb251_26;
  TNode<IntPtrT> phi_bb251_27;
  TNode<IntPtrT> phi_bb251_28;
  TNode<IntPtrT> phi_bb251_29;
  TNode<IntPtrT> phi_bb251_30;
  TNode<IntPtrT> phi_bb251_32;
  TNode<BoolT> phi_bb251_33;
  TNode<BoolT> phi_bb251_34;
  TNode<Object> phi_bb251_35;
  TNode<Int32T> phi_bb251_36;
  TNode<Int32T> phi_bb251_38;
  TNode<Int32T> phi_bb251_39;
  TNode<Int32T> tmp449;
  TNode<Int32T> tmp450;
  TNode<Int32T> tmp451;
  TNode<Int32T> tmp452;
  if (block251.is_used()) {
    ca_.Bind(&block251, &phi_bb251_17, &phi_bb251_18, &phi_bb251_19, &phi_bb251_26, &phi_bb251_27, &phi_bb251_28, &phi_bb251_29, &phi_bb251_30, &phi_bb251_32, &phi_bb251_33, &phi_bb251_34, &phi_bb251_35, &phi_bb251_36, &phi_bb251_38, &phi_bb251_39);
    tmp449 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    tmp450 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{phi_bb251_38}, TNode<Int32T>{tmp449});
    tmp451 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    tmp452 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{phi_bb251_39}, TNode<Int32T>{tmp451});
    ca_.Goto(&block249, phi_bb251_17, phi_bb251_18, phi_bb251_19, phi_bb251_26, phi_bb251_27, phi_bb251_28, phi_bb251_29, phi_bb251_30, phi_bb251_32, phi_bb251_33, phi_bb251_34, phi_bb251_35, phi_bb251_36, tmp450, tmp452);
  }

  TNode<Object> phi_bb252_17;
  TNode<IntPtrT> phi_bb252_18;
  TNode<BoolT> phi_bb252_19;
  TNode<IntPtrT> phi_bb252_26;
  TNode<IntPtrT> phi_bb252_27;
  TNode<IntPtrT> phi_bb252_28;
  TNode<IntPtrT> phi_bb252_29;
  TNode<IntPtrT> phi_bb252_30;
  TNode<IntPtrT> phi_bb252_32;
  TNode<BoolT> phi_bb252_33;
  TNode<BoolT> phi_bb252_34;
  TNode<Object> phi_bb252_35;
  TNode<Int32T> phi_bb252_36;
  TNode<Int32T> phi_bb252_38;
  TNode<Int32T> phi_bb252_39;
  TNode<FixedArray> tmp453;
  TNode<Object> tmp454;
  TNode<IntPtrT> tmp455;
  TNode<IntPtrT> tmp456;
  TNode<Int32T> tmp457;
  TNode<Int32T> tmp458;
  TNode<IntPtrT> tmp459;
  TNode<UintPtrT> tmp460;
  TNode<UintPtrT> tmp461;
  TNode<BoolT> tmp462;
  if (block252.is_used()) {
    ca_.Bind(&block252, &phi_bb252_17, &phi_bb252_18, &phi_bb252_19, &phi_bb252_26, &phi_bb252_27, &phi_bb252_28, &phi_bb252_29, &phi_bb252_30, &phi_bb252_32, &phi_bb252_33, &phi_bb252_34, &phi_bb252_35, &phi_bb252_36, &phi_bb252_38, &phi_bb252_39);
    tmp453 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{phi_bb252_35});
    std::tie(tmp454, tmp455, tmp456) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp453}).Flatten();
    tmp457 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    tmp458 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{phi_bb252_39}, TNode<Int32T>{tmp457});
    tmp459 = Convert_intptr_int32_0(state_, TNode<Int32T>{phi_bb252_39});
    tmp460 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp459});
    tmp461 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp456});
    tmp462 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp460}, TNode<UintPtrT>{tmp461});
    ca_.Branch(tmp462, &block260, std::vector<compiler::Node*>{phi_bb252_17, phi_bb252_18, phi_bb252_19, phi_bb252_26, phi_bb252_27, phi_bb252_28, phi_bb252_29, phi_bb252_30, phi_bb252_32, phi_bb252_33, phi_bb252_34, phi_bb252_35, phi_bb252_36, phi_bb252_38}, &block261, std::vector<compiler::Node*>{phi_bb252_17, phi_bb252_18, phi_bb252_19, phi_bb252_26, phi_bb252_27, phi_bb252_28, phi_bb252_29, phi_bb252_30, phi_bb252_32, phi_bb252_33, phi_bb252_34, phi_bb252_35, phi_bb252_36, phi_bb252_38});
  }

  TNode<Object> phi_bb260_17;
  TNode<IntPtrT> phi_bb260_18;
  TNode<BoolT> phi_bb260_19;
  TNode<IntPtrT> phi_bb260_26;
  TNode<IntPtrT> phi_bb260_27;
  TNode<IntPtrT> phi_bb260_28;
  TNode<IntPtrT> phi_bb260_29;
  TNode<IntPtrT> phi_bb260_30;
  TNode<IntPtrT> phi_bb260_32;
  TNode<BoolT> phi_bb260_33;
  TNode<BoolT> phi_bb260_34;
  TNode<Object> phi_bb260_35;
  TNode<Int32T> phi_bb260_36;
  TNode<Int32T> phi_bb260_38;
  TNode<IntPtrT> tmp463;
  TNode<IntPtrT> tmp464;
  TNode<Object> tmp465;
  TNode<IntPtrT> tmp466;
  TNode<Object> tmp467;
  TNode<IntPtrT> tmp468;
  TNode<IntPtrT> tmp469;
  TNode<IntPtrT> tmp470;
  TNode<BoolT> tmp471;
  if (block260.is_used()) {
    ca_.Bind(&block260, &phi_bb260_17, &phi_bb260_18, &phi_bb260_19, &phi_bb260_26, &phi_bb260_27, &phi_bb260_28, &phi_bb260_29, &phi_bb260_30, &phi_bb260_32, &phi_bb260_33, &phi_bb260_34, &phi_bb260_35, &phi_bb260_36, &phi_bb260_38);
    tmp463 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{tmp459});
    tmp464 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp455}, TNode<IntPtrT>{tmp463});
    std::tie(tmp465, tmp466) = NewReference_Object_0(state_, TNode<Object>{tmp454}, TNode<IntPtrT>{tmp464}).Flatten();
    tmp467 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp465, tmp466});
    tmp468 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp469 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb260_26}, TNode<IntPtrT>{tmp468});
    tmp470 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp471 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb260_26}, TNode<IntPtrT>{tmp470});
    ca_.Branch(tmp471, &block265, std::vector<compiler::Node*>{phi_bb260_17, phi_bb260_18, phi_bb260_19, phi_bb260_27, phi_bb260_28, phi_bb260_29, phi_bb260_30, phi_bb260_32, phi_bb260_33, phi_bb260_34, phi_bb260_35, phi_bb260_36, phi_bb260_38}, &block266, std::vector<compiler::Node*>{phi_bb260_17, phi_bb260_18, phi_bb260_19, phi_bb260_27, phi_bb260_28, phi_bb260_29, phi_bb260_30, phi_bb260_32, phi_bb260_33, phi_bb260_34, phi_bb260_35, phi_bb260_36, phi_bb260_38});
  }

  TNode<Object> phi_bb261_17;
  TNode<IntPtrT> phi_bb261_18;
  TNode<BoolT> phi_bb261_19;
  TNode<IntPtrT> phi_bb261_26;
  TNode<IntPtrT> phi_bb261_27;
  TNode<IntPtrT> phi_bb261_28;
  TNode<IntPtrT> phi_bb261_29;
  TNode<IntPtrT> phi_bb261_30;
  TNode<IntPtrT> phi_bb261_32;
  TNode<BoolT> phi_bb261_33;
  TNode<BoolT> phi_bb261_34;
  TNode<Object> phi_bb261_35;
  TNode<Int32T> phi_bb261_36;
  TNode<Int32T> phi_bb261_38;
  if (block261.is_used()) {
    ca_.Bind(&block261, &phi_bb261_17, &phi_bb261_18, &phi_bb261_19, &phi_bb261_26, &phi_bb261_27, &phi_bb261_28, &phi_bb261_29, &phi_bb261_30, &phi_bb261_32, &phi_bb261_33, &phi_bb261_34, &phi_bb261_35, &phi_bb261_36, &phi_bb261_38);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> phi_bb265_17;
  TNode<IntPtrT> phi_bb265_18;
  TNode<BoolT> phi_bb265_19;
  TNode<IntPtrT> phi_bb265_27;
  TNode<IntPtrT> phi_bb265_28;
  TNode<IntPtrT> phi_bb265_29;
  TNode<IntPtrT> phi_bb265_30;
  TNode<IntPtrT> phi_bb265_32;
  TNode<BoolT> phi_bb265_33;
  TNode<BoolT> phi_bb265_34;
  TNode<Object> phi_bb265_35;
  TNode<Int32T> phi_bb265_36;
  TNode<Int32T> phi_bb265_38;
  TNode<Object> tmp472;
  TNode<IntPtrT> tmp473;
  TNode<IntPtrT> tmp474;
  TNode<IntPtrT> tmp475;
  if (block265.is_used()) {
    ca_.Bind(&block265, &phi_bb265_17, &phi_bb265_18, &phi_bb265_19, &phi_bb265_27, &phi_bb265_28, &phi_bb265_29, &phi_bb265_30, &phi_bb265_32, &phi_bb265_33, &phi_bb265_34, &phi_bb265_35, &phi_bb265_36, &phi_bb265_38);
    std::tie(tmp472, tmp473) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb265_28}).Flatten();
    tmp474 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp475 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb265_28}, TNode<IntPtrT>{tmp474});
    ca_.Goto(&block264, phi_bb265_17, phi_bb265_18, phi_bb265_19, phi_bb265_27, tmp475, phi_bb265_29, phi_bb265_30, phi_bb265_32, phi_bb265_33, phi_bb265_34, phi_bb265_35, phi_bb265_36, phi_bb265_38, tmp472, tmp473);
  }

  TNode<Object> phi_bb266_17;
  TNode<IntPtrT> phi_bb266_18;
  TNode<BoolT> phi_bb266_19;
  TNode<IntPtrT> phi_bb266_27;
  TNode<IntPtrT> phi_bb266_28;
  TNode<IntPtrT> phi_bb266_29;
  TNode<IntPtrT> phi_bb266_30;
  TNode<IntPtrT> phi_bb266_32;
  TNode<BoolT> phi_bb266_33;
  TNode<BoolT> phi_bb266_34;
  TNode<Object> phi_bb266_35;
  TNode<Int32T> phi_bb266_36;
  TNode<Int32T> phi_bb266_38;
  if (block266.is_used()) {
    ca_.Bind(&block266, &phi_bb266_17, &phi_bb266_18, &phi_bb266_19, &phi_bb266_27, &phi_bb266_28, &phi_bb266_29, &phi_bb266_30, &phi_bb266_32, &phi_bb266_33, &phi_bb266_34, &phi_bb266_35, &phi_bb266_36, &phi_bb266_38);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block268, phi_bb266_17, phi_bb266_18, phi_bb266_19, phi_bb266_27, phi_bb266_28, phi_bb266_29, phi_bb266_30, phi_bb266_32, phi_bb266_33, phi_bb266_34, phi_bb266_35, phi_bb266_36, phi_bb266_38);
    } else {
      ca_.Goto(&block269, phi_bb266_17, phi_bb266_18, phi_bb266_19, phi_bb266_27, phi_bb266_28, phi_bb266_29, phi_bb266_30, phi_bb266_32, phi_bb266_33, phi_bb266_34, phi_bb266_35, phi_bb266_36, phi_bb266_38);
    }
  }

  TNode<Object> phi_bb268_17;
  TNode<IntPtrT> phi_bb268_18;
  TNode<BoolT> phi_bb268_19;
  TNode<IntPtrT> phi_bb268_27;
  TNode<IntPtrT> phi_bb268_28;
  TNode<IntPtrT> phi_bb268_29;
  TNode<IntPtrT> phi_bb268_30;
  TNode<IntPtrT> phi_bb268_32;
  TNode<BoolT> phi_bb268_33;
  TNode<BoolT> phi_bb268_34;
  TNode<Object> phi_bb268_35;
  TNode<Int32T> phi_bb268_36;
  TNode<Int32T> phi_bb268_38;
  TNode<Object> tmp476;
  TNode<IntPtrT> tmp477;
  TNode<IntPtrT> tmp478;
  TNode<IntPtrT> tmp479;
  if (block268.is_used()) {
    ca_.Bind(&block268, &phi_bb268_17, &phi_bb268_18, &phi_bb268_19, &phi_bb268_27, &phi_bb268_28, &phi_bb268_29, &phi_bb268_30, &phi_bb268_32, &phi_bb268_33, &phi_bb268_34, &phi_bb268_35, &phi_bb268_36, &phi_bb268_38);
    std::tie(tmp476, tmp477) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb268_30}).Flatten();
    tmp478 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp479 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb268_30}, TNode<IntPtrT>{tmp478});
    ca_.Goto(&block267, phi_bb268_17, phi_bb268_18, phi_bb268_19, phi_bb268_27, phi_bb268_28, phi_bb268_29, tmp479, phi_bb268_32, phi_bb268_33, phi_bb268_34, phi_bb268_35, phi_bb268_36, phi_bb268_38, tmp476, tmp477);
  }

  TNode<Object> phi_bb269_17;
  TNode<IntPtrT> phi_bb269_18;
  TNode<BoolT> phi_bb269_19;
  TNode<IntPtrT> phi_bb269_27;
  TNode<IntPtrT> phi_bb269_28;
  TNode<IntPtrT> phi_bb269_29;
  TNode<IntPtrT> phi_bb269_30;
  TNode<IntPtrT> phi_bb269_32;
  TNode<BoolT> phi_bb269_33;
  TNode<BoolT> phi_bb269_34;
  TNode<Object> phi_bb269_35;
  TNode<Int32T> phi_bb269_36;
  TNode<Int32T> phi_bb269_38;
  TNode<IntPtrT> tmp480;
  TNode<BoolT> tmp481;
  if (block269.is_used()) {
    ca_.Bind(&block269, &phi_bb269_17, &phi_bb269_18, &phi_bb269_19, &phi_bb269_27, &phi_bb269_28, &phi_bb269_29, &phi_bb269_30, &phi_bb269_32, &phi_bb269_33, &phi_bb269_34, &phi_bb269_35, &phi_bb269_36, &phi_bb269_38);
    tmp480 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp481 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb269_32}, TNode<IntPtrT>{tmp480});
    ca_.Branch(tmp481, &block271, std::vector<compiler::Node*>{phi_bb269_17, phi_bb269_18, phi_bb269_19, phi_bb269_27, phi_bb269_28, phi_bb269_29, phi_bb269_30, phi_bb269_32, phi_bb269_33, phi_bb269_34, phi_bb269_35, phi_bb269_36, phi_bb269_38}, &block272, std::vector<compiler::Node*>{phi_bb269_17, phi_bb269_18, phi_bb269_19, phi_bb269_27, phi_bb269_28, phi_bb269_29, phi_bb269_30, phi_bb269_32, phi_bb269_33, phi_bb269_34, phi_bb269_35, phi_bb269_36, phi_bb269_38});
  }

  TNode<Object> phi_bb271_17;
  TNode<IntPtrT> phi_bb271_18;
  TNode<BoolT> phi_bb271_19;
  TNode<IntPtrT> phi_bb271_27;
  TNode<IntPtrT> phi_bb271_28;
  TNode<IntPtrT> phi_bb271_29;
  TNode<IntPtrT> phi_bb271_30;
  TNode<IntPtrT> phi_bb271_32;
  TNode<BoolT> phi_bb271_33;
  TNode<BoolT> phi_bb271_34;
  TNode<Object> phi_bb271_35;
  TNode<Int32T> phi_bb271_36;
  TNode<Int32T> phi_bb271_38;
  TNode<Object> tmp482;
  TNode<IntPtrT> tmp483;
  TNode<IntPtrT> tmp484;
  TNode<BoolT> tmp485;
  if (block271.is_used()) {
    ca_.Bind(&block271, &phi_bb271_17, &phi_bb271_18, &phi_bb271_19, &phi_bb271_27, &phi_bb271_28, &phi_bb271_29, &phi_bb271_30, &phi_bb271_32, &phi_bb271_33, &phi_bb271_34, &phi_bb271_35, &phi_bb271_36, &phi_bb271_38);
    std::tie(tmp482, tmp483) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb271_32}).Flatten();
    tmp484 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp485 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block267, phi_bb271_17, phi_bb271_18, phi_bb271_19, phi_bb271_27, phi_bb271_28, phi_bb271_29, phi_bb271_30, tmp484, tmp485, phi_bb271_34, phi_bb271_35, phi_bb271_36, phi_bb271_38, tmp482, tmp483);
  }

  TNode<Object> phi_bb272_17;
  TNode<IntPtrT> phi_bb272_18;
  TNode<BoolT> phi_bb272_19;
  TNode<IntPtrT> phi_bb272_27;
  TNode<IntPtrT> phi_bb272_28;
  TNode<IntPtrT> phi_bb272_29;
  TNode<IntPtrT> phi_bb272_30;
  TNode<IntPtrT> phi_bb272_32;
  TNode<BoolT> phi_bb272_33;
  TNode<BoolT> phi_bb272_34;
  TNode<Object> phi_bb272_35;
  TNode<Int32T> phi_bb272_36;
  TNode<Int32T> phi_bb272_38;
  TNode<Object> tmp486;
  TNode<IntPtrT> tmp487;
  TNode<IntPtrT> tmp488;
  TNode<IntPtrT> tmp489;
  TNode<IntPtrT> tmp490;
  TNode<IntPtrT> tmp491;
  TNode<BoolT> tmp492;
  if (block272.is_used()) {
    ca_.Bind(&block272, &phi_bb272_17, &phi_bb272_18, &phi_bb272_19, &phi_bb272_27, &phi_bb272_28, &phi_bb272_29, &phi_bb272_30, &phi_bb272_32, &phi_bb272_33, &phi_bb272_34, &phi_bb272_35, &phi_bb272_36, &phi_bb272_38);
    std::tie(tmp486, tmp487) = NewReference_intptr_0(state_, TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb272_30}).Flatten();
    tmp488 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp489 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb272_30}, TNode<IntPtrT>{tmp488});
    tmp490 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp491 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp489}, TNode<IntPtrT>{tmp490});
    tmp492 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block267, phi_bb272_17, phi_bb272_18, phi_bb272_19, phi_bb272_27, phi_bb272_28, phi_bb272_29, tmp491, tmp489, tmp492, phi_bb272_34, phi_bb272_35, phi_bb272_36, phi_bb272_38, tmp486, tmp487);
  }

  TNode<Object> phi_bb267_17;
  TNode<IntPtrT> phi_bb267_18;
  TNode<BoolT> phi_bb267_19;
  TNode<IntPtrT> phi_bb267_27;
  TNode<IntPtrT> phi_bb267_28;
  TNode<IntPtrT> phi_bb267_29;
  TNode<IntPtrT> phi_bb267_30;
  TNode<IntPtrT> phi_bb267_32;
  TNode<BoolT> phi_bb267_33;
  TNode<BoolT> phi_bb267_34;
  TNode<Object> phi_bb267_35;
  TNode<Int32T> phi_bb267_36;
  TNode<Int32T> phi_bb267_38;
  TNode<Object> phi_bb267_43;
  TNode<IntPtrT> phi_bb267_44;
  if (block267.is_used()) {
    ca_.Bind(&block267, &phi_bb267_17, &phi_bb267_18, &phi_bb267_19, &phi_bb267_27, &phi_bb267_28, &phi_bb267_29, &phi_bb267_30, &phi_bb267_32, &phi_bb267_33, &phi_bb267_34, &phi_bb267_35, &phi_bb267_36, &phi_bb267_38, &phi_bb267_43, &phi_bb267_44);
    ca_.Goto(&block264, phi_bb267_17, phi_bb267_18, phi_bb267_19, phi_bb267_27, phi_bb267_28, phi_bb267_29, phi_bb267_30, phi_bb267_32, phi_bb267_33, phi_bb267_34, phi_bb267_35, phi_bb267_36, phi_bb267_38, phi_bb267_43, phi_bb267_44);
  }

  TNode<Object> phi_bb264_17;
  TNode<IntPtrT> phi_bb264_18;
  TNode<BoolT> phi_bb264_19;
  TNode<IntPtrT> phi_bb264_27;
  TNode<IntPtrT> phi_bb264_28;
  TNode<IntPtrT> phi_bb264_29;
  TNode<IntPtrT> phi_bb264_30;
  TNode<IntPtrT> phi_bb264_32;
  TNode<BoolT> phi_bb264_33;
  TNode<BoolT> phi_bb264_34;
  TNode<Object> phi_bb264_35;
  TNode<Int32T> phi_bb264_36;
  TNode<Int32T> phi_bb264_38;
  TNode<Object> phi_bb264_43;
  TNode<IntPtrT> phi_bb264_44;
  TNode<IntPtrT> tmp493;
  TNode<Int32T> tmp494;
  TNode<Int32T> tmp495;
  if (block264.is_used()) {
    ca_.Bind(&block264, &phi_bb264_17, &phi_bb264_18, &phi_bb264_19, &phi_bb264_27, &phi_bb264_28, &phi_bb264_29, &phi_bb264_30, &phi_bb264_32, &phi_bb264_33, &phi_bb264_34, &phi_bb264_35, &phi_bb264_36, &phi_bb264_38, &phi_bb264_43, &phi_bb264_44);
    tmp493 = CodeStubAssembler(state_).BitcastTaggedToWord(TNode<Object>{tmp467});
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb264_43, phi_bb264_44}, tmp493);
    tmp494 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    tmp495 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{phi_bb264_38}, TNode<Int32T>{tmp494});
    ca_.Goto(&block249, phi_bb264_17, phi_bb264_18, phi_bb264_19, tmp469, phi_bb264_27, phi_bb264_28, phi_bb264_29, phi_bb264_30, phi_bb264_32, phi_bb264_33, phi_bb264_34, phi_bb264_35, phi_bb264_36, tmp495, tmp458);
  }

  TNode<Object> phi_bb248_17;
  TNode<IntPtrT> phi_bb248_18;
  TNode<BoolT> phi_bb248_19;
  TNode<IntPtrT> phi_bb248_26;
  TNode<IntPtrT> phi_bb248_27;
  TNode<IntPtrT> phi_bb248_28;
  TNode<IntPtrT> phi_bb248_29;
  TNode<IntPtrT> phi_bb248_30;
  TNode<IntPtrT> phi_bb248_32;
  TNode<BoolT> phi_bb248_33;
  TNode<BoolT> phi_bb248_34;
  TNode<Object> phi_bb248_35;
  TNode<Int32T> phi_bb248_36;
  TNode<Int32T> phi_bb248_38;
  TNode<Int32T> phi_bb248_39;
  if (block248.is_used()) {
    ca_.Bind(&block248, &phi_bb248_17, &phi_bb248_18, &phi_bb248_19, &phi_bb248_26, &phi_bb248_27, &phi_bb248_28, &phi_bb248_29, &phi_bb248_30, &phi_bb248_32, &phi_bb248_33, &phi_bb248_34, &phi_bb248_35, &phi_bb248_36, &phi_bb248_38, &phi_bb248_39);
    ca_.Goto(&block243, phi_bb248_17, phi_bb248_18, phi_bb248_19, phi_bb248_26, phi_bb248_27, phi_bb248_28, phi_bb248_29, phi_bb248_30, phi_bb248_32, phi_bb248_33, phi_bb248_34, phi_bb248_35, phi_bb248_36);
  }

  TNode<Object> phi_bb243_17;
  TNode<IntPtrT> phi_bb243_18;
  TNode<BoolT> phi_bb243_19;
  TNode<IntPtrT> phi_bb243_26;
  TNode<IntPtrT> phi_bb243_27;
  TNode<IntPtrT> phi_bb243_28;
  TNode<IntPtrT> phi_bb243_29;
  TNode<IntPtrT> phi_bb243_30;
  TNode<IntPtrT> phi_bb243_32;
  TNode<BoolT> phi_bb243_33;
  TNode<BoolT> phi_bb243_34;
  TNode<Object> phi_bb243_35;
  TNode<Int32T> phi_bb243_36;
  TNode<RawPtrT> tmp496;
  TNode<RawPtrT> tmp497;
  if (block243.is_used()) {
    ca_.Bind(&block243, &phi_bb243_17, &phi_bb243_18, &phi_bb243_19, &phi_bb243_26, &phi_bb243_27, &phi_bb243_28, &phi_bb243_29, &phi_bb243_30, &phi_bb243_32, &phi_bb243_33, &phi_bb243_34, &phi_bb243_35, &phi_bb243_36);
    tmp496 = CodeStubAssembler(state_).GCUnsafeReferenceToRawPtr(TNode<Object>{phi_bb135_23}, TNode<IntPtrT>{phi_bb135_24});
    tmp497 = (TNode<RawPtrT>{tmp496});
    ca_.Branch(phi_bb243_33, &block275, std::vector<compiler::Node*>{phi_bb243_17, phi_bb243_18, phi_bb243_19, phi_bb243_26, phi_bb243_27, phi_bb243_28, phi_bb243_29, phi_bb243_30, phi_bb243_32, phi_bb243_33, phi_bb243_34, phi_bb243_35, phi_bb243_36, phi_bb243_30}, &block276, std::vector<compiler::Node*>{phi_bb243_17, phi_bb243_18, phi_bb243_19, phi_bb243_26, phi_bb243_27, phi_bb243_28, phi_bb243_29, phi_bb243_30, phi_bb243_32, phi_bb243_33, phi_bb243_34, phi_bb243_35, phi_bb243_36, phi_bb243_30});
  }

  TNode<Object> phi_bb275_17;
  TNode<IntPtrT> phi_bb275_18;
  TNode<BoolT> phi_bb275_19;
  TNode<IntPtrT> phi_bb275_26;
  TNode<IntPtrT> phi_bb275_27;
  TNode<IntPtrT> phi_bb275_28;
  TNode<IntPtrT> phi_bb275_29;
  TNode<IntPtrT> phi_bb275_30;
  TNode<IntPtrT> phi_bb275_32;
  TNode<BoolT> phi_bb275_33;
  TNode<BoolT> phi_bb275_34;
  TNode<Object> phi_bb275_35;
  TNode<Int32T> phi_bb275_36;
  TNode<IntPtrT> phi_bb275_39;
  TNode<IntPtrT> tmp498;
  TNode<IntPtrT> tmp499;
  if (block275.is_used()) {
    ca_.Bind(&block275, &phi_bb275_17, &phi_bb275_18, &phi_bb275_19, &phi_bb275_26, &phi_bb275_27, &phi_bb275_28, &phi_bb275_29, &phi_bb275_30, &phi_bb275_32, &phi_bb275_33, &phi_bb275_34, &phi_bb275_35, &phi_bb275_36, &phi_bb275_39);
    tmp498 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp499 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb275_39}, TNode<IntPtrT>{tmp498});
    ca_.Goto(&block276, phi_bb275_17, phi_bb275_18, phi_bb275_19, phi_bb275_26, phi_bb275_27, phi_bb275_28, phi_bb275_29, phi_bb275_30, phi_bb275_32, phi_bb275_33, phi_bb275_34, phi_bb275_35, phi_bb275_36, tmp499);
  }

  TNode<Object> phi_bb276_17;
  TNode<IntPtrT> phi_bb276_18;
  TNode<BoolT> phi_bb276_19;
  TNode<IntPtrT> phi_bb276_26;
  TNode<IntPtrT> phi_bb276_27;
  TNode<IntPtrT> phi_bb276_28;
  TNode<IntPtrT> phi_bb276_29;
  TNode<IntPtrT> phi_bb276_30;
  TNode<IntPtrT> phi_bb276_32;
  TNode<BoolT> phi_bb276_33;
  TNode<BoolT> phi_bb276_34;
  TNode<Object> phi_bb276_35;
  TNode<Int32T> phi_bb276_36;
  TNode<IntPtrT> phi_bb276_39;
  TNode<RawPtrT> tmp500;
  TNode<WasmInternalFunction> tmp501;
  TNode<IntPtrT> tmp502;
  TNode<RawPtrT> tmp503;
  TNode<RawPtrT> tmp504;
  TNode<RawPtrT> tmp505;
  TNode<IntPtrT> tmp506;
  TNode<Object> tmp507;
  TNode<IntPtrT> tmp508;
  TNode<IntPtrT> tmp509;
  TNode<Object> tmp510;
  TNode<IntPtrT> tmp511;
  TNode<IntPtrT> tmp512;
  TNode<Object> tmp513;
  TNode<IntPtrT> tmp514;
  TNode<IntPtrT> tmp515;
  TNode<Object> tmp516;
  TNode<IntPtrT> tmp517;
  TNode<IntPtrT> tmp518;
  TNode<Object> tmp519;
  TNode<IntPtrT> tmp520;
  TNode<IntPtrT> tmp521;
  TNode<Object> tmp522;
  TNode<IntPtrT> tmp523;
  TNode<IntPtrT> tmp524;
  TNode<Object> tmp525;
  TNode<IntPtrT> tmp526;
  if (block276.is_used()) {
    ca_.Bind(&block276, &phi_bb276_17, &phi_bb276_18, &phi_bb276_19, &phi_bb276_26, &phi_bb276_27, &phi_bb276_28, &phi_bb276_29, &phi_bb276_30, &phi_bb276_32, &phi_bb276_33, &phi_bb276_34, &phi_bb276_35, &phi_bb276_36, &phi_bb276_39);
    tmp500 = CodeStubAssembler(state_).GCUnsafeReferenceToRawPtr(TNode<Object>{tmp198}, TNode<IntPtrT>{phi_bb276_39});
    tmp501 = CodeStubAssembler(state_).LoadWasmInternalFunctionFromFunctionData(TNode<WasmFunctionData>{tmp2});
    tmp502 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp503 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp501, tmp502});
    tmp504 = CodeStubAssembler(state_).StackSlotPtr(JSToWasmWrapperFrameConstants::kWrapperBufferSize, (SizeOf_intptr_0(state_)));
    tmp505 = (TNode<RawPtrT>{tmp504});
    tmp506 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferReturnCount);
    std::tie(tmp507, tmp508) = GetRefAt_int32_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp505}, TNode<IntPtrT>{tmp506}).Flatten();
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{tmp507, tmp508}, tmp31);
    tmp509 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferRefReturnCount);
    std::tie(tmp510, tmp511) = GetRefAt_bool_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp505}, TNode<IntPtrT>{tmp509}).Flatten();
    CodeStubAssembler(state_).StoreReference<BoolT>(CodeStubAssembler::Reference{tmp510, tmp511}, phi_bb276_19);
    tmp512 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferSigRepresentationArray);
    std::tie(tmp513, tmp514) = GetRefAt_WasmCodePointer_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp505}, TNode<IntPtrT>{tmp512}).Flatten();
    CodeStubAssembler(state_).StoreReference<RawPtrT>(CodeStubAssembler::Reference{tmp513, tmp514}, tmp35);
    tmp515 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferStackReturnBufferSize);
    std::tie(tmp516, tmp517) = GetRefAt_intptr_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp505}, TNode<IntPtrT>{tmp515}).Flatten();
    CodeStubAssembler(state_).StoreReference<IntPtrT>(CodeStubAssembler::Reference{tmp516, tmp517}, phi_bb276_18);
    tmp518 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferCallTarget);
    std::tie(tmp519, tmp520) = GetRefAt_WasmCodePointer_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp505}, TNode<IntPtrT>{tmp518}).Flatten();
    CodeStubAssembler(state_).StoreReference<RawPtrT>(CodeStubAssembler::Reference{tmp519, tmp520}, tmp503);
    tmp521 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferParamStart);
    std::tie(tmp522, tmp523) = GetRefAt_RawPtr_intptr_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp505}, TNode<IntPtrT>{tmp521}).Flatten();
    CodeStubAssembler(state_).StoreReference<RawPtrT>(CodeStubAssembler::Reference{tmp522, tmp523}, tmp497);
    tmp524 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferParamEnd);
    std::tie(tmp525, tmp526) = GetRefAt_WasmCodePointer_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp505}, TNode<IntPtrT>{tmp524}).Flatten();
    CodeStubAssembler(state_).StoreReference<RawPtrT>(CodeStubAssembler::Reference{tmp525, tmp526}, tmp500);
    if (((CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kPromise)))) {
      ca_.Goto(&block277, phi_bb276_17, phi_bb276_18, phi_bb276_19, phi_bb276_26, phi_bb276_27, phi_bb276_28, phi_bb276_29, phi_bb276_30, phi_bb276_32, phi_bb276_33, phi_bb276_34, phi_bb276_35, phi_bb276_36);
    } else {
      ca_.Goto(&block278, phi_bb276_17, phi_bb276_18, phi_bb276_19, phi_bb276_26, phi_bb276_27, phi_bb276_28, phi_bb276_29, phi_bb276_30, phi_bb276_32, phi_bb276_33, phi_bb276_34, phi_bb276_35, phi_bb276_36);
    }
  }

  TNode<Object> phi_bb277_17;
  TNode<IntPtrT> phi_bb277_18;
  TNode<BoolT> phi_bb277_19;
  TNode<IntPtrT> phi_bb277_26;
  TNode<IntPtrT> phi_bb277_27;
  TNode<IntPtrT> phi_bb277_28;
  TNode<IntPtrT> phi_bb277_29;
  TNode<IntPtrT> phi_bb277_30;
  TNode<IntPtrT> phi_bb277_32;
  TNode<BoolT> phi_bb277_33;
  TNode<BoolT> phi_bb277_34;
  TNode<Object> phi_bb277_35;
  TNode<Int32T> phi_bb277_36;
  TNode<Object> tmp527;
  if (block277.is_used()) {
    ca_.Bind(&block277, &phi_bb277_17, &phi_bb277_18, &phi_bb277_19, &phi_bb277_26, &phi_bb277_27, &phi_bb277_28, &phi_bb277_29, &phi_bb277_30, &phi_bb277_32, &phi_bb277_33, &phi_bb277_34, &phi_bb277_35, &phi_bb277_36);
    tmp527 = ca_.CallBuiltin<Object>(Builtin::kWasmReturnPromiseOnSuspendAsm, TNode<Object>(), tmp505, tmp20, phi_bb277_17);
    ca_.Goto(&block279, phi_bb277_17, phi_bb277_18, phi_bb277_19, phi_bb277_26, phi_bb277_27, phi_bb277_28, phi_bb277_29, phi_bb277_30, phi_bb277_32, phi_bb277_33, phi_bb277_34, phi_bb277_35, phi_bb277_36, tmp527);
  }

  TNode<Object> phi_bb278_17;
  TNode<IntPtrT> phi_bb278_18;
  TNode<BoolT> phi_bb278_19;
  TNode<IntPtrT> phi_bb278_26;
  TNode<IntPtrT> phi_bb278_27;
  TNode<IntPtrT> phi_bb278_28;
  TNode<IntPtrT> phi_bb278_29;
  TNode<IntPtrT> phi_bb278_30;
  TNode<IntPtrT> phi_bb278_32;
  TNode<BoolT> phi_bb278_33;
  TNode<BoolT> phi_bb278_34;
  TNode<Object> phi_bb278_35;
  TNode<Int32T> phi_bb278_36;
  TNode<BoolT> tmp528;
  if (block278.is_used()) {
    ca_.Bind(&block278, &phi_bb278_17, &phi_bb278_18, &phi_bb278_19, &phi_bb278_26, &phi_bb278_27, &phi_bb278_28, &phi_bb278_29, &phi_bb278_30, &phi_bb278_32, &phi_bb278_33, &phi_bb278_34, &phi_bb278_35, &phi_bb278_36);
    tmp528 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kNoPromise)));
    ca_.Branch(tmp528, &block280, std::vector<compiler::Node*>{phi_bb278_17, phi_bb278_18, phi_bb278_19, phi_bb278_26, phi_bb278_27, phi_bb278_28, phi_bb278_29, phi_bb278_30, phi_bb278_32, phi_bb278_33, phi_bb278_34, phi_bb278_35, phi_bb278_36}, &block281, std::vector<compiler::Node*>{phi_bb278_17, phi_bb278_18, phi_bb278_19, phi_bb278_26, phi_bb278_27, phi_bb278_28, phi_bb278_29, phi_bb278_30, phi_bb278_32, phi_bb278_33, phi_bb278_34, phi_bb278_35, phi_bb278_36});
  }

  TNode<Object> phi_bb280_17;
  TNode<IntPtrT> phi_bb280_18;
  TNode<BoolT> phi_bb280_19;
  TNode<IntPtrT> phi_bb280_26;
  TNode<IntPtrT> phi_bb280_27;
  TNode<IntPtrT> phi_bb280_28;
  TNode<IntPtrT> phi_bb280_29;
  TNode<IntPtrT> phi_bb280_30;
  TNode<IntPtrT> phi_bb280_32;
  TNode<BoolT> phi_bb280_33;
  TNode<BoolT> phi_bb280_34;
  TNode<Object> phi_bb280_35;
  TNode<Int32T> phi_bb280_36;
  TNode<Object> tmp529;
  if (block280.is_used()) {
    ca_.Bind(&block280, &phi_bb280_17, &phi_bb280_18, &phi_bb280_19, &phi_bb280_26, &phi_bb280_27, &phi_bb280_28, &phi_bb280_29, &phi_bb280_30, &phi_bb280_32, &phi_bb280_33, &phi_bb280_34, &phi_bb280_35, &phi_bb280_36);
    tmp529 = ca_.CallBuiltin<Object>(Builtin::kJSToWasmWrapperAsm, TNode<Object>(), tmp505, tmp20, phi_bb280_17);
    ca_.Goto(&block282, phi_bb280_17, phi_bb280_18, phi_bb280_19, phi_bb280_26, phi_bb280_27, phi_bb280_28, phi_bb280_29, phi_bb280_30, phi_bb280_32, phi_bb280_33, phi_bb280_34, phi_bb280_35, phi_bb280_36, tmp529);
  }

  TNode<Object> phi_bb281_17;
  TNode<IntPtrT> phi_bb281_18;
  TNode<BoolT> phi_bb281_19;
  TNode<IntPtrT> phi_bb281_26;
  TNode<IntPtrT> phi_bb281_27;
  TNode<IntPtrT> phi_bb281_28;
  TNode<IntPtrT> phi_bb281_29;
  TNode<IntPtrT> phi_bb281_30;
  TNode<IntPtrT> phi_bb281_32;
  TNode<BoolT> phi_bb281_33;
  TNode<BoolT> phi_bb281_34;
  TNode<Object> phi_bb281_35;
  TNode<Int32T> phi_bb281_36;
  TNode<BoolT> tmp530;
  if (block281.is_used()) {
    ca_.Bind(&block281, &phi_bb281_17, &phi_bb281_18, &phi_bb281_19, &phi_bb281_26, &phi_bb281_27, &phi_bb281_28, &phi_bb281_29, &phi_bb281_30, &phi_bb281_32, &phi_bb281_33, &phi_bb281_34, &phi_bb281_35, &phi_bb281_36);
    tmp530 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt32Equal(p_promise, wasm::Promise::kStressSwitch)));
    ca_.Branch(tmp530, &block283, std::vector<compiler::Node*>{phi_bb281_17, phi_bb281_18, phi_bb281_19, phi_bb281_26, phi_bb281_27, phi_bb281_28, phi_bb281_29, phi_bb281_30, phi_bb281_32, phi_bb281_33, phi_bb281_34, phi_bb281_35, phi_bb281_36}, &block284, std::vector<compiler::Node*>{phi_bb281_17, phi_bb281_18, phi_bb281_19, phi_bb281_26, phi_bb281_27, phi_bb281_28, phi_bb281_29, phi_bb281_30, phi_bb281_32, phi_bb281_33, phi_bb281_34, phi_bb281_35, phi_bb281_36});
  }

  TNode<Object> phi_bb283_17;
  TNode<IntPtrT> phi_bb283_18;
  TNode<BoolT> phi_bb283_19;
  TNode<IntPtrT> phi_bb283_26;
  TNode<IntPtrT> phi_bb283_27;
  TNode<IntPtrT> phi_bb283_28;
  TNode<IntPtrT> phi_bb283_29;
  TNode<IntPtrT> phi_bb283_30;
  TNode<IntPtrT> phi_bb283_32;
  TNode<BoolT> phi_bb283_33;
  TNode<BoolT> phi_bb283_34;
  TNode<Object> phi_bb283_35;
  TNode<Int32T> phi_bb283_36;
  TNode<Object> tmp531;
  if (block283.is_used()) {
    ca_.Bind(&block283, &phi_bb283_17, &phi_bb283_18, &phi_bb283_19, &phi_bb283_26, &phi_bb283_27, &phi_bb283_28, &phi_bb283_29, &phi_bb283_30, &phi_bb283_32, &phi_bb283_33, &phi_bb283_34, &phi_bb283_35, &phi_bb283_36);
    tmp531 = ca_.CallBuiltin<Object>(Builtin::kJSToWasmStressSwitchStacksAsm, TNode<Object>(), tmp505, tmp20, phi_bb283_17);
    ca_.Goto(&block282, phi_bb283_17, phi_bb283_18, phi_bb283_19, phi_bb283_26, phi_bb283_27, phi_bb283_28, phi_bb283_29, phi_bb283_30, phi_bb283_32, phi_bb283_33, phi_bb283_34, phi_bb283_35, phi_bb283_36, tmp531);
  }

  TNode<Object> phi_bb284_17;
  TNode<IntPtrT> phi_bb284_18;
  TNode<BoolT> phi_bb284_19;
  TNode<IntPtrT> phi_bb284_26;
  TNode<IntPtrT> phi_bb284_27;
  TNode<IntPtrT> phi_bb284_28;
  TNode<IntPtrT> phi_bb284_29;
  TNode<IntPtrT> phi_bb284_30;
  TNode<IntPtrT> phi_bb284_32;
  TNode<BoolT> phi_bb284_33;
  TNode<BoolT> phi_bb284_34;
  TNode<Object> phi_bb284_35;
  TNode<Int32T> phi_bb284_36;
  if (block284.is_used()) {
    ca_.Bind(&block284, &phi_bb284_17, &phi_bb284_18, &phi_bb284_19, &phi_bb284_26, &phi_bb284_27, &phi_bb284_28, &phi_bb284_29, &phi_bb284_30, &phi_bb284_32, &phi_bb284_33, &phi_bb284_34, &phi_bb284_35, &phi_bb284_36);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Object> phi_bb282_17;
  TNode<IntPtrT> phi_bb282_18;
  TNode<BoolT> phi_bb282_19;
  TNode<IntPtrT> phi_bb282_26;
  TNode<IntPtrT> phi_bb282_27;
  TNode<IntPtrT> phi_bb282_28;
  TNode<IntPtrT> phi_bb282_29;
  TNode<IntPtrT> phi_bb282_30;
  TNode<IntPtrT> phi_bb282_32;
  TNode<BoolT> phi_bb282_33;
  TNode<BoolT> phi_bb282_34;
  TNode<Object> phi_bb282_35;
  TNode<Int32T> phi_bb282_36;
  TNode<Object> phi_bb282_42;
  if (block282.is_used()) {
    ca_.Bind(&block282, &phi_bb282_17, &phi_bb282_18, &phi_bb282_19, &phi_bb282_26, &phi_bb282_27, &phi_bb282_28, &phi_bb282_29, &phi_bb282_30, &phi_bb282_32, &phi_bb282_33, &phi_bb282_34, &phi_bb282_35, &phi_bb282_36, &phi_bb282_42);
    ca_.Goto(&block279, phi_bb282_17, phi_bb282_18, phi_bb282_19, phi_bb282_26, phi_bb282_27, phi_bb282_28, phi_bb282_29, phi_bb282_30, phi_bb282_32, phi_bb282_33, phi_bb282_34, phi_bb282_35, phi_bb282_36, phi_bb282_42);
  }

  TNode<Object> phi_bb279_17;
  TNode<IntPtrT> phi_bb279_18;
  TNode<BoolT> phi_bb279_19;
  TNode<IntPtrT> phi_bb279_26;
  TNode<IntPtrT> phi_bb279_27;
  TNode<IntPtrT> phi_bb279_28;
  TNode<IntPtrT> phi_bb279_29;
  TNode<IntPtrT> phi_bb279_30;
  TNode<IntPtrT> phi_bb279_32;
  TNode<BoolT> phi_bb279_33;
  TNode<BoolT> phi_bb279_34;
  TNode<Object> phi_bb279_35;
  TNode<Int32T> phi_bb279_36;
  TNode<Object> phi_bb279_42;
  if (block279.is_used()) {
    ca_.Bind(&block279, &phi_bb279_17, &phi_bb279_18, &phi_bb279_19, &phi_bb279_26, &phi_bb279_27, &phi_bb279_28, &phi_bb279_29, &phi_bb279_30, &phi_bb279_32, &phi_bb279_33, &phi_bb279_34, &phi_bb279_35, &phi_bb279_36, &phi_bb279_42);
    ca_.Goto(&block286, phi_bb279_42);
  }

  TNode<Object> phi_bb286_7;
    ca_.Bind(&block286, &phi_bb286_7);
  return TNode<Object>{phi_bb286_7};
}

TF_BUILTIN(JSToWasmWrapper, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Word32T> argc = UncheckedParameter<Word32T>(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(UncheckedCast<Int32T>(argc)));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length, FrameArgumentsArgcType::kCountIncludesReceiver));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
  USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
USE(parameter2);
  TNode<JSDispatchHandleT> parameter3 = InvalidDispatchHandleConstant();
USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    CodeStubAssembler(state_).SetSupportsDynamicParameterCount(TNode<JSFunction>{parameter2}, TNode<JSDispatchHandleT>{parameter3});
    tmp0 = JSToWasmWrapperHelper_0(state_, TNode<NativeContext>{parameter0}, TNode<Object>{parameter1}, TNode<JSFunction>{parameter2}, TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, wasm::Promise::kNoPromise);
    arguments.PopAndReturn(tmp0);
  }
}

TF_BUILTIN(WasmPromising, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Word32T> argc = UncheckedParameter<Word32T>(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(UncheckedCast<Int32T>(argc)));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length, FrameArgumentsArgcType::kCountIncludesReceiver));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
  USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
USE(parameter2);
  TNode<JSDispatchHandleT> parameter3 = InvalidDispatchHandleConstant();
USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    CodeStubAssembler(state_).SetSupportsDynamicParameterCount(TNode<JSFunction>{parameter2}, TNode<JSDispatchHandleT>{parameter3});
    tmp0 = JSToWasmWrapperHelper_0(state_, TNode<NativeContext>{parameter0}, TNode<Object>{parameter1}, TNode<JSFunction>{parameter2}, TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, wasm::Promise::kPromise);
    arguments.PopAndReturn(tmp0);
  }
}

TF_BUILTIN(WasmStressSwitch, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Word32T> argc = UncheckedParameter<Word32T>(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(UncheckedCast<Int32T>(argc)));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length, FrameArgumentsArgcType::kCountIncludesReceiver));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
  USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedParameter<JSFunction>(Descriptor::kJSTarget);
USE(parameter2);
  TNode<JSDispatchHandleT> parameter3 = InvalidDispatchHandleConstant();
USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    CodeStubAssembler(state_).SetSupportsDynamicParameterCount(TNode<JSFunction>{parameter2}, TNode<JSDispatchHandleT>{parameter3});
    tmp0 = JSToWasmWrapperHelper_0(state_, TNode<NativeContext>{parameter0}, TNode<Object>{parameter1}, TNode<JSFunction>{parameter2}, TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, wasm::Promise::kStressSwitch);
    arguments.PopAndReturn(tmp0);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=797&c=1
TNode<Object> WasmToJSObject_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<Object> p_value, TNode<Int32T> p_retType) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block69(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block73(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  TNode<Int32T> tmp2;
  TNode<Int32T> tmp3;
  TNode<Int32T> tmp4;
  TNode<Int32T> tmp5;
  TNode<Int32T> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    tmp1 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{p_retType}, TNode<Int32T>{tmp0});
    tmp2 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueType::kKindBits);
    tmp3 = CodeStubAssembler(state_).Word32Sar(TNode<Int32T>{p_retType}, TNode<Int32T>{tmp2});
    tmp4 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmHeapTypeBitsMask);
    tmp5 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp3}, TNode<Int32T>{tmp4});
    tmp6 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    tmp7 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp6});
    ca_.Branch(tmp7, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<Int32T> tmp8;
  TNode<BoolT> tmp9;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp8 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kEq);
    tmp9 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp8});
    ca_.Branch(tmp9, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp10;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block9, tmp10);
  }

  TNode<Int32T> tmp11;
  TNode<BoolT> tmp12;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp11 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kI31);
    tmp12 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp11});
    ca_.Goto(&block9, tmp12);
  }

  TNode<BoolT> phi_bb9_6;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_6);
    ca_.Branch(phi_bb9_6, &block10, std::vector<compiler::Node*>{}, &block11, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp13;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block12, tmp13);
  }

  TNode<Int32T> tmp14;
  TNode<BoolT> tmp15;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp14 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kStruct);
    tmp15 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp14});
    ca_.Goto(&block12, tmp15);
  }

  TNode<BoolT> phi_bb12_6;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_6);
    ca_.Branch(phi_bb12_6, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp16;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp16 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block15, tmp16);
  }

  TNode<Int32T> tmp17;
  TNode<BoolT> tmp18;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp17 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kArray);
    tmp18 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp17});
    ca_.Goto(&block15, tmp18);
  }

  TNode<BoolT> phi_bb15_6;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_6);
    ca_.Branch(phi_bb15_6, &block16, std::vector<compiler::Node*>{}, &block17, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp19;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp19 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block18, tmp19);
  }

  TNode<Int32T> tmp20;
  TNode<BoolT> tmp21;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp20 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kAny);
    tmp21 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp20});
    ca_.Goto(&block18, tmp21);
  }

  TNode<BoolT> phi_bb18_6;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_6);
    ca_.Branch(phi_bb18_6, &block19, std::vector<compiler::Node*>{}, &block20, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp22;
  if (block19.is_used()) {
    ca_.Bind(&block19);
    tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block21, tmp22);
  }

  TNode<Int32T> tmp23;
  TNode<BoolT> tmp24;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp23 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kExtern);
    tmp24 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp23});
    ca_.Goto(&block21, tmp24);
  }

  TNode<BoolT> phi_bb21_6;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_6);
    ca_.Branch(phi_bb21_6, &block22, std::vector<compiler::Node*>{}, &block23, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp25;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp25 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block24, tmp25);
  }

  TNode<Int32T> tmp26;
  TNode<BoolT> tmp27;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp26 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kString);
    tmp27 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp26});
    ca_.Goto(&block24, tmp27);
  }

  TNode<BoolT> phi_bb24_6;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_6);
    ca_.Branch(phi_bb24_6, &block25, std::vector<compiler::Node*>{}, &block26, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp28;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    tmp28 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block27, tmp28);
  }

  TNode<Int32T> tmp29;
  TNode<BoolT> tmp30;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    tmp29 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kNone);
    tmp30 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp29});
    ca_.Goto(&block27, tmp30);
  }

  TNode<BoolT> phi_bb27_6;
  if (block27.is_used()) {
    ca_.Bind(&block27, &phi_bb27_6);
    ca_.Branch(phi_bb27_6, &block28, std::vector<compiler::Node*>{}, &block29, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp31;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    tmp31 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block30, tmp31);
  }

  TNode<Int32T> tmp32;
  TNode<BoolT> tmp33;
  if (block29.is_used()) {
    ca_.Bind(&block29);
    tmp32 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kNoFunc);
    tmp33 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp32});
    ca_.Goto(&block30, tmp33);
  }

  TNode<BoolT> phi_bb30_6;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_6);
    ca_.Branch(phi_bb30_6, &block31, std::vector<compiler::Node*>{}, &block32, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp34;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    tmp34 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block33, tmp34);
  }

  TNode<Int32T> tmp35;
  TNode<BoolT> tmp36;
  if (block32.is_used()) {
    ca_.Bind(&block32);
    tmp35 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kNoExtern);
    tmp36 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp35});
    ca_.Goto(&block33, tmp36);
  }

  TNode<BoolT> phi_bb33_6;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_6);
    ca_.Branch(phi_bb33_6, &block34, std::vector<compiler::Node*>{}, &block35, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp37;
  if (block34.is_used()) {
    ca_.Bind(&block34);
    tmp37 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block36, tmp37);
  }

  TNode<Int32T> tmp38;
  TNode<BoolT> tmp39;
  if (block35.is_used()) {
    ca_.Bind(&block35);
    tmp38 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kExn);
    tmp39 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp38});
    ca_.Goto(&block36, tmp39);
  }

  TNode<BoolT> phi_bb36_6;
  if (block36.is_used()) {
    ca_.Bind(&block36, &phi_bb36_6);
    ca_.Branch(phi_bb36_6, &block37, std::vector<compiler::Node*>{}, &block38, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp40;
  if (block37.is_used()) {
    ca_.Bind(&block37);
    tmp40 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block39, tmp40);
  }

  TNode<Int32T> tmp41;
  TNode<BoolT> tmp42;
  if (block38.is_used()) {
    ca_.Bind(&block38);
    tmp41 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kNoExn);
    tmp42 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp41});
    ca_.Goto(&block39, tmp42);
  }

  TNode<BoolT> phi_bb39_6;
  if (block39.is_used()) {
    ca_.Bind(&block39, &phi_bb39_6);
    ca_.Branch(phi_bb39_6, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp43;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp43 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{p_value});
    ca_.Goto(&block1, tmp43);
  }

  TNode<Object> tmp44;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp44 = CodeStubAssembler(state_).CallRuntime(Runtime::kWasmGenericWasmToJSObject, p_context, p_value); 
    ca_.Goto(&block1, tmp44);
  }

  TNode<Int32T> tmp45;
  TNode<BoolT> tmp46;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp45 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kExtern);
    tmp46 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp45});
    ca_.Branch(tmp46, &block46, std::vector<compiler::Node*>{}, &block47, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp47;
  if (block46.is_used()) {
    ca_.Bind(&block46);
    tmp47 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block48, tmp47);
  }

  TNode<Int32T> tmp48;
  TNode<BoolT> tmp49;
  if (block47.is_used()) {
    ca_.Bind(&block47);
    tmp48 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kNoExtern);
    tmp49 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp48});
    ca_.Goto(&block48, tmp49);
  }

  TNode<BoolT> phi_bb48_6;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_6);
    ca_.Branch(phi_bb48_6, &block49, std::vector<compiler::Node*>{}, &block50, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp50;
  if (block49.is_used()) {
    ca_.Bind(&block49);
    tmp50 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block51, tmp50);
  }

  TNode<Int32T> tmp51;
  TNode<BoolT> tmp52;
  if (block50.is_used()) {
    ca_.Bind(&block50);
    tmp51 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kExn);
    tmp52 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp51});
    ca_.Goto(&block51, tmp52);
  }

  TNode<BoolT> phi_bb51_6;
  if (block51.is_used()) {
    ca_.Bind(&block51, &phi_bb51_6);
    ca_.Branch(phi_bb51_6, &block52, std::vector<compiler::Node*>{}, &block53, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp53;
  if (block52.is_used()) {
    ca_.Bind(&block52);
    tmp53 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block54, tmp53);
  }

  TNode<Int32T> tmp54;
  TNode<BoolT> tmp55;
  if (block53.is_used()) {
    ca_.Bind(&block53);
    tmp54 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kNoExn);
    tmp55 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp54});
    ca_.Goto(&block54, tmp55);
  }

  TNode<BoolT> phi_bb54_6;
  if (block54.is_used()) {
    ca_.Bind(&block54, &phi_bb54_6);
    ca_.Branch(phi_bb54_6, &block44, std::vector<compiler::Node*>{}, &block45, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp56;
  if (block44.is_used()) {
    ca_.Bind(&block44);
    tmp56 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{p_value});
    ca_.Goto(&block1, tmp56);
  }

  TNode<WasmNull> tmp57;
  TNode<BoolT> tmp58;
  if (block45.is_used()) {
    ca_.Bind(&block45);
    tmp57 = kWasmNull_0(state_);
    tmp58 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{p_value}, TNode<HeapObject>{tmp57});
    ca_.Branch(tmp58, &block55, std::vector<compiler::Node*>{}, &block56, std::vector<compiler::Node*>{});
  }

  TNode<Null> tmp59;
  if (block55.is_used()) {
    ca_.Bind(&block55);
    tmp59 = Null_0(state_);
    ca_.Goto(&block1, tmp59);
  }

  TNode<Int32T> tmp60;
  TNode<BoolT> tmp61;
  if (block56.is_used()) {
    ca_.Bind(&block56);
    tmp60 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kEq);
    tmp61 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp60});
    ca_.Branch(tmp61, &block59, std::vector<compiler::Node*>{}, &block60, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp62;
  if (block59.is_used()) {
    ca_.Bind(&block59);
    tmp62 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block61, tmp62);
  }

  TNode<Int32T> tmp63;
  TNode<BoolT> tmp64;
  if (block60.is_used()) {
    ca_.Bind(&block60);
    tmp63 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kStruct);
    tmp64 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp63});
    ca_.Goto(&block61, tmp64);
  }

  TNode<BoolT> phi_bb61_6;
  if (block61.is_used()) {
    ca_.Bind(&block61, &phi_bb61_6);
    ca_.Branch(phi_bb61_6, &block62, std::vector<compiler::Node*>{}, &block63, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp65;
  if (block62.is_used()) {
    ca_.Bind(&block62);
    tmp65 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block64, tmp65);
  }

  TNode<Int32T> tmp66;
  TNode<BoolT> tmp67;
  if (block63.is_used()) {
    ca_.Bind(&block63);
    tmp66 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kArray);
    tmp67 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp66});
    ca_.Goto(&block64, tmp67);
  }

  TNode<BoolT> phi_bb64_6;
  if (block64.is_used()) {
    ca_.Bind(&block64, &phi_bb64_6);
    ca_.Branch(phi_bb64_6, &block65, std::vector<compiler::Node*>{}, &block66, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp68;
  if (block65.is_used()) {
    ca_.Bind(&block65);
    tmp68 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block67, tmp68);
  }

  TNode<Int32T> tmp69;
  TNode<BoolT> tmp70;
  if (block66.is_used()) {
    ca_.Bind(&block66);
    tmp69 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kString);
    tmp70 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp69});
    ca_.Goto(&block67, tmp70);
  }

  TNode<BoolT> phi_bb67_6;
  if (block67.is_used()) {
    ca_.Bind(&block67, &phi_bb67_6);
    ca_.Branch(phi_bb67_6, &block68, std::vector<compiler::Node*>{}, &block69, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp71;
  if (block68.is_used()) {
    ca_.Bind(&block68);
    tmp71 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block70, tmp71);
  }

  TNode<Int32T> tmp72;
  TNode<BoolT> tmp73;
  if (block69.is_used()) {
    ca_.Bind(&block69);
    tmp72 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kI31);
    tmp73 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp72});
    ca_.Goto(&block70, tmp73);
  }

  TNode<BoolT> phi_bb70_6;
  if (block70.is_used()) {
    ca_.Bind(&block70, &phi_bb70_6);
    ca_.Branch(phi_bb70_6, &block71, std::vector<compiler::Node*>{}, &block72, std::vector<compiler::Node*>{});
  }

  TNode<BoolT> tmp74;
  if (block71.is_used()) {
    ca_.Bind(&block71);
    tmp74 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block73, tmp74);
  }

  TNode<Int32T> tmp75;
  TNode<BoolT> tmp76;
  if (block72.is_used()) {
    ca_.Bind(&block72);
    tmp75 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::HeapType::Representation::kAny);
    tmp76 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp75});
    ca_.Goto(&block73, tmp76);
  }

  TNode<BoolT> phi_bb73_6;
  if (block73.is_used()) {
    ca_.Bind(&block73, &phi_bb73_6);
    ca_.Branch(phi_bb73_6, &block57, std::vector<compiler::Node*>{}, &block58, std::vector<compiler::Node*>{});
  }

  TNode<Object> tmp77;
  if (block57.is_used()) {
    ca_.Bind(&block57);
    tmp77 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{p_value});
    ca_.Goto(&block1, tmp77);
  }

  TNode<Object> tmp78;
  if (block58.is_used()) {
    ca_.Bind(&block58);
    tmp78 = CodeStubAssembler(state_).CallRuntime(Runtime::kWasmGenericWasmToJSObject, p_context, p_value); 
    ca_.Goto(&block1, tmp78);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block74, phi_bb1_3);
  }

  TNode<Object> phi_bb74_3;
    ca_.Bind(&block74, &phi_bb74_3);
  return TNode<Object>{phi_bb74_3};
}

TF_BUILTIN(JSToWasmHandleReturns, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kJsContext);
  USE(parameter0);
  TNode<JSArray> parameter1 = UncheckedParameter<JSArray>(Descriptor::kResultArray);
  USE(parameter1);
  TNode<RawPtrT> parameter2 = UncheckedParameter<RawPtrT>(Descriptor::kWrapperBuffer);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block69(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block73(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block77(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block78(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block80(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block81(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block84(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block79(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block76(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block85(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block89(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block90(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block92(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block93(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block95(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block96(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block91(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block88(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block86(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block87(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block97(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block100(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block101(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block102(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block106(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block107(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block109(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block110(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block105(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block103(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block99(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block98(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block75(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block112(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block113(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block116(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block114(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block121(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block122(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, BoolT> block123(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block119(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block125(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block126(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block128(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block129(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block131(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block132(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block127(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block124(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block137(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block138(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block120(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block115(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block143(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block141(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block146(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block150(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block151(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block153(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block154(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block156(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block157(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block152(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block149(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block158(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block159(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, Int32T> block160(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block165(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block166(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block147(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block169(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block173(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block174(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block176(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block177(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block179(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block180(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block175(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block172(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block181(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block184(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block185(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, Float32T> block187(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block182(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block188(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block191(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block192(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, Float32T> block194(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block189(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, Float32T> block190(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, Float32T> block183(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block199(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block200(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block170(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block203(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block206(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block210(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block211(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block213(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block214(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block216(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block217(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block212(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block209(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block222(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block223(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block207(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block227(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block228(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block230(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block231(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block233(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block234(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block229(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block226(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block236(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block237(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block239(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block240(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block242(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block243(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, Object, IntPtrT> block238(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, Object, IntPtrT> block235(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, Object, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block248(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, Object, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block249(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block208(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block204(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block252(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block256(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block257(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block258(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block262(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block263(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block265(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block266(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block261(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block259(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT> block255(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block271(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, Object, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block272(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block253(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block279(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block280(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block287(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block288(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block254(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block205(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block171(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block148(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, BoolT, IntPtrT> block142(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Int32T> tmp3;
  TNode<Int32T> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferReturnCount);
    std::tie(tmp1, tmp2) = GetRefAt_int32_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp3 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp1, tmp2});
    tmp4 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp5 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp3}, TNode<Int32T>{tmp4});
    ca_.Branch(tmp5, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Undefined> tmp6;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp6 = Undefined_0(state_);
    CodeStubAssembler(state_).Return(tmp6);
  }

  TNode<Int32T> tmp7;
  TNode<BoolT> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp7 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp8 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp3}, TNode<Int32T>{tmp7});
    ca_.Branch(tmp8, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp9;
  TNode<Object> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<RawPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<Object> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<Int32T> tmp16;
  TNode<Int32T> tmp17;
  TNode<BoolT> tmp18;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp9 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferSigRepresentationArray);
    std::tie(tmp10, tmp11) = GetRefAt_WasmCodePointer_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp9}).Flatten();
    tmp12 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp10, tmp11});
    tmp13 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    std::tie(tmp14, tmp15) = GetRefAt_int32_WasmCodePointer_0(state_, TNode<RawPtrT>{tmp12}, TNode<IntPtrT>{tmp13}).Flatten();
    tmp16 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp14, tmp15});
    tmp17 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI32.raw_bit_field());
    tmp18 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp16}, TNode<Int32T>{tmp17});
    ca_.Branch(tmp18, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    if ((wasm::kIsBigEndian)) {
      ca_.Goto(&block8);
    } else {
      ca_.Goto(&block9);
    }
  }

  TNode<IntPtrT> tmp19;
  TNode<Object> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Int64T> tmp22;
  TNode<Int32T> tmp23;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp19 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister1);
    std::tie(tmp20, tmp21) = GetRefAt_int64_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp19}).Flatten();
    tmp22 = CodeStubAssembler(state_).LoadReference<Int64T>(CodeStubAssembler::Reference{tmp20, tmp21});
    tmp23 = CodeStubAssembler(state_).TruncateInt64ToInt32(TNode<Int64T>{tmp22});
    ca_.Goto(&block10, tmp23);
  }

  TNode<IntPtrT> tmp24;
  TNode<Object> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<Int32T> tmp27;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp24 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister1);
    std::tie(tmp25, tmp26) = GetRefAt_int32_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp24}).Flatten();
    tmp27 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp25, tmp26});
    ca_.Goto(&block10, tmp27);
  }

  TNode<Int32T> phi_bb10_6;
  TNode<Number> tmp28;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_6);
    tmp28 = Convert_Number_int32_0(state_, TNode<Int32T>{phi_bb10_6});
    CodeStubAssembler(state_).Return(tmp28);
  }

  TNode<Int32T> tmp29;
  TNode<BoolT> tmp30;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp29 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF32.raw_bit_field());
    tmp30 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp16}, TNode<Int32T>{tmp29});
    ca_.Branch(tmp30, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    if ((wasm::kIsFpAlwaysDouble)) {
      ca_.Goto(&block14);
    } else {
      ca_.Goto(&block15);
    }
  }

  TNode<IntPtrT> tmp31;
  TNode<Object> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<Float64T> tmp34;
  TNode<Float32T> tmp35;
  TNode<Number> tmp36;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp31 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferFPReturnRegister1);
    std::tie(tmp32, tmp33) = GetRefAt_float64_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp31}).Flatten();
    tmp34 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp32, tmp33});
    tmp35 = CodeStubAssembler(state_).TruncateFloat64ToFloat32(TNode<Float64T>{tmp34});
    tmp36 = Convert_Number_float32_0(state_, TNode<Float32T>{tmp35});
    CodeStubAssembler(state_).Return(tmp36);
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    if ((wasm::kIsBigEndianOnSim)) {
      ca_.Goto(&block17);
    } else {
      ca_.Goto(&block18);
    }
  }

  TNode<IntPtrT> tmp37;
  TNode<Object> tmp38;
  TNode<IntPtrT> tmp39;
  TNode<Int64T> tmp40;
  TNode<Int64T> tmp41;
  TNode<Int64T> tmp42;
  TNode<Int32T> tmp43;
  TNode<Float32T> tmp44;
  TNode<Number> tmp45;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp37 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferFPReturnRegister1);
    std::tie(tmp38, tmp39) = GetRefAt_int64_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp37}).Flatten();
    tmp40 = CodeStubAssembler(state_).LoadReference<Int64T>(CodeStubAssembler::Reference{tmp38, tmp39});
    tmp41 = FromConstexpr_int64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x20ull));
    tmp42 = CodeStubAssembler(state_).Word64Sar(TNode<Int64T>{tmp40}, TNode<Int64T>{tmp41});
    tmp43 = CodeStubAssembler(state_).TruncateInt64ToInt32(TNode<Int64T>{tmp42});
    tmp44 = CodeStubAssembler(state_).BitcastInt32ToFloat32(TNode<Int32T>{tmp43});
    tmp45 = Convert_Number_float32_0(state_, TNode<Float32T>{tmp44});
    CodeStubAssembler(state_).Return(tmp45);
  }

  TNode<IntPtrT> tmp46;
  TNode<Object> tmp47;
  TNode<IntPtrT> tmp48;
  TNode<Float32T> tmp49;
  TNode<Number> tmp50;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp46 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferFPReturnRegister1);
    std::tie(tmp47, tmp48) = GetRefAt_float32_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp46}).Flatten();
    tmp49 = CodeStubAssembler(state_).LoadReference<Float32T>(CodeStubAssembler::Reference{tmp47, tmp48});
    tmp50 = Convert_Number_float32_0(state_, TNode<Float32T>{tmp49});
    CodeStubAssembler(state_).Return(tmp50);
  }

  TNode<Int32T> tmp51;
  TNode<BoolT> tmp52;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp51 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF64.raw_bit_field());
    tmp52 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp16}, TNode<Int32T>{tmp51});
    ca_.Branch(tmp52, &block20, std::vector<compiler::Node*>{}, &block21, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp53;
  TNode<Object> tmp54;
  TNode<IntPtrT> tmp55;
  TNode<Float64T> tmp56;
  TNode<Number> tmp57;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp53 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferFPReturnRegister1);
    std::tie(tmp54, tmp55) = GetRefAt_float64_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp53}).Flatten();
    tmp56 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp54, tmp55});
    tmp57 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp56});
    CodeStubAssembler(state_).Return(tmp57);
  }

  TNode<Int32T> tmp58;
  TNode<BoolT> tmp59;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp58 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI64.raw_bit_field());
    tmp59 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp16}, TNode<Int32T>{tmp58});
    ca_.Branch(tmp59, &block23, std::vector<compiler::Node*>{}, &block24, std::vector<compiler::Node*>{});
  }

  if (block23.is_used()) {
    ca_.Bind(&block23);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block26);
    } else {
      ca_.Goto(&block27);
    }
  }

  TNode<IntPtrT> tmp60;
  TNode<Object> tmp61;
  TNode<IntPtrT> tmp62;
  TNode<IntPtrT> tmp63;
  TNode<BigInt> tmp64;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    tmp60 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister1);
    std::tie(tmp61, tmp62) = GetRefAt_intptr_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp60}).Flatten();
    tmp63 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{tmp61, tmp62});
    tmp64 = ca_.CallBuiltin<BigInt>(Builtin::kI64ToBigInt, TNode<Object>(), tmp63);
    CodeStubAssembler(state_).Return(tmp64);
  }

  TNode<IntPtrT> tmp65;
  TNode<Object> tmp66;
  TNode<IntPtrT> tmp67;
  TNode<IntPtrT> tmp68;
  TNode<IntPtrT> tmp69;
  TNode<Object> tmp70;
  TNode<IntPtrT> tmp71;
  TNode<IntPtrT> tmp72;
  TNode<BigInt> tmp73;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    tmp65 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister1);
    std::tie(tmp66, tmp67) = GetRefAt_intptr_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp65}).Flatten();
    tmp68 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{tmp66, tmp67});
    tmp69 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister2);
    std::tie(tmp70, tmp71) = GetRefAt_intptr_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp69}).Flatten();
    tmp72 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{tmp70, tmp71});
    tmp73 = ca_.CallBuiltin<BigInt>(Builtin::kI32PairToBigInt, TNode<Object>(), tmp68, tmp72);
    CodeStubAssembler(state_).Return(tmp73);
  }

  TNode<IntPtrT> tmp74;
  TNode<RawPtrT> tmp75;
  TNode<RawPtrT> tmp76;
  TNode<IntPtrT> tmp77;
  TNode<Object> tmp78;
  TNode<IntPtrT> tmp79;
  TNode<UintPtrT> tmp80;
  TNode<Object> tmp81;
  TNode<Object> tmp82;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    tmp74 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister1);
    tmp75 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp74});
    tmp76 = (TNode<RawPtrT>{tmp75});
    tmp77 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    std::tie(tmp78, tmp79) = GetRefAt_uintptr_RawPtr_uintptr_0(state_, TNode<RawPtrT>{tmp76}, TNode<IntPtrT>{tmp77}).Flatten();
    tmp80 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp78, tmp79});
    tmp81 = CodeStubAssembler(state_).BitcastWordToTagged(TNode<UintPtrT>{tmp80});
    tmp82 = WasmToJSObject_0(state_, TNode<NativeContext>{parameter0}, TNode<Object>{tmp81}, TNode<Int32T>{tmp16});
    CodeStubAssembler(state_).Return(tmp82);
  }

  TNode<IntPtrT> tmp83;
  TNode<FixedArrayBase> tmp84;
  TNode<FixedArray> tmp85;
  TNode<IntPtrT> tmp86;
  TNode<Object> tmp87;
  TNode<IntPtrT> tmp88;
  TNode<RawPtrT> tmp89;
  TNode<IntPtrT> tmp90;
  TNode<RawPtrT> tmp91;
  TNode<IntPtrT> tmp92;
  TNode<RawPtrT> tmp93;
  TNode<Object> tmp94;
  TNode<IntPtrT> tmp95;
  TNode<IntPtrT> tmp96;
  TNode<IntPtrT> tmp97;
  TNode<IntPtrT> tmp98;
  TNode<IntPtrT> tmp99;
  TNode<IntPtrT> tmp100;
  TNode<IntPtrT> tmp101;
  TNode<BoolT> tmp102;
  TNode<IntPtrT> tmp103;
  TNode<Object> tmp104;
  TNode<IntPtrT> tmp105;
  TNode<RawPtrT> tmp106;
  TNode<RawPtrT> tmp107;
  TNode<IntPtrT> tmp108;
  TNode<Object> tmp109;
  TNode<IntPtrT> tmp110;
  TNode<IntPtrT> tmp111;
  TNode<IntPtrT> tmp112;
  TNode<Object> tmp113;
  TNode<IntPtrT> tmp114;
  TNode<BoolT> tmp115;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp83 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp84 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{parameter1, tmp83});
    tmp85 = TORQUE_CAST(TNode<Object>{tmp84});
    tmp86 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferStackReturnBufferStart);
    std::tie(tmp87, tmp88) = GetRefAt_WasmCodePointer_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp86}).Flatten();
    tmp89 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp87, tmp88});
    tmp90 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister1);
    tmp91 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp90});
    tmp92 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferFPReturnRegister1);
    tmp93 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp92});
    std::tie(tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102) = LocationAllocatorForReturns_0(state_, TNode<RawPtrT>{tmp91}, TNode<RawPtrT>{tmp93}, TNode<RawPtrT>{tmp89}).Flatten();
    tmp103 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferSigRepresentationArray);
    std::tie(tmp104, tmp105) = GetRefAt_WasmCodePointer_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp103}).Flatten();
    tmp106 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference{tmp104, tmp105});
    tmp107 = (TNode<RawPtrT>{tmp106});
    tmp108 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp3});
    std::tie(tmp109, tmp110, tmp111) = NewOffHeapConstSlice_int32_0(state_, TNode<RawPtrT>{tmp107}, TNode<IntPtrT>{tmp108}).Flatten();
    tmp112 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferRefReturnCount);
    std::tie(tmp113, tmp114) = GetRefAt_bool_RawPtr_intptr_0(state_, TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp112}).Flatten();
    tmp115 = CodeStubAssembler(state_).LoadReference<BoolT>(CodeStubAssembler::Reference{tmp113, tmp114});
    ca_.Branch(tmp115, &block42, std::vector<compiler::Node*>{}, &block43, std::vector<compiler::Node*>{tmp95, tmp96, tmp97, tmp98, tmp99, tmp101, tmp102});
  }

  TNode<IntPtrT> tmp116;
  if (block42.is_used()) {
    ca_.Bind(&block42);
    tmp116 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block46, tmp95, tmp96, tmp97, tmp98, tmp99, tmp101, tmp102, tmp116);
  }

  TNode<IntPtrT> phi_bb46_7;
  TNode<IntPtrT> phi_bb46_8;
  TNode<IntPtrT> phi_bb46_9;
  TNode<IntPtrT> phi_bb46_10;
  TNode<IntPtrT> phi_bb46_11;
  TNode<IntPtrT> phi_bb46_13;
  TNode<BoolT> phi_bb46_14;
  TNode<IntPtrT> phi_bb46_20;
  TNode<IntPtrT> tmp117;
  TNode<BoolT> tmp118;
  if (block46.is_used()) {
    ca_.Bind(&block46, &phi_bb46_7, &phi_bb46_8, &phi_bb46_9, &phi_bb46_10, &phi_bb46_11, &phi_bb46_13, &phi_bb46_14, &phi_bb46_20);
    tmp117 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp3});
    tmp118 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb46_20}, TNode<IntPtrT>{tmp117});
    ca_.Branch(tmp118, &block44, std::vector<compiler::Node*>{phi_bb46_7, phi_bb46_8, phi_bb46_9, phi_bb46_10, phi_bb46_11, phi_bb46_13, phi_bb46_14, phi_bb46_20}, &block45, std::vector<compiler::Node*>{phi_bb46_7, phi_bb46_8, phi_bb46_9, phi_bb46_10, phi_bb46_11, phi_bb46_13, phi_bb46_14, phi_bb46_20});
  }

  TNode<IntPtrT> phi_bb44_7;
  TNode<IntPtrT> phi_bb44_8;
  TNode<IntPtrT> phi_bb44_9;
  TNode<IntPtrT> phi_bb44_10;
  TNode<IntPtrT> phi_bb44_11;
  TNode<IntPtrT> phi_bb44_13;
  TNode<BoolT> phi_bb44_14;
  TNode<IntPtrT> phi_bb44_20;
  TNode<IntPtrT> tmp119;
  TNode<IntPtrT> tmp120;
  TNode<Object> tmp121;
  TNode<IntPtrT> tmp122;
  TNode<Int32T> tmp123;
  TNode<Int32T> tmp124;
  TNode<BoolT> tmp125;
  if (block44.is_used()) {
    ca_.Bind(&block44, &phi_bb44_7, &phi_bb44_8, &phi_bb44_9, &phi_bb44_10, &phi_bb44_11, &phi_bb44_13, &phi_bb44_14, &phi_bb44_20);
    tmp119 = TimesSizeOf_int32_0(state_, TNode<IntPtrT>{phi_bb44_20});
    tmp120 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp110}, TNode<IntPtrT>{tmp119});
    std::tie(tmp121, tmp122) = NewReference_int32_0(state_, TNode<Object>{tmp109}, TNode<IntPtrT>{tmp120}).Flatten();
    tmp123 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp121, tmp122});
    tmp124 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI32.raw_bit_field());
    tmp125 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp123}, TNode<Int32T>{tmp124});
    ca_.Branch(tmp125, &block49, std::vector<compiler::Node*>{phi_bb44_7, phi_bb44_8, phi_bb44_9, phi_bb44_10, phi_bb44_11, phi_bb44_13, phi_bb44_14, phi_bb44_20}, &block50, std::vector<compiler::Node*>{phi_bb44_7, phi_bb44_8, phi_bb44_9, phi_bb44_10, phi_bb44_11, phi_bb44_13, phi_bb44_14, phi_bb44_20});
  }

  TNode<IntPtrT> phi_bb49_7;
  TNode<IntPtrT> phi_bb49_8;
  TNode<IntPtrT> phi_bb49_9;
  TNode<IntPtrT> phi_bb49_10;
  TNode<IntPtrT> phi_bb49_11;
  TNode<IntPtrT> phi_bb49_13;
  TNode<BoolT> phi_bb49_14;
  TNode<IntPtrT> phi_bb49_20;
  TNode<IntPtrT> tmp126;
  TNode<IntPtrT> tmp127;
  TNode<IntPtrT> tmp128;
  TNode<BoolT> tmp129;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_7, &phi_bb49_8, &phi_bb49_9, &phi_bb49_10, &phi_bb49_11, &phi_bb49_13, &phi_bb49_14, &phi_bb49_20);
    tmp126 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp127 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb49_7}, TNode<IntPtrT>{tmp126});
    tmp128 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp129 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb49_7}, TNode<IntPtrT>{tmp128});
    ca_.Branch(tmp129, &block53, std::vector<compiler::Node*>{phi_bb49_8, phi_bb49_9, phi_bb49_10, phi_bb49_11, phi_bb49_13, phi_bb49_14, phi_bb49_20}, &block54, std::vector<compiler::Node*>{phi_bb49_8, phi_bb49_9, phi_bb49_10, phi_bb49_11, phi_bb49_13, phi_bb49_14, phi_bb49_20});
  }

  TNode<IntPtrT> phi_bb53_8;
  TNode<IntPtrT> phi_bb53_9;
  TNode<IntPtrT> phi_bb53_10;
  TNode<IntPtrT> phi_bb53_11;
  TNode<IntPtrT> phi_bb53_13;
  TNode<BoolT> phi_bb53_14;
  TNode<IntPtrT> phi_bb53_20;
  TNode<Object> tmp130;
  TNode<IntPtrT> tmp131;
  TNode<IntPtrT> tmp132;
  TNode<IntPtrT> tmp133;
  if (block53.is_used()) {
    ca_.Bind(&block53, &phi_bb53_8, &phi_bb53_9, &phi_bb53_10, &phi_bb53_11, &phi_bb53_13, &phi_bb53_14, &phi_bb53_20);
    std::tie(tmp130, tmp131) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb53_9}).Flatten();
    tmp132 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp133 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb53_9}, TNode<IntPtrT>{tmp132});
    ca_.Goto(&block52, phi_bb53_8, tmp133, phi_bb53_10, phi_bb53_11, phi_bb53_13, phi_bb53_14, phi_bb53_20, tmp130, tmp131);
  }

  TNode<IntPtrT> phi_bb54_8;
  TNode<IntPtrT> phi_bb54_9;
  TNode<IntPtrT> phi_bb54_10;
  TNode<IntPtrT> phi_bb54_11;
  TNode<IntPtrT> phi_bb54_13;
  TNode<BoolT> phi_bb54_14;
  TNode<IntPtrT> phi_bb54_20;
  if (block54.is_used()) {
    ca_.Bind(&block54, &phi_bb54_8, &phi_bb54_9, &phi_bb54_10, &phi_bb54_11, &phi_bb54_13, &phi_bb54_14, &phi_bb54_20);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block56, phi_bb54_8, phi_bb54_9, phi_bb54_10, phi_bb54_11, phi_bb54_13, phi_bb54_14, phi_bb54_20);
    } else {
      ca_.Goto(&block57, phi_bb54_8, phi_bb54_9, phi_bb54_10, phi_bb54_11, phi_bb54_13, phi_bb54_14, phi_bb54_20);
    }
  }

  TNode<IntPtrT> phi_bb56_8;
  TNode<IntPtrT> phi_bb56_9;
  TNode<IntPtrT> phi_bb56_10;
  TNode<IntPtrT> phi_bb56_11;
  TNode<IntPtrT> phi_bb56_13;
  TNode<BoolT> phi_bb56_14;
  TNode<IntPtrT> phi_bb56_20;
  TNode<Object> tmp134;
  TNode<IntPtrT> tmp135;
  TNode<IntPtrT> tmp136;
  TNode<IntPtrT> tmp137;
  if (block56.is_used()) {
    ca_.Bind(&block56, &phi_bb56_8, &phi_bb56_9, &phi_bb56_10, &phi_bb56_11, &phi_bb56_13, &phi_bb56_14, &phi_bb56_20);
    std::tie(tmp134, tmp135) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb56_11}).Flatten();
    tmp136 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp137 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb56_11}, TNode<IntPtrT>{tmp136});
    ca_.Goto(&block55, phi_bb56_8, phi_bb56_9, phi_bb56_10, tmp137, phi_bb56_13, phi_bb56_14, phi_bb56_20, tmp134, tmp135);
  }

  TNode<IntPtrT> phi_bb57_8;
  TNode<IntPtrT> phi_bb57_9;
  TNode<IntPtrT> phi_bb57_10;
  TNode<IntPtrT> phi_bb57_11;
  TNode<IntPtrT> phi_bb57_13;
  TNode<BoolT> phi_bb57_14;
  TNode<IntPtrT> phi_bb57_20;
  TNode<IntPtrT> tmp138;
  TNode<BoolT> tmp139;
  if (block57.is_used()) {
    ca_.Bind(&block57, &phi_bb57_8, &phi_bb57_9, &phi_bb57_10, &phi_bb57_11, &phi_bb57_13, &phi_bb57_14, &phi_bb57_20);
    tmp138 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp139 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb57_13}, TNode<IntPtrT>{tmp138});
    ca_.Branch(tmp139, &block59, std::vector<compiler::Node*>{phi_bb57_8, phi_bb57_9, phi_bb57_10, phi_bb57_11, phi_bb57_13, phi_bb57_14, phi_bb57_20}, &block60, std::vector<compiler::Node*>{phi_bb57_8, phi_bb57_9, phi_bb57_10, phi_bb57_11, phi_bb57_13, phi_bb57_14, phi_bb57_20});
  }

  TNode<IntPtrT> phi_bb59_8;
  TNode<IntPtrT> phi_bb59_9;
  TNode<IntPtrT> phi_bb59_10;
  TNode<IntPtrT> phi_bb59_11;
  TNode<IntPtrT> phi_bb59_13;
  TNode<BoolT> phi_bb59_14;
  TNode<IntPtrT> phi_bb59_20;
  TNode<Object> tmp140;
  TNode<IntPtrT> tmp141;
  TNode<IntPtrT> tmp142;
  TNode<BoolT> tmp143;
  if (block59.is_used()) {
    ca_.Bind(&block59, &phi_bb59_8, &phi_bb59_9, &phi_bb59_10, &phi_bb59_11, &phi_bb59_13, &phi_bb59_14, &phi_bb59_20);
    std::tie(tmp140, tmp141) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb59_13}).Flatten();
    tmp142 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp143 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block55, phi_bb59_8, phi_bb59_9, phi_bb59_10, phi_bb59_11, tmp142, tmp143, phi_bb59_20, tmp140, tmp141);
  }

  TNode<IntPtrT> phi_bb60_8;
  TNode<IntPtrT> phi_bb60_9;
  TNode<IntPtrT> phi_bb60_10;
  TNode<IntPtrT> phi_bb60_11;
  TNode<IntPtrT> phi_bb60_13;
  TNode<BoolT> phi_bb60_14;
  TNode<IntPtrT> phi_bb60_20;
  TNode<Object> tmp144;
  TNode<IntPtrT> tmp145;
  TNode<IntPtrT> tmp146;
  TNode<IntPtrT> tmp147;
  TNode<IntPtrT> tmp148;
  TNode<IntPtrT> tmp149;
  TNode<BoolT> tmp150;
  if (block60.is_used()) {
    ca_.Bind(&block60, &phi_bb60_8, &phi_bb60_9, &phi_bb60_10, &phi_bb60_11, &phi_bb60_13, &phi_bb60_14, &phi_bb60_20);
    std::tie(tmp144, tmp145) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb60_11}).Flatten();
    tmp146 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp147 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb60_11}, TNode<IntPtrT>{tmp146});
    tmp148 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp149 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp147}, TNode<IntPtrT>{tmp148});
    tmp150 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block55, phi_bb60_8, phi_bb60_9, phi_bb60_10, tmp149, tmp147, tmp150, phi_bb60_20, tmp144, tmp145);
  }

  TNode<IntPtrT> phi_bb55_8;
  TNode<IntPtrT> phi_bb55_9;
  TNode<IntPtrT> phi_bb55_10;
  TNode<IntPtrT> phi_bb55_11;
  TNode<IntPtrT> phi_bb55_13;
  TNode<BoolT> phi_bb55_14;
  TNode<IntPtrT> phi_bb55_20;
  TNode<Object> phi_bb55_22;
  TNode<IntPtrT> phi_bb55_23;
  if (block55.is_used()) {
    ca_.Bind(&block55, &phi_bb55_8, &phi_bb55_9, &phi_bb55_10, &phi_bb55_11, &phi_bb55_13, &phi_bb55_14, &phi_bb55_20, &phi_bb55_22, &phi_bb55_23);
    ca_.Goto(&block52, phi_bb55_8, phi_bb55_9, phi_bb55_10, phi_bb55_11, phi_bb55_13, phi_bb55_14, phi_bb55_20, phi_bb55_22, phi_bb55_23);
  }

  TNode<IntPtrT> phi_bb52_8;
  TNode<IntPtrT> phi_bb52_9;
  TNode<IntPtrT> phi_bb52_10;
  TNode<IntPtrT> phi_bb52_11;
  TNode<IntPtrT> phi_bb52_13;
  TNode<BoolT> phi_bb52_14;
  TNode<IntPtrT> phi_bb52_20;
  TNode<Object> phi_bb52_22;
  TNode<IntPtrT> phi_bb52_23;
  if (block52.is_used()) {
    ca_.Bind(&block52, &phi_bb52_8, &phi_bb52_9, &phi_bb52_10, &phi_bb52_11, &phi_bb52_13, &phi_bb52_14, &phi_bb52_20, &phi_bb52_22, &phi_bb52_23);
    ca_.Goto(&block51, tmp127, phi_bb52_8, phi_bb52_9, phi_bb52_10, phi_bb52_11, phi_bb52_13, phi_bb52_14, phi_bb52_20);
  }

  TNode<IntPtrT> phi_bb50_7;
  TNode<IntPtrT> phi_bb50_8;
  TNode<IntPtrT> phi_bb50_9;
  TNode<IntPtrT> phi_bb50_10;
  TNode<IntPtrT> phi_bb50_11;
  TNode<IntPtrT> phi_bb50_13;
  TNode<BoolT> phi_bb50_14;
  TNode<IntPtrT> phi_bb50_20;
  TNode<Int32T> tmp151;
  TNode<BoolT> tmp152;
  if (block50.is_used()) {
    ca_.Bind(&block50, &phi_bb50_7, &phi_bb50_8, &phi_bb50_9, &phi_bb50_10, &phi_bb50_11, &phi_bb50_13, &phi_bb50_14, &phi_bb50_20);
    tmp151 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF32.raw_bit_field());
    tmp152 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp123}, TNode<Int32T>{tmp151});
    ca_.Branch(tmp152, &block61, std::vector<compiler::Node*>{phi_bb50_7, phi_bb50_8, phi_bb50_9, phi_bb50_10, phi_bb50_11, phi_bb50_13, phi_bb50_14, phi_bb50_20}, &block62, std::vector<compiler::Node*>{phi_bb50_7, phi_bb50_8, phi_bb50_9, phi_bb50_10, phi_bb50_11, phi_bb50_13, phi_bb50_14, phi_bb50_20});
  }

  TNode<IntPtrT> phi_bb61_7;
  TNode<IntPtrT> phi_bb61_8;
  TNode<IntPtrT> phi_bb61_9;
  TNode<IntPtrT> phi_bb61_10;
  TNode<IntPtrT> phi_bb61_11;
  TNode<IntPtrT> phi_bb61_13;
  TNode<BoolT> phi_bb61_14;
  TNode<IntPtrT> phi_bb61_20;
  TNode<IntPtrT> tmp153;
  TNode<IntPtrT> tmp154;
  TNode<IntPtrT> tmp155;
  TNode<BoolT> tmp156;
  if (block61.is_used()) {
    ca_.Bind(&block61, &phi_bb61_7, &phi_bb61_8, &phi_bb61_9, &phi_bb61_10, &phi_bb61_11, &phi_bb61_13, &phi_bb61_14, &phi_bb61_20);
    tmp153 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp154 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb61_8}, TNode<IntPtrT>{tmp153});
    tmp155 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp156 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb61_8}, TNode<IntPtrT>{tmp155});
    ca_.Branch(tmp156, &block65, std::vector<compiler::Node*>{phi_bb61_7, phi_bb61_9, phi_bb61_10, phi_bb61_11, phi_bb61_13, phi_bb61_14, phi_bb61_20}, &block66, std::vector<compiler::Node*>{phi_bb61_7, phi_bb61_9, phi_bb61_10, phi_bb61_11, phi_bb61_13, phi_bb61_14, phi_bb61_20});
  }

  TNode<IntPtrT> phi_bb65_7;
  TNode<IntPtrT> phi_bb65_9;
  TNode<IntPtrT> phi_bb65_10;
  TNode<IntPtrT> phi_bb65_11;
  TNode<IntPtrT> phi_bb65_13;
  TNode<BoolT> phi_bb65_14;
  TNode<IntPtrT> phi_bb65_20;
  TNode<Object> tmp157;
  TNode<IntPtrT> tmp158;
  TNode<IntPtrT> tmp159;
  TNode<IntPtrT> tmp160;
  if (block65.is_used()) {
    ca_.Bind(&block65, &phi_bb65_7, &phi_bb65_9, &phi_bb65_10, &phi_bb65_11, &phi_bb65_13, &phi_bb65_14, &phi_bb65_20);
    std::tie(tmp157, tmp158) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb65_10}).Flatten();
    tmp159 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp160 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb65_10}, TNode<IntPtrT>{tmp159});
    ca_.Goto(&block64, phi_bb65_7, phi_bb65_9, tmp160, phi_bb65_11, phi_bb65_13, phi_bb65_14, phi_bb65_20, tmp157, tmp158);
  }

  TNode<IntPtrT> phi_bb66_7;
  TNode<IntPtrT> phi_bb66_9;
  TNode<IntPtrT> phi_bb66_10;
  TNode<IntPtrT> phi_bb66_11;
  TNode<IntPtrT> phi_bb66_13;
  TNode<BoolT> phi_bb66_14;
  TNode<IntPtrT> phi_bb66_20;
  if (block66.is_used()) {
    ca_.Bind(&block66, &phi_bb66_7, &phi_bb66_9, &phi_bb66_10, &phi_bb66_11, &phi_bb66_13, &phi_bb66_14, &phi_bb66_20);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block68, phi_bb66_7, phi_bb66_9, phi_bb66_10, phi_bb66_11, phi_bb66_13, phi_bb66_14, phi_bb66_20);
    } else {
      ca_.Goto(&block69, phi_bb66_7, phi_bb66_9, phi_bb66_10, phi_bb66_11, phi_bb66_13, phi_bb66_14, phi_bb66_20);
    }
  }

  TNode<IntPtrT> phi_bb68_7;
  TNode<IntPtrT> phi_bb68_9;
  TNode<IntPtrT> phi_bb68_10;
  TNode<IntPtrT> phi_bb68_11;
  TNode<IntPtrT> phi_bb68_13;
  TNode<BoolT> phi_bb68_14;
  TNode<IntPtrT> phi_bb68_20;
  TNode<Object> tmp161;
  TNode<IntPtrT> tmp162;
  TNode<IntPtrT> tmp163;
  TNode<IntPtrT> tmp164;
  if (block68.is_used()) {
    ca_.Bind(&block68, &phi_bb68_7, &phi_bb68_9, &phi_bb68_10, &phi_bb68_11, &phi_bb68_13, &phi_bb68_14, &phi_bb68_20);
    std::tie(tmp161, tmp162) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb68_11}).Flatten();
    tmp163 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp164 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb68_11}, TNode<IntPtrT>{tmp163});
    ca_.Goto(&block67, phi_bb68_7, phi_bb68_9, phi_bb68_10, tmp164, phi_bb68_13, phi_bb68_14, phi_bb68_20, tmp161, tmp162);
  }

  TNode<IntPtrT> phi_bb69_7;
  TNode<IntPtrT> phi_bb69_9;
  TNode<IntPtrT> phi_bb69_10;
  TNode<IntPtrT> phi_bb69_11;
  TNode<IntPtrT> phi_bb69_13;
  TNode<BoolT> phi_bb69_14;
  TNode<IntPtrT> phi_bb69_20;
  TNode<IntPtrT> tmp165;
  TNode<BoolT> tmp166;
  if (block69.is_used()) {
    ca_.Bind(&block69, &phi_bb69_7, &phi_bb69_9, &phi_bb69_10, &phi_bb69_11, &phi_bb69_13, &phi_bb69_14, &phi_bb69_20);
    tmp165 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp166 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb69_13}, TNode<IntPtrT>{tmp165});
    ca_.Branch(tmp166, &block71, std::vector<compiler::Node*>{phi_bb69_7, phi_bb69_9, phi_bb69_10, phi_bb69_11, phi_bb69_13, phi_bb69_14, phi_bb69_20}, &block72, std::vector<compiler::Node*>{phi_bb69_7, phi_bb69_9, phi_bb69_10, phi_bb69_11, phi_bb69_13, phi_bb69_14, phi_bb69_20});
  }

  TNode<IntPtrT> phi_bb71_7;
  TNode<IntPtrT> phi_bb71_9;
  TNode<IntPtrT> phi_bb71_10;
  TNode<IntPtrT> phi_bb71_11;
  TNode<IntPtrT> phi_bb71_13;
  TNode<BoolT> phi_bb71_14;
  TNode<IntPtrT> phi_bb71_20;
  TNode<Object> tmp167;
  TNode<IntPtrT> tmp168;
  TNode<IntPtrT> tmp169;
  TNode<BoolT> tmp170;
  if (block71.is_used()) {
    ca_.Bind(&block71, &phi_bb71_7, &phi_bb71_9, &phi_bb71_10, &phi_bb71_11, &phi_bb71_13, &phi_bb71_14, &phi_bb71_20);
    std::tie(tmp167, tmp168) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb71_13}).Flatten();
    tmp169 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp170 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block67, phi_bb71_7, phi_bb71_9, phi_bb71_10, phi_bb71_11, tmp169, tmp170, phi_bb71_20, tmp167, tmp168);
  }

  TNode<IntPtrT> phi_bb72_7;
  TNode<IntPtrT> phi_bb72_9;
  TNode<IntPtrT> phi_bb72_10;
  TNode<IntPtrT> phi_bb72_11;
  TNode<IntPtrT> phi_bb72_13;
  TNode<BoolT> phi_bb72_14;
  TNode<IntPtrT> phi_bb72_20;
  TNode<Object> tmp171;
  TNode<IntPtrT> tmp172;
  TNode<IntPtrT> tmp173;
  TNode<IntPtrT> tmp174;
  TNode<IntPtrT> tmp175;
  TNode<IntPtrT> tmp176;
  TNode<BoolT> tmp177;
  if (block72.is_used()) {
    ca_.Bind(&block72, &phi_bb72_7, &phi_bb72_9, &phi_bb72_10, &phi_bb72_11, &phi_bb72_13, &phi_bb72_14, &phi_bb72_20);
    std::tie(tmp171, tmp172) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb72_11}).Flatten();
    tmp173 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp174 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb72_11}, TNode<IntPtrT>{tmp173});
    tmp175 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp176 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp174}, TNode<IntPtrT>{tmp175});
    tmp177 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block67, phi_bb72_7, phi_bb72_9, phi_bb72_10, tmp176, tmp174, tmp177, phi_bb72_20, tmp171, tmp172);
  }

  TNode<IntPtrT> phi_bb67_7;
  TNode<IntPtrT> phi_bb67_9;
  TNode<IntPtrT> phi_bb67_10;
  TNode<IntPtrT> phi_bb67_11;
  TNode<IntPtrT> phi_bb67_13;
  TNode<BoolT> phi_bb67_14;
  TNode<IntPtrT> phi_bb67_20;
  TNode<Object> phi_bb67_22;
  TNode<IntPtrT> phi_bb67_23;
  if (block67.is_used()) {
    ca_.Bind(&block67, &phi_bb67_7, &phi_bb67_9, &phi_bb67_10, &phi_bb67_11, &phi_bb67_13, &phi_bb67_14, &phi_bb67_20, &phi_bb67_22, &phi_bb67_23);
    ca_.Goto(&block64, phi_bb67_7, phi_bb67_9, phi_bb67_10, phi_bb67_11, phi_bb67_13, phi_bb67_14, phi_bb67_20, phi_bb67_22, phi_bb67_23);
  }

  TNode<IntPtrT> phi_bb64_7;
  TNode<IntPtrT> phi_bb64_9;
  TNode<IntPtrT> phi_bb64_10;
  TNode<IntPtrT> phi_bb64_11;
  TNode<IntPtrT> phi_bb64_13;
  TNode<BoolT> phi_bb64_14;
  TNode<IntPtrT> phi_bb64_20;
  TNode<Object> phi_bb64_22;
  TNode<IntPtrT> phi_bb64_23;
  if (block64.is_used()) {
    ca_.Bind(&block64, &phi_bb64_7, &phi_bb64_9, &phi_bb64_10, &phi_bb64_11, &phi_bb64_13, &phi_bb64_14, &phi_bb64_20, &phi_bb64_22, &phi_bb64_23);
    ca_.Goto(&block63, phi_bb64_7, tmp154, phi_bb64_9, phi_bb64_10, phi_bb64_11, phi_bb64_13, phi_bb64_14, phi_bb64_20);
  }

  TNode<IntPtrT> phi_bb62_7;
  TNode<IntPtrT> phi_bb62_8;
  TNode<IntPtrT> phi_bb62_9;
  TNode<IntPtrT> phi_bb62_10;
  TNode<IntPtrT> phi_bb62_11;
  TNode<IntPtrT> phi_bb62_13;
  TNode<BoolT> phi_bb62_14;
  TNode<IntPtrT> phi_bb62_20;
  TNode<Int32T> tmp178;
  TNode<BoolT> tmp179;
  if (block62.is_used()) {
    ca_.Bind(&block62, &phi_bb62_7, &phi_bb62_8, &phi_bb62_9, &phi_bb62_10, &phi_bb62_11, &phi_bb62_13, &phi_bb62_14, &phi_bb62_20);
    tmp178 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI64.raw_bit_field());
    tmp179 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp123}, TNode<Int32T>{tmp178});
    ca_.Branch(tmp179, &block73, std::vector<compiler::Node*>{phi_bb62_7, phi_bb62_8, phi_bb62_9, phi_bb62_10, phi_bb62_11, phi_bb62_13, phi_bb62_14, phi_bb62_20}, &block74, std::vector<compiler::Node*>{phi_bb62_7, phi_bb62_8, phi_bb62_9, phi_bb62_10, phi_bb62_11, phi_bb62_13, phi_bb62_14, phi_bb62_20});
  }

  TNode<IntPtrT> phi_bb73_7;
  TNode<IntPtrT> phi_bb73_8;
  TNode<IntPtrT> phi_bb73_9;
  TNode<IntPtrT> phi_bb73_10;
  TNode<IntPtrT> phi_bb73_11;
  TNode<IntPtrT> phi_bb73_13;
  TNode<BoolT> phi_bb73_14;
  TNode<IntPtrT> phi_bb73_20;
  TNode<IntPtrT> tmp180;
  TNode<IntPtrT> tmp181;
  TNode<IntPtrT> tmp182;
  TNode<BoolT> tmp183;
  if (block73.is_used()) {
    ca_.Bind(&block73, &phi_bb73_7, &phi_bb73_8, &phi_bb73_9, &phi_bb73_10, &phi_bb73_11, &phi_bb73_13, &phi_bb73_14, &phi_bb73_20);
    tmp180 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp181 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb73_7}, TNode<IntPtrT>{tmp180});
    tmp182 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp183 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb73_7}, TNode<IntPtrT>{tmp182});
    ca_.Branch(tmp183, &block77, std::vector<compiler::Node*>{phi_bb73_8, phi_bb73_9, phi_bb73_10, phi_bb73_11, phi_bb73_13, phi_bb73_14, phi_bb73_20}, &block78, std::vector<compiler::Node*>{phi_bb73_8, phi_bb73_9, phi_bb73_10, phi_bb73_11, phi_bb73_13, phi_bb73_14, phi_bb73_20});
  }

  TNode<IntPtrT> phi_bb77_8;
  TNode<IntPtrT> phi_bb77_9;
  TNode<IntPtrT> phi_bb77_10;
  TNode<IntPtrT> phi_bb77_11;
  TNode<IntPtrT> phi_bb77_13;
  TNode<BoolT> phi_bb77_14;
  TNode<IntPtrT> phi_bb77_20;
  TNode<Object> tmp184;
  TNode<IntPtrT> tmp185;
  TNode<IntPtrT> tmp186;
  TNode<IntPtrT> tmp187;
  if (block77.is_used()) {
    ca_.Bind(&block77, &phi_bb77_8, &phi_bb77_9, &phi_bb77_10, &phi_bb77_11, &phi_bb77_13, &phi_bb77_14, &phi_bb77_20);
    std::tie(tmp184, tmp185) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb77_9}).Flatten();
    tmp186 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp187 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb77_9}, TNode<IntPtrT>{tmp186});
    ca_.Goto(&block76, phi_bb77_8, tmp187, phi_bb77_10, phi_bb77_11, phi_bb77_13, phi_bb77_14, phi_bb77_20, tmp184, tmp185);
  }

  TNode<IntPtrT> phi_bb78_8;
  TNode<IntPtrT> phi_bb78_9;
  TNode<IntPtrT> phi_bb78_10;
  TNode<IntPtrT> phi_bb78_11;
  TNode<IntPtrT> phi_bb78_13;
  TNode<BoolT> phi_bb78_14;
  TNode<IntPtrT> phi_bb78_20;
  if (block78.is_used()) {
    ca_.Bind(&block78, &phi_bb78_8, &phi_bb78_9, &phi_bb78_10, &phi_bb78_11, &phi_bb78_13, &phi_bb78_14, &phi_bb78_20);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block80, phi_bb78_8, phi_bb78_9, phi_bb78_10, phi_bb78_11, phi_bb78_13, phi_bb78_14, phi_bb78_20);
    } else {
      ca_.Goto(&block81, phi_bb78_8, phi_bb78_9, phi_bb78_10, phi_bb78_11, phi_bb78_13, phi_bb78_14, phi_bb78_20);
    }
  }

  TNode<IntPtrT> phi_bb80_8;
  TNode<IntPtrT> phi_bb80_9;
  TNode<IntPtrT> phi_bb80_10;
  TNode<IntPtrT> phi_bb80_11;
  TNode<IntPtrT> phi_bb80_13;
  TNode<BoolT> phi_bb80_14;
  TNode<IntPtrT> phi_bb80_20;
  TNode<Object> tmp188;
  TNode<IntPtrT> tmp189;
  TNode<IntPtrT> tmp190;
  TNode<IntPtrT> tmp191;
  if (block80.is_used()) {
    ca_.Bind(&block80, &phi_bb80_8, &phi_bb80_9, &phi_bb80_10, &phi_bb80_11, &phi_bb80_13, &phi_bb80_14, &phi_bb80_20);
    std::tie(tmp188, tmp189) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb80_11}).Flatten();
    tmp190 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp191 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb80_11}, TNode<IntPtrT>{tmp190});
    ca_.Goto(&block79, phi_bb80_8, phi_bb80_9, phi_bb80_10, tmp191, phi_bb80_13, phi_bb80_14, phi_bb80_20, tmp188, tmp189);
  }

  TNode<IntPtrT> phi_bb81_8;
  TNode<IntPtrT> phi_bb81_9;
  TNode<IntPtrT> phi_bb81_10;
  TNode<IntPtrT> phi_bb81_11;
  TNode<IntPtrT> phi_bb81_13;
  TNode<BoolT> phi_bb81_14;
  TNode<IntPtrT> phi_bb81_20;
  TNode<IntPtrT> tmp192;
  TNode<BoolT> tmp193;
  if (block81.is_used()) {
    ca_.Bind(&block81, &phi_bb81_8, &phi_bb81_9, &phi_bb81_10, &phi_bb81_11, &phi_bb81_13, &phi_bb81_14, &phi_bb81_20);
    tmp192 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp193 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb81_13}, TNode<IntPtrT>{tmp192});
    ca_.Branch(tmp193, &block83, std::vector<compiler::Node*>{phi_bb81_8, phi_bb81_9, phi_bb81_10, phi_bb81_11, phi_bb81_13, phi_bb81_14, phi_bb81_20}, &block84, std::vector<compiler::Node*>{phi_bb81_8, phi_bb81_9, phi_bb81_10, phi_bb81_11, phi_bb81_13, phi_bb81_14, phi_bb81_20});
  }

  TNode<IntPtrT> phi_bb83_8;
  TNode<IntPtrT> phi_bb83_9;
  TNode<IntPtrT> phi_bb83_10;
  TNode<IntPtrT> phi_bb83_11;
  TNode<IntPtrT> phi_bb83_13;
  TNode<BoolT> phi_bb83_14;
  TNode<IntPtrT> phi_bb83_20;
  TNode<Object> tmp194;
  TNode<IntPtrT> tmp195;
  TNode<IntPtrT> tmp196;
  TNode<BoolT> tmp197;
  if (block83.is_used()) {
    ca_.Bind(&block83, &phi_bb83_8, &phi_bb83_9, &phi_bb83_10, &phi_bb83_11, &phi_bb83_13, &phi_bb83_14, &phi_bb83_20);
    std::tie(tmp194, tmp195) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb83_13}).Flatten();
    tmp196 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp197 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block79, phi_bb83_8, phi_bb83_9, phi_bb83_10, phi_bb83_11, tmp196, tmp197, phi_bb83_20, tmp194, tmp195);
  }

  TNode<IntPtrT> phi_bb84_8;
  TNode<IntPtrT> phi_bb84_9;
  TNode<IntPtrT> phi_bb84_10;
  TNode<IntPtrT> phi_bb84_11;
  TNode<IntPtrT> phi_bb84_13;
  TNode<BoolT> phi_bb84_14;
  TNode<IntPtrT> phi_bb84_20;
  TNode<Object> tmp198;
  TNode<IntPtrT> tmp199;
  TNode<IntPtrT> tmp200;
  TNode<IntPtrT> tmp201;
  TNode<IntPtrT> tmp202;
  TNode<IntPtrT> tmp203;
  TNode<BoolT> tmp204;
  if (block84.is_used()) {
    ca_.Bind(&block84, &phi_bb84_8, &phi_bb84_9, &phi_bb84_10, &phi_bb84_11, &phi_bb84_13, &phi_bb84_14, &phi_bb84_20);
    std::tie(tmp198, tmp199) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb84_11}).Flatten();
    tmp200 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp201 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb84_11}, TNode<IntPtrT>{tmp200});
    tmp202 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp203 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp201}, TNode<IntPtrT>{tmp202});
    tmp204 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block79, phi_bb84_8, phi_bb84_9, phi_bb84_10, tmp203, tmp201, tmp204, phi_bb84_20, tmp198, tmp199);
  }

  TNode<IntPtrT> phi_bb79_8;
  TNode<IntPtrT> phi_bb79_9;
  TNode<IntPtrT> phi_bb79_10;
  TNode<IntPtrT> phi_bb79_11;
  TNode<IntPtrT> phi_bb79_13;
  TNode<BoolT> phi_bb79_14;
  TNode<IntPtrT> phi_bb79_20;
  TNode<Object> phi_bb79_22;
  TNode<IntPtrT> phi_bb79_23;
  if (block79.is_used()) {
    ca_.Bind(&block79, &phi_bb79_8, &phi_bb79_9, &phi_bb79_10, &phi_bb79_11, &phi_bb79_13, &phi_bb79_14, &phi_bb79_20, &phi_bb79_22, &phi_bb79_23);
    ca_.Goto(&block76, phi_bb79_8, phi_bb79_9, phi_bb79_10, phi_bb79_11, phi_bb79_13, phi_bb79_14, phi_bb79_20, phi_bb79_22, phi_bb79_23);
  }

  TNode<IntPtrT> phi_bb76_8;
  TNode<IntPtrT> phi_bb76_9;
  TNode<IntPtrT> phi_bb76_10;
  TNode<IntPtrT> phi_bb76_11;
  TNode<IntPtrT> phi_bb76_13;
  TNode<BoolT> phi_bb76_14;
  TNode<IntPtrT> phi_bb76_20;
  TNode<Object> phi_bb76_22;
  TNode<IntPtrT> phi_bb76_23;
  if (block76.is_used()) {
    ca_.Bind(&block76, &phi_bb76_8, &phi_bb76_9, &phi_bb76_10, &phi_bb76_11, &phi_bb76_13, &phi_bb76_14, &phi_bb76_20, &phi_bb76_22, &phi_bb76_23);
    if (((CodeStubAssembler(state_).ConstexprBoolNot((CodeStubAssembler(state_).Is64()))))) {
      ca_.Goto(&block85, phi_bb76_8, phi_bb76_9, phi_bb76_10, phi_bb76_11, phi_bb76_13, phi_bb76_14, phi_bb76_20);
    } else {
      ca_.Goto(&block86, phi_bb76_8, phi_bb76_9, phi_bb76_10, phi_bb76_11, phi_bb76_13, phi_bb76_14, phi_bb76_20);
    }
  }

  TNode<IntPtrT> phi_bb85_8;
  TNode<IntPtrT> phi_bb85_9;
  TNode<IntPtrT> phi_bb85_10;
  TNode<IntPtrT> phi_bb85_11;
  TNode<IntPtrT> phi_bb85_13;
  TNode<BoolT> phi_bb85_14;
  TNode<IntPtrT> phi_bb85_20;
  TNode<IntPtrT> tmp205;
  TNode<IntPtrT> tmp206;
  TNode<IntPtrT> tmp207;
  TNode<BoolT> tmp208;
  if (block85.is_used()) {
    ca_.Bind(&block85, &phi_bb85_8, &phi_bb85_9, &phi_bb85_10, &phi_bb85_11, &phi_bb85_13, &phi_bb85_14, &phi_bb85_20);
    tmp205 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp206 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp181}, TNode<IntPtrT>{tmp205});
    tmp207 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp208 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp181}, TNode<IntPtrT>{tmp207});
    ca_.Branch(tmp208, &block89, std::vector<compiler::Node*>{phi_bb85_8, phi_bb85_9, phi_bb85_10, phi_bb85_11, phi_bb85_13, phi_bb85_14, phi_bb85_20}, &block90, std::vector<compiler::Node*>{phi_bb85_8, phi_bb85_9, phi_bb85_10, phi_bb85_11, phi_bb85_13, phi_bb85_14, phi_bb85_20});
  }

  TNode<IntPtrT> phi_bb89_8;
  TNode<IntPtrT> phi_bb89_9;
  TNode<IntPtrT> phi_bb89_10;
  TNode<IntPtrT> phi_bb89_11;
  TNode<IntPtrT> phi_bb89_13;
  TNode<BoolT> phi_bb89_14;
  TNode<IntPtrT> phi_bb89_20;
  TNode<Object> tmp209;
  TNode<IntPtrT> tmp210;
  TNode<IntPtrT> tmp211;
  TNode<IntPtrT> tmp212;
  if (block89.is_used()) {
    ca_.Bind(&block89, &phi_bb89_8, &phi_bb89_9, &phi_bb89_10, &phi_bb89_11, &phi_bb89_13, &phi_bb89_14, &phi_bb89_20);
    std::tie(tmp209, tmp210) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb89_9}).Flatten();
    tmp211 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp212 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb89_9}, TNode<IntPtrT>{tmp211});
    ca_.Goto(&block88, phi_bb89_8, tmp212, phi_bb89_10, phi_bb89_11, phi_bb89_13, phi_bb89_14, phi_bb89_20, tmp209, tmp210);
  }

  TNode<IntPtrT> phi_bb90_8;
  TNode<IntPtrT> phi_bb90_9;
  TNode<IntPtrT> phi_bb90_10;
  TNode<IntPtrT> phi_bb90_11;
  TNode<IntPtrT> phi_bb90_13;
  TNode<BoolT> phi_bb90_14;
  TNode<IntPtrT> phi_bb90_20;
  if (block90.is_used()) {
    ca_.Bind(&block90, &phi_bb90_8, &phi_bb90_9, &phi_bb90_10, &phi_bb90_11, &phi_bb90_13, &phi_bb90_14, &phi_bb90_20);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block92, phi_bb90_8, phi_bb90_9, phi_bb90_10, phi_bb90_11, phi_bb90_13, phi_bb90_14, phi_bb90_20);
    } else {
      ca_.Goto(&block93, phi_bb90_8, phi_bb90_9, phi_bb90_10, phi_bb90_11, phi_bb90_13, phi_bb90_14, phi_bb90_20);
    }
  }

  TNode<IntPtrT> phi_bb92_8;
  TNode<IntPtrT> phi_bb92_9;
  TNode<IntPtrT> phi_bb92_10;
  TNode<IntPtrT> phi_bb92_11;
  TNode<IntPtrT> phi_bb92_13;
  TNode<BoolT> phi_bb92_14;
  TNode<IntPtrT> phi_bb92_20;
  TNode<Object> tmp213;
  TNode<IntPtrT> tmp214;
  TNode<IntPtrT> tmp215;
  TNode<IntPtrT> tmp216;
  if (block92.is_used()) {
    ca_.Bind(&block92, &phi_bb92_8, &phi_bb92_9, &phi_bb92_10, &phi_bb92_11, &phi_bb92_13, &phi_bb92_14, &phi_bb92_20);
    std::tie(tmp213, tmp214) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb92_11}).Flatten();
    tmp215 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp216 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb92_11}, TNode<IntPtrT>{tmp215});
    ca_.Goto(&block91, phi_bb92_8, phi_bb92_9, phi_bb92_10, tmp216, phi_bb92_13, phi_bb92_14, phi_bb92_20, tmp213, tmp214);
  }

  TNode<IntPtrT> phi_bb93_8;
  TNode<IntPtrT> phi_bb93_9;
  TNode<IntPtrT> phi_bb93_10;
  TNode<IntPtrT> phi_bb93_11;
  TNode<IntPtrT> phi_bb93_13;
  TNode<BoolT> phi_bb93_14;
  TNode<IntPtrT> phi_bb93_20;
  TNode<IntPtrT> tmp217;
  TNode<BoolT> tmp218;
  if (block93.is_used()) {
    ca_.Bind(&block93, &phi_bb93_8, &phi_bb93_9, &phi_bb93_10, &phi_bb93_11, &phi_bb93_13, &phi_bb93_14, &phi_bb93_20);
    tmp217 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp218 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb93_13}, TNode<IntPtrT>{tmp217});
    ca_.Branch(tmp218, &block95, std::vector<compiler::Node*>{phi_bb93_8, phi_bb93_9, phi_bb93_10, phi_bb93_11, phi_bb93_13, phi_bb93_14, phi_bb93_20}, &block96, std::vector<compiler::Node*>{phi_bb93_8, phi_bb93_9, phi_bb93_10, phi_bb93_11, phi_bb93_13, phi_bb93_14, phi_bb93_20});
  }

  TNode<IntPtrT> phi_bb95_8;
  TNode<IntPtrT> phi_bb95_9;
  TNode<IntPtrT> phi_bb95_10;
  TNode<IntPtrT> phi_bb95_11;
  TNode<IntPtrT> phi_bb95_13;
  TNode<BoolT> phi_bb95_14;
  TNode<IntPtrT> phi_bb95_20;
  TNode<Object> tmp219;
  TNode<IntPtrT> tmp220;
  TNode<IntPtrT> tmp221;
  TNode<BoolT> tmp222;
  if (block95.is_used()) {
    ca_.Bind(&block95, &phi_bb95_8, &phi_bb95_9, &phi_bb95_10, &phi_bb95_11, &phi_bb95_13, &phi_bb95_14, &phi_bb95_20);
    std::tie(tmp219, tmp220) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb95_13}).Flatten();
    tmp221 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp222 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block91, phi_bb95_8, phi_bb95_9, phi_bb95_10, phi_bb95_11, tmp221, tmp222, phi_bb95_20, tmp219, tmp220);
  }

  TNode<IntPtrT> phi_bb96_8;
  TNode<IntPtrT> phi_bb96_9;
  TNode<IntPtrT> phi_bb96_10;
  TNode<IntPtrT> phi_bb96_11;
  TNode<IntPtrT> phi_bb96_13;
  TNode<BoolT> phi_bb96_14;
  TNode<IntPtrT> phi_bb96_20;
  TNode<Object> tmp223;
  TNode<IntPtrT> tmp224;
  TNode<IntPtrT> tmp225;
  TNode<IntPtrT> tmp226;
  TNode<IntPtrT> tmp227;
  TNode<IntPtrT> tmp228;
  TNode<BoolT> tmp229;
  if (block96.is_used()) {
    ca_.Bind(&block96, &phi_bb96_8, &phi_bb96_9, &phi_bb96_10, &phi_bb96_11, &phi_bb96_13, &phi_bb96_14, &phi_bb96_20);
    std::tie(tmp223, tmp224) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb96_11}).Flatten();
    tmp225 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp226 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb96_11}, TNode<IntPtrT>{tmp225});
    tmp227 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp228 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp226}, TNode<IntPtrT>{tmp227});
    tmp229 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block91, phi_bb96_8, phi_bb96_9, phi_bb96_10, tmp228, tmp226, tmp229, phi_bb96_20, tmp223, tmp224);
  }

  TNode<IntPtrT> phi_bb91_8;
  TNode<IntPtrT> phi_bb91_9;
  TNode<IntPtrT> phi_bb91_10;
  TNode<IntPtrT> phi_bb91_11;
  TNode<IntPtrT> phi_bb91_13;
  TNode<BoolT> phi_bb91_14;
  TNode<IntPtrT> phi_bb91_20;
  TNode<Object> phi_bb91_22;
  TNode<IntPtrT> phi_bb91_23;
  if (block91.is_used()) {
    ca_.Bind(&block91, &phi_bb91_8, &phi_bb91_9, &phi_bb91_10, &phi_bb91_11, &phi_bb91_13, &phi_bb91_14, &phi_bb91_20, &phi_bb91_22, &phi_bb91_23);
    ca_.Goto(&block88, phi_bb91_8, phi_bb91_9, phi_bb91_10, phi_bb91_11, phi_bb91_13, phi_bb91_14, phi_bb91_20, phi_bb91_22, phi_bb91_23);
  }

  TNode<IntPtrT> phi_bb88_8;
  TNode<IntPtrT> phi_bb88_9;
  TNode<IntPtrT> phi_bb88_10;
  TNode<IntPtrT> phi_bb88_11;
  TNode<IntPtrT> phi_bb88_13;
  TNode<BoolT> phi_bb88_14;
  TNode<IntPtrT> phi_bb88_20;
  TNode<Object> phi_bb88_22;
  TNode<IntPtrT> phi_bb88_23;
  if (block88.is_used()) {
    ca_.Bind(&block88, &phi_bb88_8, &phi_bb88_9, &phi_bb88_10, &phi_bb88_11, &phi_bb88_13, &phi_bb88_14, &phi_bb88_20, &phi_bb88_22, &phi_bb88_23);
    ca_.Goto(&block87, tmp206, phi_bb88_8, phi_bb88_9, phi_bb88_10, phi_bb88_11, phi_bb88_13, phi_bb88_14, phi_bb88_20);
  }

  TNode<IntPtrT> phi_bb86_8;
  TNode<IntPtrT> phi_bb86_9;
  TNode<IntPtrT> phi_bb86_10;
  TNode<IntPtrT> phi_bb86_11;
  TNode<IntPtrT> phi_bb86_13;
  TNode<BoolT> phi_bb86_14;
  TNode<IntPtrT> phi_bb86_20;
  if (block86.is_used()) {
    ca_.Bind(&block86, &phi_bb86_8, &phi_bb86_9, &phi_bb86_10, &phi_bb86_11, &phi_bb86_13, &phi_bb86_14, &phi_bb86_20);
    ca_.Goto(&block87, tmp181, phi_bb86_8, phi_bb86_9, phi_bb86_10, phi_bb86_11, phi_bb86_13, phi_bb86_14, phi_bb86_20);
  }

  TNode<IntPtrT> phi_bb87_7;
  TNode<IntPtrT> phi_bb87_8;
  TNode<IntPtrT> phi_bb87_9;
  TNode<IntPtrT> phi_bb87_10;
  TNode<IntPtrT> phi_bb87_11;
  TNode<IntPtrT> phi_bb87_13;
  TNode<BoolT> phi_bb87_14;
  TNode<IntPtrT> phi_bb87_20;
  if (block87.is_used()) {
    ca_.Bind(&block87, &phi_bb87_7, &phi_bb87_8, &phi_bb87_9, &phi_bb87_10, &phi_bb87_11, &phi_bb87_13, &phi_bb87_14, &phi_bb87_20);
    ca_.Goto(&block75, phi_bb87_7, phi_bb87_8, phi_bb87_9, phi_bb87_10, phi_bb87_11, phi_bb87_13, phi_bb87_14, phi_bb87_20);
  }

  TNode<IntPtrT> phi_bb74_7;
  TNode<IntPtrT> phi_bb74_8;
  TNode<IntPtrT> phi_bb74_9;
  TNode<IntPtrT> phi_bb74_10;
  TNode<IntPtrT> phi_bb74_11;
  TNode<IntPtrT> phi_bb74_13;
  TNode<BoolT> phi_bb74_14;
  TNode<IntPtrT> phi_bb74_20;
  TNode<Int32T> tmp230;
  TNode<BoolT> tmp231;
  if (block74.is_used()) {
    ca_.Bind(&block74, &phi_bb74_7, &phi_bb74_8, &phi_bb74_9, &phi_bb74_10, &phi_bb74_11, &phi_bb74_13, &phi_bb74_14, &phi_bb74_20);
    tmp230 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF64.raw_bit_field());
    tmp231 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp123}, TNode<Int32T>{tmp230});
    ca_.Branch(tmp231, &block97, std::vector<compiler::Node*>{phi_bb74_7, phi_bb74_8, phi_bb74_9, phi_bb74_10, phi_bb74_11, phi_bb74_13, phi_bb74_14, phi_bb74_20}, &block98, std::vector<compiler::Node*>{phi_bb74_7, phi_bb74_8, phi_bb74_9, phi_bb74_10, phi_bb74_11, phi_bb74_13, phi_bb74_14, phi_bb74_20});
  }

  TNode<IntPtrT> phi_bb97_7;
  TNode<IntPtrT> phi_bb97_8;
  TNode<IntPtrT> phi_bb97_9;
  TNode<IntPtrT> phi_bb97_10;
  TNode<IntPtrT> phi_bb97_11;
  TNode<IntPtrT> phi_bb97_13;
  TNode<BoolT> phi_bb97_14;
  TNode<IntPtrT> phi_bb97_20;
  TNode<IntPtrT> tmp232;
  TNode<IntPtrT> tmp233;
  TNode<IntPtrT> tmp234;
  TNode<BoolT> tmp235;
  if (block97.is_used()) {
    ca_.Bind(&block97, &phi_bb97_7, &phi_bb97_8, &phi_bb97_9, &phi_bb97_10, &phi_bb97_11, &phi_bb97_13, &phi_bb97_14, &phi_bb97_20);
    tmp232 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp233 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb97_8}, TNode<IntPtrT>{tmp232});
    tmp234 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp235 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb97_8}, TNode<IntPtrT>{tmp234});
    ca_.Branch(tmp235, &block100, std::vector<compiler::Node*>{phi_bb97_7, phi_bb97_9, phi_bb97_10, phi_bb97_11, phi_bb97_13, phi_bb97_14, phi_bb97_20}, &block101, std::vector<compiler::Node*>{phi_bb97_7, phi_bb97_9, phi_bb97_10, phi_bb97_11, phi_bb97_13, phi_bb97_14, phi_bb97_20});
  }

  TNode<IntPtrT> phi_bb100_7;
  TNode<IntPtrT> phi_bb100_9;
  TNode<IntPtrT> phi_bb100_10;
  TNode<IntPtrT> phi_bb100_11;
  TNode<IntPtrT> phi_bb100_13;
  TNode<BoolT> phi_bb100_14;
  TNode<IntPtrT> phi_bb100_20;
  TNode<Object> tmp236;
  TNode<IntPtrT> tmp237;
  TNode<IntPtrT> tmp238;
  TNode<IntPtrT> tmp239;
  if (block100.is_used()) {
    ca_.Bind(&block100, &phi_bb100_7, &phi_bb100_9, &phi_bb100_10, &phi_bb100_11, &phi_bb100_13, &phi_bb100_14, &phi_bb100_20);
    std::tie(tmp236, tmp237) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb100_10}).Flatten();
    tmp238 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp239 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb100_10}, TNode<IntPtrT>{tmp238});
    ca_.Goto(&block99, phi_bb100_7, phi_bb100_9, tmp239, phi_bb100_11, phi_bb100_13, phi_bb100_14, phi_bb100_20, tmp236, tmp237);
  }

  TNode<IntPtrT> phi_bb101_7;
  TNode<IntPtrT> phi_bb101_9;
  TNode<IntPtrT> phi_bb101_10;
  TNode<IntPtrT> phi_bb101_11;
  TNode<IntPtrT> phi_bb101_13;
  TNode<BoolT> phi_bb101_14;
  TNode<IntPtrT> phi_bb101_20;
  if (block101.is_used()) {
    ca_.Bind(&block101, &phi_bb101_7, &phi_bb101_9, &phi_bb101_10, &phi_bb101_11, &phi_bb101_13, &phi_bb101_14, &phi_bb101_20);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block102, phi_bb101_7, phi_bb101_9, phi_bb101_10, phi_bb101_11, phi_bb101_13, phi_bb101_14, phi_bb101_20);
    } else {
      ca_.Goto(&block103, phi_bb101_7, phi_bb101_9, phi_bb101_10, phi_bb101_11, phi_bb101_13, phi_bb101_14, phi_bb101_20);
    }
  }

  TNode<IntPtrT> phi_bb102_7;
  TNode<IntPtrT> phi_bb102_9;
  TNode<IntPtrT> phi_bb102_10;
  TNode<IntPtrT> phi_bb102_11;
  TNode<IntPtrT> phi_bb102_13;
  TNode<BoolT> phi_bb102_14;
  TNode<IntPtrT> phi_bb102_20;
  if (block102.is_used()) {
    ca_.Bind(&block102, &phi_bb102_7, &phi_bb102_9, &phi_bb102_10, &phi_bb102_11, &phi_bb102_13, &phi_bb102_14, &phi_bb102_20);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block106, phi_bb102_7, phi_bb102_9, phi_bb102_10, phi_bb102_11, phi_bb102_13, phi_bb102_14, phi_bb102_20);
    } else {
      ca_.Goto(&block107, phi_bb102_7, phi_bb102_9, phi_bb102_10, phi_bb102_11, phi_bb102_13, phi_bb102_14, phi_bb102_20);
    }
  }

  TNode<IntPtrT> phi_bb106_7;
  TNode<IntPtrT> phi_bb106_9;
  TNode<IntPtrT> phi_bb106_10;
  TNode<IntPtrT> phi_bb106_11;
  TNode<IntPtrT> phi_bb106_13;
  TNode<BoolT> phi_bb106_14;
  TNode<IntPtrT> phi_bb106_20;
  TNode<Object> tmp240;
  TNode<IntPtrT> tmp241;
  TNode<IntPtrT> tmp242;
  TNode<IntPtrT> tmp243;
  if (block106.is_used()) {
    ca_.Bind(&block106, &phi_bb106_7, &phi_bb106_9, &phi_bb106_10, &phi_bb106_11, &phi_bb106_13, &phi_bb106_14, &phi_bb106_20);
    std::tie(tmp240, tmp241) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb106_11}).Flatten();
    tmp242 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp243 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb106_11}, TNode<IntPtrT>{tmp242});
    ca_.Goto(&block105, phi_bb106_7, phi_bb106_9, phi_bb106_10, tmp243, phi_bb106_13, phi_bb106_14, phi_bb106_20, tmp240, tmp241);
  }

  TNode<IntPtrT> phi_bb107_7;
  TNode<IntPtrT> phi_bb107_9;
  TNode<IntPtrT> phi_bb107_10;
  TNode<IntPtrT> phi_bb107_11;
  TNode<IntPtrT> phi_bb107_13;
  TNode<BoolT> phi_bb107_14;
  TNode<IntPtrT> phi_bb107_20;
  TNode<IntPtrT> tmp244;
  TNode<BoolT> tmp245;
  if (block107.is_used()) {
    ca_.Bind(&block107, &phi_bb107_7, &phi_bb107_9, &phi_bb107_10, &phi_bb107_11, &phi_bb107_13, &phi_bb107_14, &phi_bb107_20);
    tmp244 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp245 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb107_13}, TNode<IntPtrT>{tmp244});
    ca_.Branch(tmp245, &block109, std::vector<compiler::Node*>{phi_bb107_7, phi_bb107_9, phi_bb107_10, phi_bb107_11, phi_bb107_13, phi_bb107_14, phi_bb107_20}, &block110, std::vector<compiler::Node*>{phi_bb107_7, phi_bb107_9, phi_bb107_10, phi_bb107_11, phi_bb107_13, phi_bb107_14, phi_bb107_20});
  }

  TNode<IntPtrT> phi_bb109_7;
  TNode<IntPtrT> phi_bb109_9;
  TNode<IntPtrT> phi_bb109_10;
  TNode<IntPtrT> phi_bb109_11;
  TNode<IntPtrT> phi_bb109_13;
  TNode<BoolT> phi_bb109_14;
  TNode<IntPtrT> phi_bb109_20;
  TNode<Object> tmp246;
  TNode<IntPtrT> tmp247;
  TNode<IntPtrT> tmp248;
  TNode<BoolT> tmp249;
  if (block109.is_used()) {
    ca_.Bind(&block109, &phi_bb109_7, &phi_bb109_9, &phi_bb109_10, &phi_bb109_11, &phi_bb109_13, &phi_bb109_14, &phi_bb109_20);
    std::tie(tmp246, tmp247) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb109_13}).Flatten();
    tmp248 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp249 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block105, phi_bb109_7, phi_bb109_9, phi_bb109_10, phi_bb109_11, tmp248, tmp249, phi_bb109_20, tmp246, tmp247);
  }

  TNode<IntPtrT> phi_bb110_7;
  TNode<IntPtrT> phi_bb110_9;
  TNode<IntPtrT> phi_bb110_10;
  TNode<IntPtrT> phi_bb110_11;
  TNode<IntPtrT> phi_bb110_13;
  TNode<BoolT> phi_bb110_14;
  TNode<IntPtrT> phi_bb110_20;
  TNode<Object> tmp250;
  TNode<IntPtrT> tmp251;
  TNode<IntPtrT> tmp252;
  TNode<IntPtrT> tmp253;
  TNode<IntPtrT> tmp254;
  TNode<IntPtrT> tmp255;
  TNode<BoolT> tmp256;
  if (block110.is_used()) {
    ca_.Bind(&block110, &phi_bb110_7, &phi_bb110_9, &phi_bb110_10, &phi_bb110_11, &phi_bb110_13, &phi_bb110_14, &phi_bb110_20);
    std::tie(tmp250, tmp251) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb110_11}).Flatten();
    tmp252 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp253 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb110_11}, TNode<IntPtrT>{tmp252});
    tmp254 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp255 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp253}, TNode<IntPtrT>{tmp254});
    tmp256 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block105, phi_bb110_7, phi_bb110_9, phi_bb110_10, tmp255, tmp253, tmp256, phi_bb110_20, tmp250, tmp251);
  }

  TNode<IntPtrT> phi_bb105_7;
  TNode<IntPtrT> phi_bb105_9;
  TNode<IntPtrT> phi_bb105_10;
  TNode<IntPtrT> phi_bb105_11;
  TNode<IntPtrT> phi_bb105_13;
  TNode<BoolT> phi_bb105_14;
  TNode<IntPtrT> phi_bb105_20;
  TNode<Object> phi_bb105_22;
  TNode<IntPtrT> phi_bb105_23;
  if (block105.is_used()) {
    ca_.Bind(&block105, &phi_bb105_7, &phi_bb105_9, &phi_bb105_10, &phi_bb105_11, &phi_bb105_13, &phi_bb105_14, &phi_bb105_20, &phi_bb105_22, &phi_bb105_23);
    ca_.Goto(&block99, phi_bb105_7, phi_bb105_9, phi_bb105_10, phi_bb105_11, phi_bb105_13, phi_bb105_14, phi_bb105_20, phi_bb105_22, phi_bb105_23);
  }

  TNode<IntPtrT> phi_bb103_7;
  TNode<IntPtrT> phi_bb103_9;
  TNode<IntPtrT> phi_bb103_10;
  TNode<IntPtrT> phi_bb103_11;
  TNode<IntPtrT> phi_bb103_13;
  TNode<BoolT> phi_bb103_14;
  TNode<IntPtrT> phi_bb103_20;
  TNode<Object> tmp257;
  TNode<IntPtrT> tmp258;
  TNode<IntPtrT> tmp259;
  TNode<IntPtrT> tmp260;
  TNode<BoolT> tmp261;
  if (block103.is_used()) {
    ca_.Bind(&block103, &phi_bb103_7, &phi_bb103_9, &phi_bb103_10, &phi_bb103_11, &phi_bb103_13, &phi_bb103_14, &phi_bb103_20);
    std::tie(tmp257, tmp258) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb103_11}).Flatten();
    tmp259 = FromConstexpr_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Mul((FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull))), (SizeOf_intptr_0(state_)))));
    tmp260 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb103_11}, TNode<IntPtrT>{tmp259});
    tmp261 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block99, phi_bb103_7, phi_bb103_9, phi_bb103_10, tmp260, phi_bb103_13, tmp261, phi_bb103_20, tmp257, tmp258);
  }

  TNode<IntPtrT> phi_bb99_7;
  TNode<IntPtrT> phi_bb99_9;
  TNode<IntPtrT> phi_bb99_10;
  TNode<IntPtrT> phi_bb99_11;
  TNode<IntPtrT> phi_bb99_13;
  TNode<BoolT> phi_bb99_14;
  TNode<IntPtrT> phi_bb99_20;
  TNode<Object> phi_bb99_22;
  TNode<IntPtrT> phi_bb99_23;
  if (block99.is_used()) {
    ca_.Bind(&block99, &phi_bb99_7, &phi_bb99_9, &phi_bb99_10, &phi_bb99_11, &phi_bb99_13, &phi_bb99_14, &phi_bb99_20, &phi_bb99_22, &phi_bb99_23);
    ca_.Goto(&block98, phi_bb99_7, tmp233, phi_bb99_9, phi_bb99_10, phi_bb99_11, phi_bb99_13, phi_bb99_14, phi_bb99_20);
  }

  TNode<IntPtrT> phi_bb98_7;
  TNode<IntPtrT> phi_bb98_8;
  TNode<IntPtrT> phi_bb98_9;
  TNode<IntPtrT> phi_bb98_10;
  TNode<IntPtrT> phi_bb98_11;
  TNode<IntPtrT> phi_bb98_13;
  TNode<BoolT> phi_bb98_14;
  TNode<IntPtrT> phi_bb98_20;
  if (block98.is_used()) {
    ca_.Bind(&block98, &phi_bb98_7, &phi_bb98_8, &phi_bb98_9, &phi_bb98_10, &phi_bb98_11, &phi_bb98_13, &phi_bb98_14, &phi_bb98_20);
    ca_.Goto(&block75, phi_bb98_7, phi_bb98_8, phi_bb98_9, phi_bb98_10, phi_bb98_11, phi_bb98_13, phi_bb98_14, phi_bb98_20);
  }

  TNode<IntPtrT> phi_bb75_7;
  TNode<IntPtrT> phi_bb75_8;
  TNode<IntPtrT> phi_bb75_9;
  TNode<IntPtrT> phi_bb75_10;
  TNode<IntPtrT> phi_bb75_11;
  TNode<IntPtrT> phi_bb75_13;
  TNode<BoolT> phi_bb75_14;
  TNode<IntPtrT> phi_bb75_20;
  if (block75.is_used()) {
    ca_.Bind(&block75, &phi_bb75_7, &phi_bb75_8, &phi_bb75_9, &phi_bb75_10, &phi_bb75_11, &phi_bb75_13, &phi_bb75_14, &phi_bb75_20);
    ca_.Goto(&block63, phi_bb75_7, phi_bb75_8, phi_bb75_9, phi_bb75_10, phi_bb75_11, phi_bb75_13, phi_bb75_14, phi_bb75_20);
  }

  TNode<IntPtrT> phi_bb63_7;
  TNode<IntPtrT> phi_bb63_8;
  TNode<IntPtrT> phi_bb63_9;
  TNode<IntPtrT> phi_bb63_10;
  TNode<IntPtrT> phi_bb63_11;
  TNode<IntPtrT> phi_bb63_13;
  TNode<BoolT> phi_bb63_14;
  TNode<IntPtrT> phi_bb63_20;
  if (block63.is_used()) {
    ca_.Bind(&block63, &phi_bb63_7, &phi_bb63_8, &phi_bb63_9, &phi_bb63_10, &phi_bb63_11, &phi_bb63_13, &phi_bb63_14, &phi_bb63_20);
    ca_.Goto(&block51, phi_bb63_7, phi_bb63_8, phi_bb63_9, phi_bb63_10, phi_bb63_11, phi_bb63_13, phi_bb63_14, phi_bb63_20);
  }

  TNode<IntPtrT> phi_bb51_7;
  TNode<IntPtrT> phi_bb51_8;
  TNode<IntPtrT> phi_bb51_9;
  TNode<IntPtrT> phi_bb51_10;
  TNode<IntPtrT> phi_bb51_11;
  TNode<IntPtrT> phi_bb51_13;
  TNode<BoolT> phi_bb51_14;
  TNode<IntPtrT> phi_bb51_20;
  TNode<IntPtrT> tmp262;
  TNode<IntPtrT> tmp263;
  if (block51.is_used()) {
    ca_.Bind(&block51, &phi_bb51_7, &phi_bb51_8, &phi_bb51_9, &phi_bb51_10, &phi_bb51_11, &phi_bb51_13, &phi_bb51_14, &phi_bb51_20);
    tmp262 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp263 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb51_20}, TNode<IntPtrT>{tmp262});
    ca_.Goto(&block46, phi_bb51_7, phi_bb51_8, phi_bb51_9, phi_bb51_10, phi_bb51_11, phi_bb51_13, phi_bb51_14, tmp263);
  }

  TNode<IntPtrT> phi_bb45_7;
  TNode<IntPtrT> phi_bb45_8;
  TNode<IntPtrT> phi_bb45_9;
  TNode<IntPtrT> phi_bb45_10;
  TNode<IntPtrT> phi_bb45_11;
  TNode<IntPtrT> phi_bb45_13;
  TNode<BoolT> phi_bb45_14;
  TNode<IntPtrT> phi_bb45_20;
  TNode<BoolT> tmp264;
  if (block45.is_used()) {
    ca_.Bind(&block45, &phi_bb45_7, &phi_bb45_8, &phi_bb45_9, &phi_bb45_10, &phi_bb45_11, &phi_bb45_13, &phi_bb45_14, &phi_bb45_20);
    tmp264 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{phi_bb45_14});
    ca_.Branch(tmp264, &block112, std::vector<compiler::Node*>{phi_bb45_7, phi_bb45_8, phi_bb45_9, phi_bb45_10, phi_bb45_11, phi_bb45_13, phi_bb45_14}, &block113, std::vector<compiler::Node*>{phi_bb45_7, phi_bb45_8, phi_bb45_9, phi_bb45_10, phi_bb45_11, phi_bb45_13, phi_bb45_14});
  }

  TNode<IntPtrT> phi_bb112_7;
  TNode<IntPtrT> phi_bb112_8;
  TNode<IntPtrT> phi_bb112_9;
  TNode<IntPtrT> phi_bb112_10;
  TNode<IntPtrT> phi_bb112_11;
  TNode<IntPtrT> phi_bb112_13;
  TNode<BoolT> phi_bb112_14;
  TNode<IntPtrT> tmp265;
  if (block112.is_used()) {
    ca_.Bind(&block112, &phi_bb112_7, &phi_bb112_8, &phi_bb112_9, &phi_bb112_10, &phi_bb112_11, &phi_bb112_13, &phi_bb112_14);
    tmp265 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block113, phi_bb112_7, phi_bb112_8, phi_bb112_9, phi_bb112_10, phi_bb112_11, tmp265, phi_bb112_14);
  }

  TNode<IntPtrT> phi_bb113_7;
  TNode<IntPtrT> phi_bb113_8;
  TNode<IntPtrT> phi_bb113_9;
  TNode<IntPtrT> phi_bb113_10;
  TNode<IntPtrT> phi_bb113_11;
  TNode<IntPtrT> phi_bb113_13;
  TNode<BoolT> phi_bb113_14;
  TNode<IntPtrT> tmp266;
  if (block113.is_used()) {
    ca_.Bind(&block113, &phi_bb113_7, &phi_bb113_8, &phi_bb113_9, &phi_bb113_10, &phi_bb113_11, &phi_bb113_13, &phi_bb113_14);
    tmp266 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block116, phi_bb113_7, phi_bb113_8, phi_bb113_9, phi_bb113_10, phi_bb113_11, phi_bb113_13, phi_bb113_14, tmp266);
  }

  TNode<IntPtrT> phi_bb116_7;
  TNode<IntPtrT> phi_bb116_8;
  TNode<IntPtrT> phi_bb116_9;
  TNode<IntPtrT> phi_bb116_10;
  TNode<IntPtrT> phi_bb116_11;
  TNode<IntPtrT> phi_bb116_13;
  TNode<BoolT> phi_bb116_14;
  TNode<IntPtrT> phi_bb116_20;
  TNode<IntPtrT> tmp267;
  TNode<BoolT> tmp268;
  if (block116.is_used()) {
    ca_.Bind(&block116, &phi_bb116_7, &phi_bb116_8, &phi_bb116_9, &phi_bb116_10, &phi_bb116_11, &phi_bb116_13, &phi_bb116_14, &phi_bb116_20);
    tmp267 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp3});
    tmp268 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb116_20}, TNode<IntPtrT>{tmp267});
    ca_.Branch(tmp268, &block114, std::vector<compiler::Node*>{phi_bb116_7, phi_bb116_8, phi_bb116_9, phi_bb116_10, phi_bb116_11, phi_bb116_13, phi_bb116_14, phi_bb116_20}, &block115, std::vector<compiler::Node*>{phi_bb116_7, phi_bb116_8, phi_bb116_9, phi_bb116_10, phi_bb116_11, phi_bb116_13, phi_bb116_14, phi_bb116_20});
  }

  TNode<IntPtrT> phi_bb114_7;
  TNode<IntPtrT> phi_bb114_8;
  TNode<IntPtrT> phi_bb114_9;
  TNode<IntPtrT> phi_bb114_10;
  TNode<IntPtrT> phi_bb114_11;
  TNode<IntPtrT> phi_bb114_13;
  TNode<BoolT> phi_bb114_14;
  TNode<IntPtrT> phi_bb114_20;
  TNode<IntPtrT> tmp269;
  TNode<IntPtrT> tmp270;
  TNode<Object> tmp271;
  TNode<IntPtrT> tmp272;
  TNode<Int32T> tmp273;
  TNode<Int32T> tmp274;
  TNode<Int32T> tmp275;
  TNode<Int32T> tmp276;
  TNode<BoolT> tmp277;
  if (block114.is_used()) {
    ca_.Bind(&block114, &phi_bb114_7, &phi_bb114_8, &phi_bb114_9, &phi_bb114_10, &phi_bb114_11, &phi_bb114_13, &phi_bb114_14, &phi_bb114_20);
    tmp269 = TimesSizeOf_int32_0(state_, TNode<IntPtrT>{phi_bb114_20});
    tmp270 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp110}, TNode<IntPtrT>{tmp269});
    std::tie(tmp271, tmp272) = NewReference_int32_0(state_, TNode<Object>{tmp109}, TNode<IntPtrT>{tmp270}).Flatten();
    tmp273 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp271, tmp272});
    tmp274 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmValueKindBitsMask);
    tmp275 = CodeStubAssembler(state_).Word32And(TNode<Int32T>{tmp273}, TNode<Int32T>{tmp274});
    tmp276 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRef);
    tmp277 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp275}, TNode<Int32T>{tmp276});
    ca_.Branch(tmp277, &block121, std::vector<compiler::Node*>{phi_bb114_7, phi_bb114_8, phi_bb114_9, phi_bb114_10, phi_bb114_11, phi_bb114_13, phi_bb114_14, phi_bb114_20}, &block122, std::vector<compiler::Node*>{phi_bb114_7, phi_bb114_8, phi_bb114_9, phi_bb114_10, phi_bb114_11, phi_bb114_13, phi_bb114_14, phi_bb114_20});
  }

  TNode<IntPtrT> phi_bb121_7;
  TNode<IntPtrT> phi_bb121_8;
  TNode<IntPtrT> phi_bb121_9;
  TNode<IntPtrT> phi_bb121_10;
  TNode<IntPtrT> phi_bb121_11;
  TNode<IntPtrT> phi_bb121_13;
  TNode<BoolT> phi_bb121_14;
  TNode<IntPtrT> phi_bb121_20;
  TNode<BoolT> tmp278;
  if (block121.is_used()) {
    ca_.Bind(&block121, &phi_bb121_7, &phi_bb121_8, &phi_bb121_9, &phi_bb121_10, &phi_bb121_11, &phi_bb121_13, &phi_bb121_14, &phi_bb121_20);
    tmp278 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block123, phi_bb121_7, phi_bb121_8, phi_bb121_9, phi_bb121_10, phi_bb121_11, phi_bb121_13, phi_bb121_14, phi_bb121_20, tmp278);
  }

  TNode<IntPtrT> phi_bb122_7;
  TNode<IntPtrT> phi_bb122_8;
  TNode<IntPtrT> phi_bb122_9;
  TNode<IntPtrT> phi_bb122_10;
  TNode<IntPtrT> phi_bb122_11;
  TNode<IntPtrT> phi_bb122_13;
  TNode<BoolT> phi_bb122_14;
  TNode<IntPtrT> phi_bb122_20;
  TNode<Int32T> tmp279;
  TNode<BoolT> tmp280;
  if (block122.is_used()) {
    ca_.Bind(&block122, &phi_bb122_7, &phi_bb122_8, &phi_bb122_9, &phi_bb122_10, &phi_bb122_11, &phi_bb122_13, &phi_bb122_14, &phi_bb122_20);
    tmp279 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::ValueKind::kRefNull);
    tmp280 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp275}, TNode<Int32T>{tmp279});
    ca_.Goto(&block123, phi_bb122_7, phi_bb122_8, phi_bb122_9, phi_bb122_10, phi_bb122_11, phi_bb122_13, phi_bb122_14, phi_bb122_20, tmp280);
  }

  TNode<IntPtrT> phi_bb123_7;
  TNode<IntPtrT> phi_bb123_8;
  TNode<IntPtrT> phi_bb123_9;
  TNode<IntPtrT> phi_bb123_10;
  TNode<IntPtrT> phi_bb123_11;
  TNode<IntPtrT> phi_bb123_13;
  TNode<BoolT> phi_bb123_14;
  TNode<IntPtrT> phi_bb123_20;
  TNode<BoolT> phi_bb123_24;
  if (block123.is_used()) {
    ca_.Bind(&block123, &phi_bb123_7, &phi_bb123_8, &phi_bb123_9, &phi_bb123_10, &phi_bb123_11, &phi_bb123_13, &phi_bb123_14, &phi_bb123_20, &phi_bb123_24);
    ca_.Branch(phi_bb123_24, &block119, std::vector<compiler::Node*>{phi_bb123_7, phi_bb123_8, phi_bb123_9, phi_bb123_10, phi_bb123_11, phi_bb123_13, phi_bb123_14, phi_bb123_20}, &block120, std::vector<compiler::Node*>{phi_bb123_7, phi_bb123_8, phi_bb123_9, phi_bb123_10, phi_bb123_11, phi_bb123_13, phi_bb123_14, phi_bb123_20});
  }

  TNode<IntPtrT> phi_bb119_7;
  TNode<IntPtrT> phi_bb119_8;
  TNode<IntPtrT> phi_bb119_9;
  TNode<IntPtrT> phi_bb119_10;
  TNode<IntPtrT> phi_bb119_11;
  TNode<IntPtrT> phi_bb119_13;
  TNode<BoolT> phi_bb119_14;
  TNode<IntPtrT> phi_bb119_20;
  TNode<IntPtrT> tmp281;
  TNode<IntPtrT> tmp282;
  TNode<IntPtrT> tmp283;
  TNode<BoolT> tmp284;
  if (block119.is_used()) {
    ca_.Bind(&block119, &phi_bb119_7, &phi_bb119_8, &phi_bb119_9, &phi_bb119_10, &phi_bb119_11, &phi_bb119_13, &phi_bb119_14, &phi_bb119_20);
    tmp281 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp282 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb119_7}, TNode<IntPtrT>{tmp281});
    tmp283 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp284 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb119_7}, TNode<IntPtrT>{tmp283});
    ca_.Branch(tmp284, &block125, std::vector<compiler::Node*>{phi_bb119_8, phi_bb119_9, phi_bb119_10, phi_bb119_11, phi_bb119_13, phi_bb119_14, phi_bb119_20}, &block126, std::vector<compiler::Node*>{phi_bb119_8, phi_bb119_9, phi_bb119_10, phi_bb119_11, phi_bb119_13, phi_bb119_14, phi_bb119_20});
  }

  TNode<IntPtrT> phi_bb125_8;
  TNode<IntPtrT> phi_bb125_9;
  TNode<IntPtrT> phi_bb125_10;
  TNode<IntPtrT> phi_bb125_11;
  TNode<IntPtrT> phi_bb125_13;
  TNode<BoolT> phi_bb125_14;
  TNode<IntPtrT> phi_bb125_20;
  TNode<Object> tmp285;
  TNode<IntPtrT> tmp286;
  TNode<IntPtrT> tmp287;
  TNode<IntPtrT> tmp288;
  if (block125.is_used()) {
    ca_.Bind(&block125, &phi_bb125_8, &phi_bb125_9, &phi_bb125_10, &phi_bb125_11, &phi_bb125_13, &phi_bb125_14, &phi_bb125_20);
    std::tie(tmp285, tmp286) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb125_9}).Flatten();
    tmp287 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp288 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb125_9}, TNode<IntPtrT>{tmp287});
    ca_.Goto(&block124, phi_bb125_8, tmp288, phi_bb125_10, phi_bb125_11, phi_bb125_13, phi_bb125_14, phi_bb125_20, tmp285, tmp286);
  }

  TNode<IntPtrT> phi_bb126_8;
  TNode<IntPtrT> phi_bb126_9;
  TNode<IntPtrT> phi_bb126_10;
  TNode<IntPtrT> phi_bb126_11;
  TNode<IntPtrT> phi_bb126_13;
  TNode<BoolT> phi_bb126_14;
  TNode<IntPtrT> phi_bb126_20;
  if (block126.is_used()) {
    ca_.Bind(&block126, &phi_bb126_8, &phi_bb126_9, &phi_bb126_10, &phi_bb126_11, &phi_bb126_13, &phi_bb126_14, &phi_bb126_20);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block128, phi_bb126_8, phi_bb126_9, phi_bb126_10, phi_bb126_11, phi_bb126_13, phi_bb126_14, phi_bb126_20);
    } else {
      ca_.Goto(&block129, phi_bb126_8, phi_bb126_9, phi_bb126_10, phi_bb126_11, phi_bb126_13, phi_bb126_14, phi_bb126_20);
    }
  }

  TNode<IntPtrT> phi_bb128_8;
  TNode<IntPtrT> phi_bb128_9;
  TNode<IntPtrT> phi_bb128_10;
  TNode<IntPtrT> phi_bb128_11;
  TNode<IntPtrT> phi_bb128_13;
  TNode<BoolT> phi_bb128_14;
  TNode<IntPtrT> phi_bb128_20;
  TNode<Object> tmp289;
  TNode<IntPtrT> tmp290;
  TNode<IntPtrT> tmp291;
  TNode<IntPtrT> tmp292;
  if (block128.is_used()) {
    ca_.Bind(&block128, &phi_bb128_8, &phi_bb128_9, &phi_bb128_10, &phi_bb128_11, &phi_bb128_13, &phi_bb128_14, &phi_bb128_20);
    std::tie(tmp289, tmp290) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb128_11}).Flatten();
    tmp291 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp292 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb128_11}, TNode<IntPtrT>{tmp291});
    ca_.Goto(&block127, phi_bb128_8, phi_bb128_9, phi_bb128_10, tmp292, phi_bb128_13, phi_bb128_14, phi_bb128_20, tmp289, tmp290);
  }

  TNode<IntPtrT> phi_bb129_8;
  TNode<IntPtrT> phi_bb129_9;
  TNode<IntPtrT> phi_bb129_10;
  TNode<IntPtrT> phi_bb129_11;
  TNode<IntPtrT> phi_bb129_13;
  TNode<BoolT> phi_bb129_14;
  TNode<IntPtrT> phi_bb129_20;
  TNode<IntPtrT> tmp293;
  TNode<BoolT> tmp294;
  if (block129.is_used()) {
    ca_.Bind(&block129, &phi_bb129_8, &phi_bb129_9, &phi_bb129_10, &phi_bb129_11, &phi_bb129_13, &phi_bb129_14, &phi_bb129_20);
    tmp293 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp294 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb129_13}, TNode<IntPtrT>{tmp293});
    ca_.Branch(tmp294, &block131, std::vector<compiler::Node*>{phi_bb129_8, phi_bb129_9, phi_bb129_10, phi_bb129_11, phi_bb129_13, phi_bb129_14, phi_bb129_20}, &block132, std::vector<compiler::Node*>{phi_bb129_8, phi_bb129_9, phi_bb129_10, phi_bb129_11, phi_bb129_13, phi_bb129_14, phi_bb129_20});
  }

  TNode<IntPtrT> phi_bb131_8;
  TNode<IntPtrT> phi_bb131_9;
  TNode<IntPtrT> phi_bb131_10;
  TNode<IntPtrT> phi_bb131_11;
  TNode<IntPtrT> phi_bb131_13;
  TNode<BoolT> phi_bb131_14;
  TNode<IntPtrT> phi_bb131_20;
  TNode<Object> tmp295;
  TNode<IntPtrT> tmp296;
  TNode<IntPtrT> tmp297;
  TNode<BoolT> tmp298;
  if (block131.is_used()) {
    ca_.Bind(&block131, &phi_bb131_8, &phi_bb131_9, &phi_bb131_10, &phi_bb131_11, &phi_bb131_13, &phi_bb131_14, &phi_bb131_20);
    std::tie(tmp295, tmp296) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb131_13}).Flatten();
    tmp297 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp298 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block127, phi_bb131_8, phi_bb131_9, phi_bb131_10, phi_bb131_11, tmp297, tmp298, phi_bb131_20, tmp295, tmp296);
  }

  TNode<IntPtrT> phi_bb132_8;
  TNode<IntPtrT> phi_bb132_9;
  TNode<IntPtrT> phi_bb132_10;
  TNode<IntPtrT> phi_bb132_11;
  TNode<IntPtrT> phi_bb132_13;
  TNode<BoolT> phi_bb132_14;
  TNode<IntPtrT> phi_bb132_20;
  TNode<Object> tmp299;
  TNode<IntPtrT> tmp300;
  TNode<IntPtrT> tmp301;
  TNode<IntPtrT> tmp302;
  TNode<IntPtrT> tmp303;
  TNode<IntPtrT> tmp304;
  TNode<BoolT> tmp305;
  if (block132.is_used()) {
    ca_.Bind(&block132, &phi_bb132_8, &phi_bb132_9, &phi_bb132_10, &phi_bb132_11, &phi_bb132_13, &phi_bb132_14, &phi_bb132_20);
    std::tie(tmp299, tmp300) = NewReference_intptr_0(state_, TNode<Object>{tmp94}, TNode<IntPtrT>{phi_bb132_11}).Flatten();
    tmp301 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp302 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb132_11}, TNode<IntPtrT>{tmp301});
    tmp303 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp304 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp302}, TNode<IntPtrT>{tmp303});
    tmp305 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block127, phi_bb132_8, phi_bb132_9, phi_bb132_10, tmp304, tmp302, tmp305, phi_bb132_20, tmp299, tmp300);
  }

  TNode<IntPtrT> phi_bb127_8;
  TNode<IntPtrT> phi_bb127_9;
  TNode<IntPtrT> phi_bb127_10;
  TNode<IntPtrT> phi_bb127_11;
  TNode<IntPtrT> phi_bb127_13;
  TNode<BoolT> phi_bb127_14;
  TNode<IntPtrT> phi_bb127_20;
  TNode<Object> phi_bb127_23;
  TNode<IntPtrT> phi_bb127_24;
  if (block127.is_used()) {
    ca_.Bind(&block127, &phi_bb127_8, &phi_bb127_9, &phi_bb127_10, &phi_bb127_11, &phi_bb127_13, &phi_bb127_14, &phi_bb127_20, &phi_bb127_23, &phi_bb127_24);
    ca_.Goto(&block124, phi_bb127_8, phi_bb127_9, phi_bb127_10, phi_bb127_11, phi_bb127_13, phi_bb127_14, phi_bb127_20, phi_bb127_23, phi_bb127_24);
  }

  TNode<IntPtrT> phi_bb124_8;
  TNode<IntPtrT> phi_bb124_9;
  TNode<IntPtrT> phi_bb124_10;
  TNode<IntPtrT> phi_bb124_11;
  TNode<IntPtrT> phi_bb124_13;
  TNode<BoolT> phi_bb124_14;
  TNode<IntPtrT> phi_bb124_20;
  TNode<Object> phi_bb124_23;
  TNode<IntPtrT> phi_bb124_24;
  TNode<IntPtrT> tmp306;
  TNode<Object> tmp307;
  TNode<Object> tmp308;
  TNode<IntPtrT> tmp309;
  TNode<IntPtrT> tmp310;
  TNode<UintPtrT> tmp311;
  TNode<UintPtrT> tmp312;
  TNode<BoolT> tmp313;
  if (block124.is_used()) {
    ca_.Bind(&block124, &phi_bb124_8, &phi_bb124_9, &phi_bb124_10, &phi_bb124_11, &phi_bb124_13, &phi_bb124_14, &phi_bb124_20, &phi_bb124_23, &phi_bb124_24);
    tmp306 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb124_23, phi_bb124_24});
    tmp307 = CodeStubAssembler(state_).BitcastWordToTagged(TNode<IntPtrT>{tmp306});
    std::tie(tmp308, tmp309, tmp310) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp85}).Flatten();
    tmp311 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb124_20});
    tmp312 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp310});
    tmp313 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp311}, TNode<UintPtrT>{tmp312});
    ca_.Branch(tmp313, &block137, std::vector<compiler::Node*>{phi_bb124_8, phi_bb124_9, phi_bb124_10, phi_bb124_11, phi_bb124_13, phi_bb124_14, phi_bb124_20, phi_bb124_23, phi_bb124_24, phi_bb124_20, phi_bb124_20, phi_bb124_20, phi_bb124_20}, &block138, std::vector<compiler::Node*>{phi_bb124_8, phi_bb124_9, phi_bb124_10, phi_bb124_11, phi_bb124_13, phi_bb124_14, phi_bb124_20, phi_bb124_23, phi_bb124_24, phi_bb124_20, phi_bb124_20, phi_bb124_20, phi_bb124_20});
  }

  TNode<IntPtrT> phi_bb137_8;
  TNode<IntPtrT> phi_bb137_9;
  TNode<IntPtrT> phi_bb137_10;
  TNode<IntPtrT> phi_bb137_11;
  TNode<IntPtrT> phi_bb137_13;
  TNode<BoolT> phi_bb137_14;
  TNode<IntPtrT> phi_bb137_20;
  TNode<Object> phi_bb137_23;
  TNode<IntPtrT> phi_bb137_24;
  TNode<IntPtrT> phi_bb137_31;
  TNode<IntPtrT> phi_bb137_32;
  TNode<IntPtrT> phi_bb137_36;
  TNode<IntPtrT> phi_bb137_37;
  TNode<IntPtrT> tmp314;
  TNode<IntPtrT> tmp315;
  TNode<Object> tmp316;
  TNode<IntPtrT> tmp317;
  if (block137.is_used()) {
    ca_.Bind(&block137, &phi_bb137_8, &phi_bb137_9, &phi_bb137_10, &phi_bb137_11, &phi_bb137_13, &phi_bb137_14, &phi_bb137_20, &phi_bb137_23, &phi_bb137_24, &phi_bb137_31, &phi_bb137_32, &phi_bb137_36, &phi_bb137_37);
    tmp314 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb137_37});
    tmp315 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp309}, TNode<IntPtrT>{tmp314});
    std::tie(tmp316, tmp317) = NewReference_Object_0(state_, TNode<Object>{tmp308}, TNode<IntPtrT>{tmp315}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp316, tmp317}, tmp307);
    ca_.Goto(&block120, tmp282, phi_bb137_8, phi_bb137_9, phi_bb137_10, phi_bb137_11, phi_bb137_13, phi_bb137_14, phi_bb137_20);
  }

  TNode<IntPtrT> phi_bb138_8;
  TNode<IntPtrT> phi_bb138_9;
  TNode<IntPtrT> phi_bb138_10;
  TNode<IntPtrT> phi_bb138_11;
  TNode<IntPtrT> phi_bb138_13;
  TNode<BoolT> phi_bb138_14;
  TNode<IntPtrT> phi_bb138_20;
  TNode<Object> phi_bb138_23;
  TNode<IntPtrT> phi_bb138_24;
  TNode<IntPtrT> phi_bb138_31;
  TNode<IntPtrT> phi_bb138_32;
  TNode<IntPtrT> phi_bb138_36;
  TNode<IntPtrT> phi_bb138_37;
  if (block138.is_used()) {
    ca_.Bind(&block138, &phi_bb138_8, &phi_bb138_9, &phi_bb138_10, &phi_bb138_11, &phi_bb138_13, &phi_bb138_14, &phi_bb138_20, &phi_bb138_23, &phi_bb138_24, &phi_bb138_31, &phi_bb138_32, &phi_bb138_36, &phi_bb138_37);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb120_7;
  TNode<IntPtrT> phi_bb120_8;
  TNode<IntPtrT> phi_bb120_9;
  TNode<IntPtrT> phi_bb120_10;
  TNode<IntPtrT> phi_bb120_11;
  TNode<IntPtrT> phi_bb120_13;
  TNode<BoolT> phi_bb120_14;
  TNode<IntPtrT> phi_bb120_20;
  TNode<IntPtrT> tmp318;
  TNode<IntPtrT> tmp319;
  if (block120.is_used()) {
    ca_.Bind(&block120, &phi_bb120_7, &phi_bb120_8, &phi_bb120_9, &phi_bb120_10, &phi_bb120_11, &phi_bb120_13, &phi_bb120_14, &phi_bb120_20);
    tmp318 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp319 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb120_20}, TNode<IntPtrT>{tmp318});
    ca_.Goto(&block116, phi_bb120_7, phi_bb120_8, phi_bb120_9, phi_bb120_10, phi_bb120_11, phi_bb120_13, phi_bb120_14, tmp319);
  }

  TNode<IntPtrT> phi_bb115_7;
  TNode<IntPtrT> phi_bb115_8;
  TNode<IntPtrT> phi_bb115_9;
  TNode<IntPtrT> phi_bb115_10;
  TNode<IntPtrT> phi_bb115_11;
  TNode<IntPtrT> phi_bb115_13;
  TNode<BoolT> phi_bb115_14;
  TNode<IntPtrT> phi_bb115_20;
  if (block115.is_used()) {
    ca_.Bind(&block115, &phi_bb115_7, &phi_bb115_8, &phi_bb115_9, &phi_bb115_10, &phi_bb115_11, &phi_bb115_13, &phi_bb115_14, &phi_bb115_20);
    ca_.Goto(&block43, phi_bb115_7, phi_bb115_8, phi_bb115_9, phi_bb115_10, phi_bb115_11, phi_bb115_13, phi_bb115_14);
  }

  TNode<IntPtrT> phi_bb43_7;
  TNode<IntPtrT> phi_bb43_8;
  TNode<IntPtrT> phi_bb43_9;
  TNode<IntPtrT> phi_bb43_10;
  TNode<IntPtrT> phi_bb43_11;
  TNode<IntPtrT> phi_bb43_13;
  TNode<BoolT> phi_bb43_14;
  TNode<IntPtrT> tmp320;
  TNode<RawPtrT> tmp321;
  TNode<IntPtrT> tmp322;
  TNode<RawPtrT> tmp323;
  TNode<Object> tmp324;
  TNode<IntPtrT> tmp325;
  TNode<IntPtrT> tmp326;
  TNode<IntPtrT> tmp327;
  TNode<IntPtrT> tmp328;
  TNode<IntPtrT> tmp329;
  TNode<IntPtrT> tmp330;
  TNode<IntPtrT> tmp331;
  TNode<BoolT> tmp332;
  TNode<IntPtrT> tmp333;
  if (block43.is_used()) {
    ca_.Bind(&block43, &phi_bb43_7, &phi_bb43_8, &phi_bb43_9, &phi_bb43_10, &phi_bb43_11, &phi_bb43_13, &phi_bb43_14);
    tmp320 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferGPReturnRegister1);
    tmp321 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp320});
    tmp322 = FromConstexpr_intptr_constexpr_intptr_0(state_, JSToWasmWrapperFrameConstants::kWrapperBufferFPReturnRegister1);
    tmp323 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{parameter2}, TNode<IntPtrT>{tmp322});
    std::tie(tmp324, tmp325, tmp326, tmp327, tmp328, tmp329, tmp330, tmp331, tmp332) = LocationAllocatorForReturns_0(state_, TNode<RawPtrT>{tmp321}, TNode<RawPtrT>{tmp323}, TNode<RawPtrT>{tmp89}).Flatten();
    tmp333 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block143, tmp325, tmp326, tmp327, tmp328, tmp329, tmp331, tmp332, tmp333);
  }

  TNode<IntPtrT> phi_bb143_7;
  TNode<IntPtrT> phi_bb143_8;
  TNode<IntPtrT> phi_bb143_9;
  TNode<IntPtrT> phi_bb143_10;
  TNode<IntPtrT> phi_bb143_11;
  TNode<IntPtrT> phi_bb143_13;
  TNode<BoolT> phi_bb143_14;
  TNode<IntPtrT> phi_bb143_20;
  TNode<IntPtrT> tmp334;
  TNode<BoolT> tmp335;
  if (block143.is_used()) {
    ca_.Bind(&block143, &phi_bb143_7, &phi_bb143_8, &phi_bb143_9, &phi_bb143_10, &phi_bb143_11, &phi_bb143_13, &phi_bb143_14, &phi_bb143_20);
    tmp334 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp3});
    tmp335 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb143_20}, TNode<IntPtrT>{tmp334});
    ca_.Branch(tmp335, &block141, std::vector<compiler::Node*>{phi_bb143_7, phi_bb143_8, phi_bb143_9, phi_bb143_10, phi_bb143_11, phi_bb143_13, phi_bb143_14, phi_bb143_20}, &block142, std::vector<compiler::Node*>{phi_bb143_7, phi_bb143_8, phi_bb143_9, phi_bb143_10, phi_bb143_11, phi_bb143_13, phi_bb143_14, phi_bb143_20});
  }

  TNode<IntPtrT> phi_bb141_7;
  TNode<IntPtrT> phi_bb141_8;
  TNode<IntPtrT> phi_bb141_9;
  TNode<IntPtrT> phi_bb141_10;
  TNode<IntPtrT> phi_bb141_11;
  TNode<IntPtrT> phi_bb141_13;
  TNode<BoolT> phi_bb141_14;
  TNode<IntPtrT> phi_bb141_20;
  TNode<IntPtrT> tmp336;
  TNode<IntPtrT> tmp337;
  TNode<Object> tmp338;
  TNode<IntPtrT> tmp339;
  TNode<Int32T> tmp340;
  TNode<Int32T> tmp341;
  TNode<BoolT> tmp342;
  if (block141.is_used()) {
    ca_.Bind(&block141, &phi_bb141_7, &phi_bb141_8, &phi_bb141_9, &phi_bb141_10, &phi_bb141_11, &phi_bb141_13, &phi_bb141_14, &phi_bb141_20);
    tmp336 = TimesSizeOf_int32_0(state_, TNode<IntPtrT>{phi_bb141_20});
    tmp337 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp110}, TNode<IntPtrT>{tmp336});
    std::tie(tmp338, tmp339) = NewReference_int32_0(state_, TNode<Object>{tmp109}, TNode<IntPtrT>{tmp337}).Flatten();
    tmp340 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp338, tmp339});
    tmp341 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI32.raw_bit_field());
    tmp342 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp340}, TNode<Int32T>{tmp341});
    ca_.Branch(tmp342, &block146, std::vector<compiler::Node*>{phi_bb141_7, phi_bb141_8, phi_bb141_9, phi_bb141_10, phi_bb141_11, phi_bb141_13, phi_bb141_14, phi_bb141_20}, &block147, std::vector<compiler::Node*>{phi_bb141_7, phi_bb141_8, phi_bb141_9, phi_bb141_10, phi_bb141_11, phi_bb141_13, phi_bb141_14, phi_bb141_20});
  }

  TNode<IntPtrT> phi_bb146_7;
  TNode<IntPtrT> phi_bb146_8;
  TNode<IntPtrT> phi_bb146_9;
  TNode<IntPtrT> phi_bb146_10;
  TNode<IntPtrT> phi_bb146_11;
  TNode<IntPtrT> phi_bb146_13;
  TNode<BoolT> phi_bb146_14;
  TNode<IntPtrT> phi_bb146_20;
  TNode<IntPtrT> tmp343;
  TNode<IntPtrT> tmp344;
  TNode<IntPtrT> tmp345;
  TNode<BoolT> tmp346;
  if (block146.is_used()) {
    ca_.Bind(&block146, &phi_bb146_7, &phi_bb146_8, &phi_bb146_9, &phi_bb146_10, &phi_bb146_11, &phi_bb146_13, &phi_bb146_14, &phi_bb146_20);
    tmp343 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp344 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb146_7}, TNode<IntPtrT>{tmp343});
    tmp345 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp346 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb146_7}, TNode<IntPtrT>{tmp345});
    ca_.Branch(tmp346, &block150, std::vector<compiler::Node*>{phi_bb146_8, phi_bb146_9, phi_bb146_10, phi_bb146_11, phi_bb146_13, phi_bb146_14, phi_bb146_20}, &block151, std::vector<compiler::Node*>{phi_bb146_8, phi_bb146_9, phi_bb146_10, phi_bb146_11, phi_bb146_13, phi_bb146_14, phi_bb146_20});
  }

  TNode<IntPtrT> phi_bb150_8;
  TNode<IntPtrT> phi_bb150_9;
  TNode<IntPtrT> phi_bb150_10;
  TNode<IntPtrT> phi_bb150_11;
  TNode<IntPtrT> phi_bb150_13;
  TNode<BoolT> phi_bb150_14;
  TNode<IntPtrT> phi_bb150_20;
  TNode<Object> tmp347;
  TNode<IntPtrT> tmp348;
  TNode<IntPtrT> tmp349;
  TNode<IntPtrT> tmp350;
  if (block150.is_used()) {
    ca_.Bind(&block150, &phi_bb150_8, &phi_bb150_9, &phi_bb150_10, &phi_bb150_11, &phi_bb150_13, &phi_bb150_14, &phi_bb150_20);
    std::tie(tmp347, tmp348) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb150_9}).Flatten();
    tmp349 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp350 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb150_9}, TNode<IntPtrT>{tmp349});
    ca_.Goto(&block149, phi_bb150_8, tmp350, phi_bb150_10, phi_bb150_11, phi_bb150_13, phi_bb150_14, phi_bb150_20, tmp347, tmp348);
  }

  TNode<IntPtrT> phi_bb151_8;
  TNode<IntPtrT> phi_bb151_9;
  TNode<IntPtrT> phi_bb151_10;
  TNode<IntPtrT> phi_bb151_11;
  TNode<IntPtrT> phi_bb151_13;
  TNode<BoolT> phi_bb151_14;
  TNode<IntPtrT> phi_bb151_20;
  if (block151.is_used()) {
    ca_.Bind(&block151, &phi_bb151_8, &phi_bb151_9, &phi_bb151_10, &phi_bb151_11, &phi_bb151_13, &phi_bb151_14, &phi_bb151_20);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block153, phi_bb151_8, phi_bb151_9, phi_bb151_10, phi_bb151_11, phi_bb151_13, phi_bb151_14, phi_bb151_20);
    } else {
      ca_.Goto(&block154, phi_bb151_8, phi_bb151_9, phi_bb151_10, phi_bb151_11, phi_bb151_13, phi_bb151_14, phi_bb151_20);
    }
  }

  TNode<IntPtrT> phi_bb153_8;
  TNode<IntPtrT> phi_bb153_9;
  TNode<IntPtrT> phi_bb153_10;
  TNode<IntPtrT> phi_bb153_11;
  TNode<IntPtrT> phi_bb153_13;
  TNode<BoolT> phi_bb153_14;
  TNode<IntPtrT> phi_bb153_20;
  TNode<Object> tmp351;
  TNode<IntPtrT> tmp352;
  TNode<IntPtrT> tmp353;
  TNode<IntPtrT> tmp354;
  if (block153.is_used()) {
    ca_.Bind(&block153, &phi_bb153_8, &phi_bb153_9, &phi_bb153_10, &phi_bb153_11, &phi_bb153_13, &phi_bb153_14, &phi_bb153_20);
    std::tie(tmp351, tmp352) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb153_11}).Flatten();
    tmp353 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp354 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb153_11}, TNode<IntPtrT>{tmp353});
    ca_.Goto(&block152, phi_bb153_8, phi_bb153_9, phi_bb153_10, tmp354, phi_bb153_13, phi_bb153_14, phi_bb153_20, tmp351, tmp352);
  }

  TNode<IntPtrT> phi_bb154_8;
  TNode<IntPtrT> phi_bb154_9;
  TNode<IntPtrT> phi_bb154_10;
  TNode<IntPtrT> phi_bb154_11;
  TNode<IntPtrT> phi_bb154_13;
  TNode<BoolT> phi_bb154_14;
  TNode<IntPtrT> phi_bb154_20;
  TNode<IntPtrT> tmp355;
  TNode<BoolT> tmp356;
  if (block154.is_used()) {
    ca_.Bind(&block154, &phi_bb154_8, &phi_bb154_9, &phi_bb154_10, &phi_bb154_11, &phi_bb154_13, &phi_bb154_14, &phi_bb154_20);
    tmp355 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp356 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb154_13}, TNode<IntPtrT>{tmp355});
    ca_.Branch(tmp356, &block156, std::vector<compiler::Node*>{phi_bb154_8, phi_bb154_9, phi_bb154_10, phi_bb154_11, phi_bb154_13, phi_bb154_14, phi_bb154_20}, &block157, std::vector<compiler::Node*>{phi_bb154_8, phi_bb154_9, phi_bb154_10, phi_bb154_11, phi_bb154_13, phi_bb154_14, phi_bb154_20});
  }

  TNode<IntPtrT> phi_bb156_8;
  TNode<IntPtrT> phi_bb156_9;
  TNode<IntPtrT> phi_bb156_10;
  TNode<IntPtrT> phi_bb156_11;
  TNode<IntPtrT> phi_bb156_13;
  TNode<BoolT> phi_bb156_14;
  TNode<IntPtrT> phi_bb156_20;
  TNode<Object> tmp357;
  TNode<IntPtrT> tmp358;
  TNode<IntPtrT> tmp359;
  TNode<BoolT> tmp360;
  if (block156.is_used()) {
    ca_.Bind(&block156, &phi_bb156_8, &phi_bb156_9, &phi_bb156_10, &phi_bb156_11, &phi_bb156_13, &phi_bb156_14, &phi_bb156_20);
    std::tie(tmp357, tmp358) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb156_13}).Flatten();
    tmp359 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp360 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block152, phi_bb156_8, phi_bb156_9, phi_bb156_10, phi_bb156_11, tmp359, tmp360, phi_bb156_20, tmp357, tmp358);
  }

  TNode<IntPtrT> phi_bb157_8;
  TNode<IntPtrT> phi_bb157_9;
  TNode<IntPtrT> phi_bb157_10;
  TNode<IntPtrT> phi_bb157_11;
  TNode<IntPtrT> phi_bb157_13;
  TNode<BoolT> phi_bb157_14;
  TNode<IntPtrT> phi_bb157_20;
  TNode<Object> tmp361;
  TNode<IntPtrT> tmp362;
  TNode<IntPtrT> tmp363;
  TNode<IntPtrT> tmp364;
  TNode<IntPtrT> tmp365;
  TNode<IntPtrT> tmp366;
  TNode<BoolT> tmp367;
  if (block157.is_used()) {
    ca_.Bind(&block157, &phi_bb157_8, &phi_bb157_9, &phi_bb157_10, &phi_bb157_11, &phi_bb157_13, &phi_bb157_14, &phi_bb157_20);
    std::tie(tmp361, tmp362) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb157_11}).Flatten();
    tmp363 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp364 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb157_11}, TNode<IntPtrT>{tmp363});
    tmp365 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp366 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp364}, TNode<IntPtrT>{tmp365});
    tmp367 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block152, phi_bb157_8, phi_bb157_9, phi_bb157_10, tmp366, tmp364, tmp367, phi_bb157_20, tmp361, tmp362);
  }

  TNode<IntPtrT> phi_bb152_8;
  TNode<IntPtrT> phi_bb152_9;
  TNode<IntPtrT> phi_bb152_10;
  TNode<IntPtrT> phi_bb152_11;
  TNode<IntPtrT> phi_bb152_13;
  TNode<BoolT> phi_bb152_14;
  TNode<IntPtrT> phi_bb152_20;
  TNode<Object> phi_bb152_22;
  TNode<IntPtrT> phi_bb152_23;
  if (block152.is_used()) {
    ca_.Bind(&block152, &phi_bb152_8, &phi_bb152_9, &phi_bb152_10, &phi_bb152_11, &phi_bb152_13, &phi_bb152_14, &phi_bb152_20, &phi_bb152_22, &phi_bb152_23);
    ca_.Goto(&block149, phi_bb152_8, phi_bb152_9, phi_bb152_10, phi_bb152_11, phi_bb152_13, phi_bb152_14, phi_bb152_20, phi_bb152_22, phi_bb152_23);
  }

  TNode<IntPtrT> phi_bb149_8;
  TNode<IntPtrT> phi_bb149_9;
  TNode<IntPtrT> phi_bb149_10;
  TNode<IntPtrT> phi_bb149_11;
  TNode<IntPtrT> phi_bb149_13;
  TNode<BoolT> phi_bb149_14;
  TNode<IntPtrT> phi_bb149_20;
  TNode<Object> phi_bb149_22;
  TNode<IntPtrT> phi_bb149_23;
  if (block149.is_used()) {
    ca_.Bind(&block149, &phi_bb149_8, &phi_bb149_9, &phi_bb149_10, &phi_bb149_11, &phi_bb149_13, &phi_bb149_14, &phi_bb149_20, &phi_bb149_22, &phi_bb149_23);
    if ((wasm::kIsBigEndian)) {
      ca_.Goto(&block158, phi_bb149_8, phi_bb149_9, phi_bb149_10, phi_bb149_11, phi_bb149_13, phi_bb149_14, phi_bb149_20, phi_bb149_22, phi_bb149_23);
    } else {
      ca_.Goto(&block159, phi_bb149_8, phi_bb149_9, phi_bb149_10, phi_bb149_11, phi_bb149_13, phi_bb149_14, phi_bb149_20, phi_bb149_22, phi_bb149_23);
    }
  }

  TNode<IntPtrT> phi_bb158_8;
  TNode<IntPtrT> phi_bb158_9;
  TNode<IntPtrT> phi_bb158_10;
  TNode<IntPtrT> phi_bb158_11;
  TNode<IntPtrT> phi_bb158_13;
  TNode<BoolT> phi_bb158_14;
  TNode<IntPtrT> phi_bb158_20;
  TNode<Object> phi_bb158_22;
  TNode<IntPtrT> phi_bb158_23;
  TNode<Object> tmp368;
  TNode<IntPtrT> tmp369;
  TNode<Int64T> tmp370;
  TNode<Int32T> tmp371;
  if (block158.is_used()) {
    ca_.Bind(&block158, &phi_bb158_8, &phi_bb158_9, &phi_bb158_10, &phi_bb158_11, &phi_bb158_13, &phi_bb158_14, &phi_bb158_20, &phi_bb158_22, &phi_bb158_23);
    std::tie(tmp368, tmp369) = RefCast_int64_0(state_, TorqueStructReference_intptr_0{TNode<Object>{phi_bb158_22}, TNode<IntPtrT>{phi_bb158_23}, TorqueStructUnsafe_0{}}).Flatten();
    tmp370 = CodeStubAssembler(state_).LoadReference<Int64T>(CodeStubAssembler::Reference{tmp368, tmp369});
    tmp371 = CodeStubAssembler(state_).TruncateInt64ToInt32(TNode<Int64T>{tmp370});
    ca_.Goto(&block160, phi_bb158_8, phi_bb158_9, phi_bb158_10, phi_bb158_11, phi_bb158_13, phi_bb158_14, phi_bb158_20, phi_bb158_22, phi_bb158_23, tmp371);
  }

  TNode<IntPtrT> phi_bb159_8;
  TNode<IntPtrT> phi_bb159_9;
  TNode<IntPtrT> phi_bb159_10;
  TNode<IntPtrT> phi_bb159_11;
  TNode<IntPtrT> phi_bb159_13;
  TNode<BoolT> phi_bb159_14;
  TNode<IntPtrT> phi_bb159_20;
  TNode<Object> phi_bb159_22;
  TNode<IntPtrT> phi_bb159_23;
  TNode<Object> tmp372;
  TNode<IntPtrT> tmp373;
  TNode<Int32T> tmp374;
  if (block159.is_used()) {
    ca_.Bind(&block159, &phi_bb159_8, &phi_bb159_9, &phi_bb159_10, &phi_bb159_11, &phi_bb159_13, &phi_bb159_14, &phi_bb159_20, &phi_bb159_22, &phi_bb159_23);
    std::tie(tmp372, tmp373) = RefCast_int32_0(state_, TorqueStructReference_intptr_0{TNode<Object>{phi_bb159_22}, TNode<IntPtrT>{phi_bb159_23}, TorqueStructUnsafe_0{}}).Flatten();
    tmp374 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{tmp372, tmp373});
    ca_.Goto(&block160, phi_bb159_8, phi_bb159_9, phi_bb159_10, phi_bb159_11, phi_bb159_13, phi_bb159_14, phi_bb159_20, phi_bb159_22, phi_bb159_23, tmp374);
  }

  TNode<IntPtrT> phi_bb160_8;
  TNode<IntPtrT> phi_bb160_9;
  TNode<IntPtrT> phi_bb160_10;
  TNode<IntPtrT> phi_bb160_11;
  TNode<IntPtrT> phi_bb160_13;
  TNode<BoolT> phi_bb160_14;
  TNode<IntPtrT> phi_bb160_20;
  TNode<Object> phi_bb160_22;
  TNode<IntPtrT> phi_bb160_23;
  TNode<Int32T> phi_bb160_24;
  TNode<Object> tmp375;
  TNode<IntPtrT> tmp376;
  TNode<IntPtrT> tmp377;
  TNode<UintPtrT> tmp378;
  TNode<UintPtrT> tmp379;
  TNode<BoolT> tmp380;
  if (block160.is_used()) {
    ca_.Bind(&block160, &phi_bb160_8, &phi_bb160_9, &phi_bb160_10, &phi_bb160_11, &phi_bb160_13, &phi_bb160_14, &phi_bb160_20, &phi_bb160_22, &phi_bb160_23, &phi_bb160_24);
    std::tie(tmp375, tmp376, tmp377) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp85}).Flatten();
    tmp378 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb160_20});
    tmp379 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp377});
    tmp380 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp378}, TNode<UintPtrT>{tmp379});
    ca_.Branch(tmp380, &block165, std::vector<compiler::Node*>{phi_bb160_8, phi_bb160_9, phi_bb160_10, phi_bb160_11, phi_bb160_13, phi_bb160_14, phi_bb160_20, phi_bb160_22, phi_bb160_23, phi_bb160_20, phi_bb160_20, phi_bb160_20, phi_bb160_20}, &block166, std::vector<compiler::Node*>{phi_bb160_8, phi_bb160_9, phi_bb160_10, phi_bb160_11, phi_bb160_13, phi_bb160_14, phi_bb160_20, phi_bb160_22, phi_bb160_23, phi_bb160_20, phi_bb160_20, phi_bb160_20, phi_bb160_20});
  }

  TNode<IntPtrT> phi_bb165_8;
  TNode<IntPtrT> phi_bb165_9;
  TNode<IntPtrT> phi_bb165_10;
  TNode<IntPtrT> phi_bb165_11;
  TNode<IntPtrT> phi_bb165_13;
  TNode<BoolT> phi_bb165_14;
  TNode<IntPtrT> phi_bb165_20;
  TNode<Object> phi_bb165_22;
  TNode<IntPtrT> phi_bb165_23;
  TNode<IntPtrT> phi_bb165_29;
  TNode<IntPtrT> phi_bb165_30;
  TNode<IntPtrT> phi_bb165_34;
  TNode<IntPtrT> phi_bb165_35;
  TNode<IntPtrT> tmp381;
  TNode<IntPtrT> tmp382;
  TNode<Object> tmp383;
  TNode<IntPtrT> tmp384;
  TNode<Number> tmp385;
  if (block165.is_used()) {
    ca_.Bind(&block165, &phi_bb165_8, &phi_bb165_9, &phi_bb165_10, &phi_bb165_11, &phi_bb165_13, &phi_bb165_14, &phi_bb165_20, &phi_bb165_22, &phi_bb165_23, &phi_bb165_29, &phi_bb165_30, &phi_bb165_34, &phi_bb165_35);
    tmp381 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb165_35});
    tmp382 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp376}, TNode<IntPtrT>{tmp381});
    std::tie(tmp383, tmp384) = NewReference_Object_0(state_, TNode<Object>{tmp375}, TNode<IntPtrT>{tmp382}).Flatten();
    tmp385 = Convert_Number_int32_0(state_, TNode<Int32T>{phi_bb160_24});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp383, tmp384}, tmp385);
    ca_.Goto(&block148, tmp344, phi_bb165_8, phi_bb165_9, phi_bb165_10, phi_bb165_11, phi_bb165_13, phi_bb165_14, phi_bb165_20);
  }

  TNode<IntPtrT> phi_bb166_8;
  TNode<IntPtrT> phi_bb166_9;
  TNode<IntPtrT> phi_bb166_10;
  TNode<IntPtrT> phi_bb166_11;
  TNode<IntPtrT> phi_bb166_13;
  TNode<BoolT> phi_bb166_14;
  TNode<IntPtrT> phi_bb166_20;
  TNode<Object> phi_bb166_22;
  TNode<IntPtrT> phi_bb166_23;
  TNode<IntPtrT> phi_bb166_29;
  TNode<IntPtrT> phi_bb166_30;
  TNode<IntPtrT> phi_bb166_34;
  TNode<IntPtrT> phi_bb166_35;
  if (block166.is_used()) {
    ca_.Bind(&block166, &phi_bb166_8, &phi_bb166_9, &phi_bb166_10, &phi_bb166_11, &phi_bb166_13, &phi_bb166_14, &phi_bb166_20, &phi_bb166_22, &phi_bb166_23, &phi_bb166_29, &phi_bb166_30, &phi_bb166_34, &phi_bb166_35);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb147_7;
  TNode<IntPtrT> phi_bb147_8;
  TNode<IntPtrT> phi_bb147_9;
  TNode<IntPtrT> phi_bb147_10;
  TNode<IntPtrT> phi_bb147_11;
  TNode<IntPtrT> phi_bb147_13;
  TNode<BoolT> phi_bb147_14;
  TNode<IntPtrT> phi_bb147_20;
  TNode<Int32T> tmp386;
  TNode<BoolT> tmp387;
  if (block147.is_used()) {
    ca_.Bind(&block147, &phi_bb147_7, &phi_bb147_8, &phi_bb147_9, &phi_bb147_10, &phi_bb147_11, &phi_bb147_13, &phi_bb147_14, &phi_bb147_20);
    tmp386 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF32.raw_bit_field());
    tmp387 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp340}, TNode<Int32T>{tmp386});
    ca_.Branch(tmp387, &block169, std::vector<compiler::Node*>{phi_bb147_7, phi_bb147_8, phi_bb147_9, phi_bb147_10, phi_bb147_11, phi_bb147_13, phi_bb147_14, phi_bb147_20}, &block170, std::vector<compiler::Node*>{phi_bb147_7, phi_bb147_8, phi_bb147_9, phi_bb147_10, phi_bb147_11, phi_bb147_13, phi_bb147_14, phi_bb147_20});
  }

  TNode<IntPtrT> phi_bb169_7;
  TNode<IntPtrT> phi_bb169_8;
  TNode<IntPtrT> phi_bb169_9;
  TNode<IntPtrT> phi_bb169_10;
  TNode<IntPtrT> phi_bb169_11;
  TNode<IntPtrT> phi_bb169_13;
  TNode<BoolT> phi_bb169_14;
  TNode<IntPtrT> phi_bb169_20;
  TNode<IntPtrT> tmp388;
  TNode<IntPtrT> tmp389;
  TNode<IntPtrT> tmp390;
  TNode<BoolT> tmp391;
  if (block169.is_used()) {
    ca_.Bind(&block169, &phi_bb169_7, &phi_bb169_8, &phi_bb169_9, &phi_bb169_10, &phi_bb169_11, &phi_bb169_13, &phi_bb169_14, &phi_bb169_20);
    tmp388 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp389 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb169_8}, TNode<IntPtrT>{tmp388});
    tmp390 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp391 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb169_8}, TNode<IntPtrT>{tmp390});
    ca_.Branch(tmp391, &block173, std::vector<compiler::Node*>{phi_bb169_7, phi_bb169_9, phi_bb169_10, phi_bb169_11, phi_bb169_13, phi_bb169_14, phi_bb169_20}, &block174, std::vector<compiler::Node*>{phi_bb169_7, phi_bb169_9, phi_bb169_10, phi_bb169_11, phi_bb169_13, phi_bb169_14, phi_bb169_20});
  }

  TNode<IntPtrT> phi_bb173_7;
  TNode<IntPtrT> phi_bb173_9;
  TNode<IntPtrT> phi_bb173_10;
  TNode<IntPtrT> phi_bb173_11;
  TNode<IntPtrT> phi_bb173_13;
  TNode<BoolT> phi_bb173_14;
  TNode<IntPtrT> phi_bb173_20;
  TNode<Object> tmp392;
  TNode<IntPtrT> tmp393;
  TNode<IntPtrT> tmp394;
  TNode<IntPtrT> tmp395;
  if (block173.is_used()) {
    ca_.Bind(&block173, &phi_bb173_7, &phi_bb173_9, &phi_bb173_10, &phi_bb173_11, &phi_bb173_13, &phi_bb173_14, &phi_bb173_20);
    std::tie(tmp392, tmp393) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb173_10}).Flatten();
    tmp394 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp395 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb173_10}, TNode<IntPtrT>{tmp394});
    ca_.Goto(&block172, phi_bb173_7, phi_bb173_9, tmp395, phi_bb173_11, phi_bb173_13, phi_bb173_14, phi_bb173_20, tmp392, tmp393);
  }

  TNode<IntPtrT> phi_bb174_7;
  TNode<IntPtrT> phi_bb174_9;
  TNode<IntPtrT> phi_bb174_10;
  TNode<IntPtrT> phi_bb174_11;
  TNode<IntPtrT> phi_bb174_13;
  TNode<BoolT> phi_bb174_14;
  TNode<IntPtrT> phi_bb174_20;
  if (block174.is_used()) {
    ca_.Bind(&block174, &phi_bb174_7, &phi_bb174_9, &phi_bb174_10, &phi_bb174_11, &phi_bb174_13, &phi_bb174_14, &phi_bb174_20);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block176, phi_bb174_7, phi_bb174_9, phi_bb174_10, phi_bb174_11, phi_bb174_13, phi_bb174_14, phi_bb174_20);
    } else {
      ca_.Goto(&block177, phi_bb174_7, phi_bb174_9, phi_bb174_10, phi_bb174_11, phi_bb174_13, phi_bb174_14, phi_bb174_20);
    }
  }

  TNode<IntPtrT> phi_bb176_7;
  TNode<IntPtrT> phi_bb176_9;
  TNode<IntPtrT> phi_bb176_10;
  TNode<IntPtrT> phi_bb176_11;
  TNode<IntPtrT> phi_bb176_13;
  TNode<BoolT> phi_bb176_14;
  TNode<IntPtrT> phi_bb176_20;
  TNode<Object> tmp396;
  TNode<IntPtrT> tmp397;
  TNode<IntPtrT> tmp398;
  TNode<IntPtrT> tmp399;
  if (block176.is_used()) {
    ca_.Bind(&block176, &phi_bb176_7, &phi_bb176_9, &phi_bb176_10, &phi_bb176_11, &phi_bb176_13, &phi_bb176_14, &phi_bb176_20);
    std::tie(tmp396, tmp397) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb176_11}).Flatten();
    tmp398 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp399 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb176_11}, TNode<IntPtrT>{tmp398});
    ca_.Goto(&block175, phi_bb176_7, phi_bb176_9, phi_bb176_10, tmp399, phi_bb176_13, phi_bb176_14, phi_bb176_20, tmp396, tmp397);
  }

  TNode<IntPtrT> phi_bb177_7;
  TNode<IntPtrT> phi_bb177_9;
  TNode<IntPtrT> phi_bb177_10;
  TNode<IntPtrT> phi_bb177_11;
  TNode<IntPtrT> phi_bb177_13;
  TNode<BoolT> phi_bb177_14;
  TNode<IntPtrT> phi_bb177_20;
  TNode<IntPtrT> tmp400;
  TNode<BoolT> tmp401;
  if (block177.is_used()) {
    ca_.Bind(&block177, &phi_bb177_7, &phi_bb177_9, &phi_bb177_10, &phi_bb177_11, &phi_bb177_13, &phi_bb177_14, &phi_bb177_20);
    tmp400 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp401 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb177_13}, TNode<IntPtrT>{tmp400});
    ca_.Branch(tmp401, &block179, std::vector<compiler::Node*>{phi_bb177_7, phi_bb177_9, phi_bb177_10, phi_bb177_11, phi_bb177_13, phi_bb177_14, phi_bb177_20}, &block180, std::vector<compiler::Node*>{phi_bb177_7, phi_bb177_9, phi_bb177_10, phi_bb177_11, phi_bb177_13, phi_bb177_14, phi_bb177_20});
  }

  TNode<IntPtrT> phi_bb179_7;
  TNode<IntPtrT> phi_bb179_9;
  TNode<IntPtrT> phi_bb179_10;
  TNode<IntPtrT> phi_bb179_11;
  TNode<IntPtrT> phi_bb179_13;
  TNode<BoolT> phi_bb179_14;
  TNode<IntPtrT> phi_bb179_20;
  TNode<Object> tmp402;
  TNode<IntPtrT> tmp403;
  TNode<IntPtrT> tmp404;
  TNode<BoolT> tmp405;
  if (block179.is_used()) {
    ca_.Bind(&block179, &phi_bb179_7, &phi_bb179_9, &phi_bb179_10, &phi_bb179_11, &phi_bb179_13, &phi_bb179_14, &phi_bb179_20);
    std::tie(tmp402, tmp403) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb179_13}).Flatten();
    tmp404 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp405 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block175, phi_bb179_7, phi_bb179_9, phi_bb179_10, phi_bb179_11, tmp404, tmp405, phi_bb179_20, tmp402, tmp403);
  }

  TNode<IntPtrT> phi_bb180_7;
  TNode<IntPtrT> phi_bb180_9;
  TNode<IntPtrT> phi_bb180_10;
  TNode<IntPtrT> phi_bb180_11;
  TNode<IntPtrT> phi_bb180_13;
  TNode<BoolT> phi_bb180_14;
  TNode<IntPtrT> phi_bb180_20;
  TNode<Object> tmp406;
  TNode<IntPtrT> tmp407;
  TNode<IntPtrT> tmp408;
  TNode<IntPtrT> tmp409;
  TNode<IntPtrT> tmp410;
  TNode<IntPtrT> tmp411;
  TNode<BoolT> tmp412;
  if (block180.is_used()) {
    ca_.Bind(&block180, &phi_bb180_7, &phi_bb180_9, &phi_bb180_10, &phi_bb180_11, &phi_bb180_13, &phi_bb180_14, &phi_bb180_20);
    std::tie(tmp406, tmp407) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb180_11}).Flatten();
    tmp408 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp409 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb180_11}, TNode<IntPtrT>{tmp408});
    tmp410 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp411 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp409}, TNode<IntPtrT>{tmp410});
    tmp412 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block175, phi_bb180_7, phi_bb180_9, phi_bb180_10, tmp411, tmp409, tmp412, phi_bb180_20, tmp406, tmp407);
  }

  TNode<IntPtrT> phi_bb175_7;
  TNode<IntPtrT> phi_bb175_9;
  TNode<IntPtrT> phi_bb175_10;
  TNode<IntPtrT> phi_bb175_11;
  TNode<IntPtrT> phi_bb175_13;
  TNode<BoolT> phi_bb175_14;
  TNode<IntPtrT> phi_bb175_20;
  TNode<Object> phi_bb175_22;
  TNode<IntPtrT> phi_bb175_23;
  if (block175.is_used()) {
    ca_.Bind(&block175, &phi_bb175_7, &phi_bb175_9, &phi_bb175_10, &phi_bb175_11, &phi_bb175_13, &phi_bb175_14, &phi_bb175_20, &phi_bb175_22, &phi_bb175_23);
    ca_.Goto(&block172, phi_bb175_7, phi_bb175_9, phi_bb175_10, phi_bb175_11, phi_bb175_13, phi_bb175_14, phi_bb175_20, phi_bb175_22, phi_bb175_23);
  }

  TNode<IntPtrT> phi_bb172_7;
  TNode<IntPtrT> phi_bb172_9;
  TNode<IntPtrT> phi_bb172_10;
  TNode<IntPtrT> phi_bb172_11;
  TNode<IntPtrT> phi_bb172_13;
  TNode<BoolT> phi_bb172_14;
  TNode<IntPtrT> phi_bb172_20;
  TNode<Object> phi_bb172_22;
  TNode<IntPtrT> phi_bb172_23;
  if (block172.is_used()) {
    ca_.Bind(&block172, &phi_bb172_7, &phi_bb172_9, &phi_bb172_10, &phi_bb172_11, &phi_bb172_13, &phi_bb172_14, &phi_bb172_20, &phi_bb172_22, &phi_bb172_23);
    if ((wasm::kIsFpAlwaysDouble)) {
      ca_.Goto(&block181, phi_bb172_7, phi_bb172_9, phi_bb172_10, phi_bb172_11, phi_bb172_13, phi_bb172_14, phi_bb172_20, phi_bb172_22, phi_bb172_23);
    } else {
      ca_.Goto(&block182, phi_bb172_7, phi_bb172_9, phi_bb172_10, phi_bb172_11, phi_bb172_13, phi_bb172_14, phi_bb172_20, phi_bb172_22, phi_bb172_23);
    }
  }

  TNode<IntPtrT> phi_bb181_7;
  TNode<IntPtrT> phi_bb181_9;
  TNode<IntPtrT> phi_bb181_10;
  TNode<IntPtrT> phi_bb181_11;
  TNode<IntPtrT> phi_bb181_13;
  TNode<BoolT> phi_bb181_14;
  TNode<IntPtrT> phi_bb181_20;
  TNode<Object> phi_bb181_22;
  TNode<IntPtrT> phi_bb181_23;
  TNode<IntPtrT> tmp413;
  TNode<BoolT> tmp414;
  if (block181.is_used()) {
    ca_.Bind(&block181, &phi_bb181_7, &phi_bb181_9, &phi_bb181_10, &phi_bb181_11, &phi_bb181_13, &phi_bb181_14, &phi_bb181_20, &phi_bb181_22, &phi_bb181_23);
    tmp413 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp414 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp389}, TNode<IntPtrT>{tmp413});
    ca_.Branch(tmp414, &block184, std::vector<compiler::Node*>{phi_bb181_7, phi_bb181_9, phi_bb181_10, phi_bb181_11, phi_bb181_13, phi_bb181_14, phi_bb181_20, phi_bb181_22, phi_bb181_23}, &block185, std::vector<compiler::Node*>{phi_bb181_7, phi_bb181_9, phi_bb181_10, phi_bb181_11, phi_bb181_13, phi_bb181_14, phi_bb181_20, phi_bb181_22, phi_bb181_23});
  }

  TNode<IntPtrT> phi_bb184_7;
  TNode<IntPtrT> phi_bb184_9;
  TNode<IntPtrT> phi_bb184_10;
  TNode<IntPtrT> phi_bb184_11;
  TNode<IntPtrT> phi_bb184_13;
  TNode<BoolT> phi_bb184_14;
  TNode<IntPtrT> phi_bb184_20;
  TNode<Object> phi_bb184_22;
  TNode<IntPtrT> phi_bb184_23;
  TNode<Object> tmp415;
  TNode<IntPtrT> tmp416;
  TNode<Float64T> tmp417;
  TNode<Float32T> tmp418;
  if (block184.is_used()) {
    ca_.Bind(&block184, &phi_bb184_7, &phi_bb184_9, &phi_bb184_10, &phi_bb184_11, &phi_bb184_13, &phi_bb184_14, &phi_bb184_20, &phi_bb184_22, &phi_bb184_23);
    std::tie(tmp415, tmp416) = RefCast_float64_0(state_, TorqueStructReference_intptr_0{TNode<Object>{phi_bb184_22}, TNode<IntPtrT>{phi_bb184_23}, TorqueStructUnsafe_0{}}).Flatten();
    tmp417 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp415, tmp416});
    tmp418 = CodeStubAssembler(state_).TruncateFloat64ToFloat32(TNode<Float64T>{tmp417});
    ca_.Goto(&block187, phi_bb184_7, phi_bb184_9, phi_bb184_10, phi_bb184_11, phi_bb184_13, phi_bb184_14, phi_bb184_20, phi_bb184_22, phi_bb184_23, tmp418);
  }

  TNode<IntPtrT> phi_bb185_7;
  TNode<IntPtrT> phi_bb185_9;
  TNode<IntPtrT> phi_bb185_10;
  TNode<IntPtrT> phi_bb185_11;
  TNode<IntPtrT> phi_bb185_13;
  TNode<BoolT> phi_bb185_14;
  TNode<IntPtrT> phi_bb185_20;
  TNode<Object> phi_bb185_22;
  TNode<IntPtrT> phi_bb185_23;
  TNode<Object> tmp419;
  TNode<IntPtrT> tmp420;
  TNode<Float32T> tmp421;
  if (block185.is_used()) {
    ca_.Bind(&block185, &phi_bb185_7, &phi_bb185_9, &phi_bb185_10, &phi_bb185_11, &phi_bb185_13, &phi_bb185_14, &phi_bb185_20, &phi_bb185_22, &phi_bb185_23);
    std::tie(tmp419, tmp420) = RefCast_float32_0(state_, TorqueStructReference_intptr_0{TNode<Object>{phi_bb185_22}, TNode<IntPtrT>{phi_bb185_23}, TorqueStructUnsafe_0{}}).Flatten();
    tmp421 = CodeStubAssembler(state_).LoadReference<Float32T>(CodeStubAssembler::Reference{tmp419, tmp420});
    ca_.Goto(&block187, phi_bb185_7, phi_bb185_9, phi_bb185_10, phi_bb185_11, phi_bb185_13, phi_bb185_14, phi_bb185_20, phi_bb185_22, phi_bb185_23, tmp421);
  }

  TNode<IntPtrT> phi_bb187_7;
  TNode<IntPtrT> phi_bb187_9;
  TNode<IntPtrT> phi_bb187_10;
  TNode<IntPtrT> phi_bb187_11;
  TNode<IntPtrT> phi_bb187_13;
  TNode<BoolT> phi_bb187_14;
  TNode<IntPtrT> phi_bb187_20;
  TNode<Object> phi_bb187_22;
  TNode<IntPtrT> phi_bb187_23;
  TNode<Float32T> phi_bb187_24;
  if (block187.is_used()) {
    ca_.Bind(&block187, &phi_bb187_7, &phi_bb187_9, &phi_bb187_10, &phi_bb187_11, &phi_bb187_13, &phi_bb187_14, &phi_bb187_20, &phi_bb187_22, &phi_bb187_23, &phi_bb187_24);
    ca_.Goto(&block183, phi_bb187_7, phi_bb187_9, phi_bb187_10, phi_bb187_11, phi_bb187_13, phi_bb187_14, phi_bb187_20, phi_bb187_22, phi_bb187_23, phi_bb187_24);
  }

  TNode<IntPtrT> phi_bb182_7;
  TNode<IntPtrT> phi_bb182_9;
  TNode<IntPtrT> phi_bb182_10;
  TNode<IntPtrT> phi_bb182_11;
  TNode<IntPtrT> phi_bb182_13;
  TNode<BoolT> phi_bb182_14;
  TNode<IntPtrT> phi_bb182_20;
  TNode<Object> phi_bb182_22;
  TNode<IntPtrT> phi_bb182_23;
  if (block182.is_used()) {
    ca_.Bind(&block182, &phi_bb182_7, &phi_bb182_9, &phi_bb182_10, &phi_bb182_11, &phi_bb182_13, &phi_bb182_14, &phi_bb182_20, &phi_bb182_22, &phi_bb182_23);
    if ((wasm::kIsBigEndianOnSim)) {
      ca_.Goto(&block188, phi_bb182_7, phi_bb182_9, phi_bb182_10, phi_bb182_11, phi_bb182_13, phi_bb182_14, phi_bb182_20, phi_bb182_22, phi_bb182_23);
    } else {
      ca_.Goto(&block189, phi_bb182_7, phi_bb182_9, phi_bb182_10, phi_bb182_11, phi_bb182_13, phi_bb182_14, phi_bb182_20, phi_bb182_22, phi_bb182_23);
    }
  }

  TNode<IntPtrT> phi_bb188_7;
  TNode<IntPtrT> phi_bb188_9;
  TNode<IntPtrT> phi_bb188_10;
  TNode<IntPtrT> phi_bb188_11;
  TNode<IntPtrT> phi_bb188_13;
  TNode<BoolT> phi_bb188_14;
  TNode<IntPtrT> phi_bb188_20;
  TNode<Object> phi_bb188_22;
  TNode<IntPtrT> phi_bb188_23;
  TNode<IntPtrT> tmp422;
  TNode<BoolT> tmp423;
  if (block188.is_used()) {
    ca_.Bind(&block188, &phi_bb188_7, &phi_bb188_9, &phi_bb188_10, &phi_bb188_11, &phi_bb188_13, &phi_bb188_14, &phi_bb188_20, &phi_bb188_22, &phi_bb188_23);
    tmp422 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp423 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp389}, TNode<IntPtrT>{tmp422});
    ca_.Branch(tmp423, &block191, std::vector<compiler::Node*>{phi_bb188_7, phi_bb188_9, phi_bb188_10, phi_bb188_11, phi_bb188_13, phi_bb188_14, phi_bb188_20, phi_bb188_22, phi_bb188_23}, &block192, std::vector<compiler::Node*>{phi_bb188_7, phi_bb188_9, phi_bb188_10, phi_bb188_11, phi_bb188_13, phi_bb188_14, phi_bb188_20, phi_bb188_22, phi_bb188_23});
  }

  TNode<IntPtrT> phi_bb191_7;
  TNode<IntPtrT> phi_bb191_9;
  TNode<IntPtrT> phi_bb191_10;
  TNode<IntPtrT> phi_bb191_11;
  TNode<IntPtrT> phi_bb191_13;
  TNode<BoolT> phi_bb191_14;
  TNode<IntPtrT> phi_bb191_20;
  TNode<Object> phi_bb191_22;
  TNode<IntPtrT> phi_bb191_23;
  TNode<Object> tmp424;
  TNode<IntPtrT> tmp425;
  TNode<Int64T> tmp426;
  TNode<Int64T> tmp427;
  TNode<Int64T> tmp428;
  TNode<Int32T> tmp429;
  TNode<Float32T> tmp430;
  if (block191.is_used()) {
    ca_.Bind(&block191, &phi_bb191_7, &phi_bb191_9, &phi_bb191_10, &phi_bb191_11, &phi_bb191_13, &phi_bb191_14, &phi_bb191_20, &phi_bb191_22, &phi_bb191_23);
    std::tie(tmp424, tmp425) = RefCast_int64_0(state_, TorqueStructReference_intptr_0{TNode<Object>{phi_bb191_22}, TNode<IntPtrT>{phi_bb191_23}, TorqueStructUnsafe_0{}}).Flatten();
    tmp426 = CodeStubAssembler(state_).LoadReference<Int64T>(CodeStubAssembler::Reference{tmp424, tmp425});
    tmp427 = FromConstexpr_int64_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x20ull));
    tmp428 = CodeStubAssembler(state_).Word64Sar(TNode<Int64T>{tmp426}, TNode<Int64T>{tmp427});
    tmp429 = CodeStubAssembler(state_).TruncateInt64ToInt32(TNode<Int64T>{tmp428});
    tmp430 = CodeStubAssembler(state_).BitcastInt32ToFloat32(TNode<Int32T>{tmp429});
    ca_.Goto(&block194, phi_bb191_7, phi_bb191_9, phi_bb191_10, phi_bb191_11, phi_bb191_13, phi_bb191_14, phi_bb191_20, phi_bb191_22, phi_bb191_23, tmp430);
  }

  TNode<IntPtrT> phi_bb192_7;
  TNode<IntPtrT> phi_bb192_9;
  TNode<IntPtrT> phi_bb192_10;
  TNode<IntPtrT> phi_bb192_11;
  TNode<IntPtrT> phi_bb192_13;
  TNode<BoolT> phi_bb192_14;
  TNode<IntPtrT> phi_bb192_20;
  TNode<Object> phi_bb192_22;
  TNode<IntPtrT> phi_bb192_23;
  TNode<Object> tmp431;
  TNode<IntPtrT> tmp432;
  TNode<Float32T> tmp433;
  if (block192.is_used()) {
    ca_.Bind(&block192, &phi_bb192_7, &phi_bb192_9, &phi_bb192_10, &phi_bb192_11, &phi_bb192_13, &phi_bb192_14, &phi_bb192_20, &phi_bb192_22, &phi_bb192_23);
    std::tie(tmp431, tmp432) = RefCast_float32_0(state_, TorqueStructReference_intptr_0{TNode<Object>{phi_bb192_22}, TNode<IntPtrT>{phi_bb192_23}, TorqueStructUnsafe_0{}}).Flatten();
    tmp433 = CodeStubAssembler(state_).LoadReference<Float32T>(CodeStubAssembler::Reference{tmp431, tmp432});
    ca_.Goto(&block194, phi_bb192_7, phi_bb192_9, phi_bb192_10, phi_bb192_11, phi_bb192_13, phi_bb192_14, phi_bb192_20, phi_bb192_22, phi_bb192_23, tmp433);
  }

  TNode<IntPtrT> phi_bb194_7;
  TNode<IntPtrT> phi_bb194_9;
  TNode<IntPtrT> phi_bb194_10;
  TNode<IntPtrT> phi_bb194_11;
  TNode<IntPtrT> phi_bb194_13;
  TNode<BoolT> phi_bb194_14;
  TNode<IntPtrT> phi_bb194_20;
  TNode<Object> phi_bb194_22;
  TNode<IntPtrT> phi_bb194_23;
  TNode<Float32T> phi_bb194_24;
  if (block194.is_used()) {
    ca_.Bind(&block194, &phi_bb194_7, &phi_bb194_9, &phi_bb194_10, &phi_bb194_11, &phi_bb194_13, &phi_bb194_14, &phi_bb194_20, &phi_bb194_22, &phi_bb194_23, &phi_bb194_24);
    ca_.Goto(&block190, phi_bb194_7, phi_bb194_9, phi_bb194_10, phi_bb194_11, phi_bb194_13, phi_bb194_14, phi_bb194_20, phi_bb194_22, phi_bb194_23, phi_bb194_24);
  }

  TNode<IntPtrT> phi_bb189_7;
  TNode<IntPtrT> phi_bb189_9;
  TNode<IntPtrT> phi_bb189_10;
  TNode<IntPtrT> phi_bb189_11;
  TNode<IntPtrT> phi_bb189_13;
  TNode<BoolT> phi_bb189_14;
  TNode<IntPtrT> phi_bb189_20;
  TNode<Object> phi_bb189_22;
  TNode<IntPtrT> phi_bb189_23;
  TNode<Object> tmp434;
  TNode<IntPtrT> tmp435;
  TNode<Float32T> tmp436;
  if (block189.is_used()) {
    ca_.Bind(&block189, &phi_bb189_7, &phi_bb189_9, &phi_bb189_10, &phi_bb189_11, &phi_bb189_13, &phi_bb189_14, &phi_bb189_20, &phi_bb189_22, &phi_bb189_23);
    std::tie(tmp434, tmp435) = RefCast_float32_0(state_, TorqueStructReference_intptr_0{TNode<Object>{phi_bb189_22}, TNode<IntPtrT>{phi_bb189_23}, TorqueStructUnsafe_0{}}).Flatten();
    tmp436 = CodeStubAssembler(state_).LoadReference<Float32T>(CodeStubAssembler::Reference{tmp434, tmp435});
    ca_.Goto(&block190, phi_bb189_7, phi_bb189_9, phi_bb189_10, phi_bb189_11, phi_bb189_13, phi_bb189_14, phi_bb189_20, phi_bb189_22, phi_bb189_23, tmp436);
  }

  TNode<IntPtrT> phi_bb190_7;
  TNode<IntPtrT> phi_bb190_9;
  TNode<IntPtrT> phi_bb190_10;
  TNode<IntPtrT> phi_bb190_11;
  TNode<IntPtrT> phi_bb190_13;
  TNode<BoolT> phi_bb190_14;
  TNode<IntPtrT> phi_bb190_20;
  TNode<Object> phi_bb190_22;
  TNode<IntPtrT> phi_bb190_23;
  TNode<Float32T> phi_bb190_24;
  if (block190.is_used()) {
    ca_.Bind(&block190, &phi_bb190_7, &phi_bb190_9, &phi_bb190_10, &phi_bb190_11, &phi_bb190_13, &phi_bb190_14, &phi_bb190_20, &phi_bb190_22, &phi_bb190_23, &phi_bb190_24);
    ca_.Goto(&block183, phi_bb190_7, phi_bb190_9, phi_bb190_10, phi_bb190_11, phi_bb190_13, phi_bb190_14, phi_bb190_20, phi_bb190_22, phi_bb190_23, phi_bb190_24);
  }

  TNode<IntPtrT> phi_bb183_7;
  TNode<IntPtrT> phi_bb183_9;
  TNode<IntPtrT> phi_bb183_10;
  TNode<IntPtrT> phi_bb183_11;
  TNode<IntPtrT> phi_bb183_13;
  TNode<BoolT> phi_bb183_14;
  TNode<IntPtrT> phi_bb183_20;
  TNode<Object> phi_bb183_22;
  TNode<IntPtrT> phi_bb183_23;
  TNode<Float32T> phi_bb183_24;
  TNode<Object> tmp437;
  TNode<IntPtrT> tmp438;
  TNode<IntPtrT> tmp439;
  TNode<UintPtrT> tmp440;
  TNode<UintPtrT> tmp441;
  TNode<BoolT> tmp442;
  if (block183.is_used()) {
    ca_.Bind(&block183, &phi_bb183_7, &phi_bb183_9, &phi_bb183_10, &phi_bb183_11, &phi_bb183_13, &phi_bb183_14, &phi_bb183_20, &phi_bb183_22, &phi_bb183_23, &phi_bb183_24);
    std::tie(tmp437, tmp438, tmp439) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp85}).Flatten();
    tmp440 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb183_20});
    tmp441 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp439});
    tmp442 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp440}, TNode<UintPtrT>{tmp441});
    ca_.Branch(tmp442, &block199, std::vector<compiler::Node*>{phi_bb183_7, phi_bb183_9, phi_bb183_10, phi_bb183_11, phi_bb183_13, phi_bb183_14, phi_bb183_20, phi_bb183_22, phi_bb183_23, phi_bb183_20, phi_bb183_20, phi_bb183_20, phi_bb183_20}, &block200, std::vector<compiler::Node*>{phi_bb183_7, phi_bb183_9, phi_bb183_10, phi_bb183_11, phi_bb183_13, phi_bb183_14, phi_bb183_20, phi_bb183_22, phi_bb183_23, phi_bb183_20, phi_bb183_20, phi_bb183_20, phi_bb183_20});
  }

  TNode<IntPtrT> phi_bb199_7;
  TNode<IntPtrT> phi_bb199_9;
  TNode<IntPtrT> phi_bb199_10;
  TNode<IntPtrT> phi_bb199_11;
  TNode<IntPtrT> phi_bb199_13;
  TNode<BoolT> phi_bb199_14;
  TNode<IntPtrT> phi_bb199_20;
  TNode<Object> phi_bb199_22;
  TNode<IntPtrT> phi_bb199_23;
  TNode<IntPtrT> phi_bb199_29;
  TNode<IntPtrT> phi_bb199_30;
  TNode<IntPtrT> phi_bb199_34;
  TNode<IntPtrT> phi_bb199_35;
  TNode<IntPtrT> tmp443;
  TNode<IntPtrT> tmp444;
  TNode<Object> tmp445;
  TNode<IntPtrT> tmp446;
  TNode<Number> tmp447;
  if (block199.is_used()) {
    ca_.Bind(&block199, &phi_bb199_7, &phi_bb199_9, &phi_bb199_10, &phi_bb199_11, &phi_bb199_13, &phi_bb199_14, &phi_bb199_20, &phi_bb199_22, &phi_bb199_23, &phi_bb199_29, &phi_bb199_30, &phi_bb199_34, &phi_bb199_35);
    tmp443 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb199_35});
    tmp444 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp438}, TNode<IntPtrT>{tmp443});
    std::tie(tmp445, tmp446) = NewReference_Object_0(state_, TNode<Object>{tmp437}, TNode<IntPtrT>{tmp444}).Flatten();
    tmp447 = Convert_Number_float32_0(state_, TNode<Float32T>{phi_bb183_24});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp445, tmp446}, tmp447);
    ca_.Goto(&block171, phi_bb199_7, tmp389, phi_bb199_9, phi_bb199_10, phi_bb199_11, phi_bb199_13, phi_bb199_14, phi_bb199_20);
  }

  TNode<IntPtrT> phi_bb200_7;
  TNode<IntPtrT> phi_bb200_9;
  TNode<IntPtrT> phi_bb200_10;
  TNode<IntPtrT> phi_bb200_11;
  TNode<IntPtrT> phi_bb200_13;
  TNode<BoolT> phi_bb200_14;
  TNode<IntPtrT> phi_bb200_20;
  TNode<Object> phi_bb200_22;
  TNode<IntPtrT> phi_bb200_23;
  TNode<IntPtrT> phi_bb200_29;
  TNode<IntPtrT> phi_bb200_30;
  TNode<IntPtrT> phi_bb200_34;
  TNode<IntPtrT> phi_bb200_35;
  if (block200.is_used()) {
    ca_.Bind(&block200, &phi_bb200_7, &phi_bb200_9, &phi_bb200_10, &phi_bb200_11, &phi_bb200_13, &phi_bb200_14, &phi_bb200_20, &phi_bb200_22, &phi_bb200_23, &phi_bb200_29, &phi_bb200_30, &phi_bb200_34, &phi_bb200_35);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb170_7;
  TNode<IntPtrT> phi_bb170_8;
  TNode<IntPtrT> phi_bb170_9;
  TNode<IntPtrT> phi_bb170_10;
  TNode<IntPtrT> phi_bb170_11;
  TNode<IntPtrT> phi_bb170_13;
  TNode<BoolT> phi_bb170_14;
  TNode<IntPtrT> phi_bb170_20;
  TNode<Int32T> tmp448;
  TNode<BoolT> tmp449;
  if (block170.is_used()) {
    ca_.Bind(&block170, &phi_bb170_7, &phi_bb170_8, &phi_bb170_9, &phi_bb170_10, &phi_bb170_11, &phi_bb170_13, &phi_bb170_14, &phi_bb170_20);
    tmp448 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmI64.raw_bit_field());
    tmp449 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp340}, TNode<Int32T>{tmp448});
    ca_.Branch(tmp449, &block203, std::vector<compiler::Node*>{phi_bb170_7, phi_bb170_8, phi_bb170_9, phi_bb170_10, phi_bb170_11, phi_bb170_13, phi_bb170_14, phi_bb170_20}, &block204, std::vector<compiler::Node*>{phi_bb170_7, phi_bb170_8, phi_bb170_9, phi_bb170_10, phi_bb170_11, phi_bb170_13, phi_bb170_14, phi_bb170_20});
  }

  TNode<IntPtrT> phi_bb203_7;
  TNode<IntPtrT> phi_bb203_8;
  TNode<IntPtrT> phi_bb203_9;
  TNode<IntPtrT> phi_bb203_10;
  TNode<IntPtrT> phi_bb203_11;
  TNode<IntPtrT> phi_bb203_13;
  TNode<BoolT> phi_bb203_14;
  TNode<IntPtrT> phi_bb203_20;
  if (block203.is_used()) {
    ca_.Bind(&block203, &phi_bb203_7, &phi_bb203_8, &phi_bb203_9, &phi_bb203_10, &phi_bb203_11, &phi_bb203_13, &phi_bb203_14, &phi_bb203_20);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block206, phi_bb203_7, phi_bb203_8, phi_bb203_9, phi_bb203_10, phi_bb203_11, phi_bb203_13, phi_bb203_14, phi_bb203_20);
    } else {
      ca_.Goto(&block207, phi_bb203_7, phi_bb203_8, phi_bb203_9, phi_bb203_10, phi_bb203_11, phi_bb203_13, phi_bb203_14, phi_bb203_20);
    }
  }

  TNode<IntPtrT> phi_bb206_7;
  TNode<IntPtrT> phi_bb206_8;
  TNode<IntPtrT> phi_bb206_9;
  TNode<IntPtrT> phi_bb206_10;
  TNode<IntPtrT> phi_bb206_11;
  TNode<IntPtrT> phi_bb206_13;
  TNode<BoolT> phi_bb206_14;
  TNode<IntPtrT> phi_bb206_20;
  TNode<IntPtrT> tmp450;
  TNode<IntPtrT> tmp451;
  TNode<IntPtrT> tmp452;
  TNode<BoolT> tmp453;
  if (block206.is_used()) {
    ca_.Bind(&block206, &phi_bb206_7, &phi_bb206_8, &phi_bb206_9, &phi_bb206_10, &phi_bb206_11, &phi_bb206_13, &phi_bb206_14, &phi_bb206_20);
    tmp450 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp451 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb206_7}, TNode<IntPtrT>{tmp450});
    tmp452 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp453 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb206_7}, TNode<IntPtrT>{tmp452});
    ca_.Branch(tmp453, &block210, std::vector<compiler::Node*>{phi_bb206_8, phi_bb206_9, phi_bb206_10, phi_bb206_11, phi_bb206_13, phi_bb206_14, phi_bb206_20}, &block211, std::vector<compiler::Node*>{phi_bb206_8, phi_bb206_9, phi_bb206_10, phi_bb206_11, phi_bb206_13, phi_bb206_14, phi_bb206_20});
  }

  TNode<IntPtrT> phi_bb210_8;
  TNode<IntPtrT> phi_bb210_9;
  TNode<IntPtrT> phi_bb210_10;
  TNode<IntPtrT> phi_bb210_11;
  TNode<IntPtrT> phi_bb210_13;
  TNode<BoolT> phi_bb210_14;
  TNode<IntPtrT> phi_bb210_20;
  TNode<Object> tmp454;
  TNode<IntPtrT> tmp455;
  TNode<IntPtrT> tmp456;
  TNode<IntPtrT> tmp457;
  if (block210.is_used()) {
    ca_.Bind(&block210, &phi_bb210_8, &phi_bb210_9, &phi_bb210_10, &phi_bb210_11, &phi_bb210_13, &phi_bb210_14, &phi_bb210_20);
    std::tie(tmp454, tmp455) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb210_9}).Flatten();
    tmp456 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp457 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb210_9}, TNode<IntPtrT>{tmp456});
    ca_.Goto(&block209, phi_bb210_8, tmp457, phi_bb210_10, phi_bb210_11, phi_bb210_13, phi_bb210_14, phi_bb210_20, tmp454, tmp455);
  }

  TNode<IntPtrT> phi_bb211_8;
  TNode<IntPtrT> phi_bb211_9;
  TNode<IntPtrT> phi_bb211_10;
  TNode<IntPtrT> phi_bb211_11;
  TNode<IntPtrT> phi_bb211_13;
  TNode<BoolT> phi_bb211_14;
  TNode<IntPtrT> phi_bb211_20;
  if (block211.is_used()) {
    ca_.Bind(&block211, &phi_bb211_8, &phi_bb211_9, &phi_bb211_10, &phi_bb211_11, &phi_bb211_13, &phi_bb211_14, &phi_bb211_20);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block213, phi_bb211_8, phi_bb211_9, phi_bb211_10, phi_bb211_11, phi_bb211_13, phi_bb211_14, phi_bb211_20);
    } else {
      ca_.Goto(&block214, phi_bb211_8, phi_bb211_9, phi_bb211_10, phi_bb211_11, phi_bb211_13, phi_bb211_14, phi_bb211_20);
    }
  }

  TNode<IntPtrT> phi_bb213_8;
  TNode<IntPtrT> phi_bb213_9;
  TNode<IntPtrT> phi_bb213_10;
  TNode<IntPtrT> phi_bb213_11;
  TNode<IntPtrT> phi_bb213_13;
  TNode<BoolT> phi_bb213_14;
  TNode<IntPtrT> phi_bb213_20;
  TNode<Object> tmp458;
  TNode<IntPtrT> tmp459;
  TNode<IntPtrT> tmp460;
  TNode<IntPtrT> tmp461;
  if (block213.is_used()) {
    ca_.Bind(&block213, &phi_bb213_8, &phi_bb213_9, &phi_bb213_10, &phi_bb213_11, &phi_bb213_13, &phi_bb213_14, &phi_bb213_20);
    std::tie(tmp458, tmp459) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb213_11}).Flatten();
    tmp460 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp461 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb213_11}, TNode<IntPtrT>{tmp460});
    ca_.Goto(&block212, phi_bb213_8, phi_bb213_9, phi_bb213_10, tmp461, phi_bb213_13, phi_bb213_14, phi_bb213_20, tmp458, tmp459);
  }

  TNode<IntPtrT> phi_bb214_8;
  TNode<IntPtrT> phi_bb214_9;
  TNode<IntPtrT> phi_bb214_10;
  TNode<IntPtrT> phi_bb214_11;
  TNode<IntPtrT> phi_bb214_13;
  TNode<BoolT> phi_bb214_14;
  TNode<IntPtrT> phi_bb214_20;
  TNode<IntPtrT> tmp462;
  TNode<BoolT> tmp463;
  if (block214.is_used()) {
    ca_.Bind(&block214, &phi_bb214_8, &phi_bb214_9, &phi_bb214_10, &phi_bb214_11, &phi_bb214_13, &phi_bb214_14, &phi_bb214_20);
    tmp462 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp463 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb214_13}, TNode<IntPtrT>{tmp462});
    ca_.Branch(tmp463, &block216, std::vector<compiler::Node*>{phi_bb214_8, phi_bb214_9, phi_bb214_10, phi_bb214_11, phi_bb214_13, phi_bb214_14, phi_bb214_20}, &block217, std::vector<compiler::Node*>{phi_bb214_8, phi_bb214_9, phi_bb214_10, phi_bb214_11, phi_bb214_13, phi_bb214_14, phi_bb214_20});
  }

  TNode<IntPtrT> phi_bb216_8;
  TNode<IntPtrT> phi_bb216_9;
  TNode<IntPtrT> phi_bb216_10;
  TNode<IntPtrT> phi_bb216_11;
  TNode<IntPtrT> phi_bb216_13;
  TNode<BoolT> phi_bb216_14;
  TNode<IntPtrT> phi_bb216_20;
  TNode<Object> tmp464;
  TNode<IntPtrT> tmp465;
  TNode<IntPtrT> tmp466;
  TNode<BoolT> tmp467;
  if (block216.is_used()) {
    ca_.Bind(&block216, &phi_bb216_8, &phi_bb216_9, &phi_bb216_10, &phi_bb216_11, &phi_bb216_13, &phi_bb216_14, &phi_bb216_20);
    std::tie(tmp464, tmp465) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb216_13}).Flatten();
    tmp466 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp467 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block212, phi_bb216_8, phi_bb216_9, phi_bb216_10, phi_bb216_11, tmp466, tmp467, phi_bb216_20, tmp464, tmp465);
  }

  TNode<IntPtrT> phi_bb217_8;
  TNode<IntPtrT> phi_bb217_9;
  TNode<IntPtrT> phi_bb217_10;
  TNode<IntPtrT> phi_bb217_11;
  TNode<IntPtrT> phi_bb217_13;
  TNode<BoolT> phi_bb217_14;
  TNode<IntPtrT> phi_bb217_20;
  TNode<Object> tmp468;
  TNode<IntPtrT> tmp469;
  TNode<IntPtrT> tmp470;
  TNode<IntPtrT> tmp471;
  TNode<IntPtrT> tmp472;
  TNode<IntPtrT> tmp473;
  TNode<BoolT> tmp474;
  if (block217.is_used()) {
    ca_.Bind(&block217, &phi_bb217_8, &phi_bb217_9, &phi_bb217_10, &phi_bb217_11, &phi_bb217_13, &phi_bb217_14, &phi_bb217_20);
    std::tie(tmp468, tmp469) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb217_11}).Flatten();
    tmp470 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp471 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb217_11}, TNode<IntPtrT>{tmp470});
    tmp472 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp473 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp471}, TNode<IntPtrT>{tmp472});
    tmp474 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block212, phi_bb217_8, phi_bb217_9, phi_bb217_10, tmp473, tmp471, tmp474, phi_bb217_20, tmp468, tmp469);
  }

  TNode<IntPtrT> phi_bb212_8;
  TNode<IntPtrT> phi_bb212_9;
  TNode<IntPtrT> phi_bb212_10;
  TNode<IntPtrT> phi_bb212_11;
  TNode<IntPtrT> phi_bb212_13;
  TNode<BoolT> phi_bb212_14;
  TNode<IntPtrT> phi_bb212_20;
  TNode<Object> phi_bb212_22;
  TNode<IntPtrT> phi_bb212_23;
  if (block212.is_used()) {
    ca_.Bind(&block212, &phi_bb212_8, &phi_bb212_9, &phi_bb212_10, &phi_bb212_11, &phi_bb212_13, &phi_bb212_14, &phi_bb212_20, &phi_bb212_22, &phi_bb212_23);
    ca_.Goto(&block209, phi_bb212_8, phi_bb212_9, phi_bb212_10, phi_bb212_11, phi_bb212_13, phi_bb212_14, phi_bb212_20, phi_bb212_22, phi_bb212_23);
  }

  TNode<IntPtrT> phi_bb209_8;
  TNode<IntPtrT> phi_bb209_9;
  TNode<IntPtrT> phi_bb209_10;
  TNode<IntPtrT> phi_bb209_11;
  TNode<IntPtrT> phi_bb209_13;
  TNode<BoolT> phi_bb209_14;
  TNode<IntPtrT> phi_bb209_20;
  TNode<Object> phi_bb209_22;
  TNode<IntPtrT> phi_bb209_23;
  TNode<IntPtrT> tmp475;
  TNode<Object> tmp476;
  TNode<IntPtrT> tmp477;
  TNode<IntPtrT> tmp478;
  TNode<UintPtrT> tmp479;
  TNode<UintPtrT> tmp480;
  TNode<BoolT> tmp481;
  if (block209.is_used()) {
    ca_.Bind(&block209, &phi_bb209_8, &phi_bb209_9, &phi_bb209_10, &phi_bb209_11, &phi_bb209_13, &phi_bb209_14, &phi_bb209_20, &phi_bb209_22, &phi_bb209_23);
    tmp475 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb209_22, phi_bb209_23});
    std::tie(tmp476, tmp477, tmp478) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp85}).Flatten();
    tmp479 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb209_20});
    tmp480 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp478});
    tmp481 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp479}, TNode<UintPtrT>{tmp480});
    ca_.Branch(tmp481, &block222, std::vector<compiler::Node*>{phi_bb209_8, phi_bb209_9, phi_bb209_10, phi_bb209_11, phi_bb209_13, phi_bb209_14, phi_bb209_20, phi_bb209_22, phi_bb209_23, phi_bb209_20, phi_bb209_20, phi_bb209_20, phi_bb209_20}, &block223, std::vector<compiler::Node*>{phi_bb209_8, phi_bb209_9, phi_bb209_10, phi_bb209_11, phi_bb209_13, phi_bb209_14, phi_bb209_20, phi_bb209_22, phi_bb209_23, phi_bb209_20, phi_bb209_20, phi_bb209_20, phi_bb209_20});
  }

  TNode<IntPtrT> phi_bb222_8;
  TNode<IntPtrT> phi_bb222_9;
  TNode<IntPtrT> phi_bb222_10;
  TNode<IntPtrT> phi_bb222_11;
  TNode<IntPtrT> phi_bb222_13;
  TNode<BoolT> phi_bb222_14;
  TNode<IntPtrT> phi_bb222_20;
  TNode<Object> phi_bb222_22;
  TNode<IntPtrT> phi_bb222_23;
  TNode<IntPtrT> phi_bb222_29;
  TNode<IntPtrT> phi_bb222_30;
  TNode<IntPtrT> phi_bb222_34;
  TNode<IntPtrT> phi_bb222_35;
  TNode<IntPtrT> tmp482;
  TNode<IntPtrT> tmp483;
  TNode<Object> tmp484;
  TNode<IntPtrT> tmp485;
  TNode<BigInt> tmp486;
  if (block222.is_used()) {
    ca_.Bind(&block222, &phi_bb222_8, &phi_bb222_9, &phi_bb222_10, &phi_bb222_11, &phi_bb222_13, &phi_bb222_14, &phi_bb222_20, &phi_bb222_22, &phi_bb222_23, &phi_bb222_29, &phi_bb222_30, &phi_bb222_34, &phi_bb222_35);
    tmp482 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb222_35});
    tmp483 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp477}, TNode<IntPtrT>{tmp482});
    std::tie(tmp484, tmp485) = NewReference_Object_0(state_, TNode<Object>{tmp476}, TNode<IntPtrT>{tmp483}).Flatten();
    tmp486 = ca_.CallBuiltin<BigInt>(Builtin::kI64ToBigInt, TNode<Object>(), tmp475);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp484, tmp485}, tmp486);
    ca_.Goto(&block208, tmp451, phi_bb222_8, phi_bb222_9, phi_bb222_10, phi_bb222_11, phi_bb222_13, phi_bb222_14, phi_bb222_20);
  }

  TNode<IntPtrT> phi_bb223_8;
  TNode<IntPtrT> phi_bb223_9;
  TNode<IntPtrT> phi_bb223_10;
  TNode<IntPtrT> phi_bb223_11;
  TNode<IntPtrT> phi_bb223_13;
  TNode<BoolT> phi_bb223_14;
  TNode<IntPtrT> phi_bb223_20;
  TNode<Object> phi_bb223_22;
  TNode<IntPtrT> phi_bb223_23;
  TNode<IntPtrT> phi_bb223_29;
  TNode<IntPtrT> phi_bb223_30;
  TNode<IntPtrT> phi_bb223_34;
  TNode<IntPtrT> phi_bb223_35;
  if (block223.is_used()) {
    ca_.Bind(&block223, &phi_bb223_8, &phi_bb223_9, &phi_bb223_10, &phi_bb223_11, &phi_bb223_13, &phi_bb223_14, &phi_bb223_20, &phi_bb223_22, &phi_bb223_23, &phi_bb223_29, &phi_bb223_30, &phi_bb223_34, &phi_bb223_35);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb207_7;
  TNode<IntPtrT> phi_bb207_8;
  TNode<IntPtrT> phi_bb207_9;
  TNode<IntPtrT> phi_bb207_10;
  TNode<IntPtrT> phi_bb207_11;
  TNode<IntPtrT> phi_bb207_13;
  TNode<BoolT> phi_bb207_14;
  TNode<IntPtrT> phi_bb207_20;
  TNode<IntPtrT> tmp487;
  TNode<IntPtrT> tmp488;
  TNode<IntPtrT> tmp489;
  TNode<BoolT> tmp490;
  if (block207.is_used()) {
    ca_.Bind(&block207, &phi_bb207_7, &phi_bb207_8, &phi_bb207_9, &phi_bb207_10, &phi_bb207_11, &phi_bb207_13, &phi_bb207_14, &phi_bb207_20);
    tmp487 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp488 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb207_7}, TNode<IntPtrT>{tmp487});
    tmp489 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp490 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb207_7}, TNode<IntPtrT>{tmp489});
    ca_.Branch(tmp490, &block227, std::vector<compiler::Node*>{phi_bb207_8, phi_bb207_9, phi_bb207_10, phi_bb207_11, phi_bb207_13, phi_bb207_14, phi_bb207_20}, &block228, std::vector<compiler::Node*>{phi_bb207_8, phi_bb207_9, phi_bb207_10, phi_bb207_11, phi_bb207_13, phi_bb207_14, phi_bb207_20});
  }

  TNode<IntPtrT> phi_bb227_8;
  TNode<IntPtrT> phi_bb227_9;
  TNode<IntPtrT> phi_bb227_10;
  TNode<IntPtrT> phi_bb227_11;
  TNode<IntPtrT> phi_bb227_13;
  TNode<BoolT> phi_bb227_14;
  TNode<IntPtrT> phi_bb227_20;
  TNode<Object> tmp491;
  TNode<IntPtrT> tmp492;
  TNode<IntPtrT> tmp493;
  TNode<IntPtrT> tmp494;
  if (block227.is_used()) {
    ca_.Bind(&block227, &phi_bb227_8, &phi_bb227_9, &phi_bb227_10, &phi_bb227_11, &phi_bb227_13, &phi_bb227_14, &phi_bb227_20);
    std::tie(tmp491, tmp492) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb227_9}).Flatten();
    tmp493 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp494 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb227_9}, TNode<IntPtrT>{tmp493});
    ca_.Goto(&block226, phi_bb227_8, tmp494, phi_bb227_10, phi_bb227_11, phi_bb227_13, phi_bb227_14, phi_bb227_20, tmp491, tmp492);
  }

  TNode<IntPtrT> phi_bb228_8;
  TNode<IntPtrT> phi_bb228_9;
  TNode<IntPtrT> phi_bb228_10;
  TNode<IntPtrT> phi_bb228_11;
  TNode<IntPtrT> phi_bb228_13;
  TNode<BoolT> phi_bb228_14;
  TNode<IntPtrT> phi_bb228_20;
  if (block228.is_used()) {
    ca_.Bind(&block228, &phi_bb228_8, &phi_bb228_9, &phi_bb228_10, &phi_bb228_11, &phi_bb228_13, &phi_bb228_14, &phi_bb228_20);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block230, phi_bb228_8, phi_bb228_9, phi_bb228_10, phi_bb228_11, phi_bb228_13, phi_bb228_14, phi_bb228_20);
    } else {
      ca_.Goto(&block231, phi_bb228_8, phi_bb228_9, phi_bb228_10, phi_bb228_11, phi_bb228_13, phi_bb228_14, phi_bb228_20);
    }
  }

  TNode<IntPtrT> phi_bb230_8;
  TNode<IntPtrT> phi_bb230_9;
  TNode<IntPtrT> phi_bb230_10;
  TNode<IntPtrT> phi_bb230_11;
  TNode<IntPtrT> phi_bb230_13;
  TNode<BoolT> phi_bb230_14;
  TNode<IntPtrT> phi_bb230_20;
  TNode<Object> tmp495;
  TNode<IntPtrT> tmp496;
  TNode<IntPtrT> tmp497;
  TNode<IntPtrT> tmp498;
  if (block230.is_used()) {
    ca_.Bind(&block230, &phi_bb230_8, &phi_bb230_9, &phi_bb230_10, &phi_bb230_11, &phi_bb230_13, &phi_bb230_14, &phi_bb230_20);
    std::tie(tmp495, tmp496) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb230_11}).Flatten();
    tmp497 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp498 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb230_11}, TNode<IntPtrT>{tmp497});
    ca_.Goto(&block229, phi_bb230_8, phi_bb230_9, phi_bb230_10, tmp498, phi_bb230_13, phi_bb230_14, phi_bb230_20, tmp495, tmp496);
  }

  TNode<IntPtrT> phi_bb231_8;
  TNode<IntPtrT> phi_bb231_9;
  TNode<IntPtrT> phi_bb231_10;
  TNode<IntPtrT> phi_bb231_11;
  TNode<IntPtrT> phi_bb231_13;
  TNode<BoolT> phi_bb231_14;
  TNode<IntPtrT> phi_bb231_20;
  TNode<IntPtrT> tmp499;
  TNode<BoolT> tmp500;
  if (block231.is_used()) {
    ca_.Bind(&block231, &phi_bb231_8, &phi_bb231_9, &phi_bb231_10, &phi_bb231_11, &phi_bb231_13, &phi_bb231_14, &phi_bb231_20);
    tmp499 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp500 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb231_13}, TNode<IntPtrT>{tmp499});
    ca_.Branch(tmp500, &block233, std::vector<compiler::Node*>{phi_bb231_8, phi_bb231_9, phi_bb231_10, phi_bb231_11, phi_bb231_13, phi_bb231_14, phi_bb231_20}, &block234, std::vector<compiler::Node*>{phi_bb231_8, phi_bb231_9, phi_bb231_10, phi_bb231_11, phi_bb231_13, phi_bb231_14, phi_bb231_20});
  }

  TNode<IntPtrT> phi_bb233_8;
  TNode<IntPtrT> phi_bb233_9;
  TNode<IntPtrT> phi_bb233_10;
  TNode<IntPtrT> phi_bb233_11;
  TNode<IntPtrT> phi_bb233_13;
  TNode<BoolT> phi_bb233_14;
  TNode<IntPtrT> phi_bb233_20;
  TNode<Object> tmp501;
  TNode<IntPtrT> tmp502;
  TNode<IntPtrT> tmp503;
  TNode<BoolT> tmp504;
  if (block233.is_used()) {
    ca_.Bind(&block233, &phi_bb233_8, &phi_bb233_9, &phi_bb233_10, &phi_bb233_11, &phi_bb233_13, &phi_bb233_14, &phi_bb233_20);
    std::tie(tmp501, tmp502) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb233_13}).Flatten();
    tmp503 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp504 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block229, phi_bb233_8, phi_bb233_9, phi_bb233_10, phi_bb233_11, tmp503, tmp504, phi_bb233_20, tmp501, tmp502);
  }

  TNode<IntPtrT> phi_bb234_8;
  TNode<IntPtrT> phi_bb234_9;
  TNode<IntPtrT> phi_bb234_10;
  TNode<IntPtrT> phi_bb234_11;
  TNode<IntPtrT> phi_bb234_13;
  TNode<BoolT> phi_bb234_14;
  TNode<IntPtrT> phi_bb234_20;
  TNode<Object> tmp505;
  TNode<IntPtrT> tmp506;
  TNode<IntPtrT> tmp507;
  TNode<IntPtrT> tmp508;
  TNode<IntPtrT> tmp509;
  TNode<IntPtrT> tmp510;
  TNode<BoolT> tmp511;
  if (block234.is_used()) {
    ca_.Bind(&block234, &phi_bb234_8, &phi_bb234_9, &phi_bb234_10, &phi_bb234_11, &phi_bb234_13, &phi_bb234_14, &phi_bb234_20);
    std::tie(tmp505, tmp506) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb234_11}).Flatten();
    tmp507 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp508 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb234_11}, TNode<IntPtrT>{tmp507});
    tmp509 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp510 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp508}, TNode<IntPtrT>{tmp509});
    tmp511 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block229, phi_bb234_8, phi_bb234_9, phi_bb234_10, tmp510, tmp508, tmp511, phi_bb234_20, tmp505, tmp506);
  }

  TNode<IntPtrT> phi_bb229_8;
  TNode<IntPtrT> phi_bb229_9;
  TNode<IntPtrT> phi_bb229_10;
  TNode<IntPtrT> phi_bb229_11;
  TNode<IntPtrT> phi_bb229_13;
  TNode<BoolT> phi_bb229_14;
  TNode<IntPtrT> phi_bb229_20;
  TNode<Object> phi_bb229_22;
  TNode<IntPtrT> phi_bb229_23;
  if (block229.is_used()) {
    ca_.Bind(&block229, &phi_bb229_8, &phi_bb229_9, &phi_bb229_10, &phi_bb229_11, &phi_bb229_13, &phi_bb229_14, &phi_bb229_20, &phi_bb229_22, &phi_bb229_23);
    ca_.Goto(&block226, phi_bb229_8, phi_bb229_9, phi_bb229_10, phi_bb229_11, phi_bb229_13, phi_bb229_14, phi_bb229_20, phi_bb229_22, phi_bb229_23);
  }

  TNode<IntPtrT> phi_bb226_8;
  TNode<IntPtrT> phi_bb226_9;
  TNode<IntPtrT> phi_bb226_10;
  TNode<IntPtrT> phi_bb226_11;
  TNode<IntPtrT> phi_bb226_13;
  TNode<BoolT> phi_bb226_14;
  TNode<IntPtrT> phi_bb226_20;
  TNode<Object> phi_bb226_22;
  TNode<IntPtrT> phi_bb226_23;
  TNode<IntPtrT> tmp512;
  TNode<IntPtrT> tmp513;
  TNode<IntPtrT> tmp514;
  TNode<BoolT> tmp515;
  if (block226.is_used()) {
    ca_.Bind(&block226, &phi_bb226_8, &phi_bb226_9, &phi_bb226_10, &phi_bb226_11, &phi_bb226_13, &phi_bb226_14, &phi_bb226_20, &phi_bb226_22, &phi_bb226_23);
    tmp512 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp513 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp488}, TNode<IntPtrT>{tmp512});
    tmp514 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp515 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp488}, TNode<IntPtrT>{tmp514});
    ca_.Branch(tmp515, &block236, std::vector<compiler::Node*>{phi_bb226_8, phi_bb226_9, phi_bb226_10, phi_bb226_11, phi_bb226_13, phi_bb226_14, phi_bb226_20, phi_bb226_22, phi_bb226_23}, &block237, std::vector<compiler::Node*>{phi_bb226_8, phi_bb226_9, phi_bb226_10, phi_bb226_11, phi_bb226_13, phi_bb226_14, phi_bb226_20, phi_bb226_22, phi_bb226_23});
  }

  TNode<IntPtrT> phi_bb236_8;
  TNode<IntPtrT> phi_bb236_9;
  TNode<IntPtrT> phi_bb236_10;
  TNode<IntPtrT> phi_bb236_11;
  TNode<IntPtrT> phi_bb236_13;
  TNode<BoolT> phi_bb236_14;
  TNode<IntPtrT> phi_bb236_20;
  TNode<Object> phi_bb236_22;
  TNode<IntPtrT> phi_bb236_23;
  TNode<Object> tmp516;
  TNode<IntPtrT> tmp517;
  TNode<IntPtrT> tmp518;
  TNode<IntPtrT> tmp519;
  if (block236.is_used()) {
    ca_.Bind(&block236, &phi_bb236_8, &phi_bb236_9, &phi_bb236_10, &phi_bb236_11, &phi_bb236_13, &phi_bb236_14, &phi_bb236_20, &phi_bb236_22, &phi_bb236_23);
    std::tie(tmp516, tmp517) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb236_9}).Flatten();
    tmp518 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp519 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb236_9}, TNode<IntPtrT>{tmp518});
    ca_.Goto(&block235, phi_bb236_8, tmp519, phi_bb236_10, phi_bb236_11, phi_bb236_13, phi_bb236_14, phi_bb236_20, phi_bb236_22, phi_bb236_23, tmp516, tmp517);
  }

  TNode<IntPtrT> phi_bb237_8;
  TNode<IntPtrT> phi_bb237_9;
  TNode<IntPtrT> phi_bb237_10;
  TNode<IntPtrT> phi_bb237_11;
  TNode<IntPtrT> phi_bb237_13;
  TNode<BoolT> phi_bb237_14;
  TNode<IntPtrT> phi_bb237_20;
  TNode<Object> phi_bb237_22;
  TNode<IntPtrT> phi_bb237_23;
  if (block237.is_used()) {
    ca_.Bind(&block237, &phi_bb237_8, &phi_bb237_9, &phi_bb237_10, &phi_bb237_11, &phi_bb237_13, &phi_bb237_14, &phi_bb237_20, &phi_bb237_22, &phi_bb237_23);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block239, phi_bb237_8, phi_bb237_9, phi_bb237_10, phi_bb237_11, phi_bb237_13, phi_bb237_14, phi_bb237_20, phi_bb237_22, phi_bb237_23);
    } else {
      ca_.Goto(&block240, phi_bb237_8, phi_bb237_9, phi_bb237_10, phi_bb237_11, phi_bb237_13, phi_bb237_14, phi_bb237_20, phi_bb237_22, phi_bb237_23);
    }
  }

  TNode<IntPtrT> phi_bb239_8;
  TNode<IntPtrT> phi_bb239_9;
  TNode<IntPtrT> phi_bb239_10;
  TNode<IntPtrT> phi_bb239_11;
  TNode<IntPtrT> phi_bb239_13;
  TNode<BoolT> phi_bb239_14;
  TNode<IntPtrT> phi_bb239_20;
  TNode<Object> phi_bb239_22;
  TNode<IntPtrT> phi_bb239_23;
  TNode<Object> tmp520;
  TNode<IntPtrT> tmp521;
  TNode<IntPtrT> tmp522;
  TNode<IntPtrT> tmp523;
  if (block239.is_used()) {
    ca_.Bind(&block239, &phi_bb239_8, &phi_bb239_9, &phi_bb239_10, &phi_bb239_11, &phi_bb239_13, &phi_bb239_14, &phi_bb239_20, &phi_bb239_22, &phi_bb239_23);
    std::tie(tmp520, tmp521) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb239_11}).Flatten();
    tmp522 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp523 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb239_11}, TNode<IntPtrT>{tmp522});
    ca_.Goto(&block238, phi_bb239_8, phi_bb239_9, phi_bb239_10, tmp523, phi_bb239_13, phi_bb239_14, phi_bb239_20, phi_bb239_22, phi_bb239_23, tmp520, tmp521);
  }

  TNode<IntPtrT> phi_bb240_8;
  TNode<IntPtrT> phi_bb240_9;
  TNode<IntPtrT> phi_bb240_10;
  TNode<IntPtrT> phi_bb240_11;
  TNode<IntPtrT> phi_bb240_13;
  TNode<BoolT> phi_bb240_14;
  TNode<IntPtrT> phi_bb240_20;
  TNode<Object> phi_bb240_22;
  TNode<IntPtrT> phi_bb240_23;
  TNode<IntPtrT> tmp524;
  TNode<BoolT> tmp525;
  if (block240.is_used()) {
    ca_.Bind(&block240, &phi_bb240_8, &phi_bb240_9, &phi_bb240_10, &phi_bb240_11, &phi_bb240_13, &phi_bb240_14, &phi_bb240_20, &phi_bb240_22, &phi_bb240_23);
    tmp524 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp525 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb240_13}, TNode<IntPtrT>{tmp524});
    ca_.Branch(tmp525, &block242, std::vector<compiler::Node*>{phi_bb240_8, phi_bb240_9, phi_bb240_10, phi_bb240_11, phi_bb240_13, phi_bb240_14, phi_bb240_20, phi_bb240_22, phi_bb240_23}, &block243, std::vector<compiler::Node*>{phi_bb240_8, phi_bb240_9, phi_bb240_10, phi_bb240_11, phi_bb240_13, phi_bb240_14, phi_bb240_20, phi_bb240_22, phi_bb240_23});
  }

  TNode<IntPtrT> phi_bb242_8;
  TNode<IntPtrT> phi_bb242_9;
  TNode<IntPtrT> phi_bb242_10;
  TNode<IntPtrT> phi_bb242_11;
  TNode<IntPtrT> phi_bb242_13;
  TNode<BoolT> phi_bb242_14;
  TNode<IntPtrT> phi_bb242_20;
  TNode<Object> phi_bb242_22;
  TNode<IntPtrT> phi_bb242_23;
  TNode<Object> tmp526;
  TNode<IntPtrT> tmp527;
  TNode<IntPtrT> tmp528;
  TNode<BoolT> tmp529;
  if (block242.is_used()) {
    ca_.Bind(&block242, &phi_bb242_8, &phi_bb242_9, &phi_bb242_10, &phi_bb242_11, &phi_bb242_13, &phi_bb242_14, &phi_bb242_20, &phi_bb242_22, &phi_bb242_23);
    std::tie(tmp526, tmp527) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb242_13}).Flatten();
    tmp528 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp529 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block238, phi_bb242_8, phi_bb242_9, phi_bb242_10, phi_bb242_11, tmp528, tmp529, phi_bb242_20, phi_bb242_22, phi_bb242_23, tmp526, tmp527);
  }

  TNode<IntPtrT> phi_bb243_8;
  TNode<IntPtrT> phi_bb243_9;
  TNode<IntPtrT> phi_bb243_10;
  TNode<IntPtrT> phi_bb243_11;
  TNode<IntPtrT> phi_bb243_13;
  TNode<BoolT> phi_bb243_14;
  TNode<IntPtrT> phi_bb243_20;
  TNode<Object> phi_bb243_22;
  TNode<IntPtrT> phi_bb243_23;
  TNode<Object> tmp530;
  TNode<IntPtrT> tmp531;
  TNode<IntPtrT> tmp532;
  TNode<IntPtrT> tmp533;
  TNode<IntPtrT> tmp534;
  TNode<IntPtrT> tmp535;
  TNode<BoolT> tmp536;
  if (block243.is_used()) {
    ca_.Bind(&block243, &phi_bb243_8, &phi_bb243_9, &phi_bb243_10, &phi_bb243_11, &phi_bb243_13, &phi_bb243_14, &phi_bb243_20, &phi_bb243_22, &phi_bb243_23);
    std::tie(tmp530, tmp531) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb243_11}).Flatten();
    tmp532 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp533 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb243_11}, TNode<IntPtrT>{tmp532});
    tmp534 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp535 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp533}, TNode<IntPtrT>{tmp534});
    tmp536 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block238, phi_bb243_8, phi_bb243_9, phi_bb243_10, tmp535, tmp533, tmp536, phi_bb243_20, phi_bb243_22, phi_bb243_23, tmp530, tmp531);
  }

  TNode<IntPtrT> phi_bb238_8;
  TNode<IntPtrT> phi_bb238_9;
  TNode<IntPtrT> phi_bb238_10;
  TNode<IntPtrT> phi_bb238_11;
  TNode<IntPtrT> phi_bb238_13;
  TNode<BoolT> phi_bb238_14;
  TNode<IntPtrT> phi_bb238_20;
  TNode<Object> phi_bb238_22;
  TNode<IntPtrT> phi_bb238_23;
  TNode<Object> phi_bb238_24;
  TNode<IntPtrT> phi_bb238_25;
  if (block238.is_used()) {
    ca_.Bind(&block238, &phi_bb238_8, &phi_bb238_9, &phi_bb238_10, &phi_bb238_11, &phi_bb238_13, &phi_bb238_14, &phi_bb238_20, &phi_bb238_22, &phi_bb238_23, &phi_bb238_24, &phi_bb238_25);
    ca_.Goto(&block235, phi_bb238_8, phi_bb238_9, phi_bb238_10, phi_bb238_11, phi_bb238_13, phi_bb238_14, phi_bb238_20, phi_bb238_22, phi_bb238_23, phi_bb238_24, phi_bb238_25);
  }

  TNode<IntPtrT> phi_bb235_8;
  TNode<IntPtrT> phi_bb235_9;
  TNode<IntPtrT> phi_bb235_10;
  TNode<IntPtrT> phi_bb235_11;
  TNode<IntPtrT> phi_bb235_13;
  TNode<BoolT> phi_bb235_14;
  TNode<IntPtrT> phi_bb235_20;
  TNode<Object> phi_bb235_22;
  TNode<IntPtrT> phi_bb235_23;
  TNode<Object> phi_bb235_24;
  TNode<IntPtrT> phi_bb235_25;
  TNode<IntPtrT> tmp537;
  TNode<IntPtrT> tmp538;
  TNode<Object> tmp539;
  TNode<IntPtrT> tmp540;
  TNode<IntPtrT> tmp541;
  TNode<UintPtrT> tmp542;
  TNode<UintPtrT> tmp543;
  TNode<BoolT> tmp544;
  if (block235.is_used()) {
    ca_.Bind(&block235, &phi_bb235_8, &phi_bb235_9, &phi_bb235_10, &phi_bb235_11, &phi_bb235_13, &phi_bb235_14, &phi_bb235_20, &phi_bb235_22, &phi_bb235_23, &phi_bb235_24, &phi_bb235_25);
    tmp537 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb235_22, phi_bb235_23});
    tmp538 = CodeStubAssembler(state_).LoadReference<IntPtrT>(CodeStubAssembler::Reference{phi_bb235_24, phi_bb235_25});
    std::tie(tmp539, tmp540, tmp541) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp85}).Flatten();
    tmp542 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb235_20});
    tmp543 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp541});
    tmp544 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp542}, TNode<UintPtrT>{tmp543});
    ca_.Branch(tmp544, &block248, std::vector<compiler::Node*>{phi_bb235_8, phi_bb235_9, phi_bb235_10, phi_bb235_11, phi_bb235_13, phi_bb235_14, phi_bb235_20, phi_bb235_22, phi_bb235_23, phi_bb235_24, phi_bb235_25, phi_bb235_20, phi_bb235_20, phi_bb235_20, phi_bb235_20}, &block249, std::vector<compiler::Node*>{phi_bb235_8, phi_bb235_9, phi_bb235_10, phi_bb235_11, phi_bb235_13, phi_bb235_14, phi_bb235_20, phi_bb235_22, phi_bb235_23, phi_bb235_24, phi_bb235_25, phi_bb235_20, phi_bb235_20, phi_bb235_20, phi_bb235_20});
  }

  TNode<IntPtrT> phi_bb248_8;
  TNode<IntPtrT> phi_bb248_9;
  TNode<IntPtrT> phi_bb248_10;
  TNode<IntPtrT> phi_bb248_11;
  TNode<IntPtrT> phi_bb248_13;
  TNode<BoolT> phi_bb248_14;
  TNode<IntPtrT> phi_bb248_20;
  TNode<Object> phi_bb248_22;
  TNode<IntPtrT> phi_bb248_23;
  TNode<Object> phi_bb248_24;
  TNode<IntPtrT> phi_bb248_25;
  TNode<IntPtrT> phi_bb248_32;
  TNode<IntPtrT> phi_bb248_33;
  TNode<IntPtrT> phi_bb248_37;
  TNode<IntPtrT> phi_bb248_38;
  TNode<IntPtrT> tmp545;
  TNode<IntPtrT> tmp546;
  TNode<Object> tmp547;
  TNode<IntPtrT> tmp548;
  TNode<BigInt> tmp549;
  if (block248.is_used()) {
    ca_.Bind(&block248, &phi_bb248_8, &phi_bb248_9, &phi_bb248_10, &phi_bb248_11, &phi_bb248_13, &phi_bb248_14, &phi_bb248_20, &phi_bb248_22, &phi_bb248_23, &phi_bb248_24, &phi_bb248_25, &phi_bb248_32, &phi_bb248_33, &phi_bb248_37, &phi_bb248_38);
    tmp545 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb248_38});
    tmp546 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp540}, TNode<IntPtrT>{tmp545});
    std::tie(tmp547, tmp548) = NewReference_Object_0(state_, TNode<Object>{tmp539}, TNode<IntPtrT>{tmp546}).Flatten();
    tmp549 = ca_.CallBuiltin<BigInt>(Builtin::kI32PairToBigInt, TNode<Object>(), tmp537, tmp538);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp547, tmp548}, tmp549);
    ca_.Goto(&block208, tmp513, phi_bb248_8, phi_bb248_9, phi_bb248_10, phi_bb248_11, phi_bb248_13, phi_bb248_14, phi_bb248_20);
  }

  TNode<IntPtrT> phi_bb249_8;
  TNode<IntPtrT> phi_bb249_9;
  TNode<IntPtrT> phi_bb249_10;
  TNode<IntPtrT> phi_bb249_11;
  TNode<IntPtrT> phi_bb249_13;
  TNode<BoolT> phi_bb249_14;
  TNode<IntPtrT> phi_bb249_20;
  TNode<Object> phi_bb249_22;
  TNode<IntPtrT> phi_bb249_23;
  TNode<Object> phi_bb249_24;
  TNode<IntPtrT> phi_bb249_25;
  TNode<IntPtrT> phi_bb249_32;
  TNode<IntPtrT> phi_bb249_33;
  TNode<IntPtrT> phi_bb249_37;
  TNode<IntPtrT> phi_bb249_38;
  if (block249.is_used()) {
    ca_.Bind(&block249, &phi_bb249_8, &phi_bb249_9, &phi_bb249_10, &phi_bb249_11, &phi_bb249_13, &phi_bb249_14, &phi_bb249_20, &phi_bb249_22, &phi_bb249_23, &phi_bb249_24, &phi_bb249_25, &phi_bb249_32, &phi_bb249_33, &phi_bb249_37, &phi_bb249_38);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb208_7;
  TNode<IntPtrT> phi_bb208_8;
  TNode<IntPtrT> phi_bb208_9;
  TNode<IntPtrT> phi_bb208_10;
  TNode<IntPtrT> phi_bb208_11;
  TNode<IntPtrT> phi_bb208_13;
  TNode<BoolT> phi_bb208_14;
  TNode<IntPtrT> phi_bb208_20;
  if (block208.is_used()) {
    ca_.Bind(&block208, &phi_bb208_7, &phi_bb208_8, &phi_bb208_9, &phi_bb208_10, &phi_bb208_11, &phi_bb208_13, &phi_bb208_14, &phi_bb208_20);
    ca_.Goto(&block205, phi_bb208_7, phi_bb208_8, phi_bb208_9, phi_bb208_10, phi_bb208_11, phi_bb208_13, phi_bb208_14, phi_bb208_20);
  }

  TNode<IntPtrT> phi_bb204_7;
  TNode<IntPtrT> phi_bb204_8;
  TNode<IntPtrT> phi_bb204_9;
  TNode<IntPtrT> phi_bb204_10;
  TNode<IntPtrT> phi_bb204_11;
  TNode<IntPtrT> phi_bb204_13;
  TNode<BoolT> phi_bb204_14;
  TNode<IntPtrT> phi_bb204_20;
  TNode<Int32T> tmp550;
  TNode<BoolT> tmp551;
  if (block204.is_used()) {
    ca_.Bind(&block204, &phi_bb204_7, &phi_bb204_8, &phi_bb204_9, &phi_bb204_10, &phi_bb204_11, &phi_bb204_13, &phi_bb204_14, &phi_bb204_20);
    tmp550 = FromConstexpr_int32_constexpr_int32_0(state_, wasm::kWasmF64.raw_bit_field());
    tmp551 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp340}, TNode<Int32T>{tmp550});
    ca_.Branch(tmp551, &block252, std::vector<compiler::Node*>{phi_bb204_7, phi_bb204_8, phi_bb204_9, phi_bb204_10, phi_bb204_11, phi_bb204_13, phi_bb204_14, phi_bb204_20}, &block253, std::vector<compiler::Node*>{phi_bb204_7, phi_bb204_8, phi_bb204_9, phi_bb204_10, phi_bb204_11, phi_bb204_13, phi_bb204_14, phi_bb204_20});
  }

  TNode<IntPtrT> phi_bb252_7;
  TNode<IntPtrT> phi_bb252_8;
  TNode<IntPtrT> phi_bb252_9;
  TNode<IntPtrT> phi_bb252_10;
  TNode<IntPtrT> phi_bb252_11;
  TNode<IntPtrT> phi_bb252_13;
  TNode<BoolT> phi_bb252_14;
  TNode<IntPtrT> phi_bb252_20;
  TNode<IntPtrT> tmp552;
  TNode<IntPtrT> tmp553;
  TNode<IntPtrT> tmp554;
  TNode<BoolT> tmp555;
  if (block252.is_used()) {
    ca_.Bind(&block252, &phi_bb252_7, &phi_bb252_8, &phi_bb252_9, &phi_bb252_10, &phi_bb252_11, &phi_bb252_13, &phi_bb252_14, &phi_bb252_20);
    tmp552 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp553 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{phi_bb252_8}, TNode<IntPtrT>{tmp552});
    tmp554 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp555 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{phi_bb252_8}, TNode<IntPtrT>{tmp554});
    ca_.Branch(tmp555, &block256, std::vector<compiler::Node*>{phi_bb252_7, phi_bb252_9, phi_bb252_10, phi_bb252_11, phi_bb252_13, phi_bb252_14, phi_bb252_20}, &block257, std::vector<compiler::Node*>{phi_bb252_7, phi_bb252_9, phi_bb252_10, phi_bb252_11, phi_bb252_13, phi_bb252_14, phi_bb252_20});
  }

  TNode<IntPtrT> phi_bb256_7;
  TNode<IntPtrT> phi_bb256_9;
  TNode<IntPtrT> phi_bb256_10;
  TNode<IntPtrT> phi_bb256_11;
  TNode<IntPtrT> phi_bb256_13;
  TNode<BoolT> phi_bb256_14;
  TNode<IntPtrT> phi_bb256_20;
  TNode<Object> tmp556;
  TNode<IntPtrT> tmp557;
  TNode<IntPtrT> tmp558;
  TNode<IntPtrT> tmp559;
  if (block256.is_used()) {
    ca_.Bind(&block256, &phi_bb256_7, &phi_bb256_9, &phi_bb256_10, &phi_bb256_11, &phi_bb256_13, &phi_bb256_14, &phi_bb256_20);
    std::tie(tmp556, tmp557) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb256_10}).Flatten();
    tmp558 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_float64_0(state_)));
    tmp559 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb256_10}, TNode<IntPtrT>{tmp558});
    ca_.Goto(&block255, phi_bb256_7, phi_bb256_9, tmp559, phi_bb256_11, phi_bb256_13, phi_bb256_14, phi_bb256_20, tmp556, tmp557);
  }

  TNode<IntPtrT> phi_bb257_7;
  TNode<IntPtrT> phi_bb257_9;
  TNode<IntPtrT> phi_bb257_10;
  TNode<IntPtrT> phi_bb257_11;
  TNode<IntPtrT> phi_bb257_13;
  TNode<BoolT> phi_bb257_14;
  TNode<IntPtrT> phi_bb257_20;
  if (block257.is_used()) {
    ca_.Bind(&block257, &phi_bb257_7, &phi_bb257_9, &phi_bb257_10, &phi_bb257_11, &phi_bb257_13, &phi_bb257_14, &phi_bb257_20);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block258, phi_bb257_7, phi_bb257_9, phi_bb257_10, phi_bb257_11, phi_bb257_13, phi_bb257_14, phi_bb257_20);
    } else {
      ca_.Goto(&block259, phi_bb257_7, phi_bb257_9, phi_bb257_10, phi_bb257_11, phi_bb257_13, phi_bb257_14, phi_bb257_20);
    }
  }

  TNode<IntPtrT> phi_bb258_7;
  TNode<IntPtrT> phi_bb258_9;
  TNode<IntPtrT> phi_bb258_10;
  TNode<IntPtrT> phi_bb258_11;
  TNode<IntPtrT> phi_bb258_13;
  TNode<BoolT> phi_bb258_14;
  TNode<IntPtrT> phi_bb258_20;
  if (block258.is_used()) {
    ca_.Bind(&block258, &phi_bb258_7, &phi_bb258_9, &phi_bb258_10, &phi_bb258_11, &phi_bb258_13, &phi_bb258_14, &phi_bb258_20);
    if (((CodeStubAssembler(state_).Is64()))) {
      ca_.Goto(&block262, phi_bb258_7, phi_bb258_9, phi_bb258_10, phi_bb258_11, phi_bb258_13, phi_bb258_14, phi_bb258_20);
    } else {
      ca_.Goto(&block263, phi_bb258_7, phi_bb258_9, phi_bb258_10, phi_bb258_11, phi_bb258_13, phi_bb258_14, phi_bb258_20);
    }
  }

  TNode<IntPtrT> phi_bb262_7;
  TNode<IntPtrT> phi_bb262_9;
  TNode<IntPtrT> phi_bb262_10;
  TNode<IntPtrT> phi_bb262_11;
  TNode<IntPtrT> phi_bb262_13;
  TNode<BoolT> phi_bb262_14;
  TNode<IntPtrT> phi_bb262_20;
  TNode<Object> tmp560;
  TNode<IntPtrT> tmp561;
  TNode<IntPtrT> tmp562;
  TNode<IntPtrT> tmp563;
  if (block262.is_used()) {
    ca_.Bind(&block262, &phi_bb262_7, &phi_bb262_9, &phi_bb262_10, &phi_bb262_11, &phi_bb262_13, &phi_bb262_14, &phi_bb262_20);
    std::tie(tmp560, tmp561) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb262_11}).Flatten();
    tmp562 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp563 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb262_11}, TNode<IntPtrT>{tmp562});
    ca_.Goto(&block261, phi_bb262_7, phi_bb262_9, phi_bb262_10, tmp563, phi_bb262_13, phi_bb262_14, phi_bb262_20, tmp560, tmp561);
  }

  TNode<IntPtrT> phi_bb263_7;
  TNode<IntPtrT> phi_bb263_9;
  TNode<IntPtrT> phi_bb263_10;
  TNode<IntPtrT> phi_bb263_11;
  TNode<IntPtrT> phi_bb263_13;
  TNode<BoolT> phi_bb263_14;
  TNode<IntPtrT> phi_bb263_20;
  TNode<IntPtrT> tmp564;
  TNode<BoolT> tmp565;
  if (block263.is_used()) {
    ca_.Bind(&block263, &phi_bb263_7, &phi_bb263_9, &phi_bb263_10, &phi_bb263_11, &phi_bb263_13, &phi_bb263_14, &phi_bb263_20);
    tmp564 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp565 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{phi_bb263_13}, TNode<IntPtrT>{tmp564});
    ca_.Branch(tmp565, &block265, std::vector<compiler::Node*>{phi_bb263_7, phi_bb263_9, phi_bb263_10, phi_bb263_11, phi_bb263_13, phi_bb263_14, phi_bb263_20}, &block266, std::vector<compiler::Node*>{phi_bb263_7, phi_bb263_9, phi_bb263_10, phi_bb263_11, phi_bb263_13, phi_bb263_14, phi_bb263_20});
  }

  TNode<IntPtrT> phi_bb265_7;
  TNode<IntPtrT> phi_bb265_9;
  TNode<IntPtrT> phi_bb265_10;
  TNode<IntPtrT> phi_bb265_11;
  TNode<IntPtrT> phi_bb265_13;
  TNode<BoolT> phi_bb265_14;
  TNode<IntPtrT> phi_bb265_20;
  TNode<Object> tmp566;
  TNode<IntPtrT> tmp567;
  TNode<IntPtrT> tmp568;
  TNode<BoolT> tmp569;
  if (block265.is_used()) {
    ca_.Bind(&block265, &phi_bb265_7, &phi_bb265_9, &phi_bb265_10, &phi_bb265_11, &phi_bb265_13, &phi_bb265_14, &phi_bb265_20);
    std::tie(tmp566, tmp567) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb265_13}).Flatten();
    tmp568 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp569 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block261, phi_bb265_7, phi_bb265_9, phi_bb265_10, phi_bb265_11, tmp568, tmp569, phi_bb265_20, tmp566, tmp567);
  }

  TNode<IntPtrT> phi_bb266_7;
  TNode<IntPtrT> phi_bb266_9;
  TNode<IntPtrT> phi_bb266_10;
  TNode<IntPtrT> phi_bb266_11;
  TNode<IntPtrT> phi_bb266_13;
  TNode<BoolT> phi_bb266_14;
  TNode<IntPtrT> phi_bb266_20;
  TNode<Object> tmp570;
  TNode<IntPtrT> tmp571;
  TNode<IntPtrT> tmp572;
  TNode<IntPtrT> tmp573;
  TNode<IntPtrT> tmp574;
  TNode<IntPtrT> tmp575;
  TNode<BoolT> tmp576;
  if (block266.is_used()) {
    ca_.Bind(&block266, &phi_bb266_7, &phi_bb266_9, &phi_bb266_10, &phi_bb266_11, &phi_bb266_13, &phi_bb266_14, &phi_bb266_20);
    std::tie(tmp570, tmp571) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb266_11}).Flatten();
    tmp572 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp573 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb266_11}, TNode<IntPtrT>{tmp572});
    tmp574 = FromConstexpr_intptr_constexpr_int31_0(state_, (SizeOf_intptr_0(state_)));
    tmp575 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp573}, TNode<IntPtrT>{tmp574});
    tmp576 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block261, phi_bb266_7, phi_bb266_9, phi_bb266_10, tmp575, tmp573, tmp576, phi_bb266_20, tmp570, tmp571);
  }

  TNode<IntPtrT> phi_bb261_7;
  TNode<IntPtrT> phi_bb261_9;
  TNode<IntPtrT> phi_bb261_10;
  TNode<IntPtrT> phi_bb261_11;
  TNode<IntPtrT> phi_bb261_13;
  TNode<BoolT> phi_bb261_14;
  TNode<IntPtrT> phi_bb261_20;
  TNode<Object> phi_bb261_22;
  TNode<IntPtrT> phi_bb261_23;
  if (block261.is_used()) {
    ca_.Bind(&block261, &phi_bb261_7, &phi_bb261_9, &phi_bb261_10, &phi_bb261_11, &phi_bb261_13, &phi_bb261_14, &phi_bb261_20, &phi_bb261_22, &phi_bb261_23);
    ca_.Goto(&block255, phi_bb261_7, phi_bb261_9, phi_bb261_10, phi_bb261_11, phi_bb261_13, phi_bb261_14, phi_bb261_20, phi_bb261_22, phi_bb261_23);
  }

  TNode<IntPtrT> phi_bb259_7;
  TNode<IntPtrT> phi_bb259_9;
  TNode<IntPtrT> phi_bb259_10;
  TNode<IntPtrT> phi_bb259_11;
  TNode<IntPtrT> phi_bb259_13;
  TNode<BoolT> phi_bb259_14;
  TNode<IntPtrT> phi_bb259_20;
  TNode<Object> tmp577;
  TNode<IntPtrT> tmp578;
  TNode<IntPtrT> tmp579;
  TNode<IntPtrT> tmp580;
  TNode<BoolT> tmp581;
  if (block259.is_used()) {
    ca_.Bind(&block259, &phi_bb259_7, &phi_bb259_9, &phi_bb259_10, &phi_bb259_11, &phi_bb259_13, &phi_bb259_14, &phi_bb259_20);
    std::tie(tmp577, tmp578) = NewReference_intptr_0(state_, TNode<Object>{tmp324}, TNode<IntPtrT>{phi_bb259_11}).Flatten();
    tmp579 = FromConstexpr_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Mul((FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull))), (SizeOf_intptr_0(state_)))));
    tmp580 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb259_11}, TNode<IntPtrT>{tmp579});
    tmp581 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block255, phi_bb259_7, phi_bb259_9, phi_bb259_10, tmp580, phi_bb259_13, tmp581, phi_bb259_20, tmp577, tmp578);
  }

  TNode<IntPtrT> phi_bb255_7;
  TNode<IntPtrT> phi_bb255_9;
  TNode<IntPtrT> phi_bb255_10;
  TNode<IntPtrT> phi_bb255_11;
  TNode<IntPtrT> phi_bb255_13;
  TNode<BoolT> phi_bb255_14;
  TNode<IntPtrT> phi_bb255_20;
  TNode<Object> phi_bb255_22;
  TNode<IntPtrT> phi_bb255_23;
  TNode<Object> tmp582;
  TNode<IntPtrT> tmp583;
  TNode<Float64T> tmp584;
  TNode<Object> tmp585;
  TNode<IntPtrT> tmp586;
  TNode<IntPtrT> tmp587;
  TNode<UintPtrT> tmp588;
  TNode<UintPtrT> tmp589;
  TNode<BoolT> tmp590;
  if (block255.is_used()) {
    ca_.Bind(&block255, &phi_bb255_7, &phi_bb255_9, &phi_bb255_10, &phi_bb255_11, &phi_bb255_13, &phi_bb255_14, &phi_bb255_20, &phi_bb255_22, &phi_bb255_23);
    std::tie(tmp582, tmp583) = RefCast_float64_0(state_, TorqueStructReference_intptr_0{TNode<Object>{phi_bb255_22}, TNode<IntPtrT>{phi_bb255_23}, TorqueStructUnsafe_0{}}).Flatten();
    tmp584 = CodeStubAssembler(state_).LoadReference<Float64T>(CodeStubAssembler::Reference{tmp582, tmp583});
    std::tie(tmp585, tmp586, tmp587) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp85}).Flatten();
    tmp588 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb255_20});
    tmp589 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp587});
    tmp590 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp588}, TNode<UintPtrT>{tmp589});
    ca_.Branch(tmp590, &block271, std::vector<compiler::Node*>{phi_bb255_7, phi_bb255_9, phi_bb255_10, phi_bb255_11, phi_bb255_13, phi_bb255_14, phi_bb255_20, phi_bb255_22, phi_bb255_23, phi_bb255_20, phi_bb255_20, phi_bb255_20, phi_bb255_20}, &block272, std::vector<compiler::Node*>{phi_bb255_7, phi_bb255_9, phi_bb255_10, phi_bb255_11, phi_bb255_13, phi_bb255_14, phi_bb255_20, phi_bb255_22, phi_bb255_23, phi_bb255_20, phi_bb255_20, phi_bb255_20, phi_bb255_20});
  }

  TNode<IntPtrT> phi_bb271_7;
  TNode<IntPtrT> phi_bb271_9;
  TNode<IntPtrT> phi_bb271_10;
  TNode<IntPtrT> phi_bb271_11;
  TNode<IntPtrT> phi_bb271_13;
  TNode<BoolT> phi_bb271_14;
  TNode<IntPtrT> phi_bb271_20;
  TNode<Object> phi_bb271_22;
  TNode<IntPtrT> phi_bb271_23;
  TNode<IntPtrT> phi_bb271_29;
  TNode<IntPtrT> phi_bb271_30;
  TNode<IntPtrT> phi_bb271_34;
  TNode<IntPtrT> phi_bb271_35;
  TNode<IntPtrT> tmp591;
  TNode<IntPtrT> tmp592;
  TNode<Object> tmp593;
  TNode<IntPtrT> tmp594;
  TNode<Number> tmp595;
  if (block271.is_used()) {
    ca_.Bind(&block271, &phi_bb271_7, &phi_bb271_9, &phi_bb271_10, &phi_bb271_11, &phi_bb271_13, &phi_bb271_14, &phi_bb271_20, &phi_bb271_22, &phi_bb271_23, &phi_bb271_29, &phi_bb271_30, &phi_bb271_34, &phi_bb271_35);
    tmp591 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb271_35});
    tmp592 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp586}, TNode<IntPtrT>{tmp591});
    std::tie(tmp593, tmp594) = NewReference_Object_0(state_, TNode<Object>{tmp585}, TNode<IntPtrT>{tmp592}).Flatten();
    tmp595 = Convert_Number_float64_0(state_, TNode<Float64T>{tmp584});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp593, tmp594}, tmp595);
    ca_.Goto(&block254, phi_bb271_7, tmp553, phi_bb271_9, phi_bb271_10, phi_bb271_11, phi_bb271_13, phi_bb271_14, phi_bb271_20);
  }

  TNode<IntPtrT> phi_bb272_7;
  TNode<IntPtrT> phi_bb272_9;
  TNode<IntPtrT> phi_bb272_10;
  TNode<IntPtrT> phi_bb272_11;
  TNode<IntPtrT> phi_bb272_13;
  TNode<BoolT> phi_bb272_14;
  TNode<IntPtrT> phi_bb272_20;
  TNode<Object> phi_bb272_22;
  TNode<IntPtrT> phi_bb272_23;
  TNode<IntPtrT> phi_bb272_29;
  TNode<IntPtrT> phi_bb272_30;
  TNode<IntPtrT> phi_bb272_34;
  TNode<IntPtrT> phi_bb272_35;
  if (block272.is_used()) {
    ca_.Bind(&block272, &phi_bb272_7, &phi_bb272_9, &phi_bb272_10, &phi_bb272_11, &phi_bb272_13, &phi_bb272_14, &phi_bb272_20, &phi_bb272_22, &phi_bb272_23, &phi_bb272_29, &phi_bb272_30, &phi_bb272_34, &phi_bb272_35);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb253_7;
  TNode<IntPtrT> phi_bb253_8;
  TNode<IntPtrT> phi_bb253_9;
  TNode<IntPtrT> phi_bb253_10;
  TNode<IntPtrT> phi_bb253_11;
  TNode<IntPtrT> phi_bb253_13;
  TNode<BoolT> phi_bb253_14;
  TNode<IntPtrT> phi_bb253_20;
  TNode<Object> tmp596;
  TNode<IntPtrT> tmp597;
  TNode<IntPtrT> tmp598;
  TNode<UintPtrT> tmp599;
  TNode<UintPtrT> tmp600;
  TNode<BoolT> tmp601;
  if (block253.is_used()) {
    ca_.Bind(&block253, &phi_bb253_7, &phi_bb253_8, &phi_bb253_9, &phi_bb253_10, &phi_bb253_11, &phi_bb253_13, &phi_bb253_14, &phi_bb253_20);
    std::tie(tmp596, tmp597, tmp598) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp85}).Flatten();
    tmp599 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb253_20});
    tmp600 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp598});
    tmp601 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp599}, TNode<UintPtrT>{tmp600});
    ca_.Branch(tmp601, &block279, std::vector<compiler::Node*>{phi_bb253_7, phi_bb253_8, phi_bb253_9, phi_bb253_10, phi_bb253_11, phi_bb253_13, phi_bb253_14, phi_bb253_20, phi_bb253_20, phi_bb253_20, phi_bb253_20, phi_bb253_20}, &block280, std::vector<compiler::Node*>{phi_bb253_7, phi_bb253_8, phi_bb253_9, phi_bb253_10, phi_bb253_11, phi_bb253_13, phi_bb253_14, phi_bb253_20, phi_bb253_20, phi_bb253_20, phi_bb253_20, phi_bb253_20});
  }

  TNode<IntPtrT> phi_bb279_7;
  TNode<IntPtrT> phi_bb279_8;
  TNode<IntPtrT> phi_bb279_9;
  TNode<IntPtrT> phi_bb279_10;
  TNode<IntPtrT> phi_bb279_11;
  TNode<IntPtrT> phi_bb279_13;
  TNode<BoolT> phi_bb279_14;
  TNode<IntPtrT> phi_bb279_20;
  TNode<IntPtrT> phi_bb279_26;
  TNode<IntPtrT> phi_bb279_27;
  TNode<IntPtrT> phi_bb279_31;
  TNode<IntPtrT> phi_bb279_32;
  TNode<IntPtrT> tmp602;
  TNode<IntPtrT> tmp603;
  TNode<Object> tmp604;
  TNode<IntPtrT> tmp605;
  TNode<Object> tmp606;
  TNode<Object> tmp607;
  TNode<IntPtrT> tmp608;
  TNode<IntPtrT> tmp609;
  TNode<UintPtrT> tmp610;
  TNode<UintPtrT> tmp611;
  TNode<BoolT> tmp612;
  if (block279.is_used()) {
    ca_.Bind(&block279, &phi_bb279_7, &phi_bb279_8, &phi_bb279_9, &phi_bb279_10, &phi_bb279_11, &phi_bb279_13, &phi_bb279_14, &phi_bb279_20, &phi_bb279_26, &phi_bb279_27, &phi_bb279_31, &phi_bb279_32);
    tmp602 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb279_32});
    tmp603 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp597}, TNode<IntPtrT>{tmp602});
    std::tie(tmp604, tmp605) = NewReference_Object_0(state_, TNode<Object>{tmp596}, TNode<IntPtrT>{tmp603}).Flatten();
    tmp606 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp604, tmp605});
    std::tie(tmp607, tmp608, tmp609) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray>{tmp85}).Flatten();
    tmp610 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb279_20});
    tmp611 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp609});
    tmp612 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp610}, TNode<UintPtrT>{tmp611});
    ca_.Branch(tmp612, &block287, std::vector<compiler::Node*>{phi_bb279_7, phi_bb279_8, phi_bb279_9, phi_bb279_10, phi_bb279_11, phi_bb279_13, phi_bb279_14, phi_bb279_20, phi_bb279_20, phi_bb279_20, phi_bb279_20, phi_bb279_20}, &block288, std::vector<compiler::Node*>{phi_bb279_7, phi_bb279_8, phi_bb279_9, phi_bb279_10, phi_bb279_11, phi_bb279_13, phi_bb279_14, phi_bb279_20, phi_bb279_20, phi_bb279_20, phi_bb279_20, phi_bb279_20});
  }

  TNode<IntPtrT> phi_bb280_7;
  TNode<IntPtrT> phi_bb280_8;
  TNode<IntPtrT> phi_bb280_9;
  TNode<IntPtrT> phi_bb280_10;
  TNode<IntPtrT> phi_bb280_11;
  TNode<IntPtrT> phi_bb280_13;
  TNode<BoolT> phi_bb280_14;
  TNode<IntPtrT> phi_bb280_20;
  TNode<IntPtrT> phi_bb280_26;
  TNode<IntPtrT> phi_bb280_27;
  TNode<IntPtrT> phi_bb280_31;
  TNode<IntPtrT> phi_bb280_32;
  if (block280.is_used()) {
    ca_.Bind(&block280, &phi_bb280_7, &phi_bb280_8, &phi_bb280_9, &phi_bb280_10, &phi_bb280_11, &phi_bb280_13, &phi_bb280_14, &phi_bb280_20, &phi_bb280_26, &phi_bb280_27, &phi_bb280_31, &phi_bb280_32);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb287_7;
  TNode<IntPtrT> phi_bb287_8;
  TNode<IntPtrT> phi_bb287_9;
  TNode<IntPtrT> phi_bb287_10;
  TNode<IntPtrT> phi_bb287_11;
  TNode<IntPtrT> phi_bb287_13;
  TNode<BoolT> phi_bb287_14;
  TNode<IntPtrT> phi_bb287_20;
  TNode<IntPtrT> phi_bb287_27;
  TNode<IntPtrT> phi_bb287_28;
  TNode<IntPtrT> phi_bb287_32;
  TNode<IntPtrT> phi_bb287_33;
  TNode<IntPtrT> tmp613;
  TNode<IntPtrT> tmp614;
  TNode<Object> tmp615;
  TNode<IntPtrT> tmp616;
  TNode<Object> tmp617;
  if (block287.is_used()) {
    ca_.Bind(&block287, &phi_bb287_7, &phi_bb287_8, &phi_bb287_9, &phi_bb287_10, &phi_bb287_11, &phi_bb287_13, &phi_bb287_14, &phi_bb287_20, &phi_bb287_27, &phi_bb287_28, &phi_bb287_32, &phi_bb287_33);
    tmp613 = TimesSizeOf_Object_0(state_, TNode<IntPtrT>{phi_bb287_33});
    tmp614 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp608}, TNode<IntPtrT>{tmp613});
    std::tie(tmp615, tmp616) = NewReference_Object_0(state_, TNode<Object>{tmp607}, TNode<IntPtrT>{tmp614}).Flatten();
    tmp617 = WasmToJSObject_0(state_, TNode<NativeContext>{parameter0}, TNode<Object>{tmp606}, TNode<Int32T>{tmp340});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp615, tmp616}, tmp617);
    ca_.Goto(&block254, phi_bb287_7, phi_bb287_8, phi_bb287_9, phi_bb287_10, phi_bb287_11, phi_bb287_13, phi_bb287_14, phi_bb287_20);
  }

  TNode<IntPtrT> phi_bb288_7;
  TNode<IntPtrT> phi_bb288_8;
  TNode<IntPtrT> phi_bb288_9;
  TNode<IntPtrT> phi_bb288_10;
  TNode<IntPtrT> phi_bb288_11;
  TNode<IntPtrT> phi_bb288_13;
  TNode<BoolT> phi_bb288_14;
  TNode<IntPtrT> phi_bb288_20;
  TNode<IntPtrT> phi_bb288_27;
  TNode<IntPtrT> phi_bb288_28;
  TNode<IntPtrT> phi_bb288_32;
  TNode<IntPtrT> phi_bb288_33;
  if (block288.is_used()) {
    ca_.Bind(&block288, &phi_bb288_7, &phi_bb288_8, &phi_bb288_9, &phi_bb288_10, &phi_bb288_11, &phi_bb288_13, &phi_bb288_14, &phi_bb288_20, &phi_bb288_27, &phi_bb288_28, &phi_bb288_32, &phi_bb288_33);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb254_7;
  TNode<IntPtrT> phi_bb254_8;
  TNode<IntPtrT> phi_bb254_9;
  TNode<IntPtrT> phi_bb254_10;
  TNode<IntPtrT> phi_bb254_11;
  TNode<IntPtrT> phi_bb254_13;
  TNode<BoolT> phi_bb254_14;
  TNode<IntPtrT> phi_bb254_20;
  if (block254.is_used()) {
    ca_.Bind(&block254, &phi_bb254_7, &phi_bb254_8, &phi_bb254_9, &phi_bb254_10, &phi_bb254_11, &phi_bb254_13, &phi_bb254_14, &phi_bb254_20);
    ca_.Goto(&block205, phi_bb254_7, phi_bb254_8, phi_bb254_9, phi_bb254_10, phi_bb254_11, phi_bb254_13, phi_bb254_14, phi_bb254_20);
  }

  TNode<IntPtrT> phi_bb205_7;
  TNode<IntPtrT> phi_bb205_8;
  TNode<IntPtrT> phi_bb205_9;
  TNode<IntPtrT> phi_bb205_10;
  TNode<IntPtrT> phi_bb205_11;
  TNode<IntPtrT> phi_bb205_13;
  TNode<BoolT> phi_bb205_14;
  TNode<IntPtrT> phi_bb205_20;
  if (block205.is_used()) {
    ca_.Bind(&block205, &phi_bb205_7, &phi_bb205_8, &phi_bb205_9, &phi_bb205_10, &phi_bb205_11, &phi_bb205_13, &phi_bb205_14, &phi_bb205_20);
    ca_.Goto(&block171, phi_bb205_7, phi_bb205_8, phi_bb205_9, phi_bb205_10, phi_bb205_11, phi_bb205_13, phi_bb205_14, phi_bb205_20);
  }

  TNode<IntPtrT> phi_bb171_7;
  TNode<IntPtrT> phi_bb171_8;
  TNode<IntPtrT> phi_bb171_9;
  TNode<IntPtrT> phi_bb171_10;
  TNode<IntPtrT> phi_bb171_11;
  TNode<IntPtrT> phi_bb171_13;
  TNode<BoolT> phi_bb171_14;
  TNode<IntPtrT> phi_bb171_20;
  if (block171.is_used()) {
    ca_.Bind(&block171, &phi_bb171_7, &phi_bb171_8, &phi_bb171_9, &phi_bb171_10, &phi_bb171_11, &phi_bb171_13, &phi_bb171_14, &phi_bb171_20);
    ca_.Goto(&block148, phi_bb171_7, phi_bb171_8, phi_bb171_9, phi_bb171_10, phi_bb171_11, phi_bb171_13, phi_bb171_14, phi_bb171_20);
  }

  TNode<IntPtrT> phi_bb148_7;
  TNode<IntPtrT> phi_bb148_8;
  TNode<IntPtrT> phi_bb148_9;
  TNode<IntPtrT> phi_bb148_10;
  TNode<IntPtrT> phi_bb148_11;
  TNode<IntPtrT> phi_bb148_13;
  TNode<BoolT> phi_bb148_14;
  TNode<IntPtrT> phi_bb148_20;
  TNode<IntPtrT> tmp618;
  TNode<IntPtrT> tmp619;
  if (block148.is_used()) {
    ca_.Bind(&block148, &phi_bb148_7, &phi_bb148_8, &phi_bb148_9, &phi_bb148_10, &phi_bb148_11, &phi_bb148_13, &phi_bb148_14, &phi_bb148_20);
    tmp618 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp619 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb148_20}, TNode<IntPtrT>{tmp618});
    ca_.Goto(&block143, phi_bb148_7, phi_bb148_8, phi_bb148_9, phi_bb148_10, phi_bb148_11, phi_bb148_13, phi_bb148_14, tmp619);
  }

  TNode<IntPtrT> phi_bb142_7;
  TNode<IntPtrT> phi_bb142_8;
  TNode<IntPtrT> phi_bb142_9;
  TNode<IntPtrT> phi_bb142_10;
  TNode<IntPtrT> phi_bb142_11;
  TNode<IntPtrT> phi_bb142_13;
  TNode<BoolT> phi_bb142_14;
  TNode<IntPtrT> phi_bb142_20;
  if (block142.is_used()) {
    ca_.Bind(&block142, &phi_bb142_7, &phi_bb142_8, &phi_bb142_9, &phi_bb142_10, &phi_bb142_11, &phi_bb142_13, &phi_bb142_14, &phi_bb142_20);
    CodeStubAssembler(state_).Return(parameter1);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=405&c=32
int31_t SizeOf_float64_0(compiler::CodeAssemblerState* state_) {
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
  return kDoubleSize;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=467&c=8
TorqueStructReference_float64_0 RefCast_float64_0(compiler::CodeAssemblerState* state_, TorqueStructReference_intptr_0 p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_float64_0(state_, TNode<Object>{p_i.object}, TNode<IntPtrT>{p_i.offset}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_float64_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=470&c=8
TorqueStructReference_float32_0 RefCast_float32_0(compiler::CodeAssemblerState* state_, TorqueStructReference_intptr_0 p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_float32_0(state_, TNode<Object>{p_i.object}, TNode<IntPtrT>{p_i.offset}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_float32_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=508&c=30
TorqueStructReference_intptr_0 GetRefAt_intptr_RawFunctionSigPtr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_intptr_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_intptr_0{TNode<Object>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=513&c=17
TorqueStructReference_WasmCodePointer_0 GetRefAt_WasmCodePointer_RawFunctionSigPtr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_WasmCodePointer_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_WasmCodePointer_0{TNode<Object>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=612&c=19
TorqueStructReference_intptr_0 NewReference_intptr_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = (TorqueStructReference_intptr_0{TNode<Object>{p_object}, TNode<IntPtrT>{p_offset}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_intptr_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=693&c=7
TNode<WasmSuspenderObject> UnsafeCast_WasmSuspenderObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<WasmSuspenderObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<WasmSuspenderObject>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=734&c=4
TorqueStructReference_int32_0 GetRefAt_int32_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_int32_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_int32_0{TNode<Object>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=735&c=4
TorqueStructReference_bool_0 GetRefAt_bool_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_bool_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_bool_0{TNode<Object>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=736&c=4
TorqueStructReference_WasmCodePointer_0 GetRefAt_WasmCodePointer_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_WasmCodePointer_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_WasmCodePointer_0{TNode<Object>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=737&c=4
TorqueStructReference_intptr_0 GetRefAt_intptr_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_intptr_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_intptr_0{TNode<Object>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=741&c=4
TorqueStructReference_RawPtr_intptr_0 GetRefAt_RawPtr_intptr_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_RawPtr_intptr_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_RawPtr_intptr_0{TNode<Object>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=848&c=22
TorqueStructReference_int32_0 GetRefAt_int32_WasmCodePointer_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_int32_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_int32_0{TNode<Object>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=852&c=37
TorqueStructReference_int64_0 GetRefAt_int64_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_int64_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_int64_0{TNode<Object>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=861&c=58
TorqueStructReference_float64_0 GetRefAt_float64_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_float64_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_float64_0{TNode<Object>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=871&c=13
TorqueStructReference_float32_0 GetRefAt_float32_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_float32_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_float32_0{TNode<Object>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=893&c=23
TorqueStructReference_uintptr_0 GetRefAt_uintptr_RawPtr_uintptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_base, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  TNode<Object> tmp2;
  TNode<IntPtrT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT>{p_base}, TNode<IntPtrT>{p_offset});
    tmp1 = (TNode<RawPtrT>{tmp0});
    std::tie(tmp2, tmp3) = NewOffHeapReference_uintptr_0(state_, TNode<RawPtrT>{tmp1}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_uintptr_0{TNode<Object>{tmp2}, TNode<IntPtrT>{tmp3}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=964&c=37
TorqueStructReference_int64_0 RefCast_int64_0(compiler::CodeAssemblerState* state_, TorqueStructReference_intptr_0 p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_int64_0(state_, TNode<Object>{p_i.object}, TNode<IntPtrT>{p_i.offset}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_int64_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=966&c=16
TorqueStructReference_int32_0 RefCast_int32_0(compiler::CodeAssemblerState* state_, TorqueStructReference_intptr_0 p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = NewReference_int32_0(state_, TNode<Object>{p_i.object}, TNode<IntPtrT>{p_i.offset}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_int32_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=154&c=10
TorqueStructReference_float32_0 NewReference_float32_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = (TorqueStructReference_float32_0{TNode<Object>{p_object}, TNode<IntPtrT>{p_offset}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_float32_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/js-to-wasm.tq?l=154&c=10
TorqueStructReference_int64_0 NewReference_int64_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<IntPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1) = (TorqueStructReference_int64_0{TNode<Object>{p_object}, TNode<IntPtrT>{p_offset}, TorqueStructUnsafe_0{}}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_int64_0{TNode<Object>{tmp0}, TNode<IntPtrT>{tmp1}, TorqueStructUnsafe_0{}};
}

} // namespace internal
} // namespace v8
