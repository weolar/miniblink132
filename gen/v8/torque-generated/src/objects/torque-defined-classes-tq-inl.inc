template<class D, class P>
inline TorqueGeneratedStrongDescriptorArray<D, P>::TorqueGeneratedStrongDescriptorArray(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsStrongDescriptorArray_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(StrongDescriptorArray)
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=765&c=3
template<class D, class P>
int TorqueGeneratedInternalClass<D, P>::a() const {
  int value = TaggedField<Smi>::load(*this, kAOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=765&c=3
template<class D, class P>
void TorqueGeneratedInternalClass<D, P>::set_a(int value) {
  WRITE_FIELD(*this, kAOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=766&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedInternalClass<D, P>::b() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedInternalClass::b(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=766&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedInternalClass<D, P>::b(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kBOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=766&c=3
template<class D, class P>
void TorqueGeneratedInternalClass<D, P>::set_b(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kBOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedInternalClass<D, P>::TorqueGeneratedInternalClass(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsInternalClass_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(InternalClass)
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=829&c=3
template<class D, class P>
int TorqueGeneratedSmiPair<D, P>::a() const {
  int value = TaggedField<Smi>::load(*this, kAOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=829&c=3
template<class D, class P>
void TorqueGeneratedSmiPair<D, P>::set_a(int value) {
  WRITE_FIELD(*this, kAOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=830&c=3
template<class D, class P>
int TorqueGeneratedSmiPair<D, P>::b() const {
  int value = TaggedField<Smi>::load(*this, kBOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=830&c=3
template<class D, class P>
void TorqueGeneratedSmiPair<D, P>::set_b(int value) {
  WRITE_FIELD(*this, kBOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedSmiPair<D, P>::TorqueGeneratedSmiPair(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsSmiPair_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(SmiPair)
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=927&c=3
template<class D, class P>
int TorqueGeneratedSmiBox<D, P>::value() const {
  int value = TaggedField<Smi>::load(*this, kValueOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=927&c=3
template<class D, class P>
void TorqueGeneratedSmiBox<D, P>::set_value(int value) {
  WRITE_FIELD(*this, kValueOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=928&c=3
template<class D, class P>
int TorqueGeneratedSmiBox<D, P>::unrelated() const {
  int value = TaggedField<Smi>::load(*this, kUnrelatedOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=928&c=3
template<class D, class P>
void TorqueGeneratedSmiBox<D, P>::set_unrelated(int value) {
  WRITE_FIELD(*this, kUnrelatedOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedSmiBox<D, P>::TorqueGeneratedSmiBox(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsSmiBox_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(SmiBox)
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1179&c=3
template<class D, class P>
Tagged<HeapObject> TorqueGeneratedExportedSubClassBase<D, P>::a() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedExportedSubClassBase::a(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1179&c=3
template<class D, class P>
Tagged<HeapObject> TorqueGeneratedExportedSubClassBase<D, P>::a(PtrComprCageBase cage_base) const {
  Tagged<HeapObject> value = TaggedField<Tagged<HeapObject>>::load(cage_base, *this, kAOffset);
  DCHECK(IsHeapObject(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1179&c=3
template<class D, class P>
void TorqueGeneratedExportedSubClassBase<D, P>::set_a(Tagged<HeapObject> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value));
  WRITE_FIELD(*this, kAOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kAOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1180&c=3
template<class D, class P>
Tagged<HeapObject> TorqueGeneratedExportedSubClassBase<D, P>::b() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedExportedSubClassBase::b(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1180&c=3
template<class D, class P>
Tagged<HeapObject> TorqueGeneratedExportedSubClassBase<D, P>::b(PtrComprCageBase cage_base) const {
  Tagged<HeapObject> value = TaggedField<Tagged<HeapObject>>::load(cage_base, *this, kBOffset);
  DCHECK(IsHeapObject(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1180&c=3
template<class D, class P>
void TorqueGeneratedExportedSubClassBase<D, P>::set_b(Tagged<HeapObject> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value));
  WRITE_FIELD(*this, kBOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kBOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedExportedSubClassBase<D, P>::TorqueGeneratedExportedSubClassBase(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsExportedSubClassBase_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(ExportedSubClassBase)
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1172&c=3
template<class D, class P>
int32_t TorqueGeneratedExportedSubClass<D, P>::c_field() const {
  int32_t value = this->template ReadField<int32_t>(kCFieldOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1172&c=3
template<class D, class P>
void TorqueGeneratedExportedSubClass<D, P>::set_c_field(int32_t value) {
  this->template WriteField<int32_t>(kCFieldOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1173&c=3
template<class D, class P>
int32_t TorqueGeneratedExportedSubClass<D, P>::d_field() const {
  int32_t value = this->template ReadField<int32_t>(kDFieldOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1173&c=3
template<class D, class P>
void TorqueGeneratedExportedSubClass<D, P>::set_d_field(int32_t value) {
  this->template WriteField<int32_t>(kDFieldOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1174&c=3
template<class D, class P>
int TorqueGeneratedExportedSubClass<D, P>::e_field() const {
  int value = TaggedField<Smi>::load(*this, kEFieldOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1174&c=3
template<class D, class P>
void TorqueGeneratedExportedSubClass<D, P>::set_e_field(int value) {
  WRITE_FIELD(*this, kEFieldOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedExportedSubClass<D, P>::TorqueGeneratedExportedSubClass(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsExportedSubClass_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(ExportedSubClass)
template<class D, class P>
inline TorqueGeneratedAbstractInternalClass<D, P>::TorqueGeneratedAbstractInternalClass(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsAbstractInternalClass_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(AbstractInternalClass)
template<class D, class P>
inline TorqueGeneratedAbstractInternalClassSubclass1<D, P>::TorqueGeneratedAbstractInternalClassSubclass1(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsAbstractInternalClassSubclass1_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(AbstractInternalClassSubclass1)
template<class D, class P>
inline TorqueGeneratedAbstractInternalClassSubclass2<D, P>::TorqueGeneratedAbstractInternalClassSubclass2(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsAbstractInternalClassSubclass2_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(AbstractInternalClassSubclass2)
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1196&c=3
template<class D, class P>
int32_t TorqueGeneratedInternalClassWithStructElements<D, P>::dummy1() const {
  int32_t value = this->template ReadField<int32_t>(kDummy1Offset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1196&c=3
template<class D, class P>
void TorqueGeneratedInternalClassWithStructElements<D, P>::set_dummy1(int32_t value) {
  this->template WriteField<int32_t>(kDummy1Offset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1197&c=3
template<class D, class P>
int32_t TorqueGeneratedInternalClassWithStructElements<D, P>::dummy2() const {
  int32_t value = this->template ReadField<int32_t>(kDummy2Offset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1197&c=3
template<class D, class P>
void TorqueGeneratedInternalClassWithStructElements<D, P>::set_dummy2(int32_t value) {
  this->template WriteField<int32_t>(kDummy2Offset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1198&c=9
template<class D, class P>
int TorqueGeneratedInternalClassWithStructElements<D, P>::count() const {
  int value = TaggedField<Smi>::load(*this, kCountOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1198&c=9
template<class D, class P>
void TorqueGeneratedInternalClassWithStructElements<D, P>::set_count(int value) {
  WRITE_FIELD(*this, kCountOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1199&c=3
template<class D, class P>
int TorqueGeneratedInternalClassWithStructElements<D, P>::data() const {
  int value = TaggedField<Smi>::load(*this, kDataOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1199&c=3
template<class D, class P>
void TorqueGeneratedInternalClassWithStructElements<D, P>::set_data(int value) {
  WRITE_FIELD(*this, kDataOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1200&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedInternalClassWithStructElements<D, P>::object() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedInternalClassWithStructElements::object(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1200&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedInternalClassWithStructElements<D, P>::object(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kObjectOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1200&c=3
template<class D, class P>
void TorqueGeneratedInternalClassWithStructElements<D, P>::set_object(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kObjectOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kObjectOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1201&c=3
template<class D, class P>
int TorqueGeneratedInternalClassWithStructElements<D, P>::entries(int i) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->count());
  int offset = kEntriesOffset + i * kTaggedSize;
  int value = TaggedField<Smi>::load(*this, offset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1201&c=3
template<class D, class P>
void TorqueGeneratedInternalClassWithStructElements<D, P>::set_entries(int i, int value) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->count());
  int offset = kEntriesOffset + i * kTaggedSize;
  WRITE_FIELD(*this, offset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1202&c=3
template<class D, class P>
int TorqueGeneratedInternalClassWithStructElements<D, P>::more_entries_a(int i) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->count());
  int offset = MoreEntriesOffset() + 0 + i * 8;
  int value = TaggedField<Smi>::load(*this, offset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1202&c=3
template<class D, class P>
void TorqueGeneratedInternalClassWithStructElements<D, P>::set_more_entries_a(int i, int value) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->count());
  int offset = MoreEntriesOffset() + 0 + i * 8;
  WRITE_FIELD(*this, offset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1202&c=3
template<class D, class P>
int TorqueGeneratedInternalClassWithStructElements<D, P>::more_entries_b(int i) const {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->count());
  int offset = MoreEntriesOffset() + 4 + i * 8;
  int value = TaggedField<Smi>::load(*this, offset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1202&c=3
template<class D, class P>
void TorqueGeneratedInternalClassWithStructElements<D, P>::set_more_entries_b(int i, int value) {
  DCHECK_GE(i, 0);
  DCHECK_LT(i, this ->count());
  int offset = MoreEntriesOffset() + 4 + i * 8;
  WRITE_FIELD(*this, offset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1202&c=3
template<class D, class P>
int TorqueGeneratedInternalClassWithStructElements<D, P>::MoreEntriesOffset() const {
  return static_cast<int>(std::get<1>(TqRuntimeFieldSliceInternalClassWithStructElementsMoreEntries(*static_cast<const D*>(this))));
}

template<class D, class P>
inline TorqueGeneratedInternalClassWithStructElements<D, P>::TorqueGeneratedInternalClassWithStructElements(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsInternalClassWithStructElements_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(InternalClassWithStructElements)
// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1214&c=3
template<class D, class P>
int32_t TorqueGeneratedExportedSubClass2<D, P>::x_field() const {
  int32_t value = this->template ReadField<int32_t>(kXFieldOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1214&c=3
template<class D, class P>
void TorqueGeneratedExportedSubClass2<D, P>::set_x_field(int32_t value) {
  this->template WriteField<int32_t>(kXFieldOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1215&c=3
template<class D, class P>
int32_t TorqueGeneratedExportedSubClass2<D, P>::y_field() const {
  int32_t value = this->template ReadField<int32_t>(kYFieldOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1215&c=3
template<class D, class P>
void TorqueGeneratedExportedSubClass2<D, P>::set_y_field(int32_t value) {
  this->template WriteField<int32_t>(kYFieldOffset, value);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1216&c=3
template<class D, class P>
int TorqueGeneratedExportedSubClass2<D, P>::z_field() const {
  int value = TaggedField<Smi>::load(*this, kZFieldOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/test/torque/test-torque.tq?l=1216&c=3
template<class D, class P>
void TorqueGeneratedExportedSubClass2<D, P>::set_z_field(int value) {
  WRITE_FIELD(*this, kZFieldOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedExportedSubClass2<D, P>::TorqueGeneratedExportedSubClass2(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsExportedSubClass2_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(ExportedSubClass2)
// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=47&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedSortState<D, P>::receiver() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSortState::receiver(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=47&c=3
template<class D, class P>
Tagged<JSReceiver> TorqueGeneratedSortState<D, P>::receiver(PtrComprCageBase cage_base) const {
  Tagged<JSReceiver> value = TaggedField<Tagged<JSReceiver>>::load(cage_base, *this, kReceiverOffset);
  DCHECK(IsJSReceiver(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=47&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_receiver(Tagged<JSReceiver> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value));
  WRITE_FIELD(*this, kReceiverOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kReceiverOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=52&c=3
template<class D, class P>
Tagged<Map> TorqueGeneratedSortState<D, P>::initialReceiverMap() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSortState::initialReceiverMap(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=52&c=3
template<class D, class P>
Tagged<Map> TorqueGeneratedSortState<D, P>::initialReceiverMap(PtrComprCageBase cage_base) const {
  Tagged<Map> value = TaggedField<Tagged<Map>>::load(cage_base, *this, kInitialReceiverMapOffset);
  DCHECK(IsMap(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=52&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_initialReceiverMap(Tagged<Map> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsMap(value));
  WRITE_FIELD(*this, kInitialReceiverMapOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kInitialReceiverMapOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=53&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedSortState<D, P>::initialReceiverLength() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSortState::initialReceiverLength(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=53&c=3
template<class D, class P>
Tagged<Number> TorqueGeneratedSortState<D, P>::initialReceiverLength(PtrComprCageBase cage_base) const {
  Tagged<Number> value = TaggedField<Tagged<Number>>::load(cage_base, *this, kInitialReceiverLengthOffset);
  DCHECK(IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=53&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_initialReceiverLength(Tagged<Number> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kInitialReceiverLengthOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kInitialReceiverLengthOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=56&c=3
template<class D, class P>
Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> TorqueGeneratedSortState<D, P>::userCmpFn() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSortState::userCmpFn(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=56&c=3
template<class D, class P>
Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> TorqueGeneratedSortState<D, P>::userCmpFn(PtrComprCageBase cage_base) const {
  Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> value = TaggedField<Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>>>::load(cage_base, *this, kUserCmpFnOffset);
  DCHECK(IsUndefined(value) || IsJSFunction(value) || IsCallableApiObject(value) || IsCallableJSProxy(value) || IsJSWrappedFunction(value) || IsJSBoundFunction(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=56&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_userCmpFn(Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSFunction(value) || IsCallableApiObject(value) || IsCallableJSProxy(value) || IsJSWrappedFunction(value) || IsJSBoundFunction(value));
  WRITE_FIELD(*this, kUserCmpFnOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kUserCmpFnOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=61&c=3
template<class D, class P>
int TorqueGeneratedSortState<D, P>::sortComparePtr() const {
  int value = TaggedField<Smi>::load(*this, kSortComparePtrOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=61&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_sortComparePtr(int value) {
  WRITE_FIELD(*this, kSortComparePtrOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=66&c=3
template<class D, class P>
int TorqueGeneratedSortState<D, P>::loadFn() const {
  int value = TaggedField<Smi>::load(*this, kLoadFnOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=66&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_loadFn(int value) {
  WRITE_FIELD(*this, kLoadFnOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=67&c=3
template<class D, class P>
int TorqueGeneratedSortState<D, P>::storeFn() const {
  int value = TaggedField<Smi>::load(*this, kStoreFnOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=67&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_storeFn(int value) {
  WRITE_FIELD(*this, kStoreFnOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=68&c=3
template<class D, class P>
int TorqueGeneratedSortState<D, P>::deleteFn() const {
  int value = TaggedField<Smi>::load(*this, kDeleteFnOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=68&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_deleteFn(int value) {
  WRITE_FIELD(*this, kDeleteFnOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=69&c=3
template<class D, class P>
int TorqueGeneratedSortState<D, P>::canUseSameAccessorFn() const {
  int value = TaggedField<Smi>::load(*this, kCanUseSameAccessorFnOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=69&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_canUseSameAccessorFn(int value) {
  WRITE_FIELD(*this, kCanUseSameAccessorFnOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=74&c=3
template<class D, class P>
int TorqueGeneratedSortState<D, P>::minGallop() const {
  int value = TaggedField<Smi>::load(*this, kMinGallopOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=74&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_minGallop(int value) {
  WRITE_FIELD(*this, kMinGallopOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=86&c=3
template<class D, class P>
int TorqueGeneratedSortState<D, P>::pendingRunsSize() const {
  int value = TaggedField<Smi>::load(*this, kPendingRunsSizeOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=86&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_pendingRunsSize(int value) {
  WRITE_FIELD(*this, kPendingRunsSizeOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=87&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedSortState<D, P>::pendingRuns() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSortState::pendingRuns(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=87&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedSortState<D, P>::pendingRuns(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kPendingRunsOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=87&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_pendingRuns(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kPendingRunsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kPendingRunsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=92&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedSortState<D, P>::workArray() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSortState::workArray(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=92&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedSortState<D, P>::workArray(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kWorkArrayOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=92&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_workArray(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kWorkArrayOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kWorkArrayOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=95&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedSortState<D, P>::tempArray() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSortState::tempArray(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=95&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedSortState<D, P>::tempArray(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kTempArrayOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=95&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_tempArray(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kTempArrayOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kTempArrayOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=98&c=3
template<class D, class P>
int TorqueGeneratedSortState<D, P>::sortLength() const {
  int value = TaggedField<Smi>::load(*this, kSortLengthOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=98&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_sortLength(int value) {
  WRITE_FIELD(*this, kSortLengthOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=102&c=3
template<class D, class P>
int TorqueGeneratedSortState<D, P>::numberOfUndefined() const {
  int value = TaggedField<Smi>::load(*this, kNumberOfUndefinedOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/third_party/v8/builtins/array-sort.tq?l=102&c=3
template<class D, class P>
void TorqueGeneratedSortState<D, P>::set_numberOfUndefined(int value) {
  WRITE_FIELD(*this, kNumberOfUndefinedOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedSortState<D, P>::TorqueGeneratedSortState(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsSortState_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(SortState)
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=67&c=3
template<class D, class P>
Tagged<HeapObject> TorqueGeneratedWasmFastApiCallData<D, P>::signature() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmFastApiCallData::signature(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=67&c=3
template<class D, class P>
Tagged<HeapObject> TorqueGeneratedWasmFastApiCallData<D, P>::signature(PtrComprCageBase cage_base) const {
  Tagged<HeapObject> value = TaggedField<Tagged<HeapObject>>::load(cage_base, *this, kSignatureOffset);
  DCHECK(IsHeapObject(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=67&c=3
template<class D, class P>
void TorqueGeneratedWasmFastApiCallData<D, P>::set_signature(Tagged<HeapObject> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value));
  WRITE_FIELD(*this, kSignatureOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSignatureOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=68&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedWasmFastApiCallData<D, P>::callback_data() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmFastApiCallData::callback_data(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=68&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedWasmFastApiCallData<D, P>::callback_data(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kCallbackDataOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=68&c=3
template<class D, class P>
void TorqueGeneratedWasmFastApiCallData<D, P>::set_callback_data(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kCallbackDataOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCallbackDataOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=69&c=3
template<class D, class P>
Tagged<Union<MaybeObject, Null>> TorqueGeneratedWasmFastApiCallData<D, P>::cached_map() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmFastApiCallData::cached_map(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=69&c=3
template<class D, class P>
Tagged<Union<MaybeObject, Null>> TorqueGeneratedWasmFastApiCallData<D, P>::cached_map(PtrComprCageBase cage_base) const {
  Tagged<Union<MaybeObject, Null>> value = TaggedField<Tagged<Union<MaybeObject, Null>>>::load(cage_base, *this, kCachedMapOffset);
  DCHECK(value.IsCleared() || (!value.IsWeak() && IsNull(value.GetHeapObjectOrSmi())) || (value.IsWeak() && IsMap(value.GetHeapObjectOrSmi())));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=69&c=3
template<class D, class P>
void TorqueGeneratedWasmFastApiCallData<D, P>::set_cached_map(Tagged<Union<MaybeObject, Null>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsCleared() || (!value.IsWeak() && IsNull(value.GetHeapObjectOrSmi())) || (value.IsWeak() && IsMap(value.GetHeapObjectOrSmi())));
  RELAXED_WRITE_WEAK_FIELD(*this, kCachedMapOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCachedMapOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedWasmFastApiCallData<D, P>::TorqueGeneratedWasmFastApiCallData(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmFastApiCallData_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(WasmFastApiCallData)
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=314&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedWasmStringViewIter<D, P>::string() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWasmStringViewIter::string(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=314&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedWasmStringViewIter<D, P>::string(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kStringOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=314&c=3
template<class D, class P>
void TorqueGeneratedWasmStringViewIter<D, P>::set_string(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kStringOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kStringOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=315&c=3
template<class D, class P>
uint32_t TorqueGeneratedWasmStringViewIter<D, P>::offset() const {
  uint32_t value = this->template ReadField<uint32_t>(kOffsetOffset);
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=315&c=3
template<class D, class P>
void TorqueGeneratedWasmStringViewIter<D, P>::set_offset(uint32_t value) {
  this->template WriteField<uint32_t>(kOffsetOffset, value);
}

template<class D, class P>
inline TorqueGeneratedWasmStringViewIter<D, P>::TorqueGeneratedWasmStringViewIter(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWasmStringViewIter_NonInline(*this));
}
TQ_OBJECT_CONSTRUCTORS_IMPL(WasmStringViewIter)
