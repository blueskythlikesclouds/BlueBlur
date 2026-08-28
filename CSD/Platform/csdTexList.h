#pragma once

#include <CSD/Manager/csdmBase.h>
#include <CSD/Manager/csdmRCPtr.h>

namespace Chao::CSD
{
    class CTexList : public CBase
    {
    public:
        RCPtr<unsigned char> m_rcData;

        virtual ~CTexList() = default;
        virtual int GetChunkMagic() = 0;
        virtual void CreateResource() = 0;
        virtual void SetData(void* in_pTextureData, size_t in_pTextureDataSize) = 0;
        virtual void SetTexture(int in_Index, void* unk0, void* unk1, int unk2) = 0;
        virtual void SetFilteringMode(int in_FilterMode, void* unk0, int unk1) = 0;
        virtual void SetWrapMode(int in_WrapMode, void* unk0, int unk1) = 0;
    };

    BB_ASSERT_OFFSETOF(CTexList, m_rcData, 0x4);
    BB_ASSERT_SIZEOF(CTexList, 0xC);
}