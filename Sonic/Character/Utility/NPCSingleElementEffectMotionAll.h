#pragma once

#include <Hedgehog/MotionCore/Motion/hhSingleElementEffectMotionAll.h>

namespace Hedgehog::Mirage
{
    class CPictureData;
}

namespace Sonic
{
    class CNPCSingleElementEffectMotionAll : public Hedgehog::Motion::CSingleElementEffectMotionAll
    {
    public:
        Hedgehog::Math::CVector4 m_ChrPlayableMenuParam;
        bool m_EnableChrPlayableMenuParam;
        BB_INSERT_PADDING(0xF);
        boost::shared_ptr<Hedgehog::Mirage::CPictureData> m_spNpcEyePicture;
    };

    BB_ASSERT_OFFSETOF(CNPCSingleElementEffectMotionAll, m_ChrPlayableMenuParam, 0xA0);
    BB_ASSERT_OFFSETOF(CNPCSingleElementEffectMotionAll, m_EnableChrPlayableMenuParam, 0xB0);
    BB_ASSERT_OFFSETOF(CNPCSingleElementEffectMotionAll, m_spNpcEyePicture, 0xC0);
    BB_ASSERT_SIZEOF(CNPCSingleElementEffectMotionAll, 0xD0);
}