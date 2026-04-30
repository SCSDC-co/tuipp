#pragma once

#include <string>
#include <vector>

#include "tuipp/styles/Background.hpp"
#include "tuipp/styles/Effects.hpp"
#include "tuipp/styles/Foreground.hpp"
#include "tuipp/styles/Justification.hpp"
#include "tuipp/widgets/IRenderable.hpp"

namespace tuipp {

namespace widgets {

/**
 * @brief Just normal text!
 *
 * ## Examples of use
 *
 * @code{.cpp}
 * // Create the widget:
 * auto text = tuipp::widgets::Text("Text widget!");
 *
 * // 3 ways of rendering it:
 * tuipp::Console console;
 * console << text;
 *
 * tuipp::Console::println(text);
 *
 * text.render();
 * @endcode
 *
 * It also support styles:
 *
 * @code{.cpp}
 * auto colored_text =
 *   tuipp::widgets::Text("Colored text!",
 *                        tuipp::styles::Foreground::GREEN,
 *                        tuipp::styles::Background::GREY,
 *                        { tuipp::styles::Effects::BOLD });
 * @endcode
 */
class Text : public tuipp::widgets::IRenderable
{
  public:
    styles::Foreground foreground{};
    styles::Background background{};
    std::vector<styles::Effects> effects{};

    styles::Justification justification{};

    Text(std::string content,
         styles::Justification justification  = styles::Justification::LEFT,
         styles::Foreground foreground        = styles::Foreground::NONE,
         styles::Background background        = styles::Background::NONE,
         std::vector<styles::Effects> effects = { styles::Effects::NONE })
      : content(content)
      , justification(justification)
      , foreground(foreground)
      , background(background)
      , effects(effects)
    {
    }

    virtual void render(const int& width) const override;
    virtual int get_lenght() const override;

  private:
    std::string content{};
};

} // namespace widgets

} // namespace tuipp
