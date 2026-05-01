#include "tuipp/widgets/Panel.hpp"

#include <iostream>

#include "tuipp/styles/Border.hpp"
#include "tuipp/widgets/IRenderable.hpp"
#include "widgets/apply_styles.hpp"
#include "widgets/markup_text/parser/get_text_length.hpp"
#include "widgets/markup_text/parser/parse_string.hpp"

namespace tuipp {

namespace widgets {

void
Panel::render(const int& width) const
{
    const int header_lenght{ markup_text::get_text_length(this->header) };

    int biggest_lenght{ 0 };

    for (auto& widget : this->childrens) {
        int widget_lenght{ widget->get_length() };

        if (widget_lenght > biggest_lenght) {
            biggest_lenght = widget_lenght;
        }
    }

    if (header_lenght > biggest_lenght) {
        biggest_lenght = header_lenght;
    }

    const int actual_width{ biggest_lenght + 2 };

    apply_foreground(std::cout, this->border_color);

    std::cout << styles::border::get_part_from_border_type(this->border,
                                                           styles::border::BorderParts::TOP_LEFT)
              << termcolor::reset;

    markup_text::parse_string(std::cout, this->header);

    apply_foreground(std::cout, this->border_color);

    for (int i = 0; i < actual_width - header_lenght - 2; ++i) {
        std::cout << styles::border::get_part_from_border_type(this->border,
                                                               styles::border::BorderParts::TOP);
    }

    std::cout << styles::border::get_part_from_border_type(this->border,
                                                           styles::border::BorderParts::TOP_RIGHT)
              << termcolor::reset << '\n';

    for (auto& widget : this->childrens) {
        apply_foreground(std::cout, this->border_color);

        std::cout << styles::border::get_part_from_border_type(this->border,
                                                               styles::border::BorderParts::LEFT)
                  << termcolor::reset;

        widget->render(width - actual_width);

        for (int i = widget->get_length(); i < actual_width - 2; ++i) {
            std::cout << ' ';
        }

        apply_foreground(std::cout, this->border_color);

        std::cout << styles::border::get_part_from_border_type(this->border,
                                                               styles::border::BorderParts::RIGHT)
                  << termcolor::reset << '\n';
    }

    apply_foreground(std::cout, this->border_color);

    std::cout << styles::border::get_part_from_border_type(
      this->border, styles::border::BorderParts::BOTTOM_LEFT);

    for (int i = 0; i < actual_width - 2; ++i) {
        std::cout << styles::border::get_part_from_border_type(this->border,
                                                               styles::border::BorderParts::BOTTOM);
    }

    std::cout << styles::border::get_part_from_border_type(
                   this->border, styles::border::BorderParts::BOTTOM_RIGHT)
              << termcolor::reset;
}

void
Panel::add_element(IRenderable& item)
{
    this->childrens.push_back(&item);
}

int
Panel::get_length() const
{
    int lenght{};

    int header_lenght = markup_text::get_text_length(this->header) + 2;

    lenght = header_lenght;

    int longest{ 0 };

    for (auto& widget : this->childrens) {
        int widget_lenght = widget->get_length();

        if (widget_lenght > longest) {
            longest = widget_lenght;
        }
    }

    if (longest > header_lenght) {
        lenght = longest;
    }

    return lenght;
}

} // namespace widgets

} // namespace tuipp
