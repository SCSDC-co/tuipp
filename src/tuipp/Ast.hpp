#pragma once

#include <memory>
#include <vector>

#include "handle_styles.hpp"

namespace tuipp {

struct Node
{
    std::vector<tuipp::Style> styles{};

    std::string content{};

    std::vector<std::unique_ptr<tuipp::Node>> children{};
};

struct Ast
{
    std::vector<std::unique_ptr<tuipp::Node>> children{};
};

} // namespace tuipp
