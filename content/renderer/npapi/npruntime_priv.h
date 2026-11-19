// Copyright (C) 2006-2009 Google Inc. All rights reserved.
// Ported and adapted for miniblink132 (V8 13.2).

#ifndef CONTENT_RENDERER_NPAPI_NPRUNTIME_PRIV_H_
#define CONTENT_RENDERER_NPAPI_NPRUNTIME_PRIV_H_

#include <stdint.h>

#include "third_party/npapi/bindings/npapi.h"
#include "third_party/npapi/bindings/npruntime.h"
#include "v8/include/v8.h"

namespace blink {
class WebLocalFrame;
}

#ifdef __cplusplus
extern "C" {
#endif

NPIdentifier _NPN_GetStringIdentifier(const NPUTF8* name);
void _NPN_GetStringIdentifiers(const NPUTF8** names, int32_t nameCount, NPIdentifier* identifiers);
NPIdentifier _NPN_GetIntIdentifier(int32_t intId);
bool _NPN_IdentifierIsString(NPIdentifier identifier);
NPUTF8* _NPN_UTF8FromIdentifier(NPIdentifier identifier);
int32_t _NPN_IntFromIdentifier(NPIdentifier identifier);
void _NPN_ReleaseVariantValue(NPVariant* variant);
NPObject* _NPN_CreateObject(NPP npp, NPClass* npClass);
NPObject* _NPN_RetainObject(NPObject* npObject);
void _NPN_ReleaseObject(NPObject* npObject);
void _NPN_DeallocateObject(NPObject* npObject);
void _NPN_InitializeVariantWithStringCopy(NPVariant* variant, const NPString* value);

bool _NPN_Invoke(NPP npp, NPObject* npObject, NPIdentifier methodName, const NPVariant* arguments, uint32_t argumentCount, NPVariant* result);
bool _NPN_InvokeDefault(NPP npp, NPObject* npObject, const NPVariant* arguments, uint32_t argumentCount, NPVariant* result);
bool _NPN_Evaluate(NPP npp, NPObject* npObject, NPString* npScript, NPVariant* result);
bool _NPN_EvaluateHelper(NPP npp, bool popupsAllowed, NPObject* npObject, NPString* npScript, NPVariant* result);
bool _NPN_GetProperty(NPP npp, NPObject* npObject, NPIdentifier propertyName, NPVariant* result);
bool _NPN_SetProperty(NPP npp, NPObject* npObject, NPIdentifier propertyName, const NPVariant* value);
bool _NPN_RemoveProperty(NPP npp, NPObject* npObject, NPIdentifier propertyName);
bool _NPN_HasProperty(NPP npp, NPObject* npObject, NPIdentifier propertyName);
bool _NPN_HasMethod(NPP npp, NPObject* npObject, NPIdentifier methodName);
void _NPN_SetException(NPObject* npObject, const NPUTF8* message);
bool _NPN_Enumerate(NPP npp, NPObject* npObject, NPIdentifier** identifier, uint32_t* count);
bool _NPN_Construct(NPP npp, NPObject* npObject, const NPVariant* arguments, uint32_t argumentCount, NPVariant* result);

void _NPN_RegisterObject(NPObject* npObject, NPObject* owner);
void _NPN_UnregisterObject(NPObject* npObject);
bool _NPN_IsAlive(NPObject* npObject);

#ifdef __cplusplus
}
#endif

namespace content {

struct PrivateIdentifier {
    union {
        const NPUTF8* string;
        int32_t number;
    } value;
    bool isString;
};

struct V8NPObject {
    NPObject object;
    v8::Global<v8::Object> v8Object;
    v8::Global<v8::Context> v8Context;
    blink::WebLocalFrame* rootFrame = nullptr;
    NPP ownerInstance = nullptr;
    int64_t mbwebviewId = 0;
    int identityHash = 0;
};

NPIdentifier getStringIdentifierFromV8(v8::Isolate* isolate, v8::Local<v8::String> str);
void convertV8ObjectToNPVariant(v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Value> object, NPObject* owner, NPVariant* result);
v8::Local<v8::Value> convertNPVariantToV8Object(v8::Isolate* isolate, v8::Local<v8::Context> context, const NPVariant* variant, NPObject* owner);

NPObject* npCreateV8ScriptObject(
    v8::Isolate* isolate, v8::Local<v8::Context> context, NPP npp, v8::Local<v8::Object> object, blink::WebLocalFrame* rootFrame, int64_t mbwebviewId);
V8NPObject* npObjectToV8NPObject(NPObject* npObject);
void disposeV8NPObject(NPObject* npObject);
NPObject* v8ObjectToNPObject(v8::Local<v8::Object> object);
bool isWrappedNPObject(v8::Local<v8::Object> object);

v8::Local<v8::Object> createV8ObjectForNPObject(v8::Isolate* isolate, v8::Local<v8::Context> context, NPObject* object, NPObject* root);
void forgetV8ObjectForNPObject(NPObject* object);

} // namespace content

#endif // CONTENT_RENDERER_NPAPI_NPRUNTIME_PRIV_H_
