#include "tuipp/widgets/Rule.hpp"

#include <cstddef>
#include <ostream>

#include "apply_styles.hpp"
#include "markup_text/parser/get_text_lenght.hpp"
#include "markup_text/parser/parse_string.hpp"
#include "tuipp/Console.hpp"
#include "vendor/termcolor.hpp"

namespace tuipp {

namespace widgets {

void
Rule::render() const
{
    std::ostream& output{ std::cout };

    int content_lenght{ markup_text::get_text_lenght(this->content) };

    std::size_t total_width{ Console::terminal_size.width };

    int padding_left{};
    int padding_right{};

    switch (this->justification) {
        case styles::Justification::LEFT:
            padding_left  = 0;
            padding_right = total_width - content_lenght;
            break;
        case styles::Justification::CENTER:
            padding_left  = (total_width / 2) - (content_lenght / 2);
            padding_right = (total_width / 2) - (content_lenght / 2);
            break;
        case styles::Justification::RIGHT:
            padding_left  = total_width - content_lenght;
            padding_right = 0;
            break;
    }

    int width{ 0 };

    apply_foreground(output, this->color);

    for (int i = 0; i < padding_left; ++i) {
        output << this->fill_char;

        ++width;
    }

    output << termcolor::reset;

    markup_text::parse_string(output, this->content);

    output << termcolor::reset;

    apply_foreground(output, this->color);

    width += content_lenght;

    for (int i = 0; i < padding_right && width < total_width; ++i) {
        output << this->fill_char;

        ++width;
    }

    output << termcolor::reset << std::endl;
}

} // namespace widgets

} // namespace tuipp
