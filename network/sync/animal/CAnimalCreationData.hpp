#pragma once
#include <cstdint>

// TODO, CPedBaseCreationData
class CAnimalCreationData
{
public:
	char pad_0000[4]; //0x0000
	uint32_t m_PopulationType; //0x0004
	uint32_t m_ModelHash; //0x0008
	char pad_000C[18]; //0x000C
	bool m_BannedPed; //0x001E
	char pad_001F[5]; //0x001F
}; //Size: 0x0024
static_assert(sizeof(CAnimalCreationData) == 0x24);