/**
 * @file Console.hpp
 *
 * @brief A class that represent a console and some other console utility
 *
 * @author Giuliano De Amicis
 */

#pragma once

#include <cstddef>

#include "private/macros.hpp"
#include "tuipp/print.hpp"

namespace tuipp {

class Console
{
  public:
    struct TerminalSize
    {
        std::size_t width{};
        std::size_t height{};
    };

    enum ColorSystem
    {
        NO_COLORS,
        EIGHT_BIT,
        TRUE_COLOR
    };

    TUIPP_NODISCARD TerminalSize get_terminal_size() const;
    TUIPP_NODISCARD ColorSystem get_color_support() const;

    TUIPP_NODISCARD std::string get_color_support_string() const;
    TUIPP_NODISCARD bool get_support_ansi() const;

    void print_info(const bool& color) const;

    Console()
      : terminal_size(set_terminal_size())
      , color_support(set_color_support())
      , support_ansi(set_color_support()) {};

    template<typename T>
    Console& operator<<(const T& value)
    {
        print(value);

        return *this;
    }

    // wth is this
    Console& operator<<(
      std::ostream& (*f)(std::ostream&) // some C shenanigans for accepting stream manipulators
    )
    {
        std::cout << f;

        return *this;
    }

  private:
    TerminalSize terminal_size{};
    ColorSystem color_support{};

    bool support_ansi{};

    TUIPP_NODISCARD TerminalSize set_terminal_size();
    TUIPP_NODISCARD ColorSystem set_color_support();
    TUIPP_NODISCARD bool set_support_ansi();
};

} // namespace tuipp
