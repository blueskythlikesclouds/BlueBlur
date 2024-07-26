#pragma once

#include <Sonic/System/GameObject3D.h>

namespace Sonic
{
    class CGlitterPlayer;

    class CObjectBase : public CGameObject3D
    {
    public:
        struct SElementInfo
        {
            boost::shared_ptr<Hedgehog::Mirage::CSingleElement> spElement;
            bool IsValid = false;
            size_t Flag = 0;

            SElementInfo(boost::shared_ptr<Hedgehog::Mirage::CSingleElement>& in_spElement) : spElement(in_spElement) {}
        };

        size_t m_FieldF4;
        Sonic::CGlitterPlayer* m_pGlitterPlayer;
        size_t m_FieldFC;

        CObjectBase() : CGameObject3D(), m_FieldF4(0), m_pGlitterPlayer(nullptr), m_FieldFC(0) {}
        CObjectBase(const bb_null_ctor& nil) : CGameObject3D(nil) {}

        BB_OVERRIDE_FUNCTION_PTR(bool, CMessageActor, ProcessMessage, 0x1058D00, 
            (Hedgehog::Universe::Message&, in_rMessage), (bool, in_Flag))

        BB_OVERRIDE_FUNCTION_PTR(void, CUpdateUnit, UpdateParallel, 0x10589A0, 
            (const Hedgehog::Universe::SUpdateInfo&, in_rUpdateInfo))

        BB_OVERRIDE_FUNCTION_PTR(void, CGameObject, Initialize, 0x1058670, 
            (const Hedgehog::Base::THolder<CWorld>&, in_rWorldHolder), (Sonic::CGameDocument*, in_pGameDocument))

        BB_OVERRIDE_FUNCTION_PTR(void, CGameObject, AddCallback, 0x1058B00, (const Hedgehog::Base::THolder<CWorld>&, in_rWorldHolder),
            (Sonic::CGameDocument*, in_pGameDocument), (const boost::shared_ptr<Hedgehog::Database::CDatabase>&, in_spDatabase))

        BB_OVERRIDE_FUNCTION_PTR(void, CGameObject, DeathCallback, 0x1058960, (Sonic::CGameDocument*, in_pGameDocument))

        virtual void CObjectBase5C() {}

        BB_VIRTUAL_FUNCTION_PTR(void, SetAddUpdateUnit, 0x10585E0, (Sonic::CGameDocument*, in_pGameDocument))

        virtual bool SetAddRenderables(Sonic::CGameDocument* in_pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase) { return true; }
        virtual bool SetAddColliders(const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase) { return true; }
        virtual bool SetAddStateMachine(const Hedgehog::Base::THolder<Sonic::CWorld>& in_rWorldHolder,
            Sonic::CGameDocument* in_pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase) { return true; }
        virtual bool CObjectBase70(void*, void*, void*) { return true; }
        virtual void CObjectBase74(void*) {}
        virtual void CObjectBase78(void*) {}
        virtual void SetUpdateParallel(const Hedgehog::Universe::SUpdateInfo& in_rUpdateInfo) {}
        virtual void SetUpdatePostParallel(const Hedgehog::Universe::SUpdateInfo& in_rUpdateInfo) {}
        virtual void CObjectBase84(void*) {}

        BB_VIRTUAL_FUNCTION_PTR(void*, CObjectBase88, 0x10585D0, (void*, A1))

        virtual void CObjectBase8C() {}

        bool AddRenderable(const char* in_pModelName, SElementInfo& out_spElementInfo,
            const boost::shared_ptr<Hedgehog::Mirage::CMatrixNode>& in_rMatrixNode, const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase);
    };

    BB_ASSERT_OFFSETOF(CObjectBase, m_FieldF4, 0xF4);
    BB_ASSERT_OFFSETOF(CObjectBase, m_pGlitterPlayer, 0xF8);
    BB_ASSERT_OFFSETOF(CObjectBase, m_FieldFC, 0xFC);
    BB_ASSERT_SIZEOF(CObjectBase, 0x100);
}

#include <Sonic/Object/ObjectBase.inl>