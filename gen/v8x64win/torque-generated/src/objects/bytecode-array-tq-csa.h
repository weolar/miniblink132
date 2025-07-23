#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_BYTECODE_ARRAY_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_BYTECODE_ARRAY_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=7&c=1
TNode<BytecodeArray> Cast_BytecodeArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=26&c=1
TNode<BytecodeWrapper> Cast_BytecodeWrapper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=31&c=1
TNode<Code> Cast_Code_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=32&c=1
TNode<CodeWrapper> Cast_CodeWrapper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=9&c=9
TNode<Smi> LoadBytecodeArrayLength_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=10&c=3
TNode<BytecodeWrapper> LoadBytecodeArrayWrapper_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=10&c=3
void StoreBytecodeArrayWrapper_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<BytecodeWrapper> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=11&c=3
TNode<MaybeObject> LoadBytecodeArraySourcePositionTable_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=11&c=3
void StoreBytecodeArraySourcePositionTable_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=12&c=3
TNode<MaybeObject> LoadBytecodeArrayHandlerTable_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=12&c=3
void StoreBytecodeArrayHandlerTable_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=13&c=3
TNode<MaybeObject> LoadBytecodeArrayConstantPool_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=13&c=3
void StoreBytecodeArrayConstantPool_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<MaybeObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=14&c=3
TNode<Int32T> LoadBytecodeArrayFrameSize_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=14&c=3
void StoreBytecodeArrayFrameSize_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<Int32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=15&c=3
TNode<Uint16T> LoadBytecodeArrayParameterSize_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=15&c=3
void StoreBytecodeArrayParameterSize_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<Uint16T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=16&c=3
TNode<Uint16T> LoadBytecodeArrayMaxArguments_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=16&c=3
void StoreBytecodeArrayMaxArguments_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<Uint16T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=17&c=3
TNode<Int32T> LoadBytecodeArrayIncomingNewTargetOrGeneratorRegister_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=17&c=3
void StoreBytecodeArrayIncomingNewTargetOrGeneratorRegister_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<Int32T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=20&c=3
TorqueStructSlice_uint8_MutableReference_uint8_0 FieldSliceBytecodeArrayBytes_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=20&c=3
TNode<Uint8T> LoadBytecodeArrayBytes_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<IntPtrT> p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=20&c=3
void StoreBytecodeArrayBytes_0(compiler::CodeAssemblerState* state_, TNode<BytecodeArray> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=28&c=3
TNode<TrustedPointerT> LoadBytecodeWrapperBytecode_0(compiler::CodeAssemblerState* state_, TNode<BytecodeWrapper> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=28&c=3
void StoreBytecodeWrapperBytecode_0(compiler::CodeAssemblerState* state_, TNode<BytecodeWrapper> p_o, TNode<TrustedPointerT> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=7&c=1
TNode<BytecodeArray> DownCastForTorqueClass_BytecodeArray_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=26&c=1
TNode<BytecodeWrapper> DownCastForTorqueClass_BytecodeWrapper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=31&c=1
TNode<Code> DownCastForTorqueClass_Code_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=32&c=1
TNode<CodeWrapper> DownCastForTorqueClass_CodeWrapper_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=20&c=3
TorqueStructSlice_uint8_MutableReference_uint8_0 NewMutableSlice_uint8_0(compiler::CodeAssemblerState* state_, TNode<Object> p_object, TNode<IntPtrT> p_offset, TNode<IntPtrT> p_length);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_BYTECODE_ARRAY_TQ_CSA_H_
