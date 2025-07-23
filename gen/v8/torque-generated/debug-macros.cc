#include "torque-generated/debug-macros.h"

#include "src/objects/swiss-name-dictionary.h"
#include "src/objects/ordered-hash-table.h"
#include "src/torque/runtime-support.h"
#include "tools/debug_helper/debug-macro-shims.h"
#include "include/v8-internal.h"

namespace v8 {
namespace internal {
namespace debug_helper_internal {

#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceContextElements
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceContextElements

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=14&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceContextElements(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_Object_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceContextElements
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceFixedArrayObjects
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceFixedArrayObjects

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=14&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceFixedArrayObjects(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_Object_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceFixedArrayObjects
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceWeakFixedArrayObjects
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceWeakFixedArrayObjects

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=39&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceWeakFixedArrayObjects(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_MaybeObject_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceWeakFixedArrayObjects
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSloppyArgumentsElementsMappedEntries
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSloppyArgumentsElementsMappedEntries

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=31&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSloppyArgumentsElementsMappedEntries(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x10ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_Smi_OR_TheHole_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSloppyArgumentsElementsMappedEntries
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceWeakArrayListObjects
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceWeakArrayListObjects

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=72&c=36
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceWeakArrayListObjects(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0xcull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_MaybeObject_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceWeakArrayListObjects
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceBytecodeArrayBytes
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceBytecodeArrayBytes

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=20&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceBytecodeArrayBytes(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x24ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_uint8_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceBytecodeArrayBytes
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceScriptContextTableObjects
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceScriptContextTableObjects

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=22&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceScriptContextTableObjects(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x10ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_Context_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceScriptContextTableObjects
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoModuleVariableCount
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoModuleVariableCount

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=134&c=9
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceScopeInfoModuleVariableCount(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uint32_t tmp1 {};
    USE(tmp1);
    uint32_t tmp2 {};
    USE(tmp2);
    uint32_t tmp3 {};
    USE(tmp3);
    bool tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    intptr_t phi_bb4_4 {};
    USE(phi_bb4_4);
    intptr_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    uintptr_t tmp9 {};
    USE(tmp9);
    intptr_t tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_FIELD_OR_FAIL(uint32_t, tmp1, accessor, p_o, tmp0);
    tmp2 = CastToUnderlyingTypeIfEnum(base::BitField<ScopeType, 0, 4, uint32_t>::decode(tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_uint32_constexpr_uint32_0(accessor, ScopeType::MODULE_SCOPE));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::Word32Equal(accessor, tmp2, tmp3));
    if (tmp4) {
        goto block2;
    } else {
        goto block3;
    }

block2:
    ASSIGN_OR_RETURN(tmp5, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x1ull)));
    phi_bb4_4 = tmp5;
    goto block4;

block3:
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x0ull)));
    phi_bb4_4 = tmp6;
    goto block4;

block4:
    ASSIGN_OR_RETURN(tmp7, TqDebugConvert_intptr_intptr_0(accessor, phi_bb4_4));
    ASSIGN_OR_RETURN(tmp8, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x18ull)));
    ASSIGN_OR_RETURN(std::tie(tmp9, tmp10, tmp11), TqDebugNewConstSlice_Smi_0(accessor, p_o, tmp8, tmp7));
    goto block6;

block6:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp9, tmp10, tmp11) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoModuleVariableCount
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoContextLocalNames
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoContextLocalNames

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=140&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceScopeInfoContextLocalNames(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uintptr_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    intptr_t tmp9 {};
    USE(tmp9);
    bool tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    uintptr_t tmp12 {};
    USE(tmp12);
    uintptr_t tmp13 {};
    USE(tmp13);
    uintptr_t phi_bb4_8 {};
    USE(phi_bb4_8);
    intptr_t tmp14 {};
    USE(tmp14);
    uintptr_t tmp15 {};
    USE(tmp15);
    intptr_t tmp16 {};
    USE(tmp16);
    intptr_t tmp17 {};
    USE(tmp17);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceScopeInfoModuleVariableCount(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x4ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 12));
    READ_TAGGED_FIELD_OR_FAIL(tmp7, accessor, p_o, static_cast<int>(tmp6));
    ASSIGN_OR_RETURN(tmp8, TqDebugConvert_intptr_Smi_0(accessor, tmp7));
    ASSIGN_OR_RETURN(tmp9, TqDebugFromConstexpr_intptr_constexpr_int32_0(accessor, kScopeInfoMaxInlinedLocalNamesSize));
    ASSIGN_OR_RETURN(tmp10, TorqueDebugMacroShims::CodeStubAssembler::IntPtrLessThan(accessor, tmp8, tmp9));
    if (tmp10) {
        goto block2;
    } else {
        goto block3;
    }

block2:
    ASSIGN_OR_RETURN(tmp11, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 12));
    READ_TAGGED_FIELD_OR_FAIL(tmp12, accessor, p_o, static_cast<int>(tmp11));
    phi_bb4_8 = tmp12;
    goto block4;

block3:
    ASSIGN_OR_RETURN(tmp13, TqDebugFromConstexpr_Smi_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x0ull)));
    phi_bb4_8 = tmp13;
    goto block4;

block4:
    ASSIGN_OR_RETURN(tmp14, TqDebugConvert_intptr_Smi_0(accessor, phi_bb4_8));
    ASSIGN_OR_RETURN(std::tie(tmp15, tmp16, tmp17), TqDebugNewMutableSlice_String_0(accessor, p_o, tmp5, tmp14));
    goto block6;

block6:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp15, tmp16, tmp17) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoContextLocalNames
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoContextLocalNamesHashtable
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoContextLocalNamesHashtable

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=145&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceScopeInfoContextLocalNamesHashtable(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uintptr_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    intptr_t tmp9 {};
    USE(tmp9);
    bool tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    intptr_t tmp12 {};
    USE(tmp12);
    intptr_t phi_bb4_8 {};
    USE(phi_bb4_8);
    intptr_t tmp13 {};
    USE(tmp13);
    uintptr_t tmp14 {};
    USE(tmp14);
    intptr_t tmp15 {};
    USE(tmp15);
    intptr_t tmp16 {};
    USE(tmp16);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceScopeInfoContextLocalNames(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x4ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 12));
    READ_TAGGED_FIELD_OR_FAIL(tmp7, accessor, p_o, static_cast<int>(tmp6));
    ASSIGN_OR_RETURN(tmp8, TqDebugConvert_intptr_Smi_0(accessor, tmp7));
    ASSIGN_OR_RETURN(tmp9, TqDebugFromConstexpr_intptr_constexpr_int32_0(accessor, kScopeInfoMaxInlinedLocalNamesSize));
    ASSIGN_OR_RETURN(tmp10, TorqueDebugMacroShims::CodeStubAssembler::IntPtrLessThanOrEqual(accessor, tmp9, tmp8));
    if (tmp10) {
        goto block2;
    } else {
        goto block3;
    }

block2:
    ASSIGN_OR_RETURN(tmp11, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x1ull)));
    phi_bb4_8 = tmp11;
    goto block4;

block3:
    ASSIGN_OR_RETURN(tmp12, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x0ull)));
    phi_bb4_8 = tmp12;
    goto block4;

block4:
    ASSIGN_OR_RETURN(tmp13, TqDebugConvert_intptr_intptr_0(accessor, phi_bb4_8));
    ASSIGN_OR_RETURN(std::tie(tmp14, tmp15, tmp16), TqDebugNewMutableSlice_NameToIndexHashTable_0(accessor, p_o, tmp5, tmp13));
    goto block6;

block6:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp14, tmp15, tmp16) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoContextLocalNamesHashtable
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoContextLocalInfos
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoContextLocalInfos

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=151&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceScopeInfoContextLocalInfos(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uintptr_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    uintptr_t tmp9 {};
    USE(tmp9);
    intptr_t tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceScopeInfoContextLocalNamesHashtable(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x4ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 12));
    READ_TAGGED_FIELD_OR_FAIL(tmp7, accessor, p_o, static_cast<int>(tmp6));
    ASSIGN_OR_RETURN(tmp8, TqDebugConvert_intptr_Smi_0(accessor, tmp7));
    ASSIGN_OR_RETURN(std::tie(tmp9, tmp10, tmp11), TqDebugNewMutableSlice_SmiTagged_VariableProperties_0(accessor, p_o, tmp5, tmp8));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp9, tmp10, tmp11) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoContextLocalInfos
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoSavedClassVariableInfo
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoSavedClassVariableInfo

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=157&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceScopeInfoSavedClassVariableInfo(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uint32_t tmp7 {};
    USE(tmp7);
    bool tmp8 {};
    USE(tmp8);
    intptr_t tmp9 {};
    USE(tmp9);
    intptr_t tmp10 {};
    USE(tmp10);
    intptr_t phi_bb4_8 {};
    USE(phi_bb4_8);
    intptr_t tmp11 {};
    USE(tmp11);
    uintptr_t tmp12 {};
    USE(tmp12);
    intptr_t tmp13 {};
    USE(tmp13);
    intptr_t tmp14 {};
    USE(tmp14);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceScopeInfoContextLocalInfos(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x4ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_FIELD_OR_FAIL(uint32_t, tmp7, accessor, p_o, tmp6);
    tmp8 = CastToUnderlyingTypeIfEnum(base::BitField<bool, 10, 1, uint32_t>::decode(tmp7));
    if (tmp8) {
        goto block2;
    } else {
        goto block3;
    }

block2:
    ASSIGN_OR_RETURN(tmp9, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x1ull)));
    phi_bb4_8 = tmp9;
    goto block4;

block3:
    ASSIGN_OR_RETURN(tmp10, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x0ull)));
    phi_bb4_8 = tmp10;
    goto block4;

block4:
    ASSIGN_OR_RETURN(tmp11, TqDebugConvert_intptr_intptr_0(accessor, phi_bb4_8));
    ASSIGN_OR_RETURN(std::tie(tmp12, tmp13, tmp14), TqDebugNewMutableSlice_Smi_0(accessor, p_o, tmp5, tmp11));
    goto block6;

block6:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp12, tmp13, tmp14) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoSavedClassVariableInfo
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoFunctionVariableInfo
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoFunctionVariableInfo

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=163&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceScopeInfoFunctionVariableInfo(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uint32_t tmp7 {};
    USE(tmp7);
    uint32_t tmp8 {};
    USE(tmp8);
    uint32_t tmp9 {};
    USE(tmp9);
    bool tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    intptr_t tmp12 {};
    USE(tmp12);
    intptr_t phi_bb4_8 {};
    USE(phi_bb4_8);
    intptr_t tmp13 {};
    USE(tmp13);
    uintptr_t tmp14 {};
    USE(tmp14);
    intptr_t tmp15 {};
    USE(tmp15);
    intptr_t tmp16 {};
    USE(tmp16);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceScopeInfoSavedClassVariableInfo(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x4ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_FIELD_OR_FAIL(uint32_t, tmp7, accessor, p_o, tmp6);
    tmp8 = CastToUnderlyingTypeIfEnum(base::BitField<VariableAllocationInfo, 12, 2, uint32_t>::decode(tmp7));
    ASSIGN_OR_RETURN(tmp9, TqDebugFromConstexpr_VariableAllocationInfo_constexpr_NONE_0(accessor, VariableAllocationInfo::NONE));
    ASSIGN_OR_RETURN(tmp10, TorqueDebugMacroShims::CodeStubAssembler::Word32NotEqual(accessor, tmp8, tmp9));
    if (tmp10) {
        goto block2;
    } else {
        goto block3;
    }

block2:
    ASSIGN_OR_RETURN(tmp11, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x1ull)));
    phi_bb4_8 = tmp11;
    goto block4;

block3:
    ASSIGN_OR_RETURN(tmp12, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x0ull)));
    phi_bb4_8 = tmp12;
    goto block4;

block4:
    ASSIGN_OR_RETURN(tmp13, TqDebugConvert_intptr_intptr_0(accessor, phi_bb4_8));
    ASSIGN_OR_RETURN(std::tie(tmp14, tmp15, tmp16), TqDebugNewMutableSlice_FunctionVariableInfo_0(accessor, p_o, tmp5, tmp13));
    goto block6;

block6:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp14, tmp15, tmp16) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoFunctionVariableInfo
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoInferredFunctionName
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoInferredFunctionName

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=168&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceScopeInfoInferredFunctionName(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uint32_t tmp7 {};
    USE(tmp7);
    bool tmp8 {};
    USE(tmp8);
    intptr_t tmp9 {};
    USE(tmp9);
    intptr_t tmp10 {};
    USE(tmp10);
    intptr_t phi_bb4_8 {};
    USE(phi_bb4_8);
    intptr_t tmp11 {};
    USE(tmp11);
    uintptr_t tmp12 {};
    USE(tmp12);
    intptr_t tmp13 {};
    USE(tmp13);
    intptr_t tmp14 {};
    USE(tmp14);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceScopeInfoFunctionVariableInfo(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_FIELD_OR_FAIL(uint32_t, tmp7, accessor, p_o, tmp6);
    tmp8 = CastToUnderlyingTypeIfEnum(base::BitField<bool, 14, 1, uint32_t>::decode(tmp7));
    if (tmp8) {
        goto block2;
    } else {
        goto block3;
    }

block2:
    ASSIGN_OR_RETURN(tmp9, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x1ull)));
    phi_bb4_8 = tmp9;
    goto block4;

block3:
    ASSIGN_OR_RETURN(tmp10, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x0ull)));
    phi_bb4_8 = tmp10;
    goto block4;

block4:
    ASSIGN_OR_RETURN(tmp11, TqDebugConvert_intptr_intptr_0(accessor, phi_bb4_8));
    ASSIGN_OR_RETURN(std::tie(tmp12, tmp13, tmp14), TqDebugNewMutableSlice_Undefined_OR_String_0(accessor, p_o, tmp5, tmp11));
    goto block6;

block6:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp12, tmp13, tmp14) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoInferredFunctionName
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoOuterScopeInfo
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoOuterScopeInfo

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=170&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceScopeInfoOuterScopeInfo(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uint32_t tmp7 {};
    USE(tmp7);
    bool tmp8 {};
    USE(tmp8);
    intptr_t tmp9 {};
    USE(tmp9);
    intptr_t tmp10 {};
    USE(tmp10);
    intptr_t phi_bb4_8 {};
    USE(phi_bb4_8);
    intptr_t tmp11 {};
    USE(tmp11);
    uintptr_t tmp12 {};
    USE(tmp12);
    intptr_t tmp13 {};
    USE(tmp13);
    intptr_t tmp14 {};
    USE(tmp14);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceScopeInfoInferredFunctionName(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x4ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_FIELD_OR_FAIL(uint32_t, tmp7, accessor, p_o, tmp6);
    tmp8 = CastToUnderlyingTypeIfEnum(base::BitField<bool, 22, 1, uint32_t>::decode(tmp7));
    if (tmp8) {
        goto block2;
    } else {
        goto block3;
    }

block2:
    ASSIGN_OR_RETURN(tmp9, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x1ull)));
    phi_bb4_8 = tmp9;
    goto block4;

block3:
    ASSIGN_OR_RETURN(tmp10, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x0ull)));
    phi_bb4_8 = tmp10;
    goto block4;

block4:
    ASSIGN_OR_RETURN(tmp11, TqDebugConvert_intptr_intptr_0(accessor, phi_bb4_8));
    ASSIGN_OR_RETURN(std::tie(tmp12, tmp13, tmp14), TqDebugNewMutableSlice_TheHole_OR_ScopeInfo_0(accessor, p_o, tmp5, tmp11));
    goto block6;

block6:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp12, tmp13, tmp14) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoOuterScopeInfo
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoModuleInfo
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoModuleInfo

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=174&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceScopeInfoModuleInfo(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uint32_t tmp7 {};
    USE(tmp7);
    uint32_t tmp8 {};
    USE(tmp8);
    uint32_t tmp9 {};
    USE(tmp9);
    bool tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    intptr_t tmp12 {};
    USE(tmp12);
    intptr_t phi_bb4_8 {};
    USE(phi_bb4_8);
    intptr_t tmp13 {};
    USE(tmp13);
    uintptr_t tmp14 {};
    USE(tmp14);
    intptr_t tmp15 {};
    USE(tmp15);
    intptr_t tmp16 {};
    USE(tmp16);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceScopeInfoOuterScopeInfo(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x4ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_FIELD_OR_FAIL(uint32_t, tmp7, accessor, p_o, tmp6);
    tmp8 = CastToUnderlyingTypeIfEnum(base::BitField<ScopeType, 0, 4, uint32_t>::decode(tmp7));
    ASSIGN_OR_RETURN(tmp9, TqDebugFromConstexpr_uint32_constexpr_uint32_0(accessor, ScopeType::MODULE_SCOPE));
    ASSIGN_OR_RETURN(tmp10, TorqueDebugMacroShims::CodeStubAssembler::Word32Equal(accessor, tmp8, tmp9));
    if (tmp10) {
        goto block2;
    } else {
        goto block3;
    }

block2:
    ASSIGN_OR_RETURN(tmp11, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x1ull)));
    phi_bb4_8 = tmp11;
    goto block4;

block3:
    ASSIGN_OR_RETURN(tmp12, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x0ull)));
    phi_bb4_8 = tmp12;
    goto block4;

block4:
    ASSIGN_OR_RETURN(tmp13, TqDebugConvert_intptr_intptr_0(accessor, phi_bb4_8));
    ASSIGN_OR_RETURN(std::tie(tmp14, tmp15, tmp16), TqDebugNewMutableSlice_SourceTextModuleInfo_0(accessor, p_o, tmp5, tmp13));
    goto block6;

block6:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp14, tmp15, tmp16) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoModuleInfo
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoModuleVariables
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoModuleVariables

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=176&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceScopeInfoModuleVariables(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uint32_t tmp7 {};
    USE(tmp7);
    uint32_t tmp8 {};
    USE(tmp8);
    uint32_t tmp9 {};
    USE(tmp9);
    bool tmp10 {};
    USE(tmp10);
    uintptr_t tmp11 {};
    USE(tmp11);
    intptr_t tmp12 {};
    USE(tmp12);
    intptr_t tmp13 {};
    USE(tmp13);
    intptr_t tmp14 {};
    USE(tmp14);
    uintptr_t tmp15 {};
    USE(tmp15);
    uintptr_t tmp16 {};
    USE(tmp16);
    bool tmp17 {};
    USE(tmp17);
    intptr_t tmp18 {};
    USE(tmp18);
    intptr_t tmp19 {};
    USE(tmp19);
    uintptr_t tmp20 {};
    USE(tmp20);
    intptr_t tmp21 {};
    USE(tmp21);
    uintptr_t tmp22 {};
    USE(tmp22);
    uintptr_t tmp23 {};
    USE(tmp23);
    uintptr_t phi_bb4_8 {};
    USE(phi_bb4_8);
    intptr_t tmp24 {};
    USE(tmp24);
    uintptr_t tmp25 {};
    USE(tmp25);
    intptr_t tmp26 {};
    USE(tmp26);
    intptr_t tmp27 {};
    USE(tmp27);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceScopeInfoModuleInfo(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x4ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_FIELD_OR_FAIL(uint32_t, tmp7, accessor, p_o, tmp6);
    tmp8 = CastToUnderlyingTypeIfEnum(base::BitField<ScopeType, 0, 4, uint32_t>::decode(tmp7));
    ASSIGN_OR_RETURN(tmp9, TqDebugFromConstexpr_uint32_constexpr_uint32_0(accessor, ScopeType::MODULE_SCOPE));
    ASSIGN_OR_RETURN(tmp10, TorqueDebugMacroShims::CodeStubAssembler::Word32Equal(accessor, tmp8, tmp9));
    if (tmp10) {
        goto block2;
    } else {
        goto block3;
    }

block2:
    ASSIGN_OR_RETURN(std::tie(tmp11, tmp12, tmp13), TqDebugFieldSliceScopeInfoModuleVariableCount(accessor, p_o));
    ASSIGN_OR_RETURN(tmp14, TqDebugConvert_intptr_constexpr_int31_0(accessor, 0));
    ASSIGN_OR_RETURN(tmp15, TqDebugConvert_uintptr_intptr_0(accessor, tmp14));
    ASSIGN_OR_RETURN(tmp16, TqDebugConvert_uintptr_intptr_0(accessor, tmp13));
    ASSIGN_OR_RETURN(tmp17, TorqueDebugMacroShims::CodeStubAssembler::UintPtrLessThan(accessor, tmp15, tmp16));
    if (tmp17) {
        goto block10;
    } else {
        goto block11;
    }

block10:
    ASSIGN_OR_RETURN(tmp18, TqDebugTimesSizeOf_Smi_0(accessor, tmp14));
    ASSIGN_OR_RETURN(tmp19, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp12, tmp18));
    ASSIGN_OR_RETURN(std::tie(tmp20, tmp21), TqDebugNewReference_Smi_0(accessor, tmp11, tmp19));
    READ_TAGGED_FIELD_OR_FAIL(tmp22, accessor, tmp20, static_cast<int>(tmp21));
    phi_bb4_8 = tmp22;
    goto block4;

block11:
    UNREACHABLE();

block3:
    ASSIGN_OR_RETURN(tmp23, TqDebugFromConstexpr_Smi_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x0ull)));
    phi_bb4_8 = tmp23;
    goto block4;

block4:
    ASSIGN_OR_RETURN(tmp24, TqDebugConvert_intptr_Smi_0(accessor, phi_bb4_8));
    ASSIGN_OR_RETURN(std::tie(tmp25, tmp26, tmp27), TqDebugNewMutableSlice_ModuleVariable_0(accessor, p_o, tmp5, tmp24));
    goto block14;

block14:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp25, tmp26, tmp27) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceScopeInfoModuleVariables
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceFixedDoubleArrayValues
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceFixedDoubleArrayValues

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=33&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceFixedDoubleArrayValues(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_float64_or_hole_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceFixedDoubleArrayValues
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceRegExpMatchInfoObjects
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceRegExpMatchInfoObjects

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=19&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceRegExpMatchInfoObjects(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x14ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_Smi_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceRegExpMatchInfoObjects
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceCoverageInfoSlots
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceCoverageInfoSlots

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceCoverageInfoSlots(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    int32_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_FIELD_OR_FAIL(int32_t, tmp1, accessor, p_o, tmp0);
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_int32_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_CoverageInfoSlot_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceCoverageInfoSlots
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceDescriptorArrayDescriptors
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceDescriptorArrayDescriptors

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceDescriptorArrayDescriptors(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uint16_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_FIELD_OR_FAIL(uint16_t, tmp1, accessor, p_o, tmp0);
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_uint16_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x10ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_DescriptorEntry_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceDescriptorArrayDescriptors
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceClosureFeedbackCellArrayObjects
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceClosureFeedbackCellArrayObjects

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=41&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceClosureFeedbackCellArrayObjects(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_FeedbackCell_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceClosureFeedbackCellArrayObjects
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceFeedbackVectorRawFeedbackSlots
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceFeedbackVectorRawFeedbackSlots

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=56&c=36
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceFeedbackVectorRawFeedbackSlots(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    int32_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_FIELD_OR_FAIL(int32_t, tmp1, accessor, p_o, tmp0);
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_int32_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x20ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_MaybeObject_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceFeedbackVectorRawFeedbackSlots
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceTrustedFixedArrayObjects
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceTrustedFixedArrayObjects

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=22&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceTrustedFixedArrayObjects(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_Object_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceTrustedFixedArrayObjects
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceProtectedFixedArrayObjects
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceProtectedFixedArrayObjects

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=28&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceProtectedFixedArrayObjects(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_Smi_OR_TrustedObject_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceProtectedFixedArrayObjects
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceTrustedWeakFixedArrayObjects
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceTrustedWeakFixedArrayObjects

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=45&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceTrustedWeakFixedArrayObjects(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_MaybeObject_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceTrustedWeakFixedArrayObjects
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceByteArrayValues
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceByteArrayValues

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=50&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceByteArrayValues(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_uint8_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceByteArrayValues
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceTrustedByteArrayValues
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceTrustedByteArrayValues

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=56&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceTrustedByteArrayValues(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_uint8_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceTrustedByteArrayValues
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceArrayListObjects
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceArrayListObjects

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=65&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceArrayListObjects(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0xcull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_Object_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceArrayListObjects
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceObjectBoilerplateDescriptionRawEntries
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceObjectBoilerplateDescriptionRawEntries

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/literal-objects.tq?l=10&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceObjectBoilerplateDescriptionRawEntries(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x10ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_Object_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceObjectBoilerplateDescriptionRawEntries
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashSetPadding
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashSetPadding

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=31&c=31
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSmallOrderedHashSetPadding(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    uintptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugConvert_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x1ull)));
    ASSIGN_OR_RETURN(tmp1, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x7ull)));
    ASSIGN_OR_RETURN(std::tie(tmp2, tmp3, tmp4), TqDebugNewMutableSlice_uint8_0(accessor, p_o, tmp1, tmp0));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp2, tmp3, tmp4) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashSetPadding
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashSetDataTable
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashSetDataTable

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=32&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSmallOrderedHashSetDataTable(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uint8_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uintptr_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    intptr_t tmp9 {};
    USE(tmp9);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 6));
    READ_FIELD_OR_FAIL(uint8_t, tmp1, accessor, p_o, tmp0);
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_uint8_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, SmallOrderedHashTable<int>::kLoadFactor));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp2, tmp3));
    ASSIGN_OR_RETURN(tmp5, TqDebugConvert_intptr_intptr_0(accessor, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(std::tie(tmp7, tmp8, tmp9),
        TqDebugNewMutableSlice_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0(
            accessor, p_o, tmp6, tmp5));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp7, tmp8, tmp9) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashSetDataTable
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashSetHashTable
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashSetHashTable

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=34&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSmallOrderedHashSetHashTable(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uint8_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    uintptr_t tmp9 {};
    USE(tmp9);
    intptr_t tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceSmallOrderedHashSetDataTable(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x4ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 6));
    READ_FIELD_OR_FAIL(uint8_t, tmp7, accessor, p_o, tmp6);
    ASSIGN_OR_RETURN(tmp8, TqDebugConvert_intptr_uint8_0(accessor, tmp7));
    ASSIGN_OR_RETURN(std::tie(tmp9, tmp10, tmp11), TqDebugNewMutableSlice_uint8_0(accessor, p_o, tmp5, tmp8));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp9, tmp10, tmp11) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashSetHashTable
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashSetChainTable
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashSetChainTable

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=35&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSmallOrderedHashSetChainTable(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uint8_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    intptr_t tmp9 {};
    USE(tmp9);
    intptr_t tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    uintptr_t tmp12 {};
    USE(tmp12);
    intptr_t tmp13 {};
    USE(tmp13);
    intptr_t tmp14 {};
    USE(tmp14);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceSmallOrderedHashSetHashTable(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x1ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 6));
    READ_FIELD_OR_FAIL(uint8_t, tmp7, accessor, p_o, tmp6);
    ASSIGN_OR_RETURN(tmp8, TqDebugConvert_intptr_uint8_0(accessor, tmp7));
    ASSIGN_OR_RETURN(tmp9, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, SmallOrderedHashTable<int>::kLoadFactor));
    ASSIGN_OR_RETURN(tmp10, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp8, tmp9));
    ASSIGN_OR_RETURN(tmp11, TqDebugConvert_intptr_intptr_0(accessor, tmp10));
    ASSIGN_OR_RETURN(std::tie(tmp12, tmp13, tmp14), TqDebugNewMutableSlice_uint8_0(accessor, p_o, tmp5, tmp11));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp12, tmp13, tmp14) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashSetChainTable
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashMapPadding
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashMapPadding

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=70&c=31
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSmallOrderedHashMapPadding(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    uintptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugConvert_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x1ull)));
    ASSIGN_OR_RETURN(tmp1, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x7ull)));
    ASSIGN_OR_RETURN(std::tie(tmp2, tmp3, tmp4), TqDebugNewMutableSlice_uint8_0(accessor, p_o, tmp1, tmp0));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp2, tmp3, tmp4) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashMapPadding
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashMapDataTable
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashMapDataTable

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=71&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSmallOrderedHashMapDataTable(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uint8_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uintptr_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    intptr_t tmp9 {};
    USE(tmp9);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 6));
    READ_FIELD_OR_FAIL(uint8_t, tmp1, accessor, p_o, tmp0);
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_uint8_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, SmallOrderedHashTable<int>::kLoadFactor));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp2, tmp3));
    ASSIGN_OR_RETURN(tmp5, TqDebugConvert_intptr_intptr_0(accessor, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(std::tie(tmp7, tmp8, tmp9), TqDebugNewMutableSlice_HashMapEntry_0(accessor, p_o, tmp6, tmp5));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp7, tmp8, tmp9) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashMapDataTable
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashMapHashTable
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashMapHashTable

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=73&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSmallOrderedHashMapHashTable(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uint8_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    uintptr_t tmp9 {};
    USE(tmp9);
    intptr_t tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceSmallOrderedHashMapDataTable(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 6));
    READ_FIELD_OR_FAIL(uint8_t, tmp7, accessor, p_o, tmp6);
    ASSIGN_OR_RETURN(tmp8, TqDebugConvert_intptr_uint8_0(accessor, tmp7));
    ASSIGN_OR_RETURN(std::tie(tmp9, tmp10, tmp11), TqDebugNewMutableSlice_uint8_0(accessor, p_o, tmp5, tmp8));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp9, tmp10, tmp11) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashMapHashTable
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashMapChainTable
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashMapChainTable

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=74&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSmallOrderedHashMapChainTable(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uint8_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    intptr_t tmp9 {};
    USE(tmp9);
    intptr_t tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    uintptr_t tmp12 {};
    USE(tmp12);
    intptr_t tmp13 {};
    USE(tmp13);
    intptr_t tmp14 {};
    USE(tmp14);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceSmallOrderedHashMapHashTable(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x1ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 6));
    READ_FIELD_OR_FAIL(uint8_t, tmp7, accessor, p_o, tmp6);
    ASSIGN_OR_RETURN(tmp8, TqDebugConvert_intptr_uint8_0(accessor, tmp7));
    ASSIGN_OR_RETURN(tmp9, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, SmallOrderedHashTable<int>::kLoadFactor));
    ASSIGN_OR_RETURN(tmp10, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp8, tmp9));
    ASSIGN_OR_RETURN(tmp11, TqDebugConvert_intptr_intptr_0(accessor, tmp10));
    ASSIGN_OR_RETURN(std::tie(tmp12, tmp13, tmp14), TqDebugNewMutableSlice_uint8_0(accessor, p_o, tmp5, tmp11));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp12, tmp13, tmp14) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedHashMapChainTable
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedNameDictionaryPadding1
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedNameDictionaryPadding1

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=110&c=31
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSmallOrderedNameDictionaryPadding1(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    uintptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugConvert_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x1ull)));
    ASSIGN_OR_RETURN(tmp1, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0xbull)));
    ASSIGN_OR_RETURN(std::tie(tmp2, tmp3, tmp4), TqDebugNewMutableSlice_uint8_0(accessor, p_o, tmp1, tmp0));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp2, tmp3, tmp4) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedNameDictionaryPadding1
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedNameDictionaryDataTable
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedNameDictionaryDataTable

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=111&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSmallOrderedNameDictionaryDataTable(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uint8_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uintptr_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    intptr_t tmp9 {};
    USE(tmp9);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 10));
    READ_FIELD_OR_FAIL(uint8_t, tmp1, accessor, p_o, tmp0);
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_uint8_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, SmallOrderedHashTable<int>::kLoadFactor));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp2, tmp3));
    ASSIGN_OR_RETURN(tmp5, TqDebugConvert_intptr_intptr_0(accessor, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0xcull)));
    ASSIGN_OR_RETURN(std::tie(tmp7, tmp8, tmp9), TqDebugNewMutableSlice_NameDictionaryEntry_0(accessor, p_o, tmp6, tmp5));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp7, tmp8, tmp9) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedNameDictionaryDataTable
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedNameDictionaryHashTable
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedNameDictionaryHashTable

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=113&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSmallOrderedNameDictionaryHashTable(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uint8_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    uintptr_t tmp9 {};
    USE(tmp9);
    intptr_t tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceSmallOrderedNameDictionaryDataTable(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0xcull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 10));
    READ_FIELD_OR_FAIL(uint8_t, tmp7, accessor, p_o, tmp6);
    ASSIGN_OR_RETURN(tmp8, TqDebugConvert_intptr_uint8_0(accessor, tmp7));
    ASSIGN_OR_RETURN(std::tie(tmp9, tmp10, tmp11), TqDebugNewMutableSlice_uint8_0(accessor, p_o, tmp5, tmp8));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp9, tmp10, tmp11) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedNameDictionaryHashTable
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedNameDictionaryChainTable
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedNameDictionaryChainTable

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=114&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSmallOrderedNameDictionaryChainTable(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uint8_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    uintptr_t tmp9 {};
    USE(tmp9);
    intptr_t tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceSmallOrderedNameDictionaryHashTable(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x1ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 10));
    READ_FIELD_OR_FAIL(uint8_t, tmp7, accessor, p_o, tmp6);
    ASSIGN_OR_RETURN(tmp8, TqDebugConvert_intptr_uint8_0(accessor, tmp7));
    ASSIGN_OR_RETURN(std::tie(tmp9, tmp10, tmp11), TqDebugNewMutableSlice_uint8_0(accessor, p_o, tmp5, tmp8));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp9, tmp10, tmp11) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSmallOrderedNameDictionaryChainTable
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSeqOneByteStringChars
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSeqOneByteStringChars

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=141&c=9
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSeqOneByteStringChars(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    int32_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 8));
    READ_FIELD_OR_FAIL(int32_t, tmp1, accessor, p_o, tmp0);
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_int32_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0xcull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewConstSlice_char8_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSeqOneByteStringChars
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSeqTwoByteStringChars
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSeqTwoByteStringChars

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=147&c=9
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSeqTwoByteStringChars(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    int32_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 8));
    READ_FIELD_OR_FAIL(int32_t, tmp1, accessor, p_o, tmp0);
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_int32_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0xcull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewConstSlice_char16_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSeqTwoByteStringChars
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSwissNameDictionaryDataTable
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSwissNameDictionaryDataTable

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/swiss-name-dictionary.tq?l=12&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSwissNameDictionaryDataTable(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    int32_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uintptr_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    intptr_t tmp9 {};
    USE(tmp9);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 8));
    READ_FIELD_OR_FAIL(int32_t, tmp1, accessor, p_o, tmp0);
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_int32_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x2ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp2, tmp3));
    ASSIGN_OR_RETURN(tmp5, TqDebugConvert_intptr_intptr_0(accessor, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x10ull)));
    ASSIGN_OR_RETURN(std::tie(tmp7, tmp8, tmp9),
        TqDebugNewMutableSlice_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0(
            accessor, p_o, tmp6, tmp5));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp7, tmp8, tmp9) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSwissNameDictionaryDataTable
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSwissNameDictionaryCtrlTable
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSwissNameDictionaryCtrlTable

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/swiss-name-dictionary.tq?l=13&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSwissNameDictionaryCtrlTable(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    int32_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    intptr_t tmp9 {};
    USE(tmp9);
    intptr_t tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    uintptr_t tmp12 {};
    USE(tmp12);
    intptr_t tmp13 {};
    USE(tmp13);
    intptr_t tmp14 {};
    USE(tmp14);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceSwissNameDictionaryDataTable(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x4ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 8));
    READ_FIELD_OR_FAIL(int32_t, tmp7, accessor, p_o, tmp6);
    ASSIGN_OR_RETURN(tmp8, TqDebugConvert_intptr_int32_0(accessor, tmp7));
    ASSIGN_OR_RETURN(tmp9, TqDebugFromConstexpr_intptr_constexpr_int32_0(accessor, swiss_table::Group::kWidth));
    ASSIGN_OR_RETURN(tmp10, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp8, tmp9));
    ASSIGN_OR_RETURN(tmp11, TqDebugConvert_intptr_intptr_0(accessor, tmp10));
    ASSIGN_OR_RETURN(std::tie(tmp12, tmp13, tmp14), TqDebugNewMutableSlice_uint8_0(accessor, p_o, tmp5, tmp11));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp12, tmp13, tmp14) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSwissNameDictionaryCtrlTable
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceSwissNameDictionaryPropertyDetailsTable
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceSwissNameDictionaryPropertyDetailsTable

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/swiss-name-dictionary.tq?l=14&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceSwissNameDictionaryPropertyDetailsTable(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    int32_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    intptr_t tmp9 {};
    USE(tmp9);
    uintptr_t tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    intptr_t tmp12 {};
    USE(tmp12);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceSwissNameDictionaryCtrlTable(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x1ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 8));
    READ_FIELD_OR_FAIL(int32_t, tmp7, accessor, p_o, tmp6);
    ASSIGN_OR_RETURN(tmp8, TqDebugConvert_intptr_int32_0(accessor, tmp7));
    ASSIGN_OR_RETURN(tmp9, TqDebugConvert_intptr_intptr_0(accessor, tmp8));
    ASSIGN_OR_RETURN(std::tie(tmp10, tmp11, tmp12), TqDebugNewMutableSlice_uint8_0(accessor, p_o, tmp5, tmp9));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp10, tmp11, tmp12) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceSwissNameDictionaryPropertyDetailsTable
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceTurboshaftWord32SetTypeElements
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceTurboshaftWord32SetTypeElements

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=38&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceTurboshaftWord32SetTypeElements(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uint32_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_FIELD_OR_FAIL(uint32_t, tmp1, accessor, p_o, tmp0);
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_uint32_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_uint32_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceTurboshaftWord32SetTypeElements
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceTurboshaftWord64SetTypeElementsHigh
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceTurboshaftWord64SetTypeElementsHigh

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=61&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceTurboshaftWord64SetTypeElementsHigh(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uint32_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_FIELD_OR_FAIL(uint32_t, tmp1, accessor, p_o, tmp0);
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_uint32_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x8ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_uint32_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceTurboshaftWord64SetTypeElementsHigh
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceTurboshaftWord64SetTypeElementsLow
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceTurboshaftWord64SetTypeElementsLow

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=62&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceTurboshaftWord64SetTypeElementsLow(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uint32_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    uintptr_t tmp9 {};
    USE(tmp9);
    intptr_t tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceTurboshaftWord64SetTypeElementsHigh(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x4ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 4));
    READ_FIELD_OR_FAIL(uint32_t, tmp7, accessor, p_o, tmp6);
    ASSIGN_OR_RETURN(tmp8, TqDebugConvert_intptr_uint32_0(accessor, tmp7));
    ASSIGN_OR_RETURN(std::tie(tmp9, tmp10, tmp11), TqDebugNewMutableSlice_uint32_0(accessor, p_o, tmp5, tmp8));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp9, tmp10, tmp11) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceTurboshaftWord64SetTypeElementsLow
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceTurboshaftFloat64SetTypeElements
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceTurboshaftFloat64SetTypeElements

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=86&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceTurboshaftFloat64SetTypeElements(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uint32_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 8));
    READ_FIELD_OR_FAIL(uint32_t, tmp1, accessor, p_o, tmp0);
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_uint32_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0xcull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_float64_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceTurboshaftFloat64SetTypeElements
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceInternalClassWithStructElementsEntries
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceInternalClassWithStructElementsEntries

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1201&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceInternalClassWithStructElementsEntries(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 12));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x18ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_Smi_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceInternalClassWithStructElementsEntries
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceInternalClassWithStructElementsMoreEntries
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceInternalClassWithStructElementsMoreEntries

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1202&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceInternalClassWithStructElementsMoreEntries(d::MemoryAccessor accessor, uintptr_t p_o)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    intptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    uintptr_t tmp7 {};
    USE(tmp7);
    intptr_t tmp8 {};
    USE(tmp8);
    uintptr_t tmp9 {};
    USE(tmp9);
    intptr_t tmp10 {};
    USE(tmp10);
    intptr_t tmp11 {};
    USE(tmp11);
    goto block0;

block0:
    ASSIGN_OR_RETURN(std::tie(tmp0, tmp1, tmp2), TqDebugFieldSliceInternalClassWithStructElementsEntries(accessor, p_o));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x4ull)));
    ASSIGN_OR_RETURN(tmp4, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, tmp3, tmp2));
    ASSIGN_OR_RETURN(tmp5, TorqueDebugMacroShims::CodeStubAssembler::IntPtrAdd(accessor, tmp1, tmp4));
    ASSIGN_OR_RETURN(tmp6, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 12));
    READ_TAGGED_FIELD_OR_FAIL(tmp7, accessor, p_o, static_cast<int>(tmp6));
    ASSIGN_OR_RETURN(tmp8, TqDebugConvert_intptr_Smi_0(accessor, tmp7));
    ASSIGN_OR_RETURN(std::tie(tmp9, tmp10, tmp11), TqDebugNewMutableSlice_InternalClassStructElement_0(accessor, p_o, tmp5, tmp8));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp9, tmp10, tmp11) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceInternalClassWithStructElementsMoreEntries
#ifndef V8_INTERNAL_DEFINED_TqDebugFieldSliceWasmTypeInfoSupertypes
#define V8_INTERNAL_DEFINED_TqDebugFieldSliceWasmTypeInfoSupertypes

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugFieldSliceWasmTypeInfoSupertypes(d::MemoryAccessor accessor, uintptr_t p_o)
{
    intptr_t tmp0 {};
    USE(tmp0);
    uintptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    intptr_t tmp3 {};
    USE(tmp3);
    uintptr_t tmp4 {};
    USE(tmp4);
    intptr_t tmp5 {};
    USE(tmp5);
    intptr_t tmp6 {};
    USE(tmp6);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, 16));
    READ_TAGGED_FIELD_OR_FAIL(tmp1, accessor, p_o, static_cast<int>(tmp0));
    ASSIGN_OR_RETURN(tmp2, TqDebugConvert_intptr_Smi_0(accessor, tmp1));
    ASSIGN_OR_RETURN(tmp3, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, IntegerLiteral(false, 0x14ull)));
    ASSIGN_OR_RETURN(std::tie(tmp4, tmp5, tmp6), TqDebugNewMutableSlice_Object_0(accessor, p_o, tmp3, tmp2));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp4, tmp5, tmp6) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFieldSliceWasmTypeInfoSupertypes
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=290&c=1
Value<intptr_t> TqDebugConvert_intptr_Smi_0(d::MemoryAccessor accessor, uintptr_t p_s)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::SmiUntag(accessor, p_s));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Object_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Object_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=14&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_Object_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Object_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=290&c=1
Value<intptr_t> TqDebugConvert_intptr_Smi_0(d::MemoryAccessor accessor, uintptr_t p_s)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::SmiUntag(accessor, p_s));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Smi_OR_TheHole_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Smi_OR_TheHole_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=31&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_Smi_OR_TheHole_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Smi_OR_TheHole_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=290&c=1
Value<intptr_t> TqDebugConvert_intptr_Smi_0(d::MemoryAccessor accessor, uintptr_t p_s)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::SmiUntag(accessor, p_s));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_MaybeObject_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_MaybeObject_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=39&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_MaybeObject_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_MaybeObject_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=290&c=1
Value<intptr_t> TqDebugConvert_intptr_Smi_0(d::MemoryAccessor accessor, uintptr_t p_s)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::SmiUntag(accessor, p_s));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_uint8_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_uint8_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=20&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_uint8_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_uint8_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_uint32_constexpr_uint32_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_uint32_constexpr_uint32_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=127&c=1
Value<uint32_t> TqDebugFromConstexpr_uint32_constexpr_uint32_0(d::MemoryAccessor accessor, uint32_t p_i)
{
    int32_t tmp0 {};
    USE(tmp0);
    uint32_t tmp1 {};
    USE(tmp1);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    ASSIGN_OR_RETURN(tmp1, TorqueDebugMacroShims::CodeStubAssembler::Unsigned(accessor, tmp0));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp1 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_uint32_constexpr_uint32_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/builtins-string.tq?l=189&c=26
Value<intptr_t> TqDebugConvert_intptr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    goto block0;

block0:
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, p_i };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewConstSlice_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugNewConstSlice_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=134&c=9
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewConstSlice_Smi_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewConstSlice_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=290&c=1
Value<intptr_t> TqDebugConvert_intptr_Smi_0(d::MemoryAccessor accessor, uintptr_t p_s)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::SmiUntag(accessor, p_s));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int32_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int32_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=76&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int32_0(d::MemoryAccessor accessor, int32_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int32_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_Smi_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_Smi_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=56&c=1
Value<uintptr_t> TqDebugFromConstexpr_Smi_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(
        tmp0, TqDebugConvert_Smi_constexpr_int31_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToInt31(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_Smi_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_String_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_String_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=140&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_String_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_String_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_NameToIndexHashTable_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_NameToIndexHashTable_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=145&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_NameToIndexHashTable_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_NameToIndexHashTable_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_SmiTagged_VariableProperties_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_SmiTagged_VariableProperties_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=151&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_SmiTagged_VariableProperties_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_SmiTagged_VariableProperties_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=157&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_Smi_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_VariableAllocationInfo_constexpr_NONE_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_VariableAllocationInfo_constexpr_NONE_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=25&c=1
Value<uint32_t> TqDebugFromConstexpr_VariableAllocationInfo_constexpr_NONE_0(d::MemoryAccessor accessor, VariableAllocationInfo p_o)
{
    uint32_t tmp0 {};
    USE(tmp0);
    uint32_t tmp1 {};
    USE(tmp1);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (tmp0);
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp1 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_VariableAllocationInfo_constexpr_NONE_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_FunctionVariableInfo_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_FunctionVariableInfo_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=163&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_FunctionVariableInfo_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_FunctionVariableInfo_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Undefined_OR_String_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Undefined_OR_String_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=168&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_Undefined_OR_String_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Undefined_OR_String_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_TheHole_OR_ScopeInfo_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_TheHole_OR_ScopeInfo_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=170&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_TheHole_OR_ScopeInfo_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_TheHole_OR_ScopeInfo_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_SourceTextModuleInfo_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_SourceTextModuleInfo_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=174&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_SourceTextModuleInfo_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_SourceTextModuleInfo_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=125&c=23
Value<intptr_t> TqDebugConvert_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_uintptr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_uintptr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=389&c=1
Value<uintptr_t> TqDebugConvert_uintptr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::Unsigned(accessor, p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_uintptr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugTimesSizeOf_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugTimesSizeOf_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=109&c=36
Value<intptr_t> TqDebugTimesSizeOf_Smi_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_int31_0(accessor, kTaggedSize));
    ASSIGN_OR_RETURN(tmp1, TorqueDebugMacroShims::CodeStubAssembler::IntPtrMul(accessor, p_i, tmp0));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp1 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugTimesSizeOf_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewReference_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugNewReference_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/torque-internal.tq?l=108&c=12
Value<std::tuple<uintptr_t, intptr_t>> TqDebugNewReference_Smi_0(d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    goto block0;

block0:
    std::tie(tmp0, tmp1) = (std::make_tuple(p_object, p_offset));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewReference_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_ModuleVariable_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_ModuleVariable_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=176&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_ModuleVariable_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_ModuleVariable_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_int32_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_int32_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=204&c=1
Value<intptr_t> TqDebugConvert_intptr_int32_0(d::MemoryAccessor accessor, int32_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::ChangeInt32ToIntPtr(accessor, p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_int32_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_CoverageInfoSlot_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_CoverageInfoSlot_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/debug-objects.tq?l=64&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_CoverageInfoSlot_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_CoverageInfoSlot_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_uint16_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_uint16_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=231&c=1
Value<intptr_t> TqDebugConvert_intptr_uint16_0(d::MemoryAccessor accessor, uint16_t p_ui)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::ChangeUint32ToWord(accessor, p_ui));
    ASSIGN_OR_RETURN(tmp1, TorqueDebugMacroShims::CodeStubAssembler::Signed(accessor, tmp0));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp1 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_uint16_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_DescriptorEntry_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_DescriptorEntry_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/descriptor-array.tq?l=27&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_DescriptorEntry_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_DescriptorEntry_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_int32_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_int32_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=204&c=1
Value<intptr_t> TqDebugConvert_intptr_int32_0(d::MemoryAccessor accessor, int32_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::ChangeInt32ToIntPtr(accessor, p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_int32_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_MaybeObject_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_MaybeObject_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=39&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_MaybeObject_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_MaybeObject_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/base.tq?l=621&c=47
Value<intptr_t> TqDebugConvert_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(accessor, p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_uint8_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_uint8_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=20&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_uint8_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_uint8_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_uint8_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_uint8_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=234&c=1
Value<intptr_t> TqDebugConvert_intptr_uint8_0(d::MemoryAccessor accessor, uint8_t p_ui)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::ChangeUint32ToWord(accessor, p_ui));
    ASSIGN_OR_RETURN(tmp1, TorqueDebugMacroShims::CodeStubAssembler::Signed(accessor, tmp0));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp1 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_uint8_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/builtins-string.tq?l=189&c=26
Value<intptr_t> TqDebugConvert_intptr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    goto block0;

block0:
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, p_i };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=32&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>>
TqDebugNewMutableSlice_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_HashMapEntry_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_HashMapEntry_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=71&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_HashMapEntry_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_HashMapEntry_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_NameDictionaryEntry_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_NameDictionaryEntry_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=111&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_NameDictionaryEntry_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_NameDictionaryEntry_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_int32_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_int32_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=204&c=1
Value<intptr_t> TqDebugConvert_intptr_int32_0(d::MemoryAccessor accessor, int32_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::ChangeInt32ToIntPtr(accessor, p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_int32_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/builtins-string.tq?l=189&c=26
Value<intptr_t> TqDebugConvert_intptr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    goto block0;

block0:
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, p_i };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/ordered-hash-table.tq?l=32&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>>
TqDebugNewMutableSlice_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_JSReceiver_OR_Undefined_OR_Null_OR_Boolean_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int32_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int32_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=76&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int32_0(d::MemoryAccessor accessor, int32_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int32_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_uint8_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_uint8_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=20&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_uint8_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_uint8_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_uint32_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_uint32_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=210&c=1
Value<intptr_t> TqDebugConvert_intptr_uint32_0(d::MemoryAccessor accessor, uint32_t p_i)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::ChangeUint32ToWord(accessor, p_i));
    ASSIGN_OR_RETURN(tmp1, TorqueDebugMacroShims::CodeStubAssembler::Signed(accessor, tmp0));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp1 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_uint32_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_uint32_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_uint32_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=38&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_uint32_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_uint32_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_float64_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_float64_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turboshaft-types.tq?l=86&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_float64_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_float64_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=290&c=1
Value<intptr_t> TqDebugConvert_intptr_Smi_0(d::MemoryAccessor accessor, uintptr_t p_s)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::SmiUntag(accessor, p_s));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=157&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_Smi_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_InternalClassStructElement_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_InternalClassStructElement_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1202&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_InternalClassStructElement_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_InternalClassStructElement_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=290&c=1
Value<intptr_t> TqDebugConvert_intptr_Smi_0(d::MemoryAccessor accessor, uintptr_t p_s)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::SmiUntag(accessor, p_s));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Object_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Object_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=14&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_Object_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Object_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_Smi_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_Smi_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=57&c=10
Value<uintptr_t> TqDebugConvert_Smi_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TqDebugFromConstexpr_Smi_constexpr_int31_0(accessor, p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_Smi_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_Smi_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_Smi_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=85&c=1
Value<uintptr_t> TqDebugFromConstexpr_Smi_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = Internals::IntToSmi(CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_Smi_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Object_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Object_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=14&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_Object_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Object_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Context_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Context_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=22&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_Context_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Context_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_float64_or_hole_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_float64_or_hole_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=33&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_float64_or_hole_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_float64_or_hole_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=290&c=1
Value<intptr_t> TqDebugConvert_intptr_Smi_0(d::MemoryAccessor accessor, uintptr_t p_s)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::SmiUntag(accessor, p_s));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/scope-info.tq?l=157&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_Smi_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=290&c=1
Value<intptr_t> TqDebugConvert_intptr_Smi_0(d::MemoryAccessor accessor, uintptr_t p_s)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::SmiUntag(accessor, p_s));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_FeedbackCell_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_FeedbackCell_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/feedback-vector.tq?l=41&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_FeedbackCell_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_FeedbackCell_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Smi_OR_TrustedObject_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Smi_OR_TrustedObject_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/fixed-array.tq?l=28&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_Smi_OR_TrustedObject_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Smi_OR_TrustedObject_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_uint8_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_uint8_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/bytecode-array.tq?l=20&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_uint8_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_uint8_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=290&c=1
Value<intptr_t> TqDebugConvert_intptr_Smi_0(d::MemoryAccessor accessor, uintptr_t p_s)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::SmiUntag(accessor, p_s));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Object_0
#define V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Object_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=14&c=3
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewMutableSlice_Object_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewMutableSlice_Object_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_int31_0(d::MemoryAccessor accessor, int31_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqDebugConvert_intptr_int32_0
#define V8_INTERNAL_DEFINED_TqDebugConvert_intptr_int32_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=204&c=1
Value<intptr_t> TqDebugConvert_intptr_int32_0(d::MemoryAccessor accessor, int32_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0, TorqueDebugMacroShims::CodeStubAssembler::ChangeInt32ToIntPtr(accessor, p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugConvert_intptr_int32_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0(d::MemoryAccessor accessor, IntegerLiteral p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    ASSIGN_OR_RETURN(tmp0,
        TqDebugFromConstexpr_intptr_constexpr_intptr_0(accessor, (TorqueDebugMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(accessor, p_i))));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewConstSlice_char8_0
#define V8_INTERNAL_DEFINED_TqDebugNewConstSlice_char8_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/string.tq?l=141&c=9
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewConstSlice_char8_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewConstSlice_char8_0
#ifndef V8_INTERNAL_DEFINED_TqDebugNewConstSlice_char16_0
#define V8_INTERNAL_DEFINED_TqDebugNewConstSlice_char16_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/wasm.tq?l=1035&c=26
Value<std::tuple<uintptr_t, intptr_t, intptr_t>> TqDebugNewConstSlice_char16_0(
    d::MemoryAccessor accessor, uintptr_t p_object, intptr_t p_offset, intptr_t p_length)
{
    uintptr_t tmp0 {};
    USE(tmp0);
    intptr_t tmp1 {};
    USE(tmp1);
    intptr_t tmp2 {};
    USE(tmp2);
    goto block0;

block0:
    std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, std::make_tuple(tmp0, tmp1, tmp2) };
}

#endif // V8_INTERNAL_DEFINED_TqDebugNewConstSlice_char16_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#ifndef V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
Value<intptr_t> TqDebugFromConstexpr_intptr_constexpr_intptr_0(d::MemoryAccessor accessor, intptr_t p_i)
{
    intptr_t tmp0 {};
    USE(tmp0);
    goto block0;

block0:
    tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
    goto block2;

block2:
    return { d::MemoryAccessResult::kOk, tmp0 };
}

#endif // V8_INTERNAL_DEFINED_TqDebugFromConstexpr_intptr_constexpr_intptr_0
} // namespace internal
} // namespace v8
} // namespace debug_helper_internal
