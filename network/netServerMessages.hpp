#pragma once
#include <cstdint>

namespace rage 
{
class ServerRPCSerializer 
{
public:
  virtual int dtor() = 0;
  virtual int Unk() = 0;
  virtual void *GetData() = 0;
  virtual int GetSize() = 0;
};

class ServerMsgData 
{
public:
  unsigned char *data;
  int size;
  bool is_json;
};

class ServerMsg 
{
public:
  virtual ~ServerMsg() = default;
  virtual void _0x08() = 0;
  virtual void _0x10() = 0;
  virtual void _0x18() = 0;
  virtual void _0x20() = 0;
  virtual void _0x28() = 0;
  virtual void _0x30() = 0;
  virtual const char *GetName() = 0;
  virtual void _0x40() = 0;
  virtual void _0x48() = 0;
  virtual void _0x50() = 0;
  virtual void _0x58() = 0;
  virtual void _0x60() = 0;
  virtual void _0x68() = 0;
  virtual void _0x70() = 0;
  virtual ServerMsgData *GetMsgData() = 0;
};
}