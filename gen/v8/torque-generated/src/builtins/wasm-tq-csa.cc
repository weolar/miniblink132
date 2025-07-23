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
#include "torque-generated/src/builtins/wasm-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-findindex-tq-csa.h"
#include "torque-generated/src/builtins/array-flat-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-splice-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/builtins-string-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/frames-tq-csa.h"
#include "torque-generated/src/builtins/ic-tq-csa.h"
#include "torque-generated/src/builtins/number-tq-csa.h"
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"
#include "torque-generated/src/objects/name-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"
#include "torque-generated/src/objects/struct-tq-csa.h"
#include "torque-generated/src/objects/intl-objects-tq-csa.h"
#include "torque-generated/src/builtins/js-to-wasm-tq-csa.h"
#include "torque-generated/src/builtins/wasm-tq-csa.h"
#include "torque-generated/src/wasm/wasm-objects-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=98&c=1
TNode<Int32T> NumberToInt32_0(compiler::CodeAssemblerState* state_, TNode<Number> p_input)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_int32_Number_0(state_, TNode<Number> { p_input });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=101&c=1
TNode<Uint32T> NumberToUint32_0(compiler::CodeAssemblerState* state_, TNode<Number> p_input)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    TNode<Uint32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_int32_Number_0(state_, TNode<Number> { p_input });
        tmp1 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Uint32T> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=143&c=1
TNode<NativeContext> LoadContextFromFrame_0(compiler::CodeAssemblerState* state_)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<NativeContext> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<NativeContext> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=147&c=1
TNode<WasmTrustedInstanceData> LoadMaybeSharedInstanceDataFromFrame_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_extractSharedData)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<WasmTrustedInstanceData> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        ca_.Branch(p_extractSharedData, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    TNode<WasmTrustedInstanceData> tmp1;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp1 = WasmBuiltinsAssembler(state_).LoadSharedPartFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        ca_.Goto(&block1, tmp1);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block1, tmp0);
    }

    TNode<WasmTrustedInstanceData> phi_bb1_1;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_1);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmTrustedInstanceData> { phi_bb1_1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=157&c=1
TNode<WasmTrustedInstanceData> LoadMaybeSharedInstanceDataFromFrame_1(compiler::CodeAssemblerState* state_, TNode<Smi> p_extractSharedData)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<WasmTrustedInstanceData> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<Smi> tmp1;
    TNode<BoolT> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
        tmp2 = CodeStubAssembler(state_).SmiEqual(TNode<Smi> { p_extractSharedData }, TNode<Smi> { tmp1 });
        ca_.Branch(tmp2, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    TNode<WasmTrustedInstanceData> tmp3;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp3 = WasmBuiltinsAssembler(state_).LoadSharedPartFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        ca_.Goto(&block1, tmp3);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block1, tmp0);
    }

    TNode<WasmTrustedInstanceData> phi_bb1_1;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_1);
        ca_.Goto(&block5);
    }

    ca_.Bind(&block5);
    return TNode<WasmTrustedInstanceData> { phi_bb1_1 };
}

TF_BUILTIN(WasmInt32ToHeapNumber, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Int32T> parameter0 = UncheckedParameter<Int32T>(Descriptor::kVal);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    TNode<HeapNumber> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_float64_int32_0(state_, TNode<Int32T> { parameter0 });
        tmp1 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T> { tmp0 });
        CodeStubAssembler(state_).Return(tmp1);
    }
}

TF_BUILTIN(WasmFuncRefToJS, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<HeapObject> parameter1 = UncheckedParameter<HeapObject>(Descriptor::kVal);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmNull> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_WasmNull_0(state_, TNode<HeapObject> { parameter1 }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    TNode<WasmInternalFunction> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<HeapObject> tmp4;
    TNode<Undefined> tmp5;
    TNode<BoolT> tmp6;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp2 = CodeStubAssembler(state_).LoadWasmInternalFunctionFromFuncRef(TNode<WasmFuncRef> { ca_.UncheckedCast<WasmFuncRef>(parameter1) });
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp4 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { tmp2, tmp3 });
        tmp5 = Undefined_0(state_);
        tmp6 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object> { tmp4 }, TNode<HeapObject> { tmp5 });
        ca_.Branch(tmp6, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    TNode<Null> tmp7;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp7 = Null_0(state_);
        CodeStubAssembler(state_).Return(tmp7);
    }

    TNode<JSFunction> tmp8;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp8 = TORQUE_CAST(TNode<Object> { tmp4 });
        CodeStubAssembler(state_).Return(tmp8);
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmInternalFunctionCreateExternal, parameter0, tmp2);
    }
}

TF_BUILTIN(WasmTaggedNonSmiToInt32, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<HeapObject> parameter1 = UncheckedParameter<HeapObject>(Descriptor::kVal);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeTaggedNonSmiToInt32(TNode<Context> { parameter0 }, TNode<HeapObject> { parameter1 });
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(WasmTaggedToFloat64, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kVal);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeTaggedToFloat64(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(WasmTaggedToFloat32, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kVal);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Float64T> tmp0;
    TNode<Float32T> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeTaggedToFloat64(TNode<Context> { parameter0 }, TNode<Object> { parameter1 });
        tmp1 = CodeStubAssembler(state_).TruncateFloat64ToFloat32(TNode<Float64T> { tmp0 });
        CodeStubAssembler(state_).Return(tmp1);
    }
}

TF_BUILTIN(WasmMemoryGrow, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Int32T> parameter0 = UncheckedParameter<Int32T>(Descriptor::kMemIndex);
    USE(parameter0);
    TNode<Int32T> parameter1 = UncheckedParameter<Int32T>(Descriptor::kNumPages);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<BoolT> tmp1;
    TNode<BoolT> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T> { parameter1 });
        tmp1 = CodeStubAssembler(state_).IsValidPositiveSmi(TNode<IntPtrT> { tmp0 });
        tmp2 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp1 });
        ca_.Branch(tmp2, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    TNode<Int32T> tmp3;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp3 = Int32Constant_0(state_, IntegerLiteral(true, 0x1ull));
        CodeStubAssembler(state_).Return(tmp3);
    }

    TNode<WasmTrustedInstanceData> tmp4;
    TNode<NativeContext> tmp5;
    TNode<Smi> tmp6;
    TNode<Smi> tmp7;
    TNode<Smi> tmp8;
    TNode<Int32T> tmp9;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp4 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp5 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp4 });
        tmp6 = CodeStubAssembler(state_).SmiFromInt32(TNode<Int32T> { parameter0 });
        tmp7 = CodeStubAssembler(state_).SmiFromInt32(TNode<Int32T> { parameter1 });
        tmp8 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmMemoryGrow, tmp5, tmp4, tmp6, tmp7));
        tmp9 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { tmp8 });
        CodeStubAssembler(state_).Return(tmp9);
    }
}

TF_BUILTIN(WasmTableInit, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kDstRaw);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kSrcRaw);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kSizeRaw);
    USE(parameter2);
    TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kTableIndex);
    USE(parameter3);
    TNode<Smi> parameter4 = UncheckedParameter<Smi>(Descriptor::kSegmentIndex);
    USE(parameter4);
    TNode<Smi> parameter5 = UncheckedParameter<Smi>(Descriptor::kExtractSharedData);
    USE(parameter5);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadMaybeSharedInstanceDataFromFrame_1(state_, TNode<Smi> { parameter5 });
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Convert_PositiveSmi_intptr_1(state_, TNode<IntPtrT> { parameter0 }, &label2);
        ca_.Goto(&block3);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(&block2);
    }

    TNode<Smi> tmp3;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        compiler::CodeAssemblerLabel label4(&ca_);
        tmp3 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T> { parameter1 }, &label4);
        ca_.Goto(&block5);
        if (label4.is_used()) {
            ca_.Bind(&label4);
            ca_.Goto(&block6);
        }
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block2);
    }

    TNode<Smi> tmp5;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        compiler::CodeAssemblerLabel label6(&ca_);
        tmp5 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T> { parameter2 }, &label6);
        ca_.Goto(&block7);
        if (label6.is_used()) {
            ca_.Bind(&label6);
            ca_.Goto(&block8);
        }
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block2);
    }

    TNode<NativeContext> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp7 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTableInit, tmp7, tmp0, parameter3, parameter4, tmp1, tmp3, tmp5);
    }

    if (block2.is_used()) {
        ca_.Bind(&block2);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
    }
}

TF_BUILTIN(WasmTableCopy, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kDstRaw);
    USE(parameter0);
    TNode<IntPtrT> parameter1 = UncheckedParameter<IntPtrT>(Descriptor::kSrcRaw);
    USE(parameter1);
    TNode<IntPtrT> parameter2 = UncheckedParameter<IntPtrT>(Descriptor::kSizeRaw);
    USE(parameter2);
    TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kDstTable);
    USE(parameter3);
    TNode<Smi> parameter4 = UncheckedParameter<Smi>(Descriptor::kSrcTable);
    USE(parameter4);
    TNode<Smi> parameter5 = UncheckedParameter<Smi>(Descriptor::kExtractSharedData);
    USE(parameter5);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadMaybeSharedInstanceDataFromFrame_1(state_, TNode<Smi> { parameter5 });
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Convert_PositiveSmi_intptr_1(state_, TNode<IntPtrT> { parameter0 }, &label2);
        ca_.Goto(&block3);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(&block2);
    }

    TNode<Smi> tmp3;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        compiler::CodeAssemblerLabel label4(&ca_);
        tmp3 = Convert_PositiveSmi_intptr_1(state_, TNode<IntPtrT> { parameter1 }, &label4);
        ca_.Goto(&block5);
        if (label4.is_used()) {
            ca_.Bind(&label4);
            ca_.Goto(&block6);
        }
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block2);
    }

    TNode<Smi> tmp5;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        compiler::CodeAssemblerLabel label6(&ca_);
        tmp5 = Convert_PositiveSmi_intptr_1(state_, TNode<IntPtrT> { parameter2 }, &label6);
        ca_.Goto(&block7);
        if (label6.is_used()) {
            ca_.Bind(&label6);
            ca_.Goto(&block8);
        }
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block2);
    }

    TNode<NativeContext> tmp7;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp7 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTableCopy, tmp7, tmp0, parameter3, parameter4, tmp1, tmp3, tmp5);
    }

    if (block2.is_used()) {
        ca_.Bind(&block2);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
    }
}

TF_BUILTIN(WasmTableFill, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kStartRaw);
    USE(parameter0);
    TNode<IntPtrT> parameter1 = UncheckedParameter<IntPtrT>(Descriptor::kCountRaw);
    USE(parameter1);
    TNode<BoolT> parameter2 = UncheckedParameter<BoolT>(Descriptor::kExtractSharedData);
    USE(parameter2);
    TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kTable);
    USE(parameter3);
    TNode<Object> parameter4 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter4);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadMaybeSharedInstanceDataFromFrame_0(state_, TNode<BoolT> { parameter2 });
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Convert_PositiveSmi_intptr_1(state_, TNode<IntPtrT> { parameter0 }, &label2);
        ca_.Goto(&block3);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(&block2);
    }

    TNode<Smi> tmp3;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        compiler::CodeAssemblerLabel label4(&ca_);
        tmp3 = Convert_PositiveSmi_intptr_1(state_, TNode<IntPtrT> { parameter1 }, &label4);
        ca_.Goto(&block5);
        if (label4.is_used()) {
            ca_.Bind(&label4);
            ca_.Goto(&block6);
        }
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block2);
    }

    TNode<NativeContext> tmp5;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp5 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTableFill, tmp5, tmp0, parameter3, tmp1, parameter4, tmp3);
    }

    if (block2.is_used()) {
        ca_.Bind(&block2);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
    }
}

TF_BUILTIN(WasmTableGrow, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Smi> parameter0 = UncheckedParameter<Smi>(Descriptor::kTable);
    USE(parameter0);
    TNode<IntPtrT> parameter1 = UncheckedParameter<IntPtrT>(Descriptor::kDeltaRaw);
    USE(parameter1);
    TNode<BoolT> parameter2 = UncheckedParameter<BoolT>(Descriptor::kExtractSharedData);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadMaybeSharedInstanceDataFromFrame_0(state_, TNode<BoolT> { parameter2 });
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Convert_PositiveSmi_intptr_1(state_, TNode<IntPtrT> { parameter1 }, &label2);
        ca_.Goto(&block3);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block4);
        }
    }

    TNode<Smi> tmp3;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp3 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(true, 0x1ull));
        CodeStubAssembler(state_).Return(tmp3);
    }

    TNode<NativeContext> tmp4;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp4 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTableGrow, tmp4, tmp0, parameter0, parameter3, tmp1);
    }
}

TF_BUILTIN(WasmTableGet, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kTableIndex);
    USE(parameter0);
    TNode<IntPtrT> parameter1 = UncheckedParameter<IntPtrT>(Descriptor::kIndex);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<FixedArray> tmp1;
    TNode<Object> tmp2;
    TNode<WasmTableObject> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Smi> tmp5;
    TNode<Int32T> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<UintPtrT> tmp8;
    TNode<UintPtrT> tmp9;
    TNode<BoolT> tmp10;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = WasmBuiltinsAssembler(state_).LoadTablesFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp2 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray> { tmp1 }, TNode<IntPtrT> { parameter0 });
        tmp3 = TORQUE_CAST(TNode<Object> { tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp3, tmp4 });
        tmp6 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { tmp5 });
        tmp7 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T> { tmp6 });
        tmp8 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { tmp7 });
        tmp9 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { parameter1 });
        tmp10 = CodeStubAssembler(state_).UintPtrGreaterThanOrEqual(TNode<UintPtrT> { tmp9 }, TNode<UintPtrT> { tmp8 });
        ca_.Branch(tmp10, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
    }

    TNode<IntPtrT> tmp11;
    TNode<FixedArray> tmp12;
    TNode<Object> tmp13;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp12 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference { tmp3, tmp11 });
        tmp13 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray> { tmp12 }, TNode<IntPtrT> { parameter1 });
        CodeStubAssembler(state_).Return(tmp13);
    }
}

TF_BUILTIN(WasmTableSet, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kTableIndex);
    USE(parameter0);
    TNode<BoolT> parameter1 = UncheckedParameter<BoolT>(Descriptor::kExtractSharedData);
    USE(parameter1);
    TNode<IntPtrT> parameter2 = UncheckedParameter<IntPtrT>(Descriptor::kIndex);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<FixedArray> tmp1;
    TNode<Object> tmp2;
    TNode<WasmTableObject> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Smi> tmp5;
    TNode<Int32T> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<UintPtrT> tmp8;
    TNode<UintPtrT> tmp9;
    TNode<BoolT> tmp10;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadMaybeSharedInstanceDataFromFrame_0(state_, TNode<BoolT> { parameter1 });
        tmp1 = WasmBuiltinsAssembler(state_).LoadTablesFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp2 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray> { tmp1 }, TNode<IntPtrT> { parameter0 });
        tmp3 = TORQUE_CAST(TNode<Object> { tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp3, tmp4 });
        tmp6 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { tmp5 });
        tmp7 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T> { tmp6 });
        tmp8 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { tmp7 });
        tmp9 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { parameter2 });
        tmp10 = CodeStubAssembler(state_).UintPtrGreaterThanOrEqual(TNode<UintPtrT> { tmp9 }, TNode<UintPtrT> { tmp8 });
        ca_.Branch(tmp10, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
    }

    TNode<IntPtrT> tmp11;
    TNode<FixedArray> tmp12;
    TNode<Undefined> tmp13;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp12 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference { tmp3, tmp11 });
        CodeStubAssembler(state_).StoreFixedArrayElement(TNode<FixedArray> { tmp12 }, TNode<IntPtrT> { parameter2 }, TNode<Object> { parameter3 });
        tmp13 = Undefined_0(state_);
        CodeStubAssembler(state_).Return(tmp13);
    }
}

TF_BUILTIN(WasmTableGetFuncRef, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kTableIndex);
    USE(parameter0);
    TNode<IntPtrT> parameter1 = UncheckedParameter<IntPtrT>(Descriptor::kIndex);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<FixedArray> tmp1;
    TNode<Object> tmp2;
    TNode<WasmTableObject> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Smi> tmp5;
    TNode<Int32T> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<UintPtrT> tmp8;
    TNode<UintPtrT> tmp9;
    TNode<BoolT> tmp10;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = WasmBuiltinsAssembler(state_).LoadTablesFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp2 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray> { tmp1 }, TNode<IntPtrT> { parameter0 });
        tmp3 = TORQUE_CAST(TNode<Object> { tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp3, tmp4 });
        tmp6 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { tmp5 });
        tmp7 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T> { tmp6 });
        tmp8 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { tmp7 });
        tmp9 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { parameter1 });
        tmp10 = CodeStubAssembler(state_).UintPtrGreaterThanOrEqual(TNode<UintPtrT> { tmp9 }, TNode<UintPtrT> { tmp8 });
        ca_.Branch(tmp10, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
    }

    TNode<IntPtrT> tmp11;
    TNode<FixedArray> tmp12;
    TNode<Object> tmp13;
    TNode<HeapObject> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<Map> tmp16;
    TNode<BoolT> tmp17;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp12 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference { tmp3, tmp11 });
        tmp13 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray> { tmp12 }, TNode<IntPtrT> { parameter1 });
        tmp14 = TORQUE_CAST(TNode<Object> { tmp13 });
        tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp16 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { tmp14, tmp15 });
        tmp17 = CodeStubAssembler(state_).IsTuple2Map(TNode<Map> { tmp16 });
        ca_.Branch(tmp17, &block49, std::vector<compiler::Node*> {}, &block50, std::vector<compiler::Node*> {});
    }

    TNode<NativeContext> tmp18;
    TNode<Smi> tmp19;
    TNode<Smi> tmp20;
    if (block49.is_used()) {
        ca_.Bind(&block49);
        tmp18 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp19 = CodeStubAssembler(state_).SmiFromIntPtr(TNode<IntPtrT> { parameter0 });
        tmp20 = CodeStubAssembler(state_).SmiFromIntPtr(TNode<IntPtrT> { parameter1 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmFunctionTableGet, tmp18, tmp0, tmp19, tmp20);
    }

    TNode<WasmNull> tmp21;
    if (block50.is_used()) {
        ca_.Bind(&block50);
        compiler::CodeAssemblerLabel label22(&ca_);
        tmp21 = Cast_WasmNull_0(state_, TNode<HeapObject> { tmp14 }, &label22);
        ca_.Goto(&block56);
        if (label22.is_used()) {
            ca_.Bind(&label22);
            ca_.Goto(&block57);
        }
    }

    TNode<BoolT> tmp23;
    if (block57.is_used()) {
        ca_.Bind(&block57);
        tmp23 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block53, tmp23);
    }

    TNode<BoolT> tmp24;
    if (block56.is_used()) {
        ca_.Bind(&block56);
        tmp24 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block53, tmp24);
    }

    TNode<BoolT> phi_bb53_10;
    if (block53.is_used()) {
        ca_.Bind(&block53, &phi_bb53_10);
        ca_.Branch(phi_bb53_10, &block51, std::vector<compiler::Node*> {}, &block52, std::vector<compiler::Node*> {});
    }

    if (block51.is_used()) {
        ca_.Bind(&block51);
        CodeStubAssembler(state_).Return(tmp14);
    }

    if (block52.is_used()) {
        ca_.Bind(&block52);
        CodeStubAssembler(state_).Return(tmp14);
    }
}

TF_BUILTIN(WasmFunctionTableGet, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kTableIndex);
    USE(parameter0);
    TNode<IntPtrT> parameter1 = UncheckedParameter<IntPtrT>(Descriptor::kIndex);
    USE(parameter1);
    TNode<BoolT> parameter2 = UncheckedParameter<BoolT>(Descriptor::kExtractSharedData);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Smi> tmp2;
    TNode<Smi> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadMaybeSharedInstanceDataFromFrame_0(state_, TNode<BoolT> { parameter2 });
        tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp2 = CodeStubAssembler(state_).SmiFromIntPtr(TNode<IntPtrT> { parameter0 });
        tmp3 = CodeStubAssembler(state_).SmiFromIntPtr(TNode<IntPtrT> { parameter1 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmFunctionTableGet, tmp1, tmp0, tmp2, tmp3);
    }
}

TF_BUILTIN(WasmTableSetFuncRef, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kTableIndex);
    USE(parameter0);
    TNode<BoolT> parameter1 = UncheckedParameter<BoolT>(Descriptor::kExtractSharedData);
    USE(parameter1);
    TNode<IntPtrT> parameter2 = UncheckedParameter<IntPtrT>(Descriptor::kIndex);
    USE(parameter2);
    TNode<WasmFuncRef> parameter3 = UncheckedParameter<WasmFuncRef>(Descriptor::kValue);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<FixedArray> tmp1;
    TNode<Object> tmp2;
    TNode<WasmTableObject> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Smi> tmp5;
    TNode<Int32T> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<UintPtrT> tmp8;
    TNode<UintPtrT> tmp9;
    TNode<BoolT> tmp10;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadMaybeSharedInstanceDataFromFrame_0(state_, TNode<BoolT> { parameter1 });
        tmp1 = WasmBuiltinsAssembler(state_).LoadTablesFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp2 = CodeStubAssembler(state_).LoadFixedArrayElement(TNode<FixedArray> { tmp1 }, TNode<IntPtrT> { parameter0 });
        tmp3 = TORQUE_CAST(TNode<Object> { tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp3, tmp4 });
        tmp6 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { tmp5 });
        tmp7 = CodeStubAssembler(state_).ChangeInt32ToIntPtr(TNode<Int32T> { tmp6 });
        tmp8 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { tmp7 });
        tmp9 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT> { parameter2 });
        tmp10 = CodeStubAssembler(state_).UintPtrGreaterThanOrEqual(TNode<UintPtrT> { tmp9 }, TNode<UintPtrT> { tmp8 });
        ca_.Branch(tmp10, &block24, std::vector<compiler::Node*> {}, &block25, std::vector<compiler::Node*> {});
    }

    if (block24.is_used()) {
        ca_.Bind(&block24);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapTableOutOfBounds, TNode<Object>());
    }

    TNode<NativeContext> tmp11;
    TNode<Smi> tmp12;
    TNode<Smi> tmp13;
    if (block25.is_used()) {
        ca_.Bind(&block25);
        tmp11 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp12 = CodeStubAssembler(state_).SmiFromIntPtr(TNode<IntPtrT> { parameter0 });
        tmp13 = CodeStubAssembler(state_).SmiFromIntPtr(TNode<IntPtrT> { parameter2 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmFunctionTableSet, tmp11, tmp0, tmp12, tmp13, parameter3);
    }
}

TF_BUILTIN(WasmRefFunc, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kIndex);
    USE(parameter0);
    TNode<BoolT> parameter1 = UncheckedParameter<BoolT>(Descriptor::kExtractSharedData);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<FixedArray> tmp1;
    TNode<Object> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<UintPtrT> tmp7;
    TNode<BoolT> tmp8;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadMaybeSharedInstanceDataFromFrame_0(state_, TNode<BoolT> { parameter1 });
        tmp1 = WasmBuiltinsAssembler(state_).LoadFuncRefsFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        std::tie(tmp2, tmp3, tmp4) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp1 }).Flatten();
        tmp5 = Convert_intptr_uint32_0(state_, TNode<Uint32T> { parameter0 });
        tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp5 });
        tmp7 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp4 });
        tmp8 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp6 }, TNode<UintPtrT> { tmp7 });
        ca_.Branch(tmp8, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<Object> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<Object> tmp13;
    TNode<BoolT> tmp14;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp9 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp5 });
        tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp3 }, TNode<IntPtrT> { tmp9 });
        std::tie(tmp11, tmp12) = NewReference_Object_0(state_, TNode<Object> { tmp2 }, TNode<IntPtrT> { tmp10 }).Flatten();
        tmp13 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp11, tmp12 });
        tmp14 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object> { tmp13 });
        ca_.Branch(tmp14, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<NativeContext> tmp15;
    TNode<Smi> tmp16;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp15 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp16 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter0 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmRefFunc, tmp15, tmp0, tmp16);
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        CodeStubAssembler(state_).Return(tmp13);
    }
}

TF_BUILTIN(WasmInternalFunctionCreateExternal, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<WasmInternalFunction> parameter1 = UncheckedParameter<WasmInternalFunction>(Descriptor::kFunc);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSFunction> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmInternalFunctionCreateExternal, parameter0, parameter1));
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(WasmAllocateZeroedFixedArray, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kSize);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp1 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT> { parameter0 }, TNode<IntPtrT> { tmp0 });
        ca_.Branch(tmp1, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<FixedArray> tmp2;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp2 = kEmptyFixedArray_0(state_);
        CodeStubAssembler(state_).Return(tmp2);
    }

    TNode<FixedArrayBase> tmp3;
    TNode<FixedArray> tmp4;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp3 = CodeStubAssembler(state_).AllocateFixedArray(
            ElementsKind::PACKED_ELEMENTS, TNode<IntPtrT> { parameter0 }, CodeStubAssembler::AllocationFlag::kNone);
        tmp4 = TORQUE_CAST(TNode<Object> { tmp3 });
        CodeStubAssembler(state_).FillEntireFixedArrayWithSmiZero(ElementsKind::PACKED_ELEMENTS, TNode<FixedArray> { tmp4 }, TNode<IntPtrT> { parameter0 });
        CodeStubAssembler(state_).Return(tmp4);
    }
}

TF_BUILTIN(WasmAllocateFixedArray, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kSize);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp1 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT> { parameter0 }, TNode<IntPtrT> { tmp0 });
        ca_.Branch(tmp1, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<FixedArray> tmp2;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp2 = kEmptyFixedArray_0(state_);
        CodeStubAssembler(state_).Return(tmp2);
    }

    TNode<FixedArrayBase> tmp3;
    TNode<FixedArray> tmp4;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp3 = CodeStubAssembler(state_).AllocateFixedArray(
            ElementsKind::PACKED_ELEMENTS, TNode<IntPtrT> { parameter0 }, CodeStubAssembler::AllocationFlag::kNone);
        tmp4 = TORQUE_CAST(TNode<Object> { tmp3 });
        CodeStubAssembler(state_).Return(tmp4);
    }
}

TF_BUILTIN(WasmLiftoffDeoptFinish, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = kNoContext_0(state_);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmLiftoffDeoptFinish, tmp1, tmp0);
    }
}

TF_BUILTIN(WasmThrow, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Object> parameter0 = UncheckedParameter<Object>(Descriptor::kTag);
    USE(parameter0);
    TNode<FixedArray> parameter1 = UncheckedParameter<FixedArray>(Descriptor::kValues);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmThrow, tmp0, parameter0, parameter1);
    }
}

TF_BUILTIN(WasmRethrow, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Object> parameter0 = UncheckedParameter<Object>(Descriptor::kException);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmReThrow, tmp0, parameter0);
    }
}

TF_BUILTIN(WasmThrowRef, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Object> parameter0 = UncheckedParameter<Object>(Descriptor::kException);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmNull> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kWasmNull_0(state_);
        tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { parameter0 }, TNode<HeapObject> { tmp0 });
        ca_.Branch(tmp1, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapRethrowNull, TNode<Object>());
    }

    TNode<NativeContext> tmp2;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp2 = LoadContextFromFrame_0(state_);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmReThrow, tmp2, parameter0);
    }
}

TF_BUILTIN(WasmRethrowExplicitContext, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Object> parameter0 = UncheckedParameter<Object>(Descriptor::kException);
    USE(parameter0);
    TNode<Context> parameter1 = UncheckedParameter<Context>(Descriptor::kExplicitContext);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Null> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Null_0(state_);
        tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { parameter0 }, TNode<HeapObject> { tmp0 });
        ca_.Branch(tmp1, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapRethrowNull, TNode<Object>());
    }

    if (block2.is_used()) {
        ca_.Bind(&block2);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmReThrow, parameter1, parameter0);
    }
}

TF_BUILTIN(WasmTriggerTierUp, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<NativeContext> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = LoadContextFromFrame_0(state_);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTriggerTierUp, tmp1, tmp0);
    }
}

TF_BUILTIN(WasmGrowableStackGuard, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<IntPtrT> parameter0 = UncheckedParameter<IntPtrT>(Descriptor::kParamSlotsSize);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<RawPtrT> tmp3;
    TNode<Uint32T> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).LoadParentFramePointer();
        tmp1 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT> { tmp0 }, TNode<IntPtrT> { parameter0 });
        tmp2 = FromConstexpr_intptr_constexpr_int32_0(state_, CommonFrameConstants::kFixedFrameSizeAboveFp);
        tmp3 = CodeStubAssembler(state_).RawPtrAdd(TNode<RawPtrT> { tmp1 }, TNode<IntPtrT> { tmp2 });
        tmp4 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmHandleStackOverflow, TNode<Object>(), tmp3, tmp4);
    }
}

TF_BUILTIN(WasmStackGuard, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        tmp1 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStackGuard, tmp0, tmp1);
    }
}

TF_BUILTIN(WasmStackOverflow, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kThrowWasmStackOverflow, tmp0);
    }
}

TF_BUILTIN(WasmTraceMemory, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Smi> parameter0 = UncheckedParameter<Smi>(Descriptor::kInfo);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTraceMemory, tmp0, parameter0);
    }
}

TF_BUILTIN(WasmTraceEnter, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTraceEnter, tmp0);
    }
}

TF_BUILTIN(WasmTraceExit, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Smi> parameter0 = UncheckedParameter<Smi>(Descriptor::kInfo);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmTraceExit, tmp0, parameter0);
    }
}

TF_BUILTIN(WasmAllocateJSArray, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Smi> parameter1 = UncheckedParameter<Smi>(Descriptor::kSize);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Map> tmp0;
    TNode<JSArray> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = GetFastPackedElementsJSArrayMap_0(state_, TNode<Context> { parameter0 });
        tmp1 = CodeStubAssembler(state_).AllocateJSArray(
            ElementsKind::PACKED_ELEMENTS, TNode<Map> { tmp0 }, TNode<Smi> { parameter1 }, TNode<Smi> { parameter1 });
        CodeStubAssembler(state_).Return(tmp1);
    }
}

TF_BUILTIN(WasmAllocateStructWithRtt, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Map> parameter0 = UncheckedParameter<Map>(Descriptor::kRtt);
    USE(parameter0);
    TNode<Int32T> parameter1 = UncheckedParameter<Int32T>(Descriptor::kInstanceSize);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<HeapObject> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Object> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<WasmStruct> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<FixedArray> tmp7;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_intptr_int32_0(state_, TNode<Int32T> { parameter1 });
        tmp1 = CodeStubAssembler(state_).Allocate(TNode<IntPtrT> { tmp0 });
        tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        std::tie(tmp3, tmp4)
            = UnsafeConstCast_Map_0(state_, TorqueStructReference_Map_0 { TNode<Object> { tmp1 }, TNode<IntPtrT> { tmp2 }, TorqueStructUnsafe_0 {} }).Flatten();
        CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference { tmp3, tmp4 }, parameter0);
        tmp5 = TORQUE_CAST(TNode<HeapObject> { tmp1 });
        tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp7 = kEmptyFixedArray_0(state_);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp5, tmp6 }, tmp7);
        CodeStubAssembler(state_).Return(tmp1);
    }
}

TF_BUILTIN(WasmAllocateArray_Uninitialized, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Map> parameter0 = UncheckedParameter<Map>(Descriptor::kRtt);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kLength);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kElementSize);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<HeapObject> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<Object> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<WasmArray> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<FixedArray> tmp12;
    TNode<WasmArray> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<WasmArray> tmp15;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_intptr_uint32_0(state_, TNode<Uint32T> { parameter1 });
        tmp1 = Convert_intptr_uint32_0(state_, TNode<Uint32T> { parameter2 });
        tmp2 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT> { tmp0 }, TNode<IntPtrT> { tmp1 });
        tmp3 = AlignTagged_0(state_, TNode<IntPtrT> { tmp2 });
        tmp4 = Convert_intptr_constexpr_int32_0(state_, WasmArray::kHeaderSize);
        tmp5 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp3 }, TNode<IntPtrT> { tmp4 });
        tmp6 = CodeStubAssembler(state_).Allocate(TNode<IntPtrT> { tmp5 });
        tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        std::tie(tmp8, tmp9)
            = UnsafeConstCast_Map_0(state_, TorqueStructReference_Map_0 { TNode<Object> { tmp6 }, TNode<IntPtrT> { tmp7 }, TorqueStructUnsafe_0 {} }).Flatten();
        CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference { tmp8, tmp9 }, parameter0);
        tmp10 = TORQUE_CAST(TNode<HeapObject> { tmp6 });
        tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp12 = kEmptyFixedArray_0(state_);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp10, tmp11 }, tmp12);
        tmp13 = TORQUE_CAST(TNode<HeapObject> { tmp6 });
        tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference { tmp13, tmp14 }, parameter1);
        tmp15 = TORQUE_CAST(TNode<HeapObject> { tmp6 });
        CodeStubAssembler(state_).Return(tmp15);
    }
}

TF_BUILTIN(WasmArrayNewSegment, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kSegmentIndex);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kOffset);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kLength);
    USE(parameter2);
    TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kIsElement);
    USE(parameter3);
    TNode<Smi> parameter4 = UncheckedParameter<Smi>(Descriptor::kExtractSharedData);
    USE(parameter4);
    TNode<Map> parameter5 = UncheckedParameter<Map>(Descriptor::kRtt);
    USE(parameter5);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadMaybeSharedInstanceDataFromFrame_1(state_, TNode<Smi> { parameter4 });
        compiler::CodeAssemblerLabel label2(&ca_);
        tmp1 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T> { parameter1 }, &label2);
        ca_.Goto(&block5);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block6);
        }
    }

    TNode<Smi> tmp3;
    TNode<BoolT> tmp4;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp3 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
        tmp4 = CodeStubAssembler(state_).SmiEqual(TNode<Smi> { parameter3 }, TNode<Smi> { tmp3 });
        ca_.Branch(tmp4, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    TNode<Smi> tmp5;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        compiler::CodeAssemblerLabel label6(&ca_);
        tmp5 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T> { parameter2 }, &label6);
        ca_.Goto(&block7);
        if (label6.is_used()) {
            ca_.Bind(&label6);
            ca_.Goto(&block8);
        }
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapArrayTooLarge, TNode<Object>());
    }

    TNode<NativeContext> tmp7;
    TNode<Smi> tmp8;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp7 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp8 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter0 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmArrayNewSegment, tmp7, tmp0, tmp8, tmp1, tmp5, parameter5);
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapDataSegmentOutOfBounds, TNode<Object>());
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapElementSegmentOutOfBounds, TNode<Object>());
    }
}

TF_BUILTIN(WasmArrayInitSegment, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kArrayIndex);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kSegmentOffset);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kLength);
    USE(parameter2);
    TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kSegmentIndex);
    USE(parameter3);
    TNode<Smi> parameter4 = UncheckedParameter<Smi>(Descriptor::kIsElement);
    USE(parameter4);
    TNode<Smi> parameter5 = UncheckedParameter<Smi>(Descriptor::kExtractSharedData);
    USE(parameter5);
    TNode<HeapObject> parameter6 = UncheckedParameter<HeapObject>(Descriptor::kArrayRaw);
    USE(parameter6);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<WasmNull> tmp1;
    TNode<BoolT> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadMaybeSharedInstanceDataFromFrame_1(state_, TNode<Smi> { parameter5 });
        tmp1 = kWasmNull_0(state_);
        tmp2 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { parameter6 }, TNode<HeapObject> { tmp1 });
        ca_.Branch(tmp2, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapNullDereference, TNode<Object>());
    }

    TNode<WasmArray> tmp3;
    TNode<Smi> tmp4;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp3 = TORQUE_CAST(TNode<HeapObject> { parameter6 });
        compiler::CodeAssemblerLabel label5(&ca_);
        tmp4 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T> { parameter0 }, &label5);
        ca_.Goto(&block7);
        if (label5.is_used()) {
            ca_.Bind(&label5);
            ca_.Goto(&block8);
        }
    }

    if (block8.is_used()) {
        ca_.Bind(&block8);
        ca_.Goto(&block4);
    }

    TNode<Smi> tmp6;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        compiler::CodeAssemblerLabel label7(&ca_);
        tmp6 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T> { parameter1 }, &label7);
        ca_.Goto(&block9);
        if (label7.is_used()) {
            ca_.Bind(&label7);
            ca_.Goto(&block10);
        }
    }

    TNode<Smi> tmp8;
    TNode<BoolT> tmp9;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp8 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
        tmp9 = CodeStubAssembler(state_).SmiEqual(TNode<Smi> { parameter4 }, TNode<Smi> { tmp8 });
        ca_.Branch(tmp9, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    TNode<Smi> tmp10;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        compiler::CodeAssemblerLabel label11(&ca_);
        tmp10 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T> { parameter2 }, &label11);
        ca_.Goto(&block11);
        if (label11.is_used()) {
            ca_.Bind(&label11);
            ca_.Goto(&block12);
        }
    }

    if (block12.is_used()) {
        ca_.Bind(&block12);
        ca_.Goto(&block4);
    }

    TNode<NativeContext> tmp12;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp12 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmArrayInitSegment, tmp12, tmp0, parameter3, tmp3, tmp4, tmp6, tmp10);
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapDataSegmentOutOfBounds, TNode<Object>());
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapElementSegmentOutOfBounds, TNode<Object>());
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapArrayOutOfBounds, TNode<Object>());
    }
}

TF_BUILTIN(WasmArrayCopy, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kDstIndex);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kSrcIndex);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kLength);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kDstObject);
    USE(parameter3);
    TNode<Object> parameter4 = UncheckedParameter<Object>(Descriptor::kSrcObject);
    USE(parameter4);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmNull> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kWasmNull_0(state_);
        tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { parameter3 }, TNode<HeapObject> { tmp0 });
        ca_.Branch(tmp1, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapNullDereference, TNode<Object>());
    }

    TNode<WasmArray> tmp2;
    TNode<Uint32T> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Uint32T> tmp5;
    TNode<BoolT> tmp6;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp2 = TORQUE_CAST(TNode<Object> { parameter3 });
        tmp3 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { parameter0 }, TNode<Uint32T> { parameter2 });
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { tmp2, tmp4 });
        tmp6 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp3 }, TNode<Uint32T> { tmp5 });
        ca_.Branch(tmp6, &block18, std::vector<compiler::Node*> {}, &block19, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp7;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block20, tmp7);
    }

    TNode<Uint32T> tmp8;
    TNode<BoolT> tmp9;
    if (block19.is_used()) {
        ca_.Bind(&block19);
        tmp8 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { parameter0 }, TNode<Uint32T> { parameter2 });
        tmp9 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { tmp8 }, TNode<Uint32T> { parameter0 });
        ca_.Goto(&block20, tmp9);
    }

    TNode<BoolT> phi_bb20_7;
    if (block20.is_used()) {
        ca_.Bind(&block20, &phi_bb20_7);
        ca_.Branch(phi_bb20_7, &block16, std::vector<compiler::Node*> {}, &block17, std::vector<compiler::Node*> {});
    }

    if (block16.is_used()) {
        ca_.Bind(&block16);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapArrayOutOfBounds, TNode<Object>());
    }

    TNode<WasmNull> tmp10;
    TNode<BoolT> tmp11;
    if (block17.is_used()) {
        ca_.Bind(&block17);
        tmp10 = kWasmNull_0(state_);
        tmp11 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { parameter4 }, TNode<HeapObject> { tmp10 });
        ca_.Branch(tmp11, &block21, std::vector<compiler::Node*> {}, &block22, std::vector<compiler::Node*> {});
    }

    if (block21.is_used()) {
        ca_.Bind(&block21);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapNullDereference, TNode<Object>());
    }

    TNode<WasmArray> tmp12;
    TNode<Uint32T> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<Uint32T> tmp15;
    TNode<BoolT> tmp16;
    if (block22.is_used()) {
        ca_.Bind(&block22);
        tmp12 = TORQUE_CAST(TNode<Object> { parameter4 });
        tmp13 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { parameter1 }, TNode<Uint32T> { parameter2 });
        tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp15 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { tmp12, tmp14 });
        tmp16 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp13 }, TNode<Uint32T> { tmp15 });
        ca_.Branch(tmp16, &block38, std::vector<compiler::Node*> {}, &block39, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp17;
    if (block38.is_used()) {
        ca_.Bind(&block38);
        tmp17 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block40, tmp17);
    }

    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block39.is_used()) {
        ca_.Bind(&block39);
        tmp18 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { parameter1 }, TNode<Uint32T> { parameter2 });
        tmp19 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { tmp18 }, TNode<Uint32T> { parameter1 });
        ca_.Goto(&block40, tmp19);
    }

    TNode<BoolT> phi_bb40_8;
    if (block40.is_used()) {
        ca_.Bind(&block40, &phi_bb40_8);
        ca_.Branch(phi_bb40_8, &block36, std::vector<compiler::Node*> {}, &block37, std::vector<compiler::Node*> {});
    }

    if (block36.is_used()) {
        ca_.Bind(&block36);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapArrayOutOfBounds, TNode<Object>());
    }

    TNode<Uint32T> tmp20;
    TNode<BoolT> tmp21;
    if (block37.is_used()) {
        ca_.Bind(&block37);
        tmp20 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp21 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { parameter2 }, TNode<Uint32T> { tmp20 });
        ca_.Branch(tmp21, &block41, std::vector<compiler::Node*> {}, &block42, std::vector<compiler::Node*> {});
    }

    TNode<Undefined> tmp22;
    if (block41.is_used()) {
        ca_.Bind(&block41);
        tmp22 = Undefined_0(state_);
        CodeStubAssembler(state_).Return(tmp22);
    }

    TNode<NativeContext> tmp23;
    TNode<Smi> tmp24;
    TNode<Smi> tmp25;
    TNode<Smi> tmp26;
    if (block42.is_used()) {
        ca_.Bind(&block42);
        tmp23 = LoadContextFromFrame_0(state_);
        tmp24 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter0 });
        tmp25 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter1 });
        tmp26 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter2 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmArrayCopy, tmp23, tmp2, tmp24, tmp12, tmp25, tmp26);
    }
}

TF_BUILTIN(WasmUint32ToNumber, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kValue);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).ChangeUint32ToTagged(TNode<Uint32T> { parameter0 });
        CodeStubAssembler(state_).Return(tmp0);
    }
}

TF_BUILTIN(UintPtr53ToNumber, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<UintPtrT> parameter0 = UncheckedParameter<UintPtrT>(Descriptor::kValue);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, kSmiMaxValue);
        tmp1 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT> { parameter0 }, TNode<UintPtrT> { tmp0 });
        ca_.Branch(tmp1, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp2;
    TNode<Smi> tmp3;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp2 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { parameter0 });
        tmp3 = Convert_Smi_intptr_0(state_, TNode<IntPtrT> { tmp2 });
        CodeStubAssembler(state_).Return(tmp3);
    }

    TNode<Float64T> tmp4;
    TNode<HeapNumber> tmp5;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp4 = CodeStubAssembler(state_).ChangeUintPtrToFloat64(TNode<UintPtrT> { parameter0 });
        tmp5 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T> { tmp4 });
        CodeStubAssembler(state_).Return(tmp5);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=616&c=1
TNode<Number> UintPtrToNumberRounding_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_value)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Number> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, kSmiMaxValue);
        tmp1 = CodeStubAssembler(state_).UintPtrLessThanOrEqual(TNode<UintPtrT> { p_value }, TNode<UintPtrT> { tmp0 });
        ca_.Branch(tmp1, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp2;
    TNode<Smi> tmp3;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp2 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { p_value });
        tmp3 = Convert_Smi_intptr_0(state_, TNode<IntPtrT> { tmp2 });
        ca_.Goto(&block1, tmp3);
    }

    TNode<Float64T> tmp4;
    TNode<HeapNumber> tmp5;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp4 = CodeStubAssembler(state_).ChangeUintPtrToFloat64(TNode<UintPtrT> { p_value });
        tmp5 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T> { tmp4 });
        ca_.Goto(&block1, tmp5);
    }

    TNode<Number> phi_bb1_1;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_1);
        ca_.Goto(&block4);
    }

    ca_.Bind(&block4);
    return TNode<Number> { phi_bb1_1 };
}

TF_BUILTIN(WasmI32AtomicWait, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Int32T> parameter0 = UncheckedParameter<Int32T>(Descriptor::kMemIndex);
    USE(parameter0);
    TNode<UintPtrT> parameter1 = UncheckedParameter<UintPtrT>(Descriptor::kOffset);
    USE(parameter1);
    TNode<Int32T> parameter2 = UncheckedParameter<Int32T>(Descriptor::kExpectedValue);
    USE(parameter2);
    TNode<BigInt> parameter3 = UncheckedParameter<BigInt>(Descriptor::kTimeout);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Smi> tmp2;
    TNode<Number> tmp3;
    TNode<Number> tmp4;
    TNode<Smi> tmp5;
    TNode<Int32T> tmp6;
    TNode<Uint32T> tmp7;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp2 = CodeStubAssembler(state_).SmiFromInt32(TNode<Int32T> { parameter0 });
        tmp3 = ca_.CallBuiltin<Number>(Builtin::kUintPtr53ToNumber, TNode<Object>(), parameter1);
        tmp4 = CodeStubAssembler(state_).ChangeInt32ToTagged(TNode<Int32T> { parameter2 });
        tmp5 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmI32AtomicWait, tmp1, tmp0, tmp2, tmp3, tmp4, parameter3));
        tmp6 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { tmp5 });
        tmp7 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp6 });
        CodeStubAssembler(state_).Return(tmp7);
    }
}

TF_BUILTIN(WasmI64AtomicWait, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Int32T> parameter0 = UncheckedParameter<Int32T>(Descriptor::kMemIndex);
    USE(parameter0);
    TNode<UintPtrT> parameter1 = UncheckedParameter<UintPtrT>(Descriptor::kOffset);
    USE(parameter1);
    TNode<BigInt> parameter2 = UncheckedParameter<BigInt>(Descriptor::kExpectedValue);
    USE(parameter2);
    TNode<BigInt> parameter3 = UncheckedParameter<BigInt>(Descriptor::kTimeout);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Smi> tmp2;
    TNode<Number> tmp3;
    TNode<Smi> tmp4;
    TNode<Int32T> tmp5;
    TNode<Uint32T> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp2 = CodeStubAssembler(state_).SmiFromInt32(TNode<Int32T> { parameter0 });
        tmp3 = ca_.CallBuiltin<Number>(Builtin::kUintPtr53ToNumber, TNode<Object>(), parameter1);
        tmp4 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmI64AtomicWait, tmp1, tmp0, tmp2, tmp3, parameter2, parameter3));
        tmp5 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { tmp4 });
        tmp6 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp5 });
        CodeStubAssembler(state_).Return(tmp6);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=652&c=1
void UpdateCallRefOrIndirectIC_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_vector, TNode<IntPtrT> p_index, TNode<Object> p_target)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block79(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block80(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block97(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block98(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block101(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block112(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block113(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block120(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block121(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block102(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block131(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block130(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block133(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block132(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block128(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block126(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block124(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block148(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block155(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block156(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block149(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block174(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block172(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block180(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block181(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block188(
        &ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block189(
        &ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block173(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block196(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block197(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block204(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block205(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block212(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block213(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block150(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block125(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block216(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block217(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block260(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block261(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block269(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block270(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block278(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block279(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block287(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block288(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block295(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block296(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block303(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block304(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block218(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block134(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block103(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block307(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<UintPtrT> tmp4;
    TNode<BoolT> tmp5;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1, tmp2) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_vector }).Flatten();
        tmp3 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { p_index });
        tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp2 });
        tmp5 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp3 }, TNode<UintPtrT> { tmp4 });
        ca_.Branch(tmp5, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<Object> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<UintPtrT> tmp16;
    TNode<UintPtrT> tmp17;
    TNode<BoolT> tmp18;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp6 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { p_index });
        tmp7 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp1 }, TNode<IntPtrT> { tmp6 });
        std::tie(tmp8, tmp9) = NewReference_Object_0(state_, TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp7 }).Flatten();
        tmp10 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp8, tmp9 });
        std::tie(tmp11, tmp12, tmp13) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_vector }).Flatten();
        tmp14 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp15 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_index }, TNode<IntPtrT> { tmp14 });
        tmp16 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp15 });
        tmp17 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp13 });
        tmp18 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp16 }, TNode<UintPtrT> { tmp17 });
        ca_.Branch(tmp18, &block14, std::vector<compiler::Node*> {}, &block15, std::vector<compiler::Node*> {});
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<Object> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<Object> tmp23;
    TNode<BoolT> tmp24;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        tmp19 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp15 });
        tmp20 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp12 }, TNode<IntPtrT> { tmp19 });
        std::tie(tmp21, tmp22) = NewReference_Object_0(state_, TNode<Object> { tmp11 }, TNode<IntPtrT> { tmp20 }).Flatten();
        tmp23 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp21, tmp22 });
        tmp24 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject> { tmp10 }, TNode<MaybeObject> { p_target });
        ca_.Branch(tmp24, &block18, std::vector<compiler::Node*> {}, &block19, std::vector<compiler::Node*> {});
    }

    if (block15.is_used()) {
        ca_.Bind(&block15);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Smi> tmp25;
    TNode<Smi> tmp26;
    TNode<Smi> tmp27;
    TNode<Object> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<UintPtrT> tmp33;
    TNode<UintPtrT> tmp34;
    TNode<BoolT> tmp35;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        tmp25 = TORQUE_CAST(TNode<Object> { tmp23 });
        tmp26 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
        tmp27 = CodeStubAssembler(state_).SmiAdd(TNode<Smi> { tmp25 }, TNode<Smi> { tmp26 });
        std::tie(tmp28, tmp29, tmp30) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_vector }).Flatten();
        tmp31 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp32 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_index }, TNode<IntPtrT> { tmp31 });
        tmp33 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp32 });
        tmp34 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp30 });
        tmp35 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp33 }, TNode<UintPtrT> { tmp34 });
        ca_.Branch(tmp35, &block34, std::vector<compiler::Node*> {}, &block35, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<Object> tmp38;
    TNode<IntPtrT> tmp39;
    if (block34.is_used()) {
        ca_.Bind(&block34);
        tmp36 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp32 });
        tmp37 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp29 }, TNode<IntPtrT> { tmp36 });
        std::tie(tmp38, tmp39) = NewReference_Object_0(state_, TNode<Object> { tmp28 }, TNode<IntPtrT> { tmp37 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp38, tmp39 }, tmp27);
        ca_.Goto(&block1);
    }

    if (block35.is_used()) {
        ca_.Bind(&block35);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<HeapObject> tmp40;
    if (block19.is_used()) {
        ca_.Bind(&block19);
        compiler::CodeAssemblerLabel label41(&ca_);
        tmp40 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object> { tmp10 }, &label41);
        ca_.Goto(&block44);
        if (label41.is_used()) {
            ca_.Bind(&label41);
            ca_.Goto(&block45);
        }
    }

    if (block45.is_used()) {
        ca_.Bind(&block45);
        ca_.Goto(&block42);
    }

    TNode<FixedArray> tmp42;
    if (block44.is_used()) {
        ca_.Bind(&block44);
        compiler::CodeAssemblerLabel label43(&ca_);
        tmp42 = Cast_FixedArray_0(state_, TNode<HeapObject> { tmp40 }, &label43);
        ca_.Goto(&block46);
        if (label43.is_used()) {
            ca_.Bind(&label43);
            ca_.Goto(&block47);
        }
    }

    if (block47.is_used()) {
        ca_.Bind(&block47);
        ca_.Goto(&block42);
    }

    TNode<BoolT> tmp44;
    if (block46.is_used()) {
        ca_.Bind(&block46);
        tmp44 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block40, tmp44);
    }

    TNode<BoolT> tmp45;
    if (block42.is_used()) {
        ca_.Bind(&block42);
        tmp45 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block40, tmp45);
    }

    TNode<BoolT> phi_bb40_7;
    if (block40.is_used()) {
        ca_.Bind(&block40, &phi_bb40_7);
        ca_.Branch(phi_bb40_7, &block38, std::vector<compiler::Node*> {}, &block39, std::vector<compiler::Node*> {});
    }

    TNode<FixedArray> tmp46;
    TNode<IntPtrT> tmp47;
    if (block38.is_used()) {
        ca_.Bind(&block38);
        tmp46 = TORQUE_CAST(TNode<Object> { tmp10 });
        tmp47 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block63, tmp47);
    }

    TNode<IntPtrT> phi_bb63_6;
    TNode<IntPtrT> tmp48;
    TNode<BoolT> tmp49;
    if (block63.is_used()) {
        ca_.Bind(&block63, &phi_bb63_6);
        tmp48 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase> { tmp46 });
        tmp49 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT> { phi_bb63_6 }, TNode<IntPtrT> { tmp48 });
        ca_.Branch(tmp49, &block61, std::vector<compiler::Node*> { phi_bb63_6 }, &block62, std::vector<compiler::Node*> { phi_bb63_6 });
    }

    TNode<IntPtrT> phi_bb61_6;
    TNode<Object> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<UintPtrT> tmp53;
    TNode<UintPtrT> tmp54;
    TNode<BoolT> tmp55;
    if (block61.is_used()) {
        ca_.Bind(&block61, &phi_bb61_6);
        std::tie(tmp50, tmp51, tmp52) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp46 }).Flatten();
        tmp53 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { phi_bb61_6 });
        tmp54 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp52 });
        tmp55 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp53 }, TNode<UintPtrT> { tmp54 });
        ca_.Branch(tmp55, &block71, std::vector<compiler::Node*> { phi_bb61_6, phi_bb61_6, phi_bb61_6, phi_bb61_6, phi_bb61_6 }, &block72,
            std::vector<compiler::Node*> { phi_bb61_6, phi_bb61_6, phi_bb61_6, phi_bb61_6, phi_bb61_6 });
    }

    TNode<IntPtrT> phi_bb71_6;
    TNode<IntPtrT> phi_bb71_11;
    TNode<IntPtrT> phi_bb71_12;
    TNode<IntPtrT> phi_bb71_16;
    TNode<IntPtrT> phi_bb71_17;
    TNode<IntPtrT> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<Object> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<Object> tmp60;
    TNode<BoolT> tmp61;
    if (block71.is_used()) {
        ca_.Bind(&block71, &phi_bb71_6, &phi_bb71_11, &phi_bb71_12, &phi_bb71_16, &phi_bb71_17);
        tmp56 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { phi_bb71_17 });
        tmp57 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp51 }, TNode<IntPtrT> { tmp56 });
        std::tie(tmp58, tmp59) = NewReference_Object_0(state_, TNode<Object> { tmp50 }, TNode<IntPtrT> { tmp57 }).Flatten();
        tmp60 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp58, tmp59 });
        tmp61 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject> { tmp60 }, TNode<MaybeObject> { p_target });
        ca_.Branch(tmp61, &block65, std::vector<compiler::Node*> { phi_bb71_6 }, &block66, std::vector<compiler::Node*> { phi_bb71_6 });
    }

    TNode<IntPtrT> phi_bb72_6;
    TNode<IntPtrT> phi_bb72_11;
    TNode<IntPtrT> phi_bb72_12;
    TNode<IntPtrT> phi_bb72_16;
    TNode<IntPtrT> phi_bb72_17;
    if (block72.is_used()) {
        ca_.Bind(&block72, &phi_bb72_6, &phi_bb72_11, &phi_bb72_12, &phi_bb72_16, &phi_bb72_17);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> phi_bb65_6;
    TNode<Object> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<IntPtrT> tmp64;
    TNode<IntPtrT> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<UintPtrT> tmp67;
    TNode<UintPtrT> tmp68;
    TNode<BoolT> tmp69;
    if (block65.is_used()) {
        ca_.Bind(&block65, &phi_bb65_6);
        std::tie(tmp62, tmp63, tmp64) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp46 }).Flatten();
        tmp65 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp66 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb65_6 }, TNode<IntPtrT> { tmp65 });
        tmp67 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp66 });
        tmp68 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp64 });
        tmp69 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp67 }, TNode<UintPtrT> { tmp68 });
        ca_.Branch(tmp69, &block79, std::vector<compiler::Node*> { phi_bb65_6 }, &block80, std::vector<compiler::Node*> { phi_bb65_6 });
    }

    TNode<IntPtrT> phi_bb79_6;
    TNode<IntPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<Object> tmp72;
    TNode<IntPtrT> tmp73;
    TNode<Object> tmp74;
    TNode<Smi> tmp75;
    TNode<Smi> tmp76;
    TNode<Smi> tmp77;
    TNode<Object> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<IntPtrT> tmp80;
    TNode<IntPtrT> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<UintPtrT> tmp83;
    TNode<UintPtrT> tmp84;
    TNode<BoolT> tmp85;
    if (block79.is_used()) {
        ca_.Bind(&block79, &phi_bb79_6);
        tmp70 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp66 });
        tmp71 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp63 }, TNode<IntPtrT> { tmp70 });
        std::tie(tmp72, tmp73) = NewReference_Object_0(state_, TNode<Object> { tmp62 }, TNode<IntPtrT> { tmp71 }).Flatten();
        tmp74 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp72, tmp73 });
        tmp75 = TORQUE_CAST(TNode<Object> { tmp74 });
        tmp76 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
        tmp77 = CodeStubAssembler(state_).SmiAdd(TNode<Smi> { tmp75 }, TNode<Smi> { tmp76 });
        std::tie(tmp78, tmp79, tmp80) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp46 }).Flatten();
        tmp81 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp82 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb79_6 }, TNode<IntPtrT> { tmp81 });
        tmp83 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp82 });
        tmp84 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp80 });
        tmp85 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp83 }, TNode<UintPtrT> { tmp84 });
        ca_.Branch(tmp85, &block97, std::vector<compiler::Node*> { phi_bb79_6 }, &block98, std::vector<compiler::Node*> { phi_bb79_6 });
    }

    TNode<IntPtrT> phi_bb80_6;
    if (block80.is_used()) {
        ca_.Bind(&block80, &phi_bb80_6);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> phi_bb97_6;
    TNode<IntPtrT> tmp86;
    TNode<IntPtrT> tmp87;
    TNode<Object> tmp88;
    TNode<IntPtrT> tmp89;
    if (block97.is_used()) {
        ca_.Bind(&block97, &phi_bb97_6);
        tmp86 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp82 });
        tmp87 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp79 }, TNode<IntPtrT> { tmp86 });
        std::tie(tmp88, tmp89) = NewReference_Object_0(state_, TNode<Object> { tmp78 }, TNode<IntPtrT> { tmp87 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp88, tmp89 }, tmp77);
        ca_.Goto(&block1);
    }

    TNode<IntPtrT> phi_bb98_6;
    if (block98.is_used()) {
        ca_.Bind(&block98, &phi_bb98_6);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> phi_bb66_6;
    TNode<IntPtrT> tmp90;
    TNode<IntPtrT> tmp91;
    if (block66.is_used()) {
        ca_.Bind(&block66, &phi_bb66_6);
        tmp90 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp91 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb66_6 }, TNode<IntPtrT> { tmp90 });
        ca_.Goto(&block63, tmp91);
    }

    TNode<IntPtrT> phi_bb62_6;
    if (block62.is_used()) {
        ca_.Bind(&block62, &phi_bb62_6);
        ca_.Goto(&block39);
    }

    TNode<Smi> tmp92;
    TNode<BoolT> tmp93;
    if (block39.is_used()) {
        ca_.Bind(&block39);
        tmp92 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
        tmp93 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject> { tmp23 }, TNode<MaybeObject> { tmp92 });
        ca_.Branch(tmp93, &block101, std::vector<compiler::Node*> {}, &block102, std::vector<compiler::Node*> {});
    }

    TNode<Object> tmp94;
    TNode<IntPtrT> tmp95;
    TNode<IntPtrT> tmp96;
    TNode<UintPtrT> tmp97;
    TNode<UintPtrT> tmp98;
    TNode<BoolT> tmp99;
    if (block101.is_used()) {
        ca_.Bind(&block101);
        std::tie(tmp94, tmp95, tmp96) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_vector }).Flatten();
        tmp97 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { p_index });
        tmp98 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp96 });
        tmp99 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp97 }, TNode<UintPtrT> { tmp98 });
        ca_.Branch(tmp99, &block112, std::vector<compiler::Node*> {}, &block113, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp100;
    TNode<IntPtrT> tmp101;
    TNode<Object> tmp102;
    TNode<IntPtrT> tmp103;
    TNode<Object> tmp104;
    TNode<IntPtrT> tmp105;
    TNode<IntPtrT> tmp106;
    TNode<IntPtrT> tmp107;
    TNode<IntPtrT> tmp108;
    TNode<UintPtrT> tmp109;
    TNode<UintPtrT> tmp110;
    TNode<BoolT> tmp111;
    if (block112.is_used()) {
        ca_.Bind(&block112);
        tmp100 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { p_index });
        tmp101 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp95 }, TNode<IntPtrT> { tmp100 });
        std::tie(tmp102, tmp103) = NewReference_Object_0(state_, TNode<Object> { tmp94 }, TNode<IntPtrT> { tmp101 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp102, tmp103 }, p_target);
        std::tie(tmp104, tmp105, tmp106) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_vector }).Flatten();
        tmp107 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp108 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_index }, TNode<IntPtrT> { tmp107 });
        tmp109 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp108 });
        tmp110 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp106 });
        tmp111 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp109 }, TNode<UintPtrT> { tmp110 });
        ca_.Branch(tmp111, &block120, std::vector<compiler::Node*> {}, &block121, std::vector<compiler::Node*> {});
    }

    if (block113.is_used()) {
        ca_.Bind(&block113);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> tmp112;
    TNode<IntPtrT> tmp113;
    TNode<Object> tmp114;
    TNode<IntPtrT> tmp115;
    TNode<Smi> tmp116;
    if (block120.is_used()) {
        ca_.Bind(&block120);
        tmp112 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp108 });
        tmp113 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp105 }, TNode<IntPtrT> { tmp112 });
        std::tie(tmp114, tmp115) = NewReference_Object_0(state_, TNode<Object> { tmp104 }, TNode<IntPtrT> { tmp113 }).Flatten();
        tmp116 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp114, tmp115 }, tmp116);
        ca_.Goto(&block103);
    }

    if (block121.is_used()) {
        ca_.Bind(&block121);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<HeapObject> tmp117;
    if (block102.is_used()) {
        ca_.Bind(&block102);
        compiler::CodeAssemblerLabel label118(&ca_);
        tmp117 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object> { tmp10 }, &label118);
        ca_.Goto(&block130);
        if (label118.is_used()) {
            ca_.Bind(&label118);
            ca_.Goto(&block131);
        }
    }

    if (block131.is_used()) {
        ca_.Bind(&block131);
        ca_.Goto(&block128);
    }

    TNode<FixedArray> tmp119;
    if (block130.is_used()) {
        ca_.Bind(&block130);
        compiler::CodeAssemblerLabel label120(&ca_);
        tmp119 = Cast_FixedArray_0(state_, TNode<HeapObject> { tmp117 }, &label120);
        ca_.Goto(&block132);
        if (label120.is_used()) {
            ca_.Bind(&label120);
            ca_.Goto(&block133);
        }
    }

    if (block133.is_used()) {
        ca_.Bind(&block133);
        ca_.Goto(&block128);
    }

    TNode<BoolT> tmp121;
    if (block132.is_used()) {
        ca_.Bind(&block132);
        tmp121 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block126, tmp121);
    }

    TNode<BoolT> tmp122;
    if (block128.is_used()) {
        ca_.Bind(&block128);
        tmp122 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block126, tmp122);
    }

    TNode<BoolT> phi_bb126_7;
    if (block126.is_used()) {
        ca_.Bind(&block126, &phi_bb126_7);
        ca_.Branch(phi_bb126_7, &block124, std::vector<compiler::Node*> {}, &block125, std::vector<compiler::Node*> {});
    }

    TNode<FixedArray> tmp123;
    TNode<IntPtrT> tmp124;
    TNode<Smi> tmp125;
    TNode<Smi> tmp126;
    TNode<BoolT> tmp127;
    if (block124.is_used()) {
        ca_.Bind(&block124);
        tmp123 = TORQUE_CAST(TNode<Object> { tmp10 });
        tmp124 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp125 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp123, tmp124 });
        tmp126 = CodeStubAssembler(state_).SmiConstant((CodeStubAssembler(state_).ConstexprInt31Mul(
            wasm::kMaxPolymorphism, (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull))))));
        tmp127 = CodeStubAssembler(state_).SmiEqual(TNode<Smi> { tmp125 }, TNode<Smi> { tmp126 });
        ca_.Branch(tmp127, &block148, std::vector<compiler::Node*> {}, &block149, std::vector<compiler::Node*> {});
    }

    TNode<Object> tmp128;
    TNode<IntPtrT> tmp129;
    TNode<IntPtrT> tmp130;
    TNode<UintPtrT> tmp131;
    TNode<UintPtrT> tmp132;
    TNode<BoolT> tmp133;
    if (block148.is_used()) {
        ca_.Bind(&block148);
        std::tie(tmp128, tmp129, tmp130) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_vector }).Flatten();
        tmp131 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { p_index });
        tmp132 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp130 });
        tmp133 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp131 }, TNode<UintPtrT> { tmp132 });
        ca_.Branch(tmp133, &block155, std::vector<compiler::Node*> {}, &block156, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp134;
    TNode<IntPtrT> tmp135;
    TNode<Object> tmp136;
    TNode<IntPtrT> tmp137;
    TNode<Symbol> tmp138;
    if (block155.is_used()) {
        ca_.Bind(&block155);
        tmp134 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { p_index });
        tmp135 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp129 }, TNode<IntPtrT> { tmp134 });
        std::tie(tmp136, tmp137) = NewReference_Object_0(state_, TNode<Object> { tmp128 }, TNode<IntPtrT> { tmp135 }).Flatten();
        tmp138 = kMegamorphicSymbol_0(state_);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp136, tmp137 }, tmp138);
        ca_.Goto(&block150);
    }

    if (block156.is_used()) {
        ca_.Bind(&block156);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> tmp139;
    TNode<IntPtrT> tmp140;
    TNode<IntPtrT> tmp141;
    TNode<FixedArrayBase> tmp142;
    TNode<FixedArray> tmp143;
    TNode<IntPtrT> tmp144;
    if (block149.is_used()) {
        ca_.Bind(&block149);
        tmp139 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase> { tmp123 });
        tmp140 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp141 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp139 }, TNode<IntPtrT> { tmp140 });
        tmp142
            = CodeStubAssembler(state_).AllocateFixedArray(ElementsKind::PACKED_ELEMENTS, TNode<IntPtrT> { tmp141 }, CodeStubAssembler::AllocationFlag::kNone);
        tmp143 = TORQUE_CAST(TNode<Object> { tmp142 });
        tmp144 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block174, tmp144);
    }

    TNode<IntPtrT> phi_bb174_7;
    TNode<IntPtrT> tmp145;
    TNode<BoolT> tmp146;
    if (block174.is_used()) {
        ca_.Bind(&block174, &phi_bb174_7);
        tmp145 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase> { tmp123 });
        tmp146 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT> { phi_bb174_7 }, TNode<IntPtrT> { tmp145 });
        ca_.Branch(tmp146, &block172, std::vector<compiler::Node*> { phi_bb174_7 }, &block173, std::vector<compiler::Node*> { phi_bb174_7 });
    }

    TNode<IntPtrT> phi_bb172_7;
    TNode<Object> tmp147;
    TNode<IntPtrT> tmp148;
    TNode<IntPtrT> tmp149;
    TNode<UintPtrT> tmp150;
    TNode<UintPtrT> tmp151;
    TNode<BoolT> tmp152;
    if (block172.is_used()) {
        ca_.Bind(&block172, &phi_bb172_7);
        std::tie(tmp147, tmp148, tmp149) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp143 }).Flatten();
        tmp150 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { phi_bb172_7 });
        tmp151 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp149 });
        tmp152 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp150 }, TNode<UintPtrT> { tmp151 });
        ca_.Branch(tmp152, &block180, std::vector<compiler::Node*> { phi_bb172_7, phi_bb172_7, phi_bb172_7, phi_bb172_7, phi_bb172_7 }, &block181,
            std::vector<compiler::Node*> { phi_bb172_7, phi_bb172_7, phi_bb172_7, phi_bb172_7, phi_bb172_7 });
    }

    TNode<IntPtrT> phi_bb180_7;
    TNode<IntPtrT> phi_bb180_12;
    TNode<IntPtrT> phi_bb180_13;
    TNode<IntPtrT> phi_bb180_17;
    TNode<IntPtrT> phi_bb180_18;
    TNode<IntPtrT> tmp153;
    TNode<IntPtrT> tmp154;
    TNode<Object> tmp155;
    TNode<IntPtrT> tmp156;
    TNode<Object> tmp157;
    TNode<IntPtrT> tmp158;
    TNode<IntPtrT> tmp159;
    TNode<UintPtrT> tmp160;
    TNode<UintPtrT> tmp161;
    TNode<BoolT> tmp162;
    if (block180.is_used()) {
        ca_.Bind(&block180, &phi_bb180_7, &phi_bb180_12, &phi_bb180_13, &phi_bb180_17, &phi_bb180_18);
        tmp153 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { phi_bb180_18 });
        tmp154 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp148 }, TNode<IntPtrT> { tmp153 });
        std::tie(tmp155, tmp156) = NewReference_Object_0(state_, TNode<Object> { tmp147 }, TNode<IntPtrT> { tmp154 }).Flatten();
        std::tie(tmp157, tmp158, tmp159) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp123 }).Flatten();
        tmp160 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { phi_bb180_7 });
        tmp161 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp159 });
        tmp162 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp160 }, TNode<UintPtrT> { tmp161 });
        ca_.Branch(tmp162, &block188,
            std::vector<compiler::Node*> { phi_bb180_7, phi_bb180_12, phi_bb180_13, phi_bb180_7, phi_bb180_7, phi_bb180_7, phi_bb180_7 }, &block189,
            std::vector<compiler::Node*> { phi_bb180_7, phi_bb180_12, phi_bb180_13, phi_bb180_7, phi_bb180_7, phi_bb180_7, phi_bb180_7 });
    }

    TNode<IntPtrT> phi_bb181_7;
    TNode<IntPtrT> phi_bb181_12;
    TNode<IntPtrT> phi_bb181_13;
    TNode<IntPtrT> phi_bb181_17;
    TNode<IntPtrT> phi_bb181_18;
    if (block181.is_used()) {
        ca_.Bind(&block181, &phi_bb181_7, &phi_bb181_12, &phi_bb181_13, &phi_bb181_17, &phi_bb181_18);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> phi_bb188_7;
    TNode<IntPtrT> phi_bb188_12;
    TNode<IntPtrT> phi_bb188_13;
    TNode<IntPtrT> phi_bb188_20;
    TNode<IntPtrT> phi_bb188_21;
    TNode<IntPtrT> phi_bb188_25;
    TNode<IntPtrT> phi_bb188_26;
    TNode<IntPtrT> tmp163;
    TNode<IntPtrT> tmp164;
    TNode<Object> tmp165;
    TNode<IntPtrT> tmp166;
    TNode<Object> tmp167;
    TNode<IntPtrT> tmp168;
    TNode<IntPtrT> tmp169;
    if (block188.is_used()) {
        ca_.Bind(&block188, &phi_bb188_7, &phi_bb188_12, &phi_bb188_13, &phi_bb188_20, &phi_bb188_21, &phi_bb188_25, &phi_bb188_26);
        tmp163 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { phi_bb188_26 });
        tmp164 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp158 }, TNode<IntPtrT> { tmp163 });
        std::tie(tmp165, tmp166) = NewReference_Object_0(state_, TNode<Object> { tmp157 }, TNode<IntPtrT> { tmp164 }).Flatten();
        tmp167 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference { tmp165, tmp166 });
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp155, tmp156 }, tmp167);
        tmp168 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
        tmp169 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb188_7 }, TNode<IntPtrT> { tmp168 });
        ca_.Goto(&block174, tmp169);
    }

    TNode<IntPtrT> phi_bb189_7;
    TNode<IntPtrT> phi_bb189_12;
    TNode<IntPtrT> phi_bb189_13;
    TNode<IntPtrT> phi_bb189_20;
    TNode<IntPtrT> phi_bb189_21;
    TNode<IntPtrT> phi_bb189_25;
    TNode<IntPtrT> phi_bb189_26;
    if (block189.is_used()) {
        ca_.Bind(&block189, &phi_bb189_7, &phi_bb189_12, &phi_bb189_13, &phi_bb189_20, &phi_bb189_21, &phi_bb189_25, &phi_bb189_26);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> phi_bb173_7;
    TNode<IntPtrT> tmp170;
    TNode<Object> tmp171;
    TNode<IntPtrT> tmp172;
    TNode<IntPtrT> tmp173;
    TNode<UintPtrT> tmp174;
    TNode<UintPtrT> tmp175;
    TNode<BoolT> tmp176;
    if (block173.is_used()) {
        ca_.Bind(&block173, &phi_bb173_7);
        tmp170 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase> { tmp123 });
        std::tie(tmp171, tmp172, tmp173) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp143 }).Flatten();
        tmp174 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp170 });
        tmp175 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp173 });
        tmp176 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp174 }, TNode<UintPtrT> { tmp175 });
        ca_.Branch(tmp176, &block196, std::vector<compiler::Node*> {}, &block197, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp177;
    TNode<IntPtrT> tmp178;
    TNode<Object> tmp179;
    TNode<IntPtrT> tmp180;
    TNode<Object> tmp181;
    TNode<IntPtrT> tmp182;
    TNode<IntPtrT> tmp183;
    TNode<IntPtrT> tmp184;
    TNode<IntPtrT> tmp185;
    TNode<UintPtrT> tmp186;
    TNode<UintPtrT> tmp187;
    TNode<BoolT> tmp188;
    if (block196.is_used()) {
        ca_.Bind(&block196);
        tmp177 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp170 });
        tmp178 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp172 }, TNode<IntPtrT> { tmp177 });
        std::tie(tmp179, tmp180) = NewReference_Object_0(state_, TNode<Object> { tmp171 }, TNode<IntPtrT> { tmp178 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp179, tmp180 }, p_target);
        std::tie(tmp181, tmp182, tmp183) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp143 }).Flatten();
        tmp184 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp185 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp170 }, TNode<IntPtrT> { tmp184 });
        tmp186 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp185 });
        tmp187 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp183 });
        tmp188 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp186 }, TNode<UintPtrT> { tmp187 });
        ca_.Branch(tmp188, &block204, std::vector<compiler::Node*> {}, &block205, std::vector<compiler::Node*> {});
    }

    if (block197.is_used()) {
        ca_.Bind(&block197);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> tmp189;
    TNode<IntPtrT> tmp190;
    TNode<Object> tmp191;
    TNode<IntPtrT> tmp192;
    TNode<Smi> tmp193;
    TNode<Object> tmp194;
    TNode<IntPtrT> tmp195;
    TNode<IntPtrT> tmp196;
    TNode<UintPtrT> tmp197;
    TNode<UintPtrT> tmp198;
    TNode<BoolT> tmp199;
    if (block204.is_used()) {
        ca_.Bind(&block204);
        tmp189 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp185 });
        tmp190 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp182 }, TNode<IntPtrT> { tmp189 });
        std::tie(tmp191, tmp192) = NewReference_Object_0(state_, TNode<Object> { tmp181 }, TNode<IntPtrT> { tmp190 }).Flatten();
        tmp193 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp191, tmp192 }, tmp193);
        std::tie(tmp194, tmp195, tmp196) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_vector }).Flatten();
        tmp197 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { p_index });
        tmp198 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp196 });
        tmp199 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp197 }, TNode<UintPtrT> { tmp198 });
        ca_.Branch(tmp199, &block212, std::vector<compiler::Node*> {}, &block213, std::vector<compiler::Node*> {});
    }

    if (block205.is_used()) {
        ca_.Bind(&block205);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> tmp200;
    TNode<IntPtrT> tmp201;
    TNode<Object> tmp202;
    TNode<IntPtrT> tmp203;
    if (block212.is_used()) {
        ca_.Bind(&block212);
        tmp200 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { p_index });
        tmp201 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp195 }, TNode<IntPtrT> { tmp200 });
        std::tie(tmp202, tmp203) = NewReference_Object_0(state_, TNode<Object> { tmp194 }, TNode<IntPtrT> { tmp201 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp202, tmp203 }, tmp143);
        ca_.Goto(&block150);
    }

    if (block213.is_used()) {
        ca_.Bind(&block213);
        CodeStubAssembler(state_).Unreachable();
    }

    if (block150.is_used()) {
        ca_.Bind(&block150);
        ca_.Goto(&block134);
    }

    TNode<Symbol> tmp204;
    TNode<BoolT> tmp205;
    if (block125.is_used()) {
        ca_.Bind(&block125);
        tmp204 = kMegamorphicSymbol_0(state_);
        tmp205 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { tmp10 }, TNode<HeapObject> { tmp204 });
        ca_.Branch(tmp205, &block216, std::vector<compiler::Node*> {}, &block217, std::vector<compiler::Node*> {});
    }

    if (block216.is_used()) {
        ca_.Bind(&block216);
        ca_.Goto(&block218);
    }

    TNode<IntPtrT> tmp206;
    TNode<FixedArrayBase> tmp207;
    TNode<FixedArray> tmp208;
    TNode<Object> tmp209;
    TNode<IntPtrT> tmp210;
    TNode<IntPtrT> tmp211;
    TNode<UintPtrT> tmp212;
    TNode<IntPtrT> tmp213;
    TNode<UintPtrT> tmp214;
    TNode<UintPtrT> tmp215;
    TNode<BoolT> tmp216;
    if (block217.is_used()) {
        ca_.Bind(&block217);
        tmp206 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x4ull));
        tmp207
            = CodeStubAssembler(state_).AllocateFixedArray(ElementsKind::PACKED_ELEMENTS, TNode<IntPtrT> { tmp206 }, CodeStubAssembler::AllocationFlag::kNone);
        tmp208 = TORQUE_CAST(TNode<Object> { tmp207 });
        std::tie(tmp209, tmp210, tmp211) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp208 }).Flatten();
        tmp212 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp213 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { tmp212 });
        tmp214 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp213 });
        tmp215 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp211 });
        tmp216 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp214 }, TNode<UintPtrT> { tmp215 });
        ca_.Branch(tmp216, &block260, std::vector<compiler::Node*> {}, &block261, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp217;
    TNode<IntPtrT> tmp218;
    TNode<Object> tmp219;
    TNode<IntPtrT> tmp220;
    TNode<Object> tmp221;
    TNode<IntPtrT> tmp222;
    TNode<IntPtrT> tmp223;
    TNode<UintPtrT> tmp224;
    TNode<IntPtrT> tmp225;
    TNode<UintPtrT> tmp226;
    TNode<UintPtrT> tmp227;
    TNode<BoolT> tmp228;
    if (block260.is_used()) {
        ca_.Bind(&block260);
        tmp217 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp213 });
        tmp218 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp210 }, TNode<IntPtrT> { tmp217 });
        std::tie(tmp219, tmp220) = NewReference_Object_0(state_, TNode<Object> { tmp209 }, TNode<IntPtrT> { tmp218 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp219, tmp220 }, tmp10);
        std::tie(tmp221, tmp222, tmp223) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp208 }).Flatten();
        tmp224 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp225 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { tmp224 });
        tmp226 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp225 });
        tmp227 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp223 });
        tmp228 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp226 }, TNode<UintPtrT> { tmp227 });
        ca_.Branch(tmp228, &block269, std::vector<compiler::Node*> {}, &block270, std::vector<compiler::Node*> {});
    }

    if (block261.is_used()) {
        ca_.Bind(&block261);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> tmp229;
    TNode<IntPtrT> tmp230;
    TNode<Object> tmp231;
    TNode<IntPtrT> tmp232;
    TNode<Object> tmp233;
    TNode<IntPtrT> tmp234;
    TNode<IntPtrT> tmp235;
    TNode<UintPtrT> tmp236;
    TNode<IntPtrT> tmp237;
    TNode<UintPtrT> tmp238;
    TNode<UintPtrT> tmp239;
    TNode<BoolT> tmp240;
    if (block269.is_used()) {
        ca_.Bind(&block269);
        tmp229 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp225 });
        tmp230 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp222 }, TNode<IntPtrT> { tmp229 });
        std::tie(tmp231, tmp232) = NewReference_Object_0(state_, TNode<Object> { tmp221 }, TNode<IntPtrT> { tmp230 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp231, tmp232 }, tmp23);
        std::tie(tmp233, tmp234, tmp235) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp208 }).Flatten();
        tmp236 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp237 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { tmp236 });
        tmp238 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp237 });
        tmp239 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp235 });
        tmp240 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp238 }, TNode<UintPtrT> { tmp239 });
        ca_.Branch(tmp240, &block278, std::vector<compiler::Node*> {}, &block279, std::vector<compiler::Node*> {});
    }

    if (block270.is_used()) {
        ca_.Bind(&block270);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> tmp241;
    TNode<IntPtrT> tmp242;
    TNode<Object> tmp243;
    TNode<IntPtrT> tmp244;
    TNode<Object> tmp245;
    TNode<IntPtrT> tmp246;
    TNode<IntPtrT> tmp247;
    TNode<UintPtrT> tmp248;
    TNode<IntPtrT> tmp249;
    TNode<UintPtrT> tmp250;
    TNode<UintPtrT> tmp251;
    TNode<BoolT> tmp252;
    if (block278.is_used()) {
        ca_.Bind(&block278);
        tmp241 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp237 });
        tmp242 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp234 }, TNode<IntPtrT> { tmp241 });
        std::tie(tmp243, tmp244) = NewReference_Object_0(state_, TNode<Object> { tmp233 }, TNode<IntPtrT> { tmp242 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp243, tmp244 }, p_target);
        std::tie(tmp245, tmp246, tmp247) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { tmp208 }).Flatten();
        tmp248 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x3ull));
        tmp249 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { tmp248 });
        tmp250 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp249 });
        tmp251 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp247 });
        tmp252 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp250 }, TNode<UintPtrT> { tmp251 });
        ca_.Branch(tmp252, &block287, std::vector<compiler::Node*> {}, &block288, std::vector<compiler::Node*> {});
    }

    if (block279.is_used()) {
        ca_.Bind(&block279);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> tmp253;
    TNode<IntPtrT> tmp254;
    TNode<Object> tmp255;
    TNode<IntPtrT> tmp256;
    TNode<Smi> tmp257;
    TNode<Object> tmp258;
    TNode<IntPtrT> tmp259;
    TNode<IntPtrT> tmp260;
    TNode<UintPtrT> tmp261;
    TNode<UintPtrT> tmp262;
    TNode<BoolT> tmp263;
    if (block287.is_used()) {
        ca_.Bind(&block287);
        tmp253 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp249 });
        tmp254 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp246 }, TNode<IntPtrT> { tmp253 });
        std::tie(tmp255, tmp256) = NewReference_Object_0(state_, TNode<Object> { tmp245 }, TNode<IntPtrT> { tmp254 }).Flatten();
        tmp257 = SmiConstant_0(state_, IntegerLiteral(false, 0x1ull));
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp255, tmp256 }, tmp257);
        std::tie(tmp258, tmp259, tmp260) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_vector }).Flatten();
        tmp261 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { p_index });
        tmp262 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp260 });
        tmp263 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp261 }, TNode<UintPtrT> { tmp262 });
        ca_.Branch(tmp263, &block295, std::vector<compiler::Node*> {}, &block296, std::vector<compiler::Node*> {});
    }

    if (block288.is_used()) {
        ca_.Bind(&block288);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> tmp264;
    TNode<IntPtrT> tmp265;
    TNode<Object> tmp266;
    TNode<IntPtrT> tmp267;
    TNode<Object> tmp268;
    TNode<IntPtrT> tmp269;
    TNode<IntPtrT> tmp270;
    TNode<IntPtrT> tmp271;
    TNode<IntPtrT> tmp272;
    TNode<UintPtrT> tmp273;
    TNode<UintPtrT> tmp274;
    TNode<BoolT> tmp275;
    if (block295.is_used()) {
        ca_.Bind(&block295);
        tmp264 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { p_index });
        tmp265 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp259 }, TNode<IntPtrT> { tmp264 });
        std::tie(tmp266, tmp267) = NewReference_Object_0(state_, TNode<Object> { tmp258 }, TNode<IntPtrT> { tmp265 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp266, tmp267 }, tmp208);
        std::tie(tmp268, tmp269, tmp270) = FieldSliceFixedArrayObjects_0(state_, TNode<FixedArray> { p_vector }).Flatten();
        tmp271 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp272 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_index }, TNode<IntPtrT> { tmp271 });
        tmp273 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp272 });
        tmp274 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp270 });
        tmp275 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp273 }, TNode<UintPtrT> { tmp274 });
        ca_.Branch(tmp275, &block303, std::vector<compiler::Node*> {}, &block304, std::vector<compiler::Node*> {});
    }

    if (block296.is_used()) {
        ca_.Bind(&block296);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<IntPtrT> tmp276;
    TNode<IntPtrT> tmp277;
    TNode<Object> tmp278;
    TNode<IntPtrT> tmp279;
    TNode<Undefined> tmp280;
    if (block303.is_used()) {
        ca_.Bind(&block303);
        tmp276 = TimesSizeOf_Object_0(state_, TNode<IntPtrT> { tmp272 });
        tmp277 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp269 }, TNode<IntPtrT> { tmp276 });
        std::tie(tmp278, tmp279) = NewReference_Object_0(state_, TNode<Object> { tmp268 }, TNode<IntPtrT> { tmp277 }).Flatten();
        tmp280 = Undefined_0(state_);
        CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference { tmp278, tmp279 }, tmp280);
        ca_.Goto(&block218);
    }

    if (block304.is_used()) {
        ca_.Bind(&block304);
        CodeStubAssembler(state_).Unreachable();
    }

    if (block218.is_used()) {
        ca_.Bind(&block218);
        ca_.Goto(&block134);
    }

    if (block134.is_used()) {
        ca_.Bind(&block134);
        ca_.Goto(&block103);
    }

    if (block103.is_used()) {
        ca_.Bind(&block103);
        ca_.Goto(&block1);
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(&block307);
    }

    ca_.Bind(&block307);
}

TF_BUILTIN(CallRefIC, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<FixedArray> parameter0 = UncheckedParameter<FixedArray>(Descriptor::kVector);
    USE(parameter0);
    TNode<Int32T> parameter1 = UncheckedParameter<Int32T>(Descriptor::kVectorIndex);
    USE(parameter1);
    TNode<UintPtrT> parameter2 = UncheckedParameter<UintPtrT>(Descriptor::kSignatureHash);
    USE(parameter2);
    TNode<WasmFuncRef> parameter3 = UncheckedParameter<WasmFuncRef>(Descriptor::kFuncref);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<WasmInternalFunction> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<RawPtrT> tmp3;
    TNode<TrustedObject> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_intptr_int32_0(state_, TNode<Int32T> { parameter1 });
        UpdateCallRefOrIndirectIC_0(state_, TNode<FixedArray> { parameter0 }, TNode<IntPtrT> { tmp0 }, TNode<Object> { parameter3 });
        tmp1 = CodeStubAssembler(state_).LoadWasmInternalFunctionFromFuncRef(TNode<WasmFuncRef> { parameter3 });
        tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp3 = CodeStubAssembler(state_).LoadReference<RawPtrT>(CodeStubAssembler::Reference { tmp1, tmp2 });
        tmp4 = CodeStubAssembler(state_).LoadImplicitArgFromWasmInternalFunction(TNode<WasmInternalFunction> { tmp1 });
        CodeStubAssembler(state_).Return(tmp3, tmp4);
    }
}

TF_BUILTIN(CallIndirectIC, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<FixedArray> parameter0 = UncheckedParameter<FixedArray>(Descriptor::kVector);
    USE(parameter0);
    TNode<Int32T> parameter1 = UncheckedParameter<Int32T>(Descriptor::kVectorIndex);
    USE(parameter1);
    TNode<RawPtrT> parameter2 = UncheckedParameter<RawPtrT>(Descriptor::kTarget);
    USE(parameter2);
    TNode<TrustedObject> parameter3 = UncheckedParameter<TrustedObject>(Descriptor::kImplicitArg);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject> { parameter3 }, TNode<MaybeObject> { tmp0 });
        ca_.Branch(tmp1, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<UintPtrT> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<UintPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<Smi> tmp6;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp2 = Convert_uintptr_WasmCodePointer_0(state_, TNode<RawPtrT> { parameter2 });
        tmp3 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, kSmiMaxValue);
        tmp4 = CodeStubAssembler(state_).WordAnd(TNode<UintPtrT> { tmp2 }, TNode<UintPtrT> { tmp3 });
        tmp5 = CodeStubAssembler(state_).Signed(TNode<UintPtrT> { tmp4 });
        tmp6 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT> { tmp5 });
        ca_.Goto(&block3, tmp6);
    }

    TNode<Undefined> tmp7;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp7 = Undefined_0(state_);
        ca_.Goto(&block3, tmp7);
    }

    TNode<Object> phi_bb3_5;
    TNode<IntPtrT> tmp8;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_5);
        tmp8 = Convert_intptr_int32_0(state_, TNode<Int32T> { parameter1 });
        UpdateCallRefOrIndirectIC_0(state_, TNode<FixedArray> { parameter0 }, TNode<IntPtrT> { tmp8 }, TNode<Object> { phi_bb3_5 });
        CodeStubAssembler(state_).Return(parameter2, parameter3);
    }
}

TF_BUILTIN(WasmGetOwnProperty, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kObject);
    USE(parameter1);
    TNode<Name> parameter2 = UncheckedParameter<Name>(Descriptor::kUniqueName);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

    TNode<HeapObject> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object> { parameter1 }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(&block2);
    }

    TNode<JSReceiver> tmp2;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_JSReceiver_0(state_, TNode<HeapObject> { tmp0 }, &label3);
        ca_.Goto(&block5);
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block6);
        }
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block2);
    }

    TNode<IntPtrT> tmp4;
    TNode<Map> tmp5;
    TNode<Uint16T> tmp6;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp5 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { tmp2, tmp4 });
        tmp6 = CodeStubAssembler(state_).LoadInstanceType(TNode<HeapObject> { tmp2 });
        compiler::CodeAssemblerLabel label7(&ca_);
        compiler::CodeAssemblerLabel label8(&ca_);
        compiler::CodeAssemblerLabel label9(&ca_);
        CodeStubAssembler(state_).TryHasOwnProperty(
            TNode<HeapObject> { tmp2 }, TNode<Map> { tmp5 }, TNode<Uint16T> { tmp6 }, TNode<Name> { parameter2 }, &label7, &label8, &label9);
        if (label7.is_used()) {
            ca_.Bind(&label7);
            ca_.Goto(&block9);
        }
        if (label8.is_used()) {
            ca_.Bind(&label8);
            ca_.Goto(&block10);
        }
        if (label9.is_used()) {
            ca_.Bind(&label9);
            ca_.Goto(&block11);
        }
    }

    TNode<Smi> tmp10;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp10 = CodeStubAssembler(state_).SmiConstant(OnNonExistent::kReturnUndefined);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kGetPropertyWithReceiver, parameter0, tmp2, parameter2, tmp2, tmp10);
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block2);
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block2);
    }

    TNode<Undefined> tmp11;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp11 = Undefined_0(state_);
        CodeStubAssembler(state_).Return(tmp11);
    }
}

TF_BUILTIN(WasmTrap, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Smi> parameter0 = UncheckedParameter<Smi>(Descriptor::kError);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadContextFromWasmOrJsFrame();
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kThrowWasmError, tmp0, parameter0);
    }
}

TF_BUILTIN(ThrowWasmTrapUnreachable, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapUnreachable);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(WasmTrapHandlerThrowTrap, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadContextFromWasmOrJsFrame();
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kTrapHandlerThrowWasmError, tmp0);
    }
}

TF_BUILTIN(WasmPropagateException, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kNoContext_0(state_);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kPropagateException, tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapMemOutOfBounds, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapMemOutOfBounds);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapUnalignedAccess, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapUnalignedAccess);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapDivByZero, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapDivByZero);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapDivUnrepresentable, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapDivUnrepresentable);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapRemByZero, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapRemByZero);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapFloatUnrepresentable, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapFloatUnrepresentable);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapFuncSigMismatch, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapFuncSigMismatch);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapDataSegmentOutOfBounds, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapDataSegmentOutOfBounds);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapElementSegmentOutOfBounds, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapElementSegmentOutOfBounds);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapTableOutOfBounds, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapTableOutOfBounds);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapRethrowNull, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapRethrowNull);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapNullDereference, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapNullDereference);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapIllegalCast, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapIllegalCast);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapArrayOutOfBounds, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapArrayOutOfBounds);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapArrayTooLarge, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapArrayTooLarge);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

TF_BUILTIN(ThrowWasmTrapStringOffsetOutOfBounds, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapStringOffsetOutOfBounds);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kWasmTrap, TNode<Object>(), tmp0);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=896&c=1
void ModifyThreadInWasmFlag_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_newValue)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Object> tmp3;
    TNode<IntPtrT> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_intptr_0(state_, Isolate::thread_in_wasm_flag_address_offset());
        tmp1 = CodeStubAssembler(state_).LoadPointerFromRootRegister(TNode<IntPtrT> { tmp0 });
        tmp2 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        std::tie(tmp3, tmp4) = GetRefAt_int32_WasmCodePointer_0(state_, TNode<RawPtrT> { tmp1 }, TNode<IntPtrT> { tmp2 }).Flatten();
        CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference { tmp3, tmp4 }, p_newValue);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
}

TF_BUILTIN(WasmStringNewWtf8, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<UintPtrT> parameter0 = UncheckedParameter<UintPtrT>(Descriptor::kOffset);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kSize);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kMemory);
    USE(parameter2);
    TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kUtf8Variant);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Smi> tmp2;
    TNode<Number> tmp3;
    TNode<Number> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp2 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter2 });
        tmp3 = UintPtrToNumberRounding_0(state_, TNode<UintPtrT> { parameter0 });
        tmp4 = ca_.CallBuiltin<Number>(Builtin::kWasmUint32ToNumber, TNode<Object>(), parameter1);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringNewWtf8, tmp1, tmp0, tmp2, parameter3, tmp3, tmp4);
    }
}

TF_BUILTIN(WasmStringNewWtf8Array, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kStart);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kEnd);
    USE(parameter1);
    TNode<WasmArray> parameter2 = UncheckedParameter<WasmArray>(Descriptor::kArray);
    USE(parameter2);
    TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kUtf8Variant);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Uint32T> tmp2;
    TNode<BoolT> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadContextFromWasmOrJsFrame();
        tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp2 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { parameter2, tmp1 });
        tmp3 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { tmp2 }, TNode<Uint32T> { parameter1 });
        ca_.Branch(tmp3, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block2);
    }

    TNode<BoolT> tmp4;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp4 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { parameter1 }, TNode<Uint32T> { parameter0 });
        ca_.Branch(tmp4, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        ca_.Goto(&block2);
    }

    TNode<Smi> tmp5;
    TNode<Smi> tmp6;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp5 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter0 });
        tmp6 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter1 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringNewWtf8Array, tmp0, parameter3, parameter2, tmp5, tmp6);
    }

    TNode<Smi> tmp7;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp7 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapArrayOutOfBounds);
        CodeStubAssembler(state_).CallRuntime(Runtime::kThrowWasmError, tmp0, tmp7);
        CodeStubAssembler(state_).Unreachable();
    }
}

TF_BUILTIN(WasmStringNewWtf16, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kMemory);
    USE(parameter0);
    TNode<UintPtrT> parameter1 = UncheckedParameter<UintPtrT>(Descriptor::kOffset);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kSize);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Smi> tmp2;
    TNode<Number> tmp3;
    TNode<Number> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp2 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter0 });
        tmp3 = UintPtrToNumberRounding_0(state_, TNode<UintPtrT> { parameter1 });
        tmp4 = ca_.CallBuiltin<Number>(Builtin::kWasmUint32ToNumber, TNode<Object>(), parameter2);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringNewWtf16, tmp1, tmp0, tmp2, tmp3, tmp4);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=951&c=1
TNode<String> StringFromTwoByteSlice_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length, TorqueStructSlice_char16_ConstReference_char16_0 p_slice)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, Uint32T> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, Uint32T> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, Uint32T> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, Uint32T> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<IntPtrT, Uint32T> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp1 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x8ull));
        tmp2 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT> { p_slice.length }, TNode<IntPtrT> { tmp1 });
        ca_.Goto(&block6, tmp0);
    }

    TNode<IntPtrT> phi_bb6_4;
    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_4);
        tmp3 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT> { phi_bb6_4 }, TNode<IntPtrT> { tmp2 });
        ca_.Branch(tmp3, &block4, std::vector<compiler::Node*> { phi_bb6_4 }, &block5, std::vector<compiler::Node*> { phi_bb6_4 });
    }

    TNode<IntPtrT> phi_bb4_4;
    TNode<IntPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<Object> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<Uint16T> tmp8;
    TNode<Uint32T> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<Object> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<Uint16T> tmp16;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<Object> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<Uint16T> tmp25;
    TNode<Uint32T> tmp26;
    TNode<Uint32T> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<Object> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<Uint16T> tmp34;
    TNode<Uint32T> tmp35;
    TNode<Uint32T> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<Object> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<Uint16T> tmp43;
    TNode<Uint32T> tmp44;
    TNode<Uint32T> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<IntPtrT> tmp49;
    TNode<Object> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<Uint16T> tmp52;
    TNode<Uint32T> tmp53;
    TNode<Uint32T> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<Object> tmp59;
    TNode<IntPtrT> tmp60;
    TNode<Uint16T> tmp61;
    TNode<Uint32T> tmp62;
    TNode<Uint32T> tmp63;
    TNode<IntPtrT> tmp64;
    TNode<IntPtrT> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<Object> tmp68;
    TNode<IntPtrT> tmp69;
    TNode<Uint16T> tmp70;
    TNode<Uint32T> tmp71;
    TNode<Uint32T> tmp72;
    TNode<Uint32T> tmp73;
    TNode<BoolT> tmp74;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_4);
        tmp4 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { phi_bb4_4 });
        tmp5 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_slice.offset }, TNode<IntPtrT> { tmp4 });
        std::tie(tmp6, tmp7) = NewReference_char16_0(state_, TNode<Object> { p_slice.object }, TNode<IntPtrT> { tmp5 }).Flatten();
        tmp8 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp6, tmp7 });
        tmp9 = Convert_uint32_char16_0(state_, TNode<Uint16T> { tmp8 });
        tmp10 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp11 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb4_4 }, TNode<IntPtrT> { tmp10 });
        tmp12 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { tmp11 });
        tmp13 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_slice.offset }, TNode<IntPtrT> { tmp12 });
        std::tie(tmp14, tmp15) = NewReference_char16_0(state_, TNode<Object> { p_slice.object }, TNode<IntPtrT> { tmp13 }).Flatten();
        tmp16 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp14, tmp15 });
        tmp17 = Convert_uint32_char16_0(state_, TNode<Uint16T> { tmp16 });
        tmp18 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T> { tmp9 }, TNode<Uint32T> { tmp17 });
        tmp19 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp20 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb4_4 }, TNode<IntPtrT> { tmp19 });
        tmp21 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { tmp20 });
        tmp22 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_slice.offset }, TNode<IntPtrT> { tmp21 });
        std::tie(tmp23, tmp24) = NewReference_char16_0(state_, TNode<Object> { p_slice.object }, TNode<IntPtrT> { tmp22 }).Flatten();
        tmp25 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp23, tmp24 });
        tmp26 = Convert_uint32_char16_0(state_, TNode<Uint16T> { tmp25 });
        tmp27 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T> { tmp18 }, TNode<Uint32T> { tmp26 });
        tmp28 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x3ull));
        tmp29 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb4_4 }, TNode<IntPtrT> { tmp28 });
        tmp30 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { tmp29 });
        tmp31 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_slice.offset }, TNode<IntPtrT> { tmp30 });
        std::tie(tmp32, tmp33) = NewReference_char16_0(state_, TNode<Object> { p_slice.object }, TNode<IntPtrT> { tmp31 }).Flatten();
        tmp34 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp32, tmp33 });
        tmp35 = Convert_uint32_char16_0(state_, TNode<Uint16T> { tmp34 });
        tmp36 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T> { tmp27 }, TNode<Uint32T> { tmp35 });
        tmp37 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x4ull));
        tmp38 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb4_4 }, TNode<IntPtrT> { tmp37 });
        tmp39 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { tmp38 });
        tmp40 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_slice.offset }, TNode<IntPtrT> { tmp39 });
        std::tie(tmp41, tmp42) = NewReference_char16_0(state_, TNode<Object> { p_slice.object }, TNode<IntPtrT> { tmp40 }).Flatten();
        tmp43 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp41, tmp42 });
        tmp44 = Convert_uint32_char16_0(state_, TNode<Uint16T> { tmp43 });
        tmp45 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T> { tmp36 }, TNode<Uint32T> { tmp44 });
        tmp46 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x5ull));
        tmp47 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb4_4 }, TNode<IntPtrT> { tmp46 });
        tmp48 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { tmp47 });
        tmp49 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_slice.offset }, TNode<IntPtrT> { tmp48 });
        std::tie(tmp50, tmp51) = NewReference_char16_0(state_, TNode<Object> { p_slice.object }, TNode<IntPtrT> { tmp49 }).Flatten();
        tmp52 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp50, tmp51 });
        tmp53 = Convert_uint32_char16_0(state_, TNode<Uint16T> { tmp52 });
        tmp54 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T> { tmp45 }, TNode<Uint32T> { tmp53 });
        tmp55 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x6ull));
        tmp56 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb4_4 }, TNode<IntPtrT> { tmp55 });
        tmp57 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { tmp56 });
        tmp58 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_slice.offset }, TNode<IntPtrT> { tmp57 });
        std::tie(tmp59, tmp60) = NewReference_char16_0(state_, TNode<Object> { p_slice.object }, TNode<IntPtrT> { tmp58 }).Flatten();
        tmp61 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp59, tmp60 });
        tmp62 = Convert_uint32_char16_0(state_, TNode<Uint16T> { tmp61 });
        tmp63 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T> { tmp54 }, TNode<Uint32T> { tmp62 });
        tmp64 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x7ull));
        tmp65 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb4_4 }, TNode<IntPtrT> { tmp64 });
        tmp66 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { tmp65 });
        tmp67 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_slice.offset }, TNode<IntPtrT> { tmp66 });
        std::tie(tmp68, tmp69) = NewReference_char16_0(state_, TNode<Object> { p_slice.object }, TNode<IntPtrT> { tmp67 }).Flatten();
        tmp70 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp68, tmp69 });
        tmp71 = Convert_uint32_char16_0(state_, TNode<Uint16T> { tmp70 });
        tmp72 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T> { tmp63 }, TNode<Uint32T> { tmp71 });
        tmp73 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xffull));
        tmp74 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp72 }, TNode<Uint32T> { tmp73 });
        ca_.Branch(tmp74, &block15, std::vector<compiler::Node*> { phi_bb4_4 }, &block16, std::vector<compiler::Node*> { phi_bb4_4 });
    }

    TNode<IntPtrT> phi_bb15_4;
    if (block15.is_used()) {
        ca_.Bind(&block15, &phi_bb15_4);
        ca_.Goto(&block3);
    }

    TNode<IntPtrT> phi_bb16_4;
    TNode<IntPtrT> tmp75;
    TNode<IntPtrT> tmp76;
    if (block16.is_used()) {
        ca_.Bind(&block16, &phi_bb16_4);
        tmp75 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x8ull));
        tmp76 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb16_4 }, TNode<IntPtrT> { tmp75 });
        ca_.Goto(&block6, tmp76);
    }

    TNode<IntPtrT> phi_bb5_4;
    TNode<Uint32T> tmp77;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_4);
        tmp77 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block19, phi_bb5_4, tmp77);
    }

    TNode<IntPtrT> phi_bb19_4;
    TNode<Uint32T> phi_bb19_7;
    TNode<BoolT> tmp78;
    if (block19.is_used()) {
        ca_.Bind(&block19, &phi_bb19_4, &phi_bb19_7);
        tmp78 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT> { phi_bb19_4 }, TNode<IntPtrT> { p_slice.length });
        ca_.Branch(tmp78, &block17, std::vector<compiler::Node*> { phi_bb19_4, phi_bb19_7 }, &block18, std::vector<compiler::Node*> { phi_bb19_4, phi_bb19_7 });
    }

    TNode<IntPtrT> phi_bb17_4;
    TNode<Uint32T> phi_bb17_7;
    TNode<IntPtrT> tmp79;
    TNode<IntPtrT> tmp80;
    TNode<Object> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<Uint16T> tmp83;
    TNode<Uint32T> tmp84;
    TNode<Uint32T> tmp85;
    TNode<IntPtrT> tmp86;
    TNode<IntPtrT> tmp87;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_4, &phi_bb17_7);
        tmp79 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { phi_bb17_4 });
        tmp80 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_slice.offset }, TNode<IntPtrT> { tmp79 });
        std::tie(tmp81, tmp82) = NewReference_char16_0(state_, TNode<Object> { p_slice.object }, TNode<IntPtrT> { tmp80 }).Flatten();
        tmp83 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp81, tmp82 });
        tmp84 = Convert_uint32_char16_0(state_, TNode<Uint16T> { tmp83 });
        tmp85 = CodeStubAssembler(state_).Word32Or(TNode<Uint32T> { phi_bb17_7 }, TNode<Uint32T> { tmp84 });
        tmp86 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp87 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb17_4 }, TNode<IntPtrT> { tmp86 });
        ca_.Goto(&block19, tmp87, tmp85);
    }

    TNode<IntPtrT> phi_bb18_4;
    TNode<Uint32T> phi_bb18_7;
    TNode<Uint32T> tmp88;
    TNode<BoolT> tmp89;
    if (block18.is_used()) {
        ca_.Bind(&block18, &phi_bb18_4, &phi_bb18_7);
        tmp88 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xffull));
        tmp89 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { phi_bb18_7 }, TNode<Uint32T> { tmp88 });
        ca_.Branch(tmp89, &block21, std::vector<compiler::Node*> { phi_bb18_4, phi_bb18_7 }, &block22, std::vector<compiler::Node*> { phi_bb18_4, phi_bb18_7 });
    }

    TNode<IntPtrT> phi_bb21_4;
    TNode<Uint32T> phi_bb21_7;
    if (block21.is_used()) {
        ca_.Bind(&block21, &phi_bb21_4, &phi_bb21_7);
        ca_.Goto(&block3);
    }

    TNode<IntPtrT> phi_bb22_4;
    TNode<Uint32T> phi_bb22_7;
    TNode<IntPtrT> tmp90;
    TNode<IntPtrT> tmp91;
    TNode<SeqOneByteString> tmp92;
    if (block22.is_used()) {
        ca_.Bind(&block22, &phi_bb22_4, &phi_bb22_7);
        tmp90 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { p_slice.length });
        tmp91 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_slice.offset }, TNode<IntPtrT> { tmp90 });
        tmp92 = AllocateNonEmptySeqOneByteString_TwoByteToOneByteIterator_0(state_, TNode<Uint32T> { p_length },
            TorqueStructTwoByteToOneByteIterator_0 { TNode<Object> { p_slice.object }, TNode<IntPtrT> { p_slice.offset }, TNode<IntPtrT> { tmp91 } });
        ca_.Goto(&block1, tmp92);
    }

    TNode<IntPtrT> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<String> tmp95;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp93 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { p_slice.length });
        tmp94 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { p_slice.offset }, TNode<IntPtrT> { tmp93 });
        tmp95 = AllocateSeqTwoByteString_SliceIterator_char16_ConstReference_char16_0(state_, TNode<Uint32T> { p_length },
            TorqueStructSliceIterator_char16_ConstReference_char16_0 {
                TNode<Object> { p_slice.object }, TNode<IntPtrT> { p_slice.offset }, TNode<IntPtrT> { tmp94 }, TorqueStructUnsafe_0 {} });
        ca_.Goto(&block1, tmp95);
    }

    TNode<String> phi_bb1_4;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_4);
        ca_.Goto(&block24, phi_bb1_4);
    }

    TNode<String> phi_bb24_4;
    ca_.Bind(&block24, &phi_bb24_4);
    return TNode<String> { phi_bb24_4 };
}

TF_BUILTIN(WasmStringNewWtf16Array, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<WasmArray> parameter0 = UncheckedParameter<WasmArray>(Descriptor::kArray);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kStart);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kEnd);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Uint32T> tmp1;
    TNode<BoolT> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { parameter0, tmp0 });
        tmp2 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { tmp1 }, TNode<Uint32T> { parameter2 });
        ca_.Branch(tmp2, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        ca_.Goto(&block4);
    }

    TNode<BoolT> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp3 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { parameter2 }, TNode<Uint32T> { parameter1 });
        ca_.Branch(tmp3, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        ca_.Goto(&block4);
    }

    TNode<Uint32T> tmp4;
    TNode<Uint32T> tmp5;
    TNode<BoolT> tmp6;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp4 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { parameter2 }, TNode<Uint32T> { parameter1 });
        tmp5 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp6 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { tmp4 }, TNode<Uint32T> { tmp5 });
        ca_.Branch(tmp6, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    TNode<String> tmp7;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp7 = kEmptyString_0(state_);
        CodeStubAssembler(state_).Return(tmp7);
    }

    TNode<Uint32T> tmp8;
    TNode<BoolT> tmp9;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp8 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp9 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { tmp4 }, TNode<Uint32T> { tmp8 });
        ca_.Branch(tmp9, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<Object> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<Uint16T> tmp16;
    TNode<String> tmp17;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp10 = Convert_intptr_uint32_0(state_, TNode<Uint32T> { parameter1 });
        tmp11 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { tmp10 });
        tmp12 = FromConstexpr_intptr_constexpr_int32_0(state_, WasmArray::kHeaderSize);
        tmp13 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp12 }, TNode<IntPtrT> { tmp11 });
        std::tie(tmp14, tmp15) = NewReference_char16_0(state_, TNode<Object> { parameter0 }, TNode<IntPtrT> { tmp13 }).Flatten();
        tmp16 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp14, tmp15 });
        tmp17 = CodeStubAssembler(state_).StringFromSingleCharCode(TNode<Uint16T> { tmp16 });
        CodeStubAssembler(state_).Return(tmp17);
    }

    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block12.is_used()) {
        ca_.Bind(&block12);
        tmp18 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x20ull));
        tmp19 = CodeStubAssembler(state_).Uint32GreaterThanOrEqual(TNode<Uint32T> { tmp4 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block13, std::vector<compiler::Node*> {}, &block14, std::vector<compiler::Node*> {});
    }

    TNode<NativeContext> tmp20;
    TNode<Smi> tmp21;
    TNode<Smi> tmp22;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        tmp20 = WasmBuiltinsAssembler(state_).LoadContextFromWasmOrJsFrame();
        tmp21 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter1 });
        tmp22 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter2 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringNewWtf16Array, tmp20, parameter0, tmp21, tmp22);
    }

    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<Uint32T> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<Object> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<Object> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        tmp23 = Convert_intptr_uint32_0(state_, TNode<Uint32T> { tmp4 });
        tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp25 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { parameter0, tmp24 });
        tmp26 = Convert_intptr_uint32_0(state_, TNode<Uint32T> { tmp25 });
        tmp27 = FromConstexpr_intptr_constexpr_int32_0(state_, WasmArray::kHeaderSize);
        std::tie(tmp28, tmp29, tmp30)
            = NewConstSlice_char16_0(state_, TNode<Object> { parameter0 }, TNode<IntPtrT> { tmp27 }, TNode<IntPtrT> { tmp26 }).Flatten();
        tmp31 = Convert_intptr_uint32_0(state_, TNode<Uint32T> { parameter1 });
        compiler::CodeAssemblerLabel label35(&ca_);
        std::tie(tmp32, tmp33, tmp34) = Subslice_char16_0(state_,
            TorqueStructSlice_char16_ConstReference_char16_0 {
                TNode<Object> { tmp28 }, TNode<IntPtrT> { tmp29 }, TNode<IntPtrT> { tmp30 }, TorqueStructUnsafe_0 {} },
            TNode<IntPtrT> { tmp31 }, TNode<IntPtrT> { tmp23 }, &label35)
                                            .Flatten();
        ca_.Goto(&block17);
        if (label35.is_used()) {
            ca_.Bind(&label35);
            ca_.Goto(&block18);
        }
    }

    if (block18.is_used()) {
        ca_.Bind(&block18);
        ca_.Goto(&block4);
    }

    TNode<String> tmp36;
    if (block17.is_used()) {
        ca_.Bind(&block17);
        tmp36 = StringFromTwoByteSlice_0(state_, TNode<Uint32T> { tmp4 },
            TorqueStructSlice_char16_ConstReference_char16_0 {
                TNode<Object> { tmp32 }, TNode<IntPtrT> { tmp33 }, TNode<IntPtrT> { tmp34 }, TorqueStructUnsafe_0 {} });
        CodeStubAssembler(state_).Return(tmp36);
    }

    TNode<NativeContext> tmp37;
    TNode<Smi> tmp38;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp37 = WasmBuiltinsAssembler(state_).LoadContextFromWasmOrJsFrame();
        tmp38 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapArrayOutOfBounds);
        CodeStubAssembler(state_).CallRuntime(Runtime::kThrowWasmError, tmp37, tmp38);
        CodeStubAssembler(state_).Unreachable();
    }
}

TF_BUILTIN(WasmStringFromDataSegment, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kSegmentLength);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kArrayStart);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kArrayEnd);
    USE(parameter2);
    TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kSegmentIndex);
    USE(parameter3);
    TNode<Smi> parameter4 = UncheckedParameter<Smi>(Descriptor::kSegmentOffset);
    USE(parameter4);
    TNode<Smi> parameter5 = UncheckedParameter<Smi>(Descriptor::kVariant);
    USE(parameter5);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<Int32T> tmp1;
    TNode<Uint32T> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<Uint32T> tmp4;
    TNode<Uint32T> tmp5;
    TNode<BoolT> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { parameter4 });
        tmp2 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp1 });
        tmp3 = kSmiMax_0(state_);
        tmp4 = Convert_uint32_uintptr_0(state_, TNode<UintPtrT> { tmp3 });
        tmp5 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { tmp4 }, TNode<Uint32T> { tmp2 });
        tmp6 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { parameter0 }, TNode<Uint32T> { tmp5 });
        ca_.Branch(tmp6, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        ca_.Goto(&block4);
    }

    TNode<BoolT> tmp7;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp7 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { parameter1 }, TNode<Uint32T> { parameter0 });
        ca_.Branch(tmp7, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        ca_.Goto(&block2);
    }

    TNode<BoolT> tmp8;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp8 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { parameter2 }, TNode<Uint32T> { parameter1 });
        ca_.Branch(tmp8, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block2);
    }

    TNode<Uint32T> tmp9;
    TNode<Uint32T> tmp10;
    TNode<BoolT> tmp11;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp9 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { parameter2 }, TNode<Uint32T> { parameter1 });
        tmp10 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { parameter0 }, TNode<Uint32T> { parameter1 });
        tmp11 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp9 }, TNode<Uint32T> { tmp10 });
        ca_.Branch(tmp11, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block2);
    }

    TNode<Uint32T> tmp12;
    TNode<Smi> tmp13;
    if (block12.is_used()) {
        ca_.Bind(&block12);
        tmp12 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { tmp2 }, TNode<Uint32T> { parameter1 });
        compiler::CodeAssemblerLabel label14(&ca_);
        tmp13 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T> { tmp12 }, &label14);
        ca_.Goto(&block13);
        if (label14.is_used()) {
            ca_.Bind(&label14);
            ca_.Goto(&block14);
        }
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block4);
    }

    TNode<Smi> tmp15;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        compiler::CodeAssemblerLabel label16(&ca_);
        tmp15 = Convert_PositiveSmi_uint32_0(state_, TNode<Uint32T> { tmp9 }, &label16);
        ca_.Goto(&block15);
        if (label16.is_used()) {
            ca_.Bind(&label16);
            ca_.Goto(&block16);
        }
    }

    if (block16.is_used()) {
        ca_.Bind(&block16);
        ca_.Goto(&block4);
    }

    TNode<NativeContext> tmp17;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp17 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringNewSegmentWtf8, tmp17, tmp0, parameter3, tmp13, tmp15, parameter5);
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapElementSegmentOutOfBounds, TNode<Object>());
    }

    if (block2.is_used()) {
        ca_.Bind(&block2);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kThrowWasmTrapArrayOutOfBounds, TNode<Object>());
    }
}

TF_BUILTIN(WasmStringAsWtf16, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kStr);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<ConsString> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_ConsString_1(state_, TNode<String> { parameter0 }, &label1);
        ca_.Goto(&block3);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block4);
        }
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        CodeStubAssembler(state_).Return(parameter0);
    }

    TNode<String> tmp2;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp2 = Flatten_1(state_, TNode<ConsString> { tmp0 });
        CodeStubAssembler(state_).Return(tmp2);
    }
}

TF_BUILTIN(WasmStringConst, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kIndex);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Smi> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp2 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter0 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringConst, tmp1, tmp0, tmp2);
    }
}

TF_BUILTIN(WasmStringMeasureUtf8, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    TNode<Number> tmp1;
    TNode<Int32T> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        tmp1 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringMeasureUtf8, tmp0, parameter0));
        tmp2 = NumberToInt32_0(state_, TNode<Number> { tmp1 });
        CodeStubAssembler(state_).Return(tmp2);
    }
}

TF_BUILTIN(WasmStringMeasureWtf8, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    TNode<Number> tmp1;
    TNode<Int32T> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        tmp1 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringMeasureWtf8, tmp0, parameter0));
        tmp2 = NumberToInt32_0(state_, TNode<Number> { tmp1 });
        CodeStubAssembler(state_).Return(tmp2);
    }
}

TF_BUILTIN(WasmStringEncodeWtf8, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<UintPtrT> parameter0 = UncheckedParameter<UintPtrT>(Descriptor::kOffset);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kMemory);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kUtf8Variant);
    USE(parameter2);
    TNode<String> parameter3 = UncheckedParameter<String>(Descriptor::kString);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Smi> tmp2;
    TNode<Smi> tmp3;
    TNode<Number> tmp4;
    TNode<Number> tmp5;
    TNode<Uint32T> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp2 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter1 });
        tmp3 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter2 });
        tmp4 = UintPtrToNumberRounding_0(state_, TNode<UintPtrT> { parameter0 });
        tmp5 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringEncodeWtf8, tmp1, tmp0, tmp2, tmp3, parameter3, tmp4));
        tmp6 = NumberToUint32_0(state_, TNode<Number> { tmp5 });
        CodeStubAssembler(state_).Return(tmp6);
    }
}

TF_BUILTIN(WasmStringEncodeWtf8Array, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
    USE(parameter0);
    TNode<WasmArray> parameter1 = UncheckedParameter<WasmArray>(Descriptor::kArray);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kStart);
    USE(parameter2);
    TNode<Smi> parameter3 = UncheckedParameter<Smi>(Descriptor::kUtf8Variant);
    USE(parameter3);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Number> tmp2;
    TNode<Number> tmp3;
    TNode<Uint32T> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp2 = ca_.CallBuiltin<Number>(Builtin::kWasmUint32ToNumber, TNode<Object>(), parameter2);
        tmp3 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringEncodeWtf8Array, tmp1, parameter3, parameter0, parameter1, tmp2));
        tmp4 = NumberToUint32_0(state_, TNode<Number> { tmp3 });
        CodeStubAssembler(state_).Return(tmp4);
    }
}

TF_BUILTIN(WasmStringToUtf8Array, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    TNode<WasmArray> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        tmp1 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringToUtf8Array, tmp0, parameter0));
        CodeStubAssembler(state_).Return(tmp1);
    }
}

TF_BUILTIN(WasmStringEncodeWtf16, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
    USE(parameter0);
    TNode<UintPtrT> parameter1 = UncheckedParameter<UintPtrT>(Descriptor::kOffset);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kMemory);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Smi> tmp2;
    TNode<Number> tmp3;
    TNode<Smi> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<Int32T> tmp6;
    TNode<Smi> tmp7;
    TNode<Object> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Int32T> tmp10;
    TNode<Uint32T> tmp11;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp2 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter2 });
        tmp3 = UintPtrToNumberRounding_0(state_, TNode<UintPtrT> { parameter1 });
        tmp4 = SmiConstant_0(state_, IntegerLiteral(false, 0x0ull));
        tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp6 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { parameter0, tmp5 });
        tmp7 = CodeStubAssembler(state_).SmiFromInt32(TNode<Int32T> { tmp6 });
        tmp8 = CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringEncodeWtf16, tmp1, tmp0, tmp2, parameter0, tmp3, tmp4, tmp7);
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp10 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { parameter0, tmp9 });
        tmp11 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp10 });
        CodeStubAssembler(state_).Return(tmp11);
    }
}

TF_BUILTIN(WasmStringEncodeWtf16Array, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
    USE(parameter0);
    TNode<WasmArray> parameter1 = UncheckedParameter<WasmArray>(Descriptor::kArray);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kStart);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, String> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, String> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block66(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block81(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block79(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block85(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block86(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block80(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Uint32T> tmp1;
    TNode<BoolT> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { parameter1, tmp0 });
        tmp2 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { parameter2 }, TNode<Uint32T> { tmp1 });
        ca_.Branch(tmp2, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        ca_.Goto(&block2);
    }

    TNode<IntPtrT> tmp3;
    TNode<Uint32T> tmp4;
    TNode<Uint32T> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<Int32T> tmp7;
    TNode<Uint32T> tmp8;
    TNode<BoolT> tmp9;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp4 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { parameter1, tmp3 });
        tmp5 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { tmp4 }, TNode<Uint32T> { parameter2 });
        tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp7 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { parameter0, tmp6 });
        tmp8 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp7 });
        tmp9 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp8 });
        ca_.Branch(tmp9, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        ca_.Goto(&block2);
    }

    TNode<IntPtrT> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<Object> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<Int32T> tmp20;
    TNode<IntPtrT> tmp21;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp10 = Convert_intptr_uint32_0(state_, TNode<Uint32T> { parameter2 });
        tmp11 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { tmp10 });
        tmp12 = FromConstexpr_intptr_constexpr_int32_0(state_, WasmArray::kHeaderSize);
        tmp13 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp12 }, TNode<IntPtrT> { tmp11 });
        tmp14 = CodeStubAssembler(state_).LoadStringLengthAsWord(TNode<String> { parameter0 });
        std::tie(tmp15, tmp16, tmp17)
            = NewMutableSlice_char16_0(state_, TNode<Object> { parameter1 }, TNode<IntPtrT> { tmp13 }, TNode<IntPtrT> { tmp14 }).Flatten();
        tmp18 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp20 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { parameter0, tmp19 });
        tmp21 = Convert_intptr_int32_0(state_, TNode<Int32T> { tmp20 });
        ca_.Goto(&block13, parameter0, tmp18);
    }

    TNode<String> phi_bb13_9;
    TNode<IntPtrT> phi_bb13_10;
    TNode<BoolT> tmp22;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_9, &phi_bb13_10);
        tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(
            tmp22, &block11, std::vector<compiler::Node*> { phi_bb13_9, phi_bb13_10 }, &block12, std::vector<compiler::Node*> { phi_bb13_9, phi_bb13_10 });
    }

    TNode<String> phi_bb11_9;
    TNode<IntPtrT> phi_bb11_10;
    TNode<SeqOneByteString> tmp23;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_9, &phi_bb11_10);
        compiler::CodeAssemblerLabel label24(&ca_);
        tmp23 = Cast_SeqOneByteString_1(state_, TNode<String> { phi_bb11_9 }, &label24);
        ca_.Goto(&block16, phi_bb11_9, phi_bb11_10, phi_bb11_9, phi_bb11_9);
        if (label24.is_used()) {
            ca_.Bind(&label24);
            ca_.Goto(&block17, phi_bb11_9, phi_bb11_10, phi_bb11_9, phi_bb11_9);
        }
    }

    TNode<String> phi_bb17_9;
    TNode<IntPtrT> phi_bb17_10;
    TNode<String> phi_bb17_12;
    TNode<String> phi_bb17_13;
    TNode<SeqTwoByteString> tmp25;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_9, &phi_bb17_10, &phi_bb17_12, &phi_bb17_13);
        compiler::CodeAssemblerLabel label26(&ca_);
        tmp25 = Cast_SeqTwoByteString_1(state_, TNode<String> { ca_.UncheckedCast<String>(phi_bb17_12) }, &label26);
        ca_.Goto(&block24, phi_bb17_9, phi_bb17_10, phi_bb17_12);
        if (label26.is_used()) {
            ca_.Bind(&label26);
            ca_.Goto(&block25, phi_bb17_9, phi_bb17_10, phi_bb17_12);
        }
    }

    TNode<String> phi_bb16_9;
    TNode<IntPtrT> phi_bb16_10;
    TNode<String> phi_bb16_12;
    TNode<String> phi_bb16_13;
    TNode<Object> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<Object> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<IntPtrT> tmp32;
    if (block16.is_used()) {
        ca_.Bind(&block16, &phi_bb16_9, &phi_bb16_10, &phi_bb16_12, &phi_bb16_13);
        std::tie(tmp27, tmp28, tmp29) = FieldSliceSeqOneByteStringChars_0(state_, TNode<SeqOneByteString> { tmp23 }).Flatten();
        compiler::CodeAssemblerLabel label33(&ca_);
        std::tie(tmp30, tmp31, tmp32) = Subslice_char8_0(state_,
            TorqueStructSlice_char8_ConstReference_char8_0 {
                TNode<Object> { tmp27 }, TNode<IntPtrT> { tmp28 }, TNode<IntPtrT> { tmp29 }, TorqueStructUnsafe_0 {} },
            TNode<IntPtrT> { phi_bb16_10 }, TNode<IntPtrT> { tmp21 }, &label33)
                                            .Flatten();
        ca_.Goto(&block20, phi_bb16_9, phi_bb16_10, phi_bb16_12, phi_bb16_10);
        if (label33.is_used()) {
            ca_.Bind(&label33);
            ca_.Goto(&block21, phi_bb16_9, phi_bb16_10, phi_bb16_12, phi_bb16_10);
        }
    }

    TNode<String> phi_bb21_9;
    TNode<IntPtrT> phi_bb21_10;
    TNode<String> phi_bb21_12;
    TNode<IntPtrT> phi_bb21_17;
    if (block21.is_used()) {
        ca_.Bind(&block21, &phi_bb21_9, &phi_bb21_10, &phi_bb21_12, &phi_bb21_17);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<String> phi_bb20_9;
    TNode<IntPtrT> phi_bb20_10;
    TNode<String> phi_bb20_12;
    TNode<IntPtrT> phi_bb20_17;
    if (block20.is_used()) {
        ca_.Bind(&block20, &phi_bb20_9, &phi_bb20_10, &phi_bb20_12, &phi_bb20_17);
        ca_.Goto(&block10, tmp30, tmp31, tmp32);
    }

    TNode<String> phi_bb25_9;
    TNode<IntPtrT> phi_bb25_10;
    TNode<String> phi_bb25_12;
    TNode<ThinString> tmp34;
    if (block25.is_used()) {
        ca_.Bind(&block25, &phi_bb25_9, &phi_bb25_10, &phi_bb25_12);
        compiler::CodeAssemblerLabel label35(&ca_);
        tmp34 = Cast_ThinString_1(state_, TNode<String> { ca_.UncheckedCast<String>(phi_bb25_12) }, &label35);
        ca_.Goto(&block32, phi_bb25_9, phi_bb25_10, phi_bb25_12);
        if (label35.is_used()) {
            ca_.Bind(&label35);
            ca_.Goto(&block33, phi_bb25_9, phi_bb25_10, phi_bb25_12);
        }
    }

    TNode<String> phi_bb24_9;
    TNode<IntPtrT> phi_bb24_10;
    TNode<String> phi_bb24_12;
    TNode<Object> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<Object> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    if (block24.is_used()) {
        ca_.Bind(&block24, &phi_bb24_9, &phi_bb24_10, &phi_bb24_12);
        std::tie(tmp36, tmp37, tmp38) = FieldSliceSeqTwoByteStringChars_0(state_, TNode<SeqTwoByteString> { tmp25 }).Flatten();
        compiler::CodeAssemblerLabel label42(&ca_);
        std::tie(tmp39, tmp40, tmp41) = Subslice_char16_0(state_,
            TorqueStructSlice_char16_ConstReference_char16_0 {
                TNode<Object> { tmp36 }, TNode<IntPtrT> { tmp37 }, TNode<IntPtrT> { tmp38 }, TorqueStructUnsafe_0 {} },
            TNode<IntPtrT> { phi_bb24_10 }, TNode<IntPtrT> { tmp21 }, &label42)
                                            .Flatten();
        ca_.Goto(&block28, phi_bb24_9, phi_bb24_10, phi_bb24_12, phi_bb24_10);
        if (label42.is_used()) {
            ca_.Bind(&label42);
            ca_.Goto(&block29, phi_bb24_9, phi_bb24_10, phi_bb24_12, phi_bb24_10);
        }
    }

    TNode<String> phi_bb29_9;
    TNode<IntPtrT> phi_bb29_10;
    TNode<String> phi_bb29_12;
    TNode<IntPtrT> phi_bb29_17;
    if (block29.is_used()) {
        ca_.Bind(&block29, &phi_bb29_9, &phi_bb29_10, &phi_bb29_12, &phi_bb29_17);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<String> phi_bb28_9;
    TNode<IntPtrT> phi_bb28_10;
    TNode<String> phi_bb28_12;
    TNode<IntPtrT> phi_bb28_17;
    if (block28.is_used()) {
        ca_.Bind(&block28, &phi_bb28_9, &phi_bb28_10, &phi_bb28_12, &phi_bb28_17);
        ca_.Goto(&block8, tmp39, tmp40, tmp41);
    }

    TNode<String> phi_bb33_9;
    TNode<IntPtrT> phi_bb33_10;
    TNode<String> phi_bb33_12;
    TNode<ConsString> tmp43;
    if (block33.is_used()) {
        ca_.Bind(&block33, &phi_bb33_9, &phi_bb33_10, &phi_bb33_12);
        compiler::CodeAssemblerLabel label44(&ca_);
        tmp43 = Cast_ConsString_1(state_, TNode<String> { ca_.UncheckedCast<String>(phi_bb33_12) }, &label44);
        ca_.Goto(&block36, phi_bb33_9, phi_bb33_10, phi_bb33_12);
        if (label44.is_used()) {
            ca_.Bind(&label44);
            ca_.Goto(&block37, phi_bb33_9, phi_bb33_10, phi_bb33_12);
        }
    }

    TNode<String> phi_bb32_9;
    TNode<IntPtrT> phi_bb32_10;
    TNode<String> phi_bb32_12;
    TNode<IntPtrT> tmp45;
    TNode<String> tmp46;
    if (block32.is_used()) {
        ca_.Bind(&block32, &phi_bb32_9, &phi_bb32_10, &phi_bb32_12);
        tmp45 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp46 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference { tmp34, tmp45 });
        ca_.Goto(&block30, tmp46, phi_bb32_10, phi_bb32_12);
    }

    TNode<String> phi_bb37_9;
    TNode<IntPtrT> phi_bb37_10;
    TNode<String> phi_bb37_12;
    TNode<SlicedString> tmp47;
    if (block37.is_used()) {
        ca_.Bind(&block37, &phi_bb37_9, &phi_bb37_10, &phi_bb37_12);
        compiler::CodeAssemblerLabel label48(&ca_);
        tmp47 = Cast_SlicedString_1(state_, TNode<String> { ca_.UncheckedCast<String>(phi_bb37_12) }, &label48);
        ca_.Goto(&block40, phi_bb37_9, phi_bb37_10, phi_bb37_12);
        if (label48.is_used()) {
            ca_.Bind(&label48);
            ca_.Goto(&block41, phi_bb37_9, phi_bb37_10, phi_bb37_12);
        }
    }

    TNode<String> phi_bb36_9;
    TNode<IntPtrT> phi_bb36_10;
    TNode<String> phi_bb36_12;
    TNode<String> tmp49;
    if (block36.is_used()) {
        ca_.Bind(&block36, &phi_bb36_9, &phi_bb36_10, &phi_bb36_12);
        tmp49 = Flatten_1(state_, TNode<ConsString> { tmp43 });
        ca_.Goto(&block34, tmp49, phi_bb36_10, phi_bb36_12);
    }

    TNode<String> phi_bb41_9;
    TNode<IntPtrT> phi_bb41_10;
    TNode<String> phi_bb41_12;
    TNode<ExternalOneByteString> tmp50;
    if (block41.is_used()) {
        ca_.Bind(&block41, &phi_bb41_9, &phi_bb41_10, &phi_bb41_12);
        compiler::CodeAssemblerLabel label51(&ca_);
        tmp50 = Cast_ExternalOneByteString_1(state_, TNode<String> { ca_.UncheckedCast<String>(phi_bb41_12) }, &label51);
        ca_.Goto(&block44, phi_bb41_9, phi_bb41_10, phi_bb41_12);
        if (label51.is_used()) {
            ca_.Bind(&label51);
            ca_.Goto(&block45, phi_bb41_9, phi_bb41_10, phi_bb41_12);
        }
    }

    TNode<String> phi_bb40_9;
    TNode<IntPtrT> phi_bb40_10;
    TNode<String> phi_bb40_12;
    TNode<IntPtrT> tmp52;
    TNode<Smi> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<String> tmp57;
    if (block40.is_used()) {
        ca_.Bind(&block40, &phi_bb40_9, &phi_bb40_10, &phi_bb40_12);
        tmp52 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp53 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp47, tmp52 });
        tmp54 = Convert_intptr_Smi_0(state_, TNode<Smi> { tmp53 });
        tmp55 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb40_10 }, TNode<IntPtrT> { tmp54 });
        tmp56 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp57 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference { tmp47, tmp56 });
        ca_.Goto(&block34, tmp57, tmp55, phi_bb40_12);
    }

    TNode<String> phi_bb45_9;
    TNode<IntPtrT> phi_bb45_10;
    TNode<String> phi_bb45_12;
    TNode<ExternalTwoByteString> tmp58;
    if (block45.is_used()) {
        ca_.Bind(&block45, &phi_bb45_9, &phi_bb45_10, &phi_bb45_12);
        compiler::CodeAssemblerLabel label59(&ca_);
        tmp58 = Cast_ExternalTwoByteString_1(state_, TNode<String> { ca_.UncheckedCast<String>(phi_bb45_12) }, &label59);
        ca_.Goto(&block52, phi_bb45_9, phi_bb45_10, phi_bb45_12);
        if (label59.is_used()) {
            ca_.Bind(&label59);
            ca_.Goto(&block53, phi_bb45_9, phi_bb45_10, phi_bb45_12);
        }
    }

    TNode<String> phi_bb44_9;
    TNode<IntPtrT> phi_bb44_10;
    TNode<String> phi_bb44_12;
    TNode<RawPtrT> tmp60;
    TNode<IntPtrT> tmp61;
    TNode<Int32T> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<Object> tmp64;
    TNode<IntPtrT> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<Object> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<IntPtrT> tmp69;
    if (block44.is_used()) {
        ca_.Bind(&block44, &phi_bb44_9, &phi_bb44_10, &phi_bb44_12);
        tmp60 = Method_ExternalOneByteString_GetChars_0(state_, TNode<ExternalOneByteString> { tmp50 });
        tmp61 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp62 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp50, tmp61 });
        tmp63 = Convert_intptr_int32_0(state_, TNode<Int32T> { tmp62 });
        std::tie(tmp64, tmp65, tmp66) = NewOffHeapConstSlice_char8_0(state_, TNode<RawPtrT> { tmp60 }, TNode<IntPtrT> { tmp63 }).Flatten();
        compiler::CodeAssemblerLabel label70(&ca_);
        std::tie(tmp67, tmp68, tmp69) = Subslice_char8_0(state_,
            TorqueStructSlice_char8_ConstReference_char8_0 {
                TNode<Object> { tmp64 }, TNode<IntPtrT> { tmp65 }, TNode<IntPtrT> { tmp66 }, TorqueStructUnsafe_0 {} },
            TNode<IntPtrT> { phi_bb44_10 }, TNode<IntPtrT> { tmp21 }, &label70)
                                            .Flatten();
        ca_.Goto(&block48, phi_bb44_9, phi_bb44_10, phi_bb44_12, phi_bb44_10);
        if (label70.is_used()) {
            ca_.Bind(&label70);
            ca_.Goto(&block49, phi_bb44_9, phi_bb44_10, phi_bb44_12, phi_bb44_10);
        }
    }

    TNode<String> phi_bb49_9;
    TNode<IntPtrT> phi_bb49_10;
    TNode<String> phi_bb49_12;
    TNode<IntPtrT> phi_bb49_20;
    if (block49.is_used()) {
        ca_.Bind(&block49, &phi_bb49_9, &phi_bb49_10, &phi_bb49_12, &phi_bb49_20);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<String> phi_bb48_9;
    TNode<IntPtrT> phi_bb48_10;
    TNode<String> phi_bb48_12;
    TNode<IntPtrT> phi_bb48_20;
    if (block48.is_used()) {
        ca_.Bind(&block48, &phi_bb48_9, &phi_bb48_10, &phi_bb48_12, &phi_bb48_20);
        ca_.Goto(&block10, tmp67, tmp68, tmp69);
    }

    TNode<String> phi_bb53_9;
    TNode<IntPtrT> phi_bb53_10;
    TNode<String> phi_bb53_12;
    if (block53.is_used()) {
        ca_.Bind(&block53, &phi_bb53_9, &phi_bb53_10, &phi_bb53_12);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<String> phi_bb52_9;
    TNode<IntPtrT> phi_bb52_10;
    TNode<String> phi_bb52_12;
    TNode<RawPtrT> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<Int32T> tmp73;
    TNode<IntPtrT> tmp74;
    TNode<Object> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<Object> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<IntPtrT> tmp80;
    if (block52.is_used()) {
        ca_.Bind(&block52, &phi_bb52_9, &phi_bb52_10, &phi_bb52_12);
        tmp71 = Method_ExternalTwoByteString_GetChars_0(state_, TNode<ExternalTwoByteString> { tmp58 });
        tmp72 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp73 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp58, tmp72 });
        tmp74 = Convert_intptr_int32_0(state_, TNode<Int32T> { tmp73 });
        std::tie(tmp75, tmp76, tmp77) = NewOffHeapConstSlice_char16_0(state_, TNode<RawPtrT> { tmp71 }, TNode<IntPtrT> { tmp74 }).Flatten();
        compiler::CodeAssemblerLabel label81(&ca_);
        std::tie(tmp78, tmp79, tmp80) = Subslice_char16_0(state_,
            TorqueStructSlice_char16_ConstReference_char16_0 {
                TNode<Object> { tmp75 }, TNode<IntPtrT> { tmp76 }, TNode<IntPtrT> { tmp77 }, TorqueStructUnsafe_0 {} },
            TNode<IntPtrT> { phi_bb52_10 }, TNode<IntPtrT> { tmp21 }, &label81)
                                            .Flatten();
        ca_.Goto(&block56, phi_bb52_9, phi_bb52_10, phi_bb52_12, phi_bb52_10);
        if (label81.is_used()) {
            ca_.Bind(&label81);
            ca_.Goto(&block57, phi_bb52_9, phi_bb52_10, phi_bb52_12, phi_bb52_10);
        }
    }

    TNode<String> phi_bb57_9;
    TNode<IntPtrT> phi_bb57_10;
    TNode<String> phi_bb57_12;
    TNode<IntPtrT> phi_bb57_20;
    if (block57.is_used()) {
        ca_.Bind(&block57, &phi_bb57_9, &phi_bb57_10, &phi_bb57_12, &phi_bb57_20);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<String> phi_bb56_9;
    TNode<IntPtrT> phi_bb56_10;
    TNode<String> phi_bb56_12;
    TNode<IntPtrT> phi_bb56_20;
    if (block56.is_used()) {
        ca_.Bind(&block56, &phi_bb56_9, &phi_bb56_10, &phi_bb56_12, &phi_bb56_20);
        ca_.Goto(&block8, tmp78, tmp79, tmp80);
    }

    TNode<String> phi_bb34_9;
    TNode<IntPtrT> phi_bb34_10;
    TNode<String> phi_bb34_12;
    if (block34.is_used()) {
        ca_.Bind(&block34, &phi_bb34_9, &phi_bb34_10, &phi_bb34_12);
        ca_.Goto(&block30, phi_bb34_9, phi_bb34_10, phi_bb34_12);
    }

    TNode<String> phi_bb30_9;
    TNode<IntPtrT> phi_bb30_10;
    TNode<String> phi_bb30_12;
    if (block30.is_used()) {
        ca_.Bind(&block30, &phi_bb30_9, &phi_bb30_10, &phi_bb30_12);
        ca_.Goto(&block13, phi_bb30_9, phi_bb30_10);
    }

    TNode<String> phi_bb12_9;
    TNode<IntPtrT> phi_bb12_10;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_9, &phi_bb12_10);
        VerifiedUnreachable_0(state_);
    }

    TNode<Object> phi_bb10_7;
    TNode<IntPtrT> phi_bb10_8;
    TNode<IntPtrT> phi_bb10_9;
    TNode<IntPtrT> tmp82;
    TNode<IntPtrT> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<IntPtrT> tmp85;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_7, &phi_bb10_8, &phi_bb10_9);
        tmp82 = TimesSizeOf_char8_0(state_, TNode<IntPtrT> { phi_bb10_9 });
        tmp83 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb10_8 }, TNode<IntPtrT> { tmp82 });
        tmp84 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { tmp17 });
        tmp85 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp16 }, TNode<IntPtrT> { tmp84 });
        ca_.Goto(&block62, phi_bb10_7, phi_bb10_8, phi_bb10_9, phi_bb10_7, phi_bb10_8, tmp16);
    }

    TNode<Object> phi_bb62_7;
    TNode<IntPtrT> phi_bb62_8;
    TNode<IntPtrT> phi_bb62_9;
    TNode<Object> phi_bb62_10;
    TNode<IntPtrT> phi_bb62_11;
    TNode<IntPtrT> phi_bb62_14;
    TNode<BoolT> tmp86;
    if (block62.is_used()) {
        ca_.Bind(&block62, &phi_bb62_7, &phi_bb62_8, &phi_bb62_9, &phi_bb62_10, &phi_bb62_11, &phi_bb62_14);
        tmp86 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp86, &block60, std::vector<compiler::Node*> { phi_bb62_7, phi_bb62_8, phi_bb62_9, phi_bb62_10, phi_bb62_11, phi_bb62_14 }, &block61,
            std::vector<compiler::Node*> { phi_bb62_7, phi_bb62_8, phi_bb62_9, phi_bb62_10, phi_bb62_11, phi_bb62_14 });
    }

    TNode<Object> phi_bb60_7;
    TNode<IntPtrT> phi_bb60_8;
    TNode<IntPtrT> phi_bb60_9;
    TNode<Object> phi_bb60_10;
    TNode<IntPtrT> phi_bb60_11;
    TNode<IntPtrT> phi_bb60_14;
    TNode<BoolT> tmp87;
    if (block60.is_used()) {
        ca_.Bind(&block60, &phi_bb60_7, &phi_bb60_8, &phi_bb60_9, &phi_bb60_10, &phi_bb60_11, &phi_bb60_14);
        tmp87 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT> { phi_bb60_14 }, TNode<IntPtrT> { tmp85 });
        ca_.Branch(tmp87, &block66, std::vector<compiler::Node*> { phi_bb60_7, phi_bb60_8, phi_bb60_9, phi_bb60_10, phi_bb60_11, phi_bb60_14 }, &block67,
            std::vector<compiler::Node*> { phi_bb60_7, phi_bb60_8, phi_bb60_9, phi_bb60_10, phi_bb60_11, phi_bb60_14 });
    }

    TNode<Object> phi_bb66_7;
    TNode<IntPtrT> phi_bb66_8;
    TNode<IntPtrT> phi_bb66_9;
    TNode<Object> phi_bb66_10;
    TNode<IntPtrT> phi_bb66_11;
    TNode<IntPtrT> phi_bb66_14;
    if (block66.is_used()) {
        ca_.Bind(&block66, &phi_bb66_7, &phi_bb66_8, &phi_bb66_9, &phi_bb66_10, &phi_bb66_11, &phi_bb66_14);
        ca_.Goto(&block61, phi_bb66_7, phi_bb66_8, phi_bb66_9, phi_bb66_10, phi_bb66_11, phi_bb66_14);
    }

    TNode<Object> phi_bb67_7;
    TNode<IntPtrT> phi_bb67_8;
    TNode<IntPtrT> phi_bb67_9;
    TNode<Object> phi_bb67_10;
    TNode<IntPtrT> phi_bb67_11;
    TNode<IntPtrT> phi_bb67_14;
    TNode<Object> tmp88;
    TNode<IntPtrT> tmp89;
    TNode<IntPtrT> tmp90;
    TNode<IntPtrT> tmp91;
    TNode<Object> tmp92;
    TNode<IntPtrT> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<IntPtrT> tmp95;
    TNode<Uint8T> tmp96;
    TNode<Uint16T> tmp97;
    TNode<Uint16T> tmp98;
    if (block67.is_used()) {
        ca_.Bind(&block67, &phi_bb67_7, &phi_bb67_8, &phi_bb67_9, &phi_bb67_10, &phi_bb67_11, &phi_bb67_14);
        std::tie(tmp88, tmp89) = NewReference_char16_0(state_, TNode<Object> { tmp15 }, TNode<IntPtrT> { phi_bb67_14 }).Flatten();
        tmp90 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt16Size);
        tmp91 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb67_14 }, TNode<IntPtrT> { tmp90 });
        std::tie(tmp92, tmp93) = NewReference_char8_0(state_, TNode<Object> { phi_bb67_10 }, TNode<IntPtrT> { phi_bb67_11 }).Flatten();
        tmp94 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
        tmp95 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb67_11 }, TNode<IntPtrT> { tmp94 });
        tmp96 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference { tmp92, tmp93 });
        tmp97 = Convert_uint16_char8_0(state_, TNode<Uint8T> { tmp96 });
        tmp98 = (TNode<Uint16T> { tmp97 });
        CodeStubAssembler(state_).StoreReference<Uint16T>(CodeStubAssembler::Reference { tmp88, tmp89 }, tmp98);
        ca_.Goto(&block62, phi_bb67_7, phi_bb67_8, phi_bb67_9, phi_bb67_10, tmp95, tmp91);
    }

    TNode<Object> phi_bb61_7;
    TNode<IntPtrT> phi_bb61_8;
    TNode<IntPtrT> phi_bb61_9;
    TNode<Object> phi_bb61_10;
    TNode<IntPtrT> phi_bb61_11;
    TNode<IntPtrT> phi_bb61_14;
    if (block61.is_used()) {
        ca_.Bind(&block61, &phi_bb61_7, &phi_bb61_8, &phi_bb61_9, &phi_bb61_10, &phi_bb61_11, &phi_bb61_14);
        ca_.Goto(&block7);
    }

    TNode<Object> phi_bb8_7;
    TNode<IntPtrT> phi_bb8_8;
    TNode<IntPtrT> phi_bb8_9;
    TNode<IntPtrT> tmp99;
    TNode<IntPtrT> tmp100;
    TNode<IntPtrT> tmp101;
    TNode<IntPtrT> tmp102;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_7, &phi_bb8_8, &phi_bb8_9);
        tmp99 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { phi_bb8_9 });
        tmp100 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb8_8 }, TNode<IntPtrT> { tmp99 });
        tmp101 = TimesSizeOf_char16_0(state_, TNode<IntPtrT> { tmp17 });
        tmp102 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp16 }, TNode<IntPtrT> { tmp101 });
        ca_.Goto(&block81, phi_bb8_7, phi_bb8_8, phi_bb8_9, phi_bb8_7, phi_bb8_8, tmp16);
    }

    TNode<Object> phi_bb81_7;
    TNode<IntPtrT> phi_bb81_8;
    TNode<IntPtrT> phi_bb81_9;
    TNode<Object> phi_bb81_10;
    TNode<IntPtrT> phi_bb81_11;
    TNode<IntPtrT> phi_bb81_14;
    TNode<BoolT> tmp103;
    if (block81.is_used()) {
        ca_.Bind(&block81, &phi_bb81_7, &phi_bb81_8, &phi_bb81_9, &phi_bb81_10, &phi_bb81_11, &phi_bb81_14);
        tmp103 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp103, &block79, std::vector<compiler::Node*> { phi_bb81_7, phi_bb81_8, phi_bb81_9, phi_bb81_10, phi_bb81_11, phi_bb81_14 }, &block80,
            std::vector<compiler::Node*> { phi_bb81_7, phi_bb81_8, phi_bb81_9, phi_bb81_10, phi_bb81_11, phi_bb81_14 });
    }

    TNode<Object> phi_bb79_7;
    TNode<IntPtrT> phi_bb79_8;
    TNode<IntPtrT> phi_bb79_9;
    TNode<Object> phi_bb79_10;
    TNode<IntPtrT> phi_bb79_11;
    TNode<IntPtrT> phi_bb79_14;
    TNode<BoolT> tmp104;
    if (block79.is_used()) {
        ca_.Bind(&block79, &phi_bb79_7, &phi_bb79_8, &phi_bb79_9, &phi_bb79_10, &phi_bb79_11, &phi_bb79_14);
        tmp104 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT> { phi_bb79_14 }, TNode<IntPtrT> { tmp102 });
        ca_.Branch(tmp104, &block85, std::vector<compiler::Node*> { phi_bb79_7, phi_bb79_8, phi_bb79_9, phi_bb79_10, phi_bb79_11, phi_bb79_14 }, &block86,
            std::vector<compiler::Node*> { phi_bb79_7, phi_bb79_8, phi_bb79_9, phi_bb79_10, phi_bb79_11, phi_bb79_14 });
    }

    TNode<Object> phi_bb85_7;
    TNode<IntPtrT> phi_bb85_8;
    TNode<IntPtrT> phi_bb85_9;
    TNode<Object> phi_bb85_10;
    TNode<IntPtrT> phi_bb85_11;
    TNode<IntPtrT> phi_bb85_14;
    if (block85.is_used()) {
        ca_.Bind(&block85, &phi_bb85_7, &phi_bb85_8, &phi_bb85_9, &phi_bb85_10, &phi_bb85_11, &phi_bb85_14);
        ca_.Goto(&block80, phi_bb85_7, phi_bb85_8, phi_bb85_9, phi_bb85_10, phi_bb85_11, phi_bb85_14);
    }

    TNode<Object> phi_bb86_7;
    TNode<IntPtrT> phi_bb86_8;
    TNode<IntPtrT> phi_bb86_9;
    TNode<Object> phi_bb86_10;
    TNode<IntPtrT> phi_bb86_11;
    TNode<IntPtrT> phi_bb86_14;
    TNode<Object> tmp105;
    TNode<IntPtrT> tmp106;
    TNode<IntPtrT> tmp107;
    TNode<IntPtrT> tmp108;
    TNode<Object> tmp109;
    TNode<IntPtrT> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<IntPtrT> tmp112;
    TNode<Uint16T> tmp113;
    if (block86.is_used()) {
        ca_.Bind(&block86, &phi_bb86_7, &phi_bb86_8, &phi_bb86_9, &phi_bb86_10, &phi_bb86_11, &phi_bb86_14);
        std::tie(tmp105, tmp106) = NewReference_char16_0(state_, TNode<Object> { tmp15 }, TNode<IntPtrT> { phi_bb86_14 }).Flatten();
        tmp107 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt16Size);
        tmp108 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb86_14 }, TNode<IntPtrT> { tmp107 });
        std::tie(tmp109, tmp110) = NewReference_char16_0(state_, TNode<Object> { phi_bb86_10 }, TNode<IntPtrT> { phi_bb86_11 }).Flatten();
        tmp111 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt16Size);
        tmp112 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb86_11 }, TNode<IntPtrT> { tmp111 });
        tmp113 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference { tmp109, tmp110 });
        CodeStubAssembler(state_).StoreReference<Uint16T>(CodeStubAssembler::Reference { tmp105, tmp106 }, tmp113);
        ca_.Goto(&block81, phi_bb86_7, phi_bb86_8, phi_bb86_9, phi_bb86_10, tmp112, tmp108);
    }

    TNode<Object> phi_bb80_7;
    TNode<IntPtrT> phi_bb80_8;
    TNode<IntPtrT> phi_bb80_9;
    TNode<Object> phi_bb80_10;
    TNode<IntPtrT> phi_bb80_11;
    TNode<IntPtrT> phi_bb80_14;
    if (block80.is_used()) {
        ca_.Bind(&block80, &phi_bb80_7, &phi_bb80_8, &phi_bb80_9, &phi_bb80_10, &phi_bb80_11, &phi_bb80_14);
        ca_.Goto(&block7);
    }

    TNode<IntPtrT> tmp114;
    TNode<Int32T> tmp115;
    TNode<Uint32T> tmp116;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp114 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp115 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { parameter0, tmp114 });
        tmp116 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp115 });
        CodeStubAssembler(state_).Return(tmp116);
    }

    TNode<NativeContext> tmp117;
    TNode<Smi> tmp118;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp117 = WasmBuiltinsAssembler(state_).LoadContextFromWasmOrJsFrame();
        tmp118 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapArrayOutOfBounds);
        CodeStubAssembler(state_).CallRuntime(Runtime::kThrowWasmError, tmp117, tmp118);
        CodeStubAssembler(state_).Unreachable();
    }
}

TF_BUILTIN(ThrowToLowerCaseCalledOnNull, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    TNode<String> tmp1;
    TNode<Smi> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        tmp1 = CodeStubAssembler(state_).StringConstant("String.prototype.toLowerCase");
        tmp2 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kCalledOnNullOrUndefined);
        CodeStubAssembler(state_).CallRuntime(Runtime::kWasmThrowTypeError, tmp0, tmp2, tmp1);
        CodeStubAssembler(state_).Unreachable();
    }
}

TF_BUILTIN(ThrowIndexOfCalledOnNull, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    TNode<String> tmp1;
    TNode<Smi> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        tmp1 = CodeStubAssembler(state_).StringConstant("String.prototype.indexOf");
        tmp2 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kCalledOnNullOrUndefined);
        CodeStubAssembler(state_).CallRuntime(Runtime::kWasmThrowTypeError, tmp0, tmp2, tmp1);
        CodeStubAssembler(state_).Unreachable();
    }
}

TF_BUILTIN(ThrowDataViewTypeError, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Object> parameter0 = UncheckedParameter<Object>(Descriptor::kValue);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        tmp1 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kIncompatibleMethodReceiver);
        CodeStubAssembler(state_).CallRuntime(Runtime::kWasmThrowDataViewTypeError, tmp0, tmp1, parameter0);
        CodeStubAssembler(state_).Unreachable();
    }
}

TF_BUILTIN(ThrowDataViewDetachedError, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        tmp1 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kDetachedOperation);
        CodeStubAssembler(state_).CallRuntime(Runtime::kWasmThrowDataViewDetachedError, tmp0, tmp1);
        CodeStubAssembler(state_).Unreachable();
    }
}

TF_BUILTIN(ThrowDataViewOutOfBounds, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    TNode<Smi> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        tmp1 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kInvalidDataViewAccessorOffset);
        CodeStubAssembler(state_).CallRuntime(Runtime::kWasmThrowRangeError, tmp0, tmp1);
        CodeStubAssembler(state_).Unreachable();
    }
}

TF_BUILTIN(WasmStringConcat, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kA);
    USE(parameter0);
    TNode<String> parameter1 = UncheckedParameter<String>(Descriptor::kB);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        CodeStubAssembler(state_).TailCallBuiltin(Builtin::kStringAdd_CheckNone, tmp0, parameter0, parameter1);
    }
}

TF_BUILTIN(WasmStringEqual, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kA);
    USE(parameter0);
    TNode<String> parameter1 = UncheckedParameter<String>(Descriptor::kB);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BoolT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject> { parameter0 }, TNode<MaybeObject> { parameter1 });
        ca_.Branch(tmp0, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<Int32T> tmp1;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp1 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        CodeStubAssembler(state_).Return(tmp1);
    }

    TNode<IntPtrT> tmp2;
    TNode<Int32T> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Int32T> tmp5;
    TNode<BoolT> tmp6;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp3 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { parameter0, tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { parameter1, tmp4 });
        tmp6 = CodeStubAssembler(state_).Word32NotEqual(TNode<Int32T> { tmp3 }, TNode<Int32T> { tmp5 });
        ca_.Branch(tmp6, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    TNode<Int32T> tmp7;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp7 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        CodeStubAssembler(state_).Return(tmp7);
    }

    TNode<Smi> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Boolean> tmp10;
    TNode<True> tmp11;
    TNode<BoolT> tmp12;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp8 = kNoContext_0(state_);
        tmp9 = CodeStubAssembler(state_).LoadStringLengthAsWord(TNode<String> { parameter0 });
        tmp10 = ca_.CallBuiltin<Boolean>(Builtin::kStringEqual, tmp8, parameter0, parameter1, tmp9);
        tmp11 = True_0(state_);
        tmp12 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject> { tmp10 }, TNode<HeapObject> { tmp11 });
        ca_.Branch(tmp12, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    TNode<Int32T> tmp13;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp13 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        CodeStubAssembler(state_).Return(tmp13);
    }

    TNode<Int32T> tmp14;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp14 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        CodeStubAssembler(state_).Return(tmp14);
    }
}

TF_BUILTIN(WasmStringIsUSVSequence, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kStr);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint16T> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).LoadInstanceType(TNode<HeapObject> { parameter0 });
        tmp1 = CodeStubAssembler(state_).IsOneByteStringInstanceType(TNode<Uint16T> { tmp0 });
        ca_.Branch(tmp1, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<Int32T> tmp2;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp2 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        CodeStubAssembler(state_).Return(tmp2);
    }

    TNode<NativeContext> tmp3;
    TNode<Number> tmp4;
    TNode<Int32T> tmp5;
    TNode<Int32T> tmp6;
    TNode<BoolT> tmp7;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp3 = LoadContextFromFrame_0(state_);
        tmp4 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringMeasureUtf8, tmp3, parameter0));
        tmp5 = NumberToInt32_0(state_, TNode<Number> { tmp4 });
        tmp6 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp7 = CodeStubAssembler(state_).Int32LessThan(TNode<Int32T> { tmp5 }, TNode<Int32T> { tmp6 });
        ca_.Branch(tmp7, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    TNode<Int32T> tmp8;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp8 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        CodeStubAssembler(state_).Return(tmp8);
    }

    TNode<Int32T> tmp9;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp9 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        CodeStubAssembler(state_).Return(tmp9);
    }
}

TF_BUILTIN(WasmStringAsWtf8, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kStr);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringAsWtf8, tmp0, parameter0);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1227&c=1
TNode<BoolT> IsWtf8CodepointStart_0(compiler::CodeAssemblerState* state_, TNode<ByteArray> p_view, TNode<Uint32T> p_pos)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<UintPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<UintPtrT> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<BoolT> tmp7;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1, tmp2) = FieldSliceByteArrayValues_0(state_, TNode<ByteArray> { p_view }).Flatten();
        tmp3 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { p_pos });
        tmp4 = Convert_intptr_uintptr_0(state_, TNode<UintPtrT> { tmp3 });
        tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp4 });
        tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT> { tmp2 });
        tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp5 }, TNode<UintPtrT> { tmp6 });
        ca_.Branch(tmp7, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<Object> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<Uint8T> tmp12;
    TNode<Uint32T> tmp13;
    TNode<Uint32T> tmp14;
    TNode<Uint32T> tmp15;
    TNode<BoolT> tmp16;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp8 = TimesSizeOf_uint8_0(state_, TNode<IntPtrT> { tmp4 });
        tmp9 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp1 }, TNode<IntPtrT> { tmp8 });
        std::tie(tmp10, tmp11) = NewReference_uint8_0(state_, TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp9 }).Flatten();
        tmp12 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference { tmp10, tmp11 });
        tmp13 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xc0ull));
        tmp14 = CodeStubAssembler(state_).Word32And(TNode<Uint32T> { tmp12 }, TNode<Uint32T> { tmp13 });
        tmp15 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x80ull));
        tmp16 = CodeStubAssembler(state_).Word32NotEqual(TNode<Uint32T> { tmp14 }, TNode<Uint32T> { tmp15 });
        ca_.Goto(&block10);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        CodeStubAssembler(state_).Unreachable();
    }

    ca_.Bind(&block10);
    return TNode<BoolT> { tmp16 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1232&c=1
TNode<Uint32T> AlignWtf8PositionForward_0(compiler::CodeAssemblerState* state_, TNode<ByteArray> p_view, TNode<Uint32T> p_pos)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    TNode<Int32T> tmp2;
    TNode<Uint32T> tmp3;
    TNode<BoolT> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { p_view, tmp0 });
        tmp2 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { tmp1 });
        tmp3 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp2 });
        tmp4 = CodeStubAssembler(state_).Uint32GreaterThanOrEqual(TNode<Uint32T> { p_pos }, TNode<Uint32T> { tmp3 });
        ca_.Branch(tmp4, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    if (block2.is_used()) {
        ca_.Bind(&block2);
        ca_.Goto(&block1, tmp3);
    }

    TNode<BoolT> tmp5;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp5 = IsWtf8CodepointStart_0(state_, TNode<ByteArray> { p_view }, TNode<Uint32T> { p_pos });
        ca_.Branch(tmp5, &block4, std::vector<compiler::Node*> {}, &block5, std::vector<compiler::Node*> {});
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(&block1, p_pos);
    }

    TNode<Uint32T> tmp6;
    TNode<Uint32T> tmp7;
    TNode<BoolT> tmp8;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp6 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp7 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { p_pos }, TNode<Uint32T> { tmp6 });
        tmp8 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { tmp7 }, TNode<Uint32T> { tmp3 });
        ca_.Branch(tmp8, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block1, tmp3);
    }

    TNode<Uint32T> tmp9;
    TNode<Uint32T> tmp10;
    TNode<BoolT> tmp11;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp9 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp10 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { p_pos }, TNode<Uint32T> { tmp9 });
        tmp11 = IsWtf8CodepointStart_0(state_, TNode<ByteArray> { p_view }, TNode<Uint32T> { tmp10 });
        ca_.Branch(tmp11, &block8, std::vector<compiler::Node*> {}, &block9, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp12;
    TNode<Uint32T> tmp13;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp12 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp13 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { p_pos }, TNode<Uint32T> { tmp12 });
        ca_.Goto(&block1, tmp13);
    }

    TNode<Uint32T> tmp14;
    TNode<Uint32T> tmp15;
    TNode<BoolT> tmp16;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp14 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp15 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { p_pos }, TNode<Uint32T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { tmp15 }, TNode<Uint32T> { tmp3 });
        ca_.Branch(tmp16, &block10, std::vector<compiler::Node*> {}, &block11, std::vector<compiler::Node*> {});
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block1, tmp3);
    }

    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp17 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp18 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { p_pos }, TNode<Uint32T> { tmp17 });
        tmp19 = IsWtf8CodepointStart_0(state_, TNode<ByteArray> { p_view }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block12, std::vector<compiler::Node*> {}, &block13, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp20;
    TNode<Uint32T> tmp21;
    if (block12.is_used()) {
        ca_.Bind(&block12);
        tmp20 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp21 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { p_pos }, TNode<Uint32T> { tmp20 });
        ca_.Goto(&block1, tmp21);
    }

    TNode<Uint32T> tmp22;
    TNode<Uint32T> tmp23;
    if (block13.is_used()) {
        ca_.Bind(&block13);
        tmp22 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x3ull));
        tmp23 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { p_pos }, TNode<Uint32T> { tmp22 });
        ca_.Goto(&block1, tmp23);
    }

    TNode<Uint32T> phi_bb1_2;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_2);
        ca_.Goto(&block14, phi_bb1_2);
    }

    TNode<Uint32T> phi_bb14_2;
    ca_.Bind(&block14, &phi_bb14_2);
    return TNode<Uint32T> { phi_bb14_2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1249&c=1
TNode<Uint32T> AlignWtf8PositionBackward_0(compiler::CodeAssemblerState* state_, TNode<ByteArray> p_view, TNode<Uint32T> p_pos)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BoolT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = IsWtf8CodepointStart_0(state_, TNode<ByteArray> { p_view }, TNode<Uint32T> { p_pos });
        ca_.Branch(tmp0, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    if (block2.is_used()) {
        ca_.Bind(&block2);
        ca_.Goto(&block1, p_pos);
    }

    TNode<Uint32T> tmp1;
    TNode<Uint32T> tmp2;
    TNode<BoolT> tmp3;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp1 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp2 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { p_pos }, TNode<Uint32T> { tmp1 });
        tmp3 = IsWtf8CodepointStart_0(state_, TNode<ByteArray> { p_view }, TNode<Uint32T> { tmp2 });
        ca_.Branch(tmp3, &block4, std::vector<compiler::Node*> {}, &block5, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp4;
    TNode<Uint32T> tmp5;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp4 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp5 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { p_pos }, TNode<Uint32T> { tmp4 });
        ca_.Goto(&block1, tmp5);
    }

    TNode<Uint32T> tmp6;
    TNode<Uint32T> tmp7;
    TNode<BoolT> tmp8;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp6 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp7 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { p_pos }, TNode<Uint32T> { tmp6 });
        tmp8 = IsWtf8CodepointStart_0(state_, TNode<ByteArray> { p_view }, TNode<Uint32T> { tmp7 });
        ca_.Branch(tmp8, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp9;
    TNode<Uint32T> tmp10;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp9 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp10 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { p_pos }, TNode<Uint32T> { tmp9 });
        ca_.Goto(&block1, tmp10);
    }

    TNode<Uint32T> tmp11;
    TNode<Uint32T> tmp12;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp11 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x3ull));
        tmp12 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { p_pos }, TNode<Uint32T> { tmp11 });
        ca_.Goto(&block1, tmp12);
    }

    TNode<Uint32T> phi_bb1_2;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_2);
        ca_.Goto(&block8, phi_bb1_2);
    }

    TNode<Uint32T> phi_bb8_2;
    ca_.Bind(&block8, &phi_bb8_2);
    return TNode<Uint32T> { phi_bb8_2 };
}

TF_BUILTIN(WasmStringViewWtf8Advance, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<ByteArray> parameter0 = UncheckedParameter<ByteArray>(Descriptor::kView);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kPos);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kBytes);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    TNode<BoolT> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = AlignWtf8PositionForward_0(state_, TNode<ByteArray> { parameter0 }, TNode<Uint32T> { parameter1 });
        tmp1 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp2 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { parameter2 }, TNode<Uint32T> { tmp1 });
        ca_.Branch(tmp2, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        CodeStubAssembler(state_).Return(tmp0);
    }

    TNode<IntPtrT> tmp3;
    TNode<Smi> tmp4;
    TNode<Int32T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<Uint32T> tmp7;
    TNode<BoolT> tmp8;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp4 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { parameter0, tmp3 });
        tmp5 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { tmp4 });
        tmp6 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp5 });
        tmp7 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { tmp6 }, TNode<Uint32T> { tmp0 });
        tmp8 = CodeStubAssembler(state_).Uint32GreaterThanOrEqual(TNode<Uint32T> { parameter2 }, TNode<Uint32T> { tmp7 });
        ca_.Branch(tmp8, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        CodeStubAssembler(state_).Return(tmp6);
    }

    TNode<Uint32T> tmp9;
    TNode<Uint32T> tmp10;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp9 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { tmp0 }, TNode<Uint32T> { parameter2 });
        tmp10 = AlignWtf8PositionBackward_0(state_, TNode<ByteArray> { parameter0 }, TNode<Uint32T> { tmp9 });
        CodeStubAssembler(state_).Return(tmp10);
    }
}

TF_BUILTIN(WasmStringViewWtf8Encode, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<UintPtrT> parameter0 = UncheckedParameter<UintPtrT>(Descriptor::kAddr);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kPos);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kBytes);
    USE(parameter2);
    TNode<ByteArray> parameter3 = UncheckedParameter<ByteArray>(Descriptor::kView);
    USE(parameter3);
    TNode<Smi> parameter4 = UncheckedParameter<Smi>(Descriptor::kMemory);
    USE(parameter4);
    TNode<Smi> parameter5 = UncheckedParameter<Smi>(Descriptor::kUtf8Variant);
    USE(parameter5);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Uint32T> tmp2;
    TNode<WasmTrustedInstanceData> tmp3;
    TNode<NativeContext> tmp4;
    TNode<Number> tmp5;
    TNode<Number> tmp6;
    TNode<Number> tmp7;
    TNode<Object> tmp8;
    TNode<Uint32T> tmp9;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp1 = ca_.CallBuiltin<Uint32T>(Builtin::kWasmStringViewWtf8Advance, TNode<Object>(), parameter3, parameter1, tmp0);
        tmp2 = ca_.CallBuiltin<Uint32T>(Builtin::kWasmStringViewWtf8Advance, TNode<Object>(), parameter3, tmp1, parameter2);
        tmp3 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp4 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp3 });
        tmp5 = UintPtrToNumberRounding_0(state_, TNode<UintPtrT> { parameter0 });
        tmp6 = ca_.CallBuiltin<Number>(Builtin::kWasmUint32ToNumber, TNode<Object>(), tmp1);
        tmp7 = ca_.CallBuiltin<Number>(Builtin::kWasmUint32ToNumber, TNode<Object>(), tmp2);
        tmp8 = CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringViewWtf8Encode, tmp4, tmp3, parameter5, parameter3, tmp5, tmp6, tmp7, parameter4);
        tmp9 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { tmp2 }, TNode<Uint32T> { tmp1 });
        CodeStubAssembler(state_).Return(tmp2, tmp9);
    }
}

TF_BUILTIN(WasmStringViewWtf8Slice, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<ByteArray> parameter0 = UncheckedParameter<ByteArray>(Descriptor::kView);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kStart);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kEnd);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Uint32T> tmp2;
    TNode<Uint32T> tmp3;
    TNode<BoolT> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp1 = ca_.CallBuiltin<Uint32T>(Builtin::kWasmStringViewWtf8Advance, TNode<Object>(), parameter0, parameter1, tmp0);
        tmp2 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp3 = ca_.CallBuiltin<Uint32T>(Builtin::kWasmStringViewWtf8Advance, TNode<Object>(), parameter0, parameter2, tmp2);
        tmp4 = CodeStubAssembler(state_).Uint32LessThanOrEqual(TNode<Uint32T> { tmp3 }, TNode<Uint32T> { tmp1 });
        ca_.Branch(tmp4, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<String> tmp5;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp5 = kEmptyString_0(state_);
        CodeStubAssembler(state_).Return(tmp5);
    }

    TNode<NativeContext> tmp6;
    TNode<Number> tmp7;
    TNode<Number> tmp8;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp6 = LoadContextFromFrame_0(state_);
        tmp7 = ca_.CallBuiltin<Number>(Builtin::kWasmUint32ToNumber, TNode<Object>(), tmp1);
        tmp8 = ca_.CallBuiltin<Number>(Builtin::kWasmUint32ToNumber, TNode<Object>(), tmp3);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringViewWtf8Slice, tmp6, parameter0, tmp7, tmp8);
    }
}

TF_BUILTIN(WasmStringViewWtf16GetCodeUnit, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kOffset);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Int32T> tmp1;
    TNode<Uint32T> tmp2;
    TNode<BoolT> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { parameter0, tmp0 });
        tmp2 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp1 });
        tmp3 = CodeStubAssembler(state_).Uint32LessThanOrEqual(TNode<Uint32T> { tmp2 }, TNode<Uint32T> { parameter1 });
        ca_.Branch(tmp3, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    TNode<NativeContext> tmp4;
    TNode<Smi> tmp5;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp4 = LoadContextFromFrame_0(state_);
        tmp5 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapStringOffsetOutOfBounds);
        CodeStubAssembler(state_).CallRuntime(Runtime::kThrowWasmError, tmp4, tmp5);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> tmp6;
    TNode<Uint16T> tmp7;
    TNode<Uint32T> tmp8;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp6 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { parameter1 });
        tmp7 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String> { parameter0 }, TNode<UintPtrT> { tmp6 });
        tmp8 = Convert_uint32_char16_0(state_, TNode<Uint16T> { tmp7 });
        CodeStubAssembler(state_).Return(tmp8);
    }
}

TF_BUILTIN(WasmStringViewWtf16Encode, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<UintPtrT> parameter0 = UncheckedParameter<UintPtrT>(Descriptor::kOffset);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kStart);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kLength);
    USE(parameter2);
    TNode<String> parameter3 = UncheckedParameter<String>(Descriptor::kString);
    USE(parameter3);
    TNode<Smi> parameter4 = UncheckedParameter<Smi>(Descriptor::kMemory);
    USE(parameter4);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Int32T> tmp2;
    TNode<Uint32T> tmp3;
    TNode<BoolT> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp2 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { parameter3, tmp1 });
        tmp3 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp2 });
        tmp4 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { parameter1 }, TNode<Uint32T> { tmp3 });
        ca_.Branch(tmp4, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    if (block1.is_used()) {
        ca_.Bind(&block1);
        ca_.Goto(&block3, parameter1);
    }

    TNode<IntPtrT> tmp5;
    TNode<Int32T> tmp6;
    TNode<Uint32T> tmp7;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp6 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { parameter3, tmp5 });
        tmp7 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp6 });
        ca_.Goto(&block3, tmp7);
    }

    TNode<Uint32T> phi_bb3_6;
    TNode<IntPtrT> tmp8;
    TNode<Int32T> tmp9;
    TNode<Uint32T> tmp10;
    TNode<Uint32T> tmp11;
    TNode<BoolT> tmp12;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_6);
        tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp9 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { parameter3, tmp8 });
        tmp10 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp9 });
        tmp11 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { tmp10 }, TNode<Uint32T> { phi_bb3_6 });
        tmp12 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { parameter2 }, TNode<Uint32T> { tmp11 });
        ca_.Branch(tmp12, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        ca_.Goto(&block7, parameter2);
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block7, tmp11);
    }

    TNode<Uint32T> phi_bb7_8;
    TNode<NativeContext> tmp13;
    TNode<Number> tmp14;
    TNode<Smi> tmp15;
    TNode<Smi> tmp16;
    TNode<Object> tmp17;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_8);
        tmp13 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp14 = UintPtrToNumberRounding_0(state_, TNode<UintPtrT> { parameter0 });
        tmp15 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { phi_bb3_6 });
        tmp16 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { phi_bb7_8 });
        tmp17 = CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringEncodeWtf16, tmp13, tmp0, parameter4, parameter3, tmp14, tmp15, tmp16);
        CodeStubAssembler(state_).Return(phi_bb7_8);
    }
}

TF_BUILTIN(WasmStringViewWtf16Slice, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kStart);
    USE(parameter1);
    TNode<Uint32T> parameter2 = UncheckedParameter<Uint32T>(Descriptor::kEnd);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, String> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, String> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block68(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String, IntPtrT> block67(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT, String> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String, IntPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block77(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object, IntPtrT, IntPtrT, Object, IntPtrT, IntPtrT> block76(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Int32T> tmp1;
    TNode<Uint32T> tmp2;
    TNode<BoolT> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { parameter0, tmp0 });
        tmp2 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp1 });
        tmp3 = CodeStubAssembler(state_).Uint32GreaterThanOrEqual(TNode<Uint32T> { parameter1 }, TNode<Uint32T> { tmp2 });
        ca_.Branch(tmp3, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<String> tmp4;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp4 = kEmptyString_0(state_);
        CodeStubAssembler(state_).Return(tmp4);
    }

    TNode<BoolT> tmp5;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp5 = CodeStubAssembler(state_).Uint32LessThanOrEqual(TNode<Uint32T> { parameter2 }, TNode<Uint32T> { parameter1 });
        ca_.Branch(tmp5, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    TNode<String> tmp6;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp6 = kEmptyString_0(state_);
        CodeStubAssembler(state_).Return(tmp6);
    }

    TNode<BoolT> tmp7;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp7 = CodeStubAssembler(state_).Uint32LessThanOrEqual(TNode<Uint32T> { parameter2 }, TNode<Uint32T> { tmp2 });
        ca_.Branch(tmp7, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        ca_.Goto(&block7, parameter2);
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block7, tmp2);
    }

    TNode<Uint32T> phi_bb7_4;
    TNode<Uint32T> tmp8;
    TNode<Uint32T> tmp9;
    TNode<BoolT> tmp10;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_4);
        tmp8 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { phi_bb7_4 }, TNode<Uint32T> { parameter1 });
        tmp9 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp10 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp8 }, TNode<Uint32T> { tmp9 });
        ca_.Branch(tmp10, &block11, std::vector<compiler::Node*> {}, &block12, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp11;
    TNode<Uint32T> tmp12;
    TNode<BoolT> tmp13;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp11 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp12 = CodeStubAssembler(state_).Uint32Div(TNode<Uint32T> { tmp2 }, TNode<Uint32T> { tmp11 });
        tmp13 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { tmp8 }, TNode<Uint32T> { tmp12 });
        ca_.Goto(&block13, tmp13);
    }

    TNode<BoolT> tmp14;
    if (block12.is_used()) {
        ca_.Bind(&block12);
        tmp14 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block13, tmp14);
    }

    TNode<BoolT> phi_bb13_7;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_7);
        ca_.Branch(phi_bb13_7, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp15;
    TNode<BoolT> tmp16;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp15 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x20ull));
        tmp16 = CodeStubAssembler(state_).Uint32GreaterThan(TNode<Uint32T> { tmp8 }, TNode<Uint32T> { tmp15 });
        ca_.Branch(tmp16, &block20, std::vector<compiler::Node*> {}, &block21, std::vector<compiler::Node*> {});
    }

    TNode<NativeContext> tmp17;
    TNode<Smi> tmp18;
    TNode<Smi> tmp19;
    if (block20.is_used()) {
        ca_.Bind(&block20);
        tmp17 = WasmBuiltinsAssembler(state_).LoadContextFromWasmOrJsFrame();
        tmp18 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { parameter1 });
        tmp19 = CodeStubAssembler(state_).SmiFromUint32(TNode<Uint32T> { tmp8 });
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmSubstring, tmp17, parameter0, tmp18, tmp19);
    }

    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<Int32T> tmp22;
    TNode<IntPtrT> tmp23;
    if (block21.is_used()) {
        ca_.Bind(&block21);
        tmp20 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp22 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { parameter0, tmp21 });
        tmp23 = Convert_intptr_int32_0(state_, TNode<Int32T> { tmp22 });
        ca_.Goto(&block24, parameter0, tmp20);
    }

    TNode<String> phi_bb24_8;
    TNode<IntPtrT> phi_bb24_9;
    TNode<BoolT> tmp24;
    if (block24.is_used()) {
        ca_.Bind(&block24, &phi_bb24_8, &phi_bb24_9);
        tmp24 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Branch(tmp24, &block22, std::vector<compiler::Node*> { phi_bb24_8, phi_bb24_9 }, &block23, std::vector<compiler::Node*> { phi_bb24_8, phi_bb24_9 });
    }

    TNode<String> phi_bb22_8;
    TNode<IntPtrT> phi_bb22_9;
    TNode<SeqOneByteString> tmp25;
    if (block22.is_used()) {
        ca_.Bind(&block22, &phi_bb22_8, &phi_bb22_9);
        compiler::CodeAssemblerLabel label26(&ca_);
        tmp25 = Cast_SeqOneByteString_1(state_, TNode<String> { phi_bb22_8 }, &label26);
        ca_.Goto(&block27, phi_bb22_8, phi_bb22_9, phi_bb22_8, phi_bb22_8);
        if (label26.is_used()) {
            ca_.Bind(&label26);
            ca_.Goto(&block28, phi_bb22_8, phi_bb22_9, phi_bb22_8, phi_bb22_8);
        }
    }

    TNode<String> phi_bb28_8;
    TNode<IntPtrT> phi_bb28_9;
    TNode<String> phi_bb28_11;
    TNode<String> phi_bb28_12;
    TNode<SeqTwoByteString> tmp27;
    if (block28.is_used()) {
        ca_.Bind(&block28, &phi_bb28_8, &phi_bb28_9, &phi_bb28_11, &phi_bb28_12);
        compiler::CodeAssemblerLabel label28(&ca_);
        tmp27 = Cast_SeqTwoByteString_1(state_, TNode<String> { ca_.UncheckedCast<String>(phi_bb28_11) }, &label28);
        ca_.Goto(&block35, phi_bb28_8, phi_bb28_9, phi_bb28_11);
        if (label28.is_used()) {
            ca_.Bind(&label28);
            ca_.Goto(&block36, phi_bb28_8, phi_bb28_9, phi_bb28_11);
        }
    }

    TNode<String> phi_bb27_8;
    TNode<IntPtrT> phi_bb27_9;
    TNode<String> phi_bb27_11;
    TNode<String> phi_bb27_12;
    TNode<Object> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<Object> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    if (block27.is_used()) {
        ca_.Bind(&block27, &phi_bb27_8, &phi_bb27_9, &phi_bb27_11, &phi_bb27_12);
        std::tie(tmp29, tmp30, tmp31) = FieldSliceSeqOneByteStringChars_0(state_, TNode<SeqOneByteString> { tmp25 }).Flatten();
        compiler::CodeAssemblerLabel label35(&ca_);
        std::tie(tmp32, tmp33, tmp34) = Subslice_char8_0(state_,
            TorqueStructSlice_char8_ConstReference_char8_0 {
                TNode<Object> { tmp29 }, TNode<IntPtrT> { tmp30 }, TNode<IntPtrT> { tmp31 }, TorqueStructUnsafe_0 {} },
            TNode<IntPtrT> { phi_bb27_9 }, TNode<IntPtrT> { tmp23 }, &label35)
                                            .Flatten();
        ca_.Goto(&block31, phi_bb27_8, phi_bb27_9, phi_bb27_11, phi_bb27_9);
        if (label35.is_used()) {
            ca_.Bind(&label35);
            ca_.Goto(&block32, phi_bb27_8, phi_bb27_9, phi_bb27_11, phi_bb27_9);
        }
    }

    TNode<String> phi_bb32_8;
    TNode<IntPtrT> phi_bb32_9;
    TNode<String> phi_bb32_11;
    TNode<IntPtrT> phi_bb32_16;
    if (block32.is_used()) {
        ca_.Bind(&block32, &phi_bb32_8, &phi_bb32_9, &phi_bb32_11, &phi_bb32_16);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<String> phi_bb31_8;
    TNode<IntPtrT> phi_bb31_9;
    TNode<String> phi_bb31_11;
    TNode<IntPtrT> phi_bb31_16;
    if (block31.is_used()) {
        ca_.Bind(&block31, &phi_bb31_8, &phi_bb31_9, &phi_bb31_11, &phi_bb31_16);
        ca_.Goto(&block19, tmp32, tmp33, tmp34);
    }

    TNode<String> phi_bb36_8;
    TNode<IntPtrT> phi_bb36_9;
    TNode<String> phi_bb36_11;
    TNode<ThinString> tmp36;
    if (block36.is_used()) {
        ca_.Bind(&block36, &phi_bb36_8, &phi_bb36_9, &phi_bb36_11);
        compiler::CodeAssemblerLabel label37(&ca_);
        tmp36 = Cast_ThinString_1(state_, TNode<String> { ca_.UncheckedCast<String>(phi_bb36_11) }, &label37);
        ca_.Goto(&block43, phi_bb36_8, phi_bb36_9, phi_bb36_11);
        if (label37.is_used()) {
            ca_.Bind(&label37);
            ca_.Goto(&block44, phi_bb36_8, phi_bb36_9, phi_bb36_11);
        }
    }

    TNode<String> phi_bb35_8;
    TNode<IntPtrT> phi_bb35_9;
    TNode<String> phi_bb35_11;
    TNode<Object> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<Object> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<IntPtrT> tmp43;
    if (block35.is_used()) {
        ca_.Bind(&block35, &phi_bb35_8, &phi_bb35_9, &phi_bb35_11);
        std::tie(tmp38, tmp39, tmp40) = FieldSliceSeqTwoByteStringChars_0(state_, TNode<SeqTwoByteString> { tmp27 }).Flatten();
        compiler::CodeAssemblerLabel label44(&ca_);
        std::tie(tmp41, tmp42, tmp43) = Subslice_char16_0(state_,
            TorqueStructSlice_char16_ConstReference_char16_0 {
                TNode<Object> { tmp38 }, TNode<IntPtrT> { tmp39 }, TNode<IntPtrT> { tmp40 }, TorqueStructUnsafe_0 {} },
            TNode<IntPtrT> { phi_bb35_9 }, TNode<IntPtrT> { tmp23 }, &label44)
                                            .Flatten();
        ca_.Goto(&block39, phi_bb35_8, phi_bb35_9, phi_bb35_11, phi_bb35_9);
        if (label44.is_used()) {
            ca_.Bind(&label44);
            ca_.Goto(&block40, phi_bb35_8, phi_bb35_9, phi_bb35_11, phi_bb35_9);
        }
    }

    TNode<String> phi_bb40_8;
    TNode<IntPtrT> phi_bb40_9;
    TNode<String> phi_bb40_11;
    TNode<IntPtrT> phi_bb40_16;
    if (block40.is_used()) {
        ca_.Bind(&block40, &phi_bb40_8, &phi_bb40_9, &phi_bb40_11, &phi_bb40_16);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<String> phi_bb39_8;
    TNode<IntPtrT> phi_bb39_9;
    TNode<String> phi_bb39_11;
    TNode<IntPtrT> phi_bb39_16;
    if (block39.is_used()) {
        ca_.Bind(&block39, &phi_bb39_8, &phi_bb39_9, &phi_bb39_11, &phi_bb39_16);
        ca_.Goto(&block17, tmp41, tmp42, tmp43);
    }

    TNode<String> phi_bb44_8;
    TNode<IntPtrT> phi_bb44_9;
    TNode<String> phi_bb44_11;
    TNode<ConsString> tmp45;
    if (block44.is_used()) {
        ca_.Bind(&block44, &phi_bb44_8, &phi_bb44_9, &phi_bb44_11);
        compiler::CodeAssemblerLabel label46(&ca_);
        tmp45 = Cast_ConsString_1(state_, TNode<String> { ca_.UncheckedCast<String>(phi_bb44_11) }, &label46);
        ca_.Goto(&block47, phi_bb44_8, phi_bb44_9, phi_bb44_11);
        if (label46.is_used()) {
            ca_.Bind(&label46);
            ca_.Goto(&block48, phi_bb44_8, phi_bb44_9, phi_bb44_11);
        }
    }

    TNode<String> phi_bb43_8;
    TNode<IntPtrT> phi_bb43_9;
    TNode<String> phi_bb43_11;
    TNode<IntPtrT> tmp47;
    TNode<String> tmp48;
    if (block43.is_used()) {
        ca_.Bind(&block43, &phi_bb43_8, &phi_bb43_9, &phi_bb43_11);
        tmp47 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp48 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference { tmp36, tmp47 });
        ca_.Goto(&block41, tmp48, phi_bb43_9, phi_bb43_11);
    }

    TNode<String> phi_bb48_8;
    TNode<IntPtrT> phi_bb48_9;
    TNode<String> phi_bb48_11;
    TNode<SlicedString> tmp49;
    if (block48.is_used()) {
        ca_.Bind(&block48, &phi_bb48_8, &phi_bb48_9, &phi_bb48_11);
        compiler::CodeAssemblerLabel label50(&ca_);
        tmp49 = Cast_SlicedString_1(state_, TNode<String> { ca_.UncheckedCast<String>(phi_bb48_11) }, &label50);
        ca_.Goto(&block51, phi_bb48_8, phi_bb48_9, phi_bb48_11);
        if (label50.is_used()) {
            ca_.Bind(&label50);
            ca_.Goto(&block52, phi_bb48_8, phi_bb48_9, phi_bb48_11);
        }
    }

    TNode<String> phi_bb47_8;
    TNode<IntPtrT> phi_bb47_9;
    TNode<String> phi_bb47_11;
    TNode<String> tmp51;
    if (block47.is_used()) {
        ca_.Bind(&block47, &phi_bb47_8, &phi_bb47_9, &phi_bb47_11);
        tmp51 = Flatten_1(state_, TNode<ConsString> { tmp45 });
        ca_.Goto(&block45, tmp51, phi_bb47_9, phi_bb47_11);
    }

    TNode<String> phi_bb52_8;
    TNode<IntPtrT> phi_bb52_9;
    TNode<String> phi_bb52_11;
    TNode<ExternalOneByteString> tmp52;
    if (block52.is_used()) {
        ca_.Bind(&block52, &phi_bb52_8, &phi_bb52_9, &phi_bb52_11);
        compiler::CodeAssemblerLabel label53(&ca_);
        tmp52 = Cast_ExternalOneByteString_1(state_, TNode<String> { ca_.UncheckedCast<String>(phi_bb52_11) }, &label53);
        ca_.Goto(&block55, phi_bb52_8, phi_bb52_9, phi_bb52_11);
        if (label53.is_used()) {
            ca_.Bind(&label53);
            ca_.Goto(&block56, phi_bb52_8, phi_bb52_9, phi_bb52_11);
        }
    }

    TNode<String> phi_bb51_8;
    TNode<IntPtrT> phi_bb51_9;
    TNode<String> phi_bb51_11;
    TNode<IntPtrT> tmp54;
    TNode<Smi> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<String> tmp59;
    if (block51.is_used()) {
        ca_.Bind(&block51, &phi_bb51_8, &phi_bb51_9, &phi_bb51_11);
        tmp54 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp55 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference { tmp49, tmp54 });
        tmp56 = Convert_intptr_Smi_0(state_, TNode<Smi> { tmp55 });
        tmp57 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { phi_bb51_9 }, TNode<IntPtrT> { tmp56 });
        tmp58 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp59 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference { tmp49, tmp58 });
        ca_.Goto(&block45, tmp59, tmp57, phi_bb51_11);
    }

    TNode<String> phi_bb56_8;
    TNode<IntPtrT> phi_bb56_9;
    TNode<String> phi_bb56_11;
    TNode<ExternalTwoByteString> tmp60;
    if (block56.is_used()) {
        ca_.Bind(&block56, &phi_bb56_8, &phi_bb56_9, &phi_bb56_11);
        compiler::CodeAssemblerLabel label61(&ca_);
        tmp60 = Cast_ExternalTwoByteString_1(state_, TNode<String> { ca_.UncheckedCast<String>(phi_bb56_11) }, &label61);
        ca_.Goto(&block63, phi_bb56_8, phi_bb56_9, phi_bb56_11);
        if (label61.is_used()) {
            ca_.Bind(&label61);
            ca_.Goto(&block64, phi_bb56_8, phi_bb56_9, phi_bb56_11);
        }
    }

    TNode<String> phi_bb55_8;
    TNode<IntPtrT> phi_bb55_9;
    TNode<String> phi_bb55_11;
    TNode<RawPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<Int32T> tmp64;
    TNode<IntPtrT> tmp65;
    TNode<Object> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<Object> tmp69;
    TNode<IntPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    if (block55.is_used()) {
        ca_.Bind(&block55, &phi_bb55_8, &phi_bb55_9, &phi_bb55_11);
        tmp62 = Method_ExternalOneByteString_GetChars_0(state_, TNode<ExternalOneByteString> { tmp52 });
        tmp63 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp64 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp52, tmp63 });
        tmp65 = Convert_intptr_int32_0(state_, TNode<Int32T> { tmp64 });
        std::tie(tmp66, tmp67, tmp68) = NewOffHeapConstSlice_char8_0(state_, TNode<RawPtrT> { tmp62 }, TNode<IntPtrT> { tmp65 }).Flatten();
        compiler::CodeAssemblerLabel label72(&ca_);
        std::tie(tmp69, tmp70, tmp71) = Subslice_char8_0(state_,
            TorqueStructSlice_char8_ConstReference_char8_0 {
                TNode<Object> { tmp66 }, TNode<IntPtrT> { tmp67 }, TNode<IntPtrT> { tmp68 }, TorqueStructUnsafe_0 {} },
            TNode<IntPtrT> { phi_bb55_9 }, TNode<IntPtrT> { tmp23 }, &label72)
                                            .Flatten();
        ca_.Goto(&block59, phi_bb55_8, phi_bb55_9, phi_bb55_11, phi_bb55_9);
        if (label72.is_used()) {
            ca_.Bind(&label72);
            ca_.Goto(&block60, phi_bb55_8, phi_bb55_9, phi_bb55_11, phi_bb55_9);
        }
    }

    TNode<String> phi_bb60_8;
    TNode<IntPtrT> phi_bb60_9;
    TNode<String> phi_bb60_11;
    TNode<IntPtrT> phi_bb60_19;
    if (block60.is_used()) {
        ca_.Bind(&block60, &phi_bb60_8, &phi_bb60_9, &phi_bb60_11, &phi_bb60_19);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<String> phi_bb59_8;
    TNode<IntPtrT> phi_bb59_9;
    TNode<String> phi_bb59_11;
    TNode<IntPtrT> phi_bb59_19;
    if (block59.is_used()) {
        ca_.Bind(&block59, &phi_bb59_8, &phi_bb59_9, &phi_bb59_11, &phi_bb59_19);
        ca_.Goto(&block19, tmp69, tmp70, tmp71);
    }

    TNode<String> phi_bb64_8;
    TNode<IntPtrT> phi_bb64_9;
    TNode<String> phi_bb64_11;
    if (block64.is_used()) {
        ca_.Bind(&block64, &phi_bb64_8, &phi_bb64_9, &phi_bb64_11);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<String> phi_bb63_8;
    TNode<IntPtrT> phi_bb63_9;
    TNode<String> phi_bb63_11;
    TNode<RawPtrT> tmp73;
    TNode<IntPtrT> tmp74;
    TNode<Int32T> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<Object> tmp77;
    TNode<IntPtrT> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<Object> tmp80;
    TNode<IntPtrT> tmp81;
    TNode<IntPtrT> tmp82;
    if (block63.is_used()) {
        ca_.Bind(&block63, &phi_bb63_8, &phi_bb63_9, &phi_bb63_11);
        tmp73 = Method_ExternalTwoByteString_GetChars_0(state_, TNode<ExternalTwoByteString> { tmp60 });
        tmp74 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp75 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp60, tmp74 });
        tmp76 = Convert_intptr_int32_0(state_, TNode<Int32T> { tmp75 });
        std::tie(tmp77, tmp78, tmp79) = NewOffHeapConstSlice_char16_0(state_, TNode<RawPtrT> { tmp73 }, TNode<IntPtrT> { tmp76 }).Flatten();
        compiler::CodeAssemblerLabel label83(&ca_);
        std::tie(tmp80, tmp81, tmp82) = Subslice_char16_0(state_,
            TorqueStructSlice_char16_ConstReference_char16_0 {
                TNode<Object> { tmp77 }, TNode<IntPtrT> { tmp78 }, TNode<IntPtrT> { tmp79 }, TorqueStructUnsafe_0 {} },
            TNode<IntPtrT> { phi_bb63_9 }, TNode<IntPtrT> { tmp23 }, &label83)
                                            .Flatten();
        ca_.Goto(&block67, phi_bb63_8, phi_bb63_9, phi_bb63_11, phi_bb63_9);
        if (label83.is_used()) {
            ca_.Bind(&label83);
            ca_.Goto(&block68, phi_bb63_8, phi_bb63_9, phi_bb63_11, phi_bb63_9);
        }
    }

    TNode<String> phi_bb68_8;
    TNode<IntPtrT> phi_bb68_9;
    TNode<String> phi_bb68_11;
    TNode<IntPtrT> phi_bb68_19;
    if (block68.is_used()) {
        ca_.Bind(&block68, &phi_bb68_8, &phi_bb68_9, &phi_bb68_11, &phi_bb68_19);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<String> phi_bb67_8;
    TNode<IntPtrT> phi_bb67_9;
    TNode<String> phi_bb67_11;
    TNode<IntPtrT> phi_bb67_19;
    if (block67.is_used()) {
        ca_.Bind(&block67, &phi_bb67_8, &phi_bb67_9, &phi_bb67_11, &phi_bb67_19);
        ca_.Goto(&block17, tmp80, tmp81, tmp82);
    }

    TNode<String> phi_bb45_8;
    TNode<IntPtrT> phi_bb45_9;
    TNode<String> phi_bb45_11;
    if (block45.is_used()) {
        ca_.Bind(&block45, &phi_bb45_8, &phi_bb45_9, &phi_bb45_11);
        ca_.Goto(&block41, phi_bb45_8, phi_bb45_9, phi_bb45_11);
    }

    TNode<String> phi_bb41_8;
    TNode<IntPtrT> phi_bb41_9;
    TNode<String> phi_bb41_11;
    if (block41.is_used()) {
        ca_.Bind(&block41, &phi_bb41_8, &phi_bb41_9, &phi_bb41_11);
        ca_.Goto(&block24, phi_bb41_8, phi_bb41_9);
    }

    TNode<String> phi_bb23_8;
    TNode<IntPtrT> phi_bb23_9;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_8, &phi_bb23_9);
        VerifiedUnreachable_0(state_);
    }

    TNode<Object> phi_bb19_6;
    TNode<IntPtrT> phi_bb19_7;
    TNode<IntPtrT> phi_bb19_8;
    TNode<IntPtrT> tmp84;
    TNode<IntPtrT> tmp85;
    TNode<Object> tmp86;
    TNode<IntPtrT> tmp87;
    TNode<IntPtrT> tmp88;
    if (block19.is_used()) {
        ca_.Bind(&block19, &phi_bb19_6, &phi_bb19_7, &phi_bb19_8);
        tmp84 = Convert_intptr_uint32_0(state_, TNode<Uint32T> { parameter1 });
        tmp85 = Convert_intptr_uint32_0(state_, TNode<Uint32T> { tmp8 });
        compiler::CodeAssemblerLabel label89(&ca_);
        std::tie(tmp86, tmp87, tmp88) = Subslice_char8_0(state_,
            TorqueStructSlice_char8_ConstReference_char8_0 {
                TNode<Object> { phi_bb19_6 }, TNode<IntPtrT> { phi_bb19_7 }, TNode<IntPtrT> { phi_bb19_8 }, TorqueStructUnsafe_0 {} },
            TNode<IntPtrT> { tmp84 }, TNode<IntPtrT> { tmp85 }, &label89)
                                            .Flatten();
        ca_.Goto(&block71, phi_bb19_6, phi_bb19_7, phi_bb19_8, phi_bb19_6, phi_bb19_7, phi_bb19_8);
        if (label89.is_used()) {
            ca_.Bind(&label89);
            ca_.Goto(&block72, phi_bb19_6, phi_bb19_7, phi_bb19_8, phi_bb19_6, phi_bb19_7, phi_bb19_8);
        }
    }

    TNode<Object> phi_bb72_6;
    TNode<IntPtrT> phi_bb72_7;
    TNode<IntPtrT> phi_bb72_8;
    TNode<Object> phi_bb72_9;
    TNode<IntPtrT> phi_bb72_10;
    TNode<IntPtrT> phi_bb72_11;
    if (block72.is_used()) {
        ca_.Bind(&block72, &phi_bb72_6, &phi_bb72_7, &phi_bb72_8, &phi_bb72_9, &phi_bb72_10, &phi_bb72_11);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Object> phi_bb71_6;
    TNode<IntPtrT> phi_bb71_7;
    TNode<IntPtrT> phi_bb71_8;
    TNode<Object> phi_bb71_9;
    TNode<IntPtrT> phi_bb71_10;
    TNode<IntPtrT> phi_bb71_11;
    TNode<IntPtrT> tmp90;
    TNode<IntPtrT> tmp91;
    TNode<SeqOneByteString> tmp92;
    if (block71.is_used()) {
        ca_.Bind(&block71, &phi_bb71_6, &phi_bb71_7, &phi_bb71_8, &phi_bb71_9, &phi_bb71_10, &phi_bb71_11);
        tmp90 = TimesSizeOf_char8_0(state_, TNode<IntPtrT> { tmp88 });
        tmp91 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp87 }, TNode<IntPtrT> { tmp90 });
        tmp92 = AllocateNonEmptySeqOneByteString_SliceIterator_char8_ConstReference_char8_0(state_, TNode<Uint32T> { tmp8 },
            TorqueStructSliceIterator_char8_ConstReference_char8_0 {
                TNode<Object> { tmp86 }, TNode<IntPtrT> { tmp87 }, TNode<IntPtrT> { tmp91 }, TorqueStructUnsafe_0 {} });
        CodeStubAssembler(state_).Return(tmp92);
    }

    TNode<Object> phi_bb17_6;
    TNode<IntPtrT> phi_bb17_7;
    TNode<IntPtrT> phi_bb17_8;
    TNode<IntPtrT> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<Object> tmp95;
    TNode<IntPtrT> tmp96;
    TNode<IntPtrT> tmp97;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_6, &phi_bb17_7, &phi_bb17_8);
        tmp93 = Convert_intptr_uint32_0(state_, TNode<Uint32T> { parameter1 });
        tmp94 = Convert_intptr_uint32_0(state_, TNode<Uint32T> { tmp8 });
        compiler::CodeAssemblerLabel label98(&ca_);
        std::tie(tmp95, tmp96, tmp97) = Subslice_char16_0(state_,
            TorqueStructSlice_char16_ConstReference_char16_0 {
                TNode<Object> { phi_bb17_6 }, TNode<IntPtrT> { phi_bb17_7 }, TNode<IntPtrT> { phi_bb17_8 }, TorqueStructUnsafe_0 {} },
            TNode<IntPtrT> { tmp93 }, TNode<IntPtrT> { tmp94 }, &label98)
                                            .Flatten();
        ca_.Goto(&block76, phi_bb17_6, phi_bb17_7, phi_bb17_8, phi_bb17_6, phi_bb17_7, phi_bb17_8);
        if (label98.is_used()) {
            ca_.Bind(&label98);
            ca_.Goto(&block77, phi_bb17_6, phi_bb17_7, phi_bb17_8, phi_bb17_6, phi_bb17_7, phi_bb17_8);
        }
    }

    TNode<Object> phi_bb77_6;
    TNode<IntPtrT> phi_bb77_7;
    TNode<IntPtrT> phi_bb77_8;
    TNode<Object> phi_bb77_9;
    TNode<IntPtrT> phi_bb77_10;
    TNode<IntPtrT> phi_bb77_11;
    if (block77.is_used()) {
        ca_.Bind(&block77, &phi_bb77_6, &phi_bb77_7, &phi_bb77_8, &phi_bb77_9, &phi_bb77_10, &phi_bb77_11);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Object> phi_bb76_6;
    TNode<IntPtrT> phi_bb76_7;
    TNode<IntPtrT> phi_bb76_8;
    TNode<Object> phi_bb76_9;
    TNode<IntPtrT> phi_bb76_10;
    TNode<IntPtrT> phi_bb76_11;
    TNode<String> tmp99;
    if (block76.is_used()) {
        ca_.Bind(&block76, &phi_bb76_6, &phi_bb76_7, &phi_bb76_8, &phi_bb76_9, &phi_bb76_10, &phi_bb76_11);
        tmp99 = StringFromTwoByteSlice_0(state_, TNode<Uint32T> { tmp8 },
            TorqueStructSlice_char16_ConstReference_char16_0 {
                TNode<Object> { tmp95 }, TNode<IntPtrT> { tmp96 }, TNode<IntPtrT> { tmp97 }, TorqueStructUnsafe_0 {} });
        CodeStubAssembler(state_).Return(tmp99);
    }

    TNode<UintPtrT> tmp100;
    TNode<UintPtrT> tmp101;
    TNode<String> tmp102;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp100 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { parameter1 });
        tmp101 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { phi_bb7_4 });
        tmp102 = StringBuiltinsAssembler(state_).SubString(TNode<String> { parameter0 }, TNode<UintPtrT> { tmp100 }, TNode<UintPtrT> { tmp101 });
        CodeStubAssembler(state_).Return(tmp102);
    }
}

TF_BUILTIN(WasmStringAsIter, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Map> tmp0;
    TNode<BoolT> tmp1;
    TNode<BoolT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<HeapObject> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<Uint32T> tmp8;
    TNode<WasmStringViewIter> tmp9;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).GetInstanceTypeMap(WASM_STRING_VIEW_ITER_TYPE);
        tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp4 = AllocateFromNew_0(state_, TNode<IntPtrT> { tmp3 }, TNode<Map> { tmp0 }, TNode<BoolT> { tmp1 }, TNode<BoolT> { tmp2 });
        tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference { tmp4, tmp5 }, tmp0);
        tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<String>(CodeStubAssembler::Reference { tmp4, tmp6 }, parameter0);
        tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp8 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference { tmp4, tmp7 }, tmp8);
        tmp9 = TORQUE_CAST(TNode<HeapObject> { tmp4 });
        CodeStubAssembler(state_).Return(tmp9);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1376&c=1
TNode<BoolT> IsLeadSurrogate_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_code)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Uint32T> tmp2;
    TNode<BoolT> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xfc00ull));
        tmp1 = CodeStubAssembler(state_).Word32And(TNode<Uint32T> { p_code }, TNode<Uint32T> { tmp0 });
        tmp2 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xd800ull));
        tmp3 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { tmp1 }, TNode<Uint32T> { tmp2 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<BoolT> { tmp3 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1379&c=1
TNode<BoolT> IsTrailSurrogate_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_code)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Uint32T> tmp2;
    TNode<BoolT> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xfc00ull));
        tmp1 = CodeStubAssembler(state_).Word32And(TNode<Uint32T> { p_code }, TNode<Uint32T> { tmp0 });
        tmp2 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xdc00ull));
        tmp3 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { tmp1 }, TNode<Uint32T> { tmp2 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<BoolT> { tmp3 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1382&c=1
TNode<Int32T> CombineSurrogatePair_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_lead, TNode<Uint16T> p_trail)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Uint32T> tmp2;
    TNode<Uint32T> tmp3;
    TNode<Uint32T> tmp4;
    TNode<Uint32T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<Int32T> tmp7;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_uint32_char16_0(state_, TNode<Uint16T> { p_lead });
        tmp1 = Convert_uint32_char16_0(state_, TNode<Uint16T> { p_trail });
        tmp2 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xfca02400ull));
        tmp3 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xaull));
        tmp4 = CodeStubAssembler(state_).Word32Shl(TNode<Uint32T> { tmp0 }, TNode<Uint32T> { tmp3 });
        tmp5 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { tmp4 }, TNode<Uint32T> { tmp1 });
        tmp6 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { tmp5 }, TNode<Uint32T> { tmp2 });
        tmp7 = CodeStubAssembler(state_).Signed(TNode<Uint32T> { tmp6 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<Int32T> { tmp7 };
}

TF_BUILTIN(WasmStringCodePointAt, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kOffset);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Int32T> tmp1;
    TNode<Uint32T> tmp2;
    TNode<BoolT> tmp3;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp1 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { parameter0, tmp0 });
        tmp2 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp1 });
        tmp3 = CodeStubAssembler(state_).Uint32LessThanOrEqual(TNode<Uint32T> { tmp2 }, TNode<Uint32T> { parameter1 });
        ca_.Branch(tmp3, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    TNode<NativeContext> tmp4;
    TNode<Smi> tmp5;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp4 = LoadContextFromFrame_0(state_);
        tmp5 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kWasmTrapStringOffsetOutOfBounds);
        CodeStubAssembler(state_).CallRuntime(Runtime::kThrowWasmError, tmp4, tmp5);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<UintPtrT> tmp6;
    TNode<Uint16T> tmp7;
    TNode<BoolT> tmp8;
    TNode<BoolT> tmp9;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp6 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { parameter1 });
        tmp7 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String> { parameter0 }, TNode<UintPtrT> { tmp6 });
        tmp8 = IsLeadSurrogate_0(state_, TNode<Uint16T> { tmp7 });
        tmp9 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp8 });
        ca_.Branch(tmp9, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp10;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp10 = Convert_uint32_char16_0(state_, TNode<Uint16T> { tmp7 });
        CodeStubAssembler(state_).Return(tmp10);
    }

    TNode<Uint32T> tmp11;
    TNode<Uint32T> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<Int32T> tmp14;
    TNode<Uint32T> tmp15;
    TNode<BoolT> tmp16;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp11 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp12 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { parameter1 }, TNode<Uint32T> { tmp11 });
        tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp14 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { parameter0, tmp13 });
        tmp15 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp14 });
        tmp16 = CodeStubAssembler(state_).Uint32LessThanOrEqual(TNode<Uint32T> { tmp15 }, TNode<Uint32T> { tmp12 });
        ca_.Branch(tmp16, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp17;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp17 = Convert_uint32_char16_0(state_, TNode<Uint16T> { tmp7 });
        CodeStubAssembler(state_).Return(tmp17);
    }

    TNode<UintPtrT> tmp18;
    TNode<Uint16T> tmp19;
    TNode<BoolT> tmp20;
    TNode<BoolT> tmp21;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp18 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { tmp12 });
        tmp19 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String> { parameter0 }, TNode<UintPtrT> { tmp18 });
        tmp20 = IsTrailSurrogate_0(state_, TNode<Uint16T> { tmp19 });
        tmp21 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp20 });
        ca_.Branch(tmp21, &block9, std::vector<compiler::Node*> {}, &block10, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp22;
    if (block9.is_used()) {
        ca_.Bind(&block9);
        tmp22 = Convert_uint32_char16_0(state_, TNode<Uint16T> { tmp7 });
        CodeStubAssembler(state_).Return(tmp22);
    }

    TNode<Int32T> tmp23;
    TNode<Uint32T> tmp24;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp23 = CombineSurrogatePair_0(state_, TNode<Uint16T> { tmp7 }, TNode<Uint16T> { tmp19 });
        tmp24 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp23 });
        CodeStubAssembler(state_).Return(tmp24);
    }
}

TF_BUILTIN(WasmStringViewIterNext, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<WasmStringViewIter> parameter0 = UncheckedParameter<WasmStringViewIter>(Descriptor::kView);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<String> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Uint32T> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Int32T> tmp5;
    TNode<Uint32T> tmp6;
    TNode<BoolT> tmp7;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference { parameter0, tmp0 });
        tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp3 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { parameter0, tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp1, tmp4 });
        tmp6 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp5 });
        tmp7 = CodeStubAssembler(state_).Uint32GreaterThanOrEqual(TNode<Uint32T> { tmp3 }, TNode<Uint32T> { tmp6 });
        ca_.Branch(tmp7, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<Int32T> tmp8;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp8 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(true, 0x1ull));
        CodeStubAssembler(state_).Return(tmp8);
    }

    TNode<UintPtrT> tmp9;
    TNode<Uint16T> tmp10;
    TNode<BoolT> tmp11;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp9 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { tmp3 });
        tmp10 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String> { tmp1 }, TNode<UintPtrT> { tmp9 });
        tmp11 = IsLeadSurrogate_0(state_, TNode<Uint16T> { tmp10 });
        ca_.Branch(tmp11, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp12;
    TNode<Uint32T> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<Int32T> tmp15;
    TNode<Uint32T> tmp16;
    TNode<BoolT> tmp17;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp12 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp13 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { tmp3 }, TNode<Uint32T> { tmp12 });
        tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp15 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp1, tmp14 });
        tmp16 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { tmp13 }, TNode<Uint32T> { tmp16 });
        ca_.Goto(&block9, tmp17);
    }

    TNode<BoolT> tmp18;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp18 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block9, tmp18);
    }

    TNode<BoolT> phi_bb9_5;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_5);
        ca_.Branch(phi_bb9_5, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp19;
    TNode<Uint32T> tmp20;
    TNode<UintPtrT> tmp21;
    TNode<Uint16T> tmp22;
    TNode<BoolT> tmp23;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp19 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp20 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { tmp3 }, TNode<Uint32T> { tmp19 });
        tmp21 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { tmp20 });
        tmp22 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String> { tmp1 }, TNode<UintPtrT> { tmp21 });
        tmp23 = IsTrailSurrogate_0(state_, TNode<Uint16T> { tmp22 });
        ca_.Branch(tmp23, &block10, std::vector<compiler::Node*> {}, &block11, std::vector<compiler::Node*> {});
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block3);
    }

    TNode<IntPtrT> tmp24;
    TNode<Uint32T> tmp25;
    TNode<Uint32T> tmp26;
    TNode<Int32T> tmp27;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp25 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp26 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { tmp3 }, TNode<Uint32T> { tmp25 });
        CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference { parameter0, tmp24 }, tmp26);
        tmp27 = CombineSurrogatePair_0(state_, TNode<Uint16T> { tmp10 }, TNode<Uint16T> { tmp22 });
        CodeStubAssembler(state_).Return(tmp27);
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block3);
    }

    TNode<IntPtrT> tmp28;
    TNode<Uint32T> tmp29;
    TNode<Uint32T> tmp30;
    TNode<Uint32T> tmp31;
    TNode<Int32T> tmp32;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp28 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp29 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp30 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { tmp3 }, TNode<Uint32T> { tmp29 });
        CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference { parameter0, tmp28 }, tmp30);
        tmp31 = Convert_uint32_char16_0(state_, TNode<Uint16T> { tmp10 });
        tmp32 = CodeStubAssembler(state_).Signed(TNode<Uint32T> { tmp31 });
        CodeStubAssembler(state_).Return(tmp32);
    }
}

TF_BUILTIN(WasmStringViewIterAdvance, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<WasmStringViewIter> parameter0 = UncheckedParameter<WasmStringViewIter>(Descriptor::kView);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kCodepoints);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<String> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Uint32T> tmp3;
    TNode<Uint32T> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference { parameter0, tmp0 });
        tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp3 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { parameter0, tmp2 });
        tmp4 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block3, tmp3, tmp4);
    }

    TNode<Uint32T> phi_bb3_3;
    TNode<Uint32T> phi_bb3_4;
    TNode<BoolT> tmp5;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_3, &phi_bb3_4);
        tmp5 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { phi_bb3_4 }, TNode<Uint32T> { parameter1 });
        ca_.Branch(tmp5, &block1, std::vector<compiler::Node*> { phi_bb3_3, phi_bb3_4 }, &block2, std::vector<compiler::Node*> { phi_bb3_3, phi_bb3_4 });
    }

    TNode<Uint32T> phi_bb1_3;
    TNode<Uint32T> phi_bb1_4;
    TNode<IntPtrT> tmp6;
    TNode<Int32T> tmp7;
    TNode<Uint32T> tmp8;
    TNode<BoolT> tmp9;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_3, &phi_bb1_4);
        tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp7 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp1, tmp6 });
        tmp8 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp7 });
        tmp9 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb1_3 }, TNode<Uint32T> { tmp8 });
        ca_.Branch(tmp9, &block4, std::vector<compiler::Node*> { phi_bb1_3, phi_bb1_4 }, &block5, std::vector<compiler::Node*> { phi_bb1_3, phi_bb1_4 });
    }

    TNode<Uint32T> phi_bb4_3;
    TNode<Uint32T> phi_bb4_4;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_3, &phi_bb4_4);
        ca_.Goto(&block2, phi_bb4_3, phi_bb4_4);
    }

    TNode<Uint32T> phi_bb5_3;
    TNode<Uint32T> phi_bb5_4;
    TNode<Uint32T> tmp10;
    TNode<Uint32T> tmp11;
    TNode<Uint32T> tmp12;
    TNode<Uint32T> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<Int32T> tmp15;
    TNode<Uint32T> tmp16;
    TNode<BoolT> tmp17;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_3, &phi_bb5_4);
        tmp10 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp11 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { phi_bb5_4 }, TNode<Uint32T> { tmp10 });
        tmp12 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp13 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { phi_bb5_3 }, TNode<Uint32T> { tmp12 });
        tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp15 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp1, tmp14 });
        tmp16 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp15 });
        tmp17 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { tmp13 }, TNode<Uint32T> { tmp16 });
        ca_.Branch(tmp17, &block8, std::vector<compiler::Node*> { phi_bb5_3 }, &block9, std::vector<compiler::Node*> { phi_bb5_3 });
    }

    TNode<Uint32T> phi_bb8_3;
    TNode<UintPtrT> tmp18;
    TNode<Uint16T> tmp19;
    TNode<BoolT> tmp20;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_3);
        tmp18 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { phi_bb8_3 });
        tmp19 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String> { tmp1 }, TNode<UintPtrT> { tmp18 });
        tmp20 = IsLeadSurrogate_0(state_, TNode<Uint16T> { tmp19 });
        ca_.Goto(&block10, phi_bb8_3, tmp20);
    }

    TNode<Uint32T> phi_bb9_3;
    TNode<BoolT> tmp21;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_3);
        tmp21 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block10, phi_bb9_3, tmp21);
    }

    TNode<Uint32T> phi_bb10_3;
    TNode<BoolT> phi_bb10_6;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_3, &phi_bb10_6);
        ca_.Branch(phi_bb10_6, &block11, std::vector<compiler::Node*> { phi_bb10_3 }, &block12, std::vector<compiler::Node*> { phi_bb10_3 });
    }

    TNode<Uint32T> phi_bb11_3;
    TNode<Uint32T> tmp22;
    TNode<Uint32T> tmp23;
    TNode<UintPtrT> tmp24;
    TNode<Uint16T> tmp25;
    TNode<BoolT> tmp26;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_3);
        tmp22 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp23 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { phi_bb11_3 }, TNode<Uint32T> { tmp22 });
        tmp24 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { tmp23 });
        tmp25 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String> { tmp1 }, TNode<UintPtrT> { tmp24 });
        tmp26 = IsTrailSurrogate_0(state_, TNode<Uint16T> { tmp25 });
        ca_.Goto(&block13, phi_bb11_3, tmp26);
    }

    TNode<Uint32T> phi_bb12_3;
    TNode<BoolT> tmp27;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_3);
        tmp27 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block13, phi_bb12_3, tmp27);
    }

    TNode<Uint32T> phi_bb13_3;
    TNode<BoolT> phi_bb13_6;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_3, &phi_bb13_6);
        ca_.Branch(phi_bb13_6, &block6, std::vector<compiler::Node*> { phi_bb13_3 }, &block7, std::vector<compiler::Node*> { phi_bb13_3 });
    }

    TNode<Uint32T> phi_bb6_3;
    TNode<Uint32T> tmp28;
    TNode<Uint32T> tmp29;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_3);
        tmp28 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp29 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { phi_bb6_3 }, TNode<Uint32T> { tmp28 });
        ca_.Goto(&block14, tmp29);
    }

    TNode<Uint32T> phi_bb7_3;
    TNode<Uint32T> tmp30;
    TNode<Uint32T> tmp31;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_3);
        tmp30 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp31 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { phi_bb7_3 }, TNode<Uint32T> { tmp30 });
        ca_.Goto(&block14, tmp31);
    }

    TNode<Uint32T> phi_bb14_3;
    if (block14.is_used()) {
        ca_.Bind(&block14, &phi_bb14_3);
        ca_.Goto(&block3, phi_bb14_3, tmp11);
    }

    TNode<Uint32T> phi_bb2_3;
    TNode<Uint32T> phi_bb2_4;
    TNode<IntPtrT> tmp32;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_3, &phi_bb2_4);
        tmp32 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference { parameter0, tmp32 }, phi_bb2_3);
        CodeStubAssembler(state_).Return(phi_bb2_4);
    }
}

TF_BUILTIN(WasmStringViewIterRewind, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<WasmStringViewIter> parameter0 = UncheckedParameter<WasmStringViewIter>(Descriptor::kView);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kCodepoints);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, BoolT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<String> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Uint32T> tmp3;
    TNode<Uint32T> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<Int32T> tmp6;
    TNode<Int32T> tmp7;
    TNode<BoolT> tmp8;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference { parameter0, tmp0 });
        tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp3 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { parameter0, tmp2 });
        tmp4 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp6 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp1, tmp5 });
        tmp7 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp8 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T> { tmp6 }, TNode<Int32T> { tmp7 });
        ca_.Branch(tmp8, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp9;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp9 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        CodeStubAssembler(state_).Return(tmp9);
    }

    if (block2.is_used()) {
        ca_.Bind(&block2);
        ca_.Goto(&block5, tmp3, tmp4);
    }

    TNode<Uint32T> phi_bb5_3;
    TNode<Uint32T> phi_bb5_4;
    TNode<BoolT> tmp10;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_3, &phi_bb5_4);
        tmp10 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { phi_bb5_4 }, TNode<Uint32T> { parameter1 });
        ca_.Branch(tmp10, &block3, std::vector<compiler::Node*> { phi_bb5_3, phi_bb5_4 }, &block4, std::vector<compiler::Node*> { phi_bb5_3, phi_bb5_4 });
    }

    TNode<Uint32T> phi_bb3_3;
    TNode<Uint32T> phi_bb3_4;
    TNode<Uint32T> tmp11;
    TNode<BoolT> tmp12;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_3, &phi_bb3_4);
        tmp11 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp12 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb3_3 }, TNode<Uint32T> { tmp11 });
        ca_.Branch(tmp12, &block6, std::vector<compiler::Node*> { phi_bb3_3, phi_bb3_4 }, &block7, std::vector<compiler::Node*> { phi_bb3_3, phi_bb3_4 });
    }

    TNode<Uint32T> phi_bb6_3;
    TNode<Uint32T> phi_bb6_4;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_3, &phi_bb6_4);
        ca_.Goto(&block4, phi_bb6_3, phi_bb6_4);
    }

    TNode<Uint32T> phi_bb7_3;
    TNode<Uint32T> phi_bb7_4;
    TNode<Uint32T> tmp13;
    TNode<Uint32T> tmp14;
    TNode<Uint32T> tmp15;
    TNode<BoolT> tmp16;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_3, &phi_bb7_4);
        tmp13 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp14 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { phi_bb7_4 }, TNode<Uint32T> { tmp13 });
        tmp15 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp16 = CodeStubAssembler(state_).Uint32GreaterThanOrEqual(TNode<Uint32T> { phi_bb7_3 }, TNode<Uint32T> { tmp15 });
        ca_.Branch(tmp16, &block10, std::vector<compiler::Node*> { phi_bb7_3 }, &block11, std::vector<compiler::Node*> { phi_bb7_3 });
    }

    TNode<Uint32T> phi_bb10_3;
    TNode<Uint32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<Uint16T> tmp20;
    TNode<BoolT> tmp21;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_3);
        tmp17 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp18 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { phi_bb10_3 }, TNode<Uint32T> { tmp17 });
        tmp19 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { tmp18 });
        tmp20 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String> { tmp1 }, TNode<UintPtrT> { tmp19 });
        tmp21 = IsTrailSurrogate_0(state_, TNode<Uint16T> { tmp20 });
        ca_.Goto(&block12, phi_bb10_3, tmp21);
    }

    TNode<Uint32T> phi_bb11_3;
    TNode<BoolT> tmp22;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_3);
        tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block12, phi_bb11_3, tmp22);
    }

    TNode<Uint32T> phi_bb12_3;
    TNode<BoolT> phi_bb12_6;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_3, &phi_bb12_6);
        ca_.Branch(phi_bb12_6, &block13, std::vector<compiler::Node*> { phi_bb12_3 }, &block14, std::vector<compiler::Node*> { phi_bb12_3 });
    }

    TNode<Uint32T> phi_bb13_3;
    TNode<Uint32T> tmp23;
    TNode<Uint32T> tmp24;
    TNode<UintPtrT> tmp25;
    TNode<Uint16T> tmp26;
    TNode<BoolT> tmp27;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_3);
        tmp23 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp24 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { phi_bb13_3 }, TNode<Uint32T> { tmp23 });
        tmp25 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { tmp24 });
        tmp26 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String> { tmp1 }, TNode<UintPtrT> { tmp25 });
        tmp27 = IsLeadSurrogate_0(state_, TNode<Uint16T> { tmp26 });
        ca_.Goto(&block15, phi_bb13_3, tmp27);
    }

    TNode<Uint32T> phi_bb14_3;
    TNode<BoolT> tmp28;
    if (block14.is_used()) {
        ca_.Bind(&block14, &phi_bb14_3);
        tmp28 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block15, phi_bb14_3, tmp28);
    }

    TNode<Uint32T> phi_bb15_3;
    TNode<BoolT> phi_bb15_6;
    if (block15.is_used()) {
        ca_.Bind(&block15, &phi_bb15_3, &phi_bb15_6);
        ca_.Branch(phi_bb15_6, &block8, std::vector<compiler::Node*> { phi_bb15_3 }, &block9, std::vector<compiler::Node*> { phi_bb15_3 });
    }

    TNode<Uint32T> phi_bb8_3;
    TNode<Uint32T> tmp29;
    TNode<Uint32T> tmp30;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_3);
        tmp29 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp30 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { phi_bb8_3 }, TNode<Uint32T> { tmp29 });
        ca_.Goto(&block16, tmp30);
    }

    TNode<Uint32T> phi_bb9_3;
    TNode<Uint32T> tmp31;
    TNode<Uint32T> tmp32;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_3);
        tmp31 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp32 = CodeStubAssembler(state_).Uint32Sub(TNode<Uint32T> { phi_bb9_3 }, TNode<Uint32T> { tmp31 });
        ca_.Goto(&block16, tmp32);
    }

    TNode<Uint32T> phi_bb16_3;
    if (block16.is_used()) {
        ca_.Bind(&block16, &phi_bb16_3);
        ca_.Goto(&block5, phi_bb16_3, tmp14);
    }

    TNode<Uint32T> phi_bb4_3;
    TNode<Uint32T> phi_bb4_4;
    TNode<IntPtrT> tmp33;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_3, &phi_bb4_4);
        tmp33 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference { parameter0, tmp33 }, phi_bb4_3);
        CodeStubAssembler(state_).Return(phi_bb4_4);
    }
}

TF_BUILTIN(WasmStringViewIterSlice, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<WasmStringViewIter> parameter0 = UncheckedParameter<WasmStringViewIter>(Descriptor::kView);
    USE(parameter0);
    TNode<Uint32T> parameter1 = UncheckedParameter<Uint32T>(Descriptor::kCodepoints);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Uint32T, Uint32T, String> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<String> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<Uint32T> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Uint32T> tmp5;
    TNode<Uint32T> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference { parameter0, tmp0 });
        tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp3 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { parameter0, tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp5 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { parameter0, tmp4 });
        tmp6 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block3, tmp5, tmp6);
    }

    TNode<Uint32T> phi_bb3_4;
    TNode<Uint32T> phi_bb3_5;
    TNode<BoolT> tmp7;
    if (block3.is_used()) {
        ca_.Bind(&block3, &phi_bb3_4, &phi_bb3_5);
        tmp7 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { phi_bb3_5 }, TNode<Uint32T> { parameter1 });
        ca_.Branch(tmp7, &block1, std::vector<compiler::Node*> { phi_bb3_4, phi_bb3_5 }, &block2, std::vector<compiler::Node*> { phi_bb3_4, phi_bb3_5 });
    }

    TNode<Uint32T> phi_bb1_4;
    TNode<Uint32T> phi_bb1_5;
    TNode<IntPtrT> tmp8;
    TNode<Int32T> tmp9;
    TNode<Uint32T> tmp10;
    TNode<BoolT> tmp11;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_4, &phi_bb1_5);
        tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp9 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp1, tmp8 });
        tmp10 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp9 });
        tmp11 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { phi_bb1_4 }, TNode<Uint32T> { tmp10 });
        ca_.Branch(tmp11, &block4, std::vector<compiler::Node*> { phi_bb1_4, phi_bb1_5 }, &block5, std::vector<compiler::Node*> { phi_bb1_4, phi_bb1_5 });
    }

    TNode<Uint32T> phi_bb4_4;
    TNode<Uint32T> phi_bb4_5;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_4, &phi_bb4_5);
        ca_.Goto(&block2, phi_bb4_4, phi_bb4_5);
    }

    TNode<Uint32T> phi_bb5_4;
    TNode<Uint32T> phi_bb5_5;
    TNode<Uint32T> tmp12;
    TNode<Uint32T> tmp13;
    TNode<Uint32T> tmp14;
    TNode<Uint32T> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<Int32T> tmp17;
    TNode<Uint32T> tmp18;
    TNode<BoolT> tmp19;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_4, &phi_bb5_5);
        tmp12 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp13 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { phi_bb5_5 }, TNode<Uint32T> { tmp12 });
        tmp14 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp15 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { phi_bb5_4 }, TNode<Uint32T> { tmp14 });
        tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        tmp17 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference { tmp1, tmp16 });
        tmp18 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { tmp17 });
        tmp19 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { tmp15 }, TNode<Uint32T> { tmp18 });
        ca_.Branch(tmp19, &block8, std::vector<compiler::Node*> { phi_bb5_4 }, &block9, std::vector<compiler::Node*> { phi_bb5_4 });
    }

    TNode<Uint32T> phi_bb8_4;
    TNode<UintPtrT> tmp20;
    TNode<Uint16T> tmp21;
    TNode<BoolT> tmp22;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_4);
        tmp20 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { phi_bb8_4 });
        tmp21 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String> { tmp1 }, TNode<UintPtrT> { tmp20 });
        tmp22 = IsLeadSurrogate_0(state_, TNode<Uint16T> { tmp21 });
        ca_.Goto(&block10, phi_bb8_4, tmp22);
    }

    TNode<Uint32T> phi_bb9_4;
    TNode<BoolT> tmp23;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_4);
        tmp23 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block10, phi_bb9_4, tmp23);
    }

    TNode<Uint32T> phi_bb10_4;
    TNode<BoolT> phi_bb10_7;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_4, &phi_bb10_7);
        ca_.Branch(phi_bb10_7, &block11, std::vector<compiler::Node*> { phi_bb10_4 }, &block12, std::vector<compiler::Node*> { phi_bb10_4 });
    }

    TNode<Uint32T> phi_bb11_4;
    TNode<Uint32T> tmp24;
    TNode<Uint32T> tmp25;
    TNode<UintPtrT> tmp26;
    TNode<Uint16T> tmp27;
    TNode<BoolT> tmp28;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_4);
        tmp24 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp25 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { phi_bb11_4 }, TNode<Uint32T> { tmp24 });
        tmp26 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { tmp25 });
        tmp27 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String> { tmp1 }, TNode<UintPtrT> { tmp26 });
        tmp28 = IsTrailSurrogate_0(state_, TNode<Uint16T> { tmp27 });
        ca_.Goto(&block13, phi_bb11_4, tmp28);
    }

    TNode<Uint32T> phi_bb12_4;
    TNode<BoolT> tmp29;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_4);
        tmp29 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block13, phi_bb12_4, tmp29);
    }

    TNode<Uint32T> phi_bb13_4;
    TNode<BoolT> phi_bb13_7;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_4, &phi_bb13_7);
        ca_.Branch(phi_bb13_7, &block6, std::vector<compiler::Node*> { phi_bb13_4 }, &block7, std::vector<compiler::Node*> { phi_bb13_4 });
    }

    TNode<Uint32T> phi_bb6_4;
    TNode<Uint32T> tmp30;
    TNode<Uint32T> tmp31;
    if (block6.is_used()) {
        ca_.Bind(&block6, &phi_bb6_4);
        tmp30 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp31 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { phi_bb6_4 }, TNode<Uint32T> { tmp30 });
        ca_.Goto(&block14, tmp31);
    }

    TNode<Uint32T> phi_bb7_4;
    TNode<Uint32T> tmp32;
    TNode<Uint32T> tmp33;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_4);
        tmp32 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp33 = CodeStubAssembler(state_).Uint32Add(TNode<Uint32T> { phi_bb7_4 }, TNode<Uint32T> { tmp32 });
        ca_.Goto(&block14, tmp33);
    }

    TNode<Uint32T> phi_bb14_4;
    if (block14.is_used()) {
        ca_.Bind(&block14, &phi_bb14_4);
        ca_.Goto(&block3, phi_bb14_4, tmp13);
    }

    TNode<Uint32T> phi_bb2_4;
    TNode<Uint32T> phi_bb2_5;
    TNode<BoolT> tmp34;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_4, &phi_bb2_5);
        tmp34 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { tmp3 }, TNode<Uint32T> { phi_bb2_4 });
        ca_.Branch(tmp34, &block15, std::vector<compiler::Node*> { phi_bb2_4, phi_bb2_5 }, &block16, std::vector<compiler::Node*> { phi_bb2_4, phi_bb2_5 });
    }

    TNode<Uint32T> phi_bb15_4;
    TNode<Uint32T> phi_bb15_5;
    TNode<String> tmp35;
    if (block15.is_used()) {
        ca_.Bind(&block15, &phi_bb15_4, &phi_bb15_5);
        tmp35 = kEmptyString_0(state_);
        ca_.Goto(&block17, phi_bb15_4, phi_bb15_5, tmp35);
    }

    TNode<Uint32T> phi_bb16_4;
    TNode<Uint32T> phi_bb16_5;
    TNode<UintPtrT> tmp36;
    TNode<UintPtrT> tmp37;
    TNode<String> tmp38;
    if (block16.is_used()) {
        ca_.Bind(&block16, &phi_bb16_4, &phi_bb16_5);
        tmp36 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { tmp3 });
        tmp37 = Convert_uintptr_uint32_0(state_, TNode<Uint32T> { phi_bb16_4 });
        tmp38 = StringBuiltinsAssembler(state_).SubString(TNode<String> { tmp1 }, TNode<UintPtrT> { tmp36 }, TNode<UintPtrT> { tmp37 });
        ca_.Goto(&block17, phi_bb16_4, phi_bb16_5, tmp38);
    }

    TNode<Uint32T> phi_bb17_4;
    TNode<Uint32T> phi_bb17_5;
    TNode<String> phi_bb17_6;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_4, &phi_bb17_5, &phi_bb17_6);
        CodeStubAssembler(state_).Return(phi_bb17_6);
    }
}

TF_BUILTIN(WasmIntToString, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Int32T> parameter0 = UncheckedParameter<Int32T>(Descriptor::kX);
    USE(parameter0);
    TNode<Int32T> parameter1 = UncheckedParameter<Int32T>(Descriptor::kRadix);
    USE(parameter1);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Int32T> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0xaull));
        tmp1 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T> { parameter1 }, TNode<Int32T> { tmp0 });
        ca_.Branch(tmp1, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<Smi> tmp2;
    TNode<Int32T> tmp3;
    TNode<BoolT> tmp4;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp2 = CodeStubAssembler(state_).SmiFromInt32(TNode<Int32T> { parameter0 });
        tmp3 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { tmp2 });
        tmp4 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T> { parameter0 }, TNode<Int32T> { tmp3 });
        ca_.Branch(tmp4, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    TNode<String> tmp5;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp5 = CodeStubAssembler(state_).NumberToString(TNode<Number> { tmp2 });
        CodeStubAssembler(state_).Return(tmp5);
    }

    TNode<String> tmp6;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp6 = IntToDecimalString_0(state_, TNode<Int32T> { parameter0 });
        CodeStubAssembler(state_).Return(tmp6);
    }

    TNode<Int32T> tmp7;
    TNode<BoolT> tmp8;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp7 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x2ull));
        tmp8 = CodeStubAssembler(state_).Int32LessThan(TNode<Int32T> { parameter1 }, TNode<Int32T> { tmp7 });
        ca_.Branch(tmp8, &block7, std::vector<compiler::Node*> {}, &block8, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp9;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block9, tmp9);
    }

    TNode<Int32T> tmp10;
    TNode<BoolT> tmp11;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp10 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x24ull));
        tmp11 = CodeStubAssembler(state_).Int32GreaterThan(TNode<Int32T> { parameter1 }, TNode<Int32T> { tmp10 });
        ca_.Goto(&block9, tmp11);
    }

    TNode<BoolT> phi_bb9_3;
    if (block9.is_used()) {
        ca_.Bind(&block9, &phi_bb9_3);
        ca_.Branch(phi_bb9_3, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    TNode<WasmTrustedInstanceData> tmp12;
    TNode<NativeContext> tmp13;
    TNode<Smi> tmp14;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp12 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp13 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp12 });
        tmp14 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kToRadixFormatRange);
        CodeStubAssembler(state_).CallRuntime(Runtime::kThrowRangeError, tmp13, tmp14);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Uint32T> tmp15;
    TNode<String> tmp16;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp15 = CodeStubAssembler(state_).Unsigned(TNode<Int32T> { parameter1 });
        tmp16 = IntToString_0(state_, TNode<Int32T> { parameter0 }, TNode<Uint32T> { tmp15 });
        CodeStubAssembler(state_).Return(tmp16);
    }
}

TF_BUILTIN(WasmStringToDouble, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kS);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    TNode<Uint32T> tmp1;
    TNode<BoolT> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp1 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { parameter0, tmp0 });
        tmp2 = IsIntegerIndex_0(state_, TNode<Uint32T> { tmp1 });
        ca_.Branch(tmp2, &block3, std::vector<compiler::Node*> {}, &block4, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp3;
    TNode<Uint32T> tmp4;
    TNode<BoolT> tmp5;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp3 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32<base::BitField<uint32_t, 26, 6, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp1)));
        tmp4 = FromConstexpr_uint32_constexpr_uint32_0(state_, Name::kMaxCachedArrayIndexLength);
        tmp5 = CodeStubAssembler(state_).Uint32LessThan(TNode<Uint32T> { tmp3 }, TNode<Uint32T> { tmp4 });
        ca_.Goto(&block5, tmp5);
    }

    TNode<BoolT> tmp6;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block5, tmp6);
    }

    TNode<BoolT> phi_bb5_3;
    if (block5.is_used()) {
        ca_.Bind(&block5, &phi_bb5_3);
        ca_.Branch(phi_bb5_3, &block1, std::vector<compiler::Node*> {}, &block2, std::vector<compiler::Node*> {});
    }

    TNode<Uint32T> tmp7;
    TNode<Int32T> tmp8;
    TNode<Float64T> tmp9;
    if (block1.is_used()) {
        ca_.Bind(&block1);
        tmp7 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32<base::BitField<uint32_t, 2, 24, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp1)));
        tmp8 = CodeStubAssembler(state_).Signed(TNode<Uint32T> { tmp7 });
        tmp9 = Convert_float64_int32_0(state_, TNode<Int32T> { tmp8 });
        CodeStubAssembler(state_).Return(tmp9);
    }

    TNode<String> tmp10;
    TNode<Float64T> tmp11;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp10 = Flatten_0(state_, TNode<String> { parameter0 });
        tmp11 = WasmBuiltinsAssembler(state_).StringToFloat64(TNode<String> { tmp10 });
        CodeStubAssembler(state_).Return(tmp11);
    }
}

TF_BUILTIN(WasmStringFromCodePoint, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Uint32T> parameter0 = UncheckedParameter<Uint32T>(Descriptor::kCodePoint);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<NativeContext> tmp0;
    TNode<Number> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = LoadContextFromFrame_0(state_);
        tmp1 = ca_.CallBuiltin<Number>(Builtin::kWasmUint32ToNumber, TNode<Object>(), parameter0);
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmStringFromCodePoint, tmp0, tmp1);
    }
}

TF_BUILTIN(WasmStringHash, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<String> parameter0 = UncheckedParameter<String>(Descriptor::kString);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    TNode<Smi> tmp1;
    TNode<Int32T> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kNoContext_0(state_);
        tmp1 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kWasmStringHash, tmp0, parameter0));
        tmp2 = CodeStubAssembler(state_).SmiToInt32(TNode<Smi> { tmp1 });
        CodeStubAssembler(state_).Return(tmp2);
    }
}

TF_BUILTIN(WasmAnyConvertExtern, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Object> parameter0 = UncheckedParameter<Object>(Descriptor::kExternObject);
    USE(parameter0);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmTrustedInstanceData> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Smi> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = WasmBuiltinsAssembler(state_).LoadInstanceDataFromFrame();
        tmp1 = WasmBuiltinsAssembler(state_).LoadContextFromInstanceData(TNode<WasmTrustedInstanceData> { tmp0 });
        tmp2 = CodeStubAssembler(state_).SmiConstant(wasm::kWasmAnyRef.raw_bit_field());
        CodeStubAssembler(state_).TailCallRuntime(Runtime::kWasmJSToWasmObject, tmp1, parameter0, tmp2);
    }
}

TF_BUILTIN(WasmFastApiCallTypeCheckAndUpdateIC, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<WasmFastApiCallData> parameter1 = UncheckedParameter<WasmFastApiCallData>(Descriptor::kData);
    USE(parameter1);
    TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kReceiver);
    USE(parameter2);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSReceiver> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_JSReceiver_1(state_, TNode<Context> { parameter0 }, TNode<Object> { parameter2 }, &label1);
        ca_.Goto(&block5);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block6);
        }
    }

    TNode<Smi> tmp2;
    TNode<Smi> tmp3;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp2 = CodeStubAssembler(state_).SmiConstant(MessageTemplate::kIllegalInvocation);
        tmp3 = Convert_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        CodeStubAssembler(state_).CallRuntime(Runtime::kWasmThrowTypeError, parameter0, tmp2, tmp3);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Int32T> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<HeapObject> tmp6;
    TNode<JSReceiver> tmp7;
    TNode<Int32T> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<Map> tmp11;
    TNode<MaybeObject> tmp12;
    TNode<Smi> tmp13;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp4 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ModifyThreadInWasmFlag_0(state_, TNode<Int32T> { tmp4 });
        tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        tmp6 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference { parameter1, tmp5 });
        tmp7 = CallOrConstructBuiltinsAssembler(state_).GetCompatibleReceiver(
            TNode<JSReceiver> { tmp0 }, TNode<HeapObject> { tmp6 }, TNode<Context> { parameter0 });
        tmp8 = FromConstexpr_int32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        ModifyThreadInWasmFlag_0(state_, TNode<Int32T> { tmp8 });
        tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp11 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { tmp0, tmp10 });
        tmp12 = StrongToWeak_Map_0(state_, TNode<Map> { tmp11 });
        CodeStubAssembler(state_).StoreReference<MaybeObject>(CodeStubAssembler::Reference { parameter1, tmp9 }, tmp12);
        tmp13 = FromConstexpr_Smi_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        CodeStubAssembler(state_).Return(tmp13);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=341&c=12
TNode<BoolT> Is_WasmFuncRef_HeapObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmFuncRef> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_WasmFuncRef_0(state_, TNode<HeapObject> { p_o }, &label1);
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=341&c=38
TNode<BoolT> Is_WasmNull_HeapObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmNull> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_WasmNull_0(state_, TNode<HeapObject> { p_o }, &label1);
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=341&c=61
TNode<BoolT> Is_Tuple2_HeapObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Tuple2> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_Tuple2_0(state_, TNode<HeapObject> { p_o }, &label1);
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=373&c=10
TNode<BoolT> Is_WasmFuncRef_WasmFuncRef_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<WasmFuncRef> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmFuncRef> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_WasmFuncRef_0(state_, TNode<HeapObject> { p_o }, &label1);
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=373&c=36
TNode<BoolT> Is_WasmNull_WasmFuncRef_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<WasmFuncRef> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmNull> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_WasmNull_0(state_, TNode<HeapObject> { p_o }, &label1);
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=402&c=12
TNode<BoolT> Is_WasmFuncRef_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmFuncRef> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_WasmFuncRef_1(state_, TNode<Context> { p_context }, TNode<Object> { p_o }, &label1);
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

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=512&c=7
TNode<IntPtrT> Convert_intptr_constexpr_int32_0(compiler::CodeAssemblerState* state_, int32_t p_i)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<IntPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_intptr_constexpr_int32_0(state_, p_i);
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<IntPtrT> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=582&c=20
TNode<WasmArray> UnsafeCast_WasmArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<WasmArray> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = TORQUE_CAST(TNode<Object> { p_o });
        ca_.Goto(&block6);
    }

    ca_.Bind(&block6);
    return TNode<WasmArray> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1004&c=12
TNode<String> AllocateSeqTwoByteString_SliceIterator_char16_ConstReference_char16_0(
    compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length, TorqueStructSliceIterator_char16_ConstReference_char16_0 p_content)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Uint32T> tmp0;
    TNode<BoolT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uint32_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp1 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T> { p_length }, TNode<Uint32T> { tmp0 });
        ca_.Branch(tmp1, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    TNode<String> tmp2;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp2 = kEmptyString_0(state_);
        ca_.Goto(&block1, tmp2);
    }

    TNode<SeqTwoByteString> tmp3;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp3 = AllocateNonEmptySeqTwoByteString_SliceIterator_char16_ConstReference_char16_0(state_, TNode<Uint32T> { p_length },
            TorqueStructSliceIterator_char16_ConstReference_char16_0 {
                TNode<Object> { p_content.object }, TNode<IntPtrT> { p_content.start }, TNode<IntPtrT> { p_content.end }, TorqueStructUnsafe_0 {} });
        ca_.Goto(&block1, tmp3);
    }

    TNode<String> phi_bb1_4;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_4);
        ca_.Goto(&block4);
    }

    ca_.Bind(&block4);
    return TNode<String> { phi_bb1_4 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1008&c=10
TNode<SeqOneByteString> AllocateNonEmptySeqOneByteString_TwoByteToOneByteIterator_0(
    compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length, TorqueStructTwoByteToOneByteIterator_0 p_content)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Map> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Int32T> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<BoolT> tmp7;
    TNode<BoolT> tmp8;
    TNode<HeapObject> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<SeqOneByteString> tmp14;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kSeqOneByteStringMap_0(state_);
        tmp1 = kNameEmptyHashField_0(state_);
        tmp2 = CodeStubAssembler(state_).Signed(TNode<Uint32T> { p_length });
        tmp3 = Convert_intptr_int32_0(state_, TNode<Int32T> { tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp5 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT> { tmp4 }, TNode<IntPtrT> { tmp3 }, kUInt8Size);
        tmp6 = AlignTagged_0(state_, TNode<IntPtrT> { tmp5 });
        tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        tmp9 = AllocateFromNew_0(state_, TNode<IntPtrT> { tmp6 }, TNode<Map> { tmp0 }, TNode<BoolT> { tmp7 }, TNode<BoolT> { tmp8 });
        tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference { tmp9, tmp10 }, tmp0);
        tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference { tmp9, tmp11 }, tmp1);
        tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference { tmp9, tmp12 }, tmp2);
        tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        InitializeFieldsFromIterator_char8_TwoByteToOneByteIterator_0(state_,
            TorqueStructSlice_char8_MutableReference_char8_0 {
                TNode<Object> { tmp9 }, TNode<IntPtrT> { tmp13 }, TNode<IntPtrT> { tmp3 }, TorqueStructUnsafe_0 {} },
            TorqueStructTwoByteToOneByteIterator_0 {
                TNode<Object> { p_content.object }, TNode<IntPtrT> { p_content.start }, TNode<IntPtrT> { p_content.end } });
        tmp14 = TORQUE_CAST(TNode<HeapObject> { tmp9 });
        ca_.Goto(&block9);
    }

    ca_.Bind(&block9);
    return TNode<SeqOneByteString> { tmp14 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1035&c=26
TorqueStructSlice_char16_ConstReference_char16_0 NewConstSlice_char16_0(
    compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1, tmp2) = (TorqueStructSlice_char16_ConstReference_char16_0 {
                                          TNode<Object> { p_object }, TNode<IntPtrT> { p_offset }, TNode<IntPtrT> { p_length }, TorqueStructUnsafe_0 {} })
                                         .Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructSlice_char16_ConstReference_char16_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp1 }, TNode<IntPtrT> { tmp2 },
        TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1142&c=26
TorqueStructSlice_char16_MutableReference_char16_0 NewMutableSlice_char16_0(
    compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Object> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        std::tie(tmp0, tmp1, tmp2) = (TorqueStructSlice_char16_MutableReference_char16_0 {
                                          TNode<Object> { p_object }, TNode<IntPtrT> { p_offset }, TNode<IntPtrT> { p_length }, TorqueStructUnsafe_0 {} })
                                         .Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructSlice_char16_MutableReference_char16_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp1 }, TNode<IntPtrT> { tmp2 },
        TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1151&c=39
TNode<Uint16T> Convert_uint16_char8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_i)
{
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
    return TNode<Uint16T> { p_i };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1357&c=14
TNode<SeqOneByteString> AllocateNonEmptySeqOneByteString_SliceIterator_char8_ConstReference_char8_0(
    compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length, TorqueStructSliceIterator_char8_ConstReference_char8_0 p_content)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Map> tmp0;
    TNode<Uint32T> tmp1;
    TNode<Int32T> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<BoolT> tmp7;
    TNode<BoolT> tmp8;
    TNode<HeapObject> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<SeqOneByteString> tmp14;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kSeqOneByteStringMap_0(state_);
        tmp1 = kNameEmptyHashField_0(state_);
        tmp2 = CodeStubAssembler(state_).Signed(TNode<Uint32T> { p_length });
        tmp3 = Convert_intptr_int32_0(state_, TNode<Int32T> { tmp2 });
        tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        tmp5 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT> { tmp4 }, TNode<IntPtrT> { tmp3 }, kUInt8Size);
        tmp6 = AlignTagged_0(state_, TNode<IntPtrT> { tmp5 });
        tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        tmp9 = AllocateFromNew_0(state_, TNode<IntPtrT> { tmp6 }, TNode<Map> { tmp0 }, TNode<BoolT> { tmp7 }, TNode<BoolT> { tmp8 });
        tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference { tmp9, tmp10 }, tmp0);
        tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
        CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference { tmp9, tmp11 }, tmp1);
        tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference { tmp9, tmp12 }, tmp2);
        tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
        InitializeFieldsFromIterator_char8_SliceIterator_char8_ConstReference_char8_0(state_,
            TorqueStructSlice_char8_MutableReference_char8_0 {
                TNode<Object> { tmp9 }, TNode<IntPtrT> { tmp13 }, TNode<IntPtrT> { tmp3 }, TorqueStructUnsafe_0 {} },
            TorqueStructSliceIterator_char8_ConstReference_char8_0 {
                TNode<Object> { p_content.object }, TNode<IntPtrT> { p_content.start }, TNode<IntPtrT> { p_content.end }, TorqueStructUnsafe_0 {} });
        tmp14 = TORQUE_CAST(TNode<HeapObject> { tmp9 });
        ca_.Goto(&block9);
    }

    ca_.Bind(&block9);
    return TNode<SeqOneByteString> { tmp14 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1556&c=23
TNode<MaybeObject> StrongToWeak_Map_0(compiler::CodeAssemblerState* state_, TNode<Map> p_x)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<MaybeObject> tmp0;
    TNode<MaybeObject> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).MakeWeak(TNode<HeapObject> { p_x });
        tmp1 = (TNode<MaybeObject> { tmp0 });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<MaybeObject> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_WasmCodePointer_0 NewOffHeapReference_WasmCodePointer_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<TaggedIndex> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kZeroBitPattern_0(state_);
        tmp1 = Convert_WasmCodePointer_RawPtr_WasmCodePointer_0(state_, TNode<RawPtrT> { p_ptr });
        tmp2 = Convert_intptr_WasmCodePointer_0(state_, TNode<RawPtrT> { tmp1 });
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
        tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp2 }, TNode<IntPtrT> { tmp3 });
        std::tie(tmp5, tmp6) = (TorqueStructReference_WasmCodePointer_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp4 }, TorqueStructUnsafe_0 {} }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_WasmCodePointer_0 { TNode<Object> { tmp5 }, TNode<IntPtrT> { tmp6 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_int32_0 NewOffHeapReference_int32_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<TaggedIndex> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kZeroBitPattern_0(state_);
        tmp1 = Convert_WasmCodePointer_RawPtr_int32_0(state_, TNode<RawPtrT> { p_ptr });
        tmp2 = Convert_intptr_WasmCodePointer_0(state_, TNode<RawPtrT> { tmp1 });
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
        tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp2 }, TNode<IntPtrT> { tmp3 });
        std::tie(tmp5, tmp6) = (TorqueStructReference_int32_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp4 }, TorqueStructUnsafe_0 {} }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_int32_0 { TNode<Object> { tmp5 }, TNode<IntPtrT> { tmp6 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_bool_0 NewOffHeapReference_bool_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<TaggedIndex> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kZeroBitPattern_0(state_);
        tmp1 = Convert_WasmCodePointer_RawPtr_bool_0(state_, TNode<RawPtrT> { p_ptr });
        tmp2 = Convert_intptr_WasmCodePointer_0(state_, TNode<RawPtrT> { tmp1 });
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
        tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp2 }, TNode<IntPtrT> { tmp3 });
        std::tie(tmp5, tmp6) = (TorqueStructReference_bool_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp4 }, TorqueStructUnsafe_0 {} }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_bool_0 { TNode<Object> { tmp5 }, TNode<IntPtrT> { tmp6 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_RawPtr_intptr_0 NewOffHeapReference_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<TaggedIndex> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kZeroBitPattern_0(state_);
        tmp1 = Convert_WasmCodePointer_RawPtr_RawPtr_intptr_0(state_, TNode<RawPtrT> { p_ptr });
        tmp2 = Convert_intptr_WasmCodePointer_0(state_, TNode<RawPtrT> { tmp1 });
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
        tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp2 }, TNode<IntPtrT> { tmp3 });
        std::tie(tmp5, tmp6) = (TorqueStructReference_RawPtr_intptr_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp4 }, TorqueStructUnsafe_0 {} }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_RawPtr_intptr_0 { TNode<Object> { tmp5 }, TNode<IntPtrT> { tmp6 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_int64_0 NewOffHeapReference_int64_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<TaggedIndex> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kZeroBitPattern_0(state_);
        tmp1 = Convert_WasmCodePointer_RawPtr_int64_0(state_, TNode<RawPtrT> { p_ptr });
        tmp2 = Convert_intptr_WasmCodePointer_0(state_, TNode<RawPtrT> { tmp1 });
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
        tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp2 }, TNode<IntPtrT> { tmp3 });
        std::tie(tmp5, tmp6) = (TorqueStructReference_int64_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp4 }, TorqueStructUnsafe_0 {} }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_int64_0 { TNode<Object> { tmp5 }, TNode<IntPtrT> { tmp6 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_float64_0 NewOffHeapReference_float64_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<TaggedIndex> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kZeroBitPattern_0(state_);
        tmp1 = Convert_WasmCodePointer_RawPtr_float64_0(state_, TNode<RawPtrT> { p_ptr });
        tmp2 = Convert_intptr_WasmCodePointer_0(state_, TNode<RawPtrT> { tmp1 });
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
        tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp2 }, TNode<IntPtrT> { tmp3 });
        std::tie(tmp5, tmp6) = (TorqueStructReference_float64_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp4 }, TorqueStructUnsafe_0 {} }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_float64_0 { TNode<Object> { tmp5 }, TNode<IntPtrT> { tmp6 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_float32_0 NewOffHeapReference_float32_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<TaggedIndex> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kZeroBitPattern_0(state_);
        tmp1 = Convert_WasmCodePointer_RawPtr_float32_0(state_, TNode<RawPtrT> { p_ptr });
        tmp2 = Convert_intptr_WasmCodePointer_0(state_, TNode<RawPtrT> { tmp1 });
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
        tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp2 }, TNode<IntPtrT> { tmp3 });
        std::tie(tmp5, tmp6) = (TorqueStructReference_float32_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp4 }, TorqueStructUnsafe_0 {} }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_float32_0 { TNode<Object> { tmp5 }, TNode<IntPtrT> { tmp6 }, TorqueStructUnsafe_0 {} };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_uintptr_0 NewOffHeapReference_uintptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<TaggedIndex> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<Object> tmp5;
    TNode<IntPtrT> tmp6;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = kZeroBitPattern_0(state_);
        tmp1 = Convert_WasmCodePointer_RawPtr_uintptr_0(state_, TNode<RawPtrT> { p_ptr });
        tmp2 = Convert_intptr_WasmCodePointer_0(state_, TNode<RawPtrT> { tmp1 });
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, kHeapObjectTag);
        tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT> { tmp2 }, TNode<IntPtrT> { tmp3 });
        std::tie(tmp5, tmp6) = (TorqueStructReference_uintptr_0 { TNode<Object> { tmp0 }, TNode<IntPtrT> { tmp4 }, TorqueStructUnsafe_0 {} }).Flatten();
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TorqueStructReference_uintptr_0 { TNode<Object> { tmp5 }, TNode<IntPtrT> { tmp6 }, TorqueStructUnsafe_0 {} };
}

} // namespace internal
} // namespace v8
