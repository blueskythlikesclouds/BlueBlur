#pragma once

#include <CSD/Manager/csdmBase.h>
#include <CSD/Manager/csdmColor.h>
#include <CSD/Manager/csdmResourceBase.h>

namespace Chao::CSD
{
	struct MotionPattern
	{
		struct SField7C
		{
			Hedgehog::Math::CVector2 m_Position;
		};
		BB_INSERT_PADDING(0x28);
		int HideFlag;
		Hedgehog::Math::CVector2 Position;
		float Rotation;
		Hedgehog::Math::CVector2 Scale;
		float CurrentSpriteIndex;
		Chao::CSD::Color Color;
		Chao::CSD::Color GradientTopLeft;
		Chao::CSD::Color GradientBottomLeft;
		Chao::CSD::Color GradientTopRight;
		Chao::CSD::Color GradientBottomRight;
		BB_INSERT_PADDING(0x1F);
		void* m_Field78;
		SField7C* m_Field7C;
		uint32_t m_RenderFlags;
	};
	class CMotionPattern : public CResourceBase<MotionPattern>, CBase
	{
	};
	BB_ASSERT_OFFSETOF(MotionPattern, HideFlag, 0x28);
	BB_ASSERT_OFFSETOF(MotionPattern, Position, 0x2C);
	BB_ASSERT_OFFSETOF(MotionPattern, Rotation, 0x34);
	BB_ASSERT_OFFSETOF(MotionPattern, Scale, 0x38);
	BB_ASSERT_OFFSETOF(MotionPattern, CurrentSpriteIndex, 0x40);
	BB_ASSERT_OFFSETOF(MotionPattern, Color, 0x44);
	BB_ASSERT_OFFSETOF(MotionPattern, GradientTopLeft, 0x48);
	BB_ASSERT_OFFSETOF(MotionPattern, GradientBottomLeft, 0x4C);
	BB_ASSERT_OFFSETOF(MotionPattern, GradientTopRight, 0x50);
	BB_ASSERT_OFFSETOF(MotionPattern, GradientBottomRight, 0x54);
	BB_ASSERT_OFFSETOF(MotionPattern, m_Field78, 0x78);
	BB_ASSERT_OFFSETOF(MotionPattern, m_Field7C, 0x7C);
	BB_ASSERT_OFFSETOF(MotionPattern, m_RenderFlags, 0x80);
}