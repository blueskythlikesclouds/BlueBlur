#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/System/hhSymbol.h>

namespace Hedgehog::Mirage
{
    class CVertexShaderParameterData;
    class CPixelShaderParameterData;

    enum EShaderConstant
    {
        eShaderConstant_IsGIEnabled = 0,
        eShaderConstant_MatVPInvertNoTranslate = 1,
        eShaderConstant_BackGroundScale = 2,
        eShaderConstant_SkyParam = 3,
        eShaderConstant_LightScatteringMode = 4,
        eShaderConstant_IsAlphaDepthBlur = 5,
        eShaderConstant_TimeParam = 6,
        eShaderConstant_GIModeParam = 7,
        eShaderConstant_LightDirection = 8,
        eShaderConstant_LightDirection0 = 9,
        eShaderConstant_LightDiffuse0 = 10,
        eShaderConstant_LightSpecular0 = 11,
        eShaderConstant_AmbientColor = 12,
        eShaderConstant_GI0Scale = 13,
        eShaderConstant_GI1Scale = 14,
        eShaderConstant_InShadowScale = 15,
        eShaderConstant_ShadowMapParams = 16,
        eShaderConstant_GIAtlasParam = 17,
        eShaderConstant_EmissionPower = 18,
        eShaderConstant_LuminanceRange = 19,
        eShaderConstant_IsShadowMapEnable = 20,
        eShaderConstant_ShadowMap_Radius_ChangeStep = 21,
        eShaderConstant_PlayableParam = 22,
        eShaderConstant_MtxBillboardY = 23,
        eShaderConstant_EdgeEmissionParam = 24,
        eShaderConstant_VerticalLightDirection = 25,
        eShaderConstant_ViewZAlphaFade = 26,
        eShaderConstant_MtxProjection = 32,
        eShaderConstant_MtxInvProjection = 33,
        eShaderConstant_MtxView = 34,
        eShaderConstant_MtxWorld = 35,
        eShaderConstant_MtxWorldIT = 36,
        eShaderConstant_MtxPalette = 37,
        eShaderConstant_EyePosition = 38,
        eShaderConstant_EyeDirection = 39,
        eShaderConstant_ViewportSize = 40,
        eShaderConstant_CameraNearFarAspect = 41,
        eShaderConstant_MtxPrevProjection = 42,
        eShaderConstant_MtxPrevView = 43,
        eShaderConstant_MtxPrevWorld = 44,
        eShaderConstant_MtxPrevPalette = 45,
        eShaderConstant_HasBone = 46,
        eShaderConstant_MtxLightViewProjection = 47,
        eShaderConstant_MtxVerticalLightViewProjection = 48,
        eShaderConstant_MtxLightView = 49,
        eShaderConstant_GlobalLight_Direction = 50,
        eShaderConstant_GlobalLight_Diffuse = 51,
        eShaderConstant_GlobalLight_Specular = 52,
        eShaderConstant_LocalLight0_Position = 53,
        eShaderConstant_LocalLight1_Position = 54,
        eShaderConstant_LocalLight2_Position = 55,
        eShaderConstant_LocalLight3_Position = 56,
        eShaderConstant_LocalLight0_Color = 57,
        eShaderConstant_LocalLight1_Color = 58,
        eShaderConstant_LocalLight2_Color = 59,
        eShaderConstant_LocalLight3_Color = 60,
        eShaderConstant_LocalLight0_Range = 61,
        eShaderConstant_LocalLight1_Range = 62,
        eShaderConstant_LocalLight2_Range = 63,
        eShaderConstant_LocalLight3_Range = 64,
        eShaderConstant_LocalLight0_Attribute = 65,
        eShaderConstant_LocalLight1_Attribute = 66,
        eShaderConstant_LocalLight2_Attribute = 67,
        eShaderConstant_LocalLight3_Attribute = 68,
        eShaderConstant_EyeLight_Diffuse = 70,
        eShaderConstant_EyeLight_Specular = 71,
        eShaderConstant_EyeLight_Range = 72,
        eShaderConstant_EyeLight_Attribute = 73,
        eShaderConstant_AmbientColor0 = 74,
        eShaderConstant_GroundColor = 75,
        eShaderConstant_SkyColor = 76,
        eShaderConstant_IsEnableHemisphere = 77,
        eShaderConstant_PowerGlossLevel = 78,
        eShaderConstant_LightField = 79,
        eShaderConstant_VsmEpsilon = 80,
        eShaderConstant_GIAtlasParam0 = 81,
        eShaderConstant_ColourCompressFactor = 82,
        eShaderConstant_ForceAlphaColor = 83,
        eShaderConstant_GlobalLight_Direction_View = 84,
        eShaderConstant_Diffuse = 85,
        eShaderConstant_PlayableParam0 = 86,
        eShaderConstant_TexcoordIndex = 87,
        eShaderConstant_ZOffsetRate = 88,
        eShaderConstant_TexcoordOffset = 89,
        nShaderConstant = 90
    };

    struct SShaderConstant
    {
        uint8_t Register;
        uint8_t Size;
    };

    class CGlobalParametersData : public Base::CObject
    {
    public:
        Base::CStringSymbol m_ConstantNames[nShaderConstant];

        SShaderConstant m_VertexFloat4Constants[nShaderConstant];
        SShaderConstant m_PixelFloat4Constants[nShaderConstant];

        SShaderConstant m_VertexInt4Constants[nShaderConstant];
        SShaderConstant m_PixelInt4Constants[nShaderConstant];

        SShaderConstant m_VertexBoolConstants[nShaderConstant];
        SShaderConstant m_PixelBoolConstants[nShaderConstant];

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