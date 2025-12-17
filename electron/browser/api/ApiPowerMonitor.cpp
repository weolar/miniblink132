
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/IdLiveDetect.h"
#include "electron/common/NodeBinding.h"
#include "electron/common/NodeThread.h"
#include "electron/common/AtomVersion.h"
#include "electron/common/V8Util.h"
#include "electron/common/api/EventEmitter.h"
#include "electron/common/api/EventEmitterCaller.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "gin/converter.h"
#include "third_party/libnode/src/node_binding.h"
#include "base/command_line.h"
#include "ui/base/idle/idle.h"

namespace gin_helper {
template <>
struct Converter<ui::IdleState> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate,
        const ui::IdleState& in) {
        switch (in) {
            case ui::IDLE_STATE_ACTIVE:
                return StringToV8(isolate, "active");
            case ui::IDLE_STATE_IDLE:
                return StringToV8(isolate, "idle");
            case ui::IDLE_STATE_LOCKED:
                return StringToV8(isolate, "locked");
            case ui::IDLE_STATE_UNKNOWN:
            default:
                return StringToV8(isolate, "unknown");
        }
    }
};
}

namespace atom {

// // Main process
// const { app } = require('electron')
// app.commandLine.hasSwitch('disable-gpu')

class ApiPowerMonitor : public mate::EventEmitter<ApiPowerMonitor> {
public:
    static void init(v8::Isolate* isolate, v8::Local<v8::Object> target, node::Environment* env);

    explicit ApiPowerMonitor(v8::Isolate* isolate, v8::Local<v8::Object> wrapper);
    ~ApiPowerMonitor();

    ui::IdleState getSystemIdleStateApi(int idleThreshold) const;
    int getSystemIdleTimeApi() const;

    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args);

public:
    static gin_helper::WrapperInfo kWrapperInfo;
};

gin_helper::WrapperInfo ApiPowerMonitor::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };
v8::Persistent<v8::Function> s_ApiPowerMonitorConstructor;

static void initializeApiPowerMonitor(v8::Local<v8::Object> target, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, const NodeNative* native)
{
    ApiPowerMonitor::init(context->GetIsolate(), target, nullptr);
}

void ApiPowerMonitor::init(v8::Isolate* isolate, v8::Local<v8::Object> target, node::Environment* env)
{
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, ApiPowerMonitor::newFunction);
    gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
    builder.SetMethod("getSystemIdleState", &ApiPowerMonitor::getSystemIdleStateApi);
    builder.SetMethod("getSystemIdleTime", &ApiPowerMonitor::getSystemIdleTimeApi);

    v8::Local<v8::Function> prototypFunc = prototype->GetFunction(context).ToLocalChecked();
    target->Set(context, v8::String::NewFromUtf8(isolate, "ApiPowerMonitor").ToLocalChecked(), prototypFunc);
    s_ApiPowerMonitorConstructor.Reset(isolate, prototypFunc);
}

void ApiPowerMonitor::newFunction(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    CHECK(info.IsConstructCall());
    new ApiPowerMonitor(isolate, info.This()); // v8管理内存回收
    info.GetReturnValue().Set(info.This());
}

static LRESULT CALLBACK wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
    ApiPowerMonitor* self = (ApiPowerMonitor*)::GetPropW(hWnd, L"kPropW");
    if (!self && message == WM_CREATE) {
        LPCREATESTRUCTW cs = (LPCREATESTRUCTW)lParam;
        self = (ApiPowerMonitor*)cs->lpCreateParams;
        ::SetPropW(hWnd, L"kPropW", (HANDLE)self);
        return 0;
    }

    switch (message) {
        // ===== 关机事件处理 =====
        case WM_QUERYENDSESSION:
        {
            // lParam区分关机（ENDSESSION_CLOSEAPP）和注销（ENDSESSION_LOGOFF）
            bool isShutdown = (lParam & ENDSESSION_CLOSEAPP) != 0;
            bool isLogoff = (lParam & ENDSESSION_LOGOFF) != 0;

            if (isShutdown) {
                //std::cout << "检测到系统即将关机！" << std::endl;
                // 此处可执行数据保存等操作（需快速完成，避免阻塞关机流程）
                if (!self->mate::EventEmitter<ApiPowerMonitor>::emit("shutdown"))
                    return 0; // 此处返回0则不能关机，返回1就能关机。
                else
                    return 1;
            } else if (isLogoff) {
                //std::cout << "检测到用户即将注销！" << std::endl;
            }
            return TRUE; // 返回TRUE允许关机，返回FALSE尝试阻止（不推荐）
        }
        case WM_POWERBROADCAST:
        {
            switch (wParam) {
                case PBT_APMSUSPEND:
                    //std::cout << "系统即将休眠" << std::endl;
                    self->mate::EventEmitter<ApiPowerMonitor>::emit("suspend");
                    break;
                case PBT_APMRESUMESUSPEND:
                    //std::cout << "系统已唤醒" << std::endl;
                    self->mate::EventEmitter<ApiPowerMonitor>::emit("resume");
                    break;
                case PBT_APMPOWERSTATUSCHANGE:
                {
                    SYSTEM_POWER_STATUS status;
                    ::GetSystemPowerStatus(&status);
//                     std::cout << "电源状态变化："
//                         << (status.ACLineStatus ? "交流电" : "电池")
//                         << "，剩余电量：" << status.BatteryLifePercent << "%" << std::endl;
                    if (status.ACLineStatus)
                        self->mate::EventEmitter<ApiPowerMonitor>::emit("on-ac");
                    else
                        self->mate::EventEmitter<ApiPowerMonitor>::emit("on-battery");
                    break;
                }
            }
            return TRUE; // 处理成功
        }
        default:
            return ::DefWindowProcW(hWnd, message, wParam, lParam);
    }
}

ApiPowerMonitor::ApiPowerMonitor(v8::Isolate* isolate, v8::Local<v8::Object> wrapper)
{
    mate::EventEmitter<ApiPowerMonitor>::InitWith(isolate, wrapper);

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = wndProc;
    wc.lpszClassName = L"PowerEventWindow";
    ::RegisterClassW(&wc);

    HWND hWnd = CreateWindowExW(0, wc.lpszClassName, L"", 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, NULL, this);
}

ApiPowerMonitor::~ApiPowerMonitor()
{
}

ui::IdleState ApiPowerMonitor::getSystemIdleStateApi(int idleThreshold) const
{
    if (idleThreshold > 0) {
        return ui::CalculateIdleState(idleThreshold);
    } else {
        isolate()->ThrowException(v8::Exception::TypeError(gin::StringToV8(isolate(), "Invalid idle threshold, must be greater than 0")));
        return ui::IDLE_STATE_UNKNOWN;
    }
}

int ApiPowerMonitor::getSystemIdleTimeApi() const
{
    return ui::CalculateIdleTime();
}

static const char PowerMonitorSricpt[] = "exports = {};";

static NodeNative nativePowerMonitorNative { "ApiPowerMonitor", PowerMonitorSricpt, sizeof(PowerMonitorSricpt) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_browser_powermonitor, initializeApiPowerMonitor, &nativePowerMonitorNative)

} // atom