// Copyright (c) 2016 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_COMMON_API_ATOM_API_KEY_WEAK_MAP_H_
#define ATOM_COMMON_API_ATOM_API_KEY_WEAK_MAP_H_

#include "electron/common/KeyWeakMap.h"

#include "electron/common/api/GetConstructorFromTls.h"
#include "electron/common/gin_helper/wrappable.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"

namespace atom {

namespace api {

static int kKeyWeakMapClassNameCount = 0;

template <typename K> class KeyWeakMap : public gin_helper::Wrappable<KeyWeakMap<K>> {
public:
    static v8::Local<v8::Object> create(v8::Isolate* isolate)
    {
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::Persistent<v8::Function>* constructor = V8PersistentTls::get(&constructorTlsKey);
        v8::Local<v8::Function> constructorFunction = v8::Local<v8::Function>::New(isolate, *constructor);
        v8::MaybeLocal<v8::Object> obj = constructorFunction->NewInstance(context).ToLocalChecked();
        return obj.ToLocalChecked();
    }

    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        v8::Isolate* isolate = args.GetIsolate();
        if (args.IsConstructCall()) {
            if (args.Length() > 1)
                return;

            KeyWeakMap* self = new KeyWeakMap(isolate, args.This());
            args.GetReturnValue().Set(args.This());
        }
    }

    static void init(v8::Isolate* isolate)
    {
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::Persistent<v8::Function>* constructor = V8PersistentTls::get(&constructorTlsKey);
        if (!(*constructor).IsEmpty())
            return;

        ++kKeyWeakMapClassNameCount;
        char className[24] = { 0 };
        sprintf(className, "KeyWeakMap%d", kKeyWeakMapClassNameCount);

        v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, &KeyWeakMap<K>::newFunction);
        prototype->SetClassName(gin_helper::StringToV8(isolate, className));
        gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
        builder.SetMethod("set", &KeyWeakMap<K>::set);
        builder.SetMethod("get", &KeyWeakMap<K>::get);
        builder.SetMethod("has", &KeyWeakMap<K>::has);
        builder.SetMethod("remove", &KeyWeakMap<K>::remove);
        (*constructor).Reset(isolate, prototype->GetFunction(context).ToLocalChecked());
    }

    static gin_helper::WrapperInfo kWrapperInfo;

protected:
    explicit KeyWeakMap(v8::Isolate* isolate, v8::Local<v8::Object> wrapper)
    {
        gin_helper::Wrappable<KeyWeakMap<K>>::InitWith(isolate, wrapper);
    }
    virtual ~KeyWeakMap() override
    {
        OutputDebugStringA("~KeyWeakMap\n");
    }

private:
    // API for KeyWeakMap.
    void set(v8::Isolate* isolate, const K& key, v8::Local<v8::Object> object)
    {
        m_keyWeakMap.set(isolate, key, object);
    }

    v8::Local<v8::Object> get(v8::Isolate* isolate, const K& key)
    {
        return m_keyWeakMap.get(isolate, key).ToLocalChecked();
    }

    bool has(const K& key)
    {
        return m_keyWeakMap.has(key);
    }

    void remove(const K& key)
    {
        m_keyWeakMap.remove(key);
    }

    //static v8::Persistent<v8::Function> constructor;
    static DWORD constructorTlsKey;

    atom::KeyWeakMap<K> m_keyWeakMap;

    DISALLOW_COPY_AND_ASSIGN(KeyWeakMap);
};

} // namespace api

} // namespace atom

#endif // ATOM_COMMON_API_ATOM_API_KEY_WEAK_MAP_H_
