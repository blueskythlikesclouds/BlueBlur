#pragma once

#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CVertexShaderData : public Database::CDatabaseData
    {
    public:
        BB_INSERT_PADDING(0x18);
    };

    BB_ASSERT_SIZEOF(CVertexShaderData, 0x24);
}
