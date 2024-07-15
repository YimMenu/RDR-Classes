#pragma once
#include "rlScSessionMultiplayer.hpp"
#include "CNetworkScSessionMultiplayerImpl.hpp"
#include "CNetworkScServerConnection.hpp"

class CNetworkScSession
{
public:
	rage::rlScSessionMultiplayer* m_RlineSession;
	CNetworkScSessionMultiplayerImpl* m_SessionMultiplayer;
	void* m_NetLog;
	bool m_Initialized;
};
static_assert(sizeof(CNetworkScSession) == 0x20);