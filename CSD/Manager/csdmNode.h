#pragma once

#include <CSD/Manager/csdmBase.h>
#include <CSD/Manager/csdmResourceBase.h>
#include <CSD/Manager/csdmNodeObserver.h>
#include <CSD/Manager/csdmSubjectBase.h>
#include <CSD/Manager/csdmMotionPattern.h>

namespace Chao::CSD
{
    class CFontList;
    class CMotionPattern;
    class CScene;
    struct Node;

    enum ESyncedProperty : uint32_t
    {
        eSyncedProperty_HideFlag = 0,
        eSyncedProperty_PositionX = 1,
        eSyncedProperty_PositionY = 2,
        eSyncedProperty_Rotation = 3,
        eSyncedProperty_ScaleX = 4,
        eSyncedProperty_ScaleY = 5,
        eSyncedProperty_Pattern = 6,
        eSyncedProperty_Color = 7,
        eSyncedProperty_ColorTopLeft = 8,
        eSyncedProperty_ColorBottomLeft = 9,
        eSyncedProperty_ColorTopRight = 10,
        eSyncedProperty_ColorBottomRight = 11,
        eSyncedProperty_UserData1 = 12,
        eSyncedProperty_UserData2 = 13,
        eSyncedProperty_UserData3 = 14
    };

    class CNode : public CResourceBase<Node>, SubjectBase<CNodeObserver, CNode>, CBase
    {
    public:
        void* m_Field20;
        hh::map<int, Chao::CSD::RCPtr<char>> m_Field24; //?
        int m_Field30;
        CMotionPattern* m_pMotionPattern;
        CFontList* m_pFontList;
        RCPtr<CScene> m_ParentScene;
        RCPtr<char> m_rcChar;
        RCPtr<char> m_rcText;
        RCPtr<wchar_t> m_rcTextWide;
        hh::map<ESyncedProperty, Chao::CSD::RCPtr<CNode>> m_SyncedProperties;
        CMotionPattern* m_pMotionPattern2; //?

        ~CNode() override = default;

        Hedgehog::Math::CVector2 GetPosition() const;
        Hedgehog::Math::CVector2 GetCornerPosition(int in_Index) const;
        size_t GetHideFlag() const;
        float GetRotation() const;
        Hedgehog::Math::CVector2 GetScale() const;
        size_t GetPatternIndex() const;
        Color GetMainColor() const;
        Color GetCornerColor(int in_Index) const;
        int GetUserData(int in_Index) const;
        float GetMaxWidth() const;
        float GetMaxHeight() const;

        void SetText(const char* in_pText);
        void SetText(const wchar_t* in_pText);

        void SetHideFlag(size_t in_HideFlag);
        void SetPosition(float in_X, float in_Y);
        void SetPositionX(float in_X);
        void SetPositionY(float in_Y);
        void SetRotation(float in_Rotation);
        void SetScale(float in_X, float in_Y);
        void SetPatternIndex(size_t in_PatternIndex);
        void SetMainColor(const Color& in_Color);
        void SetCornerColor(int in_Index, const Color& in_Color);
        void SetUserData(int in_Index, uint32_t in_Data);
    };
    BB_ASSERT_OFFSETOF(CNode, m_Field20, 0x20);
    BB_ASSERT_OFFSETOF(CNode, m_Field24, 0x24);
    BB_ASSERT_OFFSETOF(CNode, m_Field30, 0x30);
    BB_ASSERT_OFFSETOF(CNode, m_pMotionPattern, 0x34);
    BB_ASSERT_OFFSETOF(CNode, m_pFontList, 0x38);
    BB_ASSERT_OFFSETOF(CNode, m_ParentScene, 0x3C);
    BB_ASSERT_OFFSETOF(CNode, m_rcChar, 0x44);
    BB_ASSERT_OFFSETOF(CNode, m_rcText, 0x4C);
    BB_ASSERT_OFFSETOF(CNode, m_rcTextWide, 0x54);
    BB_ASSERT_OFFSETOF(CNode, m_SyncedProperties, 0x5C);
    BB_ASSERT_OFFSETOF(CNode, m_pMotionPattern2, 0x68);
    BB_ASSERT_SIZEOF(CNode, 0x6C);
}

#include <CSD/Manager/csdmNode.inl>