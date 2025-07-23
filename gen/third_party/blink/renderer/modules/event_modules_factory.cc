// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/event_factory.cc.tmpl
// and input files:
//   gen/third_party/blink/renderer/modules/event_interface_modules_names.json5

#include "third_party/blink/renderer/modules/event_modules_factory.h"

#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/frame/deprecation/deprecation.h"
#include "third_party/blink/renderer/modules/device_orientation/device_motion_event.h"
#include "third_party/blink/renderer/modules/device_orientation/device_orientation_event.h"
#include "third_party/blink/renderer/modules/indexeddb/idb_version_change_event.h"
#include "third_party/blink/renderer/modules/storage/storage_event.h"
#include "third_party/blink/renderer/modules/webgl/webgl_context_event.h"
#include "third_party/blink/renderer/modules/websockets/close_event.h"
#include "third_party/blink/renderer/platform/instrumentation/use_counter.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

Event* EventModulesFactory::Create(ScriptState* script_state, ExecutionContext* executionContext, const String& type)
{
    if (EqualIgnoringASCIICase(type, "CloseEvent")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventCloseEvent);
        return CloseEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "DeviceMotionEvent")) {
//         UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventDeviceMotionEvent);
//         return DeviceMotionEvent::Create();
        *(int*)1 = 1;
    }
    if (EqualIgnoringASCIICase(type, "DeviceOrientationEvent")) {
//         UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventDeviceOrientationEvent);
//         return DeviceOrientationEvent::Create();
        *(int*)1 = 1;
    }
    if (EqualIgnoringASCIICase(type, "IDBVersionChangeEvent")) {
//         UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventIDBVersionChangeEvent);
//         return IDBVersionChangeEvent::Create();
        *(int*)1 = 1;
    }
    if (EqualIgnoringASCIICase(type, "StorageEvent")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventStorageEvent);
        return StorageEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "WebGLContextEvent")) {
//         UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventWebGLContextEvent);
//         return WebGLContextEvent::Create();
        *(int*)1 = 1;
    }
    return nullptr;
}

} // namespace blink
