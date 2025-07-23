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
#include "torque-generated/src/builtins/set-is-disjoint-from-tq-csa.h"
#include "torque-generated/src/builtins/array-from-async-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/collections-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/set-difference-tq-csa.h"
#include "torque-generated/src/builtins/set-is-disjoint-from-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(SetPrototypeIsDisjointFrom, CodeStubAssembler)
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
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT, IntPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, JSReceiver> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, JSReceiver> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, JSReceiver> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, JSReceiver> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, JSReceiver> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
        tmp3 = FromConstexpr_Object_constexpr_string_0(state_, "Set.prototype.isDisjointFrom");
        CodeStubAssembler(state_).ThrowTypeError(
            TNode<Context> { parameter0 }, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object> { tmp3 }, TNode<Object> { parameter1 });
    }

    TNode<JSReceiver> tmp4;
    TNode<Number> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<JSSet> tmp8;
    TNode<OrderedHashSet> tmp9;
    TNode<Int32T> tmp10;
    TNode<JSSet> tmp11;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        std::tie(tmp4, tmp5, tmp6, tmp7)
            = GetSetRecord_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, "Set.prototype.isDisjointFrom").Flatten();
        std::tie(tmp8, tmp9) = NewStableBackingTableWitness_0(state_, TNode<JSSet> { tmp1 }).Flatten();
        tmp10 = LoadOrderedHashTableMetadata_0(state_, TNode<FixedArray> { tmp9 }, OrderedHashSet::NumberOfElementsIndex());
        compiler::CodeAssemblerLabel label12(&ca_);
        tmp11 = Cast_JSSetWithNoCustomIteration_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, &label12);
        ca_.Goto(&block12);
        if (label12.is_used()) {
            ca_.Bind(&label12);
            ca_.Goto(&block13);
        }
    }

    TNode<JSMap> tmp13;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        compiler::CodeAssemblerLabel label14(&ca_);
        tmp13 = Cast_JSMapWithNoCustomIteration_1(state_, TNode<Context> { parameter0 }, TNode<Object> { ca_.UncheckedCast<Object>(parameter2) }, &label14);
        ca_.Goto(&block21);
        if (label14.is_used()) {
            ca_.Bind(&label14);
            ca_.Goto(&block22);
        }
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        compiler::CodeAssemblerLabel label15(&ca_);
        CheckSetRecordHasJSSetMethods_0(
            state_, TorqueStructSetRecord { TNode<JSReceiver> { tmp4 }, TNode<Number> { tmp5 }, TNode<Object> { tmp6 }, TNode<Object> { tmp7 } }, &label15);
        ca_.Goto(&block14);
        if (label15.is_used()) {
            ca_.Bind(&label15);
            ca_.Goto(&block15);
        }
    }

    if (block15.is_used()) {
        ca_.Bind(&block15);
        ca_.Goto(&block9);
    }

    TNode<JSSet> tmp16;
    TNode<OrderedHashSet> tmp17;
    TNode<Int32T> tmp18;
    TNode<BoolT> tmp19;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        std::tie(tmp16, tmp17) = NewStableBackingTableWitness_0(state_, TNode<JSSet> { tmp11 }).Flatten();
        tmp18 = LoadOrderedHashTableMetadata_0(state_, TNode<FixedArray> { tmp17 }, OrderedHashSet::NumberOfElementsIndex());
        tmp19 = CodeStubAssembler(state_).Int32LessThanOrEqual(TNode<Int32T> { tmp10 }, TNode<Int32T> { tmp18 });
        ca_.Branch(tmp19, &block17, std::vector<compiler::Node*> {}, &block18, std::vector<compiler::Node*> {});
    }

    TNode<Boolean> tmp20;
    if (block17.is_used()) {
        ca_.Bind(&block17);
        tmp20 = FastIsDisjointFrom_StableJSSetBackingTableWitness_0(state_, TNode<Context> { parameter0 },
            TorqueStructStableJSSetBackingTableWitness_0 { TNode<JSSet> { tmp8 }, TNode<OrderedHashSet> { tmp9 } },
            TorqueStructStableJSSetBackingTableWitness_0 { TNode<JSSet> { tmp16 }, TNode<OrderedHashSet> { tmp17 } });
        CodeStubAssembler(state_).Return(tmp20);
    }

    TNode<Boolean> tmp21;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        tmp21 = FastIsDisjointFrom_StableJSSetBackingTableWitness_0(state_, TNode<Context> { parameter0 },
            TorqueStructStableJSSetBackingTableWitness_0 { TNode<JSSet> { tmp16 }, TNode<OrderedHashSet> { tmp17 } },
            TorqueStructStableJSSetBackingTableWitness_0 { TNode<JSSet> { tmp8 }, TNode<OrderedHashSet> { tmp9 } });
        CodeStubAssembler(state_).Return(tmp21);
    }

    if (block22.is_used()) {
        ca_.Bind(&block22);
        ca_.Goto(&block9);
    }

    if (block21.is_used()) {
        ca_.Bind(&block21);
        compiler::CodeAssemblerLabel label22(&ca_);
        CheckSetRecordHasJSMapMethods_0(
            state_, TorqueStructSetRecord { TNode<JSReceiver> { tmp4 }, TNode<Number> { tmp5 }, TNode<Object> { tmp6 }, TNode<Object> { tmp7 } }, &label22);
        ca_.Goto(&block23);
        if (label22.is_used()) {
            ca_.Bind(&label22);
            ca_.Goto(&block24);
        }
    }

    if (block24.is_used()) {
        ca_.Bind(&block24);
        ca_.Goto(&block9);
    }

    TNode<JSMap> tmp23;
    TNode<OrderedHashMap> tmp24;
    TNode<Int32T> tmp25;
    TNode<BoolT> tmp26;
    if (block23.is_used()) {
        ca_.Bind(&block23);
        std::tie(tmp23, tmp24) = NewStableBackingTableWitness_1(state_, TNode<JSMap> { tmp13 }).Flatten();
        tmp25 = LoadOrderedHashTableMetadata_0(state_, TNode<FixedArray> { tmp24 }, OrderedHashMap::NumberOfElementsIndex());
        tmp26 = CodeStubAssembler(state_).Int32LessThanOrEqual(TNode<Int32T> { tmp10 }, TNode<Int32T> { tmp25 });
        ca_.Branch(tmp26, &block26, std::vector<compiler::Node*> {}, &block27, std::vector<compiler::Node*> {});
    }

    TNode<Boolean> tmp27;
    if (block26.is_used()) {
        ca_.Bind(&block26);
        tmp27 = FastIsDisjointFrom_StableJSMapBackingTableWitness_0(state_, TNode<Context> { parameter0 },
            TorqueStructStableJSSetBackingTableWitness_0 { TNode<JSSet> { tmp8 }, TNode<OrderedHashSet> { tmp9 } },
            TorqueStructStableJSMapBackingTableWitness_0 { TNode<JSMap> { tmp23 }, TNode<OrderedHashMap> { tmp24 } });
        CodeStubAssembler(state_).Return(tmp27);
    }

    TNode<OrderedHashMap> tmp28;
    TNode<Int32T> tmp29;
    TNode<Int32T> tmp30;
    TNode<Object> tmp31;
    TNode<Object> tmp32;
    TNode<IntPtrT> tmp33;
    if (block27.is_used()) {
        ca_.Bind(&block27);
        std::tie(tmp28, tmp29, tmp30, tmp31, tmp32, tmp33) = NewUnmodifiedOrderedHashMapIterator_0(state_, TNode<OrderedHashMap> { tmp24 }).Flatten();
        ca_.Goto(&block31, tmp31, tmp32, tmp33);
    }

    TNode<Object> phi_bb31_20;
    TNode<Object> phi_bb31_21;
    TNode<IntPtrT> phi_bb31_22;
    TNode<BoolT> tmp34;
    if (block31.is_used()) {
        ca_.Bind(&block31, &phi_bb31_20, &phi_bb31_21, &phi_bb31_22);
        tmp34 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp34, &block29, std::vector<compiler::Node*> { phi_bb31_20, phi_bb31_21, phi_bb31_22 }, &block30,
            std::vector<compiler::Node*> { phi_bb31_20, phi_bb31_21, phi_bb31_22 });
    }

    TNode<Object> phi_bb29_20;
    TNode<Object> phi_bb29_21;
    TNode<IntPtrT> phi_bb29_22;
    TNode<Object> tmp35;
    TNode<Object> tmp36;
    TNode<IntPtrT> tmp37;
    if (block29.is_used()) {
        ca_.Bind(&block29, &phi_bb29_20, &phi_bb29_21, &phi_bb29_22);
        compiler::CodeAssemblerLabel label38(&ca_);
        std::tie(tmp35, tmp36, tmp37) = CollectionsBuiltinsAssembler(state_)
                                            .NextKeyValueIndexTupleUnmodifiedTable(TNode<OrderedHashMap> { tmp28 }, TNode<Int32T> { tmp29 },
                                                TNode<Int32T> { tmp30 }, TNode<IntPtrT> { phi_bb29_22 }, &label38)
                                            .Flatten();
        ca_.Goto(&block33, phi_bb29_20, phi_bb29_21, phi_bb29_22, phi_bb29_22);
        if (label38.is_used()) {
            ca_.Bind(&label38);
            ca_.Goto(&block34, phi_bb29_20, phi_bb29_21, phi_bb29_22, phi_bb29_22);
        }
    }

    TNode<Object> phi_bb34_20;
    TNode<Object> phi_bb34_21;
    TNode<IntPtrT> phi_bb34_22;
    TNode<IntPtrT> phi_bb34_26;
    if (block34.is_used()) {
        ca_.Bind(&block34, &phi_bb34_20, &phi_bb34_21, &phi_bb34_22, &phi_bb34_26);
        ca_.Goto(&block7, tmp9);
    }

    TNode<Object> phi_bb33_20;
    TNode<Object> phi_bb33_21;
    TNode<IntPtrT> phi_bb33_22;
    TNode<IntPtrT> phi_bb33_26;
    TNode<BoolT> tmp39;
    if (block33.is_used()) {
        ca_.Bind(&block33, &phi_bb33_20, &phi_bb33_21, &phi_bb33_22, &phi_bb33_26);
        tmp39 = CollectionsBuiltinsAssembler(state_).TableHasKey(TNode<Context> { parameter0 }, TNode<OrderedHashSet> { tmp9 }, TNode<Object> { tmp35 });
        ca_.Branch(tmp39, &block35, std::vector<compiler::Node*> {}, &block36, std::vector<compiler::Node*> {});
    }

    TNode<False> tmp40;
    if (block35.is_used()) {
        ca_.Bind(&block35);
        tmp40 = False_0(state_);
        CodeStubAssembler(state_).Return(tmp40);
    }

    if (block36.is_used()) {
        ca_.Bind(&block36);
        ca_.Goto(&block31, tmp35, tmp36, tmp37);
    }

    TNode<Object> phi_bb30_20;
    TNode<Object> phi_bb30_21;
    TNode<IntPtrT> phi_bb30_22;
    if (block30.is_used()) {
        ca_.Bind(&block30, &phi_bb30_20, &phi_bb30_21, &phi_bb30_22);
        ca_.Goto(&block8, tmp9);
    }

    TNode<Number> tmp41;
    TNode<BoolT> tmp42;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp41 = Convert_Number_int32_0(state_, TNode<Int32T> { tmp10 });
        tmp42 = NumberIsLessThanOrEqual_0(state_, TNode<Number> { tmp41 }, TNode<Number> { tmp5 });
        ca_.Branch(tmp42, &block38, std::vector<compiler::Node*> {}, &block39, std::vector<compiler::Node*> {});
    }

    TNode<OrderedHashSet> tmp43;
    TNode<Object> tmp44;
    TNode<IntPtrT> tmp45;
    if (block38.is_used()) {
        ca_.Bind(&block38);
        std::tie(tmp43, tmp44, tmp45) = NewOrderedHashSetIterator_0(state_, TNode<OrderedHashSet> { tmp9 }).Flatten();
        ca_.Goto(&block44, tmp43, tmp44, tmp45);
    }

    TNode<OrderedHashSet> phi_bb44_12;
    TNode<Object> phi_bb44_13;
    TNode<IntPtrT> phi_bb44_14;
    TNode<BoolT> tmp46;
    if (block44.is_used()) {
        ca_.Bind(&block44, &phi_bb44_12, &phi_bb44_13, &phi_bb44_14);
        tmp46 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp46, &block42, std::vector<compiler::Node*> { phi_bb44_12, phi_bb44_13, phi_bb44_14 }, &block43,
            std::vector<compiler::Node*> { phi_bb44_12, phi_bb44_13, phi_bb44_14 });
    }

    TNode<OrderedHashSet> phi_bb42_12;
    TNode<Object> phi_bb42_13;
    TNode<IntPtrT> phi_bb42_14;
    TNode<OrderedHashSet> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<Object> tmp49;
    TNode<IntPtrT> tmp50;
    if (block42.is_used()) {
        ca_.Bind(&block42, &phi_bb42_12, &phi_bb42_13, &phi_bb42_14);
        std::tie(tmp47, tmp48) = CollectionsBuiltinsAssembler(state_)
                                     .TransitionOrderedHashSetNoUpdate(TNode<OrderedHashSet> { phi_bb42_12 }, TNode<IntPtrT> { phi_bb42_14 })
                                     .Flatten();
        compiler::CodeAssemblerLabel label51(&ca_);
        std::tie(tmp49, tmp50)
            = CollectionsBuiltinsAssembler(state_).NextKeyIndexPair(TNode<OrderedHashSet> { tmp47 }, TNode<IntPtrT> { tmp48 }, &label51).Flatten();
        ca_.Goto(&block46, phi_bb42_13);
        if (label51.is_used()) {
            ca_.Bind(&label51);
            ca_.Goto(&block47, phi_bb42_13);
        }
    }

    TNode<Object> phi_bb47_13;
    if (block47.is_used()) {
        ca_.Bind(&block47, &phi_bb47_13);
        ca_.Goto(&block7, tmp9);
    }

    TNode<Object> phi_bb46_13;
    TNode<Object> tmp52;
    TNode<BoolT> tmp53;
    if (block46.is_used()) {
        ca_.Bind(&block46, &phi_bb46_13);
        tmp52 = CodeStubAssembler(state_).Call(TNode<Context> { parameter0 }, TNode<Object> { tmp6 }, TNode<Object> { tmp4 }, TNode<Object> { tmp49 });
        tmp53 = ToBoolean_0(state_, TNode<Object> { tmp52 });
        ca_.Branch(tmp53, &block48, std::vector<compiler::Node*> {}, &block49, std::vector<compiler::Node*> {});
    }

    TNode<False> tmp54;
    if (block48.is_used()) {
        ca_.Bind(&block48);
        tmp54 = False_0(state_);
        CodeStubAssembler(state_).Return(tmp54);
    }

    if (block49.is_used()) {
        ca_.Bind(&block49);
        ca_.Goto(&block44, tmp47, tmp49, tmp50);
    }

    TNode<OrderedHashSet> phi_bb43_12;
    TNode<Object> phi_bb43_13;
    TNode<IntPtrT> phi_bb43_14;
    if (block43.is_used()) {
        ca_.Bind(&block43, &phi_bb43_12, &phi_bb43_13, &phi_bb43_14);
        ca_.Goto(&block40, tmp9);
    }

    TNode<JSReceiver> tmp55;
    TNode<JSReceiver> tmp56;
    TNode<Object> tmp57;
    if (block39.is_used()) {
        ca_.Bind(&block39);
        tmp55 = UnsafeCast_Callable_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp7 });
        std::tie(tmp56, tmp57) = GetKeysIterator_0(state_, TNode<Context> { parameter0 }, TNode<JSReceiver> { tmp4 }, TNode<JSReceiver> { tmp55 }).Flatten();
        ca_.Goto(&block52, tmp9, ca_.Uninitialized<JSReceiver>());
    }

    TNode<OrderedHashSet> phi_bb52_10;
    TNode<JSReceiver> phi_bb52_14;
    TNode<BoolT> tmp58;
    if (block52.is_used()) {
        ca_.Bind(&block52, &phi_bb52_10, &phi_bb52_14);
        tmp58 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(
            tmp58, &block50, std::vector<compiler::Node*> { phi_bb52_10, phi_bb52_14 }, &block51, std::vector<compiler::Node*> { phi_bb52_10, phi_bb52_14 });
    }

    TNode<OrderedHashSet> phi_bb50_10;
    TNode<JSReceiver> phi_bb50_14;
    TNode<JSReceiver> tmp59;
    if (block50.is_used()) {
        ca_.Bind(&block50, &phi_bb50_10, &phi_bb50_14);
        compiler::CodeAssemblerLabel label60(&ca_);
        tmp59 = IteratorBuiltinsAssembler(state_).IteratorStep(
            TNode<Context> { parameter0 }, TorqueStructIteratorRecord { TNode<JSReceiver> { tmp56 }, TNode<Object> { tmp57 } }, TNode<Map> { tmp0 }, &label60);
        ca_.Goto(&block53, phi_bb50_10, phi_bb50_14);
        if (label60.is_used()) {
            ca_.Bind(&label60);
            ca_.Goto(&block54, phi_bb50_10, phi_bb50_14);
        }
    }

    TNode<OrderedHashSet> phi_bb54_10;
    TNode<JSReceiver> phi_bb54_14;
    if (block54.is_used()) {
        ca_.Bind(&block54, &phi_bb54_10, &phi_bb54_14);
        ca_.Goto(&block7, phi_bb54_10);
    }

    TNode<OrderedHashSet> phi_bb53_10;
    TNode<JSReceiver> phi_bb53_14;
    TNode<Object> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<Object> tmp63;
    TNode<HeapObject> tmp64;
    if (block53.is_used()) {
        ca_.Bind(&block53, &phi_bb53_10, &phi_bb53_14);
        tmp61 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context> { parameter0 }, TNode<JSReceiver> { tmp59 }, TNode<Map> { tmp0 });
        tmp62 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp63 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp8, tmp62 });
        compiler::CodeAssemblerLabel label65(&ca_);
        tmp64 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object> { tmp63 }, &label65);
        ca_.Goto(&block59, phi_bb53_10);
        if (label65.is_used()) {
            ca_.Bind(&label65);
            ca_.Goto(&block60, phi_bb53_10);
        }
    }

    TNode<OrderedHashSet> phi_bb60_10;
    if (block60.is_used()) {
        ca_.Bind(&block60, &phi_bb60_10);
        ca_.Goto(&block57, phi_bb60_10);
    }

    TNode<OrderedHashSet> phi_bb59_10;
    TNode<OrderedHashSet> tmp66;
    if (block59.is_used()) {
        ca_.Bind(&block59, &phi_bb59_10);
        compiler::CodeAssemblerLabel label67(&ca_);
        tmp66 = Cast_OrderedHashSet_0(state_, TNode<HeapObject> { tmp64 }, &label67);
        ca_.Goto(&block62, phi_bb59_10);
        if (label67.is_used()) {
            ca_.Bind(&label67);
            ca_.Goto(&block63, phi_bb59_10);
        }
    }

    TNode<OrderedHashSet> phi_bb63_10;
    if (block63.is_used()) {
        ca_.Bind(&block63, &phi_bb63_10);
        ca_.Goto(&block57, phi_bb63_10);
    }

    TNode<OrderedHashSet> phi_bb62_10;
    TNode<OrderedHashSet> tmp68;
    TNode<BoolT> tmp69;
    if (block62.is_used()) {
        ca_.Bind(&block62, &phi_bb62_10);
        tmp68 = (TNode<OrderedHashSet> { tmp66 });
        tmp69 = CollectionsBuiltinsAssembler(state_).TableHasKey(TNode<Context> { parameter0 }, TNode<OrderedHashSet> { tmp68 }, TNode<Object> { tmp61 });
        ca_.Branch(tmp69, &block64, std::vector<compiler::Node*> {}, &block65, std::vector<compiler::Node*> {});
    }

    TNode<OrderedHashSet> phi_bb57_10;
    if (block57.is_used()) {
        ca_.Bind(&block57, &phi_bb57_10);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<False> tmp70;
    if (block64.is_used()) {
        ca_.Bind(&block64);
        IteratorClose_0(state_, TNode<Context> { parameter0 }, TorqueStructIteratorRecord { TNode<JSReceiver> { tmp56 }, TNode<Object> { tmp57 } });
        tmp70 = False_0(state_);
        CodeStubAssembler(state_).Return(tmp70);
    }

    if (block65.is_used()) {
        ca_.Bind(&block65);
        ca_.Goto(&block52, tmp68, tmp59);
    }

    TNode<OrderedHashSet> phi_bb51_10;
    TNode<JSReceiver> phi_bb51_14;
    if (block51.is_used()) {
        ca_.Bind(&block51, &phi_bb51_10, &phi_bb51_14);
        ca_.Goto(&block40, phi_bb51_10);
    }

    TNode<OrderedHashSet> phi_bb40_10;
    if (block40.is_used()) {
        ca_.Bind(&block40, &phi_bb40_10);
        ca_.Goto(&block8, phi_bb40_10);
    }

    TNode<OrderedHashSet> phi_bb8_10;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_10);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<OrderedHashSet> phi_bb7_10;
    TNode<True> tmp71;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_10);
        tmp71 = True_0(state_);
        CodeStubAssembler(state_).Return(tmp71);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/set-is-disjoint-from.tq?l=38&c=18
TNode<Boolean> FastIsDisjointFrom_StableJSSetBackingTableWitness_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context,
    TorqueStructStableJSSetBackingTableWitness_0 p_collectionToIterate, TorqueStructStableJSSetBackingTableWitness_0 p_tableToLookup)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Boolean> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Boolean> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
        ca_.Goto(&block7, tmp3, tmp4);
    }

    TNode<Object> phi_bb7_8;
    TNode<IntPtrT> phi_bb7_9;
    TNode<BoolT> tmp5;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_8, &phi_bb7_9);
        tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp5, &block5, std::vector<compiler::Node*> { phi_bb7_8, phi_bb7_9 }, &block6, std::vector<compiler::Node*> { phi_bb7_8, phi_bb7_9 });
    }

    TNode<Object> phi_bb5_8;
    TNode<IntPtrT> phi_bb5_9;
    TNode<Object> tmp6;
    TNode<IntPtrT> tmp7;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_8, &phi_bb5_9);
        compiler::CodeAssemblerLabel label8(&ca_);
        std::tie(tmp6, tmp7) = CollectionsBuiltinsAssembler(state_)
                                   .NextKeyIndexPairUnmodifiedTable(
                                       TNode<OrderedHashSet> { tmp0 }, TNode<Int32T> { tmp1 }, TNode<Int32T> { tmp2 }, TNode<IntPtrT> { phi_bb5_9 }, &label8)
                                   .Flatten();
        ca_.Goto(&block9, phi_bb5_8, phi_bb5_9, phi_bb5_9);
        if (label8.is_used()) {
            ca_.Bind(&label8);
            ca_.Goto(&block10, phi_bb5_8, phi_bb5_9, phi_bb5_9);
        }
    }

    TNode<Object> phi_bb10_8;
    TNode<IntPtrT> phi_bb10_9;
    TNode<IntPtrT> phi_bb10_13;
    TNode<True> tmp9;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_8, &phi_bb10_9, &phi_bb10_13);
        tmp9 = True_0(state_);
        ca_.Goto(&block1, tmp9);
    }

    TNode<Object> phi_bb9_8;
    TNode<IntPtrT> phi_bb9_9;
    TNode<IntPtrT> phi_bb9_13;
    TNode<BoolT> tmp10;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_8, &phi_bb9_9, &phi_bb9_13);
        tmp10 = CollectionsBuiltinsAssembler(state_).TableHasKey(
            TNode<Context> { p_context }, TNode<OrderedHashSet> { p_tableToLookup.unstable }, TNode<Object> { tmp6 });
        ca_.Branch(tmp10, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    TNode<False> tmp11;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp11 = False_0(state_);
        ca_.Goto(&block1, tmp11);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block7, tmp6, tmp7);
    }

    TNode<Object> phi_bb6_8;
    TNode<IntPtrT> phi_bb6_9;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_8, &phi_bb6_9);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Boolean> phi_bb1_5;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_5);
        ca_.Goto(&block14, phi_bb1_5);
    }

    TNode<Boolean> phi_bb14_5;
    ca_.Bind(&block14, &phi_bb14_5);
    return TNode<Boolean> { phi_bb14_5 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/set-is-disjoint-from.tq?l=53&c=18
TNode<Boolean> FastIsDisjointFrom_StableJSMapBackingTableWitness_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context,
    TorqueStructStableJSSetBackingTableWitness_0 p_collectionToIterate, TorqueStructStableJSMapBackingTableWitness_0 p_tableToLookup)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Boolean> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Boolean> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
        ca_.Goto(&block7, tmp3, tmp4);
    }

    TNode<Object> phi_bb7_8;
    TNode<IntPtrT> phi_bb7_9;
    TNode<BoolT> tmp5;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_8, &phi_bb7_9);
        tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp5, &block5, std::vector<compiler::Node*> { phi_bb7_8, phi_bb7_9 }, &block6, std::vector<compiler::Node*> { phi_bb7_8, phi_bb7_9 });
    }

    TNode<Object> phi_bb5_8;
    TNode<IntPtrT> phi_bb5_9;
    TNode<Object> tmp6;
    TNode<IntPtrT> tmp7;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_8, &phi_bb5_9);
        compiler::CodeAssemblerLabel label8(&ca_);
        std::tie(tmp6, tmp7) = CollectionsBuiltinsAssembler(state_)
                                   .NextKeyIndexPairUnmodifiedTable(
                                       TNode<OrderedHashSet> { tmp0 }, TNode<Int32T> { tmp1 }, TNode<Int32T> { tmp2 }, TNode<IntPtrT> { phi_bb5_9 }, &label8)
                                   .Flatten();
        ca_.Goto(&block9, phi_bb5_8, phi_bb5_9, phi_bb5_9);
        if (label8.is_used()) {
            ca_.Bind(&label8);
            ca_.Goto(&block10, phi_bb5_8, phi_bb5_9, phi_bb5_9);
        }
    }

    TNode<Object> phi_bb10_8;
    TNode<IntPtrT> phi_bb10_9;
    TNode<IntPtrT> phi_bb10_13;
    TNode<True> tmp9;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_8, &phi_bb10_9, &phi_bb10_13);
        tmp9 = True_0(state_);
        ca_.Goto(&block1, tmp9);
    }

    TNode<Object> phi_bb9_8;
    TNode<IntPtrT> phi_bb9_9;
    TNode<IntPtrT> phi_bb9_13;
    TNode<BoolT> tmp10;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_8, &phi_bb9_9, &phi_bb9_13);
        tmp10 = CollectionsBuiltinsAssembler(state_).TableHasKey(
            TNode<Context> { p_context }, TNode<OrderedHashMap> { p_tableToLookup.unstable }, TNode<Object> { tmp6 });
        ca_.Branch(tmp10, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    TNode<False> tmp11;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp11 = False_0(state_);
        ca_.Goto(&block1, tmp11);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block7, tmp6, tmp7);
    }

    TNode<Object> phi_bb6_8;
    TNode<IntPtrT> phi_bb6_9;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_8, &phi_bb6_9);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Boolean> phi_bb1_5;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_5);
        ca_.Goto(&block14, phi_bb1_5);
    }

    TNode<Boolean> phi_bb14_5;
    ca_.Bind(&block14, &phi_bb14_5);
    return TNode<Boolean> { phi_bb14_5 };
}

} // namespace internal
} // namespace v8
