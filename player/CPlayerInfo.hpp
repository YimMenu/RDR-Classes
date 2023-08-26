#pragma once
#include "../network/rlGamerInfo.hpp"

class CPlayerInfo
{
public:
	char pad_0000[336]; //0x0000
	rage::rlGamerInfo m_GamerInfo; //0x0150
	char pad_0158[4000]; //0x0228
	void* m_Ped; //0x11C8
	char pad_11D0[3640]; //0x11D0
}; //Size: 0x2008
static_assert(sizeof(CPlayerInfo) == 0x2008);