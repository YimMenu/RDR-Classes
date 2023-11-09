#pragma once
#include <cstdint>

#pragma pack(push, 8)
class CPlayerHealthData
{
public:
	uint32_t m_Unused; //0x0000
	bool m_BulletProof; //0x0004
	bool m_FlameProof; //0x0005
	bool m_ExplosionProof; //0x0006
	bool m_CollisionProof; //0x0007
	bool m_MeleeProof; //0x0008
	bool m_SmokeProof; //0x0009
	bool m_SteamProof; //0x000A
	bool m_Godmode; //0x000B
private:
	char m_Pad[4];
}; //Size: 0x0010
static_assert(sizeof(CPlayerHealthData) == 0x10);
#pragma pack(pop)