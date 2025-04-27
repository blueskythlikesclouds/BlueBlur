namespace Sonic
{
    inline uint32_t pCGlobalParameterManagerCreateParameterFile = 0xCE9A40;

    inline BB_NOINLINE void fCGlobalParameterManagerCreateParameterFile(CGlobalParameterManager* in_pGlobalParameterManager, boost::shared_ptr<CParameterFile>* out_spParameterFile,
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

    inline boost::shared_ptr<CParameterFile> CGlobalParameterManager::CreateParameterFile(
        const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription)
    {
        boost::shared_ptr<CParameterFile> spParameterFile;
        fCGlobalParameterManagerCreateParameterFile(this, &spParameterFile, &in_rName, &in_rDescription);
        return spParameterFile;
    }
}