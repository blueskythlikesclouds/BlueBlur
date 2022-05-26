#pragma once

#include <CSD/Manager/csdmBase.h>
#include <CSD/Manager/csdmResourceBase.h>
#include <CSD/Manager/csdmNodeObserver.h>
#include <CSD/Manager/csdmSubjectBase.h>

namespace Chao::CSD
{
    struct Node;
    class CNode;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetText0, 0x67E290, CNode* This, const char* in_pText);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetText1, 0x67E290, CNode* This, const wchar_t* in_pText);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeGetPosition, 0x67CC80, const CNode* This, Hedgehog::Math::CVector2& out_Position);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetPosition, 0x67D550, CNode* This, float in_X, float in_Y);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetHideFlag, 0x67D690, CNode* This, size_t in_HideFlag);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetRotation, 0x67D6D0, CNode* This, float in_Rotation);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetScale, 0x67D710, CNode* This, float in_X, float in_Y);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetPatternIndex, 0x67D760, CNode* This, size_t in_PatternIndex);

    class CNode : public CResourceBase<Node>, SubjectBase<CNodeObserver, CNode>, CBase
    {
    public:
        BB_INSERT_PADDING(0x4C);

        ~CNode() override = default;

        void SetText(const char* in_pText)
        {
            fpCNodeSetText0(this, in_pText);
        }

        void SetText(const wchar_t* in_pText)
        {
            fpCNodeSetText1(this, in_pText);
        }

        Hedgehog::Math::CVector2 GetPosition() const
        {
            Hedgehog::Math::CVector2 position;
            fpCNodeGetPosition(this, position);
            return position;
        }

        void SetPosition(float in_X, float in_Y)
        {
            fpCNodeSetPosition(this, in_X, in_Y);
        }

        void SetHideFlag(size_t in_HideFlag)
        {
            fpCNodeSetHideFlag(this, in_HideFlag);
        }

        void SetRotation(float in_Rotation)
        {
            fpCNodeSetRotation(this, in_Rotation);
        }

        void SetScale(float in_X, float in_Y)
        {
            fpCNodeSetScale(this, in_X, in_Y);
        }

        void SetPatternIndex(size_t in_PatternIndex)
        {
            fpCNodeSetPatternIndex(this, in_PatternIndex);
        }
    };

    BB_ASSERT_SIZEOF(CNode, 0x6C);
}