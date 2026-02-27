#pragma once
#include <Hedgehog/Base/Type/hhSharedString.h>
namespace Hedgehog::Sound
{
	class CSoundPlaybackControlObserver;
	class CSoundModuleManager;
	class CSoundListenerManager;
    class CSoundHandleCri;
    class CSoundHandle;

	class CSoundSystem : public Hedgehog::Base::CSynchronizedObject
	{
	public:
		int m_Field04;
		boost::shared_ptr<CSoundPlaybackControlObserver> m_spPlaybackControlObserver;
		BB_INSERT_PADDING(0x10);
		boost::shared_ptr<CSoundModuleManager> m_spSoundModuleManager;
		boost::shared_ptr<CSoundListenerManager> m_spSoundListenerManager;
		BB_INSERT_PADDING(0x18);

		static constexpr Hedgehog::Base::TSynchronizedPtr<CSoundSystem>* ms_pInstance = (Hedgehog::Base::TSynchronizedPtr<CSoundSystem>*)0x01E79044;
		static Hedgehog::Base::TSynchronizedPtr<CSoundSystem> GetInstance()
		{
			return *ms_pInstance;
		}
		boost::shared_ptr<Hedgehog::Sound::CSoundHandleCri> CreateSoundHandle()
		{
			boost::shared_ptr<Hedgehog::Sound::CSoundHandleCri> handle;
			BB_FUNCTION_PTR(void, __thiscall, fpCreateSoundHandle, 0x0075F640, void*, boost::shared_ptr<Hedgehog::Sound::CSoundHandleCri>&, int a3, int a4);
			fpCreateSoundHandle(m_spSoundModuleManager.get(), handle, 4, 0);
			return handle;
		}
		boost::shared_ptr<Hedgehog::Sound::CSoundHandle> PlaySound(int in_CueID)
		{
			boost::shared_ptr<Hedgehog::Sound::CSoundHandle> returnedHandle;
			BB_FUNCTION_PTR(void*, __thiscall, fpPlaySoundStaticID, 0x075FA60, void* This, boost::shared_ptr<Hedgehog::Sound::CSoundHandle>&, int cueId);
 			fpPlaySoundStaticID(m_spSoundModuleManager.get(), returnedHandle, in_CueID);
			return returnedHandle;
		}
		boost::shared_ptr<Hedgehog::Sound::CSoundHandle> PlaySound(const Hedgehog::Base::CSharedString in_CueName)
		{
			boost::shared_ptr<Hedgehog::Sound::CSoundHandle> returnedHandle;
			BB_FUNCTION_PTR(void*, __thiscall, fpPlaySoundStaticID, 0x75FA90, void* This, boost::shared_ptr<Hedgehog::Sound::CSoundHandle>&, const Hedgehog::Base::CSharedString & cueId);
			fpPlaySoundStaticID(m_spSoundModuleManager.get(), returnedHandle, in_CueName);
			return returnedHandle;
		}
	};
	BB_ASSERT_OFFSETOF(CSoundSystem, m_Field04, 0x4);
	BB_ASSERT_OFFSETOF(CSoundSystem, m_spPlaybackControlObserver, 0x8);
	BB_ASSERT_OFFSETOF(CSoundSystem, m_spSoundModuleManager, 0x20);
	BB_ASSERT_OFFSETOF(CSoundSystem, m_spSoundListenerManager, 0x28);
};