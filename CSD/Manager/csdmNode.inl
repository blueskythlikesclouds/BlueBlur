namespace Chao::CSD
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetText0, 0x67E290, CNode* This, const char* in_pText);

    inline void CNode::SetText(const char* in_pText)
    {
        fpCNodeSetText0(this, in_pText);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetText1, 0x67E290, CNode* This, const wchar_t* in_pText);

    inline void CNode::SetText(const wchar_t* in_pText)
    {
        fpCNodeSetText1(this, in_pText);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeGetPosition, 0x67CC80, const CNode* This, Hedgehog::Math::CVector2& out_Position);

    inline Hedgehog::Math::CVector2 CNode::GetPosition() const
    {
        Hedgehog::Math::CVector2 position;
        fpCNodeGetPosition(this, position);
        return position;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetPosition, 0x67D550, CNode* This, float in_X, float in_Y);

    inline void CNode::SetPosition(float in_X, float in_Y)
    {
        fpCNodeSetPosition(this, in_X, in_Y);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetHideFlag, 0x67D690, CNode* This, size_t in_HideFlag);

    inline void CNode::SetHideFlag(size_t in_HideFlag)
    {
        fpCNodeSetHideFlag(this, in_HideFlag);
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
    inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetColor, 0x679E20, CNode* This, const Color& in_Color);

    inline void CNode::SetColor(const Color& in_HexColorABGR)
    {
        m_pMotionPattern->m_pResource->Color = in_HexColorABGR;
        m_pMotionPattern->m_pResource->m_RenderFlags &= ~0x80u;
        auto result = m_pMotionPattern->m_pResource;
        result->m_RenderFlags &= ~0x80000u;
    }
}