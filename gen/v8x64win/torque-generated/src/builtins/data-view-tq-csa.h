#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_DATA_VIEW_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_DATA_VIEW_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=9&c=1
const char* kBuiltinNameByteLength_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=11&c=1
const char* kBuiltinNameByteOffset_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=14&c=1
TNode<String> MakeDataViewGetterNameString_0(compiler::CodeAssemblerState* state_, ElementsKind p_kind);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=42&c=1
TNode<String> MakeDataViewSetterNameString_0(compiler::CodeAssemblerState* state_, ElementsKind p_kind);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=70&c=1
TNode<BoolT> WasDetached_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBufferView> p_view);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=74&c=1
TNode<JSDataViewOrRabGsabDataView> ValidateDataView_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, TNode<String> p_method);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=148&c=1
TNode<Smi> LoadDataView8_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, bool p_signed);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=157&c=1
TNode<Number> LoadDataView16_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<BoolT> p_requestedLittleEndian, bool p_signed);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=184&c=1
TNode<Number> LoadDataView32_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<BoolT> p_requestedLittleEndian, ElementsKind p_kind);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=212&c=1
TNode<Number> LoadDataViewFloat16_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<BoolT> p_requestedLittleEndian);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=230&c=1
TNode<Number> LoadDataViewFloat64_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<BoolT> p_requestedLittleEndian);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=261&c=1
int31_t kZeroDigitBigInt_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=262&c=1
int31_t kOneDigitBigInt_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=263&c=1
int31_t kTwoDigitBigInt_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=266&c=1
TNode<BigInt> MakeBigIntOn64Bit_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Uint32T> p_lowWord, TNode<Uint32T> p_highWord, bool p_signed);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=295&c=1
TNode<BigInt> MakeBigIntOn32Bit_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Uint32T> p_lowWord, TNode<Uint32T> p_highWord, bool p_signed);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=363&c=1
TNode<BigInt> MakeBigInt_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Uint32T> p_lowWord, TNode<Uint32T> p_highWord, bool p_signed);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=375&c=1
TNode<BigInt> LoadDataViewBigInt_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<BoolT> p_requestedLittleEndian, bool p_signed);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=407&c=1
TNode<Numeric> DataViewGet_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, TNode<Object> p_requestIndex, TNode<Object> p_requestedLittleEndian, ElementsKind p_kind);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=588&c=1
void StoreDataView8_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<Uint32T> p_value);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=593&c=1
void StoreDataView16_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<Uint32T> p_value, TNode<BoolT> p_requestedLittleEndian);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=610&c=1
void StoreDataView32_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<Uint32T> p_value, TNode<BoolT> p_requestedLittleEndian);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=633&c=1
void StoreDataView64_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<Uint32T> p_lowWord, TNode<Uint32T> p_highWord, TNode<BoolT> p_requestedLittleEndian);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=677&c=1
void StoreDataViewBigInt_0(compiler::CodeAssemblerState* state_, TNode<JSArrayBuffer> p_buffer, TNode<UintPtrT> p_offset, TNode<BigInt> p_bigIntValue, TNode<BoolT> p_requestedLittleEndian);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=716&c=1
TNode<Object> DataViewSet_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, TNode<Object> p_requestIndex, TNode<Object> p_value, TNode<Object> p_requestedLittleEndian, ElementsKind p_kind);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=77&c=5
TNode<JSDataView> Cast_JSDataView_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=78&c=14
TNode<JSDataView> UnsafeCast_JSDataView_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=80&c=5
TNode<JSRabGsabDataView> Cast_JSRabGsabDataView_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/data-view.tq?l=81&c=14
TNode<JSRabGsabDataView> UnsafeCast_JSRabGsabDataView_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_DATA_VIEW_TQ_CSA_H_
