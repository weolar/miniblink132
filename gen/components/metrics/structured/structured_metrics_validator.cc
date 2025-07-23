// Generated from gen_validator.py. DO NOT EDIT!
// source: structured.xml

#include "components/metrics/structured/structured_metrics_validator.h"

#include <cstdint>
#include <string>

#include "components/metrics/structured/enums.h"
#include "components/metrics/structured/event.h"
#include "components/metrics/structured/event_validator.h"
#include "components/metrics/structured/project_validator.h"
#include <optional>
#include "third_party/metrics_proto/structured_data.pb.h"

namespace metrics {
namespace structured {

namespace {

//---------------------EventValidator Classes----------------------------------
class PopularDisplays_MonitorInfoEventValidator final : public ::metrics::structured::EventValidator {
public:
    PopularDisplays_MonitorInfoEventValidator();
    ~PopularDisplays_MonitorInfoEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(2134486541903110786);
};

PopularDisplays_MonitorInfoEventValidator::PopularDisplays_MonitorInfoEventValidator()
    : ::metrics::structured::EventValidator(PopularDisplays_MonitorInfoEventValidator::kEventNameHash, false)
{
    Initialize();
}

PopularDisplays_MonitorInfoEventValidator::~PopularDisplays_MonitorInfoEventValidator() = default;

void PopularDisplays_MonitorInfoEventValidator::Initialize()
{
    metric_metadata_ = { { "DisplayName", { Event::MetricType::kRawString, UINT64_C(4289270646520720629) } },
        { "ManufacturerId", { Event::MetricType::kRawString, UINT64_C(15125530491922306148) } },
        { "ProductId", { Event::MetricType::kLong, UINT64_C(3765840483194334735) } },
        { "NativeModeSize", { Event::MetricType::kRawString, UINT64_C(5170292205527742159) } },
        { "NativeModeRefreshRate", { Event::MetricType::kDouble, UINT64_C(5698152332635855491) } },
        { "PhysicalSize", { Event::MetricType::kRawString, UINT64_C(17526088120773883476) } },
        { "ConnectionType", { Event::MetricType::kRawString, UINT64_C(15958005172467117203) } },
        { "IsVrrCapable", { Event::MetricType::kLong, UINT64_C(6788392488518635712) } } };

    metrics_name_map_ = { { UINT64_C(4289270646520720629), "DisplayName" }, { UINT64_C(15125530491922306148), "ManufacturerId" },
        { UINT64_C(3765840483194334735), "ProductId" }, { UINT64_C(5170292205527742159), "NativeModeSize" },
        { UINT64_C(5698152332635855491), "NativeModeRefreshRate" }, { UINT64_C(17526088120773883476), "PhysicalSize" },
        { UINT64_C(15958005172467117203), "ConnectionType" }, { UINT64_C(6788392488518635712), "IsVrrCapable" } };
}
class FastPair_DiscoveryNotificationShownEventValidator final : public ::metrics::structured::EventValidator {
public:
    FastPair_DiscoveryNotificationShownEventValidator();
    ~FastPair_DiscoveryNotificationShownEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(9794167847225427927);
};

FastPair_DiscoveryNotificationShownEventValidator::FastPair_DiscoveryNotificationShownEventValidator()
    : ::metrics::structured::EventValidator(FastPair_DiscoveryNotificationShownEventValidator::kEventNameHash, false)
{
    Initialize();
}

FastPair_DiscoveryNotificationShownEventValidator::~FastPair_DiscoveryNotificationShownEventValidator() = default;

void FastPair_DiscoveryNotificationShownEventValidator::Initialize()
{
    metric_metadata_ = { { "Protocol", { Event::MetricType::kLong, UINT64_C(9838808232981121206) } },
        { "FastPairVersion", { Event::MetricType::kLong, UINT64_C(7275670451123585686) } },
        { "ModelId", { Event::MetricType::kLong, UINT64_C(3121773042410042095) } }, { "RSSI", { Event::MetricType::kLong, UINT64_C(7508615291271386745) } },
        { "TxPower", { Event::MetricType::kLong, UINT64_C(1493188836192841721) } } };

    metrics_name_map_ = { { UINT64_C(9838808232981121206), "Protocol" }, { UINT64_C(7275670451123585686), "FastPairVersion" },
        { UINT64_C(3121773042410042095), "ModelId" }, { UINT64_C(7508615291271386745), "RSSI" }, { UINT64_C(1493188836192841721), "TxPower" } };
}

class FastPair_PairingStartEventValidator final : public ::metrics::structured::EventValidator {
public:
    FastPair_PairingStartEventValidator();
    ~FastPair_PairingStartEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(2342185101128577068);
};

FastPair_PairingStartEventValidator::FastPair_PairingStartEventValidator()
    : ::metrics::structured::EventValidator(FastPair_PairingStartEventValidator::kEventNameHash, false)
{
    Initialize();
}

FastPair_PairingStartEventValidator::~FastPair_PairingStartEventValidator() = default;

void FastPair_PairingStartEventValidator::Initialize()
{
    metric_metadata_ = { { "Protocol", { Event::MetricType::kLong, UINT64_C(9838808232981121206) } },
        { "FastPairVersion", { Event::MetricType::kLong, UINT64_C(7275670451123585686) } },
        { "ModelId", { Event::MetricType::kLong, UINT64_C(3121773042410042095) } }, { "RSSI", { Event::MetricType::kLong, UINT64_C(7508615291271386745) } },
        { "TxPower", { Event::MetricType::kLong, UINT64_C(1493188836192841721) } } };

    metrics_name_map_ = { { UINT64_C(9838808232981121206), "Protocol" }, { UINT64_C(7275670451123585686), "FastPairVersion" },
        { UINT64_C(3121773042410042095), "ModelId" }, { UINT64_C(7508615291271386745), "RSSI" }, { UINT64_C(1493188836192841721), "TxPower" } };
}

class FastPair_PairingCompleteEventValidator final : public ::metrics::structured::EventValidator {
public:
    FastPair_PairingCompleteEventValidator();
    ~FastPair_PairingCompleteEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(7548910873986616453);
};

FastPair_PairingCompleteEventValidator::FastPair_PairingCompleteEventValidator()
    : ::metrics::structured::EventValidator(FastPair_PairingCompleteEventValidator::kEventNameHash, false)
{
    Initialize();
}

FastPair_PairingCompleteEventValidator::~FastPair_PairingCompleteEventValidator() = default;

void FastPair_PairingCompleteEventValidator::Initialize()
{
    metric_metadata_ = { { "Protocol", { Event::MetricType::kLong, UINT64_C(9838808232981121206) } },
        { "FastPairVersion", { Event::MetricType::kLong, UINT64_C(7275670451123585686) } },
        { "ModelId", { Event::MetricType::kLong, UINT64_C(3121773042410042095) } }, { "RSSI", { Event::MetricType::kLong, UINT64_C(7508615291271386745) } },
        { "TxPower", { Event::MetricType::kLong, UINT64_C(1493188836192841721) } } };

    metrics_name_map_ = { { UINT64_C(9838808232981121206), "Protocol" }, { UINT64_C(7275670451123585686), "FastPairVersion" },
        { UINT64_C(3121773042410042095), "ModelId" }, { UINT64_C(7508615291271386745), "RSSI" }, { UINT64_C(1493188836192841721), "TxPower" } };
}

class FastPair_PairFailureEventValidator final : public ::metrics::structured::EventValidator {
public:
    FastPair_PairFailureEventValidator();
    ~FastPair_PairFailureEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(17174637411246838540);
};

FastPair_PairFailureEventValidator::FastPair_PairFailureEventValidator()
    : ::metrics::structured::EventValidator(FastPair_PairFailureEventValidator::kEventNameHash, false)
{
    Initialize();
}

FastPair_PairFailureEventValidator::~FastPair_PairFailureEventValidator() = default;

void FastPair_PairFailureEventValidator::Initialize()
{
    metric_metadata_ = { { "Protocol", { Event::MetricType::kLong, UINT64_C(9838808232981121206) } },
        { "FastPairVersion", { Event::MetricType::kLong, UINT64_C(7275670451123585686) } },
        { "Reason", { Event::MetricType::kLong, UINT64_C(18445816987321669298) } },
        { "ModelId", { Event::MetricType::kLong, UINT64_C(3121773042410042095) } } };

    metrics_name_map_ = { { UINT64_C(9838808232981121206), "Protocol" }, { UINT64_C(7275670451123585686), "FastPairVersion" },
        { UINT64_C(18445816987321669298), "Reason" }, { UINT64_C(3121773042410042095), "ModelId" } };
}
class Hindsight_CrOSActionEvent_FileOpenedEventValidator final : public ::metrics::structured::EventValidator {
public:
    Hindsight_CrOSActionEvent_FileOpenedEventValidator();
    ~Hindsight_CrOSActionEvent_FileOpenedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(6176288366907657397);
};

Hindsight_CrOSActionEvent_FileOpenedEventValidator::Hindsight_CrOSActionEvent_FileOpenedEventValidator()
    : ::metrics::structured::EventValidator(Hindsight_CrOSActionEvent_FileOpenedEventValidator::kEventNameHash, false)
{
    Initialize();
}

Hindsight_CrOSActionEvent_FileOpenedEventValidator::~Hindsight_CrOSActionEvent_FileOpenedEventValidator() = default;

void Hindsight_CrOSActionEvent_FileOpenedEventValidator::Initialize()
{
    metric_metadata_ = { { "Filename", { Event::MetricType::kHmac, UINT64_C(1391895386658060561) } },
        { "OpenType", { Event::MetricType::kLong, UINT64_C(10506272911216643482) } },
        { "SequenceId", { Event::MetricType::kLong, UINT64_C(8860601784949375835) } },
        { "TimeSinceLastAction", { Event::MetricType::kLong, UINT64_C(15150636701605912378) } } };

    metrics_name_map_ = { { UINT64_C(1391895386658060561), "Filename" }, { UINT64_C(10506272911216643482), "OpenType" },
        { UINT64_C(8860601784949375835), "SequenceId" }, { UINT64_C(15150636701605912378), "TimeSinceLastAction" } };
}

class Hindsight_CrOSActionEvent_SearchResultLaunchedEventValidator final : public ::metrics::structured::EventValidator {
public:
    Hindsight_CrOSActionEvent_SearchResultLaunchedEventValidator();
    ~Hindsight_CrOSActionEvent_SearchResultLaunchedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(7258544623737125992);
};

Hindsight_CrOSActionEvent_SearchResultLaunchedEventValidator::Hindsight_CrOSActionEvent_SearchResultLaunchedEventValidator()
    : ::metrics::structured::EventValidator(Hindsight_CrOSActionEvent_SearchResultLaunchedEventValidator::kEventNameHash, false)
{
    Initialize();
}

Hindsight_CrOSActionEvent_SearchResultLaunchedEventValidator::~Hindsight_CrOSActionEvent_SearchResultLaunchedEventValidator() = default;

void Hindsight_CrOSActionEvent_SearchResultLaunchedEventValidator::Initialize()
{
    metric_metadata_ = { { "Query", { Event::MetricType::kHmac, UINT64_C(7404398033256593499) } },
        { "ResultType", { Event::MetricType::kLong, UINT64_C(8293845286137751377) } },
        { "SearchResultId", { Event::MetricType::kHmac, UINT64_C(8748164516837068211) } },
        { "SequenceId", { Event::MetricType::kLong, UINT64_C(8860601784949375835) } },
        { "TimeSinceLastAction", { Event::MetricType::kLong, UINT64_C(15150636701605912378) } } };

    metrics_name_map_
        = { { UINT64_C(7404398033256593499), "Query" }, { UINT64_C(8293845286137751377), "ResultType" }, { UINT64_C(8748164516837068211), "SearchResultId" },
              { UINT64_C(8860601784949375835), "SequenceId" }, { UINT64_C(15150636701605912378), "TimeSinceLastAction" } };
}

class Hindsight_CrOSActionEvent_SettingChangedEventValidator final : public ::metrics::structured::EventValidator {
public:
    Hindsight_CrOSActionEvent_SettingChangedEventValidator();
    ~Hindsight_CrOSActionEvent_SettingChangedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(15173432087155953262);
};

Hindsight_CrOSActionEvent_SettingChangedEventValidator::Hindsight_CrOSActionEvent_SettingChangedEventValidator()
    : ::metrics::structured::EventValidator(Hindsight_CrOSActionEvent_SettingChangedEventValidator::kEventNameHash, false)
{
    Initialize();
}

Hindsight_CrOSActionEvent_SettingChangedEventValidator::~Hindsight_CrOSActionEvent_SettingChangedEventValidator() = default;

void Hindsight_CrOSActionEvent_SettingChangedEventValidator::Initialize()
{
    metric_metadata_ = { { "CurrentValue", { Event::MetricType::kLong, UINT64_C(4480604349707933716) } },
        { "PreviousValue", { Event::MetricType::kLong, UINT64_C(12685882687934574180) } },
        { "SequenceId", { Event::MetricType::kLong, UINT64_C(8860601784949375835) } },
        { "SettingId", { Event::MetricType::kLong, UINT64_C(8375811908993639483) } },
        { "SettingType", { Event::MetricType::kLong, UINT64_C(211450250705861929) } },
        { "TimeSinceLastAction", { Event::MetricType::kLong, UINT64_C(15150636701605912378) } } };

    metrics_name_map_ = { { UINT64_C(4480604349707933716), "CurrentValue" }, { UINT64_C(12685882687934574180), "PreviousValue" },
        { UINT64_C(8860601784949375835), "SequenceId" }, { UINT64_C(8375811908993639483), "SettingId" }, { UINT64_C(211450250705861929), "SettingType" },
        { UINT64_C(15150636701605912378), "TimeSinceLastAction" } };
}

class Hindsight_CrOSActionEvent_TabEvent_TabNavigatedEventValidator final : public ::metrics::structured::EventValidator {
public:
    Hindsight_CrOSActionEvent_TabEvent_TabNavigatedEventValidator();
    ~Hindsight_CrOSActionEvent_TabEvent_TabNavigatedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(11495565264134779777);
};

Hindsight_CrOSActionEvent_TabEvent_TabNavigatedEventValidator::Hindsight_CrOSActionEvent_TabEvent_TabNavigatedEventValidator()
    : ::metrics::structured::EventValidator(Hindsight_CrOSActionEvent_TabEvent_TabNavigatedEventValidator::kEventNameHash, false)
{
    Initialize();
}

Hindsight_CrOSActionEvent_TabEvent_TabNavigatedEventValidator::~Hindsight_CrOSActionEvent_TabEvent_TabNavigatedEventValidator() = default;

void Hindsight_CrOSActionEvent_TabEvent_TabNavigatedEventValidator::Initialize()
{
    metric_metadata_ = { { "PageTransition", { Event::MetricType::kLong, UINT64_C(17736770626535281502) } },
        { "SequenceId", { Event::MetricType::kLong, UINT64_C(8860601784949375835) } },
        { "TimeSinceLastAction", { Event::MetricType::kLong, UINT64_C(15150636701605912378) } },
        { "URL", { Event::MetricType::kHmac, UINT64_C(16623790803831280729) } },
        { "Visibility", { Event::MetricType::kLong, UINT64_C(1669047024429367828) } } };

    metrics_name_map_ = { { UINT64_C(17736770626535281502), "PageTransition" }, { UINT64_C(8860601784949375835), "SequenceId" },
        { UINT64_C(15150636701605912378), "TimeSinceLastAction" }, { UINT64_C(16623790803831280729), "URL" }, { UINT64_C(1669047024429367828), "Visibility" } };
}

class Hindsight_CrOSActionEvent_TabEvent_TabOpenedEventValidator final : public ::metrics::structured::EventValidator {
public:
    Hindsight_CrOSActionEvent_TabEvent_TabOpenedEventValidator();
    ~Hindsight_CrOSActionEvent_TabEvent_TabOpenedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(13824184328368382026);
};

Hindsight_CrOSActionEvent_TabEvent_TabOpenedEventValidator::Hindsight_CrOSActionEvent_TabEvent_TabOpenedEventValidator()
    : ::metrics::structured::EventValidator(Hindsight_CrOSActionEvent_TabEvent_TabOpenedEventValidator::kEventNameHash, false)
{
    Initialize();
}

Hindsight_CrOSActionEvent_TabEvent_TabOpenedEventValidator::~Hindsight_CrOSActionEvent_TabEvent_TabOpenedEventValidator() = default;

void Hindsight_CrOSActionEvent_TabEvent_TabOpenedEventValidator::Initialize()
{
    metric_metadata_ = { { "SequenceId", { Event::MetricType::kLong, UINT64_C(8860601784949375835) } },
        { "TimeSinceLastAction", { Event::MetricType::kLong, UINT64_C(15150636701605912378) } },
        { "URL", { Event::MetricType::kHmac, UINT64_C(16623790803831280729) } }, { "URLOpened", { Event::MetricType::kHmac, UINT64_C(7878775340823931445) } },
        { "WindowOpenDisposition", { Event::MetricType::kLong, UINT64_C(17804395139469765033) } } };

    metrics_name_map_ = { { UINT64_C(8860601784949375835), "SequenceId" }, { UINT64_C(15150636701605912378), "TimeSinceLastAction" },
        { UINT64_C(16623790803831280729), "URL" }, { UINT64_C(7878775340823931445), "URLOpened" },
        { UINT64_C(17804395139469765033), "WindowOpenDisposition" } };
}

class Hindsight_CrOSActionEvent_TabEvent_TabReactivatedEventValidator final : public ::metrics::structured::EventValidator {
public:
    Hindsight_CrOSActionEvent_TabEvent_TabReactivatedEventValidator();
    ~Hindsight_CrOSActionEvent_TabEvent_TabReactivatedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(1414982393805218127);
};

Hindsight_CrOSActionEvent_TabEvent_TabReactivatedEventValidator::Hindsight_CrOSActionEvent_TabEvent_TabReactivatedEventValidator()
    : ::metrics::structured::EventValidator(Hindsight_CrOSActionEvent_TabEvent_TabReactivatedEventValidator::kEventNameHash, false)
{
    Initialize();
}

Hindsight_CrOSActionEvent_TabEvent_TabReactivatedEventValidator::~Hindsight_CrOSActionEvent_TabEvent_TabReactivatedEventValidator() = default;

void Hindsight_CrOSActionEvent_TabEvent_TabReactivatedEventValidator::Initialize()
{
    metric_metadata_ = { { "SequenceId", { Event::MetricType::kLong, UINT64_C(8860601784949375835) } },
        { "TimeSinceLastAction", { Event::MetricType::kLong, UINT64_C(15150636701605912378) } },
        { "URL", { Event::MetricType::kHmac, UINT64_C(16623790803831280729) } } };

    metrics_name_map_ = { { UINT64_C(8860601784949375835), "SequenceId" }, { UINT64_C(15150636701605912378), "TimeSinceLastAction" },
        { UINT64_C(16623790803831280729), "URL" } };
}
class LauncherUsage_LauncherUsageEventValidator final : public ::metrics::structured::EventValidator {
public:
    LauncherUsage_LauncherUsageEventValidator();
    ~LauncherUsage_LauncherUsageEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(338987758122020898);
};

LauncherUsage_LauncherUsageEventValidator::LauncherUsage_LauncherUsageEventValidator()
    : ::metrics::structured::EventValidator(LauncherUsage_LauncherUsageEventValidator::kEventNameHash, false)
{
    Initialize();
}

LauncherUsage_LauncherUsageEventValidator::~LauncherUsage_LauncherUsageEventValidator() = default;

void LauncherUsage_LauncherUsageEventValidator::Initialize()
{
    metric_metadata_ = { { "App", { Event::MetricType::kHmac, UINT64_C(12431693315825569690) } },
        { "Domain", { Event::MetricType::kHmac, UINT64_C(16926279638941368063) } }, { "Hour", { Event::MetricType::kLong, UINT64_C(13068971801390763210) } },
        { "ProviderType", { Event::MetricType::kLong, UINT64_C(15485758544594317646) } },
        { "Score", { Event::MetricType::kLong, UINT64_C(6760243690594795363) } },
        { "SearchQuery", { Event::MetricType::kHmac, UINT64_C(3417621012679571145) } },
        { "SearchQueryLength", { Event::MetricType::kLong, UINT64_C(12117433152880007486) } },
        { "Target", { Event::MetricType::kHmac, UINT64_C(14130661245465482316) } } };

    metrics_name_map_ = { { UINT64_C(12431693315825569690), "App" }, { UINT64_C(16926279638941368063), "Domain" }, { UINT64_C(13068971801390763210), "Hour" },
        { UINT64_C(15485758544594317646), "ProviderType" }, { UINT64_C(6760243690594795363), "Score" }, { UINT64_C(3417621012679571145), "SearchQuery" },
        { UINT64_C(12117433152880007486), "SearchQueryLength" }, { UINT64_C(14130661245465482316), "Target" } };
}
class NearbyShare_DiscoveryEventValidator final : public ::metrics::structured::EventValidator {
public:
    NearbyShare_DiscoveryEventValidator();
    ~NearbyShare_DiscoveryEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(8121790022846552438);
};

NearbyShare_DiscoveryEventValidator::NearbyShare_DiscoveryEventValidator()
    : ::metrics::structured::EventValidator(NearbyShare_DiscoveryEventValidator::kEventNameHash, false)
{
    Initialize();
}

NearbyShare_DiscoveryEventValidator::~NearbyShare_DiscoveryEventValidator() = default;

void NearbyShare_DiscoveryEventValidator::Initialize()
{
    metric_metadata_ = { { "Platform", { Event::MetricType::kLong, UINT64_C(4728558894243024398) } },
        { "DeviceRelationship", { Event::MetricType::kLong, UINT64_C(13896013314141638305) } },
        { "TimeToDiscovery", { Event::MetricType::kLong, UINT64_C(11511130230327788576) } } };

    metrics_name_map_ = { { UINT64_C(4728558894243024398), "Platform" }, { UINT64_C(13896013314141638305), "DeviceRelationship" },
        { UINT64_C(11511130230327788576), "TimeToDiscovery" } };
}

class NearbyShare_ThroughputEventValidator final : public ::metrics::structured::EventValidator {
public:
    NearbyShare_ThroughputEventValidator();
    ~NearbyShare_ThroughputEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(12486561721064188940);
};

NearbyShare_ThroughputEventValidator::NearbyShare_ThroughputEventValidator()
    : ::metrics::structured::EventValidator(NearbyShare_ThroughputEventValidator::kEventNameHash, false)
{
    Initialize();
}

NearbyShare_ThroughputEventValidator::~NearbyShare_ThroughputEventValidator() = default;

void NearbyShare_ThroughputEventValidator::Initialize()
{
    metric_metadata_ = { { "IsReceiving", { Event::MetricType::kLong, UINT64_C(9128428000102963387) } },
        { "Platform", { Event::MetricType::kLong, UINT64_C(4728558894243024398) } },
        { "DeviceRelationship", { Event::MetricType::kLong, UINT64_C(13896013314141638305) } },
        { "Medium", { Event::MetricType::kLong, UINT64_C(9797764244958727891) } },
        { "UpdateBytes", { Event::MetricType::kLong, UINT64_C(408764248645399113) } },
        { "UpdateMillis", { Event::MetricType::kLong, UINT64_C(12242757734491391520) } },
        { "TransferredBytes", { Event::MetricType::kLong, UINT64_C(9118773029146018532) } },
        { "TotalTransferBytes", { Event::MetricType::kLong, UINT64_C(5936024394832739350) } } };

    metrics_name_map_ = { { UINT64_C(9128428000102963387), "IsReceiving" }, { UINT64_C(4728558894243024398), "Platform" },
        { UINT64_C(13896013314141638305), "DeviceRelationship" }, { UINT64_C(9797764244958727891), "Medium" }, { UINT64_C(408764248645399113), "UpdateBytes" },
        { UINT64_C(12242757734491391520), "UpdateMillis" }, { UINT64_C(9118773029146018532), "TransferredBytes" },
        { UINT64_C(5936024394832739350), "TotalTransferBytes" } };
}

class NearbyShare_FileAttachmentEventValidator final : public ::metrics::structured::EventValidator {
public:
    NearbyShare_FileAttachmentEventValidator();
    ~NearbyShare_FileAttachmentEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(16611026906961162750);
};

NearbyShare_FileAttachmentEventValidator::NearbyShare_FileAttachmentEventValidator()
    : ::metrics::structured::EventValidator(NearbyShare_FileAttachmentEventValidator::kEventNameHash, false)
{
    Initialize();
}

NearbyShare_FileAttachmentEventValidator::~NearbyShare_FileAttachmentEventValidator() = default;

void NearbyShare_FileAttachmentEventValidator::Initialize()
{
    metric_metadata_ = { { "IsReceiving", { Event::MetricType::kLong, UINT64_C(9128428000102963387) } },
        { "Platform", { Event::MetricType::kLong, UINT64_C(4728558894243024398) } },
        { "DeviceRelationship", { Event::MetricType::kLong, UINT64_C(13896013314141638305) } },
        { "FileType", { Event::MetricType::kLong, UINT64_C(1646892813222506878) } }, { "Size", { Event::MetricType::kLong, UINT64_C(8028993641010258682) } },
        { "Result", { Event::MetricType::kLong, UINT64_C(10298151285721392449) } } };

    metrics_name_map_ = { { UINT64_C(9128428000102963387), "IsReceiving" }, { UINT64_C(4728558894243024398), "Platform" },
        { UINT64_C(13896013314141638305), "DeviceRelationship" }, { UINT64_C(1646892813222506878), "FileType" }, { UINT64_C(8028993641010258682), "Size" },
        { UINT64_C(10298151285721392449), "Result" } };
}

class NearbyShare_TextAttachmentEventValidator final : public ::metrics::structured::EventValidator {
public:
    NearbyShare_TextAttachmentEventValidator();
    ~NearbyShare_TextAttachmentEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(6709412692638581792);
};

NearbyShare_TextAttachmentEventValidator::NearbyShare_TextAttachmentEventValidator()
    : ::metrics::structured::EventValidator(NearbyShare_TextAttachmentEventValidator::kEventNameHash, false)
{
    Initialize();
}

NearbyShare_TextAttachmentEventValidator::~NearbyShare_TextAttachmentEventValidator() = default;

void NearbyShare_TextAttachmentEventValidator::Initialize()
{
    metric_metadata_ = { { "IsReceiving", { Event::MetricType::kLong, UINT64_C(9128428000102963387) } },
        { "Platform", { Event::MetricType::kLong, UINT64_C(4728558894243024398) } },
        { "DeviceRelationship", { Event::MetricType::kLong, UINT64_C(13896013314141638305) } },
        { "TextType", { Event::MetricType::kLong, UINT64_C(17216547163414011577) } }, { "Size", { Event::MetricType::kLong, UINT64_C(8028993641010258682) } },
        { "Result", { Event::MetricType::kLong, UINT64_C(10298151285721392449) } } };

    metrics_name_map_ = { { UINT64_C(9128428000102963387), "IsReceiving" }, { UINT64_C(4728558894243024398), "Platform" },
        { UINT64_C(13896013314141638305), "DeviceRelationship" }, { UINT64_C(17216547163414011577), "TextType" }, { UINT64_C(8028993641010258682), "Size" },
        { UINT64_C(10298151285721392449), "Result" } };
}

class NearbyShare_ShareSessionEventValidator final : public ::metrics::structured::EventValidator {
public:
    NearbyShare_ShareSessionEventValidator();
    ~NearbyShare_ShareSessionEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(3465270551632052329);
};

NearbyShare_ShareSessionEventValidator::NearbyShare_ShareSessionEventValidator()
    : ::metrics::structured::EventValidator(NearbyShare_ShareSessionEventValidator::kEventNameHash, false)
{
    Initialize();
}

NearbyShare_ShareSessionEventValidator::~NearbyShare_ShareSessionEventValidator() = default;

void NearbyShare_ShareSessionEventValidator::Initialize()
{
    metric_metadata_ = { { "IsReceiving", { Event::MetricType::kLong, UINT64_C(9128428000102963387) } },
        { "Platform", { Event::MetricType::kLong, UINT64_C(4728558894243024398) } },
        { "DeviceRelationship", { Event::MetricType::kLong, UINT64_C(13896013314141638305) } },
        { "TimeToDiscovery", { Event::MetricType::kLong, UINT64_C(11511130230327788576) } },
        { "TimeToSelect", { Event::MetricType::kLong, UINT64_C(9117514697115207368) } },
        { "TimeToConnect", { Event::MetricType::kLong, UINT64_C(13628493367322951889) } },
        { "TimeToAccept", { Event::MetricType::kLong, UINT64_C(6624773114135395023) } },
        { "TimeToTransferComplete", { Event::MetricType::kLong, UINT64_C(1950847233332487065) } },
        { "InitialMedium", { Event::MetricType::kLong, UINT64_C(8520335851354841661) } },
        { "TimeToUpgrade", { Event::MetricType::kLong, UINT64_C(8775751502897238848) } },
        { "FinalMedium", { Event::MetricType::kLong, UINT64_C(10668180146530993290) } },
        { "NumberOfFiles", { Event::MetricType::kLong, UINT64_C(11792151616168586475) } },
        { "NumberOfTexts", { Event::MetricType::kLong, UINT64_C(2367228332571108755) } },
        { "NumberOfWiFiCredentials", { Event::MetricType::kLong, UINT64_C(15567319932061774315) } },
        { "TotalTransferBytes", { Event::MetricType::kLong, UINT64_C(5936024394832739350) } },
        { "BytesTransferred", { Event::MetricType::kLong, UINT64_C(3708151605264891472) } },
        { "Result", { Event::MetricType::kLong, UINT64_C(10298151285721392449) } } };

    metrics_name_map_ = { { UINT64_C(9128428000102963387), "IsReceiving" }, { UINT64_C(4728558894243024398), "Platform" },
        { UINT64_C(13896013314141638305), "DeviceRelationship" }, { UINT64_C(11511130230327788576), "TimeToDiscovery" },
        { UINT64_C(9117514697115207368), "TimeToSelect" }, { UINT64_C(13628493367322951889), "TimeToConnect" },
        { UINT64_C(6624773114135395023), "TimeToAccept" }, { UINT64_C(1950847233332487065), "TimeToTransferComplete" },
        { UINT64_C(8520335851354841661), "InitialMedium" }, { UINT64_C(8775751502897238848), "TimeToUpgrade" },
        { UINT64_C(10668180146530993290), "FinalMedium" }, { UINT64_C(11792151616168586475), "NumberOfFiles" },
        { UINT64_C(2367228332571108755), "NumberOfTexts" }, { UINT64_C(15567319932061774315), "NumberOfWiFiCredentials" },
        { UINT64_C(5936024394832739350), "TotalTransferBytes" }, { UINT64_C(3708151605264891472), "BytesTransferred" },
        { UINT64_C(10298151285721392449), "Result" } };
}
class PhoneHub_SessionDetailsEventValidator final : public ::metrics::structured::EventValidator {
public:
    PhoneHub_SessionDetailsEventValidator();
    ~PhoneHub_SessionDetailsEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(14629822153912792501);
};

PhoneHub_SessionDetailsEventValidator::PhoneHub_SessionDetailsEventValidator()
    : ::metrics::structured::EventValidator(PhoneHub_SessionDetailsEventValidator::kEventNameHash, false)
{
    Initialize();
}

PhoneHub_SessionDetailsEventValidator::~PhoneHub_SessionDetailsEventValidator() = default;

void PhoneHub_SessionDetailsEventValidator::Initialize()
{
    metric_metadata_ = { { "SessionId", { Event::MetricType::kRawString, UINT64_C(4297293875635157131) } },
        { "Timestamp", { Event::MetricType::kLong, UINT64_C(11805586358985797642) } },
        { "ConnectionMedium", { Event::MetricType::kLong, UINT64_C(13131851803141078605) } },
        { "ChromebookBluetoothStack", { Event::MetricType::kLong, UINT64_C(15110970193774360897) } },
        { "DevicesNetworkState", { Event::MetricType::kLong, UINT64_C(5557047930145251011) } },
        { "ChromebookLocale", { Event::MetricType::kRawString, UINT64_C(17301340632531771882) } },
        { "ChromebookPseudonymousId", { Event::MetricType::kRawString, UINT64_C(15157035504208410273) } },
        { "PhoneManufacturer", { Event::MetricType::kRawString, UINT64_C(13371302375274686383) } },
        { "PhoneModel", { Event::MetricType::kRawString, UINT64_C(14454608432121246609) } },
        { "PhoneAndroidVersion", { Event::MetricType::kLong, UINT64_C(17812242366157473801) } },
        { "PhoneAmbientApkVersion", { Event::MetricType::kLong, UINT64_C(12805024565569487205) } },
        { "PhoneGmsCoreVersion", { Event::MetricType::kLong, UINT64_C(6418828325351853188) } },
        { "PhoneProfile", { Event::MetricType::kLong, UINT64_C(10168993227198787982) } },
        { "PhoneNetworkStatus", { Event::MetricType::kLong, UINT64_C(15382914908836993561) } },
        { "PhoneLocale", { Event::MetricType::kRawString, UINT64_C(6698835397966629082) } },
        { "PhonePseudonymousId", { Event::MetricType::kRawString, UINT64_C(2429174681495363783) } },
        { "PhoneInfoLastUpdatedTimestamp", { Event::MetricType::kLong, UINT64_C(8951112839187436979) } } };

    metrics_name_map_ = { { UINT64_C(4297293875635157131), "SessionId" }, { UINT64_C(11805586358985797642), "Timestamp" },
        { UINT64_C(13131851803141078605), "ConnectionMedium" }, { UINT64_C(15110970193774360897), "ChromebookBluetoothStack" },
        { UINT64_C(5557047930145251011), "DevicesNetworkState" }, { UINT64_C(17301340632531771882), "ChromebookLocale" },
        { UINT64_C(15157035504208410273), "ChromebookPseudonymousId" }, { UINT64_C(13371302375274686383), "PhoneManufacturer" },
        { UINT64_C(14454608432121246609), "PhoneModel" }, { UINT64_C(17812242366157473801), "PhoneAndroidVersion" },
        { UINT64_C(12805024565569487205), "PhoneAmbientApkVersion" }, { UINT64_C(6418828325351853188), "PhoneGmsCoreVersion" },
        { UINT64_C(10168993227198787982), "PhoneProfile" }, { UINT64_C(15382914908836993561), "PhoneNetworkStatus" },
        { UINT64_C(6698835397966629082), "PhoneLocale" }, { UINT64_C(2429174681495363783), "PhonePseudonymousId" },
        { UINT64_C(8951112839187436979), "PhoneInfoLastUpdatedTimestamp" } };
}

class PhoneHub_DiscoveryStartedEventValidator final : public ::metrics::structured::EventValidator {
public:
    PhoneHub_DiscoveryStartedEventValidator();
    ~PhoneHub_DiscoveryStartedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(7992577258084539318);
};

PhoneHub_DiscoveryStartedEventValidator::PhoneHub_DiscoveryStartedEventValidator()
    : ::metrics::structured::EventValidator(PhoneHub_DiscoveryStartedEventValidator::kEventNameHash, false)
{
    Initialize();
}

PhoneHub_DiscoveryStartedEventValidator::~PhoneHub_DiscoveryStartedEventValidator() = default;

void PhoneHub_DiscoveryStartedEventValidator::Initialize()
{
    metric_metadata_ = { { "SessionId", { Event::MetricType::kRawString, UINT64_C(4297293875635157131) } },
        { "Timestamp", { Event::MetricType::kLong, UINT64_C(11805586358985797642) } },
        { "DiscoveryEntrypoint", { Event::MetricType::kLong, UINT64_C(17359941946827438118) } } };

    metrics_name_map_ = { { UINT64_C(4297293875635157131), "SessionId" }, { UINT64_C(11805586358985797642), "Timestamp" },
        { UINT64_C(17359941946827438118), "DiscoveryEntrypoint" } };
}

class PhoneHub_DiscoveryFinishedEventValidator final : public ::metrics::structured::EventValidator {
public:
    PhoneHub_DiscoveryFinishedEventValidator();
    ~PhoneHub_DiscoveryFinishedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(16302049427530543562);
};

PhoneHub_DiscoveryFinishedEventValidator::PhoneHub_DiscoveryFinishedEventValidator()
    : ::metrics::structured::EventValidator(PhoneHub_DiscoveryFinishedEventValidator::kEventNameHash, false)
{
    Initialize();
}

PhoneHub_DiscoveryFinishedEventValidator::~PhoneHub_DiscoveryFinishedEventValidator() = default;

void PhoneHub_DiscoveryFinishedEventValidator::Initialize()
{
    metric_metadata_ = { { "SessionId", { Event::MetricType::kRawString, UINT64_C(4297293875635157131) } },
        { "Timestamp", { Event::MetricType::kLong, UINT64_C(11805586358985797642) } },
        { "DiscoeryResult", { Event::MetricType::kLong, UINT64_C(2625041250615430412) } },
        { "DiscoveryResultErrorCode", { Event::MetricType::kLong, UINT64_C(12961209316465789227) } } };

    metrics_name_map_ = { { UINT64_C(4297293875635157131), "SessionId" }, { UINT64_C(11805586358985797642), "Timestamp" },
        { UINT64_C(2625041250615430412), "DiscoeryResult" }, { UINT64_C(12961209316465789227), "DiscoveryResultErrorCode" } };
}

class PhoneHub_NearbyConnectionEventValidator final : public ::metrics::structured::EventValidator {
public:
    PhoneHub_NearbyConnectionEventValidator();
    ~PhoneHub_NearbyConnectionEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(13864616483619165279);
};

PhoneHub_NearbyConnectionEventValidator::PhoneHub_NearbyConnectionEventValidator()
    : ::metrics::structured::EventValidator(PhoneHub_NearbyConnectionEventValidator::kEventNameHash, false)
{
    Initialize();
}

PhoneHub_NearbyConnectionEventValidator::~PhoneHub_NearbyConnectionEventValidator() = default;

void PhoneHub_NearbyConnectionEventValidator::Initialize()
{
    metric_metadata_ = { { "SessionId", { Event::MetricType::kRawString, UINT64_C(4297293875635157131) } },
        { "Timestamp", { Event::MetricType::kLong, UINT64_C(11805586358985797642) } },
        { "NearbyConnectionStep", { Event::MetricType::kLong, UINT64_C(6257331507597854855) } },
        { "NearbyConnectionStepResult", { Event::MetricType::kLong, UINT64_C(9838672903631926231) } } };

    metrics_name_map_ = { { UINT64_C(4297293875635157131), "SessionId" }, { UINT64_C(11805586358985797642), "Timestamp" },
        { UINT64_C(6257331507597854855), "NearbyConnectionStep" }, { UINT64_C(9838672903631926231), "NearbyConnectionStepResult" } };
}

class PhoneHub_SecureChannelAuthenticationEventValidator final : public ::metrics::structured::EventValidator {
public:
    PhoneHub_SecureChannelAuthenticationEventValidator();
    ~PhoneHub_SecureChannelAuthenticationEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(7469924009091573938);
};

PhoneHub_SecureChannelAuthenticationEventValidator::PhoneHub_SecureChannelAuthenticationEventValidator()
    : ::metrics::structured::EventValidator(PhoneHub_SecureChannelAuthenticationEventValidator::kEventNameHash, false)
{
    Initialize();
}

PhoneHub_SecureChannelAuthenticationEventValidator::~PhoneHub_SecureChannelAuthenticationEventValidator() = default;

void PhoneHub_SecureChannelAuthenticationEventValidator::Initialize()
{
    metric_metadata_ = { { "SessionId", { Event::MetricType::kRawString, UINT64_C(4297293875635157131) } },
        { "Timestamp", { Event::MetricType::kLong, UINT64_C(11805586358985797642) } },
        { "SecureChannelAuthenticationState", { Event::MetricType::kLong, UINT64_C(14407245615475564531) } } };

    metrics_name_map_ = { { UINT64_C(4297293875635157131), "SessionId" }, { UINT64_C(11805586358985797642), "Timestamp" },
        { UINT64_C(14407245615475564531), "SecureChannelAuthenticationState" } };
}

class PhoneHub_PhoneHubMessageEventValidator final : public ::metrics::structured::EventValidator {
public:
    PhoneHub_PhoneHubMessageEventValidator();
    ~PhoneHub_PhoneHubMessageEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(10478645582908403406);
};

PhoneHub_PhoneHubMessageEventValidator::PhoneHub_PhoneHubMessageEventValidator()
    : ::metrics::structured::EventValidator(PhoneHub_PhoneHubMessageEventValidator::kEventNameHash, false)
{
    Initialize();
}

PhoneHub_PhoneHubMessageEventValidator::~PhoneHub_PhoneHubMessageEventValidator() = default;

void PhoneHub_PhoneHubMessageEventValidator::Initialize()
{
    metric_metadata_ = { { "SessionId", { Event::MetricType::kRawString, UINT64_C(4297293875635157131) } },
        { "Timestamp", { Event::MetricType::kLong, UINT64_C(11805586358985797642) } },
        { "PhoneHubMessageType", { Event::MetricType::kLong, UINT64_C(1917552159321581499) } },
        { "PhoneHubMessageDirection", { Event::MetricType::kLong, UINT64_C(7945222392456051322) } } };

    metrics_name_map_ = { { UINT64_C(4297293875635157131), "SessionId" }, { UINT64_C(11805586358985797642), "Timestamp" },
        { UINT64_C(1917552159321581499), "PhoneHubMessageType" }, { UINT64_C(7945222392456051322), "PhoneHubMessageDirection" } };
}

class PhoneHub_PhoneHubUiUpdateEventValidator final : public ::metrics::structured::EventValidator {
public:
    PhoneHub_PhoneHubUiUpdateEventValidator();
    ~PhoneHub_PhoneHubUiUpdateEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(17145414062248710895);
};

PhoneHub_PhoneHubUiUpdateEventValidator::PhoneHub_PhoneHubUiUpdateEventValidator()
    : ::metrics::structured::EventValidator(PhoneHub_PhoneHubUiUpdateEventValidator::kEventNameHash, false)
{
    Initialize();
}

PhoneHub_PhoneHubUiUpdateEventValidator::~PhoneHub_PhoneHubUiUpdateEventValidator() = default;

void PhoneHub_PhoneHubUiUpdateEventValidator::Initialize()
{
    metric_metadata_ = { { "SessionId", { Event::MetricType::kRawString, UINT64_C(4297293875635157131) } },
        { "Timestamp", { Event::MetricType::kLong, UINT64_C(11805586358985797642) } },
        { "PhoneHubUiState", { Event::MetricType::kLong, UINT64_C(1379831192396083094) } } };

    metrics_name_map_ = { { UINT64_C(4297293875635157131), "SessionId" }, { UINT64_C(11805586358985797642), "Timestamp" },
        { UINT64_C(1379831192396083094), "PhoneHubUiState" } };
}
class StructuredMetrics_InitializationEventValidator final : public ::metrics::structured::EventValidator {
public:
    StructuredMetrics_InitializationEventValidator();
    ~StructuredMetrics_InitializationEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(17627823560409533063);
};

StructuredMetrics_InitializationEventValidator::StructuredMetrics_InitializationEventValidator()
    : ::metrics::structured::EventValidator(StructuredMetrics_InitializationEventValidator::kEventNameHash, false)
{
    Initialize();
}

StructuredMetrics_InitializationEventValidator::~StructuredMetrics_InitializationEventValidator() = default;

void StructuredMetrics_InitializationEventValidator::Initialize()
{
    metric_metadata_ = { { "Platform", { Event::MetricType::kLong, UINT64_C(4728558894243024398) } } };

    metrics_name_map_ = { { UINT64_C(4728558894243024398), "Platform" } };
}
class CrOSEvents_AppDiscovery_AppInstalledEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_AppDiscovery_AppInstalledEventValidator();
    ~CrOSEvents_AppDiscovery_AppInstalledEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(7058343684005446180);
};

CrOSEvents_AppDiscovery_AppInstalledEventValidator::CrOSEvents_AppDiscovery_AppInstalledEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_AppDiscovery_AppInstalledEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_AppDiscovery_AppInstalledEventValidator::~CrOSEvents_AppDiscovery_AppInstalledEventValidator() = default;

void CrOSEvents_AppDiscovery_AppInstalledEventValidator::Initialize()
{
    metric_metadata_ = { { "AppId", { Event::MetricType::kRawString, UINT64_C(3436411431909560556) } },
        { "AppType", { Event::MetricType::kLong, UINT64_C(8663828604683851647) } },
        { "InstallSource", { Event::MetricType::kLong, UINT64_C(7897354207534621578) } },
        { "InstallReason", { Event::MetricType::kLong, UINT64_C(1281400133578045381) } } };

    metrics_name_map_ = { { UINT64_C(3436411431909560556), "AppId" }, { UINT64_C(8663828604683851647), "AppType" },
        { UINT64_C(7897354207534621578), "InstallSource" }, { UINT64_C(1281400133578045381), "InstallReason" } };
}

class CrOSEvents_AppDiscovery_AppInstallService_InstallRequestedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_AppDiscovery_AppInstallService_InstallRequestedEventValidator();
    ~CrOSEvents_AppDiscovery_AppInstallService_InstallRequestedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(9189515227642480669);
};

CrOSEvents_AppDiscovery_AppInstallService_InstallRequestedEventValidator::CrOSEvents_AppDiscovery_AppInstallService_InstallRequestedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_AppDiscovery_AppInstallService_InstallRequestedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_AppDiscovery_AppInstallService_InstallRequestedEventValidator::~CrOSEvents_AppDiscovery_AppInstallService_InstallRequestedEventValidator() = default;

void CrOSEvents_AppDiscovery_AppInstallService_InstallRequestedEventValidator::Initialize()
{
    metric_metadata_ = { { "AppId", { Event::MetricType::kRawString, UINT64_C(3436411431909560556) } },
        { "Surface", { Event::MetricType::kInt, UINT64_C(12253540920802058568) } } };

    metrics_name_map_ = { { UINT64_C(3436411431909560556), "AppId" }, { UINT64_C(12253540920802058568), "Surface" } };
}

class CrOSEvents_AppDiscovery_AppLaunchedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_AppDiscovery_AppLaunchedEventValidator();
    ~CrOSEvents_AppDiscovery_AppLaunchedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(10707673304400816961);
};

CrOSEvents_AppDiscovery_AppLaunchedEventValidator::CrOSEvents_AppDiscovery_AppLaunchedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_AppDiscovery_AppLaunchedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_AppDiscovery_AppLaunchedEventValidator::~CrOSEvents_AppDiscovery_AppLaunchedEventValidator() = default;

void CrOSEvents_AppDiscovery_AppLaunchedEventValidator::Initialize()
{
    metric_metadata_ = { { "AppId", { Event::MetricType::kRawString, UINT64_C(3436411431909560556) } },
        { "AppType", { Event::MetricType::kLong, UINT64_C(8663828604683851647) } },
        { "LaunchSource", { Event::MetricType::kLong, UINT64_C(5360095524695749322) } } };

    metrics_name_map_
        = { { UINT64_C(3436411431909560556), "AppId" }, { UINT64_C(8663828604683851647), "AppType" }, { UINT64_C(5360095524695749322), "LaunchSource" } };
}

class CrOSEvents_AppDiscovery_AppUninstallEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_AppDiscovery_AppUninstallEventValidator();
    ~CrOSEvents_AppDiscovery_AppUninstallEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(2738328505235822343);
};

CrOSEvents_AppDiscovery_AppUninstallEventValidator::CrOSEvents_AppDiscovery_AppUninstallEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_AppDiscovery_AppUninstallEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_AppDiscovery_AppUninstallEventValidator::~CrOSEvents_AppDiscovery_AppUninstallEventValidator() = default;

void CrOSEvents_AppDiscovery_AppUninstallEventValidator::Initialize()
{
    metric_metadata_ = { { "AppId", { Event::MetricType::kRawString, UINT64_C(3436411431909560556) } },
        { "AppType", { Event::MetricType::kLong, UINT64_C(8663828604683851647) } },
        { "UninstallSource", { Event::MetricType::kLong, UINT64_C(8215808397380782455) } } };

    metrics_name_map_
        = { { UINT64_C(3436411431909560556), "AppId" }, { UINT64_C(8663828604683851647), "AppType" }, { UINT64_C(8215808397380782455), "UninstallSource" } };
}

class CrOSEvents_AppDiscovery_AppStateChangedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_AppDiscovery_AppStateChangedEventValidator();
    ~CrOSEvents_AppDiscovery_AppStateChangedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(9243762327526693209);
};

CrOSEvents_AppDiscovery_AppStateChangedEventValidator::CrOSEvents_AppDiscovery_AppStateChangedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_AppDiscovery_AppStateChangedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_AppDiscovery_AppStateChangedEventValidator::~CrOSEvents_AppDiscovery_AppStateChangedEventValidator() = default;

void CrOSEvents_AppDiscovery_AppStateChangedEventValidator::Initialize()
{
    metric_metadata_ = { { "AppId", { Event::MetricType::kRawString, UINT64_C(3436411431909560556) } },
        { "AppState", { Event::MetricType::kLong, UINT64_C(7939215552227078667) } } };

    metrics_name_map_ = { { UINT64_C(3436411431909560556), "AppId" }, { UINT64_C(7939215552227078667), "AppState" } };
}

class CrOSEvents_AppDiscovery_ArcAppCameraAccessedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_AppDiscovery_ArcAppCameraAccessedEventValidator();
    ~CrOSEvents_AppDiscovery_ArcAppCameraAccessedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(8471047485040088054);
};

CrOSEvents_AppDiscovery_ArcAppCameraAccessedEventValidator::CrOSEvents_AppDiscovery_ArcAppCameraAccessedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_AppDiscovery_ArcAppCameraAccessedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_AppDiscovery_ArcAppCameraAccessedEventValidator::~CrOSEvents_AppDiscovery_ArcAppCameraAccessedEventValidator() = default;

void CrOSEvents_AppDiscovery_ArcAppCameraAccessedEventValidator::Initialize()
{
    metric_metadata_ = { { "AppId", { Event::MetricType::kRawString, UINT64_C(3436411431909560556) } } };

    metrics_name_map_ = { { UINT64_C(3436411431909560556), "AppId" } };
}

class CrOSEvents_AppDiscovery_LauncherOpenEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_AppDiscovery_LauncherOpenEventValidator();
    ~CrOSEvents_AppDiscovery_LauncherOpenEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(14878222005301987403);
};

CrOSEvents_AppDiscovery_LauncherOpenEventValidator::CrOSEvents_AppDiscovery_LauncherOpenEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_AppDiscovery_LauncherOpenEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_AppDiscovery_LauncherOpenEventValidator::~CrOSEvents_AppDiscovery_LauncherOpenEventValidator() = default;

void CrOSEvents_AppDiscovery_LauncherOpenEventValidator::Initialize()
{
    metric_metadata_ = {

    };

    metrics_name_map_ = {

    };
}

class CrOSEvents_AppDiscovery_AppLauncherResultOpenedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_AppDiscovery_AppLauncherResultOpenedEventValidator();
    ~CrOSEvents_AppDiscovery_AppLauncherResultOpenedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(8029308694385404808);
};

CrOSEvents_AppDiscovery_AppLauncherResultOpenedEventValidator::CrOSEvents_AppDiscovery_AppLauncherResultOpenedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_AppDiscovery_AppLauncherResultOpenedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_AppDiscovery_AppLauncherResultOpenedEventValidator::~CrOSEvents_AppDiscovery_AppLauncherResultOpenedEventValidator() = default;

void CrOSEvents_AppDiscovery_AppLauncherResultOpenedEventValidator::Initialize()
{
    metric_metadata_ = { { "FuzzyStringMatch", { Event::MetricType::kDouble, UINT64_C(14159803595132072453) } },
        { "AppId", { Event::MetricType::kRawString, UINT64_C(3436411431909560556) } },
        { "AppName", { Event::MetricType::kRawString, UINT64_C(12020578951758927002) } },
        { "ResultCategory", { Event::MetricType::kLong, UINT64_C(1461456690361619671) } } };

    metrics_name_map_ = { { UINT64_C(14159803595132072453), "FuzzyStringMatch" }, { UINT64_C(3436411431909560556), "AppId" },
        { UINT64_C(12020578951758927002), "AppName" }, { UINT64_C(1461456690361619671), "ResultCategory" } };
}

class CrOSEvents_AppDiscovery_Browser_OmniboxInstallIconClickedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_AppDiscovery_Browser_OmniboxInstallIconClickedEventValidator();
    ~CrOSEvents_AppDiscovery_Browser_OmniboxInstallIconClickedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(3850425801585793723);
};

CrOSEvents_AppDiscovery_Browser_OmniboxInstallIconClickedEventValidator::CrOSEvents_AppDiscovery_Browser_OmniboxInstallIconClickedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_AppDiscovery_Browser_OmniboxInstallIconClickedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_AppDiscovery_Browser_OmniboxInstallIconClickedEventValidator::~CrOSEvents_AppDiscovery_Browser_OmniboxInstallIconClickedEventValidator() = default;

void CrOSEvents_AppDiscovery_Browser_OmniboxInstallIconClickedEventValidator::Initialize()
{
    metric_metadata_ = { { "IPHShown", { Event::MetricType::kLong, UINT64_C(7048166618781235113) } } };

    metrics_name_map_ = { { UINT64_C(7048166618781235113), "IPHShown" } };
}

class CrOSEvents_AppDiscovery_Browser_AppInstallDialogShownEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_AppDiscovery_Browser_AppInstallDialogShownEventValidator();
    ~CrOSEvents_AppDiscovery_Browser_AppInstallDialogShownEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(12637046804977021887);
};

CrOSEvents_AppDiscovery_Browser_AppInstallDialogShownEventValidator::CrOSEvents_AppDiscovery_Browser_AppInstallDialogShownEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_AppDiscovery_Browser_AppInstallDialogShownEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_AppDiscovery_Browser_AppInstallDialogShownEventValidator::~CrOSEvents_AppDiscovery_Browser_AppInstallDialogShownEventValidator() = default;

void CrOSEvents_AppDiscovery_Browser_AppInstallDialogShownEventValidator::Initialize()
{
    metric_metadata_ = { { "AppId", { Event::MetricType::kRawString, UINT64_C(3436411431909560556) } } };

    metrics_name_map_ = { { UINT64_C(3436411431909560556), "AppId" } };
}

class CrOSEvents_AppDiscovery_Browser_AppInstallDialogResultEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_AppDiscovery_Browser_AppInstallDialogResultEventValidator();
    ~CrOSEvents_AppDiscovery_Browser_AppInstallDialogResultEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(13700312836166654669);
};

CrOSEvents_AppDiscovery_Browser_AppInstallDialogResultEventValidator::CrOSEvents_AppDiscovery_Browser_AppInstallDialogResultEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_AppDiscovery_Browser_AppInstallDialogResultEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_AppDiscovery_Browser_AppInstallDialogResultEventValidator::~CrOSEvents_AppDiscovery_Browser_AppInstallDialogResultEventValidator() = default;

void CrOSEvents_AppDiscovery_Browser_AppInstallDialogResultEventValidator::Initialize()
{
    metric_metadata_ = { { "WebAppInstallStatus", { Event::MetricType::kLong, UINT64_C(17331805925352160966) } },
        { "AppId", { Event::MetricType::kRawString, UINT64_C(3436411431909560556) } } };

    metrics_name_map_ = { { UINT64_C(17331805925352160966), "WebAppInstallStatus" }, { UINT64_C(3436411431909560556), "AppId" } };
}

class CrOSEvents_AppDiscovery_Browser_ClickInstallAppFromMenuEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_AppDiscovery_Browser_ClickInstallAppFromMenuEventValidator();
    ~CrOSEvents_AppDiscovery_Browser_ClickInstallAppFromMenuEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(9038997657104637664);
};

CrOSEvents_AppDiscovery_Browser_ClickInstallAppFromMenuEventValidator::CrOSEvents_AppDiscovery_Browser_ClickInstallAppFromMenuEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_AppDiscovery_Browser_ClickInstallAppFromMenuEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_AppDiscovery_Browser_ClickInstallAppFromMenuEventValidator::~CrOSEvents_AppDiscovery_Browser_ClickInstallAppFromMenuEventValidator() = default;

void CrOSEvents_AppDiscovery_Browser_ClickInstallAppFromMenuEventValidator::Initialize()
{
    metric_metadata_ = { { "AppId", { Event::MetricType::kRawString, UINT64_C(3436411431909560556) } } };

    metrics_name_map_ = { { UINT64_C(3436411431909560556), "AppId" } };
}

class CrOSEvents_AppDiscovery_Browser_CreateShortcutEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_AppDiscovery_Browser_CreateShortcutEventValidator();
    ~CrOSEvents_AppDiscovery_Browser_CreateShortcutEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(1826365659052634425);
};

CrOSEvents_AppDiscovery_Browser_CreateShortcutEventValidator::CrOSEvents_AppDiscovery_Browser_CreateShortcutEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_AppDiscovery_Browser_CreateShortcutEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_AppDiscovery_Browser_CreateShortcutEventValidator::~CrOSEvents_AppDiscovery_Browser_CreateShortcutEventValidator() = default;

void CrOSEvents_AppDiscovery_Browser_CreateShortcutEventValidator::Initialize()
{
    metric_metadata_ = { { "AppId", { Event::MetricType::kRawString, UINT64_C(3436411431909560556) } } };

    metrics_name_map_ = { { UINT64_C(3436411431909560556), "AppId" } };
}

class CrOSEvents_CameraApp_StartSessionEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_CameraApp_StartSessionEventValidator();
    ~CrOSEvents_CameraApp_StartSessionEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(12442349267185093909);
};

CrOSEvents_CameraApp_StartSessionEventValidator::CrOSEvents_CameraApp_StartSessionEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_CameraApp_StartSessionEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_CameraApp_StartSessionEventValidator::~CrOSEvents_CameraApp_StartSessionEventValidator() = default;

void CrOSEvents_CameraApp_StartSessionEventValidator::Initialize()
{
    metric_metadata_ = { { "LaunchType", { Event::MetricType::kInt, UINT64_C(11712806806050724828) } },
        { "Language", { Event::MetricType::kLong, UINT64_C(5302048478445481009) } } };

    metrics_name_map_ = { { UINT64_C(11712806806050724828), "LaunchType" }, { UINT64_C(5302048478445481009), "Language" } };
}

class CrOSEvents_CameraApp_CaptureEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_CameraApp_CaptureEventValidator();
    ~CrOSEvents_CameraApp_CaptureEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(3120751945078508193);
};

CrOSEvents_CameraApp_CaptureEventValidator::CrOSEvents_CameraApp_CaptureEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_CameraApp_CaptureEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_CameraApp_CaptureEventValidator::~CrOSEvents_CameraApp_CaptureEventValidator() = default;

void CrOSEvents_CameraApp_CaptureEventValidator::Initialize()
{
    metric_metadata_ = { { "Mode", { Event::MetricType::kInt, UINT64_C(7281166215790160128) } },
        { "Facing", { Event::MetricType::kInt, UINT64_C(12017311213637341809) } },
        { "IsMirrored", { Event::MetricType::kLong, UINT64_C(8806235660365203951) } },
        { "GridType", { Event::MetricType::kInt, UINT64_C(17360880062035905322) } },
        { "TimerType", { Event::MetricType::kInt, UINT64_C(13792450029747923064) } },
        { "ShutterType", { Event::MetricType::kInt, UINT64_C(7628310117392551471) } },
        { "AndroidIntentResultType", { Event::MetricType::kInt, UINT64_C(7195461414176739445) } },
        { "IsWindowMaximized", { Event::MetricType::kLong, UINT64_C(15812246738115104128) } },
        { "IsWindowPortrait", { Event::MetricType::kLong, UINT64_C(18016234378620372904) } },
        { "ResolutionWidth", { Event::MetricType::kLong, UINT64_C(8618647903498522462) } },
        { "ResolutionHeight", { Event::MetricType::kLong, UINT64_C(10882813561946656813) } },
        { "ResolutionLevel", { Event::MetricType::kInt, UINT64_C(448241819433007071) } },
        { "AspectRatioSet", { Event::MetricType::kInt, UINT64_C(17362845054209563998) } },
        { "IsVideoSnapshot", { Event::MetricType::kLong, UINT64_C(11328348040425994864) } },
        { "IsMuted", { Event::MetricType::kLong, UINT64_C(16310095796065347619) } }, { "Fps", { Event::MetricType::kLong, UINT64_C(1975478281771230569) } },
        { "EverPaused", { Event::MetricType::kLong, UINT64_C(1166810848989755013) } },
        { "Duration", { Event::MetricType::kLong, UINT64_C(16153614581047612563) } },
        { "RecordType", { Event::MetricType::kInt, UINT64_C(2556852903161176255) } },
        { "GifResultType", { Event::MetricType::kInt, UINT64_C(4369868611535915600) } },
        { "TimelapseSpeed", { Event::MetricType::kLong, UINT64_C(17390575290622626020) } },
        { "ZoomRatio", { Event::MetricType::kDouble, UINT64_C(17282258216284759255) } } };

    metrics_name_map_ = { { UINT64_C(7281166215790160128), "Mode" }, { UINT64_C(12017311213637341809), "Facing" },
        { UINT64_C(8806235660365203951), "IsMirrored" }, { UINT64_C(17360880062035905322), "GridType" }, { UINT64_C(13792450029747923064), "TimerType" },
        { UINT64_C(7628310117392551471), "ShutterType" }, { UINT64_C(7195461414176739445), "AndroidIntentResultType" },
        { UINT64_C(15812246738115104128), "IsWindowMaximized" }, { UINT64_C(18016234378620372904), "IsWindowPortrait" },
        { UINT64_C(8618647903498522462), "ResolutionWidth" }, { UINT64_C(10882813561946656813), "ResolutionHeight" },
        { UINT64_C(448241819433007071), "ResolutionLevel" }, { UINT64_C(17362845054209563998), "AspectRatioSet" },
        { UINT64_C(11328348040425994864), "IsVideoSnapshot" }, { UINT64_C(16310095796065347619), "IsMuted" }, { UINT64_C(1975478281771230569), "Fps" },
        { UINT64_C(1166810848989755013), "EverPaused" }, { UINT64_C(16153614581047612563), "Duration" }, { UINT64_C(2556852903161176255), "RecordType" },
        { UINT64_C(4369868611535915600), "GifResultType" }, { UINT64_C(17390575290622626020), "TimelapseSpeed" },
        { UINT64_C(17282258216284759255), "ZoomRatio" } };
}

class CrOSEvents_CameraApp_AndroidIntentEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_CameraApp_AndroidIntentEventValidator();
    ~CrOSEvents_CameraApp_AndroidIntentEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(7329192243316244541);
};

CrOSEvents_CameraApp_AndroidIntentEventValidator::CrOSEvents_CameraApp_AndroidIntentEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_CameraApp_AndroidIntentEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_CameraApp_AndroidIntentEventValidator::~CrOSEvents_CameraApp_AndroidIntentEventValidator() = default;

void CrOSEvents_CameraApp_AndroidIntentEventValidator::Initialize()
{
    metric_metadata_ = { { "Mode", { Event::MetricType::kInt, UINT64_C(7281166215790160128) } },
        { "ShouldHandleResult", { Event::MetricType::kLong, UINT64_C(6587406469413955246) } },
        { "ShouldDownscale", { Event::MetricType::kLong, UINT64_C(2801729415672548365) } },
        { "IsSecure", { Event::MetricType::kLong, UINT64_C(14591288558073196738) } } };

    metrics_name_map_ = { { UINT64_C(7281166215790160128), "Mode" }, { UINT64_C(6587406469413955246), "ShouldHandleResult" },
        { UINT64_C(2801729415672548365), "ShouldDownscale" }, { UINT64_C(14591288558073196738), "IsSecure" } };
}

class CrOSEvents_CameraApp_OpenPTZPanelEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_CameraApp_OpenPTZPanelEventValidator();
    ~CrOSEvents_CameraApp_OpenPTZPanelEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(10219338529199028724);
};

CrOSEvents_CameraApp_OpenPTZPanelEventValidator::CrOSEvents_CameraApp_OpenPTZPanelEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_CameraApp_OpenPTZPanelEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_CameraApp_OpenPTZPanelEventValidator::~CrOSEvents_CameraApp_OpenPTZPanelEventValidator() = default;

void CrOSEvents_CameraApp_OpenPTZPanelEventValidator::Initialize()
{
    metric_metadata_ = { { "SupportPan", { Event::MetricType::kLong, UINT64_C(15602960518385121293) } },
        { "SupportTilt", { Event::MetricType::kLong, UINT64_C(14998415272116405712) } },
        { "SupportZoom", { Event::MetricType::kLong, UINT64_C(18133441798314859318) } } };

    metrics_name_map_ = { { UINT64_C(15602960518385121293), "SupportPan" }, { UINT64_C(14998415272116405712), "SupportTilt" },
        { UINT64_C(18133441798314859318), "SupportZoom" } };
}

class CrOSEvents_CameraApp_DocScanActionEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_CameraApp_DocScanActionEventValidator();
    ~CrOSEvents_CameraApp_DocScanActionEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(16175792557571171867);
};

CrOSEvents_CameraApp_DocScanActionEventValidator::CrOSEvents_CameraApp_DocScanActionEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_CameraApp_DocScanActionEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_CameraApp_DocScanActionEventValidator::~CrOSEvents_CameraApp_DocScanActionEventValidator() = default;

void CrOSEvents_CameraApp_DocScanActionEventValidator::Initialize()
{
    metric_metadata_ = { { "ActionType", { Event::MetricType::kInt, UINT64_C(14009839378079256537) } } };

    metrics_name_map_ = { { UINT64_C(14009839378079256537), "ActionType" } };
}

class CrOSEvents_CameraApp_DocScanResultEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_CameraApp_DocScanResultEventValidator();
    ~CrOSEvents_CameraApp_DocScanResultEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(11722103785276254025);
};

CrOSEvents_CameraApp_DocScanResultEventValidator::CrOSEvents_CameraApp_DocScanResultEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_CameraApp_DocScanResultEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_CameraApp_DocScanResultEventValidator::~CrOSEvents_CameraApp_DocScanResultEventValidator() = default;

void CrOSEvents_CameraApp_DocScanResultEventValidator::Initialize()
{
    metric_metadata_ = { { "ResultType", { Event::MetricType::kInt, UINT64_C(8293845286137751377) } },
        { "FixTypes", { Event::MetricType::kLong, UINT64_C(17638491211271930443) } },
        { "FixCount", { Event::MetricType::kLong, UINT64_C(3576764359326890144) } },
        { "PageCount", { Event::MetricType::kLong, UINT64_C(7212889574957062281) } } };

    metrics_name_map_ = { { UINT64_C(8293845286137751377), "ResultType" }, { UINT64_C(17638491211271930443), "FixTypes" },
        { UINT64_C(3576764359326890144), "FixCount" }, { UINT64_C(7212889574957062281), "PageCount" } };
}

class CrOSEvents_CameraApp_OpenCameraEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_CameraApp_OpenCameraEventValidator();
    ~CrOSEvents_CameraApp_OpenCameraEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(1579272689456091859);
};

CrOSEvents_CameraApp_OpenCameraEventValidator::CrOSEvents_CameraApp_OpenCameraEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_CameraApp_OpenCameraEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_CameraApp_OpenCameraEventValidator::~CrOSEvents_CameraApp_OpenCameraEventValidator() = default;

void CrOSEvents_CameraApp_OpenCameraEventValidator::Initialize()
{
    metric_metadata_ = { { "CameraModuleId", { Event::MetricType::kRawString, UINT64_C(15314096248640439099) } } };

    metrics_name_map_ = { { UINT64_C(15314096248640439099), "CameraModuleId" } };
}

class CrOSEvents_CameraApp_LowStorageActionEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_CameraApp_LowStorageActionEventValidator();
    ~CrOSEvents_CameraApp_LowStorageActionEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(356388052753455524);
};

CrOSEvents_CameraApp_LowStorageActionEventValidator::CrOSEvents_CameraApp_LowStorageActionEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_CameraApp_LowStorageActionEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_CameraApp_LowStorageActionEventValidator::~CrOSEvents_CameraApp_LowStorageActionEventValidator() = default;

void CrOSEvents_CameraApp_LowStorageActionEventValidator::Initialize()
{
    metric_metadata_ = { { "ActionType", { Event::MetricType::kInt, UINT64_C(14009839378079256537) } } };

    metrics_name_map_ = { { UINT64_C(14009839378079256537), "ActionType" } };
}

class CrOSEvents_CameraApp_BarcodeDetectedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_CameraApp_BarcodeDetectedEventValidator();
    ~CrOSEvents_CameraApp_BarcodeDetectedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(16213301286884956999);
};

CrOSEvents_CameraApp_BarcodeDetectedEventValidator::CrOSEvents_CameraApp_BarcodeDetectedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_CameraApp_BarcodeDetectedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_CameraApp_BarcodeDetectedEventValidator::~CrOSEvents_CameraApp_BarcodeDetectedEventValidator() = default;

void CrOSEvents_CameraApp_BarcodeDetectedEventValidator::Initialize()
{
    metric_metadata_ = { { "ContentType", { Event::MetricType::kInt, UINT64_C(13265227184175150385) } },
        { "WifiSecurityType", { Event::MetricType::kInt, UINT64_C(8289078073336165797) } } };

    metrics_name_map_ = { { UINT64_C(13265227184175150385), "ContentType" }, { UINT64_C(8289078073336165797), "WifiSecurityType" } };
}

class CrOSEvents_CameraApp_PerfEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_CameraApp_PerfEventValidator();
    ~CrOSEvents_CameraApp_PerfEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(8599673815546087386);
};

CrOSEvents_CameraApp_PerfEventValidator::CrOSEvents_CameraApp_PerfEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_CameraApp_PerfEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_CameraApp_PerfEventValidator::~CrOSEvents_CameraApp_PerfEventValidator() = default;

void CrOSEvents_CameraApp_PerfEventValidator::Initialize()
{
    metric_metadata_ = { { "EventType", { Event::MetricType::kInt, UINT64_C(5446425777535537951) } },
        { "Duration", { Event::MetricType::kLong, UINT64_C(16153614581047612563) } }, { "Facing", { Event::MetricType::kInt, UINT64_C(12017311213637341809) } },
        { "ResolutionWidth", { Event::MetricType::kLong, UINT64_C(8618647903498522462) } },
        { "ResolutionHeight", { Event::MetricType::kLong, UINT64_C(10882813561946656813) } },
        { "PageCount", { Event::MetricType::kLong, UINT64_C(7212889574957062281) } },
        { "Pressure", { Event::MetricType::kInt, UINT64_C(12071187160118041417) } } };

    metrics_name_map_
        = { { UINT64_C(5446425777535537951), "EventType" }, { UINT64_C(16153614581047612563), "Duration" }, { UINT64_C(12017311213637341809), "Facing" },
              { UINT64_C(8618647903498522462), "ResolutionWidth" }, { UINT64_C(10882813561946656813), "ResolutionHeight" },
              { UINT64_C(7212889574957062281), "PageCount" }, { UINT64_C(12071187160118041417), "Pressure" } };
}

class CrOSEvents_CameraApp_UnsupportedProtocolEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_CameraApp_UnsupportedProtocolEventValidator();
    ~CrOSEvents_CameraApp_UnsupportedProtocolEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(3222573963151036809);
};

CrOSEvents_CameraApp_UnsupportedProtocolEventValidator::CrOSEvents_CameraApp_UnsupportedProtocolEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_CameraApp_UnsupportedProtocolEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_CameraApp_UnsupportedProtocolEventValidator::~CrOSEvents_CameraApp_UnsupportedProtocolEventValidator() = default;

void CrOSEvents_CameraApp_UnsupportedProtocolEventValidator::Initialize()
{
    metric_metadata_ = {

    };

    metrics_name_map_ = {

    };
}

class CrOSEvents_CameraApp_EndSessionEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_CameraApp_EndSessionEventValidator();
    ~CrOSEvents_CameraApp_EndSessionEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(3626223696860803178);
};

CrOSEvents_CameraApp_EndSessionEventValidator::CrOSEvents_CameraApp_EndSessionEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_CameraApp_EndSessionEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_CameraApp_EndSessionEventValidator::~CrOSEvents_CameraApp_EndSessionEventValidator() = default;

void CrOSEvents_CameraApp_EndSessionEventValidator::Initialize()
{
    metric_metadata_ = { { "Duration", { Event::MetricType::kLong, UINT64_C(16153614581047612563) } } };

    metrics_name_map_ = { { UINT64_C(16153614581047612563), "Duration" } };
}

class CrOSEvents_CameraApp_MemoryUsageEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_CameraApp_MemoryUsageEventValidator();
    ~CrOSEvents_CameraApp_MemoryUsageEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(7670635453183417468);
};

CrOSEvents_CameraApp_MemoryUsageEventValidator::CrOSEvents_CameraApp_MemoryUsageEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_CameraApp_MemoryUsageEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_CameraApp_MemoryUsageEventValidator::~CrOSEvents_CameraApp_MemoryUsageEventValidator() = default;

void CrOSEvents_CameraApp_MemoryUsageEventValidator::Initialize()
{
    metric_metadata_ = { { "Behaviors", { Event::MetricType::kLong, UINT64_C(4700209534766344183) } },
        { "MemoryUsage", { Event::MetricType::kLong, UINT64_C(16490182591747914808) } } };

    metrics_name_map_ = { { UINT64_C(4700209534766344183), "Behaviors" }, { UINT64_C(16490182591747914808), "MemoryUsage" } };
}

class CrOSEvents_CameraApp_OcrEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_CameraApp_OcrEventValidator();
    ~CrOSEvents_CameraApp_OcrEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(5249398244840003813);
};

CrOSEvents_CameraApp_OcrEventValidator::CrOSEvents_CameraApp_OcrEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_CameraApp_OcrEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_CameraApp_OcrEventValidator::~CrOSEvents_CameraApp_OcrEventValidator() = default;

void CrOSEvents_CameraApp_OcrEventValidator::Initialize()
{
    metric_metadata_ = { { "EventType", { Event::MetricType::kInt, UINT64_C(5446425777535537951) } },
        { "IsPrimaryLanguage", { Event::MetricType::kLong, UINT64_C(5602775459885379213) } },
        { "LineCount", { Event::MetricType::kLong, UINT64_C(11054703378591998024) } },
        { "WordCount", { Event::MetricType::kLong, UINT64_C(11113615136000051604) } } };

    metrics_name_map_ = { { UINT64_C(5446425777535537951), "EventType" }, { UINT64_C(5602775459885379213), "IsPrimaryLanguage" },
        { UINT64_C(11054703378591998024), "LineCount" }, { UINT64_C(11113615136000051604), "WordCount" } };
}

class CrOSEvents_Growth_Ui_ButtonPressedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_Growth_Ui_ButtonPressedEventValidator();
    ~CrOSEvents_Growth_Ui_ButtonPressedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(9030171304122254777);
};

CrOSEvents_Growth_Ui_ButtonPressedEventValidator::CrOSEvents_Growth_Ui_ButtonPressedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_Growth_Ui_ButtonPressedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_Growth_Ui_ButtonPressedEventValidator::~CrOSEvents_Growth_Ui_ButtonPressedEventValidator() = default;

void CrOSEvents_Growth_Ui_ButtonPressedEventValidator::Initialize()
{
    metric_metadata_ = { { "CampaignId", { Event::MetricType::kLong, UINT64_C(2958941458260039650) } },
        { "ButtonId", { Event::MetricType::kInt, UINT64_C(14221048210491722787) } } };

    metrics_name_map_ = { { UINT64_C(2958941458260039650), "CampaignId" }, { UINT64_C(14221048210491722787), "ButtonId" } };
}

class CrOSEvents_Growth_Ui_DismissedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_Growth_Ui_DismissedEventValidator();
    ~CrOSEvents_Growth_Ui_DismissedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(17982940111339093869);
};

CrOSEvents_Growth_Ui_DismissedEventValidator::CrOSEvents_Growth_Ui_DismissedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_Growth_Ui_DismissedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_Growth_Ui_DismissedEventValidator::~CrOSEvents_Growth_Ui_DismissedEventValidator() = default;

void CrOSEvents_Growth_Ui_DismissedEventValidator::Initialize()
{
    metric_metadata_ = { { "CampaignId", { Event::MetricType::kLong, UINT64_C(2958941458260039650) } } };

    metrics_name_map_ = { { UINT64_C(2958941458260039650), "CampaignId" } };
}

class CrOSEvents_Growth_Ui_ImpressionEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_Growth_Ui_ImpressionEventValidator();
    ~CrOSEvents_Growth_Ui_ImpressionEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(9777892808369836221);
};

CrOSEvents_Growth_Ui_ImpressionEventValidator::CrOSEvents_Growth_Ui_ImpressionEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_Growth_Ui_ImpressionEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_Growth_Ui_ImpressionEventValidator::~CrOSEvents_Growth_Ui_ImpressionEventValidator() = default;

void CrOSEvents_Growth_Ui_ImpressionEventValidator::Initialize()
{
    metric_metadata_ = { { "CampaignId", { Event::MetricType::kLong, UINT64_C(2958941458260039650) } } };

    metrics_name_map_ = { { UINT64_C(2958941458260039650), "CampaignId" } };
}

class CrOSEvents_OOBE_GaiaSigninRequestedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_OOBE_GaiaSigninRequestedEventValidator();
    ~CrOSEvents_OOBE_GaiaSigninRequestedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(7215278611898390473);
};

CrOSEvents_OOBE_GaiaSigninRequestedEventValidator::CrOSEvents_OOBE_GaiaSigninRequestedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_OOBE_GaiaSigninRequestedEventValidator::kEventNameHash, true)
{
    Initialize();
}

CrOSEvents_OOBE_GaiaSigninRequestedEventValidator::~CrOSEvents_OOBE_GaiaSigninRequestedEventValidator() = default;

void CrOSEvents_OOBE_GaiaSigninRequestedEventValidator::Initialize()
{
    metric_metadata_ = { { "IsReauthentication", { Event::MetricType::kLong, UINT64_C(5577652860899525433) } },
        { "IsFlexFlow", { Event::MetricType::kLong, UINT64_C(5798416126479240383) } },
        { "IsDemoModeFlow", { Event::MetricType::kLong, UINT64_C(17073063279367758864) } },
        { "IsOwnerUser", { Event::MetricType::kLong, UINT64_C(9505254692993180831) } },
        { "IsEphemeralOrMGS", { Event::MetricType::kLong, UINT64_C(6790006799240086503) } },
        { "IsFirstOnboarding", { Event::MetricType::kLong, UINT64_C(13225088464573499838) } },
        { "ChromeMilestone", { Event::MetricType::kLong, UINT64_C(8933670696912054868) } } };

    metrics_name_map_ = { { UINT64_C(5577652860899525433), "IsReauthentication" }, { UINT64_C(5798416126479240383), "IsFlexFlow" },
        { UINT64_C(17073063279367758864), "IsDemoModeFlow" }, { UINT64_C(9505254692993180831), "IsOwnerUser" },
        { UINT64_C(6790006799240086503), "IsEphemeralOrMGS" }, { UINT64_C(13225088464573499838), "IsFirstOnboarding" },
        { UINT64_C(8933670696912054868), "ChromeMilestone" } };
}

class CrOSEvents_OOBE_GaiaSigninCompletedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_OOBE_GaiaSigninCompletedEventValidator();
    ~CrOSEvents_OOBE_GaiaSigninCompletedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(4496792889211345956);
};

CrOSEvents_OOBE_GaiaSigninCompletedEventValidator::CrOSEvents_OOBE_GaiaSigninCompletedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_OOBE_GaiaSigninCompletedEventValidator::kEventNameHash, true)
{
    Initialize();
}

CrOSEvents_OOBE_GaiaSigninCompletedEventValidator::~CrOSEvents_OOBE_GaiaSigninCompletedEventValidator() = default;

void CrOSEvents_OOBE_GaiaSigninCompletedEventValidator::Initialize()
{
    metric_metadata_ = { { "IsReauthentication", { Event::MetricType::kLong, UINT64_C(5577652860899525433) } },
        { "IsFlexFlow", { Event::MetricType::kLong, UINT64_C(5798416126479240383) } },
        { "IsDemoModeFlow", { Event::MetricType::kLong, UINT64_C(17073063279367758864) } },
        { "IsOwnerUser", { Event::MetricType::kLong, UINT64_C(9505254692993180831) } },
        { "IsEphemeralOrMGS", { Event::MetricType::kLong, UINT64_C(6790006799240086503) } },
        { "IsFirstOnboarding", { Event::MetricType::kLong, UINT64_C(13225088464573499838) } },
        { "ChromeMilestone", { Event::MetricType::kLong, UINT64_C(8933670696912054868) } } };

    metrics_name_map_ = { { UINT64_C(5577652860899525433), "IsReauthentication" }, { UINT64_C(5798416126479240383), "IsFlexFlow" },
        { UINT64_C(17073063279367758864), "IsDemoModeFlow" }, { UINT64_C(9505254692993180831), "IsOwnerUser" },
        { UINT64_C(6790006799240086503), "IsEphemeralOrMGS" }, { UINT64_C(13225088464573499838), "IsFirstOnboarding" },
        { UINT64_C(8933670696912054868), "ChromeMilestone" } };
}

class CrOSEvents_OOBE_OobeStartedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_OOBE_OobeStartedEventValidator();
    ~CrOSEvents_OOBE_OobeStartedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(16917942210530705939);
};

CrOSEvents_OOBE_OobeStartedEventValidator::CrOSEvents_OOBE_OobeStartedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_OOBE_OobeStartedEventValidator::kEventNameHash, true)
{
    Initialize();
}

CrOSEvents_OOBE_OobeStartedEventValidator::~CrOSEvents_OOBE_OobeStartedEventValidator() = default;

void CrOSEvents_OOBE_OobeStartedEventValidator::Initialize()
{
    metric_metadata_ = { { "IsFlexFlow", { Event::MetricType::kLong, UINT64_C(5798416126479240383) } },
        { "ChromeMilestone", { Event::MetricType::kLong, UINT64_C(8933670696912054868) } } };

    metrics_name_map_ = { { UINT64_C(5798416126479240383), "IsFlexFlow" }, { UINT64_C(8933670696912054868), "ChromeMilestone" } };
}

class CrOSEvents_OOBE_PreLoginOobeCompletedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_OOBE_PreLoginOobeCompletedEventValidator();
    ~CrOSEvents_OOBE_PreLoginOobeCompletedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(16454148751386228729);
};

CrOSEvents_OOBE_PreLoginOobeCompletedEventValidator::CrOSEvents_OOBE_PreLoginOobeCompletedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_OOBE_PreLoginOobeCompletedEventValidator::kEventNameHash, true)
{
    Initialize();
}

CrOSEvents_OOBE_PreLoginOobeCompletedEventValidator::~CrOSEvents_OOBE_PreLoginOobeCompletedEventValidator() = default;

void CrOSEvents_OOBE_PreLoginOobeCompletedEventValidator::Initialize()
{
    metric_metadata_ = { { "CompletedFlowType", { Event::MetricType::kLong, UINT64_C(4412736575066763809) } },
        { "IsFlexFlow", { Event::MetricType::kLong, UINT64_C(5798416126479240383) } },
        { "IsDemoModeFlow", { Event::MetricType::kLong, UINT64_C(17073063279367758864) } },
        { "ChromeMilestone", { Event::MetricType::kLong, UINT64_C(8933670696912054868) } } };

    metrics_name_map_ = { { UINT64_C(4412736575066763809), "CompletedFlowType" }, { UINT64_C(5798416126479240383), "IsFlexFlow" },
        { UINT64_C(17073063279367758864), "IsDemoModeFlow" }, { UINT64_C(8933670696912054868), "ChromeMilestone" } };
}

class CrOSEvents_OOBE_DeviceRegisteredEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_OOBE_DeviceRegisteredEventValidator();
    ~CrOSEvents_OOBE_DeviceRegisteredEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(8463510949069965716);
};

CrOSEvents_OOBE_DeviceRegisteredEventValidator::CrOSEvents_OOBE_DeviceRegisteredEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_OOBE_DeviceRegisteredEventValidator::kEventNameHash, true)
{
    Initialize();
}

CrOSEvents_OOBE_DeviceRegisteredEventValidator::~CrOSEvents_OOBE_DeviceRegisteredEventValidator() = default;

void CrOSEvents_OOBE_DeviceRegisteredEventValidator::Initialize()
{
    metric_metadata_ = { { "IsFirstOnboarding", { Event::MetricType::kLong, UINT64_C(13225088464573499838) } },
        { "IsFlexFlow", { Event::MetricType::kLong, UINT64_C(5798416126479240383) } },
        { "IsDemoModeFlow", { Event::MetricType::kLong, UINT64_C(17073063279367758864) } },
        { "ChromeMilestone", { Event::MetricType::kLong, UINT64_C(8933670696912054868) } } };

    metrics_name_map_ = { { UINT64_C(13225088464573499838), "IsFirstOnboarding" }, { UINT64_C(5798416126479240383), "IsFlexFlow" },
        { UINT64_C(17073063279367758864), "IsDemoModeFlow" }, { UINT64_C(8933670696912054868), "ChromeMilestone" } };
}

class CrOSEvents_OOBE_OobeCompletedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_OOBE_OobeCompletedEventValidator();
    ~CrOSEvents_OOBE_OobeCompletedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(10747825633360213518);
};

CrOSEvents_OOBE_OobeCompletedEventValidator::CrOSEvents_OOBE_OobeCompletedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_OOBE_OobeCompletedEventValidator::kEventNameHash, true)
{
    Initialize();
}

CrOSEvents_OOBE_OobeCompletedEventValidator::~CrOSEvents_OOBE_OobeCompletedEventValidator() = default;

void CrOSEvents_OOBE_OobeCompletedEventValidator::Initialize()
{
    metric_metadata_ = { { "IsFlexFlow", { Event::MetricType::kLong, UINT64_C(5798416126479240383) } },
        { "IsDemoModeFlow", { Event::MetricType::kLong, UINT64_C(17073063279367758864) } },
        { "IsOwnerUser", { Event::MetricType::kLong, UINT64_C(9505254692993180831) } },
        { "IsEphemeralOrMGS", { Event::MetricType::kLong, UINT64_C(6790006799240086503) } },
        { "IsFirstOnboarding", { Event::MetricType::kLong, UINT64_C(13225088464573499838) } },
        { "ChromeMilestone", { Event::MetricType::kLong, UINT64_C(8933670696912054868) } } };

    metrics_name_map_ = { { UINT64_C(5798416126479240383), "IsFlexFlow" }, { UINT64_C(17073063279367758864), "IsDemoModeFlow" },
        { UINT64_C(9505254692993180831), "IsOwnerUser" }, { UINT64_C(6790006799240086503), "IsEphemeralOrMGS" },
        { UINT64_C(13225088464573499838), "IsFirstOnboarding" }, { UINT64_C(8933670696912054868), "ChromeMilestone" } };
}

class CrOSEvents_OOBE_OnboardingStartedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_OOBE_OnboardingStartedEventValidator();
    ~CrOSEvents_OOBE_OnboardingStartedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(11157696941906249496);
};

CrOSEvents_OOBE_OnboardingStartedEventValidator::CrOSEvents_OOBE_OnboardingStartedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_OOBE_OnboardingStartedEventValidator::kEventNameHash, true)
{
    Initialize();
}

CrOSEvents_OOBE_OnboardingStartedEventValidator::~CrOSEvents_OOBE_OnboardingStartedEventValidator() = default;

void CrOSEvents_OOBE_OnboardingStartedEventValidator::Initialize()
{
    metric_metadata_ = { { "IsFlexFlow", { Event::MetricType::kLong, UINT64_C(5798416126479240383) } },
        { "IsDemoModeFlow", { Event::MetricType::kLong, UINT64_C(17073063279367758864) } },
        { "IsOwnerUser", { Event::MetricType::kLong, UINT64_C(9505254692993180831) } },
        { "IsEphemeralOrMGS", { Event::MetricType::kLong, UINT64_C(6790006799240086503) } },
        { "IsFirstOnboarding", { Event::MetricType::kLong, UINT64_C(13225088464573499838) } },
        { "ChromeMilestone", { Event::MetricType::kLong, UINT64_C(8933670696912054868) } } };

    metrics_name_map_ = { { UINT64_C(5798416126479240383), "IsFlexFlow" }, { UINT64_C(17073063279367758864), "IsDemoModeFlow" },
        { UINT64_C(9505254692993180831), "IsOwnerUser" }, { UINT64_C(6790006799240086503), "IsEphemeralOrMGS" },
        { UINT64_C(13225088464573499838), "IsFirstOnboarding" }, { UINT64_C(8933670696912054868), "ChromeMilestone" } };
}

class CrOSEvents_OOBE_OnboardingCompletedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_OOBE_OnboardingCompletedEventValidator();
    ~CrOSEvents_OOBE_OnboardingCompletedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(17879153985667426106);
};

CrOSEvents_OOBE_OnboardingCompletedEventValidator::CrOSEvents_OOBE_OnboardingCompletedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_OOBE_OnboardingCompletedEventValidator::kEventNameHash, true)
{
    Initialize();
}

CrOSEvents_OOBE_OnboardingCompletedEventValidator::~CrOSEvents_OOBE_OnboardingCompletedEventValidator() = default;

void CrOSEvents_OOBE_OnboardingCompletedEventValidator::Initialize()
{
    metric_metadata_ = { { "IsFlexFlow", { Event::MetricType::kLong, UINT64_C(5798416126479240383) } },
        { "IsDemoModeFlow", { Event::MetricType::kLong, UINT64_C(17073063279367758864) } },
        { "IsOwnerUser", { Event::MetricType::kLong, UINT64_C(9505254692993180831) } },
        { "IsEphemeralOrMGS", { Event::MetricType::kLong, UINT64_C(6790006799240086503) } },
        { "IsFirstOnboarding", { Event::MetricType::kLong, UINT64_C(13225088464573499838) } },
        { "ChromeMilestone", { Event::MetricType::kLong, UINT64_C(8933670696912054868) } } };

    metrics_name_map_ = { { UINT64_C(5798416126479240383), "IsFlexFlow" }, { UINT64_C(17073063279367758864), "IsDemoModeFlow" },
        { UINT64_C(9505254692993180831), "IsOwnerUser" }, { UINT64_C(6790006799240086503), "IsEphemeralOrMGS" },
        { UINT64_C(13225088464573499838), "IsFirstOnboarding" }, { UINT64_C(8933670696912054868), "ChromeMilestone" } };
}

class CrOSEvents_OOBE_PageEnteredEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_OOBE_PageEnteredEventValidator();
    ~CrOSEvents_OOBE_PageEnteredEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(5040523310352364307);
};

CrOSEvents_OOBE_PageEnteredEventValidator::CrOSEvents_OOBE_PageEnteredEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_OOBE_PageEnteredEventValidator::kEventNameHash, true)
{
    Initialize();
}

CrOSEvents_OOBE_PageEnteredEventValidator::~CrOSEvents_OOBE_PageEnteredEventValidator() = default;

void CrOSEvents_OOBE_PageEnteredEventValidator::Initialize()
{
    metric_metadata_ = { { "PageId", { Event::MetricType::kRawString, UINT64_C(10985869583411328777) } },
        { "IsFlexFlow", { Event::MetricType::kLong, UINT64_C(5798416126479240383) } },
        { "IsDemoModeFlow", { Event::MetricType::kLong, UINT64_C(17073063279367758864) } },
        { "IsOwnerUser", { Event::MetricType::kLong, UINT64_C(9505254692993180831) } },
        { "IsEphemeralOrMGS", { Event::MetricType::kLong, UINT64_C(6790006799240086503) } },
        { "IsFirstOnboarding", { Event::MetricType::kLong, UINT64_C(13225088464573499838) } },
        { "ChromeMilestone", { Event::MetricType::kLong, UINT64_C(8933670696912054868) } } };

    metrics_name_map_
        = { { UINT64_C(10985869583411328777), "PageId" }, { UINT64_C(5798416126479240383), "IsFlexFlow" }, { UINT64_C(17073063279367758864), "IsDemoModeFlow" },
              { UINT64_C(9505254692993180831), "IsOwnerUser" }, { UINT64_C(6790006799240086503), "IsEphemeralOrMGS" },
              { UINT64_C(13225088464573499838), "IsFirstOnboarding" }, { UINT64_C(8933670696912054868), "ChromeMilestone" } };
}

class CrOSEvents_OOBE_PageSkippedBySystemEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_OOBE_PageSkippedBySystemEventValidator();
    ~CrOSEvents_OOBE_PageSkippedBySystemEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(3047534590220959328);
};

CrOSEvents_OOBE_PageSkippedBySystemEventValidator::CrOSEvents_OOBE_PageSkippedBySystemEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_OOBE_PageSkippedBySystemEventValidator::kEventNameHash, true)
{
    Initialize();
}

CrOSEvents_OOBE_PageSkippedBySystemEventValidator::~CrOSEvents_OOBE_PageSkippedBySystemEventValidator() = default;

void CrOSEvents_OOBE_PageSkippedBySystemEventValidator::Initialize()
{
    metric_metadata_ = { { "PageId", { Event::MetricType::kRawString, UINT64_C(10985869583411328777) } },
        { "IsFlexFlow", { Event::MetricType::kLong, UINT64_C(5798416126479240383) } },
        { "IsDemoModeFlow", { Event::MetricType::kLong, UINT64_C(17073063279367758864) } },
        { "IsOwnerUser", { Event::MetricType::kLong, UINT64_C(9505254692993180831) } },
        { "IsEphemeralOrMGS", { Event::MetricType::kLong, UINT64_C(6790006799240086503) } },
        { "IsFirstOnboarding", { Event::MetricType::kLong, UINT64_C(13225088464573499838) } },
        { "ChromeMilestone", { Event::MetricType::kLong, UINT64_C(8933670696912054868) } } };

    metrics_name_map_
        = { { UINT64_C(10985869583411328777), "PageId" }, { UINT64_C(5798416126479240383), "IsFlexFlow" }, { UINT64_C(17073063279367758864), "IsDemoModeFlow" },
              { UINT64_C(9505254692993180831), "IsOwnerUser" }, { UINT64_C(6790006799240086503), "IsEphemeralOrMGS" },
              { UINT64_C(13225088464573499838), "IsFirstOnboarding" }, { UINT64_C(8933670696912054868), "ChromeMilestone" } };
}

class CrOSEvents_OOBE_PageLeftEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_OOBE_PageLeftEventValidator();
    ~CrOSEvents_OOBE_PageLeftEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(9866162796307818893);
};

CrOSEvents_OOBE_PageLeftEventValidator::CrOSEvents_OOBE_PageLeftEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_OOBE_PageLeftEventValidator::kEventNameHash, true)
{
    Initialize();
}

CrOSEvents_OOBE_PageLeftEventValidator::~CrOSEvents_OOBE_PageLeftEventValidator() = default;

void CrOSEvents_OOBE_PageLeftEventValidator::Initialize()
{
    metric_metadata_ = { { "PageId", { Event::MetricType::kRawString, UINT64_C(10985869583411328777) } },
        { "ExitReason", { Event::MetricType::kRawString, UINT64_C(17511456341007791027) } },
        { "IsFlexFlow", { Event::MetricType::kLong, UINT64_C(5798416126479240383) } },
        { "IsDemoModeFlow", { Event::MetricType::kLong, UINT64_C(17073063279367758864) } },
        { "IsOwnerUser", { Event::MetricType::kLong, UINT64_C(9505254692993180831) } },
        { "IsEphemeralOrMGS", { Event::MetricType::kLong, UINT64_C(6790006799240086503) } },
        { "IsFirstOnboarding", { Event::MetricType::kLong, UINT64_C(13225088464573499838) } },
        { "ChromeMilestone", { Event::MetricType::kLong, UINT64_C(8933670696912054868) } } };

    metrics_name_map_ = { { UINT64_C(10985869583411328777), "PageId" }, { UINT64_C(17511456341007791027), "ExitReason" },
        { UINT64_C(5798416126479240383), "IsFlexFlow" }, { UINT64_C(17073063279367758864), "IsDemoModeFlow" }, { UINT64_C(9505254692993180831), "IsOwnerUser" },
        { UINT64_C(6790006799240086503), "IsEphemeralOrMGS" }, { UINT64_C(13225088464573499838), "IsFirstOnboarding" },
        { UINT64_C(8933670696912054868), "ChromeMilestone" } };
}

class CrOSEvents_OOBE_PreLoginOobeResumedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_OOBE_PreLoginOobeResumedEventValidator();
    ~CrOSEvents_OOBE_PreLoginOobeResumedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(5945023717299231192);
};

CrOSEvents_OOBE_PreLoginOobeResumedEventValidator::CrOSEvents_OOBE_PreLoginOobeResumedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_OOBE_PreLoginOobeResumedEventValidator::kEventNameHash, true)
{
    Initialize();
}

CrOSEvents_OOBE_PreLoginOobeResumedEventValidator::~CrOSEvents_OOBE_PreLoginOobeResumedEventValidator() = default;

void CrOSEvents_OOBE_PreLoginOobeResumedEventValidator::Initialize()
{
    metric_metadata_ = { { "PendingPageId", { Event::MetricType::kRawString, UINT64_C(18257920047382457110) } },
        { "ExitReason", { Event::MetricType::kRawString, UINT64_C(17511456341007791027) } },
        { "IsFlexFlow", { Event::MetricType::kLong, UINT64_C(5798416126479240383) } },
        { "IsDemoModeFlow", { Event::MetricType::kLong, UINT64_C(17073063279367758864) } },
        { "IsOwnerUser", { Event::MetricType::kLong, UINT64_C(9505254692993180831) } },
        { "IsEphemeralOrMGS", { Event::MetricType::kLong, UINT64_C(6790006799240086503) } },
        { "IsFirstOnboarding", { Event::MetricType::kLong, UINT64_C(13225088464573499838) } },
        { "ChromeMilestone", { Event::MetricType::kLong, UINT64_C(8933670696912054868) } } };

    metrics_name_map_ = { { UINT64_C(18257920047382457110), "PendingPageId" }, { UINT64_C(17511456341007791027), "ExitReason" },
        { UINT64_C(5798416126479240383), "IsFlexFlow" }, { UINT64_C(17073063279367758864), "IsDemoModeFlow" }, { UINT64_C(9505254692993180831), "IsOwnerUser" },
        { UINT64_C(6790006799240086503), "IsEphemeralOrMGS" }, { UINT64_C(13225088464573499838), "IsFirstOnboarding" },
        { UINT64_C(8933670696912054868), "ChromeMilestone" } };
}

class CrOSEvents_OOBE_OnboardingResumedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_OOBE_OnboardingResumedEventValidator();
    ~CrOSEvents_OOBE_OnboardingResumedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(10437926740417395028);
};

CrOSEvents_OOBE_OnboardingResumedEventValidator::CrOSEvents_OOBE_OnboardingResumedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_OOBE_OnboardingResumedEventValidator::kEventNameHash, true)
{
    Initialize();
}

CrOSEvents_OOBE_OnboardingResumedEventValidator::~CrOSEvents_OOBE_OnboardingResumedEventValidator() = default;

void CrOSEvents_OOBE_OnboardingResumedEventValidator::Initialize()
{
    metric_metadata_ = { { "PendingPageId", { Event::MetricType::kRawString, UINT64_C(18257920047382457110) } },
        { "ExitReason", { Event::MetricType::kRawString, UINT64_C(17511456341007791027) } },
        { "IsFlexFlow", { Event::MetricType::kLong, UINT64_C(5798416126479240383) } },
        { "IsDemoModeFlow", { Event::MetricType::kLong, UINT64_C(17073063279367758864) } },
        { "IsOwnerUser", { Event::MetricType::kLong, UINT64_C(9505254692993180831) } },
        { "IsEphemeralOrMGS", { Event::MetricType::kLong, UINT64_C(6790006799240086503) } },
        { "IsFirstOnboarding", { Event::MetricType::kLong, UINT64_C(13225088464573499838) } },
        { "ChromeMilestone", { Event::MetricType::kLong, UINT64_C(8933670696912054868) } } };

    metrics_name_map_ = { { UINT64_C(18257920047382457110), "PendingPageId" }, { UINT64_C(17511456341007791027), "ExitReason" },
        { UINT64_C(5798416126479240383), "IsFlexFlow" }, { UINT64_C(17073063279367758864), "IsDemoModeFlow" }, { UINT64_C(9505254692993180831), "IsOwnerUser" },
        { UINT64_C(6790006799240086503), "IsEphemeralOrMGS" }, { UINT64_C(13225088464573499838), "IsFirstOnboarding" },
        { UINT64_C(8933670696912054868), "ChromeMilestone" } };
}

class CrOSEvents_OOBE_ChoobeResumedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_OOBE_ChoobeResumedEventValidator();
    ~CrOSEvents_OOBE_ChoobeResumedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(5000399004328028203);
};

CrOSEvents_OOBE_ChoobeResumedEventValidator::CrOSEvents_OOBE_ChoobeResumedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_OOBE_ChoobeResumedEventValidator::kEventNameHash, true)
{
    Initialize();
}

CrOSEvents_OOBE_ChoobeResumedEventValidator::~CrOSEvents_OOBE_ChoobeResumedEventValidator() = default;

void CrOSEvents_OOBE_ChoobeResumedEventValidator::Initialize()
{
    metric_metadata_ = { { "ExitReason", { Event::MetricType::kRawString, UINT64_C(17511456341007791027) } },
        { "IsFlexFlow", { Event::MetricType::kLong, UINT64_C(5798416126479240383) } },
        { "IsDemoModeFlow", { Event::MetricType::kLong, UINT64_C(17073063279367758864) } },
        { "IsOwnerUser", { Event::MetricType::kLong, UINT64_C(9505254692993180831) } },
        { "IsEphemeralOrMGS", { Event::MetricType::kLong, UINT64_C(6790006799240086503) } },
        { "IsFirstOnboarding", { Event::MetricType::kLong, UINT64_C(13225088464573499838) } },
        { "ChromeMilestone", { Event::MetricType::kLong, UINT64_C(8933670696912054868) } } };

    metrics_name_map_ = { { UINT64_C(17511456341007791027), "ExitReason" }, { UINT64_C(5798416126479240383), "IsFlexFlow" },
        { UINT64_C(17073063279367758864), "IsDemoModeFlow" }, { UINT64_C(9505254692993180831), "IsOwnerUser" },
        { UINT64_C(6790006799240086503), "IsEphemeralOrMGS" }, { UINT64_C(13225088464573499838), "IsFirstOnboarding" },
        { UINT64_C(8933670696912054868), "ChromeMilestone" } };
}

class CrOSEvents_Picker_StartSessionEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_Picker_StartSessionEventValidator();
    ~CrOSEvents_Picker_StartSessionEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(9220963912679537764);
};

CrOSEvents_Picker_StartSessionEventValidator::CrOSEvents_Picker_StartSessionEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_Picker_StartSessionEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_Picker_StartSessionEventValidator::~CrOSEvents_Picker_StartSessionEventValidator() = default;

void CrOSEvents_Picker_StartSessionEventValidator::Initialize()
{
    metric_metadata_ = { { "InputFieldType", { Event::MetricType::kInt, UINT64_C(950879100125546993) } },
        { "SelectionLength", { Event::MetricType::kLong, UINT64_C(10867454528311693071) } } };

    metrics_name_map_ = { { UINT64_C(950879100125546993), "InputFieldType" }, { UINT64_C(10867454528311693071), "SelectionLength" } };
}

class CrOSEvents_Picker_FinishSessionEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_Picker_FinishSessionEventValidator();
    ~CrOSEvents_Picker_FinishSessionEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(201053742732988011);
};

CrOSEvents_Picker_FinishSessionEventValidator::CrOSEvents_Picker_FinishSessionEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_Picker_FinishSessionEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_Picker_FinishSessionEventValidator::~CrOSEvents_Picker_FinishSessionEventValidator() = default;

void CrOSEvents_Picker_FinishSessionEventValidator::Initialize()
{
    metric_metadata_ = { { "Outcome", { Event::MetricType::kInt, UINT64_C(14948499774890759507) } },
        { "Action", { Event::MetricType::kInt, UINT64_C(21381969153622804) } }, { "ResultSource", { Event::MetricType::kInt, UINT64_C(3250885703202095730) } },
        { "ResultType", { Event::MetricType::kInt, UINT64_C(8293845286137751377) } },
        { "TotalEdits", { Event::MetricType::kLong, UINT64_C(15496493931690867361) } },
        { "FinalQuerySize", { Event::MetricType::kLong, UINT64_C(12456793078331395270) } },
        { "ResultIndex", { Event::MetricType::kLong, UINT64_C(14050360147635690067) } } };

    metrics_name_map_ = { { UINT64_C(14948499774890759507), "Outcome" }, { UINT64_C(21381969153622804), "Action" },
        { UINT64_C(3250885703202095730), "ResultSource" }, { UINT64_C(8293845286137751377), "ResultType" }, { UINT64_C(15496493931690867361), "TotalEdits" },
        { UINT64_C(12456793078331395270), "FinalQuerySize" }, { UINT64_C(14050360147635690067), "ResultIndex" } };
}

class CrOSEvents_QuickStart_ScreenOpenedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_QuickStart_ScreenOpenedEventValidator();
    ~CrOSEvents_QuickStart_ScreenOpenedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(1090623010432954280);
};

CrOSEvents_QuickStart_ScreenOpenedEventValidator::CrOSEvents_QuickStart_ScreenOpenedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_QuickStart_ScreenOpenedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_QuickStart_ScreenOpenedEventValidator::~CrOSEvents_QuickStart_ScreenOpenedEventValidator() = default;

void CrOSEvents_QuickStart_ScreenOpenedEventValidator::Initialize()
{
    metric_metadata_ = { { "ScreenName", { Event::MetricType::kInt, UINT64_C(3762975082825354124) } } };

    metrics_name_map_ = { { UINT64_C(3762975082825354124), "ScreenName" } };
}

class CrOSEvents_QuickStart_ScreenClosedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_QuickStart_ScreenClosedEventValidator();
    ~CrOSEvents_QuickStart_ScreenClosedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(15755974401621020180);
};

CrOSEvents_QuickStart_ScreenClosedEventValidator::CrOSEvents_QuickStart_ScreenClosedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_QuickStart_ScreenClosedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_QuickStart_ScreenClosedEventValidator::~CrOSEvents_QuickStart_ScreenClosedEventValidator() = default;

void CrOSEvents_QuickStart_ScreenClosedEventValidator::Initialize()
{
    metric_metadata_ = { { "ScreenName", { Event::MetricType::kInt, UINT64_C(3762975082825354124) } } };

    metrics_name_map_ = { { UINT64_C(3762975082825354124), "ScreenName" } };
}

class CrOSEvents_QuickStart_InitiatedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_QuickStart_InitiatedEventValidator();
    ~CrOSEvents_QuickStart_InitiatedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(10069442393575500987);
};

CrOSEvents_QuickStart_InitiatedEventValidator::CrOSEvents_QuickStart_InitiatedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_QuickStart_InitiatedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_QuickStart_InitiatedEventValidator::~CrOSEvents_QuickStart_InitiatedEventValidator() = default;

void CrOSEvents_QuickStart_InitiatedEventValidator::Initialize()
{
    metric_metadata_ = { { "EntryPoint", { Event::MetricType::kInt, UINT64_C(14367068064969258826) } } };

    metrics_name_map_ = { { UINT64_C(14367068064969258826), "EntryPoint" } };
}

class CrOSEvents_QuickStart_FlowAbortedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_QuickStart_FlowAbortedEventValidator();
    ~CrOSEvents_QuickStart_FlowAbortedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(271458273284797266);
};

CrOSEvents_QuickStart_FlowAbortedEventValidator::CrOSEvents_QuickStart_FlowAbortedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_QuickStart_FlowAbortedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_QuickStart_FlowAbortedEventValidator::~CrOSEvents_QuickStart_FlowAbortedEventValidator() = default;

void CrOSEvents_QuickStart_FlowAbortedEventValidator::Initialize()
{
    metric_metadata_ = { { "Reason", { Event::MetricType::kInt, UINT64_C(18445816987321669298) } } };

    metrics_name_map_ = { { UINT64_C(18445816987321669298), "Reason" } };
}

class CrOSEvents_QuickStart_EstablishConnectionEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_QuickStart_EstablishConnectionEventValidator();
    ~CrOSEvents_QuickStart_EstablishConnectionEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(5941464810469552436);
};

CrOSEvents_QuickStart_EstablishConnectionEventValidator::CrOSEvents_QuickStart_EstablishConnectionEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_QuickStart_EstablishConnectionEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_QuickStart_EstablishConnectionEventValidator::~CrOSEvents_QuickStart_EstablishConnectionEventValidator() = default;

void CrOSEvents_QuickStart_EstablishConnectionEventValidator::Initialize()
{
    metric_metadata_ = { { "Success", { Event::MetricType::kLong, UINT64_C(5790085346892983794) } } };

    metrics_name_map_ = { { UINT64_C(5790085346892983794), "Success" } };
}

class CrOSEvents_QuickStart_AutomaticResumeAfterUpdateEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_QuickStart_AutomaticResumeAfterUpdateEventValidator();
    ~CrOSEvents_QuickStart_AutomaticResumeAfterUpdateEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(12354443421864201072);
};

CrOSEvents_QuickStart_AutomaticResumeAfterUpdateEventValidator::CrOSEvents_QuickStart_AutomaticResumeAfterUpdateEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_QuickStart_AutomaticResumeAfterUpdateEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_QuickStart_AutomaticResumeAfterUpdateEventValidator::~CrOSEvents_QuickStart_AutomaticResumeAfterUpdateEventValidator() = default;

void CrOSEvents_QuickStart_AutomaticResumeAfterUpdateEventValidator::Initialize()
{
    metric_metadata_ = { { "Success", { Event::MetricType::kLong, UINT64_C(5790085346892983794) } } };

    metrics_name_map_ = { { UINT64_C(5790085346892983794), "Success" } };
}

class CrOSEvents_QuickStart_GetWifiCredentialsEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_QuickStart_GetWifiCredentialsEventValidator();
    ~CrOSEvents_QuickStart_GetWifiCredentialsEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(2010302068650205616);
};

CrOSEvents_QuickStart_GetWifiCredentialsEventValidator::CrOSEvents_QuickStart_GetWifiCredentialsEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_QuickStart_GetWifiCredentialsEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_QuickStart_GetWifiCredentialsEventValidator::~CrOSEvents_QuickStart_GetWifiCredentialsEventValidator() = default;

void CrOSEvents_QuickStart_GetWifiCredentialsEventValidator::Initialize()
{
    metric_metadata_ = { { "Success", { Event::MetricType::kLong, UINT64_C(5790085346892983794) } } };

    metrics_name_map_ = { { UINT64_C(5790085346892983794), "Success" } };
}

class CrOSEvents_QuickStart_InstallForcedUpdateEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_QuickStart_InstallForcedUpdateEventValidator();
    ~CrOSEvents_QuickStart_InstallForcedUpdateEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(9647936154020725001);
};

CrOSEvents_QuickStart_InstallForcedUpdateEventValidator::CrOSEvents_QuickStart_InstallForcedUpdateEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_QuickStart_InstallForcedUpdateEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_QuickStart_InstallForcedUpdateEventValidator::~CrOSEvents_QuickStart_InstallForcedUpdateEventValidator() = default;

void CrOSEvents_QuickStart_InstallForcedUpdateEventValidator::Initialize()
{
    metric_metadata_ = {

    };

    metrics_name_map_ = {

    };
}

class CrOSEvents_QuickStart_InstallConsumerUpdateEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_QuickStart_InstallConsumerUpdateEventValidator();
    ~CrOSEvents_QuickStart_InstallConsumerUpdateEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(10280751123048611555);
};

CrOSEvents_QuickStart_InstallConsumerUpdateEventValidator::CrOSEvents_QuickStart_InstallConsumerUpdateEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_QuickStart_InstallConsumerUpdateEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_QuickStart_InstallConsumerUpdateEventValidator::~CrOSEvents_QuickStart_InstallConsumerUpdateEventValidator() = default;

void CrOSEvents_QuickStart_InstallConsumerUpdateEventValidator::Initialize()
{
    metric_metadata_ = {

    };

    metrics_name_map_ = {

    };
}

class CrOSEvents_QuickStart_ConsumerUpdateCancelledEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_QuickStart_ConsumerUpdateCancelledEventValidator();
    ~CrOSEvents_QuickStart_ConsumerUpdateCancelledEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(2414761012814314589);
};

CrOSEvents_QuickStart_ConsumerUpdateCancelledEventValidator::CrOSEvents_QuickStart_ConsumerUpdateCancelledEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_QuickStart_ConsumerUpdateCancelledEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_QuickStart_ConsumerUpdateCancelledEventValidator::~CrOSEvents_QuickStart_ConsumerUpdateCancelledEventValidator() = default;

void CrOSEvents_QuickStart_ConsumerUpdateCancelledEventValidator::Initialize()
{
    metric_metadata_ = {

    };

    metrics_name_map_ = {

    };
}

class CrOSEvents_QuickStart_AccountTransferStartedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_QuickStart_AccountTransferStartedEventValidator();
    ~CrOSEvents_QuickStart_AccountTransferStartedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(12443251032486016611);
};

CrOSEvents_QuickStart_AccountTransferStartedEventValidator::CrOSEvents_QuickStart_AccountTransferStartedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_QuickStart_AccountTransferStartedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_QuickStart_AccountTransferStartedEventValidator::~CrOSEvents_QuickStart_AccountTransferStartedEventValidator() = default;

void CrOSEvents_QuickStart_AccountTransferStartedEventValidator::Initialize()
{
    metric_metadata_ = {

    };

    metrics_name_map_ = {

    };
}

class CrOSEvents_QuickStart_AccountTransferCompleteEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_QuickStart_AccountTransferCompleteEventValidator();
    ~CrOSEvents_QuickStart_AccountTransferCompleteEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(2521315848004865523);
};

CrOSEvents_QuickStart_AccountTransferCompleteEventValidator::CrOSEvents_QuickStart_AccountTransferCompleteEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_QuickStart_AccountTransferCompleteEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_QuickStart_AccountTransferCompleteEventValidator::~CrOSEvents_QuickStart_AccountTransferCompleteEventValidator() = default;

void CrOSEvents_QuickStart_AccountTransferCompleteEventValidator::Initialize()
{
    metric_metadata_ = { { "Success", { Event::MetricType::kLong, UINT64_C(5790085346892983794) } } };

    metrics_name_map_ = { { UINT64_C(5790085346892983794), "Success" } };
}

class CrOSEvents_RecorderApp_StartSessionEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_StartSessionEventValidator();
    ~CrOSEvents_RecorderApp_StartSessionEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(17953969145682322416);
};

CrOSEvents_RecorderApp_StartSessionEventValidator::CrOSEvents_RecorderApp_StartSessionEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_StartSessionEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_StartSessionEventValidator::~CrOSEvents_RecorderApp_StartSessionEventValidator() = default;

void CrOSEvents_RecorderApp_StartSessionEventValidator::Initialize()
{
    metric_metadata_ = { { "SpeakerLabelEnableState", { Event::MetricType::kInt, UINT64_C(7185056042130600927) } },
        { "SummaryEnableState", { Event::MetricType::kInt, UINT64_C(7219783397079093482) } },
        { "TranscriptionEnableState", { Event::MetricType::kInt, UINT64_C(11991758514740170116) } } };

    metrics_name_map_ = { { UINT64_C(7185056042130600927), "SpeakerLabelEnableState" }, { UINT64_C(7219783397079093482), "SummaryEnableState" },
        { UINT64_C(11991758514740170116), "TranscriptionEnableState" } };
}

class CrOSEvents_RecorderApp_RecordEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_RecordEventValidator();
    ~CrOSEvents_RecorderApp_RecordEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(7805421305578040825);
};

CrOSEvents_RecorderApp_RecordEventValidator::CrOSEvents_RecorderApp_RecordEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_RecordEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_RecordEventValidator::~CrOSEvents_RecorderApp_RecordEventValidator() = default;

void CrOSEvents_RecorderApp_RecordEventValidator::Initialize()
{
    metric_metadata_ = { { "MicrophoneType", { Event::MetricType::kInt, UINT64_C(16635485834660957432) } },
        { "IncludeSystemAudio", { Event::MetricType::kLong, UINT64_C(5806201864338858385) } },
        { "AudioDuration", { Event::MetricType::kLong, UINT64_C(5537392993791184098) } },
        { "RecordDuration", { Event::MetricType::kLong, UINT64_C(5782425229489164648) } },
        { "EverPaused", { Event::MetricType::kLong, UINT64_C(1166810848989755013) } },
        { "EverMuted", { Event::MetricType::kLong, UINT64_C(9845797442415213087) } },
        { "TranscriptionLocale", { Event::MetricType::kInt, UINT64_C(5965042203756890174) } },
        { "TranscriptionLabelEnableState", { Event::MetricType::kInt, UINT64_C(9570428353886012461) } },
        { "SpeakerLabelEnableState", { Event::MetricType::kInt, UINT64_C(7185056042130600927) } },
        { "RecordingSaved", { Event::MetricType::kLong, UINT64_C(13336650162539611812) } },
        { "SpeakerCount", { Event::MetricType::kLong, UINT64_C(6133512048111385679) } },
        { "WordCount", { Event::MetricType::kLong, UINT64_C(11113615136000051604) } } };

    metrics_name_map_ = { { UINT64_C(16635485834660957432), "MicrophoneType" }, { UINT64_C(5806201864338858385), "IncludeSystemAudio" },
        { UINT64_C(5537392993791184098), "AudioDuration" }, { UINT64_C(5782425229489164648), "RecordDuration" },
        { UINT64_C(1166810848989755013), "EverPaused" }, { UINT64_C(9845797442415213087), "EverMuted" },
        { UINT64_C(5965042203756890174), "TranscriptionLocale" }, { UINT64_C(9570428353886012461), "TranscriptionLabelEnableState" },
        { UINT64_C(7185056042130600927), "SpeakerLabelEnableState" }, { UINT64_C(13336650162539611812), "RecordingSaved" },
        { UINT64_C(6133512048111385679), "SpeakerCount" }, { UINT64_C(11113615136000051604), "WordCount" } };
}

class CrOSEvents_RecorderApp_SuggestTitleEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_SuggestTitleEventValidator();
    ~CrOSEvents_RecorderApp_SuggestTitleEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(6589582711380377924);
};

CrOSEvents_RecorderApp_SuggestTitleEventValidator::CrOSEvents_RecorderApp_SuggestTitleEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_SuggestTitleEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_SuggestTitleEventValidator::~CrOSEvents_RecorderApp_SuggestTitleEventValidator() = default;

void CrOSEvents_RecorderApp_SuggestTitleEventValidator::Initialize()
{
    metric_metadata_ = { { "WordCount", { Event::MetricType::kLong, UINT64_C(11113615136000051604) } },
        { "ResultStatus", { Event::MetricType::kInt, UINT64_C(11472170562072191176) } },
        { "SuggestionAccepted", { Event::MetricType::kLong, UINT64_C(13386380613962213388) } },
        { "AcceptedSuggestionIndex", { Event::MetricType::kLong, UINT64_C(3630690086070433640) } } };

    metrics_name_map_ = { { UINT64_C(11113615136000051604), "WordCount" }, { UINT64_C(11472170562072191176), "ResultStatus" },
        { UINT64_C(13386380613962213388), "SuggestionAccepted" }, { UINT64_C(3630690086070433640), "AcceptedSuggestionIndex" } };
}

class CrOSEvents_RecorderApp_SummarizeEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_SummarizeEventValidator();
    ~CrOSEvents_RecorderApp_SummarizeEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(12387081154250538363);
};

CrOSEvents_RecorderApp_SummarizeEventValidator::CrOSEvents_RecorderApp_SummarizeEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_SummarizeEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_SummarizeEventValidator::~CrOSEvents_RecorderApp_SummarizeEventValidator() = default;

void CrOSEvents_RecorderApp_SummarizeEventValidator::Initialize()
{
    metric_metadata_ = { { "WordCount", { Event::MetricType::kLong, UINT64_C(11113615136000051604) } },
        { "ResultStatus", { Event::MetricType::kInt, UINT64_C(11472170562072191176) } } };

    metrics_name_map_ = { { UINT64_C(11113615136000051604), "WordCount" }, { UINT64_C(11472170562072191176), "ResultStatus" } };
}

class CrOSEvents_RecorderApp_FeedbackTitleSuggestionEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_FeedbackTitleSuggestionEventValidator();
    ~CrOSEvents_RecorderApp_FeedbackTitleSuggestionEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(11687446154149603047);
};

CrOSEvents_RecorderApp_FeedbackTitleSuggestionEventValidator::CrOSEvents_RecorderApp_FeedbackTitleSuggestionEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_FeedbackTitleSuggestionEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_FeedbackTitleSuggestionEventValidator::~CrOSEvents_RecorderApp_FeedbackTitleSuggestionEventValidator() = default;

void CrOSEvents_RecorderApp_FeedbackTitleSuggestionEventValidator::Initialize()
{
    metric_metadata_ = { { "Feedback", { Event::MetricType::kInt, UINT64_C(13737318931587321944) } } };

    metrics_name_map_ = { { UINT64_C(13737318931587321944), "Feedback" } };
}

class CrOSEvents_RecorderApp_FeedbackSummaryEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_FeedbackSummaryEventValidator();
    ~CrOSEvents_RecorderApp_FeedbackSummaryEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(4650126128948725327);
};

CrOSEvents_RecorderApp_FeedbackSummaryEventValidator::CrOSEvents_RecorderApp_FeedbackSummaryEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_FeedbackSummaryEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_FeedbackSummaryEventValidator::~CrOSEvents_RecorderApp_FeedbackSummaryEventValidator() = default;

void CrOSEvents_RecorderApp_FeedbackSummaryEventValidator::Initialize()
{
    metric_metadata_ = { { "Feedback", { Event::MetricType::kInt, UINT64_C(13737318931587321944) } } };

    metrics_name_map_ = { { UINT64_C(13737318931587321944), "Feedback" } };
}

class CrOSEvents_RecorderApp_OnboardEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_OnboardEventValidator();
    ~CrOSEvents_RecorderApp_OnboardEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(11142430298433716066);
};

CrOSEvents_RecorderApp_OnboardEventValidator::CrOSEvents_RecorderApp_OnboardEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_OnboardEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_OnboardEventValidator::~CrOSEvents_RecorderApp_OnboardEventValidator() = default;

void CrOSEvents_RecorderApp_OnboardEventValidator::Initialize()
{
    metric_metadata_ = { { "TranscriptionEnableState", { Event::MetricType::kInt, UINT64_C(11991758514740170116) } },
        { "SpeakerLabelEnableState", { Event::MetricType::kInt, UINT64_C(7185056042130600927) } } };

    metrics_name_map_ = { { UINT64_C(11991758514740170116), "TranscriptionEnableState" }, { UINT64_C(7185056042130600927), "SpeakerLabelEnableState" } };
}

class CrOSEvents_RecorderApp_ExportEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_ExportEventValidator();
    ~CrOSEvents_RecorderApp_ExportEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(7302397246000171114);
};

CrOSEvents_RecorderApp_ExportEventValidator::CrOSEvents_RecorderApp_ExportEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_ExportEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_ExportEventValidator::~CrOSEvents_RecorderApp_ExportEventValidator() = default;

void CrOSEvents_RecorderApp_ExportEventValidator::Initialize()
{
    metric_metadata_ = { { "AudioFormat", { Event::MetricType::kInt, UINT64_C(11525709879673230681) } },
        { "TranscriptFormat", { Event::MetricType::kInt, UINT64_C(3603822239288471539) } } };

    metrics_name_map_ = { { UINT64_C(11525709879673230681), "AudioFormat" }, { UINT64_C(3603822239288471539), "TranscriptFormat" } };
}

class CrOSEvents_RecorderApp_ChangePlaybackSpeedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_ChangePlaybackSpeedEventValidator();
    ~CrOSEvents_RecorderApp_ChangePlaybackSpeedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(6165782950648608956);
};

CrOSEvents_RecorderApp_ChangePlaybackSpeedEventValidator::CrOSEvents_RecorderApp_ChangePlaybackSpeedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_ChangePlaybackSpeedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_ChangePlaybackSpeedEventValidator::~CrOSEvents_RecorderApp_ChangePlaybackSpeedEventValidator() = default;

void CrOSEvents_RecorderApp_ChangePlaybackSpeedEventValidator::Initialize()
{
    metric_metadata_ = { { "PlaybackSpeed", { Event::MetricType::kDouble, UINT64_C(11167588223634711362) } } };

    metrics_name_map_ = { { UINT64_C(11167588223634711362), "PlaybackSpeed" } };
}

class CrOSEvents_RecorderApp_ChangePlaybackVolumeEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_ChangePlaybackVolumeEventValidator();
    ~CrOSEvents_RecorderApp_ChangePlaybackVolumeEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(7259950894653435603);
};

CrOSEvents_RecorderApp_ChangePlaybackVolumeEventValidator::CrOSEvents_RecorderApp_ChangePlaybackVolumeEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_ChangePlaybackVolumeEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_ChangePlaybackVolumeEventValidator::~CrOSEvents_RecorderApp_ChangePlaybackVolumeEventValidator() = default;

void CrOSEvents_RecorderApp_ChangePlaybackVolumeEventValidator::Initialize()
{
    metric_metadata_ = { { "Volume", { Event::MetricType::kLong, UINT64_C(13653391348900584924) } },
        { "Muted", { Event::MetricType::kLong, UINT64_C(8116925261070264013) } } };

    metrics_name_map_ = { { UINT64_C(13653391348900584924), "Volume" }, { UINT64_C(8116925261070264013), "Muted" } };
}

class CrOSEvents_RecorderApp_AppStartPerfEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_AppStartPerfEventValidator();
    ~CrOSEvents_RecorderApp_AppStartPerfEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(1929732514403632354);
};

CrOSEvents_RecorderApp_AppStartPerfEventValidator::CrOSEvents_RecorderApp_AppStartPerfEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_AppStartPerfEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_AppStartPerfEventValidator::~CrOSEvents_RecorderApp_AppStartPerfEventValidator() = default;

void CrOSEvents_RecorderApp_AppStartPerfEventValidator::Initialize()
{
    metric_metadata_ = { { "Duration", { Event::MetricType::kLong, UINT64_C(16153614581047612563) } } };

    metrics_name_map_ = { { UINT64_C(16153614581047612563), "Duration" } };
}

class CrOSEvents_RecorderApp_TranscriptionModelDownloadPerfEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_TranscriptionModelDownloadPerfEventValidator();
    ~CrOSEvents_RecorderApp_TranscriptionModelDownloadPerfEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(3331410798536455675);
};

CrOSEvents_RecorderApp_TranscriptionModelDownloadPerfEventValidator::CrOSEvents_RecorderApp_TranscriptionModelDownloadPerfEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_TranscriptionModelDownloadPerfEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_TranscriptionModelDownloadPerfEventValidator::~CrOSEvents_RecorderApp_TranscriptionModelDownloadPerfEventValidator() = default;

void CrOSEvents_RecorderApp_TranscriptionModelDownloadPerfEventValidator::Initialize()
{
    metric_metadata_ = { { "Duration", { Event::MetricType::kLong, UINT64_C(16153614581047612563) } } };

    metrics_name_map_ = { { UINT64_C(16153614581047612563), "Duration" } };
}

class CrOSEvents_RecorderApp_SummaryModelDownloadPerfEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_SummaryModelDownloadPerfEventValidator();
    ~CrOSEvents_RecorderApp_SummaryModelDownloadPerfEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(9067544395735895359);
};

CrOSEvents_RecorderApp_SummaryModelDownloadPerfEventValidator::CrOSEvents_RecorderApp_SummaryModelDownloadPerfEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_SummaryModelDownloadPerfEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_SummaryModelDownloadPerfEventValidator::~CrOSEvents_RecorderApp_SummaryModelDownloadPerfEventValidator() = default;

void CrOSEvents_RecorderApp_SummaryModelDownloadPerfEventValidator::Initialize()
{
    metric_metadata_ = { { "Duration", { Event::MetricType::kLong, UINT64_C(16153614581047612563) } } };

    metrics_name_map_ = { { UINT64_C(16153614581047612563), "Duration" } };
}

class CrOSEvents_RecorderApp_RecordingSavingPerfEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_RecordingSavingPerfEventValidator();
    ~CrOSEvents_RecorderApp_RecordingSavingPerfEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(12782201950398001108);
};

CrOSEvents_RecorderApp_RecordingSavingPerfEventValidator::CrOSEvents_RecorderApp_RecordingSavingPerfEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_RecordingSavingPerfEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_RecordingSavingPerfEventValidator::~CrOSEvents_RecorderApp_RecordingSavingPerfEventValidator() = default;

void CrOSEvents_RecorderApp_RecordingSavingPerfEventValidator::Initialize()
{
    metric_metadata_ = { { "Duration", { Event::MetricType::kLong, UINT64_C(16153614581047612563) } },
        { "AudioDuration", { Event::MetricType::kLong, UINT64_C(5537392993791184098) } },
        { "WordCount", { Event::MetricType::kLong, UINT64_C(11113615136000051604) } } };

    metrics_name_map_ = { { UINT64_C(16153614581047612563), "Duration" }, { UINT64_C(5537392993791184098), "AudioDuration" },
        { UINT64_C(11113615136000051604), "WordCount" } };
}

class CrOSEvents_RecorderApp_TitleSuggestionPerfEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_TitleSuggestionPerfEventValidator();
    ~CrOSEvents_RecorderApp_TitleSuggestionPerfEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(5966473471854842275);
};

CrOSEvents_RecorderApp_TitleSuggestionPerfEventValidator::CrOSEvents_RecorderApp_TitleSuggestionPerfEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_TitleSuggestionPerfEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_TitleSuggestionPerfEventValidator::~CrOSEvents_RecorderApp_TitleSuggestionPerfEventValidator() = default;

void CrOSEvents_RecorderApp_TitleSuggestionPerfEventValidator::Initialize()
{
    metric_metadata_ = { { "Duration", { Event::MetricType::kLong, UINT64_C(16153614581047612563) } },
        { "WordCount", { Event::MetricType::kLong, UINT64_C(11113615136000051604) } } };

    metrics_name_map_ = { { UINT64_C(16153614581047612563), "Duration" }, { UINT64_C(11113615136000051604), "WordCount" } };
}

class CrOSEvents_RecorderApp_SummaryPerfEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_SummaryPerfEventValidator();
    ~CrOSEvents_RecorderApp_SummaryPerfEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(165717034475136350);
};

CrOSEvents_RecorderApp_SummaryPerfEventValidator::CrOSEvents_RecorderApp_SummaryPerfEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_SummaryPerfEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_SummaryPerfEventValidator::~CrOSEvents_RecorderApp_SummaryPerfEventValidator() = default;

void CrOSEvents_RecorderApp_SummaryPerfEventValidator::Initialize()
{
    metric_metadata_ = { { "Duration", { Event::MetricType::kLong, UINT64_C(16153614581047612563) } },
        { "WordCount", { Event::MetricType::kLong, UINT64_C(11113615136000051604) } } };

    metrics_name_map_ = { { UINT64_C(16153614581047612563), "Duration" }, { UINT64_C(11113615136000051604), "WordCount" } };
}

class CrOSEvents_RecorderApp_ExportPerfEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_RecorderApp_ExportPerfEventValidator();
    ~CrOSEvents_RecorderApp_ExportPerfEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(4757515255007932385);
};

CrOSEvents_RecorderApp_ExportPerfEventValidator::CrOSEvents_RecorderApp_ExportPerfEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_RecorderApp_ExportPerfEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_RecorderApp_ExportPerfEventValidator::~CrOSEvents_RecorderApp_ExportPerfEventValidator() = default;

void CrOSEvents_RecorderApp_ExportPerfEventValidator::Initialize()
{
    metric_metadata_ = { { "Duration", { Event::MetricType::kLong, UINT64_C(16153614581047612563) } },
        { "RecordingSize", { Event::MetricType::kLong, UINT64_C(2049867094765889460) } } };

    metrics_name_map_ = { { UINT64_C(16153614581047612563), "Duration" }, { UINT64_C(2049867094765889460), "RecordingSize" } };
}

class CrOSEvents_UserLoginEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_UserLoginEventValidator();
    ~CrOSEvents_UserLoginEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(3946957472799472890);
};

CrOSEvents_UserLoginEventValidator::CrOSEvents_UserLoginEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_UserLoginEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_UserLoginEventValidator::~CrOSEvents_UserLoginEventValidator() = default;

void CrOSEvents_UserLoginEventValidator::Initialize()
{
    metric_metadata_ = {

    };

    metrics_name_map_ = {

    };
}

class CrOSEvents_UserLogoutEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_UserLogoutEventValidator();
    ~CrOSEvents_UserLogoutEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(15162740773924916380);
};

CrOSEvents_UserLogoutEventValidator::CrOSEvents_UserLogoutEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_UserLogoutEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_UserLogoutEventValidator::~CrOSEvents_UserLogoutEventValidator() = default;

void CrOSEvents_UserLogoutEventValidator::Initialize()
{
    metric_metadata_ = {

    };

    metrics_name_map_ = {

    };
}

class CrOSEvents_SystemSuspendedEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_SystemSuspendedEventValidator();
    ~CrOSEvents_SystemSuspendedEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(9156818098953353395);
};

CrOSEvents_SystemSuspendedEventValidator::CrOSEvents_SystemSuspendedEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_SystemSuspendedEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_SystemSuspendedEventValidator::~CrOSEvents_SystemSuspendedEventValidator() = default;

void CrOSEvents_SystemSuspendedEventValidator::Initialize()
{
    metric_metadata_ = { { "Reason", { Event::MetricType::kLong, UINT64_C(18445816987321669298) } } };

    metrics_name_map_ = { { UINT64_C(18445816987321669298), "Reason" } };
}

class CrOSEvents_Test1EventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_Test1EventValidator();
    ~CrOSEvents_Test1EventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(5509740142892158459);
};

CrOSEvents_Test1EventValidator::CrOSEvents_Test1EventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_Test1EventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_Test1EventValidator::~CrOSEvents_Test1EventValidator() = default;

void CrOSEvents_Test1EventValidator::Initialize()
{
    metric_metadata_ = { { "Metric1", { Event::MetricType::kDouble, UINT64_C(8511085042759365099) } } };

    metrics_name_map_ = { { UINT64_C(8511085042759365099), "Metric1" } };
}

class CrOSEvents_NoMetricsEventEventValidator final : public ::metrics::structured::EventValidator {
public:
    CrOSEvents_NoMetricsEventEventValidator();
    ~CrOSEvents_NoMetricsEventEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(5106854608989380457);
};

CrOSEvents_NoMetricsEventEventValidator::CrOSEvents_NoMetricsEventEventValidator()
    : ::metrics::structured::EventValidator(CrOSEvents_NoMetricsEventEventValidator::kEventNameHash, false)
{
    Initialize();
}

CrOSEvents_NoMetricsEventEventValidator::~CrOSEvents_NoMetricsEventEventValidator() = default;

void CrOSEvents_NoMetricsEventEventValidator::Initialize()
{
    metric_metadata_ = {

    };

    metrics_name_map_ = {

    };
}
class DevTools_SessionStartEventValidator final : public ::metrics::structured::EventValidator {
public:
    DevTools_SessionStartEventValidator();
    ~DevTools_SessionStartEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(13744243518034680300);
};

DevTools_SessionStartEventValidator::DevTools_SessionStartEventValidator()
    : ::metrics::structured::EventValidator(DevTools_SessionStartEventValidator::kEventNameHash, false)
{
    Initialize();
}

DevTools_SessionStartEventValidator::~DevTools_SessionStartEventValidator() = default;

void DevTools_SessionStartEventValidator::Initialize()
{
    metric_metadata_ = { { "Trigger", { Event::MetricType::kLong, UINT64_C(17769223356561141745) } },
        { "DockSide", { Event::MetricType::kLong, UINT64_C(11856538614544483686) } },
        { "SessionId", { Event::MetricType::kLong, UINT64_C(4297293875635157131) } },
        { "IsSignedIn", { Event::MetricType::kLong, UINT64_C(11300401373250147556) } } };

    metrics_name_map_ = { { UINT64_C(17769223356561141745), "Trigger" }, { UINT64_C(11856538614544483686), "DockSide" },
        { UINT64_C(4297293875635157131), "SessionId" }, { UINT64_C(11300401373250147556), "IsSignedIn" } };
}

class DevTools_SessionEndEventValidator final : public ::metrics::structured::EventValidator {
public:
    DevTools_SessionEndEventValidator();
    ~DevTools_SessionEndEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(3262187048172162891);
};

DevTools_SessionEndEventValidator::DevTools_SessionEndEventValidator()
    : ::metrics::structured::EventValidator(DevTools_SessionEndEventValidator::kEventNameHash, false)
{
    Initialize();
}

DevTools_SessionEndEventValidator::~DevTools_SessionEndEventValidator() = default;

void DevTools_SessionEndEventValidator::Initialize()
{
    metric_metadata_ = { { "Trigger", { Event::MetricType::kLong, UINT64_C(17769223356561141745) } },
        { "TimeSinceSessionStart", { Event::MetricType::kLong, UINT64_C(16337824081306684483) } },
        { "SessionId", { Event::MetricType::kLong, UINT64_C(4297293875635157131) } } };

    metrics_name_map_ = { { UINT64_C(17769223356561141745), "Trigger" }, { UINT64_C(16337824081306684483), "TimeSinceSessionStart" },
        { UINT64_C(4297293875635157131), "SessionId" } };
}

class DevTools_ImpressionEventValidator final : public ::metrics::structured::EventValidator {
public:
    DevTools_ImpressionEventValidator();
    ~DevTools_ImpressionEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(4398047322841981703);
};

DevTools_ImpressionEventValidator::DevTools_ImpressionEventValidator()
    : ::metrics::structured::EventValidator(DevTools_ImpressionEventValidator::kEventNameHash, false)
{
    Initialize();
}

DevTools_ImpressionEventValidator::~DevTools_ImpressionEventValidator() = default;

void DevTools_ImpressionEventValidator::Initialize()
{
    metric_metadata_ = { { "VeId", { Event::MetricType::kLong, UINT64_C(15328103879772752934) } },
        { "VeType", { Event::MetricType::kLong, UINT64_C(15167065131200700515) } },
        { "VeParent", { Event::MetricType::kLong, UINT64_C(16136417644891610031) } },
        { "VeContext", { Event::MetricType::kLong, UINT64_C(15142575525071682906) } },
        { "TimeSinceSessionStart", { Event::MetricType::kLong, UINT64_C(16337824081306684483) } },
        { "SessionId", { Event::MetricType::kLong, UINT64_C(4297293875635157131) } }, { "Width", { Event::MetricType::kLong, UINT64_C(3644896802912593514) } },
        { "Height", { Event::MetricType::kLong, UINT64_C(17205655745617698527) } } };

    metrics_name_map_
        = { { UINT64_C(15328103879772752934), "VeId" }, { UINT64_C(15167065131200700515), "VeType" }, { UINT64_C(16136417644891610031), "VeParent" },
              { UINT64_C(15142575525071682906), "VeContext" }, { UINT64_C(16337824081306684483), "TimeSinceSessionStart" },
              { UINT64_C(4297293875635157131), "SessionId" }, { UINT64_C(3644896802912593514), "Width" }, { UINT64_C(17205655745617698527), "Height" } };
}

class DevTools_ResizeEventValidator final : public ::metrics::structured::EventValidator {
public:
    DevTools_ResizeEventValidator();
    ~DevTools_ResizeEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(15727676286859240);
};

DevTools_ResizeEventValidator::DevTools_ResizeEventValidator()
    : ::metrics::structured::EventValidator(DevTools_ResizeEventValidator::kEventNameHash, false)
{
    Initialize();
}

DevTools_ResizeEventValidator::~DevTools_ResizeEventValidator() = default;

void DevTools_ResizeEventValidator::Initialize()
{
    metric_metadata_ = { { "VeId", { Event::MetricType::kLong, UINT64_C(15328103879772752934) } },
        { "TimeSinceSessionStart", { Event::MetricType::kLong, UINT64_C(16337824081306684483) } },
        { "SessionId", { Event::MetricType::kLong, UINT64_C(4297293875635157131) } }, { "Width", { Event::MetricType::kLong, UINT64_C(3644896802912593514) } },
        { "Height", { Event::MetricType::kLong, UINT64_C(17205655745617698527) } } };

    metrics_name_map_ = { { UINT64_C(15328103879772752934), "VeId" }, { UINT64_C(16337824081306684483), "TimeSinceSessionStart" },
        { UINT64_C(4297293875635157131), "SessionId" }, { UINT64_C(3644896802912593514), "Width" }, { UINT64_C(17205655745617698527), "Height" } };
}

class DevTools_ClickEventValidator final : public ::metrics::structured::EventValidator {
public:
    DevTools_ClickEventValidator();
    ~DevTools_ClickEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(5980286229304309245);
};

DevTools_ClickEventValidator::DevTools_ClickEventValidator()
    : ::metrics::structured::EventValidator(DevTools_ClickEventValidator::kEventNameHash, false)
{
    Initialize();
}

DevTools_ClickEventValidator::~DevTools_ClickEventValidator() = default;

void DevTools_ClickEventValidator::Initialize()
{
    metric_metadata_ = { { "VeId", { Event::MetricType::kLong, UINT64_C(15328103879772752934) } },
        { "MouseButton", { Event::MetricType::kLong, UINT64_C(5321775134026642721) } },
        { "DoubleClick", { Event::MetricType::kLong, UINT64_C(11093651096396196453) } },
        { "Context", { Event::MetricType::kLong, UINT64_C(12487954430760699291) } },
        { "TimeSinceSessionStart", { Event::MetricType::kLong, UINT64_C(16337824081306684483) } },
        { "SessionId", { Event::MetricType::kLong, UINT64_C(4297293875635157131) } } };

    metrics_name_map_ = { { UINT64_C(15328103879772752934), "VeId" }, { UINT64_C(5321775134026642721), "MouseButton" },
        { UINT64_C(11093651096396196453), "DoubleClick" }, { UINT64_C(12487954430760699291), "Context" },
        { UINT64_C(16337824081306684483), "TimeSinceSessionStart" }, { UINT64_C(4297293875635157131), "SessionId" } };
}

class DevTools_HoverEventValidator final : public ::metrics::structured::EventValidator {
public:
    DevTools_HoverEventValidator();
    ~DevTools_HoverEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(4890306395588587268);
};

DevTools_HoverEventValidator::DevTools_HoverEventValidator()
    : ::metrics::structured::EventValidator(DevTools_HoverEventValidator::kEventNameHash, false)
{
    Initialize();
}

DevTools_HoverEventValidator::~DevTools_HoverEventValidator() = default;

void DevTools_HoverEventValidator::Initialize()
{
    metric_metadata_ = { { "VeId", { Event::MetricType::kLong, UINT64_C(15328103879772752934) } },
        { "Time", { Event::MetricType::kLong, UINT64_C(12064385795062408818) } }, { "Context", { Event::MetricType::kLong, UINT64_C(12487954430760699291) } },
        { "TimeSinceSessionStart", { Event::MetricType::kLong, UINT64_C(16337824081306684483) } },
        { "SessionId", { Event::MetricType::kLong, UINT64_C(4297293875635157131) } } };

    metrics_name_map_ = { { UINT64_C(15328103879772752934), "VeId" }, { UINT64_C(12064385795062408818), "Time" }, { UINT64_C(12487954430760699291), "Context" },
        { UINT64_C(16337824081306684483), "TimeSinceSessionStart" }, { UINT64_C(4297293875635157131), "SessionId" } };
}

class DevTools_DragEventValidator final : public ::metrics::structured::EventValidator {
public:
    DevTools_DragEventValidator();
    ~DevTools_DragEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(17504965937910711994);
};

DevTools_DragEventValidator::DevTools_DragEventValidator()
    : ::metrics::structured::EventValidator(DevTools_DragEventValidator::kEventNameHash, false)
{
    Initialize();
}

DevTools_DragEventValidator::~DevTools_DragEventValidator() = default;

void DevTools_DragEventValidator::Initialize()
{
    metric_metadata_ = { { "VeId", { Event::MetricType::kLong, UINT64_C(15328103879772752934) } },
        { "Distance", { Event::MetricType::kLong, UINT64_C(767569209284850633) } }, { "Context", { Event::MetricType::kLong, UINT64_C(12487954430760699291) } },
        { "TimeSinceSessionStart", { Event::MetricType::kLong, UINT64_C(16337824081306684483) } },
        { "SessionId", { Event::MetricType::kLong, UINT64_C(4297293875635157131) } } };

    metrics_name_map_
        = { { UINT64_C(15328103879772752934), "VeId" }, { UINT64_C(767569209284850633), "Distance" }, { UINT64_C(12487954430760699291), "Context" },
              { UINT64_C(16337824081306684483), "TimeSinceSessionStart" }, { UINT64_C(4297293875635157131), "SessionId" } };
}

class DevTools_ChangeEventValidator final : public ::metrics::structured::EventValidator {
public:
    DevTools_ChangeEventValidator();
    ~DevTools_ChangeEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(11431363328394973259);
};

DevTools_ChangeEventValidator::DevTools_ChangeEventValidator()
    : ::metrics::structured::EventValidator(DevTools_ChangeEventValidator::kEventNameHash, false)
{
    Initialize();
}

DevTools_ChangeEventValidator::~DevTools_ChangeEventValidator() = default;

void DevTools_ChangeEventValidator::Initialize()
{
    metric_metadata_ = { { "VeId", { Event::MetricType::kLong, UINT64_C(15328103879772752934) } },
        { "Context", { Event::MetricType::kLong, UINT64_C(12487954430760699291) } },
        { "TimeSinceSessionStart", { Event::MetricType::kLong, UINT64_C(16337824081306684483) } },
        { "SessionId", { Event::MetricType::kLong, UINT64_C(4297293875635157131) } } };

    metrics_name_map_ = { { UINT64_C(15328103879772752934), "VeId" }, { UINT64_C(12487954430760699291), "Context" },
        { UINT64_C(16337824081306684483), "TimeSinceSessionStart" }, { UINT64_C(4297293875635157131), "SessionId" } };
}

class DevTools_KeyDownEventValidator final : public ::metrics::structured::EventValidator {
public:
    DevTools_KeyDownEventValidator();
    ~DevTools_KeyDownEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(1502882311982410087);
};

DevTools_KeyDownEventValidator::DevTools_KeyDownEventValidator()
    : ::metrics::structured::EventValidator(DevTools_KeyDownEventValidator::kEventNameHash, false)
{
    Initialize();
}

DevTools_KeyDownEventValidator::~DevTools_KeyDownEventValidator() = default;

void DevTools_KeyDownEventValidator::Initialize()
{
    metric_metadata_ = { { "VeId", { Event::MetricType::kLong, UINT64_C(15328103879772752934) } },
        { "Context", { Event::MetricType::kLong, UINT64_C(12487954430760699291) } },
        { "TimeSinceSessionStart", { Event::MetricType::kLong, UINT64_C(16337824081306684483) } },
        { "SessionId", { Event::MetricType::kLong, UINT64_C(4297293875635157131) } } };

    metrics_name_map_ = { { UINT64_C(15328103879772752934), "VeId" }, { UINT64_C(12487954430760699291), "Context" },
        { UINT64_C(16337824081306684483), "TimeSinceSessionStart" }, { UINT64_C(4297293875635157131), "SessionId" } };
}
class TestProjectOne_TestEventOneEventValidator final : public ::metrics::structured::EventValidator {
public:
    TestProjectOne_TestEventOneEventValidator();
    ~TestProjectOne_TestEventOneEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(13593049295042080097);
};

TestProjectOne_TestEventOneEventValidator::TestProjectOne_TestEventOneEventValidator()
    : ::metrics::structured::EventValidator(TestProjectOne_TestEventOneEventValidator::kEventNameHash, false)
{
    Initialize();
}

TestProjectOne_TestEventOneEventValidator::~TestProjectOne_TestEventOneEventValidator() = default;

void TestProjectOne_TestEventOneEventValidator::Initialize()
{
    metric_metadata_ = { { "TestMetricOne", { Event::MetricType::kHmac, UINT64_C(637929385654885975) } },
        { "TestMetricTwo", { Event::MetricType::kLong, UINT64_C(14083999144141567134) } } };

    metrics_name_map_ = { { UINT64_C(637929385654885975), "TestMetricOne" }, { UINT64_C(14083999144141567134), "TestMetricTwo" } };
}
class TestProjectTwo_TestEventThreeEventValidator final : public ::metrics::structured::EventValidator {
public:
    TestProjectTwo_TestEventThreeEventValidator();
    ~TestProjectTwo_TestEventThreeEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(5848687377041124372);
};

TestProjectTwo_TestEventThreeEventValidator::TestProjectTwo_TestEventThreeEventValidator()
    : ::metrics::structured::EventValidator(TestProjectTwo_TestEventThreeEventValidator::kEventNameHash, false)
{
    Initialize();
}

TestProjectTwo_TestEventThreeEventValidator::~TestProjectTwo_TestEventThreeEventValidator() = default;

void TestProjectTwo_TestEventThreeEventValidator::Initialize()
{
    metric_metadata_ = { { "TestMetricFour", { Event::MetricType::kHmac, UINT64_C(2917855408523247722) } } };

    metrics_name_map_ = { { UINT64_C(2917855408523247722), "TestMetricFour" } };
}

class TestProjectTwo_TestEventTwoEventValidator final : public ::metrics::structured::EventValidator {
public:
    TestProjectTwo_TestEventTwoEventValidator();
    ~TestProjectTwo_TestEventTwoEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(8995967733561999410);
};

TestProjectTwo_TestEventTwoEventValidator::TestProjectTwo_TestEventTwoEventValidator()
    : ::metrics::structured::EventValidator(TestProjectTwo_TestEventTwoEventValidator::kEventNameHash, false)
{
    Initialize();
}

TestProjectTwo_TestEventTwoEventValidator::~TestProjectTwo_TestEventTwoEventValidator() = default;

void TestProjectTwo_TestEventTwoEventValidator::Initialize()
{
    metric_metadata_ = { { "TestMetricThree", { Event::MetricType::kHmac, UINT64_C(13469300759843809564) } } };

    metrics_name_map_ = { { UINT64_C(13469300759843809564), "TestMetricThree" } };
}
class TestProjectThree_TestEventFourEventValidator final : public ::metrics::structured::EventValidator {
public:
    TestProjectThree_TestEventFourEventValidator();
    ~TestProjectThree_TestEventFourEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(1718797808092246258);
};

TestProjectThree_TestEventFourEventValidator::TestProjectThree_TestEventFourEventValidator()
    : ::metrics::structured::EventValidator(TestProjectThree_TestEventFourEventValidator::kEventNameHash, false)
{
    Initialize();
}

TestProjectThree_TestEventFourEventValidator::~TestProjectThree_TestEventFourEventValidator() = default;

void TestProjectThree_TestEventFourEventValidator::Initialize()
{
    metric_metadata_ = { { "TestMetricFour", { Event::MetricType::kLong, UINT64_C(2917855408523247722) } } };

    metrics_name_map_ = { { UINT64_C(2917855408523247722), "TestMetricFour" } };
}
class TestProjectFour_TestEventFiveEventValidator final : public ::metrics::structured::EventValidator {
public:
    TestProjectFour_TestEventFiveEventValidator();
    ~TestProjectFour_TestEventFiveEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(7045523601811399253);
};

TestProjectFour_TestEventFiveEventValidator::TestProjectFour_TestEventFiveEventValidator()
    : ::metrics::structured::EventValidator(TestProjectFour_TestEventFiveEventValidator::kEventNameHash, false)
{
    Initialize();
}

TestProjectFour_TestEventFiveEventValidator::~TestProjectFour_TestEventFiveEventValidator() = default;

void TestProjectFour_TestEventFiveEventValidator::Initialize()
{
    metric_metadata_ = { { "TestMetricFive", { Event::MetricType::kHmac, UINT64_C(8665976921794972190) } } };

    metrics_name_map_ = { { UINT64_C(8665976921794972190), "TestMetricFive" } };
}
class TestProjectFive_TestEventSixEventValidator final : public ::metrics::structured::EventValidator {
public:
    TestProjectFive_TestEventSixEventValidator();
    ~TestProjectFive_TestEventSixEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(2873337042686447043);
};

TestProjectFive_TestEventSixEventValidator::TestProjectFive_TestEventSixEventValidator()
    : ::metrics::structured::EventValidator(TestProjectFive_TestEventSixEventValidator::kEventNameHash, false)
{
    Initialize();
}

TestProjectFive_TestEventSixEventValidator::~TestProjectFive_TestEventSixEventValidator() = default;

void TestProjectFive_TestEventSixEventValidator::Initialize()
{
    metric_metadata_ = { { "TestMetricSix", { Event::MetricType::kRawString, UINT64_C(3431522567539822144) } } };

    metrics_name_map_ = { { UINT64_C(3431522567539822144), "TestMetricSix" } };
}
class TestProjectSix_TestEventSevenEventValidator final : public ::metrics::structured::EventValidator {
public:
    TestProjectSix_TestEventSevenEventValidator();
    ~TestProjectSix_TestEventSevenEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(16749091071228286247);
};

TestProjectSix_TestEventSevenEventValidator::TestProjectSix_TestEventSevenEventValidator()
    : ::metrics::structured::EventValidator(TestProjectSix_TestEventSevenEventValidator::kEventNameHash, false)
{
    Initialize();
}

TestProjectSix_TestEventSevenEventValidator::~TestProjectSix_TestEventSevenEventValidator() = default;

void TestProjectSix_TestEventSevenEventValidator::Initialize()
{
    metric_metadata_ = { { "TestMetricSeven", { Event::MetricType::kDouble, UINT64_C(8395865158198697574) } } };

    metrics_name_map_ = { { UINT64_C(8395865158198697574), "TestMetricSeven" } };
}

class TestProjectSix_TestEnumEventValidator final : public ::metrics::structured::EventValidator {
public:
    TestProjectSix_TestEnumEventValidator();
    ~TestProjectSix_TestEnumEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(14837072141472316574);
};

TestProjectSix_TestEnumEventValidator::TestProjectSix_TestEnumEventValidator()
    : ::metrics::structured::EventValidator(TestProjectSix_TestEnumEventValidator::kEventNameHash, false)
{
    Initialize();
}

TestProjectSix_TestEnumEventValidator::~TestProjectSix_TestEnumEventValidator() = default;

void TestProjectSix_TestEnumEventValidator::Initialize()
{
    metric_metadata_ = { { "TestEnumMetric", { Event::MetricType::kInt, UINT64_C(16584986597633634829) } } };

    metrics_name_map_ = { { UINT64_C(16584986597633634829), "TestEnumMetric" } };
}
class TestProjectSeven_TestEventEightEventValidator final : public ::metrics::structured::EventValidator {
public:
    TestProjectSeven_TestEventEightEventValidator();
    ~TestProjectSeven_TestEventEightEventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(16290206418240617738);
};

TestProjectSeven_TestEventEightEventValidator::TestProjectSeven_TestEventEightEventValidator()
    : ::metrics::structured::EventValidator(TestProjectSeven_TestEventEightEventValidator::kEventNameHash, true)
{
    Initialize();
}

TestProjectSeven_TestEventEightEventValidator::~TestProjectSeven_TestEventEightEventValidator() = default;

void TestProjectSeven_TestEventEightEventValidator::Initialize()
{
    metric_metadata_ = { { "TestMetricEight", { Event::MetricType::kDouble, UINT64_C(6311095899609065709) } } };

    metrics_name_map_ = { { UINT64_C(6311095899609065709), "TestMetricEight" } };
}
class SequencedTestProject_Test1EventValidator final : public ::metrics::structured::EventValidator {
public:
    SequencedTestProject_Test1EventValidator();
    ~SequencedTestProject_Test1EventValidator();

    void Initialize();

    static constexpr uint64_t kEventNameHash = UINT64_C(2284817119476109309);
};

SequencedTestProject_Test1EventValidator::SequencedTestProject_Test1EventValidator()
    : ::metrics::structured::EventValidator(SequencedTestProject_Test1EventValidator::kEventNameHash, false)
{
    Initialize();
}

SequencedTestProject_Test1EventValidator::~SequencedTestProject_Test1EventValidator() = default;

void SequencedTestProject_Test1EventValidator::Initialize()
{
    metric_metadata_ = { { "Metric1", { Event::MetricType::kDouble, UINT64_C(8511085042759365099) } } };

    metrics_name_map_ = { { UINT64_C(8511085042759365099), "Metric1" } };
}

//---------------------ProjectValidator Classes---------------------------------
class PopularDisplaysProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    PopularDisplaysProjectValidator();
    ~PopularDisplaysProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(13666187132464558198);
    static constexpr IdType kIdType = IdType::kUnidentified;
    static constexpr IdScope kIdScope = IdScope::kPerDevice;
    static constexpr EventType kEventType = StructuredEventProto_EventType_RAW_STRING;
    static constexpr int kKeyRotationPeriod = 90;
};

PopularDisplaysProjectValidator::PopularDisplaysProjectValidator()
    : ::metrics::structured::ProjectValidator(PopularDisplaysProjectValidator::kProjectNameHash, PopularDisplaysProjectValidator::kIdType,
        PopularDisplaysProjectValidator::kIdScope, PopularDisplaysProjectValidator::kEventType, PopularDisplaysProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void PopularDisplaysProjectValidator::Initialize()
{
    event_validators_.emplace("MonitorInfo", std::make_unique<PopularDisplays_MonitorInfoEventValidator>());

    event_name_map_.emplace(UINT64_C(2134486541903110786), "MonitorInfo");
}

PopularDisplaysProjectValidator::~PopularDisplaysProjectValidator() = default;

class FastPairProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    FastPairProjectValidator();
    ~FastPairProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(4257181691211608017);
    static constexpr IdType kIdType = IdType::kUnidentified;
    static constexpr IdScope kIdScope = IdScope::kPerProfile;
    static constexpr EventType kEventType = StructuredEventProto_EventType_REGULAR;
    static constexpr int kKeyRotationPeriod = 30;
};

FastPairProjectValidator::FastPairProjectValidator()
    : ::metrics::structured::ProjectValidator(FastPairProjectValidator::kProjectNameHash, FastPairProjectValidator::kIdType, FastPairProjectValidator::kIdScope,
        FastPairProjectValidator::kEventType, FastPairProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void FastPairProjectValidator::Initialize()
{
    event_validators_.emplace("DiscoveryNotificationShown", std::make_unique<FastPair_DiscoveryNotificationShownEventValidator>());
    event_validators_.emplace("PairingStart", std::make_unique<FastPair_PairingStartEventValidator>());
    event_validators_.emplace("PairingComplete", std::make_unique<FastPair_PairingCompleteEventValidator>());
    event_validators_.emplace("PairFailure", std::make_unique<FastPair_PairFailureEventValidator>());

    event_name_map_.emplace(UINT64_C(9794167847225427927), "DiscoveryNotificationShown");
    event_name_map_.emplace(UINT64_C(2342185101128577068), "PairingStart");
    event_name_map_.emplace(UINT64_C(7548910873986616453), "PairingComplete");
    event_name_map_.emplace(UINT64_C(17174637411246838540), "PairFailure");
}

FastPairProjectValidator::~FastPairProjectValidator() = default;

class HindsightProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    HindsightProjectValidator();
    ~HindsightProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(16658867201751992801);
    static constexpr IdType kIdType = IdType::kProjectId;
    static constexpr IdScope kIdScope = IdScope::kPerProfile;
    static constexpr EventType kEventType = StructuredEventProto_EventType_REGULAR;
    static constexpr int kKeyRotationPeriod = 90;
};

HindsightProjectValidator::HindsightProjectValidator()
    : ::metrics::structured::ProjectValidator(HindsightProjectValidator::kProjectNameHash, HindsightProjectValidator::kIdType,
        HindsightProjectValidator::kIdScope, HindsightProjectValidator::kEventType, HindsightProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void HindsightProjectValidator::Initialize()
{
    event_validators_.emplace("CrOSActionEvent_FileOpened", std::make_unique<Hindsight_CrOSActionEvent_FileOpenedEventValidator>());
    event_validators_.emplace("CrOSActionEvent_SearchResultLaunched", std::make_unique<Hindsight_CrOSActionEvent_SearchResultLaunchedEventValidator>());
    event_validators_.emplace("CrOSActionEvent_SettingChanged", std::make_unique<Hindsight_CrOSActionEvent_SettingChangedEventValidator>());
    event_validators_.emplace("CrOSActionEvent_TabEvent_TabNavigated", std::make_unique<Hindsight_CrOSActionEvent_TabEvent_TabNavigatedEventValidator>());
    event_validators_.emplace("CrOSActionEvent_TabEvent_TabOpened", std::make_unique<Hindsight_CrOSActionEvent_TabEvent_TabOpenedEventValidator>());
    event_validators_.emplace("CrOSActionEvent_TabEvent_TabReactivated", std::make_unique<Hindsight_CrOSActionEvent_TabEvent_TabReactivatedEventValidator>());

    event_name_map_.emplace(UINT64_C(6176288366907657397), "CrOSActionEvent_FileOpened");
    event_name_map_.emplace(UINT64_C(7258544623737125992), "CrOSActionEvent_SearchResultLaunched");
    event_name_map_.emplace(UINT64_C(15173432087155953262), "CrOSActionEvent_SettingChanged");
    event_name_map_.emplace(UINT64_C(11495565264134779777), "CrOSActionEvent_TabEvent_TabNavigated");
    event_name_map_.emplace(UINT64_C(13824184328368382026), "CrOSActionEvent_TabEvent_TabOpened");
    event_name_map_.emplace(UINT64_C(1414982393805218127), "CrOSActionEvent_TabEvent_TabReactivated");
}

HindsightProjectValidator::~HindsightProjectValidator() = default;

class LauncherUsageProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    LauncherUsageProjectValidator();
    ~LauncherUsageProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(10270819838268357145);
    static constexpr IdType kIdType = IdType::kProjectId;
    static constexpr IdScope kIdScope = IdScope::kPerProfile;
    static constexpr EventType kEventType = StructuredEventProto_EventType_REGULAR;
    static constexpr int kKeyRotationPeriod = 90;
};

LauncherUsageProjectValidator::LauncherUsageProjectValidator()
    : ::metrics::structured::ProjectValidator(LauncherUsageProjectValidator::kProjectNameHash, LauncherUsageProjectValidator::kIdType,
        LauncherUsageProjectValidator::kIdScope, LauncherUsageProjectValidator::kEventType, LauncherUsageProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void LauncherUsageProjectValidator::Initialize()
{
    event_validators_.emplace("LauncherUsage", std::make_unique<LauncherUsage_LauncherUsageEventValidator>());

    event_name_map_.emplace(UINT64_C(338987758122020898), "LauncherUsage");
}

LauncherUsageProjectValidator::~LauncherUsageProjectValidator() = default;

class NearbyShareProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    NearbyShareProjectValidator();
    ~NearbyShareProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(16660214177681096661);
    static constexpr IdType kIdType = IdType::kUnidentified;
    static constexpr IdScope kIdScope = IdScope::kPerProfile;
    static constexpr EventType kEventType = StructuredEventProto_EventType_REGULAR;
    static constexpr int kKeyRotationPeriod = 30;
};

NearbyShareProjectValidator::NearbyShareProjectValidator()
    : ::metrics::structured::ProjectValidator(NearbyShareProjectValidator::kProjectNameHash, NearbyShareProjectValidator::kIdType,
        NearbyShareProjectValidator::kIdScope, NearbyShareProjectValidator::kEventType, NearbyShareProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void NearbyShareProjectValidator::Initialize()
{
    event_validators_.emplace("Discovery", std::make_unique<NearbyShare_DiscoveryEventValidator>());
    event_validators_.emplace("Throughput", std::make_unique<NearbyShare_ThroughputEventValidator>());
    event_validators_.emplace("FileAttachment", std::make_unique<NearbyShare_FileAttachmentEventValidator>());
    event_validators_.emplace("TextAttachment", std::make_unique<NearbyShare_TextAttachmentEventValidator>());
    event_validators_.emplace("ShareSession", std::make_unique<NearbyShare_ShareSessionEventValidator>());

    event_name_map_.emplace(UINT64_C(8121790022846552438), "Discovery");
    event_name_map_.emplace(UINT64_C(12486561721064188940), "Throughput");
    event_name_map_.emplace(UINT64_C(16611026906961162750), "FileAttachment");
    event_name_map_.emplace(UINT64_C(6709412692638581792), "TextAttachment");
    event_name_map_.emplace(UINT64_C(3465270551632052329), "ShareSession");
}

NearbyShareProjectValidator::~NearbyShareProjectValidator() = default;

class PhoneHubProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    PhoneHubProjectValidator();
    ~PhoneHubProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(7404894664453311568);
    static constexpr IdType kIdType = IdType::kUnidentified;
    static constexpr IdScope kIdScope = IdScope::kPerProfile;
    static constexpr EventType kEventType = StructuredEventProto_EventType_RAW_STRING;
    static constexpr int kKeyRotationPeriod = 90;
};

PhoneHubProjectValidator::PhoneHubProjectValidator()
    : ::metrics::structured::ProjectValidator(PhoneHubProjectValidator::kProjectNameHash, PhoneHubProjectValidator::kIdType, PhoneHubProjectValidator::kIdScope,
        PhoneHubProjectValidator::kEventType, PhoneHubProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void PhoneHubProjectValidator::Initialize()
{
    event_validators_.emplace("SessionDetails", std::make_unique<PhoneHub_SessionDetailsEventValidator>());
    event_validators_.emplace("DiscoveryStarted", std::make_unique<PhoneHub_DiscoveryStartedEventValidator>());
    event_validators_.emplace("DiscoveryFinished", std::make_unique<PhoneHub_DiscoveryFinishedEventValidator>());
    event_validators_.emplace("NearbyConnection", std::make_unique<PhoneHub_NearbyConnectionEventValidator>());
    event_validators_.emplace("SecureChannelAuthentication", std::make_unique<PhoneHub_SecureChannelAuthenticationEventValidator>());
    event_validators_.emplace("PhoneHubMessage", std::make_unique<PhoneHub_PhoneHubMessageEventValidator>());
    event_validators_.emplace("PhoneHubUiUpdate", std::make_unique<PhoneHub_PhoneHubUiUpdateEventValidator>());

    event_name_map_.emplace(UINT64_C(14629822153912792501), "SessionDetails");
    event_name_map_.emplace(UINT64_C(7992577258084539318), "DiscoveryStarted");
    event_name_map_.emplace(UINT64_C(16302049427530543562), "DiscoveryFinished");
    event_name_map_.emplace(UINT64_C(13864616483619165279), "NearbyConnection");
    event_name_map_.emplace(UINT64_C(7469924009091573938), "SecureChannelAuthentication");
    event_name_map_.emplace(UINT64_C(10478645582908403406), "PhoneHubMessage");
    event_name_map_.emplace(UINT64_C(17145414062248710895), "PhoneHubUiUpdate");
}

PhoneHubProjectValidator::~PhoneHubProjectValidator() = default;

class StructuredMetricsProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    StructuredMetricsProjectValidator();
    ~StructuredMetricsProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(12908457551569912491);
    static constexpr IdType kIdType = IdType::kProjectId;
    static constexpr IdScope kIdScope = IdScope::kPerDevice;
    static constexpr EventType kEventType = StructuredEventProto_EventType_REGULAR;
    static constexpr int kKeyRotationPeriod = 90;
};

StructuredMetricsProjectValidator::StructuredMetricsProjectValidator()
    : ::metrics::structured::ProjectValidator(StructuredMetricsProjectValidator::kProjectNameHash, StructuredMetricsProjectValidator::kIdType,
        StructuredMetricsProjectValidator::kIdScope, StructuredMetricsProjectValidator::kEventType, StructuredMetricsProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void StructuredMetricsProjectValidator::Initialize()
{
    event_validators_.emplace("Initialization", std::make_unique<StructuredMetrics_InitializationEventValidator>());

    event_name_map_.emplace(UINT64_C(17627823560409533063), "Initialization");
}

StructuredMetricsProjectValidator::~StructuredMetricsProjectValidator() = default;

class CrOSEventsProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    CrOSEventsProjectValidator();
    ~CrOSEventsProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(12657197978410187837);
    static constexpr IdType kIdType = IdType::kProjectId;
    static constexpr IdScope kIdScope = IdScope::kPerDevice;
    static constexpr EventType kEventType = StructuredEventProto_EventType_SEQUENCE;
    static constexpr int kKeyRotationPeriod = 120;
};

CrOSEventsProjectValidator::CrOSEventsProjectValidator()
    : ::metrics::structured::ProjectValidator(CrOSEventsProjectValidator::kProjectNameHash, CrOSEventsProjectValidator::kIdType,
        CrOSEventsProjectValidator::kIdScope, CrOSEventsProjectValidator::kEventType, CrOSEventsProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void CrOSEventsProjectValidator::Initialize()
{
    event_validators_.emplace("AppDiscovery_AppInstalled", std::make_unique<CrOSEvents_AppDiscovery_AppInstalledEventValidator>());
    event_validators_.emplace(
        "AppDiscovery_AppInstallService_InstallRequested", std::make_unique<CrOSEvents_AppDiscovery_AppInstallService_InstallRequestedEventValidator>());
    event_validators_.emplace("AppDiscovery_AppLaunched", std::make_unique<CrOSEvents_AppDiscovery_AppLaunchedEventValidator>());
    event_validators_.emplace("AppDiscovery_AppUninstall", std::make_unique<CrOSEvents_AppDiscovery_AppUninstallEventValidator>());
    event_validators_.emplace("AppDiscovery_AppStateChanged", std::make_unique<CrOSEvents_AppDiscovery_AppStateChangedEventValidator>());
    event_validators_.emplace("AppDiscovery_ArcAppCameraAccessed", std::make_unique<CrOSEvents_AppDiscovery_ArcAppCameraAccessedEventValidator>());
    event_validators_.emplace("AppDiscovery_LauncherOpen", std::make_unique<CrOSEvents_AppDiscovery_LauncherOpenEventValidator>());
    event_validators_.emplace("AppDiscovery_AppLauncherResultOpened", std::make_unique<CrOSEvents_AppDiscovery_AppLauncherResultOpenedEventValidator>());
    event_validators_.emplace(
        "AppDiscovery_Browser_OmniboxInstallIconClicked", std::make_unique<CrOSEvents_AppDiscovery_Browser_OmniboxInstallIconClickedEventValidator>());
    event_validators_.emplace(
        "AppDiscovery_Browser_AppInstallDialogShown", std::make_unique<CrOSEvents_AppDiscovery_Browser_AppInstallDialogShownEventValidator>());
    event_validators_.emplace(
        "AppDiscovery_Browser_AppInstallDialogResult", std::make_unique<CrOSEvents_AppDiscovery_Browser_AppInstallDialogResultEventValidator>());
    event_validators_.emplace(
        "AppDiscovery_Browser_ClickInstallAppFromMenu", std::make_unique<CrOSEvents_AppDiscovery_Browser_ClickInstallAppFromMenuEventValidator>());
    event_validators_.emplace("AppDiscovery_Browser_CreateShortcut", std::make_unique<CrOSEvents_AppDiscovery_Browser_CreateShortcutEventValidator>());
    event_validators_.emplace("CameraApp_StartSession", std::make_unique<CrOSEvents_CameraApp_StartSessionEventValidator>());
    event_validators_.emplace("CameraApp_Capture", std::make_unique<CrOSEvents_CameraApp_CaptureEventValidator>());
    event_validators_.emplace("CameraApp_AndroidIntent", std::make_unique<CrOSEvents_CameraApp_AndroidIntentEventValidator>());
    event_validators_.emplace("CameraApp_OpenPTZPanel", std::make_unique<CrOSEvents_CameraApp_OpenPTZPanelEventValidator>());
    event_validators_.emplace("CameraApp_DocScanAction", std::make_unique<CrOSEvents_CameraApp_DocScanActionEventValidator>());
    event_validators_.emplace("CameraApp_DocScanResult", std::make_unique<CrOSEvents_CameraApp_DocScanResultEventValidator>());
    event_validators_.emplace("CameraApp_OpenCamera", std::make_unique<CrOSEvents_CameraApp_OpenCameraEventValidator>());
    event_validators_.emplace("CameraApp_LowStorageAction", std::make_unique<CrOSEvents_CameraApp_LowStorageActionEventValidator>());
    event_validators_.emplace("CameraApp_BarcodeDetected", std::make_unique<CrOSEvents_CameraApp_BarcodeDetectedEventValidator>());
    event_validators_.emplace("CameraApp_Perf", std::make_unique<CrOSEvents_CameraApp_PerfEventValidator>());
    event_validators_.emplace("CameraApp_UnsupportedProtocol", std::make_unique<CrOSEvents_CameraApp_UnsupportedProtocolEventValidator>());
    event_validators_.emplace("CameraApp_EndSession", std::make_unique<CrOSEvents_CameraApp_EndSessionEventValidator>());
    event_validators_.emplace("CameraApp_MemoryUsage", std::make_unique<CrOSEvents_CameraApp_MemoryUsageEventValidator>());
    event_validators_.emplace("CameraApp_Ocr", std::make_unique<CrOSEvents_CameraApp_OcrEventValidator>());
    event_validators_.emplace("Growth_Ui_ButtonPressed", std::make_unique<CrOSEvents_Growth_Ui_ButtonPressedEventValidator>());
    event_validators_.emplace("Growth_Ui_Dismissed", std::make_unique<CrOSEvents_Growth_Ui_DismissedEventValidator>());
    event_validators_.emplace("Growth_Ui_Impression", std::make_unique<CrOSEvents_Growth_Ui_ImpressionEventValidator>());
    event_validators_.emplace("OOBE_GaiaSigninRequested", std::make_unique<CrOSEvents_OOBE_GaiaSigninRequestedEventValidator>());
    event_validators_.emplace("OOBE_GaiaSigninCompleted", std::make_unique<CrOSEvents_OOBE_GaiaSigninCompletedEventValidator>());
    event_validators_.emplace("OOBE_OobeStarted", std::make_unique<CrOSEvents_OOBE_OobeStartedEventValidator>());
    event_validators_.emplace("OOBE_PreLoginOobeCompleted", std::make_unique<CrOSEvents_OOBE_PreLoginOobeCompletedEventValidator>());
    event_validators_.emplace("OOBE_DeviceRegistered", std::make_unique<CrOSEvents_OOBE_DeviceRegisteredEventValidator>());
    event_validators_.emplace("OOBE_OobeCompleted", std::make_unique<CrOSEvents_OOBE_OobeCompletedEventValidator>());
    event_validators_.emplace("OOBE_OnboardingStarted", std::make_unique<CrOSEvents_OOBE_OnboardingStartedEventValidator>());
    event_validators_.emplace("OOBE_OnboardingCompleted", std::make_unique<CrOSEvents_OOBE_OnboardingCompletedEventValidator>());
    event_validators_.emplace("OOBE_PageEntered", std::make_unique<CrOSEvents_OOBE_PageEnteredEventValidator>());
    event_validators_.emplace("OOBE_PageSkippedBySystem", std::make_unique<CrOSEvents_OOBE_PageSkippedBySystemEventValidator>());
    event_validators_.emplace("OOBE_PageLeft", std::make_unique<CrOSEvents_OOBE_PageLeftEventValidator>());
    event_validators_.emplace("OOBE_PreLoginOobeResumed", std::make_unique<CrOSEvents_OOBE_PreLoginOobeResumedEventValidator>());
    event_validators_.emplace("OOBE_OnboardingResumed", std::make_unique<CrOSEvents_OOBE_OnboardingResumedEventValidator>());
    event_validators_.emplace("OOBE_ChoobeResumed", std::make_unique<CrOSEvents_OOBE_ChoobeResumedEventValidator>());
    event_validators_.emplace("Picker_StartSession", std::make_unique<CrOSEvents_Picker_StartSessionEventValidator>());
    event_validators_.emplace("Picker_FinishSession", std::make_unique<CrOSEvents_Picker_FinishSessionEventValidator>());
    event_validators_.emplace("QuickStart_ScreenOpened", std::make_unique<CrOSEvents_QuickStart_ScreenOpenedEventValidator>());
    event_validators_.emplace("QuickStart_ScreenClosed", std::make_unique<CrOSEvents_QuickStart_ScreenClosedEventValidator>());
    event_validators_.emplace("QuickStart_Initiated", std::make_unique<CrOSEvents_QuickStart_InitiatedEventValidator>());
    event_validators_.emplace("QuickStart_FlowAborted", std::make_unique<CrOSEvents_QuickStart_FlowAbortedEventValidator>());
    event_validators_.emplace("QuickStart_EstablishConnection", std::make_unique<CrOSEvents_QuickStart_EstablishConnectionEventValidator>());
    event_validators_.emplace("QuickStart_AutomaticResumeAfterUpdate", std::make_unique<CrOSEvents_QuickStart_AutomaticResumeAfterUpdateEventValidator>());
    event_validators_.emplace("QuickStart_GetWifiCredentials", std::make_unique<CrOSEvents_QuickStart_GetWifiCredentialsEventValidator>());
    event_validators_.emplace("QuickStart_InstallForcedUpdate", std::make_unique<CrOSEvents_QuickStart_InstallForcedUpdateEventValidator>());
    event_validators_.emplace("QuickStart_InstallConsumerUpdate", std::make_unique<CrOSEvents_QuickStart_InstallConsumerUpdateEventValidator>());
    event_validators_.emplace("QuickStart_ConsumerUpdateCancelled", std::make_unique<CrOSEvents_QuickStart_ConsumerUpdateCancelledEventValidator>());
    event_validators_.emplace("QuickStart_AccountTransferStarted", std::make_unique<CrOSEvents_QuickStart_AccountTransferStartedEventValidator>());
    event_validators_.emplace("QuickStart_AccountTransferComplete", std::make_unique<CrOSEvents_QuickStart_AccountTransferCompleteEventValidator>());
    event_validators_.emplace("RecorderApp_StartSession", std::make_unique<CrOSEvents_RecorderApp_StartSessionEventValidator>());
    event_validators_.emplace("RecorderApp_Record", std::make_unique<CrOSEvents_RecorderApp_RecordEventValidator>());
    event_validators_.emplace("RecorderApp_SuggestTitle", std::make_unique<CrOSEvents_RecorderApp_SuggestTitleEventValidator>());
    event_validators_.emplace("RecorderApp_Summarize", std::make_unique<CrOSEvents_RecorderApp_SummarizeEventValidator>());
    event_validators_.emplace("RecorderApp_FeedbackTitleSuggestion", std::make_unique<CrOSEvents_RecorderApp_FeedbackTitleSuggestionEventValidator>());
    event_validators_.emplace("RecorderApp_FeedbackSummary", std::make_unique<CrOSEvents_RecorderApp_FeedbackSummaryEventValidator>());
    event_validators_.emplace("RecorderApp_Onboard", std::make_unique<CrOSEvents_RecorderApp_OnboardEventValidator>());
    event_validators_.emplace("RecorderApp_Export", std::make_unique<CrOSEvents_RecorderApp_ExportEventValidator>());
    event_validators_.emplace("RecorderApp_ChangePlaybackSpeed", std::make_unique<CrOSEvents_RecorderApp_ChangePlaybackSpeedEventValidator>());
    event_validators_.emplace("RecorderApp_ChangePlaybackVolume", std::make_unique<CrOSEvents_RecorderApp_ChangePlaybackVolumeEventValidator>());
    event_validators_.emplace("RecorderApp_AppStartPerf", std::make_unique<CrOSEvents_RecorderApp_AppStartPerfEventValidator>());
    event_validators_.emplace(
        "RecorderApp_TranscriptionModelDownloadPerf", std::make_unique<CrOSEvents_RecorderApp_TranscriptionModelDownloadPerfEventValidator>());
    event_validators_.emplace("RecorderApp_SummaryModelDownloadPerf", std::make_unique<CrOSEvents_RecorderApp_SummaryModelDownloadPerfEventValidator>());
    event_validators_.emplace("RecorderApp_RecordingSavingPerf", std::make_unique<CrOSEvents_RecorderApp_RecordingSavingPerfEventValidator>());
    event_validators_.emplace("RecorderApp_TitleSuggestionPerf", std::make_unique<CrOSEvents_RecorderApp_TitleSuggestionPerfEventValidator>());
    event_validators_.emplace("RecorderApp_SummaryPerf", std::make_unique<CrOSEvents_RecorderApp_SummaryPerfEventValidator>());
    event_validators_.emplace("RecorderApp_ExportPerf", std::make_unique<CrOSEvents_RecorderApp_ExportPerfEventValidator>());
    event_validators_.emplace("UserLogin", std::make_unique<CrOSEvents_UserLoginEventValidator>());
    event_validators_.emplace("UserLogout", std::make_unique<CrOSEvents_UserLogoutEventValidator>());
    event_validators_.emplace("SystemSuspended", std::make_unique<CrOSEvents_SystemSuspendedEventValidator>());
    event_validators_.emplace("Test1", std::make_unique<CrOSEvents_Test1EventValidator>());
    event_validators_.emplace("NoMetricsEvent", std::make_unique<CrOSEvents_NoMetricsEventEventValidator>());

    event_name_map_.emplace(UINT64_C(7058343684005446180), "AppDiscovery_AppInstalled");
    event_name_map_.emplace(UINT64_C(9189515227642480669), "AppDiscovery_AppInstallService_InstallRequested");
    event_name_map_.emplace(UINT64_C(10707673304400816961), "AppDiscovery_AppLaunched");
    event_name_map_.emplace(UINT64_C(2738328505235822343), "AppDiscovery_AppUninstall");
    event_name_map_.emplace(UINT64_C(9243762327526693209), "AppDiscovery_AppStateChanged");
    event_name_map_.emplace(UINT64_C(8471047485040088054), "AppDiscovery_ArcAppCameraAccessed");
    event_name_map_.emplace(UINT64_C(14878222005301987403), "AppDiscovery_LauncherOpen");
    event_name_map_.emplace(UINT64_C(8029308694385404808), "AppDiscovery_AppLauncherResultOpened");
    event_name_map_.emplace(UINT64_C(3850425801585793723), "AppDiscovery_Browser_OmniboxInstallIconClicked");
    event_name_map_.emplace(UINT64_C(12637046804977021887), "AppDiscovery_Browser_AppInstallDialogShown");
    event_name_map_.emplace(UINT64_C(13700312836166654669), "AppDiscovery_Browser_AppInstallDialogResult");
    event_name_map_.emplace(UINT64_C(9038997657104637664), "AppDiscovery_Browser_ClickInstallAppFromMenu");
    event_name_map_.emplace(UINT64_C(1826365659052634425), "AppDiscovery_Browser_CreateShortcut");
    event_name_map_.emplace(UINT64_C(12442349267185093909), "CameraApp_StartSession");
    event_name_map_.emplace(UINT64_C(3120751945078508193), "CameraApp_Capture");
    event_name_map_.emplace(UINT64_C(7329192243316244541), "CameraApp_AndroidIntent");
    event_name_map_.emplace(UINT64_C(10219338529199028724), "CameraApp_OpenPTZPanel");
    event_name_map_.emplace(UINT64_C(16175792557571171867), "CameraApp_DocScanAction");
    event_name_map_.emplace(UINT64_C(11722103785276254025), "CameraApp_DocScanResult");
    event_name_map_.emplace(UINT64_C(1579272689456091859), "CameraApp_OpenCamera");
    event_name_map_.emplace(UINT64_C(356388052753455524), "CameraApp_LowStorageAction");
    event_name_map_.emplace(UINT64_C(16213301286884956999), "CameraApp_BarcodeDetected");
    event_name_map_.emplace(UINT64_C(8599673815546087386), "CameraApp_Perf");
    event_name_map_.emplace(UINT64_C(3222573963151036809), "CameraApp_UnsupportedProtocol");
    event_name_map_.emplace(UINT64_C(3626223696860803178), "CameraApp_EndSession");
    event_name_map_.emplace(UINT64_C(7670635453183417468), "CameraApp_MemoryUsage");
    event_name_map_.emplace(UINT64_C(5249398244840003813), "CameraApp_Ocr");
    event_name_map_.emplace(UINT64_C(9030171304122254777), "Growth_Ui_ButtonPressed");
    event_name_map_.emplace(UINT64_C(17982940111339093869), "Growth_Ui_Dismissed");
    event_name_map_.emplace(UINT64_C(9777892808369836221), "Growth_Ui_Impression");
    event_name_map_.emplace(UINT64_C(7215278611898390473), "OOBE_GaiaSigninRequested");
    event_name_map_.emplace(UINT64_C(4496792889211345956), "OOBE_GaiaSigninCompleted");
    event_name_map_.emplace(UINT64_C(16917942210530705939), "OOBE_OobeStarted");
    event_name_map_.emplace(UINT64_C(16454148751386228729), "OOBE_PreLoginOobeCompleted");
    event_name_map_.emplace(UINT64_C(8463510949069965716), "OOBE_DeviceRegistered");
    event_name_map_.emplace(UINT64_C(10747825633360213518), "OOBE_OobeCompleted");
    event_name_map_.emplace(UINT64_C(11157696941906249496), "OOBE_OnboardingStarted");
    event_name_map_.emplace(UINT64_C(17879153985667426106), "OOBE_OnboardingCompleted");
    event_name_map_.emplace(UINT64_C(5040523310352364307), "OOBE_PageEntered");
    event_name_map_.emplace(UINT64_C(3047534590220959328), "OOBE_PageSkippedBySystem");
    event_name_map_.emplace(UINT64_C(9866162796307818893), "OOBE_PageLeft");
    event_name_map_.emplace(UINT64_C(5945023717299231192), "OOBE_PreLoginOobeResumed");
    event_name_map_.emplace(UINT64_C(10437926740417395028), "OOBE_OnboardingResumed");
    event_name_map_.emplace(UINT64_C(5000399004328028203), "OOBE_ChoobeResumed");
    event_name_map_.emplace(UINT64_C(9220963912679537764), "Picker_StartSession");
    event_name_map_.emplace(UINT64_C(201053742732988011), "Picker_FinishSession");
    event_name_map_.emplace(UINT64_C(1090623010432954280), "QuickStart_ScreenOpened");
    event_name_map_.emplace(UINT64_C(15755974401621020180), "QuickStart_ScreenClosed");
    event_name_map_.emplace(UINT64_C(10069442393575500987), "QuickStart_Initiated");
    event_name_map_.emplace(UINT64_C(271458273284797266), "QuickStart_FlowAborted");
    event_name_map_.emplace(UINT64_C(5941464810469552436), "QuickStart_EstablishConnection");
    event_name_map_.emplace(UINT64_C(12354443421864201072), "QuickStart_AutomaticResumeAfterUpdate");
    event_name_map_.emplace(UINT64_C(2010302068650205616), "QuickStart_GetWifiCredentials");
    event_name_map_.emplace(UINT64_C(9647936154020725001), "QuickStart_InstallForcedUpdate");
    event_name_map_.emplace(UINT64_C(10280751123048611555), "QuickStart_InstallConsumerUpdate");
    event_name_map_.emplace(UINT64_C(2414761012814314589), "QuickStart_ConsumerUpdateCancelled");
    event_name_map_.emplace(UINT64_C(12443251032486016611), "QuickStart_AccountTransferStarted");
    event_name_map_.emplace(UINT64_C(2521315848004865523), "QuickStart_AccountTransferComplete");
    event_name_map_.emplace(UINT64_C(17953969145682322416), "RecorderApp_StartSession");
    event_name_map_.emplace(UINT64_C(7805421305578040825), "RecorderApp_Record");
    event_name_map_.emplace(UINT64_C(6589582711380377924), "RecorderApp_SuggestTitle");
    event_name_map_.emplace(UINT64_C(12387081154250538363), "RecorderApp_Summarize");
    event_name_map_.emplace(UINT64_C(11687446154149603047), "RecorderApp_FeedbackTitleSuggestion");
    event_name_map_.emplace(UINT64_C(4650126128948725327), "RecorderApp_FeedbackSummary");
    event_name_map_.emplace(UINT64_C(11142430298433716066), "RecorderApp_Onboard");
    event_name_map_.emplace(UINT64_C(7302397246000171114), "RecorderApp_Export");
    event_name_map_.emplace(UINT64_C(6165782950648608956), "RecorderApp_ChangePlaybackSpeed");
    event_name_map_.emplace(UINT64_C(7259950894653435603), "RecorderApp_ChangePlaybackVolume");
    event_name_map_.emplace(UINT64_C(1929732514403632354), "RecorderApp_AppStartPerf");
    event_name_map_.emplace(UINT64_C(3331410798536455675), "RecorderApp_TranscriptionModelDownloadPerf");
    event_name_map_.emplace(UINT64_C(9067544395735895359), "RecorderApp_SummaryModelDownloadPerf");
    event_name_map_.emplace(UINT64_C(12782201950398001108), "RecorderApp_RecordingSavingPerf");
    event_name_map_.emplace(UINT64_C(5966473471854842275), "RecorderApp_TitleSuggestionPerf");
    event_name_map_.emplace(UINT64_C(165717034475136350), "RecorderApp_SummaryPerf");
    event_name_map_.emplace(UINT64_C(4757515255007932385), "RecorderApp_ExportPerf");
    event_name_map_.emplace(UINT64_C(3946957472799472890), "UserLogin");
    event_name_map_.emplace(UINT64_C(15162740773924916380), "UserLogout");
    event_name_map_.emplace(UINT64_C(9156818098953353395), "SystemSuspended");
    event_name_map_.emplace(UINT64_C(5509740142892158459), "Test1");
    event_name_map_.emplace(UINT64_C(5106854608989380457), "NoMetricsEvent");
}

CrOSEventsProjectValidator::~CrOSEventsProjectValidator() = default;

class DevToolsProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    DevToolsProjectValidator();
    ~DevToolsProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(5200054249928363981);
    static constexpr IdType kIdType = IdType::kProjectId;
    static constexpr IdScope kIdScope = IdScope::kPerDevice;
    static constexpr EventType kEventType = StructuredEventProto_EventType_REGULAR;
    static constexpr int kKeyRotationPeriod = 120;
};

DevToolsProjectValidator::DevToolsProjectValidator()
    : ::metrics::structured::ProjectValidator(DevToolsProjectValidator::kProjectNameHash, DevToolsProjectValidator::kIdType, DevToolsProjectValidator::kIdScope,
        DevToolsProjectValidator::kEventType, DevToolsProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void DevToolsProjectValidator::Initialize()
{
    event_validators_.emplace("SessionStart", std::make_unique<DevTools_SessionStartEventValidator>());
    event_validators_.emplace("SessionEnd", std::make_unique<DevTools_SessionEndEventValidator>());
    event_validators_.emplace("Impression", std::make_unique<DevTools_ImpressionEventValidator>());
    event_validators_.emplace("Resize", std::make_unique<DevTools_ResizeEventValidator>());
    event_validators_.emplace("Click", std::make_unique<DevTools_ClickEventValidator>());
    event_validators_.emplace("Hover", std::make_unique<DevTools_HoverEventValidator>());
    event_validators_.emplace("Drag", std::make_unique<DevTools_DragEventValidator>());
    event_validators_.emplace("Change", std::make_unique<DevTools_ChangeEventValidator>());
    event_validators_.emplace("KeyDown", std::make_unique<DevTools_KeyDownEventValidator>());

    event_name_map_.emplace(UINT64_C(13744243518034680300), "SessionStart");
    event_name_map_.emplace(UINT64_C(3262187048172162891), "SessionEnd");
    event_name_map_.emplace(UINT64_C(4398047322841981703), "Impression");
    event_name_map_.emplace(UINT64_C(15727676286859240), "Resize");
    event_name_map_.emplace(UINT64_C(5980286229304309245), "Click");
    event_name_map_.emplace(UINT64_C(4890306395588587268), "Hover");
    event_name_map_.emplace(UINT64_C(17504965937910711994), "Drag");
    event_name_map_.emplace(UINT64_C(11431363328394973259), "Change");
    event_name_map_.emplace(UINT64_C(1502882311982410087), "KeyDown");
}

DevToolsProjectValidator::~DevToolsProjectValidator() = default;

class TestProjectOneProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    TestProjectOneProjectValidator();
    ~TestProjectOneProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(16881314472396226433);
    static constexpr IdType kIdType = IdType::kProjectId;
    static constexpr IdScope kIdScope = IdScope::kPerProfile;
    static constexpr EventType kEventType = StructuredEventProto_EventType_REGULAR;
    static constexpr int kKeyRotationPeriod = 90;
};

TestProjectOneProjectValidator::TestProjectOneProjectValidator()
    : ::metrics::structured::ProjectValidator(TestProjectOneProjectValidator::kProjectNameHash, TestProjectOneProjectValidator::kIdType,
        TestProjectOneProjectValidator::kIdScope, TestProjectOneProjectValidator::kEventType, TestProjectOneProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void TestProjectOneProjectValidator::Initialize()
{
    event_validators_.emplace("TestEventOne", std::make_unique<TestProjectOne_TestEventOneEventValidator>());

    event_name_map_.emplace(UINT64_C(13593049295042080097), "TestEventOne");
}

TestProjectOneProjectValidator::~TestProjectOneProjectValidator() = default;

class TestProjectTwoProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    TestProjectTwoProjectValidator();
    ~TestProjectTwoProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(5876808001962504629);
    static constexpr IdType kIdType = IdType::kProjectId;
    static constexpr IdScope kIdScope = IdScope::kPerProfile;
    static constexpr EventType kEventType = StructuredEventProto_EventType_REGULAR;
    static constexpr int kKeyRotationPeriod = 90;
};

TestProjectTwoProjectValidator::TestProjectTwoProjectValidator()
    : ::metrics::structured::ProjectValidator(TestProjectTwoProjectValidator::kProjectNameHash, TestProjectTwoProjectValidator::kIdType,
        TestProjectTwoProjectValidator::kIdScope, TestProjectTwoProjectValidator::kEventType, TestProjectTwoProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void TestProjectTwoProjectValidator::Initialize()
{
    event_validators_.emplace("TestEventThree", std::make_unique<TestProjectTwo_TestEventThreeEventValidator>());
    event_validators_.emplace("TestEventTwo", std::make_unique<TestProjectTwo_TestEventTwoEventValidator>());

    event_name_map_.emplace(UINT64_C(5848687377041124372), "TestEventThree");
    event_name_map_.emplace(UINT64_C(8995967733561999410), "TestEventTwo");
}

TestProjectTwoProjectValidator::~TestProjectTwoProjectValidator() = default;

class TestProjectThreeProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    TestProjectThreeProjectValidator();
    ~TestProjectThreeProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(10860358748803291132);
    static constexpr IdType kIdType = IdType::kUmaId;
    static constexpr IdScope kIdScope = IdScope::kPerProfile;
    static constexpr EventType kEventType = StructuredEventProto_EventType_REGULAR;
    static constexpr int kKeyRotationPeriod = 90;
};

TestProjectThreeProjectValidator::TestProjectThreeProjectValidator()
    : ::metrics::structured::ProjectValidator(TestProjectThreeProjectValidator::kProjectNameHash, TestProjectThreeProjectValidator::kIdType,
        TestProjectThreeProjectValidator::kIdScope, TestProjectThreeProjectValidator::kEventType, TestProjectThreeProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void TestProjectThreeProjectValidator::Initialize()
{
    event_validators_.emplace("TestEventFour", std::make_unique<TestProjectThree_TestEventFourEventValidator>());

    event_name_map_.emplace(UINT64_C(1718797808092246258), "TestEventFour");
}

TestProjectThreeProjectValidator::~TestProjectThreeProjectValidator() = default;

class TestProjectFourProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    TestProjectFourProjectValidator();
    ~TestProjectFourProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(6801665881746546626);
    static constexpr IdType kIdType = IdType::kProjectId;
    static constexpr IdScope kIdScope = IdScope::kPerDevice;
    static constexpr EventType kEventType = StructuredEventProto_EventType_REGULAR;
    static constexpr int kKeyRotationPeriod = 90;
};

TestProjectFourProjectValidator::TestProjectFourProjectValidator()
    : ::metrics::structured::ProjectValidator(TestProjectFourProjectValidator::kProjectNameHash, TestProjectFourProjectValidator::kIdType,
        TestProjectFourProjectValidator::kIdScope, TestProjectFourProjectValidator::kEventType, TestProjectFourProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void TestProjectFourProjectValidator::Initialize()
{
    event_validators_.emplace("TestEventFive", std::make_unique<TestProjectFour_TestEventFiveEventValidator>());

    event_name_map_.emplace(UINT64_C(7045523601811399253), "TestEventFive");
}

TestProjectFourProjectValidator::~TestProjectFourProjectValidator() = default;

class TestProjectFiveProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    TestProjectFiveProjectValidator();
    ~TestProjectFiveProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(3960582687892677139);
    static constexpr IdType kIdType = IdType::kUnidentified;
    static constexpr IdScope kIdScope = IdScope::kPerProfile;
    static constexpr EventType kEventType = StructuredEventProto_EventType_RAW_STRING;
    static constexpr int kKeyRotationPeriod = 90;
};

TestProjectFiveProjectValidator::TestProjectFiveProjectValidator()
    : ::metrics::structured::ProjectValidator(TestProjectFiveProjectValidator::kProjectNameHash, TestProjectFiveProjectValidator::kIdType,
        TestProjectFiveProjectValidator::kIdScope, TestProjectFiveProjectValidator::kEventType, TestProjectFiveProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void TestProjectFiveProjectValidator::Initialize()
{
    event_validators_.emplace("TestEventSix", std::make_unique<TestProjectFive_TestEventSixEventValidator>());

    event_name_map_.emplace(UINT64_C(2873337042686447043), "TestEventSix");
}

TestProjectFiveProjectValidator::~TestProjectFiveProjectValidator() = default;

class TestProjectSixProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    TestProjectSixProjectValidator();
    ~TestProjectSixProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(6972396123792667134);
    static constexpr IdType kIdType = IdType::kUnidentified;
    static constexpr IdScope kIdScope = IdScope::kPerProfile;
    static constexpr EventType kEventType = StructuredEventProto_EventType_REGULAR;
    static constexpr int kKeyRotationPeriod = 90;
};

TestProjectSixProjectValidator::TestProjectSixProjectValidator()
    : ::metrics::structured::ProjectValidator(TestProjectSixProjectValidator::kProjectNameHash, TestProjectSixProjectValidator::kIdType,
        TestProjectSixProjectValidator::kIdScope, TestProjectSixProjectValidator::kEventType, TestProjectSixProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void TestProjectSixProjectValidator::Initialize()
{
    event_validators_.emplace("TestEventSeven", std::make_unique<TestProjectSix_TestEventSevenEventValidator>());
    event_validators_.emplace("TestEnum", std::make_unique<TestProjectSix_TestEnumEventValidator>());

    event_name_map_.emplace(UINT64_C(16749091071228286247), "TestEventSeven");
    event_name_map_.emplace(UINT64_C(14837072141472316574), "TestEnum");
}

TestProjectSixProjectValidator::~TestProjectSixProjectValidator() = default;

class TestProjectSevenProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    TestProjectSevenProjectValidator();
    ~TestProjectSevenProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(10319251808101486833);
    static constexpr IdType kIdType = IdType::kUnidentified;
    static constexpr IdScope kIdScope = IdScope::kPerProfile;
    static constexpr EventType kEventType = StructuredEventProto_EventType_REGULAR;
    static constexpr int kKeyRotationPeriod = 90;
};

TestProjectSevenProjectValidator::TestProjectSevenProjectValidator()
    : ::metrics::structured::ProjectValidator(TestProjectSevenProjectValidator::kProjectNameHash, TestProjectSevenProjectValidator::kIdType,
        TestProjectSevenProjectValidator::kIdScope, TestProjectSevenProjectValidator::kEventType, TestProjectSevenProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void TestProjectSevenProjectValidator::Initialize()
{
    event_validators_.emplace("TestEventEight", std::make_unique<TestProjectSeven_TestEventEightEventValidator>());

    event_name_map_.emplace(UINT64_C(16290206418240617738), "TestEventEight");
}

TestProjectSevenProjectValidator::~TestProjectSevenProjectValidator() = default;

class SequencedTestProjectProjectValidator final : public ::metrics::structured::ProjectValidator {
public:
    SequencedTestProjectProjectValidator();
    ~SequencedTestProjectProjectValidator() override;

    void Initialize();

    static constexpr uint64_t kProjectNameHash = UINT64_C(7434962983641669694);
    static constexpr IdType kIdType = IdType::kProjectId;
    static constexpr IdScope kIdScope = IdScope::kPerProfile;
    static constexpr EventType kEventType = StructuredEventProto_EventType_SEQUENCE;
    static constexpr int kKeyRotationPeriod = 90;
};

SequencedTestProjectProjectValidator::SequencedTestProjectProjectValidator()
    : ::metrics::structured::ProjectValidator(SequencedTestProjectProjectValidator::kProjectNameHash, SequencedTestProjectProjectValidator::kIdType,
        SequencedTestProjectProjectValidator::kIdScope, SequencedTestProjectProjectValidator::kEventType,
        SequencedTestProjectProjectValidator::kKeyRotationPeriod)
{
    Initialize();
}

void SequencedTestProjectProjectValidator::Initialize()
{
    event_validators_.emplace("Test1", std::make_unique<SequencedTestProject_Test1EventValidator>());

    event_name_map_.emplace(UINT64_C(2284817119476109309), "Test1");
}

SequencedTestProjectProjectValidator::~SequencedTestProjectProjectValidator() = default;

}

namespace validator {

Validators::Validators()
{
    Initialize();
}

void Validators::Initialize()
{
    validators_.emplace("PopularDisplays", std::make_unique<PopularDisplaysProjectValidator>());
    validators_.emplace("FastPair", std::make_unique<FastPairProjectValidator>());
    validators_.emplace("Hindsight", std::make_unique<HindsightProjectValidator>());
    validators_.emplace("LauncherUsage", std::make_unique<LauncherUsageProjectValidator>());
    validators_.emplace("NearbyShare", std::make_unique<NearbyShareProjectValidator>());
    validators_.emplace("PhoneHub", std::make_unique<PhoneHubProjectValidator>());
    validators_.emplace("StructuredMetrics", std::make_unique<StructuredMetricsProjectValidator>());
    validators_.emplace("CrOSEvents", std::make_unique<CrOSEventsProjectValidator>());
    validators_.emplace("DevTools", std::make_unique<DevToolsProjectValidator>());
    validators_.emplace("TestProjectOne", std::make_unique<TestProjectOneProjectValidator>());
    validators_.emplace("TestProjectTwo", std::make_unique<TestProjectTwoProjectValidator>());
    validators_.emplace("TestProjectThree", std::make_unique<TestProjectThreeProjectValidator>());
    validators_.emplace("TestProjectFour", std::make_unique<TestProjectFourProjectValidator>());
    validators_.emplace("TestProjectFive", std::make_unique<TestProjectFiveProjectValidator>());
    validators_.emplace("TestProjectSix", std::make_unique<TestProjectSixProjectValidator>());
    validators_.emplace("TestProjectSeven", std::make_unique<TestProjectSevenProjectValidator>());
    validators_.emplace("SequencedTestProject", std::make_unique<SequencedTestProjectProjectValidator>());

    project_name_map_.emplace(UINT64_C(13666187132464558198), "PopularDisplays");
    project_name_map_.emplace(UINT64_C(4257181691211608017), "FastPair");
    project_name_map_.emplace(UINT64_C(16658867201751992801), "Hindsight");
    project_name_map_.emplace(UINT64_C(10270819838268357145), "LauncherUsage");
    project_name_map_.emplace(UINT64_C(16660214177681096661), "NearbyShare");
    project_name_map_.emplace(UINT64_C(7404894664453311568), "PhoneHub");
    project_name_map_.emplace(UINT64_C(12908457551569912491), "StructuredMetrics");
    project_name_map_.emplace(UINT64_C(12657197978410187837), "CrOSEvents");
    project_name_map_.emplace(UINT64_C(5200054249928363981), "DevTools");
    project_name_map_.emplace(UINT64_C(16881314472396226433), "TestProjectOne");
    project_name_map_.emplace(UINT64_C(5876808001962504629), "TestProjectTwo");
    project_name_map_.emplace(UINT64_C(10860358748803291132), "TestProjectThree");
    project_name_map_.emplace(UINT64_C(6801665881746546626), "TestProjectFour");
    project_name_map_.emplace(UINT64_C(3960582687892677139), "TestProjectFive");
    project_name_map_.emplace(UINT64_C(6972396123792667134), "TestProjectSix");
    project_name_map_.emplace(UINT64_C(10319251808101486833), "TestProjectSeven");
    project_name_map_.emplace(UINT64_C(7434962983641669694), "SequencedTestProject");
}

const ProjectValidator* Validators::GetProjectValidator(std::string_view project_name) const
{
    const auto it = validators_.find(project_name);
    if (it == validators_.end())
        return nullptr;
    return it->second.get();
}

std::optional<std::string_view> Validators::GetProjectName(uint64_t project_name_hash) const
{
    const auto it = project_name_map_.find(project_name_hash);
    if (it == project_name_map_.end())
        return std::nullopt;
    // This lookup will never fail.
    return it->second;
}

// static
Validators* Validators::Get()
{
    static base::NoDestructor<Validators> validators;
    return validators.get();
}

} // namespace validator
} // namespace structured
} // namespace metrics