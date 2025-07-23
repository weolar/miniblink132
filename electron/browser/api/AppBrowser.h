
#ifndef electron_browser_api_AppBrowser_h
#define electron_browser_api_AppBrowser_h

#if defined(_WIN32)
#include <xstring>
#endif
#include <vector>

namespace atom {

#if defined(_WIN32)
struct LaunchItem {
    std::u16string name;
    std::u16string path;
    std::u16string scope;
    std::vector<std::u16string> args;
    bool enabled = true;

    LaunchItem();
    ~LaunchItem();
    LaunchItem(const LaunchItem&);
};
#endif

// Set/Get the login item settings of the app
struct LoginItemSettings {
    bool open_at_login = false;
    bool open_as_hidden = false;
    bool restore_state = false;
    bool opened_at_login = false;
    bool opened_as_hidden = false;
    std::u16string path;
    std::vector<std::u16string> args;

#if defined(_WIN32)
    // used in browser::setLoginItemSettings
    bool enabled = true;
    std::u16string name;

    // used in browser::getLoginItemSettings
    bool executable_will_launch_at_login = false;
    std::vector<LaunchItem> launch_items;
#endif

    LoginItemSettings();
    ~LoginItemSettings();
    LoginItemSettings(const LoginItemSettings&);
};

LoginItemSettings getLoginItemSettings(const LoginItemSettings& options);
void setLoginItemSettings(LoginItemSettings settings);

}

#endif // electron_browser_api_AppBrowser_h
