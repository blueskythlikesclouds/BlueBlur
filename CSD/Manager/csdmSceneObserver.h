#pragma once

#include <CSD/Manager/csdmObserverBase.h>

namespace Chao::CSD
{
    class CScene;

    class CSceneObserver : public CObserverBase<CScene>
    {
    public:
        virtual void OnMotionEnd(CScene* in_pScene) {};
        virtual void OnMotionStart(CScene* in_pScene) {};
        virtual void CSceneObserver0C() {}; //unused
        virtual void CSceneObserver10() {}; //unused
        virtual void CSceneObserver14() {}; //unused
        virtual void CSceneObserver18() {}; //unused
    };
}