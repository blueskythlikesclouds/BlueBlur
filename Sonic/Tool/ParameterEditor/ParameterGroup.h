#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Sonic/Tool/ParameterEditor/AbstractParameterNode.h>

namespace Sonic
{
    class CParameterGroup : public CAbstractParameterNode
    {
    public:
        static constexpr void* ms_pVfTable = (void*)0x16E5FA4;

        CEditParam* CreateParameterCategory(
            const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription);

        void Flush();
    };

    BB_ASSERT_SIZEOF(CParameterGroup, 0x3C);
}

#include <Sonic/Tool/ParameterEditor/ParameterGroup.inl>