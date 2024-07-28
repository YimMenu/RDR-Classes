#pragma once
#include "rage/vector.hpp"

#pragma pack(push, 8)
class CVehicleProximityMigrationData
{
public:
	uint32_t m_NumPassengers; //0x0000
	bool m_PassengersActive[17]; //0x0004
	uint16_t m_PassengerObjectIds[17]; //0x0016
	bool m_OverridePopulationType; //0x0038
	uint32_t m_PopulationType; //0x003C
	uint32_t m_Flags; //0x0040
	uint32_t m_Timestamp; //0x0044
	bool m_HasPositionData; //0x0048
	alignas(16) rage::fvector3 m_Position; //0x0050
	int m_VelocityX;
	int m_VelocityY;
	int m_VelocityZ;
	uint32_t m_UnkAmount; //0x006C
}; //Size: 0x0070
static_assert(sizeof(CVehicleProximityMigrationData) == 0x70);
#pragma pack(pop)