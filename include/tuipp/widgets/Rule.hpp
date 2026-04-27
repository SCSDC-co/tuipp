#pragma once

#include <string>

#include "../../../src/tuipp/widgets/IRenderable.hpp"
#include "tuipp/styles/Border.hpp"
#include "tuipp/styles/Foreground.hpp"
#include "tuipp/styles/Justification.hpp"

namespace tuipp {

namespace widgets {

class Rule : public tuipp::widgets::IRenderable
{
  public:
    std::string fill_char{};

    styles::Justification justification{};
    styles::Foreground color{};

    Rule(std::string content,
         styles::border::BorderType border = styles::border::BorderType::SQUARE)
      : content(content)
      , fill_char(
          styles::border::get_part_from_border_type(border, styles::border::BorderParts::TOP))
    {
    }

    virtual void render() const;

  private:
    std::string content{};
};

} // namespace widgets

} // namespace tuipp
