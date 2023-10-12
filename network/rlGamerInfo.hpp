#pragma once
#include <cstdint>
#include "rlGamerInfoBase.hpp"

#pragma pack(push, 8)
namespace rage
{
	class rlGamerInfo : public rage::rlGamerInfoBase
	{
	public:
		uint64_t m_HostToken;
		uint64_t m_PeerId2;
		rage::rlGamerHandle m_GamerHandle2;
		uint32_t m_ProfileIndex;
		char m_Name[21];
		uint8_t m_Flags;
	};
	static_assert(sizeof(rage::rlGamerInfo) == 0xD8);
}
#pragma pack(pop)