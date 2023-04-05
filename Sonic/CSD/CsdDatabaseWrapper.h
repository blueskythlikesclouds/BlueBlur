#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Hedgehog::Database
{
    class CDatabase;
}

namespace Sonic
{
    class CCsdProject;
    class CCsdDatabaseWrapper;

    static uint32_t pCCsdDatabaseWrapperGetCsdProject = 0x10DD920;

    static void fCCsdDatabaseWrapperGetCsdProject(const Hedgehog::Base::CSharedString* in_pName, CCsdDatabaseWrapper* This, boost::shared_ptr<CCsdProject>* out_spCsdProject)
    {
        __asm
        {
            push out_spCsdProject
            push This
            mov edi, in_pName
            call [pCCsdDatabaseWrapperGetCsdProject]
        }
    }

    class CCsdDatabaseWrapper
    {
    public:
        Hedgehog::Database::CDatabase* m_pDatabase;

        CCsdDatabaseWrapper(Hedgehog::Database::CDatabase* in_pDatabase) : m_pDatabase(in_pDatabase) {}
        
        boost::shared_ptr<CCsdProject> GetCsdProject(const Hedgehog::Base::CSharedString& in_rName)
        {
            boost::shared_ptr<CCsdProject> spCsdProject;
            fCCsdDatabaseWrapperGetCsdProject(&in_rName, this, &spCsdProject);
            return spCsdProject;
        }
    };
}