#pragma once

#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Base
{
    class CCriticalSectionD3D9;
}

namespace Hedgehog::Mirage
{
    class CRenderingInfrastructure;

    class CVertexShaderCodeData : public Database::CDatabaseData
    {
    public:
        DX_PATCH::IDirect3DVertexShader9* m_pD3DVertexShader;
        boost::shared_ptr<uint8_t[]> m_spFunction;
        size_t m_FunctionSize;
        boost::shared_ptr<Base::CCriticalSectionD3D9> m_spCriticalSection;
        CRenderingInfrastructure* m_pRenderingInfrastructure;
    };

    BB_ASSERT_OFFSETOF(CVertexShaderCodeData, m_pD3DVertexShader, 0xC);
    BB_ASSERT_OFFSETOF(CVertexShaderCodeData, m_spFunction, 0x10);
    BB_ASSERT_OFFSETOF(CVertexShaderCodeData, m_FunctionSize, 0x18);
    BB_ASSERT_OFFSETOF(CVertexShaderCodeData, m_spCriticalSection, 0x1C);
    BB_ASSERT_OFFSETOF(CVertexShaderCodeData, m_pRenderingInfrastructure, 0x24);
    BB_ASSERT_SIZEOF(CVertexShaderCodeData, 0x28);
}