#pragma once
#include <cstdint>

class CPedVitalityData
{
public:
	uint32_t m_HealthInReserve[8];
	uint32_t m_Health;
	uint32_t unk_0024;
	uint32_t unk_0028;
	uint32_t unk_002C;
	uint32_t unk_0030;
	uint32_t unk_0034;
	uint8_t m_NumHealthReserves;
	bool unk_0039;
	bool m_HasUpgradeData;
	bool unk_003B;
	bool unk_003C;
	bool unk_003D;
	bool m_HasHealthTankUpgrade;
	bool m_HasStaminaTankUpgrade;
	uint32_t unk_0040;
	uint32_t unk_0044;
	uint32_t unk_0048;
	bool unk_004C;
	bool unk_004D;
	bool unk_004E;
	uint32_t m_TotalHealth;
	uint32_t m_UnkComponentValue;
	uint32_t dword58;
	char gap5C[4];
	uint64_t qword60;
	uint64_t qword68;
	bool m_HasDefaultHealth;
	bool m_IsDead;
	bool m_HasDefaultUnk;
	bool m_IsIncapacitated;
	bool unk_0074;
	bool unk_0075;
};
static_assert(sizeof(CPedVitalityData) == 0x78);