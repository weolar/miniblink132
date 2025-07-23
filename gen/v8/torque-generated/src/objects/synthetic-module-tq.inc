class SyntheticModule;
// Alias for IsSyntheticModule() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsSyntheticModule_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedSyntheticModule : public P {
  static_assert(
      std::is_same<SyntheticModule, D>::value,
      "Use this class as direct base for SyntheticModule.");
  static_assert(
      std::is_same<Module, P>::value,
      "Pass in Module as second template parameter for TorqueGeneratedSyntheticModule.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedSyntheticModule<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=6&c=3
  inline Tagged<String> name() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=6&c=3
  inline Tagged<String> name(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=6&c=3
  inline void set_name(Tagged<String> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=7&c=3
  inline Tagged<FixedArray> export_names() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=7&c=3
  inline Tagged<FixedArray> export_names(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=7&c=3
  inline void set_export_names(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=8&c=3
  inline Tagged<Foreign> evaluation_steps() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=8&c=3
  inline Tagged<Foreign> evaluation_steps(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=8&c=3
  inline void set_evaluation_steps(Tagged<Foreign> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(SyntheticModule)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=5&c=1
  V8_EXPORT_PRIVATE void SyntheticModuleVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=6&c=3
  static constexpr int kNameOffset = P::kHeaderSize;
  static constexpr int kNameOffsetEnd = kNameOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=7&c=3
  static constexpr int kExportNamesOffset = kNameOffsetEnd + 1;
  static constexpr int kExportNamesOffsetEnd = kExportNamesOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=8&c=3
  static constexpr int kEvaluationStepsOffset = kExportNamesOffsetEnd + 1;
  static constexpr int kEvaluationStepsOffsetEnd = kEvaluationStepsOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kEvaluationStepsOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kEvaluationStepsOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kEvaluationStepsOffsetEnd + 1;
  static constexpr int kHeaderSize = kEvaluationStepsOffsetEnd + 1;
  static constexpr int kSize = kEvaluationStepsOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=5&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 40);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/synthetic-module.tq?l=5&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedSyntheticModule() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedSyntheticModule, DAlias>::value,
        "class TorqueGeneratedSyntheticModule should be used as direct base for SyntheticModule.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedSyntheticModule(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedSyntheticModule(Address ptr);
};

