#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Animation
{
    class CAnimationControl;

    static BB_FUNCTION_PTR(void, __thiscall, fpCAnimationControlSetPlaybackSpeed, 0x6D21C0, CAnimationControl* This, float in_Speed);

    class CAnimationControl : public Base::CObject
    {
    public:
        uint32_t m_Field4;
        void* m_hkaDefaultAnimationControl;
        uint32_t m_FieldC;
        uint32_t m_PlaybackType;
        float m_Field14;
        float m_PlaybackSpeed;
        BB_INSERT_PADDING(0x18);
        bool m_Field34;
        BB_INSERT_PADDING(0x37); // 3 extra bytes of padding due to the bool above here
        bool m_Field6C;
        BB_INSERT_PADDING(0x78);

        virtual ~CAnimationControl() = default;

        void SetPlaybackSpeed(float in_Speed)
        {
            fpCAnimationControlSetPlaybackSpeed(this, in_Speed);
        }
    };

    BB_ASSERT_OFFSETOF(CAnimationControl, m_PlaybackSpeed, 0x18);
    BB_ASSERT_OFFSETOF(CAnimationControl, m_Field34, 0x34);
    BB_ASSERT_OFFSETOF(CAnimationControl, m_Field6C, 0x6C);
    BB_ASSERT_SIZEOF(CAnimationControl, 0xE8);
}
