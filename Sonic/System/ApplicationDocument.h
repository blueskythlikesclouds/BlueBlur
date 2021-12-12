#pragma once

#include <BlueBlur.inl>

#include <Hedgehog/Base/Thread/hhHolder.h>
#include <Hedgehog/Base/Thread/hhSynchronizedObject.h>
#include <Hedgehog/Universe/Engine/hhMessageManager.h>

namespace Sonic
{
    class CApplicationDocument : public Hedgehog::Base::CSynchronizedObject
    {
    public:
        class CMember
        {
        public:
            BB_INSERT_PADDING(0x20);
            Hedgehog::Universe::CMessageManager* m_pMessageManager;
            BB_INSERT_PADDING(0x20C);
        };

        static constexpr CApplicationDocument** ms_pInstance = (CApplicationDocument**)0x1E66B34;

        static Hedgehog::Base::THolder<CApplicationDocument> GetInstance()
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
    BB_ASSERT_SIZEOF(CApplicationDocument::CMember, 0x230);

    BB_ASSERT_OFFSETOF(CApplicationDocument, m_pMember, 0x4);
    BB_ASSERT_SIZEOF(CApplicationDocument, 0x40);
}