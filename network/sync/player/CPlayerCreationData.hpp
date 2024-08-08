#pragma once
#include <cstdint>

class CPlayerCreationData
{
public:
	uint32_t m_Hash; // 0x0000
	char m_Pad[20];  // 0x0004
}; //Size: 0x18
static_assert(sizeof(CPlayerCreationData) == 0x18);