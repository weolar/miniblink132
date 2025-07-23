class WasmNull;
class WasmFuncRef;
class WasmImportData;
class WasmInstanceObject;
class WasmInternalFunction;
class WasmFunctionData;
class WasmExportedFunctionData;
class WasmJSFunctionData;
class WasmCapiFunctionData;
class WasmResumeData;
class WasmContinuationObject;
class WasmSuspenderObject;
class WasmExceptionTag;
class WasmModuleObject;
class WasmTableObject;
class WasmMemoryObject;
class WasmGlobalObject;
class WasmTagObject;
class AsmWasmData;
class WasmTypeInfo;
class WasmObject;
class WasmStruct;
class WasmArray;
class WasmSuspendingObject;
// Alias for IsWasmNull() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=321&c=1
V8_EXPORT_PRIVATE bool IsWasmNull_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=321&c=1
template <class D, class P>
class TorqueGeneratedWasmNull : public P {
  static_assert(
      std::is_same<WasmNull, D>::value,
      "Use this class as direct base for WasmNull.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedWasmNull.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmNull<D,P>;

  DECL_PRINTER(WasmNull)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=321&c=1
  V8_EXPORT_PRIVATE void WasmNullVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;
  static constexpr int kSize = P::kHeaderSize;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=321&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 4);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=321&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmNull() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmNull, DAlias>::value,
        "class TorqueGeneratedWasmNull should be used as direct base for WasmNull.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmNull(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmNull(Address ptr);
};

// Alias for IsWasmFuncRef() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=109&c=1
V8_EXPORT_PRIVATE bool IsWasmFuncRef_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=109&c=1
template <class D, class P>
class TorqueGeneratedWasmFuncRef : public P {
  static_assert(
      std::is_same<WasmFuncRef, D>::value,
      "Use this class as direct base for WasmFuncRef.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedWasmFuncRef.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmFuncRef<D,P>;

  DECL_PRINTER(WasmFuncRef)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=109&c=1
  V8_EXPORT_PRIVATE void WasmFuncRefVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=111&c=3
  static constexpr int kTrustedInternalOffset = P::kHeaderSize;
  static constexpr int kTrustedInternalOffsetEnd = kTrustedInternalOffset + kTrustedPointerSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kTrustedInternalOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kTrustedInternalOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kTrustedInternalOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kTrustedInternalOffsetEnd + 1;
  static constexpr int kHeaderSize = kTrustedInternalOffsetEnd + 1;
  static constexpr int kSize = kTrustedInternalOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=109&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 8);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=109&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmFuncRef() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmFuncRef, DAlias>::value,
        "class TorqueGeneratedWasmFuncRef should be used as direct base for WasmFuncRef.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmFuncRef(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmFuncRef(Address ptr);
};

// Alias for IsWasmImportData() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=43&c=1
V8_EXPORT_PRIVATE bool IsWasmImportData_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=43&c=1
template <class D, class P>
class TorqueGeneratedWasmImportData : public P {
  static_assert(
      std::is_same<WasmImportData, D>::value,
      "Use this class as direct base for WasmImportData.");
  static_assert(
      std::is_same<TrustedObject, P>::value,
      "Pass in TrustedObject as second template parameter for TorqueGeneratedWasmImportData.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmImportData<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=48&c=3
  inline Tagged<NativeContext> native_context() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=48&c=3
  inline Tagged<NativeContext> native_context(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=48&c=3
  inline void set_native_context(Tagged<NativeContext> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class JSReceiver | class Undefined)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=49&c=3
  inline Tagged<Union<JSReceiver, Undefined>> callable() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=49&c=3
  inline Tagged<Union<JSReceiver, Undefined>> callable(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=49&c=3
  inline void set_callable(Tagged<Union<JSReceiver, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=50&c=3
  inline int suspend() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=50&c=3
  inline void set_suspend(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=51&c=3
  inline int wrapper_budget() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=51&c=3
  inline void set_wrapper_budget(int value);

  // Torque type: (Smi | class WasmFuncRef | class Tuple2)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=58&c=3
  inline Tagged<Union<Smi, Tuple2, WasmFuncRef>> call_origin() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=58&c=3
  inline Tagged<Union<Smi, Tuple2, WasmFuncRef>> call_origin(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=58&c=3
  inline void set_call_origin(Tagged<Union<Smi, Tuple2, WasmFuncRef>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=60&c=3
  inline const wasm::CanonicalSig* sig() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=60&c=3
  inline void set_sig(const wasm::CanonicalSig* value);

  DECL_PRINTER(WasmImportData)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=43&c=1
  V8_EXPORT_PRIVATE void WasmImportDataVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=47&c=3
  static constexpr int kProtectedInstanceDataOffset = P::kHeaderSize;
  static constexpr int kProtectedInstanceDataOffsetEnd = kProtectedInstanceDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfWeakFieldsOffset = kProtectedInstanceDataOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kProtectedInstanceDataOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=48&c=3
  static constexpr int kNativeContextOffset = kProtectedInstanceDataOffsetEnd + 1;
  static constexpr int kNativeContextOffsetEnd = kNativeContextOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=49&c=3
  static constexpr int kCallableOffset = kNativeContextOffsetEnd + 1;
  static constexpr int kCallableOffsetEnd = kCallableOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=50&c=3
  static constexpr int kSuspendOffset = kCallableOffsetEnd + 1;
  static constexpr int kSuspendOffsetEnd = kSuspendOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=51&c=3
  static constexpr int kWrapperBudgetOffset = kSuspendOffsetEnd + 1;
  static constexpr int kWrapperBudgetOffsetEnd = kWrapperBudgetOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=58&c=3
  static constexpr int kCallOriginOffset = kWrapperBudgetOffsetEnd + 1;
  static constexpr int kCallOriginOffsetEnd = kCallOriginOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCallOriginOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=60&c=3
  static constexpr int kSigOffset = kCallOriginOffsetEnd + 1;
  static constexpr int kSigOffsetEnd = kSigOffset + kSystemPointerSize - 1;
  static constexpr int kHeaderSize = kSigOffsetEnd + 1;
  static constexpr int kSize = kSigOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=43&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 36);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=43&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmImportData() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmImportData, DAlias>::value,
        "class TorqueGeneratedWasmImportData should be used as direct base for WasmImportData.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmImportData(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmImportData(Address ptr);
};

// Alias for IsWasmInstanceObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=33&c=1
V8_EXPORT_PRIVATE bool IsWasmInstanceObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=33&c=1
template <class D, class P>
class TorqueGeneratedWasmInstanceObject : public P {
  static_assert(
      std::is_same<WasmInstanceObject, D>::value,
      "Use this class as direct base for WasmInstanceObject.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedWasmInstanceObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmInstanceObject<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=35&c=3
  inline Tagged<WasmModuleObject> module_object() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=35&c=3
  inline Tagged<WasmModuleObject> module_object(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=35&c=3
  inline void set_module_object(Tagged<WasmModuleObject> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=36&c=3
  inline Tagged<JSObject> exports_object() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=36&c=3
  inline Tagged<JSObject> exports_object(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=36&c=3
  inline void set_exports_object(Tagged<JSObject> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(WasmInstanceObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=33&c=1
  V8_EXPORT_PRIVATE void WasmInstanceObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=34&c=3
  static constexpr int kTrustedDataOffset = P::kHeaderSize;
  static constexpr int kTrustedDataOffsetEnd = kTrustedDataOffset + kTrustedPointerSize - 1;
  static constexpr int kStartOfStrongFieldsOffset = kTrustedDataOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=35&c=3
  static constexpr int kModuleObjectOffset = kTrustedDataOffsetEnd + 1;
  static constexpr int kModuleObjectOffsetEnd = kModuleObjectOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=36&c=3
  static constexpr int kExportsObjectOffset = kModuleObjectOffsetEnd + 1;
  static constexpr int kExportsObjectOffsetEnd = kExportsObjectOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kExportsObjectOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kExportsObjectOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kExportsObjectOffsetEnd + 1;
  static constexpr int kHeaderSize = kExportsObjectOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmInstanceObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmInstanceObject, DAlias>::value,
        "class TorqueGeneratedWasmInstanceObject should be used as direct base for WasmInstanceObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmInstanceObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmInstanceObject(Address ptr);
};

// Alias for IsWasmInternalFunction() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=74&c=1
V8_EXPORT_PRIVATE bool IsWasmInternalFunction_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=74&c=1
template <class D, class P>
class TorqueGeneratedWasmInternalFunction : public P {
  static_assert(
      std::is_same<WasmInternalFunction, D>::value,
      "Use this class as direct base for WasmInternalFunction.");
  static_assert(
      std::is_same<ExposedTrustedObject, P>::value,
      "Pass in ExposedTrustedObject as second template parameter for TorqueGeneratedWasmInternalFunction.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmInternalFunction<D,P>;

  // Torque type: (class Undefined | class JSFunction)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=84&c=3
  inline Tagged<Union<JSFunction, Undefined>> external() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=84&c=3
  inline Tagged<Union<JSFunction, Undefined>> external(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=84&c=3
  inline void set_external(Tagged<Union<JSFunction, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=91&c=3
  inline int function_index() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=91&c=3
  inline void set_function_index(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=93&c=3
  inline Address call_target() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=93&c=3
  inline void set_call_target(Address value);

  DECL_PRINTER(WasmInternalFunction)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=74&c=1
  V8_EXPORT_PRIVATE void WasmInternalFunctionVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=81&c=3
  static constexpr int kProtectedImplicitArgOffset = P::kHeaderSize;
  static constexpr int kProtectedImplicitArgOffsetEnd = kProtectedImplicitArgOffset + kTaggedSize - 1;
  static constexpr int kEndOfWeakFieldsOffset = kProtectedImplicitArgOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kProtectedImplicitArgOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=84&c=3
  static constexpr int kExternalOffset = kProtectedImplicitArgOffsetEnd + 1;
  static constexpr int kExternalOffsetEnd = kExternalOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=91&c=3
  static constexpr int kFunctionIndexOffset = kExternalOffsetEnd + 1;
  static constexpr int kFunctionIndexOffsetEnd = kFunctionIndexOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kFunctionIndexOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=93&c=3
  static constexpr int kCallTargetOffset = kFunctionIndexOffsetEnd + 1;
  static constexpr int kCallTargetOffsetEnd = kCallTargetOffset + kSystemPointerSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=95&c=43
  static constexpr int kOptionalPaddingOffset = kCallTargetOffsetEnd + 1;
  static constexpr int kOptionalPaddingOffsetEnd = kOptionalPaddingOffset + 0 - 1;
  static constexpr int kHeaderSize = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kSize = kOptionalPaddingOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=74&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 24);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=74&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmInternalFunction() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmInternalFunction, DAlias>::value,
        "class TorqueGeneratedWasmInternalFunction should be used as direct base for WasmInternalFunction.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmInternalFunction(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmInternalFunction(Address ptr);
};

// Alias for IsWasmFunctionData() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=118&c=1
V8_EXPORT_PRIVATE bool IsWasmFunctionData_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=118&c=1
template <class D, class P>
class TorqueGeneratedWasmFunctionData : public P {
  static_assert(
      std::is_same<WasmFunctionData, D>::value,
      "Use this class as direct base for WasmFunctionData.");
  static_assert(
      std::is_same<ExposedTrustedObject, P>::value,
      "Pass in ExposedTrustedObject as second template parameter for TorqueGeneratedWasmFunctionData.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmFunctionData<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=123&c=3
  inline Tagged<WasmFuncRef> func_ref() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=123&c=3
  inline Tagged<WasmFuncRef> func_ref(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=123&c=3
  inline void set_func_ref(Tagged<WasmFuncRef> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=125&c=3
  inline int js_promise_flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=125&c=3
  inline void set_js_promise_flags(int value);

  DECL_PRINTER(WasmFunctionData)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=118&c=1
  V8_EXPORT_PRIVATE void WasmFunctionDataVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=120&c=3
  static constexpr int kWrapperCodeOffset = P::kHeaderSize;
  static constexpr int kWrapperCodeOffsetEnd = kWrapperCodeOffset + kTrustedPointerSize - 1;
  static constexpr int kStartOfStrongFieldsOffset = kWrapperCodeOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=123&c=3
  static constexpr int kFuncRefOffset = kWrapperCodeOffsetEnd + 1;
  static constexpr int kFuncRefOffsetEnd = kFuncRefOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=125&c=3
  static constexpr int kJsPromiseFlagsOffset = kFuncRefOffsetEnd + 1;
  static constexpr int kJsPromiseFlagsOffsetEnd = kJsPromiseFlagsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kJsPromiseFlagsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kJsPromiseFlagsOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=128&c=3
  static constexpr int kProtectedInternalOffset = kJsPromiseFlagsOffsetEnd + 1;
  static constexpr int kProtectedInternalOffsetEnd = kProtectedInternalOffset + kTaggedSize - 1;
  static constexpr int kEndOfWeakFieldsOffset = kProtectedInternalOffsetEnd + 1;
  static constexpr int kHeaderSize = kProtectedInternalOffsetEnd + 1;
  static constexpr int kSize = kProtectedInternalOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=118&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 20);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=118&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmFunctionData() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmFunctionData, DAlias>::value,
        "class TorqueGeneratedWasmFunctionData should be used as direct base for WasmFunctionData.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmFunctionData(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmFunctionData(Address ptr);
};

// Alias for IsWasmExportedFunctionData() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=134&c=1
V8_EXPORT_PRIVATE bool IsWasmExportedFunctionData_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=134&c=1
template <class D, class P>
class TorqueGeneratedWasmExportedFunctionData : public P {
  static_assert(
      std::is_same<WasmExportedFunctionData, D>::value,
      "Use this class as direct base for WasmExportedFunctionData.");
  static_assert(
      std::is_same<WasmFunctionData, P>::value,
      "Pass in WasmFunctionData as second template parameter for TorqueGeneratedWasmExportedFunctionData.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmExportedFunctionData<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=139&c=3
  inline int function_index() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=139&c=3
  inline void set_function_index(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=141&c=3
  inline Tagged<Cell> wrapper_budget() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=141&c=3
  inline Tagged<Cell> wrapper_budget(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=141&c=3
  inline void set_wrapper_budget(Tagged<Cell> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=142&c=3
  inline int canonical_type_index() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=142&c=3
  inline void set_canonical_type_index(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=147&c=3
  inline int packed_args_size() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=147&c=3
  inline void set_packed_args_size(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=150&c=3
  inline const wasm::CanonicalSig* sig() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=150&c=3
  inline void set_sig(const wasm::CanonicalSig* value);

  DECL_PRINTER(WasmExportedFunctionData)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=134&c=1
  V8_EXPORT_PRIVATE void WasmExportedFunctionDataVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=138&c=3
  static constexpr int kProtectedInstanceDataOffset = P::kHeaderSize;
  static constexpr int kProtectedInstanceDataOffsetEnd = kProtectedInstanceDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfWeakFieldsOffset = kProtectedInstanceDataOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kProtectedInstanceDataOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=139&c=3
  static constexpr int kFunctionIndexOffset = kProtectedInstanceDataOffsetEnd + 1;
  static constexpr int kFunctionIndexOffsetEnd = kFunctionIndexOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=141&c=3
  static constexpr int kWrapperBudgetOffset = kFunctionIndexOffsetEnd + 1;
  static constexpr int kWrapperBudgetOffsetEnd = kWrapperBudgetOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=142&c=3
  static constexpr int kCanonicalTypeIndexOffset = kWrapperBudgetOffsetEnd + 1;
  static constexpr int kCanonicalTypeIndexOffsetEnd = kCanonicalTypeIndexOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=147&c=3
  static constexpr int kPackedArgsSizeOffset = kCanonicalTypeIndexOffsetEnd + 1;
  static constexpr int kPackedArgsSizeOffsetEnd = kPackedArgsSizeOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kPackedArgsSizeOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=148&c=3
  static constexpr int kCWrapperCodeOffset = kPackedArgsSizeOffsetEnd + 1;
  static constexpr int kCWrapperCodeOffsetEnd = kCWrapperCodeOffset + kTrustedPointerSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=150&c=3
  static constexpr int kSigOffset = kCWrapperCodeOffsetEnd + 1;
  static constexpr int kSigOffsetEnd = kSigOffset + kSystemPointerSize - 1;
  static constexpr int kHeaderSize = kSigOffsetEnd + 1;
  static constexpr int kSize = kSigOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=134&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 52);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=134&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmExportedFunctionData() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmExportedFunctionData, DAlias>::value,
        "class TorqueGeneratedWasmExportedFunctionData should be used as direct base for WasmExportedFunctionData.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmExportedFunctionData(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmExportedFunctionData(Address ptr);
};

// Alias for IsWasmJSFunctionData() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=157&c=1
V8_EXPORT_PRIVATE bool IsWasmJSFunctionData_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=157&c=1
template <class D, class P>
class TorqueGeneratedWasmJSFunctionData : public P {
  static_assert(
      std::is_same<WasmJSFunctionData, D>::value,
      "Use this class as direct base for WasmJSFunctionData.");
  static_assert(
      std::is_same<WasmFunctionData, P>::value,
      "Pass in WasmFunctionData as second template parameter for TorqueGeneratedWasmJSFunctionData.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmJSFunctionData<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=158&c=3
  inline int canonical_sig_index() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=158&c=3
  inline void set_canonical_sig_index(int value);

  DECL_PRINTER(WasmJSFunctionData)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=157&c=1
  V8_EXPORT_PRIVATE void WasmJSFunctionDataVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=158&c=3
  static constexpr int kCanonicalSigIndexOffset = P::kHeaderSize;
  static constexpr int kCanonicalSigIndexOffsetEnd = kCanonicalSigIndexOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCanonicalSigIndexOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kCanonicalSigIndexOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=159&c=3
  static constexpr int kProtectedOffheapDataOffset = kCanonicalSigIndexOffsetEnd + 1;
  static constexpr int kProtectedOffheapDataOffsetEnd = kProtectedOffheapDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfWeakFieldsOffset = kProtectedOffheapDataOffsetEnd + 1;
  static constexpr int kHeaderSize = kProtectedOffheapDataOffsetEnd + 1;
  static constexpr int kSize = kProtectedOffheapDataOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=157&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 28);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=157&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmJSFunctionData() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmJSFunctionData, DAlias>::value,
        "class TorqueGeneratedWasmJSFunctionData should be used as direct base for WasmJSFunctionData.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmJSFunctionData(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmJSFunctionData(Address ptr);
};

// Alias for IsWasmCapiFunctionData() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=163&c=1
V8_EXPORT_PRIVATE bool IsWasmCapiFunctionData_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=163&c=1
template <class D, class P>
class TorqueGeneratedWasmCapiFunctionData : public P {
  static_assert(
      std::is_same<WasmCapiFunctionData, D>::value,
      "Use this class as direct base for WasmCapiFunctionData.");
  static_assert(
      std::is_same<WasmFunctionData, P>::value,
      "Pass in WasmFunctionData as second template parameter for TorqueGeneratedWasmCapiFunctionData.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmCapiFunctionData<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=165&c=3
  inline int canonical_sig_index() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=165&c=3
  inline void set_canonical_sig_index(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=166&c=3
  inline Tagged<Foreign> embedder_data() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=166&c=3
  inline Tagged<Foreign> embedder_data(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=166&c=3
  inline void set_embedder_data(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=167&c=3
  inline const wasm::CanonicalSig* sig() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=167&c=3
  inline void set_sig(const wasm::CanonicalSig* value);

  DECL_PRINTER(WasmCapiFunctionData)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=163&c=1
  V8_EXPORT_PRIVATE void WasmCapiFunctionDataVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=165&c=3
  static constexpr int kCanonicalSigIndexOffset = P::kHeaderSize;
  static constexpr int kCanonicalSigIndexOffsetEnd = kCanonicalSigIndexOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=166&c=3
  static constexpr int kEmbedderDataOffset = kCanonicalSigIndexOffsetEnd + 1;
  static constexpr int kEmbedderDataOffsetEnd = kEmbedderDataOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kEmbedderDataOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=167&c=3
  static constexpr int kSigOffset = kEmbedderDataOffsetEnd + 1;
  static constexpr int kSigOffsetEnd = kSigOffset + kSystemPointerSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kSigOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kSigOffsetEnd + 1;
  static constexpr int kHeaderSize = kSigOffsetEnd + 1;
  static constexpr int kSize = kSigOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=163&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 36);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=163&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmCapiFunctionData() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmCapiFunctionData, DAlias>::value,
        "class TorqueGeneratedWasmCapiFunctionData should be used as direct base for WasmCapiFunctionData.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmCapiFunctionData(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmCapiFunctionData(Address ptr);
};

// Alias for IsWasmResumeData() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=170&c=1
V8_EXPORT_PRIVATE bool IsWasmResumeData_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=170&c=1
template <class D, class P>
class TorqueGeneratedWasmResumeData : public P {
  static_assert(
      std::is_same<WasmResumeData, D>::value,
      "Use this class as direct base for WasmResumeData.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedWasmResumeData.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmResumeData<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=171&c=3
  inline Tagged<WasmSuspenderObject> suspender() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=171&c=3
  inline Tagged<WasmSuspenderObject> suspender(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=171&c=3
  inline void set_suspender(Tagged<WasmSuspenderObject> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=172&c=3
  inline int on_resume() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=172&c=3
  inline void set_on_resume(int value);

  DECL_PRINTER(WasmResumeData)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=170&c=1
  V8_EXPORT_PRIVATE void WasmResumeDataVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=171&c=3
  static constexpr int kSuspenderOffset = P::kHeaderSize;
  static constexpr int kSuspenderOffsetEnd = kSuspenderOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=172&c=3
  static constexpr int kOnResumeOffset = kSuspenderOffsetEnd + 1;
  static constexpr int kOnResumeOffsetEnd = kOnResumeOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kOnResumeOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kOnResumeOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kOnResumeOffsetEnd + 1;
  static constexpr int kHeaderSize = kOnResumeOffsetEnd + 1;
  static constexpr int kSize = kOnResumeOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=170&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=170&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmResumeData() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmResumeData, DAlias>::value,
        "class TorqueGeneratedWasmResumeData should be used as direct base for WasmResumeData.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmResumeData(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmResumeData(Address ptr);
};

// Alias for IsWasmContinuationObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=175&c=1
V8_EXPORT_PRIVATE bool IsWasmContinuationObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=175&c=1
template <class D, class P>
class TorqueGeneratedWasmContinuationObject : public P {
  static_assert(
      std::is_same<WasmContinuationObject, D>::value,
      "Use this class as direct base for WasmContinuationObject.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedWasmContinuationObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmContinuationObject<D,P>;

  // Torque type: (class Undefined | class WasmContinuationObject)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=176&c=3
  inline Tagged<Union<Undefined, WasmContinuationObject>> parent() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=176&c=3
  inline Tagged<Union<Undefined, WasmContinuationObject>> parent(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=176&c=3
  inline void set_parent(Tagged<Union<Undefined, WasmContinuationObject>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(WasmContinuationObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=175&c=1
  V8_EXPORT_PRIVATE void WasmContinuationObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=176&c=3
  static constexpr int kParentOffset = P::kHeaderSize;
  static constexpr int kParentOffsetEnd = kParentOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kParentOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=177&c=3
  static constexpr int kStackOffset = kParentOffsetEnd + 1;
  static constexpr int kStackOffsetEnd = kStackOffset + kExternalPointerSlotSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=178&c=3
  static constexpr int kJmpbufOffset = kStackOffsetEnd + 1;
  static constexpr int kJmpbufOffsetEnd = kJmpbufOffset + kExternalPointerSlotSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kJmpbufOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kJmpbufOffsetEnd + 1;
  static constexpr int kHeaderSize = kJmpbufOffsetEnd + 1;
  static constexpr int kSize = kJmpbufOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=175&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 24);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=175&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmContinuationObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmContinuationObject, DAlias>::value,
        "class TorqueGeneratedWasmContinuationObject should be used as direct base for WasmContinuationObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmContinuationObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmContinuationObject(Address ptr);
};

// Alias for IsWasmSuspenderObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=181&c=1
V8_EXPORT_PRIVATE bool IsWasmSuspenderObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=181&c=1
template <class D, class P>
class TorqueGeneratedWasmSuspenderObject : public P {
  static_assert(
      std::is_same<WasmSuspenderObject, D>::value,
      "Use this class as direct base for WasmSuspenderObject.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedWasmSuspenderObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmSuspenderObject<D,P>;

  // Torque type: (class Undefined | class WasmContinuationObject)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=182&c=3
  inline Tagged<Union<Undefined, WasmContinuationObject>> continuation() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=182&c=3
  inline Tagged<Union<Undefined, WasmContinuationObject>> continuation(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=182&c=3
  inline void set_continuation(Tagged<Union<Undefined, WasmContinuationObject>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class WasmSuspenderObject)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=183&c=3
  inline Tagged<Union<Undefined, WasmSuspenderObject>> parent() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=183&c=3
  inline Tagged<Union<Undefined, WasmSuspenderObject>> parent(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=183&c=3
  inline void set_parent(Tagged<Union<Undefined, WasmSuspenderObject>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=184&c=3
  inline Tagged<JSPromise> promise() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=184&c=3
  inline Tagged<JSPromise> promise(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=184&c=3
  inline void set_promise(Tagged<JSPromise> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class JSObject)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=185&c=3
  inline Tagged<Union<JSObject, Undefined>> resume() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=185&c=3
  inline Tagged<Union<JSObject, Undefined>> resume(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=185&c=3
  inline void set_resume(Tagged<Union<JSObject, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class JSObject)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=186&c=3
  inline Tagged<Union<JSObject, Undefined>> reject() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=186&c=3
  inline Tagged<Union<JSObject, Undefined>> reject(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=186&c=3
  inline void set_reject(Tagged<Union<JSObject, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=187&c=3
  inline int state() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=187&c=3
  inline void set_state(int value);

  DECL_PRINTER(WasmSuspenderObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=181&c=1
  V8_EXPORT_PRIVATE void WasmSuspenderObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=182&c=3
  static constexpr int kContinuationOffset = P::kHeaderSize;
  static constexpr int kContinuationOffsetEnd = kContinuationOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=183&c=3
  static constexpr int kParentOffset = kContinuationOffsetEnd + 1;
  static constexpr int kParentOffsetEnd = kParentOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=184&c=3
  static constexpr int kPromiseOffset = kParentOffsetEnd + 1;
  static constexpr int kPromiseOffsetEnd = kPromiseOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=185&c=3
  static constexpr int kResumeOffset = kPromiseOffsetEnd + 1;
  static constexpr int kResumeOffsetEnd = kResumeOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=186&c=3
  static constexpr int kRejectOffset = kResumeOffsetEnd + 1;
  static constexpr int kRejectOffsetEnd = kRejectOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=187&c=3
  static constexpr int kStateOffset = kRejectOffsetEnd + 1;
  static constexpr int kStateOffsetEnd = kStateOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kStateOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kStateOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kStateOffsetEnd + 1;
  static constexpr int kHeaderSize = kStateOffsetEnd + 1;
  static constexpr int kSize = kStateOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=181&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 28);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=181&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmSuspenderObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmSuspenderObject, DAlias>::value,
        "class TorqueGeneratedWasmSuspenderObject should be used as direct base for WasmSuspenderObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmSuspenderObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmSuspenderObject(Address ptr);
};

// Alias for IsWasmExceptionTag() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=190&c=1
V8_EXPORT_PRIVATE bool IsWasmExceptionTag_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=190&c=1
template <class D, class P>
class TorqueGeneratedWasmExceptionTag : public P {
  static_assert(
      std::is_same<WasmExceptionTag, D>::value,
      "Use this class as direct base for WasmExceptionTag.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedWasmExceptionTag.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmExceptionTag<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=194&c=3
  inline int index() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=194&c=3
  inline void set_index(int value);

  DECL_PRINTER(WasmExceptionTag)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=190&c=1
  V8_EXPORT_PRIVATE void WasmExceptionTagVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=194&c=3
  static constexpr int kIndexOffset = P::kHeaderSize;
  static constexpr int kIndexOffsetEnd = kIndexOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kIndexOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kIndexOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kIndexOffsetEnd + 1;
  static constexpr int kHeaderSize = kIndexOffsetEnd + 1;
  static constexpr int kSize = kIndexOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=190&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 8);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=190&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmExceptionTag() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmExceptionTag, DAlias>::value,
        "class TorqueGeneratedWasmExceptionTag should be used as direct base for WasmExceptionTag.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmExceptionTag(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmExceptionTag(Address ptr);
};

// Alias for IsWasmModuleObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=199&c=1
V8_EXPORT_PRIVATE bool IsWasmModuleObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=199&c=1
template <class D, class P>
class TorqueGeneratedWasmModuleObject : public P {
  static_assert(
      std::is_same<WasmModuleObject, D>::value,
      "Use this class as direct base for WasmModuleObject.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedWasmModuleObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmModuleObject<D,P>;

  // Torque type: ManagedWasmNativeModule
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=200&c=3
  inline Tagged<Managed<wasm::NativeModule>> managed_native_module() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=200&c=3
  inline Tagged<Managed<wasm::NativeModule>> managed_native_module(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=200&c=3
  inline void set_managed_native_module(Tagged<Managed<wasm::NativeModule>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=201&c=3
  inline Tagged<Script> script() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=201&c=3
  inline Tagged<Script> script(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=201&c=3
  inline void set_script(Tagged<Script> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(WasmModuleObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=199&c=1
  V8_EXPORT_PRIVATE void WasmModuleObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=200&c=3
  static constexpr int kManagedNativeModuleOffset = P::kHeaderSize;
  static constexpr int kManagedNativeModuleOffsetEnd = kManagedNativeModuleOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=201&c=3
  static constexpr int kScriptOffset = kManagedNativeModuleOffsetEnd + 1;
  static constexpr int kScriptOffsetEnd = kScriptOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kScriptOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kScriptOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kScriptOffsetEnd + 1;
  static constexpr int kHeaderSize = kScriptOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmModuleObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmModuleObject, DAlias>::value,
        "class TorqueGeneratedWasmModuleObject should be used as direct base for WasmModuleObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmModuleObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmModuleObject(Address ptr);
};

// Alias for IsWasmTableObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=206&c=1
V8_EXPORT_PRIVATE bool IsWasmTableObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=206&c=1
template <class D, class P>
class TorqueGeneratedWasmTableObject : public P {
  static_assert(
      std::is_same<WasmTableObject, D>::value,
      "Use this class as direct base for WasmTableObject.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedWasmTableObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmTableObject<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=215&c=3
  inline Tagged<FixedArray> entries() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=215&c=3
  inline Tagged<FixedArray> entries(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=215&c=3
  inline void set_entries(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=216&c=3
  inline int current_length() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=216&c=3
  inline void set_current_length(int value);

  // Torque type: (class Undefined | BigInt | class HeapNumber | Smi)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=221&c=3
  inline Tagged<Union<BigInt, HeapNumber, Smi, Undefined>> maximum_length() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=221&c=3
  inline Tagged<Union<BigInt, HeapNumber, Smi, Undefined>> maximum_length(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=221&c=3
  inline void set_maximum_length(Tagged<Union<BigInt, HeapNumber, Smi, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=224&c=3
  inline Tagged<FixedArray> uses() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=224&c=3
  inline Tagged<FixedArray> uses(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=224&c=3
  inline void set_uses(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=225&c=3
  inline int raw_type() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=225&c=3
  inline void set_raw_type(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=230&c=3
  inline wasm::AddressType address_type() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=230&c=3
  inline void set_address_type(wasm::AddressType value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=232&c=3
  inline uint8_t padding_for_address_type_0() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=232&c=3
  inline void set_padding_for_address_type_0(uint8_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=233&c=3
  inline uint16_t padding_for_address_type_1() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=233&c=3
  inline void set_padding_for_address_type_1(uint16_t value);

  DECL_PRINTER(WasmTableObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=206&c=1
  V8_EXPORT_PRIVATE void WasmTableObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=215&c=3
  static constexpr int kEntriesOffset = P::kHeaderSize;
  static constexpr int kEntriesOffsetEnd = kEntriesOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=216&c=3
  static constexpr int kCurrentLengthOffset = kEntriesOffsetEnd + 1;
  static constexpr int kCurrentLengthOffsetEnd = kCurrentLengthOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=221&c=3
  static constexpr int kMaximumLengthOffset = kCurrentLengthOffsetEnd + 1;
  static constexpr int kMaximumLengthOffsetEnd = kMaximumLengthOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=224&c=3
  static constexpr int kUsesOffset = kMaximumLengthOffsetEnd + 1;
  static constexpr int kUsesOffsetEnd = kUsesOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=225&c=3
  static constexpr int kRawTypeOffset = kUsesOffsetEnd + 1;
  static constexpr int kRawTypeOffsetEnd = kRawTypeOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kRawTypeOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=229&c=3
  static constexpr int kTrustedDataOffset = kRawTypeOffsetEnd + 1;
  static constexpr int kTrustedDataOffsetEnd = kTrustedDataOffset + kTrustedPointerSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=230&c=3
  static constexpr int kAddressTypeOffset = kTrustedDataOffsetEnd + 1;
  static constexpr int kAddressTypeOffsetEnd = kAddressTypeOffset + kUInt8Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=232&c=3
  static constexpr int kPaddingForAddressType0Offset = kAddressTypeOffsetEnd + 1;
  static constexpr int kPaddingForAddressType0OffsetEnd = kPaddingForAddressType0Offset + kUInt8Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=233&c=3
  static constexpr int kPaddingForAddressType1Offset = kPaddingForAddressType0OffsetEnd + 1;
  static constexpr int kPaddingForAddressType1OffsetEnd = kPaddingForAddressType1Offset + kUInt16Size - 1;
  static constexpr int kStartOfWeakFieldsOffset = kPaddingForAddressType1OffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kPaddingForAddressType1OffsetEnd + 1;
  static constexpr int kHeaderSize = kPaddingForAddressType1OffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmTableObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmTableObject, DAlias>::value,
        "class TorqueGeneratedWasmTableObject should be used as direct base for WasmTableObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmTableObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmTableObject(Address ptr);
};

// Alias for IsWasmMemoryObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=237&c=1
V8_EXPORT_PRIVATE bool IsWasmMemoryObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=237&c=1
template <class D, class P>
class TorqueGeneratedWasmMemoryObject : public P {
  static_assert(
      std::is_same<WasmMemoryObject, D>::value,
      "Use this class as direct base for WasmMemoryObject.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedWasmMemoryObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmMemoryObject<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=238&c=3
  inline Tagged<JSArrayBuffer> array_buffer() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=238&c=3
  inline Tagged<JSArrayBuffer> array_buffer(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=238&c=3
  inline void set_array_buffer(Tagged<JSArrayBuffer> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=239&c=3
  inline int maximum_pages() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=239&c=3
  inline void set_maximum_pages(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=240&c=3
  inline Tagged<WeakArrayList> instances() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=240&c=3
  inline Tagged<WeakArrayList> instances(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=240&c=3
  inline void set_instances(Tagged<WeakArrayList> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=241&c=3
  inline wasm::AddressType address_type() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=241&c=3
  inline void set_address_type(wasm::AddressType value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=243&c=3
  inline uint8_t padding_for_address_type_0() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=243&c=3
  inline void set_padding_for_address_type_0(uint8_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=244&c=3
  inline uint16_t padding_for_address_type_1() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=244&c=3
  inline void set_padding_for_address_type_1(uint16_t value);

  DECL_PRINTER(WasmMemoryObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=237&c=1
  V8_EXPORT_PRIVATE void WasmMemoryObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=238&c=3
  static constexpr int kArrayBufferOffset = P::kHeaderSize;
  static constexpr int kArrayBufferOffsetEnd = kArrayBufferOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=239&c=3
  static constexpr int kMaximumPagesOffset = kArrayBufferOffsetEnd + 1;
  static constexpr int kMaximumPagesOffsetEnd = kMaximumPagesOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=240&c=3
  static constexpr int kInstancesOffset = kMaximumPagesOffsetEnd + 1;
  static constexpr int kInstancesOffsetEnd = kInstancesOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kInstancesOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=241&c=3
  static constexpr int kAddressTypeOffset = kInstancesOffsetEnd + 1;
  static constexpr int kAddressTypeOffsetEnd = kAddressTypeOffset + kUInt8Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=243&c=3
  static constexpr int kPaddingForAddressType0Offset = kAddressTypeOffsetEnd + 1;
  static constexpr int kPaddingForAddressType0OffsetEnd = kPaddingForAddressType0Offset + kUInt8Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=244&c=3
  static constexpr int kPaddingForAddressType1Offset = kPaddingForAddressType0OffsetEnd + 1;
  static constexpr int kPaddingForAddressType1OffsetEnd = kPaddingForAddressType1Offset + kUInt16Size - 1;
  static constexpr int kStartOfWeakFieldsOffset = kPaddingForAddressType1OffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kPaddingForAddressType1OffsetEnd + 1;
  static constexpr int kHeaderSize = kPaddingForAddressType1OffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmMemoryObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmMemoryObject, DAlias>::value,
        "class TorqueGeneratedWasmMemoryObject should be used as direct base for WasmMemoryObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmMemoryObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmMemoryObject(Address ptr);
};

// Alias for IsWasmGlobalObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=248&c=1
V8_EXPORT_PRIVATE bool IsWasmGlobalObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=248&c=1
template <class D, class P>
class TorqueGeneratedWasmGlobalObject : public P {
  static_assert(
      std::is_same<WasmGlobalObject, D>::value,
      "Use this class as direct base for WasmGlobalObject.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedWasmGlobalObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmGlobalObject<D,P>;

  // Torque type: (class Undefined | class JSArrayBuffer)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=253&c=3
  inline Tagged<Union<JSArrayBuffer, Undefined>> untagged_buffer() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=253&c=3
  inline Tagged<Union<JSArrayBuffer, Undefined>> untagged_buffer(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=253&c=3
  inline void set_untagged_buffer(Tagged<Union<JSArrayBuffer, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class FixedArray)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=254&c=3
  inline Tagged<Union<FixedArray, Undefined>> tagged_buffer() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=254&c=3
  inline Tagged<Union<FixedArray, Undefined>> tagged_buffer(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=254&c=3
  inline void set_tagged_buffer(Tagged<Union<FixedArray, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=255&c=3
  inline int offset() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=255&c=3
  inline void set_offset(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=256&c=3
  inline int raw_type() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=256&c=3
  inline void set_raw_type(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=259&c=3
  inline int is_mutable() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=259&c=3
  inline void set_is_mutable(int value);

  DECL_PRINTER(WasmGlobalObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=248&c=1
  V8_EXPORT_PRIVATE void WasmGlobalObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=252&c=3
  static constexpr int kTrustedDataOffset = P::kHeaderSize;
  static constexpr int kTrustedDataOffsetEnd = kTrustedDataOffset + kTrustedPointerSize - 1;
  static constexpr int kStartOfStrongFieldsOffset = kTrustedDataOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=253&c=3
  static constexpr int kUntaggedBufferOffset = kTrustedDataOffsetEnd + 1;
  static constexpr int kUntaggedBufferOffsetEnd = kUntaggedBufferOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=254&c=3
  static constexpr int kTaggedBufferOffset = kUntaggedBufferOffsetEnd + 1;
  static constexpr int kTaggedBufferOffsetEnd = kTaggedBufferOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=255&c=3
  static constexpr int kOffsetOffset = kTaggedBufferOffsetEnd + 1;
  static constexpr int kOffsetOffsetEnd = kOffsetOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=256&c=3
  static constexpr int kRawTypeOffset = kOffsetOffsetEnd + 1;
  static constexpr int kRawTypeOffsetEnd = kRawTypeOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=259&c=3
  static constexpr int kIsMutableOffset = kRawTypeOffsetEnd + 1;
  static constexpr int kIsMutableOffsetEnd = kIsMutableOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kIsMutableOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kIsMutableOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kIsMutableOffsetEnd + 1;
  static constexpr int kHeaderSize = kIsMutableOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmGlobalObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmGlobalObject, DAlias>::value,
        "class TorqueGeneratedWasmGlobalObject should be used as direct base for WasmGlobalObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmGlobalObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmGlobalObject(Address ptr);
};

// Alias for IsWasmTagObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=262&c=1
V8_EXPORT_PRIVATE bool IsWasmTagObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=262&c=1
template <class D, class P>
class TorqueGeneratedWasmTagObject : public P {
  static_assert(
      std::is_same<WasmTagObject, D>::value,
      "Use this class as direct base for WasmTagObject.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedWasmTagObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmTagObject<D,P>;

  // Torque type: PodArrayOfWasmValueType
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=263&c=3
  inline Tagged<PodArray<wasm::ValueType>> serialized_signature() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=263&c=3
  inline Tagged<PodArray<wasm::ValueType>> serialized_signature(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=263&c=3
  inline void set_serialized_signature(Tagged<PodArray<wasm::ValueType>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=264&c=3
  inline Tagged<HeapObject> tag() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=264&c=3
  inline Tagged<HeapObject> tag(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=264&c=3
  inline void set_tag(Tagged<HeapObject> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=265&c=3
  inline int canonical_type_index() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=265&c=3
  inline void set_canonical_type_index(int value);

  DECL_PRINTER(WasmTagObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=262&c=1
  V8_EXPORT_PRIVATE void WasmTagObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=263&c=3
  static constexpr int kSerializedSignatureOffset = P::kHeaderSize;
  static constexpr int kSerializedSignatureOffsetEnd = kSerializedSignatureOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=264&c=3
  static constexpr int kTagOffset = kSerializedSignatureOffsetEnd + 1;
  static constexpr int kTagOffsetEnd = kTagOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=265&c=3
  static constexpr int kCanonicalTypeIndexOffset = kTagOffsetEnd + 1;
  static constexpr int kCanonicalTypeIndexOffsetEnd = kCanonicalTypeIndexOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCanonicalTypeIndexOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=266&c=3
  static constexpr int kTrustedDataOffset = kCanonicalTypeIndexOffsetEnd + 1;
  static constexpr int kTrustedDataOffsetEnd = kTrustedDataOffset + kTrustedPointerSize - 1;
  static constexpr int kStartOfWeakFieldsOffset = kTrustedDataOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kTrustedDataOffsetEnd + 1;
  static constexpr int kHeaderSize = kTrustedDataOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmTagObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmTagObject, DAlias>::value,
        "class TorqueGeneratedWasmTagObject should be used as direct base for WasmTagObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmTagObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmTagObject(Address ptr);
};

// Alias for IsAsmWasmData() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=271&c=1
V8_EXPORT_PRIVATE bool IsAsmWasmData_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=271&c=1
template <class D, class P>
class TorqueGeneratedAsmWasmData : public P {
  static_assert(
      std::is_same<AsmWasmData, D>::value,
      "Use this class as direct base for AsmWasmData.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedAsmWasmData.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedAsmWasmData<D,P>;

  // Torque type: ManagedWasmNativeModule
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=272&c=3
  inline Tagged<Managed<wasm::NativeModule>> managed_native_module() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=272&c=3
  inline Tagged<Managed<wasm::NativeModule>> managed_native_module(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=272&c=3
  inline void set_managed_native_module(Tagged<Managed<wasm::NativeModule>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=273&c=3
  inline Tagged<HeapNumber> uses_bitset() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=273&c=3
  inline Tagged<HeapNumber> uses_bitset(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=273&c=3
  inline void set_uses_bitset(Tagged<HeapNumber> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(AsmWasmData)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=271&c=1
  V8_EXPORT_PRIVATE void AsmWasmDataVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=272&c=3
  static constexpr int kManagedNativeModuleOffset = P::kHeaderSize;
  static constexpr int kManagedNativeModuleOffsetEnd = kManagedNativeModuleOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=273&c=3
  static constexpr int kUsesBitsetOffset = kManagedNativeModuleOffsetEnd + 1;
  static constexpr int kUsesBitsetOffsetEnd = kUsesBitsetOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kUsesBitsetOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kUsesBitsetOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kUsesBitsetOffsetEnd + 1;
  static constexpr int kHeaderSize = kUsesBitsetOffsetEnd + 1;
  static constexpr int kSize = kUsesBitsetOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=271&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=271&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedAsmWasmData() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedAsmWasmData, DAlias>::value,
        "class TorqueGeneratedAsmWasmData should be used as direct base for AsmWasmData.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedAsmWasmData(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedAsmWasmData(Address ptr);
};

// Alias for IsWasmTypeInfo() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=276&c=1
V8_EXPORT_PRIVATE bool IsWasmTypeInfo_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=276&c=1
template <class D, class P>
class TorqueGeneratedWasmTypeInfo : public P {
  static_assert(
      std::is_same<WasmTypeInfo, D>::value,
      "Use this class as direct base for WasmTypeInfo.");
  static_assert(
      std::is_same<HeapObject, P>::value,
      "Pass in HeapObject as second template parameter for TorqueGeneratedWasmTypeInfo.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmTypeInfo<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=286&c=3
  inline uint32_t module_type_index() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=286&c=3
  inline void set_module_type_index(uint32_t value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=291&c=9
  inline int supertypes_length() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=291&c=9
  inline void set_supertypes_length(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
  inline Tagged<Object> supertypes(int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
  inline Tagged<Object> supertypes(PtrComprCageBase cage_base, int i) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
  inline void set_supertypes(int i, Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(WasmTypeInfo)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=276&c=1
  V8_EXPORT_PRIVATE void WasmTypeInfoVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=285&c=3
  static constexpr int kNativeTypeOffset = P::kHeaderSize;
  static constexpr int kNativeTypeOffsetEnd = kNativeTypeOffset + kExternalPointerSlotSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=286&c=3
  static constexpr int kModuleTypeIndexOffset = kNativeTypeOffsetEnd + 1;
  static constexpr int kModuleTypeIndexOffsetEnd = kModuleTypeIndexOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=288&c=31
  static constexpr int kOptionalPaddingOffset = kModuleTypeIndexOffsetEnd + 1;
  static constexpr int kOptionalPaddingOffsetEnd = kOptionalPaddingOffset + 0 - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=290&c=3
  static constexpr int kTrustedDataOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kTrustedDataOffsetEnd = kTrustedDataOffset + kTrustedPointerSize - 1;
  static constexpr int kStartOfStrongFieldsOffset = kTrustedDataOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=291&c=9
  static constexpr int kSupertypesLengthOffset = kTrustedDataOffsetEnd + 1;
  static constexpr int kSupertypesLengthOffsetEnd = kSupertypesLengthOffset + kTaggedSize - 1;
  static constexpr int kHeaderSize = kSupertypesLengthOffsetEnd + 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=292&c=3
  static constexpr int kSupertypesOffset = kSupertypesLengthOffsetEnd + 1;
  static constexpr int kSupertypesOffsetEnd = kSupertypesOffset + 0 - 1;
  static constexpr int kEndOfStrongFieldsOffset = kSupertypesOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kSupertypesOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kSupertypesOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=276&c=1
  V8_INLINE static constexpr int32_t SizeFor(int supertypes_length) {
    int32_t size = kHeaderSize;
    size += supertypes_length * 4;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=276&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor(this->supertypes_length());
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmTypeInfo() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmTypeInfo, DAlias>::value,
        "class TorqueGeneratedWasmTypeInfo should be used as direct base for WasmTypeInfo.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmTypeInfo(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmTypeInfo(Address ptr);
};

// Alias for IsWasmObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=299&c=1
V8_EXPORT_PRIVATE bool IsWasmObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=299&c=1
template <class D, class P>
class TorqueGeneratedWasmObject : public P {
  static_assert(
      std::is_same<WasmObject, D>::value,
      "Use this class as direct base for WasmObject.");
  static_assert(
      std::is_same<JSReceiver, P>::value,
      "Pass in JSReceiver as second template parameter for TorqueGeneratedWasmObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmObject<D,P>;

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=299&c=1
  V8_EXPORT_PRIVATE void WasmObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmObject, DAlias>::value,
        "class TorqueGeneratedWasmObject should be used as direct base for WasmObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmObject(Address ptr);
};

// Alias for IsWasmStruct() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=302&c=1
V8_EXPORT_PRIVATE bool IsWasmStruct_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=302&c=1
template <class D, class P>
class TorqueGeneratedWasmStruct : public P {
  static_assert(
      std::is_same<WasmStruct, D>::value,
      "Use this class as direct base for WasmStruct.");
  static_assert(
      std::is_same<WasmObject, P>::value,
      "Pass in WasmObject as second template parameter for TorqueGeneratedWasmStruct.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmStruct<D,P>;

  DECL_PRINTER(WasmStruct)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=302&c=1
  V8_EXPORT_PRIVATE void WasmStructVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;
  static constexpr int kSize = P::kHeaderSize;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=302&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 8);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=302&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmStruct() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmStruct, DAlias>::value,
        "class TorqueGeneratedWasmStruct should be used as direct base for WasmStruct.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmStruct(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmStruct(Address ptr);
};

// Alias for IsWasmArray() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=305&c=1
V8_EXPORT_PRIVATE bool IsWasmArray_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=305&c=1
template <class D, class P>
class TorqueGeneratedWasmArray : public P {
  static_assert(
      std::is_same<WasmArray, D>::value,
      "Use this class as direct base for WasmArray.");
  static_assert(
      std::is_same<WasmObject, P>::value,
      "Pass in WasmObject as second template parameter for TorqueGeneratedWasmArray.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmArray<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=307&c=3
  inline uint32_t length() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=307&c=3
  inline void set_length(uint32_t value);

  DECL_PRINTER(WasmArray)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=305&c=1
  V8_EXPORT_PRIVATE void WasmArrayVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=307&c=3
  static constexpr int kLengthOffset = P::kHeaderSize;
  static constexpr int kLengthOffsetEnd = kLengthOffset + kInt32Size - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=310&c=31
  static constexpr int kOptionalPaddingOffset = kLengthOffsetEnd + 1;
  static constexpr int kOptionalPaddingOffsetEnd = kOptionalPaddingOffset + 0 - 1;
  static constexpr int kStartOfWeakFieldsOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kStartOfStrongFieldsOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kEndOfStrongFieldsOffset = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kHeaderSize = kOptionalPaddingOffsetEnd + 1;
  static constexpr int kSize = kOptionalPaddingOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=305&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 12);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=305&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmArray() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmArray, DAlias>::value,
        "class TorqueGeneratedWasmArray should be used as direct base for WasmArray.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmArray(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmArray(Address ptr);
};

// Alias for IsWasmSuspendingObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=326&c=1
V8_EXPORT_PRIVATE bool IsWasmSuspendingObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=326&c=1
template <class D, class P>
class TorqueGeneratedWasmSuspendingObject : public P {
  static_assert(
      std::is_same<WasmSuspendingObject, D>::value,
      "Use this class as direct base for WasmSuspendingObject.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedWasmSuspendingObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedWasmSuspendingObject<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=327&c=3
  inline Tagged<JSReceiver> callable() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=327&c=3
  inline Tagged<JSReceiver> callable(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=327&c=3
  inline void set_callable(Tagged<JSReceiver> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(WasmSuspendingObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=326&c=1
  V8_EXPORT_PRIVATE void WasmSuspendingObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/wasm/wasm-objects.tq?l=327&c=3
  static constexpr int kCallableOffset = P::kHeaderSize;
  static constexpr int kCallableOffsetEnd = kCallableOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCallableOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kCallableOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kCallableOffsetEnd + 1;
  static constexpr int kHeaderSize = kCallableOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedWasmSuspendingObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedWasmSuspendingObject, DAlias>::value,
        "class TorqueGeneratedWasmSuspendingObject should be used as direct base for WasmSuspendingObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedWasmSuspendingObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedWasmSuspendingObject(Address ptr);
};

