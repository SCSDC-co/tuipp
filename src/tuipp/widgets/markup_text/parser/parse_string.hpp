#pragma once

#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "handle_styles.hpp"
#include "vendor/termcolor.hpp"

namespace tuipp {

namespace widgets {

namespace markup_text {

template<typename CharT>
std::basic_ostream<CharT>&
parse_string(std::basic_ostream<CharT>& stream, const std::string& string)
{
    char prev_char{};

    std::vector<Styles> styles{};

    for (std::size_t i = 0; i < string.size(); ++i) {
        char current_char{ string[i] };
        char next_char{ string[i + 1] };

        if (current_char == '[' && prev_char != '[' && next_char != '[') {
            std::string buffer{};

            while (current_char != ']') {
                ++i;

                current_char = string[i];

                buffer += current_char;
            }

            // this removes the ']' at the end of the buffer
            buffer.pop_back();

            handle_styles(stream, buffer, styles);
        } else {
            // it will print "[[" without this
            if (current_char == '[' && (next_char == '[' || prev_char == '[')) {
                stream << '[';

                ++i;
            } else if (current_char == ']' && (next_char == ']' || prev_char == ']')) {
                stream << ']';

                ++i;
            } else {
                stream << current_char;
            }
        }

        prev_char = current_char;
    }

    stream << termcolor::reset;

    return stream;
}

} // namespace markup_text

} // namespace widgets

} // namespace tuipp
