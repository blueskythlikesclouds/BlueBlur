#pragma once

#include <CSD/Manager/csdmBase.h>
#include <CSD/Manager/csdmResourceBase.h>
#include <CSD/Manager/csdmSceneObserver.h>
#include <CSD/Manager/csdmSubjectBase.h>

namespace Chao::CSD
{
    struct Scene;
    class CScene;
    class CNode;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCSceneGetNode, 0x67AFE0,
        const CScene* This, RCPtr<CNode>& out_rcNode, const char* in_pName);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCSceneSetMotion, 0x679710,
        CScene* This, const char* in_pName);

    class CScene : public CResourceBase<Scene>, SubjectBase<CSceneObserver, CScene>, CBase
    {
    public:
        BB_INSERT_PADDING(0x5C);
        float m_PrevMotionTime;
        float m_MotionTime;
        float m_MotionSpeed;
        BB_INSERT_PADDING(0x58);

        ~CScene() override = default;

        virtual void Display(float);

        RCPtr<CNode> GetNode(const char* in_pName) const
        {
            RCPtr<CNode> rcNode;
            fpCSceneGetNode(this, rcNode, in_pName);
            return rcNode;
        }

        void SetMotion(const char* in_pName)
        {
            fpCSceneSetMotion(this, in_pName);
        }

        void SetMotionTime(float in_MotionTime)
        {
            m_PrevMotionTime = in_MotionTime;
            m_MotionTime = in_MotionTime;
        }
    };

    BB_ASSERT_OFFSETOF(CScene, m_PrevMotionTime, 0x7C);
    BB_ASSERT_OFFSETOF(CScene, m_MotionTime, 0x80);
    BB_ASSERT_OFFSETOF(CScene, m_MotionSpeed, 0x84);
    BB_ASSERT_SIZEOF(CScene, 0xE0);
}