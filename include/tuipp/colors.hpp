/**
 * @file colors.hpp
 *
 * @brief Plenty of colors!
 *
 * @author Giuliano De Amicis
 */

#pragma once

#include "../vendor/termcolor.hpp"

namespace tuipp {

/// Plenty of colors!
namespace colors {

template<typename CharT>
std::basic_ostream<CharT>&
red(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::red;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
green(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::green;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
grey(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::grey;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
blue(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::blue;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
magenta(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::magenta;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
yellow(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::yellow;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
cyan(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::cyan;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
white(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::white;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
on_red(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::on_red;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
on_green(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::on_green;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
on_grey(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::on_grey;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
on_blue(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::on_blue;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
on_magenta(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::on_magenta;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
on_yellow(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::on_yellow;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
on_cyan(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::on_cyan;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
on_white(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::on_white;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
bright_red(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::bright_red;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
bright_green(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::bright_green;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
bright_grey(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::bright_grey;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
bright_blue(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::bright_blue;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
bright_magenta(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::bright_magenta;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
bright_yellow(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::bright_yellow;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
bright_cyan(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::bright_cyan;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
bright_white(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::bright_white;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
bold(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::bold;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
underline(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::underline;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
blink(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::blink;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
italic(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::italic;

    return stream;
}

template<typename CharT>
std::basic_ostream<CharT>&
reset(std::basic_ostream<CharT>& stream)
{
    stream << termcolor::reset;

    return stream;
}

} // namespace colors

} // namespace tuipp
