#pragma once
#include <cstdint>

#pragma pack(push, 4)
namespace rage
{
	class rlJson
	{
		uint32_t unk0;  // 0x00
		uint32_t unk1;  // 0x04
		char* m_Buffer;   // 0x08
		uint32_t m_Curlen;// 0x10
		uint32_t m_Maxlen;// 0x14
		uint32_t unk4;  // 0x18
		uint32_t m_Flags; // 0x1C
		uint8_t m_Flags2; // 0x20

	public:
		rlJson(char* _buffer, uint32_t _length) :
			m_Buffer(_buffer),
			m_Maxlen(_length)
		{
			unk0 = 0;
			unk1 = 0;
			m_Curlen = 0;
			unk4 = 1;
			m_Flags = 0;
			m_Flags2 = 0;
		}

		inline char* GetBuffer() const
		{
			return m_Buffer;
		}
	};
	static_assert(sizeof(rage::rlJson) == 0x24);
}
#pragma pack(pop)