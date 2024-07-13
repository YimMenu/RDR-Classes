#pragma once
#include "rlGamerInfo.hpp"

class CNetGamePlayer;

namespace rage
{
	class rlScSessionPeer;
}

class CNetworkScSessionPlayer
{
public:
	CNetworkScSessionMultiplayerImpl* m_MultiplayerSession;
	rage::rlScSessionPeer* m_SessionPeer;
	char m_PlayerIndex;
	rage::rlGamerInfo m_GamerInfo;
	rage::rlGamerInfoBase m_PeerAddr;
	char m_NetPlayerData[224]; // CNetGamePlayerDataMsg
	bool m_HasGamerInfo;
	char m_GamerInfoUpdated;
	int m_ComplainedReasons;
	int m_ComplaintUnkReason;
	int m_TimeoutReason;
	char m_ComplaintData[224];
	bool m_HasOurGamerInfo;
	bool m_Initialized;
	CNetGamePlayer* m_NetGamePlayer;
	int m_NameProfanityCheckId;
	char m_NameProfanityCheckComplete;
};
static_assert(sizeof(CNetworkScSessionPlayer) == 0x370);