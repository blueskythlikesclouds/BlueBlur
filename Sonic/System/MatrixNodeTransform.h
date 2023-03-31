#pragma once

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNode.h>
#include <Hedgehog/MirageCore/Misc/hhTransform.h>

namespace Sonic
{
    class CMatrixNodeTransform;

    static uint32_t pCMatrixNodeTransformCtor = 0xD172B0;

    static void fCMatrixNodeTransformCtor(CMatrixNodeTransform* This)
    {
        __asm
        {
            mov edi, This
            call[pCMatrixNodeTransformCtor]
        }
    }

    class CMatrixNodeTransform : public Hedgehog::Mirage::CMatrixNode
    {
    public:
        Hedgehog::Mirage::CTransform m_Transform;
        Hedgehog::Math::CMatrix m_WorldMatrix;

        CMatrixNodeTransform()
        {
            fCMatrixNodeTransformCtor(this);
        }
    };

    BB_ASSERT_OFFSETOF(CMatrixNodeTransform, m_Transform, 0x60);
    BB_ASSERT_OFFSETOF(CMatrixNodeTransform, m_WorldMatrix, 0xC0);
    BB_ASSERT_SIZEOF(CMatrixNodeTransform, 0x100);
}