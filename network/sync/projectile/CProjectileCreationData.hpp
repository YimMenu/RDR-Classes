#pragma once
#include <cstdint>
#include "rage/vector.hpp"

struct CProjectileCreationData
{
	uint16_t unk_0000;
	uint16_t m_OwnerObjectId;
	uint32_t m_AmmoHash;
	uint32_t m_WeaponHash;
	uint32_t unk_000C;
	rage::vector3 m_Vector;
	uint32_t unk_0020;
	uint16_t m_ObjectId2;
	char pad_0026[2];
	bool unk_0028;
	char pad_0029[3];
	uint32_t unk_002C;
	bool pad_0030;
	bool unk_0031;
	char pad_0032[2];
	float unk_0034;
	bool unk_0038;
	bool unk_0039;
	bool unk_003A;
	bool unk_003B;
	char pad_003C[4];
	rage::matrix34 m_Matrix;
};
static_assert(sizeof(CProjectileCreationData) == 0x80);