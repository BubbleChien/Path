
#ifndef CR_VECTOR_HPP
#define CR_VECTOR_HPP



#include "./CR_Common.hpp"



namespace CR
{
	class Vector
	{
		CR_PUBLIC

		float x = 0.0f;
		float y = 0.0f;

		CR_PUBLIC

		inline Vector() = default;
		inline Vector(float x, float y);

		inline void Set(float x, float y);

		inline void Move(float x, float y);
	};



	Vector::Vector(float x, float y)
	{
		this->x = x;
		this->y = y;
	}



	void Vector::Set(float x, float y)
	{
		this->x = x;
		this->y = y;
	}



	void Vector::Move(float x, float y)
	{
		this->x += x;
		this->y += y;
	}
}



#endif
