#pragma once
#include <cstdint>
#include "netPeerAddress.hpp"

namespace rage 
{
    class netConnection
    {
    public:
#pragma pack(push, 8)
        class InFrame
        {
        public:
            enum class EventType
            {
                ConnectionClosed = 4,
                FrameReceived = 5,
                BandwidthExceeded = 6,
                OutOfMemory = 7
            };

            virtual ~InFrame() = default;

            virtual void Destroy() = 0;
            virtual EventType GetEventType() = 0;
            virtual uint32_t _0x18() = 0;

            char pad_0[0x38];         // 0x8
            InFrame* m_This;          // 0x40
            int m_MsgId;              // 0x48
            char m_Unk;               // 0x4C
            int m_ConnectionId;       // 0x50
            netPeerAddress m_Address; // 0x58
            uint32_t m_Length;        // 0x78
            void* m_Data;             // 0x80
        };
        static_assert(sizeof(InFrame) == 0x88);
    };
#pragma pack(pop)
}