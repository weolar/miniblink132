
#include "base/trace_event/process_memory_dump.h"
#include "base/trace_event/memory_allocator_dump.h"
#include "base/trace_event/trace_config.h"
#include "base/trace_event/trace_log.h"

namespace perfetto::trace_processor {

// Coordinates the loading of traces from an arbitrary source.
class TraceProcessorStorage {
public:
};
}

namespace base {
namespace trace_event {

const char MemoryAllocatorDump::kNameSize[] = "size";
const char MemoryAllocatorDump::kNameObjectCount[] = "object_count";
const char MemoryAllocatorDump::kTypeScalar[] = "scalar";
const char MemoryAllocatorDump::kTypeString[] = "string";
const char MemoryAllocatorDump::kUnitsBytes[] = "bytes";
const char MemoryAllocatorDump::kUnitsObjects[] = "objects";

class TraceBufferChunk {

};

class TraceBuffer {

};

class JsonStringOutputWriter {

};

struct TraceLog::RegisteredAsyncObserver {

};


TraceLog::TraceLog(int generation)
    : process_sort_index_(0)
    , process_id_hash_(0)
    , process_id_(base::kNullProcessId)
    , trace_options_(kInternalRecordUntilFull)
    , trace_config_(TraceConfig())
    , thread_shared_chunk_index_(0)
    , generation_(generation)
    , use_worker_thread_(false)
{

}

bool TraceLog::OnMemoryDump(MemoryDumpArgs const&, ProcessMemoryDump*)
{
    return false;
}

TraceLog::~TraceLog(void)
{

}

TraceEvent::~TraceEvent(void)
{

}

TraceLog* TraceLog::GetInstance(void)
{
    static TraceLog* s_inst = nullptr;
    if (!s_inst)
        s_inst = new TraceLog(0);
    return s_inst;
}

void TraceLog::RemoveEnabledStateObserver(TraceLog::EnabledStateObserver*)
{

}

void TraceLog::SetEnabled(const TraceConfig& trace_config, uint8_t modes_to_enable)
{

}

void TraceLog::SetDisabled(void)
{

}

void TraceLog::RemoveAsyncEnabledStateObserver(AsyncEnabledStateObserver* listener)
{

}

void TraceLog::AddEnabledStateObserver(EnabledStateObserver* listener)
{

}

void TraceLog::AddAsyncEnabledStateObserver(WeakPtr<AsyncEnabledStateObserver> listener)
{

}


MemoryAllocatorDump* ProcessMemoryDump::GetAllocatorDump(const std::string& absolute_name) const
{
    *(int*)1 = 1;
    return nullptr;
}

MemoryAllocatorDump* ProcessMemoryDump::CreateAllocatorDump(const std::string& absolute_name)
{
    *(int*)1 = 1;
    return nullptr;
}

MemoryAllocatorDump* ProcessMemoryDump::CreateAllocatorDump(const std::string& absolute_name, const MemoryAllocatorDumpGuid& guid)
{
    *(int*)1 = 1;
    return nullptr;
}

MemoryAllocatorDump* ProcessMemoryDump::CreateSharedGlobalAllocatorDump(const MemoryAllocatorDumpGuid& guid)
{
    *(int*)1 = 1;
    return nullptr;
}

MemoryAllocatorDump::~MemoryAllocatorDump()
{
    *(int*)1 = 1;
}

TraceConfig::MemoryDumpConfig::HeapProfiler::HeapProfiler(void)
{
}

TraceConfig::TraceConfig(std::string_view category_filter_string, std::string_view trace_options_string)
{
    *(int*)1 = 1;
}

TraceConfig::TraceConfig(std::string_view category_filter_string, TraceRecordMode record_mode)
{
    *(int*)1 = 1;
}

TraceConfig::ProcessFilterConfig::ProcessFilterConfig()
{
}

TraceConfig::MemoryDumpConfig::MemoryDumpConfig()
{
}

TraceConfig::MemoryDumpConfig::~MemoryDumpConfig()
{
}

TraceConfig::EventFilterConfig::~EventFilterConfig()
{
    *(int*)1 = 1;
}

TraceConfig::ProcessFilterConfig::~ProcessFilterConfig()
{
    *(int*)1 = 1;
}

void ProcessMemoryDump::AddOwnershipEdge(const MemoryAllocatorDumpGuid& source, const MemoryAllocatorDumpGuid& target, int importance)
{
    *(int*)1 = 1;
}

void ProcessMemoryDump::AddOwnershipEdge(const MemoryAllocatorDumpGuid& source, const MemoryAllocatorDumpGuid& target)
{
    *(int*)1 = 1;
}

void ProcessMemoryDump::AddSuballocation(const MemoryAllocatorDumpGuid& source, const std::string& target_node_name)
{
    *(int*)1 = 1;
}

void ProcessMemoryDump::Clear()
{
    *(int*)1 = 1;
}

void ProcessMemoryDump::CreateSharedMemoryOwnershipEdge(const MemoryAllocatorDumpGuid& client_local_dump_guid, const UnguessableToken& shared_memory_guid, int importance)
{
    *(int*)1 = 1;
}

void ProcessMemoryDump::DumpHeapUsage(const std::unordered_map<base::trace_event::AllocationContext, base::trace_event::AllocationMetrics>& metrics_by_context,
    base::trace_event::TraceEventMemoryOverhead& overhead, const char* allocator_name)
{
    *(int*)1 = 1;
}

void ProcessMemoryDump::TakeAllDumpsFrom(ProcessMemoryDump* other)
{
    *(int*)1 = 1;
}

void MemoryAllocatorDump::AddScalar(const char* name, const char* units, uint64_t value)
{
    *(int*)1 = 1;
}

void MemoryAllocatorDump::AddString(const char* name, const char* units, const std::string& value)
{
    *(int*)1 = 1;
}

TraceConfig::~TraceConfig(void)
{

}

TraceConfig::TraceConfig()
{

}

ProcessMemoryDump::~ProcessMemoryDump(void)
{
    *(int*)1 = 1;
}

ProcessMemoryDump::ProcessMemoryDump(const MemoryDumpArgs&)
{
    *(int*)1 = 1;
}

} // trace_event
} // base