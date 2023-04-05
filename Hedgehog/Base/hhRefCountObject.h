#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Base
{
    class CRefCountObject
    {
    private:
        uint32_t m_refCount;

    public:
        CRefCountObject() : m_refCount(1) {}

        virtual ~CRefCountObject() = default;

        LONG AddRef()
        {
            return InterlockedIncrement(&m_refCount);
        }

        LONG Release()
        {
            const LONG result = InterlockedDecrement(&m_refCount);
            
            if (result == 0)
                delete this;

            return result;
        }
    };

    template<typename T>
    class CRefPtr
    {
    public:
        CRefPtr()
            : m_pObject(nullptr)
        {
        }

        CRefPtr(T* in_pObj)
            : m_pObject(in_pObj)
        {
            if (m_pObject)
                m_pObject->AddRef();
        }

        CRefPtr(const CRefPtr& in_rOther)
            : m_pObject(in_rOther.m_pObject)
        {
            if (m_pObject)
                m_pObject->AddRef();
        }

        CRefPtr(CRefPtr&& in_rOther)
            : m_pObject(in_rOther.m_pObject)
        {
            in_rOther.m_pObject = nullptr;
        }

        ~CRefPtr()
        {
            if (m_pObject)
                m_pObject->Release();
        }

        CRefPtr& operator=(T* in_rObj)
        {
            if (m_pObject)
                m_pObject->Release();

            m_pObject = in_rObj;

            if (m_pObject)
                m_pObject->AddRef();

            return *this;
        }

        CRefPtr& operator=(const CRefPtr& in_rOther)
        {
            if (m_pObject)
                m_pObject->Release();

            m_pObject = in_rOther.m_pObject;

            if (m_pObject)
                m_pObject->AddRef();

            return *this;
        }

        CRefPtr& operator=(CRefPtr&& io_rOther)
        {
            if (m_pObject)
                m_pObject->Release();

            m_pObject = io_rOther.m_pObject;
            io_rOther.m_pObject = nullptr;

            return *this;
        }

        T* operator->()
        {
            return m_pObject;
        }

        T& operator*()
        {
            return *m_pObject;
        }

        operator T*()
        {
            return m_pObject;
        }

        operator bool() const
        {
            return m_pObject != nullptr;
        }

        T* Get()
        {
            return m_pObject;
        }

        const T* Get() const
        {
            return m_pObject;
        }

        T* Detach()
        {
            T* obj = m_pObject;
            m_pObject = nullptr;
            return obj;
        }

        void Reset()
        {
            if (m_pObject)
                m_pObject->Release();

            m_pObject = nullptr;
        }

        void Swap(CRefPtr& io_rOther)
        {
            T* obj = m_pObject;
            m_pObject = io_rOther.m_pObject;
            io_rOther.m_pObject = obj;
        }

    private:
        T* m_pObject;
    };

    BB_ASSERT_SIZEOF(CRefCountObject, 0x8);
}