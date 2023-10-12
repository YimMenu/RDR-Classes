#pragma once
#include <cstdint>

class CNetGamePlayer;
namespace rage
{
	class netGameEvent
	{
	public:
		virtual ~netGameEvent() = 0; // 0x00

		std::int16_t m_EventType;       // 0x08
		bool m_RequiresReply;           // 0x0A
		char m_Pad1[0xD];               // 0x0B
		class CNetGamePlayer* m_Sender; // 0x18
		char m_Pad2[0x18];              // 0x20
	};
	static_assert(sizeof(rage::netGameEvent) == 0x38);
}