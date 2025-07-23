#pragma once

#include <CSD/Manager/csdmBase.h>
#include <CSD/Manager/csdmResourceBase.h>
#include <CSD/Manager/csdmNodeObserver.h>
#include <CSD/Manager/csdmSubjectBase.h>
#include <CSD/Manager/csdmMotionPattern.h>

namespace Chao::CSD
{
    struct Node;
    class CMotionPattern;
    struct CFontList;
    class CNode : public CResourceBase<Node>, SubjectBase<CNodeObserver, CNode>, CBase
    {
    public:
        BB_INSERT_PADDING(0x14);
        CMotionPattern* m_pMotionPattern;
        CFontList* m_pFontList;
        BB_INSERT_PADDING(0x30);

        ~CNode() override = default;

        void SetText(const char* in_pText);
        void SetText(const wchar_t* in_pText);

        Hedgehog::Math::CVector2 GetPosition() const;
        void SetPosition(float in_X, float in_Y);
        void SetHideFlag(size_t in_HideFlag);
        void SetRotation(float in_Rotation);
        void SetScale(float in_X, float in_Y);
        void SetPatternIndex(size_t in_PatternIndex);
        void SetColor(const Color& in_HexColorABGR);
    };
    BB_ASSERT_OFFSETOF(CNode, m_pMotionPattern, 0x34);
    BB_ASSERT_OFFSETOF(CNode, m_pFontList, 0x38);
    BB_ASSERT_SIZEOF(CNode, 0x6C);
}

#include <CSD/Manager/csdmNode.inl>