#pragma once

class CNetGamePlayer;

class CScriptParticipant
{
public:
    char pad_0000[16];                      //0x0000
    class CNetGamePlayer* m_net_game_player;//0x0010
    char pad_0018[2];                       //0x0018
    int16_t m_participant_index;            //0x001A
    char pad_001C[12];                      //0x001C
}; 
static_assert(sizeof(CScriptParticipant) == 0x28);

#pragma pack(push, 8)
namespace rage
{
    class scriptHandler;
    class scriptHandlerNetComponent
    {
    public:
        virtual ~scriptHandlerNetComponent() = default;
        virtual bool _0x08(void*) = 0;
        virtual void _0x10(CNetGamePlayer*) = 0;
        virtual void* HandlePlayerLeft(CNetGamePlayer* player) = 0;
        virtual void* SendHostMigrationEvent(CNetGamePlayer* player) = 0;

    public:
        scriptHandler* m_ScriptHandler;         // 0x08
        char m_Pad[0x28];                       // 0x10
        std::uint8_t m_LocalParticipantId;      // 0x38
        void* m_Pad2[4];                        // 0x40
        CScriptParticipant* m_Participants[32]; // 0x60
        int m_Pad3[3];                          // 0x160
        std::uint8_t m_NumParticipants;         // 0x168
    };
    static_assert(sizeof(rage::scriptHandlerNetComponent) == 0x170);
}
#pragma pack(pop)