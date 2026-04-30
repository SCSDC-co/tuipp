#pragma once

#include <string>

#include "tuipp/widgets/IRenderable.hpp"

namespace tuipp {

namespace widgets {

/**
 * @brief A widget for writing colorful text easily
 *
 * ## Examples of use
 *
 * @code{.cpp}
 * // Create the widget:
 * auto markup_text = tuipp::widgets::MarkupText("[bold][green]Markup[/] [blue]text[/][/]");
 *
 * // 3 ways of rendering it:
 * tuipp::Console console;
 * console << markup_text;
 *
 * tuipp::Console::println(markup_text);
 *
 * markup_text.render();
 * @endcode
 *
 * ## Styles:
 *
 * - Foreground colors: `red`, `green`, `grey`, `blue`, `magenta`, `yellow`, `white`, `bright
 *   red`, `bright green`, `bright grey`, `bright blue`, `bright magenta`, `bright yellow`,
 *   `bright cyan`, `bright white`
 *
 * - Effects: `bold`, `underline`, `blink`, `italic`, `dim`, `strikethrough`, `conceal`,
 *   `reverse`
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
 */
class MarkupText : public tuipp::widgets::IRenderable
{
  public:
    MarkupText(std::string content)
      : content(content)
    {
    }

    virtual void render(const int& width) const override;
    virtual int get_lenght() const override;

  private:
    std::string content{};
};

} // namespace widgets

} // namespace tuipp
