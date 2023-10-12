#pragma once

namespace rage
{
    union scrValue
    {
        int m_Int;
        unsigned int m_Uns;
        float m_Float;
        const char* m_String;
        scrValue* m_reference;
        unsigned long long m_Any;
        bool operator==(const scrValue& value) {
			return m_Int == value.m_Int;
		}        
    };
}