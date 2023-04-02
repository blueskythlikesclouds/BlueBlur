#pragma once

#include <Hedgehog/Base/System/hhAllocator.h>

namespace Hedgehog::Base
{
    template<typename T>
    class CCowData
    {
    protected:
        class CData
        {
        public:
            size_t m_RefCountAndLength;
            T m_Data[1];
        };

        static constexpr const T* ms_memStatic = (const T*)0x13E0DC0;

        const T* m_ptr;

        bool IsMemStatic() const
        {
            return !m_ptr || m_ptr == ms_memStatic;
        }

        CData* GetData() const
        {
            return (CData*)((char*)m_ptr - offsetof(CData, m_Data));
        }

        void SetData(CData* in_pData)
        {
            m_ptr = (const T*)((char*)in_pData + offsetof(CData, m_Data));
        }

    public:
        const T* Get() const
        {
            return IsMemStatic() ? ms_memStatic : m_ptr;
        }

        void Unset()
        {
            if (!IsMemStatic() && (uint16_t)InterlockedDecrement(&GetData()->m_RefCountAndLength) == 0)
                __HH_FREE(GetData());

            m_ptr = ms_memStatic;
        }

        void Set(const CCowData& in_rOther)
        {
            m_ptr = in_rOther.m_ptr;

            if (!IsMemStatic())
                InterlockedIncrement(&GetData()->m_RefCountAndLength);
        }

        void Set(const T* in_pPtr, const size_t in_Length)
        {
            if (!in_Length)
                return;

            const size_t memSize = offsetof(CData, m_Data) + in_Length * sizeof(T);
            const size_t memSizeAligned = (memSize + 0x10) & 0xFFFFFFF0;

            CData* pData = (CData*)__HH_ALLOC(memSizeAligned);
            pData->m_RefCountAndLength = (in_Length << 16) | 1;

            if (in_pPtr)
            {
                memcpy(pData->m_Data, in_pPtr, in_Length * sizeof(T));
                memset(&pData->m_Data[in_Length], 0, memSizeAligned - memSize);
            }

            SetData(pData);
        }

        CCowData() : m_ptr(ms_memStatic)
        {

        }

        CCowData(const CCowData& in_Other)
        {
            Set(in_Other);
        }

        CCowData(CCowData&& io_rOther)
        {
            m_ptr = io_rOther.m_ptr;
            io_rOther.m_ptr = ms_memStatic;
        }

        ~CCowData()
        {
            Unset();
        }

        CCowData& operator=(CCowData&& io_rOther)
        {
            if (this != &io_rOther)
            {
                m_ptr = io_rOther.m_ptr;
                io_rOther.m_ptr = ms_memStatic;
            }
            return *this;
        }

        CCowData& operator=(const CCowData& in_rOther)
        {
            if (this != &in_rOther)
            {
                Unset();
                Set(in_rOther);
            }
            return *this;
        }
    };
}