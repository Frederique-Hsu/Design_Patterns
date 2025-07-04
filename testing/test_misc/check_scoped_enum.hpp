/*!
 *  \file       check_scoped_enum.hpp
 *  \brief
 *
 */


#pragma once


#include <cstdint>

namespace details
{
    enum class EndiannessType : std::uint8_t
    {
        SEP_LITTLE_ENDIAN = 0,
        SEP_BIG_ENDIAN = 1
    };

    static constexpr int SEP_READER_MAX_DIMENSION = 32u;
}
