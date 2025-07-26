#include "quickjs.h"
#include "cutils.h"

static JSValue plusNumbers(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv)
{
    int a, b;

    if (JS_ToInt32(ctx, &a, argv[0]))
        return JS_EXCEPTION;

    if (JS_ToInt32(ctx, &b, argv[1]))
        return JS_EXCEPTION;

    return JS_NewInt32(ctx, a + b);
}

static const JSCFunctionListEntry js_my_module_funcs[] = {
    JS_CFUNC_DEF("plus", 2, plusNumbers),
};

static int js_my_module_init(JSContext* ctx, JSModuleDef* m)
{
    return JS_SetModuleExportList(ctx, m, js_my_module_funcs, countof(js_my_module_funcs));
}

JSModuleDef* js_init_module_my_module(JSContext* ctx, const char* module_name)
{
    JSModuleDef* m;
    m = JS_NewCModule(ctx, module_name, js_my_module_init);

    if (!m)
        return NULL;

    JS_AddModuleExportList(ctx, m, js_my_module_funcs, countof(js_my_module_funcs));
    return m;
}