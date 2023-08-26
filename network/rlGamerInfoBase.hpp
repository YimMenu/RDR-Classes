#pragma once
#include <cstdint>
#include "rlGamerHandle.hpp"

#pragma pack(push, 8)
namespace rage
{
    class rlGamerInfoBase
	{
		uint64_t m_PeerId;
		rage::rlGamerHandle m_GamerHandle;
		char m_AesKey[33];
		netAddress m_InternalAddress;
		uint16_t m_InternalPort;
		netAddress m_UnkAddress;
		uint16_t m_UnkPort;
		netAddress m_ExternalAddress;
		uint16_t m_ExternalPort;
		netAddress m_RelayAddress;
		uint16_t m_RelayPort;
		char gap5A[54]; // TODO: reverse this
		uint32_t m_RelayState;
	};
	static_assert(sizeof(rage::rlGamerInfoBase) == 0x98);
}
#pragma pack(pop)