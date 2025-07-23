#pragma once
namespace Sonic
{
	class IUpdateCoordinator
	{
	public:
		virtual void IUpdateCoordinator00() = 0;
		virtual int GetUpdateMode() = 0;
		virtual void IUpdateCoordinator08(int) = 0;
		virtual void IUpdateCoordinator0C(int) = 0;
		virtual double IUpdateCoordinator10() = 0;
		virtual double IUpdateCoordinator14() = 0;
		virtual double IUpdateCoordinator18() = 0;
		virtual void IUpdateCoordinator1C(int) = 0;
		virtual void IUpdateCoordinator20() = 0;
		virtual void* GetDebugSnapshot(int*) = 0;
		virtual void* IUpdateCoordinator28(int*) = 0;
	};
}