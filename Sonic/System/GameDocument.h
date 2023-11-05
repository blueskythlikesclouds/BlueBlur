#pragma once

#include <Hedgehog/Base/Container/hhList.h>
#include <Hedgehog/Base/Container/hhMap.h>
#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Base/Thread/hhSynchronizedObject.h>
#include <Hedgehog/Base/Thread/hhSynchronizedPtr.h>

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Universe/Engine/hhUpdateManager.h>

namespace Hedgehog::Database
{
    class CDatabase;
}
namespace Hedgehog::Mirage
{
    class CDebugDraw;
    class CLightFieldManager;
}

// TODO: Move elsewhere
namespace Hedgehog::Sound
{
    class CSoundHandle : public Hedgehog::Base::CObject
    {
    public:

        // TOOD: need virtual destructor later in the vtable

        virtual void* CSoundHandle00(void* a1) { return nullptr; }
        virtual void* CSoundHandle04(void* a1) { return nullptr; }
        virtual void* CSoundHandle08() {}
        virtual void* SetPaused(bool a1, bool a2) { return nullptr; }
        virtual void* Stop(void* a1) { return nullptr; }
        virtual void* SetCue(const Hedgehog::Base::CSharedString& in_cueName) { return nullptr; }
        virtual void* SetCueByID(uint32_t in_cueID) { return nullptr; }
        virtual void* CSoundHandle1C(void* a1) { return nullptr; }
        virtual void* CSoundHandle20(void* a1) { return nullptr; }
        virtual void  SetFloat1(float a1) {}
        virtual float GetFloat1() { return 0; }
        virtual void  SetEcho(float a1) {}
        virtual float GetEcho() { return 0; }
        virtual void  SetFloat3(float a1) {}
        virtual float GetFloat3() { return 0; }
    	virtual void* CSoundHandle3C() { return nullptr; }
        virtual void* SetAutoLoop(bool a1) { return nullptr; }
        virtual void* CSoundHandle44() { return nullptr; }
        virtual bool  CSoundHandle48(int a1) { return false; }
        virtual void* CSoundHandle4C(void* a1) { return nullptr; }
        virtual void* CSoundHandle50(void* a1) { return nullptr; }
        virtual void* CSoundHandle54(void* a1) { return nullptr; }
        virtual void* CSoundHandle58(void* a1) { return nullptr; }

        virtual ~CSoundHandle() = default; // 24th entry

        virtual void* CSoundHandle60(void* a1) { return nullptr; }
        virtual void* CSoundHandle64() { return nullptr; }
        virtual void* CSoundHandle68(void* a1, void* a2) { return nullptr; }

        virtual void* GetSoundPlayer() = 0;


        int m_Field004;
        int m_Field008;
        int m_Field00C;
        int m_Field010;
        int m_Field014;
        int m_Field018;
        int m_Field01C;
        int m_Field020;
        int m_Field024;
        int m_Field028;
        int m_Field02C;
        int m_Field030;
        int m_Field034;
        float m_Field038;
        int m_Field03C;
        int m_Field040;
        boost::shared_ptr<void> m_spSoundCommandProcessor;
        int m_Field04C;
        int m_Field050;
        int m_Field054;
        int m_Field058;
        int m_Field05C;
        char m_Field060;
        int m_Field064;
        char m_Field068;
        char field_69;
        char field_6A;
        int m_Field06C;
    };
    class CSoundHandleCri : public CSoundHandle
    {
    public:
        int m_Field070;
        int m_Field074;
        int m_Field078;
        int m_Field07C;

        virtual void* GetSoundPlayer() { return nullptr; }
    };
    class CSoundHandleBgm : public CSoundHandleCri
    {
    public:
        int m_Field080;
        int m_Field084;
        int m_Field088;
        int m_Field08C;
    };
}

namespace Sonic
{
    namespace Mission
    {
        class CMissionManager;
    }

    class CGameDocument;
    class CGameObject;
    class CLightManager;
    class CRenderDirector;
    class CWorld;
    class CParticleManager;
    class CParameterBank;
    class CNextStagePreloadingManager;
    class CEventManager;
    class CPathManager;

    class CSetObjectManager;
    class CActivationManager;
    class CObjectInfoManager;
    class CObjectPhysicsParamContainer;
    class CInstancerManager;
    class CVisibilityCullingManager;
    class CPVsManager;
    class CScoreManager;

    // TODO: Move elsewhere & rename
    struct SBGMData
    {
        boost::shared_ptr<Hedgehog::Sound::CSoundHandleBgm> m_spSoundHandleBGM;
        Hedgehog::Base::CSharedString m_SongName;
        BB_INSERT_PADDING(0x04);
        float m_Volume;
        float m_PlaybackSpeed;
    };
    BB_ASSERT_SIZEOF(SBGMData, 0x18);

    static inline BB_FUNCTION_PTR(void, __stdcall, fpAddGameObject, 0xD631A0,
        CGameDocument* in_pGameDocument, const Hedgehog::Base::THolder<CWorld>& in_rWorldHolder,
        const boost::shared_ptr<CGameObject>& in_spGameObject, boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase,
        CGameObject* in_pParentGameObject);

    // TODO: Move elsewhere
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
        boost::shared_ptr<CPVsManager> m_spPVsManager;
        CPVsManager* m_pPVsManager;
        BB_INSERT_PADDING(0x0C) {};
        boost::shared_ptr<Mission::CMissionManager> m_spMissionManager;
        boost::shared_ptr<CScoreManager> m_spScoreManager;

        virtual ~CGameActParameter() = default;
    };
    BB_ASSERT_OFFSETOF(CGameActParameter, m_pSetObjectManager, 0x14);

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
            m_pMember->m_spUpdateManager->Add(in_rCategory, in_pUpdateUnit);
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