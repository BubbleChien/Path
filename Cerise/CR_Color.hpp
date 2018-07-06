
#ifndef CR_COLOR_HPP
#define CR_COLOR_HPP



#include "./CR_Common.hpp"



namespace CR
{
	namespace Color
	{
		constexpr uint32_t RGB(uint8_t r, uint8_t g, uint8_t b)
		{
			return C2D_Color32(r, g, b, 0xFF);
		}



		constexpr uint32_t RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
		{
			return C2D_Color32(r, g, b, a);
		}



		constexpr uint32_t Alpha(uint8_t a)
		{
			return C2D_Color32(0xFF, 0xFF, 0xFF, a);
		}
	}
}



#endif
