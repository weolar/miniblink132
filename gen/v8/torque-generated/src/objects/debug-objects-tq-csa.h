#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_DEBUG_OBJECTS_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_DEBUG_OBJECTS_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=5&c=1
TNode<BreakPoint> Cast_BreakPoint_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=10&c=1
TNode<BreakPointInfo> Cast_BreakPointInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=33&c=1
TNode<DebugInfo> Cast_DebugInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=62&c=1
TNode<CoverageInfo> Cast_CoverageInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=72&c=1
TNode<StackFrameInfo> Cast_StackFrameInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=84&c=1
TNode<StackTraceInfo> Cast_StackTraceInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=104&c=1
TNode<ErrorStackData> Cast_ErrorStackData_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=6&c=3
TNode<Smi> LoadBreakPointId_0(compiler::CodeAssemblerState* state_, TNode<BreakPoint> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=6&c=3
void StoreBreakPointId_0(compiler::CodeAssemblerState* state_, TNode<BreakPoint> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=7&c=3
TNode<String> LoadBreakPointCondition_0(compiler::CodeAssemblerState* state_, TNode<BreakPoint> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=7&c=3
void StoreBreakPointCondition_0(compiler::CodeAssemblerState* state_, TNode<BreakPoint> p_o, TNode<String> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=12&c=3
TNode<Smi> LoadBreakPointInfoSourcePosition_0(compiler::CodeAssemblerState* state_, TNode<BreakPointInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=12&c=3
void StoreBreakPointInfoSourcePosition_0(compiler::CodeAssemblerState* state_, TNode<BreakPointInfo> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=14&c=3
TNode<HeapObject> LoadBreakPointInfoBreakPoints_0(compiler::CodeAssemblerState* state_, TNode<BreakPointInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=14&c=3
void StoreBreakPointInfoBreakPoints_0(compiler::CodeAssemblerState* state_, TNode<BreakPointInfo> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=34&c=3
TNode<SharedFunctionInfo> LoadDebugInfoShared_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=34&c=3
void StoreDebugInfoShared_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o, TNode<SharedFunctionInfo> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=36&c=3
TNode<Smi> LoadDebugInfoDebuggerHints_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=36&c=3
void StoreDebugInfoDebuggerHints_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=38&c=3
TNode<FixedArray> LoadDebugInfoBreakPoints_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=38&c=3
void StoreDebugInfoBreakPoints_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=40&c=36
TNode<Smi> LoadDebugInfoFlags_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=40&c=36
void StoreDebugInfoFlags_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=41&c=3
TNode<HeapObject> LoadDebugInfoCoverageInfo_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=41&c=3
void StoreDebugInfoCoverageInfo_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=45&c=3
TNode<TrustedPointerT> LoadDebugInfoOriginalBytecodeArray_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=45&c=3
void StoreDebugInfoOriginalBytecodeArray_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=49&c=3
TNode<TrustedPointerT> LoadDebugInfoDebugBytecodeArray_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=49&c=3
void StoreDebugInfoDebugBytecodeArray_0(compiler::CodeAssemblerState* state_, TNode<DebugInfo> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=63&c=9
TNode<Int32T> LoadCoverageInfoSlotCount_0(compiler::CodeAssemblerState* state_, TNode<CoverageInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
TorqueStructSlice_CoverageInfoSlot_MutableReference_CoverageInfoSlot_0 FieldSliceCoverageInfoSlots_0(
    compiler::CodeAssemblerState* state_, TNode<CoverageInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=79&c=3
TNode<HeapObject> LoadStackFrameInfoSharedOrScript_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=79&c=3
void StoreStackFrameInfoSharedOrScript_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=80&c=3
TNode<String> LoadStackFrameInfoFunctionName_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=80&c=3
void StoreStackFrameInfoFunctionName_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<String> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=81&c=3
TNode<Smi> LoadStackFrameInfoFlags_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=81&c=3
void StoreStackFrameInfoFlags_0(compiler::CodeAssemblerState* state_, TNode<StackFrameInfo> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=86&c=3
TNode<Smi> LoadStackTraceInfoId_0(compiler::CodeAssemblerState* state_, TNode<StackTraceInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=86&c=3
void StoreStackTraceInfoId_0(compiler::CodeAssemblerState* state_, TNode<StackTraceInfo> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=88&c=3
TNode<FixedArray> LoadStackTraceInfoFrames_0(compiler::CodeAssemblerState* state_, TNode<StackTraceInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=88&c=3
void StoreStackTraceInfoFrames_0(compiler::CodeAssemblerState* state_, TNode<StackTraceInfo> p_o, TNode<FixedArray> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=108&c=3
TNode<Object> LoadErrorStackDataCallSiteInfosOrFormattedStack_0(compiler::CodeAssemblerState* state_, TNode<ErrorStackData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=108&c=3
void StoreErrorStackDataCallSiteInfosOrFormattedStack_0(compiler::CodeAssemblerState* state_, TNode<ErrorStackData> p_o, TNode<Object> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=110&c=3
TNode<StackTraceInfo> LoadErrorStackDataStackTrace_0(compiler::CodeAssemblerState* state_, TNode<ErrorStackData> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=110&c=3
void StoreErrorStackDataStackTrace_0(compiler::CodeAssemblerState* state_, TNode<ErrorStackData> p_o, TNode<StackTraceInfo> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=5&c=1
TNode<BreakPoint> DownCastForTorqueClass_BreakPoint_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=10&c=1
TNode<BreakPointInfo> DownCastForTorqueClass_BreakPointInfo_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=33&c=1
TNode<DebugInfo> DownCastForTorqueClass_DebugInfo_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=62&c=1
TNode<CoverageInfo> DownCastForTorqueClass_CoverageInfo_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=72&c=1
TNode<StackFrameInfo> DownCastForTorqueClass_StackFrameInfo_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=84&c=1
TNode<StackTraceInfo> DownCastForTorqueClass_StackTraceInfo_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=104&c=1
TNode<ErrorStackData> DownCastForTorqueClass_ErrorStackData_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
TorqueStructSlice_CoverageInfoSlot_MutableReference_CoverageInfoSlot_0 NewMutableSlice_CoverageInfoSlot_0(
    compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_DEBUG_OBJECTS_TQ_CSA_H_
