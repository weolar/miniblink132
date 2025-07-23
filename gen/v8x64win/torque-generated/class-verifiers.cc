#ifdef VERIFY_HEAP
#include "torque-generated/class-verifiers.h"

#include "src/objects/all-objects-inl.h"

// Has to be the last include (doesn't have include guards):
#include "src/objects/object-macros.h"
namespace v8 {
namespace internal {
#include "torque-generated/test/torque/test-torque-tq-inl.inc"
void TorqueGeneratedClassVerifiers::JSReceiverVerify(Tagged<JSReceiver> o, Isolate* isolate) {
  CHECK(IsJSReceiver(o, isolate));
  {
    Tagged<Object> properties_or_hash__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, properties_or_hash__value);
    CHECK(IsSmi(properties_or_hash__value) || IsFixedArrayBase(properties_or_hash__value) || IsPropertyArray(properties_or_hash__value) || IsSwissNameDictionary(properties_or_hash__value));
  }
}
void TorqueGeneratedClassVerifiers::ContextVerify(Tagged<Context> o, Isolate* isolate) {
  CHECK(IsContext(o, isolate));
  {
    Tagged<Object> length__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, length__value);
    CHECK(IsSmi(length__value));
  }
  intptr_t elements__offset, elements__length;
  std::tie(std::ignore, elements__offset, elements__length) = TqRuntimeFieldSliceContextElements(o);
  CHECK_EQ(elements__offset, static_cast<int>(elements__offset));
  CHECK_EQ(elements__length, static_cast<int>(elements__length));
  for (int i = 0; i < static_cast<int>(elements__length); ++i) {
    Tagged<Object> elements__value = TaggedField<Object>::load(o, static_cast<int>(elements__offset) + i * kTaggedSize);
    Object::VerifyPointer(isolate, elements__value);
  }
}
void TorqueGeneratedClassVerifiers::JSObjectVerify(Tagged<JSObject> o, Isolate* isolate) {
  o->JSReceiverVerify(isolate);
  CHECK(IsJSObject(o, isolate));
  {
    Tagged<Object> elements__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, elements__value);
    CHECK(IsFixedArrayBase(elements__value));
  }
}
void TorqueGeneratedClassVerifiers::JSObjectWithEmbedderSlotsVerify(Tagged<JSObjectWithEmbedderSlots> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSObjectWithEmbedderSlots(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSPromiseVerify(Tagged<JSPromise> o, Isolate* isolate) {
  o->JSObjectWithEmbedderSlotsVerify(isolate);
  CHECK(IsJSPromise(o, isolate));
  {
    Tagged<Object> reactions_or_result__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, reactions_or_result__value);
    CHECK(IsJSReceiver(reactions_or_result__value) || IsUndefined(reactions_or_result__value) || IsNull(reactions_or_result__value) || IsBoolean(reactions_or_result__value) || IsSymbol(reactions_or_result__value) || IsString(reactions_or_result__value) || IsBigInt(reactions_or_result__value) || IsHeapNumber(reactions_or_result__value) || IsSmi(reactions_or_result__value) || IsPromiseReaction(reactions_or_result__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::JSFunctionOrBoundFunctionOrWrappedFunctionVerify(Tagged<JSFunctionOrBoundFunctionOrWrappedFunction> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSFunctionOrBoundFunctionOrWrappedFunction(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSFunctionVerify(Tagged<JSFunction> o, Isolate* isolate) {
  o->JSFunctionOrBoundFunctionOrWrappedFunctionVerify(isolate);
  CHECK(IsJSFunction(o, isolate));
  {
    Tagged<Object> shared_function_info__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, shared_function_info__value);
    CHECK(IsSharedFunctionInfo(shared_function_info__value));
  }
  {
    Tagged<Object> context__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, context__value);
    CHECK(IsContext(context__value));
  }
  {
    Tagged<Object> feedback_cell__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, feedback_cell__value);
    CHECK(IsFeedbackCell(feedback_cell__value));
  }
  {
    Tagged<Object> prototype_or_initial_map__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, prototype_or_initial_map__value);
    CHECK(IsJSReceiver(prototype_or_initial_map__value) || IsMap(prototype_or_initial_map__value));
  }
}
void TorqueGeneratedClassVerifiers::ForeignVerify(Tagged<Foreign> o, Isolate* isolate) {
  CHECK(IsForeign(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSProxyVerify(Tagged<JSProxy> o, Isolate* isolate) {
  o->JSReceiverVerify(isolate);
  CHECK(IsJSProxy(o, isolate));
  {
    Tagged<Object> target__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, target__value);
    CHECK(IsJSReceiver(target__value) || IsNull(target__value));
  }
  {
    Tagged<Object> handler__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, handler__value);
    CHECK(IsJSReceiver(handler__value) || IsNull(handler__value));
  }
}
void TorqueGeneratedClassVerifiers::JSWrappedFunctionVerify(Tagged<JSWrappedFunction> o, Isolate* isolate) {
  o->JSFunctionOrBoundFunctionOrWrappedFunctionVerify(isolate);
  CHECK(IsJSWrappedFunction(o, isolate));
  {
    Tagged<Object> wrapped_target_function__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, wrapped_target_function__value);
    CHECK(IsJSFunction(wrapped_target_function__value) || IsCallableApiObject(wrapped_target_function__value) || IsCallableJSProxy(wrapped_target_function__value) || IsJSWrappedFunction(wrapped_target_function__value) || IsJSBoundFunction(wrapped_target_function__value));
  }
  {
    Tagged<Object> context__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, context__value);
    CHECK(IsNativeContext(context__value));
  }
}
void TorqueGeneratedClassVerifiers::JSBoundFunctionVerify(Tagged<JSBoundFunction> o, Isolate* isolate) {
  o->JSFunctionOrBoundFunctionOrWrappedFunctionVerify(isolate);
  CHECK(IsJSBoundFunction(o, isolate));
  {
    Tagged<Object> bound_target_function__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, bound_target_function__value);
    CHECK(IsJSFunction(bound_target_function__value) || IsCallableApiObject(bound_target_function__value) || IsCallableJSProxy(bound_target_function__value) || IsJSWrappedFunction(bound_target_function__value) || IsJSBoundFunction(bound_target_function__value));
  }
  {
    Tagged<Object> bound_this__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, bound_this__value);
    CHECK(IsJSReceiver(bound_this__value) || IsUndefined(bound_this__value) || IsNull(bound_this__value) || IsBoolean(bound_this__value) || IsSymbol(bound_this__value) || IsString(bound_this__value) || IsBigInt(bound_this__value) || IsHeapNumber(bound_this__value) || IsSmi(bound_this__value) || IsSourceTextModule(bound_this__value));
  }
  {
    Tagged<Object> bound_arguments__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, bound_arguments__value);
    CHECK(IsFixedArray(bound_arguments__value));
  }
}
void TorqueGeneratedClassVerifiers::JSAPIObjectWithEmbedderSlotsVerify(Tagged<JSAPIObjectWithEmbedderSlots> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSAPIObjectWithEmbedderSlots(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSCustomElementsObjectVerify(Tagged<JSCustomElementsObject> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSCustomElementsObject(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSSpecialObjectVerify(Tagged<JSSpecialObject> o, Isolate* isolate) {
  o->JSCustomElementsObjectVerify(isolate);
  CHECK(IsJSSpecialObject(o, isolate));
}
void TorqueGeneratedClassVerifiers::WasmNullVerify(Tagged<WasmNull> o, Isolate* isolate) {
  CHECK(IsWasmNull(o, isolate));
}
void TorqueGeneratedClassVerifiers::WasmFuncRefVerify(Tagged<WasmFuncRef> o, Isolate* isolate) {
  CHECK(IsWasmFuncRef(o, isolate));
}
void TorqueGeneratedClassVerifiers::TemplateInfoVerify(Tagged<TemplateInfo> o, Isolate* isolate) {
  CHECK(IsTemplateInfo(o, isolate));
  {
    Tagged<Object> serial_number__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, serial_number__value);
    CHECK(IsSmi(serial_number__value));
  }
  {
    Tagged<Object> number_of_properties__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, number_of_properties__value);
    CHECK(IsSmi(number_of_properties__value));
  }
  {
    Tagged<Object> property_list__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, property_list__value);
    CHECK(IsUndefined(property_list__value) || IsArrayList(property_list__value));
  }
  {
    Tagged<Object> property_accessors__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, property_accessors__value);
    CHECK(IsUndefined(property_accessors__value) || IsArrayList(property_accessors__value));
  }
}
void TorqueGeneratedClassVerifiers::FunctionTemplateInfoVerify(Tagged<FunctionTemplateInfo> o, Isolate* isolate) {
  o->TemplateInfoVerify(isolate);
  CHECK(IsFunctionTemplateInfo(o, isolate));
  {
    Tagged<Object> class_name__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, class_name__value);
    CHECK(IsUndefined(class_name__value) || IsString(class_name__value));
  }
  {
    Tagged<Object> interface_name__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, interface_name__value);
    CHECK(IsUndefined(interface_name__value) || IsString(interface_name__value));
  }
  {
    Tagged<Object> signature__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, signature__value);
    CHECK(IsUndefined(signature__value) || IsFunctionTemplateInfo(signature__value));
  }
  {
    Tagged<Object> rare_data__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, rare_data__value);
    CHECK(IsUndefined(rare_data__value) || IsFunctionTemplateRareData(rare_data__value));
  }
  {
    Tagged<Object> shared_function_info__value = TaggedField<Object>::load(o, 36);
    Object::VerifyPointer(isolate, shared_function_info__value);
    CHECK(IsUndefined(shared_function_info__value) || IsSharedFunctionInfo(shared_function_info__value));
  }
  {
    Tagged<Object> cached_property_name__value = TaggedField<Object>::load(o, 40);
    Object::VerifyPointer(isolate, cached_property_name__value);
  }
  {
    Tagged<Object> callback_data__value = TaggedField<Object>::load(o, 44);
    Object::VerifyPointer(isolate, callback_data__value);
  }
}
void TorqueGeneratedClassVerifiers::WeakCellVerify(Tagged<WeakCell> o, Isolate* isolate) {
  CHECK(IsWeakCell(o, isolate));
  {
    Tagged<Object> finalization_registry__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, finalization_registry__value);
    CHECK(IsUndefined(finalization_registry__value) || IsJSFinalizationRegistry(finalization_registry__value));
  }
  {
    Tagged<Object> target__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, target__value);
    CHECK(IsJSReceiver(target__value) || IsUndefined(target__value) || IsSymbol(target__value));
  }
  {
    Tagged<Object> unregister_token__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, unregister_token__value);
    CHECK(IsJSReceiver(unregister_token__value) || IsUndefined(unregister_token__value) || IsSymbol(unregister_token__value));
  }
  {
    Tagged<Object> holdings__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, holdings__value);
    CHECK(IsJSReceiver(holdings__value) || IsUndefined(holdings__value) || IsNull(holdings__value) || IsBoolean(holdings__value) || IsSymbol(holdings__value) || IsString(holdings__value) || IsBigInt(holdings__value) || IsHeapNumber(holdings__value) || IsSmi(holdings__value));
  }
  {
    Tagged<Object> prev__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, prev__value);
    CHECK(IsUndefined(prev__value) || IsWeakCell(prev__value));
  }
  {
    Tagged<Object> next__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, next__value);
    CHECK(IsUndefined(next__value) || IsWeakCell(next__value));
  }
  {
    Tagged<Object> key_list_prev__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, key_list_prev__value);
    CHECK(IsUndefined(key_list_prev__value) || IsWeakCell(key_list_prev__value));
  }
  {
    Tagged<Object> key_list_next__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, key_list_next__value);
    CHECK(IsUndefined(key_list_next__value) || IsWeakCell(key_list_next__value));
  }
}
void TorqueGeneratedClassVerifiers::MapVerify(Tagged<Map> o, Isolate* isolate) {
  CHECK(IsMap(o, isolate));
  {
    Tagged<Object> prototype__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, prototype__value);
    CHECK(IsJSReceiver(prototype__value) || IsNull(prototype__value));
  }
  {
    Tagged<Object> constructor_or_back_pointer_or_native_context__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, constructor_or_back_pointer_or_native_context__value);
  }
  {
    Tagged<Object> instance_descriptors__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, instance_descriptors__value);
    CHECK(IsDescriptorArray(instance_descriptors__value));
  }
  {
    Tagged<Object> dependent_code__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, dependent_code__value);
    CHECK(IsDependentCode(dependent_code__value));
  }
  {
    Tagged<Object> prototype_validity_cell__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, prototype_validity_cell__value);
    CHECK(IsZero(prototype_validity_cell__value) || IsCell(prototype_validity_cell__value));
  }
  {
    Tagged<MaybeObject> transitions_or_prototype_info__value = TaggedField<MaybeObject>::load(o, 36);
    Object::VerifyMaybeObjectPointer(isolate, transitions_or_prototype_info__value);
    CHECK(transitions_or_prototype_info__value.IsCleared() || (!transitions_or_prototype_info__value.IsWeak() && IsZero(transitions_or_prototype_info__value.GetHeapObjectOrSmi())) || (!transitions_or_prototype_info__value.IsWeak() && IsTransitionArray(transitions_or_prototype_info__value.GetHeapObjectOrSmi())) || (!transitions_or_prototype_info__value.IsWeak() && IsMap(transitions_or_prototype_info__value.GetHeapObjectOrSmi())) || (transitions_or_prototype_info__value.IsWeak() && IsMap(transitions_or_prototype_info__value.GetHeapObjectOrSmi())) || (!transitions_or_prototype_info__value.IsWeak() && IsPrototypeInfo(transitions_or_prototype_info__value.GetHeapObjectOrSmi())));
  }
}
void TorqueGeneratedClassVerifiers::JSCollectionVerify(Tagged<JSCollection> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSCollection(o, isolate));
  {
    Tagged<Object> table__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, table__value);
  }
}
void TorqueGeneratedClassVerifiers::JSSetVerify(Tagged<JSSet> o, Isolate* isolate) {
  o->JSCollectionVerify(isolate);
  CHECK(IsJSSet(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSMapVerify(Tagged<JSMap> o, Isolate* isolate) {
  o->JSCollectionVerify(isolate);
  CHECK(IsJSMap(o, isolate));
}
void TorqueGeneratedClassVerifiers::StructVerify(Tagged<Struct> o, Isolate* isolate) {
  CHECK(IsStruct(o, isolate));
}
void TorqueGeneratedClassVerifiers::PromiseCapabilityVerify(Tagged<PromiseCapability> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsPromiseCapability(o, isolate));
  {
    Tagged<Object> promise__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, promise__value);
    CHECK(IsJSReceiver(promise__value) || IsUndefined(promise__value));
  }
  {
    Tagged<Object> resolve__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, resolve__value);
    CHECK(IsJSReceiver(resolve__value) || IsUndefined(resolve__value) || IsNull(resolve__value) || IsBoolean(resolve__value) || IsSymbol(resolve__value) || IsString(resolve__value) || IsBigInt(resolve__value) || IsHeapNumber(resolve__value) || IsSmi(resolve__value));
  }
  {
    Tagged<Object> reject__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, reject__value);
    CHECK(IsJSReceiver(reject__value) || IsUndefined(reject__value) || IsNull(reject__value) || IsBoolean(reject__value) || IsSymbol(reject__value) || IsString(reject__value) || IsBigInt(reject__value) || IsHeapNumber(reject__value) || IsSmi(reject__value));
  }
}
void TorqueGeneratedClassVerifiers::JSArrayBufferViewVerify(Tagged<JSArrayBufferView> o, Isolate* isolate) {
  o->JSAPIObjectWithEmbedderSlotsVerify(isolate);
  CHECK(IsJSArrayBufferView(o, isolate));
  {
    Tagged<Object> buffer__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, buffer__value);
    CHECK(IsJSArrayBuffer(buffer__value));
  }
}
void TorqueGeneratedClassVerifiers::JSTypedArrayVerify(Tagged<JSTypedArray> o, Isolate* isolate) {
  o->JSArrayBufferViewVerify(isolate);
  CHECK(IsJSTypedArray(o, isolate));
  {
    Tagged<Object> base_pointer__value = TaggedField<Object>::load(o, 56);
    Object::VerifyPointer(isolate, base_pointer__value);
    CHECK(IsSmi(base_pointer__value) || IsByteArray(base_pointer__value));
  }
}
void TorqueGeneratedClassVerifiers::DataHandlerVerify(Tagged<DataHandler> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsDataHandler(o, isolate));
  {
    Tagged<Object> smi_handler__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, smi_handler__value);
    CHECK(IsSmi(smi_handler__value) || IsCode(smi_handler__value));
  }
  {
    Tagged<Object> validity_cell__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, validity_cell__value);
    CHECK(IsSmi(validity_cell__value) || IsCell(validity_cell__value));
  }
  {
    Tagged<MaybeObject> data1__value = TaggedField<MaybeObject>::load(o, 12);
    Object::VerifyMaybeObjectPointer(isolate, data1__value);
    CHECK(data1__value.IsCleared() || (!data1__value.IsWeak() && IsHeapObject(data1__value.GetHeapObjectOrSmi())) || (!data1__value.IsWeak() && IsSmi(data1__value.GetHeapObjectOrSmi())) || data1__value.IsWeak());
  }
  {
    Tagged<MaybeObject> data2__value = TaggedField<MaybeObject>::load(o, 16);
    Object::VerifyMaybeObjectPointer(isolate, data2__value);
    CHECK(data2__value.IsCleared() || (!data2__value.IsWeak() && IsHeapObject(data2__value.GetHeapObjectOrSmi())) || (!data2__value.IsWeak() && IsSmi(data2__value.GetHeapObjectOrSmi())) || data2__value.IsWeak());
  }
  {
    Tagged<MaybeObject> data3__value = TaggedField<MaybeObject>::load(o, 20);
    Object::VerifyMaybeObjectPointer(isolate, data3__value);
    CHECK(data3__value.IsCleared() || (!data3__value.IsWeak() && IsHeapObject(data3__value.GetHeapObjectOrSmi())) || (!data3__value.IsWeak() && IsSmi(data3__value.GetHeapObjectOrSmi())) || data3__value.IsWeak());
  }
}
void TorqueGeneratedClassVerifiers::AllocationMementoVerify(Tagged<AllocationMemento> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsAllocationMemento(o, isolate));
  {
    Tagged<Object> allocation_site__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, allocation_site__value);
    CHECK(IsAllocationSite(allocation_site__value));
  }
}
void TorqueGeneratedClassVerifiers::InterceptorInfoVerify(Tagged<InterceptorInfo> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsInterceptorInfo(o, isolate));
  {
    Tagged<Object> getter__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, getter__value);
    CHECK(IsUndefined(getter__value) || IsZero(getter__value) || IsNonNullForeign(getter__value));
  }
  {
    Tagged<Object> setter__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, setter__value);
    CHECK(IsUndefined(setter__value) || IsZero(setter__value) || IsNonNullForeign(setter__value));
  }
  {
    Tagged<Object> query__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, query__value);
    CHECK(IsUndefined(query__value) || IsZero(query__value) || IsNonNullForeign(query__value));
  }
  {
    Tagged<Object> descriptor__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, descriptor__value);
    CHECK(IsUndefined(descriptor__value) || IsZero(descriptor__value) || IsNonNullForeign(descriptor__value));
  }
  {
    Tagged<Object> deleter__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, deleter__value);
    CHECK(IsUndefined(deleter__value) || IsZero(deleter__value) || IsNonNullForeign(deleter__value));
  }
  {
    Tagged<Object> enumerator__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, enumerator__value);
    CHECK(IsUndefined(enumerator__value) || IsZero(enumerator__value) || IsNonNullForeign(enumerator__value));
  }
  {
    Tagged<Object> definer__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, definer__value);
    CHECK(IsUndefined(definer__value) || IsZero(definer__value) || IsNonNullForeign(definer__value));
  }
  {
    Tagged<Object> data__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, data__value);
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 36);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::AccessCheckInfoVerify(Tagged<AccessCheckInfo> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsAccessCheckInfo(o, isolate));
  {
    Tagged<Object> callback__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, callback__value);
    CHECK(IsUndefined(callback__value) || IsZero(callback__value) || IsForeign(callback__value));
  }
  {
    Tagged<Object> named_interceptor__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, named_interceptor__value);
    CHECK(IsUndefined(named_interceptor__value) || IsZero(named_interceptor__value) || IsInterceptorInfo(named_interceptor__value));
  }
  {
    Tagged<Object> indexed_interceptor__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, indexed_interceptor__value);
    CHECK(IsUndefined(indexed_interceptor__value) || IsZero(indexed_interceptor__value) || IsInterceptorInfo(indexed_interceptor__value));
  }
  {
    Tagged<Object> data__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, data__value);
  }
}
void TorqueGeneratedClassVerifiers::AccessorInfoVerify(Tagged<AccessorInfo> o, Isolate* isolate) {
  CHECK(IsAccessorInfo(o, isolate));
  {
    Tagged<Object> name__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, name__value);
    CHECK(IsName(name__value));
  }
  {
    Tagged<Object> data__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, data__value);
  }
}
void TorqueGeneratedClassVerifiers::JSArgumentsObjectVerify(Tagged<JSArgumentsObject> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSArgumentsObject(o, isolate));
}
void TorqueGeneratedClassVerifiers::AliasedArgumentsEntryVerify(Tagged<AliasedArgumentsEntry> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsAliasedArgumentsEntry(o, isolate));
  {
    Tagged<Object> aliased_context_slot__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, aliased_context_slot__value);
    CHECK(IsSmi(aliased_context_slot__value));
  }
}
void TorqueGeneratedClassVerifiers::CallSiteInfoVerify(Tagged<CallSiteInfo> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsCallSiteInfo(o, isolate));
  {
    Tagged<Object> receiver_or_instance__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, receiver_or_instance__value);
    CHECK(IsJSReceiver(receiver_or_instance__value) || IsUndefined(receiver_or_instance__value) || IsNull(receiver_or_instance__value) || IsBoolean(receiver_or_instance__value) || IsSymbol(receiver_or_instance__value) || IsString(receiver_or_instance__value) || IsBigInt(receiver_or_instance__value) || IsHeapNumber(receiver_or_instance__value) || IsSmi(receiver_or_instance__value));
  }
  {
    Tagged<Object> function__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, function__value);
    CHECK(IsSmi(function__value) || IsJSFunction(function__value));
  }
  {
    Tagged<Object> code_offset_or_source_position__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, code_offset_or_source_position__value);
    CHECK(IsSmi(code_offset_or_source_position__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
  {
    Tagged<Object> parameters__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, parameters__value);
    CHECK(IsFixedArray(parameters__value));
  }
}
void TorqueGeneratedClassVerifiers::CellVerify(Tagged<Cell> o, Isolate* isolate) {
  CHECK(IsCell(o, isolate));
  {
    Tagged<Object> value__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, value__value);
  }
}
void TorqueGeneratedClassVerifiers::WeakArrayListVerify(Tagged<WeakArrayList> o, Isolate* isolate) {
  CHECK(IsWeakArrayList(o, isolate));
  {
    Tagged<Object> capacity__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, capacity__value);
    CHECK(IsSmi(capacity__value));
  }
  {
    Tagged<Object> length__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, length__value);
    CHECK(IsSmi(length__value));
  }
  intptr_t objects__offset, objects__length;
  std::tie(std::ignore, objects__offset, objects__length) = TqRuntimeFieldSliceWeakArrayListObjects(o);
  CHECK_EQ(objects__offset, static_cast<int>(objects__offset));
  CHECK_EQ(objects__length, static_cast<int>(objects__length));
  for (int i = 0; i < static_cast<int>(objects__length); ++i) {
    Tagged<MaybeObject> objects__value = TaggedField<MaybeObject>::load(o, static_cast<int>(objects__offset) + i * kTaggedSize);
    Object::VerifyMaybeObjectPointer(isolate, objects__value);
    CHECK(objects__value.IsCleared() || (!objects__value.IsWeak() && IsHeapObject(objects__value.GetHeapObjectOrSmi())) || (!objects__value.IsWeak() && IsSmi(objects__value.GetHeapObjectOrSmi())) || objects__value.IsWeak());
  }
}
void TorqueGeneratedClassVerifiers::ScopeInfoVerify(Tagged<ScopeInfo> o, Isolate* isolate) {
  CHECK(IsScopeInfo(o, isolate));
  {
    Tagged<Object> parameter_count__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, parameter_count__value);
    CHECK(IsSmi(parameter_count__value));
  }
  {
    Tagged<Object> context_local_count__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, context_local_count__value);
    CHECK(IsSmi(context_local_count__value));
  }
  {
    Tagged<Object> start__value = TaggedField<Object>::load(o, 16 + 0);
    Object::VerifyPointer(isolate, start__value);
    CHECK(IsSmi(start__value));
    Tagged<Object> end__value = TaggedField<Object>::load(o, 16 + 4);
    Object::VerifyPointer(isolate, end__value);
    CHECK(IsSmi(end__value));
  }
  intptr_t module_variable_count__offset, module_variable_count__length;
  std::tie(std::ignore, module_variable_count__offset, module_variable_count__length) = TqRuntimeFieldSliceScopeInfoModuleVariableCount(o);
  CHECK_EQ(module_variable_count__offset, static_cast<int>(module_variable_count__offset));
  CHECK_EQ(module_variable_count__length, static_cast<int>(module_variable_count__length));
  for (int i = 0; i < static_cast<int>(module_variable_count__length); ++i) {
    Tagged<Object> module_variable_count__value = TaggedField<Object>::load(o, static_cast<int>(module_variable_count__offset) + i * kTaggedSize);
    Object::VerifyPointer(isolate, module_variable_count__value);
    CHECK(IsSmi(module_variable_count__value));
  }
  intptr_t context_local_names__offset, context_local_names__length;
  std::tie(std::ignore, context_local_names__offset, context_local_names__length) = TqRuntimeFieldSliceScopeInfoContextLocalNames(o);
  CHECK_EQ(context_local_names__offset, static_cast<int>(context_local_names__offset));
  CHECK_EQ(context_local_names__length, static_cast<int>(context_local_names__length));
  for (int i = 0; i < static_cast<int>(context_local_names__length); ++i) {
    Tagged<Object> context_local_names__value = TaggedField<Object>::load(o, static_cast<int>(context_local_names__offset) + i * kTaggedSize);
    Object::VerifyPointer(isolate, context_local_names__value);
    CHECK(IsString(context_local_names__value));
  }
  intptr_t context_local_names_hashtable__offset, context_local_names_hashtable__length;
  std::tie(std::ignore, context_local_names_hashtable__offset, context_local_names_hashtable__length) = TqRuntimeFieldSliceScopeInfoContextLocalNamesHashtable(o);
  CHECK_EQ(context_local_names_hashtable__offset, static_cast<int>(context_local_names_hashtable__offset));
  CHECK_EQ(context_local_names_hashtable__length, static_cast<int>(context_local_names_hashtable__length));
  for (int i = 0; i < static_cast<int>(context_local_names_hashtable__length); ++i) {
    Tagged<Object> context_local_names_hashtable__value = TaggedField<Object>::load(o, static_cast<int>(context_local_names_hashtable__offset) + i * kTaggedSize);
    Object::VerifyPointer(isolate, context_local_names_hashtable__value);
    CHECK(IsNameToIndexHashTable(context_local_names_hashtable__value));
  }
  intptr_t context_local_infos__offset, context_local_infos__length;
  std::tie(std::ignore, context_local_infos__offset, context_local_infos__length) = TqRuntimeFieldSliceScopeInfoContextLocalInfos(o);
  CHECK_EQ(context_local_infos__offset, static_cast<int>(context_local_infos__offset));
  CHECK_EQ(context_local_infos__length, static_cast<int>(context_local_infos__length));
  for (int i = 0; i < static_cast<int>(context_local_infos__length); ++i) {
    Tagged<Object> context_local_infos__value = TaggedField<Object>::load(o, static_cast<int>(context_local_infos__offset) + i * kTaggedSize);
    Object::VerifyPointer(isolate, context_local_infos__value);
    CHECK(IsSmi(context_local_infos__value));
  }
  intptr_t saved_class_variable_info__offset, saved_class_variable_info__length;
  std::tie(std::ignore, saved_class_variable_info__offset, saved_class_variable_info__length) = TqRuntimeFieldSliceScopeInfoSavedClassVariableInfo(o);
  CHECK_EQ(saved_class_variable_info__offset, static_cast<int>(saved_class_variable_info__offset));
  CHECK_EQ(saved_class_variable_info__length, static_cast<int>(saved_class_variable_info__length));
  for (int i = 0; i < static_cast<int>(saved_class_variable_info__length); ++i) {
    Tagged<Object> saved_class_variable_info__value = TaggedField<Object>::load(o, static_cast<int>(saved_class_variable_info__offset) + i * kTaggedSize);
    Object::VerifyPointer(isolate, saved_class_variable_info__value);
    CHECK(IsSmi(saved_class_variable_info__value));
  }
  intptr_t function_variable_info__offset, function_variable_info__length;
  std::tie(std::ignore, function_variable_info__offset, function_variable_info__length) = TqRuntimeFieldSliceScopeInfoFunctionVariableInfo(o);
  CHECK_EQ(function_variable_info__offset, static_cast<int>(function_variable_info__offset));
  CHECK_EQ(function_variable_info__length, static_cast<int>(function_variable_info__length));
  for (int i = 0; i < static_cast<int>(function_variable_info__length); ++i) {
    Tagged<Object> name__value = TaggedField<Object>::load(o, static_cast<int>(function_variable_info__offset) + 0 + i * 8);
    Object::VerifyPointer(isolate, name__value);
    CHECK(IsString(name__value) || IsZero(name__value));
    Tagged<Object> context_or_stack_slot_index__value = TaggedField<Object>::load(o, static_cast<int>(function_variable_info__offset) + 4 + i * 8);
    Object::VerifyPointer(isolate, context_or_stack_slot_index__value);
    CHECK(IsSmi(context_or_stack_slot_index__value));
  }
  intptr_t inferred_function_name__offset, inferred_function_name__length;
  std::tie(std::ignore, inferred_function_name__offset, inferred_function_name__length) = TqRuntimeFieldSliceScopeInfoInferredFunctionName(o);
  CHECK_EQ(inferred_function_name__offset, static_cast<int>(inferred_function_name__offset));
  CHECK_EQ(inferred_function_name__length, static_cast<int>(inferred_function_name__length));
  for (int i = 0; i < static_cast<int>(inferred_function_name__length); ++i) {
    Tagged<Object> inferred_function_name__value = TaggedField<Object>::load(o, static_cast<int>(inferred_function_name__offset) + i * kTaggedSize);
    Object::VerifyPointer(isolate, inferred_function_name__value);
    CHECK(IsUndefined(inferred_function_name__value) || IsString(inferred_function_name__value));
  }
  intptr_t outer_scope_info__offset, outer_scope_info__length;
  std::tie(std::ignore, outer_scope_info__offset, outer_scope_info__length) = TqRuntimeFieldSliceScopeInfoOuterScopeInfo(o);
  CHECK_EQ(outer_scope_info__offset, static_cast<int>(outer_scope_info__offset));
  CHECK_EQ(outer_scope_info__length, static_cast<int>(outer_scope_info__length));
  for (int i = 0; i < static_cast<int>(outer_scope_info__length); ++i) {
    Tagged<Object> outer_scope_info__value = TaggedField<Object>::load(o, static_cast<int>(outer_scope_info__offset) + i * kTaggedSize);
    Object::VerifyPointer(isolate, outer_scope_info__value);
    CHECK(IsTheHole(outer_scope_info__value) || IsScopeInfo(outer_scope_info__value));
  }
  intptr_t module_info__offset, module_info__length;
  std::tie(std::ignore, module_info__offset, module_info__length) = TqRuntimeFieldSliceScopeInfoModuleInfo(o);
  CHECK_EQ(module_info__offset, static_cast<int>(module_info__offset));
  CHECK_EQ(module_info__length, static_cast<int>(module_info__length));
  for (int i = 0; i < static_cast<int>(module_info__length); ++i) {
    Tagged<Object> module_info__value = TaggedField<Object>::load(o, static_cast<int>(module_info__offset) + i * kTaggedSize);
    Object::VerifyPointer(isolate, module_info__value);
    CHECK(IsSourceTextModuleInfo(module_info__value));
  }
  intptr_t module_variables__offset, module_variables__length;
  std::tie(std::ignore, module_variables__offset, module_variables__length) = TqRuntimeFieldSliceScopeInfoModuleVariables(o);
  CHECK_EQ(module_variables__offset, static_cast<int>(module_variables__offset));
  CHECK_EQ(module_variables__length, static_cast<int>(module_variables__length));
  for (int i = 0; i < static_cast<int>(module_variables__length); ++i) {
    Tagged<Object> name__value = TaggedField<Object>::load(o, static_cast<int>(module_variables__offset) + 0 + i * 12);
    Object::VerifyPointer(isolate, name__value);
    CHECK(IsString(name__value));
    Tagged<Object> index__value = TaggedField<Object>::load(o, static_cast<int>(module_variables__offset) + 4 + i * 12);
    Object::VerifyPointer(isolate, index__value);
    CHECK(IsSmi(index__value));
    Tagged<Object> properties__value = TaggedField<Object>::load(o, static_cast<int>(module_variables__offset) + 8 + i * 12);
    Object::VerifyPointer(isolate, properties__value);
    CHECK(IsSmi(properties__value));
  }
}
void TorqueGeneratedClassVerifiers::BreakPointVerify(Tagged<BreakPoint> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsBreakPoint(o, isolate));
  {
    Tagged<Object> id__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, id__value);
    CHECK(IsSmi(id__value));
  }
  {
    Tagged<Object> condition__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, condition__value);
    CHECK(IsString(condition__value));
  }
}
void TorqueGeneratedClassVerifiers::BreakPointInfoVerify(Tagged<BreakPointInfo> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsBreakPointInfo(o, isolate));
  {
    Tagged<Object> source_position__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, source_position__value);
    CHECK(IsSmi(source_position__value));
  }
  {
    Tagged<Object> break_points__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, break_points__value);
    CHECK(IsUndefined(break_points__value) || IsFixedArray(break_points__value) || IsBreakPoint(break_points__value));
  }
}
void TorqueGeneratedClassVerifiers::DebugInfoVerify(Tagged<DebugInfo> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsDebugInfo(o, isolate));
  {
    Tagged<Object> shared__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, shared__value);
    CHECK(IsSharedFunctionInfo(shared__value));
  }
  {
    Tagged<Object> debugger_hints__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, debugger_hints__value);
    CHECK(IsSmi(debugger_hints__value));
  }
  {
    Tagged<Object> break_points__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, break_points__value);
    CHECK(IsFixedArray(break_points__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
  {
    Tagged<Object> coverage_info__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, coverage_info__value);
    CHECK(IsUndefined(coverage_info__value) || IsCoverageInfo(coverage_info__value));
  }
}
void TorqueGeneratedClassVerifiers::CoverageInfoVerify(Tagged<CoverageInfo> o, Isolate* isolate) {
  CHECK(IsCoverageInfo(o, isolate));
  intptr_t slots__offset, slots__length;
  std::tie(std::ignore, slots__offset, slots__length) = TqRuntimeFieldSliceCoverageInfoSlots(o);
  CHECK_EQ(slots__offset, static_cast<int>(slots__offset));
  CHECK_EQ(slots__length, static_cast<int>(slots__length));
  for (int i = 0; i < static_cast<int>(slots__length); ++i) {
  }
}
void TorqueGeneratedClassVerifiers::StackFrameInfoVerify(Tagged<StackFrameInfo> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsStackFrameInfo(o, isolate));
  {
    Tagged<Object> shared_or_script__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, shared_or_script__value);
    CHECK(IsScript(shared_or_script__value) || IsSharedFunctionInfo(shared_or_script__value));
  }
  {
    Tagged<Object> function_name__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, function_name__value);
    CHECK(IsString(function_name__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::StackTraceInfoVerify(Tagged<StackTraceInfo> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsStackTraceInfo(o, isolate));
  {
    Tagged<Object> id__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, id__value);
    CHECK(IsSmi(id__value));
  }
  {
    Tagged<Object> frames__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, frames__value);
    CHECK(IsFixedArray(frames__value));
  }
}
void TorqueGeneratedClassVerifiers::ErrorStackDataVerify(Tagged<ErrorStackData> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsErrorStackData(o, isolate));
  {
    Tagged<Object> call_site_infos_or_formatted_stack__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, call_site_infos_or_formatted_stack__value);
    CHECK(IsJSReceiver(call_site_infos_or_formatted_stack__value) || IsUndefined(call_site_infos_or_formatted_stack__value) || IsNull(call_site_infos_or_formatted_stack__value) || IsBoolean(call_site_infos_or_formatted_stack__value) || IsSymbol(call_site_infos_or_formatted_stack__value) || IsString(call_site_infos_or_formatted_stack__value) || IsBigInt(call_site_infos_or_formatted_stack__value) || IsHeapNumber(call_site_infos_or_formatted_stack__value) || IsSmi(call_site_infos_or_formatted_stack__value) || IsFixedArray(call_site_infos_or_formatted_stack__value));
  }
  {
    Tagged<Object> stack_trace__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, stack_trace__value);
    CHECK(IsStackTraceInfo(stack_trace__value));
  }
}
void TorqueGeneratedClassVerifiers::EnumCacheVerify(Tagged<EnumCache> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsEnumCache(o, isolate));
  {
    Tagged<Object> keys__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, keys__value);
    CHECK(IsFixedArray(keys__value));
  }
  {
    Tagged<Object> indices__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, indices__value);
    CHECK(IsFixedArray(indices__value));
  }
}
void TorqueGeneratedClassVerifiers::ClassPositionsVerify(Tagged<ClassPositions> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsClassPositions(o, isolate));
  {
    Tagged<Object> start__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, start__value);
    CHECK(IsSmi(start__value));
  }
  {
    Tagged<Object> end__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, end__value);
    CHECK(IsSmi(end__value));
  }
}
void TorqueGeneratedClassVerifiers::AccessorPairVerify(Tagged<AccessorPair> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsAccessorPair(o, isolate));
  {
    Tagged<Object> getter__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, getter__value);
  }
  {
    Tagged<Object> setter__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, setter__value);
  }
}
void TorqueGeneratedClassVerifiers::DescriptorArrayVerify(Tagged<DescriptorArray> o, Isolate* isolate) {
  CHECK(IsDescriptorArray(o, isolate));
  {
    Tagged<Object> enum_cache__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, enum_cache__value);
    CHECK(IsEnumCache(enum_cache__value));
  }
  intptr_t descriptors__offset, descriptors__length;
  std::tie(std::ignore, descriptors__offset, descriptors__length) = TqRuntimeFieldSliceDescriptorArrayDescriptors(o);
  CHECK_EQ(descriptors__offset, static_cast<int>(descriptors__offset));
  CHECK_EQ(descriptors__length, static_cast<int>(descriptors__length));
  for (int i = 0; i < static_cast<int>(descriptors__length); ++i) {
    Tagged<Object> key__value = TaggedField<Object>::load(o, static_cast<int>(descriptors__offset) + 0 + i * 12);
    Object::VerifyPointer(isolate, key__value);
    CHECK(IsUndefined(key__value) || IsName(key__value));
    Tagged<Object> details__value = TaggedField<Object>::load(o, static_cast<int>(descriptors__offset) + 4 + i * 12);
    Object::VerifyPointer(isolate, details__value);
    CHECK(IsUndefined(details__value) || IsSmi(details__value));
    Tagged<MaybeObject> value__value = TaggedField<MaybeObject>::load(o, static_cast<int>(descriptors__offset) + 8 + i * 12);
    Object::VerifyMaybeObjectPointer(isolate, value__value);
    CHECK(value__value.IsCleared() || (!value__value.IsWeak() && IsJSReceiver(value__value.GetHeapObjectOrSmi())) || (!value__value.IsWeak() && IsUndefined(value__value.GetHeapObjectOrSmi())) || (!value__value.IsWeak() && IsNull(value__value.GetHeapObjectOrSmi())) || (!value__value.IsWeak() && IsBoolean(value__value.GetHeapObjectOrSmi())) || (!value__value.IsWeak() && IsSymbol(value__value.GetHeapObjectOrSmi())) || (!value__value.IsWeak() && IsString(value__value.GetHeapObjectOrSmi())) || (!value__value.IsWeak() && IsBigInt(value__value.GetHeapObjectOrSmi())) || (!value__value.IsWeak() && IsHeapNumber(value__value.GetHeapObjectOrSmi())) || (!value__value.IsWeak() && IsSmi(value__value.GetHeapObjectOrSmi())) || (!value__value.IsWeak() && IsNumberDictionary(value__value.GetHeapObjectOrSmi())) || (!value__value.IsWeak() && IsAccessorInfo(value__value.GetHeapObjectOrSmi())) || (!value__value.IsWeak() && IsClassPositions(value__value.GetHeapObjectOrSmi())) || (!value__value.IsWeak() && IsAccessorPair(value__value.GetHeapObjectOrSmi())) || (value__value.IsWeak() && IsMap(value__value.GetHeapObjectOrSmi())));
  }
}
void TorqueGeneratedClassVerifiers::StrongDescriptorArrayVerify(Tagged<StrongDescriptorArray> o, Isolate* isolate) {
  o->DescriptorArrayVerify(isolate);
  CHECK(IsStrongDescriptorArray(o, isolate));
}
void TorqueGeneratedClassVerifiers::EmbedderDataArrayVerify(Tagged<EmbedderDataArray> o, Isolate* isolate) {
  CHECK(IsEmbedderDataArray(o, isolate));
  {
    Tagged<Object> length__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, length__value);
    CHECK(IsSmi(length__value));
  }
}
void TorqueGeneratedClassVerifiers::FeedbackCellVerify(Tagged<FeedbackCell> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsFeedbackCell(o, isolate));
  {
    Tagged<Object> value__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, value__value);
    CHECK(IsUndefined(value__value) || IsClosureFeedbackCellArray(value__value) || IsFeedbackVector(value__value));
  }
}
void TorqueGeneratedClassVerifiers::FeedbackVectorVerify(Tagged<FeedbackVector> o, Isolate* isolate) {
  CHECK(IsFeedbackVector(o, isolate));
  {
    Tagged<Object> shared_function_info__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, shared_function_info__value);
    CHECK(IsSharedFunctionInfo(shared_function_info__value));
  }
  {
    Tagged<Object> closure_feedback_cell_array__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, closure_feedback_cell_array__value);
    CHECK(IsClosureFeedbackCellArray(closure_feedback_cell_array__value));
  }
  {
    Tagged<Object> parent_feedback_cell__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, parent_feedback_cell__value);
    CHECK(IsFeedbackCell(parent_feedback_cell__value));
  }
  {
    Tagged<MaybeObject> maybe_optimized_code__value = TaggedField<MaybeObject>::load(o, 28);
    Object::VerifyMaybeObjectPointer(isolate, maybe_optimized_code__value);
    CHECK(maybe_optimized_code__value.IsCleared() || (maybe_optimized_code__value.IsWeak() && IsCodeWrapper(maybe_optimized_code__value.GetHeapObjectOrSmi())));
  }
  intptr_t raw_feedback_slots__offset, raw_feedback_slots__length;
  std::tie(std::ignore, raw_feedback_slots__offset, raw_feedback_slots__length) = TqRuntimeFieldSliceFeedbackVectorRawFeedbackSlots(o);
  CHECK_EQ(raw_feedback_slots__offset, static_cast<int>(raw_feedback_slots__offset));
  CHECK_EQ(raw_feedback_slots__length, static_cast<int>(raw_feedback_slots__length));
  for (int i = 0; i < static_cast<int>(raw_feedback_slots__length); ++i) {
    Tagged<MaybeObject> raw_feedback_slots__value = TaggedField<MaybeObject>::load(o, static_cast<int>(raw_feedback_slots__offset) + i * kTaggedSize);
    Object::VerifyMaybeObjectPointer(isolate, raw_feedback_slots__value);
    CHECK(raw_feedback_slots__value.IsCleared() || (!raw_feedback_slots__value.IsWeak() && IsHeapObject(raw_feedback_slots__value.GetHeapObjectOrSmi())) || (!raw_feedback_slots__value.IsWeak() && IsSmi(raw_feedback_slots__value.GetHeapObjectOrSmi())) || raw_feedback_slots__value.IsWeak());
  }
}
void TorqueGeneratedClassVerifiers::TrustedForeignVerify(Tagged<TrustedForeign> o, Isolate* isolate) {
  CHECK(IsTrustedForeign(o, isolate));
}
void TorqueGeneratedClassVerifiers::FreeSpaceVerify(Tagged<FreeSpace> o, Isolate* isolate) {
  CHECK(IsFreeSpace(o, isolate));
  {
    Tagged<Object> size__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, size__value);
    CHECK(IsSmi(size__value));
  }
}
void TorqueGeneratedClassVerifiers::JSArrayBufferVerify(Tagged<JSArrayBuffer> o, Isolate* isolate) {
  o->JSAPIObjectWithEmbedderSlotsVerify(isolate);
  CHECK(IsJSArrayBuffer(o, isolate));
  {
    Tagged<Object> detach_key__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, detach_key__value);
  }
}
void TorqueGeneratedClassVerifiers::JSDataViewOrRabGsabDataViewVerify(Tagged<JSDataViewOrRabGsabDataView> o, Isolate* isolate) {
  o->JSArrayBufferViewVerify(isolate);
  CHECK(IsJSDataViewOrRabGsabDataView(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSDataViewVerify(Tagged<JSDataView> o, Isolate* isolate) {
  o->JSDataViewOrRabGsabDataViewVerify(isolate);
  CHECK(IsJSDataView(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSRabGsabDataViewVerify(Tagged<JSRabGsabDataView> o, Isolate* isolate) {
  o->JSDataViewOrRabGsabDataViewVerify(isolate);
  CHECK(IsJSRabGsabDataView(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSArrayIteratorVerify(Tagged<JSArrayIterator> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSArrayIterator(o, isolate));
  {
    Tagged<Object> iterated_object__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, iterated_object__value);
    CHECK(IsJSReceiver(iterated_object__value));
  }
  {
    Tagged<Object> next_index__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, next_index__value);
    CHECK(IsHeapNumber(next_index__value) || IsSmi(next_index__value));
  }
  {
    Tagged<Object> kind__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, kind__value);
    CHECK(IsSmi(kind__value));
  }
}
void TorqueGeneratedClassVerifiers::JSArrayVerify(Tagged<JSArray> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSArray(o, isolate));
  {
    Tagged<Object> length__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, length__value);
    CHECK(IsHeapNumber(length__value) || IsSmi(length__value));
  }
}
void TorqueGeneratedClassVerifiers::TemplateLiteralObjectVerify(Tagged<TemplateLiteralObject> o, Isolate* isolate) {
  o->JSArrayVerify(isolate);
  CHECK(IsTemplateLiteralObject(o, isolate));
  {
    Tagged<Object> raw__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, raw__value);
    CHECK(IsJSArray(raw__value));
  }
  {
    Tagged<Object> function_literal_id__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, function_literal_id__value);
    CHECK(IsSmi(function_literal_id__value));
  }
  {
    Tagged<Object> slot_id__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, slot_id__value);
    CHECK(IsSmi(slot_id__value));
  }
}
void TorqueGeneratedClassVerifiers::AlwaysSharedSpaceJSObjectVerify(Tagged<AlwaysSharedSpaceJSObject> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsAlwaysSharedSpaceJSObject(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSSynchronizationPrimitiveVerify(Tagged<JSSynchronizationPrimitive> o, Isolate* isolate) {
  o->AlwaysSharedSpaceJSObjectVerify(isolate);
  CHECK(IsJSSynchronizationPrimitive(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSAtomicsMutexVerify(Tagged<JSAtomicsMutex> o, Isolate* isolate) {
  o->JSSynchronizationPrimitiveVerify(isolate);
  CHECK(IsJSAtomicsMutex(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSAtomicsConditionVerify(Tagged<JSAtomicsCondition> o, Isolate* isolate) {
  o->JSSynchronizationPrimitiveVerify(isolate);
  CHECK(IsJSAtomicsCondition(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSCollectionIteratorVerify(Tagged<JSCollectionIterator> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSCollectionIterator(o, isolate));
  {
    Tagged<Object> table__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, table__value);
  }
  {
    Tagged<Object> index__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, index__value);
  }
}
void TorqueGeneratedClassVerifiers::JSWeakCollectionVerify(Tagged<JSWeakCollection> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSWeakCollection(o, isolate));
  {
    Tagged<Object> table__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, table__value);
  }
}
void TorqueGeneratedClassVerifiers::JSWeakSetVerify(Tagged<JSWeakSet> o, Isolate* isolate) {
  o->JSWeakCollectionVerify(isolate);
  CHECK(IsJSWeakSet(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSWeakMapVerify(Tagged<JSWeakMap> o, Isolate* isolate) {
  o->JSWeakCollectionVerify(isolate);
  CHECK(IsJSWeakMap(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSDisposableStackBaseVerify(Tagged<JSDisposableStackBase> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSDisposableStackBase(o, isolate));
  {
    Tagged<Object> stack__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, stack__value);
    CHECK(IsFixedArray(stack__value));
  }
  {
    Tagged<Object> status__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, status__value);
    CHECK(IsSmi(status__value));
  }
  {
    Tagged<Object> error__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, error__value);
  }
}
void TorqueGeneratedClassVerifiers::JSSyncDisposableStackVerify(Tagged<JSSyncDisposableStack> o, Isolate* isolate) {
  o->JSDisposableStackBaseVerify(isolate);
  CHECK(IsJSSyncDisposableStack(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSAsyncDisposableStackVerify(Tagged<JSAsyncDisposableStack> o, Isolate* isolate) {
  o->JSDisposableStackBaseVerify(isolate);
  CHECK(IsJSAsyncDisposableStack(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSGeneratorObjectVerify(Tagged<JSGeneratorObject> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSGeneratorObject(o, isolate));
  {
    Tagged<Object> function__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, function__value);
    CHECK(IsJSFunction(function__value));
  }
  {
    Tagged<Object> context__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, context__value);
    CHECK(IsContext(context__value));
  }
  {
    Tagged<Object> receiver__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, receiver__value);
    CHECK(IsJSReceiver(receiver__value) || IsUndefined(receiver__value) || IsNull(receiver__value) || IsBoolean(receiver__value) || IsSymbol(receiver__value) || IsString(receiver__value) || IsBigInt(receiver__value) || IsHeapNumber(receiver__value) || IsSmi(receiver__value));
  }
  {
    Tagged<Object> input_or_debug_pos__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, input_or_debug_pos__value);
  }
  {
    Tagged<Object> resume_mode__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, resume_mode__value);
    CHECK(IsSmi(resume_mode__value));
  }
  {
    Tagged<Object> continuation__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, continuation__value);
    CHECK(IsSmi(continuation__value));
  }
  {
    Tagged<Object> parameters_and_registers__value = TaggedField<Object>::load(o, 36);
    Object::VerifyPointer(isolate, parameters_and_registers__value);
    CHECK(IsFixedArray(parameters_and_registers__value));
  }
}
void TorqueGeneratedClassVerifiers::JSAsyncFunctionObjectVerify(Tagged<JSAsyncFunctionObject> o, Isolate* isolate) {
  o->JSGeneratorObjectVerify(isolate);
  CHECK(IsJSAsyncFunctionObject(o, isolate));
  {
    Tagged<Object> promise__value = TaggedField<Object>::load(o, 40);
    Object::VerifyPointer(isolate, promise__value);
    CHECK(IsJSPromise(promise__value));
  }
}
void TorqueGeneratedClassVerifiers::JSAsyncGeneratorObjectVerify(Tagged<JSAsyncGeneratorObject> o, Isolate* isolate) {
  o->JSGeneratorObjectVerify(isolate);
  CHECK(IsJSAsyncGeneratorObject(o, isolate));
  {
    Tagged<Object> queue__value = TaggedField<Object>::load(o, 40);
    Object::VerifyPointer(isolate, queue__value);
    CHECK(IsHeapObject(queue__value));
  }
  {
    Tagged<Object> is_awaiting__value = TaggedField<Object>::load(o, 44);
    Object::VerifyPointer(isolate, is_awaiting__value);
    CHECK(IsSmi(is_awaiting__value));
  }
}
void TorqueGeneratedClassVerifiers::AsyncGeneratorRequestVerify(Tagged<AsyncGeneratorRequest> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsAsyncGeneratorRequest(o, isolate));
  {
    Tagged<Object> next__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, next__value);
    CHECK(IsUndefined(next__value) || IsAsyncGeneratorRequest(next__value));
  }
  {
    Tagged<Object> resume_mode__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, resume_mode__value);
    CHECK(IsSmi(resume_mode__value));
  }
  {
    Tagged<Object> value__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, value__value);
  }
  {
    Tagged<Object> promise__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, promise__value);
    CHECK(IsJSPromise(promise__value));
  }
}
void TorqueGeneratedClassVerifiers::JSIteratorHelperVerify(Tagged<JSIteratorHelper> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSIteratorHelper(o, isolate));
  {
    Tagged<Object> underlying_object__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, underlying_object__value);
    CHECK(IsJSReceiver(underlying_object__value) || IsUndefined(underlying_object__value) || IsNull(underlying_object__value));
  }
  {
    Tagged<Object> underlying_next__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, underlying_next__value);
    CHECK(IsJSReceiver(underlying_next__value) || IsUndefined(underlying_next__value) || IsNull(underlying_next__value) || IsBoolean(underlying_next__value) || IsSymbol(underlying_next__value) || IsString(underlying_next__value) || IsBigInt(underlying_next__value) || IsHeapNumber(underlying_next__value) || IsSmi(underlying_next__value));
  }
}
void TorqueGeneratedClassVerifiers::JSIteratorMapHelperVerify(Tagged<JSIteratorMapHelper> o, Isolate* isolate) {
  o->JSIteratorHelperVerify(isolate);
  CHECK(IsJSIteratorMapHelper(o, isolate));
  {
    Tagged<Object> mapper__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, mapper__value);
    CHECK(IsJSFunction(mapper__value) || IsCallableApiObject(mapper__value) || IsCallableJSProxy(mapper__value) || IsJSWrappedFunction(mapper__value) || IsJSBoundFunction(mapper__value));
  }
  {
    Tagged<Object> counter__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, counter__value);
    CHECK(IsHeapNumber(counter__value) || IsSmi(counter__value));
  }
}
void TorqueGeneratedClassVerifiers::JSIteratorFilterHelperVerify(Tagged<JSIteratorFilterHelper> o, Isolate* isolate) {
  o->JSIteratorHelperVerify(isolate);
  CHECK(IsJSIteratorFilterHelper(o, isolate));
  {
    Tagged<Object> predicate__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, predicate__value);
    CHECK(IsJSFunction(predicate__value) || IsCallableApiObject(predicate__value) || IsCallableJSProxy(predicate__value) || IsJSWrappedFunction(predicate__value) || IsJSBoundFunction(predicate__value));
  }
  {
    Tagged<Object> counter__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, counter__value);
    CHECK(IsHeapNumber(counter__value) || IsSmi(counter__value));
  }
}
void TorqueGeneratedClassVerifiers::JSIteratorTakeHelperVerify(Tagged<JSIteratorTakeHelper> o, Isolate* isolate) {
  o->JSIteratorHelperVerify(isolate);
  CHECK(IsJSIteratorTakeHelper(o, isolate));
  {
    Tagged<Object> remaining__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, remaining__value);
    CHECK(IsHeapNumber(remaining__value) || IsSmi(remaining__value));
  }
}
void TorqueGeneratedClassVerifiers::JSIteratorDropHelperVerify(Tagged<JSIteratorDropHelper> o, Isolate* isolate) {
  o->JSIteratorHelperVerify(isolate);
  CHECK(IsJSIteratorDropHelper(o, isolate));
  {
    Tagged<Object> remaining__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, remaining__value);
    CHECK(IsHeapNumber(remaining__value) || IsSmi(remaining__value));
  }
}
void TorqueGeneratedClassVerifiers::JSIteratorFlatMapHelperVerify(Tagged<JSIteratorFlatMapHelper> o, Isolate* isolate) {
  o->JSIteratorHelperVerify(isolate);
  CHECK(IsJSIteratorFlatMapHelper(o, isolate));
  {
    Tagged<Object> mapper__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, mapper__value);
    CHECK(IsJSFunction(mapper__value) || IsCallableApiObject(mapper__value) || IsCallableJSProxy(mapper__value) || IsJSWrappedFunction(mapper__value) || IsJSBoundFunction(mapper__value));
  }
  {
    Tagged<Object> counter__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, counter__value);
    CHECK(IsHeapNumber(counter__value) || IsSmi(counter__value));
  }
  {
    Tagged<Object> object__value = TaggedField<Object>::load(o, 28 + 0);
    Object::VerifyPointer(isolate, object__value);
    CHECK(IsJSReceiver(object__value));
    Tagged<Object> next__value = TaggedField<Object>::load(o, 28 + 4);
    Object::VerifyPointer(isolate, next__value);
    CHECK(IsJSReceiver(next__value) || IsUndefined(next__value) || IsNull(next__value) || IsBoolean(next__value) || IsSymbol(next__value) || IsString(next__value) || IsBigInt(next__value) || IsHeapNumber(next__value) || IsSmi(next__value));
  }
  {
    Tagged<Object> innerAlive__value = TaggedField<Object>::load(o, 36);
    Object::VerifyPointer(isolate, innerAlive__value);
    CHECK(IsBoolean(innerAlive__value));
  }
}
void TorqueGeneratedClassVerifiers::JSExternalObjectVerify(Tagged<JSExternalObject> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSExternalObject(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSGlobalProxyVerify(Tagged<JSGlobalProxy> o, Isolate* isolate) {
  o->JSSpecialObjectVerify(isolate);
  CHECK(IsJSGlobalProxy(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSGlobalObjectVerify(Tagged<JSGlobalObject> o, Isolate* isolate) {
  o->JSSpecialObjectVerify(isolate);
  CHECK(IsJSGlobalObject(o, isolate));
  {
    Tagged<Object> global_proxy__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, global_proxy__value);
    CHECK(IsJSGlobalProxy(global_proxy__value));
  }
}
void TorqueGeneratedClassVerifiers::JSPrimitiveWrapperVerify(Tagged<JSPrimitiveWrapper> o, Isolate* isolate) {
  o->JSCustomElementsObjectVerify(isolate);
  CHECK(IsJSPrimitiveWrapper(o, isolate));
  {
    Tagged<Object> value__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, value__value);
    CHECK(IsJSReceiver(value__value) || IsUndefined(value__value) || IsNull(value__value) || IsBoolean(value__value) || IsSymbol(value__value) || IsString(value__value) || IsBigInt(value__value) || IsHeapNumber(value__value) || IsSmi(value__value));
  }
}
void TorqueGeneratedClassVerifiers::JSMessageObjectVerify(Tagged<JSMessageObject> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSMessageObject(o, isolate));
  {
    Tagged<Object> message_type__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, message_type__value);
    CHECK(IsSmi(message_type__value));
  }
  {
    Tagged<Object> argument__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, argument__value);
  }
  {
    Tagged<Object> script__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, script__value);
    CHECK(IsScript(script__value));
  }
  {
    Tagged<Object> stack_trace__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, stack_trace__value);
    CHECK(IsTheHole(stack_trace__value) || IsStackTraceInfo(stack_trace__value));
  }
  {
    Tagged<Object> shared_info__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, shared_info__value);
    CHECK(IsSmi(shared_info__value) || IsSharedFunctionInfo(shared_info__value));
  }
  {
    Tagged<Object> bytecode_offset__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, bytecode_offset__value);
    CHECK(IsSmi(bytecode_offset__value));
  }
  {
    Tagged<Object> start_position__value = TaggedField<Object>::load(o, 36);
    Object::VerifyPointer(isolate, start_position__value);
    CHECK(IsSmi(start_position__value));
  }
  {
    Tagged<Object> end_position__value = TaggedField<Object>::load(o, 40);
    Object::VerifyPointer(isolate, end_position__value);
    CHECK(IsSmi(end_position__value));
  }
  {
    Tagged<Object> error_level__value = TaggedField<Object>::load(o, 44);
    Object::VerifyPointer(isolate, error_level__value);
    CHECK(IsSmi(error_level__value));
  }
}
void TorqueGeneratedClassVerifiers::JSDateVerify(Tagged<JSDate> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSDate(o, isolate));
  {
    Tagged<Object> year__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, year__value);
    CHECK(IsUndefined(year__value) || IsSmi(year__value) || IsNaN(year__value));
  }
  {
    Tagged<Object> month__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, month__value);
    CHECK(IsUndefined(month__value) || IsSmi(month__value) || IsNaN(month__value));
  }
  {
    Tagged<Object> day__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, day__value);
    CHECK(IsUndefined(day__value) || IsSmi(day__value) || IsNaN(day__value));
  }
  {
    Tagged<Object> weekday__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, weekday__value);
    CHECK(IsUndefined(weekday__value) || IsSmi(weekday__value) || IsNaN(weekday__value));
  }
  {
    Tagged<Object> hour__value = TaggedField<Object>::load(o, 36);
    Object::VerifyPointer(isolate, hour__value);
    CHECK(IsUndefined(hour__value) || IsSmi(hour__value) || IsNaN(hour__value));
  }
  {
    Tagged<Object> min__value = TaggedField<Object>::load(o, 40);
    Object::VerifyPointer(isolate, min__value);
    CHECK(IsUndefined(min__value) || IsSmi(min__value) || IsNaN(min__value));
  }
  {
    Tagged<Object> sec__value = TaggedField<Object>::load(o, 44);
    Object::VerifyPointer(isolate, sec__value);
    CHECK(IsUndefined(sec__value) || IsSmi(sec__value) || IsNaN(sec__value));
  }
  {
    Tagged<Object> cache_stamp__value = TaggedField<Object>::load(o, 48);
    Object::VerifyPointer(isolate, cache_stamp__value);
    CHECK(IsUndefined(cache_stamp__value) || IsSmi(cache_stamp__value) || IsNaN(cache_stamp__value));
  }
}
void TorqueGeneratedClassVerifiers::JSAsyncFromSyncIteratorVerify(Tagged<JSAsyncFromSyncIterator> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSAsyncFromSyncIterator(o, isolate));
  {
    Tagged<Object> sync_iterator__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, sync_iterator__value);
    CHECK(IsJSReceiver(sync_iterator__value));
  }
  {
    Tagged<Object> next__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, next__value);
  }
}
void TorqueGeneratedClassVerifiers::JSStringIteratorVerify(Tagged<JSStringIterator> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSStringIterator(o, isolate));
  {
    Tagged<Object> string__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, string__value);
    CHECK(IsString(string__value));
  }
  {
    Tagged<Object> index__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, index__value);
    CHECK(IsSmi(index__value));
  }
}
void TorqueGeneratedClassVerifiers::JSValidIteratorWrapperVerify(Tagged<JSValidIteratorWrapper> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSValidIteratorWrapper(o, isolate));
  {
    Tagged<Object> object__value = TaggedField<Object>::load(o, 12 + 0);
    Object::VerifyPointer(isolate, object__value);
    CHECK(IsJSReceiver(object__value));
    Tagged<Object> next__value = TaggedField<Object>::load(o, 12 + 4);
    Object::VerifyPointer(isolate, next__value);
    CHECK(IsJSReceiver(next__value) || IsUndefined(next__value) || IsNull(next__value) || IsBoolean(next__value) || IsSymbol(next__value) || IsString(next__value) || IsBigInt(next__value) || IsHeapNumber(next__value) || IsSmi(next__value));
  }
}
void TorqueGeneratedClassVerifiers::JSRawJsonVerify(Tagged<JSRawJson> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSRawJson(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSRegExpStringIteratorVerify(Tagged<JSRegExpStringIterator> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSRegExpStringIterator(o, isolate));
  {
    Tagged<Object> iterating_reg_exp__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, iterating_reg_exp__value);
    CHECK(IsJSReceiver(iterating_reg_exp__value));
  }
  {
    Tagged<Object> iterated_string__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, iterated_string__value);
    CHECK(IsString(iterated_string__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::JSRegExpVerify(Tagged<JSRegExp> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSRegExp(o, isolate));
  {
    Tagged<Object> source__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, source__value);
    CHECK(IsUndefined(source__value) || IsString(source__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsUndefined(flags__value) || IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::JSShadowRealmVerify(Tagged<JSShadowRealm> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSShadowRealm(o, isolate));
  {
    Tagged<Object> native_context__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, native_context__value);
    CHECK(IsNativeContext(native_context__value));
  }
}
void TorqueGeneratedClassVerifiers::JSSharedArrayVerify(Tagged<JSSharedArray> o, Isolate* isolate) {
  o->AlwaysSharedSpaceJSObjectVerify(isolate);
  CHECK(IsJSSharedArray(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSSharedStructVerify(Tagged<JSSharedStruct> o, Isolate* isolate) {
  o->AlwaysSharedSpaceJSObjectVerify(isolate);
  CHECK(IsJSSharedStruct(o, isolate));
}
void TorqueGeneratedClassVerifiers::JSTemporalCalendarVerify(Tagged<JSTemporalCalendar> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSTemporalCalendar(o, isolate));
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::JSTemporalDurationVerify(Tagged<JSTemporalDuration> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSTemporalDuration(o, isolate));
  {
    Tagged<Object> years__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, years__value);
    CHECK(IsHeapNumber(years__value) || IsSmi(years__value));
  }
  {
    Tagged<Object> months__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, months__value);
    CHECK(IsHeapNumber(months__value) || IsSmi(months__value));
  }
  {
    Tagged<Object> weeks__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, weeks__value);
    CHECK(IsHeapNumber(weeks__value) || IsSmi(weeks__value));
  }
  {
    Tagged<Object> days__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, days__value);
    CHECK(IsHeapNumber(days__value) || IsSmi(days__value));
  }
  {
    Tagged<Object> hours__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, hours__value);
    CHECK(IsHeapNumber(hours__value) || IsSmi(hours__value));
  }
  {
    Tagged<Object> minutes__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, minutes__value);
    CHECK(IsHeapNumber(minutes__value) || IsSmi(minutes__value));
  }
  {
    Tagged<Object> seconds__value = TaggedField<Object>::load(o, 36);
    Object::VerifyPointer(isolate, seconds__value);
    CHECK(IsHeapNumber(seconds__value) || IsSmi(seconds__value));
  }
  {
    Tagged<Object> milliseconds__value = TaggedField<Object>::load(o, 40);
    Object::VerifyPointer(isolate, milliseconds__value);
    CHECK(IsHeapNumber(milliseconds__value) || IsSmi(milliseconds__value));
  }
  {
    Tagged<Object> microseconds__value = TaggedField<Object>::load(o, 44);
    Object::VerifyPointer(isolate, microseconds__value);
    CHECK(IsHeapNumber(microseconds__value) || IsSmi(microseconds__value));
  }
  {
    Tagged<Object> nanoseconds__value = TaggedField<Object>::load(o, 48);
    Object::VerifyPointer(isolate, nanoseconds__value);
    CHECK(IsHeapNumber(nanoseconds__value) || IsSmi(nanoseconds__value));
  }
}
void TorqueGeneratedClassVerifiers::JSTemporalInstantVerify(Tagged<JSTemporalInstant> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSTemporalInstant(o, isolate));
  {
    Tagged<Object> nanoseconds__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, nanoseconds__value);
    CHECK(IsBigInt(nanoseconds__value));
  }
}
void TorqueGeneratedClassVerifiers::JSTemporalPlainDateTimeVerify(Tagged<JSTemporalPlainDateTime> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSTemporalPlainDateTime(o, isolate));
  {
    Tagged<Object> year_month_day__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, year_month_day__value);
    CHECK(IsSmi(year_month_day__value));
  }
  {
    Tagged<Object> hour_minute_second__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, hour_minute_second__value);
    CHECK(IsSmi(hour_minute_second__value));
  }
  {
    Tagged<Object> second_parts__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, second_parts__value);
    CHECK(IsSmi(second_parts__value));
  }
  {
    Tagged<Object> calendar__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, calendar__value);
    CHECK(IsJSReceiver(calendar__value));
  }
}
void TorqueGeneratedClassVerifiers::JSTemporalPlainDateVerify(Tagged<JSTemporalPlainDate> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSTemporalPlainDate(o, isolate));
  {
    Tagged<Object> year_month_day__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, year_month_day__value);
    CHECK(IsSmi(year_month_day__value));
  }
  {
    Tagged<Object> calendar__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, calendar__value);
    CHECK(IsJSReceiver(calendar__value));
  }
}
void TorqueGeneratedClassVerifiers::JSTemporalPlainMonthDayVerify(Tagged<JSTemporalPlainMonthDay> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSTemporalPlainMonthDay(o, isolate));
  {
    Tagged<Object> year_month_day__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, year_month_day__value);
    CHECK(IsSmi(year_month_day__value));
  }
  {
    Tagged<Object> calendar__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, calendar__value);
    CHECK(IsJSReceiver(calendar__value));
  }
}
void TorqueGeneratedClassVerifiers::JSTemporalPlainTimeVerify(Tagged<JSTemporalPlainTime> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSTemporalPlainTime(o, isolate));
  {
    Tagged<Object> hour_minute_second__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, hour_minute_second__value);
    CHECK(IsSmi(hour_minute_second__value));
  }
  {
    Tagged<Object> second_parts__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, second_parts__value);
    CHECK(IsSmi(second_parts__value));
  }
  {
    Tagged<Object> calendar__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, calendar__value);
    CHECK(IsJSReceiver(calendar__value));
  }
}
void TorqueGeneratedClassVerifiers::JSTemporalPlainYearMonthVerify(Tagged<JSTemporalPlainYearMonth> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSTemporalPlainYearMonth(o, isolate));
  {
    Tagged<Object> year_month_day__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, year_month_day__value);
    CHECK(IsSmi(year_month_day__value));
  }
  {
    Tagged<Object> calendar__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, calendar__value);
    CHECK(IsJSReceiver(calendar__value));
  }
}
void TorqueGeneratedClassVerifiers::JSTemporalTimeZoneVerify(Tagged<JSTemporalTimeZone> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSTemporalTimeZone(o, isolate));
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
  {
    Tagged<Object> details__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, details__value);
    CHECK(IsSmi(details__value));
  }
}
void TorqueGeneratedClassVerifiers::JSTemporalZonedDateTimeVerify(Tagged<JSTemporalZonedDateTime> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSTemporalZonedDateTime(o, isolate));
  {
    Tagged<Object> nanoseconds__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, nanoseconds__value);
    CHECK(IsBigInt(nanoseconds__value));
  }
  {
    Tagged<Object> time_zone__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, time_zone__value);
    CHECK(IsJSReceiver(time_zone__value));
  }
  {
    Tagged<Object> calendar__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, calendar__value);
    CHECK(IsJSReceiver(calendar__value));
  }
}
void TorqueGeneratedClassVerifiers::JSFinalizationRegistryVerify(Tagged<JSFinalizationRegistry> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSFinalizationRegistry(o, isolate));
  {
    Tagged<Object> native_context__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, native_context__value);
    CHECK(IsNativeContext(native_context__value));
  }
  {
    Tagged<Object> cleanup__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, cleanup__value);
    CHECK(IsJSFunction(cleanup__value) || IsCallableApiObject(cleanup__value) || IsCallableJSProxy(cleanup__value) || IsJSWrappedFunction(cleanup__value) || IsJSBoundFunction(cleanup__value));
  }
  {
    Tagged<Object> active_cells__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, active_cells__value);
    CHECK(IsUndefined(active_cells__value) || IsWeakCell(active_cells__value));
  }
  {
    Tagged<Object> cleared_cells__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, cleared_cells__value);
    CHECK(IsUndefined(cleared_cells__value) || IsWeakCell(cleared_cells__value));
  }
  {
    Tagged<Object> key_map__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, key_map__value);
  }
  {
    Tagged<Object> next_dirty__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, next_dirty__value);
    CHECK(IsUndefined(next_dirty__value) || IsJSFinalizationRegistry(next_dirty__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 36);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::JSWeakRefVerify(Tagged<JSWeakRef> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSWeakRef(o, isolate));
  {
    Tagged<Object> target__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, target__value);
    CHECK(IsJSReceiver(target__value) || IsUndefined(target__value) || IsSymbol(target__value));
  }
}
void TorqueGeneratedClassVerifiers::ArrayBoilerplateDescriptionVerify(Tagged<ArrayBoilerplateDescription> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsArrayBoilerplateDescription(o, isolate));
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
  {
    Tagged<Object> constant_elements__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, constant_elements__value);
    CHECK(IsFixedArrayBase(constant_elements__value));
  }
}
void TorqueGeneratedClassVerifiers::MegaDomHandlerVerify(Tagged<MegaDomHandler> o, Isolate* isolate) {
  CHECK(IsMegaDomHandler(o, isolate));
  {
    Tagged<MaybeObject> accessor__value = TaggedField<MaybeObject>::load(o, 4);
    Object::VerifyMaybeObjectPointer(isolate, accessor__value);
    CHECK(accessor__value.IsCleared() || (!accessor__value.IsWeak() && IsHeapObject(accessor__value.GetHeapObjectOrSmi())) || (!accessor__value.IsWeak() && IsSmi(accessor__value.GetHeapObjectOrSmi())) || accessor__value.IsWeak());
  }
  {
    Tagged<MaybeObject> context__value = TaggedField<MaybeObject>::load(o, 8);
    Object::VerifyMaybeObjectPointer(isolate, context__value);
    CHECK(context__value.IsCleared() || (!context__value.IsWeak() && IsHeapObject(context__value.GetHeapObjectOrSmi())) || (!context__value.IsWeak() && IsSmi(context__value.GetHeapObjectOrSmi())) || context__value.IsWeak());
  }
}
void TorqueGeneratedClassVerifiers::MicrotaskVerify(Tagged<Microtask> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsMicrotask(o, isolate));
  {
    Tagged<Object> continuation_preserved_embedder_data__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, continuation_preserved_embedder_data__value);
  }
}
void TorqueGeneratedClassVerifiers::CallbackTaskVerify(Tagged<CallbackTask> o, Isolate* isolate) {
  o->MicrotaskVerify(isolate);
  CHECK(IsCallbackTask(o, isolate));
  {
    Tagged<Object> callback__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, callback__value);
    CHECK(IsForeign(callback__value));
  }
  {
    Tagged<Object> data__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, data__value);
    CHECK(IsForeign(data__value));
  }
}
void TorqueGeneratedClassVerifiers::CallableTaskVerify(Tagged<CallableTask> o, Isolate* isolate) {
  o->MicrotaskVerify(isolate);
  CHECK(IsCallableTask(o, isolate));
  {
    Tagged<Object> callable__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, callable__value);
    CHECK(IsJSReceiver(callable__value));
  }
  {
    Tagged<Object> context__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, context__value);
    CHECK(IsContext(context__value));
  }
}
void TorqueGeneratedClassVerifiers::ModuleVerify(Tagged<Module> o, Isolate* isolate) {
  CHECK(IsModule(o, isolate));
  {
    Tagged<Object> exports__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, exports__value);
    CHECK(IsObjectHashTable(exports__value));
  }
  {
    Tagged<Object> hash__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, hash__value);
    CHECK(IsSmi(hash__value));
  }
  {
    Tagged<Object> status__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, status__value);
    CHECK(IsSmi(status__value));
  }
  {
    Tagged<Object> module_namespace__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, module_namespace__value);
    CHECK(IsUndefined(module_namespace__value) || IsJSModuleNamespace(module_namespace__value));
  }
  {
    Tagged<Object> exception__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, exception__value);
  }
  {
    Tagged<Object> top_level_capability__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, top_level_capability__value);
    CHECK(IsUndefined(top_level_capability__value) || IsJSPromise(top_level_capability__value));
  }
}
void TorqueGeneratedClassVerifiers::JSModuleNamespaceVerify(Tagged<JSModuleNamespace> o, Isolate* isolate) {
  o->JSSpecialObjectVerify(isolate);
  CHECK(IsJSModuleNamespace(o, isolate));
  {
    Tagged<Object> module__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, module__value);
    CHECK(IsModule(module__value));
  }
}
void TorqueGeneratedClassVerifiers::ScriptOrModuleVerify(Tagged<ScriptOrModule> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsScriptOrModule(o, isolate));
  {
    Tagged<Object> resource_name__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, resource_name__value);
  }
  {
    Tagged<Object> host_defined_options__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, host_defined_options__value);
    CHECK(IsFixedArray(host_defined_options__value));
  }
}
void TorqueGeneratedClassVerifiers::PromiseReactionVerify(Tagged<PromiseReaction> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsPromiseReaction(o, isolate));
  {
    Tagged<Object> continuation_preserved_embedder_data__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, continuation_preserved_embedder_data__value);
  }
  {
    Tagged<Object> next__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, next__value);
    CHECK(IsZero(next__value) || IsPromiseReaction(next__value));
  }
  {
    Tagged<Object> reject_handler__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, reject_handler__value);
    CHECK(IsUndefined(reject_handler__value) || IsJSFunction(reject_handler__value) || IsCallableApiObject(reject_handler__value) || IsCallableJSProxy(reject_handler__value) || IsJSWrappedFunction(reject_handler__value) || IsJSBoundFunction(reject_handler__value));
  }
  {
    Tagged<Object> fulfill_handler__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, fulfill_handler__value);
    CHECK(IsUndefined(fulfill_handler__value) || IsJSFunction(fulfill_handler__value) || IsCallableApiObject(fulfill_handler__value) || IsCallableJSProxy(fulfill_handler__value) || IsJSWrappedFunction(fulfill_handler__value) || IsJSBoundFunction(fulfill_handler__value));
  }
  {
    Tagged<Object> promise_or_capability__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, promise_or_capability__value);
    CHECK(IsUndefined(promise_or_capability__value) || IsJSPromise(promise_or_capability__value) || IsPromiseCapability(promise_or_capability__value));
  }
}
void TorqueGeneratedClassVerifiers::PromiseReactionJobTaskVerify(Tagged<PromiseReactionJobTask> o, Isolate* isolate) {
  o->MicrotaskVerify(isolate);
  CHECK(IsPromiseReactionJobTask(o, isolate));
  {
    Tagged<Object> argument__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, argument__value);
  }
  {
    Tagged<Object> context__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, context__value);
    CHECK(IsContext(context__value));
  }
  {
    Tagged<Object> handler__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, handler__value);
    CHECK(IsUndefined(handler__value) || IsJSFunction(handler__value) || IsCallableApiObject(handler__value) || IsCallableJSProxy(handler__value) || IsJSWrappedFunction(handler__value) || IsJSBoundFunction(handler__value));
  }
  {
    Tagged<Object> promise_or_capability__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, promise_or_capability__value);
    CHECK(IsUndefined(promise_or_capability__value) || IsJSPromise(promise_or_capability__value) || IsPromiseCapability(promise_or_capability__value));
  }
}
void TorqueGeneratedClassVerifiers::PromiseFulfillReactionJobTaskVerify(Tagged<PromiseFulfillReactionJobTask> o, Isolate* isolate) {
  o->PromiseReactionJobTaskVerify(isolate);
  CHECK(IsPromiseFulfillReactionJobTask(o, isolate));
}
void TorqueGeneratedClassVerifiers::PromiseRejectReactionJobTaskVerify(Tagged<PromiseRejectReactionJobTask> o, Isolate* isolate) {
  o->PromiseReactionJobTaskVerify(isolate);
  CHECK(IsPromiseRejectReactionJobTask(o, isolate));
}
void TorqueGeneratedClassVerifiers::PromiseResolveThenableJobTaskVerify(Tagged<PromiseResolveThenableJobTask> o, Isolate* isolate) {
  o->MicrotaskVerify(isolate);
  CHECK(IsPromiseResolveThenableJobTask(o, isolate));
  {
    Tagged<Object> context__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, context__value);
    CHECK(IsContext(context__value));
  }
  {
    Tagged<Object> promise_to_resolve__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, promise_to_resolve__value);
    CHECK(IsJSPromise(promise_to_resolve__value));
  }
  {
    Tagged<Object> thenable__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, thenable__value);
    CHECK(IsJSReceiver(thenable__value));
  }
  {
    Tagged<Object> then__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, then__value);
    CHECK(IsJSReceiver(then__value));
  }
}
void TorqueGeneratedClassVerifiers::PropertyArrayVerify(Tagged<PropertyArray> o, Isolate* isolate) {
  CHECK(IsPropertyArray(o, isolate));
  {
    Tagged<Object> length_and_hash__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, length_and_hash__value);
    CHECK(IsSmi(length_and_hash__value));
  }
}
void TorqueGeneratedClassVerifiers::PropertyCellVerify(Tagged<PropertyCell> o, Isolate* isolate) {
  CHECK(IsPropertyCell(o, isolate));
  {
    Tagged<Object> name__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, name__value);
    CHECK(IsString(name__value) || IsPublicSymbol(name__value) || IsPrivateSymbol(name__value));
  }
  {
    Tagged<Object> property_details_raw__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, property_details_raw__value);
    CHECK(IsSmi(property_details_raw__value));
  }
  {
    Tagged<Object> value__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, value__value);
  }
  {
    Tagged<Object> dependent_code__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, dependent_code__value);
    CHECK(IsDependentCode(dependent_code__value));
  }
}
void TorqueGeneratedClassVerifiers::ContextSidePropertyCellVerify(Tagged<ContextSidePropertyCell> o, Isolate* isolate) {
  CHECK(IsContextSidePropertyCell(o, isolate));
  {
    Tagged<Object> property_details_raw__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, property_details_raw__value);
    CHECK(IsSmi(property_details_raw__value));
  }
  {
    Tagged<Object> dependent_code__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, dependent_code__value);
    CHECK(IsDependentCode(dependent_code__value));
  }
}
void TorqueGeneratedClassVerifiers::PropertyDescriptorObjectVerify(Tagged<PropertyDescriptorObject> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsPropertyDescriptorObject(o, isolate));
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
  {
    Tagged<Object> value__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, value__value);
    CHECK(IsJSReceiver(value__value) || IsUndefined(value__value) || IsNull(value__value) || IsBoolean(value__value) || IsSymbol(value__value) || IsString(value__value) || IsBigInt(value__value) || IsHeapNumber(value__value) || IsSmi(value__value) || IsTheHole(value__value));
  }
  {
    Tagged<Object> get__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, get__value);
    CHECK(IsJSReceiver(get__value) || IsUndefined(get__value) || IsNull(get__value) || IsBoolean(get__value) || IsSymbol(get__value) || IsString(get__value) || IsBigInt(get__value) || IsHeapNumber(get__value) || IsSmi(get__value) || IsTheHole(get__value) || IsFunctionTemplateInfo(get__value));
  }
  {
    Tagged<Object> set__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, set__value);
    CHECK(IsJSReceiver(set__value) || IsUndefined(set__value) || IsNull(set__value) || IsBoolean(set__value) || IsSymbol(set__value) || IsString(set__value) || IsBigInt(set__value) || IsHeapNumber(set__value) || IsSmi(set__value) || IsTheHole(set__value) || IsFunctionTemplateInfo(set__value));
  }
}
void TorqueGeneratedClassVerifiers::PrototypeInfoVerify(Tagged<PrototypeInfo> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsPrototypeInfo(o, isolate));
  {
    Tagged<Object> module_namespace__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, module_namespace__value);
    CHECK(IsUndefined(module_namespace__value) || IsJSModuleNamespace(module_namespace__value));
  }
  {
    Tagged<Object> prototype_users__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, prototype_users__value);
    CHECK(IsZero(prototype_users__value) || IsWeakArrayList(prototype_users__value));
  }
  {
    Tagged<Object> prototype_chain_enum_cache__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, prototype_chain_enum_cache__value);
    CHECK(IsUndefined(prototype_chain_enum_cache__value) || IsFixedArray(prototype_chain_enum_cache__value) || IsZero(prototype_chain_enum_cache__value));
  }
  {
    Tagged<Object> registry_slot__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, registry_slot__value);
    CHECK(IsSmi(registry_slot__value));
  }
  {
    Tagged<Object> bit_field__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, bit_field__value);
    CHECK(IsSmi(bit_field__value));
  }
  {
    Tagged<Object> derived_maps__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, derived_maps__value);
    CHECK(IsUndefined(derived_maps__value) || IsWeakArrayList(derived_maps__value));
  }
}
void TorqueGeneratedClassVerifiers::ScriptVerify(Tagged<Script> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsScript(o, isolate));
  {
    Tagged<Object> source__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, source__value);
    CHECK(IsUndefined(source__value) || IsString(source__value));
  }
  {
    Tagged<Object> name__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, name__value);
  }
  {
    Tagged<Object> line_offset__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, line_offset__value);
    CHECK(IsSmi(line_offset__value));
  }
  {
    Tagged<Object> column_offset__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, column_offset__value);
    CHECK(IsSmi(column_offset__value));
  }
  {
    Tagged<Object> context_data__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, context_data__value);
    CHECK(IsUndefined(context_data__value) || IsSymbol(context_data__value) || IsSmi(context_data__value));
  }
  {
    Tagged<Object> script_type__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, script_type__value);
    CHECK(IsSmi(script_type__value));
  }
  {
    Tagged<Object> line_ends__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, line_ends__value);
    CHECK(IsSmi(line_ends__value) || IsFixedArray(line_ends__value));
  }
  {
    Tagged<Object> id__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, id__value);
    CHECK(IsSmi(id__value));
  }
  {
    Tagged<Object> eval_from_shared_or_wrapped_arguments__value = TaggedField<Object>::load(o, 36);
    Object::VerifyPointer(isolate, eval_from_shared_or_wrapped_arguments__value);
    CHECK(IsUndefined(eval_from_shared_or_wrapped_arguments__value) || IsFixedArray(eval_from_shared_or_wrapped_arguments__value) || IsSharedFunctionInfo(eval_from_shared_or_wrapped_arguments__value));
  }
  {
    Tagged<Object> eval_from_position__value = TaggedField<Object>::load(o, 40);
    Object::VerifyPointer(isolate, eval_from_position__value);
    CHECK(IsSmi(eval_from_position__value) || IsForeign(eval_from_position__value));
  }
  {
    Tagged<Object> infos__value = TaggedField<Object>::load(o, 44);
    Object::VerifyPointer(isolate, infos__value);
    CHECK(IsWeakFixedArray(infos__value) || IsWeakArrayList(infos__value));
  }
  {
    Tagged<Object> compiled_lazy_function_positions__value = TaggedField<Object>::load(o, 48);
    Object::VerifyPointer(isolate, compiled_lazy_function_positions__value);
    CHECK(IsUndefined(compiled_lazy_function_positions__value) || IsArrayList(compiled_lazy_function_positions__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 52);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
  {
    Tagged<Object> source_url__value = TaggedField<Object>::load(o, 56);
    Object::VerifyPointer(isolate, source_url__value);
    CHECK(IsUndefined(source_url__value) || IsString(source_url__value));
  }
  {
    Tagged<Object> source_mapping_url__value = TaggedField<Object>::load(o, 60);
    Object::VerifyPointer(isolate, source_mapping_url__value);
  }
  {
    Tagged<Object> host_defined_options__value = TaggedField<Object>::load(o, 64);
    Object::VerifyPointer(isolate, host_defined_options__value);
    CHECK(IsFixedArray(host_defined_options__value));
  }
  {
    Tagged<Object> source_hash__value = TaggedField<Object>::load(o, 68);
    Object::VerifyPointer(isolate, source_hash__value);
    CHECK(IsUndefined(source_hash__value) || IsString(source_hash__value));
  }
}
void TorqueGeneratedClassVerifiers::PreparseDataVerify(Tagged<PreparseData> o, Isolate* isolate) {
  CHECK(IsPreparseData(o, isolate));
}
void TorqueGeneratedClassVerifiers::InterpreterDataVerify(Tagged<InterpreterData> o, Isolate* isolate) {
  CHECK(IsInterpreterData(o, isolate));
}
void TorqueGeneratedClassVerifiers::SharedFunctionInfoVerify(Tagged<SharedFunctionInfo> o, Isolate* isolate) {
  CHECK(IsSharedFunctionInfo(o, isolate));
  {
    Tagged<Object> untrusted_function_data__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, untrusted_function_data__value);
  }
  {
    Tagged<Object> name_or_scope_info__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, name_or_scope_info__value);
    CHECK(IsString(name_or_scope_info__value) || IsNoSharedNameSentinel(name_or_scope_info__value) || IsScopeInfo(name_or_scope_info__value));
  }
  {
    Tagged<Object> outer_scope_info_or_feedback_metadata__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, outer_scope_info_or_feedback_metadata__value);
    CHECK(IsHeapObject(outer_scope_info_or_feedback_metadata__value));
  }
  {
    Tagged<Object> script__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, script__value);
    CHECK(IsUndefined(script__value) || IsScript(script__value));
  }
}
void TorqueGeneratedClassVerifiers::UncompiledDataVerify(Tagged<UncompiledData> o, Isolate* isolate) {
  CHECK(IsUncompiledData(o, isolate));
  {
    Tagged<Object> inferred_name__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, inferred_name__value);
    CHECK(IsString(inferred_name__value));
  }
}
void TorqueGeneratedClassVerifiers::UncompiledDataWithoutPreparseDataVerify(Tagged<UncompiledDataWithoutPreparseData> o, Isolate* isolate) {
  o->UncompiledDataVerify(isolate);
  CHECK(IsUncompiledDataWithoutPreparseData(o, isolate));
}
void TorqueGeneratedClassVerifiers::UncompiledDataWithPreparseDataVerify(Tagged<UncompiledDataWithPreparseData> o, Isolate* isolate) {
  o->UncompiledDataVerify(isolate);
  CHECK(IsUncompiledDataWithPreparseData(o, isolate));
  {
    Tagged<Object> preparse_data__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, preparse_data__value);
    CHECK(IsPreparseData(preparse_data__value));
  }
}
void TorqueGeneratedClassVerifiers::UncompiledDataWithoutPreparseDataWithJobVerify(Tagged<UncompiledDataWithoutPreparseDataWithJob> o, Isolate* isolate) {
  o->UncompiledDataWithoutPreparseDataVerify(isolate);
  CHECK(IsUncompiledDataWithoutPreparseDataWithJob(o, isolate));
}
void TorqueGeneratedClassVerifiers::UncompiledDataWithPreparseDataAndJobVerify(Tagged<UncompiledDataWithPreparseDataAndJob> o, Isolate* isolate) {
  o->UncompiledDataWithPreparseDataVerify(isolate);
  CHECK(IsUncompiledDataWithPreparseDataAndJob(o, isolate));
}
void TorqueGeneratedClassVerifiers::OnHeapBasicBlockProfilerDataVerify(Tagged<OnHeapBasicBlockProfilerData> o, Isolate* isolate) {
  CHECK(IsOnHeapBasicBlockProfilerData(o, isolate));
  {
    Tagged<Object> block_ids__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, block_ids__value);
    CHECK(IsByteArray(block_ids__value));
  }
  {
    Tagged<Object> counts__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, counts__value);
    CHECK(IsByteArray(counts__value));
  }
  {
    Tagged<Object> branches__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, branches__value);
    CHECK(IsByteArray(branches__value));
  }
  {
    Tagged<Object> name__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, name__value);
    CHECK(IsString(name__value));
  }
  {
    Tagged<Object> schedule__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, schedule__value);
    CHECK(IsString(schedule__value));
  }
  {
    Tagged<Object> code__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, code__value);
    CHECK(IsString(code__value));
  }
  {
    Tagged<Object> hash__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, hash__value);
    CHECK(IsSmi(hash__value));
  }
}
void TorqueGeneratedClassVerifiers::SourceTextModuleVerify(Tagged<SourceTextModule> o, Isolate* isolate) {
  o->ModuleVerify(isolate);
  CHECK(IsSourceTextModule(o, isolate));
  {
    Tagged<Object> code__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, code__value);
    CHECK(IsJSFunction(code__value) || IsJSGeneratorObject(code__value) || IsSharedFunctionInfo(code__value));
  }
  {
    Tagged<Object> regular_exports__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, regular_exports__value);
    CHECK(IsFixedArray(regular_exports__value));
  }
  {
    Tagged<Object> regular_imports__value = TaggedField<Object>::load(o, 36);
    Object::VerifyPointer(isolate, regular_imports__value);
    CHECK(IsFixedArray(regular_imports__value));
  }
  {
    Tagged<Object> requested_modules__value = TaggedField<Object>::load(o, 40);
    Object::VerifyPointer(isolate, requested_modules__value);
    CHECK(IsFixedArray(requested_modules__value));
  }
  {
    Tagged<Object> import_meta__value = TaggedField<Object>::load(o, 44);
    Object::VerifyPointer(isolate, import_meta__value);
    CHECK(IsJSObject(import_meta__value) || IsTheHole(import_meta__value));
  }
  {
    Tagged<Object> cycle_root__value = TaggedField<Object>::load(o, 48);
    Object::VerifyPointer(isolate, cycle_root__value);
    CHECK(IsTheHole(cycle_root__value) || IsSourceTextModule(cycle_root__value));
  }
  {
    Tagged<Object> async_parent_modules__value = TaggedField<Object>::load(o, 52);
    Object::VerifyPointer(isolate, async_parent_modules__value);
    CHECK(IsArrayList(async_parent_modules__value));
  }
  {
    Tagged<Object> dfs_index__value = TaggedField<Object>::load(o, 56);
    Object::VerifyPointer(isolate, dfs_index__value);
    CHECK(IsSmi(dfs_index__value));
  }
  {
    Tagged<Object> dfs_ancestor_index__value = TaggedField<Object>::load(o, 60);
    Object::VerifyPointer(isolate, dfs_ancestor_index__value);
    CHECK(IsSmi(dfs_ancestor_index__value));
  }
  {
    Tagged<Object> pending_async_dependencies__value = TaggedField<Object>::load(o, 64);
    Object::VerifyPointer(isolate, pending_async_dependencies__value);
    CHECK(IsSmi(pending_async_dependencies__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 68);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::ModuleRequestVerify(Tagged<ModuleRequest> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsModuleRequest(o, isolate));
  {
    Tagged<Object> specifier__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, specifier__value);
    CHECK(IsString(specifier__value));
  }
  {
    Tagged<Object> import_attributes__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, import_attributes__value);
    CHECK(IsFixedArray(import_attributes__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::SourceTextModuleInfoEntryVerify(Tagged<SourceTextModuleInfoEntry> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsSourceTextModuleInfoEntry(o, isolate));
  {
    Tagged<Object> export_name__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, export_name__value);
    CHECK(IsUndefined(export_name__value) || IsString(export_name__value));
  }
  {
    Tagged<Object> local_name__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, local_name__value);
    CHECK(IsUndefined(local_name__value) || IsString(local_name__value));
  }
  {
    Tagged<Object> import_name__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, import_name__value);
    CHECK(IsUndefined(import_name__value) || IsString(import_name__value));
  }
  {
    Tagged<Object> module_request__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, module_request__value);
    CHECK(IsSmi(module_request__value));
  }
  {
    Tagged<Object> cell_index__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, cell_index__value);
    CHECK(IsSmi(cell_index__value));
  }
  {
    Tagged<Object> beg_pos__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, beg_pos__value);
    CHECK(IsSmi(beg_pos__value));
  }
  {
    Tagged<Object> end_pos__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, end_pos__value);
    CHECK(IsSmi(end_pos__value));
  }
}
void TorqueGeneratedClassVerifiers::Tuple2Verify(Tagged<Tuple2> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsTuple2(o, isolate));
  {
    Tagged<Object> value1__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, value1__value);
  }
  {
    Tagged<Object> value2__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, value2__value);
  }
}
void TorqueGeneratedClassVerifiers::SyntheticModuleVerify(Tagged<SyntheticModule> o, Isolate* isolate) {
  o->ModuleVerify(isolate);
  CHECK(IsSyntheticModule(o, isolate));
  {
    Tagged<Object> name__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, name__value);
    CHECK(IsString(name__value));
  }
  {
    Tagged<Object> export_names__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, export_names__value);
    CHECK(IsFixedArray(export_names__value));
  }
  {
    Tagged<Object> evaluation_steps__value = TaggedField<Object>::load(o, 36);
    Object::VerifyPointer(isolate, evaluation_steps__value);
    CHECK(IsForeign(evaluation_steps__value));
  }
}
void TorqueGeneratedClassVerifiers::TemplateObjectDescriptionVerify(Tagged<TemplateObjectDescription> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsTemplateObjectDescription(o, isolate));
  {
    Tagged<Object> raw_strings__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, raw_strings__value);
    CHECK(IsFixedArray(raw_strings__value));
  }
  {
    Tagged<Object> cooked_strings__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, cooked_strings__value);
    CHECK(IsFixedArray(cooked_strings__value));
  }
}
void TorqueGeneratedClassVerifiers::FunctionTemplateRareDataVerify(Tagged<FunctionTemplateRareData> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsFunctionTemplateRareData(o, isolate));
  {
    Tagged<Object> prototype_template__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, prototype_template__value);
    CHECK(IsUndefined(prototype_template__value) || IsObjectTemplateInfo(prototype_template__value));
  }
  {
    Tagged<Object> prototype_provider_template__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, prototype_provider_template__value);
    CHECK(IsUndefined(prototype_provider_template__value) || IsFunctionTemplateInfo(prototype_provider_template__value));
  }
  {
    Tagged<Object> parent_template__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, parent_template__value);
    CHECK(IsUndefined(parent_template__value) || IsFunctionTemplateInfo(parent_template__value));
  }
  {
    Tagged<Object> named_property_handler__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, named_property_handler__value);
    CHECK(IsUndefined(named_property_handler__value) || IsInterceptorInfo(named_property_handler__value));
  }
  {
    Tagged<Object> indexed_property_handler__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, indexed_property_handler__value);
    CHECK(IsUndefined(indexed_property_handler__value) || IsInterceptorInfo(indexed_property_handler__value));
  }
  {
    Tagged<Object> instance_template__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, instance_template__value);
    CHECK(IsUndefined(instance_template__value) || IsObjectTemplateInfo(instance_template__value));
  }
  {
    Tagged<Object> instance_call_handler__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, instance_call_handler__value);
    CHECK(IsUndefined(instance_call_handler__value) || IsFunctionTemplateInfo(instance_call_handler__value));
  }
  {
    Tagged<Object> access_check_info__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, access_check_info__value);
    CHECK(IsUndefined(access_check_info__value) || IsAccessCheckInfo(access_check_info__value));
  }
  {
    Tagged<Object> c_function_overloads__value = TaggedField<Object>::load(o, 36);
    Object::VerifyPointer(isolate, c_function_overloads__value);
    CHECK(IsFixedArray(c_function_overloads__value));
  }
}
void TorqueGeneratedClassVerifiers::ObjectTemplateInfoVerify(Tagged<ObjectTemplateInfo> o, Isolate* isolate) {
  o->TemplateInfoVerify(isolate);
  CHECK(IsObjectTemplateInfo(o, isolate));
  {
    Tagged<Object> constructor__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, constructor__value);
    CHECK(IsUndefined(constructor__value) || IsFunctionTemplateInfo(constructor__value));
  }
  {
    Tagged<Object> data__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, data__value);
    CHECK(IsSmi(data__value));
  }
}
void TorqueGeneratedClassVerifiers::DictionaryTemplateInfoVerify(Tagged<DictionaryTemplateInfo> o, Isolate* isolate) {
  CHECK(IsDictionaryTemplateInfo(o, isolate));
  {
    Tagged<Object> property_names__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, property_names__value);
    CHECK(IsFixedArray(property_names__value));
  }
  {
    Tagged<Object> serial_number__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, serial_number__value);
    CHECK(IsSmi(serial_number__value));
  }
}
void TorqueGeneratedClassVerifiers::TurbofanTypeVerify(Tagged<TurbofanType> o, Isolate* isolate) {
  CHECK(IsTurbofanType(o, isolate));
}
void TorqueGeneratedClassVerifiers::TurbofanBitsetTypeVerify(Tagged<TurbofanBitsetType> o, Isolate* isolate) {
  o->TurbofanTypeVerify(isolate);
  CHECK(IsTurbofanBitsetType(o, isolate));
}
void TorqueGeneratedClassVerifiers::TurbofanUnionTypeVerify(Tagged<TurbofanUnionType> o, Isolate* isolate) {
  o->TurbofanTypeVerify(isolate);
  CHECK(IsTurbofanUnionType(o, isolate));
  {
    Tagged<Object> type1__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, type1__value);
    CHECK(IsTurbofanType(type1__value));
  }
  {
    Tagged<Object> type2__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, type2__value);
    CHECK(IsTurbofanType(type2__value));
  }
}
void TorqueGeneratedClassVerifiers::TurbofanRangeTypeVerify(Tagged<TurbofanRangeType> o, Isolate* isolate) {
  o->TurbofanTypeVerify(isolate);
  CHECK(IsTurbofanRangeType(o, isolate));
}
void TorqueGeneratedClassVerifiers::TurbofanHeapConstantTypeVerify(Tagged<TurbofanHeapConstantType> o, Isolate* isolate) {
  o->TurbofanTypeVerify(isolate);
  CHECK(IsTurbofanHeapConstantType(o, isolate));
  {
    Tagged<Object> constant__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, constant__value);
    CHECK(IsHeapObject(constant__value));
  }
}
void TorqueGeneratedClassVerifiers::TurbofanOtherNumberConstantTypeVerify(Tagged<TurbofanOtherNumberConstantType> o, Isolate* isolate) {
  o->TurbofanTypeVerify(isolate);
  CHECK(IsTurbofanOtherNumberConstantType(o, isolate));
}
void TorqueGeneratedClassVerifiers::TurboshaftTypeVerify(Tagged<TurboshaftType> o, Isolate* isolate) {
  CHECK(IsTurboshaftType(o, isolate));
}
void TorqueGeneratedClassVerifiers::TurboshaftWord32TypeVerify(Tagged<TurboshaftWord32Type> o, Isolate* isolate) {
  o->TurboshaftTypeVerify(isolate);
  CHECK(IsTurboshaftWord32Type(o, isolate));
}
void TorqueGeneratedClassVerifiers::TurboshaftWord32RangeTypeVerify(Tagged<TurboshaftWord32RangeType> o, Isolate* isolate) {
  o->TurboshaftWord32TypeVerify(isolate);
  CHECK(IsTurboshaftWord32RangeType(o, isolate));
}
void TorqueGeneratedClassVerifiers::TurboshaftWord32SetTypeVerify(Tagged<TurboshaftWord32SetType> o, Isolate* isolate) {
  o->TurboshaftWord32TypeVerify(isolate);
  CHECK(IsTurboshaftWord32SetType(o, isolate));
}
void TorqueGeneratedClassVerifiers::TurboshaftWord64TypeVerify(Tagged<TurboshaftWord64Type> o, Isolate* isolate) {
  o->TurboshaftTypeVerify(isolate);
  CHECK(IsTurboshaftWord64Type(o, isolate));
}
void TorqueGeneratedClassVerifiers::TurboshaftWord64RangeTypeVerify(Tagged<TurboshaftWord64RangeType> o, Isolate* isolate) {
  o->TurboshaftWord64TypeVerify(isolate);
  CHECK(IsTurboshaftWord64RangeType(o, isolate));
}
void TorqueGeneratedClassVerifiers::TurboshaftWord64SetTypeVerify(Tagged<TurboshaftWord64SetType> o, Isolate* isolate) {
  o->TurboshaftWord64TypeVerify(isolate);
  CHECK(IsTurboshaftWord64SetType(o, isolate));
}
void TorqueGeneratedClassVerifiers::TurboshaftFloat64TypeVerify(Tagged<TurboshaftFloat64Type> o, Isolate* isolate) {
  o->TurboshaftTypeVerify(isolate);
  CHECK(IsTurboshaftFloat64Type(o, isolate));
}
void TorqueGeneratedClassVerifiers::TurboshaftFloat64RangeTypeVerify(Tagged<TurboshaftFloat64RangeType> o, Isolate* isolate) {
  o->TurboshaftFloat64TypeVerify(isolate);
  CHECK(IsTurboshaftFloat64RangeType(o, isolate));
}
void TorqueGeneratedClassVerifiers::TurboshaftFloat64SetTypeVerify(Tagged<TurboshaftFloat64SetType> o, Isolate* isolate) {
  o->TurboshaftFloat64TypeVerify(isolate);
  CHECK(IsTurboshaftFloat64SetType(o, isolate));
}
void TorqueGeneratedClassVerifiers::InternalClassVerify(Tagged<InternalClass> o, Isolate* isolate) {
  CHECK(IsInternalClass(o, isolate));
  {
    Tagged<Object> a__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, a__value);
    CHECK(IsSmi(a__value));
  }
  {
    Tagged<Object> b__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, b__value);
    CHECK(IsHeapNumber(b__value) || IsSmi(b__value));
  }
}
void TorqueGeneratedClassVerifiers::SmiPairVerify(Tagged<SmiPair> o, Isolate* isolate) {
  CHECK(IsSmiPair(o, isolate));
  {
    Tagged<Object> a__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, a__value);
    CHECK(IsSmi(a__value));
  }
  {
    Tagged<Object> b__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, b__value);
    CHECK(IsSmi(b__value));
  }
}
void TorqueGeneratedClassVerifiers::SmiBoxVerify(Tagged<SmiBox> o, Isolate* isolate) {
  CHECK(IsSmiBox(o, isolate));
  {
    Tagged<Object> value__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, value__value);
    CHECK(IsSmi(value__value));
  }
  {
    Tagged<Object> unrelated__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, unrelated__value);
    CHECK(IsSmi(unrelated__value));
  }
}
void TorqueGeneratedClassVerifiers::ExportedSubClassBaseVerify(Tagged<ExportedSubClassBase> o, Isolate* isolate) {
  CHECK(IsExportedSubClassBase(o, isolate));
  {
    Tagged<Object> a__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, a__value);
    CHECK(IsHeapObject(a__value));
  }
  {
    Tagged<Object> b__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, b__value);
    CHECK(IsHeapObject(b__value));
  }
}
void TorqueGeneratedClassVerifiers::ExportedSubClassVerify(Tagged<ExportedSubClass> o, Isolate* isolate) {
  o->ExportedSubClassBaseVerify(isolate);
  CHECK(IsExportedSubClass(o, isolate));
  {
    Tagged<Object> e_field__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, e_field__value);
    CHECK(IsSmi(e_field__value));
  }
}
void TorqueGeneratedClassVerifiers::AbstractInternalClassVerify(Tagged<AbstractInternalClass> o, Isolate* isolate) {
  CHECK(IsAbstractInternalClass(o, isolate));
}
void TorqueGeneratedClassVerifiers::AbstractInternalClassSubclass1Verify(Tagged<AbstractInternalClassSubclass1> o, Isolate* isolate) {
  o->AbstractInternalClassVerify(isolate);
  CHECK(IsAbstractInternalClassSubclass1(o, isolate));
}
void TorqueGeneratedClassVerifiers::AbstractInternalClassSubclass2Verify(Tagged<AbstractInternalClassSubclass2> o, Isolate* isolate) {
  o->AbstractInternalClassVerify(isolate);
  CHECK(IsAbstractInternalClassSubclass2(o, isolate));
}
void TorqueGeneratedClassVerifiers::InternalClassWithStructElementsVerify(Tagged<InternalClassWithStructElements> o, Isolate* isolate) {
  CHECK(IsInternalClassWithStructElements(o, isolate));
  {
    Tagged<Object> count__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, count__value);
    CHECK(IsSmi(count__value));
  }
  {
    Tagged<Object> data__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, data__value);
    CHECK(IsSmi(data__value));
  }
  {
    Tagged<Object> object__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, object__value);
  }
  intptr_t entries__offset, entries__length;
  std::tie(std::ignore, entries__offset, entries__length) = TqRuntimeFieldSliceInternalClassWithStructElementsEntries(o);
  CHECK_EQ(entries__offset, static_cast<int>(entries__offset));
  CHECK_EQ(entries__length, static_cast<int>(entries__length));
  for (int i = 0; i < static_cast<int>(entries__length); ++i) {
    Tagged<Object> entries__value = TaggedField<Object>::load(o, static_cast<int>(entries__offset) + i * kTaggedSize);
    Object::VerifyPointer(isolate, entries__value);
    CHECK(IsSmi(entries__value));
  }
  intptr_t more_entries__offset, more_entries__length;
  std::tie(std::ignore, more_entries__offset, more_entries__length) = TqRuntimeFieldSliceInternalClassWithStructElementsMoreEntries(o);
  CHECK_EQ(more_entries__offset, static_cast<int>(more_entries__offset));
  CHECK_EQ(more_entries__length, static_cast<int>(more_entries__length));
  for (int i = 0; i < static_cast<int>(more_entries__length); ++i) {
    Tagged<Object> a__value = TaggedField<Object>::load(o, static_cast<int>(more_entries__offset) + 0 + i * 8);
    Object::VerifyPointer(isolate, a__value);
    CHECK(IsSmi(a__value));
    Tagged<Object> b__value = TaggedField<Object>::load(o, static_cast<int>(more_entries__offset) + 4 + i * 8);
    Object::VerifyPointer(isolate, b__value);
    CHECK(IsSmi(b__value));
  }
}
void TorqueGeneratedClassVerifiers::ExportedSubClass2Verify(Tagged<ExportedSubClass2> o, Isolate* isolate) {
  o->ExportedSubClassBaseVerify(isolate);
  CHECK(IsExportedSubClass2(o, isolate));
  {
    Tagged<Object> z_field__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, z_field__value);
    CHECK(IsSmi(z_field__value));
  }
}
void TorqueGeneratedClassVerifiers::SortStateVerify(Tagged<SortState> o, Isolate* isolate) {
  CHECK(IsSortState(o, isolate));
  {
    Tagged<Object> receiver__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, receiver__value);
    CHECK(IsJSReceiver(receiver__value));
  }
  {
    Tagged<Object> initialReceiverMap__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, initialReceiverMap__value);
    CHECK(IsMap(initialReceiverMap__value));
  }
  {
    Tagged<Object> initialReceiverLength__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, initialReceiverLength__value);
    CHECK(IsHeapNumber(initialReceiverLength__value) || IsSmi(initialReceiverLength__value));
  }
  {
    Tagged<Object> userCmpFn__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, userCmpFn__value);
    CHECK(IsUndefined(userCmpFn__value) || IsJSFunction(userCmpFn__value) || IsCallableApiObject(userCmpFn__value) || IsCallableJSProxy(userCmpFn__value) || IsJSWrappedFunction(userCmpFn__value) || IsJSBoundFunction(userCmpFn__value));
  }
  {
    Tagged<Object> sortComparePtr__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, sortComparePtr__value);
    CHECK(IsSmi(sortComparePtr__value));
  }
  {
    Tagged<Object> loadFn__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, loadFn__value);
    CHECK(IsSmi(loadFn__value));
  }
  {
    Tagged<Object> storeFn__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, storeFn__value);
    CHECK(IsSmi(storeFn__value));
  }
  {
    Tagged<Object> deleteFn__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, deleteFn__value);
    CHECK(IsSmi(deleteFn__value));
  }
  {
    Tagged<Object> canUseSameAccessorFn__value = TaggedField<Object>::load(o, 36);
    Object::VerifyPointer(isolate, canUseSameAccessorFn__value);
    CHECK(IsSmi(canUseSameAccessorFn__value));
  }
  {
    Tagged<Object> minGallop__value = TaggedField<Object>::load(o, 40);
    Object::VerifyPointer(isolate, minGallop__value);
    CHECK(IsSmi(minGallop__value));
  }
  {
    Tagged<Object> pendingRunsSize__value = TaggedField<Object>::load(o, 44);
    Object::VerifyPointer(isolate, pendingRunsSize__value);
    CHECK(IsSmi(pendingRunsSize__value));
  }
  {
    Tagged<Object> pendingRuns__value = TaggedField<Object>::load(o, 48);
    Object::VerifyPointer(isolate, pendingRuns__value);
    CHECK(IsFixedArray(pendingRuns__value));
  }
  {
    Tagged<Object> workArray__value = TaggedField<Object>::load(o, 52);
    Object::VerifyPointer(isolate, workArray__value);
    CHECK(IsFixedArray(workArray__value));
  }
  {
    Tagged<Object> tempArray__value = TaggedField<Object>::load(o, 56);
    Object::VerifyPointer(isolate, tempArray__value);
    CHECK(IsFixedArray(tempArray__value));
  }
  {
    Tagged<Object> sortLength__value = TaggedField<Object>::load(o, 60);
    Object::VerifyPointer(isolate, sortLength__value);
    CHECK(IsSmi(sortLength__value));
  }
  {
    Tagged<Object> numberOfUndefined__value = TaggedField<Object>::load(o, 64);
    Object::VerifyPointer(isolate, numberOfUndefined__value);
    CHECK(IsSmi(numberOfUndefined__value));
  }
}
void TorqueGeneratedClassVerifiers::JSV8BreakIteratorVerify(Tagged<JSV8BreakIterator> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSV8BreakIterator(o, isolate));
  {
    Tagged<Object> locale__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, locale__value);
    CHECK(IsString(locale__value));
  }
  {
    Tagged<Object> break_iterator__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, break_iterator__value);
    CHECK(IsForeign(break_iterator__value));
  }
  {
    Tagged<Object> unicode_string__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, unicode_string__value);
    CHECK(IsForeign(unicode_string__value));
  }
  {
    Tagged<Object> bound_adopt_text__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, bound_adopt_text__value);
    CHECK(IsUndefined(bound_adopt_text__value) || IsJSFunction(bound_adopt_text__value));
  }
  {
    Tagged<Object> bound_first__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, bound_first__value);
    CHECK(IsUndefined(bound_first__value) || IsJSFunction(bound_first__value));
  }
  {
    Tagged<Object> bound_next__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, bound_next__value);
    CHECK(IsUndefined(bound_next__value) || IsJSFunction(bound_next__value));
  }
  {
    Tagged<Object> bound_current__value = TaggedField<Object>::load(o, 36);
    Object::VerifyPointer(isolate, bound_current__value);
    CHECK(IsUndefined(bound_current__value) || IsJSFunction(bound_current__value));
  }
  {
    Tagged<Object> bound_break_type__value = TaggedField<Object>::load(o, 40);
    Object::VerifyPointer(isolate, bound_break_type__value);
    CHECK(IsUndefined(bound_break_type__value) || IsJSFunction(bound_break_type__value));
  }
}
void TorqueGeneratedClassVerifiers::JSCollatorVerify(Tagged<JSCollator> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSCollator(o, isolate));
  {
    Tagged<Object> icu_collator__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, icu_collator__value);
    CHECK(IsForeign(icu_collator__value));
  }
  {
    Tagged<Object> bound_compare__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, bound_compare__value);
    CHECK(IsUndefined(bound_compare__value) || IsJSFunction(bound_compare__value));
  }
  {
    Tagged<Object> locale__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, locale__value);
    CHECK(IsString(locale__value));
  }
}
void TorqueGeneratedClassVerifiers::JSDateTimeFormatVerify(Tagged<JSDateTimeFormat> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSDateTimeFormat(o, isolate));
  {
    Tagged<Object> locale__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, locale__value);
    CHECK(IsString(locale__value));
  }
  {
    Tagged<Object> icu_locale__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, icu_locale__value);
    CHECK(IsForeign(icu_locale__value));
  }
  {
    Tagged<Object> icu_simple_date_format__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, icu_simple_date_format__value);
    CHECK(IsForeign(icu_simple_date_format__value));
  }
  {
    Tagged<Object> icu_date_interval_format__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, icu_date_interval_format__value);
    CHECK(IsForeign(icu_date_interval_format__value));
  }
  {
    Tagged<Object> bound_format__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, bound_format__value);
    CHECK(IsUndefined(bound_format__value) || IsJSFunction(bound_format__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::JSDisplayNamesVerify(Tagged<JSDisplayNames> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSDisplayNames(o, isolate));
  {
    Tagged<Object> internal__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, internal__value);
    CHECK(IsForeign(internal__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::JSDurationFormatVerify(Tagged<JSDurationFormat> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSDurationFormat(o, isolate));
  {
    Tagged<Object> style_flags__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, style_flags__value);
    CHECK(IsSmi(style_flags__value));
  }
  {
    Tagged<Object> display_flags__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, display_flags__value);
    CHECK(IsSmi(display_flags__value));
  }
  {
    Tagged<Object> icu_locale__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, icu_locale__value);
    CHECK(IsForeign(icu_locale__value));
  }
  {
    Tagged<Object> icu_number_formatter__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, icu_number_formatter__value);
    CHECK(IsForeign(icu_number_formatter__value));
  }
}
void TorqueGeneratedClassVerifiers::JSListFormatVerify(Tagged<JSListFormat> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSListFormat(o, isolate));
  {
    Tagged<Object> locale__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, locale__value);
    CHECK(IsString(locale__value));
  }
  {
    Tagged<Object> icu_formatter__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, icu_formatter__value);
    CHECK(IsForeign(icu_formatter__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::JSLocaleVerify(Tagged<JSLocale> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSLocale(o, isolate));
  {
    Tagged<Object> icu_locale__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, icu_locale__value);
    CHECK(IsForeign(icu_locale__value));
  }
}
void TorqueGeneratedClassVerifiers::JSNumberFormatVerify(Tagged<JSNumberFormat> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSNumberFormat(o, isolate));
  {
    Tagged<Object> locale__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, locale__value);
    CHECK(IsString(locale__value));
  }
  {
    Tagged<Object> icu_number_formatter__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, icu_number_formatter__value);
    CHECK(IsForeign(icu_number_formatter__value));
  }
  {
    Tagged<Object> bound_format__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, bound_format__value);
    CHECK(IsUndefined(bound_format__value) || IsJSFunction(bound_format__value));
  }
}
void TorqueGeneratedClassVerifiers::JSPluralRulesVerify(Tagged<JSPluralRules> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSPluralRules(o, isolate));
  {
    Tagged<Object> locale__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, locale__value);
    CHECK(IsString(locale__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
  {
    Tagged<Object> icu_plural_rules__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, icu_plural_rules__value);
    CHECK(IsForeign(icu_plural_rules__value));
  }
  {
    Tagged<Object> icu_number_formatter__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, icu_number_formatter__value);
    CHECK(IsForeign(icu_number_formatter__value));
  }
}
void TorqueGeneratedClassVerifiers::JSRelativeTimeFormatVerify(Tagged<JSRelativeTimeFormat> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSRelativeTimeFormat(o, isolate));
  {
    Tagged<Object> locale__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, locale__value);
    CHECK(IsString(locale__value));
  }
  {
    Tagged<Object> numberingSystem__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, numberingSystem__value);
    CHECK(IsString(numberingSystem__value));
  }
  {
    Tagged<Object> icu_formatter__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, icu_formatter__value);
    CHECK(IsForeign(icu_formatter__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::JSSegmentIteratorVerify(Tagged<JSSegmentIterator> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSSegmentIterator(o, isolate));
  {
    Tagged<Object> icu_break_iterator__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, icu_break_iterator__value);
    CHECK(IsForeign(icu_break_iterator__value));
  }
  {
    Tagged<Object> raw_string__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, raw_string__value);
    CHECK(IsString(raw_string__value));
  }
  {
    Tagged<Object> unicode_string__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, unicode_string__value);
    CHECK(IsForeign(unicode_string__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::JSSegmentDataObjectVerify(Tagged<JSSegmentDataObject> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSSegmentDataObject(o, isolate));
  {
    Tagged<Object> segment__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, segment__value);
    CHECK(IsString(segment__value));
  }
  {
    Tagged<Object> index__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, index__value);
    CHECK(IsHeapNumber(index__value) || IsSmi(index__value));
  }
  {
    Tagged<Object> input__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, input__value);
    CHECK(IsString(input__value));
  }
}
void TorqueGeneratedClassVerifiers::JSSegmentDataObjectWithIsWordLikeVerify(Tagged<JSSegmentDataObjectWithIsWordLike> o, Isolate* isolate) {
  o->JSSegmentDataObjectVerify(isolate);
  CHECK(IsJSSegmentDataObjectWithIsWordLike(o, isolate));
  {
    Tagged<Object> is_word_like__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, is_word_like__value);
    CHECK(IsBoolean(is_word_like__value));
  }
}
void TorqueGeneratedClassVerifiers::JSSegmenterVerify(Tagged<JSSegmenter> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSSegmenter(o, isolate));
  {
    Tagged<Object> locale__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, locale__value);
    CHECK(IsString(locale__value));
  }
  {
    Tagged<Object> icu_break_iterator__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, icu_break_iterator__value);
    CHECK(IsForeign(icu_break_iterator__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::JSSegmentsVerify(Tagged<JSSegments> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsJSSegments(o, isolate));
  {
    Tagged<Object> icu_break_iterator__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, icu_break_iterator__value);
    CHECK(IsForeign(icu_break_iterator__value));
  }
  {
    Tagged<Object> raw_string__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, raw_string__value);
    CHECK(IsString(raw_string__value));
  }
  {
    Tagged<Object> unicode_string__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, unicode_string__value);
    CHECK(IsForeign(unicode_string__value));
  }
  {
    Tagged<Object> flags__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, flags__value);
    CHECK(IsSmi(flags__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmImportDataVerify(Tagged<WasmImportData> o, Isolate* isolate) {
  CHECK(IsWasmImportData(o, isolate));
  {
    Tagged<Object> native_context__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, native_context__value);
    CHECK(IsNativeContext(native_context__value));
  }
  {
    Tagged<Object> callable__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, callable__value);
    CHECK(IsJSReceiver(callable__value) || IsUndefined(callable__value));
  }
  {
    Tagged<Object> suspend__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, suspend__value);
    CHECK(IsSmi(suspend__value));
  }
  {
    Tagged<Object> wrapper_budget__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, wrapper_budget__value);
    CHECK(IsSmi(wrapper_budget__value));
  }
  {
    Tagged<Object> call_origin__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, call_origin__value);
    CHECK(IsSmi(call_origin__value) || IsWasmFuncRef(call_origin__value) || IsTuple2(call_origin__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmInstanceObjectVerify(Tagged<WasmInstanceObject> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsWasmInstanceObject(o, isolate));
  {
    Tagged<Object> module_object__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, module_object__value);
    CHECK(IsWasmModuleObject(module_object__value));
  }
  {
    Tagged<Object> exports_object__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, exports_object__value);
    CHECK(IsJSObject(exports_object__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmFastApiCallDataVerify(Tagged<WasmFastApiCallData> o, Isolate* isolate) {
  CHECK(IsWasmFastApiCallData(o, isolate));
  {
    Tagged<Object> signature__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, signature__value);
    CHECK(IsHeapObject(signature__value));
  }
  {
    Tagged<Object> callback_data__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, callback_data__value);
  }
  {
    Tagged<MaybeObject> cached_map__value = TaggedField<MaybeObject>::load(o, 12);
    Object::VerifyMaybeObjectPointer(isolate, cached_map__value);
    CHECK(cached_map__value.IsCleared() || (!cached_map__value.IsWeak() && IsNull(cached_map__value.GetHeapObjectOrSmi())) || (cached_map__value.IsWeak() && IsMap(cached_map__value.GetHeapObjectOrSmi())));
  }
}
void TorqueGeneratedClassVerifiers::WasmInternalFunctionVerify(Tagged<WasmInternalFunction> o, Isolate* isolate) {
  CHECK(IsWasmInternalFunction(o, isolate));
  {
    Tagged<Object> external__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, external__value);
    CHECK(IsUndefined(external__value) || IsJSFunction(external__value));
  }
  {
    Tagged<Object> function_index__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, function_index__value);
    CHECK(IsSmi(function_index__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmFunctionDataVerify(Tagged<WasmFunctionData> o, Isolate* isolate) {
  CHECK(IsWasmFunctionData(o, isolate));
  {
    Tagged<Object> func_ref__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, func_ref__value);
    CHECK(IsWasmFuncRef(func_ref__value));
  }
  {
    Tagged<Object> js_promise_flags__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, js_promise_flags__value);
    CHECK(IsSmi(js_promise_flags__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmExportedFunctionDataVerify(Tagged<WasmExportedFunctionData> o, Isolate* isolate) {
  o->WasmFunctionDataVerify(isolate);
  CHECK(IsWasmExportedFunctionData(o, isolate));
  {
    Tagged<Object> function_index__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, function_index__value);
    CHECK(IsSmi(function_index__value));
  }
  {
    Tagged<Object> wrapper_budget__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, wrapper_budget__value);
    CHECK(IsCell(wrapper_budget__value));
  }
  {
    Tagged<Object> canonical_type_index__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, canonical_type_index__value);
    CHECK(IsSmi(canonical_type_index__value));
  }
  {
    Tagged<Object> packed_args_size__value = TaggedField<Object>::load(o, 36);
    Object::VerifyPointer(isolate, packed_args_size__value);
    CHECK(IsSmi(packed_args_size__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmJSFunctionDataVerify(Tagged<WasmJSFunctionData> o, Isolate* isolate) {
  o->WasmFunctionDataVerify(isolate);
  CHECK(IsWasmJSFunctionData(o, isolate));
  {
    Tagged<Object> canonical_sig_index__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, canonical_sig_index__value);
    CHECK(IsSmi(canonical_sig_index__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmCapiFunctionDataVerify(Tagged<WasmCapiFunctionData> o, Isolate* isolate) {
  o->WasmFunctionDataVerify(isolate);
  CHECK(IsWasmCapiFunctionData(o, isolate));
  {
    Tagged<Object> canonical_sig_index__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, canonical_sig_index__value);
    CHECK(IsSmi(canonical_sig_index__value));
  }
  {
    Tagged<Object> embedder_data__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, embedder_data__value);
    CHECK(IsForeign(embedder_data__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmResumeDataVerify(Tagged<WasmResumeData> o, Isolate* isolate) {
  CHECK(IsWasmResumeData(o, isolate));
  {
    Tagged<Object> suspender__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, suspender__value);
    CHECK(IsWasmSuspenderObject(suspender__value));
  }
  {
    Tagged<Object> on_resume__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, on_resume__value);
    CHECK(IsSmi(on_resume__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmContinuationObjectVerify(Tagged<WasmContinuationObject> o, Isolate* isolate) {
  CHECK(IsWasmContinuationObject(o, isolate));
  {
    Tagged<Object> parent__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, parent__value);
    CHECK(IsUndefined(parent__value) || IsWasmContinuationObject(parent__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmSuspenderObjectVerify(Tagged<WasmSuspenderObject> o, Isolate* isolate) {
  CHECK(IsWasmSuspenderObject(o, isolate));
  {
    Tagged<Object> continuation__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, continuation__value);
    CHECK(IsUndefined(continuation__value) || IsWasmContinuationObject(continuation__value));
  }
  {
    Tagged<Object> parent__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, parent__value);
    CHECK(IsUndefined(parent__value) || IsWasmSuspenderObject(parent__value));
  }
  {
    Tagged<Object> promise__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, promise__value);
    CHECK(IsJSPromise(promise__value));
  }
  {
    Tagged<Object> resume__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, resume__value);
    CHECK(IsUndefined(resume__value) || IsJSObject(resume__value));
  }
  {
    Tagged<Object> reject__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, reject__value);
    CHECK(IsUndefined(reject__value) || IsJSObject(reject__value));
  }
  {
    Tagged<Object> state__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, state__value);
    CHECK(IsSmi(state__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmExceptionTagVerify(Tagged<WasmExceptionTag> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsWasmExceptionTag(o, isolate));
  {
    Tagged<Object> index__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, index__value);
    CHECK(IsSmi(index__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmModuleObjectVerify(Tagged<WasmModuleObject> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsWasmModuleObject(o, isolate));
  {
    Tagged<Object> managed_native_module__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, managed_native_module__value);
    CHECK(IsForeign(managed_native_module__value));
  }
  {
    Tagged<Object> script__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, script__value);
    CHECK(IsScript(script__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmTableObjectVerify(Tagged<WasmTableObject> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsWasmTableObject(o, isolate));
  {
    Tagged<Object> entries__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, entries__value);
    CHECK(IsFixedArray(entries__value));
  }
  {
    Tagged<Object> current_length__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, current_length__value);
    CHECK(IsSmi(current_length__value));
  }
  {
    Tagged<Object> maximum_length__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, maximum_length__value);
    CHECK(IsUndefined(maximum_length__value) || IsBigInt(maximum_length__value) || IsHeapNumber(maximum_length__value) || IsSmi(maximum_length__value));
  }
  {
    Tagged<Object> uses__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, uses__value);
    CHECK(IsFixedArray(uses__value));
  }
  {
    Tagged<Object> raw_type__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, raw_type__value);
    CHECK(IsSmi(raw_type__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmMemoryObjectVerify(Tagged<WasmMemoryObject> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsWasmMemoryObject(o, isolate));
  {
    Tagged<Object> array_buffer__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, array_buffer__value);
    CHECK(IsJSArrayBuffer(array_buffer__value));
  }
  {
    Tagged<Object> maximum_pages__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, maximum_pages__value);
    CHECK(IsSmi(maximum_pages__value));
  }
  {
    Tagged<Object> instances__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, instances__value);
    CHECK(IsWeakArrayList(instances__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmGlobalObjectVerify(Tagged<WasmGlobalObject> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsWasmGlobalObject(o, isolate));
  {
    Tagged<Object> untagged_buffer__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, untagged_buffer__value);
    CHECK(IsUndefined(untagged_buffer__value) || IsJSArrayBuffer(untagged_buffer__value));
  }
  {
    Tagged<Object> tagged_buffer__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, tagged_buffer__value);
    CHECK(IsUndefined(tagged_buffer__value) || IsFixedArray(tagged_buffer__value));
  }
  {
    Tagged<Object> offset__value = TaggedField<Object>::load(o, 24);
    Object::VerifyPointer(isolate, offset__value);
    CHECK(IsSmi(offset__value));
  }
  {
    Tagged<Object> raw_type__value = TaggedField<Object>::load(o, 28);
    Object::VerifyPointer(isolate, raw_type__value);
    CHECK(IsSmi(raw_type__value));
  }
  {
    Tagged<Object> is_mutable__value = TaggedField<Object>::load(o, 32);
    Object::VerifyPointer(isolate, is_mutable__value);
    CHECK(IsSmi(is_mutable__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmTagObjectVerify(Tagged<WasmTagObject> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsWasmTagObject(o, isolate));
  {
    Tagged<Object> serialized_signature__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, serialized_signature__value);
    CHECK(IsByteArray(serialized_signature__value));
  }
  {
    Tagged<Object> tag__value = TaggedField<Object>::load(o, 16);
    Object::VerifyPointer(isolate, tag__value);
    CHECK(IsHeapObject(tag__value));
  }
  {
    Tagged<Object> canonical_type_index__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, canonical_type_index__value);
    CHECK(IsSmi(canonical_type_index__value));
  }
}
void TorqueGeneratedClassVerifiers::AsmWasmDataVerify(Tagged<AsmWasmData> o, Isolate* isolate) {
  o->StructVerify(isolate);
  CHECK(IsAsmWasmData(o, isolate));
  {
    Tagged<Object> managed_native_module__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, managed_native_module__value);
    CHECK(IsForeign(managed_native_module__value));
  }
  {
    Tagged<Object> uses_bitset__value = TaggedField<Object>::load(o, 8);
    Object::VerifyPointer(isolate, uses_bitset__value);
    CHECK(IsHeapNumber(uses_bitset__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmTypeInfoVerify(Tagged<WasmTypeInfo> o, Isolate* isolate) {
  CHECK(IsWasmTypeInfo(o, isolate));
  {
    Tagged<Object> supertypes_length__value = TaggedField<Object>::load(o, 20);
    Object::VerifyPointer(isolate, supertypes_length__value);
    CHECK(IsSmi(supertypes_length__value));
  }
  intptr_t supertypes__offset, supertypes__length;
  std::tie(std::ignore, supertypes__offset, supertypes__length) = TqRuntimeFieldSliceWasmTypeInfoSupertypes(o);
  CHECK_EQ(supertypes__offset, static_cast<int>(supertypes__offset));
  CHECK_EQ(supertypes__length, static_cast<int>(supertypes__length));
  for (int i = 0; i < static_cast<int>(supertypes__length); ++i) {
    Tagged<Object> supertypes__value = TaggedField<Object>::load(o, static_cast<int>(supertypes__offset) + i * kTaggedSize);
    Object::VerifyPointer(isolate, supertypes__value);
  }
}
void TorqueGeneratedClassVerifiers::WasmObjectVerify(Tagged<WasmObject> o, Isolate* isolate) {
  o->JSReceiverVerify(isolate);
  CHECK(IsWasmObject(o, isolate));
}
void TorqueGeneratedClassVerifiers::WasmStructVerify(Tagged<WasmStruct> o, Isolate* isolate) {
  o->WasmObjectVerify(isolate);
  CHECK(IsWasmStruct(o, isolate));
}
void TorqueGeneratedClassVerifiers::WasmArrayVerify(Tagged<WasmArray> o, Isolate* isolate) {
  o->WasmObjectVerify(isolate);
  CHECK(IsWasmArray(o, isolate));
}
void TorqueGeneratedClassVerifiers::WasmStringViewIterVerify(Tagged<WasmStringViewIter> o, Isolate* isolate) {
  CHECK(IsWasmStringViewIter(o, isolate));
  {
    Tagged<Object> string__value = TaggedField<Object>::load(o, 4);
    Object::VerifyPointer(isolate, string__value);
    CHECK(IsString(string__value));
  }
}
void TorqueGeneratedClassVerifiers::WasmSuspendingObjectVerify(Tagged<WasmSuspendingObject> o, Isolate* isolate) {
  o->JSObjectVerify(isolate);
  CHECK(IsWasmSuspendingObject(o, isolate));
  {
    Tagged<Object> callable__value = TaggedField<Object>::load(o, 12);
    Object::VerifyPointer(isolate, callable__value);
    CHECK(IsJSReceiver(callable__value));
  }
}
}  // namespace internal
}  // namespace v8

#include "src/objects/object-macros-undef.h"
#endif  // VERIFY_HEAP
