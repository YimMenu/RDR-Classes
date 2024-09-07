#pragma once

#include <cstdint>
#include <string_view>

#include "rage/atArray.hpp"

class CTrainCarriageInfo
{
public:
	uint32_t m_ModelName;
	uint32_t _0x5E64EA3E;
	uint32_t _0xE2BDEA7B;
	uint32_t _0xECA6D302;
	uint32_t _0xFBF5C716;
	float _0x46B81FF8;
	float _0xEC4633A5;
	uint _0x535A0BBE;
	uint m_ModelId;
	int m_Extras;
	bool _0x153918B6;
	bool _0x88A76D74;
	bool _0xC77853E4;
	uint8_t m_TintPreset;
};
static_assert(sizeof(CTrainCarriageInfo) == 0x2C);

class CTrainConfigRef
{
public:
	uint32_t m_TrainConfigName;
	uint8_t _0x07E33620;
};
static_assert(sizeof(CTrainConfigRef) == 0x8);

class CTrainConfig
{
public:
	uint32_t m_Name;
	float _0x0ED29061;
	float _0xE43D854D;
	float _0x72443177;
	float _0xA50FC0EB;
	bool _0xFD90C5F8;
	bool _0x0546B416;
	bool _0xD41F8E7D;
	bool m_CarriagesSwing;
	bool _0xEDD766A7;
	bool _0xDB277834;
	bool m_NoRandomSpawn;
	bool m_NoDriver;
	float m_CarriageGap;
	rage::atArray<CTrainCarriageInfo> m_Carriages;
	uint32_t _0xA400A33A;
	float m_DefaultMaxSpeed;
	float m_MaxAcceleration;
	float m_MaxDeceleration;
	bool m_IsTram;
};
static_assert(sizeof(CTrainConfig) == 0x48);

class CTrainConfigGroup
{
public:
	uint32_t m_Name;
	rage::atArray<CTrainConfigRef> m_Refs;
};
static_assert(sizeof(CTrainConfigGroup) == 0x18);

class CTrainConfigs
{
public:
	rage::atArray<CTrainConfig> m_TrainConfigs;
	rage::atArray<CTrainConfigGroup> m_TrainGroups;
};