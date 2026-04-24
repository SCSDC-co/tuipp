/**
 * @file print.hpp
 *
 * @brief A utility to print text with markup support.
 *
 * @details Example:
 *
 * @code{.cpp}
 * tuipp::println("[bold red]Hello, World![reset]");
 * tuipp::print("[bold green]Hello, World![reset]");
 * @endcode
 *
 * @author Giuliano De Amicis
 */

#pragma once

#include <iostream>
#include <ostream>
#include <print>
#include <string>

#include "../../src/tuipp/string_parser/parse_string.hpp"

namespace tuipp {

/**
 * @brief Print an output to the screen with a new line at the end (supports markup).
 *
 * ## Examples:
 *
 * @code{.cpp}
 * tuipp::println("[bold green]Hello, World![/]");
 * tuipp::println(
 * "[green]This is green [bold]this is bold and green[/] this is still green[/]"
 * );
 * tuipp::println("[blue]Number of files: [/]", 10, ".");
 * tuipp::println("[green]This is green [bold]this is bold and green[reset] this is normal");
 * @endcode
 *
 * ## Styles:
 *
 * - Foreground colors: `red`, `green`, `grey`, `blue`, `magenta`, `yellow`, `white`, `bright red`,
 *   `bright green`, `bright grey`, `bright blue`, `bright magenta`, `bright yellow`, `bright cyan`,
 *   `bright white`
 *
 * - Effects: `bold`, `underline`, `blink`, `italic`
 *
 * - Reset: `/` (for one style)
 *
 * - For the background colors just type: `on <color>`
 *
 * ---
 *
 * You can also escape markup brackets using a backslash:
 *
 * @code{.cpp}
 * tuipp::println("\[bold red]Hello, World!\[/]");
 * @endcode
 *
 * ---
 *
 * It can also print iterables:
 *
 * @code{.cpp}
 * std::vector<int> vector{ { 1, 2, 3, 4, 5, 6 } };
 *
 * tuipp::println(vector);
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
 * tuipp::print("[bold green]Hello, World![/]");
 * tuipp::print(
 * "[green]This is green [bold]this is bold and green[/] this is still green[/]"
 * );
 * tuipp::print("[blue]Number of files: [/]", 10, ".");
 * tuipp::print("[green]This is green [bold]this is bold and green[reset] this is normal");
 * @endcode
 *
 * ## Styles:
 *
 * - Foreground colors: `red`, `green`, `grey`, `blue`, `magenta`, `yellow`, `white`, `bright red`,
 *   `bright green`, `bright grey`, `bright blue`, `bright magenta`, `bright yellow`, `bright cyan`,
 *   `bright white`
 *
 * - Effects: `bold`, `underline`, `blink`, `italic`
 *
 * - Reset: `/` (for one style)
 *
 * - For the background colors just type: `on <color>`
 *
 * ---
 *
 * You can also escape markup brackets using a backslash:
 *
 * @code{.cpp}
 * tuipp::print("\[bold red]Hello, World!\[/]");
 * @endcode
 *
 * ---
 *
 * It can also print iterables:
 *
 * @code{.cpp}
 * std::vector<int> vector{ { 1, 2, 3, 4, 5, 6 } };
 *
 * tuipp::print(vector);
 * @endcode
 *
 * @param content The items you want to print, they can be of any type and you can pass as many as
 * you want.
 */
template<typename... Args>
void
print(const Args&... content)
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

} // namespace tuipp
