#pragma once
#include <cstdint>
#include "../base/fwExtensibleBase.hpp"
#include "rage/vector.hpp"

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
        char m_Pad1[0x38];                  // 0x0038
        rage::vector3 m_Position;           // 0x0070
        char m_Pad0080[0x1C];               // 0x0080   
        uint32_t m_ComponentIndex;          // 0x009C
        char m_Pad2[0x10];                  // 0x00A0

        uint32_t GetComponentIndex() const
        {
            return (m_ComponentIndex & 0x1FFFFu);
        }
    };
    static_assert(sizeof(fwEntity) == 0xB0);
}
