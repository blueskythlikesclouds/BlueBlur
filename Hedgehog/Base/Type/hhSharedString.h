#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Base
{
    class CSharedString;

    static inline BB_FUNCTION_PTR(int, __thiscall, fpCSharedStringCompare, 0x6618C0,
        const CSharedString* This, const CSharedString& in_rOther);

    class CSharedString
    {
    private:
        struct SStringHolder
        {
            union
            {
                struct
                {
                    uint16_t RefCount;
                    uint16_t Length;
                };

                size_t RefCountAndLength;
            };

            char aStr[1u];

            static SStringHolder* GetHolder(const char* in_pStr)
            {
                return (SStringHolder*)((size_t)in_pStr - sizeof(RefCountAndLength));
            }

            static size_t GetMemorySize(const size_t in_Length)
            {
                return sizeof(RefCountAndLength) + in_Length;
            }

            static size_t GetMemorySizeAligned(const size_t in_Length)
            {
                return (GetMemorySize(in_Length) + 0x10) & ~0xF;
            }

            static SStringHolder* Make(const char* in_pStr, const size_t in_Length)
            {
                const size_t memSize = GetMemorySize(in_Length);
                const size_t memSizeAligned = GetMemorySizeAligned(in_Length);

                SStringHolder* pHolder = (SStringHolder*)__HH_ALLOC(memSizeAligned);
                pHolder->RefCount = 1;
                pHolder->Length = (uint16_t)in_Length;

                if (in_pStr)
                    memcpy(pHolder->aStr, in_pStr, in_Length);

                memset(&pHolder->aStr[in_Length], 0, memSizeAligned - memSize);

                return pHolder;
            }

            static SStringHolder* Concat(
                const char* in_pStrA, const size_t in_LengthA,
                const char* in_pStrB, const size_t in_LengthB)
            {
                SStringHolder* pHolder = Make(nullptr, in_LengthA + in_LengthB);
                
                memcpy(pHolder->aStr, in_pStrA, in_LengthA);
                memcpy(&pHolder->aStr[in_LengthA], in_pStrB, in_LengthB);

                return pHolder;
            }

            void AddRef()
            {
                InterlockedIncrement(&RefCountAndLength);
            }

            void Release()
            {
                if ((uint16_t)InterlockedDecrement(&RefCountAndLength) == 0)
                    __HH_FREE(this);
            }

            bool IsUnique() const
            {
                return RefCount == 1;
            }

            bool TryInplaceAssign(const char* in_pStr, const size_t in_Length)
            {
                if (!IsUnique())
                    return false;

                const size_t memSizeAligned = GetMemorySizeAligned(in_Length);

                if (memSizeAligned > GetMemorySizeAligned(Length))
                    return false;

                if (in_pStr)
                    memcpy(aStr, in_pStr, in_Length);

                memset(&aStr[in_Length], 0, memSizeAligned - GetMemorySize(in_Length));

                Length = (uint16_t)in_Length;

                return true;
            }

            bool TryInplaceAppend(const char* in_pStr, const size_t in_Length)
            {
                if (!IsUnique())
                    return false;

                const size_t memSizeAligned = GetMemorySizeAligned(Length + in_Length);

                if (memSizeAligned > GetMemorySizeAligned(Length))
                    return false;

                if (in_pStr)
                    memcpy(&aStr[Length], in_pStr, in_Length);

                memset(&aStr[Length + in_Length], 0, memSizeAligned - GetMemorySize(Length + in_Length));

                Length = (uint16_t)(Length + in_Length);

                return true;
            }

            bool TryInplacePrepend(const char* in_pStr, const size_t in_Length)
            {
                if (!IsUnique())
                    return false;

                const size_t memSizeAligned = GetMemorySizeAligned(in_Length + Length);

                if (memSizeAligned > GetMemorySizeAligned(Length))
                    return false;

                memmove(&aStr[in_Length], aStr, Length);

                if (in_pStr)
                    memcpy(aStr, in_pStr, in_Length);

                memset(&aStr[in_Length + Length], 0, memSizeAligned - GetMemorySize(in_Length + Length));

                Length = (uint16_t)(in_Length + Length);

                return true;
            }
        };

        static constexpr const char* ms_pMemStatic = (const char*)0x13E0DC0;

        const char* m_pStr;

        SStringHolder* GetHolder() const
        {
            return SStringHolder::GetHolder(m_pStr);
        }

        bool IsMemStatic() const
        {
            return !m_pStr || m_pStr == ms_pMemStatic;
        }

        CSharedString(SStringHolder* in_pHolder)
            : m_pStr(in_pHolder->aStr)
        {

        }

    public:
        static constexpr size_t npos = ~0u;

        CSharedString() : m_pStr(ms_pMemStatic)
        {
        }

        CSharedString(const char* in_pStr)
        {
            size_t length;

            if (in_pStr && (length = strlen(in_pStr)) != 0)
                m_pStr = SStringHolder::Make(in_pStr, length)->aStr;

            else
                m_pStr = ms_pMemStatic;
        }

        CSharedString(const CSharedString& in_rOther)
            : m_pStr(in_rOther.m_pStr)
        {
            if (!IsMemStatic())
                GetHolder()->AddRef();
        }

        CSharedString(CSharedString&& io_rOther)
            : m_pStr(io_rOther.m_pStr)
        {
            io_rOther.m_pStr = ms_pMemStatic;
        }

        ~CSharedString()
        {
            if (!IsMemStatic())
                GetHolder()->Release();
        }

        const char* get() const
        {
            return !IsMemStatic() ? m_pStr : ms_pMemStatic;
        }

        const char* c_str() const
        {
            return get();
        }

        const char* data() const
        {
            return get();
        }

        size_t size() const
        {
            return !IsMemStatic() ? GetHolder()->Length : 0u;
        }
        
        size_t length() const
        {
            return size();
        }

        bool empty() const
        {
            return size() == 0;
        }

        const char* begin() const
        {
            return get();
        }

        const char* end() const
        {
            return !IsMemStatic() ? &m_pStr[GetHolder()->Length] : ms_pMemStatic;
        }

        CSharedString substr(size_t pos = 0, size_t len = npos) const
        {
            if (IsMemStatic()) 
                return CSharedString();

            if (len > (GetHolder()->Length - pos))
                len = GetHolder()->Length - pos;

            if (pos == 0 && len == GetHolder()->Length)
                return *this;

            return SStringHolder::Make(&m_pStr[pos], len);
        }

        size_t find(char c, size_t pos = 0) const
        {
            if (IsMemStatic())
                return npos;

            for (size_t i = pos; i < GetHolder()->Length; i++)
            {
                if (m_pStr[i] == c)
                    return i;
            }

            return npos;
        }

        void assign(const CSharedString& in_rOther)
        {
            if (!IsMemStatic())
                GetHolder()->Release();

            m_pStr = in_rOther.m_pStr;

            if (!IsMemStatic())
                GetHolder()->AddRef();
        }

        void assign(const char* in_pStr)
        {
            size_t length;

            if (in_pStr && (length = strlen(in_pStr)) != 0)
            {
                if (IsMemStatic())
                {
                    m_pStr = SStringHolder::Make(in_pStr, length)->aStr;
                }
                else if (!GetHolder()->TryInplaceAssign(in_pStr, length))
                {
                    GetHolder()->Release();
                    m_pStr = SStringHolder::Make(in_pStr, length)->aStr;
                }
            }
            else
            {
                if (!IsMemStatic())
                    GetHolder()->Release();

                m_pStr = ms_pMemStatic;
            }
        }

        void assign(CSharedString&& io_rOther)
        {
            m_pStr = io_rOther.m_pStr;
            io_rOther.m_pStr = ms_pMemStatic;
        }

        void append(const CSharedString& in_rOther)
        {
            if (in_rOther.IsMemStatic())
                return;

            if (IsMemStatic())
            {
                assign(in_rOther);
            }
            else if (!GetHolder()->TryInplaceAppend(in_rOther.GetHolder()->aStr, in_rOther.GetHolder()->Length))
            {
                SStringHolder* pHolder = SStringHolder::Concat(
                    GetHolder()->aStr, GetHolder()->Length,
                    in_rOther.GetHolder()->aStr, in_rOther.GetHolder()->Length);

                GetHolder()->Release();
                m_pStr = pHolder->aStr;
            }
        }

        void append(const char* in_pStr)
        {
            size_t length;

            if (in_pStr && (length = strlen(in_pStr)) != 0)
            {
                if (IsMemStatic())
                {
                    m_pStr = SStringHolder::Make(in_pStr, length)->aStr;
                }
                else if (!GetHolder()->TryInplaceAppend(in_pStr, length))
                {
                    SStringHolder* pHolder = SStringHolder::Concat(
                        GetHolder()->aStr, GetHolder()->Length, in_pStr, length);

                    GetHolder()->Release();
                    m_pStr = pHolder->aStr;
                }
            }
        }

        void prepend(const CSharedString& in_rOther)
        {
            if (in_rOther.IsMemStatic())
                return;

            if (IsMemStatic())
            {
                assign(in_rOther);
            }
            else if (!GetHolder()->TryInplacePrepend(in_rOther.GetHolder()->aStr, in_rOther.GetHolder()->Length))
            {
                SStringHolder* pHolder = SStringHolder::Concat(
                    in_rOther.GetHolder()->aStr, in_rOther.GetHolder()->Length,
                    GetHolder()->aStr, GetHolder()->Length);

                GetHolder()->Release();
                m_pStr = pHolder->aStr;
            }
        }

        void prepend(const char* in_pStr)
        {
            size_t length;

            if (in_pStr && (length = strlen(in_pStr)) != 0)
            {
                if (IsMemStatic())
                {
                    m_pStr = SStringHolder::Make(in_pStr, length)->aStr;
                }
                else if (!GetHolder()->TryInplacePrepend(in_pStr, length))
                {
                    SStringHolder* pHolder = SStringHolder::Concat(
                        in_pStr, length, GetHolder()->aStr, GetHolder()->Length);

                    GetHolder()->Release();
                    m_pStr = pHolder->aStr;
                }
            }
        }

        int compare(const CSharedString& in_rOther) const
        {
            return fpCSharedStringCompare(this, in_rOther);
        }

        CSharedString& operator=(const CSharedString& in_rOther)
        {
            assign(in_rOther);
            return *this;
        }

        CSharedString& operator=(const char* in_pStr)
        {
            assign(in_pStr);
            return *this;
        }

        CSharedString& operator=(CSharedString&& io_rOther)
        {
            assign(std::move(io_rOther));
            return *this;
        }

        CSharedString& operator+=(const CSharedString& in_rOther)
        {
            append(in_rOther);
            return *this;
        }

        CSharedString& operator+=(const char* in_pStr)
        {
            append(in_pStr);
            return *this;
        }

        friend CSharedString operator+(const CSharedString& in_rLeft, const CSharedString& in_rRight)
        {
            if (in_rLeft.IsMemStatic())
                return in_rRight;

            if (in_rRight.IsMemStatic())
                return in_rLeft;

            return SStringHolder::Concat(
                in_rLeft.GetHolder()->aStr, in_rLeft.GetHolder()->Length,
                in_rRight.GetHolder()->aStr, in_rRight.GetHolder()->Length);
        }

        friend CSharedString operator+(const CSharedString& in_rLeft, const char* in_pRight)
        {
            size_t length;

            if (in_pRight && (length = strlen(in_pRight)) != 0)
            {
                if (in_rLeft.IsMemStatic())
                {
                    return SStringHolder::Make(in_pRight, length);
                }
                else
                {
                    return SStringHolder::Concat(
                        in_rLeft.GetHolder()->aStr, in_rLeft.GetHolder()->Length, in_pRight, length);
                }
            }
            else
            {
                return in_rLeft;
            }
        }       
        
        friend CSharedString operator+(const char* in_pLeft, const CSharedString& in_pRight)
        {
            size_t length;

            if (in_pLeft && (length = strlen(in_pLeft)) != 0)
            {
                if (in_pRight.IsMemStatic())
                {
                    return SStringHolder::Make(in_pLeft, length);
                }
                else
                {
                    return SStringHolder::Concat(
                        in_pLeft, length, in_pRight.GetHolder()->aStr, in_pRight.GetHolder()->Length);
                }
            }
            else
            {
                return in_pRight;
            }
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