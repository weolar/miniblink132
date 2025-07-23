// Generated from gen_events.py. DO NOT EDIT!
// source: structured.xml

#include "components/metrics/structured/structured_events.h"

#include "base/strings/string_number_conversions.h"
#include "base/values.h"

namespace metrics {
namespace structured {
namespace events {
namespace v2 {

namespace popular_displays {

MonitorInfo::MonitorInfo()
    : ::metrics::structured::Event("PopularDisplays", "MonitorInfo", false)
{
}
MonitorInfo::~MonitorInfo() = default;

MonitorInfo&& MonitorInfo::SetDisplayName(const std::string& value) &&
{
    AddMetric("DisplayName", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

MonitorInfo& MonitorInfo::SetDisplayName(const std::string& value) &
{
    AddMetric("DisplayName", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

MonitorInfo&& MonitorInfo::SetManufacturerId(const std::string& value) &&
{
    AddMetric("ManufacturerId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

MonitorInfo& MonitorInfo::SetManufacturerId(const std::string& value) &
{
    AddMetric("ManufacturerId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

MonitorInfo&& MonitorInfo::SetProductId(const int64_t value) &&
{
    AddMetric("ProductId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

MonitorInfo& MonitorInfo::SetProductId(const int64_t value) &
{
    AddMetric("ProductId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

MonitorInfo&& MonitorInfo::SetNativeModeSize(const std::string& value) &&
{
    AddMetric("NativeModeSize", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

MonitorInfo& MonitorInfo::SetNativeModeSize(const std::string& value) &
{
    AddMetric("NativeModeSize", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

MonitorInfo&& MonitorInfo::SetNativeModeRefreshRate(const double value) &&
{
    AddMetric("NativeModeRefreshRate", Event::MetricType::kDouble, base::Value(value));
    return std::move(*this);
}

MonitorInfo& MonitorInfo::SetNativeModeRefreshRate(const double value) &
{
    AddMetric("NativeModeRefreshRate", Event::MetricType::kDouble, base::Value(value));
    return *this;
}

MonitorInfo&& MonitorInfo::SetPhysicalSize(const std::string& value) &&
{
    AddMetric("PhysicalSize", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

MonitorInfo& MonitorInfo::SetPhysicalSize(const std::string& value) &
{
    AddMetric("PhysicalSize", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

MonitorInfo&& MonitorInfo::SetConnectionType(const std::string& value) &&
{
    AddMetric("ConnectionType", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

MonitorInfo& MonitorInfo::SetConnectionType(const std::string& value) &
{
    AddMetric("ConnectionType", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

MonitorInfo&& MonitorInfo::SetIsVrrCapable(const int64_t value) &&
{
    AddMetric("IsVrrCapable", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

MonitorInfo& MonitorInfo::SetIsVrrCapable(const int64_t value) &
{
    AddMetric("IsVrrCapable", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

} // namespace popular_displays

namespace fast_pair {

DiscoveryNotificationShown::DiscoveryNotificationShown()
    : ::metrics::structured::Event("FastPair", "DiscoveryNotificationShown", false)
{
}
DiscoveryNotificationShown::~DiscoveryNotificationShown() = default;

DiscoveryNotificationShown&& DiscoveryNotificationShown::SetProtocol(const int64_t value) &&
{
    AddMetric("Protocol", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

DiscoveryNotificationShown& DiscoveryNotificationShown::SetProtocol(const int64_t value) &
{
    AddMetric("Protocol", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

DiscoveryNotificationShown&& DiscoveryNotificationShown::SetFastPairVersion(const int64_t value) &&
{
    AddMetric("FastPairVersion", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

DiscoveryNotificationShown& DiscoveryNotificationShown::SetFastPairVersion(const int64_t value) &
{
    AddMetric("FastPairVersion", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

DiscoveryNotificationShown&& DiscoveryNotificationShown::SetModelId(const int64_t value) &&
{
    AddMetric("ModelId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

DiscoveryNotificationShown& DiscoveryNotificationShown::SetModelId(const int64_t value) &
{
    AddMetric("ModelId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

DiscoveryNotificationShown&& DiscoveryNotificationShown::SetRSSI(const int64_t value) &&
{
    AddMetric("RSSI", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

DiscoveryNotificationShown& DiscoveryNotificationShown::SetRSSI(const int64_t value) &
{
    AddMetric("RSSI", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

DiscoveryNotificationShown&& DiscoveryNotificationShown::SetTxPower(const int64_t value) &&
{
    AddMetric("TxPower", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

DiscoveryNotificationShown& DiscoveryNotificationShown::SetTxPower(const int64_t value) &
{
    AddMetric("TxPower", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PairingStart::PairingStart()
    : ::metrics::structured::Event("FastPair", "PairingStart", false)
{
}
PairingStart::~PairingStart() = default;

PairingStart&& PairingStart::SetProtocol(const int64_t value) &&
{
    AddMetric("Protocol", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PairingStart& PairingStart::SetProtocol(const int64_t value) &
{
    AddMetric("Protocol", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PairingStart&& PairingStart::SetFastPairVersion(const int64_t value) &&
{
    AddMetric("FastPairVersion", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PairingStart& PairingStart::SetFastPairVersion(const int64_t value) &
{
    AddMetric("FastPairVersion", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PairingStart&& PairingStart::SetModelId(const int64_t value) &&
{
    AddMetric("ModelId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PairingStart& PairingStart::SetModelId(const int64_t value) &
{
    AddMetric("ModelId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PairingStart&& PairingStart::SetRSSI(const int64_t value) &&
{
    AddMetric("RSSI", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PairingStart& PairingStart::SetRSSI(const int64_t value) &
{
    AddMetric("RSSI", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PairingStart&& PairingStart::SetTxPower(const int64_t value) &&
{
    AddMetric("TxPower", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PairingStart& PairingStart::SetTxPower(const int64_t value) &
{
    AddMetric("TxPower", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PairingComplete::PairingComplete()
    : ::metrics::structured::Event("FastPair", "PairingComplete", false)
{
}
PairingComplete::~PairingComplete() = default;

PairingComplete&& PairingComplete::SetProtocol(const int64_t value) &&
{
    AddMetric("Protocol", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PairingComplete& PairingComplete::SetProtocol(const int64_t value) &
{
    AddMetric("Protocol", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PairingComplete&& PairingComplete::SetFastPairVersion(const int64_t value) &&
{
    AddMetric("FastPairVersion", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PairingComplete& PairingComplete::SetFastPairVersion(const int64_t value) &
{
    AddMetric("FastPairVersion", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PairingComplete&& PairingComplete::SetModelId(const int64_t value) &&
{
    AddMetric("ModelId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PairingComplete& PairingComplete::SetModelId(const int64_t value) &
{
    AddMetric("ModelId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PairingComplete&& PairingComplete::SetRSSI(const int64_t value) &&
{
    AddMetric("RSSI", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PairingComplete& PairingComplete::SetRSSI(const int64_t value) &
{
    AddMetric("RSSI", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PairingComplete&& PairingComplete::SetTxPower(const int64_t value) &&
{
    AddMetric("TxPower", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PairingComplete& PairingComplete::SetTxPower(const int64_t value) &
{
    AddMetric("TxPower", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PairFailure::PairFailure()
    : ::metrics::structured::Event("FastPair", "PairFailure", false)
{
}
PairFailure::~PairFailure() = default;

PairFailure&& PairFailure::SetProtocol(const int64_t value) &&
{
    AddMetric("Protocol", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PairFailure& PairFailure::SetProtocol(const int64_t value) &
{
    AddMetric("Protocol", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PairFailure&& PairFailure::SetFastPairVersion(const int64_t value) &&
{
    AddMetric("FastPairVersion", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PairFailure& PairFailure::SetFastPairVersion(const int64_t value) &
{
    AddMetric("FastPairVersion", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PairFailure&& PairFailure::SetReason(const int64_t value) &&
{
    AddMetric("Reason", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PairFailure& PairFailure::SetReason(const int64_t value) &
{
    AddMetric("Reason", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PairFailure&& PairFailure::SetModelId(const int64_t value) &&
{
    AddMetric("ModelId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PairFailure& PairFailure::SetModelId(const int64_t value) &
{
    AddMetric("ModelId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

} // namespace fast_pair

namespace hindsight {

CrOSActionEvent_FileOpened::CrOSActionEvent_FileOpened()
    : ::metrics::structured::Event("Hindsight", "CrOSActionEvent_FileOpened", false)
{
}
CrOSActionEvent_FileOpened::~CrOSActionEvent_FileOpened() = default;

CrOSActionEvent_FileOpened&& CrOSActionEvent_FileOpened::SetFilename(const std::string& value) &&
{
    AddMetric("Filename", Event::MetricType::kHmac, base::Value(value));
    return std::move(*this);
}

CrOSActionEvent_FileOpened& CrOSActionEvent_FileOpened::SetFilename(const std::string& value) &
{
    AddMetric("Filename", Event::MetricType::kHmac, base::Value(value));
    return *this;
}

CrOSActionEvent_FileOpened&& CrOSActionEvent_FileOpened::SetOpenType(const int64_t value) &&
{
    AddMetric("OpenType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_FileOpened& CrOSActionEvent_FileOpened::SetOpenType(const int64_t value) &
{
    AddMetric("OpenType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_FileOpened&& CrOSActionEvent_FileOpened::SetSequenceId(const int64_t value) &&
{
    AddMetric("SequenceId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_FileOpened& CrOSActionEvent_FileOpened::SetSequenceId(const int64_t value) &
{
    AddMetric("SequenceId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_FileOpened&& CrOSActionEvent_FileOpened::SetTimeSinceLastAction(const int64_t value) &&
{
    AddMetric("TimeSinceLastAction", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_FileOpened& CrOSActionEvent_FileOpened::SetTimeSinceLastAction(const int64_t value) &
{
    AddMetric("TimeSinceLastAction", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_SearchResultLaunched::CrOSActionEvent_SearchResultLaunched()
    : ::metrics::structured::Event("Hindsight", "CrOSActionEvent_SearchResultLaunched", false)
{
}
CrOSActionEvent_SearchResultLaunched::~CrOSActionEvent_SearchResultLaunched() = default;

CrOSActionEvent_SearchResultLaunched&& CrOSActionEvent_SearchResultLaunched::SetQuery(const std::string& value) &&
{
    AddMetric("Query", Event::MetricType::kHmac, base::Value(value));
    return std::move(*this);
}

CrOSActionEvent_SearchResultLaunched& CrOSActionEvent_SearchResultLaunched::SetQuery(const std::string& value) &
{
    AddMetric("Query", Event::MetricType::kHmac, base::Value(value));
    return *this;
}

CrOSActionEvent_SearchResultLaunched&& CrOSActionEvent_SearchResultLaunched::SetResultType(const int64_t value) &&
{
    AddMetric("ResultType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_SearchResultLaunched& CrOSActionEvent_SearchResultLaunched::SetResultType(const int64_t value) &
{
    AddMetric("ResultType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_SearchResultLaunched&& CrOSActionEvent_SearchResultLaunched::SetSearchResultId(const std::string& value) &&
{
    AddMetric("SearchResultId", Event::MetricType::kHmac, base::Value(value));
    return std::move(*this);
}

CrOSActionEvent_SearchResultLaunched& CrOSActionEvent_SearchResultLaunched::SetSearchResultId(const std::string& value) &
{
    AddMetric("SearchResultId", Event::MetricType::kHmac, base::Value(value));
    return *this;
}

CrOSActionEvent_SearchResultLaunched&& CrOSActionEvent_SearchResultLaunched::SetSequenceId(const int64_t value) &&
{
    AddMetric("SequenceId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_SearchResultLaunched& CrOSActionEvent_SearchResultLaunched::SetSequenceId(const int64_t value) &
{
    AddMetric("SequenceId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_SearchResultLaunched&& CrOSActionEvent_SearchResultLaunched::SetTimeSinceLastAction(const int64_t value) &&
{
    AddMetric("TimeSinceLastAction", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_SearchResultLaunched& CrOSActionEvent_SearchResultLaunched::SetTimeSinceLastAction(const int64_t value) &
{
    AddMetric("TimeSinceLastAction", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_SettingChanged::CrOSActionEvent_SettingChanged()
    : ::metrics::structured::Event("Hindsight", "CrOSActionEvent_SettingChanged", false)
{
}
CrOSActionEvent_SettingChanged::~CrOSActionEvent_SettingChanged() = default;

CrOSActionEvent_SettingChanged&& CrOSActionEvent_SettingChanged::SetCurrentValue(const int64_t value) &&
{
    AddMetric("CurrentValue", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_SettingChanged& CrOSActionEvent_SettingChanged::SetCurrentValue(const int64_t value) &
{
    AddMetric("CurrentValue", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_SettingChanged&& CrOSActionEvent_SettingChanged::SetPreviousValue(const int64_t value) &&
{
    AddMetric("PreviousValue", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_SettingChanged& CrOSActionEvent_SettingChanged::SetPreviousValue(const int64_t value) &
{
    AddMetric("PreviousValue", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_SettingChanged&& CrOSActionEvent_SettingChanged::SetSequenceId(const int64_t value) &&
{
    AddMetric("SequenceId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_SettingChanged& CrOSActionEvent_SettingChanged::SetSequenceId(const int64_t value) &
{
    AddMetric("SequenceId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_SettingChanged&& CrOSActionEvent_SettingChanged::SetSettingId(const int64_t value) &&
{
    AddMetric("SettingId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_SettingChanged& CrOSActionEvent_SettingChanged::SetSettingId(const int64_t value) &
{
    AddMetric("SettingId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_SettingChanged&& CrOSActionEvent_SettingChanged::SetSettingType(const int64_t value) &&
{
    AddMetric("SettingType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_SettingChanged& CrOSActionEvent_SettingChanged::SetSettingType(const int64_t value) &
{
    AddMetric("SettingType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_SettingChanged&& CrOSActionEvent_SettingChanged::SetTimeSinceLastAction(const int64_t value) &&
{
    AddMetric("TimeSinceLastAction", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_SettingChanged& CrOSActionEvent_SettingChanged::SetTimeSinceLastAction(const int64_t value) &
{
    AddMetric("TimeSinceLastAction", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_TabEvent_TabNavigated::CrOSActionEvent_TabEvent_TabNavigated()
    : ::metrics::structured::Event("Hindsight", "CrOSActionEvent_TabEvent_TabNavigated", false)
{
}
CrOSActionEvent_TabEvent_TabNavigated::~CrOSActionEvent_TabEvent_TabNavigated() = default;

CrOSActionEvent_TabEvent_TabNavigated&& CrOSActionEvent_TabEvent_TabNavigated::SetPageTransition(const int64_t value) &&
{
    AddMetric("PageTransition", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_TabEvent_TabNavigated& CrOSActionEvent_TabEvent_TabNavigated::SetPageTransition(const int64_t value) &
{
    AddMetric("PageTransition", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_TabEvent_TabNavigated&& CrOSActionEvent_TabEvent_TabNavigated::SetSequenceId(const int64_t value) &&
{
    AddMetric("SequenceId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_TabEvent_TabNavigated& CrOSActionEvent_TabEvent_TabNavigated::SetSequenceId(const int64_t value) &
{
    AddMetric("SequenceId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_TabEvent_TabNavigated&& CrOSActionEvent_TabEvent_TabNavigated::SetTimeSinceLastAction(const int64_t value) &&
{
    AddMetric("TimeSinceLastAction", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_TabEvent_TabNavigated& CrOSActionEvent_TabEvent_TabNavigated::SetTimeSinceLastAction(const int64_t value) &
{
    AddMetric("TimeSinceLastAction", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_TabEvent_TabNavigated&& CrOSActionEvent_TabEvent_TabNavigated::SetURL(const std::string& value) &&
{
    AddMetric("URL", Event::MetricType::kHmac, base::Value(value));
    return std::move(*this);
}

CrOSActionEvent_TabEvent_TabNavigated& CrOSActionEvent_TabEvent_TabNavigated::SetURL(const std::string& value) &
{
    AddMetric("URL", Event::MetricType::kHmac, base::Value(value));
    return *this;
}

CrOSActionEvent_TabEvent_TabNavigated&& CrOSActionEvent_TabEvent_TabNavigated::SetVisibility(const int64_t value) &&
{
    AddMetric("Visibility", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_TabEvent_TabNavigated& CrOSActionEvent_TabEvent_TabNavigated::SetVisibility(const int64_t value) &
{
    AddMetric("Visibility", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_TabEvent_TabOpened::CrOSActionEvent_TabEvent_TabOpened()
    : ::metrics::structured::Event("Hindsight", "CrOSActionEvent_TabEvent_TabOpened", false)
{
}
CrOSActionEvent_TabEvent_TabOpened::~CrOSActionEvent_TabEvent_TabOpened() = default;

CrOSActionEvent_TabEvent_TabOpened&& CrOSActionEvent_TabEvent_TabOpened::SetSequenceId(const int64_t value) &&
{
    AddMetric("SequenceId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_TabEvent_TabOpened& CrOSActionEvent_TabEvent_TabOpened::SetSequenceId(const int64_t value) &
{
    AddMetric("SequenceId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_TabEvent_TabOpened&& CrOSActionEvent_TabEvent_TabOpened::SetTimeSinceLastAction(const int64_t value) &&
{
    AddMetric("TimeSinceLastAction", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_TabEvent_TabOpened& CrOSActionEvent_TabEvent_TabOpened::SetTimeSinceLastAction(const int64_t value) &
{
    AddMetric("TimeSinceLastAction", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_TabEvent_TabOpened&& CrOSActionEvent_TabEvent_TabOpened::SetURL(const std::string& value) &&
{
    AddMetric("URL", Event::MetricType::kHmac, base::Value(value));
    return std::move(*this);
}

CrOSActionEvent_TabEvent_TabOpened& CrOSActionEvent_TabEvent_TabOpened::SetURL(const std::string& value) &
{
    AddMetric("URL", Event::MetricType::kHmac, base::Value(value));
    return *this;
}

CrOSActionEvent_TabEvent_TabOpened&& CrOSActionEvent_TabEvent_TabOpened::SetURLOpened(const std::string& value) &&
{
    AddMetric("URLOpened", Event::MetricType::kHmac, base::Value(value));
    return std::move(*this);
}

CrOSActionEvent_TabEvent_TabOpened& CrOSActionEvent_TabEvent_TabOpened::SetURLOpened(const std::string& value) &
{
    AddMetric("URLOpened", Event::MetricType::kHmac, base::Value(value));
    return *this;
}

CrOSActionEvent_TabEvent_TabOpened&& CrOSActionEvent_TabEvent_TabOpened::SetWindowOpenDisposition(const int64_t value) &&
{
    AddMetric("WindowOpenDisposition", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_TabEvent_TabOpened& CrOSActionEvent_TabEvent_TabOpened::SetWindowOpenDisposition(const int64_t value) &
{
    AddMetric("WindowOpenDisposition", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_TabEvent_TabReactivated::CrOSActionEvent_TabEvent_TabReactivated()
    : ::metrics::structured::Event("Hindsight", "CrOSActionEvent_TabEvent_TabReactivated", false)
{
}
CrOSActionEvent_TabEvent_TabReactivated::~CrOSActionEvent_TabEvent_TabReactivated() = default;

CrOSActionEvent_TabEvent_TabReactivated&& CrOSActionEvent_TabEvent_TabReactivated::SetSequenceId(const int64_t value) &&
{
    AddMetric("SequenceId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_TabEvent_TabReactivated& CrOSActionEvent_TabEvent_TabReactivated::SetSequenceId(const int64_t value) &
{
    AddMetric("SequenceId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_TabEvent_TabReactivated&& CrOSActionEvent_TabEvent_TabReactivated::SetTimeSinceLastAction(const int64_t value) &&
{
    AddMetric("TimeSinceLastAction", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CrOSActionEvent_TabEvent_TabReactivated& CrOSActionEvent_TabEvent_TabReactivated::SetTimeSinceLastAction(const int64_t value) &
{
    AddMetric("TimeSinceLastAction", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CrOSActionEvent_TabEvent_TabReactivated&& CrOSActionEvent_TabEvent_TabReactivated::SetURL(const std::string& value) &&
{
    AddMetric("URL", Event::MetricType::kHmac, base::Value(value));
    return std::move(*this);
}

CrOSActionEvent_TabEvent_TabReactivated& CrOSActionEvent_TabEvent_TabReactivated::SetURL(const std::string& value) &
{
    AddMetric("URL", Event::MetricType::kHmac, base::Value(value));
    return *this;
}

} // namespace hindsight

namespace launcher_usage {

LauncherUsage::LauncherUsage()
    : ::metrics::structured::Event("LauncherUsage", "LauncherUsage", false)
{
}
LauncherUsage::~LauncherUsage() = default;

LauncherUsage&& LauncherUsage::SetApp(const std::string& value) &&
{
    AddMetric("App", Event::MetricType::kHmac, base::Value(value));
    return std::move(*this);
}

LauncherUsage& LauncherUsage::SetApp(const std::string& value) &
{
    AddMetric("App", Event::MetricType::kHmac, base::Value(value));
    return *this;
}

LauncherUsage&& LauncherUsage::SetDomain(const std::string& value) &&
{
    AddMetric("Domain", Event::MetricType::kHmac, base::Value(value));
    return std::move(*this);
}

LauncherUsage& LauncherUsage::SetDomain(const std::string& value) &
{
    AddMetric("Domain", Event::MetricType::kHmac, base::Value(value));
    return *this;
}

LauncherUsage&& LauncherUsage::SetHour(const int64_t value) &&
{
    AddMetric("Hour", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

LauncherUsage& LauncherUsage::SetHour(const int64_t value) &
{
    AddMetric("Hour", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

LauncherUsage&& LauncherUsage::SetProviderType(const int64_t value) &&
{
    AddMetric("ProviderType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

LauncherUsage& LauncherUsage::SetProviderType(const int64_t value) &
{
    AddMetric("ProviderType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

LauncherUsage&& LauncherUsage::SetScore(const int64_t value) &&
{
    AddMetric("Score", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

LauncherUsage& LauncherUsage::SetScore(const int64_t value) &
{
    AddMetric("Score", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

LauncherUsage&& LauncherUsage::SetSearchQuery(const std::string& value) &&
{
    AddMetric("SearchQuery", Event::MetricType::kHmac, base::Value(value));
    return std::move(*this);
}

LauncherUsage& LauncherUsage::SetSearchQuery(const std::string& value) &
{
    AddMetric("SearchQuery", Event::MetricType::kHmac, base::Value(value));
    return *this;
}

LauncherUsage&& LauncherUsage::SetSearchQueryLength(const int64_t value) &&
{
    AddMetric("SearchQueryLength", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

LauncherUsage& LauncherUsage::SetSearchQueryLength(const int64_t value) &
{
    AddMetric("SearchQueryLength", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

LauncherUsage&& LauncherUsage::SetTarget(const std::string& value) &&
{
    AddMetric("Target", Event::MetricType::kHmac, base::Value(value));
    return std::move(*this);
}

LauncherUsage& LauncherUsage::SetTarget(const std::string& value) &
{
    AddMetric("Target", Event::MetricType::kHmac, base::Value(value));
    return *this;
}

} // namespace launcher_usage

namespace nearby_share {

Discovery::Discovery()
    : ::metrics::structured::Event("NearbyShare", "Discovery", false)
{
}
Discovery::~Discovery() = default;

Discovery&& Discovery::SetPlatform(const int64_t value) &&
{
    AddMetric("Platform", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Discovery& Discovery::SetPlatform(const int64_t value) &
{
    AddMetric("Platform", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Discovery&& Discovery::SetDeviceRelationship(const int64_t value) &&
{
    AddMetric("DeviceRelationship", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Discovery& Discovery::SetDeviceRelationship(const int64_t value) &
{
    AddMetric("DeviceRelationship", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Discovery&& Discovery::SetTimeToDiscovery(const int64_t value) &&
{
    AddMetric("TimeToDiscovery", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Discovery& Discovery::SetTimeToDiscovery(const int64_t value) &
{
    AddMetric("TimeToDiscovery", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Throughput::Throughput()
    : ::metrics::structured::Event("NearbyShare", "Throughput", false)
{
}
Throughput::~Throughput() = default;

Throughput&& Throughput::SetIsReceiving(const int64_t value) &&
{
    AddMetric("IsReceiving", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Throughput& Throughput::SetIsReceiving(const int64_t value) &
{
    AddMetric("IsReceiving", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Throughput&& Throughput::SetPlatform(const int64_t value) &&
{
    AddMetric("Platform", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Throughput& Throughput::SetPlatform(const int64_t value) &
{
    AddMetric("Platform", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Throughput&& Throughput::SetDeviceRelationship(const int64_t value) &&
{
    AddMetric("DeviceRelationship", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Throughput& Throughput::SetDeviceRelationship(const int64_t value) &
{
    AddMetric("DeviceRelationship", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Throughput&& Throughput::SetMedium(const int64_t value) &&
{
    AddMetric("Medium", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Throughput& Throughput::SetMedium(const int64_t value) &
{
    AddMetric("Medium", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Throughput&& Throughput::SetUpdateBytes(const int64_t value) &&
{
    AddMetric("UpdateBytes", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Throughput& Throughput::SetUpdateBytes(const int64_t value) &
{
    AddMetric("UpdateBytes", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Throughput&& Throughput::SetUpdateMillis(const int64_t value) &&
{
    AddMetric("UpdateMillis", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Throughput& Throughput::SetUpdateMillis(const int64_t value) &
{
    AddMetric("UpdateMillis", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Throughput&& Throughput::SetTransferredBytes(const int64_t value) &&
{
    AddMetric("TransferredBytes", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Throughput& Throughput::SetTransferredBytes(const int64_t value) &
{
    AddMetric("TransferredBytes", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Throughput&& Throughput::SetTotalTransferBytes(const int64_t value) &&
{
    AddMetric("TotalTransferBytes", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Throughput& Throughput::SetTotalTransferBytes(const int64_t value) &
{
    AddMetric("TotalTransferBytes", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

FileAttachment::FileAttachment()
    : ::metrics::structured::Event("NearbyShare", "FileAttachment", false)
{
}
FileAttachment::~FileAttachment() = default;

FileAttachment&& FileAttachment::SetIsReceiving(const int64_t value) &&
{
    AddMetric("IsReceiving", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

FileAttachment& FileAttachment::SetIsReceiving(const int64_t value) &
{
    AddMetric("IsReceiving", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

FileAttachment&& FileAttachment::SetPlatform(const int64_t value) &&
{
    AddMetric("Platform", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

FileAttachment& FileAttachment::SetPlatform(const int64_t value) &
{
    AddMetric("Platform", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

FileAttachment&& FileAttachment::SetDeviceRelationship(const int64_t value) &&
{
    AddMetric("DeviceRelationship", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

FileAttachment& FileAttachment::SetDeviceRelationship(const int64_t value) &
{
    AddMetric("DeviceRelationship", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

FileAttachment&& FileAttachment::SetFileType(const int64_t value) &&
{
    AddMetric("FileType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

FileAttachment& FileAttachment::SetFileType(const int64_t value) &
{
    AddMetric("FileType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

FileAttachment&& FileAttachment::SetSize(const int64_t value) &&
{
    AddMetric("Size", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

FileAttachment& FileAttachment::SetSize(const int64_t value) &
{
    AddMetric("Size", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

FileAttachment&& FileAttachment::SetResult(const int64_t value) &&
{
    AddMetric("Result", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

FileAttachment& FileAttachment::SetResult(const int64_t value) &
{
    AddMetric("Result", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

TextAttachment::TextAttachment()
    : ::metrics::structured::Event("NearbyShare", "TextAttachment", false)
{
}
TextAttachment::~TextAttachment() = default;

TextAttachment&& TextAttachment::SetIsReceiving(const int64_t value) &&
{
    AddMetric("IsReceiving", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

TextAttachment& TextAttachment::SetIsReceiving(const int64_t value) &
{
    AddMetric("IsReceiving", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

TextAttachment&& TextAttachment::SetPlatform(const int64_t value) &&
{
    AddMetric("Platform", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

TextAttachment& TextAttachment::SetPlatform(const int64_t value) &
{
    AddMetric("Platform", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

TextAttachment&& TextAttachment::SetDeviceRelationship(const int64_t value) &&
{
    AddMetric("DeviceRelationship", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

TextAttachment& TextAttachment::SetDeviceRelationship(const int64_t value) &
{
    AddMetric("DeviceRelationship", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

TextAttachment&& TextAttachment::SetTextType(const int64_t value) &&
{
    AddMetric("TextType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

TextAttachment& TextAttachment::SetTextType(const int64_t value) &
{
    AddMetric("TextType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

TextAttachment&& TextAttachment::SetSize(const int64_t value) &&
{
    AddMetric("Size", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

TextAttachment& TextAttachment::SetSize(const int64_t value) &
{
    AddMetric("Size", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

TextAttachment&& TextAttachment::SetResult(const int64_t value) &&
{
    AddMetric("Result", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

TextAttachment& TextAttachment::SetResult(const int64_t value) &
{
    AddMetric("Result", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession::ShareSession()
    : ::metrics::structured::Event("NearbyShare", "ShareSession", false)
{
}
ShareSession::~ShareSession() = default;

ShareSession&& ShareSession::SetIsReceiving(const int64_t value) &&
{
    AddMetric("IsReceiving", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetIsReceiving(const int64_t value) &
{
    AddMetric("IsReceiving", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetPlatform(const int64_t value) &&
{
    AddMetric("Platform", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetPlatform(const int64_t value) &
{
    AddMetric("Platform", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetDeviceRelationship(const int64_t value) &&
{
    AddMetric("DeviceRelationship", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetDeviceRelationship(const int64_t value) &
{
    AddMetric("DeviceRelationship", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetTimeToDiscovery(const int64_t value) &&
{
    AddMetric("TimeToDiscovery", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetTimeToDiscovery(const int64_t value) &
{
    AddMetric("TimeToDiscovery", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetTimeToSelect(const int64_t value) &&
{
    AddMetric("TimeToSelect", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetTimeToSelect(const int64_t value) &
{
    AddMetric("TimeToSelect", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetTimeToConnect(const int64_t value) &&
{
    AddMetric("TimeToConnect", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetTimeToConnect(const int64_t value) &
{
    AddMetric("TimeToConnect", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetTimeToAccept(const int64_t value) &&
{
    AddMetric("TimeToAccept", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetTimeToAccept(const int64_t value) &
{
    AddMetric("TimeToAccept", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetTimeToTransferComplete(const int64_t value) &&
{
    AddMetric("TimeToTransferComplete", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetTimeToTransferComplete(const int64_t value) &
{
    AddMetric("TimeToTransferComplete", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetInitialMedium(const int64_t value) &&
{
    AddMetric("InitialMedium", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetInitialMedium(const int64_t value) &
{
    AddMetric("InitialMedium", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetTimeToUpgrade(const int64_t value) &&
{
    AddMetric("TimeToUpgrade", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetTimeToUpgrade(const int64_t value) &
{
    AddMetric("TimeToUpgrade", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetFinalMedium(const int64_t value) &&
{
    AddMetric("FinalMedium", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetFinalMedium(const int64_t value) &
{
    AddMetric("FinalMedium", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetNumberOfFiles(const int64_t value) &&
{
    AddMetric("NumberOfFiles", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetNumberOfFiles(const int64_t value) &
{
    AddMetric("NumberOfFiles", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetNumberOfTexts(const int64_t value) &&
{
    AddMetric("NumberOfTexts", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetNumberOfTexts(const int64_t value) &
{
    AddMetric("NumberOfTexts", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetNumberOfWiFiCredentials(const int64_t value) &&
{
    AddMetric("NumberOfWiFiCredentials", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetNumberOfWiFiCredentials(const int64_t value) &
{
    AddMetric("NumberOfWiFiCredentials", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetTotalTransferBytes(const int64_t value) &&
{
    AddMetric("TotalTransferBytes", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetTotalTransferBytes(const int64_t value) &
{
    AddMetric("TotalTransferBytes", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetBytesTransferred(const int64_t value) &&
{
    AddMetric("BytesTransferred", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetBytesTransferred(const int64_t value) &
{
    AddMetric("BytesTransferred", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

ShareSession&& ShareSession::SetResult(const int64_t value) &&
{
    AddMetric("Result", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

ShareSession& ShareSession::SetResult(const int64_t value) &
{
    AddMetric("Result", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

} // namespace nearby_share

namespace phone_hub {

SessionDetails::SessionDetails()
    : ::metrics::structured::Event("PhoneHub", "SessionDetails", false)
{
}
SessionDetails::~SessionDetails() = default;

SessionDetails&& SessionDetails::SetSessionId(const std::string& value) &&
{
    AddMetric("SessionId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetSessionId(const std::string& value) &
{
    AddMetric("SessionId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

SessionDetails&& SessionDetails::SetTimestamp(const int64_t value) &&
{
    AddMetric("Timestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetTimestamp(const int64_t value) &
{
    AddMetric("Timestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SessionDetails&& SessionDetails::SetConnectionMedium(const int64_t value) &&
{
    AddMetric("ConnectionMedium", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetConnectionMedium(const int64_t value) &
{
    AddMetric("ConnectionMedium", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SessionDetails&& SessionDetails::SetChromebookBluetoothStack(const int64_t value) &&
{
    AddMetric("ChromebookBluetoothStack", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetChromebookBluetoothStack(const int64_t value) &
{
    AddMetric("ChromebookBluetoothStack", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SessionDetails&& SessionDetails::SetDevicesNetworkState(const int64_t value) &&
{
    AddMetric("DevicesNetworkState", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetDevicesNetworkState(const int64_t value) &
{
    AddMetric("DevicesNetworkState", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SessionDetails&& SessionDetails::SetChromebookLocale(const std::string& value) &&
{
    AddMetric("ChromebookLocale", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetChromebookLocale(const std::string& value) &
{
    AddMetric("ChromebookLocale", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

SessionDetails&& SessionDetails::SetChromebookPseudonymousId(const std::string& value) &&
{
    AddMetric("ChromebookPseudonymousId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetChromebookPseudonymousId(const std::string& value) &
{
    AddMetric("ChromebookPseudonymousId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

SessionDetails&& SessionDetails::SetPhoneManufacturer(const std::string& value) &&
{
    AddMetric("PhoneManufacturer", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetPhoneManufacturer(const std::string& value) &
{
    AddMetric("PhoneManufacturer", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

SessionDetails&& SessionDetails::SetPhoneModel(const std::string& value) &&
{
    AddMetric("PhoneModel", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetPhoneModel(const std::string& value) &
{
    AddMetric("PhoneModel", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

SessionDetails&& SessionDetails::SetPhoneAndroidVersion(const int64_t value) &&
{
    AddMetric("PhoneAndroidVersion", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetPhoneAndroidVersion(const int64_t value) &
{
    AddMetric("PhoneAndroidVersion", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SessionDetails&& SessionDetails::SetPhoneAmbientApkVersion(const int64_t value) &&
{
    AddMetric("PhoneAmbientApkVersion", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetPhoneAmbientApkVersion(const int64_t value) &
{
    AddMetric("PhoneAmbientApkVersion", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SessionDetails&& SessionDetails::SetPhoneGmsCoreVersion(const int64_t value) &&
{
    AddMetric("PhoneGmsCoreVersion", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetPhoneGmsCoreVersion(const int64_t value) &
{
    AddMetric("PhoneGmsCoreVersion", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SessionDetails&& SessionDetails::SetPhoneProfile(const int64_t value) &&
{
    AddMetric("PhoneProfile", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetPhoneProfile(const int64_t value) &
{
    AddMetric("PhoneProfile", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SessionDetails&& SessionDetails::SetPhoneNetworkStatus(const int64_t value) &&
{
    AddMetric("PhoneNetworkStatus", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetPhoneNetworkStatus(const int64_t value) &
{
    AddMetric("PhoneNetworkStatus", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SessionDetails&& SessionDetails::SetPhoneLocale(const std::string& value) &&
{
    AddMetric("PhoneLocale", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetPhoneLocale(const std::string& value) &
{
    AddMetric("PhoneLocale", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

SessionDetails&& SessionDetails::SetPhonePseudonymousId(const std::string& value) &&
{
    AddMetric("PhonePseudonymousId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetPhonePseudonymousId(const std::string& value) &
{
    AddMetric("PhonePseudonymousId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

SessionDetails&& SessionDetails::SetPhoneInfoLastUpdatedTimestamp(const int64_t value) &&
{
    AddMetric("PhoneInfoLastUpdatedTimestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionDetails& SessionDetails::SetPhoneInfoLastUpdatedTimestamp(const int64_t value) &
{
    AddMetric("PhoneInfoLastUpdatedTimestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

DiscoveryStarted::DiscoveryStarted()
    : ::metrics::structured::Event("PhoneHub", "DiscoveryStarted", false)
{
}
DiscoveryStarted::~DiscoveryStarted() = default;

DiscoveryStarted&& DiscoveryStarted::SetSessionId(const std::string& value) &&
{
    AddMetric("SessionId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

DiscoveryStarted& DiscoveryStarted::SetSessionId(const std::string& value) &
{
    AddMetric("SessionId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

DiscoveryStarted&& DiscoveryStarted::SetTimestamp(const int64_t value) &&
{
    AddMetric("Timestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

DiscoveryStarted& DiscoveryStarted::SetTimestamp(const int64_t value) &
{
    AddMetric("Timestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

DiscoveryStarted&& DiscoveryStarted::SetDiscoveryEntrypoint(const int64_t value) &&
{
    AddMetric("DiscoveryEntrypoint", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

DiscoveryStarted& DiscoveryStarted::SetDiscoveryEntrypoint(const int64_t value) &
{
    AddMetric("DiscoveryEntrypoint", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

DiscoveryFinished::DiscoveryFinished()
    : ::metrics::structured::Event("PhoneHub", "DiscoveryFinished", false)
{
}
DiscoveryFinished::~DiscoveryFinished() = default;

DiscoveryFinished&& DiscoveryFinished::SetSessionId(const std::string& value) &&
{
    AddMetric("SessionId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

DiscoveryFinished& DiscoveryFinished::SetSessionId(const std::string& value) &
{
    AddMetric("SessionId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

DiscoveryFinished&& DiscoveryFinished::SetTimestamp(const int64_t value) &&
{
    AddMetric("Timestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

DiscoveryFinished& DiscoveryFinished::SetTimestamp(const int64_t value) &
{
    AddMetric("Timestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

DiscoveryFinished&& DiscoveryFinished::SetDiscoeryResult(const int64_t value) &&
{
    AddMetric("DiscoeryResult", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

DiscoveryFinished& DiscoveryFinished::SetDiscoeryResult(const int64_t value) &
{
    AddMetric("DiscoeryResult", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

DiscoveryFinished&& DiscoveryFinished::SetDiscoveryResultErrorCode(const int64_t value) &&
{
    AddMetric("DiscoveryResultErrorCode", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

DiscoveryFinished& DiscoveryFinished::SetDiscoveryResultErrorCode(const int64_t value) &
{
    AddMetric("DiscoveryResultErrorCode", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

NearbyConnection::NearbyConnection()
    : ::metrics::structured::Event("PhoneHub", "NearbyConnection", false)
{
}
NearbyConnection::~NearbyConnection() = default;

NearbyConnection&& NearbyConnection::SetSessionId(const std::string& value) &&
{
    AddMetric("SessionId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

NearbyConnection& NearbyConnection::SetSessionId(const std::string& value) &
{
    AddMetric("SessionId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

NearbyConnection&& NearbyConnection::SetTimestamp(const int64_t value) &&
{
    AddMetric("Timestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

NearbyConnection& NearbyConnection::SetTimestamp(const int64_t value) &
{
    AddMetric("Timestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

NearbyConnection&& NearbyConnection::SetNearbyConnectionStep(const int64_t value) &&
{
    AddMetric("NearbyConnectionStep", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

NearbyConnection& NearbyConnection::SetNearbyConnectionStep(const int64_t value) &
{
    AddMetric("NearbyConnectionStep", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

NearbyConnection&& NearbyConnection::SetNearbyConnectionStepResult(const int64_t value) &&
{
    AddMetric("NearbyConnectionStepResult", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

NearbyConnection& NearbyConnection::SetNearbyConnectionStepResult(const int64_t value) &
{
    AddMetric("NearbyConnectionStepResult", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SecureChannelAuthentication::SecureChannelAuthentication()
    : ::metrics::structured::Event("PhoneHub", "SecureChannelAuthentication", false)
{
}
SecureChannelAuthentication::~SecureChannelAuthentication() = default;

SecureChannelAuthentication&& SecureChannelAuthentication::SetSessionId(const std::string& value) &&
{
    AddMetric("SessionId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

SecureChannelAuthentication& SecureChannelAuthentication::SetSessionId(const std::string& value) &
{
    AddMetric("SessionId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

SecureChannelAuthentication&& SecureChannelAuthentication::SetTimestamp(const int64_t value) &&
{
    AddMetric("Timestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SecureChannelAuthentication& SecureChannelAuthentication::SetTimestamp(const int64_t value) &
{
    AddMetric("Timestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SecureChannelAuthentication&& SecureChannelAuthentication::SetSecureChannelAuthenticationState(const int64_t value) &&
{
    AddMetric("SecureChannelAuthenticationState", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SecureChannelAuthentication& SecureChannelAuthentication::SetSecureChannelAuthenticationState(const int64_t value) &
{
    AddMetric("SecureChannelAuthenticationState", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PhoneHubMessage::PhoneHubMessage()
    : ::metrics::structured::Event("PhoneHub", "PhoneHubMessage", false)
{
}
PhoneHubMessage::~PhoneHubMessage() = default;

PhoneHubMessage&& PhoneHubMessage::SetSessionId(const std::string& value) &&
{
    AddMetric("SessionId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

PhoneHubMessage& PhoneHubMessage::SetSessionId(const std::string& value) &
{
    AddMetric("SessionId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

PhoneHubMessage&& PhoneHubMessage::SetTimestamp(const int64_t value) &&
{
    AddMetric("Timestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PhoneHubMessage& PhoneHubMessage::SetTimestamp(const int64_t value) &
{
    AddMetric("Timestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PhoneHubMessage&& PhoneHubMessage::SetPhoneHubMessageType(const int64_t value) &&
{
    AddMetric("PhoneHubMessageType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PhoneHubMessage& PhoneHubMessage::SetPhoneHubMessageType(const int64_t value) &
{
    AddMetric("PhoneHubMessageType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PhoneHubMessage&& PhoneHubMessage::SetPhoneHubMessageDirection(const int64_t value) &&
{
    AddMetric("PhoneHubMessageDirection", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PhoneHubMessage& PhoneHubMessage::SetPhoneHubMessageDirection(const int64_t value) &
{
    AddMetric("PhoneHubMessageDirection", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PhoneHubUiUpdate::PhoneHubUiUpdate()
    : ::metrics::structured::Event("PhoneHub", "PhoneHubUiUpdate", false)
{
}
PhoneHubUiUpdate::~PhoneHubUiUpdate() = default;

PhoneHubUiUpdate&& PhoneHubUiUpdate::SetSessionId(const std::string& value) &&
{
    AddMetric("SessionId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

PhoneHubUiUpdate& PhoneHubUiUpdate::SetSessionId(const std::string& value) &
{
    AddMetric("SessionId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

PhoneHubUiUpdate&& PhoneHubUiUpdate::SetTimestamp(const int64_t value) &&
{
    AddMetric("Timestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PhoneHubUiUpdate& PhoneHubUiUpdate::SetTimestamp(const int64_t value) &
{
    AddMetric("Timestamp", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

PhoneHubUiUpdate&& PhoneHubUiUpdate::SetPhoneHubUiState(const int64_t value) &&
{
    AddMetric("PhoneHubUiState", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

PhoneHubUiUpdate& PhoneHubUiUpdate::SetPhoneHubUiState(const int64_t value) &
{
    AddMetric("PhoneHubUiState", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

} // namespace phone_hub

namespace structured_metrics {

Initialization::Initialization()
    : ::metrics::structured::Event("StructuredMetrics", "Initialization", false)
{
}
Initialization::~Initialization() = default;

Initialization&& Initialization::SetPlatform(const int64_t value) &&
{
    AddMetric("Platform", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Initialization& Initialization::SetPlatform(const int64_t value) &
{
    AddMetric("Platform", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

} // namespace structured_metrics

namespace cr_os_events {

AppDiscovery_AppInstalled::AppDiscovery_AppInstalled()
    : ::metrics::structured::Event("CrOSEvents", "AppDiscovery_AppInstalled", true)
{
}
AppDiscovery_AppInstalled::~AppDiscovery_AppInstalled() = default;

AppDiscovery_AppInstalled&& AppDiscovery_AppInstalled::SetAppId(const std::string& value) &&
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

AppDiscovery_AppInstalled& AppDiscovery_AppInstalled::SetAppId(const std::string& value) &
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

AppDiscovery_AppInstalled&& AppDiscovery_AppInstalled::SetAppType(const int64_t value) &&
{
    AddMetric("AppType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

AppDiscovery_AppInstalled& AppDiscovery_AppInstalled::SetAppType(const int64_t value) &
{
    AddMetric("AppType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

AppDiscovery_AppInstalled&& AppDiscovery_AppInstalled::SetInstallSource(const int64_t value) &&
{
    AddMetric("InstallSource", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

AppDiscovery_AppInstalled& AppDiscovery_AppInstalled::SetInstallSource(const int64_t value) &
{
    AddMetric("InstallSource", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

AppDiscovery_AppInstalled&& AppDiscovery_AppInstalled::SetInstallReason(const int64_t value) &&
{
    AddMetric("InstallReason", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

AppDiscovery_AppInstalled& AppDiscovery_AppInstalled::SetInstallReason(const int64_t value) &
{
    AddMetric("InstallReason", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

AppDiscovery_AppInstallService_InstallRequested::AppDiscovery_AppInstallService_InstallRequested()
    : ::metrics::structured::Event("CrOSEvents", "AppDiscovery_AppInstallService_InstallRequested", true)
{
}
AppDiscovery_AppInstallService_InstallRequested::~AppDiscovery_AppInstallService_InstallRequested() = default;

AppDiscovery_AppInstallService_InstallRequested&& AppDiscovery_AppInstallService_InstallRequested::SetAppId(const std::string& value) &&
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

AppDiscovery_AppInstallService_InstallRequested& AppDiscovery_AppInstallService_InstallRequested::SetAppId(const std::string& value) &
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

AppDiscovery_AppInstallService_InstallRequested&& AppDiscovery_AppInstallService_InstallRequested::SetSurface(const AppInstallSurface value) &&
{
    AddMetric("Surface", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

AppDiscovery_AppInstallService_InstallRequested& AppDiscovery_AppInstallService_InstallRequested::SetSurface(const AppInstallSurface value) &
{
    AddMetric("Surface", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

AppDiscovery_AppLaunched::AppDiscovery_AppLaunched()
    : ::metrics::structured::Event("CrOSEvents", "AppDiscovery_AppLaunched", true)
{
}
AppDiscovery_AppLaunched::~AppDiscovery_AppLaunched() = default;

AppDiscovery_AppLaunched&& AppDiscovery_AppLaunched::SetAppId(const std::string& value) &&
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

AppDiscovery_AppLaunched& AppDiscovery_AppLaunched::SetAppId(const std::string& value) &
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

AppDiscovery_AppLaunched&& AppDiscovery_AppLaunched::SetAppType(const int64_t value) &&
{
    AddMetric("AppType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

AppDiscovery_AppLaunched& AppDiscovery_AppLaunched::SetAppType(const int64_t value) &
{
    AddMetric("AppType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

AppDiscovery_AppLaunched&& AppDiscovery_AppLaunched::SetLaunchSource(const int64_t value) &&
{
    AddMetric("LaunchSource", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

AppDiscovery_AppLaunched& AppDiscovery_AppLaunched::SetLaunchSource(const int64_t value) &
{
    AddMetric("LaunchSource", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

AppDiscovery_AppUninstall::AppDiscovery_AppUninstall()
    : ::metrics::structured::Event("CrOSEvents", "AppDiscovery_AppUninstall", true)
{
}
AppDiscovery_AppUninstall::~AppDiscovery_AppUninstall() = default;

AppDiscovery_AppUninstall&& AppDiscovery_AppUninstall::SetAppId(const std::string& value) &&
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

AppDiscovery_AppUninstall& AppDiscovery_AppUninstall::SetAppId(const std::string& value) &
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

AppDiscovery_AppUninstall&& AppDiscovery_AppUninstall::SetAppType(const int64_t value) &&
{
    AddMetric("AppType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

AppDiscovery_AppUninstall& AppDiscovery_AppUninstall::SetAppType(const int64_t value) &
{
    AddMetric("AppType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

AppDiscovery_AppUninstall&& AppDiscovery_AppUninstall::SetUninstallSource(const int64_t value) &&
{
    AddMetric("UninstallSource", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

AppDiscovery_AppUninstall& AppDiscovery_AppUninstall::SetUninstallSource(const int64_t value) &
{
    AddMetric("UninstallSource", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

AppDiscovery_AppStateChanged::AppDiscovery_AppStateChanged()
    : ::metrics::structured::Event("CrOSEvents", "AppDiscovery_AppStateChanged", true)
{
}
AppDiscovery_AppStateChanged::~AppDiscovery_AppStateChanged() = default;

AppDiscovery_AppStateChanged&& AppDiscovery_AppStateChanged::SetAppId(const std::string& value) &&
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

AppDiscovery_AppStateChanged& AppDiscovery_AppStateChanged::SetAppId(const std::string& value) &
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

AppDiscovery_AppStateChanged&& AppDiscovery_AppStateChanged::SetAppState(const int64_t value) &&
{
    AddMetric("AppState", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

AppDiscovery_AppStateChanged& AppDiscovery_AppStateChanged::SetAppState(const int64_t value) &
{
    AddMetric("AppState", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

AppDiscovery_ArcAppCameraAccessed::AppDiscovery_ArcAppCameraAccessed()
    : ::metrics::structured::Event("CrOSEvents", "AppDiscovery_ArcAppCameraAccessed", true)
{
}
AppDiscovery_ArcAppCameraAccessed::~AppDiscovery_ArcAppCameraAccessed() = default;

AppDiscovery_ArcAppCameraAccessed&& AppDiscovery_ArcAppCameraAccessed::SetAppId(const std::string& value) &&
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

AppDiscovery_ArcAppCameraAccessed& AppDiscovery_ArcAppCameraAccessed::SetAppId(const std::string& value) &
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

AppDiscovery_LauncherOpen::AppDiscovery_LauncherOpen()
    : ::metrics::structured::Event("CrOSEvents", "AppDiscovery_LauncherOpen", true)
{
}
AppDiscovery_LauncherOpen::~AppDiscovery_LauncherOpen() = default;

AppDiscovery_AppLauncherResultOpened::AppDiscovery_AppLauncherResultOpened()
    : ::metrics::structured::Event("CrOSEvents", "AppDiscovery_AppLauncherResultOpened", true)
{
}
AppDiscovery_AppLauncherResultOpened::~AppDiscovery_AppLauncherResultOpened() = default;

AppDiscovery_AppLauncherResultOpened&& AppDiscovery_AppLauncherResultOpened::SetFuzzyStringMatch(const double value) &&
{
    AddMetric("FuzzyStringMatch", Event::MetricType::kDouble, base::Value(value));
    return std::move(*this);
}

AppDiscovery_AppLauncherResultOpened& AppDiscovery_AppLauncherResultOpened::SetFuzzyStringMatch(const double value) &
{
    AddMetric("FuzzyStringMatch", Event::MetricType::kDouble, base::Value(value));
    return *this;
}

AppDiscovery_AppLauncherResultOpened&& AppDiscovery_AppLauncherResultOpened::SetAppId(const std::string& value) &&
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

AppDiscovery_AppLauncherResultOpened& AppDiscovery_AppLauncherResultOpened::SetAppId(const std::string& value) &
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

AppDiscovery_AppLauncherResultOpened&& AppDiscovery_AppLauncherResultOpened::SetAppName(const std::string& value) &&
{
    AddMetric("AppName", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

AppDiscovery_AppLauncherResultOpened& AppDiscovery_AppLauncherResultOpened::SetAppName(const std::string& value) &
{
    AddMetric("AppName", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

AppDiscovery_AppLauncherResultOpened&& AppDiscovery_AppLauncherResultOpened::SetResultCategory(const int64_t value) &&
{
    AddMetric("ResultCategory", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

AppDiscovery_AppLauncherResultOpened& AppDiscovery_AppLauncherResultOpened::SetResultCategory(const int64_t value) &
{
    AddMetric("ResultCategory", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

AppDiscovery_Browser_OmniboxInstallIconClicked::AppDiscovery_Browser_OmniboxInstallIconClicked()
    : ::metrics::structured::Event("CrOSEvents", "AppDiscovery_Browser_OmniboxInstallIconClicked", true)
{
}
AppDiscovery_Browser_OmniboxInstallIconClicked::~AppDiscovery_Browser_OmniboxInstallIconClicked() = default;

AppDiscovery_Browser_OmniboxInstallIconClicked&& AppDiscovery_Browser_OmniboxInstallIconClicked::SetIPHShown(const int64_t value) &&
{
    AddMetric("IPHShown", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

AppDiscovery_Browser_OmniboxInstallIconClicked& AppDiscovery_Browser_OmniboxInstallIconClicked::SetIPHShown(const int64_t value) &
{
    AddMetric("IPHShown", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

AppDiscovery_Browser_AppInstallDialogShown::AppDiscovery_Browser_AppInstallDialogShown()
    : ::metrics::structured::Event("CrOSEvents", "AppDiscovery_Browser_AppInstallDialogShown", true)
{
}
AppDiscovery_Browser_AppInstallDialogShown::~AppDiscovery_Browser_AppInstallDialogShown() = default;

AppDiscovery_Browser_AppInstallDialogShown&& AppDiscovery_Browser_AppInstallDialogShown::SetAppId(const std::string& value) &&
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

AppDiscovery_Browser_AppInstallDialogShown& AppDiscovery_Browser_AppInstallDialogShown::SetAppId(const std::string& value) &
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

AppDiscovery_Browser_AppInstallDialogResult::AppDiscovery_Browser_AppInstallDialogResult()
    : ::metrics::structured::Event("CrOSEvents", "AppDiscovery_Browser_AppInstallDialogResult", true)
{
}
AppDiscovery_Browser_AppInstallDialogResult::~AppDiscovery_Browser_AppInstallDialogResult() = default;

AppDiscovery_Browser_AppInstallDialogResult&& AppDiscovery_Browser_AppInstallDialogResult::SetWebAppInstallStatus(const int64_t value) &&
{
    AddMetric("WebAppInstallStatus", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

AppDiscovery_Browser_AppInstallDialogResult& AppDiscovery_Browser_AppInstallDialogResult::SetWebAppInstallStatus(const int64_t value) &
{
    AddMetric("WebAppInstallStatus", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

AppDiscovery_Browser_AppInstallDialogResult&& AppDiscovery_Browser_AppInstallDialogResult::SetAppId(const std::string& value) &&
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

AppDiscovery_Browser_AppInstallDialogResult& AppDiscovery_Browser_AppInstallDialogResult::SetAppId(const std::string& value) &
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

AppDiscovery_Browser_ClickInstallAppFromMenu::AppDiscovery_Browser_ClickInstallAppFromMenu()
    : ::metrics::structured::Event("CrOSEvents", "AppDiscovery_Browser_ClickInstallAppFromMenu", true)
{
}
AppDiscovery_Browser_ClickInstallAppFromMenu::~AppDiscovery_Browser_ClickInstallAppFromMenu() = default;

AppDiscovery_Browser_ClickInstallAppFromMenu&& AppDiscovery_Browser_ClickInstallAppFromMenu::SetAppId(const std::string& value) &&
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

AppDiscovery_Browser_ClickInstallAppFromMenu& AppDiscovery_Browser_ClickInstallAppFromMenu::SetAppId(const std::string& value) &
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

AppDiscovery_Browser_CreateShortcut::AppDiscovery_Browser_CreateShortcut()
    : ::metrics::structured::Event("CrOSEvents", "AppDiscovery_Browser_CreateShortcut", true)
{
}
AppDiscovery_Browser_CreateShortcut::~AppDiscovery_Browser_CreateShortcut() = default;

AppDiscovery_Browser_CreateShortcut&& AppDiscovery_Browser_CreateShortcut::SetAppId(const std::string& value) &&
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

AppDiscovery_Browser_CreateShortcut& AppDiscovery_Browser_CreateShortcut::SetAppId(const std::string& value) &
{
    AddMetric("AppId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

CameraApp_StartSession::CameraApp_StartSession()
    : ::metrics::structured::Event("CrOSEvents", "CameraApp_StartSession", true)
{
}
CameraApp_StartSession::~CameraApp_StartSession() = default;

CameraApp_StartSession&& CameraApp_StartSession::SetLaunchType(const CameraAppLaunchType value) &&
{
    AddMetric("LaunchType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_StartSession& CameraApp_StartSession::SetLaunchType(const CameraAppLaunchType value) &
{
    AddMetric("LaunchType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_StartSession&& CameraApp_StartSession::SetLanguage(const int64_t value) &&
{
    AddMetric("Language", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_StartSession& CameraApp_StartSession::SetLanguage(const int64_t value) &
{
    AddMetric("Language", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Capture::CameraApp_Capture()
    : ::metrics::structured::Event("CrOSEvents", "CameraApp_Capture", true)
{
}
CameraApp_Capture::~CameraApp_Capture() = default;

CameraApp_Capture&& CameraApp_Capture::SetMode(const CameraAppMode value) &&
{
    AddMetric("Mode", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetMode(const CameraAppMode value) &
{
    AddMetric("Mode", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetFacing(const CameraAppFacing value) &&
{
    AddMetric("Facing", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetFacing(const CameraAppFacing value) &
{
    AddMetric("Facing", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetIsMirrored(const int64_t value) &&
{
    AddMetric("IsMirrored", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetIsMirrored(const int64_t value) &
{
    AddMetric("IsMirrored", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetGridType(const CameraAppGridType value) &&
{
    AddMetric("GridType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetGridType(const CameraAppGridType value) &
{
    AddMetric("GridType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetTimerType(const CameraAppTimerType value) &&
{
    AddMetric("TimerType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetTimerType(const CameraAppTimerType value) &
{
    AddMetric("TimerType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetShutterType(const CameraAppShutterType value) &&
{
    AddMetric("ShutterType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetShutterType(const CameraAppShutterType value) &
{
    AddMetric("ShutterType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetAndroidIntentResultType(const CameraAppAndroidIntentResultType value) &&
{
    AddMetric("AndroidIntentResultType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetAndroidIntentResultType(const CameraAppAndroidIntentResultType value) &
{
    AddMetric("AndroidIntentResultType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetIsWindowMaximized(const int64_t value) &&
{
    AddMetric("IsWindowMaximized", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetIsWindowMaximized(const int64_t value) &
{
    AddMetric("IsWindowMaximized", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetIsWindowPortrait(const int64_t value) &&
{
    AddMetric("IsWindowPortrait", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetIsWindowPortrait(const int64_t value) &
{
    AddMetric("IsWindowPortrait", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetResolutionWidth(const int64_t value) &&
{
    AddMetric("ResolutionWidth", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetResolutionWidth(const int64_t value) &
{
    AddMetric("ResolutionWidth", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetResolutionHeight(const int64_t value) &&
{
    AddMetric("ResolutionHeight", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetResolutionHeight(const int64_t value) &
{
    AddMetric("ResolutionHeight", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetResolutionLevel(const CameraAppResolutionLevel value) &&
{
    AddMetric("ResolutionLevel", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetResolutionLevel(const CameraAppResolutionLevel value) &
{
    AddMetric("ResolutionLevel", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetAspectRatioSet(const CameraAppAspectRatioSet value) &&
{
    AddMetric("AspectRatioSet", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetAspectRatioSet(const CameraAppAspectRatioSet value) &
{
    AddMetric("AspectRatioSet", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetIsVideoSnapshot(const int64_t value) &&
{
    AddMetric("IsVideoSnapshot", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetIsVideoSnapshot(const int64_t value) &
{
    AddMetric("IsVideoSnapshot", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetIsMuted(const int64_t value) &&
{
    AddMetric("IsMuted", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetIsMuted(const int64_t value) &
{
    AddMetric("IsMuted", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetFps(const int64_t value) &&
{
    AddMetric("Fps", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetFps(const int64_t value) &
{
    AddMetric("Fps", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetEverPaused(const int64_t value) &&
{
    AddMetric("EverPaused", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetEverPaused(const int64_t value) &
{
    AddMetric("EverPaused", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetDuration(const int64_t value) &&
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetDuration(const int64_t value) &
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetRecordType(const CameraAppRecordType value) &&
{
    AddMetric("RecordType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetRecordType(const CameraAppRecordType value) &
{
    AddMetric("RecordType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetGifResultType(const CameraAppGifResultType value) &&
{
    AddMetric("GifResultType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetGifResultType(const CameraAppGifResultType value) &
{
    AddMetric("GifResultType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetTimelapseSpeed(const int64_t value) &&
{
    AddMetric("TimelapseSpeed", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetTimelapseSpeed(const int64_t value) &
{
    AddMetric("TimelapseSpeed", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Capture&& CameraApp_Capture::SetZoomRatio(const double value) &&
{
    AddMetric("ZoomRatio", Event::MetricType::kDouble, base::Value(value));
    return std::move(*this);
}

CameraApp_Capture& CameraApp_Capture::SetZoomRatio(const double value) &
{
    AddMetric("ZoomRatio", Event::MetricType::kDouble, base::Value(value));
    return *this;
}

CameraApp_AndroidIntent::CameraApp_AndroidIntent()
    : ::metrics::structured::Event("CrOSEvents", "CameraApp_AndroidIntent", true)
{
}
CameraApp_AndroidIntent::~CameraApp_AndroidIntent() = default;

CameraApp_AndroidIntent&& CameraApp_AndroidIntent::SetMode(const CameraAppMode value) &&
{
    AddMetric("Mode", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_AndroidIntent& CameraApp_AndroidIntent::SetMode(const CameraAppMode value) &
{
    AddMetric("Mode", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_AndroidIntent&& CameraApp_AndroidIntent::SetShouldHandleResult(const int64_t value) &&
{
    AddMetric("ShouldHandleResult", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_AndroidIntent& CameraApp_AndroidIntent::SetShouldHandleResult(const int64_t value) &
{
    AddMetric("ShouldHandleResult", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_AndroidIntent&& CameraApp_AndroidIntent::SetShouldDownscale(const int64_t value) &&
{
    AddMetric("ShouldDownscale", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_AndroidIntent& CameraApp_AndroidIntent::SetShouldDownscale(const int64_t value) &
{
    AddMetric("ShouldDownscale", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_AndroidIntent&& CameraApp_AndroidIntent::SetIsSecure(const int64_t value) &&
{
    AddMetric("IsSecure", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_AndroidIntent& CameraApp_AndroidIntent::SetIsSecure(const int64_t value) &
{
    AddMetric("IsSecure", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_OpenPTZPanel::CameraApp_OpenPTZPanel()
    : ::metrics::structured::Event("CrOSEvents", "CameraApp_OpenPTZPanel", true)
{
}
CameraApp_OpenPTZPanel::~CameraApp_OpenPTZPanel() = default;

CameraApp_OpenPTZPanel&& CameraApp_OpenPTZPanel::SetSupportPan(const int64_t value) &&
{
    AddMetric("SupportPan", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_OpenPTZPanel& CameraApp_OpenPTZPanel::SetSupportPan(const int64_t value) &
{
    AddMetric("SupportPan", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_OpenPTZPanel&& CameraApp_OpenPTZPanel::SetSupportTilt(const int64_t value) &&
{
    AddMetric("SupportTilt", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_OpenPTZPanel& CameraApp_OpenPTZPanel::SetSupportTilt(const int64_t value) &
{
    AddMetric("SupportTilt", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_OpenPTZPanel&& CameraApp_OpenPTZPanel::SetSupportZoom(const int64_t value) &&
{
    AddMetric("SupportZoom", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_OpenPTZPanel& CameraApp_OpenPTZPanel::SetSupportZoom(const int64_t value) &
{
    AddMetric("SupportZoom", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_DocScanAction::CameraApp_DocScanAction()
    : ::metrics::structured::Event("CrOSEvents", "CameraApp_DocScanAction", true)
{
}
CameraApp_DocScanAction::~CameraApp_DocScanAction() = default;

CameraApp_DocScanAction&& CameraApp_DocScanAction::SetActionType(const CameraAppDocScanActionType value) &&
{
    AddMetric("ActionType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_DocScanAction& CameraApp_DocScanAction::SetActionType(const CameraAppDocScanActionType value) &
{
    AddMetric("ActionType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_DocScanResult::CameraApp_DocScanResult()
    : ::metrics::structured::Event("CrOSEvents", "CameraApp_DocScanResult", true)
{
}
CameraApp_DocScanResult::~CameraApp_DocScanResult() = default;

CameraApp_DocScanResult&& CameraApp_DocScanResult::SetResultType(const CameraAppDocScanResultType value) &&
{
    AddMetric("ResultType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_DocScanResult& CameraApp_DocScanResult::SetResultType(const CameraAppDocScanResultType value) &
{
    AddMetric("ResultType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_DocScanResult&& CameraApp_DocScanResult::SetFixTypes(const int64_t value) &&
{
    AddMetric("FixTypes", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_DocScanResult& CameraApp_DocScanResult::SetFixTypes(const int64_t value) &
{
    AddMetric("FixTypes", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_DocScanResult&& CameraApp_DocScanResult::SetFixCount(const int64_t value) &&
{
    AddMetric("FixCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_DocScanResult& CameraApp_DocScanResult::SetFixCount(const int64_t value) &
{
    AddMetric("FixCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_DocScanResult&& CameraApp_DocScanResult::SetPageCount(const int64_t value) &&
{
    AddMetric("PageCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_DocScanResult& CameraApp_DocScanResult::SetPageCount(const int64_t value) &
{
    AddMetric("PageCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_OpenCamera::CameraApp_OpenCamera()
    : ::metrics::structured::Event("CrOSEvents", "CameraApp_OpenCamera", true)
{
}
CameraApp_OpenCamera::~CameraApp_OpenCamera() = default;

CameraApp_OpenCamera&& CameraApp_OpenCamera::SetCameraModuleId(const std::string& value) &&
{
    AddMetric("CameraModuleId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

CameraApp_OpenCamera& CameraApp_OpenCamera::SetCameraModuleId(const std::string& value) &
{
    AddMetric("CameraModuleId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

CameraApp_LowStorageAction::CameraApp_LowStorageAction()
    : ::metrics::structured::Event("CrOSEvents", "CameraApp_LowStorageAction", true)
{
}
CameraApp_LowStorageAction::~CameraApp_LowStorageAction() = default;

CameraApp_LowStorageAction&& CameraApp_LowStorageAction::SetActionType(const CameraAppLowStorageActionType value) &&
{
    AddMetric("ActionType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_LowStorageAction& CameraApp_LowStorageAction::SetActionType(const CameraAppLowStorageActionType value) &
{
    AddMetric("ActionType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_BarcodeDetected::CameraApp_BarcodeDetected()
    : ::metrics::structured::Event("CrOSEvents", "CameraApp_BarcodeDetected", true)
{
}
CameraApp_BarcodeDetected::~CameraApp_BarcodeDetected() = default;

CameraApp_BarcodeDetected&& CameraApp_BarcodeDetected::SetContentType(const CameraAppBarcodeContentType value) &&
{
    AddMetric("ContentType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_BarcodeDetected& CameraApp_BarcodeDetected::SetContentType(const CameraAppBarcodeContentType value) &
{
    AddMetric("ContentType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_BarcodeDetected&& CameraApp_BarcodeDetected::SetWifiSecurityType(const CameraAppWifiSecurityType value) &&
{
    AddMetric("WifiSecurityType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_BarcodeDetected& CameraApp_BarcodeDetected::SetWifiSecurityType(const CameraAppWifiSecurityType value) &
{
    AddMetric("WifiSecurityType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_Perf::CameraApp_Perf()
    : ::metrics::structured::Event("CrOSEvents", "CameraApp_Perf", true)
{
}
CameraApp_Perf::~CameraApp_Perf() = default;

CameraApp_Perf&& CameraApp_Perf::SetEventType(const CameraAppPerfEventType value) &&
{
    AddMetric("EventType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_Perf& CameraApp_Perf::SetEventType(const CameraAppPerfEventType value) &
{
    AddMetric("EventType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_Perf&& CameraApp_Perf::SetDuration(const int64_t value) &&
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Perf& CameraApp_Perf::SetDuration(const int64_t value) &
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Perf&& CameraApp_Perf::SetFacing(const CameraAppFacing value) &&
{
    AddMetric("Facing", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_Perf& CameraApp_Perf::SetFacing(const CameraAppFacing value) &
{
    AddMetric("Facing", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_Perf&& CameraApp_Perf::SetResolutionWidth(const int64_t value) &&
{
    AddMetric("ResolutionWidth", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Perf& CameraApp_Perf::SetResolutionWidth(const int64_t value) &
{
    AddMetric("ResolutionWidth", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Perf&& CameraApp_Perf::SetResolutionHeight(const int64_t value) &&
{
    AddMetric("ResolutionHeight", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Perf& CameraApp_Perf::SetResolutionHeight(const int64_t value) &
{
    AddMetric("ResolutionHeight", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Perf&& CameraApp_Perf::SetPageCount(const int64_t value) &&
{
    AddMetric("PageCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Perf& CameraApp_Perf::SetPageCount(const int64_t value) &
{
    AddMetric("PageCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Perf&& CameraApp_Perf::SetPressure(const CameraAppPressure value) &&
{
    AddMetric("Pressure", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_Perf& CameraApp_Perf::SetPressure(const CameraAppPressure value) &
{
    AddMetric("Pressure", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_UnsupportedProtocol::CameraApp_UnsupportedProtocol()
    : ::metrics::structured::Event("CrOSEvents", "CameraApp_UnsupportedProtocol", true)
{
}
CameraApp_UnsupportedProtocol::~CameraApp_UnsupportedProtocol() = default;

CameraApp_EndSession::CameraApp_EndSession()
    : ::metrics::structured::Event("CrOSEvents", "CameraApp_EndSession", true)
{
}
CameraApp_EndSession::~CameraApp_EndSession() = default;

CameraApp_EndSession&& CameraApp_EndSession::SetDuration(const int64_t value) &&
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_EndSession& CameraApp_EndSession::SetDuration(const int64_t value) &
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_MemoryUsage::CameraApp_MemoryUsage()
    : ::metrics::structured::Event("CrOSEvents", "CameraApp_MemoryUsage", true)
{
}
CameraApp_MemoryUsage::~CameraApp_MemoryUsage() = default;

CameraApp_MemoryUsage&& CameraApp_MemoryUsage::SetBehaviors(const int64_t value) &&
{
    AddMetric("Behaviors", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_MemoryUsage& CameraApp_MemoryUsage::SetBehaviors(const int64_t value) &
{
    AddMetric("Behaviors", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_MemoryUsage&& CameraApp_MemoryUsage::SetMemoryUsage(const int64_t value) &&
{
    AddMetric("MemoryUsage", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_MemoryUsage& CameraApp_MemoryUsage::SetMemoryUsage(const int64_t value) &
{
    AddMetric("MemoryUsage", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Ocr::CameraApp_Ocr()
    : ::metrics::structured::Event("CrOSEvents", "CameraApp_Ocr", true)
{
}
CameraApp_Ocr::~CameraApp_Ocr() = default;

CameraApp_Ocr&& CameraApp_Ocr::SetEventType(const CameraAppOcrEventType value) &&
{
    AddMetric("EventType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

CameraApp_Ocr& CameraApp_Ocr::SetEventType(const CameraAppOcrEventType value) &
{
    AddMetric("EventType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

CameraApp_Ocr&& CameraApp_Ocr::SetIsPrimaryLanguage(const int64_t value) &&
{
    AddMetric("IsPrimaryLanguage", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Ocr& CameraApp_Ocr::SetIsPrimaryLanguage(const int64_t value) &
{
    AddMetric("IsPrimaryLanguage", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Ocr&& CameraApp_Ocr::SetLineCount(const int64_t value) &&
{
    AddMetric("LineCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Ocr& CameraApp_Ocr::SetLineCount(const int64_t value) &
{
    AddMetric("LineCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

CameraApp_Ocr&& CameraApp_Ocr::SetWordCount(const int64_t value) &&
{
    AddMetric("WordCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

CameraApp_Ocr& CameraApp_Ocr::SetWordCount(const int64_t value) &
{
    AddMetric("WordCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Growth_Ui_ButtonPressed::Growth_Ui_ButtonPressed()
    : ::metrics::structured::Event("CrOSEvents", "Growth_Ui_ButtonPressed", true)
{
}
Growth_Ui_ButtonPressed::~Growth_Ui_ButtonPressed() = default;

Growth_Ui_ButtonPressed&& Growth_Ui_ButtonPressed::SetCampaignId(const int64_t value) &&
{
    AddMetric("CampaignId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Growth_Ui_ButtonPressed& Growth_Ui_ButtonPressed::SetCampaignId(const int64_t value) &
{
    AddMetric("CampaignId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Growth_Ui_ButtonPressed&& Growth_Ui_ButtonPressed::SetButtonId(const CampaignButtonId value) &&
{
    AddMetric("ButtonId", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

Growth_Ui_ButtonPressed& Growth_Ui_ButtonPressed::SetButtonId(const CampaignButtonId value) &
{
    AddMetric("ButtonId", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

Growth_Ui_Dismissed::Growth_Ui_Dismissed()
    : ::metrics::structured::Event("CrOSEvents", "Growth_Ui_Dismissed", true)
{
}
Growth_Ui_Dismissed::~Growth_Ui_Dismissed() = default;

Growth_Ui_Dismissed&& Growth_Ui_Dismissed::SetCampaignId(const int64_t value) &&
{
    AddMetric("CampaignId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Growth_Ui_Dismissed& Growth_Ui_Dismissed::SetCampaignId(const int64_t value) &
{
    AddMetric("CampaignId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Growth_Ui_Impression::Growth_Ui_Impression()
    : ::metrics::structured::Event("CrOSEvents", "Growth_Ui_Impression", true)
{
}
Growth_Ui_Impression::~Growth_Ui_Impression() = default;

Growth_Ui_Impression&& Growth_Ui_Impression::SetCampaignId(const int64_t value) &&
{
    AddMetric("CampaignId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Growth_Ui_Impression& Growth_Ui_Impression::SetCampaignId(const int64_t value) &
{
    AddMetric("CampaignId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_GaiaSigninRequested::OOBE_GaiaSigninRequested()
    : ::metrics::structured::Event("CrOSEvents", "OOBE_GaiaSigninRequested", true)
{
}
OOBE_GaiaSigninRequested::~OOBE_GaiaSigninRequested() = default;

OOBE_GaiaSigninRequested&& OOBE_GaiaSigninRequested::SetIsReauthentication(const int64_t value) &&
{
    AddMetric("IsReauthentication", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_GaiaSigninRequested& OOBE_GaiaSigninRequested::SetIsReauthentication(const int64_t value) &
{
    AddMetric("IsReauthentication", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_GaiaSigninRequested&& OOBE_GaiaSigninRequested::SetIsFlexFlow(const int64_t value) &&
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_GaiaSigninRequested& OOBE_GaiaSigninRequested::SetIsFlexFlow(const int64_t value) &
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_GaiaSigninRequested&& OOBE_GaiaSigninRequested::SetIsDemoModeFlow(const int64_t value) &&
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_GaiaSigninRequested& OOBE_GaiaSigninRequested::SetIsDemoModeFlow(const int64_t value) &
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_GaiaSigninRequested&& OOBE_GaiaSigninRequested::SetIsOwnerUser(const int64_t value) &&
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_GaiaSigninRequested& OOBE_GaiaSigninRequested::SetIsOwnerUser(const int64_t value) &
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_GaiaSigninRequested&& OOBE_GaiaSigninRequested::SetIsEphemeralOrMGS(const int64_t value) &&
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_GaiaSigninRequested& OOBE_GaiaSigninRequested::SetIsEphemeralOrMGS(const int64_t value) &
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_GaiaSigninRequested&& OOBE_GaiaSigninRequested::SetIsFirstOnboarding(const int64_t value) &&
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_GaiaSigninRequested& OOBE_GaiaSigninRequested::SetIsFirstOnboarding(const int64_t value) &
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_GaiaSigninRequested&& OOBE_GaiaSigninRequested::SetChromeMilestone(const int64_t value) &&
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_GaiaSigninRequested& OOBE_GaiaSigninRequested::SetChromeMilestone(const int64_t value) &
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_GaiaSigninCompleted::OOBE_GaiaSigninCompleted()
    : ::metrics::structured::Event("CrOSEvents", "OOBE_GaiaSigninCompleted", true)
{
}
OOBE_GaiaSigninCompleted::~OOBE_GaiaSigninCompleted() = default;

OOBE_GaiaSigninCompleted&& OOBE_GaiaSigninCompleted::SetIsReauthentication(const int64_t value) &&
{
    AddMetric("IsReauthentication", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_GaiaSigninCompleted& OOBE_GaiaSigninCompleted::SetIsReauthentication(const int64_t value) &
{
    AddMetric("IsReauthentication", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_GaiaSigninCompleted&& OOBE_GaiaSigninCompleted::SetIsFlexFlow(const int64_t value) &&
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_GaiaSigninCompleted& OOBE_GaiaSigninCompleted::SetIsFlexFlow(const int64_t value) &
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_GaiaSigninCompleted&& OOBE_GaiaSigninCompleted::SetIsDemoModeFlow(const int64_t value) &&
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_GaiaSigninCompleted& OOBE_GaiaSigninCompleted::SetIsDemoModeFlow(const int64_t value) &
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_GaiaSigninCompleted&& OOBE_GaiaSigninCompleted::SetIsOwnerUser(const int64_t value) &&
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_GaiaSigninCompleted& OOBE_GaiaSigninCompleted::SetIsOwnerUser(const int64_t value) &
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_GaiaSigninCompleted&& OOBE_GaiaSigninCompleted::SetIsEphemeralOrMGS(const int64_t value) &&
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_GaiaSigninCompleted& OOBE_GaiaSigninCompleted::SetIsEphemeralOrMGS(const int64_t value) &
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_GaiaSigninCompleted&& OOBE_GaiaSigninCompleted::SetIsFirstOnboarding(const int64_t value) &&
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_GaiaSigninCompleted& OOBE_GaiaSigninCompleted::SetIsFirstOnboarding(const int64_t value) &
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_GaiaSigninCompleted&& OOBE_GaiaSigninCompleted::SetChromeMilestone(const int64_t value) &&
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_GaiaSigninCompleted& OOBE_GaiaSigninCompleted::SetChromeMilestone(const int64_t value) &
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OobeStarted::OOBE_OobeStarted()
    : ::metrics::structured::Event("CrOSEvents", "OOBE_OobeStarted", true)
{
}
OOBE_OobeStarted::~OOBE_OobeStarted() = default;

OOBE_OobeStarted&& OOBE_OobeStarted::SetIsFlexFlow(const int64_t value) &&
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OobeStarted& OOBE_OobeStarted::SetIsFlexFlow(const int64_t value) &
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OobeStarted&& OOBE_OobeStarted::SetChromeMilestone(const int64_t value) &&
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OobeStarted& OOBE_OobeStarted::SetChromeMilestone(const int64_t value) &
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PreLoginOobeCompleted::OOBE_PreLoginOobeCompleted()
    : ::metrics::structured::Event("CrOSEvents", "OOBE_PreLoginOobeCompleted", true)
{
}
OOBE_PreLoginOobeCompleted::~OOBE_PreLoginOobeCompleted() = default;

OOBE_PreLoginOobeCompleted&& OOBE_PreLoginOobeCompleted::SetCompletedFlowType(const int64_t value) &&
{
    AddMetric("CompletedFlowType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PreLoginOobeCompleted& OOBE_PreLoginOobeCompleted::SetCompletedFlowType(const int64_t value) &
{
    AddMetric("CompletedFlowType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PreLoginOobeCompleted&& OOBE_PreLoginOobeCompleted::SetIsFlexFlow(const int64_t value) &&
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PreLoginOobeCompleted& OOBE_PreLoginOobeCompleted::SetIsFlexFlow(const int64_t value) &
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PreLoginOobeCompleted&& OOBE_PreLoginOobeCompleted::SetIsDemoModeFlow(const int64_t value) &&
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PreLoginOobeCompleted& OOBE_PreLoginOobeCompleted::SetIsDemoModeFlow(const int64_t value) &
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PreLoginOobeCompleted&& OOBE_PreLoginOobeCompleted::SetChromeMilestone(const int64_t value) &&
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PreLoginOobeCompleted& OOBE_PreLoginOobeCompleted::SetChromeMilestone(const int64_t value) &
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_DeviceRegistered::OOBE_DeviceRegistered()
    : ::metrics::structured::Event("CrOSEvents", "OOBE_DeviceRegistered", true)
{
}
OOBE_DeviceRegistered::~OOBE_DeviceRegistered() = default;

OOBE_DeviceRegistered&& OOBE_DeviceRegistered::SetIsFirstOnboarding(const int64_t value) &&
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_DeviceRegistered& OOBE_DeviceRegistered::SetIsFirstOnboarding(const int64_t value) &
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_DeviceRegistered&& OOBE_DeviceRegistered::SetIsFlexFlow(const int64_t value) &&
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_DeviceRegistered& OOBE_DeviceRegistered::SetIsFlexFlow(const int64_t value) &
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_DeviceRegistered&& OOBE_DeviceRegistered::SetIsDemoModeFlow(const int64_t value) &&
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_DeviceRegistered& OOBE_DeviceRegistered::SetIsDemoModeFlow(const int64_t value) &
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_DeviceRegistered&& OOBE_DeviceRegistered::SetChromeMilestone(const int64_t value) &&
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_DeviceRegistered& OOBE_DeviceRegistered::SetChromeMilestone(const int64_t value) &
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OobeCompleted::OOBE_OobeCompleted()
    : ::metrics::structured::Event("CrOSEvents", "OOBE_OobeCompleted", true)
{
}
OOBE_OobeCompleted::~OOBE_OobeCompleted() = default;

OOBE_OobeCompleted&& OOBE_OobeCompleted::SetIsFlexFlow(const int64_t value) &&
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OobeCompleted& OOBE_OobeCompleted::SetIsFlexFlow(const int64_t value) &
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OobeCompleted&& OOBE_OobeCompleted::SetIsDemoModeFlow(const int64_t value) &&
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OobeCompleted& OOBE_OobeCompleted::SetIsDemoModeFlow(const int64_t value) &
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OobeCompleted&& OOBE_OobeCompleted::SetIsOwnerUser(const int64_t value) &&
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OobeCompleted& OOBE_OobeCompleted::SetIsOwnerUser(const int64_t value) &
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OobeCompleted&& OOBE_OobeCompleted::SetIsEphemeralOrMGS(const int64_t value) &&
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OobeCompleted& OOBE_OobeCompleted::SetIsEphemeralOrMGS(const int64_t value) &
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OobeCompleted&& OOBE_OobeCompleted::SetIsFirstOnboarding(const int64_t value) &&
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OobeCompleted& OOBE_OobeCompleted::SetIsFirstOnboarding(const int64_t value) &
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OobeCompleted&& OOBE_OobeCompleted::SetChromeMilestone(const int64_t value) &&
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OobeCompleted& OOBE_OobeCompleted::SetChromeMilestone(const int64_t value) &
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingStarted::OOBE_OnboardingStarted()
    : ::metrics::structured::Event("CrOSEvents", "OOBE_OnboardingStarted", true)
{
}
OOBE_OnboardingStarted::~OOBE_OnboardingStarted() = default;

OOBE_OnboardingStarted&& OOBE_OnboardingStarted::SetIsFlexFlow(const int64_t value) &&
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingStarted& OOBE_OnboardingStarted::SetIsFlexFlow(const int64_t value) &
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingStarted&& OOBE_OnboardingStarted::SetIsDemoModeFlow(const int64_t value) &&
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingStarted& OOBE_OnboardingStarted::SetIsDemoModeFlow(const int64_t value) &
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingStarted&& OOBE_OnboardingStarted::SetIsOwnerUser(const int64_t value) &&
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingStarted& OOBE_OnboardingStarted::SetIsOwnerUser(const int64_t value) &
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingStarted&& OOBE_OnboardingStarted::SetIsEphemeralOrMGS(const int64_t value) &&
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingStarted& OOBE_OnboardingStarted::SetIsEphemeralOrMGS(const int64_t value) &
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingStarted&& OOBE_OnboardingStarted::SetIsFirstOnboarding(const int64_t value) &&
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingStarted& OOBE_OnboardingStarted::SetIsFirstOnboarding(const int64_t value) &
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingStarted&& OOBE_OnboardingStarted::SetChromeMilestone(const int64_t value) &&
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingStarted& OOBE_OnboardingStarted::SetChromeMilestone(const int64_t value) &
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingCompleted::OOBE_OnboardingCompleted()
    : ::metrics::structured::Event("CrOSEvents", "OOBE_OnboardingCompleted", true)
{
}
OOBE_OnboardingCompleted::~OOBE_OnboardingCompleted() = default;

OOBE_OnboardingCompleted&& OOBE_OnboardingCompleted::SetIsFlexFlow(const int64_t value) &&
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingCompleted& OOBE_OnboardingCompleted::SetIsFlexFlow(const int64_t value) &
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingCompleted&& OOBE_OnboardingCompleted::SetIsDemoModeFlow(const int64_t value) &&
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingCompleted& OOBE_OnboardingCompleted::SetIsDemoModeFlow(const int64_t value) &
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingCompleted&& OOBE_OnboardingCompleted::SetIsOwnerUser(const int64_t value) &&
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingCompleted& OOBE_OnboardingCompleted::SetIsOwnerUser(const int64_t value) &
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingCompleted&& OOBE_OnboardingCompleted::SetIsEphemeralOrMGS(const int64_t value) &&
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingCompleted& OOBE_OnboardingCompleted::SetIsEphemeralOrMGS(const int64_t value) &
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingCompleted&& OOBE_OnboardingCompleted::SetIsFirstOnboarding(const int64_t value) &&
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingCompleted& OOBE_OnboardingCompleted::SetIsFirstOnboarding(const int64_t value) &
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingCompleted&& OOBE_OnboardingCompleted::SetChromeMilestone(const int64_t value) &&
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingCompleted& OOBE_OnboardingCompleted::SetChromeMilestone(const int64_t value) &
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageEntered::OOBE_PageEntered()
    : ::metrics::structured::Event("CrOSEvents", "OOBE_PageEntered", true)
{
}
OOBE_PageEntered::~OOBE_PageEntered() = default;

OOBE_PageEntered&& OOBE_PageEntered::SetPageId(const std::string& value) &&
{
    AddMetric("PageId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

OOBE_PageEntered& OOBE_PageEntered::SetPageId(const std::string& value) &
{
    AddMetric("PageId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

OOBE_PageEntered&& OOBE_PageEntered::SetIsFlexFlow(const int64_t value) &&
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageEntered& OOBE_PageEntered::SetIsFlexFlow(const int64_t value) &
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageEntered&& OOBE_PageEntered::SetIsDemoModeFlow(const int64_t value) &&
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageEntered& OOBE_PageEntered::SetIsDemoModeFlow(const int64_t value) &
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageEntered&& OOBE_PageEntered::SetIsOwnerUser(const int64_t value) &&
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageEntered& OOBE_PageEntered::SetIsOwnerUser(const int64_t value) &
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageEntered&& OOBE_PageEntered::SetIsEphemeralOrMGS(const int64_t value) &&
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageEntered& OOBE_PageEntered::SetIsEphemeralOrMGS(const int64_t value) &
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageEntered&& OOBE_PageEntered::SetIsFirstOnboarding(const int64_t value) &&
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageEntered& OOBE_PageEntered::SetIsFirstOnboarding(const int64_t value) &
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageEntered&& OOBE_PageEntered::SetChromeMilestone(const int64_t value) &&
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageEntered& OOBE_PageEntered::SetChromeMilestone(const int64_t value) &
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageSkippedBySystem::OOBE_PageSkippedBySystem()
    : ::metrics::structured::Event("CrOSEvents", "OOBE_PageSkippedBySystem", true)
{
}
OOBE_PageSkippedBySystem::~OOBE_PageSkippedBySystem() = default;

OOBE_PageSkippedBySystem&& OOBE_PageSkippedBySystem::SetPageId(const std::string& value) &&
{
    AddMetric("PageId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

OOBE_PageSkippedBySystem& OOBE_PageSkippedBySystem::SetPageId(const std::string& value) &
{
    AddMetric("PageId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

OOBE_PageSkippedBySystem&& OOBE_PageSkippedBySystem::SetIsFlexFlow(const int64_t value) &&
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageSkippedBySystem& OOBE_PageSkippedBySystem::SetIsFlexFlow(const int64_t value) &
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageSkippedBySystem&& OOBE_PageSkippedBySystem::SetIsDemoModeFlow(const int64_t value) &&
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageSkippedBySystem& OOBE_PageSkippedBySystem::SetIsDemoModeFlow(const int64_t value) &
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageSkippedBySystem&& OOBE_PageSkippedBySystem::SetIsOwnerUser(const int64_t value) &&
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageSkippedBySystem& OOBE_PageSkippedBySystem::SetIsOwnerUser(const int64_t value) &
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageSkippedBySystem&& OOBE_PageSkippedBySystem::SetIsEphemeralOrMGS(const int64_t value) &&
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageSkippedBySystem& OOBE_PageSkippedBySystem::SetIsEphemeralOrMGS(const int64_t value) &
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageSkippedBySystem&& OOBE_PageSkippedBySystem::SetIsFirstOnboarding(const int64_t value) &&
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageSkippedBySystem& OOBE_PageSkippedBySystem::SetIsFirstOnboarding(const int64_t value) &
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageSkippedBySystem&& OOBE_PageSkippedBySystem::SetChromeMilestone(const int64_t value) &&
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageSkippedBySystem& OOBE_PageSkippedBySystem::SetChromeMilestone(const int64_t value) &
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageLeft::OOBE_PageLeft()
    : ::metrics::structured::Event("CrOSEvents", "OOBE_PageLeft", true)
{
}
OOBE_PageLeft::~OOBE_PageLeft() = default;

OOBE_PageLeft&& OOBE_PageLeft::SetPageId(const std::string& value) &&
{
    AddMetric("PageId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

OOBE_PageLeft& OOBE_PageLeft::SetPageId(const std::string& value) &
{
    AddMetric("PageId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

OOBE_PageLeft&& OOBE_PageLeft::SetExitReason(const std::string& value) &&
{
    AddMetric("ExitReason", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

OOBE_PageLeft& OOBE_PageLeft::SetExitReason(const std::string& value) &
{
    AddMetric("ExitReason", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

OOBE_PageLeft&& OOBE_PageLeft::SetIsFlexFlow(const int64_t value) &&
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageLeft& OOBE_PageLeft::SetIsFlexFlow(const int64_t value) &
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageLeft&& OOBE_PageLeft::SetIsDemoModeFlow(const int64_t value) &&
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageLeft& OOBE_PageLeft::SetIsDemoModeFlow(const int64_t value) &
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageLeft&& OOBE_PageLeft::SetIsOwnerUser(const int64_t value) &&
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageLeft& OOBE_PageLeft::SetIsOwnerUser(const int64_t value) &
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageLeft&& OOBE_PageLeft::SetIsEphemeralOrMGS(const int64_t value) &&
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageLeft& OOBE_PageLeft::SetIsEphemeralOrMGS(const int64_t value) &
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageLeft&& OOBE_PageLeft::SetIsFirstOnboarding(const int64_t value) &&
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageLeft& OOBE_PageLeft::SetIsFirstOnboarding(const int64_t value) &
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PageLeft&& OOBE_PageLeft::SetChromeMilestone(const int64_t value) &&
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PageLeft& OOBE_PageLeft::SetChromeMilestone(const int64_t value) &
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PreLoginOobeResumed::OOBE_PreLoginOobeResumed()
    : ::metrics::structured::Event("CrOSEvents", "OOBE_PreLoginOobeResumed", true)
{
}
OOBE_PreLoginOobeResumed::~OOBE_PreLoginOobeResumed() = default;

OOBE_PreLoginOobeResumed&& OOBE_PreLoginOobeResumed::SetPendingPageId(const std::string& value) &&
{
    AddMetric("PendingPageId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

OOBE_PreLoginOobeResumed& OOBE_PreLoginOobeResumed::SetPendingPageId(const std::string& value) &
{
    AddMetric("PendingPageId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

OOBE_PreLoginOobeResumed&& OOBE_PreLoginOobeResumed::SetExitReason(const std::string& value) &&
{
    AddMetric("ExitReason", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

OOBE_PreLoginOobeResumed& OOBE_PreLoginOobeResumed::SetExitReason(const std::string& value) &
{
    AddMetric("ExitReason", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

OOBE_PreLoginOobeResumed&& OOBE_PreLoginOobeResumed::SetIsFlexFlow(const int64_t value) &&
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PreLoginOobeResumed& OOBE_PreLoginOobeResumed::SetIsFlexFlow(const int64_t value) &
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PreLoginOobeResumed&& OOBE_PreLoginOobeResumed::SetIsDemoModeFlow(const int64_t value) &&
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PreLoginOobeResumed& OOBE_PreLoginOobeResumed::SetIsDemoModeFlow(const int64_t value) &
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PreLoginOobeResumed&& OOBE_PreLoginOobeResumed::SetIsOwnerUser(const int64_t value) &&
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PreLoginOobeResumed& OOBE_PreLoginOobeResumed::SetIsOwnerUser(const int64_t value) &
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PreLoginOobeResumed&& OOBE_PreLoginOobeResumed::SetIsEphemeralOrMGS(const int64_t value) &&
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PreLoginOobeResumed& OOBE_PreLoginOobeResumed::SetIsEphemeralOrMGS(const int64_t value) &
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PreLoginOobeResumed&& OOBE_PreLoginOobeResumed::SetIsFirstOnboarding(const int64_t value) &&
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PreLoginOobeResumed& OOBE_PreLoginOobeResumed::SetIsFirstOnboarding(const int64_t value) &
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_PreLoginOobeResumed&& OOBE_PreLoginOobeResumed::SetChromeMilestone(const int64_t value) &&
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_PreLoginOobeResumed& OOBE_PreLoginOobeResumed::SetChromeMilestone(const int64_t value) &
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingResumed::OOBE_OnboardingResumed()
    : ::metrics::structured::Event("CrOSEvents", "OOBE_OnboardingResumed", true)
{
}
OOBE_OnboardingResumed::~OOBE_OnboardingResumed() = default;

OOBE_OnboardingResumed&& OOBE_OnboardingResumed::SetPendingPageId(const std::string& value) &&
{
    AddMetric("PendingPageId", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

OOBE_OnboardingResumed& OOBE_OnboardingResumed::SetPendingPageId(const std::string& value) &
{
    AddMetric("PendingPageId", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

OOBE_OnboardingResumed&& OOBE_OnboardingResumed::SetExitReason(const std::string& value) &&
{
    AddMetric("ExitReason", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

OOBE_OnboardingResumed& OOBE_OnboardingResumed::SetExitReason(const std::string& value) &
{
    AddMetric("ExitReason", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

OOBE_OnboardingResumed&& OOBE_OnboardingResumed::SetIsFlexFlow(const int64_t value) &&
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingResumed& OOBE_OnboardingResumed::SetIsFlexFlow(const int64_t value) &
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingResumed&& OOBE_OnboardingResumed::SetIsDemoModeFlow(const int64_t value) &&
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingResumed& OOBE_OnboardingResumed::SetIsDemoModeFlow(const int64_t value) &
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingResumed&& OOBE_OnboardingResumed::SetIsOwnerUser(const int64_t value) &&
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingResumed& OOBE_OnboardingResumed::SetIsOwnerUser(const int64_t value) &
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingResumed&& OOBE_OnboardingResumed::SetIsEphemeralOrMGS(const int64_t value) &&
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingResumed& OOBE_OnboardingResumed::SetIsEphemeralOrMGS(const int64_t value) &
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingResumed&& OOBE_OnboardingResumed::SetIsFirstOnboarding(const int64_t value) &&
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingResumed& OOBE_OnboardingResumed::SetIsFirstOnboarding(const int64_t value) &
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_OnboardingResumed&& OOBE_OnboardingResumed::SetChromeMilestone(const int64_t value) &&
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_OnboardingResumed& OOBE_OnboardingResumed::SetChromeMilestone(const int64_t value) &
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_ChoobeResumed::OOBE_ChoobeResumed()
    : ::metrics::structured::Event("CrOSEvents", "OOBE_ChoobeResumed", true)
{
}
OOBE_ChoobeResumed::~OOBE_ChoobeResumed() = default;

OOBE_ChoobeResumed&& OOBE_ChoobeResumed::SetExitReason(const std::string& value) &&
{
    AddMetric("ExitReason", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

OOBE_ChoobeResumed& OOBE_ChoobeResumed::SetExitReason(const std::string& value) &
{
    AddMetric("ExitReason", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

OOBE_ChoobeResumed&& OOBE_ChoobeResumed::SetIsFlexFlow(const int64_t value) &&
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_ChoobeResumed& OOBE_ChoobeResumed::SetIsFlexFlow(const int64_t value) &
{
    AddMetric("IsFlexFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_ChoobeResumed&& OOBE_ChoobeResumed::SetIsDemoModeFlow(const int64_t value) &&
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_ChoobeResumed& OOBE_ChoobeResumed::SetIsDemoModeFlow(const int64_t value) &
{
    AddMetric("IsDemoModeFlow", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_ChoobeResumed&& OOBE_ChoobeResumed::SetIsOwnerUser(const int64_t value) &&
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_ChoobeResumed& OOBE_ChoobeResumed::SetIsOwnerUser(const int64_t value) &
{
    AddMetric("IsOwnerUser", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_ChoobeResumed&& OOBE_ChoobeResumed::SetIsEphemeralOrMGS(const int64_t value) &&
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_ChoobeResumed& OOBE_ChoobeResumed::SetIsEphemeralOrMGS(const int64_t value) &
{
    AddMetric("IsEphemeralOrMGS", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_ChoobeResumed&& OOBE_ChoobeResumed::SetIsFirstOnboarding(const int64_t value) &&
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_ChoobeResumed& OOBE_ChoobeResumed::SetIsFirstOnboarding(const int64_t value) &
{
    AddMetric("IsFirstOnboarding", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

OOBE_ChoobeResumed&& OOBE_ChoobeResumed::SetChromeMilestone(const int64_t value) &&
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

OOBE_ChoobeResumed& OOBE_ChoobeResumed::SetChromeMilestone(const int64_t value) &
{
    AddMetric("ChromeMilestone", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Picker_StartSession::Picker_StartSession()
    : ::metrics::structured::Event("CrOSEvents", "Picker_StartSession", true)
{
}
Picker_StartSession::~Picker_StartSession() = default;

Picker_StartSession&& Picker_StartSession::SetInputFieldType(const PickerInputFieldType value) &&
{
    AddMetric("InputFieldType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

Picker_StartSession& Picker_StartSession::SetInputFieldType(const PickerInputFieldType value) &
{
    AddMetric("InputFieldType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

Picker_StartSession&& Picker_StartSession::SetSelectionLength(const int64_t value) &&
{
    AddMetric("SelectionLength", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Picker_StartSession& Picker_StartSession::SetSelectionLength(const int64_t value) &
{
    AddMetric("SelectionLength", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Picker_FinishSession::Picker_FinishSession()
    : ::metrics::structured::Event("CrOSEvents", "Picker_FinishSession", true)
{
}
Picker_FinishSession::~Picker_FinishSession() = default;

Picker_FinishSession&& Picker_FinishSession::SetOutcome(const PickerSessionOutcome value) &&
{
    AddMetric("Outcome", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

Picker_FinishSession& Picker_FinishSession::SetOutcome(const PickerSessionOutcome value) &
{
    AddMetric("Outcome", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

Picker_FinishSession&& Picker_FinishSession::SetAction(const PickerAction value) &&
{
    AddMetric("Action", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

Picker_FinishSession& Picker_FinishSession::SetAction(const PickerAction value) &
{
    AddMetric("Action", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

Picker_FinishSession&& Picker_FinishSession::SetResultSource(const PickerResultSource value) &&
{
    AddMetric("ResultSource", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

Picker_FinishSession& Picker_FinishSession::SetResultSource(const PickerResultSource value) &
{
    AddMetric("ResultSource", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

Picker_FinishSession&& Picker_FinishSession::SetResultType(const PickerResultType value) &&
{
    AddMetric("ResultType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

Picker_FinishSession& Picker_FinishSession::SetResultType(const PickerResultType value) &
{
    AddMetric("ResultType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

Picker_FinishSession&& Picker_FinishSession::SetTotalEdits(const int64_t value) &&
{
    AddMetric("TotalEdits", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Picker_FinishSession& Picker_FinishSession::SetTotalEdits(const int64_t value) &
{
    AddMetric("TotalEdits", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Picker_FinishSession&& Picker_FinishSession::SetFinalQuerySize(const int64_t value) &&
{
    AddMetric("FinalQuerySize", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Picker_FinishSession& Picker_FinishSession::SetFinalQuerySize(const int64_t value) &
{
    AddMetric("FinalQuerySize", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Picker_FinishSession&& Picker_FinishSession::SetResultIndex(const int64_t value) &&
{
    AddMetric("ResultIndex", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Picker_FinishSession& Picker_FinishSession::SetResultIndex(const int64_t value) &
{
    AddMetric("ResultIndex", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

QuickStart_ScreenOpened::QuickStart_ScreenOpened()
    : ::metrics::structured::Event("CrOSEvents", "QuickStart_ScreenOpened", true)
{
}
QuickStart_ScreenOpened::~QuickStart_ScreenOpened() = default;

QuickStart_ScreenOpened&& QuickStart_ScreenOpened::SetScreenName(const QuickStartScreenName value) &&
{
    AddMetric("ScreenName", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

QuickStart_ScreenOpened& QuickStart_ScreenOpened::SetScreenName(const QuickStartScreenName value) &
{
    AddMetric("ScreenName", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

QuickStart_ScreenClosed::QuickStart_ScreenClosed()
    : ::metrics::structured::Event("CrOSEvents", "QuickStart_ScreenClosed", true)
{
}
QuickStart_ScreenClosed::~QuickStart_ScreenClosed() = default;

QuickStart_ScreenClosed&& QuickStart_ScreenClosed::SetScreenName(const QuickStartScreenName value) &&
{
    AddMetric("ScreenName", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

QuickStart_ScreenClosed& QuickStart_ScreenClosed::SetScreenName(const QuickStartScreenName value) &
{
    AddMetric("ScreenName", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

QuickStart_Initiated::QuickStart_Initiated()
    : ::metrics::structured::Event("CrOSEvents", "QuickStart_Initiated", true)
{
}
QuickStart_Initiated::~QuickStart_Initiated() = default;

QuickStart_Initiated&& QuickStart_Initiated::SetEntryPoint(const QuickStartEntryPoint value) &&
{
    AddMetric("EntryPoint", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

QuickStart_Initiated& QuickStart_Initiated::SetEntryPoint(const QuickStartEntryPoint value) &
{
    AddMetric("EntryPoint", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

QuickStart_FlowAborted::QuickStart_FlowAborted()
    : ::metrics::structured::Event("CrOSEvents", "QuickStart_FlowAborted", true)
{
}
QuickStart_FlowAborted::~QuickStart_FlowAborted() = default;

QuickStart_FlowAborted&& QuickStart_FlowAborted::SetReason(const QuickStartAbortFlowReason value) &&
{
    AddMetric("Reason", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

QuickStart_FlowAborted& QuickStart_FlowAborted::SetReason(const QuickStartAbortFlowReason value) &
{
    AddMetric("Reason", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

QuickStart_EstablishConnection::QuickStart_EstablishConnection()
    : ::metrics::structured::Event("CrOSEvents", "QuickStart_EstablishConnection", true)
{
}
QuickStart_EstablishConnection::~QuickStart_EstablishConnection() = default;

QuickStart_EstablishConnection&& QuickStart_EstablishConnection::SetSuccess(const int64_t value) &&
{
    AddMetric("Success", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

QuickStart_EstablishConnection& QuickStart_EstablishConnection::SetSuccess(const int64_t value) &
{
    AddMetric("Success", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

QuickStart_AutomaticResumeAfterUpdate::QuickStart_AutomaticResumeAfterUpdate()
    : ::metrics::structured::Event("CrOSEvents", "QuickStart_AutomaticResumeAfterUpdate", true)
{
}
QuickStart_AutomaticResumeAfterUpdate::~QuickStart_AutomaticResumeAfterUpdate() = default;

QuickStart_AutomaticResumeAfterUpdate&& QuickStart_AutomaticResumeAfterUpdate::SetSuccess(const int64_t value) &&
{
    AddMetric("Success", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

QuickStart_AutomaticResumeAfterUpdate& QuickStart_AutomaticResumeAfterUpdate::SetSuccess(const int64_t value) &
{
    AddMetric("Success", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

QuickStart_GetWifiCredentials::QuickStart_GetWifiCredentials()
    : ::metrics::structured::Event("CrOSEvents", "QuickStart_GetWifiCredentials", true)
{
}
QuickStart_GetWifiCredentials::~QuickStart_GetWifiCredentials() = default;

QuickStart_GetWifiCredentials&& QuickStart_GetWifiCredentials::SetSuccess(const int64_t value) &&
{
    AddMetric("Success", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

QuickStart_GetWifiCredentials& QuickStart_GetWifiCredentials::SetSuccess(const int64_t value) &
{
    AddMetric("Success", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

QuickStart_InstallForcedUpdate::QuickStart_InstallForcedUpdate()
    : ::metrics::structured::Event("CrOSEvents", "QuickStart_InstallForcedUpdate", true)
{
}
QuickStart_InstallForcedUpdate::~QuickStart_InstallForcedUpdate() = default;

QuickStart_InstallConsumerUpdate::QuickStart_InstallConsumerUpdate()
    : ::metrics::structured::Event("CrOSEvents", "QuickStart_InstallConsumerUpdate", true)
{
}
QuickStart_InstallConsumerUpdate::~QuickStart_InstallConsumerUpdate() = default;

QuickStart_ConsumerUpdateCancelled::QuickStart_ConsumerUpdateCancelled()
    : ::metrics::structured::Event("CrOSEvents", "QuickStart_ConsumerUpdateCancelled", true)
{
}
QuickStart_ConsumerUpdateCancelled::~QuickStart_ConsumerUpdateCancelled() = default;

QuickStart_AccountTransferStarted::QuickStart_AccountTransferStarted()
    : ::metrics::structured::Event("CrOSEvents", "QuickStart_AccountTransferStarted", true)
{
}
QuickStart_AccountTransferStarted::~QuickStart_AccountTransferStarted() = default;

QuickStart_AccountTransferComplete::QuickStart_AccountTransferComplete()
    : ::metrics::structured::Event("CrOSEvents", "QuickStart_AccountTransferComplete", true)
{
}
QuickStart_AccountTransferComplete::~QuickStart_AccountTransferComplete() = default;

QuickStart_AccountTransferComplete&& QuickStart_AccountTransferComplete::SetSuccess(const int64_t value) &&
{
    AddMetric("Success", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

QuickStart_AccountTransferComplete& QuickStart_AccountTransferComplete::SetSuccess(const int64_t value) &
{
    AddMetric("Success", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_StartSession::RecorderApp_StartSession()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_StartSession", true)
{
}
RecorderApp_StartSession::~RecorderApp_StartSession() = default;

RecorderApp_StartSession&& RecorderApp_StartSession::SetSpeakerLabelEnableState(const RecorderAppSpeakerLabelEnableState value) &&
{
    AddMetric("SpeakerLabelEnableState", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

RecorderApp_StartSession& RecorderApp_StartSession::SetSpeakerLabelEnableState(const RecorderAppSpeakerLabelEnableState value) &
{
    AddMetric("SpeakerLabelEnableState", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

RecorderApp_StartSession&& RecorderApp_StartSession::SetSummaryEnableState(const RecorderAppSummaryEnableState value) &&
{
    AddMetric("SummaryEnableState", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

RecorderApp_StartSession& RecorderApp_StartSession::SetSummaryEnableState(const RecorderAppSummaryEnableState value) &
{
    AddMetric("SummaryEnableState", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

RecorderApp_StartSession&& RecorderApp_StartSession::SetTranscriptionEnableState(const RecorderAppTranscriptionEnableState value) &&
{
    AddMetric("TranscriptionEnableState", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

RecorderApp_StartSession& RecorderApp_StartSession::SetTranscriptionEnableState(const RecorderAppTranscriptionEnableState value) &
{
    AddMetric("TranscriptionEnableState", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

RecorderApp_Record::RecorderApp_Record()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_Record", true)
{
}
RecorderApp_Record::~RecorderApp_Record() = default;

RecorderApp_Record&& RecorderApp_Record::SetMicrophoneType(const RecorderAppMicrophoneType value) &&
{
    AddMetric("MicrophoneType", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

RecorderApp_Record& RecorderApp_Record::SetMicrophoneType(const RecorderAppMicrophoneType value) &
{
    AddMetric("MicrophoneType", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

RecorderApp_Record&& RecorderApp_Record::SetIncludeSystemAudio(const int64_t value) &&
{
    AddMetric("IncludeSystemAudio", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_Record& RecorderApp_Record::SetIncludeSystemAudio(const int64_t value) &
{
    AddMetric("IncludeSystemAudio", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_Record&& RecorderApp_Record::SetAudioDuration(const int64_t value) &&
{
    AddMetric("AudioDuration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_Record& RecorderApp_Record::SetAudioDuration(const int64_t value) &
{
    AddMetric("AudioDuration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_Record&& RecorderApp_Record::SetRecordDuration(const int64_t value) &&
{
    AddMetric("RecordDuration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_Record& RecorderApp_Record::SetRecordDuration(const int64_t value) &
{
    AddMetric("RecordDuration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_Record&& RecorderApp_Record::SetEverPaused(const int64_t value) &&
{
    AddMetric("EverPaused", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_Record& RecorderApp_Record::SetEverPaused(const int64_t value) &
{
    AddMetric("EverPaused", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_Record&& RecorderApp_Record::SetEverMuted(const int64_t value) &&
{
    AddMetric("EverMuted", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_Record& RecorderApp_Record::SetEverMuted(const int64_t value) &
{
    AddMetric("EverMuted", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_Record&& RecorderApp_Record::SetTranscriptionLocale(const RecorderAppTranscriptionLocale value) &&
{
    AddMetric("TranscriptionLocale", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

RecorderApp_Record& RecorderApp_Record::SetTranscriptionLocale(const RecorderAppTranscriptionLocale value) &
{
    AddMetric("TranscriptionLocale", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

RecorderApp_Record&& RecorderApp_Record::SetTranscriptionLabelEnableState(const RecorderAppTranscriptionEnableState value) &&
{
    AddMetric("TranscriptionLabelEnableState", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

RecorderApp_Record& RecorderApp_Record::SetTranscriptionLabelEnableState(const RecorderAppTranscriptionEnableState value) &
{
    AddMetric("TranscriptionLabelEnableState", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

RecorderApp_Record&& RecorderApp_Record::SetSpeakerLabelEnableState(const RecorderAppSpeakerLabelEnableState value) &&
{
    AddMetric("SpeakerLabelEnableState", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

RecorderApp_Record& RecorderApp_Record::SetSpeakerLabelEnableState(const RecorderAppSpeakerLabelEnableState value) &
{
    AddMetric("SpeakerLabelEnableState", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

RecorderApp_Record&& RecorderApp_Record::SetRecordingSaved(const int64_t value) &&
{
    AddMetric("RecordingSaved", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_Record& RecorderApp_Record::SetRecordingSaved(const int64_t value) &
{
    AddMetric("RecordingSaved", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_Record&& RecorderApp_Record::SetSpeakerCount(const int64_t value) &&
{
    AddMetric("SpeakerCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_Record& RecorderApp_Record::SetSpeakerCount(const int64_t value) &
{
    AddMetric("SpeakerCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_Record&& RecorderApp_Record::SetWordCount(const int64_t value) &&
{
    AddMetric("WordCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_Record& RecorderApp_Record::SetWordCount(const int64_t value) &
{
    AddMetric("WordCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_SuggestTitle::RecorderApp_SuggestTitle()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_SuggestTitle", true)
{
}
RecorderApp_SuggestTitle::~RecorderApp_SuggestTitle() = default;

RecorderApp_SuggestTitle&& RecorderApp_SuggestTitle::SetWordCount(const int64_t value) &&
{
    AddMetric("WordCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_SuggestTitle& RecorderApp_SuggestTitle::SetWordCount(const int64_t value) &
{
    AddMetric("WordCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_SuggestTitle&& RecorderApp_SuggestTitle::SetResultStatus(const RecorderAppModelResultStatus value) &&
{
    AddMetric("ResultStatus", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

RecorderApp_SuggestTitle& RecorderApp_SuggestTitle::SetResultStatus(const RecorderAppModelResultStatus value) &
{
    AddMetric("ResultStatus", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

RecorderApp_SuggestTitle&& RecorderApp_SuggestTitle::SetSuggestionAccepted(const int64_t value) &&
{
    AddMetric("SuggestionAccepted", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_SuggestTitle& RecorderApp_SuggestTitle::SetSuggestionAccepted(const int64_t value) &
{
    AddMetric("SuggestionAccepted", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_SuggestTitle&& RecorderApp_SuggestTitle::SetAcceptedSuggestionIndex(const int64_t value) &&
{
    AddMetric("AcceptedSuggestionIndex", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_SuggestTitle& RecorderApp_SuggestTitle::SetAcceptedSuggestionIndex(const int64_t value) &
{
    AddMetric("AcceptedSuggestionIndex", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_Summarize::RecorderApp_Summarize()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_Summarize", true)
{
}
RecorderApp_Summarize::~RecorderApp_Summarize() = default;

RecorderApp_Summarize&& RecorderApp_Summarize::SetWordCount(const int64_t value) &&
{
    AddMetric("WordCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_Summarize& RecorderApp_Summarize::SetWordCount(const int64_t value) &
{
    AddMetric("WordCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_Summarize&& RecorderApp_Summarize::SetResultStatus(const RecorderAppModelResultStatus value) &&
{
    AddMetric("ResultStatus", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

RecorderApp_Summarize& RecorderApp_Summarize::SetResultStatus(const RecorderAppModelResultStatus value) &
{
    AddMetric("ResultStatus", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

RecorderApp_FeedbackTitleSuggestion::RecorderApp_FeedbackTitleSuggestion()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_FeedbackTitleSuggestion", true)
{
}
RecorderApp_FeedbackTitleSuggestion::~RecorderApp_FeedbackTitleSuggestion() = default;

RecorderApp_FeedbackTitleSuggestion&& RecorderApp_FeedbackTitleSuggestion::SetFeedback(const RecorderAppModelFeedback value) &&
{
    AddMetric("Feedback", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

RecorderApp_FeedbackTitleSuggestion& RecorderApp_FeedbackTitleSuggestion::SetFeedback(const RecorderAppModelFeedback value) &
{
    AddMetric("Feedback", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

RecorderApp_FeedbackSummary::RecorderApp_FeedbackSummary()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_FeedbackSummary", true)
{
}
RecorderApp_FeedbackSummary::~RecorderApp_FeedbackSummary() = default;

RecorderApp_FeedbackSummary&& RecorderApp_FeedbackSummary::SetFeedback(const RecorderAppModelFeedback value) &&
{
    AddMetric("Feedback", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

RecorderApp_FeedbackSummary& RecorderApp_FeedbackSummary::SetFeedback(const RecorderAppModelFeedback value) &
{
    AddMetric("Feedback", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

RecorderApp_Onboard::RecorderApp_Onboard()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_Onboard", true)
{
}
RecorderApp_Onboard::~RecorderApp_Onboard() = default;

RecorderApp_Onboard&& RecorderApp_Onboard::SetTranscriptionEnableState(const RecorderAppTranscriptionEnableState value) &&
{
    AddMetric("TranscriptionEnableState", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

RecorderApp_Onboard& RecorderApp_Onboard::SetTranscriptionEnableState(const RecorderAppTranscriptionEnableState value) &
{
    AddMetric("TranscriptionEnableState", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

RecorderApp_Onboard&& RecorderApp_Onboard::SetSpeakerLabelEnableState(const RecorderAppSpeakerLabelEnableState value) &&
{
    AddMetric("SpeakerLabelEnableState", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

RecorderApp_Onboard& RecorderApp_Onboard::SetSpeakerLabelEnableState(const RecorderAppSpeakerLabelEnableState value) &
{
    AddMetric("SpeakerLabelEnableState", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

RecorderApp_Export::RecorderApp_Export()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_Export", true)
{
}
RecorderApp_Export::~RecorderApp_Export() = default;

RecorderApp_Export&& RecorderApp_Export::SetAudioFormat(const RecorderAppAudioFormat value) &&
{
    AddMetric("AudioFormat", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

RecorderApp_Export& RecorderApp_Export::SetAudioFormat(const RecorderAppAudioFormat value) &
{
    AddMetric("AudioFormat", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

RecorderApp_Export&& RecorderApp_Export::SetTranscriptFormat(const RecorderAppTranscriptFormat value) &&
{
    AddMetric("TranscriptFormat", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

RecorderApp_Export& RecorderApp_Export::SetTranscriptFormat(const RecorderAppTranscriptFormat value) &
{
    AddMetric("TranscriptFormat", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

RecorderApp_ChangePlaybackSpeed::RecorderApp_ChangePlaybackSpeed()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_ChangePlaybackSpeed", true)
{
}
RecorderApp_ChangePlaybackSpeed::~RecorderApp_ChangePlaybackSpeed() = default;

RecorderApp_ChangePlaybackSpeed&& RecorderApp_ChangePlaybackSpeed::SetPlaybackSpeed(const double value) &&
{
    AddMetric("PlaybackSpeed", Event::MetricType::kDouble, base::Value(value));
    return std::move(*this);
}

RecorderApp_ChangePlaybackSpeed& RecorderApp_ChangePlaybackSpeed::SetPlaybackSpeed(const double value) &
{
    AddMetric("PlaybackSpeed", Event::MetricType::kDouble, base::Value(value));
    return *this;
}

RecorderApp_ChangePlaybackVolume::RecorderApp_ChangePlaybackVolume()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_ChangePlaybackVolume", true)
{
}
RecorderApp_ChangePlaybackVolume::~RecorderApp_ChangePlaybackVolume() = default;

RecorderApp_ChangePlaybackVolume&& RecorderApp_ChangePlaybackVolume::SetVolume(const int64_t value) &&
{
    AddMetric("Volume", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_ChangePlaybackVolume& RecorderApp_ChangePlaybackVolume::SetVolume(const int64_t value) &
{
    AddMetric("Volume", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_ChangePlaybackVolume&& RecorderApp_ChangePlaybackVolume::SetMuted(const int64_t value) &&
{
    AddMetric("Muted", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_ChangePlaybackVolume& RecorderApp_ChangePlaybackVolume::SetMuted(const int64_t value) &
{
    AddMetric("Muted", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_AppStartPerf::RecorderApp_AppStartPerf()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_AppStartPerf", true)
{
}
RecorderApp_AppStartPerf::~RecorderApp_AppStartPerf() = default;

RecorderApp_AppStartPerf&& RecorderApp_AppStartPerf::SetDuration(const int64_t value) &&
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_AppStartPerf& RecorderApp_AppStartPerf::SetDuration(const int64_t value) &
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_TranscriptionModelDownloadPerf::RecorderApp_TranscriptionModelDownloadPerf()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_TranscriptionModelDownloadPerf", true)
{
}
RecorderApp_TranscriptionModelDownloadPerf::~RecorderApp_TranscriptionModelDownloadPerf() = default;

RecorderApp_TranscriptionModelDownloadPerf&& RecorderApp_TranscriptionModelDownloadPerf::SetDuration(const int64_t value) &&
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_TranscriptionModelDownloadPerf& RecorderApp_TranscriptionModelDownloadPerf::SetDuration(const int64_t value) &
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_SummaryModelDownloadPerf::RecorderApp_SummaryModelDownloadPerf()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_SummaryModelDownloadPerf", true)
{
}
RecorderApp_SummaryModelDownloadPerf::~RecorderApp_SummaryModelDownloadPerf() = default;

RecorderApp_SummaryModelDownloadPerf&& RecorderApp_SummaryModelDownloadPerf::SetDuration(const int64_t value) &&
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_SummaryModelDownloadPerf& RecorderApp_SummaryModelDownloadPerf::SetDuration(const int64_t value) &
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_RecordingSavingPerf::RecorderApp_RecordingSavingPerf()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_RecordingSavingPerf", true)
{
}
RecorderApp_RecordingSavingPerf::~RecorderApp_RecordingSavingPerf() = default;

RecorderApp_RecordingSavingPerf&& RecorderApp_RecordingSavingPerf::SetDuration(const int64_t value) &&
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_RecordingSavingPerf& RecorderApp_RecordingSavingPerf::SetDuration(const int64_t value) &
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_RecordingSavingPerf&& RecorderApp_RecordingSavingPerf::SetAudioDuration(const int64_t value) &&
{
    AddMetric("AudioDuration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_RecordingSavingPerf& RecorderApp_RecordingSavingPerf::SetAudioDuration(const int64_t value) &
{
    AddMetric("AudioDuration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_RecordingSavingPerf&& RecorderApp_RecordingSavingPerf::SetWordCount(const int64_t value) &&
{
    AddMetric("WordCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_RecordingSavingPerf& RecorderApp_RecordingSavingPerf::SetWordCount(const int64_t value) &
{
    AddMetric("WordCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_TitleSuggestionPerf::RecorderApp_TitleSuggestionPerf()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_TitleSuggestionPerf", true)
{
}
RecorderApp_TitleSuggestionPerf::~RecorderApp_TitleSuggestionPerf() = default;

RecorderApp_TitleSuggestionPerf&& RecorderApp_TitleSuggestionPerf::SetDuration(const int64_t value) &&
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_TitleSuggestionPerf& RecorderApp_TitleSuggestionPerf::SetDuration(const int64_t value) &
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_TitleSuggestionPerf&& RecorderApp_TitleSuggestionPerf::SetWordCount(const int64_t value) &&
{
    AddMetric("WordCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_TitleSuggestionPerf& RecorderApp_TitleSuggestionPerf::SetWordCount(const int64_t value) &
{
    AddMetric("WordCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_SummaryPerf::RecorderApp_SummaryPerf()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_SummaryPerf", true)
{
}
RecorderApp_SummaryPerf::~RecorderApp_SummaryPerf() = default;

RecorderApp_SummaryPerf&& RecorderApp_SummaryPerf::SetDuration(const int64_t value) &&
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_SummaryPerf& RecorderApp_SummaryPerf::SetDuration(const int64_t value) &
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_SummaryPerf&& RecorderApp_SummaryPerf::SetWordCount(const int64_t value) &&
{
    AddMetric("WordCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_SummaryPerf& RecorderApp_SummaryPerf::SetWordCount(const int64_t value) &
{
    AddMetric("WordCount", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_ExportPerf::RecorderApp_ExportPerf()
    : ::metrics::structured::Event("CrOSEvents", "RecorderApp_ExportPerf", true)
{
}
RecorderApp_ExportPerf::~RecorderApp_ExportPerf() = default;

RecorderApp_ExportPerf&& RecorderApp_ExportPerf::SetDuration(const int64_t value) &&
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_ExportPerf& RecorderApp_ExportPerf::SetDuration(const int64_t value) &
{
    AddMetric("Duration", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

RecorderApp_ExportPerf&& RecorderApp_ExportPerf::SetRecordingSize(const int64_t value) &&
{
    AddMetric("RecordingSize", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

RecorderApp_ExportPerf& RecorderApp_ExportPerf::SetRecordingSize(const int64_t value) &
{
    AddMetric("RecordingSize", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

UserLogin::UserLogin()
    : ::metrics::structured::Event("CrOSEvents", "UserLogin", true)
{
}
UserLogin::~UserLogin() = default;

UserLogout::UserLogout()
    : ::metrics::structured::Event("CrOSEvents", "UserLogout", true)
{
}
UserLogout::~UserLogout() = default;

SystemSuspended::SystemSuspended()
    : ::metrics::structured::Event("CrOSEvents", "SystemSuspended", true)
{
}
SystemSuspended::~SystemSuspended() = default;

SystemSuspended&& SystemSuspended::SetReason(const int64_t value) &&
{
    AddMetric("Reason", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SystemSuspended& SystemSuspended::SetReason(const int64_t value) &
{
    AddMetric("Reason", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Test1::Test1()
    : ::metrics::structured::Event("CrOSEvents", "Test1", true)
{
}
Test1::~Test1() = default;

Test1&& Test1::SetMetric1(const double value) &&
{
    AddMetric("Metric1", Event::MetricType::kDouble, base::Value(value));
    return std::move(*this);
}

Test1& Test1::SetMetric1(const double value) &
{
    AddMetric("Metric1", Event::MetricType::kDouble, base::Value(value));
    return *this;
}

NoMetricsEvent::NoMetricsEvent()
    : ::metrics::structured::Event("CrOSEvents", "NoMetricsEvent", true)
{
}
NoMetricsEvent::~NoMetricsEvent() = default;

} // namespace cr_os_events

namespace dev_tools {

SessionStart::SessionStart()
    : ::metrics::structured::Event("DevTools", "SessionStart", false)
{
}
SessionStart::~SessionStart() = default;

SessionStart&& SessionStart::SetTrigger(const int64_t value) &&
{
    AddMetric("Trigger", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionStart& SessionStart::SetTrigger(const int64_t value) &
{
    AddMetric("Trigger", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SessionStart&& SessionStart::SetDockSide(const int64_t value) &&
{
    AddMetric("DockSide", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionStart& SessionStart::SetDockSide(const int64_t value) &
{
    AddMetric("DockSide", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SessionStart&& SessionStart::SetSessionId(const int64_t value) &&
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionStart& SessionStart::SetSessionId(const int64_t value) &
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SessionStart&& SessionStart::SetIsSignedIn(const int64_t value) &&
{
    AddMetric("IsSignedIn", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionStart& SessionStart::SetIsSignedIn(const int64_t value) &
{
    AddMetric("IsSignedIn", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SessionEnd::SessionEnd()
    : ::metrics::structured::Event("DevTools", "SessionEnd", false)
{
}
SessionEnd::~SessionEnd() = default;

SessionEnd&& SessionEnd::SetTrigger(const int64_t value) &&
{
    AddMetric("Trigger", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionEnd& SessionEnd::SetTrigger(const int64_t value) &
{
    AddMetric("Trigger", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SessionEnd&& SessionEnd::SetTimeSinceSessionStart(const int64_t value) &&
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionEnd& SessionEnd::SetTimeSinceSessionStart(const int64_t value) &
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

SessionEnd&& SessionEnd::SetSessionId(const int64_t value) &&
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

SessionEnd& SessionEnd::SetSessionId(const int64_t value) &
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Impression::Impression()
    : ::metrics::structured::Event("DevTools", "Impression", false)
{
}
Impression::~Impression() = default;

Impression&& Impression::SetVeId(const int64_t value) &&
{
    AddMetric("VeId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Impression& Impression::SetVeId(const int64_t value) &
{
    AddMetric("VeId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Impression&& Impression::SetVeType(const int64_t value) &&
{
    AddMetric("VeType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Impression& Impression::SetVeType(const int64_t value) &
{
    AddMetric("VeType", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Impression&& Impression::SetVeParent(const int64_t value) &&
{
    AddMetric("VeParent", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Impression& Impression::SetVeParent(const int64_t value) &
{
    AddMetric("VeParent", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Impression&& Impression::SetVeContext(const int64_t value) &&
{
    AddMetric("VeContext", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Impression& Impression::SetVeContext(const int64_t value) &
{
    AddMetric("VeContext", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Impression&& Impression::SetTimeSinceSessionStart(const int64_t value) &&
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Impression& Impression::SetTimeSinceSessionStart(const int64_t value) &
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Impression&& Impression::SetSessionId(const int64_t value) &&
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Impression& Impression::SetSessionId(const int64_t value) &
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Impression&& Impression::SetWidth(const int64_t value) &&
{
    AddMetric("Width", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Impression& Impression::SetWidth(const int64_t value) &
{
    AddMetric("Width", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Impression&& Impression::SetHeight(const int64_t value) &&
{
    AddMetric("Height", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Impression& Impression::SetHeight(const int64_t value) &
{
    AddMetric("Height", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Resize::Resize()
    : ::metrics::structured::Event("DevTools", "Resize", false)
{
}
Resize::~Resize() = default;

Resize&& Resize::SetVeId(const int64_t value) &&
{
    AddMetric("VeId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Resize& Resize::SetVeId(const int64_t value) &
{
    AddMetric("VeId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Resize&& Resize::SetTimeSinceSessionStart(const int64_t value) &&
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Resize& Resize::SetTimeSinceSessionStart(const int64_t value) &
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Resize&& Resize::SetSessionId(const int64_t value) &&
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Resize& Resize::SetSessionId(const int64_t value) &
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Resize&& Resize::SetWidth(const int64_t value) &&
{
    AddMetric("Width", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Resize& Resize::SetWidth(const int64_t value) &
{
    AddMetric("Width", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Resize&& Resize::SetHeight(const int64_t value) &&
{
    AddMetric("Height", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Resize& Resize::SetHeight(const int64_t value) &
{
    AddMetric("Height", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Click::Click()
    : ::metrics::structured::Event("DevTools", "Click", false)
{
}
Click::~Click() = default;

Click&& Click::SetVeId(const int64_t value) &&
{
    AddMetric("VeId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Click& Click::SetVeId(const int64_t value) &
{
    AddMetric("VeId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Click&& Click::SetMouseButton(const int64_t value) &&
{
    AddMetric("MouseButton", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Click& Click::SetMouseButton(const int64_t value) &
{
    AddMetric("MouseButton", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Click&& Click::SetDoubleClick(const int64_t value) &&
{
    AddMetric("DoubleClick", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Click& Click::SetDoubleClick(const int64_t value) &
{
    AddMetric("DoubleClick", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Click&& Click::SetContext(const int64_t value) &&
{
    AddMetric("Context", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Click& Click::SetContext(const int64_t value) &
{
    AddMetric("Context", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Click&& Click::SetTimeSinceSessionStart(const int64_t value) &&
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Click& Click::SetTimeSinceSessionStart(const int64_t value) &
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Click&& Click::SetSessionId(const int64_t value) &&
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Click& Click::SetSessionId(const int64_t value) &
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Hover::Hover()
    : ::metrics::structured::Event("DevTools", "Hover", false)
{
}
Hover::~Hover() = default;

Hover&& Hover::SetVeId(const int64_t value) &&
{
    AddMetric("VeId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Hover& Hover::SetVeId(const int64_t value) &
{
    AddMetric("VeId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Hover&& Hover::SetTime(const int64_t value) &&
{
    AddMetric("Time", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Hover& Hover::SetTime(const int64_t value) &
{
    AddMetric("Time", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Hover&& Hover::SetContext(const int64_t value) &&
{
    AddMetric("Context", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Hover& Hover::SetContext(const int64_t value) &
{
    AddMetric("Context", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Hover&& Hover::SetTimeSinceSessionStart(const int64_t value) &&
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Hover& Hover::SetTimeSinceSessionStart(const int64_t value) &
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Hover&& Hover::SetSessionId(const int64_t value) &&
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Hover& Hover::SetSessionId(const int64_t value) &
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Drag::Drag()
    : ::metrics::structured::Event("DevTools", "Drag", false)
{
}
Drag::~Drag() = default;

Drag&& Drag::SetVeId(const int64_t value) &&
{
    AddMetric("VeId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Drag& Drag::SetVeId(const int64_t value) &
{
    AddMetric("VeId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Drag&& Drag::SetDistance(const int64_t value) &&
{
    AddMetric("Distance", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Drag& Drag::SetDistance(const int64_t value) &
{
    AddMetric("Distance", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Drag&& Drag::SetContext(const int64_t value) &&
{
    AddMetric("Context", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Drag& Drag::SetContext(const int64_t value) &
{
    AddMetric("Context", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Drag&& Drag::SetTimeSinceSessionStart(const int64_t value) &&
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Drag& Drag::SetTimeSinceSessionStart(const int64_t value) &
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Drag&& Drag::SetSessionId(const int64_t value) &&
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Drag& Drag::SetSessionId(const int64_t value) &
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Change::Change()
    : ::metrics::structured::Event("DevTools", "Change", false)
{
}
Change::~Change() = default;

Change&& Change::SetVeId(const int64_t value) &&
{
    AddMetric("VeId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Change& Change::SetVeId(const int64_t value) &
{
    AddMetric("VeId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Change&& Change::SetContext(const int64_t value) &&
{
    AddMetric("Context", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Change& Change::SetContext(const int64_t value) &
{
    AddMetric("Context", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Change&& Change::SetTimeSinceSessionStart(const int64_t value) &&
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Change& Change::SetTimeSinceSessionStart(const int64_t value) &
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

Change&& Change::SetSessionId(const int64_t value) &&
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

Change& Change::SetSessionId(const int64_t value) &
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

KeyDown::KeyDown()
    : ::metrics::structured::Event("DevTools", "KeyDown", false)
{
}
KeyDown::~KeyDown() = default;

KeyDown&& KeyDown::SetVeId(const int64_t value) &&
{
    AddMetric("VeId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

KeyDown& KeyDown::SetVeId(const int64_t value) &
{
    AddMetric("VeId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

KeyDown&& KeyDown::SetContext(const int64_t value) &&
{
    AddMetric("Context", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

KeyDown& KeyDown::SetContext(const int64_t value) &
{
    AddMetric("Context", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

KeyDown&& KeyDown::SetTimeSinceSessionStart(const int64_t value) &&
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

KeyDown& KeyDown::SetTimeSinceSessionStart(const int64_t value) &
{
    AddMetric("TimeSinceSessionStart", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

KeyDown&& KeyDown::SetSessionId(const int64_t value) &&
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

KeyDown& KeyDown::SetSessionId(const int64_t value) &
{
    AddMetric("SessionId", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

} // namespace dev_tools

namespace test_project_one {

TestEventOne::TestEventOne()
    : ::metrics::structured::Event("TestProjectOne", "TestEventOne", false)
{
}
TestEventOne::~TestEventOne() = default;

TestEventOne&& TestEventOne::SetTestMetricOne(const std::string& value) &&
{
    AddMetric("TestMetricOne", Event::MetricType::kHmac, base::Value(value));
    return std::move(*this);
}

TestEventOne& TestEventOne::SetTestMetricOne(const std::string& value) &
{
    AddMetric("TestMetricOne", Event::MetricType::kHmac, base::Value(value));
    return *this;
}

TestEventOne&& TestEventOne::SetTestMetricTwo(const int64_t value) &&
{
    AddMetric("TestMetricTwo", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

TestEventOne& TestEventOne::SetTestMetricTwo(const int64_t value) &
{
    AddMetric("TestMetricTwo", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

} // namespace test_project_one

namespace test_project_two {

TestEventThree::TestEventThree()
    : ::metrics::structured::Event("TestProjectTwo", "TestEventThree", false)
{
}
TestEventThree::~TestEventThree() = default;

TestEventThree&& TestEventThree::SetTestMetricFour(const std::string& value) &&
{
    AddMetric("TestMetricFour", Event::MetricType::kHmac, base::Value(value));
    return std::move(*this);
}

TestEventThree& TestEventThree::SetTestMetricFour(const std::string& value) &
{
    AddMetric("TestMetricFour", Event::MetricType::kHmac, base::Value(value));
    return *this;
}

TestEventTwo::TestEventTwo()
    : ::metrics::structured::Event("TestProjectTwo", "TestEventTwo", false)
{
}
TestEventTwo::~TestEventTwo() = default;

TestEventTwo&& TestEventTwo::SetTestMetricThree(const std::string& value) &&
{
    AddMetric("TestMetricThree", Event::MetricType::kHmac, base::Value(value));
    return std::move(*this);
}

TestEventTwo& TestEventTwo::SetTestMetricThree(const std::string& value) &
{
    AddMetric("TestMetricThree", Event::MetricType::kHmac, base::Value(value));
    return *this;
}

} // namespace test_project_two

namespace test_project_three {

TestEventFour::TestEventFour()
    : ::metrics::structured::Event("TestProjectThree", "TestEventFour", false)
{
}
TestEventFour::~TestEventFour() = default;

TestEventFour&& TestEventFour::SetTestMetricFour(const int64_t value) &&
{
    AddMetric("TestMetricFour", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return std::move(*this);
}

TestEventFour& TestEventFour::SetTestMetricFour(const int64_t value) &
{
    AddMetric("TestMetricFour", Event::MetricType::kLong, base::Value(base::NumberToString(value)));
    return *this;
}

} // namespace test_project_three

namespace test_project_four {

TestEventFive::TestEventFive()
    : ::metrics::structured::Event("TestProjectFour", "TestEventFive", false)
{
}
TestEventFive::~TestEventFive() = default;

TestEventFive&& TestEventFive::SetTestMetricFive(const std::string& value) &&
{
    AddMetric("TestMetricFive", Event::MetricType::kHmac, base::Value(value));
    return std::move(*this);
}

TestEventFive& TestEventFive::SetTestMetricFive(const std::string& value) &
{
    AddMetric("TestMetricFive", Event::MetricType::kHmac, base::Value(value));
    return *this;
}

} // namespace test_project_four

namespace test_project_five {

TestEventSix::TestEventSix()
    : ::metrics::structured::Event("TestProjectFive", "TestEventSix", false)
{
}
TestEventSix::~TestEventSix() = default;

TestEventSix&& TestEventSix::SetTestMetricSix(const std::string& value) &&
{
    AddMetric("TestMetricSix", Event::MetricType::kRawString, base::Value(value));
    return std::move(*this);
}

TestEventSix& TestEventSix::SetTestMetricSix(const std::string& value) &
{
    AddMetric("TestMetricSix", Event::MetricType::kRawString, base::Value(value));
    return *this;
}

} // namespace test_project_five

namespace test_project_six {

TestEventSeven::TestEventSeven()
    : ::metrics::structured::Event("TestProjectSix", "TestEventSeven", false)
{
}
TestEventSeven::~TestEventSeven() = default;

TestEventSeven&& TestEventSeven::SetTestMetricSeven(const double value) &&
{
    AddMetric("TestMetricSeven", Event::MetricType::kDouble, base::Value(value));
    return std::move(*this);
}

TestEventSeven& TestEventSeven::SetTestMetricSeven(const double value) &
{
    AddMetric("TestMetricSeven", Event::MetricType::kDouble, base::Value(value));
    return *this;
}

TestEnum::TestEnum()
    : ::metrics::structured::Event("TestProjectSix", "TestEnum", false)
{
}
TestEnum::~TestEnum() = default;

TestEnum&& TestEnum::SetTestEnumMetric(const Enum1 value) &&
{
    AddMetric("TestEnumMetric", Event::MetricType::kInt, base::Value((int)value));
    return std::move(*this);
}

TestEnum& TestEnum::SetTestEnumMetric(const Enum1 value) &
{
    AddMetric("TestEnumMetric", Event::MetricType::kInt, base::Value((int)value));
    return *this;
}

} // namespace test_project_six

namespace test_project_seven {

TestEventEight::TestEventEight()
    : ::metrics::structured::Event("TestProjectSeven", "TestEventEight", false)
{
}
TestEventEight::~TestEventEight() = default;

TestEventEight&& TestEventEight::SetTestMetricEight(const double value) &&
{
    AddMetric("TestMetricEight", Event::MetricType::kDouble, base::Value(value));
    return std::move(*this);
}

TestEventEight& TestEventEight::SetTestMetricEight(const double value) &
{
    AddMetric("TestMetricEight", Event::MetricType::kDouble, base::Value(value));
    return *this;
}

} // namespace test_project_seven

namespace sequenced_test_project {

Test1::Test1()
    : ::metrics::structured::Event("SequencedTestProject", "Test1", true)
{
}
Test1::~Test1() = default;

Test1&& Test1::SetMetric1(const double value) &&
{
    AddMetric("Metric1", Event::MetricType::kDouble, base::Value(value));
    return std::move(*this);
}

Test1& Test1::SetMetric1(const double value) &
{
    AddMetric("Metric1", Event::MetricType::kDouble, base::Value(value));
    return *this;
}

} // namespace sequenced_test_project

} // namespace v2
} // namespace events
} // namespace structured
} // namespace metrics