#pragma once
#include "script/types.hpp"

#include "ACEData.hpp"

struct ACE_MISSION_QUEUE
{
	SCR_INT                           NumItems;
	SCR_INT                           QueueHead;
	SCR_ARRAY<ACE_MISSION_REQUEST, 5> Requests;
};
static_assert(sizeof(ACE_MISSION_QUEUE) == 203 * 8);

struct ACE_MISSIONS
{
	SCR_ARRAY<ACE_MISSION_SLOT_DATA, 71> Slots;
	SCR_ARRAY<ACE_MISSION_DATA, 71>      Datas;
};

struct ACE_MISSION_LOCATION_RUNTIME_DATA
{
	alignas(8) ACEHostRuntimeState State;
	SCR_INT                        VolumeLockState;
	SCR_INT                        VolumeLockRequestId;

};
static_assert(sizeof(ACE_MISSION_LOCATION_RUNTIME_DATA) == 3 * 8);

// TODO: find actual names
struct ACE_MISSION_RUNTIME_DATA
{
	SCR_ARRAY<ACE_MISSION_LOCATION_RUNTIME_DATA, 1> Locations;
	SCR_INT                                         StartingGangId;
	PLAYER_INDEX                                    StartingPlayer;
};
static_assert(sizeof(ACE_MISSION_RUNTIME_DATA) == 6 * 8);

struct ACE_HOST_RUNTIME_DATA
{
	SCR_ARRAY<ACE_MISSION_RUNTIME_DATA, 71> RuntimeMissionDatas;
	SCR_ARRAY<uint64_t, 71>                 SlotIndices;
	SCR_INT                                 NumSlots;
};
static_assert(sizeof(ACE_HOST_RUNTIME_DATA) == 500 * 8);

struct ACE_HOST_DATA
{
	alignas(8) ACEHostState                                 State;
	SCR_INT                                                 LastValidateTime;
	alignas(8) ACESlotType                                  ValidatingSlot;
	SCR_ARRAY<uint64_t, static_cast<int>(ACESlotType::MAX)> MaxMissionsInSlot;
	SCR_ARRAY<uint64_t, static_cast<int>(ACESlotType::MAX)> AllMissionsInSlot;
	SCR_ARRAY<uint64_t, static_cast<int>(ACESlotType::MAX)> ValidMissionsInSlot;
	SCR_ARRAY<uint64_t, static_cast<int>(ACESlotType::MAX)> WrongMissionsInSlot;
	SCR_ARRAY<uint64_t, static_cast<int>(ACESlotType::MAX)> OverflowMissionsInSlot;
	ACE_MISSION_QUEUE                                       MissionQueue;
	ACE_MISSIONS                                            Missions;
	ACE_HOST_RUNTIME_DATA                                   RuntimeData;
};
static_assert(sizeof(ACE_HOST_DATA) == 3005 * 8);