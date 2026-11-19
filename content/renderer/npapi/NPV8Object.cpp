// Copyright (C) 2004, 2006 Apple Computer, Inc. All rights reserved.
// Copyright (C) 2007-2009 Google, Inc. All rights reserved.
// Ported and adapted for miniblink132 (V8 13.2).

#include "content/renderer/npapi/npruntime_priv.h"

#include <cstring>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>

#include "content/browser/MbWebview.h"
#include "content/common/LiveIdDetect.h"
#include "mbnet/cookies/WebCookieJarCurlImpl.h"
#include "third_party/blink/public/web/web_document.h"
#include "third_party/blink/public/web/web_local_frame.h"
#include "third_party/blink/renderer/platform/bindings/script_forbidden_scope.h"

#if defined(_WIN32)
#include <windows.h>
extern "C" WINBASEAPI BOOL WINAPI InternetSetCookieA(LPCSTR lpszUrl, LPCSTR lpszCookieName, LPCSTR lpszCookieData);
#endif

namespace content {

namespace {

class ScopedNPObjectRetain {
public:
    explicit ScopedNPObjectRetain(NPObject* obj)
        : m_obj(obj)
    {
        if (m_obj)
            _NPN_RetainObject(m_obj);
    }
    ~ScopedNPObjectRetain()
    {
        if (m_obj)
            _NPN_ReleaseObject(m_obj);
    }
    ScopedNPObjectRetain(const ScopedNPObjectRetain&) = delete;
    ScopedNPObjectRetain& operator=(const ScopedNPObjectRetain&) = delete;

private:
    NPObject* m_obj;
};

std::unordered_map<int, std::vector<V8NPObject*>>& v8NPObjectHashMap()
{
    static auto* s_map = new std::unordered_map<int, std::vector<V8NPObject*>>();
    return *s_map;
}

NPObject* allocV8NPObject(NPP, NPClass*)
{
    void* mem = calloc(1, sizeof(V8NPObject));
    if (!mem)
        return nullptr;
    auto* obj = new (mem) V8NPObject();
    return &obj->object;
}

void freeV8NPObject(NPObject* npObject)
{
    disposeV8NPObject(npObject);
    auto* v8NpObject = reinterpret_cast<V8NPObject*>(npObject);
    v8NpObject->~V8NPObject();
    free(v8NpObject);
}

NPClass g_v8NPObjectClass = {
    NP_CLASS_STRUCT_VERSION,
    allocV8NPObject,
    freeV8NPObject,
    nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
};

v8::Local<v8::String> npIdentifierToV8String(v8::Isolate* isolate, NPIdentifier name)
{
    auto* identifier = static_cast<PrivateIdentifier*>(name);
    if (!identifier)
        return v8::String::Empty(isolate);
    if (identifier->isString) {
        const char* s = identifier->value.string ? identifier->value.string : "";
        return v8::String::NewFromUtf8(isolate, s).FromMaybe(v8::String::Empty(isolate));
    }
    char buf[32];
    snprintf(buf, sizeof(buf), "%d", identifier->value.number);
    return v8::String::NewFromUtf8(isolate, buf).FromMaybe(v8::String::Empty(isolate));
}

bool enterV8NPObjectContext(V8NPObject* obj, v8::Isolate* isolate, v8::Local<v8::Context>* outContext)
{
    if (!obj || obj->v8Object.IsEmpty())
        return false;
    if (!obj->v8Context.IsEmpty()) {
        *outContext = obj->v8Context.Get(isolate);
        return !outContext->IsEmpty();
    }
    if (obj->rootFrame) {
        *outContext = obj->rootFrame->MainWorldScriptContext();
        return !outContext->IsEmpty();
    }
    *outContext = isolate->GetCurrentContext();
    return !outContext->IsEmpty();
}

std::unique_ptr<v8::Local<v8::Value>[]> createValueListFromVariantArgs(
    v8::Isolate* isolate, v8::Local<v8::Context> context, const NPVariant* arguments, uint32_t argumentCount, NPObject* owner)
{
    std::unique_ptr<v8::Local<v8::Value>[]> argv(new v8::Local<v8::Value>[argumentCount > 0 ? argumentCount : 1]);
    for (uint32_t i = 0; i < argumentCount; ++i)
        argv[i] = convertNPVariantToV8Object(isolate, context, &arguments[i], owner);
    return argv;
}

#if defined(_WIN32)
void syncSwfUploadCookiesToWinInet(V8NPObject* v8NpObject)
{
    if (!v8NpObject || !v8NpObject->rootFrame || !v8NpObject->mbwebviewId)
        return;

    auto* webview = static_cast<MbWebView*>(common::LiveIdDetect::getMbWebviewIds()->getPtr(v8NpObject->mbwebviewId));
    if (!webview)
        return;

    mbnet::WebCookieJarImpl* cookieJar = webview->getWebCookieJarImpl();
    if (!cookieJar)
        return;

    blink::KURL docUrl(v8NpObject->rootFrame->GetDocument().Url());
    if (!docUrl.ProtocolIsInHTTPFamily())
        return;

    std::string cookie = cookieJar->getCookiesForSession(docUrl, false);
    if (cookie.size() < 3)
        return;
    if (cookie.back() != ';')
        cookie += "; ";

    std::string host = docUrl.Protocol().Utf8() + "://" + docUrl.Host().Utf8();
    if (docUrl.HasPort())
        host += ":" + std::to_string(docUrl.Port());

    size_t pos = 0;
    while (pos < cookie.size()) {
        while (pos < cookie.size() && cookie[pos] == ' ')
            ++pos;
        size_t eq = cookie.find('=', pos);
        if (eq == std::string::npos)
            break;
        size_t semi = cookie.find(';', eq + 1);
        if (semi == std::string::npos)
            break;

        std::string key = cookie.substr(pos, eq - pos);
        std::string val = cookie.substr(eq + 1, semi - eq - 1);
        pos = semi + 1;

        if (key.empty() || key.find_first_of(";\r\n") != std::string::npos
            || val.find_first_of(";\r\n") != std::string::npos) {
            continue;
        }

        // Write as session-scoped cookie (no permanent expires) to avoid persisting credentials in IE cache.
        std::string setLine = val + ";path=/";
        ::InternetSetCookieA(host.c_str(), key.c_str(), setLine.c_str());
    }
}
#endif

} // namespace

NPIdentifier getStringIdentifierFromV8(v8::Isolate* isolate, v8::Local<v8::String> str)
{
    if (str.IsEmpty())
        return _NPN_GetStringIdentifier("");
    char stackBuf[128];
    int utf8Len = str->Utf8Length(isolate);
    if (utf8Len + 1 <= static_cast<int>(sizeof(stackBuf))) {
        str->WriteUtf8(isolate, stackBuf, utf8Len + 1);
        return _NPN_GetStringIdentifier(stackBuf);
    }
    v8::String::Utf8Value utf8(isolate, str);
    return _NPN_GetStringIdentifier(*utf8 ? *utf8 : "");
}

void convertV8ObjectToNPVariant(
    v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Value> object, NPObject* owner, NPVariant* result)
{
    VOID_TO_NPVARIANT(*result);
    if (object.IsEmpty())
        return;

    if (object->IsInt32()) {
        INT32_TO_NPVARIANT(object.As<v8::Int32>()->Value(), *result);
    } else if (object->IsNumber()) {
        DOUBLE_TO_NPVARIANT(object.As<v8::Number>()->Value(), *result);
    } else if (object->IsBoolean()) {
        BOOLEAN_TO_NPVARIANT(object.As<v8::Boolean>()->Value(), *result);
    } else if (object->IsNull()) {
        NULL_TO_NPVARIANT(*result);
    } else if (object->IsUndefined()) {
        VOID_TO_NPVARIANT(*result);
    } else if (object->IsString()) {
        v8::Local<v8::String> str = object.As<v8::String>();
        int utf8Len = str->Utf8Length(isolate);
        char* utf8Chars = static_cast<char*>(NPN_MemAlloc(static_cast<uint32_t>(utf8Len + 1)));
        if (!utf8Chars)
            return;
        str->WriteUtf8(isolate, utf8Chars, utf8Len + 1);
        STRINGN_TO_NPVARIANT(utf8Chars, static_cast<uint32_t>(utf8Len), *result);
    } else if (object->IsObject()) {
        blink::WebLocalFrame* rootFrame = nullptr;
        NPP ownerInstance = nullptr;
        int64_t mbwebviewId = 0;
        if (V8NPObject* ownerV8 = npObjectToV8NPObject(owner)) {
            rootFrame = ownerV8->rootFrame;
            ownerInstance = ownerV8->ownerInstance;
            mbwebviewId = ownerV8->mbwebviewId;
        }
        NPObject* npobject = npCreateV8ScriptObject(isolate, context, ownerInstance, object.As<v8::Object>(), rootFrame, mbwebviewId);
        if (npobject)
            _NPN_RegisterObject(npobject, owner);
        OBJECT_TO_NPVARIANT(npobject, *result);
    }
}

v8::Local<v8::Value> convertNPVariantToV8Object(
    v8::Isolate* isolate, v8::Local<v8::Context> context, const NPVariant* variant, NPObject* owner)
{
    if (!variant)
        return v8::Undefined(isolate);

    switch (variant->type) {
    case NPVariantType_Int32:
        return v8::Integer::New(isolate, NPVARIANT_TO_INT32(*variant));
    case NPVariantType_Double:
        return v8::Number::New(isolate, NPVARIANT_TO_DOUBLE(*variant));
    case NPVariantType_Bool:
        return v8::Boolean::New(isolate, NPVARIANT_TO_BOOLEAN(*variant));
    case NPVariantType_Null:
        return v8::Null(isolate);
    case NPVariantType_Void:
        return v8::Undefined(isolate);
    case NPVariantType_String: {
        NPString src = NPVARIANT_TO_STRING(*variant);
        if (!src.UTF8Characters || src.UTF8Length == 0)
            return v8::String::Empty(isolate);
        return v8::String::NewFromUtf8(isolate, src.UTF8Characters, v8::NewStringType::kNormal, src.UTF8Length)
            .FromMaybe(v8::String::Empty(isolate));
    }
    case NPVariantType_Object: {
        NPObject* obj = NPVARIANT_TO_OBJECT(*variant);
        if (!obj)
            return v8::Null(isolate);
        if (V8NPObject* v8Obj = npObjectToV8NPObject(obj))
            return v8Obj->v8Object.Get(isolate);
        return createV8ObjectForNPObject(isolate, context, obj, owner);
    }
    default:
        return v8::Undefined(isolate);
    }
}

V8NPObject* npObjectToV8NPObject(NPObject* npObject)
{
    if (!npObject || npObject->_class != &g_v8NPObjectClass)
        return nullptr;
    auto* v8NpObject = reinterpret_cast<V8NPObject*>(npObject);
    return v8NpObject->v8Object.IsEmpty() ? nullptr : v8NpObject;
}

void disposeV8NPObject(NPObject* npObject)
{
    if (!npObject || npObject->_class != &g_v8NPObjectClass)
        return;
    auto* v8NpObject = reinterpret_cast<V8NPObject*>(npObject);
    if (v8NpObject->identityHash != 0) {
        auto& hashMap = v8NPObjectHashMap();
        auto it = hashMap.find(v8NpObject->identityHash);
        if (it != hashMap.end()) {
            auto& bucket = it->second;
            for (auto vit = bucket.begin(); vit != bucket.end(); ++vit) {
                if (*vit == v8NpObject) {
                    bucket.erase(vit);
                    break;
                }
            }
            if (bucket.empty())
                hashMap.erase(it);
        }
        v8NpObject->identityHash = 0;
    }
    v8NpObject->v8Object.Reset();
    v8NpObject->v8Context.Reset();
    v8NpObject->rootFrame = nullptr;
    v8NpObject->ownerInstance = nullptr;
}

NPObject* npCreateV8ScriptObject(
    v8::Isolate* isolate, v8::Local<v8::Context> context, NPP npp, v8::Local<v8::Object> object, blink::WebLocalFrame* rootFrame, int64_t mbwebviewId)
{
    if (object.IsEmpty())
        return nullptr;

    if (isWrappedNPObject(object)) {
        NPObject* unwrapped = v8ObjectToNPObject(object);
        if (unwrapped)
            _NPN_RetainObject(unwrapped);
        return unwrapped;
    }

    int hash = object->GetIdentityHash();
    auto& hashMap = v8NPObjectHashMap();
    if (hash != 0) {
        auto it = hashMap.find(hash);
        if (it != hashMap.end()) {
            for (V8NPObject* existing : it->second) {
                if (existing && !existing->v8Object.IsEmpty()
                    && existing->ownerInstance == npp
                    && existing->rootFrame == rootFrame
                    && (context.IsEmpty() || existing->v8Context.IsEmpty() || existing->v8Context.Get(isolate) == context)
                    && existing->v8Object.Get(isolate) == object) {
                    _NPN_RetainObject(&existing->object);
                    return reinterpret_cast<NPObject*>(existing);
                }
            }
        }
    }

    auto* v8npObject = reinterpret_cast<V8NPObject*>(_NPN_CreateObject(npp, &g_v8NPObjectClass));
    if (!v8npObject)
        return nullptr;

    v8npObject->v8Object.Reset(isolate, object);
    if (!context.IsEmpty())
        v8npObject->v8Context.Reset(isolate, context);
    v8npObject->rootFrame = rootFrame;
    v8npObject->ownerInstance = npp;
    v8npObject->mbwebviewId = mbwebviewId;
    v8npObject->identityHash = hash;
    if (hash != 0)
        hashMap[hash].push_back(v8npObject);
    return reinterpret_cast<NPObject*>(v8npObject);
}

} // namespace content

extern "C" {

bool _NPN_Invoke(NPP npp, NPObject* npObject, NPIdentifier methodName, const NPVariant* arguments, uint32_t argumentCount, NPVariant* result)
{
    if (!npObject)
        return false;
    if (result)
        VOID_TO_NPVARIANT(*result);

    content::ScopedNPObjectRetain retain(npObject);
    content::V8NPObject* v8NpObject = content::npObjectToV8NPObject(npObject);
    if (!v8NpObject) {
        if (npObject->_class && npObject->_class->invoke)
            return npObject->_class->invoke(npObject, methodName, arguments, argumentCount, result);
        return false;
    }

    auto* identifier = static_cast<content::PrivateIdentifier*>(methodName);
    if (!identifier || !identifier->isString)
        return false;

    if (identifier->value.string && !strcmp(identifier->value.string, "eval")) {
        if (argumentCount != 1 || arguments[0].type != NPVariantType_String)
            return false;
        return _NPN_Evaluate(npp, npObject, const_cast<NPString*>(&arguments[0].value.stringValue), result);
    }

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    if (!isolate)
        return false;
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::Context> context;
    if (!content::enterV8NPObjectContext(v8NpObject, isolate, &context))
        return false;

    v8::Context::Scope contextScope(context);
    v8::MicrotasksScope microtasksScope(context, v8::MicrotasksScope::Type::kRunMicrotasks);
    v8::TryCatch tryCatch(isolate);

    v8::Local<v8::Object> recv = v8NpObject->v8Object.Get(isolate);
    v8::Local<v8::Value> fnVal;
    if (!recv->Get(context, content::npIdentifierToV8String(isolate, methodName)).ToLocal(&fnVal) || !fnVal->IsFunction())
        return false;

    auto argv = content::createValueListFromVariantArgs(isolate, context, arguments, argumentCount, npObject);
    v8::Local<v8::Value> retVal;
    if (!fnVal.As<v8::Function>()->Call(context, recv, argumentCount, argv.get()).ToLocal(&retVal))
        return false;

    if (_NPN_IsAlive(npObject) && result)
        content::convertV8ObjectToNPVariant(isolate, context, retVal, npObject, result);
    return true;
}

bool _NPN_InvokeDefault(NPP, NPObject* npObject, const NPVariant* arguments, uint32_t argumentCount, NPVariant* result)
{
    if (!npObject)
        return false;
    if (result)
        VOID_TO_NPVARIANT(*result);

    content::ScopedNPObjectRetain retain(npObject);
    content::V8NPObject* v8NpObject = content::npObjectToV8NPObject(npObject);
    if (!v8NpObject) {
        if (npObject->_class && npObject->_class->invokeDefault)
            return npObject->_class->invokeDefault(npObject, arguments, argumentCount, result);
        return false;
    }

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    if (!isolate)
        return false;
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::Context> context;
    if (!content::enterV8NPObjectContext(v8NpObject, isolate, &context))
        return false;

    v8::Context::Scope contextScope(context);
    v8::MicrotasksScope microtasksScope(context, v8::MicrotasksScope::Type::kRunMicrotasks);
    v8::TryCatch tryCatch(isolate);

    v8::Local<v8::Object> fnObj = v8NpObject->v8Object.Get(isolate);
    if (!fnObj->IsFunction())
        return false;

    auto argv = content::createValueListFromVariantArgs(isolate, context, arguments, argumentCount, npObject);
    v8::Local<v8::Value> retVal;
    if (!fnObj.As<v8::Function>()->Call(context, context->Global(), argumentCount, argv.get()).ToLocal(&retVal))
        return false;

    if (_NPN_IsAlive(npObject) && result)
        content::convertV8ObjectToNPVariant(isolate, context, retVal, npObject, result);
    return true;
}

bool _NPN_Evaluate(NPP npp, NPObject* npObject, NPString* npScript, NPVariant* result)
{
    return _NPN_EvaluateHelper(npp, false, npObject, npScript, result);
}

bool _NPN_EvaluateHelper(NPP, bool popupsAllowed, NPObject* npObject, NPString* npScript, NPVariant* result)
{
    if (result)
        VOID_TO_NPVARIANT(*result);
    if (blink::ScriptForbiddenScope::IsScriptForbidden() || !npObject || !npScript)
        return false;

    content::ScopedNPObjectRetain retain(npObject);
    content::V8NPObject* v8NpObject = content::npObjectToV8NPObject(npObject);
    if (!v8NpObject)
        return false;

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    if (!isolate)
        return false;
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::Context> context;
    if (!content::enterV8NPObjectContext(v8NpObject, isolate, &context))
        return false;

    if (popupsAllowed && v8NpObject->rootFrame)
        v8NpObject->rootFrame->NotifyUserActivation(blink::mojom::UserActivationNotificationType::kInteraction);

    v8::Context::Scope contextScope(context);
    v8::MicrotasksScope microtasksScope(context, v8::MicrotasksScope::Type::kRunMicrotasks);
    v8::TryCatch tryCatch(isolate);

    std::string scriptStd;
    if (npScript->UTF8Characters && npScript->UTF8Length > 0)
        scriptStd.assign(npScript->UTF8Characters, npScript->UTF8Length);
#if defined(_WIN32)
    if (scriptStd.find("SWFUpload") != std::string::npos && scriptStd.find("uploadStart(") != std::string::npos)
        content::syncSwfUploadCookiesToWinInet(v8NpObject);
#endif

    v8::Local<v8::String> source;
    if (!v8::String::NewFromUtf8(isolate, scriptStd.data(), v8::NewStringType::kNormal, static_cast<int>(scriptStd.size())).ToLocal(&source))
        return false;

    v8::Local<v8::Script> compiled;
    if (!v8::Script::Compile(context, source).ToLocal(&compiled))
        return false;

    v8::Local<v8::Value> v8result;
    if (!compiled->Run(context).ToLocal(&v8result))
        return false;

    if (_NPN_IsAlive(npObject) && result)
        content::convertV8ObjectToNPVariant(isolate, context, v8result, npObject, result);
    return true;
}

bool _NPN_GetProperty(NPP, NPObject* npObject, NPIdentifier propertyName, NPVariant* result)
{
    if (!npObject || !result)
        return false;
    VOID_TO_NPVARIANT(*result);

    content::ScopedNPObjectRetain retain(npObject);
    if (content::V8NPObject* object = content::npObjectToV8NPObject(npObject)) {
        v8::Isolate* isolate = v8::Isolate::GetCurrent();
        if (!isolate)
            return false;
        v8::HandleScope handleScope(isolate);
        v8::Local<v8::Context> context;
        if (!content::enterV8NPObjectContext(object, isolate, &context))
            return false;

        v8::Context::Scope contextScope(context);
        v8::MicrotasksScope microtasksScope(context, v8::MicrotasksScope::Type::kRunMicrotasks);
        v8::TryCatch tryCatch(isolate);

        v8::Local<v8::Object> obj = object->v8Object.Get(isolate);
        v8::Local<v8::Value> v8result;
        if (!obj->Get(context, content::npIdentifierToV8String(isolate, propertyName)).ToLocal(&v8result))
            return false;

        if (_NPN_IsAlive(npObject))
            content::convertV8ObjectToNPVariant(isolate, context, v8result, npObject, result);
        return true;
    }

    if (npObject->_class && npObject->_class->hasProperty && npObject->_class->getProperty
        && npObject->_class->hasProperty(npObject, propertyName)) {
        return npObject->_class->getProperty(npObject, propertyName, result);
    }
    return false;
}

bool _NPN_SetProperty(NPP, NPObject* npObject, NPIdentifier propertyName, const NPVariant* value)
{
    if (!npObject || !value)
        return false;

    content::ScopedNPObjectRetain retain(npObject);
    if (content::V8NPObject* object = content::npObjectToV8NPObject(npObject)) {
        v8::Isolate* isolate = v8::Isolate::GetCurrent();
        if (!isolate)
            return false;
        v8::HandleScope handleScope(isolate);
        v8::Local<v8::Context> context;
        if (!content::enterV8NPObjectContext(object, isolate, &context))
            return false;

        v8::Context::Scope contextScope(context);
        v8::MicrotasksScope microtasksScope(context, v8::MicrotasksScope::Type::kRunMicrotasks);
        v8::TryCatch tryCatch(isolate);

        v8::Local<v8::Object> obj = object->v8Object.Get(isolate);
        v8::Local<v8::Value> v8Val = content::convertNPVariantToV8Object(isolate, context, value, npObject);
        return obj->Set(context, content::npIdentifierToV8String(isolate, propertyName), v8Val).FromMaybe(false);
    }

    if (npObject->_class && npObject->_class->setProperty)
        return npObject->_class->setProperty(npObject, propertyName, value);
    return false;
}

bool _NPN_RemoveProperty(NPP, NPObject* npObject, NPIdentifier propertyName)
{
    if (!npObject)
        return false;

    content::V8NPObject* object = content::npObjectToV8NPObject(npObject);
    if (!object)
        return (npObject->_class && npObject->_class->removeProperty) ? npObject->_class->removeProperty(npObject, propertyName) : false;

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    if (!isolate)
        return false;
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::Context> context;
    if (!content::enterV8NPObjectContext(object, isolate, &context))
        return false;

    v8::Context::Scope contextScope(context);
    v8::TryCatch tryCatch(isolate);

    v8::Local<v8::Object> obj = object->v8Object.Get(isolate);
    return obj->Delete(context, content::npIdentifierToV8String(isolate, propertyName)).FromMaybe(false);
}

bool _NPN_HasProperty(NPP, NPObject* npObject, NPIdentifier propertyName)
{
    if (!npObject)
        return false;

    if (content::V8NPObject* object = content::npObjectToV8NPObject(npObject)) {
        v8::Isolate* isolate = v8::Isolate::GetCurrent();
        if (!isolate)
            return false;
        v8::HandleScope handleScope(isolate);
        v8::Local<v8::Context> context;
        if (!content::enterV8NPObjectContext(object, isolate, &context))
            return false;

        v8::Context::Scope contextScope(context);
        v8::TryCatch tryCatch(isolate);

        v8::Local<v8::Object> obj = object->v8Object.Get(isolate);
        return obj->Has(context, content::npIdentifierToV8String(isolate, propertyName)).FromMaybe(false);
    }

    return (npObject->_class && npObject->_class->hasProperty) ? npObject->_class->hasProperty(npObject, propertyName) : false;
}

bool _NPN_HasMethod(NPP, NPObject* npObject, NPIdentifier methodName)
{
    if (!npObject)
        return false;

    if (content::V8NPObject* object = content::npObjectToV8NPObject(npObject)) {
        v8::Isolate* isolate = v8::Isolate::GetCurrent();
        if (!isolate)
            return false;
        v8::HandleScope handleScope(isolate);
        v8::Local<v8::Context> context;
        if (!content::enterV8NPObjectContext(object, isolate, &context))
            return false;

        v8::Context::Scope contextScope(context);
        v8::TryCatch tryCatch(isolate);

        v8::Local<v8::Object> obj = object->v8Object.Get(isolate);
        v8::Local<v8::Value> prop;
        if (!obj->Get(context, content::npIdentifierToV8String(isolate, methodName)).ToLocal(&prop))
            return false;
        return prop->IsFunction();
    }

    return (npObject->_class && npObject->_class->hasMethod) ? npObject->_class->hasMethod(npObject, methodName) : false;
}

void _NPN_SetException(NPObject*, const NPUTF8* message)
{
    const char* msg = message ? message : "NPObject exception";
    if (message) {
        OutputDebugStringA("_NPN_SetException: ");
        OutputDebugStringA(message);
        OutputDebugStringA("\n");
    }
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    if (isolate && isolate->InContext()) {
        v8::HandleScope handleScope(isolate);
        v8::Local<v8::String> str;
        if (v8::String::NewFromUtf8(isolate, msg).ToLocal(&str))
            isolate->ThrowException(v8::Exception::Error(str));
    }
}

bool _NPN_Enumerate(NPP, NPObject* npObject, NPIdentifier** identifier, uint32_t* count)
{
    if (!npObject || !identifier || !count)
        return false;

    content::ScopedNPObjectRetain retain(npObject);
    if (content::V8NPObject* object = content::npObjectToV8NPObject(npObject)) {
        v8::Isolate* isolate = v8::Isolate::GetCurrent();
        if (!isolate)
            return false;
        v8::HandleScope handleScope(isolate);
        v8::Local<v8::Context> context;
        if (!content::enterV8NPObjectContext(object, isolate, &context))
            return false;

        v8::Context::Scope contextScope(context);
        v8::TryCatch tryCatch(isolate);

        v8::Local<v8::Object> obj = object->v8Object.Get(isolate);
        v8::Local<v8::Array> props;
        if (!obj->GetPropertyNames(context).ToLocal(&props))
            return false;

        uint32_t propCount = props->Length();
        NPIdentifier* outIds = static_cast<NPIdentifier*>(NPN_MemAlloc(sizeof(NPIdentifier) * (propCount > 0 ? propCount : 1)));
        if (!outIds)
            return false;
        *count = propCount;
        *identifier = outIds;
        for (uint32_t i = 0; i < propCount; ++i) {
            v8::Local<v8::Value> nameVal;
            v8::Local<v8::String> nameStr;
            if (!props->Get(context, i).ToLocal(&nameVal) || !nameVal->ToString(context).ToLocal(&nameStr)) {
                (*identifier)[i] = _NPN_GetStringIdentifier("");
            } else {
                (*identifier)[i] = content::getStringIdentifierFromV8(isolate, nameStr);
            }
        }
        return true;
    }

    if (npObject->_class && NP_CLASS_STRUCT_VERSION_HAS_ENUM(npObject->_class) && npObject->_class->enumerate)
        return npObject->_class->enumerate(npObject, identifier, count);
    return false;
}

bool _NPN_Construct(NPP, NPObject* npObject, const NPVariant* arguments, uint32_t argumentCount, NPVariant* result)
{
    if (!npObject)
        return false;
    if (result)
        VOID_TO_NPVARIANT(*result);

    content::ScopedNPObjectRetain retain(npObject);
    if (content::V8NPObject* object = content::npObjectToV8NPObject(npObject)) {
        v8::Isolate* isolate = v8::Isolate::GetCurrent();
        if (!isolate)
            return false;
        v8::HandleScope handleScope(isolate);
        v8::Local<v8::Context> context;
        if (!content::enterV8NPObjectContext(object, isolate, &context))
            return false;

        v8::Context::Scope contextScope(context);
        v8::MicrotasksScope microtasksScope(context, v8::MicrotasksScope::Type::kRunMicrotasks);
        v8::TryCatch tryCatch(isolate);

        v8::Local<v8::Object> ctorObj = object->v8Object.Get(isolate);
        if (!ctorObj->IsFunction())
            return false;

        auto argv = content::createValueListFromVariantArgs(isolate, context, arguments, argumentCount, npObject);
        v8::Local<v8::Value> retObj;
        if (!ctorObj.As<v8::Function>()->CallAsConstructor(context, argumentCount, argv.get()).ToLocal(&retObj))
            return false;

        if (_NPN_IsAlive(npObject) && result)
            content::convertV8ObjectToNPVariant(isolate, context, retObj, npObject, result);
        return true;
    }

    if (npObject->_class && NP_CLASS_STRUCT_VERSION_HAS_CTOR(npObject->_class) && npObject->_class->construct)
        return npObject->_class->construct(npObject, arguments, argumentCount, result);
    return false;
}

} // extern "C"
