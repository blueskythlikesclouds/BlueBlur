#pragma once

#include <CSD/Manager/csdmBase.h>
#include <CSD/Manager/csdmResourceBase.h>
#include <CSD/Manager/csdmNodeObserver.h>
#include <CSD/Manager/csdmSubjectBase.h>

namespace Chao::CSD
{
    struct Node;
    class CNode;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCNodeSetText, 0x67E290, CNode* This, const char* in_pText);

    class CNode : public CResourceBase<Node>, SubjectBase<CNodeObserver, CNode>, CBase
    {
    public:
        BB_INSERT_PADDING(0x4C);

        ~CNode() override = default;

        void SetText(const char* in_pText)
        {
            fpCNodeSetText(this, in_pText);
        }
    };

    BB_ASSERT_SIZEOF(CNode, 0x6C);
}