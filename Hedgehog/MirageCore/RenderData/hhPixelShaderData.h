#pragma once

#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CPixelShaderData : public Hedgehog::Database::CDatabaseData
    {
    public:
        BB_INSERT_PADDING(0x18);
    };

    BB_ASSERT_SIZEOF(CPixelShaderData, 0x24);
}
