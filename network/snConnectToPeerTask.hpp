#pragma once
#include <cstdint>

namespace rage
{
#pragma pack(push, 8)
	class snConnectToPeerTaskData
	{
	public:
		int m_Unk;
		int m_Reason;
		uint64_t m_SessionToken;
		char m_Flags;
	};
	static_assert(sizeof(rage::snConnectToPeerTaskData) == 0x18);
#pragma pack(pop)

	class snConnectToPeerTaskResult
	{
	public:
		char pad[0x10]{};
		int m_PeerId;
		char pad2[0x34C]{};
	};
	static_assert(sizeof(snConnectToPeerTaskResult) == 0x360);
}