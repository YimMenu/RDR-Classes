#pragma once

#include "rlGamerHandle.hpp"

namespace rage 
{
    class rlPlatformPartyMember
    {
    public:
        virtual void Clear() noexcept = 0;
        virtual bool IsInSession() const noexcept { return false; }
        virtual const char* GetDisplayName() const noexcept { return m_displayName; }
        rlGamerHandle* GetGamerHandle(rlGamerHandle* handle) const noexcept {
            if (handle) {
                handle->m_RockstarId = 0;
                handle->m_UnkData = 0;
                handle->m_Platform = 0;
            }
            return handle;
        }
        /*
        rlSessionInfo* GetSessionInfo(rlSessionInfo* info) const noexcept {
            if (info) {
                info->Clear();
            }
            return info;
        }
        */
    private:
        const char* m_displayName = "DefaultName";
    };

    class rlPlatformParty 
    {
    public:
        virtual ~rlPlatformParty() = default;
        virtual int ShowPartyUi(int uiMode) const { return 0; }
        virtual int GetPartySize() const { return 0; }
        virtual void GetPartyMembers(rlPlatformPartyMember* partyMembers, unsigned int memberCount) const = 0;
        virtual bool IsInPlatformParty() { return false; }
        virtual void ShowPartyInvitesUi(int inviteType) const = 0;
        virtual bool IsInPlatformPartyChat() { return false; }
        virtual bool IsPlatformPartyMember(const rlGamerHandle& gamerHandle) const noexcept { return false; }
        virtual void EnableGameReadyNotifications() noexcept = 0;
        virtual void DisableGameReadyNotifications() noexcept = 0;
        virtual bool GetMember(int memberIndex, rlPlatformPartyMember* member) noexcept { return false; }
    };
}