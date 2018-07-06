
#ifndef CR_MATH_HPP
#define CR_MATH_HPP



#include "./CR_Common.hpp"



namespace CR
{
	namespace Math
	{
		inline float Floor(float n)
		{
			return static_cast<float>(static_cast<int32_t>(n));
		}



		inline float Pixel(float n)
		{
			return (Math::Floor(n) + 0.375f);
		}



		inline float Abs(float n)
		{
			return std::abs(n);
		}



		inline float Clamp(float n, float l, float h)
		{
			return std::max(l, std::min(n, h));
		}



		inline float Lerp(float a, float b, float t)
		{
			return (t > 1.0f) ? b : (a + (b - a) * t);
		}



		inline float EaseOut(float a, float b, float t)
		{
			return (t > 1.0f) ? b : ((a - b) * t * (t - 2.0f) + a);
		}



		inline float Sin(float n)
		{
			return std::sin(n);
		}
	}
}



#endif
