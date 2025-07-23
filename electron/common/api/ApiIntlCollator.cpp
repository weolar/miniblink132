// Copyright (c) 2013 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/nodeblink.h"

#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/api/EventEmitter.h"
#include "electron/common/gin_helper/wrappable.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/libnode/src/node_version.h"
#include "third_party/libuv/include/uv.h"
#include "base/threading/thread_local.h"

namespace {

THREAD_LOCAL_CONSTRUCTOR(IntlCollator)

class IntlCollator : public mate::EventEmitter<IntlCollator> {
public:
    explicit IntlCollator(v8::Isolate* isolate, v8::Local<v8::Object> wrapper)
    {
        gin_helper::Wrappable<IntlCollator>::InitWith(isolate, wrapper);
    }

    static void init(v8::Isolate* isolate, v8::Local<v8::Object> target)
    {
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, newFunction);

        prototype->SetClassName(v8::String::NewFromUtf8(isolate, "IntlCollator").ToLocalChecked());
        gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
        builder.SetMethod("compare", &IntlCollator::compareApi);

        getIntlCollatorConstructor().Reset(isolate, prototype->GetFunction(context).ToLocalChecked());
        target->Set(context, v8::String::NewFromUtf8(isolate, "IntlCollator").ToLocalChecked(), prototype->GetFunction(context).ToLocalChecked());
    }

    int compareApi(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        if (args.Length() != 2 || !args[0]->IsString() || !args[1]->IsString())
            return -1;

        v8::Isolate* isolate = args.GetIsolate();
        v8::String::Utf8Value str0(isolate, args[0]);
        v8::String::Utf8Value str1(isolate, args[1]);
        const char* string0 = *str0;
        int stringLen0 = str0.length();

        const char* string1 = *str1;
        int stringLen1 = str1.length();

        if (stringLen0 == 0 && stringLen1 == 0) {
            return 0;
        } else if (stringLen0 != 0 && stringLen1 == 0) {
            return 1;
        } else if (stringLen0 == 0 && stringLen1 != 0) {
            return -1;
        }

        for (int i = 0; i < stringLen0 && i < stringLen1; ++i) {
            if (string0[i] == string1[i])
                continue;
            return string0[i] - string1[i];
        }
        return 0;
    }

    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        v8::Isolate* isolate = args.GetIsolate();
        if (args.IsConstructCall()) {
            new IntlCollator(isolate, args.This());
            args.GetReturnValue().Set(args.This());
            return;
        }
    }

public:
    static gin_helper::WrapperInfo kWrapperInfo;
};

gin_helper::WrapperInfo IntlCollator::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };

void initializeCommonIntlCollatorApi(v8::Local<v8::Object> target, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, void* priv)
{
    IntlCollator::init(context->GetIsolate(), target);
}

} // namespace

static const char CommonIntlCollatorSricpt[] = "exports = {};";

static NodeNative nativeCommonIntlCollatorNative { "IntlCollator", CommonIntlCollatorSricpt, sizeof(CommonIntlCollatorSricpt) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_common_intl_collator, initializeCommonIntlCollatorApi, &nativeCommonIntlCollatorNative)
