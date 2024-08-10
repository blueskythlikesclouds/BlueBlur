#pragma once

#include <Sonic/Tool/ParameterEditor/AbstractParameterNode.h>

namespace Sonic
{
    class CParameterCategory : public CAbstractParameterNode
    {
    public:
        static constexpr void* ms_pVfTable = (void*)0x16E5FFC;

        BB_INSERT_PADDING(0xC);
    };

    BB_ASSERT_SIZEOF(CParameterCategory, 0x48);
}