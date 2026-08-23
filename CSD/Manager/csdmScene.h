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
    class CMotion;
    class CMotionPalette;
    class CFontList;

    enum EMotionRepeatType : size_t
    {
        eMotionRepeatType_PlayOnce = 0,
        eMotionRepeatType_Loop = 1,
        eMotionRepeatType_PingPong = 2,
        eMotionRepeatType_PlayThenDestroy = 3
    };

    class CSceneMotionRepeat : public CSceneObserver
    {
    public:
        EMotionRepeatType m_MotionEndRepeatType;
        EMotionRepeatType m_MotionStartRepeatType;

        void OnMotionEnd(CScene* in_pScene) override;
        void OnMotionStart(CScene* in_pScene) override;
    };

    class CScene : public CResourceBase<Scene>, SubjectBase<CSceneObserver, CScene>, CBase
    {
    public:
        class CFunctorBase
        {
        public:
            virtual bool Execute(Chao::CSD::CScene* in_pTarget) = 0;             
            virtual ~CFunctorBase() = 0;
        };
        struct SNodeCastSearch
        {
            int GroupIndex;
            int CastIndex;
        };
        int m_Field20;
        hh::map<int, Chao::CSD::RCPtr<CFunctorBase>> m_Functors;
        hh::map<int, Chao::CSD::RCPtr<char>> m_Field30;
        hh::map<int, Chao::CSD::RCPtr<char>> m_Field3C;
        hh::map<int, Chao::CSD::RCPtr<char>> m_Field48;
        hh::map<int, Chao::CSD::RCPtr<char>> m_Field54;
        hh::map<int, Chao::CSD::RCPtr<char>> m_Field60;
        RCPtr<CMotion> m_rcMotion;
        CFontList* m_pFontList;
        CMotionPalette* m_pMotionPalette;
        float m_PrevMotionFrame;
        float m_MotionFrame;
        float m_MotionSpeed;
        float m_MotionStartFrame;
        float m_MotionEndFrame;
        Chao::CSD::RCPtr<Chao::CSD::CNode> m_rcNode;
        CMotionPattern* m_pMotionPattern;
        size_t m_MotionDisableFlag;
        //NOTE: m_MotionRepeatType is EndRepeatType here!
        CSceneMotionRepeat m_MotionObserver;
        int m_MotionIndex;
        float m_ZIndex;
        hh::map<SNodeCastSearch, RCPtr<CNode>> m_ActiveNodes;
        const char* m_Name;
        RCPtr<char> m_rcFieldD0;
        RCPtr<CProject> m_rcParentProject;

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

        void SetRepeatType(EMotionRepeatType in_Type);
        void SetStartRepeatType(EMotionRepeatType in_Type);
        void SetEndRepeatType(EMotionRepeatType in_Type);
    };

    BB_ASSERT_OFFSETOF(CSceneMotionRepeat, m_MotionEndRepeatType, 0x10);
    BB_ASSERT_OFFSETOF(CSceneMotionRepeat, m_MotionStartRepeatType, 0x14);
    BB_ASSERT_OFFSETOF(CScene, m_Field20, 0x20);
    BB_ASSERT_OFFSETOF(CScene, m_Functors, 0x24);
    BB_ASSERT_OFFSETOF(CScene, m_Field30, 0x30);
    BB_ASSERT_OFFSETOF(CScene, m_Field3C, 0x3C);
    BB_ASSERT_OFFSETOF(CScene, m_Field48, 0x48);
    BB_ASSERT_OFFSETOF(CScene, m_Field54, 0x54);
    BB_ASSERT_OFFSETOF(CScene, m_Field60, 0x60);
    BB_ASSERT_OFFSETOF(CScene, m_rcMotion, 0x6C);
    BB_ASSERT_OFFSETOF(CScene, m_pFontList, 0x74);
    BB_ASSERT_OFFSETOF(CScene, m_pMotionPalette, 0x78);
    BB_ASSERT_OFFSETOF(CScene, m_PrevMotionFrame, 0x7C);
    BB_ASSERT_OFFSETOF(CScene, m_MotionFrame, 0x80);
    BB_ASSERT_OFFSETOF(CScene, m_MotionSpeed, 0x84);
    BB_ASSERT_OFFSETOF(CScene, m_MotionStartFrame, 0x88);
    BB_ASSERT_OFFSETOF(CScene, m_MotionEndFrame, 0x8C);
    BB_ASSERT_OFFSETOF(CScene, m_MotionDisableFlag, 0x9C);
    BB_ASSERT_OFFSETOF(CScene, m_MotionObserver, 0xA0);
    BB_ASSERT_OFFSETOF(CScene, m_MotionIndex, 0xB8);
    BB_ASSERT_OFFSETOF(CScene, m_ZIndex, 0xBC);
    BB_ASSERT_OFFSETOF(CScene, m_ActiveNodes, 0xC0);
    BB_ASSERT_OFFSETOF(CScene, m_Name, 0xCC);
    BB_ASSERT_OFFSETOF(CScene, m_rcFieldD0, 0xD0);
    BB_ASSERT_OFFSETOF(CScene, m_rcParentProject, 0xD8);
    BB_ASSERT_SIZEOF(CScene, 0xE0);
}

#include <CSD/Manager/csdmScene.inl>