#pragma once

namespace rage
{
	class atDelegate
	{
	public:
		void* m_Object;
		void* m_Callback;
	};
	static_assert(sizeof(atDelegate) == 0x10);
}