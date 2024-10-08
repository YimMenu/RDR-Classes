#pragma once
#include <cstdint>

class CObject;
namespace rage
{
    class netObject
    {
    public:
#pragma pack(push, 1)
        struct GUID
        {
            std::uint64_t m_Data1;
            std::uint64_t m_Data2;

            std::uint32_t GetAccountId() const
            {
                return m_Data2 & 0xFFFFFFFF;
            }

            std::uint16_t GetAccountComponent() const
            {
                return (m_Data2 >> 32) & 0xFFFF;
            }

            std::uint64_t GetCreationTime() const
            {
                return m_Data1 & 0xFFFFFFFFFFFF;
            }

            std::uint16_t GetObjectToken() const
            {
                return m_Data1 >> 48;
            }

            std::uint16_t GetObjectType() const
            {
                return (m_Data2 >> 48) & 0xFF;
            }

            std::uint8_t GetCreationCycle() const
            {
                return m_Data2 >> 56;
            }
        };
#pragma pack(pop)

        virtual ~netObject() = 0;

        char m_Pad[0x38];              // 0x08
        uint16_t m_ObjectType;         // 0x40
        uint16_t m_ObjectId;           // 0x42
        uint8_t m_Unk;                 // 0x44
        uint8_t m_OwnerId;             // 0x45
        uint8_t m_MigratingOwnerId;    // 0x46
        bool m_IsRemotelyControlled;   // 0x47
        char m_Pad2[0xA8];             // 0x48
        int m_OwnershipToken;          // 0xF0
        char m_Pad3[0x14];             // 0xF4
        GUID m_Guid;                   // 0x108
    };
    static_assert(sizeof(rage::netObject) == 0x118);
}