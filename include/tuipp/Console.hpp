/**
 * @file Console.hpp
 *
 * @brief A class that represent a console with some useful utilities
 *
 * @author Giuliano De Amicis
 */

#pragma once

#include <iostream>
#include <ostream>
#include <print>
#include <string>

#include "../../src/tuipp/string_parser/parse_string.hpp"
#include "private/macros.hpp"
#include "tuipp/console_info.hpp"

namespace tuipp {

/**
 * @brief This is the class that represent a console.
 *
 * Most of its methods and properties are static, so you can use them without creating it.
 *
 * ## Examples
 *
 * @code{.cpp}
 * tuipp::Console console{}; // creates the console
 *
 * console << "[green]Print to the screen using[/] << [green]operator overload![/]" << std::endl;
 * console << "you can" << " " << "chain them!" << std::endl;
 *
 * tuipp::Console::print("[green]This is a static member![/]");
 * tuipp::Console::println("[green]Also this![/]");
 *
 * tuipp::Console::print_info(true);
 * @endcode
 */
class Console
{
  public:
    inline static console_info::TerminalSize terminal_size{
        tuipp::console_info::get_terminal_size()
    };
    inline static console_info::ColorSystem color_support{
        tuipp::console_info::get_color_support()
    };

    inline static bool support_ansi{ tuipp::console_info::get_support_ansi() };

    /**
     * @brief Print an output to the screen with a new line at the end (supports markup).
     *
     * ## Examples:
     *
     * @code{.cpp}
     * tuipp::Console::println("[bold green]Hello, World![/]");
     * tuipp::Console::println(
     * "[green]This is green [bold]this is bold and green[/] this is still green[/]"
     * );
     * tuipp::Console::println("[blue]Number of files: [/]", 10, ".");
     * tuipp::Console::println("[green]This is green [bold]this is bold and green[reset] this is
     * normal");
     * @endcode
     *
     * ## Styles:
     *
     * - Foreground colors: `red`, `green`, `grey`, `blue`, `magenta`, `yellow`, `white`, `bright
     * red`, `bright green`, `bright grey`, `bright blue`, `bright magenta`, `bright yellow`,
     * `bright cyan`, `bright white`
     *
     * - Effects: `bold`, `underline`, `blink`, `italic`, `dim`, `strikethrough`, `conceal`,
     * `reverse`
     *
     * - Reset: `/` (for one style), `reset` (for all styles)
     *
     * - For the background colors just type: `on <color>`
     *
     * ---
     *
     * You can also escape markup brackets using a backslash:
     *
     * @code{.cpp}
     * tuipp::Console::println("\[bold red]Hello, World!\[/]");
     * @endcode
     *
     * ---
     *
     * It can also print iterables:
     *
     * @code{.cpp}
     * std::vector<int> vector{ { 1, 2, 3, 4, 5, 6 } };
     *
     * tuipp::Console::println(vector);
     * @endcode
     *
     * @param content The items you want to print, they can be of any type and you can pass as many
     * as you want.
     */
    template<typename... Args>
    static void println(const Args&... content)
    {
        std::ostream& output = std::cout;

        (
          [&]() {
              if constexpr (std::is_convertible_v<decltype(content), std::string>) {
                  parse_string(output, content);
              } else {
                  std::print("{}", content);
              }
          }(),
          ...);

        output << std::endl;
    }

    /**
     * @brief Print an output to the screen without a new line at the end (supports markup).
     *
     * ## Examples:
     *
     * @code{.cpp}
     * tuipp::Console::print("[bold green]Hello, World![/]");
     * tuipp::Console::print(
     * "[green]This is green [bold]this is bold and green[/] this is still green[/]"
     * );
     * tuipp::Console::print("[blue]Number of files: [/]", 10, ".");
     * tuipp::Console::print("[green]This is green [bold]this is bold and green[reset] this is
     * normal");
     * @endcode
     *
     * ## Styles:
     *
     * - Foreground colors: `red`, `green`, `grey`, `blue`, `magenta`, `yellow`, `white`, `bright
     * red`, `bright green`, `bright grey`, `bright blue`, `bright magenta`, `bright yellow`,
     * `bright cyan`, `bright white`
     *
     * - Effects: `bold`, `underline`, `blink`, `italic`, `dim`, `strikethrough`, `conceal`,
     * `reverse`
     *
     * - Reset: `/` (for one style), `reset` (for all styles)
     *
     * - For the background colors just type: `on <color>`
     *
     * ---
     *
     * You can also escape markup brackets using a backslash:
     *
     * @code{.cpp}
     * tuipp::Console::print("\[bold red]Hello, World!\[/]");
     * @endcode
     *
     * ---
     *
     * It can also print iterables:
     *
     * @code{.cpp}
     * std::vector<int> vector{ { 1, 2, 3, 4, 5, 6 } };
     *
     * tuipp::Console::print(vector);
     * @endcode
     *
     * @param content The items you want to print, they can be of any type and you can pass as many
     * as you want.
     */
    template<typename... Args>
    static void print(const Args&... content)
    {
        (
          [&]() {
              if constexpr (std::is_convertible_v<decltype(content), std::string>) {
                  parse_string(std::cout, content);
              } else {
                  std::print("{}", content);
              }
          }(),
          ...);
    }

    /// @return the color support as a string
    TUIPP_NODISCARD static std::string get_color_support_string()
    {
        switch (color_support) {
            case tuipp::console_info::NO_COLORS:
                return "no colors";
            case tuipp::console_info::EIGHT_BIT:
                return "8 bit";
            case tuipp::console_info::TRUE_COLOR:
                return "true color";
        }

        // just to disable some compiler warnings
        return "";
    }

    /// A utility to print the console info in a nice format
    static void print_info(const bool& color)
    {
        if (color) {
            println("[green]Console properties:[/]");
            println("  [green]Size: [/]", terminal_size.width, "x", terminal_size.height);
            println("  [green]Color support: [/]", get_color_support_string());
            println("  [green]ANSI support: [/]", support_ansi);
        } else {
            std::cout << "Console properties:" << std::endl;
            std::cout << "  Size: " << terminal_size.width << "x" << terminal_size.height
                      << std::endl;
            std::cout << "  Color support: " << get_color_support_string() << std::endl;
            std::cout << "  ANSI support: " << (support_ansi ? "true" : "false") << std::endl;
        }
    }

    /// A << operator overload made for printing things in the `std::cout` style
    template<typename T>
    Console& operator<<(const T& value)
    {
        print(value);

        return *this;
    }

    // wth is this
    /// A << operator overload made for printing stream manipulators like `std::endl`
    Console& operator<<(
      std::ostream& (*f)(std::ostream&) // some C shenanigans for accepting stream manipulators
    )
    {
        std::cout << f;

        return *this;
    }
};

} // namespace tuipp
