﻿#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CLightData;

    class CLightListData : public Hedgehog::Database::CDatabaseData
    {
    public:
        hh::vector<boost::shared_ptr<CLightData>> m_Lights;
    };

    BB_ASSERT_OFFSETOF(CLightListData, m_Lights, 0xC);
    BB_ASSERT_SIZEOF(CLightListData, 0x1C);
}