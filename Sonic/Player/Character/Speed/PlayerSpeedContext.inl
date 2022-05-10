#pragma once

#include <Sonic/Player/Character/Speed/PlayerSpeedContext.h>
#include <Sonic/Player/Character/Speed/StateFlag.h>

inline float Sonic::Player::CPlayerSpeedContext::GetMaxChaosEnergy() const
{
    if (StateFlag(eStateFlag_EnableChaosEnergySetting))
        return m_ChaosEnergySetting;

    if (m_ChaosEnergyGaugeSize != 1 && m_ChaosEnergyGaugeSize == 2)
        return 200.0f;

    return 100.0f;
}