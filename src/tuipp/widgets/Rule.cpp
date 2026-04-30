#include "tuipp/widgets/Rule.hpp"

#include <ostream>

#include "../src/vendor/termcolor.hpp"
#include "apply_styles.hpp"
#include "markup_text/parser/get_text_length.hpp"
#include "markup_text/parser/parse_string.hpp"

namespace tuipp {

namespace widgets {

void
Rule::render(const int& width) const
{
    std::ostream& output{ std::cout };

    int content_length{ markup_text::get_text_length(this->content) };

    int padding_left{};
    int padding_right{};

    switch (this->justification) {
        case styles::Justification::LEFT:
            padding_left  = 0;
            padding_right = width - content_length;
            break;
        case styles::Justification::CENTER:
            padding_left  = (width / 2) - (content_length / 2);
            padding_right = (width / 2) - (content_length / 2);
            break;
        case styles::Justification::RIGHT:
            padding_left  = width - content_length;
            padding_right = 0;
            break;
    }

    int total_width{ 0 };

    apply_foreground(output, this->color);

    for (int i = 0; i < padding_left; ++i) {
        output << this->fill_char;

        ++total_width;
    }

    output << termcolor::reset;

    markup_text::parse_string(output, this->content);

    output << termcolor::reset;

    apply_foreground(output, this->color);

    total_width += content_length;

    for (int i = 0; i < padding_right && total_width < width; ++i) {
        output << this->fill_char;

        ++total_width;
    }

    output << termcolor::reset << '\n';
}

} // namespace widgets

} // namespace tuipp
