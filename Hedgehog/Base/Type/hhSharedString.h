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

        CSharedString(const CSharedString& in_rOther)
            : m_data(in_rOther.m_data)
        {

        }

        CSharedString(CSharedString&& io_rOther)
            : m_data(std::move(io_rOther.m_data))
        {
        }

        CSharedString(const char* in_pData)
        {
            m_data.Set(in_pData, in_pData ? strlen(in_pData) : 0);
        }

        const char* c_str() const
        {
            return m_data.Get();
        }

        int compare(const CSharedString& in_rOther) const
        {
            return fpCSharedStringCompare(this, in_rOther);
        }

        CSharedString& operator=(const char* in_pOther)
        {
            m_data.Unset();
            m_data.Set(in_pOther, in_pOther ? strlen(in_pOther) : 0);
            return *this;
        }

        CSharedString& operator=(const CSharedString& in_rOther)
        {
            m_data = in_rOther.m_data;
            return *this;
        }        

        CSharedString& operator=(CSharedString&& io_rOther)
        {
            m_data = std::move(io_rOther.m_data);
            return *this;
        }

        bool operator>(const CSharedString& in_rOther) const
        {
            return compare(in_rOther) > 0;
        }

        bool operator>=(const CSharedString& in_rOther) const
        {
            return compare(in_rOther) >= 0;
        }

        bool operator<(const CSharedString& in_rOther) const
        {
            return compare(in_rOther) < 0;
        }

        bool operator<=(const CSharedString& in_rOther) const
        {
            return compare(in_rOther) <= 0;
        }

        bool operator==(const CSharedString& in_rOther) const
        {
            return compare(in_rOther) == 0;
        }              
        
        bool operator!=(const CSharedString& in_rOther) const
        {
            return !(*this == in_rOther);
        }

        bool operator==(const char* in_pOther) const
        {
            return strcmp(c_str(), in_pOther) == 0;
        }       
        
        bool operator!=(const char* in_pOther) const
        {
            return !(*this == in_pOther);
        }
    };

    BB_ASSERT_SIZEOF(CSharedString, 0x4);
}