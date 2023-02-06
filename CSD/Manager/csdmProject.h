#pragma once

#include <CSD/Manager/csdmBase.h>
#include <CSD/Manager/csdmResourceBase.h>

namespace Chao::CSD
{
    struct Project;
    class CProject;
    class CScene;
    class CTexList;
    
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCProjectCreateScene0, 0x677220,
        const CProject* This, RCPtr<CScene>& out_rcScene, const char* in_pName, void* in_pFactory);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCProjectCreateScene1, 0x677160,
        const CProject* This, RCPtr<CScene>& out_rcScene, const char* in_pName, const char* in_pMotionName, void* in_pFactory);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCProjectDestroyScene, 0x678BA0,
        CProject* This, CScene* in_pScene);

    class CProject : public CResourceBase<Project>, CBase
    {
    public:
        BB_INSERT_PADDING(0x1C);
        RCPtr<CTexList> m_rcTexList;
        BB_INSERT_PADDING(0x1C);

        RCPtr<CScene> CreateScene(const char* in_pName) const
        {
            RCPtr<CScene> rcScene;
            fpCProjectCreateScene0(this, rcScene, in_pName, nullptr);
            return rcScene;
        }

        RCPtr<CScene> CreateScene(const char* in_pName, const char* in_pMotionName) const
        {
            RCPtr<CScene> rcScene;
            fpCProjectCreateScene1(this, rcScene, in_pName, in_pMotionName, nullptr);
            return rcScene;
        }

        void DestroyScene(CScene* in_pScene)
        {
            fpCProjectDestroyScene(this, in_pScene);
        }

        void DestroyScene(RCPtr<CScene>& inout_rcScene)
        {
            if (!inout_rcScene)
                return;

            DestroyScene(inout_rcScene.Get());
            inout_rcScene = nullptr;
        }

        static void DestroyScene(CProject* in_pProject, RCPtr<CScene>& inout_rcScene)
        {
            if (in_pProject)
                in_pProject->DestroyScene(inout_rcScene);
            else
                inout_rcScene = nullptr;
        }
    };

    BB_ASSERT_OFFSETOF(CProject, m_rcTexList, 0x2C);
    BB_ASSERT_SIZEOF(CProject, 0x50);
}
