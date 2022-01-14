#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Sonic
{
    class CEditParam;

    class CAbstractParameter : public Hedgehog::Base::CObject
    {
    public:
        CEditParam* m_pEditParam;
        Hedgehog::Base::CSharedString m_Name;
        Hedgehog::Base::CSharedString m_Description;
        hh::vector<boost::shared_ptr<CAbstractParameter>> m_Children;
        BB_INSERT_PADDING(0x14);

        virtual ~CAbstractParameter() = default;
    };

    BB_ASSERT_OFFSETOF(CAbstractParameter, m_pEditParam, 0x4);
    BB_ASSERT_OFFSETOF(CAbstractParameter, m_Name, 0x8);
    BB_ASSERT_OFFSETOF(CAbstractParameter, m_Description, 0xC);
    BB_ASSERT_OFFSETOF(CAbstractParameter, m_Children, 0x10);
    BB_ASSERT_SIZEOF(CAbstractParameter, 0x34);
}