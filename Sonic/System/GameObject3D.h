#pragma once

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNodeListener.h>
#include <Sonic/System/GameObject.h>

namespace Hedgehog::Database
{
    class CDatabase;
}

namespace Sonic
{
    class CMatrixNodeTransform;
    class CRigidBody;
    class CEventCollisionHolder;

    class CGameObject3D : public CGameObject, public Hedgehog::Mirage::CMatrixNodeListener
    {
    public:
        BB_INSERT_PADDING(0xC);
        boost::shared_ptr<CMatrixNodeTransform> m_spMatrixNodeTransform;
        boost::shared_ptr<CEventCollisionHolder> m_spEventCollisionHolder;
        BB_INSERT_PADDING(0x2C);

        CGameObject3D(const bb_null_ctor& nil) : CGameObject(nil), CMatrixNodeListener(nil) {}
        CGameObject3D();
        virtual ~CGameObject3D();

        BB_OVERRIDE_FUNCTION_PTR(bool, CMessageActor, ProcessMessage, 0xD5E4D0,
            (Hedgehog::Universe::Message&, in_rMessage), (bool, in_Flag))

        BB_OVERRIDE_FUNCTION_PTR(void, CGameObject, AddCallback, 0xD5CB80, (const Hedgehog::Base::THolder<CWorld>&, in_rWorldHolder),
            (Sonic::CGameDocument*, in_pGameDocument), (const boost::shared_ptr<Hedgehog::Database::CDatabase>&, in_spDatabase))

        BB_OVERRIDE_FUNCTION_PTR(void, CGameObject, RemoveCallback, 0xD5C770, (Sonic::CGameDocument*, in_pGameDocument))

        BB_OVERRIDE_FUNCTION_PTR(void, CGameObject, DeathCallback, 0xD5D540, (Sonic::CGameDocument*, in_pGameDocument))

        BB_OVERRIDE_FUNCTION_PTR(bool, CMatrixNodeListener, MatrixNodeChangedCallback, 0xD5C780, 
            (const Hedgehog::Math::CMatrix&, in_rMatrix), (size_t, in_Flags))

        BB_VIRTUAL_FUNCTION_PTR(void,  SetVisible, 0xD5D6D0, (bool, in_IsVisible))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable38, 0xD5D200, (void*, A1), (void*, A2), (void*, A3), (void*, A4))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable3C, 0xD5CCB0, (void*, A1), (void*, A2), (void*, A3))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable40, 0xD5CCE0, (void*, A1), (void*, A2))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable44, 0xD5D3A0, (void*, A1), (void*, A2), (void*, A3))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable48, 0xD5CD10, (void*, A1), (void*, A2))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable4C, 0xD5CBF0, (void*, A1), (void*, A2), (void*, A3))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable50, 0xD5CC20, (void*, A1), (void*, A2))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable54, 0xD5CC50, (void*, A1), (void*, A2), (void*, A3))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable58, 0xD5CC80, (void*, A1), (void*, A2))

        void SetPosition(const Hedgehog::Math::CVector& in_rPosition);

        // Adds a CRigidBody to this game, attached to a MatrixNode.
        // Requires a hkpShape to be made first, and collision mask ID--see the function 0x1255FA0 for examples.
        bool AddRigidBody(const boost::shared_ptr<CRigidBody>& in_spRigidBody, 
            hk2010_2_0::hkpShape* in_pShape, int in_CollisionID, const boost::shared_ptr<Hedgehog::Mirage::CMatrixNode>& in_spMatrixNode);

        // Adds a CRigidBody to this game, attached to a MatrixNode.
        // Takes in the name of a ".phy.hkx" file, which is the container for rigidbodies in the game.
        // Also takes in the name of the rigidbody from the container to use.
        bool AddRigidBody(const boost::shared_ptr<CRigidBody>& in_spRigidBody, const char* in_pContainerName,
            const char* in_pShapeName, int in_CollisionID, 
            const boost::shared_ptr<Hedgehog::Mirage::CMatrixNode>& in_spMatrixNode,
            const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase);

        void AddEventCollision(const Hedgehog::Base::CStringSymbol& in_rSymbol, hk2010_2_0::hkpShape* in_pShape, int in_CollisionMask, 
            bool in_IsOffset, bool in_IsContactPhantom);

        void AddEventCollision(const Hedgehog::Base::CStringSymbol& in_rSymbol, hk2010_2_0::hkpShape* in_pShape, int in_CollisionMask,
            bool in_IsContactPhantom, const boost::shared_ptr<Hedgehog::Mirage::CMatrixNode>& in_spMatrixNode);

        void SetCullingRange(float in_Range);
    };

    BB_ASSERT_OFFSETOF(CGameObject3D, m_spMatrixNodeTransform, 0xB8);
    BB_ASSERT_SIZEOF(CGameObject3D, 0xF4);
}

#include <Sonic/System/GameObject3D.inl>