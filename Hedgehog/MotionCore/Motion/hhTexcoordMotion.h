#pragma once

#include <Hedgehog/MotionCore/Motion/hhMotionBase.h>

namespace Hedgehog::Mirage
{
    class CMaterialData;
}

namespace Hedgehog::Motion
{
    class CTexcoordAnimationData;

    class CTexcoordMotion : public CMotionBase
    {
    public:
        boost::shared_ptr<CTexcoordAnimationData> m_spTexcoordAnimationData;
        Mirage::CMaterialData* m_pMaterialData{};
        int32_t m_TexcoordIndex{ -1 };
        float m_TexcoordOffset[8]{};
        uint32_t m_Field48{};
        uint32_t m_Field4C{};
    };

    BB_ASSERT_OFFSETOF(CTexcoordMotion, m_spTexcoordAnimationData, 0x18);
    BB_ASSERT_OFFSETOF(CTexcoordMotion, m_pMaterialData, 0x20);
    BB_ASSERT_OFFSETOF(CTexcoordMotion, m_TexcoordIndex, 0x24);
    BB_ASSERT_OFFSETOF(CTexcoordMotion, m_TexcoordOffset, 0x28);
    BB_ASSERT_OFFSETOF(CTexcoordMotion, m_Field48, 0x48);
    BB_ASSERT_OFFSETOF(CTexcoordMotion, m_Field4C, 0x4C);
    BB_ASSERT_SIZEOF(CTexcoordMotion, 0x50);
}