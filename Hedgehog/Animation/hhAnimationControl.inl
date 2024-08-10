namespace Hedgehog::Animation
{
    static BB_FUNCTION_PTR(void, __thiscall, fpCAnimationControlSetPlaybackSpeed, 0x6D21C0, CAnimationControl* This, float in_Speed);

    inline void CAnimationControl::SetPlaybackSpeed(float in_Speed)
    {
        fpCAnimationControlSetPlaybackSpeed(this, in_Speed);
    }
}