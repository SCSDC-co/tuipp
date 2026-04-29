#include "../../../include/tuipp/styles/Border.hpp"

#include <string>

#include "BorderParts.hpp"

namespace tuipp {

namespace styles {

namespace border {

TUIPP_NODISCARD std::string
get_part_from_border_type(BorderType type, BorderParts part)
{
    switch (type) {
        case BorderType::NONE:
            return None::get_part(part);
        case BorderType::ASCII:
            return Ascii::get_part(part);
        case BorderType::DOUBLE:
            return Double::get_part(part);
        case BorderType::HEAVY:
            return Heavy::get_part(part);
        case BorderType::ROUNDED:
            return Rounded::get_part(part);
        case BorderType::SQUARE:
            return Square::get_part(part);
    }

    return "";
}

TUIPP_NODISCARD std::string
None::get_part(BorderParts part)
{
    switch (part) {
        case BorderParts::TOP_LEFT:
            return " ";
        case BorderParts::TOP:
            return " ";
        case BorderParts::TOP_RIGHT:
            return " ";
        case BorderParts::LEFT:
            return " ";
        case BorderParts::RIGHT:
            return " ";
        case BorderParts::BOTTOM_LEFT:
            return " ";
        case BorderParts::BOTTOM:
            return " ";
        case BorderParts::BOTTOM_RIGHT:
            return " ";
    }

    return "";
}

TUIPP_NODISCARD std::string
Ascii::get_part(BorderParts part)
{
    switch (part) {
        case BorderParts::TOP_LEFT:
            return "+";
        case BorderParts::TOP:
            return "-";
        case BorderParts::TOP_RIGHT:
            return "+";
        case BorderParts::LEFT:
            return "|";
        case BorderParts::RIGHT:
            return "|";
        case BorderParts::BOTTOM_LEFT:
            return "+";
        case BorderParts::BOTTOM:
            return "-";
        case BorderParts::BOTTOM_RIGHT:
            return "+";
    }

    return "";
}

TUIPP_NODISCARD std::string
Double::get_part(BorderParts part)
{
    switch (part) {
        case BorderParts::TOP_LEFT:
            return "╔";
        case BorderParts::TOP:
            return "═";
        case BorderParts::TOP_RIGHT:
            return "╗";
        case BorderParts::LEFT:
            return "║";
        case BorderParts::RIGHT:
            return "║";
        case BorderParts::BOTTOM_LEFT:
            return "╚";
        case BorderParts::BOTTOM:
            return "═";
        case BorderParts::BOTTOM_RIGHT:
            return "╝";
    }

    return "";
}

TUIPP_NODISCARD std::string
Heavy::get_part(BorderParts part)
{
    switch (part) {
        case BorderParts::TOP_LEFT:
            return "┏";
        case BorderParts::TOP:
            return "━";
        case BorderParts::TOP_RIGHT:
            return "┓";
        case BorderParts::LEFT:
            return "┃";
        case BorderParts::RIGHT:
            return "┃";
        case BorderParts::BOTTOM_LEFT:
            return "┗";
        case BorderParts::BOTTOM:
            return "━";
        case BorderParts::BOTTOM_RIGHT:
            return "┛";
    }

    return "";
}

TUIPP_NODISCARD std::string
Rounded::get_part(BorderParts part)
{
    switch (part) {
        case BorderParts::TOP_LEFT:
            return "╭";
        case BorderParts::TOP:
            return "─";
        case BorderParts::TOP_RIGHT:
            return "╮";
        case BorderParts::LEFT:
            return "│";
        case BorderParts::RIGHT:
            return "│";
        case BorderParts::BOTTOM_LEFT:
            return "╰";
        case BorderParts::BOTTOM:
            return "─";
        case BorderParts::BOTTOM_RIGHT:
            return "╯";
    }

    return "";
}

TUIPP_NODISCARD std::string
Square::get_part(BorderParts part)
{
    switch (part) {
        case BorderParts::TOP_LEFT:
            return "┌";
        case BorderParts::TOP:
            return "─";
        case BorderParts::TOP_RIGHT:
            return "┐";
        case BorderParts::LEFT:
            return "│";
        case BorderParts::RIGHT:
            return "│";
        case BorderParts::BOTTOM_LEFT:
            return "└";
        case BorderParts::BOTTOM:
            return "─";
        case BorderParts::BOTTOM_RIGHT:
            return "┘";
    }

    return "";
}

} // namespace border

} // namespace styles

} // namespace tuipp
