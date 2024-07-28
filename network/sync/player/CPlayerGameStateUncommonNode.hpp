#pragma once
#include <cstdint>
#include "rage/vector.hpp"

#pragma pack(push, 8)
class CPlayerGameStateUncommonNode
{
private:
	char m_Pad[0x78];
public:
	std::uint16_t m_SpectatorId;             // 0x78
	alignas(8) rage::vector3 m_SpectatePos;  // 0x80
private:
	char m_Pad2[0x4];                        // 0x90
public:
	bool m_IsSpectating;                     // 0x94
	bool m_IsSpectatingStaticPos;            // 0x95
private:
	char m_Pad3[0xA];                        // 0x96
}; //Size: 0x0010
constexpr int a = offsetof(CPlayerGameStateUncommonNode, CPlayerGameStateUncommonNode::m_SpectatePos);
static_assert(sizeof(CPlayerGameStateUncommonNode) == 0xA0);
#pragma pack(pop)