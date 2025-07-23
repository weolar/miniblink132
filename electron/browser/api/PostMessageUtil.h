#ifndef electron_browser_api_PostMessageUtil_h
#define electron_browser_api_PostMessageUtil_h

#include "v8.h"

namespace mojo {
class Connector;
class Message;
}

namespace atom {

bool isValidWrappable(const v8::Local<v8::Value>& val);
bool v8FunInfoToMojoMessage(const v8::FunctionCallbackInfo<v8::Value>& info, mojo::Message* mojoMessage, std::string* channel);
bool postMessageHelper(mojo::Connector* m_connector, const v8::FunctionCallbackInfo<v8::Value>& info);

// onChannelMessagingApiAcceptHelper的接收消息的字段参考https://mdn.org.cn/en-US/docs/Web/API/Channel_Messaging_API
bool onChannelMessagingApiAcceptHelper(bool inBlinkThread, const std::string& channle, v8::Local<v8::Object> wrap, mojo::Message* mojoMessage);
bool onApiUtilityProcessAcceptHelper(v8::Local<v8::Object> wrap, mojo::Message* mojoMessage);

}

#endif // electron_browser_api_PostMessageUtil_h
