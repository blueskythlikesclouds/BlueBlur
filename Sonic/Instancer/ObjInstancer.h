#pragma once

#include <Sonic/System/GameObject3D.h>
#include <Sonic/Instancer/MetaInstancer.h>

namespace Sonic
{
    class CInstancerAssetData;

    class CObjInstancer : public CGameObject3D
    {
    public:
        boost::shared_ptr<CMetaInstancer::CDesc> m_spMetaInstancerDesc;
        boost::shared_ptr<CInstancerAssetData> m_spInstancerAssetData;
        CMetaInstancer* m_scpInstancer;
    };

    BB_ASSERT_OFFSETOF(CObjInstancer, m_spMetaInstancerDesc, 0xF4);
    BB_ASSERT_OFFSETOF(CObjInstancer, m_spInstancerAssetData, 0xFC);
    BB_ASSERT_OFFSETOF(CObjInstancer, m_scpInstancer, 0x104);
    BB_ASSERT_SIZEOF(CObjInstancer, 0x108);
}