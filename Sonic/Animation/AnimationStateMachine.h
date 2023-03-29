#pragma once

#include <Hedgehog/Universe/Engine/hhStateMachineBase.h>

namespace Sonic
{
	class CAnimationData;

	class __declspec(align(4)) CAnimationControlSingle
	{
	public:
		virtual ~CAnimationControlSingle() = default;

		void SetPlaybackSpeed(float speed)
		{
			BB_FUNCTION_PTR(void, __thiscall, fpSetPlaybackSpeed, 0x006D21C0, CAnimationControlSingle*, float);
			fpSetPlaybackSpeed(this, speed);
		}

		uint32_t m_field4;
		void* m_hkaDefaultAnimationControl;
		uint32_t m_fieldC;
		uint32_t m_PlaybackType;
		float m_field14;
		float m_PlaybackSpeed;
		BB_INSERT_PADDING(0x18);
		bool m_field34;
		BB_INSERT_PADDING(0x37); // 3 extra bytes of padding due to the bool above here
		bool m_field6C;
		BB_INSERT_PADDING(0x78);
		boost::shared_ptr<CAnimationData> m_spAnimationData;
	};
	BB_ASSERT_OFFSETOF(CAnimationControlSingle, m_PlaybackSpeed, 0x18);
	BB_ASSERT_OFFSETOF(CAnimationControlSingle, m_field34, 0x34);
	BB_ASSERT_OFFSETOF(CAnimationControlSingle, m_field6C, 0x6C);
	BB_ASSERT_OFFSETOF(CAnimationControlSingle, m_spAnimationData, 0xE8);
	BB_ASSERT_SIZEOF(CAnimationControlSingle, 0xF0);

	class CAnimationStateSingle : public Hedgehog::Universe::CStateMachineBase::CStateBase
	{
	public:
		BB_INSERT_PADDING(0x20) {};
		boost::shared_ptr<CAnimationControlSingle> m_spAnimationControlSingle;
		Hedgehog::Base::CSharedString m_TransitionState;
		float    m_field8C;
		uint32_t m_field90;
		BB_INSERT_PADDING(0x10C) {};

		//BB_INSERT_PADDING(0x140) {};
	};
	BB_ASSERT_SIZEOF(CAnimationStateSingle, 0x1A0);
	BB_ASSERT_OFFSETOF(CAnimationStateSingle, m_TransitionState, 0x88);

	class CAnimationStateMachine : public Hedgehog::Universe::CStateMachineBase
	{
		static void fCAnimationStateMachineCtor(CAnimationStateMachine* This)
		{
			uint32_t func = 0x00CDF720;
			__asm
			{
				mov esi, This
				call func
			}
		}
		static void fUpdate(CAnimationStateMachine* This, const Hedgehog::Universe::SUpdateInfo& updateInfo)
		{
			static uint32_t func = 0x00CE0810;
			__asm
			{
				mov ecx, This
				mov eax, updateInfo
				call func
			}
		}

		BB_INSERT_PADDING(0x28) {};

	public:

		CAnimationStateMachine(const bb_null_ctor&)
			: CStateMachineBase(bb_null_ctor{})
		{
		}

		CAnimationStateMachine()
			: CAnimationStateMachine(bb_null_ctor{})
		{
			fCAnimationStateMachineCtor(this);
		}

		void AddAnimationState(const Hedgehog::Base::CSharedString& name)
		{
			BB_FUNCTION_PTR(void*, __stdcall, func, 0xCDFA20,
				void* This, const boost::shared_ptr<void>&_spAnimationState, const Hedgehog::Base::CSharedString & _name, const Hedgehog::Base::CSharedString & _alsoName);

			const boost::shared_ptr<void> emptyPtr{};

			func(this, emptyPtr, name, name);
		}

		void AddAnimationState(const Hedgehog::Base::CSharedString& name, const boost::shared_ptr<void>& emptyPtr)
		{
			BB_FUNCTION_PTR(void*, __stdcall, func, 0xCDFA20,
				void* This, const boost::shared_ptr<void>&_spAnimationState, const Hedgehog::Base::CSharedString & _name, const Hedgehog::Base::CSharedString & _alsoName);

			func(this, emptyPtr, name, name);
		}

		boost::shared_ptr<CAnimationStateSingle> GetAnimationStateByName(const Hedgehog::Base::CSharedString& name)
		{
			typedef boost::shared_ptr<CAnimationStateSingle> animSingle;
			BB_FUNCTION_PTR(animSingle&, __stdcall, func, 0x00CDFB40, CAnimationStateMachine * This, const Hedgehog::Base::CSharedString & _name);
			return func(this, name);
		}

		void ChangeState(const Hedgehog::Base::CSharedString& name)
		{
			BB_FUNCTION_PTR(void, __stdcall, ChangeAnimation, 0xCDFC80, void* a1, boost::shared_ptr<void>*a2, const Hedgehog::Base::CSharedString & _name);
			boost::shared_ptr<void> Empty = {};
			ChangeAnimation(this, &Empty, name);
		}
		void Update(const Hedgehog::Universe::SUpdateInfo& updateInfo)
		{
			fUpdate(this, updateInfo);
		}
	};

	BB_ASSERT_SIZEOF(CAnimationStateMachine, 0x88);
}