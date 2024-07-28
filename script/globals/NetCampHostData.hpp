#pragma once
#include "script/types.hpp"
#include "rage/joaat.hpp"
#include <unordered_map> // TODO: remove!

enum class CampState
{
	INVALID = -1,
	WAITING,
	RUNNING,
	CLEANUP
};

inline std::unordered_map<CampState, std::string> g_CampStateMap = {
	{CampState::INVALID, "Invalid"},
	{CampState::WAITING, "Waiting"},
	{CampState::RUNNING, "Running"},
	{CampState::CLEANUP, "Cleanup"}
};

enum class CampLocationIndex : std::uint32_t
{
	GRIZZLIES_CAMP = rage::Joaat("GRIZZLIES_CAMP"),
	BAYOU_NAWAS_CAMP = rage::Joaat("BAYOU_NAWAS_CAMP"),
	BIG_VALLEY_CAMP = rage::Joaat("BIG_VALLEY_CAMP"),
	CHOLLA_SPRINGS_CAMP = rage::Joaat("CHOLLA_SPRINGS_CAMP"),
	CUMBERLAND_FOREST_CAMP = rage::Joaat("CUMBERLAND_FOREST_CAMP"),
	GAPTOOTH_RIDGE_CAMP = rage::Joaat("GAPTOOTH_RIDGE_CAMP"),
	GREAT_PLAINS_CAMP = rage::Joaat("GREAT_PLAINS_CAMP"),
	HEARTLAND_CAMP = rage::Joaat("HEARTLAND_CAMP"),
	HENNIGANS_STEAD_CAMP = rage::Joaat("HENNIGANS_STEAD_CAMP"),
	RIO_BRAVO_CAMP = rage::Joaat("RIO_BRAVO_CAMP"),
	ROANOKE_RIDGE_CAMP = rage::Joaat("ROANOKE_RIDGE_CAMP"),
	SCARLETT_MEADOWS_CAMP = rage::Joaat("SCARLETT_MEADOWS_CAMP"),
	TALL_TREES_CAMP = rage::Joaat("TALL_TREES_CAMP"),
};

inline std::unordered_map<CampLocationIndex, std::string> g_CampLocationMap = {
	{CampLocationIndex::GRIZZLIES_CAMP, "Grizzlies"},
	{CampLocationIndex::BAYOU_NAWAS_CAMP, "Bayou Nawas"},
	{CampLocationIndex::BIG_VALLEY_CAMP, "Big Valley"},
	{CampLocationIndex::CHOLLA_SPRINGS_CAMP, "Cholla Springs"},
	{CampLocationIndex::CUMBERLAND_FOREST_CAMP, "Cumberland Forest"},
	{CampLocationIndex::GAPTOOTH_RIDGE_CAMP, "Gaptooth Ridge"},
	{CampLocationIndex::GREAT_PLAINS_CAMP, "Great Plains"},
	{CampLocationIndex::HEARTLAND_CAMP, "Heartland"},
	{CampLocationIndex::HENNIGANS_STEAD_CAMP, "Hennigans Stead"},
	{CampLocationIndex::RIO_BRAVO_CAMP, "Rio Bravo"},
	{CampLocationIndex::ROANOKE_RIDGE_CAMP, "Roanoke Ridge"},
	{CampLocationIndex::SCARLETT_MEADOWS_CAMP, "Scarlett Meadows"},
	{CampLocationIndex::TALL_TREES_CAMP, "Tall Trees"}
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

inline std::unordered_map<CampBit, std::string> g_CampBitMap = {
	{CampBit::IS_LAUNCHED, "Is Launched"},
	{CampBit::IS_ATTACKING, "Is Attacking"},
	{CampBit::IS_ACTIVE, "Is Active"},
	{CampBit::BLIP_DISABLED, "Blip Disabled"},
	{CampBit::WHITE_FLAG_RAISED, "White Flag Raised"},
	{CampBit::WHITE_FLAG_LOCKED_LOWERED, "White Flag Locked Lowered"},
	{CampBit::SHOW_BLIPS_HIDDEN, "Show Blips Hidden"},
	{CampBit::IS_FOLLOWER_STOLEN, "Is Follower Stolen"},
	{CampBit::SUPPRESS_FOLLOWER, "Suppress Follower"},
	{CampBit::FOLLOWER_DEAD, "Follower Dead"},
	{CampBit::IS_CAMPWORKS_LAUNCHED, "Is Campworks Launched"},
	{CampBit::WHITE_FLAG_RAISED_PRE_CONTENT, "White Flag Raised Pre Content"},
	{CampBit::WHITE_FLAG_LOCKED_FOR_CONTENT, "White Flag Locked For Content"}
};

enum class CampContentType
{
	NONE,
	NET_BEAT,
	DYNAMIC_MISSION,
	TRADER_MISSION,
	CAMP_RAID
};

inline std::unordered_map<CampContentType, std::string> g_CampContentTypeMap = {
	{CampContentType::NONE, "None"},
	{CampContentType::NET_BEAT, "Net Beat"},
	{CampContentType::DYNAMIC_MISSION, "Dynamic Mission"},
	{CampContentType::TRADER_MISSION, "Trader Mission"},
	{CampContentType::CAMP_RAID, "Camp Raid"}
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