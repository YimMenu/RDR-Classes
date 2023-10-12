#pragma once
#include <cstdint>
#include "rage/vector.hpp"
#include <cstddef>

#pragma pack(push, 8)
class CPhysicalAttachData
{
public:
	bool m_IsAttached;                   //0x0000
	uint16_t m_AttachObjectId;           //0x0002
	alignas(16) rage::fvector3 m_Offset; //0x0010
	rage::fvector4 m_Orientation;        //0x0020
	rage::fvector3 m_ParentOffset;       //0x0030
	uint16_t m_OtherAttachBone;          //0x0040
	uint16_t m_AttachBone;               //0x0042
	uint32_t m_AttachFlags;              //0x0044
	char pad_0048[24];                   //0x0048
}; //Size: 0x0060
#pragma pack(pop)
static_assert(sizeof(CPhysicalAttachData) == 0x60);