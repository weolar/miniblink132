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
#include "torque-generated/src/builtins/set-intersection-tq-csa.h"
#include "torque-generated/src/builtins/array-from-async-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/collections-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/function-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/set-difference-tq-csa.h"
#include "torque-generated/src/builtins/set-intersection-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(SetPrototypeIntersection, CodeStubAssembler)
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
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, Object, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, Object, IntPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, Object, IntPtrT, IntPtrT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, Object, IntPtrT, IntPtrT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, Object, IntPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, Object, IntPtrT> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, Object, IntPtrT> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, Object, IntPtrT> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, JSReceiver> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, JSReceiver> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, JSReceiver> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, JSReceiver> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet, JSReceiver> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, OrderedHashSet> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
        tmp3 = FromConstexpr_Object_constexpr_string_0(state_, "Set.prototype.intersection");
        CodeStubAssembler(state_).ThrowTypeError(
            TNode<Context> { parameter0 }, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object> { tmp3 }, TNode<Object> { parameter1 });
    }

    TNode<JSReceiver> tmp4;
    TNode<Number> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<JSSet> tmp8;
    TNode<OrderedHashSet> tmp9;
    TNode<OrderedHashSet> tmp10;
    TNode<Int32T> tmp11;
    TNode<JSSet> tmp12;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        std::tie(tmp4, tmp5, tmp6, tmp7)
            = GetSetRecord_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, "Set.prototype.intersection").Flatten();
        std::tie(tmp8, tmp9) = NewStableBackingTableWitness_0(state_, TNode<JSSet> { tmp1 }).Flatten();
        tmp10 = CodeStubAssembler(state_).AllocateOrderedHashSet();
        tmp11 = LoadOrderedHashTableMetadata_0(state_, TNode<FixedArray> { tmp9 }, OrderedHashSet::NumberOfElementsIndex());
        compiler::CodeAssemblerLabel label13(&ca_);
        tmp12 = Cast_JSSetWithNoCustomIteration_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, &label13);
        ca_.Goto(&block12);
        if (label13.is_used()) {
            ca_.Bind(&label13);
            ca_.Goto(&block13);
        }
    }

    TNode<JSMap> tmp14;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        compiler::CodeAssemblerLabel label15(&ca_);
        tmp14 = Cast_JSMapWithNoCustomIteration_1(state_, TNode<Context> { parameter0 }, TNode<Object> { ca_.UncheckedCast<Object>(parameter2) }, &label15);
        ca_.Goto(&block22);
        if (label15.is_used()) {
            ca_.Bind(&label15);
            ca_.Goto(&block23);
        }
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        compiler::CodeAssemblerLabel label16(&ca_);
        CheckSetRecordHasJSSetMethods_0(
            state_, TorqueStructSetRecord { TNode<JSReceiver> { tmp4 }, TNode<Number> { tmp5 }, TNode<Object> { tmp6 }, TNode<Object> { tmp7 } }, &label16);
        ca_.Goto(&block14);
        if (label16.is_used()) {
            ca_.Bind(&label16);
            ca_.Goto(&block15);
        }
    }

    if (block15.is_used()) {
        ca_.Bind(&block15);
        ca_.Goto(&block9);
    }

    TNode<JSSet> tmp17;
    TNode<OrderedHashSet> tmp18;
    TNode<Int32T> tmp19;
    TNode<BoolT> tmp20;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        std::tie(tmp17, tmp18) = NewStableBackingTableWitness_0(state_, TNode<JSSet> { tmp12 }).Flatten();
        tmp19 = LoadOrderedHashTableMetadata_0(state_, TNode<FixedArray> { tmp18 }, OrderedHashSet::NumberOfElementsIndex());
        tmp20 = CodeStubAssembler(state_).Int32LessThanOrEqual(TNode<Int32T> { tmp11 }, TNode<Int32T> { tmp19 });
        ca_.Branch(tmp20, &block17, std::vector<compiler::Node*> {}, &block18, std::vector<compiler::Node*> {});
    }

    TNode<String> tmp21;
    TNode<OrderedHashSet> tmp22;
    if (block17.is_used()) {
        ca_.Bind(&block17);
        tmp21 = FromConstexpr_String_constexpr_string_0(state_, "Set.prototype.intersection");
        tmp22 = FastIntersect_StableJSSetBackingTableWitness_0(state_, TNode<Context> { parameter0 },
            TorqueStructStableJSSetBackingTableWitness_0 { TNode<JSSet> { tmp8 }, TNode<OrderedHashSet> { tmp9 } },
            TorqueStructStableJSSetBackingTableWitness_0 { TNode<JSSet> { tmp17 }, TNode<OrderedHashSet> { tmp18 } }, TNode<String> { tmp21 },
            TNode<OrderedHashSet> { tmp10 });
        ca_.Goto(&block7, tmp9, tmp22);
    }

    TNode<String> tmp23;
    TNode<OrderedHashSet> tmp24;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        tmp23 = FromConstexpr_String_constexpr_string_0(state_, "Set.prototype.intersection");
        tmp24 = FastIntersect_StableJSSetBackingTableWitness_0(state_, TNode<Context> { parameter0 },
            TorqueStructStableJSSetBackingTableWitness_0 { TNode<JSSet> { tmp17 }, TNode<OrderedHashSet> { tmp18 } },
            TorqueStructStableJSSetBackingTableWitness_0 { TNode<JSSet> { tmp8 }, TNode<OrderedHashSet> { tmp9 } }, TNode<String> { tmp23 },
            TNode<OrderedHashSet> { tmp10 });
        ca_.Goto(&block7, tmp9, tmp24);
    }

    if (block23.is_used()) {
        ca_.Bind(&block23);
        ca_.Goto(&block9);
    }

    if (block22.is_used()) {
        ca_.Bind(&block22);
        compiler::CodeAssemblerLabel label25(&ca_);
        CheckSetRecordHasJSMapMethods_0(
            state_, TorqueStructSetRecord { TNode<JSReceiver> { tmp4 }, TNode<Number> { tmp5 }, TNode<Object> { tmp6 }, TNode<Object> { tmp7 } }, &label25);
        ca_.Goto(&block24);
        if (label25.is_used()) {
            ca_.Bind(&label25);
            ca_.Goto(&block25);
        }
    }

    if (block25.is_used()) {
        ca_.Bind(&block25);
        ca_.Goto(&block9);
    }

    TNode<JSMap> tmp26;
    TNode<OrderedHashMap> tmp27;
    TNode<Int32T> tmp28;
    TNode<BoolT> tmp29;
    if (block24.is_used()) {
        ca_.Bind(&block24);
        std::tie(tmp26, tmp27) = NewStableBackingTableWitness_1(state_, TNode<JSMap> { tmp14 }).Flatten();
        tmp28 = LoadOrderedHashTableMetadata_0(state_, TNode<FixedArray> { tmp27 }, OrderedHashMap::NumberOfElementsIndex());
        tmp29 = CodeStubAssembler(state_).Int32LessThanOrEqual(TNode<Int32T> { tmp11 }, TNode<Int32T> { tmp28 });
        ca_.Branch(tmp29, &block27, std::vector<compiler::Node*> {}, &block28, std::vector<compiler::Node*> {});
    }

    TNode<String> tmp30;
    TNode<OrderedHashSet> tmp31;
    if (block27.is_used()) {
        ca_.Bind(&block27);
        tmp30 = FromConstexpr_String_constexpr_string_0(state_, "Set.prototype.intersection");
        tmp31 = FastIntersect_StableJSMapBackingTableWitness_0(state_, TNode<Context> { parameter0 },
            TorqueStructStableJSSetBackingTableWitness_0 { TNode<JSSet> { tmp8 }, TNode<OrderedHashSet> { tmp9 } },
            TorqueStructStableJSMapBackingTableWitness_0 { TNode<JSMap> { tmp26 }, TNode<OrderedHashMap> { tmp27 } }, TNode<String> { tmp30 },
            TNode<OrderedHashSet> { tmp10 });
        ca_.Goto(&block7, tmp9, tmp31);
    }

    TNode<OrderedHashMap> tmp32;
    TNode<Int32T> tmp33;
    TNode<Int32T> tmp34;
    TNode<Object> tmp35;
    TNode<Object> tmp36;
    TNode<IntPtrT> tmp37;
    if (block28.is_used()) {
        ca_.Bind(&block28);
        std::tie(tmp32, tmp33, tmp34, tmp35, tmp36, tmp37) = NewUnmodifiedOrderedHashMapIterator_0(state_, TNode<OrderedHashMap> { tmp27 }).Flatten();
        ca_.Goto(&block33, tmp10, tmp35, tmp36, tmp37);
    }

    TNode<OrderedHashSet> phi_bb33_11;
    TNode<Object> phi_bb33_21;
    TNode<Object> phi_bb33_22;
    TNode<IntPtrT> phi_bb33_23;
    TNode<BoolT> tmp38;
    if (block33.is_used()) {
        ca_.Bind(&block33, &phi_bb33_11, &phi_bb33_21, &phi_bb33_22, &phi_bb33_23);
        tmp38 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp38, &block31, std::vector<compiler::Node*> { phi_bb33_11, phi_bb33_21, phi_bb33_22, phi_bb33_23 }, &block32,
            std::vector<compiler::Node*> { phi_bb33_11, phi_bb33_21, phi_bb33_22, phi_bb33_23 });
    }

    TNode<OrderedHashSet> phi_bb31_11;
    TNode<Object> phi_bb31_21;
    TNode<Object> phi_bb31_22;
    TNode<IntPtrT> phi_bb31_23;
    TNode<Object> tmp39;
    TNode<Object> tmp40;
    TNode<IntPtrT> tmp41;
    if (block31.is_used()) {
        ca_.Bind(&block31, &phi_bb31_11, &phi_bb31_21, &phi_bb31_22, &phi_bb31_23);
        compiler::CodeAssemblerLabel label42(&ca_);
        std::tie(tmp39, tmp40, tmp41) = CollectionsBuiltinsAssembler(state_)
                                            .NextKeyValueIndexTupleUnmodifiedTable(TNode<OrderedHashMap> { tmp32 }, TNode<Int32T> { tmp33 },
                                                TNode<Int32T> { tmp34 }, TNode<IntPtrT> { phi_bb31_23 }, &label42)
                                            .Flatten();
        ca_.Goto(&block35, phi_bb31_11, phi_bb31_21, phi_bb31_22, phi_bb31_23, phi_bb31_23);
        if (label42.is_used()) {
            ca_.Bind(&label42);
            ca_.Goto(&block36, phi_bb31_11, phi_bb31_21, phi_bb31_22, phi_bb31_23, phi_bb31_23);
        }
    }

    TNode<OrderedHashSet> phi_bb36_11;
    TNode<Object> phi_bb36_21;
    TNode<Object> phi_bb36_22;
    TNode<IntPtrT> phi_bb36_23;
    TNode<IntPtrT> phi_bb36_27;
    if (block36.is_used()) {
        ca_.Bind(&block36, &phi_bb36_11, &phi_bb36_21, &phi_bb36_22, &phi_bb36_23, &phi_bb36_27);
        ca_.Goto(&block7, tmp9, phi_bb36_11);
    }

    TNode<OrderedHashSet> phi_bb35_11;
    TNode<Object> phi_bb35_21;
    TNode<Object> phi_bb35_22;
    TNode<IntPtrT> phi_bb35_23;
    TNode<IntPtrT> phi_bb35_27;
    TNode<BoolT> tmp43;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_11, &phi_bb35_21, &phi_bb35_22, &phi_bb35_23, &phi_bb35_27);
        tmp43 = CollectionsBuiltinsAssembler(state_).TableHasKey(TNode<Context> { parameter0 }, TNode<OrderedHashSet> { tmp9 }, TNode<Object> { tmp39 });
        ca_.Branch(tmp43, &block37, std::vector<compiler::Node*> { phi_bb35_11 }, &block38, std::vector<compiler::Node*> { phi_bb35_11 });
    }

    TNode<OrderedHashSet> phi_bb37_11;
    TNode<String> tmp44;
    TNode<OrderedHashSet> tmp45;
    if (block37.is_used()) {
        ca_.Bind(&block37, &phi_bb37_11);
        tmp44 = FromConstexpr_String_constexpr_string_0(state_, "Set.prototype.intersection");
        tmp45 = CollectionsBuiltinsAssembler(state_).AddToSetTable(
            TNode<Context> { parameter0 }, TNode<OrderedHashSet> { phi_bb37_11 }, TNode<Object> { tmp39 }, TNode<String> { tmp44 });
        ca_.Goto(&block38, tmp45);
    }

    TNode<OrderedHashSet> phi_bb38_11;
    if (block38.is_used()) {
        ca_.Bind(&block38, &phi_bb38_11);
        ca_.Goto(&block33, phi_bb38_11, tmp39, tmp40, tmp41);
    }

    TNode<OrderedHashSet> phi_bb32_11;
    TNode<Object> phi_bb32_21;
    TNode<Object> phi_bb32_22;
    TNode<IntPtrT> phi_bb32_23;
    if (block32.is_used()) {
        ca_.Bind(&block32, &phi_bb32_11, &phi_bb32_21, &phi_bb32_22, &phi_bb32_23);
        ca_.Goto(&block8, tmp9, phi_bb32_11);
    }

    TNode<Number> tmp46;
    TNode<BoolT> tmp47;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp46 = Convert_Number_int32_0(state_, TNode<Int32T> { tmp11 });
        tmp47 = NumberIsLessThanOrEqual_0(state_, TNode<Number> { tmp46 }, TNode<Number> { tmp5 });
        ca_.Branch(tmp47, &block40, std::vector<compiler::Node*> {}, &block41, std::vector<compiler::Node*> {});
    }

    TNode<OrderedHashSet> tmp48;
    TNode<Object> tmp49;
    TNode<IntPtrT> tmp50;
    if (block40.is_used()) {
        ca_.Bind(&block40);
        std::tie(tmp48, tmp49, tmp50) = NewOrderedHashSetIterator_0(state_, TNode<OrderedHashSet> { tmp9 }).Flatten();
        ca_.Goto(&block46, tmp10, tmp48, tmp49, tmp50);
    }

    TNode<OrderedHashSet> phi_bb46_11;
    TNode<OrderedHashSet> phi_bb46_13;
    TNode<Object> phi_bb46_14;
    TNode<IntPtrT> phi_bb46_15;
    TNode<BoolT> tmp51;
    if (block46.is_used()) {
        ca_.Bind(&block46, &phi_bb46_11, &phi_bb46_13, &phi_bb46_14, &phi_bb46_15);
        tmp51 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp51, &block44, std::vector<compiler::Node*> { phi_bb46_11, phi_bb46_13, phi_bb46_14, phi_bb46_15 }, &block45,
            std::vector<compiler::Node*> { phi_bb46_11, phi_bb46_13, phi_bb46_14, phi_bb46_15 });
    }

    TNode<OrderedHashSet> phi_bb44_11;
    TNode<OrderedHashSet> phi_bb44_13;
    TNode<Object> phi_bb44_14;
    TNode<IntPtrT> phi_bb44_15;
    TNode<OrderedHashSet> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<Object> tmp54;
    TNode<IntPtrT> tmp55;
    if (block44.is_used()) {
        ca_.Bind(&block44, &phi_bb44_11, &phi_bb44_13, &phi_bb44_14, &phi_bb44_15);
        std::tie(tmp52, tmp53) = CollectionsBuiltinsAssembler(state_)
                                     .TransitionOrderedHashSetNoUpdate(TNode<OrderedHashSet> { phi_bb44_13 }, TNode<IntPtrT> { phi_bb44_15 })
                                     .Flatten();
        compiler::CodeAssemblerLabel label56(&ca_);
        std::tie(tmp54, tmp55)
            = CollectionsBuiltinsAssembler(state_).NextKeyIndexPair(TNode<OrderedHashSet> { tmp52 }, TNode<IntPtrT> { tmp53 }, &label56).Flatten();
        ca_.Goto(&block48, phi_bb44_11, phi_bb44_14);
        if (label56.is_used()) {
            ca_.Bind(&label56);
            ca_.Goto(&block49, phi_bb44_11, phi_bb44_14);
        }
    }

    TNode<OrderedHashSet> phi_bb49_11;
    TNode<Object> phi_bb49_14;
    if (block49.is_used()) {
        ca_.Bind(&block49, &phi_bb49_11, &phi_bb49_14);
        ca_.Goto(&block7, tmp9, phi_bb49_11);
    }

    TNode<OrderedHashSet> phi_bb48_11;
    TNode<Object> phi_bb48_14;
    TNode<Object> tmp57;
    TNode<BoolT> tmp58;
    if (block48.is_used()) {
        ca_.Bind(&block48, &phi_bb48_11, &phi_bb48_14);
        tmp57 = CodeStubAssembler(state_).Call(TNode<Context> { parameter0 }, TNode<Object> { tmp6 }, TNode<Object> { tmp4 }, TNode<Object> { tmp54 });
        tmp58 = ToBoolean_0(state_, TNode<Object> { tmp57 });
        ca_.Branch(tmp58, &block50, std::vector<compiler::Node*> { phi_bb48_11 }, &block51, std::vector<compiler::Node*> { phi_bb48_11 });
    }

    TNode<OrderedHashSet> phi_bb50_11;
    TNode<String> tmp59;
    TNode<OrderedHashSet> tmp60;
    if (block50.is_used()) {
        ca_.Bind(&block50, &phi_bb50_11);
        tmp59 = FromConstexpr_String_constexpr_string_0(state_, "Set.prototype.intersection");
        tmp60 = CollectionsBuiltinsAssembler(state_).AddToSetTable(
            TNode<Context> { parameter0 }, TNode<OrderedHashSet> { phi_bb50_11 }, TNode<Object> { tmp54 }, TNode<String> { tmp59 });
        ca_.Goto(&block51, tmp60);
    }

    TNode<OrderedHashSet> phi_bb51_11;
    if (block51.is_used()) {
        ca_.Bind(&block51, &phi_bb51_11);
        ca_.Goto(&block46, phi_bb51_11, tmp52, tmp54, tmp55);
    }

    TNode<OrderedHashSet> phi_bb45_11;
    TNode<OrderedHashSet> phi_bb45_13;
    TNode<Object> phi_bb45_14;
    TNode<IntPtrT> phi_bb45_15;
    if (block45.is_used()) {
        ca_.Bind(&block45, &phi_bb45_11, &phi_bb45_13, &phi_bb45_14, &phi_bb45_15);
        ca_.Goto(&block42, tmp9, phi_bb45_11);
    }

    TNode<JSReceiver> tmp61;
    TNode<JSReceiver> tmp62;
    TNode<Object> tmp63;
    if (block41.is_used()) {
        ca_.Bind(&block41);
        tmp61 = UnsafeCast_Callable_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp7 });
        std::tie(tmp62, tmp63) = GetKeysIterator_0(state_, TNode<Context> { parameter0 }, TNode<JSReceiver> { tmp4 }, TNode<JSReceiver> { tmp61 }).Flatten();
        ca_.Goto(&block54, tmp9, tmp10, ca_.Uninitialized<JSReceiver>());
    }

    TNode<OrderedHashSet> phi_bb54_10;
    TNode<OrderedHashSet> phi_bb54_11;
    TNode<JSReceiver> phi_bb54_15;
    TNode<BoolT> tmp64;
    if (block54.is_used()) {
        ca_.Bind(&block54, &phi_bb54_10, &phi_bb54_11, &phi_bb54_15);
        tmp64 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp64, &block52, std::vector<compiler::Node*> { phi_bb54_10, phi_bb54_11, phi_bb54_15 }, &block53,
            std::vector<compiler::Node*> { phi_bb54_10, phi_bb54_11, phi_bb54_15 });
    }

    TNode<OrderedHashSet> phi_bb52_10;
    TNode<OrderedHashSet> phi_bb52_11;
    TNode<JSReceiver> phi_bb52_15;
    TNode<JSReceiver> tmp65;
    if (block52.is_used()) {
        ca_.Bind(&block52, &phi_bb52_10, &phi_bb52_11, &phi_bb52_15);
        compiler::CodeAssemblerLabel label66(&ca_);
        tmp65 = IteratorBuiltinsAssembler(state_).IteratorStep(
            TNode<Context> { parameter0 }, TorqueStructIteratorRecord { TNode<JSReceiver> { tmp62 }, TNode<Object> { tmp63 } }, TNode<Map> { tmp0 }, &label66);
        ca_.Goto(&block55, phi_bb52_10, phi_bb52_11, phi_bb52_15);
        if (label66.is_used()) {
            ca_.Bind(&label66);
            ca_.Goto(&block56, phi_bb52_10, phi_bb52_11, phi_bb52_15);
        }
    }

    TNode<OrderedHashSet> phi_bb56_10;
    TNode<OrderedHashSet> phi_bb56_11;
    TNode<JSReceiver> phi_bb56_15;
    if (block56.is_used()) {
        ca_.Bind(&block56, &phi_bb56_10, &phi_bb56_11, &phi_bb56_15);
        ca_.Goto(&block7, phi_bb56_10, phi_bb56_11);
    }

    TNode<OrderedHashSet> phi_bb55_10;
    TNode<OrderedHashSet> phi_bb55_11;
    TNode<JSReceiver> phi_bb55_15;
    TNode<Object> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<Object> tmp69;
    TNode<HeapObject> tmp70;
    if (block55.is_used()) {
        ca_.Bind(&block55, &phi_bb55_10, &phi_bb55_11, &phi_bb55_15);
        tmp67 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context> { parameter0 }, TNode<JSReceiver> { tmp65 }, TNode<Map> { tmp0 });
        tmp68 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp69 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp8, tmp68 });
        compiler::CodeAssemblerLabel label71(&ca_);
        tmp70 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object> { tmp69 }, &label71);
        ca_.Goto(&block61, phi_bb55_10, phi_bb55_11);
        if (label71.is_used()) {
            ca_.Bind(&label71);
            ca_.Goto(&block62, phi_bb55_10, phi_bb55_11);
        }
    }

    TNode<OrderedHashSet> phi_bb62_10;
    TNode<OrderedHashSet> phi_bb62_11;
    if (block62.is_used()) {
        ca_.Bind(&block62, &phi_bb62_10, &phi_bb62_11);
        ca_.Goto(&block59, phi_bb62_10, phi_bb62_11);
    }

    TNode<OrderedHashSet> phi_bb61_10;
    TNode<OrderedHashSet> phi_bb61_11;
    TNode<OrderedHashSet> tmp72;
    if (block61.is_used()) {
        ca_.Bind(&block61, &phi_bb61_10, &phi_bb61_11);
        compiler::CodeAssemblerLabel label73(&ca_);
        tmp72 = Cast_OrderedHashSet_0(state_, TNode<HeapObject> { tmp70 }, &label73);
        ca_.Goto(&block64, phi_bb61_10, phi_bb61_11);
        if (label73.is_used()) {
            ca_.Bind(&label73);
            ca_.Goto(&block65, phi_bb61_10, phi_bb61_11);
        }
    }

    TNode<OrderedHashSet> phi_bb65_10;
    TNode<OrderedHashSet> phi_bb65_11;
    if (block65.is_used()) {
        ca_.Bind(&block65, &phi_bb65_10, &phi_bb65_11);
        ca_.Goto(&block59, phi_bb65_10, phi_bb65_11);
    }

    TNode<OrderedHashSet> phi_bb64_10;
    TNode<OrderedHashSet> phi_bb64_11;
    TNode<OrderedHashSet> tmp74;
    TNode<BoolT> tmp75;
    if (block64.is_used()) {
        ca_.Bind(&block64, &phi_bb64_10, &phi_bb64_11);
        tmp74 = (TNode<OrderedHashSet> { tmp72 });
        tmp75 = CollectionsBuiltinsAssembler(state_).TableHasKey(TNode<Context> { parameter0 }, TNode<OrderedHashSet> { tmp74 }, TNode<Object> { tmp67 });
        ca_.Branch(tmp75, &block66, std::vector<compiler::Node*> { phi_bb64_11 }, &block67, std::vector<compiler::Node*> { phi_bb64_11 });
    }

    TNode<OrderedHashSet> phi_bb59_10;
    TNode<OrderedHashSet> phi_bb59_11;
    if (block59.is_used()) {
        ca_.Bind(&block59, &phi_bb59_10, &phi_bb59_11);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<OrderedHashSet> phi_bb66_11;
    TNode<String> tmp76;
    TNode<OrderedHashSet> tmp77;
    if (block66.is_used()) {
        ca_.Bind(&block66, &phi_bb66_11);
        tmp76 = FromConstexpr_String_constexpr_string_0(state_, "Set.prototype.intersection");
        tmp77 = CollectionsBuiltinsAssembler(state_).AddToSetTable(
            TNode<Context> { parameter0 }, TNode<OrderedHashSet> { phi_bb66_11 }, TNode<Object> { tmp67 }, TNode<String> { tmp76 });
        ca_.Goto(&block67, tmp77);
    }

    TNode<OrderedHashSet> phi_bb67_11;
    if (block67.is_used()) {
        ca_.Bind(&block67, &phi_bb67_11);
        ca_.Goto(&block54, tmp74, phi_bb67_11, tmp65);
    }

    TNode<OrderedHashSet> phi_bb53_10;
    TNode<OrderedHashSet> phi_bb53_11;
    TNode<JSReceiver> phi_bb53_15;
    if (block53.is_used()) {
        ca_.Bind(&block53, &phi_bb53_10, &phi_bb53_11, &phi_bb53_15);
        ca_.Goto(&block42, phi_bb53_10, phi_bb53_11);
    }

    TNode<OrderedHashSet> phi_bb42_10;
    TNode<OrderedHashSet> phi_bb42_11;
    if (block42.is_used()) {
        ca_.Bind(&block42, &phi_bb42_10, &phi_bb42_11);
        ca_.Goto(&block8, phi_bb42_10, phi_bb42_11);
    }

    TNode<OrderedHashSet> phi_bb8_10;
    TNode<OrderedHashSet> phi_bb8_11;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_10, &phi_bb8_11);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<OrderedHashSet> phi_bb7_10;
    TNode<OrderedHashSet> phi_bb7_11;
    TNode<IntPtrT> tmp78;
    TNode<Object> tmp79;
    TNode<IntPtrT> tmp80;
    TNode<Map> tmp81;
    TNode<FixedArray> tmp82;
    TNode<FixedArray> tmp83;
    TNode<BoolT> tmp84;
    TNode<BoolT> tmp85;
    TNode<IntPtrT> tmp86;
    TNode<HeapObject> tmp87;
    TNode<IntPtrT> tmp88;
    TNode<IntPtrT> tmp89;
    TNode<IntPtrT> tmp90;
    TNode<IntPtrT> tmp91;
    TNode<JSSet> tmp92;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_10, &phi_bb7_11);
        tmp78 = JS_SET_MAP_INDEX_0(state_);
        std::tie(tmp79, tmp80) = NativeContextSlot_NativeContext_Map_0(state_, TNode<NativeContext> { parameter0 }, TNode<IntPtrT> { tmp78 }).Flatten();
        tmp81 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { tmp79, tmp80 });
        tmp82 = kEmptyFixedArray_0(state_);
        tmp83 = kEmptyFixedArray_0(state_);
        tmp84 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        tmp85 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        tmp86 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp87 = AllocateFromNew_0(state_, TNode<IntPtrT> { tmp86 }, TNode<Map> { tmp81 }, TNode<BoolT> { tmp84 }, TNode<BoolT> { tmp85 });
        tmp88 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference { tmp87, tmp88 }, tmp81);
        tmp89 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp87, tmp89 }, tmp82);
        tmp90 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference { tmp87, tmp90 }, tmp83);
        tmp91 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp87, tmp91 }, phi_bb7_11);
        tmp92 = TORQUE_CAST(TNode<HeapObject> { tmp87 });
        CodeStubAssembler(state_).Return(tmp92);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/set-intersection.tq?l=40&c=27
TNode<OrderedHashSet> FastIntersect_StableJSSetBackingTableWitness_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context,
    TorqueStructStableJSSetBackingTableWitness_0 p_collectionToIterate, TorqueStructStableJSSetBackingTableWitness_0 p_tableToLookup,
    TNode<String> p_methodName, TNode<OrderedHashSet> p_resultSetData)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<OrderedHashSet> tmp0;
    TNode<Int32T> tmp1;
    TNode<Int32T> tmp2;
    TNode<Object> tmp3;
    TNode<IntPtrT> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1, tmp2, tmp3, tmp4)
            = NewUnmodifiedOrderedHashSetIterator_0(state_, TNode<OrderedHashSet> { p_collectionToIterate.unstable }).Flatten();
        ca_.Goto(&block7, p_resultSetData, tmp3, tmp4);
    }

    TNode<OrderedHashSet> phi_bb7_7;
    TNode<Object> phi_bb7_11;
    TNode<IntPtrT> phi_bb7_12;
    TNode<BoolT> tmp5;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_7, &phi_bb7_11, &phi_bb7_12);
        tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp5, &block5, std::vector<compiler::Node*> { phi_bb7_7, phi_bb7_11, phi_bb7_12 }, &block6,
            std::vector<compiler::Node*> { phi_bb7_7, phi_bb7_11, phi_bb7_12 });
    }

    TNode<OrderedHashSet> phi_bb5_7;
    TNode<Object> phi_bb5_11;
    TNode<IntPtrT> phi_bb5_12;
    TNode<Object> tmp6;
    TNode<IntPtrT> tmp7;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_7, &phi_bb5_11, &phi_bb5_12);
        compiler::CodeAssemblerLabel label8(&ca_);
        std::tie(tmp6, tmp7) = CollectionsBuiltinsAssembler(state_)
                                   .NextKeyIndexPairUnmodifiedTable(
                                       TNode<OrderedHashSet> { tmp0 }, TNode<Int32T> { tmp1 }, TNode<Int32T> { tmp2 }, TNode<IntPtrT> { phi_bb5_12 }, &label8)
                                   .Flatten();
        ca_.Goto(&block9, phi_bb5_7, phi_bb5_11, phi_bb5_12, phi_bb5_12);
        if (label8.is_used()) {
            ca_.Bind(&label8);
            ca_.Goto(&block10, phi_bb5_7, phi_bb5_11, phi_bb5_12, phi_bb5_12);
        }
    }

    TNode<OrderedHashSet> phi_bb10_7;
    TNode<Object> phi_bb10_11;
    TNode<IntPtrT> phi_bb10_12;
    TNode<IntPtrT> phi_bb10_16;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_7, &phi_bb10_11, &phi_bb10_12, &phi_bb10_16);
        ca_.Goto(&block14, phi_bb10_7);
    }

    TNode<OrderedHashSet> phi_bb9_7;
    TNode<Object> phi_bb9_11;
    TNode<IntPtrT> phi_bb9_12;
    TNode<IntPtrT> phi_bb9_16;
    TNode<BoolT> tmp9;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_7, &phi_bb9_11, &phi_bb9_12, &phi_bb9_16);
        tmp9 = CollectionsBuiltinsAssembler(state_).TableHasKey(
            TNode<Context> { p_context }, TNode<OrderedHashSet> { p_tableToLookup.unstable }, TNode<Object> { tmp6 });
        ca_.Branch(tmp9, &block11, std::vector<compiler::Node*> { phi_bb9_7 }, &block12, std::vector<compiler::Node*> { phi_bb9_7 });
    }

    TNode<OrderedHashSet> phi_bb11_7;
    TNode<OrderedHashSet> tmp10;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_7);
        tmp10 = CollectionsBuiltinsAssembler(state_).AddToSetTable(
            TNode<Context> { p_context }, TNode<OrderedHashSet> { phi_bb11_7 }, TNode<Object> { tmp6 }, TNode<String> { p_methodName });
        ca_.Goto(&block12, tmp10);
    }

    TNode<OrderedHashSet> phi_bb12_7;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_7);
        ca_.Goto(&block7, phi_bb12_7, tmp6, tmp7);
    }

    TNode<OrderedHashSet> phi_bb6_7;
    TNode<Object> phi_bb6_11;
    TNode<IntPtrT> phi_bb6_12;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_7, &phi_bb6_11, &phi_bb6_12);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<OrderedHashSet> phi_bb14_7;
    ca_.Bind(&block14, &phi_bb14_7);
    return TNode<OrderedHashSet> { phi_bb14_7 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/set-intersection.tq?l=58&c=27
TNode<OrderedHashSet> FastIntersect_StableJSMapBackingTableWitness_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context,
    TorqueStructStableJSSetBackingTableWitness_0 p_collectionToIterate, TorqueStructStableJSMapBackingTableWitness_0 p_tableToLookup,
    TNode<String> p_methodName, TNode<OrderedHashSet> p_resultSetData)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<OrderedHashSet> tmp0;
    TNode<Int32T> tmp1;
    TNode<Int32T> tmp2;
    TNode<Object> tmp3;
    TNode<IntPtrT> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1, tmp2, tmp3, tmp4)
            = NewUnmodifiedOrderedHashSetIterator_0(state_, TNode<OrderedHashSet> { p_collectionToIterate.unstable }).Flatten();
        ca_.Goto(&block7, p_resultSetData, tmp3, tmp4);
    }

    TNode<OrderedHashSet> phi_bb7_7;
    TNode<Object> phi_bb7_11;
    TNode<IntPtrT> phi_bb7_12;
    TNode<BoolT> tmp5;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_7, &phi_bb7_11, &phi_bb7_12);
        tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp5, &block5, std::vector<compiler::Node*> { phi_bb7_7, phi_bb7_11, phi_bb7_12 }, &block6,
            std::vector<compiler::Node*> { phi_bb7_7, phi_bb7_11, phi_bb7_12 });
    }

    TNode<OrderedHashSet> phi_bb5_7;
    TNode<Object> phi_bb5_11;
    TNode<IntPtrT> phi_bb5_12;
    TNode<Object> tmp6;
    TNode<IntPtrT> tmp7;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_7, &phi_bb5_11, &phi_bb5_12);
        compiler::CodeAssemblerLabel label8(&ca_);
        std::tie(tmp6, tmp7) = CollectionsBuiltinsAssembler(state_)
                                   .NextKeyIndexPairUnmodifiedTable(
                                       TNode<OrderedHashSet> { tmp0 }, TNode<Int32T> { tmp1 }, TNode<Int32T> { tmp2 }, TNode<IntPtrT> { phi_bb5_12 }, &label8)
                                   .Flatten();
        ca_.Goto(&block9, phi_bb5_7, phi_bb5_11, phi_bb5_12, phi_bb5_12);
        if (label8.is_used()) {
            ca_.Bind(&label8);
            ca_.Goto(&block10, phi_bb5_7, phi_bb5_11, phi_bb5_12, phi_bb5_12);
        }
    }

    TNode<OrderedHashSet> phi_bb10_7;
    TNode<Object> phi_bb10_11;
    TNode<IntPtrT> phi_bb10_12;
    TNode<IntPtrT> phi_bb10_16;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_7, &phi_bb10_11, &phi_bb10_12, &phi_bb10_16);
        ca_.Goto(&block14, phi_bb10_7);
    }

    TNode<OrderedHashSet> phi_bb9_7;
    TNode<Object> phi_bb9_11;
    TNode<IntPtrT> phi_bb9_12;
    TNode<IntPtrT> phi_bb9_16;
    TNode<BoolT> tmp9;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_7, &phi_bb9_11, &phi_bb9_12, &phi_bb9_16);
        tmp9 = CollectionsBuiltinsAssembler(state_).TableHasKey(
            TNode<Context> { p_context }, TNode<OrderedHashMap> { p_tableToLookup.unstable }, TNode<Object> { tmp6 });
        ca_.Branch(tmp9, &block11, std::vector<compiler::Node*> { phi_bb9_7 }, &block12, std::vector<compiler::Node*> { phi_bb9_7 });
    }

    TNode<OrderedHashSet> phi_bb11_7;
    TNode<OrderedHashSet> tmp10;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_7);
        tmp10 = CollectionsBuiltinsAssembler(state_).AddToSetTable(
            TNode<Context> { p_context }, TNode<OrderedHashSet> { phi_bb11_7 }, TNode<Object> { tmp6 }, TNode<String> { p_methodName });
        ca_.Goto(&block12, tmp10);
    }

    TNode<OrderedHashSet> phi_bb12_7;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_7);
        ca_.Goto(&block7, phi_bb12_7, tmp6, tmp7);
    }

    TNode<OrderedHashSet> phi_bb6_7;
    TNode<Object> phi_bb6_11;
    TNode<IntPtrT> phi_bb6_12;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_7, &phi_bb6_11, &phi_bb6_12);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<OrderedHashSet> phi_bb14_7;
    ca_.Bind(&block14, &phi_bb14_7);
    return TNode<OrderedHashSet> { phi_bb14_7 };
}

} // namespace internal
} // namespace v8
