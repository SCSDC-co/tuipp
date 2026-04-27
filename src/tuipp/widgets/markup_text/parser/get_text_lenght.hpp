#pragma once

#include <string>

namespace tuipp {

namespace widgets {

namespace markup_text {

inline int
get_text_lenght(const std::string& string)
{
    int lenght{ 0 };

    char prev_char{};

    for (std::size_t i = 0; i < string.size(); ++i) {
        char current_char{ string[i] };
        char next_char{ string[i + 1] };

        if (current_char == '[' && prev_char != '[' && next_char != '[') {
            while (current_char != ']') {
                ++i;

                current_char = string[i];
            }
        } else {
            // it will print "[[" without this
            if (current_char == '[' && (next_char == '[' || prev_char == '[')) {
                ++i;
            } else if (current_char == ']' && (next_char == ']' || prev_char == ']')) {
                ++i;
            }

            ++lenght;
        }

        prev_char = current_char;
    }

    return lenght;
}

} // namespace markup_text

} // namespace widgets

} // namespace tuipp
