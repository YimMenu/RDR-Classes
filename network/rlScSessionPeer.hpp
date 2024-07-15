#pragma once
#include <cstdint>
#include "rlGamerHandle.hpp"

namespace rage
{
	class rlScPeerConnection;
	class rlScSessionPeerIdentifier
	{
	public:
		std::uint32_t m_AccountId;
		rage::rlGamerHandle m_Handle;
	};

	class rlScSessionPeer
	{
	public:
		rage::rlScPeerConnection* m_Connection;
		rage::rlScSessionPeerIdentifier m_Identifier;
		int m_PeerIndex; // 0 - 63
		bool m_IsHost; 
	};
}