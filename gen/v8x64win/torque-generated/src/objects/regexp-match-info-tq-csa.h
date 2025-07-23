#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_REGEXP_MATCH_INFO_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_REGEXP_MATCH_INFO_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=5&c=1
TNode<RegExpMatchInfo> Cast_RegExpMatchInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=14&c=9
TNode<Smi> LoadRegExpMatchInfoLength_0(compiler::CodeAssemblerState* state_, TNode<RegExpMatchInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=15&c=3
TNode<Smi> LoadRegExpMatchInfoNumberOfCaptureRegisters_0(compiler::CodeAssemblerState* state_, TNode<RegExpMatchInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=15&c=3
void StoreRegExpMatchInfoNumberOfCaptureRegisters_0(compiler::CodeAssemblerState* state_, TNode<RegExpMatchInfo> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=16&c=3
TNode<String> LoadRegExpMatchInfoLastSubject_0(compiler::CodeAssemblerState* state_, TNode<RegExpMatchInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=16&c=3
void StoreRegExpMatchInfoLastSubject_0(compiler::CodeAssemblerState* state_, TNode<RegExpMatchInfo> p_o, TNode<String> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=17&c=3
TNode<Object> LoadRegExpMatchInfoLastInput_0(compiler::CodeAssemblerState* state_, TNode<RegExpMatchInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=17&c=3
void StoreRegExpMatchInfoLastInput_0(compiler::CodeAssemblerState* state_, TNode<RegExpMatchInfo> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=19&c=3
TorqueStructSlice_Smi_MutableReference_Smi_0 FieldSliceRegExpMatchInfoObjects_0(compiler::CodeAssemblerState* state_, TNode<RegExpMatchInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=19&c=3
TNode<Smi> LoadRegExpMatchInfoObjects_0(compiler::CodeAssemblerState* state_, TNode<RegExpMatchInfo> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=19&c=3
void StoreRegExpMatchInfoObjects_0(compiler::CodeAssemblerState* state_, TNode<RegExpMatchInfo> p_o, TNode<IntPtrT> p_i, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=7&c=3
TNode<Smi> Method_RegExpMatchInfo_GetStartOfCapture_0(compiler::CodeAssemblerState* state_, TNode<RegExpMatchInfo> p_this, int31_t p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=10&c=3
TNode<Smi> Method_RegExpMatchInfo_GetEndOfCapture_0(compiler::CodeAssemblerState* state_, TNode<RegExpMatchInfo> p_this, int31_t p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=5&c=1
TNode<RegExpMatchInfo> DownCastForTorqueClass_RegExpMatchInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_REGEXP_MATCH_INFO_TQ_CSA_H_
