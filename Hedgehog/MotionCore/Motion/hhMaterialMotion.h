#pragma once

#include <Hedgehog/MotionCore/Motion/hhMotionBase.h>

namespace Hedgehog::Mirage
{
    class CMaterialData;
}

namespace Hedgehog::Motion
{
    class CMaterialAnimationData;

    struct SMaterialMotionData
    {
        float Diffuse[4];
        float Ambient[4];
        float Specular[4];
        float Emissive[4];
        float PowerGlossLevel[4];
        float OpacityReflectionRefractionSpectype[4];
    };

    class CMaterialMotion : public CMotionBase
    {
    public:
        boost::shared_ptr<CMaterialAnimationData> m_spMaterialAnimationData;
        Mirage::CMaterialData* m_pMaterialData{};
        SMaterialMotionData m_MaterialMotionData;
        SMaterialMotionData m_DefaultMaterialMotionData;
    };

    BB_ASSERT_OFFSETOF(CMaterialMotion, m_spMaterialAnimationData, 0x18);
    BB_ASSERT_OFFSETOF(CMaterialMotion, m_pMaterialData, 0x20);
    BB_ASSERT_OFFSETOF(CMaterialMotion, m_MaterialMotionData, 0x24);
    BB_ASSERT_OFFSETOF(CMaterialMotion, m_DefaultMaterialMotionData, 0x84);
    BB_ASSERT_SIZEOF(CMaterialMotion, 0xE4);
}