#pragma once
#include <cstdint>
#include "rage/vector.hpp"

#pragma pack(push, 8)
class CPlayerCameraUncommonData
{
public:
	rage::vector3 m_UnkCameraOffset; // 0x0
	char m_Pad[8];                   // 0x10
	bool m_IsSpectating;             // 0x18
private:
	char m_Pad2[7];                   // 0x19
}; //Size: 0x0010
static_assert(sizeof(CPlayerCameraUncommonData) == 0x20);
#pragma pack(pop)