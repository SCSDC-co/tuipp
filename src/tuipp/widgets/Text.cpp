#include "tuipp/widgets/Text.hpp"

#include <iostream>
#include <string>

#include "../src/vendor/termcolor.hpp"
#include "apply_styles.hpp"
#include "tuipp/styles/Justification.hpp"
#include "widgets/apply_styles.hpp"

namespace tuipp {

namespace widgets {

void
Text::render(const int& width) const
{
    std::ostream& output = std::cout;

    int padding{};

    switch (this->justification) {
        case styles::Justification::LEFT:
            padding = 0;
            break;
        case styles::Justification::CENTER:
            padding = (width / 2) - (this->content.length() / 2);
            break;
        case styles::Justification::RIGHT:
            padding = (width - this->content.length());
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

int
Text::get_length() const
{
    return this->content.length();
}

} // namespace widgets

} // namespace tuipp
