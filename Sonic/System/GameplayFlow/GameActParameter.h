#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Sonic
{
    namespace Mission
    {
        class CMissionManager;
    }

    class CPvsManager;
    class CVisibilityCullingManager;
    class CInstancerManager;
    class CObjectPhysicsParamContainer;
    class CObjectInfoManager;
    class CActivationManager;
    class CSetObjectManager;
    class CPathManager;
    class CScoreManager;

    class CGameActParameter : Hedgehog::Base::CObject
    {
    public:
        boost::shared_ptr<CPathManager> m_spPathManager;
        boost::shared_ptr<CSetObjectManager> m_spSetObjectManager;
        CSetObjectManager* m_pSetObjectManager;
        int m_SetObjectManagerID;
        boost::shared_ptr<CActivationManager> m_spActivationManager;
        CActivationManager* m_pActivationManager;
        boost::shared_ptr<CObjectInfoManager> m_spObjectInfoManager;
        CObjectInfoManager* m_pObjectInfoManager;
        boost::shared_ptr<CObjectPhysicsParamContainer> m_spObjectPhysicsParamContainer;
        boost::shared_ptr<CInstancerManager> m_spInstancerManager;
        CInstancerManager* m_pInstanceManager;
        int m_ActorID_Field048; // assigned at 0x00D9539F
        BB_INSERT_PADDING(0x14) {};
        boost::shared_ptr<CVisibilityCullingManager> m_spVisibilityCullingManager;
        CVisibilityCullingManager* m_pVisibilityCullingManager;
        boost::shared_ptr<CPvsManager> m_spPvsManager;
        CPvsManager* m_pPvsManager;
        BB_INSERT_PADDING(0x0C) {};
        boost::shared_ptr<Mission::CMissionManager> m_spMissionManager;
        boost::shared_ptr<CScoreManager> m_spScoreManager;

        virtual ~CGameActParameter() = default;
    };

    BB_ASSERT_OFFSETOF(CGameActParameter, m_pSetObjectManager, 0x14);
    BB_ASSERT_SIZEOF(CGameActParameter, 0x94);
}