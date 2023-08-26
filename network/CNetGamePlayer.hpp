#pragma once
#include "netPlayer.hpp"

class CNetGamePlayer : public rage::netPlayer
{
public:
	char pad_0128[2440]; //0x0128
}; //Size: 0x0AB0
static_assert(sizeof(CNetGamePlayer) == 0xAB0);