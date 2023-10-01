#pragma once

#include "netSyncNodeBase.hpp"
#include "rage/tlsContext.hpp"

namespace rage
{
#pragma pack(push, 8)
    class netSyncDataNode : public netSyncNodeBase
    {
        struct ThreadData
        {
            bool m_Unk;
            bool m_NodeActive;
        };
        static_assert(sizeof(ThreadData) == 2);

    public:
        uint32_t m_Flags;                   // 0x40
        uint32_t pad3;                      // 0x44
        uint64_t pad4;                      // 0x48
        netSyncDataNode* m_ParentData;      // 0x50
        uint32_t m_MoreFlags;               // 0x58
        netSyncDataNode* m_Children[19];    // 0x60
        ThreadData m_ThreadData[8];         // 0xF8
        char pad5[10];                      // 0x110
        void* m_CommonDataOpsVFT;           // 0x118

#if _WIN32
        inline bool IsActive()
        {
            return m_ThreadData[rage::tlsContext::Get()->m_SyncThreadIndex].m_NodeActive;
        }
#endif
    };
    static_assert(sizeof(netSyncDataNode) == 0x120);
#pragma pack(pop)
}