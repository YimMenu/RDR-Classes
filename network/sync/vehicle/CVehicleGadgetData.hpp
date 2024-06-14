#pragma once
#include <cstdint>

class CGadgetData 
{
public:
  uint32_t m_type;
  uint8_t m_data[0xF3];
};
static_assert(sizeof(CGadgetData) == 0xF8);

class CVehicleGadgetNodeData 
{
public:
  bool m_has_position;
  char pad_0001[15];
  float m_position[4];
  uint32_t m_num_gadgets;
  char pad_0002[12];
  CGadgetData m_gadgets[2];
};
static_assert(sizeof(CVehicleGadgetNodeData) == 0x220);