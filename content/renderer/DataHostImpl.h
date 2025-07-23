
#ifndef content_renderer_DataHostImpl_h
#define content_renderer_DataHostImpl_h

#include "gen/components/attribution_reporting/data_host.mojom-blink.h"
#include "gen/components/attribution_reporting/registration_header_error.mojom-blink.h"

namespace attribution_reporting {

SourceRegistration::~SourceRegistration()
{
    *(int*)1 = 1;
}

TriggerRegistration::~TriggerRegistration()
{
    *(int*)1 = 1;
}

AggregatableNamedBudgetDefs::~AggregatableNamedBudgetDefs(void)
{
    *(int*)1 = 1;
}

SourceAggregatableDebugReportingConfig::~SourceAggregatableDebugReportingConfig(void)
{
    *(int*)1 = 1;
}

AggregationKeys::~AggregationKeys(void)
{
    *(int*)1 = 1;
}

FilterData::~FilterData(void)
{
    *(int*)1 = 1;
}

TriggerSpecs::~TriggerSpecs(void)
{
    *(int*)1 = 1;
}

DestinationSet::~DestinationSet(void)
{
    *(int*)1 = 1;
}

AttributionScopesSet::~AttributionScopesSet(void)
{
    *(int*)1 = 1;
}

AggregatableDebugReportingConfig::~AggregatableDebugReportingConfig(void)
{
    *(int*)1 = 1;
}

TriggerSpec::~TriggerSpec(void)
{
    *(int*)1 = 1;
}

FilterConfig::~FilterConfig(void)
{
    *(int*)1 = 1;
}

EventReportWindows::~EventReportWindows(void)
{
    *(int*)1 = 1;
}

AggregatableTriggerConfig::~AggregatableTriggerConfig(void)
{
    *(int*)1 = 1;
}

AttributionScopesData::~AttributionScopesData(void)
{
    *(int*)1 = 1;
}

AggregatableNamedBudgetCandidate::~AggregatableNamedBudgetCandidate(void)
{
    *(int*)1 = 1;
}

AggregatableValues::~AggregatableValues(void)
{
    *(int*)1 = 1;
}

FilterPair::~FilterPair(void)
{
    *(int*)1 = 1;
}

AggregatableTriggerData::~AggregatableTriggerData(void)
{
    *(int*)1 = 1;
}

}

namespace content {

class DataHostImpl : public ::attribution_reporting::mojom::blink::DataHost {
    void SourceDataAvailable(
        ::attribution_reporting::SuitableOrigin reporting_origin, 
        ::attribution_reporting::SourceRegistration data, 
        bool was_fetched_via_service_worker) override
    {
        OutputDebugStringA("DataHostImpl::SourceDataAvailable not impl\n");
    }

    void TriggerDataAvailable(
        ::attribution_reporting::SuitableOrigin reporting_origin, 
        ::attribution_reporting::TriggerRegistration data, 
        bool was_fetched_via_service_worker)
        override
    {

    }

    void OsSourceDataAvailable(::std::vector<::attribution_reporting::OsRegistrationItem> registration, bool was_fetched_via_service_worker) override
    {

    }

    void OsTriggerDataAvailable(::std::vector<::attribution_reporting::OsRegistrationItem> registration, bool was_fetched_via_service_worker) override
    {

    }

    void ReportRegistrationHeaderError(::attribution_reporting::SuitableOrigin reporting_origin, ::attribution_reporting::RegistrationHeaderError error) override
    {

    }
};

}

#endif // content_renderer_DataHostImpl_h