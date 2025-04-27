namespace Sonic
{
    inline hk2010_2_0::hkpShape* CRigidBody::GetShape() const
    {
        return m_pHkpRigidBody->m_Collideable.m_Shape;
    }
}