#pragma once
#include <cstdint>

class CNetGamePlayer;
class CNetGamePlayerDataMsg;
class CNonPhysicalPlayerData;

namespace rage
{
	class rlGamerInfo;
	class netConnectionManager;
#pragma pack(push, 8)
	// the same as GTA 1.63
	class netPlayerMgrBase
	{
	public:
		virtual ~netPlayerMgrBase() = default;
		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;
		virtual void unk_0x18() = 0;
		virtual CNetGamePlayer* AddPlayer_raw(rage::rlGamerInfo* gamer_info, uint32_t a2, CNetGamePlayerDataMsg* player_data, CNonPhysicalPlayerData* non_physical_player_data) = 0;
		virtual void RemovePlayer(CNetGamePlayer* net_game_player) = 0;
		virtual void UpdatePlayerListsForPlayer(CNetGamePlayer* net_game_player) = 0;
		virtual CNetGamePlayer* AddPlayer(rage::rlGamerInfo* gamer_info, uint32_t a3, CNetGamePlayerDataMsg* player_data, CNonPhysicalPlayerData* non_physical_player_data) = 0;

		rage::netConnectionManager* m_NetConnectionManager; //0x0008
		uint64_t* m_NetBandwidthManager; //0x0010
		char pad_0018[208]; //0x0018
		CNetGamePlayer* m_LocalPlayer; //0x00E8
		char pad_00F0[144]; //0x00F0
		CNetGamePlayer* m_PlayerList[32]; //0x0180 (TODO: is this used?)
		uint16_t m_PlayerLimit; //0x0280
		char pad_0282[10]; //0x0282
		uint16_t m_PlayerCount; //0x028C
		char pad_0290[1618]; //0x0290
	}; //Size: 0x08E0
	static_assert(sizeof(netPlayerMgrBase) == 0x8E0);
#pragma pack(pop)
}