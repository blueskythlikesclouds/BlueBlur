#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/System/hhSymbol.h>

namespace Hedgehog::Mirage
{
    class CVertexShaderParameterData;
    class CPixelShaderParameterData;

    struct SShaderConstant
    {
        uint8_t Register;
        uint8_t Size;
    };

    class CGlobalParametersData : public Base::CObject
    {
    public:
        Base::CStringSymbol m_ConstantNames[90];

        SShaderConstant m_VertexFloat4Constants[90];
        SShaderConstant m_PixelFloat4Constants[90];

        SShaderConstant m_VertexInt4Constants[90];
        SShaderConstant m_PixelInt4Constants[90];

        SShaderConstant m_VertexBoolConstants[90];
        SShaderConstant m_PixelBoolConstants[90];

        boost::shared_ptr<CVertexShaderParameterData> m_spGlobalVertexShaderParameterData;
        boost::shared_ptr<CPixelShaderParameterData> m_spGlobalPixelShaderParameterData;

        virtual ~CGlobalParametersData() = default;
    };

    BB_ASSERT_OFFSETOF(CGlobalParametersData, m_ConstantNames, 0x4);
    BB_ASSERT_OFFSETOF(CGlobalParametersData, m_VertexFloat4Constants, 0x16C);
    BB_ASSERT_OFFSETOF(CGlobalParametersData, m_PixelFloat4Constants, 0x220);
    BB_ASSERT_OFFSETOF(CGlobalParametersData, m_VertexInt4Constants, 0x2D4);
    BB_ASSERT_OFFSETOF(CGlobalParametersData, m_PixelInt4Constants, 0x388);
    BB_ASSERT_OFFSETOF(CGlobalParametersData, m_VertexBoolConstants, 0x43C);
    BB_ASSERT_OFFSETOF(CGlobalParametersData, m_PixelBoolConstants, 0x4F0);
    BB_ASSERT_OFFSETOF(CGlobalParametersData, m_spGlobalVertexShaderParameterData, 0x5A4);
    BB_ASSERT_OFFSETOF(CGlobalParametersData, m_spGlobalPixelShaderParameterData, 0x5AC);
    BB_ASSERT_SIZEOF(CGlobalParametersData, 0x5B4);
}
