#pragma once

namespace Hedgehog::Animation
{
    class CAnimationPose;
}

namespace Sonic
{
    class IAnimationContext
    {
    public:
        virtual Hedgehog::Animation::CAnimationPose* GetAnimationPose() = 0;
        virtual const Hedgehog::Math::CVector& GetPlaybackVectorA(const Hedgehog::Math::CVector& in_velocity) = 0;
        virtual const Hedgehog::Math::CVector& GetPlaybackVectorB(const Hedgehog::Math::CVector& in_velocity) = 0;
    };
}