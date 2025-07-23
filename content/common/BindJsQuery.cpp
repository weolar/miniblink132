
#include "content/browser/MbWebview.h"
#include "content/common/BindJsQuery.h"
#include "content/common/LiveIdDetect.h"
#include "content/common/ThreadCall.h"
#include "mbvip/core/MbJsValue.h"
#include "base/strings/utf_string_conversions.h"
#include <string>
#include <string.h>

extern bool g_isElectronMode;

namespace v8 {
bool ApiStringIsWellFormed(v8::Isolate* isolate, v8::Local<v8::String> source);
v8::Local<v8::String> ApiStringToWellFormed(v8::Isolate* isolate, v8::Local<v8::String> source);
}

namespace content {

static const char* injectScript =
    //"window.chrome = {app:null, runtime:null};\n"
    "if (!('chrome' in window)) {\n"
    "    Object.defineProperty(window, \"chrome\", {\n"
    "        get: function() {\n"
    "            return {\n"
    "                app:null, \n"
    "                runtime: {\n"
    "                    sendMessage:function() {} \n"
    "                }\n"
    "            };\n"
    "        },\n"
    "        set : function(val) {\n"
    "        },\n"
    "        enumerable : true,\n"
    "    });\n"
    "}\n"
    "window.__g_callbackMap__ = {};\n"
    "window.__g_callbackMapIdGen__ = 0;\n"
    "window.__onMbQuery__ = function(id, customMsg, response) {\n"
    "    var cb = window.__g_callbackMap__[id];\n"
    "    console.log('__onMbQuery__ cb:' + customMsg);\n"
    "    if (cb) {\n"
    "        cb(customMsg, response);\n"
    "        delete window.__g_callbackMap__[id];\n"
    "    }\n"
    "}\n"
    "window.__setMbQuery__ = function(func, func2) {\n"
    "    window.mbQuery = function(customMsg, request, cb) {\n"
    "        var id = -1\n"
    "        if ('function' == typeof cb) {\n"
    "            id = ++window.__g_callbackMapIdGen__;"
    "            window.__g_callbackMap__[id] = cb;\n"
    "        }\n"
    "        func(customMsg, request, id);\n"
    "        console.log('mbQuery cb:' + typeof cb);\n"
    "    }\n"
    "    window.mbSendToNative = func2;"
    "    window.mbSendToNative2 = function(request) {\n"
    "        var args = Array.prototype.slice.call(arguments);\n"
    "        func2(args);\n"
    "        console.log('mbSendToNative cb:' + typeof cb);\n"
    "    }\n"
    "}\n"
    "function __Audio__(url) {\n"
    "    this.paused = false;\n"
    "    this.loop = false;\n"
    "    this.playbackRate = 1;\n"
    "    this.defaultPlaybackRate = false;\n"
    "    this.src = false;\n"
    "    this.duration = 1;\n"
    "}\n"
    "__Audio__.prototype.addEventListener = function() {\n"
    "    return this;\n"
    "};\n"
    "__Audio__.prototype.pause = function() {\n"
    "    return this;\n"
    "};\n"
    "__Audio__.prototype.load = function() {\n"
    "    return this;\n"
    "};\n"
    "__Audio__.prototype.play = function() {\n"
    "    return this;\n"
    "};\n"
    "\n"
    "window.Audio = __Audio__\n";

static const char* injectStringWellFormed = "String.prototype.toWellFormed = function() { return __ApiStringToWellFormed__(this); }\n"
                                            "String.prototype.isWellFormed = function() { return __ApiStringIsWellFormed__(this); }\n";

// "function __NumberFormat__() {}\n"
// "__NumberFormat__.prototype.format = function(num) { return num; }\n"
// "window.Intl = {};\n"
// "Intl.NumberFormat = __NumberFormat__;\n"
;

void printCallstackIsolate(v8::Isolate* isolate)
{
    const v8::StackTrace::StackTraceOptions options = static_cast<v8::StackTrace::StackTraceOptions>(v8::StackTrace::kLineNumber | v8::StackTrace::kColumnOffset
        | v8::StackTrace::kScriptId | v8::StackTrace::kScriptNameOrSourceURL | v8::StackTrace::kFunctionName);

    int stackNum = 50;
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::StackTrace> stackTrace(v8::StackTrace::CurrentStackTrace(isolate, stackNum, options));
    int count = stackTrace->GetFrameCount();

    char* output = (char*)malloc(0x100);
    sprintf(output, "content::printCallstack: %d\n", count);
    OutputDebugStringA(output);
    free(output);

    for (int i = 0; i < count; ++i) {
        v8::Local<v8::StackFrame> stackFrame = stackTrace->GetFrame(isolate, i);
        int line = stackFrame->GetLineNumber();
        v8::Local<v8::String> scriptName = stackFrame->GetScriptNameOrSourceURL();
        v8::Local<v8::String> funcName = stackFrame->GetFunctionName();

        std::string scriptNameWTF;
        std::string funcNameWTF;

        if (!scriptName.IsEmpty()) {
            v8::String::Utf8Value scriptNameUtf8(isolate, scriptName);
            scriptNameWTF = *scriptNameUtf8;
        }

        if (!funcName.IsEmpty()) {
            v8::String::Utf8Value funcNameUtf8(isolate, funcName);
            funcNameWTF = *funcNameUtf8;
        }
        std::vector<char> output2;
        output2.resize(1000);
        sprintf(&output2[0], "line:%d, [", line);
        OutputDebugStringA(&output2[0]);

        if (!scriptNameWTF.empty()) {
            OutputDebugStringA(scriptNameWTF.c_str());
        }
        OutputDebugStringA("] , [");

        if (!funcNameWTF.empty()) {
            OutputDebugStringA(funcNameWTF.c_str());
        }
        OutputDebugStringA("]\n");
    }
    OutputDebugStringA("\n");
}

void printCallstack()
{
    printCallstackIsolate(v8::Isolate::GetCurrent());
}

static void mbConsoleLog(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Value> param0 = info[0];
    v8::MaybeLocal<v8::String> param0Maybe = param0->ToString(context);
    if (param0Maybe.IsEmpty())
        return;
    v8::Local<v8::String> param0V8String = param0Maybe.ToLocalChecked();

    v8::String::Utf8Value param0String(isolate, param0V8String);
    std::string str = "mbConsoleLog, ";
    str += *param0String;
    str += "\n";

//     if (std::string::npos != str.find("utility-process.js"))
//         MessageBoxA(0, "utility-process.js", 0, 0);

    if (std::string::npos != str.find("__alert__")) {
        MessageBoxA(0, str.c_str(), 0, 0);
    }

    if (std::string::npos != str.find("__callstack__")) {
        printCallstackIsolate(isolate);
    }

    std::u16string strW = base::UTF8ToUTF16(str);
    OutputDebugStringW((const WCHAR*)strW.c_str());
}

// 新增加一个不定参数的版本
void BindJsQuery::jsCallback2(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Local<v8::External> ext = info.Data().As<v8::External>();
    BindJsQuery* self = (BindJsQuery*)ext->Value();

    v8::Isolate* isolate = info.GetIsolate();
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Context::Scope contextScope(context);

    void* host = (void*)common::LiveIdDetect::getMbWebviewIds()->getPtrLocked(self->m_webviewId);
    if (!host)
        return;
    common::LiveIdDetect::getMbWebviewIds()->unlock(self->m_webviewId, self);

    std::vector<mb::MbJsValue*>* jsValues = new std::vector<mb::MbJsValue*>(info.Length());
    for (int i = 0; i < info.Length(); ++i) {
        v8::Local<v8::Value> argIt = info[i];
        mb::MbJsValue* jsValue = mb::MbJsValue::v8ValueToMb(isolate, context, argIt);
        jsValues->at(i) = jsValue;
    }

    self->onJsQuery2InBlinkThread(self->m_frameToken, jsValues);
}

void BindJsQuery::onJsQuery2InBlinkThread(const blink::LocalFrameToken& frameToken, std::vector<mb::MbJsValue*>* jsValues)
{
    int64_t id = m_webviewId;
    BindJsQuery* self = this;

    size_t frameId = (blink::LocalFrameToken::Hasher()(m_frameToken));

    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [self, id, jsValues] {
        void* unuse = common::LiveIdDetect::getMbWebviewIds()->getPtrLocked(id);
        if (!unuse) {
            delete jsValues;
            return;
        }

        std::vector<mbJsValue> vals;
        for (size_t i = 0; i < jsValues->size(); ++i) {
            mb::MbJsValue* v = jsValues->at(i);
            vals.push_back(v->getId());
        }

        //std::function<void(mbJsExecState es, int64_t idInfo, int customMsg, const utf8* request)>* closure = self->getClosure().m_jsQueryClosure;
        QueryFn2* closure = self->m_closure2;
        if (closure)
            (*closure)((mbJsExecState) nullptr, vals.data(), vals.size());

        for (size_t i = 0; i < jsValues->size(); ++i) {
            mb::MbJsValue* v = jsValues->at(i);
            v->deref();
        }

        common::LiveIdDetect::getMbWebviewIds()->unlock(id, unuse);
    });
}

void BindJsQuery::jsCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Local<v8::External> ext = info.Data().As<v8::External>();
    BindJsQuery* self = (BindJsQuery*)ext->Value();

    if (3 != info.Length())
        return;

    v8::Isolate* isolate = info.GetIsolate();
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Context::Scope contextScope(context);

    v8::Local<v8::Value> arg0 = info[0];
    int customMsg = arg0->ToInt32(context).ToLocalChecked()->Value();

    v8::Local<v8::Value> arg1 = info[1];
    v8::Local<v8::String> str = arg1->ToString(context).ToLocalChecked();
    v8::String::Utf8Value strUtf8(isolate, str);

    v8::Local<v8::Value> arg2 = info[2];
    int queryId = arg2->ToInt32(context).ToLocalChecked()->Value();

    void* host = (void*)common::LiveIdDetect::getMbWebviewIds()->getPtrLocked(self->m_webviewId);
    if (!host)
        return;
    common::LiveIdDetect::getMbWebviewIds()->unlock(self->m_webviewId, self);

    std::string* requestString = new std::string(*strUtf8, strUtf8.length());
    self->onJsQueryInBlinkThread(self->m_frameToken, customMsg, requestString, queryId);
}

void BindJsQuery::onJsQueryInBlinkThread(const blink::LocalFrameToken& frameToken, int customMsg, const std::string* requestString, int queryId)
{
    int64_t id = m_webviewId;
    BindJsQuery* self = this;

    size_t frameId = (blink::LocalFrameToken::Hasher()(m_frameToken));

    std::pair<size_t, int>* idInfo = new std::pair<size_t, int>(frameId, queryId);

    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [self, id, customMsg, requestString, idInfo] {
        void* unuse = common::LiveIdDetect::getMbWebviewIds()->getPtrLocked(id);
        if (!unuse) {
            delete idInfo;
            delete requestString;
            return;
        }

        //std::function<void(mbJsExecState es, int64_t idInfo, int customMsg, const utf8* request)>* closure = self->getClosure().m_jsQueryClosure;
        QueryFn* closure = self->m_closure;
        if (closure)
            (*closure)((mbJsExecState) nullptr, (__int64)idInfo, customMsg, requestString->c_str());
        delete requestString;

        common::LiveIdDetect::getMbWebviewIds()->unlock(id, unuse);
    });
}

static void bindGlobalFunction(v8::Local<v8::Context> context, const char* name, v8::FunctionCallback callback)
{
    v8::Isolate* isolate = context->GetIsolate();
    v8::HandleScope handleScope(isolate);
    v8::TryCatch block(isolate);
    v8::Context::Scope contextScope(context);

    v8::Local<v8::Object> object = context->Global();
    v8::Local<v8::FunctionTemplate> tmpl = v8::FunctionTemplate::New(isolate);

    // Set the function handler callback.
    tmpl->SetCallHandler(callback);

    // Retrieve the function object and set the name.
    v8::Local<v8::Function> func = tmpl->GetFunction(context).ToLocalChecked();
    v8::Local<v8::String> nameV8 = v8::String::NewFromUtf8(isolate, name, v8::NewStringType::kNormal, -1).ToLocalChecked();
    func->SetName(nameV8);

    object->Set(context, nameV8, func);
}

// static void V8StringToWellFormed(const v8::FunctionCallbackInfo<v8::Value>& info)
// {
//     if (1 != info.Length())
//         return;
//     if (!info[0]->IsStringObject())
//         return;
//     v8::Local<v8::StringObject> a0 = info[0].As<v8::StringObject>();
//     v8::Local<v8::String> ret = v8::ApiStringToWellFormed(info.GetIsolate(), a0->ValueOf());
//     info.GetReturnValue().Set(ret);
// }
//
// static void V8StringIsWellFormed(const v8::FunctionCallbackInfo<v8::Value>& info)
// {
//     if (1 != info.Length())
//         return;
//     if (!info[0]->IsStringObject())
//         return;
//     v8::Local<v8::StringObject> a0 = info[0].As<v8::StringObject>();
//     bool ret = v8::ApiStringIsWellFormed(info.GetIsolate(), a0->ValueOf());
//     info.GetReturnValue().Set(ret);
// }

void fixStringWelFormed(v8::Local<v8::Context> context)
{
//     bindGlobalFunction(context, "__ApiStringToWellFormed__", V8StringToWellFormed);
//     bindGlobalFunction(context, "__ApiStringIsWellFormed__", V8StringIsWellFormed);

//     v8::Isolate* isolate = context->GetIsolate();
//     v8::Isolate::Scope isolateScope(isolate);
//     v8::HandleScope handleScope(isolate);
//     v8::Context::Scope contextScope(context);
// 
//     v8::Local<v8::String> source = v8::String::NewFromUtf8(isolate, injectStringWellFormed).ToLocalChecked();
//     v8::Local<v8::Script> script = v8::Script::Compile(context, source).ToLocalChecked();
//     script->Run(context);
}

void BindJsQuery::bindFun(v8::Local<v8::Context> context, QueryFn* queryFn, QueryFn2* queryFn2, MbWebView* webview, const blink::LocalFrameToken& frameToken)
{
    int64_t webviewId = webview->getId();
    v8::Isolate* isolate = context->GetIsolate();
    v8::HandleScope handleScope(isolate);
    v8::Context::Scope contextScope(context);
    v8::Local<v8::Object> globalObj = context->Global();
    v8::MicrotasksScope microtasksScope(context, v8::MicrotasksScope::Type::kDoNotRunMicrotasks);

    if (!g_isElectronMode)
        bindGlobalFunction(context, "mbConsoleLog", mbConsoleLog);

    fixStringWelFormed(context);

    size_t frameId = (blink::LocalFrameToken::Hasher()(frameToken));
    std::string injectScriptStr(injectScript);
    mb::MbJsValue* mbVal = webview->runJsOnBlinkThreadImpl((mbWebFrameHandle)frameId, 0, &injectScriptStr, false, nullptr, nullptr);
    if (mbVal)
        mbVal->deref();

    // 构建func参数
    BindJsQuery* self = new BindJsQuery();
    self->m_webviewId = webviewId;
    self->m_frameToken = frameToken;
    self->m_closure = queryFn;
    self->m_closure2 = queryFn2;
    v8::Local<v8::Value> dataLocal = v8::External::New(isolate, self);

    v8::Local<v8::FunctionTemplate> functionTemplate = v8::FunctionTemplate::New(isolate, jsCallback, dataLocal);
    v8::Local<v8::Function> v8Function;
    if (!functionTemplate->GetFunction(context).ToLocal(&v8Function))
        DebugBreak();

    v8::Local<v8::FunctionTemplate> functionTemplate2 = v8::FunctionTemplate::New(isolate, jsCallback2, dataLocal);
    v8::Local<v8::Function> v8Function2;
    if (!functionTemplate2->GetFunction(context).ToLocal(&v8Function2))
        DebugBreak();

    v8::Local<v8::Object> global = context->Global();
    v8::Local<v8::Value> windowVal
        = global->Get(context, v8::String::NewFromUtf8(isolate, "window", v8::NewStringType::kNormal, -1).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Object> windowObj = windowVal->ToObject(context).ToLocalChecked();

    v8::Local<v8::String> setMbQueryStr = v8::String::NewFromUtf8(isolate, "__setMbQuery__", v8::NewStringType::kNormal, -1).ToLocalChecked();
    v8::Local<v8::Value> setMbQueryStrValue = windowObj->Get(context, setMbQueryStr).ToLocalChecked();
    if (!setMbQueryStrValue->IsFunction()) // https://www.hao123.com/?tn=48021271_79_hao_pg 这网页不知道为啥有时绑定失败
        return;

    v8::Function* setMbQueryFunc = v8::Function::Cast(*setMbQueryStrValue);

    v8::Local<v8::Value> argv[2] = { v8Function, v8Function2 };
    setMbQueryFunc->Call(context, v8::Undefined(isolate), 2, argv);
}

}