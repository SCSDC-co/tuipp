#pragma once

#include "tuipp/styles/Background.hpp"
#include "tuipp/styles/Effects.hpp"
#include "tuipp/styles/Foreground.hpp"
#include "vendor/termcolor.hpp"

namespace tuipp {

namespace widgets {

template<typename CharT>
std::basic_ostream<CharT>&
apply_foreground(std::basic_ostream<CharT>& stream, styles::Foreground foreground)
{
    switch (foreground) {
        case styles::Foreground::NONE:
            break;
        case styles::Foreground::RED:
            stream << termcolor::red;
            break;
        case styles::Foreground::GREEN:
            stream << termcolor::green;
            break;
        case styles::Foreground::GREY:
            stream << termcolor::grey;
            break;
        case styles::Foreground::BLUE:
            stream << termcolor::blue;
            break;
        case styles::Foreground::MAGENTA:
            stream << termcolor::magenta;
            break;
        case styles::Foreground::YELLOW:
            stream << termcolor::yellow;
            break;
        case styles::Foreground::CYAN:
            stream << termcolor::cyan;
            break;
        case styles::Foreground::WHITE:
            stream << termcolor::white;
            break;
        case styles::Foreground::BRIGHT_RED:
            stream << termcolor::bright_red;
            break;
        case styles::Foreground::BRIGHT_GREEN:
            stream << termcolor::bright_green;
            break;
        case styles::Foreground::BRIGHT_GREY:
            stream << termcolor::bright_grey;
            break;
        case styles::Foreground::BRIGHT_BLUE:
            stream << termcolor::bright_blue;
            break;
        case styles::Foreground::BRIGHT_MAGENTA:
            stream << termcolor::bright_magenta;
            break;
        case styles::Foreground::BRIGHT_YELLOW:
            stream << termcolor::bright_yellow;
            break;
        case styles::Foreground::BRIGHT_CYAN:
            stream << termcolor::bright_cyan;
            break;
        case styles::Foreground::BRIGHT_WHITE:
            stream << termcolor::bright_white;
            break;
    }

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
apply_background(std::basic_ostream<CharT>& stream, styles::Background background)
{
    switch (background) {
        case styles::Background::NONE:
            break;
        case styles::Background::RED:
            stream << termcolor::on_red;
            break;
        case styles::Background::GREEN:
            stream << termcolor::on_green;
            break;
        case styles::Background::GREY:
            stream << termcolor::on_grey;
            break;
        case styles::Background::BLUE:
            stream << termcolor::on_blue;
            break;
        case styles::Background::MAGENTA:
            stream << termcolor::on_magenta;
            break;
        case styles::Background::YELLOW:
            stream << termcolor::on_yellow;
            break;
        case styles::Background::CYAN:
            stream << termcolor::on_cyan;
            break;
        case styles::Background::WHITE:
            stream << termcolor::on_white;
            break;
        case styles::Background::BRIGHT_RED:
            stream << termcolor::on_bright_red;
            break;
        case styles::Background::BRIGHT_GREEN:
            stream << termcolor::on_bright_green;
            break;
        case styles::Background::BRIGHT_GREY:
            stream << termcolor::on_bright_grey;
            break;
        case styles::Background::BRIGHT_BLUE:
            stream << termcolor::on_bright_blue;
            break;
        case styles::Background::BRIGHT_MAGENTA:
            stream << termcolor::on_bright_magenta;
            break;
        case styles::Background::BRIGHT_YELLOW:
            stream << termcolor::on_bright_yellow;
            break;
        case styles::Background::BRIGHT_CYAN:
            stream << termcolor::on_bright_cyan;
            break;
        case styles::Background::BRIGHT_WHITE:
            stream << termcolor::on_bright_white;
            break;
    }

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
apply_effect(std::basic_ostream<CharT>& stream, styles::Effects effect)
{
    switch (effect) {
        case styles::Effects::NONE:
            break;
        case styles::Effects::BOLD:
            stream << termcolor::bold;
            break;
        case styles::Effects::UNDERLINE:
            stream << termcolor::underline;
            break;
        case styles::Effects::BLINK:
            stream << termcolor::blink;
            break;
        case styles::Effects::ITALIC:
            stream << termcolor::italic;
            break;
        case styles::Effects::DIM:
            stream << termcolor::dark;
            break;
        case styles::Effects::REVERSE:
            stream << termcolor::reverse;
            break;
        case styles::Effects::CONCEALED:
            stream << termcolor::concealed;
            break;
        case styles::Effects::STRIKE_THROUGH:
            stream << termcolor::crossed;
            break;
    }

    return stream;
}

} // namespace widgets

} // namespace tuipp
