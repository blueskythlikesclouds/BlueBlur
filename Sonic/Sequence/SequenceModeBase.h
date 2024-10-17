#pragma once
namespace Sonic
{
	namespace Sequence
	{
		class CSequenceMode : public Hedgehog::Universe::CMessageActor
		{
		public:
			virtual void CSequenceMode04();
			virtual void ChangeModule();
			virtual void EndModule();
		};
	}
}