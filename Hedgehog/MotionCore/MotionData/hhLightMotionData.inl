namespace Hedgehog::Motion
{
    inline BB_FUNCTION_PTR(void, __cdecl, fpCLightMotionDataStep, 0x758640,
        CLightMotionData* This, uint32_t in_Index, float in_Frame, CLightSubMotionValueData& in_rValueData, const Math::CMatrix& in_rMatrix);

    inline void CLightMotionData::Step(uint32_t in_Index, float in_Frame, CLightSubMotionValueData& in_rValueData,
        const Math::CMatrix& in_rMatrix)
    {
        fpCLightMotionDataStep(this, in_Index, in_Frame, in_rValueData, in_rMatrix);
    }
}