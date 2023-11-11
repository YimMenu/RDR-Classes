#pragma once
#include <cstdint>

class CPedAttachData
{
public:
	char pad_0000[32]; //0x0000
	uint16_t m_AttachObjectId; //0x0020
	char pad_0022[15]; //0x0022
	bool m_IsAttached; //0x0031
	char pad_0032[14]; //0x0032
}; //Size: 0x0040
static_assert(sizeof(CPedAttachData) == 0x40);