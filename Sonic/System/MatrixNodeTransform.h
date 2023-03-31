#pragma once

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNode.h>
#include <Hedgehog/MirageCore/Misc/hhTransform.h>

namespace Sonic
{
    class CMatrixNodeTransform : public Hedgehog::Mirage::CMatrixNode
    {
    private:
        static void* fpCMatrixNodeTransformCtor(void* This)
        {
            void* result = nullptr;
            uint32_t func = 0x00D172B0;
            __asm
            {
                mov edi, This
                call func
                mov result, eax
            }

            return result;
        }
    public:
        Hedgehog::Mirage::CTransform m_Transform;
        Hedgehog::Math::CMatrix m_WorldMatrix;

        CMatrixNodeTransform()
        {
            fpCMatrixNodeTransformCtor(this);
        }
    };

    BB_ASSERT_OFFSETOF(CMatrixNodeTransform, m_Transform, 0x60);
    BB_ASSERT_OFFSETOF(CMatrixNodeTransform, m_WorldMatrix, 0xC0);
    BB_ASSERT_SIZEOF(CMatrixNodeTransform, 0x100);
}