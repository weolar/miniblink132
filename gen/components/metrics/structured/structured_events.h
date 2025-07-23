
// Generated from gen_events.py. DO NOT EDIT!
// source: structured.xml

#ifndef GEN_COMPONENTS_METRICS_STRUCTURED_STRUCTURED_EVENTS_H
#define GEN_COMPONENTS_METRICS_STRUCTURED_STRUCTURED_EVENTS_H

#include <cstdint>
#include <string>

#include "components/metrics/structured/event.h"

namespace metrics {
namespace structured {
namespace events {
namespace v2 {

namespace popular_displays {

class MonitorInfo final : public ::metrics::structured::Event {
public:
    MonitorInfo();
    ~MonitorInfo() override;

    MonitorInfo&& SetDisplayName(const std::string& value) &&;
    MonitorInfo& SetDisplayName(const std::string& value) &;
    MonitorInfo&& SetManufacturerId(const std::string& value) &&;
    MonitorInfo& SetManufacturerId(const std::string& value) &;
    MonitorInfo&& SetProductId(const int64_t value) &&;
    MonitorInfo& SetProductId(const int64_t value) &;
    MonitorInfo&& SetNativeModeSize(const std::string& value) &&;
    MonitorInfo& SetNativeModeSize(const std::string& value) &;
    MonitorInfo&& SetNativeModeRefreshRate(const double value) &&;
    MonitorInfo& SetNativeModeRefreshRate(const double value) &;
    MonitorInfo&& SetPhysicalSize(const std::string& value) &&;
    MonitorInfo& SetPhysicalSize(const std::string& value) &;
    MonitorInfo&& SetConnectionType(const std::string& value) &&;
    MonitorInfo& SetConnectionType(const std::string& value) &;
    MonitorInfo&& SetIsVrrCapable(const int64_t value) &&;
    MonitorInfo& SetIsVrrCapable(const int64_t value) &;
};

} // namespace popular_displays

namespace fast_pair {

class DiscoveryNotificationShown final : public ::metrics::structured::Event {
public:
    DiscoveryNotificationShown();
    ~DiscoveryNotificationShown() override;

    DiscoveryNotificationShown&& SetProtocol(const int64_t value) &&;
    DiscoveryNotificationShown& SetProtocol(const int64_t value) &;
    DiscoveryNotificationShown&& SetFastPairVersion(const int64_t value) &&;
    DiscoveryNotificationShown& SetFastPairVersion(const int64_t value) &;
    DiscoveryNotificationShown&& SetModelId(const int64_t value) &&;
    DiscoveryNotificationShown& SetModelId(const int64_t value) &;
    DiscoveryNotificationShown&& SetRSSI(const int64_t value) &&;
    DiscoveryNotificationShown& SetRSSI(const int64_t value) &;
    DiscoveryNotificationShown&& SetTxPower(const int64_t value) &&;
    DiscoveryNotificationShown& SetTxPower(const int64_t value) &;
};

class PairingStart final : public ::metrics::structured::Event {
public:
    PairingStart();
    ~PairingStart() override;

    PairingStart&& SetProtocol(const int64_t value) &&;
    PairingStart& SetProtocol(const int64_t value) &;
    PairingStart&& SetFastPairVersion(const int64_t value) &&;
    PairingStart& SetFastPairVersion(const int64_t value) &;
    PairingStart&& SetModelId(const int64_t value) &&;
    PairingStart& SetModelId(const int64_t value) &;
    PairingStart&& SetRSSI(const int64_t value) &&;
    PairingStart& SetRSSI(const int64_t value) &;
    PairingStart&& SetTxPower(const int64_t value) &&;
    PairingStart& SetTxPower(const int64_t value) &;
};

class PairingComplete final : public ::metrics::structured::Event {
public:
    PairingComplete();
    ~PairingComplete() override;

    PairingComplete&& SetProtocol(const int64_t value) &&;
    PairingComplete& SetProtocol(const int64_t value) &;
    PairingComplete&& SetFastPairVersion(const int64_t value) &&;
    PairingComplete& SetFastPairVersion(const int64_t value) &;
    PairingComplete&& SetModelId(const int64_t value) &&;
    PairingComplete& SetModelId(const int64_t value) &;
    PairingComplete&& SetRSSI(const int64_t value) &&;
    PairingComplete& SetRSSI(const int64_t value) &;
    PairingComplete&& SetTxPower(const int64_t value) &&;
    PairingComplete& SetTxPower(const int64_t value) &;
};

class PairFailure final : public ::metrics::structured::Event {
public:
    PairFailure();
    ~PairFailure() override;

    PairFailure&& SetProtocol(const int64_t value) &&;
    PairFailure& SetProtocol(const int64_t value) &;
    PairFailure&& SetFastPairVersion(const int64_t value) &&;
    PairFailure& SetFastPairVersion(const int64_t value) &;
    PairFailure&& SetReason(const int64_t value) &&;
    PairFailure& SetReason(const int64_t value) &;
    PairFailure&& SetModelId(const int64_t value) &&;
    PairFailure& SetModelId(const int64_t value) &;
};

} // namespace fast_pair

namespace hindsight {

class CrOSActionEvent_FileOpened final : public ::metrics::structured::Event {
public:
    CrOSActionEvent_FileOpened();
    ~CrOSActionEvent_FileOpened() override;

    CrOSActionEvent_FileOpened&& SetFilename(const std::string& value) &&;
    CrOSActionEvent_FileOpened& SetFilename(const std::string& value) &;
    CrOSActionEvent_FileOpened&& SetOpenType(const int64_t value) &&;
    CrOSActionEvent_FileOpened& SetOpenType(const int64_t value) &;
    CrOSActionEvent_FileOpened&& SetSequenceId(const int64_t value) &&;
    CrOSActionEvent_FileOpened& SetSequenceId(const int64_t value) &;
    CrOSActionEvent_FileOpened&& SetTimeSinceLastAction(const int64_t value) &&;
    CrOSActionEvent_FileOpened& SetTimeSinceLastAction(const int64_t value) &;
};

class CrOSActionEvent_SearchResultLaunched final : public ::metrics::structured::Event {
public:
    CrOSActionEvent_SearchResultLaunched();
    ~CrOSActionEvent_SearchResultLaunched() override;

    CrOSActionEvent_SearchResultLaunched&& SetQuery(const std::string& value) &&;
    CrOSActionEvent_SearchResultLaunched& SetQuery(const std::string& value) &;
    CrOSActionEvent_SearchResultLaunched&& SetResultType(const int64_t value) &&;
    CrOSActionEvent_SearchResultLaunched& SetResultType(const int64_t value) &;
    CrOSActionEvent_SearchResultLaunched&& SetSearchResultId(const std::string& value) &&;
    CrOSActionEvent_SearchResultLaunched& SetSearchResultId(const std::string& value) &;
    CrOSActionEvent_SearchResultLaunched&& SetSequenceId(const int64_t value) &&;
    CrOSActionEvent_SearchResultLaunched& SetSequenceId(const int64_t value) &;
    CrOSActionEvent_SearchResultLaunched&& SetTimeSinceLastAction(const int64_t value) &&;
    CrOSActionEvent_SearchResultLaunched& SetTimeSinceLastAction(const int64_t value) &;
};

class CrOSActionEvent_SettingChanged final : public ::metrics::structured::Event {
public:
    CrOSActionEvent_SettingChanged();
    ~CrOSActionEvent_SettingChanged() override;

    CrOSActionEvent_SettingChanged&& SetCurrentValue(const int64_t value) &&;
    CrOSActionEvent_SettingChanged& SetCurrentValue(const int64_t value) &;
    CrOSActionEvent_SettingChanged&& SetPreviousValue(const int64_t value) &&;
    CrOSActionEvent_SettingChanged& SetPreviousValue(const int64_t value) &;
    CrOSActionEvent_SettingChanged&& SetSequenceId(const int64_t value) &&;
    CrOSActionEvent_SettingChanged& SetSequenceId(const int64_t value) &;
    CrOSActionEvent_SettingChanged&& SetSettingId(const int64_t value) &&;
    CrOSActionEvent_SettingChanged& SetSettingId(const int64_t value) &;
    CrOSActionEvent_SettingChanged&& SetSettingType(const int64_t value) &&;
    CrOSActionEvent_SettingChanged& SetSettingType(const int64_t value) &;
    CrOSActionEvent_SettingChanged&& SetTimeSinceLastAction(const int64_t value) &&;
    CrOSActionEvent_SettingChanged& SetTimeSinceLastAction(const int64_t value) &;
};

class CrOSActionEvent_TabEvent_TabNavigated final : public ::metrics::structured::Event {
public:
    CrOSActionEvent_TabEvent_TabNavigated();
    ~CrOSActionEvent_TabEvent_TabNavigated() override;

    CrOSActionEvent_TabEvent_TabNavigated&& SetPageTransition(const int64_t value) &&;
    CrOSActionEvent_TabEvent_TabNavigated& SetPageTransition(const int64_t value) &;
    CrOSActionEvent_TabEvent_TabNavigated&& SetSequenceId(const int64_t value) &&;
    CrOSActionEvent_TabEvent_TabNavigated& SetSequenceId(const int64_t value) &;
    CrOSActionEvent_TabEvent_TabNavigated&& SetTimeSinceLastAction(const int64_t value) &&;
    CrOSActionEvent_TabEvent_TabNavigated& SetTimeSinceLastAction(const int64_t value) &;
    CrOSActionEvent_TabEvent_TabNavigated&& SetURL(const std::string& value) &&;
    CrOSActionEvent_TabEvent_TabNavigated& SetURL(const std::string& value) &;
    CrOSActionEvent_TabEvent_TabNavigated&& SetVisibility(const int64_t value) &&;
    CrOSActionEvent_TabEvent_TabNavigated& SetVisibility(const int64_t value) &;
};

class CrOSActionEvent_TabEvent_TabOpened final : public ::metrics::structured::Event {
public:
    CrOSActionEvent_TabEvent_TabOpened();
    ~CrOSActionEvent_TabEvent_TabOpened() override;

    CrOSActionEvent_TabEvent_TabOpened&& SetSequenceId(const int64_t value) &&;
    CrOSActionEvent_TabEvent_TabOpened& SetSequenceId(const int64_t value) &;
    CrOSActionEvent_TabEvent_TabOpened&& SetTimeSinceLastAction(const int64_t value) &&;
    CrOSActionEvent_TabEvent_TabOpened& SetTimeSinceLastAction(const int64_t value) &;
    CrOSActionEvent_TabEvent_TabOpened&& SetURL(const std::string& value) &&;
    CrOSActionEvent_TabEvent_TabOpened& SetURL(const std::string& value) &;
    CrOSActionEvent_TabEvent_TabOpened&& SetURLOpened(const std::string& value) &&;
    CrOSActionEvent_TabEvent_TabOpened& SetURLOpened(const std::string& value) &;
    CrOSActionEvent_TabEvent_TabOpened&& SetWindowOpenDisposition(const int64_t value) &&;
    CrOSActionEvent_TabEvent_TabOpened& SetWindowOpenDisposition(const int64_t value) &;
};

class CrOSActionEvent_TabEvent_TabReactivated final : public ::metrics::structured::Event {
public:
    CrOSActionEvent_TabEvent_TabReactivated();
    ~CrOSActionEvent_TabEvent_TabReactivated() override;

    CrOSActionEvent_TabEvent_TabReactivated&& SetSequenceId(const int64_t value) &&;
    CrOSActionEvent_TabEvent_TabReactivated& SetSequenceId(const int64_t value) &;
    CrOSActionEvent_TabEvent_TabReactivated&& SetTimeSinceLastAction(const int64_t value) &&;
    CrOSActionEvent_TabEvent_TabReactivated& SetTimeSinceLastAction(const int64_t value) &;
    CrOSActionEvent_TabEvent_TabReactivated&& SetURL(const std::string& value) &&;
    CrOSActionEvent_TabEvent_TabReactivated& SetURL(const std::string& value) &;
};

} // namespace hindsight

namespace launcher_usage {

class LauncherUsage final : public ::metrics::structured::Event {
public:
    LauncherUsage();
    ~LauncherUsage() override;

    LauncherUsage&& SetApp(const std::string& value) &&;
    LauncherUsage& SetApp(const std::string& value) &;
    LauncherUsage&& SetDomain(const std::string& value) &&;
    LauncherUsage& SetDomain(const std::string& value) &;
    LauncherUsage&& SetHour(const int64_t value) &&;
    LauncherUsage& SetHour(const int64_t value) &;
    LauncherUsage&& SetProviderType(const int64_t value) &&;
    LauncherUsage& SetProviderType(const int64_t value) &;
    LauncherUsage&& SetScore(const int64_t value) &&;
    LauncherUsage& SetScore(const int64_t value) &;
    LauncherUsage&& SetSearchQuery(const std::string& value) &&;
    LauncherUsage& SetSearchQuery(const std::string& value) &;
    LauncherUsage&& SetSearchQueryLength(const int64_t value) &&;
    LauncherUsage& SetSearchQueryLength(const int64_t value) &;
    LauncherUsage&& SetTarget(const std::string& value) &&;
    LauncherUsage& SetTarget(const std::string& value) &;
};

} // namespace launcher_usage

namespace nearby_share {

class Discovery final : public ::metrics::structured::Event {
public:
    Discovery();
    ~Discovery() override;

    Discovery&& SetPlatform(const int64_t value) &&;
    Discovery& SetPlatform(const int64_t value) &;
    Discovery&& SetDeviceRelationship(const int64_t value) &&;
    Discovery& SetDeviceRelationship(const int64_t value) &;
    Discovery&& SetTimeToDiscovery(const int64_t value) &&;
    Discovery& SetTimeToDiscovery(const int64_t value) &;
};

class Throughput final : public ::metrics::structured::Event {
public:
    Throughput();
    ~Throughput() override;

    Throughput&& SetIsReceiving(const int64_t value) &&;
    Throughput& SetIsReceiving(const int64_t value) &;
    Throughput&& SetPlatform(const int64_t value) &&;
    Throughput& SetPlatform(const int64_t value) &;
    Throughput&& SetDeviceRelationship(const int64_t value) &&;
    Throughput& SetDeviceRelationship(const int64_t value) &;
    Throughput&& SetMedium(const int64_t value) &&;
    Throughput& SetMedium(const int64_t value) &;
    Throughput&& SetUpdateBytes(const int64_t value) &&;
    Throughput& SetUpdateBytes(const int64_t value) &;
    Throughput&& SetUpdateMillis(const int64_t value) &&;
    Throughput& SetUpdateMillis(const int64_t value) &;
    Throughput&& SetTransferredBytes(const int64_t value) &&;
    Throughput& SetTransferredBytes(const int64_t value) &;
    Throughput&& SetTotalTransferBytes(const int64_t value) &&;
    Throughput& SetTotalTransferBytes(const int64_t value) &;
};

class FileAttachment final : public ::metrics::structured::Event {
public:
    FileAttachment();
    ~FileAttachment() override;

    FileAttachment&& SetIsReceiving(const int64_t value) &&;
    FileAttachment& SetIsReceiving(const int64_t value) &;
    FileAttachment&& SetPlatform(const int64_t value) &&;
    FileAttachment& SetPlatform(const int64_t value) &;
    FileAttachment&& SetDeviceRelationship(const int64_t value) &&;
    FileAttachment& SetDeviceRelationship(const int64_t value) &;
    FileAttachment&& SetFileType(const int64_t value) &&;
    FileAttachment& SetFileType(const int64_t value) &;
    FileAttachment&& SetSize(const int64_t value) &&;
    FileAttachment& SetSize(const int64_t value) &;
    FileAttachment&& SetResult(const int64_t value) &&;
    FileAttachment& SetResult(const int64_t value) &;
};

class TextAttachment final : public ::metrics::structured::Event {
public:
    TextAttachment();
    ~TextAttachment() override;

    TextAttachment&& SetIsReceiving(const int64_t value) &&;
    TextAttachment& SetIsReceiving(const int64_t value) &;
    TextAttachment&& SetPlatform(const int64_t value) &&;
    TextAttachment& SetPlatform(const int64_t value) &;
    TextAttachment&& SetDeviceRelationship(const int64_t value) &&;
    TextAttachment& SetDeviceRelationship(const int64_t value) &;
    TextAttachment&& SetTextType(const int64_t value) &&;
    TextAttachment& SetTextType(const int64_t value) &;
    TextAttachment&& SetSize(const int64_t value) &&;
    TextAttachment& SetSize(const int64_t value) &;
    TextAttachment&& SetResult(const int64_t value) &&;
    TextAttachment& SetResult(const int64_t value) &;
};

class ShareSession final : public ::metrics::structured::Event {
public:
    ShareSession();
    ~ShareSession() override;

    ShareSession&& SetIsReceiving(const int64_t value) &&;
    ShareSession& SetIsReceiving(const int64_t value) &;
    ShareSession&& SetPlatform(const int64_t value) &&;
    ShareSession& SetPlatform(const int64_t value) &;
    ShareSession&& SetDeviceRelationship(const int64_t value) &&;
    ShareSession& SetDeviceRelationship(const int64_t value) &;
    ShareSession&& SetTimeToDiscovery(const int64_t value) &&;
    ShareSession& SetTimeToDiscovery(const int64_t value) &;
    ShareSession&& SetTimeToSelect(const int64_t value) &&;
    ShareSession& SetTimeToSelect(const int64_t value) &;
    ShareSession&& SetTimeToConnect(const int64_t value) &&;
    ShareSession& SetTimeToConnect(const int64_t value) &;
    ShareSession&& SetTimeToAccept(const int64_t value) &&;
    ShareSession& SetTimeToAccept(const int64_t value) &;
    ShareSession&& SetTimeToTransferComplete(const int64_t value) &&;
    ShareSession& SetTimeToTransferComplete(const int64_t value) &;
    ShareSession&& SetInitialMedium(const int64_t value) &&;
    ShareSession& SetInitialMedium(const int64_t value) &;
    ShareSession&& SetTimeToUpgrade(const int64_t value) &&;
    ShareSession& SetTimeToUpgrade(const int64_t value) &;
    ShareSession&& SetFinalMedium(const int64_t value) &&;
    ShareSession& SetFinalMedium(const int64_t value) &;
    ShareSession&& SetNumberOfFiles(const int64_t value) &&;
    ShareSession& SetNumberOfFiles(const int64_t value) &;
    ShareSession&& SetNumberOfTexts(const int64_t value) &&;
    ShareSession& SetNumberOfTexts(const int64_t value) &;
    ShareSession&& SetNumberOfWiFiCredentials(const int64_t value) &&;
    ShareSession& SetNumberOfWiFiCredentials(const int64_t value) &;
    ShareSession&& SetTotalTransferBytes(const int64_t value) &&;
    ShareSession& SetTotalTransferBytes(const int64_t value) &;
    ShareSession&& SetBytesTransferred(const int64_t value) &&;
    ShareSession& SetBytesTransferred(const int64_t value) &;
    ShareSession&& SetResult(const int64_t value) &&;
    ShareSession& SetResult(const int64_t value) &;
};

} // namespace nearby_share

namespace phone_hub {

class SessionDetails final : public ::metrics::structured::Event {
public:
    SessionDetails();
    ~SessionDetails() override;

    SessionDetails&& SetSessionId(const std::string& value) &&;
    SessionDetails& SetSessionId(const std::string& value) &;
    SessionDetails&& SetTimestamp(const int64_t value) &&;
    SessionDetails& SetTimestamp(const int64_t value) &;
    SessionDetails&& SetConnectionMedium(const int64_t value) &&;
    SessionDetails& SetConnectionMedium(const int64_t value) &;
    SessionDetails&& SetChromebookBluetoothStack(const int64_t value) &&;
    SessionDetails& SetChromebookBluetoothStack(const int64_t value) &;
    SessionDetails&& SetDevicesNetworkState(const int64_t value) &&;
    SessionDetails& SetDevicesNetworkState(const int64_t value) &;
    SessionDetails&& SetChromebookLocale(const std::string& value) &&;
    SessionDetails& SetChromebookLocale(const std::string& value) &;
    SessionDetails&& SetChromebookPseudonymousId(const std::string& value) &&;
    SessionDetails& SetChromebookPseudonymousId(const std::string& value) &;
    SessionDetails&& SetPhoneManufacturer(const std::string& value) &&;
    SessionDetails& SetPhoneManufacturer(const std::string& value) &;
    SessionDetails&& SetPhoneModel(const std::string& value) &&;
    SessionDetails& SetPhoneModel(const std::string& value) &;
    SessionDetails&& SetPhoneAndroidVersion(const int64_t value) &&;
    SessionDetails& SetPhoneAndroidVersion(const int64_t value) &;
    SessionDetails&& SetPhoneAmbientApkVersion(const int64_t value) &&;
    SessionDetails& SetPhoneAmbientApkVersion(const int64_t value) &;
    SessionDetails&& SetPhoneGmsCoreVersion(const int64_t value) &&;
    SessionDetails& SetPhoneGmsCoreVersion(const int64_t value) &;
    SessionDetails&& SetPhoneProfile(const int64_t value) &&;
    SessionDetails& SetPhoneProfile(const int64_t value) &;
    SessionDetails&& SetPhoneNetworkStatus(const int64_t value) &&;
    SessionDetails& SetPhoneNetworkStatus(const int64_t value) &;
    SessionDetails&& SetPhoneLocale(const std::string& value) &&;
    SessionDetails& SetPhoneLocale(const std::string& value) &;
    SessionDetails&& SetPhonePseudonymousId(const std::string& value) &&;
    SessionDetails& SetPhonePseudonymousId(const std::string& value) &;
    SessionDetails&& SetPhoneInfoLastUpdatedTimestamp(const int64_t value) &&;
    SessionDetails& SetPhoneInfoLastUpdatedTimestamp(const int64_t value) &;
};

class DiscoveryStarted final : public ::metrics::structured::Event {
public:
    DiscoveryStarted();
    ~DiscoveryStarted() override;

    DiscoveryStarted&& SetSessionId(const std::string& value) &&;
    DiscoveryStarted& SetSessionId(const std::string& value) &;
    DiscoveryStarted&& SetTimestamp(const int64_t value) &&;
    DiscoveryStarted& SetTimestamp(const int64_t value) &;
    DiscoveryStarted&& SetDiscoveryEntrypoint(const int64_t value) &&;
    DiscoveryStarted& SetDiscoveryEntrypoint(const int64_t value) &;
};

class DiscoveryFinished final : public ::metrics::structured::Event {
public:
    DiscoveryFinished();
    ~DiscoveryFinished() override;

    DiscoveryFinished&& SetSessionId(const std::string& value) &&;
    DiscoveryFinished& SetSessionId(const std::string& value) &;
    DiscoveryFinished&& SetTimestamp(const int64_t value) &&;
    DiscoveryFinished& SetTimestamp(const int64_t value) &;
    DiscoveryFinished&& SetDiscoeryResult(const int64_t value) &&;
    DiscoveryFinished& SetDiscoeryResult(const int64_t value) &;
    DiscoveryFinished&& SetDiscoveryResultErrorCode(const int64_t value) &&;
    DiscoveryFinished& SetDiscoveryResultErrorCode(const int64_t value) &;
};

class NearbyConnection final : public ::metrics::structured::Event {
public:
    NearbyConnection();
    ~NearbyConnection() override;

    NearbyConnection&& SetSessionId(const std::string& value) &&;
    NearbyConnection& SetSessionId(const std::string& value) &;
    NearbyConnection&& SetTimestamp(const int64_t value) &&;
    NearbyConnection& SetTimestamp(const int64_t value) &;
    NearbyConnection&& SetNearbyConnectionStep(const int64_t value) &&;
    NearbyConnection& SetNearbyConnectionStep(const int64_t value) &;
    NearbyConnection&& SetNearbyConnectionStepResult(const int64_t value) &&;
    NearbyConnection& SetNearbyConnectionStepResult(const int64_t value) &;
};

class SecureChannelAuthentication final : public ::metrics::structured::Event {
public:
    SecureChannelAuthentication();
    ~SecureChannelAuthentication() override;

    SecureChannelAuthentication&& SetSessionId(const std::string& value) &&;
    SecureChannelAuthentication& SetSessionId(const std::string& value) &;
    SecureChannelAuthentication&& SetTimestamp(const int64_t value) &&;
    SecureChannelAuthentication& SetTimestamp(const int64_t value) &;
    SecureChannelAuthentication&& SetSecureChannelAuthenticationState(const int64_t value) &&;
    SecureChannelAuthentication& SetSecureChannelAuthenticationState(const int64_t value) &;
};

class PhoneHubMessage final : public ::metrics::structured::Event {
public:
    PhoneHubMessage();
    ~PhoneHubMessage() override;

    PhoneHubMessage&& SetSessionId(const std::string& value) &&;
    PhoneHubMessage& SetSessionId(const std::string& value) &;
    PhoneHubMessage&& SetTimestamp(const int64_t value) &&;
    PhoneHubMessage& SetTimestamp(const int64_t value) &;
    PhoneHubMessage&& SetPhoneHubMessageType(const int64_t value) &&;
    PhoneHubMessage& SetPhoneHubMessageType(const int64_t value) &;
    PhoneHubMessage&& SetPhoneHubMessageDirection(const int64_t value) &&;
    PhoneHubMessage& SetPhoneHubMessageDirection(const int64_t value) &;
};

class PhoneHubUiUpdate final : public ::metrics::structured::Event {
public:
    PhoneHubUiUpdate();
    ~PhoneHubUiUpdate() override;

    PhoneHubUiUpdate&& SetSessionId(const std::string& value) &&;
    PhoneHubUiUpdate& SetSessionId(const std::string& value) &;
    PhoneHubUiUpdate&& SetTimestamp(const int64_t value) &&;
    PhoneHubUiUpdate& SetTimestamp(const int64_t value) &;
    PhoneHubUiUpdate&& SetPhoneHubUiState(const int64_t value) &&;
    PhoneHubUiUpdate& SetPhoneHubUiState(const int64_t value) &;
};

} // namespace phone_hub

namespace structured_metrics {

class Initialization final : public ::metrics::structured::Event {
public:
    Initialization();
    ~Initialization() override;

    Initialization&& SetPlatform(const int64_t value) &&;
    Initialization& SetPlatform(const int64_t value) &;
};

} // namespace structured_metrics

namespace cr_os_events {

enum class AppInstallSurface {
    APP_PRELOAD_SERVICE_OEM = 0,
    APP_PRELOAD_SERVICE_DEFAULT = 1,
    OOBE_APP_RECOMMENDATIONS = 2,
    APP_INSTALL_URI_UNKNOWN = 3,
    APP_INSTALL_URI_SHOWOFF = 4,
    APP_INSTALL_URI_MALL = 5,
    APP_INSTALL_URI_GETIT = 6,
    APP_INSTALL_URI_LAUNCHER = 7,
    APP_INSTALL_URI_PERIPHERALS = 8,
    APP_INSTALL_URI_MALL_V2 = 9
};

enum class CameraAppLaunchType { DEFAULT = 0, ASSISTANT = 1 };

enum class CameraAppMode { PHOTO = 0, VIDEO = 1, SCAN = 2, PORTRAIT = 3 };

enum class CameraAppFacing { ENVIRONMENT = 0, USER = 1, EXTERNAL = 2, UNKNOWN = 3 };

enum class CameraAppGridType { NONE = 0, THREE_BY_THREE = 1, FOUR_BY_FOUR = 2, GOLDEN = 3 };

enum class CameraAppTimerType { NONE = 0, THREE_SECONDS = 1, TEN_SECONDS = 2 };

enum class CameraAppShutterType { UNKNOWN = 0, ASSISTANT = 1, KEYBOARD = 2, MOUSE = 3, TOUCH = 4, VOLUME_KEY = 5 };

enum class CameraAppPressure { NOMINAL = 0, FAIR = 1, SERIOUS = 2, CRITICAL = 3 };

enum class CameraAppAndroidIntentResultType { NON_INTENT = 0, CONFIRMED = 1, CANCELED = 2 };

enum class CameraAppResolutionLevel { UNKNOWN = 0, FOUR_K = 1, QUAD_HD = 2, FULL_HD = 3, HD = 4, THREE_HUNDRED_THIRTY_P = 5, FULL = 6, MEDIUM = 7 };

enum class CameraAppAspectRatioSet { OTHERS = 0, FOUR_TO_THREE = 1, SIXTEEN_TO_NINE = 2, SQUARE = 3 };

enum class CameraAppRecordType { NOT_RECORDING = 0, NORMAL = 1, GIF = 2, TIMELAPSE = 3 };

enum class CameraAppGifResultType { NOT_GIF = 0, RETAKE = 1, SHARE = 2, SAVE = 3 };

enum class CameraAppDocScanActionType { ADD_PAGE = 0, DELETE_PAGE = 1, FIX = 2 };

enum class CameraAppDocScanResultType { CANCEL = 0, SAVE_AS_PDF = 1, SAVE_AS_PHOTO = 2, SHARE = 3 };

enum class CameraAppLowStorageActionType {
    MANAGE_STORAGE_AUTO_STOP = 0,
    MANAGE_STORAGE_CANNOT_START = 1,
    SHOW_AUTO_STOP_DIALOG = 2,
    SHOW_CANNOT_START_DIALOG = 3,
    SHOW_WARNING_MESSAGE = 4
};

enum class CameraAppBarcodeContentType { TEXT = 0, URL = 1, WIFI = 2 };

enum class CameraAppWifiSecurityType { NONE = 0, EAP = 1, WEP = 2, WPA = 3 };

enum class CameraAppPerfEventType {
    CAMERA_SWITCHING = 0,
    GIF_CAPTURE_POST_PROCESSING = 1,
    LAUNCHING_FROM_LAUNCH_APP_COLD = 2,
    LAUNCHING_FROM_LAUNCH_APP_WARM = 3,
    LAUNCHING_FROM_WINDOW_CREATION = 4,
    MODE_SWITCHING = 5,
    PHOTO_CAPTURE_POST_PROCESSING_SAVING = 6,
    PHOTO_CAPTURE_SHUTTER = 7,
    PHOTO_TAKING = 8,
    PORTRAIT_MODE_CAPTURE_POST_PROCESSING_SAVING = 9,
    TIMELAPSE_CAPTURE_POST_PROCESSING_SAVING = 10,
    VIDEO_CAPTURE_POST_PROCESSING_SAVING = 11,
    SNAPSHOT_TAKING = 12,
    DOCUMENT_CAPTURE_POST_PROCESSING = 13,
    DOCUMENT_PDF_SAVING = 14,
    OCR_SCANNING = 15,
    GIF_CAPTURE_SAVING = 16
};

enum class CameraAppOcrEventType { COPY_TEXT = 0, TEXT_DETECTED = 1 };

enum class CampaignButtonId { PRIMARY = 0, SECONDARY = 1, OTHERS = 2, CLOSE = 3 };

enum class QuickStartAbortFlowReason {
    USER_CLICKED_BACK = 0,
    USER_CLICKED_CANCEL = 1,
    SIGNIN_SCHOOL = 2,
    ENTERPRISE_ENROLLMENT = 3,
    QS_ERROR = 4,
    ADD_CHILD = 5
};

enum class QuickStartEntryPoint { WELCOME_SCREEN = 0, NETWORK_SCREEN = 1, GAIA_INFO_SCREEN = 2, GAIA_SCREEN = 3 };

enum class QuickStartScreenName {
    OTHER = 0,
    NONE = 1,
    WELCOME_SCREEN = 2,
    NETWORK_SCREEN = 3,
    GAIA_SCREEN = 4,
    QS_SETUP_WITH_ANDROID_PHONE = 5,
    QS_CONNECTING_TO_WIFI = 6,
    CHECKING_FOR_UPDATE_AND_DETERMINING_DEVICE_CONFIG = 7,
    CHOOSE_CHROMEBOOK_SETUP = 8,
    CONSUMER_UPDATE = 9,
    QS_RESUMING_CONNECTION_AFTER_UPDATE = 10,
    QS_GETTING_GOOGLE_ACCOUNT_INFO = 11,
    QS_COMPLETE = 12,
    SETUP_DEVICE_PIN = 13,
    ADD_CHILD = 14,
    REVIEW_PRIVACY_AND_TERMS = 15,
    UNIFIED_SETUP = 16,
    GAIA_INFO_SCREEN = 17,
    QS_WIFI_CREDENTIALS_RECEIVED = 18,
    QS_SELECT_GOOGLE_ACCOUNT = 19,
    QS_CREATING_ACCOUNT = 20,
    QS_FALLBACK_URL = 21
};

enum class PickerInputFieldType {
    NONE = 0,
    PLAIN_TEXT = 1,
    RICH_TEXT = 2,
    PASSWORD = 3,
    SEARCH = 4,
    EMAIL = 5,
    NUMBER = 6,
    TELEPHONE = 7,
    URL = 8,
    DATE_TIME = 9,
    OTHER = 10
};

enum class PickerSessionOutcome { UNKNOWN = 0, INSERTED_OR_COPIED = 1, ABANDONED = 2, REDIRECTED = 3, FORMAT = 4, OPEN_FILE = 5, OPEN_LINK = 6, CREATE = 7 };

enum class PickerAction {
    UNKNOWN = 0,
    OPEN_EDITOR_WRITE = 1,
    OPEN_EDITOR_REWRITE = 2,
    OPEN_LOBSTER = 2,
    OPEN_LINKS = 3,
    OPEN_EXPRESSIONS = 4,
    OPEN_CLIPBOARD = 5,
    OPEN_DRIVE_FILES = 6,
    OPEN_LOCAL_FILES = 7,
    OPEN_DATES_TIMES = 8,
    OPEN_UNITS_MATHS = 9,
    TRANSFORM_UPPER_CASE = 10,
    TRANSFORM_LOWER_CASE = 11,
    TRANSFORM_SENTENCE_CASE = 12,
    TRANSFORM_TITLE_CASE = 13,
    CAPS_ON = 14,
    CAPS_OFF = 15
};

enum class PickerResultSource {
    UNKNOWN = 0,
    OMNIBOX = 1,
    EMOJI = 2,
    CLIPBOARD = 3,
    DRIVE_FILES = 4,
    LOCAL_FILES = 5,
    DATES_TIMES = 6,
    UNITS_MATHS = 7,
    CASE_TRANSFORM = 8,
    TENOR = 9
};

enum class PickerResultType {
    UNKNOWN = 0,
    TEXT = 1,
    EMOJI = 2,
    SYMBOL = 3,
    EMOTICON = 4,
    CLIPBOARD_FILE = 5,
    CLIPBOARD_TEXT = 6,
    CLIPBOARD_IMAGE = 7,
    CLIPBOARD_HTML = 8,
    GIF = 9,
    LINK = 10,
    LOCAL_FILE = 11,
    DRIVE_FILE = 12
};

enum class RecorderAppSpeakerLabelEnableState { ENABLED = 0, DISABLED_FIRST = 1, DISABLED = 2, UNKNOWN = 3, NOT_AVAILABLE = 4 };

enum class RecorderAppSummaryEnableState { ENABLED = 0, DISABLED = 1, UNKNOWN = 2, NOT_AVAILABLE = 3 };

enum class RecorderAppTranscriptionEnableState { ENABLED = 0, DISABLED_FIRST = 1, DISABLED = 2, UNKNOWN = 3, NOT_AVAILABLE = 4 };

enum class RecorderAppMicrophoneType { INTERNAL = 0, EXTERNAL = 1 };

enum class RecorderAppTranscriptionLocale {
    NONE = 0,
    EN_US = 1,
    JA_JP = 2,
    DE_DE = 3,
    ES_ES = 4,
    FR_FR = 5,
    IT_IT = 6,
    EN_CA = 7,
    EN_AU = 8,
    EN_GB = 9,
    EN_IE = 10,
    EN_SG = 11,
    FR_BE = 12,
    FR_CH = 13,
    EN_IN = 14,
    IT_CH = 15,
    DE_AT = 16,
    DE_BE = 17,
    DE_CH = 18,
    ES_US = 19,
    HI_IN = 20,
    PT_BR = 21,
    ID_ID = 22,
    KO_KR = 23,
    PL_PL = 24,
    TH_TH = 25,
    TR_TR = 26,
    ZH_CN = 27,
    ZH_TW = 28,
    DA_DK = 29,
    FR_CA = 30,
    NB_NO = 31,
    NL_NL = 32,
    SV_SE = 33,
    RU_RU = 34,
    VI_VN = 35
};

enum class RecorderAppModelResultStatus {
    SUCCESS = 0,
    GENERAL_ERROR = 1,
    UNSAFE = 2,
    UNSUPPORTED_TRANSCRIPTION_IS_TOO_SHORT = 3,
    UNSUPPORTED_TRANSCRIPTION_IS_TOO_LONG = 4,
    UNSUPPORTED_LANGUAGE = 5
};

enum class RecorderAppModelFeedback { NEGATIVE = 0, POSITIVE = 1 };

enum class RecorderAppAudioFormat { NOT_EXPORTED = 0, WEBM_ORIGINAL = 1 };

enum class RecorderAppTranscriptFormat { NOT_AVAILABLE = 0, NOT_EXPORTED = 1, TXT = 2 };

class AppDiscovery_AppInstalled final : public ::metrics::structured::Event {
public:
    AppDiscovery_AppInstalled();
    ~AppDiscovery_AppInstalled() override;

    AppDiscovery_AppInstalled&& SetAppId(const std::string& value) &&;
    AppDiscovery_AppInstalled& SetAppId(const std::string& value) &;
    AppDiscovery_AppInstalled&& SetAppType(const int64_t value) &&;
    AppDiscovery_AppInstalled& SetAppType(const int64_t value) &;
    AppDiscovery_AppInstalled&& SetInstallSource(const int64_t value) &&;
    AppDiscovery_AppInstalled& SetInstallSource(const int64_t value) &;
    AppDiscovery_AppInstalled&& SetInstallReason(const int64_t value) &&;
    AppDiscovery_AppInstalled& SetInstallReason(const int64_t value) &;
};

class AppDiscovery_AppInstallService_InstallRequested final : public ::metrics::structured::Event {
public:
    AppDiscovery_AppInstallService_InstallRequested();
    ~AppDiscovery_AppInstallService_InstallRequested() override;

    AppDiscovery_AppInstallService_InstallRequested&& SetAppId(const std::string& value) &&;
    AppDiscovery_AppInstallService_InstallRequested& SetAppId(const std::string& value) &;
    AppDiscovery_AppInstallService_InstallRequested&& SetSurface(const AppInstallSurface value) &&;
    AppDiscovery_AppInstallService_InstallRequested& SetSurface(const AppInstallSurface value) &;
};

class AppDiscovery_AppLaunched final : public ::metrics::structured::Event {
public:
    AppDiscovery_AppLaunched();
    ~AppDiscovery_AppLaunched() override;

    AppDiscovery_AppLaunched&& SetAppId(const std::string& value) &&;
    AppDiscovery_AppLaunched& SetAppId(const std::string& value) &;
    AppDiscovery_AppLaunched&& SetAppType(const int64_t value) &&;
    AppDiscovery_AppLaunched& SetAppType(const int64_t value) &;
    AppDiscovery_AppLaunched&& SetLaunchSource(const int64_t value) &&;
    AppDiscovery_AppLaunched& SetLaunchSource(const int64_t value) &;
};

class AppDiscovery_AppUninstall final : public ::metrics::structured::Event {
public:
    AppDiscovery_AppUninstall();
    ~AppDiscovery_AppUninstall() override;

    AppDiscovery_AppUninstall&& SetAppId(const std::string& value) &&;
    AppDiscovery_AppUninstall& SetAppId(const std::string& value) &;
    AppDiscovery_AppUninstall&& SetAppType(const int64_t value) &&;
    AppDiscovery_AppUninstall& SetAppType(const int64_t value) &;
    AppDiscovery_AppUninstall&& SetUninstallSource(const int64_t value) &&;
    AppDiscovery_AppUninstall& SetUninstallSource(const int64_t value) &;
};

class AppDiscovery_AppStateChanged final : public ::metrics::structured::Event {
public:
    AppDiscovery_AppStateChanged();
    ~AppDiscovery_AppStateChanged() override;

    AppDiscovery_AppStateChanged&& SetAppId(const std::string& value) &&;
    AppDiscovery_AppStateChanged& SetAppId(const std::string& value) &;
    AppDiscovery_AppStateChanged&& SetAppState(const int64_t value) &&;
    AppDiscovery_AppStateChanged& SetAppState(const int64_t value) &;
};

class AppDiscovery_ArcAppCameraAccessed final : public ::metrics::structured::Event {
public:
    AppDiscovery_ArcAppCameraAccessed();
    ~AppDiscovery_ArcAppCameraAccessed() override;

    AppDiscovery_ArcAppCameraAccessed&& SetAppId(const std::string& value) &&;
    AppDiscovery_ArcAppCameraAccessed& SetAppId(const std::string& value) &;
};

class AppDiscovery_LauncherOpen final : public ::metrics::structured::Event {
public:
    AppDiscovery_LauncherOpen();
    ~AppDiscovery_LauncherOpen() override;
};

class AppDiscovery_AppLauncherResultOpened final : public ::metrics::structured::Event {
public:
    AppDiscovery_AppLauncherResultOpened();
    ~AppDiscovery_AppLauncherResultOpened() override;

    AppDiscovery_AppLauncherResultOpened&& SetFuzzyStringMatch(const double value) &&;
    AppDiscovery_AppLauncherResultOpened& SetFuzzyStringMatch(const double value) &;
    AppDiscovery_AppLauncherResultOpened&& SetAppId(const std::string& value) &&;
    AppDiscovery_AppLauncherResultOpened& SetAppId(const std::string& value) &;
    AppDiscovery_AppLauncherResultOpened&& SetAppName(const std::string& value) &&;
    AppDiscovery_AppLauncherResultOpened& SetAppName(const std::string& value) &;
    AppDiscovery_AppLauncherResultOpened&& SetResultCategory(const int64_t value) &&;
    AppDiscovery_AppLauncherResultOpened& SetResultCategory(const int64_t value) &;
};

class AppDiscovery_Browser_OmniboxInstallIconClicked final : public ::metrics::structured::Event {
public:
    AppDiscovery_Browser_OmniboxInstallIconClicked();
    ~AppDiscovery_Browser_OmniboxInstallIconClicked() override;

    AppDiscovery_Browser_OmniboxInstallIconClicked&& SetIPHShown(const int64_t value) &&;
    AppDiscovery_Browser_OmniboxInstallIconClicked& SetIPHShown(const int64_t value) &;
};

class AppDiscovery_Browser_AppInstallDialogShown final : public ::metrics::structured::Event {
public:
    AppDiscovery_Browser_AppInstallDialogShown();
    ~AppDiscovery_Browser_AppInstallDialogShown() override;

    AppDiscovery_Browser_AppInstallDialogShown&& SetAppId(const std::string& value) &&;
    AppDiscovery_Browser_AppInstallDialogShown& SetAppId(const std::string& value) &;
};

class AppDiscovery_Browser_AppInstallDialogResult final : public ::metrics::structured::Event {
public:
    AppDiscovery_Browser_AppInstallDialogResult();
    ~AppDiscovery_Browser_AppInstallDialogResult() override;

    AppDiscovery_Browser_AppInstallDialogResult&& SetWebAppInstallStatus(const int64_t value) &&;
    AppDiscovery_Browser_AppInstallDialogResult& SetWebAppInstallStatus(const int64_t value) &;
    AppDiscovery_Browser_AppInstallDialogResult&& SetAppId(const std::string& value) &&;
    AppDiscovery_Browser_AppInstallDialogResult& SetAppId(const std::string& value) &;
};

class AppDiscovery_Browser_ClickInstallAppFromMenu final : public ::metrics::structured::Event {
public:
    AppDiscovery_Browser_ClickInstallAppFromMenu();
    ~AppDiscovery_Browser_ClickInstallAppFromMenu() override;

    AppDiscovery_Browser_ClickInstallAppFromMenu&& SetAppId(const std::string& value) &&;
    AppDiscovery_Browser_ClickInstallAppFromMenu& SetAppId(const std::string& value) &;
};

class AppDiscovery_Browser_CreateShortcut final : public ::metrics::structured::Event {
public:
    AppDiscovery_Browser_CreateShortcut();
    ~AppDiscovery_Browser_CreateShortcut() override;

    AppDiscovery_Browser_CreateShortcut&& SetAppId(const std::string& value) &&;
    AppDiscovery_Browser_CreateShortcut& SetAppId(const std::string& value) &;
};

class CameraApp_StartSession final : public ::metrics::structured::Event {
public:
    CameraApp_StartSession();
    ~CameraApp_StartSession() override;

    CameraApp_StartSession&& SetLaunchType(const CameraAppLaunchType value) &&;
    CameraApp_StartSession& SetLaunchType(const CameraAppLaunchType value) &;
    CameraApp_StartSession&& SetLanguage(const int64_t value) &&;
    CameraApp_StartSession& SetLanguage(const int64_t value) &;
};

class CameraApp_Capture final : public ::metrics::structured::Event {
public:
    CameraApp_Capture();
    ~CameraApp_Capture() override;

    CameraApp_Capture&& SetMode(const CameraAppMode value) &&;
    CameraApp_Capture& SetMode(const CameraAppMode value) &;
    CameraApp_Capture&& SetFacing(const CameraAppFacing value) &&;
    CameraApp_Capture& SetFacing(const CameraAppFacing value) &;
    CameraApp_Capture&& SetIsMirrored(const int64_t value) &&;
    CameraApp_Capture& SetIsMirrored(const int64_t value) &;
    CameraApp_Capture&& SetGridType(const CameraAppGridType value) &&;
    CameraApp_Capture& SetGridType(const CameraAppGridType value) &;
    CameraApp_Capture&& SetTimerType(const CameraAppTimerType value) &&;
    CameraApp_Capture& SetTimerType(const CameraAppTimerType value) &;
    CameraApp_Capture&& SetShutterType(const CameraAppShutterType value) &&;
    CameraApp_Capture& SetShutterType(const CameraAppShutterType value) &;
    CameraApp_Capture&& SetAndroidIntentResultType(const CameraAppAndroidIntentResultType value) &&;
    CameraApp_Capture& SetAndroidIntentResultType(const CameraAppAndroidIntentResultType value) &;
    CameraApp_Capture&& SetIsWindowMaximized(const int64_t value) &&;
    CameraApp_Capture& SetIsWindowMaximized(const int64_t value) &;
    CameraApp_Capture&& SetIsWindowPortrait(const int64_t value) &&;
    CameraApp_Capture& SetIsWindowPortrait(const int64_t value) &;
    CameraApp_Capture&& SetResolutionWidth(const int64_t value) &&;
    CameraApp_Capture& SetResolutionWidth(const int64_t value) &;
    CameraApp_Capture&& SetResolutionHeight(const int64_t value) &&;
    CameraApp_Capture& SetResolutionHeight(const int64_t value) &;
    CameraApp_Capture&& SetResolutionLevel(const CameraAppResolutionLevel value) &&;
    CameraApp_Capture& SetResolutionLevel(const CameraAppResolutionLevel value) &;
    CameraApp_Capture&& SetAspectRatioSet(const CameraAppAspectRatioSet value) &&;
    CameraApp_Capture& SetAspectRatioSet(const CameraAppAspectRatioSet value) &;
    CameraApp_Capture&& SetIsVideoSnapshot(const int64_t value) &&;
    CameraApp_Capture& SetIsVideoSnapshot(const int64_t value) &;
    CameraApp_Capture&& SetIsMuted(const int64_t value) &&;
    CameraApp_Capture& SetIsMuted(const int64_t value) &;
    CameraApp_Capture&& SetFps(const int64_t value) &&;
    CameraApp_Capture& SetFps(const int64_t value) &;
    CameraApp_Capture&& SetEverPaused(const int64_t value) &&;
    CameraApp_Capture& SetEverPaused(const int64_t value) &;
    CameraApp_Capture&& SetDuration(const int64_t value) &&;
    CameraApp_Capture& SetDuration(const int64_t value) &;
    CameraApp_Capture&& SetRecordType(const CameraAppRecordType value) &&;
    CameraApp_Capture& SetRecordType(const CameraAppRecordType value) &;
    CameraApp_Capture&& SetGifResultType(const CameraAppGifResultType value) &&;
    CameraApp_Capture& SetGifResultType(const CameraAppGifResultType value) &;
    CameraApp_Capture&& SetTimelapseSpeed(const int64_t value) &&;
    CameraApp_Capture& SetTimelapseSpeed(const int64_t value) &;
    CameraApp_Capture&& SetZoomRatio(const double value) &&;
    CameraApp_Capture& SetZoomRatio(const double value) &;
};

class CameraApp_AndroidIntent final : public ::metrics::structured::Event {
public:
    CameraApp_AndroidIntent();
    ~CameraApp_AndroidIntent() override;

    CameraApp_AndroidIntent&& SetMode(const CameraAppMode value) &&;
    CameraApp_AndroidIntent& SetMode(const CameraAppMode value) &;
    CameraApp_AndroidIntent&& SetShouldHandleResult(const int64_t value) &&;
    CameraApp_AndroidIntent& SetShouldHandleResult(const int64_t value) &;
    CameraApp_AndroidIntent&& SetShouldDownscale(const int64_t value) &&;
    CameraApp_AndroidIntent& SetShouldDownscale(const int64_t value) &;
    CameraApp_AndroidIntent&& SetIsSecure(const int64_t value) &&;
    CameraApp_AndroidIntent& SetIsSecure(const int64_t value) &;
};

class CameraApp_OpenPTZPanel final : public ::metrics::structured::Event {
public:
    CameraApp_OpenPTZPanel();
    ~CameraApp_OpenPTZPanel() override;

    CameraApp_OpenPTZPanel&& SetSupportPan(const int64_t value) &&;
    CameraApp_OpenPTZPanel& SetSupportPan(const int64_t value) &;
    CameraApp_OpenPTZPanel&& SetSupportTilt(const int64_t value) &&;
    CameraApp_OpenPTZPanel& SetSupportTilt(const int64_t value) &;
    CameraApp_OpenPTZPanel&& SetSupportZoom(const int64_t value) &&;
    CameraApp_OpenPTZPanel& SetSupportZoom(const int64_t value) &;
};

class CameraApp_DocScanAction final : public ::metrics::structured::Event {
public:
    CameraApp_DocScanAction();
    ~CameraApp_DocScanAction() override;

    CameraApp_DocScanAction&& SetActionType(const CameraAppDocScanActionType value) &&;
    CameraApp_DocScanAction& SetActionType(const CameraAppDocScanActionType value) &;
};

class CameraApp_DocScanResult final : public ::metrics::structured::Event {
public:
    CameraApp_DocScanResult();
    ~CameraApp_DocScanResult() override;

    CameraApp_DocScanResult&& SetResultType(const CameraAppDocScanResultType value) &&;
    CameraApp_DocScanResult& SetResultType(const CameraAppDocScanResultType value) &;
    CameraApp_DocScanResult&& SetFixTypes(const int64_t value) &&;
    CameraApp_DocScanResult& SetFixTypes(const int64_t value) &;
    CameraApp_DocScanResult&& SetFixCount(const int64_t value) &&;
    CameraApp_DocScanResult& SetFixCount(const int64_t value) &;
    CameraApp_DocScanResult&& SetPageCount(const int64_t value) &&;
    CameraApp_DocScanResult& SetPageCount(const int64_t value) &;
};

class CameraApp_OpenCamera final : public ::metrics::structured::Event {
public:
    CameraApp_OpenCamera();
    ~CameraApp_OpenCamera() override;

    CameraApp_OpenCamera&& SetCameraModuleId(const std::string& value) &&;
    CameraApp_OpenCamera& SetCameraModuleId(const std::string& value) &;
};

class CameraApp_LowStorageAction final : public ::metrics::structured::Event {
public:
    CameraApp_LowStorageAction();
    ~CameraApp_LowStorageAction() override;

    CameraApp_LowStorageAction&& SetActionType(const CameraAppLowStorageActionType value) &&;
    CameraApp_LowStorageAction& SetActionType(const CameraAppLowStorageActionType value) &;
};

class CameraApp_BarcodeDetected final : public ::metrics::structured::Event {
public:
    CameraApp_BarcodeDetected();
    ~CameraApp_BarcodeDetected() override;

    CameraApp_BarcodeDetected&& SetContentType(const CameraAppBarcodeContentType value) &&;
    CameraApp_BarcodeDetected& SetContentType(const CameraAppBarcodeContentType value) &;
    CameraApp_BarcodeDetected&& SetWifiSecurityType(const CameraAppWifiSecurityType value) &&;
    CameraApp_BarcodeDetected& SetWifiSecurityType(const CameraAppWifiSecurityType value) &;
};

class CameraApp_Perf final : public ::metrics::structured::Event {
public:
    CameraApp_Perf();
    ~CameraApp_Perf() override;

    CameraApp_Perf&& SetEventType(const CameraAppPerfEventType value) &&;
    CameraApp_Perf& SetEventType(const CameraAppPerfEventType value) &;
    CameraApp_Perf&& SetDuration(const int64_t value) &&;
    CameraApp_Perf& SetDuration(const int64_t value) &;
    CameraApp_Perf&& SetFacing(const CameraAppFacing value) &&;
    CameraApp_Perf& SetFacing(const CameraAppFacing value) &;
    CameraApp_Perf&& SetResolutionWidth(const int64_t value) &&;
    CameraApp_Perf& SetResolutionWidth(const int64_t value) &;
    CameraApp_Perf&& SetResolutionHeight(const int64_t value) &&;
    CameraApp_Perf& SetResolutionHeight(const int64_t value) &;
    CameraApp_Perf&& SetPageCount(const int64_t value) &&;
    CameraApp_Perf& SetPageCount(const int64_t value) &;
    CameraApp_Perf&& SetPressure(const CameraAppPressure value) &&;
    CameraApp_Perf& SetPressure(const CameraAppPressure value) &;
};

class CameraApp_UnsupportedProtocol final : public ::metrics::structured::Event {
public:
    CameraApp_UnsupportedProtocol();
    ~CameraApp_UnsupportedProtocol() override;
};

class CameraApp_EndSession final : public ::metrics::structured::Event {
public:
    CameraApp_EndSession();
    ~CameraApp_EndSession() override;

    CameraApp_EndSession&& SetDuration(const int64_t value) &&;
    CameraApp_EndSession& SetDuration(const int64_t value) &;
};

class CameraApp_MemoryUsage final : public ::metrics::structured::Event {
public:
    CameraApp_MemoryUsage();
    ~CameraApp_MemoryUsage() override;

    CameraApp_MemoryUsage&& SetBehaviors(const int64_t value) &&;
    CameraApp_MemoryUsage& SetBehaviors(const int64_t value) &;
    CameraApp_MemoryUsage&& SetMemoryUsage(const int64_t value) &&;
    CameraApp_MemoryUsage& SetMemoryUsage(const int64_t value) &;
};

class CameraApp_Ocr final : public ::metrics::structured::Event {
public:
    CameraApp_Ocr();
    ~CameraApp_Ocr() override;

    CameraApp_Ocr&& SetEventType(const CameraAppOcrEventType value) &&;
    CameraApp_Ocr& SetEventType(const CameraAppOcrEventType value) &;
    CameraApp_Ocr&& SetIsPrimaryLanguage(const int64_t value) &&;
    CameraApp_Ocr& SetIsPrimaryLanguage(const int64_t value) &;
    CameraApp_Ocr&& SetLineCount(const int64_t value) &&;
    CameraApp_Ocr& SetLineCount(const int64_t value) &;
    CameraApp_Ocr&& SetWordCount(const int64_t value) &&;
    CameraApp_Ocr& SetWordCount(const int64_t value) &;
};

class Growth_Ui_ButtonPressed final : public ::metrics::structured::Event {
public:
    Growth_Ui_ButtonPressed();
    ~Growth_Ui_ButtonPressed() override;

    Growth_Ui_ButtonPressed&& SetCampaignId(const int64_t value) &&;
    Growth_Ui_ButtonPressed& SetCampaignId(const int64_t value) &;
    Growth_Ui_ButtonPressed&& SetButtonId(const CampaignButtonId value) &&;
    Growth_Ui_ButtonPressed& SetButtonId(const CampaignButtonId value) &;
};

class Growth_Ui_Dismissed final : public ::metrics::structured::Event {
public:
    Growth_Ui_Dismissed();
    ~Growth_Ui_Dismissed() override;

    Growth_Ui_Dismissed&& SetCampaignId(const int64_t value) &&;
    Growth_Ui_Dismissed& SetCampaignId(const int64_t value) &;
};

class Growth_Ui_Impression final : public ::metrics::structured::Event {
public:
    Growth_Ui_Impression();
    ~Growth_Ui_Impression() override;

    Growth_Ui_Impression&& SetCampaignId(const int64_t value) &&;
    Growth_Ui_Impression& SetCampaignId(const int64_t value) &;
};

class OOBE_GaiaSigninRequested final : public ::metrics::structured::Event {
public:
    OOBE_GaiaSigninRequested();
    ~OOBE_GaiaSigninRequested() override;

    OOBE_GaiaSigninRequested&& SetIsReauthentication(const int64_t value) &&;
    OOBE_GaiaSigninRequested& SetIsReauthentication(const int64_t value) &;
    OOBE_GaiaSigninRequested&& SetIsFlexFlow(const int64_t value) &&;
    OOBE_GaiaSigninRequested& SetIsFlexFlow(const int64_t value) &;
    OOBE_GaiaSigninRequested&& SetIsDemoModeFlow(const int64_t value) &&;
    OOBE_GaiaSigninRequested& SetIsDemoModeFlow(const int64_t value) &;
    OOBE_GaiaSigninRequested&& SetIsOwnerUser(const int64_t value) &&;
    OOBE_GaiaSigninRequested& SetIsOwnerUser(const int64_t value) &;
    OOBE_GaiaSigninRequested&& SetIsEphemeralOrMGS(const int64_t value) &&;
    OOBE_GaiaSigninRequested& SetIsEphemeralOrMGS(const int64_t value) &;
    OOBE_GaiaSigninRequested&& SetIsFirstOnboarding(const int64_t value) &&;
    OOBE_GaiaSigninRequested& SetIsFirstOnboarding(const int64_t value) &;
    OOBE_GaiaSigninRequested&& SetChromeMilestone(const int64_t value) &&;
    OOBE_GaiaSigninRequested& SetChromeMilestone(const int64_t value) &;
};

class OOBE_GaiaSigninCompleted final : public ::metrics::structured::Event {
public:
    OOBE_GaiaSigninCompleted();
    ~OOBE_GaiaSigninCompleted() override;

    OOBE_GaiaSigninCompleted&& SetIsReauthentication(const int64_t value) &&;
    OOBE_GaiaSigninCompleted& SetIsReauthentication(const int64_t value) &;
    OOBE_GaiaSigninCompleted&& SetIsFlexFlow(const int64_t value) &&;
    OOBE_GaiaSigninCompleted& SetIsFlexFlow(const int64_t value) &;
    OOBE_GaiaSigninCompleted&& SetIsDemoModeFlow(const int64_t value) &&;
    OOBE_GaiaSigninCompleted& SetIsDemoModeFlow(const int64_t value) &;
    OOBE_GaiaSigninCompleted&& SetIsOwnerUser(const int64_t value) &&;
    OOBE_GaiaSigninCompleted& SetIsOwnerUser(const int64_t value) &;
    OOBE_GaiaSigninCompleted&& SetIsEphemeralOrMGS(const int64_t value) &&;
    OOBE_GaiaSigninCompleted& SetIsEphemeralOrMGS(const int64_t value) &;
    OOBE_GaiaSigninCompleted&& SetIsFirstOnboarding(const int64_t value) &&;
    OOBE_GaiaSigninCompleted& SetIsFirstOnboarding(const int64_t value) &;
    OOBE_GaiaSigninCompleted&& SetChromeMilestone(const int64_t value) &&;
    OOBE_GaiaSigninCompleted& SetChromeMilestone(const int64_t value) &;
};

class OOBE_OobeStarted final : public ::metrics::structured::Event {
public:
    OOBE_OobeStarted();
    ~OOBE_OobeStarted() override;

    OOBE_OobeStarted&& SetIsFlexFlow(const int64_t value) &&;
    OOBE_OobeStarted& SetIsFlexFlow(const int64_t value) &;
    OOBE_OobeStarted&& SetChromeMilestone(const int64_t value) &&;
    OOBE_OobeStarted& SetChromeMilestone(const int64_t value) &;
};

class OOBE_PreLoginOobeCompleted final : public ::metrics::structured::Event {
public:
    OOBE_PreLoginOobeCompleted();
    ~OOBE_PreLoginOobeCompleted() override;

    OOBE_PreLoginOobeCompleted&& SetCompletedFlowType(const int64_t value) &&;
    OOBE_PreLoginOobeCompleted& SetCompletedFlowType(const int64_t value) &;
    OOBE_PreLoginOobeCompleted&& SetIsFlexFlow(const int64_t value) &&;
    OOBE_PreLoginOobeCompleted& SetIsFlexFlow(const int64_t value) &;
    OOBE_PreLoginOobeCompleted&& SetIsDemoModeFlow(const int64_t value) &&;
    OOBE_PreLoginOobeCompleted& SetIsDemoModeFlow(const int64_t value) &;
    OOBE_PreLoginOobeCompleted&& SetChromeMilestone(const int64_t value) &&;
    OOBE_PreLoginOobeCompleted& SetChromeMilestone(const int64_t value) &;
};

class OOBE_DeviceRegistered final : public ::metrics::structured::Event {
public:
    OOBE_DeviceRegistered();
    ~OOBE_DeviceRegistered() override;

    OOBE_DeviceRegistered&& SetIsFirstOnboarding(const int64_t value) &&;
    OOBE_DeviceRegistered& SetIsFirstOnboarding(const int64_t value) &;
    OOBE_DeviceRegistered&& SetIsFlexFlow(const int64_t value) &&;
    OOBE_DeviceRegistered& SetIsFlexFlow(const int64_t value) &;
    OOBE_DeviceRegistered&& SetIsDemoModeFlow(const int64_t value) &&;
    OOBE_DeviceRegistered& SetIsDemoModeFlow(const int64_t value) &;
    OOBE_DeviceRegistered&& SetChromeMilestone(const int64_t value) &&;
    OOBE_DeviceRegistered& SetChromeMilestone(const int64_t value) &;
};

class OOBE_OobeCompleted final : public ::metrics::structured::Event {
public:
    OOBE_OobeCompleted();
    ~OOBE_OobeCompleted() override;

    OOBE_OobeCompleted&& SetIsFlexFlow(const int64_t value) &&;
    OOBE_OobeCompleted& SetIsFlexFlow(const int64_t value) &;
    OOBE_OobeCompleted&& SetIsDemoModeFlow(const int64_t value) &&;
    OOBE_OobeCompleted& SetIsDemoModeFlow(const int64_t value) &;
    OOBE_OobeCompleted&& SetIsOwnerUser(const int64_t value) &&;
    OOBE_OobeCompleted& SetIsOwnerUser(const int64_t value) &;
    OOBE_OobeCompleted&& SetIsEphemeralOrMGS(const int64_t value) &&;
    OOBE_OobeCompleted& SetIsEphemeralOrMGS(const int64_t value) &;
    OOBE_OobeCompleted&& SetIsFirstOnboarding(const int64_t value) &&;
    OOBE_OobeCompleted& SetIsFirstOnboarding(const int64_t value) &;
    OOBE_OobeCompleted&& SetChromeMilestone(const int64_t value) &&;
    OOBE_OobeCompleted& SetChromeMilestone(const int64_t value) &;
};

class OOBE_OnboardingStarted final : public ::metrics::structured::Event {
public:
    OOBE_OnboardingStarted();
    ~OOBE_OnboardingStarted() override;

    OOBE_OnboardingStarted&& SetIsFlexFlow(const int64_t value) &&;
    OOBE_OnboardingStarted& SetIsFlexFlow(const int64_t value) &;
    OOBE_OnboardingStarted&& SetIsDemoModeFlow(const int64_t value) &&;
    OOBE_OnboardingStarted& SetIsDemoModeFlow(const int64_t value) &;
    OOBE_OnboardingStarted&& SetIsOwnerUser(const int64_t value) &&;
    OOBE_OnboardingStarted& SetIsOwnerUser(const int64_t value) &;
    OOBE_OnboardingStarted&& SetIsEphemeralOrMGS(const int64_t value) &&;
    OOBE_OnboardingStarted& SetIsEphemeralOrMGS(const int64_t value) &;
    OOBE_OnboardingStarted&& SetIsFirstOnboarding(const int64_t value) &&;
    OOBE_OnboardingStarted& SetIsFirstOnboarding(const int64_t value) &;
    OOBE_OnboardingStarted&& SetChromeMilestone(const int64_t value) &&;
    OOBE_OnboardingStarted& SetChromeMilestone(const int64_t value) &;
};

class OOBE_OnboardingCompleted final : public ::metrics::structured::Event {
public:
    OOBE_OnboardingCompleted();
    ~OOBE_OnboardingCompleted() override;

    OOBE_OnboardingCompleted&& SetIsFlexFlow(const int64_t value) &&;
    OOBE_OnboardingCompleted& SetIsFlexFlow(const int64_t value) &;
    OOBE_OnboardingCompleted&& SetIsDemoModeFlow(const int64_t value) &&;
    OOBE_OnboardingCompleted& SetIsDemoModeFlow(const int64_t value) &;
    OOBE_OnboardingCompleted&& SetIsOwnerUser(const int64_t value) &&;
    OOBE_OnboardingCompleted& SetIsOwnerUser(const int64_t value) &;
    OOBE_OnboardingCompleted&& SetIsEphemeralOrMGS(const int64_t value) &&;
    OOBE_OnboardingCompleted& SetIsEphemeralOrMGS(const int64_t value) &;
    OOBE_OnboardingCompleted&& SetIsFirstOnboarding(const int64_t value) &&;
    OOBE_OnboardingCompleted& SetIsFirstOnboarding(const int64_t value) &;
    OOBE_OnboardingCompleted&& SetChromeMilestone(const int64_t value) &&;
    OOBE_OnboardingCompleted& SetChromeMilestone(const int64_t value) &;
};

class OOBE_PageEntered final : public ::metrics::structured::Event {
public:
    OOBE_PageEntered();
    ~OOBE_PageEntered() override;

    OOBE_PageEntered&& SetPageId(const std::string& value) &&;
    OOBE_PageEntered& SetPageId(const std::string& value) &;
    OOBE_PageEntered&& SetIsFlexFlow(const int64_t value) &&;
    OOBE_PageEntered& SetIsFlexFlow(const int64_t value) &;
    OOBE_PageEntered&& SetIsDemoModeFlow(const int64_t value) &&;
    OOBE_PageEntered& SetIsDemoModeFlow(const int64_t value) &;
    OOBE_PageEntered&& SetIsOwnerUser(const int64_t value) &&;
    OOBE_PageEntered& SetIsOwnerUser(const int64_t value) &;
    OOBE_PageEntered&& SetIsEphemeralOrMGS(const int64_t value) &&;
    OOBE_PageEntered& SetIsEphemeralOrMGS(const int64_t value) &;
    OOBE_PageEntered&& SetIsFirstOnboarding(const int64_t value) &&;
    OOBE_PageEntered& SetIsFirstOnboarding(const int64_t value) &;
    OOBE_PageEntered&& SetChromeMilestone(const int64_t value) &&;
    OOBE_PageEntered& SetChromeMilestone(const int64_t value) &;
};

class OOBE_PageSkippedBySystem final : public ::metrics::structured::Event {
public:
    OOBE_PageSkippedBySystem();
    ~OOBE_PageSkippedBySystem() override;

    OOBE_PageSkippedBySystem&& SetPageId(const std::string& value) &&;
    OOBE_PageSkippedBySystem& SetPageId(const std::string& value) &;
    OOBE_PageSkippedBySystem&& SetIsFlexFlow(const int64_t value) &&;
    OOBE_PageSkippedBySystem& SetIsFlexFlow(const int64_t value) &;
    OOBE_PageSkippedBySystem&& SetIsDemoModeFlow(const int64_t value) &&;
    OOBE_PageSkippedBySystem& SetIsDemoModeFlow(const int64_t value) &;
    OOBE_PageSkippedBySystem&& SetIsOwnerUser(const int64_t value) &&;
    OOBE_PageSkippedBySystem& SetIsOwnerUser(const int64_t value) &;
    OOBE_PageSkippedBySystem&& SetIsEphemeralOrMGS(const int64_t value) &&;
    OOBE_PageSkippedBySystem& SetIsEphemeralOrMGS(const int64_t value) &;
    OOBE_PageSkippedBySystem&& SetIsFirstOnboarding(const int64_t value) &&;
    OOBE_PageSkippedBySystem& SetIsFirstOnboarding(const int64_t value) &;
    OOBE_PageSkippedBySystem&& SetChromeMilestone(const int64_t value) &&;
    OOBE_PageSkippedBySystem& SetChromeMilestone(const int64_t value) &;
};

class OOBE_PageLeft final : public ::metrics::structured::Event {
public:
    OOBE_PageLeft();
    ~OOBE_PageLeft() override;

    OOBE_PageLeft&& SetPageId(const std::string& value) &&;
    OOBE_PageLeft& SetPageId(const std::string& value) &;
    OOBE_PageLeft&& SetExitReason(const std::string& value) &&;
    OOBE_PageLeft& SetExitReason(const std::string& value) &;
    OOBE_PageLeft&& SetIsFlexFlow(const int64_t value) &&;
    OOBE_PageLeft& SetIsFlexFlow(const int64_t value) &;
    OOBE_PageLeft&& SetIsDemoModeFlow(const int64_t value) &&;
    OOBE_PageLeft& SetIsDemoModeFlow(const int64_t value) &;
    OOBE_PageLeft&& SetIsOwnerUser(const int64_t value) &&;
    OOBE_PageLeft& SetIsOwnerUser(const int64_t value) &;
    OOBE_PageLeft&& SetIsEphemeralOrMGS(const int64_t value) &&;
    OOBE_PageLeft& SetIsEphemeralOrMGS(const int64_t value) &;
    OOBE_PageLeft&& SetIsFirstOnboarding(const int64_t value) &&;
    OOBE_PageLeft& SetIsFirstOnboarding(const int64_t value) &;
    OOBE_PageLeft&& SetChromeMilestone(const int64_t value) &&;
    OOBE_PageLeft& SetChromeMilestone(const int64_t value) &;
};

class OOBE_PreLoginOobeResumed final : public ::metrics::structured::Event {
public:
    OOBE_PreLoginOobeResumed();
    ~OOBE_PreLoginOobeResumed() override;

    OOBE_PreLoginOobeResumed&& SetPendingPageId(const std::string& value) &&;
    OOBE_PreLoginOobeResumed& SetPendingPageId(const std::string& value) &;
    OOBE_PreLoginOobeResumed&& SetExitReason(const std::string& value) &&;
    OOBE_PreLoginOobeResumed& SetExitReason(const std::string& value) &;
    OOBE_PreLoginOobeResumed&& SetIsFlexFlow(const int64_t value) &&;
    OOBE_PreLoginOobeResumed& SetIsFlexFlow(const int64_t value) &;
    OOBE_PreLoginOobeResumed&& SetIsDemoModeFlow(const int64_t value) &&;
    OOBE_PreLoginOobeResumed& SetIsDemoModeFlow(const int64_t value) &;
    OOBE_PreLoginOobeResumed&& SetIsOwnerUser(const int64_t value) &&;
    OOBE_PreLoginOobeResumed& SetIsOwnerUser(const int64_t value) &;
    OOBE_PreLoginOobeResumed&& SetIsEphemeralOrMGS(const int64_t value) &&;
    OOBE_PreLoginOobeResumed& SetIsEphemeralOrMGS(const int64_t value) &;
    OOBE_PreLoginOobeResumed&& SetIsFirstOnboarding(const int64_t value) &&;
    OOBE_PreLoginOobeResumed& SetIsFirstOnboarding(const int64_t value) &;
    OOBE_PreLoginOobeResumed&& SetChromeMilestone(const int64_t value) &&;
    OOBE_PreLoginOobeResumed& SetChromeMilestone(const int64_t value) &;
};

class OOBE_OnboardingResumed final : public ::metrics::structured::Event {
public:
    OOBE_OnboardingResumed();
    ~OOBE_OnboardingResumed() override;

    OOBE_OnboardingResumed&& SetPendingPageId(const std::string& value) &&;
    OOBE_OnboardingResumed& SetPendingPageId(const std::string& value) &;
    OOBE_OnboardingResumed&& SetExitReason(const std::string& value) &&;
    OOBE_OnboardingResumed& SetExitReason(const std::string& value) &;
    OOBE_OnboardingResumed&& SetIsFlexFlow(const int64_t value) &&;
    OOBE_OnboardingResumed& SetIsFlexFlow(const int64_t value) &;
    OOBE_OnboardingResumed&& SetIsDemoModeFlow(const int64_t value) &&;
    OOBE_OnboardingResumed& SetIsDemoModeFlow(const int64_t value) &;
    OOBE_OnboardingResumed&& SetIsOwnerUser(const int64_t value) &&;
    OOBE_OnboardingResumed& SetIsOwnerUser(const int64_t value) &;
    OOBE_OnboardingResumed&& SetIsEphemeralOrMGS(const int64_t value) &&;
    OOBE_OnboardingResumed& SetIsEphemeralOrMGS(const int64_t value) &;
    OOBE_OnboardingResumed&& SetIsFirstOnboarding(const int64_t value) &&;
    OOBE_OnboardingResumed& SetIsFirstOnboarding(const int64_t value) &;
    OOBE_OnboardingResumed&& SetChromeMilestone(const int64_t value) &&;
    OOBE_OnboardingResumed& SetChromeMilestone(const int64_t value) &;
};

class OOBE_ChoobeResumed final : public ::metrics::structured::Event {
public:
    OOBE_ChoobeResumed();
    ~OOBE_ChoobeResumed() override;

    OOBE_ChoobeResumed&& SetExitReason(const std::string& value) &&;
    OOBE_ChoobeResumed& SetExitReason(const std::string& value) &;
    OOBE_ChoobeResumed&& SetIsFlexFlow(const int64_t value) &&;
    OOBE_ChoobeResumed& SetIsFlexFlow(const int64_t value) &;
    OOBE_ChoobeResumed&& SetIsDemoModeFlow(const int64_t value) &&;
    OOBE_ChoobeResumed& SetIsDemoModeFlow(const int64_t value) &;
    OOBE_ChoobeResumed&& SetIsOwnerUser(const int64_t value) &&;
    OOBE_ChoobeResumed& SetIsOwnerUser(const int64_t value) &;
    OOBE_ChoobeResumed&& SetIsEphemeralOrMGS(const int64_t value) &&;
    OOBE_ChoobeResumed& SetIsEphemeralOrMGS(const int64_t value) &;
    OOBE_ChoobeResumed&& SetIsFirstOnboarding(const int64_t value) &&;
    OOBE_ChoobeResumed& SetIsFirstOnboarding(const int64_t value) &;
    OOBE_ChoobeResumed&& SetChromeMilestone(const int64_t value) &&;
    OOBE_ChoobeResumed& SetChromeMilestone(const int64_t value) &;
};

class Picker_StartSession final : public ::metrics::structured::Event {
public:
    Picker_StartSession();
    ~Picker_StartSession() override;

    Picker_StartSession&& SetInputFieldType(const PickerInputFieldType value) &&;
    Picker_StartSession& SetInputFieldType(const PickerInputFieldType value) &;
    Picker_StartSession&& SetSelectionLength(const int64_t value) &&;
    Picker_StartSession& SetSelectionLength(const int64_t value) &;
};

class Picker_FinishSession final : public ::metrics::structured::Event {
public:
    Picker_FinishSession();
    ~Picker_FinishSession() override;

    Picker_FinishSession&& SetOutcome(const PickerSessionOutcome value) &&;
    Picker_FinishSession& SetOutcome(const PickerSessionOutcome value) &;
    Picker_FinishSession&& SetAction(const PickerAction value) &&;
    Picker_FinishSession& SetAction(const PickerAction value) &;
    Picker_FinishSession&& SetResultSource(const PickerResultSource value) &&;
    Picker_FinishSession& SetResultSource(const PickerResultSource value) &;
    Picker_FinishSession&& SetResultType(const PickerResultType value) &&;
    Picker_FinishSession& SetResultType(const PickerResultType value) &;
    Picker_FinishSession&& SetTotalEdits(const int64_t value) &&;
    Picker_FinishSession& SetTotalEdits(const int64_t value) &;
    Picker_FinishSession&& SetFinalQuerySize(const int64_t value) &&;
    Picker_FinishSession& SetFinalQuerySize(const int64_t value) &;
    Picker_FinishSession&& SetResultIndex(const int64_t value) &&;
    Picker_FinishSession& SetResultIndex(const int64_t value) &;
};

class QuickStart_ScreenOpened final : public ::metrics::structured::Event {
public:
    QuickStart_ScreenOpened();
    ~QuickStart_ScreenOpened() override;

    QuickStart_ScreenOpened&& SetScreenName(const QuickStartScreenName value) &&;
    QuickStart_ScreenOpened& SetScreenName(const QuickStartScreenName value) &;
};

class QuickStart_ScreenClosed final : public ::metrics::structured::Event {
public:
    QuickStart_ScreenClosed();
    ~QuickStart_ScreenClosed() override;

    QuickStart_ScreenClosed&& SetScreenName(const QuickStartScreenName value) &&;
    QuickStart_ScreenClosed& SetScreenName(const QuickStartScreenName value) &;
};

class QuickStart_Initiated final : public ::metrics::structured::Event {
public:
    QuickStart_Initiated();
    ~QuickStart_Initiated() override;

    QuickStart_Initiated&& SetEntryPoint(const QuickStartEntryPoint value) &&;
    QuickStart_Initiated& SetEntryPoint(const QuickStartEntryPoint value) &;
};

class QuickStart_FlowAborted final : public ::metrics::structured::Event {
public:
    QuickStart_FlowAborted();
    ~QuickStart_FlowAborted() override;

    QuickStart_FlowAborted&& SetReason(const QuickStartAbortFlowReason value) &&;
    QuickStart_FlowAborted& SetReason(const QuickStartAbortFlowReason value) &;
};

class QuickStart_EstablishConnection final : public ::metrics::structured::Event {
public:
    QuickStart_EstablishConnection();
    ~QuickStart_EstablishConnection() override;

    QuickStart_EstablishConnection&& SetSuccess(const int64_t value) &&;
    QuickStart_EstablishConnection& SetSuccess(const int64_t value) &;
};

class QuickStart_AutomaticResumeAfterUpdate final : public ::metrics::structured::Event {
public:
    QuickStart_AutomaticResumeAfterUpdate();
    ~QuickStart_AutomaticResumeAfterUpdate() override;

    QuickStart_AutomaticResumeAfterUpdate&& SetSuccess(const int64_t value) &&;
    QuickStart_AutomaticResumeAfterUpdate& SetSuccess(const int64_t value) &;
};

class QuickStart_GetWifiCredentials final : public ::metrics::structured::Event {
public:
    QuickStart_GetWifiCredentials();
    ~QuickStart_GetWifiCredentials() override;

    QuickStart_GetWifiCredentials&& SetSuccess(const int64_t value) &&;
    QuickStart_GetWifiCredentials& SetSuccess(const int64_t value) &;
};

class QuickStart_InstallForcedUpdate final : public ::metrics::structured::Event {
public:
    QuickStart_InstallForcedUpdate();
    ~QuickStart_InstallForcedUpdate() override;
};

class QuickStart_InstallConsumerUpdate final : public ::metrics::structured::Event {
public:
    QuickStart_InstallConsumerUpdate();
    ~QuickStart_InstallConsumerUpdate() override;
};

class QuickStart_ConsumerUpdateCancelled final : public ::metrics::structured::Event {
public:
    QuickStart_ConsumerUpdateCancelled();
    ~QuickStart_ConsumerUpdateCancelled() override;
};

class QuickStart_AccountTransferStarted final : public ::metrics::structured::Event {
public:
    QuickStart_AccountTransferStarted();
    ~QuickStart_AccountTransferStarted() override;
};

class QuickStart_AccountTransferComplete final : public ::metrics::structured::Event {
public:
    QuickStart_AccountTransferComplete();
    ~QuickStart_AccountTransferComplete() override;

    QuickStart_AccountTransferComplete&& SetSuccess(const int64_t value) &&;
    QuickStart_AccountTransferComplete& SetSuccess(const int64_t value) &;
};

class RecorderApp_StartSession final : public ::metrics::structured::Event {
public:
    RecorderApp_StartSession();
    ~RecorderApp_StartSession() override;

    RecorderApp_StartSession&& SetSpeakerLabelEnableState(const RecorderAppSpeakerLabelEnableState value) &&;
    RecorderApp_StartSession& SetSpeakerLabelEnableState(const RecorderAppSpeakerLabelEnableState value) &;
    RecorderApp_StartSession&& SetSummaryEnableState(const RecorderAppSummaryEnableState value) &&;
    RecorderApp_StartSession& SetSummaryEnableState(const RecorderAppSummaryEnableState value) &;
    RecorderApp_StartSession&& SetTranscriptionEnableState(const RecorderAppTranscriptionEnableState value) &&;
    RecorderApp_StartSession& SetTranscriptionEnableState(const RecorderAppTranscriptionEnableState value) &;
};

class RecorderApp_Record final : public ::metrics::structured::Event {
public:
    RecorderApp_Record();
    ~RecorderApp_Record() override;

    RecorderApp_Record&& SetMicrophoneType(const RecorderAppMicrophoneType value) &&;
    RecorderApp_Record& SetMicrophoneType(const RecorderAppMicrophoneType value) &;
    RecorderApp_Record&& SetIncludeSystemAudio(const int64_t value) &&;
    RecorderApp_Record& SetIncludeSystemAudio(const int64_t value) &;
    RecorderApp_Record&& SetAudioDuration(const int64_t value) &&;
    RecorderApp_Record& SetAudioDuration(const int64_t value) &;
    RecorderApp_Record&& SetRecordDuration(const int64_t value) &&;
    RecorderApp_Record& SetRecordDuration(const int64_t value) &;
    RecorderApp_Record&& SetEverPaused(const int64_t value) &&;
    RecorderApp_Record& SetEverPaused(const int64_t value) &;
    RecorderApp_Record&& SetEverMuted(const int64_t value) &&;
    RecorderApp_Record& SetEverMuted(const int64_t value) &;
    RecorderApp_Record&& SetTranscriptionLocale(const RecorderAppTranscriptionLocale value) &&;
    RecorderApp_Record& SetTranscriptionLocale(const RecorderAppTranscriptionLocale value) &;
    RecorderApp_Record&& SetTranscriptionLabelEnableState(const RecorderAppTranscriptionEnableState value) &&;
    RecorderApp_Record& SetTranscriptionLabelEnableState(const RecorderAppTranscriptionEnableState value) &;
    RecorderApp_Record&& SetSpeakerLabelEnableState(const RecorderAppSpeakerLabelEnableState value) &&;
    RecorderApp_Record& SetSpeakerLabelEnableState(const RecorderAppSpeakerLabelEnableState value) &;
    RecorderApp_Record&& SetRecordingSaved(const int64_t value) &&;
    RecorderApp_Record& SetRecordingSaved(const int64_t value) &;
    RecorderApp_Record&& SetSpeakerCount(const int64_t value) &&;
    RecorderApp_Record& SetSpeakerCount(const int64_t value) &;
    RecorderApp_Record&& SetWordCount(const int64_t value) &&;
    RecorderApp_Record& SetWordCount(const int64_t value) &;
};

class RecorderApp_SuggestTitle final : public ::metrics::structured::Event {
public:
    RecorderApp_SuggestTitle();
    ~RecorderApp_SuggestTitle() override;

    RecorderApp_SuggestTitle&& SetWordCount(const int64_t value) &&;
    RecorderApp_SuggestTitle& SetWordCount(const int64_t value) &;
    RecorderApp_SuggestTitle&& SetResultStatus(const RecorderAppModelResultStatus value) &&;
    RecorderApp_SuggestTitle& SetResultStatus(const RecorderAppModelResultStatus value) &;
    RecorderApp_SuggestTitle&& SetSuggestionAccepted(const int64_t value) &&;
    RecorderApp_SuggestTitle& SetSuggestionAccepted(const int64_t value) &;
    RecorderApp_SuggestTitle&& SetAcceptedSuggestionIndex(const int64_t value) &&;
    RecorderApp_SuggestTitle& SetAcceptedSuggestionIndex(const int64_t value) &;
};

class RecorderApp_Summarize final : public ::metrics::structured::Event {
public:
    RecorderApp_Summarize();
    ~RecorderApp_Summarize() override;

    RecorderApp_Summarize&& SetWordCount(const int64_t value) &&;
    RecorderApp_Summarize& SetWordCount(const int64_t value) &;
    RecorderApp_Summarize&& SetResultStatus(const RecorderAppModelResultStatus value) &&;
    RecorderApp_Summarize& SetResultStatus(const RecorderAppModelResultStatus value) &;
};

class RecorderApp_FeedbackTitleSuggestion final : public ::metrics::structured::Event {
public:
    RecorderApp_FeedbackTitleSuggestion();
    ~RecorderApp_FeedbackTitleSuggestion() override;

    RecorderApp_FeedbackTitleSuggestion&& SetFeedback(const RecorderAppModelFeedback value) &&;
    RecorderApp_FeedbackTitleSuggestion& SetFeedback(const RecorderAppModelFeedback value) &;
};

class RecorderApp_FeedbackSummary final : public ::metrics::structured::Event {
public:
    RecorderApp_FeedbackSummary();
    ~RecorderApp_FeedbackSummary() override;

    RecorderApp_FeedbackSummary&& SetFeedback(const RecorderAppModelFeedback value) &&;
    RecorderApp_FeedbackSummary& SetFeedback(const RecorderAppModelFeedback value) &;
};

class RecorderApp_Onboard final : public ::metrics::structured::Event {
public:
    RecorderApp_Onboard();
    ~RecorderApp_Onboard() override;

    RecorderApp_Onboard&& SetTranscriptionEnableState(const RecorderAppTranscriptionEnableState value) &&;
    RecorderApp_Onboard& SetTranscriptionEnableState(const RecorderAppTranscriptionEnableState value) &;
    RecorderApp_Onboard&& SetSpeakerLabelEnableState(const RecorderAppSpeakerLabelEnableState value) &&;
    RecorderApp_Onboard& SetSpeakerLabelEnableState(const RecorderAppSpeakerLabelEnableState value) &;
};

class RecorderApp_Export final : public ::metrics::structured::Event {
public:
    RecorderApp_Export();
    ~RecorderApp_Export() override;

    RecorderApp_Export&& SetAudioFormat(const RecorderAppAudioFormat value) &&;
    RecorderApp_Export& SetAudioFormat(const RecorderAppAudioFormat value) &;
    RecorderApp_Export&& SetTranscriptFormat(const RecorderAppTranscriptFormat value) &&;
    RecorderApp_Export& SetTranscriptFormat(const RecorderAppTranscriptFormat value) &;
};

class RecorderApp_ChangePlaybackSpeed final : public ::metrics::structured::Event {
public:
    RecorderApp_ChangePlaybackSpeed();
    ~RecorderApp_ChangePlaybackSpeed() override;

    RecorderApp_ChangePlaybackSpeed&& SetPlaybackSpeed(const double value) &&;
    RecorderApp_ChangePlaybackSpeed& SetPlaybackSpeed(const double value) &;
};

class RecorderApp_ChangePlaybackVolume final : public ::metrics::structured::Event {
public:
    RecorderApp_ChangePlaybackVolume();
    ~RecorderApp_ChangePlaybackVolume() override;

    RecorderApp_ChangePlaybackVolume&& SetVolume(const int64_t value) &&;
    RecorderApp_ChangePlaybackVolume& SetVolume(const int64_t value) &;
    RecorderApp_ChangePlaybackVolume&& SetMuted(const int64_t value) &&;
    RecorderApp_ChangePlaybackVolume& SetMuted(const int64_t value) &;
};

class RecorderApp_AppStartPerf final : public ::metrics::structured::Event {
public:
    RecorderApp_AppStartPerf();
    ~RecorderApp_AppStartPerf() override;

    RecorderApp_AppStartPerf&& SetDuration(const int64_t value) &&;
    RecorderApp_AppStartPerf& SetDuration(const int64_t value) &;
};

class RecorderApp_TranscriptionModelDownloadPerf final : public ::metrics::structured::Event {
public:
    RecorderApp_TranscriptionModelDownloadPerf();
    ~RecorderApp_TranscriptionModelDownloadPerf() override;

    RecorderApp_TranscriptionModelDownloadPerf&& SetDuration(const int64_t value) &&;
    RecorderApp_TranscriptionModelDownloadPerf& SetDuration(const int64_t value) &;
};

class RecorderApp_SummaryModelDownloadPerf final : public ::metrics::structured::Event {
public:
    RecorderApp_SummaryModelDownloadPerf();
    ~RecorderApp_SummaryModelDownloadPerf() override;

    RecorderApp_SummaryModelDownloadPerf&& SetDuration(const int64_t value) &&;
    RecorderApp_SummaryModelDownloadPerf& SetDuration(const int64_t value) &;
};

class RecorderApp_RecordingSavingPerf final : public ::metrics::structured::Event {
public:
    RecorderApp_RecordingSavingPerf();
    ~RecorderApp_RecordingSavingPerf() override;

    RecorderApp_RecordingSavingPerf&& SetDuration(const int64_t value) &&;
    RecorderApp_RecordingSavingPerf& SetDuration(const int64_t value) &;
    RecorderApp_RecordingSavingPerf&& SetAudioDuration(const int64_t value) &&;
    RecorderApp_RecordingSavingPerf& SetAudioDuration(const int64_t value) &;
    RecorderApp_RecordingSavingPerf&& SetWordCount(const int64_t value) &&;
    RecorderApp_RecordingSavingPerf& SetWordCount(const int64_t value) &;
};

class RecorderApp_TitleSuggestionPerf final : public ::metrics::structured::Event {
public:
    RecorderApp_TitleSuggestionPerf();
    ~RecorderApp_TitleSuggestionPerf() override;

    RecorderApp_TitleSuggestionPerf&& SetDuration(const int64_t value) &&;
    RecorderApp_TitleSuggestionPerf& SetDuration(const int64_t value) &;
    RecorderApp_TitleSuggestionPerf&& SetWordCount(const int64_t value) &&;
    RecorderApp_TitleSuggestionPerf& SetWordCount(const int64_t value) &;
};

class RecorderApp_SummaryPerf final : public ::metrics::structured::Event {
public:
    RecorderApp_SummaryPerf();
    ~RecorderApp_SummaryPerf() override;

    RecorderApp_SummaryPerf&& SetDuration(const int64_t value) &&;
    RecorderApp_SummaryPerf& SetDuration(const int64_t value) &;
    RecorderApp_SummaryPerf&& SetWordCount(const int64_t value) &&;
    RecorderApp_SummaryPerf& SetWordCount(const int64_t value) &;
};

class RecorderApp_ExportPerf final : public ::metrics::structured::Event {
public:
    RecorderApp_ExportPerf();
    ~RecorderApp_ExportPerf() override;

    RecorderApp_ExportPerf&& SetDuration(const int64_t value) &&;
    RecorderApp_ExportPerf& SetDuration(const int64_t value) &;
    RecorderApp_ExportPerf&& SetRecordingSize(const int64_t value) &&;
    RecorderApp_ExportPerf& SetRecordingSize(const int64_t value) &;
};

class UserLogin final : public ::metrics::structured::Event {
public:
    UserLogin();
    ~UserLogin() override;
};

class UserLogout final : public ::metrics::structured::Event {
public:
    UserLogout();
    ~UserLogout() override;
};

class SystemSuspended final : public ::metrics::structured::Event {
public:
    SystemSuspended();
    ~SystemSuspended() override;

    SystemSuspended&& SetReason(const int64_t value) &&;
    SystemSuspended& SetReason(const int64_t value) &;
};

class Test1 final : public ::metrics::structured::Event {
public:
    Test1();
    ~Test1() override;

    Test1&& SetMetric1(const double value) &&;
    Test1& SetMetric1(const double value) &;
};

class NoMetricsEvent final : public ::metrics::structured::Event {
public:
    NoMetricsEvent();
    ~NoMetricsEvent() override;
};

} // namespace cr_os_events

namespace dev_tools {

class SessionStart final : public ::metrics::structured::Event {
public:
    SessionStart();
    ~SessionStart() override;

    SessionStart&& SetTrigger(const int64_t value) &&;
    SessionStart& SetTrigger(const int64_t value) &;
    SessionStart&& SetDockSide(const int64_t value) &&;
    SessionStart& SetDockSide(const int64_t value) &;
    SessionStart&& SetSessionId(const int64_t value) &&;
    SessionStart& SetSessionId(const int64_t value) &;
    SessionStart&& SetIsSignedIn(const int64_t value) &&;
    SessionStart& SetIsSignedIn(const int64_t value) &;
};

class SessionEnd final : public ::metrics::structured::Event {
public:
    SessionEnd();
    ~SessionEnd() override;

    SessionEnd&& SetTrigger(const int64_t value) &&;
    SessionEnd& SetTrigger(const int64_t value) &;
    SessionEnd&& SetTimeSinceSessionStart(const int64_t value) &&;
    SessionEnd& SetTimeSinceSessionStart(const int64_t value) &;
    SessionEnd&& SetSessionId(const int64_t value) &&;
    SessionEnd& SetSessionId(const int64_t value) &;
};

class Impression final : public ::metrics::structured::Event {
public:
    Impression();
    ~Impression() override;

    Impression&& SetVeId(const int64_t value) &&;
    Impression& SetVeId(const int64_t value) &;
    Impression&& SetVeType(const int64_t value) &&;
    Impression& SetVeType(const int64_t value) &;
    Impression&& SetVeParent(const int64_t value) &&;
    Impression& SetVeParent(const int64_t value) &;
    Impression&& SetVeContext(const int64_t value) &&;
    Impression& SetVeContext(const int64_t value) &;
    Impression&& SetTimeSinceSessionStart(const int64_t value) &&;
    Impression& SetTimeSinceSessionStart(const int64_t value) &;
    Impression&& SetSessionId(const int64_t value) &&;
    Impression& SetSessionId(const int64_t value) &;
    Impression&& SetWidth(const int64_t value) &&;
    Impression& SetWidth(const int64_t value) &;
    Impression&& SetHeight(const int64_t value) &&;
    Impression& SetHeight(const int64_t value) &;
};

class Resize final : public ::metrics::structured::Event {
public:
    Resize();
    ~Resize() override;

    Resize&& SetVeId(const int64_t value) &&;
    Resize& SetVeId(const int64_t value) &;
    Resize&& SetTimeSinceSessionStart(const int64_t value) &&;
    Resize& SetTimeSinceSessionStart(const int64_t value) &;
    Resize&& SetSessionId(const int64_t value) &&;
    Resize& SetSessionId(const int64_t value) &;
    Resize&& SetWidth(const int64_t value) &&;
    Resize& SetWidth(const int64_t value) &;
    Resize&& SetHeight(const int64_t value) &&;
    Resize& SetHeight(const int64_t value) &;
};

class Click final : public ::metrics::structured::Event {
public:
    Click();
    ~Click() override;

    Click&& SetVeId(const int64_t value) &&;
    Click& SetVeId(const int64_t value) &;
    Click&& SetMouseButton(const int64_t value) &&;
    Click& SetMouseButton(const int64_t value) &;
    Click&& SetDoubleClick(const int64_t value) &&;
    Click& SetDoubleClick(const int64_t value) &;
    Click&& SetContext(const int64_t value) &&;
    Click& SetContext(const int64_t value) &;
    Click&& SetTimeSinceSessionStart(const int64_t value) &&;
    Click& SetTimeSinceSessionStart(const int64_t value) &;
    Click&& SetSessionId(const int64_t value) &&;
    Click& SetSessionId(const int64_t value) &;
};

class Hover final : public ::metrics::structured::Event {
public:
    Hover();
    ~Hover() override;

    Hover&& SetVeId(const int64_t value) &&;
    Hover& SetVeId(const int64_t value) &;
    Hover&& SetTime(const int64_t value) &&;
    Hover& SetTime(const int64_t value) &;
    Hover&& SetContext(const int64_t value) &&;
    Hover& SetContext(const int64_t value) &;
    Hover&& SetTimeSinceSessionStart(const int64_t value) &&;
    Hover& SetTimeSinceSessionStart(const int64_t value) &;
    Hover&& SetSessionId(const int64_t value) &&;
    Hover& SetSessionId(const int64_t value) &;
};

class Drag final : public ::metrics::structured::Event {
public:
    Drag();
    ~Drag() override;

    Drag&& SetVeId(const int64_t value) &&;
    Drag& SetVeId(const int64_t value) &;
    Drag&& SetDistance(const int64_t value) &&;
    Drag& SetDistance(const int64_t value) &;
    Drag&& SetContext(const int64_t value) &&;
    Drag& SetContext(const int64_t value) &;
    Drag&& SetTimeSinceSessionStart(const int64_t value) &&;
    Drag& SetTimeSinceSessionStart(const int64_t value) &;
    Drag&& SetSessionId(const int64_t value) &&;
    Drag& SetSessionId(const int64_t value) &;
};

class Change final : public ::metrics::structured::Event {
public:
    Change();
    ~Change() override;

    Change&& SetVeId(const int64_t value) &&;
    Change& SetVeId(const int64_t value) &;
    Change&& SetContext(const int64_t value) &&;
    Change& SetContext(const int64_t value) &;
    Change&& SetTimeSinceSessionStart(const int64_t value) &&;
    Change& SetTimeSinceSessionStart(const int64_t value) &;
    Change&& SetSessionId(const int64_t value) &&;
    Change& SetSessionId(const int64_t value) &;
};

class KeyDown final : public ::metrics::structured::Event {
public:
    KeyDown();
    ~KeyDown() override;

    KeyDown&& SetVeId(const int64_t value) &&;
    KeyDown& SetVeId(const int64_t value) &;
    KeyDown&& SetContext(const int64_t value) &&;
    KeyDown& SetContext(const int64_t value) &;
    KeyDown&& SetTimeSinceSessionStart(const int64_t value) &&;
    KeyDown& SetTimeSinceSessionStart(const int64_t value) &;
    KeyDown&& SetSessionId(const int64_t value) &&;
    KeyDown& SetSessionId(const int64_t value) &;
};

} // namespace dev_tools

namespace test_project_one {

class TestEventOne final : public ::metrics::structured::Event {
public:
    TestEventOne();
    ~TestEventOne() override;

    TestEventOne&& SetTestMetricOne(const std::string& value) &&;
    TestEventOne& SetTestMetricOne(const std::string& value) &;
    TestEventOne&& SetTestMetricTwo(const int64_t value) &&;
    TestEventOne& SetTestMetricTwo(const int64_t value) &;
};

} // namespace test_project_one

namespace test_project_two {

class TestEventThree final : public ::metrics::structured::Event {
public:
    TestEventThree();
    ~TestEventThree() override;

    TestEventThree&& SetTestMetricFour(const std::string& value) &&;
    TestEventThree& SetTestMetricFour(const std::string& value) &;
};

class TestEventTwo final : public ::metrics::structured::Event {
public:
    TestEventTwo();
    ~TestEventTwo() override;

    TestEventTwo&& SetTestMetricThree(const std::string& value) &&;
    TestEventTwo& SetTestMetricThree(const std::string& value) &;
};

} // namespace test_project_two

namespace test_project_three {

class TestEventFour final : public ::metrics::structured::Event {
public:
    TestEventFour();
    ~TestEventFour() override;

    TestEventFour&& SetTestMetricFour(const int64_t value) &&;
    TestEventFour& SetTestMetricFour(const int64_t value) &;
};

} // namespace test_project_three

namespace test_project_four {

class TestEventFive final : public ::metrics::structured::Event {
public:
    TestEventFive();
    ~TestEventFive() override;

    TestEventFive&& SetTestMetricFive(const std::string& value) &&;
    TestEventFive& SetTestMetricFive(const std::string& value) &;
};

} // namespace test_project_four

namespace test_project_five {

class TestEventSix final : public ::metrics::structured::Event {
public:
    TestEventSix();
    ~TestEventSix() override;

    TestEventSix&& SetTestMetricSix(const std::string& value) &&;
    TestEventSix& SetTestMetricSix(const std::string& value) &;
};

} // namespace test_project_five

namespace test_project_six {

enum class Enum1 { VARIANT1 = 1, VARIANT2 = 2, VARIANT3 = 5 };

class TestEventSeven final : public ::metrics::structured::Event {
public:
    TestEventSeven();
    ~TestEventSeven() override;

    TestEventSeven&& SetTestMetricSeven(const double value) &&;
    TestEventSeven& SetTestMetricSeven(const double value) &;
};

class TestEnum final : public ::metrics::structured::Event {
public:
    TestEnum();
    ~TestEnum() override;

    TestEnum&& SetTestEnumMetric(const Enum1 value) &&;
    TestEnum& SetTestEnumMetric(const Enum1 value) &;
};

} // namespace test_project_six

namespace test_project_seven {

class TestEventEight final : public ::metrics::structured::Event {
public:
    TestEventEight();
    ~TestEventEight() override;

    TestEventEight&& SetTestMetricEight(const double value) &&;
    TestEventEight& SetTestMetricEight(const double value) &;
};

} // namespace test_project_seven

namespace sequenced_test_project {

class Test1 final : public ::metrics::structured::Event {
public:
    Test1();
    ~Test1() override;

    Test1&& SetMetric1(const double value) &&;
    Test1& SetMetric1(const double value) &;
};

} // namespace sequenced_test_project

} // namespace v2
} // namespace events
} // namespace structured
} // namespace metrics

#endif // GEN_COMPONENTS_METRICS_STRUCTURED_STRUCTURED_EVENTS_H
