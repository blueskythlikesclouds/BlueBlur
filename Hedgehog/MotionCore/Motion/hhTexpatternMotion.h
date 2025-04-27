#pragma once

#include <Hedgehog/MotionCore/Motion/hhMotionBase.h>

namespace Hedgehog::Mirage
{
    class CMaterialData;
    class CPictureData;
}

namespace Hedgehog::Motion
{
    class CPtAnimationData;

    class CTexpatternMotion : public CMotionBase
    {
    public:
        boost::shared_ptr<CPtAnimationData> m_spPtAnimationData;
        Mirage::CMaterialData* m_pMaterialData{};
        int32_t m_Register0{ -1 };
        int32_t m_Register1{ -1 };
        Mirage::CPictureData* m_pPictureData{};
    };

    BB_ASSERT_OFFSETOF(CTexpatternMotion, m_spPtAnimationData, 0x18);
    BB_ASSERT_OFFSETOF(CTexpatternMotion, m_pMaterialData, 0x20);
    BB_ASSERT_OFFSETOF(CTexpatternMotion, m_Register0, 0x24);
    BB_ASSERT_OFFSETOF(CTexpatternMotion, m_Register1, 0x28);
    BB_ASSERT_OFFSETOF(CTexpatternMotion, m_pPictureData, 0x2C);
    BB_ASSERT_SIZEOF(CTexpatternMotion, 0x30);
}