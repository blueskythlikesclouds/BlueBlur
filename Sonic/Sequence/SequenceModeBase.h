#pragma once
namespace Sonic
{
	namespace Sequence
	{
		class CSequenceMode : public Hedgehog::Universe::CMessageActor
		{
		public:
			virtual void CSequenceMode10();
			virtual void ChangeModule();
			virtual void EndModule();
		};
	}
}