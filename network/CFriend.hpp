#pragma once
#include <cstdint>

class CFriend
{
public:
    std::uint64_t m_RockstarId;
    char m_Pad[0x8];
    char m_Name[24];
};