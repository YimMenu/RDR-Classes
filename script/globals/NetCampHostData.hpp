#pragma once
#include "script/types.hpp"
#include "rage/joaat.hpp"

enum class CampState
{
	INVALID = -1,
	WAITING,
	RUNNING,
	CLEANUP
};

enum class CampLocationIndex : std::uint32_t
{
	GRIZZLIES_CAMP = rage::joaat("GRIZZLIES_CAMP"),
	BAYOU_NAWAS_CAMP = rage::joaat("BAYOU_NAWAS_CAMP"),
	BIG_VALLEY_CAMP = rage::joaat("BIG_VALLEY_CAMP"),
	CHOLLA_SPRINGS_CAMP = rage::joaat("CHOLLA_SPRINGS_CAMP"),
	CUMBERLAND_FOREST_CAMP = rage::joaat("CUMBERLAND_FOREST_CAMP"),
	GAPTOOTH_RIDGE_CAMP = rage::joaat("GAPTOOTH_RIDGE_CAMP"),
	GREAT_PLAINS_CAMP = rage::joaat("GREAT_PLAINS_CAMP"),
	HEARTLAND_CAMP = rage::joaat("HEARTLAND_CAMP"),
	HENNIGANS_STEAD_CAMP = rage::joaat("HENNIGANS_STEAD_CAMP"),
	RIO_BRAVO_CAMP = rage::joaat("RIO_BRAVO_CAMP"),
	ROANOKE_RIDGE_CAMP = rage::joaat("ROANOKE_RIDGE_CAMP"),
	SCARLETT_MEADOWS_CAMP = rage::joaat("SCARLETT_MEADOWS_CAMP"),
	TALL_TREES_CAMP = rage::joaat("TALL_TREES_CAMP"),
};

enum class CampBit
{
	IS_LAUNCHED,
	IS_ATTACKING,
	IS_ACTIVE,
	BLIP_DISABLED,
	WHITE_FLAG_RAISED,
	WHITE_FLAG_LOCKED_LOWERED,
	SHOW_BLIPS_HIDDEN,
	IS_FOLLOWER_STOLEN,
	SUPPRESS_FOLLOWER,
	FOLLOWER_DEAD,
	IS_CAMPWORKS_LAUNCHED,
	WHITE_FLAG_RAISED_PRE_CONTENT,
	WHITE_FLAG_LOCKED_FOR_CONTENT
};

enum class CampContentType
{
	NONE,
	NET_BEAT,
	DYNAMIC_MISSION,
	TRADER_MISSION,
	CAMP_RAID
};

struct CAMP_LOCATION
{
	SCR_INT                      Size; // tents and the main camp
	alignas(8) CampLocationIndex Index;
	SCR_INT                      Instance; // or similar
};

struct CAMP_CONTENT
{
	SCR_BOOL                   Active; // actually a bitset with a single bit
	alignas(8) CampContentType Type;
};

struct CAMP_VOLUME_LOCKS
{
	SCR_INT CampRequestId;
	SCR_INT AllRequestId;
};

struct NET_HOST_CAMP
{
	alignas(8) CampState    State;
	CAMP_LOCATION           Location;
	uint64_t                PAD_0004[3];
	SCR_BITSET<CampBit>     Flags;
	uint64_t                PAD_0008;
	PLAYER_INDEX            Owner; // likely the posse leader
	SCR_ARRAY<uint64_t, 7>  TentOwners; // or residents
	CAMP_CONTENT            ActiveContent;
	SCR_VEC3                Position;
	CAMP_VOLUME_LOCKS       VolumeLocks;
	SCR_INT                 RelationshipBits;
	SCR_INT                 LastVolumeUpdateTime;
};
static_assert(sizeof(NET_HOST_CAMP) == 27 * 8);

enum class CampRequestState
{
	INVALID = -1,
	INIT,
	WAIT_FOR_VOLUME_LOCKS,
	VERIFY,
	UPDATE_CAMP_SIZE,
	FIND_NEW_CAMP_IN_DISTRICT,
	FIND_NEW_CAMP_ANYWHERE,
	COMPLETE
};

struct NET_HOST_CAMP_REQUEST
{
	alignas(8) CampRequestState State;
	CAMP_LOCATION               Location;
	SCR_INT                     RequestId;
	SCR_INT                     Flags; // TODO
	SCR_INT                     PlacementAttempts;
};
static_assert(sizeof(NET_HOST_CAMP_REQUEST) == 7 * 8);

enum class CampManagerHostState
{
	INIT,
	STREAM,
	RUNNING
};

struct NetCampHostData
{
	SCR_ARRAY<NET_HOST_CAMP, 32>         Camps;
	SCR_ARRAY<NET_HOST_CAMP_REQUEST, 32> CampRequests;
	alignas(8) CampManagerHostState      State;
	SCR_INT                              CampPlayerBitset;
};
static_assert(sizeof(NetCampHostData) == 1092 * 8);