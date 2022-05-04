#pragma once

#include <CSD/Manager/csdmRCPtr.h>
#include <Hedgehog/Base/Platform/D3D9/hhCriticalSectionD3D9.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Chao::CSD
{
    class CProject;
}

namespace Sonic
{
    class CCsdProject : public Hedgehog::Database::CDatabaseData
    {
    public:
        Chao::CSD::RCPtr<Chao::CSD::CProject> m_rcProject;
        boost::shared_ptr<Hedgehog::Base::CCriticalSectionD3D9> m_spCriticalSection;
    };

    BB_ASSERT_OFFSETOF(CCsdProject, m_rcProject, 0xC);
    BB_ASSERT_OFFSETOF(CCsdProject, m_spCriticalSection, 0x14);
    BB_ASSERT_SIZEOF(CCsdProject, 0x1C);
}