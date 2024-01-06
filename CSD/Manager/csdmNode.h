#pragma once

#include <CSD/Manager/csdmBase.h>
#include <CSD/Manager/csdmResourceBase.h>
#include <CSD/Manager/csdmNodeObserver.h>
#include <CSD/Manager/csdmSubjectBase.h>

namespace Chao::CSD
{
    struct Node;

    class CNode : public CResourceBase<Node>, SubjectBase<CNodeObserver, CNode>, CBase
    {
    public:
        BB_INSERT_PADDING(0x4C);

        ~CNode() override = default;

        void SetText(const char* in_pText);
        void SetText(const wchar_t* in_pText);

        Hedgehog::Math::CVector2 GetPosition() const;
        void SetPosition(float in_X, float in_Y);
        void SetHideFlag(size_t in_HideFlag);
        void SetRotation(float in_Rotation);
        void SetScale(float in_X, float in_Y);
        void SetPatternIndex(size_t in_PatternIndex);
    };

    BB_ASSERT_SIZEOF(CNode, 0x6C);
}

#include <CSD/Manager/csdmNode.inl>