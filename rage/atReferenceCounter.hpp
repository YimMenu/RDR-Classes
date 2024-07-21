#pragma once

#include <cstdint>
#include "base/datBase.hpp"

namespace rage {

    class atReferenceCounter : public datBase {
    public:
        atReferenceCounter() noexcept : m_referenceCount(0) {}

        virtual ~atReferenceCounter() noexcept {}

        atReferenceCounter(const atReferenceCounter&) = delete;
        atReferenceCounter& operator=(const atReferenceCounter&) = delete;

        atReferenceCounter(atReferenceCounter&&) = delete;
        atReferenceCounter& operator=(atReferenceCounter&&) = delete;

        void AddRef() const noexcept {
            ++m_referenceCount;
        }

        void Release() const noexcept {
            if (--m_referenceCount == 0) {
                delete this;
            }
        }
    private:
        mutable int32_t m_referenceCount;
    };
}