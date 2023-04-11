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
        virtual Hedgehog::Math::CVector GetVelocityForAnimationSpeed() = 0;
        virtual Hedgehog::Math::CVector GetVelocityForAnimationChange() = 0;
    };
}