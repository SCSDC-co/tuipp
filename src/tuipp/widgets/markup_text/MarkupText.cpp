#include "tuipp/widgets/MarkupText.hpp"

#include "parser/parse_string.hpp"
#include "widgets/markup_text/parser/get_text_length.hpp"

namespace tuipp {

namespace widgets {

void
MarkupText::render(const int& width) const
{
    markup_text::parse_string(std::cout, this->content);
}

int
MarkupText::get_length() const
{
    return markup_text::get_text_length(this->content);
}

} // namespace widgets

} // namespace tuipp
