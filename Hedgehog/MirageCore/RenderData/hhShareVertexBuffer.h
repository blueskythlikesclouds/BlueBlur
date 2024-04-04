#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CMeshData;
    class CRenderingInfrastructure;

    class CShareVertexBuffer : public Hedgehog::Database::CDatabaseData
    {
    public:
        struct SMeshData
        {
            CMeshData* pMeshData;
            uint8_t* pVertexData;
            uint16_t* pIndexData;
            void* pVertexElements;
        };

        DX_PATCH::IDirect3DVertexBuffer9* m_pD3DVertexBuffer;
        DX_PATCH::IDirect3DVertexBuffer9* m_pD3DIndexBuffer;
        hh::vector<SMeshData> m_MeshDataList;
        CRenderingInfrastructure* m_pRenderingInfrastructure;
        uint32_t m_Field28;
        uint32_t m_Field2C;
    };

    BB_ASSERT_OFFSETOF(CShareVertexBuffer, m_pD3DVertexBuffer, 0xC);
    BB_ASSERT_OFFSETOF(CShareVertexBuffer, m_pD3DIndexBuffer, 0x10);
    BB_ASSERT_OFFSETOF(CShareVertexBuffer, m_MeshDataList, 0x14);
    BB_ASSERT_OFFSETOF(CShareVertexBuffer, m_pRenderingInfrastructure, 0x24);
    BB_ASSERT_OFFSETOF(CShareVertexBuffer, m_Field28, 0x28);
    BB_ASSERT_OFFSETOF(CShareVertexBuffer, m_Field2C, 0x2C);
    BB_ASSERT_SIZEOF(CShareVertexBuffer, 0x30);
}
