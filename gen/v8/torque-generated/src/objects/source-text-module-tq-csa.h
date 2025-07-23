#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_SOURCE_TEXT_MODULE_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_SOURCE_TEXT_MODULE_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=12&c=1
TNode<SourceTextModule> Cast_SourceTextModule_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=58&c=1
TNode<ModuleRequest> Cast_ModuleRequest_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=68&c=1
TNode<SourceTextModuleInfoEntry> Cast_SourceTextModuleInfoEntry_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=14&c=3
TNode<HeapObject> LoadSourceTextModuleCode_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=14&c=3
void StoreSourceTextModuleCode_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=20&c=3
TNode<FixedArray> LoadSourceTextModuleRegularExports_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=20&c=3
void StoreSourceTextModuleRegularExports_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=21&c=3
TNode<FixedArray> LoadSourceTextModuleRegularImports_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=21&c=3
void StoreSourceTextModuleRegularImports_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=26&c=3
TNode<FixedArray> LoadSourceTextModuleRequestedModules_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=26&c=3
void StoreSourceTextModuleRequestedModules_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=31&c=36
TNode<HeapObject> LoadSourceTextModuleImportMeta_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=31&c=36
void StoreSourceTextModuleImportMeta_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=36&c=3
TNode<HeapObject> LoadSourceTextModuleCycleRoot_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=36&c=3
void StoreSourceTextModuleCycleRoot_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=38&c=3
TNode<ArrayList> LoadSourceTextModuleAsyncParentModules_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=38&c=3
void StoreSourceTextModuleAsyncParentModules_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<ArrayList> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=41&c=3
TNode<Smi> LoadSourceTextModuleDfsIndex_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=41&c=3
void StoreSourceTextModuleDfsIndex_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=42&c=3
TNode<Smi> LoadSourceTextModuleDfsAncestorIndex_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=42&c=3
void StoreSourceTextModuleDfsAncestorIndex_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=45&c=3
TNode<Smi> LoadSourceTextModulePendingAsyncDependencies_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=45&c=3
void StoreSourceTextModulePendingAsyncDependencies_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=47&c=3
TNode<Smi> LoadSourceTextModuleFlags_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=47&c=3
void StoreSourceTextModuleFlags_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModule> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=59&c=3
TNode<String> LoadModuleRequestSpecifier_0(compiler::CodeAssemblerState* state_, TNode<ModuleRequest> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=59&c=3
void StoreModuleRequestSpecifier_0(compiler::CodeAssemblerState* state_, TNode<ModuleRequest> p_o, TNode<String> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=63&c=3
TNode<FixedArray> LoadModuleRequestImportAttributes_0(compiler::CodeAssemblerState* state_, TNode<ModuleRequest> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=63&c=3
void StoreModuleRequestImportAttributes_0(compiler::CodeAssemblerState* state_, TNode<ModuleRequest> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=65&c=3
TNode<Smi> LoadModuleRequestFlags_0(compiler::CodeAssemblerState* state_, TNode<ModuleRequest> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=65&c=3
void StoreModuleRequestFlags_0(compiler::CodeAssemblerState* state_, TNode<ModuleRequest> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=69&c=3
TNode<PrimitiveHeapObject> LoadSourceTextModuleInfoEntryExportName_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=69&c=3
void StoreSourceTextModuleInfoEntryExportName_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o, TNode<PrimitiveHeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=70&c=3
TNode<PrimitiveHeapObject> LoadSourceTextModuleInfoEntryLocalName_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=70&c=3
void StoreSourceTextModuleInfoEntryLocalName_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o, TNode<PrimitiveHeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=71&c=3
TNode<PrimitiveHeapObject> LoadSourceTextModuleInfoEntryImportName_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=71&c=3
void StoreSourceTextModuleInfoEntryImportName_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o, TNode<PrimitiveHeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=72&c=3
TNode<Smi> LoadSourceTextModuleInfoEntryModuleRequest_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=72&c=3
void StoreSourceTextModuleInfoEntryModuleRequest_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=73&c=3
TNode<Smi> LoadSourceTextModuleInfoEntryCellIndex_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=73&c=3
void StoreSourceTextModuleInfoEntryCellIndex_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=74&c=3
TNode<Smi> LoadSourceTextModuleInfoEntryBegPos_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=74&c=3
void StoreSourceTextModuleInfoEntryBegPos_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=75&c=3
TNode<Smi> LoadSourceTextModuleInfoEntryEndPos_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=75&c=3
void StoreSourceTextModuleInfoEntryEndPos_0(compiler::CodeAssemblerState* state_, TNode<SourceTextModuleInfoEntry> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=12&c=1
TNode<SourceTextModule> DownCastForTorqueClass_SourceTextModule_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=58&c=1
TNode<ModuleRequest> DownCastForTorqueClass_ModuleRequest_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=68&c=1
TNode<SourceTextModuleInfoEntry> DownCastForTorqueClass_SourceTextModuleInfoEntry_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_SOURCE_TEXT_MODULE_TQ_CSA_H_
