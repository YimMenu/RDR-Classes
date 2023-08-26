#pragma once
#include "scrThreadContext.hpp"

namespace rage
{
    class scrThread
    {
    public:
        virtual ~scrThread() = default;                                                                 // 0 (0x00)
        virtual void Reset(std::uint32_t script_hash, void* args, std::uint32_t arg_count) = 0;         // 1 (0x08)
        virtual eThreadState Run() = 0;                                                                 // 2 (0x10)
        virtual eThreadState Tick(std::uint32_t ops_to_execute) = 0;                                    // 3 (0x18)
        virtual void Kill() = 0;                                                                        // 4 (0x20)

    public:
        scrThreadContext m_Context;                 // 0x008
        void* m_Stack;                              // 0x6B8
        char m_padding[0x8];                        // 0x6C0
        uint32_t m_ArgsSize;                        // 0x6C8
        uint32_t m_ArgsPointer;                     // 0x6CC
        const char* m_ExitMessage;                  // 0x6D0
        char m_padding2[0x8];                       // 0x6D8
        void* m_Handler;                            // 0x6E0
        void* m_HandlerNetComponent;                // 0x6E8
    };
    static_assert(sizeof(rage::scrThread) == 0x6F0);
}