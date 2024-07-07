#pragma once
#include "script/types.hpp"

enum class FMERunningState
{
	INVALID,
	INIT,
	LAUNCH_OFFLINE,
	MATCHMAKE,
	LAUNCH_ONLINE,
	MAIN,
	CLEANUP
};

enum class FMEEvent
{
	INVALID = -1,
	FIRST,
	CHALLENGES,
	DEAD_DROP,
	GOLDEN_HAT,
	HOT_PROPERTY,
	KING_OF_THE_CASTLE,
	KING_OF_THE_RAILS,
	WILDLIFE_PHOTOGRAPHER,
	THEMED_ESCAPED_CONVICTS,
	THEMED_ROUND_UP,
	THEMED_SUPPLY_TRAIN,
	THEMED_WRECKAGE,
	THEMED_CONDOR_EGG,
	THEMED_ANIMAL_TAGGING,
	THEMED_LAST,
	PV_CHALLENGE_HERBALIST,
	PV_CHALLENGE_BIGGEST_FISH,
	PV_CHALLENGE_FLYING_BIRD,
	HUNT_THE_POSSE_LEADER,
	MAX
};

struct FME_VOLUME_LOCK
{
	SCR_INT RequestId;
	SCR_INT RequestId2; // ???
};

struct FME_EVENT
{
	alignas(8) FMERunningState State;
	alignas(8) FMEEvent        Event;
	SCR_INT                    LocationId;
	SCR_INT                    VariationId;
	SCR_INT                    PAD_0004; // random int for volume stuff?
	SCR_GUID                   UID;
	PLAYER_INDEX               LaunchPlayer;
	SCR_INT                    PAD_0008; // unused
	FME_VOLUME_LOCK            VolumeLock; 
	SCR_INT                    PAD_0011; // unused
	SCR_DATE                   LaunchWindowDate;
	SCR_DATE                   ExpirationDate;
};
static_assert(sizeof(FME_EVENT) == 26 * 8);

struct FME_MANAGER_HOST_DATA
{
	SCR_INT                 State;
	SCR_ARRAY<FME_EVENT, 8> Events;
	SCR_DATE                LaunchDate;
	SCR_DATE                ThemedLaunchDate;
	alignas(8) FMEEvent     LaunchingEvent;
	alignas(8) FMEEvent     LaunchingThemedEvent;
	SCR_INT                 NumLaunchesToday;
	SCR_INT                 NumThemedLaunchesToday;
};
static_assert(sizeof(FME_MANAGER_HOST_DATA) == 228 * 8);