#pragma once

#include <Hedgehog/Base/Container/hhMap.h>
#include <Hedgehog/Base/System/hhSymbol.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CVertexShaderData;
    class CPixelShaderData;

    class CVertexShaderPermutationData
    {
    public:
        map<size_t, boost::shared_ptr<CVertexShaderData>> m_VertexShaders;
        size_t m_SubPermutations;
    };

    BB_ASSERT_OFFSETOF(CVertexShaderPermutationData, m_VertexShaders, 0x0);
    BB_ASSERT_OFFSETOF(CVertexShaderPermutationData, m_SubPermutations, 0xC);
    BB_ASSERT_SIZEOF(CVertexShaderPermutationData, 0x10);

    class CPixelShaderPermutationData
    {
    public:
        map<Base::CStringSymbol, boost::shared_ptr<CVertexShaderPermutationData>> m_VertexShaderPermutations;
        map<size_t, boost::shared_ptr<CPixelShaderData>> m_PixelShaders;
        size_t m_SubPermutations;
        BB_INSERT_PADDING(0x4);
    };

    BB_ASSERT_OFFSETOF(CPixelShaderPermutationData, m_VertexShaderPermutations, 0x0);
    BB_ASSERT_OFFSETOF(CPixelShaderPermutationData, m_PixelShaders, 0xC);
    BB_ASSERT_OFFSETOF(CPixelShaderPermutationData, m_SubPermutations, 0x18);
    BB_ASSERT_SIZEOF(CPixelShaderPermutationData, 0x20);

    class CShaderListData : public Database::CDatabaseData
    {
    public:
        map<Base::CStringSymbol, CPixelShaderPermutationData> m_PixelShaderPermutations;
    };

    BB_ASSERT_OFFSETOF(CShaderListData, m_PixelShaderPermutations, 0xC);
    BB_ASSERT_SIZEOF(CShaderListData, 0x18);
}