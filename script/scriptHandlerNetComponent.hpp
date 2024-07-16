#pragma once

class CNetGamePlayer;

class CScriptParticipant 
{
public:
  char m_Pad[16];                       // 0x0000
  class CNetGamePlayer *m_NetGamePlayer; // 0x0010
  char m_Pad2[2];                        // 0x0018
  int16_t m_ParticipantIndex;             // 0x001A
  char m_Pad3[12];                       // 0x001C
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
  virtual bool _0x08(void *) = 0;
  virtual void _0x10(CNetGamePlayer *) = 0;
  virtual void *HandlePlayerLeft(CNetGamePlayer *player) = 0;
  virtual void *SendHostMigrationEvent(CNetGamePlayer *player) = 0;
  virtual void PlayerJoined(void **, void *msg_ctx) = 0;
  virtual void PlayerJoinedAck(void **, void *msg_ctx) = 0;
  virtual void PlayerJoinedHostAck(void *, void *) = 0;
  virtual void *_0x40(void *, void *) = 0;
  virtual void *_0x48(void *, void *, void *) = 0;
  virtual void *_0x50(void *, void *) = 0;
  virtual void *_0x58(void *, void *) = 0;
  virtual void *_0x60(void *, void *) = 0;
  virtual void *_0x68(void *, void *) = 0;
  virtual void _0x70(void *, void *) = 0;
  virtual void _0x78(void *, void *) = 0;
  virtual short _0x80(void *, void *) = 0;
  virtual void *_0x88(void *, void *) = 0;
  virtual void *_0x90(void *, void *) = 0;
  virtual bool _0x98(void *, void *) = 0;
  virtual void *_0xA0(void *, void *) = 0;
  virtual void *_0xA8(void *, void *) = 0;
  virtual short _0xB0(void *, void *) = 0;
  virtual short _0xB8(void *, void *) = 0;
  virtual short _0xC0(void *, void *) = 0;
  virtual bool RegisterHostBroadcastData(void *data, int size, char *a3) = 0;
  virtual bool RegisterPlayerBroadcastData(int a1, int size, bool a3) = 0;
  virtual bool CanStartJoining() = 0;
  virtual bool _0xE0() = 0;
  virtual bool AddPlayerToScript(CNetGamePlayer *player,
                                 short *out_participant_id,
                                 short *out_slot_number,
                                 int *out_fail_reason) = 0;
  virtual bool AddPlayerToScriptImpl(CNetGamePlayer *player,
                                     short participant_id,
                                     short slot_number) = 0;
  virtual bool RemovePlayerFromScript(CNetGamePlayer *player) = 0;
  virtual void *PlayerLeftImpl(CNetGamePlayer *, bool) = 0;
  virtual bool DoHostMigration(CNetGamePlayer *player, short host_token,
                               bool unk) = 0;
  virtual void *LeaveFromScript() = 0;

public:
  scriptHandler *m_ScriptHandler;         // 0x08
  char m_Pad[0x20];                       // 0x10
  CScriptParticipant *m_Host;             // 0x30
  std::uint8_t m_LocalParticipantId;      // 0x38
  void *m_Pad2[4];                        // 0x40
  CScriptParticipant *m_Participants[32]; // 0x60
  int m_Pad3[3];                          // 0x160
  std::uint8_t m_NumParticipants;         // 0x168

  inline CNetGamePlayer *GetHost() const 
  {
    if (!m_Host)
      return nullptr;

    return m_Host->m_NetGamePlayer;
  }
};
static_assert(sizeof(rage::scriptHandlerNetComponent) == 0x170);
}
#pragma pack(pop)