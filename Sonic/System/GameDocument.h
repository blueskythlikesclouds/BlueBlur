#pragma once

#include <Hedgehog/Base/Container/hhList.h>
#include <Hedgehog/Base/Container/hhMap.h>
#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Base/Thread/hhSynchronizedObject.h>
#include <Hedgehog/Base/Thread/hhSynchronizedPtr.h>
#include <Hedgehog/Universe/Engine/hhUpdateManager.h>

namespace Hedgehog::Sound
{
    class CSoundHandleBgm;
}

namespace Hedgehog::Database
{
    class CDatabase;
}
namespace Hedgehog::Mirage
{
    class CDebugDraw;
    class CLightFieldManager;
}

namespace Sonic
{
    struct SBGMData;
    class CGameActParameter;
    class CLightManager;
    class CRenderDirector;
    class CParameterBank;
    class CNextStagePreloadingManager;
    class CParticleManager;
    class CEventManager;

    static inline BB_FUNCTION_PTR(void, __stdcall, fpAddGameObject, 0xD631A0,
        CGameDocument* in_pGameDocument, const Hedgehog::Base::THolder<CWorld>& in_rWorldHolder,
        const boost::shared_ptr<CGameObject>& in_spGameObject, boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase,
        CGameObject* in_pParentGameObject);

    class CGameDocument : public Hedgehog::Base::CSynchronizedObject
    {
    public:
        class CMember
        {
        public:
            boost::shared_ptr<Hedgehog::Universe::CUpdateManager> m_spUpdateManager;
            boost::shared_ptr<CRenderDirector> m_spRenderDirector;
            hh::map<Hedgehog::Base::CSharedString, boost::shared_ptr<CWorld>> m_Worlds;
            boost::shared_ptr<Hedgehog::Database::CDatabase> m_spDatabase;
            hh::list<boost::shared_ptr<CGameObject>> m_GameObjects;
            hh::vector<void*> m_UnkVector01;
            boost::shared_ptr<Hedgehog::Mirage::CDebugDraw> m_spDebugDraw;
            hh::vector<size_t> m_PlayerIDs;
            BB_INSERT_PADDING(0x20);
            boost::shared_ptr<Hedgehog::Mirage::CLightFieldManager> m_spLightFieldManager;
            boost::shared_ptr<CLightManager> m_spLightManager;
            Hedgehog::Base::CSharedString m_StageName;
            hh::vector<SBGMData> m_AudioData;
            float m_Field9C;
            BB_INSERT_PADDING(0x08);
            Hedgehog::Base::CSharedString m_Name01;
            BB_INSERT_PADDING(0x48);
            CParameterBank* m_pParamaterBank;
            BB_INSERT_PADDING(0x28);
            boost::shared_ptr<CNextStagePreloadingManager> m_spNextStagePreloadingManager;
            BB_INSERT_PADDING(0x04);
            boost::shared_ptr<CParticleManager> m_spParticleManager;
            CParticleManager* m_pParticleManager; // Odd.
            boost::shared_ptr<CEventManager> m_spEventManager;
            BB_INSERT_PADDING(0x70);
        };

        static constexpr Hedgehog::Base::TSynchronizedPtr<CGameDocument>* ms_pInstance = (Hedgehog::Base::TSynchronizedPtr<CGameDocument>*)0x1E0BE5C;

        static Hedgehog::Base::TSynchronizedPtr<CGameDocument> GetInstance()
        {
            return *ms_pInstance;
        }

        CMember* m_pMember;
        BB_INSERT_PADDING(0x0C);
        CGameActParameter* m_pGameActParameter;
        BB_INSERT_PADDING(0x04);

        virtual ~CGameDocument() = default;

        Hedgehog::Base::TSynchronizedPtr<CWorld> GetWorld(const Hedgehog::Base::CSharedString& in_rName = "main") const
        {
            const auto pair = m_pMember->m_Worlds.find(in_rName);
            return pair != m_pMember->m_Worlds.end() ? pair->second.get() : nullptr;
        }

        void AddGameObject(const boost::shared_ptr<CGameObject>& in_spGameObject, const char* in_pWorldName = "main", CGameObject* in_pParentGameObject = nullptr)
        {
            fpAddGameObject(this, *GetWorld(in_pWorldName), in_spGameObject, m_pMember->m_spDatabase, in_pParentGameObject);
        }

        void AddUpdateUnit(const Hedgehog::Base::CSharedString& in_rCategory, Hedgehog::Universe::CUpdateUnit* in_pUpdateUnit)
        {
            m_pMember->m_spUpdateManager->AddUpdateUnit(in_rCategory, in_pUpdateUnit);
        }
    };

    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_spUpdateManager, 0x0);
    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_spRenderDirector, 0x8);
    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_Worlds, 0x10);
    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_spDatabase, 0x1C);
    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_GameObjects, 0x24);
    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_PlayerIDs, 0x48);
    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_spLightManager, 0x80);
    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_StageName, 0x88);
    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_AudioData, 0x8C);
    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_Field9C, 0x9C);
    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_Name01, 0xA8);
    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_pParamaterBank, 0xF4);
    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_spNextStagePreloadingManager, 0x120);
    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_spParticleManager, 0x12C);
    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_pParticleManager, 0x134);
    BB_ASSERT_OFFSETOF(CGameDocument::CMember, m_spEventManager, 0x138);
    BB_ASSERT_SIZEOF(CGameDocument::CMember, 0x1B0);

    BB_ASSERT_OFFSETOF(CGameDocument, m_pCriticalSection, 0x4);
    BB_ASSERT_OFFSETOF(CGameDocument, m_pMember, 0x8);
    BB_ASSERT_SIZEOF(CGameDocument, 0x20);
}