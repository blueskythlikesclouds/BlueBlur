#pragma once

#include <CSD/Manager/csdmBase.h>
#include <CSD/Manager/csdmResourceBase.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Chao::CSD
{
    struct Project;
    class CProject;
    class CScene;
    class CTexList;

    class CProject : public CResourceBase<Project>, CBase
    {
    public:
        uint32_t m_Field10;
        hh::map<const char*, RCPtr<CScene>> m_SpawnedScenes;
        hh::map<float, RCPtr<CScene>> m_Field20;
        RCPtr<CTexList> m_rcTexList;
        CFontList* m_rcFontList;
        BB_INSERT_PADDING(0x18);

        RCPtr<CScene> CreateScene(const char* in_pName) const;
        RCPtr<CScene> CreateScene(const char* in_pName, const char* in_pMotionName) const;

        void DestroyScene(CScene* in_pScene);
        void DestroyScene(RCPtr<CScene>& inout_rcScene);

        static void DestroyScene(CProject* in_pProject, RCPtr<CScene>& inout_rcScene);
    };

    BB_ASSERT_OFFSETOF(CProject, m_Field10, 0x10);
    BB_ASSERT_OFFSETOF(CProject, m_SpawnedScenes, 0x14);
    BB_ASSERT_OFFSETOF(CProject, m_Field20, 0x20);
    BB_ASSERT_OFFSETOF(CProject, m_rcTexList, 0x2C);
    BB_ASSERT_OFFSETOF(CProject, m_rcFontList, 0x34);
    BB_ASSERT_SIZEOF(CProject, 0x50);
}


#include <CSD/Manager/csdmProject.inl>