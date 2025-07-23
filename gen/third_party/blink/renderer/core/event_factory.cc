// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/event_factory.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/events/event_interface_aliases.json5
//   gen/third_party/blink/renderer/core/event_interface_names.json5

#include "third_party/blink/renderer/core/events/event_factory.h"

#include "third_party/blink/renderer/core/dom/events/custom_event.h"
#include "third_party/blink/renderer/core/dom/events/event.h"
#include "third_party/blink/renderer/core/events/animation_event.h"
#include "third_party/blink/renderer/core/events/before_unload_event.h"
#include "third_party/blink/renderer/core/events/composition_event.h"
#include "third_party/blink/renderer/core/events/drag_event.h"
#include "third_party/blink/renderer/core/events/error_event.h"
#include "third_party/blink/renderer/core/events/focus_event.h"
#include "third_party/blink/renderer/core/events/hash_change_event.h"
#include "third_party/blink/renderer/core/events/keyboard_event.h"
#include "third_party/blink/renderer/core/events/message_event.h"
#include "third_party/blink/renderer/core/events/mouse_event.h"
#include "third_party/blink/renderer/core/events/mutation_event.h"
#include "third_party/blink/renderer/core/events/page_transition_event.h"
#include "third_party/blink/renderer/core/events/pop_state_event.h"
#include "third_party/blink/renderer/core/events/text_event.h"
#include "third_party/blink/renderer/core/events/touch_event.h"
#include "third_party/blink/renderer/core/events/transition_event.h"
#include "third_party/blink/renderer/core/events/ui_event.h"
#include "third_party/blink/renderer/core/events/wheel_event.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/frame/deprecation/deprecation.h"
#include "third_party/blink/renderer/core/html/track/track_event.h"
#include "third_party/blink/renderer/platform/instrumentation/use_counter.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

Event* EventFactory::Create(ScriptState* script_state, ExecutionContext* executionContext, const String& type)
{
    if (EqualIgnoringASCIICase(type, "AnimationEvent")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventAnimationEvent);
        return AnimationEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "BeforeUnloadEvent")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventBeforeUnloadEvent);
        return BeforeUnloadEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "CompositionEvent")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventCompositionEvent);
        return CompositionEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "CustomEvent")) {
        return CustomEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "DragEvent")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventDragEvent);
        return DragEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "ErrorEvent")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventErrorEvent);
        return ErrorEvent::Create(script_state);
    }
    if (EqualIgnoringASCIICase(type, "Event")) {
        return Event::Create();
    }
    if (EqualIgnoringASCIICase(type, "FocusEvent")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventFocusEvent);
        return FocusEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "HashChangeEvent")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventHashChangeEvent);
        return HashChangeEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "KeyboardEvent")) {
        return KeyboardEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "MessageEvent")) {
        return MessageEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "MouseEvent")) {
        return MouseEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "MutationEvent") && RuntimeEnabledFeatures::MutationEventsEnabled(executionContext)) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventMutationEvent);
        return MutationEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "PageTransitionEvent")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventPageTransitionEvent);
        return PageTransitionEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "PopStateEvent")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventPopStateEvent);
        return PopStateEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "TextEvent")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventTextEvent);
        return TextEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "TouchEvent")) {
        return TouchEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "TrackEvent")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventTrackEvent);
        return TrackEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "TransitionEvent")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventTransitionEvent);
        return TransitionEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "UIEvent")) {
        return UIEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "WheelEvent")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventWheelEvent);
        return WheelEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "Events")) {
        return Event::Create();
    }
    if (EqualIgnoringASCIICase(type, "HTMLEvents")) {
        return Event::Create();
    }
    if (EqualIgnoringASCIICase(type, "KeyboardEvents")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventKeyboardEvents);
        return KeyboardEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "MouseEvents")) {
        return MouseEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "MutationEvents") && RuntimeEnabledFeatures::MutationEventsEnabled(executionContext)) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventMutationEvents);
        return MutationEvent::Create();
    }
    if (EqualIgnoringASCIICase(type, "SVGEvents")) {
        UseCounter::Count(executionContext, WebFeature::kDocumentCreateEventSVGEvents);
        return Event::Create();
    }
    if (EqualIgnoringASCIICase(type, "UIEvents")) {
        return UIEvent::Create();
    }
    return nullptr;
}

} // namespace blink
