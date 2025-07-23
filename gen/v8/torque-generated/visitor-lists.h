#ifndef V8_GEN_TORQUE_GENERATED_VISITOR_LISTS_H_
#define V8_GEN_TORQUE_GENERATED_VISITOR_LISTS_H_

#define TORQUE_INSTANCE_TYPE_TO_BODY_DESCRIPTOR_LIST(V)                                                                                                        \
    V(WEAK_ARRAY_LIST_TYPE, WeakArrayList)                                                                                                                     \
    V(SCOPE_INFO_TYPE, ScopeInfo)                                                                                                                              \
    V(DESCRIPTOR_ARRAY_TYPE, DescriptorArray)                                                                                                                  \
    V(STRONG_DESCRIPTOR_ARRAY_TYPE, StrongDescriptorArray)                                                                                                     \
    V(FEEDBACK_VECTOR_TYPE, FeedbackVector)                                                                                                                    \
    V(MEGA_DOM_HANDLER_TYPE, MegaDomHandler)                                                                                                                   \
    V(ON_HEAP_BASIC_BLOCK_PROFILER_DATA_TYPE, OnHeapBasicBlockProfilerData)                                                                                    \
    V(DICTIONARY_TEMPLATE_INFO_TYPE, DictionaryTemplateInfo)                                                                                                   \
    V(TURBOFAN_BITSET_TYPE_TYPE, TurbofanBitsetType)                                                                                                           \
    V(TURBOFAN_UNION_TYPE_TYPE, TurbofanUnionType)                                                                                                             \
    V(TURBOFAN_RANGE_TYPE_TYPE, TurbofanRangeType)                                                                                                             \
    V(TURBOFAN_HEAP_CONSTANT_TYPE_TYPE, TurbofanHeapConstantType)                                                                                              \
    V(TURBOFAN_OTHER_NUMBER_CONSTANT_TYPE_TYPE, TurbofanOtherNumberConstantType)                                                                               \
    V(TURBOSHAFT_WORD32_TYPE_TYPE, TurboshaftWord32Type)                                                                                                       \
    V(TURBOSHAFT_WORD32_RANGE_TYPE_TYPE, TurboshaftWord32RangeType)                                                                                            \
    V(TURBOSHAFT_WORD32_SET_TYPE_TYPE, TurboshaftWord32SetType)                                                                                                \
    V(TURBOSHAFT_WORD64_TYPE_TYPE, TurboshaftWord64Type)                                                                                                       \
    V(TURBOSHAFT_WORD64_RANGE_TYPE_TYPE, TurboshaftWord64RangeType)                                                                                            \
    V(TURBOSHAFT_WORD64_SET_TYPE_TYPE, TurboshaftWord64SetType)                                                                                                \
    V(TURBOSHAFT_FLOAT64_TYPE_TYPE, TurboshaftFloat64Type)                                                                                                     \
    V(TURBOSHAFT_FLOAT64_RANGE_TYPE_TYPE, TurboshaftFloat64RangeType)                                                                                          \
    V(TURBOSHAFT_FLOAT64_SET_TYPE_TYPE, TurboshaftFloat64SetType)                                                                                              \
    V(INTERNAL_CLASS_TYPE, InternalClass)                                                                                                                      \
    V(SMI_PAIR_TYPE, SmiPair)                                                                                                                                  \
    V(SMI_BOX_TYPE, SmiBox)                                                                                                                                    \
    V(EXPORTED_SUB_CLASS_BASE_TYPE, ExportedSubClassBase)                                                                                                      \
    V(EXPORTED_SUB_CLASS_TYPE, ExportedSubClass)                                                                                                               \
    V(ABSTRACT_INTERNAL_CLASS_SUBCLASS1_TYPE, AbstractInternalClassSubclass1)                                                                                  \
    V(ABSTRACT_INTERNAL_CLASS_SUBCLASS2_TYPE, AbstractInternalClassSubclass2)                                                                                  \
    V(INTERNAL_CLASS_WITH_STRUCT_ELEMENTS_TYPE, InternalClassWithStructElements)                                                                               \
    V(EXPORTED_SUB_CLASS2_TYPE, ExportedSubClass2)                                                                                                             \
    V(SORT_STATE_TYPE, SortState)                                                                                                                              \
    V(WASM_FAST_API_CALL_DATA_TYPE, WasmFastApiCallData)                                                                                                       \
    V(WASM_STRING_VIEW_ITER_TYPE, WasmStringViewIter)

#define TORQUE_DATA_ONLY_VISITOR_ID_LIST(V)                                                                                                                    \
    V(TurbofanBitsetType)                                                                                                                                      \
    V(TurbofanRangeType)                                                                                                                                       \
    V(TurbofanOtherNumberConstantType)                                                                                                                         \
    V(TurboshaftWord32Type)                                                                                                                                    \
    V(TurboshaftWord32RangeType)                                                                                                                               \
    V(TurboshaftWord32SetType)                                                                                                                                 \
    V(TurboshaftWord64Type)                                                                                                                                    \
    V(TurboshaftWord64RangeType)                                                                                                                               \
    V(TurboshaftWord64SetType)                                                                                                                                 \
    V(TurboshaftFloat64Type)                                                                                                                                   \
    V(TurboshaftFloat64RangeType)                                                                                                                              \
    V(TurboshaftFloat64SetType)                                                                                                                                \
    V(AbstractInternalClassSubclass1)                                                                                                                          \
    V(AbstractInternalClassSubclass2)

#define TORQUE_POINTER_VISITOR_ID_LIST(V)                                                                                                                      \
    V(Context)                                                                                                                                                 \
    V(WeakArrayList)                                                                                                                                           \
    V(ScopeInfo)                                                                                                                                               \
    V(DescriptorArray)                                                                                                                                         \
    V(StrongDescriptorArray)                                                                                                                                   \
    V(FeedbackVector)                                                                                                                                          \
    V(MegaDomHandler)                                                                                                                                          \
    V(OnHeapBasicBlockProfilerData)                                                                                                                            \
    V(DictionaryTemplateInfo)                                                                                                                                  \
    V(TurbofanUnionType)                                                                                                                                       \
    V(TurbofanHeapConstantType)                                                                                                                                \
    V(InternalClass)                                                                                                                                           \
    V(SmiPair)                                                                                                                                                 \
    V(SmiBox)                                                                                                                                                  \
    V(ExportedSubClassBase)                                                                                                                                    \
    V(ExportedSubClass)                                                                                                                                        \
    V(InternalClassWithStructElements)                                                                                                                         \
    V(ExportedSubClass2)                                                                                                                                       \
    V(SortState)                                                                                                                                               \
    V(WasmFastApiCallData)                                                                                                                                     \
    V(WasmStringViewIter)

#endif // V8_GEN_TORQUE_GENERATED_VISITOR_LISTS_H_
