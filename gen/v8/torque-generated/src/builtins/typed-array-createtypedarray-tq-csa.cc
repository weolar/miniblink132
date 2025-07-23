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
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/arraybuffer-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/js-array-buffer-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=23&c=1
TNode<JSTypedArray> AllocateTypedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, bool p_isOnHeap, TNode<Map> p_map,
    TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_byteOffset, TNode<UintPtrT> p_byteLength, TNode<UintPtrT> p_length, TNode<BoolT> p_isLengthTracking)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<ByteArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    if (block0.is_used()) {
        ca_.Bind(&block0);
        if ((p_isOnHeap)) {
            ca_.Goto(&block2);
        } else {
            ca_.Goto(&block3);
        }
    }

    TNode<ByteArray> tmp0;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp0 = CodeStubAssembler(state_).AllocateByteArray(TNode<UintPtrT> { p_byteLength });
        ca_.Goto(&block4, tmp0);
    }

    TNode<ByteArray> tmp1;
    TNode<RawPtrT> tmp2;
    TNode<UintPtrT> tmp3;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp1 = kEmptyByteArray_0(state_);
        tmp2 = CodeStubAssembler(state_).LoadJSArrayBufferBackingStorePtr(TNode<JSArrayBuffer> { p_buffer });
        tmp3 = Convert_uintptr_WasmCodePointer_0(state_, TNode<RawPtrT> { tmp2 });
        ca_.Goto(&block4, tmp1);
    }

    TNode<ByteArray> phi_bb4_7;
    TNode<JSObject> tmp4;
    TNode<JSTypedArray> tmp5;
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_7);
        tmp4 = AllocateFastOrSlowJSObjectFromMap_0(state_, TNode<Context> { p_context }, TNode<Map> { p_map });
        tmp5 = UnsafeCast_JSTypedArray_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp4 });
        tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
        CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference { tmp5, tmp6 }, phi_bb4_7);
        tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        CodeStubAssembler(state_).StoreReference<JSArrayBuffer>(CodeStubAssembler::Reference { tmp5, tmp7 }, p_buffer);
        CodeStubAssembler(state_).StoreJSArrayBufferViewByteOffset(TNode<JSArrayBufferView> { tmp5 }, TNode<UintPtrT> { p_byteOffset });
        ca_.Branch(p_isLengthTracking, &block20, std::vector<compiler::Node*> {}, &block21, std::vector<compiler::Node*> {});
    }

    TNode<UintPtrT> tmp8;
    TNode<UintPtrT> tmp9;
    if (block20.is_used()) {
        ca_.Bind(&block20);
        tmp8 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        CodeStubAssembler(state_).StoreJSArrayBufferViewByteLength(TNode<JSArrayBufferView> { tmp5 }, TNode<UintPtrT> { tmp8 });
        tmp9 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        CodeStubAssembler(state_).StoreJSTypedArrayLength(TNode<JSTypedArray> { tmp5 }, TNode<UintPtrT> { tmp9 });
        ca_.Goto(&block22);
    }

    if (block21.is_used()) {
        ca_.Bind(&block21);
        CodeStubAssembler(state_).StoreJSArrayBufferViewByteLength(TNode<JSArrayBufferView> { tmp5 }, TNode<UintPtrT> { p_byteLength });
        CodeStubAssembler(state_).StoreJSTypedArrayLength(TNode<JSTypedArray> { tmp5 }, TNode<UintPtrT> { p_length });
        ca_.Goto(&block22);
    }

    TNode<IntPtrT> tmp10;
    TNode<Uint32T> tmp11;
    TNode<Uint32T> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<BoolT> tmp14;
    if (block22.is_used()) {
        ca_.Bind(&block22);
        tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        tmp11 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { tmp5, tmp10 });
        tmp12 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<bool, 0, 1, uint32_t>>(
            ca_.UncheckedCast<Word32T>(tmp11), ca_.UncheckedCast<Uint32T>(p_isLengthTracking)));
        CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference { tmp5, tmp10 }, tmp12);
        tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
        tmp14 = IsResizableArrayBuffer_0(state_, TNode<JSArrayBuffer> { p_buffer });
        ca_.Branch(tmp14, &block27, std::vector<compiler::Node*> {}, &block28, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp15;
    TNode<BoolT> tmp16;
    if (block27.is_used()) {
        ca_.Bind(&block27);
        tmp15 = IsSharedArrayBuffer_0(state_, TNode<JSArrayBuffer> { p_buffer });
        tmp16 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp15 });
        ca_.Goto(&block29, tmp16);
    }

    TNode<BoolT> tmp17;
    if (block28.is_used()) {
        ca_.Bind(&block28);
        tmp17 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block29, tmp17);
    }

    TNode<BoolT> phi_bb29_13;
    TNode<Uint32T> tmp18;
    TNode<Uint32T> tmp19;
    if (block29.is_used()) {
        ca_.Bind(&block29, &phi_bb29_13);
        tmp18 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference { tmp5, tmp13 });
        tmp19 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<bool, 1, 1, uint32_t>>(
            ca_.UncheckedCast<Word32T>(tmp18), ca_.UncheckedCast<Uint32T>(phi_bb29_13)));
        CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference { tmp5, tmp13 }, tmp19);
        if ((p_isOnHeap)) {
            ca_.Goto(&block30);
        } else {
            ca_.Goto(&block31);
        }
    }

    if (block30.is_used()) {
        ca_.Bind(&block30);
        TypedArrayBuiltinsAssembler(state_).SetJSTypedArrayOnHeapDataPtr(
            TNode<JSTypedArray> { tmp5 }, TNode<ByteArray> { phi_bb4_7 }, TNode<UintPtrT> { p_byteOffset });
        ca_.Goto(&block32);
    }

    TNode<RawPtrT> tmp20;
    if (block31.is_used()) {
        ca_.Bind(&block31);
        tmp20 = CodeStubAssembler(state_).LoadJSArrayBufferBackingStorePtr(TNode<JSArrayBuffer> { p_buffer });
        TypedArrayBuiltinsAssembler(state_).SetJSTypedArrayOffHeapDataPtr(
            TNode<JSTypedArray> { tmp5 }, TNode<RawPtrT> { tmp20 }, TNode<UintPtrT> { p_byteOffset });
        ca_.Goto(&block32);
    }

    if (block32.is_used()) {
        ca_.Bind(&block32);
        TypedArrayBuiltinsAssembler(state_).SetupTypedArrayEmbedderFields(TNode<JSTypedArray> { tmp5 });
        ca_.Goto(&block37);
    }

    ca_.Bind(&block37);
    return TNode<JSTypedArray> { tmp5 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=84&c=1
TNode<JSTypedArray> TypedArrayInitialize_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, bool p_initialize, TNode<Map> p_map,
    TNode<UintPtrT> p_length, TorqueStructTypedArrayElementsInfo p_elementsInfo, compiler::CodeAssemblerLabel* label_IfRangeError)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<JSTypedArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    TNode<UintPtrT> tmp1;
    TNode<BoolT> tmp2;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
        tmp1 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT> { tmp0 }, TNode<UintPtrT> { p_elementsInfo.sizeLog2 });
        tmp2 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT> { p_length }, TNode<UintPtrT> { tmp1 });
        ca_.Branch(tmp2, &block4, std::vector<compiler::Node*> {}, &block5, std::vector<compiler::Node*> {});
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(label_IfRangeError);
    }

    TNode<UintPtrT> tmp3;
    TNode<Number> tmp4;
    TNode<JSReceiver> tmp5;
    TNode<UintPtrT> tmp6;
    TNode<UintPtrT> tmp7;
    TNode<BoolT> tmp8;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp3 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT> { p_length }, TNode<UintPtrT> { p_elementsInfo.sizeLog2 });
        tmp4 = Convert_Number_uintptr_0(state_, TNode<UintPtrT> { tmp3 });
        tmp5 = GetArrayBufferFunction_0(state_, TNode<Context> { p_context });
        tmp6 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp7 = FromConstexpr_uintptr_constexpr_int31_0(state_, JSTypedArray::kMaxSizeInHeap);
        tmp8 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT> { tmp3 }, TNode<UintPtrT> { tmp7 });
        ca_.Branch(tmp8, &block10, std::vector<compiler::Node*> {}, &block11, std::vector<compiler::Node*> {});
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        if ((p_initialize)) {
            ca_.Goto(&block15);
        } else {
            ca_.Goto(&block16);
        }
    }

    TNode<JSArrayBuffer> tmp9;
    TNode<BoolT> tmp10;
    TNode<JSTypedArray> tmp11;
    if (block11.is_used()) {
        ca_.Bind(&block11);
        tmp9 = TypedArrayBuiltinsAssembler(state_).AllocateEmptyOnHeapBuffer(TNode<Context> { p_context });
        tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        tmp11 = AllocateTypedArray_0(state_, TNode<Context> { p_context }, true, TNode<Map> { p_map }, TNode<JSArrayBuffer> { tmp9 }, TNode<UintPtrT> { tmp6 },
            TNode<UintPtrT> { tmp3 }, TNode<UintPtrT> { p_length }, TNode<BoolT> { tmp10 });
        if ((p_initialize)) {
            ca_.Goto(&block12);
        } else {
            ca_.Goto(&block13);
        }
    }

    TNode<RawPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    if (block12.is_used()) {
        ca_.Bind(&block12);
        tmp12 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray> { tmp11 });
        tmp13 = FromConstexpr_intptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        TypedArrayBuiltinsAssembler(state_).CallCMemset(TNode<RawPtrT> { tmp12 }, TNode<IntPtrT> { tmp13 }, TNode<UintPtrT> { tmp3 });
        ca_.Goto(&block14);
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block14);
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        ca_.Goto(&block2, tmp11);
    }

    TNode<JSReceiver> tmp14;
    if (block15.is_used()) {
        ca_.Bind(&block15);
        tmp14 = CodeStubAssembler(state_).Construct(TNode<Context> { p_context }, TNode<JSReceiver> { tmp5 }, TNode<Object> { tmp4 });
        ca_.Goto(&block7, tmp14);
    }

    TNode<JSFunction> tmp15;
    TNode<Undefined> tmp16;
    TNode<Object> tmp17;
    if (block16.is_used()) {
        ca_.Bind(&block16);
        tmp15 = GetArrayBufferNoInitFunction_0(state_, TNode<Context> { p_context });
        tmp16 = Undefined_0(state_);
        tmp17 = CodeStubAssembler(state_).Call(TNode<Context> { p_context }, TNode<Object> { tmp15 }, TNode<Object> { tmp16 }, TNode<Object> { tmp4 });
        ca_.Goto(&block7, tmp17);
    }

    TNode<Object> phi_bb7_9;
    TNode<JSArrayBuffer> tmp18;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_9);
        compiler::CodeAssemblerLabel label19(&ca_);
        tmp18 = Cast_JSArrayBuffer_1(state_, TNode<Context> { p_context }, TNode<Object> { phi_bb7_9 }, &label19);
        ca_.Goto(&block20);
        if (label19.is_used()) {
            ca_.Bind(&label19);
            ca_.Goto(&block21);
        }
    }

    if (block21.is_used()) {
        ca_.Bind(&block21);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<BoolT> tmp20;
    TNode<JSTypedArray> tmp21;
    if (block20.is_used()) {
        ca_.Bind(&block20);
        tmp20 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        tmp21 = AllocateTypedArray_0(state_, TNode<Context> { p_context }, false, TNode<Map> { p_map }, TNode<JSArrayBuffer> { tmp18 },
            TNode<UintPtrT> { tmp6 }, TNode<UintPtrT> { tmp3 }, TNode<UintPtrT> { p_length }, TNode<BoolT> { tmp20 });
        ca_.Goto(&block2, tmp21);
    }

    TNode<JSTypedArray> phi_bb2_5;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_5);
        ca_.Goto(&block22);
    }

    ca_.Bind(&block22);
    return TNode<JSTypedArray> { phi_bb2_5 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=130&c=1
TNode<JSTypedArray> ConstructByLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_map, TNode<Object> p_lengthObj,
    TorqueStructTypedArrayElementsInfo p_elementsInfo)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = ToIndex_0(state_, TNode<Context> { p_context }, TNode<Object> { p_lengthObj }, &label1);
        ca_.Goto(&block4);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block5);
        }
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        ca_.Goto(&block3);
    }

    TNode<JSTypedArray> tmp2;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = TypedArrayInitialize_0(state_, TNode<Context> { p_context }, true, TNode<Map> { p_map }, TNode<UintPtrT> { tmp0 },
            TorqueStructTypedArrayElementsInfo { TNode<UintPtrT> { p_elementsInfo.sizeLog2 }, TNode<Int32T> { p_elementsInfo.kind } }, &label3);
        ca_.Goto(&block6);
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block7);
        }
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        ca_.Goto(&block3);
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block8);
    }

    if (block3.is_used()) {
        ca_.Bind(&block3);
        CodeStubAssembler(state_).ThrowRangeError(TNode<Context> { p_context }, MessageTemplate::kInvalidTypedArrayLength, TNode<Object> { p_lengthObj });
    }

    ca_.Bind(&block8);
    return TNode<JSTypedArray> { tmp2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=145&c=1
TNode<JSTypedArray> ConstructByArrayLike_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_map, TNode<HeapObject> p_arrayLike,
    TNode<UintPtrT> p_length, TorqueStructTypedArrayElementsInfo p_elementsInfo)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSTypedArray> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = TypedArrayInitialize_0(state_, TNode<Context> { p_context }, false, TNode<Map> { p_map }, TNode<UintPtrT> { p_length },
            TorqueStructTypedArrayElementsInfo { TNode<UintPtrT> { p_elementsInfo.sizeLog2 }, TNode<Int32T> { p_elementsInfo.kind } }, &label1);
        ca_.Goto(&block4);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block5);
        }
    }

    TNode<Number> tmp2;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp2 = Convert_Number_uintptr_0(state_, TNode<UintPtrT> { p_length });
        CodeStubAssembler(state_).ThrowRangeError(TNode<Context> { p_context }, MessageTemplate::kInvalidTypedArrayLength, TNode<Object> { tmp2 });
    }

    TNode<JSTypedArray> tmp3;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        compiler::CodeAssemblerLabel label4(&ca_);
        tmp3 = Cast_JSTypedArray_0(state_, TNode<HeapObject> { p_arrayLike }, &label4);
        ca_.Goto(&block10);
        if (label4.is_used()) {
            ca_.Bind(&label4);
            ca_.Goto(&block11);
        }
    }

    if (block11.is_used()) {
        ca_.Bind(&block11);
        ca_.Goto(&block7);
    }

    TNode<IntPtrT> tmp5;
    TNode<JSArrayBuffer> tmp6;
    TNode<UintPtrT> tmp7;
    if (block10.is_used()) {
        ca_.Bind(&block10);
        tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp6 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference { tmp3, tmp5 });
        compiler::CodeAssemblerLabel label8(&ca_);
        tmp7 = LoadJSArrayBufferViewByteLength_0(state_, TNode<JSArrayBufferView> { tmp3 }, TNode<JSArrayBuffer> { tmp6 }, &label8);
        ca_.Goto(&block14);
        if (label8.is_used()) {
            ca_.Bind(&label8);
            ca_.Goto(&block15);
        }
    }

    if (block15.is_used()) {
        ca_.Bind(&block15);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { p_context }, MessageTemplate::kDetachedOperation, "Construct");
    }

    TNode<Int32T> tmp9;
    TNode<BoolT> tmp10;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        tmp9 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray> { tmp3 });
        tmp10 = ElementsKindNotEqual_0(state_, TNode<Int32T> { tmp9 }, TNode<Int32T> { p_elementsInfo.kind });
        ca_.Branch(tmp10, &block16, std::vector<compiler::Node*> {}, &block17, std::vector<compiler::Node*> {});
    }

    TNode<Int32T> tmp11;
    TNode<BoolT> tmp12;
    TNode<BoolT> tmp13;
    TNode<BoolT> tmp14;
    if (block16.is_used()) {
        ca_.Bind(&block16);
        tmp11 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray> { tmp3 });
        tmp12 = TypedArrayBuiltinsAssembler(state_).IsBigInt64ElementsKind(TNode<Int32T> { tmp11 });
        tmp13 = TypedArrayBuiltinsAssembler(state_).IsBigInt64ElementsKind(TNode<Int32T> { p_elementsInfo.kind });
        tmp14 = CodeStubAssembler(state_).Word32NotEqual(TNode<BoolT> { tmp12 }, TNode<BoolT> { tmp13 });
        ca_.Branch(tmp14, &block28, std::vector<compiler::Node*> {}, &block29, std::vector<compiler::Node*> {});
    }

    TNode<UintPtrT> tmp15;
    TNode<BoolT> tmp16;
    if (block17.is_used()) {
        ca_.Bind(&block17);
        tmp15 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp16 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT> { p_length }, TNode<UintPtrT> { tmp15 });
        ca_.Branch(tmp16, &block19, std::vector<compiler::Node*> {}, &block20, std::vector<compiler::Node*> {});
    }

    TNode<IntPtrT> tmp17;
    TNode<JSArrayBuffer> tmp18;
    TNode<BoolT> tmp19;
    if (block19.is_used()) {
        ca_.Bind(&block19);
        tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp18 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference { tmp3, tmp17 });
        tmp19 = IsSharedArrayBuffer_0(state_, TNode<JSArrayBuffer> { tmp18 });
        ca_.Branch(tmp19, &block25, std::vector<compiler::Node*> {}, &block26, std::vector<compiler::Node*> {});
    }

    TNode<RawPtrT> tmp20;
    TNode<RawPtrT> tmp21;
    if (block25.is_used()) {
        ca_.Bind(&block25);
        tmp20 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray> { tmp0 });
        tmp21 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray> { tmp3 });
        TypedArrayBuiltinsAssembler(state_).CallCRelaxedMemcpy(TNode<RawPtrT> { tmp20 }, TNode<RawPtrT> { tmp21 }, TNode<UintPtrT> { tmp7 });
        ca_.Goto(&block27);
    }

    TNode<RawPtrT> tmp22;
    TNode<RawPtrT> tmp23;
    if (block26.is_used()) {
        ca_.Bind(&block26);
        tmp22 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray> { tmp0 });
        tmp23 = CodeStubAssembler(state_).LoadJSTypedArrayDataPtr(TNode<JSTypedArray> { tmp3 });
        TypedArrayBuiltinsAssembler(state_).CallCMemcpy(TNode<RawPtrT> { tmp22 }, TNode<RawPtrT> { tmp23 }, TNode<UintPtrT> { tmp7 });
        ca_.Goto(&block27);
    }

    if (block27.is_used()) {
        ca_.Bind(&block27);
        ca_.Goto(&block20);
    }

    if (block20.is_used()) {
        ca_.Bind(&block20);
        ca_.Goto(&block6);
    }

    if (block28.is_used()) {
        ca_.Bind(&block28);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { p_context }, MessageTemplate::kBigIntMixedTypes);
    }

    if (block29.is_used()) {
        ca_.Bind(&block29);
        ca_.Goto(&block7);
    }

    TNode<UintPtrT> tmp24;
    TNode<BoolT> tmp25;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp24 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp25 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT> { p_length }, TNode<UintPtrT> { tmp24 });
        ca_.Branch(tmp25, &block30, std::vector<compiler::Node*> {}, &block31, std::vector<compiler::Node*> {});
    }

    TNode<Number> tmp26;
    if (block30.is_used()) {
        ca_.Bind(&block30);
        tmp26 = Convert_Number_uintptr_0(state_, TNode<UintPtrT> { p_length });
        CodeStubAssembler(state_).CallRuntime(Runtime::kTypedArrayCopyElements, p_context, tmp0, p_arrayLike, tmp26);
        ca_.Goto(&block31);
    }

    if (block31.is_used()) {
        ca_.Bind(&block31);
        ca_.Goto(&block6);
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block32);
    }

    ca_.Bind(&block32);
    return TNode<JSTypedArray> { tmp0 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=198&c=1
void ConstructByIterable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_iterable, TNode<JSReceiver> p_iteratorFn,
    compiler::CodeAssemblerLabel* label_IfConstructByArrayLike, compiler::TypedCodeAssemblerVariable<JSArray>* label_IfConstructByArrayLike_parameter_0,
    compiler::TypedCodeAssemblerVariable<UintPtrT>* label_IfConstructByArrayLike_parameter_1)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSArray> tmp0;
    TNode<UintPtrT> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = ca_.CallBuiltin<JSArray>(Builtin::kIterableToListConvertHoles, p_context, p_iterable, p_iteratorFn);
        tmp1 = LoadJSArrayLengthAsUintPtr_0(state_, TNode<JSArray> { tmp0 });
        *label_IfConstructByArrayLike_parameter_1 = tmp1;
        *label_IfConstructByArrayLike_parameter_0 = tmp0;
        ca_.Goto(label_IfConstructByArrayLike);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=210&c=1
void ConstructByTypedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSTypedArray> p_srcTypedArray,
    compiler::CodeAssemblerLabel* label_IfConstructByArrayLike, compiler::TypedCodeAssemblerVariable<JSTypedArray>* label_IfConstructByArrayLike_parameter_0,
    compiler::TypedCodeAssemblerVariable<UintPtrT>* label_IfConstructByArrayLike_parameter_1)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<UintPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<UintPtrT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = CodeStubAssembler(state_).LoadJSTypedArrayLengthAndCheckDetached(TNode<JSTypedArray> { p_srcTypedArray }, &label1);
        ca_.Goto(&block4);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block5);
        }
    }

    TNode<UintPtrT> tmp2;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp2 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block2, tmp2);
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(&block2, tmp0);
    }

    TNode<UintPtrT> phi_bb2_2;
    if (block2.is_used()) {
        ca_.Bind(&block2, &phi_bb2_2);
        *label_IfConstructByArrayLike_parameter_1 = phi_bb2_2;
        *label_IfConstructByArrayLike_parameter_0 = p_srcTypedArray;
        ca_.Goto(label_IfConstructByArrayLike);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=227&c=1
TNode<JSTypedArray> ConstructByArrayBuffer_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSFunction> p_target,
    TNode<JSReceiver> p_newTarget, TNode<JSArrayBuffer> p_buffer, TNode<Object> p_byteOffset, TNode<Object> p_length)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Map, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, UintPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, UintPtrT, UintPtrT> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, UintPtrT, UintPtrT> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT, String> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<BoolT> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<BoolT> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = IsResizableArrayBuffer_0(state_, TNode<JSArrayBuffer> { p_buffer });
        ca_.Branch(tmp0, &block2, std::vector<compiler::Node*> {}, &block3, std::vector<compiler::Node*> {});
    }

    TNode<Undefined> tmp1;
    TNode<BoolT> tmp2;
    if (block2.is_used()) {
        ca_.Bind(&block2);
        tmp1 = Undefined_0(state_);
        tmp2 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { p_length }, TNode<HeapObject> { tmp1 });
        ca_.Goto(&block4, tmp2);
    }

    TNode<BoolT> tmp3;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block4, tmp3);
    }

    TNode<BoolT> phi_bb4_8;
    TNode<BoolT> tmp4;
    if (block4.is_used()) {
        ca_.Bind(&block4, &phi_bb4_8);
        tmp4 = IsResizableArrayBuffer_0(state_, TNode<JSArrayBuffer> { p_buffer });
        ca_.Branch(tmp4, &block5, std::vector<compiler::Node*> {}, &block6, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp5;
    TNode<BoolT> tmp6;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp5 = IsSharedArrayBuffer_0(state_, TNode<JSArrayBuffer> { p_buffer });
        tmp6 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp5 });
        ca_.Branch(tmp6, &block8, std::vector<compiler::Node*> {}, &block9, std::vector<compiler::Node*> {});
    }

    TNode<BoolT> tmp7;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block10, tmp7);
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        ca_.Goto(&block10, phi_bb4_8);
    }

    TNode<BoolT> phi_bb10_10;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_10);
        ca_.Goto(&block7, phi_bb10_10);
    }

    TNode<BoolT> tmp8;
    if (block6.is_used()) {
        ca_.Bind(&block6);
        tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block7, tmp8);
    }

    TNode<BoolT> phi_bb7_9;
    if (block7.is_used()) {
        ca_.Bind(&block7, &phi_bb7_9);
        ca_.Branch(phi_bb7_9, &block11, std::vector<compiler::Node*> { phi_bb7_9 }, &block12, std::vector<compiler::Node*> { phi_bb7_9 });
    }

    TNode<BoolT> phi_bb11_8;
    TNode<Map> tmp9;
    if (block11.is_used()) {
        ca_.Bind(&block11, &phi_bb11_8);
        tmp9 = GetDerivedRabGsabTypedArrayMap_0(state_, TNode<Context> { p_context }, TNode<JSFunction> { p_target }, TNode<JSReceiver> { p_newTarget });
        ca_.Goto(&block13, tmp9, phi_bb11_8);
    }

    TNode<BoolT> phi_bb12_8;
    TNode<Map> tmp10;
    if (block12.is_used()) {
        ca_.Bind(&block12, &phi_bb12_8);
        tmp10 = GetDerivedMap_0(state_, TNode<Context> { p_context }, TNode<JSFunction> { p_target }, TNode<JSReceiver> { p_newTarget });
        ca_.Goto(&block13, tmp10, phi_bb12_8);
    }

    TNode<Map> phi_bb13_6;
    TNode<BoolT> phi_bb13_8;
    TNode<UintPtrT> tmp11;
    TNode<Int32T> tmp12;
    TNode<UintPtrT> tmp13;
    if (block13.is_used()) {
        ca_.Bind(&block13, &phi_bb13_6, &phi_bb13_8);
        std::tie(tmp11, tmp12) = TypedArrayBuiltinsAssembler(state_).GetTypedArrayElementsInfo(TNode<Map> { phi_bb13_6 }).Flatten();
        compiler::CodeAssemblerLabel label14(&ca_);
        tmp13 = ToIndex_0(state_, TNode<Context> { p_context }, TNode<Object> { p_byteOffset }, &label14);
        ca_.Goto(&block20, phi_bb13_8);
        if (label14.is_used()) {
            ca_.Bind(&label14);
            ca_.Goto(&block21, phi_bb13_8);
        }
    }

    TNode<BoolT> phi_bb21_8;
    if (block21.is_used()) {
        ca_.Bind(&block21, &phi_bb21_8);
        ca_.Goto(&block15, phi_bb21_8);
    }

    TNode<BoolT> phi_bb20_8;
    TNode<UintPtrT> tmp15;
    TNode<UintPtrT> tmp16;
    TNode<UintPtrT> tmp17;
    TNode<UintPtrT> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<UintPtrT> tmp20;
    TNode<BoolT> tmp21;
    if (block20.is_used()) {
        ca_.Bind(&block20, &phi_bb20_8);
        tmp15 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp16 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT> { tmp15 }, TNode<UintPtrT> { tmp11 });
        tmp17 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp18 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT> { tmp16 }, TNode<UintPtrT> { tmp17 });
        tmp19 = CodeStubAssembler(state_).WordAnd(TNode<UintPtrT> { tmp13 }, TNode<UintPtrT> { tmp18 });
        tmp20 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp21 = CodeStubAssembler(state_).WordNotEqual(TNode<UintPtrT> { tmp19 }, TNode<UintPtrT> { tmp20 });
        ca_.Branch(tmp21, &block22, std::vector<compiler::Node*> { phi_bb20_8 }, &block23, std::vector<compiler::Node*> { phi_bb20_8 });
    }

    TNode<BoolT> phi_bb22_8;
    TNode<String> tmp22;
    if (block22.is_used()) {
        ca_.Bind(&block22, &phi_bb22_8);
        tmp22 = FromConstexpr_String_constexpr_string_0(state_, "start offset");
        ca_.Goto(&block19, phi_bb22_8, tmp22);
    }

    TNode<BoolT> phi_bb23_8;
    TNode<UintPtrT> tmp23;
    if (block23.is_used()) {
        ca_.Bind(&block23, &phi_bb23_8);
        compiler::CodeAssemblerLabel label24(&ca_);
        tmp23 = ToIndex_0(state_, TNode<Context> { p_context }, TNode<Object> { p_length }, &label24);
        ca_.Goto(&block25, phi_bb23_8);
        if (label24.is_used()) {
            ca_.Bind(&label24);
            ca_.Goto(&block26, phi_bb23_8);
        }
    }

    TNode<BoolT> phi_bb26_8;
    if (block26.is_used()) {
        ca_.Bind(&block26, &phi_bb26_8);
        ca_.Goto(&block17, phi_bb26_8);
    }

    TNode<BoolT> phi_bb25_8;
    TNode<BoolT> tmp25;
    if (block25.is_used()) {
        ca_.Bind(&block25, &phi_bb25_8);
        tmp25 = IsDetachedBuffer_0(state_, TNode<JSArrayBuffer> { p_buffer });
        ca_.Branch(tmp25, &block27, std::vector<compiler::Node*> { phi_bb25_8 }, &block28, std::vector<compiler::Node*> { phi_bb25_8 });
    }

    TNode<BoolT> phi_bb27_8;
    if (block27.is_used()) {
        ca_.Bind(&block27, &phi_bb27_8);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { p_context }, MessageTemplate::kDetachedOperation, "Construct");
    }

    TNode<BoolT> phi_bb28_8;
    TNode<BoolT> tmp26;
    if (block28.is_used()) {
        ca_.Bind(&block28, &phi_bb28_8);
        tmp26 = IsResizableArrayBuffer_0(state_, TNode<JSArrayBuffer> { p_buffer });
        ca_.Branch(tmp26, &block31, std::vector<compiler::Node*> { phi_bb28_8 }, &block32, std::vector<compiler::Node*> { phi_bb28_8 });
    }

    TNode<BoolT> phi_bb31_8;
    TNode<BoolT> tmp27;
    if (block31.is_used()) {
        ca_.Bind(&block31, &phi_bb31_8);
        tmp27 = IsSharedArrayBuffer_0(state_, TNode<JSArrayBuffer> { p_buffer });
        ca_.Goto(&block33, phi_bb31_8, tmp27);
    }

    TNode<BoolT> phi_bb32_8;
    TNode<BoolT> tmp28;
    if (block32.is_used()) {
        ca_.Bind(&block32, &phi_bb32_8);
        tmp28 = FromConstexpr_bool_constexpr_bool_0(state_, false);
        ca_.Goto(&block33, phi_bb32_8, tmp28);
    }

    TNode<BoolT> phi_bb33_8;
    TNode<BoolT> phi_bb33_16;
    if (block33.is_used()) {
        ca_.Bind(&block33, &phi_bb33_8, &phi_bb33_16);
        ca_.Branch(phi_bb33_16, &block29, std::vector<compiler::Node*> { phi_bb33_8 }, &block30, std::vector<compiler::Node*> { phi_bb33_8 });
    }

    TNode<BoolT> phi_bb29_8;
    TNode<Object> tmp29;
    TNode<UintPtrT> tmp30;
    if (block29.is_used()) {
        ca_.Bind(&block29, &phi_bb29_8);
        tmp29 = CodeStubAssembler(state_).CallRuntime(Runtime::kGrowableSharedArrayBufferByteLength, p_context, p_buffer);
        compiler::CodeAssemblerLabel label31(&ca_);
        tmp30 = ToIndex_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp29 }, &label31);
        ca_.Goto(&block37, phi_bb29_8);
        if (label31.is_used()) {
            ca_.Bind(&label31);
            ca_.Goto(&block38, phi_bb29_8);
        }
    }

    TNode<BoolT> phi_bb38_8;
    if (block38.is_used()) {
        ca_.Bind(&block38, &phi_bb38_8);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<BoolT> phi_bb37_8;
    if (block37.is_used()) {
        ca_.Bind(&block37, &phi_bb37_8);
        ca_.Goto(&block34, phi_bb37_8, tmp30);
    }

    TNode<BoolT> phi_bb30_8;
    TNode<UintPtrT> tmp32;
    if (block30.is_used()) {
        ca_.Bind(&block30, &phi_bb30_8);
        tmp32 = CodeStubAssembler(state_).LoadJSArrayBufferByteLength(TNode<JSArrayBuffer> { p_buffer });
        ca_.Goto(&block34, phi_bb30_8, tmp32);
    }

    TNode<BoolT> phi_bb34_8;
    TNode<UintPtrT> phi_bb34_14;
    if (block34.is_used()) {
        ca_.Bind(&block34, &phi_bb34_8, &phi_bb34_14);
        ca_.Branch(phi_bb4_8, &block39, std::vector<compiler::Node*> { phi_bb34_8 }, &block40, std::vector<compiler::Node*> { phi_bb34_8 });
    }

    TNode<BoolT> phi_bb39_8;
    TNode<BoolT> tmp33;
    if (block39.is_used()) {
        ca_.Bind(&block39, &phi_bb39_8);
        tmp33 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { phi_bb34_14 }, TNode<UintPtrT> { tmp13 });
        ca_.Branch(tmp33, &block42, std::vector<compiler::Node*> { phi_bb39_8 }, &block43, std::vector<compiler::Node*> { phi_bb39_8 });
    }

    TNode<BoolT> phi_bb42_8;
    if (block42.is_used()) {
        ca_.Bind(&block42, &phi_bb42_8);
        ca_.Goto(&block15, phi_bb42_8);
    }

    TNode<BoolT> phi_bb43_8;
    TNode<UintPtrT> tmp34;
    TNode<UintPtrT> tmp35;
    if (block43.is_used()) {
        ca_.Bind(&block43, &phi_bb43_8);
        tmp34 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp35 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        ca_.Goto(&block41, phi_bb43_8, tmp34, tmp35);
    }

    TNode<BoolT> phi_bb40_8;
    TNode<Undefined> tmp36;
    TNode<BoolT> tmp37;
    if (block40.is_used()) {
        ca_.Bind(&block40, &phi_bb40_8);
        tmp36 = Undefined_0(state_);
        tmp37 = CodeStubAssembler(state_).TaggedEqual(TNode<Object> { p_length }, TNode<HeapObject> { tmp36 });
        ca_.Branch(tmp37, &block44, std::vector<compiler::Node*> { phi_bb40_8 }, &block45, std::vector<compiler::Node*> { phi_bb40_8 });
    }

    TNode<BoolT> phi_bb44_8;
    TNode<UintPtrT> tmp38;
    TNode<UintPtrT> tmp39;
    TNode<UintPtrT> tmp40;
    TNode<UintPtrT> tmp41;
    TNode<UintPtrT> tmp42;
    TNode<UintPtrT> tmp43;
    TNode<BoolT> tmp44;
    if (block44.is_used()) {
        ca_.Bind(&block44, &phi_bb44_8);
        tmp38 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp39 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT> { tmp38 }, TNode<UintPtrT> { tmp11 });
        tmp40 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
        tmp41 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT> { tmp39 }, TNode<UintPtrT> { tmp40 });
        tmp42 = CodeStubAssembler(state_).WordAnd(TNode<UintPtrT> { phi_bb34_14 }, TNode<UintPtrT> { tmp41 });
        tmp43 = FromConstexpr_uintptr_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
        tmp44 = CodeStubAssembler(state_).WordNotEqual(TNode<UintPtrT> { tmp42 }, TNode<UintPtrT> { tmp43 });
        ca_.Branch(tmp44, &block47, std::vector<compiler::Node*> { phi_bb44_8 }, &block48, std::vector<compiler::Node*> { phi_bb44_8 });
    }

    TNode<BoolT> phi_bb47_8;
    TNode<String> tmp45;
    if (block47.is_used()) {
        ca_.Bind(&block47, &phi_bb47_8);
        tmp45 = FromConstexpr_String_constexpr_string_0(state_, "byte length");
        ca_.Goto(&block19, phi_bb47_8, tmp45);
    }

    TNode<BoolT> phi_bb48_8;
    TNode<BoolT> tmp46;
    if (block48.is_used()) {
        ca_.Bind(&block48, &phi_bb48_8);
        tmp46 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { phi_bb34_14 }, TNode<UintPtrT> { tmp13 });
        ca_.Branch(tmp46, &block50, std::vector<compiler::Node*> { phi_bb48_8 }, &block51, std::vector<compiler::Node*> { phi_bb48_8 });
    }

    TNode<BoolT> phi_bb50_8;
    if (block50.is_used()) {
        ca_.Bind(&block50, &phi_bb50_8);
        ca_.Goto(&block15, phi_bb50_8);
    }

    TNode<BoolT> phi_bb51_8;
    TNode<UintPtrT> tmp47;
    TNode<UintPtrT> tmp48;
    if (block51.is_used()) {
        ca_.Bind(&block51, &phi_bb51_8);
        tmp47 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT> { phi_bb34_14 }, TNode<UintPtrT> { tmp13 });
        tmp48 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT> { tmp47 }, TNode<UintPtrT> { tmp11 });
        ca_.Goto(&block46, phi_bb51_8, tmp48, tmp47);
    }

    TNode<BoolT> phi_bb45_8;
    TNode<UintPtrT> tmp49;
    TNode<UintPtrT> tmp50;
    TNode<BoolT> tmp51;
    if (block45.is_used()) {
        ca_.Bind(&block45, &phi_bb45_8);
        tmp49 = FromConstexpr_uintptr_constexpr_uintptr_0(state_, JSArrayBuffer::kMaxByteLength);
        tmp50 = CodeStubAssembler(state_).WordShr(TNode<UintPtrT> { tmp49 }, TNode<UintPtrT> { tmp11 });
        tmp51 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT> { tmp23 }, TNode<UintPtrT> { tmp50 });
        ca_.Branch(tmp51, &block54, std::vector<compiler::Node*> { phi_bb45_8 }, &block55, std::vector<compiler::Node*> { phi_bb45_8 });
    }

    TNode<BoolT> phi_bb54_8;
    if (block54.is_used()) {
        ca_.Bind(&block54, &phi_bb54_8);
        ca_.Goto(&block17, phi_bb54_8);
    }

    TNode<BoolT> phi_bb55_8;
    TNode<UintPtrT> tmp52;
    TNode<BoolT> tmp53;
    if (block55.is_used()) {
        ca_.Bind(&block55, &phi_bb55_8);
        tmp52 = CodeStubAssembler(state_).WordShl(TNode<UintPtrT> { tmp23 }, TNode<UintPtrT> { tmp11 });
        tmp53 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { phi_bb34_14 }, TNode<UintPtrT> { tmp52 });
        ca_.Branch(tmp53, &block58, std::vector<compiler::Node*> { phi_bb55_8 }, &block59, std::vector<compiler::Node*> { phi_bb55_8 });
    }

    TNode<BoolT> phi_bb58_8;
    TNode<BoolT> tmp54;
    if (block58.is_used()) {
        ca_.Bind(&block58, &phi_bb58_8);
        tmp54 = FromConstexpr_bool_constexpr_bool_0(state_, true);
        ca_.Goto(&block60, phi_bb58_8, tmp54);
    }

    TNode<BoolT> phi_bb59_8;
    TNode<UintPtrT> tmp55;
    TNode<BoolT> tmp56;
    if (block59.is_used()) {
        ca_.Bind(&block59, &phi_bb59_8);
        tmp55 = CodeStubAssembler(state_).UintPtrSub(TNode<UintPtrT> { phi_bb34_14 }, TNode<UintPtrT> { tmp52 });
        tmp56 = CodeStubAssembler(state_).UintPtrGreaterThan(TNode<UintPtrT> { tmp13 }, TNode<UintPtrT> { tmp55 });
        ca_.Goto(&block60, phi_bb59_8, tmp56);
    }

    TNode<BoolT> phi_bb60_8;
    TNode<BoolT> phi_bb60_16;
    if (block60.is_used()) {
        ca_.Bind(&block60, &phi_bb60_8, &phi_bb60_16);
        ca_.Branch(phi_bb60_16, &block56, std::vector<compiler::Node*> { phi_bb60_8 }, &block57, std::vector<compiler::Node*> { phi_bb60_8 });
    }

    TNode<BoolT> phi_bb56_8;
    if (block56.is_used()) {
        ca_.Bind(&block56, &phi_bb56_8);
        ca_.Goto(&block17, phi_bb56_8);
    }

    TNode<BoolT> phi_bb57_8;
    if (block57.is_used()) {
        ca_.Bind(&block57, &phi_bb57_8);
        ca_.Goto(&block46, phi_bb57_8, tmp23, tmp52);
    }

    TNode<BoolT> phi_bb46_8;
    TNode<UintPtrT> phi_bb46_12;
    TNode<UintPtrT> phi_bb46_13;
    if (block46.is_used()) {
        ca_.Bind(&block46, &phi_bb46_8, &phi_bb46_12, &phi_bb46_13);
        ca_.Goto(&block41, phi_bb46_8, phi_bb46_12, phi_bb46_13);
    }

    TNode<BoolT> phi_bb41_8;
    TNode<UintPtrT> phi_bb41_12;
    TNode<UintPtrT> phi_bb41_13;
    TNode<JSTypedArray> tmp57;
    if (block41.is_used()) {
        ca_.Bind(&block41, &phi_bb41_8, &phi_bb41_12, &phi_bb41_13);
        tmp57 = AllocateTypedArray_0(state_, TNode<Context> { p_context }, false, TNode<Map> { phi_bb13_6 }, TNode<JSArrayBuffer> { p_buffer },
            TNode<UintPtrT> { tmp13 }, TNode<UintPtrT> { phi_bb41_13 }, TNode<UintPtrT> { phi_bb41_12 }, TNode<BoolT> { phi_bb4_8 });
        ca_.Goto(&block61);
    }

    TNode<BoolT> phi_bb19_8;
    TNode<String> phi_bb19_11;
    if (block19.is_used()) {
        ca_.Bind(&block19, &phi_bb19_8, &phi_bb19_11);
        CodeStubAssembler(state_).CallRuntime(Runtime::kThrowInvalidTypedArrayAlignment, p_context, phi_bb13_6, phi_bb19_11);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<BoolT> phi_bb17_8;
    if (block17.is_used()) {
        ca_.Bind(&block17, &phi_bb17_8);
        CodeStubAssembler(state_).ThrowRangeError(TNode<Context> { p_context }, MessageTemplate::kInvalidTypedArrayLength, TNode<Object> { p_length });
    }

    TNode<BoolT> phi_bb15_8;
    if (block15.is_used()) {
        ca_.Bind(&block15, &phi_bb15_8);
        CodeStubAssembler(state_).ThrowRangeError(TNode<Context> { p_context }, MessageTemplate::kInvalidOffset, TNode<Object> { p_byteOffset });
    }

    ca_.Bind(&block61);
    return TNode<JSTypedArray> { tmp57 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=331&c=1
TNode<JSTypedArray> TypedArrayCreateByLength_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_constructor, TNode<Number> p_length, const char* p_methodName)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSReceiver> tmp0;
    TNode<UintPtrT> tmp1;
    TNode<JSTypedArray> tmp2;
    TNode<IntPtrT> tmp3;
    TNode<JSArrayBuffer> tmp4;
    TNode<BoolT> tmp5;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).Construct(TNode<Context> { p_context }, TNode<JSReceiver> { p_constructor }, TNode<Object> { p_length });
        tmp1 = TypedArrayBuiltinsAssembler(state_).ValidateTypedArrayAndGetLength(TNode<Context> { p_context }, TNode<Object> { tmp0 }, p_methodName);
        tmp2 = UnsafeCast_JSTypedArray_0(state_, TNode<Context> { p_context }, TNode<Object> { tmp0 });
        tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
        tmp4 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference { tmp2, tmp3 });
        tmp5 = IsDetachedBuffer_0(state_, TNode<JSArrayBuffer> { tmp4 });
        ca_.Branch(tmp5, &block20, std::vector<compiler::Node*> {}, &block21, std::vector<compiler::Node*> {});
    }

    if (block20.is_used()) {
        ca_.Bind(&block20);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { p_context }, MessageTemplate::kDetachedOperation, p_methodName);
    }

    TNode<UintPtrT> tmp6;
    TNode<BoolT> tmp7;
    if (block21.is_used()) {
        ca_.Bind(&block21);
        tmp6 = Convert_uintptr_Number_0(state_, TNode<Number> { p_length });
        tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp1 }, TNode<UintPtrT> { tmp6 });
        ca_.Branch(tmp7, &block22, std::vector<compiler::Node*> {}, &block23, std::vector<compiler::Node*> {});
    }

    if (block22.is_used()) {
        ca_.Bind(&block22);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { p_context }, MessageTemplate::kTypedArrayTooShort);
    }

    if (block23.is_used()) {
        ca_.Bind(&block23);
        ca_.Goto(&block24);
    }

    ca_.Bind(&block24);
    return TNode<JSTypedArray> { tmp2 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=370&c=1
void ConstructByJSReceiver_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_obj,
    compiler::CodeAssemblerLabel* label_IfConstructByArrayLike, compiler::TypedCodeAssemblerVariable<JSReceiver>* label_IfConstructByArrayLike_parameter_0,
    compiler::TypedCodeAssemblerVariable<UintPtrT>* label_IfConstructByArrayLike_parameter_1, compiler::CodeAssemblerLabel* label_IfIteratorNotCallable,
    compiler::TypedCodeAssemblerVariable<Object>* label_IfIteratorNotCallable_parameter_0)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<JSReceiver, UintPtrT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Symbol> tmp0;
    TNode<JSReceiver> tmp1;
    compiler::TypedCodeAssemblerVariable<Object> tmp4(&ca_);
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = CodeStubAssembler(state_).IteratorSymbolConstant();
        compiler::CodeAssemblerLabel label2(&ca_);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp1 = GetMethod_0(state_, TNode<Context> { p_context }, TNode<Object> { p_obj }, TNode<Name> { tmp0 }, &label2, &label3, &tmp4);
        ca_.Goto(&block7);
        if (label2.is_used()) {
            ca_.Bind(&label2);
            ca_.Goto(&block8);
        }
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block9);
        }
    }

    TNode<String> tmp5;
    TNode<Object> tmp6;
    TNode<Number> tmp7;
    TNode<UintPtrT> tmp8;
    if (block8.is_used()) {
        ca_.Bind(&block8);
        tmp5 = kLengthString_0(state_);
        tmp6 = CodeStubAssembler(state_).GetProperty(TNode<Context> { p_context }, TNode<Object> { p_obj }, TNode<Object> { tmp5 });
        tmp7 = CodeStubAssembler(state_).ToLength_Inline(TNode<Context> { p_context }, TNode<Object> { tmp6 });
        compiler::CodeAssemblerLabel label9(&ca_);
        tmp8 = ChangeSafeIntegerNumberToUintPtr_0(state_, TNode<Number> { tmp7 }, &label9);
        ca_.Goto(&block13);
        if (label9.is_used()) {
            ca_.Bind(&label9);
            ca_.Goto(&block14);
        }
    }

    if (block9.is_used()) {
        ca_.Bind(&block9);
        *label_IfIteratorNotCallable_parameter_0 = tmp4.value();
        ca_.Goto(label_IfIteratorNotCallable);
    }

    compiler::TypedCodeAssemblerVariable<JSArray> tmp11(&ca_);
    compiler::TypedCodeAssemblerVariable<UintPtrT> tmp12(&ca_);
    if (block7.is_used()) {
        ca_.Bind(&block7);
        compiler::CodeAssemblerLabel label10(&ca_);
        ConstructByIterable_0(state_, TNode<Context> { p_context }, TNode<JSReceiver> { p_obj }, TNode<JSReceiver> { tmp1 }, &label10, &tmp11, &tmp12);
        if (label10.is_used()) {
            ca_.Bind(&label10);
            ca_.Goto(&block10);
        }
    }

    if (block10.is_used()) {
        ca_.Bind(&block10);
        ca_.Goto(&block1, tmp11.value(), tmp12.value());
    }

    if (block14.is_used()) {
        ca_.Bind(&block14);
        CodeStubAssembler(state_).ThrowRangeError(TNode<Context> { p_context }, MessageTemplate::kInvalidTypedArrayLength, TNode<Object> { tmp7 });
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block1, p_obj, tmp8);
    }

    TNode<JSReceiver> phi_bb1_0;
    TNode<UintPtrT> phi_bb1_1;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_0, &phi_bb1_1);
        *label_IfConstructByArrayLike_parameter_1 = phi_bb1_1;
        *label_IfConstructByArrayLike_parameter_0 = phi_bb1_0;
        ca_.Goto(label_IfConstructByArrayLike);
    }
}

TF_BUILTIN(CreateTypedArray, CodeStubAssembler)
{
    compiler::CodeAssemblerState* state_ = state();
    compiler::CodeAssembler ca_(state());
    TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
    USE(parameter0);
    TNode<JSFunction> parameter1 = UncheckedParameter<JSFunction>(Descriptor::kTarget);
    USE(parameter1);
    TNode<JSReceiver> parameter2 = UncheckedParameter<JSReceiver>(Descriptor::kNewTarget);
    USE(parameter2);
    TNode<Object> parameter3 = UncheckedParameter<Object>(Descriptor::kArg1);
    USE(parameter3);
    TNode<Object> parameter4 = UncheckedParameter<Object>(Descriptor::kArg2);
    USE(parameter4);
    TNode<Object> parameter5 = UncheckedParameter<Object>(Descriptor::kArg3);
    USE(parameter5);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<JSReceiver, UintPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Smi> tmp0;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        compiler::CodeAssemblerLabel label1(&ca_);
        tmp0 = Cast_Smi_0(state_, TNode<Object> { parameter3 }, &label1);
        ca_.Goto(&block13);
        if (label1.is_used()) {
            ca_.Bind(&label1);
            ca_.Goto(&block14);
        }
    }

    TNode<JSArrayBuffer> tmp2;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        compiler::CodeAssemblerLabel label3(&ca_);
        tmp2 = Cast_JSArrayBuffer_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(parameter3) }, &label3);
        ca_.Goto(&block17);
        if (label3.is_used()) {
            ca_.Bind(&label3);
            ca_.Goto(&block18);
        }
    }

    if (block13.is_used()) {
        ca_.Bind(&block13);
        ca_.Goto(&block10, tmp0);
    }

    TNode<JSTypedArray> tmp4;
    if (block18.is_used()) {
        ca_.Bind(&block18);
        compiler::CodeAssemblerLabel label5(&ca_);
        tmp4 = Cast_JSTypedArray_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(parameter3) }, &label5);
        ca_.Goto(&block21);
        if (label5.is_used()) {
            ca_.Bind(&label5);
            ca_.Goto(&block22);
        }
    }

    TNode<JSTypedArray> tmp6;
    if (block17.is_used()) {
        ca_.Bind(&block17);
        tmp6 = ConstructByArrayBuffer_0(state_, TNode<Context> { parameter0 }, TNode<JSFunction> { parameter1 }, TNode<JSReceiver> { parameter2 },
            TNode<JSArrayBuffer> { tmp2 }, TNode<Object> { parameter4 }, TNode<Object> { parameter5 });
        CodeStubAssembler(state_).Return(tmp6);
    }

    TNode<JSReceiver> tmp7;
    if (block22.is_used()) {
        ca_.Bind(&block22);
        compiler::CodeAssemblerLabel label8(&ca_);
        tmp7 = Cast_JSReceiver_0(state_, TNode<HeapObject> { ca_.UncheckedCast<HeapObject>(parameter3) }, &label8);
        ca_.Goto(&block26);
        if (label8.is_used()) {
            ca_.Bind(&label8);
            ca_.Goto(&block27);
        }
    }

    compiler::TypedCodeAssemblerVariable<JSTypedArray> tmp10(&ca_);
    compiler::TypedCodeAssemblerVariable<UintPtrT> tmp11(&ca_);
    if (block21.is_used()) {
        ca_.Bind(&block21);
        compiler::CodeAssemblerLabel label9(&ca_);
        ConstructByTypedArray_0(state_, TNode<Context> { parameter0 }, TNode<JSTypedArray> { tmp4 }, &label9, &tmp10, &tmp11);
        if (label9.is_used()) {
            ca_.Bind(&label9);
            ca_.Goto(&block23);
        }
    }

    if (block23.is_used()) {
        ca_.Bind(&block23);
        ca_.Goto(&block8, tmp10.value(), tmp11.value());
    }

    if (block27.is_used()) {
        ca_.Bind(&block27);
        ca_.Goto(&block10, ca_.UncheckedCast<PrimitiveHeapObject>(parameter3));
    }

    compiler::TypedCodeAssemblerVariable<JSReceiver> tmp13(&ca_);
    compiler::TypedCodeAssemblerVariable<UintPtrT> tmp14(&ca_);
    compiler::TypedCodeAssemblerVariable<Object> tmp16(&ca_);
    if (block26.is_used()) {
        ca_.Bind(&block26);
        compiler::CodeAssemblerLabel label12(&ca_);
        compiler::CodeAssemblerLabel label15(&ca_);
        ConstructByJSReceiver_0(state_, TNode<Context> { parameter0 }, TNode<JSReceiver> { tmp7 }, &label12, &tmp13, &tmp14, &label15, &tmp16);
        if (label12.is_used()) {
            ca_.Bind(&label12);
            ca_.Goto(&block28);
        }
        if (label15.is_used()) {
            ca_.Bind(&label15);
            ca_.Goto(&block29);
        }
    }

    if (block28.is_used()) {
        ca_.Bind(&block28);
        ca_.Goto(&block8, tmp13.value(), tmp14.value());
    }

    if (block29.is_used()) {
        ca_.Bind(&block29);
        CodeStubAssembler(state_).ThrowTypeError(
            TNode<Context> { parameter0 }, MessageTemplate::kFirstArgumentIteratorSymbolNonCallable, "TypedArray\'s constructor");
    }

    TNode<Object> phi_bb10_6;
    TNode<Map> tmp17;
    TNode<UintPtrT> tmp18;
    TNode<Int32T> tmp19;
    TNode<JSTypedArray> tmp20;
    if (block10.is_used()) {
        ca_.Bind(&block10, &phi_bb10_6);
        tmp17 = GetDerivedMap_0(state_, TNode<Context> { parameter0 }, TNode<JSFunction> { parameter1 }, TNode<JSReceiver> { parameter2 });
        std::tie(tmp18, tmp19) = TypedArrayBuiltinsAssembler(state_).GetTypedArrayElementsInfo(TNode<Map> { tmp17 }).Flatten();
        tmp20 = ConstructByLength_0(state_, TNode<Context> { parameter0 }, TNode<Map> { tmp17 }, TNode<Object> { phi_bb10_6 },
            TorqueStructTypedArrayElementsInfo { TNode<UintPtrT> { tmp18 }, TNode<Int32T> { tmp19 } });
        CodeStubAssembler(state_).Return(tmp20);
    }

    TNode<JSReceiver> phi_bb8_6;
    TNode<UintPtrT> phi_bb8_7;
    TNode<Map> tmp21;
    TNode<UintPtrT> tmp22;
    TNode<Int32T> tmp23;
    TNode<JSTypedArray> tmp24;
    if (block8.is_used()) {
        ca_.Bind(&block8, &phi_bb8_6, &phi_bb8_7);
        tmp21 = GetDerivedMap_0(state_, TNode<Context> { parameter0 }, TNode<JSFunction> { parameter1 }, TNode<JSReceiver> { parameter2 });
        std::tie(tmp22, tmp23) = TypedArrayBuiltinsAssembler(state_).GetTypedArrayElementsInfo(TNode<Map> { tmp21 }).Flatten();
        tmp24 = ConstructByArrayLike_0(state_, TNode<Context> { parameter0 }, TNode<Map> { tmp21 }, TNode<HeapObject> { phi_bb8_6 },
            TNode<UintPtrT> { phi_bb8_7 }, TorqueStructTypedArrayElementsInfo { TNode<UintPtrT> { tmp22 }, TNode<Int32T> { tmp23 } });
        CodeStubAssembler(state_).Return(tmp24);
    }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=444&c=1
TNode<JSTypedArray> TypedArraySpeciesCreate_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, const char* p_methodName, int31_t p_numArgs,
    TNode<JSTypedArray> p_exemplar, TNode<Object> p_arg0, TNode<Object> p_arg1, TNode<Object> p_arg2)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<JSTypedArray> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<JSTypedArray> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSFunction> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<Map> tmp2;
    TNode<BoolT> tmp3;
    TNode<BoolT> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = TypedArrayBuiltinsAssembler(state_).GetDefaultConstructor(TNode<Context> { p_context }, TNode<JSTypedArray> { p_exemplar });
        tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
        tmp2 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference { p_exemplar, tmp1 });
        tmp3 = CodeStubAssembler(state_).IsPrototypeTypedArrayPrototype(TNode<Context> { p_context }, TNode<Map> { tmp2 });
        tmp4 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT> { tmp3 });
        ca_.Branch(tmp4, &block4, std::vector<compiler::Node*> {}, &block5, std::vector<compiler::Node*> {});
    }

    if (block4.is_used()) {
        ca_.Bind(&block4);
        ca_.Goto(&block3);
    }

    TNode<BoolT> tmp5;
    if (block5.is_used()) {
        ca_.Bind(&block5);
        tmp5 = CodeStubAssembler(state_).IsTypedArraySpeciesProtectorCellInvalid();
        ca_.Branch(tmp5, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        ca_.Goto(&block3);
    }

    TNode<JSTypedArray> tmp6;
    if (block7.is_used()) {
        ca_.Bind(&block7);
        tmp6 = ca_.CallBuiltin<JSTypedArray>(Builtin::kCreateTypedArray, p_context, tmp0, tmp0, p_arg0, p_arg1, p_arg2);
        ca_.Goto(&block1, tmp6);
    }

    TNode<JSReceiver> tmp7;
    TNode<JSReceiver> tmp8;
    if (block3.is_used()) {
        ca_.Bind(&block3);
        tmp7 = CodeStubAssembler(state_).SpeciesConstructor(TNode<Context> { p_context }, TNode<Object> { p_exemplar }, TNode<JSReceiver> { tmp0 });
        compiler::CodeAssemblerLabel label9(&ca_);
        tmp8 = Cast_Constructor_0(state_, TNode<HeapObject> { tmp7 }, &label9);
        ca_.Goto(&block14);
        if (label9.is_used()) {
            ca_.Bind(&label9);
            ca_.Goto(&block15);
        }
    }

    if (block15.is_used()) {
        ca_.Bind(&block15);
        CodeStubAssembler(state_).Unreachable();
    }

    TNode<Undefined> tmp10;
    if (block14.is_used()) {
        ca_.Bind(&block14);
        tmp10 = Undefined_0(state_);
        if (((CodeStubAssembler(state_).ConstexprInt31Equal(
                p_numArgs, (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull))))))) {
            ca_.Goto(&block16);
        } else {
            ca_.Goto(&block17);
        }
    }

    TNode<JSReceiver> tmp11;
    if (block16.is_used()) {
        ca_.Bind(&block16);
        tmp11 = CodeStubAssembler(state_).Construct(TNode<Context> { p_context }, TNode<JSReceiver> { tmp8 }, TNode<Object> { p_arg0 });
        ca_.Goto(&block18, tmp11);
    }

    TNode<JSReceiver> tmp12;
    if (block17.is_used()) {
        ca_.Bind(&block17);
        tmp12 = CodeStubAssembler(state_).Construct(
            TNode<Context> { p_context }, TNode<JSReceiver> { tmp8 }, TNode<Object> { p_arg0 }, TNode<Object> { p_arg1 }, TNode<Object> { p_arg2 });
        ca_.Goto(&block18, tmp12);
    }

    TNode<Object> phi_bb18_7;
    TNode<JSTypedArray> tmp13;
    if (block18.is_used()) {
        ca_.Bind(&block18, &phi_bb18_7);
        tmp13 = TypedArrayBuiltinsAssembler(state_).ValidateTypedArray(TNode<Context> { p_context }, TNode<Object> { phi_bb18_7 }, p_methodName);
        ca_.Goto(&block1, tmp13);
    }

    TNode<JSTypedArray> phi_bb1_5;
    if (block1.is_used()) {
        ca_.Bind(&block1, &phi_bb1_5);
        ca_.Goto(&block23, phi_bb1_5);
    }

    TNode<JSTypedArray> phi_bb23_5;
    ca_.Bind(&block23, &phi_bb23_5);
    return TNode<JSTypedArray> { phi_bb23_5 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=481&c=1
TNode<JSTypedArray> TypedArraySpeciesCreateByLength_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, const char* p_methodName, TNode<JSTypedArray> p_exemplar, TNode<UintPtrT> p_length)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<Undefined> tmp1;
    TNode<Undefined> tmp2;
    TNode<JSTypedArray> tmp3;
    TNode<UintPtrT> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_Number_uintptr_0(state_, TNode<UintPtrT> { p_length });
        tmp1 = Undefined_0(state_);
        tmp2 = Undefined_0(state_);
        tmp3 = TypedArraySpeciesCreate_0(state_, TNode<Context> { p_context }, p_methodName,
            (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull))), TNode<JSTypedArray> { p_exemplar },
            TNode<Object> { tmp0 }, TNode<Object> { tmp1 }, TNode<Object> { tmp2 });
        compiler::CodeAssemblerLabel label5(&ca_);
        tmp4 = CodeStubAssembler(state_).LoadJSTypedArrayLengthAndCheckDetached(TNode<JSTypedArray> { tmp3 }, &label5);
        ca_.Goto(&block4);
        if (label5.is_used()) {
            ca_.Bind(&label5);
            ca_.Goto(&block5);
        }
    }

    if (block5.is_used()) {
        ca_.Bind(&block5);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { p_context }, MessageTemplate::kTypedArrayTooShort);
    }

    TNode<BoolT> tmp6;
    if (block4.is_used()) {
        ca_.Bind(&block4);
        tmp6 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT> { tmp4 }, TNode<UintPtrT> { p_length });
        ca_.Branch(tmp6, &block6, std::vector<compiler::Node*> {}, &block7, std::vector<compiler::Node*> {});
    }

    if (block6.is_used()) {
        ca_.Bind(&block6);
        CodeStubAssembler(state_).ThrowTypeError(TNode<Context> { p_context }, MessageTemplate::kTypedArrayTooShort);
    }

    if (block7.is_used()) {
        ca_.Bind(&block7);
        ca_.Goto(&block8);
    }

    ca_.Bind(&block8);
    return TNode<JSTypedArray> { tmp3 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=503&c=1
TNode<JSTypedArray> TypedArraySpeciesCreateByBuffer_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, const char* p_methodName,
    TNode<JSTypedArray> p_exemplar, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_beginByteOffset, TNode<Object> p_newLength)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<Number> tmp0;
    TNode<JSTypedArray> tmp1;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = Convert_Number_uintptr_0(state_, TNode<UintPtrT> { p_beginByteOffset });
        tmp1 = TypedArraySpeciesCreate_0(state_, TNode<Context> { p_context }, p_methodName,
            (FromConstexpr_constexpr_int31_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x3ull))), TNode<JSTypedArray> { p_exemplar },
            TNode<Object> { p_buffer }, TNode<Object> { tmp0 }, TNode<Object> { p_newLength });
        ca_.Goto(&block2);
    }

    ca_.Bind(&block2);
    return TNode<JSTypedArray> { tmp1 };
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-createtypedarray.tq?l=515&c=1
TNode<JSTypedArray> TypedArrayCreateSameType_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSTypedArray> p_exemplar, TNode<UintPtrT> p_newLength)
{
    compiler::CodeAssembler ca_(state_);
    compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
    compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    TNode<JSFunction> tmp0;
    TNode<Number> tmp1;
    TNode<Undefined> tmp2;
    TNode<Undefined> tmp3;
    TNode<JSTypedArray> tmp4;
    if (block0.is_used()) {
        ca_.Bind(&block0);
        tmp0 = TypedArrayBuiltinsAssembler(state_).GetDefaultConstructor(TNode<Context> { p_context }, TNode<JSTypedArray> { p_exemplar });
        tmp1 = Convert_Number_uintptr_0(state_, TNode<UintPtrT> { p_newLength });
        tmp2 = Undefined_0(state_);
        tmp3 = Undefined_0(state_);
        tmp4 = ca_.CallBuiltin<JSTypedArray>(Builtin::kCreateTypedArray, p_context, tmp0, tmp0, tmp1, tmp2, tmp3);
        ca_.Goto(&block10);
    }

    ca_.Bind(&block10);
    return TNode<JSTypedArray> { tmp4 };
}

} // namespace internal
} // namespace v8
