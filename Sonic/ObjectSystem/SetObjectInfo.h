#pragma once

#include <BlueBlur.inl>

namespace Sonic
{
    class CGameObject;
    class CSetObjectListener;

    struct SSetObjectInfo
    {
        boost::shared_ptr<CGameObject> spGameObject;
        boost::shared_ptr<CSetObjectListener> spSetObjectListener;
        float Field10;
        bool Field14;
        alignas(0x10) Hedgehog::Math::CQuaternion Field20;
        size_t Field30;
        size_t Field34;
        bool Field38;
        float Field3C;

        SSetObjectInfo(
            const boost::shared_ptr<CGameObject>& in_spGameObject,
            const boost::shared_ptr<CSetObjectListener>& in_spSetObjectListener,
            const Hedgehog::Math::CQuaternion& in_rField20 = Hedgehog::Math::CQuaternion::Identity(),
            bool in_Field14 = false,
            float in_Field10 = 0.0f) :

            spGameObject(in_spGameObject),
            spSetObjectListener(in_spSetObjectListener),

            Field10(in_Field10),
            Field14(in_Field14),
            Field20(in_rField20),

            Field30(1),
            Field34(0),
            Field38(true),
            Field3C(*(float*)0x1A44D64)
        {
        }
    };

    BB_ASSERT_OFFSETOF(SSetObjectInfo, spGameObject, 0x00);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, spSetObjectListener, 0x08);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, Field10, 0x10);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, Field14, 0x14);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, Field20, 0x20);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, Field30, 0x30);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, Field34, 0x34);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, Field38, 0x38);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, Field3C, 0x3C);
    BB_ASSERT_SIZEOF(SSetObjectInfo, 0x40);
}