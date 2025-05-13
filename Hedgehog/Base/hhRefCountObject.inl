namespace Hedgehog::Base
{
    inline CRefCountObject::CRefCountObject() : m_refCount(0)
    {}

    inline CRefCountObject::~CRefCountObject() = default;

    inline LONG CRefCountObject::AddRef()
    {
        return InterlockedIncrement(&m_refCount);
    }

    inline LONG CRefCountObject::Release()
    {
        const LONG result = InterlockedDecrement(&m_refCount);

        if (result == 0)
            delete this;

        return result;
    }

    template <typename T>
    CRefPtr<T>::CRefPtr() : m_pObject(nullptr)
    {
    }

    template <typename T>
    CRefPtr<T>::CRefPtr(T* in_pObj) : m_pObject(in_pObj)
    {
        if (m_pObject)
            m_pObject->AddRef();
    }

    template <typename T>
    CRefPtr<T>::CRefPtr(const CRefPtr& in_rOther) : m_pObject(in_rOther.m_pObject)
    {
        if (m_pObject)
            m_pObject->AddRef();
    }

    template <typename T>
    CRefPtr<T>::CRefPtr(CRefPtr&& in_rOther) : m_pObject(in_rOther.m_pObject)
    {
        in_rOther.m_pObject = nullptr;
    }

    template <typename T>
    CRefPtr<T>::~CRefPtr()
    {
        if (m_pObject)
            m_pObject->Release();
    }

    template <typename T>
    CRefPtr<T>& CRefPtr<T>::operator=(T* in_rObj)
    {
        if (m_pObject)
            m_pObject->Release();

        m_pObject = in_rObj;

        if (m_pObject)
            m_pObject->AddRef();

        return *this;
    }

    template <typename T>
    CRefPtr<T>& CRefPtr<T>::operator=(const CRefPtr& in_rOther)
    {
        if (m_pObject)
            m_pObject->Release();

        m_pObject = in_rOther.m_pObject;

        if (m_pObject)
            m_pObject->AddRef();

        return *this;
    }

    template <typename T>
    CRefPtr<T>& CRefPtr<T>::operator=(CRefPtr&& io_rOther)
    {
        if (m_pObject)
            m_pObject->Release();

        m_pObject = io_rOther.m_pObject;
        io_rOther.m_pObject = nullptr;

        return *this;
    }

    template <typename T>
    T* CRefPtr<T>::operator->() const
    {
        return m_pObject;
    }

    template <typename T>
    T& CRefPtr<T>::operator*() const
    {
        return *m_pObject;
    }

    template <typename T>
    CRefPtr<T>::operator T* () const
    {
        return m_pObject;
    }

    template <typename T>
    CRefPtr<T>::operator bool() const
    {
        return m_pObject != nullptr;
    }

    template <typename T>
    T* CRefPtr<T>::Get()
    {
        return m_pObject;
    }

    template <typename T>
    const T* CRefPtr<T>::Get() const
    {
        return m_pObject;
    }

    template <typename T>
    T* CRefPtr<T>::Detach()
    {
        T* obj = m_pObject;
        m_pObject = nullptr;
        return obj;
    }

    template <typename T>
    void CRefPtr<T>::Reset()
    {
        if (m_pObject)
            m_pObject->Release();

        m_pObject = nullptr;
    }

    template <typename T>
    void CRefPtr<T>::Swap(CRefPtr& io_rOther)
    {
        T* obj = m_pObject;
        m_pObject = io_rOther.m_pObject;
        io_rOther.m_pObject = obj;
    }
}