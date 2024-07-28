#pragma once
#include <cstdint>

#pragma pack(push, 8)
namespace rage
{
	class atUri
	{
	public:
		enum ProtocolType
		{
			HTTP,
			HTTPS,
			WS,
			WSS
		};

		ProtocolType m_ProtocolType;
		char m_Host[128];
		std::int16_t m_Port;
		char m_Path[512];
		char m_QueryString[512];
	};
	static_assert(sizeof(atUri) == 0x488);
}
#pragma pack(pop)