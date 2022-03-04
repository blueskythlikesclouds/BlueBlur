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

        CRefPtr(T* obj)
            : m_pObject(obj)
        {
            if (m_pObject)
                m_pObject->AddRef();
        }

        CRefPtr(const CRefPtr& other)
            : m_pObject(other.m_pObject)
        {
            if (m_pObject)
                m_pObject->AddRef();
        }

        CRefPtr(CRefPtr&& other)
            : m_pObject(other.m_pObject)
        {
            other.m_pObject = nullptr;
        }

        ~CRefPtr()
        {
            if (m_pObject)
                m_pObject->Release();
        }

        CRefPtr& operator=(T* obj)
        {
            if (m_pObject)
                m_pObject->Release();

            m_pObject = obj;

            if (m_pObject)
                m_pObject->AddRef();

            return *this;
        }

        CRefPtr& operator=(const CRefPtr& other)
        {
            if (m_pObject)
                m_pObject->Release();

            m_pObject = other.m_pObject;

            if (m_pObject)
                m_pObject->AddRef();

            return *this;
        }

        CRefPtr& operator=(CRefPtr&& other)
        {
            if (m_pObject)
                m_pObject->Release();

            m_pObject = other.m_pObject;
            other.m_pObject = nullptr;

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

        void Swap(CRefPtr& other)
        {
            T* obj = m_pObject;
            m_pObject = other.m_pObject;
            other.m_pObject = obj;
        }

    private:
        T* m_pObject;
    };

    BB_ASSERT_SIZEOF(CRefCountObject, 0x8);
}