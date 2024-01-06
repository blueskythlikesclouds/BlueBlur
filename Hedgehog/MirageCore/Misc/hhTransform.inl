namespace Hedgehog::Mirage
{
    inline void CTransform::UpdateMatrix()
    {
        m_Matrix = Eigen::Translation3f(m_Position) * m_Rotation;
    }

    inline void CTransform::SetRotation(const Math::CQuaternion& in_rRotation)
    {
        m_Rotation = in_rRotation;
        UpdateMatrix();
    }

    inline void CTransform::SetPosition(const Math::CVector& in_rPosition)
    {
        m_Position = in_rPosition;
        UpdateMatrix();
    }

    inline void CTransform::SetRotationAndPosition(const Math::CQuaternion& in_rRotation,
        const Math::CVector& in_rPosition)
    {
        m_Rotation = in_rRotation;
        m_Position = in_rPosition;
        UpdateMatrix();
    }
}