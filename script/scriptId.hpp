#pragma once
#include "scriptIdBase.hpp"

#pragma pack(push, 8)
namespace rage
{
    class scriptId : public scriptIdBase
    {
    public:
        joaat_t m_ScriptHash;           // 0x08
    };
    static_assert(sizeof(scriptId) == 0x10);
}

class CGameScriptId : public rage::scriptId
{
public:
    int m_Timestamp;                // 0x10 (verify)
    int m_ObjectBrainPositionHash;  // 0x14
    union
    {
        int m_PedBrainObjectId;     // 0x18
        int m_WorldPointBrainIndex; // 0x18
        int m_FallbackId;           // 0x18
    };
    int m_InstanceHash;             // 0x1C (derived from brain parameters)
    bool m_IsPedBrainScript;        // 0x20
};

static_assert(sizeof(CGameScriptId) == 0x28);
#pragma pack(pop)