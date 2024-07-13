#pragma once
#include <cstdint>

class CNetworkScSessionMultiplayerImpl;
class CNetworkScServerConnection;

namespace rage
{
#pragma pack(push, 8)
	struct rlScSessionMultiplayer
	{
	public:
		virtual ~rlScSessionMultiplayer() = default;

		uint64_t qword8;
		CNetworkScSessionMultiplayerImpl* m_SessionMultiplayer;
		uint64_t qword18;
		int16_t word20;
		char byte22;
		uint32_t dword24;
		char gap28[4184];
		CNetworkScServerConnection* m_ServerConnection;
		void* m_NetConnectionManager;
		uint64_t qword1090;
		uint32_t m_SessionType;
		char gap109C[9176];
		uint32_t m_ConnectionId;
		char gap347C[164];
	};
	static_assert(sizeof(rage::rlScSessionMultiplayer) == 0x3520);
#pragma pack(pop)
}