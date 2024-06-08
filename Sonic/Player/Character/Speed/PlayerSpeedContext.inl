#include <Sonic/Player/Character/Speed/StateFlag.h>

namespace Sonic::Player
{
    inline CPlayerSpeedContext* CPlayerSpeedContext::GetInstance()
    {
        return *ms_pInstance;
    }

    inline uint8_t CPlayerSpeedContext::GetStateFlag(const CPlayerSpeedContext::EStateFlag in_StateFlag) const
    {
        return m_pStateFlag->m_Flags[(size_t)in_StateFlag];
    }

    inline void CPlayerSpeedContext::SetStateFlag(const CPlayerSpeedContext::EStateFlag in_StateFlag, const uint8_t in_Flag) const
    {
        m_pStateFlag->m_Flags[(size_t)in_StateFlag] = in_Flag;
    }

    inline uint32_t pCPlayerSpeedContextHandleVelocityChanged = 0xE4F100;

    inline void fpCPlayerSpeedContextHandleVelocityChanged(CPlayerSpeedContext* This)
    {
        __asm
        {
            mov esi, This
            call[pCPlayerSpeedContextHandleVelocityChanged]
        }
    }

    inline void CPlayerSpeedContext::HandleVelocityChanged()
    {
        fpCPlayerSpeedContextHandleVelocityChanged(this);
    }

    inline void CPlayerSpeedContext::HandleHorizontalOrVerticalVelocityChanged()
    {
        m_Velocity = m_HorizontalVelocity + m_VerticalVelocity;
        m_VelocityChanged = false;
        m_HorizontalOrVerticalVelocityChanged = false;
    }

    inline const Hedgehog::Math::CVector& CPlayerSpeedContext::GetVelocity()
    {
        if (m_HorizontalOrVerticalVelocityChanged)
            HandleHorizontalOrVerticalVelocityChanged();

        return m_Velocity;
    }

    inline void CPlayerSpeedContext::SetVelocity(const Hedgehog::Math::CVector& in_rVelocity)
    {
        m_Velocity = in_rVelocity;
        m_VelocityChanged = true;
        m_HorizontalOrVerticalVelocityChanged = false;
    }

    inline const Hedgehog::Math::CVector& CPlayerSpeedContext::GetHorizontalVelocity()
    {
        if (m_VelocityChanged)
            HandleVelocityChanged();
            
        return m_HorizontalVelocity;
    }

    inline void CPlayerSpeedContext::SetHorizontalVelocity(const Hedgehog::Math::CVector& in_rVelocity)
    {
        if (m_VelocityChanged)
            HandleVelocityChanged();
            
        m_HorizontalVelocity = in_rVelocity;
        m_VelocityChanged = false;
        m_HorizontalOrVerticalVelocityChanged = true;
    }

    inline void CPlayerSpeedContext::SetHorizontalVelocityClearChanged(const Hedgehog::Math::CVector& in_rVelocity)
    {
        m_HorizontalVelocity = in_rVelocity;
        HandleHorizontalOrVerticalVelocityChanged();
    }

    inline const Hedgehog::Math::CVector& CPlayerSpeedContext::GetVerticalVelocity()
    {
        if (m_VelocityChanged)
            HandleVelocityChanged();

        return m_VerticalVelocity;
    }

    inline void CPlayerSpeedContext::SetVerticalVelocity(const Hedgehog::Math::CVector& in_rVelocity)
    {
        if (m_VelocityChanged)
            HandleVelocityChanged();

        m_VerticalVelocity = in_rVelocity;
        m_VelocityChanged = false;
        m_HorizontalOrVerticalVelocityChanged = true;
    }

    inline void CPlayerSpeedContext::AddVelocity(const Hedgehog::Math::CVector& in_rImpulse)
    {
        if (m_HorizontalOrVerticalVelocityChanged)
        {
            HandleHorizontalOrVerticalVelocityChanged();
        }
        m_Velocity += in_rImpulse;
        m_VelocityChanged = true;
        m_HorizontalOrVerticalVelocityChanged = false;
    }

    inline Hedgehog::Math::CVector CPlayerSpeedContext::GetHorizontalVelocityDirection()
    {
        const Hedgehog::Math::CVector horizontalVelocity = GetHorizontalVelocity();
        if (horizontalVelocity.squaredNorm() < FLT_EPSILON)
            return Hedgehog::Math::CVector::Zero();

        return horizontalVelocity.normalized();
    }

    inline Hedgehog::Math::CVector CPlayerSpeedContext::GetHorizontalMovementDirection()
    {
        const Hedgehog::Math::CVector horizontalVelocity = GetHorizontalVelocity();
        if (horizontalVelocity.squaredNorm() < FLT_EPSILON)
            return GetFrontDirection();

        return horizontalVelocity.normalized();
    }

    inline uint32_t pCPlayerSpeedContextGetUpDirection = 0xE71FB0;
    inline void fCPlayerSpeedContextGetUpDirection(const CPlayerSpeedContext* This, Hedgehog::Math::CVector* in_pVector)
    {
        __asm
        {
            mov eax, This
            mov esi, in_pVector
            call[pCPlayerSpeedContextGetUpDirection]
            mov in_pVector, eax
        }
    }

    inline Hedgehog::Math::CVector CPlayerSpeedContext::GetUpDirection()
    {
        Hedgehog::Math::CVector result = Hedgehog::Math::CVector::Zero();
        fCPlayerSpeedContextGetUpDirection(this, &result);
        return result;
    }

    inline uint32_t pCPlayerSpeedContextGetRightDirection = 0xE72070;
    inline void fCPlayerSpeedContextGetRightDirection(const CPlayerSpeedContext* This, Hedgehog::Math::CVector* in_pVector)
    {
        __asm
        {
            mov eax, This
            mov esi, in_pVector
            call[pCPlayerSpeedContextGetRightDirection]
            mov in_pVector, eax
        }
    }

    inline Hedgehog::Math::CVector CPlayerSpeedContext::GetRightDirection()
    {
        Hedgehog::Math::CVector result = Hedgehog::Math::CVector::Zero();
        fCPlayerSpeedContextGetRightDirection(this, &result);
        return result;
    }

    inline uint32_t pCPlayerSpeedContextGetFrontDirection = 0xE72010;
    inline void fCPlayerSpeedContextGetFrontDirection(const CPlayerSpeedContext* This, Hedgehog::Math::CVector* in_pVector)
    {
        __asm
        {
            mov eax, This
            mov esi, in_pVector
            call[pCPlayerSpeedContextGetFrontDirection]
            mov in_pVector, eax
        }
    }

    inline Hedgehog::Math::CVector CPlayerSpeedContext::GetFrontDirection()
    {
        Hedgehog::Math::CVector result = Hedgehog::Math::CVector::Zero();
        fCPlayerSpeedContextGetFrontDirection(this, &result);
        return result;
    }

    inline uint32_t pCPlayerSpeedContextGetRotationSpeed = 0xE547F0;
    inline float fCPlayerSpeedContextGetRotationSpeed(const CPlayerSpeedContext* This)
    {
        volatile float result = 0.0f;
        __asm
        {
            mov esi, This
            call[pCPlayerSpeedContextGetRotationSpeed]
            movss dword ptr[result], xmm0
        }

        return result;
    }

    inline float CPlayerSpeedContext::GetRotationSpeed()
    {
        return fCPlayerSpeedContextGetRotationSpeed(this);
    }

    inline uint32_t pCPlayerSpeedContextGetRotationForce = 0xE53490;
    inline float fCPlayerSpeedContextGetRotationForce(const CPlayerSpeedContext* This, const Hedgehog::Math::CVector& in_rFrontDirection,
        const Hedgehog::Math::CVector& in_rTargetDirection)
    {
        volatile float result = 0.0f;

        __asm
        {
            push in_rTargetDirection
            mov edi, in_rFrontDirection
            mov eax, This
            call[pCPlayerSpeedContextGetRotationForce]
            movss dword ptr[result], xmm0
        }

        return result;
    }

    inline float CPlayerSpeedContext::GetRotationForce(const Hedgehog::Math::CVector& in_rFrontDirection,
        const Hedgehog::Math::CVector& in_rTargetDirection)
    {
        fCPlayerSpeedContextGetRotationForce(this, in_rFrontDirection, in_rTargetDirection);
    }

    inline uint32_t pCPlayerSpeedContextSetYawRotation = 0xE51800;

    inline void fCPlayerSpeedContextSetYawRotation(const CPlayerSpeedContext* This, const Hedgehog::Math::CQuaternion& in_rRotation,
        bool in_UpdateMatrix)
    {
        __asm
        {
            movzx eax, in_UpdateMatrix
            push eax
            mov ecx, in_rRotation
            mov eax, This
            call [pCPlayerSpeedContextSetYawRotation]
        }
    }

    inline void CPlayerSpeedContext::SetYawRotation(const Hedgehog::Math::CQuaternion& in_rRotation,
        bool in_UpdateMatrix)
    {
        fCPlayerSpeedContextSetYawRotation(this, in_rRotation, in_UpdateMatrix);
    }

    inline void CPlayerSpeedContext::SetYawRotation(float in_Angle, bool in_UpdateMatrix)
    {
        SetYawRotation(Hedgehog::Math::CQuaternion(Eigen::AngleAxisf(in_Angle, Hedgehog::Math::CVector(0, 1, 0))), in_UpdateMatrix);
    }

    inline float CPlayerSpeedContext::GetMaxChaosEnergy() const
    {
        if (StateFlag(eStateFlag_EnableChaosEnergySetting))
            return m_ChaosEnergySetting;

        if (m_ChaosEnergyGaugeSize != 1 && m_ChaosEnergyGaugeSize == 2)
            return 200.0f;

        return 100.0f;
    }
}