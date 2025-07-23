class JSDisposableStackBase;
class JSSyncDisposableStack;
class JSAsyncDisposableStack;
// Alias for IsJSDisposableStackBase() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=23&c=1
V8_EXPORT_PRIVATE bool IsJSDisposableStackBase_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=23&c=1
template <class D, class P>
class TorqueGeneratedJSDisposableStackBase : public P {
  static_assert(
      std::is_same<JSDisposableStackBase, D>::value,
      "Use this class as direct base for JSDisposableStackBase.");
  static_assert(
      std::is_same<JSObject, P>::value,
      "Pass in JSObject as second template parameter for TorqueGeneratedJSDisposableStackBase.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSDisposableStackBase<D,P>;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=29&c=3
  inline Tagged<FixedArray> stack() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=29&c=3
  inline Tagged<FixedArray> stack(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=29&c=3
  inline void set_stack(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=30&c=3
  inline int status() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=30&c=3
  inline void set_status(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=31&c=3
  inline Tagged<Object> error() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=31&c=3
  inline Tagged<Object> error(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=31&c=3
  inline void set_error(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(JSDisposableStackBase)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=23&c=1
  V8_EXPORT_PRIVATE void JSDisposableStackBaseVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=29&c=3
  static constexpr int kStackOffset = P::kHeaderSize;
  static constexpr int kStackOffsetEnd = kStackOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=30&c=3
  static constexpr int kStatusOffset = kStackOffsetEnd + 1;
  static constexpr int kStatusOffsetEnd = kStatusOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=31&c=3
  static constexpr int kErrorOffset = kStatusOffsetEnd + 1;
  static constexpr int kErrorOffsetEnd = kErrorOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kErrorOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kErrorOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kErrorOffsetEnd + 1;
  static constexpr int kHeaderSize = kErrorOffsetEnd + 1;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSDisposableStackBase() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSDisposableStackBase, DAlias>::value,
        "class TorqueGeneratedJSDisposableStackBase should be used as direct base for JSDisposableStackBase.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSDisposableStackBase(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSDisposableStackBase(Address ptr);
};

// Alias for IsJSSyncDisposableStack() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=34&c=1
V8_EXPORT_PRIVATE bool IsJSSyncDisposableStack_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=34&c=1
template <class D, class P>
class TorqueGeneratedJSSyncDisposableStack : public P {
  static_assert(
      std::is_same<JSSyncDisposableStack, D>::value,
      "Use this class as direct base for JSSyncDisposableStack.");
  static_assert(
      std::is_same<JSDisposableStackBase, P>::value,
      "Pass in JSDisposableStackBase as second template parameter for TorqueGeneratedJSSyncDisposableStack.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSSyncDisposableStack<D,P>;

  DECL_PRINTER(JSSyncDisposableStack)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=34&c=1
  V8_EXPORT_PRIVATE void JSSyncDisposableStackVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSSyncDisposableStack() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSSyncDisposableStack, DAlias>::value,
        "class TorqueGeneratedJSSyncDisposableStack should be used as direct base for JSSyncDisposableStack.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSSyncDisposableStack(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSSyncDisposableStack(Address ptr);
};

// Alias for IsJSAsyncDisposableStack() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=36&c=1
V8_EXPORT_PRIVATE bool IsJSAsyncDisposableStack_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=36&c=1
template <class D, class P>
class TorqueGeneratedJSAsyncDisposableStack : public P {
  static_assert(
      std::is_same<JSAsyncDisposableStack, D>::value,
      "Use this class as direct base for JSAsyncDisposableStack.");
  static_assert(
      std::is_same<JSDisposableStackBase, P>::value,
      "Pass in JSDisposableStackBase as second template parameter for TorqueGeneratedJSAsyncDisposableStack.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedJSAsyncDisposableStack<D,P>;

  DECL_PRINTER(JSAsyncDisposableStack)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-disposable-stack.tq?l=36&c=1
  V8_EXPORT_PRIVATE void JSAsyncDisposableStackVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfWeakFieldsOffset = P::kHeaderSize;
  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kEndOfStrongFieldsOffset = P::kHeaderSize;
  static constexpr int kHeaderSize = P::kHeaderSize;

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedJSAsyncDisposableStack() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedJSAsyncDisposableStack, DAlias>::value,
        "class TorqueGeneratedJSAsyncDisposableStack should be used as direct base for JSAsyncDisposableStack.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedJSAsyncDisposableStack(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedJSAsyncDisposableStack(Address ptr);
};

