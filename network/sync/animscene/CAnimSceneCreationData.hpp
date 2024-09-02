#pragma once
#include <cstdint>

class CAnimSceneCreationData
{
public:
    uint32_t m_AnimDict;        // 0x0000
    int32_t m_PlaybackListName; // 0x0004
    uint32_t m_Flags;           // 0x0008 - TODO: fix this
    char m_Pad[116];            // 0x0012
}; //Size: 0x0080
static_assert(sizeof(CAnimSceneCreationData) == 0x80);