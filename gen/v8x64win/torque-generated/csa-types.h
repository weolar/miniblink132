#ifndef V8_GEN_TORQUE_GENERATED_CSA_TYPES_H_
#define V8_GEN_TORQUE_GENERATED_CSA_TYPES_H_

#include "src/compiler/code-assembler.h"

namespace v8 {
namespace internal {
struct TorqueStructArrayFromAsyncIterableResumeState_0 {
  TNode<Uint32T> step;
  TNode<Object> awaitedValue;
  TNode<Smi> index;

  std::tuple<TNode<Uint32T>, TNode<Object>, TNode<Smi>> Flatten() const {
    return std::make_tuple(step, awaitedValue, index);
  }
};
struct TorqueStructArrayFromAsyncArrayLikeResumeState_0 {
  TNode<Uint32T> step;
  TNode<Object> awaitedValue;
  TNode<Number> len;
  TNode<Smi> index;

  std::tuple<TNode<Uint32T>, TNode<Object>, TNode<Number>, TNode<Smi>> Flatten() const {
    return std::make_tuple(step, awaitedValue, len, index);
  }
};
struct TorqueStructBuffer_0 {
  TNode<FixedArray> fixedArray;
  TNode<IntPtrT> index;
  TNode<IntPtrT> totalStringLength;
  TNode<BoolT> isOneByte;
  TNode<PrimitiveHeapObject> lastString;

  std::tuple<TNode<FixedArray>, TNode<IntPtrT>, TNode<IntPtrT>, TNode<BoolT>, TNode<PrimitiveHeapObject>> Flatten() const {
    return std::make_tuple(fixedArray, index, totalStringLength, isOneByte, lastString);
  }
};
struct TorqueStructVector_0 {
  TNode<FixedArray> fixedArray;
  TNode<BoolT> onlySmis;
  TNode<BoolT> onlyNumbers;
  TNode<BoolT> skippedElements;

  std::tuple<TNode<FixedArray>, TNode<BoolT>, TNode<BoolT>, TNode<BoolT>> Flatten() const {
    return std::make_tuple(fixedArray, onlySmis, onlyNumbers, skippedElements);
  }
};
struct TorqueStructfloat64_or_hole_0 {
  TNode<BoolT> is_hole;
  TNode<Float64T> value;

  std::tuple<TNode<BoolT>, TNode<Float64T>> Flatten() const {
    return std::make_tuple(is_hole, value);
  }
};
struct TorqueStructKeyValuePair {
  TNode<Object> key;
  TNode<Object> value;

  std::tuple<TNode<Object>, TNode<Object>> Flatten() const {
    return std::make_tuple(key, value);
  }
};
struct TorqueStructSetRecord {
  TNode<JSReceiver> object;
  TNode<Number> size;
  TNode<Object> has;
  TNode<Object> keys;

  std::tuple<TNode<JSReceiver>, TNode<Number>, TNode<Object>, TNode<Object>> Flatten() const {
    return std::make_tuple(object, size, has, keys);
  }
};
struct TorqueStructKeyIndexPair {
  TNode<Object> key;
  TNode<IntPtrT> index;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(key, index);
  }
};
struct TorqueStructOrderedHashSetIndexPair {
  TNode<OrderedHashSet> table;
  TNode<IntPtrT> index;

  std::tuple<TNode<OrderedHashSet>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(table, index);
  }
};
struct TorqueStructUnmodifiedOrderedHashSetIterator_0 {
  TNode<OrderedHashSet> table;
  TNode<Int32T> numBuckets;
  TNode<Int32T> usedCapacity;
  TorqueStructKeyIndexPair current;

  std::tuple<TNode<OrderedHashSet>, TNode<Int32T>, TNode<Int32T>, TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(table, numBuckets, usedCapacity, current.key, current.index);
  }
};
struct TorqueStructOrderedHashSetIterator_0 {
  TNode<OrderedHashSet> table;
  TorqueStructKeyIndexPair current;

  std::tuple<TNode<OrderedHashSet>, TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(table, current.key, current.index);
  }
};
struct TorqueStructKeyValueIndexTuple {
  TNode<Object> key;
  TNode<Object> value;
  TNode<IntPtrT> index;

  std::tuple<TNode<Object>, TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(key, value, index);
  }
};
struct TorqueStructUnmodifiedOrderedHashMapIterator_0 {
  TNode<OrderedHashMap> table;
  TNode<Int32T> numBuckets;
  TNode<Int32T> usedCapacity;
  TorqueStructKeyValueIndexTuple current;

  std::tuple<TNode<OrderedHashMap>, TNode<Int32T>, TNode<Int32T>, TNode<Object>, TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(table, numBuckets, usedCapacity, current.key, current.value, current.index);
  }
};
struct TorqueStructStableJSSetBackingTableWitness_0 {
  TNode<JSSet> collection;
  TNode<OrderedHashSet> unstable;

  std::tuple<TNode<JSSet>, TNode<OrderedHashSet>> Flatten() const {
    return std::make_tuple(collection, unstable);
  }
};
struct TorqueStructStableJSMapBackingTableWitness_0 {
  TNode<JSMap> collection;
  TNode<OrderedHashMap> unstable;

  std::tuple<TNode<JSMap>, TNode<OrderedHashMap>> Flatten() const {
    return std::make_tuple(collection, unstable);
  }
};
struct TorqueStructToBooleanForBaselineJumpResult_0 {
  TNode<Object> value;
  TNode<Smi> is_to_boolean;

  std::tuple<TNode<Object>, TNode<Smi>> Flatten() const {
    return std::make_tuple(value, is_to_boolean);
  }
};
struct TorqueStructArguments {
  TNode<RawPtrT> frame;
  TNode<RawPtrT> base;
  TNode<IntPtrT> length;
  TNode<IntPtrT> actual_count;

  std::tuple<TNode<RawPtrT>, TNode<RawPtrT>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(frame, base, length, actual_count);
  }
};
struct TorqueStructArgumentsIterator_0 {
  TorqueStructArguments arguments;
  TNode<IntPtrT> current;

  std::tuple<TNode<RawPtrT>, TNode<RawPtrT>, TNode<IntPtrT>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(arguments.frame, arguments.base, arguments.length, arguments.actual_count, current);
  }
};
struct TorqueStructFrameWithArgumentsInfo_0 {
  TNode<RawPtrT> frame;
  TNode<BInt> argument_count;
  TNode<BInt> formal_parameter_count;

  std::tuple<TNode<RawPtrT>, TNode<BInt>, TNode<BInt>> Flatten() const {
    return std::make_tuple(frame, argument_count, formal_parameter_count);
  }
};
struct TorqueStructGrowableFixedArray_0 {
  TNode<FixedArray> array;
  TNode<IntPtrT> capacity;
  TNode<IntPtrT> length;

  std::tuple<TNode<FixedArray>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(array, capacity, length);
  }
};
struct TorqueStructIteratorRecord {
  TNode<JSReceiver> object;
  TNode<Object> next;

  std::tuple<TNode<JSReceiver>, TNode<Object>> Flatten() const {
    return std::make_tuple(object, next);
  }
};
struct TorqueStructPromiseResolvingFunctions {
  TNode<JSFunction> resolve;
  TNode<JSFunction> reject;
  TNode<Context> context;

  std::tuple<TNode<JSFunction>, TNode<JSFunction>, TNode<Context>> Flatten() const {
    return std::make_tuple(resolve, reject, context);
  }
};
struct TorqueStructPromiseAllResolveElementFunctor_0 {

  std::tuple<> Flatten() const {
    return std::make_tuple();
  }
};
struct TorqueStructPromiseAllRejectElementFunctor_0 {

  std::tuple<> Flatten() const {
    return std::make_tuple();
  }
};
struct TorqueStructPromiseAllSettledResolveElementFunctor_0 {

  std::tuple<> Flatten() const {
    return std::make_tuple();
  }
};
struct TorqueStructPromiseAllSettledRejectElementFunctor_0 {

  std::tuple<> Flatten() const {
    return std::make_tuple();
  }
};
struct TorqueStructPromiseAllWrapResultAsFulfilledFunctor_0 {

  std::tuple<> Flatten() const {
    return std::make_tuple();
  }
};
struct TorqueStructPromiseAllSettledWrapResultAsFulfilledFunctor_0 {

  std::tuple<> Flatten() const {
    return std::make_tuple();
  }
};
struct TorqueStructPromiseAllSettledWrapResultAsRejectedFunctor_0 {

  std::tuple<> Flatten() const {
    return std::make_tuple();
  }
};
struct TorqueStructPromiseFinallyFunctions_0 {
  TNode<JSFunction> then_finally;
  TNode<JSFunction> catch_finally;

  std::tuple<TNode<JSFunction>, TNode<JSFunction>> Flatten() const {
    return std::make_tuple(then_finally, catch_finally);
  }
};
struct TorqueStructInvokeThenOneArgFunctor_0 {

  std::tuple<> Flatten() const {
    return std::make_tuple();
  }
};
struct TorqueStructInvokeThenTwoArgFunctor_0 {

  std::tuple<> Flatten() const {
    return std::make_tuple();
  }
};
struct TorqueStructOrderedHashSetAndNumberOfElements_0 {
  TNode<OrderedHashSet> setData;
  TNode<Smi> numberOfElements;

  std::tuple<TNode<OrderedHashSet>, TNode<Smi>> Flatten() const {
    return std::make_tuple(setData, numberOfElements);
  }
};
struct TorqueStructIsSubstringAtFunctor_0 {
  TNode<IntPtrT> start;

  std::tuple<TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(start);
  }
};
struct TorqueStructStringMatchFunctor_0 {

  std::tuple<> Flatten() const {
    return std::make_tuple();
  }
};
struct TorqueStructStringSearchFunctor_0 {

  std::tuple<> Flatten() const {
    return std::make_tuple();
  }
};
struct TorqueStructUnsafe_0 {

  std::tuple<> Flatten() const {
    return std::make_tuple();
  }
};
struct TorqueStructUninitializedIterator_0 {

  std::tuple<> Flatten() const {
    return std::make_tuple();
  }
};
struct TorqueStructTypedArrayElementsInfo {
  TNode<UintPtrT> sizeLog2;
  TNode<Int32T> kind;

  std::tuple<TNode<UintPtrT>, TNode<Int32T>> Flatten() const {
    return std::make_tuple(sizeLog2, kind);
  }
};
struct TorqueStructTypedArrayAccessor_0 {
  TNode<BuiltinPtr> loadNumericFn;
  TNode<BuiltinPtr> storeNumericFn;
  TNode<BuiltinPtr> storeJSAnyFn;

  std::tuple<TNode<BuiltinPtr>, TNode<BuiltinPtr>, TNode<BuiltinPtr>> Flatten() const {
    return std::make_tuple(loadNumericFn, storeNumericFn, storeJSAnyFn);
  }
};
struct TorqueStructAttachedJSTypedArrayAndLength_0 {
  TNode<JSTypedArray> array;
  TNode<UintPtrT> length;

  std::tuple<TNode<JSTypedArray>, TNode<UintPtrT>> Flatten() const {
    return std::make_tuple(array, length);
  }
};
struct TorqueStructAttachedJSTypedArrayWitness_0 {
  TNode<JSTypedArray> stable;
  TNode<JSTypedArray> unstable;
  TNode<BuiltinPtr> loadfn;

  std::tuple<TNode<JSTypedArray>, TNode<JSTypedArray>, TNode<BuiltinPtr>> Flatten() const {
    return std::make_tuple(stable, unstable, loadfn);
  }
};
struct TorqueStructParameterMapIterator_0 {
  TNode<IntPtrT> currentIndex;
  TNode<IntPtrT> endInterationIndex;

  std::tuple<TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(currentIndex, endInterationIndex);
  }
};
struct TorqueStructParameterValueIterator_0 {
  TNode<IntPtrT> mapped_count;
  TorqueStructArguments arguments;
  TNode<IntPtrT> current;

  std::tuple<TNode<IntPtrT>, TNode<RawPtrT>, TNode<RawPtrT>, TNode<IntPtrT>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(mapped_count, arguments.frame, arguments.base, arguments.length, arguments.actual_count, current);
  }
};
struct TorqueStructCoverageInfoSlot {
  TNode<Int32T> start_source_position;
  TNode<Int32T> end_source_position;
  TNode<Int32T> block_count;
  TNode<Int32T> padding;

  std::tuple<TNode<Int32T>, TNode<Int32T>, TNode<Int32T>, TNode<Int32T>> Flatten() const {
    return std::make_tuple(start_source_position, end_source_position, block_count, padding);
  }
};
struct TorqueStructDescriptorEntry {
  TNode<PrimitiveHeapObject> key;
  TNode<Object> details;
  TNode<MaybeObject> value;

  std::tuple<TNode<PrimitiveHeapObject>, TNode<Object>, TNode<MaybeObject>> Flatten() const {
    return std::make_tuple(key, details, value);
  }
};
struct TorqueStructFastJSArrayWitness_0 {
  TNode<JSArray> stable;
  TNode<JSArray> unstable;
  TNode<Map> map;
  TNode<BoolT> hasDoubles;
  TNode<BoolT> hasSmis;
  TNode<BoolT> arrayIsPushable;

  std::tuple<TNode<JSArray>, TNode<JSArray>, TNode<Map>, TNode<BoolT>, TNode<BoolT>, TNode<BoolT>> Flatten() const {
    return std::make_tuple(stable, unstable, map, hasDoubles, hasSmis, arrayIsPushable);
  }
};
struct TorqueStructFastJSArrayForReadWitness_0 {
  TNode<JSArray> stable;
  TNode<JSArray> unstable;
  TNode<Map> map;
  TNode<BoolT> hasDoubles;

  std::tuple<TNode<JSArray>, TNode<JSArray>, TNode<Map>, TNode<BoolT>> Flatten() const {
    return std::make_tuple(stable, unstable, map, hasDoubles);
  }
};
struct TorqueStructHashMapEntry_0 {
  TNode<Object> key;
  TNode<Object> value;

  std::tuple<TNode<Object>, TNode<Object>> Flatten() const {
    return std::make_tuple(key, value);
  }
};
struct TorqueStructNameDictionaryEntry_0 {
  TNode<Object> key;
  TNode<Object> value;
  TNode<Object> property_details;

  std::tuple<TNode<Object>, TNode<Object>, TNode<Object>> Flatten() const {
    return std::make_tuple(key, value, property_details);
  }
};
struct TorqueStructPositionInfo_0 {
  TNode<Smi> start;
  TNode<Smi> end;

  std::tuple<TNode<Smi>, TNode<Smi>> Flatten() const {
    return std::make_tuple(start, end);
  }
};
struct TorqueStructFunctionVariableInfo_0 {
  TNode<Object> name;
  TNode<Smi> context_or_stack_slot_index;

  std::tuple<TNode<Object>, TNode<Smi>> Flatten() const {
    return std::make_tuple(name, context_or_stack_slot_index);
  }
};
struct TorqueStructModuleVariable_0 {
  TNode<String> name;
  TNode<Smi> index;
  TNode<Smi> properties;

  std::tuple<TNode<String>, TNode<Smi>, TNode<Smi>> Flatten() const {
    return std::make_tuple(name, index, properties);
  }
};
struct TorqueStructAbstractStringIndexOfFunctor_0 {
  TNode<Smi> fromIndex;

  std::tuple<TNode<Smi>> Flatten() const {
    return std::make_tuple(fromIndex);
  }
};
struct TorqueStructProbeSequence_0 {
  TNode<Uint32T> mask;
  TNode<Uint32T> offset;
  TNode<Uint32T> index;

  std::tuple<TNode<Uint32T>, TNode<Uint32T>, TNode<Uint32T>> Flatten() const {
    return std::make_tuple(mask, offset, index);
  }
};
struct TorqueStructByteMask_0 {
  TNode<Uint64T> mask;

  std::tuple<TNode<Uint64T>> Flatten() const {
    return std::make_tuple(mask);
  }
};
struct TorqueStructBitMask_0 {
  TNode<Uint32T> mask;

  std::tuple<TNode<Uint32T>> Flatten() const {
    return std::make_tuple(mask);
  }
};
struct TorqueStructGroupPortableImpl_0 {
  TNode<Uint64T> ctrl;

  std::tuple<TNode<Uint64T>> Flatten() const {
    return std::make_tuple(ctrl);
  }
};
struct TorqueStructGroupSse2Impl_0 {
  TNode<I8x16T> ctrl;

  std::tuple<TNode<I8x16T>> Flatten() const {
    return std::make_tuple(ctrl);
  }
};
struct TorqueStructGroupPortableLoader_0 {

  std::tuple<> Flatten() const {
    return std::make_tuple();
  }
};
struct TorqueStructGroupSse2Loader_0 {

  std::tuple<> Flatten() const {
    return std::make_tuple();
  }
};
struct TorqueStructTestStructA_0 {
  TNode<FixedArray> indexes;
  TNode<Smi> i;
  TNode<Number> k;

  std::tuple<TNode<FixedArray>, TNode<Smi>, TNode<Number>> Flatten() const {
    return std::make_tuple(indexes, i, k);
  }
};
struct TorqueStructTestStructB_0 {
  TorqueStructTestStructA_0 x;
  TNode<Smi> y;

  std::tuple<TNode<FixedArray>, TNode<Smi>, TNode<Number>, TNode<Smi>> Flatten() const {
    return std::make_tuple(x.indexes, x.i, x.k, y);
  }
};
struct TorqueStructTestStructC_0 {
  TorqueStructTestStructA_0 x;
  TorqueStructTestStructA_0 y;

  std::tuple<TNode<FixedArray>, TNode<Smi>, TNode<Number>, TNode<FixedArray>, TNode<Smi>, TNode<Number>> Flatten() const {
    return std::make_tuple(x.indexes, x.i, x.k, y.indexes, y.i, y.k);
  }
};
struct TorqueStructTestInner_0 {
  TNode<Int32T> x;
  TNode<Int32T> y;

  std::tuple<TNode<Int32T>, TNode<Int32T>> Flatten() const {
    return std::make_tuple(x, y);
  }
};
struct TorqueStructTestOuter_0 {
  TNode<Int32T> a;
  TorqueStructTestInner_0 b;
  TNode<Int32T> c;

  std::tuple<TNode<Int32T>, TNode<Int32T>, TNode<Int32T>, TNode<Int32T>> Flatten() const {
    return std::make_tuple(a, b.x, b.y, c);
  }
};
struct TorqueStructStructWithConst_0 {
  TNode<Object> a;
  TNode<Int32T> b;

  std::tuple<TNode<Object>, TNode<Int32T>> Flatten() const {
    return std::make_tuple(a, b);
  }
};
struct TorqueStructTestIterator_0 {
  TNode<Smi> count;

  std::tuple<TNode<Smi>> Flatten() const {
    return std::make_tuple(count);
  }
};
struct TorqueStructInternalClassStructElement_0 {
  TNode<Smi> a;
  TNode<Smi> b;

  std::tuple<TNode<Smi>, TNode<Smi>> Flatten() const {
    return std::make_tuple(a, b);
  }
};
struct TorqueStructTwoValues_0 {
  TNode<Smi> a;
  TNode<Map> b;

  std::tuple<TNode<Smi>, TNode<Map>> Flatten() const {
    return std::make_tuple(a, b);
  }
};
struct TorqueStructInt64AsInt32Pair {
  TNode<UintPtrT> low;
  TNode<UintPtrT> high;

  std::tuple<TNode<UintPtrT>, TNode<UintPtrT>> Flatten() const {
    return std::make_tuple(low, high);
  }
};
struct TorqueStructReturnSlotAllocator_0 {
  TNode<IntPtrT> remainingGPRegs;
  TNode<IntPtrT> remainingFPRegs;
  TNode<BoolT> hasSmallSlot;
  TNode<BoolT> smallSlotLast;
  TNode<IntPtrT> stackSlots;

  std::tuple<TNode<IntPtrT>, TNode<IntPtrT>, TNode<BoolT>, TNode<BoolT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(remainingGPRegs, remainingFPRegs, hasSmallSlot, smallSlotLast, stackSlots);
  }
};
struct TorqueStructLocationAllocator_0 {
  TNode<Object> object;
  TNode<IntPtrT> remainingGPRegs;
  TNode<IntPtrT> remainingFPRegs;
  TNode<IntPtrT> nextGPReg;
  TNode<IntPtrT> nextFPReg;
  TNode<IntPtrT> nextStack;
  TNode<IntPtrT> stackStart;
  TNode<IntPtrT> smallSlot;
  TNode<BoolT> smallSlotLast;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>, TNode<IntPtrT>, TNode<IntPtrT>, TNode<IntPtrT>, TNode<IntPtrT>, TNode<IntPtrT>, TNode<BoolT>> Flatten() const {
    return std::make_tuple(object, remainingGPRegs, remainingFPRegs, nextGPReg, nextFPReg, nextStack, stackStart, smallSlot, smallSlotLast);
  }
};
struct TorqueStructTargetAndImplicitArg_0 {
  TNode<RawPtrT> target;
  TNode<TrustedObject> implicit_arg;

  std::tuple<TNode<RawPtrT>, TNode<TrustedObject>> Flatten() const {
    return std::make_tuple(target, implicit_arg);
  }
};
struct TorqueStructTwoByteToOneByteIterator_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructNewPositionAndBytesWritten_0 {
  TNode<Uint32T> newPosition;
  TNode<Uint32T> bytesWritten;

  std::tuple<TNode<Uint32T>, TNode<Uint32T>> Flatten() const {
    return std::make_tuple(newPosition, bytesWritten);
  }
};
struct TorqueStructWasmToJSResult {
  TNode<IntPtrT> popCount;
  TNode<IntPtrT> result0;
  TNode<IntPtrT> result1;
  TNode<Float64T> result2;
  TNode<Float64T> result3;

  std::tuple<TNode<IntPtrT>, TNode<IntPtrT>, TNode<IntPtrT>, TNode<Float64T>, TNode<Float64T>> Flatten() const {
    return std::make_tuple(popCount, result0, result1, result2, result3);
  }
};
struct TorqueStructReference_char8_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_char8_MutableReference_char8_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_char16_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_char16_MutableReference_char16_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_float64_or_hole_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Object_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_char8_ConstReference_char8_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructSlice_char16_ConstReference_char16_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructTestTuple_intptr_Smi_0 {
  TNode<IntPtrT> fst;
  TNode<Smi> snd;

  std::tuple<TNode<IntPtrT>, TNode<Smi>> Flatten() const {
    return std::make_tuple(fst, snd);
  }
};
struct TorqueStructTestTuple_Smi_intptr_0 {
  TNode<Smi> fst;
  TNode<IntPtrT> snd;

  std::tuple<TNode<Smi>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(fst, snd);
  }
};
struct TorqueStructTestTuple_TestTuple_intptr_Smi_TestTuple_Smi_intptr_0 {
  TorqueStructTestTuple_intptr_Smi_0 fst;
  TorqueStructTestTuple_Smi_intptr_0 snd;

  std::tuple<TNode<IntPtrT>, TNode<Smi>, TNode<Smi>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(fst.fst, fst.snd, snd.fst, snd.snd);
  }
};
struct TorqueStructSliceIterator_char8_ConstReference_char8_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_char16_ConstReference_char16_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructReference_intptr_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_Object_MutableReference_Object_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_MaybeObject_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_MaybeObject_MutableReference_MaybeObject_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_Smi_OR_TheHole_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_Smi_OR_TheHole_MutableReference_Smi_OR_TheHole_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_uint8_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_uint8_MutableReference_uint8_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_Context_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_Context_MutableReference_Context_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_Smi_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_Smi_ConstReference_Smi_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_String_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_String_MutableReference_String_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_NameToIndexHashTable_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_NameToIndexHashTable_MutableReference_NameToIndexHashTable_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_SmiTagged_VariableProperties_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_SmiTagged_VariableProperties_MutableReference_SmiTagged_VariableProperties_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructSlice_Smi_MutableReference_Smi_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_FunctionVariableInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_FunctionVariableInfo_MutableReference_FunctionVariableInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_Undefined_OR_String_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_Undefined_OR_String_MutableReference_Undefined_OR_String_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_TheHole_OR_ScopeInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_TheHole_OR_ScopeInfo_MutableReference_TheHole_OR_ScopeInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_SourceTextModuleInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_SourceTextModuleInfo_MutableReference_SourceTextModuleInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_ModuleVariable_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_ModuleVariable_MutableReference_ModuleVariable_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructSlice_float64_or_hole_MutableReference_float64_or_hole_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_CoverageInfoSlot_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_CoverageInfoSlot_MutableReference_CoverageInfoSlot_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_DescriptorEntry_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_DescriptorEntry_MutableReference_DescriptorEntry_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_FeedbackCell_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_FeedbackCell_MutableReference_FeedbackCell_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_Smi_OR_TrustedObject_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_Smi_OR_TrustedObject_MutableReference_Smi_OR_TrustedObject_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_MutableReference_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_HashMapEntry_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_HashMapEntry_MutableReference_HashMapEntry_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_NameDictionaryEntry_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_NameDictionaryEntry_MutableReference_NameDictionaryEntry_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_uint32_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_uint32_MutableReference_uint32_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_float64_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_float64_MutableReference_float64_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructReference_InternalClassStructElement_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_InternalClassStructElement_MutableReference_InternalClassStructElement_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructSliceIterator_char8_MutableReference_char8_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_char16_MutableReference_char16_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_Object_MutableReference_Object_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_MaybeObject_MutableReference_MaybeObject_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_Smi_OR_TheHole_MutableReference_Smi_OR_TheHole_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_uint8_MutableReference_uint8_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_Context_MutableReference_Context_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_Smi_ConstReference_Smi_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_String_MutableReference_String_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_NameToIndexHashTable_MutableReference_NameToIndexHashTable_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_SmiTagged_VariableProperties_MutableReference_SmiTagged_VariableProperties_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_Smi_MutableReference_Smi_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_FunctionVariableInfo_MutableReference_FunctionVariableInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_Undefined_OR_String_MutableReference_Undefined_OR_String_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_TheHole_OR_ScopeInfo_MutableReference_TheHole_OR_ScopeInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_SourceTextModuleInfo_MutableReference_SourceTextModuleInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_ModuleVariable_MutableReference_ModuleVariable_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_float64_or_hole_MutableReference_float64_or_hole_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_CoverageInfoSlot_MutableReference_CoverageInfoSlot_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_DescriptorEntry_MutableReference_DescriptorEntry_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_FeedbackCell_MutableReference_FeedbackCell_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_Smi_OR_TrustedObject_MutableReference_Smi_OR_TrustedObject_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_MutableReference_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_HashMapEntry_MutableReference_HashMapEntry_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_NameDictionaryEntry_MutableReference_NameDictionaryEntry_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_uint32_MutableReference_uint32_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_float64_MutableReference_float64_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructSliceIterator_InternalClassStructElement_MutableReference_InternalClassStructElement_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructReference_Map_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Number_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSReceiver_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSAny_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSPromise_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSFunction_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_FixedArrayBase_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSArrayBuffer_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_FixedArray_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_FixedArray_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_DescriptorArray_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_Name_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_Smi_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Constructor_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Callable_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_RegExpMatchInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSObject_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSReceiver_OR_Map_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SymbolFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SharedFunctionInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSArrayBufferViewFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_WeakCell_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSReceiver_OR_Undefined_OR_Symbol_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_NativeContext_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_FinalizationRegistryFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_JSFinalizationRegistry_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_NumberDictionary_OR_AccessorInfo_OR_ClassPositions_OR_AccessorPair_OR_Weak_Map_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_MapBitFields3_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSReceiver_OR_Null_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Smi_OR_FixedArrayBase_OR_PropertyArray_OR_SwissNameDictionary_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_SourceTextModule_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_int32_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_IteratorRecord_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSReceiver_OR_Undefined_OR_Null_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Boolean_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_FixedDoubleArray_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_NameHash_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_WeakArrayList_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_PropertyDescriptorObjectFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_OR_FunctionTemplateInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_JSFunction_OR_CallableApiObject_OR_CallableJSProxy_OR_JSWrappedFunction_OR_JSBoundFunction_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Zero_OR_PromiseReaction_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_PromiseReaction_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSReceiver_OR_Undefined_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_PromiseCapability_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSPromiseFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_JSPromise_OR_PromiseCapability_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Null_OR_JSProxy_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSRegExpStringIteratorFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_SmiTagged_JSRegExpFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Zero_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ScopeFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructConstantIterator_Smi_0 {
  TNode<Smi> value;

  std::tuple<TNode<Smi>> Flatten() const {
    return std::make_tuple(value);
  }
};
struct TorqueStructReference_HeapObject_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructConstantIterator_Hole_0 {
  TNode<Hole> value;

  std::tuple<TNode<Hole>> Flatten() const {
    return std::make_tuple(value);
  }
};
struct TorqueStructIteratorSequence_Object_SliceIterator_Object_MutableReference_Object_ConstantIterator_Hole_0 {
  TorqueStructSliceIterator_Object_MutableReference_Object_0 first;
  TorqueStructConstantIterator_Hole_0 second;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>, TNode<Hole>> Flatten() const {
    return std::make_tuple(first.object, first.start, first.end, second.value);
  }
};
struct TorqueStructConstantIterator_float64_or_hole_0 {
  TorqueStructfloat64_or_hole_0 value;

  std::tuple<TNode<BoolT>, TNode<Float64T>> Flatten() const {
    return std::make_tuple(value.is_hole, value.value);
  }
};
struct TorqueStructIteratorSequence_float64_or_hole_SliceIterator_float64_or_hole_MutableReference_float64_or_hole_ConstantIterator_float64_or_hole_0 {
  TorqueStructSliceIterator_float64_or_hole_MutableReference_float64_or_hole_0 first;
  TorqueStructConstantIterator_float64_or_hole_0 second;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>, TNode<BoolT>, TNode<Float64T>> Flatten() const {
    return std::make_tuple(first.object, first.start, first.end, second.value.is_hole, second.value.value);
  }
};
struct TorqueStructReference_JSArrayBufferFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Smi_OR_ByteArray_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_IterationKind_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_InstanceType_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_MapBitFields1_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructConstantIterator_uint8_0 {
  TNode<Uint8T> value;

  std::tuple<TNode<Uint8T>> Flatten() const {
    return std::make_tuple(value);
  }
};
struct TorqueStructConstantIterator_TheHole_0 {
  TNode<Hole> value;

  std::tuple<TNode<Hole>> Flatten() const {
    return std::make_tuple(value);
  }
};
struct TorqueStructConstantIterator_HashMapEntry_0 {
  TorqueStructHashMapEntry_0 value;

  std::tuple<TNode<Object>, TNode<Object>> Flatten() const {
    return std::make_tuple(value.key, value.value);
  }
};
struct TorqueStructReference_uint16_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ByteArray_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SharedFunctionInfoFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_TurbofanTypeLowBits_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_TurbofanTypeHighBits_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_TurbofanType_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_TurboshaftFloatSpecialValues_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSBox_intptr_0 {
  TNode<IntPtrT> value;

  std::tuple<TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(value);
  }
};
struct TorqueStructSBox_SBox_intptr_0 {
  TorqueStructSBox_intptr_0 value;

  std::tuple<TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(value.value);
  }
};
struct TorqueStructReference_CompareBuiltinFn_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_LoadFn_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_StoreFn_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_DeleteFn_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_CanUseSameAccessorFn_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_RawFunctionSigPtr_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_RawPtr_int32_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructSlice_int32_ConstReference_int32_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TNode<IntPtrT> length;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset, length);
  }
};
struct TorqueStructSliceIterator_int32_ConstReference_int32_0 {
  TNode<Object> object;
  TNode<IntPtrT> start;
  TNode<IntPtrT> end;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, start, end);
  }
};
struct TorqueStructReference_float32_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Cell_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_WasmCodePointer_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_JSObject_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_bool_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_RawPtr_intptr_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_int64_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_uintptr_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_JSFunction_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Null_OR_Weak_Map_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ScopeInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_TrustedPointer_Code_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ExternalPointer_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_CppHeapPointer_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_TrustedPointer_WasmInternalFunction_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_ArrayList_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_FunctionTemplateInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_FunctionTemplateRareData_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_SharedFunctionInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_FunctionTemplateInfoFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_int16_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_MapBitFields2_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_DependentCode_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Zero_OR_Cell_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Zero_OR_TransitionArray_OR_Map_OR_Weak_Map_OR_PrototypeInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Smi_OR_Code_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Smi_OR_Cell_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_AllocationSite_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_Zero_OR_NonNullForeign_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_InterceptorInfoFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_Zero_OR_Foreign_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_Zero_OR_InterceptorInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Name_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_AccessorInfoFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_TrustedPointer_BytecodeArray_OR_Code_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Smi_OR_JSFunction_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_CallSiteInfoFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_BytecodeWrapper_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ProtectedPointer_TrustedByteArray_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ProtectedPointer_TrustedFixedArray_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_TrustedPointer_BytecodeArray_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_PositionInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_FixedArray_OR_BreakPoint_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_DebuggerHints_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_DebugInfoFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_CoverageInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Script_OR_SharedFunctionInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_StackFrameInfoFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_FixedArray_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_StackTraceInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_EnumCache_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_ClosureFeedbackCellArray_OR_FeedbackVector_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_OsrState_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_FeedbackVectorFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ClosureFeedbackCellArray_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Weak_CodeWrapper_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Smi_OR_Uninitialized_OR_FreeSpace_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSArray_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_DisposableStackStatus_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_AsyncGeneratorRequest_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSGlobalProxy_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Script_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_TheHole_OR_StackTraceInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Smi_OR_SharedFunctionInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_Smi_OR_NaN_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_RegExpDataWrapper_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_TrustedPointer_RegExpData_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSTemporalCalendarFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_BigInt_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSTemporalYearMonthDay_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSTemporalHourMinuteSecond_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSTemporalSecondParts_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSTemporalTimeZoneFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSTemporalTimeZoneSubMilliseconds_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSRegExpFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Foreign_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ObjectHashTable_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_JSModuleNamespace_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_JSPromise_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Module_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_AnyName_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Zero_OR_WeakArrayList_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_FixedArray_OR_Zero_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_PrototypeInfoFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_Symbol_OR_Smi_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Smi_OR_FixedArray_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_FixedArray_OR_SharedFunctionInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Smi_OR_Foreign_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_WeakFixedArray_OR_WeakArrayList_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_ScriptFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ProtectedPointer_BytecodeArray_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ProtectedPointer_Code_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_TrustedPointer_ExposedTrustedObject_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_String_OR_NoSharedNameSentinel_OR_ScopeInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_Script_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SharedFunctionInfoFlags2_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_PreparseData_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_FixedInt32Array_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_FixedUInt32Array_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_PodArrayOfIntegerPairs_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSFunction_OR_JSGeneratorObject_OR_SharedFunctionInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_JSObject_OR_TheHole_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_TheHole_OR_SourceTextModule_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ArrayList_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_SourceTextModuleFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_ModuleRequestFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_ObjectTemplateInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_InterceptorInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_AccessCheckInfo_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_ObjectTemplateInfoFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSDateTimeFormatFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSDisplayNamesFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSDurationFormatStyleFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSDurationFormatDisplayFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSListFormatFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSPluralRulesFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSRelativeTimeFormatFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSSegmentIteratorFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSSegmenterFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_SmiTagged_JSSegmentsFlags_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ProtectedPointer_WasmTrustedInstanceData_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Smi_OR_WasmFuncRef_OR_Tuple2_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_TrustedPointer_WasmTrustedInstanceData_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_WasmModuleObject_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ProtectedPointer_WasmImportData_OR_WasmTrustedInstanceData_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_WasmFuncRef_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ProtectedPointer_WasmInternalFunction_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ProtectedPointer_TrustedManagedWasmJSFunctionOffheapData_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_WasmSuspenderObject_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_WasmContinuationObject_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_WasmSuspenderObject_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_ManagedWasmNativeModule_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_BigInt_OR_HeapNumber_OR_Smi_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_AddressType_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_WeakArrayList_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_Undefined_OR_JSArrayBuffer_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_PodArrayOfWasmValueType_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_HeapNumber_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
struct TorqueStructReference_String_OR_Zero_0 {
  TNode<Object> object;
  TNode<IntPtrT> offset;
  TorqueStructUnsafe_0 unsafeMarker;

  std::tuple<TNode<Object>, TNode<IntPtrT>> Flatten() const {
    return std::make_tuple(object, offset);
  }
};
}  // namespace internal
}  // namespace v8
#endif  // V8_GEN_TORQUE_GENERATED_CSA_TYPES_H_
