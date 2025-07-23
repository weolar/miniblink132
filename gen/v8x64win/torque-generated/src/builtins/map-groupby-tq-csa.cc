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
#include "torque-generated/src/builtins/map-groupby-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/collections-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/function-tq-csa.h"
#include "torque-generated/src/builtins/map-groupby-tq-csa.h"
#include "torque-generated/src/builtins/object-groupby-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(MapGroupBy, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kItems);
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kCallback);
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT, IntPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<False> tmp0;
  TNode<OrderedHashMap> tmp1;
  TNode<OrderedHashMap> tmp2;
  TNode<Int32T> tmp3;
  TNode<Int32T> tmp4;
  TNode<Object> tmp5;
  TNode<Object> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Map> tmp8;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = False_0(state_);
    tmp1 = GroupByImpl_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, TNode<Object>{parameter3}, TNode<Boolean>{tmp0}, "Map.groupBy");
    std::tie(tmp2, tmp3, tmp4, tmp5, tmp6, tmp7) = NewUnmodifiedOrderedHashMapIterator_0(state_, TNode<OrderedHashMap>{tmp1}).Flatten();
    tmp8 = GetFastPackedElementsJSArrayMap_0(state_, TNode<Context>{parameter0});
    ca_.Goto(&block5, tmp5, tmp6, tmp7);
  }

  TNode<Object> phi_bb5_8;
  TNode<Object> phi_bb5_9;
  TNode<IntPtrT> phi_bb5_10;
  TNode<BoolT> tmp9;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_8, &phi_bb5_9, &phi_bb5_10);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp9, &block3, std::vector<compiler::Node*>{phi_bb5_8, phi_bb5_9, phi_bb5_10}, &block4, std::vector<compiler::Node*>{phi_bb5_8, phi_bb5_9, phi_bb5_10});
  }

  TNode<Object> phi_bb3_8;
  TNode<Object> phi_bb3_9;
  TNode<IntPtrT> phi_bb3_10;
  TNode<Object> tmp10;
  TNode<Object> tmp11;
  TNode<IntPtrT> tmp12;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_8, &phi_bb3_9, &phi_bb3_10);
    compiler::CodeAssemblerLabel label13(&ca_);
    std::tie(tmp10, tmp11, tmp12) = CollectionsBuiltinsAssembler(state_).NextKeyValueIndexTupleUnmodifiedTable(TNode<OrderedHashMap>{tmp2}, TNode<Int32T>{tmp3}, TNode<Int32T>{tmp4}, TNode<IntPtrT>{phi_bb3_10}, &label13).Flatten();
    ca_.Goto(&block7, phi_bb3_8, phi_bb3_9, phi_bb3_10, phi_bb3_10);
    if (label13.is_used()) {
      ca_.Bind(&label13);
      ca_.Goto(&block8, phi_bb3_8, phi_bb3_9, phi_bb3_10, phi_bb3_10);
    }
  }

  TNode<Object> phi_bb8_8;
  TNode<Object> phi_bb8_9;
  TNode<IntPtrT> phi_bb8_10;
  TNode<IntPtrT> phi_bb8_15;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_8, &phi_bb8_9, &phi_bb8_10, &phi_bb8_15);
    ca_.Goto(&block1);
  }

  TNode<Object> phi_bb7_8;
  TNode<Object> phi_bb7_9;
  TNode<IntPtrT> phi_bb7_10;
  TNode<IntPtrT> phi_bb7_15;
  TNode<ArrayList> tmp14;
  TNode<FixedArray> tmp15;
  TNode<JSArray> tmp16;
  TNode<Int32T> tmp17;
  TNode<Int32T> tmp18;
  TNode<Int32T> tmp19;
  TNode<Int32T> tmp20;
  TNode<Int32T> tmp21;
  TNode<Int32T> tmp22;
  TNode<IntPtrT> tmp23;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_8, &phi_bb7_9, &phi_bb7_10, &phi_bb7_15);
    tmp14 = UnsafeCast_ArrayList_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp11});
    tmp15 = CodeStubAssembler(state_).ArrayListElements(TNode<ArrayList>{tmp14});
    tmp16 = NewJSArray_0(state_, TNode<Context>{parameter0}, TNode<Map>{tmp8}, TNode<FixedArrayBase>{tmp15});
    tmp17 = Convert_int32_intptr_0(state_, TNode<IntPtrT>{tmp12});
    tmp18 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp19 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp17}, TNode<Int32T>{tmp18});
    tmp20 = FromConstexpr_int32_constexpr_int32_0(state_, OrderedHashMap::kEntrySize);
    tmp21 = CodeStubAssembler(state_).Int32Mul(TNode<Int32T>{tmp19}, TNode<Int32T>{tmp20});
    tmp22 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp21}, TNode<Int32T>{tmp3});
    tmp23 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp22});
    CollectionsBuiltinsAssembler(state_).UnsafeStoreValueInOrderedHashMapEntry(TNode<OrderedHashMap>{tmp2}, TNode<Object>{tmp16}, TNode<IntPtrT>{tmp23});
    ca_.Goto(&block5, tmp10, tmp11, tmp12);
  }

  TNode<Object> phi_bb4_8;
  TNode<Object> phi_bb4_9;
  TNode<IntPtrT> phi_bb4_10;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_8, &phi_bb4_9, &phi_bb4_10);
    ca_.Goto(&block1);
  }

  TNode<IntPtrT> tmp24;
  TNode<Object> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<Map> tmp27;
  TNode<FixedArray> tmp28;
  TNode<FixedArray> tmp29;
  TNode<BoolT> tmp30;
  TNode<BoolT> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<HeapObject> tmp33;
  TNode<IntPtrT> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<JSMap> tmp38;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp24 = JS_MAP_MAP_INDEX_0(state_);
    std::tie(tmp25, tmp26) = NativeContextSlot_NativeContext_Map_0(state_, TNode<NativeContext>{parameter0}, TNode<IntPtrT>{tmp24}).Flatten();
    tmp27 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp25, tmp26});
    tmp28 = kEmptyFixedArray_0(state_);
    tmp29 = kEmptyFixedArray_0(state_);
    tmp30 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp31 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp32 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp33 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp32}, TNode<Map>{tmp27}, TNode<BoolT>{tmp30}, TNode<BoolT>{tmp31});
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp33, tmp34}, tmp27);
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp33, tmp35}, tmp28);
    tmp36 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp33, tmp36}, tmp29);
    tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp33, tmp37}, tmp1);
    tmp38 = TORQUE_CAST(TNode<HeapObject>{tmp33});
    CodeStubAssembler(state_).Return(tmp38);
  }
}

} // namespace internal
} // namespace v8
