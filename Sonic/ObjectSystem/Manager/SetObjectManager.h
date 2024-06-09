#pragma once
namespace Sonic
{
    class CUserIDGroupCategoryManager;
    class CParameterBankManager;
    class CSetLayerManager;
    class CSetObjectEventManager;
    class CSetObjectManager
    {
    public:
        class CSetObjectManagerMember
        {
        public:
            BB_INSERT_PADDING(0x30);
            boost::shared_ptr<CUserIDGroupCategoryManager> m_spUserIDGroupCategoryManager;
            boost::shared_ptr<CParameterBankManager> m_spParameterBankManager;
            BB_INSERT_PADDING(0x10);
            boost::shared_ptr<CSetLayerManager> m_spSetLayerManager;
            boost::shared_ptr<CSetObjectEventManager> m_spSetObjectEventManager;
        };

        BB_ASSERT_OFFSETOF(CSetObjectManagerMember, m_spSetLayerManager, 0x50);
        BB_INSERT_PADDING(0xAC);
        CSetObjectManagerMember* m_pMember;
    };

    BB_ASSERT_OFFSETOF(CSetObjectManager, m_pMember, 0xAC);
}