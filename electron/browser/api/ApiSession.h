// Copyright (c) 2014 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef electron_browser_api_ApiSession_h
#define electron_browser_api_ApiSession_h

#include "common/api/EventEmitter.h"

#include "mbvip/core/mb.h"
#include "base/files/file_path.h"
#include <vector>
#include <map>

namespace atom {

class ApiWebRequest;
class ProtocolInterface;
class WebContents;

class ApiSession : public mate::EventEmitter<ApiSession> {
public:
    static const char* kDefaultSessionName;
    static const char* kDefaultDir;

    static ApiSession* create(v8::Isolate* isolate, const std::string& name);

    static void init(v8::Isolate* isolate, v8::Local<v8::Object> target);
    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void fromPartitionApi(const v8::FunctionCallbackInfo<v8::Value>& args);

    std::string getPath() const
    {
        return m_path.AsUTF8Unsafe();
    }
    std::string getName() const
    {
        return m_name;
    }

    std::vector<std::string> getPreloadsApi();
    void onLoadUrlBeginInBlinkThread(mbWebView webView, const char* url, void* job);

    mbDownloadOpt onDownloadCallback(WebContents*, mbWebView, size_t, const char*, const char*, const char*, mbNetJob, mbNetJobDataBind*);

private:
    ApiSession(v8::Isolate* isolate, v8::Local<v8::Object> wrapper);
    ~ApiSession();

    void webRequestApi(const v8::FunctionCallbackInfo<v8::Value>& args);
    void protocolApi(const v8::FunctionCallbackInfo<v8::Value>& args);
    void onApi(const v8::FunctionCallbackInfo<v8::Value>& args);
    void setDownloadPathApi(const std::string& path);
    void setPermissionRequestHandlerApi();
    void setPermissionCheckHandlerApi();
    void setDevicePermissionHandlerApi();
    void setPreloadsApi(const std::vector<std::string>& paths);

    void dispatchSendHeaders(mbWebView webView, const char* url, mbNetJob job, v8::Persistent<v8::Value>* persistentCb);

    ApiWebRequest* m_webRequest;
    ProtocolInterface* m_protocol;
    base::FilePath m_path; // 在磁盘存储的路径，如G:\mycode\mb\out\Release\minieleses\default
    std::string m_name; // js设置的name
    v8::Persistent<v8::Object> m_liveSelf;

    std::vector<std::string> m_preloadPaths;

    std::string m_downloadPath;

public:
    static gin::WrapperInfo kWrapperInfo;
    static v8::Persistent<v8::Function> constructor;
};

class SessionMgr {
public:
    static SessionMgr* get();
    ApiSession* findOrCreateSession(v8::Isolate* isolate, const std::string& name, bool createIfNotExist);
    static base::FilePath createSessionDirname(const std::string& name);
    base::FilePath getRootDir() const { return m_rootDir; }

private:
    bool createRootDir();
    SessionMgr();

    CRITICAL_SECTION m_lock;
    std::map<std::string, ApiSession*> m_map;
    base::FilePath m_rootDir; // rootdir/minieleses/ 这个目录

    static SessionMgr* m_inst;
};

} // atom namespace

#endif // electron_browser_api_ApiSession_h
