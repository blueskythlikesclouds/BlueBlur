#pragma once
namespace Chao::CSD
{
    class Color
	{
	public:
		uint8_t A;
		uint8_t B;
		uint8_t G;
		uint8_t R;

		Color() {};
		Color(uint8_t in_R, uint8_t in_G, uint8_t in_B, uint8_t in_A) : A(in_A), B(in_B), G(in_G), R(in_R) 
        {};
        
		Color(uint32_t in_RgbaHexCode) 
		{
			A = (in_RgbaHexCode >> 24) & 0xFF;
            B = (in_RgbaHexCode >> 16) & 0xFF;
            G = (in_RgbaHexCode >> 8)  & 0xFF;
            R = (in_RgbaHexCode >> 0)  & 0xFF;
		}
		static Color FromVec4(Hedgehog::Math::CVector4 in_RgbaVec4)
		{
            Color newColor;
			newColor.A = (uint8_t)std::clamp(in_RgbaVec4.w() * 255.0f, 0.0f, 255.0f);
			newColor.B = (uint8_t)std::clamp(in_RgbaVec4.z() * 255.0f, 0.0f, 255.0f);
			newColor.G = (uint8_t)std::clamp(in_RgbaVec4.y() * 255.0f, 0.0f, 255.0f);
			newColor.R = (uint8_t)std::clamp(in_RgbaVec4.x() * 255.0f, 0.0f, 255.0f);
			return newColor;
		}
	};
}