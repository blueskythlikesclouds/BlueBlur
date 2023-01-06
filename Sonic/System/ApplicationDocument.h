#pragma once

#include <Hedgehog/Base/Thread/hhSynchronizedObject.h>
#include <Hedgehog/Base/Thread/hhSynchronizedPtr.h>
#include <Hedgehog/Universe/Engine/hhMessageManager.h>

namespace Hedgehog::Database
{
    class CDatabaseLoader;
}

namespace Sonic
{
    class CApplicationDocument : public Hedgehog::Base::CSynchronizedObject
    {
    public:
        class CMember
        {
        public:
            BB_INSERT_PADDING(0x1C);
            Hedgehog::Universe::CMessageManager* m_pMessageManager;
            BB_INSERT_PADDING(0xA4);
            boost::shared_ptr<Hedgehog::Database::CDatabaseLoader> m_spDatabaseLoader;
            BB_INSERT_PADDING(0x160);

            virtual ~CMember() = default;
        };

        static constexpr Hedgehog::Base::TSynchronizedPtr<CApplicationDocument>* ms_pInstance = (Hedgehog::Base::TSynchronizedPtr<CApplicationDocument>*)0x1E66B34;

        static Hedgehog::Base::TSynchronizedPtr<CApplicationDocument> GetInstance()
        {
            return *ms_pInstance;
        }

        CMember* m_pMember;
        BB_INSERT_PADDING(0x38);

        void AddMessageActor(const Hedgehog::Base::CSharedString& category, Hedgehog::Universe::CMessageActor* pMessageActor)
        {
            m_pMember->m_pMessageManager->Add(category, pMessageActor);
        }
    };

    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_pMessageManager, 0x20);
    BB_ASSERT_OFFSETOF(CApplicationDocument::CMember, m_spDatabaseLoader, 0xC8);
    BB_ASSERT_SIZEOF(CApplicationDocument::CMember, 0x230);

    BB_ASSERT_OFFSETOF(CApplicationDocument, m_pMember, 0x4);
    BB_ASSERT_SIZEOF(CApplicationDocument, 0x40);
}