#pragma once

#include <cstdint>
#include <string_view>

namespace rage
{
    using joaat_t = std::uint32_t;
    inline constexpr char JoaatToLower(char c)
    {
        return c >= 'A' && c <= 'Z' ? c | 1 << 5 : c;
    }

    inline constexpr joaat_t Joaat(const std::string_view str)
    {
        joaat_t hash = 0;
        for (auto c : str)
        {
            hash += JoaatToLower(c);
            hash += (hash << 10);
            hash ^= (hash >> 6);
        }
        hash += (hash << 3);
        hash ^= (hash >> 11);
        hash += (hash << 15);
        return hash;
    }
};