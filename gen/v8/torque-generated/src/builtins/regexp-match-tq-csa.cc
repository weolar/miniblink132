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
#include "torque-generated/src/builtins/regexp-match-tq-csa.h"
#include "torque-generated/src/builtins/array-flat-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/boolean-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/growable-fixed-array-tq-csa.h"
#include "torque-generated/src/builtins/number-tq-csa.h"
#include "torque-generated/src/builtins/regexp-exec-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-all-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-tq-csa.h"
#include "torque-generated/src/builtins/regexp-replace-tq-csa.h"
#include "torque-generated/src/builtins/regexp-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/src/objects/regexp-match-info-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=25&c=1
TNode<Object> RegExpPrototypeMatchBody_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_regexp, TNode<String> p_string, bool p_isFastPath)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, String> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT, HeapObject> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block69(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT> block88(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT> block89(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block92(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block93(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block94(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block95(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block96(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block101(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block102(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block103(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<FixedArray, IntPtrT, IntPtrT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block108(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        if ((p_isFastPath)) {
            ca_.Goto(&block2);
        } else {
            ca_.Goto(&block3);
        }
    }

    if (block2.is_used()) {
        ca_.Bind(&block2);
        ca_.Goto(&block4);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block4);
    }

    TNode<BoolT> tmp0;
    TNode<BoolT> tmp1;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp0 = RegExpBuiltinsAssembler(state_).FlagGetter(TNode<Context> { p_context }, TNode<Object> { p_regexp }, JSRegExp::Flag::kGlobal, p_isFastPath);
        tmp1 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp0 });
        ca_.Branch(tmp1, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp2;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, p_isFastPath);
        ca_.Branch(tmp2, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    TNode<Object> tmp3;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp3 = RegExpPrototypeExecBodyFast_0(state_, TNode<Context> { p_context }, TNode<JSReceiver> { p_regexp }, TNode<String> { p_string });
        ca_.Goto(&block13, tmp3);
    }

    TNode<Object> tmp4;
    if (block12.is_used()) {
        ca_.Bind(&block12);
        tmp4 = RegExpExec_0(state_, TNode<Context> { p_context }, TNode<JSReceiver> { p_regexp }, TNode<String> { p_string });
        ca_.Goto(&block13, tmp4);
    }

    TNode<Object> phi_bb13_4;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_4);
        ca_.Goto(&block1, phi_bb13_4);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        if ((p_isFastPath)) {
            ca_.Goto(&block19);
        } else {
            ca_.Goto(&block20);
        }
    }

    TNode<JSRegExp> tmp5;
    TNode<TrustedObject> tmp6;
    TNode<RegExpData> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<Smi> tmp9;
    TNode<Number> tmp10;
    TNode<BoolT> tmp11;
    if (block19.is_used()) {
        ca_.Bind(&block19);
        tmp5 = UnsafeCast_JSRegExp_0(state_, TNode<Context> { p_context }, TNode<Object> { p_regexp });
        tmp6 = CodeStubAssembler(state_).LoadTrustedPointerFromObject(TNode<HeapObject> { tmp5 }, JSRegExp::kDataOffset, kRegExpDataIndirectPointerTag);
        tmp7 = UnsafeCast_RegExpData_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp6 });
        tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp9 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp7, tmp8 });
        tmp10 = FromConstexpr_Number_constexpr_uint32_0(state_, static_cast<uint8_t>(RegExpData::Type::ATOM));
        tmp11 = IsNumberEqual_0(state_, TNode<Number> { tmp9 }, TNode<Number> { tmp10 });
        ca_.Branch(tmp11, &block22, std::vector<compiler::Node*> {}, &block23, std::vector<compiler::Node*> {});
    }

    TNode<Object> tmp12;
    if (block22.is_used()) {
        ca_.Bind(&block22);
        tmp12 = CodeStubAssembler(state_).CallRuntime(Runtime::kRegExpMatchGlobalAtom, p_context, tmp5, p_string, tmp7);
        ca_.Goto(&block1, tmp12);
    }

    if (block23.is_used()) {
        ca_.Bind(&block23);
        ca_.Goto(&block21);
    }

    if (block20.is_used()) {
        ca_.Bind(&block20);
        ca_.Goto(&block21);
    }

    TNode<BoolT> tmp13;
    if (block21.is_used()) {
        ca_.Bind(&block21);
        tmp13 = RegExpBuiltinsAssembler(state_).FlagGetter(TNode<Context> { p_context }, TNode<Object> { p_regexp }, JSRegExp::Flag::kUnicode, p_isFastPath);
        ca_.Branch(tmp13, &block24, std::vector<compiler::Node*> {}, &block25, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp14;
    if (block24.is_used()) {
        ca_.Bind(&block24);
        tmp14 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block26, tmp14);
    }

    TNode<BoolT> tmp15;
    if (block25.is_used()) {
        ca_.Bind(&block25);
        tmp15
            = RegExpBuiltinsAssembler(state_).FlagGetter(TNode<Context> { p_context }, TNode<Object> { p_regexp }, JSRegExp::Flag::kUnicodeSets, p_isFastPath);
        ca_.Goto(&block26, tmp15);
    }

    TNode<BoolT> phi_bb26_5;
    TNode<Number> tmp16;
    TNode<FixedArray> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<IntPtrT> tmp19;
    if (block26.is_used()) {
        ca_.Bind(&block26, &phi_bb26_5);
        tmp16 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        StoreLastIndex_0(state_, TNode<Context> { p_context }, TNode<Object> { p_regexp }, TNode<Number> { tmp16 }, p_isFastPath);
        std::tie(tmp17, tmp18, tmp19) = NewGrowableFixedArray_0(state_).Flatten();
        ca_.Goto(&block29, tmp17, tmp18, tmp19);
    }

    TNode<FixedArray> phi_bb29_5;
    TNode<IntPtrT> phi_bb29_6;
    TNode<IntPtrT> phi_bb29_7;
    TNode<BoolT> tmp20;
    if (block29.is_used()) {
        ca_.Bind(&block29, &phi_bb29_5, &phi_bb29_6, &phi_bb29_7);
        tmp20 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp20, &block27, std::vector<compiler::Node*> { phi_bb29_5, phi_bb29_6, phi_bb29_7 }, &block28,
            std::vector<compiler::Node*> { phi_bb29_5, phi_bb29_6, phi_bb29_7 });
    }

    TNode<FixedArray> phi_bb27_5;
    TNode<IntPtrT> phi_bb27_6;
    TNode<IntPtrT> phi_bb27_7;
    TNode<String> tmp21;
    if (block27.is_used()) {
        ca_.Bind(&block27, &phi_bb27_5, &phi_bb27_6, &phi_bb27_7);
        tmp21 = CodeStubAssembler(state_).EmptyStringConstant();
        if ((p_isFastPath)) {
            ca_.Goto(&block34, phi_bb27_5, phi_bb27_6, phi_bb27_7);
        } else {
            ca_.Goto(&block35, phi_bb27_5, phi_bb27_6, phi_bb27_7);
        }
    }

    TNode<FixedArray> phi_bb34_5;
    TNode<IntPtrT> phi_bb34_6;
    TNode<IntPtrT> phi_bb34_7;
    TNode<JSRegExp> tmp22;
    TNode<RegExpMatchInfo> tmp23;
    if (block34.is_used()) {
        ca_.Bind(&block34, &phi_bb34_5, &phi_bb34_6, &phi_bb34_7);
        tmp22 = UnsafeCast_JSRegExp_0(state_, TNode<Context> { p_context }, TNode<Object> { p_regexp });
        compiler::CodeAssemblerLabel label24(&ca_);
        tmp23
            = RegExpPrototypeExecBodyWithoutResultFast_0(state_, TNode<Context> { p_context }, TNode<JSRegExp> { tmp22 }, TNode<String> { p_string }, &label24);
        ca_.Goto(&block37, phi_bb34_5, phi_bb34_6, phi_bb34_7);
        if (label24.is_used()) {
            ca_.Bind(&label24);
            ca_.Goto(&block38, phi_bb34_5, phi_bb34_6, phi_bb34_7);
        }
    }

    TNode<FixedArray> phi_bb38_5;
    TNode<IntPtrT> phi_bb38_6;
    TNode<IntPtrT> phi_bb38_7;
    if (block38.is_used()) {
        ca_.Bind(&block38, &phi_bb38_5, &phi_bb38_6, &phi_bb38_7);
        ca_.Goto(&block33, phi_bb38_5, phi_bb38_6, phi_bb38_7);
    }

    TNode<FixedArray> phi_bb37_5;
    TNode<IntPtrT> phi_bb37_6;
    TNode<IntPtrT> phi_bb37_7;
    TNode<Smi> tmp25;
    TNode<Smi> tmp26;
    TNode<Smi> tmp27;
    TNode<Smi> tmp28;
    TNode<String> tmp29;
    if (block37.is_used()) {
        ca_.Bind(&block37, &phi_bb37_5, &phi_bb37_6, &phi_bb37_7);
        tmp25 = Method_RegExpMatchInfo_GetStartOfCapture_0(
            state_, TNode<RegExpMatchInfo> { tmp23 }, (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull))));
        tmp26 = Method_RegExpMatchInfo_GetEndOfCapture_0(
            state_, TNode<RegExpMatchInfo> { tmp23 }, (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull))));
        tmp27 = UnsafeCast_Smi_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp25 });
        tmp28 = UnsafeCast_Smi_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp26 });
        tmp29 = ca_.CallBuiltin<String>(Builtin::kSubString, p_context, p_string, tmp27, tmp28);
        ca_.Goto(&block36, phi_bb37_5, phi_bb37_6, phi_bb37_7, tmp29);
    }

    TNode<FixedArray> phi_bb35_5;
    TNode<IntPtrT> phi_bb35_6;
    TNode<IntPtrT> phi_bb35_7;
    TNode<Object> tmp30;
    TNode<Null> tmp31;
    TNode<BoolT> tmp32;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_5, &phi_bb35_6, &phi_bb35_7);
        tmp30 = RegExpExec_0(state_, TNode<Context> { p_context }, TNode<JSReceiver> { p_regexp }, TNode<String> { p_string });
        tmp31 = Null_0(state_);
        tmp32 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { tmp30 }, TNode<HeapObject> { tmp31 });
        ca_.Branch(tmp32, &block43, std::vector<compiler::Node*> { phi_bb35_5, phi_bb35_6, phi_bb35_7 }, &block44,
            std::vector<compiler::Node*> { phi_bb35_5, phi_bb35_6, phi_bb35_7 });
    }

    TNode<FixedArray> phi_bb43_5;
    TNode<IntPtrT> phi_bb43_6;
    TNode<IntPtrT> phi_bb43_7;
    if (block43.is_used()) {
        ca_.Bind(&block43, &phi_bb43_5, &phi_bb43_6, &phi_bb43_7);
        ca_.Goto(&block33, phi_bb43_5, phi_bb43_6, phi_bb43_7);
    }

    TNode<FixedArray> phi_bb44_5;
    TNode<IntPtrT> phi_bb44_6;
    TNode<IntPtrT> phi_bb44_7;
    TNode<Smi> tmp33;
    TNode<Object> tmp34;
    TNode<String> tmp35;
    if (block44.is_used()) {
        ca_.Bind(&block44, &phi_bb44_5, &phi_bb44_6, &phi_bb44_7);
        tmp33 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
        tmp34 = CodeStubAssembler(state_).GetProperty(TNode<Context> { p_context }, TNode<Object> { tmp30 }, TNode<Object> { tmp33 });
        tmp35 = CodeStubAssembler(state_).ToString_Inline(TNode<Context> { p_context }, TNode<Object> { tmp34 });
        ca_.Goto(&block36, phi_bb44_5, phi_bb44_6, phi_bb44_7, tmp35);
    }

    TNode<FixedArray> phi_bb36_5;
    TNode<IntPtrT> phi_bb36_6;
    TNode<IntPtrT> phi_bb36_7;
    TNode<String> phi_bb36_8;
    TNode<BoolT> tmp36;
    if (block36.is_used()) {
        ca_.Bind(&block36, &phi_bb36_5, &phi_bb36_6, &phi_bb36_7, &phi_bb36_8);
        tmp36 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT> { phi_bb36_6 }, TNode<IntPtrT> { phi_bb36_7 });
        ca_.Branch(tmp36, &block69, std::vector<compiler::Node*> { phi_bb36_5, phi_bb36_6, phi_bb36_7 }, &block70,
            std::vector<compiler::Node*> { phi_bb36_5, phi_bb36_6, phi_bb36_7 });
    }

    TNode<FixedArray> phi_bb33_5;
    TNode<IntPtrT> phi_bb33_6;
    TNode<IntPtrT> phi_bb33_7;
    TNode<IntPtrT> tmp37;
    TNode<BoolT> tmp38;
    if (block33.is_used()) {
        ca_.Bind(&block33, &phi_bb33_5, &phi_bb33_6, &phi_bb33_7);
        tmp37 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp38 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT> { phi_bb33_7 }, TNode<IntPtrT> { tmp37 });
        ca_.Branch(tmp38, &block45, std::vector<compiler::Node*> { phi_bb33_5, phi_bb33_6, phi_bb33_7 }, &block46,
            std::vector<compiler::Node*> { phi_bb33_5, phi_bb33_6, phi_bb33_7 });
    }

    TNode<FixedArray> phi_bb45_5;
    TNode<IntPtrT> phi_bb45_6;
    TNode<IntPtrT> phi_bb45_7;
    TNode<Null> tmp39;
    if (block45.is_used()) {
        ca_.Bind(&block45, &phi_bb45_5, &phi_bb45_6, &phi_bb45_7);
        tmp39 = Null_0(state_);
        ca_.Goto(&block47, phi_bb45_5, phi_bb45_6, phi_bb45_7, tmp39);
    }

    TNode<FixedArray> phi_bb46_5;
    TNode<IntPtrT> phi_bb46_6;
    TNode<IntPtrT> phi_bb46_7;
    TNode<NativeContext> tmp40;
    TNode<Map> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<Hole> tmp43;
    TNode<FixedArray> tmp44;
    TNode<Smi> tmp45;
    TNode<JSArray> tmp46;
    if (block46.is_used()) {
        ca_.Bind(&block46, &phi_bb46_5, &phi_bb46_6, &phi_bb46_7);
        tmp40 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context> { p_context });
        tmp41 = CodeStubAssembler(state_).LoadJSArrayElementsMap(ElementsKind::PACKED_ELEMENTS, TNode<NativeContext> { tmp40 });
        tmp42 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp43 = TheHole_0(state_);
        tmp44 = ExtractFixedArray_0(state_, TNode<FixedArray> { phi_bb46_5 }, TNode<IntPtrT> { tmp42 }, TNode<IntPtrT> { phi_bb46_7 },
            TNode<IntPtrT> { phi_bb46_7 }, TNode<Hole> { tmp43 });
        tmp45 = Convert_Smi_intptr_0(state_, TNode<IntPtrT> { phi_bb46_7 });
        tmp46 = CodeStubAssembler(state_).AllocateJSArray(TNode<Map> { tmp41 }, TNode<FixedArrayBase> { tmp44 }, TNode<Smi> { tmp45 });
        ca_.Goto(&block47, phi_bb46_5, phi_bb46_6, phi_bb46_7, tmp46);
    }

    TNode<FixedArray> phi_bb47_5;
    TNode<IntPtrT> phi_bb47_6;
    TNode<IntPtrT> phi_bb47_7;
    TNode<HeapObject> phi_bb47_9;
    if (block47.is_used()) {
        ca_.Bind(&block47, &phi_bb47_5, &phi_bb47_6, &phi_bb47_7, &phi_bb47_9);
        ca_.Goto(&block1, phi_bb47_9);
    }

    TNode<FixedArray> phi_bb69_5;
    TNode<IntPtrT> phi_bb69_6;
    TNode<IntPtrT> phi_bb69_7;
    TNode<IntPtrT> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<IntPtrT> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<Hole> tmp53;
    TNode<FixedArray> tmp54;
    if (block69.is_used()) {
        ca_.Bind(&block69, &phi_bb69_5, &phi_bb69_6, &phi_bb69_7);
        tmp47 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp48 = CodeStubAssembler(state_).WordSar(TNode<IntPtrT> { phi_bb69_6 }, TNode<IntPtrT> { tmp47 });
        tmp49 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb69_6 }, TNode<IntPtrT> { tmp48 });
        tmp50 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x10ull));
        tmp51 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp49 }, TNode<IntPtrT> { tmp50 });
        tmp52 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp53 = TheHole_0(state_);
        tmp54 = ExtractFixedArray_0(
            state_, TNode<FixedArray> { phi_bb69_5 }, TNode<IntPtrT> { tmp52 }, TNode<IntPtrT> { phi_bb69_7 }, TNode<IntPtrT> { tmp51 }, TNode<Hole> { tmp53 });
        ca_.Goto(&block70, tmp54, tmp51, phi_bb69_7);
    }

    TNode<FixedArray> phi_bb70_5;
    TNode<IntPtrT> phi_bb70_6;
    TNode<IntPtrT> phi_bb70_7;
    TNode<Object> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<UintPtrT> tmp60;
    TNode<UintPtrT> tmp61;
    TNode<BoolT> tmp62;
    if (block70.is_used()) {
        ca_.Bind(&block70, &phi_bb70_5, &phi_bb70_6, &phi_bb70_7);
        std::tie(tmp55, tmp56, tmp57) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { phi_bb70_5 }).Flatten();
        tmp58 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
        tmp59 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb70_7 }, TNode<IntPtrT> { tmp58 });
        tmp60 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { phi_bb70_7 });
        tmp61 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp57 });
        tmp62 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp60 }, TNode<UintPtrT> { tmp61 });
        ca_.Branch(tmp62, &block88, std::vector<compiler::Node*> { phi_bb70_7, phi_bb70_7, phi_bb70_7, phi_bb70_7 }, &block89,
            std::vector<compiler::Node*> { phi_bb70_7, phi_bb70_7, phi_bb70_7, phi_bb70_7 });
    }

    TNode<IntPtrT> phi_bb88_15;
    TNode<IntPtrT> phi_bb88_16;
    TNode<IntPtrT> phi_bb88_20;
    TNode<IntPtrT> phi_bb88_21;
    TNode<IntPtrT> tmp63;
    TNode<IntPtrT> tmp64;
    TNode<Object> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<Smi> tmp67;
    TNode<Smi> tmp68;
    TNode<BoolT> tmp69;
    if (block88.is_used()) {
        ca_.Bind(&block88, &phi_bb88_15, &phi_bb88_16, &phi_bb88_20, &phi_bb88_21);
        tmp63 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { phi_bb88_21 });
        tmp64 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp56 }, TNode<IntPtrT> { tmp63 });
        std::tie(tmp65, tmp66) = NewReference_Object_0(state_, TNode<Object> { tmp55 }, TNode<IntPtrT> { tmp64 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp65, tmp66 }, phi_bb36_8);
        tmp67 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String> { phi_bb36_8 });
        tmp68 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp69 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi> { tmp67 }, TNode<Smi> { tmp68 });
        ca_.Branch(tmp69, &block92, std::vector<compiler::Node*> {}, &block93, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> phi_bb89_15;
    TNode<IntPtrT> phi_bb89_16;
    TNode<IntPtrT> phi_bb89_20;
    TNode<IntPtrT> phi_bb89_21;
    if (block89.is_used()) {
        ca_.Bind(&block89, &phi_bb89_15, &phi_bb89_16, &phi_bb89_20, &phi_bb89_21);
        CodeStubAssembler(state_).Unreachable();
    }

    if (block92.is_used()) {
        ca_.Bind(&block92);
        ca_.Goto(&block29, phi_bb70_5, phi_bb70_6, tmp59);
    }

    TNode<Object> tmp70;
    if (block93.is_used()) {
        ca_.Bind(&block93);
        tmp70 = LoadLastIndex_0(state_, TNode<Context> { p_context }, TNode<Object> { p_regexp }, p_isFastPath);
        if ((p_isFastPath)) {
            ca_.Goto(&block94);
        } else {
            ca_.Goto(&block95);
        }
    }

    if (block94.is_used()) {
        ca_.Bind(&block94);
        ca_.Goto(&block96, tmp70);
    }

    TNode<Number> tmp71;
    if (block95.is_used()) {
        ca_.Bind(&block95);
        tmp71 = CodeStubAssembler(state_).ToLength_Inline(TNode<Context> { p_context }, TNode<Object> { tmp70 });
        ca_.Goto(&block96, tmp71);
    }

    TNode<Object> phi_bb96_10;
    TNode<Number> tmp72;
    TNode<Number> tmp73;
    if (block96.is_used()) {
        ca_.Bind(&block96, &phi_bb96_10);
        tmp72 = UnsafeCast_Number_0(state_, TNode<Context> { p_context }, TNode<Object> { phi_bb96_10 });
        tmp73 = RegExpBuiltinsAssembler(state_).AdvanceStringIndex(
            TNode<String> { p_string }, TNode<Number> { tmp72 }, TNode<BoolT> { phi_bb26_5 }, p_isFastPath);
        if ((p_isFastPath)) {
            ca_.Goto(&block101);
        } else {
            ca_.Goto(&block102);
        }
    }

    if (block101.is_used()) {
        ca_.Bind(&block101);
        StaticAssertStringLengthFitsSmi_0(state_);
        ca_.Goto(&block103);
    }

    if (block102.is_used()) {
        ca_.Bind(&block102);
        ca_.Goto(&block103);
    }

    if (block103.is_used()) {
        ca_.Bind(&block103);
        StoreLastIndex_0(state_, TNode<Context> { p_context }, TNode<Object> { p_regexp }, TNode<Number> { tmp73 }, p_isFastPath);
        ca_.Goto(&block29, phi_bb70_5, phi_bb70_6, tmp59);
    }

    TNode<FixedArray> phi_bb28_5;
    TNode<IntPtrT> phi_bb28_6;
    TNode<IntPtrT> phi_bb28_7;
    if (block28.is_used()) {
        ca_.Bind(&block28, &phi_bb28_5, &phi_bb28_6, &phi_bb28_7);
        VerifiedUnreachable_0(state_);
    }

    TNode<Object> phi_bb1_3;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_3);
        ca_.Goto(&block108);
    }

    ca_.Bind(&block108);
    return TNode<Object> { phi_bb1_3 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=117&c=1
TNode<Object> FastRegExpPrototypeMatchBody_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_receiver, TNode<String> p_string)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = RegExpPrototypeMatchBody_0(state_, TNode<Context> { p_context }, TNode<JSReceiver> { p_receiver }, TNode<String> { p_string }, true);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Object> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=122&c=1
TNode<Object> SlowRegExpPrototypeMatchBody_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver, TNode<String> p_string)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = RegExpPrototypeMatchBody_0(state_, TNode<Context> { p_context }, TNode<JSReceiver> { p_receiver }, TNode<String> { p_string }, false);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Object> { tmp0 };
}

TF_BUILTIN(RegExpMatchFast, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<JSRegExp> parameter1 = UncheckedParameter<JSRegExp>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<String> parameter2 = UncheckedParameter<String>(Descriptor::kString);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FastRegExpPrototypeMatchBody_0(state_, TNode<Context> { parameter0 }, TNode<JSRegExp> { parameter1 }, TNode<String> { parameter2 });
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(RegExpPrototypeMatch, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kString);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSReceiver> tmp0;
    TNode<String> tmp1;
    TNode<JSRegExp> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        CodeStubAssembler(state_).ThrowIfNotJSReceiver(
            TNode<Context> { parameter0 }, TNode<Object> { parameter1 }, MessageTemplate::kIncompatibleMethodReceiver, "RegExp.prototype.@@match");
        tmp0 = UnsafeCast_JSReceiver_0(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = CodeStubAssembler(state_).ToString_Inline(TNode<Context> { parameter0 }, TNode<Object> { parameter2 });
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_FastJSRegExp_0(state_, TNode<Context> { parameter0 }, TNode<HeapObject> { tmp0 }, &label3);
        ca_.Goto(&block3);
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block4);
        }
    }

    TNode<Object> tmp4;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp4 = SlowRegExpPrototypeMatchBody_0(state_, TNode<Context> { parameter0 }, TNode<JSReceiver> { tmp0 }, TNode<String> { tmp1 });
        CodeStubAssembler(state_).Return(tmp4);
    }

    TNode<Object> tmp5;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp5 = ca_.CallBuiltin<Object>(Builtin::kRegExpMatchFast, parameter0, tmp2, tmp1);
        CodeStubAssembler(state_).Return(tmp5);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=29&c=12
TNode<BoolT> Is_FastJSRegExp_JSReceiver_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSRegExp> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_FastJSRegExp_0(state_, TNode<Context> { p_context }, TNode<HeapObject> { p_o }, &label1);
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
    return TNode<BoolT> { phi_bb1_2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=45&c=9
TNode<RegExpData> UnsafeCast_RegExpData_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<RegExpData> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = TORQUE_CAST(TNode<Object> { p_o });
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<RegExpData> { tmp0 };
}

} // namespace internal
} // namespace v8
