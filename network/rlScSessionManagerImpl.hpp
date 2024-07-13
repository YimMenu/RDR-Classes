#pragma once
#include "rage/atUri.hpp"
#include "rlScSession.hpp"

namespace rage
{
	class rlScSessionPoolEntry
	{
	public:
		rlScSessionPoolEntry* m_Next;
		rlScSessionPoolEntry* m_Prev;
		rage::rlScSession m_Session;
	};

	class rlScSessionPool
	{
	public:
		rlScSessionPoolEntry m_Entries[4];
		rlScSessionPoolEntry* m_Next;
		rlScSessionPoolEntry* m_Last;
		rlScSessionPoolEntry* m_First;
		rlScSessionPoolEntry* qword3AD8;
		int m_NumSessions;
	};
	static_assert(sizeof(rlScSessionPool) == 0x3AE8);

	class rlScSessionManagerImpl
	{
	public:
		virtual ~rlScSessionManagerImpl() = default;

		char m_Pad[0x79F0];
		rage::atUri m_ServerUri;
		rage::rlScSessionPool m_SessionPool;
		char m_Pad2[0x170];
	};
	static_assert(sizeof(rlScSessionManagerImpl) == 0xBAD8);
}