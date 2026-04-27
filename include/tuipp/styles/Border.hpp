#pragma once

#include <string>

#include "../../../src/tuipp/borders/BorderParts.hpp"
#include "tuipp/private/macros.hpp"

namespace tuipp {

namespace styles {

namespace border {

enum class BorderType
{
    NONE,
    ASCII,
    DOUBLE,
    HEAVY,
    ROUNDED,
    SQUARE,
};

TUIPP_NODISCARD std::string
get_part_from_border_type(BorderType type, BorderParts part);

struct None
{
    TUIPP_NODISCARD static std::string get_part(BorderParts part);
};

struct Ascii
{
    TUIPP_NODISCARD static std::string get_part(BorderParts part);
};

struct Double
{
    TUIPP_NODISCARD static std::string get_part(BorderParts part);
};

struct Heavy
{
    TUIPP_NODISCARD static std::string get_part(BorderParts part);
};

struct Rounded
{
    TUIPP_NODISCARD static std::string get_part(BorderParts part);
};

struct Square
{
    TUIPP_NODISCARD static std::string get_part(BorderParts part);
};

} // namespace border

} // namespace styles

} // namespace tuipp
