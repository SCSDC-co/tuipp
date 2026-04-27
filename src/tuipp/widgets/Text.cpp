#include "tuipp/widgets/Text.hpp"

#include <iostream>

#include "../../../src/tuipp/widgets/apply_styles.hpp"
#include "apply_styles.hpp"
#include "vendor/termcolor.hpp"

namespace tuipp {

namespace widgets {

void
Text::render() const
{
    std::ostream& output = std::cout;

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
