
// Generated from gen_builders.py.  DO NOT EDIT!
// source: dwa.xml

#ifndef COMPONENTS_METRICS_DWA_DWA_DECODE_H
#define COMPONENTS_METRICS_DWA_DWA_DECODE_H

#include <cstdint>
#include <map>

namespace dwa {
namespace builders {

typedef std::map<uint64_t, const char*> MetricDecodeMap;
typedef std::map<uint32_t, const char*> StudyDecodeMap;
struct EntryDecoder {
    const char* name;
    const MetricDecodeMap metric_map;
    const StudyDecodeMap study_map;
};
typedef std::map<uint64_t, EntryDecoder> DecodeMap;
DecodeMap CreateDecodeMap();

} // namespace builders
} // namespace dwa

#endif // COMPONENTS_METRICS_DWA_DWA_DECODE_H
