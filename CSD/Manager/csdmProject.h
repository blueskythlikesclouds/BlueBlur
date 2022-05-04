#pragma once

#include <CSD/Manager/csdmBase.h>
#include <CSD/Manager/csdmResourceBase.h>

namespace Chao::CSD
{
    struct Project;
    class CProject;
    class CScene;
    
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCProjectGetScene, 0x677220,
        const CProject* This, RCPtr<CScene>& out_rcScene, const char* in_pName, size_t in_Group);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCProjectKillScene, 0x678BA0,
        CProject* This, CScene* in_pScene);

    class CProject : public CResourceBase<Project>, CBase
    {
    public:
        BB_INSERT_PADDING(0x40);

        RCPtr<CScene> GetScene(const char* in_pName, size_t in_Group) const
        {
            RCPtr<CScene> rcScene;
            fpCProjectGetScene(this, rcScene, in_pName, in_Group);
            return rcScene;
        }

        void KillScene(CScene* in_pScene)
        {
            fpCProjectKillScene(this, in_pScene);
        }

        void KillScene(RCPtr<CScene>& inout_rcScene)
        {
            if (!inout_rcScene)
                return;

            KillScene(inout_rcScene.Get());
            inout_rcScene = nullptr;
        }
    };

    BB_ASSERT_SIZEOF(CProject, 0x50);
}
