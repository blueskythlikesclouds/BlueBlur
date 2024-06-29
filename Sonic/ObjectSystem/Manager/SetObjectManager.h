#pragma once
#include <Hedgehog/Base/Thread/hhSynchronizedObject.h>
#include <Sonic/System/GameObject.h>

namespace Sonic
{
    class CUserIDGroupCategoryManager;
    class CParameterBankManager;
    class CSetLayerManager;
    class CSetObjectEventManager;

    class CSetObjectManager : public Sonic::CGameObject, public Hedgehog::Base::CSynchronizedObject
    {
    public:
        class CMember
        {
        public:
            BB_INSERT_PADDING(0x10);
            boost::shared_ptr<Sonic::CSetObjectFactory> m_spSetObjectFactory;
            BB_INSERT_PADDING(0x18);
            boost::shared_ptr<CUserIDGroupCategoryManager> m_spUserIDGroupCategoryManager;
            boost::shared_ptr<CParameterBankManager> m_spParameterBankManager;
            BB_INSERT_PADDING(0x10);
            boost::shared_ptr<CSetLayerManager> m_spSetLayerManager;
            boost::shared_ptr<CSetObjectEventManager> m_spSetObjectEventManager;
        };
        CMember* m_pMember;
    };
    BB_ASSERT_OFFSETOF(CSetObjectManager, m_pMember, 0xAC);
    BB_ASSERT_OFFSETOF(CSetObjectManager::CMember, m_spSetObjectFactory, 0x10);
    BB_ASSERT_OFFSETOF(CSetObjectManager::CMember, m_spUserIDGroupCategoryManager, 0x30);
    BB_ASSERT_OFFSETOF(CSetObjectManager::CMember, m_spParameterBankManager, 0x38);
    BB_ASSERT_OFFSETOF(CSetObjectManager::CMember, m_spSetLayerManager, 0x50);
    BB_ASSERT_OFFSETOF(CSetObjectManager::CMember, m_spSetObjectEventManager, 0x58);
}