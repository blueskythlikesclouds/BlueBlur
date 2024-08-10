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

    enum EMotionRepeatType : size_t
    {
        eMotionRepeatType_PlayOnce = 0,
        eMotionRepeatType_Loop = 1,
        eMotionRepeatType_PingPong = 2,
        eMotionRepeatType_PlayThenDestroy = 3
    };

    class CScene : public CResourceBase<Scene>, SubjectBase<CSceneObserver, CScene>, CBase
    {
    public:
        BB_INSERT_PADDING(0x5C);
        float m_PrevMotionFrame;
        float m_MotionFrame;
        float m_MotionSpeed;
        float m_MotionStartFrame;
        float m_MotionEndFrame;
        BB_INSERT_PADDING(0xC);
        size_t m_MotionDisableFlag;
        BB_INSERT_PADDING(0x10);
        EMotionRepeatType m_MotionRepeatType;
        BB_INSERT_PADDING(0x2C);

        ~CScene() override = default;

        // Update should be called with a delta time of zero
        // after making changes to a motion.

        // Example:
        // SetMotion("Intro_Anim");
        // SetMotionFrame(0.0);
        // m_MotionSpeed = 2.0f;
        // Update(0.0f);

        // Changes are not going to be recognized if
        // update is not called.

        virtual void Update(float in_DeltaTime = 0.0f);
        virtual void Render(void*);

        RCPtr<CNode> GetNode(const char* in_pName) const;

        bool SetMotion(const char* in_pName);
        void SetMotionFrame(float in_MotionFrame);
        void SetPosition(float in_X, float in_Y);
        void SetHideFlag(size_t in_HideFlag);
        void SetRotation(float in_Angle);
        void SetScale(float in_X, float in_Y);
    };

    BB_ASSERT_OFFSETOF(CScene, m_PrevMotionFrame, 0x7C);
    BB_ASSERT_OFFSETOF(CScene, m_MotionFrame, 0x80);
    BB_ASSERT_OFFSETOF(CScene, m_MotionSpeed, 0x84);
    BB_ASSERT_OFFSETOF(CScene, m_MotionStartFrame, 0x88);
    BB_ASSERT_OFFSETOF(CScene, m_MotionEndFrame, 0x8C);
    BB_ASSERT_OFFSETOF(CScene, m_MotionDisableFlag, 0x9C);
    BB_ASSERT_OFFSETOF(CScene, m_MotionRepeatType, 0xB0);
    BB_ASSERT_SIZEOF(CScene, 0xE0);
}

#include <CSD/Manager/csdmScene.inl>