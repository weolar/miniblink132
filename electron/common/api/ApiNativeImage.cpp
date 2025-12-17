// Copyright (c) 2014 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/common/api/ApiNativeImage.h"

#include "electron/nodeblink.h"
#include "electron/common/asar/Archive.h"
#include "electron/common/asar/AsarUtil.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/gin_helper/wrappable.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "electron/common/InitGdiPlus.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/libnode/src/node_buffer.h"
#include "third_party/libnode/src/node_version.h"
#include "third_party/libuv/include/uv.h"
#include "base/strings/string_util.h"
#include "base/threading/thread_local.h"
#include "mbvip/core/mb.h"

#undef min
#undef max
using std::max;
using std::min;

#include <Unknwn.h>
#include <gdiplus.h>
#include <objidl.h>
#include <vector>

namespace atom {

THREAD_LOCAL_CONSTRUCTOR(NativeImage)

typedef mbMemBuf*(MB_CALL_TYPE* FN_mbEncodeBase64)(const char* data, unsigned len, int policy);

NativeImage::NativeImage(v8::Isolate* isolate, v8::Local<v8::Object> wrapper)
{
    m_gdipBitmap = nullptr;
    gin_helper::Wrappable<NativeImage>::InitWith(isolate, wrapper);
}

void NativeImage::init(v8::Isolate* isolate, v8::Local<v8::Object> target)
{
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, newFunction);

    prototype->SetClassName(v8::String::NewFromUtf8(isolate, "NativeImage").ToLocalChecked());
    gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
    builder.SetMethod("toPNG", &NativeImage::toPNGAPI);
    builder.SetMethod("toDataURL", &NativeImage::toDataURLApi);

    getNativeImageConstructor().Reset(isolate, prototype->GetFunction(context).ToLocalChecked());
    target->Set(context, v8::String::NewFromUtf8(isolate, "NativeImage").ToLocalChecked(), prototype->GetFunction(context).ToLocalChecked());

    gin_helper::Dictionary nativeImageClass(isolate, prototype->GetFunction(context).ToLocalChecked());
    nativeImageClass.SetMethod("createEmpty", &NativeImage::createEmptyApi);
    nativeImageClass.SetMethod("createFromPath", &NativeImage::createFromPathApi);
}

std::vector<unsigned char>* NativeImage::encodeToBuffer(const CLSID* clsid)
{
    IStream* pIStream = nullptr;

    std::vector<unsigned char>* output = nullptr;
    bool ok = false;
    HRESULT hr = ::CreateStreamOnHGlobal(NULL, true, &pIStream);
    if (S_OK != hr)
        return nullptr;
    Gdiplus::Status status = m_gdipBitmap->Save(pIStream, clsid, NULL);

    LARGE_INTEGER liTemp = { 0 };
    pIStream->Seek(liTemp, STREAM_SEEK_SET, NULL);
    DWORD dwSize = 0;
    STATSTG stats = { 0 };
    pIStream->Stat(&stats, 0);

    do {
        if (0 == stats.cbSize.QuadPart || stats.cbSize.QuadPart > 2024 * 2024)
            break;

        dwSize = (DWORD)stats.cbSize.QuadPart;
        output = new std::vector<unsigned char>();
        output->resize(dwSize);

        ULONG readSize = 0;
        hr = pIStream->Read(output->data(), dwSize, &readSize);
        ok = (S_OK == hr);
    } while (false);

    if (!ok && output) {
        delete output;
        output = nullptr;
    }

    if (pIStream)
        pIStream->Release();

    return output;
}

v8::Local<v8::Object> NativeImage::toPNGAPI(const base::Value::Dict& args)
{
    //double scaleFactor = 1.0;
    //absl::optional<double> scaleFactorOpt = args.FindDouble("scaleFactor");

    std::vector<unsigned char>* output = encodeToBuffer(&s_pngClsid);
    if (!output)
        return v8::Local<v8::Object>();

    const char* data = reinterpret_cast<const char*>(output->data());
    size_t size = output->size();
    v8::Local<v8::Object> result = node::Buffer::Copy(isolate(), data, size).ToLocalChecked();

    delete output;

    return result;
}

v8::Local<v8::Object> NativeImage::toJpeg(const base::Value::Dict& args)
{
    //     int quality = 100;
    //     args.GetInteger("quality", &quality);

    std::vector<unsigned char>* output = encodeToBuffer(&s_jpgClsid);
    if (!output)
        return v8::Local<v8::Object>();

    const char* data = reinterpret_cast<const char*>(output->data());
    size_t size = output->size();
    v8::Local<v8::Object> result = node::Buffer::Copy(isolate(), data, size).ToLocalChecked();
    delete output;

    return result;
}

v8::Local<v8::Object> NativeImage::toBitmap(const base::Value::Dict& args)
{
    //     int quality = 100;
    //     args.GetInteger("quality", &quality);

    UINT w = m_gdipBitmap->GetWidth();
    UINT h = m_gdipBitmap->GetHeight();

    Gdiplus::Rect rect(0, 0, w, h);
    Gdiplus::BitmapData lockedBitmapData;
    m_gdipBitmap->LockBits(
#if USING_VC6RT != 1
        &
#endif
        rect,
        Gdiplus::ImageLockModeRead, PixelFormat32bppARGB, &lockedBitmapData);

    v8::Local<v8::Object> result;
    const char* data = reinterpret_cast<const char*>(lockedBitmapData.Scan0);
    if (!data)
        return result;

    int stride = lockedBitmapData.Stride;
    size_t size = w * stride / 4 + h;
    result = node::Buffer::Copy(isolate(), data, size).ToLocalChecked();

    return result;
}

v8::Local<v8::Object> NativeImage::createEmpty(v8::Isolate* isolate)
{
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Function> constructorFunction = v8::Local<v8::Function>::New(isolate, getNativeImageConstructor());
    v8::Local<v8::Object> obj = constructorFunction->NewInstance(context).ToLocalChecked();

    NativeImage* self = (NativeImage*)WrappableBase::GetNativePtr(obj, &kWrapperInfo);
    return obj;
}

void NativeImage::createEmptyApi(const v8::FunctionCallbackInfo<v8::Value> info)
{
    info.GetReturnValue().Set(createEmpty(info.GetIsolate()));
}

void NativeImage::createFromPathApi(const v8::FunctionCallbackInfo<v8::Value> info /*v8::Isolate* isolate, const std::string& path*/)
{
    std::string fileContents;
    std::string path;
    if (info.Length() == 1 && info[0]->IsString()) {
        v8::String::Utf8Value pathString(info.GetIsolate(), info[0]);
        path = *pathString;
    }

    if (0 == path.size() || !asar::readFileToString(base::FilePath::FromUTF8Unsafe(path), &fileContents))
        return;

    const unsigned char* data = reinterpret_cast<const unsigned char*>(fileContents.data());
    size_t size = fileContents.size();

    v8::Local<v8::Object> obj = createNativeImageFromBuffer(info.GetIsolate(), data, size);
    info.GetReturnValue().Set(obj);
}

void NativeImage::createFromBufferApi(const v8::FunctionCallbackInfo<v8::Value> info)
{
    v8::Isolate* isolate = info.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Value> buffer;
    v8::Local<v8::Object> resultObj;
    if (info.Length() == 1) {
        buffer = info[0];
        if (!buffer->IsUint8Array()) {
            info.GetReturnValue().Set(resultObj);
            return;
        }
    }
    int width = 0;
    int height = 0;
    double scaleFactor = 1.0;
    if (info.Length() == 2 && info[1]->IsObject()) {
        gin_helper::Dictionary options(isolate, info[1]->ToObject(context).ToLocalChecked());
        options.GetBydefaultVal("width", width, &width);
        options.GetBydefaultVal("height", height, &height);
        options.GetBydefaultVal("scaleFactor", scaleFactor, &scaleFactor);
    }

    unsigned char* data = reinterpret_cast<unsigned char*>(node::Buffer::Data(buffer));
    size_t size = node::Buffer::Length(buffer);

    resultObj = createNativeImageFromBuffer(isolate, data, size);
    info.GetReturnValue().Set(resultObj);
}

v8::Local<v8::Object> NativeImage::createFromBITMAPINFO(v8::Isolate* isolate, const BITMAPINFO* gdiBitmapInfo, void* gdiBitmapData)
{
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Function> constructorFunction = v8::Local<v8::Function>::New(isolate, getNativeImageConstructor());
    v8::Local<v8::Object> resultObj = constructorFunction->NewInstance(context).ToLocalChecked();
    NativeImage* self = (NativeImage*)WrappableBase::GetNativePtr(resultObj, &NativeImage::kWrapperInfo);

    Gdiplus::Bitmap* gdipBitmap = Gdiplus::Bitmap::FromBITMAPINFO(gdiBitmapInfo, gdiBitmapData);
    if (!gdipBitmap)
        return v8::Local<v8::Object>();

    UINT w = gdipBitmap->GetWidth();
    UINT h = gdipBitmap->GetHeight();
    Gdiplus::Rect rect(0, 0, w, h);
    self->m_gdipBitmap = gdipBitmap->Clone(rect, PixelFormat32bppARGB); // 这个要复制一份，不然好像外面的bitmap销毁，这个bitmap也没了
    delete gdipBitmap;

    return resultObj;
}

void NativeImage::createFromBufferImpl(const unsigned char* data, size_t size)
{
    HGLOBAL memHandle = ::GlobalAlloc(GMEM_FIXED, size);
    BYTE* pMem = (BYTE*)::GlobalLock(memHandle);
    memcpy(pMem, data, size);
    ::GlobalUnlock(memHandle);

    IStream* istream = nullptr;
    ::CreateStreamOnHGlobal(memHandle, FALSE, &istream);
    m_gdipBitmap = Gdiplus::Bitmap::FromStream(istream);

    if (memHandle)
        ::GlobalFree(memHandle);

    if (istream)
        istream->Release();
}

v8::Local<v8::Object> NativeImage::createNativeImageFromBuffer(v8::Isolate* isolate, const unsigned char* data, size_t size)
{
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Function> constructorFunction = v8::Local<v8::Function>::New(isolate, getNativeImageConstructor());
    v8::Local<v8::Object> resultObj = constructorFunction->NewInstance(context).ToLocalChecked();
    NativeImage* self = (NativeImage*)WrappableBase::GetNativePtr(resultObj, &NativeImage::kWrapperInfo);
    self->createFromBufferImpl(data, size);

    return resultObj;
}

std::string NativeImage::toDataURLApi()
{
    static FN_mbEncodeBase64 pmbEncodeBase64 = nullptr;
    if (!pmbEncodeBase64)
        pmbEncodeBase64 = (FN_mbEncodeBase64)mbGetProcAddr("mbEncodeBase64");
    if (!m_gdipBitmap)
        return "";
    UINT w = m_gdipBitmap->GetWidth();
    UINT h = m_gdipBitmap->GetHeight();

    Gdiplus::Rect rect(0, 0, w, h);
    std::vector<unsigned char>* output = encodeToBuffer(&s_jpgClsid);
    if (!output)
        return "";
    mbMemBuf* buf = pmbEncodeBase64((const char*)output->data(), output->size(), 0);
    delete output;
    if (!buf)
        return "";

    std::string ret("data:image/jpeg;base64,");
    ret += std::string((const char*)buf->data, buf->length);
    return ret;
}

void NativeImage::newFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    v8::Isolate* isolate = args.GetIsolate();
    if (args.IsConstructCall()) {
        new NativeImage(isolate, args.This());
        args.GetReturnValue().Set(args.This());
        return;
    }
}

NativeImage* NativeImage::GetSelf(v8::Local<v8::Object> handle)
{
    return (NativeImage*)WrappableBase::GetNativePtr(handle, &kWrapperInfo);
}

HICON NativeImage::getIcon()
{
    HICON hIcon = NULL;
    if (m_gdipBitmap)
        m_gdipBitmap->GetHICON(&hIcon);
    return hIcon;
}

HBITMAP NativeImage::getBitmap()
{
    HBITMAP hBitmap = NULL;
    Gdiplus::Color colorBackground = 0xff000000;
    if (m_gdipBitmap)
        m_gdipBitmap->GetHBITMAP(colorBackground, &hBitmap);
    return hBitmap;
}

int NativeImage::getWidth() const
{
    if (m_gdipBitmap)
        return m_gdipBitmap->GetWidth();
    return 0;
}
int NativeImage::getHeight() const
{
    if (m_gdipBitmap)
        return m_gdipBitmap->GetHeight();
    return 0;
}

gin_helper::WrapperInfo NativeImage::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };

void initializeNativeImageApi(v8::Local<v8::Object> exports, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, void* priv)
{
    NativeImage::init(context->GetIsolate(), exports);
}

} // atom namespace

static const char CommonNativeImageNative[] = "console.log('BrowserNativeImageNative');;";
static NodeNative nativeCommonNativeImageNative { "NativeImage", CommonNativeImageNative, sizeof(CommonNativeImageNative) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_common_nativeImage, atom::initializeNativeImageApi, &nativeCommonNativeImageNative)
