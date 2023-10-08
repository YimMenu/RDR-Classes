#pragma once
#include "netGameEvent.hpp"
#include "script/scriptId.hpp"
#include "rage/atPlayerBits.hpp"

#pragma pack(push, 8)
class CScriptedGameEvent : public rage::netGameEvent
{
public:
	CGameScriptId m_ScriptId;          // 0x38
	int m_DataSize;                    // 0x60
	bool m_Unk;                        // 0x64 (netComponent && *(netComponent + 0x16C) == 32)
	bool m_ScriptIdOverridden;         // 0x65
	bool m_HasScriptMetadataIdx;       // 0x66
	std::uint64_t m_Data[54];          // 0x68
	rage::atPlayerBits m_ReceiverBits; // 0x218
	int m_ScriptMetadataIndex;         // 0x21C
	int m_ScriptHash;                  // 0x220
	int16_t m_Status;                  // 0x224
};
#pragma pack(pop)
static_assert(sizeof(CScriptedGameEvent) == 0x228);