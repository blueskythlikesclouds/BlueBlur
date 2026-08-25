namespace Chao::CSD
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeGetPosition, 0x67CC80, const CNode* This, Hedgehog::Math::CVector2& out_Position);
    inline Hedgehog::Math::CVector2 CNode::GetPosition() const
    {
        Hedgehog::Math::CVector2 position;
        fpCNodeGetPosition(this, position);
        return position;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeGetCornerPosition, 0x67D900, const CNode* This, Hedgehog::Math::CVector2& out_Position, int in_CornerIdx);
    inline Hedgehog::Math::CVector2 CNode::GetCornerPosition(int in_Index) const
    {
        Hedgehog::Math::CVector2 position;
        fpCNodeGetCornerPosition(this, position, in_Index);
        return position;
    }

    inline size_t CNode::GetHideFlag() const
    {
        return m_pMotionPattern->GetHideFlag();
    }

    inline float CNode::GetRotation() const
    {
        return m_pMotionPattern->GetRotation();
    }

    inline Hedgehog::Math::CVector2 CNode::GetScale() const
    {
        return m_pMotionPattern->GetScale();
    }

    inline size_t CNode::GetPatternIndex() const
    {
        //it seems like it returns a float to do some kind of
        //weird texture calc, but its passed around as size_t
        return (size_t)m_pMotionPattern->GetPatternIndex();
    }

    inline Color CNode::GetMainColor() const
    {
        return m_pMotionPattern->GetMainColor();
    }

    inline Color CNode::GetCornerColor(int in_Index) const
    {
        return m_pMotionPattern->GetCornerColor(in_Index);
    }

    inline int CNode::GetUserData(int in_Index) const
    {
        return m_pMotionPattern->GetUserData(in_Index);
    }


    inline BB_FUNCTION_PTR(float, __thiscall, fpCNodeGetMaxWidth, 0x67DCE0, const CNode* This);
    inline float CNode::GetMaxWidth() const
    {
        return fpCNodeGetMaxWidth(this);
    }

    inline BB_FUNCTION_PTR(float, __thiscall, fpCNodeGetMaxHeight, 0x67DD50, const CNode* This);
    inline float CNode::GetMaxHeight() const
    {
        return fpCNodeGetMaxHeight(this);
    }



    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetText0, 0x67E290, CNode* This, const char* in_pText);
    inline void CNode::SetText(const char* in_pText)
    {
        fpCNodeSetText0(this, in_pText);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetTextWide, 0x67E390, CNode* This, const wchar_t* in_pText);
    inline void CNode::SetText(const wchar_t* in_pText)
    {
        fpCNodeSetTextWide(this, in_pText);
    }



    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetHideFlag, 0x67D690, CNode* This, size_t in_HideFlag);
    inline void CNode::SetHideFlag(size_t in_HideFlag)
    {
        fpCNodeSetHideFlag(this, in_HideFlag);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetPosition, 0x67D550, CNode* This, float in_X, float in_Y);
    inline void CNode::SetPosition(float in_X, float in_Y)
    {
        fpCNodeSetPosition(this, in_X, in_Y);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetPositionX, 0x67DA50, CNode* This, float in_X);
    inline void CNode::SetPositionX(float in_X)
    {
        fpCNodeSetPositionX(this, in_X);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetPositionY, 0x67DA90, CNode* This, float in_Y);
    inline void CNode::SetPositionY(float in_Y)
    {
        fpCNodeSetPositionY(this, in_Y);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetRotation, 0x67D6D0, CNode* This, float in_Rotation);
    inline void CNode::SetRotation(float in_Rotation)
    {
        fpCNodeSetRotation(this, in_Rotation);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetScale, 0x67D710, CNode* This, float in_X, float in_Y);
    inline void CNode::SetScale(float in_X, float in_Y)
    {
        fpCNodeSetScale(this, in_X, in_Y);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetPatternIndex, 0x67D760, CNode* This, size_t in_PatternIndex);
    inline void CNode::SetPatternIndex(size_t in_PatternIndex)
    {
        fpCNodeSetPatternIndex(this, in_PatternIndex);
    }

    inline void CNode::SetMainColor(const Color& in_Color)
    {
        m_pMotionPattern->SetMainColor(in_Color);
    }

    inline void CNode::SetCornerColor(int in_Index, const Color& in_Color)
    {
        m_pMotionPattern->SetCornerColor(in_Index, in_Color);
    }

    inline void CNode::SetUserData(int in_Index, uint32_t in_Data)
    {
        m_pMotionPattern->SetUserData(in_Index, in_Data);
    }
}