#pragma once
#include "rage/vector.hpp"

class CPedHealthData
{
public:
	rage::matrix44 m_WoundEffectPos;
	uint32_t m_DamageWeaponHash;
	uint32_t m_DamageWeaponMode;
	uint32_t m_KillerWeaponHash;
	uint32_t m_KillerWeaponMode;
	uint32_t m_HitComponent;
	float m_CurrentBleedOutDuration;
	uint32_t m_IncapacitationThreshold;
	uint32_t m_WoundIntensity;
	int m_DeathTime;
	uint32_t unk_0064;
	int m_Health;
	unsigned int unsigned_int6C;
	unsigned int m_HealthConfig;
	unsigned int unk_0074;
	uint16_t m_DamagerId;
	uint16_t m_KillerId;
	uint16_t unk_007C;
	char m_DamageCleanliness;
	char unk_007F;
	int m_DamageCleanlinessHits;
	uint8_t m_TotalBleedOutDuration;
	uint8_t unk_0085;
	uint8_t m_FireDamageAmount;
	char unk_0087;
	uint16_t m_IncapacitationFlags;
	uint8_t m_TranquilizerPlayerId;
	bool unk_008B;
	bool m_TotalBleedOutDurationOverridden;
	bool m_HasDefaultHealth;
	bool m_HasDamageBone;
	bool unk_008F;
	bool unk_0090;
	bool unk_0091;
	bool unk_0092;
	bool m_CanBeIncapacitated;
	bool m_Incapacitated;
	bool unk_0095;
	bool unk_0096;
	bool unk_0097;
	bool unk_0098;
	bool unk_0099;
	bool unk_009A;
	bool unk_009B;
	bool m_HasWound;
	bool m_HasBloodPool;
	bool unk_009E;
	bool m_TakingDamage;
	bool unk_00A0;
	bool unk_00A1;
	char epad[0xE];
};
static_assert(sizeof(CPedHealthData) == 0xB0);