// Copyright (c) 2014 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/nodeblink.h"

#include "electron/common/asar/Archive.h"
#include "electron/common/asar/AsarUtil.h"
#include "electron/common/asar/AsarJs.h"
#include "electron/common/asar/AsarInitJs.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/gin_helper/wrappable.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/libnode/src/node_version.h"
#include "third_party/libuv/include/uv.h"
#include "base/strings/string_util.h"
#include "base/threading/thread_local.h"
#include <vector>
#pragma clang optimize off

namespace node {
bool g_disable_has_run_bootstrapping_code_error = false;
}

namespace atom {

THREAD_LOCAL_CONSTRUCTOR(V8Archive)

class V8Archive : public gin_helper::Wrappable<V8Archive> {
public:
    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        v8::Isolate* isolate = args.GetIsolate();
        if (!args.IsConstructCall()) {
            args.GetReturnValue().Set(v8::False(isolate));
            return;
        }

        new V8Archive(isolate, args.This() /*, std::move(archive)*/);
        args.GetReturnValue().Set(args.This());
    }

    bool init(const std::string& pathString)
    {
        std::string pathStr = pathString;
        if (base::StartsWith(pathString, "file:", base::CompareCase::INSENSITIVE_ASCII)) {
            pathStr = pathString.substr(5, std::string::npos);
#ifdef _WIN32
            do {
                if (pathStr.size() >= 2 && (pathStr[0] == '\\' || pathStr[0] == '/')) {
                    pathStr = pathStr.substr(1, std::string::npos);
                } else
                    break;
            } while (true);
#endif // _WIN32
        }

        base::FilePath path = base::FilePath::FromUTF8Unsafe((pathStr));
        std::unique_ptr<asar::Archive> archive(new asar::Archive(path));
        if (!archive->Init())
            return false;

        m_archive = std::move(archive);
        return true;
    }

    static void buildPrototype(v8::Isolate* isolate, v8::Local<v8::Object> target)
    {
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, newFunction);
        prototype->SetClassName(v8::String::NewFromUtf8(isolate, "Archive").ToLocalChecked());

        gin_helper::ObjectTemplateBuilder(isolate, prototype->InstanceTemplate())
            .SetMethod("init", &V8Archive::init)
            .SetMethod("path", &V8Archive::getPath)
            .SetMethod("getFileInfo", &V8Archive::getFileInfo)
            .SetMethod("stat", &V8Archive::stat)
            .SetMethod("readdir", &V8Archive::readdir)
            .SetMethod("realpath", &V8Archive::realpath)
            .SetMethod("copyFileOut", &V8Archive::copyFileOut)
            .SetMethod("getFd", &V8Archive::getFD)
            .SetMethod("destroy", &V8Archive::destroy)
            .SetMethod("readJSON", &V8Archive::readJSON);

        getV8ArchiveConstructor().Reset(isolate, prototype->GetFunction(context).ToLocalChecked());
        target->Set(context, v8::String::NewFromUtf8(isolate, "Archive").ToLocalChecked(), prototype->GetFunction(context).ToLocalChecked());
    }

protected:
    V8Archive(v8::Isolate* isolate, v8::Local<v8::Object> wrapper /*, std::unique_ptr<asar::Archive> archive*/)
        : m_archive(nullptr /*std::move(archive)*/)
    {
        gin_helper::Wrappable<V8Archive>::InitWith(isolate, wrapper);
    }

    // Returns the path of the file.
    std::string getPath()
    {
        return m_archive->path().AsUTF8Unsafe();
    }

    // Reads the offset and size of file.
    v8::Local<v8::Value> getFileInfo(const std::string& pathString)
    {
        base::FilePath path = base::FilePath::FromUTF8Unsafe((pathString));
        asar::Archive::FileInfo info;
        if (!m_archive || !m_archive->GetFileInfo(path, &info))
            return v8::False(isolate());
        gin_helper::Dictionary dict(isolate(), v8::Object::New(isolate()));
        dict.Set("size", info.size);
        dict.Set("unpacked", info.unpacked);
        dict.Set("offset", info.offset);
        return dict.GetHandle();
    }

    // look: W:\mycode\mb108\third_party\libnode\src\node_file.cc, InternalModuleReadJSON
    v8::Local<v8::Value> readJSON(const std::string& chars, const std::string& filapath)
    {
        int64_t offset = chars.size();
        size_t start = 0;
        if (offset >= 3 && 0 == memcmp(chars.data(), "\xEF\xBB\xBF", 3)) {
            start = 3; // Skip UTF-8 BOM.
        }
        const size_t size = offset - start;

        // TODO(anonrig): Follow-up on removing the following changes for AIX.
        const char* p = &chars[start];
        const char* pe = &chars[size];
        const char* pos[2];
        const char** ppos = &pos[0];

        while (p < pe) {
            char c = *p++;
            if (c == '\\' && p < pe && *p == '"')
                p++;
            if (c != '"')
                continue;
            *ppos++ = p;
            if (ppos < &pos[2])
                continue;
            ppos = &pos[0];

            const char* s = &pos[0][0];
            const char* se = &pos[1][-1]; // Exclude quote.
            size_t n = se - s;

            if (n == 4) {
                if (0 == memcmp(s, "main", 4))
                    break;
                if (0 == memcmp(s, "name", 4))
                    break;
                if (0 == memcmp(s, "type", 4))
                    break;
            } else if (n == 7) {
                if (0 == memcmp(s, "exports", 7))
                    break;
                if (0 == memcmp(s, "imports", 7))
                    break;
            }
        }

        v8::Local<v8::Value> return_value[2] = { v8::String::NewFromUtf8(isolate(), &chars[start], v8::NewStringType::kNormal, size).ToLocalChecked(),
            v8::Boolean::New(isolate(), p < pe ? true : false) };

        return (v8::Array::New(isolate(), return_value, arraysize(return_value)));
    }

    // Returns a fake result of fs.stat(path).
    v8::Local<v8::Value> stat(const std::string& pathString)
    {
        base::FilePath path = base::FilePath::FromUTF8Unsafe((pathString));
        asar::Archive::Stats stats;
        if (!m_archive || !m_archive->Stat(path, &stats)) {
            //             char* output = (char*)malloc(400);
            //             sprintf_s(output, 399, "stat fail: %s\n", path.AsUTF8Unsafe().c_str());
            //             OutputDebugStringA(output);
            //             free(output);
            return v8::False(isolate());
        }
        gin_helper::Dictionary dict(isolate(), v8::Object::New(isolate()));
        dict.Set("size", stats.size);
        dict.Set("offset", stats.offset);
        dict.Set("isFile", stats.is_file);
        dict.Set("isDirectory", stats.is_directory);
        dict.Set("isLink", stats.is_link);
        return dict.GetHandle();
    }

    // Returns all files under a directory.
    v8::Local<v8::Value> readdir(const std::string& pathString)
    {
        base::FilePath path = base::FilePath::FromUTF8Unsafe((pathString));
        std::vector<base::FilePath> files;
        if (!m_archive || !m_archive->Readdir(path, &files))
            return v8::False(isolate());

        v8::Local<v8::Context> context = isolate()->GetCurrentContext();
        v8::Local<v8::Array> v8Arr = v8::Array::New(isolate(), files.size());
        for (size_t i = 0; i < files.size(); ++i) {
            const base::FilePath& pathIt = files[i];
            std::string pathItString = pathIt.AsUTF8Unsafe();
            v8Arr->Set(context, i, v8::String::NewFromUtf8(isolate(), pathItString.c_str(), v8::NewStringType::kNormal, pathItString.size()).ToLocalChecked());
        }
        return v8Arr;
    }

    // Returns the path of file with symbol link resolved.
    v8::Local<v8::Value> realpath(const std::string& pathString)
    {
        base::FilePath path = base::FilePath::FromUTF8Unsafe((pathString));
        base::FilePath realpath;
        if (!m_archive || !m_archive->Realpath(path, &realpath))
            return v8::False(isolate());

        std::string realpathString = realpath.AsUTF8Unsafe();
        return v8::String::NewFromUtf8(isolate(), realpathString.c_str(), v8::NewStringType::kNormal, realpathString.size()).ToLocalChecked();
    }

    // Copy the file out into a temporary file and returns the new path.
    v8::Local<v8::Value> copyFileOut(const std::string& pathString)
    {
        base::FilePath path = base::FilePath::FromUTF8Unsafe((pathString));
        base::FilePath newPath;
        if (!m_archive || !m_archive->CopyFileOut(path, &newPath))
            return v8::False(isolate());
        std::string newPathString = newPath.AsUTF8Unsafe();
        return v8::String::NewFromUtf8(isolate(), newPathString.c_str(), v8::NewStringType::kNormal, newPathString.size()).ToLocalChecked();
    }

    // Return the file descriptor.
    int getFD() const
    {
        if (!m_archive)
            return -1;
        return m_archive->GetFD();
    }

    // Free the resources used by archive.
    void destroy()
    {
        m_archive.reset();
    }

private:
    std::unique_ptr<asar::Archive> m_archive;

public:
    static gin_helper::WrapperInfo kWrapperInfo;
    DISALLOW_COPY_AND_ASSIGN(V8Archive);
};

gin_helper::WrapperInfo V8Archive::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };

// »¹µÃ¸ÄW:\mycode\mb132\third_party\libnode\src\node_builtins.cc
#define FAKE_ASAR 0

void initAsarSupport(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    v8::Local<v8::Value> process = info[0];
    v8::Local<v8::Value> require = info[1];
    // Evaluate asar_init.coffee.
    std::string buffer;

#if FAKE_ASAR
    asar::readFileToString(base::FilePath::FromUTF8Unsafe("W:\\mycode\\mb132\\electron\\lib\\common\\asar_init.js"), &buffer);
    const char* asarInitNative = &buffer.at(0);
    size_t asarInitNativeLength = buffer.size();
#else
    const char* asarInitNative = atom::AsarInitJs;
    size_t asarInitNativeLength = sizeof(atom::AsarInitJs);
#endif
    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

    v8::MaybeLocal<v8::Script> script
        = v8::Script::Compile(context, v8::String::NewFromUtf8(isolate, asarInitNative, v8::NewStringType::kNormal, asarInitNativeLength).ToLocalChecked());
    v8::Local<v8::Script> asar_init = script.ToLocalChecked();
    v8::Local<v8::Value> result = asar_init->Run(context).ToLocalChecked();
    if (!result->IsFunction())
        return;

    v8::Function* resultFunc = v8::Function::Cast(*result);

#if FAKE_ASAR
    asar::readFileToString(base::FilePath::FromUTF8Unsafe("W:\\mycode\\mb132\\electron\\lib\\common\\asar.js"), &buffer);
    v8::Local<v8::String> asarNativeV8 = v8::String::NewFromUtf8(isolate, &buffer.at(0), v8::NewStringType::kNormal, buffer.size()).ToLocalChecked();
#else
    v8::Local<v8::String> asarNativeV8 = v8::String::NewFromUtf8(isolate, (const char*)AsarJs, v8::NewStringType::kNormal, AsarJsLength - 1).ToLocalChecked();
#endif
    v8::Local<v8::Value> vals[] = { process, require, asarNativeV8 };

    node::g_disable_has_run_bootstrapping_code_error = true;
    // Initialize asar support.
    v8::MaybeLocal<v8::Value> ret = resultFunc->Call(isolate->GetCurrentContext(), v8::Undefined(isolate), 3, vals);
    node::g_disable_has_run_bootstrapping_code_error = false;
}

void initializeAsarApi(v8::Local<v8::Object> exports, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, void* priv)
{
    v8::Isolate* isolate = context->GetIsolate();
    gin_helper::Dictionary dict(isolate, exports);
    //dict.SetMethod("createArchive", &V8Archive::newFunction);
    dict.SetMethod("initAsarSupport", &initAsarSupport);

    V8Archive::buildPrototype(isolate, exports);
}

} // atom namespace

static const char CommonAsarNative[] = "console.log('CommonAsarNative');;";
static NodeNative nativeCommonAsarNative { "Asar", CommonAsarNative, sizeof(CommonAsarNative) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_common_asar, atom::initializeAsarApi, &nativeCommonAsarNative)
