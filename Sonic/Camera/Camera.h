#pragma once

#include <Hedgehog/MirageCore/Camera/hhCamera.h>
#include <Hedgehog/Universe/Engine/hhStateMachine.h>

#include <Sonic/System/GameObject.h>

namespace Sonic
{
    class CCamera : public CGameObject, public Hedgehog::Universe::TStateMachine<CCamera>
    {
    public:
        class CMyCamera : public Hedgehog::Mirage::CCamera
        {
        public:
            Hedgehog::Math::CMatrix m_InputView;
        } m_MyCamera;

        BB_INSERT_PADDING(0x228);
        float m_FieldOfView;
        BB_INSERT_PADDING(0x54);
    };

    BB_ASSERT_OFFSETOF(CCamera::CMyCamera, m_InputView, 0xC0);
    BB_ASSERT_OFFSETOF(CCamera, m_MyCamera, 0x110);
    BB_ASSERT_OFFSETOF(CCamera, m_FieldOfView, 0x438);
    BB_ASSERT_SIZEOF(CCamera, 0x490);
}