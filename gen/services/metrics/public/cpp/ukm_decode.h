
// Generated from gen_builders.py.  DO NOT EDIT!
// source: ukm.xml

#ifndef SERVICES_METRICS_PUBLIC_CPP_UKM_DECODE_H
#define SERVICES_METRICS_PUBLIC_CPP_UKM_DECODE_H

#include <cstdint>
#include <map>

namespace ukm {
namespace builders {

typedef std::map<uint64_t, const char*> MetricDecodeMap;
struct EntryDecoder {
    const char* name;
    const MetricDecodeMap metric_map;
};
typedef std::map<uint64_t, EntryDecoder> DecodeMap;
DecodeMap CreateDecodeMap();

} // namespace builders
} // namespace ukm

#endif // SERVICES_METRICS_PUBLIC_CPP_UKM_DECODE_H
