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
#include "torque-generated/src/builtins/set-is-subset-of-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/collections-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/set-difference-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(SetPrototypeIsSubsetOf, CodeStubAssembler)
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
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, Object, IntPtrT> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSSet> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_JSSet_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    TNode<Object> tmp2;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp2 = FromConstexpr_Object_constexpr_string_0(state_, "Set.prototype.isSubsetOf");
        CodeStubAssembler(state_).ThrowTypeError(
            TNode<Context> { parameter0 }, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object> { tmp2 }, TNode<Object> { parameter1 });
    }

    TNode<JSReceiver> tmp3;
    TNode<Number> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<JSSet> tmp7;
    TNode<OrderedHashSet> tmp8;
    TNode<Int32T> tmp9;
    TNode<Number> tmp10;
    TNode<BoolT> tmp11;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        std::tie(tmp3, tmp4, tmp5, tmp6)
            = GetSetRecord_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, "Set.prototype.isSubsetOf").Flatten();
        std::tie(tmp7, tmp8) = NewStableBackingTableWitness_0(state_, TNode<JSSet> { tmp0 }).Flatten();
        tmp9 = LoadOrderedHashTableMetadata_0(state_, TNode<FixedArray> { tmp8 }, OrderedHashSet::NumberOfElementsIndex());
        tmp10 = Convert_Number_int32_0(state_, TNode<Int32T> { tmp9 });
        tmp11 = NumberIsGreaterThan_0(state_, TNode<Number> { tmp10 }, TNode<Number> { tmp4 });
        ca_.Branch(tmp11, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    TNode<False> tmp12;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp12 = False_0(state_);
        CodeStubAssembler(state_).Return(tmp12);
    }

    TNode<JSSet> tmp13;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        compiler::CodeAssemblerLabel label14(&ca_);
        tmp13 = Cast_JSSetWithNoCustomIteration_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, &label14);
        ca_.Goto(&block14);
        if (label14.is_used()) {
            ca_.Bind(&label14);
            ca_.Goto(&block15);
        }
    }

    TNode<JSMap> tmp15;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        compiler::CodeAssemblerLabel label16(&ca_);
        tmp15 = Cast_JSMapWithNoCustomIteration_1(state_, TNode<Context> { parameter0 }, TNode<Object> { ca_.UncheckedCast<Object>(parameter2) }, &label16);
        ca_.Goto(&block30);
        if (label16.is_used()) {
            ca_.Bind(&label16);
            ca_.Goto(&block31);
        }
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        compiler::CodeAssemblerLabel label17(&ca_);
        CheckSetRecordHasJSSetMethods_0(
            state_, TorqueStructSetRecord { TNode<JSReceiver> { tmp3 }, TNode<Number> { tmp4 }, TNode<Object> { tmp5 }, TNode<Object> { tmp6 } }, &label17);
        ca_.Goto(&block16);
        if (label17.is_used()) {
            ca_.Bind(&label17);
            ca_.Goto(&block17);
        }
    }

    if (block17.is_used()) {
        ca_.Bind(&block17);
        ca_.Goto(&block11);
    }

    TNode<JSSet> tmp18;
    TNode<OrderedHashSet> tmp19;
    TNode<OrderedHashSet> tmp20;
    TNode<Int32T> tmp21;
    TNode<Int32T> tmp22;
    TNode<Object> tmp23;
    TNode<IntPtrT> tmp24;
    if (block16.is_used()) {
        ca_.Bind(&block16);
        std::tie(tmp18, tmp19) = NewStableBackingTableWitness_0(state_, TNode<JSSet> { tmp13 }).Flatten();
        std::tie(tmp20, tmp21, tmp22, tmp23, tmp24) = NewUnmodifiedOrderedHashSetIterator_0(state_, TNode<OrderedHashSet> { tmp8 }).Flatten();
        ca_.Goto(&block21, tmp23, tmp24);
    }

    TNode<Object> phi_bb21_18;
    TNode<IntPtrT> phi_bb21_19;
    TNode<BoolT> tmp25;
    if (block21.is_used()) {
        ca_.Bind(&block21, &phi_bb21_18, &phi_bb21_19);
        tmp25 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(
            tmp25, &block19, std::vector<compiler::Node*> { phi_bb21_18, phi_bb21_19 }, &block20, std::vector<compiler::Node*> { phi_bb21_18, phi_bb21_19 });
    }

    TNode<Object> phi_bb19_18;
    TNode<IntPtrT> phi_bb19_19;
    TNode<Object> tmp26;
    TNode<IntPtrT> tmp27;
    if (block19.is_used()) {
        ca_.Bind(&block19, &phi_bb19_18, &phi_bb19_19);
        compiler::CodeAssemblerLabel label28(&ca_);
        std::tie(tmp26, tmp27) = CollectionsBuiltinsAssembler(state_)
                                     .NextKeyIndexPairUnmodifiedTable(TNode<OrderedHashSet> { tmp20 }, TNode<Int32T> { tmp21 }, TNode<Int32T> { tmp22 },
                                         TNode<IntPtrT> { phi_bb19_19 }, &label28)
                                     .Flatten();
        ca_.Goto(&block23, phi_bb19_18, phi_bb19_19, phi_bb19_19);
        if (label28.is_used()) {
            ca_.Bind(&label28);
            ca_.Goto(&block24, phi_bb19_18, phi_bb19_19, phi_bb19_19);
        }
    }

    TNode<Object> phi_bb24_18;
    TNode<IntPtrT> phi_bb24_19;
    TNode<IntPtrT> phi_bb24_23;
    if (block24.is_used()) {
        ca_.Bind(&block24, &phi_bb24_18, &phi_bb24_19, &phi_bb24_23);
        ca_.Goto(&block9);
    }

    TNode<Object> phi_bb23_18;
    TNode<IntPtrT> phi_bb23_19;
    TNode<IntPtrT> phi_bb23_23;
    TNode<BoolT> tmp29;
    TNode<BoolT> tmp30;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_18, &phi_bb23_19, &phi_bb23_23);
        tmp29 = CollectionsBuiltinsAssembler(state_).TableHasKey(TNode<Context> { parameter0 }, TNode<OrderedHashSet> { tmp19 }, TNode<Object> { tmp26 });
        tmp30 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp29 });
        ca_.Branch(tmp30, &block25, std::vector<compiler::Node*> {}, &block26, std::vector<compiler::Node*> {});
    }

    TNode<False> tmp31;
    if (block25.is_used()) {
        ca_.Bind(&block25);
        tmp31 = False_0(state_);
        CodeStubAssembler(state_).Return(tmp31);
    }

    if (block26.is_used()) {
        ca_.Bind(&block26);
        ca_.Goto(&block21, tmp26, tmp27);
    }

    TNode<Object> phi_bb20_18;
    TNode<IntPtrT> phi_bb20_19;
    if (block20.is_used()) {
        ca_.Bind(&block20, &phi_bb20_18, &phi_bb20_19);
        ca_.Goto(&block12);
    }

    if (block31.is_used()) {
        ca_.Bind(&block31);
        ca_.Goto(&block11);
    }

    if (block30.is_used()) {
        ca_.Bind(&block30);
        compiler::CodeAssemblerLabel label32(&ca_);
        CheckSetRecordHasJSMapMethods_0(
            state_, TorqueStructSetRecord { TNode<JSReceiver> { tmp3 }, TNode<Number> { tmp4 }, TNode<Object> { tmp5 }, TNode<Object> { tmp6 } }, &label32);
        ca_.Goto(&block32);
        if (label32.is_used()) {
            ca_.Bind(&label32);
            ca_.Goto(&block33);
        }
    }

    if (block33.is_used()) {
        ca_.Bind(&block33);
        ca_.Goto(&block11);
    }

    TNode<JSMap> tmp33;
    TNode<OrderedHashMap> tmp34;
    TNode<OrderedHashSet> tmp35;
    TNode<Int32T> tmp36;
    TNode<Int32T> tmp37;
    TNode<Object> tmp38;
    TNode<IntPtrT> tmp39;
    if (block32.is_used()) {
        ca_.Bind(&block32);
        std::tie(tmp33, tmp34) = NewStableBackingTableWitness_1(state_, TNode<JSMap> { tmp15 }).Flatten();
        std::tie(tmp35, tmp36, tmp37, tmp38, tmp39) = NewUnmodifiedOrderedHashSetIterator_0(state_, TNode<OrderedHashSet> { tmp8 }).Flatten();
        ca_.Goto(&block37, tmp38, tmp39);
    }

    TNode<Object> phi_bb37_18;
    TNode<IntPtrT> phi_bb37_19;
    TNode<BoolT> tmp40;
    if (block37.is_used()) {
        ca_.Bind(&block37, &phi_bb37_18, &phi_bb37_19);
        tmp40 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(
            tmp40, &block35, std::vector<compiler::Node*> { phi_bb37_18, phi_bb37_19 }, &block36, std::vector<compiler::Node*> { phi_bb37_18, phi_bb37_19 });
    }

    TNode<Object> phi_bb35_18;
    TNode<IntPtrT> phi_bb35_19;
    TNode<Object> tmp41;
    TNode<IntPtrT> tmp42;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_18, &phi_bb35_19);
        compiler::CodeAssemblerLabel label43(&ca_);
        std::tie(tmp41, tmp42) = CollectionsBuiltinsAssembler(state_)
                                     .NextKeyIndexPairUnmodifiedTable(TNode<OrderedHashSet> { tmp35 }, TNode<Int32T> { tmp36 }, TNode<Int32T> { tmp37 },
                                         TNode<IntPtrT> { phi_bb35_19 }, &label43)
                                     .Flatten();
        ca_.Goto(&block39, phi_bb35_18, phi_bb35_19, phi_bb35_19);
        if (label43.is_used()) {
            ca_.Bind(&label43);
            ca_.Goto(&block40, phi_bb35_18, phi_bb35_19, phi_bb35_19);
        }
    }

    TNode<Object> phi_bb40_18;
    TNode<IntPtrT> phi_bb40_19;
    TNode<IntPtrT> phi_bb40_23;
    if (block40.is_used()) {
        ca_.Bind(&block40, &phi_bb40_18, &phi_bb40_19, &phi_bb40_23);
        ca_.Goto(&block9);
    }

    TNode<Object> phi_bb39_18;
    TNode<IntPtrT> phi_bb39_19;
    TNode<IntPtrT> phi_bb39_23;
    TNode<BoolT> tmp44;
    TNode<BoolT> tmp45;
    if (block39.is_used()) {
        ca_.Bind(&block39, &phi_bb39_18, &phi_bb39_19, &phi_bb39_23);
        tmp44 = CollectionsBuiltinsAssembler(state_).TableHasKey(TNode<Context> { parameter0 }, TNode<OrderedHashMap> { tmp34 }, TNode<Object> { tmp41 });
        tmp45 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp44 });
        ca_.Branch(tmp45, &block41, std::vector<compiler::Node*> {}, &block42, std::vector<compiler::Node*> {});
    }

    TNode<False> tmp46;
    if (block41.is_used()) {
        ca_.Bind(&block41);
        tmp46 = False_0(state_);
        CodeStubAssembler(state_).Return(tmp46);
    }

    if (block42.is_used()) {
        ca_.Bind(&block42);
        ca_.Goto(&block37, tmp41, tmp42);
    }

    TNode<Object> phi_bb36_18;
    TNode<IntPtrT> phi_bb36_19;
    if (block36.is_used()) {
        ca_.Bind(&block36, &phi_bb36_18, &phi_bb36_19);
        ca_.Goto(&block12);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block10);
    }

    TNode<OrderedHashSet> tmp47;
    TNode<Object> tmp48;
    TNode<IntPtrT> tmp49;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        std::tie(tmp47, tmp48, tmp49) = NewOrderedHashSetIterator_0(state_, TNode<OrderedHashSet> { tmp8 }).Flatten();
        ca_.Goto(&block47, tmp47, tmp48, tmp49);
    }

    TNode<OrderedHashSet> phi_bb47_11;
    TNode<Object> phi_bb47_12;
    TNode<IntPtrT> phi_bb47_13;
    TNode<BoolT> tmp50;
    if (block47.is_used()) {
        ca_.Bind(&block47, &phi_bb47_11, &phi_bb47_12, &phi_bb47_13);
        tmp50 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp50, &block45, std::vector<compiler::Node*> { phi_bb47_11, phi_bb47_12, phi_bb47_13 }, &block46,
            std::vector<compiler::Node*> { phi_bb47_11, phi_bb47_12, phi_bb47_13 });
    }

    TNode<OrderedHashSet> phi_bb45_11;
    TNode<Object> phi_bb45_12;
    TNode<IntPtrT> phi_bb45_13;
    TNode<OrderedHashSet> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<Object> tmp53;
    TNode<IntPtrT> tmp54;
    if (block45.is_used()) {
        ca_.Bind(&block45, &phi_bb45_11, &phi_bb45_12, &phi_bb45_13);
        std::tie(tmp51, tmp52) = CollectionsBuiltinsAssembler(state_)
                                     .TransitionOrderedHashSetNoUpdate(TNode<OrderedHashSet> { phi_bb45_11 }, TNode<IntPtrT> { phi_bb45_13 })
                                     .Flatten();
        compiler::CodeAssemblerLabel label55(&ca_);
        std::tie(tmp53, tmp54)
            = CollectionsBuiltinsAssembler(state_).NextKeyIndexPair(TNode<OrderedHashSet> { tmp51 }, TNode<IntPtrT> { tmp52 }, &label55).Flatten();
        ca_.Goto(&block49, phi_bb45_12);
        if (label55.is_used()) {
            ca_.Bind(&label55);
            ca_.Goto(&block50, phi_bb45_12);
        }
    }

    TNode<Object> phi_bb50_12;
    if (block50.is_used()) {
        ca_.Bind(&block50, &phi_bb50_12);
        ca_.Goto(&block9);
    }

    TNode<Object> phi_bb49_12;
    TNode<Object> tmp56;
    TNode<BoolT> tmp57;
    TNode<BoolT> tmp58;
    if (block49.is_used()) {
        ca_.Bind(&block49, &phi_bb49_12);
        tmp56 = CodeStubAssembler(state_).Call(TNode<Context> { parameter0 }, TNode<Object> { tmp5 }, TNode<Object> { tmp3 }, TNode<Object> { tmp53 });
        tmp57 = ToBoolean_0(state_, TNode<Object> { tmp56 });
        tmp58 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp57 });
        ca_.Branch(tmp58, &block51, std::vector<compiler::Node*> {}, &block52, std::vector<compiler::Node*> {});
    }

    TNode<False> tmp59;
    if (block51.is_used()) {
        ca_.Bind(&block51);
        tmp59 = False_0(state_);
        CodeStubAssembler(state_).Return(tmp59);
    }

    if (block52.is_used()) {
        ca_.Bind(&block52);
        ca_.Goto(&block47, tmp51, tmp53, tmp54);
    }

    TNode<OrderedHashSet> phi_bb46_11;
    TNode<Object> phi_bb46_12;
    TNode<IntPtrT> phi_bb46_13;
    if (block46.is_used()) {
        ca_.Bind(&block46, &phi_bb46_11, &phi_bb46_12, &phi_bb46_13);
        ca_.Goto(&block10);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<True> tmp60;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp60 = True_0(state_);
        CodeStubAssembler(state_).Return(tmp60);
    }
}

} // namespace internal
} // namespace v8
