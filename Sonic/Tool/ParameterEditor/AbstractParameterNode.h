#pragma once

#include <Sonic/Tool/ParameterEditor/AbstractParameter.h>

namespace Sonic
{
    class CAbstractParameterNode : public CAbstractParameter
    {
    public:
        BB_INSERT_PADDING(0x8);
    };

    BB_ASSERT_SIZEOF(CAbstractParameterNode, 0x3C);
}