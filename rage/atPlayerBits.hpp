#pragma once

#pragma pack(push, 8)
namespace rage
{
	class atPlayerBits
	{
		constexpr static int MAX_PLAYERS = 32;
		int m_PlayerBits[MAX_PLAYERS / 32];

	public:
		bool IsSet(int id)
		{
			return _bittest((const long*)&m_PlayerBits[id / 32], id % 32);
		}

		void Set(int id)
		{
			m_PlayerBits[id / 32] |= (1 << (id % 32));
		}

		void Clear(int id)
		{
			m_PlayerBits[id / 32] &= ~(1 << (id % 32));
		}

		// TODO: bit count, CNetGamePlayer...
	};
	static_assert(sizeof(rage::atPlayerBits) == 4);
}
#pragma pack(pop)