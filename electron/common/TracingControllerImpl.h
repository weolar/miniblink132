
#ifndef electron_common_TracingControllerImpl_h
#define electron_common_TracingControllerImpl_h

#include "libplatform/v8-tracing.h"

namespace atom {

class TracingControllerImpl : public v8::platform::tracing::TracingController {
public:
    TracingControllerImpl() = default;
    ~TracingControllerImpl() override = default;

    // disable copy
    TracingControllerImpl(const TracingControllerImpl&) = delete;
    TracingControllerImpl& operator=(const TracingControllerImpl&) = delete;

    // TracingController implementation.
    const uint8_t* GetCategoryGroupEnabled(const char* name) override
    {
        //return TRACE_EVENT_API_GET_CATEGORY_GROUP_ENABLED(name);
        return (const uint8_t*)"TracingControllerImpl";
    }

    uint64_t AddTraceEvent(char phase, const uint8_t* category_enabled_flag, const char* name, const char* scope, uint64_t id, uint64_t bind_id,
        int32_t num_args, const char** arg_names, const uint8_t* arg_types, const uint64_t* arg_values,
        std::unique_ptr<v8::ConvertableToTraceFormat>* arg_convertables, unsigned int flags) override
    {
        //         base::trace_event::TraceArguments args(
        //             num_args, arg_names, arg_types,
        //             reinterpret_cast<const unsigned long long*>(  // NOLINT(runtime/int)
        //                 arg_values),
        //             arg_convertables);
        //         DCHECK_LE(num_args, 2);
        //         base::trace_event::TraceEventHandle handle =
        //             TRACE_EVENT_API_ADD_TRACE_EVENT_WITH_BIND_ID(
        //                 phase, category_enabled_flag, name, scope, id, bind_id, &args,
        //                 flags);
        //         uint64_t result;
        //         memcpy(&result, &handle, sizeof(result));
        //         return result;
        return 0;
    }

    uint64_t AddTraceEventWithTimestamp(char phase, const uint8_t* category_enabled_flag, const char* name, const char* scope, uint64_t id, uint64_t bind_id,
        int32_t num_args, const char** arg_names, const uint8_t* arg_types, const uint64_t* arg_values,
        std::unique_ptr<v8::ConvertableToTraceFormat>* arg_convertables, unsigned int flags, int64_t timestampMicroseconds) override
    {
        //         base::trace_event::TraceArguments args(
        //             num_args, arg_names, arg_types,
        //             reinterpret_cast<const unsigned long long*>(  // NOLINT(runtime/int)
        //                 arg_values),
        //             arg_convertables);
        //         DCHECK_LE(num_args, 2);
        //         base::TimeTicks timestamp =
        //             base::TimeTicks() + base::Microseconds(timestampMicroseconds);
        //         base::trace_event::TraceEventHandle handle =
        //             TRACE_EVENT_API_ADD_TRACE_EVENT_WITH_THREAD_ID_AND_TIMESTAMP(
        //                 phase, category_enabled_flag, name, scope, id, bind_id,
        //                 TRACE_EVENT_API_CURRENT_THREAD_ID, timestamp, &args, flags);
        //         uint64_t result;
        //         memcpy(&result, &handle, sizeof(result));
        //         return result;

        return 0;
    }

    void UpdateTraceEventDuration(const uint8_t* category_enabled_flag, const char* name, uint64_t handle) override
    {
        //         base::trace_event::TraceEventHandle traceEventHandle;
        //         memcpy(&traceEventHandle, &handle, sizeof(handle));
        //         TRACE_EVENT_API_UPDATE_TRACE_EVENT_DURATION(category_enabled_flag, name, traceEventHandle);
    }

    void AddTraceStateObserver(TraceStateObserver* observer) override
    {
        //g_trace_state_dispatcher.Get().AddObserver(observer);
    }

    void RemoveTraceStateObserver(TraceStateObserver* observer) override
    {
        //g_trace_state_dispatcher.Get().RemoveObserver(observer);
    }
};

}

#endif