class JSArgumentsObject;
class JSStrictArgumentsObject;
class JSSloppyArgumentsObject;
class AliasedArgumentsEntry;
// Alias for IsJSArgumentsObject() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=5&c=1
V8_EXPORT_PRIVATE bool IsJSArgumentsObject_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=5&c=1
template <class D, class P>
class TorqueGeneratedJSArgumentsObject : public P {
  static_assert(
      std::is_same<JSArgumentsObject, D>::value,
      "Use this class as direct base for JSArgumentsObject.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSArgumentsObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSArgumentsObject<D,P>;

  DECL_PRINTER(JSArgumentsObject)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=5&c=1
  V8_EXPORT_PRIVATE void JSArgumentsObjectVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSArgumentsObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSArgumentsObject, DAlias>::value,
        "class TorqueGeneratedJSArgumentsObject should be used as direct base for JSArgumentsObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSArgumentsObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSArgumentsObject(Address ptr);
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=23&c=1
template <class D, class P>
class TorqueGeneratedJSStrictArgumentsObject : public P {
  static_assert(
      std::is_same<JSStrictArgumentsObject, D>::value,
      "Use this class as direct base for JSStrictArgumentsObject.");
  static_assert(
      std::is_same<JSArgumentsObject, P>::value,
      "Pass in JSArgumentsObject as second template parameter for TorqueGeneratedJSStrictArgumentsObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSStrictArgumentsObject<D,P>;

  // Torque type: JSAny
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=24&c=3
  inline Tagged<JSAny> length() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=24&c=3
  inline Tagged<JSAny> length(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=24&c=3
  inline void set_length(Tagged<JSAny> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSStrictArgumentsObject)


  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=24&c=3
  static constexpr int kLengthOffset = P::kHeaderSize;
  static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kLengthOffsetEnd + 1;
  static constexpr int kSize = kLengthOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSStrictArgumentsObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSStrictArgumentsObject, DAlias>::value,
        "class TorqueGeneratedJSStrictArgumentsObject should be used as direct base for JSStrictArgumentsObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSStrictArgumentsObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSStrictArgumentsObject(Address ptr);
};

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=17&c=1
template <class D, class P>
class TorqueGeneratedJSSloppyArgumentsObject : public P {
  static_assert(
      std::is_same<JSSloppyArgumentsObject, D>::value,
      "Use this class as direct base for JSSloppyArgumentsObject.");
  static_assert(
      std::is_same<JSArgumentsObject, P>::value,
      "Pass in JSArgumentsObject as second template parameter for TorqueGeneratedJSSloppyArgumentsObject.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSSloppyArgumentsObject<D,P>;

  // Torque type: JSAny
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=18&c=3
  inline Tagged<JSAny> length() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=18&c=3
  inline Tagged<JSAny> length(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=18&c=3
  inline void set_length(Tagged<JSAny> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: JSAny
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=19&c=3
  inline Tagged<JSAny> callee() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=19&c=3
  inline Tagged<JSAny> callee(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=19&c=3
  inline void set_callee(Tagged<JSAny> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSSloppyArgumentsObject)


  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=18&c=3
  static constexpr int kLengthOffset = P::kHeaderSize;
  static constexpr int kLengthOffsetEnd = kLengthOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=19&c=3
  static constexpr int kCalleeOffset = kLengthOffsetEnd + 1;
  static constexpr int kCalleeOffsetEnd = kCalleeOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kCalleeOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kCalleeOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kCalleeOffsetEnd + 1;
  static constexpr int kSize = kCalleeOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSSloppyArgumentsObject() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSSloppyArgumentsObject, DAlias>::value,
        "class TorqueGeneratedJSSloppyArgumentsObject should be used as direct base for JSSloppyArgumentsObject.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSSloppyArgumentsObject(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSSloppyArgumentsObject(Address ptr);
};

// Alias for IsAliasedArgumentsEntry() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=41&c=1
V8_EXPORT_PRIVATE bool IsAliasedArgumentsEntry_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=41&c=1
template <class D, class P>
class TorqueGeneratedAliasedArgumentsEntry : public P {
  static_assert(
      std::is_same<AliasedArgumentsEntry, D>::value,
      "Use this class as direct base for AliasedArgumentsEntry.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedAliasedArgumentsEntry.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedAliasedArgumentsEntry<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=42&c=3
  inline int aliased_context_slot() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=42&c=3
  inline void set_aliased_context_slot(int value);

  DECL_PRINTER(AliasedArgumentsEntry)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=41&c=1
  V8_EXPORT_PRIVATE void AliasedArgumentsEntryVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=42&c=3
  static constexpr int kAliasedContextSlotOffset = P::kHeaderSize;
  static constexpr int kAliasedContextSlotOffsetEnd = kAliasedContextSlotOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kAliasedContextSlotOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kAliasedContextSlotOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kAliasedContextSlotOffsetEnd + 1;
  static constexpr int kHeaderSize = kAliasedContextSlotOffsetEnd + 1;
  static constexpr int kSize = kAliasedContextSlotOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=41&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 8);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/arguments.tq?l=41&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedAliasedArgumentsEntry() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedAliasedArgumentsEntry, DAlias>::value,
        "class TorqueGeneratedAliasedArgumentsEntry should be used as direct base for AliasedArgumentsEntry.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedAliasedArgumentsEntry(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedAliasedArgumentsEntry(Address ptr);
};

