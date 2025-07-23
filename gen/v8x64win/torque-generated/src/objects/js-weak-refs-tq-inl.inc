// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=22&c=3
template<class D, class P>
Tagged<Union<JSFinalizationRegistry, Undefined>> TorqueGeneratedWeakCell<D, P>::finalization_registry() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWeakCell::finalization_registry(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=22&c=3
template<class D, class P>
Tagged<Union<JSFinalizationRegistry, Undefined>> TorqueGeneratedWeakCell<D, P>::finalization_registry(PtrComprCageBase cage_base) const {
  Tagged<Union<JSFinalizationRegistry, Undefined>> value = TaggedField<Tagged<Union<JSFinalizationRegistry, Undefined>>>::load(cage_base, *this, kFinalizationRegistryOffset);
  DCHECK(IsUndefined(value) || IsJSFinalizationRegistry(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=22&c=3
template<class D, class P>
void TorqueGeneratedWeakCell<D, P>::set_finalization_registry(Tagged<Union<JSFinalizationRegistry, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSFinalizationRegistry(value));
  WRITE_FIELD(*this, kFinalizationRegistryOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kFinalizationRegistryOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=23&c=3
template<class D, class P>
Tagged<Union<JSReceiver, Symbol, Undefined>> TorqueGeneratedWeakCell<D, P>::target() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWeakCell::target(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=23&c=3
template<class D, class P>
Tagged<Union<JSReceiver, Symbol, Undefined>> TorqueGeneratedWeakCell<D, P>::target(PtrComprCageBase cage_base) const {
  Tagged<Union<JSReceiver, Symbol, Undefined>> value = TaggedField<Tagged<Union<JSReceiver, Symbol, Undefined>>>::load(cage_base, *this, kTargetOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsSymbol(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=23&c=3
template<class D, class P>
void TorqueGeneratedWeakCell<D, P>::set_target(Tagged<Union<JSReceiver, Symbol, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsSymbol(value));
  WRITE_FIELD(*this, kTargetOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kTargetOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=24&c=3
template<class D, class P>
Tagged<Union<JSReceiver, Symbol, Undefined>> TorqueGeneratedWeakCell<D, P>::unregister_token() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWeakCell::unregister_token(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=24&c=3
template<class D, class P>
Tagged<Union<JSReceiver, Symbol, Undefined>> TorqueGeneratedWeakCell<D, P>::unregister_token(PtrComprCageBase cage_base) const {
  Tagged<Union<JSReceiver, Symbol, Undefined>> value = TaggedField<Tagged<Union<JSReceiver, Symbol, Undefined>>>::load(cage_base, *this, kUnregisterTokenOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsSymbol(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=24&c=3
template<class D, class P>
void TorqueGeneratedWeakCell<D, P>::set_unregister_token(Tagged<Union<JSReceiver, Symbol, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsSymbol(value));
  WRITE_FIELD(*this, kUnregisterTokenOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kUnregisterTokenOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=25&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedWeakCell<D, P>::holdings() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWeakCell::holdings(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=25&c=3
template<class D, class P>
Tagged<JSAny> TorqueGeneratedWeakCell<D, P>::holdings(PtrComprCageBase cage_base) const {
  Tagged<JSAny> value = TaggedField<Tagged<JSAny>>::load(cage_base, *this, kHoldingsOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=25&c=3
template<class D, class P>
void TorqueGeneratedWeakCell<D, P>::set_holdings(Tagged<JSAny> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsNull(value) || IsBoolean(value) || IsSymbol(value) || IsString(value) || IsBigInt(value) || IsHeapNumber(value) || IsSmi(value));
  WRITE_FIELD(*this, kHoldingsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kHoldingsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=29&c=3
template<class D, class P>
Tagged<Union<Undefined, WeakCell>> TorqueGeneratedWeakCell<D, P>::prev() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWeakCell::prev(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=29&c=3
template<class D, class P>
Tagged<Union<Undefined, WeakCell>> TorqueGeneratedWeakCell<D, P>::prev(PtrComprCageBase cage_base) const {
  Tagged<Union<Undefined, WeakCell>> value = TaggedField<Tagged<Union<Undefined, WeakCell>>>::load(cage_base, *this, kPrevOffset);
  DCHECK(IsUndefined(value) || IsWeakCell(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=29&c=3
template<class D, class P>
void TorqueGeneratedWeakCell<D, P>::set_prev(Tagged<Union<Undefined, WeakCell>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsWeakCell(value));
  WRITE_FIELD(*this, kPrevOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kPrevOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=30&c=3
template<class D, class P>
Tagged<Union<Undefined, WeakCell>> TorqueGeneratedWeakCell<D, P>::next() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWeakCell::next(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=30&c=3
template<class D, class P>
Tagged<Union<Undefined, WeakCell>> TorqueGeneratedWeakCell<D, P>::next(PtrComprCageBase cage_base) const {
  Tagged<Union<Undefined, WeakCell>> value = TaggedField<Tagged<Union<Undefined, WeakCell>>>::load(cage_base, *this, kNextOffset);
  DCHECK(IsUndefined(value) || IsWeakCell(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=30&c=3
template<class D, class P>
void TorqueGeneratedWeakCell<D, P>::set_next(Tagged<Union<Undefined, WeakCell>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsWeakCell(value));
  WRITE_FIELD(*this, kNextOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNextOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=38&c=3
template<class D, class P>
Tagged<Union<Undefined, WeakCell>> TorqueGeneratedWeakCell<D, P>::key_list_prev() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWeakCell::key_list_prev(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=38&c=3
template<class D, class P>
Tagged<Union<Undefined, WeakCell>> TorqueGeneratedWeakCell<D, P>::key_list_prev(PtrComprCageBase cage_base) const {
  Tagged<Union<Undefined, WeakCell>> value = TaggedField<Tagged<Union<Undefined, WeakCell>>>::load(cage_base, *this, kKeyListPrevOffset);
  DCHECK(IsUndefined(value) || IsWeakCell(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=38&c=3
template<class D, class P>
void TorqueGeneratedWeakCell<D, P>::set_key_list_prev(Tagged<Union<Undefined, WeakCell>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsWeakCell(value));
  WRITE_FIELD(*this, kKeyListPrevOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kKeyListPrevOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=39&c=3
template<class D, class P>
Tagged<Union<Undefined, WeakCell>> TorqueGeneratedWeakCell<D, P>::key_list_next() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedWeakCell::key_list_next(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=39&c=3
template<class D, class P>
Tagged<Union<Undefined, WeakCell>> TorqueGeneratedWeakCell<D, P>::key_list_next(PtrComprCageBase cage_base) const {
  Tagged<Union<Undefined, WeakCell>> value = TaggedField<Tagged<Union<Undefined, WeakCell>>>::load(cage_base, *this, kKeyListNextOffset);
  DCHECK(IsUndefined(value) || IsWeakCell(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=39&c=3
template<class D, class P>
void TorqueGeneratedWeakCell<D, P>::set_key_list_next(Tagged<Union<Undefined, WeakCell>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsWeakCell(value));
  WRITE_FIELD(*this, kKeyListNextOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kKeyListNextOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedWeakCell<D, P>::TorqueGeneratedWeakCell(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsWeakCell_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=10&c=3
template<class D, class P>
Tagged<NativeContext> TorqueGeneratedJSFinalizationRegistry<D, P>::native_context() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSFinalizationRegistry::native_context(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=10&c=3
template<class D, class P>
Tagged<NativeContext> TorqueGeneratedJSFinalizationRegistry<D, P>::native_context(PtrComprCageBase cage_base) const {
  Tagged<NativeContext> value = TaggedField<Tagged<NativeContext>>::load(cage_base, *this, kNativeContextOffset);
  DCHECK(IsNativeContext(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=10&c=3
template<class D, class P>
void TorqueGeneratedJSFinalizationRegistry<D, P>::set_native_context(Tagged<NativeContext> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsNativeContext(value));
  WRITE_FIELD(*this, kNativeContextOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNativeContextOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=11&c=3
template<class D, class P>
Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> TorqueGeneratedJSFinalizationRegistry<D, P>::cleanup() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSFinalizationRegistry::cleanup(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=11&c=3
template<class D, class P>
Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> TorqueGeneratedJSFinalizationRegistry<D, P>::cleanup(PtrComprCageBase cage_base) const {
  Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> value = TaggedField<Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>>>::load(cage_base, *this, kCleanupOffset);
  DCHECK(IsJSFunction(value) || IsCallableApiObject(value) || IsCallableJSProxy(value) || IsJSWrappedFunction(value) || IsJSBoundFunction(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=11&c=3
template<class D, class P>
void TorqueGeneratedJSFinalizationRegistry<D, P>::set_cleanup(Tagged<Union<JSBoundFunction, JSFunction, JSObject, JSProxy, JSWrappedFunction>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSFunction(value) || IsCallableApiObject(value) || IsCallableJSProxy(value) || IsJSWrappedFunction(value) || IsJSBoundFunction(value));
  WRITE_FIELD(*this, kCleanupOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCleanupOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=12&c=3
template<class D, class P>
Tagged<Union<Undefined, WeakCell>> TorqueGeneratedJSFinalizationRegistry<D, P>::active_cells() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSFinalizationRegistry::active_cells(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=12&c=3
template<class D, class P>
Tagged<Union<Undefined, WeakCell>> TorqueGeneratedJSFinalizationRegistry<D, P>::active_cells(PtrComprCageBase cage_base) const {
  Tagged<Union<Undefined, WeakCell>> value = TaggedField<Tagged<Union<Undefined, WeakCell>>>::load(cage_base, *this, kActiveCellsOffset);
  DCHECK(IsUndefined(value) || IsWeakCell(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=12&c=3
template<class D, class P>
void TorqueGeneratedJSFinalizationRegistry<D, P>::set_active_cells(Tagged<Union<Undefined, WeakCell>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsWeakCell(value));
  WRITE_FIELD(*this, kActiveCellsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kActiveCellsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=13&c=3
template<class D, class P>
Tagged<Union<Undefined, WeakCell>> TorqueGeneratedJSFinalizationRegistry<D, P>::cleared_cells() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSFinalizationRegistry::cleared_cells(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=13&c=3
template<class D, class P>
Tagged<Union<Undefined, WeakCell>> TorqueGeneratedJSFinalizationRegistry<D, P>::cleared_cells(PtrComprCageBase cage_base) const {
  Tagged<Union<Undefined, WeakCell>> value = TaggedField<Tagged<Union<Undefined, WeakCell>>>::load(cage_base, *this, kClearedCellsOffset);
  DCHECK(IsUndefined(value) || IsWeakCell(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=13&c=3
template<class D, class P>
void TorqueGeneratedJSFinalizationRegistry<D, P>::set_cleared_cells(Tagged<Union<Undefined, WeakCell>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsWeakCell(value));
  WRITE_FIELD(*this, kClearedCellsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kClearedCellsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=14&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedJSFinalizationRegistry<D, P>::key_map() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSFinalizationRegistry::key_map(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=14&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedJSFinalizationRegistry<D, P>::key_map(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kKeyMapOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=14&c=3
template<class D, class P>
void TorqueGeneratedJSFinalizationRegistry<D, P>::set_key_map(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kKeyMapOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kKeyMapOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=17&c=3
template<class D, class P>
Tagged<Union<JSFinalizationRegistry, Undefined>> TorqueGeneratedJSFinalizationRegistry<D, P>::next_dirty() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSFinalizationRegistry::next_dirty(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=17&c=3
template<class D, class P>
Tagged<Union<JSFinalizationRegistry, Undefined>> TorqueGeneratedJSFinalizationRegistry<D, P>::next_dirty(PtrComprCageBase cage_base) const {
  Tagged<Union<JSFinalizationRegistry, Undefined>> value = TaggedField<Tagged<Union<JSFinalizationRegistry, Undefined>>>::load(cage_base, *this, kNextDirtyOffset);
  DCHECK(IsUndefined(value) || IsJSFinalizationRegistry(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=17&c=3
template<class D, class P>
void TorqueGeneratedJSFinalizationRegistry<D, P>::set_next_dirty(Tagged<Union<JSFinalizationRegistry, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSFinalizationRegistry(value));
  WRITE_FIELD(*this, kNextDirtyOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kNextDirtyOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=18&c=3
template<class D, class P>
int TorqueGeneratedJSFinalizationRegistry<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=18&c=3
template<class D, class P>
void TorqueGeneratedJSFinalizationRegistry<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedJSFinalizationRegistry<D, P>::TorqueGeneratedJSFinalizationRegistry(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSFinalizationRegistry_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=43&c=3
template<class D, class P>
Tagged<Union<JSReceiver, Symbol, Undefined>> TorqueGeneratedJSWeakRef<D, P>::target() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSWeakRef::target(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=43&c=3
template<class D, class P>
Tagged<Union<JSReceiver, Symbol, Undefined>> TorqueGeneratedJSWeakRef<D, P>::target(PtrComprCageBase cage_base) const {
  Tagged<Union<JSReceiver, Symbol, Undefined>> value = TaggedField<Tagged<Union<JSReceiver, Symbol, Undefined>>>::load(cage_base, *this, kTargetOffset);
  DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsSymbol(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-weak-refs.tq?l=43&c=3
template<class D, class P>
void TorqueGeneratedJSWeakRef<D, P>::set_target(Tagged<Union<JSReceiver, Symbol, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSReceiver(value) || IsUndefined(value) || IsSymbol(value));
  WRITE_FIELD(*this, kTargetOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kTargetOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSWeakRef<D, P>::TorqueGeneratedJSWeakRef(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSWeakRef_NonInline(*this));
}
