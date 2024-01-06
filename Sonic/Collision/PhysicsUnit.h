#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Container/hhMap.h>

namespace Hedgehog::Base
{
    class CCriticalSectionD3D9;
}

namespace Hedgehog::Universe
{
    class CMessageActor;
}

namespace hk2010_2_0
{
    class hkpRigidBody;
}

namespace Sonic
{
    class CPhysicsWorld;

    class CPhysicsUnit : public Hedgehog::Base::CObject
    {
    public:
        hk2010_2_0::hkpRigidBody* m_pHkpRigidBody;
        CPhysicsWorld* m_pPhysicsWorld;
        void* m_Field0C;
        uint32_t m_CollisionCategory;
        uint32_t m_Field14;
        uint32_t m_Field18;
        hh::map<void*, void*> m_Field1C;
        hh::map<void*, void*> m_Field28;
        uint8_t m_Field34;
        uint8_t m_Field35;
        uint8_t m_Field36;
        uint8_t m_Field37;
        uint32_t m_Field38;
        Hedgehog::Universe::CMessageActor* m_pMessageActor;
        boost::shared_ptr<Hedgehog::Base::CCriticalSectionD3D9> m_spCriticalSectionD3D9;

        virtual ~CPhysicsUnit() = default;

        virtual void* GetCollider(void* a1) { return a1; }
        virtual void* fn02(void* a1) { return a1; }
        virtual void AddProperty(int in_Id, uint64_t* in_pValue) {}
        virtual void fn04(int a1, int a2) {}
        virtual void fn05(int a1, int a2) {}
        virtual void GetProperty(uint64_t* weird, int hash) {}
        virtual bool HasProperty(int hash) { return false; }

        void AddProperty(int id, int value);

        void AddBoolProperty(int hashedName, int id);
        bool GetBoolProperty(int id);
    };

    BB_ASSERT_SIZEOF(CPhysicsUnit, 0x48);
}

#include <Sonic/Collision/PhysicsUnit.inl>