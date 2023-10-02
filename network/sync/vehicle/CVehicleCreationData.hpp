#pragma once
#include <cstdint>

class CVehicleCreationData
{
public:
	char pad_0000[4]; //0x0000
	uint32_t m_PopulationType; //0x0004
	char pad_0008[4]; //0x0008
	uint32_t m_ModelHash; //0x000C
	char pad_0010[24]; //0x0010
}; //Size: 0x0028
static_assert(sizeof(CVehicleCreationData) == 0x28);