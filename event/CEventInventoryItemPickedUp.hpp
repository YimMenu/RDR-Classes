#pragma once
#include "CEvent.hpp"
#include "script/types.hpp"

class CEventInventoryItemPickedUp : public CEvent
{
	SCR_INT m_Unk;
	SCR_INT m_RewardHash;
	SCR_INT m_ItemHash;
	SCR_BOOL m_Unk2;
	SCR_BOOL m_Unk3;
	PICKUP_INDEX m_Pickup;
};
static_assert(sizeof(CEventInventoryItemPickedUp) == 0x90);