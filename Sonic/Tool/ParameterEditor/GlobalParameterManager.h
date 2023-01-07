#pragma once

#include <Hedgehog/Base/Container/hhList.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

#include "GlobalParameterManager.h"
#include "ParameterFile.h"

namespace Sonic
{
    class CParameterFile;

    class CGlobalParameterManager;

    static inline uint32_t pCGlobalParameterManagerCreateParameterFile = 0xCE9A40;

    static void fCGlobalParameterManagerCreateParameterFile(CGlobalParameterManager* in_pGlobalParameterManager, boost::shared_ptr<CParameterFile>* out_spParameterFile,
        const Hedgehog::Base::CSharedString* in_pName, const Hedgehog::Base::CSharedString* in_pDescription)
    {
        __asm
        {
            push in_pDescription
            mov eax, in_pName
            push out_spParameterFile
            push in_pGlobalParameterManager
            call[pCGlobalParameterManagerCreateParameterFile]
        }
    }

    class CGlobalParameterManager
    {
    public:
        hh::list<boost::shared_ptr<CParameterFile>> m_GlobalParameterFileList;
        hh::list<boost::shared_ptr<CParameterFile>> m_LocalParameterFileList;

        boost::shared_ptr<CParameterFile> CreateParameterFile(const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription)
        {
            boost::shared_ptr<CParameterFile> spParameterFile;
            fCGlobalParameterManagerCreateParameterFile(this, &spParameterFile, &in_rName, &in_rDescription);
            return spParameterFile;
        }
    };

    BB_ASSERT_OFFSETOF(CGlobalParameterManager, m_GlobalParameterFileList, 0x0);
    BB_ASSERT_OFFSETOF(CGlobalParameterManager, m_LocalParameterFileList, 0xC);
    BB_ASSERT_SIZEOF(CGlobalParameterManager, 0x18);
}
