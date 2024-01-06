#pragma once

#include <Hedgehog/Base/Container/hhList.h>
#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Sonic/Tool/ParameterEditor/GlobalParameterManager.h>
#include <Sonic/Tool/ParameterEditor/ParameterFile.h>

namespace Sonic
{
    class CParameterFile;

    class CGlobalParameterManager
    {
    public:
        hh::list<boost::shared_ptr<CParameterFile>> m_GlobalParameterFileList;
        hh::list<boost::shared_ptr<CParameterFile>> m_LocalParameterFileList;

        boost::shared_ptr<CParameterFile> CreateParameterFile(const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription);
    };

    BB_ASSERT_OFFSETOF(CGlobalParameterManager, m_GlobalParameterFileList, 0x0);
    BB_ASSERT_OFFSETOF(CGlobalParameterManager, m_LocalParameterFileList, 0xC);
    BB_ASSERT_SIZEOF(CGlobalParameterManager, 0x18);
}


#include <Sonic/Tool/ParameterEditor/GlobalParameterManager.inl>