#pragma once
#include "joaat.hpp"

namespace rage
{
	class rlJson;
	class rlMetric
	{
	public:
		virtual ~rlMetric() = default;                         // 0x00
		virtual int GetType() = 0;                             // 0x08
		virtual int GetType2() = 0;                            // 0x10
		virtual const char* GetName() = 0;                     // 0x18
		virtual bool Serialize(rage::rlJson* serializer) = 0;  // 0x20
		virtual int GetSize() = 0;                             // 0x28
		virtual joaat_t GetNameHash() = 0;                     // 0x30
		virtual bool _0x38() = 0;
		virtual bool _0x40() = 0;
	};
	static_assert(sizeof(rage::rlMetric) == 0x8);
}