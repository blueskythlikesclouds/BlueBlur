namespace Sonic
{
    inline uint32_t pCCsdDatabaseWrapperGetCsdProject = 0x10DD920;

    inline void fCCsdDatabaseWrapperGetCsdProject(const Hedgehog::Base::CSharedString* in_pName, CCsdDatabaseWrapper* This, boost::shared_ptr<CCsdProject>* out_spCsdProject)
    {
        __asm
        {
            push out_spCsdProject
            push This
            mov edi, in_pName
            call[pCCsdDatabaseWrapperGetCsdProject]
        }
    }

    inline boost::shared_ptr<CCsdProject> CCsdDatabaseWrapper::GetCsdProject(
        const Hedgehog::Base::CSharedString& in_rName)
    {
        boost::shared_ptr<CCsdProject> spCsdProject;
        fCCsdDatabaseWrapperGetCsdProject(&in_rName, this, &spCsdProject);
        return spCsdProject;
    }
}