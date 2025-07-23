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
#include "torque-generated/src/builtins/array-splice-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-splice-tq-csa.h"
#include "torque-generated/src/builtins/array-to-spliced-tq-csa.h"
#include "torque-generated/src/builtins/array-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=12&c=1
TNode<FixedArray> Extract_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_source, TNode<Smi> p_startIndex, TNode<Smi> p_count, TNode<Smi> p_resultCapacity) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Hole> tmp3;
  TNode<FixedArray> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_startIndex});
    tmp1 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_count});
    tmp2 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_resultCapacity});
    tmp3 = TheHole_0(state_);
    tmp4 = ExtractFixedArray_0(state_, TNode<FixedArray>{p_source}, TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2}, TNode<Hole>{tmp3});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<FixedArray>{tmp4};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=20&c=1
TNode<FixedArrayBase> Extract_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArrayBase> p_source, TNode<Smi> p_startIndex, TNode<Smi> p_count, TNode<Smi> p_resultCapacity) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArrayBase> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<FixedArray> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_EmptyFixedArray_1(state_, TNode<HeapObject>{p_source}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<FixedArrayBase> tmp5;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_startIndex});
    tmp3 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_count});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_resultCapacity});
    tmp5 = ExtractFixedDoubleArray_0(state_, TNode<FixedDoubleArray>{ca_.UncheckedCast<FixedDoubleArray>(p_source)}, TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    ca_.Goto(&block1, tmp5);
  }

  TNode<IntPtrT> tmp6;
  TNode<FixedDoubleArray> tmp7;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp6 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_resultCapacity});
    tmp7 = CodeStubAssembler(state_).AllocateFixedDoubleArrayWithHoles(TNode<IntPtrT>{tmp6});
    ca_.Goto(&block1, tmp7);
  }

  TNode<FixedArrayBase> phi_bb1_5;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_5);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<FixedArrayBase>{phi_bb1_5};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=126&c=1
TNode<Int32T> TransitionElementsKindForInsertionIfNeeded_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArray> p_a, TNode<Int32T> p_originalElementsKind, TorqueStructArguments p_args, IntegerLiteral p_argsStart) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT, Int32T> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_intptr_0(state_, (CodeStubAssembler(state_).ConstexprIntegerLiteralToIntptr(p_argsStart)));
    ca_.Goto(&block8, p_originalElementsKind, tmp0);
  }

  TNode<Int32T> phi_bb8_7;
  TNode<IntPtrT> phi_bb8_8;
  TNode<BoolT> tmp1;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_7, &phi_bb8_8);
    tmp1 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb8_8}, TNode<IntPtrT>{p_args.length});
    ca_.Branch(tmp1, &block6, std::vector<compiler::Node*>{phi_bb8_7, phi_bb8_8}, &block7, std::vector<compiler::Node*>{phi_bb8_7, phi_bb8_8});
  }

  TNode<Int32T> phi_bb6_7;
  TNode<IntPtrT> phi_bb6_8;
  TNode<Object> tmp2;
  TNode<BoolT> tmp3;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_7, &phi_bb6_8);
    tmp2 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{p_args.frame}, TNode<RawPtrT>{p_args.base}, TNode<IntPtrT>{p_args.length}, TNode<IntPtrT>{p_args.actual_count}}, TNode<IntPtrT>{phi_bb6_8});
    tmp3 = CodeStubAssembler(state_).IsFastSmiElementsKind(TNode<Int32T>{phi_bb6_7});
    ca_.Branch(tmp3, &block10, std::vector<compiler::Node*>{phi_bb6_7, phi_bb6_8}, &block11, std::vector<compiler::Node*>{phi_bb6_7, phi_bb6_8});
  }

  TNode<Int32T> phi_bb10_7;
  TNode<IntPtrT> phi_bb10_8;
  TNode<BoolT> tmp4;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_7, &phi_bb10_8);
    tmp4 = CodeStubAssembler(state_).TaggedIsNotSmi(TNode<Object>{tmp2});
    ca_.Branch(tmp4, &block13, std::vector<compiler::Node*>{phi_bb10_7, phi_bb10_8}, &block14, std::vector<compiler::Node*>{phi_bb10_7, phi_bb10_8});
  }

  TNode<Int32T> phi_bb13_7;
  TNode<IntPtrT> phi_bb13_8;
  TNode<HeapObject> tmp5;
  TNode<BoolT> tmp6;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_7, &phi_bb13_8);
    tmp5 = UnsafeCast_HeapObject_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp2});
    tmp6 = IsHeapNumber_0(state_, TNode<HeapObject>{tmp5});
    ca_.Branch(tmp6, &block15, std::vector<compiler::Node*>{phi_bb13_7, phi_bb13_8}, &block16, std::vector<compiler::Node*>{phi_bb13_7, phi_bb13_8});
  }

  TNode<Int32T> phi_bb15_7;
  TNode<IntPtrT> phi_bb15_8;
  TNode<Int32T> tmp7;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_7, &phi_bb15_8);
    tmp7 = AllowDoubleElements_0(state_, TNode<Int32T>{phi_bb15_7});
    ca_.Goto(&block17, phi_bb15_7, phi_bb15_8, tmp7);
  }

  TNode<Int32T> phi_bb16_7;
  TNode<IntPtrT> phi_bb16_8;
  TNode<Int32T> tmp8;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_7, &phi_bb16_8);
    tmp8 = AllowNonNumberElements_0(state_, TNode<Int32T>{phi_bb16_7});
    ca_.Goto(&block17, phi_bb16_7, phi_bb16_8, tmp8);
  }

  TNode<Int32T> phi_bb17_7;
  TNode<IntPtrT> phi_bb17_8;
  TNode<Int32T> phi_bb17_11;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_7, &phi_bb17_8, &phi_bb17_11);
    ca_.Goto(&block14, phi_bb17_11, phi_bb17_8);
  }

  TNode<Int32T> phi_bb14_7;
  TNode<IntPtrT> phi_bb14_8;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_7, &phi_bb14_8);
    ca_.Goto(&block12, phi_bb14_7, phi_bb14_8);
  }

  TNode<Int32T> phi_bb11_7;
  TNode<IntPtrT> phi_bb11_8;
  TNode<BoolT> tmp9;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_7, &phi_bb11_8);
    tmp9 = CodeStubAssembler(state_).IsDoubleElementsKind(TNode<Int32T>{phi_bb11_7});
    ca_.Branch(tmp9, &block19, std::vector<compiler::Node*>{phi_bb11_7, phi_bb11_8}, &block20, std::vector<compiler::Node*>{phi_bb11_7, phi_bb11_8});
  }

  TNode<Int32T> phi_bb19_7;
  TNode<IntPtrT> phi_bb19_8;
  TNode<BoolT> tmp10;
  TNode<BoolT> tmp11;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_7, &phi_bb19_8);
    tmp10 = IsNumber_0(state_, TNode<Object>{tmp2});
    tmp11 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp10});
    ca_.Branch(tmp11, &block22, std::vector<compiler::Node*>{phi_bb19_7, phi_bb19_8}, &block23, std::vector<compiler::Node*>{phi_bb19_7, phi_bb19_8});
  }

  TNode<Int32T> phi_bb22_7;
  TNode<IntPtrT> phi_bb22_8;
  TNode<Int32T> tmp12;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_7, &phi_bb22_8);
    tmp12 = AllowNonNumberElements_0(state_, TNode<Int32T>{phi_bb22_7});
    ca_.Goto(&block23, tmp12, phi_bb22_8);
  }

  TNode<Int32T> phi_bb23_7;
  TNode<IntPtrT> phi_bb23_8;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_7, &phi_bb23_8);
    ca_.Goto(&block12, phi_bb23_7, phi_bb23_8);
  }

  TNode<Int32T> phi_bb20_7;
  TNode<IntPtrT> phi_bb20_8;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_7, &phi_bb20_8);
    ca_.Goto(&block7, phi_bb20_7, phi_bb20_8);
  }

  TNode<Int32T> phi_bb12_7;
  TNode<IntPtrT> phi_bb12_8;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_7, &phi_bb12_8);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp14 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb12_8}, TNode<IntPtrT>{tmp13});
    ca_.Goto(&block8, phi_bb12_7, tmp14);
  }

  TNode<Int32T> phi_bb7_7;
  TNode<IntPtrT> phi_bb7_8;
  TNode<BoolT> tmp15;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_7, &phi_bb7_8);
    tmp15 = ElementsKindNotEqual_0(state_, TNode<Int32T>{phi_bb7_7}, TNode<Int32T>{p_originalElementsKind});
    ca_.Branch(tmp15, &block24, std::vector<compiler::Node*>{phi_bb7_7}, &block25, std::vector<compiler::Node*>{phi_bb7_7});
  }

  TNode<Int32T> phi_bb24_7;
  TNode<Int32T> tmp16;
  TNode<Smi> tmp17;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_7);
    tmp16 = Convert_int32_ElementsKind_0(state_, TNode<Int32T>{phi_bb24_7});
    tmp17 = Convert_Smi_int32_0(state_, TNode<Int32T>{tmp16});
    CodeStubAssembler(state_).CallRuntime(Runtime::kTransitionElementsKindWithKind, p_context, p_a, tmp17);
    ca_.Goto(&block25, phi_bb24_7);
  }

  TNode<Int32T> phi_bb25_7;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_7);
    ca_.Goto(&block26, phi_bb25_7);
  }

  TNode<Int32T> phi_bb26_7;
    ca_.Bind(&block26, &phi_bb26_7);
  return TNode<Int32T>{phi_bb26_7};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=160&c=1
TNode<Object> FastArraySplice_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructArguments p_args, TNode<JSReceiver> p_o, TNode<Number> p_originalLengthNumber, TNode<Number> p_actualStartNumber, TNode<Smi> p_insertCount, TNode<Number> p_actualDeleteCountNumber, compiler::CodeAssemblerLabel* label_Bailout) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Smi_0(state_, TNode<Object>{p_originalLengthNumber}, &label1);
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

  TNode<Smi> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Smi_0(state_, TNode<Object>{p_actualStartNumber}, &label3);
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

  TNode<Smi> tmp4;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = Cast_Smi_0(state_, TNode<Object>{p_actualDeleteCountNumber}, &label5);
    ca_.Goto(&block7);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block1);
  }

  TNode<Smi> tmp6;
  TNode<Smi> tmp7;
  TNode<JSArray> tmp8;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp6 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{p_insertCount}, TNode<Smi>{tmp4});
    tmp7 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp0}, TNode<Smi>{tmp6});
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = Cast_JSArray_0(state_, TNode<HeapObject>{p_o}, &label9);
    ca_.Goto(&block9);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block10);
    }
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block1);
  }

  TNode<IntPtrT> tmp10;
  TNode<Map> tmp11;
  TNode<BoolT> tmp12;
  TNode<BoolT> tmp13;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp11 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp8, tmp10});
    tmp12 = CodeStubAssembler(state_).IsPrototypeInitialArrayPrototype(TNode<Context>{p_context}, TNode<Map>{tmp11});
    tmp13 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp12});
    ca_.Branch(tmp13, &block11, std::vector<compiler::Node*>{}, &block12, std::vector<compiler::Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block1);
  }

  TNode<BoolT> tmp14;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp14 = CodeStubAssembler(state_).IsNoElementsProtectorCellInvalid();
    ca_.Branch(tmp14, &block13, std::vector<compiler::Node*>{}, &block14, std::vector<compiler::Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block1);
  }

  TNode<BoolT> tmp15;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp15 = CodeStubAssembler(state_).IsArraySpeciesProtectorCellInvalid();
    ca_.Branch(tmp15, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.Goto(&block1);
  }

  TNode<Int32T> tmp16;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    compiler::CodeAssemblerLabel label17(&ca_);
    tmp16 = CodeStubAssembler(state_).EnsureArrayPushable(TNode<Context>{p_context}, TNode<Map>{tmp11}, &label17);
    ca_.Goto(&block17);
    if (label17.is_used()) {
      ca_.Bind(&label17);
      ca_.Goto(&block18);
    }
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    ca_.Goto(&block1);
  }

  TNode<BoolT> tmp18;
  TNode<BoolT> tmp19;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp18 = CodeStubAssembler(state_).IsFastElementsKind(TNode<Int32T>{tmp16});
    tmp19 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp18});
    ca_.Branch(tmp19, &block19, std::vector<compiler::Node*>{}, &block20, std::vector<compiler::Node*>{});
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    ca_.Goto(&block1);
  }

  TNode<Int32T> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Number> tmp22;
  TNode<Smi> tmp23;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp20 = TransitionElementsKindForInsertionIfNeeded_0(state_, TNode<Context>{p_context}, TNode<JSArray>{tmp8}, TNode<Int32T>{tmp16}, TorqueStructArguments{TNode<RawPtrT>{p_args.frame}, TNode<RawPtrT>{p_args.base}, TNode<IntPtrT>{p_args.length}, TNode<IntPtrT>{p_args.actual_count}}, IntegerLiteral(false, 0x2ull));
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp22 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp8, tmp21});
    compiler::CodeAssemblerLabel label24(&ca_);
    tmp23 = Cast_Smi_0(state_, TNode<Object>{tmp22}, &label24);
    ca_.Goto(&block21);
    if (label24.is_used()) {
      ca_.Bind(&label24);
      ca_.Goto(&block22);
    }
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.Goto(&block1);
  }

  TNode<BoolT> tmp25;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp25 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi>{tmp0}, TNode<Smi>{tmp23});
    ca_.Branch(tmp25, &block23, std::vector<compiler::Node*>{}, &block24, std::vector<compiler::Node*>{});
  }

  if (block23.is_used()) {
    ca_.Bind(&block23);
    ca_.Goto(&block1);
  }

  TNode<JSArray> tmp26;
  TNode<Smi> tmp27;
  TNode<BoolT> tmp28;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    tmp26 = ca_.CallBuiltin<JSArray>(Builtin::kExtractFastJSArray, p_context, tmp8, tmp2, tmp4);
    tmp27 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp28 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp7}, TNode<Smi>{tmp27});
    ca_.Branch(tmp28, &block25, std::vector<compiler::Node*>{}, &block26, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp29;
  TNode<FixedArray> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<Number> tmp32;
  if (block25.is_used()) {
    ca_.Bind(&block25);
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp30 = kEmptyFixedArray_0(state_);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp8, tmp29}, tmp30);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp32 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp8, tmp31}, tmp32);
    ca_.Goto(&block2);
  }

  TNode<BoolT> tmp33;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    tmp33 = CodeStubAssembler(state_).IsFastSmiOrTaggedElementsKind(TNode<Int32T>{tmp20});
    ca_.Branch(tmp33, &block27, std::vector<compiler::Node*>{}, &block28, std::vector<compiler::Node*>{});
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    FastSplice_FixedArray_JSAny_0(state_, TNode<Context>{p_context}, TorqueStructArguments{TNode<RawPtrT>{p_args.frame}, TNode<RawPtrT>{p_args.base}, TNode<IntPtrT>{p_args.length}, TNode<IntPtrT>{p_args.actual_count}}, TNode<JSArray>{tmp8}, TNode<Smi>{tmp23}, TNode<Smi>{tmp7}, TNode<Smi>{tmp2}, TNode<Smi>{p_insertCount}, TNode<Smi>{tmp4});
    ca_.Goto(&block29);
  }

  if (block28.is_used()) {
    ca_.Bind(&block28);
    FastSplice_FixedDoubleArray_Number_0(state_, TNode<Context>{p_context}, TorqueStructArguments{TNode<RawPtrT>{p_args.frame}, TNode<RawPtrT>{p_args.base}, TNode<IntPtrT>{p_args.length}, TNode<IntPtrT>{p_args.actual_count}}, TNode<JSArray>{tmp8}, TNode<Smi>{tmp23}, TNode<Smi>{tmp7}, TNode<Smi>{tmp2}, TNode<Smi>{p_insertCount}, TNode<Smi>{tmp4});
    ca_.Goto(&block29);
  }

  if (block29.is_used()) {
    ca_.Bind(&block29);
    ca_.Goto(&block2);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block30);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_Bailout);
  }

    ca_.Bind(&block30);
  return TNode<Object>{tmp26};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=212&c=1
TNode<Object> FillDeletedElementsArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Number> p_actualStart, TNode<Number> p_actualDeleteCount, TNode<JSReceiver> p_a) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block4, tmp0);
  }

  TNode<Number> phi_bb4_5;
  TNode<BoolT> tmp1;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5);
    tmp1 = NumberIsLessThan_0(state_, TNode<Number>{phi_bb4_5}, TNode<Number>{p_actualDeleteCount});
    ca_.Branch(tmp1, &block2, std::vector<compiler::Node*>{phi_bb4_5}, &block3, std::vector<compiler::Node*>{phi_bb4_5});
  }

  TNode<Number> phi_bb2_5;
  TNode<Number> tmp2;
  TNode<Boolean> tmp3;
  TNode<True> tmp4;
  TNode<BoolT> tmp5;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_5);
    tmp2 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{p_actualStart}, TNode<Number>{phi_bb2_5});
    tmp3 = ca_.CallBuiltin<Boolean>(Builtin::kHasProperty, p_context, p_o, tmp2);
    tmp4 = True_0(state_);
    tmp5 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp3}, TNode<HeapObject>{tmp4});
    ca_.Branch(tmp5, &block5, std::vector<compiler::Node*>{phi_bb2_5}, &block6, std::vector<compiler::Node*>{phi_bb2_5});
  }

  TNode<Number> phi_bb5_5;
  TNode<Object> tmp6;
  TNode<Object> tmp7;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5);
    tmp6 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_o}, TNode<Object>{tmp2});
    tmp7 = ca_.CallBuiltin<Object>(Builtin::kFastCreateDataProperty, p_context, p_a, phi_bb5_5, tmp6);
    ca_.Goto(&block6, phi_bb5_5);
  }

  TNode<Number> phi_bb6_5;
  TNode<Number> tmp8;
  TNode<Number> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_5);
    tmp8 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    tmp9 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb6_5}, TNode<Number>{tmp8});
    ca_.Goto(&block4, tmp9);
  }

  TNode<Number> phi_bb3_5;
  TNode<String> tmp10;
  TNode<Object> tmp11;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5);
    tmp10 = kLengthString_0(state_);
    tmp11 = ca_.CallBuiltin<Object>(Builtin::kSetProperty, p_context, p_a, tmp10, p_actualDeleteCount);
    ca_.Goto(&block7);
  }

    ca_.Bind(&block7);
  return TNode<Object>{p_a};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=245&c=1
void HandleForwardCase_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<Number> p_itemCount, TNode<Number> p_actualStart, TNode<Number> p_actualDeleteCount) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block4, p_actualStart);
  }

  TNode<Number> phi_bb4_6;
  TNode<Number> tmp0;
  TNode<BoolT> tmp1;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_6);
    tmp0 = CodeStubAssembler(state_).NumberSub(TNode<Number>{p_len}, TNode<Number>{p_actualDeleteCount});
    tmp1 = NumberIsLessThan_0(state_, TNode<Number>{phi_bb4_6}, TNode<Number>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<compiler::Node*>{phi_bb4_6}, &block3, std::vector<compiler::Node*>{phi_bb4_6});
  }

  TNode<Number> phi_bb2_6;
  TNode<Number> tmp2;
  TNode<Number> tmp3;
  TNode<Boolean> tmp4;
  TNode<True> tmp5;
  TNode<BoolT> tmp6;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_6);
    tmp2 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb2_6}, TNode<Number>{p_actualDeleteCount});
    tmp3 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb2_6}, TNode<Number>{p_itemCount});
    tmp4 = ca_.CallBuiltin<Boolean>(Builtin::kHasProperty, p_context, p_o, tmp2);
    tmp5 = True_0(state_);
    tmp6 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp4}, TNode<HeapObject>{tmp5});
    ca_.Branch(tmp6, &block5, std::vector<compiler::Node*>{phi_bb2_6}, &block6, std::vector<compiler::Node*>{phi_bb2_6});
  }

  TNode<Number> phi_bb5_6;
  TNode<Object> tmp7;
  TNode<Object> tmp8;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_6);
    tmp7 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_o}, TNode<Object>{tmp2});
    tmp8 = ca_.CallBuiltin<Object>(Builtin::kSetProperty, p_context, p_o, tmp3, tmp7);
    ca_.Goto(&block7, phi_bb5_6);
  }

  TNode<Number> phi_bb6_6;
  TNode<Smi> tmp9;
  TNode<Boolean> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_6);
    tmp9 = FromConstexpr_LanguageModeSmi_constexpr_LanguageMode_0(state_, LanguageMode::kStrict);
    tmp10 = ca_.CallBuiltin<Boolean>(Builtin::kDeleteProperty, p_context, p_o, tmp3, tmp9);
    ca_.Goto(&block7, phi_bb6_6);
  }

  TNode<Number> phi_bb7_6;
  TNode<Number> tmp11;
  TNode<Number> tmp12;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_6);
    tmp11 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    tmp12 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb7_6}, TNode<Number>{tmp11});
    ca_.Goto(&block4, tmp12);
  }

  TNode<Number> phi_bb3_6;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_6);
    ca_.Goto(&block10, p_len);
  }

  TNode<Number> phi_bb10_6;
  TNode<Number> tmp13;
  TNode<Number> tmp14;
  TNode<BoolT> tmp15;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_6);
    tmp13 = CodeStubAssembler(state_).NumberSub(TNode<Number>{p_len}, TNode<Number>{p_actualDeleteCount});
    tmp14 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp13}, TNode<Number>{p_itemCount});
    tmp15 = NumberIsGreaterThan_0(state_, TNode<Number>{phi_bb10_6}, TNode<Number>{tmp14});
    ca_.Branch(tmp15, &block8, std::vector<compiler::Node*>{phi_bb10_6}, &block9, std::vector<compiler::Node*>{phi_bb10_6});
  }

  TNode<Number> phi_bb8_6;
  TNode<Number> tmp16;
  TNode<Number> tmp17;
  TNode<Smi> tmp18;
  TNode<Boolean> tmp19;
  TNode<Number> tmp20;
  TNode<Number> tmp21;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_6);
    tmp16 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp17 = CodeStubAssembler(state_).NumberSub(TNode<Number>{phi_bb8_6}, TNode<Number>{tmp16});
    tmp18 = FromConstexpr_LanguageModeSmi_constexpr_LanguageMode_0(state_, LanguageMode::kStrict);
    tmp19 = ca_.CallBuiltin<Boolean>(Builtin::kDeleteProperty, p_context, p_o, tmp17, tmp18);
    tmp20 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    tmp21 = CodeStubAssembler(state_).NumberSub(TNode<Number>{phi_bb8_6}, TNode<Number>{tmp20});
    ca_.Goto(&block10, tmp21);
  }

  TNode<Number> phi_bb9_6;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_6);
    ca_.Goto(&block11);
  }

    ca_.Bind(&block11);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=293&c=1
void HandleBackwardCase_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<Number> p_itemCount, TNode<Number> p_actualStart, TNode<Number> p_actualDeleteCount) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Number> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).NumberSub(TNode<Number>{p_len}, TNode<Number>{p_actualDeleteCount});
    ca_.Goto(&block4, tmp0);
  }

  TNode<Number> phi_bb4_6;
  TNode<BoolT> tmp1;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_6);
    tmp1 = NumberIsGreaterThan_0(state_, TNode<Number>{phi_bb4_6}, TNode<Number>{p_actualStart});
    ca_.Branch(tmp1, &block2, std::vector<compiler::Node*>{phi_bb4_6}, &block3, std::vector<compiler::Node*>{phi_bb4_6});
  }

  TNode<Number> phi_bb2_6;
  TNode<Number> tmp2;
  TNode<Number> tmp3;
  TNode<Number> tmp4;
  TNode<Number> tmp5;
  TNode<Number> tmp6;
  TNode<Number> tmp7;
  TNode<Boolean> tmp8;
  TNode<True> tmp9;
  TNode<BoolT> tmp10;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_6);
    tmp2 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb2_6}, TNode<Number>{p_actualDeleteCount});
    tmp3 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp4 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp2}, TNode<Number>{tmp3});
    tmp5 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb2_6}, TNode<Number>{p_itemCount});
    tmp6 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp7 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp5}, TNode<Number>{tmp6});
    tmp8 = ca_.CallBuiltin<Boolean>(Builtin::kHasProperty, p_context, p_o, tmp4);
    tmp9 = True_0(state_);
    tmp10 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp8}, TNode<HeapObject>{tmp9});
    ca_.Branch(tmp10, &block5, std::vector<compiler::Node*>{phi_bb2_6}, &block6, std::vector<compiler::Node*>{phi_bb2_6});
  }

  TNode<Number> phi_bb5_6;
  TNode<Object> tmp11;
  TNode<Object> tmp12;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_6);
    tmp11 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_o}, TNode<Object>{tmp4});
    tmp12 = ca_.CallBuiltin<Object>(Builtin::kSetProperty, p_context, p_o, tmp7, tmp11);
    ca_.Goto(&block7, phi_bb5_6);
  }

  TNode<Number> phi_bb6_6;
  TNode<Smi> tmp13;
  TNode<Boolean> tmp14;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_6);
    tmp13 = FromConstexpr_LanguageModeSmi_constexpr_LanguageMode_0(state_, LanguageMode::kStrict);
    tmp14 = ca_.CallBuiltin<Boolean>(Builtin::kDeleteProperty, p_context, p_o, tmp7, tmp13);
    ca_.Goto(&block7, phi_bb6_6);
  }

  TNode<Number> phi_bb7_6;
  TNode<Number> tmp15;
  TNode<Number> tmp16;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_6);
    tmp15 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    tmp16 = CodeStubAssembler(state_).NumberSub(TNode<Number>{phi_bb7_6}, TNode<Number>{tmp15});
    ca_.Goto(&block4, tmp16);
  }

  TNode<Number> phi_bb3_6;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_6);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=330&c=1
TNode<Object> SlowSplice_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructArguments p_arguments, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<Number> p_actualStart, TNode<Smi> p_insertCount, TNode<Number> p_actualDeleteCount) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  TNode<Object> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).ArraySpeciesCreate(TNode<Context>{p_context}, TNode<Object>{p_o}, TNode<Number>{p_actualDeleteCount});
    tmp1 = FillDeletedElementsArray_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_o}, TNode<Number>{p_actualStart}, TNode<Number>{p_actualDeleteCount}, TNode<JSReceiver>{tmp0});
    tmp2 = NumberIsLessThan_0(state_, TNode<Number>{p_insertCount}, TNode<Number>{p_actualDeleteCount});
    ca_.Branch(tmp2, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    HandleForwardCase_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_o}, TNode<Number>{p_len}, TNode<Number>{p_insertCount}, TNode<Number>{p_actualStart}, TNode<Number>{p_actualDeleteCount});
    ca_.Goto(&block4);
  }

  TNode<BoolT> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp3 = NumberIsGreaterThan_0(state_, TNode<Number>{p_insertCount}, TNode<Number>{p_actualDeleteCount});
    ca_.Branch(tmp3, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    HandleBackwardCase_0(state_, TNode<Context>{p_context}, TNode<JSReceiver>{p_o}, TNode<Number>{p_len}, TNode<Number>{p_insertCount}, TNode<Number>{p_actualStart}, TNode<Number>{p_actualDeleteCount});
    ca_.Goto(&block6);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block4);
  }

  TNode<IntPtrT> tmp4;
  TNode<BoolT> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp4 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp5 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{p_arguments.length}, TNode<IntPtrT>{tmp4});
    ca_.Branch(tmp5, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{p_actualStart});
  }

  TNode<IntPtrT> tmp6;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp6 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    ca_.Goto(&block11, p_actualStart, tmp6);
  }

  TNode<Number> phi_bb11_12;
  TNode<IntPtrT> phi_bb11_13;
  TNode<BoolT> tmp7;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_12, &phi_bb11_13);
    tmp7 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb11_13}, TNode<IntPtrT>{p_arguments.length});
    ca_.Branch(tmp7, &block9, std::vector<compiler::Node*>{phi_bb11_12, phi_bb11_13}, &block10, std::vector<compiler::Node*>{phi_bb11_12, phi_bb11_13});
  }

  TNode<Number> phi_bb9_12;
  TNode<IntPtrT> phi_bb9_13;
  TNode<Object> tmp8;
  TNode<Object> tmp9;
  TNode<Number> tmp10;
  TNode<Number> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_12, &phi_bb9_13);
    tmp8 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{p_arguments.frame}, TNode<RawPtrT>{p_arguments.base}, TNode<IntPtrT>{p_arguments.length}, TNode<IntPtrT>{p_arguments.actual_count}}, TNode<IntPtrT>{phi_bb9_13});
    tmp9 = ca_.CallBuiltin<Object>(Builtin::kSetProperty, p_context, p_o, phi_bb9_12, tmp8);
    tmp10 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp11 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{phi_bb9_12}, TNode<Number>{tmp10});
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp13 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb9_13}, TNode<IntPtrT>{tmp12});
    ca_.Goto(&block11, tmp11, tmp13);
  }

  TNode<Number> phi_bb10_12;
  TNode<IntPtrT> phi_bb10_13;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_12, &phi_bb10_13);
    ca_.Goto(&block8, phi_bb10_12);
  }

  TNode<Number> phi_bb8_12;
  TNode<String> tmp14;
  TNode<Number> tmp15;
  TNode<Number> tmp16;
  TNode<Object> tmp17;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_12);
    tmp14 = kLengthString_0(state_);
    tmp15 = CodeStubAssembler(state_).NumberSub(TNode<Number>{p_len}, TNode<Number>{p_actualDeleteCount});
    tmp16 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp15}, TNode<Number>{p_insertCount});
    tmp17 = ca_.CallBuiltin<Object>(Builtin::kSetProperty, p_context, p_o, tmp14, tmp16);
    ca_.Goto(&block13);
  }

    ca_.Bind(&block13);
  return TNode<Object>{tmp0};
}

TF_BUILTIN(ArrayPrototypeSplice, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number, Smi, Number> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number, Smi, Number> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  TNode<Number> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Object> tmp3;
  TNode<Number> tmp4;
  TNode<Number> tmp5;
  TNode<BoolT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.CallBuiltin<JSReceiver>(Builtin::kToObject, parameter0, parameter1);
    tmp1 = GetLengthProperty_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp0});
    tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp3 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp2});
    tmp4 = ToInteger_Inline_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp3});
    tmp5 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp6 = NumberIsLessThan_0(state_, TNode<Number>{tmp4}, TNode<Number>{tmp5});
    ca_.Branch(tmp6, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Number> tmp7;
  TNode<Number> tmp8;
  TNode<Number> tmp9;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp7 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp1}, TNode<Number>{tmp4});
    tmp8 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp9 = Max_0(state_, TNode<Number>{tmp7}, TNode<Number>{tmp8});
    ca_.Goto(&block3, tmp9);
  }

  TNode<Number> tmp10;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp10 = Min_0(state_, TNode<Number>{tmp4}, TNode<Number>{tmp1});
    ca_.Goto(&block3, tmp10);
  }

  TNode<Number> phi_bb3_10;
  TNode<IntPtrT> tmp11;
  TNode<BoolT> tmp12;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_10);
    tmp11 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp12 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{tmp11});
    ca_.Branch(tmp12, &block5, std::vector<compiler::Node*>{}, &block6, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp13;
  TNode<Number> tmp14;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp13 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp14 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    ca_.Goto(&block7, tmp13, tmp14);
  }

  TNode<IntPtrT> tmp15;
  TNode<BoolT> tmp16;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp15 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp16 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{tmp15});
    ca_.Branch(tmp16, &block8, std::vector<compiler::Node*>{}, &block9, std::vector<compiler::Node*>{});
  }

  TNode<Smi> tmp17;
  TNode<Number> tmp18;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp17 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp18 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp1}, TNode<Number>{phi_bb3_10});
    ca_.Goto(&block10, tmp17, tmp18);
  }

  TNode<Smi> tmp19;
  TNode<Smi> tmp20;
  TNode<Smi> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<Object> tmp23;
  TNode<Number> tmp24;
  TNode<Number> tmp25;
  TNode<Number> tmp26;
  TNode<Number> tmp27;
  TNode<Number> tmp28;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp19 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{torque_arguments.length});
    tmp20 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
    tmp21 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp19}, TNode<Smi>{tmp20});
    tmp22 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp23 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<IntPtrT>{tmp22});
    tmp24 = ToInteger_Inline_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp23});
    tmp25 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp26 = Max_0(state_, TNode<Number>{tmp24}, TNode<Number>{tmp25});
    tmp27 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp1}, TNode<Number>{phi_bb3_10});
    tmp28 = Min_0(state_, TNode<Number>{tmp26}, TNode<Number>{tmp27});
    ca_.Goto(&block10, tmp21, tmp28);
  }

  TNode<Smi> phi_bb10_11;
  TNode<Number> phi_bb10_12;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_11, &phi_bb10_12);
    ca_.Goto(&block7, phi_bb10_11, phi_bb10_12);
  }

  TNode<Smi> phi_bb7_11;
  TNode<Number> phi_bb7_12;
  TNode<Number> tmp29;
  TNode<Number> tmp30;
  TNode<Number> tmp31;
  TNode<BoolT> tmp32;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_11, &phi_bb7_12);
    tmp29 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp1}, TNode<Number>{phi_bb7_11});
    tmp30 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp29}, TNode<Number>{phi_bb7_12});
    tmp31 = FromConstexpr_Number_constexpr_float64_0(state_, kMaxSafeInteger);
    tmp32 = NumberIsGreaterThan_0(state_, TNode<Number>{tmp30}, TNode<Number>{tmp31});
    ca_.Branch(tmp32, &block11, std::vector<compiler::Node*>{phi_bb7_11, phi_bb7_12}, &block12, std::vector<compiler::Node*>{phi_bb7_11, phi_bb7_12});
  }

  TNode<Smi> phi_bb11_11;
  TNode<Number> phi_bb11_12;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_11, &phi_bb11_12);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kInvalidArrayLength, TNode<Object>{tmp30});
  }

  TNode<Smi> phi_bb12_11;
  TNode<Number> phi_bb12_12;
  TNode<Object> tmp33;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_11, &phi_bb12_12);
    compiler::CodeAssemblerLabel label34(&ca_);
    tmp33 = FastArraySplice_0(state_, TNode<Context>{parameter0}, TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<JSReceiver>{tmp0}, TNode<Number>{tmp1}, TNode<Number>{phi_bb3_10}, TNode<Smi>{phi_bb12_11}, TNode<Number>{phi_bb12_12}, &label34);
    ca_.Goto(&block15, phi_bb12_11, phi_bb12_12, phi_bb12_11, phi_bb12_12);
    if (label34.is_used()) {
      ca_.Bind(&label34);
      ca_.Goto(&block16, phi_bb12_11, phi_bb12_12, phi_bb12_11, phi_bb12_12);
    }
  }

  TNode<Smi> phi_bb16_11;
  TNode<Number> phi_bb16_12;
  TNode<Smi> phi_bb16_22;
  TNode<Number> phi_bb16_23;
  TNode<Object> tmp35;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_11, &phi_bb16_12, &phi_bb16_22, &phi_bb16_23);
    tmp35 = SlowSplice_0(state_, TNode<Context>{parameter0}, TorqueStructArguments{TNode<RawPtrT>{torque_arguments.frame}, TNode<RawPtrT>{torque_arguments.base}, TNode<IntPtrT>{torque_arguments.length}, TNode<IntPtrT>{torque_arguments.actual_count}}, TNode<JSReceiver>{tmp0}, TNode<Number>{tmp1}, TNode<Number>{phi_bb3_10}, TNode<Smi>{phi_bb16_11}, TNode<Number>{phi_bb16_12});
    arguments.PopAndReturn(tmp35);
  }

  TNode<Smi> phi_bb15_11;
  TNode<Number> phi_bb15_12;
  TNode<Smi> phi_bb15_22;
  TNode<Number> phi_bb15_23;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_11, &phi_bb15_12, &phi_bb15_22, &phi_bb15_23);
    arguments.PopAndReturn(tmp33);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=137&c=40
TNode<HeapObject> UnsafeCast_HeapObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<HeapObject>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=153&c=47
TNode<Int32T> Convert_int32_ElementsKind_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_i) {
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
  return TNode<Int32T>{p_i};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=200&c=5
void FastSplice_FixedArray_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructArguments p_args, TNode<JSArray> p_a, TNode<Smi> p_length, TNode<Smi> p_newLength, TNode<Smi> p_actualStart, TNode<Smi> p_insertCount, TNode<Smi> p_actualDeleteCount) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    EnsureWriteableFastElements_0(state_, TNode<Context>{p_context}, TNode<JSArray>{p_a});
    tmp0 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi>{p_insertCount}, TNode<Smi>{p_actualDeleteCount});
    ca_.Branch(tmp0, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp1;
  TNode<FixedArrayBase> tmp2;
  TNode<FixedArray> tmp3;
  TNode<Smi> tmp4;
  TNode<Smi> tmp5;
  TNode<Smi> tmp6;
  TNode<Smi> tmp7;
  TNode<BoolT> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp2 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{p_a, tmp1});
    tmp3 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp2});
    tmp4 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{p_actualStart}, TNode<Smi>{p_insertCount});
    tmp5 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{p_actualStart}, TNode<Smi>{p_actualDeleteCount});
    tmp6 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{p_length}, TNode<Smi>{p_actualDeleteCount});
    tmp7 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp6}, TNode<Smi>{p_actualStart});
    tmp8 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{p_insertCount}, TNode<Smi>{p_actualDeleteCount});
    ca_.Branch(tmp8, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  TNode<FixedArray> tmp9;
  TNode<FixedArray> tmp10;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp9 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp3});
    DoMoveElements_FixedArray_0(state_, TNode<FixedArray>{tmp9}, TNode<Smi>{tmp4}, TNode<Smi>{tmp5}, TNode<Smi>{tmp7});
    tmp10 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp3});
    StoreHoles_FixedArray_0(state_, TNode<FixedArray>{tmp10}, TNode<Smi>{p_newLength}, TNode<Smi>{p_length});
    ca_.Goto(&block6);
  }

  TNode<BoolT> tmp11;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp11 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{p_insertCount}, TNode<Smi>{p_actualDeleteCount});
    ca_.Branch(tmp11, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp12;
  TNode<Smi> tmp13;
  TNode<BoolT> tmp14;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp13 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp3, tmp12});
    tmp14 = CodeStubAssembler(state_).SmiLessThanOrEqual(TNode<Smi>{p_newLength}, TNode<Smi>{tmp13});
    ca_.Branch(tmp14, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<FixedArray> tmp15;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp15 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp3});
    DoMoveElements_FixedArray_0(state_, TNode<FixedArray>{tmp15}, TNode<Smi>{tmp4}, TNode<Smi>{tmp5}, TNode<Smi>{tmp7});
    ca_.Goto(&block11);
  }

  TNode<Smi> tmp16;
  TNode<Smi> tmp17;
  TNode<FixedArray> tmp18;
  TNode<FixedArray> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Smi> tmp22;
  TNode<Smi> tmp23;
  TNode<BoolT> tmp24;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp16 = CodeStubAssembler(state_).CalculateNewElementsCapacity(TNode<Smi>{p_newLength});
    tmp17 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp18 = Extract_0(state_, TNode<Context>{p_context}, TNode<FixedArray>{tmp3}, TNode<Smi>{tmp17}, TNode<Smi>{p_actualStart}, TNode<Smi>{tmp16});
    tmp19 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp18});
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{p_a, tmp20}, tmp19);
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp22 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp3, tmp21});
    tmp23 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp24 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp22}, TNode<Smi>{tmp23});
    ca_.Branch(tmp24, &block12, std::vector<compiler::Node*>{}, &block13, std::vector<compiler::Node*>{});
  }

  TNode<FixedArray> tmp25;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp25 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp3});
    DoCopyElements_FixedArray_0(state_, TNode<FixedArray>{tmp19}, TNode<Smi>{tmp4}, TNode<FixedArray>{tmp25}, TNode<Smi>{tmp5}, TNode<Smi>{tmp7});
    ca_.Goto(&block13);
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block11);
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block8);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block6);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block3);
  }

  TNode<IntPtrT> tmp26;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    InsertArgumentsIntoFastPackedArray_FixedArray_JSAny_0(state_, TNode<JSArray>{p_a}, TNode<Smi>{p_actualStart}, TorqueStructArguments{TNode<RawPtrT>{p_args.frame}, TNode<RawPtrT>{p_args.base}, TNode<IntPtrT>{p_args.length}, TNode<IntPtrT>{p_args.actual_count}}, IntegerLiteral(false, 0x2ull), TNode<Smi>{p_insertCount});
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{p_a, tmp26}, p_newLength);
    ca_.Goto(&block14);
  }

    ca_.Bind(&block14);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=204&c=5
void FastSplice_FixedDoubleArray_Number_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructArguments p_args, TNode<JSArray> p_a, TNode<Smi> p_length, TNode<Smi> p_newLength, TNode<Smi> p_actualStart, TNode<Smi> p_insertCount, TNode<Smi> p_actualDeleteCount) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    EnsureWriteableFastElements_0(state_, TNode<Context>{p_context}, TNode<JSArray>{p_a});
    tmp0 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi>{p_insertCount}, TNode<Smi>{p_actualDeleteCount});
    ca_.Branch(tmp0, &block2, std::vector<compiler::Node*>{}, &block3, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp1;
  TNode<FixedArrayBase> tmp2;
  TNode<FixedArrayBase> tmp3;
  TNode<Smi> tmp4;
  TNode<Smi> tmp5;
  TNode<Smi> tmp6;
  TNode<Smi> tmp7;
  TNode<BoolT> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp2 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{p_a, tmp1});
    tmp3 = UnsafeCast_FixedDoubleArray_OR_EmptyFixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp2});
    tmp4 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{p_actualStart}, TNode<Smi>{p_insertCount});
    tmp5 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{p_actualStart}, TNode<Smi>{p_actualDeleteCount});
    tmp6 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{p_length}, TNode<Smi>{p_actualDeleteCount});
    tmp7 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp6}, TNode<Smi>{p_actualStart});
    tmp8 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{p_insertCount}, TNode<Smi>{p_actualDeleteCount});
    ca_.Branch(tmp8, &block4, std::vector<compiler::Node*>{}, &block5, std::vector<compiler::Node*>{});
  }

  TNode<FixedDoubleArray> tmp9;
  TNode<FixedDoubleArray> tmp10;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp9 = UnsafeCast_FixedDoubleArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp3});
    DoMoveElements_FixedDoubleArray_0(state_, TNode<FixedDoubleArray>{tmp9}, TNode<Smi>{tmp4}, TNode<Smi>{tmp5}, TNode<Smi>{tmp7});
    tmp10 = UnsafeCast_FixedDoubleArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp3});
    StoreHoles_FixedDoubleArray_0(state_, TNode<FixedDoubleArray>{tmp10}, TNode<Smi>{p_newLength}, TNode<Smi>{p_length});
    ca_.Goto(&block6);
  }

  TNode<BoolT> tmp11;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp11 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{p_insertCount}, TNode<Smi>{p_actualDeleteCount});
    ca_.Branch(tmp11, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp12;
  TNode<Smi> tmp13;
  TNode<BoolT> tmp14;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp13 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp3, tmp12});
    tmp14 = CodeStubAssembler(state_).SmiLessThanOrEqual(TNode<Smi>{p_newLength}, TNode<Smi>{tmp13});
    ca_.Branch(tmp14, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  TNode<FixedDoubleArray> tmp15;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp15 = UnsafeCast_FixedDoubleArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp3});
    DoMoveElements_FixedDoubleArray_0(state_, TNode<FixedDoubleArray>{tmp15}, TNode<Smi>{tmp4}, TNode<Smi>{tmp5}, TNode<Smi>{tmp7});
    ca_.Goto(&block11);
  }

  TNode<Smi> tmp16;
  TNode<Smi> tmp17;
  TNode<FixedArrayBase> tmp18;
  TNode<FixedDoubleArray> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<Smi> tmp22;
  TNode<Smi> tmp23;
  TNode<BoolT> tmp24;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp16 = CodeStubAssembler(state_).CalculateNewElementsCapacity(TNode<Smi>{p_newLength});
    tmp17 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp18 = Extract_1(state_, TNode<Context>{p_context}, TNode<FixedArrayBase>{tmp3}, TNode<Smi>{tmp17}, TNode<Smi>{p_actualStart}, TNode<Smi>{tmp16});
    tmp19 = UnsafeCast_FixedDoubleArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp18});
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{p_a, tmp20}, tmp19);
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp22 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp3, tmp21});
    tmp23 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp24 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp22}, TNode<Smi>{tmp23});
    ca_.Branch(tmp24, &block12, std::vector<compiler::Node*>{}, &block13, std::vector<compiler::Node*>{});
  }

  TNode<FixedDoubleArray> tmp25;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp25 = UnsafeCast_FixedDoubleArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp3});
    DoCopyElements_FixedDoubleArray_0(state_, TNode<FixedDoubleArray>{tmp19}, TNode<Smi>{tmp4}, TNode<FixedDoubleArray>{tmp25}, TNode<Smi>{tmp5}, TNode<Smi>{tmp7});
    ca_.Goto(&block13);
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block11);
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    ca_.Goto(&block8);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block6);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block3);
  }

  TNode<IntPtrT> tmp26;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    InsertArgumentsIntoFastPackedArray_FixedDoubleArray_Number_0(state_, TNode<JSArray>{p_a}, TNode<Smi>{p_actualStart}, TorqueStructArguments{TNode<RawPtrT>{p_args.frame}, TNode<RawPtrT>{p_args.base}, TNode<IntPtrT>{p_args.length}, TNode<IntPtrT>{p_args.actual_count}}, IntegerLiteral(false, 0x2ull), TNode<Smi>{p_insertCount});
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{p_a, tmp26}, p_newLength);
    ca_.Goto(&block14);
  }

    ca_.Bind(&block14);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=95&c=7
void DoMoveElements_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_elements, TNode<Smi> p_dstIndex, TNode<Smi> p_srcIndex, TNode<Smi> p_count) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_dstIndex});
    tmp1 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_srcIndex});
    tmp2 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_count});
    TorqueMoveElements_0(state_, TNode<FixedArray>{p_elements}, TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=97&c=7
void StoreHoles_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_elements, TNode<Smi> p_holeStartIndex, TNode<Smi> p_holeEndIndex) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block4, p_holeStartIndex);
  }

  TNode<Smi> phi_bb4_3;
  TNode<BoolT> tmp0;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_3);
    tmp0 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{phi_bb4_3}, TNode<Smi>{p_holeEndIndex});
    ca_.Branch(tmp0, &block2, std::vector<compiler::Node*>{phi_bb4_3}, &block3, std::vector<compiler::Node*>{phi_bb4_3});
  }

  TNode<Smi> phi_bb2_3;
  TNode<Smi> tmp1;
  TNode<Smi> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_3);
    StoreArrayHole_1(state_, TNode<FixedArray>{p_elements}, TNode<Smi>{phi_bb2_3});
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp2 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb2_3}, TNode<Smi>{tmp1});
    ca_.Goto(&block4, tmp2);
  }

  TNode<Smi> phi_bb3_3;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_3);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=110&c=11
void DoCopyElements_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_dstElements, TNode<Smi> p_dstIndex, TNode<FixedArray> p_srcElements, TNode<Smi> p_srcIndex, TNode<Smi> p_count) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_dstIndex});
    tmp1 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_srcIndex});
    tmp2 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_count});
    TorqueCopyElements_0(state_, TNode<FixedArray>{p_dstElements}, TNode<IntPtrT>{tmp0}, TNode<FixedArray>{p_srcElements}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=89&c=22
TNode<FixedArrayBase> UnsafeCast_FixedDoubleArray_OR_EmptyFixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<FixedArrayBase> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = TORQUE_CAST(TNode<Object>{p_o});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<FixedArrayBase>{tmp0};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=95&c=7
void DoMoveElements_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_elements, TNode<Smi> p_dstIndex, TNode<Smi> p_srcIndex, TNode<Smi> p_count) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_dstIndex});
    tmp1 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_srcIndex});
    tmp2 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_count});
    TorqueMoveElements_1(state_, TNode<FixedDoubleArray>{p_elements}, TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=97&c=7
void StoreHoles_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_elements, TNode<Smi> p_holeStartIndex, TNode<Smi> p_holeEndIndex) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block4, p_holeStartIndex);
  }

  TNode<Smi> phi_bb4_3;
  TNode<BoolT> tmp0;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_3);
    tmp0 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{phi_bb4_3}, TNode<Smi>{p_holeEndIndex});
    ca_.Branch(tmp0, &block2, std::vector<compiler::Node*>{phi_bb4_3}, &block3, std::vector<compiler::Node*>{phi_bb4_3});
  }

  TNode<Smi> phi_bb2_3;
  TNode<Smi> tmp1;
  TNode<Smi> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_3);
    StoreArrayHole_0(state_, TNode<FixedDoubleArray>{p_elements}, TNode<Smi>{phi_bb2_3});
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp2 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb2_3}, TNode<Smi>{tmp1});
    ca_.Goto(&block4, tmp2);
  }

  TNode<Smi> phi_bb3_3;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_3);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-splice.tq?l=110&c=11
void DoCopyElements_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_dstElements, TNode<Smi> p_dstIndex, TNode<FixedDoubleArray> p_srcElements, TNode<Smi> p_srcIndex, TNode<Smi> p_count) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_dstIndex});
    tmp1 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_srcIndex});
    tmp2 = Convert_intptr_Smi_0(state_, TNode<Smi>{p_count});
    TorqueCopyElements_1(state_, TNode<FixedDoubleArray>{p_dstElements}, TNode<IntPtrT>{tmp0}, TNode<FixedDoubleArray>{p_srcElements}, TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp2});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

} // namespace internal
} // namespace v8
