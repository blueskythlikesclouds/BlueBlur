#pragma once

#include <Hedgehog/Base/Container/hhMap.h>
#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>
#include <Hedgehog/MirageCore/Misc/hhPrimitive.h>
#include <Hedgehog/MirageCore/Misc/hhVertexDeclarationPtr.h>

namespace Hedgehog::Mirage
{
    class CMaterialData;

    class CMeshData : public Database::CDatabaseData
    {
    public:
        size_t m_IndexNum;
        size_t m_VertexNum;
        size_t m_VertexSize;
        size_t m_NodeNum;
        uint8_t* m_pNodeIndices;
        size_t m_VertexOffset;
        size_t m_IndexOffset;
        DX_PATCH::IDirect3DIndexBuffer9* m_pD3DIndexBuffer;
        DX_PATCH::IDirect3DVertexBuffer9* m_pD3DVertexBuffer;
        boost::shared_ptr<CMaterialData> m_spMaterial;
        CVertexDeclarationPtr m_VertexDeclarationPtr;
        CPrimitive m_Primitive;
        Base::CSharedString m_MaterialName;
        map<void*, void*> m_Field94;
    };
    
    BB_ASSERT_OFFSETOF(CMeshData, m_IndexNum, 0xC);
    BB_ASSERT_OFFSETOF(CMeshData, m_VertexNum, 0x10);
    BB_ASSERT_OFFSETOF(CMeshData, m_VertexSize, 0x14);
    BB_ASSERT_OFFSETOF(CMeshData, m_NodeNum, 0x18);
    BB_ASSERT_OFFSETOF(CMeshData, m_pNodeIndices, 0x1C);
    BB_ASSERT_OFFSETOF(CMeshData, m_VertexOffset, 0x20);
    BB_ASSERT_OFFSETOF(CMeshData, m_IndexOffset, 0x24);
    BB_ASSERT_OFFSETOF(CMeshData, m_pD3DIndexBuffer, 0x28);
    BB_ASSERT_OFFSETOF(CMeshData, m_pD3DVertexBuffer, 0x2C);
    BB_ASSERT_OFFSETOF(CMeshData, m_spMaterial, 0x30);
    BB_ASSERT_OFFSETOF(CMeshData, m_VertexDeclarationPtr, 0x38);
    BB_ASSERT_OFFSETOF(CMeshData, m_Primitive, 0x40);
    BB_ASSERT_OFFSETOF(CMeshData, m_MaterialName, 0x90);
    BB_ASSERT_OFFSETOF(CMeshData, m_Field94, 0x94);
    BB_ASSERT_SIZEOF(CMeshData, 0xA0);
}