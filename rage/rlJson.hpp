#pragma once
#include <cstdint>

namespace rage
{
	class rlJson
	{
		uint32_t unk0;  // 0x00
		uint32_t unk1;  // 0x00
		char* buffer;   // 0x08
		uint32_t curlen;// 0x10
		uint32_t maxlen;// 0x14
		uint32_t unk4;  // 0x18
		uint8_t flags;  // 0x1C

	public:
		rlJson(char* _buffer, uint32_t _length) :
			buffer(_buffer),
			maxlen(_length)
		{
			unk0 = 0;
			unk1 = 0;
			curlen = 0;
			unk4 = 1;
			flags = 0;
		}

		inline char* GetBuffer() const
		{
			return buffer;
		}
	};
	static_assert(sizeof(rage::rlJson) == 0x20);
}