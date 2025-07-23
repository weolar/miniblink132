#ifndef V8_GEN_TORQUE_GENERATED_SRC_WASM_WASM_OBJECTS_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_WASM_WASM_OBJECTS_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=22&c=1
TNode<Uint8T> FromConstexpr_AddressType_constexpr_kI32_0(compiler::CodeAssemblerState* state_, wasm::AddressType p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=22&c=1
TNode<Uint8T> FromConstexpr_AddressType_constexpr_kI64_0(compiler::CodeAssemblerState* state_, wasm::AddressType p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=31&c=1
TNode<WasmTrustedInstanceData> Cast_WasmTrustedInstanceData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=33&c=1
TNode<WasmInstanceObject> Cast_WasmInstanceObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=43&c=1
TNode<WasmImportData> Cast_WasmImportData_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=66&c=1
TNode<WasmFastApiCallData> Cast_WasmFastApiCallData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=74&c=1
TNode<WasmInternalFunction> Cast_WasmInternalFunction_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=109&c=1
TNode<WasmFuncRef> Cast_WasmFuncRef_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=118&c=1
TNode<WasmFunctionData> Cast_WasmFunctionData_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=134&c=1
TNode<WasmExportedFunctionData> Cast_WasmExportedFunctionData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=157&c=1
TNode<WasmJSFunctionData> Cast_WasmJSFunctionData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=163&c=1
TNode<WasmCapiFunctionData> Cast_WasmCapiFunctionData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=170&c=1
TNode<WasmResumeData> Cast_WasmResumeData_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=175&c=1
TNode<WasmContinuationObject> Cast_WasmContinuationObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=181&c=1
TNode<WasmSuspenderObject> Cast_WasmSuspenderObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=190&c=1
TNode<WasmExceptionTag> Cast_WasmExceptionTag_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=197&c=1
TNode<WasmExceptionPackage> Cast_WasmExceptionPackage_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=199&c=1
TNode<WasmModuleObject> Cast_WasmModuleObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=204&c=1
TNode<WasmDispatchTable> Cast_WasmDispatchTable_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=206&c=1
TNode<WasmTableObject> Cast_WasmTableObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=237&c=1
TNode<WasmMemoryObject> Cast_WasmMemoryObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=248&c=1
TNode<WasmGlobalObject> Cast_WasmGlobalObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=262&c=1
TNode<WasmTagObject> Cast_WasmTagObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=271&c=1
TNode<AsmWasmData> Cast_AsmWasmData_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=276&c=1
TNode<WasmTypeInfo> Cast_WasmTypeInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=299&c=1
TNode<WasmObject> Cast_WasmObject_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=302&c=1
TNode<WasmStruct> Cast_WasmStruct_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=305&c=1
TNode<WasmArray> Cast_WasmArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=313&c=1
TNode<WasmStringViewIter> Cast_WasmStringViewIter_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=321&c=1
TNode<WasmNull> Cast_WasmNull_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=324&c=1
TNode<WasmNull> kWasmNull_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=326&c=1
TNode<WasmSuspendingObject> Cast_WasmSuspendingObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=111&c=3
TNode<TrustedPointerT> LoadWasmFuncRefTrustedInternal_0(compiler::CodeAssemblerState* state_, TNode<WasmFuncRef> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=111&c=3
void StoreWasmFuncRefTrustedInternal_0(compiler::CodeAssemblerState* state_, TNode<WasmFuncRef> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=47&c=3
TNode<MaybeObject> LoadWasmImportDataProtectedInstanceData_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=47&c=3
void StoreWasmImportDataProtectedInstanceData_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=48&c=3
TNode<NativeContext> LoadWasmImportDataNativeContext_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=48&c=3
void StoreWasmImportDataNativeContext_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o, TNode<NativeContext> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=49&c=3
TNode<HeapObject> LoadWasmImportDataCallable_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=49&c=3
void StoreWasmImportDataCallable_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=50&c=3
TNode<Smi> LoadWasmImportDataSuspend_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=50&c=3
void StoreWasmImportDataSuspend_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=51&c=3
TNode<Smi> LoadWasmImportDataWrapperBudget_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=51&c=3
void StoreWasmImportDataWrapperBudget_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=58&c=3
TNode<Object> LoadWasmImportDataCallOrigin_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=58&c=3
void StoreWasmImportDataCallOrigin_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=60&c=3
TNode<RawPtrT> LoadWasmImportDataSig_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=60&c=3
void StoreWasmImportDataSig_0(compiler::CodeAssemblerState* state_, TNode<WasmImportData> p_o, TNode<RawPtrT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=34&c=3
TNode<TrustedPointerT> LoadWasmInstanceObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmInstanceObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=34&c=3
void StoreWasmInstanceObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmInstanceObject> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=35&c=3
TNode<WasmModuleObject> LoadWasmInstanceObjectModuleObject_0(compiler::CodeAssemblerState* state_, TNode<WasmInstanceObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=35&c=3
void StoreWasmInstanceObjectModuleObject_0(compiler::CodeAssemblerState* state_, TNode<WasmInstanceObject> p_o, TNode<WasmModuleObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=36&c=3
TNode<JSObject> LoadWasmInstanceObjectExportsObject_0(compiler::CodeAssemblerState* state_, TNode<WasmInstanceObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=36&c=3
void StoreWasmInstanceObjectExportsObject_0(compiler::CodeAssemblerState* state_, TNode<WasmInstanceObject> p_o, TNode<JSObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=67&c=3
TNode<HeapObject> LoadWasmFastApiCallDataSignature_0(compiler::CodeAssemblerState* state_, TNode<WasmFastApiCallData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=67&c=3
void StoreWasmFastApiCallDataSignature_0(compiler::CodeAssemblerState* state_, TNode<WasmFastApiCallData> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=68&c=3
TNode<Object> LoadWasmFastApiCallDataCallbackData_0(compiler::CodeAssemblerState* state_, TNode<WasmFastApiCallData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=68&c=3
void StoreWasmFastApiCallDataCallbackData_0(compiler::CodeAssemblerState* state_, TNode<WasmFastApiCallData> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=69&c=3
TNode<MaybeObject> LoadWasmFastApiCallDataCachedMap_0(compiler::CodeAssemblerState* state_, TNode<WasmFastApiCallData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=69&c=3
void StoreWasmFastApiCallDataCachedMap_0(compiler::CodeAssemblerState* state_, TNode<WasmFastApiCallData> p_o, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=81&c=3
TNode<MaybeObject> LoadWasmInternalFunctionProtectedImplicitArg_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=81&c=3
void StoreWasmInternalFunctionProtectedImplicitArg_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=84&c=3
TNode<HeapObject> LoadWasmInternalFunctionExternal_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=84&c=3
void StoreWasmInternalFunctionExternal_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=91&c=3
TNode<Smi> LoadWasmInternalFunctionFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=91&c=3
void StoreWasmInternalFunctionFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=93&c=3
TNode<RawPtrT> LoadWasmInternalFunctionCallTarget_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=93&c=3
void StoreWasmInternalFunctionCallTarget_0(compiler::CodeAssemblerState* state_, TNode<WasmInternalFunction> p_o, TNode<RawPtrT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=120&c=3
TNode<TrustedPointerT> LoadWasmFunctionDataWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=120&c=3
void StoreWasmFunctionDataWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=123&c=3
TNode<WasmFuncRef> LoadWasmFunctionDataFuncRef_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=123&c=3
void StoreWasmFunctionDataFuncRef_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o, TNode<WasmFuncRef> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=125&c=3
TNode<Smi> LoadWasmFunctionDataJsPromiseFlags_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=125&c=3
void StoreWasmFunctionDataJsPromiseFlags_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=128&c=3
TNode<MaybeObject> LoadWasmFunctionDataProtectedInternal_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=128&c=3
void StoreWasmFunctionDataProtectedInternal_0(compiler::CodeAssemblerState* state_, TNode<WasmFunctionData> p_o, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=138&c=3
TNode<MaybeObject> LoadWasmExportedFunctionDataProtectedInstanceData_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=138&c=3
void StoreWasmExportedFunctionDataProtectedInstanceData_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=139&c=3
TNode<Smi> LoadWasmExportedFunctionDataFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=139&c=3
void StoreWasmExportedFunctionDataFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=141&c=3
TNode<Cell> LoadWasmExportedFunctionDataWrapperBudget_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=141&c=3
void StoreWasmExportedFunctionDataWrapperBudget_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<Cell> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=142&c=3
TNode<Smi> LoadWasmExportedFunctionDataCanonicalTypeIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=142&c=3
void StoreWasmExportedFunctionDataCanonicalTypeIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=147&c=3
TNode<Smi> LoadWasmExportedFunctionDataPackedArgsSize_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=147&c=3
void StoreWasmExportedFunctionDataPackedArgsSize_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=148&c=3
TNode<TrustedPointerT> LoadWasmExportedFunctionDataCWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=148&c=3
void StoreWasmExportedFunctionDataCWrapperCode_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=150&c=3
TNode<RawPtrT> LoadWasmExportedFunctionDataSig_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=150&c=3
void StoreWasmExportedFunctionDataSig_0(compiler::CodeAssemblerState* state_, TNode<WasmExportedFunctionData> p_o, TNode<RawPtrT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=158&c=3
TNode<Smi> LoadWasmJSFunctionDataCanonicalSigIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=158&c=3
void StoreWasmJSFunctionDataCanonicalSigIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=159&c=3
TNode<MaybeObject> LoadWasmJSFunctionDataProtectedOffheapData_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=159&c=3
void StoreWasmJSFunctionDataProtectedOffheapData_0(compiler::CodeAssemblerState* state_, TNode<WasmJSFunctionData> p_o, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=165&c=3
TNode<Smi> LoadWasmCapiFunctionDataCanonicalSigIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=165&c=3
void StoreWasmCapiFunctionDataCanonicalSigIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=166&c=3
TNode<Foreign> LoadWasmCapiFunctionDataEmbedderData_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=166&c=3
void StoreWasmCapiFunctionDataEmbedderData_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o, TNode<Foreign> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=167&c=3
TNode<RawPtrT> LoadWasmCapiFunctionDataSig_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=167&c=3
void StoreWasmCapiFunctionDataSig_0(compiler::CodeAssemblerState* state_, TNode<WasmCapiFunctionData> p_o, TNode<RawPtrT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=171&c=3
TNode<WasmSuspenderObject> LoadWasmResumeDataSuspender_0(compiler::CodeAssemblerState* state_, TNode<WasmResumeData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=171&c=3
void StoreWasmResumeDataSuspender_0(compiler::CodeAssemblerState* state_, TNode<WasmResumeData> p_o, TNode<WasmSuspenderObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=172&c=3
TNode<Smi> LoadWasmResumeDataOnResume_0(compiler::CodeAssemblerState* state_, TNode<WasmResumeData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=172&c=3
void StoreWasmResumeDataOnResume_0(compiler::CodeAssemblerState* state_, TNode<WasmResumeData> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=176&c=3
TNode<HeapObject> LoadWasmContinuationObjectParent_0(compiler::CodeAssemblerState* state_, TNode<WasmContinuationObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=176&c=3
void StoreWasmContinuationObjectParent_0(compiler::CodeAssemblerState* state_, TNode<WasmContinuationObject> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=177&c=3
TNode<ExternalPointerT> LoadWasmContinuationObjectStack_0(compiler::CodeAssemblerState* state_, TNode<WasmContinuationObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=177&c=3
void StoreWasmContinuationObjectStack_0(compiler::CodeAssemblerState* state_, TNode<WasmContinuationObject> p_o, TNode<ExternalPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=178&c=3
TNode<ExternalPointerT> LoadWasmContinuationObjectJmpbuf_0(compiler::CodeAssemblerState* state_, TNode<WasmContinuationObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=178&c=3
void StoreWasmContinuationObjectJmpbuf_0(compiler::CodeAssemblerState* state_, TNode<WasmContinuationObject> p_o, TNode<ExternalPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=182&c=3
TNode<HeapObject> LoadWasmSuspenderObjectContinuation_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=182&c=3
void StoreWasmSuspenderObjectContinuation_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=183&c=3
TNode<HeapObject> LoadWasmSuspenderObjectParent_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=183&c=3
void StoreWasmSuspenderObjectParent_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=184&c=3
TNode<JSPromise> LoadWasmSuspenderObjectPromise_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=184&c=3
void StoreWasmSuspenderObjectPromise_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o, TNode<JSPromise> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=185&c=3
TNode<HeapObject> LoadWasmSuspenderObjectResume_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=185&c=3
void StoreWasmSuspenderObjectResume_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=186&c=3
TNode<HeapObject> LoadWasmSuspenderObjectReject_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=186&c=3
void StoreWasmSuspenderObjectReject_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=187&c=3
TNode<Smi> LoadWasmSuspenderObjectState_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=187&c=3
void StoreWasmSuspenderObjectState_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspenderObject> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=194&c=3
TNode<Smi> LoadWasmExceptionTagIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExceptionTag> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=194&c=3
void StoreWasmExceptionTagIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmExceptionTag> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=200&c=3
TNode<Foreign> LoadWasmModuleObjectManagedNativeModule_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=200&c=3
void StoreWasmModuleObjectManagedNativeModule_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o, TNode<Foreign> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=201&c=3
TNode<Script> LoadWasmModuleObjectScript_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=201&c=3
void StoreWasmModuleObjectScript_0(compiler::CodeAssemblerState* state_, TNode<WasmModuleObject> p_o, TNode<Script> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=215&c=3
TNode<FixedArray> LoadWasmTableObjectEntries_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=215&c=3
void StoreWasmTableObjectEntries_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=216&c=3
TNode<Smi> LoadWasmTableObjectCurrentLength_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=216&c=3
void StoreWasmTableObjectCurrentLength_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=221&c=3
TNode<Object> LoadWasmTableObjectMaximumLength_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=221&c=3
void StoreWasmTableObjectMaximumLength_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=224&c=3
TNode<FixedArray> LoadWasmTableObjectUses_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=224&c=3
void StoreWasmTableObjectUses_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=225&c=3
TNode<Smi> LoadWasmTableObjectRawType_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=225&c=3
void StoreWasmTableObjectRawType_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=229&c=3
TNode<TrustedPointerT> LoadWasmTableObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=229&c=3
void StoreWasmTableObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=230&c=3
TNode<Uint8T> LoadWasmTableObjectAddressType_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=230&c=3
void StoreWasmTableObjectAddressType_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<Uint8T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=232&c=3
TNode<Uint8T> LoadWasmTableObjectPaddingForAddressType0_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=232&c=3
void StoreWasmTableObjectPaddingForAddressType0_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<Uint8T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=233&c=3
TNode<Uint16T> LoadWasmTableObjectPaddingForAddressType1_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=233&c=3
void StoreWasmTableObjectPaddingForAddressType1_0(compiler::CodeAssemblerState* state_, TNode<WasmTableObject> p_o, TNode<Uint16T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=238&c=3
TNode<JSArrayBuffer> LoadWasmMemoryObjectArrayBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=238&c=3
void StoreWasmMemoryObjectArrayBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o, TNode<JSArrayBuffer> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=239&c=3
TNode<Smi> LoadWasmMemoryObjectMaximumPages_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=239&c=3
void StoreWasmMemoryObjectMaximumPages_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=240&c=3
TNode<WeakArrayList> LoadWasmMemoryObjectInstances_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=240&c=3
void StoreWasmMemoryObjectInstances_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o, TNode<WeakArrayList> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=241&c=3
TNode<Uint8T> LoadWasmMemoryObjectAddressType_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=241&c=3
void StoreWasmMemoryObjectAddressType_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o, TNode<Uint8T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=243&c=3
TNode<Uint8T> LoadWasmMemoryObjectPaddingForAddressType0_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=243&c=3
void StoreWasmMemoryObjectPaddingForAddressType0_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o, TNode<Uint8T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=244&c=3
TNode<Uint16T> LoadWasmMemoryObjectPaddingForAddressType1_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=244&c=3
void StoreWasmMemoryObjectPaddingForAddressType1_0(compiler::CodeAssemblerState* state_, TNode<WasmMemoryObject> p_o, TNode<Uint16T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=252&c=3
TNode<TrustedPointerT> LoadWasmGlobalObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=252&c=3
void StoreWasmGlobalObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=253&c=3
TNode<HeapObject> LoadWasmGlobalObjectUntaggedBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=253&c=3
void StoreWasmGlobalObjectUntaggedBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=254&c=3
TNode<HeapObject> LoadWasmGlobalObjectTaggedBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=254&c=3
void StoreWasmGlobalObjectTaggedBuffer_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=255&c=3
TNode<Smi> LoadWasmGlobalObjectOffset_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=255&c=3
void StoreWasmGlobalObjectOffset_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=256&c=3
TNode<Smi> LoadWasmGlobalObjectRawType_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=256&c=3
void StoreWasmGlobalObjectRawType_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=259&c=3
TNode<Smi> LoadWasmGlobalObjectIsMutable_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=259&c=3
void StoreWasmGlobalObjectIsMutable_0(compiler::CodeAssemblerState* state_, TNode<WasmGlobalObject> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=263&c=3
TNode<ByteArray> LoadWasmTagObjectSerializedSignature_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=263&c=3
void StoreWasmTagObjectSerializedSignature_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o, TNode<ByteArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=264&c=3
TNode<HeapObject> LoadWasmTagObjectTag_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=264&c=3
void StoreWasmTagObjectTag_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=265&c=3
TNode<Smi> LoadWasmTagObjectCanonicalTypeIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=265&c=3
void StoreWasmTagObjectCanonicalTypeIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=266&c=3
TNode<TrustedPointerT> LoadWasmTagObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=266&c=3
void StoreWasmTagObjectTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmTagObject> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=272&c=3
TNode<Foreign> LoadAsmWasmDataManagedNativeModule_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=272&c=3
void StoreAsmWasmDataManagedNativeModule_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o, TNode<Foreign> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=273&c=3
TNode<HeapNumber> LoadAsmWasmDataUsesBitset_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=273&c=3
void StoreAsmWasmDataUsesBitset_0(compiler::CodeAssemblerState* state_, TNode<AsmWasmData> p_o, TNode<HeapNumber> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=285&c=3
TNode<ExternalPointerT> LoadWasmTypeInfoNativeType_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=285&c=3
void StoreWasmTypeInfoNativeType_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o, TNode<ExternalPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=286&c=3
TNode<Uint32T> LoadWasmTypeInfoModuleTypeIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=286&c=3
void StoreWasmTypeInfoModuleTypeIndex_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=290&c=3
TNode<TrustedPointerT> LoadWasmTypeInfoTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=290&c=3
void StoreWasmTypeInfoTrustedData_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=291&c=9
TNode<Smi> LoadWasmTypeInfoSupertypesLength_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
TorqueStructSlice_Object_MutableReference_Object_0 FieldSliceWasmTypeInfoSupertypes_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
TNode<Object> LoadWasmTypeInfoSupertypes_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
void StoreWasmTypeInfoSupertypes_0(compiler::CodeAssemblerState* state_, TNode<WasmTypeInfo> p_o, TNode<IntPtrT> p_i, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=307&c=3
TNode<Uint32T> LoadWasmArrayLength_0(compiler::CodeAssemblerState* state_, TNode<WasmArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=307&c=3
void StoreWasmArrayLength_0(compiler::CodeAssemblerState* state_, TNode<WasmArray> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=314&c=3
TNode<String> LoadWasmStringViewIterString_0(compiler::CodeAssemblerState* state_, TNode<WasmStringViewIter> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=314&c=3
void StoreWasmStringViewIterString_0(compiler::CodeAssemblerState* state_, TNode<WasmStringViewIter> p_o, TNode<String> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=315&c=3
TNode<Uint32T> LoadWasmStringViewIterOffset_0(compiler::CodeAssemblerState* state_, TNode<WasmStringViewIter> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=315&c=3
void StoreWasmStringViewIterOffset_0(compiler::CodeAssemblerState* state_, TNode<WasmStringViewIter> p_o, TNode<Uint32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=327&c=3
TNode<JSReceiver> LoadWasmSuspendingObjectCallable_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspendingObject> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=327&c=3
void StoreWasmSuspendingObjectCallable_0(compiler::CodeAssemblerState* state_, TNode<WasmSuspendingObject> p_o, TNode<JSReceiver> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=31&c=1
TNode<WasmTrustedInstanceData> DownCastForTorqueClass_WasmTrustedInstanceData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=33&c=1
TNode<WasmInstanceObject> DownCastForTorqueClass_WasmInstanceObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=43&c=1
TNode<WasmImportData> DownCastForTorqueClass_WasmImportData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=66&c=1
TNode<WasmFastApiCallData> DownCastForTorqueClass_WasmFastApiCallData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=74&c=1
TNode<WasmInternalFunction> DownCastForTorqueClass_WasmInternalFunction_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=109&c=1
TNode<WasmFuncRef> DownCastForTorqueClass_WasmFuncRef_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=118&c=1
TNode<WasmFunctionData> DownCastForTorqueClass_WasmFunctionData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=134&c=1
TNode<WasmExportedFunctionData> DownCastForTorqueClass_WasmExportedFunctionData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=157&c=1
TNode<WasmJSFunctionData> DownCastForTorqueClass_WasmJSFunctionData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=163&c=1
TNode<WasmCapiFunctionData> DownCastForTorqueClass_WasmCapiFunctionData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=170&c=1
TNode<WasmResumeData> DownCastForTorqueClass_WasmResumeData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=175&c=1
TNode<WasmContinuationObject> DownCastForTorqueClass_WasmContinuationObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=181&c=1
TNode<WasmSuspenderObject> DownCastForTorqueClass_WasmSuspenderObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=190&c=1
TNode<WasmExceptionTag> DownCastForTorqueClass_WasmExceptionTag_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=197&c=1
TNode<WasmExceptionPackage> DownCastForTorqueClass_WasmExceptionPackage_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=199&c=1
TNode<WasmModuleObject> DownCastForTorqueClass_WasmModuleObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=204&c=1
TNode<WasmDispatchTable> DownCastForTorqueClass_WasmDispatchTable_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=206&c=1
TNode<WasmTableObject> DownCastForTorqueClass_WasmTableObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=237&c=1
TNode<WasmMemoryObject> DownCastForTorqueClass_WasmMemoryObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=248&c=1
TNode<WasmGlobalObject> DownCastForTorqueClass_WasmGlobalObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=262&c=1
TNode<WasmTagObject> DownCastForTorqueClass_WasmTagObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=271&c=1
TNode<AsmWasmData> DownCastForTorqueClass_AsmWasmData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=276&c=1
TNode<WasmTypeInfo> DownCastForTorqueClass_WasmTypeInfo_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=299&c=1
TNode<WasmObject> DownCastForTorqueClass_WasmObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=302&c=1
TNode<WasmStruct> DownCastForTorqueClass_WasmStruct_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=305&c=1
TNode<WasmArray> DownCastForTorqueClass_WasmArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=313&c=1
TNode<WasmStringViewIter> DownCastForTorqueClass_WasmStringViewIter_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=321&c=1
TNode<WasmNull> DownCastForTorqueClass_WasmNull_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=326&c=1
TNode<WasmSuspendingObject> DownCastForTorqueClass_WasmSuspendingObject_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_WASM_WASM_OBJECTS_TQ_CSA_H_
