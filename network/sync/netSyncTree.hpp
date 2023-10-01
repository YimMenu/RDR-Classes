#pragma once

#include "netSyncNodeBase.hpp"

namespace rage
{
#pragma pack(push, 8)
	class netSyncTree
	{
	public:
		char pad_0000[176]; //0x0000
		netSyncNodeBase* m_NextSyncNode; //0x00B0
		netSyncNodeBase* m_LastSyncNode; //0x00B8
		uint32_t m_NodeCount; //0x00C0
		uint32_t m_SyncNodeCount; //0x00C4
		char pad_00C8[24]; //0x00C8
		netSyncNodeBase* m_Nodes[74]; //0x00E0
		uint32_t m_NodeMaxCount; //0x0330
		netSyncNodeBase* m_SyncNodes[64]; //0x0338
		uint32_t m_SyncNodeMaxCount; //0x0538
		char pad_053C[900]; //0x053C
	}; //Size: 0x08C0
	static_assert(sizeof(rage::netSyncTree) == 0x8C0);
#pragma pack(pop)
}