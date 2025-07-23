// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=6&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedSyntheticModule<D, P>::name() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSyntheticModule::name(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=6&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedSyntheticModule<D, P>::name(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kNameOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=6&c=3
template<class D, class P>
void TorqueGeneratedSyntheticModule<D, P>::set_name(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kNameOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNameOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=7&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedSyntheticModule<D, P>::export_names() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSyntheticModule::export_names(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=7&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedSyntheticModule<D, P>::export_names(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kExportNamesOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=7&c=3
template<class D, class P>
void TorqueGeneratedSyntheticModule<D, P>::set_export_names(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kExportNamesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kExportNamesOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=8&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedSyntheticModule<D, P>::evaluation_steps() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSyntheticModule::evaluation_steps(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=8&c=3
template<class D, class P>
Tagged<Foreign> TorqueGeneratedSyntheticModule<D, P>::evaluation_steps(PtrComprCageBase cage_base) const {
  Tagged<Foreign> value = TaggedField<Tagged<Foreign>>::load(cage_base, *this, kEvaluationStepsOffset);
  DCHECK(IsForeign(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=8&c=3
template<class D, class P>
void TorqueGeneratedSyntheticModule<D, P>::set_evaluation_steps(Tagged<Foreign> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsForeign(value));
  WRITE_FIELD(*this, kEvaluationStepsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kEvaluationStepsOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedSyntheticModule<D, P>::TorqueGeneratedSyntheticModule(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsSyntheticModule_NonInline(*this));
}
