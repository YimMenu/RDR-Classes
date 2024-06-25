#pragma once
#include <cstdint>

namespace rage 
{
#pragma pack(push, 8)
class InFrame 
{
public:
  enum class EventType 
  {
    ConnectionClosed = 4,
    FrameReceived = 5,
    BandwidthExceeded = 6,
    OutOfMemory = 7
  };

  virtual ~InFrame() = default;

  virtual void Destroy() = 0;
  virtual EventType GetEventType() = 0;
  virtual uint32_t _0x18() = 0;

  char pad_0[0x70];  // 0x8
  uint32_t m_Length; // 0x78
  void *m_Data;      // 0x80
};
#pragma pack(pop)
}