#pragma once
#include "netSyncDataNode.hpp"
#include "NodeCommonDataOperations.hpp"

namespace rage
{
	class netSyncData;
	class netObject;
}

class CProjectBaseSyncDataNode : public rage::netSyncDataNode
{
private:
	NodeCommonDataOperations m_CommonDataOperations; // 0x120
	char m_Data[];                                   // 0x130

public:
#if _WIN32
	template<typename T>
	T& GetData()
	{
		return *reinterpret_cast<T*>(&m_Data[rage::tlsContext::Get()->m_SyncThreadIndex * sizeof(T)]);
	}
#endif
};
static_assert(sizeof(CProjectBaseSyncDataNode) == 0x130);

// We probably don't need these anymore
//class CSyncDataNodeFrequent : public CProjectBaseSyncDataNode {};
//class CSyncDataNodeInfrequent : public CProjectBaseSyncDataNode {};