#pragma once
#include <cstdint>

// TODO
class CObjectCreationData
{
public:
	char pad_0000[284]; //0x0000
	uint32_t m_ObjectType; //0x011C
	uint32_t m_ModelHash; //0x0120
	char pad_0124[76]; //0x0124
}; //Size: 0x0170
static_assert(sizeof(CObjectCreationData) == 0x170);