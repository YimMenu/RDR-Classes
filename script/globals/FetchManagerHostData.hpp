#pragma once
#include "script/types.hpp"
#include "GunForHireMissionData.hpp"
#include "ACEData.hpp"

enum class MissionLaunchType
{
	INVALID = -1,
	PLAYER_LAUNCHED,
	DYNAMIC_UNACCEPTED,
	AMBIENT_TRAIN,
	MAX
};

enum class MissionState
{
	INVALID = -1,
	INIT,
	WAITING_FOR_SLOT,
	RUNNING,
	CLEANUP
};

enum class MissionFlags
{
	IS_AGGRO,
	LAUNCHED,
	CLEANED_UP,
	IS_FORCE_PASSIVE,
	IS_STARTED,
	IS_ACTIVE,
	IS_COMPLETED,
	IS_RECONCILING,
	IN_LAUNCH_RADIUS,
	CHECKED_SHUTDOWN_RADIUS,
	OUTSIDE_SHUTDOWN_RADIUS,
	NOT_RUNNING_THREAD,
	ONLINE_STREAMING_COMPLETE,
	ALLOW_DISABLED_LAW,
	FORCE_DELETE,
	SPAWN_COMPLETED,
	FORCE_HIDE_UI,
	ACCEPTED,
	FAILED_TO_ACCEPT,
	IS_RELAUNCH,
	CHECKED_ONLINE_THREAD,
	GLOBAL_SIGNAL_READY,
	PREVENT_THREAD_SHUTDOWN,
	SHUTDOWN_DETECTED,
	INHERITED_MISSION_FROM_POSSE,
	ACTIVE_PLAYERS_LEFT,
	TALKED_TO_DYNAMIC_MISSION_GIVER,
	GAVE_IGNORED_MISSION_GIVER_HONOR,
	DELETE_EXISTING_VOLUME_LOCKS,
	REQUESTED_ACE_SLOT,
	FORCE_SHUTDOWN_PRIMARY_TEAM,
	IS_INSTANCED
};

enum class SaleBit
{
	INVALID = 31,
	SIZE_VERY_SMALL = 0,
	SIZE_SMALL,
	SIZE_MEDIUM,
	SIZE_LARGE,
	STRENGTH_WEAK,
	STRENGTH_AVERAGE,
	STRENGTH_STRONG,
	ORDER_ANY,
	ORDER_UNFLAVORED,
	ORDER_REGULAR,
	ORDER_IMPROVED,
	ORDER_SPECIAL,
	STORY_MISSION_COMPLETE
};

struct MISSION_SALE_DATA
{
	SCR_BITSET<SaleBit> Flags;
	SCR_INT             NumGoods; // used only for CAMP_SELL
};

struct FETCH_MANAGER_MISSION
{
	SCR_INT                      MissionIndex; // seemingly obtained from the server
	alignas(8) MissionLaunchType LaunchType;
	alignas(8) MissionState      State;
	SCR_BITSET<MissionFlags>     Flags;
	SCR_INT                      ACESlot;
	SCR_INT                      CampIndex;
	SCR_INT                      Location;
	SCR_INT                      GFHLocation;
	SCR_INT                      BeatIndex;
	SCR_INT                      Instance; // maybe, a random integer from 0 to 65535
	SCR_INT                      StartTime;
	SCR_INT                      GangMembers;
	SCR_INT                      RequiredRelGroups; // whatever that means
	SCR_INT                      GangId;
	SCR_INT                      LaunchPlayers;
	PLAYER_INDEX                 Owner;
	PLAYER_INDEX                 Target; // ???
	PLAYER_INDEX                 SecondaryPlayer;
	PLAYER_INDEX                 BountyTarget; // ???
	SCR_VEC3                     Position; // used only for CAMP_RAID
	GFH_TARGET_DATA              TargetData;
	MISSION_SALE_DATA            SaleData;
};
static_assert(sizeof(FETCH_MANAGER_MISSION) == 28 * 8);

struct FETCH_MISSION_THREAD
{
	SCR_INT  MissionIndex;
	SCR_BOOL CleanedUp;
};

struct FETCH_MANAGER_HOST_DATA
{
	SCR_ARRAY<FETCH_MANAGER_MISSION, 13>                          Missions;
	SCR_ARRAY<uint64_t, static_cast<int>(MissionLaunchType::MAX)> RunningMissionsOfType;
	SCR_ARRAY<FETCH_MISSION_THREAD, 5>                            MissionsThreads;
	ACE_DATA                                                      ACEData;
	SCR_INT                                                       State; // init, streaming, running
	SCR_INT                                                       PAD_0585;
	SCR_INT                                                       ViableTargets;
	SCR_INT                                                       NumRunningMissions;
};
static_assert(sizeof(FETCH_MANAGER_HOST_DATA) == 588 * 8);