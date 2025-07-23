
#include "electron/common/api/EventEmitter.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include <string>
#include <v8.h>

namespace node {
class Environment;
}

namespace gin_helper {
class Dictionary;
class Arguments;
}

namespace atom {

class ApiWebFrameMain : public mate::EventEmitter<ApiWebFrameMain> {
public:
    static void init(v8::Isolate* isolate, v8::Local<v8::Object> target, node::Environment* env);
    static ApiWebFrameMain* createOrGet(intptr_t frameId);

    void reloadApi();
    v8::Local<v8::Promise> executeJavaScriptApi(gin_helper::Arguments* args, const std::string& code);

    explicit ApiWebFrameMain(v8::Isolate* isolate, v8::Local<v8::Object> wrapper, intptr_t frameId);
    ~ApiWebFrameMain();

    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args);

    intptr_t getFrameTreeNodeIdApi() const;
    std::string getNameApi() const;
    intptr_t getOSProcessIdApi() const;
    intptr_t getRoutingIdApi() const;
    std::string getUrlApi() const;
    std::string getPageVisibilityStateApi() const;
    static void fromIdApi(const v8::FunctionCallbackInfo<v8::Value>& info);
    static void fromIDOrNullApi(const v8::FunctionCallbackInfo<v8::Value>& info);

    v8::Local<v8::Value> getTopApi() const;
    v8::Local<v8::Value> getParentApi() const;
    v8::Local<v8::Value> getFramesApi() const;
    v8::Local<v8::Value> getFramesInSubtreeApi() const;

private:
    static ApiWebFrameMain* create(intptr_t frameId);

public:
    intptr_t m_frameId = 0;

    static gin_helper::WrapperInfo kWrapperInfo;
};

}
