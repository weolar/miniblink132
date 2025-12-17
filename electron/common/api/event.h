// Copyright (c) 2014 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_BROWSER_API_EVENT_H_
#define ATOM_BROWSER_API_EVENT_H_

#include "electron/common/gin_helper/wrappable.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "base/containers/span.h"
#include <functional>
#include <windows.h>

namespace mate {

class Event : public gin_helper::Wrappable<Event> {
public:
    static gin_helper::WrapperInfo kWrapperInfo;
    static Event* create(v8::Isolate* isolate, v8::Local<v8::Object> wrapper, std::function<void(base::span<const uint8_t>)>&& callback);

    static void init(v8::Isolate* isolate);
    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args);

    // event.PreventDefault().
    void preventDefault(v8::Isolate* isolate);

    // event.sendReply(json), used for replying synchronous message.
    bool sendReply(const v8::FunctionCallbackInfo<v8::Value>& info);
    //std::vector<char> returnValueGet();
    //void returnValueSet(const base::span<const uint8_t>& json);

protected:
    explicit Event(v8::Isolate* isolate, v8::Local<v8::Object> wrapper);
    ~Event() override;

private:
    //static v8::Persistent<v8::Function> constructor;
    static DWORD constructorTlsKey;
    DISALLOW_COPY_AND_ASSIGN(Event);
    std::function<void(base::span<const uint8_t>)>* m_callback;

    //std::vector<char> m_returnValue;
};

} // namespace mate

#endif // ATOM_BROWSER_API_EVENT_H_
