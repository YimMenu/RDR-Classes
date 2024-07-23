#pragma once
#include <cstdint>
#include "../base/fwExtensibleBase.hpp"

class CMoveObjectPooledObject;
class CNavigation;
class CBaseModelInfo;

namespace rage
{
    class fwDrawData;
    class fwDynamicEntityComponent;
    class crmtRequestPose;
    class crmtRequestIk;
    class crFrameFilter;
    class fwAudEntity;
    class netObject;
    class fwEntity : public fwExtensibleBase
    {
    public:
        class CBaseModelInfo* m_ModelInfo;  // 0x0020
        void* m_Unk;                        // 0x0028
        uint8_t m_EntityType;               // 0x0030
        char m_Pad1[0x64];                  // 0x0038
        uint32_t m_EntityPoolSlot;          // 0x009C
        char m_Pad2[0x40];                  // 0x00A0
        // TODO: move these out of rage::fwEntity
        class rage::netObject* m_NetObject; // 0x00E0

        uint32_t GetEntityPoolSlot()
        {
            return (m_EntityPoolSlot & 0x1FFFFu);
        }
    };
    static_assert(sizeof(fwEntity) == 0xE8);
}
