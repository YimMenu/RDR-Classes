#pragma once
#include <cstdint>

class CPlayerAppearanceData
{
public:
	char pad_0000[23612]; //0x0000
	uint32_t m_ModelHash; //0x5C3C
	char pad_5C40[7]; //0x5C40
	bool m_BannedPlayerModel; //0x5C47
}; //Size: 0x5C48
static_assert(sizeof(CPlayerAppearanceData) == 0x5C48);