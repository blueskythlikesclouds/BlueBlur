namespace Sonic
{
    inline uint32_t pCObjectBaseAddRenderable = 0xE95DC0;

    inline void __declspec(naked) __declspec(noinline) fCObjectBaseAddRenderable()
    {
        __asm
        {
            mov eax, ecx
            jmp pCObjectBaseAddRenderable
        }
    }

    inline BB_FUNCTION_PTR(bool, __thiscall, fpCObjectBaseAddRenderable, fCObjectBaseAddRenderable,
        const boost::shared_ptr<Hedgehog::Mirage::CSingleElement>& out_spSingleElement, Sonic::CObjectBase* This,
        const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase, const char* in_pModelName, boost::shared_ptr<Hedgehog::Mirage::CMatrixNode> in_spMatrixNode);

    inline bool CObjectBase::AddRenderable(const char* in_pModelName,
        const boost::shared_ptr<Hedgehog::Mirage::CSingleElement>& out_spSingleElement,
        const boost::shared_ptr<Hedgehog::Mirage::CMatrixNode>& in_rMatrixNode,
        const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase)
    {
        return fpCObjectBaseAddRenderable(out_spSingleElement, this, in_spDatabase, in_pModelName, in_rMatrixNode);
    }
}