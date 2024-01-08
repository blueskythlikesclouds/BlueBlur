#pragma once

#include <Hedgehog/Base/Thread/hhSynchronizedObject.h>
#include <Hedgehog/Base/Thread/hhSynchronizedPtr.h>
#include <Hedgehog/Universe/Engine/hhMessageManager.h>

namespace Hedgehog::Database
{
    class CDatabase;
    class CDatabaseLoader;
}

namespace Hedgehog::Mirage
{
    class CRenderingInfrastructure;
}

namespace Sonic
{
    class CApplication;
    class CParameterEditor;

    class CApplicationDocument : public Hedgehog::Base::CSynchronizedObject
    {
    public:
        class CMember
        {
        public:
            BB_INSERT_PADDING(0x10);
            CApplication* m_pApplication;
            BB_INSERT_PADDING(0x8);
            Hedgehog::Universe::CMessageManager* m_pMessageManager;
            BB_INSERT_PADDING(0x18);
            boost::shared_ptr<Hedgehog::Mirage::CRenderingInfrastructure> m_spRenderingInfrastructure;
            BB_INSERT_PADDING(0x3C);
            boost::shared_ptr<Hedgehog::Database::CDatabase> m_spApplicationDatabase;
            boost::shared_ptr<Hedgehog::Database::CDatabase> m_spShaderDatabase;
            BB_INSERT_PADDING(0x10);
            boost::shared_ptr<Hedgehog::Database::CDatabase> m_spDatabase;
            BB_INSERT_PADDING(0x20);
            boost::shared_ptr<Hedgehog::Database::CDatabaseLoader> m_spDatabaseLoader;
            BB_INSERT_PADDING(0x18);
            boost::shared_ptr<Hedgehog::Mirage::CMatrixNode> m_spMatrixNodeRoot;
            BB_INSERT_PADDING(0x114);
            boost::shared_ptr<CParameterEditor> m_spParameterEditor;
            BB_INSERT_PADDING(0x24);

            virtual ~CMember() = default;
        };

        static constexpr Hedgehog::Base::TSynchronizedPtr<CApplicationDocument>* ms_pInstance = (Hedgehog::Base::TSynchronizedPtr<CApplicationDocument>*)0x1E66B34;

        static Hedgehog::Base::TSynchronizedPtr<CApplicationDocument> GetInstance();

        CMember* m_pMember;
        BB_INSERT_PADDING(0x38);

        void AddMessageActor(const Hedgehog::Base::CSharedString& in_rCategory, Hedgehog::Universe::CMessageActor* in_pMessageActor);
    };

    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_pApplication, 0x14);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_pMessageManager, 0x20);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spRenderingInfrastructure, 0x3C);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spApplicationDatabase, 0x80);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spShaderDatabase, 0x88);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spDatabase, 0xA0);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spDatabaseLoader, 0xC8);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spMatrixNodeRoot, 0xE8);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spParameterEditor, 0x204);
    BB_ASSERT_SIZEOF(CApplicationDocument::CMember, 0x230);

    BB_ASSERT_OFFSETOF(CApplicationDocument, m_pMember, 0x4);
    BB_ASSERT_SIZEOF(CApplicationDocument, 0x40);
}

#include <Sonic/System/ApplicationDocument.inl>