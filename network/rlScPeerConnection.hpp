#pragma once
#include "snConnectToPeerTask.hpp"
#include "rlGamerHandle.hpp"
#include "rlGamerInfoBase.hpp"
#include "rage/rlTaskStatus.hpp"
#include "rage/atDelegate.hpp"

namespace rage
{
	class netConnectionManager;
	class rlScSessionPeer;

	class rlScPeerConnection
	{
	public:
		rage::atDelegate m_ConnectionSuccessful;
		rage::atDelegate m_ConnectionFailed;
		int m_State;
		int dword28;
		rage::snConnectToPeerTaskData m_ConnectToPeerData;
		rage::rlGamerInfoBase m_PeerAddress;
		rage::netConnectionManager* m_NetConnectionManager;
		char m_Unk[56];
		rage::rlScSessionPeer* m_Peer;
		rage::rlTaskStatus m_TaskStatus;
		rage::snConnectToPeerTaskResult m_ConnectToPeerResult;
		int m_ConnectionMsgSize;
		char m_ConnectionMsgData[256];
		int m_MessageId;
		char gap590[8];
		int m_ConnectionId;
		int dword59C;
	};
	static_assert(sizeof(rlScPeerConnection) == 0x5A0);
}