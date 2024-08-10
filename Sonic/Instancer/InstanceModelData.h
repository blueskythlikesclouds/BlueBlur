#pragma once

#include <Sonic/Instancer/MetaInstancer.h>

namespace Hedgehog::Mirage
{
    class CTextureData;
    class CVertexShaderData;
    class CPixelShaderData;
    class CMeshData;
}

namespace Sonic
{
    class CInstanceModelData : public Hedgehog::Base::CObject, public CMetaInstancer::CCloneable<CInstanceModelData>
    {
    public:
        uint32_t m_Field4;
        boost::shared_ptr<Hedgehog::Mirage::CTextureData> m_aTextureData[4];
        boost::shared_ptr<Hedgehog::Mirage::CVertexShaderData> m_spVertexShaderData;
        boost::shared_ptr<Hedgehog::Mirage::CPixelShaderData> m_spPixelShaderData;
        boost::shared_ptr<Hedgehog::Mirage::CMeshData> m_spMeshData;
    };

    BB_ASSERT_OFFSETOF(CInstanceModelData, m_Field4, 0x4);
    BB_ASSERT_OFFSETOF(CInstanceModelData, m_aTextureData, 0x8);
    BB_ASSERT_OFFSETOF(CInstanceModelData, m_spVertexShaderData, 0x28);
    BB_ASSERT_OFFSETOF(CInstanceModelData, m_spPixelShaderData, 0x30);
    BB_ASSERT_OFFSETOF(CInstanceModelData, m_spMeshData, 0x38);
    BB_ASSERT_SIZEOF(CInstanceModelData, 0x40);
}