
#include "MiniV8Api.h"
#include <windows.h>

// #pragma optimize("", off)
// #pragma clang optimize off

unsigned int g_v8MemSize = 0;
extern "C" void* g_stack_point;

extern "C" void printDebug(const char* format, ...)
{
    va_list argList;
    va_start(argList, format);

    char* output = (char*)malloc(1301);
    vsprintf(output, format, argList);
    OutputDebugStringA(output);
    free(output);

    va_end(argList);
}

void printEmptyFuncInfo(const char* fun, bool isBreak, bool isPrint)
{
    if (isPrint) {
        std::string output = fun;
        output += "\n";
        OutputDebugStringA(output.c_str());
    }
    if (isBreak)
        DebugBreak();
}

static JSValue jsTestNode(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor)
{
    JSValueConst v = argv[0];
    miniv8::V8Object* obj = (miniv8::V8Object*)JS_GetUserdata(v);
    int id = JS_GetObjId(v);

    const char* str = JS_ToCString(ctx, argv[1]);

    char* output = (char*)malloc(0x100);
    sprintf_s(output, 0x99, "jsTestNode: %lld, %p, id:%x, %s\n", v, obj, id, str);
    OutputDebugStringA(output);
    free(output);

    JS_FreeCString(ctx, argv[1], str);

    return JS_UNDEFINED;
}
static JSValue jsPrintStack(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor)
{
    JS_PrintStack(ctx);
    return JS_UNDEFINED;
}

static JSValue jsPrint(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor)
{
    int i;
    const char* str;

    for (i = 0; i < argc; i++) {
        if (i != 0)
            printDebug(" ");
        str = JS_ToCString(ctx, argv[i]);
        if (!str)
            return JS_EXCEPTION;

        if (strstr(str, "MessageFileLoader"))
            OutputDebugStringA("");

        OutputDebugStringA(str);
        JS_FreeCString(ctx, argv[i], str);
    }
    OutputDebugStringA("\n");

    return JS_UNDEFINED;
}

void miniv8PrintWhenError(JSContext* ctx)
{
    JSValue exceptionVal = JS_GetException(ctx);
    BOOL isError = JS_IsError(ctx, exceptionVal);

    jsPrint(ctx, JS_NULL, 1, &exceptionVal, nullptr, FALSE);

    if (isError) {
        JSValue val = JS_GetPropertyStr(ctx, exceptionVal, "stack");
        if (!JS_IsUndefined(val)) {
            const char* stack = JS_ToCString(ctx, val);
            OutputDebugStringA(stack);
            OutputDebugStringA("\n");
            JS_FreeCString(ctx, val, stack);
        }
        JS_FreeValue(ctx, val);
    }
    JS_FreeValue(ctx, exceptionVal);
}

void miniv8ReleaseAssert(bool b, const char* info)
{
    if (b)
        return;

    OutputDebugStringA(info);
    DebugBreak();
}

namespace v8 {

bool g_miniv8Enable = true;

// namespace platform {
// v8::Platform* CreateDefaultPlatform(int thread_pool_size);
// bool PumpMessageLoop(v8::Platform*, v8::Isolate*);
// }
}

namespace miniv8 {

V8Context::V8Context(V8Isolate* isolate, JSContext* ctx)
{
    m_head.m_type = kOTContext;
    m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Context;
    m_head.m_refOrDerefCopy = m_head.m_refOrDeref;
    m_head.m_tracer = onV8HeadTraceOfV8Context;
    m_head.m_objectGroupId = (intptr_t)this; // context的组id设置成独一无二的一档
    m_isolate = isolate;
    m_ctx = ctx;
    m_isDetachGlobal = false;
    m_isCodeGenerationFromStringsAllowed = true;
    m_maxEmbedderDataIndex = 0;
    m_microtaskQueue = nullptr;
    m_extrasBindingObject = nullptr;
    JS_SetContextOpaque(ctx, this);

    V8Isolate::GetCurrent()->regContext(this);

    static int s_count = 0;
    if (1 == s_count)
        JS_SetTestCtx(ctx);
    printDebug("V8Context::V8Context 1: %p ctx:%p, %d\n", this, ctx, s_count);
    s_count++;
}

V8Context::V8Context(const V8Context& other)
{
    m_head.m_type = other.m_head.m_type;
    m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Context;
    m_head.m_refOrDerefCopy = m_head.m_refOrDeref;
    m_head.m_tracer = onV8HeadTraceOfV8Context;
    m_extrasBindingObject = other.m_extrasBindingObject;
    if (m_extrasBindingObject)
        JS_DupValue(m_ctx, m_extrasBindingObject->m_head.m_qjsValue);

    m_isolate = other.m_isolate;
    m_ctx = other.m_ctx;
    m_isCodeGenerationFromStringsAllowed = other.m_isCodeGenerationFromStringsAllowed;

    printDebug("V8Context::V8Context 2: %p, %p\n", this, m_ctx);
}

V8Context::~V8Context()
{
    printDebug("V8Context::~~V8Context: %p JSContext* m_ctx:%p\n", this, m_ctx);

    if (m_microtaskQueue)
        delete m_microtaskQueue;

    if (m_ctx) {
        JSValue global = JS_GetGlobalObject(m_ctx);
        JS_SetPrototype(m_ctx, global, JS_NULL);
        JS_FreeValue(m_ctx, global);

        if (m_extrasBindingObject)
            JS_FreeValue(m_ctx, m_extrasBindingObject->m_head.m_qjsValue);

        JS_DetachGlobalObject(m_ctx);

        JS_FreeContext(m_ctx);
    }
}

void V8Context::onV8HeadTraceOfV8Context(void* tracer, V8Head* head)
{
    V8Head::onTrace(tracer, head);

    V8Context* self = (V8Context*)head;
    if (self->m_extrasBindingObject)
        V8Head::onTraceHelper(tracer, &self->m_extrasBindingObject->m_head);
}

} // miniv8

static JSValue js_isTraceCategoryEnabled(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor)
{
    return JS_FALSE;
}

static JSValue js_trace(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor)
{
    return JS_FALSE;
}

v8::Local<v8::Object> v8::Context::GetExtrasBindingObject(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
    JSContext* ctx = self->m_ctx;

    if (self->m_extrasBindingObject)
        return v8::Utils::convert<miniv8::V8Object, v8::Object>(self->m_extrasBindingObject);

    v8::Local<v8::Object> ret = v8::Object::New(v8::Isolate::GetCurrent());

    self->m_extrasBindingObject = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(*ret);
    JS_DupValue(ctx, self->m_extrasBindingObject->m_head.m_qjsValue);

    JSValue extrasBindingObject = self->m_extrasBindingObject->v(self->m_extrasBindingObject);

    JS_SetPropertyStr(ctx, extrasBindingObject, "isTraceCategoryEnabled", JS_NewCFunction(ctx, js_isTraceCategoryEnabled, "isTraceCategoryEnabled", 0));
    JS_SetPropertyStr(ctx, extrasBindingObject, "trace", JS_NewCFunction(ctx, js_trace, "trace", 0));

    return ret;
}

//////////////////////////////////////////////////////////////////////////

// v8::Platform* v8::platform::CreateDefaultPlatform(int)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
//     return nullptr;
// }

v8::Platform* v8::platform::CreateDefaultPlatform(int thread_pool_size, IdleTaskSupport idle_task_support)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return nullptr;
}

bool v8::platform::PumpMessageLoop(v8::Platform*, v8::Isolate*, v8::platform::MessageLoopBehavior behavior)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return true;
}

__int64 v8::Integer::Value(void) const
{
    //printEmptyFuncInfo(__FUNCTION__, false, false);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Data* self = v8::Utils::openHandle<v8::Integer, miniv8::V8Data>(this);
    if (!JS_IsInteger(self->v(self)))
        return 0;

    __int64 result = 0;
    if (0 == JS_ToInt64(ctx, &result, self->v(self)))
        return result;
    return 0;
}

__int64 v8::Value::IntegerValue(void) const
{
    //printEmptyFuncInfo(__FUNCTION__, false, false);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Data* self = v8::Utils::openHandle<v8::Value, miniv8::V8Data>(this);
    if (!JS_IsInteger(self->v(self)))
        return 0;

    __int64 result = 0;
    if (0 == JS_ToInt64(ctx, &result, self->v(self)))
        return result;
    return 0;
}

bool v8::Value::IsNullOrUndefined() const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Data* self = v8::Utils::openHandle<v8::Value, miniv8::V8Data>(this);
    JSValue v = self->v(self);
    return (JS_IsUndefined(v) || JS_IsNull(v));
}

bool v8::ArrayBuffer::IsExternal(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::ArrayBuffer::IsNeuterable(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::Boolean::Value(void) const
{
    //printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Data* self = v8::Utils::openHandle<v8::Boolean, miniv8::V8Data>(this);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    return (0 != JS_ToBool(ctx, self->v(self)));
}

bool v8::BooleanObject::ValueOf(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::Context::IsCodeGenerationFromStringsAllowed(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);

    return self->isCodeGenerationFromStringsAllowed();
}

bool v8::Isolate::AddMessageListener(void(__cdecl*)(v8::Local<v8::Message>, v8::Local<v8::Value>), v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return true;
}

bool v8::Isolate::GetHeapSpaceStatistics(v8::HeapSpaceStatistics*, size_t)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::Isolate::IdleNotificationDeadline(double)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return true;
}

bool v8::Isolate::InContext(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* self = (miniv8::V8Isolate*)this;
    return self->isInContext();
}

bool v8::Isolate::IsDead(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

void v8::V8::DisposeGlobal(v8::internal::Object** obj)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    isolate->disposeGlobal(obj);
}

void v8::V8::MakeWeak(v8::internal::Object** obj, void* param, v8::WeakCallbackInfo<void>::Callback callback, v8::WeakCallbackType type)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();

    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::toHandle<miniv8::V8Data>(*(intptr_t*)obj);
    //head->m_isWeak = 1;
    head->m_weakCallback = (void*)callback;
    head->m_weakCallbackParam = param;

    if (head->m_type == miniv8::kOTObject) {
        miniv8::V8Object* obj = (miniv8::V8Object*)head;
        //miniv8ReleaseAssert(!(obj->m_alignedPointerInInternalFields[1]) || param == obj->m_alignedPointerInInternalFields[1], "");
        if ((obj->m_alignedPointerInInternalFields[1]) && param != obj->m_alignedPointerInInternalFields[1])
            OutputDebugStringA("v8::V8::MakeWeak fail !!!!!\n");
    }
}

void v8::V8::MakeWeak(v8::internal::Object*** obj)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    MakeWeak(*obj, nullptr, nullptr, v8::WeakCallbackType::kParameter);
}

// TODO：全局引用，把一些local的也放到全局句柄里
v8::internal::Object** v8::V8::GlobalizeReference(v8::internal::Isolate* isolate, v8::internal::Object** obj)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    miniv8::V8Data* vdata = Utils::toHandle<miniv8::V8Data>(*(intptr_t*)obj);
    miniv8::V8ObjectType type = vdata->m_head.m_type;

    void** index = nullptr;
    miniv8::V8Head* head = (miniv8::V8Head*)vdata;
    if (!head->m_isolatGlobalScopeIndex) {
        index = iso->findGlobalizeHandleEmptyIndex();
        iso->refGlobalizeHandleIndex((intptr_t)index);

        head->m_isolatGlobalScopeIndex = index;
        *index = v8::Utils::maskPtr(head);
    } else {
        index = (void**)head->m_isolatGlobalScopeIndex;
        iso->refGlobalizeHandleIndex((intptr_t)index);
        return (v8::internal::Object**)index;
    }

    miniv8::V8Context* v8ctx = iso->getCurrentCtx();
    JSContext* ctx = v8ctx ? v8ctx->ctx() : nullptr;

    switch (type) {
    case miniv8::kOTPrivate:
    case miniv8::kOTSymbol:
        break;
    case miniv8::kOTSignature:
    case miniv8::kOTScript:
    case miniv8::kOTExternal:
        break;

    case miniv8::kOTPromise:
    case miniv8::kOTResolver:
    case miniv8::kOTValue:
    case miniv8::kOTString:
    case miniv8::kOTContext:
    case miniv8::kOTData:
    case miniv8::kOTObject:
    case miniv8::kOTFunction:
    case miniv8::kOTObjectTemplate:
    case miniv8::kOTFunctionTemplate:
    case miniv8::kOTArrayBuffer:
    case miniv8::kOTArray:
    case miniv8::kOTUint8CArray:
    case miniv8::kOTInt8Array:
    case miniv8::kOTUint8Array:
    case miniv8::kOTInt16Array:
    case miniv8::kOTUint16Array:
    case miniv8::kOTInt32Array:
    case miniv8::kOTUint32Array:
#ifdef CONFIG_BIGNUM
    case miniv8::kOTInt64Array:
    case miniv8::kOTUint64Array:
#endif
    case miniv8::kOTFloat32Array:
    case miniv8::kOTFloat64Array:
        break;
    default:
        DebugBreak();
        break;
    }
    //printDebug("GlobalizeReference: %p %p\n", index, vdata);

    return (v8::internal::Object**)index;
}

v8::internal::Object** v8::HandleScope::CreateHandle(v8::internal::HeapObject*, v8::internal::Object*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return nullptr;
}

// TODO：局部引用，把一些local的也放到isoloate局部引用表里
v8::internal::Object** v8::HandleScope::CreateHandle(v8::internal::Isolate* isolate, v8::internal::Object* obj)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    miniv8::V8ObjectType type = (miniv8::V8ObjectType)(*(intptr_t*)obj);
    miniv8::V8Data* vdata = Utils::toHandle<miniv8::V8Data>((intptr_t)obj);

    void* ret = nullptr;
    switch (vdata->m_head.m_type) {
    case miniv8::kOTContext:
    case miniv8::kOTSignature:
    case miniv8::kOTData:
    case miniv8::kOTString:
    case miniv8::kOTObjectTemplate:
    case miniv8::kOTFunctionTemplate:
    case miniv8::kOTFunction:
    case miniv8::kOTPromise:
    case miniv8::kOTResolver:
    case miniv8::kOTObject:
    case miniv8::kOTValue:
    case miniv8::kOTScript:
    case miniv8::kOTExternal:
    case miniv8::kOTArrayBuffer:
    case miniv8::kOTArrayBufferView:
    case miniv8::kOTUint8CArray:
    case miniv8::kOTInt8Array:
    case miniv8::kOTUint8Array:
    case miniv8::kOTInt16Array:
    case miniv8::kOTUint16Array:
    case miniv8::kOTInt32Array:
    case miniv8::kOTUint32Array:
#ifdef CONFIG_BIGNUM
    case miniv8::kOTInt64Array:
    case miniv8::kOTUint64Array:
#endif
    case miniv8::kOTFloat32Array:
    case miniv8::kOTFloat64Array:
    case miniv8::kOTArray:
        ret = vdata;
        break;
    default:
        DebugBreak();
        break;
    }

    void** index = nullptr;
    miniv8::V8Head* head = (miniv8::V8Head*)ret;

    if (head->m_isolatGlobalScopeIndex) { // 如果有全局句柄表引用，则用全局的
        index = (void**)head->m_isolatGlobalScopeIndex;
        //iso->refGlobalizeHandleIndex((intptr_t)index);
    } else if (head->m_isolatHandleScopeIndex) {
        index = (void**)head->m_isolatHandleScopeIndex;
    } else {
        index = iso->findHandleScopeEmptyIndex();
        //miniv8ReleaseAssert(!head->m_isolatHandleScopeIndexHadClear, "");
        if (!head->m_refOrDeref) { // 这种情况是刚才被handle scrope回收过句柄
            head->m_refOrDeref = head->m_refOrDerefCopy;
            head->m_refOrDeref(head, true);
        }
        head->m_isolatHandleScopeIndex = index;
        *index = v8::Utils::maskPtr(ret);
    }

    return (v8::internal::Object**)index;
}

bool v8::Isolate::IsExecutionTerminating(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::Isolate::WillAutorunMicrotasks(void) const
{
    //printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::Message::IsOpaque(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::Message::IsSharedCrossOrigin(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

v8::Maybe<bool> v8::Object::SetAccessor(v8::Local<v8::Context> v8context, v8::Local<v8::Name> name, v8::AccessorNameGetterCallback getter,
    v8::AccessorNameSetterCallback setter, v8::MaybeLocal<v8::Value> data, v8::AccessControl settings, v8::PropertyAttribute attribute,
    SideEffectType getter_side_effect_type, SideEffectType setter_side_effect_type)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* context = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*v8context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8String* namePtr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(name.As<v8::String>()));
    JSContext* ctx = context->ctx();

    miniv8ReleaseAssert(namePtr->m_head.m_type == miniv8::V8ObjectType::kOTString, "v8::Object::SetAccessor fail\n");

    size_t nameLen = 0;
    JSValue nameVal = namePtr->v(namePtr);
    const char* nameStr = JS_ToCStringLen(context->ctx(), &nameLen, namePtr->v(namePtr));
    uint32_t hashVal = miniv8::hash(nameStr, nameLen);

    std::map<intptr_t, miniv8::V8Object::AccessorData*>::iterator it = self->m_accessorMap.find(hashVal);
    if (it != self->m_accessorMap.end()) {
        delete it->second;
        self->m_accessorMap.erase(it);
    }

    if (!self->m_props)
        self->m_props = new std::vector<JSCFunctionListEntry>();

    uint8_t propFlags = JS_PROP_CONFIGURABLE;
    if (attribute & ALL_CAN_WRITE)
        propFlags |= JS_PROP_WRITABLE;

    JSCFunctionListEntry prop = { 0 };
    prop.name = strdup(nameStr); // TODO: free
    prop.prop_flags = propFlags;
    prop.def_type = JS_DEF_CGETSET;
    prop.magic = 0;
    prop.u.getset.get.getter = &v8::MacroAssembler::wrapGetter;
    prop.u.getset.set.setter = &v8::MacroAssembler::wrapSetter;
    prop.u.getset.userdata = (void*)(hashVal); // TODO:userdata

    //printDebug("v8::Object::SetAccessor 1: %p, %x\n", self, prop.u.getset.userdata);

    self->m_props->push_back(prop);

    miniv8::V8Object::AccessorData* accessorData = new miniv8::V8Object::AccessorData(); // TODO delete
    accessorData->nameGetter = getter;
    accessorData->nameSetter = setter;
    accessorData->data = data.IsEmpty() ? nullptr : v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*(data.ToLocalChecked()));
    miniv8::stdMapInsert(&self->m_accessorMap, hashVal, accessorData);

    JS_SetPropertyFunctionList(ctx, self->v(self), self->m_props->data(), self->m_props->size());

    if (accessorData->data) {
        JSValue accessorDataV = accessorData->data->v(accessorData->data);
        JS_DupValue(ctx, accessorDataV);
        JS_SetPropertyStr(ctx, self->v(self), "SetAccessorData", accessorDataV); // TODO: free
    }
    JS_FreeCString(ctx, nameVal, nameStr);
    return v8::Just<bool>(true);
}

bool v8::Object::SetAccessor(v8::Local<v8::Name> name, void(__cdecl*)(v8::Local<v8::Name>, class v8::PropertyCallbackInfo<v8::Value> const&),
    void(__cdecl*)(v8::Local<v8::Name>, v8::Local<v8::Value>, v8::PropertyCallbackInfo<void> const&), v8::Local<v8::Value>, v8::AccessControl,
    v8::PropertyAttribute)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8String* namePtr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(name.As<v8::String>()));
    if (namePtr->getStr() == "stack")
        return (true);
    return (false);
}

bool v8::Object::SetAccessor(v8::Local<v8::String> name, v8::AccessorGetterCallback getter, v8::AccessorSetterCallback setter, v8::Local<v8::Value> data,
    v8::AccessControl settings, v8::PropertyAttribute attribute)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8String* namePtr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*name);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();

    size_t nameLen = 0;
    JSValue nameVal = namePtr->v(namePtr);
    const char* nameStr = JS_ToCStringLen(ctx, &nameLen, nameVal);
    uint32_t hashVal = miniv8::hash(nameStr, nameLen);

    if (self->m_accessorMap.find(hashVal) != self->m_accessorMap.end())
        DebugBreak();

    if (!self->m_props)
        self->m_props = new std::vector<JSCFunctionListEntry>();

    uint8_t propFlags = JS_PROP_CONFIGURABLE;
    if (attribute & ALL_CAN_WRITE)
        propFlags |= JS_PROP_WRITABLE;

    JSCFunctionListEntry prop = { 0 };
    prop.name = strdup(nameStr); //TODO: free
    prop.prop_flags = propFlags;
    prop.def_type = JS_DEF_CGETSET;
    prop.magic = 0;
    prop.u.getset.get.getter = &v8::MacroAssembler::wrapGetter;
    prop.u.getset.set.setter = &v8::MacroAssembler::wrapSetter;
    prop.u.getset.userdata = (void*)(hashVal); // TODO:userdata

    //printDebug("v8::Object::SetAccessor 2: %x\n", prop.u.getset.userdata);

    self->m_props->push_back(prop);

    miniv8::V8Object::AccessorData* accessorData = new miniv8::V8Object::AccessorData(); // TODO delete
    accessorData->getter = getter;
    accessorData->setter = setter;
    accessorData->data = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*data);
    miniv8::stdMapInsert(&self->m_accessorMap, hashVal, accessorData);

    JS_SetPropertyFunctionList(ctx, self->v(self), self->m_props->data(), self->m_props->size());
    JS_FreeCString(ctx, nameVal, nameStr);

    return true;
}

v8::Maybe<bool> v8::Object::CreateDataProperty(v8::Local<v8::Context> context, unsigned int index, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Context* v8context = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* value = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);

    JSValueConst v = value->v(value);
    JS_DupValue(v8context->ctx(), v);
    int ret = JS_SetPropertyUint32(v8context->ctx(), self->v(self), index, v);
    if (TRUE == ret)
        return v8::Just<bool>(true);

    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::CreateDataProperty(v8::Local<v8::Context> context, v8::Local<v8::Name> key, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    if (key.IsEmpty() || val.IsEmpty()) // TODO:V8Document::preparePrototypeObject导致这里可能是空的
        return v8::Just<bool>(false);

    miniv8::V8Context* v8Ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* v8Key = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    miniv8::V8Value* valueQjs = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);
    JSContext* ctx = v8Ctx->ctx();

    JSAtom keyAtom = JS_ValueToAtom(ctx, v8Key->v(v8Key));

    JSValueConst v = valueQjs->v(valueQjs);
    JS_DupValue(ctx, v);
    int ret = JS_SetProperty(ctx, self->v(self), keyAtom, v);
    JS_FreeAtom(ctx, keyAtom);

    if (TRUE == ret)
        return v8::Just<bool>(true);

    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::DefineOwnProperty(
    v8::Local<v8::Context> context, v8::Local<v8::Name> key, v8::Local<v8::Value> value, v8::PropertyAttribute attributes)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* v8Key = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    miniv8::V8Value* val = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*value);

    size_t keyStrLen = 0;
    const char* keyStr = JS_ToCStringLen(ctx->ctx(), &keyStrLen, v8Key->v(v8Key));

    int flag = 0;
    if (0 == (attributes & v8::ReadOnly))
        flag |= JS_PROP_WRITABLE;
    if (0 == (attributes & v8::DontEnum))
        flag |= JS_PROP_ENUMERABLE;
    if (0 == (attributes & v8::DontDelete))
        flag |= JS_PROP_CONFIGURABLE;

    self->m_head.m_unGcType |= miniv8::V8Head::kIsDefineOwnProperty;
    val->m_head.m_unGcType |= miniv8::V8Head::kIsDefineOwnProperty;

    int ret = JS_DefinePropertyValueStr(ctx->ctx(), self->v(self), keyStr, JS_DupValue(ctx->ctx(), val->v(val)), flag);
    JS_FreeCString(ctx->ctx(), v8Key->v(v8Key), keyStr);

    return v8::Just<bool>(TRUE == ret);
}

v8::Maybe<bool> v8::Object::Delete(v8::Local<v8::Context> context, unsigned int index)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);

    JSAtom prop = JS_NewAtomUInt32(ctx->ctx(), index);
    int ret = JS_DeleteProperty(ctx->ctx(), self->v(self), prop, 0);
    JS_FreeAtom(ctx->ctx(), prop);
    return v8::Just<bool>(TRUE == ret);
}

v8::Maybe<bool> v8::Object::Delete(v8::Local<v8::Context> context, v8::Local<v8::Value> key)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* v8Ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* v8Key = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    JSContext* ctx = v8Ctx->ctx();

    JSAtom prop = JS_ValueToAtom(ctx, v8Key->v(v8Key));
    int ret = JS_DeleteProperty(ctx, self->v(self), prop, 0);
    JS_FreeAtom(ctx, prop);

    return v8::Just<bool>(TRUE == ret);
}

v8::Maybe<bool> v8::Object::Has(v8::Local<v8::Context> context, unsigned int index)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::Has(v8::Local<v8::Context> context, v8::Local<v8::Value> key)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Context* v8Ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* v8Key = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    JSContext* ctx = v8Ctx->ctx();

    JSAtom prop = JS_ValueToAtom(ctx, v8Key->v(v8Key));
    int ret = JS_HasProperty(ctx, self->v(self), prop);
    JS_FreeAtom(ctx, prop);

    return v8::Just<bool>(TRUE == ret);
}

v8::Maybe<bool> v8::Object::HasOwnProperty(v8::Local<v8::Context> context, v8::Local<v8::Name> key)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    // TODO：V8Document::preparePrototypeObject -》 v8::Symbol::GetUnscopables，这个key可能是空的
    if (key.IsEmpty())
        return v8::Just<bool>(false);

    miniv8::V8Context* v8Ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* v8Key = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    JSContext* ctx = v8Ctx->ctx();

    JSAtom prop = JS_ValueToAtom(ctx, v8Key->v(v8Key));
    int ret = JS_HasProperty(ctx, self->v(self), prop);
    JS_FreeAtom(ctx, prop);

    return v8::Just<bool>(TRUE == ret);
}

v8::Maybe<bool> v8::Object::HasRealIndexedProperty(v8::Local<v8::Context> context, unsigned int index)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::HasRealNamedCallbackProperty(v8::Local<v8::Context>, v8::Local<v8::Name>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::HasRealNamedProperty(v8::Local<v8::Context>, v8::Local<v8::Name>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Just<bool>(false);
}

v8::MaybeLocal<v8::Value> v8::Object::CallAsFunction(v8::Local<v8::Context>, v8::Local<v8::Value>, int, v8::Local<v8::Value>* const)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::MaybeLocal<v8::Value>();
}

v8::MaybeLocal<v8::Value> v8::Object::Get(v8::Local<v8::Context> context, unsigned int index)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);

    JSValue v = JS_GetPropertyUint32(ctx->ctx(), self->v(self), index);

    miniv8::V8Value* val = miniv8::V8Value::create(ctx, v);
    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(val);
    JS_FreeValue(ctx->ctx(), v);

    return ret;
}

v8::Local<v8::Value> v8::Object::Get(unsigned int index)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    JSContext* ctx = miniv8::V8Context::getCurrentJsCtx();
    miniv8::V8Context* context = miniv8::V8Context::getCurrentCtx();

    JSValue selfV = self->v(self);
    JSValue val = JS_GetPropertyUint32(ctx, selfV, index);
    miniv8::V8Value* v = miniv8::V8Value::create(context, val); // TODO: 放到句柄域
    JS_FreeValue(ctx, val);

    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(v);
    return ret;
}

v8::Local<v8::Value> v8::Object::Get(v8::Local<v8::Value> key)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::MaybeLocal<v8::Value> ret = Get(isolate->GetCurrentContext(), key);
    if (ret.IsEmpty())
        return v8::Local<v8::Value>();
    return ret.ToLocalChecked();
}

v8::MaybeLocal<v8::Value> v8::Object::Get(v8::Local<v8::Context> context, v8::Local<v8::Value> keyVal)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8String* key = v8::Utils::openHandle<v8::Value, miniv8::V8String>(*keyVal);
    if (key->m_head.m_type != miniv8::kOTString && key->m_head.m_type != miniv8::kOTPrivate && key->m_head.m_type != miniv8::kOTSymbol)
        return v8::MaybeLocal<v8::Value>();

    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();

    JSContext* jsCtx = ctx->ctx();

    JSValue selfV = self->v(self);
    JSValue val;

    BOOL isFunction = JS_IsFunction(jsCtx, selfV);
    if (!isFunction && key->getStr() == "prototype") {
        val = JS_GetPrototype(jsCtx, selfV);
    } else {
        JSAtom prop = JS_ValueToAtom(jsCtx, key->v(key));
        val = JS_GetProperty(jsCtx, selfV, prop);
        JS_FreeAtom(jsCtx, prop);
    }

    miniv8::V8Value* v = miniv8::V8Value::create(ctx, val);
    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(v);
    JS_FreeValue(jsCtx, val);

    return ret;
}

v8::MaybeLocal<v8::Value> v8::Object::GetOwnPropertyDescriptor(v8::Local<v8::Context>, v8::Local<v8::Name>)
{
    printEmptyFuncInfo(__FUNCTION__, true, false);
    return v8::MaybeLocal<v8::Value>();
}

v8::MaybeLocal<v8::Value> v8::Object::GetRealNamedProperty(v8::Local<v8::Context> context, v8::Local<v8::Name> keyVal)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Name* key = v8::Utils::openHandle<v8::Value, miniv8::V8Name>(*keyVal);
    if (key->m_head.m_type != miniv8::kOTString && key->m_head.m_type != miniv8::kOTPrivate && key->m_head.m_type != miniv8::kOTSymbol)
        return v8::MaybeLocal<v8::Value>();

    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();

    JSContext* jsCtx = ctx->ctx();
    JSValue selfV = self->v(self);

    JSAtom prop = JS_ValueToAtom(jsCtx, key->v(key));
    JSValue val = JS_GetPropertyImpl(jsCtx, selfV, prop, selfV, 0, FALSE);
    JS_FreeAtom(jsCtx, prop);

    miniv8::V8Value* v = miniv8::V8Value::create(ctx, val);
    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(v);
    JS_FreeValue(jsCtx, val);

    return ret;
}

bool v8::Object::Delete(v8::Local<v8::Value> key)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* keyPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();

    JSAtom prop = JS_ValueToAtom(ctx, keyPtr->v(keyPtr));
    if (0 == prop)
        return false;

    bool b = TRUE == JS_DeleteProperty(ctx, self->v(self), prop, 0);
    JS_FreeAtom(ctx, prop);
    return b;
}

bool v8::Object::IsCallable(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::Object::Set(unsigned int index, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* valPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();

    JSValue value = valPtr->v(valPtr);
    JS_DupValue(valPtr->ctx(), value);
    return TRUE == JS_SetPropertyUint32(ctx, self->v(self), index, value);
}

bool v8::Object::Set(v8::Local<v8::Value> key, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* keyPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    miniv8::V8Value* valPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();

    JSAtom prop = JS_ValueToAtom(ctx, keyPtr->v(keyPtr));
    if (0 == prop)
        return false;

    JSValueConst value = valPtr->v(valPtr);
    bool b = TRUE == JS_SetProperty(ctx, self->v(self), prop, valPtr->v(valPtr));
    JS_DupValue(ctx, value);
    JS_FreeAtom(ctx, prop);

    return b;
}

const char* kPrivateKey = "__privatekey__";

v8::Maybe<bool> v8::Object::DeletePrivate(v8::Local<v8::Context> context, v8::Local<v8::Private> keyPrivate)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* key = v8::Utils::openHandle<v8::Private, miniv8::V8Value>(*keyPrivate);
    v8::Local<v8::Value> keyVal = v8::Utils::convert<miniv8::V8Value, v8::Value>(key);

    return Delete(context, keyVal);
}

v8::Maybe<bool> v8::Object::HasPrivate(v8::Local<v8::Context> context, v8::Local<v8::Private> keyPrivate)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* key = v8::Utils::openHandle<v8::Private, miniv8::V8Value>(*keyPrivate);
    v8::Local<v8::Value> keyVal = v8::Utils::convert<miniv8::V8Value, v8::Value>(key);

    return Has(context, keyVal);
}

v8::MaybeLocal<v8::Value> v8::Object::GetPrivate(v8::Local<v8::Context> context, v8::Local<v8::Private> keyPrivate)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* key = v8::Utils::openHandle<v8::Private, miniv8::V8Value>(*keyPrivate);
    v8::Local<v8::Value> keyVal = v8::Utils::convert<miniv8::V8Value, v8::Value>(key);
    return Get(context, keyVal);
}

v8::Local<v8::Private> v8::Private::ForApi(v8::Isolate* isolate, v8::Local<v8::String> name)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8String* nameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*name);
    JSValue val = nameStr->v(nameStr);

    std::string str = nameStr->getStr();
    str += kPrivateKey;
    miniv8::V8Private* ret = new miniv8::V8Private(str);
    return v8::Utils::convert<miniv8::V8Private, v8::Private>(ret);
}

v8::Local<v8::Private> v8::Private::New(v8::Isolate*, v8::Local<v8::String> name)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* nameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*name);
    std::string str = nameStr->getStr();
    str += kPrivateKey;
    miniv8::V8Private* ret = new miniv8::V8Private(str);
    return v8::Utils::convert<miniv8::V8Private, v8::Private>(ret);
}

v8::Maybe<bool> v8::Object::SetPrivate(v8::Local<v8::Context> context, v8::Local<v8::Private> keyPrivate, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* ctx = (miniv8::V8Context*)(*context);
    miniv8::V8Value* key = v8::Utils::openHandle<v8::Private, miniv8::V8Value>(*keyPrivate);
    v8::Local<v8::Value> keyVal = v8::Utils::convert<miniv8::V8Value, v8::Value>(key);
    //JSValue v = keyPri->v(keyPri);
    //v8::Local<v8::Value> key = v8::Utils::convert<miniv8::V8Value, v8::Value>(miniv8::V8Value::create(ctx, v));
    return Set(context, keyVal, val);
}

v8::Maybe<bool> v8::Object::Set(v8::Local<v8::Context> context, unsigned int index, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* valPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);
    miniv8::V8Context* v8context = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);

    JSValueConst value = valPtr->v(valPtr);
    JS_DupValue(v8context->ctx(), value);
    if (TRUE == JS_SetPropertyUint32(v8context->ctx(), self->v(self), index, value))
        return v8::Just<bool>(true);
    return v8::Just<bool>(false);
}

v8::Maybe<bool> v8::Object::ForceSet(v8::Local<v8::Context> context, v8::Local<v8::Value> key, v8::Local<v8::Value> value, v8::PropertyAttribute attribs)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    return self->Set(context, key, value, true);
}

v8::Maybe<bool> v8::Object::Set(v8::Local<v8::Context> context, v8::Local<v8::Value> key, v8::Local<v8::Value> value)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    return self->Set(context, key, value, false);
}

void v8::Object::SetAccessorProperty(v8::Local<v8::Name>, v8::Local<v8::Function>, v8::Local<v8::Function>, v8::PropertyAttribute, v8::AccessControl)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::MaybeLocal<v8::Array> v8::Object::GetPropertyNames(
    v8::Local<v8::Context> context, v8::KeyCollectionMode mode, v8::PropertyFilter, v8::IndexFilter, v8::KeyConversionMode)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8ReleaseAssert(KeyCollectionMode::kOwnOnly == mode, "v8::Object::GetPropertyNames, mode must be kOwnOnly\n");

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Context* v8Context = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSContext* ctx = v8Context->ctx();
    JSValue val = self->v(self);
    JSPropertyEnum* tab = nullptr;
    uint32_t len = 0;

    v8::Local<v8::Array> ret = v8::Array::New(isolate, len);
    if (0 > JS_GetOwnPropertyNames(ctx, &tab, &len, val, JS_GPN_STRING_MASK | JS_GPN_SYMBOL_MASK | JS_GPN_ENUM_ONLY))
        return ret;

    for (size_t i = 0; i < len; ++i) {
        if (!(tab[i].is_enumerable))
            continue;
        const char* prop = JS_AtomToCString(ctx, tab[i].atom);
        v8::Local<v8::String> propStr = v8::String::NewFromOneByte(isolate, (const uint8_t*)prop, v8::NewStringType::kNormal, -1).ToLocalChecked();
        ret->Set(i, propStr);
        JS_FreeAtomCString(ctx, tab[i].atom, prop);
    }
    JS_FreePropEnum(ctx, tab, len);
    return ret;
}

v8::MaybeLocal<v8::Array> v8::Object::GetOwnPropertyNames(v8::Local<v8::Context> context)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return GetPropertyNames(
        context, v8::KeyCollectionMode::kOwnOnly, v8::ALL_PROPERTIES, v8::IndexFilter::kIncludeIndices, v8::KeyConversionMode::kConvertToString);
}

v8::MaybeLocal<v8::Array> v8::Object::GetOwnPropertyNames(v8::Local<v8::Context> context, v8::PropertyFilter)
{
    return GetOwnPropertyNames(context);
}

v8::Local<v8::Array> v8::Object::GetOwnPropertyNames(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Local<v8::Array>();
}

v8::MaybeLocal<v8::Array> v8::Object::GetPropertyNames(v8::Local<v8::Context> context)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* v8Context = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    JSContext* ctx = v8Context->ctx();
    JSValue val = self->v(self);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    JSPropertyEnum* tab = nullptr;
    uint32_t len = 0;
    if (TRUE != JS_GetOwnPropertyNames(ctx, &tab, &len, val, JS_GPN_STRING_MASK | JS_GPN_SYMBOL_MASK | JS_GPN_ENUM_ONLY))
        return v8::MaybeLocal<v8::Array>();

    JSValue prototype = JS_GetPrototype(ctx, val);

    JSPropertyEnum* tab2 = nullptr;
    uint32_t len2 = 0;
    if (TRUE != JS_GetOwnPropertyNames(ctx, &tab2, &len2, prototype, JS_GPN_STRING_MASK | JS_GPN_SYMBOL_MASK | JS_GPN_ENUM_ONLY))
        len2 = 0;

    v8::Local<v8::Array> ret = v8::Array::New(isolate, len + len2);
    size_t i = 0;
    for (; i < len; ++i) {
        if (!(tab[i].is_enumerable))
            continue;
        const char* prop = JS_AtomToCString(ctx, tab[i].atom);
        v8::Local<v8::String> propStr = v8::String::NewFromOneByte(isolate, (const uint8_t*)prop, v8::NewStringType::kNormal, -1).ToLocalChecked();
        ret->Set(i, propStr);
        JS_FreeAtomCString(ctx, tab[i].atom, prop);
    }

    for (; i < len + len2; ++i) {
        if (!(tab[i].is_enumerable))
            continue;
        const char* prop = JS_AtomToCString(ctx, tab2[i].atom);
        v8::Local<v8::String> propStr = v8::String::NewFromOneByte(isolate, (const uint8_t*)prop, v8::NewStringType::kNormal, -1).ToLocalChecked();
        ret->Set(i, propStr);
        JS_FreeAtomCString(ctx, tab2[i].atom, prop);
    }

    JS_FreeValue(ctx, val);
    JS_FreeValue(ctx, prototype);
    JS_FreePropEnum(ctx, tab2, len2);
    JS_FreePropEnum(ctx, tab2, len2);
    return ret;
}

int v8::Object::GetIdentityHash(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    return self->getId();
}

int v8::Object::InternalFieldCount(void)
{
    //printEmptyFuncInfo(__FUNCTION__, false, false);
    //     return self->m_alignedPointerInInternalFields.size();

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);

    JSValue v = self->v(self);

    //printDebug("v8::Object::InternalFieldCount: %p, %d, %d\n", self, self->m_internalFieldCount, JS_IsUndefined(v));
    return self->m_internalFieldCount;
    //return miniv8::V8Object::kMaxaAlignedPointerArraySize;
}

v8::Local<v8::Value> v8::Object::SlowGetInternalField(int index)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8ReleaseAssert(index < miniv8::V8Object::kMaxaAlignedPointerArraySize, "v8::Object::GetInternalField fail\n");
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    if (!self->m_internalFields[index])
        return v8::Undefined((v8::Isolate*)isolate);

    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(self->m_internalFields[index]);
    return ret;
}

void v8::Object::SetInternalField(int index, v8::Local<v8::Value> value)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8ReleaseAssert(index < miniv8::V8Object::kMaxaAlignedPointerArraySize, "v8::Object::SetInternalField fail\n");
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Value* val = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*value);

    val->m_head.m_isInMember |= miniv8::V8Head::kIsSetInternalField;
    val->m_head.m_unGcType |= miniv8::V8Head::kIsSetInternalField;

    self->m_internalFields[index] = val; // TODO: GC的时候，有这个的可以不用回收
}

v8::Local<v8::Value> v8::Object::GetInternalField(int index)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8ReleaseAssert(index < miniv8::V8Object::kMaxaAlignedPointerArraySize, "v8::Object::GetInternalField fail\n");
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    if (!self->m_internalFields[index])
        return v8::Undefined((v8::Isolate*)isolate);

    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(self->m_internalFields[index]);
    return ret;
}

void v8::Object::SetAlignedPointerInInternalField(int index, void* value)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8ReleaseAssert(index < miniv8::V8Object::kMaxaAlignedPointerArraySize, "v8::Object::SetAlignedPointerInInternalField");
    //printDebug("v8::Object::SetAlignedPointerInInternalField: %p, index:%d, value:%p\n", self, index, value);

    self->m_alignedPointerInInternalFields[index] = value;

    //     if (1 == index) {
    //         //miniv8ReleaseAssert(!(self->m_head.m_weakCallbackParam) || self->m_head.m_weakCallbackParam == value, "");
    //         if ((self->m_head.m_weakCallbackParam) && self->m_head.m_weakCallbackParam != value)
    //             OutputDebugStringA("v8::Object::SetAlignedPointerInInternalField fail\n");
    //     }
}

static void copyEmytpIndex(void* arr1[], void* arr2[], int len)
{
    for (int i = 0; i < len; ++i) {
        if (nullptr != arr1[i])
            arr1[i] = arr2[i];
    }
}

void* v8::Object::GetAlignedPointerFromInternalField(int index)
{
    return SlowGetAlignedPointerFromInternalField(index);
}

void* v8::Object::SlowGetAlignedPointerFromInternalField(int index)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8ReleaseAssert(index < miniv8::V8Object::kMaxaAlignedPointerArraySize, "v8::Object::SlowGetAlignedPointerFromInternalField fail\n");

    void* it = self->m_alignedPointerInInternalFields[index];
    if (it)
        return it;

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    //     v8::Local<v8::Context> context = isolate->GetCurrentContext();
    //     miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSContext* ctx = miniv8::V8Context::getEmptyJsCtx();

    JSValueConst prototype = JS_GetPrototype(ctx, self->v(self));
    JS_FreeValue(ctx, prototype);
    miniv8::V8Object* prototypeObj = (miniv8::V8Object*)JS_GetUserdata(prototype);
    if (prototypeObj) {
        it = prototypeObj->m_alignedPointerInInternalFields[index];
        if (it) { // 拷贝一份，防止有些情况没有ctx获取不到prototype
            copyEmytpIndex(
                self->m_alignedPointerInInternalFields, prototypeObj->m_alignedPointerInInternalFields, miniv8::V8Object::kMaxaAlignedPointerArraySize);
            return it;
        }
    }

    // 见WindowProxy::installDOMWindow()，要查找原型的原型
    prototype = JS_GetPrototype(ctx, prototype);
    prototypeObj = (miniv8::V8Object*)JS_GetUserdata(prototype);
    JS_FreeValue(ctx, prototype);
    if (!prototypeObj)
        return nullptr;

    it = prototypeObj->m_alignedPointerInInternalFields[index];
    if (it) {
        copyEmytpIndex(self->m_alignedPointerInInternalFields, prototypeObj->m_alignedPointerInInternalFields, miniv8::V8Object::kMaxaAlignedPointerArraySize);
        return it;
    }

    return nullptr;
}

v8::Maybe<bool> v8::Object::SetPrototype(v8::Local<v8::Context> context, v8::Local<v8::Value> protoValue)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8Context* v8ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Value* protoVal = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*protoValue);
    JSContext* ctx = v8ctx->ctx();

    if (self->SetPrototype(ctx, protoVal))
        return v8::Just<bool>(true);
    return v8::Just<bool>(false);
}

v8::Local<v8::Value> v8::Object::GetPrototype(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    return self->GetPrototype();
}

v8::Local<v8::Object> v8::Object::Clone(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);

    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    miniv8::V8Context* context = isolate->getCurrentCtx();
    JSContext* ctx = context->ctx();

    JSValue oldV = self->v(self);
    v8::Local<v8::Object> ret;
    if (1) {
        miniv8::V8Object* newObj = miniv8::V8Object::createFromClone(context, oldV);
        newObj->m_internalFieldCount = self->m_internalFieldCount;
        newObj->m_templId = self->m_templId;
        memcpy(
            newObj->m_alignedPointerInInternalFields, newObj->m_alignedPointerInInternalFields, sizeof(void*) * miniv8::V8Object::kMaxaAlignedPointerArraySize);

        ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(newObj); // TODO: free
    } else {
        ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(self);
    }

    //     if (0) {
    //         JSAtom prop = JS_NewAtom(ctx, "value");
    //         JSValue test = JS_GetProperty(ctx, newV, prop);
    //         test = JS_GetProperty(ctx, oldV, prop);
    //     }
    return ret;
}

// 见v8::FunctionTemplate::HasInstance
v8::Local<v8::Object> v8::Object::FindInstanceInPrototypeChain(v8::Local<v8::FunctionTemplate> templ)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8ReleaseAssert(!templ.IsEmpty(), "v8::Object::FindInstanceInPrototypeChain fail\n"); // TODO; 这鬼函数有点奇葩

    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    miniv8::V8FunctionTemplate* funcTempl = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(*templ);

    JSValue v = self->v(self);
    JSValue proto = v;
    while (true) {
        miniv8::V8Object* protoV8 = (miniv8::V8Object*)JS_GetUserdata(proto);
        if (protoV8) {
            int id = protoV8->getTemplId();
            if (id == funcTempl->getRegisterId()) {
                if (JS_IsObject(protoV8->v(protoV8)))
                    return v8::Utils::convert<miniv8::V8Object, v8::Object>((miniv8::V8Object*)protoV8);
                else
                    return v8::Local<v8::Object>();
            }
        }

        JSValue next = JS_GetPrototype(NULL, proto);
        if (JS_VALUE_IS_EQ(next, proto) || JS_VALUE_IS_EQ(next, JS_NULL) || JS_VALUE_IS_EQ(JS_UNDEFINED, next))
            return v8::Local<v8::Object>();
        JS_FreeValue(NULL, next);
        proto = next;
    }
    return v8::Local<v8::Object>();
}

v8::Local<v8::Object> v8::Object::New(
    v8::Isolate* isolate, v8::Local<v8::Value> prototype_or_null, v8::Local<v8::Name>* names, v8::Local<v8::Value>* values, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
    if (!prototype_or_null->IsNullOrUndefined() || names || values)
        DebugBreak();
    return New(isolate);
}

v8::Local<v8::Object> v8::Object::New(v8::Isolate* isolate)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Context* context = ((miniv8::V8Isolate*)isolate)->getEmptyCtx();
    JSContext* ctx = context->ctx();
    JSValue val = JS_NewObject(ctx);

    miniv8::V8Object* v = new miniv8::V8Object(context, val); // TODO: 放到句柄域
    v8::Local<v8::Object> ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(v);
    JS_FreeValue(ctx, val);

    return ret;
}

v8::Local<v8::Array> v8::Object::GetPropertyNames(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Local<v8::Array>();
}

v8::Isolate* v8::Object::GetIsolate(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    return (v8::Isolate*)(self->v8Ctx()->isolate());
}

v8::Local<v8::Context> v8::Object::CreationContext(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    if (self->m_ctx)
        return v8::Utils::convert<miniv8::V8Context, v8::Context>(self->m_ctx);
    return v8::Local<v8::Context>();
}

v8::Local<v8::String> v8::Object::GetConstructorName(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
    miniv8::V8Context* context = miniv8::V8Context::getCurrentCtx();
    JSContext* ctx = context->ctx();
    //JS_PrintStack(ctx);
    miniv8::V8Object* self = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(this);
    const char* funName = JS_GetConstructorName(ctx, self->v(self));
    return v8::String::NewFromOneByte(v8::Isolate::GetCurrent(), (const uint8_t*)funName);
}

// v8::Local<v8::Value> v8::Object::GetInternalField(int)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
//     return v8::Local<v8::Value>();
// }

v8::Maybe<v8::PropertyAttribute> v8::Object::GetPropertyAttributes(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Just<v8::PropertyAttribute>(v8::ReadOnly);
}

v8::Maybe<v8::PropertyAttribute> v8::Object::GetRealNamedPropertyAttributes(v8::Local<v8::Context>, v8::Local<v8::Name>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Just<v8::PropertyAttribute>(v8::ReadOnly);
}

v8::MaybeLocal<v8::String> v8::Object::ObjectProtoToString(v8::Local<v8::Context>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::MaybeLocal<v8::String>();
}

bool v8::Promise::HasHandler(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::StackFrame::IsEval(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::String::CanMakeExternal(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

v8::Local<v8::String> v8::String::Concat(v8::Isolate* isolate, v8::Local<v8::String> left, v8::Local<v8::String> right)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* leftStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*left);
    std::string leftString = leftStr->getStr();
    miniv8::V8String* rightStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*right);
    std::string rightString = rightStr->getStr();

    std::vector<char> data(leftString.size() + rightString.size() + 1);

    if (0 != leftString.size())
        memcpy(data.data(), leftString.c_str(), leftString.size());
    if (0 != rightString.size())
        memcpy(data.data() + leftString.size(), rightString.c_str(), rightString.size());
    data[leftString.size() + rightString.size()] = '\0';

    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(data.data(), data.size()));
    return ret;
}

bool v8::String::ContainsOnlyOneByte(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();

    if (1 == JS_ContainsOnlyOneByte(ctx, self->v(self)))
        return true;
    return false;

    //     const std::string& str = self->getStr();
    //     if (-1 != self->m_isContainsOnlyOneByte)
    //         return self->m_isContainsOnlyOneByte == 1;
    //
    //     for (size_t i = 0; i < str.size(); ++i) {
    //         char c = str[i];
    //         if (!isascii(c)) {
    //             self->m_isContainsOnlyOneByte = 0;
    //             return false;
    //         }
    //     }
    //     self->m_isContainsOnlyOneByte = 1;
    //     return true;
}

bool v8::String::IsExternal(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    return !!self->m_twoByteExternalString;
}

bool v8::String::IsExternalOneByte(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    return !!self->m_oneByteExternalString;
}

bool v8::String::IsOneByte(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return true;
}

bool v8::String::MakeExternal(v8::String::ExternalOneByteStringResource* resource)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    self->m_oneByteExternalString = resource;
    return false;
}

bool v8::String::MakeExternal(v8::String::ExternalStringResource* resource)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    self->m_twoByteExternalString = resource;
    return false;
}

v8::String::ExternalStringResource* v8::String::GetExternalStringResource() const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    return self->m_twoByteExternalString;
}

v8::String::ExternalStringResourceBase* v8::String::GetExternalStringResourceBase(v8::String::Encoding* encoding_out) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    int tag = JS_VALUE_GET_TAG(self->m_head.m_qjsValue);
    if (self->m_twoByteExternalString)
        return self->m_twoByteExternalString;
    return self->m_oneByteExternalString;
}

const v8::String::ExternalOneByteStringResource* v8::String::GetExternalOneByteStringResource(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);
    int tag = JS_VALUE_GET_TAG(self->m_head.m_qjsValue);
    return self->m_oneByteExternalString;
}

int v8::String::Length(void) const
{
    //TODO: 这函数要搞个缓存，不然影响效率
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);

    int length = self->getStrCount();
    return length;
}

int v8::String::Utf8Length(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);

    const std::string& str = self->getStr();
    return str.size();
}

int v8::String::Write(v8::Isolate* isolate, uint16_t* buffer, int start, int length, int options) const
{
    return Write(buffer, start, length, options);
}

int v8::String::Write(uint16_t* buffer, int start, int length, int options) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);

    miniv8ReleaseAssert(0 == start && (v8::String::NO_NULL_TERMINATION == options || NO_OPTIONS == options), "v8::String::Write fail\n");

    const std::string& str = self->getStr();
    std::wstring wstr = miniv8::utf8ToUtf16(str);
    size_t len = length;
    if (len > wstr.size())
        len = wstr.size();
    memcpy(buffer, wstr.c_str(), len * sizeof(uint16_t));

    return (int)len;
}

int v8::String::WriteOneByte(v8::Isolate* isolate, uint8_t* buffer, int start /*= 0*/, int length /*= -1*/, int options /*= NO_OPTIONS*/) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return WriteOneByte(buffer, start, length, options);
}

int v8::String::WriteOneByte(uint8_t* buffer, int start, int length, int options) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);

    if (start != 0)
        DebugBreak();

    const std::string& str = self->getStr();
    int len = (int)str.size();
    if (start + length > len)
        length = len - start;

    memcpy(buffer, str.c_str() + start, length); // TODO: start+ length 没考虑溢出的情况
    return length;
}

int v8::String::WriteUtf8(char* buffer, int length, int* nchars_ref, int options) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* self = v8::Utils::openHandle<v8::String, miniv8::V8String>(this);

    if (nchars_ref)
        DebugBreak();

    const std::string& str = self->getStr();
    size_t len = str.size();
    if (length > (int)len) // v8好像规定如果写入结尾的0，len就要+1。如果不写，就不+1
        length = (int)len;

    memcpy(buffer, str.c_str(), length); // TODO: start+ length 没考虑溢出的情况
    return length;
}

v8::Local<v8::String> v8::String::Concat(v8::Local<v8::String> leftStr, v8::Local<v8::String> rightStr)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* left = v8::Utils::openHandle<v8::String, miniv8::V8String>(*leftStr);
    miniv8::V8String* right = v8::Utils::openHandle<v8::String, miniv8::V8String>(*rightStr);
    std::string str = left->getStr();
    str += right->getStr();

    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(str));
    return ret;
}

v8::Local<v8::String> v8::String::NewFromTwoByte(v8::Isolate* isolate, unsigned short const* lpszSrc, v8::String::NewStringType type, int length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    if (-1 == length)
        length = (int)wcslen((const wchar_t*)lpszSrc);

    std::string utf8Str = miniv8::utf16ToChar((const wchar_t*)lpszSrc, length, CP_UTF8);
    return v8::String::NewFromUtf8(isolate, utf8Str.c_str(), type, utf8Str.size());
}

v8::Local<v8::String> v8::String::NewFromUtf8(v8::Isolate* isolate, char const* data, v8::String::NewStringType, int length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    // TODO: 没考虑编码
    if (length == -1)
        length = strlen((const char*)data);
    std::string str((const char*)data, length);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(str)); // TODO free
    return ret;
}

v8::MaybeLocal<v8::String> v8::String::NewFromUtf8(v8::Isolate* isolate, const char* data, v8::NewStringType type, int length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    if (length == -1)
        length = strlen((const char*)data);
    std::string str((const char*)data, length);

    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(str)); // TODO free

    return ret;
}

v8::MaybeLocal<v8::String> v8::String::NewExternalOneByte(v8::Isolate* isolate, v8::String::ExternalOneByteStringResource* resource)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    // TODO:编码还没考虑
    if (!resource)
        return v8::MaybeLocal<v8::String>();

    //std::string str(resource->data(), resource->length());
    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(resource)); // TODO free
    return ret;
}

v8::MaybeLocal<v8::String> v8::String::NewExternalTwoByte(v8::Isolate*, v8::String::ExternalStringResource* resource)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    if (!resource)
        return v8::MaybeLocal<v8::String>();
    //std::string str = miniv8::utf16ToChar((LPCWSTR)res->data(), res->length(), CP_UTF8);
    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(resource)); // TODO free
    return ret;
}

v8::Local<v8::String> v8::String::NewFromOneByte(v8::Isolate* isolate, unsigned char const* data, v8::String::NewStringType type, int length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    // TODO: 没考虑编码
    miniv8ReleaseAssert(type == v8::String::kNormalString, "");

    if (length == -1)
        length = strlen((const char*)data);
    std::string str((const char*)data, length);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(str)); // TODO free
    return ret;
}

v8::MaybeLocal<v8::String> v8::String::NewFromOneByte(v8::Isolate* isolate, unsigned char const* data, v8::NewStringType type, int length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    // TODO: 没考虑编码
    //miniv8ReleaseAssert(type == v8::NewStringType::kNormal, "");

    if (length == -1)
        length = strlen((const char*)data);
    std::string str((const char*)data, length);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(str)); // TODO free
    return ret;
}

v8::MaybeLocal<v8::String> v8::String::NewFromTwoByte(v8::Isolate* isolate, unsigned short const* str, v8::NewStringType type, int length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8ReleaseAssert(type == v8::NewStringType::kNormal, "");

    if (length == -1)
        length = wcslen((const WCHAR*)str);
    std::string utf8 = miniv8::utf16ToChar((const WCHAR*)str, length, CP_UTF8);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    v8::Local<v8::String> ret = v8::Utils::convert<miniv8::V8String, v8::String>(new miniv8::V8String(utf8)); // TODO free
    return ret;
}

v8::String::Utf8Value::Utf8Value(v8::Local<v8::Value> str)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    if (!str->IsString())
        DebugBreak();
    miniv8::V8String* v8string = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(str.As<v8::String>()));
    const std::string& strv8 = v8string->getStr();

    this->str_ = (char*)strv8.c_str();
    this->length_ = (int)strv8.size();
}

v8::String::Utf8Value::~Utf8Value(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

#if V8_MINOR_VERSION < 8
v8::String::Value::Value(v8::Isolate* isolate, v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* value = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);
    if (value->m_head.m_type != miniv8::kOTString) {
        DebugBreak();
        return;
    }

    miniv8::V8String* valueStr = (miniv8::V8String*)value;
    std::wstring str = miniv8::utf8ToUtf16(valueStr->getStr());
    length_ = (int)str.size();
    str_ = (uint16_t*)malloc(sizeof(uint16_t) * (length_ + 1));
    if (str.size() > 0)
        memcpy(str_, str.c_str(), sizeof(uint16_t) * (length_));
    str_[length_] = 0;
}
#endif

v8::String::Value::Value(v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

v8::String::Value::~Value(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    if (str_)
        free(str_);
}

bool v8::TryCatch::CanContinue(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)isolate_;
    return !isolate->hasErr();
}

bool v8::TryCatch::HasCaught(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)isolate_;
    return isolate->hasErr();
}

bool v8::TryCatch::HasTerminated(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

v8::TryCatch::TryCatch(v8::Isolate* isolate)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    isolate_ = (internal::Isolate*)isolate;
}

v8::TryCatch::TryCatch(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::TryCatch::~TryCatch(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::Local<v8::Value> v8::TryCatch::Exception(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::TryCatch::ReThrow(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Local<v8::Value>();
}

v8::Local<v8::Message> v8::TryCatch::Message(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Local<v8::Message>();
}

void v8::TryCatch::Reset(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)isolate_;
    isolate->clearErr(isolate->getCurrentJsCtx());
}

void v8::TryCatch::SetVerbose(bool)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

bool v8::TryCatch::IsVerbose(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return false;
}

// bool v8::V8::AddMessageListener(void(__cdecl*)(v8::Local<v8::Message>, v8::Local<v8::Value>), v8::Local<v8::Value>)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
//     return false;
// }

bool v8::V8::Initialize(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return true;
}

// bool v8::V8::IsDead(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
//     return false;
// }

// bool v8::V8::IsExecutionTerminating(v8::Isolate*)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
//     return false;
// }

bool v8::Value::BooleanValue(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int ret = JS_ToBool(ctx, self->v(self));
    if (TRUE == ret)
        return true;
    return false;
}

bool v8::Value::Equals(v8::Local<v8::Value> other) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Value* otherPtr = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*other);

    return JS_VALUE_IS_EQ(self->v(self), otherPtr->v(otherPtr));
}

bool v8::Value::IsArgumentsObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::Value::IsArray(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int ret = JS_IsArray(ctx, self->v(self));
    return ret == TRUE;
}

bool v8::Value::IsArrayBuffer(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (miniv8::kOTArrayBuffer == self->m_head.m_type)
        return true;
    int ret = JS_IsArrayBuffer(self->v(self));
    return ret == TRUE;
}

bool v8::Value::IsArrayBufferView(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (miniv8::kOTArrayBufferView <= self->m_head.m_type && self->m_head.m_type <= miniv8::kOTFloat64Array)
        return true;
    int ret = JS_IsArrayBufferView(self->v(self));
    return ret == TRUE;
}

bool v8::Value::IsBoolean(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsBool(self->v(self)) == TRUE;
}

bool v8::Value::IsBooleanObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsBool(self->v(self)) == TRUE;
}

bool v8::Value::IsDataView(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return false;
}

bool v8::Value::IsDate(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::Value::IsExternal(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return self->m_head.m_type == miniv8::kOTExternal;
}

bool v8::Value::IsFunction(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return self->m_head.m_type == miniv8::V8ObjectType::kOTFunction || TRUE == JS_IsFunction(ctx, self->v(self));
}

bool v8::Value::IsGeneratorFunction(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::Value::IsGeneratorObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::Value::IsInt16Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::Value::IsInt32() const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    JSValue v = self->v(self);
    return JS_IsInteger(v) == TRUE || JS_IsNumber(v) == TRUE;
}

bool v8::Value::IsMap() const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsMap(self->v(self)) == TRUE;
}

bool v8::Value::IsMapIterator() const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsMapIterator(self->v(self)) == TRUE;
}

bool v8::Value::IsName() const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return false;
}

bool v8::Value::IsNativeError(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsException(self->v(self)) == TRUE;
}

bool v8::Value::IsNumber(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsNumber(self->v(self)) == TRUE;
}

bool v8::Value::IsNumberObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsNumber(self->v(self)) == TRUE;
}

bool v8::Value::IsObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTObject)
        return true;

    return JS_IsObject(self->v(self)) == TRUE;
}

bool v8::Value::IsPromise(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsPromise(self->v(self)) == TRUE;
}

bool v8::Value::IsProxy(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsProxy(self->v(self)) == TRUE;
}

bool v8::Value::IsRegExp(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsRegExp(self->v(self)) == TRUE;
}

bool v8::Value::IsSet(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsSet(self->v(self)) == TRUE;
}

bool v8::Value::IsSetIterator(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsSetIterator(self->v(self)) == TRUE;
}

bool v8::Value::IsSharedArrayBuffer(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsSharedArrayBuffer(self->v(self)) == TRUE;
}

bool v8::Value::IsStringObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsString(self->v(self)) == TRUE;
}

bool v8::Value::IsSymbol(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTSymbol)
        return true;
    JSValue v = self->v(self);
    return JS_IsSymbol(v);
}

bool v8::Value::IsSymbolObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return IsSymbol();
}

bool v8::Value::IsFalse(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (JS_IsBool(self->v(self)) == TRUE) {
        int ret = JS_ToBool(ctx, self->v(self));
        if (FALSE == ret)
            return true;
    }
    return false;
}

bool v8::Value::IsTrue(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (!self)
        return false;
    if (JS_IsBool(self->v(self)) == TRUE) {
        int ret = JS_ToBool(ctx, self->v(self));
        if (TRUE == ret)
            return true;
    }
    return false;
}

bool v8::Value::IsTypedArray(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (miniv8::kOTUint8CArray <= self->m_head.m_type && self->m_head.m_type <= miniv8::kOTFloat64Array)
        return true;
    return JS_IsTypedArray(self->v(self));
}

bool v8::Value::IsUint16Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTUint16Array)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_UINT16_TYPED_ARRAY);
}

bool v8::Value::IsUint32(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsInteger(self->v(self)) == TRUE;
}

bool v8::Value::IsUint32Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTUint32Array)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_UINT32_TYPED_ARRAY);
}

bool v8::Value::IsUint8Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTUint8Array)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_UINT8_TYPED_ARRAY);
}

bool v8::Value::IsUint8ClampedArray(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTUint8CArray)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_UINT8C_TYPED_ARRAY);
}

bool v8::Value::IsFloat32Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTFloat32Array)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_FLOAT32_TYPED_ARRAY);
}

bool v8::Value::IsFloat64Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTFloat64Array)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_FLOAT64_TYPED_ARRAY);
}

bool v8::Value::IsInt32Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTInt32Array)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_INT32_TYPED_ARRAY);
}

bool v8::Value::IsInt8Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTInt8Array)
        return true;
    return JS_IsWhatTypedArray(self->v(self), JS_INT8_TYPED_ARRAY);
}

bool v8::Value::IsWeakMap(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsWeakMap(self->v(self)) == TRUE;
}

bool v8::Value::IsWeakSet(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsWeakSet(self->v(self)) == TRUE;
}

bool v8::Value::StrictEquals(v8::Local<v8::Value> other) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    if (other.IsEmpty())
        return false;

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Value* otherVal = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*other);
    if (self == otherVal)
        return true;

    if (JS_VALUE_IS_EQ(self->v(self), otherVal->v(otherVal)))
        return true;

    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    return JS_IsValueEq(ctx, self->v(self), otherVal->v(otherVal), TRUE);
}

double v8::Date::ValueOf(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

double v8::Number::Value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Number, miniv8::V8Value>(this);
    double res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    int ret = JS_ToFloat64(ctx, &res, self->v(self));
    if (0 == ret)
        return res;
    return 0;
}

double v8::NumberObject::ValueOf(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::NumberObject, miniv8::V8Value>(this);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    double res = 0;
    int ret = JS_ToFloat64(ctx, &res, self->v(self));
    if (0 == ret)
        return res;
    return 0;
}

double v8::Value::NumberValue(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    double res = 0;
    int ret = JS_ToFloat64(ctx, &res, self->v(self));
    if (0 == ret)
        return res;
    return 0;
}

v8::RegExp::Flags v8::RegExp::GetFlags(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::RegExp::kNone;
}

int v8::Function::GetScriptColumnNumber(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::Function::GetScriptLineNumber(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::Function::ScriptId(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::Int32::Value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Int32, miniv8::V8Value>(this);
    int32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    int ret = JS_ToInt32(ctx, &res, self->v(self));
    if (0 == ret)
        return res;
    return 0;
}

int v8::Isolate::ContextDisposedNotification(bool)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::Message::GetEndColumn(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::Message::GetEndPosition(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::Message::GetLineNumber(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::Message::GetStartColumn(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::Message::GetStartPosition(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::StackFrame::GetColumn(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::StackFrame::GetLineNumber(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::StackFrame::GetScriptId(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::StackTrace::GetFrameCount(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::UnboundScript::GetId(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

v8::Local<v8::Value> v8::UnboundScript::GetSourceMappingURL(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
    miniv8::V8UnboundScript* self = v8::Utils::openHandle<v8::UnboundScript, miniv8::V8UnboundScript>(this);
    return v8::String::NewFromUtf8(v8::Isolate::GetCurrent(), self->getSourceName().c_str());
}

#if V8_MINOR_VERSION < 8
v8::Local<v8::Value> v8::V8::GetEternal(v8::Isolate* iso, int index)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8ReleaseAssert(index < miniv8::V8Isolate::kSlotSize, "v8::V8::GetEternal fail\n");
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)iso;
    miniv8::V8Value* val = (miniv8::V8Value*)(isolate->m_eternals[index]);
    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(val);
    return ret;
}

void v8::V8::Eternalize(v8::Isolate* iso, v8::Value* v, int* index)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)iso;
    miniv8::V8Value* val = v8::Utils::toHandle<miniv8::V8Value>(*(uintptr_t*)v);
    val->m_head.m_unGcType |= miniv8::V8Head::kIsEternal; // 有这个标记的就不回收了

    for (int i = 0; i < miniv8::V8Isolate::kSlotSize; ++i) {
        if (isolate->m_eternals[i] == val) {
            *index = i;
            return;
        }

        if (!isolate->m_eternals[i]) {
            isolate->m_eternals[i] = val;
            *index = i;

            v8::Persistent<v8::Value>* eternalizePersistent;
            eternalizePersistent = new v8::Persistent<v8::Value>((v8::Isolate*)isolate, v8::Utils::convert<miniv8::V8Value, v8::Value>(val));
            isolate->m_eternalsPersistents[i] = eternalizePersistent;
            return;
        }
    }
    DebugBreak();
}

#else

v8::Value* v8::V8::Eternalize(v8::Isolate* iso, v8::Value* v)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)iso;
    miniv8::V8Value* val = v8::Utils::toHandle<miniv8::V8Value>(*(uintptr_t*)v);
    val->m_head.m_unGcType |= miniv8::V8Head::kIsEternal; // 有这个标记的就不回收了

    for (int i = 0; i < miniv8::V8Isolate::kSlotSize; ++i) {
        if (isolate->m_eternals[i] == val) {
            void* ptr = &isolate->m_eternals[i];
            return (v8::Value*)ptr;
        }
        if (!isolate->m_eternals[i]) {
            isolate->m_eternals[i] = v8::Utils::maskPtr(val);
            void* ptr = &isolate->m_eternals[i];

            v8::Persistent<v8::Value>* eternalizePersistent;
            eternalizePersistent = new v8::Persistent<v8::Value>((v8::Isolate*)isolate, v8::Utils::convert<miniv8::V8Value, v8::Value>(val));
            isolate->m_eternalsPersistents[i] = eternalizePersistent;

            return (v8::Value*)ptr;
        }
    }
    DebugBreak();
    return nullptr;
}
#endif

void* v8::V8::ClearWeak(v8::internal::Object** obj)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)obj);
    head->m_weakCallback = kInvalidWeakCallback;
    return obj;
}

void v8::Isolate::ReportExternalAllocationLimitReached(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

#if V8_MINOR_VERSION < 8
void v8::Isolate::SetObjectGroupId(v8::internal::Object** obj, v8::UniqueId uid)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //v8::internal::Internals::UpdateNodeFlag(obj, true, v8::internal::Internals::kNodeIsActiveShift); // 暂时简化处理，全部标记为激活态
    intptr_t id = *(intptr_t*)(&uid);
    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)obj);
    head->m_objectGroupId = id;
}

void v8::Isolate::SetReference(v8::internal::Object** parent, v8::internal::Object** child)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    // 暂时简化处理，全部标记为激活态
    //     v8::internal::Internals::UpdateNodeFlag(parent, true, v8::internal::Internals::kNodeIsActiveShift);
    //     v8::internal::Internals::UpdateNodeFlag(child, true, v8::internal::Internals::kNodeIsActiveShift);

    miniv8::V8Head* parentHead = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)parent);
    miniv8::V8Head* childHead = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)child);

    childHead->m_objectGroupId = parentHead->m_objectGroupId;
}

void v8::Isolate::SetReferenceFromGroup(v8::UniqueId id, v8::internal::Object** obj)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    // 暂时简化处理，全部标记为激活态
    //v8::internal::Internals::UpdateNodeFlag(obj, true, v8::internal::Internals::kNodeIsActiveShift);
    SetObjectGroupId(obj, id);
}
#endif

void v8::V8::FromJustIsNothing(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::V8::ToLocalEmpty(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

const v8::ScriptCompiler::CachedData* v8::ScriptCompiler::StreamedSource::GetCachedData(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return nullptr;
}

unsigned int v8::Array::Length(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Array* arr = v8::Utils::openHandle<v8::Array, miniv8::V8Array>(this);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8::Isolate::GetCurrent();
    JSContext* ctx = miniv8::V8Context::getCurrentJsCtx();

    JSValue lengthVal = JS_GetPropertyStr(ctx, arr->v(arr), "length");
    if (!JS_IsInteger(lengthVal))
        return 0;

    int32_t res = 0;
    if (0 == JS_ToInt32(ctx, &res, lengthVal))
        return res;
    return 0;
}

unsigned int v8::CpuProfileNode::GetHitCount(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return 0;
}

unsigned int v8::CpuProfileNode::GetHitLineCount(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return 0;
}

unsigned int v8::CpuProfileNode::GetNodeId(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return 0;
}

unsigned int v8::HeapProfiler::GetHeapStats(v8::OutputStream*, __int64*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return 0;
}

unsigned int v8::HeapProfiler::GetObjectId(v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return 0;
}

size_t v8::Isolate::NumberOfHeapSpaces(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
    return 0;
}

uint32_t v8::Uint32::Value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Uint32, miniv8::V8Value>(this);
    int32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    int ret = JS_ToInt32(ctx, &res, self->v(self));
    if (0 == ret)
        return res;
    return 0;
}

uint32_t v8::Value::Uint32Value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    uint32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    int ret = JS_ToUint32(ctx, &res, self->v(self));
    if (0 == ret)
        return res;
    return 0;
}

v8::CpuProfile* v8::CpuProfiler::StopProfiling(v8::Local<v8::String>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return nullptr;
}

v8::CpuProfileNode const* v8::CpuProfile::GetSample(int) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return nullptr;
}

v8::CpuProfileNode const* v8::CpuProfile::GetTopDownRoot(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return nullptr;
}

v8::CpuProfileNode const* v8::CpuProfileNode::GetChild(int) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return nullptr;
}

v8::CpuProfiler* v8::Isolate::GetCpuProfiler(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return nullptr;
}

v8::EscapableHandleScope::EscapableHandleScope(v8::Isolate* isolate)
    : HandleScope(isolate)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //     miniv8::V8Isolate* v8isolate = (miniv8::V8Isolate*)isolate;
    //     void** ret = v8isolate->findHandleScopeEmptyIndex();
}

v8::internal::Object** v8::EscapableHandleScope::Escape(v8::internal::Object** obj)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    if (!obj)
        return obj;

    miniv8::V8Isolate* v8isolate = (miniv8::V8Isolate*)GetIsolate();
    v8isolate->escapeHandleScope((void**)obj);
    return obj;
}

v8::HandleScope::HandleScope(v8::Isolate* isolate)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    isolate_ = (v8::internal::Isolate*)isolate;
    miniv8::V8Isolate* v8isolate = (miniv8::V8Isolate*)isolate;
    v8isolate->enterHandleScope();
}

v8::HandleScope::~HandleScope(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Isolate* v8isolate = (miniv8::V8Isolate*)isolate_;
    v8isolate->exitHandleScope();
    //v8isolate->gcTempScopeHandles();
}

v8::HeapProfiler* v8::Isolate::GetHeapProfiler(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return nullptr;
}

v8::HeapSpaceStatistics::HeapSpaceStatistics(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::HeapStatistics::HeapStatistics(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::Isolate* v8::Context::GetIsolate(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
    return (v8::Isolate*)self->isolate();
}

v8::Isolate* v8::Isolate::GetCurrent(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return (v8::Isolate*)(miniv8::V8Isolate::GetCurrent());
}

v8::Isolate* v8::Isolate::New(const v8::Isolate::CreateParams& params)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = new miniv8::V8Isolate();
    isolate->init(params);
    miniv8ReleaseAssert((v8::Isolate*)isolate == v8::Isolate::GetCurrent(), "v8::Isolate::New fail\n");
    return (v8::Isolate*)isolate;
}

v8::Isolate* v8::Isolate::Allocate(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = new miniv8::V8Isolate();
    return (v8::Isolate*)isolate;
}

void v8::Isolate::Initialize(v8::Isolate* iso, const v8::Isolate::CreateParams& params)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)(iso);
    isolate->init(params);
    miniv8ReleaseAssert((v8::Isolate*)isolate == v8::Isolate::GetCurrent(), "v8::Isolate::New fail\n");
}

// v8::Isolate::CreateParams::CreateParams(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
// }

v8::Local<v8::AccessorSignature> v8::AccessorSignature::New(v8::Isolate* v8Isolate, v8::Local<v8::FunctionTemplate> functionTemplate)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //return v8::Utils::convert<miniv8::V8AccessorSignature, v8::AccessorSignature>(new V8AccessorSignature());
    return v8::Local<v8::AccessorSignature>();
}

v8::Local<v8::Array> v8::Array::New(v8::Isolate* v8Isolate, v8::Local<v8::Value>* elements, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8Isolate;
    miniv8::V8Context* v8ctx = isolate->getCurrentCtx();
    JSContext* ctx = v8ctx->ctx();

    JSValue arr = JS_NewArray(ctx);
    miniv8::V8Array* ret = new miniv8::V8Array(v8ctx, arr);
    for (size_t i = 0; elements && i < length; ++i) {
        miniv8::V8Value* ele = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*(elements[i]));
        ele->m_head.m_unGcType |= miniv8::V8Head::kIsArrayMemField;
        JS_DupValue(ctx, ele->v(ele));
        JS_SetPropertyUint32(ctx, arr, i, ele->v(ele));
    }
    JS_FreeValue(ctx, arr);
    return v8::Utils::convert<miniv8::V8Array, v8::Array>(ret);
}

v8::Local<v8::Array> v8::Array::New(v8::Isolate* v8Isolate, int length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Array::New(v8Isolate, nullptr, length);
}

v8::Local<v8::PrimitiveArray> v8::PrimitiveArray::New(v8::Isolate* v8Isolate, int length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8Isolate;
    miniv8::V8Context* v8ctx = isolate->getCurrentCtx();
    JSContext* ctx = v8ctx->ctx();

    JSValue arr = JS_NewArray(ctx);
    miniv8::V8PrimitiveArray* ret = new miniv8::V8PrimitiveArray(v8ctx, arr);
    JS_FreeValue(ctx, arr);
    return v8::Utils::convert<miniv8::V8PrimitiveArray, v8::PrimitiveArray>(ret);
}

void v8::PrimitiveArray::Set(v8::Isolate* v8Isolate, int index, v8::Local<v8::Primitive> item)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8Isolate;
    miniv8::V8Context* v8ctx = isolate->getCurrentCtx();

    miniv8::V8PrimitiveArray* self = v8::Utils::openHandle<v8::PrimitiveArray, miniv8::V8PrimitiveArray>(this);
    miniv8::V8Primitive* it = v8::Utils::openHandle<v8::Primitive, miniv8::V8Primitive>(*item);
    JS_SetPropertyUint32(v8ctx->ctx(), self->v(self), (uint32_t)index, it->v(it));
}

v8::Local<v8::Array> v8::Map::AsArray(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::Array>();
}

v8::Local<v8::Array> v8::Set::AsArray(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::Array>();
}

v8::Local<v8::Array> v8::StackTrace::AsArray(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Local<v8::Array>();
}

size_t v8::ArrayBuffer::ByteLength(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8ArrayBuffer* self = v8::Utils::openHandle<v8::ArrayBuffer, miniv8::V8ArrayBuffer>(this);

    size_t size = 0;
    uint8_t* data = self->getContents(&size);
    return size;
}

v8::ArrayBuffer::Contents v8::ArrayBuffer::Externalize(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return GetContents(); // TODO:暂时没搞明白Externalize和GetContents有啥区别
}

v8::ArrayBuffer::Contents v8::ArrayBuffer::GetContents(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8ArrayBuffer* self = v8::Utils::openHandle<v8::ArrayBuffer, miniv8::V8ArrayBuffer>(this);

    size_t size = 0;
    uint8_t* data = self->getContents(&size);

    v8::ArrayBuffer::Contents ret;
    ret.data_ = data;
    ret.byte_length_ = size;
    return ret;
}

void* v8::ArrayBuffer::Data() const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8ArrayBuffer* self = v8::Utils::openHandle<v8::ArrayBuffer, miniv8::V8ArrayBuffer>(this);

    size_t size = 0;
    uint8_t* data = self->getContents(&size);

    return data;
}

void v8::ArrayBuffer::Neuter(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

class BackingStoreImpl {
public:
    BackingStoreImpl()
    {
        m_arrayBufferAllocator = nullptr;
        m_data = nullptr;
        m_len = 0;
        m_deleter = nullptr;
        m_deleterData = nullptr;
    }

    void init(miniv8::V8Isolate* isolate, char* data, size_t byte_length, v8::BackingStore::DeleterCallback deleter, void* deleter_data)
    {
        m_arrayBufferAllocator = isolate->getCreateParams().array_buffer_allocator;
        m_data = data;
        m_len = byte_length;
        m_deleter = deleter;
        m_deleterData = deleter_data;
    }

    ~BackingStoreImpl()
    {
        deleteData();
    }

    void* Data() const
    {
        return m_data;
    }
    size_t ByteLength() const
    {
        return m_len;
    }
    bool IsShared() const
    {
        return false;
    }

    void deleteData()
    {
        if (m_deleter)
            m_deleter(m_data, m_len, m_deleterData);
        m_deleter = nullptr;
    }

    v8::BackingStore::DeleterCallback getDeleter() const
    {
        return m_deleter;
    }
    void* getDeleterData() const
    {
        return m_deleterData;
    }

    static BackingStoreImpl* EmptyBackingStore(bool isShared)
    {
        DebugBreak();
        return new BackingStoreImpl();
    }

    static void internalizedDeleterCallback(void* data, size_t length, void* deleterData)
    {
        BackingStoreImpl* self = (BackingStoreImpl*)deleterData;
        self->m_arrayBufferAllocator->Free(data, length);
    }

private:
    char* m_data;
    size_t m_len;

    v8::BackingStore::DeleterCallback m_deleter;
    void* m_deleterData;
    v8::ArrayBuffer::Allocator* m_arrayBufferAllocator;
};

std::unique_ptr<v8::BackingStore> v8::ArrayBuffer::NewBackingStore(
    void* data, size_t byte_length, v8::BackingStore::DeleterCallback deleter, void* deleter_data)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8ReleaseAssert(deleter, "NewBackingStore: DeleterCallback must not is null\n");
    BackingStoreImpl* result = new BackingStoreImpl();
    result->init((miniv8::V8Isolate*)(v8::Isolate::GetCurrent()), (char*)data, byte_length, deleter, deleter_data);
    return std::unique_ptr<BackingStore>((v8::BackingStore*)result);
}

std::unique_ptr<v8::BackingStore> v8::ArrayBuffer::NewBackingStore(v8::Isolate*, size_t byteLength)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    void* data = malloc(byteLength);
    return NewBackingStore(
        data, byteLength, [](void* data, size_t length, void* deleterData) { free(data); }, nullptr);
}

std::unique_ptr<v8::BackingStore> v8::BackingStore::Reallocate(v8::Isolate* isolate, std::unique_ptr<v8::BackingStore> store, size_t new_length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8ReleaseAssert(new_length != 0, "NewBackingStore: Reallocate' Reallocate must not is 0\n");

    BackingStoreImpl* oldStore = (BackingStoreImpl*)store.release();

    void* data = malloc(new_length);
    size_t oldSize = oldStore->ByteLength();

    memcpy(data, oldStore->Data(), (oldSize > new_length) ? new_length : oldSize);

    return v8::ArrayBuffer::NewBackingStore(data, new_length, oldStore->getDeleter(), oldStore->getDeleterData());
}

struct FreeArrayBufferWrap {
    FreeArrayBufferWrap(std::shared_ptr<v8::BackingStore> store)
    {
        m_store = store;
    }

    static void freeData(JSRuntime* rt, void* opaque, void* ptr)
    {
        FreeArrayBufferWrap* info = (FreeArrayBufferWrap*)opaque;
        miniv8ReleaseAssert(ptr == info->m_store->Data(), "onFreeArrayBufferDataFunc2, ptr must is info->m_store->Data()\n");

        BackingStoreImpl* store = (BackingStoreImpl*)(info->m_store.get());
        store->deleteData();
        delete info;
    }

    std::shared_ptr<v8::BackingStore> m_store;
};

v8::Local<v8::ArrayBuffer> v8::ArrayBuffer::New(v8::Isolate* v8Isolate, void* buf, size_t byteLength, v8::ArrayBufferCreationMode mode)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    if (byteLength == 0)
        return v8::Local<v8::ArrayBuffer>();

    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8Isolate;
    miniv8::V8Context* v8ctx = miniv8::V8Context::getCurrentOrEmptyCtx();
    JSContext* ctx = v8ctx->ctx();

    BackingStoreImpl* store(new BackingStoreImpl());

    if (mode == v8::ArrayBufferCreationMode::kInternalized) { // kInternalized表示要手动用isolate->getCreateParams().array_buffer_allocator删除buf
        store->init(isolate, (char*)buf, byteLength, &BackingStoreImpl::internalizedDeleterCallback, store);
    } else {
        store->init(isolate, (char*)buf, byteLength, nullptr, nullptr);
    }

    std::shared_ptr<v8::BackingStore> backingStore((v8::BackingStore*)(store));
    FreeArrayBufferWrap* info = new FreeArrayBufferWrap(backingStore);
    JSValue arr = JS_NewArrayBuffer(ctx, (uint8_t*)buf, byteLength, &FreeArrayBufferWrap::freeData, info, FALSE);
    miniv8::V8ArrayBuffer* ret = miniv8::V8ArrayBuffer::create(v8ctx, arr);
    ret->setStore(backingStore);

    JS_FreeValue(ctx, arr);
    ret->m_internalFieldCount = 2;

    return v8::Utils::convert<miniv8::V8ArrayBuffer, v8::ArrayBuffer>(ret);
}

v8::Local<v8::ArrayBuffer> v8::ArrayBuffer::New(v8::Isolate* v8Isolate, size_t byteLength)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8Isolate;

    //     uint8_t* buf = (uint8_t*)malloc(len);
    //     JSValue arr = JS_NewArrayBufferCopy(context->ctx(), buf, len);
    //     miniv8::V8ArrayBuffer* ret = miniv8::V8ArrayBuffer::create(context, arr);
    //     JS_FreeValue(context->ctx(), arr);
    //     free(buf);
    //
    //     return v8::Utils::convert<miniv8::V8ArrayBuffer, v8::ArrayBuffer>(ret);

    void* buf = isolate->getCreateParams().array_buffer_allocator->AllocateUninitialized(byteLength);
    return New(v8Isolate, buf, byteLength, v8::ArrayBufferCreationMode::kInternalized);
}

v8::Local<v8::ArrayBuffer> v8::ArrayBuffer::New(v8::Isolate*, std::shared_ptr<v8::BackingStore> store)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Context* context = miniv8::V8Context::getEmptyCtx();

    uint8_t* data = (uint8_t*)store->Data();
    size_t byteLength = store->ByteLength();

    FreeArrayBufferWrap* info = new FreeArrayBufferWrap(store);
    JSValue arr = JS_NewArrayBuffer(context->ctx(), data, byteLength, &FreeArrayBufferWrap::freeData, info, FALSE);
    miniv8::V8ArrayBuffer* ret = miniv8::V8ArrayBuffer::create(context, arr);
    JS_FreeValue(context->ctx(), arr);

    ret->m_internalFieldCount = 2;
    ret->setStore(store);

    return v8::Utils::convert<miniv8::V8ArrayBuffer, v8::ArrayBuffer>(ret);
}

std::shared_ptr<v8::BackingStore> v8::ArrayBuffer::GetBackingStore(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
    miniv8::V8ArrayBuffer* self = v8::Utils::openHandle<v8::ArrayBuffer, miniv8::V8ArrayBuffer>(this);
    std::shared_ptr<v8::BackingStore> backingStore = self->getStore();
    if (!backingStore)
        backingStore.reset((v8::BackingStore*)(BackingStoreImpl::EmptyBackingStore(true)));

    return backingStore;
}

v8::BackingStore::~BackingStore(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    BackingStoreImpl* self = (BackingStoreImpl*)this;
    self->deleteData();
}

void* v8::BackingStore::Data(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    BackingStoreImpl* self = (BackingStoreImpl*)this;
    return self->Data();
}

size_t v8::BackingStore::ByteLength(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    BackingStoreImpl* self = (BackingStoreImpl*)this;
    return self->ByteLength();
}

// v8::Maybe<void> v8::JustVoid(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return v8::Nothing<void>();
// }

size_t v8::ArrayBufferView::ByteLength(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8ArrayBufferView* self = v8::Utils::openHandle<v8::ArrayBufferView, miniv8::V8ArrayBufferView>(this);
    return self->getByteLength();
}

size_t v8::ArrayBufferView::ByteOffset(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8ArrayBufferView* self = v8::Utils::openHandle<v8::ArrayBufferView, miniv8::V8ArrayBufferView>(this);
    return self->getByteOffset();
}

unsigned int v8::CpuProfileNode::GetCallUid(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return 0;
}

size_t v8::ArrayBufferView::CopyContents(void* data, size_t byte_length)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
    miniv8::V8ArrayBufferView* self = v8::Utils::openHandle<v8::ArrayBufferView, miniv8::V8ArrayBufferView>(this);
    return self->copyContents(data, byte_length);
}

bool v8::ArrayBufferView::HasBuffer(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8ArrayBufferView* self = v8::Utils::openHandle<v8::ArrayBufferView, miniv8::V8ArrayBufferView>(this);
    return self->hasBuffer();
}

v8::Local<v8::ArrayBuffer> v8::ArrayBufferView::Buffer(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8ArrayBufferView* self = v8::Utils::openHandle<v8::ArrayBufferView, miniv8::V8ArrayBufferView>(this);
    return self->getBuffer();
}

v8::Local<v8::Context> v8::Isolate::GetCallingContext(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* self = (miniv8::V8Isolate*)this;
    miniv8::V8Context* ctx = self->getCurrentCtx();
    return v8::Utils::convert<miniv8::V8Context, v8::Context>(ctx);
}

v8::Local<v8::Context> v8::Isolate::GetCurrentContext(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* self = (miniv8::V8Isolate*)this;
    miniv8::V8Context* ctx = self->getCurrentCtx();
    return v8::Utils::convert<miniv8::V8Context, v8::Context>(ctx);
}

v8::Local<v8::Context> v8::Isolate::GetEnteredContext(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* self = (miniv8::V8Isolate*)this;
    miniv8::V8Context* ctx = self->getCurrentCtx();
    return v8::Utils::convert<miniv8::V8Context, v8::Context>(ctx);
}

v8::Local<v8::DataView> v8::DataView::New(v8::Local<v8::ArrayBuffer>, size_t, size_t)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::DataView>();
}

v8::Local<v8::External> v8::External::New(v8::Isolate* v8isolate, void* userdata)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8isolate;

    miniv8::V8External* ret = new miniv8::V8External(userdata);
    ret->m_userdata = userdata;
    return v8::Utils::convert<miniv8::V8External, v8::External>(ret);
}

v8::Local<v8::Function> v8::Function::New(v8::Isolate* isolate, v8::FunctionCallback callback, v8::Local<v8::Value> data, int length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    //void* dataPtr = static_cast<void*>(v8::External::Cast(*data));

    miniv8::V8Function* ret = new miniv8::V8Function(ctx, callback, data);
    return v8::Utils::convert<miniv8::V8Function, v8::Function>(ret);
}

v8::MaybeLocal<v8::Function> v8::Function::New(
    v8::Local<v8::Context> context, v8::FunctionCallback callback, v8::Local<v8::Value> data, int length, v8::ConstructorBehavior behavior)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* ctx = (miniv8::V8Context*)(*context);

    //void* dataPtr = static_cast<void*>(v8::External::Cast(*data));
    miniv8::V8Function* ret = new miniv8::V8Function(ctx, callback, data);
    return v8::Utils::convert<miniv8::V8Function, v8::Function>(ret);
}

v8::Local<v8::Value> v8::Function::Call(v8::Local<v8::Value> recv, int argc, v8::Local<v8::Value> argv[])
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Function* self = v8::Utils::openHandle<v8::Function, miniv8::V8Function>(this);
    return Call(v8::Utils::convert<miniv8::V8Context, v8::Context>(self->v8Ctx()), recv, argc, argv).ToLocalChecked();
}

const char* kClosureArg = "__miniv8args__";

v8::MaybeLocal<v8::Value> v8::Function::Call(v8::Local<v8::Context> context, v8::Local<v8::Value> recv, int argc, v8::Local<v8::Value> argv[])
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Function* self = v8::Utils::openHandle<v8::Function, miniv8::V8Function>(this);
    miniv8::V8Context* v8context = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSContext* ctx = v8context->ctx();
    miniv8::V8Value* funcObj = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*recv);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    miniv8::V8Isolate* v8isolate = (miniv8::V8Isolate*)isolate;

    //v8isolate->gcHandleScopeHandles(false);
    miniv8::V8Isolate::AutoCallReentry autoCallReentry(v8isolate);

    std::vector<JSValueConst> argvWrap;
    for (int i = 0; i < argc; ++i) {
        miniv8::V8Value* argVal = (miniv8::V8Value*)(*(argv[i]));
        argVal = v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)argVal);

        if (argVal->m_head.m_type > miniv8::V8ObjectType::kOTMax || argVal->m_head.m_type < miniv8::V8ObjectType::kOTMin)
            DebugBreak();

        JS_BOOL b = JS_IsNumber(argVal->v(argVal));

        argvWrap.push_back(argVal->v(argVal));
    }

    JSValue retV;
    if (JS_IsBytecodeFunction(ctx, self->v(self))) { // 这个是从v8::ScriptCompiler::CompileFunction里来的
        //         JSValue global = JS_GetGlobalObject(ctx);
        //         JSValue args = JS_NewArray(ctx);
        //         for (int i = 0; i < argc;++i) {
        //             JS_DupValue(ctx, argvWrap[i]);
        //             JS_SetPropertyUint32(ctx, args, i, argvWrap[i]);
        //         }
        //         int count = JS_GetRefCount(ctx, args);
        //         JS_DupValue(ctx, args);
        //         JS_SetPropertyStr(ctx, global, kClosureArg, args);
        //         count = JS_GetRefCount(ctx, args);
        //
        //         retV = JS_EvalFunctionWithArgs(ctx, self->v(self), funcObj->v(funcObj), argc, 0 != argc ? &argvWrap[0] : nullptr);
        //
        //         count = JS_GetRefCount(ctx, args);
        //         JS_DeletePropertyStr(ctx, global, kClosureArg, 0);
        //         JS_FreeValue(ctx, args);
        //         JS_FreeValue(ctx, global);
        DebugBreak();
    } else
        retV = JS_Call(ctx, self->v(self), funcObj ? funcObj->v(funcObj) : JS_NULL, argc, 0 != argc ? &argvWrap[0] : nullptr);

    if (JS_IsException(retV)) {
        miniv8PrintWhenError(ctx);
        JS_FreeValue(ctx, retV);
        return v8::Undefined(isolate);
    }
    //     if (funcObj)
    //         JS_FreeValue(ctx, funcObj->v(funcObj));

    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(miniv8::V8Value::create(v8context, retV)); // TODO free
    JS_FreeValue(ctx, retV);
    return ret;
}

v8::Local<v8::Value> v8::Function::GetBoundFunction(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::Function::GetDisplayName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::Function::GetInferredName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::Value>();
}

void v8::Function::SetName(v8::Local<v8::String> name)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Function* self = v8::Utils::openHandle<v8::Function, miniv8::V8Function>(this);
    miniv8::V8String* nameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*name);

    std::string nameString = nameStr->getStr();
    self->m_name = nameString;
}

v8::Local<v8::Value> v8::Function::GetName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Function* self = v8::Utils::openHandle<v8::Function, miniv8::V8Function>(this);
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    std::string name = self->getName();

    miniv8::V8String* ret = new miniv8::V8String(name);
    return v8::Utils::convert<miniv8::V8String, v8::String>(ret); // TODO free!
}

namespace miniv8 {
void* g_testFunc = nullptr;
}

v8::MaybeLocal<v8::Object> v8::Function::NewInstance(v8::Local<Context> context, int argc, v8::Local<Value> argv[]) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    // 暂时没搞和Function::Call的区别
    miniv8::V8Function* self = v8::Utils::openHandle<v8::Function, miniv8::V8Function>(this);
    miniv8::V8Context* v8ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSContext* ctx = v8ctx->ctx();
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8::Isolate::GetCurrent();

    std::vector<JSValueConst> argvWrap;
    for (int i = 0; i < argc; ++i) {
        miniv8::V8Value* argVal = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*(argv[i]));
        argvWrap.push_back(argVal->v(argVal));
    }

    JSValue funVal = self->v(self); // will call JS_NewCFunction，获取Function
    // will call v8::internal::FunctionCallbackArguments::onConstructorCallback
    //printDebug("v8::Function::NewInstance: %p, %I64u\n", ctx->ctx(), funVal);
    JSValue instVal = JS_CallConstructor(ctx, funVal, argc, 0 != argc ? &argvWrap[0] : nullptr);

    miniv8::V8Object* inst = miniv8::V8Object::create(v8ctx, instVal);
    JS_FreeValue(ctx, instVal);

    if (0)
        miniv8::g_testFunc = inst;

    if (0) {
        JS_PrintStack(ctx);
        JS_DupValue(ctx, instVal);
        JS_FreeValue(ctx, instVal);
    }

    JS_DupValue(ctx, funVal);

    // 让funVal和instVal关联，这样可以让instVal销毁的时候自动销毁funVal
    //JSAtom funValSymbol = JS_NewAtomWithSymbol(ctx, "funVal");
    JSValue funValSymbolVal = JS_NewSymbolByStr(ctx, "funVal", -1);
    JSAtom funValSymbol = JS_ValueToAtom(ctx, funValSymbolVal);
    JS_SetProperty(ctx, instVal, funValSymbol, funVal);
    //JS_SetPropertyStr(ctx, instVal, "funVal", funVal);

#if 0 // 放到onConstructorCallback里去了。不然如果是js new出来的就调用不到
    inst->setTemplId(self->getTemplId());
    inst->m_internalFieldCount = self->m_internalFieldCount;

    miniv8::V8Template* templ = isolate->getTemplateById(self->getTemplId());
    if (templ && templ->m_instanceTemplate) {
        templ->getInstanceTemplate()->newTemplateInstance(inst, false);

        if (0 == inst->m_internalFieldCount)
            inst->m_internalFieldCount = templ->getInstanceTemplate()->m_internalFieldCount;
    }
#endif
    return (v8::Utils::convert<miniv8::V8Object, v8::Object>(inst)); // TODO free
}

v8::ScriptOrigin v8::Function::GetScriptOrigin(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    miniv8::V8Function* self = v8::Utils::openHandle<v8::Function, miniv8::V8Function>(this);
    std::string name = self->getName();
    miniv8::V8Context* context = miniv8::V8Context::getCurrentOrEmptyCtx();

    v8::Local<v8::String> nameStr = v8::String::NewFromUtf8(isolate, name.c_str());
    v8::Local<v8::String> sourceMapUrl;
    if (!self->getSrcUrl().empty())
        sourceMapUrl = v8::String::NewFromUtf8(isolate, self->getSrcUrl().c_str());

    return ScriptOrigin(nameStr, v8::Local<v8::Integer>(), /*resource_line_offset*/
        v8::Local<v8::Integer>(), /*resource_column_offset*/
        v8::Local<v8::Boolean>(), /*resource_is_shared_cross_origin*/
        v8::Local<v8::Integer>(), /*script_id*/
        sourceMapUrl, v8::Local<v8::Boolean>(), /*resource_is_opaque*/
        v8::Local<v8::Boolean>() /*is_wasm*/);
}

//////////////////////////////////////////////////////////////////////////
// Template

// from G:\mycode\mb_temp\third_party\WebKit\Source\bindings\core\v8\V8DOMConfiguration.cpp doInstallMethodInternal
void v8::Template::Set(v8::Local<v8::Name> name, v8::Local<v8::Data> value, v8::PropertyAttribute attr)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    // value可以是v8::FunctionTemplate、v8::Integer等
    miniv8::V8Template* self = v8::Utils::openHandle<v8::Template, miniv8::V8Template>(this);
    self->Set(name, value, attr);
}

static void V8CALL functionCallbackEmpty(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    info.GetReturnValue().Set(info.This());
}

// static
v8::Local<v8::FunctionTemplate> v8::FunctionTemplate::New(v8::Isolate* isolate, v8::FunctionCallback callback, v8::Local<v8::Value> data,
    v8::Local<v8::Signature> signature, int length, v8::ConstructorBehavior behavior, SideEffectType side_effect_type, const CFunction* c_function,
    uint16_t instance_type, uint16_t allowed_receiver_instance_type_range_start, uint16_t allowed_receiver_instance_type_range_end)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8FunctionTemplate* self = new miniv8::V8FunctionTemplate();

    if (!data.IsEmpty()) {
        miniv8::V8External* dataVal = (miniv8::V8External*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*data); // TODO: free
        miniv8ReleaseAssert(dataVal->m_head.m_type == miniv8::kOTExternal, "v8::FunctionTemplate::New fail\n");

        self->m_userdata = dataVal->getUserdata();
    }
    self->m_constructor = callback ? callback : functionCallbackEmpty;
    self->m_argLength = length;
    self->m_signature.Reset(isolate, signature);

    v8::Local<v8::FunctionTemplate> ret = v8::Utils::convert<miniv8::V8FunctionTemplate, v8::FunctionTemplate>(self);
    return ret;
}

//look at v8::Object::FindInstanceInPrototypeChain
bool v8::FunctionTemplate::HasInstance(v8::Local<v8::Value> object)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    if (object.IsEmpty())
        return false;

    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);
    if (!self)
        return false;
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8::Isolate::GetCurrent();
    miniv8::V8Value* objVal = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*object);
    miniv8::V8Object* obj = miniv8::V8Object::getByQjsValue(objVal->v(objVal));
    if (!obj)
        return false;

    if (miniv8::V8ObjectType::kOTObject != obj->m_head.m_type && miniv8::V8ObjectType::kOTArray != obj->m_head.m_type
        && (obj->m_head.m_type < miniv8::V8ObjectType::kOTUint8CArray || obj->m_head.m_type > miniv8::V8ObjectType::kOTFloat64Array)) {
        //miniv8ReleaseAssert(false, "v8::FunctionTemplate::HasInstance fail\n");
        return false;
    }

    miniv8::V8Template* objTempl = isolate->getTemplateById(obj->m_templId);

    while (objTempl) {
        if (objTempl->getRegisterId() == self->getRegisterId())
            return true;
        objTempl = objTempl->getParentTemplate();
    }
    return false;
}

v8::Local<v8::ObjectTemplate> v8::FunctionTemplate::InstanceTemplate(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::Local<v8::ObjectTemplate> ret;
    JSContext* ctx = miniv8::V8Context::getEmptyJsCtx();

    if (!self->m_instanceTemplate) {
        miniv8::V8ObjectTemplate* templ = new miniv8::V8ObjectTemplate();
        templ->m_internalFieldCount = self->m_internalFieldCount;
        templ->m_parentTemplate = self;
        JS_DupValue(ctx, self->v(self));
        JS_SetPropertyStr(ctx, templ->v(templ), "parentTemplate", self->v(self));

        self->m_instanceTemplate = templ;
        JS_DupValue(ctx, templ->v(templ));
        JS_SetPropertyStr(ctx, self->v(self), "instanceTemplate", templ->v(templ));

        //printDebug("FunctionTemplate::InstanceTemplate: self: %p, instanceTemplate:%p\n", self, templ);
    }

    ret = v8::Utils::convert<miniv8::V8ObjectTemplate, v8::ObjectTemplate>(self->m_instanceTemplate);
    return ret;
}

v8::Local<v8::ObjectTemplate> v8::FunctionTemplate::PrototypeTemplate(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::Local<v8::ObjectTemplate> ret;
    JSContext* ctx = miniv8::V8Context::getEmptyJsCtx();

    if (!self->m_prototypeTemplate) {
        miniv8::V8ObjectTemplate* templ = new miniv8::V8ObjectTemplate();
        templ->m_internalFieldCount = self->m_internalFieldCount;
        templ->m_parentTemplate = self;
        JS_DupValue(ctx, self->v(self));
        JS_SetPropertyStr(ctx, templ->v(templ), "parentTemplate", self->v(self));

        self->m_prototypeTemplate = templ;
        JS_DupValue(ctx, templ->v(templ));
        JS_SetPropertyStr(ctx, self->v(self), "prototypeTemplate", templ->v(templ));

        //printDebug("FunctionTemplate::PrototypeTemplate: self: %p, prototype:%p\n", self, self->m_prototypeTemplate);
    }

    ret = v8::Utils::convert<miniv8::V8ObjectTemplate, v8::ObjectTemplate>(self->m_prototypeTemplate);
    return ret;
}

v8::Local<v8::Function> v8::FunctionTemplate::GetFunction(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    return self->GetFunction(isolate->GetCurrentContext()).ToLocalChecked();
}

v8::MaybeLocal<v8::Function> v8::FunctionTemplate::GetFunction(v8::Local<v8::Context> context)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);
    return self->GetFunction(context);
}

void v8::FunctionTemplate::Inherit(v8::Local<v8::FunctionTemplate> parentTemplate)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);
    miniv8::V8FunctionTemplate* parent = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(*parentTemplate);
    self->inherit(parent);
}

void v8::FunctionTemplate::ReadOnlyPrototype(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::FunctionTemplate::RemovePrototype(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::FunctionTemplate::SetAcceptAnyReceiver(bool)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::FunctionTemplate::SetCallHandler(v8::FunctionCallback constructor, v8::Local<v8::Value> data
#if V8_MINOR_VERSION < 8
    ,
    v8::experimental::FastAccessorBuilder* fastHandler
#endif
)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8External* dataExternal = nullptr;
    if (!data.IsEmpty())
        dataExternal = (miniv8::V8External*)(v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*data));

    miniv8ReleaseAssert(!dataExternal || dataExternal->m_head.m_type == miniv8::kOTExternal, "FunctionTemplate::SetCallHandler data fail\n");
#if V8_MINOR_VERSION < 8
    miniv8ReleaseAssert(!fastHandler, "FunctionTemplate::SetCallHandler fastHandler fail\n");
#endif

    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);
    self->m_constructor = constructor;
    self->m_userdata = dataExternal ? dataExternal->getUserdata() : nullptr;
}

void v8::FunctionTemplate::SetClassName(v8::Local<v8::String> name)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8FunctionTemplate* self = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(this);
    std::string nameStr = miniv8::getStringFromV8String(name);
    self->setClassName(nameStr);
}

void v8::FunctionTemplate::SetHiddenPrototype(bool)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::FunctionTemplate::SetLength(int)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

//////////////////////////////////////////////////////////////////////////

// static
v8::Local<v8::ObjectTemplate> v8::ObjectTemplate::New(v8::Isolate*, v8::Local<v8::FunctionTemplate> constructor)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8ObjectTemplate* objTemp = new miniv8::V8ObjectTemplate();
    v8::Local<v8::ObjectTemplate> ret = v8::Utils::convert<miniv8::V8ObjectTemplate, v8::ObjectTemplate>(objTemp);
    return ret;
}

void v8::ObjectTemplate::MarkAsUndetectable(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::ObjectTemplate::SetAccessCheckCallback(bool(__cdecl*)(v8::Local<v8::Context>, v8::Local<v8::Object>, v8::Local<v8::Value>), v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Template::SetAccessorProperty(
    v8::Local<v8::Name> name, v8::Local<v8::FunctionTemplate> getter, v8::Local<v8::FunctionTemplate> setter, v8::PropertyAttribute, v8::AccessControl)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8ReleaseAssert(name->IsString(), "v8::Template::SetAccessorProperty fail 1\n");

    miniv8::V8Template* self = v8::Utils::openHandle<v8::Template, miniv8::V8Template>(this);
    miniv8::V8String* nameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(name.As<v8::String>()));

    miniv8::V8FunctionTemplate* getterTempl = nullptr;
    if (!getter.IsEmpty())
        getterTempl = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(*getter);
    miniv8::V8FunctionTemplate* setterTempl = nullptr;
    if (!setter.IsEmpty())
        setterTempl = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(*setter);
    miniv8ReleaseAssert(getterTempl || setterTempl, "v8::Template::SetAccessorProperty fail 2\n");

    std::string nameString = nameStr->getStr();

    if (getterTempl && setterTempl)
        miniv8ReleaseAssert(getterTempl->m_userdata == setterTempl->m_userdata, "v8::Template::SetAccessorProperty fail 3\n");

    //     std::map<std::string, miniv8::V8ObjectTemplate::Accessor>::const_iterator it = self->m_accessors.find(nameString);
    //     if (it != self->m_accessors.end())
    //         DebugBreak();

    miniv8::V8ObjectTemplate::Accessor accessor;
    accessor.getterFunc = getterTempl ? getterTempl->m_constructor : nullptr;
    accessor.setterFunc = setterTempl ? setterTempl->m_constructor : nullptr;
    accessor.data = getterTempl ? getterTempl->m_userdata : setterTempl->m_userdata;
    accessor.name = nameString;
    miniv8::stdMapInsert(&self->m_accessors, nameString, accessor);
}

void v8::Template::SetNativeDataProperty(v8::Local<v8::Name> name, v8::AccessorNameGetterCallback getter, v8::AccessorNameSetterCallback setter,
    v8::Local<v8::Value> data, v8::PropertyAttribute attribute, v8::Local<v8::AccessorSignature> signature, v8::AccessControl settings)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* nameStr = v8::Utils::openHandle<v8::Name, miniv8::V8String>(*name);

    size_t len = 0;
    std::string nameString = nameStr->getStr();
    if (nameString.empty())
        return;
    if (nameString == "length" || "name" == nameString || "toString" == nameString) // window属性的length暂不支持
        return;

    miniv8::V8External* external = v8::Utils::openHandle<v8::Value, miniv8::V8External>(*data);
    miniv8::V8Template* self = v8::Utils::openHandle<v8::Template, miniv8::V8Template>(this);
    miniv8::V8Template::Accessor accessor;
    accessor.nameGetter = getter;
    accessor.nameSetter = setter;
    accessor.data = external ? external->getUserdata() : nullptr;
    accessor.name = nameString;
    miniv8::stdMapInsert(&self->m_accessors, nameString, accessor);
}

void v8::ObjectTemplate::SetAccessor2(Local<String> name, AccessorGetterCallback getter, AccessorSetterCallback setter, Local<Value> data,
    AccessControl settings, PropertyAttribute attribute, SideEffectType getter_side_effect_type, SideEffectType setter_side_effect_type)
{
    SetAccessor(name, getter, setter, data, settings, attribute, v8::Local<v8::AccessorSignature>());
}

void v8::ObjectTemplate::SetAccessor3(Local<Name> name, AccessorNameGetterCallback getter, AccessorNameSetterCallback setter, Local<Value> data,
    AccessControl settings, PropertyAttribute attribute, SideEffectType getter_side_effect_type, SideEffectType setter_side_effect_type)
{
    SetAccessor(name, getter, setter, data, settings, attribute, v8::Local<v8::AccessorSignature>());
}

void v8::ObjectTemplate::SetAccessor(v8::Local<v8::Name> name, v8::AccessorNameGetterCallback getter, v8::AccessorNameSetterCallback setter,
    v8::Local<v8::Value> data, v8::AccessControl settings, v8::PropertyAttribute attribute, v8::Local<v8::AccessorSignature> signature)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8String* nameStr = v8::Utils::openHandle<v8::Name, miniv8::V8String>(*name);

    size_t len = 0;
    std::string nameString = nameStr->getStr();
    if (nameString.empty())
        return;
    if (nameString == "length" || "name" == nameString || "toString" == nameString) // window属性的length暂不支持
        return;

    miniv8::V8External* external = v8::Utils::openHandle<v8::Value, miniv8::V8External>(*data);
    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);
    miniv8::V8ObjectTemplate::Accessor accessor;
    accessor.nameGetter = getter;
    accessor.nameSetter = setter;
    accessor.data = external->getUserdata();
    accessor.name = nameString;
    miniv8::stdMapInsert(&self->m_accessors, nameString, accessor);
}

void v8::ObjectTemplate::SetAccessor(v8::Local<v8::String> name, v8::AccessorGetterCallback getter, v8::AccessorSetterCallback setter,
    v8::Local<v8::Value> data, v8::AccessControl settings, v8::PropertyAttribute attribute, v8::Local<v8::AccessorSignature> signature)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8String* nameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*name);
    size_t len = 0;
    std::string nameString = nameStr->getStr();
    if (nameString.empty())
        return;

    if (nameString == "length" || "name" == nameString || "toString" == nameString) // window属性的length暂不支持
        return;

    miniv8::V8External* external = v8::Utils::openHandle<v8::Value, miniv8::V8External>(*data);
    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);

    miniv8::V8ObjectTemplate::Accessor accessor;
    accessor.getter = getter;
    accessor.setter = setter;
    accessor.data = external ? external->getUserdata() : nullptr;
    miniv8::stdMapInsert(&self->m_accessors, nameString, accessor);
}

void v8::ObjectTemplate::SetCallAsFunctionHandler(v8::FunctionCallback cb, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    OutputDebugStringA("v8::ObjectTemplate::SetCallAsFunctionHandler not impl\n");
}

void v8::ObjectTemplate::SetHandler(const v8::IndexedPropertyHandlerConfiguration& indexedHandle)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);

    if (indexedHandle.getter)
        self->m_indexedPropHandles.getter = indexedHandle.getter;
    if (indexedHandle.query)
        self->m_indexedPropHandles.query = indexedHandle.query;
    if (indexedHandle.setter)
        self->m_indexedPropHandles.setter = indexedHandle.setter;
    if (indexedHandle.deleter)
        self->m_indexedPropHandles.deleter = indexedHandle.deleter;
    if (indexedHandle.enumerator)
        self->m_indexedPropHandles.enumerator = indexedHandle.enumerator;
    if (indexedHandle.definer)
        self->m_indexedPropHandles.definer = indexedHandle.definer;
    if (indexedHandle.descriptor)
        self->m_indexedPropHandles.descriptor = indexedHandle.descriptor;
}

void v8::ObjectTemplate::SetHandler(const v8::NamedPropertyHandlerConfiguration& namedHandle)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);

    if (namedHandle.getter)
        self->m_namePropHandles.getter = namedHandle.getter;
    if (namedHandle.query)
        self->m_namePropHandles.query = namedHandle.query;
    if (namedHandle.setter)
        self->m_namePropHandles.setter = namedHandle.setter;
    if (namedHandle.deleter)
        self->m_namePropHandles.deleter = namedHandle.deleter;
    if (namedHandle.enumerator)
        self->m_namePropHandles.enumerator = namedHandle.enumerator;
}

#if V8_MINOR_VERSION < 8
void v8::ObjectTemplate::SetNamedPropertyHandler(v8::NamedPropertyGetterCallback getter, v8::NamedPropertySetterCallback setter,
    v8::NamedPropertyQueryCallback query, v8::NamedPropertyDeleterCallback deleter, v8::NamedPropertyEnumeratorCallback enumerator, v8::Local<v8::Value> data)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    v8::NamedPropertyHandlerConfiguration namedHandle;
    namedHandle.getter = getter;
    namedHandle.setter = setter;
    namedHandle.query = query;
    namedHandle.deleter = deleter;
    namedHandle.enumerator = enumerator;
    namedHandle.data = data;

    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);
    self->m_namePropHandles = namedHandle;
}
#else
void v8::ObjectTemplate::SetNamedPropertyHandler(v8::NamedPropertyGetterCallback getter, v8::NamedPropertySetterCallback setter,
    v8::NamedPropertyQueryCallback query, v8::NamedPropertyDeleterCallback deleter, v8::NamedPropertyEnumeratorCallback enumerator, v8::Local<v8::Value> data)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}
#endif

void v8::ObjectTemplate::SetInternalFieldCount(int count)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);
    self->m_internalFieldCount = count;

    if (self->m_parentTemplate) {
        int parentCount = self->getParentTemplate()->m_internalFieldCount;
        //miniv8ReleaseAssert(parentCount == 0 || parentCount == count, "v8::ObjectTemplate::SetInternalFieldCount fail\n");
        if (parentCount == 0)
            self->getParentTemplate()->m_internalFieldCount = count;
    }
    //printDebug("v8::ObjectTemplate::SetInternalFieldCount: %p, %d\n", this, count);
}

int v8::ObjectTemplate::InternalFieldCount()
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);

    char* output = (char*)malloc(0x100);
    sprintf(output, "v8::ObjectTemplate::InternalFieldCount: %p\n", self);
    OutputDebugStringA(output);
    free(output);

    return self->m_internalFieldCount;
}

v8::MaybeLocal<v8::Object> v8::ObjectTemplate::NewInstance(v8::Local<v8::Context> context)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8ObjectTemplate* self = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(this);
    miniv8::V8Context* jsCtx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSContext* ctx = jsCtx->ctx();

    JSValue v = JS_NewObject(ctx);
    miniv8::V8Object* obj = new miniv8::V8Object(jsCtx, v);
    JS_FreeValue(ctx, v);
    self->newTemplateInstance(obj, false);

    v8::Local<v8::Object> ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(obj);

    // 有可能本ObjectTemplate是FunctionTemplate的InstanceTemplate，所以调用本函数的时候，需要把FunctionTemplate的原型链搞过来
    JSValue parentTemplateV = JS_NULL;
    JSValue prototypeTemplateV = JS_NULL;
    do {
        parentTemplateV = JS_GetPropertyStr(ctx, self->v(self), "parentTemplate");
        miniv8::V8FunctionTemplate* parentTemplate = (miniv8::V8FunctionTemplate*)JS_GetUserdata(parentTemplateV);
        if (!parentTemplate || parentTemplate->m_head.m_type != miniv8::kOTFunctionTemplate)
            break;

        prototypeTemplateV = JS_GetPropertyStr(ctx, parentTemplateV, "prototypeTemplate");
        miniv8::V8ObjectTemplate* prototypeTemplate = (miniv8::V8ObjectTemplate*)JS_GetUserdata(prototypeTemplateV);
        if (!prototypeTemplate || prototypeTemplate->m_head.m_type != miniv8::kOTObjectTemplate)
            break;
        if (prototypeTemplate == self)
            break;

        miniv8ReleaseAssert(self->m_parentTemplate == parentTemplate && parentTemplate->m_prototypeTemplate == prototypeTemplate, "");
        v8::Local<v8::ObjectTemplate> prototypeTemplateV8 = v8::Utils::convert<miniv8::V8ObjectTemplate, v8::ObjectTemplate>(prototypeTemplate);
        v8::MaybeLocal<v8::Object> prototype = prototypeTemplateV8->NewInstance(context); // 这句里面会调用m_prototypeTemplate->newTemplateInstance(fun, true);
        if (!prototype.IsEmpty()) {
            miniv8::V8Object* prototypeObject = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(*(prototype.ToLocalChecked()));
            JS_SetPrototype(ctx, obj->v(obj), prototypeObject->v(prototypeObject));

            obj->setTemplId(self->getRegisterId());
        }
    } while (false);

    JS_FreeValue(ctx, prototypeTemplateV);
    JS_FreeValue(ctx, parentTemplateV);
    return ret;
}

//////////////////////////////////////////////////////////////////////////

v8::Local<v8::Integer> v8::Integer::New(v8::Isolate*, int v)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Integer* obj = new miniv8::V8Integer(v);
    v8::Local<v8::Integer> ret = v8::Utils::convert<miniv8::V8Integer, v8::Integer>(obj);
    return ret;
}

v8::Local<v8::Integer> v8::Integer::NewFromUnsigned(v8::Isolate*, uint32_t v)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Integer* obj = new miniv8::V8Integer(v); // TODO: 没区分有无符号
    v8::Local<v8::Integer> ret = v8::Utils::convert<miniv8::V8Integer, v8::Integer>(obj);
    return ret;
}

size_t v8::TypedArray::Length(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8ArrayBufferView* arrayBufView = v8::Utils::openHandle<v8::TypedArray, miniv8::V8ArrayBufferView>(this);
    return arrayBufView->getEleCount();
}

template <typename V8TypeT, typename JsTypeT, JS_TYPED_ARRAY type>
static v8::Local<V8TypeT> typedArrayNew(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    JSContext* ctx = miniv8::V8Context::getEmptyJsCtx();
    miniv8::V8Context* context = miniv8::V8Context::getEmptyCtx();

    miniv8::V8ArrayBuffer* arrayBuf = v8::Utils::openHandle<v8::ArrayBuffer, miniv8::V8ArrayBuffer>(*arrayBuffer);
    //printDebug("typedArrayNew:%p\n", arrayBuf);

    JSValue arrayBufVal = arrayBuf->v(arrayBuf);
    //JS_DupValue(ctx, arrayBufVal); // 2023.3.30: 这里看起来要dup…

    JSValue val = JS_NewTypedArray(ctx, type, arrayBufVal, byteOffset, length);
    JsTypeT* ret = JsTypeT::create(context, val);
    JS_FreeValue(ctx, val);
    return v8::Utils::convert<JsTypeT, V8TypeT>(ret);
}

v8::Local<v8::Int16Array> v8::Int16Array::New(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return typedArrayNew<v8::Int16Array, miniv8::V8Int16Array, JS_INT16_TYPED_ARRAY>(arrayBuffer, byteOffset, length);
}

v8::Local<v8::Int32Array> v8::Int32Array::New(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return typedArrayNew<v8::Int32Array, miniv8::V8Int32Array, JS_INT32_TYPED_ARRAY>(arrayBuffer, byteOffset, length);
}

v8::Local<v8::Int8Array> v8::Int8Array::New(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return typedArrayNew<v8::Int8Array, miniv8::V8Int8Array, JS_INT8_TYPED_ARRAY>(arrayBuffer, byteOffset, length);
}

v8::Local<v8::Uint16Array> v8::Uint16Array::New(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return typedArrayNew<v8::Uint16Array, miniv8::V8Uint16Array, JS_UINT16_TYPED_ARRAY>(arrayBuffer, byteOffset, length);
}

v8::Local<v8::Uint32Array> v8::Uint32Array::New(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return typedArrayNew<v8::Uint32Array, miniv8::V8Uint32Array, JS_UINT32_TYPED_ARRAY>(arrayBuffer, byteOffset, length);
}

v8::Local<v8::Uint8Array> v8::Uint8Array::New(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return typedArrayNew<v8::Uint8Array, miniv8::V8Uint8Array, JS_UINT8_TYPED_ARRAY>(arrayBuffer, byteOffset, length);
}

v8::Local<v8::Uint8ClampedArray> v8::Uint8ClampedArray::New(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return typedArrayNew<v8::Uint8ClampedArray, miniv8::V8Uint8ClampedArray, JS_UINT8C_TYPED_ARRAY>(arrayBuffer, byteOffset, length);
}

v8::Local<v8::Float32Array> v8::Float32Array::New(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return typedArrayNew<v8::Float32Array, miniv8::V8Float32Array, JS_FLOAT32_TYPED_ARRAY>(arrayBuffer, byteOffset, length);
}

v8::Local<v8::Float64Array> v8::Float64Array::New(v8::Local<v8::ArrayBuffer> arrayBuffer, size_t byteOffset, size_t length)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return typedArrayNew<v8::Float64Array, miniv8::V8Float64Array, JS_FLOAT64_TYPED_ARRAY>(arrayBuffer, byteOffset, length);
}

v8::Local<v8::Map> v8::Map::New(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    JSContext* ctx = miniv8::V8Context::getEmptyJsCtx();
    miniv8::V8Context* context = miniv8::V8Context::getEmptyCtx();

    JSValue val = JS_NewMap(ctx);
    miniv8::V8Map* ret = (miniv8::V8Map*)miniv8::V8Value::create(context, val);
    JS_FreeValue(ctx, val);
    return v8::Utils::convert<miniv8::V8Map, v8::Map>(ret);
}

v8::MaybeLocal<v8::Map> v8::Map::Set(v8::Local<v8::Context> context, v8::Local<v8::Value> key, v8::Local<v8::Value> value)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* v8ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Map* v8map = v8::Utils::openHandle<v8::Map, miniv8::V8Map>(this);
    v8::Local<v8::String> keyStr;
    miniv8::V8Value* v8value = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*value);

    //miniv8::V8String* v8key = v8::Utils::openHandle<v8::String, miniv8::V8String>(*keyStr);
    miniv8::V8Value* v8key = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);

    JSValue v = v8value->v(v8value);
    JS_DupValue(v8ctx->ctx(), v);

    JSValue setVal = JS_GetPropertyStr(v8ctx->ctx(), v8map->v(v8map), "set");
    int count = JS_GetRefCount(v8ctx->ctx(), v8map->v(v8map));

    JSValueConst argv[2];
    argv[0] = v8key->v(v8key);
    argv[1] = v;
    JSValue ret = JS_Call(v8ctx->ctx(), setVal, v8map->v(v8map), 2, argv); // js_map_set
    count = JS_GetRefCount(v8ctx->ctx(), v8map->v(v8map));

    if (JS_IsException(ret))
        return v8::MaybeLocal<v8::Map>();

    return v8::Utils::convert<miniv8::V8Map, v8::Map>(v8map);
}

v8::MaybeLocal<v8::Value> v8::Map::Get(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::MaybeLocal<v8::Value> ret;
    DebugBreak();
    return ret;
}

v8::Local<v8::Message> v8::Exception::CreateMessage(v8::Isolate*, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::Message>();
}

void v8::Isolate::IsolateInBackgroundNotification()
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::Local<v8::NativeWeakMap> v8::NativeWeakMap::New(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::NativeWeakMap>();
}

v8::Local<v8::Number> v8::Number::New(v8::Isolate*, double num)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Number* number = new miniv8::V8Number(num);
    v8::Local<v8::Number> ret = v8::Utils::convert<miniv8::V8Number, v8::Number>(number);
    return ret;
}

v8::Local<v8::Number> v8::Value::ToNumber(v8::Isolate*) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Local<v8::Number>();
}

// v8::Local<v8::Number> v8::Value::ToNumber(void) const
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
//     return v8::Local<v8::Number>();
// }

v8::Local<v8::Integer> v8::Value::ToInteger(v8::Isolate*) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::MaybeLocal<v8::Integer> ret = ToInteger(isolate->GetCurrentContext());
    return ret.ToLocalChecked();
}

v8::MaybeLocal<v8::Integer> v8::Value::ToInteger(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSValue v = self->v(self);
    miniv8::V8Integer* ret = nullptr;
    int32_t res;
    if (0 == JS_ToInt32(ctx->ctx(), &res, v)) {
        ret = new miniv8::V8Integer(res);
    } else
        ret = new miniv8::V8Integer(0);

    return v8::Utils::convert<miniv8::V8Integer, v8::Integer>(ret);
}

v8::MaybeLocal<v8::Number> v8::Value::ToNumber(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Number* num = nullptr;

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (self->m_head.m_type == miniv8::kOTNumber)
        return v8::Utils::convert<miniv8::V8Number, v8::Number>((miniv8::V8Number*)self);

    JSValue v = self->v(self);
    num = new miniv8::V8Number(ctx, v);

    //     int32_t res = 0;
    //     if (JS_IsInteger(v)) {
    //         JS_ToInt32(ctx, &res, v);
    //         num = new miniv8::V8Number();
    //     }
    return v8::Utils::convert<miniv8::V8Number, v8::Number>(num);
}

v8::MaybeLocal<v8::Object> v8::Value::ToObject(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    v8::Local<v8::Object> ret;
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    JSValue v = self->v(self);
    if (self->m_head.m_type == miniv8::kOTObject || JS_IsObject(v))
        ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(miniv8::V8Object::create(ctx, v));
    else
        ret = v8::Object::New(isolate);

    return ret;
}

v8::Local<v8::Int32> v8::Value::ToInt32(v8::Isolate* isolate) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return ToInt32(isolate->GetCurrentContext()).ToLocalChecked();
}

v8::Maybe<int> v8::Value::Int32Value(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    int ret = JS_ToInt32(ctx, &res, self->v(self));
    if (0 <= ret)
        return v8::Just(res);
    return v8::Just(0);
}

int v8::Value::Int32Value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    int ret = JS_ToInt32(ctx, &res, self->v(self));
    if (0 <= ret)
        return res;
    return 0;
}

v8::MaybeLocal<v8::Int32> v8::Value::ToInt32(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    if (0 > JS_ToInt32(ctx, &res, self->v(self)))
        res = 0;
    miniv8::V8Int32* ret = new miniv8::V8Int32(res);
    return v8::Utils::convert<miniv8::V8Int32, v8::Int32>(ret);
}

v8::MaybeLocal<v8::Uint32> v8::Value::ToUint32(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    if (0 > JS_ToInt32(ctx, &res, self->v(self)))
        res = 0;
    miniv8::V8Uint32* ret = new miniv8::V8Uint32(res);
    return v8::Utils::convert<miniv8::V8Uint32, v8::Uint32>(ret);
}

v8::Maybe<unsigned int> v8::Value::Uint32Value(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    int32_t res = 0;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    int ret = JS_ToInt32(ctx, &res, self->v(self));
    if (0 <= ret)
        return v8::Just((unsigned int)res);
    return v8::Just((unsigned int)0);
}

v8::MaybeLocal<v8::Uint32> v8::Value::ToArrayIndex(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::MaybeLocal<v8::Uint32> ret;
    DebugBreak();
    return ret;
}

v8::Local<v8::Boolean> v8::Value::ToBoolean(v8::Isolate* isolate) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return ToBoolean(isolate->GetCurrentContext()).ToLocalChecked();
}

v8::MaybeLocal<v8::Boolean> v8::Value::ToBoolean(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);

    bool b = 1 == JS_ToBool(ctx->ctx(), self->v(self));
    miniv8::V8Boolean* ret = new miniv8::V8Boolean(b);
    return v8::Utils::convert<miniv8::V8Boolean, v8::Boolean>(ret);
}

v8::Local<v8::Object> v8::Proxy::GetTarget(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Local<v8::Object>();
}

v8::Local<v8::Object> v8::Value::ToObject(v8::Isolate* isolata) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Context* context = miniv8::V8Context::getCurrentCtx();
    JSValue val = self->v(self);

    //     if (self->m_head.m_type == miniv8::V8ObjectType::kOTObject) {
    // //         miniv8::V8Object* ret = miniv8::V8Object::create(context, val);
    // //         return v8::Utils::convert<miniv8::V8Object, v8::Object>(ret);
    //
    //         return v8::Utils::convert<miniv8::V8Object, v8::Object>((miniv8::V8Object*)self);
    //
    //     } else if (self->m_head.m_type == miniv8::V8ObjectType::kOTValue) {
    //         if (JS_IsArrayBuffer(val)) {
    // //             miniv8::V8Value* ret = miniv8::V8Value::create(context, val);
    // //             return v8::Utils::convert<miniv8::V8Object, v8::Object>((miniv8::V8Object*)ret);
    //             return v8::Utils::convert<miniv8::V8Object, v8::Object>((miniv8::V8Object*)self);
    //         } else
    //             DebugBreak();
    //     } else
    //         miniv8ReleaseAssert(false, "v8::Value::ToObject");

    switch (self->m_head.m_type) {
    case miniv8::V8ObjectType::kOTObject:
    case miniv8::V8ObjectType::kOTUint8CArray:
    case miniv8::V8ObjectType::kOTInt8Array:
    case miniv8::V8ObjectType::kOTUint8Array:
    case miniv8::V8ObjectType::kOTInt16Array:
    case miniv8::V8ObjectType::kOTUint16Array:
    case miniv8::V8ObjectType::kOTInt32Array:
    case miniv8::V8ObjectType::kOTUint32Array:
    case miniv8::V8ObjectType::kOTFloat32Array:
    case miniv8::V8ObjectType::kOTFloat64Array:
        return v8::Utils::convert<miniv8::V8Object, v8::Object>((miniv8::V8Object*)self);
    case miniv8::V8ObjectType::kOTValue:
        if (JS_IsObject(val)) {
            miniv8::V8Object* ret = miniv8::V8Object::create(context, val);
            return v8::Utils::convert<miniv8::V8Object, v8::Object>(ret);
        }
        DebugBreak();
    }

    return v8::Local<v8::Object>();
}

v8::Maybe<bool> v8::Value::Equals(v8::Local<v8::Context> context, v8::Local<v8::Value> other) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Context* v8ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Value* v8other = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*other);

    if (!self && !v8other)
        return v8::Just<bool>(true);

    if ((!self && v8other) || (self && !v8other))
        return v8::Just<bool>(false);

    if (self == v8other)
        return v8::Just<bool>(true);

    if (self->m_head.m_type != v8other->m_head.m_type)
        return v8::Just<bool>(false);

    if (JS_IsValueEq(v8ctx->ctx(), self->m_head.m_qjsValue, v8other->m_head.m_qjsValue, TRUE))
        return v8::Just<bool>(true);

    return v8::Nothing<bool>();
}

v8::Local<v8::Set> v8::Set::New(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::Set>();
}

v8::Local<v8::Signature> v8::Signature::New(v8::Isolate*, v8::Local<v8::FunctionTemplate> templ)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8FunctionTemplate* templPtr = v8::Utils::openHandle<v8::FunctionTemplate, miniv8::V8FunctionTemplate>(*templ);
    miniv8::V8Signature* ret = miniv8::V8Signature::create(templPtr);

    return v8::Utils::convert<miniv8::V8Signature, v8::Signature>(ret);
}

v8::Local<v8::StackFrame> v8::StackTrace::GetFrame(unsigned int) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::StackFrame>();
}

v8::Local<v8::StackTrace> v8::Message::GetStackTrace(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::StackTrace>();
}

v8::Local<v8::StackTrace> v8::StackTrace::CurrentStackTrace(v8::Isolate*, int, v8::StackTrace::StackTraceOptions)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8StackTrace* ret = new miniv8::V8StackTrace();
    return v8::Utils::convert<miniv8::V8StackTrace, v8::StackTrace>(ret);
}

v8::Local<v8::String> v8::CpuProfile::GetTitle(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::CpuProfileNode::GetFunctionName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::CpuProfileNode::GetScriptResourceName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::Message::Get(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::Message::GetSourceLine(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::RegExp::GetSource(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::StackFrame::GetFunctionName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::StackFrame::GetScriptName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::StackFrame::GetScriptNameOrSourceURL(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::StringObject::ValueOf(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Local<v8::String>();
}

v8::Local<v8::String> v8::Value::ToString(v8::Isolate*) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8::Isolate::GetCurrent();
    miniv8::V8Context* context = isolate->getCurrentCtx();
    JSContext* ctx = isolate->getCurrentJsCtx();

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);

    JSValue v = self->v(self);
    JSValue strVal = JS_ToString(ctx, v);
    size_t len = 0;
    const char* ret = JS_ToCStringLen(ctx, &len, strVal);
    miniv8::V8Value* str = miniv8::V8Value::create(context, strVal);
    JS_FreeCString(ctx, strVal, ret);

    if (str->m_head.m_type == miniv8::kOTString) {
        return v8::Utils::convert<miniv8::V8Value, v8::String>(str);
    }
    DebugBreak();
    return v8::Local<v8::String>();
}

v8::Local<v8::Symbol> v8::Symbol::GetIterator(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Symbol* self = new miniv8::V8Symbol("Symbol.iterator");
    v8::Local<v8::Symbol> ret = v8::Utils::convert<miniv8::V8Symbol, v8::Symbol>(self);
    return ret;
}

v8::Local<v8::Symbol> v8::Symbol::GetUnscopables(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Symbol* self = new miniv8::V8Symbol("Symbol.unscopables");
    v8::Local<v8::Symbol> ret = v8::Utils::convert<miniv8::V8Symbol, v8::Symbol>(self);
    return ret;
}

v8::Local<v8::Symbol> v8::Symbol::GetToStringTag(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //printDebug("v8::Symbol::GetToStringTag not impl!\n");
    miniv8::V8Symbol* self = new miniv8::V8Symbol("Symbol.toStringTag");
    v8::Local<v8::Symbol> ret = v8::Utils::convert<miniv8::V8Symbol, v8::Symbol>(self);
    return ret;
}

v8::Local<v8::Value> v8::Symbol::Description(v8::Isolate* v8isolate) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Symbol* self = v8::Utils::openHandle<v8::Symbol, miniv8::V8Symbol>(this);
    return v8::String::NewFromUtf8(v8isolate, self->getStr().c_str());
}

v8::Local<v8::Symbol> v8::Symbol::New(v8::Isolate* isolate, v8::Local<v8::String> str)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* strVal = v8::Utils::openHandle<v8::String, miniv8::V8String>(*str);

    std::string symbolStr /*= "___"*/;
    symbolStr += strVal->getStr();
    //symbolStr += "___";
    miniv8::V8Symbol* self = new miniv8::V8Symbol(symbolStr);
    v8::Local<v8::Symbol> ret = v8::Utils::convert<miniv8::V8Symbol, v8::Symbol>(self);
    return ret;
}

v8::Local<v8::Value> v8::Symbol::Name(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, false);
    return v8::Local<v8::Value>();
}

v8::Local<v8::Symbol> v8::SymbolObject::ValueOf(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, false);
    DebugBreak();
    return v8::Local<v8::Symbol>();
}

v8::Local<v8::UnboundScript> v8::Script::GetUnboundScript(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::UnboundScript>();
}

v8::Local<v8::Value> v8::BooleanObject::New(v8::Isolate*, bool)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::Context::GetSecurityToken(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::Value>();
}

static v8::Local<v8::Value> newError(v8::Local<v8::String> errorString, const char* type)
{
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::Local<v8::Object> err = v8::Object::New(isolate);
    v8::Local<v8::String> key = v8::String::NewFromUtf8(isolate, "error", v8::NewStringType::kNormal, -1).ToLocalChecked();
    err->Set(isolate->GetCurrentContext(), key, errorString);
    return err;
}

v8::Local<v8::Value> v8::Exception::Error(v8::Local<v8::String> errorString)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //     miniv8::V8String* errStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*err);
    //     miniv8::V8Exception* exc = new miniv8::V8Exception(errStr->getStr());
    //     return v8::Utils::convert<miniv8::V8Value, v8::Value>((miniv8::V8Value*)exc);
    return newError(errorString, "error");
}

v8::Local<v8::Value> v8::Exception::RangeError(v8::Local<v8::String> errorString)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return newError(errorString, "error");
}

v8::Local<v8::Value> v8::Exception::ReferenceError(v8::Local<v8::String> errorString)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return newError(errorString, "error");
}

v8::Local<v8::Value> v8::Exception::SyntaxError(v8::Local<v8::String> errorString)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return newError(errorString, "error");
}

v8::Local<v8::Value> v8::Exception::TypeError(v8::Local<v8::String> errorString)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return newError(errorString, "error");
}

v8::Local<v8::Value> v8::HeapProfiler::FindObjectById(unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::Isolate::ThrowException(v8::Local<v8::Value> val)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;
    miniv8::V8Context* context = isolate->getCurrentCtx();
    JSContext* ctx = context->ctx();
    JSValue v;

    std::string errorStr = "v8::Isolate::ThrowException!";

    //TODO: Free?
    if (val->IsObject()) {
        v8::Local<v8::Object> obj = val.As<v8::Object>();
        v8::Local<v8::String> key = v8::String::NewFromUtf8(this, "error", v8::NewStringType::kNormal, -1).ToLocalChecked();
        v8::MaybeLocal<v8::Value> err = obj->Get(this->GetCurrentContext(), key);
        if (!err.IsEmpty() && err.ToLocalChecked()->IsString()) {
            v8::Local<v8::String> errStr = err.ToLocalChecked().As<v8::String>();
            v8::String::Utf8Value errString(this, errStr);
            errorStr += *errString;
        }

        v = JS_ThrowTypeError(ctx, errorStr.c_str());
    } else if (val->IsString()) {
        miniv8::V8String* errStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(val.As<v8::String>()));
        v = JS_ThrowTypeError(ctx, errStr->getStr().c_str());
    }

    isolate->m_errorVal = v;
    return v8::Utils::convert<miniv8::V8Value, v8::Value>(new miniv8::V8Value(context, v));
}

v8::Local<v8::Value> v8::Message::GetScriptResourceName(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::NativeWeakMap::Get(v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::NumberObject::New(v8::Isolate*, double)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::Proxy::GetHandler(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::Value>();
}

// v8::Local<v8::Value> v8::StringObject::New(v8::Isolate*, v8::Local<v8::String>)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
//     return v8::Local<v8::Value>();
// }

v8::Local<v8::Value> v8::StringObject::New(v8::Local<v8::String>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::Value>();
}

void v8::Locker::Initialize(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

// v8::Locker::Locker(v8::Isolate*)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
// }

v8::Locker::~Locker(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::Maybe<int64_t> v8::Value::IntegerValue(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Context* v8ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSValue v = self->v(self);

    int64_t val = 0;
    if (-1 == JS_ToInt64(v8ctx->ctx(), &val, v))
        return v8::Nothing<int64_t>();
    return v8::Just(val);
}

v8::Maybe<bool> v8::Value::BooleanValue(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSValue v = self->v(self);

    if (1 == JS_ToBool(ctx->ctx(), v))
        return v8::Just(true);
    return v8::Just(false);
}

v8::Maybe<double> v8::Value::NumberValue(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSValue v = self->v(self);
    double res = 0;
    if (0 == JS_ToFloat64(ctx->ctx(), &res, v))
        return v8::Just<double>(res);
    return v8::Just<double>(0);
}

v8::Maybe<int> v8::Message::GetEndColumn(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::Maybe<int> ret = v8::Just(0);
    DebugBreak();
    return ret;
}

v8::Maybe<int> v8::Message::GetLineNumber(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::Maybe<int> ret = v8::Just(0);
    DebugBreak();
    return ret;
}

v8::Maybe<int> v8::Message::GetStartColumn(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::Maybe<int> ret = v8::Just(0);
    DebugBreak();
    return ret;
}

v8::Local<v8::Promise> v8::Promise::Resolver::GetPromise(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Resolver* self = v8::Utils::openHandle<v8::Promise::Resolver, miniv8::V8Resolver>(this);

    miniv8::V8Context* context = miniv8::V8Context::getEmptyCtx();
    JSContext* ctx = context->ctx();

    self->bindResolvingFuncs(context);
    return v8::Utils::convert<miniv8::V8Promise, v8::Promise>(self);

    //     if (!self->m_promise) {
    //         JSValue resolvingFuncs[2];
    //         JSValue promiseVal = JS_NewPromiseCapability(ctx, resolvingFuncs);
    //         int count = JS_GetRefCount(ctx, promiseVal);
    //         count = JS_GetRefCount(ctx, resolvingFuncs[0]);
    //
    //         self->m_promise = new miniv8::V8Promise(context, promiseVal);
    //         self->m_promise->m_resolvingFuncs[0] = resolvingFuncs[0];
    //         self->m_promise->m_resolvingFuncs[1] = resolvingFuncs[1];
    //         JS_DupValue(ctx, resolvingFuncs[0]);
    //         JS_DupValue(ctx, resolvingFuncs[1]);
    //         count = JS_GetRefCount(ctx, promiseVal);
    //
    //         JS_SetPropertyStr(ctx, self->v(self), "promise", promiseVal);
    //         //JS_FreeValue(ctx, promiseVal);
    //         count = JS_GetRefCount(ctx, promiseVal);
    //         count = count;
    //     }
    //     return v8::Utils::convert<miniv8::V8Promise, v8::Promise>(self->m_promise);
}

v8::MaybeLocal<v8::Promise::Resolver> v8::Promise::Resolver::New(v8::Local<v8::Context> context)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    v8::MaybeLocal<v8::Promise::Resolver> ret;
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);

    //JSValue val = JS_NewObject(ctx->ctx());
    miniv8::V8Resolver* resolver = new miniv8::V8Resolver(ctx /*, val*/);
    //JS_FreeValue(ctx->ctx(), val);

    return v8::Utils::convert<miniv8::V8Resolver, v8::Promise::Resolver>(resolver);
}

v8::Maybe<bool> v8::Promise::Resolver::Resolve(v8::Local<v8::Context> context, v8::Local<v8::Value> value)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::Maybe<bool> ret = v8::Just(true);

    miniv8::V8Context* jsCtx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSContext* ctx = jsCtx->ctx();
    miniv8::V8Resolver* resolver = v8::Utils::openHandle<v8::Promise::Resolver, miniv8::V8Resolver>(this);
    miniv8::V8Value* val = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*value);

    JSValue resolverVal = resolver->m_resolvingFuncs[0];
    JSValue jsVal = val->v(val);

    JSValue retVal = JS_Call(ctx, resolverVal, JS_UNDEFINED, 1, &jsVal);
    if (JS_IsException(retVal)) {
        JS_PrintStack(ctx);
    }
    JS_FreeValue(ctx, retVal);

    return ret;
}

v8::Maybe<bool> v8::Promise::Resolver::Reject(v8::Local<v8::Context> context, v8::Local<v8::Value> value)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::Maybe<bool> ret = v8::Just(true);

    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8Resolver* reject = v8::Utils::openHandle<v8::Promise::Resolver, miniv8::V8Resolver>(this);
    miniv8::V8Value* val = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*value);

    JSValue rejectVal = reject->m_resolvingFuncs[1];
    JSValue jsVal = val->v(val);

    JSValue retVal = JS_Call(ctx->ctx(), rejectVal, JS_UNDEFINED, 1, &jsVal);
    JS_FreeValue(ctx->ctx(), retVal);

    return ret;
}

v8::MaybeLocal<v8::Promise> v8::Promise::Catch(v8::Local<v8::Context>, v8::Local<v8::Function>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::MaybeLocal<v8::Promise> ret;
    DebugBreak();
    return ret;
}

v8::MaybeLocal<v8::Promise> v8::Promise::Then(v8::Local<v8::Context>, v8::Local<v8::Function>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::MaybeLocal<v8::Promise> ret;
    DebugBreak();
    return ret;
}

v8::MaybeLocal<v8::RegExp> v8::RegExp::New(v8::Local<v8::Context>, v8::Local<v8::String>, v8::RegExp::Flags)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::MaybeLocal<v8::RegExp> ret;
    return ret;
}

v8::MaybeLocal<v8::Script> v8::Script::Compile(v8::Local<v8::Context> context, v8::Local<v8::String> source, v8::ScriptOrigin* scriptOrigin)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* sourceStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(source));
    std::string name = "[no name]";

    if (scriptOrigin) {
        v8::Local<v8::Value> resourceName = scriptOrigin->ResourceName();
        if (resourceName->IsString()) {
            miniv8::V8String* resName = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(resourceName.As<v8::String>()));
            name = resName->getStr();
        }
    }
    miniv8::V8Script* script = new miniv8::V8Script();
    script->setSource(sourceStr->getStr());
    script->setSourceName(name);
    v8::Local<v8::Script> ret = v8::Utils::convert<miniv8::V8Script, v8::Script>(script);
    return ret;
}

v8::MaybeLocal<v8::Script> v8::ScriptCompiler::Compile(v8::Local<v8::Context> context, v8::ScriptCompiler::Source* source, v8::ScriptCompiler::CompileOptions)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* sourceStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(source->source_string));
    std::string name;

    if (!source->resource_name.IsEmpty() && source->resource_name->IsString()) {
        v8::MaybeLocal<v8::String> sourceName = source->resource_name->ToString(context);
        miniv8::V8String* sourceNameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(sourceName.ToLocalChecked()));
        name = sourceNameStr->getStr();
    }

    miniv8::V8Script* script = new miniv8::V8Script();
    script->setSource(sourceStr->getStr());
    script->setSourceName(name);
    v8::Local<v8::Script> ret = v8::Utils::convert<miniv8::V8Script, v8::Script>(script);
    return ret;
}

void readFile(const wchar_t* path, std::vector<char>* buffer)
{
    HANDLE hFile = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hFile) {
        DebugBreak();
    }

    DWORD fileSizeHigh;
    const DWORD bufferSize = ::GetFileSize(hFile, &fileSizeHigh);

    DWORD numberOfBytesRead = 0;
    buffer->resize(bufferSize);
    BOOL b = ::ReadFile(hFile, &buffer->at(0), bufferSize, &numberOfBytesRead, nullptr);
    ::CloseHandle(hFile);
    b = b;
}

static void removeShebang(std::string& str)
{
    if (str.length() >= 2 && str[0] == '#' && str[1] == '!') {
        size_t pos = str.find_first_of('\n');
        if (pos != std::string::npos) {
            str.erase(0, pos + 1);
        } else {
            str.clear();
        }
    }
}

static std::string getHookedSrc(const std::string& srcName, miniv8::V8String* sourceStr)
{
    //     std::vector<char> buffer;
    //     if (srcName == "node:net") {
    //         readFile(L"G:\\test\\nodejs_test\\nodejs\\lib\\net.js", &buffer);
    //         buffer.push_back(0);
    //         return buffer.data();
    //     } else if (srcName == "node:_http_server") {
    //         readFile(L"G:\\test\\nodejs_test\\nodejs\\lib\\_http_server.js", &buffer);
    //         buffer.push_back(0);
    //         return buffer.data();
    //     }
    std::string str = sourceStr->getStr();
    removeShebang(str);
    return str;
}

// 要考虑v8::ScriptCompiler::CreateCodeCacheForFunction会编译v8::Function
v8::MaybeLocal<v8::Function> v8::ScriptCompiler::CompileFunction(v8::Local<v8::Context> context, v8::ScriptCompiler::Source* source,
    size_t arguments_count /*= 0*/, v8::Local<v8::String> arguments[] /*= nullptr*/, size_t context_extension_count /*= 0*/,
    v8::Local<v8::Object> context_extensions[] /*= nullptr*/, v8::ScriptCompiler::CompileOptions options /*= kNoCompileOptions*/,
    v8::ScriptCompiler::NoCacheReason no_cache_reason /*= kNoCacheNoReason*/)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8String* sourceStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(source->source_string));
    miniv8::V8String* sourceName = nullptr;
    std::string srcName;
    if (source->resource_name->IsString()) {
        sourceName = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(source->resource_name.As<v8::String>()));
        srcName = sourceName->getStr();
    }
    if (srcName.empty()) {
        std::vector<char> filename(100);
        static int s_count = 0;
        sprintf(filename.data(), "CompileFunction_%x.js\n", s_count++);
        srcName = filename.data();
    }

    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8::Isolate::GetCurrent();

    JSValue ret = JS_NULL;
    {
        //不能调用miniv8::AutoEnterExitContext autoEnterExitContext(isolate, ctx);否则会回收local句柄

        if (v8::ScriptCompiler::kConsumeCodeCache == options) {
            if (source->cached_data && source->cached_data->length == sizeof(miniv8::V8Function)) {
                //ret = JS_ReadObject(ctx->ctx(), source->cached_data->data, source->cached_data->length, JS_READ_OBJ_BYTECODE);
                miniv8::V8Function* func = (miniv8::V8Function*)source->cached_data->data;
                ret = func->v(func);
                JS_DupValue(ctx->ctx(), ret);
            }
        } else { // 会到v8::Function::Call里执行
            std::string src = "(function(";
            for (size_t i = 0; i < arguments_count; ++i) {
                v8::Local<v8::String> arg = arguments[i];
                miniv8::V8String* argStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*arg);
                src += argStr->getStr();
                if (i != arguments_count - 1)
                    src += ", ";
            }
            src += ") {";
            src += getHookedSrc(srcName, sourceStr);
            src += ";\n })";
            //         src += "(";
            //
            //         // show: (function(a1, a2){})(__miniv8args__[0], __miniv8args__[1]);
            //         for (size_t i = 0; i < arguments_count; ++i) {
            //             src += kClosureArg;
            //             src += "[";
            //
            //             char c = '0';
            //             c += i;
            //             src += c;
            //             src += "]";
            //             if (i != arguments_count - 1)
            //                 src += ", ";
            //
            //         }
            //         src += ");";
            ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), srcName.c_str(), JS_EVAL_TYPE_GLOBAL /*| JS_EVAL_FLAG_COMPILE_ONLY*/);

            //         src = "(function (a){jsPrint('hahahaha---:' + a);})";
            // //         src = "((a)=>{jsPrint('hahahaha---' + a)})(__miniv8args__[0])";
            //         ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), srcName.c_str(), JS_EVAL_TYPE_GLOBAL | JS_EVAL_FLAG_COMPILE_ONLY);
            //         if (JS_IsException(ret))
            //             miniv8PrintWhenError(ctx->ctx());
            //
            //         JSValueConst argv = JS_NewInt32(ctx->ctx(), 123);
            //
            //         JSValue global = JS_GetGlobalObject(ctx->ctx());
            // //         JS_SetPropertyStr(ctx->ctx(), global, "__args__", argv);
            // //
            // //         //JSValue ret2 = JS_EvalFunction(ctx->ctx(), ret);
            //         JSValue ret2 = JS_EvalFunctionWithArgs(ctx->ctx(), ret, global, 1, &argv);
            //         //JSValue ret2 = JS_Call(ctx->ctx(), ret, JS_GetGlobalObject(ctx->ctx()), 1, &argv);
            // //
            // //         if (JS_IsException(ret2))
            // //             miniv8PrintWhenError(ctx->ctx());
        }
    }

    miniv8::V8Value* retVal = nullptr;
    if (JS_IsException(ret)) {
        miniv8PrintWhenError(ctx->ctx());
    } else
        retVal = miniv8::V8Value::create(ctx, ret);
    JS_FreeValue(ctx->ctx(), ret);

    if (!retVal || miniv8::kOTFunction != retVal->m_head.m_type)
        return v8::MaybeLocal<v8::Function>();

    miniv8::V8Function* v8func = (miniv8::V8Function*)retVal;
    v8func->setSrcUrl(srcName);
    return v8::Utils::convert<miniv8::V8Function, v8::Function>(v8func);
}

// 会到v8::Function::Call里执行
v8::ScriptCompiler::CachedData* v8::ScriptCompiler::CreateCodeCacheForFunction(v8::Local<v8::Function> v8func)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Function* func = v8::Utils::openHandle<v8::Function, miniv8::V8Function>(*v8func);
    if (!func)
        return nullptr;

    miniv8::V8Context* v8ctx = miniv8::V8Isolate::GetCurrent()->getEmptyCtx();

    JSValue obj = func->v(func);
    func->m_head.m_unGcType |= miniv8::V8Head::kIsCodeCacheField;
    JS_DupValue(v8ctx->ctx(), obj);

    //     size_t size = 0;
    //     uint8_t* buf = JS_WriteObject(ctx->ctx(), &size, obj, JS_WRITE_OBJ_BYTECODE);
    //     v8::ScriptCompiler::CachedData* cache = new v8::ScriptCompiler::CachedData((const uint8_t*)buf, size, v8::ScriptCompiler::CachedData::BufferNotOwned);

    // 直接用 miniv8::V8Function当成字节码缓存区了。懒得搞真正的字节码，因为js如果调用了字节码的JSValue，需要特殊处理才能调用，而且传参数还很麻烦
    v8::ScriptCompiler::CachedData* cache
        = new v8::ScriptCompiler::CachedData((const uint8_t*)func, sizeof(miniv8::V8Function), v8::ScriptCompiler::CachedData::BufferOwned);
    return cache;
}

v8::ScriptCompiler::CachedData::CachedData(unsigned char const* d, int len, v8::ScriptCompiler::CachedData::BufferPolicy buffer_pol)
    : data(d)
    , length(len)
    , rejected(false)
    , buffer_policy(buffer_pol)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::ScriptCompiler::CachedData::~CachedData(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* v8ctx = miniv8::V8Isolate::GetCurrent()->getEmptyCtx();
    if (length == sizeof(miniv8::V8Function) && v8::ScriptCompiler::CachedData::BufferNotOwned == buffer_policy) {
        miniv8::V8Function* func = (miniv8::V8Function*)data;
        JSValue val = func->v(func);
        JS_FreeValue(v8ctx->ctx(), val);
    }
}

v8::MaybeLocal<v8::Script> v8::ScriptCompiler::Compile(
    v8::Local<v8::Context>, v8::ScriptCompiler::StreamedSource*, v8::Local<v8::String>, v8::ScriptOrigin const&)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::MaybeLocal<v8::Script> ret;
    DebugBreak();
    return ret;
}

v8::Local<v8::Value> v8::Script::Run(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    v8::MaybeLocal<v8::Value> ret = Run(isolate->GetCurrentContext());
    if (ret.IsEmpty())
        return v8::Local<v8::Value>();
    return ret.ToLocalChecked();
}

v8::MaybeLocal<v8::UnboundScript> v8::ScriptCompiler::CompileUnboundScript(
    v8::Isolate* isolate, v8::ScriptCompiler::Source* source, v8::ScriptCompiler::CompileOptions)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8String* sourceStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(source->source_string));
    std::string name;

    if (!source->resource_name.IsEmpty() && source->resource_name->IsString()) {
        v8::MaybeLocal<v8::String> sourceName = source->resource_name->ToString(isolate->GetCurrentContext());
        miniv8::V8String* sourceNameStr = v8::Utils::openHandle<v8::String, miniv8::V8String>(*(sourceName.ToLocalChecked()));
        name = sourceNameStr->getStr();
    }

    miniv8::V8UnboundScript* script = new miniv8::V8UnboundScript();
    script->setSource(sourceStr->getStr());
    script->setSourceName(name);

    //     OutputDebugStringA("CompileUnboundScript:");
    //     OutputDebugStringA(name.c_str());
    //     OutputDebugStringA("\n");
    //
    //     if (std::string::npos != name.find("isLicensePlate.js"))
    //         OutputDebugStringA("");

    v8::Local<v8::UnboundScript> ret = v8::Utils::convert<miniv8::V8UnboundScript, v8::UnboundScript>(script);
    return ret;
}

v8::Local<v8::Script> v8::UnboundScript::BindToCurrentContext(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8UnboundScript* self = v8::Utils::openHandle<v8::UnboundScript, miniv8::V8UnboundScript>(this);

    miniv8::V8Script* script = new miniv8::V8Script();
    script->setSource(self->getSource());
    std::string name = self->getSourceName();
    script->setSourceName(name);

    //     OutputDebugStringA("BindToCurrentContext:");
    //     OutputDebugStringA(name.c_str());
    //     OutputDebugStringA("\n");
    //
    //     if (std::string::npos != name.find("isLicensePlate.js"))
    //         OutputDebugStringA("");

    v8::Local<v8::Script> ret = v8::Utils::convert<miniv8::V8Script, v8::Script>(script);
    return ret;
}

/// <param name="buffer"></param>

bool saveDumpFile(const wchar_t* url, const char* buffer, unsigned int size)
{
    HANDLE hFile = CreateFileW(url, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE != hFile) {
        DWORD dwSize = 0;
        WriteFile(hFile, buffer, size, &dwSize, NULL);
        CloseHandle(hFile);
        return TRUE;
    }
    DebugBreak();
    return FALSE;
}

v8::MaybeLocal<v8::Value> v8::Script::Run(v8::Local<v8::Context> context)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Script* self = v8::Utils::openHandle<v8::Script, miniv8::V8Script>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);

    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8::Isolate::GetCurrent();

    std::vector<char> buffer;

    if (sizeof(void*) == 4) {
        int dump = 0;
        g_stack_point = &dump;
    }
    // TODO: 返回值，可能是已经存在的dom之类的
    isolate->enterContext(ctx);

    JSValue ret;
    if ("b2222ootstrap_node.js" == self->getSourceName()) {
        //         readFile(L"G:\\mycode\\mb_temp\\node\\lib\\internal\\bootstrap_node.js", &buffer);
        //         buffer.push_back(0);
        //         ret = JS_Eval(ctx->ctx(), buffer.data(), buffer.size() - 1, self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
    } else if ("http://weolar22.com/node_insert.js" == self->getSourceName()) {
        //         readFile(L"G:\\test\\web_test\\test2\\dist\\2.js", &buffer);
        //         buffer.push_back(0);
        //         std::string src;
        //         src += buffer.data();
        //         ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
        //     } else if ("stream.js" == self->getSourceName()) {
        //         readFile(L"G:\\mycode\\mb_temp\\node\\lib\\stream.js", &buffer);
        //         buffer.push_back(0);
        //         std::string src = "(function (exports, require, module, __filename, __dirname) { 'use strict';\n";
        //         src += buffer.data();
        //         src += "});";
        //         ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
        //     } else if ("_stream_readable.js" == self->getSourceName()) {
        //         readFile(L"G:\\test\\temp\\_stream_readable.js", &buffer);
        //         buffer.push_back(0);
        //         ret = JS_Eval(ctx->ctx(), buffer.data(), buffer.size() - 1, self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
        //
        //     } else if ("_http_incoming.js" == self->getSourceName()) {
        //         readFile(L"G:\\mycode\\mb_temp\\node\\lib\\_http_incoming.js", &buffer);
        //         buffer.push_back(0);
        //         std::string src = "(function (exports, require, module, __filename, __dirname) { 'use strict';\n";
        //         src += buffer.data();
        //         src += "});";
        //         ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
        //     } else if ("_http_common.js" == self->getSourceName()) {
        //         readFile(L"G:\\mycode\\mb_temp\\node\\lib\\_http_common.js", &buffer);
        //         buffer.push_back(0);
        //         std::string src = "(function (exports, require, module, __filename, __dirname) { 'use strict';\n";
        //         src += buffer.data();
        //         src += "});";
        //         ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
        //    } else if ("buffer.js" == self->getSourceName()) {
        //         readFile(L"G:\\mycode\\mininode\\node-v8.2.1\\lib\\buffer.js", &buffer);
        //         buffer.push_back(0);
        //         std::string src = "(function (exports, require, module, __filename, __dirname) {";
        //         src += buffer.data();
        //         src += "});";
        //         ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
        //     } else if ("fs.js" == self->getSourceName()) {
        //         readFile(L"G:\\mycode\\mininode\\node-v8.2.1\\lib\\fs.js", &buffer);
        //         buffer.push_back(0);
        //         std::string src = "(function (exports, require, module, __filename, __dirname) {";
        //         src += buffer.data();
        //         src += "});";
        //         ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
        //     } else if ("internal/child_process.js" == self->getSourceName()) {
        //         readFile(L"G:\\mycode\\mb_temp\\node\\lib\\internal\\child_process.js", &buffer);
        //         buffer.push_back(0);
        //         std::string src = "(function (exports, require, module, __filename, __dirname) {";
        //         src += buffer.data();
        //         src += "});";
        //         ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
        //     } else if ("net.js" == self->getSourceName()) {
        //         readFile(L"G:\\test\\nodejs_test\\nodejs\\lib\\net.js", &buffer);
        //         buffer.push_back(0);
        //         std::string src = "(function (exports, require, module, __filename, __dirname) {";
        //         src += buffer.data();
        //         src += "});";
        //         ret = JS_Eval(ctx->ctx(), src.c_str(), src.size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);
    } else
        ret = JS_Eval(ctx->ctx(), self->getSource().c_str(), self->getSource().size(), self->getSourceName().c_str(), JS_EVAL_TYPE_GLOBAL);

    isolate->exitContext();

    if (JS_IsException(ret)) {
        miniv8PrintWhenError(ctx->ctx());
    }

    miniv8::V8Value* retVal = miniv8::V8Value::create(ctx, ret);
    JS_FreeValue(ctx->ctx(), ret);
    return v8::Utils::convert<miniv8::V8Value, v8::Value>(retVal);
}

v8::MaybeLocal<v8::Set> v8::Set::Add(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::MaybeLocal<v8::Set> ret;
    return ret;
}

v8::MaybeLocal<v8::String> v8::Message::GetSourceLine(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::MaybeLocal<v8::String> ret;
    return ret;
}

v8::MaybeLocal<v8::String> v8::Value::ToString(v8::Local<v8::Context> context) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::MaybeLocal<v8::String> ret;

    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    miniv8::V8Context* ctx = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    miniv8::V8String* str = nullptr;

    JSValue v = self->v(self);
    if (miniv8::kOTString == self->m_head.m_type) {
        miniv8::V8String* str = (miniv8::V8String*)self;
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    } else if (miniv8::kOTValue == self->m_head.m_type) {

    } else if (JS_IsString(v)) {
    }

    char strbuf[126 * 2] = { 0 };
    uint32_t tag = JS_VALUE_GET_TAG(v);

    if (JS_TAG_IS_FLOAT64(tag)) {
        double d = JS_VALUE_GET_FLOAT64(v);
        sprintf(strbuf, "%f", d);

        str = new miniv8::V8String(strbuf);
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    }

    switch (tag) {
    case JS_TAG_INT: {
        int32_t int32Val = JS_VALUE_GET_INT(v);
        sprintf(strbuf, "%d", int32Val);
        str = new miniv8::V8String(strbuf);
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    }
    case JS_TAG_BOOL: {
        int32_t int32Val = JS_VALUE_GET_INT(v);
        str = new miniv8::V8String(int32Val == 0 ? "false" : "true");
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    }
    case JS_TAG_NULL: {
        str = new miniv8::V8String("null");
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    }
    case JS_TAG_UNDEFINED: {
        str = new miniv8::V8String("undefined");
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    }
    case JS_TAG_OBJECT: {
        str = new miniv8::V8String("[Object]");
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    }
    case JS_TAG_STRING: {
        str = (miniv8::V8String*)miniv8::V8Value::create(ctx, v);
        return v8::Utils::convert<miniv8::V8String, v8::String>(str);
    }
    default: {
        DebugBreak();
    }
    }
    return ret;
}

v8::MaybeLocal<v8::Value> v8::Date::New(v8::Local<v8::Context>, double)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    v8::MaybeLocal<v8::Value> ret;
    return ret;
}

v8::MaybeLocal<v8::Value> v8::JSON::Parse(v8::Isolate* isolate, v8::Local<v8::String> str)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    JSContext* ctx = miniv8::V8Context::getCurrentJsCtx();
    miniv8::V8Context* context = miniv8::V8Context::getCurrentCtx();

    miniv8::V8String* json = v8::Utils::openHandle<v8::String, miniv8::V8String>(*str);
    const std::string& jsonStr = json->getStr();
    JSValue val = JS_ParseJSON(ctx, jsonStr.c_str(), jsonStr.size(), "<JsonParse>");

    miniv8::V8Value* ret = miniv8::V8Value::create(context, val);
    return v8::Utils::convert<miniv8::V8Value, v8::Value>(ret);
}

// v8::Platform* v8::platform::CreateDefaultPlatform(int)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
// }

v8::ResourceConstraints::ResourceConstraints(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::ScriptCompiler::ScriptStreamingTask* v8::ScriptCompiler::StartStreamingScript(
    v8::Isolate*, v8::ScriptCompiler::StreamedSource*, v8::ScriptCompiler::CompileOptions)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return nullptr;
}

v8::ScriptCompiler::StreamedSource::StreamedSource(v8::ScriptCompiler::ExternalSourceStream*, v8::ScriptCompiler::StreamedSource::Encoding)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::ScriptCompiler::StreamedSource::~StreamedSource(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::ScriptOrigin v8::Message::GetScriptOrigin(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    v8::Local<v8::String> resourceName = v8::String::NewFromUtf8(v8::Isolate::GetCurrent(), "v8::Message::GetScriptOrigin");
    return v8::ScriptOrigin(resourceName);
}
bool v8::ScriptCompiler::ExternalSourceStream::SetBookmark(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

void v8::ScriptCompiler::ExternalSourceStream::ResetToBookmark(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void* v8::External::Value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8External* self = v8::Utils::openHandle<v8::External, miniv8::V8External>(this);
    return self->getUserdata();
}

// void* v8::ScriptCompiler::CachedData::`scalar deleting destructor'(unsigned int)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
// }
//
// void* v8::ScriptCompiler::StreamedSource::`scalar deleting destructor'(unsigned int)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
// }
//
// void addAccessor(v8::Local<v8::Context>, char const*, __int64(__cdecl*)(struct JsExecStateInfo*, void*), void*, __int64(__cdecl*)(struct JsExecStateInfo*, void*), void*)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
// }

void v8::Context::AllowCodeGenerationFromStrings(bool)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::Local<v8::Object> v8::Context::Global(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
    if (self->m_isDetachGlobal) {
        DebugBreak(); // 按理来说调用DetachGlobal后不应该再调用本api Global了
        return v8::Local<v8::Object>();
    }

    JSValue val = JS_GetGlobalObject(self->ctx());
    miniv8::V8Object* ret = miniv8::V8Object::create(self, val);
    JS_FreeValue(self->ctx(), val); // JS_GetGlobalObject里面会增加引用计数

    return v8::Utils::convert<miniv8::V8Object, v8::Object>(ret);
}

void v8::Context::DetachGlobal(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
    miniv8ReleaseAssert(!self->m_isDetachGlobal, "m_isDetachGlobal call much\n");

    //     JSValue val = JS_GetGlobalObject(self->ctx());
    // //     miniv8::V8Object* global = miniv8::V8Object::create(self, val);
    // //     v8::Local<v8::Object> globalV8 = v8::Utils::convert<miniv8::V8Object, v8::Object>(global);
    // //     v8::V8::DisposeGlobal((v8::internal::Object **)(*globalV8));
    //     JS_FreeValue(self->ctx(), val);

    for (std::map<int, void*>::iterator it = self->m_embedderDatas.begin(); it != self->m_embedderDatas.end(); ++it) {
        miniv8::V8Value* val = (miniv8::V8Value*)(it->second);
        if (!val)
            continue;
        JS_FreeValue(self->ctx(), val->v(val));
    }

    JS_DetachGlobalObject(self->ctx());
    self->m_isDetachGlobal = true;
}

unsigned int v8::Context::GetNumberOfEmbedderDataFields(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
    return self->m_maxEmbedderDataIndex + 1;
}

void v8::Context::SetAlignedPointerInEmbedderData(int index, void* data)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);

    if (self->m_maxEmbedderDataIndex < index)
        self->m_maxEmbedderDataIndex = index;
    miniv8::stdMapInsert(&self->m_alignedPointerInEmbedderDatas, index, data);
}

void v8::Context::SetEmbedderData(int index, v8::Local<v8::Value> value)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8ReleaseAssert(!value.IsEmpty(), "");
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
    miniv8::V8Value* val = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*value);
    JSContext* ctx = self->ctx();

    JS_DupValue(ctx, val->v(val));
    val->m_head.m_unGcType |= miniv8::V8Head::kIsEmbedderData;

    if (self->m_maxEmbedderDataIndex < index)
        self->m_maxEmbedderDataIndex = index;

    std::map<int, void*>::iterator it = self->m_embedderDatas.find(index);
    if (it != self->m_embedderDatas.end()) {
        miniv8::V8Value* oldVal = (miniv8::V8Value*)(it->second);
        if (oldVal)
            JS_FreeValue(ctx, oldVal->v(oldVal));
    }
    miniv8::stdMapInsert(&self->m_embedderDatas, index, val);
}

v8::Local<v8::Value> v8::Context::SlowGetEmbedderData(int index)
{
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
    std::map<int, void*>::const_iterator it = self->m_embedderDatas.find(index);
    if (it == self->m_embedderDatas.end())
        return v8::Local<v8::Value>();
    miniv8::V8Value* val = (miniv8::V8Value*)(it->second);
    if (!val)
        return v8::Local<v8::Value>();

    v8::Local<v8::Value> ret = v8::Utils::convert<miniv8::V8Value, v8::Value>(val);
    return ret;
}

v8::Local<v8::Value> v8::Context::GetEmbedderData(int index)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return SlowGetEmbedderData(index);
}

void* v8::Context::SlowGetAlignedPointerFromEmbedderData(int index)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);

    std::map<int, void*>::const_iterator it = self->m_alignedPointerInEmbedderDatas.find(index);
    if (it == self->m_alignedPointerInEmbedderDatas.end())
        return nullptr;
    return it->second;
}

void* v8::Context::GetAlignedPointerFromEmbedderData(int index)
{
    return SlowGetAlignedPointerFromEmbedderData(index);
}

v8::Local<v8::Context> v8::Context::New(v8::Isolate* isolate, v8::ExtensionConfiguration*, v8::MaybeLocal<v8::ObjectTemplate> globalTemplate,
    v8::MaybeLocal<v8::Value> oldGlobal, DeserializeInternalFieldsCallback internal_fields_deserializer, MicrotaskQueue* microtask_queue)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    miniv8::V8Isolate* iso = (miniv8::V8Isolate*)isolate;
    JSContext* ctx = JS_NewContext(iso->getRuntime());
    miniv8::V8Context* ret = new miniv8::V8Context(iso, ctx);

    JSValue global = JS_GetGlobalObject(ctx);
    miniv8::V8Object* globalObj = miniv8::V8Object::create(ret, global);

    // blink会设置global的原型的原型，如果这里不设置一下，那么global的原型就是Object对象了
    // 这会导致innerGlobalObject->SetPrototype(context, windowWrapper)设置失败
    JSValue globalProto = JS_NewObject(ctx);
    JS_SetPrototype(ctx, global, globalProto);
    JS_FreeValue(ctx, globalProto);

    JS_SetPropertyStr(ctx, global, "jsPrint", JS_NewCFunction(ctx, jsPrint, "print", 0));
    JS_SetPropertyStr(ctx, global, "mbConsoleLog", JS_NewCFunction(ctx, jsPrint, "mbConsoleLog", 0));
    JS_SetPropertyStr(ctx, global, "jsTestNode", JS_NewCFunction(ctx, jsTestNode, "jsTestNode", 0));
    JS_SetPropertyStr(ctx, global, "jsPrintStack", JS_NewCFunction(ctx, jsPrintStack, "jsPrintStack", 0));

    miniv8::V8ObjectTemplate* globalTempl = v8::Utils::openHandle<v8::ObjectTemplate, miniv8::V8ObjectTemplate>(*(globalTemplate.ToLocalChecked()));
    if (globalTempl) {
        globalTempl->newTemplateInstance(globalObj, false);
        globalObj->setTemplId(globalTempl->getRegisterId());
    }
    // TODO: 没考虑m_instanceTemplate等情况
    JS_FreeValue(ctx, global);

    if (oldGlobal.IsEmpty())
        return v8::Utils::convert<miniv8::V8Context, v8::Context>(ret);

    // 按照v8的规范，要把老的global对象替换成新的。
    v8::Utils::resetPtr(oldGlobal.ToLocalChecked(), &globalObj->m_head);

    return v8::Utils::convert<miniv8::V8Context, v8::Context>(ret);
}

void v8::Context::Enter(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    isolate->enterContext(self);
}

void v8::Context::Exit(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    isolate->exitContext();
}

// void v8::Context::TestPrintCallStack()
// {
//     miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
//     JS_PrintStack(self->ctx());
// }

void v8::Context::SetErrorMessageForCodeGenerationFromStrings(v8::Local<v8::String>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Context::SetSecurityToken(v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Context::UseDefaultSecurityToken(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

// void v8::Eternal<v8::FunctionTemplate>::Set<v8::FunctionTemplate>(v8::Isolate*, v8::Local<v8::FunctionTemplate>)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
// }

void v8::HeapProfiler::ClearObjectIds(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

#if V8_MINOR_VERSION < 8
void v8::HeapProfiler::SetRetainedObjectInfo(v8::UniqueId, v8::RetainedObjectInfo*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}
#endif

void v8::HeapProfiler::SetWrapperClassInfoProvider(unsigned short, v8::RetainedObjectInfo*(__cdecl*)(unsigned short, v8::Local<v8::Value>))
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::HeapProfiler::StartTrackingHeapObjects(bool)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::HeapProfiler::StopTrackingHeapObjects(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::HeapSnapshot::Delete(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::HeapSnapshot::Serialize(v8::OutputStream*, v8::HeapSnapshot::SerializationFormat) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::AddCallCompletedCallback(void(__cdecl*)(void))
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::CancelTerminateExecution(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::EnqueueMicrotask(v8::MicrotaskCallback microtask, void* data)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;

    std::pair<void*, void*>* task = new std::pair<void*, void*>(microtask, data);
    isolate->m_microtasks.push_back(task);
}

void v8::Isolate::RunMicrotasks(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;
    isolate->runMicrotasks();
}

void v8::Isolate::LowMemoryNotification(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate::GetCurrent()->runGC();
}

void v8::Isolate::Dispose(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //     miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;
    //     if (isolate->m_isExiting)
    //         return;
    //     isolate->m_isExiting = true;
    //
    //     for (int i = 0; i < miniv8::V8Isolate::kSlotSize; ++i) {
    //         miniv8::V8Value* val = isolate->getEternalByIndex(i);
    //         if (!val)
    //             continue;
    //         val->m_head.m_unGcType &= ~(miniv8::V8Head::kIsEternal);
    //
    //         v8::Persistent<v8::Value>* valuePersistent = isolate->m_eternalsPersistents[i];
    //         valuePersistent->Reset();
    //         delete valuePersistent;
    //
    //         int index = isolate->getGlobalizeCountHandlesIndex(&val->m_head);
    //         int count = isolate->m_globalizeCountHandles[index];
    //         miniv8ReleaseAssert(0 == count, "");
    //         isolate->m_eternals[i] = nullptr; // 不需要再走trace了
    //     }
    //
    //     isolate->runGC();
    //     isolate->runGC();
}

void v8::Isolate::Enter(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::Exit(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //     // 此时m_emptyContext 已经被析构了
    //     miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;
    //     isolate->runGC();
    //     isolate->m_emptyContextPersistents.Reset();
    //     isolate->runGC();
    //     JS_FreeRuntime(isolate->m_runtime);
}

void v8::Isolate::PrintCallStack()
{
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    JSContext* ctx = isolate->getCurrentJsCtx();
    if (ctx)
        JS_PrintStack(ctx);
}

// int v8::internal::Internals::GetInstanceType(const v8::internal::Object* obj)
// {
// //     typedef internal::Object O;
// //     O* map = ReadField<O*>(obj, kHeapObjectMapOffset);
// //     // Map::InstanceType is defined so that it will always be loaded into
// //     // the LS 8 bits of one 16-bit word, regardless of endianess.
// //     return ReadField<uint16_t>(map, kMapInstanceTypeAndBitFieldOffset) & 0xff;
//     printEmptyFuncInfo(__FUNCTION__, false, false);
//     DebugBreak();
//     return 0;
// }

// int v8::internal::Internals::GetOddballKind(const v8::internal::Object* obj)
// {
// //     typedef internal::Object O;
// //     return SmiValue(ReadField<O*>(obj, kOddballKindOffset));
//     printEmptyFuncInfo(__FUNCTION__, false, false);
//     DebugBreak();
//     return 0;
// }

// bool v8::internal::Internals::IsExternalTwoByteString(int instance_type)
// {
//     int representation = (instance_type & kFullStringRepresentationMask);
//     return representation == kExternalTwoByteRepresentationTag;
// }

uint8_t v8::internal::Internals::GetNodeFlag(v8::internal::Object** obj, int shift)
{
    //     uint8_t* addr = reinterpret_cast<uint8_t*>(obj) + kNodeFlagsOffset;
    //     return *addr & static_cast<uint8_t>(1U << shift);
    printEmptyFuncInfo(__FUNCTION__, false, false);

    //miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::toHandle<miniv8::V8Data>((uintptr_t)obj);
    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)obj);
    //     uint8_t mask = static_cast<uint8_t>(1U << shift);
    //     return head->m_nodeFlag & mask;
    return head->getNodeFlag(shift);
}

void v8::internal::Internals::UpdateNodeFlag(v8::internal::Object** obj, bool value, int shift)
{
    //     uint8_t* addr = reinterpret_cast<uint8_t*>(obj) + kNodeFlagsOffset;
    //     uint8_t mask = static_cast<uint8_t>(1U << shift);
    //     *addr = static_cast<uint8_t>((*addr & ~mask) | (value << shift));
    printEmptyFuncInfo(__FUNCTION__, false, false);

    if (v8::internal::Internals::kNodeIsActiveShift == shift)
        OutputDebugStringA("");

    //miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::toHandle<miniv8::V8Data>((uintptr_t)obj);
    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)obj);
    uint8_t mask = static_cast<uint8_t>(1U << shift);
    head->m_nodeFlag |= static_cast<uint8_t>((head->m_nodeFlag & ~mask) | (value << shift));
}

uint8_t v8::internal::Internals::GetNodeState(v8::internal::Object** obj)
{
    //     uint8_t* addr = reinterpret_cast<uint8_t*>(obj) + kNodeFlagsOffset;
    //     return *addr & kNodeStateMask;
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::toHandle<miniv8::V8Data>((uintptr_t)obj);
    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)obj);
    return head->m_nodeState & kNodeStateMask;
}

void v8::internal::Internals::UpdateNodeState(v8::internal::Object** obj, uint8_t value)
{
    //     uint8_t* addr = reinterpret_cast<uint8_t*>(obj) + kNodeFlagsOffset;
    //     *addr = static_cast<uint8_t>((*addr & ~kNodeStateMask) | value);
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::toHandle<miniv8::V8Data>((uintptr_t)obj);
    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)obj);
    head->m_nodeState = static_cast<uint8_t>((head->m_nodeState & ~kNodeStateMask) | value);
}

// v8::Local<v8::Primitive> v8::Undefined(Isolate* isolate)
// {
//     typedef internal::Object* S;
//     typedef internal::Internals I;
//     I::CheckInitialized(isolate);
//     S* slot = I::GetRoot(isolate, I::kUndefinedValueRootIndex);
//     return Local<Primitive>(reinterpret_cast<Primitive*>(slot));
// }
//
// v8::Local<v8::Primitive> v8::Null(Isolate* isolate)
// {
//     typedef internal::Object* S;
//     typedef internal::Internals I;
//     I::CheckInitialized(isolate);
//     S* slot = I::GetRoot(isolate, I::kNullValueRootIndex);
//     return Local<Primitive>(reinterpret_cast<Primitive*>(slot));
// }
//
// v8::Local<v8::Boolean> v8::True(v8::Isolate* isolate)
// {
//     typedef internal::Object* S;
//     typedef internal::Internals I;
//     I::CheckInitialized(isolate);
//     S* slot = I::GetRoot(isolate, I::kTrueValueRootIndex);
//     return Local<Boolean>(reinterpret_cast<Boolean*>(slot));
// }
//
// v8::Local<v8::Boolean> v8::False(v8::Isolate* isolate)
// {
//     typedef internal::Object* S;
//     typedef internal::Internals I;
//     I::CheckInitialized(isolate);
//     S* slot = I::GetRoot(isolate, I::kFalseValueRootIndex);
//     return Local<Boolean>(reinterpret_cast<Boolean*>(slot));
// }

v8::Local<v8::String> v8::String::Empty(Isolate* isolate)
{
    typedef internal::Object* S;
    typedef internal::Internals I;
    I::CheckInitialized(isolate);
    S* slot = I::GetRoot(isolate, I::kEmptyStringRootIndex);
    return Local<String>(reinterpret_cast<String*>(slot));
}

bool v8::Value::IsAsyncFunction(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    return JS_IsAsyncFunction(miniv8::V8Context::getEmptyJsCtx(), self->v(self));
}

bool v8::Value::IsUndefined() const
{
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    if (!self)
        return true;
    JSValue v = self->v(self);
    return !!JS_IsUndefined(v);
}

// bool v8::Value::QuickIsUndefined() const
// {
//     DebugBreak();
//     return false;
// }

bool v8::Value::IsNull() const
{
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);
    JSValue v = miniv8::V8Data::V8Data_v(self);
    return JS_VALUE_IS_EQ(v, JS_NULL);
}

// bool v8::Value::QuickIsNull() const
// {
//     DebugBreak();
//     return false;
// }

bool v8::Value::IsString() const
{
    miniv8::V8Value* self = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(this);

    if (miniv8::kOTString == self->m_head.m_type)
        return true;
    JSValue v = self->v(self);
    return JS_IsString(v) != 0;
}

// bool v8::Value::QuickIsString() const
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
//     DebugBreak();
//     return false;
// }

bool v8::Value::FullIsNull(void) const
{
    DebugBreak();
    return false;
}

bool v8::Value::FullIsUndefined(void) const
{
    DebugBreak();
    return false;
}

#if V8_MINOR_VERSION >= 8
v8::MaybeLocal<v8::WasmCompiledModule> v8::ValueDeserializer::Delegate::GetWasmModuleFromId(v8::Isolate*, uint32_t)
{
    DebugBreak();
    return v8::MaybeLocal<v8::WasmCompiledModule>();
}

void v8::ArrayBuffer::Allocator::SetProtection(void* data, size_t length, v8::ArrayBuffer::Allocator::Protection protection)
{
    DebugBreak();
}

void v8::ArrayBuffer::Allocator::Free(void* data, size_t length, v8::ArrayBuffer::Allocator::AllocationMode mode)
{
    DebugBreak();
}

void* v8::ArrayBuffer::Allocator::Reserve(size_t length)
{
    DebugBreak();
    return nullptr;
}
#endif

v8::internal::MicrotaskQueue::MicrotaskQueue()
{
}

v8::internal::MicrotaskQueue::~MicrotaskQueue()
{
}

class MicrotaskFunctionWrap {
public:
    MicrotaskFunctionWrap(v8::Isolate* isolate, v8::Local<v8::Function> microtask)
    {
        m_isolate = isolate;
        m_microtask.Reset(isolate, microtask);
    }

    static void V8CALL microtaskFunctionCallback(void* data)
    {
        MicrotaskFunctionWrap* self = (MicrotaskFunctionWrap*)data;
        if (!(self->m_isolate->GetCurrentContext().IsEmpty()))
            self->m_microtask.Get(self->m_isolate)->Call(self->m_isolate->GetCurrentContext(), v8::Local<v8::Value>(), 0, nullptr);
        else
            DebugBreak();
        delete self;
    }

private:
    v8::Isolate* m_isolate;
    v8::Persistent<v8::Function> m_microtask;
};

void v8::internal::MicrotaskQueue::EnqueueMicrotask(v8::Isolate* isolate, v8::Local<v8::Function> microtask)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    isolate->EnqueueMicrotask(&MicrotaskFunctionWrap::microtaskFunctionCallback, new MicrotaskFunctionWrap(isolate, microtask));
}

void v8::internal::MicrotaskQueue::EnqueueMicrotask(v8::Isolate* isolate, v8::MicrotaskCallback microtask, void* data)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    isolate->EnqueueMicrotask(microtask, data);
}

void v8::internal::MicrotaskQueue::AddMicrotasksCompletedCallback(v8::MicrotasksCompletedCallbackWithData callback, void* data)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

void v8::internal::MicrotaskQueue::RemoveMicrotasksCompletedCallback(v8::MicrotasksCompletedCallbackWithData callback, void* data)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

void v8::internal::MicrotaskQueue::PerformCheckpoint(v8::Isolate* isolate)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    isolate->RunMicrotasks();
}

bool v8::internal::MicrotaskQueue::IsRunningMicrotasks() const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

int v8::internal::MicrotaskQueue::GetMicrotasksScopeDepth() const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return 0;
}

v8::MicrotaskQueue* v8::Context::GetMicrotaskQueue()
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Context* self = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(this);
    if (self->m_microtaskQueue)
        return self->m_microtaskQueue;

    self->m_microtaskQueue = new v8::internal::MicrotaskQueue();
    return self->m_microtaskQueue;
}

namespace v8 {

namespace base {

class SysInfo {
public:
    // Returns the number of logical processors/core on the current machine.
    static int NumberOfProcessors();

    // Returns the number of bytes of physical memory on the current machine.
    static int64_t AmountOfPhysicalMemory();

    // Returns the number of bytes of virtual memory of this process. A return
    // value of zero means that there is no limit on the available virtual memory.
    static int64_t AmountOfVirtualMemory();
};

int SysInfo::NumberOfProcessors()
{
    return 0;
}

int64_t SysInfo::AmountOfPhysicalMemory()
{
    return 0;
}

int64_t SysInfo::AmountOfVirtualMemory()
{
    return 0;
}

} // namespace base

bool g_patchForCreateDataProperty = false;
const int Function::kLineOffsetNotFound = 0;

v8::ValueSerializer::~ValueSerializer()
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}
v8::ValueSerializer::ValueSerializer(v8::Isolate*, v8::ValueSerializer::Delegate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

} // v8

class Miniv8Inspector : public v8_inspector::V8Inspector {
public:
    static std::unique_ptr<v8_inspector::V8Inspector> create(v8::Isolate*, v8_inspector::V8InspectorClient*)
    {
        std::unique_ptr<v8_inspector::V8Inspector> ret(new Miniv8Inspector());
        return std::move(ret);
    }
    virtual ~Miniv8Inspector()
    {
    }

    // Contexts instrumentation.
    virtual void contextCreated(const v8_inspector::V8ContextInfo&) override
    {
    }
    virtual void contextDestroyed(v8::Local<v8::Context>) override
    {
    }
    virtual void resetContextGroup(int contextGroupId) override
    {
    }

    // Various instrumentation.
#if V8_MINOR_VERSION < 8
    virtual void willExecuteScript(v8::Local<v8::Context>, int scriptId) override
    {
    }
    virtual void didExecuteScript(v8::Local<v8::Context>) override
    {
    }
#endif
    virtual void idleStarted() override
    {
    }
    virtual void idleFinished() override
    {
    }

    // Async stack traces instrumentation.
    virtual void asyncTaskScheduled(const v8_inspector::StringView& taskName, void* task, bool recurring) override
    {
    }
    virtual void asyncTaskCanceled(void* task) override
    {
    }
    virtual void asyncTaskStarted(void* task) override
    {
    }
    virtual void asyncTaskFinished(void* task) override
    {
    }
    virtual void allAsyncTasksCanceled() override
    {
    }

    // Exceptions instrumentation.
    virtual unsigned exceptionThrown(v8::Local<v8::Context>, const v8_inspector::StringView& message, v8::Local<v8::Value> exception,
        const v8_inspector::StringView& detailedMessage, const v8_inspector::StringView& url, unsigned lineNumber, unsigned columnNumber,
        std::unique_ptr<v8_inspector::V8StackTrace>, int scriptId) override
    {
        return 0;
    }
    virtual void exceptionRevoked(v8::Local<v8::Context>, unsigned exceptionId, const v8_inspector::StringView& message) override
    {
    }

    virtual std::unique_ptr<v8_inspector::V8InspectorSession> connect(
        int contextGroupId, v8_inspector::V8Inspector::Channel*, const v8_inspector::StringView& state) override
    {
        DebugBreak();
        return nullptr;
    }

    // API methods.
    virtual std::unique_ptr<v8_inspector::V8StackTrace> createStackTrace(v8::Local<v8::StackTrace>) override
    {
        DebugBreak();
        return nullptr;
    }
    virtual std::unique_ptr<v8_inspector::V8StackTrace> captureStackTrace(bool fullStack) override
    {
        DebugBreak();
        return nullptr;
    }
};

class Miniv8StringBuffer : public v8_inspector::StringBuffer {
public:
    Miniv8StringBuffer(const v8_inspector::StringView& str)
    {
        if (str.length() == 0) {
            m_str = new v8_inspector::StringView();
            return;
        }

        if (str.is8Bit()) {
            uint8_t* buf8 = (uint8_t*)malloc(str.length() + 1);
            memcpy(buf8, str.characters8(), str.length());
            buf8[str.length()] = 0;
            m_str = new v8_inspector::StringView(buf8, str.length());
        } else {
            uint16_t* buf16 = (uint16_t*)malloc((str.length() + 1) * sizeof(uint16_t));
            memcpy(buf16, str.characters16(), str.length() * sizeof(uint16_t));
            buf16[str.length()] = 0;
            m_str = new v8_inspector::StringView(buf16, str.length());
        }
    }

    ~Miniv8StringBuffer() override
    {
        free((void*)m_str->characters8());
        delete m_str;
    }

    const v8_inspector::StringView& string() override
    {
        return *m_str;
    }

    static std::unique_ptr<v8_inspector::StringBuffer> create(const v8_inspector::StringView& str)
    {
        std::unique_ptr<v8_inspector::StringBuffer> ret(new Miniv8StringBuffer(str));
        return std::move(ret);
    }

private:
    v8_inspector::StringView* m_str;
};

std::unique_ptr<v8_inspector::StringBuffer> v8_inspector::StringBuffer::create(const v8_inspector::StringView& str)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return Miniv8StringBuffer::create(str);
}

std::unique_ptr<v8_inspector::V8Inspector> v8_inspector::V8Inspector::create(v8::Isolate* isolate, v8_inspector::V8InspectorClient* client)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return Miniv8Inspector::create(isolate, client);
}

void v8::Isolate::SetJitCodeEventHandler(v8::JitCodeEventOptions, v8::JitCodeEventHandler)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::AddGCPrologueCallback(v8::Isolate::GCCallback callback, v8::GCType gc_type)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;
    isolate->addGCPrologueCallback(callback, gc_type);
}

void v8::Isolate::AddGCEpilogueCallback(v8::Isolate::GCCallback callback, v8::GCType gc_type)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;
    isolate->addGCEpilogueCallback(callback, gc_type);
}

void v8::Isolate::VisitHandlesWithClassIds(v8::PersistentHandleVisitor* visitor)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;
    isolate->visitHandlesWithClassIds(visitor);
}

void v8::V8::AddGCEpilogueCallback(v8::GCCallback callback, v8::GCType gc_type)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    isolate->addGCEpilogueCallback((v8::Isolate::GCCallback)callback, gc_type);
}

void v8::V8::AddGCPrologueCallback(v8::GCCallback callback, v8::GCType gc_type)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    isolate->addGCPrologueCallback((v8::Isolate::GCCallback)callback, gc_type);
}

void v8::Isolate::VisitWeakHandles(v8::PersistentHandleVisitor* visitor)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)this;
    isolate->visitHandlesWithClassIds(visitor); // 暂时也走visitHandlesWithClassIds，以后再想办法
}

void v8::internal::Internals::CheckInitializedImpl(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

namespace v8 {
namespace platform {
void SetTracingController(Platform*, platform::tracing::TracingController*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}
} // namespace platform
} // namespace v8
