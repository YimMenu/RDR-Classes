#pragma once
#include "fwRefAwareBase.hpp"

namespace rage
{
    class fwExtensibleBase : public fwRefAwareBase
    {
    public:
        void* m_extension_container; // 0x0010
        void* m_extensible_unk; // 0x0018
    }; //Size: 0x0020
    static_assert(sizeof(fwExtensibleBase) == 0x20);
}
