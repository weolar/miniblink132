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
#include "torque-generated/src/builtins/typed-array-from-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-flat-tq-csa.h"
#include "torque-generated/src/builtins/array-from-async-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/set-difference-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-every-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-from-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/src/objects/js-function-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-from.tq?l=8&c=1
const char* kBuiltinNameFrom_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    return "%TypedArray%.from";
}

TF_BUILTIN(TypedArrayFrom, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
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
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object, UintPtrT> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object, UintPtrT> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object, UintPtrT> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object, UintPtrT> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object, UintPtrT, Object> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT, Object, UintPtrT> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Object> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Object> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<JSReceiver> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp1 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp0 });
        tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp3 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp5 = CodeStubAssembler(state_).GetArgumentValue(
            TorqueStructArguments { TNode<RawPtrT> { torque_arguments.frame }, TNode<RawPtrT> { torque_arguments.base },
                TNode<IntPtrT> { torque_arguments.length }, TNode<IntPtrT> { torque_arguments.actual_count } },
            TNode<IntPtrT> { tmp4 });
        compiler::CodeAssemblerLabel label7(&ca_);
        tmp6 = Cast_Constructor_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, &label7);
        ca_.Goto(&block3);
        if (label7.is_used()) {
            ca_.Bind(&label7);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { parameter0 }, MessageTemplate::kNotConstructor, TNode<Object> { parameter1 });
    }

    TNode<Undefined> tmp8;
    TNode<BoolT> tmp9;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp8 = Undefined_0(state_);
        tmp9 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { tmp3 }, TNode<HeapObject> { tmp8 });
        ca_.Branch(tmp9, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp10;
    TNode<BoolT> tmp11;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp10 = Is_Callable_JSAny_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp3 });
        tmp11 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp10 });
        ca_.Goto(&block9, tmp11);
    }

    TNode<BoolT> tmp12;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block9, tmp12);
    }

    TNode<BoolT> phi_bb9_12;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_12);
        ca_.Branch(phi_bb9_12, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        CodeStubAssembler(state_).CallRuntime(Runtime::kThrowCalledNonCallable, parameter0, tmp3);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Symbol> tmp13;
    TNode<JSReceiver> tmp14;
    compiler::TypedCodeAssemblerVariable<Object> tmp17(&ca_);
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp13 = CodeStubAssembler(state_).IteratorSymbolConstant();
        compiler::CodeAssemblerLabel label15(&ca_);
        compiler::CodeAssemblerLabel label16(&ca_);
        tmp14 = GetMethod_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp1 }, TNode<Name> { tmp13 }, &label15, &label16, &tmp17);
        ca_.Goto(&block14);
        if (label15.is_used()) {
            ca_.Bind(&label15);
            ca_.Goto(&block15);
        }
        if (label16.is_used()) {
            ca_.Bind(&label16);
            ca_.Goto(&block16);
        }
    }

    TNode<JSReceiver> tmp18;
    TNode<Number> tmp19;
    TNode<UintPtrT> tmp20;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp18 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context> { parameter0 }, TNode<Object> { tmp1 });
        tmp19 = GetLengthProperty_0(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp18 });
        compiler::CodeAssemblerLabel label21(&ca_);
        tmp20 = ChangeSafeIntegerNumberToUintPtr_0(state_, TNode<Number> { tmp19 }, &label21);
        ca_.Goto(&block49);
        if (label21.is_used()) {
            ca_.Bind(&label21);
            ca_.Goto(&block50);
        }
    }

    if (block16.is_used()) {
        ca_.Bind(&block16);
        CodeStubAssembler(state_).ThrowTypeError(
            TNode<Context> { parameter0 }, MessageTemplate::kFirstArgumentIteratorSymbolNonCallable, kBuiltinNameFrom_0(state_));
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Branch(tmp9, &block19, std::vector<compiler::Node*> {}, &block20, std::vector<compiler::Node*> {});
    }

    if (block19.is_used()) {
        ca_.Bind(&block19);
        ca_.Goto(&block18, ca_.Uninitialized<UintPtrT>());
    }

    TNode<JSFunction> tmp22;
    if (block20.is_used()) {
        ca_.Bind(&block20);
        compiler::CodeAssemblerLabel label23(&ca_);
        tmp22 = Cast_JSFunction_0(state_, TNode<HeapObject> { tmp14 }, &label23);
        ca_.Goto(&block21);
        if (label23.is_used()) {
            ca_.Bind(&label23);
            ca_.Goto(&block22);
        }
    }

    if (block22.is_used()) {
        ca_.Bind(&block22);
        ca_.Goto(&block18, ca_.Uninitialized<UintPtrT>());
    }

    TNode<BoolT> tmp24;
    if (block21.is_used()) {
        ca_.Bind(&block21);
        tmp24 = CodeStubAssembler(state_).IsArrayIteratorProtectorCellInvalid();
        ca_.Branch(tmp24, &block23, std::vector<compiler::Node*> {}, &block24, std::vector<compiler::Node*> {});
    }

    if (block23.is_used()) {
        ca_.Bind(&block23);
        ca_.Goto(&block18, ca_.Uninitialized<UintPtrT>());
    }

    TNode<JSArray> tmp25;
    if (block24.is_used()) {
        ca_.Bind(&block24);
        compiler::CodeAssemblerLabel label26(&ca_);
        tmp25 = Cast_JSArray_1(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp1 }, &label26);
        ca_.Goto(&block27);
        if (label26.is_used()) {
            ca_.Bind(&label26);
            ca_.Goto(&block28);
        }
    }

    TNode<JSTypedArray> tmp27;
    if (block28.is_used()) {
        ca_.Bind(&block28);
        compiler::CodeAssemblerLabel label28(&ca_);
        tmp27 = Cast_JSTypedArray_1(state_, TNode<Context> { parameter0 }, TNode<Object> { ca_.UncheckedCast<Object>(tmp1) }, &label28);
        ca_.Goto(&block33);
        if (label28.is_used()) {
            ca_.Bind(&label28);
            ca_.Goto(&block34);
        }
    }

    TNode<IntPtrT> tmp29;
    TNode<SharedFunctionInfo> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<Object> tmp32;
    TNode<Smi> tmp33;
    TNode<BoolT> tmp34;
    TNode<BoolT> tmp35;
    if (block27.is_used()) {
        ca_.Bind(&block27);
        tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp30 = CodeStubAssembler(state_).LoadReference<SharedFunctionInfo>(CodeStubAssembler::Reference { tmp22, tmp29 });
        tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp32 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp30, tmp31 });
        tmp33 = CodeStubAssembler(state_).SmiConstant(Builtin::kArrayPrototypeValues);
        tmp34 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject> { tmp32 }, TNode<MaybeObject> { tmp33 });
        tmp35 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp34 });
        ca_.Branch(tmp35, &block29, std::vector<compiler::Node*> {}, &block30, std::vector<compiler::Node*> {});
    }

    if (block29.is_used()) {
        ca_.Bind(&block29);
        ca_.Goto(&block18, ca_.Uninitialized<UintPtrT>());
    }

    TNode<IntPtrT> tmp36;
    TNode<Number> tmp37;
    TNode<UintPtrT> tmp38;
    if (block30.is_used()) {
        ca_.Bind(&block30);
        tmp36 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp37 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference { tmp25, tmp36 });
        tmp38 = Convert_uintptr_Number_0(state_, TNode<Number> { tmp37 });
        ca_.Goto(&block25, tmp38, tmp1);
    }

    TNode<JSSet> tmp39;
    if (block34.is_used()) {
        ca_.Bind(&block34);
        compiler::CodeAssemblerLabel label40(&ca_);
        tmp39 = Cast_JSSet_1(state_, TNode<Context> { parameter0 }, TNode<Object> { ca_.UncheckedCast<Object>(tmp1) }, &label40);
        ca_.Goto(&block41);
        if (label40.is_used()) {
            ca_.Bind(&label40);
            ca_.Goto(&block42);
        }
    }

    TNode<UintPtrT> tmp41;
    if (block33.is_used()) {
        ca_.Bind(&block33);
        compiler::CodeAssemblerLabel label42(&ca_);
        tmp41 = CodeStubAssembler(state_).LoadJSTypedArrayLengthAndCheckDetached(TNode<JSTypedArray> { tmp27 }, &label42);
        ca_.Goto(&block35);
        if (label42.is_used()) {
            ca_.Bind(&label42);
            ca_.Goto(&block36);
        }
    }

    if (block36.is_used()) {
        ca_.Bind(&block36);
        ca_.Goto(&block18, ca_.Uninitialized<UintPtrT>());
    }

    TNode<IntPtrT> tmp43;
    TNode<SharedFunctionInfo> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<Object> tmp46;
    TNode<Smi> tmp47;
    TNode<BoolT> tmp48;
    TNode<BoolT> tmp49;
    if (block35.is_used()) {
        ca_.Bind(&block35);
        tmp43 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp44 = CodeStubAssembler(state_).LoadReference<SharedFunctionInfo>(CodeStubAssembler::Reference { tmp22, tmp43 });
        tmp45 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp46 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp44, tmp45 });
        tmp47 = CodeStubAssembler(state_).SmiConstant(Builtin::kTypedArrayPrototypeValues);
        tmp48 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject> { tmp46 }, TNode<MaybeObject> { tmp47 });
        tmp49 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp48 });
        ca_.Branch(tmp49, &block37, std::vector<compiler::Node*> {}, &block38, std::vector<compiler::Node*> {});
    }

    if (block37.is_used()) {
        ca_.Bind(&block37);
        ca_.Goto(&block18, tmp41);
    }

    if (block38.is_used()) {
        ca_.Bind(&block38);
        ca_.Goto(&block31, tmp41, tmp1);
    }

    if (block42.is_used()) {
        ca_.Bind(&block42);
        ca_.Goto(&block18, ca_.Uninitialized<UintPtrT>());
    }

    TNode<IntPtrT> tmp50;
    TNode<SharedFunctionInfo> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<Object> tmp53;
    TNode<Smi> tmp54;
    TNode<BoolT> tmp55;
    TNode<BoolT> tmp56;
    if (block41.is_used()) {
        ca_.Bind(&block41);
        tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp51 = CodeStubAssembler(state_).LoadReference<SharedFunctionInfo>(CodeStubAssembler::Reference { tmp22, tmp50 });
        tmp52 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp53 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp51, tmp52 });
        tmp54 = CodeStubAssembler(state_).SmiConstant(Builtin::kSetPrototypeValues);
        tmp55 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject> { tmp53 }, TNode<MaybeObject> { tmp54 });
        tmp56 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp55 });
        ca_.Branch(tmp56, &block43, std::vector<compiler::Node*> {}, &block44, std::vector<compiler::Node*> {});
    }

    if (block43.is_used()) {
        ca_.Bind(&block43);
        ca_.Goto(&block18, ca_.Uninitialized<UintPtrT>());
    }

    TNode<JSArray> tmp57;
    if (block44.is_used()) {
        ca_.Bind(&block44);
        compiler::CodeAssemblerLabel label58(&ca_);
        tmp57 = IteratorBuiltinsAssembler(state_).FastIterableToList(TNode<Context> { parameter0 }, TNode<Object> { tmp39 }, &label58);
        ca_.Goto(&block45);
        if (label58.is_used()) {
            ca_.Bind(&label58);
            ca_.Goto(&block46);
        }
    }

    if (block46.is_used()) {
        ca_.Bind(&block46);
        ca_.Goto(&block18, ca_.Uninitialized<UintPtrT>());
    }

    TNode<IntPtrT> tmp59;
    TNode<Number> tmp60;
    TNode<UintPtrT> tmp61;
    if (block45.is_used()) {
        ca_.Bind(&block45);
        tmp59 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp60 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference { tmp57, tmp59 });
        tmp61 = Convert_uintptr_Number_0(state_, TNode<Number> { tmp60 });
        ca_.Goto(&block31, tmp61, tmp57);
    }

    TNode<UintPtrT> phi_bb31_11;
    TNode<Object> phi_bb31_12;
    if (block31.is_used()) {
        ca_.Bind(&block31, &phi_bb31_11, &phi_bb31_12);
        ca_.Goto(&block25, phi_bb31_11, phi_bb31_12);
    }

    TNode<UintPtrT> phi_bb25_11;
    TNode<Object> phi_bb25_12;
    if (block25.is_used()) {
        ca_.Bind(&block25, &phi_bb25_11, &phi_bb25_12);
        ca_.Goto(&block17, phi_bb25_11, phi_bb25_12);
    }

    TNode<UintPtrT> phi_bb18_11;
    TNode<JSArray> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<Number> tmp64;
    TNode<UintPtrT> tmp65;
    if (block18.is_used()) {
        ca_.Bind(&block18, &phi_bb18_11);
        tmp62 = ca_.CallBuiltin<JSArray>(Builtin::kIterableToList, parameter0, tmp1, tmp14);
        tmp63 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp64 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference { tmp62, tmp63 });
        tmp65 = Convert_uintptr_Number_0(state_, TNode<Number> { tmp64 });
        ca_.Goto(&block17, tmp65, tmp62);
    }

    TNode<UintPtrT> phi_bb17_11;
    TNode<Object> phi_bb17_12;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_11, &phi_bb17_12);
        ca_.Goto(&block12, phi_bb17_11, phi_bb17_12);
    }

    if (block50.is_used()) {
        ca_.Bind(&block50);
        CodeStubAssembler(state_).ThrowRangeError(TNode<Context> { parameter0 }, MessageTemplate::kInvalidTypedArrayLength, TNode<Object> { tmp19 });
    }

    if (block49.is_used()) {
        ca_.Bind(&block49);
        ca_.Goto(&block12, tmp20, tmp18);
    }

    TNode<UintPtrT> phi_bb12_11;
    TNode<Object> phi_bb12_12;
    TNode<Number> tmp66;
    TNode<JSTypedArray> tmp67;
    TNode<BoolT> tmp68;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_11, &phi_bb12_12);
        tmp66 = Convert_Number_uintptr_0(state_, TNode<UintPtrT> { phi_bb12_11 });
        tmp67 = TypedArrayCreateByLength_0(
            state_, TNode<Context> { parameter0 }, TNode<JSReceiver> { tmp6 }, TNode<Number> { tmp66 }, kBuiltinNameFrom_0(state_));
        tmp68 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp9 });
        ca_.Branch(
            tmp68, &block51, std::vector<compiler::Node*> { phi_bb12_11, phi_bb12_12 }, &block52, std::vector<compiler::Node*> { phi_bb12_11, phi_bb12_12 });
    }

    TNode<UintPtrT> phi_bb51_11;
    TNode<Object> phi_bb51_12;
    TNode<UintPtrT> tmp69;
    TNode<BoolT> tmp70;
    if (block51.is_used()) {
        ca_.Bind(&block51, &phi_bb51_11, &phi_bb51_12);
        tmp69 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp70 = CodeStubAssembler(state_).WordNotEqual(TNode<UintPtrT> { phi_bb51_11 }, TNode<UintPtrT> { tmp69 });
        ca_.Branch(
            tmp70, &block53, std::vector<compiler::Node*> { phi_bb51_11, phi_bb51_12 }, &block54, std::vector<compiler::Node*> { phi_bb51_11, phi_bb51_12 });
    }

    TNode<UintPtrT> phi_bb53_11;
    TNode<Object> phi_bb53_12;
    if (block53.is_used()) {
        ca_.Bind(&block53, &phi_bb53_11, &phi_bb53_12);
        CodeStubAssembler(state_).CallRuntime(Runtime::kTypedArrayCopyElements, parameter0, tmp67, phi_bb53_12, tmp66);
        ca_.Goto(&block54, phi_bb53_11, phi_bb53_12);
    }

    TNode<UintPtrT> phi_bb54_11;
    TNode<Object> phi_bb54_12;
    if (block54.is_used()) {
        ca_.Bind(&block54, &phi_bb54_11, &phi_bb54_12);
        arguments.PopAndReturn(tmp67);
    }

    TNode<UintPtrT> phi_bb52_11;
    TNode<Object> phi_bb52_12;
    TNode<JSReceiver> tmp71;
    if (block52.is_used()) {
        ca_.Bind(&block52, &phi_bb52_11, &phi_bb52_12);
        compiler::CodeAssemblerLabel label72(&ca_);
        tmp71 = Cast_Callable_1(state_, TNode<Context> { parameter0 }, TNode<Object> { tmp3 }, &label72);
        ca_.Goto(&block57, phi_bb52_11, phi_bb52_12);
        if (label72.is_used()) {
            ca_.Bind(&label72);
            ca_.Goto(&block58, phi_bb52_11, phi_bb52_12);
        }
    }

    TNode<UintPtrT> phi_bb58_11;
    TNode<Object> phi_bb58_12;
    if (block58.is_used()) {
        ca_.Bind(&block58, &phi_bb58_11, &phi_bb58_12);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> phi_bb57_11;
    TNode<Object> phi_bb57_12;
    TNode<Int32T> tmp73;
    TNode<BuiltinPtr> tmp74;
    TNode<BuiltinPtr> tmp75;
    TNode<BuiltinPtr> tmp76;
    TNode<UintPtrT> tmp77;
    if (block57.is_used()) {
        ca_.Bind(&block57, &phi_bb57_11, &phi_bb57_12);
        tmp73 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray> { tmp67 });
        std::tie(tmp74, tmp75, tmp76) = GetTypedArrayAccessor_0(state_, TNode<Int32T> { tmp73 }).Flatten();
        tmp77 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block61, phi_bb57_11, phi_bb57_12, tmp77);
    }

    TNode<UintPtrT> phi_bb61_11;
    TNode<Object> phi_bb61_12;
    TNode<UintPtrT> phi_bb61_19;
    TNode<BoolT> tmp78;
    if (block61.is_used()) {
        ca_.Bind(&block61, &phi_bb61_11, &phi_bb61_12, &phi_bb61_19);
        tmp78 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { phi_bb61_19 }, TNode<UintPtrT> { phi_bb61_11 });
        ca_.Branch(tmp78, &block59, std::vector<compiler::Node*> { phi_bb61_11, phi_bb61_12, phi_bb61_19 }, &block60,
            std::vector<compiler::Node*> { phi_bb61_11, phi_bb61_12, phi_bb61_19 });
    }

    TNode<UintPtrT> phi_bb59_11;
    TNode<Object> phi_bb59_12;
    TNode<UintPtrT> phi_bb59_19;
    TNode<Number> tmp79;
    TNode<Object> tmp80;
    if (block59.is_used()) {
        ca_.Bind(&block59, &phi_bb59_11, &phi_bb59_12, &phi_bb59_19);
        tmp79 = Convert_Number_uintptr_0(state_, TNode<UintPtrT> { phi_bb59_19 });
        tmp80 = CodeStubAssembler(state_).GetProperty(TNode<Context> { parameter0 }, TNode<Object> { phi_bb59_12 }, TNode<Object> { tmp79 });
        ca_.Branch(tmp9, &block63, std::vector<compiler::Node*> { phi_bb59_11, phi_bb59_12, phi_bb59_19 }, &block64,
            std::vector<compiler::Node*> { phi_bb59_11, phi_bb59_12, phi_bb59_19 });
    }

    TNode<UintPtrT> phi_bb63_11;
    TNode<Object> phi_bb63_12;
    TNode<UintPtrT> phi_bb63_19;
    TNode<Object> tmp81;
    if (block63.is_used()) {
        ca_.Bind(&block63, &phi_bb63_11, &phi_bb63_12, &phi_bb63_19);
        tmp81 = CodeStubAssembler(state_).Call(
            TNode<Context> { parameter0 }, TNode<Object> { tmp71 }, TNode<Object> { tmp5 }, TNode<Object> { tmp80 }, TNode<Object> { tmp79 });
        ca_.Goto(&block65, phi_bb63_11, phi_bb63_12, phi_bb63_19, tmp81);
    }

    TNode<UintPtrT> phi_bb64_11;
    TNode<Object> phi_bb64_12;
    TNode<UintPtrT> phi_bb64_19;
    if (block64.is_used()) {
        ca_.Bind(&block64, &phi_bb64_11, &phi_bb64_12, &phi_bb64_19);
        ca_.Goto(&block65, phi_bb64_11, phi_bb64_12, phi_bb64_19, tmp80);
    }

    TNode<UintPtrT> phi_bb65_11;
    TNode<Object> phi_bb65_12;
    TNode<UintPtrT> phi_bb65_19;
    TNode<Object> phi_bb65_22;
    TNode<Smi> tmp82;
    TNode<UintPtrT> tmp83;
    TNode<UintPtrT> tmp84;
    if (block65.is_used()) {
        ca_.Bind(&block65, &phi_bb65_11, &phi_bb65_12, &phi_bb65_19, &phi_bb65_22);
        tmp82 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(
            Builtins::CallInterfaceDescriptorFor(ExampleBuiltinForTorqueFunctionPointerType(3)), tmp76, parameter0, tmp67, phi_bb65_19, phi_bb65_22));
        tmp83 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
        tmp84 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT> { phi_bb65_19 }, TNode<UintPtrT> { tmp83 });
        ca_.Goto(&block61, phi_bb65_11, phi_bb65_12, tmp84);
    }

    TNode<UintPtrT> phi_bb60_11;
    TNode<Object> phi_bb60_12;
    TNode<UintPtrT> phi_bb60_19;
    if (block60.is_used()) {
        ca_.Bind(&block60, &phi_bb60_11, &phi_bb60_12, &phi_bb60_19);
        arguments.PopAndReturn(tmp67);
    }
}

} // namespace internal
} // namespace v8
