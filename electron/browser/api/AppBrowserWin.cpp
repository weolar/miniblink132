
#include "electron/browser/api/AppBrowser.h"

#include "base/command_line.h"
#include "base/path_service.h"
#include "base/win/registry.h"
#include "base/file_version_info.h"
#include "base/files/file_path.h"
#include "base/strings/utf_string_conversions.h"
#include "base/strings/stringprintf.h"
#include "base/strings/string_util.h"
#include <shobjidl.h>
#include <windows.h>
#include <xstring>

// look O:\chromium\ele22fp\electron\shell\browser\browser_win.cc
namespace atom {

static std::wstring g_app_user_model_id;

LaunchItem::LaunchItem() = default;
LaunchItem::~LaunchItem() = default;
LaunchItem::LaunchItem(const LaunchItem& other) = default;

LoginItemSettings::LoginItemSettings() = default;
LoginItemSettings::~LoginItemSettings() = default;
LoginItemSettings::LoginItemSettings(const LoginItemSettings& other) = default;

void SetAppUserModelID(const std::wstring& name)
{
    g_app_user_model_id = name;
    SetCurrentProcessExplicitAppUserModelID(g_app_user_model_id.c_str());
}

std::string GetApplicationName()
{
    HMODULE mod = GetModuleHandle(nullptr);
    std::unique_ptr<FileVersionInfo> info(FileVersionInfo::CreateFileVersionInfoForModule(mod));
    return base::UTF16ToUTF8(info->product_name());
}

const WCHAR kAppUserModelIDFormat[] = L"electron.app.$1";

PCWSTR GetRawAppUserModelID()
{
    if (g_app_user_model_id.empty()) {
        PWSTR current_app_id;
        if (SUCCEEDED(GetCurrentProcessExplicitAppUserModelID(&current_app_id))) {
            g_app_user_model_id = current_app_id;
        } else {
            std::string name = GetApplicationName();
            std::wstring generated_app_id = base::ReplaceStringPlaceholders(kAppUserModelIDFormat, { base::UTF8ToWide(name) }, nullptr);
            SetAppUserModelID(generated_app_id);
        }
        CoTaskMemFree(current_app_id);
    }

    return g_app_user_model_id.c_str();
}

PCWSTR GetAppUserModelID()
{
    return GetRawAppUserModelID();
}

static bool GetProcessExecPath(std::wstring* exe)
{
    base::FilePath path;
    if (!base::PathService::Get(base::FILE_EXE, &path)) {
        return false;
    }
    *exe = path.value();
    return true;
}

bool FormatCommandLineString(std::wstring* exe, const std::vector<std::u16string>& launch_args)
{
    if (exe->empty() && !GetProcessExecPath(exe)) {
        return false;
    }

    if (!launch_args.empty()) {
        std::u16string joined_launch_args = base::JoinString(
            base::span<const std::u16string>(launch_args.data(), launch_args.size()), std::u16string_view(u" "));
        *exe = base::StringPrintf(L"%ls %ls", exe->c_str(), base::as_wcstr(joined_launch_args));
    }

    return true;
}

void asChar16Vector(const std::vector<std::wstring>& val, std::vector<std::u16string>* out)
{
    for (size_t i = 0; i < val.size(); ++i) {
        out->push_back(base::AsString16(val[i]));
    }
}

// Helper for GetLoginItemSettings().
// iterates over all the entries in a windows registry path and returns
// a list of launchItem with matching paths to our application.
// if a launchItem with a matching path also has a matching entry within the
// startup_approved_key_path, set executable_will_launch_at_login to be `true`
std::vector<LaunchItem> getLoginItemSettingsHelper(
    base::win::RegistryValueIterator* it, boolean* executable_will_launch_at_login, const std::u16string& scope, const LoginItemSettings& options)
{
    std::vector<LaunchItem> launch_items;

    base::FilePath lookup_exe_path;
    if (options.path.empty()) {
        std::wstring process_exe_path;
        GetProcessExecPath(&process_exe_path);
        lookup_exe_path = base::CommandLine::FromString(process_exe_path).GetProgram();
    } else {
        lookup_exe_path = base::CommandLine::FromString(base::as_wcstr(options.path)).GetProgram();
    }

    if (lookup_exe_path.empty())
        return launch_items;

    while (it->Valid()) {
        base::CommandLine registry_launch_cmd = base::CommandLine::FromString(it->Value());
        base::FilePath registry_launch_path = registry_launch_cmd.GetProgram();
        bool exe_match = base::FilePath::CompareEqualIgnoreCase(lookup_exe_path.value(), registry_launch_path.value());

        // add launch item to vector if it has a matching path (case-insensitive)
        if (exe_match) {
            LaunchItem launch_item;
            launch_item.name = base::AsString16(it->Name());
            launch_item.path = base::AsString16(registry_launch_path.value());
            asChar16Vector(registry_launch_cmd.GetArgs(), &(launch_item.args));
            launch_item.scope = scope;
            launch_item.enabled = true;

            // attempt to update launch_item.enabled if there is a matching key
            // value entry in the StartupApproved registry
            HKEY hkey;
            // StartupApproved registry path
            LPCWSTR path = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\StartupApproved\\Run";
            LONG res;
            if (scope == u"user") {
                res = RegOpenKeyEx(HKEY_CURRENT_USER, path, 0, KEY_QUERY_VALUE, &hkey);
            } else {
                res = RegOpenKeyEx(HKEY_LOCAL_MACHINE, path, 0, KEY_QUERY_VALUE, &hkey);
            }
            if (res == ERROR_SUCCESS) {
                DWORD type, size;
                WCHAR startup_binary[12];
                LONG result = RegQueryValueEx(hkey, it->Name(), nullptr, &type, reinterpret_cast<BYTE*>(&startup_binary), &(size = sizeof(startup_binary)));
                if (result == ERROR_SUCCESS) {
                    if (type == REG_BINARY) {
                        // any other binary other than this indicates that the program is
                        // not set to launch at login
                        WCHAR binary_accepted[12] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
                        WCHAR binary_accepted_alt[12] = { 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
                        std::string reg_binary(reinterpret_cast<char*>(binary_accepted));
                        std::string reg_binary_alt(reinterpret_cast<char*>(binary_accepted_alt));
                        std::string reg_startup_binary(reinterpret_cast<char*>(startup_binary));
                        launch_item.enabled = (reg_startup_binary == reg_binary) || (reg_startup_binary == reg_binary_alt);
                    }
                }
            }

            *executable_will_launch_at_login = *executable_will_launch_at_login || launch_item.enabled;
            launch_items.push_back(launch_item);
        }
        it->operator++();
    }
    return launch_items;
}

LoginItemSettings getLoginItemSettings(const LoginItemSettings& options)
{
    LoginItemSettings settings;
    std::wstring keyPath = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    base::win::RegKey key(HKEY_CURRENT_USER, keyPath.c_str(), KEY_ALL_ACCESS);
    std::wstring keyVal;

    // keep old openAtLogin behaviour
    if (!FAILED(key.ReadValue(GetAppUserModelID(), &keyVal))) {
        std::wstring exe = base::UTF16ToWide(options.path);
        if (FormatCommandLineString(&exe, options.args)) {
            settings.open_at_login = keyVal == exe;
        }
    }

    // iterate over current user and machine registries and populate launch items
    // if there exists a launch entry with property enabled=='true',
    // set executable_will_launch_at_login to 'true'.
    boolean executable_will_launch_at_login = false;
    std::vector<LaunchItem> launch_items;
    base::win::RegistryValueIterator hkcu_iterator(HKEY_CURRENT_USER, keyPath.c_str());
    base::win::RegistryValueIterator hklm_iterator(HKEY_LOCAL_MACHINE, keyPath.c_str());

    launch_items = getLoginItemSettingsHelper(&hkcu_iterator, &executable_will_launch_at_login, u"user", options);
    std::vector<LaunchItem> launch_items_hklm = getLoginItemSettingsHelper(&hklm_iterator, &executable_will_launch_at_login, u"machine", options);
    launch_items.insert(launch_items.end(), launch_items_hklm.begin(), launch_items_hklm.end());

    settings.executable_will_launch_at_login = executable_will_launch_at_login;
    settings.launch_items = launch_items;
    return settings;
}

void setLoginItemSettings(LoginItemSettings settings)
{
    std::wstring key_path = L"Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    base::win::RegKey key(HKEY_CURRENT_USER, key_path.c_str(), KEY_ALL_ACCESS);

    std::wstring startup_approved_key_path = L"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\StartupApproved\\Run";
    base::win::RegKey startup_approved_key(HKEY_CURRENT_USER, startup_approved_key_path.c_str(), KEY_ALL_ACCESS);
    PCWSTR key_name = (!settings.name.empty() ? (const WCHAR*)(settings.name.c_str()) : GetAppUserModelID());

    if (settings.open_at_login) {
        std::wstring exe = base::UTF16ToWide(settings.path);
        if (FormatCommandLineString(&exe, settings.args)) {
            key.WriteValue(key_name, exe.c_str());

            if (settings.enabled) {
                startup_approved_key.DeleteValue(key_name);
            } else {
                HKEY hard_key;
                LPCTSTR path = TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\StartupApproved\\Run");
                LONG res = RegOpenKeyEx(HKEY_CURRENT_USER, path, 0, KEY_ALL_ACCESS, &hard_key);

                if (res == ERROR_SUCCESS) {
                    UCHAR disable_startup_binary[] = { 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
                    RegSetValueEx(hard_key, key_name, 0, REG_BINARY, reinterpret_cast<const BYTE*>(disable_startup_binary), sizeof(disable_startup_binary));
                }
            }
        }
    } else {
        // if open at login is false, delete both values
        startup_approved_key.DeleteValue(key_name);
        key.DeleteValue(key_name);
    }
}

} // atom