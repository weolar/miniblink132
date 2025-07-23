// Copyright (c) 2013 GitHub, Inc.
// Copyright (c) 2012 Intel Corp. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "electron/common/api/ObjectLifeMonitor.h"

namespace atom {

ObjectLifeMonitor::ObjectLifeMonitor(v8::Isolate* isolate, v8::Local<v8::Object> target)
    : m_isolate(isolate)
    , m_context(isolate, isolate->GetCurrentContext())
    , m_target(isolate, target)
/*weak_ptr_factory_(this)*/
{
    m_target.SetWeak(this, onObjectGC, v8::WeakCallbackType::kParameter);
}

ObjectLifeMonitor::~ObjectLifeMonitor()
{
    if (m_target.IsEmpty())
        return;
    m_target.ClearWeak();
    m_target.Reset();
}

// static
void ObjectLifeMonitor::onObjectGC(const v8::WeakCallbackInfo<ObjectLifeMonitor>& data)
{
    ObjectLifeMonitor* self = data.GetParameter();
    self->m_target.Reset();
    self->onRunDestructor();
    data.SetSecondPassCallback(freeMe);
}

// static
void ObjectLifeMonitor::freeMe(const v8::WeakCallbackInfo<ObjectLifeMonitor>& data)
{
    delete data.GetParameter();
}

} // namespace atom
