#pragma once
#include <cstdint>

namespace rage {

class pgBase {
public:
    virtual void ShutdownClass() = 0;
    virtual void SetHandleIndex(uint32_t index) = 0;
    virtual void Validate(uint32_t arg) = 0;
    virtual void InitClass(int arg) = 0;
    virtual uint32_t GetHandleIndex() const { return 0; }

    uintptr_t LookupMetaData(uint32_t index) const {
        uintptr_t current = reinterpret_cast<uintptr_t>(this);

        uintptr_t nextPage = *reinterpret_cast<uintptr_t*>(current + 8);
        if (nextPage == 0)
            return 0;

        uint8_t pageStatus = *reinterpret_cast<uint8_t*>(nextPage + 11);
        if (pageStatus == 0)
            return 0;

        uintptr_t* metadataStart = reinterpret_cast<uintptr_t*>(nextPage + 16);
        uintptr_t metadataCount = *reinterpret_cast<uintptr_t*>(nextPage + 24);

        for (uintptr_t i = 0; i < metadataCount; ++i) {
            uintptr_t currentMeta = *(metadataStart + i);

            uint32_t metaIndex = *reinterpret_cast<uint32_t*>(currentMeta + 8);
            if (metaIndex == index) {
                return currentMeta;
            }
        }

        return 0;
    }

    bool HasPageMap() const {
        uintptr_t nextPage = *reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(this) + 8);
        if (nextPage == 0)
            return false;

        uint8_t pageStatus = *reinterpret_cast<uint8_t*>(nextPage + 11);
        if (pageStatus == 0)
            return false;

        nextPage = 0;
        bool hasPageMap = (nextPage != 0);

        return hasPageMap;
    }

    bool MapContainsPointer(void* ptr) const {
        uintptr_t basePage = reinterpret_cast<uintptr_t>(this);
        uintptr_t nextPage = *reinterpret_cast<uintptr_t*>(basePage + 8);
        if (nextPage == 0)
            return false;

        uint8_t pageStatus = *reinterpret_cast<uint8_t*>(nextPage + 11);
        if (pageStatus == 0)
            return false;

        uintptr_t* data = reinterpret_cast<uintptr_t*>(nextPage + 16);
        uintptr_t count = *reinterpret_cast<uintptr_t*>(nextPage + 8);

        for (uintptr_t i = 0; i < count; ++i) {
            uintptr_t elementPage = *(data + i);
            if (elementPage >= reinterpret_cast<uintptr_t>(ptr) && elementPage < reinterpret_cast<uintptr_t>(ptr) + 24) {
                return true;
            }
        }

        return false;
    }

private:
    uint32_t m_map_size;
};

class pgBaseRefCounted : public pgBase {
public:
    virtual ~pgBaseRefCounted() = default;
};

class pgBaseMetaDataType {
public:
    static pgBaseMetaDataType* m_first;

    pgBaseMetaDataType(uint32_t id, uintptr_t value)
        : m_id(id), m_value(value), m_next(nullptr) {
        if (!m_first) {
            m_first = this;
        }
    }

    ~pgBaseMetaDataType() {
        if (m_first == this) {
            m_first = m_next;
        } else {
            pgBaseMetaDataType* current = m_first;
            while (current && current->m_next != this) {
                current = current->m_next;
            }
            if (current) {
                current->m_next = m_next;
            }
        }
    }

    static pgBaseMetaDataType* Lookup(uint32_t id) {
        pgBaseMetaDataType* current = m_first;
        while (current != nullptr) {
            if (current->m_id == id) {
                return current;
            }
            current = current->m_next;
        }
        return nullptr;
    }

private:
    uint32_t m_id;
    uintptr_t m_value;
    pgBaseMetaDataType* m_next;
};

}