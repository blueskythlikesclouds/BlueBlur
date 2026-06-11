#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Hedgehog::Database
{
    class CDatabase;
}

namespace Hedgehog::Font
{
    class CFontConverseData;
    class CFontTextureData;

    class CFontDatabaseWrapper : public Hedgehog::Base::CObject
    {
    public:
        Hedgehog::Database::CDatabase* m_pDatabase;
        bool m_Flag;
        
        CFontDatabaseWrapper(Hedgehog::Database::CDatabase* pDatabase);        

        boost::shared_ptr<CFontConverseData> GetFontConverseData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CFontTextureData> GetFontTextureData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);

    };

    BB_ASSERT_OFFSETOF(CFontDatabaseWrapper, m_pDatabase, 0x0);
    BB_ASSERT_OFFSETOF(CFontDatabaseWrapper, m_Flag, 0x4);
    BB_ASSERT_SIZEOF(CFontDatabaseWrapper, 0x8);
}

#include <Hedgehog/Font/hhFontDatabaseWrapper.inl>