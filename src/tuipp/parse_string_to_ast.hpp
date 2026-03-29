#pragma once

#include <cstddef>

#include "Ast.hpp"
#include "tuipp/private/macros.hpp"

namespace tuipp {

TUIPP_NODISCARD inline Ast
parse_string_to_ast(const std::string& string)
{
    Ast ast{};

    char prev_char{};
    std::string buffer{};

    for (std::size_t i = 0; i < string.size(); ++i) {
    }

    return ast;
}

} // namespace tuipp
