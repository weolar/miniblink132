// Generated from generate_allowlist_from_histograms_file.py. Do not edit!

#ifndef UI_VIEWS_BUBBLE_HISTOGRAMS_VARIANT_H_
#define UI_VIEWS_BUBBLE_HISTOGRAMS_VARIANT_H_

#include <algorithm>
#include <string_view>

namespace views_metrics {

inline constexpr std::string_view kBubbleNameAllowList[] = {
    "All",
    "DownloadBubbleContentsView",
    "ExtensionsMenuView",
    "PageInfoBubbleViewBase",
    "PermissionPromptBaseView",
    "ProfileMenuViewBase",
};

constexpr bool IsValidBubbleName(std::string_view s)
{
    return std::binary_search(std::cbegin(kBubbleNameAllowList), std::cend(kBubbleNameAllowList), s);
}

} // namespace views_metrics

#endif // UI_VIEWS_BUBBLE_HISTOGRAMS_VARIANT_H_
