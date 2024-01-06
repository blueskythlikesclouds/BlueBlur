namespace Chao::CSD
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCSceneGetNode, 0x67AFE0, const CScene* This, RCPtr<CNode>& out_rcNode, const char* in_pName);

    inline RCPtr<CNode> CScene::GetNode(const char* in_pName) const
    {
        RCPtr<CNode> rcNode;
        fpCSceneGetNode(this, rcNode, in_pName);
        return rcNode;
    }

    inline BB_FUNCTION_PTR(bool, __thiscall, fpCSceneSetMotion, 0x679710, CScene* This, const char* in_pName);

    inline bool CScene::SetMotion(const char* in_pName)
    {
        return fpCSceneSetMotion(this, in_pName);
    }

    inline void CScene::SetMotionFrame(float in_MotionFrame)
    {
        m_PrevMotionFrame = in_MotionFrame;
        m_MotionFrame = in_MotionFrame;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCSceneSetPosition, 0x679B50, CScene* This, float in_X, float in_Y);

    inline void CScene::SetPosition(float in_X, float in_Y)
    {
        fpCSceneSetPosition(this, in_X, in_Y);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCSceneSetHideFlag, 0x679B20, CScene* This, size_t in_Hidden);

    inline void CScene::SetHideFlag(size_t in_HideFlag)
    {
        fpCSceneSetHideFlag(this, in_HideFlag);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCSceneSetRotation, 0x679D50, CScene* This, float in_Rotation);

    inline void CScene::SetRotation(float in_Angle)
    {
        fpCSceneSetRotation(this, in_Angle);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCSceneSetScale, 0x679DD0, CScene* This, float in_X, float in_Y);

    inline void CScene::SetScale(float in_X, float in_Y)
    {
        fpCSceneSetScale(this, in_X, in_Y);
    }
}