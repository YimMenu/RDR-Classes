#pragma once
#include "netPlayer.hpp"

class CPlayerInfo;
class CNetGamePlayer : public rage::netPlayer
{
public:
	CPlayerInfo* m_PlayerInfo; //0x0128
	char pad_0130[2432]; //0x0130
}; //Size: 0x0AB0
static_assert(sizeof(CNetGamePlayer) == 0xAB0);