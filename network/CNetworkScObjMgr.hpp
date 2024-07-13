#pragma once
#include <cstdint>
#include "rage/atPlayerBits.hpp"

class CNetworkScObjMgr
{
public:
	virtual ~CNetworkScObjMgr() = default;

	char pad[20];
	std::uint32_t m_State;
	rage::atPlayerBits m_PlayersInScope;
	rage::atPlayerBits m_TimedOutPlayers;
	rage::atPlayerBits m_PlayersReadyForIdRemap;
	rage::atPlayerBits m_PlayersDistributedObjects;
	rage::atPlayerBits m_PlayersAckedFinalDistributeObjects;
	rage::atPlayerBits m_PlayersReadyForObjectRemap;
	rage::atPlayerBits m_PlayersCompletedDistributingObjects;
	rage::atPlayerBits m_PlayersReadyToRestartObjectRemap;
	char pad40[240];
};
static_assert(sizeof(CNetworkScObjMgr) == 0x130);