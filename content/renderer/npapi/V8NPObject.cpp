// Copyright (C) 2006-2009 Google Inc. All rights reserved.
// Ported and adapted for miniblink132 (V8 13.2).

#include "content/renderer/npapi/npruntime_priv.h"

#include <memory>
#include <unordered_map>
#include <vector>

namespace content {

namespace {

alignas(8) int g_npObjectWrapperMagic = 0x4E504F42; // 'NPOB'
v8::Eternal<v8::FunctionTemplate> g_npObjectTemplate;

class ScopedNPRetain {
public:
    explicit ScopedNPRetain(NPObject* obj)
        : m_obj(obj)
    {
        if (m_obj)
            _NPN_RetainObject(m_obj);
    }
    ~ScopedNPRetain()
    {
        if (m_obj)
            _NPN_ReleaseObject(m_obj);
    }
    ScopedNPRetain(const ScopedNPRetain&) = delete;
    ScopedNPRetain& operator=(const ScopedNPRetain&) = delete;

private:
    NPObject* m_obj;
};

enum InvokeFunctionType {
    kInvokeMethod = 1,
    kInvokeConstruct = 2,
    kInvokeDefault = 3
};

struct NPWrapperEntry {
    NPObject* npObject = nullptr;
    v8::Global<v8::Object> wrapper;
};

std::unordered_map<NPObject*, std::vector<NPWrapperEntry*>>& npWrapperMap()
{
    static auto* s_map = new std::unordered_map<NPObject*, std::vector<NPWrapperEntry*>>();
    return *s_map;
}

void removeEntryFromWrapperMap(NPObject* npObj, NPWrapperEntry* entry)
{
    if (!npObj)
        return;
    auto& map = npWrapperMap();
    auto it = map.find(npObj);
    if (it == map.end())
        return;
    auto& bucket = it->second;
    for (auto vit = bucket.begin(); vit != bucket.end(); ++vit) {
        if (*vit == entry) {
            bucket.erase(vit);
            break;
        }
    }
    if (bucket.empty())
        map.erase(it);
}

void onWrapperSecondPassWeakCallback(const v8::WeakCallbackInfo<NPWrapperEntry>& data)
{
    NPWrapperEntry* entry = data.GetParameter();
    if (!entry)
        return;

    NPObject* npObj = entry->npObject;
    delete entry;
    if (npObj && _NPN_IsAlive(npObj))
        _NPN_ReleaseObject(npObj);
}

void onWrapperFirstPassWeakCallback(const v8::WeakCallbackInfo<NPWrapperEntry>& data)
{
    NPWrapperEntry* entry = data.GetParameter();
    if (!entry)
        return;

    // First-pass GC callback: only reset the V8 handle and unlink map entry.
    // Defer releasing the NPObject (which may call into plugin deallocate/V8) to second pass.
    entry->wrapper.Reset();
    removeEntryFromWrapperMap(entry->npObject, entry);
    data.SetSecondPassCallback(onWrapperSecondPassWeakCallback);
}

void throwNPReferenceError(v8::Isolate* isolate, const char* msg)
{
    v8::Local<v8::String> str;
    if (v8::String::NewFromUtf8(isolate, msg).ToLocal(&str))
        isolate->ThrowException(v8::Exception::ReferenceError(str));
}

void throwNPGeneralError(v8::Isolate* isolate, const char* msg)
{
    v8::Local<v8::String> str;
    if (v8::String::NewFromUtf8(isolate, msg).ToLocal(&str))
        isolate->ThrowException(v8::Exception::Error(str));
}

void npObjectInvokeImpl(const v8::FunctionCallbackInfo<v8::Value>& info, InvokeFunctionType functionId)
{
    v8::Isolate* isolate = info.GetIsolate();
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    if (context.IsEmpty())
        return;

    NPObject* npObject = nullptr;
    v8::Local<v8::String> methodName;

    if (isWrappedNPObject(info.This())) {
        npObject = v8ObjectToNPObject(info.This());
    } else if (isWrappedNPObject(info.Holder())) {
        npObject = v8ObjectToNPObject(info.Holder());
    }

    if (functionId == kInvokeMethod && info.Data()->IsArray()) {
        v8::Local<v8::Array> dataArr = info.Data().As<v8::Array>();
        v8::Local<v8::Value> targetVal;
        if (!npObject && dataArr->Get(context, 0).ToLocal(&targetVal) && targetVal->IsObject()) {
            v8::Local<v8::Object> targetObj = targetVal.As<v8::Object>();
            if (isWrappedNPObject(targetObj))
                npObject = v8ObjectToNPObject(targetObj);
        }
        v8::Local<v8::Value> nameVal;
        if (dataArr->Get(context, 1).ToLocal(&nameVal) && nameVal->IsString())
            methodName = nameVal.As<v8::String>();
    } else if (info.Data()->IsString()) {
        methodName = info.Data().As<v8::String>();
    }

    if (!npObject || !_NPN_IsAlive(npObject) || !npObject->_class) {
        throwNPReferenceError(isolate, "NPObject deleted");
        return;
    }

    ScopedNPRetain retain(npObject);

    int numArgs = info.Length();
    std::unique_ptr<NPVariant[]> npArgs(new NPVariant[numArgs > 0 ? numArgs : 1]);
    for (int i = 0; i < numArgs; ++i)
        convertV8ObjectToNPVariant(isolate, context, info[i], npObject, &npArgs[i]);

    NPVariant result;
    VOID_TO_NPVARIANT(result);

    v8::TryCatch tryCatch(isolate);
    bool retval = false;
    switch (functionId) {
    case kInvokeMethod:
        if (npObject->_class->invoke && !methodName.IsEmpty()) {
            NPIdentifier identifier = getStringIdentifierFromV8(isolate, methodName);
            retval = npObject->_class->invoke(npObject, identifier, npArgs.get(), numArgs, &result);
        }
        break;
    case kInvokeConstruct:
        if (NP_CLASS_STRUCT_VERSION_HAS_CTOR(npObject->_class) && npObject->_class->construct)
            retval = npObject->_class->construct(npObject, npArgs.get(), numArgs, &result);
        break;
    case kInvokeDefault:
        if (npObject->_class->invokeDefault)
            retval = npObject->_class->invokeDefault(npObject, npArgs.get(), numArgs, &result);
        break;
    }

    for (int i = 0; i < numArgs; ++i)
        _NPN_ReleaseVariantValue(&npArgs[i]);

    if (tryCatch.HasCaught()) {
        _NPN_ReleaseVariantValue(&result);
        tryCatch.ReThrow();
        return;
    }

    if (!retval) {
        _NPN_ReleaseVariantValue(&result);
        throwNPGeneralError(isolate, "Error calling method on NPObject");
        return;
    }

    v8::Local<v8::Value> returnValue = v8::Undefined(isolate);
    if (_NPN_IsAlive(npObject))
        returnValue = convertNPVariantToV8Object(isolate, context, &result, npObject);
    _NPN_ReleaseVariantValue(&result);

    info.GetReturnValue().Set(returnValue);
}

void npObjectMethodHandler(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    npObjectInvokeImpl(info, kInvokeMethod);
}

void npObjectInvokeDefaultHandler(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    npObjectInvokeImpl(info, info.IsConstructCall() ? kInvokeConstruct : kInvokeDefault);
}

bool npObjectHasPropertyOrMethod(NPObject* npObject, NPIdentifier identifier, bool allowMethod)
{
    if (!npObject || !_NPN_IsAlive(npObject) || !npObject->_class)
        return false;
    ScopedNPRetain retain(npObject);
    if (npObject->_class->hasProperty && npObject->_class->hasProperty(npObject, identifier))
        return true;
    if (!_NPN_IsAlive(npObject) || !npObject->_class)
        return false;
    if (allowMethod && npObject->_class->hasMethod && npObject->_class->hasMethod(npObject, identifier))
        return true;
    return false;
}

v8::Intercepted npObjectGetImpl(
    v8::Isolate* isolate, v8::Local<v8::Object> holder, NPIdentifier identifier, v8::Local<v8::Value> key, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    NPObject* npObject = v8ObjectToNPObject(holder);
    if (!npObject || !_NPN_IsAlive(npObject) || !npObject->_class)
        return v8::Intercepted::kNo;

    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    if (context.IsEmpty())
        return v8::Intercepted::kNo;

    ScopedNPRetain retain(npObject);
    v8::TryCatch tryCatch(isolate);

    if (npObject->_class->hasProperty && npObject->_class->getProperty && npObject->_class->hasProperty(npObject, identifier)) {
        if (tryCatch.HasCaught()) {
            tryCatch.ReThrow();
            return v8::Intercepted::kYes;
        }
        if (!_NPN_IsAlive(npObject))
            return v8::Intercepted::kNo;

        NPVariant result;
        VOID_TO_NPVARIANT(result);
        bool ok = npObject->_class->getProperty(npObject, identifier, &result);
        if (tryCatch.HasCaught()) {
            _NPN_ReleaseVariantValue(&result);
            tryCatch.ReThrow();
            return v8::Intercepted::kYes;
        }
        if (!ok) {
            _NPN_ReleaseVariantValue(&result);
            info.GetReturnValue().Set(v8::Undefined(isolate));
            return v8::Intercepted::kYes;
        }

        v8::Local<v8::Value> returnValue = v8::Undefined(isolate);
        if (_NPN_IsAlive(npObject))
            returnValue = convertNPVariantToV8Object(isolate, context, &result, npObject);
        _NPN_ReleaseVariantValue(&result);
        info.GetReturnValue().Set(returnValue);
        return v8::Intercepted::kYes;
    }

    if (tryCatch.HasCaught()) {
        tryCatch.ReThrow();
        return v8::Intercepted::kYes;
    }
    if (!_NPN_IsAlive(npObject) || !npObject->_class)
        return v8::Intercepted::kNo;

    if (key->IsString() && npObject->_class->hasMethod && npObject->_class->hasMethod(npObject, identifier)) {
        if (tryCatch.HasCaught()) {
            tryCatch.ReThrow();
            return v8::Intercepted::kYes;
        }
        if (!_NPN_IsAlive(npObject))
            return v8::Intercepted::kNo;

        v8::Local<v8::Array> dataArr = v8::Array::New(isolate, 2);
        bool ok0 = dataArr->Set(context, 0, holder).FromMaybe(false);
        bool ok1 = dataArr->Set(context, 1, key).FromMaybe(false);
        if (!ok0 || !ok1)
            return v8::Intercepted::kNo;

        v8::Local<v8::Function> fn;
        if (!v8::Function::New(context, npObjectMethodHandler, dataArr).ToLocal(&fn))
            return v8::Intercepted::kNo;
        fn->SetName(key.As<v8::String>());
        info.GetReturnValue().Set(fn);
        return v8::Intercepted::kYes;
    }
    if (tryCatch.HasCaught()) {
        tryCatch.ReThrow();
        return v8::Intercepted::kYes;
    }

    return v8::Intercepted::kNo;
}

v8::Intercepted npObjectNamedPropertyGetter(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    if (!name->IsString())
        return v8::Intercepted::kNo;
    v8::Local<v8::String> nameStr = name.As<v8::String>();
    NPIdentifier identifier = getStringIdentifierFromV8(info.GetIsolate(), nameStr);
    return npObjectGetImpl(info.GetIsolate(), info.Holder(), identifier, nameStr, info);
}

v8::Intercepted npObjectIndexedPropertyGetter(uint32_t index, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    NPIdentifier identifier = _NPN_GetIntIdentifier(static_cast<int32_t>(index));
    return npObjectGetImpl(info.GetIsolate(), info.Holder(), identifier, v8::Number::New(info.GetIsolate(), index), info);
}

v8::Intercepted npObjectNamedPropertyQuery(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Integer>& info)
{
    if (!name->IsString())
        return v8::Intercepted::kNo;
    NPObject* npObject = v8ObjectToNPObject(info.Holder());
    NPIdentifier identifier = getStringIdentifierFromV8(info.GetIsolate(), name.As<v8::String>());
    if (!npObjectHasPropertyOrMethod(npObject, identifier, true))
        return v8::Intercepted::kNo;
    info.GetReturnValue().Set(static_cast<int32_t>(v8::None));
    return v8::Intercepted::kYes;
}

v8::Intercepted npObjectIndexedPropertyQuery(uint32_t index, const v8::PropertyCallbackInfo<v8::Integer>& info)
{
    NPObject* npObject = v8ObjectToNPObject(info.Holder());
    NPIdentifier identifier = _NPN_GetIntIdentifier(static_cast<int32_t>(index));
    if (!npObjectHasPropertyOrMethod(npObject, identifier, false))
        return v8::Intercepted::kNo;
    info.GetReturnValue().Set(static_cast<int32_t>(v8::None));
    return v8::Intercepted::kYes;
}

v8::Intercepted npObjectSetImpl(v8::Isolate* isolate, v8::Local<v8::Object> holder, NPIdentifier identifier, v8::Local<v8::Value> value)
{
    NPObject* npObject = v8ObjectToNPObject(holder);
    if (!npObject || !_NPN_IsAlive(npObject) || !npObject->_class)
        return v8::Intercepted::kNo;

    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    if (context.IsEmpty())
        return v8::Intercepted::kNo;

    ScopedNPRetain retain(npObject);
    v8::TryCatch tryCatch(isolate);

    if (npObject->_class->setProperty) {
        if (!_NPN_IsAlive(npObject))
            return v8::Intercepted::kNo;

        NPVariant npValue;
        VOID_TO_NPVARIANT(npValue);
        convertV8ObjectToNPVariant(isolate, context, value, npObject, &npValue);
        bool success = npObject->_class->setProperty(npObject, identifier, &npValue);
        _NPN_ReleaseVariantValue(&npValue);
        if (tryCatch.HasCaught()) {
            tryCatch.ReThrow();
            return v8::Intercepted::kYes;
        }
        return success ? v8::Intercepted::kYes : v8::Intercepted::kNo;
    }
    return v8::Intercepted::kNo;
}

v8::Intercepted npObjectNamedPropertySetter(v8::Local<v8::Name> name, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    if (!name->IsString())
        return v8::Intercepted::kNo;
    NPIdentifier identifier = getStringIdentifierFromV8(info.GetIsolate(), name.As<v8::String>());
    return npObjectSetImpl(info.GetIsolate(), info.Holder(), identifier, value);
}

v8::Intercepted npObjectIndexedPropertySetter(uint32_t index, v8::Local<v8::Value> value, const v8::PropertyCallbackInfo<void>& info)
{
    NPIdentifier identifier = _NPN_GetIntIdentifier(static_cast<int32_t>(index));
    return npObjectSetImpl(info.GetIsolate(), info.Holder(), identifier, value);
}

v8::Intercepted npObjectNamedPropertyDefiner(
    v8::Local<v8::Name> name, const v8::PropertyDescriptor& desc, const v8::PropertyCallbackInfo<void>& info)
{
    if (!name->IsString() || !desc.has_value())
        return v8::Intercepted::kNo;
    NPIdentifier identifier = getStringIdentifierFromV8(info.GetIsolate(), name.As<v8::String>());
    return npObjectSetImpl(info.GetIsolate(), info.Holder(), identifier, desc.value());
}

v8::Intercepted npObjectIndexedPropertyDefiner(
    uint32_t index, const v8::PropertyDescriptor& desc, const v8::PropertyCallbackInfo<void>& info)
{
    if (!desc.has_value())
        return v8::Intercepted::kNo;
    NPIdentifier identifier = _NPN_GetIntIdentifier(static_cast<int32_t>(index));
    return npObjectSetImpl(info.GetIsolate(), info.Holder(), identifier, desc.value());
}

v8::Intercepted npObjectDeleteImpl(
    v8::Local<v8::Object> holder, NPIdentifier identifier, const v8::PropertyCallbackInfo<v8::Boolean>& info)
{
    NPObject* npObject = v8ObjectToNPObject(holder);
    if (!npObject || !_NPN_IsAlive(npObject) || !npObject->_class)
        return v8::Intercepted::kNo;

    ScopedNPRetain retain(npObject);
    v8::Isolate* isolate = info.GetIsolate();
    v8::TryCatch tryCatch(isolate);

    if (npObject->_class->hasProperty && npObject->_class->removeProperty && npObject->_class->hasProperty(npObject, identifier)) {
        if (tryCatch.HasCaught()) {
            tryCatch.ReThrow();
            return v8::Intercepted::kYes;
        }
        if (!_NPN_IsAlive(npObject))
            return v8::Intercepted::kNo;
        bool removed = npObject->_class->removeProperty(npObject, identifier);
        if (tryCatch.HasCaught()) {
            tryCatch.ReThrow();
            return v8::Intercepted::kYes;
        }
        info.GetReturnValue().Set(removed);
        return v8::Intercepted::kYes;
    }
    if (tryCatch.HasCaught()) {
        tryCatch.ReThrow();
        return v8::Intercepted::kYes;
    }
    return v8::Intercepted::kNo;
}

v8::Intercepted npObjectNamedPropertyDeleter(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Boolean>& info)
{
    if (!name->IsString())
        return v8::Intercepted::kNo;
    NPIdentifier identifier = getStringIdentifierFromV8(info.GetIsolate(), name.As<v8::String>());
    return npObjectDeleteImpl(info.Holder(), identifier, info);
}

v8::Intercepted npObjectIndexedPropertyDeleter(uint32_t index, const v8::PropertyCallbackInfo<v8::Boolean>& info)
{
    NPIdentifier identifier = _NPN_GetIntIdentifier(static_cast<int32_t>(index));
    return npObjectDeleteImpl(info.Holder(), identifier, info);
}

void npObjectPropertyEnumerator(const v8::PropertyCallbackInfo<v8::Array>& info, bool namedProperty)
{
    v8::Isolate* isolate = info.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    NPObject* npObject = v8ObjectToNPObject(info.Holder());
    if (!npObject || !_NPN_IsAlive(npObject) || !npObject->_class || context.IsEmpty())
        return;

    ScopedNPRetain retain(npObject);
    v8::TryCatch tryCatch(isolate);

    if (NP_CLASS_STRUCT_VERSION_HAS_ENUM(npObject->_class) && npObject->_class->enumerate) {
        uint32_t count = 0;
        NPIdentifier* identifiers = nullptr;
        bool ok = npObject->_class->enumerate(npObject, &identifiers, &count);
        if (tryCatch.HasCaught()) {
            if (identifiers)
                NPN_MemFree(identifiers);
            tryCatch.ReThrow();
            return;
        }
        if (ok) {
            uint32_t matchCount = 0;
            if (identifiers) {
                for (uint32_t i = 0; i < count; ++i) {
                    auto* id = static_cast<PrivateIdentifier*>(identifiers[i]);
                    if (id && id->isString == namedProperty)
                        ++matchCount;
                }
            }
            v8::Local<v8::Array> arr = v8::Array::New(isolate, matchCount);
            uint32_t outIdx = 0;
            if (identifiers) {
                for (uint32_t i = 0; i < count; ++i) {
                    auto* id = static_cast<PrivateIdentifier*>(identifiers[i]);
                    if (!id || id->isString != namedProperty)
                        continue;
                    v8::Local<v8::Value> val;
                    if (namedProperty) {
                        val = v8::String::NewFromUtf8(isolate, id->value.string ? id->value.string : "")
                                  .FromMaybe(v8::String::Empty(isolate));
                    } else {
                        val = v8::Integer::New(isolate, id->value.number);
                    }
                    (void)arr->Set(context, outIdx++, val);
                }
                NPN_MemFree(identifiers);
            }
            info.GetReturnValue().Set(arr);
        }
    }
}

void npObjectNamedPropertyEnumerator(const v8::PropertyCallbackInfo<v8::Array>& info)
{
    npObjectPropertyEnumerator(info, true);
}

void npObjectIndexedPropertyEnumerator(const v8::PropertyCallbackInfo<v8::Array>& info)
{
    npObjectPropertyEnumerator(info, false);
}

} // namespace

bool isWrappedNPObject(v8::Local<v8::Object> object)
{
    if (object.IsEmpty() || g_npObjectTemplate.IsEmpty())
        return false;
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    if (!isolate || !g_npObjectTemplate.Get(isolate)->HasInstance(object))
        return false;
    if (object->InternalFieldCount() != 2)
        return false;
    return object->GetAlignedPointerFromInternalField(0) == &g_npObjectWrapperMagic;
}

NPObject* v8ObjectToNPObject(v8::Local<v8::Object> object)
{
    if (!isWrappedNPObject(object))
        return nullptr;
    return static_cast<NPObject*>(object->GetAlignedPointerFromInternalField(1));
}

v8::Local<v8::Object> createV8ObjectForNPObject(v8::Isolate* isolate, v8::Local<v8::Context> context, NPObject* object, NPObject* root)
{
    if (!object || context.IsEmpty())
        return v8::Local<v8::Object>();

    if (V8NPObject* v8NPObject = npObjectToV8NPObject(object))
        return v8NPObject->v8Object.Get(isolate);

    auto existingIt = npWrapperMap().find(object);
    if (existingIt != npWrapperMap().end()) {
        for (NPWrapperEntry* existing : existingIt->second) {
            if (!existing || existing->wrapper.IsEmpty())
                continue;
            v8::Local<v8::Object> existingObj = existing->wrapper.Get(isolate);
            v8::Local<v8::Context> existingCtx;
            if (existingObj->GetCreationContext(isolate).ToLocal(&existingCtx) && existingCtx == context)
                return existingObj;
        }
    }

    if (g_npObjectTemplate.IsEmpty()) {
        v8::Local<v8::FunctionTemplate> templ = v8::FunctionTemplate::New(isolate);
        templ->InstanceTemplate()->SetInternalFieldCount(2);
        templ->InstanceTemplate()->SetHandler(v8::NamedPropertyHandlerConfiguration(
            npObjectNamedPropertyGetter,
            npObjectNamedPropertySetter,
            npObjectNamedPropertyQuery,
            npObjectNamedPropertyDeleter,
            npObjectNamedPropertyEnumerator,
            npObjectNamedPropertyDefiner,
            nullptr,
            v8::Local<v8::Value>(),
            v8::PropertyHandlerFlags::kOnlyInterceptStrings));
        templ->InstanceTemplate()->SetHandler(v8::IndexedPropertyHandlerConfiguration(
            npObjectIndexedPropertyGetter,
            npObjectIndexedPropertySetter,
            npObjectIndexedPropertyQuery,
            npObjectIndexedPropertyDeleter,
            npObjectIndexedPropertyEnumerator,
            npObjectIndexedPropertyDefiner,
            nullptr));
        templ->InstanceTemplate()->SetCallAsFunctionHandler(npObjectInvokeDefaultHandler);
        g_npObjectTemplate.Set(isolate, templ);
    }

    v8::Local<v8::Function> ctor;
    if (!g_npObjectTemplate.Get(isolate)->GetFunction(context).ToLocal(&ctor))
        return v8::Local<v8::Object>();

    v8::Local<v8::Object> wrapper;
    if (!ctor->NewInstance(context).ToLocal(&wrapper))
        return v8::Local<v8::Object>();

    wrapper->SetAlignedPointerInInternalField(0, &g_npObjectWrapperMagic);
    wrapper->SetAlignedPointerInInternalField(1, object);

    _NPN_RetainObject(object);
    _NPN_RegisterObject(object, root);

    auto* entry = new NPWrapperEntry();
    entry->npObject = object;
    entry->wrapper.Reset(isolate, wrapper);
    entry->wrapper.SetWeak(entry, onWrapperFirstPassWeakCallback, v8::WeakCallbackType::kParameter);
    npWrapperMap()[object].push_back(entry);

    return wrapper;
}

void forgetV8ObjectForNPObject(NPObject* object)
{
    if (!object)
        return;

    auto it = npWrapperMap().find(object);
    if (it == npWrapperMap().end())
        return;

    std::vector<NPWrapperEntry*> entries = std::move(it->second);
    npWrapperMap().erase(it);

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    size_t releaseCount = 0;
    for (NPWrapperEntry* entry : entries) {
        if (!entry)
            continue;
        if (isolate && !entry->wrapper.IsEmpty()) {
            v8::HandleScope scope(isolate);
            v8::Local<v8::Object> wrapper = entry->wrapper.Get(isolate);
            if (wrapper->InternalFieldCount() == 2) {
                wrapper->SetAlignedPointerInInternalField(0, nullptr);
                wrapper->SetAlignedPointerInInternalField(1, nullptr);
            }
        }
        entry->wrapper.Reset();
        delete entry;
        ++releaseCount;
    }

    for (size_t i = 0; i < releaseCount; ++i)
        _NPN_ReleaseObject(object);
}

} // namespace content
