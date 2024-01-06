namespace Chao::CSD
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCProjectCreateScene0, 0x677220,
        const CProject* This, RCPtr<CScene>& out_rcScene, const char* in_pName, void* in_pFactory);

    inline RCPtr<CScene> CProject::CreateScene(const char* in_pName) const
    {
        RCPtr<CScene> rcScene;
        fpCProjectCreateScene0(this, rcScene, in_pName, nullptr);
        return rcScene;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCProjectCreateScene1, 0x677160,
        const CProject* This, RCPtr<CScene>& out_rcScene, const char* in_pName, const char* in_pMotionName, void* in_pFactory);

    inline RCPtr<CScene> CProject::CreateScene(const char* in_pName, const char* in_pMotionName) const
    {
        RCPtr<CScene> rcScene;
        fpCProjectCreateScene1(this, rcScene, in_pName, in_pMotionName, nullptr);
        return rcScene;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCProjectDestroyScene, 0x678BA0,
        CProject* This, CScene* in_pScene);

    inline void CProject::DestroyScene(CScene* in_pScene)
    {
        fpCProjectDestroyScene(this, in_pScene);
    }

    inline void CProject::DestroyScene(RCPtr<CScene>& inout_rcScene)
    {
        if (!inout_rcScene)
            return;

        DestroyScene(inout_rcScene.Get());
        inout_rcScene = nullptr;
    }

    inline void CProject::DestroyScene(CProject* in_pProject, RCPtr<CScene>& inout_rcScene)
    {
        if (in_pProject)
            in_pProject->DestroyScene(inout_rcScene);
        else
            inout_rcScene = nullptr;
    }
}