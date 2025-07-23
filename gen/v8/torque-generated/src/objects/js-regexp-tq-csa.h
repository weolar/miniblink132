#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_REGEXP_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_REGEXP_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=17&c=1
TNode<RegExpData> Cast_RegExpData_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=25&c=1
TNode<AtomRegExpData> Cast_AtomRegExpData_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=30&c=1
TNode<IrRegExpData> Cast_IrRegExpData_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=45&c=1
TNode<RegExpDataWrapper> Cast_RegExpDataWrapper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=50&c=1
TNode<JSRegExp> Cast_JSRegExp_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=19&c=3
TNode<Smi> LoadRegExpDataTypeTag_0(compiler::CodeAssemblerState* state_, TNode<RegExpData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=19&c=3
void StoreRegExpDataTypeTag_0(compiler::CodeAssemblerState* state_, TNode<RegExpData> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=20&c=3
TNode<String> LoadRegExpDataSource_0(compiler::CodeAssemblerState* state_, TNode<RegExpData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=20&c=3
void StoreRegExpDataSource_0(compiler::CodeAssemblerState* state_, TNode<RegExpData> p_o, TNode<String> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=21&c=3
TNode<Smi> LoadRegExpDataFlags_0(compiler::CodeAssemblerState* state_, TNode<RegExpData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=21&c=3
void StoreRegExpDataFlags_0(compiler::CodeAssemblerState* state_, TNode<RegExpData> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=22&c=3
TNode<RegExpDataWrapper> LoadRegExpDataWrapper_0(compiler::CodeAssemblerState* state_, TNode<RegExpData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=22&c=3
void StoreRegExpDataWrapper_0(compiler::CodeAssemblerState* state_, TNode<RegExpData> p_o, TNode<RegExpDataWrapper> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=27&c=9
TNode<String> LoadAtomRegExpDataPattern_0(compiler::CodeAssemblerState* state_, TNode<AtomRegExpData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=34&c=3
TNode<MaybeObject> LoadIrRegExpDataLatin1Bytecode_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=34&c=3
void StoreIrRegExpDataLatin1Bytecode_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=35&c=3
TNode<MaybeObject> LoadIrRegExpDataUc16Bytecode_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=35&c=3
void StoreIrRegExpDataUc16Bytecode_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=36&c=3
TNode<TrustedPointerT> LoadIrRegExpDataLatin1Code_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=36&c=3
void StoreIrRegExpDataLatin1Code_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=37&c=3
TNode<TrustedPointerT> LoadIrRegExpDataUc16Code_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=37&c=3
void StoreIrRegExpDataUc16Code_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=38&c=3
TNode<FixedArray> LoadIrRegExpDataCaptureNameMap_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=38&c=3
void StoreIrRegExpDataCaptureNameMap_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=39&c=3
TNode<Smi> LoadIrRegExpDataMaxRegisterCount_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=39&c=3
void StoreIrRegExpDataMaxRegisterCount_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=40&c=3
TNode<Smi> LoadIrRegExpDataCaptureCount_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=40&c=3
void StoreIrRegExpDataCaptureCount_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=41&c=3
TNode<Smi> LoadIrRegExpDataTicksUntilTierUp_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=41&c=3
void StoreIrRegExpDataTicksUntilTierUp_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=42&c=3
TNode<Smi> LoadIrRegExpDataBacktrackLimit_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=42&c=3
void StoreIrRegExpDataBacktrackLimit_0(compiler::CodeAssemblerState* state_, TNode<IrRegExpData> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=47&c=3
TNode<TrustedPointerT> LoadRegExpDataWrapperData_0(compiler::CodeAssemblerState* state_, TNode<RegExpDataWrapper> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=47&c=3
void StoreRegExpDataWrapperData_0(compiler::CodeAssemblerState* state_, TNode<RegExpDataWrapper> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=51&c=3
TNode<TrustedPointerT> LoadJSRegExpData_0(compiler::CodeAssemblerState* state_, TNode<JSRegExp> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=51&c=3
void StoreJSRegExpData_0(compiler::CodeAssemblerState* state_, TNode<JSRegExp> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=52&c=3
TNode<PrimitiveHeapObject> LoadJSRegExpSource_0(compiler::CodeAssemblerState* state_, TNode<JSRegExp> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=52&c=3
void StoreJSRegExpSource_0(compiler::CodeAssemblerState* state_, TNode<JSRegExp> p_o, TNode<PrimitiveHeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=53&c=3
TNode<Object> LoadJSRegExpFlags_0(compiler::CodeAssemblerState* state_, TNode<JSRegExp> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=53&c=3
void StoreJSRegExpFlags_0(compiler::CodeAssemblerState* state_, TNode<JSRegExp> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=80&c=3
TNode<Object> LoadJSRegExpResultIndex_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=80&c=3
void StoreJSRegExpResultIndex_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=81&c=3
TNode<Object> LoadJSRegExpResultInput_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=81&c=3
void StoreJSRegExpResultInput_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=82&c=3
TNode<Object> LoadJSRegExpResultGroups_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=82&c=3
void StoreJSRegExpResultGroups_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=85&c=3
TNode<HeapObject> LoadJSRegExpResultNames_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=85&c=3
void StoreJSRegExpResultNames_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=86&c=3
TNode<String> LoadJSRegExpResultRegexpInput_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=86&c=3
void StoreJSRegExpResultRegexpInput_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o, TNode<String> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=87&c=3
TNode<Smi> LoadJSRegExpResultRegexpLastIndex_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=87&c=3
void StoreJSRegExpResultRegexpLastIndex_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=91&c=3
TNode<Object> LoadJSRegExpResultWithIndicesIndices_0(compiler::CodeAssemblerState* state_, TNode<JSRegExpResult> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=91&c=3
void StoreJSRegExpResultWithIndicesIndices_0(compiler::CodeAssemblerState* state_, TNode<JSRegExpResult> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=97&c=3
TNode<Object> LoadJSRegExpResultIndicesGroups_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=97&c=3
void StoreJSRegExpResultIndicesGroups_0(compiler::CodeAssemblerState* state_, TNode<JSArray> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=17&c=1
TNode<RegExpData> DownCastForTorqueClass_RegExpData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=25&c=1
TNode<AtomRegExpData> DownCastForTorqueClass_AtomRegExpData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=30&c=1
TNode<IrRegExpData> DownCastForTorqueClass_IrRegExpData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=45&c=1
TNode<RegExpDataWrapper> DownCastForTorqueClass_RegExpDataWrapper_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-regexp.tq?l=50&c=1
TNode<JSRegExp> DownCastForTorqueClass_JSRegExp_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_REGEXP_TQ_CSA_H_
