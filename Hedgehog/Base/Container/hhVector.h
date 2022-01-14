#pragma once

#include <BlueBlur.inl>

namespace Hedgehog
{
    template<typename T>
    class vector
    {
    public:
        BB_INSERT_PADDING(0x4);
        T* m_pBegin;
        T* m_pEnd;
        T* m_pCapacityEnd;

        T* begin() const
        {
            return m_pBegin;
        }

        T* end() const
        {
            return m_pEnd;
        }

        size_t size() const
        {
            return ((size_t)m_pEnd - (size_t)m_pBegin) / sizeof(T);
        }

        size_t capacity() const
        {
            return ((size_t)m_pCapacityEnd - (size_t)m_pBegin) / sizeof(T);
        }

        T& operator[](const size_t index) const
        {
            return m_pBegin[index];
        }
    };
}

namespace hh = Hedgehog;