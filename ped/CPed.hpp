#pragma once
#include "physical/CPhysical.hpp"

class CPed : public CPhysical
{
	char m_Pad6[0x18]; // 0x0368
};
static_assert(sizeof(CPed) == 0x380);