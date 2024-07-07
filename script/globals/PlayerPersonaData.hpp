#pragma once
#include "script/types.hpp"
#include "rage/joaat.hpp"

enum class AbilityType : std::uint32_t
{
	STRANGE_MEDICINE = rage::joaat("NET_PLAYER_ABILITY__STRANGE_MEDICINE"),
	FOCUS_FIRE = rage::joaat("NET_PLAYER_ABILITY__FOCUS_FIRE"),
	NECESSITY_BREEDS = rage::joaat("NET_PLAYER_ABILITY__NECESSITY_BREEDS"),
	THE_GIFT_OF_FOCUS = rage::joaat("NET_PLAYER_ABILITY__THE_GIFT_OF_FOCUS"),
	RIDE_LIKE_THE_WIND = rage::joaat("NET_PLAYER_ABILITY__RIDE_LIKE_THE_WIND"),
	FOOL_ME_ONCE = rage::joaat("NET_PLAYER_ABILITY__FOOL_ME_ONCE"),
	GUNSLINGERS_CHOICE = rage::joaat("NET_PLAYER_ABILITY__GUNSLINGERS_CHOICE"),
	COME_BACK_STRONGER = rage::joaat("NET_PLAYER_ABILITY__COME_BACK_STRONGER"),
	WINNING_STREAK = rage::joaat("NET_PLAYER_ABILITY__WINNING_STREAK"),
	KICK_IN_THE_BUTT = rage::joaat("NET_PLAYER_ABILITY__KICK_IN_THE_BUTT"),
	PEAK_CONDITION = rage::joaat("NET_PLAYER_ABILITY__PEAK_CONDITION"),
	THE_SHORT_GAME = rage::joaat("NET_PLAYER_ABILITY__THE_SHORT_GAME"),
	OVERRIDE_REVENGE_SLOW_TIME = rage::joaat("NET_PLAYER_ABILITY__OVERRIDE_REVENGE_SLOW_TIME"),
	IRON_LUNG = rage::joaat("NET_PLAYER_ABILITY__IRON_LUNG"),
	THE_UNBLINKING_EYE = rage::joaat("NET_PLAYER_ABILITY__THE_UNBLINKING_EYE"),
	INVALID = 0,
	FRIENDS_FOR_LIFE = rage::joaat("NET_PLAYER_ABILITY__FRIENDS_FOR_LIFE"),
	NEVER_WITHOUT_ONE = rage::joaat("NET_PLAYER_ABILITY__NEVER_WITHOUT_ONE"),
	OF_SINGLE_PURPOSE = rage::joaat("NET_PLAYER_ABILITY__OF_SINGLE_PURPOSE"),
	A_MOMENT_TO_RECUPERATE = rage::joaat("NET_PLAYER_ABILITY__A_MOMENT_TO_RECUPERATE"),
	SLIPPERY_BASTARD = rage::joaat("NET_PLAYER_ABILITY__SLIPPERY_BASTARD"),
	PAINT_IT_BLACK = rage::joaat("NET_PLAYER_ABILITY__PAINT_IT_BLACK"),
	TAKE_THE_PAIN_AWAY = rage::joaat("NET_PLAYER_ABILITY__TAKE_THE_PAIN_AWAY"),
	EYE_FOR_AN_EYE = rage::joaat("NET_PLAYER_ABILITY__EYE_FOR_AN_EYE"),
	COLD_BLOODED = rage::joaat("NET_PLAYER_ABILITY__COLD_BLOODED"),
	HUNKER_DOWN = rage::joaat("NET_PLAYER_ABILITY__HUNKER_DOWN"),
	QUITE_AN_INSPIRATION = rage::joaat("NET_PLAYER_ABILITY__QUITE_AN_INSPIRATION"),
	TO_FIGHT_ANOTHER_DAY = rage::joaat("NET_PLAYER_ABILITY__TO_FIGHT_ANOTHER_DAY"),
	HORSEMAN = rage::joaat("NET_PLAYER_ABILITY__HORSEMAN"),
	LIVE_FOR_THE_FIGHT = rage::joaat("NET_PLAYER_ABILITY__LIVE_FOR_THE_FIGHT"),
	HANGMAN = rage::joaat("NET_PLAYER_ABILITY__HANGMAN"),
	STRENGTH_IN_NUMBERS = rage::joaat("NET_PLAYER_ABILITY__STRENGTH_IN_NUMBERS"),
	SLOW_AND_STEADY = rage::joaat("NET_PLAYER_ABILITY__SLOW_AND_STEADY"),
	LANDONS_PATIENCE = rage::joaat("NET_PLAYER_ABILITY__LANDONS_PATIENCE"),
	SHARPSHOOTER = rage::joaat("NET_PLAYER_ABILITY__SHARPSHOOTER")
};

enum class OutfitTheme
{
	NONE,
	CITY,
	RUGGED,
	MAX
};

enum class ClothingFlag
{
	IS_ANIMAL
};

struct METAPED_PLAYER_CLOTHING_DATA
{
	SCR_HASH                 Model;
	SCR_INT                  PAD_0001;
	alignas(8) OutfitTheme   GangOutfitTheme;
	SCR_HASH                 Outfit;
	SCR_HASH                 OverrideOutfit; // or mission outfit
	SCR_HASH                 HeadItem;
	SCR_HASH                 FacialHairItem;
	SCR_HASH                 HairItem;
	SCR_HASH                 EyesItem;
	SCR_HASH                 TeethItem;
	SCR_BITSET<ClothingFlag> Flags;
};
static_assert(sizeof(METAPED_PLAYER_CLOTHING_DATA) == 11 * 8);

struct ABILITY_EQUIP_DATA
{
	alignas(8) AbilityType Type;
	SCR_INT                Tier;
	SCR_INT                PAD_0002;
};

struct HONOR_INFO
{
	SCR_INT GrossHonor;
	SCR_INT HonorLevel; // not sure how these values are different, if at all
};

// WARNING: many of these fields are overwritten every tick
struct PLAYER_PERSONA_DATA_ENTRY
{
	SCR_INT                          Rank;
	GAMER_HANDLE                     Handle;
	HONOR_INFO                       HonorInfo;
	SCR_ARRAY<ABILITY_EQUIP_DATA, 4> Abilities;
	METAPED_PLAYER_CLOTHING_DATA     ClothingData;
	SCR_FLOAT                        DistanceMultiplier; // unknown usage
};
static_assert(sizeof(PLAYER_PERSONA_DATA_ENTRY) == 30 * 8);

struct PLAYER_PERSONA_DATA
{
	SCR_ARRAY<PLAYER_PERSONA_DATA_ENTRY, 32> Entries;
};
static_assert(sizeof(PLAYER_PERSONA_DATA) == 961 * 8);