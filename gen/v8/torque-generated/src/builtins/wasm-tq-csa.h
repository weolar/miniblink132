#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_WASM_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_WASM_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=98&c=1
TNode<Int32T> NumberToInt32_0(compiler::CodeAssemblerState* state_, TNode<Number> p_input);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=101&c=1
TNode<Uint32T> NumberToUint32_0(compiler::CodeAssemblerState* state_, TNode<Number> p_input);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=143&c=1
TNode<NativeContext> LoadContextFromFrame_0(compiler::CodeAssemblerState* state_);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=147&c=1
TNode<WasmTrustedInstanceData> LoadMaybeSharedInstanceDataFromFrame_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_extractSharedData);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=157&c=1
TNode<WasmTrustedInstanceData> LoadMaybeSharedInstanceDataFromFrame_1(compiler::CodeAssemblerState* state_, TNode<Smi> p_extractSharedData);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=616&c=1
TNode<Number> UintPtrToNumberRounding_0(compiler::CodeAssemblerState* state_, TNode<UintPtrT> p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=652&c=1
void UpdateCallRefOrIndirectIC_0(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_vector, TNode<IntPtrT> p_index, TNode<Object> p_target);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=896&c=1
void ModifyThreadInWasmFlag_0(compiler::CodeAssemblerState* state_, TNode<Int32T> p_newValue);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=951&c=1
TNode<String> StringFromTwoByteSlice_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length, TorqueStructSlice_char16_ConstReference_char16_0 p_slice);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1227&c=1
TNode<BoolT> IsWtf8CodepointStart_0(compiler::CodeAssemblerState* state_, TNode<ByteArray> p_view, TNode<Uint32T> p_pos);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1232&c=1
TNode<Uint32T> AlignWtf8PositionForward_0(compiler::CodeAssemblerState* state_, TNode<ByteArray> p_view, TNode<Uint32T> p_pos);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1249&c=1
TNode<Uint32T> AlignWtf8PositionBackward_0(compiler::CodeAssemblerState* state_, TNode<ByteArray> p_view, TNode<Uint32T> p_pos);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1376&c=1
TNode<BoolT> IsLeadSurrogate_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_code);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1379&c=1
TNode<BoolT> IsTrailSurrogate_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_code);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1382&c=1
TNode<Int32T> CombineSurrogatePair_0(compiler::CodeAssemblerState* state_, TNode<Uint16T> p_lead, TNode<Uint16T> p_trail);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=341&c=12
TNode<BoolT> Is_WasmFuncRef_HeapObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=341&c=38
TNode<BoolT> Is_WasmNull_HeapObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=341&c=61
TNode<BoolT> Is_Tuple2_HeapObject_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=373&c=10
TNode<BoolT> Is_WasmFuncRef_WasmFuncRef_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<WasmFuncRef> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=373&c=36
TNode<BoolT> Is_WasmNull_WasmFuncRef_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<WasmFuncRef> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=402&c=12
TNode<BoolT> Is_WasmFuncRef_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=512&c=7
TNode<IntPtrT> Convert_intptr_constexpr_int32_0(compiler::CodeAssemblerState* state_, int32_t p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=582&c=20
TNode<WasmArray> UnsafeCast_WasmArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1004&c=12
TNode<String> AllocateSeqTwoByteString_SliceIterator_char16_ConstReference_char16_0(
    compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length, TorqueStructSliceIterator_char16_ConstReference_char16_0 p_content);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1008&c=10
TNode<SeqOneByteString> AllocateNonEmptySeqOneByteString_TwoByteToOneByteIterator_0(
    compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length, TorqueStructTwoByteToOneByteIterator_0 p_content);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1035&c=26
TorqueStructSlice_char16_ConstReference_char16_0 NewConstSlice_char16_0(
    compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1142&c=26
TorqueStructSlice_char16_MutableReference_char16_0 NewMutableSlice_char16_0(
    compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1151&c=39
TNode<Uint16T> Convert_uint16_char8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1357&c=14
TNode<SeqOneByteString> AllocateNonEmptySeqOneByteString_SliceIterator_char8_ConstReference_char8_0(
    compiler::CodeAssemblerState* state_, TNode<Uint32T> p_length, TorqueStructSliceIterator_char8_ConstReference_char8_0 p_content);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1556&c=23
TNode<MaybeObject> StrongToWeak_Map_0(compiler::CodeAssemblerState* state_, TNode<Map> p_x);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_WasmCodePointer_0 NewOffHeapReference_WasmCodePointer_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_int32_0 NewOffHeapReference_int32_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_bool_0 NewOffHeapReference_bool_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_RawPtr_intptr_0 NewOffHeapReference_RawPtr_intptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_int64_0 NewOffHeapReference_int64_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_float64_0 NewOffHeapReference_float64_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_float32_0 NewOffHeapReference_float32_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=884&c=10
TorqueStructReference_uintptr_0 NewOffHeapReference_uintptr_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_ptr);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_WASM_TQ_CSA_H_
