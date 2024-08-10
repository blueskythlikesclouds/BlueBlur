#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CPixelShaderCodeData;
    class CPixelShaderParameterData;

    class CPixelShaderData : public Hedgehog::Database::CDatabaseData
    {
    public:
        boost::shared_ptr<CPixelShaderCodeData> m_spCode;
        hh::vector<boost::shared_ptr<CPixelShaderParameterData>> m_ParameterList;            
    };

    BB_ASSERT_OFFSETOF(CPixelShaderData, m_spCode, 0xC);
    BB_ASSERT_OFFSETOF(CPixelShaderData, m_ParameterList, 0x14);
    BB_ASSERT_SIZEOF(CPixelShaderData, 0x24);
}
