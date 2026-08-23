namespace Chao::CSD
{    
    inline BB_FUNCTION_PTR(int, __thiscall, fpCMotionPatternGetHideFlag, 0x6854E0, const CMotionPattern* This);
    inline size_t CMotionPattern::GetHideFlag() const
    {
        return fpCMotionPatternGetHideFlag(this);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMotionPatternGetPositionNormalized, 0x6850B0, const CMotionPattern* This, const Hedgehog::Math::CVector2& out_Position);
    inline Hedgehog::Math::CVector2 CMotionPattern::GetPositionNormalized() const
    {
        Hedgehog::Math::CVector2 out_Result;
        fpCMotionPatternGetPositionNormalized(this, out_Result);
        return out_Result;
    }

    inline BB_FUNCTION_PTR(float, __thiscall, fpCMotionPatternGetRotation, 0x685520, const CMotionPattern* This);
    inline float CMotionPattern::GetRotation() const
    {
        return fpCMotionPatternGetRotation(this);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMotionPatternGetScale, 0x685600, const CMotionPattern* This, const Hedgehog::Math::CVector2& out_Position);
    inline Hedgehog::Math::CVector2 CMotionPattern::GetScale() const
    {
        Hedgehog::Math::CVector2 out_Result;
        fpCMotionPatternGetScale(this, out_Result);
        return out_Result;
    }

    inline BB_FUNCTION_PTR(float, __thiscall, fpCMotionPatternGetPatternIndex, 0x685850, const CMotionPattern* This);
    inline float CMotionPattern::GetPatternIndex() const
    {
        return fpCMotionPatternGetPatternIndex(this);
    }

    inline BB_FUNCTION_PTR(int, __thiscall, fpCMotionPatternGetMainColor, 0x685780, const CMotionPattern* This);
    inline Color CMotionPattern::GetMainColor() const
    {
        return (Color)fpCMotionPatternGetMainColor(this);
    }

    inline BB_FUNCTION_PTR(int, __thiscall, fpCMotionPatternGetCornerColor, 0x685960, const CMotionPattern* This, int in_CornerIndex);
    inline Color CMotionPattern::GetCornerColor(int in_Index) const
    {
        return (Color)fpCMotionPatternGetCornerColor(this, in_Index);
    }


    inline BB_FUNCTION_PTR(int, __thiscall, fpCMotionPatternGetUserdata, 0x685A80, const CMotionPattern* This, int in_Index);
    inline int CMotionPattern::GetUserData(int in_Index) const
    {
        return fpCMotionPatternGetUserdata(this, in_Index);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMotionPatternSetMainColor, 0x6857C0, const CMotionPattern* This, uint32_t in_Color);
    inline void CMotionPattern::SetMainColor(const Color& in_Color)
    {
        fpCMotionPatternSetMainColor(this, (uint32_t)in_Color.data());
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMotionPatternSetCornerColor, 0x6859B0, const CMotionPattern* This, int in_Index, uint32_t in_Color);
    inline void CMotionPattern::SetCornerColor(int in_Index, const Color& in_Color)
    {
        fpCMotionPatternSetCornerColor(this, in_Index, (uint32_t)in_Color.data());
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMotionPatternSetUserData, 0x685AD0, const CMotionPattern* This, int in_Index, uint32_t in_Data);
    inline void CMotionPattern::SetUserData(int in_Index, uint32_t in_Data)
    {
        fpCMotionPatternSetUserData(this, in_Index, in_Data);
    }

}