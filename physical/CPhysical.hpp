#pragma once
#include "entity/CDynamicEntity.hpp"

class CPhysical : public CDynamicEntity
{
public:
	char m_Pad5[0x1B8]; // 0x01B0
};
static_assert(sizeof(CPhysical) == 0x368);