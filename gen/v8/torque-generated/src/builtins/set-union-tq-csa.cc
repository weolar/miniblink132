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
#include "torque-generated/src/builtins/set-union-tq-csa.h"
#include "torque-generated/src/builtins/array-from-async-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/collections-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/function-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/set-difference-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(SetPrototypeUnion, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kOther);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT, IntPtrT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT, IntPtrT> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, Object, IntPtrT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, Object, IntPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, Object, IntPtrT, IntPtrT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, Object, IntPtrT, IntPtrT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, Object, IntPtrT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, JSReceiver> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, JSReceiver> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, JSReceiver> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, JSReceiver> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, JSReceiver> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Map> tmp0;
    TNode<JSSet> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = GetIteratorResultMap_0(state_, TNode<Context> { parameter0 });
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Cast_JSSet_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label2);
        ca_.Goto(&block3);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block4);
        }
    }

    TNode<Object> tmp3;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp3 = FromConstexpr_Object_constexpr_string_0(state_, "Set.prototype.union");
        CodeStubAssembler(state_).ThrowTypeError(
            TNode<Context> { parameter0 }, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object> { tmp3 }, TNode<Object> { parameter1 });
    }

    TNode<JSReceiver> tmp4;
    TNode<Number> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<JSSet> tmp8;
    TNode<OrderedHashSet> tmp9;
    TNode<FixedArrayBase> tmp10;
    TNode<OrderedHashSet> tmp11;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        std::tie(tmp4, tmp5, tmp6, tmp7) = GetSetRecord_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, "Set.prototype.union").Flatten();
        std::tie(tmp8, tmp9) = NewStableBackingTableWitness_0(state_, TNode<JSSet> { tmp1 }).Flatten();
        tmp10 = CodeStubAssembler(state_).CloneFixedArray(TNode<FixedArrayBase> { tmp9 }, CodeStubAssembler::ExtractFixedArrayFlag::kFixedArrays);
        compiler::CodeAssemblerLabel label12(&ca_);
        tmp11 = Cast_OrderedHashSet_0(state_, TNode<HeapObject> { tmp10 }, &label12);
        ca_.Goto(&block8);
        if (label12.is_used()) {
            ca_.Bind(&label12);
            ca_.Goto(&block9);
        }
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<JSSet> tmp13;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        compiler::CodeAssemblerLabel label14(&ca_);
        tmp13 = Cast_JSSetWithNoCustomIteration_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, &label14);
        ca_.Goto(&block16);
        if (label14.is_used()) {
            ca_.Bind(&label14);
            ca_.Goto(&block17);
        }
    }

    TNode<JSMap> tmp15;
    if (block17.is_used()) {
        ca_.Bind(&block17);
        compiler::CodeAssemblerLabel label16(&ca_);
        tmp15 = Cast_JSMapWithNoCustomIteration_1(state_, TNode<Context> { parameter0 }, TNode<Object> { ca_.UncheckedCast<Object>(parameter2) }, &label16);
        ca_.Goto(&block29);
        if (label16.is_used()) {
            ca_.Bind(&label16);
            ca_.Goto(&block30);
        }
    }

    if (block16.is_used()) {
        ca_.Bind(&block16);
        compiler::CodeAssemblerLabel label17(&ca_);
        CheckSetRecordHasJSSetMethods_0(
            state_, TorqueStructSetRecord { TNode<JSReceiver> { tmp4 }, TNode<Number> { tmp5 }, TNode<Object> { tmp6 }, TNode<Object> { tmp7 } }, &label17);
        ca_.Goto(&block18);
        if (label17.is_used()) {
            ca_.Bind(&label17);
            ca_.Goto(&block19);
        }
    }

    if (block19.is_used()) {
        ca_.Bind(&block19);
        ca_.Goto(&block13);
    }

    TNode<JSSet> tmp18;
    TNode<OrderedHashSet> tmp19;
    TNode<OrderedHashSet> tmp20;
    TNode<Int32T> tmp21;
    TNode<Int32T> tmp22;
    TNode<Object> tmp23;
    TNode<IntPtrT> tmp24;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        std::tie(tmp18, tmp19) = NewStableBackingTableWitness_0(state_, TNode<JSSet> { tmp13 }).Flatten();
        std::tie(tmp20, tmp21, tmp22, tmp23, tmp24) = NewUnmodifiedOrderedHashSetIterator_0(state_, TNode<OrderedHashSet> { tmp19 }).Flatten();
        ca_.Goto(&block23, tmp11, tmp23, tmp24);
    }

    TNode<OrderedHashSet> phi_bb23_11;
    TNode<Object> phi_bb23_19;
    TNode<IntPtrT> phi_bb23_20;
    TNode<BoolT> tmp25;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_11, &phi_bb23_19, &phi_bb23_20);
        tmp25 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp25, &block21, std::vector<compiler::Node*> { phi_bb23_11, phi_bb23_19, phi_bb23_20 }, &block22,
            std::vector<compiler::Node*> { phi_bb23_11, phi_bb23_19, phi_bb23_20 });
    }

    TNode<OrderedHashSet> phi_bb21_11;
    TNode<Object> phi_bb21_19;
    TNode<IntPtrT> phi_bb21_20;
    TNode<Object> tmp26;
    TNode<IntPtrT> tmp27;
    if (block21.is_used()) {
        ca_.Bind(&block21, &phi_bb21_11, &phi_bb21_19, &phi_bb21_20);
        compiler::CodeAssemblerLabel label28(&ca_);
        std::tie(tmp26, tmp27) = CollectionsBuiltinsAssembler(state_)
                                     .NextKeyIndexPairUnmodifiedTable(TNode<OrderedHashSet> { tmp20 }, TNode<Int32T> { tmp21 }, TNode<Int32T> { tmp22 },
                                         TNode<IntPtrT> { phi_bb21_20 }, &label28)
                                     .Flatten();
        ca_.Goto(&block25, phi_bb21_11, phi_bb21_19, phi_bb21_20, phi_bb21_20);
        if (label28.is_used()) {
            ca_.Bind(&label28);
            ca_.Goto(&block26, phi_bb21_11, phi_bb21_19, phi_bb21_20, phi_bb21_20);
        }
    }

    TNode<OrderedHashSet> phi_bb26_11;
    TNode<Object> phi_bb26_19;
    TNode<IntPtrT> phi_bb26_20;
    TNode<IntPtrT> phi_bb26_24;
    if (block26.is_used()) {
        ca_.Bind(&block26, &phi_bb26_11, &phi_bb26_19, &phi_bb26_20, &phi_bb26_24);
        ca_.Goto(&block11, phi_bb26_11);
    }

    TNode<OrderedHashSet> phi_bb25_11;
    TNode<Object> phi_bb25_19;
    TNode<IntPtrT> phi_bb25_20;
    TNode<IntPtrT> phi_bb25_24;
    TNode<String> tmp29;
    TNode<OrderedHashSet> tmp30;
    if (block25.is_used()) {
        ca_.Bind(&block25, &phi_bb25_11, &phi_bb25_19, &phi_bb25_20, &phi_bb25_24);
        tmp29 = FromConstexpr_String_constexpr_string_0(state_, "Set.prototype.union");
        tmp30 = CollectionsBuiltinsAssembler(state_).AddToSetTable(
            TNode<Context> { parameter0 }, TNode<OrderedHashSet> { phi_bb25_11 }, TNode<Object> { tmp26 }, TNode<String> { tmp29 });
        ca_.Goto(&block23, tmp30, tmp26, tmp27);
    }

    TNode<OrderedHashSet> phi_bb22_11;
    TNode<Object> phi_bb22_19;
    TNode<IntPtrT> phi_bb22_20;
    if (block22.is_used()) {
        ca_.Bind(&block22, &phi_bb22_11, &phi_bb22_19, &phi_bb22_20);
        ca_.Goto(&block14, phi_bb22_11);
    }

    if (block30.is_used()) {
        ca_.Bind(&block30);
        ca_.Goto(&block13);
    }

    if (block29.is_used()) {
        ca_.Bind(&block29);
        compiler::CodeAssemblerLabel label31(&ca_);
        CheckSetRecordHasJSMapMethods_0(
            state_, TorqueStructSetRecord { TNode<JSReceiver> { tmp4 }, TNode<Number> { tmp5 }, TNode<Object> { tmp6 }, TNode<Object> { tmp7 } }, &label31);
        ca_.Goto(&block31);
        if (label31.is_used()) {
            ca_.Bind(&label31);
            ca_.Goto(&block32);
        }
    }

    if (block32.is_used()) {
        ca_.Bind(&block32);
        ca_.Goto(&block13);
    }

    TNode<JSMap> tmp32;
    TNode<OrderedHashMap> tmp33;
    TNode<OrderedHashMap> tmp34;
    TNode<Int32T> tmp35;
    TNode<Int32T> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    TNode<IntPtrT> tmp39;
    if (block31.is_used()) {
        ca_.Bind(&block31);
        std::tie(tmp32, tmp33) = NewStableBackingTableWitness_1(state_, TNode<JSMap> { tmp15 }).Flatten();
        std::tie(tmp34, tmp35, tmp36, tmp37, tmp38, tmp39) = NewUnmodifiedOrderedHashMapIterator_0(state_, TNode<OrderedHashMap> { tmp33 }).Flatten();
        ca_.Goto(&block36, tmp11, tmp37, tmp38, tmp39);
    }

    TNode<OrderedHashSet> phi_bb36_11;
    TNode<Object> phi_bb36_19;
    TNode<Object> phi_bb36_20;
    TNode<IntPtrT> phi_bb36_21;
    TNode<BoolT> tmp40;
    if (block36.is_used()) {
        ca_.Bind(&block36, &phi_bb36_11, &phi_bb36_19, &phi_bb36_20, &phi_bb36_21);
        tmp40 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp40, &block34, std::vector<compiler::Node*> { phi_bb36_11, phi_bb36_19, phi_bb36_20, phi_bb36_21 }, &block35,
            std::vector<compiler::Node*> { phi_bb36_11, phi_bb36_19, phi_bb36_20, phi_bb36_21 });
    }

    TNode<OrderedHashSet> phi_bb34_11;
    TNode<Object> phi_bb34_19;
    TNode<Object> phi_bb34_20;
    TNode<IntPtrT> phi_bb34_21;
    TNode<Object> tmp41;
    TNode<Object> tmp42;
    TNode<IntPtrT> tmp43;
    if (block34.is_used()) {
        ca_.Bind(&block34, &phi_bb34_11, &phi_bb34_19, &phi_bb34_20, &phi_bb34_21);
        compiler::CodeAssemblerLabel label44(&ca_);
        std::tie(tmp41, tmp42, tmp43) = CollectionsBuiltinsAssembler(state_)
                                            .NextKeyValueIndexTupleUnmodifiedTable(TNode<OrderedHashMap> { tmp34 }, TNode<Int32T> { tmp35 },
                                                TNode<Int32T> { tmp36 }, TNode<IntPtrT> { phi_bb34_21 }, &label44)
                                            .Flatten();
        ca_.Goto(&block38, phi_bb34_11, phi_bb34_19, phi_bb34_20, phi_bb34_21, phi_bb34_21);
        if (label44.is_used()) {
            ca_.Bind(&label44);
            ca_.Goto(&block39, phi_bb34_11, phi_bb34_19, phi_bb34_20, phi_bb34_21, phi_bb34_21);
        }
    }

    TNode<OrderedHashSet> phi_bb39_11;
    TNode<Object> phi_bb39_19;
    TNode<Object> phi_bb39_20;
    TNode<IntPtrT> phi_bb39_21;
    TNode<IntPtrT> phi_bb39_25;
    if (block39.is_used()) {
        ca_.Bind(&block39, &phi_bb39_11, &phi_bb39_19, &phi_bb39_20, &phi_bb39_21, &phi_bb39_25);
        ca_.Goto(&block11, phi_bb39_11);
    }

    TNode<OrderedHashSet> phi_bb38_11;
    TNode<Object> phi_bb38_19;
    TNode<Object> phi_bb38_20;
    TNode<IntPtrT> phi_bb38_21;
    TNode<IntPtrT> phi_bb38_25;
    TNode<String> tmp45;
    TNode<OrderedHashSet> tmp46;
    if (block38.is_used()) {
        ca_.Bind(&block38, &phi_bb38_11, &phi_bb38_19, &phi_bb38_20, &phi_bb38_21, &phi_bb38_25);
        tmp45 = FromConstexpr_String_constexpr_string_0(state_, "Set.prototype.union");
        tmp46 = CollectionsBuiltinsAssembler(state_).AddToSetTable(
            TNode<Context> { parameter0 }, TNode<OrderedHashSet> { phi_bb38_11 }, TNode<Object> { tmp41 }, TNode<String> { tmp45 });
        ca_.Goto(&block36, tmp46, tmp41, tmp42, tmp43);
    }

    TNode<OrderedHashSet> phi_bb35_11;
    TNode<Object> phi_bb35_19;
    TNode<Object> phi_bb35_20;
    TNode<IntPtrT> phi_bb35_21;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_11, &phi_bb35_19, &phi_bb35_20, &phi_bb35_21);
        ca_.Goto(&block14, phi_bb35_11);
    }

    TNode<OrderedHashSet> phi_bb14_11;
    if (block14.is_used()) {
        ca_.Bind(&block14, &phi_bb14_11);
        ca_.Goto(&block12, phi_bb14_11);
    }

    TNode<JSReceiver> tmp47;
    TNode<JSReceiver> tmp48;
    TNode<Object> tmp49;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        tmp47 = UnsafeCast_Callable_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp7 });
        std::tie(tmp48, tmp49) = GetKeysIterator_0(state_, TNode<Context> { parameter0 }, TNode<JSReceiver> { tmp4 }, TNode<JSReceiver> { tmp47 }).Flatten();
        ca_.Goto(&block42, tmp11, ca_.Uninitialized<JSReceiver>());
    }

    TNode<OrderedHashSet> phi_bb42_11;
    TNode<JSReceiver> phi_bb42_14;
    TNode<BoolT> tmp50;
    if (block42.is_used()) {
        ca_.Bind(&block42, &phi_bb42_11, &phi_bb42_14);
        tmp50 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(
            tmp50, &block40, std::vector<compiler::Node*> { phi_bb42_11, phi_bb42_14 }, &block41, std::vector<compiler::Node*> { phi_bb42_11, phi_bb42_14 });
    }

    TNode<OrderedHashSet> phi_bb40_11;
    TNode<JSReceiver> phi_bb40_14;
    TNode<JSReceiver> tmp51;
    if (block40.is_used()) {
        ca_.Bind(&block40, &phi_bb40_11, &phi_bb40_14);
        compiler::CodeAssemblerLabel label52(&ca_);
        tmp51 = IteratorBuiltinsAssembler(state_).IteratorStep(
            TNode<Context> { parameter0 }, TorqueStructIteratorRecord { TNode<JSReceiver> { tmp48 }, TNode<Object> { tmp49 } }, TNode<Map> { tmp0 }, &label52);
        ca_.Goto(&block43, phi_bb40_11, phi_bb40_14);
        if (label52.is_used()) {
            ca_.Bind(&label52);
            ca_.Goto(&block44, phi_bb40_11, phi_bb40_14);
        }
    }

    TNode<OrderedHashSet> phi_bb44_11;
    TNode<JSReceiver> phi_bb44_14;
    if (block44.is_used()) {
        ca_.Bind(&block44, &phi_bb44_11, &phi_bb44_14);
        ca_.Goto(&block11, phi_bb44_11);
    }

    TNode<OrderedHashSet> phi_bb43_11;
    TNode<JSReceiver> phi_bb43_14;
    TNode<Object> tmp53;
    TNode<String> tmp54;
    TNode<OrderedHashSet> tmp55;
    if (block43.is_used()) {
        ca_.Bind(&block43, &phi_bb43_11, &phi_bb43_14);
        tmp53 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context> { parameter0 }, TNode<JSReceiver> { tmp51 }, TNode<Map> { tmp0 });
        tmp54 = FromConstexpr_String_constexpr_string_0(state_, "Set.prototype.union");
        tmp55 = CollectionsBuiltinsAssembler(state_).AddToSetTable(
            TNode<Context> { parameter0 }, TNode<OrderedHashSet> { phi_bb43_11 }, TNode<Object> { tmp53 }, TNode<String> { tmp54 });
        ca_.Goto(&block42, tmp55, tmp51);
    }

    TNode<OrderedHashSet> phi_bb41_11;
    TNode<JSReceiver> phi_bb41_14;
    if (block41.is_used()) {
        ca_.Bind(&block41, &phi_bb41_11, &phi_bb41_14);
        ca_.Goto(&block12, phi_bb41_11);
    }

    TNode<OrderedHashSet> phi_bb12_11;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_11);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<OrderedHashSet> phi_bb11_11;
    TNode<IntPtrT> tmp56;
    TNode<Object> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<Map> tmp59;
    TNode<FixedArray> tmp60;
    TNode<FixedArray> tmp61;
    TNode<BoolT> tmp62;
    TNode<BoolT> tmp63;
    TNode<IntPtrT> tmp64;
    TNode<HeapObject> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<IntPtrT> tmp69;
    TNode<JSSet> tmp70;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_11);
        tmp56 = JS_SET_MAP_INDEX_0(state_);
        std::tie(tmp57, tmp58) = NativeContextSlot_NativeContext_Map_0(state_, TNode<NativeContext> { parameter0 }, TNode<IntPtrT> { tmp56 }).Flatten();
        tmp59 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { tmp57, tmp58 });
        tmp60 = kEmptyFixedArray_0(state_);
        tmp61 = kEmptyFixedArray_0(state_);
        tmp62 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        tmp63 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        tmp64 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp65 = AllocateFromNew_0(state_, TNode<IntPtrT> { tmp64 }, TNode<Map> { tmp59 }, TNode<BoolT> { tmp62 }, TNode<BoolT> { tmp63 });
        tmp66 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference { tmp65, tmp66 }, tmp59);
        tmp67 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp65, tmp67 }, tmp60);
        tmp68 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference { tmp65, tmp68 }, tmp61);
        tmp69 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp65, tmp69 }, phi_bb11_11);
        tmp70 = TORQUE_CAST(TNode<HeapObject> { tmp65 });
        CodeStubAssembler(state_).Return(tmp70);
    }
}

} // namespace internal
} // namespace v8
