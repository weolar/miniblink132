// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
inline std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceWasmTypeInfoSupertypes(Tagged<WasmTypeInfo> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
inline intptr_t TqRuntimeFromConstexpr_intptr_constexpr_int31_0(int31_t p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=290&c=1
inline intptr_t TqRuntimeConvert_intptr_Smi_0(Tagged<Smi> p_s);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
inline intptr_t TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0(IntegerLiteral p_i);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=14&c=3
inline std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeNewMutableSlice_Object_0(Tagged<Union<HeapObject, TaggedIndex>> p_object, intptr_t p_offset, intptr_t p_length);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
inline intptr_t TqRuntimeFromConstexpr_intptr_constexpr_intptr_0(intptr_t p_i);

#ifndef V8_INTERNAL_DEFINED_TqRuntimeFieldSliceWasmTypeInfoSupertypes
#define V8_INTERNAL_DEFINED_TqRuntimeFieldSliceWasmTypeInfoSupertypes

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeFieldSliceWasmTypeInfoSupertypes(Tagged<WasmTypeInfo> p_o) {
  DisallowGarbageCollection no_gc;
  intptr_t tmp0{}; USE(tmp0);
  Tagged<Smi> tmp1{}; USE(tmp1);
  intptr_t tmp2{}; USE(tmp2);
  intptr_t tmp3{}; USE(tmp3);
  Tagged<Union<HeapObject, TaggedIndex>> tmp4{}; USE(tmp4);
  intptr_t tmp5{}; USE(tmp5);
  intptr_t tmp6{}; USE(tmp6);
  goto block0;

  block0:
  tmp0 = TqRuntimeFromConstexpr_intptr_constexpr_int31_0(16);
  tmp1 = TaggedField<Tagged<Smi>>::load(UncheckedCast<HeapObject>(p_o), static_cast<int>(tmp0));
  tmp2 = TqRuntimeConvert_intptr_Smi_0(tmp1);
  tmp3 = TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0(IntegerLiteral(false, 0x14ull));
  std::tie(tmp4, tmp5, tmp6) = TqRuntimeNewMutableSlice_Object_0(p_o, tmp3, tmp2);
  goto block2;

  block2:
  return std::make_tuple(tmp4, tmp5, tmp6);
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeFieldSliceWasmTypeInfoSupertypes
#ifndef V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_int31_0
#define V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_int31_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=73&c=1
intptr_t TqRuntimeFromConstexpr_intptr_constexpr_int31_0(int31_t p_i) {
  DisallowGarbageCollection no_gc;
  intptr_t tmp0{}; USE(tmp0);
  goto block0;

  block0:
  tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
  goto block2;

  block2:
  return tmp0;
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_int31_0
#ifndef V8_INTERNAL_DEFINED_TqRuntimeConvert_intptr_Smi_0
#define V8_INTERNAL_DEFINED_TqRuntimeConvert_intptr_Smi_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=290&c=1
intptr_t TqRuntimeConvert_intptr_Smi_0(Tagged<Smi> p_s) {
  DisallowGarbageCollection no_gc;
  intptr_t tmp0{}; USE(tmp0);
  goto block0;

  block0:
  tmp0 = TorqueRuntimeMacroShims::CodeStubAssembler::SmiUntag(p_s);
  goto block2;

  block2:
  return tmp0;
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeConvert_intptr_Smi_0
#ifndef V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0
#define V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=8&c=1
intptr_t TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0(IntegerLiteral p_i) {
  DisallowGarbageCollection no_gc;
  intptr_t tmp0{}; USE(tmp0);
  goto block0;

  block0:
  tmp0 = TqRuntimeFromConstexpr_intptr_constexpr_intptr_0((TorqueRuntimeMacroShims::CodeStubAssembler::ConstexprIntegerLiteralToIntptr(p_i)));
  goto block2;

  block2:
  return tmp0;
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_IntegerLiteral_0
#ifndef V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_Object_0
#define V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_Object_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/contexts.tq?l=14&c=3
std::tuple<Tagged<Union<HeapObject, TaggedIndex>>, intptr_t, intptr_t> TqRuntimeNewMutableSlice_Object_0(Tagged<Union<HeapObject, TaggedIndex>> p_object, intptr_t p_offset, intptr_t p_length) {
  DisallowGarbageCollection no_gc;
  Tagged<Union<HeapObject, TaggedIndex>> tmp0{}; USE(tmp0);
  intptr_t tmp1{}; USE(tmp1);
  intptr_t tmp2{}; USE(tmp2);
  goto block0;

  block0:
  std::tie(tmp0, tmp1, tmp2) = (std::make_tuple(p_object, p_offset, p_length));
  goto block2;

  block2:
  return std::make_tuple(tmp0, tmp1, tmp2);
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeNewMutableSlice_Object_0
#ifndef V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_intptr_0
#define V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_intptr_0

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/convert.tq?l=79&c=1
intptr_t TqRuntimeFromConstexpr_intptr_constexpr_intptr_0(intptr_t p_i) {
  DisallowGarbageCollection no_gc;
  intptr_t tmp0{}; USE(tmp0);
  goto block0;

  block0:
  tmp0 = (CastToUnderlyingTypeIfEnum(p_i));
  goto block2;

  block2:
  return tmp0;
}

#endif // V8_INTERNAL_DEFINED_TqRuntimeFromConstexpr_intptr_constexpr_intptr_0
template<class D, class P>
inline TorqueGeneratedWasmNull<D, P>::TorqueGeneratedWasmNull(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmNull_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedWasmFuncRef<D, P>::TorqueGeneratedWasmFuncRef(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmFuncRef_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=48&c=3
template<class D, class P>
Tagged<NativeContext> TorqueGeneratedWasmImportData<D, P>::native_context() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmImportData::native_context(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=48&c=3
template<class D, class P>
Tagged<NativeContext> TorqueGeneratedWasmImportData<D, P>::native_context(PtrComprCageBase cage_base) const {
  Tagged<NativeContext> value = TaggedField<Tagged<NativeContext>>::load(cage_base, *this, kNativeContextOffset);
  DCHECK(IsNativeContext(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=48&c=3
template<class D, class P>
void TorqueGeneratedWasmImportData<D, P>::set_native_context(Tagged<NativeContext> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsNativeContext(value));
  WRITE_FIELD(*this, kNativeContextOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNativeContextOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=49&c=3
template<class D, class P>
Tagged<Union<JSReceiver, Undefined>> TorqueGeneratedWasmImportData<D, P>::callable() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmImportData::callable(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=49&c=3
template<class D, class P>
Tagged<Union<JSReceiver, Undefined>> TorqueGeneratedWasmImportData<D, P>::callable(PtrComprCageBase cage_base) const {
  Tagged<Union<JSReceiver, Undefined>> value = TaggedField<Tagged<Union<JSReceiver, Undefined>>>::load(cage_base, *this, kCallableOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=49&c=3
template<class D, class P>
void TorqueGeneratedWasmImportData<D, P>::set_callable(Tagged<Union<JSReceiver, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value));
  WRITE_FIELD(*this, kCallableOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCallableOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=50&c=3
template<class D, class P>
int TorqueGeneratedWasmImportData<D, P>::suspend() const {
  int value = TaggedField<Smi>::load(*this, kSuspendOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=50&c=3
template<class D, class P>
void TorqueGeneratedWasmImportData<D, P>::set_suspend(int value) {
  WRITE_FIELD(*this, kSuspendOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=51&c=3
template<class D, class P>
int TorqueGeneratedWasmImportData<D, P>::wrapper_budget() const {
  int value = TaggedField<Smi>::load(*this, kWrapperBudgetOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=51&c=3
template<class D, class P>
void TorqueGeneratedWasmImportData<D, P>::set_wrapper_budget(int value) {
  WRITE_FIELD(*this, kWrapperBudgetOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=58&c=3
template<class D, class P>
Tagged<Union<Smi, Tuple2, WasmFuncRef>> TorqueGeneratedWasmImportData<D, P>::call_origin() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmImportData::call_origin(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=58&c=3
template<class D, class P>
Tagged<Union<Smi, Tuple2, WasmFuncRef>> TorqueGeneratedWasmImportData<D, P>::call_origin(PtrComprCageBase cage_base) const {
  Tagged<Union<Smi, Tuple2, WasmFuncRef>> value = TaggedField<Tagged<Union<Smi, Tuple2, WasmFuncRef>>>::load(cage_base, *this, kCallOriginOffset);
  DCHECK(IsSmi(value) || IsWasmFuncRef(value) || IsTuple2(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=58&c=3
template<class D, class P>
void TorqueGeneratedWasmImportData<D, P>::set_call_origin(Tagged<Union<Smi, Tuple2, WasmFuncRef>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsSmi(value) || IsWasmFuncRef(value) || IsTuple2(value));
  WRITE_FIELD(*this, kCallOriginOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCallOriginOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=60&c=3
template<class D, class P>
const wasm::CanonicalSig* TorqueGeneratedWasmImportData<D, P>::sig() const {
  const wasm::CanonicalSig* value = this->template ReadField<const wasm::CanonicalSig*>(kSigOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=60&c=3
template<class D, class P>
void TorqueGeneratedWasmImportData<D, P>::set_sig(const wasm::CanonicalSig* value) {
  this->template WriteField<const wasm::CanonicalSig*>(kSigOffset, value);
}

template<class D, class P>
inline TorqueGeneratedWasmImportData<D, P>::TorqueGeneratedWasmImportData(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmImportData_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=35&c=3
template<class D, class P>
Tagged<WasmModuleObject> TorqueGeneratedWasmInstanceObject<D, P>::module_object() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmInstanceObject::module_object(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=35&c=3
template<class D, class P>
Tagged<WasmModuleObject> TorqueGeneratedWasmInstanceObject<D, P>::module_object(PtrComprCageBase cage_base) const {
  Tagged<WasmModuleObject> value = TaggedField<Tagged<WasmModuleObject>>::load(cage_base, *this, kModuleObjectOffset);
  DCHECK(IsWasmModuleObject(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=35&c=3
template<class D, class P>
void TorqueGeneratedWasmInstanceObject<D, P>::set_module_object(Tagged<WasmModuleObject> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsWasmModuleObject(value));
  WRITE_FIELD(*this, kModuleObjectOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kModuleObjectOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=36&c=3
template<class D, class P>
Tagged<JSObject> TorqueGeneratedWasmInstanceObject<D, P>::exports_object() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmInstanceObject::exports_object(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=36&c=3
template<class D, class P>
Tagged<JSObject> TorqueGeneratedWasmInstanceObject<D, P>::exports_object(PtrComprCageBase cage_base) const {
  Tagged<JSObject> value = TaggedField<Tagged<JSObject>>::load(cage_base, *this, kExportsObjectOffset);
  DCHECK(IsJSObject(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=36&c=3
template<class D, class P>
void TorqueGeneratedWasmInstanceObject<D, P>::set_exports_object(Tagged<JSObject> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSObject(value));
  WRITE_FIELD(*this, kExportsObjectOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kExportsObjectOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedWasmInstanceObject<D, P>::TorqueGeneratedWasmInstanceObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmInstanceObject_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=84&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedWasmInternalFunction<D, P>::external() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmInternalFunction::external(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=84&c=3
template<class D, class P>
Tagged<Union<JSFunction, Undefined>> TorqueGeneratedWasmInternalFunction<D, P>::external(PtrComprCageBase cage_base) const {
  Tagged<Union<JSFunction, Undefined>> value = TaggedField<Tagged<Union<JSFunction, Undefined>>>::load(cage_base, *this, kExternalOffset);
  DCHECK(IsUndefined(value) || IsJSFunction(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=84&c=3
template<class D, class P>
void TorqueGeneratedWasmInternalFunction<D, P>::set_external(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSFunction(value));
  WRITE_FIELD(*this, kExternalOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kExternalOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=91&c=3
template<class D, class P>
int TorqueGeneratedWasmInternalFunction<D, P>::function_index() const {
  int value = TaggedField<Smi>::load(*this, kFunctionIndexOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=91&c=3
template<class D, class P>
void TorqueGeneratedWasmInternalFunction<D, P>::set_function_index(int value) {
  WRITE_FIELD(*this, kFunctionIndexOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=93&c=3
template<class D, class P>
Address TorqueGeneratedWasmInternalFunction<D, P>::call_target() const {
  Address value = this->template ReadField<Address>(kCallTargetOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=93&c=3
template<class D, class P>
void TorqueGeneratedWasmInternalFunction<D, P>::set_call_target(Address value) {
  this->template WriteField<Address>(kCallTargetOffset, value);
}

template<class D, class P>
inline TorqueGeneratedWasmInternalFunction<D, P>::TorqueGeneratedWasmInternalFunction(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmInternalFunction_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=123&c=3
template<class D, class P>
Tagged<WasmFuncRef> TorqueGeneratedWasmFunctionData<D, P>::func_ref() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmFunctionData::func_ref(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=123&c=3
template<class D, class P>
Tagged<WasmFuncRef> TorqueGeneratedWasmFunctionData<D, P>::func_ref(PtrComprCageBase cage_base) const {
  Tagged<WasmFuncRef> value = TaggedField<Tagged<WasmFuncRef>>::load(cage_base, *this, kFuncRefOffset);
  DCHECK(IsWasmFuncRef(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=123&c=3
template<class D, class P>
void TorqueGeneratedWasmFunctionData<D, P>::set_func_ref(Tagged<WasmFuncRef> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsWasmFuncRef(value));
  WRITE_FIELD(*this, kFuncRefOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kFuncRefOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=125&c=3
template<class D, class P>
int TorqueGeneratedWasmFunctionData<D, P>::js_promise_flags() const {
  int value = TaggedField<Smi>::load(*this, kJsPromiseFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=125&c=3
template<class D, class P>
void TorqueGeneratedWasmFunctionData<D, P>::set_js_promise_flags(int value) {
  WRITE_FIELD(*this, kJsPromiseFlagsOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedWasmFunctionData<D, P>::TorqueGeneratedWasmFunctionData(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmFunctionData_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=139&c=3
template<class D, class P>
int TorqueGeneratedWasmExportedFunctionData<D, P>::function_index() const {
  int value = TaggedField<Smi>::load(*this, kFunctionIndexOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=139&c=3
template<class D, class P>
void TorqueGeneratedWasmExportedFunctionData<D, P>::set_function_index(int value) {
  WRITE_FIELD(*this, kFunctionIndexOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=141&c=3
template<class D, class P>
Tagged<Cell> TorqueGeneratedWasmExportedFunctionData<D, P>::wrapper_budget() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmExportedFunctionData::wrapper_budget(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=141&c=3
template<class D, class P>
Tagged<Cell> TorqueGeneratedWasmExportedFunctionData<D, P>::wrapper_budget(PtrComprCageBase cage_base) const {
  Tagged<Cell> value = TaggedField<Tagged<Cell>>::load(cage_base, *this, kWrapperBudgetOffset);
  DCHECK(IsCell(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=141&c=3
template<class D, class P>
void TorqueGeneratedWasmExportedFunctionData<D, P>::set_wrapper_budget(Tagged<Cell> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsCell(value));
  WRITE_FIELD(*this, kWrapperBudgetOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kWrapperBudgetOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=142&c=3
template<class D, class P>
int TorqueGeneratedWasmExportedFunctionData<D, P>::canonical_type_index() const {
  int value = TaggedField<Smi>::load(*this, kCanonicalTypeIndexOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=142&c=3
template<class D, class P>
void TorqueGeneratedWasmExportedFunctionData<D, P>::set_canonical_type_index(int value) {
  WRITE_FIELD(*this, kCanonicalTypeIndexOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=147&c=3
template<class D, class P>
int TorqueGeneratedWasmExportedFunctionData<D, P>::packed_args_size() const {
  int value = TaggedField<Smi>::load(*this, kPackedArgsSizeOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=147&c=3
template<class D, class P>
void TorqueGeneratedWasmExportedFunctionData<D, P>::set_packed_args_size(int value) {
  WRITE_FIELD(*this, kPackedArgsSizeOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=150&c=3
template<class D, class P>
const wasm::CanonicalSig* TorqueGeneratedWasmExportedFunctionData<D, P>::sig() const {
  const wasm::CanonicalSig* value = this->template ReadField<const wasm::CanonicalSig*>(kSigOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=150&c=3
template<class D, class P>
void TorqueGeneratedWasmExportedFunctionData<D, P>::set_sig(const wasm::CanonicalSig* value) {
  this->template WriteField<const wasm::CanonicalSig*>(kSigOffset, value);
}

template<class D, class P>
inline TorqueGeneratedWasmExportedFunctionData<D, P>::TorqueGeneratedWasmExportedFunctionData(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmExportedFunctionData_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=158&c=3
template<class D, class P>
int TorqueGeneratedWasmJSFunctionData<D, P>::canonical_sig_index() const {
  int value = TaggedField<Smi>::load(*this, kCanonicalSigIndexOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=158&c=3
template<class D, class P>
void TorqueGeneratedWasmJSFunctionData<D, P>::set_canonical_sig_index(int value) {
  WRITE_FIELD(*this, kCanonicalSigIndexOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedWasmJSFunctionData<D, P>::TorqueGeneratedWasmJSFunctionData(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmJSFunctionData_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=165&c=3
template<class D, class P>
int TorqueGeneratedWasmCapiFunctionData<D, P>::canonical_sig_index() const {
  int value = TaggedField<Smi>::load(*this, kCanonicalSigIndexOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=165&c=3
template<class D, class P>
void TorqueGeneratedWasmCapiFunctionData<D, P>::set_canonical_sig_index(int value) {
  WRITE_FIELD(*this, kCanonicalSigIndexOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=166&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedWasmCapiFunctionData<D, P>::embedder_data() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmCapiFunctionData::embedder_data(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=166&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedWasmCapiFunctionData<D, P>::embedder_data(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kEmbedderDataOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=166&c=3
template<class D, class P>
void TorqueGeneratedWasmCapiFunctionData<D, P>::set_embedder_data(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kEmbedderDataOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kEmbedderDataOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=167&c=3
template<class D, class P>
const wasm::CanonicalSig* TorqueGeneratedWasmCapiFunctionData<D, P>::sig() const {
  const wasm::CanonicalSig* value = this->template ReadField<const wasm::CanonicalSig*>(kSigOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=167&c=3
template<class D, class P>
void TorqueGeneratedWasmCapiFunctionData<D, P>::set_sig(const wasm::CanonicalSig* value) {
  this->template WriteField<const wasm::CanonicalSig*>(kSigOffset, value);
}

template<class D, class P>
inline TorqueGeneratedWasmCapiFunctionData<D, P>::TorqueGeneratedWasmCapiFunctionData(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmCapiFunctionData_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=171&c=3
template<class D, class P>
Tagged<WasmSuspenderObject> TorqueGeneratedWasmResumeData<D, P>::suspender() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmResumeData::suspender(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=171&c=3
template<class D, class P>
Tagged<WasmSuspenderObject> TorqueGeneratedWasmResumeData<D, P>::suspender(PtrComprCageBase cage_base) const {
  Tagged<WasmSuspenderObject> value = TaggedField<Tagged<WasmSuspenderObject>>::load(cage_base, *this, kSuspenderOffset);
  DCHECK(IsWasmSuspenderObject(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=171&c=3
template<class D, class P>
void TorqueGeneratedWasmResumeData<D, P>::set_suspender(Tagged<WasmSuspenderObject> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsWasmSuspenderObject(value));
  WRITE_FIELD(*this, kSuspenderOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSuspenderOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=172&c=3
template<class D, class P>
int TorqueGeneratedWasmResumeData<D, P>::on_resume() const {
  int value = TaggedField<Smi>::load(*this, kOnResumeOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=172&c=3
template<class D, class P>
void TorqueGeneratedWasmResumeData<D, P>::set_on_resume(int value) {
  WRITE_FIELD(*this, kOnResumeOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedWasmResumeData<D, P>::TorqueGeneratedWasmResumeData(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmResumeData_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=176&c=3
template<class D, class P>
Tagged<Union<Undefined, WasmContinuationObject>> TorqueGeneratedWasmContinuationObject<D, P>::parent() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmContinuationObject::parent(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=176&c=3
template<class D, class P>
Tagged<Union<Undefined, WasmContinuationObject>> TorqueGeneratedWasmContinuationObject<D, P>::parent(PtrComprCageBase cage_base) const {
  Tagged<Union<Undefined, WasmContinuationObject>> value = TaggedField<Tagged<Union<Undefined, WasmContinuationObject>>>::load(cage_base, *this, kParentOffset);
  DCHECK(IsUndefined(value) || IsWasmContinuationObject(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=176&c=3
template<class D, class P>
void TorqueGeneratedWasmContinuationObject<D, P>::set_parent(Tagged<Union<Undefined, WasmContinuationObject>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsWasmContinuationObject(value));
  WRITE_FIELD(*this, kParentOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kParentOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedWasmContinuationObject<D, P>::TorqueGeneratedWasmContinuationObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmContinuationObject_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=182&c=3
template<class D, class P>
Tagged<Union<Undefined, WasmContinuationObject>> TorqueGeneratedWasmSuspenderObject<D, P>::continuation() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmSuspenderObject::continuation(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=182&c=3
template<class D, class P>
Tagged<Union<Undefined, WasmContinuationObject>> TorqueGeneratedWasmSuspenderObject<D, P>::continuation(PtrComprCageBase cage_base) const {
  Tagged<Union<Undefined, WasmContinuationObject>> value = TaggedField<Tagged<Union<Undefined, WasmContinuationObject>>>::load(cage_base, *this, kContinuationOffset);
  DCHECK(IsUndefined(value) || IsWasmContinuationObject(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=182&c=3
template<class D, class P>
void TorqueGeneratedWasmSuspenderObject<D, P>::set_continuation(Tagged<Union<Undefined, WasmContinuationObject>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsWasmContinuationObject(value));
  WRITE_FIELD(*this, kContinuationOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kContinuationOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=183&c=3
template<class D, class P>
Tagged<Union<Undefined, WasmSuspenderObject>> TorqueGeneratedWasmSuspenderObject<D, P>::parent() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmSuspenderObject::parent(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=183&c=3
template<class D, class P>
Tagged<Union<Undefined, WasmSuspenderObject>> TorqueGeneratedWasmSuspenderObject<D, P>::parent(PtrComprCageBase cage_base) const {
  Tagged<Union<Undefined, WasmSuspenderObject>> value = TaggedField<Tagged<Union<Undefined, WasmSuspenderObject>>>::load(cage_base, *this, kParentOffset);
  DCHECK(IsUndefined(value) || IsWasmSuspenderObject(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=183&c=3
template<class D, class P>
void TorqueGeneratedWasmSuspenderObject<D, P>::set_parent(Tagged<Union<Undefined, WasmSuspenderObject>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsWasmSuspenderObject(value));
  WRITE_FIELD(*this, kParentOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kParentOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=184&c=3
template<class D, class P>
Tagged<JSPromise> TorqueGeneratedWasmSuspenderObject<D, P>::promise() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmSuspenderObject::promise(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=184&c=3
template<class D, class P>
Tagged<JSPromise> TorqueGeneratedWasmSuspenderObject<D, P>::promise(PtrComprCageBase cage_base) const {
  Tagged<JSPromise> value = TaggedField<Tagged<JSPromise>>::load(cage_base, *this, kPromiseOffset);
  DCHECK(IsJSPromise(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=184&c=3
template<class D, class P>
void TorqueGeneratedWasmSuspenderObject<D, P>::set_promise(Tagged<JSPromise> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSPromise(value));
  WRITE_FIELD(*this, kPromiseOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kPromiseOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=185&c=3
template<class D, class P>
Tagged<Union<JSObject, Undefined>> TorqueGeneratedWasmSuspenderObject<D, P>::resume() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmSuspenderObject::resume(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=185&c=3
template<class D, class P>
Tagged<Union<JSObject, Undefined>> TorqueGeneratedWasmSuspenderObject<D, P>::resume(PtrComprCageBase cage_base) const {
  Tagged<Union<JSObject, Undefined>> value = TaggedField<Tagged<Union<JSObject, Undefined>>>::load(cage_base, *this, kResumeOffset);
  DCHECK(IsUndefined(value) || IsJSObject(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=185&c=3
template<class D, class P>
void TorqueGeneratedWasmSuspenderObject<D, P>::set_resume(Tagged<Union<JSObject, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSObject(value));
  WRITE_FIELD(*this, kResumeOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kResumeOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=186&c=3
template<class D, class P>
Tagged<Union<JSObject, Undefined>> TorqueGeneratedWasmSuspenderObject<D, P>::reject() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmSuspenderObject::reject(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=186&c=3
template<class D, class P>
Tagged<Union<JSObject, Undefined>> TorqueGeneratedWasmSuspenderObject<D, P>::reject(PtrComprCageBase cage_base) const {
  Tagged<Union<JSObject, Undefined>> value = TaggedField<Tagged<Union<JSObject, Undefined>>>::load(cage_base, *this, kRejectOffset);
  DCHECK(IsUndefined(value) || IsJSObject(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=186&c=3
template<class D, class P>
void TorqueGeneratedWasmSuspenderObject<D, P>::set_reject(Tagged<Union<JSObject, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSObject(value));
  WRITE_FIELD(*this, kRejectOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kRejectOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=187&c=3
template<class D, class P>
int TorqueGeneratedWasmSuspenderObject<D, P>::state() const {
  int value = TaggedField<Smi>::load(*this, kStateOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=187&c=3
template<class D, class P>
void TorqueGeneratedWasmSuspenderObject<D, P>::set_state(int value) {
  WRITE_FIELD(*this, kStateOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedWasmSuspenderObject<D, P>::TorqueGeneratedWasmSuspenderObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmSuspenderObject_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=194&c=3
template<class D, class P>
int TorqueGeneratedWasmExceptionTag<D, P>::index() const {
  int value = TaggedField<Smi>::load(*this, kIndexOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=194&c=3
template<class D, class P>
void TorqueGeneratedWasmExceptionTag<D, P>::set_index(int value) {
  WRITE_FIELD(*this, kIndexOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedWasmExceptionTag<D, P>::TorqueGeneratedWasmExceptionTag(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmExceptionTag_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=200&c=3
template<class D, class P>
Tagged<Managed<wasm::NativeModule>> TorqueGeneratedWasmModuleObject<D, P>::managed_native_module() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmModuleObject::managed_native_module(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=200&c=3
template<class D, class P>
Tagged<Managed<wasm::NativeModule>> TorqueGeneratedWasmModuleObject<D, P>::managed_native_module(PtrComprCageBase cage_base) const {
  Tagged<Managed<wasm::NativeModule>> value = TaggedField<Tagged<Managed<wasm::NativeModule>>>::load(cage_base, *this, kManagedNativeModuleOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=200&c=3
template<class D, class P>
void TorqueGeneratedWasmModuleObject<D, P>::set_managed_native_module(Tagged<Managed<wasm::NativeModule>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kManagedNativeModuleOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kManagedNativeModuleOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=201&c=3
template<class D, class P>
Tagged<Script> TorqueGeneratedWasmModuleObject<D, P>::script() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmModuleObject::script(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=201&c=3
template<class D, class P>
Tagged<Script> TorqueGeneratedWasmModuleObject<D, P>::script(PtrComprCageBase cage_base) const {
  Tagged<Script> value = TaggedField<Tagged<Script>>::load(cage_base, *this, kScriptOffset);
  DCHECK(IsScript(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=201&c=3
template<class D, class P>
void TorqueGeneratedWasmModuleObject<D, P>::set_script(Tagged<Script> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsScript(value));
  WRITE_FIELD(*this, kScriptOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kScriptOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedWasmModuleObject<D, P>::TorqueGeneratedWasmModuleObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmModuleObject_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=215&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedWasmTableObject<D, P>::entries() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmTableObject::entries(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=215&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedWasmTableObject<D, P>::entries(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kEntriesOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=215&c=3
template<class D, class P>
void TorqueGeneratedWasmTableObject<D, P>::set_entries(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kEntriesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kEntriesOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=216&c=3
template<class D, class P>
int TorqueGeneratedWasmTableObject<D, P>::current_length() const {
  int value = TaggedField<Smi>::load(*this, kCurrentLengthOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=216&c=3
template<class D, class P>
void TorqueGeneratedWasmTableObject<D, P>::set_current_length(int value) {
  WRITE_FIELD(*this, kCurrentLengthOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=221&c=3
template<class D, class P>
Tagged<Union<BigInt, HeapNumber, Smi, Undefined>> TorqueGeneratedWasmTableObject<D, P>::maximum_length() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmTableObject::maximum_length(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=221&c=3
template<class D, class P>
Tagged<Union<BigInt, HeapNumber, Smi, Undefined>> TorqueGeneratedWasmTableObject<D, P>::maximum_length(PtrComprCageBase cage_base) const {
  Tagged<Union<BigInt, HeapNumber, Smi, Undefined>> value = TaggedField<Tagged<Union<BigInt, HeapNumber, Smi, Undefined>>>::load(cage_base, *this, kMaximumLengthOffset);
  DCHECK(IsUndefined(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=221&c=3
template<class D, class P>
void TorqueGeneratedWasmTableObject<D, P>::set_maximum_length(Tagged<Union<BigInt, HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kMaximumLengthOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kMaximumLengthOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=224&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedWasmTableObject<D, P>::uses() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmTableObject::uses(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=224&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedWasmTableObject<D, P>::uses(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kUsesOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=224&c=3
template<class D, class P>
void TorqueGeneratedWasmTableObject<D, P>::set_uses(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kUsesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kUsesOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=225&c=3
template<class D, class P>
int TorqueGeneratedWasmTableObject<D, P>::raw_type() const {
  int value = TaggedField<Smi>::load(*this, kRawTypeOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=225&c=3
template<class D, class P>
void TorqueGeneratedWasmTableObject<D, P>::set_raw_type(int value) {
  WRITE_FIELD(*this, kRawTypeOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=230&c=3
template<class D, class P>
wasm::AddressType TorqueGeneratedWasmTableObject<D, P>::address_type() const {
  wasm::AddressType value = this->template ReadField<wasm::AddressType>(kAddressTypeOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=230&c=3
template<class D, class P>
void TorqueGeneratedWasmTableObject<D, P>::set_address_type(wasm::AddressType value) {
  this->template WriteField<wasm::AddressType>(kAddressTypeOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=232&c=3
template<class D, class P>
uint8_t TorqueGeneratedWasmTableObject<D, P>::padding_for_address_type_0() const {
  uint8_t value = this->template ReadField<uint8_t>(kPaddingForAddressType0Offset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=232&c=3
template<class D, class P>
void TorqueGeneratedWasmTableObject<D, P>::set_padding_for_address_type_0(uint8_t value) {
  this->template WriteField<uint8_t>(kPaddingForAddressType0Offset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=233&c=3
template<class D, class P>
uint16_t TorqueGeneratedWasmTableObject<D, P>::padding_for_address_type_1() const {
  uint16_t value = this->template ReadField<uint16_t>(kPaddingForAddressType1Offset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=233&c=3
template<class D, class P>
void TorqueGeneratedWasmTableObject<D, P>::set_padding_for_address_type_1(uint16_t value) {
  this->template WriteField<uint16_t>(kPaddingForAddressType1Offset, value);
}

template<class D, class P>
inline TorqueGeneratedWasmTableObject<D, P>::TorqueGeneratedWasmTableObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmTableObject_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=238&c=3
template<class D, class P>
Tagged<JSArrayBuffer> TorqueGeneratedWasmMemoryObject<D, P>::array_buffer() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmMemoryObject::array_buffer(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=238&c=3
template<class D, class P>
Tagged<JSArrayBuffer> TorqueGeneratedWasmMemoryObject<D, P>::array_buffer(PtrComprCageBase cage_base) const {
  Tagged<JSArrayBuffer> value = TaggedField<Tagged<JSArrayBuffer>>::load(cage_base, *this, kArrayBufferOffset);
  DCHECK(IsJSArrayBuffer(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=238&c=3
template<class D, class P>
void TorqueGeneratedWasmMemoryObject<D, P>::set_array_buffer(Tagged<JSArrayBuffer> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSArrayBuffer(value));
  WRITE_FIELD(*this, kArrayBufferOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kArrayBufferOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=239&c=3
template<class D, class P>
int TorqueGeneratedWasmMemoryObject<D, P>::maximum_pages() const {
  int value = TaggedField<Smi>::load(*this, kMaximumPagesOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=239&c=3
template<class D, class P>
void TorqueGeneratedWasmMemoryObject<D, P>::set_maximum_pages(int value) {
  WRITE_FIELD(*this, kMaximumPagesOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=240&c=3
template<class D, class P>
Tagged<WeakArrayList> TorqueGeneratedWasmMemoryObject<D, P>::instances() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmMemoryObject::instances(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=240&c=3
template<class D, class P>
Tagged<WeakArrayList> TorqueGeneratedWasmMemoryObject<D, P>::instances(PtrComprCageBase cage_base) const {
  Tagged<WeakArrayList> value = TaggedField<Tagged<WeakArrayList>>::load(cage_base, *this, kInstancesOffset);
  DCHECK(IsWeakArrayList(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=240&c=3
template<class D, class P>
void TorqueGeneratedWasmMemoryObject<D, P>::set_instances(Tagged<WeakArrayList> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsWeakArrayList(value));
  WRITE_FIELD(*this, kInstancesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kInstancesOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=241&c=3
template<class D, class P>
wasm::AddressType TorqueGeneratedWasmMemoryObject<D, P>::address_type() const {
  wasm::AddressType value = this->template ReadField<wasm::AddressType>(kAddressTypeOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=241&c=3
template<class D, class P>
void TorqueGeneratedWasmMemoryObject<D, P>::set_address_type(wasm::AddressType value) {
  this->template WriteField<wasm::AddressType>(kAddressTypeOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=243&c=3
template<class D, class P>
uint8_t TorqueGeneratedWasmMemoryObject<D, P>::padding_for_address_type_0() const {
  uint8_t value = this->template ReadField<uint8_t>(kPaddingForAddressType0Offset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=243&c=3
template<class D, class P>
void TorqueGeneratedWasmMemoryObject<D, P>::set_padding_for_address_type_0(uint8_t value) {
  this->template WriteField<uint8_t>(kPaddingForAddressType0Offset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=244&c=3
template<class D, class P>
uint16_t TorqueGeneratedWasmMemoryObject<D, P>::padding_for_address_type_1() const {
  uint16_t value = this->template ReadField<uint16_t>(kPaddingForAddressType1Offset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=244&c=3
template<class D, class P>
void TorqueGeneratedWasmMemoryObject<D, P>::set_padding_for_address_type_1(uint16_t value) {
  this->template WriteField<uint16_t>(kPaddingForAddressType1Offset, value);
}

template<class D, class P>
inline TorqueGeneratedWasmMemoryObject<D, P>::TorqueGeneratedWasmMemoryObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmMemoryObject_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=253&c=3
template<class D, class P>
Tagged<Union<JSArrayBuffer, Undefined>> TorqueGeneratedWasmGlobalObject<D, P>::untagged_buffer() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmGlobalObject::untagged_buffer(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=253&c=3
template<class D, class P>
Tagged<Union<JSArrayBuffer, Undefined>> TorqueGeneratedWasmGlobalObject<D, P>::untagged_buffer(PtrComprCageBase cage_base) const {
  Tagged<Union<JSArrayBuffer, Undefined>> value = TaggedField<Tagged<Union<JSArrayBuffer, Undefined>>>::load(cage_base, *this, kUntaggedBufferOffset);
  DCHECK(IsUndefined(value) || IsJSArrayBuffer(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=253&c=3
template<class D, class P>
void TorqueGeneratedWasmGlobalObject<D, P>::set_untagged_buffer(Tagged<Union<JSArrayBuffer, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSArrayBuffer(value));
  WRITE_FIELD(*this, kUntaggedBufferOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kUntaggedBufferOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=254&c=3
template<class D, class P>
Tagged<Union<FixedArray, Undefined>> TorqueGeneratedWasmGlobalObject<D, P>::tagged_buffer() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmGlobalObject::tagged_buffer(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=254&c=3
template<class D, class P>
Tagged<Union<FixedArray, Undefined>> TorqueGeneratedWasmGlobalObject<D, P>::tagged_buffer(PtrComprCageBase cage_base) const {
  Tagged<Union<FixedArray, Undefined>> value = TaggedField<Tagged<Union<FixedArray, Undefined>>>::load(cage_base, *this, kTaggedBufferOffset);
  DCHECK(IsUndefined(value) || IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=254&c=3
template<class D, class P>
void TorqueGeneratedWasmGlobalObject<D, P>::set_tagged_buffer(Tagged<Union<FixedArray, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsFixedArray(value));
  WRITE_FIELD(*this, kTaggedBufferOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kTaggedBufferOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=255&c=3
template<class D, class P>
int TorqueGeneratedWasmGlobalObject<D, P>::offset() const {
  int value = TaggedField<Smi>::load(*this, kOffsetOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=255&c=3
template<class D, class P>
void TorqueGeneratedWasmGlobalObject<D, P>::set_offset(int value) {
  WRITE_FIELD(*this, kOffsetOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=256&c=3
template<class D, class P>
int TorqueGeneratedWasmGlobalObject<D, P>::raw_type() const {
  int value = TaggedField<Smi>::load(*this, kRawTypeOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=256&c=3
template<class D, class P>
void TorqueGeneratedWasmGlobalObject<D, P>::set_raw_type(int value) {
  WRITE_FIELD(*this, kRawTypeOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=259&c=3
template<class D, class P>
int TorqueGeneratedWasmGlobalObject<D, P>::is_mutable() const {
  int value = TaggedField<Smi>::load(*this, kIsMutableOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=259&c=3
template<class D, class P>
void TorqueGeneratedWasmGlobalObject<D, P>::set_is_mutable(int value) {
  WRITE_FIELD(*this, kIsMutableOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedWasmGlobalObject<D, P>::TorqueGeneratedWasmGlobalObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmGlobalObject_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=263&c=3
template<class D, class P>
Tagged<PodArray<wasm::ValueType>> TorqueGeneratedWasmTagObject<D, P>::serialized_signature() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmTagObject::serialized_signature(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=263&c=3
template<class D, class P>
Tagged<PodArray<wasm::ValueType>> TorqueGeneratedWasmTagObject<D, P>::serialized_signature(PtrComprCageBase cage_base) const {
  Tagged<PodArray<wasm::ValueType>> value = TaggedField<Tagged<PodArray<wasm::ValueType>>>::load(cage_base, *this, kSerializedSignatureOffset);
  DCHECK(IsByteArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=263&c=3
template<class D, class P>
void TorqueGeneratedWasmTagObject<D, P>::set_serialized_signature(Tagged<PodArray<wasm::ValueType>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsByteArray(value));
  WRITE_FIELD(*this, kSerializedSignatureOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSerializedSignatureOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=264&c=3
template<class D, class P>
Tagged<HeapObject> TorqueGeneratedWasmTagObject<D, P>::tag() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmTagObject::tag(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=264&c=3
template<class D, class P>
Tagged<HeapObject> TorqueGeneratedWasmTagObject<D, P>::tag(PtrComprCageBase cage_base) const {
  Tagged<HeapObject> value = TaggedField<Tagged<HeapObject>>::load(cage_base, *this, kTagOffset);
  DCHECK(IsHeapObject(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=264&c=3
template<class D, class P>
void TorqueGeneratedWasmTagObject<D, P>::set_tag(Tagged<HeapObject> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value));
  WRITE_FIELD(*this, kTagOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kTagOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=265&c=3
template<class D, class P>
int TorqueGeneratedWasmTagObject<D, P>::canonical_type_index() const {
  int value = TaggedField<Smi>::load(*this, kCanonicalTypeIndexOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=265&c=3
template<class D, class P>
void TorqueGeneratedWasmTagObject<D, P>::set_canonical_type_index(int value) {
  WRITE_FIELD(*this, kCanonicalTypeIndexOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedWasmTagObject<D, P>::TorqueGeneratedWasmTagObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmTagObject_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=272&c=3
template<class D, class P>
Tagged<Managed<wasm::NativeModule>> TorqueGeneratedAsmWasmData<D, P>::managed_native_module() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedAsmWasmData::managed_native_module(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=272&c=3
template<class D, class P>
Tagged<Managed<wasm::NativeModule>> TorqueGeneratedAsmWasmData<D, P>::managed_native_module(PtrComprCageBase cage_base) const {
  Tagged<Managed<wasm::NativeModule>> value = TaggedField<Tagged<Managed<wasm::NativeModule>>>::load(cage_base, *this, kManagedNativeModuleOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=272&c=3
template<class D, class P>
void TorqueGeneratedAsmWasmData<D, P>::set_managed_native_module(Tagged<Managed<wasm::NativeModule>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kManagedNativeModuleOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kManagedNativeModuleOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=273&c=3
template<class D, class P>
Tagged<HeapNumber> TorqueGeneratedAsmWasmData<D, P>::uses_bitset() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedAsmWasmData::uses_bitset(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=273&c=3
template<class D, class P>
Tagged<HeapNumber> TorqueGeneratedAsmWasmData<D, P>::uses_bitset(PtrComprCageBase cage_base) const {
  Tagged<HeapNumber> value = TaggedField<Tagged<HeapNumber>>::load(cage_base, *this, kUsesBitsetOffset);
  DCHECK(IsHeapNumber(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=273&c=3
template<class D, class P>
void TorqueGeneratedAsmWasmData<D, P>::set_uses_bitset(Tagged<HeapNumber> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value));
  WRITE_FIELD(*this, kUsesBitsetOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kUsesBitsetOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedAsmWasmData<D, P>::TorqueGeneratedAsmWasmData(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsAsmWasmData_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=286&c=3
template<class D, class P>
uint32_t TorqueGeneratedWasmTypeInfo<D, P>::module_type_index() const {
  uint32_t value = this->template ReadField<uint32_t>(kModuleTypeIndexOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=286&c=3
template<class D, class P>
void TorqueGeneratedWasmTypeInfo<D, P>::set_module_type_index(uint32_t value) {
  this->template WriteField<uint32_t>(kModuleTypeIndexOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=291&c=9
template<class D, class P>
int TorqueGeneratedWasmTypeInfo<D, P>::supertypes_length() const {
  int value = TaggedField<Smi>::load(*this, kSupertypesLengthOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=291&c=9
template<class D, class P>
void TorqueGeneratedWasmTypeInfo<D, P>::set_supertypes_length(int value) {
  WRITE_FIELD(*this, kSupertypesLengthOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedWasmTypeInfo<D, P>::supertypes(int i) const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmTypeInfo::supertypes(cage_base, i);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedWasmTypeInfo<D, P>::supertypes(PtrComprCageBase cage_base, int i) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->supertypes_length());
  int offset = kSupertypesOffset + i * kTaggedSize;
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, offset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
template<class D, class P>
void TorqueGeneratedWasmTypeInfo<D, P>::set_supertypes(int i, Tagged<Object> value, WriteBarrierMode mode) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->supertypes_length());
  int offset = kSupertypesOffset + i * kTaggedSize;
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, offset, value);
  CONDITIONAL_WRITE_BARRIER(*this, offset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedWasmTypeInfo<D, P>::TorqueGeneratedWasmTypeInfo(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmTypeInfo_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedWasmObject<D, P>::TorqueGeneratedWasmObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmObject_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedWasmStruct<D, P>::TorqueGeneratedWasmStruct(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmStruct_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=307&c=3
template<class D, class P>
uint32_t TorqueGeneratedWasmArray<D, P>::length() const {
  uint32_t value = this->template ReadField<uint32_t>(kLengthOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=307&c=3
template<class D, class P>
void TorqueGeneratedWasmArray<D, P>::set_length(uint32_t value) {
  this->template WriteField<uint32_t>(kLengthOffset, value);
}

template<class D, class P>
inline TorqueGeneratedWasmArray<D, P>::TorqueGeneratedWasmArray(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmArray_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=327&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedWasmSuspendingObject<D, P>::callable() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmSuspendingObject::callable(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=327&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedWasmSuspendingObject<D, P>::callable(PtrComprCageBase cage_base) const {
  Tagged<JSReceiver> value = TaggedField<Tagged<JSReceiver>>::load(cage_base, *this, kCallableOffset);
  DCHECK(IsJSReceiver(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=327&c=3
template<class D, class P>
void TorqueGeneratedWasmSuspendingObject<D, P>::set_callable(Tagged<JSReceiver> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value));
  WRITE_FIELD(*this, kCallableOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCallableOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedWasmSuspendingObject<D, P>::TorqueGeneratedWasmSuspendingObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmSuspendingObject_NonInline(*this));
}
