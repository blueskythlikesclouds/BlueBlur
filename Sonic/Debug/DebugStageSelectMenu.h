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

        CDebugStageSelectMenuXml();

        BB_OVERRIDE_FUNCTION_PTR(void, CGameObject, AddCallback, 0x10D8670, (const Hedgehog::Base::THolder<CWorld>&, in_rWorldHolder),
            (Sonic::CGameDocument*, in_pGameDocument), (const boost::shared_ptr<Hedgehog::Database::CDatabase>&, in_spDatabase))
    };

    BB_ASSERT_OFFSETOF(CDebugStageSelectMenuXml, m_Name, 0xA8);
    BB_ASSERT_OFFSETOF(CDebugStageSelectMenuXml, m_StateMachine, 0xCC);
    BB_ASSERT_SIZEOF(CDebugStageSelectMenuXml, 0x130);
}

#include <Sonic/Debug/DebugStageSelectMenu.inl>