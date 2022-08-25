#pragma once

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNodeListener.h>
#include <Sonic/System/GameObject.h>

namespace Sonic
{
    class CGameObject3D;
    class CMatrixNodeTransform;

    static inline BB_FUNCTION_PTR(CGameObject3D*, __stdcall, fpCGameObject3DCtor, 0xD5DAC0, CGameObject3D* This);

    static inline BB_FUNCTION_PTR(void, __stdcall, fpCGameObject3DSetPosition, 0xD5CE10,
        CGameObject3D* This, const Hedgehog::Math::CVector& position);

    class CGameObject3D : public CGameObject, public Hedgehog::Mirage::CMatrixNodeListener
    {
    public:
        BB_INSERT_PADDING(0x8);
        boost::shared_ptr<CMatrixNodeTransform> m_spMatrixNodeTransform;
        BB_INSERT_PADDING(0x34);

        CGameObject3D(const bb_null_ctor&) : CGameObject(bb_null_ctor{}), CMatrixNodeListener(bb_null_ctor{}) {}

        CGameObject3D() : CGameObject3D(bb_null_ctor{})
        {
            fpCGameObject3DCtor(this);
        }

        virtual ~CGameObject3D();

        BB_OVERRIDE_FUNCTION_PTR(void, CGameObject, AddCallback, 0xD5CB80, (const Hedgehog::Base::THolder<CWorld>&, worldHolder),
            (Sonic::CGameDocument*, pGameDocument), (const boost::shared_ptr<Hedgehog::Database::CDatabase>&, spDatabase))

        BB_OVERRIDE_FUNCTION_PTR(void, CGameObject, RemoveCallback, 0xD5C770, (Sonic::CGameDocument*, pGameDocument))

        BB_OVERRIDE_FUNCTION_PTR(void, CGameObject, CGameObject24, 0xD5D540, (void*, A1))

        BB_OVERRIDE_FUNCTION_PTR(bool, CMatrixNodeListener, MatrixNodeChangedCallback, 0xD5C780, 
            (const Hedgehog::Math::CMatrix&, matrix), (size_t, flags))

        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable34, 0xD5D6D0, (void*, A1))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable38, 0xD5D200, (void*, A1), (void*, A2), (void*, A3), (void*, A4))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable3C, 0xD5CCB0, (void*, A1), (void*, A2), (void*, A3))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable40, 0xD5CCE0, (void*, A1), (void*, A2))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable44, 0xD5D3A0, (void*, A1), (void*, A2), (void*, A3))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable48, 0xD5CD10, (void*, A1), (void*, A2))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable4C, 0xD5CBF0, (void*, A1), (void*, A2), (void*, A3))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable50, 0xD5CC20, (void*, A1), (void*, A2))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable54, 0xD5CC50, (void*, A1), (void*, A2), (void*, A3))
        BB_VIRTUAL_FUNCTION_PTR(void*, CGameObject3DVtable58, 0xD5CC80, (void*, A1), (void*, A2))

        void SetPosition(const Hedgehog::Math::CVector& position)
        {
            fpCGameObject3DSetPosition(this, position);
        }
    };

    BB_ASSERT_OFFSETOF(CGameObject3D, m_spMatrixNodeTransform, 0xB8);
    BB_ASSERT_SIZEOF(CGameObject3D, 0xF4);
}