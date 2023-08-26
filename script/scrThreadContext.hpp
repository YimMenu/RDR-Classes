#pragma once
#include <cstdint>

#include "../rage/joaat.hpp"

namespace rage
{
    enum class eThreadState : std::uint32_t
    {
        idle,
        running,
        killed,
        unk_3,
        unk_4,
    };

    class scrThreadContext
    {
    public:
        std::uint32_t m_ThreadId;            // 0x00
        joaat_t m_ScriptHash;                // 0x04
        eThreadState m_State;                // 0x08
        std::uint32_t m_ProgramCounter;      // 0x0C
        std::uint32_t m_FramePointer;        // 0x10
        std::uint32_t m_StackPointer;        // 0x14
        float m_TimerA;                      // 0x18
        float m_TimerB;                      // 0x1C
        float m_TimerC;                      // 0x20
        char m_padding1[0x2C];               // 0x24
        std::uint32_t m_StackSize;           // 0x50
        uint32_t m_SetjmpPC;                 // 0x54
        uint32_t m_SetjmpFrame;              // 0x58
        uint32_t m_SetjmpStack;              // 0x5C
        uint32_t m_SetjmpUnk;                // 0x60
        uint32_t m_StackFrameCount;          // 0x64 actually used in RDR2
        uint32_t m_StackFrames[16];          // 0x68
        void* m_SecureFrames[96];            // 0xA8
        void* m_SecureStatics[96];           // 0x3A8
        void* m_UnkSecureVar;                // 0x6A8
    };
    static_assert(sizeof(scrThreadContext) == 0x6B0);
}