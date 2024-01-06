namespace Sonic
{
    inline BB_FUNCTION_PTR(CGameObject3D*, __stdcall, fpCGameObject3DCtor, 0xD5DAC0, CGameObject3D* This);

    inline CGameObject3D::CGameObject3D() : CGameObject3D(bb_null_ctor{})
    {
        fpCGameObject3DCtor(this);
    }

    inline BB_FUNCTION_PTR(void, __stdcall, fpCGameObject3DSetPosition, 0xD5CE10,
        CGameObject3D* This, const Hedgehog::Math::CVector& in_rPosition);

    inline void CGameObject3D::SetPosition(const Hedgehog::Math::CVector& in_rPosition)
    {
        fpCGameObject3DSetPosition(this, in_rPosition);
    }

    inline BB_FUNCTION_PTR(bool, __stdcall, fpCGameObject3DAddRigidBody, 0xE98BD0,
        const boost::shared_ptr<Sonic::CRigidBody>&, Sonic::CGameObject3D* This, hk2010_2_0::hkpShape* in_pShape, int in_Mask,
        boost::shared_ptr<Hedgehog::Mirage::CMatrixNode> in_spMatrixNode);

    inline bool CGameObject3D::AddRigidBody(const boost::shared_ptr<CRigidBody>& in_spRigidBody,
        hk2010_2_0::hkpShape* in_pShape, int in_CollisionID,
        const boost::shared_ptr<Hedgehog::Mirage::CMatrixNode>& in_spMatrixNode)
    {
        return fpCGameObject3DAddRigidBody(in_spRigidBody, this, in_pShape, in_CollisionID, in_spMatrixNode);
    }

    inline constexpr uint32_t pCGameObject3DAddRigidBodyFromDatabase = 0xE98EB0;

    inline void __declspec(naked) __declspec(noinline) fCGameObject3DAddRigidBodyFromDatabase()
    {
        __asm
        {
            mov eax, ecx
            jmp pCGameObject3DAddRigidBodyFromDatabase
        }
    }

    inline BB_FUNCTION_PTR(bool, __thiscall, fpCGameObject3DAddRigidBodyFromDatabase, fCGameObject3DAddRigidBodyFromDatabase,
        const char* in_ContainerName, const boost::shared_ptr<CRigidBody>& in_spRigidBody, Sonic::CGameObject3D* This,
        const char* in_ShapeName, int in_ColID, boost::shared_ptr<Hedgehog::Mirage::CMatrixNode> in_spMatrixNodeSingleElement,
        boost::shared_ptr<Hedgehog::Database::CDatabase> in_spDatabase);

    inline bool CGameObject3D::AddRigidBody(const boost::shared_ptr<CRigidBody>& in_spRigidBody,
        const char* in_pContainerName, const char* in_pShapeName, int in_CollisionID,
        const boost::shared_ptr<Hedgehog::Mirage::CMatrixNode>& in_spMatrixNode,
        const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase)
    {
        return fpCGameObject3DAddRigidBodyFromDatabase(in_pContainerName, in_spRigidBody, this, in_pShapeName, in_CollisionID, in_spMatrixNode, in_spDatabase);
    }

    inline BB_FUNCTION_PTR(void*, __stdcall, fpCGameObject3DAddEventCollision, 0xD5E090,
        CGameObject3D* This, const Hedgehog::Base::CStringSymbol& in_rSymbol, hk2010_2_0::hkpShape** in_ppShape, int in_Mask, bool in_IsOffset, bool in_IsTrigger);

    inline void CGameObject3D::AddEventCollision(const Hedgehog::Base::CStringSymbol& in_rSymbol,
        hk2010_2_0::hkpShape* in_pShape, int in_CollisionMask, bool in_IsOffset, bool in_IsContactPhantom)
    {
        fpCGameObject3DAddEventCollision(this, in_rSymbol, &in_pShape, in_CollisionMask, in_IsOffset, in_IsContactPhantom);
    }

    inline BB_FUNCTION_PTR(void*, __stdcall, fpCGameObject3DAddEventCollisionGivenNode, 0xD5DC90,
        CGameObject3D* This, const Hedgehog::Base::CStringSymbol& in_rSymbol, hk2010_2_0::hkpShape** in_ppShape, int in_Mask, bool in_IsTrigger,
        boost::shared_ptr<Hedgehog::Mirage::CMatrixNode> in_spMatrixNode);

    inline void CGameObject3D::AddEventCollision(const Hedgehog::Base::CStringSymbol& in_rSymbol,
        hk2010_2_0::hkpShape* in_pShape, int in_CollisionMask, bool in_IsContactPhantom,
        const boost::shared_ptr<Hedgehog::Mirage::CMatrixNode>& in_spMatrixNode)
    {
        fpCGameObject3DAddEventCollisionGivenNode(this, in_rSymbol, &in_pShape, in_CollisionMask, in_IsContactPhantom, in_spMatrixNode);
    }
}