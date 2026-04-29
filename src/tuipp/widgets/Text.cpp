#include "../../../include/tuipp/widgets/Text.hpp"

#include <cstddef>
#include <iostream>
#include <string>

#include "../../../include/tuipp/styles/Justification.hpp"
#include "../../../include/vendor/termcolor.hpp"
#include "../tuipp/Console.hpp"
#include "apply_styles.hpp"
#include "widgets/apply_styles.hpp"

namespace tuipp {

namespace widgets {

void
Text::render() const
{
    std::ostream& output = std::cout;

    std::size_t total_width{ Console::terminal_size.width };

    int padding{};

    switch (this->justification) {
        case styles::Justification::LEFT:
            padding = 0;
            break;
        case styles::Justification::CENTER:
            padding = (total_width / 2) - (this->content.length() / 2);
            break;
        case styles::Justification::RIGHT:
            padding = (total_width - this->content.length());
            break;
    }

    output << std::string(padding, ' ');

    apply_background(output, this->background);
    apply_foreground(output, this->foreground);

    for (auto effect : this->effects) {
        apply_effect(output, effect);
    }

    output << this->content;

    output << termcolor::reset;
}

} // namespace widgets

} // namespace tuipp
