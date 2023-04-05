#pragma once

#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Motion
{
    class CLightSubMotionValueData
    {
    public:
        float m_Data[28];
    };

    BB_ASSERT_SIZEOF(CLightSubMotionValueData, 0x70);

    class CLightSubMotionData
    {
    public:
        BB_INSERT_PADDING(0x24);
        float m_FrameRate;
        float m_StartFrame;
        float m_EndFrame;
        CLightSubMotionValueData m_DefaultValueData;
        BB_INSERT_PADDING(0x8);
    };

    BB_ASSERT_OFFSETOF(CLightSubMotionData, m_FrameRate, 0x24);
    BB_ASSERT_OFFSETOF(CLightSubMotionData, m_StartFrame, 0x28);
    BB_ASSERT_OFFSETOF(CLightSubMotionData, m_EndFrame, 0x2C);
    BB_ASSERT_OFFSETOF(CLightSubMotionData, m_DefaultValueData, 0x30);
    BB_ASSERT_SIZEOF(CLightSubMotionData, 0xA8);

    class CLightMotionData;

    static inline BB_FUNCTION_PTR(void, __cdecl, fpCLightMotionDataStep, 0x758640, 
        CLightMotionData* This, uint32_t in_Index, float in_Frame, CLightSubMotionValueData& in_rValueData, const Math::CMatrix& in_rMatrix);

    class CLightMotionData : public Hedgehog::Database::CDatabaseData
    {
    public:
        uint32_t m_SubMotionCount;
        CLightSubMotionData* m_SubMotions;
        BB_INSERT_PADDING(0xC);

        void Step(uint32_t in_Index, float in_Frame, CLightSubMotionValueData& in_rValueData, const Math::CMatrix& in_rMatrix = Math::CMatrix::Identity())
        {
            fpCLightMotionDataStep(this, in_Index, in_Frame, in_rValueData, in_rMatrix);
        }
    };

    BB_ASSERT_OFFSETOF(CLightMotionData, m_SubMotionCount, 0xC);
    BB_ASSERT_OFFSETOF(CLightMotionData, m_SubMotions, 0x10);
    BB_ASSERT_SIZEOF(CLightMotionData, 0x20);
}
