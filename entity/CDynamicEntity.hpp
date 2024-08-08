#pragma once
#include "entity/CEntity.hpp"

class CPortalTracker
{
public:
	virtual ~CPortalTracker() = default;

	char m_Pad[0x90]; // 0x0008
};
static_assert(sizeof(CPortalTracker) == 0x98); // TODO: confirm

class CDynamicEntity : public CEntity
{
public:
	class rage::netObject* m_NetObject; // 0x00E0
	char m_Pad3[0x28];                  // 0x00E8
	CPortalTracker m_PortalTracker;     // 0x0110
	char m_Pad4[8];                     // 0x01A8
};
static_assert(sizeof(CDynamicEntity) == 0x1B0);