namespace Hedgehog::Base
{
    inline SStringHolder* CSharedString::GetHolder() const
    {
        return SStringHolder::GetHolder(m_pStr);
    }

    inline bool CSharedString::IsMemStatic() const
    {
        return !m_pStr || m_pStr == ms_pMemStatic;
    }

    inline CSharedString::CSharedString(SStringHolder* in_pHolder) : m_pStr(in_pHolder->aStr)
    {

    }

    inline CSharedString::CSharedString() : m_pStr(ms_pMemStatic)
    {
    }

    inline CSharedString::CSharedString(const char* in_pStr)
    {
        size_t length;

        if (in_pStr && (length = strlen(in_pStr)) != 0)
            m_pStr = SStringHolder::Make(in_pStr, length)->aStr;

        else
            m_pStr = ms_pMemStatic;
    }

    inline CSharedString::CSharedString(const CSharedString& in_rOther) : m_pStr(in_rOther.m_pStr)
    {
        if (!IsMemStatic())
            GetHolder()->AddRef();
    }

    inline CSharedString::CSharedString(CSharedString&& io_rOther) : m_pStr(io_rOther.m_pStr)
    {
        io_rOther.m_pStr = ms_pMemStatic;
    }

    inline CSharedString::~CSharedString()
    {
        if (!IsMemStatic())
            GetHolder()->Release();
    }

    inline const char* CSharedString::get() const
    {
        return !IsMemStatic() ? m_pStr : ms_pMemStatic;
    }

    inline const char* CSharedString::c_str() const
    {
        return get();
    }

    inline const char* CSharedString::data() const
    {
        return get();
    }

    inline size_t CSharedString::size() const
    {
        return !IsMemStatic() ? GetHolder()->Length : 0u;
    }

    inline size_t CSharedString::length() const
    {
        return size();
    }

    inline bool CSharedString::empty() const
    {
        return size() == 0;
    }

    inline const char* CSharedString::begin() const
    {
        return get();
    }

    inline const char* CSharedString::end() const
    {
        return !IsMemStatic() ? &m_pStr[GetHolder()->Length] : ms_pMemStatic;
    }

    inline CSharedString CSharedString::substr(size_t pos, size_t len) const
    {
        if (IsMemStatic() || len == 0)
            return CSharedString();

        if (len > (GetHolder()->Length - pos))
            len = GetHolder()->Length - pos;

        if (pos == 0 && len == GetHolder()->Length)
            return *this;

        return SStringHolder::Make(&m_pStr[pos], len);
    }

    inline size_t CSharedString::find(char c, size_t pos) const
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

    inline size_t CSharedString::find(const char* s, size_t pos) const
    {
        if (IsMemStatic())
            return npos;

        size_t len = strlen(s);
        for (size_t i = pos; i < GetHolder()->Length - len + 1; i++)
        {
            if (strncmp(m_pStr + i, s, len) == 0)
                return i;
        }

        return npos;
    }

    inline size_t CSharedString::rfind(char c, size_t pos) const
    {
        if (IsMemStatic())
            return npos;

        if (pos >= GetHolder()->Length)
            pos = GetHolder()->Length - 1;

        for (size_t i = pos; i != static_cast<size_t>(-1); i--)
        {
            if (m_pStr[i] == c)
                return i;
        }

        return npos;
    }

    inline size_t CSharedString::find_first_of(const char* s, size_t pos) const
    {
        if (IsMemStatic())
            return npos;

        size_t len = strlen(s);
        for (size_t i = pos; i < GetHolder()->Length; i++)
        {
            for (size_t j = 0; j < len; j++)
            {
                if (m_pStr[i] == s[j])
                    return i;
            }
        }

        return npos;
    }

    inline size_t CSharedString::find_last_of(const char* s, size_t pos) const
    {
        if (IsMemStatic())
            return npos;

        if (pos >= GetHolder()->Length)
            pos = GetHolder()->Length - 1;

        size_t len = strlen(s);
        for (size_t i = pos; i != static_cast<size_t>(-1); i--)
        {
            for (size_t j = 0; j < len; j++)
            {
                if (m_pStr[i] == s[j])
                    return i;
            }
        }

        return npos;
    }

    inline size_t CSharedString::find_first_not_of(const char* s, size_t pos) const
    {
        if (IsMemStatic())
            return npos;

        size_t len = strlen(s);
        for (size_t i = pos; i < GetHolder()->Length; i++)
        {
            bool found = false;
            for (size_t j = 0; j < len; j++)
            {
                if (m_pStr[i] == s[j])
                {
                    found = true;
                    break;
                }
            }

            if (!found)
                return i;
        }

        return npos;
    }

    inline size_t CSharedString::find_last_not_of(const char* s, size_t pos) const
    {
        if (IsMemStatic())
            return npos;

        if (pos >= GetHolder()->Length)
            pos = GetHolder()->Length - 1;

        size_t len = strlen(s);
        for (size_t i = pos; i != static_cast<size_t>(-1); i--)
        {
            bool found = false;
            for (size_t j = 0; j < len; j++)
            {
                if (m_pStr[i] == s[j])
                {
                    found = true;
                    break;
                }
            }

            if (!found)
                return i;
        }

        return npos;
    }

    inline size_t CSharedString::find(const CSharedString& str, size_t pos) const
    {
        return find(str.c_str(), pos);
    }

    inline size_t CSharedString::rfind(const CSharedString& str, size_t pos) const
    {
        return rfind(str.c_str(), pos);
    }

    inline size_t CSharedString::find_first_of(const CSharedString& str, size_t pos) const
    {
        return find_first_of(str.c_str(), pos);
    }

    inline size_t CSharedString::find_last_of(const CSharedString& str, size_t pos) const
    {
        return find_last_of(str.c_str(), pos);
    }

    inline size_t CSharedString::find_first_not_of(const CSharedString& str, size_t pos) const
    {
        return find_first_not_of(str.c_str(), pos);
    }

    inline size_t CSharedString::find_last_not_of(const CSharedString& str, size_t pos) const
    {
        return find_last_not_of(str.c_str(), pos);
    }

    inline void CSharedString::assign(const CSharedString& in_rOther)
    {
        if (!IsMemStatic())
            GetHolder()->Release();

        m_pStr = in_rOther.m_pStr;

        if (!IsMemStatic())
            GetHolder()->AddRef();
    }

    inline void CSharedString::assign(const char* in_pStr)
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

    inline void CSharedString::assign(CSharedString&& io_rOther)
    {
        m_pStr = io_rOther.m_pStr;
        io_rOther.m_pStr = ms_pMemStatic;
    }

    inline void CSharedString::append(const CSharedString& in_rOther)
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

    inline void CSharedString::append(const char* in_pStr)
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

    inline void CSharedString::prepend(const CSharedString& in_rOther)
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

    inline void CSharedString::prepend(const char* in_pStr)
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

    inline BB_FUNCTION_PTR(int, __thiscall, fpCSharedStringCompare, 0x6618C0,
        const CSharedString* This, const CSharedString& in_rOther);

    inline int CSharedString::compare(const CSharedString& in_rOther) const
    {
        return fpCSharedStringCompare(this, in_rOther);
    }

    inline CSharedString& CSharedString::operator=(const CSharedString& in_rOther)
    {
        assign(in_rOther);
        return *this;
    }

    inline CSharedString& CSharedString::operator=(const char* in_pStr)
    {
        assign(in_pStr);
        return *this;
    }

    inline CSharedString& CSharedString::operator=(CSharedString&& io_rOther)
    {
        assign(std::move(io_rOther));
        return *this;
    }

    inline CSharedString& CSharedString::operator+=(const CSharedString& in_rOther)
    {
        append(in_rOther);
        return *this;
    }

    inline CSharedString& CSharedString::operator+=(const char* in_pStr)
    {
        append(in_pStr);
        return *this;
    }

    inline CSharedString operator+(const CSharedString& in_rLeft, const CSharedString& in_rRight)
    {
        if (in_rLeft.IsMemStatic())
            return in_rRight;

        if (in_rRight.IsMemStatic())
            return in_rLeft;

        return SStringHolder::Concat(
            in_rLeft.GetHolder()->aStr, in_rLeft.GetHolder()->Length,
            in_rRight.GetHolder()->aStr, in_rRight.GetHolder()->Length);
    }

    inline CSharedString operator+(const CSharedString& in_rLeft, const char* in_pRight)
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

    inline CSharedString operator+(const char* in_pLeft, const CSharedString& in_pRight)
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

    inline bool CSharedString::operator>(const CSharedString& in_rOther) const
    {
        return compare(in_rOther) > 0;
    }

    inline bool CSharedString::operator>=(const CSharedString& in_rOther) const
    {
        return compare(in_rOther) >= 0;
    }

    inline bool CSharedString::operator<(const CSharedString& in_rOther) const
    {
        return compare(in_rOther) < 0;
    }

    inline bool CSharedString::operator<=(const CSharedString& in_rOther) const
    {
        return compare(in_rOther) <= 0;
    }

    inline bool CSharedString::operator==(const CSharedString& in_rOther) const
    {
        return compare(in_rOther) == 0;
    }

    inline bool CSharedString::operator!=(const CSharedString& in_rOther) const
    {
        return !(*this == in_rOther);
    }

    inline bool CSharedString::operator==(const char* in_pOther) const
    {
        return strcmp(c_str(), in_pOther) == 0;
    }

    inline bool CSharedString::operator!=(const char* in_pOther) const
    {
        return !(*this == in_pOther);
    }
}