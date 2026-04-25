#include "tuipp/Console.hpp"

#include <cstdlib>
#include <string_view>

#include "tuipp/print.hpp"
#include "tuipp/private/macros.hpp"

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

TUIPP_NODISCARD Console::TerminalSize
Console::set_terminal_size()
{
    Console::TerminalSize size{};

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
TUIPP_NODISCARD bool
Console::set_support_ansi()
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
TUIPP_NODISCARD Console::ColorSystem
Console::set_color_support()
{
    // adapted from:
    // https://github.com/spectreconsole/spectre.console/blob/main/src/Spectre.Console.Ansi/ColorSystemDetector.cs
    // thanks guys ❤  love you all

    if (std::getenv("NO_COLOR")) {
        return Console::ColorSystem::NO_COLORS;
    }

#ifdef ON_WINDOWS
    if (IsWindowsVersionOrGreater(10, 0, 15063)) {
        return Console::ColorSupport::TRUE_COLOR;
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

    return Console::ColorSystem::EIGHT_BIT;
}

TUIPP_NODISCARD Console::TerminalSize
Console::get_terminal_size() const
{
    return this->terminal_size;
}
TUIPP_NODISCARD Console::ColorSystem
Console::get_color_support() const
{
    return this->color_support;
}
TUIPP_NODISCARD std::string
Console::get_color_support_string() const
{
    switch (this->color_support) {
        case NO_COLORS:
            return "no colors";
        case EIGHT_BIT:
            return "8 bit";
        case TRUE_COLOR:
            return "true color";
    }

    // just to disable a stupid compiler warning
    return "";
}
TUIPP_NODISCARD bool
Console::get_support_ansi() const
{
    return this->support_ansi;
}

void
Console::print_info(const bool& color) const
{
    tuipp::Console::TerminalSize console_size = this->get_terminal_size();

    if (color) {
        tuipp::println("[green]Console properties:[/]");
        tuipp::println("  [green]Size: [/]", console_size.width, "x", console_size.height);
        tuipp::println("  [green]Color support: [/]", this->get_color_support_string());
        tuipp::println("  [green]ANSI support: [/]", this->get_support_ansi());
    } else {
        std::cout << "Console properties:" << std::endl;
        std::cout << "  Size: " << console_size.width << "x" << console_size.height << std::endl;
        std::cout << "  Color support: " << this->get_color_support_string() << std::endl;
        std::cout << "  ANSI support: " << (this->get_support_ansi() ? "true" : "false")
                  << std::endl;
    }
}

} // namespace tuipp
