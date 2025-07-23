// Copyright (c) 2014 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/nodeblink.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/api/EventEmitter.h"
#include "electron/common/api/ApiNativeImage.h"
#include "electron/common/gin_helper/wrappable.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/libuv/include/uv.h"
#include "ui/base/clipboard/clipboard.h"
#include "ui/base/clipboard/scoped_clipboard_writer.h"
#include "third_party/libnode/src/node_buffer.h"
#include "base/threading/thread_local.h"
#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"
#include "base/containers/contains.h"
#include <vector>

namespace atom {

THREAD_LOCAL_CONSTRUCTOR(Clipboard)

class Clipboard : public mate::EventEmitter<Clipboard> {
public:
    Clipboard(v8::Isolate* isolate, v8::Local<v8::Object> wrapper)
    {
        gin_helper::Wrappable<Clipboard>::InitWith(isolate, wrapper);
    }

    static void init(v8::Isolate* isolate, v8::Local<v8::Object> target)
    {
        v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, newFunction);
        v8::Local<v8::Context> context = isolate->GetCurrentContext();

        prototype->SetClassName(v8::String::NewFromUtf8(isolate, "Clipboard").ToLocalChecked());
        gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
        builder.SetMethod("_readImage", &Clipboard::_readImageApi);
        builder.SetMethod("_readText", &Clipboard::_readTextApi);
        builder.SetMethod("_writeText", &Clipboard::_writeTextApi);
        builder.SetMethod("_writeImage", &Clipboard::_writeImageApi);
        builder.SetMethod("readBuffer", &Clipboard::readBufferApi);
        builder.SetMethod("writeBuffer", &Clipboard::writeBufferApi);
        builder.SetMethod("availableFormats", &Clipboard::availableFormatsApi);

        builder.SetMethod("has", &Clipboard::hasApi);
        builder.SetMethod("read", &Clipboard::readApi);
        builder.SetMethod("write", &Clipboard::writeApi);
        builder.SetMethod("readRTF", &Clipboard::readRTFApi);
        builder.SetMethod("writeRTF", &Clipboard::writeRTFApi);
        builder.SetMethod("readHTML", &Clipboard::readHTMLApi);
        builder.SetMethod("writeHTML", &Clipboard::writeHTMLApi);
        builder.SetMethod("readBookmark", &Clipboard::readBookmarkApi);
        builder.SetMethod("writeBookmark", &Clipboard::writeBookmarkApi);
        builder.SetMethod("readFindText", &Clipboard::readFindTextApi);
        builder.SetMethod("writeFindText", &Clipboard::writeFindTextApi);
        builder.SetMethod("_clear", &Clipboard::_clearApi);

        getClipboardConstructor().Reset(isolate, prototype->GetFunction(context).ToLocalChecked());
        target->Set(context, v8::String::NewFromUtf8(isolate, "Clipboard").ToLocalChecked(), prototype->GetFunction(context).ToLocalChecked());
    }

    void writeFindTextApi(const std::u16string& text) {}

    std::u16string readFindTextApi() 
    {
        return std::u16string();
    }

    std::u16string readHTMLApi(gin_helper::Arguments* args)
    {
        std::u16string data;
        std::u16string html;
        std::string url;
        uint32_t start;
        uint32_t end;
        ui::Clipboard* clipboard = ui::Clipboard::GetForCurrentThread();
        clipboard->ReadHTML(/*GetClipboardBuffer(args)*/ui::ClipboardBuffer::kCopyPaste, /* data_dst = */ nullptr, &html, &url, &start, &end);
        data = html.substr(start, end - start);
        return data;
    }

    void Clipboard::writeHTMLApi(const std::u16string& html, gin_helper::Arguments* args)
    {
        ui::ScopedClipboardWriter writer(/*GetClipboardBuffer(args)*/ui::ClipboardBuffer::kCopyPaste);
        writer.WriteHTML(html, std::string());
    }

    v8::Local<v8::Value> readBookmarkApi(gin_helper::Arguments* args)
    {
        std::u16string title;
        std::string url;
        auto dict = gin_helper::Dictionary::CreateEmpty(args->isolate());
        ui::Clipboard* clipboard = ui::Clipboard::GetForCurrentThread();
        clipboard->ReadBookmark(/* data_dst = */ nullptr, &title, &url);
        dict.Set("title", title);
        dict.Set("url", url);
        return dict.GetHandle();
    }

    void writeBookmarkApi(const std::u16string& title, const std::string& url, gin_helper::Arguments* args)
    {
        ui::ScopedClipboardWriter writer(/*GetClipboardBuffer(args)*/ui::ClipboardBuffer::kCopyPaste);
        writer.WriteBookmark(title, url);
    }

    void writeRTFApi(const std::string& text, gin_helper::Arguments* args) 
    {
        ui::ScopedClipboardWriter writer(/*GetClipboardBuffer(args)*/ui::ClipboardBuffer::kCopyPaste);
        writer.WriteRTF(text);
    }

    std::u16string Clipboard::readRTFApi()
    {
        std::string data;
        ui::Clipboard* clipboard = ui::Clipboard::GetForCurrentThread();
        clipboard->ReadRTF(/*GetClipboardBuffer(args)*/ui::ClipboardBuffer::kCopyPaste, /* data_dst = */ nullptr, &data);
        return base::UTF8ToUTF16(data);
    }

    std::string readApi(const std::string& formatSstring)
    {
        return readImpl(formatSstring);
    }

    void writeApi(v8::Local<v8::Object> object)
    {
        gin_helper::Dictionary data(v8::Isolate::GetCurrent(), object);
        writeImpl(data);
    }

    void writeImpl(const gin_helper::Dictionary& data)
    {
        ui::ScopedClipboardWriter writer(ui::ClipboardBuffer::kCopyPaste/*GetClipboardBuffer(args)*/);
        std::u16string text, html, bookmark;
#if 0
        gfx::Image image;
#endif

        if (data.Get("text", &text)) {
            writer.WriteText(text);

            if (data.Get("bookmark", &bookmark))
                writer.WriteBookmark(bookmark, base::UTF16ToUTF8(text));
        }

        if (data.Get("rtf", &text)) {
            std::string rtf = base::UTF16ToUTF8(text);
            writer.WriteRTF(rtf);
        }

        if (data.Get("html", &html))
            writer.WriteHTML(html, std::string());
#if 0
        if (data.Get("image", &image))
            writer.WriteImage(image.AsBitmap());
#endif
    }

    bool hasApi(const std::string& formatSstring)
    {
        ui::Clipboard* clipboard = ui::Clipboard::GetForCurrentThread();
        ui::ClipboardFormatType format(ui::ClipboardFormatType::GetType(formatSstring));
        if (format.GetName().empty())
            format = ui::ClipboardFormatType::CustomPlatformType(formatSstring);
        return clipboard->IsFormatAvailable(format, ui::ClipboardBuffer::kCopyPaste, /* data_dst = */ nullptr);
    }

    void _clearApi(const std::string& type)
    {
        ::OpenClipboard(NULL);
        ::EmptyClipboard();
        ::CloseClipboard();
    }

    std::vector<std::u16string> availableFormatsApi()
    {
        std::vector<std::u16string> formatTypes;
        ui::Clipboard* clipboard = ui::Clipboard::GetForCurrentThread();
        clipboard->ReadAvailableTypes(/*GetClipboardBuffer(args)*/ ui::ClipboardBuffer::kCopyPaste, /* data_dst = */ nullptr, &formatTypes);
        return formatTypes;
    }

    std::string readImpl(const std::string& formatSstring)
    {
        ui::Clipboard* clipboard = ui::Clipboard::GetForCurrentThread();
        // Prefer raw platform format names
        ui::ClipboardFormatType rawFormat(ui::ClipboardFormatType::CustomPlatformType(formatSstring));
        bool rawFormatAvailable = clipboard->IsFormatAvailable(rawFormat, ui::ClipboardBuffer::kCopyPaste, /* data_dst = */ nullptr);
#if BUILDFLAG(IS_LINUX)
        if (!rawFormatAvailable) {
            rawFormatAvailable = clipboard->IsFormatAvailable(rawFormat, ui::ClipboardBuffer::kSelection, /* data_dst = */ nullptr);
        }
#endif
        if (rawFormatAvailable) {
            std::string data;
            clipboard->ReadData(rawFormat, /* data_dst = */ nullptr, &data);
            return data;
        }
        // Otherwise, resolve custom format names
        std::map<std::string, std::string> customFormatNames;
        customFormatNames = clipboard->ExtractCustomPlatformNames(ui::ClipboardBuffer::kCopyPaste, /* data_dst = */ nullptr);
#if BUILDFLAG(IS_LINUX)
        if (!base::Contains(customFormatNames, formatSstring)) {
            customFormatNames = clipboard->ExtractCustomPlatformNames(ui::ClipboardBuffer::kSelection, /* data_dst = */ nullptr);
        }
#endif

        ui::ClipboardFormatType format;
        if (base::Contains(customFormatNames, formatSstring)) {
            format = ui::ClipboardFormatType(ui::ClipboardFormatType::CustomPlatformType(customFormatNames[formatSstring]));
        } else {
            format = ui::ClipboardFormatType(ui::ClipboardFormatType::CustomPlatformType(formatSstring));
        }
        std::string data;
        clipboard->ReadData(format, /* data_dst = */ nullptr, &data);
        return data;
    }

    v8::Local<v8::Value> readBufferApi(const std::string& formatSstring, gin_helper::Arguments* args) 
    {
        std::string data = readImpl(formatSstring);
        return node::Buffer::Copy(args->isolate(), data.data(), data.length()).ToLocalChecked();
    }

    void Clipboard::writeBufferApi(const std::string& format, const v8::Local<v8::Value> buffer)
    {
        v8::Isolate* isolate = v8::Isolate::GetCurrent();
        if (!node::Buffer::HasInstance(buffer)) {
            isolate->ThrowError("buffer must be a node Buffer");
            return;
        }

        CHECK(buffer->IsArrayBufferView());
        v8::Local<v8::ArrayBufferView> buffer_view = buffer.As<v8::ArrayBufferView>();
        const size_t n_bytes = buffer_view->ByteLength();
        mojo_base::BigBuffer big_buffer{ n_bytes };
        [[maybe_unused]] const size_t n_got = buffer_view->CopyContents(big_buffer.data(), n_bytes);
        DCHECK_EQ(n_got, n_bytes);

        ui::ScopedClipboardWriter writer(/*GetClipboardBuffer(args)*/ui::ClipboardBuffer::kCopyPaste);
        writer.WriteData(base::UTF8ToUTF16(format), std::move(big_buffer));
    }

    void _writeImageApi(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        v8::Isolate* isolate = args.GetIsolate();
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        NativeImage* nativeImage = nullptr;
        if (args[0]->IsObject()) {
            v8::Local<v8::Object> handle = args[0]->ToObject(context).ToLocalChecked();
            nativeImage = NativeImage::GetSelf(handle);
        }
        if (!nativeImage)
            return;

        std::string type;
        if (args[1]->IsString()) {
            v8::Local<v8::String> str = args[0]->ToString(context).ToLocalChecked();
            v8::String::Utf8Value stringUtf8(isolate, str);
            if (0 != stringUtf8.length())
                type.assign(*stringUtf8);
        }

        HBITMAP sourceBitmap = nativeImage->getBitmap();
        int width = nativeImage->getWidth();
        int height = nativeImage->getHeight();
        if (!sourceBitmap || 0 == width || 0 == height)
            return;

        ::EmptyClipboard();

        HDC dc = ::GetDC(NULL);
        HDC compatibleDC = ::CreateCompatibleDC(NULL);
        HDC sourceDC = ::CreateCompatibleDC(NULL);

        // This is the HBITMAP we will eventually write to the clipboard
        HBITMAP hbitmap = ::CreateCompatibleBitmap(dc, width, height);
        if (!hbitmap) {
            // Failed to create the bitmap
            ::DeleteDC(compatibleDC);
            ::DeleteDC(sourceDC);
            ::ReleaseDC(NULL, dc);
            return;
        }

        HBITMAP oldBitmap = (HBITMAP)SelectObject(compatibleDC, hbitmap);
        HBITMAP oldSource = (HBITMAP)SelectObject(sourceDC, sourceBitmap);

        // Now we need to blend it into an HBITMAP we can place on the clipboard
        BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
        ::GdiAlphaBlend(compatibleDC, 0, 0, width, height, sourceDC, 0, 0, width, height, bf);

        // Clean up all the handles we just opened
        ::SelectObject(compatibleDC, oldBitmap);
        ::SelectObject(sourceDC, oldSource);
        ::DeleteObject(oldBitmap);
        ::DeleteObject(oldSource);
        ::DeleteDC(compatibleDC);
        ::DeleteDC(sourceDC);
        ::ReleaseDC(NULL, dc);

        ::OpenClipboard(NULL);
        ::SetClipboardData(CF_BITMAP, hbitmap);
        ::CloseClipboard();
    }

    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        v8::Isolate* isolate = args.GetIsolate();
        if (args.IsConstructCall()) {
            new Clipboard(isolate, args.This());
            args.GetReturnValue().Set(args.This());
            return;
        }
    }

    std::string _readTextApi(const std::string& type)
    {
        if (!::OpenClipboard(nullptr))
            return std::string();

        HANDLE data = ::GetClipboardData(CF_UNICODETEXT);
        if (!data) {
            ::CloseClipboard();
            return std::string();
        }

        LPCWSTR dataText = (LPCWSTR)::GlobalLock(data);
        std::wstring text(dataText, wcslen(dataText));
        ::GlobalUnlock(data);

        ::CloseClipboard();
        return base::WideToUTF8(text);
    }

    void _writeTextApi(const std::string& text, const std::string& type)
    {
        if (0 == text.size())
            return;

        std::u16string strW(base::UTF8ToUTF16(text));
        HGLOBAL data = ::GlobalAlloc(GMEM_MOVEABLE, ((strW.size() + 1) * sizeof(wchar_t)));
        if (!data)
            return;

        wchar_t* rawData = static_cast<wchar_t*>(::GlobalLock(data));
        memcpy(rawData, &strW[0], strW.size() * sizeof(wchar_t));
        rawData[strW.size()] = L'\0';
        ::GlobalUnlock(data);

        ::EmptyClipboard();

        if (!::OpenClipboard(nullptr))
            return;
        ::SetClipboardData(CF_UNICODETEXT, data);
        ::CloseClipboard();
    }

    v8::Local<v8::Object> readImage(const std::string& type)
    {
        if (!::OpenClipboard(nullptr))
            return NativeImage::createEmpty(isolate());

        HANDLE hBitmap = ::GetClipboardData(CF_DIB);
        if (!hBitmap) {
            ::CloseClipboard();
            return NativeImage::createEmpty(isolate());
        }

        BITMAPINFO* bitmap = static_cast<BITMAPINFO*>(::GlobalLock(hBitmap));
        if (!bitmap) {
            ::CloseClipboard();
            return NativeImage::createEmpty(isolate());
        }
        int colorTableLength = 0;
        switch (bitmap->bmiHeader.biBitCount) {
        case 1:
        case 4:
        case 8:
            colorTableLength = bitmap->bmiHeader.biClrUsed ? bitmap->bmiHeader.biClrUsed : 1 << bitmap->bmiHeader.biBitCount;
            break;
        case 16:
        case 32:
            if (bitmap->bmiHeader.biCompression == BI_BITFIELDS)
                colorTableLength = 3;
            break;
        case 24:
            break;
        default:
            DebugBreak();
        }
        void* bitmapBits = reinterpret_cast<char*>(bitmap) + bitmap->bmiHeader.biSize + colorTableLength * sizeof(RGBQUAD);
        size_t size = bitmap->bmiHeader.biWidth * bitmap->bmiHeader.biHeight * 4;
        v8::Local<v8::Object> obj = NativeImage::createFromBITMAPINFO(isolate(), bitmap, bitmapBits);
        ::GlobalUnlock(hBitmap);
        ::CloseClipboard();
        return obj;
    }

    v8::Local<v8::Object> _readImageApi(const std::string& type)
    {
        return readImage(type);
    }

public:
    static gin_helper::WrapperInfo kWrapperInfo;
};
gin_helper::WrapperInfo Clipboard::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };

void initializeClipboardApi(v8::Local<v8::Object> exports, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, void* priv)
{
    Clipboard::init(context->GetIsolate(), exports);
}

} // atom namespace

static const char CommonClipboardNative[] = "console.log('CommonClipboardNative');;";
static NodeNative nativeCommonClipboard { "Clipboard", CommonClipboardNative, sizeof(CommonClipboardNative) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_common_clipboard, atom::initializeClipboardApi, &nativeCommonClipboard)
