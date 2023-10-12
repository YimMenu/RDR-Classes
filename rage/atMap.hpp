#pragma once

namespace rage
{
    template <typename T, typename Flag>
    struct atMapMemory 
    {
        T m_value;
        Flag m_flag;
        atMapMemory() : m_value(), m_flag() {}
        atMapMemory(T val, Flag fla) : m_value(val), m_flag(fla) {}
    };

    template <typename T>
    struct atMapEquals 
    {
        bool operator()(const T& a, const T& b) const 
        {
            return a == b;
        }
    };

    template <typename T>
    struct atMapHashFn 
    {
        size_t operator()(const T& key) const {
            size_t hash = 0;
            size_t seed = 131; 
            const char* data = reinterpret_cast<const char*>(&key);
            while (*data) {
                hash = (hash * seed) + (*data);
                ++data;
            }
            return hash;
        }
    };

    template <typename T, typename data>
    struct atMapEntry
    {
        T m_key;
        data m_data;
        atMapEntry* m_next;
        atMapEntry(const T& key, const data& datas) : m_key(key), m_data(datas), m_next(nullptr) {}
    };

    template <typename Key, typename Value, typename HashFn, typename Equals, typename Memory>
    struct atMap 
    {
        atMapEntry<Key, Value>** m_Hash;
        unsigned short m_Slots;
        unsigned short m_Used;
        HashFn m_HashFn;
        Equals m_Equals;
        Memory m_Memory;
        unsigned char m_AllowReCompute;
        atMap(unsigned short slots, HashFn hashFn, Equals equals, Memory memory, unsigned char allowReCompute)
            : m_Slots(slots), m_HashFn(hashFn), m_Equals(equals), m_Memory(memory), m_AllowReCompute(allowReCompute) {
            m_Used = 0;
        }
    };
}