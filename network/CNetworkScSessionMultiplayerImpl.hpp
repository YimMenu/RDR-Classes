#pragma once
#include <cstdint>
#include "rage/atPlayerBits.hpp"
#include "CNetworkScObjMgr.hpp"
#include "CNetworkScSessionPlayer.hpp"
#include "rlGamerHandle.hpp"

class CNetworkScSession;

namespace rage
{
	class rlScSessionVolumeLockData
	{
	public:
		virtual ~rlScSessionVolumeLockData() = default;

		char m_Pad[56];
	};
}

class CNetworkScVolumeLocksImpl
{
public:
	virtual ~CNetworkScVolumeLocksImpl() = default;

	char m_Pad[8];
	rage::rlScSessionVolumeLockData m_Data[128];
};
static_assert(sizeof(CNetworkScVolumeLocksImpl) == 0x2010);

class CNetworkPopulationResetMgr
{
public:
	char pad[0x28];
	rage::atPlayerBits m_PlayersInScope;
	uint32_t dword2C;
	rage::atPlayerBits m_PlayersReady;
	uint32_t gap34;
	uint32_t dword38;
	rage::atPlayerBits m_PlayersFinished;
	rage::atPlayerBits m_TimedOutPlayers;
};

class CNetworkScSessionMultiplayerImpl
{
public:
	virtual ~CNetworkScSessionMultiplayerImpl() = default;

	rage::rlScSessionMultiplayer* m_SessionOwner;
	CNetworkScSession* m_NetworkSession;
	void* m_NetLog;
	uint32_t m_SessionState;
	int m_SessionEnterTime;
	char pad1[0x10];
	char m_TerminatePopulationReset;
	CNetworkScSessionPlayer* m_Players[32];
	CNetworkScObjMgr m_ObjectMgr;
	int m_LastTimeCheckedPeerComplaints[32];
	uint32_t m_MergeId;
	uint32_t dword2F4;
	uint64_t qword2F8;
	rage::atPlayerBits m_PendingInitializationPlayers;
	rage::atPlayerBits dword304;
	rage::atPlayerBits dword308;
	rage::atPlayerBits m_PlayersReadyForGameSync;
	rage::atPlayerBits m_PlayersAckedReadyForGameSync;
	char gap315[12];
	CNetworkScVolumeLocksImpl m_VolumeLocks;
	char m_AutoSession[0xA8]; // CAutoSession
	CNetworkPopulationResetMgr m_PopulationResetMgr;
	uint64_t qword2420;
	char m_GangManager[0x3070]; // CScGangManager
	char pad2[0x30];
	char m_ScriptShuttingDownForMerge;
	uint32_t m_ScriptShutdownMergeId;
	rage::atPlayerBits m_PlayersReadyForScriptShutdown;
	char pad3[0x20];
	int m_LastJoinConfirmUpdateTime;
	int m_LastSessionChangeEventTime;
	uint64_t qword54FC;
	uint32_t dword5504;

	inline CNetworkScSessionPlayer* GetPlayerByHandle(const rage::rlGamerHandle& handle)
	{
		for (int i = 0; i < 32; i++)
		{
			if (m_Players[i] && m_Players[i]->m_GamerInfo.m_GamerHandle2 == handle)
				return m_Players[i];
		}

		return nullptr;
	}

	inline CNetworkScSessionPlayer* GetPlayerByIndex(int index)
	{
		return m_Players[index]; // this works?
	}
};
static_assert(sizeof(CNetworkScSessionMultiplayerImpl) == 0x5510);