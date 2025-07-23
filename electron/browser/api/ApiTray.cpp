// Copyright (c) 2014 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/common/SystemTray.h"

#include "electron/nodeblink.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/HideWndHelp.h"
#include "electron/common/api/EventEmitter.h"
#include "electron/common/api/ApiNativeImage.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/libuv/include/uv.h"
#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"
#include "base/files/file_path.h"
#include <vector>
#include <ShellAPI.h>

#ifndef NIF_SHOWTIP
#define NIF_SHOWTIP 0x00000080
#endif

#ifndef NOTIFYICON_VERSION_4
#define NOTIFYICON_VERSION_4 4
#endif

#define IDR_POPUP_MENU 130

namespace atom {

const UINT WM_TRAY_MESSAGE = WM_APP + 100;

class Tray : public mate::EventEmitter<Tray> {
public:
    Tray(v8::Isolate* isolate, v8::Local<v8::Object> wrapper, /*std::string trayPath, NativeImage* nativeImage*/ v8::Local<v8::Value> arg)
        : m_hideWndHelp(nullptr)
    {
        gin_helper::Wrappable<Tray>::InitWith(isolate, wrapper);

        m_isSetContextMenu = false;

        Tray* self = this;
        m_hideWndHelp = new HideWndHelp(L"HideParentWindowClass",
            [self](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) -> LRESULT { return self->windowProc(hWnd, uMsg, wParam, lParam); });

        HCURSOR hCur = ::LoadCursor(NULL, IDC_ARROW);
        m_tray.create(nullptr, m_hideWndHelp->getWnd(), WM_TRAY_MESSAGE, L"TrayIcon", hCur, IDR_POPUP_MENU);

        //         if (nativeImage) {
        //             HICON hIcon = nativeImage->getIcon();
        //             if (hIcon)
        //                 m_tray.setIcon(hIcon);
        //         } else {
        //             std::u16string trayPathW = base::UTF8ToWide(trayPath);
        //             base::FilePath file = base::FilePath::FromUTF16Unsafe(base::StringPiece16 (trayPathW));
        //             file = file.NormalizePathSeparators();
        //             m_tray.setIcon(file.AsUTF16Unsafe().c_str());
        //         }
        setImage(arg);
    }

    static void init(v8::Isolate* isolate, v8::Local<v8::Object> target)
    {
        v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, newFunction);
        v8::Local<v8::Context> context = isolate->GetCurrentContext();

        prototype->SetClassName(v8::String::NewFromUtf8(isolate, "Tray").ToLocalChecked());
        gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
        builder.SetMethod("_setNativeMessageCallback", &Tray::_setNativeMessageCallbackApi);
        builder.SetMethod("_setIsContextMenu", &Tray::_setIsContextMenuApi);
        builder.SetMethod("setToolTip", &Tray::setToolTipApi);
        builder.SetMethod("displayBalloon", &Tray::displayBalloonApi);
        builder.SetMethod("setImage", &Tray::setImageApi);
        builder.SetMethod("destroy", &Tray::destroyApi);

        constructor.Reset(isolate, prototype->GetFunction(context).ToLocalChecked());
        target->Set(context, v8::String::NewFromUtf8(isolate, "Tray").ToLocalChecked(), prototype->GetFunction(context).ToLocalChecked());
    }

    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        v8::Isolate* isolate = args.GetIsolate();
        if (!args.IsConstructCall())
            return;

        //         NativeImage* nativeImage = nullptr;
        //         std::string trayPathString;
        //         v8::Local<v8::Value> trayPath = args[0];
        //         if (trayPath->IsString()) {
        //             v8::String::Utf8Value v(trayPath);
        //             trayPathString = *v;
        //         } else if (trayPath->IsObject()) {
        //             v8::Local<v8::Object> handle = trayPath->ToObject();
        //             nativeImage = NativeImage::GetSelf(handle);
        //         }

        new Tray(isolate, args.This(), /*trayPathString, nativeImage*/ args[0]);
        args.GetReturnValue().Set(args.This());
        return;
    }

    void _setNativeMessageCallbackApi(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        m_nativeMessageCallback.Reset(isolate(), args[0]);
    }

    void setToolTipApi(const std::string& tip)
    {
        m_tipString = base::UTF8ToUTF16(tip);
        m_tray.setTooltipText((LPCWSTR)(m_tipString.c_str()));
    }

    void _setIsContextMenuApi(bool b)
    {
        m_isSetContextMenu = b;
    }

    void destroy()
    {
    }

    void setImage(v8::Local<v8::Value> arg)
    {
        v8::Isolate* isolate = v8::Isolate::GetCurrent();
        v8::Local<v8::Context> context = isolate->GetCurrentContext();

        NativeImage* nativeImage = nullptr;
        std::string trayPathString;
        v8::Local<v8::Value> trayPath = arg;
        if (trayPath->IsString()) {
            v8::String::Utf8Value v(isolate, trayPath);
            trayPathString = *v;
        } else if (trayPath->IsObject()) {
            v8::Local<v8::Object> handle = trayPath->ToObject(context).ToLocalChecked();
            nativeImage = NativeImage::GetSelf(handle);
        }

        if (nativeImage) {
            HICON hIcon = nativeImage->getIcon();
            if (hIcon)
                m_tray.setIcon(hIcon);
        } else if (0 != trayPathString.size()) {
            std::u16string trayPathW = base::UTF8ToUTF16(trayPathString);
            base::FilePath file = base::FilePath::FromUTF16Unsafe(trayPathW);
            file = file.NormalizePathSeparators();
            m_tray.setIcon((LPCWSTR)(file.AsUTF16Unsafe().c_str()));
        }
    }

    void setImageApi(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        if (0 >= args.Length())
            return;
        setImage(args[0]);
    }

    void destroyApi(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        m_tray.removeIcon();
    }

    void displayBalloonApi(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        v8::Local<v8::Context> context = isolate()->GetCurrentContext();
        gin_helper::Dictionary options(isolate(), args[0]->ToObject(context).ToLocalChecked());

        std::u16string iconPath;
        options.GetBydefaultVal("icon", u"", &iconPath);

        std::u16string title;
        options.GetBydefaultVal("title", u"", &title);

        std::u16string content;
        options.GetBydefaultVal("content", u"", &content);

        m_tray.showBalloon((LPCWSTR)content.c_str(), (LPCWSTR)title.c_str());
    }

    void popUpContextMenu()
    {
        OutputDebugStringA("tray.displayBalloon not impl\n");
    }

    void onClick(std::string argString)
    {
        if (m_nativeMessageCallback.IsEmpty())
            return;

        v8::Function* callback = nullptr;
        v8::Local<v8::Value> f = m_nativeMessageCallback.Get(isolate());
        callback = v8::Function::Cast(*(f));

        v8::MaybeLocal<v8::String> argStringV8 = v8::String::NewFromUtf8(isolate(), argString.c_str(), v8::NewStringType::kNormal, argString.length());

        v8::Local<v8::Value> argv[1];
        argv[0] = argStringV8.ToLocalChecked();

        if (!callback->GetCreationContext().IsEmpty())
            callback->Call(callback->GetCreationContext().ToLocalChecked(), v8::Undefined(isolate()), 1, argv);
    }

    LRESULT windowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch (message) {
        case WM_TRAY_MESSAGE:
            m_tray.OnTrayNotification(wParam, lParam);

            if (LOWORD(lParam) == WM_RBUTTONUP) {
                onClick("right-click");
                mate::EventEmitter<Tray>::emit("right-click");
            } else if (LOWORD(lParam) == WM_LBUTTONUP) {
                mate::EventEmitter<Tray>::emit("click");
            }
            break;
        }
        return ::DefWindowProcW(hWnd, message, wParam, lParam);
    }

private:
    SystemTray m_tray;
    bool m_isSetContextMenu;
    std::u16string m_tipString;
    HideWndHelp* m_hideWndHelp;

    v8::Persistent<v8::Value> m_nativeMessageCallback;

public:
    static gin_helper::WrapperInfo kWrapperInfo;
    static v8::Persistent<v8::Function> constructor;
};

v8::Persistent<v8::Function> Tray::constructor;
gin_helper::WrapperInfo Tray::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };

void initializeTrayApi(v8::Local<v8::Object> exports, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, void* priv)
{
    Tray::init(context->GetIsolate(), exports);
}

} // atom namespace

static const char BrowserTrayNative[] = "console.log('BrowserTrayNative');;";
static NodeNative nativeBrowserTrayNative { "Tray", BrowserTrayNative, sizeof(BrowserTrayNative) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_browser_tray, atom::initializeTrayApi, &nativeBrowserTrayNative)
