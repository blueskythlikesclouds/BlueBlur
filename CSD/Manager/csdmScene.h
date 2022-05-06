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

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCSceneGetNode, 0x67AFE0, const CScene* This, RCPtr<CNode>& out_rcNode, const char* in_pName);
    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCSceneSetMotion, 0x679710, CScene* This, const char* in_pName);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCSceneSetPosition, 0x679B50, CScene* This, float in_X, float in_Y);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCSceneSetHideFlag, 0x679B20, CScene* This, bool in_Hidden);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCSceneSetRotation, 0x679D50, CScene* This, float in_Rotation);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCSceneSetScale, 0x679DD0, CScene* This, float in_X, float in_Y);

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
        float m_PrevMotionTime;
        float m_MotionTime;
        float m_MotionSpeed;
        float m_MotionBeginTime;
        float m_MotionEndTime;
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
        // SetMotionTime(0.0);
        // m_MotionSpeed = 2.0f;
        // Update(0.0f);

        // Changes are not going to be recognized if
        // update is not called.

        virtual void Update(float in_DeltaTime = 0.0f);
        virtual void Render(void*);

        RCPtr<CNode> GetNode(const char* in_pName) const
        {
            RCPtr<CNode> rcNode;
            fpCSceneGetNode(this, rcNode, in_pName);
            return rcNode;
        }

        bool SetMotion(const char* in_pName)
        {
            return fpCSceneSetMotion(this, in_pName);
        }

        void SetMotionTime(float in_MotionTime)
        {
            m_PrevMotionTime = in_MotionTime;
            m_MotionTime = in_MotionTime;
        }

        void SetPosition(float in_X, float in_Y)
        {
            fpCSceneSetPosition(this, in_X, in_Y);
        }

        void SetHideFlag(bool in_HideFlag)
        {
            fpCSceneSetHideFlag(this, in_HideFlag);
        }

        void SetRotation(float in_Angle)
        {
            fpCSceneSetRotation(this, in_Angle);
        }

        void SetScale(float in_X, float in_Y)
        {
            fpCSceneSetScale(this, in_X, in_Y);
        }
    };

    BB_ASSERT_OFFSETOF(CScene, m_PrevMotionTime, 0x7C);
    BB_ASSERT_OFFSETOF(CScene, m_MotionTime, 0x80);
    BB_ASSERT_OFFSETOF(CScene, m_MotionSpeed, 0x84);
    BB_ASSERT_OFFSETOF(CScene, m_MotionBeginTime, 0x88);
    BB_ASSERT_OFFSETOF(CScene, m_MotionEndTime, 0x8C);
    BB_ASSERT_OFFSETOF(CScene, m_MotionDisableFlag, 0x9C);
    BB_ASSERT_OFFSETOF(CScene, m_MotionRepeatType, 0xB0);
    BB_ASSERT_SIZEOF(CScene, 0xE0);
}