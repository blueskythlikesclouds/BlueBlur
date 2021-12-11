#pragma once

#include <BlueBlur.inl>

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNode.h>
#include <Hedgehog/MirageCore/Misc/hhTransform.h>

namespace Sonic
{
    class CMatrixNodeTransform : public Hedgehog::Mirage::CMatrixNode
    {
    public:
        Hedgehog::Mirage::CTransform m_Transform;
        Hedgehog::Math::CMatrix m_PrevTransform;
    };

    ASSERT_OFFSETOF(CMatrixNodeTransform, m_Transform, 0x60);
    ASSERT_OFFSETOF(CMatrixNodeTransform, m_PrevTransform, 0xC0);
    ASSERT_SIZEOF(CMatrixNodeTransform, 0x100);
}