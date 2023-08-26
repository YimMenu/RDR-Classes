#pragma once
#include <cstdint>

namespace rage
{
	class rlGamerInfo;
	class netPlayer
	{
	public:
		virtual ~netPlayer() = default;                                   // 0x00
		virtual void Initialize(void* unk, int message_id, int unk2) {};  // 0x08
		virtual void Initialize2(int unk) {};                             // 0x10
		virtual void Reset() {};                                          // 0x18
		virtual bool IsValid() { return false; };                         // 0x20
		virtual const char* GetName() { return nullptr; };                // 0x28
		virtual void* GetUnk() { return nullptr; };                       // 0x30
		virtual void SetTeam(int new_team) {};                            // 0x38
		virtual bool IsSameTeam(netPlayer* other) { return false; };      // 0x40
		virtual void _0x48() {};                                          // 0x48 some posse stuff
		virtual void RefreshData() {};                                    // 0x50
		virtual bool IsHost() { return true; };                           // 0x58
		virtual rage::rlGamerInfo* GetGamerInfo() { return nullptr; };    // 0x60

		char pad_0008[12]; //0x0008
		uint32_t m_MessageId; //0x0014
		uint8_t m_ActiveIndex; //0x0018
		uint8_t m_PlayerIndex; //0x0019
		char pad_001A[10]; //0x001A
		uint32_t m_JoinTime; //0x0024
		char pad_0028[4]; //0x0028
		uint32_t m_Team; //0x002C
		char pad_0030[248]; //0x0030
	}; //Size: 0x0128
	static_assert(sizeof(rage::netPlayer) == 0x128);
}