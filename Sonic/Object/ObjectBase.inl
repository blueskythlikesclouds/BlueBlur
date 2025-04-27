namespace Sonic
{
    inline uint32_t pCObjectBaseAddRenderable = 0xE95DC0;

	inline BB_NOINLINE void __declspec(naked) fCObjectBaseAddRenderable()
    {
        __asm
        {
            mov eax, ecx
            jmp pCObjectBaseAddRenderable
        }
    }

    inline BB_FUNCTION_PTR(bool, __thiscall, fpCObjectBaseAddRenderable, fCObjectBaseAddRenderable,
        CObjectBase::SElementInfo& out_spElementInfo, Sonic::CObjectBase* This,
        const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase, const char* in_pModelName, boost::shared_ptr<Hedgehog::Mirage::CMatrixNode> in_spMatrixNode);

    inline bool CObjectBase::AddRenderable(const char* in_pModelName,
        SElementInfo& out_spElementInfo,
        const boost::shared_ptr<Hedgehog::Mirage::CMatrixNode>& in_rMatrixNode,
        const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase)
    {
        return fpCObjectBaseAddRenderable(out_spElementInfo, this, in_spDatabase, in_pModelName, in_rMatrixNode);
    }
}