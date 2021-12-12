#pragma once

#include <BlueBlur.inl>

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNodeListener.h>
#include <Sonic/System/GameObject.h>

namespace Sonic
{
    class CGameObject3D;
    class CMatrixNodeTransform;

    static inline BB_FUNCTION_PTR(CGameObject3D*, __stdcall, fpCGameObject3DCtor, 0xD5DAC0, CGameObject3D* This);

    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCGameObject3DMatrixNodeUpdatedCallback, 0xD5C780,
        CGameObject3D* This, const Hedgehog::Math::CMatrix& matrix, size_t flags);

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

        virtual void AddCallback(const Hedgehog::Base::THolder<CWorld>& worldHolder,
            Sonic::CGameDocument* pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& spDatabase) override {}

        virtual bool MatrixNodeUpdatedCallback(const Hedgehog::Math::CMatrix& matrix, size_t flags) override
        {
            return fpCGameObject3DMatrixNodeUpdatedCallback(this, matrix, flags);
        }

        void SetPosition(const Hedgehog::Math::CVector& position)
        {
            fpCGameObject3DSetPosition(this, position);
        }
    };

    BB_ASSERT_OFFSETOF(CGameObject3D, m_spMatrixNodeTransform, 0xB8);
    BB_ASSERT_SIZEOF(CGameObject3D, 0xF4);
}