#include "tuipp/Console.hpp"

#include "tuipp/private/macros.hpp"

#if defined(ON_WINDOWS)
#  define WIN32_LEAN_AND_MEAN
#  define VC_EXTRALEAN
#  include <Windows.h>
#elif defined(ON_UNIX_LIKE)
#  include <sys/ioctl.h>
#endif

namespace tuipp {

TUIPP_NODISCARD Console::TerminalSize
Console::get_terminal_size()
{
    Console::TerminalSize size{};

#if defined(ON_WINDOWS)
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    size.width  = static_cast<int>(csbi.srWindow.Right - csbi.srWindow.Left + 1);
    size.height = static_cast<int>(csbi.srWindow.Bottom - csbi.srWindow.Top + 1);
#elif defined(ON_UNIX_LIKE)
    struct winsize w;
    ioctl(fileno(stdout), TIOCGWINSZ, &w);
    size.width  = static_cast<int>(w.ws_col);
    size.height = static_cast<int>(w.ws_row);
#endif

    return size;
}

} // namespace tuipp
