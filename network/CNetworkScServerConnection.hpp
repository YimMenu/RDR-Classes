#pragma once
#include "rlScSessionManagerImpl.hpp"

class CNetworkScServerConnection
{
public:
	virtual ~CNetworkScServerConnection() = default;

	char m_Pad[0x78];
	rage::rlScSessionManagerImpl m_SessionManager;
	int dwordBB58;
	rage::rlScSessionId m_CurrentSessionId;
	std::uint64_t qwordBB70[2];

	inline rage::rlScSession* GetCurrentSession()
	{
		auto& list = m_SessionManager.m_SessionPool;
		for (auto entry = list.m_First; entry; entry = entry->m_Next)
		{
			if (entry->m_Session.m_SessionId == m_CurrentSessionId)
				return &entry->m_Session;
		}

		return nullptr;
	}
};
static_assert(sizeof(CNetworkScServerConnection) == 0xBB80);