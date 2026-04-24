#pragma once

#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>

#include "handle_styles.hpp"

namespace tuipp {

template<typename CharT>
std::basic_ostream<CharT>&
parse_string(std::basic_ostream<CharT>& stream, const std::string& string)
{
    char prev_char{};

    for (std::size_t i = 0; i < string.size(); ++i) {
        char current_char{ string[i] };
        char next_char{ string[i + 1] };

        if (current_char == '[' && prev_char != '\\') {
            std::string buffer{};

            while (current_char != ']') {
                ++i;

                current_char = string[i];

                buffer += current_char;
            }

            // this removes the ']' at the end of the buffer
            buffer.pop_back();

            handle_styles(stream, buffer);
        } else {
            // it will print "\[" without this
            if (current_char == '\\' && next_char == '[') {
                stream << '[';

                ++i;
            } else {
                stream << current_char;
            }
        }

        prev_char = current_char;
    }

    return stream;
}

} // namespace tuipp
