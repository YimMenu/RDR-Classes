#pragma once

#include <cstdint>

namespace rage
{
    class datBitBuffer;

#pragma pack(push,8)
    class rlGamerHandle
    {
    public:
        uint64_t m_RockstarId; // 0x00
        uint16_t m_UnkData;    // 0x08
        uint8_t m_Platform;    // 0x0A

        inline rlGamerHandle() = default;

        inline rlGamerHandle(uint64_t rockstar_id) :
            m_RockstarId(rockstar_id),
            m_Platform(3),
            m_UnkData(0)
        {
        }

        bool Serialize(rage::datBitBuffer& buf) const;
        bool Deserialize(rage::datBitBuffer& buf);
    }; //Size: 0x0010
    static_assert(sizeof(rlGamerHandle) == 0x10);
#pragma pack(pop)
}