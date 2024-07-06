#pragma once
#include "script/types.hpp"
#include "ACEData.hpp"

enum class GFHState
{
	INVALID = -1,
	IDLE,
	WAITING_FOR_ACE_TO_ADD,
	WAIT_FOR_UID,
	PENDING,
	RUNNING,
	ENDING,
	WAITING_FOR_ACE_TO_REMOVE,
	CLEANING_UP_MISSION,
	WAIT_FOR_PLAYERS_TO_CLEAR,
	CLEAN_INVALID_GANG
};

enum class GFHGangType
{
	INVALID = -1,
	PRIMARY,
	RIVAL
};

enum class GFHGangFlag
{
	NONE,
	IS_ON_INSTANCED_MISSION,
	IS_RELAUNCHED_MISSION,
	CLEANUP_MISSION_FOR_RELAUNCH
};

struct GFH_TARGET_DATA
{
	SCR_INT Target;
	SCR_INT Instance;
	SCR_INT Class;
	SCR_INT Subclass;
};
static_assert(sizeof(GFH_TARGET_DATA) == 4 * 8);

struct GFH_GANG_MISSION_DATA
{
	SCR_INT                 GiverIndex; // TODO: find an enum for this one
	SCR_INT                 LocationIndex;
	alignas(8) GFHState     State;
	SCR_INT                 MissionIndex; // -1 = INVALID, and 70 = MAX. That's all we know
	SCR_INT                 PAD_0004;
	SCR_GUID                UID;
	SCR_INT                 ACEAddStartTime;
	SCR_BITSET<GFHGangFlag> GangFlags;
	GFH_TARGET_DATA         Data;
};
static_assert(sizeof(GFH_GANG_MISSION_DATA) == 13 * 8);

struct GFH_GANG_DATA
{
	SCR_INT                 GangId;
	SCR_INT                 ACESlot; 
	alignas(8) GFHState     State;
	GFH_GANG_MISSION_DATA   MissionData;
};
static_assert(sizeof(GFH_GANG_DATA) == 16 * 8);

struct GFH_MISSION_DATA
{
	SCR_ARRAY<GFH_GANG_DATA, 32> GangDatas;
	ACE_DATA                     ACEData;
};
static_assert(sizeof(GFH_MISSION_DATA) == 717 * 8);

enum class GFHLocationGiverHostState
{
	INVALID = -1,
	INIT,
	RUNNING,
	DISABLED
};

struct GFH_LOCATION_GIVER_DATA
{
	alignas(8) GFHLocationGiverHostState State;
	SCR_INT                              TimeInitialized;
};
static_assert(sizeof(GFH_LOCATION_GIVER_DATA) == 2 * 8);