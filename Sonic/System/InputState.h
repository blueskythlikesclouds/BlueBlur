#pragma once

#include <BlueBlur.inl>

#include <Hedgehog/Base/Thread/hhHolderBase.h>
#include <Hedgehog/Base/Thread/hhSynchronizedObject.h>

#include <Sonic/System/PadState.h>

namespace Sonic
{
    class CInputState : public Hedgehog::Base::CSynchronizedObject
    {
    public:
        static constexpr CInputState* ms_pInstance = (CInputState*)0x1E76160;

        SPadState m_PadStates[40];
        BB_INSERT_PADDING(0x50);
        uint32_t m_CurrentPadStateIndex;
        BB_INSERT_PADDING(0x4);

        static SPadState* GetPadState()
        {
            const Hedgehog::Base::CHolderBase holder(ms_pInstance, true);
            return &ms_pInstance->m_PadStates[ms_pInstance->m_CurrentPadStateIndex];
        }
    };

    BB_ASSERT_OFFSETOF(CInputState, m_PadStates, 0x4);
    BB_ASSERT_OFFSETOF(CInputState, m_CurrentPadStateIndex, 0xD74);
    BB_ASSERT_SIZEOF(CInputState, 0xD7C);
}