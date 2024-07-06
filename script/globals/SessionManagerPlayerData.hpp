#pragma once
#include "script/types.hpp"
#include "rage/joaat.hpp"
#include "PlayerStatusSyncData.hpp"

enum class ContentLock
{
	PROC_MISSIONS,
	GANG_EVENTS,
	SHOPS,
	HIDEOUTS,
	CAMPS,
	REGIONS,
	TRAINS,
	FM_ACTIVITIES,
	STORY_MISSIONS,
	PROPERTIES,
	GUN_FOR_HIRE,
	MINIGAMES,
	PLAYER_BOUNTIES,
	AMBIENT_ROAD_POPULATION
};

struct SESSION_MANAGER_PLAYER_DATA_ENTRY
{
	SCR_BITSET<ContentLock>                                        ContentLocks;
	uint64_t                                                       PAD_0001[3]; // unused?
	SCR_BITSET_LARGE<Region, static_cast<int>(Region::MAX), 30, 7> LockedRegions;
};
static_assert(sizeof(SESSION_MANAGER_PLAYER_DATA_ENTRY) == 12 * 8);

struct SESSION_MANAGER_PLAYER_DATA
{
	SCR_ARRAY<SESSION_MANAGER_PLAYER_DATA_ENTRY, 32> Entries;
};
static_assert(sizeof(SESSION_MANAGER_PLAYER_DATA) == 385 * 8);