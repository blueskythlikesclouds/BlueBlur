#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Animation
{
    class CAnimationControl : public Base::CObject
    {
    public:
        uint32_t m_Field4;
        hk2010_2_0::hkaDefaultAnimationControl* m_hkaDefaultAnimationControl;
        uint32_t m_FieldC;
        uint32_t m_PlaybackType;
        float m_Field14;
        float m_PlaybackSpeed;
        BB_INSERT_PADDING(0x18);
        bool m_Field34;
        BB_INSERT_PADDING(0x37);
        bool m_Field6C;
        BB_INSERT_PADDING(0x78);

        virtual ~CAnimationControl() = default;
        virtual float CAnimationControl04();
        virtual float GetAnimationDuration();
        virtual bool  HasDefaultAnimationControl();
        virtual bool  CAnimationControl10(float a2, void* a3);
        virtual void  CAnimationControl14();
        virtual int   CAnimationControl18(void* a2);
        virtual int   CAnimationControl1C(int a2);
        virtual bool  CAnimationControl20(float a2);
        virtual bool  CAnimationControl24(int a2);
        virtual bool  CAnimationControl28(float a2);
        virtual void  CAnimationControl2C(float a2, float a3);
        virtual int   CAnimationControl30(int a2);
        virtual void  CAnimationControl34();
        virtual int   CAnimationControl38(int a2, float a3);
        virtual int   CAnimationControl3C();
        virtual int   CAnimationControl40();
        virtual void  CAnimationControl44();
        virtual void  CAnimationControl48();

        void SetPlaybackSpeed(float in_Speed);
    };

    BB_ASSERT_OFFSETOF(CAnimationControl, m_PlaybackSpeed, 0x18);
    BB_ASSERT_OFFSETOF(CAnimationControl, m_Field34, 0x34);
    BB_ASSERT_OFFSETOF(CAnimationControl, m_Field6C, 0x6C);
    BB_ASSERT_SIZEOF(CAnimationControl, 0xE8);
}


#include <Hedgehog/Animation/hhAnimationControl.inl>