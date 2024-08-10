#pragma once

#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Base
{
    class CCriticalSectionD3D9;
}

namespace Hedgehog::Mirage
{
    class CRenderingInfrastructure;

    class CPixelShaderCodeData : public Database::CDatabaseData
    {
    public:
        DX_PATCH::IDirect3DPixelShader9* m_pD3DPixelShader;
        boost::shared_ptr<uint8_t[]> m_spFunction;
        size_t m_FunctionSize;
        boost::shared_ptr<Base::CCriticalSectionD3D9> m_spCriticalSection;
        CRenderingInfrastructure* m_pRenderingInfrastructure;
    };

    BB_ASSERT_OFFSETOF(CPixelShaderCodeData, m_pD3DPixelShader, 0xC);
    BB_ASSERT_OFFSETOF(CPixelShaderCodeData, m_spFunction, 0x10);
    BB_ASSERT_OFFSETOF(CPixelShaderCodeData, m_FunctionSize, 0x18);
    BB_ASSERT_OFFSETOF(CPixelShaderCodeData, m_spCriticalSection, 0x1C);
    BB_ASSERT_OFFSETOF(CPixelShaderCodeData, m_pRenderingInfrastructure, 0x24);
    BB_ASSERT_SIZEOF(CPixelShaderCodeData, 0x28);
}