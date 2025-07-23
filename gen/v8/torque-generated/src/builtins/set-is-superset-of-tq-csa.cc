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
#include "torque-generated/src/builtins/set-is-superset-of-tq-csa.h"
#include "torque-generated/src/builtins/array-from-async-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/collections-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/set-difference-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(SetPrototypeIsSupersetOf, CodeStubAssembler)
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
    compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT, IntPtrT> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT, IntPtrT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, Object, IntPtrT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, JSReceiver> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, JSReceiver> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, JSReceiver> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, JSReceiver> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet, JSReceiver> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<OrderedHashSet> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
        tmp3 = FromConstexpr_Object_constexpr_string_0(state_, "Set.prototype.isSupersetOf");
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
    TNode<Number> tmp11;
    TNode<BoolT> tmp12;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        std::tie(tmp4, tmp5, tmp6, tmp7)
            = GetSetRecord_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, "Set.prototype.isSupersetOf").Flatten();
        std::tie(tmp8, tmp9) = NewStableBackingTableWitness_0(state_, TNode<JSSet> { tmp1 }).Flatten();
        tmp10 = LoadOrderedHashTableMetadata_0(state_, TNode<FixedArray> { tmp9 }, OrderedHashSet::NumberOfElementsIndex());
        tmp11 = Convert_Number_int32_0(state_, TNode<Int32T> { tmp10 });
        tmp12 = NumberIsLessThan_0(state_, TNode<Number> { tmp11 }, TNode<Number> { tmp5 });
        ca_.Branch(tmp12, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    TNode<False> tmp13;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp13 = False_0(state_);
        CodeStubAssembler(state_).Return(tmp13);
    }

    TNode<JSSet> tmp14;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        compiler::CodeAssemblerLabel label15(&ca_);
        tmp14 = Cast_JSSetWithNoCustomIteration_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, &label15);
        ca_.Goto(&block14);
        if (label15.is_used()) {
            ca_.Bind(&label15);
            ca_.Goto(&block15);
        }
    }

    TNode<JSMap> tmp16;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        compiler::CodeAssemblerLabel label17(&ca_);
        tmp16 = Cast_JSMapWithNoCustomIteration_1(state_, TNode<Context> { parameter0 }, TNode<Object> { ca_.UncheckedCast<Object>(parameter2) }, &label17);
        ca_.Goto(&block30);
        if (label17.is_used()) {
            ca_.Bind(&label17);
            ca_.Goto(&block31);
        }
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        compiler::CodeAssemblerLabel label18(&ca_);
        CheckSetRecordHasJSSetMethods_0(
            state_, TorqueStructSetRecord { TNode<JSReceiver> { tmp4 }, TNode<Number> { tmp5 }, TNode<Object> { tmp6 }, TNode<Object> { tmp7 } }, &label18);
        ca_.Goto(&block16);
        if (label18.is_used()) {
            ca_.Bind(&label18);
            ca_.Goto(&block17);
        }
    }

    if (block17.is_used()) {
        ca_.Bind(&block17);
        ca_.Goto(&block11);
    }

    TNode<JSSet> tmp19;
    TNode<OrderedHashSet> tmp20;
    TNode<OrderedHashSet> tmp21;
    TNode<Int32T> tmp22;
    TNode<Int32T> tmp23;
    TNode<Object> tmp24;
    TNode<IntPtrT> tmp25;
    if (block16.is_used()) {
        ca_.Bind(&block16);
        std::tie(tmp19, tmp20) = NewStableBackingTableWitness_0(state_, TNode<JSSet> { tmp14 }).Flatten();
        std::tie(tmp21, tmp22, tmp23, tmp24, tmp25) = NewUnmodifiedOrderedHashSetIterator_0(state_, TNode<OrderedHashSet> { tmp20 }).Flatten();
        ca_.Goto(&block21, tmp24, tmp25);
    }

    TNode<Object> phi_bb21_19;
    TNode<IntPtrT> phi_bb21_20;
    TNode<BoolT> tmp26;
    if (block21.is_used()) {
        ca_.Bind(&block21, &phi_bb21_19, &phi_bb21_20);
        tmp26 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(
            tmp26, &block19, std::vector<compiler::Node*> { phi_bb21_19, phi_bb21_20 }, &block20, std::vector<compiler::Node*> { phi_bb21_19, phi_bb21_20 });
    }

    TNode<Object> phi_bb19_19;
    TNode<IntPtrT> phi_bb19_20;
    TNode<Object> tmp27;
    TNode<IntPtrT> tmp28;
    if (block19.is_used()) {
        ca_.Bind(&block19, &phi_bb19_19, &phi_bb19_20);
        compiler::CodeAssemblerLabel label29(&ca_);
        std::tie(tmp27, tmp28) = CollectionsBuiltinsAssembler(state_)
                                     .NextKeyIndexPairUnmodifiedTable(TNode<OrderedHashSet> { tmp21 }, TNode<Int32T> { tmp22 }, TNode<Int32T> { tmp23 },
                                         TNode<IntPtrT> { phi_bb19_20 }, &label29)
                                     .Flatten();
        ca_.Goto(&block23, phi_bb19_19, phi_bb19_20, phi_bb19_20);
        if (label29.is_used()) {
            ca_.Bind(&label29);
            ca_.Goto(&block24, phi_bb19_19, phi_bb19_20, phi_bb19_20);
        }
    }

    TNode<Object> phi_bb24_19;
    TNode<IntPtrT> phi_bb24_20;
    TNode<IntPtrT> phi_bb24_24;
    if (block24.is_used()) {
        ca_.Bind(&block24, &phi_bb24_19, &phi_bb24_20, &phi_bb24_24);
        ca_.Goto(&block9, tmp9);
    }

    TNode<Object> phi_bb23_19;
    TNode<IntPtrT> phi_bb23_20;
    TNode<IntPtrT> phi_bb23_24;
    TNode<BoolT> tmp30;
    TNode<BoolT> tmp31;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_19, &phi_bb23_20, &phi_bb23_24);
        tmp30 = CollectionsBuiltinsAssembler(state_).TableHasKey(TNode<Context> { parameter0 }, TNode<OrderedHashSet> { tmp9 }, TNode<Object> { tmp27 });
        tmp31 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp30 });
        ca_.Branch(tmp31, &block25, std::vector<compiler::Node*> {}, &block26, std::vector<compiler::Node*> {});
    }

    TNode<False> tmp32;
    if (block25.is_used()) {
        ca_.Bind(&block25);
        tmp32 = False_0(state_);
        CodeStubAssembler(state_).Return(tmp32);
    }

    if (block26.is_used()) {
        ca_.Bind(&block26);
        ca_.Goto(&block21, tmp27, tmp28);
    }

    TNode<Object> phi_bb20_19;
    TNode<IntPtrT> phi_bb20_20;
    if (block20.is_used()) {
        ca_.Bind(&block20, &phi_bb20_19, &phi_bb20_20);
        ca_.Goto(&block12);
    }

    if (block31.is_used()) {
        ca_.Bind(&block31);
        ca_.Goto(&block11);
    }

    if (block30.is_used()) {
        ca_.Bind(&block30);
        compiler::CodeAssemblerLabel label33(&ca_);
        CheckSetRecordHasJSMapMethods_0(
            state_, TorqueStructSetRecord { TNode<JSReceiver> { tmp4 }, TNode<Number> { tmp5 }, TNode<Object> { tmp6 }, TNode<Object> { tmp7 } }, &label33);
        ca_.Goto(&block32);
        if (label33.is_used()) {
            ca_.Bind(&label33);
            ca_.Goto(&block33);
        }
    }

    if (block33.is_used()) {
        ca_.Bind(&block33);
        ca_.Goto(&block11);
    }

    TNode<JSMap> tmp34;
    TNode<OrderedHashMap> tmp35;
    TNode<OrderedHashMap> tmp36;
    TNode<Int32T> tmp37;
    TNode<Int32T> tmp38;
    TNode<Object> tmp39;
    TNode<Object> tmp40;
    TNode<IntPtrT> tmp41;
    if (block32.is_used()) {
        ca_.Bind(&block32);
        std::tie(tmp34, tmp35) = NewStableBackingTableWitness_1(state_, TNode<JSMap> { tmp16 }).Flatten();
        std::tie(tmp36, tmp37, tmp38, tmp39, tmp40, tmp41) = NewUnmodifiedOrderedHashMapIterator_0(state_, TNode<OrderedHashMap> { tmp35 }).Flatten();
        ca_.Goto(&block37, tmp39, tmp40, tmp41);
    }

    TNode<Object> phi_bb37_19;
    TNode<Object> phi_bb37_20;
    TNode<IntPtrT> phi_bb37_21;
    TNode<BoolT> tmp42;
    if (block37.is_used()) {
        ca_.Bind(&block37, &phi_bb37_19, &phi_bb37_20, &phi_bb37_21);
        tmp42 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp42, &block35, std::vector<compiler::Node*> { phi_bb37_19, phi_bb37_20, phi_bb37_21 }, &block36,
            std::vector<compiler::Node*> { phi_bb37_19, phi_bb37_20, phi_bb37_21 });
    }

    TNode<Object> phi_bb35_19;
    TNode<Object> phi_bb35_20;
    TNode<IntPtrT> phi_bb35_21;
    TNode<Object> tmp43;
    TNode<Object> tmp44;
    TNode<IntPtrT> tmp45;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_19, &phi_bb35_20, &phi_bb35_21);
        compiler::CodeAssemblerLabel label46(&ca_);
        std::tie(tmp43, tmp44, tmp45) = CollectionsBuiltinsAssembler(state_)
                                            .NextKeyValueIndexTupleUnmodifiedTable(TNode<OrderedHashMap> { tmp36 }, TNode<Int32T> { tmp37 },
                                                TNode<Int32T> { tmp38 }, TNode<IntPtrT> { phi_bb35_21 }, &label46)
                                            .Flatten();
        ca_.Goto(&block39, phi_bb35_19, phi_bb35_20, phi_bb35_21, phi_bb35_21);
        if (label46.is_used()) {
            ca_.Bind(&label46);
            ca_.Goto(&block40, phi_bb35_19, phi_bb35_20, phi_bb35_21, phi_bb35_21);
        }
    }

    TNode<Object> phi_bb40_19;
    TNode<Object> phi_bb40_20;
    TNode<IntPtrT> phi_bb40_21;
    TNode<IntPtrT> phi_bb40_25;
    if (block40.is_used()) {
        ca_.Bind(&block40, &phi_bb40_19, &phi_bb40_20, &phi_bb40_21, &phi_bb40_25);
        ca_.Goto(&block9, tmp9);
    }

    TNode<Object> phi_bb39_19;
    TNode<Object> phi_bb39_20;
    TNode<IntPtrT> phi_bb39_21;
    TNode<IntPtrT> phi_bb39_25;
    TNode<BoolT> tmp47;
    TNode<BoolT> tmp48;
    if (block39.is_used()) {
        ca_.Bind(&block39, &phi_bb39_19, &phi_bb39_20, &phi_bb39_21, &phi_bb39_25);
        tmp47 = CollectionsBuiltinsAssembler(state_).TableHasKey(TNode<Context> { parameter0 }, TNode<OrderedHashSet> { tmp9 }, TNode<Object> { tmp43 });
        tmp48 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp47 });
        ca_.Branch(tmp48, &block41, std::vector<compiler::Node*> {}, &block42, std::vector<compiler::Node*> {});
    }

    TNode<False> tmp49;
    if (block41.is_used()) {
        ca_.Bind(&block41);
        tmp49 = False_0(state_);
        CodeStubAssembler(state_).Return(tmp49);
    }

    if (block42.is_used()) {
        ca_.Bind(&block42);
        ca_.Goto(&block37, tmp43, tmp44, tmp45);
    }

    TNode<Object> phi_bb36_19;
    TNode<Object> phi_bb36_20;
    TNode<IntPtrT> phi_bb36_21;
    if (block36.is_used()) {
        ca_.Bind(&block36, &phi_bb36_19, &phi_bb36_20, &phi_bb36_21);
        ca_.Goto(&block12);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block10, tmp9);
    }

    TNode<JSReceiver> tmp50;
    TNode<JSReceiver> tmp51;
    TNode<Object> tmp52;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp50 = UnsafeCast_Callable_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp7 });
        std::tie(tmp51, tmp52) = GetKeysIterator_0(state_, TNode<Context> { parameter0 }, TNode<JSReceiver> { tmp4 }, TNode<JSReceiver> { tmp50 }).Flatten();
        ca_.Goto(&block46, tmp9, ca_.Uninitialized<JSReceiver>());
    }

    TNode<OrderedHashSet> phi_bb46_10;
    TNode<JSReceiver> phi_bb46_14;
    TNode<BoolT> tmp53;
    if (block46.is_used()) {
        ca_.Bind(&block46, &phi_bb46_10, &phi_bb46_14);
        tmp53 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(
            tmp53, &block44, std::vector<compiler::Node*> { phi_bb46_10, phi_bb46_14 }, &block45, std::vector<compiler::Node*> { phi_bb46_10, phi_bb46_14 });
    }

    TNode<OrderedHashSet> phi_bb44_10;
    TNode<JSReceiver> phi_bb44_14;
    TNode<JSReceiver> tmp54;
    if (block44.is_used()) {
        ca_.Bind(&block44, &phi_bb44_10, &phi_bb44_14);
        compiler::CodeAssemblerLabel label55(&ca_);
        tmp54 = IteratorBuiltinsAssembler(state_).IteratorStep(
            TNode<Context> { parameter0 }, TorqueStructIteratorRecord { TNode<JSReceiver> { tmp51 }, TNode<Object> { tmp52 } }, TNode<Map> { tmp0 }, &label55);
        ca_.Goto(&block47, phi_bb44_10, phi_bb44_14);
        if (label55.is_used()) {
            ca_.Bind(&label55);
            ca_.Goto(&block48, phi_bb44_10, phi_bb44_14);
        }
    }

    TNode<OrderedHashSet> phi_bb48_10;
    TNode<JSReceiver> phi_bb48_14;
    if (block48.is_used()) {
        ca_.Bind(&block48, &phi_bb48_10, &phi_bb48_14);
        ca_.Goto(&block9, phi_bb48_10);
    }

    TNode<OrderedHashSet> phi_bb47_10;
    TNode<JSReceiver> phi_bb47_14;
    TNode<Object> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<Object> tmp58;
    TNode<HeapObject> tmp59;
    if (block47.is_used()) {
        ca_.Bind(&block47, &phi_bb47_10, &phi_bb47_14);
        tmp56 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context> { parameter0 }, TNode<JSReceiver> { tmp54 }, TNode<Map> { tmp0 });
        tmp57 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp58 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp8, tmp57 });
        compiler::CodeAssemblerLabel label60(&ca_);
        tmp59 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object> { tmp58 }, &label60);
        ca_.Goto(&block53, phi_bb47_10);
        if (label60.is_used()) {
            ca_.Bind(&label60);
            ca_.Goto(&block54, phi_bb47_10);
        }
    }

    TNode<OrderedHashSet> phi_bb54_10;
    if (block54.is_used()) {
        ca_.Bind(&block54, &phi_bb54_10);
        ca_.Goto(&block51, phi_bb54_10);
    }

    TNode<OrderedHashSet> phi_bb53_10;
    TNode<OrderedHashSet> tmp61;
    if (block53.is_used()) {
        ca_.Bind(&block53, &phi_bb53_10);
        compiler::CodeAssemblerLabel label62(&ca_);
        tmp61 = Cast_OrderedHashSet_0(state_, TNode<HeapObject> { tmp59 }, &label62);
        ca_.Goto(&block56, phi_bb53_10);
        if (label62.is_used()) {
            ca_.Bind(&label62);
            ca_.Goto(&block57, phi_bb53_10);
        }
    }

    TNode<OrderedHashSet> phi_bb57_10;
    if (block57.is_used()) {
        ca_.Bind(&block57, &phi_bb57_10);
        ca_.Goto(&block51, phi_bb57_10);
    }

    TNode<OrderedHashSet> phi_bb56_10;
    TNode<OrderedHashSet> tmp63;
    TNode<BoolT> tmp64;
    TNode<BoolT> tmp65;
    if (block56.is_used()) {
        ca_.Bind(&block56, &phi_bb56_10);
        tmp63 = (TNode<OrderedHashSet> { tmp61 });
        tmp64 = CollectionsBuiltinsAssembler(state_).TableHasKey(TNode<Context> { parameter0 }, TNode<OrderedHashSet> { tmp63 }, TNode<Object> { tmp56 });
        tmp65 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp64 });
        ca_.Branch(tmp65, &block58, std::vector<compiler::Node*> {}, &block59, std::vector<compiler::Node*> {});
    }

    TNode<OrderedHashSet> phi_bb51_10;
    if (block51.is_used()) {
        ca_.Bind(&block51, &phi_bb51_10);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<False> tmp66;
    if (block58.is_used()) {
        ca_.Bind(&block58);
        IteratorClose_0(state_, TNode<Context> { parameter0 }, TorqueStructIteratorRecord { TNode<JSReceiver> { tmp51 }, TNode<Object> { tmp52 } });
        tmp66 = False_0(state_);
        CodeStubAssembler(state_).Return(tmp66);
    }

    if (block59.is_used()) {
        ca_.Bind(&block59);
        ca_.Goto(&block46, tmp63, tmp54);
    }

    TNode<OrderedHashSet> phi_bb45_10;
    TNode<JSReceiver> phi_bb45_14;
    if (block45.is_used()) {
        ca_.Bind(&block45, &phi_bb45_10, &phi_bb45_14);
        ca_.Goto(&block10, phi_bb45_10);
    }

    TNode<OrderedHashSet> phi_bb10_10;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_10);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<OrderedHashSet> phi_bb9_10;
    TNode<True> tmp67;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_10);
        tmp67 = True_0(state_);
        CodeStubAssembler(state_).Return(tmp67);
    }
}

} // namespace internal
} // namespace v8
