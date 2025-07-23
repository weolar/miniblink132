// Copyright (c) 2014 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/common/api/EventEmitter.h"

#include "electron/common/api/event.h"
#include "electron/common/gin_helper/wrappable.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"

namespace mate {

namespace {

v8::Persistent<v8::ObjectTemplate> eventTemplate;

void preventDefault(gin_helper::Arguments* args)
{
    v8::Local<v8::Object> obj;
    args->GetHolder(&obj);
    gin_helper::Dictionary self(args->isolate(), obj);
    self.Set("defaultPrevented", true);
}

void sendReply(const std::string& json)
{
    //     gin_helper::Dictionary self(args->isolate(), args->GetThis());
    //     self.Set("defaultPrevented", true);
    DebugBreak();
}

// Create a pure JavaScript Event object.
v8::Local<v8::Object> createEventObject(v8::Isolate* isolate)
{
    if (eventTemplate.IsEmpty()) {
        eventTemplate.Reset(
            isolate, gin_helper::ObjectTemplateBuilder(isolate).SetMethod("preventDefault", &preventDefault).SetMethod("sendReply", &sendReply).Build());
    }

    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    return v8::Local<v8::ObjectTemplate>::New(isolate, eventTemplate)->NewInstance(context).ToLocalChecked();
}

} // namespace

namespace internal {

v8::Local<v8::Object> createJSEvent(v8::Isolate* isolate, v8::Local<v8::Object> object)
{
    v8::Local<v8::Object> event = createEventObject(isolate);
    gin_helper::Dictionary(isolate, event).Set("sender", object);
    return event;
}

v8::Local<v8::Object> createJSEventWithSender(v8::Isolate* isolate, v8::Local<v8::Object> object, std::function<void(std::string)>&& callback)
{
    Event* event = mate::Event::create(isolate, v8::Object::New(isolate), std::move(callback));
    v8::MaybeLocal<v8::Object> wrapper = event->GetWrapper(isolate);

    if (wrapper.IsEmpty())
        return v8::Local<v8::Object>();
    v8::Local<v8::Object> ret = wrapper.ToLocalChecked();

    gin_helper::Dictionary(isolate, ret).Set("sender", object);
    return ret;
}

v8::Local<v8::Object> createCustomEvent(v8::Isolate* isolate, v8::Local<v8::Object> object, v8::Local<v8::Object> customEvent)
{
    v8::Local<v8::Object> event = createEventObject(isolate);

    v8::MaybeLocal<v8::Context> customEventContext = customEvent->GetCreationContext();
    (void)event->SetPrototype(customEventContext.ToLocalChecked(), customEvent);
    gin_helper::Dictionary(isolate, event).Set("sender", object);
    return event;
}

v8::Local<v8::Object> createEventFromFlags(v8::Isolate* isolate, int flags)
{
    //     gin_helper::Dictionary obj = gin_helper::Dictionary::CreateEmpty(isolate);
    //     obj.Set("shiftKey", static_cast<bool>(flags & ui::EF_SHIFT_DOWN));
    //     obj.Set("ctrlKey", static_cast<bool>(flags & ui::EF_CONTROL_DOWN));
    //     obj.Set("altKey", static_cast<bool>(flags & ui::EF_ALT_DOWN));
    //     obj.Set("metaKey", static_cast<bool>(flags & ui::EF_COMMAND_DOWN));
    //     return obj.GetHandle();
    DebugBreak();
    return v8::Local<v8::Object>();
}

} // namespace internal

} // namespace mate
