#pragma once

#include <Hedgehog/Base/Thread/hhHolderBase.h>
#include <Hedgehog/Base/Thread/hhSynchronizedObject.h>

#include <Sonic/System/PadState.h>

namespace Sonic
{
    class CInputState : public Hedgehog::Base::CSynchronizedObject
    {
    public:
        static constexpr Hedgehog::Base::TSynchronizedPtr<CInputState>* ms_pInstance = (Hedgehog::Base::TSynchronizedPtr<CInputState>*)0x1E79048;

        static Hedgehog::Base::TSynchronizedPtr<CInputState> GetInstance()
        {
            return *ms_pInstance;
        }

        SPadState m_PadStates[40];
        BB_INSERT_PADDING(0x50);
        uint32_t m_CurrentPadStateIndex;
        BB_INSERT_PADDING(0x4);

        const SPadState& GetPadState() const
        {
            return m_PadStates[m_CurrentPadStateIndex];
        }
    };

    BB_ASSERT_OFFSETOF(CInputState, m_PadStates, 0x4);
    BB_ASSERT_OFFSETOF(CInputState, m_CurrentPadStateIndex, 0xD74);
    BB_ASSERT_SIZEOF(CInputState, 0xD7C);
}