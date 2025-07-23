
// Generated from gen_builders.py.  DO NOT EDIT!
// source: dwa.xml

#include "components/metrics/dwa//dwa_decode.h"
#include "components/metrics/dwa//dwa_builders.h"

namespace dwa {
namespace builders {

std::map<uint64_t, EntryDecoder> CreateDecodeMap()
{
    return {

        { UINT64_C(10084375266486398523),
            { DwaTestMetric::kEntryName,
                {

                    { DwaTestMetric::kHasVideoNameHash, DwaTestMetric::kHasVideoName },

                    { DwaTestMetric::kLatencyNameHash, DwaTestMetric::kLatencyName },

                },
                {

                    { DwaTestMetric::kACTStudyNameHash, DwaTestMetric::kACTStudyName },

                    { DwaTestMetric::kLegacyStudyNameHash, DwaTestMetric::kLegacyStudyName },

                    { DwaTestMetric::kModeBStudyNameHash, DwaTestMetric::kModeBStudyName },

                } } },

    };
}

} // namespace builders
} // namespace dwa
