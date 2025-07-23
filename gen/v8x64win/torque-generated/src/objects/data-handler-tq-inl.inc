// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=13&c=3
template<class D, class P>
Tagged<Union<Code, Smi>> TorqueGeneratedDataHandler<D, P>::smi_handler() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedDataHandler::smi_handler(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=13&c=3
template<class D, class P>
Tagged<Union<Code, Smi>> TorqueGeneratedDataHandler<D, P>::smi_handler(PtrComprCageBase cage_base) const {
  Tagged<Union<Code, Smi>> value = TaggedField<Tagged<Union<Code, Smi>>>::load(cage_base, *this, kSmiHandlerOffset);
  DCHECK(IsSmi(value) || IsCode(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=13&c=3
template<class D, class P>
void TorqueGeneratedDataHandler<D, P>::set_smi_handler(Tagged<Union<Code, Smi>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsSmi(value) || IsCode(value));
  WRITE_FIELD(*this, kSmiHandlerOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSmiHandlerOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=16&c=3
template<class D, class P>
Tagged<Union<Cell, Smi>> TorqueGeneratedDataHandler<D, P>::validity_cell() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedDataHandler::validity_cell(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=16&c=3
template<class D, class P>
Tagged<Union<Cell, Smi>> TorqueGeneratedDataHandler<D, P>::validity_cell(PtrComprCageBase cage_base) const {
  Tagged<Union<Cell, Smi>> value = TaggedField<Tagged<Union<Cell, Smi>>>::load(cage_base, *this, kValidityCellOffset);
  DCHECK(IsSmi(value) || IsCell(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=16&c=3
template<class D, class P>
void TorqueGeneratedDataHandler<D, P>::set_validity_cell(Tagged<Union<Cell, Smi>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsSmi(value) || IsCell(value));
  WRITE_FIELD(*this, kValidityCellOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kValidityCellOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=19&c=3
template<class D, class P>
Tagged<Union<HeapObject, MaybeObject, Smi>> TorqueGeneratedDataHandler<D, P>::data1() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedDataHandler::data1(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=19&c=3
template<class D, class P>
Tagged<Union<HeapObject, MaybeObject, Smi>> TorqueGeneratedDataHandler<D, P>::data1(PtrComprCageBase cage_base) const {
  Tagged<Union<HeapObject, MaybeObject, Smi>> value = TaggedField<Tagged<Union<HeapObject, MaybeObject, Smi>>>::load(cage_base, *this, kData1Offset);
  DCHECK(value.IsCleared() || (!value.IsWeak() && IsHeapObject(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSmi(value.GetHeapObjectOrSmi())) || value.IsWeak());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=19&c=3
template<class D, class P>
void TorqueGeneratedDataHandler<D, P>::set_data1(Tagged<Union<HeapObject, MaybeObject, Smi>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsCleared() || (!value.IsWeak() && IsHeapObject(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSmi(value.GetHeapObjectOrSmi())) || value.IsWeak());
  RELAXED_WRITE_WEAK_FIELD(*this, kData1Offset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kData1Offset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=20&c=3
template<class D, class P>
Tagged<Union<HeapObject, MaybeObject, Smi>> TorqueGeneratedDataHandler<D, P>::data2() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedDataHandler::data2(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=20&c=3
template<class D, class P>
Tagged<Union<HeapObject, MaybeObject, Smi>> TorqueGeneratedDataHandler<D, P>::data2(PtrComprCageBase cage_base) const {
  Tagged<Union<HeapObject, MaybeObject, Smi>> value = TaggedField<Tagged<Union<HeapObject, MaybeObject, Smi>>>::load(cage_base, *this, kData2Offset);
  DCHECK(value.IsCleared() || (!value.IsWeak() && IsHeapObject(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSmi(value.GetHeapObjectOrSmi())) || value.IsWeak());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=20&c=3
template<class D, class P>
void TorqueGeneratedDataHandler<D, P>::set_data2(Tagged<Union<HeapObject, MaybeObject, Smi>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsCleared() || (!value.IsWeak() && IsHeapObject(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSmi(value.GetHeapObjectOrSmi())) || value.IsWeak());
  RELAXED_WRITE_WEAK_FIELD(*this, kData2Offset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kData2Offset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=21&c=3
template<class D, class P>
Tagged<Union<HeapObject, MaybeObject, Smi>> TorqueGeneratedDataHandler<D, P>::data3() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedDataHandler::data3(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=21&c=3
template<class D, class P>
Tagged<Union<HeapObject, MaybeObject, Smi>> TorqueGeneratedDataHandler<D, P>::data3(PtrComprCageBase cage_base) const {
  Tagged<Union<HeapObject, MaybeObject, Smi>> value = TaggedField<Tagged<Union<HeapObject, MaybeObject, Smi>>>::load(cage_base, *this, kData3Offset);
  DCHECK(value.IsCleared() || (!value.IsWeak() && IsHeapObject(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSmi(value.GetHeapObjectOrSmi())) || value.IsWeak());
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/data-handler.tq?l=21&c=3
template<class D, class P>
void TorqueGeneratedDataHandler<D, P>::set_data3(Tagged<Union<HeapObject, MaybeObject, Smi>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(value.IsCleared() || (!value.IsWeak() && IsHeapObject(value.GetHeapObjectOrSmi())) || (!value.IsWeak() && IsSmi(value.GetHeapObjectOrSmi())) || value.IsWeak());
  RELAXED_WRITE_WEAK_FIELD(*this, kData3Offset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kData3Offset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedDataHandler<D, P>::TorqueGeneratedDataHandler(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsDataHandler_NonInline(*this));
}
