#pragma once
#include "rage/vector.hpp"
#include <cstdint>


struct CProjectileCreationData {
  char m_Pad1[2];
  uint16_t m_OwnerObjectId;
  uint32_t m_AmmoHash;
  uint32_t m_WeaponHash;
  char m_Pad2[4];
  rage::vector3 m_Velocity;
  char m_Pad3[4];
  uint16_t m_ObjectId2;
  char m_Pad4[26];
  rage::matrix34 m_InitialPosition;
};
static_assert(sizeof(CProjectileCreationData) == 0x80);
