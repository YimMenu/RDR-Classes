#pragma once
#include <cstdint>

namespace rage
{
	class netEncryptionOverride
	{
		char m_OverrideKey[33];
		std::uint8_t m_EncryptionFlags;
	};
}