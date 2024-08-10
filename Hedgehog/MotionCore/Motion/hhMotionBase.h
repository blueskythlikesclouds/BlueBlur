#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Motion
{
    enum EMotionType
    {
        eMotionType_MaterialMotion = 1,
        eMotionType_TexcoordMotion = 2,
        eMotionType_TexpatternMotion = 3,
        eMotionType_VisibilityMotion = 4,
        eMotionType_MorphMotion = 5
    };

    class CMotionBase
    {
    public:
        uint32_t m_Field4{};
        uint32_t m_MotionType;
        uint32_t m_FieldC{ 1 };
        float m_Field10{0.0f};
        float m_Field14{1.0f};

        CMotionBase(uint32_t in_MotionType)
            : m_MotionType(in_MotionType)
        {
        }

        virtual ~CMotionBase() {}
    };

    BB_ASSERT_OFFSETOF(CMotionBase, m_Field4, 0x4);
    BB_ASSERT_OFFSETOF(CMotionBase, m_MotionType, 0x8);
    BB_ASSERT_OFFSETOF(CMotionBase, m_FieldC, 0xC);
    BB_ASSERT_OFFSETOF(CMotionBase, m_Field10, 0x10);
    BB_ASSERT_OFFSETOF(CMotionBase, m_Field14, 0x14);
    BB_ASSERT_SIZEOF(CMotionBase, 0x18);
}