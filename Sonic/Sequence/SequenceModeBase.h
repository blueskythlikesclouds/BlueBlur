#pragma once

#include <Hedgehog/Universe/Engine/hhMessageActor.h>

namespace Sonic::Sequence
{
	class CSequenceMode : public Hedgehog::Universe::CMessageActor
	{
	public:
		virtual void CSequenceMode10();
		virtual void ChangeModule();
		virtual void EndModule();
	};
}
