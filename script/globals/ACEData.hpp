#pragma once
#include "script/types.hpp"
#include "SessionManagerPlayerData.hpp"

enum class ACEHostState
{
	INVALID = -1,
	INIT,
	UPDATE
};

enum class ACESlotType
{
	TRAIN,
	GFH_POSSE_VERSUS,
	AMBIENT_CONTENT,
	DEATHMATCH,
	MAX
};

enum class ACEClientRequestState
{
	INVALID = -1,
	PUSHED,
	STARTED,
	EVALUATED,
	PROCESSED
};

enum class ACERequestOwner
{
	INVALID = -1,
	GUN_FOR_HIRE,
	TRAIN_MANAGER,
	FETCH_MANAGER,
	FMA_MANAGER,
	COACH_JOB_MANAGER,
	PLAYER_DATA,
	AMBIENT_DEATHMATCH,
	NET_BEAT,
	END
};

enum class ACERequestType
{
	INVALID = -1,
	ADD_MISSION,
	UPDATE_MISSION_LAUNCH_DATA,
	UPDATE_MISSION_PRIORITY,
	UPDATE_MISSION_SLOT_TYPE,
	UPDATE_GFH_UID_AND_LAUNCH_FLAGS,
	SET_LAUNCH_CONFIG_FLAGS,
	SWITCH_MISSION_TO_UID_AND_SET_LAUNCH_DATA,
	REMOVE_MISSION
};

enum class ACERequestResult
{
	PROCESSING,
	SUCCESS,
	FAILURE
};

enum class ACESlotPriority
{
	EMPTY = -1,
	CLEANUP,
	LOW,
	HIGH,
	CRITICAL
};

enum class ACEConfigFlags
{
	USE_LAUNCHER,
	USE_GANG_SYNC,
	USE_SCRIPT_LAUNCHER = 4,
	USE_PROC_THREAD = 6,
	USE_BEAT_THREAD
};

enum class ACEHostMissionState
{
	INVALID = -1,
	DISABLED,
	IDLE,
	MISSION_RUNNING,
	PRE_CLEANUP,
	SYNC_FLAGS,
	CLEANUP,
	COMPLETED
};

enum class ACEHostRuntimeState
{
	INVALID = -1,
	DISABLED,
	IDLE,
	ACTIVE,
	CLEANUP
};

struct ACE_MISSION_IDENTIFIER_DATA
{
	SCR_GUID                UID;
	SCR_INT                 GangId;
	SCR_INT                 PosseVersusSlotId;
	SCR_INT                 GunForHireIndex;
	SCR_INT                 DeathmatchSlotId;
	SCR_GUID                GFHDeed;
	SCR_BITSET<ContentLock> ContentLocks; // actually named (e)ContentLock but that'll break the linux build
	SCR_INT                 ExpectedSlotType;
};
static_assert(sizeof(ACE_MISSION_IDENTIFIER_DATA) == 10 * 8);

struct ACE_MISSION_LOCATION_DATA
{
	SCR_INT Location;
	SCR_INT InstanceId;
	SCR_INT VolumeLockSize;
	SCR_INT LaunchDistance;
};

struct ACE_MISSION_DATA
{
	constexpr static int INVALID_EXPIRE_TIME = -15;

	SCR_HASH                                ScriptHash;
	SCR_INT                                 StackSize;
	SCR_INT                                 Radius;
	SCR_INT                                 PAD_0003;
	SCR_INT                                 ExpireTime;
	PLAYER_INDEX                            StartingPlayer;
	SCR_BITSET<ACEConfigFlags>              ConfigFlags;
	SCR_INT                                 NumLocations; // always 1
	SCR_ARRAY<ACE_MISSION_LOCATION_DATA, 1> Locations;
	alignas(8) ACEHostMissionState          State;
	SCR_INT                                 BeatParameter2;
	SCR_INT                                 BeatParameter3;
	SCR_INT                                 BeatParameter4;
};
static_assert(sizeof(ACE_MISSION_DATA) == 17 * 8);

// TODO: what is this actually called?
struct ACE_MISSION_SLOT_DATA
{
	alignas(8) ACESlotType      Type;
	alignas(8) ACESlotPriority  Priority;
	uint64_t                    PAD_0002[3]; // seemingly unused
	ACE_MISSION_IDENTIFIER_DATA IdentifierData;
};
static_assert(sizeof(ACE_MISSION_SLOT_DATA) == 15 * 8);

struct ACE_MISSION_REQUEST
{
	alignas(8) ACEClientRequestState State;
	SCR_INT                          RequestIndex;
	alignas(8) ACERequestOwner       Owner;
	PLAYER_INDEX                     PlayerOwner;
	SCR_INT                          RequestIndex2; // apparently
	alignas(8) ACERequestType        RequestType;
	alignas(8) ACERequestResult      Result;
	SCR_INT                          Timestamp;
	ACE_MISSION_SLOT_DATA            SlotData;
	ACE_MISSION_DATA                 MissionData;
};
static_assert(sizeof(ACE_MISSION_REQUEST) == 40 * 8);

struct ACE_DATA
{
	SCR_INT                           MaxItems;
	SCR_INT                           QueueAdd;
	SCR_INT                           QueueMod;
	SCR_ARRAY<ACE_MISSION_REQUEST, 5> Requests;
};
static_assert(sizeof(ACE_DATA) == 204 * 8);