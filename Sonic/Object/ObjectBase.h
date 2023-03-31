#pragma once

#include <Sonic/System/GameObject3D.h>

namespace Sonic
{
    class CObjectBase : public CGameObject3D
    {
    public:
        size_t m_FieldF4;
        size_t m_FieldF8;
        size_t m_FieldFC;

        CObjectBase() : CGameObject3D(), m_FieldF4(0), m_FieldF8(0), m_FieldFC(0) {}
        CObjectBase(const bb_null_ctor& nil) : CGameObject3D(nil) {}

        BB_OVERRIDE_FUNCTION_PTR(bool, CMessageActor, ProcessMessage, 0x1058D00, 
            (Hedgehog::Universe::Message&, in_rMessage), (bool, in_Flag))

        BB_OVERRIDE_FUNCTION_PTR(void, CUpdateUnit, UpdateParallel, 0x10589A0, 
            (const Hedgehog::Universe::SUpdateInfo&, in_rUpdateInfo))

        BB_OVERRIDE_FUNCTION_PTR(void, CGameObject, Initialize, 0x1058670, 
            (const Hedgehog::Base::THolder<CWorld>&, in_rWorldHolder), (Sonic::CGameDocument*, in_pGameDocument))

        BB_OVERRIDE_FUNCTION_PTR(void, CGameObject, AddCallback, 0x1058B00, (const Hedgehog::Base::THolder<CWorld>&, in_rWorldHolder),
            (Sonic::CGameDocument*, in_pGameDocument), (const boost::shared_ptr<Hedgehog::Database::CDatabase>&, in_spDatabase))

        BB_OVERRIDE_FUNCTION_PTR(void, CGameObject, CGameObject24, 0x1058960, (void*, A1))

        virtual void CObjectBase5C() {}

        BB_VIRTUAL_FUNCTION_PTR(void*, SetAddUpdateUnit, 0x10585E0, (void*, A1))

        virtual bool SetAddRenderables(Sonic::CGameDocument* in_pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase) { return true; }
        virtual bool SetAddColliders(const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase) { return true; }
        virtual bool SetAddStateMachine(const Hedgehog::Base::THolder<Sonic::CWorld>& in_worldHolder,
            Sonic::CGameDocument* in_pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase) { return true; }
        virtual bool CObjectBase70(void*, void*, void*) { return true; }
        virtual void CObjectBase74(void*) {}
        virtual void CObjectBase78(void*) {}
        virtual void SetUpdateParallel(const Hedgehog::Universe::SUpdateInfo& updateInfo) {}
        virtual void SetUpdatePostParallel(const Hedgehog::Universe::SUpdateInfo& updateInfo) {}
        virtual void CObjectBase84(void*) {}

        BB_VIRTUAL_FUNCTION_PTR(void*, CObjectBase88, 0x10585D0, (void*, A1))

        virtual void CObjectBase8C(void*) {}
    };

    BB_ASSERT_OFFSETOF(CObjectBase, m_FieldF4, 0xF4);
    BB_ASSERT_OFFSETOF(CObjectBase, m_FieldF8, 0xF8);
    BB_ASSERT_OFFSETOF(CObjectBase, m_FieldFC, 0xFC);
    BB_ASSERT_SIZEOF(CObjectBase, 0x100);
}