
#define _CRT_SECURE_NO_WARNINGS 1

#include "MiniV8Api.h"
#include <windows.h>

// #pragma optimize("", off)
// #pragma clang optimize off

namespace miniv8 {

static JSValue onCFunctionCallback(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv, void* userdata);

JSValue getReturnVal(JSContext* ctx, void* cehckPtr, void** retVal)
{
    if (cehckPtr == *retVal)
        return JS_UNDEFINED; // TODO: 不知道这样判断行不行

    // 如果*retVal的低位是1，说明是SMI：https://v8.dev/blog/pointer-compression
    if (V8Object::IsSmi((void*)(*retVal)) /*&& v8::internal::Internals::IsValidSmi((intptr_t)(*retVal))*/) {
        int intV = v8::internal::Internals::SmiValue((const v8::internal::Object*)(*retVal));
        return JS_NewInt32(ctx, intV);
    }

    V8Value* ret = v8::Utils::openHandle<v8::Value, V8Value>((v8::Value*)(retVal));

    if (0xdddddddd == (UINT_PTR)ret->v)
        DebugBreak();

    JSValue v = ret->v(ret); // TODO:Free
    JS_DupValue(ctx, v); // TODO: 需要增加引用吗？
    return v;
}
}

namespace v8 {

void SetPersistentWrapperClassId(void* obj, uint8_t* addr, uint16_t class_id)
{
    //*reinterpret_cast<uint16_t*>(addr) = class_id;
    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)obj);
    head->m_wrapperClassId = class_id;
}

uint16_t GetPersistentWrapperClassId(void* obj, uint8_t* addr)
{
    //return *reinterpret_cast<uint16_t*>(addr);
    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>((v8::Value*)obj);
    return head->m_wrapperClassId;
}

namespace internal {

class FunctionCallbackArguments { // 为了能访问v8::FunctionCallbackInfo的私有变量，不得不借用FunctionCallbackArguments
public:
    static JSValue objectTemplateFuncGetter(JSContext* ctx, JSValueConst thisVal, void* userdata);
    static JSValue objectTemplateFuncSetter(JSContext* ctx, JSValueConst thisVal, JSValueConst val, void* userdata);
    static JSValue onConstructorCallback(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor);
    static JSValue onCFunctionCallback(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor);
    static void changeExternal(const v8::FunctionCallbackInfo<v8::Value>& info, void* data);

    static void createFunctionCallbackInfo(miniv8::V8Context* context, bool isConstructor, miniv8::V8Object* thisValV8, std::vector<void*>* argValue,
        void** implicitArgs, miniv8::V8Value* external, miniv8::FunctionCallbackInfoWrap* functionCallbackInfoWrap, int argc, JSValueConst* argv);

    void* stub;
};

void FunctionCallbackArguments::createFunctionCallbackInfo(miniv8::V8Context* context, bool isConstructor, miniv8::V8Object* thisValV8,
    std::vector<void*>* argValue, void** implicitArgs, miniv8::V8Value* external, miniv8::FunctionCallbackInfoWrap* functionCallbackInfoWrap, int argc,
    JSValueConst* argv)
{
    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    void* thisValPtr = v8::Utils::maskPtr(thisValV8);
    void* argValuePtr = argValue->data();
    v8::Local<v8::Object> thisValLocal = v8::Utils::convert<miniv8::V8Object, v8::Object>(thisValV8); // local引用，自动释放

    // if argc == 3, argValue[3] == this, argValue[2] = arg[0], argValue[1] = arg[1], argValue[0] = arg[2]
    // if argc == 1, argValue[1] == this, argValue[0] = arg[0]
    // if argc == 0, argValue[1] == this, argValue[0] == null
    argValue->resize(argc + 2);
    (*argValue)[0] = thisValPtr;
    (*argValue)[1] = thisValPtr;
    (*argValue)[argc] = thisValPtr; // 如果argc是0的话，v8会在FunctionCallbackInfo<T>::This()里取到这个地址

    for (int i = 0; i < argc; ++i) {
        miniv8::V8Value* v = miniv8::V8Value::create(context, argv[i]);
        (*argValue)[argc - i - 1] = v8::Utils::maskPtr(v);
    }

    void* returnValue[4] = { 0 };
    returnValue[1] = isolate;

    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kHolderIndex] = thisValPtr;
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kIsolateIndex] = isolate;
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueDefaultValueIndex] = nullptr;
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueIndex] = &returnValue; // &returnValue[2]; //kReturnValueIndex
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(external);
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kCalleeIndex] = thisValPtr;
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kContextSaveIndex] = thisValV8;

    //*I::GetRoot((v8::Isolate*)&m_apiPointer, I::kUndefinedValueRootIndex) = (v8::internal::Object*)v8::Utils::maskPtr(new miniv8::V8Value(nullptr, JS_UNDEFINED));
    v8::Local<v8::Primitive> v8Undefined = v8::Undefined((v8::Isolate*)isolate);
    if (isConstructor)
        implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kNewTargetIndex] = thisValPtr;
    else
        implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kNewTargetIndex] = *v8Undefined;

    functionCallbackInfoWrap->implicitArgs = implicitArgs;

    // values[1] == this, values[0] == arg[0], values[-1] == arg[1];
    int pos = argc - 1 > 0 ? argc - 1 : 0;
    functionCallbackInfoWrap->values = &((*argValue)[pos]);
    functionCallbackInfoWrap->length = argc;
}

JSValue FunctionCallbackArguments::objectTemplateFuncGetter(JSContext* ctx, JSValueConst thisVal, void* userdata)
{
    ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Context* v8ctx = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Template::Accessor* accessor = (miniv8::V8Template::Accessor*)userdata;
    miniv8::V8Isolate* v8isolate = (miniv8::V8Isolate*)(v8::Isolate::GetCurrent());
    miniv8::AutoEnterExitContext autoEnterExitContext(v8isolate, v8ctx);
    miniv8::V8Object* thisValV8 = nullptr;

    bool needFreeThisVal = false;
    if (JS_IsUndefined(thisVal)) {
        thisVal = JS_GetGlobalObject(ctx); // 直接调用alert，thisVal可能为undefined
        needFreeThisVal = true;
    }

    thisValV8 = miniv8::V8Object::create(v8ctx, thisVal);
    if (needFreeThisVal)
        JS_FreeValue(ctx, thisVal);

    std::vector<void*> argValue;
    void* implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    miniv8::V8External* external = new miniv8::V8External(accessor->data);
    miniv8::FunctionCallbackInfoWrap wrap;
    createFunctionCallbackInfo(v8ctx, false, thisValV8, &argValue, implicitArgs, external, &wrap, 0, nullptr);
    v8::Local<v8::External> externalv8 = v8::Utils::convert<miniv8::V8External, v8::External>(external); // 为了自动回收

    void** retVal = (void**)&implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;
    v8isolate->pushRetVal(retVal);

    v8::FunctionCallbackInfo<v8::Value>* wrapV8 = (v8::FunctionCallbackInfo<v8::Value>*)(&wrap);
    accessor->getterFunc(*wrapV8);
    v8isolate->popRetVal();

    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    return v;
}

JSValue FunctionCallbackArguments::objectTemplateFuncSetter(JSContext* ctx, JSValueConst thisVal, JSValueConst val, void* userdata)
{
    ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate* v8isolate = (miniv8::V8Isolate*)(v8::Isolate::GetCurrent());
    miniv8::AutoEnterExitContext autoEnterExitContext(v8isolate, context);
    miniv8::V8Template::Accessor* accessor = (miniv8::V8Template::Accessor*)userdata;
    miniv8::V8Object* thisValV8 = nullptr;

    bool needFreeThisVal = false;
    if (JS_IsUndefined(thisVal)) {
        thisVal = JS_GetGlobalObject(ctx); // 直接调用alert，thisVal可能为undefined
        needFreeThisVal = true;
    }

    thisValV8 = miniv8::V8Object::create(context, thisVal);

    std::vector<void*> argValue;
    void* implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    miniv8::V8External* external = new miniv8::V8External(accessor->data);
    v8::Local<v8::External> externalv8 = v8::Utils::convert<miniv8::V8External, v8::External>(external); // 为了自动回收
    miniv8::FunctionCallbackInfoWrap wrap;
    createFunctionCallbackInfo(context, false, thisValV8, &argValue, implicitArgs, external, &wrap, 1, &val);

    v8::FunctionCallbackInfo<v8::Value>* wrapV8 = (v8::FunctionCallbackInfo<v8::Value>*)(&wrap);
    accessor->setterFunc(*wrapV8);

    if (needFreeThisVal)
        JS_FreeValue(ctx, thisVal);

    return JS_UNDEFINED;
}

static JSValue onToStringOfFuncInst(JSContext* ctx, JSValueConst funcVal, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor)
{
    miniv8::V8Function* self = (miniv8::V8Function*)userdata;
    std::string name = "[object ";
    name += self->getName();
    name += "]";
    return JS_NewString(ctx, name.c_str());
}

void FunctionCallbackArguments::changeExternal(const v8::FunctionCallbackInfo<v8::Value>& info, void* external)
{
    miniv8::FunctionCallbackInfoWrap* wrap = (miniv8::FunctionCallbackInfoWrap*)&info;

    void** implicitArgs = (void**)wrap->implicitArgs;
    implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(external);
}

// 通常是构造函数，也可能是普通函数
// 如果是构造函数，则老quickjs是self->v(self) == funcVal，否则funcVal是JS_UNDEFINED（新版本增加is_constructor，不用这样判断了）
// 本函数有三种情况会被调用：1、构造函数。2、普通函数。3、成员函数
// funcVal在这三种情况下分别是1、function对象。2、JS_UNDEFINED。3、this指针
// 如果构造函数且self->v(self), funcVal不相等，那有一种可能：类似这样class Script extends ContextifyScript，funcVal是继承类
JSValue FunctionCallbackArguments::onConstructorCallback(
    JSContext* ctx, JSValueConst funcVal, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor)
{
    ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Function* self = (miniv8::V8Function*)userdata;
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate* v8isolate = (miniv8::V8Isolate*)(v8::Isolate::GetCurrent());
    miniv8::AutoEnterExitContext autoEnterExitContext(v8isolate, context);

    //miniv8ReleaseAssert(!!context, "onConstructorCallback fail\n");
    miniv8::V8Object* func = miniv8::V8Object::create(context, self->v(self)); // 这个应该是Function的指针

    if (!JS_VALUE_IS_EQ(self->v(self), funcVal) && is_constructor) {
        //         JS_IsFunction(ctx, funcVal);
        //         JS_IsFunction(ctx, self->v(self));
        //         JS_PrintStack(ctx);
        OutputDebugStringA("FunctionCallbackArguments, self->v(self) != funcVal\n");
    }

    //miniv8ReleaseAssert(JS_VALUE_IS_EQ(self->v(self), funcVal) || !is_constructor, "onConstructorCallback fail\n");

    if (0 == func->m_internalFieldCount)
        func->m_internalFieldCount = self->m_internalFieldCount;

    JSValue newInst;
    bool isConstructor = is_constructor; // !JS_VALUE_IS_EQ(funcVal, JS_UNDEFINED); // funcVal不是JS_UNDEFINED表示构造函数
    miniv8::V8Object* thisValV8 = nullptr;
    if (isConstructor) {
        JSValue proto = JS_GetPropertyStr(ctx, funcVal, "prototype");
        newInst = JS_NewObjectProto(ctx, proto); // 创建这个function的实例，并且手动设置原型链。不然quickjs不会设置原型链
        JS_FreeValue(ctx, proto);
    } else {
        newInst = funcVal;
        JS_DupValue(ctx, newInst);
    }
    if (0)
        JS_PrintStack(ctx);

    thisValV8 = miniv8::V8Object::create(context, newInst);
    //printDebug("FunctionCallbackArguments: isConstructor:%d, %I64u, %p\n", isConstructor, newInst, thisValV8);
    int newInstId = JS_GetObjId(newInst);
    JS_FreeValue(ctx, newInst);

    if (thisValV8->m_internalFieldCount == 0)
        thisValV8->m_internalFieldCount = func->m_internalFieldCount;
    //miniv8::V8Data dataV8(context, self->v(self));

    std::vector<void*> argValue;
    void* implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kArgsLength] = { 0 };

    Local<v8::Value> externalLocal = self->m_data.Get((v8::Isolate*)v8isolate);
    miniv8::V8Value* external = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*externalLocal);
    miniv8::FunctionCallbackInfoWrap wrap;
    createFunctionCallbackInfo(context, isConstructor, thisValV8, &argValue, implicitArgs, external, &wrap, argc, argv);

    v8::FunctionCallbackInfo<v8::Value>* wrapV8 = (v8::FunctionCallbackInfo<v8::Value>*)&wrap;
    void** retVal = (void**)&implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;

    v8isolate->clearErr(ctx);
    v8isolate->pushRetVal(retVal);
    self->m_callback(*wrapV8); // to V8FunctionTemplate::onCall
    if (0)
        JS_PrintStack(ctx);
    if (v8isolate->hasErr()) {
        v8isolate->popRetVal();
        return v8isolate->getErrAndClear();
    }

    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    v8isolate->popRetVal();

    // 如果是构造函数，返回值必须的newInst，表示返回构造出的新实例
    if (isConstructor) {
        JS_FreeValue(ctx, v);
        v = newInst;
        JS_DupValue(ctx, v);

        JSValue toStringFuncVal = JS_NewCFunction2(ctx, onToStringOfFuncInst, NULL, 0, JS_CFUNC_generic, 0, self);
        JSAtom toStringAtom = JS_NewAtom(ctx, "toString");
        JS_SetProperty(ctx, v, /*JS_ATOM_toString*/ toStringAtom, toStringFuncVal);

        //--
        thisValV8->setTemplId(self->getTemplId());
        thisValV8->m_internalFieldCount = self->m_internalFieldCount;

        miniv8::V8Template* templ = v8isolate->getTemplateById(self->getTemplId());
        if (templ && templ->getInstanceTemplate()) {
            templ->getInstanceTemplate()->newTemplateInstance(thisValV8, false);

            if (0 == thisValV8->m_internalFieldCount)
                thisValV8->m_internalFieldCount = templ->getInstanceTemplate()->getInternalFieldCount();
        }
    } else {
        //JS_DupValue(ctx, v); // TODO: 需要增加引用吗？
    }

    if (!JS_VALUE_IS_EQ(v, JS_UNDEFINED)) {
        miniv8::V8Value* retV = miniv8::V8Value::create(context, v);
        if (-1 == retV->getTemplId()) {
            retV->setTemplId(self->getTemplId());
        } else {
            //miniv8ReleaseAssert(retV->getTemplId() == self->getTemplId(), "onConstructorCallback fail\n");
            //             if (retV->getTemplId() != self->getTemplId())
            //                 OutputDebugStringA("onConstructorCallback fail\n");
        }
    }

    int count = JS_GetRefCount(ctx, v);
    return v;
}

} // internal

JSValue MacroAssembler::objectTemplateNameGetter(JSContext* ctx, JSValueConst thisVal, void* userdata)
{
    ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate* v8isolate = (miniv8::V8Isolate*)(v8::Isolate::GetCurrent());
    miniv8::AutoEnterExitContext autoEnterExitContext(v8isolate, context);
    miniv8::V8Template::Accessor* accessor = (miniv8::V8Template::Accessor*)userdata;

    miniv8::V8String* name = new miniv8::V8String(accessor->name);
    v8::Local<v8::String> propertyName = (v8::Utils::convert<miniv8::V8String, v8::String>(name));

    miniv8::V8Object* thisValue = miniv8::V8Object::create(context, thisVal);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    void* returnValue[4] = { 0 };
    returnValue[0] = isolate;

    miniv8::V8External* external = new miniv8::V8External(accessor->data);

    void* args[v8::PropertyCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    args[v8::PropertyCallbackInfo<v8::Value>::kShouldThrowOnErrorIndex] = nullptr;
    args[v8::PropertyCallbackInfo<v8::Value>::kHolderIndex] = v8::Utils::maskPtr(thisValue); // kHolderIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kIsolateIndex] = isolate; // kIsolateIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueDefaultValueIndex] = nullptr; // kReturnValueDefaultValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex] = nullptr; // &returnValue[2]; //kReturnValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(external); // kDataIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kThisIndex] = v8::Utils::maskPtr(thisValue); // kThisIndex

    MacroAssembler infoStub; // 搞个假的，其实只是为了地址占位
    infoStub.stub = args;
    v8::PropertyCallbackInfo<v8::Value>* info = (v8::PropertyCallbackInfo<v8::Value>*)&infoStub;

    void** retVal = &args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;

    v8isolate->pushRetVal(retVal);

    if (accessor->nameGetter)
        accessor->nameGetter(propertyName, *info);
    else
        accessor->getter(propertyName, *info);

    v8isolate->popRetVal();

    v8::Local<v8::External> externalv8 = v8::Utils::convert<miniv8::V8External, v8::External>(external); // 为了自动回收

    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    return v;
}

JSValue MacroAssembler::objectTemplateNameSetter(JSContext* ctx, JSValueConst thisVal, JSValueConst val, void* userdata)
{
    ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate* v8isolate = (miniv8::V8Isolate*)(v8::Isolate::GetCurrent());
    miniv8::AutoEnterExitContext autoEnterExitContext(v8isolate, context);
    miniv8::V8Template::Accessor* accessor = (miniv8::V8Template::Accessor*)userdata;

    miniv8::V8String* name = new miniv8::V8String(accessor->name);
    v8::Local<v8::String> propertyName = (v8::Utils::convert<miniv8::V8String, v8::String>(name));

    miniv8::V8Object* thisValue = miniv8::V8Object::create(context, thisVal);

    miniv8::V8Value* value = miniv8::V8Value::create(context, val); // TODO:
    v8::Local<v8::Value> valueV8 = (v8::Utils::convert<miniv8::V8Value, v8::Value>(value));

    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    void* returnValue[4] = { 0 };
    returnValue[0] = isolate;

    miniv8::V8External* external = new miniv8::V8External(accessor->data);

    void* args[v8::PropertyCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    args[v8::PropertyCallbackInfo<v8::Value>::kShouldThrowOnErrorIndex] = nullptr;
    args[v8::PropertyCallbackInfo<v8::Value>::kHolderIndex] = v8::Utils::maskPtr(thisValue); // kHolderIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kIsolateIndex] = isolate; // kIsolateIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueDefaultValueIndex] = nullptr; // kReturnValueDefaultValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex] = nullptr; // &returnValue[2]; //kReturnValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(external); // kDataIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kThisIndex] = v8::Utils::maskPtr(thisValue); // kThisIndex

    MacroAssembler infoStub; // 搞个假的，其实只是为了地址占位
    infoStub.stub = args;
    v8::PropertyCallbackInfo<void>* info = (v8::PropertyCallbackInfo<void>*)&infoStub;
    void** retVal = &args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;
    v8isolate->pushRetVal(retVal);

    if (accessor->nameSetter)
        accessor->nameSetter(propertyName, valueV8, *info);
    else
        accessor->setter(propertyName, valueV8, *info);
    v8isolate->popRetVal();

    v8::Local<v8::External> externalv8 = v8::Utils::convert<miniv8::V8External, v8::External>(external); // 为了自动回收
    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    return v;
}

int v8::MacroAssembler::onNamePropertyQuery(JSContext* ctx, JSValueConst thisVal, JSAtom prop, void* userdata)
{
    ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate* v8isolate = (miniv8::V8Isolate*)(v8::Isolate::GetCurrent());
    miniv8::AutoEnterExitContext autoEnterExitContext(v8isolate, context);
    v8::NamedPropertyHandlerConfiguration* cfg = (v8::NamedPropertyHandlerConfiguration*)userdata;
    miniv8::V8Object* thisValue = miniv8::V8Object::create(context, thisVal);
    miniv8::V8External* external = (miniv8::V8External*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*(cfg->data));
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    if (0)
        JS_PrintStack(ctx);

    const char* nameStr = JS_AtomToCString(ctx, prop);
    miniv8::V8String* name = new miniv8::V8String(std::string(nameStr));
    JS_FreeAtomCString(ctx, prop, nameStr);
    v8::Local<v8::String> nameV8 = v8::Utils::convert<miniv8::V8String, v8::String>(name);

    void* args[v8::PropertyCallbackInfo<v8::Integer>::kArgsLength] = { 0 };
    args[v8::PropertyCallbackInfo<v8::Integer>::kShouldThrowOnErrorIndex] = nullptr;
    args[v8::PropertyCallbackInfo<v8::Integer>::kHolderIndex] = v8::Utils::maskPtr(thisValue); // kHolderIndex
    args[v8::PropertyCallbackInfo<v8::Integer>::kIsolateIndex] = isolate; // kIsolateIndex
    args[v8::PropertyCallbackInfo<v8::Integer>::kReturnValueDefaultValueIndex] = nullptr; // kReturnValueDefaultValueIndex
    args[v8::PropertyCallbackInfo<v8::Integer>::kReturnValueIndex] = nullptr; // &returnValue[2]; //kReturnValueIndex
    args[v8::PropertyCallbackInfo<v8::Integer>::kDataIndex] = v8::Utils::maskPtr(external); // kDataIndex
    args[v8::PropertyCallbackInfo<v8::Integer>::kThisIndex] = v8::Utils::maskPtr(thisValue); // kThisIndex

    MacroAssembler infoStub; // 搞个假的，其实只是为了地址占位
    infoStub.stub = args;
    v8::PropertyCallbackInfo<v8::Integer>* info = (v8::PropertyCallbackInfo<v8::Integer>*)(&infoStub);
    void** retVal = &args[v8::PropertyCallbackInfo<v8::Integer>::kReturnValueIndex];
    *retVal = &retVal;

    cfg->query(nameV8, *info);
    if (&retVal == *retVal)
        return 0;

    if (miniv8::V8Object::IsSmi((void*)(*retVal)) && v8::internal::Internals::IsValidSmi((intptr_t)(*retVal))) {
        int intV = v8::internal::Internals::SmiValue((const v8::internal::Object*)(*retVal));
        if (0 == intV)
            return 1;
    }

    return -1;
}

JS_BOOL v8::MacroAssembler::onNamePropertySet(JSContext* ctx, JSValueConst thisVal, JSAtom prop, JSValueConst val, void* userdata)
{
    ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate* v8isolate = (miniv8::V8Isolate*)(v8::Isolate::GetCurrent());
    miniv8::AutoEnterExitContext autoEnterExitContext(v8isolate, context);
    v8::NamedPropertyHandlerConfiguration* cfg = (v8::NamedPropertyHandlerConfiguration*)userdata;
    miniv8::V8Object* thisValue = miniv8::V8Object::create(context, thisVal);
    miniv8::V8External* external = (miniv8::V8External*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*(cfg->data));
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    miniv8::V8Value* value = miniv8::V8Value::create(context, val);
    v8::Local<v8::Value> valueV8 = v8::Utils::convert<miniv8::V8Value, v8::Value>(value);

    if (0)
        JS_PrintStack(ctx);

    const char* nameStr = JS_AtomToCString(ctx, prop);
    miniv8::V8String* name = new miniv8::V8String(std::string(nameStr));
    JS_FreeAtomCString(ctx, prop, nameStr);
    v8::Local<v8::String> nameV8 = v8::Utils::convert<miniv8::V8String, v8::String>(name);

    void* args[v8::PropertyCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    args[v8::PropertyCallbackInfo<v8::Value>::kShouldThrowOnErrorIndex] = nullptr;
    args[v8::PropertyCallbackInfo<v8::Value>::kHolderIndex] = v8::Utils::maskPtr(thisValue); // kHolderIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kIsolateIndex] = isolate; // kIsolateIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueDefaultValueIndex] = nullptr; // kReturnValueDefaultValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex] = nullptr; // &returnValue[2]; //kReturnValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(external); // kDataIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kThisIndex] = v8::Utils::maskPtr(thisValue); // kThisIndex

    MacroAssembler infoStub; // 搞个假的，其实只是为了地址占位
    infoStub.stub = args;
    v8::PropertyCallbackInfo<v8::Value>* info = (v8::PropertyCallbackInfo<v8::Value>*)(&infoStub);
    void** retVal = &args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;

    cfg->setter(nameV8, valueV8, *info);

    JS_FreeValue(ctx, val); // val传进来的时候就dup了

    //     JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    //     JS_BOOL retBool = (JS_VALUE_IS_EQ(JS_UNDEFINED, v)) ? FALSE : TRUE;
    //     JS_FreeValue(ctx, v);
    //
    //     return retBool;
    return TRUE;
}

JSValue v8::MacroAssembler::onNamePropertyGet(JSContext* ctx, JSValueConst thisVal, JSAtom prop, void* userdata)
{
    ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate* v8isolate = (miniv8::V8Isolate*)(v8::Isolate::GetCurrent());
    miniv8::AutoEnterExitContext autoEnterExitContext(v8isolate, context);
    v8::NamedPropertyHandlerConfiguration* cfg = (v8::NamedPropertyHandlerConfiguration*)userdata;
    miniv8::V8Object* thisValue = miniv8::V8Object::create(context, thisVal);
    miniv8::V8External* external = (miniv8::V8External*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*(cfg->data));
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    if (0)
        JS_PrintStack(ctx);

    const char* nameStr = JS_AtomToCString(ctx, prop);
    miniv8::V8String* name = new miniv8::V8String(std::string(nameStr));
    JS_FreeAtomCString(ctx, prop, nameStr);
    v8::Local<v8::String> nameV8 = v8::Utils::convert<miniv8::V8String, v8::String>(name);

    void* args[v8::PropertyCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    args[v8::PropertyCallbackInfo<v8::Value>::kShouldThrowOnErrorIndex] = nullptr;
    args[v8::PropertyCallbackInfo<v8::Value>::kHolderIndex] = v8::Utils::maskPtr(thisValue); // kHolderIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kIsolateIndex] = isolate; // kIsolateIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueDefaultValueIndex] = nullptr; // kReturnValueDefaultValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex] = nullptr; // &returnValue[2]; //kReturnValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(external); // kDataIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kThisIndex] = v8::Utils::maskPtr(thisValue); // kThisIndex

    MacroAssembler infoStub; // 搞个假的，其实只是为了地址占位
    infoStub.stub = args;
    v8::PropertyCallbackInfo<v8::Value>* info = (v8::PropertyCallbackInfo<v8::Value>*)(&infoStub);
    void** retVal = &args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;
    v8isolate->pushRetVal(retVal);

    cfg->getter(nameV8, *info);
    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    v8isolate->popRetVal();

    return v;
}

JSValue v8::MacroAssembler::onIndexHandle(JSContext* ctx, JSValueConst thisVal, int32_t index, void* userdata)
{
    ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8::V8Isolate* v8isolate = (miniv8::V8Isolate*)(v8::Isolate::GetCurrent());
    miniv8::AutoEnterExitContext autoEnterExitContext(v8isolate, context);
    v8::IndexedPropertyHandlerConfiguration* cfg = (v8::IndexedPropertyHandlerConfiguration*)userdata;
    miniv8::V8Object* thisValue = miniv8::V8Object::create(context, thisVal);
    miniv8::V8External* external = (miniv8::V8External*)v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*(cfg->data));
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    void* args[v8::PropertyCallbackInfo<v8::Integer>::kArgsLength] = { 0 };
    args[v8::PropertyCallbackInfo<v8::Integer>::kShouldThrowOnErrorIndex] = nullptr;
    args[v8::PropertyCallbackInfo<v8::Integer>::kHolderIndex] = v8::Utils::maskPtr(thisValue); // kHolderIndex
    args[v8::PropertyCallbackInfo<v8::Integer>::kIsolateIndex] = isolate; // kIsolateIndex
    args[v8::PropertyCallbackInfo<v8::Integer>::kReturnValueDefaultValueIndex] = nullptr; // kReturnValueDefaultValueIndex
    args[v8::PropertyCallbackInfo<v8::Integer>::kReturnValueIndex] = nullptr; // &returnValue[2]; //kReturnValueIndex
    args[v8::PropertyCallbackInfo<v8::Integer>::kDataIndex] = v8::Utils::maskPtr(external); // kDataIndex
    args[v8::PropertyCallbackInfo<v8::Integer>::kThisIndex] = v8::Utils::maskPtr(thisValue); // kThisIndex

    MacroAssembler infoStub; // 搞个假的，其实只是为了地址占位
    infoStub.stub = args;
    v8::PropertyCallbackInfo<v8::Value>* info = (v8::PropertyCallbackInfo<v8::Value>*)(&infoStub);
    void** retVal = &args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;
    v8isolate->pushRetVal(retVal);

    cfg->getter(index, *info);

    v8isolate->popRetVal();
    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    return v;
}

JSValue v8::MacroAssembler::wrapGetter(JSContext* ctx, JSValueConst thisVal, void* userdata)
{
    miniv8::V8Object* self = (miniv8::V8Object*)JS_GetUserdata(thisVal);
    intptr_t hashVal = (intptr_t)userdata;
    miniv8::V8Context* contextOfSelf = self->v8Ctx();
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);

    std::map<intptr_t, miniv8::V8Object::AccessorData*>::iterator it = self->m_accessorMap.find(hashVal);
    miniv8ReleaseAssert(it != self->m_accessorMap.end(), "wrapGetter fail\n");

    miniv8::V8Object::AccessorData* accessor = it->second;

    miniv8::V8String* prop = new miniv8::V8String(accessor->name);
    v8::Local<v8::String> propV8 = v8::Utils::convert<miniv8::V8String, v8::String>(prop);

    JSRuntime* runtime = JS_GetRuntime(ctx);
    miniv8::V8Isolate* v8isolate = miniv8::V8Isolate::GetCurrent();

    miniv8ReleaseAssert(contextOfSelf == context, "wrapGetter fail\n");
    miniv8::V8Object* thisValV8 = miniv8::V8Object::create(context, thisVal); // TODO: free

    //miniv8::V8Data dataV8(context, thisVal);

    void* returnValue[4] = { 0 };
    returnValue[1] = v8isolate;

    void* args[v8::PropertyCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    args[v8::PropertyCallbackInfo<v8::Value>::kHolderIndex] = v8::Utils::maskPtr(thisValV8); // kHolderIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kIsolateIndex] = v8isolate; // kIsolateIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex] = nullptr; // &returnValue[3]; // kReturnValueIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kDataIndex] = v8::Utils::maskPtr(thisValV8); // &dataV8; // kDataIndex
    args[v8::PropertyCallbackInfo<v8::Value>::kThisIndex] = v8::Utils::maskPtr(thisValV8); // kThisIndex

    //     PropertyCallbackInfoStub propertyCallbackInfoStub;
    //     propertyCallbackInfoStub.m_obj = info;
    //     v8::PropertyCallbackInfo<v8::Value>* infoV8 = (v8::PropertyCallbackInfo<v8::Value>*)(&propertyCallbackInfoStub);

    MacroAssembler infoStub; // 搞个假的，其实只是为了地址占位
    infoStub.stub = args;
    v8::PropertyCallbackInfo<v8::Value>* infoV8 = (v8::PropertyCallbackInfo<v8::Value>*)(&infoStub);

    void** retVal = &args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;
    v8isolate->pushRetVal(retVal);

    if (accessor->getter)
        accessor->getter(propV8, *infoV8);
    else if (accessor->nameGetter)
        accessor->nameGetter(propV8, *infoV8);

    v8isolate->popRetVal();
    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    return v;
}

JSValue v8::MacroAssembler::wrapSetter(JSContext* ctx, JSValueConst thisVal, JSValueConst val, void* userdata)
{
    //typedef void (V8CALL* AccessorSetterCallback)(Local<String> property, Local<Value> value, const PropertyCallbackInfo<void>& info)
    miniv8::V8Object* self = (miniv8::V8Object*)JS_GetUserdata(thisVal);
    intptr_t hashVal = (intptr_t)userdata;

    std::map<intptr_t, miniv8::V8Object::AccessorData*>::iterator it = self->m_accessorMap.find(hashVal);
    miniv8ReleaseAssert(it != self->m_accessorMap.end(), "wrapSetter fail\n");

    miniv8::V8Object::AccessorData* accessor = it->second;

    miniv8::V8String* prop = new miniv8::V8String(accessor->name);
    v8::Local<v8::String> propV8 = v8::Utils::convert<miniv8::V8String, v8::String>(prop);

    miniv8::V8Isolate* isolate = miniv8::V8Isolate::GetCurrent();
    miniv8::V8Context* contextOfSelf = self->v8Ctx();
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    miniv8ReleaseAssert(contextOfSelf == context, "wrapSetter fail\n");

    miniv8::V8Value* value = miniv8::V8Value::create(context, val); // !!
    v8::Local<v8::Value> valueV8 = v8::Utils::convert<miniv8::V8Value, v8::Value>(value);

    miniv8::V8Object* thisValV8 = miniv8::V8Object::create(context, thisVal);

    void* returnValue[4] = { 0 };
    returnValue[1] = &isolate;

    void* args[v8::PropertyCallbackInfo<void>::kArgsLength] = { 0 };
    args[v8::PropertyCallbackInfo<void>::kHolderIndex] = v8::Utils::maskPtr(thisValV8); // kHolderIndex
    args[v8::PropertyCallbackInfo<void>::kIsolateIndex] = isolate; // kIsolateIndex
    args[v8::PropertyCallbackInfo<void>::kReturnValueIndex] = nullptr; // &returnValue[3]; // kReturnValueIndex
    args[v8::PropertyCallbackInfo<void>::kDataIndex] = v8::Utils::maskPtr(thisValV8); // &dataV8; // kDataIndex
    args[v8::PropertyCallbackInfo<void>::kThisIndex] = v8::Utils::maskPtr(thisValV8); // kThisIndex

    //     PropertyCallbackInfoStub propertyCallbackInfoStub;
    //     propertyCallbackInfoStub.m_obj = info;
    //     v8::PropertyCallbackInfo<void>* infoV8 = (v8::PropertyCallbackInfo<void>*)(&propertyCallbackInfoStub);

    MacroAssembler infoStub; // 搞个假的，其实只是为了地址占位
    infoStub.stub = args;
    v8::PropertyCallbackInfo<void>* infoV8 = (v8::PropertyCallbackInfo<void>*)(&infoStub);

    void** retVal = &args[v8::PropertyCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;

    if (accessor->setter)
        accessor->setter(propV8, valueV8, *infoV8);
    else if (accessor->nameSetter)
        accessor->nameSetter(propV8, valueV8, *infoV8);

    return JS_UNDEFINED;
}

} // v8

namespace miniv8 {

static inline uint16_t byteswap_ushort(uint16_t number)
{
#if defined(_MSC_VER) && _MSC_VER > 1310
    return _byteswap_ushort(number);
#elif defined(__GNUC__)
    return __builtin_bswap16(number);
#else
    return (number >> 8) | (number << 8);
#endif
}

// 根据首字节,获取utf8字符所占字节数
inline int getUtf8charByteNum(unsigned char ch)
{
    int byteNum = 0;

    if (ch >= 0xFC && ch < 0xFE)
        byteNum = 6;
    else if (ch >= 0xF8)
        byteNum = 5;
    else if (ch >= 0xF0)
        byteNum = 4;
    else if (ch >= 0xE0)
        byteNum = 3;
    else if (ch >= 0xC0)
        byteNum = 2;
    else if (0 == (ch & 0x80))
        byteNum = 1;

    return byteNum;
}

//计算utf8字符串字符个数
size_t getUtf8Length(const char* str, size_t clen)
{
    size_t len = 0;
    int byteNum = 0;
    unsigned char ch;
    const char* ptr = str;

    if (NULL == str)
        return 0;

    if (0 == clen)
        clen = strlen(str);

    while (*ptr != '\0' && len < clen) {
        ch = (unsigned char)*ptr;
        if (0 == (byteNum = getUtf8charByteNum(ch)))
            return len;
        ptr += byteNum;
        len++;
    }

    return len;
}

uint32_t hash(const char* arKey, size_t nKeyLength)
{
    uint32_t h = 0, g;
    const char* arEnd = arKey + nKeyLength;

    while (arKey < arEnd) {
        h = (h << 4) + *arKey++;
        if ((g = (h & 0xF0000000))) {
            h = h ^ (g >> 24);
            h = h ^ g;
        }
    }
    return h;
}

TlsIndexType V8Isolate::m_inst = 0;

struct QjsMallocHead {
    int32_t magic;
    int32_t size; // 不包含head的size
};

int s_mallocSize = 0;

static void* qjsMalloc(JSMallocState* s, size_t size)
{
    s->malloc_size += size;
    s_mallocSize = s->malloc_size;
    return malloc(size);
    //     v8::ArrayBuffer::Allocator* array_buffer_allocator = (v8::ArrayBuffer::Allocator*)s->opaque;
    //     QjsMallocHead* head = (QjsMallocHead*)array_buffer_allocator->AllocateUninitialized(size + sizeof(QjsMallocHead));
    //     head->size = (int32_t)size;
    //     head->magic = 'abcd';
    //
    //     s->malloc_size += size;
    //     return head + 1;
}

static void qjsFree(JSMallocState* s, void* ptr)
{
    size_t size = 0;
    if (ptr)
        size = _msize(ptr);
    s->malloc_size -= size;
    s_mallocSize = s->malloc_size;
    free(ptr);
    //     if (!ptr)
    //         return;
    //     v8::ArrayBuffer::Allocator* array_buffer_allocator = (v8::ArrayBuffer::Allocator*)s->opaque;
    //     QjsMallocHead* head = (QjsMallocHead*)ptr;
    //     head--;
    //
    //     if ('abcd' != head->magic)
    //         DebugBreak();
    //
    //     s->malloc_size -= head->size;
    //     array_buffer_allocator->Free(head, head->size + sizeof(QjsMallocHead));
}

static void* qjsRealloc(JSMallocState* s, void* ptr, size_t size)
{
    size_t sizeOld = 0;
    if (ptr)
        sizeOld = _msize(ptr);
    s->malloc_size += size - sizeOld;
    s_mallocSize = s->malloc_size;

    return realloc(ptr, size);
    //     if (!ptr)
    //         return qjsMalloc(s, size);
    //
    //     if (0 == size) {
    //         qjsFree(s, ptr);
    //         return nullptr;
    //     }
    //
    //     v8::ArrayBuffer::Allocator* array_buffer_allocator = (v8::ArrayBuffer::Allocator*)s->opaque;
    //     QjsMallocHead* oldHead = (QjsMallocHead*)ptr;
    //     oldHead--;
    //     int oldSize = oldHead->size;
    //     if ('abcd' != oldHead->magic)
    //         DebugBreak();
    //     if (oldSize >= size)
    //         return ptr;
    //
    //     QjsMallocHead* newHead = (QjsMallocHead*)array_buffer_allocator->AllocateUninitialized(size + sizeof(QjsMallocHead));
    //     newHead->size = (int32_t)size;
    //     newHead->magic = 'abcd';
    //
    //     void* newPtr = newHead + 1;
    //     memcpy(newPtr, ptr, oldSize);
    //     array_buffer_allocator->Free(oldHead, oldSize + sizeof(QjsMallocHead));
    //
    //     s->malloc_size -= oldSize;
    //     s->malloc_size += size;
    //
    //     return newPtr;
}

static void* qjsMallocArrayBuffer(JSMallocState* s, size_t size)
{
    v8::ArrayBuffer::Allocator* array_buffer_allocator = (v8::ArrayBuffer::Allocator*)s->opaque;
    void* ptr = array_buffer_allocator->AllocateUninitialized(size);
    return ptr;
}

static void qjsFreeArrayBuffer(JSMallocState* s, void* ptr)
{
    v8::ArrayBuffer::Allocator* array_buffer_allocator = (v8::ArrayBuffer::Allocator*)s->opaque;
    array_buffer_allocator->Free(ptr, 0);
}

static size_t qjsMallocUsableSize(const void* ptr)
{
    return 0;
}

V8Isolate::V8Isolate()
{
}

void V8Isolate::init(const v8::Isolate::CreateParams& params)
{
    m_v8CreateParams = params;
    JSMallocFunctions jsMallocFunc = { qjsMalloc, qjsFree, qjsRealloc, qjsMallocUsableSize, qjsMallocArrayBuffer, qjsFreeArrayBuffer };
    m_runtime = JS_NewRuntime2(&jsMallocFunc, params.array_buffer_allocator);
#if INTPTR_MAX >= INT64_MAX
    JS_SetMaxStackSize(m_runtime, (256 * 1024 * 40));
#else
    JS_SetMaxStackSize(m_runtime, (256 * 1024 * 4));
#endif
    if (0 != m_inst) {
        void* inst = TlsGetValue(m_inst);
        miniv8ReleaseAssert(!inst, "V8Isolate::V8Isolate, m_inst has be set!\n");
    } else
        m_inst = TlsAlloc();
    TlsSetValue(m_inst, this);

    m_gcStep = kGcStepEnd;
    m_gcObjects = nullptr;
    m_errorVal = JS_NULL;
    m_isExiting = false;
    m_gcPrologueCallback = nullptr;
    m_gcEpilogueCallback = nullptr;
    m_promises = nullptr;
    m_globalHandleIndex = 0;
    m_scopeHandleIndex = 0;
    m_callReentryCount = 0;
    m_lastGcMilliseconds = 0;
    m_globalizeHandles.resize(kHandlesSize);
    m_globalizeCountHandles.resize(kHandlesSize);
    m_scopeHandles.resize(kHandlesSize);
    memset(m_globalizeHandles.data(), 0, sizeof(void*) * m_globalizeHandles.size());
    memset(m_globalizeCountHandles.data(), 0, sizeof(int32_t) * m_globalizeHandles.size());
    memset(m_scopeHandles.data(), 0, sizeof(void*) * m_scopeHandles.size());
    memset(m_apiPointer, 0, sizeof(void*) * kSlotSize);
    memset(m_eternals, 0, sizeof(void*) * kSlotSize);
    memset(m_eternalsPersistents, 0, sizeof(v8::Persistent<v8::Value>*) * kSlotSize);

    JSContext* emptyCtx = JS_NewContext(m_runtime);
    JS_SetIsEmptyContext(emptyCtx);
    m_emptyContext = new miniv8::V8Context(this, emptyCtx);

    typedef v8::internal::Internals I;
    *I::GetRoot((v8::Isolate*)&m_apiPointer, I::kNullValueRootIndex) = (v8::internal::Object*)v8::Utils::maskPtr(new miniv8::V8Value(nullptr, JS_NULL));
    *I::GetRoot((v8::Isolate*)&m_apiPointer, I::kTrueValueRootIndex) = (v8::internal::Object*)v8::Utils::maskPtr(new miniv8::V8Value(nullptr, JS_TRUE));
    *I::GetRoot((v8::Isolate*)&m_apiPointer, I::kFalseValueRootIndex) = (v8::internal::Object*)v8::Utils::maskPtr(new miniv8::V8Value(nullptr, JS_FALSE));
    *I::GetRoot((v8::Isolate*)&m_apiPointer, I::kUndefinedValueRootIndex)
        = (v8::internal::Object*)v8::Utils::maskPtr(new miniv8::V8Value(nullptr, JS_UNDEFINED));
    *I::GetRoot((v8::Isolate*)&m_apiPointer, I::kEmptyStringRootIndex) = (v8::internal::Object*)v8::Utils::maskPtr(new miniv8::V8String(""));

    for (int i = 0; i < kSlotSize; ++i) {
        V8Head* head = (V8Head*)m_apiPointer[i];
        if (!head)
            continue;
        head = v8::Utils::toHandle<V8Head>((uintptr_t)head);
        head->m_unGcType |= V8Head::kIsRootIndex;
    }

    m_emptyContextPersistents.Reset((v8::Isolate*)this, v8::Utils::convert<miniv8::V8Context, v8::Context>(m_emptyContext));
    printDebug("V8Isolate::init: %p\n", this);
}

V8Isolate* V8Isolate::GetCurrent()
{
    return (V8Isolate*)TlsGetValue(m_inst);
}

void V8Isolate::pushRetVal(void** retVal)
{
    m_retVals.push_back(retVal);
}

void V8Isolate::popRetVal()
{
    m_retVals.pop_back();
}

void V8Isolate::clearErr(JSContext* ctx)
{
    if (!JS_VALUE_IS_EQ(JS_NULL, m_errorVal))
        JS_FreeValue(nullptr, m_errorVal);
    m_errorVal = JS_NULL;
}

bool V8Isolate::hasErr() const
{
    return !JS_VALUE_IS_EQ(JS_NULL, m_errorVal);
}

JSValue V8Isolate::getErrAndClear()
{
    return m_errorVal;
}

V8Head* g_testHead = nullptr;

V8Head::V8Head()
{
    m_type = kOTMin;
    m_next = nullptr;
    m_prev = nullptr;
    m_isolatHandleScopeIndex = nullptr;
    m_isolatGlobalScopeIndex = nullptr;
    m_isolatHandleScopeIndexHadClear = false;
    m_objectGroupId = 0;
    m_qjsValue = JS_NULL;
    m_weakCallback = nullptr;
    m_weakCallbackParam = nullptr;
    m_wrapperClassId = 0;
    m_nodeFlag = 0;
    m_nodeState = 0;
    m_refOrDeref = nullptr;
    m_tracer = &V8Head::onTrace;
    m_unGcType = 0;
    m_markGC = 0;
    m_isInMember = 0;
    //m_isWeak = 0;
    m_hasCallWeakCallback = 0;

    V8Isolate* isolate = V8Isolate::GetCurrent();
    if (isolate->m_gcObjects) {
        isolate->m_gcObjects->m_next = this;
        m_prev = isolate->m_gcObjects;
    }
    isolate->m_gcObjects = this;

    static int s_count = 0;
    s_count++;
    //printDebug("V8Head: %p, %d\n", this, s_count);
    m_countId = s_count;
    //
    //     if (17 == m_countId) // global对象
    //         OutputDebugStringA("");
    //
    //     if (1894 == m_countId) // docment对象
    //         OutputDebugStringA("");
    //
    //     if (1135 == m_countId) // global的prototype对象
    //         OutputDebugStringA("");
    //
    //     if (160842 == m_countId) //
    //         OutputDebugStringA("");
    //
    //     if (111488 == m_countId) //
    //         OutputDebugStringA("");
}

// 检查GC的时候，是不是被释放的对象还在m_tempScopeHandles里
bool V8Isolate::checkGcTempScopeHandles(V8Head* head)
{
    for (size_t j = 0; j < m_tempScopeHandles.size(); ++j) {
        std::vector<void**>* handles = m_tempScopeHandles[j];

        for (size_t i = 0; i < handles->size(); ++i) {
            void** ptr = (void**)handles->at(i);
            if (head->m_isolatHandleScopeIndex == ptr)
                return true;
        }
    }
    return false;
}

V8Head::~V8Head()
{
    //printDebug("~~~V8Head: %p, %d, %I64u\n", this, m_countId, m_qjsValue);

    //     if (632 == m_countId)
    //         OutputDebugStringA("");

    V8Isolate* isolate = V8Isolate::GetCurrent();
    isolate->onHeadDelete(this);

    if (isolate->m_gcObjects == this)
        isolate->m_gcObjects = m_prev;

    if (m_prev)
        m_prev->m_next = m_next;

    if (m_next)
        m_next->m_prev = m_prev;

    if (m_isolatHandleScopeIndex) {
        miniv8ReleaseAssert(!isolate->checkGcTempScopeHandles(this), "");
        printDebug("~V8Head: %p\n", m_isolatHandleScopeIndex);
        *m_isolatHandleScopeIndex = nullptr;
    }

    if (m_isolatGlobalScopeIndex)
        *m_isolatGlobalScopeIndex = nullptr;
}

void V8Head::onTrace(void* tracer, V8Head* self)
{
    self->m_markGC = 1;

    if (0 != self->m_objectGroupId)
        V8Isolate::GetCurrent()->addActivedObjectGroupId(self->m_objectGroupId);
}

void V8Head::onTraceHelper(void* tracer, V8Head* self)
{
    if (self->m_markGC)
        return;

    if (self->m_type <= kOTMin || self->m_type >= kOTMax)
        DebugBreak();

    // printDebug("onTraceHelper: %p, %p\n", self, self->m_tracer);

    if (self->m_tracer)
        self->m_tracer(tracer, self);
    onTrace(tracer, self);
}

static void testHandleEmptyIndex(std::vector<void*>* handles)
{
    std::vector<V8Head*> heads;
    for (size_t i = 0; i < handles->size(); ++i) {
        void** ptr = (void**)(handles->at(i));
        V8Value* head = v8::Utils::toHandle<V8Value>((uintptr_t)ptr);
        heads.push_back((V8Head*)head);
    }
    OutputDebugStringA("");
}

static void** findHandleEmptyIndex(int* handleIndex, std::vector<void*>* handles)
{
    void** ret = nullptr;

    size_t count = 0;
    for (size_t i = *handleIndex;; ++i, ++count) {
        //         if (count == 20000)
        //             OutputDebugStringA("");
        //         if (i == 60000)
        //             OutputDebugStringA("");

        if (count == handles->size()) {
            testHandleEmptyIndex(handles);
            DebugBreak();
            break;
        }

        if (i >= handles->size()) {
            i = 0;
        }

        if (nullptr == handles->at(i)) {
            ret = (void**)(handles->data() + i);
            *handleIndex = i + 1;
            break;
        }
    }
    return ret;
}

void** V8Isolate::findGlobalizeHandleEmptyIndex()
{
    return findHandleEmptyIndex(&m_globalHandleIndex, &m_globalizeHandles);
}

void V8Isolate::refGlobalizeHandleIndex(intptr_t idx)
{
    int index = (idx - (intptr_t)m_globalizeHandles.data()) / (sizeof(void*));
    ++m_globalizeCountHandles[index];
}

void** V8Isolate::findHandleScopeEmptyIndex()
{
    void** ret = findHandleEmptyIndex(&m_scopeHandleIndex, &m_scopeHandles);

    for (size_t j = 0; j < m_tempScopeHandles.size(); ++j) {
        std::vector<void**>* handles = m_tempScopeHandles[j];
        for (size_t i = 0; i < handles->size(); ++i) {
            void** ptr = (void**)handles->at(i);
            if (ret == ptr) { // 找一下有没重复申请了的
                DebugBreak();
                return ret;
            }
        }
    }

    if (m_tempScopeHandles.size() > 0) { // 第一次调用可能是空的
        std::vector<void**>* handles = m_tempScopeHandles[m_tempScopeHandles.size() - 1];
        handles->push_back(ret);
    }

    return ret;
}

void V8Isolate::enterContext(V8Context* ctx)
{
    //     static int s_count = 0;
    //     if (230 == s_count)
    //         OutputDebugStringA("");
    //     if (231 == s_count)
    //         OutputDebugStringA("");
    //     printDebug("enterContext:%p, %d\n", ctx, s_count);
    //     s_count++;

    m_currentCtxs.push_back(ctx);
}

void V8Isolate::exitContext()
{
    m_currentCtxs.pop_back();
    gcTempScopeHandles();
}

void V8Isolate::enterHandleScope()
{
    std::vector<void**>* handles = new std::vector<void**>();
    m_tempScopeHandles.push_back(handles);
}

extern void* g_testFunc;

void V8Isolate::exitHandleScope()
{
    std::vector<void**>* handles = m_tempScopeHandles[m_tempScopeHandles.size() - 1];
    void** retVal = nullptr;
    if (!m_retVals.empty()) {
        retVal = m_retVals[m_retVals.size() - 1];
    }

    V8Value* ret = nullptr;
    if (retVal && !V8Object::IsSmi((void*)(*retVal)))
        ret = v8::Utils::openHandle<v8::Value, V8Value>((v8::Value*)(retVal));

    for (size_t i = 0; i < handles->size(); ++i) {
        void** ptr = (void**)handles->at(i);
        //         if (!(*ptr)) // GC的时候，有可能被释放的对象还在m_tempScopeHandles里，这会导致*ptr为null
        //             continue;

        miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::toHandle<miniv8::V8Data>((uintptr_t)(*ptr));
        if (g_testFunc == head)
            OutputDebugStringA("");

        miniv8ReleaseAssert(miniv8::V8Head::isValide(head), "V8Head is not valide\n");

        uint8_t unGcType = head->m_unGcType;
        if (unGcType & miniv8::V8Head::kIsEscapeHandleScope) {
            head->m_unGcType &= ~miniv8::V8Head::kIsEscapeHandleScope;
            if (m_tempScopeHandles.size() >= 2) { // escape handle需要放到上一层去管理，不然就内存泄露了
                std::vector<void**>* lastHandles = m_tempScopeHandles[m_tempScopeHandles.size() - 2];
                lastHandles->push_back(ptr);
            }
            continue;
        }

        if ((void**)ret == (void**)head)
            continue;

        // TODO: !!!!!!!
        if (head->m_type != miniv8::V8ObjectType::kOTContext)
            gcHandleScopeHandleItem(head, nullptr);
    }
    m_tempScopeHandles.pop_back();
    delete handles;
}

void V8Isolate::escapeHandleScope(void** obj)
{
    if (!obj)
        return;
    miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::toHandle<miniv8::V8Data>((uintptr_t)(*obj));
    miniv8ReleaseAssert(miniv8::V8Head::isValide(head), "V8Head is not valide\n");
    head->m_unGcType |= miniv8::V8Head::kIsEscapeHandleScope;
}

// void V8Context::enterContext(V8Isolate* isolate)
// {
//     std::vector<void**>* handles = new std::vector<void**>();
//     m_tempScopeHandles.push_back(handles);
//     isolate->enterContext(this);
// }
//
// void V8Context::exitContext(V8Isolate* isolate)
// {
//     isolate->exitContext();
//     std::vector<void**>* handles = m_tempScopeHandles[m_tempScopeHandles.size() - 1];
//
//     for (size_t i = 0; i < handles->size(); ++i) {
//         void** ptr = (void**)handles->at(i);
//         miniv8::V8Head* head = (miniv8::V8Head*)v8::Utils::toHandle<miniv8::V8Data>((uintptr_t)(*ptr));
//         miniv8ReleaseAssert(miniv8::V8Head::isValide(head), "V8Head is not valide\n");
//
//         if (head->m_type != miniv8::V8ObjectType::kOTContext)
//             isolate->gcHandleScopeHandleItem(head, nullptr);
//     }
//     delete handles;
//
//     m_tempScopeHandles.pop_back();
// }
//
// void V8Context::registerHandleScope(void** head)
// {
//     miniv8ReleaseAssert(m_tempScopeHandles.size() != 0, "");
//     std::vector<void**>* handles = m_tempScopeHandles[m_tempScopeHandles.size() - 1];
//     handles->push_back(head);
// }

void V8Isolate::gcTempScopeHandles()
{
    //     if (!m_currentCtxs.empty())
    //         return;
    //
    //     for (size_t i = 0; i < m_tempScopeHandles.size(); ++i) {
    //         void** ptr = (void**)m_tempScopeHandles[i];
    //         V8Head* head = (V8Head*)v8::Utils::toHandle<V8Data>((uintptr_t)(*ptr));
    //         miniv8ReleaseAssert(V8Head::isValide(head), "V8Head is not valide\n");
    //
    //         if (head->m_type != V8ObjectType::kOTContext)
    //             gcHandleScopeHandleItem(head, nullptr);
    //     }
    //     m_tempScopeHandles.clear();
}

static void runJobPendingCb(JSContext* ctx, BOOL is_pre_call, void* cb_data)
{
    V8Isolate* isolate = (V8Isolate*)cb_data;
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    is_pre_call ? isolate->enterContext(context) : isolate->exitContext();
}

void V8Isolate::runMicrotasks()
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    if (m_isExiting)
        return;

    miniv8::V8Isolate::AutoCallReentry autoCallReentry(this);

    gcHandleScopeHandles(false);

    for (size_t i = 0; i < m_microtasks.size(); ++i) {
        std::pair<void*, void*>* task = m_microtasks[i];
        v8::MicrotaskCallback microtask = (v8::MicrotaskCallback)task->first;
        microtask(task->second);
        delete task;
    }
    m_microtasks.clear();

    JSContext* pctx = nullptr;
    for (int ret = 1; ret != 0;) {
        ret = JS_ExecutePendingJob(m_runtime, &pctx, runJobPendingCb, this);
    }
    //     if (m_currentCtxs.empty())
    //         runGC(); // TODO: 临时设置个gc，以后去掉，因为影响性能
}

void V8Isolate::addGCPrologueCallback(v8::Isolate::GCCallback callback, v8::GCType gc_type)
{
    m_gcPrologueCallback = callback;
}

void V8Isolate::addGCEpilogueCallback(v8::Isolate::GCCallback callback, v8::GCType gc_type)
{
    m_gcEpilogueCallback = callback;
}

V8Context* V8Isolate::getCurrentCtx() const
{
    if (isInContext())
        return m_currentCtxs[m_currentCtxs.size() - 1];

    return nullptr;
}

JSContext* V8Isolate::getCurrentJsCtx() const
{
    V8Context* context = getCurrentCtx();
    if (!context)
        return nullptr;
    return context->ctx();
}

miniv8::V8Context* V8Isolate::getEmptyCtx() const
{
    return m_emptyContext;
}

V8Isolate::~V8Isolate()
{
}

size_t V8Isolate::registerTemplate(V8Template* t)
{
    m_templates.push_back(t);
    return m_templates.size() - 1;
}

V8Template* V8Isolate::getTemplateById(size_t id)
{
    return id >= m_templates.size() ? 0 : m_templates[id];
}

bool V8Isolate::isInContext() const
{
    return m_currentCtxs.size() > 0;
}

//
V8Value::V8Value(V8Context* ctx, JSValue value)
    : V8Data(ctx, value)
{
    m_head.m_type = kOTValue;

    //     static int s_count = 1;
    //     printDebug("V8Value~: %p, %I64u, %d\n", this, value, s_count);
    //
    //     if (1403 == s_count)
    //         OutputDebugStringA("");
    //     s_count++;
}

V8Value* V8Value::create(V8Context* context, JSValue value)
{
    V8Object* old = (V8Object*)JS_GetUserdata(value);
    JSContext* ctx = V8Context::getCtx(context);

    if (old) {
        old->m_ctx = context;
        return old;
    }

    V8Value* ret = nullptr;
    // add ref 是在哪里做？
    if (JS_IsString(value)) {
        ret = new V8String(context, value);
    } else if (JS_IsFunction(ctx, value) || JS_IsBytecodeFunction(ctx, value)) {
        ret = new V8Function(context, value);
    } else if (JS_IsArray(ctx, value)) {
        ret = new V8Array(context, value);
    } else if (JS_IsMap(value)) {
        ret = new V8Map(context, value);
    } else if (JS_IsArrayBuffer(value)) {
        ret = V8ArrayBuffer::create(context, value);
    } else if (JS_IsWhatTypedArray(value, JS_INT16_TYPED_ARRAY)) {
        ret = V8Int16Array::create(context, value);
    } else if (JS_IsWhatTypedArray(value, JS_UINT16_TYPED_ARRAY)) {
        ret = V8Uint16Array::create(context, value);
    } else if (JS_IsWhatTypedArray(value, JS_UINT32_TYPED_ARRAY)) {
        ret = V8Uint32Array::create(context, value);
    } else if (JS_IsWhatTypedArray(value, JS_INT32_TYPED_ARRAY)) {
        ret = V8Int32Array::create(context, value);
    } else if (JS_IsWhatTypedArray(value, JS_INT8_TYPED_ARRAY)) {
        ret = V8Int8Array::create(context, value);
    } else if (JS_IsWhatTypedArray(value, JS_UINT8_TYPED_ARRAY)) {
        ret = V8Uint8Array::create(context, value);
    } else if (JS_IsWhatTypedArray(value, JS_UINT8C_TYPED_ARRAY)) {
        ret = V8Uint8ClampedArray::create(context, value);
    } else if (JS_IsWhatTypedArray(value, JS_FLOAT32_TYPED_ARRAY)) {
        ret = V8Float32Array::create(context, value);
    } else if (JS_IsWhatTypedArray(value, JS_FLOAT64_TYPED_ARRAY)) {
        ret = V8Float64Array::create(context, value);
    } else if (JS_IsPromise(value)) {
        ret = V8Promise::getOrCreate(context, value); // TODO: 以后再做从quickjs里取出的值转成v8promise
    } else if (JS_IsObject(value)) {
        ret = V8Object::create(context, value);
    } else { // TODO: num等其他类型
        ret = new V8Value(context, value);
        JS_SetUserdata(context->ctx(), value, &V8Data::onJsUserDataWeakFuncOfV8Data, ret);
    }

    //JS_DupValue(ctx, value);
    v8::Local<v8::Value> retv8 = v8::Utils::convert<miniv8::V8Value, v8::Value>(ret); // 调用一下，这样可以自动内存回收
    int count = JS_GetRefCount(ctx, value);
    return ret;
}

V8Data::~V8Data()
{
}

static int s_tracerCount = 1;

struct GcTracer {
    int m_count;

    GcTracer()
    {
        m_count = s_tracerCount++;
    }
};

static void onMarkUserdataFunc(JSRuntime* rt, JSGCObjectHeader* gp, void* tracer)
{
    GcTracer* tracerPtr = (GcTracer*)tracer;
    if ((void*)0xfffffffe == tracerPtr || (void*)0xffffffff == tracerPtr)
        DebugBreak();

    if (JS_GetTraceCountValue(rt, gp) == tracerPtr->m_count)
        return;
    JS_MarkTraceCountValue(rt, gp, tracerPtr->m_count);

    V8Head* head = (V8Head*)JS_GetUserdataByGCObjectHeader(gp);
    if (!head) {
        JS_MarkUserdataObjByGP(rt, gp, onMarkUserdataFunc, tracer);
        return;
    }
    V8Head::onTraceHelper(tracer, head);
}

void V8Data::onJsUserDataWeakFuncOfV8Data(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step)
{
    V8Data* self = (V8Data*)userdata;
    delete self;
}

void V8Data::onV8HeadTraceOfV8Data(void* tracer, V8Head* ptr)
{
    V8Data* self = (V8Data*)ptr;
    V8Head::onTrace(tracer, &self->m_head);
    //V8Head::onTraceHelper(tracer, &self->m_head);

    JSRuntime* rt = V8Isolate::GetCurrent()->getRuntime();
    JS_MarkUserdataObj(rt, self->m_head.m_qjsValue, onMarkUserdataFunc, tracer);
}

V8Object* V8Object::create(V8Context* ctx, JSValue value)
{
    return createFromType(ctx, value, kOTObject);
}

V8Object* V8Object::createFromType(V8Context* ctx, JSValue value, V8ObjectType type)
{
    V8Object* old = (V8Object*)JS_GetUserdata(value);
    if (old)
        return old;

    V8Object* ret = nullptr;
    // TODO:JS_IsUndefined\JS_IsNull

    if (type == kOTArrayBuffer)
        ret = new V8ArrayBuffer(ctx, value);
    else if (type == kOTArrayBufferView)
        ret = new V8ArrayBufferView(ctx, value);

    else if (type == kOTInt16Array)
        ret = new V8Int16Array(ctx, value);
    else if (type == kOTUint16Array)
        ret = new V8Uint16Array(ctx, value);
    else if (type == kOTUint32Array)
        ret = new V8Uint32Array(ctx, value);
    else if (type == kOTInt32Array)
        ret = new V8Int32Array(ctx, value);
    else if (type == kOTInt8Array)
        ret = new V8Int8Array(ctx, value);
    else if (type == kOTUint8Array)
        ret = new V8Uint8Array(ctx, value);
    else if (type == kOTUint8CArray)
        ret = new V8Uint8ClampedArray(ctx, value);
    else if (type == kOTFloat32Array)
        ret = new V8Float32Array(ctx, value);
    else if (type == kOTFloat64Array)
        ret = new V8Float64Array(ctx, value);

    else if (type == kOTResolver) {
        //ret = new V8Resolver(ctx, value);
        DebugBreak();
    } else if (type == kOTPromise) {
        //ret = new V8Promise(ctx, value);
        DebugBreak();
    } else if (type == kOTObject)
        ret = new V8Object(ctx, value);
    else
        DebugBreak();

    int ref = JS_GetRefCount(ctx->ctx(), value);
    v8::Local<v8::Object> retv8 = v8::Utils::convert<miniv8::V8Object, v8::Object>(ret); // 调用一下，这样可以自动内存回收
    return ret;
}

V8Object* V8Object::createFromClone(V8Context* context, JSValue oldV)
{
    JSValue newV = JS_CloneValue(context->ctx(), oldV);
    //JS_DupValue(context->ctx(), newV);

    V8Object* old = (V8Object*)JS_GetUserdata(newV);
    //miniv8ReleaseAssert(old, "V8Object::createFromClone fail\n");

    // TODO:JS_IsUndefined\JS_IsNull
    V8Object* ret = new V8Object(context, newV);
    //JS_DupValue(context->ctx(), newV);

    JS_SetUserdataFromClone(newV, &V8Object::onJsUserDataWeakFuncOfV8Object, ret);
    JS_SetTestValFromClone(newV, newV);

    JS_FreeValue(context->ctx(), newV);

    v8::Local<v8::Object> retv8 = v8::Utils::convert<miniv8::V8Object, v8::Object>(ret); // 调用一下，这样可以自动内存回收
    return ret;
}

V8Object::V8Object(V8Context* ctx, JSValue value)
    : V8Value(ctx, value)
{
    m_head.m_type = kOTObject;
    m_head.m_refOrDeref = V8Object::onV8HeadRefOrDerefOfV8Object;
    m_head.m_refOrDerefCopy = m_head.m_refOrDeref;
    m_head.m_tracer = V8Object::onV8HeadTraceOfV8Object;

    m_props = nullptr;
    isObject = true;
    m_internalFieldCount = 0;
    m_hadBindInstanceTemplate = false;

    static int s_count = 0;
    InterlockedIncrement((LONG volatile*)&s_count);

    //printDebug("V8Object: %p, %d, %I64u\n", this, s_count, value);
    V8Object* old = (V8Object*)JS_GetUserdata(value);
    miniv8ReleaseAssert(!old, "V8Object::V8Object: old user data is not empty\n");

    //m_internalFieldCount = 2; // 不能直接搞成2，因为isHostObject需要判断
    memset(m_alignedPointerInInternalFields, 0, sizeof(void*) * V8Object::kMaxaAlignedPointerArraySize);
    memset(m_internalFields, 0, sizeof(void*) * V8Object::kMaxaAlignedPointerArraySize);

    JS_SetUserdata(nullptr, value, &V8Object::onJsUserDataWeakFuncOfV8Object, this);
    //JS_SetTestVal(value, value);
}

V8Object::~V8Object()
{
    // TODO: 释放的时候要JS_GetUserdata
    if (m_props)
        delete m_props;

    for (size_t i = 0; i < kMaxaAlignedPointerArraySize; ++i) {
        V8Value* val = m_internalFields[i];
        if (val) {
            val->m_head.m_isInMember &= ~miniv8::V8Head::kIsSetInternalField;
            val->m_head.m_unGcType &= ~miniv8::V8Head::kIsSetInternalField;
        }
    }
    //printDebug("~~V8Object: %p, %d, %I64u\n", this, m_head.m_countId, m_head.m_qjsValue);
}

void V8Object::onJsUserDataWeakFuncOfV8Object(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step)
{
    V8Object* self = (V8Object*)userdata;
    delete self; // TODO: !!!!!!!
}

void V8Object::onV8HeadRefOrDerefOfV8Object(V8Head* head, bool ref)
{
    V8Object* self = (V8Object*)head;
    if (ref) {
        JSValue v = self->v(self);
        JS_DupValue(nullptr, v);
        return;
    }
    if (JS_VALUE_IS_EQ(self->m_head.m_qjsValue, JS_NULL)) {
        delete self;
        return;
    }

    //     if (self->m_head.m_countId > 110000) {
    //         char* output = (char*)malloc(0x100);
    //         sprintf_s(output, 0x99, "V8Object::onV8HeadRefOrDerefOfV8Object: %d\n", self->m_head.m_countId);
    //         OutputDebugStringA(output);
    //         free(output);
    //     }

    JSRuntime* rt = V8Isolate::GetCurrent()->getRuntime();
    JS_FreeValueRT(rt, self->m_head.m_qjsValue); // 这里面有回调，会析构V8Data
    //printDebug("onV8HeadRefOrDerefOfV8Object %p\n", head);
}

void V8Object::onV8HeadTraceOfV8Object(void* tracer, V8Head* ptr)
{
    V8Object* self = (V8Object*)ptr;
    V8Data::onV8HeadTraceOfV8Data(tracer, ptr);

    for (size_t i = 0; i < kMaxaAlignedPointerArraySize; ++i) {
        V8Value* val = self->m_internalFields[i];
        if (val)
            V8Head::onTraceHelper(tracer, &(val->m_head));
    }

    std::map<intptr_t, miniv8::V8Object::AccessorData*>::iterator it = self->m_accessorMap.begin();
    for (; it != self->m_accessorMap.end(); ++it) {
        miniv8::V8Object::AccessorData* accessor = it->second;
        if (accessor->data) {
            V8Head::onTraceHelper(tracer, &(accessor->data->m_head));
        }
    }
}

V8Object* V8Object::getByQjsValue(JSValue value)
{
    V8Object* old = (V8Object*)JS_GetUserdata(value);
    return old;
}

v8::Local<v8::Value> V8Object::GetPrototype()
{
    miniv8::V8Object* self = this;
    JSContext* ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Context* v8ctx = self->v8Ctx();
    miniv8ReleaseAssert(ctx, "V8Object::GetPrototype fail\n");

    JSValue selfV = self->v(self);

    JSValue proto = JS_UNDEFINED;
    if (false && JS_IsFunction(ctx, selfV)) {
        proto = JS_GetPropertyStr(ctx, selfV, "prototype");
    } else {
        proto = JS_GetPrototype(ctx, selfV);
    }
    if (JS_IsException(proto))
        DebugBreak();

    if (JS_IsUndefined(proto)) {
        proto = JS_NewObject(ctx);
        JS_SetPropertyStr(ctx, selfV, "prototype", proto);
        DebugBreak();
    }

    miniv8::V8Object* obj = miniv8::V8Object::create(v8ctx, proto); // 这里返回的对象，可以是复用的
    obj->m_internalFieldCount = self->m_internalFieldCount;
    v8::Local<v8::Object> ret = v8::Utils::convert<miniv8::V8Object, v8::Object>(obj);
    JS_FreeValue(ctx, proto);

    return ret;
}

bool V8Object::SetPrototype(JSContext* ctx, miniv8::V8Value* protoVal)
{
    miniv8::V8Object* self = this;

    if (protoVal->m_head.m_type == miniv8::kOTObject) {
        miniv8::V8Object* protoObj = (miniv8::V8Object*)protoVal;

        for (size_t i = 0; i < miniv8::V8Object::kMaxaAlignedPointerArraySize; ++i) {
            //miniv8ReleaseAssert(!self->m_alignedPointerInInternalFields[i], "v8::Object::SetPrototype fail\n");
            if (!self->m_alignedPointerInInternalFields[i])
                self->m_alignedPointerInInternalFields[i] = protoObj->m_alignedPointerInInternalFields[i];
        }
        //memcpy(self->m_alignedPointerInInternalFields, protoObj->m_alignedPointerInInternalFields, sizeof(void*) * miniv8::V8Object::kMaxaAlignedPointerArraySize);
    }

    JSValueConst protoV = protoVal->v(protoVal);
    miniv8ReleaseAssert(!JS_IsUndefined(protoV), "V8Object::SetPrototype fail\n");
    JSValue selfV = self->v(self);
    JSAtom prototypeAtom = JS_NewAtom(ctx, "prototype");

    BOOL isFunctionOfProtoVal = JS_IsFunction(ctx, protoV);

    int ret = -1;
    BOOL isFunction = JS_IsFunction(ctx, selfV);
    if (false && isFunction) { // 貌似v8::Object::SetPrototype就是设置__proto__的。刚好JS_SetPrototype也是设置__proto__
        JS_DupValue(ctx, protoV);
        ret = JS_SetPropertyFocus(ctx, selfV, prototypeAtom, protoV);

        JSValue test = JS_GetProperty(ctx, selfV, prototypeAtom);
        BOOL isUndef = JS_IsUndefined(test);
        isUndef = isUndef;
    } else {
        ret = JS_SetPrototype(ctx, selfV, protoV);
    }
    JS_FreeAtom(ctx, prototypeAtom);

    //printDebug("v8::Object::SetPrototype: %x, selfV:%I64u, protoVal:%p, %I64u\n", ret, selfV, protoVal, protoV);

    if (-1 == ret) { // -1有可能是protoV的原型链上，已经有v了。一般出现在global.prototype再设置prototype的时候
        miniv8PrintWhenError(ctx);
        DebugBreak();
        //         JSValue global = JS_GetGlobalObject(ctx);
        //         JSValue globalPrototype = JS_GetPrototypeFree(ctx, global);
        //         if (JS_VALUE_IS_EQ(globalPrototype, selfV)) {
        //             miniv8ReleaseAssert(!isFunction, "V8Object::SetPrototype fail\n");
        //
        //             miniv8::V8Object* protoObj = (miniv8::V8Object*)protoVal;
        //             protoObj = (miniv8::V8Object*)JS_GetUserdata(protoV); // test
        //
        //             // 这里不规范，不过暂时先这么搞搞，把global.prototype.prototype = protoV 变成 global.prototype = protoV
        //             //printDebug("v8::Object::SetPrototype!: %I64u\n", protoV);
        //             ret = JS_SetPrototype(ctx, global, protoV);
        //             //ret = JS_SetPropertyStr(ctx, global, "prototype", protoV);
        //             //ret = JS_DefinePropertyValue(ctx, global, prototypeAtom, protoV, 0);
        //        }
    }

    return (TRUE == ret);
}

v8::Maybe<bool> V8Object::Set(v8::Local<v8::Context> context, v8::Local<v8::Value> key, v8::Local<v8::Value> val, bool force)
{
    miniv8::V8Object* self = this;
    miniv8::V8Value* v8Key = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*key);
    miniv8::V8Value* v8Val = v8::Utils::openHandle<v8::Value, miniv8::V8Value>(*val);
    miniv8::V8Context* v8Context = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*context);
    JSContext* ctx = miniv8::V8Context::getCtx(v8Context);
    if (!v8Val)
        return v8::Just<bool>(false);
    if (!ctx)
        ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();

    JSAtom prop = JS_ValueToAtom(ctx, v8Key->v(v8Key));
    if (0 == prop)
        return v8::Just<bool>(false);

    JSValue value = v8Val->v(v8Val);
    if (JS_VALUE_IS_EQ(value, JS_UNDEFINED)) {
        JS_DeleteProperty(ctx, self->v(self), prop, 0);
    } else {
        JS_DupValue(ctx, value);
        v8Val->m_head.m_isInMember |= miniv8::V8Head::kIsSetObjectField;
        v8Val->m_head.m_unGcType |= miniv8::V8Head::kIsSetObjectField;
        //         v8Key->m_head.m_isInMember |= miniv8::V8Head::kIsSetObjectField;
        //         v8Key->m_head.m_unGcType |= miniv8::V8Head::kIsSetObjectField;

        int ret = 0;
        //         if (force) // 这里不能走强制设置。因为例如window的document属性，是由getter获取到的。如果强制设置了，会把getter冲掉。
        //             ret = JS_SetPropertyInternal2(ctx, self->v(self), prop, value, JS_PROP_THROW, TRUE, TRUE);
        //         else
        ret = JS_SetProperty(ctx, self->v(self), prop, value);

        if (TRUE != ret) {
            //JS_FreeValue(ctx, value);
            JS_FreeAtom(ctx, prop);
            return v8::Just<bool>(true); // 强制返回true。不然WindowProxy::updateDocumentProperty走不到最后
        }
    }

    JS_FreeAtom(ctx, prop);
    return v8::Just<bool>(true);
}

// 函数的实例被调用，通常是构造函数。也可能是普通函数
JSValue V8Function::onConstructorCallback(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor)
{
    return v8::internal::FunctionCallbackArguments::onConstructorCallback(ctx, thisVal, argc, argv, userdata, is_constructor);
}

static int s_nameCount = 0;

V8Function::~V8Function()
{
    // TODO: m_signature
    //printDebug("~~V8Function: %p\n", this);

    JSContext* ctx = V8Context::getEmptyJsCtx();
    JSValue v = this->v(this);
    //     JSValue v8FunctionTemplate = JS_GetPropertyStr(ctx, v, "v8FunctionTemplate");
    //     if (JS_IsObject(v8FunctionTemplate)) {
    //         //JS_FreeValue(ctx, v8FunctionTemplate);
    //         OutputDebugStringA("");
    //     }
    //     JS_DeletePropertyStr(ctx, v, "v8FunctionTemplate", 0);

    m_data.Reset();
    m_signature.Reset();
}

std::string V8Function::getName()
{
    if (m_name.empty()) {
        InterlockedIncrement((LONG volatile*)&s_nameCount);
        char temp[64] = { 0 };
        sprintf(temp, "_miniv8_func_noname_%d\n", s_nameCount);
        m_name = temp;
    }
    return m_name;
}

void V8Function::setName(const std::string& name)
{
    if (!m_name.empty())
        DebugBreak();
    m_name = name;
}

// function HTMLAllCollection() { [native code] }
static JSValue onToStringOfFunc(JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor)
{
    V8Function* self = (V8Function*)userdata;
    std::string name = "function ";
    name += self->getName();
    name += "() { [native code] }";
    return JS_NewString(ctx, name.c_str());
}

void V8Function::onJsUserDataWeakFuncOfV8Function(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step)
{
    V8Function* self = (V8Function*)userdata;
    delete self;
}

void V8Function::onV8HeadRefOrDerefOfV8Function(V8Head* head, bool ref)
{
    V8Function* self = (V8Function*)head;
    if (ref) {
        JSValue v = self->v(self);
        JS_DupValue(nullptr, v);
        return;
    }

    if (JS_VALUE_IS_EQ(self->m_head.m_qjsValue, JS_NULL)) {
        delete self;
        return;
    }
    JSRuntime* rt = V8Isolate::GetCurrent()->getRuntime();
    JS_FreeValueRT(rt, self->m_head.m_qjsValue); // 这里面有回调，会析构V8Data
}

void V8Function::onV8HeadTraceOfV8Function(void* tracer, V8Head* ptr)
{
    JSRuntime* rt = V8Isolate::GetCurrent()->getRuntime();
    V8Function* self = (V8Function*)ptr;
    V8Data::onV8HeadTraceOfV8Data(tracer, ptr);

    if (g_testFunc == self)
        OutputDebugStringA("");

    // TODO: JS_SetPropertyStr(ctx, funInst->v(funInst), "v8FunctionTemplate", this->v(this));

    //if (!m_signature.IsEmpty())
    //if (!m_data.IsEmpty())
    //miniv8::V8ArrayBuffer* self = v8::Utils::openHandle<v8::ArrayBuffer, miniv8::V8ArrayBuffer>(this);
}

JSValue V8Function::V8Function_v(V8Data* ptr)
{
    V8Function* self = (V8Function*)ptr;
    if (!JS_VALUE_IS_EQ(JS_NULL, self->m_head.m_qjsValue))
        return self->m_head.m_qjsValue;

    //JSContext* ctx = V8Context::getCurrentJsCtx();
    JSContext* ctx = V8Isolate::GetCurrent()->getEmptyCtx()->ctx();

    // JS_NewCFunction2之后要设置JS_SetConstructor，否则function没有prototype。目前我们在V8FunctionTemplate::GetFunction里设置
    std::string name = self->getName();
    self->m_head.m_qjsValue = JS_NewCFunction2(ctx, onConstructorCallback, name.c_str(), name.size(), JS_CFUNC_constructor_or_func, 0, self);
    //JS_DupValue(ctx, self->m_head.m_qjsValue); // TODO:free

    //JS_SetConstructor(ctx, self->m_head.m_qjsValue, proto);

    JSValue toStringFuncVal = JS_NewCFunction2(ctx, onToStringOfFunc, name.c_str(), 0, JS_CFUNC_generic, 0, self);
    JSAtom toStringAtom = JS_NewAtom(ctx, "toString");
    JS_SetProperty(ctx, self->m_head.m_qjsValue, /*JS_ATOM_toString*/ toStringAtom, toStringFuncVal);

    JS_SetUserdata(ctx, self->m_head.m_qjsValue, &V8Function::onJsUserDataWeakFuncOfV8Function, self);
    //JS_SetTestVal(self->m_head.m_qjsValue, self->m_head.m_qjsValue);
    JS_FreeAtom(ctx, toStringAtom);

    return self->m_head.m_qjsValue;
}

V8Signature* V8Signature::create(V8FunctionTemplate* templ)
{
    return new V8Signature(templ->getRegisterId());
}

V8Signature::V8Signature(int funcTemplId)
    : V8Data(nullptr, JS_NULL)
{
    m_head.m_type = kOTSignature;
    m_funcTemplId = funcTemplId;
    m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Signature;
    m_head.m_refOrDerefCopy = m_head.m_refOrDeref;
}

void V8FunctionTemplate::setClassName(const std::string& name)
{
    if (!m_name.empty() && m_name != name)
        DebugBreak();
    m_name = name;
}

std::string V8FunctionTemplate::getClassName()
{
    if (m_name.empty()) {
        InterlockedIncrement((LONG volatile*)&s_nameCount);
        char temp[64] = { 0 };
        sprintf(temp, "_miniv8_funtemp_noname_%d\n", s_nameCount);
        m_name = temp;
    }
    return m_name;
}

// 函数模版的实例被调用，通常是构造函数
void V8FunctionTemplate::onCall(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    // 在构造实例的时候，绑定InstanceTemplate
    miniv8::V8FunctionTemplate* self = (miniv8::V8FunctionTemplate*)(v8::External::Cast(*info.Data())->Value());
    miniv8::V8External* external = new miniv8::V8External(self->m_userdata);
    v8::Local<v8::External> externalv8 = v8::Utils::convert<miniv8::V8External, v8::External>(external); // 为了自动回收
    v8::internal::FunctionCallbackArguments::changeExternal(info, external);
    V8Isolate* isolate = (V8Isolate*)info.GetIsolate();
    V8Context* ctx = isolate->getCurrentCtx();

    if (!self->m_instanceTemplate) {
        if (self->m_constructor)
            self->m_constructor(info);
        if (0)
            JS_PrintStack(ctx->ctx());
        return;
    }

    V8ObjectTemplate* objTempl = self->m_instanceTemplate;

    v8::Local<v8::Object> objV8 = info.This();
    miniv8::V8Object* obj = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(*objV8);
    miniv8ReleaseAssert(!obj->m_hadBindInstanceTemplate, "obj->m_hadBindInstanceTemplate must be false\n");
    obj->m_hadBindInstanceTemplate = true;

    // 绑定m_instanceTemplate的东西给this
    for (std::map<std::string, JSValue>::iterator it = objTempl->m_props.begin(); it != objTempl->m_props.end(); ++it) {
        std::string name = it->first;
        JSValue val = it->second;

        //         if (46518 == JS_GetObjId(obj->v(obj)))
        //             OutputDebugStringA("");

        JSAtom prop = JS_NewAtomOrSymbol(ctx->ctx(), name.c_str());
        JS_DupValue(ctx->ctx(), val);
        JS_DefinePropertyValue(ctx->ctx(), obj->v(obj), prop, val, 0);
        JS_FreeAtom(ctx->ctx(), prop);
    }

    // TODO: 绑定setter

    //     JSCFunctionListEntry jsMt19937ProtoFuncs[2] = {
    //         //JS_CFUNC_DEF("generate", 1, jsMt19937Generate)
    //         { "generate", JS_PROP_WRITABLE | JS_PROP_CONFIGURABLE, JS_DEF_CFUNC, 0,{ 1, JS_CFUNC_generic,{ jsMt19937Generate } } },
    //         { "haha", JS_PROP_WRITABLE | JS_PROP_CONFIGURABLE, JS_DEF_CGETSET, 0,{ 0 } }
    //     };
    //
    //     JS_SetPropertyFunctionList(ctx->ctx(), obj->v(), jsMt19937ProtoFuncs, /*std::extent_v<decltype(jsMt19937ProtoFuncs)>*/ 2);

    miniv8ReleaseAssert(self->m_constructor, "self->m_constructor must has value\n");
    self->m_constructor(info);
}

struct FunctionTemplateInfo {
    void* userdata;
    v8::FunctionCallback constructor;
    v8::Persistent<v8::Signature> signature;
};

} // miniv8

namespace v8 {
namespace internal {

static bool checkCallSignature(miniv8::V8Isolate* isolate, miniv8::V8Context* context, miniv8::V8Signature* signature, miniv8::V8Object* holder)
{
    int holderTemplId = holder->getTemplId();
    if (!signature)
        return true;

    int signatureId = signature->getFuncTemplId();
    if (signatureId == holderTemplId)
        return true;

    JSValue val = holder->v(holder);
    while (true) {
        miniv8::V8Value* v = miniv8::V8Value::create(context, val);
        int templId = v->getTemplId();
        miniv8::V8Template* templ = isolate->getTemplateById(templId);
        while (templ) {
            if (signatureId == templ->getRegisterId())
                return true;
            templ = templ->getParentTemplate();
        }

        JSValue value = JS_GetPrototype(context->ctx(), val);
        if (JS_VALUE_IS_EQ(value, val) || JS_VALUE_IS_EQ(JS_NULL, value) || JS_VALUE_IS_EQ(JS_UNDEFINED, value))
            break;
        JS_FreeValue(context->ctx(), value);
        val = value;
    }

    return false;
}

// 本函数被调用，一般是成员函数被调用的情况。所以thisVal一般是this指针
JSValue FunctionCallbackArguments::onCFunctionCallback(
    JSContext* ctx, JSValueConst thisVal, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor)
{
    // ctx不是真实的context，而是当时注册本函数时用的getEmptyJsCtx
    ctx = miniv8::V8Context::getCurrentOrEmptyJsCtx();
    miniv8::V8Context* context = (miniv8::V8Context*)JS_GetContextOpaque(ctx);
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    miniv8::V8Isolate* v8isolate = (miniv8::V8Isolate*)isolate;
    miniv8::AutoEnterExitContext autoEnterExitContext(v8isolate, context);
    miniv8::FunctionTemplateInfo* info = (miniv8::FunctionTemplateInfo*)userdata;

    miniv8::V8Object* thisValV8 = nullptr;
    miniv8::V8Object* holder = nullptr;

    bool needFreeThisVal = false;
    if (JS_IsUndefined(thisVal)) {
        thisVal = JS_GetGlobalObject(ctx); // 直接调用alert，thisVal可能为undefined
        needFreeThisVal = true;
    }

    if (2 == argc) {
        uint32_t tag = JS_VALUE_GET_TAG(argv[1]);
        if (!JS_TAG_IS_FLOAT64(tag) && tag != JS_TAG_INT && tag != JS_TAG_BOOL && tag != JS_TAG_NULL && tag != JS_TAG_UNDEFINED && tag != JS_TAG_OBJECT
            && tag != JS_TAG_STRING)
            JS_PrintStack(ctx);
    }

    holder = miniv8::V8Object::create(context, thisVal);
    if (needFreeThisVal)
        JS_FreeValue(ctx, thisVal);
    thisValV8 = holder;
    //         if (holder->m_head.m_type == miniv8::V8ObjectType::kOTFunction && 1 == argc) {
    //             const char* prop = JS_ToCString(ctx, argv[0]);
    //             bool isToString = strcmp(prop, "toString") == 0;
    //             JS_FreeCString(ctx, prop);
    //             // "" + window["DOMTokenList"].prototype 类似这样的调用，blink因为重载了toString（见gen\blink\bindings\core\v8\V8DOMTokenList.cpp）
    //             // 按照v8的处理是直接报错。这里仿照v8的处理结果
    //             if (isToString) //
    //                 return JS_ThrowTypeError(ctx, "Illegal invocation");
    //         }

    v8::Local<v8::Signature> signatureV8 = info->signature.Get(isolate);
    miniv8::V8Signature* signature = v8::Utils::openHandle<v8::Signature, miniv8::V8Signature>(*signatureV8);

    if (/*false &&*/ !checkCallSignature((miniv8::V8Isolate*)v8isolate, context, signature, holder)) {
        JS_PrintStack(ctx);
        return JS_ThrowTypeError(ctx, "Illegal invocation");
    }

    std::vector<void*> argValue;
    void* implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kArgsLength] = { 0 };
    miniv8::V8External* external = new miniv8::V8External(info->userdata);
    miniv8::FunctionCallbackInfoWrap wrap;
    createFunctionCallbackInfo(context, false, thisValV8, &argValue, implicitArgs, external, &wrap, argc, argv);

    void** retVal = (void**)&implicitArgs[v8::FunctionCallbackInfo<v8::Value>::kReturnValueIndex];
    *retVal = &retVal;

    v8isolate->clearErr(ctx);
    v8isolate->pushRetVal(retVal);

    v8::FunctionCallbackInfo<v8::Value>* wrapV8 = (v8::FunctionCallbackInfo<v8::Value>*)(&wrap);
    info->constructor(*wrapV8);
    v8isolate->popRetVal();
    v8::Local<v8::External> externalv8 = v8::Utils::convert<miniv8::V8External, v8::External>(external); // 为了自动回收

    if (v8isolate->hasErr())
        return v8isolate->getErrAndClear();

    JSValue v = miniv8::getReturnVal(ctx, &retVal, retVal);
    return v;
}

} // internal
} // v8

namespace miniv8 {

V8Template::V8Template()
    : V8Data(nullptr, JS_NULL)
    , m_indexedPropHandles()
    , m_namePropHandles()
{
    JSContext* ctx = V8Context::getEmptyJsCtx();
    m_head.m_type = kOTTemplate;

    m_isDestroyed = false;
    m_head.m_qjsValue = JS_NewObject(ctx);
    m_funInst = nullptr;
    m_internalFieldCount = 0;
    m_parentTemplate = nullptr;
    m_instanceTemplate = nullptr;
    m_prototypeTemplate = nullptr;
    m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Template;
    m_head.m_refOrDerefCopy = m_head.m_refOrDeref;
    m_head.m_tracer = onV8HeadTraceOfV8Template;
    JS_SetUserdata(ctx, m_head.m_qjsValue, &V8Template::onJsUserDataWeakFuncOfV8Template, this);

    miniv8::V8Isolate* isolate = (miniv8::V8Isolate*)v8::Isolate::GetCurrent();
    m_registerId = isolate->registerTemplate(this);

    //printDebug("V8Template::V8Template: %p\n", this);
}

V8Template::~V8Template()
{
    destroy();

    //printDebug("V8Template::~~V8Template: %p\n", this);

    //     m_funInstPersistent.Reset();
    //     m_parentTemplate.Reset();
    //     m_instanceTemplate.Reset();
    //     m_prototypeTemplate.Reset();
}

void V8Template::destroy()
{
    if (m_isDestroyed)
        return;
    m_isDestroyed = true;

    JSContext* ctx = V8Context::getEmptyJsCtx();
    JSValue v = this->v(this);

    JS_DeletePropertyStr(ctx, v, "parentTemplate", 0);
    JS_DeletePropertyStr(ctx, v, "instanceTemplate", 0);
    JS_DeletePropertyStr(ctx, v, "prototypeTemplate", 0);

    JSValue funInst = JS_GetPropertyStr(ctx, v, "funInst");
    if (JS_IsObject(funInst)) {
        JS_DelConstructor(ctx, funInst);
        //JS_FreeValue(ctx, funInst);
    }
    JS_DeletePropertyStr(ctx, v, "funInst", 0);

    for (std::map<std::string, JSValue>::iterator it = m_props.begin(); it != m_props.end(); ++it) {
        JSValue val = it->second;
        JS_FreeValue(ctx, val);
    }
    m_props.clear();

    JSRuntime* rt = V8Isolate::GetCurrent()->getRuntime();
    JS_FreeValueRT(rt, m_head.m_qjsValue); // 这里面有回调，会析构V8Data
}

void V8Template::onJsUserDataWeakFuncOfV8Template(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step)
{
    V8Template* self = (V8Template*)userdata;
    delete self;
}

void V8Template::onV8HeadRefOrDerefOfV8Template(V8Head* head, bool ref)
{
    V8Template* self = (V8Template*)head;
    if (ref) {
        JSValue v = self->v(self);
        JS_DupValue(nullptr, v);
        return;
    }
    self->destroy();
}

void V8Template::onV8HeadTraceOfV8Template(void* tracer, V8Head* ptr)
{
    JSRuntime* rt = V8Isolate::GetCurrent()->getRuntime();
    v8::Isolate* isolate = v8::Isolate::GetCurrent();

    V8Template* self = (V8Template*)ptr;
    V8Data::onV8HeadTraceOfV8Data(tracer, ptr);

    v8::Local<v8::Template> templ;
    miniv8::V8Template* v8Template = nullptr;

    if (self->m_parentTemplate) {
        V8Head::onTraceHelper(tracer, &(self->m_parentTemplate->m_head));
    }

    if (self->m_instanceTemplate) {
        V8Head::onTraceHelper(tracer, &(self->m_instanceTemplate->m_head));
    }

    if (self->m_prototypeTemplate) {
        V8Head::onTraceHelper(tracer, &(self->m_prototypeTemplate->m_head));
    }

    std::map<std::string, JSValue>::iterator it = self->m_props.begin();
    for (; it != self->m_props.end(); ++it) {
        JSValue val = it->second;
        JS_MarkUserdataObj(rt, val, onMarkUserdataFunc, tracer);
    }

    if (self->m_funInst)
        V8Head::onTraceHelper(tracer, &(self->m_funInst->m_head));
}

static void insertProps(JSContext* ctx, std::map<std::string, JSValue>* props, const std::string& name, JSValue val)
{
    std::map<std::string, JSValue>::iterator it = props->find(name);
    if (it != props->end()) {
        JS_FreeValue(ctx, it->second);
        props->erase(it);
    }
    stdMapInsert(props, name, val);
}

void V8Template::Set(v8::Local<v8::Name> name, v8::Local<v8::Data> value, v8::PropertyAttribute attr)
{
    if (value.IsEmpty())
        return; // TODO: installConstantInternal->v8::Integer::New 没实现
    miniv8::V8Data* val = v8::Utils::openHandle<v8::Data, miniv8::V8Data>(*value);

    miniv8::V8String* nameStr = (miniv8::V8String*)v8::Utils::openHandle<v8::Name, miniv8::V8Name>(*name);
    miniv8ReleaseAssert(miniv8::kOTString == nameStr->m_head.m_type || miniv8::kOTSymbol == nameStr->m_head.m_type, // frome setClassString
        "v8::Template::Set fail\n");

    if (nameStr->getStr() == "toString" && v8::None == attr) // installV8NodeTemplate等会调用到这里。暂时不需要这样
        return;

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    miniv8::V8Context* ctx = V8Isolate::GetCurrent()->getEmptyCtx();

    if (miniv8::kOTFunctionTemplate == val->m_head.m_type) {
        miniv8::V8FunctionTemplate* funcProp = (miniv8::V8FunctionTemplate*)val;

        FunctionTemplateInfo* info = new FunctionTemplateInfo(); // TODO: Free
        info->constructor = funcProp->m_constructor;
        info->userdata = funcProp->m_userdata;

        v8::Local<v8::Signature> testSig = funcProp->m_signature.Get(isolate);
        miniv8::V8Signature* testSignature = v8::Utils::openHandle<v8::Signature, miniv8::V8Signature>(*testSig);

        info->signature.Reset(isolate, funcProp->m_signature);

        JSCFunction* func = &v8::internal::FunctionCallbackArguments::onCFunctionCallback;
        JSValue v = JS_NewCFunction2(ctx->ctx(), func, nameStr->getStr().c_str(), /*funcProp->m_argLength*/ -1, JS_CFUNC_generic, 0, info);
        insertProps(ctx->ctx(), &m_props, nameStr->getStr(), v);
    } else if (miniv8::kOTString == val->m_head.m_type) {
        miniv8::V8String* valStr = (miniv8::V8String*)val;
        JSValue v = valStr->v(valStr);
        JS_DupValue(ctx->ctx(), v);
        insertProps(ctx->ctx(), &m_props, nameStr->getStr(), v);
    } else if (miniv8::kOTInteger == val->m_head.m_type) {
        miniv8::V8Integer* valInt = (miniv8::V8Integer*)val;
        JSValue v = valInt->v(valInt);
        insertProps(ctx->ctx(), &m_props, nameStr->getStr(), v);
    } else if (miniv8::kOTValue == val->m_head.m_type || miniv8::kOTPrivate == val->m_head.m_type) {
        JSValue v = val->v(val);
        //if (!(JS_VALUE_IS_EQ(v, JS_NULL) || JS_VALUE_IS_EQ(v, JS_TRUE) || JS_VALUE_IS_EQ(v, JS_UNDEFINED) || JS_VALUE_IS_EQ(v, JS_FALSE)))
        {
            JS_DupValue(ctx->ctx(), v);
            insertProps(ctx->ctx(), &m_props, nameStr->getStr(), v);
        }
    } else {
        DebugBreak();
    }
}

static void copyIndexedPropHandleIfNotEmpty(v8::IndexedPropertyHandlerConfiguration* src, const v8::IndexedPropertyHandlerConfiguration& target)
{
    if (!src->getter) // TODO:暂时只支持getter
        src->getter = target.getter;
}

static void copyNamePropHandleIfNotEmpty(v8::NamedPropertyHandlerConfiguration* src, const v8::NamedPropertyHandlerConfiguration& target)
{
    if (!src->getter) // TODO:暂时只支持getter
        src->getter = target.getter;
}

void V8Template::newTemplateInstance(miniv8::V8Object* obj, bool isSetPrototype)
{
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    JSContext* ctx = miniv8::V8Context::getEmptyJsCtx(); // 不能使用context，因为context可能页面reload后就没了
    JSValue v = obj->v(obj);

    m_head.m_unGcType |= V8Head::kIsTemplateInFunction; // 暂时不回收模版对象

    obj->m_internalFieldCount = m_internalFieldCount > obj->m_internalFieldCount ? m_internalFieldCount : obj->m_internalFieldCount;
    if (0 == obj->m_internalFieldCount && m_parentTemplate) {
        obj->m_internalFieldCount = m_parentTemplate->m_internalFieldCount;
    }

    //printDebug("v8::ObjectTemplate::NewInstance: %p, obj->m_internalFieldCount:%d\n", obj, obj->m_internalFieldCount);
    if (m_indexedPropHandles.getter) {
        JSCFunctionType indexer;
        indexer.indexer = &v8::MacroAssembler::onIndexHandle;
        JS_SetIndexedOrNamePropertyFunction(ctx, v, JS_CFUNC_indexer, indexer, &m_indexedPropHandles);
    }

    if (m_namePropHandles.getter) {
        JSCFunctionType namePropGet;
        namePropGet.name_property_get = &v8::MacroAssembler::onNamePropertyGet;
        JS_SetIndexedOrNamePropertyFunction(ctx, v, JS_CFUNC_name_property_get, namePropGet, &m_namePropHandles);
    }

    if (m_namePropHandles.setter) {
        JSCFunctionType namePropSet;
        namePropSet.name_property_set = &v8::MacroAssembler::onNamePropertySet;
        JS_SetIndexedOrNamePropertyFunction(ctx, v, JS_CFUNC_name_property_set, namePropSet, &m_namePropHandles);
    }

    if (m_namePropHandles.query) {
        JSCFunctionType namePropQuery;
        namePropQuery.name_property_query = &v8::MacroAssembler::onNamePropertyQuery;
        JS_SetIndexedOrNamePropertyFunction(ctx, v, JS_CFUNC_name_property_query, namePropQuery, &m_namePropHandles);
    }

    // 注意，如果实例化是给function template做原型链对象，要特殊处理一下
    for (std::map<std::string, JSValue>::iterator it = this->m_props.begin(); it != this->m_props.end(); ++it) {
        std::string name = it->first;
        JSValue val = it->second;

        int objId = JS_GetObjId(val);
        if (46518 == objId)
            OutputDebugStringA("");

        JSAtom prop = JS_NewAtomOrSymbol(ctx, name.c_str());

        // JS_DefinePropertyValue里面会释放一次
        JS_DupValue(ctx, val); // 这次是让V8Template::onV8HeadRefOrDerefOfV8Template释放
        JS_DefinePropertyValue(ctx, v, prop, val, 0);
        JS_OrOpPropertyFlags(ctx, v, prop, JS_PROP_CONFIGURABLE);
        JS_OrOpPropertyFlags(ctx, v, prop, JS_PROP_WRITABLE);
        JS_FreeAtom(ctx, prop);
    }

    if (this->m_accessors.empty())
        return;

    JSCFunctionListEntry* accessorsFuncs = new JSCFunctionListEntry[this->m_accessors.size()];
    std::map<std::string, V8Template::Accessor>::iterator it = this->m_accessors.begin();
    for (int i = 0; it != this->m_accessors.end(); ++it, ++i) {
        const std::string& name = it->first;
        V8Template::Accessor* val = &it->second;
        miniv8ReleaseAssert(
            val->nameGetter || val->nameSetter || val->getterFunc || val->setterFunc || val->getter || val->setter, "V8Template::newTemplateInstance fail\n");

        accessorsFuncs[i].name = name.c_str();
        accessorsFuncs[i].prop_flags = JS_PROP_CONFIGURABLE;
        accessorsFuncs[i].def_type = JS_DEF_CGETSET;
        accessorsFuncs[i].magic = 0;
        accessorsFuncs[i].u.getset.get.getter = nullptr;
        accessorsFuncs[i].u.getset.set.setter = nullptr;

        if (val->nameGetter)
            accessorsFuncs[i].u.getset.get.getter = &v8::MacroAssembler::objectTemplateNameGetter;
        if (val->nameSetter)
            accessorsFuncs[i].u.getset.set.setter = &v8::MacroAssembler::objectTemplateNameSetter;

        if (val->getterFunc)
            accessorsFuncs[i].u.getset.get.getter = &v8::internal::FunctionCallbackArguments::objectTemplateFuncGetter;
        if (val->setterFunc)
            accessorsFuncs[i].u.getset.set.setter = &v8::internal::FunctionCallbackArguments::objectTemplateFuncSetter;

        if (val->getter)
            accessorsFuncs[i].u.getset.get.getter = &v8::MacroAssembler::objectTemplateNameGetter;
        if (val->setter)
            accessorsFuncs[i].u.getset.set.setter = &v8::MacroAssembler::objectTemplateNameSetter;

        accessorsFuncs[i].u.getset.userdata = val; // TODO:userdata
    }

    //JS_DupValue(ctx, v);
    JS_SetPropertyFunctionList(ctx, v, accessorsFuncs, this->m_accessors.size());
}

v8::MaybeLocal<v8::Function> V8FunctionTemplate::GetFunction(v8::Local<v8::Context> v8context)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    miniv8::V8Context* context = v8::Utils::openHandle<v8::Context, miniv8::V8Context>(*v8context);
    JSContext* ctx = context->ctx();
    v8::Local<v8::Function> ret;

    m_head.m_unGcType |= V8Head::kIsTemplateInFunction; // 暂时不回收模版对象

    // miniv8ReleaseAssert(!m_isInit, "v8::FunctionTemplate::GetFunction fail\n");
    //     if (m_funInst) {
    //         ret = v8::Utils::convert<miniv8::V8Function, v8::Function>(m_funInst);
    //         return ret;
    //     }

    miniv8::V8Function* funInst = new miniv8::V8Function(nullptr, &miniv8::V8FunctionTemplate::onCall, v8::External::New(isolate, this));
    if (0)
        g_testFunc = funInst;
    funInst->m_internalFieldCount = m_internalFieldCount;
    funInst->m_signature.Reset(isolate, m_signature);
    funInst->setName(getClassName());
    funInst->setTemplId(getRegisterId());

    JSValue funcInstVal = funInst->v(funInst);
    JSValue selfVal = this->v(this);

    // TODO:需要绑定这个到模板对象吗？感觉好像不用
    //     JS_DupValue(ctx, funcInstVal);
    //     JS_SetPropertyStr(ctx, selfVal, "funInst", funcInstVal);

    int ref1 = JS_GetRefCount(ctx, funcInstVal);
    int ref2 = JS_GetRefCount(ctx, selfVal);
    JS_DupValue(ctx, selfVal);
    JS_SetPropertyStr(ctx, funcInstVal, "v8FunctionTemplate", selfVal);

    //     ref1 = JS_GetRefCount(ctx, funcInstVal);
    //     ref2 = JS_GetRefCount(ctx, selfVal);
    //
    //     JS_DeletePropertyStr(ctx, funcInstVal, "v8FunctionTemplate", 0);
    //     ref1 = JS_GetRefCount(ctx, funcInstVal);
    //     ref2 = JS_GetRefCount(ctx, selfVal);

    ret = v8::Utils::convert<miniv8::V8Function, v8::Function>(funInst);

    //printDebug("v8::FunctionTemplate::GetFunction: %p, %p, %I64u\n", funInst, *ret, funcInstVal);

    newTemplateInstance(funInst, false);

    v8::MaybeLocal<v8::Object> prototype;
#if 0 // 这个m_instanceTemplate的属性newTemplateInstance，要放到v8::Function::NewInstance里去设置
    if (m_instanceTemplate)
        m_instanceTemplate->newTemplateInstance(funInst); // TODO: 没考虑m_instanceTemplate的m_instanceTemplate递归情况了
#endif

    if (m_prototypeTemplate) {
        v8::Local<v8::ObjectTemplate> prototypeTemplate = v8::Utils::convert<miniv8::V8ObjectTemplate, v8::ObjectTemplate>(m_prototypeTemplate);
        prototype = prototypeTemplate->NewInstance(v8context); // 这句里面会调用m_prototypeTemplate->newTemplateInstance(fun, true);
    }

    // JS_NewCFunction2之后要设置JS_SetConstructor，否则function没有prototype
    if (!prototype.IsEmpty()) {
        miniv8::V8Object* prototypeObject = v8::Utils::openHandle<v8::Object, miniv8::V8Object>(*(prototype.ToLocalChecked()));
        //printDebug("V8FunctionTemplate::GetFunction, prototypeTemplate: fun: %I64u, prototype: %I64u\n",  fun->v(fun), prototypeObject->v(prototypeObject));
        JS_SetConstructor(ctx, funcInstVal, prototypeObject->v(prototypeObject)); // TODO free: 没考虑释放问题，另外不清楚那些访问器能否起作用
    } else {
        JSValue proto = JS_NewObject(ctx);
        JS_SetConstructor(ctx, funcInstVal, proto);
        JS_FreeValue(ctx, proto);
    }

    // TODO：没考虑继承
    return ret;
}

void V8Template::inherit(const V8Template* parent)
{
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    copyIndexedPropHandleIfNotEmpty(&m_indexedPropHandles, parent->m_indexedPropHandles);
    copyNamePropHandleIfNotEmpty(&m_namePropHandles, parent->m_namePropHandles);

    m_head.m_unGcType |= V8Head::kIsTemplateInFunction; // 暂时不回收模版对象

    // 要考虑父模版的InstanceTemplate和PrototypeTemplate是否都要继承，以及这两模版的访问器是否也要继承
    for (std::map<std::string, miniv8::V8Template::Accessor>::const_iterator parentIt = parent->m_accessors.begin(); parentIt != parent->m_accessors.end();
         ++parentIt) {
        std::map<std::string, miniv8::V8Template::Accessor>::iterator it = m_accessors.find(parentIt->first);
        if (it == m_accessors.end())
            stdMapInsert(&m_accessors, parentIt->first, parentIt->second);
    }

    for (std::map<std::string, JSValue>::const_iterator parentIt = parent->m_props.begin(); parentIt != parent->m_props.end(); ++parentIt) {
        std::map<std::string, JSValue>::iterator it = m_props.find(parentIt->first);
        if (it == m_props.end()) {
            JSValue v = parentIt->second;
            JS_DupValue(nullptr, v);
            stdMapInsert(&m_props, parentIt->first, v);
        }
    }

    JSContext* ctx = miniv8::V8Context::getEmptyJsCtx();
    if (parent->m_instanceTemplate) {
        if (!m_instanceTemplate) {
#if 0 // 不能直接指针传递，因为怕别的地方修改指针的内容。只能复制一份
            m_instanceTemplate = parent->m_instanceTemplate;
            JS_DupValue(ctx, m_instanceTemplate->v(m_instanceTemplate));
            JS_SetPropertyStr(ctx, this->v(this), "instanceTemplate", m_instanceTemplate->v(m_instanceTemplate));
#else
            m_instanceTemplate = new V8ObjectTemplate();
#endif
        }
        m_instanceTemplate->inherit(parent->m_instanceTemplate);
    }
    if (parent->m_prototypeTemplate) {
        if (!m_prototypeTemplate) {
#if 0 
            m_prototypeTemplate = parent->m_prototypeTemplate;
#else
            m_prototypeTemplate = new V8ObjectTemplate();
#endif
            JS_DupValue(ctx, m_prototypeTemplate->v(m_prototypeTemplate));
            JS_SetPropertyStr(ctx, this->v(this), "prototypeTemplate", m_prototypeTemplate->v(m_prototypeTemplate));
        }
        m_prototypeTemplate->inherit(parent->m_prototypeTemplate);
    }

    m_parentTemplate = (V8Template*)parent;
    JS_DupValue(ctx, m_parentTemplate->v(m_parentTemplate));
    JS_SetPropertyStr(ctx, this->v(this), "parentTemplate", m_parentTemplate->v(m_parentTemplate)); // 让qjs管理引用
}

V8String::V8String()
    : V8Name(nullptr, JS_NULL)
{
    init();
}

V8String::V8String(V8Context* ctx, JSValue value)
    : V8Name(ctx, value)
{
    init();
    bindJsValue();
}

V8String::V8String(const std::string& str)
    : V8Name(nullptr, JS_NULL)
{
    init();

    // 先初始化一次。获取不到就用getEmptyJsCtx
    JSContext* ctx = V8Context::getCurrentOrEmptyJsCtx();
    //ensureQjsVal(ctx, false);

    if (!ctx) // 只有当isolate都没创建的时候会这样
        m_str = new std::string(str);
    else {
        m_head.m_qjsValue = JS_NewStringLen(ctx, str.c_str(), str.size());
        bindJsValue();
    }
}

V8String::V8String(const char* str, size_t len)
    : V8Name(nullptr, JS_NULL)
{
    init();

    // 先初始化一次。获取不到就用getEmptyJsCtx
    JSContext* ctx = V8Context::getCurrentOrEmptyJsCtx();
    miniv8ReleaseAssert(ctx, "");

    m_head.m_qjsValue = JS_NewStringLen(ctx, str, len);
    bindJsValue();
}

V8String::V8String(v8::String::ExternalOneByteStringResource* resource)
    : V8Name(NULL, JS_NULL)
{
    init();
    JSContext* ctx = V8Context::getCurrentOrEmptyJsCtx();
    m_head.m_qjsValue = JS_ExternalString(ctx, resource->data(), nullptr, resource->length() /*, onFreeExternalStringFunc, resource*/);
    bindJsValue();
}

V8String::V8String(v8::String::ExternalStringResource* resource)
    : V8Name(NULL, JS_NULL)
{
    init();
    JSContext* ctx = V8Context::getCurrentOrEmptyJsCtx();
    m_head.m_qjsValue = JS_ExternalString(ctx, nullptr, resource->data(), resource->length() /*, onFreeExternalStringFunc, resource*/);
    bindJsValue();
}

V8String::~V8String()
{
    if (m_str)
        delete m_str;
    if (m_twoByteExternalString)
        delete m_twoByteExternalString;
    if (m_oneByteExternalString)
        delete m_oneByteExternalString;
}

void V8String::bindJsValue()
{
    JSContext* ctx = V8Context::getCurrentOrEmptyJsCtx();
    if (JS_GetUserdata(m_head.m_qjsValue))
        return;
    JS_SetUserdata(ctx, m_head.m_qjsValue, &V8String::onJsUserDataWeakFuncOfV8String, this); // 延迟绑定
}

JSValue V8String::V8String_v(V8Data* ptr)
{
    V8String* self = (V8String*)ptr;
    JSContext* ctx = V8Context::getCurrentOrEmptyJsCtx();

    if (JS_VALUE_IS_EQ(self->m_head.m_qjsValue, JS_NULL)) {
        miniv8ReleaseAssert(self->m_str, "V8String_v fail\n");
        self->m_head.m_qjsValue = JS_NewStringLen(ctx, self->m_str->c_str(), self->m_str->size());
        //JS_DupValue(ctx, self->m_head.m_qjsValue);
        self->bindJsValue();
    }

    return self->m_head.m_qjsValue;
}

static bool isInvalidQjsValue(JSValue qjsValue)
{
    if (JS_VALUE_IS_EQ(qjsValue, JS_NULL) || JS_VALUE_IS_EQ(qjsValue, JS_SymbolGetIterator(NULL)) || JS_VALUE_IS_EQ(qjsValue, JS_SymbolUnscopables(NULL))
        || JS_VALUE_IS_EQ(qjsValue, JS_SymbolToStringTag(NULL)))
        return true;
    return false;
}

void V8String::onV8HeadRefOrDerefOfV8String(V8Head* head, bool ref)
{
    V8String* self = (V8String*)head;
    if (ref) {
        JSValue v = self->v(self);
        JS_DupValue(nullptr, v);
        return;
    }

    if (isInvalidQjsValue(self->m_head.m_qjsValue)) {
        delete self;
        return;
    }

    //printDebug("V8String.onV8HeadRefOrDerefOfV8String: %p, %d, %I64u\n", self, self->m_head.m_countId, self->m_head.m_qjsValue);
    JSRuntime* rt = V8Isolate::GetCurrent()->getRuntime();
    JS_FreeValueRT(rt, self->m_head.m_qjsValue);
}

void V8String::init()
{
    m_head.m_type = kOTString;
    m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8String;
    m_head.m_refOrDerefCopy = m_head.m_refOrDeref;
    v = V8String_v;
    m_twoByteExternalString = nullptr;
    m_oneByteExternalString = nullptr;
    m_strCount = -1;
    m_isContainsOnlyOneByte = -1;
    m_str = nullptr;
}

void V8String::onJsUserDataWeakFuncOfV8String(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step)
{
    V8String* self = (V8String*)userdata;
    delete self;
}

std::string V8String::getStr()
{
    if (m_str)
        return *m_str;

    JSContext* ctx = V8Context::getEmptyJsCtx();

    std::string str;
    size_t len = 0;
    JSValue new_val;
    const char* nameString = JS_GetStringData(ctx, &len, &new_val, m_head.m_qjsValue);
    if (!nameString)
        DebugBreak();

    if (!JS_VALUE_IS_EQ(m_head.m_qjsValue, new_val))
        m_str = new std::string(nameString, len);
    else
        str = std::string(nameString, len);

    JS_FreeValue(ctx, new_val);
    return m_str ? *m_str : str;
}

size_t V8String::getStrCount()
{
    //     if (-1 != m_strCount)
    //         return m_strCount;
    //
    //     const std::string& str = getStr();
    //     m_strCount = miniv8::getUtf8Length(str.c_str(), str.size());
    //     return m_strCount;

    if (m_twoByteExternalString)
        return m_twoByteExternalString->length();

    if (m_oneByteExternalString)
        return m_oneByteExternalString->length();

    JSContext* ctx = V8Context::getCurrentJsCtx();
    return JS_GetStringSize(ctx, m_head.m_qjsValue);
}

V8Symbol::V8Symbol(const std::string& str)
    : V8String()
{
    m_head.m_type = kOTSymbol;
    m_str = new std::string(str);
    v = V8String_v;
    m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8Symbol;
    m_head.m_refOrDerefCopy = m_head.m_refOrDeref;

    if (str == "Symbol.iterator") {
        m_head.m_qjsValue = JS_SymbolGetIterator(NULL);
    } else if (str == "Symbol.toStringTag") {
        m_head.m_qjsValue = JS_SymbolToStringTag(NULL);
    } else if (str == "Symbol.unscopables") {
        m_head.m_qjsValue = JS_SymbolUnscopables(NULL);
    } else {
        JSContext* ctx = V8Context::getEmptyJsCtx();
        m_head.m_qjsValue = JS_NewSymbolByStr(ctx, str.c_str(), str.size());
    }
}

std::string V8Symbol::getStr()
{
    if (m_str)
        return *m_str;

    JSContext* ctx = V8Context::getEmptyJsCtx();

    std::string str;
    size_t len = 0;

    JSAtom atom = JS_ValueToAtom(ctx, m_head.m_qjsValue);
    const char* nameString = JS_AtomToCString(ctx, atom);
    if (!nameString)
        return "";
    m_str = new std::string(nameString);
    return *m_str;
}

void V8Symbol::onV8HeadRefOrDerefOfV8Symbol(V8Head* head, bool ref)
{
    miniv8ReleaseAssert(!ref, "V8Symbol::onV8HeadRefOrDerefOfV8Symbol fail\n");
    V8Symbol* self = (V8Symbol*)head;
    if (ref)
        return;

    if (isInvalidQjsValue(self->m_head.m_qjsValue)) {
        delete self;
        return;
    }

    //     JSContext* ctx = V8Context::getCurrentOrEmptyJsCtx();
    //     JSAtom atom = JS_ValueToAtom(ctx, self->m_head.m_qjsValue);
    //     JS_FreeAtom(ctx, atom);
}

V8External::V8External(void* userdata)
    : V8Value(nullptr, JS_NULL)
{
    m_head.m_type = kOTExternal;
    m_userdata = userdata;
    isExternal = true;
    v = V8External_v;

    initQjsValue(false);
}

V8External::~V8External()
{
    //printDebug("V8External::~~V8External: %p\n", this);
}

void V8External::onV8HeadRefOrDerefOfV8External(V8Head* head, bool ref)
{
    //miniv8ReleaseAssert(!ref, "onV8HeadRefOrDerefOfV8External fail\n");
    V8External* self = (V8External*)head;
    if (ref) {
        JSValue v = self->v(self);
        JS_DupValue(nullptr, v);
        return;
    }

    JSRuntime* rt = V8Isolate::GetCurrent()->getRuntime();
    JS_FreeValueRT(rt, self->m_head.m_qjsValue); // 这里面有回调，会析构V8Data
}

void V8External::onUserDataWeakFuncOfV8External(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step)
{
    V8External* self = (V8External*)userdata;
    delete self;
}

void V8External::initQjsValue(bool isCheckCtx)
{
    m_head.m_refOrDeref = onV8HeadRefOrDerefOfV8External;
    m_head.m_refOrDerefCopy = m_head.m_refOrDeref;
    JSContext* ctx = V8Context::getCurrentJsCtx();
    if (!ctx) {
        miniv8ReleaseAssert(!isCheckCtx, "V8External::initQjsValue fail\n");
        return;
    }
    m_head.m_qjsValue = JS_NewObject(ctx);
    //JS_DupValue(ctx, m_head.m_qjsValue);
    JS_SetUserdata(ctx, m_head.m_qjsValue, &V8External::onUserDataWeakFuncOfV8External, this);
    JS_SetTestVal(m_head.m_qjsValue, (void*)1);
}

JSValue V8External::V8External_v(V8Data* ptr)
{
    V8External* self = (V8External*)ptr;
    if (!JS_VALUE_IS_EQ(self->m_head.m_qjsValue, JS_NULL))
        return self->m_head.m_qjsValue;

    self->initQjsValue(true);
    return self->m_head.m_qjsValue;
}

size_t V8ArrayBuffer::getByteLength()
{
    JSContext* ctx = V8Context::getCurrentJsCtx();
    size_t size = 0;
    uint8_t* data = JS_GetArrayBuffer(ctx, &size, m_head.m_qjsValue);
    return size;
}

uint8_t* V8ArrayBuffer::getContents(size_t* size)
{
    JSContext* ctx = V8Context::getCurrentJsCtx();
    uint8_t* data = JS_GetArrayBuffer(ctx, size, m_head.m_qjsValue);
    return data;
}

v8::Local<v8::ArrayBuffer> V8ArrayBufferView::getBuffer()
{
    JSContext* ctx = V8Context::getCurrentJsCtx();
    V8Context* context = V8Context::getCurrentCtx();

    size_t byteOffset = 0;
    size_t byteLength = 0;
    size_t bytesPerElement = 0;
    JSValue arrayBuffer = JS_GetTypedArrayBuffer(ctx, m_head.m_qjsValue, &byteOffset, &byteLength, &bytesPerElement);
    V8Value* val = V8Value::create(context, arrayBuffer);
    JS_FreeValue(ctx, arrayBuffer);

    v8::Local<v8::ArrayBuffer> ret = v8::Utils::convert<miniv8::V8ArrayBuffer, v8::ArrayBuffer>((V8ArrayBuffer*)val);
    return ret;
}

size_t V8ArrayBufferView::getByteOffset()
{
    JSContext* ctx = V8Context::getCurrentJsCtx();

    size_t byteOffset = 0;
    size_t byteLength = 0;
    size_t bytesPerElement = 0;
    JSValue arrayBuffer = JS_GetTypedArrayBuffer(ctx, m_head.m_qjsValue, &byteOffset, &byteLength, &bytesPerElement);
    JS_FreeValue(ctx, arrayBuffer);
    return byteOffset;
}

size_t V8ArrayBufferView::getByteLength()
{
    JSContext* ctx = V8Context::getCurrentJsCtx();

    size_t byteOffset = 0;
    size_t byteLength = 0;
    size_t bytesPerElement = 0;
    JSValue arrayBuffer = JS_GetTypedArrayBuffer(ctx, m_head.m_qjsValue, &byteOffset, &byteLength, &bytesPerElement);
    JS_FreeValue(ctx, arrayBuffer);
    return byteLength;
}

size_t V8ArrayBufferView::getEleCount()
{
    JSContext* ctx = V8Context::getCurrentJsCtx();

    size_t byteOffset = 0;
    size_t byteLength = 0;
    size_t bytesPerElement = 0;
    JSValue arrayBuffer = JS_GetTypedArrayBuffer(ctx, m_head.m_qjsValue, &byteOffset, &byteLength, &bytesPerElement);
    JS_FreeValue(ctx, arrayBuffer);
    return byteLength / bytesPerElement;
}

size_t V8ArrayBufferView::copyContents(void* dest, size_t byteLength)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
    JSContext* ctx = V8Context::getCurrentJsCtx();

    size_t byteOffset = 0;
    size_t byteLen = 0;
    size_t bytesPerElement = 0;
    JSValue arrayBuffer = JS_GetTypedArrayBuffer(ctx, m_head.m_qjsValue, &byteOffset, &byteLen, &bytesPerElement);

    size_t actuallyWrittenLen = byteLength;
    if (byteLength > byteLen)
        actuallyWrittenLen = byteLen;

    size_t size = 0;
    uint8_t* data = JS_GetArrayBuffer(ctx, &size, arrayBuffer);
    memcpy(data, data + byteOffset, actuallyWrittenLen);
    JS_FreeValue(ctx, arrayBuffer);

    return actuallyWrittenLen;
}

bool V8ArrayBufferView::hasBuffer() const
{
    JSContext* ctx = V8Context::getCurrentJsCtx();

    size_t byteOffset = 0;
    size_t byteLen = 0;
    size_t bytesPerElement = 0;
    JSValue arrayBuffer = JS_GetTypedArrayBuffer(ctx, m_head.m_qjsValue, &byteOffset, &byteLen, &bytesPerElement);

    bool b = JS_IsException(arrayBuffer) == FALSE;
    JS_FreeValue(ctx, arrayBuffer);
    return b;
}

void V8Resolver::onJsUserDataWeakFuncOfV8Resolver(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step)
{
    V8Resolver* self = (V8Resolver*)userdata;
    delete self;
}

void V8Resolver::onV8HeadRefOrDerefOfV8Resolver(V8Head* head, bool ref)
{
    //miniv8ReleaseAssert(!ref, "onV8HeadRefOrDerefOfV8Resolver fail\n");
    V8Promise::onV8HeadRefOrDerefOfV8Promise(head, ref);

    //     V8Resolver* self = (V8Resolver*)head;
    //     miniv8::V8Context* context = miniv8::V8Context::getEmptyCtx();
    //     JSContext* ctx = context->ctx();
    //     if (ref) {
    //         JSValue v = self->v(self);
    //         JS_DupValue(nullptr, v);
    //         return;
    //     }
    //
    //     //int count = JS_GetRefCount(ctx, self->m_head.m_qjsValue);
    //     JS_DeletePropertyStr(ctx, self->m_head.m_qjsValue, "promise", 0);
    //     //count = JS_GetRefCount(ctx, self->m_head.m_qjsValue);
    //
    //     JSRuntime* rt = V8Isolate::GetCurrent()->getRuntime();
    //     JS_FreeValueRT(rt, self->m_head.m_qjsValue);
}

void V8Resolver::onV8HeadTraceOfV8Resolver(void* tracer, V8Head* ptr)
{
    V8Resolver* self = (V8Resolver*)ptr;
    V8Promise::onV8HeadTraceOfV8Promise(tracer, ptr);

    //     if (self->m_promise)
    //         V8Head::onTraceHelper(tracer, &(self->m_promise->m_head));
}

V8Resolver::V8Resolver(V8Context* ctx)
    : V8Promise(ctx)
{
    m_head.m_type = kOTResolver;
    //m_promise = nullptr;

    m_head.m_refOrDeref = &V8Resolver::onV8HeadRefOrDerefOfV8Resolver;
    m_head.m_refOrDerefCopy = m_head.m_refOrDeref;
    m_head.m_tracer = &V8Resolver::onV8HeadTraceOfV8Resolver;
    //m_head.m_qjsValue = value;
    //JS_DupValue(ctx->ctx(), m_head.m_qjsValue);
    JS_SetUserdata(ctx->ctx(), m_head.m_qjsValue, &V8Resolver::onJsUserDataWeakFuncOfV8Resolver, this);
}

V8Resolver::~V8Resolver()
{
    miniv8::V8Context* context = miniv8::V8Context::getEmptyCtx();
    JSContext* ctx = context->ctx();
}

V8Promise* V8Promise::create(V8Context* ctx)
{
    return new V8Promise(ctx);
}

V8Promise* V8Promise::getOrCreate(V8Context* ctx, JSValue value)
{
    V8Promise* ret = (V8Promise*)JS_GetUserdata(value);
    if (ret) {
        miniv8ReleaseAssert(ret && ret->m_head.m_type == kOTPromise, "");
        return ret;
    }
    ret = new V8Promise(ctx, value);
    return ret;
}

V8Promise::V8Promise(V8Context* ctx, JSValue value)
    : V8Object(ctx, JS_NULL)
{
    m_head.m_type = kOTPromise;
    m_resolvingFuncs[0] = JS_NULL;
    m_resolvingFuncs[1] = JS_NULL;
    m_prev = nullptr;
    m_next = nullptr;
    m_head.m_qjsValue = value;
    //bindResolvingFuncs(ctx);
    JS_DupValue(ctx->ctx(), m_head.m_qjsValue);
    m_head.m_refOrDeref = &V8Promise::onV8HeadRefOrDerefOfV8Promise;
    m_head.m_refOrDerefCopy = m_head.m_refOrDeref;
    m_head.m_tracer = &V8Promise::onV8HeadTraceOfV8Promise;
    JS_SetUserdata(ctx->ctx(), m_head.m_qjsValue, &V8Promise::onJsUserDataWeakFuncOfV8Promise, this);

    V8Isolate* isolate = V8Isolate::GetCurrent();
    if (isolate->m_promises) {
        isolate->m_promises->m_next = this;
        m_prev = isolate->m_promises;
    }
    isolate->m_promises = this;
}

V8Promise::V8Promise(V8Context* ctx)
    : V8Object(ctx, JS_NULL)
{
    m_head.m_type = kOTPromise;
    m_resolvingFuncs[0] = JS_NULL;
    m_resolvingFuncs[1] = JS_NULL;
    m_prev = nullptr;
    m_next = nullptr;
    //m_head.m_qjsValue = value;
    bindResolvingFuncs(ctx);
    JS_DupValue(ctx->ctx(), m_head.m_qjsValue);
    m_head.m_refOrDeref = &V8Promise::onV8HeadRefOrDerefOfV8Promise;
    m_head.m_refOrDerefCopy = m_head.m_refOrDeref;
    m_head.m_tracer = &V8Promise::onV8HeadTraceOfV8Promise;
    //JS_SetUserdata(ctx->ctx(), m_head.m_qjsValue, &V8Promise::onJsUserDataWeakFuncOfV8Promise, this);

    V8Isolate* isolate = V8Isolate::GetCurrent();
    if (isolate->m_promises) {
        isolate->m_promises->m_next = this;
        m_prev = isolate->m_promises;
    }
    isolate->m_promises = this;
}

V8Promise::~V8Promise()
{
    V8Isolate* isolate = V8Isolate::GetCurrent();
    if (isolate->m_promises == this)
        isolate->m_promises = m_prev;

    if (m_prev)
        m_prev->m_next = m_next;

    if (m_next)
        m_next->m_prev = m_prev;

    JSRuntime* rt = V8Isolate::GetCurrent()->getRuntime();
    miniv8ReleaseAssert(JS_VALUE_IS_EQ(m_resolvingFuncs[0], JS_NULL) && JS_VALUE_IS_EQ(m_resolvingFuncs[1], JS_NULL), "");
}

void V8Promise::bindResolvingFuncs(V8Context* context)
{
    JSContext* ctx = context->ctx();
    if (!JS_VALUE_IS_EQ(m_resolvingFuncs[0], JS_NULL))
        return;

    m_head.m_qjsValue = JS_NewPromiseCapability(ctx, m_resolvingFuncs);
    int count = JS_GetRefCount(ctx, m_head.m_qjsValue);
    count = JS_GetRefCount(ctx, m_resolvingFuncs[0]);

    JS_DupValue(ctx, m_resolvingFuncs[0]);
    JS_DupValue(ctx, m_resolvingFuncs[1]);
    count = JS_GetRefCount(ctx, m_head.m_qjsValue);
}

void V8Promise::onV8HeadTraceOfV8Promise(void* tracer, V8Head* ptr)
{
    onV8HeadTraceOfV8Object(tracer, ptr);
    V8Promise* self = (V8Promise*)ptr;
    // V8Head::onTraceHelper(tracer, &(val->m_head));
    JSRuntime* rt = V8Isolate::GetCurrent()->getRuntime();
    JS_MarkUserdataObj(rt, self->m_resolvingFuncs[0], onMarkUserdataFunc, tracer);
    JS_MarkUserdataObj(rt, self->m_resolvingFuncs[1], onMarkUserdataFunc, tracer);
}

void V8Promise::onV8HeadRefOrDerefOfV8Promise(V8Head* head, bool ref)
{
    miniv8ReleaseAssert(!ref, "onV8HeadRefOrDerefOfV8Resolver fail\n");
    V8Promise* self = (V8Promise*)head;
    miniv8::V8Context* context = miniv8::V8Context::getEmptyCtx();
    JSContext* ctx = context->ctx();
    if (ref) {
        JSValue v = self->v(self);
        JS_DupValue(nullptr, v);
        return;
    }

    JSRuntime* rt = V8Isolate::GetCurrent()->getRuntime();

    int count = JS_GetRefCount(ctx, self->m_resolvingFuncs[0]);

    JS_FreeValueRT(rt, self->m_resolvingFuncs[0]);
    JS_FreeValueRT(rt, self->m_resolvingFuncs[1]);

    //     self->m_resolvingFuncs[0] = JS_NULL;
    //     self->m_resolvingFuncs[1] = JS_NULL;

    count = JS_GetRefCount(ctx, self->m_head.m_qjsValue);
    JS_FreeValueRT(rt, self->m_head.m_qjsValue);
}

void V8Promise::onJsUserDataWeakFuncOfV8Promise(JSValue obj, void* userdata, JS_USER_DATA_WEAK_STEP step)
{
    V8Promise* self = (V8Promise*)userdata;
    JSRuntime* rt = V8Isolate::GetCurrent()->getRuntime();
    int count = JS_GetRefCount(nullptr, self->m_resolvingFuncs[0]);
    JS_FreeValueRT(rt, self->m_resolvingFuncs[0]);
    JS_FreeValueRT(rt, self->m_resolvingFuncs[1]);
    delete self;
}

//---------------------------------------------------------
// GC逻辑

V8Isolate::AutoCallReentry::AutoCallReentry(V8Isolate* isolate)
{
    m_isolate = isolate;

    if (0 == m_isolate->m_callReentryCount) {
        SYSTEMTIME systemTime;
        FILETIME fileTime;

        GetSystemTime(&systemTime);
        SystemTimeToFileTime(&systemTime, &fileTime);

        int64_t milliseconds = (((int64_t)fileTime.dwHighDateTime) << 32) + fileTime.dwLowDateTime;

        if (milliseconds - isolate->m_lastGcMilliseconds > 30 * 1000 * 1000) {
            isolate->runGC();
            isolate->m_lastGcMilliseconds = milliseconds;
            OutputDebugStringA("");
        }
    }

    m_isolate->m_callReentryCount++;
}

void V8Isolate::onHeadDelete(V8Head* headPtr)
{
    for (size_t i = 0; i != m_needFreedHeads.size(); ++i) {
        V8Head* head = m_needFreedHeads[i];
        if (head == headPtr)
            m_needFreedHeads[i] = nullptr;
    }
}

void V8Isolate::gcHandleScopeHandleItem(V8Head* head, void** validHead)
{
    if (!(head->m_unGcType & miniv8::V8Head::kIsEscapeHandleScope)) {
        //printDebug("gcHandleScopeHandleItem: %p\n", head->m_isolatHandleScopeIndex);
        miniv8ReleaseAssert(!validHead || head->m_isolatHandleScopeIndex == validHead, "V8Isolate::exitContext fail\n");
        *head->m_isolatHandleScopeIndex = nullptr; // TODO:2023.2.26，强制回收，应该没问题吧？
        head->m_isolatHandleScopeIndex = nullptr;
        head->m_isolatHandleScopeIndexHadClear = true;
    }

    if (head->m_isolatGlobalScopeIndex || head->m_unGcType) // 有全局句柄\m_unGcType的不回收
        return;

    if (head->m_isolatHandleScopeIndex)
        miniv8ReleaseAssert(!validHead || head->m_isolatHandleScopeIndex == validHead, "V8Isolate::exitContext fail\n");

    if (head->m_type == V8ObjectType::kOTContext)
        OutputDebugStringA("");

    //     if (V8ObjectType::kOTArrayBuffer == head->m_type)
    //         printDebug("gcHandleScopeHandleItem:%p, %llu, %d, %p\n", head, head->m_qjsValue, JS_GetRefCount(NULL, head->m_qjsValue), head->m_isolatHandleScopeIndex);

    // head->m_refOrDeref可能会在JS_FreeValue没析构head，比如还有js在引用。此时在gc的时候会走到JS_FreeValue绑定的回调
    // 必须防止m_refOrDeref多次调用
    V8HeadRefOrDerefFun refOrDeref = head->m_refOrDeref;
    head->m_refOrDeref = nullptr;
    if (refOrDeref)
        refOrDeref(head, false); // 里面可能会调用JS_FreeValue
}

void V8Isolate::gcHandleScopeHandles(bool isForce)
{
    if (!m_currentCtxs.empty())
        return;

    static int s_sleep = 0;
    ++s_sleep;
    if (!isForce && (s_sleep % 5 != 0)) // 没事别运行gc
        return;

    // 先回收一些最简单可以判断的情况，例如没任何对象引用。这里遍历m_scopeHandles以后要改成链表，这样速度快很多
    for (size_t i = 0; i < m_scopeHandles.size(); ++i) {
        V8Head* head = (V8Head*)m_scopeHandles[i];
        if (!head)
            continue;

        head = (V8Head*)v8::Utils::toHandle<V8Data>((uintptr_t)head);
        head->m_markGC = 0;

        gcHandleScopeHandleItem(head, m_scopeHandles.data() + i);
    }
}

static bool checkGlobalNeedFreed(V8Head* head)
{
    if (0 != (head->m_unGcType & V8Head::kIsEternal) || 0 != (head->m_unGcType & V8Head::kIsRootIndex))
        return false;

        //     if (V8ObjectType::kOTContext == head->m_type) {
        //         miniv8::V8Context* context = (miniv8::V8Context*)head;
        //         return context->isDetachGlobal();
        //     }

        //     if (V8ObjectType::kOTFunction == head->m_type)
        //         return false; // 函数对象不回收了。应该没有哪个傻子会不停创建函数对象吧
        //
        //     if (V8ObjectType::kOTTemplate <= head->m_type && head->m_type <= V8ObjectType::kOTFunctionTemplate)
        //         return false; // 模版对象不回收了。应该没有哪个傻子会不停创建模版对象吧

        // v8::Persistent<v8::Object>::MarkActive()会设置kNodeIsActiveShift，但我们不再把MarkActive当成不需要回收的对象
#if V8_MAJOR_VERSION < 7
    if (head->getNodeFlag(v8::internal::Internals::kNodeIsActiveShift))
        return false;
#endif
    if (V8Isolate::GetCurrent()->isActivedObjectGroupId(head->m_objectGroupId)) // 如果找到是激活态的ObjectGroupId，则不回收
        return false;

    return true;
}

static bool checkNeedFreed(V8Head* head)
{
    if (0 != head->m_markGC || head->m_isolatHandleScopeIndex) // 有m_isolatHandleScopeIndex表示在gc的外层调用，有HandleScope存了这个head
        return false;

    return checkGlobalNeedFreed(head);
}

void V8Isolate::runGlobalWeakCallback(V8Head* head)
{
    if (head->m_weakCallback && head->m_weakCallback != kInvalidWeakCallback) {
        v8::WeakCallbackInfo<void>::Callback weakCallback = (v8::WeakCallbackInfo<void>::Callback)head->m_weakCallback;
        v8::WeakCallbackInfo<void>::Callback weakCallback2 = nullptr;
        void* internalFields[v8::kInternalFieldsInWeakCallback] = { 0 };

        if (head->m_type >= kOTObject && head->m_type <= kOTLastObject) {
            V8Object* obj = (V8Object*)head;
            internalFields[0] = obj->m_alignedPointerInInternalFields[0];
            internalFields[1] = obj->m_alignedPointerInInternalFields[1];
        }

        v8::WeakCallbackInfo<void> info((v8::Isolate*)this, head->m_weakCallbackParam, internalFields, &weakCallback2);
        head->m_weakCallback = kInvalidWeakCallback; // 这里先清空，但head有时候还会挂在链上，例如document dom就是。
        weakCallback(info);

        if (weakCallback2)
            weakCallback2(info); // 这里可能调用disposeGlobal
    } else if (head->m_weakCallback != kInvalidWeakCallback) {
        int32_t index = getGlobalizeCountHandlesIndex(head);
        int count = 0;
        if (-1 != index) {
            count = m_globalizeCountHandles[index];
            miniv8ReleaseAssert(count == 0, "");
            disposeGlobalImpl(head, true);
        } else { // -1表示有的head不在global引用链上，比如模版的实例模版引用
            V8HeadRefOrDerefFun refOrDeref = head->m_refOrDeref;
            head->m_refOrDeref = nullptr;
            if (refOrDeref)
                refOrDeref(head, false);
        }
    }

    // 不需要这里清空head->m_isolatGlobalScopeIndex，因为disposeGlobal里会清空
}

int V8Isolate::getGlobalizeCountHandlesIndex(V8Head* head)
{
    void* indexPtr = head->m_isolatGlobalScopeIndex;
    if (!indexPtr)
        return -1;
    int32_t index = ((uintptr_t)indexPtr - (uintptr_t)m_globalizeHandles.data()) / (sizeof(void*));
    return index;
}

void V8Isolate::freedHeads(JSContext* ctx, bool isFirstCall)
{
    for (size_t i = 0; i != m_needFreedHeads.size(); ++i) {
        V8Head* head = m_needFreedHeads[i];
        if (!head) // runGlobalWeakCallback里可能会改m_needFreedHeads的值为null
            continue;

        if (g_testFunc == head)
            OutputDebugStringA("");

        int32_t index = getGlobalizeCountHandlesIndex(head);
        if (-1 != index)
            miniv8ReleaseAssert(
                0 == m_globalizeCountHandles[index] || (head->m_weakCallback && 1 == m_globalizeCountHandles[index]), "V8Isolate::freedHeads fail\n");

        head->m_hasCallWeakCallback = 1;
        runGlobalWeakCallback(head); // head有可能在这里面调用disposeGlobal，然后被销毁
    }
}

// 有几种情况走到本函数：1、gccallback、2、运行时外部调用Reset、gc时，3、只有弱引用，然后gc发现没人引用了，就主动调用
void V8Isolate::disposeGlobalImpl(V8Head* head, bool fromRunGlobalWeakCallback)
{
    bool needDispose = false;
    int refCount = JS_GetRefCount(nullptr, head->m_qjsValue);

    int count = 0;
    int32_t index = getGlobalizeCountHandlesIndex(head);
    miniv8ReleaseAssert(-1 != index, "disposeGlobalImpl fail\n");

    // 根据v8的标准，（貌似）如果是弱引用，则引用计数为1就可以回收了。因为不用管设置了那个弱引用的global handles
    --m_globalizeCountHandles[index];
    count = m_globalizeCountHandles[index];
    // 有可能是-1
    //miniv8ReleaseAssert(count >= 0 || count == -1 && fromRunGlobalWeakCallback, "V8Isolate::disposeGlobalImpl fail\n");

    if (head->m_weakCallback) {
        if (count <= 1) // 如果有弱引用，且外部引用为1，就可以析构了
            needDispose = true;
    } else {
        if (count <= 0) // 如果没有弱引用，且外部引用为0，就可以析构了
            needDispose = true;
    }

    // 如果GC开始了，那有一种可能走到本函数：有弱引用，且引用计数为1了
    // 或者是来自于RunGlobalWeakCallback
    if (kGcStepBeging == m_gcStep) {
        //miniv8ReleaseAssert(head->m_weakCallback && count == 0 || fromRunGlobalWeakCallback, "");
        if (needDispose) {
            // 本函数有可能反复进入。因为第一次的时候内部qjs的引用还在，导致head这次不一定被销毁，从而head一直挂在m_isolatGlobalScopeIndex上。
            // 所以需要防止m_refOrDeref被反复调用
            V8HeadRefOrDerefFun refOrDeref = head->m_refOrDeref;
            head->m_refOrDeref = nullptr;
            if (refOrDeref)
                refOrDeref(head, false);
        }
    } else if (0 == count) {
        // 如果外部主动把弱引用也给reset了，就不需要再回调了
        head->m_weakCallback = nullptr;
        if (head->m_isolatGlobalScopeIndex)
            *(head->m_isolatGlobalScopeIndex) = nullptr;
        head->m_isolatGlobalScopeIndex = nullptr;
    } else if (-1 == count) {
        m_globalizeCountHandles[index] = 0; // 不能设置为-1
        DebugBreak();
        // head->m_isolatGlobalScopeIndex = nullptr; ?
    }
}

void V8Isolate::disposeGlobal(void* obj)
{
    V8Head* head = (V8Head*)v8::Utils::toHandle<V8Data>(*(intptr_t*)obj);
    disposeGlobalImpl(head, false);
}

void V8Isolate::runV8GcCallback(bool isPrologue)
{
    if (m_isExiting)
        return;

    v8::GCCallback gcCallback = nullptr;
    if (isPrologue && m_gcPrologueCallback) {
#if V8_MAJOR_VERSION > 5
        m_gcPrologueCallback((v8::Isolate*)this, v8::kGCTypeScavenge, v8::kGCCallbackFlagConstructRetainedObjectInfos);
        m_gcPrologueCallback((v8::Isolate*)this, v8::kGCTypeMarkSweepCompact, v8::kGCCallbackFlagCollectAllAvailableGarbage);
        m_gcPrologueCallback((v8::Isolate*)this, v8::kGCTypeIncrementalMarking, v8::kGCCallbackFlagConstructRetainedObjectInfos);
#else
        gcCallback = (v8::GCCallback)m_gcPrologueCallback;
        gcCallback(v8::kGCTypeScavenge, v8::kGCCallbackFlagConstructRetainedObjectInfos);
        gcCallback(v8::kGCTypeMarkSweepCompact, v8::kGCCallbackFlagCollectAllAvailableGarbage);
        gcCallback(v8::kGCTypeIncrementalMarking, v8::kGCCallbackFlagConstructRetainedObjectInfos);
#endif
    }

    if (!isPrologue && m_gcEpilogueCallback) {
#if V8_MAJOR_VERSION > 5
        m_gcEpilogueCallback((v8::Isolate*)this, v8::kGCTypeScavenge, v8::kGCCallbackFlagConstructRetainedObjectInfos);
        m_gcPrologueCallback((v8::Isolate*)this, v8::kGCTypeMarkSweepCompact, v8::kGCCallbackFlagCollectAllAvailableGarbage);
        m_gcEpilogueCallback((v8::Isolate*)this, v8::kGCTypeIncrementalMarking, v8::kGCCallbackFlagConstructRetainedObjectInfos);
#else
        gcCallback = (v8::GCCallback)m_gcEpilogueCallback;
        gcCallback(v8::kGCTypeScavenge, v8::kGCCallbackFlagConstructRetainedObjectInfos);
        gcCallback(v8::kGCTypeMarkSweepCompact, v8::kGCCallbackFlagCollectAllAvailableGarbage);
        gcCallback(v8::kGCTypeIncrementalMarking, v8::kGCCallbackFlagConstructRetainedObjectInfos);
#endif
    }
}

miniv8::V8Value* V8Isolate::getEternalByIndex(int i)
{
#if V8_MINOR_VERSION < 8
    miniv8::V8Value* val = (miniv8::V8Value*)(m_eternals[i]);
#else
    miniv8::V8Value* val = (miniv8::V8Value*)(&(m_eternals[i]));
#endif
    return val;
}

static void checkRepetitive(const std::vector<V8Head*>& needFreedHeads, V8Head* headPtr)
{
    for (size_t i = 0; i != needFreedHeads.size(); ++i) {
        V8Head* head = needFreedHeads[i];
        if (head == headPtr)
            DebugBreak();
    }
}

static bool isPromisePending(V8Head* head)
{
    if (kOTPromise != head->m_type && kOTResolver != head->m_type)
        return false;
    return JS_IsPromisePending(head->m_qjsValue);
}

// 1，对每个gc对象，如果标记为被别人引用，则判断qjs value的引用计数，如果大于1，则减1，然后标记为弱引用对象
// 2，对全局对象，如果被设置了弱引用回调，则标记为弱引用对象。同时判断qjs value的引用计数，如果大于1，则减1
// 3，对每个弱引用对象，如果被记为没激活态，则引用计数减1，同时转成已完成弱引用状态，防止反复减1
void V8Isolate::runGC()
{
    //miniv8ReleaseAssert(m_currentCtxs.empty(), "V8Isolate::runGC fail\n");
    printDebug("V8Isolate::runGC begin\n");
    gcHandleScopeHandles(true);
    m_activedObjectGroupId.clear();
    int useCount = 0;

    // TODO: 下面这段效率不高，以后合并在其他流程里
    for (size_t i = 0; i < m_globalizeHandles.size(); ++i) {
        V8Head* head = (V8Head*)m_globalizeHandles[i];
        if (!head)
            continue;

        head = (V8Head*)v8::Utils::toHandle<V8Data>((uintptr_t)head);
        head->m_markGC = 0;
        head->m_nodeFlag = 0;
        useCount++;
    }

    runV8GcCallback(true);

    GcTracer trace;
    int domNodeCount = 0;

    // 从根对象开始遍历染色
    for (size_t i = 0; i < m_globalizeHandles.size(); ++i) {
        V8Head* head = (V8Head*)m_globalizeHandles[i];
        if (!head)
            continue;

        head = (V8Head*)v8::Utils::toHandle<V8Data>((uintptr_t)head);
        if (head->m_type == kOTObject) {
            V8Object* obj = (V8Object*)head;
            if (obj->m_alignedPointerInInternalFields[1])
                domNodeCount++;
        }

        int32_t index = getGlobalizeCountHandlesIndex(head);

        bool forceTrace = isPromisePending(head); // V8Promise要单独处理，因为这货可以是pending状态，就算没人引用它也不能回收
        if (!forceTrace && (0 == m_globalizeCountHandles[index] || (head->m_weakCallback && m_globalizeCountHandles[index] <= 1)))
            continue; // 外部已经没人引用了，或者有且仅有个弱引用的，就不trace了

        if (head->m_tracer)
            head->m_tracer(&trace, head); // into V8Data::onV8HeadTraceOfV8Data...
    }

    for (int i = 0; i < miniv8::V8Isolate::kSlotSize; ++i) { // TODO:遍历的效率太低
        miniv8::V8Value* val = getEternalByIndex(i);
        if (!val)
            continue;
        if (val->m_head.m_tracer)
            val->m_head.m_tracer(&trace, &val->m_head);
    }

    // 单独tracer promise
    V8Promise* promise = m_promises;
    while (promise) {
        if (isPromisePending(&promise->m_head)) {
            if (promise->m_head.m_tracer)
                promise->m_head.m_tracer(&trace, &promise->m_head);
        }
        promise = promise->m_prev;
    }

    // 找出没被染色的
    V8Head* head = m_gcObjects;
    while (head) {
        if (checkNeedFreed(head)) {
            //checkRepetitive(m_needFreedHeads, head);
            m_needFreedHeads.push_back(head);
        } else {
            head->m_markGC = 0;
            head->m_nodeFlag = 0;
        }

        head = head->m_prev;
    }

    m_gcStep = kGcStepBeging;
    JSContext* ctx = V8Context::getEmptyJsCtx();
    freedHeads(ctx, true); // TODO: !!!!!!!!!!!!!!!!
    m_gcStep = kGcStepEnd;

    runV8GcCallback(false);

    JS_RunGC(getRuntime());
    m_needFreedHeads.clear();

    // TODO: 下面这段效率不高，以后合并在其他流程里
    int activeCount = 0;
    for (size_t i = 0; i < m_globalizeHandles.size(); ++i) {
        V8Head* head = (V8Head*)m_globalizeHandles[i];
        if (!head)
            continue;

        head = (V8Head*)v8::Utils::toHandle<V8Data>((uintptr_t)head);
        activeCount++;
    }

    for (int i = 0; i < miniv8::V8Isolate::kSlotSize; ++i) { // TODO:遍历的效率太低
        miniv8::V8Value* val = getEternalByIndex(i);
        if (!val)
            continue;
        val->m_head.m_markGC = 0;
    }
    printDebug("V8Isolate::runGC end\n");
}

void V8Isolate::visitHandlesWithClassIds(v8::PersistentHandleVisitor* visitor)
{
    void* ptr = &(m_globalizeHandles[2]);
    for (size_t i = 0; i < m_globalizeHandles.size(); ++i) {
        V8Head* head = (V8Head*)m_globalizeHandles[i];
        if (!head)
            continue;
        head = (V8Head*)v8::Utils::toHandle<V8Data>((uintptr_t)head);
        if (!head || !(kOTValue <= head->m_type && head->m_type <= kOTLastValue))
            continue;

        int count = m_globalizeCountHandles[i];
        miniv8ReleaseAssert(count >= -1, "");
        if (0 == count || -1 == count)
            continue;

        v8::Persistent<v8::Value> persistent;
        persistent.Reset((v8::Isolate*)this, v8::Utils::convert<miniv8::V8Value, v8::Value>((miniv8::V8Value*)head));
        visitor->VisitPersistentHandle(&persistent, persistent.WrapperClassId());
        persistent.Reset();
    }
}

}