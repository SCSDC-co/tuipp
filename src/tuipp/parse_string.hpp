#pragma once

#include <cstddef>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "handle_styles.hpp"
#include "vendor/termcolor.hpp"

namespace tuipp {

enum class State
{
    TEXT,
    TAG
};

template<typename CharT>
std::basic_ostream<CharT>&
parse_string(std::basic_ostream<CharT>& stream, const std::string& string)
{
    State state{ State::TEXT };

    std::string buffer{};

    std::vector<Style> styles{};

    char prev_char{};

    for (std::size_t i = 0; i < string.size(); ++i) {
        char current_char{ string[i] };
        char next_char{ string[i + 1] };

        switch (state) {
            case State::TEXT: {
                if (current_char == '[' && prev_char != '\\') {
                    state = State::TAG;

                    buffer.clear();
                } else {
                    // this will print just '[' instead of '\['
                    if (!(current_char == '\\' && i + 1 < string.size() && next_char == '[')) {
                        stream << current_char;
                    }
                }

                break;
            }
            case State::TAG: {
                if (current_char == ']') {
                    state = State::TEXT;

                    try {
                        handle_styles(stream, buffer, styles);
                    } catch (const std::invalid_argument& e) {
                        std::cerr << std::endl << "[WARNING] " << e.what() << std::endl;
                    }
                } else {
                    buffer += current_char;
                }

                break;
            }
        }

        prev_char = current_char;
    }

    stream << termcolor::reset;

    return stream;
}

} // namespace tuipp
