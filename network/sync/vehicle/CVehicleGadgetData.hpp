#pragma once
#include <cstdint>

class CGadgetData {
public:
  uint32_t m_Type;
  uint8_t m_Data[0xF3];
};
static_assert(sizeof(CGadgetData) == 0xF8);

// TODO: Fix this
class CVehicleGadgetData {
public:
  bool m_HasPosition;
  char pad_0001[15];
  float m_Position[4];
  uint32_t m_NumGadgets;
  char pad_0002[12];
  CGadgetData m_Gadgets[2];
};
static_assert(sizeof(CVehicleGadgetData) == 0x220);