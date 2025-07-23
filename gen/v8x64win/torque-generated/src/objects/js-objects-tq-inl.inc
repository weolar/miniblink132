// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=9&c=3
template<class D, class P>
Tagged<Union<FixedArrayBase, PropertyArray, Smi, SwissNameDictionary>> TorqueGeneratedJSReceiver<D, P>::properties_or_hash() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSReceiver::properties_or_hash(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=9&c=3
template<class D, class P>
Tagged<Union<FixedArrayBase, PropertyArray, Smi, SwissNameDictionary>> TorqueGeneratedJSReceiver<D, P>::properties_or_hash(PtrComprCageBase cage_base) const {
  Tagged<Union<FixedArrayBase, PropertyArray, Smi, SwissNameDictionary>> value = TaggedField<Tagged<Union<FixedArrayBase, PropertyArray, Smi, SwissNameDictionary>>>::load(cage_base, *this, kPropertiesOrHashOffset);
  DCHECK(IsSmi(value) || IsFixedArrayBase(value) || IsPropertyArray(value) || IsSwissNameDictionary(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=9&c=3
template<class D, class P>
void TorqueGeneratedJSReceiver<D, P>::set_properties_or_hash(Tagged<Union<FixedArrayBase, PropertyArray, Smi, SwissNameDictionary>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsSmi(value) || IsFixedArrayBase(value) || IsPropertyArray(value) || IsSwissNameDictionary(value));
  WRITE_FIELD(*this, kPropertiesOrHashOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kPropertiesOrHashOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSReceiver<D, P>::TorqueGeneratedJSReceiver(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSReceiver_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=33&c=3
template<class D, class P>
Tagged<FixedArrayBase> TorqueGeneratedJSObject<D, P>::elements() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSObject::elements(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=33&c=3
template<class D, class P>
Tagged<FixedArrayBase> TorqueGeneratedJSObject<D, P>::elements(PtrComprCageBase cage_base) const {
  Tagged<FixedArrayBase> value = TaggedField<Tagged<FixedArrayBase>>::load(cage_base, *this, kElementsOffset);
  DCHECK(IsFixedArrayBase(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=33&c=3
template<class D, class P>
void TorqueGeneratedJSObject<D, P>::set_elements(Tagged<FixedArrayBase> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArrayBase(value));
  WRITE_FIELD(*this, kElementsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kElementsOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSObject<D, P>::TorqueGeneratedJSObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSObject_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedJSObjectWithEmbedderSlots<D, P>::TorqueGeneratedJSObjectWithEmbedderSlots(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSObjectWithEmbedderSlots_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=56&c=3
template<class D, class P>
CppHeapPointer_t TorqueGeneratedJSAPIObjectWithEmbedderSlots<D, P>::cpp_heap_wrappable() const {
  CppHeapPointer_t value = this->template ReadField<CppHeapPointer_t>(kCppHeapWrappableOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=56&c=3
template<class D, class P>
void TorqueGeneratedJSAPIObjectWithEmbedderSlots<D, P>::set_cpp_heap_wrappable(CppHeapPointer_t value) {
  this->template WriteField<CppHeapPointer_t>(kCppHeapWrappableOffset, value);
}

template<class D, class P>
inline TorqueGeneratedJSAPIObjectWithEmbedderSlots<D, P>::TorqueGeneratedJSAPIObjectWithEmbedderSlots(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSAPIObjectWithEmbedderSlots_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedJSCustomElementsObject<D, P>::TorqueGeneratedJSCustomElementsObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSCustomElementsObject_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=70&c=3
template<class D, class P>
CppHeapPointer_t TorqueGeneratedJSSpecialObject<D, P>::cpp_heap_wrappable() const {
  CppHeapPointer_t value = this->template ReadField<CppHeapPointer_t>(kCppHeapWrappableOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=70&c=3
template<class D, class P>
void TorqueGeneratedJSSpecialObject<D, P>::set_cpp_heap_wrappable(CppHeapPointer_t value) {
  this->template WriteField<CppHeapPointer_t>(kCppHeapWrappableOffset, value);
}

template<class D, class P>
inline TorqueGeneratedJSSpecialObject<D, P>::TorqueGeneratedJSSpecialObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSSpecialObject_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedJSExternalObject<D, P>::TorqueGeneratedJSExternalObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSExternalObject_NonInline(*this));
}
template<class D, class P>
inline TorqueGeneratedJSGlobalProxy<D, P>::TorqueGeneratedJSGlobalProxy(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSGlobalProxy_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=120&c=3
template<class D, class P>
Tagged<JSGlobalProxy> TorqueGeneratedJSGlobalObject<D, P>::global_proxy() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSGlobalObject::global_proxy(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=120&c=3
template<class D, class P>
Tagged<JSGlobalProxy> TorqueGeneratedJSGlobalObject<D, P>::global_proxy(PtrComprCageBase cage_base) const {
  Tagged<JSGlobalProxy> value = TaggedField<Tagged<JSGlobalProxy>>::load(cage_base, *this, kGlobalProxyOffset);
  DCHECK(IsJSGlobalProxy(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=120&c=3
template<class D, class P>
void TorqueGeneratedJSGlobalObject<D, P>::set_global_proxy(Tagged<JSGlobalProxy> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSGlobalProxy(value));
  WRITE_FIELD(*this, kGlobalProxyOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kGlobalProxyOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSGlobalObject<D, P>::TorqueGeneratedJSGlobalObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSGlobalObject_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=124&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSPrimitiveWrapper<D, P>::value() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSPrimitiveWrapper::value(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=124&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSPrimitiveWrapper<D, P>::value(PtrComprCageBase cage_base) const {
  Tagged<JSAny> value = TaggedField<Tagged<JSAny>>::load(cage_base, *this, kValueOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=124&c=3
template<class D, class P>
void TorqueGeneratedJSPrimitiveWrapper<D, P>::set_value(Tagged<JSAny> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kValueOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kValueOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSPrimitiveWrapper<D, P>::TorqueGeneratedJSPrimitiveWrapper(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSPrimitiveWrapper_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=129&c=3
template<class D, class P>
int TorqueGeneratedJSMessageObject<D, P>::message_type() const {
  int value = TaggedField<Smi>::load(*this, kMessageTypeOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=129&c=3
template<class D, class P>
void TorqueGeneratedJSMessageObject<D, P>::set_message_type(int value) {
  WRITE_FIELD(*this, kMessageTypeOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=131&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedJSMessageObject<D, P>::argument() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSMessageObject::argument(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=131&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedJSMessageObject<D, P>::argument(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kArgumentOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=131&c=3
template<class D, class P>
void TorqueGeneratedJSMessageObject<D, P>::set_argument(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kArgumentOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kArgumentOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=133&c=3
template<class D, class P>
Tagged<Script> TorqueGeneratedJSMessageObject<D, P>::script() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSMessageObject::script(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=133&c=3
template<class D, class P>
Tagged<Script> TorqueGeneratedJSMessageObject<D, P>::script(PtrComprCageBase cage_base) const {
  Tagged<Script> value = TaggedField<Tagged<Script>>::load(cage_base, *this, kScriptOffset);
  DCHECK(IsScript(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=133&c=3
template<class D, class P>
void TorqueGeneratedJSMessageObject<D, P>::set_script(Tagged<Script> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsScript(value));
  WRITE_FIELD(*this, kScriptOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kScriptOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=135&c=3
template<class D, class P>
Tagged<Union<Hole, StackTraceInfo>> TorqueGeneratedJSMessageObject<D, P>::stack_trace() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSMessageObject::stack_trace(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=135&c=3
template<class D, class P>
Tagged<Union<Hole, StackTraceInfo>> TorqueGeneratedJSMessageObject<D, P>::stack_trace(PtrComprCageBase cage_base) const {
  Tagged<Union<Hole, StackTraceInfo>> value = TaggedField<Tagged<Union<Hole, StackTraceInfo>>>::load(cage_base, *this, kStackTraceOffset);
  DCHECK(IsTheHole(value) || IsStackTraceInfo(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=135&c=3
template<class D, class P>
void TorqueGeneratedJSMessageObject<D, P>::set_stack_trace(Tagged<Union<Hole, StackTraceInfo>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsTheHole(value) || IsStackTraceInfo(value));
  WRITE_FIELD(*this, kStackTraceOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kStackTraceOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=136&c=3
template<class D, class P>
Tagged<Union<SharedFunctionInfo, Smi>> TorqueGeneratedJSMessageObject<D, P>::shared_info() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSMessageObject::shared_info(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=136&c=3
template<class D, class P>
Tagged<Union<SharedFunctionInfo, Smi>> TorqueGeneratedJSMessageObject<D, P>::shared_info(PtrComprCageBase cage_base) const {
  Tagged<Union<SharedFunctionInfo, Smi>> value = TaggedField<Tagged<Union<SharedFunctionInfo, Smi>>>::load(cage_base, *this, kSharedInfoOffset);
  DCHECK(IsSmi(value) || IsSharedFunctionInfo(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=136&c=3
template<class D, class P>
void TorqueGeneratedJSMessageObject<D, P>::set_shared_info(Tagged<Union<SharedFunctionInfo, Smi>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsSmi(value) || IsSharedFunctionInfo(value));
  WRITE_FIELD(*this, kSharedInfoOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSharedInfoOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=140&c=3
template<class D, class P>
int TorqueGeneratedJSMessageObject<D, P>::bytecode_offset() const {
  int value = TaggedField<Smi>::load(*this, kBytecodeOffsetOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=140&c=3
template<class D, class P>
void TorqueGeneratedJSMessageObject<D, P>::set_bytecode_offset(int value) {
  WRITE_FIELD(*this, kBytecodeOffsetOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=141&c=3
template<class D, class P>
int TorqueGeneratedJSMessageObject<D, P>::start_position() const {
  int value = TaggedField<Smi>::load(*this, kStartPositionOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=141&c=3
template<class D, class P>
void TorqueGeneratedJSMessageObject<D, P>::set_start_position(int value) {
  WRITE_FIELD(*this, kStartPositionOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=142&c=3
template<class D, class P>
int TorqueGeneratedJSMessageObject<D, P>::end_position() const {
  int value = TaggedField<Smi>::load(*this, kEndPositionOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=142&c=3
template<class D, class P>
void TorqueGeneratedJSMessageObject<D, P>::set_end_position(int value) {
  WRITE_FIELD(*this, kEndPositionOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=143&c=3
template<class D, class P>
int TorqueGeneratedJSMessageObject<D, P>::error_level() const {
  int value = TaggedField<Smi>::load(*this, kErrorLevelOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=143&c=3
template<class D, class P>
void TorqueGeneratedJSMessageObject<D, P>::set_error_level(int value) {
  WRITE_FIELD(*this, kErrorLevelOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedJSMessageObject<D, P>::TorqueGeneratedJSMessageObject(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSMessageObject_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=150&c=3
template<class D, class P>
double TorqueGeneratedJSDate<D, P>::value() const {
  double value = this->template ReadField<double>(kValueOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=150&c=3
template<class D, class P>
void TorqueGeneratedJSDate<D, P>::set_value(double value) {
  this->template WriteField<double>(kValueOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=153&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::year() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDate::year(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=153&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::year(PtrComprCageBase cage_base) const {
  Tagged<Union<HeapNumber, Smi, Undefined>> value = TaggedField<Tagged<Union<HeapNumber, Smi, Undefined>>>::load(cage_base, *this, kYearOffset);
  DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=153&c=3
template<class D, class P>
void TorqueGeneratedJSDate<D, P>::set_year(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  WRITE_FIELD(*this, kYearOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kYearOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=154&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::month() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDate::month(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=154&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::month(PtrComprCageBase cage_base) const {
  Tagged<Union<HeapNumber, Smi, Undefined>> value = TaggedField<Tagged<Union<HeapNumber, Smi, Undefined>>>::load(cage_base, *this, kMonthOffset);
  DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=154&c=3
template<class D, class P>
void TorqueGeneratedJSDate<D, P>::set_month(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  WRITE_FIELD(*this, kMonthOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kMonthOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=155&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::day() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDate::day(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=155&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::day(PtrComprCageBase cage_base) const {
  Tagged<Union<HeapNumber, Smi, Undefined>> value = TaggedField<Tagged<Union<HeapNumber, Smi, Undefined>>>::load(cage_base, *this, kDayOffset);
  DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=155&c=3
template<class D, class P>
void TorqueGeneratedJSDate<D, P>::set_day(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  WRITE_FIELD(*this, kDayOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kDayOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=156&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::weekday() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDate::weekday(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=156&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::weekday(PtrComprCageBase cage_base) const {
  Tagged<Union<HeapNumber, Smi, Undefined>> value = TaggedField<Tagged<Union<HeapNumber, Smi, Undefined>>>::load(cage_base, *this, kWeekdayOffset);
  DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=156&c=3
template<class D, class P>
void TorqueGeneratedJSDate<D, P>::set_weekday(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  WRITE_FIELD(*this, kWeekdayOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kWeekdayOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=157&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::hour() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDate::hour(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=157&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::hour(PtrComprCageBase cage_base) const {
  Tagged<Union<HeapNumber, Smi, Undefined>> value = TaggedField<Tagged<Union<HeapNumber, Smi, Undefined>>>::load(cage_base, *this, kHourOffset);
  DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=157&c=3
template<class D, class P>
void TorqueGeneratedJSDate<D, P>::set_hour(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  WRITE_FIELD(*this, kHourOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kHourOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=158&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::min() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDate::min(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=158&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::min(PtrComprCageBase cage_base) const {
  Tagged<Union<HeapNumber, Smi, Undefined>> value = TaggedField<Tagged<Union<HeapNumber, Smi, Undefined>>>::load(cage_base, *this, kMinOffset);
  DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=158&c=3
template<class D, class P>
void TorqueGeneratedJSDate<D, P>::set_min(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  WRITE_FIELD(*this, kMinOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kMinOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=159&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::sec() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDate::sec(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=159&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::sec(PtrComprCageBase cage_base) const {
  Tagged<Union<HeapNumber, Smi, Undefined>> value = TaggedField<Tagged<Union<HeapNumber, Smi, Undefined>>>::load(cage_base, *this, kSecOffset);
  DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=159&c=3
template<class D, class P>
void TorqueGeneratedJSDate<D, P>::set_sec(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  WRITE_FIELD(*this, kSecOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSecOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=163&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::cache_stamp() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSDate::cache_stamp(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=163&c=3
template<class D, class P>
Tagged<Union<HeapNumber, Smi, Undefined>> TorqueGeneratedJSDate<D, P>::cache_stamp(PtrComprCageBase cage_base) const {
  Tagged<Union<HeapNumber, Smi, Undefined>> value = TaggedField<Tagged<Union<HeapNumber, Smi, Undefined>>>::load(cage_base, *this, kCacheStampOffset);
  DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=163&c=3
template<class D, class P>
void TorqueGeneratedJSDate<D, P>::set_cache_stamp(Tagged<Union<HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsSmi(value) || IsNaN(value));
  WRITE_FIELD(*this, kCacheStampOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCacheStampOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSDate<D, P>::TorqueGeneratedJSDate(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSDate_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=167&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSAsyncFromSyncIterator<D, P>::sync_iterator() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSAsyncFromSyncIterator::sync_iterator(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=167&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSAsyncFromSyncIterator<D, P>::sync_iterator(PtrComprCageBase cage_base) const {
  Tagged<JSReceiver> value = TaggedField<Tagged<JSReceiver>>::load(cage_base, *this, kSyncIteratorOffset);
  DCHECK(IsJSReceiver(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=167&c=3
template<class D, class P>
void TorqueGeneratedJSAsyncFromSyncIterator<D, P>::set_sync_iterator(Tagged<JSReceiver> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value));
  WRITE_FIELD(*this, kSyncIteratorOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSyncIteratorOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=170&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedJSAsyncFromSyncIterator<D, P>::next() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSAsyncFromSyncIterator::next(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=170&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedJSAsyncFromSyncIterator<D, P>::next(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kNextOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=170&c=3
template<class D, class P>
void TorqueGeneratedJSAsyncFromSyncIterator<D, P>::set_next(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kNextOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNextOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSAsyncFromSyncIterator<D, P>::TorqueGeneratedJSAsyncFromSyncIterator(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSAsyncFromSyncIterator_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=175&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSStringIterator<D, P>::string() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSStringIterator::string(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=175&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedJSStringIterator<D, P>::string(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kStringOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=175&c=3
template<class D, class P>
void TorqueGeneratedJSStringIterator<D, P>::set_string(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kStringOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kStringOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=177&c=3
template<class D, class P>
int TorqueGeneratedJSStringIterator<D, P>::index() const {
  int value = TaggedField<Smi>::load(*this, kIndexOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=177&c=3
template<class D, class P>
void TorqueGeneratedJSStringIterator<D, P>::set_index(int value) {
  WRITE_FIELD(*this, kIndexOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedJSStringIterator<D, P>::TorqueGeneratedJSStringIterator(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSStringIterator_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=184&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSValidIteratorWrapper<D, P>::underlying_object() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSValidIteratorWrapper::underlying_object(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=184&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedJSValidIteratorWrapper<D, P>::underlying_object(PtrComprCageBase cage_base) const {
  Tagged<JSReceiver> value = TaggedField<Tagged<JSReceiver>>::load(cage_base, *this, kUnderlyingOffset + 0);
  DCHECK(IsJSReceiver(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=184&c=3
template<class D, class P>
void TorqueGeneratedJSValidIteratorWrapper<D, P>::set_underlying_object(Tagged<JSReceiver> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value));
  WRITE_FIELD(*this, kUnderlyingOffset + 0, value);
  CONDITIONAL_WRITE_BARRIER(*this, kUnderlyingOffset + 0, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=184&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSValidIteratorWrapper<D, P>::underlying_next() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSValidIteratorWrapper::underlying_next(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=184&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedJSValidIteratorWrapper<D, P>::underlying_next(PtrComprCageBase cage_base) const {
  Tagged<JSAny> value = TaggedField<Tagged<JSAny>>::load(cage_base, *this, kUnderlyingOffset + 4);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-objects.tq?l=184&c=3
template<class D, class P>
void TorqueGeneratedJSValidIteratorWrapper<D, P>::set_underlying_next(Tagged<JSAny> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kUnderlyingOffset + 4, value);
  CONDITIONAL_WRITE_BARRIER(*this, kUnderlyingOffset + 4, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSValidIteratorWrapper<D, P>::TorqueGeneratedJSValidIteratorWrapper(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSValidIteratorWrapper_NonInline(*this));
}
