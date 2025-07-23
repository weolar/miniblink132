// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=23&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedCallSiteInfo<D, P>::receiver_or_instance() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedCallSiteInfo::receiver_or_instance(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=23&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedCallSiteInfo<D, P>::receiver_or_instance(PtrComprCageBase cage_base) const {
  Tagged<JSAny> value = TaggedField<Tagged<JSAny>>::load(cage_base, *this, kReceiverOrInstanceOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=23&c=3
template<class D, class P>
void TorqueGeneratedCallSiteInfo<D, P>::set_receiver_or_instance(Tagged<JSAny> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kReceiverOrInstanceOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kReceiverOrInstanceOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=24&c=3
template<class D, class P>
Tagged<Union<JSFunction, Smi>> TorqueGeneratedCallSiteInfo<D, P>::function() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedCallSiteInfo::function(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=24&c=3
template<class D, class P>
Tagged<Union<JSFunction, Smi>> TorqueGeneratedCallSiteInfo<D, P>::function(PtrComprCageBase cage_base) const {
  Tagged<Union<JSFunction, Smi>> value = TaggedField<Tagged<Union<JSFunction, Smi>>>::load(cage_base, *this, kFunctionOffset);
  DCHECK(IsSmi(value) || IsJSFunction(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=24&c=3
template<class D, class P>
void TorqueGeneratedCallSiteInfo<D, P>::set_function(Tagged<Union<JSFunction, Smi>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsSmi(value) || IsJSFunction(value));
  WRITE_FIELD(*this, kFunctionOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kFunctionOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=25&c=3
template<class D, class P>
int TorqueGeneratedCallSiteInfo<D, P>::code_offset_or_source_position() const {
  int value = TaggedField<Smi>::load(*this, kCodeOffsetOrSourcePositionOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=25&c=3
template<class D, class P>
void TorqueGeneratedCallSiteInfo<D, P>::set_code_offset_or_source_position(int value) {
  WRITE_FIELD(*this, kCodeOffsetOrSourcePositionOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=26&c=3
template<class D, class P>
int TorqueGeneratedCallSiteInfo<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=26&c=3
template<class D, class P>
void TorqueGeneratedCallSiteInfo<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=27&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedCallSiteInfo<D, P>::parameters() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedCallSiteInfo::parameters(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=27&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedCallSiteInfo<D, P>::parameters(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kParametersOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/call-site-info.tq?l=27&c=3
template<class D, class P>
void TorqueGeneratedCallSiteInfo<D, P>::set_parameters(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kParametersOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kParametersOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedCallSiteInfo<D, P>::TorqueGeneratedCallSiteInfo(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsCallSiteInfo_NonInline(*this));
}
