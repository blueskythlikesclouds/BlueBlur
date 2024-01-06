#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Mirage
{
    class CTransform
    {
    public:
        Math::CQuaternion m_Rotation;
        Math::CVector m_Position;
        Math::CMatrix m_Matrix;

        void UpdateMatrix();

        void SetRotation(const Math::CQuaternion& in_rRotation);
        void SetPosition(const Math::CVector& in_rPosition);
        void SetRotationAndPosition(const Math::CQuaternion& in_rRotation, const Math::CVector& in_rPosition);
    };

    BB_ASSERT_OFFSETOF(CTransform, m_Rotation, 0x0);
    BB_ASSERT_OFFSETOF(CTransform, m_Position, 0x10);
    BB_ASSERT_OFFSETOF(CTransform, m_Matrix, 0x20);
    BB_ASSERT_SIZEOF(CTransform, 0x60);
}

#include <Hedgehog/MirageCore/Misc/hhTransform.inl>