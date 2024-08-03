#pragma once
#include "entity/fwEntity.hpp"

class CEntity : public rage::fwEntity
{
public:
	char m_Pad2[0x30]; // 0xB0
};
static_assert(sizeof(CEntity) == 0xE0);