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
	NodeCommonDataOperations m_CommonDataOperations; // 0xB0 this is generally invalidated by MoveCommonDataOpsVFT()
};
static_assert(sizeof(CProjectBaseSyncDataNode) == 0x130);

class CSyncDataNodeFrequent : public CProjectBaseSyncDataNode {};
class CSyncDataNodeInfrequent : public CProjectBaseSyncDataNode {};