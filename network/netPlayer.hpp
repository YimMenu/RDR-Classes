#pragma once
#include <cstdint>

namespace rage
{
	class netPlayer
	{
	public:
		virtual ~netPlayer() = default; // 0x00

		char pad_0008[12]; //0x0008
		uint32_t m_MessageId; //0x0014
		uint8_t m_ActiveIndex; //0x0018
		uint8_t m_PlayerIndex; //0x0019
		char pad_001A[10]; //0x001A
		uint32_t m_JoinTime; //0x0024
		char pad_0028[256]; //0x0028
	}; //Size: 0x0128
	static_assert(sizeof(rage::netPlayer) == 0x128);
}