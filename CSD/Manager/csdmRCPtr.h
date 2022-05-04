#pragma once

#include <CSD/Manager/csdmRCPtrAbs.h>

namespace Chao::CSD
{
    template<typename T>
    class RCPtr : RCPtrAbs
    {
    public:
        class RCObjectImp;

        RCPtr() : RCPtrAbs() {}
        RCPtr(const RCPtr& in_rOther) : RCPtrAbs(in_rOther) {}
        RCPtr(RCPtr&& in_rOther) : RCPtrAbs(std::move(in_rOther)) {}

        RCObject* CreateRCObject() override;

        void Attach(T* in_pObject)
        {
            RCPtrAbs::AttachAbs(in_pObject);
        }

        T* Get() const
        {
            return static_cast<T*>(RCPtrAbs::GetAbs());
        }
        
        void Set(const RCPtr& in_rOther)
        {
            RCPtrAbs::SetAbs(in_rOther);
        }

        T* operator*() const
        {
            return Get();
        }

        T* operator->() const
        {
            return Get();
        }

        RCPtr& operator=(const RCPtr& in_rOther)
        {
            Set(in_rOther);
            return *this;
        }
    };
}