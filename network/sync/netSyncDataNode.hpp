#pragma once

#include "netSyncNodeBase.hpp"

namespace rage
{
#pragma pack(push, 8)
    class netSyncDataNode : public netSyncNodeBase
    {
    public:
        uint32_t m_Flags;                // 0x40
        uint32_t pad3;                   // 0x44
        uint64_t pad4;                   // 0x48
        netSyncDataNode* m_ParentData;   // 0x50
        uint32_t m_MoreFlags;            // 0x58
        netSyncDataNode* m_Children[19]; // 0x60
        uint8_t m_SyncFrequencies[19];   // 0xF8
        char pad5[8];                    // 0x110
        void* m_CommonDataOpsVFT;        // 0x118
    };
    static_assert(sizeof(netSyncDataNode) == 0x120);
#pragma pack(pop)
}