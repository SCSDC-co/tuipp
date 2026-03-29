/**
 * @file print.hpp
 *
 * @brief A utility to print text with markup support.
 *
 * @details Example:
 *
 * @code{.cpp}
 * tuipp::println("[bold red]Hello, World![/]");
 *
 * tuipp::print("[bold green]Hello, World![/]");
 * @endcode
 *
 * @author Giuliano De Amicis
 */

#pragma once

#include <iostream>
#include <ostream>
#include <string>

#include "../../src/tuipp/parse_string.hpp"

namespace tuipp {

/**
 * @brief Print an output to the screen with a new line at the end (supports markup).
 *
 * ## Examples:
 *
 * @code{.cpp}
 * tuipp::println("[bold green]Hello, World![/]");
 * tuipp::println("[green]This is green [bold]this is bold and green[/] this is still green[/]");
 * tuipp::println("[blue]Number of files: [/]", 10, ".");
 * tuipp::println("[green]This is green [bold]this is bold and green[reset] this is normal");
 * @endcode
 *
 * ## Styles:
 *
 * - Foreground colors: `red`, `green`, `grey`, `blue`, `magenta`, `yellow`, `white`, `bright_red`,
 *   `bright_green`, `bright_grey`, `bright_blue`, `bright_magenta`, `bright_yellow`, `bright_cyan`,
 *   `bright_white`
 *
 * - Background colors: `bg_red`, `bg_green`, `bg_grey`, `bg_blue`, `bg_magenta`, `bg_yellow`,
 *   `bg_cyan`, `bg_white`
 *
 * - Effects: `bold`, `underline`, `blink`, `italic`
 *
 * - Reset: `/`, `reset`
 *
 * ---
 *
 * You can also escape markup brackets using a backslash:
 *
 * @code{.cpp}
 * tuipp::println("\[bold red]Hello, World!\[/]");
 * @endcode
 *
 * @param content The items you want to print, they can be of any type and you can pass as many as
 * you want.
 */
template<typename... Args>
void
println(const Args&... content)
{
    std::ostream& output = std::cout;

    (
      [&]() {
          if constexpr (std::is_convertible_v<decltype(content), std::string>) {
              parse_string(output, content);
          } else {
              output << content;
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
 * tuipp::print("[bold green]Hello, World![/]");
 * tuipp::print("[green]This is green [bold]this is bold and green[/] this is still green[/]");
 * tuipp::print("[blue]Number of files: [/]", 10, ".");
 * tuipp::print("[green]This is green [bold]this is bold and green[reset] this is normal");
 * @endcode
 *
 * ## Styles:
 *
 * - Foreground colors: `red`, `green`, `grey`, `blue`, `magenta`, `yellow`, `white`, `bright_red`,
 *   `bright_green`, `bright_grey`, `bright_blue`, `bright_magenta`, `bright_yellow`, `bright_cyan`,
 *   `bright_white`
 *
 * - Background colors: `bg_red`, `bg_green`, `bg_grey`, `bg_blue`, `bg_magenta`, `bg_yellow`,
 *   `bg_cyan`, `bg_white`
 *
 * - Effects: `bold`, `underline`, `blink`, `italic`
 *
 * - Reset: `/`, `reset`
 *
 * ---
 *
 * You can also escape markup brackets using a backslash:
 *
 * @code{.cpp}
 * tuipp::print("\[bold red]Hello, World!\[/]");
 * @endcode
 *
 * @param content The items you want to print, they can be of any type and you can pass as many as
 * you want.
 */
template<typename... Args>
void
print(const Args&... content)
{
    std::ostream& output = std::cout;

    (
      [&]() {
          if constexpr (std::is_convertible_v<decltype(content), std::string>) {
              parse_string(output, content);
          } else {
              output << content;
          }
      }(),
      ...);
}

} // namespace tuipp
