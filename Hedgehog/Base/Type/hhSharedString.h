#pragma once

#include <Hedgehog/Base/Type/hhCowData.h>

namespace Hedgehog::Base
{
    class CSharedString;

    static inline BB_FUNCTION_PTR(int, __thiscall, fpCSharedStringCompare, 0x6618C0,
        const CSharedString* This, const CSharedString& other);

    class CSharedString
    {
    private:
        CCowData<char> m_data;

    public:
        CSharedString()
        {

        }

        CSharedString(const char* data)
        {
            m_data.Set(data, data ? strlen(data) : 0);
        }

        const char* c_str() const
        {
            return m_data.Get();
        }

        int compare(const CSharedString& other) const
        {
            return fpCSharedStringCompare(this, other);
        }

        CSharedString& operator=(const CSharedString& other)
        {
            m_data.Unset();
            m_data.Set(other.m_data);
            return *this;
        }        
        
        CSharedString& operator=(const char* other)
        {
            m_data.Unset();
            m_data.Set(other, other ? strlen(other) : 0);
            return *this;
        }

        bool operator>(const CSharedString& other) const
        {
            return compare(other) > 0;
        }

        bool operator>=(const CSharedString& other) const
        {
            return compare(other) >= 0;
        }

        bool operator<(const CSharedString& other) const
        {
            return compare(other) < 0;
        }

        bool operator<=(const CSharedString& other) const
        {
            return compare(other) <= 0;
        }

        bool operator==(const CSharedString& other) const
        {
            return compare(other) == 0;
        }              
        
        bool operator!=(const CSharedString& other) const
        {
            return !(*this == other);
        }

        bool operator==(const char* other) const
        {
            return strcmp(c_str(), other) == 0;
        }       
        
        bool operator!=(const char* other) const
        {
            return !(*this == other);
        }
    };

    BB_ASSERT_SIZEOF(CSharedString, 0x4);
}