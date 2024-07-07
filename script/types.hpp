#pragma once
#include <cstdint>
#include "scrVector.hpp"

#ifndef BOOL
#define BOOL int
#endif

using Vector3 = rage::scrVector;
typedef int Void;
typedef int Any;
typedef int uint;
typedef int Hash;
typedef int Entity;
typedef int Player;
typedef int FireId;
typedef int Ped;
typedef int Vehicle;
typedef int Cam;
typedef int CarGenerator;
typedef int Group;
typedef int Train;
typedef int Pickup;
typedef int Object;
typedef int Weapon;
typedef int Interior;
typedef int Blip;
typedef int Texture;
typedef int TextureDict;
typedef int CoverPoint;
typedef int Camera;
typedef int TaskSequence;
typedef int ColourIndex;
typedef int Sphere;
typedef int INT, ScrHandle;
typedef int AnimScene;
typedef int Volume;
typedef int ItemSet;
typedef int PropSet;
typedef int PopZone;
typedef int PersChar;
typedef int Prompt;

#define PLAYER_INDEX alignas(8) int
#define ENTITY_INDEX alignas(8) int
#define PED_INDEX alignas(8) int
#define PICKUP_INDEX alignas(8) int
#define VEHICLE_INDEX alignas(8) int
#define INTERIOR_INDEX alignas(8) int
#define NETWORK_INDEX alignas(8) int

#define SCR_HASH alignas(8) Hash
#define SCR_INT alignas(8) int
#define SCR_BOOL alignas(8) BOOL
#define SCR_FLOAT alignas(8) float
#define SCR_VEC3 Vector3

template <int SIZE>
struct SCR_TEXT_LABEL
{
	alignas(8) char Data[SIZE];
public:
	operator char* () { return Data; }
};

#define TEXT_LABEL_15 SCR_TEXT_LABEL<16>
#define TEXT_LABEL_23 SCR_TEXT_LABEL<24>
#define TEXT_LABEL_31 SCR_TEXT_LABEL<32>
#define TEXT_LABEL_63 SCR_TEXT_LABEL<64>

template <typename T, int SIZE>
struct SCR_ARRAY
{
	SCR_INT      Size;
	alignas(8) T Data[SIZE];

	T& operator [](int index)
	{
		return Data[index];
	}
};

template <typename T>
struct SCR_BITSET
{
	alignas(8) int Value;

	bool IsSet(T val)
	{
		return Value & (1 << (int)val);
	}

	void Set(T val)
	{
		Value |= (1 << (int)val);
	}

	void Clear(T val)
	{
		Value &= ~(1 << (int)val);
	}
};

/// This is very untested, beware!
/// MODULUS should be 32 for maximum efficiency but most Rockstar scripts use 31
template <typename T, int COUNT, int MODULUS = 31, int SIZE = (COUNT / MODULUS) + 1>
struct SCR_BITSET_LARGE
{
	SCR_ARRAY<uint64_t, SIZE> Array;

	bool IsSet(T val)
	{
		return Array[(int)val / MODULUS] & (1 << ((int)val % MODULUS));
	}

	void Set(T val)
	{
		Array[(int)val / MODULUS] |= (1 << ((int)val % MODULUS));
	}

	void Clear(T val)
	{
		Array[(int)val / MODULUS] &= ~(1 << ((int)val % MODULUS));
	}
};

struct SCR_DATE
{
	SCR_INT Year;
	SCR_INT Month;
	SCR_INT Day;
	SCR_INT Hour;
	SCR_INT Minute;
	SCR_INT Second;
	SCR_INT Millisecond;
};

struct SCR_GUID
{
	SCR_INT Element1;
	SCR_INT Element2;
};

struct Color3
{
	SCR_INT R;
	SCR_INT G;
	SCR_INT B;
};
static_assert(sizeof(Color3) == 3 * 8);

// serialized bitbuffer data of rage::rlGamerHandle
struct GAMER_HANDLE
{
private:
	uint64_t Data[2];
};
static_assert(sizeof(GAMER_HANDLE) == 2 * 8);