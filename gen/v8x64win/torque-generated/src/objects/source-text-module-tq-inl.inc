// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=14&c=3
template<class D, class P>
Tagged<Union<JSFunction, JSGeneratorObject, SharedFunctionInfo>> TorqueGeneratedSourceTextModule<D, P>::code() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSourceTextModule::code(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=14&c=3
template<class D, class P>
Tagged<Union<JSFunction, JSGeneratorObject, SharedFunctionInfo>> TorqueGeneratedSourceTextModule<D, P>::code(PtrComprCageBase cage_base) const {
  Tagged<Union<JSFunction, JSGeneratorObject, SharedFunctionInfo>> value = TaggedField<Tagged<Union<JSFunction, JSGeneratorObject, SharedFunctionInfo>>>::load(cage_base, *this, kCodeOffset);
  DCHECK(IsJSFunction(value) || IsJSGeneratorObject(value) || IsSharedFunctionInfo(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=14&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModule<D, P>::set_code(Tagged<Union<JSFunction, JSGeneratorObject, SharedFunctionInfo>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSFunction(value) || IsJSGeneratorObject(value) || IsSharedFunctionInfo(value));
  WRITE_FIELD(*this, kCodeOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCodeOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=20&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedSourceTextModule<D, P>::regular_exports() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSourceTextModule::regular_exports(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=20&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedSourceTextModule<D, P>::regular_exports(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kRegularExportsOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=20&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModule<D, P>::set_regular_exports(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kRegularExportsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kRegularExportsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=21&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedSourceTextModule<D, P>::regular_imports() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSourceTextModule::regular_imports(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=21&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedSourceTextModule<D, P>::regular_imports(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kRegularImportsOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=21&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModule<D, P>::set_regular_imports(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kRegularImportsOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kRegularImportsOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=26&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedSourceTextModule<D, P>::requested_modules() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSourceTextModule::requested_modules(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=26&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedSourceTextModule<D, P>::requested_modules(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kRequestedModulesOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=26&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModule<D, P>::set_requested_modules(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kRequestedModulesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kRequestedModulesOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=31&c=36
template<class D, class P>
Tagged<Union<Hole, JSObject>> TorqueGeneratedSourceTextModule<D, P>::import_meta(AcquireLoadTag) const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSourceTextModule::import_meta(cage_base, kAcquireLoad);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=31&c=36
template<class D, class P>
Tagged<Union<Hole, JSObject>> TorqueGeneratedSourceTextModule<D, P>::import_meta(PtrComprCageBase cage_base, AcquireLoadTag) const {
  Tagged<Union<Hole, JSObject>> value = TaggedField<Tagged<Union<Hole, JSObject>>>::Acquire_Load(cage_base, *this, kImportMetaOffset);
  DCHECK(IsJSObject(value) || IsTheHole(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=31&c=36
template<class D, class P>
void TorqueGeneratedSourceTextModule<D, P>::set_import_meta(Tagged<Union<Hole, JSObject>> value, ReleaseStoreTag, WriteBarrierMode mode) {
  SLOW_DCHECK(IsJSObject(value) || IsTheHole(value));
  RELEASE_WRITE_FIELD(*this, kImportMetaOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kImportMetaOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=36&c=3
template<class D, class P>
Tagged<Union<Hole, SourceTextModule>> TorqueGeneratedSourceTextModule<D, P>::cycle_root() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSourceTextModule::cycle_root(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=36&c=3
template<class D, class P>
Tagged<Union<Hole, SourceTextModule>> TorqueGeneratedSourceTextModule<D, P>::cycle_root(PtrComprCageBase cage_base) const {
  Tagged<Union<Hole, SourceTextModule>> value = TaggedField<Tagged<Union<Hole, SourceTextModule>>>::load(cage_base, *this, kCycleRootOffset);
  DCHECK(IsTheHole(value) || IsSourceTextModule(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=36&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModule<D, P>::set_cycle_root(Tagged<Union<Hole, SourceTextModule>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsTheHole(value) || IsSourceTextModule(value));
  WRITE_FIELD(*this, kCycleRootOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kCycleRootOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=38&c=3
template<class D, class P>
Tagged<ArrayList> TorqueGeneratedSourceTextModule<D, P>::async_parent_modules() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSourceTextModule::async_parent_modules(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=38&c=3
template<class D, class P>
Tagged<ArrayList> TorqueGeneratedSourceTextModule<D, P>::async_parent_modules(PtrComprCageBase cage_base) const {
  Tagged<ArrayList> value = TaggedField<Tagged<ArrayList>>::load(cage_base, *this, kAsyncParentModulesOffset);
  DCHECK(IsArrayList(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=38&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModule<D, P>::set_async_parent_modules(Tagged<ArrayList> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsArrayList(value));
  WRITE_FIELD(*this, kAsyncParentModulesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kAsyncParentModulesOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=41&c=3
template<class D, class P>
int TorqueGeneratedSourceTextModule<D, P>::dfs_index() const {
  int value = TaggedField<Smi>::load(*this, kDfsIndexOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=41&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModule<D, P>::set_dfs_index(int value) {
  WRITE_FIELD(*this, kDfsIndexOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=42&c=3
template<class D, class P>
int TorqueGeneratedSourceTextModule<D, P>::dfs_ancestor_index() const {
  int value = TaggedField<Smi>::load(*this, kDfsAncestorIndexOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=42&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModule<D, P>::set_dfs_ancestor_index(int value) {
  WRITE_FIELD(*this, kDfsAncestorIndexOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=45&c=3
template<class D, class P>
int TorqueGeneratedSourceTextModule<D, P>::pending_async_dependencies() const {
  int value = TaggedField<Smi>::load(*this, kPendingAsyncDependenciesOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=45&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModule<D, P>::set_pending_async_dependencies(int value) {
  WRITE_FIELD(*this, kPendingAsyncDependenciesOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=47&c=3
template<class D, class P>
int TorqueGeneratedSourceTextModule<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=47&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModule<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedSourceTextModule<D, P>::TorqueGeneratedSourceTextModule(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsSourceTextModule_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=59&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedModuleRequest<D, P>::specifier() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedModuleRequest::specifier(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=59&c=3
template<class D, class P>
Tagged<String> TorqueGeneratedModuleRequest<D, P>::specifier(PtrComprCageBase cage_base) const {
  Tagged<String> value = TaggedField<Tagged<String>>::load(cage_base, *this, kSpecifierOffset);
  DCHECK(IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=59&c=3
template<class D, class P>
void TorqueGeneratedModuleRequest<D, P>::set_specifier(Tagged<String> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsString(value));
  WRITE_FIELD(*this, kSpecifierOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kSpecifierOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=63&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedModuleRequest<D, P>::import_attributes() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedModuleRequest::import_attributes(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=63&c=3
template<class D, class P>
Tagged<FixedArray> TorqueGeneratedModuleRequest<D, P>::import_attributes(PtrComprCageBase cage_base) const {
  Tagged<FixedArray> value = TaggedField<Tagged<FixedArray>>::load(cage_base, *this, kImportAttributesOffset);
  DCHECK(IsFixedArray(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=63&c=3
template<class D, class P>
void TorqueGeneratedModuleRequest<D, P>::set_import_attributes(Tagged<FixedArray> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsFixedArray(value));
  WRITE_FIELD(*this, kImportAttributesOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kImportAttributesOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=65&c=3
template<class D, class P>
int TorqueGeneratedModuleRequest<D, P>::flags() const {
  int value = TaggedField<Smi>::load(*this, kFlagsOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=65&c=3
template<class D, class P>
void TorqueGeneratedModuleRequest<D, P>::set_flags(int value) {
  WRITE_FIELD(*this, kFlagsOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedModuleRequest<D, P>::TorqueGeneratedModuleRequest(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsModuleRequest_NonInline(*this));
}
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=69&c=3
template<class D, class P>
Tagged<Union<String, Undefined>> TorqueGeneratedSourceTextModuleInfoEntry<D, P>::export_name() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSourceTextModuleInfoEntry::export_name(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=69&c=3
template<class D, class P>
Tagged<Union<String, Undefined>> TorqueGeneratedSourceTextModuleInfoEntry<D, P>::export_name(PtrComprCageBase cage_base) const {
  Tagged<Union<String, Undefined>> value = TaggedField<Tagged<Union<String, Undefined>>>::load(cage_base, *this, kExportNameOffset);
  DCHECK(IsUndefined(value) || IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=69&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModuleInfoEntry<D, P>::set_export_name(Tagged<Union<String, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsString(value));
  WRITE_FIELD(*this, kExportNameOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kExportNameOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=70&c=3
template<class D, class P>
Tagged<Union<String, Undefined>> TorqueGeneratedSourceTextModuleInfoEntry<D, P>::local_name() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSourceTextModuleInfoEntry::local_name(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=70&c=3
template<class D, class P>
Tagged<Union<String, Undefined>> TorqueGeneratedSourceTextModuleInfoEntry<D, P>::local_name(PtrComprCageBase cage_base) const {
  Tagged<Union<String, Undefined>> value = TaggedField<Tagged<Union<String, Undefined>>>::load(cage_base, *this, kLocalNameOffset);
  DCHECK(IsUndefined(value) || IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=70&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModuleInfoEntry<D, P>::set_local_name(Tagged<Union<String, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsString(value));
  WRITE_FIELD(*this, kLocalNameOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kLocalNameOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=71&c=3
template<class D, class P>
Tagged<Union<String, Undefined>> TorqueGeneratedSourceTextModuleInfoEntry<D, P>::import_name() const {
  PtrComprCageBase cage_base = GetPtrComprCageBase(*this);
  return TorqueGeneratedSourceTextModuleInfoEntry::import_name(cage_base);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=71&c=3
template<class D, class P>
Tagged<Union<String, Undefined>> TorqueGeneratedSourceTextModuleInfoEntry<D, P>::import_name(PtrComprCageBase cage_base) const {
  Tagged<Union<String, Undefined>> value = TaggedField<Tagged<Union<String, Undefined>>>::load(cage_base, *this, kImportNameOffset);
  DCHECK(IsUndefined(value) || IsString(value));
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=71&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModuleInfoEntry<D, P>::set_import_name(Tagged<Union<String, Undefined>> value, WriteBarrierMode mode) {
  SLOW_DCHECK(IsUndefined(value) || IsString(value));
  WRITE_FIELD(*this, kImportNameOffset, value);
  CONDITIONAL_WRITE_BARRIER(*this, kImportNameOffset, value, mode);
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=72&c=3
template<class D, class P>
int TorqueGeneratedSourceTextModuleInfoEntry<D, P>::module_request() const {
  int value = TaggedField<Smi>::load(*this, kModuleRequestOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=72&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModuleInfoEntry<D, P>::set_module_request(int value) {
  WRITE_FIELD(*this, kModuleRequestOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=73&c=3
template<class D, class P>
int TorqueGeneratedSourceTextModuleInfoEntry<D, P>::cell_index() const {
  int value = TaggedField<Smi>::load(*this, kCellIndexOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=73&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModuleInfoEntry<D, P>::set_cell_index(int value) {
  WRITE_FIELD(*this, kCellIndexOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=74&c=3
template<class D, class P>
int TorqueGeneratedSourceTextModuleInfoEntry<D, P>::beg_pos() const {
  int value = TaggedField<Smi>::load(*this, kBegPosOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=74&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModuleInfoEntry<D, P>::set_beg_pos(int value) {
  WRITE_FIELD(*this, kBegPosOffset, Smi::FromInt(value));
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=75&c=3
template<class D, class P>
int TorqueGeneratedSourceTextModuleInfoEntry<D, P>::end_pos() const {
  int value = TaggedField<Smi>::load(*this, kEndPosOffset).value();
  return value;
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=75&c=3
template<class D, class P>
void TorqueGeneratedSourceTextModuleInfoEntry<D, P>::set_end_pos(int value) {
  WRITE_FIELD(*this, kEndPosOffset, Smi::FromInt(value));
}

template<class D, class P>
inline TorqueGeneratedSourceTextModuleInfoEntry<D, P>::TorqueGeneratedSourceTextModuleInfoEntry(Address ptr)
    : P(ptr) {
  SLOW_DCHECK(IsSourceTextModuleInfoEntry_NonInline(*this));
}
