#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Base
{
    class CRefCountObject
    {
    private:
        uint32_t m_refCount;

    public:
        CRefCountObject();
        virtual ~CRefCountObject();

        LONG AddRef();
        LONG Release();
    };

    template<typename T>
    class CRefPtr
    {
    public:
        CRefPtr();
        CRefPtr(T* in_pObj);
        CRefPtr(const CRefPtr& in_rOther);
        CRefPtr(CRefPtr&& in_rOther);
        ~CRefPtr();

        CRefPtr& operator=(T* in_rObj);
        CRefPtr& operator=(const CRefPtr& in_rOther);
        CRefPtr& operator=(CRefPtr&& io_rOther);

        T* operator->() const;
        T& operator*() const;
        operator T*() const;

        operator bool() const;

        T* Get();
        const T* Get() const;

        T* Detach();

        void Reset();

        void Swap(CRefPtr& io_rOther);

    private:
        T* m_pObject;
    };

    BB_ASSERT_SIZEOF(CRefCountObject, 0x8);
}

#include <Hedgehog/Base/hhRefCountObject.inl>