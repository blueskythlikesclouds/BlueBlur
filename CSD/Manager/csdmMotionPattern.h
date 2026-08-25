#pragma once

#include <CSD/Manager/csdmBase.h>
#include <CSD/Manager/csdmColor.h>
#include <CSD/Manager/csdmResourceBase.h>

namespace Chao::CSD
{
	class CNode;
	class CFontList;
	struct MATRIX1;

	struct MotionPattern
	{
		struct SField7C
		{
			Hedgehog::Math::CVector2 m_Position;
			Hedgehog::Math::CVector2 m_Field08;
			Hedgehog::Math::CVector2 m_Scale;
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
	public:
		void* m_Field10;
		RCPtr<CNode> m_rcParentNode;
		RCPtr<char> m_rcMatrix;
		CFontList* m_pFontList;
		RCPtr<unsigned char> m_rcChar;
		int* m_Field30;
		int* m_Field34;

		/// Returns the hide flag
		size_t GetHideFlag() const;
		/// Returns the normalized position
		Hedgehog::Math::CVector2 GetPositionNormalized() const;
		/// Returns rotation in degrees
		float GetRotation() const;
		/// Returns scale
		Hedgehog::Math::CVector2 GetScale() const;
		/// Returns the index of the current crop
		float GetPatternIndex() const;
		/// Returns the main tint color
		Color GetMainColor() const;
		/// Returns the corner tint color
		Color GetCornerColor(int in_Index) const;
		/// Returns UserData at index
		int GetUserData(int in_Index) const;


		void SetMainColor(const Color& in_Color);
		void SetCornerColor(int in_Index, const Color& in_Color);
		void SetUserData(int in_Index, uint32_t in_Data);
	};
	BB_ASSERT_OFFSETOF(MotionPattern::SField7C, m_Scale, 0x10);
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
	BB_ASSERT_OFFSETOF(CMotionPattern, m_Field10, 0x10);
	BB_ASSERT_OFFSETOF(CMotionPattern, m_rcParentNode, 0x14);
	BB_ASSERT_OFFSETOF(CMotionPattern, m_rcMatrix, 0x1C);
	BB_ASSERT_OFFSETOF(CMotionPattern, m_pFontList, 0x24);
	BB_ASSERT_OFFSETOF(CMotionPattern, m_rcChar, 0x28);
	BB_ASSERT_OFFSETOF(CMotionPattern, m_Field30, 0x30);
	BB_ASSERT_OFFSETOF(CMotionPattern, m_Field34, 0x34);
	BB_ASSERT_SIZEOF(CMotionPattern, 0x38);
}

#include <CSD/Manager/csdmMotionPattern.inl>