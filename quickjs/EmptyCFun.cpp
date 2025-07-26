
#include <string>

#include "v8.h"
#include "v8-profiler.h"
#include "v8-debug.h"
#include "v8-inspector.h"
#include "v8-fast-api-calls.h"
#include "libplatform/v8-tracing.h"
#include "libplatform/libplatform.h"

#include <windows.h>

// extern "C" double trunc(double val)
// {
//    return 0;
//}
//
//extern "C" double round(double val)
//{
//    return 0;
//}
//
//extern "C" double fmin(double _X, double _Y)
//{
//    return 0;
//}

void printEmptyFuncInfo(const char* fun, bool isBreak, bool isPrint);

void v8::Isolate::RemoveGCEpilogueCallback(void(__cdecl*)(v8::Isolate*, v8::GCType, v8::GCCallbackFlags, void*), void*)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

void v8::Isolate::RemoveGCPrologueCallback(void(__cdecl*)(v8::Isolate*, v8::GCType, v8::GCCallbackFlags, void*), void*)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

v8::platform::tracing::TraceWriter* v8::platform::tracing::TraceWriter::CreateJSONTraceWriter(class std::basic_ostream<char, struct std::char_traits<char>>&,
    class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char>> const&)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return nullptr;
}

void v8::platform::tracing::TraceObject::Initialize(char phase, const uint8_t* category_enabled_flag, const char* name, const char* scope, uint64_t id,
    uint64_t bind_id, int num_args, const char** arg_names, const uint8_t* arg_types, const uint64_t* arg_values,
    std::unique_ptr<v8::ConvertableToTraceFormat>* arg_convertables, unsigned int flags, int64_t timestamp, int64_t cpu_timestamp)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

unsigned char const* v8::platform::tracing::TracingController::GetCategoryGroupEnabled(char const*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return (unsigned char const*)"v8::platform::tracing::TracingController::GetCategoryGroupEnabled";
}

v8::StartupData v8::SnapshotCreator::CreateBlob(v8::SnapshotCreator::FunctionCodeHandling, v8::StartupData(__cdecl*)(v8::Local<v8::Object>, int))
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::StartupData();
}

uint64_t v8::platform::tracing::TracingController::AddTraceEvent(char phase, const uint8_t* category_enabled_flag, const char* name, const char* scope,
    uint64_t id, uint64_t bind_id, int32_t num_args, const char** arg_names, const uint8_t* arg_types, const uint64_t* arg_values,
    std::unique_ptr<v8::ConvertableToTraceFormat>* arg_convertables, unsigned int flags)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return id;
}

void v8::platform::tracing::TracingController::UpdateTraceEventDuration(const uint8_t* category_enabled_flag, const char* name, uint64_t handle)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::platform::tracing::TracingController::AddTraceStateObserver(v8::TracingController::TraceStateObserver* observer)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

void v8::platform::tracing::TracingController::RemoveTraceStateObserver(v8::TracingController::TraceStateObserver* observer)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

#define ReadCycleCounter() __rdtsc()

V8_INLINE uint64_t QPCNowRaw()
{
    LARGE_INTEGER perf_counter_now = {};
    // According to the MSDN documentation for QueryPerformanceCounter(), this
    // will never fail on systems that run XP or later.
    // https://msdn.microsoft.com/library/windows/desktop/ms644904.aspx
    BOOL result = ::QueryPerformanceCounter(&perf_counter_now);
    //DCHECK(result);
    //USE(result);
    return perf_counter_now.QuadPart;
}

double TSCTicksPerSecond()
{
    //DCHECK(IsSupported());

    // The value returned by QueryPerformanceFrequency() cannot be used as the TSC
    // frequency, because there is no guarantee that the TSC frequency is equal to
    // the performance counter frequency.

    // The TSC frequency is cached in a static variable because it takes some time
    // to compute it.
    static double tsc_ticks_per_second = 0;
    if (tsc_ticks_per_second != 0)
        return tsc_ticks_per_second;

    // Increase the thread priority to reduces the chances of having a context
    // switch during a reading of the TSC and the performance counter.
    int previous_priority = ::GetThreadPriority(::GetCurrentThread());
    ::SetThreadPriority(::GetCurrentThread(), THREAD_PRIORITY_HIGHEST);

    // The first time that this function is called, make an initial reading of the
    // TSC and the performance counter.
    static const uint64_t tsc_initial = ReadCycleCounter();
    static const uint64_t perf_counter_initial = QPCNowRaw();

    // Make a another reading of the TSC and the performance counter every time
    // that this function is called.
    uint64_t tsc_now = ReadCycleCounter();
    uint64_t perf_counter_now = QPCNowRaw();

    // Reset the thread priority.
    ::SetThreadPriority(::GetCurrentThread(), previous_priority);

    // Make sure that at least 50 ms elapsed between the 2 readings. The first
    // time that this function is called, we don't expect this to be the case.
    // Note: The longer the elapsed time between the 2 readings is, the more
    //   accurate the computed TSC frequency will be. The 50 ms value was
    //   chosen because local benchmarks show that it allows us to get a
    //   stddev of less than 1 tick/us between multiple runs.
    // Note: According to the MSDN documentation for QueryPerformanceFrequency(),
    //   this will never fail on systems that run XP or later.
    //   https://msdn.microsoft.com/library/windows/desktop/ms644905.aspx
    LARGE_INTEGER perf_counter_frequency = {};
    ::QueryPerformanceFrequency(&perf_counter_frequency);
    //DCHECK_GE(perf_counter_now, perf_counter_initial);
    uint64_t perf_counter_ticks = perf_counter_now - perf_counter_initial;
    double elapsed_time_seconds = perf_counter_ticks / static_cast<double>(perf_counter_frequency.QuadPart);

    const double kMinimumEvaluationPeriodSeconds = 0.05;
    if (elapsed_time_seconds < kMinimumEvaluationPeriodSeconds)
        return 0;

    // Compute the frequency of the TSC.
    //DCHECK_GE(tsc_now, tsc_initial);
    uint64_t tsc_ticks = tsc_now - tsc_initial;
    tsc_ticks_per_second = tsc_ticks / elapsed_time_seconds;

    return tsc_ticks_per_second;
}

__int64 v8::platform::tracing::TracingController::CurrentCpuTimestampMicroseconds(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);

    const int64_t kHoursPerDay = 24;
    const int64_t kMillisecondsPerSecond = 1000;
    const int64_t kMillisecondsPerDay = kMillisecondsPerSecond * 60 * 60 * kHoursPerDay;
    const int64_t kMicrosecondsPerMillisecond = 1000;
    const int64_t kMicrosecondsPerSecond = kMicrosecondsPerMillisecond * kMillisecondsPerSecond;

    // Get the number of TSC ticks used by the current thread.
    ULONG64 thread_cycle_time = 0;
    ::QueryThreadCycleTime(::GetCurrentThread(), &thread_cycle_time);

    // Get the frequency of the TSC.
    double tsc_ticks_per_second = TSCTicksPerSecond();
    if (tsc_ticks_per_second == 0)
        return 0;

    // Return the CPU time of the current thread.
    double thread_time_seconds = thread_cycle_time / tsc_ticks_per_second;
    return (static_cast<int64_t>(thread_time_seconds * kMicrosecondsPerSecond));
}

__int64 v8::platform::tracing::TracingController::CurrentTimestampMicroseconds(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return CurrentCpuTimestampMicroseconds();
}

std::unique_ptr<v8::JobHandle> v8::platform::NewDefaultJobHandle(
    v8::Platform* platform, v8::TaskPriority priority, std::unique_ptr<v8::JobTask> job_task, size_t num_worker_threads)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return nullptr;
}

bool v8::ArrayBuffer::IsDetachable(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

v8::Local<class v8::String> v8::String::NewFromUtf8Literal(Isolate* isolate, const char* literal, NewStringType type, int length)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<class v8::String>();
}

v8::CompiledWasmModule::CompiledWasmModule(std::shared_ptr<internal::wasm::NativeModule>, const char* source_url, size_t url_length)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

v8::MaybeLocal<v8::SharedArrayBuffer> v8::ValueDeserializer::Delegate::GetSharedArrayBufferFromId(v8::Isolate*, unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::MaybeLocal<v8::SharedArrayBuffer>();
}

v8::MaybeLocal<v8::WasmModuleObject> v8::ValueDeserializer::Delegate::GetWasmModuleFromId(v8::Isolate*, unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::MaybeLocal<v8::WasmModuleObject>();
}

// v8::Maybe<unsigned int> v8::ValueSerializer::Delegate::GetWasmModuleTransferId(v8::Isolate*, v8::Local<v8::WasmModuleObject>)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return v8::Nothing<unsigned int>();
// }

bool v8::ArrayBuffer::WasDetached(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

size_t v8::SharedArrayBuffer::ByteLength(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return 0;
}

void* v8::SharedArrayBuffer::Data(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return nullptr;
}

// v8::Local<v8::FunctionTemplate> v8::FunctionTemplate::New(v8::Isolate*, void(__cdecl*)(v8::FunctionCallbackInfo<v8::Value> const&), v8::Local<v8::Value>, v8::Local<v8::Signature>, int, enum v8::ConstructorBehavior, enum v8::SideEffectType, v8::CFunction const*, unsigned short, unsigned short, unsigned short)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return v8::Local<v8::FunctionTemplate>();
// }

v8::Local<v8::BigInt> v8::BigInt::New(v8::Isolate*, __int64)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::BigInt>();
}

// v8::Local<v8::Object> v8::Object::New(v8::Isolate*, v8::Local<v8::Value>, v8::Local<v8::Name>*, v8::Local<v8::Value>*, size_t)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return v8::Local<v8::Object>();
// }

v8::MaybeLocal<v8::Value> v8::JSON::Parse(v8::Local<v8::Context>, v8::Local<v8::String>)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::MaybeLocal<v8::Value>();
}

v8::MaybeLocal<v8::String> v8::JSON::Stringify(v8::Local<v8::Context>, v8::Local<v8::Object>, v8::Local<v8::String>)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::MaybeLocal<v8::String>();
}

v8::Isolate::AllowJavascriptExecutionScope::AllowJavascriptExecutionScope(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

v8::Isolate::AllowJavascriptExecutionScope::~AllowJavascriptExecutionScope(void)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

bool v8_inspector::V8InspectorSession::canDispatchMethod(v8_inspector::StringView const&)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
    return false;
}

v8::Isolate* v8::Isolate::TryGetCurrent(void)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return nullptr;
}

void v8::Isolate::AddNearHeapLimitCallback(size_t(__cdecl*)(void*, size_t, size_t), void*)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

v8::MaybeLocal<v8::Context> v8::Context::FromSnapshot(v8::Isolate*, size_t, void(__cdecl*)(v8::Local<v8::Object>, int, v8::StartupData),
    v8::ExtensionConfiguration*, v8::MaybeLocal<v8::Value>, v8::MicrotaskQueue*)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::MaybeLocal<v8::Context>();
}

v8::HeapSnapshot const* v8::HeapProfiler::TakeHeapSnapshot(v8::HeapProfiler::HeapSnapshotOptions const&)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return nullptr;
}

v8::HeapSnapshot const* v8::HeapProfiler::TakeHeapSnapshot(v8::ActivityControl*, v8::HeapProfiler::ObjectNameResolver*, bool, bool)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return nullptr;
}

void v8::WasmStreaming::OnBytesReceived(unsigned char const*, size_t)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

void v8::WasmStreaming::Finish(bool)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

void v8::WasmStreaming::Abort(v8::MaybeLocal<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

void v8::WasmStreaming::SetUrl(char const*, size_t)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

std::shared_ptr<v8::WasmStreaming> v8::WasmStreaming::Unpack(v8::Isolate*, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return nullptr;
}

bool v8::Value::IsBigInt(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

bool v8::Value::IsWasmMemoryObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

uint64_t v8::BigInt::Uint64Value(bool*) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return 0;
}

__int64 v8::BigInt::Int64Value(bool*) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return 0;
}

v8::Local<v8::ArrayBuffer> v8::WasmMemoryObject::Buffer(void)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::ArrayBuffer>();
}

v8::CFunction::CFunction(const void* address, const v8::CFunctionInfo* type_info)
    : address_(address)
    , type_info_(type_info)
{
    //     CHECK_NOT_NULL(address_);
    //     CHECK_NOT_NULL(type_info_);
}

v8::CFunctionInfo::CFunctionInfo(const v8::CTypeInfo& return_info, unsigned int arg_count, const v8::CTypeInfo* arg_info)
    : return_info_(return_info)
    , arg_count_(arg_count)
    , arg_info_(arg_info)
{
    if (arg_count_ > 0) {
        for (unsigned int i = 0; i < arg_count_ - 1; ++i) {
            //DCHECK(arg_info_[i].GetType() != CTypeInfo::kCallbackOptionsType);
            if (arg_info_[i].GetType() == (v8::CTypeInfo::Type)(255))
                printEmptyFuncInfo(__FUNCTION__, true, true);
        }
    }
}

const v8::CTypeInfo& v8::CFunctionInfo::ArgumentInfo(unsigned int index) const
{
    //DCHECK_LT(index, ArgumentCount());
    return arg_info_[index];
}

v8::HeapCodeStatistics::HeapCodeStatistics(void)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

bool v8::Isolate::GetHeapCodeAndMetadataStatistics(v8::HeapCodeStatistics*)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

v8::Local<v8::BigInt> v8::BigInt::NewFromUnsigned(v8::Isolate*, uint64_t)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::BigInt>();
}

v8::MaybeLocal<v8::Array> v8::Object::PreviewEntries(bool*)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::MaybeLocal<v8::Array>();
}

bool v8::Value::IsBigIntObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

bool v8::Value::IsModuleNamespaceObject(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

uint64_t v8::platform::tracing::TracingController::AddTraceEventWithTimestamp(char phase, const uint8_t* category_enabled_flag, const char* name,
    const char* scope, uint64_t id, uint64_t bind_id, int32_t num_args, const char** arg_names, const uint8_t* arg_types, const uint64_t* arg_values,
    std::unique_ptr<v8::ConvertableToTraceFormat>* arg_convertables, unsigned int flags, int64_t timestamp)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

v8::SnapshotCreator::SnapshotCreator(v8::Isolate*, const intptr_t*, v8::StartupData*)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

v8::SnapshotCreator::~SnapshotCreator(void)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

void v8::SnapshotCreator::SetDefaultContext(v8::Local<v8::Context>)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

size_t v8::SnapshotCreator::AddContext(v8::Local<v8::Context>, v8::StartupData(__cdecl*)(v8::Local<v8::Object>, int))
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return 0;
}

// v8::Local<v8::Context> v8::Context::New(v8::Isolate*, v8::ExtensionConfiguration*, v8::MaybeLocal<v8::ObjectTemplate>, v8::MaybeLocal<v8::Value>, void(__cdecl*)(v8::Local<v8::Object>, int, v8::StartupData), v8::MicrotaskQueue*)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return v8::Local<v8::Context>();
// }

void v8::Isolate::GetStackSample(v8::RegisterState const&, void**, size_t, v8::SampleInfo*)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

// v8::Maybe<bool> v8::Object::SetAccessor(v8::Local<v8::Context>, v8::Local<v8::Name>, void(__cdecl*)(v8::Local<v8::Name>, v8::PropertyCallbackInfo<v8::Value> const&), void(__cdecl*)(v8::Local<v8::Name>, v8::Local<v8::Value>, v8::PropertyCallbackInfo<void> const&), v8::MaybeLocal<v8::Value>, enum v8::AccessControl, enum v8::PropertyAttribute, enum v8::SideEffectType, enum v8::SideEffectType)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return v8::Nothing<bool>();
// }

double v8::Platform::SystemClockTimeMillis(void)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return 0;
}

void v8::Isolate::AddGCPrologueCallback(void(__cdecl*)(v8::Isolate*, enum v8::GCType, enum v8::GCCallbackFlags, void*), void*, enum v8::GCType)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

void v8::Isolate::AddGCEpilogueCallback(void(__cdecl*)(v8::Isolate*, enum v8::GCType, enum v8::GCCallbackFlags, void*), void*, enum v8::GCType)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

// bool v8::ArrayBuffer::IsDetachable(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return false;
// }

v8::Maybe<bool> v8::ArrayBuffer::Detach(v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Nothing<bool>();
}

v8::Local<v8::SharedArrayBuffer> v8::SharedArrayBuffer::New(v8::Isolate*, std::shared_ptr<v8::BackingStore>)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::SharedArrayBuffer>();
}

std::shared_ptr<v8::BackingStore> v8::SharedArrayBuffer::GetBackingStore(void)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return nullptr;
}

v8::MaybeLocal<v8::WasmModuleObject> v8::WasmModuleObject::FromCompiledModule(v8::Isolate*, v8::CompiledWasmModule const&)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::MaybeLocal<v8::WasmModuleObject>();
}

v8::CompiledWasmModule v8::WasmModuleObject::GetCompiledModule(void)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return CompiledWasmModule(nullptr, nullptr, 0);
}

bool v8::String::IsExternalTwoByte(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

v8::Local<v8::BigInt64Array> v8::BigInt64Array::New(v8::Local<v8::ArrayBuffer>, size_t, size_t)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::BigInt64Array>();
}

v8::Isolate* v8::Message::GetIsolate(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return nullptr;
}

int v8::Message::ErrorLevel(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return 0;
}

v8::Local<v8::Value> v8::PropertyDescriptor::value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::Value>();
}

bool v8::PropertyDescriptor::has_value(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

bool v8::PropertyDescriptor::has_get(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

bool v8::PropertyDescriptor::has_set(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

bool v8::PropertyDescriptor::enumerable(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

bool v8::PropertyDescriptor::has_enumerable(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

bool v8::PropertyDescriptor::configurable(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

bool v8::PropertyDescriptor::has_configurable(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

bool v8::PropertyDescriptor::writable(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

bool v8::PropertyDescriptor::has_writable(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

void v8::Isolate::DateTimeConfigurationChangeNotification(enum v8::Isolate::TimeZoneDetection)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return;
}

v8::ScriptCompiler::CachedData* v8::ScriptCompiler::CreateCodeCache(v8::Local<v8::UnboundScript>)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return nullptr;
}

std::unique_ptr<v8::MeasureMemoryDelegate, std::default_delete<v8::MeasureMemoryDelegate>> v8::MeasureMemoryDelegate::Default(
    v8::Isolate*, v8::Local<v8::Context>, v8::Local<v8::Promise::Resolver>, enum v8::MeasureMemoryMode)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return nullptr;
}

v8::PropertyDescriptor::PropertyDescriptor(v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

v8::Local<v8::Value> v8::PropertyDescriptor::get(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::Value>();
}

v8::Local<v8::Value> v8::PropertyDescriptor::set(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::Value>();
}

v8::Isolate::SafeForTerminationScope::SafeForTerminationScope(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

v8::Isolate::SafeForTerminationScope::~SafeForTerminationScope(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

bool v8::Isolate::MeasureMemory(std::unique_ptr<v8::MeasureMemoryDelegate, std::default_delete<v8::MeasureMemoryDelegate>>, enum v8::MeasureMemoryExecution)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

std::unique_ptr<v8::MicrotaskQueue, std::default_delete<v8::MicrotaskQueue>> v8::MicrotaskQueue::New(v8::Isolate*, enum v8::MicrotasksPolicy)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return nullptr;
}

void v8::Isolate::SetAtomicsWaitCallback(
    void(__cdecl*)(enum v8::Isolate::AtomicsWaitEvent, v8::Local<v8::SharedArrayBuffer>, size_t, __int64, double, v8::Isolate::AtomicsWaitWakeHandle*, void*),
    void*)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

void v8::V8::SetFlagsFromString(char const*)
{
    //printEmptyFuncInfo(__FUNCTION__, true, true);
}

void v8::V8::DisposePlatform(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

void v8::HeapProfiler::AddBuildEmbedderGraphCallback(void(__cdecl*)(v8::Isolate*, v8::EmbedderGraph*, void*), void*)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

int v8::FixedArray::Length(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return 0;
}

v8::Local<v8::Data> v8::FixedArray::Get(v8::Local<v8::Context>, int) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::Data>();
}

v8::Local<v8::String> v8::ModuleRequest::GetSpecifier(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::String>();
}

v8::Local<v8::FixedArray> v8::ModuleRequest::GetImportAssertions(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::FixedArray>();
}

v8::ModuleRequest* v8::ModuleRequest::Cast(v8::Data*)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return nullptr;
}

v8::Module::Status v8::Module::GetStatus(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Module::kUninstantiated;
}

v8::Local<v8::Value> v8::Module::GetException(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::Value>();
}

int v8::Module::GetIdentityHash(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return 0;
}

v8::Maybe<bool> v8::Module::SetSyntheticModuleExport(v8::Isolate*, v8::Local<v8::String>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Nothing<bool>();
}

v8::Local<v8::UnboundModuleScript> v8::Module::GetUnboundModuleScript(void)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::UnboundModuleScript>();
}

v8::Local<v8::FixedArray> v8::Module::GetModuleRequests(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::FixedArray>();
}

v8::Local<v8::Value> v8::Module::GetModuleNamespace(void)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::Value>();
}

v8::Maybe<bool> v8::Module::InstantiateModule(v8::Local<v8::Context>,
    v8::MaybeLocal<v8::Module>(__cdecl*)(v8::Local<v8::Context>, v8::Local<v8::String>, v8::Local<v8::FixedArray>, v8::Local<v8::Module>))
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Nothing<bool>();
}

v8::MaybeLocal<v8::Value> v8::Module::Evaluate(v8::Local<v8::Context>)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::MaybeLocal<v8::Value>();
}

v8::ScriptCompiler::CachedData* v8::ScriptCompiler::CreateCodeCache(v8::Local<v8::UnboundModuleScript>)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return nullptr;
}

v8::MaybeLocal<v8::Module> v8::ScriptCompiler::CompileModule(
    v8::Isolate*, v8::ScriptCompiler::Source*, enum v8::ScriptCompiler::CompileOptions, enum v8::ScriptCompiler::NoCacheReason)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::MaybeLocal<v8::Module>();
}

void v8::Isolate::SetHostImportModuleDynamicallyCallback(
    v8::MaybeLocal<v8::Promise>(__cdecl*)(v8::Local<v8::Context>, v8::Local<v8::Data>, v8::Local<v8::Value>, v8::Local<v8::String>, v8::Local<v8::FixedArray>))
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

void v8::Isolate::SetHostInitializeImportMetaObjectCallback(void(__cdecl*)(v8::Local<v8::Context>, v8::Local<v8::Module>, v8::Local<v8::Object>))
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

bool v8::Value::IsBigInt64Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

bool v8::Value::IsBigUint64Array(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

v8::Maybe<bool> v8::Value::InstanceOf(v8::Local<v8::Context>, v8::Local<v8::Object>)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Nothing<bool>();
}

v8::Local<v8::Symbol> v8::Symbol::For(v8::Isolate*, v8::Local<v8::String>)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::Symbol>();
}

v8::MaybeLocal<v8::BigInt> v8::BigInt::NewFromWords(v8::Local<v8::Context> context, int sign_bit, int word_count, const uint64_t* words)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::MaybeLocal<v8::BigInt>();
}

int v8::BigInt::WordCount(void) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return 0;
}

void v8::BigInt::ToWordsArray(int* sign_bit, int* word_count, uint64_t* words) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

v8::Local<v8::BigUint64Array> v8::BigUint64Array::New(v8::Local<v8::ArrayBuffer>, size_t, size_t)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return v8::Local<v8::BigUint64Array>();
}

bool v8::Value::SameValue(v8::Local<v8::Value>) const
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return false;
}

int v8::Name::GetIdentityHash(void)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return 0;
}

v8::Isolate::DisallowJavascriptExecutionScope::DisallowJavascriptExecutionScope(v8::Isolate*, enum v8::Isolate::DisallowJavascriptExecutionScope::OnFailure)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

v8::Isolate::DisallowJavascriptExecutionScope::~DisallowJavascriptExecutionScope(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

void v8::Isolate::ClearKeptObjects(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::RemoveNearHeapLimitCallback(size_t(__cdecl*)(void*, size_t, size_t), size_t)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

void v8::Isolate::AutomaticallyRestoreInitialHeapLimit(double)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

void v8::Isolate::SetIdle(bool)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::Isolate* v8::SnapshotCreator::GetIsolate(void)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    return nullptr;
}

void v8::Context::SetPromiseHooks(v8::Local<v8::Function>, v8::Local<v8::Function>, v8::Local<v8::Function>, v8::Local<v8::Function>)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

void v8::HeapProfiler::RemoveBuildEmbedderGraphCallback(void(__cdecl*)(v8::Isolate*, v8::EmbedderGraph*, void*), void*)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

class ArrayBufferAllocator : public v8::ArrayBuffer::Allocator { // NOLINT
public:
    virtual ~ArrayBufferAllocator() override
    {
    }

    virtual void* Allocate(size_t length) override
    {
        return malloc(length);
    }

    virtual void* AllocateUninitialized(size_t length) override
    {
        return malloc(length);
    }

    virtual void Free(void* data, size_t length) override
    {
        return free(data);
    }

    virtual void* Reallocate(void* data, size_t old_size, size_t size) override
    {
        return realloc(data, size);
    }
};

v8::ArrayBuffer::Allocator* v8::ArrayBuffer::Allocator::NewDefaultAllocator(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
    return new ArrayBufferAllocator();
}

void v8::Isolate::SetPrepareStackTraceCallback(v8::MaybeLocal<v8::Value>(__cdecl*)(v8::Local<v8::Context>, v8::Local<v8::Value>, v8::Local<v8::Array>))
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

void v8::Isolate::SetAllowWasmCodeGenerationCallback(bool(__cdecl*)(v8::Local<v8::Context>, v8::Local<v8::String>))
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

void v8::Isolate::SetModifyCodeGenerationFromStringsCallback(
    v8::ModifyCodeGenerationFromStringsResult(__cdecl*)(v8::Local<v8::Context>, v8::Local<v8::Value>, bool))
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

void v8::Isolate::SetWasmStreamingCallback(void(__cdecl*)(v8::FunctionCallbackInfo<v8::Value> const&))
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

void v8::Isolate::SetHostCreateShadowRealmContextCallback(v8::MaybeLocal<v8::Context>(__cdecl*)(v8::Local<v8::Context>))
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

void v8::Isolate::DumpAndResetStats(void)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

void v8::Isolate::SetMicrotasksPolicy(enum v8::MicrotasksPolicy)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

void v8::Isolate::SetOOMErrorHandler(void(__cdecl*)(char const*, v8::OOMDetails const&))
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

bool v8::Isolate::AddMessageListenerWithErrorLevel(void(__cdecl*)(v8::Local<v8::Message>, v8::Local<v8::Value>), int, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
    return false;
}

void v8::CpuProfiler::UseDetailedSourcePositionsForProfiling(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, true);
}

void V8_Fatal(char const*, ...)
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
}

// int v8::base::OS::GetCurrentProcessId(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return 0;
// }
//
// int v8::base::OS::GetCurrentThreadId(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return 0;
// }
//
// v8::base::Mutex::Mutex(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// v8::base::Mutex::~Mutex(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// void v8::base::Mutex::Lock(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// void v8::base::Mutex::Unlock(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// v8::base::TimeTicks v8::base::TimeTicks::Now(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return v8::base::TimeTicks();
// }
//
// v8::base::ThreadTicks v8::base::ThreadTicks::Now(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return v8::base::TimeTicks();
// }
//
// bool v8::base::debug::EnableInProcessStackDumping(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return false;
// }
//
// void v8::base::debug::DisableSignalStackDump(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// v8::base::debug::StackTrace::StackTrace(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// v8::base::debug::StackTrace::~StackTrace(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// void v8::base::debug::StackTrace::Print(void)const
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// v8::base::PageAllocator::PageAllocator(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// double v8::base::OS::TimeCurrentMillis(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return 0
// }
//
// v8::base::ConditionVariable::ConditionVariable(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// v8::base::ConditionVariable::~ConditionVariable(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// void v8::base::ConditionVariable::NotifyOne(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// void v8::base::ConditionVariable::Wait(v8::base::Mutex*)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// bool v8::base::ConditionVariable::WaitFor(v8::base::Mutex*, v8::base::TimeDelta const&)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return false;
// }
//
// bool v8::base::ConditionVariable::WaitFor(v8::base::Mutex*, v8::base::TimeDelta const&)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return false;
// }
//
// v8::base::Thread::Thread(v8::base::Thread::Options const&)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// v8::base::Thread::~Thread(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// bool v8::base::Thread::Start(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
//     return false;
// }
//
// void v8::base::Thread::Join(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }
//
// void v8::base::ConditionVariable::NotifyAll(void)
// {
//     printEmptyFuncInfo(__FUNCTION__, true, true);
// }

void v8::Isolate::SetAbortOnUncaughtExceptionCallback(bool(__cdecl*)(v8::Isolate*))
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::ValueSerializer::SetTreatArrayBufferViewsAsHostObjects(bool)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

v8::Local<v8::Value> v8::Promise::Result(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Local<v8::Value>();
}

v8::Promise::PromiseState v8::Promise::State(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::Promise::kRejected;
}

uint32_t v8::ScriptCompiler::CachedDataVersionTag(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return 0;
}

void v8::Isolate::SetPromiseHook(void(__cdecl*)(v8::PromiseHookType, v8::Local<v8::Promise>, v8::Local<v8::Value>))
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    OutputDebugStringA("v8::Isolate::SetPromiseHook is not impl\n");
}

v8::Maybe<uint32_t> v8::ValueSerializer::Delegate::GetSharedArrayBufferId(v8::Isolate*, v8::Local<v8::SharedArrayBuffer>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::Maybe<uint32_t> ret = v8::Just<uint32_t>(0);
    DebugBreak();
    return ret;
}

v8::Maybe<bool> v8::ValueSerializer::Delegate::WriteHostObject(v8::Isolate*, v8::Local<v8::Object>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::Maybe<bool> ret = v8::Just(false);
    DebugBreak();
    return ret;
}

void v8::ValueSerializer::WriteHeader()
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

v8::Maybe<bool> v8::ValueSerializer::WriteValue(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::Maybe<bool> ret = v8::Just(false);
    DebugBreak();
    return ret;
}

// void v8::ValueSerializer::SetTreatArrayBufferViewsAsHostObjects(bool)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
// }

std::pair<uint8_t*, size_t> v8::ValueSerializer::Release()
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return std::make_pair(nullptr, 0);
}

void v8::ValueSerializer::TransferArrayBuffer(unsigned int, v8::Local<v8::ArrayBuffer>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

void v8::ValueSerializer::WriteUint32(unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

void v8::ValueSerializer::WriteUint64(uint64_t value)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

void v8::ValueSerializer::WriteDouble(double)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

void v8::ValueSerializer::WriteRawBytes(void const*, size_t)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

v8::ValueDeserializer::ValueDeserializer(v8::Isolate*, unsigned char const*, size_t, v8::ValueDeserializer::Delegate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

v8::ValueDeserializer::~ValueDeserializer()
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::MaybeLocal<v8::Object> v8::ValueDeserializer::Delegate::ReadHostObject(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return MaybeLocal<Object>();
}

v8::Maybe<bool> v8::ValueDeserializer::ReadHeader(v8::Local<v8::Context>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    v8::Maybe<bool> ret = v8::Just(false);
    return ret;
}

v8::MaybeLocal<v8::Value> v8::ValueDeserializer::ReadValue(v8::Local<v8::Context>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::MaybeLocal<Value>();
}

void v8::ValueDeserializer::TransferArrayBuffer(unsigned int, v8::Local<v8::ArrayBuffer>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

void v8::ValueDeserializer::TransferSharedArrayBuffer(unsigned int, v8::Local<v8::SharedArrayBuffer>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

uint32_t v8::ValueDeserializer::GetWireFormatVersion() const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

bool v8::ValueDeserializer::ReadUint32(uint32_t* value)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::ValueDeserializer::ReadUint64(uint64_t* value)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::ValueDeserializer::ReadDouble(double*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

bool v8::ValueDeserializer::ReadRawBytes(size_t, void const**)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

v8::Maybe<uint32_t> v8::ValueSerializer::Delegate::GetWasmModuleTransferId(v8::Isolate*, v8::Local<v8::WasmModuleObject>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::Maybe<uint32_t> ret = v8::Just<uint32_t>(0);
    return ret;
}

void* v8::ValueSerializer::Delegate::ReallocateBufferMemory(void*, size_t, size_t*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return nullptr;
}

void v8::ValueSerializer::Delegate::FreeBufferMemory(void*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::PropertyDescriptor::set_configurable(bool)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::PropertyDescriptor::set_enumerable(bool)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::Maybe<bool> v8::Object::DefineProperty(v8::Local<v8::Context>, v8::Local<v8::Name>, v8::PropertyDescriptor&)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    v8::Maybe<bool> ret = v8::Just(false);
    return ret;
}

v8::PropertyDescriptor::PropertyDescriptor(v8::Local<v8::Value>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, true, false);
}

v8::PropertyDescriptor::~PropertyDescriptor()
{
    printEmptyFuncInfo(__FUNCTION__, true, false);
}

v8::PropertyDescriptor::PropertyDescriptor(v8::Local<v8::Value>, bool)
{
    printEmptyFuncInfo(__FUNCTION__, true, false);
}

// static
const char* v8::V8::GetVersion()
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return "5.7";
}

v8::SealHandleScope::SealHandleScope(v8::Isolate*)
    : isolate_(nullptr)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::SealHandleScope::~SealHandleScope()
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

bool v8::V8::Dispose()
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

v8::MicrotasksScope::MicrotasksScope(Isolate* isolate, Type type)
    : isolate_((v8::internal::Isolate* const)isolate)
    // , microtask_queue_(nullptr)
    , run_(false)
{
}

v8::MicrotasksScope::~MicrotasksScope()
{
}

v8::Maybe<bool> v8::Object::SetIntegrityLevel(v8::Local<v8::Context>, v8::IntegrityLevel)
{
    OutputDebugStringA("v8::Object::SetIntegrityLevel is not impl\n");
    return v8::Just<bool>(true);
}

void v8::Object::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::ArrayBufferView::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

v8::MaybeLocal<v8::String> v8::Value::ToDetailString(v8::Local<v8::Context>) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
    return v8::MaybeLocal<v8::String>();
}

void v8::Boolean::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

void v8::Name::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

void v8::String::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    // DebugBreak();
}

void v8::Symbol::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

void v8::Number::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

void v8::Integer::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

void v8::Int32::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

void v8::Uint32::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

void v8::Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

void v8::Map::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

void v8::Set::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

void v8::Function::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

void v8::Promise::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

void v8::Proxy::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

void v8::WasmCompiledModule::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::ArrayBuffer::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::TypedArray::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::Uint8Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::Uint8ClampedArray::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::Int8Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::Uint16Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::Int16Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::Uint32Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    // DebugBreak();
}
void v8::Int32Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::Float32Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::Float64Array::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::DataView::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::SharedArrayBuffer::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::Date::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

void v8::NumberObject::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::BooleanObject::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::StringObject::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::SymbolObject::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::RegExp::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}
void v8::External::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    //DebugBreak();
}

// void v8::Isolate::RemoveGCPrologueCallback(void(__cdecl*)(v8::Isolate*, v8::GCType, v8::GCCallbackFlags))
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
//     DebugBreak();
// }
//
// void v8::Isolate::RemoveGCEpilogueCallback(void(__cdecl*)(v8::Isolate*, enum v8::GCType, enum v8::GCCallbackFlags))
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
//     DebugBreak();
// }

void v8::Isolate::RemoveMessageListeners(void(__cdecl*)(v8::Local<v8::Message>, v8::Local<v8::Value>))
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

void v8::Isolate::VisitExternalResources(v8::ExternalResourceVisitor*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

v8::SnapshotCreator::SnapshotCreator(intptr_t*, v8::StartupData*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

void v8::Unlocker::Initialize(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

void v8::Isolate::VisitHandlesForPartialDependence(v8::PersistentHandleVisitor*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

void v8::Promise::Resolver::CheckCast(v8::Value*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    DebugBreak();
}

v8::Local<v8::Module> v8::Module::CreateSyntheticModule(v8::Isolate*, v8::Local<v8::String>,
    std::vector<v8::Local<v8::String>, std::allocator<v8::Local<v8::String>>> const&,
    v8::MaybeLocal<v8::Value>(__cdecl*)(v8::Local<v8::Context>, v8::Local<v8::Module>))
{
    printEmptyFuncInfo(__FUNCTION__, true, true);
    //JS_PrintStack(miniv8::V8Context::getCurrentJsCtx());
    return v8::Local<v8::Module>();
}

void v8::Isolate::GetCodeRange(void**, size_t*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::GetHeapStatistics(v8::HeapStatistics*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::RemoveCallCompletedCallback(void(__cdecl*)(void))
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::RequestInterrupt(void(__cdecl*)(v8::Isolate*, void*), void*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::SetAllowCodeGenerationFromStringsCallback(v8::AllowCodeGenerationFromStringsCallback callback)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::SetAutorunMicrotasks(bool)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::SetCaptureStackTraceForUncaughtExceptions(bool, int, v8::StackTrace::StackTraceOptions)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::SetEventLogger(void(__cdecl*)(char const*, int))
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::SetFailedAccessCheckCallbackFunction(void(__cdecl*)(v8::Local<v8::Object>, v8::AccessType, v8::Local<v8::Value>))
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::SetFatalErrorHandler(void(__cdecl*)(char const*, char const*))
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::SetPromiseRejectCallback(void(__cdecl*)(v8::PromiseRejectMessage))
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::SetStackLimit(size_t)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::SetUseCounterCallback(void(__cdecl*)(v8::Isolate*, v8::Isolate::UseCounterFeature))
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Isolate::TerminateExecution(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::NativeWeakMap::Set(v8::Local<v8::Value>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::RegisterExtension(v8::Extension*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::ResourceConstraints::ConfigureDefaults(unsigned __int64, unsigned __int64)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::V8::InitializePlatform(v8::Platform*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

// void v8::V8::SetAllowCodeGenerationFromStringsCallback(bool(__cdecl*)(v8::Local<v8::Context>, v8::Local<v8::String>))
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
// }

// void v8::V8::SetCaptureStackTraceForUncaughtExceptions(bool, int, v8::StackTrace::StackTraceOptions)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
// }

void v8::V8::SetEntropySource(bool(__cdecl*)(unsigned char*, size_t))
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

// void v8::V8::SetFailedAccessCheckCallbackFunction(void(__cdecl*)(v8::Local<v8::Object>, v8::AccessType, v8::Local<v8::Value>))
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
// }

// void v8::V8::SetFatalErrorHandler(void(__cdecl*)(char const*, char const*))
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
// }

void v8::V8::SetFlagsFromCommandLine(int* argc, char**, bool remove)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    if (remove && argc) {
        *argc = 0;
    }
}

void v8::V8::SetFlagsFromString(char const*, int)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

// void v8::V8::TerminateExecution(v8::Isolate*)
// {
//     printEmptyFuncInfo(__FUNCTION__, false, false);
// }

__int64 v8::CpuProfile::GetEndTime(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

__int64 v8::CpuProfile::GetSampleTimestamp(int) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

__int64 v8::CpuProfile::GetStartTime(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

void v8::CpuProfile::Delete(void)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::CpuProfiler::SetIdle(bool)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::CpuProfiler::SetSamplingInterval(int)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::CpuProfiler::StartProfiling(v8::Local<v8::String>, bool)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Debug::CancelDebugBreak(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Debug::DebugBreak(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Debug::ProcessDebugMessages(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Debug::SendCommand(v8::Isolate*, unsigned short const*, int, v8::Debug::ClientData*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Debug::SetLiveEditEnabled(v8::Isolate*, bool)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void v8::Debug::SetMessageHandler(v8::Isolate*, void(__cdecl*)(v8::Debug::Message const&))
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}
bool v8::Debug::CheckDebugBreak(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return true;
}

bool v8::Debug::SetDebugEventListener(v8::Isolate*, void(__cdecl*)(v8::Debug::EventDetails const&), v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return true;
}

int v8::CpuProfile::GetSamplesCount(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::CpuProfileNode::GetChildrenCount(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::CpuProfileNode::GetColumnNumber(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::CpuProfileNode::GetLineNumber(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

int v8::CpuProfileNode::GetScriptId(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return 0;
}

char const* v8::CpuProfileNode::GetBailoutReason(void) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return nullptr;
}

v8::Local<v8::Context> v8::Debug::GetDebugContext(v8::Isolate*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::Local<v8::Context>();
}

v8::MaybeLocal<v8::Array> v8::Debug::GetInternalProperties(v8::Isolate*, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    ::DebugBreak();
    return v8::MaybeLocal<v8::Array>();
}

v8::MaybeLocal<v8::Value> v8::Debug::Call(v8::Local<v8::Context>, v8::Local<v8::Function>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::MaybeLocal<v8::Value>();
}

#if V8_MINOR_VERSION < 8
v8::MaybeLocal<v8::Value> v8::Debug::GetMirror(v8::Local<v8::Context>, v8::Local<v8::Value>)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return v8::MaybeLocal<v8::Value>();
}
#endif

bool v8::CpuProfileNode::GetLineTicks(struct v8::CpuProfileNode::LineTick*, unsigned int) const
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return false;
}

namespace v8 {
namespace platform {
namespace tracing {

TracingController::TracingController()
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}
TracingController::~TracingController()
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}

void TraceBufferChunk::Reset(unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}
TraceBufferChunk::TraceBufferChunk(unsigned int)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}
TraceObject* TraceBufferChunk::AddTraceEvent(size_t*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return nullptr;
}
TraceObject::~TraceObject()
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}
// static
TraceWriter* TraceWriter::CreateJSONTraceWriter(std::ostream&)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
    return nullptr;
}
void TraceConfig::AddIncludedCategory(char const*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}
void TracingController::Initialize(v8::platform::tracing::TraceBuffer*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}
void TracingController::StartTracing(v8::platform::tracing::TraceConfig*)
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}
void TracingController::StopTracing()
{
    printEmptyFuncInfo(__FUNCTION__, false, false);
}
} // namespace tracing
} // namespace platform
} // namespace v8