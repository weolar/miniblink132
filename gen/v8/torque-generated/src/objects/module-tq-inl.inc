// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=8&c=3
template<class D, class P>
Tagged<ObjectHashTable> TorqueGeneratedModule<D, P>::exports() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedModule::exports(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=8&c=3
template<class D, class P>
Tagged<ObjectHashTable> TorqueGeneratedModule<D, P>::exports(PtrComprCageBase cage_base) const {
  Tagged<ObjectHashTable> value = TaggedField<Tagged<ObjectHashTable>>::load(cage_base, *this, kExportsOffset);
  DCHECK(IsObjectHashTable(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=8&c=3
template<class D, class P>
void TorqueGeneratedModule<D, P>::set_exports(Tagged<ObjectHashTable> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsObjectHashTable(value));
  WRITE_FIELD(*this, kExportsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kExportsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=10&c=3
template<class D, class P>
int TorqueGeneratedModule<D, P>::hash() const {
  int value = TaggedField<Smi>::load(*this, kHashOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=10&c=3
template<class D, class P>
void TorqueGeneratedModule<D, P>::set_hash(int value) {
  WRITE_FIELD(*this, kHashOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=11&c=3
template<class D, class P>
int TorqueGeneratedModule<D, P>::status() const {
  int value = TaggedField<Smi>::load(*this, kStatusOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=11&c=3
template<class D, class P>
void TorqueGeneratedModule<D, P>::set_status(int value) {
  WRITE_FIELD(*this, kStatusOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=12&c=3
template<class D, class P>
Tagged<Union<JSModuleNamespace, Undefined>> TorqueGeneratedModule<D, P>::module_namespace() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedModule::module_namespace(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=12&c=3
template<class D, class P>
Tagged<Union<JSModuleNamespace, Undefined>> TorqueGeneratedModule<D, P>::module_namespace(PtrComprCageBase cage_base) const {
  Tagged<Union<JSModuleNamespace, Undefined>> value = TaggedField<Tagged<Union<JSModuleNamespace, Undefined>>>::load(cage_base, *this, kModuleNamespaceOffset);
  DCHECK(IsUndefined(value) || IsJSModuleNamespace(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=12&c=3
template<class D, class P>
void TorqueGeneratedModule<D, P>::set_module_namespace(Tagged<Union<JSModuleNamespace, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSModuleNamespace(value));
  WRITE_FIELD(*this, kModuleNamespaceOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kModuleNamespaceOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=14&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedModule<D, P>::exception() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedModule::exception(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=14&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedModule<D, P>::exception(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kExceptionOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=14&c=3
template<class D, class P>
void TorqueGeneratedModule<D, P>::set_exception(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kExceptionOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kExceptionOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=17&c=3
template<class D, class P>
Tagged<Union<JSPromise, Undefined>> TorqueGeneratedModule<D, P>::top_level_capability() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedModule::top_level_capability(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=17&c=3
template<class D, class P>
Tagged<Union<JSPromise, Undefined>> TorqueGeneratedModule<D, P>::top_level_capability(PtrComprCageBase cage_base) const {
  Tagged<Union<JSPromise, Undefined>> value = TaggedField<Tagged<Union<JSPromise, Undefined>>>::load(cage_base, *this, kTopLevelCapabilityOffset);
  DCHECK(IsUndefined(value) || IsJSPromise(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=17&c=3
template<class D, class P>
void TorqueGeneratedModule<D, P>::set_top_level_capability(Tagged<Union<JSPromise, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsJSPromise(value));
  WRITE_FIELD(*this, kTopLevelCapabilityOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kTopLevelCapabilityOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedModule<D, P>::TorqueGeneratedModule(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsModule_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=21&c=3
template<class D, class P>
Tagged<Module> TorqueGeneratedJSModuleNamespace<D, P>::module() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedJSModuleNamespace::module(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=21&c=3
template<class D, class P>
Tagged<Module> TorqueGeneratedJSModuleNamespace<D, P>::module(PtrComprCageBase cage_base) const {
  Tagged<Module> value = TaggedField<Tagged<Module>>::load(cage_base, *this, kModuleOffset);
  DCHECK(IsModule(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=21&c=3
template<class D, class P>
void TorqueGeneratedJSModuleNamespace<D, P>::set_module(Tagged<Module> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsModule(value));
  WRITE_FIELD(*this, kModuleOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kModuleOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedJSModuleNamespace<D, P>::TorqueGeneratedJSModuleNamespace(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsJSModuleNamespace_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=25&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedScriptOrModule<D, P>::resource_name() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScriptOrModule::resource_name(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=25&c=3
template<class D, class P>
Tagged<Object> TorqueGeneratedScriptOrModule<D, P>::resource_name(PtrComprCageBase cage_base) const {
  Tagged<Object> value = TaggedField<Tagged<Object>>::load(cage_base, *this, kResourceNameOffset);
  DCHECK(IsHeapObject(value) || IsSmi(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=25&c=3
template<class D, class P>
void TorqueGeneratedScriptOrModule<D, P>::set_resource_name(Tagged<Object> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsHeapObject(value) || IsSmi(value));
  WRITE_FIELD(*this, kResourceNameOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kResourceNameOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=26&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedScriptOrModule<D, P>::host_defined_options() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedScriptOrModule::host_defined_options(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=26&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedScriptOrModule<D, P>::host_defined_options(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kHostDefinedOptionsOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=26&c=3
template<class D, class P>
void TorqueGeneratedScriptOrModule<D, P>::set_host_defined_options(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kHostDefinedOptionsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kHostDefinedOptionsOffset, value, mode);
}

template<class D, class P>
inline TorqueGeneratedScriptOrModule<D, P>::TorqueGeneratedScriptOrModule(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsScriptOrModule_NonInline(*this));
}
