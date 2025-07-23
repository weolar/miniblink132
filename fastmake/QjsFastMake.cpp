
#include "FastMakeMain.h"

#include "quickjs/quickjs.h"
#include "quickjs/quickjs-libc.h"

#include "content/common/Util.h"
#include "content/common/StringUtil.h"
#include <string>
#include <vector>
#include <stdio.h>
#include <windows.h>
#include <Shlwapi.h>

#if defined(__i386__) || defined(_M_IX86)
extern "C" unsigned __int64 __cdecl __lzcnt64(unsigned __int64)
{
    DebugBreak();
    return 0;
}
#endif

extern "C" int64_t __udivti3(int64_t a, /*tu_int*/ int64_t b)
{
    DebugBreak();
    //return __udivmodti4(a, b, 0);
    return a / b;
}

struct CtxInfo {
    std::string cmd;
    std::string jsonName;
    RebuildOpt opt;
};

void printDebug(const char* format, ...)
{
    va_list argList;
    va_start(argList, format);

    char* output = (char*)malloc(0x100);
    vsprintf_s(output, 0x99, format, argList);
    OutputDebugStringA(output);
    free(output);

    va_end(argList);
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
        OutputDebugStringA(str);
        JS_FreeCString(ctx, argv[i], str);
    }
    OutputDebugStringA("\n");

    return JS_UNDEFINED;
}

static JSValue jsQfmGetCmdline(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor)
{
    const CtxInfo* ctxInfo = (const CtxInfo*)JS_GetContextOpaque(ctx);
    return JS_NewStringLen(ctx, ctxInfo->cmd.c_str(), ctxInfo->cmd.size());
}

static JSValue jsQfmRebuild(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv, void* userdata, JS_BOOL is_constructor)
{
    const CtxInfo* ctxInfo = (const CtxInfo*)JS_GetContextOpaque(ctx);
    const char* targetDir = JS_ToCString(ctx, argv[0]);
    const char* json = JS_ToCString(ctx, argv[1]);

    size_t size = strlen(json);
    if (0 == size)
        DebugBreak();

    std::vector<char> buffer;
    buffer.resize(size);
    memcpy(buffer.data(), json, size);

    std::string jsonPath = targetDir;
    char c = jsonPath[jsonPath.size() - 1];
    if (c != '\\' || c != '/')
        jsonPath += '/';
    jsonPath += ctxInfo->jsonName;

    std::wstring jsonPathW = (const WCHAR*)(content::utf8ToUtf16(jsonPath).c_str());
    common::writeFile((const WCHAR*)(jsonPathW.c_str()), buffer);
    //     if (kRebuildOptCompileTimeOutFile == ctxInfo->opt)
    //         fmBuild(jsonPathW);
    //     else
    //         fmFastBuild(jsonPathW, ctxInfo->opt);
    fmFastBuild(jsonPathW, ctxInfo->opt);

    JS_FreeCString(ctx, argv[0], targetDir);
    JS_FreeCString(ctx, argv[1], json);

    return JS_UNDEFINED;
}

static void printWhenError(JSContext* ctx)
{
    JSValue exception_val = JS_GetException(ctx);
    BOOL is_error = JS_IsError(ctx, exception_val);

    jsPrint(ctx, JS_NULL, 1, &exception_val, nullptr, FALSE);

    if (is_error) {
        JSValue val = JS_GetPropertyStr(ctx, exception_val, "stack");
        if (!JS_IsUndefined(val)) {
            const char* stack = JS_ToCString(ctx, val);
            printDebug("%s\n", stack);
            JS_FreeCString(ctx, val, stack);
        }
        JS_FreeValue(ctx, val);
    }
}

static JSValue addHelpersImpl(JSContext* ctx)
{
    JSValue globalObj = JS_GetGlobalObject(ctx);

    JS_SetPropertyStr(ctx, globalObj, "jsPrint", JS_NewCFunction(ctx, jsPrint, "jsPrint", 1));
    JS_SetPropertyStr(ctx, globalObj, "qfmRebuild", JS_NewCFunction(ctx, jsQfmRebuild, "qfmRebuild", 1));
    JS_SetPropertyStr(ctx, globalObj, "qfmGetCmdline", JS_NewCFunction(ctx, jsQfmGetCmdline, "qfmGetCmdline", 1));

    return JS_UNDEFINED;
}

static void addHelpers(JSContext* ctx)
{
    JS_FreeValue(ctx, addHelpersImpl(ctx));
}

static JSModuleDef* js_module_loader_test(JSContext* ctx, const char* moduleName, void* opaque)
{
    size_t buf_len;
    uint8_t* buf;
    JSModuleDef* m;
    JSValue func_val;

    //     std::vector<WCHAR> fullpath;
    //     fullpath.resize(MAX_PATH + 1);
    //     memset(fullpath.data(), 0, sizeof(wchar_t) * (MAX_PATH + 1));
    //     ::GetModuleFileNameW(NULL, fullpath.data(), MAX_PATH);
    //     ::PathRemoveFileSpecW(fullpath.data());
    //
    //     base::string16 moduleNameW = common::utf8ToUtf16(moduleName);
    //     ::PathAppendW(fullpath.data(), moduleNameW.c_str());
    //     std::string moduleNameFullpath = common::utf16ToUtf8(fullpath.data());
    const char* rootPath = (const char*)opaque;
    std::string moduleNameFullpath = rootPath;
    moduleNameFullpath += moduleName;

    buf = js_load_file(ctx, &buf_len, moduleNameFullpath.c_str());
    if (!buf) {
        JS_ThrowReferenceError(ctx, "could not load module filename '%s'", moduleName);
        return NULL;
    }

    /* compile the module */
    func_val = JS_Eval(ctx, (char*)buf, buf_len, moduleName, JS_EVAL_TYPE_MODULE | JS_EVAL_FLAG_COMPILE_ONLY);
    js_free(ctx, buf);
    if (JS_IsException(func_val)) {
        printWhenError(ctx);
        return NULL;
    }

    /* the module is already referenced, so we must free it */
    m = (JSModuleDef*)(JS_VALUE_GET_PTR(func_val));
    JS_FreeValue(ctx, func_val);
    return m;
}

int runQjsTest(const char* rootPath, const char* buf, size_t inputLen)
{
    JSRuntime* rt = JS_NewRuntime();
    JSContext* ctx = JS_NewContext(rt);

    addHelpers(ctx);

    /* add backtrace if the isError property is present in a thrown object */
#if 0
    JS_EnableIsErrorProperty(ctx, TRUE);
#endif
    /* loader for ES6 modules */
    JS_SetModuleLoaderFunc(rt, NULL, js_module_loader_test, (void*)rootPath);

    JSValue res_val = JS_Eval(ctx, buf, inputLen, "testqjs.js", JS_EVAL_TYPE_MODULE);

    if (JS_IsException(res_val)) {
        printWhenError(ctx);
    }

    return 0;
}

void qjsRebuild(const std::string& jsonPath, const std::string& jsonName, const std::string& cmd, RebuildOpt opt)
{
    JSRuntime* rt = JS_NewRuntime();
    JSContext* ctx = JS_NewContext(rt);

    CtxInfo ctxInfo;
    ctxInfo.cmd = cmd;
    ctxInfo.opt = opt;
    ctxInfo.jsonName = jsonName;
    JS_SetContextOpaque(ctx, (void*)&ctxInfo);

    addHelpers(ctx);

    /* add backtrace if the isError property is present in a thrown object */
#if 0
    JS_EnableIsErrorProperty(ctx, TRUE);
#endif

    /* loader for ES6 modules */
    JS_SetModuleLoaderFunc(rt, NULL, js_module_loader_test, (void*)jsonPath.c_str());

    std::string path = jsonPath + jsonName;

    std::vector<char> buffer;
    common::readFile((const WCHAR*)(content::utf8ToUtf16(path).c_str()), &buffer);
    if (buffer.size() == 0)
        DebugBreak();
    buffer.push_back('\0');

    JSValue res_val = JS_Eval(ctx, buffer.data(), buffer.size() - 1, jsonName.c_str(), JS_EVAL_TYPE_MODULE);

    if (JS_IsException(res_val)) {
        printWhenError(ctx);
        DebugBreak();
    }

    JS_FreeContext(ctx);
    OutputDebugStringA("qjsRebuild finish\n");
    //JS_FreeRuntime(rt);
}