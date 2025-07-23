#pragma once
namespace Sonic
{
    class IUpdateCoordinator;
class CUpdateDirectorNormal
{
private:
	inline BB_NOINLINE void fpUpdateCategory1(const Hedgehog::Base::CSharedString& in_rUpdCat, float in_UpdTime)
	{
		Hedgehog::Base::CSharedString* result = nullptr;
		auto appDoc = Sonic::CApplicationDocument::GetInstance();
		uint32_t sub_D671B0 = 0x00D67200;
		__asm
		{
			mov     eax, in_rUpdCat
			mov     ecx, appDoc    
			push    in_UpdTime     
			call    sub_D671B0     
		}
	}
	inline BB_NOINLINE void fpUpdateCategory2(const Hedgehog::Base::CSharedString& in_rUpdCat, float in_UpdTime)
	{
		Hedgehog::Base::CSharedString* result = nullptr;
		auto appDoc = Sonic::CApplicationDocument::GetInstance();
		uint32_t sub_D671B0 = 0x00D671B0;
		__asm
		{
			mov     eax, in_rUpdCat
			mov     ecx, appDoc    
			push    in_UpdTime     
			call    sub_D671B0     
		}
	}
public:
	uint32_t m_Field04;
	IUpdateCoordinator* m_pCoordinator;
	boost::anonymous_shared_ptr m_spMirageSnapshot;

	virtual int CUpdateDirectorNormal00(bool a2) = 0;
	virtual int Update(Sonic::CApplicationDocument* in_pAppDoc, float in_UpdTime) = 0;

	void UpdateCategory(const Hedgehog::Base::CSharedString& in_rUpdCat, float in_UpdTime)
	{
		fpUpdateCategory1(in_rUpdCat, in_UpdTime);
	};
	void UpdateCategory2(const Hedgehog::Base::CSharedString& in_rUpdCat, float in_UpdTime)
	{
		fpUpdateCategory2(in_rUpdCat, in_UpdTime);
	};
};
}