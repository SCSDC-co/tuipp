#include "../../../../include/tuipp/widgets/MarkupText.hpp"

#include "parser/parse_string.hpp"

namespace tuipp {

namespace widgets {

void
MarkupText::render() const
{
    markup_text::parse_string(std::cout, this->content);
}

} // namespace widgets

} // namespace tuipp
