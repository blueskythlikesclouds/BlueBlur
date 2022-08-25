#pragma once

#include <BlueBlur.inl>

namespace Sonic
{
    class CObjectBase;
    class CSetObjectListener;

    struct SSetObjectInfo
    {
        boost::shared_ptr<CObjectBase> m_spObject;
        boost::shared_ptr<CSetObjectListener> m_spSetObjectListener;
        float m_Field10;
        bool m_Field14;
        alignas(0x10) Hedgehog::Math::CQuaternion m_Field20;
        size_t m_Field30;
        size_t m_Field34;
        bool m_Field38;
        float m_Field3C;
    };

    BB_ASSERT_OFFSETOF(SSetObjectInfo, m_spObject, 0x00);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, m_spSetObjectListener, 0x08);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, m_Field10, 0x10);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, m_Field14, 0x14);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, m_Field20, 0x20);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, m_Field30, 0x30);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, m_Field34, 0x34);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, m_Field38, 0x38);
    BB_ASSERT_OFFSETOF(SSetObjectInfo, m_Field3C, 0x3C);
    BB_ASSERT_SIZEOF(SSetObjectInfo, 0x40);
}