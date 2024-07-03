#pragma once
#include "CNetGamePlayer.hpp"
#include "netObject.hpp"
#include "rage/datBitBuffer.hpp"

#include <cstdint>

#pragma pack(push, 8)
class CNetworkObjectMgr 
{
public:
  virtual ~CNetworkObjectMgr() = default;
  virtual void _0x8() = 0;
  virtual void Initialize() = 0; // 0x10
  virtual void Shutdown() = 0;
  virtual void Update(bool) = 0;
  virtual void AddEntity(void *, void *) = 0;
  virtual void UnregisterNetworkObject_(void *unk, bool force) = 0;
  virtual void UnregisterNetworkObject(rage::netObject *object, int reason, bool force1, bool force2) = 0;
  virtual void ChangeOwner(rage::netObject *object, CNetGamePlayer *player, int migrationType, bool unk) = 0;
  virtual void HandleJoiningPlayer(CNetGamePlayer *player) = 0;
  virtual void HandleLeavingPlayer(CNetGamePlayer *player) = 0;
  virtual void _0x50(CNetGamePlayer *player) = 0;
  virtual void _0x58() = 0;
  virtual void _0x60() = 0;
  virtual int _0x68() = 0;
  virtual void RegisterNetworkObject(rage::netObject *object) = 0;
  virtual void PackCloneCreate(rage::netObject *object, CNetGamePlayer *player, rage::datBitBuffer *buffer) = 0;
  virtual bool PackCloneRemove(rage::netObject *object, CNetGamePlayer *player, bool) = 0;
  virtual void PackCloneSync(rage::netObject *object, CNetGamePlayer *player) = 0;
};
#pragma pack(pop)