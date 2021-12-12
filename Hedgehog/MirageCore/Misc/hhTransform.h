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

        void UpdateMatrix()
        {
            m_Matrix = Eigen::Translation3f(m_Position) * m_Rotation;
        }

        void SetRotation(const Math::CQuaternion& rotation)
        {
            m_Rotation = rotation;
            UpdateMatrix();
        }

        void SetPosition(const Math::CVector& position)
        {
            m_Position = position;
            UpdateMatrix();
        }
    };

    BB_ASSERT_OFFSETOF(CTransform, m_Rotation, 0x0);
    BB_ASSERT_OFFSETOF(CTransform, m_Position, 0x10);
    BB_ASSERT_OFFSETOF(CTransform, m_Matrix, 0x20);
    BB_ASSERT_SIZEOF(CTransform, 0x60);
}