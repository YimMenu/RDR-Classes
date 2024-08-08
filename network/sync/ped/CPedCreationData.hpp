#pragma once
#include <cstdint>

// TODO, CPedBaseCreationData
class CPedCreationData
{
public:
	char pad_0000[4]; //0x0000
	uint32_t m_PopulationType; //0x0004
	uint32_t m_ModelHash; //0x0008
	char pad_000C[18]; //0x000C
	bool m_BannedPed; //0x001E
	char pad_001F[13]; //0x001F
}; //Size: 0x002C
static_assert(sizeof(CPedCreationData) == 0x2C);