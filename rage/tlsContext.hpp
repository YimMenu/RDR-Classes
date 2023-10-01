#pragma once

#if _WIN32
#include <intrin.h>
#endif

namespace rage
{
#pragma pack(push, 8)
	class tlsContext
	{
	public:
		char pad[0x410];      // 0x0000
		int m_SyncDataIndex;  // 0x0410
		char pad2[0x12EC];    // 0x0414
		bool m_RunningScript; // 0x1700

#if _WIN32
		static tlsContext* Get()
		{
			constexpr std::uint32_t TlsIndex = 0x0;
			return *reinterpret_cast<tlsContext**>(__readgsqword(0x58) + TlsIndex);
		}
#endif
	};
#pragma pack(pop)
	static_assert(sizeof(rage::tlsContext) == 0x1704);
}