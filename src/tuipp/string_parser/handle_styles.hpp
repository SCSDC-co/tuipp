#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>

#include "vendor/termcolor.hpp"

namespace tuipp {

enum class Style
{
    RED,
    GREEN,
    GREY,
    BLUE,
    MAGENTA,
    YELLOW,
    CYAN,
    WHITE,
    BG_RED,
    BG_GREEN,
    BG_GREY,
    BG_BLUE,
    BG_MAGENTA,
    BG_YELLOW,
    BG_CYAN,
    BG_WHITE,
    BRIGHT_RED,
    BRIGHT_GREEN,
    BRIGHT_GREY,
    BRIGHT_BLUE,
    BRIGHT_MAGENTA,
    BRIGHT_YELLOW,
    BRIGHT_CYAN,
    BRIGHT_WHITE,
    BOLD,
    UNDERLINE,
    BLINK,
    ITALIC,
    RESET,
};

inline const std::unordered_map<std::string, Style> token_to_style{
    { "red", Style::RED },
    { "green", Style::GREEN },
    { "grey", Style::GREY },
    { "blue", Style::BLUE },
    { "magenta", Style::MAGENTA },
    { "yellow", Style::YELLOW },
    { "cyan", Style::CYAN },
    { "white", Style::WHITE },
    { "bg_red", Style::BG_RED },
    { "bg_green", Style::BG_GREEN },
    { "bg_grey", Style::BG_GREY },
    { "bg_blue", Style::BG_BLUE },
    { "bg_magenta", Style::BG_MAGENTA },
    { "bg_yellow", Style::BG_YELLOW },
    { "bg_cyan", Style::BG_CYAN },
    { "bg_white", Style::BG_WHITE },
    { "bright_red", Style::BRIGHT_RED },
    { "bright_green", Style::BRIGHT_GREEN },
    { "bright_grey", Style::BRIGHT_GREY },
    { "bright_blue", Style::BRIGHT_BLUE },
    { "bright_magenta", Style::BRIGHT_MAGENTA },
    { "bright_yellow", Style::BRIGHT_YELLOW },
    { "bright_cyan", Style::BRIGHT_CYAN },
    { "bright_white", Style::BRIGHT_WHITE },
    { "bold", Style::BOLD },
    { "underline", Style::UNDERLINE },
    { "blink", Style::BLINK },
    { "italic", Style::ITALIC },
    { "/", Style::RESET },
};

template<typename CharT>
std::basic_ostream<CharT>&
apply_style(std::basic_ostream<CharT>& stream, const Style style)
{
    switch (style) {
        case Style::RED:
            stream << termcolor::red;
            break;
        case Style::GREEN:
            stream << termcolor::green;
            break;
        case Style::GREY:
            stream << termcolor::grey;
            break;
        case Style::BLUE:
            stream << termcolor::blue;
            break;
        case Style::MAGENTA:
            stream << termcolor::magenta;
            break;
        case Style::YELLOW:
            stream << termcolor::yellow;
            break;
        case Style::CYAN:
            stream << termcolor::cyan;
            break;
        case Style::WHITE:
            stream << termcolor::white;
            break;
        case Style::BG_RED:
            stream << termcolor::on_red;
            break;
        case Style::BG_GREEN:
            stream << termcolor::on_green;
            break;
        case Style::BG_GREY:
            stream << termcolor::on_grey;
            break;
        case Style::BG_BLUE:
            stream << termcolor::on_blue;
            break;
        case Style::BG_MAGENTA:
            stream << termcolor::on_magenta;
            break;
        case Style::BG_YELLOW:
            stream << termcolor::on_yellow;
            break;
        case Style::BG_CYAN:
            stream << termcolor::on_cyan;
            break;
        case Style::BG_WHITE:
            stream << termcolor::on_white;
            break;
        case Style::BRIGHT_RED:
            stream << termcolor::bright_red;
            break;
        case Style::BRIGHT_GREEN:
            stream << termcolor::bright_green;
            break;
        case Style::BRIGHT_GREY:
            stream << termcolor::bright_grey;
            break;
        case Style::BRIGHT_BLUE:
            stream << termcolor::bright_blue;
            break;
        case Style::BRIGHT_MAGENTA:
            stream << termcolor::bright_magenta;
            break;
        case Style::BRIGHT_YELLOW:
            stream << termcolor::bright_yellow;
            break;
        case Style::BRIGHT_CYAN:
            stream << termcolor::bright_cyan;
            break;
        case Style::BRIGHT_WHITE:
            stream << termcolor::bright_white;
            break;
        case Style::BOLD:
            stream << termcolor::bold;
            break;
        case Style::UNDERLINE:
            stream << termcolor::underline;
            break;
        case Style::BLINK:
            stream << termcolor::blink;
            break;
        case Style::ITALIC:
            stream << termcolor::italic;
            break;
        case Style::RESET:
            stream << termcolor::reset;
            break;
    }

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
handle_styles(std::basic_ostream<CharT>& stream, const std::string& buffer)
{
    if (token_to_style.find(buffer) == token_to_style.end()) {
        std::cerr << '\"' << buffer << '\"' << " is not a valid style!" << std::endl;

        std::exit(1);
    } else {
        Style style = token_to_style.at(buffer);

        apply_style(stream, style);
    }

    return stream;
}

} // namespace tuipp
