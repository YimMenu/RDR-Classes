#pragma once
#include "netPlayerMgrBase.hpp"
#include "CNetGamePlayer.hpp"

#include <cstdint>
#pragma pack(push, 8)
class CNetworkPlayerMgr : public rage::netPlayerMgrBase
{
public:
	CNetGamePlayer m_PlayerStorage[32]; // 0x08E0
	CNetGamePlayer* m_FirstPlayer;      // 0x15EE0
	CNetGamePlayer* m_LastPlayer;       // 0x15EE8
	std::uint64_t m_UnkCounter;         // 0x15EF0
};
static_assert(sizeof(CNetworkPlayerMgr) == 0x15EF8);
#pragma pack(pop)