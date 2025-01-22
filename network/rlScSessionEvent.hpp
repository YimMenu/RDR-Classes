#pragma once
#include "rage/atUri.hpp"
#include "rlGamerHandle.hpp"
#include "rlGamerInfoBase.hpp"
#include "rlScSession.hpp"


#pragma pack(push, 8)
namespace rage {
enum class SessionEvent : std::uint32_t {
  LEAVE_SESSION = 6,
  ADD_PLAYER = 7,
  REMOVE_PLAYER = 8,
  HOST_CHANGED = 9,
  QUEUE_ERROR = 17,
  LOCALIZED_MESSAGE = 19,
  CONFIG_PARAM = 20,
  INVITE_RESULT = 21,
  INVITE_QUEUED = 22,
  TRANSITION_READY_INVITE = 28,
  TRANSITION_READY_PLAYER_QUEUE = 29,
  KEEP_ALIVE_REQUEST = 30,
  COMPLAINT_RECEIVED = 31,
  QUEUE_ENTERED = 32,
  PREPARE_SERVER_TRANSFER = 33,
  SERVER_TRANSFER_RESULT = 34,
  TRANSITION_READY_SERVER_TRANSFER = 35,
  TRANSFER_TO_SERVER = 36,
  PAUSE_FOR_SERVER_TRANSFER = 37,
  ADMIN_SECURITY_INVITE = 38
};

class rlScSessionEvent {
public:
  virtual ~rlScSessionEvent() = default;

  SessionEvent m_EventType;

  template <typename T> inline T *As() { return (T *)this; }
};
static_assert(sizeof(rage::rlScSessionEvent) == 0x10);

class rlScLeaveSessionEvent : public rlScSessionEvent {
public:
  rage::rlScSessionId m_SessionId;
  int m_Reason;
  int m_Reason2;
  int m_PlayerCount;
};
static_assert(sizeof(rage::rlScLeaveSessionEvent) == 0x30);

class rlScAddPlayerEvent : public rlScSessionEvent {
public:
  rage::rlScSessionId m_SessionId;
  rage::rlScSessionPeerIdentifier m_Identifier;
  rage::rlGamerInfoBase m_PeerAddress;
};
static_assert(sizeof(rage::rlScAddPlayerEvent) == 0xD0);

class rlScRemovePlayerEvent : public rlScSessionEvent {
public:
  rage::rlScSessionId m_SessionId;
  rage::rlScSessionPeerIdentifier m_Identifier;
};
static_assert(sizeof(rage::rlScRemovePlayerEvent) == 0x38);

class rlScHostChangedEvent : public rlScSessionEvent {
public:
  rage::rlScSessionId m_SessionId;
  int m_OldIndex;
  int m_NewIndex;
};
static_assert(sizeof(rage::rlScHostChangedEvent) == 0x28);

class rlScComplaintReceivedEvent : public rlScSessionEvent {
public:
  rage::rlGamerHandle m_Complainer;
};
static_assert(sizeof(rage::rlScComplaintReceivedEvent) == 0x20);

class rlScQueueEnteredEvent : public rlScSessionEvent {
public:
  rage::rlScSessionRequestId m_RequestId;
  int m_QueueGroup;
  int m_OptionFlags;
};
static_assert(sizeof(rage::rlScQueueEnteredEvent) == 0x28);

class rlScQueueErrorEvent : public rlScSessionEvent {
public:
  rage::rlScSessionRequestId m_RequestId;
  int m_Reason;
};
static_assert(sizeof(rage::rlScQueueErrorEvent) == 0x28);

// not rlScLocalizedMessageEvent
class rlScLocalizedMessage : public rlScSessionEvent {
public:
  char m_Key[128];
};
static_assert(sizeof(rage::rlScLocalizedMessage) == 0x90);

class rlScConfigParamEvent : public rlScSessionEvent {
public:
  int m_NameHash; // TODO: reverse this
  char m_Value[32];
};
static_assert(sizeof(rage::rlScConfigParamEvent) == 0x38);

class rlScAdminSecurityInviteEvent : public rlScSessionEvent {
public:
  rage::rlGamerHandle m_Handle;
  int m_InviteId;
  int m_Flags;
  rage::atUri m_ServerUri;
  int m_SessionType;
};
static_assert(sizeof(rage::rlScAdminSecurityInviteEvent) == 0x4B8);
} // namespace rage
#pragma pack(pop)