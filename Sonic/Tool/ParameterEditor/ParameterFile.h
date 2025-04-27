#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Sonic/Tool/ParameterEditor/AbstractParameter.h>

namespace Sonic
{
    class CParameterGroup;

    class CParameterFile : public CAbstractParameter
    {
    public:
        static constexpr void* ms_pVfTable = (void*)0x16E5E88;

        boost::shared_ptr<CParameterGroup> CreateParameterGroup(const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription);
    };

    BB_ASSERT_SIZEOF(CParameterFile, 0x34);
}

#include <Sonic/Tool/ParameterEditor/ParameterFile.inl>