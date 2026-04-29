#pragma once

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../../../../../include/vendor/termcolor.hpp"
#include "../../Style.hpp"

namespace tuipp {

namespace widgets {

namespace markup_text {

inline const std::unordered_map<std::string, tuipp::widgets::Style> token_to_style{
    { "red", tuipp::widgets::Style::RED },
    { "green", tuipp::widgets::Style::GREEN },
    { "grey", tuipp::widgets::Style::GREY },
    { "gray", tuipp::widgets::Style::GREY },
    { "blue", tuipp::widgets::Style::BLUE },
    { "magenta", tuipp::widgets::Style::MAGENTA },
    { "yellow", tuipp::widgets::Style::YELLOW },
    { "cyan", tuipp::widgets::Style::CYAN },
    { "white", tuipp::widgets::Style::WHITE },
    { "on red", tuipp::widgets::Style::BG_RED },
    { "on green", tuipp::widgets::Style::BG_GREEN },
    { "on grey", tuipp::widgets::Style::BG_GREY },
    { "on gray", tuipp::widgets::Style::BG_GREY },
    { "on blue", tuipp::widgets::Style::BG_BLUE },
    { "on magenta", tuipp::widgets::Style::BG_MAGENTA },
    { "on yellow", tuipp::widgets::Style::BG_YELLOW },
    { "on cyan", tuipp::widgets::Style::BG_CYAN },
    { "on white", tuipp::widgets::Style::BG_WHITE },
    { "bright red", tuipp::widgets::Style::BRIGHT_RED },
    { "bright green", tuipp::widgets::Style::BRIGHT_GREEN },
    { "bright grey", tuipp::widgets::Style::BRIGHT_GREY },
    { "bright gray", tuipp::widgets::Style::BRIGHT_GREY },
    { "bright blue", tuipp::widgets::Style::BRIGHT_BLUE },
    { "bright magenta", tuipp::widgets::Style::BRIGHT_MAGENTA },
    { "bright yellow", tuipp::widgets::Style::BRIGHT_YELLOW },
    { "bright cyan", tuipp::widgets::Style::BRIGHT_CYAN },
    { "bright white", tuipp::widgets::Style::BRIGHT_WHITE },
    { "on bright red", tuipp::widgets::Style::BG_BRIGHT_RED },
    { "on bright green", tuipp::widgets::Style::BG_BRIGHT_GREEN },
    { "on bright grey", tuipp::widgets::Style::BG_BRIGHT_GREY },
    { "on bright gray", tuipp::widgets::Style::BG_BRIGHT_GREY },
    { "on bright blue", tuipp::widgets::Style::BG_BRIGHT_BLUE },
    { "on bright magenta", tuipp::widgets::Style::BG_BRIGHT_MAGENTA },
    { "on bright yellow", tuipp::widgets::Style::BG_BRIGHT_YELLOW },
    { "on bright cyan", tuipp::widgets::Style::BG_BRIGHT_CYAN },
    { "on bright white", tuipp::widgets::Style::BG_BRIGHT_WHITE },
    { "bold", tuipp::widgets::Style::BOLD },
    { "underline", tuipp::widgets::Style::UNDERLINE },
    { "blink", tuipp::widgets::Style::BLINK },
    { "italic", tuipp::widgets::Style::ITALIC },
    { "dim", tuipp::widgets::Style::DIM },
    { "reverse", tuipp::widgets::Style::REVERSE },
    { "conceal", tuipp::widgets::Style::CONCEALED },
    { "strikethrough", tuipp::widgets::Style::STRIKE_THROUGH },
    { "/", tuipp::widgets::Style::RESET },
    { "reset", tuipp::widgets::Style::RESET_ALL }
};

template<typename CharT>
std::basic_ostream<CharT>&
apply_style(std::basic_ostream<CharT>& stream, const tuipp::widgets::Style style)
{
    switch (style) {
        case tuipp::widgets::Style::RED:
            stream << termcolor::red;
            break;
        case tuipp::widgets::Style::GREEN:
            stream << termcolor::green;
            break;
        case tuipp::widgets::Style::GREY:
            stream << termcolor::grey;
            break;
        case tuipp::widgets::Style::BLUE:
            stream << termcolor::blue;
            break;
        case tuipp::widgets::Style::MAGENTA:
            stream << termcolor::magenta;
            break;
        case tuipp::widgets::Style::YELLOW:
            stream << termcolor::yellow;
            break;
        case tuipp::widgets::Style::CYAN:
            stream << termcolor::cyan;
            break;
        case tuipp::widgets::Style::WHITE:
            stream << termcolor::white;
            break;
        case tuipp::widgets::Style::BG_RED:
            stream << termcolor::on_red;
            break;
        case tuipp::widgets::Style::BG_GREEN:
            stream << termcolor::on_green;
            break;
        case tuipp::widgets::Style::BG_GREY:
            stream << termcolor::on_grey;
            break;
        case tuipp::widgets::Style::BG_BLUE:
            stream << termcolor::on_blue;
            break;
        case tuipp::widgets::Style::BG_MAGENTA:
            stream << termcolor::on_magenta;
            break;
        case tuipp::widgets::Style::BG_YELLOW:
            stream << termcolor::on_yellow;
            break;
        case tuipp::widgets::Style::BG_CYAN:
            stream << termcolor::on_cyan;
            break;
        case tuipp::widgets::Style::BG_WHITE:
            stream << termcolor::on_white;
            break;
        case tuipp::widgets::Style::BRIGHT_RED:
            stream << termcolor::bright_red;
            break;
        case tuipp::widgets::Style::BRIGHT_GREEN:
            stream << termcolor::bright_green;
            break;
        case tuipp::widgets::Style::BRIGHT_GREY:
            stream << termcolor::bright_grey;
            break;
        case tuipp::widgets::Style::BRIGHT_BLUE:
            stream << termcolor::bright_blue;
            break;
        case tuipp::widgets::Style::BRIGHT_MAGENTA:
            stream << termcolor::bright_magenta;
            break;
        case tuipp::widgets::Style::BRIGHT_YELLOW:
            stream << termcolor::bright_yellow;
            break;
        case tuipp::widgets::Style::BRIGHT_CYAN:
            stream << termcolor::bright_cyan;
            break;
        case tuipp::widgets::Style::BRIGHT_WHITE:
            stream << termcolor::bright_white;
            break;
        case tuipp::widgets::Style::BG_BRIGHT_RED:
            stream << termcolor::on_bright_red;
            break;
        case tuipp::widgets::Style::BG_BRIGHT_GREEN:
            stream << termcolor::on_bright_green;
            break;
        case tuipp::widgets::Style::BG_BRIGHT_GREY:
            stream << termcolor::on_bright_grey;
            break;
        case tuipp::widgets::Style::BG_BRIGHT_BLUE:
            stream << termcolor::on_bright_blue;
            break;
        case tuipp::widgets::Style::BG_BRIGHT_MAGENTA:
            stream << termcolor::on_bright_magenta;
            break;
        case tuipp::widgets::Style::BG_BRIGHT_YELLOW:
            stream << termcolor::on_bright_yellow;
            break;
        case tuipp::widgets::Style::BG_BRIGHT_CYAN:
            stream << termcolor::on_bright_cyan;
            break;
        case tuipp::widgets::Style::BG_BRIGHT_WHITE:
            stream << termcolor::on_bright_white;
            break;
        case tuipp::widgets::Style::BOLD:
            stream << termcolor::bold;
            break;
        case tuipp::widgets::Style::UNDERLINE:
            stream << termcolor::underline;
            break;
        case tuipp::widgets::Style::BLINK:
            stream << termcolor::blink;
            break;
        case tuipp::widgets::Style::ITALIC:
            stream << termcolor::italic;
            break;
        case tuipp::widgets::Style::DIM:
            stream << termcolor::dark;
            break;
        case tuipp::widgets::Style::CONCEALED:
            stream << termcolor::concealed;
            break;
        case tuipp::widgets::Style::STRIKE_THROUGH:
            stream << termcolor::crossed;
            break;
        case tuipp::widgets::Style::REVERSE:
            stream << termcolor::reverse;
            break;
    }

    return stream;
}

struct Styles
{
    std::vector<tuipp::widgets::Style> styles{};

    template<typename CharT>
    std::basic_ostream<CharT>& apply_styles(std::basic_ostream<CharT>& stream)
    {
        for (const tuipp::widgets::Style style : styles) {
            apply_style(stream, style);
        }

        return stream;
    }
};

template<typename CharT>
std::basic_ostream<CharT>&
handle_styles(std::basic_ostream<CharT>& stream,
              const std::string& buffer,
              std::vector<Styles>& styles)
{
    std::istringstream iss(buffer);

    std::string token{};

    std::vector<std::string> token_vec{};

    std::vector<tuipp::widgets::Style> style_vec{};

    while (iss >> token) {
        token_vec.push_back(token);
    }

    for (int i = 0; i < token_vec.size(); ++i) {
        std::string buffer{ token_vec[i] };

        if (buffer == "on") {
            if (token_vec[i + 1] == "bright") {
                buffer = buffer + ' ' + token_vec[i + 1] + ' ' + token_vec[i + 2];

                i += 2;
            } else {
                buffer = buffer + ' ' + token_vec[i + 1];

                ++i;
            }
        } else if (buffer == "bright") {
            buffer = buffer + ' ' + token_vec[i + 1];

            ++i;
        }

        if (token_to_style.find(buffer) == token_to_style.end()) {
            std::cerr << '\n'
                      << termcolor::reset << '\"' << buffer << '\"' << " is not a valid style!"
                      << std::endl;

            std::exit(1);
        } else {
            tuipp::widgets::Style style = token_to_style.at(buffer);

            if (style == tuipp::widgets::Style::RESET) {
                styles.pop_back();

                stream << termcolor::reset;
            } else if (style == tuipp::widgets::Style::RESET_ALL) {
                styles.clear();

                stream << termcolor::reset;
            } else {
                style_vec.push_back(style);
            }
        }
    }

    styles.emplace_back(style_vec);

    for (int i = 0; i < styles.size(); ++i) {
        styles[i].apply_styles(stream);
    }

    return stream;
}

} // namespace markup_text

} // namespace widgets

} // namespace tuipp
