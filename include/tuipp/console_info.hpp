/**
 * @file console_info.hpp
 *
 * @brief A header that contains useful methods and types for getting the console informations
 *
 * @author Giuliano De Amicis
 */

#pragma once

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <string>
#include <string_view>

#include "private/macros.hpp"

#if defined(ON_WINDOWS)
#  define WIN32_LEAN_AND_MEAN
#  define VC_EXTRALEAN
#  include <Windows.h>
// VersionHelpers.h must be included after Windows.h
#  include <VersionHelpers.h>
#elif defined(ON_UNIX_LIKE)
#  include <sys/ioctl.h>
#endif

namespace tuipp {

namespace console_info {

struct TerminalSize
{
    std::size_t width{};
    std::size_t height{};
};

enum ColorSystem
{
    /// no color support, it disables every color
    NO_COLORS,

    /// 16 colors palette
    EIGHT_BIT,

    /// full 16 million color support
    TRUE_COLOR
};

TUIPP_NODISCARD inline TerminalSize
get_terminal_size()
{
    TerminalSize size{};

#ifdef ON_WINDOWS
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    size.width  = static_cast<int>(csbi.srWindow.Right - csbi.srWindow.Left + 1);
    size.height = static_cast<int>(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
#elifdef ON_UNIX_LIKE
    struct winsize w;
    ioctl(fileno(stdout), TIOCGWINSZ, &w);
    size.width  = static_cast<int>(w.ws_col);
    size.height = static_cast<int>(w.ws_row);
#endif

    return size;
}
TUIPP_NODISCARD inline bool
get_support_ansi()
{
    char* term      = std::getenv("TERM");
    char* colorterm = std::getenv("COLORTERM");

    if (colorterm) {
        std::string_view ct(colorterm);

        if (ct == "truecolor" || ct == "24bit") {
            return true;
        }
    }

    if (term) {
        std::string_view t(term);
        if (t.find("256color") != std::string_view::npos) {
            return true;
        }
        if (t.find("xterm") != std::string_view::npos) {
            return true;
        }
        if (t.find("screen") != std::string_view::npos) {
            return true;
        }
        if (t == "linux") {
            return true;
        }
    }

    return false;
}
/// adapted from:
/// https://github.com/spectreconsole/spectre.console/blob/main/src/Spectre.Console.Ansi/ColorSystemDetector.cs
/// thanks guys ❤  love you all
TUIPP_NODISCARD inline ColorSystem
get_color_support()
{
    if (std::getenv("NO_COLOR")) {
        return ColorSystem::NO_COLORS;
    }

#ifdef ON_WINDOWS
    if (IsWindowsVersionOrGreater(10, 0, 15063)) {
        return ColorSupport::TRUE_COLOR;
    }
#else
    std::string color_term_env_var = std::getenv("COLORTERM");

    std::transform(
      color_term_env_var.begin(), color_term_env_var.end(), color_term_env_var.begin(), ::tolower);

    if (!color_term_env_var.empty()) {
        if (color_term_env_var == "truecolor" || color_term_env_var == "24bit") {
            return ColorSystem::TRUE_COLOR;
        }
    }
#endif

    return ColorSystem::EIGHT_BIT;
}

} // namespace console_info

} // namespace tuipp
