#pragma once
#include <cstdint>

class CPropSetCreationData
{
public:
	char m_Pad[16];   // 0x0000
	uint32_t m_Hash;  // 0x0010
	char m_Pad1[8];   // 0x0014
	int32_t m_Type;   // 0x001C
	char m_Pad2[544]; // 0x0020
}; //Size: 0x240
static_assert(sizeof(CPropSetCreationData) == 0x240);