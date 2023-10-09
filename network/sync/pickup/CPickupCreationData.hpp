#pragma once
#include <cstdint>

class CPickupCreationData
{
public:
	char pad_0000[68]; //0x0000
	uint32_t m_PickupHash; //0x0044
	uint32_t m_ModelHash; //0x0048
	char pad_004C[236]; //0x004C
}; //Size: 0x0138
static_assert(sizeof(CPickupCreationData) == 0x138);