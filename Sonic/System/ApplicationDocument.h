#pragma once

#include <Hedgehog/Base/Thread/hhSynchronizedObject.h>
#include <Hedgehog/Base/Thread/hhSynchronizedPtr.h>
#include <Hedgehog/Universe/Engine/hhMessageManager.h>

namespace Hedgehog::Database
{
    class CDatabase;
    class CDatabaseLoader;
}
namespace Hedgehog::Universe
{
    class CParallelJobManagerD3D9;
}
namespace Hedgehog::Mirage
{
    class CRenderingInfrastructure;
    class CRenderFramework;
}
namespace Hedgehog::FxRenderFramework
{
    class CFxPipelineExecutor;
}
namespace Hedgehog::Universe
{
    class CService;
}
namespace Sonic::Hud::ResidentLoading
{
    class CResidentLoadingImpl;
}
namespace Sonic::Sequence
{
    class CSequenceMainImpl;
}
namespace Sonic::Achievement
{
    class CManager;
}
namespace Sonic::Event
{
    class CEventQueue;
}

namespace Sonic
{
    class CApplication;
    class CParameterEditor;
    class CGameParameter;
    class CRenderDirectorMTFx;
    class CSaveIcon;
    class CHudLoading;
    class CDatabaseTree;
    class CGameplayFlowManager;
    class CPlayerProperty;
    class CGammaController;

	enum ELanguage : uint8_t
	{
		eLanguage_English,
		eLanguage_Japanese,
		eLanguage_French,
		eLanguage_German,
		eLanguage_Spanish,
		eLanguage_Italian
	};
    class CApplicationDocument : public Hedgehog::Base::CSynchronizedObject
    {
    public:
        class CMember : public Hedgehog::Base::CObject
        {
        public:
            BB_INSERT_PADDING(0x10);
            CApplication* m_pApplication;
            boost::shared_ptr<Hedgehog::Universe::CParallelJobManagerD3D9> m_spParallelJobManagerD3D9;
            Hedgehog::Universe::CMessageManager* m_pMessageManager;
            boost::shared_ptr<Hedgehog::Universe::CUpdateManager> m_spUpdateManager;
            boost::shared_ptr<Hedgehog::Universe::CUpdateManager> m_spUpdateManager2;
            CGameplayFlowManager* m_pGameplayFlowManager;
            Hedgehog::Mirage::CRenderFramework* m_pRenderFramework;
            boost::shared_ptr<Hedgehog::Mirage::CRenderingInfrastructure> m_spRenderingInfrastructure;
            Hedgehog::Mirage::CGlobalParametersData* m_pGlobalParametersData;
            boost::shared_ptr<CRenderDirectorMTFx> m_spRenderDirectorMTFx;
            void* m_Field50;
            boost::shared_ptr<Hedgehog::FxRenderFramework::CFxPipelineExecutor> m_spFxPipelineExecutor;
            BB_INSERT_PADDING(0x24);
            boost::shared_ptr<Hedgehog::Database::CDatabase> m_spApplicationDatabase;
            boost::shared_ptr<Hedgehog::Database::CDatabase> m_spShaderDatabase;
            BB_INSERT_PADDING(0xE);
            boost::shared_ptr<Hedgehog::Database::CDatabase> m_spDatabase;
            BB_INSERT_PADDING(0x20);
            boost::shared_ptr<Hedgehog::Database::CDatabaseLoader> m_spDatabaseLoader;
            BB_INSERT_PADDING(0x18);
            boost::shared_ptr<Hedgehog::Mirage::CMatrixNode> m_spMatrixNodeRoot;
            BB_INSERT_PADDING(0x10);
            CGammaController m_GammaController;
            boost::anonymous_shared_ptr m_Field140;
            boost::shared_ptr<CHudLoading> m_spHudLoading;
            boost::shared_ptr<CSaveIcon> m_spSaveIcon;
            boost::anonymous_shared_ptr m_Field158;
            boost::shared_ptr<Hud::ResidentLoading::CResidentLoadingImpl> m_spResidentLoading;
            boost::shared_ptr<Sequence::CSequenceMainImpl> m_spSequenceMain;
            boost::shared_ptr<Achievement::CManager> m_spAchievementManager;
            boost::shared_ptr<Event::CEventQueue> m_spEventQueue;
            boost::shared_ptr<CDatabaseTree> m_spDatabaseTree;
            Hedgehog::Base::CSharedString m_Field188;
            int32_t m_Field18C;
            int32_t m_Field190;
            int32_t m_Field194;
            int32_t m_Field198;
            boost::shared_ptr<Hedgehog::Base::CCriticalSectionD3D9> m_spCriticalSectionD3D9;
            void* m_Field1A4;
            boost::shared_ptr<Hedgehog::Mirage::CRenderScene> m_spRenderScene;
            void* m_Field1B0;
            boost::shared_ptr<CGameParameter> m_spGameParameter;
            BB_INSERT_PADDING(0x48);
            boost::shared_ptr<CParameterEditor> m_spParameterEditor;
            int32_t m_Field20C;
            CPlayerProperty* m_pPlayerProperty;
            boost::shared_ptr<CPlayerProperty> m_spPlayerProperty;
            BB_INSERT_PADDING(0x14);

            virtual ~CMember() = default;
        };

        static constexpr Hedgehog::Base::TSynchronizedPtr<CApplicationDocument>* ms_pInstance = (Hedgehog::Base::TSynchronizedPtr<CApplicationDocument>*)0x1E66B34;

        static Hedgehog::Base::TSynchronizedPtr<CApplicationDocument> GetInstance();

        CMember* m_pMember;
        ELanguage m_UILanguage;
        BB_INSERT_PADDING(0x2B);
        hh::map<uint32_t, boost::shared_ptr<Hedgehog::Universe::CService>> m_ServiceMap;

        void AddMessageActor(const Hedgehog::Base::CSharedString& in_rCategory, Hedgehog::Universe::CMessageActor* in_pMessageActor);

        template<typename T>
        T* GetService() const;
    };

    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_pApplication, 0x14);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_pMessageManager, 0x20);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spUpdateManager, 0x24);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spUpdateManager2, 0x2C);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_pGameplayFlowManager, 0x34);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_pRenderFramework, 0x38);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spRenderingInfrastructure, 0x3C);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_pGlobalParametersData, 0x44);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spRenderDirectorMTFx, 0x48);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_Field50, 0x50);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spFxPipelineExecutor, 0x54);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spApplicationDatabase, 0x80);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spShaderDatabase, 0x88);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spDatabase, 0xA0);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spDatabaseLoader, 0xC8);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spMatrixNodeRoot, 0xE8);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_GammaController, 0x100);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_Field140, 0x140);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spHudLoading, 0x148);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spSaveIcon, 0x150);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_Field158, 0x158);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spResidentLoading, 0x160);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spSequenceMain, 0x168);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spAchievementManager, 0x170);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spEventQueue, 0x178);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spDatabaseTree, 0x180);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_Field188, 0x188);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_Field18C, 0x18C);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_Field190, 0x190);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_Field194, 0x194);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_Field198, 0x198);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_Field198, 0x198);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spCriticalSectionD3D9, 0x19C);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_Field1A4, 0x1A4);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spRenderScene, 0x1A8);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_Field1B0, 0x1B0);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spGameParameter, 0x1B4);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spParameterEditor, 0x204);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_Field20C, 0x20C);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_pPlayerProperty, 0x210);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spPlayerProperty, 0x214);
    BB_ASSERT_SIZEOF(CApplicationDocument::CMember, 0x230);

    BB_ASSERT_OFFSETOF(CApplicationDocument, m_pMember, 0x4);
    BB_ASSERT_OFFSETOF(CApplicationDocument, m_UILanguage, 0x8);
    BB_ASSERT_OFFSETOF(CApplicationDocument, m_ServiceMap, 0x34);
    BB_ASSERT_SIZEOF(CApplicationDocument, 0x40);
}

#include <Sonic/System/ApplicationDocument.inl>