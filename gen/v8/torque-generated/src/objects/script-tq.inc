class Script;
// Alias for IsScript() that avoids inlining.
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=19&c=1
V8_EXPORT_PRIVATE bool IsScript_NonInline(Tagged<HeapObject> o);

// Definition https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=19&c=1
template <class D, class P>
class TorqueGeneratedScript : public P {
  static_assert(
      std::is_same<Script, D>::value,
      "Use this class as direct base for Script.");
  static_assert(
      std::is_same<Struct, P>::value,
      "Pass in Struct as second template parameter for TorqueGeneratedScript.");

 public: 
  using Super = P;
  using TorqueGeneratedClass = TorqueGeneratedScript<D,P>;

  // Torque type: (class Undefined | class String)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=21&c=3
  inline Tagged<Union<String, Undefined>> source() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=21&c=3
  inline Tagged<Union<String, Undefined>> source(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=21&c=3
  inline void set_source(Tagged<Union<String, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=24&c=3
  inline Tagged<Object> name() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=24&c=3
  inline Tagged<Object> name(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=24&c=3
  inline void set_name(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=27&c=3
  inline int line_offset() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=27&c=3
  inline void set_line_offset(int value);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=31&c=3
  inline int column_offset() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=31&c=3
  inline void set_column_offset(int value);

  // Torque type: (class Undefined | class Symbol | Smi)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=34&c=3
  inline Tagged<Union<Smi, Symbol, Undefined>> context_data() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=34&c=3
  inline Tagged<Union<Smi, Symbol, Undefined>> context_data(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=34&c=3
  inline void set_context_data(Tagged<Union<Smi, Symbol, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=36&c=3
  inline int script_type() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=36&c=3
  inline void set_script_type(int value);

  // Torque type: (Smi | class FixedArray)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=39&c=3
  inline Tagged<Union<FixedArray, Smi>> line_ends() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=39&c=3
  inline Tagged<Union<FixedArray, Smi>> line_ends(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=39&c=3
  inline void set_line_ends(Tagged<Union<FixedArray, Smi>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=42&c=3
  inline int id() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=42&c=3
  inline void set_id(int value);

  // Torque type: (class Undefined | class FixedArray | class SharedFunctionInfo)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=47&c=3
  inline Tagged<Union<FixedArray, SharedFunctionInfo, Undefined>> eval_from_shared_or_wrapped_arguments() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=47&c=3
  inline Tagged<Union<FixedArray, SharedFunctionInfo, Undefined>> eval_from_shared_or_wrapped_arguments(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=47&c=3
  inline void set_eval_from_shared_or_wrapped_arguments(Tagged<Union<FixedArray, SharedFunctionInfo, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (Smi | class Foreign)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=49&c=3
  inline Tagged<Union<Foreign, Smi>> eval_from_position() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=49&c=3
  inline Tagged<Union<Foreign, Smi>> eval_from_position(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=49&c=3
  inline void set_eval_from_position(Tagged<Union<Foreign, Smi>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class WeakFixedArray | class WeakArrayList)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=50&c=3
  inline Tagged<Union<WeakArrayList, WeakFixedArray>> infos() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=50&c=3
  inline Tagged<Union<WeakArrayList, WeakFixedArray>> infos(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=50&c=3
  inline void set_infos(Tagged<Union<WeakArrayList, WeakFixedArray>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class ArrayList)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=54&c=3
  inline Tagged<Union<ArrayList, Undefined>> compiled_lazy_function_positions() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=54&c=3
  inline Tagged<Union<ArrayList, Undefined>> compiled_lazy_function_positions(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=54&c=3
  inline void set_compiled_lazy_function_positions(Tagged<Union<ArrayList, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=57&c=3
  inline int flags() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=57&c=3
  inline void set_flags(int value);

  // Torque type: (class Undefined | class String)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=60&c=3
  inline Tagged<Union<String, Undefined>> source_url() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=60&c=3
  inline Tagged<Union<String, Undefined>> source_url(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=60&c=3
  inline void set_source_url(Tagged<Union<String, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=63&c=3
  inline Tagged<Object> source_mapping_url() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=63&c=3
  inline Tagged<Object> source_mapping_url(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=63&c=3
  inline void set_source_mapping_url(Tagged<Object> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=66&c=3
  inline Tagged<FixedArray> host_defined_options() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=66&c=3
  inline Tagged<FixedArray> host_defined_options(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=66&c=3
  inline void set_host_defined_options(Tagged<FixedArray> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  // Torque type: (class Undefined | class String)
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=75&c=3
  inline Tagged<Union<String, Undefined>> source_hash() const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=75&c=3
  inline Tagged<Union<String, Undefined>> source_hash(PtrComprCageBase cage_base) const;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=75&c=3
  inline void set_source_hash(Tagged<Union<String, Undefined>> value, WriteBarrierMode mode = UPDATE_WRITE_BARRIER);

  DECL_PRINTER(Script)

#ifdef VERIFY_HEAP
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=19&c=1
  V8_EXPORT_PRIVATE void ScriptVerify(Isolate* isolate);
#endif  // VERIFY_HEAP

  static constexpr int kStartOfStrongFieldsOffset = P::kHeaderSize;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=21&c=3
  static constexpr int kSourceOffset = P::kHeaderSize;
  static constexpr int kSourceOffsetEnd = kSourceOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=24&c=3
  static constexpr int kNameOffset = kSourceOffsetEnd + 1;
  static constexpr int kNameOffsetEnd = kNameOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=27&c=3
  static constexpr int kLineOffsetOffset = kNameOffsetEnd + 1;
  static constexpr int kLineOffsetOffsetEnd = kLineOffsetOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=31&c=3
  static constexpr int kColumnOffsetOffset = kLineOffsetOffsetEnd + 1;
  static constexpr int kColumnOffsetOffsetEnd = kColumnOffsetOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=34&c=3
  static constexpr int kContextDataOffset = kColumnOffsetOffsetEnd + 1;
  static constexpr int kContextDataOffsetEnd = kContextDataOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=36&c=3
  static constexpr int kScriptTypeOffset = kContextDataOffsetEnd + 1;
  static constexpr int kScriptTypeOffsetEnd = kScriptTypeOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=39&c=3
  static constexpr int kLineEndsOffset = kScriptTypeOffsetEnd + 1;
  static constexpr int kLineEndsOffsetEnd = kLineEndsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=42&c=3
  static constexpr int kIdOffset = kLineEndsOffsetEnd + 1;
  static constexpr int kIdOffsetEnd = kIdOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=47&c=3
  static constexpr int kEvalFromSharedOrWrappedArgumentsOffset = kIdOffsetEnd + 1;
  static constexpr int kEvalFromSharedOrWrappedArgumentsOffsetEnd = kEvalFromSharedOrWrappedArgumentsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=49&c=3
  static constexpr int kEvalFromPositionOffset = kEvalFromSharedOrWrappedArgumentsOffsetEnd + 1;
  static constexpr int kEvalFromPositionOffsetEnd = kEvalFromPositionOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=50&c=3
  static constexpr int kInfosOffset = kEvalFromPositionOffsetEnd + 1;
  static constexpr int kInfosOffsetEnd = kInfosOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=54&c=3
  static constexpr int kCompiledLazyFunctionPositionsOffset = kInfosOffsetEnd + 1;
  static constexpr int kCompiledLazyFunctionPositionsOffsetEnd = kCompiledLazyFunctionPositionsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=57&c=3
  static constexpr int kFlagsOffset = kCompiledLazyFunctionPositionsOffsetEnd + 1;
  static constexpr int kFlagsOffsetEnd = kFlagsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=60&c=3
  static constexpr int kSourceUrlOffset = kFlagsOffsetEnd + 1;
  static constexpr int kSourceUrlOffsetEnd = kSourceUrlOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=63&c=3
  static constexpr int kSourceMappingUrlOffset = kSourceUrlOffsetEnd + 1;
  static constexpr int kSourceMappingUrlOffsetEnd = kSourceMappingUrlOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=66&c=3
  static constexpr int kHostDefinedOptionsOffset = kSourceMappingUrlOffsetEnd + 1;
  static constexpr int kHostDefinedOptionsOffsetEnd = kHostDefinedOptionsOffset + kTaggedSize - 1;
  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=75&c=3
  static constexpr int kSourceHashOffset = kHostDefinedOptionsOffsetEnd + 1;
  static constexpr int kSourceHashOffsetEnd = kSourceHashOffset + kTaggedSize - 1;
  static constexpr int kEndOfStrongFieldsOffset = kSourceHashOffsetEnd + 1;
  static constexpr int kStartOfWeakFieldsOffset = kSourceHashOffsetEnd + 1;
  static constexpr int kEndOfWeakFieldsOffset = kSourceHashOffsetEnd + 1;
  static constexpr int kHeaderSize = kSourceHashOffsetEnd + 1;
  static constexpr int kSize = kSourceHashOffsetEnd + 1;

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=19&c=1
  V8_INLINE static constexpr int32_t SizeFor() {
    DCHECK(kHeaderSize == kSize && kHeaderSize == 72);
    int32_t size = kHeaderSize;
    return size;
  }

  // https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/script.tq?l=19&c=1
  V8_INLINE int32_t AllocatedSize() const {
    return SizeFor();
  }

  friend class Factory;

  template <class DAlias = D>
  constexpr TorqueGeneratedScript() : P() {
    static_assert(
        std::is_base_of<TorqueGeneratedScript, DAlias>::value,
        "class TorqueGeneratedScript should be used as direct base for Script.");
  }

 protected:
  inline explicit constexpr TorqueGeneratedScript(Address ptr, typename P::SkipTypeCheckTag
)    : P(ptr, typename P::SkipTypeCheckTag{}) {}
  inline explicit TorqueGeneratedScript(Address ptr);
};

