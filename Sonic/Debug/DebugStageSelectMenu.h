#pragma once

#include <Hedgehog/Universe/Engine/hhStateMachine.h>
#include <Sonic/System/GameObject.h>

namespace Sonic::StageSelectMenu
{
    class CDebugStageSelectMenuXml : public CGameObject
    {
    public:
        Hedgehog::Base::CSharedString m_Name;
        BB_INSERT_PADDING(0x20) {};
        Hedgehog::Universe::TStateMachine<CDebugStageSelectMenuXml> m_StateMachine;
        BB_INSERT_PADDING(0x4) {};

        CDebugStageSelectMenuXml() : m_Name("Select")
        {
            *reinterpret_cast<size_t*>(this) = 0x16A081C;
            *reinterpret_cast<size_t*>(static_cast<CMessageActor*>(this)) = 0x16A085C;

            m_StateMachine.SetContext(this);
        }

        BB_OVERRIDE_FUNCTION_PTR(void, CGameObject, AddCallback, 0x10D8670, (const Hedgehog::Base::THolder<CWorld>&, in_rWorldHolder),
            (Sonic::CGameDocument*, in_pGameDocument), (const boost::shared_ptr<Hedgehog::Database::CDatabase>&, in_spDatabase))
    };

    BB_ASSERT_OFFSETOF(CDebugStageSelectMenuXml, m_Name, 0xA8);
    BB_ASSERT_OFFSETOF(CDebugStageSelectMenuXml, m_StateMachine, 0xCC);
    BB_ASSERT_SIZEOF(CDebugStageSelectMenuXml, 0x130);
}