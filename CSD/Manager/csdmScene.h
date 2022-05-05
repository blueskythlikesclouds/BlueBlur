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

    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCSceneSetMotionContext, 0x679710,
        CScene* This, const char* in_pName);

    enum EMotionPlaybackType : size_t
    {
        eMotionPlaybackType_PlayOnce = 0,
        eMotionPlaybackType_Loop = 1,
        eMotionPlaybackType_PingPong = 2,
        eMotionPlaybackType_PlayThenHide = 3
    };

    class CScene : public CResourceBase<Scene>, SubjectBase<CSceneObserver, CScene>, CBase
    {
    public:
        BB_INSERT_PADDING(0x5C);
        float m_PrevMotionTime;
        float m_MotionTime;
        float m_MotionSpeed;
        float m_MotionBeginTime;
        float m_MotionEndTime;
        BB_INSERT_PADDING(0xC);
        size_t m_MotionDisabled;
        BB_INSERT_PADDING(0x10);
        EMotionPlaybackType m_MotionPlaybackType;
        BB_INSERT_PADDING(0x2C);

        ~CScene() override = default;

        // Update should be called with a delta time of zero
        // after making changes to a motion context.
        // All motions execute at the same time.

        // Example:
        // SetMotionContext("Intro_Anim");
        // SetMotionTime(0.0);
        // m_MotionSpeed = 2.0f;
        // Update(0.0f);

        // Changes are not going to be recognized if
        // update is not called.

        virtual void Update(float in_DeltaTime);
        virtual void Draw(void*);

        RCPtr<CNode> GetNode(const char* in_pName) const
        {
            RCPtr<CNode> rcNode;
            fpCSceneGetNode(this, rcNode, in_pName);
            return rcNode;
        }

        bool SetMotionContext(const char* in_pName)
        {
            return fpCSceneSetMotionContext(this, in_pName);
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
    BB_ASSERT_OFFSETOF(CScene, m_MotionBeginTime, 0x88);
    BB_ASSERT_OFFSETOF(CScene, m_MotionEndTime, 0x8C);
    BB_ASSERT_OFFSETOF(CScene, m_MotionDisabled, 0x9C);
    BB_ASSERT_OFFSETOF(CScene, m_MotionPlaybackType, 0xB0);
    BB_ASSERT_SIZEOF(CScene, 0xE0);
}