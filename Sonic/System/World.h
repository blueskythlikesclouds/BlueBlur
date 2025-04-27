#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Base/Thread/hhSynchronizedObject.h>
#include <Hedgehog/Universe/Engine/hhMessageActor.h>

namespace Hedgehog::Mirage
{
    class CRenderScene;
}

namespace Sonic
{
    class CCamera;
    class CPhysicsWorld;

    class CWorld : public Hedgehog::Base::CSynchronizedObject, public Hedgehog::Universe::CMessageActor
    {
    public:
        class CMember
        {
        public:
            boost::shared_ptr<Hedgehog::Mirage::CRenderScene> m_spRenderScene;
            Hedgehog::Base::CSharedString m_Name;
            boost::shared_ptr<CCamera> m_spCamera;
            boost::shared_ptr<CCamera> m_spOverrideCamera;
            BB_INSERT_PADDING(0x50);
            boost::shared_ptr<CPhysicsWorld> m_spPhysicsWorld;
            BB_INSERT_PADDING(0xC);
        };

        CMember* m_pMember;

        boost::shared_ptr<CCamera> GetCamera() const;
    };

    BB_ASSERT_OFFSETOF(CWorld::CMember, m_spRenderScene, 0x0);
    BB_ASSERT_OFFSETOF(CWorld::CMember, m_Name, 0x8);
    BB_ASSERT_OFFSETOF(CWorld::CMember, m_spCamera, 0xC);
    BB_ASSERT_OFFSETOF(CWorld::CMember, m_spOverrideCamera, 0x14);
    BB_ASSERT_OFFSETOF(CWorld::CMember, m_spPhysicsWorld, 0x6C);
    BB_ASSERT_SIZEOF(CWorld::CMember, 0x80);

    BB_ASSERT_OFFSETOF(CWorld, m_pMember, 0x80);
    BB_ASSERT_SIZEOF(CWorld, 0x84);
}

#include <Sonic/System/World.inl>