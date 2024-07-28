#pragma once
#include "rlScSessionPeer.hpp"

namespace rage
{
	class rlScSessionManagerImpl;
	class rlScSessionId
	{
	public:
		uint64_t m_Id;
		uint64_t m_Token;

		inline bool operator==(const rlScSessionId other)
		{
			return m_Id == other.m_Id && m_Token == other.m_Token;
		}
	};
	static_assert(sizeof(rlScSessionId) == 0x10);
	using rlScSessionRequestId = rlScSessionId; // for now

	class rlScSessionPeerPoolEntry
	{
	public:
		rlScSessionPeerPoolEntry* m_Next;
		rlScSessionPeerPoolEntry* m_Prev;
		rage::rlScSessionPeer m_Peer;
	};

	class rlScSessionPeerPool
	{
	public:
		rlScSessionPeerPoolEntry m_Entries[64];
		rlScSessionPeerPoolEntry* m_Next;
		rlScSessionPeerPoolEntry* m_Last;
		rlScSessionPeerPoolEntry* m_First;
		rlScSessionPeerPoolEntry* qwordE18;
		int m_NumPeers;
	};
	static_assert(sizeof(rlScSessionPeerPool) == 0xE28);

	class rlScSession
	{
	public:
		rage::rlScSessionId m_SessionId;
		char gap10[16];
		rage::rlScSessionManagerImpl* m_SessionManager;
		int m_SlotCount;
		rage::rlScSessionPeerPool m_PeerPool;
		int m_HostPeerIndex;
		int m_LocalPeerIndex;
		char gapE60[4];
		int m_PendingFlags;
		int m_Flags;
		int dwordE6C;
		int m_LastFlagUpdateTime;
		char pad[44];

		inline rage::rlScSessionPeer* GetPeerByHandle(rage::rlGamerHandle& handle)
		{
			for (auto entry = m_PeerPool.m_First; entry; entry = entry->m_Next)
			{
				if (entry->m_Peer.m_Identifier.m_Handle == handle)
					return &entry->m_Peer;
			}

			return nullptr;
		}

		inline rage::rlScSessionPeer* GetPeerByIndex(int index)
		{
			for (auto entry = m_PeerPool.m_First; entry; entry = entry->m_Next)
			{
				if (entry->m_Peer.m_PeerIndex == index)
					return &entry->m_Peer;
			}

			return nullptr;
		}

		inline bool IsHost()
		{
			if (m_LocalPeerIndex >= 0)
				return m_LocalPeerIndex == m_HostPeerIndex;

			return false;
		}

		inline rage::rlScSessionPeer* GetHostPeer()
		{
			if (m_HostPeerIndex < 0)
				return nullptr;

			return GetPeerByIndex(m_HostPeerIndex);
		}
	};
}